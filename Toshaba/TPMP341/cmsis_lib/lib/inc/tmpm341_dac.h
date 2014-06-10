/**
 *******************************************************************************
 * @file    tmpm341_dac.h
 * @brief   This file provides all the functions prototypes for DAC driver. 
 * @version V2.0.2.1
 * @date    2011/01/19
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
#ifndef __TMPM341_DAC_H
#define __TMPM341_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup DAC
  * @{
  */

/** @defgroup DAC_Exported_Types
  * @{
  */

/** @} */
/* End of group DAC_Exported_Types */

/* End of group DAC_Exported_Types */

/** @defgroup DAC_Exported_Constants
  * @{
  */
#define IS_DAC_CHANNEL(param) (((param) == TSB_DA0) || \
                               ((param) == TSB_DA1))

#define IS_DAC_OUTPUT_CODE(param)   ((param) <= (uint16_t) 0x3ff )

/** @} */
/* End of DAC_Exported_Constants */

/** @addtogroup DAC_Exported_types
  * @{
  */

/** @} */
/* End of DAC_Exported_types */

/** @defgroup DAC_Exported_FunctionPrototypes
  * @{
  */

    void DAC_SetOutputCode(TSB_DA_TypeDef * DACx, uint16_t OutputCode);
    void DAC_Start(TSB_DA_TypeDef * DACx);
    void DAC_Stop(TSB_DA_TypeDef * DACx);

/** @} */
/* End of DAC_Exported_FunctionPrototypes */

/** @} */
/* End of group DAC */

/** @} */
/* End of group TX03_Periph_Driver */
#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM341_DAC_H */
