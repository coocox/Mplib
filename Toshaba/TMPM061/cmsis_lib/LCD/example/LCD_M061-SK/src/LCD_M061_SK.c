/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of LCD demo for the TMPM061-SK board
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

/* --------------------------------------------------------------------------------
   This demo use the static LCD on TMPM061-SK board,(type: S5026D with 4 digit '8' ) 
   the digit in the string ¡®   0123456789¡¯ will be displayed on the LCD one by one 
   in adjustable interval time.
   
   The display order are: 
    1.	display     0 
    2.	display    01 
    3.	display   012 
    4.	display  0123 
    5.	display  123.4 
    6.	display  23.45 
    7.	display  3.456 
    8.	display  4567
    9.	display  5678
    10.	display  6789  
    11.	goto step 1 above

 --------------------------------------------------------------------------------*/

/* include file */
#include "tmpm061_lcd.h"
#include "lcd061.h"

void LCD_Demo_2(void);

struct mySoftTimer {
    uint8_t flag_TimeUp;
    uint8_t flag_Blink;
    uint32_t timer_Cnt;
}softT;

#define DELAYCONST  200000U
static void softTimer_init(void);
static void softTimer_Run(void); 

uint8_t cnt = 0U, idx = 0U, dot = 0U;
unsigned char str[] = "   0123456789";

/*int main()*/
void LCD_Demo_2(void)
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
            
            if(idx > 3U && idx < 7U){
                dot = 7U - idx;
            } else {
                dot = 0U;
            }
            display_4digit( &str[idx], dot );
            
            idx++;
            if( idx > 9U ) {
                idx = 0U;
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
