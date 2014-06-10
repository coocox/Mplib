/**************************************************************************//**
 * @file     ADC_SingleMode.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 13/11/20 2:40p $
 * @brief    ADC sample for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "adc.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

volatile uint8_t u8ADF;

void SYS_Init(void);
void UART0_Init(void);

int32_t ADC_SingleMode (void)
{
    uint32_t u32Result;

    /* Init System, IP clock and multi-function I/O
       In the end of SYS_Init() will issue SYS_LockReg()
       to lock protected register. If user want to write
       protected register, please issue SYS_UnlockReg()
       to unlock protected register if necessary */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

    printf("\nThis sample code demonstrate ADC single mode conversion\n");
    printf("It convert channel 0 and print conversion result\n");

    // Enable channel 0
    ADC_Open(ADC, ADC_INPUT_MODE_SINGLE_END, ADC_OPERATION_MODE_SINGLE, ADC_CH_0_MASK);

    // Power on ADC
    ADC_POWER_ON(ADC);

    // Enable ADC ADC_IF interrupt
    ADC_EnableInt(ADC, ADC_ADF_INT);
    NVIC_EnableIRQ(ADC_IRQn);

    u8ADF = 0;

    ADC_START_CONV(ADC);

    while (u8ADF == 0);

    u32Result = ADC_GET_CONVERSION_DATA(ADC, 0);
    printf("Channel 0 conversion result is 0x%x\n",u32Result);

    ADC_DisableInt(ADC, ADC_ADF_INT);

}


void ADC_IRQHandler(void)
{
    uint32_t u32Flag;

    // Get ADC conversion finish interrupt flag
    u32Flag = ADC_GET_INT_FLAG(ADC, ADC_ADF_INT);

    if(u32Flag & ADC_ADF_INT)
        u8ADF = 1;

    ADC_CLR_INT_FLAG(ADC, u32Flag);
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
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Set GPG multi-function pins for CKO */
    SYS->GPC_MFPL = (SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5_MFP_Msk) | SYS_GPC_MFPL_PC5_MFP_CLK_O ;

    /* Configure analog input pins ADC0(GPE0) */
    SYS->GPE_MFPL = (SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0_MFP_Msk) | SYS_GPE_MFPL_PE0_MFP_ADC0_0;
    /* Disable the digital input path */
    PE->OFFD = PE->OFFD | (ADC_CH_0_MASK << GPIO_OFFD_OFFD_Pos);

    /* enable ADC peripheral clock */
    CLK->APBCLK0 |= CLK_APBCLK0_ADC_EN_Msk;

    /* Reset ADC */
    SYS->IPRSTC2 |= SYS_IPRSTC2_ADC_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_ADC_RST_Msk;

    /* Vref connect to AVDD */
    SYS->VREFCR |= SYS_VREFCR_ADC_VREFSEL_Msk;

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
    UART0->BAUD = 0x30000066;   /* 12MHz reference clock input, for 115200 */
}

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


