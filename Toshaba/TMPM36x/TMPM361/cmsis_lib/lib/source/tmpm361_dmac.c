/**
 *******************************************************************************
 * @file    tmpm361_dmac.c
 * @brief   This file provides API functions for DMAC driver.
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm361_dmac.h"
#if defined(__TMPM360_DMAC_H) || defined(__TMPM361_DMAC_H) || defined(__TMPM362_DMAC_H) || \
    defined(__TMPM363_DMAC_H) || defined(__TMPM364_DMAC_H)

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

#define DMAC_SOFTBREQ_MASK           ((uint32_t)0x0000BFFF)
#define DMAC_SOFTSREQ_MASK           ((uint32_t)0x00002000)

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
void DMAC_Enable(void)
{
    /* Set CONFIGURATION<E> to enable the DMA circuit */
    TSB_DMAC->CONFIGURATION = CONFIGURATION_E_SET;
}

/**
  * @brief  Disable the DMA circuit.
  * @param  None
  * @retval None
  */
void DMAC_Disable(void)
{
    /* Clear CONFIGURATION<E> to disable the DMA circuit */
    TSB_DMAC->CONFIGURATION = CONFIGURATION_E_CLEAR;
}

/**
  * @brief  Get DMA Channel interrupt request state.
  * @param  None
  * @retval The state of interrupt request.
  */
DMAC_INTReq DMAC_GetINTReq(void)
{
    DMAC_INTReq tmp = { 0U };

    /* Get DMAC interrupt request status */
    tmp.All = TSB_DMAC->INTSTATUS;
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
DMAC_TxINTReq DMAC_GetTxINTReq(DMAC_Channel Chx)
{
    uint8_t tmp0 = 0U;
    uint8_t tmp1 = 0U;
    uint8_t mask = 1U;
    DMAC_TxINTReq retval = DMAC_TX_NO_REQ;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));

    mask <<= (uint32_t) Chx;
    tmp0 = (uint8_t) (TSB_DMAC->INTTCSTATUS & mask);
    tmp1 = (uint8_t) (TSB_DMAC->INTERRORSTATUS & mask) << 1U;
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
void DMAC_ClearTxINTReq(DMAC_Channel Chx, DMAC_INTSrc INTSource)
{
    uint32_t tmp = 1U;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_INT_SRC(INTSource));

    tmp <<= (uint32_t) Chx;

    if (INTSource == DMAC_INT_TX_END) {
        TSB_DMAC->INTTCCLEAR = tmp;
    } else {
        TSB_DMAC->INTERRCLR = tmp;
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
DMAC_TxINTReq DMAC_GetRawTxINTReq(DMAC_Channel Chx)
{
    uint8_t tmp0 = 0U;
    uint8_t tmp1 = 0U;
    uint8_t mask = 1U;
    DMAC_TxINTReq retval = DMAC_TX_NO_REQ;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));

    mask <<= (uint32_t) Chx;
    tmp0 = (uint8_t) (TSB_DMAC->RAWINTTCSTATUS & mask);
    tmp1 = (uint8_t) (TSB_DMAC->RAWINTERRORSTATUS & mask) << 1U;
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
WorkState DMAC_GetChannelTxState(DMAC_Channel Chx)
{
    uint32_t tmp = 0U;
    WorkState retval = BUSY;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));

    tmp = TSB_DMAC->ENBLDCHNS;
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
  *   DMAC_SIO_0_RTX, DMAC_SIO_1_RTX, DMAC_SIO_2_RTX, DMAC_SIO_3_RTX,
  *   DMAC_SIO_4_RTX, DMAC_SIO_5_RTX, DMAC_SIO_6_RTX, DMAC_SIO_7_RTX,
  *   DMAC_SIO_8_RTX, DMAC_SIO_9_RTX, DMAC_SIO_10_RTX, DMAC_SIO_11_RTX,
  *   DMAC_SSP_TX, DMAC_SSP_RX, DMAC_AD_CONVERT_END
  * @retval None
  */
void DMAC_SetSWBurstReq(DMAC_ReqNum BurstReq)
{
    uint32_t tmp = 0U;
    uint32_t mask = 1U;

    /* Check the parameters */
    assert_param(IS_DMAC_BURST_REQ_NUM(BurstReq));

    tmp = TSB_DMAC->SOFTBREQ;
    mask <<= ((uint32_t) BurstReq);
    tmp &= ~mask;
    tmp &= (uint32_t) 0xBFFF;
    mask = 1U;
    tmp |= (uint32_t) (mask << BurstReq);
    /* Set DMA software burst request */
    TSB_DMAC->SOFTBREQ = tmp;
}

/**
  * @brief  Get DMA software burst request state.
  * @param  None
  * @retval The DMA burst request status.
  */
DMAC_BurstReqState DMAC_GetSWBurstReqState(void)
{
    DMAC_BurstReqState tmp = { 0U };

    /* Get DMA burst request status */
    tmp.All = TSB_DMAC->SOFTBREQ;
    tmp.All &= DMAC_SOFTBREQ_MASK;

    return tmp;
}

/**
  * @brief  Set DMA single transfer requests by software.
  * @param  SingleReq: Select single request number.
  *   This parameter can one of the following values:
  *   DMAC_SSP_RX
  * @retval None
  */
void DMAC_SetSWSingleReq(DMAC_ReqNum SingleReq)
{
    uint32_t tmp = 0U;
    uint32_t mask = 1U;

    /* Check the parameters */
    assert_param(IS_DMAC_SINGLE_REQ_NUM(SingleReq));

    tmp = TSB_DMAC->SOFTSREQ;
    mask <<= ((uint32_t) SingleReq);
    tmp &= mask;
    mask = 1U;
    tmp |= (uint32_t) mask << SingleReq;
    /* Set DMA software single request */
    TSB_DMAC->SOFTSREQ = tmp;
}

/**
  * @brief  Get DMA software single request state.
  * @param  None
  * @retval The DMA single request status.
  */
DMAC_SingleReqState DMAC_GetSWSingleReqState(void)
{
    DMAC_SingleReqState tmp = { 0U };

    /* Get DMA single request status */
    tmp.All = TSB_DMAC->SOFTSREQ;
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
void DMAC_SetLinkedList(DMAC_Channel Chx, uint32_t LinkedAddr)
{
    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_LINK_ADDR_MAX_VALUE(LinkedAddr));

    LinkedAddr &= DMAC_LLI_MASK;

    if (Chx == DMAC_CHANNEL_0) {
        TSB_DMAC->C0LLI = LinkedAddr;
    } else {
        TSB_DMAC->C1LLI = LinkedAddr;
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
WorkState DMAC_GetFIFOState(DMAC_Channel Chx)
{
    uint32_t tmp = 0U;
    WorkState retval = BUSY;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));

    if (Chx == DMAC_CHANNEL_0) {
        tmp = TSB_DMAC->C0CONFIGURATION;
    } else {
        tmp = TSB_DMAC->C1CONFIGURATION;
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
void DMAC_SetDMAHalt(DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = TSB_DMAC->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_HALT_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_HALT_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = TSB_DMAC->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_HALT_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_HALT_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C1CONFIGURATION = tmp;
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
void DMAC_SetLockedTx(DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = TSB_DMAC->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_LOCK_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_LOCK_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = TSB_DMAC->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_LOCK_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_LOCK_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C1CONFIGURATION = tmp;
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
void DMAC_SetTxINTConfig(DMAC_Channel Chx, DMAC_INTSrc INTSource, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_DMAC_INT_SRC(INTSource));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = TSB_DMAC->C0CONFIGURATION;

        if (INTSource == DMAC_INT_TX_END) {
            tmp &= CXCONFIGURATION_ITC_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_ITC_SET;
            } else {
                /* Do nothing */
            }

            TSB_DMAC->C0CONFIGURATION = tmp;
        } else {
            tmp &= CXCONFIGURATION_IE_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_IE_SET;
            } else {
                /* Do nothing */
            }

            TSB_DMAC->C0CONFIGURATION = tmp;
        }

        break;
    case DMAC_CHANNEL_1:
        tmp = TSB_DMAC->C1CONFIGURATION;

        if (INTSource == DMAC_INT_TX_END) {
            tmp &= CXCONFIGURATION_ITC_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_ITC_SET;
            } else {
                /* Do nothing */
            }

            TSB_DMAC->C1CONFIGURATION = tmp;
        } else {
            tmp &= CXCONFIGURATION_IE_CLEAR;

            if (NewState == ENABLE) {
                tmp |= CXCONFIGURATION_IE_SET;
            } else {
                /* Do nothing */
            }

            TSB_DMAC->C1CONFIGURATION = tmp;
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
void DMAC_SetDMAChannel(DMAC_Channel Chx, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DMAC_CHANNEL(Chx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    switch (Chx) {
    case DMAC_CHANNEL_0:
        tmp = TSB_DMAC->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_E_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_E_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C0CONFIGURATION = tmp;
        break;
    case DMAC_CHANNEL_1:
        tmp = TSB_DMAC->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_E_CLEAR;

        if (NewState == ENABLE) {
            tmp |= CXCONFIGURATION_E_SET;
        } else {
            /* Do nothing */
        }

        TSB_DMAC->C1CONFIGURATION = tmp;
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
void DMAC_Init(DMAC_Channel Chx, DMAC_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
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

    if ((InitStruct->TxDirection == DMAC_MEMORY_TO_PERIPH) ||
        (InitStruct->TxDirection == DMAC_PERIPH_TO_MEMORY)) {
        assert_param(IS_DMAC_REQ_NUM(InitStruct->TxPeriph));
    } else {
        /* Do nothing */
    }

    assert_param(IS_FUNCTIONAL_STATE(InitStruct->TxINT));

    if (Chx == DMAC_CHANNEL_0) {
        /* Set DMA source address */
        TSB_DMAC->C0SRCADDR = InitStruct->SrcAddr;
        /* Set DMA destination address */
        TSB_DMAC->C0DESTADDR = InitStruct->DstAddr;

        /* Initialize DMA CxCONTROL register */
        tmp = TSB_DMAC->C0CONTROL;
        tmp &= CXCONTROL_INIT_MASK;
        tmp |= InitStruct->TxSize | (uint32_t) InitStruct->SrcIncrementState << 26U |
            (uint32_t) InitStruct->DstIncrementState << 27U |
            (uint32_t) InitStruct->SrcBitWidth << 18U |
            (uint32_t) InitStruct->DstBitWidth << 21U |
            (uint32_t) InitStruct->SrcBurstSize << 12U |
            (uint32_t) InitStruct->DstBurstSize << 15U |
            (uint32_t) InitStruct->TxINT << 31U;
        TSB_DMAC->C0CONTROL = tmp;

        /* Initialize DMA CxCONFIGURATION register */
        tmp = TSB_DMAC->C0CONFIGURATION;
        tmp &= CXCONFIGURATION_INIT_MASK;
        tmp |= InitStruct->TxDirection;

        switch (InitStruct->TxDirection) {
        case DMAC_MEMORY_TO_MEMORY:
            /* Do nothing */
            break;
        case DMAC_MEMORY_TO_PERIPH:
            tmp |= (uint32_t) InitStruct->TxPeriph << 6U;
            break;
        case DMAC_PERIPH_TO_MEMORY:
            tmp |= (uint32_t) InitStruct->TxPeriph << 1U;
            break;
        default:
            /* Do nothing */
            break;
        }

        TSB_DMAC->C0CONFIGURATION = tmp;
    } else {
        /* Set DMA source address */
        TSB_DMAC->C1SRCADDR = InitStruct->SrcAddr;
        /* Set DMA destination address */
        TSB_DMAC->C1DESTADDR = InitStruct->DstAddr;

        /* Initialize DMA CxCONTROL register */
        tmp = TSB_DMAC->C1CONTROL;
        tmp &= CXCONTROL_INIT_MASK;
        tmp |= InitStruct->TxSize | (uint32_t) InitStruct->SrcIncrementState << 26U |
            (uint32_t) InitStruct->DstIncrementState << 27U |
            (uint32_t) InitStruct->SrcBitWidth << 18U |
            (uint32_t) InitStruct->DstBitWidth << 21U |
            (uint32_t) InitStruct->SrcBurstSize << 12U |
            (uint32_t) InitStruct->DstBurstSize << 15U |
            (uint32_t) InitStruct->TxINT << 31U;
        TSB_DMAC->C1CONTROL = tmp;

        /* Initialize DMA CxCONFIGURATION register */
        tmp = TSB_DMAC->C1CONFIGURATION;
        tmp &= CXCONFIGURATION_INIT_MASK;
        tmp |= InitStruct->TxDirection;

        switch (InitStruct->TxDirection) {
        case DMAC_MEMORY_TO_MEMORY:
            /* Do nothing */
            break;
        case DMAC_MEMORY_TO_PERIPH:
            tmp |= (uint32_t) InitStruct->TxPeriph << 6U;
            break;
        case DMAC_PERIPH_TO_MEMORY:
            tmp |= (uint32_t) InitStruct->TxPeriph << 1U;
            break;
        default:
            /* Do nothing */
            break;
        }

        TSB_DMAC->C1CONFIGURATION = tmp;
    }
}

/** @} */
/* End of group DMAC_Exported_Functions */

/** @} */
/* End of group DMAC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM360_DMAC_H) || defined(__TMPM361_DMAC_H) || \*/
                                /* defined(__TMPM362_DMAC_H) || defined(__TMPM363_DMAC_H) || \*/
                                /* defined(__TMPM364_DMAC_H) */
