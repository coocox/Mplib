/**
 ******************************************************************************
 * @file     led.c
 * @brief    LED driver for the TOSHIBA 'TMPM375' Device Series
 * @version  V2.0.2.1
 * @date     2013/02/24
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
 ******************************************************************************
 */

/** include files **/

#include "led.h"

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
    /*Set PC bit0~3 output and turn off all leds */
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_0);
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_1);
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_2);
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_3);

    GPIO_WriteDataBit(GPIO_PG, GPIO_BIT_0, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PG, GPIO_BIT_1, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PG, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PG, GPIO_BIT_3, GPIO_BIT_VALUE_0);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is ON.
 *
 *************************************************************************/

void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PG);
    tmp |= led;
    GPIO_WriteData(GPIO_PG, tmp);
}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is Off.
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PG);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(GPIO_PG, tmp);
}
