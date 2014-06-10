/**
 *******************************************************************************
 * @file    tmpm370_vltd.h
 * @brief   This file provides all the functions prototypes for VLTD driver. 
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM370_VLTD_H
#define __TMPM370_VLTD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM370.h"
#include "tx03_common.h"

#if defined(__TMPM370_VLTD_H) || defined(__TMPM372_VLTD_H) || defined(__TMPM373_VLTD_H) || defined(__TMPM374_VLTD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup VLTD
  * @{
  */

/** @defgroup VLTD_Exported_Types
  * @{
  */

/** @} */
/* End of group VLTD_Exported_Types */

/** @defgroup VLTD_Exported_Constants
  * @{
  */

#define VLTD_DETECT_VOLTAGE_41          ((uint32_t)0x00000002)
#define VLTD_DETECT_VOLTAGE_44          ((uint32_t)0x00000004)
#define VLTD_DETECT_VOLTAGE_46          ((uint32_t)0x00000006)

#define IS_VLTD_DETECT_VOLTAGE(param)   (((param) == VLTD_DETECT_VOLTAGE_41) || \
                                         ((param) == VLTD_DETECT_VOLTAGE_44) || \
                                         ((param) == VLTD_DETECT_VOLTAGE_46))

/** @} */
/* End of VLTD_Exported_Constants */

/** @defgroup VLTD_Exported_FunctionPrototypes
  * @{
  */
    void VLTD_Enable(void);
    void VLTD_Disable(void);
    void VLTD_SetVoltage(uint32_t Voltage);

/** @} */
/* End of VLTD_Exported_FunctionPrototypes */

/** @} */
/* End of group VLTD */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_VLTD_H) || defined(__TMPM372_VLTD_H) || defined(__TMPM373_VLTD_H) || defined(__TMPM374_VLTD_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM370_VLTD_H */
