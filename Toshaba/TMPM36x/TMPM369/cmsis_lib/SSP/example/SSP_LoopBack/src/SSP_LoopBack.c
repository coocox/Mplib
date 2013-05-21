/**
 *******************************************************************************
 * @file    SSP_LoopBack.c
 * @brief   The application functions of SSP demo for the
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
#include "tmpm369_ssp.h"
#include "tmpm369_gpio.h"
#include "tmpm369_uart.h"
#include <stdio.h>

#define MAX_BUFSIZE  64U

typedef enum { SAME = 1U, NOT_SAME = !SAME } TestResult;
TestResult result = NOT_SAME;

TestResult Buffercompare(const uint16_t * Src, const uint16_t * Dst, uint32_t Len);
void UART0_Print(char *string);
void SIO_Configuration(void);
void SIO_ChInit(void);

/* to check the effect due to too low speed, uncomment the line below */
/* #define BITRATE_MIN */


/*--------------------------------------------------------------------
 This demo will enable the "loop back mode" of SSP module to send data
 and receive it. user can define BITRATE_MIN to see the effect due to
 too slow transmit bit rate.
 the four LEDs will blink to show the data is being received.
---------------------------------------------------------------------*/
/* main function */
void SSP_LoopBack(void)
{
    SSP_InitTypeDef initSSP;
    SSP_FIFOState fifoState;

    uint16_t datTx = 0U;        /* must use 16bit type */
    uint32_t cntTx = 0U;
    uint32_t cntRx = 0U;

    uint16_t receive = 0U;
	  char SSP_Data[16];
	
    uint16_t Rx_Buf[MAX_BUFSIZE] = { 0U };
    uint16_t Tx_Buf[MAX_BUFSIZE] = { 0U };

    /* enable UART to display some info */
    SIO_Configuration();
    SIO_ChInit();
	  UART0_Print("This is an example for SSP module!\n\r");

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
    SSP_Init(TSB_SSP0, &initSSP);


    /* enable loop back mode for self test */
    SSP_SetLoopBackMode(TSB_SSP0, ENABLE);

    /* enable and run SSP module */
    SSP_Enable(TSB_SSP0);

    while (1) {
        
        datTx++;
        
        /* send data if Tx FIFO is available */
        fifoState = SSP_GetFIFOState(TSB_SSP0, SSP_TX);
        if ((fifoState == SSP_FIFO_EMPTY) || (fifoState == SSP_FIFO_NORMAL)) {
            SSP_SetTxData(TSB_SSP0, datTx);
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
        fifoState = SSP_GetFIFOState(TSB_SSP0, SSP_RX);
        if ((fifoState == SSP_FIFO_FULL) || (fifoState == SSP_FIFO_NORMAL)) {
            receive = SSP_GetRxData(TSB_SSP0);
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
							  result = Buffercompare(Tx_Buf, Rx_Buf, MAX_BUFSIZE);
                if (result  == NOT_SAME)
                {
                    UART0_Print("result is not same\n\r");                                      
                }else
                {
                    UART0_Print("result is same\n\r");
                }
            }

        } else {
            /* do nothing */
        }
				
        sprintf((char *)SSP_Data, "%d", receive);
				UART0_Print("SSP RX DATA:");
        UART0_Print(SSP_Data);
				UART0_Print("\n\r");
    }
}

/**
  * @brief  To compare two half word buffer
  * @param  Src : pointer to point source buffer
  * @param  Dst : pointer to point destination buffer
  * @param  Len : how many data will be compared
  * @retval SAME: two buffer contain same data
            NOT_SAME: two buffer contain different data
  */
TestResult Buffercompare(const uint16_t * Src, const uint16_t * Dst, uint32_t Len)
{
    uint32_t tmp = 0U;
    TestResult result = NOT_SAME;

    for (tmp = 0U; tmp < Len; tmp++) {
        if (Src[tmp] != Dst[tmp]) {
            break;
        } else {
            result = SAME;
        }
    }

    return result;
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
