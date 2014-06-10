/******************************************************************************
 * @file     WDT_Wakeup.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 13/11/10 9:33a $
 * @brief    WDT sample for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "uart.h"
#include "wdt.h"

void SYS_Init(void);



int32_t WDT_Wakeup(void)
{
    /* Init System, IP clock and multi-function I/O
       In the end of SYS_Init() will issue SYS_LockReg()
       to lock protected register. If user want to write
       protected register, please issue SYS_UnlockReg()
       to unlock protected register if necessary */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    printf("\nThis sample code demonstrate using WDT to wake system up from power down mode\n");

    // WDT register is locked, so it is necessary to unlock protect register before configure WDT
    SYS_UnlockReg();

    // WDT timeout every 2^14 WDT clock, disable system reset, enable wake up system
    WDT_Open(WDT_TIMEOUT_2POW14, 0, FALSE, TRUE);

    // Enable WDT timeout interrupt
    WDT_EnableInt();
    NVIC_EnableIRQ(WDT_IRQn);

    while(1) {
        // Wait 'til UART FIFO empty to get a cleaner console out
        while(!UART_IS_TX_EMPTY(UART0));
        CLK_PowerDown();
    }

}


void WDT_IRQHandler(void)
{

    // Clear WDT interrupt flag
    WDT_CLEAR_TIMEOUT_INT_FLAG();

    // Check WDT wake up flag
    if(WDT_GET_TIMEOUT_WAKEUP_FLAG()) {
        printf("Wake up by WDT\n");
        // Clear WDT wake up flag
        WDT_CLEAR_TIMEOUT_WAKEUP_FLAG();
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
    /* Enable LIRC */
    CLK_EnableXtalRC(CLK_PWRCON_LIRC_EN_Msk);

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Waiting for LIRC clock stable */
    CLK_WaitClockReady( CLK_CLKSTATUS_LIRC_STB_Msk);

    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = CLK_PLLCON_84MHz_HXT;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);


    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDT_S_LIRC, 0);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();


    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;
    /* Lock protected registers */
    SYS_LockReg();
}


/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


