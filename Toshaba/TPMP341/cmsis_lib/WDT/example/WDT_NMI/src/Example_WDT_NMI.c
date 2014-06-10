/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of WDT demo for the
 *          TOSHIBA 'TMPM341' Device Series
 * @version V0.100
 * @date    2011/03/08
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

#include "tmpm341_wdt.h"
#include "led.h"

void WDT_NMI(void);

extern uint8_t fIntNMI;
//#define DEMO2
void Delay(uint32_t time)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < (time * 800U); ++i) {
        /* Do nothing */
    }
}

void WDT_NMI(void)
{
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.DetectTime = WDT_DETECT_TIME_EXP_25;
    WDT_InitStruct.OverflowOutput = WDT_NMIINT;

    LEDInit();

    LedOff(LED0 | LED1);
    WDT_Init(&WDT_InitStruct);
    WDT_Enable();

    while (1) {
        if (fIntNMI == 1U) {
            fIntNMI = 0U;
            LedOn(LED3);
            Delay(500U);
            LedOff(LED3);
            Delay(500U);
            WDT_Disable();
        } else {
            /* Do nothing */
        }
#ifdef DEMO2
        Delay(500U);
        WDT_WriteClearCode();
        LedOn(LED2);
        Delay(500U);
        LedOff(LED2);
#endif
    }
}

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
