/**
 *******************************************************************************
 * @file    tmpm061_lvd.c
 * @brief   This file provides API functions for LVD driver. 
 * @version V2.0.2.1
 * @date    2013/03/21
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
#include "tmpm061_lvd.h"

#if defined(__TMPM061_LVD_H)
/** @addtogroup TX00_Periph_Driver
  * @{
  */
/** @defgroup LVD
  * @brief LVD driver modules
  * @{
  */

/** @defgroup LVD_Private_Defines
  * @{
  */
#define LVD_MASK_KEEP1BIT       (uint32_t)0x01U
#define LVD_MASK_KEEP2BITS      (uint32_t)0x03U
#define LVD_MASK_KEEP3BITS      (uint32_t)0x07U
#define LVD_MASK_KEEP4BITS      (uint32_t)0x0FU
#define LVD_MASK_KEEP5BITS      (uint32_t)0x1FU
#define LVD_MASK_KEEP6BITS      (uint32_t)0x3FU
#define LVD_MASK_KEEP7BITS      (uint32_t)0x7FU
#define LVD_MASK_KEEP8BITS      (uint32_t)0xFFU

/** @} */
/* End of group LVD_Private_Defines */

/** @defgroup LVD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the operation of voltage detection.
  * @param  None
  * @retval None
  */
void LVD_Enable(void)
{
    /* set bit1 */
    uint32_t tmp = TSB_LVD->ICR | 0x01U;
    TSB_LVD->ICR = tmp;
}

/**
  * @brief  Disable the operation of voltage detection.
  * @param  None
  * @retval None
  */
void LVD_Disable(void)
{
    uint32_t tmp = TSB_LVD->ICR & (LVD_MASK_KEEP5BITS << 1U);
    TSB_LVD->ICR = tmp;
}

/**
  * @brief  Set threshold voltage for detection.
  * @param  Voltage :  threshold voltage for detection, which can be:
  *     LVD_DETECT_VOLTAGE_280    : 2.80 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_285    : 2.85 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_290    : 2.90 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_295    : 2.95 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_300    : 3.00 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_305    : 3.05 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_310    : 3.10 +/- 0.2V
  *     LVD_DETECT_VOLTAGE_315    : 3.15 +/- 0.2V
  * @retval None
  */
void LVD_SetVoltage(uint32_t Voltage)
{
    /* read ICR, keep bit5,4,0 and clear bit3,2,1 which are "LVDICR<LVDLVL2[2:0]" */
    uint32_t tmp = TSB_LVD->ICR & ((LVD_MASK_KEEP2BITS << 4U) | LVD_MASK_KEEP1BIT);

    /* Check the parameter */
    assert_param(IS_LVD_DETECT_VOLTAGE(Voltage));

    tmp |= Voltage << 1U;
    TSB_LVD->ICR = tmp;
}


/**
  * @brief  Get current low voltage detection status.
  * @param  None
  * @retval The status of current low voltage detection.
  *     LVD_SUPPLY_HIGH: Power supply voltage is higher than 
  *       the detection voltage specified by function LVD_SetVoltage(), (value is ¡®0¡¯)
  *     LVD_SUPPLY_LOW: Power supply voltage is lower than 
  *       the detection voltage specified by function LVD_SetVoltage(), (value is ¡®1¡¯)
  */
LVD_SupplyStatus LVD_GetStatus(void)
{
    LVD_SupplyStatus retval = LVD_SUPPLY_HIGH;
    uint32_t tmp = TSB_LVD->SR & (LVD_MASK_KEEP1BIT << 1U);     /* read bit1 */

    if (tmp) {
        retval = LVD_SUPPLY_LOW;
    } else {
        /* Do nothing */
    }
    
    return retval;
}


/**
  * @brief  Enable or disable LVD interrupt output when LVD module is enabled.
  * @param  NewState: To enable or disable the output for INTLVD.
  *   This parameter can be one of the following values:
  *     ENABLE , DISABLE.  
  * @retval None
  */
void LVD_SetINTOutput(FunctionalState NewState)
{
    /* keep bit0 to bit4 then clear bit 5 */
    uint32_t tmp = TSB_LVD->ICR & LVD_MASK_KEEP5BITS;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp |= (uint32_t) NewState << 5U;
    TSB_LVD->ICR = tmp;
}


/**
  * @brief  Set the INTLVD generation condition.
  * @param  Condition: Select INTLVD generation condition when supply power is varying.
  *   This parameter can be one of the following values:
  *     LVD_INTSEL_LOWER:  When the supply power is decreasing and lower than setting voltage.  
  *     LVD_INTSEL_LOWER_UPPER: When the supply power is decreasing and lower than setting voltage, or,
  *                 after that, when the supply power is rising and higher than setting voltage.
  * @retval None
  */
void LVD_SetINTCondition(uint32_t Condition)
{
    /* keep bit5 and bit 3 to 0, then clear bit 4 */
    uint32_t tmp = TSB_LVD->ICR & (LVD_MASK_KEEP4BITS | (LVD_MASK_KEEP1BIT << 5U));

    /* Check the parameters */
    assert_param(IS_LVD_INTSEL_LOWER_UPPER(Condition));

    tmp |= (uint32_t) Condition << 4U;
    TSB_LVD->ICR = tmp;
}

/** @} */
/* End of group LVD_Exported_Functions */
/** @} */
/* End of group LVD */
/** @} */
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_LVD_H) */
