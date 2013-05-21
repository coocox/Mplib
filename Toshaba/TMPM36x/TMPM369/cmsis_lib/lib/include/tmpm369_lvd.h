/**
 *******************************************************************************
 * @file    tmpm369_lvd.h
 * @brief   This file provides all the functions prototypes for LVD driver. 
 * @version V2.0.2.1
 * @date    2011/07/25
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
#ifndef __TMPM369_LVD_H
#define __TMPM369_LVD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
#include "tx03_common.h"

#if defined(__TMPM369_LVD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup LVD
  * @{
  */

/** @defgroup LVD_Exported_Types
  * @{
  */
    typedef enum {
        LVD_VD_UPPER = 0U,
        LVD_VD_LOWER = 1U
    } LVD_VDStatus;

/** @} */
/* End of group LVD_Exported_Types */

/** @defgroup LVD_Exported_Constants
  * @{
  */
#define LVD_VDLVL1_240                   ((uint32_t)0x00000000)
#define LVD_VDLVL1_250                   ((uint32_t)0x00000002)
#define LVD_VDLVL1_260                   ((uint32_t)0x00000004)
#define LVD_VDLVL1_270                   ((uint32_t)0x00000006)
#define LVD_VDLVL1_280                   ((uint32_t)0x00000008)
#define LVD_VDLVL1_290                   ((uint32_t)0x0000000A)
#define IS_LVD_VD1_LEVEL(param)         (((param) == LVD_VDLVL1_240) || \
                                         ((param) == LVD_VDLVL1_250) || \
                                         ((param) == LVD_VDLVL1_260) || \
                                         ((param) == LVD_VDLVL1_270) || \
                                         ((param) == LVD_VDLVL1_280) || \
                                         ((param) == LVD_VDLVL1_290))

#define LVD_VDLVL2_280                   ((uint32_t)0x00000000)
#define LVD_VDLVL2_285                   ((uint32_t)0x00000002)
#define LVD_VDLVL2_290                   ((uint32_t)0x00000004)
#define LVD_VDLVL2_295                   ((uint32_t)0x00000006)
#define LVD_VDLVL2_300                   ((uint32_t)0x00000008)
#define LVD_VDLVL2_305                   ((uint32_t)0x0000000A)
#define LVD_VDLVL2_310                   ((uint32_t)0x0000000C)
#define LVD_VDLVL2_315                   ((uint32_t)0x0000000E)
#define IS_LVD_VD2_LEVEL(param)         (((param) == LVD_VDLVL2_280) || \
                                         ((param) == LVD_VDLVL2_285) || \
                                         ((param) == LVD_VDLVL2_290) || \
                                         ((param) == LVD_VDLVL2_295) || \
                                         ((param) == LVD_VDLVL2_300) || \
                                         ((param) == LVD_VDLVL2_305) || \
                                         ((param) == LVD_VDLVL2_300) || \
                                         ((param) == LVD_VDLVL2_310) || \
                                         ((param) == LVD_VDLVL2_315))

#define LVD_INTSEL_LOWER                ((uint32_t)0x00000000)
#define LVD_INTSEL_LOWER_UPPER          ((uint32_t)0x00000010)
#define IS_LVD_INT_CONDITION(param)     (((param) == LVD_INTSEL_LOWER) || \
                                         ((param) == LVD_INTSEL_LOWER_UPPER))

/** @} */
/* End of LVD_Exported_Constants */

/** @defgroup LVD_Exported_FunctionPrototypes
  * @{
  */
    void LVD_EnableVD1(void);
    void LVD_DisableVD1(void);
    void LVD_SetVD1Level(uint32_t VDLevel);
    LVD_VDStatus LVD_GetVD1Status(void);
    void LVD_EnableVD2(void);
    void LVD_DisableVD2(void);
    void LVD_SetVD2Level(uint32_t VDLevel);
    LVD_VDStatus LVD_GetVD2Status(void);
    void LVD_SetResetOutput(FunctionalState NewState);
    void LVD_SetINTOutput(FunctionalState NewState);
    void LVD_SetINTCondition(uint32_t IntCondition);

/** @} */
/* End of LVD_Exported_FunctionPrototypes */

/** @} */
/* End of group LVD */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM369_LVD_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM369_LVD_H */
