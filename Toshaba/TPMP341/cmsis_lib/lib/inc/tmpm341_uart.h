/** 
 *******************************************************************************
 * @file    tmpm341_uart.h
 * @brief   This file provides all the functions prototypes for UART driver.
 * @version V2.0.2.2
 * @date    2011/1/17
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM341_UART_H
#define __TMPM341_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_UART_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Exported_Types
  * @{
  */

/** 
  * @brief  UART Init Structure definition
  */

    typedef struct {
        uint32_t BaudRate;      /*!< This member configures the UART communication
                                   baud rate. */
        uint32_t DataBits;      /*!< Specifies UART transfer mode, which could be 
                                   7-bit mode, 8-bit mode or 9-bit mode. */
        uint32_t StopBits;      /*!< Specifies the length of stop bit transmission
                                   in UART mode. */
        uint32_t Parity;        /*!< Specifies the parity mode which could be odd 
                                   parity, even parity or no parity. */
        uint32_t Mode;          /*!< Enables or disables Receive, Transmit or 
                                   both. */
        uint32_t FlowCtrl;      /*!< Specifies wether the hardware flow control 
                                   mode is enabled or disabled. */
    } UART_InitTypeDef;
/** @} */
/* End of group UART_Exported_Types */

/** @defgroup UART_Exported_Constants
  * @{
  */

#define UART0  TSB_SC0
#define UART1  TSB_SC1
#define UART2  TSB_SC2
#define UART3  TSB_SC3
#define UART4  TSB_SC4

#define IS_UART_DMA_PERIPH(param)   (((param) == UART0)  || \
                                     ((param) == UART2)  || \
                                     ((param) == UART4))

#define IS_UART_PERIPH(param)       (((param) == UART0)  || \
                                     ((param) == UART1)  || \
                                     ((param) == UART2)  || \
                                     ((param) == UART3)  || \
                                     ((param) == UART4))

#define UART_DATA_BITS_7            ((uint32_t)0x00000004)
#define UART_DATA_BITS_8            ((uint32_t)0x00000008)
#define UART_DATA_BITS_9            ((uint32_t)0x0000000C)
#define IS_UART_DATA_BITS(param)    (((param) == UART_DATA_BITS_7) || \
                                     ((param) == UART_DATA_BITS_8) || \
                                     ((param) == UART_DATA_BITS_9))

#define UART_STOP_BITS_1            ((uint32_t)0x00000000)
#define UART_STOP_BITS_2            ((uint32_t)0x00000010)
#define IS_UART_STOPBITS(param)     (((param) == UART_STOP_BITS_1) || \
                                     ((param) == UART_STOP_BITS_2))

#define UART_NO_PARITY              ((uint32_t)0x00000000)
#define UART_EVEN_PARITY            ((uint32_t)0x00000060)
#define UART_ODD_PARITY             ((uint32_t)0x00000020)
#define IS_UART_PARITY(param)       (((param) == UART_NO_PARITY) || \
                                     ((param) == UART_EVEN_PARITY) || \
                                     ((param) == UART_ODD_PARITY))

#define UART_ENABLE_RX              ((uint32_t)0x00000020)
#define UART_ENABLE_TX              ((uint32_t)0x00000010)
#define IS_UART_MODE(param)         (((param) == UART_ENABLE_RX) || \
                                     ((param) == UART_ENABLE_TX) || \
                                     ((param) == (UART_ENABLE_TX | UART_ENABLE_RX)))

#define UART_NONE_FLOW_CTRL         ((uint32_t)0x00000000)
#define IS_UART_FLOW_CONTROL(param) ((param) == UART_NONE_FLOW_CTRL)

#define IS_UART_BAUDRATE(param)     (((param) >= 2400U) && \
                                     ((param) <= 115200U))

#define IS_UART_DATA(param)         ((param) <= 0x01FFU)

#define UART_RX                     ((uint32_t)0x00000020)
#define UART_TX                     ((uint32_t)0x00000040)
#define IS_UART_TRX(param)          (((param) == UART_RX) || \
                                     ((param) == UART_TX))
/** @} */
/* End of group UART_Exported_Constants */

/** @addtogroup UART_Exported_Types
  * @{
  */
    typedef enum {
        UART_NO_ERR = 0U,
        UART_OVERRUN = 1U,
        UART_PARITY_ERR = 2U,
        UART_FRAMING_ERR = 3U,
        UART_ERRS = 4U
    } UART_Err;
/** @} */
/* End of group UART_Exported_Types */

/** @defgroup UART_Exported_FunctionPrototypes
  * @{
  */

    void UART_Enable(TSB_SC_TypeDef * UARTx);
    void UART_Disable(TSB_SC_TypeDef * UARTx);
    WorkState UART_GetBufState(TSB_SC_TypeDef * UARTx, uint8_t Direction);
    void UART_SWReset(TSB_SC_TypeDef * UARTx);
    void UART_Init(TSB_SC_TypeDef * UARTx, UART_InitTypeDef * InitStruct);
    uint32_t UART_GetRxData(TSB_SC_TypeDef * UARTx);
    void UART_SetTxData(TSB_SC_TypeDef * UARTx, uint32_t Data);
    void UART_DefaultConfig(TSB_SC_TypeDef * UARTx);
    UART_Err UART_GetErrState(TSB_SC_TypeDef * UARTx);
    void UART_SetWakeUpFunc(TSB_SC_TypeDef * UARTx, FunctionalState NewState);
    void UART_SetIdleMode(TSB_SC_TypeDef * UARTx, FunctionalState NewState);
    void UART_SetRxDMAReq(TSB_SC_TypeDef * UARTx, FunctionalState NewState);
    void UART_SetTxDMAReq(TSB_SC_TypeDef * UARTx, FunctionalState NewState);

/** @} */
/* End of group UART_Exported_FunctionPrototypes */

/** @} */
/* End of group UART */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM341_UART_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM341_UART_H */
