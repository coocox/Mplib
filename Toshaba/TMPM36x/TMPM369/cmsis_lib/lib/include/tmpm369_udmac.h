/**
 *******************************************************************************
 * @file    tmpm369_udmac.h
 * @brief   This file provides all the functions prototypes for uDMAC driver.
 * @version V2.0.2.2
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM369_uDMAC_H
#define __TMPM369_uDMAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
#include "tx03_common.h"

#if defined(__TMPM369_uDMAC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup uDMAC
  * @{
  */

/** @defgroup uDMAC_Exported_Constants
  * @{
  */
#define DMAC_UNIT_A  TSB_DMAA   /* redefine the name in m369.h */
#define DMAC_UNIT_B  TSB_DMAB
#define IS_DMAC_UNIT(param) (((param) == DMAC_UNIT_A) || ((param) == DMAC_UNIT_B))


/** @} */
/* End of group uDMAC_Exported_Constants */


/** @defgroup uDMAC_Exported_Types
  * @{
  */

    typedef enum {
        DMAC_ADC0_END = 0U,
        DMAC_ADC1_END = 1U,
        DMAC_DAC0_TRG = 2U,
        DMAC_DAC1_TRG = 3U,
        DMAC_SSP0_RX = 4U,      /* SSP0 reception    */
        DMAC_SSP0_TX = 5U,      /* SSP0 transmission */
        DMAC_SSP1_RX = 6U,
        DMAC_SSP1_TX = 7U,
        DMAC_SSP2_RX = 8U,
        DMAC_SSP2_TX = 9U,
        DMAC_FUART4_RX = 10U,   /* Full UART4 reception    */
        DMAC_FUART4_TX = 11U,   /* Full UART4 transmission */
        DMAC_FUART5_RX = 12U,
        DMAC_FUART5_TX = 13U,
        DMAC_SIO0_RX = 14U,     /* SIO/UART0 reception    */
        DMAC_SIO0_TX = 15U,     /* SIO/UART0 transmission */
        DMAC_SIO1_RX = 16U,
        DMAC_SIO1_TX = 17U,
        DMAC_SIO2_RX = 18U,
        DMAC_SIO2_TX = 19U,
        DMAC_SIO3_RX = 20U,
        DMAC_SIO3_TX = 21U,
        DMAC_SBI0_RXTX = 22U,   /* I2C/SIO0 receive/transmit */
        DMAC_SBI1_RXTX = 23U,
        DMAC_SBI2_RXTX = 24U,
        DMAC_TMRB0_CMP_MATCH = 25U,
        DMAC_TMRB1_CMP_MATCH = 26U,
        DMAC_TMRB2_CMP_MATCH = 27U,
        DMAC_TMRB3_CMP_MATCH = 28U,
        DMAC_TMRB4_CMP_MATCH = 29U,
        DMAC_PIN = 30U,         /* DMA request pin    */
        DMAC_SW_TRG = 31U
    } DMAC_Channel;
#define IS_DMAC_CHANNEL_ALL(param)    ((param) <=  DMAC_SW_TRG)
#define IS_DMAC_CHANNEL_BURST(param)  (((param) <=  DMAC_SW_TRG) && ((param) != DMAC_DAC0_TRG) && ((param) != DMAC_DAC1_TRG))
#define IS_DMAC_CHANNEL_SINGLE(param) (((param) >=  DMAC_DAC0_TRG) && ((param) <= DMAC_FUART5_TX))


    typedef enum {
        DMAC_PRIMARY = 0U,
        DMAC_ALTERNATE = 1U
    } DMAC_PrimaryAlt;
#define IS_DMAC_PRIMARYALT(param)   ((param) <= DMAC_ALTERNATE)
#define IS_DMAC_CTRL_BASE(param)    (((param) & (uint32_t)0x3FFU) == (uint32_t)0U)

    typedef enum {
        DMAC_SINGLE = 0U,
        DMAC_BURST = 1U
    } DMAC_TransferType;
#define IS_DMAC_TRANSFERTYPE(param) ((param) <= DMAC_BURST)

    typedef enum {
        DMAC_PRIOTIRY_NORMAL = 0U,
        DMAC_PRIOTIRY_HIGH = 1U
    } DMAC_Priority;
#define IS_DMAC_PRIORITY(param) ((param) <= DMAC_PRIOTIRY_HIGH)


    typedef enum {
        DMAC_BYTE = 0U,         /* data size of transfer is 1 byte */
        DMAC_HALF_WORD = 1U,    /* data size of transfer is 2 bytes */
        DMAC_WORD = 2U          /* data size of transfer is 4 bytes */
    } DMAC_BitWidth;
#define IS_DMAC_BIT_WIDTH(param)    ((param) <= DMAC_WORD)

    typedef enum {
        DMAC_INC_1B = 0U,       /* address increment 1 byte */
        DMAC_INC_2B = 1U,       /* address increment 2 bytes */
        DMAC_INC_4B = 2U,       /* address increment 4 bytes */
        DMAC_INC_0B = 3U        /* address does not increase */
    } DMAC_IncWidth;
#define IS_DMAC_INCWIDTH(param)     ((param) <= DMAC_INC_0B)
#define IS_DMAC_INCWIDTH_VALID(bitwidth, incwidth)     ((bitwidth) <= (incwidth))

    typedef enum {
        DMAC_INVALID = 0U,
        DMAC_BASIC = 1U,
        DMAC_AUTOMATIC = 2U,
        DMAC_PINGPONG = 3U,
        DMAC_MEM_SCATTER_GATHER_PRI = 4U,       /* Memory scatter/gather mode (primary data) */
        DMAC_MEM_SCATTER_GATHER_ALT = 5U,       /* Memory scatter/gather mode (alternative data) */
        DMAC_PERI_SCATTER_GATHER_PRI = 6U,      /* Peripheral scatter/gather mode (primary data) */
        DMAC_PERI_SCATTER_GATHER_ALT = 7U       /* Peripheral scatter/gather mode (alternative data) */
    } DMAC_CycleCtrl;
#define IS_DMAC_CYCLECTRL(param)     ((param) <= DMAC_PERI_SCATTER_GATHER_ALT)

    typedef enum {
        DMAC_NEXT_NOT_USE_BURST = 0U,
        DMAC_NEXT_USE_BURST = 1U
    } DMAC_Next_UseBurst;
#define IS_DMAC_NEXT_USEBURST(param)     ((param) <= DMAC_NEXT_USE_BURST)

    typedef enum {
        DMAC_AFTER_1_TX = 0U,   /* Arbitration after one transfer */
        DMAC_AFTER_2_TX = 1U,   /* Arbitration after two transfer */
        DMAC_AFTER_4_TX = 2U,
        DMAC_AFTER_8_TX = 3U,
        DMAC_AFTER_16_TX = 4U,
        DMAC_AFTER_32_TX = 5U,
        DMAC_AFTER_64_TX = 6U,
        DMAC_AFTER_128_TX = 7U,
        DMAC_AFTER_256_TX = 8U,
        DMAC_AFTER_512_TX = 9U, /* Arbitration after 512 transfer */
        DMAC_NEVER = 10U        /* Do not arbitration */
    } DMAC_Arbitration;
#define IS_DMAC_ARBITRATION(param)     ((param) <= DMAC_NEVER)

#define IS_DMAC_TXNUM(param)     ((param) <= 1024U)


/** 
  * @brief  DMA Structure definition  
  */

    typedef struct {
        uint32_t SrcEndPointer; /*!< The final address of source */
        uint32_t DstEndPointer; /*!< The final address of destination */
        DMAC_CycleCtrl Mode;    /*!< Set operation mode */
        DMAC_Next_UseBurst NextUseBurst;
        uint32_t TxNum;         /*!< Set the actual number of transfers. max is 1024 */
        DMAC_Arbitration ArbitrationMoment;     /*!< Specifies the arbitration moment(R_Power)  */
        DMAC_BitWidth SrcWidth; /*!< Set source bit width */
        DMAC_IncWidth SrcInc;   /*!< Set increment of the source address */
        DMAC_BitWidth DstWidth; /*!< Set destination bit width */
        DMAC_IncWidth DstInc;   /*!< Set increment of the destination address */
    } DMAC_InitTypeDef;


/** @} */
/* End of group uDMAC_Exported_Types */

/** @defgroup uDMAC_Exported_FunctionPrototypes
  * @{
  */
    FunctionalState DMAC_GetDMACState(TSB_DMA_TypeDef * DMACx);
    void DMAC_Enable(TSB_DMA_TypeDef * DMACx);
    void DMAC_Disable(TSB_DMA_TypeDef * DMACx);
    void DMAC_SetPrimaryBaseAddr(TSB_DMA_TypeDef * DMACx, uint32_t Addr);
    uint32_t DMAC_GetBaseAddr(TSB_DMA_TypeDef * DMACx, DMAC_PrimaryAlt PriAlt);
    void DMAC_SetSWReq(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_SetTransferType(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel,
                              DMAC_TransferType Type);
    DMAC_TransferType DMAC_GetTransferType(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_SetMask(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, FunctionalState NewState);
    FunctionalState DMAC_GetMask(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_SetChannel(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, FunctionalState NewState);
    FunctionalState DMAC_GetChannelState(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_SetPrimaryAlt(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, DMAC_PrimaryAlt PriAlt);
    DMAC_PrimaryAlt DMAC_GetPrimaryAlt(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_SetChannelPriority(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel,
                                 DMAC_Priority Priority);
    DMAC_Priority DMAC_GetChannelPriority(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel);
    void DMAC_ClearBusErr(TSB_DMA_TypeDef * DMACx);
    Result DMAC_GetBusErrState(TSB_DMA_TypeDef * DMACx);
    void DMAC_FillInitData(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel,
                           DMAC_InitTypeDef * InitStruct);

/** @} */
/* End of group uDMAC_Exported_FunctionPrototype */

/** @} */
/* End of group uDMAC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM369_uDMAC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM369_uDMAC_H */
