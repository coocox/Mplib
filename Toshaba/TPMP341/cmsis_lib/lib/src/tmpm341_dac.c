/**
 *******************************************************************************
 * @file    tmpm341_dac.c
 * @brief   This file provides API functions for DAC driver.
 * @version V2.0.2.1
 * @date    2011/01/25
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
#include "tmpm341_dac.h"


/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup DAC 
  * @brief DAC driver modules
  * @{
  */
/** @defgroup DAC_Private_Defines
  * @{
  */

#define DAC_START           ((uint32_t)0x00000003)
#define DAC_STOP            ((uint32_t)0x00000000)

/** @} */
/* End of group DAC_Private_Defines */

/** @defgroup DAC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group DAC_Private_FunctionPrototypes */

/** @defgroup DAC_Private_Functions
  * @{
  */

/** @} */
/* End of group group DAC_Private_Functions */

/** @defgroup DAC_Exported_Functions
  * @{
  */

/**
  * @brief  Set DACx output code.
  * @param  DACx: Select the DAC channel.
  *         This parameter can be one of the following values:
  *         TSB_DA0, TSB_DA1
  *         OutputCode: output code (10 bit) which will be converted to analog data. 
  *         Max value of this parameter can be 0x03FF
  * @retval None
  */
void DAC_SetOutputCode(TSB_DA_TypeDef * DACx, uint16_t OutputCode)
{
    /* Check the parameters */
    assert_param(IS_DAC_CHANNEL(DACx));
    assert_param(IS_DAC_OUTPUT_CODE(OutputCode));

    /* Set DAC Output Code */
    DACx->REG = (uint32_t) OutputCode;
}

/**
  * @brief  Start the operation of the specified DAC channel.
  * @param  DACx: Select the DAC channel.
  *         This parameter can be one of the following values:
  *         TSB_DA0, TSB_DA1
  * @retval None
  */
void DAC_Start(TSB_DA_TypeDef * DACx)
{
    assert_param(IS_DAC_CHANNEL(DACx));
    DACx->CTL1 = DAC_START;
}

/**
  * @brief  Stop the operation of the specified DAC channel.
  * @param  DACx: Select the DAC channel.
  *         This parameter can be one of the following values:
  *         TSB_DA0, TSB_DA1
  * @retval None
  */
void DAC_Stop(TSB_DA_TypeDef * DACx)
{
    assert_param(IS_DAC_CHANNEL(DACx));
    DACx->CTL1 = DAC_STOP;
}



/** @} */
/* End of group DAC_Exported_Functions */

/** @} */
/* End of group DAC */

/** @} */
/* End of group TX03_Periph_Driver */
