/**
 *******************************************************************************
 * @file    tmpm061_adc.c
 * @brief   This file provides API functions for ADC driver.
 * @version V2.0.2.1
 * @date    2013/03/21
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
#include "tmpm061_adc.h"

#if defined(__TMPM061_ADC_H)

/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @defgroup ADC 
  * @brief ADC driver modules
  * @{
  */

/** @defgroup ADC_Private_Defines
  * @{
  */

#define ADC_MASK_KEEP1BIT       (uint32_t)0x01U
#define ADC_MASK_KEEP2BITS      (uint32_t)0x03U
#define ADC_MASK_KEEP3BITS      (uint32_t)0x07U
#define ADC_MASK_KEEP4BITS      (uint32_t)0x0FU
#define ADC_MASK_KEEP5BITS      (uint32_t)0x1FU
#define ADC_MASK_KEEP6BITS      (uint32_t)0x3FU
#define ADC_MASK_KEEP7BITS      (uint32_t)0x7FU
#define ADC_MASK_KEEP8BITS      (uint32_t)0xFFU

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
  * @brief  Software reset to initializes all the registers except ADCLK<ADCLK>.
  * @param  None.
  * @retval None.
  */
void ADC_SWReset(void)
{
    /* write MOD4<ADRST[1:0]> = 0b10, 0b01 to reset ADC */
    TSB_AD->MOD4 = (uint32_t) 0x02;     /* other bits are useless, write them to '0' */
    TSB_AD->MOD4 = (uint32_t) 0x01;
}

/**  
  * @brief  Set A/D conversion time and prescaler output.
  * @param  Conversion_Time: Select the A/D conversion time.
  *   This parameter can be one of the following values:
  *   ADC_CONVERSION_35_CLOCK, ADC_CONVERSION_42_CLOCK,
  *   ADC_CONVERSION_68_CLOCK, ADC_CONVERSION_81_CLOCK
  * @param  Prescaler_Output: Select the A/D prescaler output.
  *   This parameter can be one of the following values:
  *   ADC_FC_DIVIDE_LEVEL_1, ADC_FC_DIVIDE_LEVEL_2, ADC_FC_DIVIDE_LEVEL_4,
  *   ADC_FC_DIVIDE_LEVEL_8, ADC_FC_DIVIDE_LEVEL_16.
  * @retval None.
  */
void ADC_SetClk(uint32_t Conversion_Time, uint32_t Prescaler_Output)
{
    /* Check the parameters */
    assert_param(IS_ADC_CONVERSION_TIME(Conversion_Time));
    assert_param(IS_ADC_PRESCALER(Prescaler_Output));

    /* Set ADCLK */
    TSB_AD->CLK = Conversion_Time + Prescaler_Output;
}


/**   
  * @brief  Start ADC conversion.
  * @param  None.
  * @retval None.
  */
void ADC_Start(void)
{
    /* Set bit 0 of MOD0  to start ADC */
    uint32_t tmp = TSB_AD->MOD0 | 0x01U;
    TSB_AD->MOD0 = tmp;
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
    /* read MOD0, keep bit4,3,2,0 and clear bit1 which is "ADMOD0<SCAN>" */
    uint32_t tmp = TSB_AD->MOD0 & ((ADC_MASK_KEEP3BITS << 2U) | ADC_MASK_KEEP1BIT);

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp |= (uint32_t) NewState << 1U;
    TSB_AD->MOD0 = tmp;
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
    /* read MOD0, keep bit4,3, 1,0 and clear bit2 which is "ADMOD0<REPEAT>" */
    uint32_t tmp = TSB_AD->MOD0 & ((ADC_MASK_KEEP2BITS << 3U) | ADC_MASK_KEEP2BITS);

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp |= (uint32_t) NewState << 2U;
    TSB_AD->MOD0 = tmp;
}

/**  
  * @brief  Set ADC interrupt mode in fixed channel repeat conversion mode.
  * @param  INTMode: Specify AD conversion interrupt mode.
  *   This parameter can be one of the following values:
  *   ADC_INT_SINGLE, ADC_INT_CONVERSION_4 or ADC_INT_CONVERSION_8.
  * @retval None.
  */
void ADC_SetINTMode(uint8_t INTMode)
{
    /* read MOD0 and keep bit2,1,0. then clear bit5,4 */
    uint32_t tmp = TSB_AD->MOD0 & ADC_MASK_KEEP3BITS;

    /* Check the parameters */
    assert_param(IS_ADC_INT_MODE(INTMode));

    /* Set ADMOD0<ITM[1:0]> */
    tmp |= INTMode;             /* no need to left shift, refer to .h file */
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
    /* check bit7 of MOD0 */
    WorkState retval = BUSY;
    uint32_t tmp = TSB_AD->MOD0 & ((uint32_t) 0x01U << 7U);

    if (tmp) {
        retval = DONE;
    } else {
      /* Do nothing */
    }
    
    return retval;
}

/**
  * @brief  Set ADC input channel.
  * @param  InputChannel: Analog input channel, it also related with other settings.
  *   This parameter can be one of the following values:
  *   ADC_AN_0, ADC_AN_1, ADC_AN_2
  * @retval None.
  */
void ADC_SetInputChannel(uint8_t InputChannel)
{
    /* read MOD1 , keep bit7,6,5,4 and clear bit3,2,1,0 */
    uint32_t tmp = TSB_AD->MOD1 & (ADC_MASK_KEEP4BITS << 4U);

    /* Check the parameters */
    assert_param(IS_ADC_INPUT_CH(InputChannel));

    /* Set ADMOD1<ADCH[3:0]> */
    tmp |= InputChannel;
    TSB_AD->MOD1 = tmp;
}

/** 
  * @brief  Set ADC operation for scanning.
  * @param  ScanMode: Spcifiy operation mode for channel scanning.
  *   This parameter can be one of the following values:
  *   ADC_SCAN_4CH, ADC_SCAN_8CH, ADC_SCAN_12CH.
  * @retval None.
  */
void ADC_SetChannelScanMode(ADC_ChannelScanMode ScanMode)
{
    /* read MOD1 and keep bit7,6, 3,2,1,0. then clear bit5,4 */
    uint32_t tmp = TSB_AD->MOD1 & ((ADC_MASK_KEEP2BITS << 6U) | ADC_MASK_KEEP4BITS);

    /* Check the parameters */
    assert_param(IS_ADC_CH_SCAN_MODE(ScanMode));

    tmp |= ((uint32_t) ScanMode << 4U);
    TSB_AD->MOD1 = tmp;
}

/** 
  * @brief  Set ADC operation mode in IDLE mode.
  * @param  NewState: Specify ADC conversion mode in IDLE mode.
  *   This parameter can be one of the following values:
  *   ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SetIdleMode(FunctionalState NewState)
{
    /* read MOD1, keep bit7, 5,4,3,2,1,0 and clear bit6 which is "ADMOD1<I2AD>" */
    uint32_t tmp = TSB_AD->MOD1 & ((ADC_MASK_KEEP1BIT << 7U) | ADC_MASK_KEEP6BITS);

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp |= (uint32_t) NewState << 6U;
    TSB_AD->MOD1 = tmp;

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

    /* read MOD1, keep bit6,5,4,3,2,1,0 and clear bit7 which are "ADMOD1<VREFON>" */
    uint32_t tmp = TSB_AD->MOD1 & ADC_MASK_KEEP7BITS;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp |= (uint32_t) NewState << 7U;
    TSB_AD->MOD1 = tmp;

}


/**
  * @brief  Read ADC result.
  * @param  ADREGx: ADC result register.
  *   This parameter can be one of the following values:
  *   ADC_REG_0, ADC_REG_1, ADC_REG_2
  * @retval ADC result.
  */
ADC_Result ADC_GetConvertResult(uint8_t ADREGx)
{
    ADC_Result retval = { 0U };

    /* Check the parameters */
    assert_param(IS_ADC_REG(ADREGx));

    /* Read ADREGx<ADRx[9:0]> to get ADC result */
    if (ADREGx == ADC_REG_0) {
        retval.All = TSB_AD->REG0;
    } else if (ADREGx == ADC_REG_1) {
        retval.All = TSB_AD->REG1;
    } else {
        retval.All = TSB_AD->REG2;
    }

    return retval;
}



/** @} */
/* End of group ADC_Exported_Functions */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX00_Periph_Driver */

#endif                          /* defined(__TMPM061_ADC_H) */
