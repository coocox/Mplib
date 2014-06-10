/**
 ******************************************************************************
 * @file     sw.c
 * @brief    SW driver for the TOSHIBA 'TMPM061' Device Series
 * @version  V0.100
 * @date     2012/04/23
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
    uint8_t reg = TSB_SW->IE;
    reg |= SW04_BIT|SW15_BIT|SW26_BIT|SW37_BIT;
    TSB_SW->IE = reg;
    
    reg = TSB_SWS->CR;
    reg |= SWS_BIT;
    TSB_SWS->CR = reg;
    
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
        TSB_SWS->DATA &= SWS_BIT_MASK;  //set it as 0
    } else {
        TSB_SWS->DATA |= SWS_BIT;
    }
    switch (sw) {
    case SW0:
    case SW4:
        tmp =  TSB_SW->DATA&SW04_BIT;
        break;
    case SW1:
    case SW5:
        tmp =  TSB_SW->DATA&SW15_BIT;
        break;
    case SW2:
    case SW6:
        tmp =  TSB_SW->DATA&SW26_BIT;
        break;
    case SW3:
    case SW7:
        tmp =  TSB_SW->DATA&SW37_BIT;
        break;
    default:
        tmp = 0U;
        break;
    }    
    if(tmp >0U) tmp = 1U;
    return tmp;

}
