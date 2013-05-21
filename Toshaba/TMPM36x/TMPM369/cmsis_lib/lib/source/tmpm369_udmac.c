/**
 *******************************************************************************
 * @file    tmpm369_udmac.c
 * @brief   This file provides API functions for uDMAC driver.
 * @version V2.0.2.1
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


/* Includes ------------------------------------------------------------------*/
#include "tmpm369_udmac.h"

#if defined(__TMPM369_uDMAC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup uDMAC
  * @brief uDMAC driver modules
  * @{
  */

/** @defgroup uDMAC_Private_Defines
  * @{
  */


/** @} */
/* End of group uDMAC_Private_Defines */

/** @defgroup uDMAC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group uDMAC_Private_FunctionPrototypes */

/** @defgroup uDMAC_Private_Functions
  * @{
  */

/** @} */
/* End of group uDMAC_Private_Functions */

/** @defgroup uDMAC_Exported_Functions
  * @{
  */

/**
  * @brief  Get the state of specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @retval The state of DMAC operation.
  *          It can be one of the following values:
  *            DISABLE :  The DMAC unit is disabled.
  *            ENABLE  :  The DMAC unit is enabled.
  */
FunctionalState DMAC_GetDMACState(TSB_DMA_TypeDef * DMACx)
{
    FunctionalState state = DISABLE;

    assert_param(IS_DMAC_UNIT(DMACx));

    /* read DMACx->STATUS.b0, 0 is disable, 1 is enable */
    if (DMACx->STATUS & (uint32_t) 0x01U) {
        state = ENABLE;
    } else {
        /* do nothing */
    }

    return state;
}


/**
  * @brief  Enable the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @retval None
  */
void DMAC_Enable(TSB_DMA_TypeDef * DMACx)
{
    assert_param(IS_DMAC_UNIT(DMACx));

    /* set DMACx->CFG.b0 */
    DMACx->CFG = (uint32_t) 0x01U;
}


/**
  * @brief  Disable the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @retval None
  */
void DMAC_Disable(TSB_DMA_TypeDef * DMACx)
{
    assert_param(IS_DMAC_UNIT(DMACx));

    /* clr DMACx->CFG.b0 */
    DMACx->CFG = (uint32_t) 0x00U;
}



/** 
  * @brief  Set the base address of the primary data of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Addr: The base address of the primary data, bit0 to bit9 must be 0.
  * @retval None
  */
void DMAC_SetPrimaryBaseAddr(TSB_DMA_TypeDef * DMACx, uint32_t Addr)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CTRL_BASE(Addr));

    DMACx->CTRLBASEPTR = Addr;
}


/**
  * @brief  Get the primary/alternative base address of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  PriAlt: Select base address type.
  *          This parameter can be one of the following values:
  *            DMAC_PRIMARY :  Get primary base address
  *            DMAC_ALTERNATE:  Get alternative base address
  * @retval The base address of primary/alternative data.
  */
uint32_t DMAC_GetBaseAddr(TSB_DMA_TypeDef * DMACx, DMAC_PrimaryAlt PriAlt)
{
    uint32_t tmp = 0U;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_PRIMARYALT(PriAlt));

    if (PriAlt == DMAC_PRIMARY) {
        tmp = DMACx->CTRLBASEPTR;
    } else {
        tmp = DMACx->ALTCTRLBASEPTR;
    }

    return tmp;
}

/**
  * @brief  Set software transfer request to the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval None.
  */
void DMAC_SetSWReq(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    /* write '1' to right bit position to requests a transfer */
    DMACx->CHNLSWREQUEST = (uint32_t)(0x01U << (uint32_t)Channel);

}


/**
  * @brief  Set transfer type to the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *           when Type == DMAC_BURST:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  *
  *           when Type == DMAC_SINGLE:
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX
  *
  * @param  Type: Select transfer type
  *          This parameter can be one of the following values:
  *             DMAC_BURST:  Single transfer is disabled, only burst transfer request can be used.
  *             DMAC_SINGLE: Single transfer is enabled.
  * @retval None.
  */
void DMAC_SetTransferType(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, DMAC_TransferType Type)
{
    uint32_t tmp = 0U;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_TRANSFERTYPE(Type));

    if (Type == DMAC_BURST) {
        assert_param(IS_DMAC_CHANNEL_BURST(Channel));
        /* Write '1' to _SET to disables the single transfer to the channel, and only burst transfer request is valid */
        tmp = DMACx->CHNLUSEBURSTSET;
        tmp |= (uint32_t)(0x01U << (uint32_t)Channel);
        DMACx->CHNLUSEBURSTSET = tmp;
    } else {
        assert_param(IS_DMAC_CHANNEL_SINGLE(Channel));
        /* Write "1" to _CLR to enables the single transfer to the corresponding channel */
        /* this SFR is write only */
        DMACx->CHNLUSEBURSTCLR = (uint32_t)(0x01U << (uint32_t)Channel);
    }
}

/**
  * @brief  Get transfer type setting for the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval The transfer type.
  *             DMAC_BURST:  Only burst transfer request can be used.
  *             DMAC_SINGLE: Single transfer is enabled.
  */
DMAC_TransferType DMAC_GetTransferType(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    uint32_t tmp = 0U;
    DMAC_TransferType Type = DMAC_SINGLE;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    tmp = DMACx->CHNLUSEBURSTSET & (uint32_t)(0x01U << (uint32_t)Channel);
    if (tmp) {
        /* read _SET, if bit is not 0, Only burst transfer request can be used */
        Type = DMAC_BURST;
    } else {
        Type = DMAC_SINGLE;
    }

    return Type;
}


/**
  * @brief  Set mask for the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @param  NewState: Clear or set the mask to enable or disable the DMA channel
  *          This parameter can be one of the following values:
  *             ENABLE : The DMA channel mask is cleared, DMA request is enable(valid)
  *             DISABLE :  The DMA channel is masked, DMA request is disable(invalid)
  * @retval None
  */
void DMAC_SetMask(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, FunctionalState NewState)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* ENABLE: clear mask to enable DMA channel,(valid). write '1' to _CLR */
        DMACx->CHNLREQMASKCLR = (uint32_t)(0x01U << (uint32_t)Channel);
    } else {
        /* DISABLE: set mask to disable DMA channel, (invalid), write '1' to _SET */
        DMACx->CHNLREQMASKSET = (uint32_t)(0x01U << (uint32_t)Channel);
    }

}


/**
  * @brief  Get mask setting for the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval The inverted mask setting.
  *             ENABLE : The DMA channel mask is cleared, DMA request is enable(valid)
  *             DISABLE :  The DMA channel is masked, DMA request is disable(invalid)
  */
FunctionalState DMAC_GetMask(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    uint32_t tmp = 0U;
    FunctionalState state = DISABLE;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    /* read _SET, mask with '1 << Channel' */
    tmp = DMACx->CHNLREQMASKSET & (uint32_t)(0x01U << (uint32_t)Channel);
    if (tmp) {                  /* if result is not 0, return DISABLE */
        state = DISABLE;
    } else {                    /* if result is 0, return ENABLE */
        state = ENABLE;
    }

    return state;
}

/**
  * @brief  Enable or disable the specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @param  NewState: Enable or disable the DMA channel
  *          This parameter can be one of the following values:
  *             ENABLE : The DMA channel will be enabled
  *             DISABLE :  The DMA channel will be disabled
  * @retval None
  */
void DMAC_SetChannel(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, FunctionalState NewState)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* ENABLE: write '1' to _SET */
        DMACx->CHNLENABLESET = (uint32_t)(0x01U << (uint32_t)Channel);
    } else {
        /* DISABLE: write '1' to _CLR */
        DMACx->CHNLENABLECLR = (uint32_t)(0x01U << (uint32_t)Channel);
    }
}


/**
  * @brief  Get the enable/disable setting for specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval  The enable/disable setting for channel
  *             ENABLE : The DMA channel is enabled
  *             DISABLE :  The DMA channel is disabled  
  */
FunctionalState DMAC_GetChannelState(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    uint32_t tmp = 0U;
    FunctionalState state = DISABLE;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    /* read _SET, mask with '1 << Channel' */
    tmp = DMACx->CHNLENABLESET & (uint32_t)(0x01U << (uint32_t)Channel);
    if (tmp) {                  /* if result is not 0, return DISABLE */
        state = DISABLE;
    } else {                    /* if result is 0, return ENABLE */
        state = ENABLE;
    }

    return state;
}


/**
  * @brief  Set to use primary data or alternative data for specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @param  PriAlt: Select primary data or alternative data for channel specified by 'Channel' above
  *          This parameter can be one of the following values:
  *             DMAC_PRIMARY :  Channel will use primary data
  *             DMAC_ALTERNATE : Channel will use alternative data
  * @retval None
  */
void DMAC_SetPrimaryAlt(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, DMAC_PrimaryAlt PriAlt)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));
    assert_param(IS_DMAC_PRIMARYALT(PriAlt));

    if (PriAlt == DMAC_PRIMARY) {
        /* PRIMARY: write '1' to _CLR */
        DMACx->CHNLPRIALTCLR = (uint32_t)(0x01U << (uint32_t)Channel);
    } else {
        /* ALTERNATE: write '1' to _SET */
        DMACx->CHNLPRIALTSET = (uint32_t)(0x01U << (uint32_t)Channel);
    }

}


/**
  * @brief  Get the setting of the using of primary data or alternative data for specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval The setting of the using of primary data or alternative data
  *             DMAC_PRIMARY :  Channel is using primary data 
  *             DMAC_ALTERNATE : Channel is using alternative data
  */
DMAC_PrimaryAlt DMAC_GetPrimaryAlt(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    uint32_t tmp = 0U;
    DMAC_PrimaryAlt PriAlt = DMAC_PRIMARY;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    /* read _SET, mask with '1 << Channel' */
    tmp = DMACx->CHNLPRIALTSET & (uint32_t)(0x01U << (uint32_t)Channel);
    if (tmp) {                  /* if result is not 0, return _ALTERNATE */
        PriAlt = DMAC_ALTERNATE;
    } else {                    /* if result is 0, return _PRIMARY */
        PriAlt = DMAC_PRIMARY;
    }

    return PriAlt;
}


/**
  * @brief  Set the priority for specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @param  Priority: Select Priority.
  *          This parameter can be one of the following values:
  *             DMAC_PRIOTIRY_NORMAL : Normal priority
  *             DMAC_PRIOTIRY_HIGH   : High priority
  * @retval None
  */
void DMAC_SetChannelPriority(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, DMAC_Priority Priority)
{
    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));
    assert_param(IS_DMAC_PRIORITY(Priority));

    if (Priority == DMAC_PRIOTIRY_NORMAL) {
        /* DMAC_PRIOTIRY_NORMAL: write '1' to _CLR */
        DMACx->CHNLPRIORITYCLR = (uint32_t)(0x01U << (uint32_t)Channel);
    } else {
        /* DMAC_PRIOTIRY_HIGH: write '1' to _SET */
        DMACx->CHNLPRIORITYSET = (uint32_t)(0x01U << (uint32_t)Channel);
    }

}


/**
  * @brief  Get the priority setting for specified channel of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @retval  The priority setting of channel
  *             DMAC_PRIOTIRY_NORMAL : Normal priority
  *             DMAC_PRIOTIRY_HIGH   : High priority
  */
DMAC_Priority DMAC_GetChannelPriority(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel)
{
    uint32_t tmp = 0U;
    DMAC_Priority Priority = DMAC_PRIOTIRY_NORMAL;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    /* read _SET, mask with '1 << Channel' */
    tmp = DMACx->CHNLPRIORITYSET & (uint32_t)(0x01U << (uint32_t)Channel);
    if (tmp) {                  /* if result is not 0, return _PRIOTIRY_HIGH */
        Priority = DMAC_PRIOTIRY_HIGH;
    } else {                    /* if result is 0, return _PRIOTIRY_NORMAL */
        Priority = DMAC_PRIOTIRY_NORMAL;
    }

    return Priority;
}


/**
  * @brief  Clear the bus error of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @retval None
  */
void DMAC_ClearBusErr(TSB_DMA_TypeDef * DMACx)
{
    assert_param(IS_DMAC_UNIT(DMACx));

    /* write '1' to bit0 */
    DMACx->ERRCLR = (uint32_t) 0x01U;
}

/**
  * @brief  Get the bus error state of the specified DMAC unit.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @retval The bus error state
  *            SUCCESS :  No bus error
  *            ERROR   :  There is error in bus
  */
Result DMAC_GetBusErrState(TSB_DMA_TypeDef * DMACx)
{
    Result tmp = SUCCESS;

    assert_param(IS_DMAC_UNIT(DMACx));
    /* read bit0, '0' is no error, '1' is error */
    if (DMACx->ERRCLR & (uint32_t) 0x01U) {
        tmp = ERROR;
    } else {
        /* Do nothing */
    }
    return tmp;
}



/**
  * @brief  Fill the DMA setting data of specified channel of the specified DMAC unit to RAM.
  * @param  DMACx: Select DMAC unit.
  *          This parameter can be one of the following values:
  *            DMAC_UNIT_A :  DMAC unit A
  *            DMAC_UNIT_B :  DMAC unit B
  * @param  Channel: Select channel.
  *          This parameter can be one of the following values:
  *             DMAC_ADC0_END,
  *             DMAC_ADC1_END,
  *             DMAC_DAC0_TRG,
  *             DMAC_DAC1_TRG,
  *             DMAC_SSP0_RX,
  *             DMAC_SSP0_TX,
  *             DMAC_SSP1_RX,
  *             DMAC_SSP1_TX,
  *             DMAC_SSP2_RX,
  *             DMAC_SSP2_TX,
  *             DMAC_FUART4_RX,
  *             DMAC_FUART4_TX,
  *             DMAC_FUART5_RX,
  *             DMAC_FUART5_TX,
  *             DMAC_SIO0_RX,
  *             DMAC_SIO0_TX,
  *             DMAC_SIO1_RX,
  *             DMAC_SIO1_TX,
  *             DMAC_SIO2_RX,
  *             DMAC_SIO2_TX,
  *             DMAC_SIO3_RX,
  *             DMAC_SIO3_TX,
  *             DMAC_SBI0_RXTX,
  *             DMAC_SBI1_RXTX,
  *             DMAC_SBI2_RXTX,
  *             DMAC_TMRB0_CMP_MATCH,
  *             DMAC_TMRB1_CMP_MATCH,
  *             DMAC_TMRB2_CMP_MATCH,
  *             DMAC_TMRB3_CMP_MATCH,
  *             DMAC_TMRB4_CMP_MATCH,
  *             DMAC_PIN,
  *             DMAC_SW_TRG
  * @param  InitStruct: the structure contain the DMA setting values.
  * @retval None
  */
void DMAC_FillInitData(TSB_DMA_TypeDef * DMACx, DMAC_Channel Channel, DMAC_InitTypeDef * InitStruct)
{
    DMAC_PrimaryAlt PriAlt = DMAC_PRIMARY;
    uint32_t Addr = 0U;
    uint32_t tmpCtrl = 0U;

    assert_param(IS_DMAC_UNIT(DMACx));
    assert_param(IS_DMAC_CHANNEL_ALL(Channel));

    assert_param(IS_POINTER_NOT_NULL(InitStruct));

    assert_param(IS_DMAC_CYCLECTRL(InitStruct->Mode));
    assert_param(IS_DMAC_NEXT_USEBURST(InitStruct->NextUseBurst));
    assert_param(IS_DMAC_TXNUM(InitStruct->TxNum));
    assert_param(IS_DMAC_ARBITRATION(InitStruct->ArbitrationMoment));
    assert_param(IS_DMAC_BIT_WIDTH(InitStruct->SrcWidth));
    assert_param(IS_DMAC_INCWIDTH(InitStruct->SrcInc));
    assert_param(IS_DMAC_BIT_WIDTH(InitStruct->DstWidth));
    assert_param(IS_DMAC_INCWIDTH(InitStruct->DstInc));

    assert_param(IS_DMAC_INCWIDTH_VALID
                 ((uint32_t) InitStruct->SrcWidth, (uint32_t) InitStruct->SrcInc));
    assert_param(IS_DMAC_INCWIDTH_VALID
                 ((uint32_t) InitStruct->DstWidth, (uint32_t) InitStruct->DstInc));


    PriAlt = DMAC_GetPrimaryAlt(DMACx, Channel);

    if (PriAlt == DMAC_PRIMARY) {
        Addr = DMAC_GetBaseAddr(DMACx, DMAC_PRIMARY);
    } else {
        Addr = DMAC_GetBaseAddr(DMACx, DMAC_ALTERNATE);
    }

    /* add offset for channel, each channel use (4 x uint32_t) RAM */
    Addr += (16U * (uint32_t) Channel);

    /* make setting data for 'control data' */
    tmpCtrl |= (uint32_t) InitStruct->Mode;
    tmpCtrl |= (uint32_t) InitStruct->NextUseBurst << 3U;
    tmpCtrl |= (uint32_t) (InitStruct->TxNum - 1U) << 4U;
    tmpCtrl |= (uint32_t) InitStruct->ArbitrationMoment << 14U;
    tmpCtrl |= (uint32_t) InitStruct->SrcWidth << 24U;
    tmpCtrl |= (uint32_t) InitStruct->SrcInc << 26U;
    tmpCtrl |= (uint32_t) InitStruct->DstWidth << 28U;
    tmpCtrl |= (uint32_t) InitStruct->DstInc << 30U;

    /* write setting data to right address */
    *((uint32_t *) (Addr)) = InitStruct->SrcEndPointer;
    *((uint32_t *) (Addr + 4U)) = InitStruct->DstEndPointer;
    *((uint32_t *) (Addr + 8U)) = tmpCtrl;
    *((uint32_t *) (Addr + 12U)) = (uint32_t) 0U;

}



/** @} */
/* End of group uDMAC_Exported_Functions */

/** @} */
/* End of group uDMAC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM369_uDMAC_H) */
