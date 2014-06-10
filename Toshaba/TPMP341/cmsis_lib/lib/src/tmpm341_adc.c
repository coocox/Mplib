/**
 *******************************************************************************
 * @file    tmpm341_adc.c
 * @brief   This file provides API functions for ADC driver.
 * @version V2.0.2.1
 * @date    2011/03/22
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
#include "tmpm341_adc.h"

#if defined(__TMPM341_ADC_H)

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
#define MOD6_ADRST_10           ((uint8_t)0x02)
#define MOD6_ADRST_01           ((uint8_t)0x01)

#define MOD3_ITM_CLEAR          ((uint8_t)0x03)

#define MOD2_ADCH_CLEAR         ((uint8_t)0xF0)
#define MOD2_HPADCH_CLEAR       ((uint8_t)0x0F)

#define MOD1_ADHWE_CLEAR        ((uint8_t)0xEE)
#define MOD1_ADHWE_SET          ((uint8_t)0x01)
#define MOD1_ADHWS_CLEAR        ((uint8_t)0xED)
#define MOD1_HPADHWE_CLEAR      ((uint8_t)0xEB)
#define MOD1_HPADHWE_SET        ((uint8_t)0x04)
#define MOD1_HPADHWS_CLEAR      ((uint8_t)0xE7)

#define MOD5_BUSY_MASK          ((uint8_t)0x05)

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
  * @brief  Software reset ADC.
  * @param  None.
  * @retval None.
  */
void ADC_SWReset(void)
{
    ADC_SetVref(ENABLE);
    TSB_AD->MOD6 = MOD6_ADRST_10;
    TSB_AD->MOD6 = MOD6_ADRST_01;
}

/**
  * @brief  Set AD sample hold time and prescaler clock.
  * @param  Sample_HoldTime: Select the AD sample hold time.
  *   This parameter can be one of the following values:
  *   ADC_CONVERSION_CLK_10, ADC_CONVERSION_CLK_20,
  *   ADC_CONVERSION_CLK_30, ADC_CONVERSION_CLK_40,
  *   ADC_CONVERSION_CLK_80.
  * @param  Prescaler_Output: Select the AD prescaler clock.
  *   This parameter can be one of the following values:
  *   ADC_FC_DIVIDE_LEVEL_1, ADC_FC_DIVIDE_LEVEL_2,
  *   ADC_FC_DIVIDE_LEVEL_4, ADC_FC_DIVIDE_LEVEL_8.
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
  * @brief  Start AD conversion.
  * @param  None.
  * @retval None.
  */
void ADC_Start(void)
{
    /* Set ADMOD0<ADS> = 1 to start AD conversion */
    TSB_AD_MOD0_ADS = 1U;
}

/**
  * @brief  Enable or disable ADC scan mode.
  * @param  NewState: Specify ADC scan mode state.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetScanMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD3<SCAN> */
    TSB_AD_MOD3_SCAN = NewState;
}

/**
  * @brief  Enable or disable ADC repeat mode.
  * @param  NewState: Specify ADC repeat mode state.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetRepeatMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD3<REPEAT> */
    TSB_AD_MOD3_REPEAT = NewState;
}

/**
  * @brief  Set ADC interrupt mode in fixed channel repeat conversion mode.
  * @param  INTMode: Specify AD conversion interrupt mode.
  *   This parameter can be one of the following values:
  *   ADC_INT_SINGLE,       ADC_INT_CONVERSION_2,
  *   ADC_INT_CONVERSION_3, ADC_INT_CONVERSION_4,
  *   ADC_INT_CONVERSION_5, ADC_INT_CONVERSION_6,
  *   ADC_INT_CONVERSION_7, ADC_INT_CONVERSION_8.
  * @retval None.
  */
void ADC_SetINTMode(uint8_t INTMode)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INT_MODE(INTMode));
    /* Set ADMOD3<ITM[2:0]> */
    tmp = TSB_AD->MOD3;
    tmp &= MOD3_ITM_CLEAR;
    tmp |= INTMode;
    TSB_AD->MOD3 = tmp;
}

/**
  * @brief  Set ADC input channel.
  * @param  InputChannel: Analog input channel.
  *   This parameter can be one of the following values:
  *   ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *   ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *   ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  *   ADC_AN_12, ADC_AN_13, ADC_AN_14.
  * @retval None.
  */
void ADC_SetInputChannel(uint8_t InputChannel)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INPUT_CHANNEL(InputChannel));
    /* Set ADMOD2<ADCH[3:0]> */
    tmp = TSB_AD->MOD2;
    tmp &= MOD2_ADCH_CLEAR;
    tmp |= InputChannel;
    TSB_AD->MOD2 = tmp;
}

/**
  * @brief  Set ADC scan channel.
  * @param  StartChannel: Specify the start channel to be scanned.
  *   This parameter can be one of the following values:
  *   ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *   ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *   ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  *   ADC_AN_12, ADC_AN_13, ADC_AN_14.
  * @param  Range: Specify the range of assignable channel scan value.
  *   This parameter can be one of the following values:
  *   1 to 15.
  * @retval None.
  */
void ADC_SetScanChannel(uint8_t StartChannel, uint8_t Range)
{
    /* Check the parameters */
    assert_param(IS_ADC_SCAN_CHANNEL(StartChannel, Range));
    TSB_AD->MOD4 = (uint32_t) (StartChannel | ((Range - 1U) << 4U));
}

/**
  * @brief  Control AVREFH-AVREFL current.
  * @param  VrefCtrl: Specify how to apply AVREFH-AVREFL current.
  *   This parameter can be one of the following values:
  *   ADC_APPLY_VREF_IN_CONVERSION or ADC_APPLY_VREF_AT_ANY_TIME.
  * @retval None.
  */
void ADC_SetVrefCut(uint8_t VrefCtrl)
{
    /* Check the parameters */
    assert_param(IS_ADC_VREF_CTRL(VrefCtrl));
    /* Set ADMOD1<RCUT> */
    TSB_AD_MOD1_RCUT = VrefCtrl;
}

/**
  * @brief  Set ADC operation in IDLE mode.
  * @param  NewState: Specify ADC operation state in IDLE mode.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetIdleMode(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD1<I2AD> */
    TSB_AD_MOD1_I2AD = NewState;
}

/**
  * @brief  Set ADC VREF application.
  * @param  NewState: Specify ADC Vref application state.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetVref(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Set ADMOD1<VREFON> */
    TSB_AD_MOD1_VREFON = NewState;
}

/**
  * @brief  Select ADC top-priority conversion analog input channel.
  * @param  TopInputChannel: Analog input channel for top-priority conversion.
  *   This parameter can be one of the following values:
  *   ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *   ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *   ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  *   ADC_AN_12, ADC_AN_13, ADC_AN_14.
  * @retval None.
  */
void ADC_SetInputChannelTop(uint8_t TopInputChannel)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_INPUT_CHANNEL(TopInputChannel));
    /* Set ADMOD2<HPADCH[3:0]> */
    tmp = TSB_AD->MOD2;
    tmp &= MOD2_HPADCH_CLEAR;
    tmp |= ((uint32_t) TopInputChannel << 4U);
    TSB_AD->MOD2 = tmp;
}

/**
  * @brief  Start top-priority AD conversion.
  * @param  None.
  * @retval None.
  */
void ADC_StartTopConvert(void)
{
    /* Set ADMOD0<HPADS> = 1 to start top-priority AD conversion */
    TSB_AD_MOD0_HPADS = 1U;
}

/**
  * @brief  Enable or disable the specified ADC monitor module.
  * @param  ADCMPx: Select which compare control register will be used.
  *   This parameter can be one of the following values:
  *   ADC_CMPCR_0 or ADC_CMPCR_1.
  * @param  NewState: Specify ADC monitor function state.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetMonitor(ADC_CMPCRx ADCMPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_CMPCRx(ADCMPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (ADCMPx == ADC_CMPCR_0) {
        /* Set ADCMPCR0<CMP0EN> */
        TSB_AD_CMPCR0_CMP0EN = NewState;
    } else {
        /* Set ADCMPCR1<CMP1EN> */
        TSB_AD_CMPCR1_CMP1EN = NewState;
    }
}

/**
  * @breif  Configure the specified ADC monitor module.
  * @param  ADCMPx: Select which compare control register will be used.
  *   This parameter can be one of the following values:
  *   ADC_CMPCR_0 or ADC_CMPCR_1.
  * @param  Monitor: The structure containing ADC monitor configuration.
  * @retval None.
  */
void ADC_ConfigMonitor(ADC_CMPCRx ADCMPx, ADC_MonitorTypeDef * Monitor)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_CMPCRx(ADCMPx));
    assert_param(IS_POINTER_NOT_NULL(Monitor));
    assert_param(IS_ADC_INPUT_CHANNEL(Monitor->CmpChannel));
    assert_param(IS_ADC_CMPCNT(Monitor->CmpCnt));
    assert_param(IS_ADC_CMPCONDITION(Monitor->Condition));
    assert_param(IS_ADC_CMPMODE(Monitor->CntMode));
    assert_param(IS_ADC_CMPVALUE_12BIT(Monitor->CmpValue));

    tmp |= (uint32_t) (Monitor->CmpChannel);
    tmp |= (uint32_t) (Monitor->Condition) << 4U;
    tmp |= (uint32_t) (Monitor->CntMode) << 5U;
    tmp |= (uint32_t) (Monitor->CmpCnt - 1U) << 8U;

    if (ADCMPx == ADC_CMPCR_0) {
        TSB_AD->CMPCR0 = tmp;
        TSB_AD->CMP0 = Monitor->CmpValue;
    } else {
        TSB_AD->CMPCR1 = tmp;
        TSB_AD->CMP1 = Monitor->CmpValue;
    }
}

/**
  * @brief  Set hardware trigger for normal AD conversion.
  * @param  HwSource: Hardware source for activating normal AD conversion.
  *   This parameter can be one of the following values:
  *   ADC_EXT_TRG or ADC_MATCH_TB5RG0.
  * @param   NewState: Specify state of hardware source for activating normal AD conversion.
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
    /* Set ADMOD1<ADHWS> */
    tmp = TSB_AD->MOD1;
    tmp &= MOD1_ADHWS_CLEAR;
    tmp |= HwSource;
    /* Set ADMOD1<ADHWE> */
    if (NewState == ENABLE) {
        tmp |= MOD1_ADHWE_SET;
    } else {
        tmp &= MOD1_ADHWE_CLEAR;
    }
    TSB_AD->MOD1 = tmp;
}

/**
  * @brief  Set hardware trigger for top-priority AD conversion.
  * @param  HwSource: Hardware source for activating top-priority AD conversion.
  *   This parameter can be one of the following values:
  *   ADC_EXT_TRG or ADC_MATCH_TB4RG0.
  * @param   NewState: Specify state of hardware source for activating top-priority AD conversion.
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
    /* Set ADMOD1<HPADHWS> */
    tmp = TSB_AD->MOD1;
    tmp &= MOD1_HPADHWS_CLEAR;
    tmp |= HwSource;
    /* Set ADMOD1<HPADHWE> */
    if (NewState == ENABLE) {
        tmp |= MOD1_HPADHWE_SET;
    } else {
        tmp &= MOD1_HPADHWE_CLEAR;
    }
    TSB_AD->MOD1 = tmp;
}

/**
  * @brief  Read AD conversion completion flag (normal and top-priority).
  * @param  None.
  * @retval A union with the state of AD conversion.
  */
ADC_State ADC_GetConvertState(void)
{
    ADC_State retval = { 0U };
    retval.All = TSB_AD->MOD5;
    return retval;
}

/**
  * @brief  Read AD conversion result.
  * @param  ADREGx: ADC result register.
  *   This parameter can be one of the following values:
  *   ADC_REG_00, ADC_REG_01, ADC_REG_02, ADC_REG_03,
  *   ADC_REG_04, ADC_REG_05, ADC_REG_06, ADC_REG_07, 
  *   ADC_REG_08, ADC_REG_09, ADC_REG_10, ADC_REG_11,
  *   ADC_REG_12, ADC_REG_13, ADC_REG_14, ADC_REG_SP.
  * @retval A union with AD result and 3 bits of extra information.
  */
ADC_Result ADC_GetConvertResult(uint8_t ADREGx)
{
    ADC_Result retval = { 0U };

    /* Check the parameters */
    assert_param(IS_ADC_REG(ADREGx));
    /* Read ADREGx to get ADC result */
    switch (ADREGx) {
    case ADC_REG_00:
        retval.All = TSB_AD->REG00;
        break;
    case ADC_REG_01:
        retval.All = TSB_AD->REG01;
        break;
    case ADC_REG_02:
        retval.All = TSB_AD->REG02;
        break;
    case ADC_REG_03:
        retval.All = TSB_AD->REG03;
        break;
    case ADC_REG_04:
        retval.All = TSB_AD->REG04;
        break;
    case ADC_REG_05:
        retval.All = TSB_AD->REG05;
        break;
    case ADC_REG_06:
        retval.All = TSB_AD->REG06;
        break;
    case ADC_REG_07:
        retval.All = TSB_AD->REG07;
        break;
    case ADC_REG_08:
        retval.All = TSB_AD->REG08;
        break;
    case ADC_REG_09:
        retval.All = TSB_AD->REG09;
        break;
    case ADC_REG_10:
        retval.All = TSB_AD->REG10;
        break;
    case ADC_REG_11:
        retval.All = TSB_AD->REG11;
        break;
    case ADC_REG_12:
        retval.All = TSB_AD->REG12;
        break;
    case ADC_REG_13:
        retval.All = TSB_AD->REG13;
        break;
    case ADC_REG_14:
        retval.All = TSB_AD->REG14;
        break;
    case ADC_REG_SP:
        retval.All = TSB_AD->REGSP;
        break;
    default:                   /* Do nothing */
        break;
    }

    return retval;
}

/**
  * @brief  Enable or disable ADC clock.
  * @param  NewState: Specify ADC clock supply state.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetClkSupply(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Check ADC is not during conversion */
    while (TSB_AD->MOD5 & MOD5_BUSY_MASK) {
        __NOP();
    }
    /* Set CGSYSCR<FCSTOP>  */
    if (NewState == ENABLE) {
        TSB_CG_SYSCR_FCSTOP = 0U;
    } else {
        TSB_CG_SYSCR_FCSTOP = 1U;
    }
}

/**
  * @breif  Enable or disable DMA activation factor for normal or top-priority AD conversion.
  * @param  DMAReq: Specify AD conversion DMA request type.
  *   This parameter can be one of the following values:
  *   ADC_DMA_REQ_NORMAL: normal AD conversion,
  *   ADC_DMA_REQ_TOP: top-priority AD conversion.
  * @param  NewState: Specify AD conversion DMA activation factor.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetDMAReq(uint8_t DMAReq, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_DMA_REQ(NewState));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* Normal or top-priority AD conversion */
    if (DMAReq == ADC_DMA_REQ_NORMAL) {
        TSB_AD_MOD7_INTADDMA = NewState;
    } else {
        TSB_AD_MOD7_INTADHPDMA = NewState;
    }
}

/** @} */
/* End of group ADC_Exported_Functions */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_ADC_H) */
