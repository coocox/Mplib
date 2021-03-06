/**
 *******************************************************************************
 * @file    Example_CG_ModeSwitch.c
 * @brief   the application functions of CG_ModeSwitch demo for the TOSHIBA
 *          'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/03/06
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

fosc : Clock generated by internal oscillator. Clock input from the X1 and X2 pins.
fpll : Clock multiplied by PLL.
fc : Clock specified by CGPLLSEL<PLLSEL> (high-speed clock).
fgear : Clock specified by CGSYSCR<GEAR[2:0]>.
fsys : Clock specified by CGCKSEL(system clock).
fperiph : Clock specified by CGSYSCR<FPSEL[2:0]>.
��T0 : Clock specified by CGSYSCR<PRCK[2:0]> (prescaler clock).



 */
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
    CG_ClearINTReq(CG_INT_SRC_7);
    /* Set external interrupt to wake up system */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_7, CG_INT_ACTIVE_STATE_RISING, ENABLE);
    NVIC_ClearPendingIRQ(INT7_IRQn);
    NVIC_EnableIRQ(INT7_IRQn);
    __enable_irq();

    /* Initialize Variables */
    gCurrentMode = NORMAL_MODE;

    while (1) {
        Mode_Judgement();       /* Push SW1 to change Mode */

        switch (gCurrentMode) {
        case NORMAL_MODE:
            LED_On(LED_ALL);
            common_uart_disp("NORMAL MODE\r\n");
            break;
        case STOP_MODE:
            LED_Off(LED_ALL);
            common_uart_disp("STOP MODE\r\n");
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
    uint8_t SW1_info = 0U;
    SW1_info = SW_Get(SW1);

    if ((1U == SW1_info) && (gCurrentMode == NORMAL_MODE)) {
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

    /* Configure GPIO to INT7 */
    GPIO_SetInput(GPIO_PE, GPIO_BIT_2); /* Set port E pin2 to input */
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_4, GPIO_BIT_2);   /* Set port E pin2 for INT7 */
    
    /* Configure GPIO to SW and LED*/
    SW_Init();
    LED_Init();
    
    /* Configure UART */
    hardware_init(UART_RETARGET);
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
