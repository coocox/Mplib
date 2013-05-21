/**
 *******************************************************************************
 * @file    MEMORY_TO_MEMORY.c
 * @brief   The application functions of DMAC demo for the
 *           TOSHIBA 'TMPM363' Device Series 
 * @version V0.100
 * @date    2010/07/23
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
/* Include header file */
#include "tmpm363_dmac.h"
#include "tmpm363_uart.h"

#define BUFFER_SIZE  32U
typedef enum { FAILED = 0, PASSED = !FAILED } TestResult;
volatile WorkState TxEndFlag = BUSY;

/* Function declaration */
TestResult Buffercompare(const uint32_t * pBuffer0, const uint32_t * pBuffer1,
                         uint16_t BufferLength);

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
/* User ram definition */
const uint32_t SRC_Buffer[BUFFER_SIZE] = {
    0x00000000U, 0x11111111U, 0x22222222U, 0x33333333U,
    0x44444444U, 0x55555555U, 0x66666666U, 0x77777777U,
    0x88888888U, 0x99999999U, 0xAAAAAAAAU, 0xBBBBBBBBU,
    0xCCCCCCCCU, 0xDDDDDDDDU, 0xEEEEEEEEU, 0xFFFFFFFFU,
    0xFFFFFFFFU, 0xEEEEEEEEU, 0xDDDDDDDDU, 0xCCCCCCCCU,
    0xBBBBBBBBU, 0xAAAAAAAAU, 0x99999999U, 0x88888888U,
    0x77777777U, 0x66666666U, 0x55555555U, 0x44444444U,
    0x33333333U, 0x22222222U, 0x11111111U, 0x00000000U
};

uint32_t DST_Buffer[BUFFER_SIZE] = { 0U };
volatile TestResult TransferResult = FAILED;

/* main function */
void MEMORY_TO_MEMORY(void)
{
    DMAC_InitTypeDef DMAC_InitStruct;
    DMAC_Channel myChannel = DMAC_CHANNEL_1;
    uint32_t LinkAddr;

    SystemInit();
	UART_Configuration(UART);
	UART_Print(UART, "This is an example for DMAC\n\r");	
    /* DMA channel1 configuration */
    DMAC_InitStruct.SrcAddr = (uint32_t) SRC_Buffer;
    DMAC_InitStruct.SrcIncrementState = ENABLE;
    DMAC_InitStruct.SrcBitWidth = DMAC_WORD;
    DMAC_InitStruct.SrcBurstSize = DMAC_4_BEATS;
    DMAC_InitStruct.DstAddr = (uint32_t) DST_Buffer;
    DMAC_InitStruct.DstIncrementState = ENABLE;
    DMAC_InitStruct.DstBitWidth = DMAC_WORD;
    DMAC_InitStruct.DstBurstSize = DMAC_4_BEATS;
    DMAC_InitStruct.TxSize = BUFFER_SIZE;
    DMAC_InitStruct.TxDirection = DMAC_MEMORY_TO_MEMORY;

    /* CXCONTROL<I> must be set when use transfer interrupt */
    DMAC_InitStruct.TxINT = ENABLE;

    LinkAddr = 0U;

    __disable_irq();
    /* enable DMA interrupt */
    NVIC_ClearPendingIRQ(INTDMACTC0_IRQn);
    NVIC_EnableIRQ(INTDMACTC0_IRQn);

    /*Enable DMA circuit */
    DMAC_Enable();
    /* Clear any pending interrupts on the channel */
    DMAC_ClearTxINTReq(myChannel, DMAC_INT_TX_END);
    DMAC_ClearTxINTReq(myChannel, DMAC_INT_TX_ERR);
    /*Initialize DMA channel */
    DMAC_Init(myChannel, &DMAC_InitStruct);
    /* If don't require scatter/gather function, set the DMACCxLLI Register to 0 */
    DMAC_SetLinkedList(myChannel, LinkAddr);
    /*Enable DMA Channel transfer end interrupt */
    DMAC_SetTxINTConfig(myChannel, DMAC_INT_TX_END, ENABLE);
    /*Enable DMA channel */
    DMAC_SetDMAChannel(myChannel, ENABLE);
    __enable_irq();

	UART_Print(UART, "Transmit starting...\n\r");	
    /* Wait the end of transmission */
    while (TxEndFlag != DONE) {
        /* Do nothing */
    }
    /* Check whether the transmitted and received data are equal */
    TransferResult = Buffercompare(SRC_Buffer, DST_Buffer, BUFFER_SIZE);
	if(TransferResult == FAILED)
	{
		UART_Print(UART, "Memory to Memory FAILED\n\r");
	}else
	{
		UART_Print(UART, "Memory to Memory PASSED\n\r");
	}
    while (1) {
        /* Do nothing */
    }
}

/* Compare two buffers */
TestResult Buffercompare(const uint32_t * pBuffer0, const uint32_t * pBuffer1,
                         uint16_t BufferLength)
{
    TestResult retval = PASSED;
    while (BufferLength--) {
        if (*pBuffer0 != *pBuffer1) {
            retval = FAILED;
            break;
        } else {
            /* Do nothing */
        }

        pBuffer0++;
        pBuffer1++;
    }

    return retval;
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
/**
  * @brief  DMA transfer end interrupt request function.
  * @param  None
  * @retval None
  */
void INTDMACTC0_IRQHandler(void)
{
    DMAC_TxINTReq tmp = DMAC_TX_NO_REQ;
    DMAC_INTReq state;
    TxEndFlag = BUSY;

    state = DMAC_GetINTReq();

    if (state.Bit.CH1_INTReq == 1U) {
        tmp = DMAC_GetTxINTReq(DMAC_CHANNEL_1);
        if (tmp == DMAC_TX_END_REQ) {
            TxEndFlag = DMAC_GetChannelTxState(DMAC_CHANNEL_1);
            DMAC_ClearTxINTReq(DMAC_CHANNEL_1, DMAC_INT_TX_END);
        } else {
            /* Do nothing */
        }
    } else {
        /* Do nothing */
    }
}
