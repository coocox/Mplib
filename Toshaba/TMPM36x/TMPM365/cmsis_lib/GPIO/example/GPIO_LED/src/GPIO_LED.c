/**
 *******************************************************************************
 * @file    GPIO_LED.c
 * @brief   the application functions of GPIO demo for the
 *          TOSHIBA 'TMPM365' Device Series
 * @version V0.100
 * @date    2012/07/31
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

/* include file */
#include "tmpm365_gpio.h"
#include "TMPM365.h"

#define LED0 (1U<<0U)
#define LED1 (1U<<1U)
#define LED2 (1U<<2U)
#define LED3 (1U<<3U)

#define LED_ALL  (LED0|LED1|LED2|LED3)
#define LED_DATA_PORT   GPIO_PA
#define LED_ON  1U
#define LED_OFF  0U

#define DELAY   0x3FFFFFU

void LED_Init(void);
void LED_Off(uint8_t led);
void LED_On(uint8_t led);

/*************************************************************************
 * Function Name:GPIO_LED
 * Parameters:None
 *
 * Return:None  
 *
 * Description: the main function for demo GPIO
 *
 *************************************************************************/

void GPIO_LED(void)
{
    char LedData[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
    uint32_t i;
    uint8_t j;
    uint8_t data;

    LED_Init();
    while (1) {
        for (j = 0U; j < 8U; ++j) {
            data = LedData[j];
            LED_On(data);
            for (i = 0U; i < DELAY; ++i) {
                /* Do nothing */
            }
        }
    }
}



/*************************************************************************
 * Function Name: LED_Init
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void LED_Init(void)
{
    uint8_t led_off;
    led_off = (uint8_t) (~LED_ALL);
    GPIO_SetOutput(LED_DATA_PORT, LED_ALL);
    GPIO_WriteData(LED_DATA_PORT, led_off);

}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(LED_DATA_PORT, tmp);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp |= led;
    GPIO_WriteData(LED_DATA_PORT, tmp);
}
