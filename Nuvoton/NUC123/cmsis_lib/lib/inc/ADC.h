/******************************************************************************
 * @file     ADC.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/17 13:49p $
 * @brief    NUC123 Series ADC Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup ADC_MACRO ADC Macro
  * @{
  */

/** @addtogroup ADC_MACRO_CONTANT ADC Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/*  ADDRx constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define ADC_DATA_VALID                  (1UL<<ADC_ADDR_VALID_Pos) /*!< The corresponding channel analog input conversion complete flag */
#define ADC_DATA_OVERRUN                (1UL<<ADC_ADDR_OVERRUN_Pos) /*!< Indicate data in RSLT[15:0] is overwritten or not */

/*---------------------------------------------------------------------------------------------------------*/
/*  ADCR constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define ADC_START                       (1UL<<ADC_ADCR_ADST_Pos) /*!< Start A/D conversion */
#define ADC_STOP                        (0UL<<ADC_ADCR_ADST_Pos) /*!< Stop A/D conversion */

#define ADC_PDMA_EN                     (1UL<<ADC_ADCR_PTEN_Pos) /*!< Enable PDMA data transfer in ADDR 0~7 */
#define ADC_PDMA_DIS                    (0UL<<ADC_ADCR_PTEN_Pos) /*!< Disable PDMA data transfer in ADDR 0~7 */

#define ADC_TRG_EN                      (1UL<<ADC_ADCR_TRGEN_Pos) /*!< Enable triggering of A/D conversion by external STADC pin */
#define ADC_TRG_DIS                     (0UL<<ADC_ADCR_TRGEN_Pos) /*!< Disable triggering of A/D conversion by external STADC pin */

#define ADC_LOW_TRG                     (0UL<<ADC_ADCR_TRGCOND_Pos) /*!< External pin STADC trigger event is low level */
#define ADC_HIGH_TRG                    (1UL<<ADC_ADCR_TRGCOND_Pos) /*!< External pin STADC trigger event is high level */
#define ADC_FALLING_TRG                 (2UL<<ADC_ADCR_TRGCOND_Pos) /*!< External pin STADC trigger event is falling edge */
#define ADC_RISING_TRG                  (3UL<<ADC_ADCR_TRGCOND_Pos) /*!< External pin STADC trigger event is rising edge */

#define ADC_TRGSRC_STADC                (0UL<<ADC_ADCR_TRGS_Pos) /*!< A/D conversion is started by external STADC pin */
#define ADC_TRGSRC_PWM                  (1UL<<ADC_ADCR_TRGS_Pos) /*!< A/D conversion is started by PWM center-aligned trigger */

#define ADC_SINGLE                      (0UL<<ADC_ADCR_ADMD_Pos) /*!< A/D Converter Operation Mode is single mode */
#define ADC_SINGLE_SCAN                 (2UL<<ADC_ADCR_ADMD_Pos) /*!< A/D Converter Operation Mode is single scan mode */
#define ADC_CONT_SCAN                   (3UL<<ADC_ADCR_ADMD_Pos) /*!< A/D Converter Operation Mode is continuous scan mode */

#define ADC_INT_EN                      (1UL<<ADC_ADCR_ADIE_Pos) /*!< Enable A/D interrupt function */
#define ADC_INT_DIS                     (0UL<<ADC_ADCR_ADIE_Pos) /*!< Disable A/D interrupt function */

#define ADC_ENABLE                      (1UL<<ADC_ADCR_ADEN_Pos) /*!< Enable A/D converter */
#define ADC_DISABLE                     (0UL<<ADC_ADCR_ADEN_Pos) /*!< Disable A/D converter */

/*---------------------------------------------------------------------------------------------------------*/
/*  ADCHER constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define ADC_CH7_EXT_IN                  (0UL<<ADC_CHER_PRESEL_Pos) /*!< External analog input as ADC channel 7 input source */
#define ADC_CH7_BANDGAP                 (1UL<<ADC_CHER_PRESEL_Pos) /*!< Internal bandgap voltage as ADC channel 7 input source */

#define ADC_CH7                         (1UL<<ADC_CHER_CHEN7_Pos) /*!< Analog input channel 7 */
#define ADC_CH6                         (1UL<<ADC_CHER_CHEN6_Pos) /*!< Analog input channel 6 */
#define ADC_CH5                         (1UL<<ADC_CHER_CHEN5_Pos) /*!< Analog input channel 5 */
#define ADC_CH4                         (1UL<<ADC_CHER_CHEN4_Pos) /*!< Analog input channel 4 */
#define ADC_CH3                         (1UL<<ADC_CHER_CHEN3_Pos) /*!< Analog input channel 3 */
#define ADC_CH2                         (1UL<<ADC_CHER_CHEN2_Pos) /*!< Analog input channel 2 */
#define ADC_CH1                         (1UL<<ADC_CHER_CHEN1_Pos) /*!< Analog input channel 1 */
#define ADC_CH0                         (1UL<<ADC_CHER_CHEN0_Pos) /*!< Analog input channel 0 */

/*---------------------------------------------------------------------------------------------------------*/
/*  ADCMPRx constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define ADC_CMP_CH0                     (0UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 0 conversion result is selected to be compared */
#define ADC_CMP_CH1                     (1UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 1 conversion result is selected to be compared */
#define ADC_CMP_CH2                     (2UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 2 conversion result is selected to be compared */
#define ADC_CMP_CH3                     (3UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 3 conversion result is selected to be compared */
#define ADC_CMP_CH4                     (4UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 4 conversion result is selected to be compared */
#define ADC_CMP_CH5                     (5UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 5 conversion result is selected to be compared */
#define ADC_CMP_CH6                     (6UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 6 conversion result is selected to be compared */
#define ADC_CMP_CH7                     (7UL<<ADC_CMPR_CMPCH_Pos) /*!< Channel 7 conversion result is selected to be compared */

#define ADC_CMP_GE                      (1UL<<ADC_CMPR_CMPCOND_Pos) /*!< When A/D conversion result is greater or equal to CMPD, internal match counter increase one */
#define ADC_CMP_LESS                    (0UL<<ADC_CMPR_CMPCOND_Pos) /*!< When A/D conversion result is less than CMPD, internal match counter increase one */

#define ADC_CMP_INT_EN                  (1UL<<ADC_CMPR_CMPIE_Pos) /*!< Enable compare function interrupt */
#define ADC_CMP_INT_DIS                 (0UL<<ADC_CMPR_CMPIE_Pos) /*!< Disable compare function interrupt */

#define ADC_CMP_EN                      (1UL<<ADC_CMPR_CMPEN_Pos) /*!< Enable compare function */
#define ADC_CMP_DIS                     (0UL<<ADC_CMPR_CMPEN_Pos) /*!< Disable compare function */

/*---------------------------------------------------------------------------------------------------------*/
/*  ADSR constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define ADC_BUSY                        (1UL<<ADC_ADSR_BUSY_Pos) /*!< Indicate A/D converter is busy at conversion or is in idle state */
#define ADC_CMP1_IF                     (1UL<<ADC_ADSR_CMPF1_Pos) /*!< Flag of conversion result in ADDR meets ADCMPR1 setting or not */
#define ADC_CMP0_IF                     (1UL<<ADC_ADSR_CMPF0_Pos) /*!< Flag of conversion result in ADDR meets ADCMPR0 setting or not */
#define ADC_CONV_DONE_IF                (1UL<<ADC_ADSR_ADF_Pos) /*!< A/D Conversion End Flag */

/*@}*/ /* end of group ADC_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup ADC_MACRO_FUNC ADC Macro Func
  @{
*/

/**
 * @brief       Check ADC conversion result status
 *
 * @param[in]   ch  ADC channel. It could be 0~7
 *
 * @retval      FALSE  Conversion result is not valid
 * @retval      TRUE   Conversion data in result register is valid
 *
 * @details     Check ADC conversion reault status, valid or not
 */
static __INLINE uint32_t ADC_IS_RSLT_VALID(uint8_t ch)
{
    return (ADC->ADDR[(ch)] & ADC_DATA_VALID);
}

/**
 * @brief       Check if ADC result register has been overwritten or not
 *
 * @param[in]   ch  ADC channel. It could be 0~7
 *
 * @retval      FALSE  Data in RSLT[15:0] is recent conversion result
 * @retval      TRUE   Data in RSLT[15:0] is overwritten 
 *
 * @details     Check if ADC result register RSLT[15:0] has been overwritten or not
 */
static __INLINE uint32_t ADC_IS_RSLT_OVERRUN(uint8_t ch)
{
    return (ADC->ADDR[(ch)] & ADC_DATA_OVERRUN);
}

/**
 * @brief       Get ADC conversion result
 *
 * @param[in]   ch  ADC channel. It could be 0~7
 *
 * @return      10-bit ADC conversion result
 *
 * @details     Get ADC conversion result from result register RSLT[15:0]
 */
static __INLINE uint16_t ADC_GET_RSLT(uint8_t ch)
{
    return (ADC->ADDR[(ch)] & 0x3FF);
}

/**
 * @brief       Start A/D conversion
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Start A/D conversion
 */
static __INLINE void ADC_START_CONVERSION(void)
{
    ADC->ADCR |= ADC_START;
}

/**
 * @brief       Stop A/D conversion
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Stop A/D conversion
 */
static __INLINE void ADC_STOP_CONVERSION(void)
{
    ADC->ADCR &= (~ADC_ADCR_ADST_Msk);
}

/**
 * @brief       Enable PDMA transfer
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable PDMA data transfer in ADDR 0~7
 */
static __INLINE void ADC_PDMA_ENABLE(void)
{
    ADC->ADCR |= ADC_PDMA_EN;
}

/**
 * @brief       Disable PDMA transfer
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Disable PDMA data transfer in ADDR 0~7
 */
static __INLINE void ADC_PDMA_DISABLE(void)
{
    ADC->ADCR &= (~ADC_ADCR_PTEN_Msk);
}

/**
 * @brief       Enable triggering of A/D conversion by external STADC pin
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable triggering of A/D conversion by external STADC pin, \n
 *              ADC external trigger function is only supported in Single-cycle Scan mode
 */
static __INLINE void ADC_TRG_ENABLE(void)
{
    ADC->ADCR |= ADC_TRG_EN;
}

/**
 * @brief       Disable triggering of A/D conversion by external STADC pin
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Disable triggering of A/D conversion by external STADC pin
 */
static __INLINE void ADC_TRG_DISABLE(void)
{
    ADC->ADCR &= (~ADC_ADCR_TRGEN_Msk);
}

/**
 * @brief       Set external trigger condition
 *
 * @param[in]   cond  External trigger condition. It could be \n
 *                    ADC_LOW_TRG, ADC_HIGH_TRG, ADC_FALLING_TRG, ADC_RISING_TRG 
 *
 * @return      None
 *
 * @details     Set external pin STADC trigger event is low, high level or falling, rising edge
 */
static __INLINE void ADC_SET_TRGCOND(uint32_t cond)
{
    ADC->ADCR = (ADC->ADCR & (~ADC_ADCR_TRGCOND_Msk)) | (cond);
}

/**
 * @brief       Set hardware trigger source
 *
 * @param[in]   src  Hardware trigger source. It could be \n
 *                   ADC_TRGSRC_STADC, ADC_TRGSRC_PWM
 *
 * @return      None
 *
 * @details     Set hardware trigger source
 */
static __INLINE void ADC_SET_TRGSRC(uint32_t src)
{
    ADC->ADCR = (ADC->ADCR & (~ADC_ADCR_TRGS_Msk)) | (src);
}

/**
 * @brief       Set A/D converter Operation Mode
 *
 * @param[in]   mode  A/D converter Operation Mode. It could be \n
 *                    ADC_SINGLE, ADC_SINGLE_SCAN, ADC_CONT_SCAN
 *
 * @return      None
 *
 * @details     Set A/D converter Operation Mode
 */
static __INLINE void ADC_SET_MODE(uint32_t mode)
{
    ADC->ADCR = (ADC->ADCR & (~ADC_ADCR_ADMD_Msk)) | (mode);
}

/**
 * @brief       Enable A/D interrupt function
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable A/D interrupt function
 */
static __INLINE void ADC_INT_ENABLE(void)
{
    ADC->ADCR |= ADC_INT_EN;
}

/**
 * @brief       Disable A/D interrupt function
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Disable A/D interrupt function
 */
static __INLINE void ADC_INT_DISABLE(void)
{
    ADC->ADCR &= (~ADC_ADCR_ADIE_Msk);
}

/**
 * @brief       Enable A/D converter
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable A/D converter
 */
static __INLINE void ADC_CONVERTER_ENABLE(void)
{
    ADC->ADCR |= ADC_ENABLE;
}

/**
 * @brief       Disable A/D converter
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     Disable A/D converter
 */
static __INLINE void ADC_CONVERTER_DISABLE(void)
{
    ADC->ADCR &= (~ADC_ADCR_ADEN_Msk);
}

/**
 * @brief       Set A/D channel 7 input source
 *
 * @param[in]   src  A/D channel 7 input source. It could be \n
 *                   ADC_CH7_EXT_IN, ADC_CH7_BANDGAP
 *
 * @return      None
 *
 * @details     Set A/D channel 7 input source
 */
static __INLINE void ADC_SET_CH7_SRC(uint32_t src)
{
    ADC->CHER = (ADC->CHER & (~ADC_CHER_PRESEL_Msk)) | (src);
}

/**
 * @brief       Enable A/D analog input channels
 *
 * @param[in]   ch  A/D channel. It could be one of following or their 'OR' combination \n
 *                  ADC_CH0, ADC_CH1, ADC_CH2, ADC_CH3, \n
 *                  ADC_CH4, ADC_CH5, ADC_CH6, ADC_CH7
 *
 * @return      None
 *
 * @details     Enable A/D analog input for the specified channels
 */
static __INLINE void ADC_CH_ENABLE(uint32_t ch)
{
    ADC->CHER |= (ch);
}

/**
 * @brief       Disable A/D analog input channels
 *
 * @param[in]   ch  A/D channel. It could be one of following or their 'OR' combination \n
 *                  ADC_CH0, ADC_CH1, ADC_CH2, ADC_CH3, \n
 *                  ADC_CH4, ADC_CH5, ADC_CH6, ADC_CH7
 *
 * @return      None
 *
 * @details     Disable A/D analog input for the specified channels
 */
static __INLINE void ADC_CH_DISABLE(uint32_t ch)
{
    ADC->CHER &= ~(ch);
}

/**
 * @brief       Set ADC compare register
 *
 * @param[in]   cmp   Comparator channel. It could be 0~1
 * @param[in]   data  Data to be used to compare with conversion result of specified channel
 * @param[in]   ch    ADC channel to be compared, it could be
                      ADC_CMP_CH0, ADC_CMP_CH1, ADC_CMP_CH2, ADC_CMP_CH3,
                      ADC_CMP_CH4, ADC_CMP_CH5, ADC_CMP_CH6, ADC_CMP_CH7
 * @param[in]   cnt   Compare match count to be set
 * @param[in]   cond  Compare condition. It could be ADC_CMP_GE, ADC_CMP_LESS
 *
 * @return      None
 *
 * @details     Set ADC compare data which is used to compare with conversion result of specified channel
 */
static __INLINE void ADC_SET_CMP(uint8_t cmp, uint16_t data, uint8_t cnt, uint32_t ch, uint32_t cond)
{
    ADC->CMPR[(cmp)] = (ADC->CMPR[(cmp)] & 0xF0000003)|((data)<<ADC_CMPR_CMPD_Pos) | ((cnt)<<ADC_CMPR_CMPMATCNT_Pos)|(ch)|(cond);
}

/**
 * @brief       Set ADC compare data
 *
 * @param[in]   ch    Comparator channel. It could be 0~1
 * @param[in]   data  Data to be used to compare with conversion result of specified channel
 *
 * @return      None
 *
 * @details     Set ADC compare data which is used to compare with conversion result of specified channel
 */
static __INLINE void ADC_SET_CMP_DATA(uint8_t ch, uint16_t data)
{
    ADC->CMPR[(ch)] = (ADC->CMPR[(ch)] & (~ADC_CMPR_CMPD_Msk)) | ((data)<<ADC_CMPR_CMPD_Pos);
}

/**
 * @brief       Set ADC Compare match count
 *
 * @param[in]   ch   ADC comparator channel. It could be 0~1
 * @param[in]   cnt  Compare match count to be set
 *
 * @return      None
 *
 * @details     Set ADC Compare match count, When internal counter reaches to (CMPMATCNT +1), CMPFx will be set
 */
static __INLINE void ADC_SET_CMP_CNT(uint8_t ch, uint8_t cnt)
{
    ADC->CMPR[(ch)] = (ADC->CMPR[(ch)] & (~ADC_CMPR_CMPMATCNT_Msk)) | ((cnt)<<ADC_CMPR_CMPMATCNT_Pos);
}

/**
 * @brief       Set ADC Compare channel
 *
 * @param[in]   cmp_ch  ADC comparator channel. It could be 0~1
 * @param[in]   adc_ch  ADC channel to be compared. It could be \n
 *                      ADC_CMP_CH0, ADC_CMP_CH1, ADC_CMP_CH2, ADC_CMP_CH3
 *                      ADC_CMP_CH4, ADC_CMP_CH5, ADC_CMP_CH6, ADC_CMP_CH7
 *
 * @return      None
 *
 * @details     Set ADC Compare channel of specified comparator
 */
static __INLINE void ADC_SET_CMP_CH(uint8_t cmp_ch, uint32_t adc_ch)
{
    ADC->CMPR[(cmp_ch)] = (ADC->CMPR[(cmp_ch)] & (~ADC_CMPR_CMPCH_Msk)) | (adc_ch);
}

/**
 * @brief       Set ADC compare conditions
 *
 * @param[in]   ch    ADC comparator channel. It could be 0~1
 * @param[in]   cond  Compare conditions. It could be ADC_CMP_GE, ADC_CMP_LESS
 *
 * @return      None
 *
 * @details     When the relations between A/D conversion result and CMPD match the setting, internal match counter increase one
 */
static __INLINE void ADC_SET_CMP_COND(uint8_t ch, uint32_t cond)
{
    ADC->CMPR[(ch)] =( ADC->CMPR[(ch)] & (~ADC_CMPR_CMPCOND_Msk)) | (cond);
}

/**
 * @brief       Enable ADC compare interrupt function
 *
 * @param[in]   ch  Comparator channel. It could be 0~1
 *
 * @return      None
 *
 * @details     Enable ADC controller compare interrupt function
 */
static __INLINE void ADC_CMP_INT_ENABLE(uint8_t ch)
{
    ADC->CMPR[(ch)] |= ADC_CMP_INT_EN;
}

/**
 * @brief       Disable ADC compare interrupt function
 *
 * @param[in]   ch  Comparator channel. It could be 0~1
 *
 * @return      None
 *
 * @details     Disable ADC controller compare interrupt function
 */
static __INLINE void ADC_CMP_INT_DISABLE(uint8_t ch)
{
    ADC->CMPR[(ch)] &= (~ADC_CMPR_CMPIE_Msk);
}

/**
 * @brief       Enable ADC compare function
 *
 * @param[in]   ch  Comparator channel. It could be 0~1
 *
 * @return      None
 *
 * @details     Enable ADC controller to compare CMPD[11:0] with specified channel conversion result
 */
static __INLINE void ADC_CMP_ENABLE(uint8_t ch)
{
    ADC->CMPR[(ch)] |= ADC_CMP_EN;
}

/**
 * @brief       Disable ADC compare function
 *
 * @param[in]   ch  Comparator channel. It could be 0~1
 *
 * @return      None
 *
 * @details     Disable ADC controller compare function
 */
static __INLINE void ADC_CMP_DISABLE(uint8_t ch)
{
    ADC->CMPR[(ch)] &= (~ADC_CMPR_CMPEN_Msk);
}

/**
 * @brief       Get ADC current conversion channel
 *
 * @param       None
 *
 * @return      When BUSY = 1, current conversion channel. When BUSY = 0, number of the next conversion channel. 
 *
 * @details     Get ADC current or next conversion channel, depending on BUSY bit
 */
static __INLINE uint8_t ADC_GET_CURRENT_CH(void)
{
    return ((ADC->ADSR & ADC_ADSR_CHANNEL_Msk)>>ADC_ADSR_CHANNEL_Pos);
}

/**
 * @brief       Get ADC converter status
 *
 * @param       None
 *
 * @retval      FALSE  A/D converter is in Idle state
 * @retval      TRUE   A/D converter is busy at conversion
 *
 * @details     Get ADC converter status, busy or idle
 */
static __INLINE uint32_t ADC_GET_CONVERTER_STS(void)
{
    return (ADC->ADSR & ADC_BUSY);
}

/**
 * @brief       Get ADC interrupt status
 *
 * @param[in]   flag  Interrupt flag of ADC. It could be ADC_CMP1_IF, ADC_CMP0_IF, ADC_CONV_DONE_IF
 *
 * @retval      FALSE  No interrupt
 * @retval      TRUE   Specified interrupt occured
 *
 * @details     Get specified ADC interrupt status
 */
static __INLINE uint32_t ADC_GET_IF(uint32_t flag)
{
    return (ADC->ADSR & (flag));
}

/**
 * @brief       Clear ADC interrupt status
 *
 * @param[in]   flag  Interrupt flag of ADC. It could be
 *              ADC_CMP1_IF, ADC_CMP0_IF, ADC_CONV_DONE_IF and their 'OR' combination
 *
 * @return      None
 *
 * @details     Clear specified ADC interrupt status
 */
static __INLINE void ADC_CLR_IF(uint32_t flag)
{
    ADC->ADSR = (flag);
}

/**
 * @brief       Get ADC PDMA current transfer data
 *
 * @param       None
 *
 * @retval      ADC PDMA current transfer data
 *
 * @details     Get ADC PDMA current transfer data
 */
static __INLINE uint32_t ADC_GET_PDMA_DATA(void)
{
    return (ADC->PDMA);
}
 
/*@}*/ /* end of group ADC_MACRO_FUNC */
/*@}*/ /* end of group ADC_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


/*---------------------------------------------------------------------------------------------------------*/
/* Define ADC API prototype                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void DrvADC_Init(uint32_t u32OpMode, uint32_t u32ChBitwise, uint32_t u32ClockSrc, uint8_t u8AdcDivisor);
void DrvADC_DeInit(void);
void DrvADC_EnableInt(void);
void DrvADC_DisableInt(void);
void DrvADC_EnableComp0Int(void);
void DrvADC_EnableComp0Int(void);
void DrvADC_DisableComp0Int(void);
void DrvADC_EnableComp1Int(void);
void DrvADC_DisableComp1Int(void);
void DrvADC_EnableExtTrigger(uint32_t u32TrgSrc, uint32_t u32Condition);
void DrvADC_EnableComp0(uint8_t u8AdcCh,
                             uint32_t u32Condition,
                             uint16_t u16Data,
                             uint8_t u8Count);
void DrvADC_EnableComp1(uint8_t u8AdcCh,
                             uint32_t u32Condition,
                             uint16_t u16Data,
                             uint8_t u8Count);




#endif
