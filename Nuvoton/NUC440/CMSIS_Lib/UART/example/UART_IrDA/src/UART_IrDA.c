/****************************************************************************
 * @file     UART_IrDA.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 13/12/04 11:55a $
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
void IrDA_FunctionTxTest(void);
void IrDA_FunctionRxTest(void);
void IrDA_FunctionTest(void);

extern char GetChar(void);
void SYS_Init(void);
void UART0_Init();
void UART1_Init();


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/

int UART_IrDA(void)
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

    printf("+------------------------+\n");
    printf("| IrDA function test |\n");
    printf("+------------------------+\n");

    IrDA_FunctionTest();

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

}

/*---------------------------------------------------------------------------------------------------------*/
/*  IrDA Function Test                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
void IrDA_FunctionTest()
{
    uint8_t u8item;

    printf("+-------------------------------------------------------------+\n");
    printf("|     Pin Configure                                           |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  ______                                      _______        |\n");
    printf("| |      |                                    |       |       |\n");
    printf("| |Master|---TXD0(pin46) <====> RXD0(pin45)---|Slave  |       |\n");
    printf("| |      |                                    |       |       |\n");
    printf("| |______|                                    |_______|       |\n");
    printf("|                                                             |\n");
    printf("+-------------------------------------------------------------+\n");

    printf("\n\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|     IrDA Function Test                                      |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  Please enable semihosted to show messages on debug session |\n");
    printf("|  Keil users must define DEBUG_ENABLE_SEMIHOST in both C/C++ |\n");
    printf("|  and Asm preprocessor symbols.                              |\n");
    printf("|  IAR users must define DEBUG_ENABLE_SEMIHOST in both C/C++  |\n");
    printf("|  Compiler and Assembler preprocessor symbols.               |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  Description :                                              |\n");
    printf("|    The sample code needs two boards. One is Master and      |\n");
    printf("|    the other is slave.  Master will send data based on      |\n");
    printf("|    terminal input and Slave will printf received data on    |\n");
    printf("|    terminal screen.                                         |\n");
    printf("|  Please select Master or Slave test                         |\n");
    printf("|  [0] Master    [1] Slave                                    |\n");
    printf("+-------------------------------------------------------------+\n\n");
    u8item = GetChar();

    if(u8item=='0')
        IrDA_FunctionTxTest();
    else
        IrDA_FunctionRxTest();

    printf("\nIrDA Sample Code End.\n");

}

/*---------------------------------------------------------------------------------------------------------*/
/*  IrDA Function Transmit Test                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void IrDA_FunctionTxTest()
{
    uint8_t u8OutChar;

    printf("\n\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|     IrDA Function Tx Mode Test                            |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1). Input char by UART terminal.                         |\n");
    printf("| 2). UART will send a char according to step 1.           |\n");
    printf("| 3). Return step 1. (Press '0' to exit)                    |\n");
    printf("+-----------------------------------------------------------+\n\n");

    printf("\nIRDA Sample Code Start. \n");

    /* Select IrDA Tx mode and set baud rate */
    UART_SelectIrDAMode(UART1, 57600, TRUE); // TRUE is TX mode

    /* Wait Terminal input to send data to UART TX pin */
    do {
        u8OutChar = GetChar();
        printf("   Input: %c , Send %c out\n",u8OutChar,u8OutChar);
        UART_WRITE(UART1,u8OutChar);
    } while(u8OutChar !='0');

}

/*---------------------------------------------------------------------------------------------------------*/
/*  IrDA Function Receive Test                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
void IrDA_FunctionRxTest()
{
    uint8_t u8InChar=0xFF;

    printf("\n\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|     IrDA Function Rx Mode Test                            |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1). Polling RDA_Flag to check data input though UART     |\n");
    printf("| 2). If received data is '0', the program will exit.       |\n");
    printf("|     Otherwise, print received data on terminal            |\n");
    printf("+-----------------------------------------------------------+\n\n");

    /* Select IrDA Rx mode and set baud rate */
    UART_SelectIrDAMode(UART1, 57600, FALSE); // FALSE is RX mode

    printf("Waiting...\n");

    /* Use polling method to wait master data */
    do {
        if( UART_IS_RX_READY(UART1)) {
            u8InChar = UART_READ(UART1);
            printf("   Input: %c \n",u8InChar);
        }
    } while(u8InChar !='0');

}

