/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Date: 13/11/10 9:33a $
 * @brief    NUC400 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "nuc400series.h"
#include "sys.h"
#include "clk.h"
#include "gpio.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000


void SYS_Init(void);
void UART0_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int GPIO_Example(void)
{
    int32_t i32Err;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART for printf */
    UART0_Init();

//    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
//
//    printf("+-------------------------------------+ \n");
//    printf("|    NUC400 GPIO Driver Sample Code   | \n");
//    printf("+-------------------------------------+ \n");
//
//    /*-----------------------------------------------------------------------------------------------------*/
//    /* GPIO Basic Mode Test --- Use Pin Data Input/Output to control GPIO pin                              */
//    /*-----------------------------------------------------------------------------------------------------*/
//    printf("  >> Please connect PB.3 and PD.7 first << \n");
//    printf("     Press any key to start test by using [Pin Data Input/Output Control] \n\n");
//    getchar();

    /* Configure PB.3 as Output mode and PD.7 as Input mode then close it */
    GPIO_SetMode(PB, BIT3, GPIO_PMD_OUTPUT);
//    GPIO_SetMode(PD, BIT7, GPIO_PMD_INPUT);

    i32Err = 0;
//    printf("  GPIO Output/Input test ...... \n");

    /* Use Pin Data Input/Output Control to pull specified I/O or get I/O pin status */
    PB3 = 0;
    for(i32Err=0;i32Err<1000000;i32Err++);
//    if (PD7 != 0) {
//        i32Err = 1;
//    }

    PB3 = 1;
    for(i32Err=0;i32Err<1000000;i32Err++);
//    if (PD7 != 1) {
//        i32Err = 1;
//    }
//
//    if ( i32Err ) {
//        printf("  [FAIL] --- Please make sure PB.3 and PD.7 are connected. \n");
//    } else {
//        printf("  [OK] \n");
//    }

//    /* Configure PB.3 and PD.7 to default Quasi-bidirectional mode */
//    GPIO_SetMode(PB, BIT3, GPIO_PMD_QUASI);
//    GPIO_SetMode(PD, BIT7, GPIO_PMD_QUASI);
//
//
//    /*-----------------------------------------------------------------------------------------------------*/
//    /* GPIO Interrupt Function Test                                                                        */
//    /*-----------------------------------------------------------------------------------------------------*/
//    printf("\n  PB2, PC5, PA0(INT0) and PF0(INT5) are used to test interrupt\n  and control LEDs(PD10)\n");
//
//    /*Configure PD10 for LED control */
//    GPIO_SetMode(PD, BIT10, GPIO_PMD_OUTPUT);
//
//    /* Configure PB2 as Input mode and enable interrupt by rising edge trigger */
//    GPIO_SetMode(PB, BIT2, GPIO_PMD_INPUT);
//    GPIO_EnableInt(PB, 2, GPIO_INT_RISING);
//    NVIC_EnableIRQ(GPB_IRQn);
//
//
//    /*  Configure PC5 as Quasi-bi-direction mode and enable interrupt by falling edge trigger */
//    GPIO_SetMode(PC, BIT5, GPIO_PMD_QUASI);
//    GPIO_EnableInt(PC, 5, GPIO_INT_FALLING);
//    NVIC_EnableIRQ(GPC_IRQn);
//
//    /* Configure PA0 as EINT0 pin and enable interrupt by falling edge trigger */
//    /*****************************************/
//    RTC->INIR = 0xA5EB1357UL;
//    while(!(RTC->INIR & RTC_INIR_ACTIVE_Msk));
//
//    RTC->AER = 0xA965;
//    while(!(RTC->AER & RTC_AER_ENF_Msk));
//
//    RTC->TAMPCTRL = 0x0;
//    RTC->SPR[23] = BIT31;
//    /*****************************************/
//    SYS->GPA_MFPL = SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0_MFP_Msk | SYS_GPA_MFPL_PA0_MFP_INT0;
//    GPIO_SetMode(PA, BIT0, GPIO_PMD_INPUT);
//    GPIO_EnableEINT0(PA, 0, GPIO_INT_FALLING);
//    NVIC_EnableIRQ(EINT0_IRQn);
//
//    /* Configure PF0 as EINT5 pin and enable interrupt by rising and falling edge trigger */
//    SYS->GPF_MFPL = SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0_MFP_Msk | SYS_GPF_MFPL_PF0_MFP_INT5;
//    GPIO_SetMode(PF, BIT0, GPIO_PMD_INPUT);
//    GPIO_EnableEINT(PF, 0, GPIO_INT_BOTH_EDGE);
//    NVIC_EnableIRQ(EINT5_IRQn);
//
//    /* Enable interrupt de-bounce function and select de-bounce sampling cycle time */
//    GPIO_SET_DEBOUNCE_TIME(GPIO_DBNCECON_DBCLKSRC_HCLK, GPIO_DBNCECON_DBCLKSEL_1);
//    GPIO_ENABLE_DEBOUNCE(PA, BIT0);
//    GPIO_ENABLE_DEBOUNCE(PB, BIT2);
//    GPIO_ENABLE_DEBOUNCE(PC, BIT5);
//    GPIO_ENABLE_DEBOUNCE(PF, BIT0);

    /* Waiting for interrupts */
    while (1)
    {

        PB3 = 0;
        for(i32Err=0;i32Err<1000000;i32Err++);
        PB3 = 1;
        for(i32Err=0;i32Err<1000000;i32Err++);
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
    CLK_EnableXtalRC(CLK_PWRCON_HXT_EN_Msk);

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON|= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HXT,CLK_CLKDIV0_UART(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL &= ~(SYS_GPG_MFPL_PG1_MFP_Msk|SYS_GPG_MFPL_PG2_MFP_Msk);
    SYS->GPG_MFPL |= SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Set GPG multi-function pins for CKO */
    SYS->GPC_MFPL = (SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5_MFP_Msk) | SYS_GPC_MFPL_PC5_MFP_CLK_O ;

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART0->LCR |=0x07;
    UART0->BAUD = 0x30000067;   /* 12MHz reference clock input, for 115200 */
    //UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    //_UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

/**
 * @brief       GPIO IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The GPIO default IRQ, declared in startup_nuc400series.s.
 */
void GPA_IRQHandler(void)
{
    PA->ISRC = PA->ISRC;
}

void GPB_IRQHandler(void)
{
    /* To check if PB2 interrupt occurred */
    if (PB->ISRC & BIT2) {
        PB->ISRC = BIT2;
        PD10 = PD10 ^ 1;
        printf("PB2 INT occurred. \n");

    } else {
        /* Un-expected interrupt. Just clear all PORTB interrupts */
        PB->ISRC = PB->ISRC;
        printf("Un-expected interrupts. \n");
    }
}

void GPC_IRQHandler(void)
{
    /* To check if PC5 interrupt occurred */
    if (PC->ISRC & BIT5) {
        PC->ISRC = BIT5;
        PD10 = PD10 ^ 1;
        printf("PC5 INT occurred. \n");
    } else {
        PC->ISRC = PC->ISRC;
        printf("Un-expected interrupts. \n");
    }
}

void GPD_IRQHandler(void)
{
    PD->ISRC = PD->ISRC;
}

void GPE_IRQHandler(void)
{
    PE->ISRC = PE->ISRC;
}

void GPF_IRQHandler(void)
{
    PF->ISRC = PF->ISRC;
}

void GPG_IRQHandler(void)
{
    PG->ISRC = PG->ISRC;
}

void GPH_IRQHandler(void)
{
    PH->ISRC = PH->ISRC;
}

void GPI_IRQHandler(void)
{
    PI->ISRC = PI->ISRC;
}

/**
 * @brief       External INT IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The External INT default IRQ, declared in startup_nuc400series.s.
 */
void EINT0_IRQHandler(void)
{
    /* For PA0, clear the INT flag */
    PA->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PA0 EINT0 occurred. \n");
}

void EINT1_IRQHandler(void)
{
    /* For PB0, clear the INT flag */
    PB->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PB0 EINT1 occurred. \n");
}

void EINT2_IRQHandler(void)
{
    /* For PC0, clear the INT flag */
    PC->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PC0 EINT2 occurred. \n");
}

void EINT3_IRQHandler(void)
{
    /* For PD0, clear the INT flag */
    PD->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PD0 EINT3 occurred. \n");
}

void EINT4_IRQHandler(void)
{
    /* For PE0, clear the INT flag */
    PE->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PE0 EINT4 occurred. \n");
}

void EINT5_IRQHandler(void)
{
    /* For PF0, clear the INT flag */
    PF->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PF0 EINT5 occurred. \n");
}

void EINT6_IRQHandler(void)
{
    /* For PG0, clear the INT flag */
    PG->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PG0 EINT6 occurred. \n");
}

void EINT7_IRQHandler(void)
{
    /* For PH0, clear the INT flag */
    PH->ISRC = BIT0;
    PD10 = PD10 ^ 1;
    printf("PH0 EINT7 occurred. \n");
}
