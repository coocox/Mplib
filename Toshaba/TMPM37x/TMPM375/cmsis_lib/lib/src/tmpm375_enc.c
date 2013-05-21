/**
 *******************************************************************************
 * @file    tmpm375_enc.c
 * @brief   This file provides API functions for ENC driver.
 * @version V2.0.2.1
 * @date    2013/02/04
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm375_enc.h"

#if defined(__TMPM375_ENC_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup ENC
  * @brief ENC driver modules
  * @{
  */

/** @defgroup Encoder_Private_Defines
  * @{
  */

#define ENTNCR_ENRUN_SET               ((uint32_t)0x00000040)
#define ENTNCR_ENCLR_SET               ((uint32_t)0x00000400)
#define ENTNCR_SFTCAP_SET              ((uint32_t)0x00000800)
#define ENTNCR_UD_MASK                 ((uint32_t)0x00002000)
#define ENTNCR_CMP_MASK                ((uint32_t)0x00008000)
#define ENTNCR_REVERR_MASK             ((uint32_t)0x00004000)
#define ENTNCR_ZDET_MASK               ((uint32_t)0x00001000)

/** @} */
/* End of group ENC_Private_Defines */


/** @defgroup ENC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group ENC_Private_FunctionPrototypes */

/** @defgroup ENC_Private_Functions
  * @{
  */

/** @} */
/* End of group group ENC_Private_Functions */

/** @defgroup ENC_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the specified encoder operation.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval None.
  */
void ENC_Enable(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    tmp = ENx->TNCR;
    /* Set ENTNCR <ENRUN> to enable encoder operation. */
    tmp |= ENTNCR_ENRUN_SET;
    ENx->TNCR = tmp;
}

/**
  * @brief  Disable the specified encoder operation.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval None.
  */
void ENC_Disable(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Clear ENTNCR<ENRUN> to disable encoder operation. */
    tmp = ENx->TNCR;
    tmp &= ~ENTNCR_ENRUN_SET;
    ENx->TNCR = tmp;
}

/**
  * @ brief  Initialize the specified encoder channel.
  * @ param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @ param  InitStruct: The structure containing basic encoder configuration.
  * @ retval None.
  */
void ENC_Init(TSB_EN_TypeDef * ENx, ENC_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_MODE(InitStruct->ModeType));
    assert_param(IS_ENC_CMPEN_STATUS(InitStruct->CompareStatus));
    assert_param(IS_ENC_FILTERVALUE(InitStruct->FilterValue));
    assert_param(IS_ENC_DIV_FACTOR(InitStruct->PulseDivFactor));
    assert_param(IS_ENC_INT_STATUS(InitStruct->IntEn));
    /* Configure the encoder mode select  */
    if ((InitStruct->ModeType == ENC_ENCODER_MODE) || (InitStruct->ModeType == ENC_TIMER_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_ZPHASE_STATUS(InitStruct->ZphaseStatus));
        /*  Enable or disable z-phase detected */
        tmp = (InitStruct->ModeType << 17U) | (InitStruct->ZphaseStatus << 7U);
    } else {
        /* Check the parameters */
        assert_param(IS_ENC_PHASE(InitStruct->PhaseType));
        /* 2-phase / 3-phase input selection */
        tmp = (InitStruct->ModeType << 17U) | (InitStruct->PhaseType << 16U);
    }
    if (InitStruct->ModeType == ENC_TIMER_MODE) {
        /* Check the parameters */
        assert_param(IS_ENC_EDGE(InitStruct->EdgeType));
        /* Edge selection of ENCZ  */
        tmp |= (InitStruct->EdgeType << 9U);
    } else {
        /* Do nothing  */
    }
    /* Configure the encoder input control register */
    tmp |=
        (InitStruct->PulseDivFactor) | (InitStruct->FilterValue << 4U) | (InitStruct->
                                                                          CompareStatus << 8U) |
        (InitStruct->IntEn << 3U);
    ENx->TNCR = tmp;
}

/**
  * @brief  Set the specified encoder to executes software capture (timer mode/sensor mode (at timer count))
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @param  ENC_Mode: Select the encoder operation mode.
  *   This parameter can be one of the following values:
  *   ENC_TIMER_MODE, ENC_SENSOR_TIME_MODE
  * @retval None
  */
void ENC_SetSWCapture(TSB_EN_TypeDef * ENx, uint32_t ENC_Mode)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_SW_MODE(ENC_Mode));
    /* Set the specified encoder to executes software capture */
    tmp = ENx->TNCR;
    tmp |= ENTNCR_SFTCAP_SET;
    ENx->TNCR = tmp;
}


/**
  * @brief  Clear pulse counter for the specified encoder
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval None
  */
void ENC_ClearCounter(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Clear pulse counter for the specified encoder */
    tmp = ENx->TNCR;
    tmp |= ENTNCR_ENCLR_SET;
    ENx->TNCR = tmp;
}

/**
  * @brief  Get the encoder compare flag/reverse error flag/z-detected/rotation direction. 
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval The encoder flag
  *   
  */
ENC_FlagStatus ENC_GetENCFlag(TSB_EN_TypeDef * ENx)
{
    ENC_FlagStatus tmp = { 0U };
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get the encoder flag */
    tmp.All = ENx->TNCR;
    return tmp;

}

/**
  * @brief  Set the encoder counter period
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @param  PeriodValue: Set the encoder counter period
  *   This parameter can be 0x0000 - 0xFFFF.
  * @retval None.
  */
void ENC_SetCounterReload(TSB_EN_TypeDef * ENx, uint32_t PeriodValue)
{
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_16BITVALUE(PeriodValue));
    /* Set the encoder counter period */
    ENx->RELOAD = (uint16_t) PeriodValue;
}

/**
  * @brief  Set the encoder counter compare value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @param  ENC_Mode:Select the encoder operation mode
  *   This parameter can be one of the following values:
  *   ENC_ENCODER_MODE, ENC_SENSOR_EVENT_MODE
  *   ENC_SENSOR_TIME_MODE, ENC_TIMER_MODE.
  * @param  CompareValue:Set the encoder counter compare value
  *   In sensor mode ((event count)) and encoder mode:,
  *   This parameter can be 0x0000 - 0xFFFF.
  *   In sensor mode (timer count) and timer mode,
  *   This parameter can be 0x000000 - 0xFFFFFF.            
  * @retval None.
  */
void ENC_SetCompareValue(TSB_EN_TypeDef * ENx, uint32_t ENC_Mode, uint32_t CompareValue)
{
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_MODE(ENC_Mode));
    /* Set the encoder counter compare value */
    if ((ENC_Mode == ENC_SENSOR_TIME_MODE) || (ENC_Mode == ENC_TIMER_MODE)) {
        assert_param(IS_ENC_24BITVALUE(CompareValue));
        ENx->INT = CompareValue;
    } else {
        assert_param(IS_ENC_16BITVALUE(CompareValue));
        ENx->INT = (uint16_t) CompareValue;
    }
}

/**
  * @brief  Get the encoder counter compare value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval Compare value of the encoder.
  */
uint32_t ENC_GetCompareValue(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Set the encoder counter compare value */
    retval = ENx->INT;
    return retval;
}

/**
  * @brief  Get the encoder counter/capture value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0.
  * @retval Value of the encoder counter.
  */
uint32_t ENC_GetCounterValue(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get and return the encoder counter/capture value */
    retval = ENx->CNT;
    return retval;
}

/** @} */
/* End of group ENC_Exported_Functions */

/** @} */
/* End of group ENC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM375_ENC_H) */
