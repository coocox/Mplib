/** 
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM373' Device Series 
 * @version V0.100
 * @date    2011/06/13
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

/* declaration ---------------------------------------------------------------*/
void delay(uint32_t time);
void duty_display(void);
uint8_t Rate = 0U;
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
  * @brief  The main function of TMRB_PPG demo
  * @param  None
  * @retval None
  */
void Example_TMRB_PPG(void)
{

    uint32_t Duty[5] = { 0x1194U, 0xEA6U, 0x9C4U, 0x4E2U, 0x1F4U };     /* duty: 10%, 25%, 50%, 75%, 90% */
    uint8_t keyvalue;

    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;

    /* LED & swich initialization */
    LED_Init();
    SW_Init();

    /* Set PA5 as TB3OUT for PPG output */
    GPIO_SetOutput(GPIO_PA, GPIO_BIT_5);
    GPIO_EnableFuncReg(GPIO_PA, GPIO_FUNC_REG_2, GPIO_BIT_5);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Cycle = TMRB6TIME;   /* T = 500us */
    m_tmrb.Duty = Duty[Rate];
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_CLEAR;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY;

    TMRB_Enable(TSB_TB6);
    TMRB_Init(TSB_TB6, &m_tmrb);
    TMRB_SetFlipFlop(TSB_TB6, &PPGFFInital);
    TMRB_SetDoubleBuf(TSB_TB6, ENABLE, TMRB_WRITE_REG_SEPARATE);        /* enable double buffer */
    TMRB_SetRunState(TSB_TB6, TMRB_RUN);

    do {                        /* Handle the condition that start with the SW1 is high*/
        keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_7);
        duty_display();
    } while (GPIO_BIT_VALUE_1 == keyvalue);

    delay(0xFFFFU);             /* noise cancel */

    while (1) {       
        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_7);   /* display when switch is low */
            duty_display();
        } while (GPIO_BIT_VALUE_0 == keyvalue);
        delay(0xFFFFU);         /* noise cancel */
        Rate++;
        if (Rate >= DUTYMAX) {  /* change duty rate */
            Rate = DUTYINIT;
        } else {
            /* Do nothing */
        }
        TMRB_ChangeDuty(TSB_TB6, Duty[Rate]);
        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_7);   /* display when switch is high */
            duty_display();
        } while (GPIO_BIT_VALUE_1  == keyvalue);
        delay(0xFFFFU);         /* noise cancel */
    }
}

void duty_display()
{
    GPIO_WriteData(GPIO_PG, (Rate + 1));
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
