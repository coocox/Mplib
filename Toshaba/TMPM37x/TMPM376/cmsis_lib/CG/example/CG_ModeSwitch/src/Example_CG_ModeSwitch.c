/**
 *******************************************************************************
 * @file    Example_CG_ModeSwitch.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM376' Device Series 
 * @version V0.100
 * @date    2011/12/20
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
 
/*========================================================= 
This is a simple demo to change the CPU operation mode. 
Only 2 modes(NORMAL and STOP) are supported . 

SW1 is connected to pin PH1 (pull down, stay as '0' except entering STOP mode )
SW0 is connected to pin PH0 (used as interrupt source INT0 to release STOP mode )


Toggle switch to switch mode as showed below: 
Current mode   Action (Switch)                  Operation        LED display
NORMAL        SW1: '0' -> '1'                   NORMAL --> STOP    LED off
STOP          SW1: Keep "0", SW0:'1' <-> '0'    STOP --> NORMAL    LED on
========================================================= */ 
 
 
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define NORMAL_MODE             ((uint8_t)0x00)
#define STOP_MODE               ((uint8_t)0x01)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
uint8_t gCurrentMode = NORMAL_MODE;
/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Mode_Judgement(void);
void System_Init(void);

/* Main function */
void Example_CG_ModeSwitch(void)
{
    System_Init();

    /* Disable interrupts */
    __disable_irq();
   
    CG_ClearINTReq(CG_INT_SRC_0);
    /* Set to use external interrupt 0 (pin PH0) to wake up system from STOP mode */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_0, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
    NVIC_ClearPendingIRQ(INT0_IRQn);
    NVIC_EnableIRQ(INT0_IRQn);
    __enable_irq();

    
    /* Initialize Variables */
    gCurrentMode = NORMAL_MODE;

    while (1) {
        Mode_Judgement();  

        switch(gCurrentMode) {
        case NORMAL_MODE:
            LED_On(LED0|LED1|LED2|LED3);
            break;
        case STOP_MODE:
            LED_Off(LED0|LED1|LED2|LED3);
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
    
    /* connect the pulled up SW1(@ pin PH1) to '1' is to change to STOP_MODE  */
    /* after that, SW1 should be connected to '0' */
    tmp = SW_Get(SW1);  
    if ((tmp) && (gCurrentMode == NORMAL_MODE)) {
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
    SW_Init();  
    /* Enable interrupt INT0 @ pin PH0 to release STOP mode */
    GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_1, GPIO_BIT_0);    

    /* Configure GPIO for LED */
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
