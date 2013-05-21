/**
 *******************************************************************************
 * @file    tmpm362_dmac.h
 * @brief   This file provides all the functions prototypes for DMAC driver.
 * @version V2.2.0
 * @date    2010/12/02
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM362_DMAC_H
#define __TMPM362_DMAC_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM362.h"
#include "tx03_common.h"

#if defined(__TMPM360_DMAC_H) || defined(__TMPM361_DMAC_H) || defined(__TMPM362_DMAC_H) || \
    defined(__TMPM363_DMAC_H) || defined(__TMPM364_DMAC_H)
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
#define IS_DMAC_TX_DIRECTION(param) (((param) == DMAC_MEMORY_TO_MEMORY) || \
                                     ((param) == DMAC_MEMORY_TO_PERIPH) || \
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
            uint32_t CH0_INTReq     : 1;
            uint32_t CH1_INTReq     : 1;
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
        DMAC_SIO_0_RTX = 0U,
        DMAC_SIO_1_RTX = 1U,
        DMAC_SIO_2_RTX = 2U,
        DMAC_SIO_3_RTX = 3U,
        DMAC_SIO_4_RTX = 4U,
        DMAC_SIO_5_RTX = 5U,
        DMAC_SIO_6_RTX = 6U,
        DMAC_SIO_7_RTX = 7U,
        DMAC_SIO_8_RTX = 8U,
        DMAC_SIO_9_RTX = 9U,
        DMAC_SIO_10_RTX = 10U,
        DMAC_SIO_11_RTX = 11U,
        DMAC_SSP_TX = 12U,
        DMAC_SSP_RX = 13U,
        DMAC_AD_CONVERT_END = 15U
    } DMAC_ReqNum;

#define IS_DMAC_REQ_NUM(param)  (((param) == DMAC_SIO_0_RTX) || \
                                 ((param) == DMAC_SIO_1_RTX) || \
                                 ((param) == DMAC_SIO_2_RTX) || \
                                 ((param) == DMAC_SIO_3_RTX) || \
                                 ((param) == DMAC_SIO_4_RTX) || \
                                 ((param) == DMAC_SIO_5_RTX) || \
                                 ((param) == DMAC_SIO_6_RTX) || \
                                 ((param) == DMAC_SIO_7_RTX) || \
                                 ((param) == DMAC_SIO_8_RTX) || \
                                 ((param) == DMAC_SIO_9_RTX) || \
                                 ((param) == DMAC_SIO_10_RTX) || \
                                 ((param) == DMAC_SIO_11_RTX) || \
                                 ((param) == DMAC_SSP_TX) || \
                                 ((param) == DMAC_SSP_RX) || \
                                 ((param) == DMAC_AD_CONVERT_END))

#define IS_DMAC_BURST_REQ_NUM(param)  (((param) == DMAC_SIO_0_RTX) || \
                                       ((param) == DMAC_SIO_1_RTX) || \
                                       ((param) == DMAC_SIO_2_RTX) || \
                                       ((param) == DMAC_SIO_3_RTX) || \
                                       ((param) == DMAC_SIO_4_RTX) || \
                                       ((param) == DMAC_SIO_5_RTX) || \
                                       ((param) == DMAC_SIO_6_RTX) || \
                                       ((param) == DMAC_SIO_7_RTX) || \
                                       ((param) == DMAC_SIO_8_RTX) || \
                                       ((param) == DMAC_SIO_9_RTX) || \
                                       ((param) == DMAC_SIO_10_RTX) || \
                                       ((param) == DMAC_SIO_11_RTX) || \
                                       ((param) == DMAC_SSP_TX) || \
                                       ((param) == DMAC_SSP_RX) || \
                                       ((param) == DMAC_AD_CONVERT_END))

#define IS_DMAC_SINGLE_REQ_NUM(param)  ((param) == DMAC_SSP_RX)

    typedef union {
        uint32_t All;
        struct {
            uint32_t SIO0_RTx         : 1;
            uint32_t SIO1_RTx         : 1;
            uint32_t SIO2_RTx         : 1;
            uint32_t SIO3_RTx         : 1;
            uint32_t SIO4_RTx         : 1;
            uint32_t SIO5_RTx         : 1;
            uint32_t SIO6_RTx         : 1;
            uint32_t SIO7_RTx         : 1;
            uint32_t SIO8_RTx         : 1;
            uint32_t SIO9_RTx         : 1;
            uint32_t SIO10_RTx        : 1;
            uint32_t SIO11_RTx        : 1;
            uint32_t SSP_Tx           : 1;
            uint32_t SSP_Rx           : 1;
            uint32_t Reserved         : 1;
            uint32_t AD_Convert_End   : 1;
        } Bit;
    } DMAC_BurstReqState;

    typedef union {
        uint32_t All;
        struct {
            uint32_t Reserved         : 13;
            uint32_t SSP_Rx           : 1;
        } Bit;
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
        DMAC_ReqNum TxPeriph;   /*!< Set transfer destination/source peripheral  */
        FunctionalState TxINT;  /*!< Set transfer interrupt */
    } DMAC_InitTypeDef;

/** @} */
/* End of group DMAC_Exported_Types */

/** @defgroup DMAC_Exported_FunctionPrototypes
  * @{
  */
    void DMAC_Enable(void);
    void DMAC_Disable(void);
    DMAC_INTReq DMAC_GetINTReq(void);
    DMAC_TxINTReq DMAC_GetTxINTReq(DMAC_Channel Chx);
    void DMAC_ClearTxINTReq(DMAC_Channel Chx, DMAC_INTSrc INTSource);
    DMAC_TxINTReq DMAC_GetRawTxINTReq(DMAC_Channel Chx);
    WorkState DMAC_GetChannelTxState(DMAC_Channel Chx);
    void DMAC_SetSWBurstReq(DMAC_ReqNum BurstReq);
    DMAC_BurstReqState DMAC_GetSWBurstReqState(void);
    void DMAC_SetSWSingleReq(DMAC_ReqNum SingleReq);
    DMAC_SingleReqState DMAC_GetSWSingleReqState(void);
    void DMAC_SetLinkedList(DMAC_Channel Chx, uint32_t LinkedAddr);
    WorkState DMAC_GetFIFOState(DMAC_Channel Chx);
    void DMAC_SetDMAHalt(DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_SetLockedTx(DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_SetTxINTConfig(DMAC_Channel Chx, DMAC_INTSrc INTSource, FunctionalState NewState);
    void DMAC_SetDMAChannel(DMAC_Channel Chx, FunctionalState NewState);
    void DMAC_Init(DMAC_Channel Chx, DMAC_InitTypeDef * InitStruct);

/** @} */
/* End of group DMAC_Exported_FunctionPrototype */

/** @} */
/* End of group DMAC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM360_DMAC_H) || defined(__TMPM361_DMAC_H) || \*/
                                /* defined(__TMPM362_DMAC_H) || defined(__TMPM363_DMAC_H) || \*/
                                /* defined(__TMPM364_DMAC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM362_DMAC_H */
