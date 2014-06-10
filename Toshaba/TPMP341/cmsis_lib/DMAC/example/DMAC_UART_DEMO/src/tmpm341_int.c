/**
 *******************************************************************************
 * @file    tmpm341_dmac_int.c
 * @brief   All interrupt request functions definition of DMA
 *           for the TOSHIBA 'TMPM341' Device Series 
 * @version V0.100
 * @date    2010/12/13
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
#include "tmpm341_int.h"

volatile WorkState TxEndFlag = BUSY;

/**
  * @brief  DMA transfer end interrupt request function.
  * @param  None
  * @retval None
  */
void INTDMAC0TC_IRQHandler(void)
{
    DMAC_TxINTReq tmp = DMAC_TX_NO_REQ;
    DMAC_INTReq state;
    TxEndFlag = BUSY;

    state = DMAC_GetINTReq(DMAC_UNIT_A);

    if (state.Bit.CH1_INTReq == 1U) {
        tmp = DMAC_GetTxINTReq(DMAC_UNIT_A, DMAC_CHANNEL_1);
        if (tmp == DMAC_TX_END_REQ) {
            TxEndFlag = DMAC_GetChannelTxState(DMAC_UNIT_A, DMAC_CHANNEL_1);
            DMAC_ClearTxINTReq(DMAC_UNIT_A, DMAC_CHANNEL_1, DMAC_INT_TX_END);
        } else {
            /* Do nothing */
        }
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  Interrupt Service Routine for SIO1 Reception
  * @param  None
  * @retval None
  */
void INTRX2_IRQHandler(void)
{
    volatile UART_Err err;

    err = UART_GetErrState(UART2);
    if (UART_NO_ERR == err) {
        UART_Rx_Buffer[UART_Rx_Cnt] = (uint8_t) UART_GetRxData(UART2);
        UART_Rx_Cnt++;
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  
  * @param  None
  * @retval None
  */
void INTDMAC0ERR_IRQHandler(void)
{
    /* Do nothing */
}
