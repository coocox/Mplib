/**
 *******************************************************************************
 * @file    tmpm341_ofd.c
 * @brief   This file provides API functions for OFD driver.
 * @version V2.0.2.2
 * @date    2011/03/15
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
#include "tmpm341_ofd.h"

#if defined(__TMPM341_OFD_H)
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
#define OFD_REG_WRITE_DISABLE     ((uint32_t)0x00000006U)
#define OFD_REG_WRITE_ENABLE      ((uint32_t)0x000000F9U)
#define OFD_DISABLE               ((uint32_t)0x00000000U)
#define OFD_ENABLE                ((uint32_t)0x000000E4U)
/** @} */
/* End of group OFD_Private_Defines */

/** @defgroup OFD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable or disable the writing of OFDCR2/OFDMN/OFDMX.
  * @param  NewState: the new state of enable or disable
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void OFD_SetRegWriteMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set OFDCR1<OFDWEN0-7> to enable or disable the writing of OFDCR2/OFDMN/OFDMX. */
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
    /* OFDCR2<OFDEN0-7> = 0xE4 */
    TSB_OFD->CR2 = OFD_ENABLE;
}

/**
  * @brief  Disable the OFD function.
  * @param  None
  * @retval None
  */
void OFD_Disable(void)
{
    /* OFDCR2<OFDEN0-7> = 0x00 */
    TSB_OFD->CR2 = OFD_DISABLE;
}

/**
  * @brief  Set the count value of detection frequency.
  * @param  HigherDetectionCount: the count value of higher detection frequency.
  *         LowerDetectionCount: the count value of lower detection frequency.
  * @retval None
  */
void OFD_SetDetectionFrequency(uint16_t HigherDetectionCount, uint16_t LowerDetectionCount)
{
    /* Set the OFDMN<OFDMN0-8> and  OFDMX<OFDMX0-8> bits */
    TSB_OFD->MN = (uint32_t) LowerDetectionCount;
    TSB_OFD->MX = (uint32_t) HigherDetectionCount;
}

/**
  * @brief  Enable or disable the OFD reset.
  * @param  NewState: the new state of enable or disable
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void OFD_Reset(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set OFDRST<OFDRSTEN> to enable or disable the OFD reset. */
    if (NewState == ENABLE) {
        TSB_OFD_RST_OFDRSTEN = 1U;
    } else {
        TSB_OFD_RST_OFDRSTEN = 0U;
    }
}

/**
  * @brief  Get the OFD busy and frequency error info.
  * @param  None
  * @retval The structure includes the OFD busy and frequency error status.
  */
OFD_Status OFD_GetStatus(void)
{
    OFD_Status status = { 0U };

    /*Read the ofd status from OFDSTAT<OFDBUSY><FRQEER> register. */
    status.All = TSB_OFD->STAT;
    return status;
}

/** @} */
/* End of group OFD_Exported_Functions */
/** @} */
/* End of group OFD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM341_OFD_H) */
