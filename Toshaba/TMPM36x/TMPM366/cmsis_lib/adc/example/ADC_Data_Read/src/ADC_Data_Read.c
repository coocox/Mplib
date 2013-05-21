/** 
 *******************************************************************************
 * @file    ADC_Data_Read.c
 * @brief   the application functions of ADC_Data_Read demo for the TOSHIBA
 *          'TMPM366' Device Series 
 * @version V0.100
 * @date    2011/03/28
 * 
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 * 
 * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
 * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
 * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
 * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm366_uart.h"
#include "tmpm366_gpio.h"
#include "tmpm366_adc.h"
#include <stdio.h>

#define DEMO_TITLE "\
*************************\n\r\
 M366 ADC Data Read Demo \n\r\
*************************\n\r"

#define INDEX_MAX 200U
static uint32_t index = 0;
static char displaybuf[32];
uint8_t fIntADC = 0U;
uint32_t test = 0xffffabcd;

void SIO1_Configuration(void);
void UART_Print(char *string);
void ADC_Display(void);
void Delay(int time);
void INTAD_IRQHandler(void);

void ADC_Data_Read(void)
{
    /* Initialize system */
    SIO1_Configuration();
    //UART_Print(DEMO_TITLE);
    /* Initialize the ADC module */
	/* Enable ADC clock supply */
    ADC_SetClkSupply(ENABLE);

    /* set ADC clock */
    ADC_SetClk(ADC_CONVERSION_CLK_80, ADC_FC_DIVIDE_LEVEL_8);

    /* select ADC input channel */
    ADC_SetInputChannel(ADC_AN_11);

    /* Enable ADC repeat mode */
    ADC_SetRepeatMode(ENABLE);

    /* Set interrupt mode */
    ADC_SetINTMode(ADC_INT_CONVERSION_8);

    /* Turn VREF on */
    ADC_SetVref(ENABLE);

    /* Wait at least 3us to ensure the voltage is stable */
    Delay(10U);
	
    ADC_Start();                /* Start ADC */
	
    /* enable AD interrupt */
    NVIC_EnableIRQ(INTAD_IRQn);

    while (1) {
        if (fIntADC == 1U) {
            fIntADC = 0U;
            ADC_Display();
        }
    }
}

/**
  * @brief  SIO Configuration.
  * @param  SCx
  * @retval None
  */
void SIO1_Configuration()
{
	UART_InitTypeDef myUART;
	GPIO_SetOutputEnableReg(GPIO_PC, GPIO_BIT_0, ENABLE);
	GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_0);
	GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_1);
	GPIO_SetInputEnableReg(GPIO_PC, GPIO_BIT_1, ENABLE);
	GPIO_SetPullUp(GPIO_PC, GPIO_BIT_0, ENABLE);
	GPIO_SetPullUp(GPIO_PC, GPIO_BIT_1, ENABLE);

    /* configure SIO1 for reception */
    myUART.BaudRate = 115200;   /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
	
    UART_Enable(UART1);
    UART_Init(UART1, &myUART);
}

void UART_Print(char *string)
{
	char *p = string;
	int i;
	while(*p)
	{
		UART_SetTxData(UART1, (uint32_t)(*p));
		p++;
		for(i = 0; i < 1000; i ++);
	}
}

/**
  * @brief  Send ADC Date value Time value to UART.
  * @param  None
  * @retval None
  */
void ADC_Display(void)
{
    ADC_Result result = ADC_GetConvertResult(ADC_REG_00);
    
    /* with output switching or not */
    if (result.Bit.OutputSwitching == 1U) {
        return; /* discard this result */
    }

    if (++index == INDEX_MAX) {
        index = 0U;

        sprintf(displaybuf, "ADC Value: %4d\n\r", result.Bit.ADResult);

		UART_Print(DEMO_TITLE);/* display title */
		UART_Print(displaybuf);/* display ADC Value */
		
    }
}

void Delay(int time)
{
    volatile int i = 0;

    for (i = 0; i < (time * 800); ++i);
}
/**
  * @brief  The ADC interrupt request function.
  * @param  None
  * @retval None
  */
void INTAD_IRQHandler(void)
{
    fIntADC = 1U;
}
