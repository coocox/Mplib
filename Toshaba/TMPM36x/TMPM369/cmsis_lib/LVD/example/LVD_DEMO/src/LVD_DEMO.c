/**
 *******************************************************************************
 * @file    LVD_DEMO.c
 * @brief   the application functions of LVD demo
 *          for the TOSHIBA 'TMPM369' Device Series
 * @version V0.100
 * @date    2011/09/14
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

#include "TMPM369.h"
#include "tmpm369_lvd.h"
#include "tmpm369_gpio.h"
#include "tmpm369_uart.h"

void UART0_Print(char *string);
void SIO_Configuration(void);
void SIO_ChInit(void);

void LVD_DEMO(void)
{
    SIO_Configuration();
    SIO_ChInit();;
  
    LVD_EnableVD2();
    LVD_SetVD2Level(LVD_VDLVL2_315);

    while (1) {
        if (LVD_GetVD2Status() == LVD_VD_UPPER) {
            UART0_Print("UPPER\n\r");
        } else {
            UART0_Print("LOWER\n\r");      
        }      
    }
}

/**
  * @brief  UART0 Print
  * @param  string
  * @retval None
  */
void UART0_Print(char *string)
{
	  char *p = string;
	  uint32_t i;
	  while(*p)
	  {
		    UART_SetTxData(UART0, (uint32_t)(*p));
		    p++;
		    for(i = 0U; i < 0xFFFFU; i ++);
	  }
}

/**
  * @brief  SIO Configuration.
  * @param  None
  * @retval None
  */
void SIO_Configuration(void)
{ 
     GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_2, ENABLE);
     GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_2, DISABLE);
     GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_2);
}

/**
  * @brief  SIO Configuration Initialize the uart port (SIO1).
  * @param  None
  * @retval None
  */
void SIO_ChInit(void)
{
    UART_InitTypeDef myUART;

    /* configure SIO0 for reception */
    UART_Enable(UART0);
    myUART.BaudRate = 115200U;  /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Init(UART0, &myUART);
}

