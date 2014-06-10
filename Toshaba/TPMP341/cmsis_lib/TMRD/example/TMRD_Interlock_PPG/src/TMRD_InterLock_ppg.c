/** 
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of TMRD interlock PPG demo for the TOSHIBA
 *          'TMPM341' Device 
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
#include "tmpm341_gpio.h"
#include "tmpm341_cg.h"


void Tmrd_interlock_ppg(void);

/*
 * Cycle is 500us:
 * fosc = 10MHz(external high-speed oscillator)
 * fpll = 8 * fosc = 80MHz(in this demo, PLL multiplying value is set to 8 multiplying)
 * ftmrd = fpll = 80MHz(in this demo, ftmrd = fpll, please see CG_SetFtmrdSrc())
 * So the value is 500us*ftmrd = 40000 = 0x9C40
 *
 * Duty is 50%:
 * Set LeadingTiming0 to 0x0000, then TrailingTiming0 is Cycle/2 = 0x4E20(250us)
 * LeadingTiming1 and TrailingTiming1 are not used, so keep their value to 0x0000.
 *
 * Phase shift is 120 degree:
 * The phase shift can be calculated by using the formula:
 *
 * ¦È = 360 degree*(PhaseShiftTiming/(Cycle+1))
 *
 * so in this demo, PhaseShiftTiming should be set to Cycle/3 = 0x3415(167us)
 */
#define TIME_CYCLE               ((uint16_t)0x9C40U)    /* 500us */
#define TIME_DUTY                ((uint16_t)0x4E20U)    /* 250us */
#define TIME_PHASE_SHIFT         ((uint16_t)0x3415U)    /* 500/3= 167us */

/*int main(void)*/
void Tmrd_interlock_ppg(void)
{
    TMRD_TimingTypeDef timestruct = { 0U };

    timestruct.Cycle = TIME_CYCLE;
    timestruct.TrailingTiming0 = TIME_DUTY;
    timestruct.PhaseShiftTiming = TIME_PHASE_SHIFT;

    /* TD0OUT0, TD0OUT1, TD1OUT0, TD1OUT1 port setting */
    GPIO_SetOutput(GPIO_PE, GPIO_BIT_4 | GPIO_BIT_5 | GPIO_BIT_6 | GPIO_BIT_7);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_3, GPIO_BIT_4 | GPIO_BIT_5 | GPIO_BIT_6 | GPIO_BIT_7);

    /* TMRD CG setting */
    CG_SetFtmrdSrc(CG_FTMRD_SRC_FPLL);
    CG_SetTMRDClk(ENABLE);

    /* TMRD mode setting */
    TMRD_SetMode(TMRD_MODE_INTERLOCK_PPG);

    /* TMRD IDLE mode */
    TMRD_SetRunStateInIdle(TSB_TD0, TMRD_RUN);
    TMRD_SetRunStateInIdle(TSB_TD1, TMRD_RUN);

    /* TMRD enable clock signal */
    TMRD_Enable(TSB_TD0);
    TMRD_Enable(TSB_TD1);

    /* Set the TMRD prescaler */
    TMRD_SetClkDivision(TSB_TD0, TMRD_CLK_DIV_1);

    /* Set the PPG output edge */
    TMRD_SetPPGInitLeadingEdge(TMRD_PPG_CHANNEL_A0, TMRD_WAVE_EDGE_RISING);
    TMRD_SetPPGInitLeadingEdge(TMRD_PPG_CHANNEL_B0, TMRD_WAVE_EDGE_RISING);

    /* Direct update the compare register */
    TMRD_SetCMPRegWritePath(TSB_TD0, TMRD_CMP_WRITE_DIRECT);
    TMRD_SetCMPRegWritePath(TSB_TD1, TMRD_CMP_WRITE_DIRECT);

    /* Set the value to timer register */
    TMRD_SetInitTiming(TSB_TD0, &timestruct);
    TMRD_SetInitTiming(TSB_TD1, &timestruct);

    /* Set the relation of phase A and B */
    TMRD_SetPhaseRelation(TMRD_PHASE_DELAY_OR_SAME);

    /* Indirct update the compare register */
    TMRD_SetCMPRegWritePath(TSB_TD0, TMRD_CMP_WRITE_INDIRECT);
    TMRD_SetCMPRegWritePath(TSB_TD1, TMRD_CMP_WRITE_INDIRECT);

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
