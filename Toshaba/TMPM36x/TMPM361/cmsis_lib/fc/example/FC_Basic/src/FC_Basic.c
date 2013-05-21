 /**
 *******************************************************************************
 * @file    FC_Basic.c
 * @brief   The demo functions of FC for the 
 *          TOSHIBA 'TMPM363' Device Series.
 * @version V0.100
 * @date    2010/07/05
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

/* Includes ------------------------------------------------------------------*/

#include "tmpm361_fc.h"
#include "tmpm361_uart.h"

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);

void FC_Basic(void)
{
    FunctionalState tmp_value_sec0, tmp_value_sec1, tmp_value_block;
	
	UART_Configuration(UART);
	UART_Print(UART, "This is an example for FC\n\r");

	/* Set security function "ENABLE" */
	FC_SetSecurityBit(ENABLE);
	UART_Print(UART, "Enable the Security Function\n\r");
	/* Get security register value */
	tmp_value_sec0 = FC_GetSecurityBit();
	if (tmp_value_sec0 != ENABLE) {
		UART_Print(UART, "Security register value is disable\n\r");
	}else{
		UART_Print(UART, "Security register value is enable\n\r");
	}

	/* Set security function "DISABLE" */
	FC_SetSecurityBit(DISABLE);
	UART_Print(UART, "Disable the Security Function\n\r");
	/* Get security register value */
	tmp_value_sec1 = FC_GetSecurityBit();
	if (tmp_value_sec1 != DISABLE) {
		UART_Print(UART, "Security register value is enable\n\r");
	}else{
		UART_Print(UART, "Security register value is diable\n\r");
	}

	/* Get Block 0 Protection status */
	tmp_value_block = FC_GetBlockProtectState(FC_BLOCK_0);
	UART_Print(UART, "Getting Block 0 Protection status\n\r");
	if (tmp_value_block != DISABLE) {
		UART_Print(UART, "The status is enable\n\r");
	}else{
		UART_Print(UART, "The status is diable\n\r");
	}
	
	/* Wait for Ready */
	while (FC_GetBusyState() != DONE) {
		/* Do nothing */
	};

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
        TSB_PE_CR_PE4C = 1;
        TSB_PE_FR2_PE4F2 = 1;
        TSB_PE_FR2_PE5F2 = 1;
        TSB_PE_IE_PE5IE = 1;
    } else {
		//do nothing
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
