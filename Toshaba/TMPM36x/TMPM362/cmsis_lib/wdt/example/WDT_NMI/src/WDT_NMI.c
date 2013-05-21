/**
 *******************************************************************************
 * @file    WDT_NMI.c
 * @brief   The application functions of WDT demo for the
 *          TOSHIBA 'TMPM362' Device Series 
 * @version V0.100
 * @date    2010/06/24
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
 *******************************************************************************
 */

#include "tmpm362_wdt.h"

//#define DEMO2 

#define FLG_WDT    ((uint8_t)0x00000001)
#define FLG_NMI    ((uint8_t)0x00000002)

uint8_t uCont = 0U;

/* Function declaration */
void Delay(uint32_t time);
void NMI_Handler(void);


/* WDT_NMI function */
void WDT_NMI(void)
{
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.DetectTime = WDT_DETECT_TIME_EXP_25;
    WDT_InitStruct.OverflowOutput = WDT_NMIINT;

    SystemInit();

    /* WDT and LED configuration */
    TSB_PM->CR = (uint32_t) 0xF0;
    TSB_PM->PUP = (uint32_t) 0xF0;
	TSB_PM->DATA = (uint32_t)0xFF;
	
    WDT_Init(&WDT_InitStruct);
    WDT_Enable();

    while (1) {
#ifdef DEMO2
        Delay(500U);
        WDT_WriteClearCode();
        TSB_PM_DATA_PM6 = !TSB_PM_DATA_PM6;
#endif
    }
}

void Delay(uint32_t time)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < (time * 800U); ++i);
}

/**
  * @brief  The NMI interrupt request function.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
    uint8_t uRegVal = 0U;
    uRegVal = (uint8_t) TSB_CG->NMIFLG;
    switch (uRegVal) {
    case FLG_WDT:
        uCont++;
        TSB_PM_DATA_PM4 = !TSB_PM_DATA_PM4;
        if (uCont == 5U) {
            WDT_Disable();
            uCont = 0U;
        }
        break;
    case FLG_NMI:
        /* Do nothing */
        break;
    default:
        /* Do nothing */
        break;
    }
}
