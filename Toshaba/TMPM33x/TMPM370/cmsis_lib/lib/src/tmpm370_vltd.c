/**
 *******************************************************************************
 * @file    tmpm370_vltd.c
 * @brief   This file provides API functions for VLTD driver. 
 * @version V2.2.0
 * @date    2011/07/11
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
#include "tmpm370_vltd.h"

#if defined(__TMPM370_VLTD_H) || defined(__TMPM372_VLTD_H) || defined(__TMPM373_VLTD_H) || defined(__TMPM374_VLTD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @defgroup VLTD
  * @brief VLTD driver modules
  * @{
  */

/** @defgroup VLTD_Private_Defines
  * @{
  */

#define VLTD_VDLVL_MASK         ((uint32_t)0xFFFFFFF9)

/** @} */
/* End of group VLTD_Private_Defines */

/** @defgroup VLTD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the operation of voltage detection.
  * @param  None
  * @retval None
  */
void VLTD_Enable(void)
{
    TSB_VD_CR_VDEN = 1U;
}

/**
  * @brief  Disable the operation of voltage detection.
  * @param  None
  * @retval None
  */
void VLTD_Disable(void)
{
    TSB_VD_CR_VDEN = 0U;
}

/**
  * @brief  Select for detection voltage.
  * @param  Voltage : detection voltage, which can be:
  *             VLTD_DETECT_VOLTAGE_41, VLTD_DETECT_VOLTAGE_44,
  *             VLTD_DETECT_VOLTAGE_46.
  * @retval None
  */
void VLTD_SetVoltage(uint32_t Voltage)
{
    uint32_t regval = TSB_VD->CR;

    /* Check the parameter */
    assert_param(IS_VLTD_DETECT_VOLTAGE(Voltage));

    regval &= VLTD_VDLVL_MASK;
    regval |= Voltage;
    TSB_VD->CR = regval;
}

/** @} */
/* End of group VLTD_Exported_Functions */
/** @} */
/* End of group VLTD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_VLTD_H) || defined(__TMPM372_VLTD_H) || defined(__TMPM373_VLTD_H) || defined(__TMPM374_VLTD_H) */
