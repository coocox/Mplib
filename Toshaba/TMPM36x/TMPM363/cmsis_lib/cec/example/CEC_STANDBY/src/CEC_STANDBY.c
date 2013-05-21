/**
 *******************************************************************************
 * @file    CEC_STANDBY.c
 * @brief   the application functions of CEC demo for the TOSHIBA
 *          'TMPM363' Device Series 
 * @version V0.100
 * @date    2010/07/20
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
#include "tmpm363_cec.h"
#include "tmpm363_uart.h"

typedef enum {
    DATA_INIT = 0,
    DATA_IN_PROGRESS = 1,
    DATA_END = 2
} CEC_DataState;

typedef struct {
    CEC_LogicalAddr Initiator;
    CEC_LogicalAddr Destination;
    uint8_t Opcode;
    uint8_t CEC_Data[17];
    uint8_t current_num;
    uint8_t Max_num;
    CEC_DataState current_state;
} CEC_FrameTypeDef;

CEC_FrameTypeDef CEC_RxFrame;
CEC_FrameTypeDef CEC_RxFrameTmp;
CEC_FrameTypeDef CEC_TxFrame;

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
void CEC_Send_Frame(CEC_LogicalAddr Initiator, CEC_LogicalAddr Destination,
                    uint8_t Opcode, uint8_t OperandNum, uint8_t Operand[17]);

void CEC_STANDBY(void)
{
    uint32_t Index = 0U;
    uint32_t temp = 0U;
    SystemInit();
    /*initial cec port */
    TSB_PI->CR = 0x01U;
    TSB_PI->FR1 = 0x01U;
    TSB_PI->IE = 0x01U;
    /*initial cec frame data buffer */
    CEC_RxFrame.Initiator = CEC_UNKNOWN;
    CEC_RxFrame.Destination = CEC_UNKNOWN;
    CEC_RxFrame.Opcode = 0xFFU;
    CEC_RxFrame.current_num = 0x0U;
    CEC_RxFrame.Max_num = 0x0U;
    CEC_RxFrame.current_state = DATA_INIT;
    for (Index = 0U; Index < 17U; Index++) {
        CEC_RxFrame.CEC_Data[Index] = 0xFFU;
    }
    CEC_RxFrameTmp = CEC_RxFrame;
    CEC_TxFrame = CEC_RxFrame;
    /*initial cec register */
    CEC_Enable();
    CEC_SWReset();
    while (CEC_GetRxState() == ENABLE);
    while (CEC_GetTxState() == BUSY);
    CEC_DefaultConfig();

    /*initial cec interupt */
    __disable_irq();
    TSB_CG->IMCGE = 0x00003030U;
    TSB_CG->IMCGE = 0x00003131U;
    TSB_CG->ICRCG = 0x10U;
    NVIC_EnableIRQ(INTCECRX_IRQn);
    NVIC_EnableIRQ(INTCECTX_IRQn);
    __enable_irq();

    /*set logical address TV */
    CEC_SetLogicalAddr(CEC_TV);
    /*Enable CEC reception */
    CEC_SetRxCtrl(ENABLE);

    while (1) {
        /*Recieve new frame or not */
        if (CEC_RxFrameTmp.current_state == DATA_END) {
            CEC_RxFrame = CEC_RxFrameTmp;
            CEC_RxFrameTmp.current_num = 0U;
            CEC_RxFrameTmp.current_state = DATA_INIT;
            temp = CEC_RxFrame.current_num;

            if (temp > 0U) {
                UART_Print(UART, "CEC Message: ");
                for (Index = 0U; Index < temp; Index++) {
                    UART_Print(UART, "0x%2x " + CEC_RxFrame.CEC_Data[Index]);
                }
                UART_Print(UART, "\n");
            }

            for (Index = 0U; Index < 17U; Index++) {
                CEC_RxFrameTmp.CEC_Data[Index] = 0xFFU;
            }
            /*CEC message is "Active Source" */
            if (CEC_RxFrame.CEC_Data[1] == 0x82U) {
                CEC_Send_Frame(CEC_TV, CEC_BROADCAST, 0x36U, 0U, CEC_RxFrame.CEC_Data);
            }
        }
    }
}

/**
  * @brief  Send A frame to other device.
  * @param  Initiator: Initiaor address ,Destination: Destination address, Opcode: operate code, OperandNum: Operand number,CEC_Data: CEC frame data
  * @retval None
  */
void CEC_Send_Frame(CEC_LogicalAddr Initiator, CEC_LogicalAddr Destination,
                    uint8_t Opcode, uint8_t OperandNum, uint8_t CEC_Data[17])
{
    uint32_t Index = 0U;
    if (CEC_TxFrame.current_state != DATA_IN_PROGRESS) {
        CEC_TxFrame.Initiator = Initiator;
        CEC_TxFrame.Destination = Destination;
        CEC_TxFrame.current_num = 0U;
        CEC_TxFrame.Opcode = Opcode;
        CEC_TxFrame.Max_num = 2U + OperandNum;
        CEC_TxFrame.current_state = DATA_IN_PROGRESS;
        CEC_TxFrame.CEC_Data[0] = (uint8_t) Initiator << 4U;
        CEC_TxFrame.CEC_Data[0] |= ((uint8_t) Destination);
        CEC_TxFrame.CEC_Data[1] = Opcode;

        for (Index = 2U; Index < 17U; Index++) {
            if (Index < CEC_TxFrame.Max_num) {
                CEC_TxFrame.CEC_Data[Index] = CEC_Data[Index];
            } else {
                CEC_TxFrame.CEC_Data[Index] = 0xFFU;
            }
        }
        if (CEC_BROADCAST == Destination) {
            CEC_SetTxBroadcast(ENABLE);
        } else {
            CEC_SetTxBroadcast(DISABLE);
        }
        /*Send first byte of frame */
        CEC_SetTxData(CEC_TxFrame.CEC_Data[0], CEC_NO_EOM);
        CEC_StartTx();
    }
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
  * @brief  The CEC reception interrupt  function.
  * @param  None
  * @retval None
  */
void INTCECRX_IRQHandler(void)
{
    CEC_DataTypeDef data;
    CEC_RxINTState stateRx;
    TSB_CG->ICRCG = 0x10U;      /* CEC clear interrupt */
    data = CEC_GetRxData();
    stateRx = CEC_GetRxINTState();
    if (stateRx.Bit.RxEnd == 1) {
        if (CEC_RxFrameTmp.current_num < 17U) {
            CEC_RxFrameTmp.CEC_Data[CEC_RxFrameTmp.current_num] = data.Data;
            CEC_RxFrameTmp.current_num++;
            CEC_RxFrameTmp.current_state = DATA_IN_PROGRESS;
        }
        if (data.EOMBit == CEC_EOM) {
            CEC_RxFrameTmp.current_state = DATA_END;
        }
    } else if (stateRx.Bit.RxStartBit == 1) {
        /*Do nothing */
    } else {
        CEC_RxFrameTmp.current_state = DATA_END;
    }

}

/**
  * @brief  The CEC transmission interrupt  function.
  * @param  None
  * @retval None
  */
void INTCECTX_IRQHandler(void)
{
    CEC_TxINTState stateTx; 
    //TSB_CG->ICRCG = 0x0cU;      /* CEC clear interrupt */
    stateTx = CEC_GetTxINTState();
    if (stateTx.Bit.TxStart == 1) {
        CEC_TxFrame.current_num++;
        if ((CEC_TxFrame.current_num + 1U) >= CEC_TxFrame.Max_num) {
            /* send the next byte of frame */
            CEC_SetTxData(CEC_TxFrame.CEC_Data[CEC_TxFrame.current_num], CEC_EOM);
        } else {
            /* send the last byte of frame */
            CEC_SetTxData(CEC_TxFrame.CEC_Data[CEC_TxFrame.current_num], CEC_NO_EOM);
        }
    } else {
        CEC_TxFrame.current_state = DATA_END;
    }
}
