/**
 *******************************************************************************
 * @file    tmpm369_dac.h
 * @brief   This file provides all the functions prototypes for DAC driver. 
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
#ifndef __TMPM369_DAC_H
#define __TMPM369_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
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

#define IS_DAC_OUTPUT_CODE(param)   ((param) <= (uint16_t) 0x3FF )
#define DAC_CLEAR       1U
#define DAC_NCLEAR      0U
#define IS_DAC_CLEAR(param)         ((param) == DAC_CLEAR)||((param) == DAC_NCLEAR)
#define IS_DAC_ADJTIME(param)       ((param) <= (uint8_t) 0xF)&&((param) != 0U)
#define DAC_0DIV8_VDD       0U
#define DAC_1DIV8_VDD       1U
#define DAC_2DIV8_VDD       2U
#define DAC_3DIV8_VDD       3U
#define DAC_4DIV8_VDD       4U
#define DAC_5DIV8_VDD       5U
#define DAC_6DIV8_VDD       6U
#define IS_DAC_OFFSET(param)        ((param) <= 6U)
#define DAC_1DIV1_VDD       0U
#define DAC_1DIV2_VDD       1U
#define DAC_1DIV4_VDD       2U
#define IS_DAC_AMPSEL(param)        ((param) <= 2U)
#define DAC_TRG_SW          0U
#define DAC_TRG_EXT         1U
#define DAC_TRG_TMRB2       2U
#define DAC_TRG_TMRB3       3U
#define DAC_TRG_TMRB4       4U
#define DAC_TRG_TMRB5       5U
#define DAC_TRG_TMRB6       6U
#define DAC_TRG_TMRB7       7U
#define IS_DAC_TRGSEL(param)        ((param) <= 7U)
#define DAC_TRG_DISABLE     0U
#define DAC_TRG_ENABLE      1U
#define IS_DAC_TRGFUNC(param)       ((param) <= 1U)
#define DAC_DMA_DISABLE     0U
#define DAC_DMA_ENABLE      1U
#define IS_DAC_DMAFUNC(param)       ((param) <= 1U)
#define DAC_NO_WAVE         0U
#define DAC_TRIANGLE_WAVE   1U
#define DAC_NOISE_WAVE      2U
#define DAC_SINE_WAVE       3U
#define IS_DAC_WAVE(param)          ((param) <= 3U)

/** @} */
/* End of DAC_Exported_Constants */

/** @addtogroup DAC_Exported_types
  * @{
  */
    typedef struct {
        uint8_t DACClear;
        uint8_t PostTime;
        uint8_t PreTime;
        uint8_t Offset;
        uint8_t AmpSel;
        uint8_t TrgSel;
        uint8_t TrgFunc;
        uint8_t DMAFunc;
        uint8_t Wave;
    } DAC_InitTypeDef;
/** @} */
/* End of DAC_Exported_types */

/** @defgroup DAC_Exported_FunctionPrototypes
  * @{
  */

    void DAC_SetOutputCode(TSB_DA_TypeDef * DACx, uint16_t OutputCode);
    void DAC_Start(TSB_DA_TypeDef * DACx);
    void DAC_Stop(TSB_DA_TypeDef * DACx);
    void DAC_Init(TSB_DA_TypeDef * DACx, DAC_InitTypeDef * InitStruct);
    Result DAC_SWOutput(TSB_DA_TypeDef * DACx);

/** @} */
/* End of DAC_Exported_FunctionPrototypes */

/** @} */
/* End of group DAC */

/** @} */
/* End of group TX03_Periph_Driver */
#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM369_DAC_H */
