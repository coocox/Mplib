/**
 ******************************************************************************
 * @file     sw.h
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
#ifndef __SW_H
#define __SW_H

#include "TMPM061.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define SW0         0U
#define SW1         1U
#define SW2         2U
#define SW3         3U
#define SW4         4U
#define SW5         5U
#define SW6         6U
#define SW7         7U

#define TSB_SW          TSB_PE
#define TSB_SWS         TSB_SW

#define SW04_BIT        0x01U
#define SW15_BIT        0x02U
#define SW26_BIT        0x04U
#define SW37_BIT        0x08U
#define SWS_BIT         0x10U

#define SW04_BIT_MASK   0xFEU
#define SW15_BIT_MASK   0xFDU
#define SW26_BIT_MASK   0xFBU
#define SW37_BIT_MASK   0xF7U

#define SWS_BIT_MASK    0xEFU


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SW_Init(void);
uint8_t SW_Get(uint8_t SW);

#endif                          /* SW_H */
