/**
 *******************************************************************************
 * @file    GPIO_LED.c
 * @brief   the application functions of GPIO demo for the
 *          TOSHIBA 'TMPM369' Device Series
 * @version V0.100
 * @date    2011/9/14
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

/* include file */
#include "TMPM369.h"
#include "tmpm369_gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define LED0     0x01U
#define LED1     0x02U
#define LED2     0x04U
#define LED3     0x08U
#define LED_ALL  0x0FU

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void LED_Init(void);
void LED_On(uint8_t led);
void LED_Off(uint8_t led);

void Delay(uint32_t time);
/* GPIO_LED function */
void GPIO_LED(void)
{
	  uint8_t i = 0;
    LED_Init();

    for (;;)
   	{
			if(0 == i)
			{
				LED_On(LED1);
				i = 1;
      }
			else
			{
       LED_Off(LED1);
			 i = 0;
      }
      Delay(500);
    }
}


/*******************************************************************************
* Function Name  : Delay
* Description    : delay time
* Input          : time.
* Return         : None.
*******************************************************************************/
void Delay(uint32_t time)
{
    volatile uint32_t i = 0U;
    uint32_t j = 0U;

    j = time * 800U;
    for (i = 0U; i < j; i++) {
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

