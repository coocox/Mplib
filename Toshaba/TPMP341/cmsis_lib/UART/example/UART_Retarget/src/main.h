/** 
 *******************************************************************************
 * @file    main.h
 * @brief   the application functions of UART_Retarget demo for the TOSHIBA
 *          'TMPM341' Device Series 
 * @version V0.100
 * @date    2011/01/25
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
 *******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include "tmpm341_uart.h"
#include "tmpm341_gpio.h"
#include "tmpm341_uart_int.h"
#include "uart.h"
#include <stdio.h>

#define M341_SK_BOARD

/* Private define ------------------------------------------------------------*/
#ifdef M341_SK_BOARD
/* use USER SW1 on TMPM341-SK board to trigger the transmission*/
#define TSW_PORT        GPIO_PE
#define TSWBITS         0x08U
#define TSWRELEASE      0x08U      /* KEYRELEASE */
#define TSW1 0x00
#else
#define TSW_PORT        GPIO_PD
#define TSWBITS         0x07U
#define TSWRELEASE      0U      /* KEYRELEASE */
/* For Toggle Switch */
#define TSW1 0x01U
#endif

/* Private function prototypes -----------------------------------------------*/
void TSW_Configuration(void);

#endif
