/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test WDT reset and restart MCU.
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
#include "WDT.h"
#include "UART.h"

void SYS_Init(void);
void UART0_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int WDT_Example(void)
{
    SYS_Init();	                                        //中:系统初始化//en:System initiation

    UART0_Init();                                       //中:初始化串口//en: Initialize UART
    printf("Press Enter key to start...\n");

    getchar();

    DrvWDT_Init(5,CLK_WDT_LIRC,WDT_RESET_DELAY_128);
    SYS_UnlockReg();
    WDT_ENABLE_RESET();
    WDT_ENABLE_COUNTING();
    WDT_TIMER_RESET();							//en:	Reset the contents of the Watchdog timer
    SYS_LockReg();

    while(1)
   {
//     SYS_UnlockReg();
//     WDT_TIMER_RESET();					   //en: If not clear WDT timer, CPU will reset
//     SYS_LockReg();
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
    sParam.u32ClkSrc  = CLK_UART_HXT;
    sParam.u32ClkDiv  = 1;
    sParam.u32ClkFreq  = __XTAL;			//HXT/1 == __XTAL
    sParam.u32BaudRate = 115200;
    sParam.u32cDataBits = UART_WORD_LEN_8;
    sParam.u32cStopBits  = UART_STOP_BIT_1;
    sParam.u32cParity 	= UART_PARITY_NONE;
    sParam.u32cRxTriggerLevel	= UART_FCR_RFITL_14BYTES;
    sParam.u32BaudMode   = UART_BAUD_MODE2;
    sParam.u8RxTimeOut	 = 200;

    /* Set UART Configuration */
    DrvUART_Init(UART0,&sParam);
    /* Enable UART Interrupt */
    DrvUART_EnableInt(UART0, UART_IER_RDA_IEN|UART_IER_RTO_IEN|UART_IER_TIMEOUT_COUNTER_EN);

}





