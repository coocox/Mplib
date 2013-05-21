/**
 *******************************************************************************
 * @file    tmpm369_dac.c
 * @brief   This file provides API functions for DAC driver.
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm369_dac.h"

#if defined(__TMPM369_DAC_H)
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
#define DAC_SWEN_TRG_MASK   ((uint32_t)0x00000F00)
#define DAC_SWEN_TRG_DATA   ((uint32_t)0x00000100)
#define DAC_CLEAR_MASK      ((uint32_t)0x00000001)
#define DAC_SWRTG_DATA      ((uint32_t)0x00000001)

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
    DACx->CNT = DAC_START;
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
    DACx->CNT = DAC_STOP;
}

/**
  * @brief  Initialize the DAC.
  * @param  DACx: Select the DAC channel.
  *         This parameter can be one of the following values:
  *         TSB_DA0, TSB_DA1
  * @param  InitStruct: The structure containing basic DAC configuration including clear DAC request, 
  *         set post adjustment for VOUTHOLD time, pre adjustment for VOUTHOLD time, 
  *         offset setting of output waveform, amplitude setting of output waveform,
  *         output waveform selection, trigger selection and trigger function.
  * @retval None
  */
void DAC_Init(TSB_DA_TypeDef * DACx, DAC_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_DAC_CHANNEL(DACx));
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_DAC_CLEAR(InitStruct->DACClear));
    assert_param(IS_DAC_ADJTIME(InitStruct->PostTime));
    assert_param(IS_DAC_ADJTIME(InitStruct->PreTime));
    assert_param(IS_DAC_OFFSET(InitStruct->Offset));
    assert_param(IS_DAC_AMPSEL(InitStruct->AmpSel));
    assert_param(IS_DAC_TRGSEL(InitStruct->TrgSel));
    assert_param(IS_DAC_TRGFUNC(InitStruct->TrgFunc));
    assert_param(IS_DAC_DMAFUNC(InitStruct->DMAFunc));
    assert_param(IS_DAC_WAVE(InitStruct->Wave));

    /*Clear DAC */
    tmp = DACx->TCTL;
    tmp &= DAC_CLEAR_MASK;
    tmp |= InitStruct->DACClear;
    DACx->TCTL = tmp;
    /*Set time to VOUTHOLD adjustment register */
    tmp = (uint8_t) (InitStruct->PostTime << 4U);
    tmp += InitStruct->PreTime;
    DACx->VCTL = tmp;

    /*set DACDCTLx(output control register) */
    tmp = (uint8_t) (InitStruct->Offset << 18U);
    tmp += (uint8_t) (InitStruct->AmpSel << 16U);
    tmp += (uint8_t) (InitStruct->TrgSel << 9U);
    tmp += (uint8_t) (InitStruct->TrgFunc << 8U);
    tmp += (uint8_t) (InitStruct->DMAFunc << 7U);
    tmp += (uint8_t) (InitStruct->Wave);
    DACx->DCTL = tmp;

}

/**
  * @brief  Software output control.
  * @param  DACx: Select the DAC channel.
  *         This parameter can be one of the following values:
  *         TSB_DA0, TSB_DA1
  * @retval SUCCESS or ERROR.
  */
Result DAC_SWOutput(TSB_DA_TypeDef * DACx)
{

    Result retval = ERROR;
    uint32_t reg = 0U;
    assert_param(IS_DAC_CHANNEL(DACx));
    /*Set the bit if <TRGEN>=1 is set. */
    reg = DACx->DCTL & DAC_SWEN_TRG_MASK;
    if (reg == DAC_SWEN_TRG_DATA) {
        DACx->TCTL = DAC_SWRTG_DATA;
        retval = SUCCESS;
    } else {
        retval = ERROR;
    }
    return retval;
}


/** @} */
/* End of group DAC_Exported_Functions */

/** @} */
/* End of group DAC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM369_DAC_H) */
