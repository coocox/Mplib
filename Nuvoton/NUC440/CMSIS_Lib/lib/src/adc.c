/**************************************************************************//**
 * @file     adc.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 series ADC driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "adc.h"
#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_ADC_Driver ADC Driver
  @{
*/


/** @addtogroup NUC400_ADC_EXPORTED_FUNCTIONS ADC Exported Functions
  @{
*/

/**
  * @brief This API configures ADC module to be ready for convert the input from selected channel
  * @param[in] adc Base address of ADC module
  * @param[in] u32InputMode Input mode (single-end/differential). Valid values are:
  *                 - \ref ADC_INPUT_MODE_SINGLE_END
  *                 - \ref ADC_INPUT_MODE_DIFFERENTIAL
  * @param[in] u32OpMode Operation mode (single/single cycle/continuous). Valid values are:
  *                 - \ref ADC_OPERATION_MODE_SINGLE
  *                 - \ref ADC_OPERATION_MODE_SINGLE_CYCLE
  *                 - \ref ADC_OPERATION_MODE_CONTINUOUS
  * @param[in] u32ChMask Channel enable bit. Each bit corresponds to a input channel. Bit 0 is channel 0, bit 1 is channel 1...
  * @return  None
  * @note This API does not turn on ADC power nor does trigger ADC conversion
  */
void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask)
{

    ADC->CR |= u32InputMode << ADC_CR_DIFFEN_Pos;
    ADC->CR |= u32OpMode << ADC_CR_ADC_OPMODE_Pos;
    ADC->CHER  = (ADC->CHER & ~ADC_CHER_CHEN_Msk) | u32ChMask;
    return;
}

/**
  * @brief Disable ADC module
  * @param[in] adc Base address of ADC module
  * @return None
  */
void ADC_Close(ADC_T *adc)
{
    SYS->IPRSTC2 |= SYS_IPRSTC2_ADC_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_ADC_RST_Msk;
    return;

}

/**
  * @brief Configure the hardware trigger condition and enable hardware trigger
  * @param[in] adc Base address of ADC module
  * @param[in] u32Source Decides the hardware trigger source. Valid values are:
  *                 - \ref ADC_TRIGGER_BY_EXT_PIN
  *                 - \ref ADC_TRIGGER_BY_PWM
  * @param[in] u32Param While ADC trigger by PWM, this parameter is used to set the delay between PWM
  *                     trigger and ADC conversion. Valid values are from 0 ~ 0xFF, and actual delay
  *                     time is (4 * u32Param * HCLK). While ADC trigger by external pin, this parameter
  *                     is used to set trigger condition. Valid values are:
  *                 - \ref ADC_LOW_LEVEL_TRIGGER
  *                 - \ref ADC_HIGH_LEVEL_TRIGGER
  *                 - \ref ADC_FALLING_EDGE_TRIGGER
  *                 - \ref ADC_RISING_EDGE_TRIGGER
  * @return None
  */
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param)
{
    ADC->CR &= ~(ADC_TRIGGER_BY_PWM | ADC_RISING_EDGE_TRIGGER | ADC_CR_HWTRG_EN_Msk);
    if(u32Source == ADC_TRIGGER_BY_EXT_PIN) {
        ADC->CR &= ~(ADC_CR_HWTRG_SRC_Msk | ADC_CR_PINTRG_COND_Msk);
        ADC->CR |= u32Source | (u32Param << ADC_CR_PINTRG_COND_Pos) | ADC_CR_HWTRG_EN_Msk;
    } else {
        ADC->CR &= ~(ADC_CR_HWTRG_SRC_Msk | ADC_CR_PWMTRG_DT_Msk);
        ADC->CR |= u32Source | (u32Param << ADC_CR_PWMTRG_DT_Pos) | ADC_CR_HWTRG_EN_Msk;
    }

    return;
}

/**
  * @brief Disable hardware trigger ADC function.
  * @param[in] adc Base address of ADC module
  * @return None
  */
void ADC_DisableHWTrigger(ADC_T *adc)
{
    ADC->CR &= ~(ADC_TRIGGER_BY_PWM | ADC_RISING_EDGE_TRIGGER | ADC_CR_HWTRG_EN_Msk);
    return;
}

/**
  * @brief Enable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask  The combination of interrupt status bits listed below. Each bit
  *                     corresponds to a interrupt status. This parameter decides which
  *                     interrupts will be enabled.
  *                     - \ref ADC_ADF_INT
  *                     - \ref ADC_CMP0_INT
  *                     - \ref ADC_CMP1_INT
  * @return None
  */
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask)
{
    if(u32Mask & ADC_ADF_INT)
        ADC->CR |= ADC_CR_ADC_IE_Msk;
    if(u32Mask & ADC_CMP0_INT)
        ADC->CMPR0 |= ADC_CMPR_CMPIE_Msk;
    if(u32Mask & ADC_CMP1_INT)
        ADC->CMPR1 |= ADC_CMPR_CMPIE_Msk;

    return;
}

/**
  * @brief Disable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask  The combination of interrupt status bits listed below. Each bit
  *                     corresponds to a interrupt status. This parameter decides which
  *                     interrupts will be disabled.
  *                     - \ref ADC_ADF_INT
  *                     - \ref ADC_CMP0_INT
  *                     - \ref ADC_CMP1_INT
  * @return None
  */
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask)
{
    if(u32Mask & ADC_ADF_INT)
        ADC->CR &= ~ADC_CR_ADC_IE_Msk;
    if(u32Mask & ADC_CMP0_INT)
        ADC->CMPR0 &= ~ADC_CMPR_CMPIE_Msk;
    if(u32Mask & ADC_CMP1_INT)
        ADC->CMPR1 &= ~ADC_CMPR_CMPIE_Msk;

    return;
}



/*@}*/ /* end of group NUC400_ADC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_ADC_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
