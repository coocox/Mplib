/**
 *******************************************************************************
 * @file    lcd.h
 * @brief   The header of the driver of LCD for the
 *           TOSHIBA 'TMPM061' Device Series 
 * @version V0.100
 * @date    2012/03/12
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

#ifndef __LCD_H
#define __LCD_H

#include "TMPM061.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ON  1
#define OFF 0

#define LCD_COMMAND    0
#define LCD_CHARACTER  1

#define   CLR_DISP      0x00000001
#define   DISP          0x00000008
#define   DISP_ON       0x0000000C
#define   DISP_CUR      0x0000000E
#define   DISP_BINK_CUR 0x0000000F
#define   DISP_OFF      DISP
#define   CUR_HOME      0x00000002
#define   SCUR_OFF      DISP_ON
#define	  CUR_UNDER     DISP_CUR
#define   CUR_BLINK     DISP_BINK_CUR
#define   CUR_LEFT      0x00000010
#define   CUR_RIGHT     0x00000014
#define   FIRST_LINE    0x00000080
#define   SECOND_LINE   0x000000C0

#define INIT_WAIT_8BIT  0x30
#define INIT_WAIT_4BIT  0x03
#define INIT_4BIT_BUS   0x02
#define FUNCTION_SET    0x20
#define CONFIG_8BIT_BUS 0x10    /* 8 bit bus */
#define CONFIG_4BIT_BUS 0x00    /* 4 bit bus */
#define CONFIG_2_LINES  0x08    /* 2 lines display */
#define CONFIG_1_LINE   0x00    /* 1 lines display */
#define CONFIG_5X10_DOT 0x04    /* 5*10 dot char font */
#define CONFIG_5X7_DOT  0x00    /* 5*7 dot char font */
#define ENTRY_MODE_SET  0x06

#define LCD_LINE_SIZE 16

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Send_To_LCD(unsigned char data, unsigned char type);
void Send_LCD_Text(char *str);
void LCD_Configuration(void);
#endif                          /* LCD_H */
