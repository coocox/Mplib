/** 
 *******************************************************************************
 * @file    retarget.h
 * @brief   the application functions of retarget for the TOSHIBA
 *          'TMPM061' Device Series 
 * @version V0.100
 * @date    2012/05/17
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RETARGET_H
#define __RETARGET_H
/* Includes ------------------------------------------------------------------*/

#include "tmpm061_uart.h"
#include <stdio.h>

#define  DEF_DISABLED                   0
#define  DEF_ENABLED                    1

#define     UART2_R     DEF_ENABLED     /*Set UARTx as retarget channel*/
   
#if (UART0_R == DEF_ENABLED)
    #define UART_RETARGET               UART0
    #define TSB_RETG    TSB_PH
    #define TXD_BIT     (1U<<0U)
    #define RXD_BIT     (1U<<1U)
    #define INT_RETARGET_IRQn       INTTX0_IRQn
    #define Retartget_IRQHandler    INTTX0_IRQHandler
#elif   (UART1_R == DEF_ENABLED) 
    #define UART_RETARGET               UART1
    #define TSB_RETG    TSB_PH
    #define TXD_BIT     (1U<<3U)
    #define RXD_BIT     (1U<<4U)
    #define INT_RETARGET_IRQn       INTTX1_IRQn
    #define Retartget_IRQHandler    INTTX1_IRQHandler
#elif   (UART2_R == DEF_ENABLED) 
    #define UART_RETARGET               UART2
    #define TSB_RETG    TSB_PI
    #define TXD_BIT     (1U<<0U)
    #define RXD_BIT     (1U<<1U)
    #define INT_RETARGET_IRQn       INTTX2_IRQn       
    #define Retartget_IRQHandler    INTTX2_IRQHandler
#endif


#define BUFFER_SIZE 16U
#define SET     0x01U           /* flag is set */
#define CLEAR   0x00U           /* flag is cleared */
#define NO      0x00U           /* Send finish NG */
#define YES     0x01U           /* Send finish OK */

void Retarget_Init(void);

#endif
