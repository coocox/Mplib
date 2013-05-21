/** 
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM370' Device Series 
 * @version V0.100
 * @date    2011/03/22
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
#include "tmpm370_tmrb.h"
#include "TMPM370.h"
#include "tmpm370_gpio.h"


/* Private define ------------------------------------------------------------*/

#define TMRB7TIME       0x09C4U /* TMRB7 for PPG , Ttmrb = 0.1us, 250us/0.1us = 2500 = 0x09C4 */
#define DUTYMAX         0x05U   /* DUTY RATE COUNTER MAX */
#define DUTYINIT        0U      /* DUTY RATE COUNTER Initialize */
#define KEYPORT         GPIO_PA /* KEY input port, according to board */

/* declaration ---------------------------------------------------------------*/
void delay(uint32_t time);

/**
  * @brief  delay some time
  * @param  delay time
  * @retval None.
  */
void delay(uint32_t time)
{
    uint32_t i = 0U;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
}

/**
  * @brief  TMRB_PPG demo
  * @param  None
  * @retval None
  */
void Example_TimerPpg(void)
{
    uint8_t Rate = 0U;
    uint32_t Duty[5] = { 0x8CAU, 0x753U, 0x4E2U, 0x271U, 0xFAU };       /* duty: 10%, 25%, 50%, 75%, 90% */
    uint8_t keyvalue;

    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;

    GPIO_SetInput(KEYPORT, GPIO_BIT_0); /* set KEY port to input */ 

    /* Set PF1 as TB7OUT for PPG output */
    GPIO_SetOutput(GPIO_PF, GPIO_BIT_1);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_1);
    GPIO_SetPullUp(GPIO_PF, GPIO_BIT_1, ENABLE);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Cycle = TMRB7TIME;   /* T = 250us */
    m_tmrb.Duty = Duty[Rate];
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_CLEAR;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY;

    TMRB_Enable(TSB_TB7);
    TMRB_Init(TSB_TB7, &m_tmrb);
    TMRB_SetFlipFlop(TSB_TB7, &PPGFFInital);
    TMRB_SetDoubleBuf(TSB_TB7, ENABLE, TMRB_WRITE_REG_SEPARATE);        /* enable double buffer */
    TMRB_SetRunState(TSB_TB7, TMRB_RUN);

    do {                        /* wait if key is pressed */
        keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_0);
    } while (GPIO_BIT_VALUE_1 == keyvalue);

    delay(0xFFFU);              /* noise cancel */

    while (1) {
        do {                    /* wait if key is released */
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_0);
        } while (GPIO_BIT_VALUE_0 == keyvalue);

        delay(0xFFFU);          /* noise cancel */

        Rate++;
        if (Rate >= DUTYMAX) {  /* change duty rate */
            Rate = DUTYINIT;
        } else {
            /* Do nothing */
        }

        TMRB_ChangeDuty(TSB_TB7, Duty[Rate]); /* change duty rate */

        do {                    /* wait if key is pressed */
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_0);
        } while (GPIO_BIT_VALUE_1 == keyvalue);

        delay(0xFFFU);          /* noise cancel */
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
