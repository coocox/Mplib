/**************************************************************************//**
 * @file     SPI_SlaveMode.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 14/01/14 10:48a $
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
void SYS_Init(void);

int SPI_SlaveMode(void)
{
    uint32_t u32TxDataCount, u32RxDataCount;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    /* Configure SPI1 as a slave, MSB first, 32-bit transaction, SPI Mode-0 timing, clock is 4MHz */
    SPI_Open(SPI1, SPI_SLAVE, SPI_MODE_0, 32, 4000000);

    /* Configure SPI1 as a low level active device. */
    SPI_SET_SS0_LOW(SPI1);

    printf("\n\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("|                       SPI Driver Sample Code                         |\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("\n");

    printf("Configure SPI1 as a slave.\n");
    printf("SPI slave peripheral clock rate: %d Hz\n", SPI_GetBusClock(SPI1));
    printf("SPI controller will enable FIFO mode and transfer %d data to a off-chip master device.\n", TEST_COUNT);
    printf("In the meanwhile the SPI controller will receive %d data from the off-chip master device.\n", TEST_COUNT);
    printf("After the transfer is done, the %d received data will be printed out.\n", TEST_COUNT);

    for(u32TxDataCount=0; u32TxDataCount<TEST_COUNT; u32TxDataCount++) {
        g_au32SourceData[u32TxDataCount] = 0x00AA0000 + u32TxDataCount;
        g_au32DestinationData[u32TxDataCount] = 0;
    }

    u32TxDataCount = 0;
    u32RxDataCount = 0;
    SPI_TRIGGER(SPI1);

    printf("Press any key if the master device configuration is ready.\n");
    getchar();
    printf("\n");

    while( u32RxDataCount<TEST_COUNT ) {
        if( ((SPI_GET_STATUS(SPI1) & SPI_STATUS_TX_FULL_Msk)==0) && (u32TxDataCount<TEST_COUNT) )
            SPI_WRITE_TX(SPI1, g_au32SourceData[u32TxDataCount++]);

        if((SPI_GET_STATUS(SPI1) & SPI_STATUS_RX_EMPTY_Msk)==0)
            g_au32DestinationData[u32RxDataCount++] = SPI_READ_RX(SPI1);
    }

    printf("Received data:\n");
    for(u32RxDataCount=0; u32RxDataCount<TEST_COUNT; u32RxDataCount++) {
        printf("%d:\t0x%08X\n", u32RxDataCount, g_au32DestinationData[u32RxDataCount]);
    }
    printf("The data transfer was done.\n");

    printf("\n\nExit SPI driver sample code.\n");

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
    CLK_EnableModuleClock(SPI1_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);
    CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL1_SPI1_S_PLL, 0);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* SPI1: GPC12=SS0, GPC15=MOSI0, GPD0=MISO0, GPD1=CLK */
    SYS->GPC_MFPH |= (SYS_GPC_MFPH_PC12_MFP_SPI1_SS0 | SYS_GPC_MFPH_PC15_MFP_SPI1_MOSI0);
    SYS->GPD_MFPL = (SYS_GPD_MFPL_PD0_MFP_SPI1_MISO0 | SYS_GPD_MFPL_PD1_MFP_SPI1_CLK);

    /* Lock protected registers */
    SYS_LockReg();
}
