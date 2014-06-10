/**
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM341' Device Series
 * @version V0.101
 * @date    2011/03/10
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
#include "tmpm341_tmrb.h"
#include "tmpm341_gpio.h"


/* Private define ------------------------------------------------------------*/

#define TMRB7TIME       0x09c4U /* TMRB7 for PPG , Ftmrb = 20MHz/8, 1ms*8/20M = 2500 = 0x09c4 */
#define DUTYMAX         0x05U   /* DUTY RATE COUNTER MAX */
#define DUTYINIT        0U      /* DUTY RATE COUNTER Initialize */
#define KEYPORT         GPIO_PE /* KEY input port, according to board */

void Tmrb_ppg(void);

/**
  * @brief  delay some time
  * @param  delay time
  * @retval None.
  */
static void delay(uint32_t time)
{
    volatile uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
}

/**
  * @brief  The main function of TMRB_PPG demo
  * @param  None
  * @retval None
  */
/*int main(void)*/
void Tmrb_ppg(void)
{
    uint8_t Rate = 0U;
    uint32_t Duty[5] = { 0x8CAU, 0x753U, 0x4E2U, 0x271U, 0xFAU };       /* duty: 10%, 25%, 50%, 75%, 90% */
    uint8_t keyvalue;

    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;

    GPIO_SetInput(KEYPORT, GPIO_BIT_3); /* set KEY port to input */

    /* Set PD0 as TB7OUT for PPG output */
    GPIO_SetOutput(GPIO_PD, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_3, GPIO_BIT_0);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Cycle = TMRB7TIME;   /* T = 1ms */
    m_tmrb.Duty = Duty[Rate];
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_CLEAR;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY;

    TMRB_Enable(TSB_TB7);
    TMRB_Init(TSB_TB7, &m_tmrb);
    TMRB_SetFlipFlop(TSB_TB7, &PPGFFInital);
    TMRB_SetDoubleBuf(TSB_TB7, ENABLE); /* enable double buffer */
    TMRB_SetRunState(TSB_TB7, TMRB_RUN);

    while (1) {
        /* Press SW1 and release to change the duty */
        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_3);
        } while (GPIO_BIT_VALUE_0 == keyvalue);

        delay(0xFFFU);          /* noise cancel */

        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_3);
        } while (GPIO_BIT_VALUE_1 == keyvalue);

        delay(0xFFFU);          /* noise cancel */

        Rate++;
        if (Rate >= DUTYMAX) {  /* change duty rate */
            Rate = DUTYINIT;
        } else {
            /* Do nothing */
        }

        TMRB_ChangeDuty(TSB_TB7, Duty[Rate]);   /* switch is High again */
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
