/**
 *******************************************************************************
 * @file    FUART_LoopBack.c
 * @brief   The application functions of FUART_LoopBack demo for the
 *          TOSHIBA 'TMPM369' Device Series
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

/* include file */
#include "tmpm369_fuart.h"
#include "tmpm369_gpio.h"


#define MAX_BUFSIZE  10U


void FUART_GPIOConfig(void);
void FUART_ChInit(void);
void FUART_Print(TSB_FUART_TypeDef * FUARTx, char *string);

void FUART_LoopBack(void)
{
    char Tx_Buf[MAX_BUFSIZE] = { 0U };

    uint32_t i = 0U;
    for (; i < MAX_BUFSIZE; i++) {
        Tx_Buf[i] = i+'a';
    }

    FUART_GPIOConfig();         /* Congigure GPIO for FUART4 */
    FUART_ChInit();             /* Initialize FUART4 */

    FUART_Enable(FUART4);

    while (1) {
			
        FUART_Print(FUART4, Tx_Buf);
				FUART_Print(FUART4, "\n\r");
				FUART_Print(FUART4, "Tx Finish\n\r");     /* sending data is finished */  
			
        }
  }

/**
  * @brief  Configure GPIO for Full UART pins, TX02, RX02, CTS2, RTS02
  * @param  None
  * @retval None
  */
void FUART_GPIOConfig(void)
{
    /* Configure port PF1 to be TXD4 */
    GPIO_SetOutput(GPIO_PF, GPIO_BIT_1);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_3, GPIO_BIT_1);

    /* Configure port PF2 to be RXD4 */
    GPIO_SetInput(GPIO_PF, GPIO_BIT_2);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_3, GPIO_BIT_2);

    /* Configure port PF0 to be CTS4 */
    GPIO_SetInput(GPIO_PF, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_3, GPIO_BIT_0);

    /* Configure port PF3 to be RTS4 */
    GPIO_SetOutput(GPIO_PF, GPIO_BIT_3);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_3, GPIO_BIT_3);
}

/**
  * @brief  Initialize Full UART channel 0
  * @param  None
  * @retval None
  */
void FUART_ChInit(void)
{
    FUART_InitTypeDef myFUART;

    myFUART.BaudRate = 115200U;
    myFUART.DataBits = FUART_DATA_BITS_8;
    myFUART.StopBits = FUART_STOP_BITS_1;
    myFUART.Parity = FUART_1_PARITY;
    myFUART.Mode = FUART_ENABLE_TX | FUART_ENABLE_RX;

    FUART_Init(FUART4, &myFUART);
}

/**
  * @brief  Full UART Print
  * @param  FUARTx, string
  * @retval None
  */
void FUART_Print(TSB_FUART_TypeDef * FUARTx, char *string)
{
	  char *p = string;
	  uint32_t i;
	  while(*p)
	  {
		    FUART_SetTxData(FUARTx, (uint32_t)(*p));
		    p++;
		    for(i = 0U; i < 0xFFFFU; i ++);
	  }
}
