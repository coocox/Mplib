/**
 *******************************************************************************
 * @file    TB0_print.c
 * @brief   the application functions of TB0_LED demo for the TOSHIBA
 *          'TMPM330' Device Series 
 * @version V1.200
 * @date    2010/06/09
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

#include "tmpm330_tmrb.h"
#include "tmpm330_uart.h"
#include "tmpm330_wdt.h"
#define TMRB_1ms 0x1388U

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);

void TB0_print(void)
{
    TMRB_InitTypeDef myTMRB;
	  WDT_Disable();
    UART_Configuration(UART0);

	  UART_Print(UART0, "This is a TIMER example!\n\r\n\r");
    myTMRB.Mode = TMRB_INTERVAL_TIMER;
    myTMRB.ClkDiv = TMRB_CLK_DIV_8;
    myTMRB.Cycle = TMRB_1ms;    /* Specific value depends on system clock */
    myTMRB.UpCntCtrl = TMRB_AUTO_CLEAR;
    myTMRB.Duty = TMRB_1ms / 2U;        /* Specific value depends on system clock */

    TMRB_Enable(TSB_TB0);
    TMRB_Init(TSB_TB0, &myTMRB);
    TMRB_SetRunState(TSB_TB0, TMRB_RUN);
    NVIC_EnableIRQ(INTTB0_IRQn);
    while (1) {
        /* Do nothing */
    }
}

void UART_Print(TSB_SC_TypeDef * UARTx, char *string)
{
	  char *p = string;
	  int i;
	  while(*p)
	  {
		    UART_SetTxData(UARTx, (uint32_t)(*p));
		    p++;
		    for(i = 0; i < 1000; i ++);
	  }
}

void UART_Configuration(TSB_SC_TypeDef * SCx)
{
    UART_InitTypeDef myUART;
    if (SCx == UART0) {
        TSB_PE_CR_PE0C = 1U;
        TSB_PE_FR1_PE0F1 = 1U;
        TSB_PE_FR1_PE1F1 = 1U;
        TSB_PE_IE_PE1IE = 1U;
    } else if (SCx == UART1) {
        TSB_PE_CR_PE4C = 1U;
        TSB_PE_FR1_PE4F1 = 1U;
        TSB_PE_FR1_PE5F1 = 1U;
        TSB_PE_IE_PE5IE = 1U;
    } else if (SCx == UART2) {
        TSB_PF_CR_PF0C = 1U;
        TSB_PF_FR1_PF0F1 = 1U;
        TSB_PF_FR1_PF1F1 = 1U;
        TSB_PF_IE_PF1IE = 1U;
    } else {
        /* Do nothing */
    }
    myUART.BaudRate = 115200U;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(SCx);
    UART_Init(SCx, &myUART);
}

void INTTB0_IRQHandler(void)
{
    static uint32_t cnt = 0U;

    if (cnt++ >= 1000U) {
        UART_Print(UART0, "Once timer interrupt has happend\n\r");
        cnt = 0U;
    }
}
