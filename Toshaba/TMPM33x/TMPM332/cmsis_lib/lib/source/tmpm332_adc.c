/**
 *******************************************************************************
 * @file    tmpm332_adc.c
 * @brief   This file provides API functions for ADC driver.
 * @version V2.1.0
 * @date    2010/07/20
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm332_adc.h"

#if defined(__TMPM330_ADC_H) || defined(__TMPM332_ADC_H) || defined(__TMPM333_ADC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup ADC 
  * @brief ADC driver modules
  * @{
  */

/** @defgroup ADC_Private_Defines
  * @{
  */
#define MOD4_ADRST_MASK         ((uint8_t)0xFC)
#define MOD4_ADRST_10           ((uint8_t)0x02)
#define MOD4_ADRST_01           ((uint8_t)0x01)

#define MOD0_ITM_CLEAR          ((uint8_t)0xC7)

#define MOD1_ADCH_CLEAR         ((uint8_t)0xE0)

#define MOD2_HPADCH_CLEAR       ((uint8_t)0xE0)

#define ADC_CMPREG_CLEAR        ((uint8_t)0x21)

#define MOD4_ADHTG_CLEAR        ((uint8_t)0xE3)
#define MOD4_ADHTG_SET          ((uint8_t)0x10)
#define MOD4_ADHS_CLEAR         ((uint8_t)0xD3)
#define MOD4_HADHTG_CLEAR       ((uint8_t)0xB3)
#define MOD4_HADHTG_SET         ((uint8_t)0x40)
#define MOD4_HADHS_CLEAR        ((uint8_t)0x73)

#define ADC_REGx_ADRxRF_MASK    ((uint16_t)0x0001)
#define ADC_REGx_OVRx_MASK      ((uint16_t)0x0002)
#define ADC_REGx_RESULT_MASK    ((uint16_t)0xFFC0)

/** @} */
/* End of group ADC_Private_Defines */

/** @defgroup ADC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group ADC_Private_FunctionPrototypes */

/** @defgroup ADC_Private_Functions
  * @{
  */

/** @} */
/* End of group ADC_Private_Functions */

/** @defgroup ADC_Exported_Functions
  * @{
  */

/**
  * @brief  Software reset ADC function.
  * @param  None.
  * @retval None.
  */
void ADC_SWReset(void)
{
    /* Set MOD4<ADRST1:0> = 10, 01 to reset ADC */
    TSB_AD->MOD4 = MOD4_ADRST_10;
    TSB_AD->MOD4 = MOD4_ADRST_01;
    /* Set ADC accuracy   */
    ADC_SetAccuracy();
}

/**
  * @brief  Set ADC accuracy.
  * @param  None.
  * @retval None.
  */
void ADC_SetAccuracy(void)
{
    /* Set ADCBARS<ADCBRA7:0> = 0x58 to assure conversion accuracy */
    TSB_AD->CBAS = 0x58U;
}

/**
  * @brief  Set ADC sample hold time and prescaler output.
  * @param  Sample_HoldTime: Select ADC sample hold time.
  *   This parameter can be one of the following values:
  *   ADC_HOLD_CLK_8, ADC_HOLD_CLK_16, ADC_HOLD_CLK_24, ADC_HOLD_CLK_32,
  *   ADC_HOLD_CLK_64, ADC_HOLD_CLK_128, ADC_HOLD_CLK_512.
  * @param  Prescaler_Output: Select ADC prescaler output.
  *   This parameter can be one of the following values:
  *   ADC_FC_DIVIDE_LEVEL_1, ADC_FC_DIVIDE_LEVEL_2, ADC_FC_DIVIDE_LEVEL_4,
  *   ADC_FC_DIVIDE_LEVEL_8, ADC_FC_DIVIDE_LEVEL_16.
  * @retval None.
  */
void ADC_SetClk(uint32_t Sample_HoldTime, uint32_t Prescaler_Output)
{
    /* Check the parameters */
    assert_param(IS_ADC_HOLD_TIME(Sample_HoldTime));
    assert_param(IS_ADC_PRESCALER(Prescaler_Output));
    /* Set ADCLK */
    TSB_AD->CLK = Sample_HoldTime + Prescaler_Output;
}

/**
  * @brief  Start ADC function.
  * @param  None.
  * @retval None
  */
void ADC_Start(void)
{
    /* Set ADMOD0<ADS> = 1 to start ADC */
    TSB_AD_MOD0_ADS = ENABLE;
}

/**
  * @brief  Set ADC scan mode.
  * @param  NewState: Specify ADC scan mode.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetScanMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD0<SCAN>     */
    TSB_AD_MOD0_SCAN = NewState;
}

/**
  * @brief  Set ADC repeat mode.
  * @param  NewState: Specify ADC repeat mode.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetRepeatMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD0<REPEAT>  */
    TSB_AD_MOD0_REPEAT = NewState;
}

/**
  * @brief  Set ADC interrupt mode in fixed channel repeat conversion mode.
  * @param  ITMode: Specify AD conversion interrupt mode.
  *   This parameter can be one of the following values:
  *   ADC_INT_SIGNLE, ADC_INT_CONVERSION_4 or ADC_INT_CONVERSION_8.
  * @retval None.
  */
void ADC_SetINTMode(uint8_t INTMode)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INT_MODE(INTMode));
    /* Set ADMOD0<ITM1:0>  */
    tmp = TSB_AD->MOD0;
    tmp &= MOD0_ITM_CLEAR;
    tmp |= INTMode;
    TSB_AD->MOD0 = tmp;
}

/**
  * @brief  Read Normal ADC completion flag.
  * @param  None.
  * @retval ADC finish state.
  *   The value returned can be one of the followings:
  *   DONE, BUSY.
  */
WorkState ADC_GetConvertState(void)
{
    uint32_t tmp = 0U;

    WorkState retval = BUSY;
    /* Read ADMOD0<EOCFN> to check ADC state    */
    tmp = TSB_AD_MOD0_EOCFN;
    if (tmp == 0U) {
        retval = BUSY;
    } else {
        retval = DONE;
    }
    return retval;
}

/**
  * @brief  Set ADC input channel.
  * @param  InputChannel: Analog input channel, it also related with other settings.
  *   This parameter can be one of the following values:
  *   ADC_AN_0, ADC_AN_1, ADC_AN_2, ADC_AN_3,(Invalid for TMPM332)
  *   ADC_AN_4, ADC_AN_5, ADC_AN_6, ADC_AN_7,
  *   ADC_AN_8, ADC_AN_9, ADC_AN_10, ADC_AN_11;
  *   ADC_AN_0_1, ADC_AN_0_2, ADC_AN_0_3, ADC_AN_0_4,
  *   ADC_AN_0_5, ADC_AN_0_6, ADC_AN_0_7,(ADC_AN_0_1~ADC_AN_0_7 is invalid for TMPM332)
  *   ADC_AN_4_5, ADC_AN_4_6, ADC_AN_4_7, ADC_AN_8_9, ADC_AN_8_10, ADC_AN_8_11.
  * @retval None.
  */
void ADC_SetInputChannel(uint8_t InputChannel)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INPUT_CH(InputChannel));
    /* Set ADMOD1<ADCH3:0>  */
    tmp = TSB_AD->MOD1;
    tmp &= MOD1_ADCH_CLEAR;
    tmp |= InputChannel;
    TSB_AD->MOD1 = tmp;
}

/**
  * @brief  Set ADC operation for scanning.
  * @param  ScanMode: Spcifiy operation mode for channel scanning.
  *   This parameter can be one of the following values:
  *   ADC_SCAN_4CH , ADC_SCAN_8CH.
  * @retval None.
  */
void ADC_SetChannelScanMode(ADC_ChannelScanMode ScanMode)
{
    /* Check the parameters */
    assert_param(IS_ADC_CH_SCAN_MODE(ScanMode));
    TSB_AD_MOD1_ADSCN = ScanMode;
}

/**
  * @brief  Set ADC in IDLE mode.
  * @param  NewState: Specify AD conversion in IDLE mode.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetIdleMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD1<I2AD>  */
    TSB_AD_MOD1_I2AD = NewState;
}

/**
  * @brief  Set ADC VREF application.
  * @param  NewState: Specify ADC Vref application.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetVref(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD1<VREFON>  */
    TSB_AD_MOD1_VREFON = NewState;
}

/**
  * @brief  Set ADC top-priority conversion analog input channel select.
  * @param  ITopInputChannel: Analog input channel for top-priority conversion.
  *   This parameter can be one of the following values:
  *   ADC_AN_0, ADC_AN_1, ADC_AN_2, ADC_AN_3,(Invalid for TMPM332)
  *   ADC_AN_4, ADC_AN_5, ADC_AN_6, ADC_AN_7,
  *   ADC_AN_8, ADC_AN_9, ADC_AN_10, ADC_AN_11.
  * @retval None.
  */
void ADC_SetInputChannelTop(uint8_t TopInputChannel)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INPUT_CH(TopInputChannel));
    /* Set ADMOD2<HPADCH3:0>  */
    tmp = TSB_AD->MOD2;
    tmp &= MOD2_HPADCH_CLEAR;
    tmp |= TopInputChannel;
    TSB_AD->MOD2 = tmp;
}

/**
  * @brief  Start top-priority ADC.
  * @param  None.
  * @retval None
  */
void ADC_StartTopConvert(void)
{
    /* Set ADMOD2<HPADCE> = 1 to start top-priority ADC */
    TSB_AD_MOD2_HPADCE = ENABLE;
}

/**
  * @brief  Read Top-priority ADC completion flag.
  * @param  None.
  * @retval Top-priority ADC finish state.
  *   The value returned can be one of the followings:
  *   DONE, BUSY.
  */
WorkState ADC_GetTopConvertState(void)
{
    uint32_t tmp = 0U;

    WorkState retval = BUSY;
    /* Read ADMOD2<EOCFHP> to check Top-priority ADC state    */
    tmp = TSB_AD_MOD2_EOCFHP;
    if (tmp == 0U) {
        retval = BUSY;
    } else {
        retval = DONE;
    }
    return retval;
}


/**
  * @brief  Set ADC monitor function.
  * @param  ADCMPx: Selet ADC compare register.
  *   This parameter can be one of the following values:
  *   ADC_CMP_0 or ADC_CMP_1.
  * @param  NewState: Specify AD conversion Vref application.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetMonitor(uint16_t ADCMPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_CMP(ADCMPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (ADCMPx == ADC_CMP_0) {
        /* Set ADMOD3<ADOBSV0> */
        TSB_AD_MOD3_ADOBSV0 = NewState;
    } else {
        /* Set ADMOD5<ADOBSV1> */
        TSB_AD_MOD5_ADOBSV1 = NewState;
    }
}

/**
  * @brief  Set ADC result output register or comparison register.
  * @param  ADCMPx: Selet AD compare register.
  *   This parameter can be one of the following values:
  *   ADC_CMP_0 or ADC_CMP_1.
  * @param  ResultComparison: Set AD conversion result storage register or
  *   comparison register if ADC monitor function is enabled.
  *   This parameter can be one of the following values:
  *   ADC_REG_08, ADC_REG_19, ADC_REG_2A, ADC_REG_3B,
  *   ADC_REG_4C, ADC_REG_5D, ADC_REG_6E, ADC_REG_7F, ADC_REG_SP.
  * @retval None.
  */
void ADC_SetResultCmpReg(uint16_t ADCMPx, uint8_t ResultComparison)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_CMP(ADCMPx));
    assert_param(IS_ADC_REG(ResultComparison));
    if (ADC_CMP_0 == ADCMPx) {
        /* Set ADMOD3<REGS3:0> */
        tmp = TSB_AD->MOD3;
        tmp &= ADC_CMPREG_CLEAR;
        tmp |= ResultComparison;
        TSB_AD->MOD3 = tmp;
    } else {
        /* Set ADMOD5<REGS3:0> */
        tmp = TSB_AD->MOD5;
        tmp &= ADC_CMPREG_CLEAR;
        tmp |= ResultComparison;
        TSB_AD->MOD5 = tmp;
    }
}

/**
  * @brief  Set ADC monitor interrupt.
  * @param  ADCMPx: Selet ADC compare register.
  *   This parameter can be one of the following values:
  *   ADC_CMP_0 or ADC_CMP_1.
  * @param   NewState: Specify ADC monitor function.
  *   This parameter can be one of the following values:
  *   ADC_COMPARISON_SMALLER or ADC_COMPARISON_LARGER.
  * @retval None.
  */
void ADC_SetMonitorINT(uint16_t ADCMPx, ADC_ComparisonState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_CMP(ADCMPx));
    assert_param(IS_ADC_CMP_INT(NewState));
    if (ADCMPx == ADC_CMP_0) {
        /* Set ADMOD3<ADOBIC0> */
        TSB_AD_MOD3_ADOBIC0 = NewState;
    } else {
        /* Set ADMOD5<ADOBIC1> */
        TSB_AD_MOD5_ADOBIC1 = NewState;
    }
}

/**
  * @brief  HW and HW Source for activating normal ADC setting.
  * @param  HwSource: HW source for activating normal ADC.
  *   This parameter can be one of the following values:
  *   ADC_EXT_TRG or ADC_MATCH_TB6RG0.
  * @param   NewState: Specify HW for activating normal ADC.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetHWTrg(uint8_t HwSource, FunctionalState NewState)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_HW_TRG_NORMAL(HwSource));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD4<ADHS> */
    tmp = TSB_AD->MOD4;
    tmp &= MOD4_ADHS_CLEAR;
    tmp |= HwSource;
    /* Set ADMOD4<ADHTG> */
    if (NewState == ENABLE) {
        tmp |= MOD4_ADHTG_SET;
    } else {
        tmp &= MOD4_ADHTG_CLEAR;
    }
    TSB_AD->MOD4 = tmp & MOD4_ADRST_MASK;
}

/**
  * @brief  HW and HW Source for activating top-priority ADC setting.
  * @param  HwSource: HW source for activating top-priority ADC.
  *   This parameter can be one of the following values:
  *   ADC_EXT_TRG or ADC_MATCH_TB5RG0.
  * @param   NewState: Specify HW for activating top-priority ADC.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetHWTrgTop(uint8_t HwSource, FunctionalState NewState)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_HW_TRG_TOP(HwSource));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD4<HADHS> */
    tmp = TSB_AD->MOD4;
    tmp &= MOD4_HADHS_CLEAR;
    tmp |= HwSource;
    /* Set ADMOD4<HADHTG> */
    if (NewState == ENABLE) {
        tmp |= MOD4_HADHTG_SET;
    } else {
        tmp &= MOD4_HADHTG_CLEAR;
    }
    TSB_AD->MOD4 = tmp & MOD4_ADRST_MASK;
}

/**
  * @brief  Read ADC result.
  * @param  ADREGx: ADC result register.
  *   This parameter can be one of the following values:
  *   ADC_REG_08, ADC_REG_19, ADC_REG_2A, ADC_REG_3B,
  *   ADC_REG_4C, ADC_REG_5D, ADC_REG_6E, ADC_REG_7F, ADC_REG_SP.
  * @retval ADC result.
  */
ADC_ResultTypeDef ADC_GetConvertResult(uint8_t ADREGx)
{
    uint32_t tmp = 0U;
    ADC_ResultTypeDef retval = {BUSY, ADC_NO_OVERRUN, 0U};

    /* Check the parameters */
    assert_param(IS_ADC_REG(ADREGx));
    /* Read ADREGx<ADRx9:0> to get ADC result    */
    switch (ADREGx) {
    case ADC_REG_08:
        tmp = TSB_AD->REG08;
        break;
    case ADC_REG_19:
        tmp = TSB_AD->REG19;
        break;
    case ADC_REG_2A:
        tmp = TSB_AD->REG2A;
        break;
    case ADC_REG_3B:
        tmp = TSB_AD->REG3B;
        break;
    case ADC_REG_4C:
        tmp = TSB_AD->REG4C;
        break;
    case ADC_REG_5D:
        tmp = TSB_AD->REG5D;
        break;
    case ADC_REG_6E:
        tmp = TSB_AD->REG6E;
        break;
    case ADC_REG_7F:
        tmp = TSB_AD->REG7F;
        break;
    case ADC_REG_SP:
        tmp = TSB_AD->REGSP;
        break;
    default:                   /* Do nothing */
        break;
    }

    if ((tmp & ADC_REGx_ADRxRF_MASK) == 0U) {
        retval.ADCResultStored = BUSY;
    } else {
        retval.ADCResultStored = DONE;
    }

    if ((tmp & ADC_REGx_OVRx_MASK) == 0U) {
        retval.ADCOverrunState = ADC_NO_OVERRUN;
    } else {
        retval.ADCOverrunState = ADC_OVERRUN;
    }

    retval.ADCResultValue = tmp & ADC_REGx_RESULT_MASK;
    retval.ADCResultValue >>= 6U;

    return retval;
}

/**
  * @brief  Set ADC comparison register value.
  * @param  ADCMPx: Selet AD compare register.
  *   This parameter can be one of the following values:
  *   ADC_CMP_0 or ADC_CMP_1.
  * @param  value: The value setting to ADC comparison register.
  * @retval None.
  */
void ADC_SetCmpValue(uint16_t ADCMPx, uint16_t value)
{
    /* Check the parameters */
    assert_param(IS_ADC_CMP(ADCMPx));
    assert_param(IS_ADC_CMP_VALUE(value));
    value <<= 6U;
    if (ADCMPx == ADC_CMP_0) {
        /* Set ADCMP0<ADCOM0[9:0]> */
        TSB_AD->CMP0 = value;
    } else {
        /* Set ADCMP1<ADCOM1[9:0]> */
        TSB_AD->CMP1 = value;
    }
}

/** @} */
/* End of group ADC_Exported_Functions */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM330_ADC_H) || (__TMPM332_ADC_H) || (__TMPM333_ADC_H) */
