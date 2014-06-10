/**
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM061' Device Series
 * @version V0.100
 * @date    2012/05/18
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
#include "TMPM061_tmrb.h"
/* Private define ------------------------------------------------------------*/

#define TMRB0TIME       0x03E8U /* TMRB0 for PPG , Ttmrb = 0.5us, 500us/0.5us = 1000 = 0x03E8 */
#define DUTYMAX         0x05U   /* DUTY RATE COUNTER MAX */
#define DUTYINIT        0U      /* DUTY RATE COUNTER Initialize */

void TMRB_PPG(void);

/**
  * @brief  Delay some time
  * @param  None
  * @retval None
  */
void delay(void)
{
    uint32_t i = 0U;
    for(i = 0U; i<0xFFFFU; i++){
      /* Do nothing */
    }
}

/**
  * @brief  The main function of TMRB_PPG demo
  * @param  None
  * @retval None
  */
/*int main(void)*/
void TMRB_PPG(void)
{
    uint8_t Rate = 0U;
    uint32_t Duty[5] = { 0x384U, 0x2EEU, 0x1F4U, 0xFAU, 0x64U  };       /* duty: 10%, 25%, 50%, 75%, 90% */

    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;

    /* Set PG0 as TB0OUT for PPG output */
    TSB_PG->CR |= 0x01;
    TSB_PG->FR1 |= 0x01;

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Cycle = TMRB0TIME;   /* T = 1ms */
    m_tmrb.Duty = Duty[Rate];
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_CLEAR;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY;

    TMRB_Enable(TSB_TB0);
    TMRB_Init(TSB_TB0, &m_tmrb);
    TMRB_SetFlipFlop(TSB_TB0, &PPGFFInital);
    TMRB_SetDoubleBuf(TSB_TB0, ENABLE); /* enable double buffer */
    TMRB_SetRunState(TSB_TB0, TMRB_RUN);

    while (1)
    {
        /* change duty rate */
        delay();
        if (Rate++ >= DUTYMAX)
        {
            Rate = DUTYINIT;
        }

        TMRB_ChangeDuty(TSB_TB0, Duty[Rate]);
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
