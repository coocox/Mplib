/**
 *******************************************************************************
 * @file    WDT_NMI.c
 * @brief   The application functions of WDT demo for the
 *          TOSHIBA 'TMPM366' Device Series 
 * @version V0.100
 * @date    2011/03/15
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

#include "tmpm366_wdt.h"
#include "tmpm366_gpio.h"
#include "tmpm366_cg.h"

#define LED_DATA_PORT   GPIO_PA

#define LED1 (1U<<0U)
#define LED2 (1U<<1U)

uint8_t fIntNMI = 0U;
#define DEMO2
void Delay(uint32_t time);
void LEDInit(void);
void LedOff(uint8_t led);
void LedOn(uint8_t led);

void WDT_NMI(void)
{
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.DetectTime = WDT_DETECT_TIME_EXP_25;
    WDT_InitStruct.OverflowOutput = WDT_NMIINT;

    LEDInit();

    LedOff(LED1 | LED2);
    WDT_Init(&WDT_InitStruct);
    WDT_Enable();

    while (1) {
        if (fIntNMI == 1U) {
            fIntNMI = 0U;
            LedOn(LED1);
            Delay(500U);
            LedOff(LED1);
            Delay(500U);
            WDT_Disable();
        } else {
            /* Do nothing */
        }
#ifdef DEMO2
        Delay(500U);
        WDT_WriteClearCode();
        LedOn(LED2);
        Delay(500U);
        LedOff(LED2);
#endif
    }
}

void Delay(uint32_t time)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < (time * 800U); ++i) {
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
void LEDInit(void)
{
    GPIO_SetOutput(LED_DATA_PORT,0xFFU);    
    GPIO_WriteData(LED_DATA_PORT,0xFFU); 
    
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
    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= (uint8_t)(~led);
    GPIO_WriteData(LED_DATA_PORT,reg);
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
    GPIO_WriteData(LED_DATA_PORT,led);
}

/**
  * @brief  The NMI interrupt request function.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
    volatile CG_NMIFactor RegVal = { 0U };
    RegVal = CG_GetNMIFlag();

    if (RegVal.Bit.WDT) {
        fIntNMI = 1U;
    } else {
        /* Do nothing */
    }
}
