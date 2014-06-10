/**
 *******************************************************************************
 * @file    tmpm061_lcd.c
 * @brief   This file provides API functions for LCD driver.
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
#include "tmpm061_lcd.h"

#if defined(__TMPM061_LCD_H)

/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @defgroup LCD 
  * @brief LCD driver modules
  * @{
  */

/** @defgroup LCD_Private_Defines
  * @{
  */
#define LCD_MASK_KEEP1BIT       (uint32_t)0x01U
#define LCD_MASK_KEEP2BITS      (uint32_t)0x03U
#define LCD_MASK_KEEP3BITS      (uint32_t)0x07U
#define LCD_MASK_KEEP4BITS      (uint32_t)0x0FU
#define LCD_MASK_KEEP5BITS      (uint32_t)0x1FU
#define LCD_MASK_KEEP6BITS      (uint32_t)0x3FU
#define LCD_MASK_KEEP7BITS      (uint32_t)0x7FU
#define LCD_MASK_KEEP8BITS      (uint32_t)0xFFU



/** @} */
/* End of group LCD_Private_Defines */

/** @defgroup LCD_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group LCD_Private_FunctionPrototypes */

/** @defgroup LCD_Private_Functions
  * @{
  */

/** @} */
/* End of group LCD_Private_Functions */

/** @defgroup LCD_Exported_Functions
  * @{
  */


/** 
  * @brief  Enable operation for LCD module.
  * @param  None
  * @retval None
  */
void LCD_Enable(void)
{
    /* write '1' to LCDEN<LCDE> to enable  */
    TSB_LCD->EN = 1U;
}


/** 
  * @brief  Disable operation for LCD module.
  * @param  None
  * @retval None
  */
void LCD_Disable(void)
{
    /* write '0' to LCDEN<LCDE> to disable  */
    TSB_LCD->EN = 0U;
}


/**  
  * @brief  Enable or disable the LCD display while LCD module is enabled.
  * @param  NewState: Enable or disable the LCD display.
  *   This parameter can be one of the following values:
  *     ENABLE:  Enable LCD display  
  *     DISABLE: Blank LCD display
  * @retval None.
  */
void LCD_SetDisplay(FunctionalState NewState)
{
    /* read CR1, keep bit 6 to 0, clear bit 7 */
    uint32_t tmp = TSB_LCD->CR1 & LCD_MASK_KEEP7BITS;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* LCDCR1<EDSP>   [  bit7:  write 1 to enable, write 0 to disable ] */
    tmp |= (uint32_t) NewState << 7U;
    TSB_LCD->CR1 = tmp;

}

/**  
  * @brief  Set duty and bias for LCD driving method.
  * @param  DutyBias: Duty and bias setting value.
  *   This parameter can be one of the following values:
  *     LCD_DUTY4_BIAS3  : 1/4 duty, 1/3 bias
  *     LCD_DUTY3_BIAS3  : 1/3 duty, 1/3 bias
  *     LCD_DUTY3_BIAS2  : 1/3 duty, 1/2 bias
  *     LCD_DUTY2_BIAS2  : 1/2 duty, 1/2 bias
  *     LCD_STATIC       : static
  * @retval None.
  */
void LCD_SetDutyBias(LCD_DutyBias DutyBias)
{
    /* read CR1 and clear bit6,5,4 which are LCDCR1<DUTY> */
    uint32_t tmp = TSB_LCD->CR1 & ((LCD_MASK_KEEP1BIT << 7U) | LCD_MASK_KEEP4BITS);

    /* Check the parameters */
    assert_param(IS_LCD_DUTY_BIAS(DutyBias));

    tmp |= (uint32_t) DutyBias << 4U;
    TSB_LCD->CR1 = tmp;
}


/**  
  * @brief  Set base frequency which is relative with fsys(gear clock frequency).
  * @param  Freq: Base frequency selection.
  *   This parameter can be one of the following values:
  *     LCD_FSYS_DIVIDE_2_POWER_18 :  F_base = fsys / (2^18)         
  *     LCD_FSYS_DIVIDE_2_POWER_17 :  F_base = fsys / (2^17)         
  *     LCD_FSYS_DIVIDE_2_POWER_16 :  F_base = fsys / (2^16)         
  *     LCD_FSYS_DIVIDE_2_POWER_15 :  F_base = fsys / (2^15)         
  *     LCD_FSYS_DIVIDE_2_POWER_14 :  F_base = fsys / (2^14)         
  *     LCD_FS_DIVIDE_2_POWER_9    :  F_base = fs / (2^9)           
  *     LCD_FS_DIVIDE_2_POWER_8    :  F_base = fs / (2^8)   
  * @retval None.
  */
void LCD_SetBaseFreq(LCD_BaseFreq Freq)
{
    /* read CR1 and clear bit3,2,1,0 which are LCDCR1<SLF> */
    uint32_t tmp = TSB_LCD->CR1 & (LCD_MASK_KEEP4BITS << 4U);

    /* Check the parameters */
    assert_param(IS_LCD_BASE_FREQ(Freq));

    tmp |= (uint32_t) Freq;
    TSB_LCD->CR1 = tmp;
}


/**  
  * @brief  Set low internal bleeder resistor connection time.
  * @param  Time: Low internal bleeder resistor connection time selection.
  *   This parameter can be one of the following values:
  *     LCD_NOT_CONNECT  : Low internal bleeder resistor is never connected         
  *     LCD_2_POWER_7_DEVIDE_BASE_FREQ  : (2^7)/F_base
  *     LCD_2_POWER_6_DEVIDE_BASE_FREQ  : (2^6)/F_base
  *     LCD_2_POWER_5_DEVIDE_BASE_FREQ  : (2^5)/F_base
  *     LCD_2_POWER_4_DEVIDE_BASE_FREQ  : (2^4)/F_base
  *     LCD_2_POWER_3_DEVIDE_BASE_FREQ  : (2^3)/F_base
  *     LCD_ALWAYS_CONNECT              : Low internal bleeder resistor is always connected 
  *   Note: Refer the parameter in LCD_SetBaseFreq() for ¡°F_base¡±.
  * @retval None.
  */
void LCD_SetLowBleederTime(LCD_LowResistorConnectionTime Time)
{
    /* read CR2 and clear bit7,6,5, which are LCDCR2<LRSE> */
    uint32_t tmp = TSB_LCD->CR2 & LCD_MASK_KEEP5BITS;

    /* Check the parameters */
    assert_param(IS_LCD_LOW_RESISTOR_CONNECTION_TIME(Time));

    tmp |= (uint32_t) Time << 5U;
    TSB_LCD->CR2 = tmp;
}

/**  
  * @brief  Set high internal bleeder resistor value.
  * @param  Value: internal bleeder resistor value selection.
  *   This parameter can be one of the following values:
  *     LCD_BLEEDER_RESISTOR_200K  : 200K ohm   
  *     LCD_BLEEDER_RESISTOR_500K  : 500K ohm
  * @retval None.
  */
void LCD_SetInternalBleeder(LCD_BleederResistorValue Value)
{
    /* read CR2 , keep bit7,6,5,3, and clear bit4, which is LCDCR2<BRH> */
    uint32_t tmp = TSB_LCD->CR2 & ((LCD_MASK_KEEP3BITS << 5U) | (LCD_MASK_KEEP1BIT << 3U));

    /* Check the parameters */
    assert_param(IS_LCD_BLEEDER_RESISTOR_VALUE(Value));

    tmp |= (uint32_t) Value << 4U;
    TSB_LCD->CR2 = tmp;
}

/**  
  * @brief  Set bleeder resistor source (Internal or external ).
  * @param  Source: Internal/external bleeder resistor switching control.
  *   This parameter can be one of the following values:
  *     LCD_BLEEDER_RESISTOR_EXTERNAL  : Use external bleeder resistor   
  *     LCD_BLEEDER_RESISTOR_INTERNAL  : Use internal bleeder resistor
  * @retval None.
  */
void LCD_SetBleederSource(LCD_BleederResistorSource Source)
{
    /* read CR2 , keep bit7,6,5,4, and clear bit3, which is LCDCR2<BRSEL> */
    uint32_t tmp = TSB_LCD->CR2 & (LCD_MASK_KEEP4BITS << 4U);

    /* Check the parameters */
    assert_param(IS_LCD_BLEEDER_RESISTOR_SOURCE(Source));

    tmp |= (uint32_t) Source << 3U;
    TSB_LCD->CR2 = tmp;
}


/**  
  * @brief  Write data to LCD buffer, 1 Seg or 2 Seg a time for a LCD buffer register.
  * @param  TargetBuf: Index of target LCD buffer.
  *   This parameter can be one of the following values:
  *   For one Seg a time:    
  *     LCD_BUF_SEG00, LCD_BUF_SEG01, LCD_BUF_SEG02 
  *      ......
  *     LCD_BUF_SEG37, LCD_BUF_SEG38, LCD_BUF_SEG39
  *  
  *   For two Seg a time:  
  *     LCD_BUF_SEG0100, LCD_BUF_SEG0302, LCD_BUF_SEG0504
  *     ......
  *     LCD_BUF_SEG3534, LCD_BUF_SEG3736, LCD_BUF_SEG3938 
  *   Note: refer to members in enum type: LCD_BUF_INDEX in tmpm061_lcd.h
  * @param  Data: the data will be wrote to LCD buffer. 
  *         When TargetBuf is for two Seg a time: 
  *           High nibble for odd seg. Low nibble for even seg.
  * @retval None.
  */
void LCD_WriteBuf(LCD_BufIndex TargetBuf, uint8_t Data)
{
    uint32_t tmpData = 0U;
    uint32_t tmpAddr = 0U;


    /* Check the parameters */
    assert_param(IS_LCD_BUF_INDEX(TargetBuf));

    if (TargetBuf <= LCD_BUF_SEG39) {   /* is to write 1 nibble */
        assert_param(IS_LCD_BUF_DATA_1N(Data));

        /* get address of LCDBUFxx */
        tmpAddr = (uint32_t) (&TSB_LCD->BUF00);
        tmpAddr += ((uint32_t) TargetBuf >> 1U) << 2U;  /*  offset = [TargetBuf/2] * 4 */
        /* read data in LCDBUFxx */
        tmpData = *((uint32_t *) (tmpAddr));

        if ((uint32_t) TargetBuf % 2U) {        /* TargetBuf is odd, write to high nibble  */
            tmpData &= (uint32_t) 0x0fU;
            tmpData |= (uint32_t) Data << 4U;
        } else {                /* TargetBuf is even, write to low nibble  */
            tmpData &= (uint32_t) 0xf0U;
            tmpData |= (uint32_t) Data;
        }
        /* write back to LCDBUFxx */
        *((uint32_t *) (tmpAddr)) = tmpData;

    } else {                    /* is to write 2 nibble */
        tmpAddr = (uint32_t) (&TSB_LCD->BUF00);
        tmpAddr += ((uint32_t)TargetBuf - (uint32_t)LCD_BUF_SEG0100) << 2U;      /* offset = delta_index * 4 */
        *((uint32_t *) (tmpAddr)) = Data;
    }
}



/** @} */
/* End of group LCD_Exported_Functions */

/** @} */
/* End of group LCD */

/** @} */
/* End of group TX00_Periph_Driver */

#endif                          /* defined(__TMPM061_LCD_H) */
