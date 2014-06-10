/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of RTC demo for the
 *          TOSHIBA 'TMPM061' Demo
 * @version V0.100
 * @date    2012/04/18
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
 *******************************************************************************
 */

/* include file */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void RTC_Basic(void);

/**
  * @brief  main function.
  * @param  None
  * @retval None
  */

/*int main(void)*/
void RTC_Basic(void)
{
    LCD_Configuration();
    __disable_irq();
    /* enable RTC interrupt */
    NVIC_ClearPendingIRQ(INTRTC_IRQn);

    /* enable RTC interrupt */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_RTC, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
    RTC_Init();

    NVIC_EnableIRQ(INTRTC_IRQn);
    __enable_irq();

    /* waiting for RTC register set finish */
    while (fRTC_1HZ_INT != 1U) {
        /* Do nothing */
    }
    fRTC_1HZ_INT = 0U;

    /* Enable RTC Clock function */
    RTC_EnableClock();

    while (1) {
        if (fRTC_1HZ_INT == 1U) {
            fRTC_1HZ_INT = 0U;

            RTC_Display();
        } else {
            /* Do nothing */
        }
    }
}

/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
