/**
 *******************************************************************************
 * @file    Example_ADC_ReadData.c
 * @brief   the application functions of ADC demo for the
 *          TOSHIBA 'TMPM375' Device Series
 * @version V0.100
 * @date    2013/03/21
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


/* This demo is to show ADC function with software trigger on M375-SK board      */
/* The loop blinking speed of the 4 LEDs is varied depend on the AD result.      */
#include "tmpm375_adc.h"
#include "led.h"
struct mySoftTimer {
    uint32_t flag_TimeUp;
    uint32_t time_Cnt;
}softT;
#define DELAYCONST  20000U
static void softTimer(void); 

ADC_Result result = { 0U };
WorkState adcState = BUSY;
uint32_t myResult = 0U;
uint32_t idx = 0U;
uint32_t cnt = 0U;

   
void Example_ADC_ReadData()
{
    /* 1. set ADC clock */
    ADC_SetClk(TSB_ADB, ADC_HOLD_FIX, ADC_FC_DIVIDE_LEVEL_8);

    /* 2. select trigger and AD channel, this time we use sofeware trigger, */
    /*    the VR1 is connected to  ADC unit B channel 9, remember to input with macro TRG_ENABLE() */
    ADC_SetSWTrg(TSB_ADB, ADC_REG0, TRG_ENABLE(ADC_AIN9));
    
    /* 3. enable ADC module */
    ADC_Enable(TSB_ADB);

    /* 4. now start ADC */
    ADC_Start(TSB_ADB, ADC_TRG_SW);

    /* initialize LEDs on M375-SK board before display something */
    LED_Init();
    
    softT.time_Cnt = DELAYCONST;
    while (1U) {
        /* check ADC module state */
        adcState = ADC_GetConvertState(TSB_ADB, ADC_TRG_SW);

        if (adcState == DONE) {
            /* read ADC result when it is finished */
            result = ADC_GetConvertResult(TSB_ADB, ADC_REG0);

            /* get the real ADC result without other information */
            /* "/256" is to limit the range of AD value */
            myResult = 16U - result.Bit.ADResult / 256U;
            /* software trigger, need to trigger it again */
            ADC_Start(TSB_ADB, ADC_TRG_SW);
        } else {
            /* Do nothing */
        }   
       softTimer();  
       if(softT.flag_TimeUp) {
            softT.flag_TimeUp = 0U;
            cnt++;
            if( cnt >= myResult ) {
                cnt = 0U;
                idx++;
                if( idx == 1U ) {
                    LED_On(LED0);
                } else if( idx == 2U ) {
                    LED_On(LED1);
                    LED_Off(LED0);
                } else if( idx == 3U ) {
                    LED_On(LED2);
                    LED_Off(LED1);
                } else if( idx == 4U ) {
                    LED_On(LED3);
                    LED_Off(LED2);
                } else if( idx == 5U ) {
                    idx = 0U;
                    LED_Off(LED3);
                } else {
                    /* Do nothing */
                }
            } else {
                /* Do nothing */
            }  
        } else {
            /* Do nothing */
        }                                 
    }
} 

/**
  * @brief  Simulate a several mS timer. 
  * @param  None
  * @retval None
  */
static void softTimer(void)
{
    if( softT.time_Cnt == 0U ){
        softT.flag_TimeUp = 1U;
        softT.time_Cnt = DELAYCONST;
    } else {
        softT.time_Cnt --;
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
