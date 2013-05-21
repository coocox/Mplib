/** 
 *******************************************************************************
 * @file    Example_TMRB_TIMER.c
 * @brief   the application functions of TMRB_TIMER demo for the TOSHIBA
 *          'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/03/26
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/**
  * @brief  The main function of TMRB_TIMER demo
  * @param  None
  * @retval None
  */
void Example_TMRB_TIMER(void)
{
    TMRB_InitTypeDef m_tmrb;

    LED_Init();                 /* LED initialize */
    LED_On(LED_ALL);            /* Turn on LED_ALL */

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    /* periodic time is 1ms(require 1000us) */ 
    m_tmrb.Cycle = Tmrb_Calculator(1000U, m_tmrb.ClkDiv); 
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    /* periodic time is 1ms(require 1000us) */
    m_tmrb.Duty = Tmrb_Calculator(1000U, m_tmrb.ClkDiv); 

    TMRB_Enable(TSB_TB0);
    TMRB_Init(TSB_TB0, &m_tmrb);
    NVIC_EnableIRQ(INTTB00_IRQn);
    TMRB_SetRunState(TSB_TB0, TMRB_RUN);

    while (1U) {
        /* Do nothing */
    }
}

/** 
  * @brief  Calculate timer value to set timer register. 
  * @param  Tmrb_Require_us: The require period which the uint is us. 
            ClkDiv: Select the division for TMRB source clock 
  * @retval the value set to Tmrb timer register. 
  */ 
uint16_t Tmrb_Calculator(uint16_t Tmrb_Require_us, uint32_t ClkDiv) 
{      
    uint32_t T0 = 0U; 
    const uint16_t Div[8U] = {1U, 2U, 8U, 32U, 64U, 128U, 256U, 512U}; 
    
    SystemCoreClockUpdate(); 

    T0 = SystemCoreClock / (1U << ((TSB_CG->SYSCR >> 8U) & 7U));   
    T0 = T0/((Div[ClkDiv])*1000000U); 
         
    return(Tmrb_Require_us * T0); 
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
