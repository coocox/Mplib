/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/06/12 1:18p $
 * @brief    NUC200 Series ACMP Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "UART.h"
#include "GPIO.h"
#include "SYS.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000

void SYS_Init(void);
void UART0_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* Main function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
void ACMP_Example()
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

//    printf("\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|                     ACMP Sample Code                           |\n");
    printf("+----------------------------------------------------------------+\n");
    printf("  PC.6  (CPP0): comparator 0 positive input\n");
    printf("  PC.14 (CPP1): comparator 1 positive input\n");
    printf("  The internal bandgap voltage is selected as the negative input of both comparators (CPN0 & CPN1).\n");
    printf("  PB.2 (CPO0): comparator 0 output\n");
    printf("  PB.13 (CPO1): comparator 1 output\n");
    printf("When the level of the positive input is greater than the level of the negative input,\n");
    printf("the analog comparator outputs a logical one; otherwise, it outputs a logical zero.\n");
    printf("This sample code will show the expression of the comparator's inputs and a sequence ");
    printf("number when detecting a transition of analog comparator's output.\n");
    printf("Press any key to start ...");
//    getchar();
//    printf("\n");

    /* Disable digital input path of PC.6 (CPP0) and PC.14 (CPP1) to avoid the leakage current */
    _GPIO_DISABLE_DIGITAL_PATH(PC, 6);
    _GPIO_DISABLE_DIGITAL_PATH(PC, 14);

    /* Configure ACMP0 Comparator 0 */
    ACMP->CMPCR[0] = ACMP_CMPCR_CMPEN_Msk | ACMP_CMPCR_CMPIE_Msk | ACMP_CMPCR_CMPCN_Msk;

    /* Configure ACMP0 Comparator 1 */
    ACMP->CMPCR[1] = ACMP_CMPCR_CMPEN_Msk | ACMP_CMPCR_CMPIE_Msk | ACMP_CMPCR_CMPCN_Msk;

    /* Enable NVIC bit for ACMP0 */
    NVIC_EnableIRQ(ACMP_IRQn);

    while(1);
}




/*---------------------------------------------------------------------------------------------------------*/
/* ACMP IRQ Handler                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
static uint32_t s_u32Acmp0IntCnt = 0;

void ACMP_IRQHandler(void)
{
    uint32_t u32DelayCount;

    /* input de-bounce */
    for(u32DelayCount=0; u32DelayCount<10000; u32DelayCount++);

    s_u32Acmp0IntCnt++;

    if (ACMP->CMPSR & ACMP_CMPSR_CMPF0_Msk)
    {
        /* Check Comparator 0 Output Status */
        if (ACMP->CMPSR & ACMP_CMPSR_CO0_Msk)
            printf("CPP0 > CPN0 (%d)\n", s_u32Acmp0IntCnt);
        else
            printf("CPP0 <= CPN0 (%d)\n", s_u32Acmp0IntCnt);

        /* Clear Comparator 0 Flag */
        ACMP->CMPSR = ACMP_CMPSR_CMPF0_Msk;
    }

    if (ACMP->CMPSR & ACMP_CMPSR_CMPF1_Msk)
    {
        /* Check Comparator 1 Output Status */
        if (ACMP->CMPSR & ACMP_CMPSR_CO1_Msk)
            printf("CPP1 > CPN1 (%d)\n", s_u32Acmp0IntCnt);
        else
            printf("CPP1 <= CPN1 (%d)\n", s_u32Acmp0IntCnt);

        /* Clear Comparator 1 Flag */
        ACMP->CMPSR = ACMP_CMPSR_CMPF1_Msk;
    }
}

void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for 12MHz clock ready */
    SYS_WaitingForClockReady( SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_XTAL;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_ACMP_EN_Msk;
    /* Select IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_XTAL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set GPB multi-function pins for UART0 RXD, UART0 TXD, CPO0 and CPO1 */
    SYS->GPB_MFP = SYS_GPB_MFP_PB13_CPO1 | SYS_GPB_MFP_PB2_CPO0 | SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB0_RXD0;
    SYS->ALT_MFP = SYS_ALT_MFP_PB2_CPO0;

    /* Set GPC multi-function pins for ACMP CPP0 and CPP1 */
    SYS->GPC_MFP = SYS_GPC_MFP_PC14_CPP1 | SYS_GPC_MFP_PC6_CPP0;
    SYS->ALT_MFP1 = 0;

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}
