/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of LCD demo for the
 *          TOSHIBA 'TMPM061' Demo
 * @version V0.100
 * @date    2012/05/16
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

/* --------------------------------------------------------------------------------
   This demo use an customer¡¯s LCD,(type: JY09484G from Hebei JIYA Electronic Co.,Ltd. ) 
   the digit in the string ¡®12345678¡¯ will be displayed on the digit ¡®8¡¯ area one by one 
   in adjustable interval time.
   
   The display order are: 
    1.	display 1 in the right one
    2.	display 12 in right two digit
    3.	display 123 in right three digit
    4.	display 1234 in right four digit
    5.	display 12345 in right five digit
    6.	display 123456 in right six digit
    7.	display 1234567 in right sever digit
    8.	display 12345678 in all the eight digit
    9.	goto step 1 above

 --------------------------------------------------------------------------------*/

/* include file */
#include "tmpm061_lcd.h"
#include "lcd061.h"

void LCD_Demo_1(void);

struct mySoftTimer {
    uint8_t flag_TimeUp;
    uint8_t flag_Blink;
    uint32_t timer_Cnt;
}softT;

#define DELAYCONST  200000U
static void softTimer_init(void);
static void softTimer_Run(void); 

uint32_t cnt = 0U;
const uint32_t digit_array[] = { 1, 12, 123, 1234, 12345, 123456,1234567,12345678 };

/*int main()*/
void LCD_Demo_1(void)
{
    /* initialize LCD pins */
    lcd_port_init();
    
    /* initialize LCD relative settings */
    lcd_configure_init();
    
    /* initialize soft timer */
    softTimer_init();

    while (1U) {

        softTimer_Run();  
        if(softT.flag_TimeUp) {
            softT.flag_TimeUp = 0;
            
            display_num( digit_array[cnt], 0U);
            if( ++cnt > 7 ) {
                cnt = 0;
            } else {
                /* Do nothing */
            }
        } else {
            /* Do nothing */
        }
    }
}



/**
  * @brief  Initialize a several mS timer. 
  * @param  None
  * @retval None
  */
static void softTimer_init(void)
{
    softT.flag_TimeUp = 0U;
    softT.flag_Blink = 0U;
    softT.timer_Cnt = DELAYCONST;
}  
  

/**
  * @brief  Simulate a several mS timer. 
  * @param  None
  * @retval None
  */
static void softTimer_Run(void)
{
    if( softT.timer_Cnt == 0U ){
        softT.flag_TimeUp = 1U;
        softT.flag_Blink = (uint8_t)~softT.flag_Blink; 
        softT.timer_Cnt = DELAYCONST;
    } else {
        softT.timer_Cnt --;
    }
}


#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
