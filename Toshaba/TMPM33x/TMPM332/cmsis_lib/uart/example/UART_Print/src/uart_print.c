/** 
 *******************************************************************************
 * @file    uart_print.c
 * @brief   the application functions of UART0 to UART2 demo for the TOSHIBA
 *          'TMPM332' Device Series 
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

#include "tmpm332_uart.h"

UART_InitTypeDef myUART;

void SIO_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(char *string);

void uart_print(void)
{
    TSB_WD_MOD_WDTE = 0U;
    TSB_WD->CR = 0x000000B1;
    SIO_Configuration(UART0);
    myUART.BaudRate = 115200U;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(UART0);
    UART_Init(UART0, &myUART);
		
    UART_Print("Hello World!\n");
}

void UART_Print(char *string)
{
	char *p = string;
	int i;
	while(*p)
	{
		UART_SetTxData(UART0, (uint32_t)(*p));
		p++;
		for(i = 0; i < 1000; i ++);
	}
}

void SIO_Configuration(TSB_SC_TypeDef * SCx)
{
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
    } else {
        /* Do nothing */
    }
}
