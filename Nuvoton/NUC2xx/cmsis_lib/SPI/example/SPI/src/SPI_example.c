/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/03 5:46p $
 * @brief    NUC200 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "SYS.h"
#include "GPIO.h"
#include "UART.h"
#include "SPI.h"
#include "PDMA.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000



#define TEST_COUNT 64

uint32_t g_au32SourceData[TEST_COUNT];
uint32_t g_au32DestinationData[TEST_COUNT];
volatile uint32_t g_u32TxDataCount;
volatile uint32_t g_u32RxDataCount;
volatile uint32_t SPI1_INT_Flag;

void SYS_Init(void);
void UART0_Init(void);
void SPI_Init(void);
void SpiLoopbackTest(void);
void SpiLoopbackTest_WithPDMA(void);
void SpiMasterMode(void);
void SpiSlaveMode(void);


void SPI_Example(void)
{
    uint32_t u32KeyOption;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init SPI */
    SPI_Init();

    while(1)
    {
//        printf("\n\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("|                       SPI Driver Sample Code                         |\n");
        printf("+----------------------------------------------------------------------+\n");
//        printf("\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("|  [1] SPI loopback test                                               |\n");
        printf("|  [2] SPI loopback test with PDMA                                     |\n");
        printf("|  [3] SPI master mode                                                 |\n");
        printf("|  [4] SPI slave mode                                                  |\n");
        printf("|  [Others] Quit                                                       |\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("Please choose a item: ");

        u32KeyOption = uart_getchar();
//        printf("\n");
        if(u32KeyOption=='1')
            SpiLoopbackTest();
        else if(u32KeyOption=='2')
            SpiLoopbackTest_WithPDMA();
        else if(u32KeyOption=='3')
            SpiMasterMode();
        else if(u32KeyOption=='4')
            SpiSlaveMode();
        else
            break;
    }

    printf("\n\nExit SPI driver sample code.\n");

    /* Disable SPI0 and SPI1 IP clock */
    SYSCLK->APBCLK &= (~(SYSCLK_APBCLK_SPI0_EN_Msk | SYSCLK_APBCLK_SPI1_EN_Msk));
    return 0;
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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_SPI0_EN_Msk | SYSCLK_APBCLK_SPI1_EN_Msk;
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
    /* Set PB multi-function pins for UART0 RXD and TXD  */
    SYS->GPB_MFP = SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB0_RXD0;
    /* Set PC0, PC1, PC2 and PC3 for SPI0; set PC8, PC9, PC10 and PC11 for SPI1 */
    SYS->GPC_MFP = SYS_GPC_MFP_PC0_SPISS00 | SYS_GPC_MFP_PC1_SPICLK0 | SYS_GPC_MFP_PC2_MISO00 | SYS_GPC_MFP_PC3_MOSI00 |
                   SYS_GPC_MFP_PC8_SPISS10 | SYS_GPC_MFP_PC9_SPICLK1 | SYS_GPC_MFP_PC10_MISO10 | SYS_GPC_MFP_PC11_MOSI10;
    SYS->ALT_MFP = 0;

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

void SPI_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init SPI                                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
    /* Configure SPI0 as a master, clock idle low, falling clock edge Tx, rising edge Rx and 32-bit transaction */
    SPI0->CNTRL = SPI_CNTRL_MASTER_MODE | SPI_CNTRL_CLK_IDLE_LOW | SPI_CNTRL_TX_FALLING |
                  SPI_CNTRL_RX_RISING | SPI_CNTRL_TX_BIT_LEN(32);
    /* Enable the automatic hardware slave select function. Select the SS pin and configure as low-active. */
    SPI0->SSR = SPI_SSR_HW_AUTO_ACTIVE_LOW;
    /* Set IP clock divider. SPI clock rate = HCLK / ((9+1)*2) = 2.5MHz */
    SPI0->DIVIDER = SPI0->DIVIDER & (~SPI_DIVIDER_DIVIDER_Msk) | SPI_DIVIDER_DIV(9);

    /* Configure SPI1 as a slave, clock idle low, falling clock edge Tx, rising edge Rx and 32-bit transaction */
    SPI1->CNTRL = SPI_CNTRL_SLAVE_MODE | SPI_CNTRL_CLK_IDLE_LOW | SPI_CNTRL_TX_FALLING |
                  SPI_CNTRL_RX_RISING | SPI_CNTRL_TX_BIT_LEN(32);
    /* Configure SPI1's slave select signal as a low level active device. */
    SPI1->SSR = SPI_SSR_SLAVE_LOW_LEVEL_ACTIVE;
}

void SpiLoopbackTest(void)
{
    uint32_t u32DataCount, u32TestCount, u32Err;

    printf("Configure SPI0 as a master and SPI1 as a slave.\n");
    printf("Bit length of a transaction: 32\n");
    printf("SPI clock rate: %d Hz\n", SPI_GetSpi0Clock1Freq());
    printf("The I/O connection for SPI0/SPI1 loopback:\n");
    printf("    SPI0_SS  (PC.0) <--> SPI1_SS(PC.8)\n    SPI0_CLK(PC.1)  <--> SPI1_CLK(PC.9)\n");
    printf("    SPI0_MISO(PC.2) <--> SPI1_MISO(PC.10)\n    SPI0_MOSI(PC.3) <--> SPI1_MOSI(PC.11)\n\n");
    printf("Please connect SPI0 with SPI1, and press any key to start transmission ...");
    uart_getchar();
//    printf("\n");

    printf("\nSPI0/1 Loopback test ");

    /* Enable the SPI1 unit transfer interrupt. */
    SPI1->CNTRL |= SPI_CNTRL_IE_Msk;
    NVIC_EnableIRQ(SPI1_IRQn);

    /* Clear Tx register of SPI1 to avoid send non-zero data to Master. Just for safe. */
    _SPI_WRITE_TX_BUFFER0(SPI1, 0);

    u32Err = 0;
    for(u32TestCount=0; u32TestCount<10000; u32TestCount++)
    {
        /* set the soure data and clear the destination buffer */
        for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++)
        {
            g_au32SourceData[u32DataCount] = u32DataCount;
            g_au32DestinationData[u32DataCount] = 0;
        }

        u32DataCount=0;
        SPI1_INT_Flag = 0;

        if((u32TestCount&0x1FF) == 0)
        {
            printf("..");
        }
        /* set the GO_BUSY bit of SPI1 */
        _SPI_SET_GO(SPI1);
        /* write the first data of source buffer to Tx register of SPI0. And start transmission. */
        _SPI_WRITE_TX_BUFFER0(SPI0, g_au32SourceData[0]);
        _SPI_SET_GO(SPI0);

        while(1)
        {
            if(SPI1_INT_Flag==1)
            {
                SPI1_INT_Flag = 0;

                if(u32DataCount<(TEST_COUNT-1))
                {
                    /* Read the previous retrived data and trigger next transfer. */
                    g_au32DestinationData[u32DataCount] = _SPI_GET_RX0_DATA(SPI1);
                    _SPI_SET_GO(SPI1);
                    u32DataCount++;
                    /* Write data to SPI0 Tx buffer and trigger the transfer */
                    _SPI_WRITE_TX_BUFFER0(SPI0, g_au32SourceData[u32DataCount]);
                    _SPI_SET_GO(SPI0);
                }
                else
                {
                    /* Just read the previous retrieved data but trigger next transfer, because this is the last transfer. */
                    g_au32DestinationData[u32DataCount] = _SPI_GET_RX0_DATA(SPI1);
                    break;
                }
            }
        }

        /*  Check the received data */
        for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++)
        {
            if(g_au32DestinationData[u32DataCount]!=g_au32SourceData[u32DataCount])
                u32Err = 1;
        }

        if(u32Err)
            break;
    }
    /* Disable the SPI1 unit transfer interrupt. */
    SPI1->CNTRL &= (~SPI_CNTRL_IE_Msk);
    NVIC_DisableIRQ(SPI1_IRQn);

    if(u32Err)
        printf(" [FAIL]\n\n");
    else
        printf(" [PASS]\n\n");

    return ;
}

void SpiMasterMode(void)
{
    uint32_t u32DataCount;

    printf("Configure SPI0 as a master.\n");
    printf("SPI clock rate: %d Hz\n", SPI_GetSpi0Clock1Freq());
    printf("SPI controller will enable FIFO mode and transfer 16 data to a off-chip slave device.\n");
    printf("In the meanwhile the SPI controller will receive 16 data from the off-chip slave device.\n");
    printf("After the transfer is done, the 16 received data will be printed out.\n");
    printf("Configure the SPI master ... ");

    for(u32DataCount=0; u32DataCount<16; u32DataCount++)
    {
        g_au32SourceData[u32DataCount] = 0x00550000 + u32DataCount;
        g_au32DestinationData[u32DataCount] = 0;
    }

    /* Set Tx FIFO threshold, enable Tx FIFO threshold interrupt and time-out interrupt */
    SPI0->FIFO_CTL = SPI_FIFO_CTL_TX_THRESHOLD(4) | SPI_FIFO_CTL_TIMEOUT_INT_EN | SPI_FIFO_CTL_TX_INT_EN;
    NVIC_EnableIRQ(SPI0_IRQn);
    g_u32TxDataCount = 0;
    g_u32RxDataCount = 0;

    printf("OK\n");
    printf("Before starting the data transfer, make sure the slave device is ready. Press any key to start the transfer.\n");
    uart_getchar();
//    printf("\n");

    /* Enable FIFO mode */
    _SPI_ENABLE_FIFO_MODE(SPI0);

    /* Wait for transfer done */
    while(g_u32RxDataCount<16);

    printf("Received data:\n");
    for(u32DataCount=0; u32DataCount<16; u32DataCount++)
    {
        printf("%d:\t0x%08X\n", u32DataCount, g_au32DestinationData[u32DataCount]);
    }
    /* Disable Tx FIFO threshold interrupt and time-out interrupt */
    SPI0->FIFO_CTL = 0;
    NVIC_DisableIRQ(SPI0_IRQn);
    /* Disable FIFO mode */
    _SPI_DISABLE_FIFO_MODE(SPI0);
    printf("The data transfer was done.\n\n");
}

void SpiSlaveMode(void)
{
    uint32_t u32TxDataCount, u32RxDataCount;

    printf("Configure SPI1 as a slave.\n");
    printf("SPI slave engine clock rate: %d Hz\n", SPI_GetSpi1Clock1Freq());
    printf("SPI controller will enable FIFO mode and transfer 16 data to a off-chip master device.\n");
    printf("In the meanwhile the SPI controller will receive 16 data from the off-chip master device.\n");
    printf("After the transfer is done, the 16 received data will be printed out.\n");

    for(u32TxDataCount=0; u32TxDataCount<16; u32TxDataCount++)
    {
        g_au32SourceData[u32TxDataCount] = 0x00AA0000 + u32TxDataCount;
        g_au32DestinationData[u32TxDataCount] = 0;
    }

    u32TxDataCount = 0;
    u32RxDataCount = 0;
    printf("Press any key if the master device configuration is ready.\n");
    uart_getchar();
//    printf("\n");

    /* Enable FIFO mode */
    _SPI_ENABLE_FIFO_MODE(SPI1);
    while( u32RxDataCount<16 )
    {
        if( (_SPI_GET_TX_FIFO_FULL_FLAG(SPI1)==0) && (u32TxDataCount<16) )
            _SPI_WRITE_TX_BUFFER0(SPI1, g_au32SourceData[u32TxDataCount++]);
        if(_SPI_GET_RX_FIFO_EMPTY_FLAG(SPI1)==0)
            g_au32DestinationData[u32RxDataCount++] = _SPI_GET_RX0_DATA(SPI1);
    }

    printf("Received data:\n");
    for(u32RxDataCount=0; u32RxDataCount<16; u32RxDataCount++)
    {
        printf("%d:\t0x%08X\n", u32RxDataCount, g_au32DestinationData[u32RxDataCount]);
    }
    /* Disable FIFO mode */
    _SPI_DISABLE_FIFO_MODE(SPI1);
    printf("SPI engine clock rate: %d Hz\n", SPI_GetSpi1Clock1Freq());
    printf("The data transfer was done.\n\n");
}

void SpiLoopbackTest_WithPDMA(void)
{
    uint32_t au32SourceData[TEST_COUNT];
    uint32_t au32DestinationData[TEST_COUNT];
    uint32_t u32DataCount, u32TestCycle;
    int32_t i32Err;

    printf("Configure SPI0 as a master and SPI1 as a slave.\n");
    printf("Bit length of a transaction: 32\n");
    printf("SPI clock rate: %d Hz\n", SPI_GetSpi0Clock1Freq());
    printf("The I/O connection for SPI0/SPI1 loopback:\n");
    printf("    SPI0_SS  (PC.0) <--> SPI1_SS(PC.8)\n    SPI0_CLK(PC.1)  <--> SPI1_CLK(PC.9)\n");
    printf("    SPI0_MISO(PC.2) <--> SPI1_MISO(PC.10)\n    SPI0_MOSI(PC.3) <--> SPI1_MOSI(PC.11)\n\n");
    printf("Please connect SPI0 with SPI1, and press any key to start transmission ...");
    uart_getchar();
//    printf("\n");
    printf("\nSPI0/1 Loopback test with one PDMA Rx channel");

    /* set the soure data and clear the destination buffer */
    for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++)
    {
        au32SourceData[u32DataCount] = u32DataCount;
        au32DestinationData[u32DataCount] = 0;
    }

    /* PDMA Init */
    SYSCLK->AHBCLK |= SYSCLK_AHBCLK_PDMA_EN_Msk;
    _PDMAGCR_PDSSR0_SPI1_RXSEL(0);
    /* Enable PDMA channel 0 clock */
    PDMA_GCR->GCRCSR |= PDMA_GCRCSR_CLK0_EN_Msk;
    /* Enable PDMA channel 0, Set Source/destination transfer direction,
       Set PDMA mode, Set peripheral transfer width */
    PDMA0->CSR = PDMA_CSR_PDMACEN_Msk | PDMA_CSR_SAD_SEL_FIXED | PDMA_CSR_DAD_SEL_INCREASE |
                 PDMA_CSR_APB_TWS_32BITS | PDMA_CSR_MODE_SEL_P2M;
    PDMA0->SAR = (uint32_t)&(SPI1->RX[0]);        /* Set Source Address */
    PDMA0->DAR = (uint32_t)au32DestinationData;   /* Set Destination Address */
    PDMA0->BCR = TEST_COUNT*4;

    i32Err = 0;
    for(u32TestCycle=0; u32TestCycle<10000; u32TestCycle++)
    {
        if((u32TestCycle&0x1FF) == 0)
            printf("..");

        /* Enable SPI PDMA and Trigger PDMA specified Channel */
        /* Trigger PDMA0 */
        PDMA0->CSR|= PDMA_CSR_TRIG_EN_Msk;
        _SPI_ENABLE_RX_PDMA(SPI1);

        /* set the GO_BUSY bit of SPI1 */
        _SPI_SET_GO(SPI1);

        u32DataCount = 0;

        while(u32DataCount<TEST_COUNT)
        {
            /* write the data of source buffer to Tx register of SPI0. And start transmission. */
            _SPI_WRITE_TX_BUFFER0(SPI0, au32SourceData[u32DataCount++]);
            /* set the GO_BUSY bit of SPI0 */
            _SPI_SET_GO(SPI0);
            /* Wait for transfer done */
            while(_SPI_GET_UNIT_TRANS_INT_FLAG(SPI0)==0);
            /* Clear the SPI unit transfer interrupt flag */
            _SPI_CLR_UNIT_TRANS_INT_FLAG(SPI0);
        }

        /* Wait PDMA transfer done */
        while((PDMA0->ISR&PDMA_ISR_BLKD_IF_Msk) == 0);
        /* Clear Block transfer down interrupt flag */
        PDMA0->ISR = PDMA_ISR_BLKD_IF_Msk;

        /* Compare the transfer data */
        for(u32DataCount=0; u32DataCount<TEST_COUNT; u32DataCount++)
        {
            if(au32DestinationData[u32DataCount]!=au32SourceData[u32DataCount])
                i32Err = 1;
        }

        if(i32Err)
            break;
    }

    /* Disable PDMA clock */
    SYSCLK->AHBCLK &= ~SYSCLK_AHBCLK_PDMA_EN_Msk;
    PDMA_GCR->GCRCSR = 0;

    if(i32Err)
    {
        printf(" [FAIL]\n\n");
    }
    else
    {
        printf(" [PASS]\n\n");
    }

    return;
}

void SPI0_IRQHandler(void)
{
    while(_SPI_GET_RX_FIFO_EMPTY_FLAG(SPI0)==0)
    {
        g_au32DestinationData[g_u32RxDataCount++] = _SPI_GET_RX0_DATA(SPI0);
    }
    while( (_SPI_GET_TX_FIFO_FULL_FLAG(SPI0)==0) && (g_u32TxDataCount<16) )
    {
        _SPI_WRITE_TX_BUFFER0(SPI0, g_au32SourceData[g_u32TxDataCount++]);
    }
    if(g_u32TxDataCount>=16)
        _SPI_DISABLE_TX_THRESHOLD_INT(SPI0);

    /* Check the Rx FIFO time-out interrupt flag */
    if( _SPI_GET_RX_FIFO_TIMEOUT_FLAG(SPI0) )
    {
        while(_SPI_GET_RX_FIFO_EMPTY_FLAG(SPI0)==0)
            g_au32DestinationData[g_u32RxDataCount++] = _SPI_GET_RX0_DATA(SPI0);
    }
}

void SPI1_IRQHandler(void)
{
    if( _SPI_GET_UNIT_TRANS_INT_FLAG(SPI1) == 1 ) /* Check the one transaction done interrupt flag */
    {
        _SPI_CLR_UNIT_TRANS_INT_FLAG(SPI1);   /* write '1' to clear SPI1 interrupt flag */
        SPI1_INT_Flag = 1;
    }
}

