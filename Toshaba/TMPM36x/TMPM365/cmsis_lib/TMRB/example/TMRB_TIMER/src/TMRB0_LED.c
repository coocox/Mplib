/** 
 *******************************************************************************
 * @file    TMRB_TIMER.c
 * @brief   the application functions of TMRB_TIMER demo for the TOSHIBA
 *          'TMPM365' Device Series 
 * @version V0.100
 * @date    2012/08/01
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "tmpm365_tmrb.h"
#include "TMPM365.h"
#include "tmpm365_gpio.h"


#define LED0 (1U<<0U)
#define LED1 (1U<<1U)
#define LED2 (1U<<2U)
#define LED3 (1U<<3U)

#define LED_ALL  (LED0|LED1|LED2|LED3)
#define LED_DATA_PORT   GPIO_PA
#define LED_ON  1U
#define LED_OFF  0U

#define TMRB_1MS        0x1770U  /* fsys = fc = 12MHz * PLL = 48MHz, fphiT0 = fperiph = fgear = fc */
                                 /* ftmrb = 1/8fphiT0 = 1/8 * 48 = 6MHz, Ttmrb = 0.167us, 1000us/0.167us = 6000 = 0x1770 */
#define KEYRELEASE      0xf0U   /* KEYRELEASE */

void LED_Init(void);
void LED_Off(uint8_t led);
void LED_On(uint8_t led);

/**
  * @brief  TMRB_TIMER function of TMRB_TIMER demo
  * @param  None
  * @retval None
  */
void TMRB_TIMER(void)
{
    TMRB_InitTypeDef m_tmrb;

    LED_Init();                 /* LED initialize */
    LED_Off(LED0 | LED1 | LED2 | LED3);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.Cycle = TMRB_1MS;    /* periodic time is 1ms */
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.Duty = TMRB_1MS;     /* periodic time is 1ms */

    TMRB_SetINTMask(TSB_TB0, TMRB_MASK_MATCH_DUTY_INT); /*duty is not used in TMRB_INTERVAL_TIMER mode */

    TMRB_Enable(TSB_TB0);
    TMRB_Init(TSB_TB0, &m_tmrb);
    NVIC_EnableIRQ(INTTB0_IRQn);
    TMRB_SetRunState(TSB_TB0, TMRB_RUN);
    while (1) {
        /* Do nothing */
    }
}

/*************************************************************************
 * Function Name: LED_Init
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void LED_Init(void)
{
    uint8_t led_off;
    led_off = (uint8_t) (~LED_ALL);
    GPIO_SetOutput(LED_DATA_PORT, LED_ALL);
    GPIO_WriteData(LED_DATA_PORT, led_off);

}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(LED_DATA_PORT, tmp);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(LED_DATA_PORT);
    tmp |= led;
    GPIO_WriteData(LED_DATA_PORT, tmp);
}
