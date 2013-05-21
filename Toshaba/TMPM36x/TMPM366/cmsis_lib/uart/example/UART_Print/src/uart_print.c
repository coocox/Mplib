/** 
 *******************************************************************************
 * @file    uart_print.c
 * @brief   the application functions of UART_Retarget demo for the TOSHIBA
 *          'TMPM366' Device Series 
 * @version V0.100
 * @date    2011/02/14
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

void SIO1_Configuration(void);
void UART_Print(char *string);

void uart_print(void)
{
    char TxBuffer[] = "TMPM366";
	
    SIO1_Configuration();
	
    UART_Print(TxBuffer);

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