/**
 *******************************************************************************
 * @file    Example_ADC_ReadData.c
 * @brief   the application functions of ADC demo for the
 *          TOSHIBA 'TMPM373' Device Series
 * @version V0.100
 * @date    2010/06/20
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


/* This demo is to show ADC function with software trigger on M373-SK board      */
/* The loop blinking speed of the 4 LEDs is varied depend on the AD result.      */

#include "tmpm373_adc.h"
#include "led.h"

ADC_Result result = { 0U };
uint8_t LEDs[4] = { LED0, LED1, LED2, LED3 };

WorkState adcState = BUSY;
uint32_t myResult = 0U;
uint32_t idx = 0U;

static void myDelay(uint32_t var);

    
void Example_ADC_ReadData()
{
    /* 1. set ADC clock */
    ADC_SetClk(TSB_ADB, ADC_HOLD_FIX, ADC_FC_DIVIDE_LEVEL_2);

    /* 2. select trigger and AD channel, this time we use sofeware trigger, */
    /*    the VR1 is connected to  ADC unit B channel 2, remember to input with macro TRG_ENABLE() */
    ADC_SetSWTrg(TSB_ADB, ADC_REG0, TRG_ENABLE(ADC_AIN2));

    /* 3. enable ADC module */
    ADC_Enable(TSB_ADB);

    /* 4. now start ADC */
    ADC_Start(TSB_ADB, ADC_TRG_SW);

    /* initialize LEDs on M373-SK board before display something */
    LED_Init();

    while (1U) {
        /* check ADC module state */
        adcState = ADC_GetConvertState(TSB_ADB, ADC_TRG_SW);

        if (adcState == DONE) {
            /* read ADC result when it is finished */
            result = ADC_GetConvertResult(TSB_ADB, ADC_REG0);

            /* get the real ADC result without other information */
            /* "/16" is to limit the range of AD value */
            myResult = result.Bit.ADResult / 16U;

            /* software trigger, need to trigger it again */
            ADC_Start(TSB_ADB, ADC_TRG_SW);
        }
        myDelay(myResult);  
        if(idx) 
        {
          LED_Off(LEDs[idx-1]);
        }
        idx &= 0x03U;
        myDelay(myResult); 
        LED_On(LEDs[idx]);
        idx++;
    }
}

uint32_t speed = 20000U;  /* change this const to get proper blink speed */
uint32_t loop = 0U;
static void myDelay(uint32_t var)
{
    loop = speed;
    if(!var) var=1;
    while(var--){
        while(loop --);
        loop = speed;
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
