/**************************************************************************//**
 * @file     PDMA_Example.c
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
uint8_t DestArray[256];
uint32_t volatile u32IsTestOver = 0;

void SYS_Init(void);
void UART0_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int PDMA_Example(void)
{
    uint32_t u32EndSrc, u32EndDst;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

    printf("+------------------------------------------------------+ \n");
    printf("|    NUC400 PDMA Memory to Memory Driver Sample Code   | \n");
    printf("+------------------------------------------------------+ \n");

    /* Open Channel 2 */
    PDMA_Open(1 << 2);
    PDMA_SetTransferCnt(2, PDMA_WIDTH_32, PDMA_TEST_LENGTH);
    u32EndSrc = (uint32_t)SrcArray + PDMA_TEST_LENGTH * 4;
    u32EndDst = (uint32_t)DestArray + PDMA_TEST_LENGTH * 4;
    PDMA_SetTransferAddr(2, u32EndSrc, PDMA_SAR_INC, u32EndDst, PDMA_DAR_INC);
    PDMA_SetTransferMode(2, PDMA_MEM, 0, 0);
    PDMA_SetBurstType(2, PDMA_REQ_BURST, PDMA_BURST_4);
    PDMA_SetTimeOut(2, 0, 0x5);
    PDMA_EnableInt(2, 0);
    NVIC_EnableIRQ(PDMA_IRQn);
    u32IsTestOver = 0;
    PDMA_Trigger(2);
    while(u32IsTestOver == 0);

    if (u32IsTestOver == 1)
        printf("test done...\n");
    else if (u32IsTestOver == 2)
        printf("target abort...\n");
    else if (u32IsTestOver == 3)
        printf("timeout...\n");

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
    uint32_t status = PDMA_GET_INT_STATUS();

    if (status & 0x1) { /* abort */
        if (PDMA_GET_ABORT_STS() & 0x4)
            u32IsTestOver = 2;
        PDMA_CLR_ABORT_FLAG(PDMA_ABTF_TABORT_F_Msk);
    } else if (status & 0x2) { /* done */
        if (PDMA_GET_TD_STS() & 0x4)
            u32IsTestOver = 1;
        PDMA_CLR_TD_FLAG(PDMA_TDF_TD_F_Msk);
    } else if (status & 0x400) { /* channel 2 timeout */
        u32IsTestOver = 3;
        PDMA_CLR_TMOUT_FLAG(2);
    } else
        printf("unknown interrupt !!\n");
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
