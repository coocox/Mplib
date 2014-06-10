/**
 *******************************************************************************
 * @file    adc.c
 * @brief   The application functions of ADC_Data_Read demo for the
 *          TOSHIBA 'TMPM341' Device Series
 * @version V0.100
 * @date    2011/03/23
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
#include "adc.h"

#define DEMO_TITLE "\
*************************\n\r\
 M341 ADC Data Read Demo \n\r\
*************************\n\r"

#define INDEX_MAX 100U
static uint32_t index = 0;
static char displaybuf[32];

/**
  * @brief  Initialize ADC register and variables
  * @param  None
  * @retval None
  */
void ADC_Init(void)
{
    /* Enable ADC clock supply */
    ADC_SetClkSupply(ENABLE);

    /* set ADC clock */
    ADC_SetClk(ADC_CONVERSION_CLK_80, ADC_FC_DIVIDE_LEVEL_8);

    /* select ADC input channel */
    ADC_SetInputChannel(ADC_AN_14);

    /* Enable ADC repeat mode */
    ADC_SetRepeatMode(ENABLE);

    /* Set interrupt mode */
    ADC_SetINTMode(ADC_INT_CONVERSION_8);

    /* Turn VREF on */
    ADC_SetVref(ENABLE);

    /* Wait at least 3us to ensure the voltage is stable */
    Delay(10U);
}

/**
  * @brief  Send ADC Date value Time value to UART.
  * @param  None
  * @retval None
  */
void ADC_Display(void)
{
	static uint8_t status = 0;

    ADC_Result result = ADC_GetConvertResult(ADC_REG_00);

    /* with output switching or not */
    if (result.Bit.OutputSwitching == 1U) {
        return; /* discard this result */
    }

    // First time enter this function
    // Print title
    if(status == 0)
    {
    	status = 1;
    	//printf("\033[2J");  /* clear terminal */
    	printf(DEMO_TITLE); /* display title */
    }

    if (++index == INDEX_MAX) {
        index = 0U;

        sprintf(displaybuf, "ADC Value: %4d\r", result.Bit.ADResult);
        printf(displaybuf); /* display ADC Value */
    }
}

void Delay(int time)
{
    volatile int i = 0;

    for (i = 0; i < (time * 800); ++i);
}
