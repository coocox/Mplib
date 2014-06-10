/**
 *******************************************************************************
 * @file    tmpm370_ofd.c
 * @brief   This file provides API functions for OFD driver.
 * @version V2.2.0
 * @date    2011/07/05
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
#include "tmpm370_ofd.h"

#if defined(__TMPM370_OFD_H) || defined(__TMPM372_OFD_H) || defined(__TMPM373_OFD_H) || defined(__TMPM374_OFD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @defgroup OFD
  * @brief OFD driver modules
  * @{
  */

/** @defgroup OFD_Private_Defines
  * @{
  */
#define OFD_REG_WRITE_DISABLE ((uint32_t)0x00000006U)
#define OFD_REG_WRITE_ENABLE  ((uint32_t)0x000000F9U)
#define OFD_DISABLE           ((uint32_t)0x00000000U)
#define OFD_ENABLE            ((uint32_t)0x000000E4U)
/** @} */
/* End of group OFD_Private_Defines */

/** @defgroup OFD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable or disable the writing of OFDCR2/OFDMNPLLON/OFDMXPLLON/OFDMNPLLOFF/OFDMXPLLOFF.
  * @param  NewState: the new state of enable or disable
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void OFD_SetRegWriteMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set OFDCR1<CLKWEN7:0> to enable or disable the writing of 
       OFDCR2/OFDMNPLLON/OFDMXPLLON/OFDMNPLLOFF/OFDMXPLLOFF. */
    if (NewState == ENABLE) {
        TSB_OFD->CR1 = OFD_REG_WRITE_ENABLE;
    } else {
        TSB_OFD->CR1 = OFD_REG_WRITE_DISABLE;
    }
}

/**
  * @brief  Enable the OFD function.
  * @param  None
  * @retval None
  */
void OFD_Enable(void)
{
    /* OFDCR2<CLKSEN7:0> = 0xE4 */
    TSB_OFD->CR2 = OFD_ENABLE;
}

/**
  * @brief  Disable the OFD function.
  * @param  None
  * @retval None
  */
void OFD_Disable(void)
{
    /* OFDCR2<CLKSEN7:0> = 0x00 */
    TSB_OFD->CR2 = OFD_DISABLE;
}

/**
  * @brief  Set the count value of detection frequency.
  * @param  State: State of PLL.
  *             This parameter can be one of the following values:
  *             OFD_PLL_ON or OFD_PLL_OFF
  *         HigherDetectionCount: the count value of higher detection frequency.
  *         LowerDetectionCount: the count value of lower detection frequency.
  * @retval None
  */
void OFD_SetDetectionFrequency(OFD_PLL_State State, uint32_t HigherDetectionCount,
                               uint32_t LowerDetectionCount)
{
    assert_param(IS_OFD_PLL_State(State));
    assert_param(IS_OFD_DETECT_FREQ_HIGHER(HigherDetectionCount));
    assert_param(IS_OFD_DETECT_FREQ_LOWER(LowerDetectionCount));
    /* Set the OFDMNPLLON<OFDMNPLLON8:0> and  OFDMXPLLON<OFDMXPLLON8:0> bits or 
       the OFDMNPLLOFF<OFDMNPLLOFF8:0> and  OFDMXPLLOFF<OFDMXPLLOFF8:0> bits */

    if (State == OFD_PLL_ON) {
        TSB_OFD->MNPLLON = LowerDetectionCount;
        TSB_OFD->MXPLLON = HigherDetectionCount;
    } else {
        TSB_OFD->MNPLLOFF = LowerDetectionCount;
        TSB_OFD->MXPLLOFF = HigherDetectionCount;
    }
}


/** @} */
/* End of group OFD_Exported_Functions */
/** @} */
/* End of group OFD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_OFD_H) || defined(__TMPM372_OFD_H) || defined(__TMPM373_OFD_H) || defined(__TMPM374_OFD_H) */
