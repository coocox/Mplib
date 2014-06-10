/**
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM061' Device Series 
 * @version V0.100
 * @date    2012/05/20
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
/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tmpm061_int.h"
#include "cg.h"
#include "led.h"
#include "sw.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define NORMAL_MODE             ((uint8_t)0x00)
#define STOP_MODE               ((uint8_t)0x01)

void CG_ModeSwitch(void);

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
uint8_t gCurrentMode = NORMAL_MODE;
/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Mode_Judgement(void);
void System_Init(void);

/* Main function */
/*int main(void)*/
void CG_ModeSwitch(void)
{
    System_Init();

    /* Disable interrupts */
    __disable_irq();
    CG_ClearINTReq(CG_INT_SRC_0);
    /* Set external interrupt to wake up system */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_0, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
    NVIC_ClearPendingIRQ(INT0_IRQn);
    NVIC_EnableIRQ(INT0_IRQn);
    __enable_irq();

    /* Initialize Variables */
    gCurrentMode = NORMAL_MODE;

    while (1) {
        Mode_Judgement();  /* Push SW0 to change Mode */

        switch(gCurrentMode) {
        case NORMAL_MODE:
            LED_On(LED_ALL);
            break;
        case STOP_MODE:
            LED_Off(LED_ALL);
            CG_NormalToStop();
            System_Init();
            gCurrentMode = NORMAL_MODE;
            break;
        default:
            gCurrentMode = NORMAL_MODE;
            break;
        }
    }
}

/**
  * @brief  Judge whether go to STOP_MODE
  * @param  None.
  * @retval None.
  */
void Mode_Judgement(void)
{
    uint8_t tmp = 0U; 
    tmp =  SW_Get(SW0);
    if ((tmp == 0x01) && (gCurrentMode == NORMAL_MODE)) {
        gCurrentMode = STOP_MODE;
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  Initialize system
  * @param  None.
  * @retval None.
  */
void System_Init(void)
{
    /* Initialize system */
    CG_SetSystem();

    /* Configure GPIO */
    TSB_PE->IE |= 0x01;
    /* INT0  input initial */ 
    TSB_PF->FR1 |= 0x02;
    TSB_PF->IE |= 0x02;
    /* Configure GPIO to LED */
    LED_Init();
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
