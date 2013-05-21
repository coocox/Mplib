/**
********************************************************************************
 * @file   KWUP_Demo.c
 * @brief  the application functions of KWUP demo for the TOSHIBA
             'TMPM362' Device Series 
 * @version V0.100
 * @date    2010/07/28
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
#include "tmpm362_kwup.h"
#include "tmpm362_uart.h"

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
void INTKWUP_IRQHandler(void);

void KWUP_Demo(void)
{
    KWUP_SettingTypeDef keySetting;
    KWUP_PortStatus portStatus;
    SystemInit();
	UART_Configuration(UART);
    /* set PJ4,PJ5 to Key0,1 */
    TSB_PJ_FR2_PJ4F2 = 1U;
    TSB_PJ_PUP_PJ4UP = 1U;
    TSB_PJ_IE_PJ4IE = 1U;

    TSB_PJ_FR2_PJ5F2 = 1U;
    TSB_PJ_PUP_PJ5UP = 1U;
    TSB_PJ_IE_PJ5IE = 1U;

	UART_Print(UART, "This is an example for KWUP operation\n\r");
    /* enable KWUP interrupt */
    NVIC_ClearPendingIRQ(INTKWUP_IRQn);
    NVIC_EnableIRQ(INTKWUP_IRQn);

    keySetting.KeyN = KWUP_INPUT_0;
    keySetting.PullUpCtrl = KWUP_PUP_CTRL_BY_DYNAMIC;
    keySetting.ActiveState = KWUP_ACTIVE_BY_RISING_EDGE;
    keySetting.INTNewState = ENABLE;
    KWUP_SetConfig(&keySetting);

    KWUP_SetPullUpConfig(KWUP_CYCLES_4_FS, KWUP_CYCLES_256_FS);

    KWUP_ClearINTReq();

    /* enable low power mode release interrupt to KWUP */
    TSB_CG->IMCGF = 0x1000U;
    TSB_CG->IMCGF += 0x0100U;

    do {
        portStatus = KWUP_GetPortStatus();
		UART_Print(UART, "Please press key(PJ5) to enter low power mode\n\r");
		while(portStatus.Bit.Key1 != 0U)/* press key(PJ5) */
		{
			portStatus = KWUP_GetPortStatus();
		}
		UART_Print(UART, "enter low power mode\n\r");
		/* enter low power mode */
		UART_Print(UART, "press KEY(PJ4) to release low power mode\n\r");
		__WFI();

		/* press KEY(PJ4) to release low power mode */
		UART_Print(UART, "release low power mode\n\r");
        
    }while (1);
}


void INTKWUP_IRQHandler(void)
{
    #define CG_INT_SRC_KWUP 21U
    KWUP_ClearINTReq();
    TSB_CG->ICRCG = CG_INT_SRC_KWUP;
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
