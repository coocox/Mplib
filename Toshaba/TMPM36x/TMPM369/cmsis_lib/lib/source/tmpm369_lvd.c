/**
 *******************************************************************************
 * @file    tmpm369_lvd.c
 * @brief   This file provides API functions for LVD driver. 
 * @version V2.0.2.1
 * @date    2011/08/09
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
#include "tmpm369_lvd.h"

#if defined(__TMPM369_LVD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @defgroup LVD
  * @brief LVD driver modules
  * @{
  */

/** @defgroup LVD_Private_Defines
  * @{
  */

#define LVD_VD1LVL_CLEAR        ((uint32_t)0xFFFFFFF1)
#define LVD_VD2LVL_CLEAR        ((uint32_t)0xFFFFFFF1)
#define LVD_VD1ST_MASK          ((uint32_t)0x00000001)
#define LVD_VD2ST_MASK          ((uint32_t)0x00000002)
#define LVD_RSTEN_SET           ((uint32_t)0x00000020)
#define LVD_RSTEN_CLEAR         ((uint32_t)0xFFFFFFDF)
#define LVD_INTEN_SET           ((uint32_t)0x00000020)
#define LVD_INTEN_CLEAR         ((uint32_t)0xFFFFFFDF)
#define LVD_INTSEL_MASK         ((uint32_t)0xFFFFFFEF)

/** @} */
/* End of group LVD_Private_Defines */

/** @defgroup LVD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the operation of voltage detection 1.
  * @param  None
  * @retval None
  */
void LVD_EnableVD1(void)
{
    TSB_LVD_RCR_LVDEN1 = 1U;
}

/**
  * @brief  Disable the operation of voltage detection 1.
  * @param  None
  * @retval None
  */
void LVD_DisableVD1(void)
{
    TSB_LVD_RCR_LVDEN1 = 0U;
}

/**
  * @brief  Select detection voltage 1 level.
  * @param  VDLevel : voltage detection 1 level, which can be:
  *             LVD_VDLVL1_240, LVD_VDLVL1_250, LVD_VDLVL1_260,
  *             LVD_VDLVL1_270, LVD_VDLVL1_280, LVD_VDLVL1_290.
  * @retval None
  */
void LVD_SetVD1Level(uint32_t VDLevel)
{
    uint32_t regval = TSB_LVD->RCR;

    /* Check the parameter */
    assert_param(IS_LVD_VD1_LEVEL(VDLevel));

    regval &= LVD_VD1LVL_CLEAR;
    regval |= VDLevel;
    TSB_LVD->RCR = regval;
}

/**
  * @brief  Get voltage detection 1 interrupt status.
  * @param  None
  * @retval LVD_VD_UPPER, LVD_VD_LOWER.
  */
LVD_VDStatus LVD_GetVD1Status(void)
{
    LVD_VDStatus result = LVD_VD_UPPER;
    uint32_t regval = TSB_LVD->SR;
    regval &= LVD_VD1ST_MASK;

    if (regval) {
        result = LVD_VD_LOWER;
    } else {
        /* do nothing */
    }
    return result;
}

/**
  * @brief  Enable the operation of voltage detection 2.
  * @param  None
  * @retval None
  */
void LVD_EnableVD2(void)
{
    TSB_LVD_ICR_LVDEN2 = 1U;
}

/**
  * @brief  Disable the operation of voltage detection 2.
  * @param  None
  * @retval None
  */
void LVD_DisableVD2(void)
{
    TSB_LVD_ICR_LVDEN2 = 0U;
}

/**
  * @brief  Select detection voltage 2 level.
  * @param  VDLevel : voltage detection 2 level, which can be:
  *             LVD_VDLVL2_280, LVD_VDLVL2_285, LVD_VDLVL2_290,
  *             LVD_VDLVL2_295, LVD_VDLVL2_300, LVD_VDLVL2_305,
  *             LVD_VDLVL2_310, LVD_VDLVL2_315.
  * @retval None
  */
void LVD_SetVD2Level(uint32_t VDLevel)
{
    uint32_t regval = TSB_LVD->ICR;

    /* Check the parameter */
    assert_param(IS_LVD_VD2_LEVEL(VDLevel));

    regval &= LVD_VD2LVL_CLEAR;
    regval |= VDLevel;
    TSB_LVD->ICR = regval;
}

/**
  * @brief  Get voltage detection 2 interrupt status.
  * @param  None
  * @retval LVD_VD_UPPER, LVD_VD_LOWER.
  */
LVD_VDStatus LVD_GetVD2Status(void)
{
    LVD_VDStatus result = LVD_VD_UPPER;
    uint32_t regval = TSB_LVD->SR;
    regval &= LVD_VD2ST_MASK;

    if (regval) {
        result = LVD_VD_LOWER;
    } else {
        /* do nothing */
    }
    return result;
}

/**
  * @brief  Enable or disable LVD reset output.
  * @param  ENABLE or DISABLE
  * @retval None
  */
void LVD_SetResetOutput(FunctionalState NewState)
{
	  /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    
    if (NewState == ENABLE) {
    	  /* Set LVDRCR<LVDRSTEN> to 1 */
        TSB_LVD->RCR |= LVD_RSTEN_SET;
    } else {
    	  /* Set LVDRCR<LVDRSTEN> to 0 */
        TSB_LVD->RCR &= LVD_RSTEN_CLEAR;
    }
}

/**
  * @brief  Enable or disable LVD interrupt output.
  * @param  ENABLE or DISABLE
  * @retval None
  */
void LVD_SetINTOutput(FunctionalState NewState)
{
	  /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    
    if (NewState == ENABLE) {
    	  /* Set LVDICR<LVDINTEN> to 1 */
        TSB_LVD->ICR |= LVD_INTEN_SET;
    } else {
    	  /* Set LVDICR<LVDINTEN> to 0 */
        TSB_LVD->ICR &= LVD_INTEN_CLEAR;
    }
}

/**
  * @brief  Set voltage detection interrupt generation condition.
  * @param  IntCondition: voltage detection interrupt generation condition.
  *   This parameter can be one of the following values:
  *   LVD_INTSEL_LOWER: Only lower than the setting voltage when voltage decreasing.
  *   LVD_INTSEL_LOWER_UPPER: Both lower and upper than the setting voltage 
  *                           when voltage decreasing.
  * @retval None
  */
void LVD_SetINTCondition(uint32_t IntCondition)
{
	  uint32_t tmp = 0U;
	  /* Check the parameters */
    assert_param(IS_LVD_INT_CONDITION(IntCondition));
    
    tmp = TSB_LVD->ICR & LVD_INTSEL_MASK;
    tmp |= IntCondition;
    TSB_LVD->ICR =tmp;
}

/** @} */
/* End of group LVD_Exported_Functions */
/** @} */
/* End of group LVD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM369_LVD_H) */
