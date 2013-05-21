/**
 *******************************************************************************
 * @file    Example_WDT_NMI.c
 * @brief   The application functions of WDT demo for the
 *          TOSHIBA 'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/1/24
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

#include "tmpm375_wdt.h"
#include "tmpm375_gpio.h"
#include "led.h"
#define  DEMO2
extern volatile uint8_t fIntNMI;

void Delay(uint32_t time);
/*******************************************************************************
* Function Name  : Delay
* Description    : delay time
* Input          : time.
* Return         : None.
*******************************************************************************/
void Delay(uint32_t time)
{
    volatile uint32_t TimeCounter = 0U;
    uint32_t DelayTime = 0U;

    DelayTime = time * 800U;
    for (TimeCounter = 0U; TimeCounter < DelayTime; TimeCounter++) {
        /* Do nothing */
    }
}

/*******************************************************************************
* Function Name  : main
* Description    : main function
* Input          : None.
* Return         : None.
*******************************************************************************/
void Example_WDT_NMI(void)
{
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.DetectTime = WDT_DETECT_TIME_EXP_25;
    WDT_InitStruct.OverflowOutput = WDT_NMIINT;

    LED_Init();

    WDT_Init(&WDT_InitStruct);
    WDT_Enable();

    while (1U) {
        if (fIntNMI == 1U) {
            fIntNMI = 0U;
            WDT_Disable();
            LED_On(LED1);
            Delay(6500U);
            LED_Off(LED1);
            Delay(500U);
            
            

        } else {
            /* Do nothing */
        }

#ifdef DEMO2
        Delay(3500U);
        WDT_WriteClearCode();
        LED_On(LED0);
        Delay(3500U);
        LED_Off(LED0);
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
