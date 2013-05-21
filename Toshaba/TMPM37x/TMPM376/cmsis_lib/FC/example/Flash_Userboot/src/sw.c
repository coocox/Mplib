/**
 ******************************************************************************
 * @file     sw.c
 * @brief    SW driver for the TOSHIBA 'TMPM376' Device Series
 * @version  V0.100
 * @date     2011/12/15
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

/* Connection for following LeD driver 
 * PH0,PH1,PK0,PK1  (98,97,74,73)    <----> PIN3~6 on PJ24  : SW0~7  
 * PH4    (94)                 <----> PIN1   on PJ24  : SWS  
 */

/* Includes ------------------------------------------------------------------*/
#include "sw.h"

/*******************************************************************************
* Function Name  : SW_Init
* Description    : Initialize the GPIO to SW 
* Input          : None 
* Return         : None.
*******************************************************************************/
void SW_Init(void)
{
    GPIO_SetInput(GPIO_PH, 0x03U);
    GPIO_SetInput(GPIO_PK, 0x03U);

    GPIO_SetOutput(SWS_DATA_PORT, GPIO_BIT_2);
}

/*******************************************************************************
* Function Name  : SW_Get
* Description    : Get SW Value
* Input          : SW (choose from SW0 ~ SW7).
* Return         : SW value.
*******************************************************************************/
uint8_t SW_Get(uint8_t sw)
{
    uint8_t tmp = 0U;
    if (sw < 4) {
        GPIO_WriteDataBit(SWS_DATA_PORT, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    } else {
        GPIO_WriteDataBit(SWS_DATA_PORT, GPIO_BIT_2, GPIO_BIT_VALUE_1);
    }
    switch (sw) {
    case SW0:
    case SW4:
        if (GPIO_ReadDataBit(GPIO_PH, GPIO_BIT_0) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW1:
    case SW5:
        if (GPIO_ReadDataBit(GPIO_PH, GPIO_BIT_1) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW2:
    case SW6:
        if (GPIO_ReadDataBit(GPIO_PK, GPIO_BIT_0) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW3:
    case SW7:
        if (GPIO_ReadDataBit(GPIO_PK, GPIO_BIT_1) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    default:
        break;
    }
    return tmp;

}
