/**
 ******************************************************************************
 * @file     led.c
 * @brief    LED driver for the TOSHIBA 'TMPM061' Device Series
 * @version  V0.100
 * @date     2012/04/20
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

/** local definitions **/

/** default settings **/

/** external functions **/

/** external data **/

/** internal functions **/

/** private data **/

/** public functions **/

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
    uint8_t reg = 0U;
    /* LED0~LED3 */
    reg = TSB_LED->CR;
    reg |= LED_ALL;
    TSB_LED->CR = reg;

    reg = TSB_LED->DATA;
    reg &= (~LED_ALL);
    TSB_LED->DATA = reg;
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
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = TSB_LED->DATA;
    tmp &= (~led);
    TSB_LED->DATA = tmp;
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
void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = TSB_LED->DATA;
    tmp |= led;
    TSB_LED->DATA = tmp;  
}
