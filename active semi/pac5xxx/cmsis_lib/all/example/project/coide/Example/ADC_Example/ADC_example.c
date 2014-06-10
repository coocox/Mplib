/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/21 10:27a $
 * @brief    NUC123 Series ADC Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "ADC.h"
#include "CLOCK.h"
#include "UART.h"
#include "GPIO.h"
#include "SYS.h"

#define DBG_PRINT    printf

volatile BOOL bIsADC0Int = FALSE;
void ADC_Init(void);
void SYS_Init(void);
void UART0_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int ADC_Example (void)
{
    SYS_Init();                                  //En:Init System
    UART0_Init();                                //En:Init UART0

    DBG_PRINT("ADC channel 0 continuous mode test ...... \n");

    ADC_Init();                                //En:Init ADC
    ADC_START_CONVERSION();                    //En:Enable ADC conversion start

    while(1)
    {
        if(bIsADC0Int)
        {
            DBG_PRINT("ADC0 conversion result = %d\n", ADC_GET_RSLT(0));
            bIsADC0Int = FALSE;
        }
    }
}

/**
 * @brief       ADC interrupt handler
 *
 * @param       None
 *
 * @return      None
 *
 * @details     ADC interrupt handler
 */
void ADC_IRQHandler(void)
{
    ADC_CLR_IF(ADC_CONV_DONE_IF);               //En:Clear ADC interrupt status

    if(ADC_IS_RSLT_VALID(0))
        bIsADC0Int = TRUE;
    else
        DBG_PRINT("ADC conversion result has not valid\n");
}

/**
 * @brief       System init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock, GPIO multi-function setting
 */
void SYS_Init(void)
{
    SYS_UnlockReg();                                        //En:Unlock protected registers
    SYS->GPF_MFP |= 3;
    CLK_HXT_ENABLE();                                        //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB)); //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                  //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock

    GPIO_UART0_RXTX();           //En:Set PB multi-function pins for UART0 RXD, UART0 TXD

    GPIO_ADC0();                                //En:Set GPIOD.0 to ADC channel 0 mode
    GPIO_SET_MODE(PD, 0, GPIO_INPUT);
    GPIO_DISABLE_DIGITAL_PATH(PD, 0);

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

    sParam.u32ClkSrc = CLK_UART_HXT;
    sParam.u32ClkDiv = 1;
    sParam.u32ClkFreq = __XTAL;
    sParam.u32BaudRate = 115200;
    sParam.u32cDataBits = UART_WORD_LEN_8;
    sParam.u32cStopBits = UART_STOP_BIT_1;
    sParam.u32cParity = UART_PARITY_NONE;
    sParam.u32cRxTriggerLevel = UART_FCR_RFITL_1BYTE;
    sParam.u32BaudMode = UART_BAUD_MODE2;
    DrvUART_Init (UART0, &sParam);
}

/**
 * @brief       ADC init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set ADC channel 0 continuous mode
 */
void ADC_Init(void)
{
    DrvADC_Init(ADC_CONT_SCAN, 0x01, CLK_ADC_HXT, 6);
    DrvADC_EnableInt();   //En:Enable ADC interrupt
}


