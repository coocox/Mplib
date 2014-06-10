/**************************************************************************//**
 * @file     adc.h
 * @version  V1.00
 * $Revision: 10 $
 * $Date: 13/11/26 2:53p $
 * @brief    NUC400 series ADC driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_ADC_Driver ADC Driver
  @{
*/

/** @addtogroup NUC400_ADC_EXPORTED_CONSTANTS ADC Exported Constants
  @{
*/

#define ADC_CH_0_MASK                    (1UL << 0)                  /*!< ADC channel 0 mask */
#define ADC_CH_1_MASK                    (1UL << 1)                  /*!< ADC channel 1 mask */
#define ADC_CH_2_MASK                    (1UL << 2)                  /*!< ADC channel 2 mask */
#define ADC_CH_3_MASK                    (1UL << 3)                  /*!< ADC channel 3 mask */
#define ADC_CH_4_MASK                    (1UL << 4)                  /*!< ADC channel 4 mask */
#define ADC_CH_5_MASK                    (1UL << 5)                  /*!< ADC channel 5 mask */
#define ADC_CH_6_MASK                    (1UL << 6)                  /*!< ADC channel 6 mask */
#define ADC_CH_7_MASK                    (1UL << 7)                  /*!< ADC channel 7 mask */
#define ADC_CMP_LESS_THAN                (0UL)                       /*!< ADC compare condition less than */
#define ADC_CMP_GREATER_OR_EQUAL_TO      (ADC_CMPR_CMPCOND_Msk)      /*!< ADC compare condition greater or equal to */
#define ADC_TRIGGER_BY_EXT_PIN           (0UL)                       /*!< ADC trigger by STADC pin */
#define ADC_TRIGGER_BY_PWM               (ADC_CR_HWTRG_SRC_Msk)      /*!< ADC trigger by PWM events */
#define ADC_LOW_LEVEL_TRIGGER            (0UL)                       /*!< External pin low level trigger ADC */
#define ADC_HIGH_LEVEL_TRIGGER           (1UL)                       /*!< External pin high level trigger ADC */
#define ADC_FALLING_EDGE_TRIGGER         (2UL)                       /*!< External pin falling edge trigger ADC */
#define ADC_RISING_EDGE_TRIGGER          (3UL)                       /*!< External pin rising edge trigger ADC */
#define ADC_ADF_INT                      (ADC_SR0_ADC_IF_Msk)        /*!< ADC convert complete interrupt */
#define ADC_CMP0_INT                     (ADC_SR0_CMPIF0_Msk)        /*!< ADC comparator 0 interrupt */
#define ADC_CMP1_INT                     (ADC_SR0_CMPIF1_Msk)        /*!< ADC comparator 1 interrupt */
#define ADC_INPUT_MODE_SINGLE_END        (0UL)                       /*!< ADC input mode set to single end */
#define ADC_INPUT_MODE_DIFFERENTIAL      (1UL)                       /*!< ADC input mode set to differential */
#define ADC_OPERATION_MODE_SINGLE        (0UL)                       /*!< ADC operation mode set to single conversion */
#define ADC_OPERATION_MODE_SINGLE_CYCLE  (2UL)                       /*!< ADC operation mode set to single cycle scan */
#define ADC_OPERATION_MODE_CONTINUOUS    (3UL)                       /*!< ADC operation mode set to continuous scan */
#define ADC_DMODE_OUT_FORMAT_UNSIGNED    (0UL)                       /*!< ADC differential mode output format with unsigned */
#define ADC_DMODE_OUT_FORMAT_2COMPLEMENT (1UL)                       /*!< ADC differential mode output format with 2's complement */

/*@}*/ /* end of group NUC400_ADC_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_ADC_EXPORTED_FUNCTIONS ADC Exported Functions
  @{
*/

/**
  * @brief Get the latest ADC conversion data
  * @param[in] adc Base address of ADC module
  * @param[in] u32ChNum Channel number
  * @return  Latest ADC conversion data
  */
#define ADC_GET_CONVERSION_DATA(adc, u32ChNum) ( *(__IO uint32_t *)( &ADC->DR0 + (1*u32ChNum)) & ADC_DR_RSLT_Msk)

/**
  * @brief Return the user-specified interrupt flags
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask The combination of following interrupt status bits. Each bit corresponds to a interrupt status.
  *                     - \ref ADC_ADF_INT
  *                     - \ref ADC_CMP0_INT
  *                     - \ref ADC_CMP1_INT
  * @return  User specified interrupt flags
  */
#define ADC_GET_INT_FLAG(adc, u32Mask) (ADC->SR0 & (u32Mask))

/**
  * @brief This macro clear the selected interrupt status bits
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask The combination of following interrupt status bits. Each bit corresponds to a interrupt status.
  *                     - \ref ADC_ADF_INT
  *                     - \ref ADC_CMP0_INT
  *                     - \ref ADC_CMP1_INT
  * @return  None
  */
#define ADC_CLR_INT_FLAG(adc, u32Mask) (ADC->SR0 = (ADC->SR0 & ~(ADC_SR0_ADC_IF_Msk | \
                                                                       ADC_SR0_CMPIF0_Msk | \
                                                                       ADC_SR0_CMPIF1_Msk)) | (u32Mask))

/**
  * @brief Get the busy state of ADC
  * @param[in] adc Base address of ADC module
  * @return busy state of ADC
  * @retval 0 ADC is not busy
  * @retval 1 ADC is busy
  */
#define ADC_IS_BUSY(adc) (ADC->SR0 & ADC_SR0_BUSY_Msk ? 1 : 0)

/**
  * @brief Check if the ADC conversion data is over written or not
  * @param[in] adc Base address of ADC module
  * @param[in] u32ChNum Currently not used
  * @return Over run state of ADC data
  * @retval 0 ADC data is not overrun
  * @retval 1 ADC data us overrun
  */
#define ADC_IS_DATA_OVERRUN(adc, u32ChNum) (ADC->SR1 & ( 1 << (ADC_SR1_OVERRUN_Pos + u32ChNum)) ? 1 : 0)

/**
  * @brief Check if the ADC conversion data is valid or not
  * @param[in] adc Base address of ADC module
  * @param[in] u32ChNum Currently not used
  * @return Valid state of ADC data
  * @retval 0 ADC data is not valid
  * @retval 1 ADC data us valid
  */
#define ADC_IS_DATA_VALID(adc, u32ChNum) (ADC->SR1 & ( 1 << (ADC_SR1_VALID_Pos + u32ChNum)) ? 1 : 0)

/**
  * @brief Power down ADC module
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_POWER_DOWN(adc) (ADC->CR &= ~ADC_CR_ADC_EN_Msk)

/**
  * @brief Power on ADC module
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_POWER_ON(adc) (ADC->CR |= ADC_CR_ADC_EN_Msk)

/**
  * @brief Configure the comparator 0 and enable it
  * @param[in] adc Base address of ADC module
  * @param[in] u32ChNum  Specifies the source channel, valid value are from 0 to 7
  * @param[in] u32Condition Specifies the compare condition
  *                     - \ref ADC_CMP_LESS_THAN
  *                     - \ref ADC_CMP_GREATER_OR_EQUAL_TO
  * @param[in] u32Data Specifies the compare value. Valid value are between 0 ~ 0x3FF
  * @param[in] u32MatchCount Specifies the match count setting, valid values are between 1~16
  * @return None
  * @details For example, ADC_ENABLE_CMP0(ADC, 5, ADC_CMP_GREATER_OR_EQUAL_TO, 0x800, 10);
  *          Means ADC will assert comparator 0 flag if channel 5 conversion result is
  *          greater or equal to 0x800 for 10 times continuously.
  */
#define ADC_ENABLE_CMP0(adc, \
                        u32ChNum, \
                        u32Condition, \
                        u32Data, \
                        u32MatchCount) (ADC->CMPR0 = ((u32ChNum) << ADC_CMPR_CMPCH_Pos) | \
                                                                   (u32Condition) | \
                                                                   ((u32Data) << ADC_CMPR_CMPD_Pos) | \
                                                                   (((u32MatchCount) - 1) << ADC_CMPR_CMPMATCNT_Pos) |\
                                                                   ADC_CMPR_CMPEN_Msk)

/**
  * @brief Disable comparator 0
  * @param[in] adc Base address of ADC module
  */
#define ADC_DISABLE_CMP0(adc) (ADC->CMPR0 = 0)

/**
  * @brief Configure the comparator 1 and enable it
  * @param[in] adc Base address of ADC module
  * @param[in] u32ChNum  Specifies the source channel, valid value are from 0 to 7
  * @param[in] u32Condition Specifies the compare condition
  *                     - \ref ADC_CMP_LESS_THAN
  *                     - \ref ADC_CMP_GREATER_OR_EQUAL_TO
  * @param[in] u32Data Specifies the compare value. Valid value are between 0 ~ 0x3FF
  * @param[in] u32MatchCount Specifies the match count setting, valid values are between 1~16
  * @return None
  * @details For example, ADC_ENABLE_CMP1(ADC, 5, ADC_CMP_GREATER_OR_EQUAL_TO, 0x800, 10);
  *          Means ADC will assert comparator 1 flag if channel 5 conversion result is
  *          greater or equal to 0x800 for 10 times continuously.
  */
#define ADC_ENABLE_CMP1(adc, \
                        u32ChNum, \
                        u32Condition, \
                        u32Data, \
                        u32MatchCount) (ADC->CMPR1 = ((u32ChNum) << ADC_CMPR_CMPCH_Pos) | \
                                                                   (u32Condition) | \
                                                                   ((u32Data) << ADC_CMPR_CMPD_Pos) | \
                                                                   ((u32MatchCount - 1) << ADC_CMPR_CMPMATCNT_Pos) |\
                                                                   ADC_CMPR_CMPEN_Msk)

/**
  * @brief Disable comparator 1
  * @param[in] adc Base address of ADC module
  */
#define ADC_DISABLE_CMP1(adc) (ADC->CMPR1 = 0)

/**
  * @brief Set ADC input channel. Enabled channel will be converted while ADC starts.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask  Channel enable bit. Each bit corresponds to a input channel. Bit 0 is channel 0, bit 1 is channel 1...
  * @return None
  */
#define ADC_SET_INPUT_CHANNEL(adc, u32Mask) (ADC->CHER = (ADC->CHER & ~ADC_CHER_CHEN_Msk) | (u32Mask))

/**
  * @brief Start the A/D conversion.
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_START_CONV(adc) (ADC->CR |= ADC_CR_ADST_Msk)

/**
  * @brief Stop the A/D conversion.
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_STOP_CONV(adc) (ADC->CR &= ~ADC_CR_ADST_Msk)

/**
  * @brief Set the output format in differential input mode.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Format Differential input mode output format. Valid values are:
  *                 - \ref ADC_DMODE_OUT_FORMAT_UNSIGNED
  *                 - \ref ADC_DMODE_OUT_FORMAT_2COMPLEMENT
  * @return None
  */
#define ADC_SET_DMOF(adc, u32Format) (ADC->CR = (ADC->CR & ~ADC_CR_DMOF_Msk) | (u32Format << ADC_CR_DMOF_Pos))

/**
  * @brief Enable PDMA transfer.
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_ENABLE_PDMA(adc) (ADC->CR |= ADC_CR_PDMA_EN_Msk)

/**
  * @brief Disable PDMA transfer.
  * @param[in] adc Base address of ADC module
  * @return None
  */
#define ADC_DISABLE_PDMA(adc) (ADC->CR &= ~ADC_CR_PDMA_EN_Msk)

/**
  * @brief Get PDMA current transfer data
  * @param[in] adc Base address of ADC module
  * @return  PDMA current transfer data
  */
#define ADC_GET_PDMA_DATA(adc) ( ADC->PDMADATA & ADC_PDMADATA_AD_PDMA_Msk)

void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param);
void ADC_DisableHWTrigger(ADC_T *adc);
void ADC_SetExtraSampleTime(ADC_T *adc,
                            uint32_t u32ChNum,
                            uint32_t u32SampleTime);
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask);



/*@}*/ /* end of group NUC400_ADC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_ADC_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__ADC_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
