/**
 *******************************************************************************
 * @file    DMAC_UART_DEMO.c
 * @brief   the application functions of DMAC UART demo for the
 *          TOSHIBA 'TMPM366' Device Series
 * @version V0.100
 * @date    2011/01/20
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

#include <stdio.h>
#include <string.h>
#include "tmpm366_dmac.h"
#include "tmpm366_uart.h"
#include "tmpm366_gpio.h"

#define BUFFER_SIZE  32U
#define UART0_BASE_ADDR   TSB_SC0_BASE
#define UART0_BUF_OFFSET  sizeof(UART0->EN)
typedef enum { FAILED = 0, PASSED = !FAILED } TestResult;

/* Function declaration */

/* User ram definition */
const uint8_t SRC_Buffer[] = "TOSHIBA";

uint8_t UART_Rx_Buffer[BUFFER_SIZE];
uint8_t UART_Rx_Cnt;
volatile TestResult TransferResult = FAILED;
volatile WorkState TxEndFlag = BUSY;

void INTRX1_IRQHandler(void);
void INTDMAC0TC_IRQHandler(void);
void INTDMAC0ERR_IRQHandler(void);
void GPIO_SetUART(void);

void DMAC_UART_DEMO(void)
{
    UART_InitTypeDef UART_InitStruct;
    DMAC_InitTypeDef DMAC_InitStruct;
    DMAC_Channel myChannel = DMAC_CHANNEL_1;
    uint32_t LinkAddr;
    uint8_t size;

    /* Set GPIO as UART */
    GPIO_SetUART();

    /* Set UART1 as reception */
    UART_Rx_Cnt = 0U;
    UART_InitStruct.BaudRate = 115200U;
    UART_InitStruct.DataBits = UART_DATA_BITS_8;
    UART_InitStruct.StopBits = UART_STOP_BITS_1;
    UART_InitStruct.Parity = UART_NO_PARITY;
    UART_InitStruct.Mode = UART_ENABLE_RX;
    UART_InitStruct.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Enable(UART1);
    UART_Init(UART1, &UART_InitStruct);

    /* Set UART0 as transmitter */
    UART_InitStruct.Mode = UART_ENABLE_TX;
    UART_Enable(UART0);
    UART_Init(UART0, &UART_InitStruct);
    UART_SetTxDMAReq(UART0, ENABLE);

    /* DMA channel1 configuration */
    size = sizeof(SRC_Buffer);
    DMAC_InitStruct.SrcAddr = (uint32_t) SRC_Buffer;
    DMAC_InitStruct.SrcIncrementState = ENABLE;
    DMAC_InitStruct.SrcBitWidth = DMAC_BYTE;
    DMAC_InitStruct.SrcBurstSize = DMAC_1_BEAT;
    DMAC_InitStruct.DstAddr = (uint32_t) (UART0_BASE_ADDR + UART0_BUF_OFFSET);
    DMAC_InitStruct.DstIncrementState = DISABLE;
    DMAC_InitStruct.DstBitWidth = DMAC_BYTE;
    DMAC_InitStruct.DstBurstSize = DMAC_1_BEAT;
    DMAC_InitStruct.TxSize = size;
    DMAC_InitStruct.TxDirection = DMAC_MEMORY_TO_PERIPH;
    DMAC_InitStruct.A_TxDstPeriph = DMACA_SIO0_UART0_TX;

    /* CXCONTROL<I> must be set when use transfer interrupt */
    DMAC_InitStruct.TxINT = ENABLE;

    LinkAddr = 0U;

    __disable_irq();
    /* enable DMA interrupt */
    NVIC_ClearPendingIRQ(INTDMAC0TC_IRQn);
    NVIC_EnableIRQ(INTDMAC0TC_IRQn);
    NVIC_ClearPendingIRQ(INTDMAC0ERR_IRQn);
    NVIC_EnableIRQ(INTDMAC0ERR_IRQn);

    /*Enable DMA circuit */
    DMAC_Enable(DMAC_UNIT_A);
    /* Clear any pending interrupts on the channel */
    DMAC_ClearTxINTReq(DMAC_UNIT_A, myChannel, DMAC_INT_TX_END);
    DMAC_ClearTxINTReq(DMAC_UNIT_A, myChannel, DMAC_INT_TX_ERR);
    /*Initialize DMA channel */
    DMAC_Init(DMAC_UNIT_A, myChannel, &DMAC_InitStruct);
    /* If don't require scatter/gather function, set the DMACCxLLI Register to 0 */
    DMAC_SetLinkedList(DMAC_UNIT_A, myChannel, LinkAddr);
    __enable_irq();

    /* enable UART1 reception interrupt */
    NVIC_ClearPendingIRQ(INTRX1_IRQn);
    NVIC_EnableIRQ(INTRX1_IRQn);

    /*Enable DMA Channel transfer end interrupt */
    DMAC_SetTxINTConfig(DMAC_UNIT_A, myChannel, DMAC_INT_TX_END, ENABLE);
    /* Enable DMA burst transfer request */
    DMACA_SetSWBurstReq(DMACA_SIO0_UART0_TX);

    /*Enable DMA channel */
    DMAC_SetDMAChannel(DMAC_UNIT_A, myChannel, ENABLE);

    /* Wait the end of transmission */
    while (TxEndFlag != DONE) {
        /* Do nothing */
    }
    while (UART_Rx_Cnt < size) {
        /* Do nothing */
    }

    while (1) {
        /* Do nothing */
    }
}

/**
  * @brief  Configure I/O ports for UART
  * @param  None
  * @retval None
  */
void GPIO_SetUART(void)
{
    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_0, ENABLE);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_1);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_0, ENABLE);

    GPIO_SetOutputEnableReg(GPIO_PC, GPIO_BIT_0, ENABLE);
    GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_0);;
    GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_1);;
    GPIO_SetInputEnableReg(GPIO_PC, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(GPIO_PC, GPIO_BIT_0, ENABLE);
    GPIO_SetPullUp(GPIO_PC, GPIO_BIT_1, ENABLE);
}

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
void INTRX1_IRQHandler(void)
{
    volatile UART_Err err;
    err = UART_GetErrState(UART1);
    if (UART_NO_ERR == err) {
        UART_Rx_Buffer[UART_Rx_Cnt] = (uint8_t) UART_GetRxData(UART1);
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
