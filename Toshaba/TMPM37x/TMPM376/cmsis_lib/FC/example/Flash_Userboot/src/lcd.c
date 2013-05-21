/**
 *******************************************************************************
 * @file    lcd.c
 * @brief   The driver of LCD for the
 *           TOSHIBA 'TMPM376' Device Series 
 * @version V0.100
 * @date    2011/12/16
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

/* Connection for following LCD driver 4BIT bus 
 * PG4~7                    <----> PIN19~22 on PJ24  : LCDB4~B7                                  
 * PC1                      <----> PIN11    on PJ24  : LCDE
 * PC2                      <----> PIN12    on PJ24  : LCDRW
 * PC3                      <----> PIN13    on PJ24  : LCDRS
 */

/* Includes ------------------------------------------------------------------*/
#include "lcd.h"
#include <string.h>

//select 4BIT bus or 8BIT bus
//#define BUS_4BIT

#define LCD_DATA    (TSB_PG->DATA)
#define LCDE        (TSB_PC_DATA_PC7)
#define LCDRW       (TSB_PC_DATA_PC6)
#define LCDRS       (TSB_PC_DATA_PC5)

#define LCD_WRITE   0UL
#define LCD_READ    1UL

void Delay_LCD(uint32_t time);

/*******************************************************************************
* Function Name  : E_Pulse
* Description    : Generation a pulse enable the LCD.
* Input          : None.
* Return         : None.
*******************************************************************************/
void E_Pulse(void)
{
    // set E high
    LCDE = 1;
    Delay_LCD(100);
    // set E low
    LCDE = 0;
    Delay_LCD(100);
}

/*******************************************************************************
* Function Name  : Set_Data
* Description    : transfer data to LCD
* Input          : data --- The data will transfer to LCD
* Return         : None.
*******************************************************************************/
void Set_Data(unsigned char data)
{
#ifdef BUS_4BIT
    uint8_t cTemp = 0U;
    cTemp = LCD_DATA & 0x0F;
    data = ((uint8_t) (data << 4)) | cTemp;
#endif
    LCD_DATA = data;
}

/*******************************************************************************
* Function Name  : Send_To_LCD
* Description    : send command or data to LCD
* Input          : data --- command or data
*                  type --- LCD_COMMAND or LCD_CHARACTER
* Return         : None.
*******************************************************************************/
void Send_To_LCD(unsigned char data, unsigned char type)
{
    // enable write
    LCDRW = LCD_WRITE;
    Delay_LCD(100);
#ifdef BUS_4BIT
    // set high nibble of command
    Set_Data((data >> 4));
#else
    Set_Data(data);
#endif
    // set RS port to set command mode or data
    if (type == LCD_COMMAND)
        LCDRS = 0;
    else
        LCDRS = 1;
    E_Pulse();
#ifdef BUS_4BIT
    // set low nibble of command
    Set_Data((data & 0x0F));
    // set RS port to set command mode or data
    if (type == LCD_COMMAND)
        LCDRS = 0;
    else
        LCDRS = 1;
    // pulse to set D0-D3 bits
    E_Pulse();
#endif
}

/*******************************************************************************
* Function Name  : Send_LCD_Text
* Description    : Send the string to LCD
* Input          : str --- pointer of the string
* Return         : None.
*******************************************************************************/
void Send_LCD_Text(char *str)
{
    unsigned char i;
    /* loop over string and send each character */
    for (i = 0; i < strlen(str); i++) {
        Send_To_LCD(str[i], LCD_CHARACTER);
    }
    for (; i < 16; i++)
        Send_To_LCD(' ', LCD_CHARACTER);
}

/*******************************************************************************
* Function Name  : LCD_IO
* Description    : Config LCD to IO
* Input          : data --- The data will transfer to LCD
* Return         : None.
*******************************************************************************/

void LCD_IO(void)
{
#ifdef BUS_4BIT
    TSB_PG->CR |= (uint32_t) 0xF0;
    TSB_PG->PUP |= (uint32_t) 0xF0;
#else
    TSB_PG->CR |= (uint32_t) 0xFF;
    TSB_PG->PUP |= (uint32_t) 0xFF;
#endif
    TSB_PC->CR |= (uint32_t) 0xE0;
    TSB_PC->PUP |= (uint32_t) 0xE0;

}

/*******************************************************************************
* Function Name  : LCD_Configuration
* Description    : Configures LCD
* Input          : None.
* Return         : None.
*******************************************************************************/
void LCD_Configuration(void)
{
    LCD_IO();

    LCDE = 0;
    LCDRW = 0;
    LCDRS = 0;

#ifdef BUS_4BIT
    Set_Data(INIT_WAIT_4BIT);
    E_Pulse();
    Set_Data(INIT_WAIT_4BIT);
    E_Pulse();
    Set_Data(INIT_WAIT_4BIT);
    E_Pulse();
    Set_Data(INIT_4BIT_BUS);
    E_Pulse();
    Send_To_LCD(FUNCTION_SET | CONFIG_4BIT_BUS | CONFIG_2_LINES | CONFIG_5X7_DOT, LCD_COMMAND);
#else
    E_Pulse();
    Set_Data(INIT_WAIT_8BIT);
    E_Pulse();
    Set_Data(INIT_WAIT_8BIT);
    E_Pulse();
    Set_Data(INIT_WAIT_8BIT);
    E_Pulse();
    Send_To_LCD(FUNCTION_SET | CONFIG_8BIT_BUS | CONFIG_2_LINES | CONFIG_5X7_DOT, LCD_COMMAND);
#endif

    // enable display
    Send_To_LCD(DISP_ON, LCD_COMMAND);

    // clear display
    Send_To_LCD(CLR_DISP, LCD_COMMAND);
    Delay_LCD(3000);
}

void Delay_LCD(uint32_t time)
{
    volatile uint32_t i = 0;

    for (i = 0; i < time * 10U; ++i);
}
