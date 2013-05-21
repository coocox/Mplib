/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of UART11 to HyperTerminal demo for the 
 *          TOSHIBA 'TMPM364' Device Series
 * @version V0.100
 * @date    2010/06/21
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
#include "tmpm364_uart.h"

#define UART UART11
#define BufSize (sizeof(TxBuffer) / sizeof(*(TxBuffer)))

uint8_t TxBuffer[] = "TMPM364\n\r";
const uint8_t NumToBeTx = BufSize - 1U;
uint8_t TxCounter = 0U;
UART_InitTypeDef myUART;

void SIO_Configuration(TSB_SC_TypeDef * SCx);

void uart_print(void)
{
    SIO_Configuration(UART);

    myUART.BaudRate = 115200U;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_RX | UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(UART);
    UART_Init(UART, &myUART);

    NVIC_EnableIRQ(INTTX11_IRQn);
    
    UART_SetTxData(UART, (uint32_t) (TxBuffer[TxCounter++]));
    while (1) {
        /* Do nothing */
    }
}

void SIO_Configuration(TSB_SC_TypeDef * SCx)
{
    if (SCx == UART11) {
        TSB_PD_CR_PD4C = 1U;
        TSB_PD_FR2_PD4F2 = 1U;
        TSB_PD_FR2_PD5F2 = 1U;
        TSB_PD_IE_PD5IE = 1U;
    } else {
        /* Do nothing */
    }
}
/**
  * @brief  The transmission interrupt request function of UART channel 11.
  * @param  None
  * @retval None
  */
void INTTX11_IRQHandler(void)
{
    volatile UART_Err err;

    if (TxCounter < NumToBeTx) {
        UART_SetTxData(UART11, TxBuffer[TxCounter++]);
    } else {
        err = UART_GetErrState(UART11);
    }
}
