/**************************************************************************//**
 * @file     SPI_MasterMode.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 Series SPI Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "spi.h"
#define TEST_COUNT 16

uint32_t g_au32SourceData[TEST_COUNT];
uint32_t g_au32DestinationData[TEST_COUNT];
volatile uint32_t g_u32TxDataCount;
volatile uint32_t g_u32RxDataCount;
void SYS_Init(void);


int SPI_MasterMode(void)
{
    uint32_t u32DataCount;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    /* Configure SPI0 as a master, MSB first, 32-bit transaction, SPI Mode-0 timing, clock is 2MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 32, 1000000);

    /* Enable the automatic hardware slave select function. Select the SPI0_SS0 pin and configure as low-active. */
    SPI_EnableAutoSS(SPI0, SPI_SS0, SPI_SS_ACTIVE_LOW);

    printf("\n\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("|                       SPI Driver Sample Code                         |\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("\n");

    printf("Configure SPI0 as a master.\n");
    printf("SPI clock rate: %d Hz\n", SPI_GetBusClock(SPI0));
    printf("SPI controller will transfer %d data to a off-chip slave device.\n", TEST_COUNT);
    printf("In the meanwhile the SPI controller will receive %d data from the off-chip slave device.\n", TEST_COUNT);
    printf("After the transfer is done, the %d received data will be printed out.\n", TEST_COUNT);
    printf("The SPI master configuration is ready.\n");

    for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++) {
        g_au32SourceData[u32DataCount] = 0x00550000 + u32DataCount;
        g_au32DestinationData[u32DataCount] = 0;
    }

    printf("Before starting the data transfer, make sure the slave device is ready. Press any key to start the transfer.\n");
    getchar();
    printf("\n");

    SPI_TRIGGER(SPI0);

    /* Set Tx FIFO threshold, enable Tx FIFO threshold interrupt and RX FIFO time-out interrupt */
    SPI_SetFIFOThreshold(SPI0, 4, 4);
    SPI_SET_SUSPEND_CYCLE(SPI0, 4);
    SPI_EnableInt(SPI0, SPI_FIFO_RXTIMEOUT_INTEN_MASK | SPI_FIFO_TXTH_INTEN_MASK);

    g_u32TxDataCount = 0;
    g_u32RxDataCount = 0;
    NVIC_EnableIRQ(SPI0_IRQn);

    /* Wait for transfer done */
    while(g_u32RxDataCount<TEST_COUNT);

    printf("Received data:\n");
    for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++) {
        printf("%d:\t0x%08X\n", u32DataCount, g_au32DestinationData[u32DataCount]);
    }
    /* Disable Tx FIFO threshold interrupt and RX FIFO time-out interrupt */
    SPI_DisableInt(SPI0, SPI_FIFO_RXTIMEOUT_INTEN_MASK | SPI_FIFO_TXTH_INTEN_MASK);

    NVIC_DisableIRQ(SPI0_IRQn);
    printf("The data transfer was done.\n");

    while(1);
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
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(SPI0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* SPI0: GPE4=SS0, GPE3=MOSI0, GPE2=MISO0, GPE5=CLK */
    SYS->GPE_MFPL = (SYS_GPE_MFPL_PE2_MFP_SPI0_MISO0 | SYS_GPE_MFPL_PE3_MFP_SPI0_MOSI0 | SYS_GPE_MFPL_PE4_MFP_SPI0_SS0 | SYS_GPE_MFPL_PE5_MFP_SPI0_CLK);

    /* Lock protected registers */
    SYS_LockReg();
}

void SPI0_IRQHandler(void)
{
    while((SPI_GET_STATUS(SPI0) & SPI_STATUS_RX_EMPTY_Msk)==0) {
        g_au32DestinationData[g_u32RxDataCount++] = SPI_READ_RX(SPI0);
    }

    while( ((SPI_GET_STATUS(SPI0) & SPI_STATUS_TX_FULL_Msk)==0) && (g_u32TxDataCount<TEST_COUNT) ) {
        SPI_WRITE_TX(SPI0, g_au32SourceData[g_u32TxDataCount++]);
    }

    if(g_u32TxDataCount>=TEST_COUNT)
        SPI_DisableInt(SPI0, SPI_FIFO_TXTH_INTEN_MASK); /* Disable TX FIFO threshold interrupt */

    /* Check the Rx FIFO time-out interrupt flag */
    if( SPI_GET_STATUS(SPI0) & SPI_STATUS_RXTO_INTSTS_Msk ) {
        while((SPI_GET_STATUS(SPI0) & SPI_STATUS_RX_EMPTY_Msk)==0)
            g_au32DestinationData[g_u32RxDataCount++] = SPI_READ_RX(SPI0);
    }
}
