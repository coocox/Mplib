/**
 *******************************************************************************
 * @file    main.c
 * @brief   The application functions of ADC demo for the
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

/* include file */
#include <stdio.h>

#include "tmpm061_adc.h"
#include "main.h"

/* define the ADC channel used here.the VR2 is connected to AIN0 in this example */
#define ADC_CHANNEL     ADC_AN_0
#define ADC_REG_RESULT  ADC_REG_0


void ADC_Data_Read(void);

struct mySoftTimer {
    uint8_t flag_TimeUp;
    uint8_t flag_Blink;
    uint32_t timer_Cnt;
}softT;

#define DELAYCONST  20000U
static void softTimer_Init(void);
static void softTimer_Run(void);

static void display_AD(uint32_t myResult);

ADC_Result adResult = { 0U };
uint32_t timeUp = 0U;
uint32_t idx = 0U;
uint32_t cnt = 0U;

WorkState adcState = BUSY;
uint32_t myResult = 0U;

void ADC_Data_Read(void)
//int main()
{

    /* 1. set ADC clock */
    ADC_SetClk(ADC_CONVERSION_81_CLOCK, ADC_FC_DIVIDE_LEVEL_16);

    /* 2. turn on reference voltage, and wait at least 3uS to let it stable */
    ADC_SetVref(ENABLE);
    timeUp = 300U;
    while( timeUp ) {
        timeUp -- ;
    }

    /* 3. use Fixed-channel single conversion */
    ADC_SetScanMode(DISABLE);
    ADC_SetRepeatMode(DISABLE);

    /* 4. select ADC channel */
    ADC_SetInputChannel(ADC_CHANNEL);

    /* 5. now start ADC */
    ADC_Start();

    /* Initialize system */
    SIO_Configuration(UART_RETARGET);
    SIO_ChInit();

    /* enable retarget Channel TX interrupt */
    NVIC_EnableIRQ(RETARGET_INT);

    printf("--------------ADC Demo------------\n\r");

    /* initialize soft timer */
    softTimer_Init();

    while (1U) {
        softTimer_Run();
        if(softT.flag_TimeUp) {
            softT.flag_TimeUp = 0U;

            /* check ADC module state */
            adcState = ADC_GetConvertState();
            if (adcState == DONE) {
                /* read ADC result when it is finished */
                adResult = ADC_GetConvertResult(ADC_REG_RESULT);
                myResult = (uint32_t)adResult.Bit.ADResult ;
                ADC_Start();
                display_AD(myResult);
            }
        } else {
            /* Do nothing */
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
  * @brief  display AD value on LCD.
  * @param  myResult: AD data which will be displayed
  * @retval None
  */
void display_AD(uint32_t myResult)
{

    if( myResult > 1023U ) {
        myResult = 1023U;
    } else {
        /* Do nothing */
    }

    printf("ADC Value is %4d\r", myResult);
}

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
