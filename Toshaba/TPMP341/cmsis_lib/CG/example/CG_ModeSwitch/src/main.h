/**
 *******************************************************************************
 * @file    main.h
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM341' Device Series 
 * @version V0.101
 * @date    2010/02/17
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
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tmpm341_cg.h"
#include "tmpm341_gpio.h"
#include "tmpm341_int.h"
#include <string.h>
#include <stdio.h>
#include "cg.h"


#define M341_SK_BOARD

/* Private typedef -----------------------------------------------------------*/
typedef enum { SLEEP = 0, WAKE = 1 } SYSSTAT;
/* Private define ------------------------------------------------------------*/
#ifdef M341_SK_BOARD
#define TSW_PORT        GPIO_PE
#define TSWBITS         0x08U
#define TSWRELEASE      0x08U      /* KEYRELEASE */
#define TSW1 0x00
#else
#define TSW_PORT        GPIO_PG
#define TSWBITS         0x80U
#define TSWRELEASE      0U      /* KEYRELEASE */
/* For Toggle Switch */
#define TSW1 0x80U
#endif

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
extern SYSSTAT fSysSleep;

/* External function prototypes ----------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void PrintCode(char *, uint16_t, uint32_t);
void Delay(uint32_t time);
void GPIO_SetINT(void);
#endif
/*********************************** END OF FILE ******************************/
