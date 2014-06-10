/**
 *******************************************************************************
 * @file    tmpm061_lvd.h
 * @brief   This file provides all the functions prototypes for LVD(Low Voltage Detection) driver. 
 * @version V2.0.2.1
 * @date    2012/04/25
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM061_LVD_H
#define __TMPM061_LVD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

#if defined(__TMPM061_LVD_H)
/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @addtogroup LVD
  * @{
  */

/** @defgroup LVD_Exported_Types
  * @{
  */

/** @} */
/* End of group LVD_Exported_Types */

/** @defgroup LVD_Exported_Constants
  * @{
  */

#define LVD_DETECT_VOLTAGE_280      ((uint32_t)0x0)
#define LVD_DETECT_VOLTAGE_285      ((uint32_t)0x1)
#define LVD_DETECT_VOLTAGE_290      ((uint32_t)0x2)
#define LVD_DETECT_VOLTAGE_295      ((uint32_t)0x3)
#define LVD_DETECT_VOLTAGE_300      ((uint32_t)0x4)
#define LVD_DETECT_VOLTAGE_305      ((uint32_t)0x5)
#define LVD_DETECT_VOLTAGE_310      ((uint32_t)0x6)
#define LVD_DETECT_VOLTAGE_315      ((uint32_t)0x7)
#define IS_LVD_DETECT_VOLTAGE(param)   ((param) <= LVD_DETECT_VOLTAGE_315)


    typedef enum {
        LVD_SUPPLY_HIGH = 0U,   /* supply voltage is higher than threshold */
        LVD_SUPPLY_LOW = 1U     /* supply voltage is lower than threshold  */
    } LVD_SupplyStatus;

#define LVD_INTSEL_LOWER            ((uint32_t)0x0)
#define LVD_INTSEL_LOWER_UPPER      ((uint32_t)0x1)
#define IS_LVD_INTSEL_LOWER_UPPER(param)   ((param)  <= LVD_INTSEL_LOWER_UPPER)

/** @} */
/* End of LVD_Exported_Constants */

/** @defgroup LVD_Exported_FunctionPrototypes
  * @{
  */

    void LVD_Enable(void);
    void LVD_Disable(void);
    void LVD_SetVoltage(uint32_t Voltage);
    LVD_SupplyStatus LVD_GetStatus(void);
    void LVD_SetINTOutput(FunctionalState NewState);
    void LVD_SetINTCondition(uint32_t Condition);

/** @} */
/* End of LVD_Exported_FunctionPrototypes */

/** @} */
/* End of group LVD */

/** @} */
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_LVD_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM061_LVD_H */
