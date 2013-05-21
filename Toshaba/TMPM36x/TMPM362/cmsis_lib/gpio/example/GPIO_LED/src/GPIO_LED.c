/**
 *******************************************************************************
 * @file    GPIO_LED.c
 * @brief   the application functions of GPIO demo for the
 *          TOSHIBA 'TMPM362' Device Series
 * @version V0.200
 * @date    2010/06/15
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* include file */
#include "tmpm362_gpio.h"

#define LED1     0x01
#define LED2     0x02

/*  Function declaration */
void demo(void);
void delay(void);
void LED_Init(void);
void LED_Display(uint8_t ucLED);
void LED_On(uint8_t ucLED);
void LED_Off(uint8_t ucLED);

void GPIO_LED(void)
{
    SystemInit();

	LED_Init();
    while (1) {
        demo();
    }
}

void demo(void)
{
	LED_On(LED1);
	delay();
	LED_On(LED2);
	delay();
	LED_Off(LED1);
	delay();
	LED_Off(LED2);
	delay();
}

void delay(void)
{
	int i;
	for(i = 0; i < 1000000; i ++);
}
/*******************************************************************************
* Function Name  : LED_Init
* Description    : Configure the GPIO to LED
* Input          : None.
* Return         : None.
*******************************************************************************/
void LED_Init(void)
{
    TSB_PM->CR = (uint32_t) 0xF0;
    TSB_PM->PUP = (uint32_t) 0xF0;
}


/*******************************************************************************
* Function Name  : LED_On
* Description    : Turn on LED
* Input          : ucLED
* Return         : None.
*******************************************************************************/
void LED_On(uint8_t ucLED)
{
    if ((ucLED & LED1) != 0U) {
        TSB_PM_DATA_PM4 = 0U;
    }
    if ((ucLED & LED2) != 0U) {
        TSB_PM_DATA_PM5 = 0U;
    }
}

/*******************************************************************************
* Function Name  : LED_Off
* Description    : Turn off LED
* Input          : ucLED
* Return         : None.
*******************************************************************************/
void LED_Off(uint8_t ucLED)
{
    if ((ucLED & LED1) != 0U) {
        TSB_PM_DATA_PM4 = 1U;
    }
    if ((ucLED & LED2) != 0U) {
        TSB_PM_DATA_PM5 = 1U;
    }
}
