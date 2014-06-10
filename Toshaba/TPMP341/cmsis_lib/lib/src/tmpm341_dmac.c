/**
 *******************************************************************************
 * @file    tmpm341_dmac.c
 * @brief   This file provides API functions for DMAC driver.
 * @version V2.0.2.3
 * @date    2010/02/09
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm341_dmac.h"
#if defined(__TMPM341_DMAC_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup DMAC 
  * @brief DMAC driver modules
  * @{
  */

/** @defgroup DMAC_Private_Defines
  * @{
  */

#define CONFIGURATION_E_SET          ((uint32_t)0x00000001)
#define CONFIGURATION_E_CLEAR        ((uint32_t)0x00000000)

#define INT_STATUS_MASK              ((uint32_t)0x00000003)

#define ENBLDCHNS_CH_FLAG            ((uint32_t)0x00000001)

#define DMAC_SOFTBREQ_MASK           ((uint32_t)0x0000FFFF)
#define DMAC_SOFTSREQ_MASK           ((uint32_t)0x0000C000)

#define DMAC_LLI_MASK                ((uint32_t)0xFFFFFFFC)

#define CXCONFIGURATION_ACTIVE_FLAG  ((uint32_t)0x00020000)
#define CXCONFIGURATION_HALT_CLEAR   ((uint32_t)0x0003FBDF)
#define CXCONFIGURATION_HALT_SET     ((uint32_t)0x00040000)
#define CXCONFIGURATION_LOCK_CLEAR   ((uint32_t)0x0006FBDF)
#define CXCONFIGURATION_LOCK_SET     ((uint32_t)0x00010000)
#define CXCONFIGURATION_ITC_CLEAR    ((uint32_t)0x00077BDF)
#define CXCONFIGURATION_ITC_SET      ((uint32_t)0x00008000)
#define CXCONFIGURATION_IE_CLEAR     ((uint32_t)0x0007BBDF)
#define CXCONFIGURATION_IE_SET       ((uint32_t)0x00004000)
#define CXCONFIGURATION_E_CLEAR      ((uint32_t)0x0007FBDE)
#define CXCONFIGURATION_E_SET        ((uint32_t)0x00000001)

#define CXCONTROL_INIT_MASK          ((uint32_t)0x8003F000)
#define CXCONFIGURATION_INIT_MASK    ((uint32_t)0x0007C001)

/** @} */
/* End of group DMAC_Private_Defines */


/** @defgroup DMAC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group DMAC_Private_FunctionPrototypes */

/** @defgroup DMAC_Private_Functions
  * @{
  */

/** @} */
/* End of group group DMAC_Private_Functions */

/** @defgroup DMAC_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the DMA circuit.
  * @param  None
  * @retval None
  */
void DMAC_Enable(TSB_DMAC_TypeDef * DMACx)
{
    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    /* Set CONFIGURATION<E> to enable the DMA circuit */
    DMACx->CONFIGURATION = CONFIGURATION_E_SET;
}

/**
  * @brief  Disable the DMA circuit.
  * @param  None
  * @retval None
  */
void DMAC_Disable(TSB_DMAC_TypeDef * DMACx)
{
    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    /* Clear CONFIGURATION<E> to disable the DMA circuit */
    DMACx->CONFIGURATION = CONFIGURATION_E_CLEAR;
}

/**
  * @brief  Get DMA Channel interrupt request state.
  * @param  None
  * @retval The state of interrupt request.
  */
DMAC_INTReq DMAC_GetINTReq(TSB_DMAC_TypeDef * DMACx)
{
    DMAC_INTReq tmp = { 0U };

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    /* Get DMAC interrupt request status */
    tmp.All = DMACx->INTSTATUS;
    tmp.All &= INT_STATUS_MASK;

    return tmp;
}

/**
  * @brief  Get the specified DMA Channel transfer interrupt request state.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @retval The request state of DMA transfer interrupt
  *   This parameter can be one of the following values:
  *   DMAC_TX_NO_REQ, DMAC_TX_END_REQ, DMAC_TX_ERR_REQ or DMAC_TX_REQS
  */
DMAC_TxINTReq DMAC_GetTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx)
{
    uint8_t tmp0 = 0U;
    uint8_t tmp1 = 0U;
    uint8_t mask = 1U;
    DMAC_TxINTReq retval = DMAC_TX_NO_REQ;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));

    mask <<= (uint32_t) Chx;
    tmp0 = (uint8_t) (DMACx->INTTCSTATUS & mask);
    tmp1 = (uint8_t) (DMACx->INTERRORSTATUS & mask) << 1U;
    tmp1 = tmp0 | tmp1;

    if (Chx == DMAC_CHANNEL_1) {
        tmp1 >>= 1U;
    } else {
        /* Do nothing */
    }

    switch (tmp1) {
    case DMAC_TX_END_REQ:      /* Check transfer end interrupt request flag */
        /* Transfer end interrupt request */
        retval = DMAC_TX_END_REQ;
        break;
    case DMAC_TX_ERR_REQ:      /* Check transfer error interrupt request flag */
        /* Transfer error interrupt request */
        retval = DMAC_TX_ERR_REQ;
        break;
    case DMAC_TX_REQS:
        /* More than one request */
        retval = DMAC_TX_REQS;
        break;
    default:
        /* Do nothing */
        break;
    }

    return retval;
}

/**
  * @brief  Clear the transfer interrupt request.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param INTSource: Select the release INT source
  *  This parameter can be one of the following values:
  *  DMAC_INT_TX_END, DMAC_INT_TX_ERR
  * @retval None
  */
void DMAC_ClearTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_INTSrc INTSource)
{
    uint32_t tmp = 1U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_INT_SRC(INTSource));

    tmp <<= (uint32_t) Chx;
    if (INTSource == DMAC_INT_TX_END) {
        DMACx->INTTCCLEAR = tmp;
    } else {
        DMACx->INTERRCLR = tmp;
    }
}

/**
  * @brief  Get the specified DMA Channel transfer raw interrupt request state.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @retval The request state of DMA transfer raw interrupt
  *   This parameter can be one of the following values:
  *   DMAC_TX_NO_REQ, DMAC_TX_END_REQ, DMAC_TX_ERR_REQ or DMAC_TX_REQS
  */
DMAC_TxINTReq DMAC_GetRawTxINTReq(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx)
{
    uint8_t tmp0 = 0U;
    uint8_t tmp1 = 0U;
    uint8_t mask = 1U;
    DMAC_TxINTReq retval = DMAC_TX_NO_REQ;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));

    mask <<= (uint32_t) Chx;
    tmp0 = (uint8_t) (DMACx->RAWINTTCSTATUS & mask);
    tmp1 = (uint8_t) (DMACx->RAWINTERRORSTATUS & mask) << 1U;
    tmp1 = tmp0 | tmp1;

    if (Chx == DMAC_CHANNEL_1) {
        tmp1 >>= 1U;
    } else {
        /* Do nothing */
    }

    switch (tmp1) {
    case DMAC_TX_END_REQ:      /* Check transfer end interrupt request flag */
        /* Transfer end interrupt request */
        retval = DMAC_TX_END_REQ;
        break;
    case DMAC_TX_ERR_REQ:      /* Check transfer error interrupt request flag */
        /* Transfer error interrupt request */
        retval = DMAC_TX_ERR_REQ;
        break;
    case DMAC_TX_REQS:
        /* More than one request */
        retval = DMAC_TX_REQS;
        break;
    default:
        /* Do nothing */
        break;
    }

    return retval;
}

/**
  * @brief  Get the specified DMA Channel transfer state.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @retval The DMA transfer status.
  *   The value returned can be one of the followings:
  *   BUSY or DONE.
  */
WorkState DMAC_GetChannelTxState(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx)
{
    uint32_t tmp = 0U;
    WorkState retval = BUSY;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));

    tmp = DMACx->ENBLDCHNS;
    tmp >>= (uint32_t) Chx;

    if ((tmp & ENBLDCHNS_CH_FLAG) == 0U) {
        /* Return transfer completed if the flag is clear */
        retval = DONE;
    } else {
        /* Do nothing */
    }

    return retval;
}

/**
  * @brief  Set DMA burst transfer requests by software.
  * @param  BurstReq: Select burst request number.
  *   This parameter can one of the following values:
  *   DMACA_SIO0_UART0_RX, DMACA_SIO0_UART0_TX, DMACA_SIO2_UART2_RX, DMACA_SIO2_UART2_TX, 
  *   DMACA_SIO4_UART4_RX, DMACA_SIO4_UART4_TX, DMACA_PULSE_CNT2, DMACA_PULSE_CNT3, 
  *   DMACA_TMRB8_CMP_MATCH, DMACA_TMRB9_CMP_MATCH, DMACA_TMRB0_CAPTURE0, DMACA_TMRB4_CAPTURE0,
  *   DMACA_TMRB4_CAPTURE1, DMACA_TMRB5_CAPTURE0, DMACA_TMRB5_CAPTURE1, DMACA_HIGH_PRIORITY_ADC
  * @retval None
  */
void DMACA_SetSWBurstReq(DMACA_ReqNum BurstReq)
{
    uint32_t tmp = 0U;
    uint32_t mask = 1U;

    /* Check the parameters */
    assert_param(IS_DMACA_BURST_REQ_NUM(BurstReq));

    tmp = TSB_DMACA->SOFTBREQ;
    mask <<= ((uint32_t) BurstReq);
    tmp &= ~mask;
    tmp &= (uint32_t) DMAC_SOFTBREQ_MASK;
    mask = 1U;
    tmp |= (uint32_t) (mask << BurstReq);
    /* Set DMA software burst request */
    TSB_DMACA->SOFTBREQ = tmp;
}

/**
  * @brief  Set DMA burst transfer requests by software.
  * @param  BurstReq: Select burst request number.
  *   This parameter can one of the following values:
  *   DMACB_TMRD00_CMP_MATCH, DMACB_TMRD10_CMP_MATCH, DMACB_PULSE_CNT0, DMACB_PULSE_CNT1, 
  *   DMACB_TMRB6_CMP_MATCH, DMACB_TMRB7_CMP_MATCH, DMACB_TMRB0_CAPTURE1, DMACB_TMRB2_CAPTURE0, 
  *   DMACB_TMRB2_CAPTURE1, DMACB_TMRB3_CAPTURE0, DMACB_TMRB3_CAPTURE1, DMACB_TMRB6_CAPTURE0, 
  *   DMACB_TMRB6_CAPTURE1, DMACB_NORMAL_ADC, DMACB_SSP_TX, DMACB_SSP_RX
  * @retval None
  */
void DMACB_SetSWBurstReq(DMACB_ReqNum BurstReq)
{
    uint32_t tmp = 0U;
    uint32_t mask = 1U;

    /* Check the parameters */
    assert_param(IS_DMACB_BURST_REQ_NUM(BurstReq));

    tmp = TSB_DMACB->SOFTBREQ;
    mask <<= ((uint32_t) BurstReq);
    tmp &= ~mask;
    tmp &= (uint32_t) DMAC_SOFTBREQ_MASK;
    mask = 1U;
    tmp |= (uint32_t) (mask << BurstReq);
    /* Set DMA software burst request */
    TSB_DMACB->SOFTBREQ = tmp;
}

/**
  * @brief  Get DMA software burst request state.
  * @param  None
  * @retval The DMA burst request status.
  */
DMAC_BurstReqState DMAC_GetSWBurstReqState(TSB_DMAC_TypeDef * DMACx)
{
    DMAC_BurstReqState tmp = { 0U };
    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));

    /* Get DMA burst request status */
    tmp.All = DMACx->SOFTBREQ;
    tmp.All &= DMAC_SOFTBREQ_MASK;

    return tmp;
}

/**
  * @brief  Set DMA single transfer requests by software.
  * @param  SingleReq: Select single request number.
  *   This parameter can one of the following values:
  *   DMACB_SSP_TX, DMACB_SSP_RX
  * @retval None
  */
void DMACB_SetSWSingleReq(DMACB_ReqNum SingleReq)
{
    uint32_t tmp = 0U;
    uint32_t mask = 1U;

    /* Check the parameters */
    assert_param(IS_DMACB_SINGLE_REQ_NUM(SingleReq));

    tmp = TSB_DMACB->SOFTSREQ;
    mask <<= ((uint32_t) SingleReq);
    tmp &= ~mask;
    tmp &= (uint32_t) DMAC_SOFTSREQ_MASK;
    mask = 1U;
    tmp |= (uint32_t) mask << SingleReq;
    /* Set DMA software single request */
    TSB_DMACB->SOFTSREQ = tmp;
}

/**
  * @brief  Get DMA software single request state.
  * @param  None
  * @retval The DMA single request status.
  */
DMAC_SingleReqState DMAC_GetSWSingleReqState(TSB_DMAC_TypeDef * DMACx)
{
    DMAC_SingleReqState tmp = { 0U };

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));

    /* Get DMA single request status */
    tmp.All = DMACx->SOFTSREQ;
    tmp.All &= DMAC_SOFTSREQ_MASK;

    return tmp;
}

/**
  * @brief  Set specified DMA Channel Linked List Item Register.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param  LinkedAddr: The start address of the next transfer information.
  *   Max 0xFFFFFFF0
  * @retval None
  */
void DMAC_SetLinkedList(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, uint32_t LinkedAddr)
{
    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_LINK_ADDR_MAX_VALUE(LinkedAddr));

    LinkedAddr &= DMAC_LLI_MASK;

    if (Chx == DMAC_CHANNEL_0) {
        DMACx->C0LLI = LinkedAddr;
    } else {
        DMACx->C1LLI = LinkedAddr;
    }
}

/**
  * @brief  Indicates whether data is present in the channel FIFO.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @retval The FIFO status.
  *   The value returned can be one of the followings:
  *   BUSY or DONE.
  */
WorkState DMAC_GetFIFOState(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx)
{
    uint32_t tmp = 0U;
    WorkState retval = BUSY;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));

    if (Chx == DMAC_CHANNEL_0) {
        tmp = DMACx->C0CONFIGURATION;
    } else {
        tmp = DMACx->C1CONFIGURATION;
    }

    tmp &= CXCONFIGURATION_ACTIVE_FLAG;

    if (tmp == 0U) {
        /* Return FIFO empty if the flag is clear */
        retval = DONE;
    } else {
        /* Do nothing */
    }

    return retval;
}

/**
  * @brief  Set whether ignore DMA request.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param  NewState: New halt state of DMA.
  *   This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void DMAC_SetDMAHalt(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = DMACx->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_HALT_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_HALT_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = DMACx->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_HALT_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_HALT_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C1CONFIGURATION = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set whether locked transfer.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param  NewState: New state of DMA transfer.
  *   This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void DMAC_SetLockedTx(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = DMACx->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_LOCK_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_LOCK_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = DMACx->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_LOCK_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_LOCK_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C1CONFIGURATION = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable or disable the specified DMA Channel transfer interrupt.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param INTSource: select the release INT source
  *  This parameter can be one of the following values:
  *  DMAC_INT_TX_END, DMAC_INT_TX_ERR
  * @param  NewState: New state of DMA transfer interrupt.
  *   This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void DMAC_SetTxINTConfig(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_INTSrc INTSource,
                         FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_INT_SRC(INTSource));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = DMACx->C0CONFIGURATION;

        if (INTSource == DMAC_INT_TX_END) {
            tmp &= CXCONFIGURATION_ITC_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_ITC_SET;
            } else {
                /* Do nothing */
            }

            DMACx->C0CONFIGURATION = tmp;
        } else {
            tmp &= CXCONFIGURATION_IE_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_IE_SET;
            } else {
                /* Do nothing */
            }

            DMACx->C0CONFIGURATION = tmp;
        }

        break;
    case DMAC_CHANNEL_1:
        tmp = DMACx->C1CONFIGURATION;

        if (INTSource == DMAC_INT_TX_END) {
            tmp &= CXCONFIGURATION_ITC_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_ITC_SET;
            } else {
                /* Do nothing */
            }

            DMACx->C1CONFIGURATION = tmp;
        } else {
            tmp &= CXCONFIGURATION_IE_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_IE_SET;
            } else {
                /* Do nothing */
            }

            DMACx->C1CONFIGURATION = tmp;
        }

        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable or disable the specified DMA Channel.
  * @param  Chx: Select DMA channel
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param  NewState: New state of DMA channel.
  *   This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void DMAC_SetDMAChannel(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = DMACx->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_E_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_E_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = DMACx->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_E_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_E_SET;
        } else {
            /* Do nothing */
        }

        DMACx->C1CONFIGURATION = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Initialize the specified DMA channel.
  * @param  Chx: Select DMA channel.
  *   This parameter can be one of the following values:
  *   DMAC_CHANNEL_0 or DMAC_CHANNEL_1
  * @param  InitStruct: The structure containing basic DMA configuration.
  * @retval None
  */
void DMAC_Init(TSB_DMAC_TypeDef * DMACx, DMAC_Channel Chx, DMAC_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_TX_DIRECTION(InitStruct->TxDirection));
    assert_param(IS_FUNCTIONAL_STATE(InitStruct->SrcIncrementState));
    assert_param(IS_FUNCTIONAL_STATE(InitStruct->DstIncrementState));
    assert_param(IS_DMAC_BIT_WIDTH(InitStruct->SrcBitWidth));
    assert_param(IS_DMAC_BIT_WIDTH(InitStruct->DstBitWidth));
    assert_param(IS_DMAC_BURST_SIZE(InitStruct->SrcBurstSize));
    assert_param(IS_DMAC_BURST_SIZE(InitStruct->DstBurstSize));
    assert_param(IS_DMAC_TX_SIZE(InitStruct->TxSize));

    switch (InitStruct->TxDirection) {
    case DMAC_MEMORY_TO_PERIPH:
        if (TSB_DMACA == DMACx) {
            assert_param(IS_DMACA_REQ_NUM(InitStruct->A_TxDstPeriph));
        } else {
            assert_param(IS_DMACB_REQ_NUM(InitStruct->B_TxDstPeriph));
        }
        break;
    case DMAC_PERIPH_TO_MEMORY:
        if (TSB_DMACA == DMACx) {
            assert_param(IS_DMACA_REQ_NUM(InitStruct->A_TxSrcPeriph));
        } else {
            assert_param(IS_DMACB_REQ_NUM(InitStruct->B_TxSrcPeriph));
        }
        break;
    case DMAC_PERIPH_TO_PERIPH:
        if (TSB_DMACA == DMACx) {
            assert_param(IS_DMACA_REQ_NUM(InitStruct->A_TxDstPeriph));
            assert_param(IS_DMACA_REQ_NUM(InitStruct->A_TxSrcPeriph));
        } else {
            assert_param(IS_DMACB_REQ_NUM(InitStruct->B_TxDstPeriph));
            assert_param(IS_DMACB_REQ_NUM(InitStruct->B_TxSrcPeriph));
        }
        break;
    default:
        /*Do nothing */
        break;
    }

    assert_param(IS_FUNCTIONAL_STATE(InitStruct->TxINT));

    if (Chx == DMAC_CHANNEL_0) {
        /* Set DMA source address */
        DMACx->C0SRCADDR = InitStruct->SrcAddr;
        /* Set DMA destination address */
        DMACx->C0DESTADDR = InitStruct->DstAddr;

        /* Initialize DMA CxCONTROL register */
        tmp = DMACx->C0CONTROL;
        tmp &= CXCONTROL_INIT_MASK;
        tmp |= InitStruct->TxSize | (uint32_t) InitStruct->SrcIncrementState << 26U |
            (uint32_t) InitStruct->DstIncrementState << 27U |
            (uint32_t) InitStruct->SrcBitWidth << 18U |
            (uint32_t) InitStruct->DstBitWidth << 21U |
            (uint32_t) InitStruct->SrcBurstSize << 12U |
            (uint32_t) InitStruct->DstBurstSize << 15U | (uint32_t) InitStruct->TxINT << 31U;
        DMACx->C0CONTROL = tmp;

        /* Initialize DMA CxCONFIGURATION register */
        tmp = DMACx->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_INIT_MASK;
        tmp |= InitStruct->TxDirection;

        switch (InitStruct->TxDirection) {
        case DMAC_MEMORY_TO_PERIPH:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxDstPeriph << 6U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxDstPeriph << 6U;
            }
            break;
        case DMAC_PERIPH_TO_MEMORY:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxSrcPeriph << 1U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxSrcPeriph << 1U;
            }
            break;
        case DMAC_PERIPH_TO_PERIPH:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxDstPeriph << 6U;
                tmp |= (uint32_t) InitStruct->A_TxSrcPeriph << 1U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxDstPeriph << 6U;
                tmp |= (uint32_t) InitStruct->B_TxSrcPeriph << 1U;
            }
            break;
        default:
            /* Do nothing */
            break;
        }

        DMACx->C0CONFIGURATION = tmp;
    } else {
        /* Set DMA source address */
        DMACx->C1SRCADDR = InitStruct->SrcAddr;
        /* Set DMA destination address */
        DMACx->C1DESTADDR = InitStruct->DstAddr;

        /* Initialize DMA CxCONTROL register */
        tmp = DMACx->C1CONTROL;
        tmp &= CXCONTROL_INIT_MASK;
        tmp |= InitStruct->TxSize | (uint32_t) InitStruct->SrcIncrementState << 26U |
            (uint32_t) InitStruct->DstIncrementState << 27U |
            (uint32_t) InitStruct->SrcBitWidth << 18U |
            (uint32_t) InitStruct->DstBitWidth << 21U |
            (uint32_t) InitStruct->SrcBurstSize << 12U |
            (uint32_t) InitStruct->DstBurstSize << 15U | (uint32_t) InitStruct->TxINT << 31U;
        DMACx->C1CONTROL = tmp;

        /* Initialize DMA CxCONFIGURATION register */
        tmp = DMACx->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_INIT_MASK;
        tmp |= InitStruct->TxDirection;

        switch (InitStruct->TxDirection) {
        case DMAC_MEMORY_TO_PERIPH:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxDstPeriph << 6U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxDstPeriph << 6U;
            }
            break;
        case DMAC_PERIPH_TO_MEMORY:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxSrcPeriph << 1U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxSrcPeriph << 1U;
            }
            break;
        case DMAC_PERIPH_TO_PERIPH:
            if (DMACx == TSB_DMACA) {
                tmp |= (uint32_t) InitStruct->A_TxDstPeriph << 6U;
                tmp |= (uint32_t) InitStruct->A_TxSrcPeriph << 1U;
            } else {
                tmp |= (uint32_t) InitStruct->B_TxDstPeriph << 6U;
                tmp |= (uint32_t) InitStruct->B_TxSrcPeriph << 1U;
            }
            break;
        default:
            /* Do nothing */
            break;
        }

        DMACx->C1CONFIGURATION = tmp;
    }
}

/** @} */
/* End of group DMAC_Exported_Functions */

/** @} */
/* End of group DMAC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM341_DMAC_H) */
