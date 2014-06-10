/**
 *******************************************************************************
 * @file    lcd061.c
 * @brief   The functions to use LCD module in TMPM061-SK board.
 * @version V0.100
 * @date    2012/08/17
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


const uint8_t number_font_table[] = {
    0x3F,   /* digit '0' */  
    0x06,   /* digit '1' */
    0x5B,   /* digit '2' */
    0x4F,   /* digit '3' */
    0x66,   /* digit '4' */
    0x6D,   /* digit '5' */
    0x7D,   /* digit '6' */   
    0x07,   /* digit '7' */  
    0x7F,   /* digit '8' */
    0x6F    /* digit '9' */
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
    LCD_SetDutyBias(LCD_STATIC);           /* static LCD on M061-SK board */
    
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
  * @brief  Display 4 digit on LCD panel which can displa"8.8.8.8"
  * @param  p: pointer point to the string which will be displayed. 
  * @param  dot_pos: The position of dot, count from left, range: 1 to 3, 0 is not display dot.
  * @retval None
  */
void display_4digit(unsigned char *p, uint8_t dot_pos)
{
    uint8_t tmp = 0U;
    uint8_t loop = 0U;
    uint8_t idx = 0U, dat = 0U;  
    
    LCD_BufIndex buf_head = LCD_BUF_SEG0100;
    
    for( ; loop < 4U; loop++) { /* total 4 digit need to display */
        tmp = *(p + loop);
        if( tmp == ' ' ) {      /* is SPACE, hide it */
            tmp = 0U;
        } else {
            tmp = number_font_table [ tmp - '0' ];
            if( dot_pos == loop + 1U) { /* if dot_pos isn't '0', should display dot */
                tmp |= 0x80U;
            } else {
                /* Do nothing */
            }
        }

        /* now 'tmp' store the font data, we will set its 8 bit info to 8 LCD Segment buffer */
        for(idx = 0U; idx < 4U; idx++) {
            dat = 0U;
            if( tmp & 0x01U ) {
                dat |= 0x01U;
            } else { 
                /* Do nothing */
            }
            if( tmp & 0x02U ) {
                dat |= 0x10U;
            } else { 
                /* Do nothing */
            }
            LCD_WriteBuf( (LCD_BufIndex)(buf_head + idx) , dat );   /* set 2 segment at one time */
            tmp >>= 2U;
         }
         buf_head += 4U;    /* for the static LCD, one digit '8' need 8 seg, */
                            /*  but we process 2 seg at one time, so, only need to add 4 here */
    }

}

