/****************************************************************************
 * @file     UART_RS485.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 13/12/04 11:57a $
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

#define IS_USE_RS485NMM   1      //1:Select NMM_Mode , 0:Select AAD_Mode
#define MATCH_ADDRSS1     0xC0
#define MATCH_ADDRSS2     0xA2
#define UNMATCH_ADDRSS1   0xB1
#define UNMATCH_ADDRSS2   0xD3

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8SendData[12] = {0};

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

void RS485_HANDLE(void);
void RS485_SendAddressByte(uint8_t u8data);
void RS485_SendDataByte(uint8_t *pu8TxBuf, uint32_t u32WriteBytes);
void RS485_9bitModeMaster(void);
void RS485_9bitModeSlave(void);
void RS485_FunctionTest(void);

extern char GetChar(void);
void SYS_Init(void);
void UART0_Init();
void UART1_Init();


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/

int UART_RS485(void)
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
    printf("| RS485 function test     |\n");
    printf("+------------------------+\n");

    RS485_FunctionTest();

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
    RS485_HANDLE();
}

/*---------------------------------------------------------------------------------------------------------*/
/* RS485 Callback function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void RS485_HANDLE()
{
    volatile uint32_t addr=0;
    volatile uint32_t regRX=0xFF;
    volatile uint32_t u32IntSts = UART1->ISR;;

    if((u32IntSts & UART_ISR_RLS_INT_Msk)&&(u32IntSts & UART_ISR_RDA_INT_Msk))           /* RLS INT & RDA INT */  //For RS485 Detect Address
    {
        if(UART1->FSR & UART_FSR_RS485_ADD_DETF_Msk) { /* ADD_IF, RS485 mode */
            addr = UART1->RBR;
            UART_RS485_CLEAR_ADDR_FLAG(UART1);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:",addr);

#if (IS_USE_RS485NMM ==1) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if (( addr == MATCH_ADDRSS1)||( addr == MATCH_ADDRSS2)) {
                UART1->FCR &= ~ UART_FCR_RX_DIS_Msk;  /* Enable RS485 RX */
            } else {
                printf("\n");
                UART1->FCR |= UART_FCR_RX_DIS_Msk;      /* Disable RS485 RX */
                UART1->FCR |= UART_FCR_RFR_Msk;       /* Clear data from RX FIFO */
            }
#endif
        }
    } else if((u32IntSts & UART_ISR_RDA_INT_Msk) || (u32IntSts & UART_ISR_TOUT_INT_Msk) ) { /* Rx Ready or Time-out INT*/
        /* Handle received data */
        printf("%2d,",UART1->RBR);
    } else if(u32IntSts & UART_ISR_BUF_ERR_INT_Msk) { /* Buffer Error INT */
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_ISR_BUF_ERR_INT_Msk);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  RS485 Transmit Control  (Address Byte: Parity Bit =1 , Data Byte:Parity Bit =0)                        */
/*---------------------------------------------------------------------------------------------------------*/
void RS485_SendAddressByte(uint8_t u8data)
{
    UART_SetLine_Config(UART1, 0, UART_WORD_LEN_8, UART_PARITY_MARK, UART_STOP_BIT_1);
    UART_WRITE(UART1,u8data);
}

void RS485_SendDataByte(uint8_t *pu8TxBuf, uint32_t u32WriteBytes)
{
    UART_SetLine_Config(UART1, 0, UART_WORD_LEN_8, UART_PARITY_SPACE, UART_STOP_BIT_1);
    UART_Write(UART1,pu8TxBuf,u32WriteBytes);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  RS485 Transmit Test                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
void RS485_9bitModeMaster()
{
    int32_t i32;
    uint8_t g_u8SendDataGroup1[10] = {0};
    uint8_t g_u8SendDataGroup2[10] = {0};
    uint8_t g_u8SendDataGroup3[10] = {0};
    uint8_t g_u8SendDataGroup4[10] = {0};

    printf("\n\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|               RS485 9-bit Master Test                     |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| The function will send different address with 10 data bytes|\n");
    printf("| to test RS485 9-bit mode. Please connect TX/RX to another |\n");
    printf("| board and wait its ready to receive.                      |\n");
    printf("| Press any key to start...                                 |\n");
    printf("+-----------------------------------------------------------+\n\n");
    GetChar();

    /* Set RS485-Master as AUD mode*/
    UART_SelectRS485Mode(UART1, UART_ALT_CSR_RS485_AUD_Msk, 0);

    /* Prepare Data to transmit*/
    for(i32=0; i32<10; i32++) {
        g_u8SendDataGroup1[i32] = i32;
        g_u8SendDataGroup2[i32] = i32+10;
        g_u8SendDataGroup3[i32] = i32+20;
        g_u8SendDataGroup4[i32] = i32+30;
    }
    /* Send For different Address and data for test */
    printf("Send Address %x and data 0~9\n",MATCH_ADDRSS1);
    RS485_SendAddressByte( MATCH_ADDRSS1 );
    RS485_SendDataByte(g_u8SendDataGroup1,10);

    printf("Send Address %x and data 10~19\n",UNMATCH_ADDRSS1);
    RS485_SendAddressByte( UNMATCH_ADDRSS1 );
    RS485_SendDataByte(g_u8SendDataGroup2,10);

    printf("Send Address %x and data 20~29\n",MATCH_ADDRSS2);
    RS485_SendAddressByte( MATCH_ADDRSS2 );
    RS485_SendDataByte(g_u8SendDataGroup3,10);

    printf("Send Address %x and data 30~39\n",UNMATCH_ADDRSS2);
    RS485_SendAddressByte( UNMATCH_ADDRSS2 );
    RS485_SendDataByte(g_u8SendDataGroup4,10);
    printf("Transfer Done\n");
}

/*---------------------------------------------------------------------------------------------------------*/
/*  RS485 Receive Test  (IS_USE_RS485NMM: 0:AAD  1:NMM)                                                    */
/*---------------------------------------------------------------------------------------------------------*/
void RS485_9bitModeSlave()
{
    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART1, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RX Trigger Level = 1 */
    UART1->FCR &= ~UART_FCR_RFITL_Msk;
    UART1->FCR |= UART_FCR_RFITL_1BYTE;

#if(IS_USE_RS485NMM == 1)
    printf("+-----------------------------------------------------------+\n");
    printf("|    Normal Multidrop Operation Mode                        |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| The function is used to test 9-bit slave mode.            |\n");
    printf("| Only Address %2x and %2x,data can receive                  |\n",MATCH_ADDRSS1,MATCH_ADDRSS2);
    printf("+-----------------------------------------------------------+\n");

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART1->FCR |= UART_FCR_RX_DIS_Msk;

    /* Set RS485-NMM Mode */
    UART_SelectRS485Mode(UART1, UART_ALT_CSR_RS485_NMM_Msk|UART_ALT_CSR_RS485_ADD_EN_Msk, 0);

#else
    printf("Auto Address Match Operation Mode\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| The function is used to test 9-bit slave mode.            |\n");
    printf("|    Auto Address Match Operation Mode                      |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|Only Address %2x,data can receive                          |\n",MATCH_ADDRSS1);
    printf("+-----------------------------------------------------------+\n");

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART1, UART_ALT_CSR_RS485_AAD_Msk|UART_ALT_CSR_RS485_ADD_EN_Msk, MATCH_ADDRSS1);
#endif

    /* Enable RDA\RLS\Time-out Interrupt  */
    UART_ENABLE_INT(UART1, (UART_IER_RDA_IEN_Msk | UART_IER_RLS_IEN_Msk | UART_IER_RTO_IEN_Msk));
    NVIC_EnableIRQ(UART1_IRQn);

    printf("Ready to receive data...(Press any key to stop test)\n");
    GetChar();

    /* Flush FIFO */
    while(UART_GET_RX_EMPTY(UART1) != 1) {
        UART_READ(UART1);
    }

    UART_DISABLE_INT(UART1, (UART_IER_RDA_IEN_Msk | UART_IER_RLS_IEN_Msk | UART_IER_RTO_IEN_Msk));

    /* Set UART Function */
    UART_Open(UART1, 115200);
    printf("\n\nEnd test\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  RS485 Function Test                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
void RS485_FunctionTest()
{
    uint32_t u32Item;
    printf("\n\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|            IO Setting                                       |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  ______                                      _______        |\n");
    printf("| |      |                                    |       |       |\n");
    printf("| |Master|---TXD0(pin46) <====> RXD0(pin45)---|Slave  |       |\n");
    printf("| |      |---RTS0(pin39) <====> RTS0(pin39)---|       |       |\n");
    printf("| |______|                                    |_______|       |\n");
    printf("|                                                             |\n");
    printf("+-------------------------------------------------------------+\n\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|       RS485 Function Test                                   |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  Please enable semihosted to show messages on debug session.|\n");
    printf("|  Keil users must define DEBUG_ENABLE_SEMIHOST in both C/C++ |\n");
    printf("|  and Asm preprocessor symbols.                              |\n");
    printf("|  IAR users must define DEBUG_ENABLE_SEMIHOST in both C/C++  |\n");
    printf("|  Compiler and Assembler preprocessor symbols.               |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("|  Please select Master or Slave test                         |\n");
    printf("|  [0] Master    [1] Slave                                    |\n");
    printf("+-------------------------------------------------------------+\n\n");
    u32Item = GetChar();

    /*
        The sample code is used to test RS485 9-bit mode and needs
        two Module test board to complete the test.
        Master:
            1.Set AUD mode and HW will control RTS pin. LEV_RTS is set to '0'.
            2.Master will send four different address with 10 bytes data to test Slave.
            3.Address bytes : the parity bit should be '1'. (Set UA_LCR = 0x2B)
            4.Data bytes : the parity bit should be '0'. (Set UA_LCR = 0x3B)
            5.RTS pin is low in idle state. When master is sending,
              RTS pin will be pull high.

        Slave:
            1.Set AAD and AUD mode firstly. LEV_RTS is set to '0'.
            2.The received byte, parity bit is '1' , is considered "ADDRESS".
            3.The received byte, parity bit is '0' , is considered "DATA".  (Default)
            4.AAD: The slave will ignore any data until ADDRESS match ADDR_MATCH value.
              When RLS and RDA interrupt is happened,it means the ADDRESS is received.
              Check if RS485_ADD_DETF is set and read UA_RBR to clear ADDRESS stored in rx_fifo.

              NMM: The slave will ignore data byte until disable RX_DIS.
              When RLS and RDA interrupt is happened,it means the ADDRESS is received.
              Check the ADDRESS is match or not by user in UART_IRQHandler.
              If the ADDRESS is match,clear RX_DIS bit to receive data byte.
              If the ADDRESS is not match,set RX_DIS bit to avoid data byte stored in FIFO.
    */

    if(u32Item =='0')
        RS485_9bitModeMaster();
    else
        RS485_9bitModeSlave();
}


