/**
 *******************************************************************************
 * @file    tmpm366_dmac.h
 * @brief   This file provides all the functions prototypes for DMAC driver.
 * @version V2.0.2.1
 * @date    2011/02/09
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
#ifndef __TMPM366_DMAC_H
#define __TMPM366_DMAC_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM366.h"
#include "tx03_common.h"

#if defined(__TMPM366_DMAC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup DMAC
  * @{
  */

/** @defgroup DMAC_Exported_Constants
  * @{
  */

#define IS_DMAC_TX_SIZE(param)   ((param) <= 0x0FFFU)
#define IS_DMAC_LINK_ADDR_MAX_VALUE(param)   ((param) <= 0xFFFFFFF0U)

#define DMAC_MEMORY_TO_MEMORY         ((uint32_t)0x00000000)
#define DMAC_MEMORY_TO_PERIPH         ((uint32_t)0x00000800)
#define DMAC_PERIPH_TO_MEMORY         ((uint32_t)0x00001000)
#define DMAC_PERIPH_TO_PERIPH         ((uint32_t)0x00001800)
#define IS_DMAC_TX_DIRECTION(param) (((param) == DMAC_MEMORY_TO_MEMORY) || \
                                     ((param) == DMAC_MEMORY_TO_PERIPH) || \
                                     ((param) == DMAC_PERIPH_TO_PERIPH) || \
                                     ((param) == DMAC_PERIPH_TO_MEMORY))

/** @} */
/* End of group DMAC_Exported_Constants */

/** @defgroup DMAC_Exported_Types
  * @{
  */
    typedef enum {
        DMAC_CHANNEL_0 = 0U,
        DMAC_CHANNEL_1 = 1U
    } DMAC_Channel;
#define IS_DMAC_CHANNEL(param) (((param) == DMAC_CHANNEL_0) || \
                                ((param) == DMAC_CHANNEL_1))

#define DMAC_UNIT_A  TSB_DMACA
#define DMAC_UNIT_B  TSB_DMACB

#define IS_DMAC_UNIT(param) (((param) == DMAC_UNIT_A) || \
                                ((param) == DMAC_UNIT_B))

    typedef enum {
        DMAC_BYTE = 0U,
        DMAC_HALF_WORD = 1U,
        DMAC_WORD = 2U
    } DMAC_BitWidth;
#define IS_DMAC_BIT_WIDTH(param) (((param) == DMAC_BYTE) || \
                                  ((param) == DMAC_HALF_WORD) || \
                                  ((param) == DMAC_WORD))

    typedef enum {
        DMAC_TX_NO_REQ = 0U,
        DMAC_TX_END_REQ = 1U,
        DMAC_TX_ERR_REQ = 2U,
        DMAC_TX_REQS = 3U
    } DMAC_TxINTReq;

    typedef union {
        uint32_t All;
        struct {
            uint32_t CH0_INTReq:1;
            uint32_t CH1_INTReq:1;
        } Bit;
    } DMAC_INTReq;

    typedef enum {
        DMAC_INT_TX_END = 0U,
        DMAC_INT_TX_ERR = 1U
    } DMAC_INTSrc;
#define IS_DMAC_INT_SRC(param)  (((param) == DMAC_INT_TX_END) || \
                                 ((param) == DMAC_INT_TX_ERR))

    typedef enum {
        DMAC_1_BEAT = 0U,
        DMAC_4_BEATS = 1U,
        DMAC_8_BEATS = 2U,
        DMAC_16_BEATS = 3U,
        DMAC_32_BEATS = 4U,
        DMAC_64_BEATS = 5U,
        DMAC_128_BEATS = 6U,
        DMAC_256_BEATS = 7U
    } DMAC_BurstSize;
#define IS_DMAC_BURST_SIZE(param)  (((param) == DMAC_1_BEAT) || \
                                    ((param) == DMAC_4_BEATS) || \
                                    ((param) == DMAC_8_BEATS) || \
                                    ((param) == DMAC_16_BEATS) || \
                                    ((param) == DMAC_32_BEATS) || \
                                    ((param) == DMAC_64_BEATS) || \
                                    ((param) == DMAC_128_BEATS) || \
                                    ((param) == DMAC_256_BEATS))

    typedef enum {
        DMACA_SIO0_UART0_RX = 0U,
        DMACA_SIO0_UART0_TX = 1U,
        DMACA_SIO1_UART1_RX = 2U,
        DMACA_SIO1_UART1_TX = 3U,
        DMACA_TMRB8_CMP_MATCH = 4U,
        DMACA_TMRB9_CMP_MATCH = 5U,
        DMACA_TMRB0_CAPTURE0 = 6U,
        DMACA_TMRB4_CAPTURE0 = 7U,
        DMACA_TMRB4_CAPTURE1 = 8U,
        DMACA_TMRB5_CAPTURE0 = 9U,
        DMACA_TMRB5_CAPTURE1 = 10U,
        DMACA_TOP_PRIORITY_ADC = 11U,
        DMACA_FULL_UART_RX = 14U,
        DMACA_FULL_UART_TX = 15U
    } DMACA_ReqNum;

    typedef enum {
        DMACB_TMRB6_CMP_MATCH = 0U,
        DMACB_TMRB7_CMP_MATCH = 1U,
        DMACB_TMRB0_CAPTURE1 = 2U,
        DMACB_TMRB2_CAPTURE0 = 3U,
        DMACB_TMRB2_CAPTURE1 = 4U,
        DMACB_TMRB3_CAPTURE0 = 5U,
        DMACB_TMRB3_CAPTURE1 = 6U,
        DMACB_TMRB6_CAPTURE0 = 7U,
        DMACB_TMRB6_CAPTURE1 = 8U,
        DMACB_NORMAL_ADC = 9U,
        DMACB_SSP0_TX = 10U,
        DMACB_SSP0_RX = 11U,
        DMACB_SSP1_TX = 12U,
        DMACB_SSP1_RX = 13U,
        DMACB_SSP2_TX = 14U,
        DMACB_SSP2_RX = 15U
    } DMACB_ReqNum;

#define IS_DMACA_REQ_NUM(param)  (((param) == DMACA_SIO0_UART0_RX) || \
                                   ((param) == DMACA_SIO0_UART0_TX) || \
                                   ((param) == DMACA_SIO1_UART1_RX) || \
                                   ((param) == DMACA_SIO1_UART1_TX) || \
                                   ((param) == DMACA_TMRB8_CMP_MATCH) || \
                                   ((param) == DMACA_TMRB9_CMP_MATCH) || \
                                   ((param) == DMACA_TMRB0_CAPTURE0) || \
                                   ((param) == DMACA_TMRB4_CAPTURE0) || \
                                   ((param) == DMACA_TMRB4_CAPTURE1) || \
                                   ((param) == DMACA_TMRB5_CAPTURE0) || \
                                   ((param) == DMACA_TMRB5_CAPTURE1) || \
                                   ((param) == DMACA_TOP_PRIORITY_ADC) || \
                                   ((param) == DMACA_FULL_UART_RX) || \
                                   ((param) == DMACA_FULL_UART_TX))

#define IS_DMACB_REQ_NUM(param)  (((param) == DMACB_TMRB6_CMP_MATCH) || \
                                   ((param) == DMACB_TMRB7_CMP_MATCH) || \
                                   ((param) == DMACB_TMRB0_CAPTURE1) || \
                                   ((param) == DMACB_TMRB2_CAPTURE0) || \
                                   ((param) == DMACB_TMRB2_CAPTURE1) || \
                                   ((param) == DMACB_TMRB3_CAPTURE0) || \
                                   ((param) == DMACB_TMRB3_CAPTURE1) || \
                                   ((param) == DMACB_TMRB6_CAPTURE0) || \
                                   ((param) == DMACB_TMRB6_CAPTURE1) || \
                                   ((param) == DMACB_NORMAL_ADC) || \
                                   ((param) == DMACB_SSP0_TX) || \
                                   ((param) == DMACB_SSP0_RX) || \
                                   ((param) == DMACB_SSP1_TX) || \
                                   ((param) == DMACB_SSP1_RX) || \
                                   ((param) == DMACB_SSP2_TX) || \
                                   ((param) == DMACB_SSP2_RX))

#define IS_DMACA_BURST_REQ_NUM(param)  (((param) == DMACA_SIO0_UART0_RX) || \
                                         ((param) == DMACA_SIO0_UART0_TX) || \
                                         ((param) == DMACA_SIO1_UART1_RX) || \
                                         ((param) == DMACA_SIO1_UART1_TX) || \
                                         ((param) == DMACA_TMRB8_CMP_MATCH) || \
                                         ((param) == DMACA_TMRB9_CMP_MATCH) || \
                                         ((param) == DMACA_TMRB0_CAPTURE0) || \
                                         ((param) == DMACA_TMRB4_CAPTURE0) || \
                                         ((param) == DMACA_TMRB4_CAPTURE1) || \
                                         ((param) == DMACA_TMRB5_CAPTURE0) || \
                                         ((param) == DMACA_TMRB5_CAPTURE1) || \
                                         ((param) == DMACA_TOP_PRIORITY_ADC) || \
                                         ((param) == DMACA_FULL_UART_RX) || \
                                         ((param) == DMACA_FULL_UART_TX))

#define IS_DMACB_BURST_REQ_NUM(param)  (((param) == DMACB_TMRB6_CMP_MATCH) || \
                                         ((param) == DMACB_TMRB7_CMP_MATCH) || \
                                         ((param) == DMACB_TMRB0_CAPTURE1) || \
                                         ((param) == DMACB_TMRB2_CAPTURE0) || \
                                         ((param) == DMACB_TMRB2_CAPTURE1) || \
                                         ((param) == DMACB_TMRB3_CAPTURE0) || \
                                         ((param) == DMACB_TMRB3_CAPTURE1) || \
                                         ((param) == DMACB_TMRB6_CAPTURE0) || \
                                         ((param) == DMACB_TMRB6_CAPTURE1) || \
                                         ((param) == DMACB_NORMAL_ADC) || \
                                         ((param) == DMACB_SSP0_TX) || \
                                         ((param) == DMACB_SSP0_RX) || \
                                         ((param) == DMACB_SSP1_TX) || \
                                         ((param) == DMACB_SSP1_RX) || \
                                         ((param) == DMACB_SSP2_TX) || \
                                         ((param) == DMACB_SSP2_RX))

#define IS_DMACA_SINGLE_REQ_NUM(param)  (((param) == DMACA_FULL_UART_RX) || \
                                         ((param) == DMACA_FULL_UART_TX))

#define IS_DMACB_SINGLE_REQ_NUM(param)  (((param) == DMACB_SSP0_TX) || \
                                         ((param) == DMACB_SSP0_RX) || \
                                         ((param) == DMACB_SSP1_TX) || \
                                         ((param) == DMACB_SSP1_RX) || \
                                         ((param) == DMACB_SSP2_TX) || \
                                         ((param) == DMACB_SSP2_RX))

    typedef union {
        uint32_t All;
        struct {
            uint32_t SIO0_UART0_RX:1;
            uint32_t SIO0_UART0_TX:1;
            uint32_t SIO1_UART1_RX:1;
            uint32_t SIO1_UART1_TX:1;
            uint32_t TMRB8_CMP_MATCH:1;
            uint32_t TMRB9_CMP_MATCH:1;
            uint32_t TMRB0_CAPTURE0:1;
            uint32_t TMRB4_CAPTURE0:1;
            uint32_t TMRB4_CAPTURE1:1;
            uint32_t TMRB5_CAPTURE0:1;
            uint32_t TMRB5_CAPTURE1:1;
            uint32_t TOP_PRIORITY_ADC:1;
            uint32_t Reserved0:2;
            uint32_t FULL_UART_RX:1;
            uint32_t FULL_UART_TX:1;
        } Bit_A;
        struct {
            uint32_t TMRB6_CMP_MATCH:1;
            uint32_t TMRB7_CMP_MATCH:1;
            uint32_t TMRB0_CAPTURE1:1;
            uint32_t TMRB2_CAPTURE0:1;
            uint32_t TMRB2_CAPTURE1:1;
            uint32_t TMRB3_CAPTURE0:1;
            uint32_t TMRB3_CAPTURE1:1;
            uint32_t TMRB6_CAPTURE0:1;
            uint32_t TMRB6_CAPTURE1:1;
            uint32_t NORMAL_ADC:1;
            uint32_t SSP0_TX:1;
            uint32_t SSP0_RX:1;
            uint32_t SSP1_TX:1;
            uint32_t SSP1_RX:1;
            uint32_t SSP2_TX:1;
            uint32_t SSP2_RX:1;
        } Bit_B;
    } DMAC_BurstReqState;

    typedef union {
        uint32_t All;
        struct {
            uint32_t Reserved0:14;
            uint32_t FULL_UART_RX:1;
            uint32_t FULL_UART_TX:1;
        } Bit_A;
        struct {
            uint32_t Reserved0:10;
            uint32_t SSP0_TX:1;
            uint32_t SSP0_RX:1;
            uint32_t SSP1_TX:1;
            uint32_t SSP1_RX:1;
            uint32_t SSP2_TX:1;
            uint32_t SSP2_RX:1;
        } Bit_B;
    } DMAC_SingleReqState;

/** @} */
/* End of group DMAC_Exported_Types */

/** @defgroup DMAC_Exported_Types
  * @{
  */

/** 
  * @brief  DMA Structure definition  
  */

    typedef struct {
        uint32_t TxDirection;   /*!< Set transfer direction  */
        uint32_t SrcAddr;       /*!< Set source address  */
        uint32_t DstAddr;       /*!< Set destination address  */
        FunctionalState SrcIncrementState;      /*!< Specifies whether the source
                                                   address is incremented or not  */
        FunctionalState DstIncrementState;      /*!< Specifies whether the destination
                                                   address is incremented or not  */
        DMAC_BitWidth SrcBitWidth;      /*!< Set transfer source bit width  */
        DMAC_BitWidth DstBitWidth;      /*!< Set transfer destination bit width  */
        DMAC_BurstSize SrcBurstSize;    /* Set transfer source burst size */
        DMAC_BurstSize DstBurstSize;    /* Set transfer destination burst size */
        uint32_t TxSize;        /*!< Set the total number of transfer  */
        DMACA_ReqNum A_TxDstPeriph;     /*!< Set transfer destination  */
        DMACA_ReqNum A_TxSrcPeriph;     /*!< Set transfer source peripheral  */
        DMACB_ReqNum B_TxDstPeriph;     /*!< Set transfer destination peripheral  */
        DMACB_ReqNum B_TxSrcPeriph;     /*!< Set transfer source peripheral  */
        FunctionalState TxINT;  /*!< Set transfer interrupt */
    } DMAC_InitTypeDef;

/** @} */
/* End of group DMAC_Exported_Types */

/** @defgroup DMAC_Exported_FunctionPrototypes
  * @{
  */
    void DMAC_Enable(TSB_DMAC_TypeDef * DMACx);
    void DMAC_Disable(TSB_DMAC_TypeDef * DMACx);
    DMAC_INTReq DMAC_GetINTReq(TSB_DMAC_TypeDef * DMACx);
    DMAC_TxINTReq DMAC_GetTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx);
    void DMAC_ClearTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_INTSrc INTSource);
    DMAC_TxINTReq DMAC_GetRawTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx);
    WorkState DMAC_GetChannelTxState(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx);
    void DMACA_SetSWBurstReq(DMACA_ReqNum BurstReq);
    void DMACB_SetSWBurstReq(DMACB_ReqNum BurstReq);
    DMAC_BurstReqState DMAC_GetSWBurstReqState(TSB_DMAC_TypeDef * DMACx);
    void DMACA_SetSWSingleReq(DMACA_ReqNum SingleReq);
    void DMACB_SetSWSingleReq(DMACB_ReqNum SingleReq);
    DMAC_SingleReqState DMAC_GetSWSingleReqState(TSB_DMAC_TypeDef * DMACx);
    void DMAC_SetLinkedList(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, uint32_t LinkedAddr);
    WorkState DMAC_GetFIFOState(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx);
    void DMAC_SetDMAHalt(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_SetLockedTx(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_SetTxINTConfig(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_INTSrc INTSource,
                             FunctionalState NewState);
    void DMAC_SetDMAChannel(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_Init(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_InitTypeDef * InitStruct);

/** @} */
/* End of group DMAC_Exported_FunctionPrototype */

/** @} */
/* End of group DMAC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM366_DMAC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM366_DMAC_H */
