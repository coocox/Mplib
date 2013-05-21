/** 
 *******************************************************************************
 * @file    adc.c
 * @brief   the application functions of ADC_Data_Read demo for the TOSHIBA
 *          'TMPM376' Device Series 
 * @version V0.100
 * @date    2011/12/12
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
 M376 ADC Data Read Demo \n\r\
*************************\n\r"

#define MAX_INDEX 2000U
static uint32_t index = 0;
static char displaybuf[32];

static void PrintN(char * pBuf, uint32_t n)
{
    char buf[16], *p;

    if (n == 0)
    {
        *pBuf = '0';
    }
    else
    {
        p = buf;
        while (n != 0)
        {
            *p++ = (n % 10) + '0';
            n /= 10;
        }

        while (p > buf)
        {
            /*TestIOPut(*--p);*/
            *pBuf++ = *--p;
        }
    }
}

/**
  * @brief  Initialize ADC register and variables
  * @param  None
  * @retval None
  */
void ADC_Init(void)
{
    /* set ADC clock */
    ADC_SetClk(TSB_ADB, ADC_HOLD_FIX, ADC_FC_DIVIDE_LEVEL_16);

    /* select trigger type and AD channel, this time software trigger is used */
    /* VR1 is connected to AIN0, remember to input with macro TRG_ENABLE() */
    ADC_SetSWTrg(TSB_ADB, ADC_REG0, TRG_ENABLE(ADC_AIN0));

    /* enable ADC module */
    ADC_Enable(TSB_ADB);
}

#if 0
/**
  * @brief  Send ADC Date value Time value to UART.
  * @param  None
  * @retval None
  */
void ADC_Display(void)
{
    ADC_Result result = ADC_GetConvertResult(TSB_ADB, ADC_REG0);

    if (++index == MAX_INDEX) {
        index = 0U;

        sprintf(displaybuf, "ADC Value: %4d\0", result.Bit.ADResult);

        printf("\033[2J");  /* clear terminal */
        printf(DEMO_TITLE); /* display title */
        printf(displaybuf); /* display ADC Value */
    }
}
#endif

/**
  * @brief  Send ADC Date value Time value to UART.
  * @param  None
  * @retval None
  */
void ADC_Display(void)
{
    ADC_Result result = ADC_GetConvertResult(TSB_ADA, ADC_REG0);
    uint32_t   AD_value = result.Bit.ADResult;

    if (++index == MAX_INDEX) {
        index = 0U;

        PrintN(displaybuf, AD_value);

        send_str("\033[2J");      /* clear terminal */
        send_str(DEMO_TITLE);     /* display title */
        send_str("ADC Value: ");
        send_str(displaybuf);     /* display ADC Value */
    }
}