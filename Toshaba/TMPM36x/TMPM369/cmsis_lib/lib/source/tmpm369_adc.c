/**
 *******************************************************************************
 * @file    tmpm369_adc.c
 * @brief   This file provides API functions for ADC driver.
 * @version V2.0.2.1
 * @date    2011/09/07
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
#include "tmpm369_adc.h"

#if defined(__TMPM369_ADC_H)

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
#define MOD6_ADRST_10           ((uint32_t)0x02U)
#define MOD6_ADRST_01           ((uint32_t)0x01U)

#define MOD3_ITM_CLEAR          ((uint32_t)0x03U)

#define MOD2_ADCH_CLEAR         ((uint32_t)0xF0U)
#define MOD2_HPADCH_CLEAR       ((uint32_t)0x0FU)

#define MOD1_ADHWE_CLEAR        ((uint32_t)0xEEU)
#define MOD1_ADHWE_SET          ((uint32_t)0x01U)
#define MOD1_ADHWS_CLEAR        ((uint32_t)0xEDU)
#define MOD1_HPADHWE_CLEAR      ((uint32_t)0xEBU)
#define MOD1_HPADHWE_SET        ((uint32_t)0x04U)
#define MOD1_HPADHWS_CLEAR      ((uint32_t)0xE7U)

#define MOD5_BUSY_MASK          ((uint32_t)0x05U)

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
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @retval None.
  */
void ADC_SWReset(TSB_AD_TypeDef * ADx)
{
    assert_param(IS_ADC_UNIT(ADx));

    ADC_SetVref(ADx, ENABLE);
    ADx->MOD6 = MOD6_ADRST_10;
    ADx->MOD6 = MOD6_ADRST_01;
}

/**
  * @brief  Set AD sample hold time and prescaler clock.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB 
  * @param  Sample_HoldTime: Select the AD sample hold time.
  *   This parameter can be one of the following values:
  *     ADC_CONVERSION_CLK_10, ADC_CONVERSION_CLK_20,
  *     ADC_CONVERSION_CLK_30, ADC_CONVERSION_CLK_40,
  *     ADC_CONVERSION_CLK_80, ADC_CONVERSION_CLK_160,
  *     ADC_CONVERSION_CLK_320
  * @param  Prescaler_Output: Select the AD prescaler clock.
  *   This parameter can be one of the following values:
  *     ADC_FC_DIVIDE_LEVEL_1, ADC_FC_DIVIDE_LEVEL_2,
  *     ADC_FC_DIVIDE_LEVEL_4, ADC_FC_DIVIDE_LEVEL_8.
  *     ADC_FC_DIVIDE_LEVEL_16.  
  * @retval None.
  */
void ADC_SetClk(TSB_AD_TypeDef * ADx, uint32_t Sample_HoldTime, uint32_t Prescaler_Output)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_HOLD_TIME(Sample_HoldTime));
    assert_param(IS_ADC_PRESCALER(Prescaler_Output));

    /* Set ADCLK */
    ADx->CLK = Sample_HoldTime + Prescaler_Output;
}

/**
  * @brief  Start AD conversion.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB
  * @retval None.
  */
void ADC_Start(TSB_AD_TypeDef * ADx)
{
    assert_param(IS_ADC_UNIT(ADx));

    /* Set ADMOD0<ADS> = 1 to start AD conversion */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD0_ADS = 1U;
    } else {
        TSB_ADB_MOD0_ADS = 1U;
    }
}

/**
  * @brief  Enable or disable ADC scan mode.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  NewState: Specify ADC scan mode state.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetScanMode(TSB_AD_TypeDef * ADx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD3<SCAN> */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD3_SCAN = NewState;
    } else {
        TSB_ADB_MOD3_SCAN = NewState;
    }

}

/**
  * @brief  Enable or disable ADC repeat mode.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  NewState: Specify ADC repeat mode state.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetRepeatMode(TSB_AD_TypeDef * ADx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD3<REPEAT> */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD3_REPEAT = NewState;
    } else {
        TSB_ADB_MOD3_REPEAT = NewState;
    }
}

/**
  * @brief  Set ADC interrupt mode in fixed channel repeat conversion mode.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  INTMode: Specify AD conversion interrupt mode.
  *   This parameter can be one of the following values:
  *     ADC_INT_SINGLE,       ADC_INT_CONVERSION_2,
  *     ADC_INT_CONVERSION_3, ADC_INT_CONVERSION_4,
  *     ADC_INT_CONVERSION_5, ADC_INT_CONVERSION_6,
  *     ADC_INT_CONVERSION_7, ADC_INT_CONVERSION_8.
  * @retval None.
  */
void ADC_SetINTMode(TSB_AD_TypeDef * ADx, uint32_t INTMode)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_INT_MODE(INTMode));

    /* Set ADMOD3<ITM[2:0]> */
    tmp = ADx->MOD3;
    tmp &= MOD3_ITM_CLEAR;
    tmp |= INTMode;
    ADx->MOD3 = tmp;
}

/**
  * @brief  Set ADC input channel.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  InputChannel: Analog input channel.
  *   This parameter can be one of the following values:
  *    When ADx == TSB_ADA:
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *    When ADx == TSB_ADB:  
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *     ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *     ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  * @retval None.
  */
void ADC_SetInputChannel(TSB_AD_TypeDef * ADx, ADC_AINx InputChannel)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    if (ADx == TSB_ADA) {
        assert_param(IS_ADCA_INPUT_CHANNEL(InputChannel));
    } else {
        assert_param(IS_ADCB_INPUT_CHANNEL(InputChannel));
    }

    /* Set ADMOD2<ADCH[3:0]> */
    tmp = ADx->MOD2;
    tmp &= MOD2_ADCH_CLEAR;
    tmp |= InputChannel;
    ADx->MOD2 = tmp;
}

/**
  * @brief  Set ADC scan channel.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  StartChannel: Specify the start channel to be scanned.
  *   This parameter can be one of the following values:
  *    When ADx == TSB_ADA:
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *    When ADx == TSB_ADB:  
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *     ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *     ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  * @param  Range: Specify the range of assignable channel scan value.
  *   This parameter can be one of the following values:
  *    When ADx == TSB_ADA:
  *      1, 2, 3, 4. (note: StartChannel + Range  <= 4 )
  *    When ADx == TSB_ADB:   
  *      1, 2, .... 11, 12  (note: StartChannel + Range  <= 12 )
  * @retval None.
  */
void ADC_SetScanChannel(TSB_AD_TypeDef * ADx, ADC_AINx StartChannel, uint32_t Range)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    if (ADx == TSB_ADA) {
        assert_param(IS_ADCA_SCAN_CHANNEL(StartChannel, Range));
    } else {
        assert_param(IS_ADCB_SCAN_CHANNEL(StartChannel, Range));
    }

    ADx->MOD4 = (uint32_t) (StartChannel | ((Range - 1U) << 4U));
}

/**
  * @brief  Control AVREFH-AVREFL current.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  VrefCtrl: Specify how to apply AVREFH-AVREFL current.
  *   This parameter can be one of the following values:
  *      ADC_APPLY_VREF_IN_CONVERSION or ADC_APPLY_VREF_AT_ANY_TIME.
  * @retval None.
  */
void ADC_SetVrefCut(TSB_AD_TypeDef * ADx, uint32_t VrefCtrl)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_VREF_CTRL(VrefCtrl));

    /* Set ADMOD1<RCUT> */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD1_RCUT = VrefCtrl;
    } else {
        TSB_ADB_MOD1_RCUT = VrefCtrl;
    }

}

/**
  * @brief  Set ADC operation in IDLE mode.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  NewState: Specify ADC operation state in IDLE mode.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetIdleMode(TSB_AD_TypeDef * ADx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD1<I2AD> */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD1_I2AD = NewState;
    } else {
        TSB_ADB_MOD1_I2AD = NewState;
    }

}

/**
  * @brief  Set ADC VREF application.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  NewState: Specify ADC Vref application state.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetVref(TSB_AD_TypeDef * ADx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD1<VREFON> */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD1_DACON = NewState;
    } else {
        TSB_ADB_MOD1_DACON = NewState;
    }

}

/**
  * @brief  Select ADC top-priority conversion analog input channel.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  TopInputChannel: Analog input channel for top-priority conversion.
  *   This parameter can be one of the following values:
  *    When ADx == TSB_ADA:
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *    When ADx == TSB_ADB:  
  *     ADC_AN_00, ADC_AN_01, ADC_AN_02, ADC_AN_03,
  *     ADC_AN_04, ADC_AN_05, ADC_AN_06, ADC_AN_07,
  *     ADC_AN_08, ADC_AN_09, ADC_AN_10, ADC_AN_11,
  * @retval None.
  */
void ADC_SetInputChannelTop(TSB_AD_TypeDef * ADx, ADC_AINx TopInputChannel)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    if (ADx == TSB_ADA) {
        assert_param(IS_ADCA_INPUT_CHANNEL(TopInputChannel));
    } else {
        assert_param(IS_ADCB_INPUT_CHANNEL(TopInputChannel));
    }

    /* Set ADMOD2<HPADCH[3:0]> */
    tmp = ADx->MOD2;
    tmp &= MOD2_HPADCH_CLEAR;
    tmp |= ((uint32_t) TopInputChannel << 4U);
    ADx->MOD2 = tmp;
}

/**
  * @brief  Start top-priority AD conversion.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB
  * @retval None.
  */
void ADC_StartTopConvert(TSB_AD_TypeDef * ADx)
{
    assert_param(IS_ADC_UNIT(ADx));

    /* Set ADMOD0<HPADS> = 1 to start top-priority AD conversion */
    if (ADx == TSB_ADA) {
        TSB_ADA_MOD0_HPADS = 1U;
    } else {
        TSB_ADB_MOD0_HPADS = 1U;
    }

}

/**
  * @brief  Enable or disable the specified ADC monitor module.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  ADCMPx: Select which compare control register will be used.
  *   This parameter can be one of the following values:
  *     ADC_CMPCR_0 or ADC_CMPCR_1.
  * @param  NewState: Specify ADC monitor function state.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetMonitor(TSB_AD_TypeDef * ADx, ADC_CMPCRx ADCMPx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_CMPCRx(ADCMPx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (ADCMPx == ADC_CMPCR_0) {
        /* Set ADCMPCR0<CMP0EN> */
        if (ADx == TSB_ADA) {
            TSB_ADA_CMPCR0_CMP0EN = NewState;
        } else {
            TSB_ADB_CMPCR0_CMP0EN = NewState;
        }
    } else {
        /* Set ADCMPCR1<CMP1EN> */
        if (ADx == TSB_ADA) {
            TSB_ADA_CMPCR1_CMP1EN = NewState;
        } else {
            TSB_ADB_CMPCR1_CMP1EN = NewState;
        }
    }
}

/**
  * @brief  Configure the specified ADC monitor module.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  ADCMPx: Select which compare control register will be used.
  *   This parameter can be one of the following values:
  *   ADC_CMPCR_0 or ADC_CMPCR_1.
  * @param  Monitor: The structure containing ADC monitor configuration.
  * @retval None.
  */
void ADC_ConfigMonitor(TSB_AD_TypeDef * ADx, ADC_CMPCRx ADCMPx, ADC_MonitorTypeDef * Monitor)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_CMPCRx(ADCMPx));
    assert_param(IS_POINTER_NOT_NULL(Monitor));
    if (ADx == TSB_ADA) {
        assert_param(IS_ADCA_INPUT_CHANNEL(Monitor->CmpChannel));
    } else {
        assert_param(IS_ADCB_INPUT_CHANNEL(Monitor->CmpChannel));
    }
    assert_param(IS_ADC_CMPCNT(Monitor->CmpCnt));
    assert_param(IS_ADC_CMPCONDITION(Monitor->Condition));
    assert_param(IS_ADC_CMPMODE(Monitor->CntMode));
    assert_param(IS_ADC_CMPVALUE_12BIT(Monitor->CmpValue));

    tmp |= (uint32_t) (Monitor->CmpChannel);
    tmp |= (uint32_t) (Monitor->Condition) << 4U;
    tmp |= (uint32_t) (Monitor->CntMode) << 5U;
    tmp |= (uint32_t) (Monitor->CmpCnt - 1U) << 8U;

    if (ADCMPx == ADC_CMPCR_0) {
        ADx->CMPCR0 = tmp;
        ADx->CMP0 = Monitor->CmpValue;
    } else {
        ADx->CMPCR1 = tmp;
        ADx->CMP1 = Monitor->CmpValue;
    }
}

/**
  * @brief  Set hardware trigger for normal AD conversion.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  HWSrc: Hardware source for activating normal AD conversion.
  *   This parameter can be one of the following values:
  *     ADC_INTERLEAVE.
  * @param  NewState: Specify state of hardware source for activating normal AD conversion.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetHWTrg(TSB_AD_TypeDef * ADx, uint32_t HWSrc, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_INTERLEAVE(HWSrc));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD1<ADHWS> */
    tmp = ADx->MOD1;
    tmp &= MOD1_ADHWS_CLEAR;
    tmp |= HWSrc;

    /* Set ADMOD1<ADHWE> */
    if (NewState == ENABLE) {
        tmp |= MOD1_ADHWE_SET;
    } else {
        tmp &= MOD1_ADHWE_CLEAR;
    }

    ADx->MOD1 = tmp;
}

/**
  * @brief  Set hardware trigger for top-priority AD conversion.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  HWSrc: Hardware source for activating top-priority AD conversion.
  *   This parameter can be one of the following values:
  *     ADC_INTERLEAVE
  * @param   NewState: Specify state of hardware source for activating top-priority AD conversion.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetHWTrgTop(TSB_AD_TypeDef * ADx, uint32_t HWSrc, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    assert_param(IS_ADC_INTERLEAVE_TOP(HWSrc));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set ADMOD1<HPADHWS> */
    tmp = ADx->MOD1;
    tmp &= MOD1_HPADHWS_CLEAR;
    tmp |= HWSrc;

    /* Set ADMOD1<HPADHWE> */
    if (NewState == ENABLE) {
        tmp |= MOD1_HPADHWE_SET;
    } else {
        tmp &= MOD1_HPADHWE_CLEAR;
    }

    ADx->MOD1 = tmp;
}

/**
  * @brief  Read AD conversion completion/busy flag (normal and top-priority).
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB
  * @retval A union with the state of AD conversion.
  */
ADC_State ADC_GetConvertState(TSB_AD_TypeDef * ADx)
{
    ADC_State retval = { 0U };

    assert_param(IS_ADC_UNIT(ADx));

    retval.All = ADx->MOD5;
    return retval;
}

/**
  * @brief  Read AD conversion result.
  * @param  ADx: Select ADC unit.
  *   This parameter can be one of the following values:
  *     TSB_ADA, TSB_ADB  
  * @param  ADREGx: ADC result register.
  *   This parameter can be one of the following values:
  *    When ADx == TSB_ADA:
  *     ADC_REG00, ADC_REG01, ADC_REG02, ADC_REG03,
  *     ADC_REG04, ADC_REG05, ADC_REG06, ADC_REG07,
  *     ADC_REGSP.
  *    When ADx == TSB_ADB:  
  *     ADC_REG00, ADC_REG01, ADC_REG02, ADC_REG03,
  *     ADC_REG04, ADC_REG05, ADC_REG06, ADC_REG07, 
  *     ADC_REG08, ADC_REG09, ADC_REG10, ADC_REG11,
  *     ADC_REGSP.
  * @retval A union with AD result and 2 bits of extra information.
  */
ADC_Result ADC_GetConvertResult(TSB_AD_TypeDef * ADx, ADC_REGx ADREGx)
{
    ADC_Result retval = { 0U };
    uint32_t tmpAddr = 0U;

    /* Check the parameters */
    assert_param(IS_ADC_UNIT(ADx));
    if (ADx == TSB_ADA) {
        assert_param(IS_ADCA_REG(ADREGx));
    } else {
        assert_param(IS_ADCB_REG(ADREGx));
    }

    if (ADREGx == ADC_REG_SP) {
        retval.All = ADx->REGSP;
    } else {
        tmpAddr = (uint32_t) (&ADx->REG00);
        tmpAddr += (0x4U * (uint32_t) ADREGx);
        retval.All = *((uint32_t *) (tmpAddr));
    }

    return retval;
}

/**
  * @brief  Enable or disable ADC clock.
  * @param  NewState: Specify ADC clock supply state.
  *   This parameter can be one of the following values:
  *     ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetClkSupply(FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Check ADC is not during conversion */
    do {
        tmp = TSB_ADA->MOD5 & MOD5_BUSY_MASK;
        tmp |= (TSB_ADB->MOD5 & MOD5_BUSY_MASK);
    } while (tmp);

    /* Set CGSYSCR<FCSTOP>  */
    if (NewState == ENABLE) {
        TSB_CG_SYSCR_FCSTOP = 0U;
    } else {
        TSB_CG_SYSCR_FCSTOP = 1U;
    }
}

/**
  * @brief  Enable/disable the trigger function in dual unit mode.
  * @param  NewState: Enable or disable the trigger function.
  *   This parameter can be one of the following values:
  *    ENABLE or DISABLE
  * @retval None.
  */
void ADC_DualUnitSetTrg(FunctionalState NewState)
{
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    TSB_ADCI_VM02_TRGAEN = NewState;
}

/**
  * @brief  Start a trigger output of ADCINTLV in dual unit mode.
  * @param  None.
  * @retval None.
  */
void ADC_DualUnitStartSWTrg(void)
{
    TSB_ADCI_VM01_SWATRG = 1U;
}


/**
  * @brief  Select control mode in dual mode.
  * @param  Mode: Select control mode in dual mode.
  *   This parameter can be one of the following values:
  *     ADC_DUALUNIT_TRG_START_MODE  or ADC_DUALUNIT_INTERLEAVE_MODE.
  * @retval None.
  */
void ADC_DualUnitSetCtrlMode(uint32_t Mode)
{
    assert_param(IS_ADC_DUALUNIT_CONTROL_MODE(Mode));

    TSB_ADCI_VM02_ADILV = Mode;
}



/**
  * @brief  Get the destination unit of the next trigger output in trigger start mode
  * @param  None
  * @retval The destination unit of the next trigger output in trigger start mode.
  *    This value can be one of the following values: 
  *       ADC_DUALUNIT_UNIT_A,  ADC_DUALUNIT_UNIT_B
  */
ADC_DualUnit_Unitx ADC_DualUnitGetNextTrgDst(void)
{
    ADC_DualUnit_Unitx tmp = ADC_DUALUNIT_UNIT_A;

    if (TSB_ADCI_VM02_TRGASTA) {
        tmp = ADC_DUALUNIT_UNIT_B;
    } else {
        /* Do nothing */
    }

    return tmp;
}


/**
  * @brief  Select a trigger input in dual unit mode.
  * @param  Trg: Select a trigger input in dual unit mode.
  *   This parameter can be one of the following values:
  *     ADC_DUALUNIT_SW,  ADC_DUALUNIT_EXT,  
  *     ADC_DUALUNIT_INTTB21, ADC_DUALUNIT_INTTB31, ADC_DUALUNIT_INTTB41, 
  *     ADC_DUALUNIT_INTTB51, ADC_DUALUNIT_INTTB61, ADC_DUALUNIT_INTTB71.
  * @retval None.
  */
void ADC_DualUnitSetTrgSrc(ADC_DualUnitTrg Trg)
{
    uint32_t tmp = 0U;
    assert_param(IS_ADC_DUALUNIT_TRG_INPUT(Trg));

    tmp = TSB_ADCI->VM02;
    tmp &= (uint32_t) (0x81U);  /* only keep bit7 and bit0 */
    tmp |= (uint32_t) Trg << 1U;

    TSB_ADCI->VM02 = tmp;
}


/**
  * @brief  Set the trigger start adjusting counter. 
  * @param  AdjustCnt: Set the trigger start adjusting counter.
  *   This parameter can be one of the following values:
  *    0x01 to 0xFF (The initial value is 0x27)
  * @retval None.
  */
void ADC_DualUnitSetAdjustingCnt(uint32_t AdjustCnt)
{
    assert_param(IS_ADC_DUALUNIT_ADJUST_COUNT(AdjustCnt));

    TSB_ADCI->VM03 = AdjustCnt;
}


/** @} */
/* End of group ADC_Exported_Functions */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM369_ADC_H) */
