/** 
 *******************************************************************************
 * @file    uart.c
 * @brief   the application functions of UART_Retarget demo for the TOSHIBA
 *          'TMPM061' Device Series 
 * @version V0.100
 * @date    2012/05/14
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "uart.h"

/* Private define ------------------------------------------------------------*/
char gSIOTxBuffer[BUFFER_SIZE] = { 0 };

uint8_t gSIORdIndex = 0U;
uint8_t gSIOWrIndex = 0U;
uint8_t fSIO_INT = 0U;
uint8_t fSIOTxOK = NO;

/**
  * @brief  SIO Configuration.
  * @param  SCx
  * @retval None
  */
void SIO_Configuration(TSB_SC_TypeDef * SCx)
{
    if (SCx == UART_RETARGET) {             
        TSB_PH->CR |= GPIO_BIT_0;
        TSB_PH->FR1 |= GPIO_BIT_0;
        TSB_PH->FR1 |= GPIO_BIT_1;
        TSB_PH->IE |= GPIO_BIT_1;
    } else {
        /*  Do Nothing */
    }
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
    UART_Enable(UART_RETARGET);
    myUART.BaudRate = 115200U;  /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Init(UART_RETARGET, &myUART);
}

/**
  * @brief  Send character by SIO1
  * @param  Character to be sent
  * @retval Character to be sent
  */
uint8_t send_char(uint8_t ch)
{
    while (gSIORdIndex != gSIOWrIndex) {        /* wait for finishing sending */
        /* do nothing */
    }
    gSIOTxBuffer[gSIOWrIndex++] = ch;   /* fill TxBuffer */
    if (fSIO_INT == CLEAR) {    /* if SIO INT disable, enable it */
        fSIO_INT = SET;         /* set SIO INT flag */
        UART_SetTxData(UART_RETARGET, gSIOTxBuffer[gSIORdIndex++]);
        NVIC_EnableIRQ(RETARGET_INT);
    }

    return ch;
}

/*********************************** END OF FILE ******************************/
