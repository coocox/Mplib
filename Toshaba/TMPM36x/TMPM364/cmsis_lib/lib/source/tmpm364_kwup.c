/**
 *******************************************************************************
 * @file    tmpm364_kwup.c
 * @brief   This file provides API functions for KWUP driver.
 * @version V2.2.0
 * @date    2010/07/22
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
#include "tmpm364_kwup.h"

#if defined(__TMPM360_KWUP_H) || defined(__TMPM361_KWUP_H) || defined(__TMPM362_KWUP_H) ||  \
    defined(__TMPM363_KWUP_H) || defined(__TMPM364_KWUP_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup KWUP 
  * @brief KWUP driver modules
  * @{
  */

/** @defgroup KWUP_Private_Defines
  * @{
  */
#define KWUP_CRn_MASK           ((uint32_t)0xFFFFFF0E)
#define KWUP_PKEY_MASK          ((uint32_t)0xFFFFFFF0)
#define KWUP_INT_MASK           ((uint32_t)0xFFFFFFF0)
#define KWUP_PULL_UP_CYCLE_MASK ((uint32_t)0xFFFFFFC3)

#define KWUP_INT_CLEAR_CODE     ((uint32_t)0x0000000A)

/** @} */
/* End of group KWUP_Private_Defines */

/** @defgroup KWUP_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group KWUP_Private_FunctionPrototypes */

/** @defgroup KWUP_Private_Functions
  * @{
  */

/** @} */
/* End of group KWUP_Private_Functions */

/** @defgroup KWUP_Exported_Functions
  * @{
  */

/**
  * @brief  configure the key wake-up settings.
  * @param  Settings: the pointer to the structure containing the key wake-up settings.
  *         Settings->KeyN : key input select.
  *         Settings->PullUpCtrl: selected static pull-up or dynamic pull-up
  *         Settings->ActiveState: active status setting
  *         Settings->INTNewState: disable /enable KWUP interrupt input 
  * @retval None.
  */
void KWUP_SetConfig(KWUP_SettingTypeDef * Settings)
{
    uint32_t tmp = 0U;
    uint32_t regval = 0U;
    assert_param(IS_POINTER_NOT_NULL(Settings));
    assert_param(IS_KWUP_INPUT(Settings->KeyN));
    assert_param(IS_KWUP_PULL_UP_CTRL(Settings->PullUpCtrl));
    assert_param(IS_KWUP_ACTIVE_STATE(Settings->ActiveState));
    assert_param(IS_FUNCTIONAL_STATE(Settings->INTNewState));

    tmp = (uint32_t) Settings->INTNewState;
    tmp |= ((uint32_t) Settings->ActiveState) << 4U;
    tmp |= ((uint32_t) Settings->PullUpCtrl) << 7U;

    switch (Settings->KeyN) {
    case KWUP_INPUT_0:
        TSB_KWUP_CR0_KEY0EN = 0U;
        regval = TSB_KWUP->CR0 & KWUP_CRn_MASK;
        regval |= tmp;
        TSB_KWUP->CR0 = regval;
        break;
    case KWUP_INPUT_1:
        TSB_KWUP_CR1_KEY1EN = 0U;
        regval = TSB_KWUP->CR1 & KWUP_CRn_MASK;
        regval |= tmp;
        TSB_KWUP->CR1 = regval;
        break;
    case KWUP_INPUT_2:
        TSB_KWUP_CR2_KEY2EN = 0U;
        regval = TSB_KWUP->CR2 & KWUP_CRn_MASK;
        regval |= tmp;
        TSB_KWUP->CR2 = regval;
        break;
    case KWUP_INPUT_3:
        TSB_KWUP_CR3_KEY3EN = 0U;
        regval = TSB_KWUP->CR3 & KWUP_CRn_MASK;
        regval |= tmp;
        TSB_KWUP->CR3 = regval;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  get port status sampled in dynamic pull-up period.
  * @param  None 
  * @retval port status.
  */
KWUP_PortStatus KWUP_GetPortStatus(void)
{
    KWUP_PortStatus state = { 0U };
    state.All = TSB_KWUP->PKEY & (~KWUP_PKEY_MASK);
    return state;
}

/**
  * @brief  Set Dynamic pull-up cycle and Dynamic pull-up period.
  * @param  T1: activating period when using dynamic pull-up.
  *             This parameter can be one of the following values:
  *             KWUP_CYCLES_2_FS, KWUP_CYCLES_4_FS, KWUP_CYCLES_8_FS, 
  *             KWUP_CYCLES_16_FS,
  * @param  T2: repeated dynamic pull-up operation cycles.
  *             This parameter can be one of the following values:
  *             KWUP_CYCLES_256_FS, KWUP_CYCLES_512_FS,
  *             KWUP_CYCLES_1024_FS, KWUP_CYCLES_2048_FS
  * @retval None.
  */
void KWUP_SetPullUpConfig(KWUP_PullUpCycles T1, KWUP_PullUpCycles T2)
{
    uint32_t tmp = 0U;
    uint32_t t1 = 0U;
    uint32_t t2 = 0U;
    assert_param(IS_KWUP_PULL_UP_CYCLES_T1(T1));
    assert_param(IS_KWUP_PULL_UP_CYCLES_T2(T2));

    tmp = TSB_KWUP->CNT & KWUP_PULL_UP_CYCLE_MASK;
    t1 = (uint32_t) T1 << 2;
    t2 = ((uint32_t) T2 - (uint32_t) KWUP_CYCLES_256_FS) << 4;
    tmp |= t1;
    tmp |= t2;
    TSB_KWUP->CNT = tmp;
}

/**
  * @brief  clear all key interrupt request 
  * @param  None 
  * @retval None
  */
void KWUP_ClearINTReq(void)
{
    TSB_KWUP->CLR = KWUP_INT_CLEAR_CODE;
}

/**
  * @brief  get key interrupt status 
  * @param  None 
  * @retval key interrupt status.
  */
KWUP_INTStatus KWUP_GetINTStatus(void)
{
    KWUP_INTStatus state = { 0U };
    state.All = TSB_KWUP->INT & (~KWUP_INT_MASK);
    return state;
}

/** @} */
/* End of group KWUP_Exported_Functions */

/** @} */
/* End of group KWUP */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM360_KWUP_H) || defined(__TMPM361_KWUP_H) || \ */
                                /* defined(__TMPM362_KWUP_H) || defined(__TMPM363_KWUP_H) || \ */
                                /* defined(__TMPM364_KWUP_H) */
