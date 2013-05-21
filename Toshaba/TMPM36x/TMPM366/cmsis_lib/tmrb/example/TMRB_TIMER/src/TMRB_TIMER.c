/** 
 *******************************************************************************
 * @file    TMRB_TIMER.c
 * @brief   the application functions of TMRB_TIMER demo for the TOSHIBA
 *          'TMPM366' Device Series 
 * @version V0.100
 * @date    2011/03/07
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
#include "tmpm366_cg.h"
#include "tmpm366_gpio.h"
#include "tmpm366_tmrb.h"

#define CG_WUODR_EXT     ((uint16_t)0x0FFF)
#define CG_WUODR_INT     ((uint16_t)0x07D0)
#define CG_WUODR_PLL     ((uint16_t)0x01F4)

#define LED1 (1U<<0U)
#define LED2 (1U<<1U)
#define LED3 (1U<<2U)
#define LED4 (1U<<3U)
#define LED5 (1U<<4U)
#define LED6 (1U<<5U)
#define LED7 (1U<<6U)
#define LED8 (1U<<7U)

#define TMRB_1MS        0x1770U /* fsys = fc = 12MHz * PLL = 48MHz, fphiT0 = fperiph = fgear = fc */
                                 /* ftmrb = 1/8fphiT0 = 1/8 * 48 = 6MHz, Ttmrb = 0.167us, 1000us/0.167us = 6000 = 0x1770 */
#define KEYRELEASE      0xf0U   /* KEYRELEASE */

void CG_InitSystem(void);
Result CG_EnableClkMulCircuit(void);
void LedOff(uint8_t led);
void LedOn(uint8_t led);


void TMRB_TIMER(void)
{
    TMRB_InitTypeDef m_tmrb;

    CG_InitSystem();            /* CG_SetSystem */
    GPIO_SetOutput(GPIO_PA,0xFFU);    
    GPIO_WriteData(GPIO_PA,0xFFU); /* LED initialize */
    LedOff(LED1 | LED2 | LED3 | LED4);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.Cycle = TMRB_1MS;    /* periodic time is 1ms */
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Duty = TMRB_1MS;     /* periodic time is 1ms */

    TMRB_Enable(TSB_TB0);
    TMRB_Init(TSB_TB0, &m_tmrb);
    NVIC_EnableIRQ(INTTB0_IRQn);
    TMRB_SetRunState(TSB_TB0, TMRB_RUN);
    while (1) {
        /* Do nothing */
    }
}

/* CG_SetSystem */
void CG_InitSystem(void)
{
    /* Set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_1);
    /* Set fperiph to fgear */
    CG_SetPhiT0Src(CG_PHIT0_SRC_FGEAR);
    CG_SetPhiT0Level(CG_DIVIDE_1);
    /* Set SCOUT source */
    CG_SetSCOUTSrc(CG_SCOUT_SRC_PHIT0);
    /* Enable high-speed oscillator */
    CG_SetFosc(CG_FOSC_OSC_EXT, ENABLE);
    /* Set fosc source */
    CG_SetFoscSrc(CG_FOSC_OSC_EXT);
    /* Set up pll and wait 200us for pll to warm up , set fc source to fpll */
    CG_EnableClkMulCircuit();
}

/* CG_EnableClkMulCircuit */
Result CG_EnableClkMulCircuit(void)
{
    Result retval = ERROR;
    WorkState st = BUSY;

    CG_SetFcSrc(CG_FC_SRC_FOSC);
    CG_SetPLL(DISABLE);
    CG_SetFPLLValue(CG_FPLL_MULTIPLY_8);
    retval = CG_SetPLL(ENABLE);
    if (retval == SUCCESS) {
        /* Set warm up time */
        CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_EXT, CG_WUODR_PLL);
        CG_StartWarmUp();

        do {
            st = CG_GetWarmUpState();
        } while (st != DONE);

        retval = CG_SetFcSrc(CG_FC_SRC_HALF_FPLL);
    } else {
        /*Do nothing */
    }
    SystemCoreClockUpdate();
    return retval;
}

/*************************************************************************
 * Function Name: LedOff
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LedOff(uint8_t led)
{
    uint8_t reg;
    reg = GPIO_ReadData(GPIO_PA);
    reg &= (uint8_t)(~led);
    GPIO_WriteData(GPIO_PA,reg);
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LedOn(uint8_t led)
{
    GPIO_WriteData(GPIO_PA,led);
}

/**
  * @brief  TMRB0 interrupt service routine (1ms)
  * @param  None
  * @retval None
  */
void INTTB0_IRQHandler(void)
{
    static uint16_t tbcount = 0U;
    static uint8_t ledon = 1U;

    tbcount++;
    if (tbcount >= 500U) {
        tbcount = 0U;
        /* reverse LED output */
        ledon = (ledon == 0U) ? 1U : 0U;
        if (0U == ledon) {
            LedOff(LED1);
        } else {
            LedOn(LED1);
        }
    } else {
        /* do nothing */
    }
}
