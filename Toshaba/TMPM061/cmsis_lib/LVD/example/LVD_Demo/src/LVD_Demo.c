/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of LVD demo for the
 *          TOSHIBA 'TMPM061' Demo
 * @version V0.100
 * @date    2012/05/15
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

/* --------------------------------------------------------------------------------
 test steps:
   1. set the power supply voltage large than 3.1V, then power up, LED0 will blink.
   2. adjust power supply voltage down to 2.9V, LED1 will blink and LED0 is off.
   3. adjust power supply voltage back to 3.1V, LED0 will blink and LED1 is off.
 --------------------------------------------------------------------------------*/

/* include file */
#include "tmpm061_lvd.h"
#include "led.h"

void LVD_Demo(void);

void INTLVD_IRQHandler(void);


#define MODE_NORMAL  1U
#define MODE_LVD     2U

static uint32_t mode = 0U;

struct mySoftTimer {
    uint8_t flag_TimeUp;
    uint8_t flag_Blink;
    uint32_t timer_Cnt;
}softT;

#define DELAYCONST  200000UL

static void softTimer_Init(void);
static void softTimer_Run(void);

/*int main()*/
void LVD_Demo(void)
{
    /* 1. set LVD threshold as 3.00 +/- 0.2V */
    LVD_SetVoltage(LVD_DETECT_VOLTAGE_300);

    /* 2. set LVD Interrupt Condition: both side */
    LVD_SetINTCondition(LVD_INTSEL_LOWER_UPPER);

    /* 3. enable LVD interrupt */
    LVD_SetINTOutput(ENABLE);

    /* 4. enable LVD module */
    LVD_Enable();


    /* when power is up, mode is 'normal' */
    mode = MODE_NORMAL;

    /* initialize LEDs on board before display something */
    LED_Init();

    /* initialize soft timer */
    softTimer_Init();

    NVIC_EnableIRQ(INTLVD_IRQn);

    while (1U) {
        softTimer_Run();
        if(softT.flag_Blink) {
            if( mode == MODE_NORMAL ) {
                LED_On(LED0);
            } else if ( mode == MODE_LVD ) {
                LED_On(LED1);
            } else {
                /* Do nothing */
            }
        } else {
            LED_Off(LED0);
            LED_Off(LED1);
        }

    }
}



/**
  * @brief  Initialize a several mS timer.
  * @param  None
  * @retval None
  */
static void softTimer_Init(void)
{
    softT.flag_TimeUp = 0U;
    softT.flag_Blink = 0U;
    softT.timer_Cnt = DELAYCONST;
}


/**
  * @brief  Simulate a several mS timer.
  * @param  None
  * @retval None
  */
static void softTimer_Run(void)
{
    if( softT.timer_Cnt == 0U ){
        softT.flag_TimeUp = 1U;
        softT.flag_Blink = (uint8_t)~softT.flag_Blink;
        softT.timer_Cnt = DELAYCONST;
    } else {
        softT.timer_Cnt --;
    }
}

/**
  * @brief  Interrupt service routine for LVD
  * @param  None
  * @retval None
  */
void INTLVD_IRQHandler(void)
{
    /* the first time enter this routine, power supply is lower than threshold */
    if( mode == MODE_NORMAL ) {
        mode = MODE_LVD;
    } else if ( mode == MODE_LVD ) { /* the second time enter thsi routine, power supply is rising and higher than threshold */
        mode = MODE_NORMAL;
    } else {
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
