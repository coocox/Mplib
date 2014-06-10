/**************************************************************************//**
 * @file     PDMA_SCATTER.c
 * @version  V1.00
 * $Date: 13/11/29 2:57p $
 * @brief    NUC400 Series PDMA Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "nuc400series.h"
#include "SYS.h"
#include "CLK.h"
#include "PDMA.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

uint32_t PDMA_TEST_LENGTH = 64;
uint8_t SrcArray[256];
uint8_t DestArray0[256];
uint8_t DestArray1[256];

typedef struct dma_desc_t {
    uint32_t ctl;
    uint32_t endsrc;
    uint32_t enddest;
    uint32_t offset;
} DMA_DESC_T;

DMA_DESC_T DMA_DESC[2];

void UART0_Init(void);
void SYS_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int PDMA_SCATTER(void)
{
    uint32_t u32EndSrc, u32EndDst0, u32EndDst1;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

    printf("+-----------------------------------------------------------------------+ \n");
    printf("|    NUC400 PDMA Memory to Memory Driver Sample Code (Scatter-gather)   | \n");
    printf("+-----------------------------------------------------------------------+ \n");

    u32EndSrc = (uint32_t)SrcArray + PDMA_TEST_LENGTH * 4;
    u32EndDst0 = (uint32_t)DestArray0 + PDMA_TEST_LENGTH * 4;
    u32EndDst1 = (uint32_t)DestArray1 + PDMA_TEST_LENGTH * 4;

    DMA_DESC[0].ctl = (PDMA_TEST_LENGTH<<PDMA_DSCT_CTRL_TFR_CNT_Pos)|PDMA_WIDTH_32|PDMA_SAR_INC|PDMA_DAR_INC|PDMA_REQ_SINGLE|PDMA_OP_SCATTER;
    DMA_DESC[0].endsrc = u32EndSrc;
    DMA_DESC[0].enddest = u32EndDst0;
    DMA_DESC[0].offset = (uint32_t)&DMA_DESC[1] - (PDMA->SCATBA);
    DMA_DESC[1].ctl = (PDMA_TEST_LENGTH<<PDMA_DSCT_CTRL_TFR_CNT_Pos)|PDMA_WIDTH_32|PDMA_SAR_INC|PDMA_DAR_INC|PDMA_REQ_SINGLE|PDMA_OP_BASIC;
    DMA_DESC[1].endsrc = u32EndDst0;
    DMA_DESC[1].enddest = u32EndDst1;
    DMA_DESC[1].offset = 0;

    /* Open Channel 5 */
    PDMA_Open(1 << 5);
    PDMA_SetTransferMode(5, PDMA_MEM, 1, (uint32_t)&DMA_DESC[0]);
    PDMA_Trigger(5);
    while(PDMA_IS_CH_BUSY(5));

    printf("test done...\n");

    PDMA_Close();
}

/**
 * @brief       DMA IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The DMA default IRQ, declared in startup_nuc400series.s.
 */
void PDMA_IRQHandler(void)
{
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
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(PDMA_MODULE);

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

