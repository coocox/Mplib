/**
 *******************************************************************************
 * @file    tmpm370_ofd.h
 * @brief   This file provides all the functions prototypes for OFD driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM370_OFD_H
#define __TMPM370_OFD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM370.h"
#include "tx03_common.h"

#if defined(__TMPM370_OFD_H) || defined(__TMPM372_OFD_H) || defined(__TMPM373_OFD_H) || defined(__TMPM374_OFD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @addtogroup OFD
  * @{
  */
/** @addtogroup OFD_Exported_Types
  * @{
  */
/** @} */
/* End of group OFD_Exported_Types */
/** @defgroup OFD_Exported_Constants
  * @{
  */
#define IS_OFD_DETECT_FREQ_HIGHER(param)    ((param) <= 0x000001FFU)
#define IS_OFD_DETECT_FREQ_LOWER(param)     ((param) <= 0x000001FFU)

    typedef enum {
        OFD_PLL_ON = 0U,
        OFD_PLL_OFF = 1U
    } OFD_PLL_State;
#define IS_OFD_PLL_State(param)      (((param) == OFD_PLL_ON) || \
                                      ((param) == OFD_PLL_OFF))

/** @} */
/* End of OFD_Exported_Constants */

/** @defgroup OFD_Exported_FunctionPrototypes
  * @{
  */
    void OFD_SetRegWriteMode(FunctionalState NewState);
    void OFD_Enable(void);
    void OFD_Disable(void);
    void OFD_SetDetectionFrequency(OFD_PLL_State State, uint32_t HigherDetectionCount, uint32_t LowerDetectionCount);

/** @} */
/* End of group OFD_Exported_FunctionPrototypes */
/** @} */
/* End of group OFD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_OFD_H) || defined(__TMPM372_OFD_H) || defined(__TMPM373_OFD_H) || defined(__TMPM374_OFD_H) */
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM370_OFD_H */
