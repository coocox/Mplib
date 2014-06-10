/**
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM341' Device Series
 * @version V0.101
 * @date    2011/02/17
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "LED.h"

//#define DEBUG

void CG_ModeSwitch(void);
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
SYSSTAT fSysSleep = WAKE;
/* Main function */
/*int main(void)*/
void CG_ModeSwitch(void)
{
    uint8_t TSW_info = 0U;

    /* Initialize system */
    CG_SetSystem();
    GPIO_SetINT();
    LEDInit();
    LedOn(LED0);

#ifdef DEBUG
    printf("TMPM341 CG_ModeSwitch DEMO\r\n");
#endif
    while (1) {
        TSW_info = GPIO_ReadData(TSW_PORT) & TSWBITS;
        if (TSW_info == TSW1) {
            fSysSleep = SLEEP;
            LedOff(LED0);
#ifdef DEBUG
            printf("Now, Going to Sleep\r\n");
#endif
            CG_NormalToStop1();

            /* connect PG3(INT0) to VCC to recover from STOP mode */
            LedOn(LED0);
            fSysSleep = WAKE;
            NVIC_DisableIRQ(INT0_IRQn);
#ifdef DEBUG
            printf("Wakeup from Sleep\r\n");
#endif
        } else {
            /* Do nothing */
        }
    }

}


/**
  * @brief  Configure I/O ports for INT
  * @param  None
  * @retval None
  */
void GPIO_SetINT(void)
{
    //for INT0
    GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_3, DISABLE);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_2, GPIO_BIT_3);
    GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_3, ENABLE);
    GPIO_SetOpenDrain(GPIO_PG, GPIO_BIT_3, DISABLE);

    //for SW1
#ifdef M341_SK_BOARD
    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_3, DISABLE);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_3, ENABLE);
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_3, ENABLE);
#else
    GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_7, DISABLE);
    GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_7, ENABLE);
    GPIO_SetPullUp(GPIO_PG, GPIO_BIT_7, ENABLE);
#endif

}

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
/*********************************** END OF FILE ******************************/
