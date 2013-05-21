/** 
 *******************************************************************************
 * @file    tmrb_dutydisplay.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/03/26
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmrb_dutydisplay.h"

/**
  * @brief  Duty Rate to String
  * @param  duty number
  * @retval Duty rate string
  */
char *DutyRateToString(uint8_t num)
{
    static char duty[9U] = "Duty:   %";

    switch (num) {
    case 0U:
        duty[6U] = '1';
        duty[7U] = '0';
        break;                  /* Duty: 10% */
    case 1U:
        duty[6U] = '2';
        duty[7U] = '5';
        break;                  /* Duty: 25% */
    case 2U:
        duty[6U] = '5';
        duty[7U] = '0';
        break;                  /* Duty: 50% */
    case 3U:
        duty[6U] = '7';
        duty[7U] = '5';
        break;                  /* Duty: 75% */
    case 4U:
        duty[6U] = '9';
        duty[7U] = '0';
        break;                  /* Duty: 90% */
    default:
        /* Do nothing */
        break;                  /* no other cases */
    }

    return duty;
}
