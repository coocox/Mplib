/**
 *******************************************************************************
 * @file    ADC_Demo.c
 * @brief   the application functions of ADC demo for the
 *          TOSHIBA 'TMPM369' Device Series
 * @version V0.100
 * @date    2011/09/20
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


/* This demo is to show ADC function with software trigger on M369-EVAL board    */
/* The loop blinking speed of the 4 LEDs is adjusted by AD conversion result.    */

#include "tmpm369_adc.h"
#include "TMPM369.h"
#include "tmpm369_gpio.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define LED0     0x01U
#define LED1     0x02U
#define LED2     0x04U
#define LED3     0x08U
#define LED_ALL  0x0FU

struct mySoftTimer {
    uint32_t flag_TimeUp;
    uint32_t time_Cnt;
}softT;

#define DELAYCONST  20000U
    
static void softTimer(void);    
void INTADB_IRQHandler(void);
void LED_Init(void);
void LED_On(uint8_t led);
void LED_Off(uint8_t led);

ADC_Result adResult = { 0U };
uint32_t timeUp = 0U;
uint32_t idx = 0U;
uint32_t cnt = 0U;
uint32_t fIntADC = 0U;


/**
  * @brief  The void function of ADC demo
  * @param  None
  * @retval None
  */    
void ADC_Demo(void)
{
    /* Software reset ADC unit B */
    ADC_SWReset(TSB_ADB);
    
    /* Enable ADC clock supply */
    ADC_SetClkSupply(ENABLE);
    
    /* Set ADC clock */            
    ADC_SetClk(TSB_ADB, ADC_CONVERSION_CLK_80, ADC_FC_DIVIDE_LEVEL_8);

    /* Select ADC input channel : Channel 0 of unit B */
    ADC_SetInputChannel(TSB_ADB, ADC_AN_00);
    
    /* Enable ADC repeat mode */
    ADC_SetRepeatMode(TSB_ADB, ENABLE);

    /* Set interrupt mode */
    ADC_SetINTMode(TSB_ADB, ADC_INT_CONVERSION_8);

    /* Turn VREF on */
    ADC_SetVref(TSB_ADB, ENABLE);    

    /* Wait at least 3us to ensure the voltage is stable */
    cnt = 100U;
    while(cnt){
        cnt--;
    }

    /* Enable AD interrupt */
    NVIC_EnableIRQ(INTADB_IRQn);

    /* Start ADC */
    ADC_Start(TSB_ADB);   
                
    /* Initialize LEDs */
    LED_Init();
    
    softT.time_Cnt = DELAYCONST;
    while (1U) {
        
        if (fIntADC == 1U) {
            fIntADC = 0U;
            /* Read AD conversion result when it is finished */
            adResult = ADC_GetConvertResult(TSB_ADB, ADC_REG00);
            
            /* Get the real ADC result without other information */
            /* "/256" is to limit the range of AD value */
            timeUp = 16U - adResult.Bit.ADResult / 256U;

        } else {
            /* Do nothing */
        }    
           
        softTimer();  
             
        if(softT.flag_TimeUp) {
            softT.flag_TimeUp = 0U;
            cnt++;
            if( cnt >= timeUp ) {
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


/**
  * @brief  The ADC interrupt request function.
  * @param  None
  * @retval None
  */
void INTADB_IRQHandler(void)
{
    fIntADC = 1U;
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
	/*Set PC bit0~3 output and turn off all leds*/
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_0);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_1);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_2);
    GPIO_SetOutput(GPIO_PC, GPIO_BIT_3);

    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_0, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_1, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    GPIO_WriteDataBit(GPIO_PC, GPIO_BIT_3, GPIO_BIT_VALUE_0);
}

/*************************************************************************
 * Function Name: LED_On
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is ON.
 *
 *************************************************************************/

void LED_On(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PC);
    tmp |= led;
    GPIO_WriteData(GPIO_PC, tmp);
}

/*************************************************************************
 * Function Name: LED_Off
 * Parameters:LED number, choose from LED0, LED1, LED2, LED3 or LED_ALL.
 *
 * Return:None  
 *
 * Description: The choosen Led is Off.
 *
 *************************************************************************/
void LED_Off(uint8_t led)
{
    uint8_t tmp;
    tmp = GPIO_ReadData(GPIO_PC);
    tmp &= (uint8_t) (~led);
    GPIO_WriteData(GPIO_PC, tmp);
}

