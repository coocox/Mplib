/******************************************************************************
 * @file     DrvADC.c
 * @brief	   NUC123 ADC driver source file
 * @version	 1.0.1
 * @date	   17, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "NUC123Series.h"
#include "ADC.h"
#include "CLOCK.h"
#include "SYS.h"

/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvADC_FUNC ADC Driver API
  * @{
  */

/**
  * @brief  Configure ADC engine and enable ADC channel.
  * @param  u32OpMode Specify the operation mode, It could be \n
  *                                         ADC_SINGLE, ADC_SINGLE_SCAN, ADC_CONT_SCAN
  * @param  u32ChBitwise Specify the input channel Bitwise, each bit represents one channel starting from LSB.\n
  *                            For example, "u32ChBitwise=0x1(00000001b)" means enable ADC channel 0 
  *                                         "u32ChBitwise=0x19(00011001b)" means enable ADC channel 0,3 and 4.
  * @param  u32ClockSrc Specify clock source of ADC, it could be
  *                                         CLK_ADC_XTL12M
  *                                         CLK_ADC_PLL
  *                                         CLK_ADC_HCLK
  *                                         CLK_ADC_OSC22M
  * @param  u8AdcDivisor Specify Divider number ADC_N, It could be [1~256]\n
  * @return None
  * @note   Don't forget to configure the corresponding pins of the specified channels as analog input pins. and
  *         disable digital path of the GPIO pin.
  */
void DrvADC_Init(uint32_t u32OpMode, uint32_t u32ChBitwise, uint32_t u32ClockSrc, uint8_t u8AdcDivisor)
{   
    /* reset ADC */
    SYS_RESET_IP2(SYS_RST_ADC);
    
    /* ADC clock source */
    SET_ADC_CLKSRC(u32ClockSrc);
    
    /* Set ADC divisor */
    SET_ADC_CLKDIV(u8AdcDivisor);
    /* ADC engine clock enable */
    APBCLK_ENABLE(CLK_ADC);
    /* ADC enable */
    ADC_CONVERTER_ENABLE();
    
    ADC_SET_MODE(u32OpMode);
    
    ADC_CH_ENABLE(u32ChBitwise);
}

/**
  * @brief  Disable ADC. it turns off ADC power, ADC clock, and disable ADC interrupt
  * @param  None
  * @return None
  */
void DrvADC_DeInit(void)
{
    ADC->CHER = 0;
    ADC->ADCR = 0;
    ADC->CMPR[0] = 0;
    ADC->CMPR[1] = 0;
    APBCLK_DISABLE(CLK_ADC);         /* ADC engine clock disable */
	
    ADC_SET_CMP_DATA(0, 0);
    ADC_SET_CMP_DATA(1, 0);
	
    NVIC_DisableIRQ(ADC_IRQn);
}

/**
  * @brief  Enable ADC interrupt
  * @param  None
  * @return None
  */
void DrvADC_EnableInt(void)
{
    ADC_CLR_IF(ADC_CMP1_IF|ADC_CMP0_IF|ADC_CONV_DONE_IF);  // clear all interrupt flag
    ADC_INT_ENABLE();
    NVIC_EnableIRQ(ADC_IRQn);
}

/**
  * @brief  Disable ADC interrupt
  * @param  None
  * @return None
  */
void DrvADC_DisableInt(void)
{
    ADC_INT_DISABLE();
    if(((ADC->CMPR[0] & ADC_CMP_INT_EN) == 0) && 
    	((ADC->CMPR[1] & ADC_CMP_INT_EN) == 0))
		NVIC_DisableIRQ(ADC_IRQn);
}

/**
  * @brief  Enable comperator 0 interrupt
  * @param  None
  * @return None
  */
void DrvADC_EnableComp0Int(void)
{
    ADC_CLR_IF(ADC_CMP0_IF);        /* clear the ADC comparator 0 interrupt flag for safe */
    ADC_CMP_INT_ENABLE(0);
    NVIC_EnableIRQ(ADC_IRQn);
}

/**
  * @brief  Disable comperator 0 interrupt
  * @param  None
  * @return None
  */
void DrvADC_DisableComp0Int(void)
{
    ADC_CMP_INT_DISABLE(0);

    if(((ADC->ADCR & ADC_INT_EN)==0) && ((ADC->CMPR[1] & ADC_CMP_INT_EN) == 0))
        NVIC_DisableIRQ(ADC_IRQn);
}

/**
  * @brief  Enable comperator 1 interrupt
  * @param  None
  * @return None
  */
void DrvADC_EnableComp1Int(void)
{
    ADC_CLR_IF(ADC_CMP1_IF);        /* clear the ADC comparator 1 interrupt flag for safe */
    ADC_CMP_INT_ENABLE(1);
    NVIC_EnableIRQ(ADC_IRQn);
}

/**
  * @brief  Disable comperator 1 interrupt
  * @param  None
  * @return None
  */
void DrvADC_DisableComp1Int(void)
{
    ADC_CMP_INT_DISABLE(1);

    if(((ADC->ADCR & ADC_INT_EN)==0) && ((ADC->CMPR[0] & ADC_CMP_INT_EN) == 0))
        NVIC_DisableIRQ(ADC_IRQn);
}

/**
  * @brief  Enable and configure ADC external trigger
  * @param  u32Condition Trigger condition, it could be
  *              ADC_LOW_TRG, ADC_HIGH_TRG, ADC_FALLING_TRG, ADC_RISING_TRG
  * @param  u32Condition Trigger condition, it could be
  *              ADC_TRGSRC_STADC, ADC_TRGSRC_PWM 
  * @return None
  * @note   ADC external trigger function is supported only in Single-cycle Scan mode
  */
void DrvADC_EnableExtTrigger(uint32_t u32TrgSrc, uint32_t u32Condition)
{
    ADC_SET_TRGSRC(u32TrgSrc);
    ADC_SET_TRGCOND(u32Condition);
    ADC_TRG_ENABLE();
}

/**
  * @brief  Enable and congire ADC comparator 0
  * @param  u8ch ADC channel to be compared. It could be \n
  *                ADC_CMP_CH0, ADC_CMP_CH1, ADC_CMP_CH2, ADC_CMP_CH3
  *                ADC_CMP_CH4, ADC_CMP_CH5, ADC_CMP_CH6, ADC_CMP_CH7
  * @param  u32Condition Specify the compare condition, it could be \n
  *                ADC_CMP_GE, ADC_CMP_LESS
  * @param  u16Data Specify the compare data
  * @param  u8Count Specify the compare match count, it could be 0~15
  * @return This API always success and has no return value.
  */
void DrvADC_EnableComp0(uint8_t u8AdcCh,
                             uint32_t u32Condition,
                             uint16_t u16Data,
                             uint8_t u8Count)
{
    ADC_SET_CMP(0,u16Data, u8Count, u8AdcCh, u32Condition); 
    ADC_CMP_ENABLE(0);
}

/**
  * @brief  Enable and congire ADC comparator 1
  * @param  u8ch Specify the channel number to compare
  * @param  u32Condition Specify the compare condition, could be ADC_CMPR_CMPCOND_GE or ADC_CMPR_CMPCOND_LT
  * @param  u16Data Specify the compare data
  * @param  u8Count Specify the compare match count, valid values are between 1~16
  * @return This API always success and has no return value.
  */
void DrvADC_EnableComp1(uint8_t u8AdcCh,
                             uint32_t u32Condition,
                             uint16_t u16Data,
                             uint8_t u8Count)
{
    ADC_SET_CMP(1,u16Data, u8Count, u8AdcCh, u32Condition); 
    ADC_CMP_ENABLE(1);
}

/*@}*/ /* end of group DrvADC_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

