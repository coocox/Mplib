/**
 *******************************************************************************
 * @file    SSP_LoopBack.c
 * @brief   The application functions of SSP demo for the
 *          TOSHIBA 'TMPM363' Device Series
 * @version V1.000
 * @date    2010/08/19
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

/* include file */
#include <stdio.h>
#include "tmpm361_ssp.h"
#include "tmpm361_uart.h"

#define MAX_BUFSIZE  64U

#define UART UART0

char *message;
		
void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);

/* to check the effect due to too low speed, uncomment the line below */
#define BITRATE_MIN


/*--------------------------------------------------------------------
 This demo will enable the "loop back mode" of SSP module to send data
 and receive it. user can define BITRATE_MIN to see the effect due to
 too slow transmit bit rate.
 This demo is compiled by EWARM v5.5 and run on KEIL MCBTMPM360 V1.0
 board. the four LEDs(PM7 to PM4, while PM7 is MSB) will blink to show
 the data is being received.
-------------------------------------------------------------------*/
/* SSP_LoopBack function */
void SSP_LoopBack(void)
{
    SSP_InitTypeDef initSSP;
    SSP_FIFOState fifoState;
	
    uint16_t datTx = 0U;        /* must use 16bit type */
    uint32_t cntTx = 0U;
    uint32_t cntRx = 0U;

    uint16_t receive = 0U;
    uint16_t Rx_Buf[MAX_BUFSIZE] = { 0U };
    uint16_t Tx_Buf[MAX_BUFSIZE] = { 0U };

    SystemInit();

    /* enable the LED on board to display some info */
    UART_Configuration(UART);
    UART_Print(UART, "This is an example for SSP module!\n\r");

    /* configure the SSP module */
    initSSP.FrameFormat = SSP_FORMAT_SPI;

    /* default is to run at maximum bit rate */
    initSSP.PreScale = 2U;
    initSSP.ClkRate = 1U;
    /* define BITRATE_MIN to run at minimum bit rate */
    /*   BitRate = fSYS / (PreScale x (1 + ClkRate)) */
#ifdef BITRATE_MIN
    initSSP.PreScale = 254U;
    initSSP.ClkRate = 255U;
#endif
    initSSP.ClkPolarity = SSP_POLARITY_LOW;
    initSSP.ClkPhase = SSP_PHASE_FIRST_EDGE;
    initSSP.DataSize = 16U;
    initSSP.Mode = SSP_MASTER;
    SSP_Init(&initSSP);


    /* enable loop back mode for self test */
    SSP_SetLoopBackMode(ENABLE);

    /* enable and run SSP module */
    SSP_Enable();

    while (1) {
        
        datTx++;
        
        /* send data if Tx FIFO is available */
        fifoState = SSP_GetFIFOState(SSP_TX);
        if ((fifoState == SSP_FIFO_EMPTY) || (fifoState == SSP_FIFO_NORMAL)) {
            SSP_SetTxData(datTx);
            if (cntTx < MAX_BUFSIZE) {
                Tx_Buf[cntTx] = datTx;
                cntTx++;
            } else {
                /* do nothing */
            }
        } else {
            /* do nothing */
        }


        /* check if there is data arrived */
        fifoState = SSP_GetFIFOState(SSP_RX);
        if ((fifoState == SSP_FIFO_FULL) || (fifoState == SSP_FIFO_NORMAL)) {
            receive = SSP_GetRxData();
            if (cntRx < MAX_BUFSIZE) {
                Rx_Buf[cntRx] = receive;
                cntRx++;
            } else {
                /* Place a break point here to check if receive data is right.                */
                /* Success Criteria:                                                          */
                /*               Every data transmited from Tx_Buf is received in Rx_Buf.     */
                /* When the line "#define BITRATE_MIN" is commented, the SSP is run in maxium */
                /*  bit rate, so we can find there is enough time to transmit date from 1 to  */
                /*  MAX_BUFSIZE one by one. but if we uncomment that line, SSP is run in      */
                /*  minimum bit rate, we will find that receive data can't catch "datTx++",   */
                /*  in this so slow bit rate, when the Tx FIFO is available, the cntTx has    */
                /*  been increased so much.                                                   */
                __NOP();
            }

        } else {
            /* do nothing */
        }
        sprintf(message, "Received data is %d\n\r" + (uint8_t)(receive / 8000));
        UART_Print(UART, message);
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
