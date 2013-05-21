/**
 *******************************************************************************
 * @file    tmpm376_wdt.h
 * @brief   This file provides all the functions prototypes for WDT driver.
 * @version V2.0.2.1
 * @date    2011/12/02
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
#ifndef __TMPM376_WDT_H
#define __TMPM376_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM376.h"
#include "tx03_common.h"

#if defined(__TMPM376_WDT_H) || defined(__TMPM377_WDT_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup WDT
  * @{
  */

/** @defgroup WDT_Exported_Types
  * @{
  */

/** 
  * @brief  WDT Init Structure definition 
  */

    typedef struct {
        uint32_t DetectTime;    /*!< Set WDT detection time. */
        uint32_t OverflowOutput;        /*!< Select "Generates NMI interrupt" or "Connects WDT out to reset". */
    } WDT_InitTypeDef;

/** @} */
/* End of group WDT_Exported_Types */

/** @defgroup WDT_Exported_Constants
  * @{
  */

#define WDT_DETECT_TIME_EXP_15          ((uint32_t)0x00000000)
#define WDT_DETECT_TIME_EXP_17          ((uint32_t)0x00000010)
#define WDT_DETECT_TIME_EXP_19          ((uint32_t)0x00000020)
#define WDT_DETECT_TIME_EXP_21          ((uint32_t)0x00000030)
#define WDT_DETECT_TIME_EXP_23          ((uint32_t)0x00000040)
#define WDT_DETECT_TIME_EXP_25          ((uint32_t)0x00000050)

#define IS_WDT_DETECT_TIME(param)   (((param) == WDT_DETECT_TIME_EXP_15) || \
                                     ((param) == WDT_DETECT_TIME_EXP_17) || \
                                     ((param) == WDT_DETECT_TIME_EXP_19) || \
                                     ((param) == WDT_DETECT_TIME_EXP_21) || \
                                     ((param) == WDT_DETECT_TIME_EXP_23) || \
                                     ((param) == WDT_DETECT_TIME_EXP_25))

#define WDT_WDOUT            ((uint32_t)0x00000001)
#define WDT_NMIINT           ((uint32_t)0x00000000)

#define IS_WDT_OUTPUT(param)      (((param) == WDT_WDOUT) || \
                                   ((param) == WDT_NMIINT))
/** @} */
/* End of WDT_Exported_Constants */

/** @addtogroup WDT_Exported_types
  * @{
  */

/** @} */
/* End of WDT_Exported_types */

/** @defgroup WDT_Exported_FunctionPrototypes
  * @{
  */

    void WDT_SetDetectTime(uint32_t DetectTime);
    void WDT_SetIdleMode(FunctionalState NewState);
    void WDT_SetOverflowOutput(uint32_t OverflowOutput);
    void WDT_Init(WDT_InitTypeDef * InitStruct);
    void WDT_Enable(void);
    void WDT_Disable(void);
    void WDT_WriteClearCode(void);

/** @} */
/* End of WDT_Exported_FunctionPrototypes */

/** @} */
/* End of group WDT */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM376_WDT_H) || defined(__TMPM377_WDT_H)  */

#ifdef __cplusplus
}
#endif
#endif                          /* defined(__TMPM376_WDT_H) */
