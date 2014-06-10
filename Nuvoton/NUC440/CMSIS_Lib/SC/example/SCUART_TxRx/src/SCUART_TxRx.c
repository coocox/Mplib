/******************************************************************************
 * @file     SCUART_TxRx.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/01/14 10:47a $
 * @brief    Smartcard UART mode demo for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "SYS.h"
#include "CLK.h"
#include "UART.h"
#include "SCUART.h"

void SYS_Init(void);

uint8_t au8TxBuf[] = "Hello World!";


int SCUART_TxRx(void)
{
    /* Init System, IP clock and multi-function I/O
       In the end of SYS_Init() will issue SYS_LockReg()
       to lock protected register. If user want to write
       protected register, please issue SYS_UnlockReg()
       to unlock protected register if necessary */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    printf("This sample code demos smartcard interface UART mode\n");
    printf("Please connect SC0 CLK pin(PA.7) with SC0 I/O pin(PA.10)\n");
    printf("Hit any key to continue\n");
    GetChar();

    // Open smartcard interface 0 in UART mode.
    SCUART_Open(SC0, 115200);
    // Enable receive interrupt
    SCUART_ENABLE_INT(SC0, SC_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(SC0_IRQn);


    SCUART_Write(SC0, au8TxBuf, sizeof(au8TxBuf));



    while(1);
}


/**
  * @brief  The interrupt services routine of smartcard port 0
  * @param  None
  * @retval None
  */
void SC0_IRQHandler(void)
{
    // Print SCUART received data to UART port
    // Data length here is short, so we're not care about UART FIFO over flow.
    UART_WRITE(UART0, SCUART_READ(SC0));

    // RDA is the only interrupt enabled in this sample, this status bit
    // automatically cleared after Rx FIFO empty. So no need to clear interrupt
    // status here.

    return;
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
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = CLK_PLLCON_84MHz_HXT;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    //CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(SC0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));
    CLK_SetModuleClock(SC0_MODULE, CLK_CLKSEL3_SC0_S_HXT, CLK_CLKDIV1_SC0(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();


    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;
    SYS->GPA_MFPL = SYS_GPA_MFPL_PA7_MFP_SC0_CLK;   // CLK as SCUART Tx pin
    SYS->GPA_MFPH = SYS_GPA_MFPH_PA10_MFP_SC0_DAT;  // CLK as SCUART Rx pin
    /* Lock protected registers */
    SYS_LockReg();
}
/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


