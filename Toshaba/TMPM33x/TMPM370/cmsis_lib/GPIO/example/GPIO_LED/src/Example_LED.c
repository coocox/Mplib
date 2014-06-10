/**
 ******************************************************************************
 * @file     led.c
 * @brief    LED driver for the TOSHIBA 'TMPM370' Device Series
 * @version  V0.100
 * @date     2010/12/24
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
 ******************************************************************************
 */

/** include files **/

#include "TMPM370.h"
#include "tmpm370_gpio.h"

/** definitions **/
#define LED_DATA_PORT   GPIO_PC
#define LED1            0X01U   /* PC0 */
#define LED2            0X04U   /* PC2 */
#define LED3            0X10U   /* PC4 */
#define LED_ALL_OFF     ~(LED1|LED2|LED3)

#define DELAY   0X5FFFFUL

static void Init_Led(void);
static void Led_On(uint8_t led);
static void Led_Off(uint8_t led);
static void Delay(uint32_t tick);

void Example_LED(void)
{
    Init_Led();

    while (1)
    {

    	Delay(DELAY);
    	Led_On(LED1 | LED2 | LED3);

        Delay(DELAY);
    	Led_Off(LED1 | LED2 | LED3);

    }

}


/*************************************************************************
 * Function Name: Init_Led
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void Init_Led()
{
    GPIO_SetOutput(LED_DATA_PORT, LED1 | LED2 | LED3);
    GPIO_WriteDataBit(LED_DATA_PORT, LED1, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(LED_DATA_PORT, LED2, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(LED_DATA_PORT, LED3, GPIO_BIT_VALUE_0);
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but all of others is OFF
 *
 *************************************************************************/

void Led_On(uint8_t led)
{
    uint8_t reg;

    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= LED_ALL_OFF;
    reg |= led;
    GPIO_WriteData(LED_DATA_PORT, reg);
}

/*************************************************************************
 * Function Name: Led_Off
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void Led_Off(uint8_t led)
{
    uint8_t reg;

    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= (~led);
    GPIO_WriteData(LED_DATA_PORT, reg);
}

static void Delay(uint32_t tick)
{
	volatile uint32_t Cnt = tick;
	while(Cnt--);
}

