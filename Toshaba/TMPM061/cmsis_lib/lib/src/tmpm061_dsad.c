/**
 *******************************************************************************
 * @file    tmpm061_DSADC.c
 * @brief   This file provides API functions for DSADC driver.
 * @version V2.0.2.1
 * @date    2013/04/16
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm061_dsad.h"

/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @defgroup DSADC_Private_Defines
  * @{
  */
#define DSAD_SWRST_CMD1         ((uint32_t)0x02)
#define DSAD_SWRST_CMD2         ((uint32_t)0x01)


/** @} */
/* End of group DSADC_Private_Defines */


/**
  * @brief  Set AD conversion clock.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2.  
  * @param  clk: AD conversion clock selection.
  *   This parameter can be one of the following values:
  *   DSADC_FC_DIVIDE_LEVEL_1, DSADC_FC_DIVIDE_LEVEL_2,
  *   DSADC_FC_DIVIDE_LEVEL_4, DSADC_FC_DIVIDE_LEVEL_8.
  * @retval None.
  */
void DSADC_SetClk(TSB_DSAD_TypeDef * DSADCx, uint32_t Clk)
{
    /* Check the parameters */
    assert_param(IS_DSADC_PERIPH(DSADCx));
    assert_param(IS_DSADC_CLOCK_SEL(Clk));
    /* Set DSADCLK */
    DSADCx->CLK = Clk;
}


/**
  * @brief  Software reset ADC function.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @retval None.
  */
void DSADC_SWReset(TSB_DSAD_TypeDef * DSADCx)
{
    assert_param(IS_DSADC_PERIPH(DSADCx));
    DSADCx->CR1 |= 0x02U;       /*Valid only when DSADCR1<BIASEN>="1". */
    DSADCx->CR0 = DSAD_SWRST_CMD1;
    DSADCx->CR0 = DSAD_SWRST_CMD2;
}


/**
  * @brief  Start DSADC function.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @retval None
  */
void DSADC_Start(TSB_DSAD_TypeDef * DSADCx)
{
    assert_param(IS_DSADC_PERIPH(DSADCx));
    /* Set ADMOD0<ADS> = 1 to start DSADC */
    DSADCx->CR2 = 0x01U;
}

/**
  * @brief  Change DSADC Synchronous mode and Conversion mode.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2.
  * @param  SyncMode: Select the DSADC Synchronous mode.
  *   This parameter can be one of the following values:
  *   DSADC_A_SYNC_MODE,DSADC_SYNC_MODE.
  * @param  ConvMode: Select the ConvMode mode.
  *   This parameter can be one of the following values:
  *   DSADC_SINGLE_MODE,DSADC_REPEAT_MODE.
  * @retval None
  */
void DSADC_ChangeMode(TSB_DSAD_TypeDef * DSADCx, uint8_t SyncMode, uint8_t ConvMode)
{
    uint32_t reg = ((uint32_t) SyncMode << 8U);

    assert_param(IS_DSADC_PERIPH(DSADCx));
    assert_param(IS_DSADC_1BIT_CHECK(SyncMode));
    assert_param(IS_DSADC_1BIT_CHECK(ConvMode));

    reg |= (uint32_t) ConvMode;
    DSADCx->CR3 = reg;
}

/**
  * @brief  Set DSADC Amplifier.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2.
  * @param  Amplifier: DSADC Amplifier setting.
  *   This parameter can be one of the following values:
  *   DSADC_GAIN_1x,DSADC_GAIN_2x,DSADC_GAIN_4x,DSADC_GAIN_8x,DSADC_GAIN_16x.
  * @retval None
  */

void DSADC_SetAmplifier(TSB_DSAD_TypeDef * DSADCx, uint32_t Amplifier)
{
    assert_param(IS_DSADC_PERIPH(DSADCx));
    assert_param(IS_DSADC_GAIN(Amplifier));
    DSADCx->CR4 = Amplifier;
}

/**
  * @brief  Get DSADC convert result.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @retval Convert result.
  */

uint32_t DSADC_GetConvertResult(TSB_DSAD_TypeDef * DSADCx)
{
    uint32_t result = 0U;

    assert_param(IS_DSADC_PERIPH(DSADCx));

    while (!((DSADCx->ST & 0x02U))) {   /* wait conversion end */
    }
    result = DSADCx->RES;
    if (result & 0x01U) {
        result >>= 8U;
    }
    return result;
}

/**
  * @brief  Initialize the specified DSADC channel.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @param  InitStruct: The structure containing basic DSADC configuration.
  * @retval None
  */

void DSADC_Init(TSB_DSAD_TypeDef * DSADCx, DSADC_InitTypeDef * InitStruct)
{
    assert_param(IS_DSADC_PERIPH(DSADCx));
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_DSADC_CLOCK_SEL(InitStruct->Clk));
    assert_param(IS_DSADC_1BIT_CHECK(InitStruct->BiasEn));
    assert_param(IS_DSADC_1BIT_CHECK(InitStruct->ModulatorEn));
    assert_param(IS_DSADC_1BIT_CHECK(InitStruct->SyncMode));
    assert_param(IS_DSADC_1BIT_CHECK(InitStruct->Repeatmode));

    assert_param(IS_DSADC_1BIT_CHECK(InitStruct->CorrectEn));
    assert_param(IS_DSADC_GAIN(InitStruct->Amplifier));
    DSADCx->CLK = InitStruct->Clk;

    /* SW Reset */
    DSADC_SWReset(DSADCx);

    /* DSADCR1 BIT1: BIASEN  BIT0: MODEN */
    DSADCx->CR1 = ((uint32_t) InitStruct->BiasEn << 1U) | InitStruct->ModulatorEn;

    /* DSADCR3 BIT8: ADSYNC  BIT0: REPEAT */
    DSADCx->CR3 = ((uint32_t) InitStruct->SyncMode << 8U) | InitStruct->Repeatmode;

    /* DSADADJ */
    DSADCx->ADJ = ((uint32_t) InitStruct->Offset << 16U) | InitStruct->CorrectEn;

    /* Amplifier setting */
    DSADCx->CR4 = InitStruct->Amplifier;

}

/**
  * @brief  Indicate DSADC Convertor status and result.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @retval The DSADC Convertor status and result.
  */
DSAD_status DSADC_GetStatus(TSB_DSAD_TypeDef * DSADCx)
{
    DSAD_status retval = { 0U };

    assert_param(IS_DSADC_PERIPH(DSADCx));

    retval.All = DSADCx->ST & 0x03U;
    retval.All = retval.All << 2U;
    retval.All |= DSADCx->RES;
    return retval;
}

/**
  * @brief  Set DSADC clock enable or disable.
  * @param  DSADCx: Select the DSADC channel.
  *   This parameter can be one of the following values:
  *   TSB_DSAD0, TSB_DSAD1, TSB_DSAD2. 
  * @param  NewState: Specify DSADC clock.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void DSADC_SetClkSupply(TSB_DSAD_TypeDef * DSADCx, FunctionalState NewState)
{
    uint32_t reg = DSADCx->ST;
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /*while convertion is end and no conversion start */
    while (DSADCx->ST == 0x02U) {
        if (NewState == ENABLE) {
            TSB_CG_SYSCR_FCSTOP = DISABLE;
        } else {
            TSB_CG_SYSCR_FCSTOP = ENABLE;
        }
    }
}

/** @} */
/* End of group DSADC_Exported_Functions */

/** @} */
/* End of group DSADC */

/** @} */
/* End of group TX00_Periph_Driver */
