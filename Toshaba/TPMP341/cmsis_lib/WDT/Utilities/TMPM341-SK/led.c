/**
 ******************************************************************************
 * @file     led.c
 * @brief    LED driver for the TOSHIBA 'TMPM341' Device Series
 * @version  V0.100
 * @date     2011/02/16
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
 ******************************************************************************
 */

/** include files **/

#include "led.h"
#include "tmpm341_gpio.h"
/** local definitions **/

/** default settings **/

/** external functions **/

/** external data **/

/** internal functions **/

/** private data **/

/** public functions **/
/**
  * @brief  delay some time
  * @param  delay time
  * @retval None.
  */
void delay(uint32_t time)
{
    uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
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
void LEDInit(void)
{
#ifdef M341_SK_BOARD
    GPIO_SetOutput(LED_DATA_PORT, 0x04U);
    GPIO_WriteData(LED_DATA_PORT, 0x04U);
#else
    GPIO_SetOutput(LED_DATA_PORT, 0x0FU);
    GPIO_WriteData(LED_DATA_PORT, 0x0FU);
#endif
}

/*************************************************************************
 * Function Name: LedOff
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LedOff(uint8_t led)
{
#ifdef M341_SK_BOARD
    GPIO_WriteDataBit(LED_DATA_PORT, GPIO_BIT_2, 0U);
#else
    uint8_t reg;
    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= (~led);
    GPIO_WriteData(LED_DATA_PORT, reg);
#endif
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LedOn(uint8_t led)
{
#ifdef M341_SK_BOARD
    GPIO_WriteDataBit(LED_DATA_PORT, GPIO_BIT_2, 1U);
#else
    GPIO_WriteData(LED_DATA_PORT, led);
#endif
}
