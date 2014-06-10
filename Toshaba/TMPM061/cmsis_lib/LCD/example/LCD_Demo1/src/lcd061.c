/**
 *******************************************************************************
 * @file    lcd061.c
 * @brief   The functions to use LCD module in TMPM061.
 * @version V0.100
 * @date    2012/05/22
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */
 
#include "lcd061.h"
#include <stdio.h>

#define MAX_DIGITS 8
void set_digit(uint8_t digit_loc, uint8_t digit, uint8_t dot);

typedef union {
    uint8_t All;
    struct {
        uint8_t low:4;   /* low nibble for even LCD buffer */        
        uint8_t high:4;  /* high nibble for odd LCD buffer */
    } Bit;
} LCD_font8;

#define SPACE 10
const uint8_t number_font_table[] = {
    0xAF,   /* digit '0' */  
    0x06,   /* digit '1' */
    0x6D,   /* digit '2' */
    0x4F,   /* digit '3' */
    0xC6,   /* digit '4' */
    0xCB,   /* digit '5' */
    0xEB,   /* digit '6' */   
    0x0E,   /* digit '7' */  
    0xEF,   /* digit '8' */
    0xCF,   /* digit '9' */
    0x00    /* ' ' (SPACE) */
};                                   


/**
  * @brief  Clear all LCD buffer. 
  * @param  None
  * @retval None
  */
void lcd_clear(void)
{
    LCD_BufIndex tmp = LCD_BUF_SEG0100;
    
    for(; tmp < LCD_BUF_SEG3938; tmp++) {
        LCD_WriteBuf(tmp, 0);
    }
}

/**
  * @brief  Initialize GPIO as LCD driver pins. 
  * @param  None
  * @retval None
  */
void lcd_port_init(void)
{
    /* Port init to SEG and COM */
    TSB_PA->FR1 = 0xFFU;
    TSB_PB->FR1 = 0xFFU;
    TSB_PC->FR1 = 0xFFU;
    TSB_PD->FR1 = 0xFFU;
}

/**
  * @brief  Configure LCD modules. 
  * @param  None
  * @retval None
  */
void lcd_configure_init(void)
{
    /* enable LCD module */
    LCD_Enable();   
    
    /* set LCD duty and bias */
    LCD_SetDutyBias(LCD_DUTY4_BIAS3);           /* 1/4 duty, 1/3 bias */
    
    /* set frame frequency */
    LCD_SetBaseFreq(LCD_FS_DIVIDE_2_POWER_8);   /* F_base = fs / (2^8) */
    
    /* Set bleeder resistor source as internal */
    LCD_SetBleederSource(LCD_BLEEDER_RESISTOR_INTERNAL);
    
    /* Set high internal bleeder resistor value */
    LCD_SetInternalBleeder(LCD_BLEEDER_RESISTOR_500K);

    /* Set low internal bleeder resistor connection time */
    LCD_SetLowBleederTime(LCD_2_POWER_6_DEVIDE_BASE_FREQ);
    
    /* clear LCD buffer */   
    lcd_clear();
    
    /* LCD on */
    LCD_SetDisplay(ENABLE);
  
}


/**
  * @brief  Display digit on LCD 
  * @param  data: The data will be displayed. range: 0 to 99999999
  * @param  dot_loc: The position of dot, count from right, 
  *                   normal range: 1 to 7. 0 is not display dot.
  * @retval None
  */
void display_num(uint32_t data, uint8_t dot_loc)
{
    uint8_t tmp = 0U;
    uint8_t i = MAX_DIGITS ;
    char str_digit[MAX_DIGITS + 1] = {0U};    
    
    if( data > 99999999U ) {
        data = 99999999U;
    }
    /* digit to string, hide '0' in high position */
    sprintf(str_digit, "%08ld", data);
    str_digit[MAX_DIGITS] = 0;
    for(; tmp < MAX_DIGITS - 1; tmp++) {             /* hide highest '0' as space */
        if(str_digit[tmp] == '0') {
            str_digit[tmp] = SPACE;
        } else {
            break;
        }
    }
    
    for( i = 0; i< MAX_DIGITS ; i++){
        tmp = str_digit[ MAX_DIGITS - 1 - i];
        if( tmp == SPACE ) {
           set_digit(i,SPACE, 0);
        } else {
           tmp -= '0';
           if( dot_loc && (i == dot_loc )){
               set_digit(i,tmp, 1);
           }else{
               set_digit(i,tmp, 0);
           }
        }    
    }
}


/**
  * @brief  Display a digit on LCD digit '8' area
  * @param  digit_loc: The position of '8' area, count from right, range: 0 to 7
  * @param  digit: The digit will be displayed. range: 0 to 9.
  * @param  dot: if it is '1', the digit will be displayed with dot.  
  * @retval None
  */

void set_digit(uint8_t digit_loc, uint8_t digit, uint8_t dot)
{
    LCD_font8 font = { 0U };
    LCD_BufIndex idx = LCD_BUF_SEG14;
    
    if( digit > SPACE ) { 
        digit = SPACE;
    } else {
        /* Do nothing */
    }
    font.All = number_font_table[digit];
    if( dot ){
      font.All |= 0x10U;    
    } else {
      /* Do nothing */
    }
            
    if( digit_loc > MAX_DIGITS - 1U ) {
        digit_loc = MAX_DIGITS - 1U;
    } else {
        /* Do nothing */
    }        

    if( digit_loc <= 3U ){
        idx -= (LCD_BufIndex)(digit_loc * 2 );
        LCD_WriteBuf( idx, font.Bit.low);
        LCD_WriteBuf( (LCD_BufIndex)(idx - 1U) , font.Bit.high);
    } else if ( digit_loc == 4U ) {
        LCD_WriteBuf( LCD_BUF_SEG03, font.Bit.low);
        LCD_WriteBuf( LCD_BUF_SEG02, font.Bit.high);
    } else {
        idx = (LCD_BufIndex)(LCD_BUF_SEG2726 + (LCD_BufIndex)(digit_loc - 5U));
        LCD_WriteBuf(idx, font.All);
    }

}

