/** 
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of TMRD interval timer demo for the TOSHIBA
 *          'TMPM341' Device Series 
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

#include "tmpm341_tmrd.h"
#include "tmpm341_cg.h"
#include "led.h"

void Tmrd_Interval_timer(void);

/* fosc = 10MHz(external high-speed oscillator)
 * fpll = 8 * fosc = 80MHz(in this demo, PLL multiplying value is set to 8 multiplying)
 * ftmrd = fpll = 80MHz(in this demo, ftmrd = fpll, please see CG_SetFtmrdSrc())
 * So the value of TIME_500US is 500us*ftmrd = 40000 = 0x9C40
 */
#define TIME_500US    ((uint16_t)0x9C40U)

/*int main(void)*/
void Tmrd_Interval_timer(void)
{
    LEDInit();

    /* TMRD CG setting */
    CG_SetFtmrdSrc(CG_FTMRD_SRC_FPLL);
    CG_SetTMRDClk(ENABLE);

    /* TMRD mode setting */
    TMRD_SetMode(TMRD_MODE_BOTH_TMR);

    /* TMRD IDLE mode */
    TMRD_SetRunStateInIdle(TSB_TD0, TMRD_RUN);

    /* TMRD enable clock signal */
    TMRD_Enable(TSB_TD0);

    /* Set the TMRD prescaler */
    TMRD_SetClkDivision(TSB_TD0, TMRD_CLK_DIV_1);

    /* Set the upcounter clear mode */
    TMRD_SetUpCntCtrl(TSB_TD0, TMRD_AUTO_CLEAR);

    /* Direct update the compare register */
    TMRD_SetCMPRegWritePath(TSB_TD0, TMRD_CMP_WRITE_DIRECT);

    /* Set the value to timer register */
    TMRD_ChangeTiming(TMRD_TIMING_TD0_CYCLE, TIME_500US);       /* 500us */

    /* Indirct update the compare register */
    TMRD_SetCMPRegWritePath(TSB_TD0, TMRD_CMP_WRITE_INDIRECT);

    /* Enable TMRD intterrupt */
    TMRD_SetCMP0INTSrc(TSB_TD0, TMRD_INT_MATCH_CYCLE);

    NVIC_EnableIRQ(INTTD0CMP0_IRQn);

    /* Start to run TMRD */
    TMRD_SetRunState(TSB_TD0, TMRD_RUN);

    while (1) {
        /* Do nothing */
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
