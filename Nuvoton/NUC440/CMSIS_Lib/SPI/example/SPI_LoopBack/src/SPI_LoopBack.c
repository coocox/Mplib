/**************************************************************************//**
 * @file     SPI_LoopBack.c
 * @version  V1.00
 * $Revision: 5 $
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
#define TEST_COUNT 64

uint32_t g_au32SourceData[TEST_COUNT];
uint32_t g_au32DestinationData[TEST_COUNT];
volatile uint32_t SPI1_INT_Flag;
void SYS_Init(void);

int SPI_LoopBack(void)
{
    uint32_t u32DataCount, u32TestCount, u32Err;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    /* Configure SPI0 as a master, MSB first, 32-bit transaction, SPI Mode-0 timing, clock is 2MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 32, 2000000);

    /* Enable the automatic hardware slave select function. Select the SPI0_SS0 pin and configure as low-active. */
    SPI_EnableAutoSS(SPI0, SPI_SS0, SPI_SS_ACTIVE_LOW);

    /* Configure SPI1 as a slave, MSB first, 32-bit transaction, SPI Mode-0 timing, clock is 4Mhz */
    SPI_Open(SPI1, SPI_SLAVE, SPI_MODE_0, 32, 4000000);

    /* Configure SPI1 as a low level active device. */
    SPI_SET_SS0_LOW(SPI1);

    printf("\n\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("|                       SPI Driver Sample Code                         |\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("\n");

    printf("Configure SPI0 as a master and SPI1 as a slave.\n");
    printf("Data width of a transaction: 32\n");
    printf("SPI clock rate: %d Hz\n", SPI_GetBusClock(SPI0));
    printf("The I/O connection for SPI0/SPI1 loopback:\n");
    printf("    SPI0_SS  (PE.4) <--> SPI1_SS(PC.12)\n    SPI0_CLK(PE.5)  <--> SPI1_CLK(PD.1)\n");
    printf("    SPI0_MISO(PE.2) <--> SPI1_MISO(PD.0)\n    SPI0_MOSI(PE.3) <--> SPI1_MOSI(PC.15)\n\n");
    printf("Please connect SPI0 with SPI1, and press any key to start transmission ...");
    getchar();
    printf("\n");

    printf("\nSPI0/1 Loopback test ");

    /* Enable the SPI1 unit transfer interrupt. */
    SPI_EnableInt(SPI1, SPI_IE_MASK);
    NVIC_EnableIRQ(SPI1_IRQn);
    SPI_TRIGGER(SPI1);

    u32Err = 0;
    for(u32TestCount=0; u32TestCount<10000; u32TestCount++) {
        /* set the source data and clear the destination buffer */
        for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++) {
            g_au32SourceData[u32DataCount] = u32DataCount;
            g_au32DestinationData[u32DataCount] = 0;
        }

        u32DataCount=0;
        SPI1_INT_Flag = 0;

        if((u32TestCount&0x1FF) == 0) {
            putchar('.');
        }

        SPI_TRIGGER(SPI0);
        /* write the first data of source buffer to Tx register of SPI0. And start transmission. */
        SPI_WRITE_TX(SPI0, g_au32SourceData[0]);

        while(1) {
            if(SPI1_INT_Flag==1) {
                SPI1_INT_Flag = 0;

                if(u32DataCount<(TEST_COUNT-1)) {
                    /* Read the previous retrieved data and trigger next transfer. */
                    g_au32DestinationData[u32DataCount] = SPI_READ_RX(SPI1);
                    u32DataCount++;
                    /* Write data to SPI0 Tx buffer and trigger the transfer */
                    SPI_WRITE_TX(SPI0, g_au32SourceData[u32DataCount]);
                } else {
                    /* Just read the previous retrieved data but trigger next transfer, because this is the last transfer. */
                    g_au32DestinationData[u32DataCount] = SPI_READ_RX(SPI1);
                    break;
                }
            }
        }

        /*  Check the received data */
        for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++) {
            if(g_au32DestinationData[u32DataCount]!=g_au32SourceData[u32DataCount])
                u32Err = 1;
        }

        if(u32Err)
            break;
    }
    /* Disable the SPI1 unit transfer interrupt. */
    SPI_DisableInt(SPI1, SPI_IE_MASK);
    NVIC_DisableIRQ(SPI1_IRQn);

    if(u32Err)
        printf(" [FAIL]\n\n");
    else
        printf(" [PASS]\n\n");


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
    CLK_EnableModuleClock(SPI0_MODULE);
    CLK_EnableModuleClock(SPI1_MODULE);

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

    /* SPI1: GPC12=SS0, GPC15=MOSI0, GPD0=MISO0, GPD1=CLK */
    SYS->GPC_MFPH |= (SYS_GPC_MFPH_PC12_MFP_SPI1_SS0 | SYS_GPC_MFPH_PC15_MFP_SPI1_MOSI0);
    SYS->GPD_MFPL = (SYS_GPD_MFPL_PD0_MFP_SPI1_MISO0 | SYS_GPD_MFPL_PD1_MFP_SPI1_CLK);

    /* Lock protected registers */
    SYS_LockReg();
}

void SPI1_IRQHandler(void)
{
    if( SPI1->STATUS & SPI_STATUS_UNIT_INTSTS_Msk ) { /* Check the unit transfer interrupt flag */
        SPI1->STATUS = SPI_STATUS_UNIT_INTSTS_Msk;   /* write '1' to clear SPI1 uint transfer interrupt flag */
        SPI1_INT_Flag = 1;
    }
}
