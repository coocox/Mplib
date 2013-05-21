/**
 *******************************************************************************
 * @file    RMC_DEMO.c
 * @brief   the application functions of RMC (Remote Controller) demo for the
 *          TOSHIBA 'TMPM363' Device Series
 * @version V0.101
 * @date    2011/04/26
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
#include "TMPM363.h"
#include "tmpm363_rmc.h"
#include "tmpm363_uart.h"

#define TOSHIBA_FORMAT_RMC
/* #define RC5_FORMAT_RMC */

#ifdef TOSHIBA_FORMAT_RMC
#define RMC_MAX_CYCLE                   ((uint8_t)0x71)
#define RMC_MIN_CYCLE                   ((uint8_t)0x5A)
#define RMC_MAX_LOW_WIDTH               ((uint8_t)0x4C)
#define RMC_MIN_LOW_WIDTH               ((uint8_t)0x49)
#define RMC_TRG_LOW_WIDTH               ((uint8_t)0xFF)
#define RMC_TRG_MAX_DATA_BIT_CYCLE      ((uint8_t)0xFE)
#define RMC_LARGER_THRESHOLD            ((uint8_t)0x00)
#define RMC_SMALLER_THRESHOLD           ((uint8_t)0x2E)
#define RMC_NOISE_CANCELLATION_TIME     ((uint8_t)0x0D)
#endif

#ifdef RC5_FORMAT_RMC
#define RMC_MAX_CYCLE                   ((uint8_t)0x00)
#define RMC_MIN_CYCLE                   ((uint8_t)0x00)
#define RMC_MAX_LOW_WIDTH               ((uint8_t)0x00)
#define RMC_MIN_LOW_WIDTH               ((uint8_t)0x00)
#define RMC_TRG_LOW_WIDTH               ((uint8_t)0x47)
#define RMC_TRG_MAX_DATA_BIT_CYCLE      ((uint8_t)0x83)
#define RMC_LARGER_THRESHOLD            ((uint8_t)0x63)
#define RMC_SMALLER_THRESHOLD           ((uint8_t)0x44)
#define RMC_NOISE_CANCELLATION_TIME     ((uint8_t)0x0F)
#endif

typedef enum { None = 0, Received = 1 } RMCRX;
RMCRX fRMCRx = None;
uint32_t RMC_Command;
char *message;

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
void RMC_Configuration(TSB_RMC_TypeDef * RMCx);
void INTRMCRX0_IRQHandler(void);

void RMC_DEMO(void)
{
    TSB_RMC_TypeDef *RMCx;
    RMC_InitTypeDef myRMC;
	
    RMCx = TSB_RMC0;
    RMC_Command = 0U;
    SystemInit();
    RMC_Configuration(RMCx);    /*RMC IO initial */

    __disable_irq();
    TSB_CG->IMCGE = 0x00300000U;
    TSB_CG->ICRCG = 0x00000012U;
    TSB_CG->IMCGE = 0x00310000U;

#ifdef TOSHIBA_FORMAT_RMC
    /*RMC register set for TOSHIBA format */
    myRMC.LeaderPara.MaxCycle = RMC_MAX_CYCLE;
    myRMC.LeaderPara.MinCycle = RMC_MIN_CYCLE;
    myRMC.LeaderPara.MaxLowWidth = RMC_MAX_LOW_WIDTH;
    myRMC.LeaderPara.MinLowWidth = RMC_MIN_LOW_WIDTH;
    myRMC.LeaderPara.LeaderDetectionState = ENABLE;
    myRMC.LeaderPara.LeaderINTState = DISABLE;
    myRMC.FallingEdgeINTState = DISABLE;
    myRMC.SignalRxMethod = RMC_RX_IN_CYCLE_METHOD;
    myRMC.LowWidth = RMC_TRG_LOW_WIDTH;
    myRMC.MaxDataBitCycle = RMC_TRG_MAX_DATA_BIT_CYCLE;
    myRMC.LargerThreshold = RMC_LARGER_THRESHOLD;
    myRMC.SmallerThreshold = RMC_SMALLER_THRESHOLD;
    myRMC.InputSignalReversedState = DISABLE;
    myRMC.NoiseCancellationTime = RMC_NOISE_CANCELLATION_TIME;
#endif

#ifdef RC5_FORMAT_RMC
    /*RMC register set for RC5 format */
    myRMC.LeaderPara.MaxCycle = RMC_MAX_CYCLE;
    myRMC.LeaderPara.MinCycle = RMC_MIN_CYCLE;
    myRMC.LeaderPara.MaxLowWidth = RMC_MAX_LOW_WIDTH;
    myRMC.LeaderPara.MinLowWidth = RMC_MIN_LOW_WIDTH;
    myRMC.LeaderPara.LeaderDetectionState = DISABLE;
    myRMC.LeaderPara.LeaderINTState = DISABLE;
    myRMC.FallingEdgeINTState = DISABLE;
    myRMC.SignalRxMethod = RMC_RX_IN_PHASE_METHOD;
    myRMC.LowWidth = RMC_TRG_LOW_WIDTH;
    myRMC.MaxDataBitCycle = RMC_TRG_MAX_DATA_BIT_CYCLE;
    myRMC.LargerThreshold = RMC_LARGER_THRESHOLD;
    myRMC.SmallerThreshold = RMC_SMALLER_THRESHOLD;
    myRMC.InputSignalReversedState = ENABLE;
    myRMC.NoiseCancellationTime = RMC_NOISE_CANCELLATION_TIME;
#endif

    /* Enable and config the function for RMC channel */
    RMC_Enable(RMCx);
    RMC_Init(RMCx, &myRMC);
    /* RMC Reception enable */
    RMC_SetRxCtrl(RMCx, ENABLE);

    /* Enable the Receive interrupt for RMC channel */
    /* RMC0 should to enable INTRMCRX0_IRQn, RMC1 should to enable INTRMCRX1_IRQn. */
    NVIC_EnableIRQ(INTRMCRX0_IRQn);

    __enable_irq();

    do {
        if (fRMCRx) {
            sprintf(message, "RMC DATA: 0x%x\n", RMC_Command );
            UART_Print(UART, message);    /*printf RMC read data */
            fRMCRx = None;
        }
    } while (1);
}

void RMC_Configuration(TSB_RMC_TypeDef * RMCx)
{
    if (RMCx == TSB_RMC0) {
        TSB_PN_FR1_PN3F1 = 0;
        TSB_PN_FR2_PN3F2 = 0;
        TSB_PN_FR3_PN3F3 = 1;
        TSB_PN_IE_PN3IE = 1;
    } else {
        /*Do nothing */
    }
}

void INTRMCRX0_IRQHandler(void)
{
    RMC_INTFactor myRMC_INTFactor;
    RMC_RxDataTypeDef myRMC_RxDataDef;
#ifdef TOSHIBA_FORMAT_RMC
    RMC_LeaderDetection myRMC_LeaderDetection;
#endif

    myRMC_INTFactor = RMC_GetINTFactor(TSB_RMC0);
#ifdef TOSHIBA_FORMAT_RMC
    if (myRMC_INTFactor.Bit.MaxDataBitCycle) {  /*Max data bit cycle detection interrupt factor */
        myRMC_LeaderDetection = RMC_GetLeader(TSB_RMC0);
        if (myRMC_LeaderDetection == RMC_LEADER_DETECTED) {     /*Leader has been detected */
            myRMC_RxDataDef = RMC_GetRxData(TSB_RMC0);
            if (myRMC_RxDataDef.RxDataBits == 0x20U) {  /*32 bits data received */
                fRMCRx = Received;
                RMC_Command = myRMC_RxDataDef.RxBuf1;   /* save the RMC data for print in main() */
            }
        }
    }
#endif

#ifdef RC5_FORMAT_RMC
    if (myRMC_INTFactor.Bit.LowWidthDetection) {        /*Low width detection interrupt factor */
        myRMC_RxDataDef = RMC_GetRxData(TSB_RMC0);
        if (myRMC_RxDataDef.RxDataBits == 0x0EU) {      /*14 bits data received */
            fRMCRx = Received;
            RMC_Command = myRMC_RxDataDef.RxBuf1;       /* save the RMC data for print in main() */
        }
    }
#endif

    TSB_CG->ICRCG = 0x00000012U;      /* clear RMC0 INT */
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
