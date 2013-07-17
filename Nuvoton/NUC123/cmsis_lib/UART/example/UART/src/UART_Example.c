
/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test UART transmit and recieve .
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
#include "UART.h"


#define RXBUFSIZE 64

volatile uint8_t comRbuf[RXBUFSIZE];
volatile uint16_t RX_Index = 0;
volatile uint16_t TX_Index 	= 0;

void SYS_Init(void);
void UART0_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int32_t UART_Example()
{
    SYS_Init();										 //中:系统初始化//en:System initiation
    UART0_Init();

    while(1)
    {
        if(TX_Index != RX_Index)
        {
            while(UART_GET_TX_POINTER(UART0) > 14);             //中:等待发送FIFO有空间//en:Wait until UART transmit FIFO is not full
            UART_WRITE(UART0, comRbuf[TX_Index]);            //中:发送一个字符//en:transmit a char via UART
            TX_Index++;
            if(TX_Index >= RXBUFSIZE)                           //中:测缓冲区满否？//en:Check if buffer full
            {
                TX_Index=0;
            }
        }
    }
}



/**
 * @brief       System init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock
 */
void SYS_Init(void)
{
    SYS_UnlockReg();                                        //En:Unlock protected registers
    GPIO_XT1();
    CLK_HXT_ENABLE();                                    //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB));                  //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                      //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}

/**
 * @brief       UART0 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set UART0 8n1, 115200bps
 */
void UART0_Init(void)
{
    STR_UART_T sParam;

    GPIO_UART0();				//En: Set UART0 all pins to PB0=RX,PB1=TX,PB2=RTS,PB3=CTS

    /* UART Setting */
    sParam.u32ClkSrc	= CLK_UART_HXT;
    sParam.u32ClkDiv	= 1;
    sParam.u32ClkFreq	= __XTAL;			//HXT/1 == __XTAL
    sParam.u32BaudRate 	= 115200;
    sParam.u32cDataBits = UART_WORD_LEN_8;
    sParam.u32cStopBits = UART_STOP_BIT_1;
    sParam.u32cParity 	= UART_PARITY_NONE;
    sParam.u32cRxTriggerLevel	= UART_FCR_RFITL_14BYTES;
    sParam.u32BaudMode    = UART_BAUD_MODE2;
    sParam.u8RxTimeOut	= 200;

    /* Set UART Configuration */
    DrvUART_Init(UART0,&sParam);
    /* Enable UART Interrupt */
    DrvUART_EnableInt(UART0, UART_IER_RDA_IEN|UART_IER_RTO_IEN|UART_IER_TIMEOUT_COUNTER_EN);

}

/**
 * @brief       UART0 ISR routine
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Recieve data in ISR routine
 */
void UART0_IRQHandler(void)
{
    uint8_t tmp;

    if(UART_GET_RDA_INT(UART0)|UART_GET_TOUT_INT(UART0)) //中:检查是否接收中断//en:Check if receive interrupt
    {
        while(UART_GET_RX_EMPTY(UART0)==0)                    //中:检查接收缓冲不为空//en:Check if received data avaliablet
        {
            if(UART_GET_RLS_FLAG(UART0))
            {
                UART_CLEAR_RLS_FLAG(UART0);
                tmp=UART_READ(UART0);//discard the byte
            }
            else
            	comRbuf[RX_Index]=UART_READ(UART0);                //中:读取字符//en:Read the char
            RX_Index++;
            if(RX_Index >= RXBUFSIZE)                     //中:测缓冲区满否？//en:Check if buffer full
            {
                 RX_Index=0;
            }
        }
    }
}
