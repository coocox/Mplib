
/******************************************************************************
 * @file     PWM_DeadZone.c
 * @version  V1.00
 * $Revision: 8 $
 * $Date: 14/01/14 10:47a $
 * @brief    PWM sample for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "pwm.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

void UART0_Init(void);
void SYS_Init(void);

int32_t PWM_DeadZone(void)
{
    /* Init System, IP clock and multi-function I/O
       In the end of SYS_Init() will issue SYS_LockReg()
       to lock protected register. If user want to write
       protected register, please issue SYS_UnlockReg()
       to unlock protected register if necessary */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART0_Init();

    printf("\nThis sample code will output PWM0 channel 0 to with different\n");
    printf("frequency and duty, enable dead zone function of all PWM0 pairs.\n");
    printf("And also enable/disable PWM0 output every 1 second.\n");
    // PWM0 frequency is 100Hz, duty 30%,
    PWM_ConfigOutputChannel(PWM0, 0, 100, 30);
    PWM_EnableDeadZone(PWM0, 0, 400);

    // PWM2 frequency is 300Hz, duty 50%
    PWM_ConfigOutputChannel(PWM0, 2, 300, 50);
    PWM_EnableDeadZone(PWM0, 2, 200);

    // PWM4 frequency is 500Hz, duty 70%
    PWM_ConfigOutputChannel(PWM0, 4, 600, 70);
    PWM_EnableDeadZone(PWM0, 4, 100);

    // Enable complementary mode
    PWM_ENABLE_COMPLEMENTARY_MODE(PWM0);

    // Enable output of all PWM channels
    PWM_EnableOutput(PWM0, 0x3F);

    // Enable PWM channel 0 period interrupt, use channel 0 to measure time.
    PWM_EnablePeriodInt(PWM0, 0, 0);
    NVIC_EnableIRQ(PWM0CH0_IRQn);

    // Start
    PWM_Start(PWM0, 0x3F);

    while(1);

}


void PWM0CH0_IRQHandler(void)
{
    static uint32_t cnt;
    static uint32_t out;

    // Channel 0 frequency is 100Hz, every 1 second enter this IRQ handler 100 times.
    if(++cnt == 100) {
        if(out)
            PWM_EnableOutput(PWM0, 0x3F);
        else
            PWM_DisableOutput(PWM0, 0x3F);
        out ^= 1;
        cnt = 0;
    }
    // Clear channel 0 period interrupt flag
    PWM_ClearPeriodIntFlag(PWM0, 0);
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

    /* enable PWM0 Channel 0~5 peripheral clock */
    CLK_EnableModuleClock(PWM0CH01_MODULE);
    CLK_EnableModuleClock(PWM0CH23_MODULE);
    CLK_EnableModuleClock(PWM0CH45_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HXT,CLK_CLKDIV0_UART(1));

    /* Set PCLK as PWM0 channel 0~3 clock source */
    CLK_SetModuleClock(PWM0CH01_MODULE,CLK_CLKSEL2_PWM0CH01_S_PCLK,1);
    CLK_SetModuleClock(PWM0CH23_MODULE,CLK_CLKSEL2_PWM0CH23_S_PCLK,1);
    CLK_SetModuleClock(PWM0CH45_MODULE,CLK_CLKSEL2_PWM0CH45_S_PCLK,1);

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

    /* Set A5 A6 C10 C11 A12 A11 multi-function pins for PWM Channel 0~5  */
    SYS->GPA_MFPL = (SYS->GPA_MFPL & ~(SYS_GPA_MFPL_PA5_MFP_Msk | SYS_GPA_MFPL_PA6_MFP_Msk)) | SYS_GPA_MFPL_PA5_MFP_PWM0_CH0 | SYS_GPA_MFPL_PA6_MFP_PWM0_CH1;
    SYS->GPC_MFPH = (SYS->GPC_MFPH & ~(SYS_GPC_MFPH_PC10_MFP_Msk | SYS_GPC_MFPH_PC11_MFP_Msk)) | SYS_GPC_MFPH_PC10_MFP_PWM0_CH2 | SYS_GPC_MFPH_PC11_MFP_PWM0_CH3;
    SYS->GPA_MFPH = (SYS->GPA_MFPH & ~(SYS_GPA_MFPH_PA12_MFP_Msk | SYS_GPA_MFPH_PA11_MFP_Msk)) | SYS_GPA_MFPH_PA12_MFP_PWM0_CH4 | SYS_GPA_MFPH_PA11_MFP_PWM0_CH5;

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


