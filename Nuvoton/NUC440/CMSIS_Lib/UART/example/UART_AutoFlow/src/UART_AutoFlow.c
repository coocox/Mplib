/****************************************************************************
 * @file     UART_AutoFlow.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 13/12/04 11:53a $
 * @brief    NUC470 Series UART Interface Controller Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "uart.h"


#define RXBUFSIZE 1024

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8SendData[12] = {0};
uint8_t g_u8RecData[RXBUFSIZE]  = {0};

volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;
volatile int32_t g_i32pointer = 0;

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

void UART_TEST_HANDLE(void);
void AutoFlow_FunctionTest(void);
void SYS_Init(void);
void UART0_Init();
void UART1_Init();

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/

int UART_AutoFlow(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();
    /* Init UART0 for printf */
    UART0_Init();

    /* Init UART1 */
    UART1_Init();

    /*---------------------------------------------------------------------------------------------------------*/
    /* SAMPLE CODE                                                                                             */
    /*---------------------------------------------------------------------------------------------------------*/

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

    printf("+--------------------------+\n");
    printf("|  Auto-Flow function test  |\n");
    printf("+--------------------------+\n");

    AutoFlow_FunctionTest();

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
    CLK->PWRCON &= ~CLK_PWRCON_HXT_EN_Msk;
    CLK->PWRCON |= (0x1 << CLK_PWRCON_HXT_EN_Pos); // XTAL12M (HXT) Enabled

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HXT;

    /* Enable IP clock */
    CLK->APBCLK0 |= CLK_APBCLK0_UART0_EN_Msk; // UART0 Clock Enable
    CLK->APBCLK0 |= CLK_APBCLK0_UART1_EN_Msk; // UART1 Clock Enable

    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set PG multi-function pins for UART0 RXD, TXD */
    SYS->GPG_MFPL &= ~(SYS_GPG_MFPL_PG1_MFP_Msk | SYS_GPG_MFPL_PG2_MFP_Msk);
    SYS->GPG_MFPL |= (SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD);

    /* Set PB multi-function pins for UART1 RXD, TXD, RTS and CTS */
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB2_MFP_Msk | SYS_GPB_MFPL_PB3_MFP_Msk |
                       SYS_GPB_MFPL_PB4_MFP_Msk | SYS_GPB_MFPL_PB2_MFP_Msk);
    SYS->GPB_MFPL |= (SYS_GPB_MFPL_PB2_MFP_UART1_RXD | SYS_GPB_MFPL_PB3_MFP_UART1_TXD |
                      SYS_GPB_MFPL_PB4_MFP_UART1_RTS | SYS_GPB_MFPL_PB5_MFP_UART1_CTS);

    /* Lock protected registers */
    SYS_LockReg();

}

void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART0, 115200);
}

void UART1_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART1, 115200);
}

/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 0 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART1_IRQHandler(void)
{
    UART_TEST_HANDLE();
}

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void UART_TEST_HANDLE()
{
    uint8_t u8InChar=0xFF;
    uint32_t u32IntSts= UART1->ISR;

    if(u32IntSts & UART_ISR_RDA_INT_Msk) {
        printf("\nInput:");

        /* Get all the input characters */
        while(UART_IS_RX_READY(UART1)) {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);    /* Rx trigger level is 1 byte*/

            printf("%c ", u8InChar);

            if(u8InChar == '0') {
                g_bWait = FALSE;
            }

            /* Check if buffer full */
            if(g_u32comRbytes < RXBUFSIZE) {
                /* Enqueue the character */
                g_u8RecData[g_u32comRtail] = u8InChar;
                g_u32comRtail = (g_u32comRtail == (RXBUFSIZE-1)) ? 0 : (g_u32comRtail+1);
                g_u32comRbytes++;
            }
        }
        printf("\nTransmission Test:");
    }

    if(u32IntSts & UART_ISR_THRE_INT_Msk) {
        uint16_t tmp;
        tmp = g_u32comRtail;
        if(g_u32comRhead != tmp) {
            u8InChar = g_u8RecData[g_u32comRhead];
            UART_WRITE(UART1,u8InChar);
            g_u32comRhead = (g_u32comRhead == (RXBUFSIZE-1)) ? 0 : (g_u32comRhead+1);
            g_u32comRbytes--;
        }
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*  UART Function Test                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
void AutoFlow_FunctionTest()
{
    uint8_t u8Item;
    uint32_t u32i;
    printf("+-----------------------------------------------------------+\n");
    printf("|     Pin Configure                                         |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  _______                                      _______     |\n");
    printf("| |       |                                    |       |    |\n");
    printf("| |Master |---TXD1    <============>    RXD1---| Slave |    |\n");
    printf("| |       |---RTS1    <============>    CTS1---|       |    |\n");
    printf("| |_______|---CTS1    <============>    RTS1---|_______|    |\n");
    printf("|                                                           |\n");
    printf("+-----------------------------------------------------------+\n\n");

    /* Set RTS Trigger Level */
    UART1->MCR |= UART_RTS_IS_HIGH_LEV_TRG;
    UART1->FCR = (UART1->FCR &~ UART_FCR_RTS_TRI_LEV_Msk) | UART_FCR_RTS_TRI_LEV_14BYTES;

    /* Enable RTS and CTS autoflow control */
    UART1->IER |= UART_IER_AUTO_RTS_EN_Msk | UART_IER_AUTO_CTS_EN_Msk;

    printf("+-----------------------------------------------------------+\n");
    printf("|       AutoFlow Function Test                              |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The sample code needs two boards. One is Master and    |\n");
    printf("|    the other is slave. Master will send 1k bytes data     |\n");
    printf("|    to slave.Slave will check if received data is correct  |\n");
    printf("|    after getting 1k bytes data.                           |\n");
    printf("|  Please select Master or Slave test                       |\n");
    printf("|  [0] Master    [1] Slave                                  |\n");
    printf("+-----------------------------------------------------------+\n\n");
    u8Item = getchar();


    if(u8Item=='0') {
        for(u32i=0; u32i<(RXBUFSIZE-1); u32i++) {
            UART_WRITE(UART1,((u32i+1)&0xFF));

            /* Slave will control RTS pin*/
            while(UART1->MCR & UART_MCR_RTS_ST_Msk);
        }
        printf("\n Transmit Done\n");
    } else {
        g_i32pointer = 0;

        /* Enable RDA\RLS\RTO Interrupt  */
        UART_ENABLE_INT(UART1, (UART_IER_RDA_IEN_Msk | UART_IER_THRE_IEN_Msk | UART_IER_RTO_IEN_Msk));

        /* Set RX Trigger Level = 8 */
        UART1->FCR = (UART1->FCR &~ UART_FCR_RFITL_Msk) | UART_FCR_RFITL_8BYTES;

        /* Set Timeout time 0x3E bit-time */
        UART_SetTimeoutCnt(UART1,0x3E);

        NVIC_EnableIRQ(UART1_IRQn);

        printf("Starting to receive %d bytes data...\n", RXBUFSIZE);

        while(g_i32pointer<(RXBUFSIZE-1)) {
            printf("%d\r",g_i32pointer);
        }

        /* Compare Data */
        for(u32i=0; u32i!=(RXBUFSIZE-1); u32i++) {
            if(g_u8RecData[u32i] != ((u32i+1)&0xFF) ) {
                printf("Compare Data Failed\n");
                while(1);
            }
        }
        printf("\n Receive OK & Check OK\n");
    }

    NVIC_DisableIRQ(UART1_IRQn);

    UART_DISABLE_INT(UART1, (UART_IER_RDA_IEN_Msk | UART_IER_THRE_IEN_Msk | UART_IER_RTO_IEN_Msk));

}


