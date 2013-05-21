/**
 *******************************************************************************
 * @file    CG_ModeSwitch.c
 * @brief   the application functions of CG_ModeSwitch demo
 * @version V0.100
 * @date    2012/07/30
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
#include "TMPM365.h"
#include "tmpm365_gpio.h"
#include "tmpm365_cg.h"
#include <string.h>
#include <stdio.h>

#define SW0         (1U<<4U)
#define SW1         (1U<<5U)
#define SW_ALL      (SW0|SW1)
#define TSB_SW          TSB_PB

#define LED0 (1U<<0U)
#define LED1 (1U<<1U)
#define LED2 (1U<<2U)
#define LED3 (1U<<3U)

#define LED_ALL  (LED0|LED1|LED2|LED3)
#define LED_DATA_PORT   GPIO_PA
#define LED_ON  1U
#define LED_OFF  0U

#define TSW_PORT        GPIO_PD
#define TSWBITS         0x02U
#define TSWRELEASE      0x02U      /* KEYRELEASE */
/* For Toggle Switch */
#define TSW1 0x00U

#define CG_WUODR_INT     ((uint16_t)0x9c40)
#define CG_WUODR_PLL     ((uint16_t)0x0960)
typedef enum { SLEEP = 0, WAKE = 1 } SYSSTAT;

void SW_Init(void);
uint8_t SW_Get(uint8_t SW);

void LED_Init(void);
void LED_Off(uint8_t led);
void LED_On(uint8_t led);

void PrintCode(char *, uint16_t, uint32_t);
void Delay(uint32_t time);
void GPIO_SetINT(void);
void INT0_IRQHandler(void);

void CG_NormalToStop1(void);
void CG_SetSystem(void);
Result CG_EnableClkMulCircuit(void);

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
/* external variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
SYSSTAT fSysSleep = WAKE;

/* CG_ModeSwitch function */
void CG_ModeSwitch(void)
{
    /* Initialize system */
    CG_SetSystem();
    SW_Init();
    LED_Init();
    LED_On(LED0);
    /* set INT0 as interrupt source */
    TSB_PG->FR1 |= 0x08;
    TSB_PG->IE |= 0x08;
    while (1) {

        if (SW_Get(SW0) == 1U) {
            fSysSleep = SLEEP;
            LED_Off(LED0);

            CG_NormalToStop1();

            /* Connect PG3 to VCC to recover from STOP mode */
            LED_On(LED0);
            fSysSleep = WAKE;
            NVIC_DisableIRQ(INT0_IRQn);

        } else {
            LED_On(LED2);
        }
    }

}

/*******************************************************************************
* Function Name  : SW_Init
* Description    : Initialize the GPIO to SW 
* Input          : None 
* Return         : None.
*******************************************************************************/
void SW_Init(void)
{
    uint8_t reg = TSB_SW->IE;
    reg |= SW_ALL;
    TSB_SW->IE = reg;
}

/*******************************************************************************
* Function Name  : SW_Get
* Description    : Get SW Value
* Input          : SW (choose from SW0 ~ SW7).
* Return         : SW value.
*******************************************************************************/
uint8_t SW_Get(uint8_t sw)
{
    uint8_t tmp = TSB_SW->DATA & sw;

    if (tmp > 0U)
        tmp = 1U;
    return tmp;
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
void INT0_IRQHandler(void)
{
    CG_ClearINTReq(CG_INT_SRC_0);
}
void CG_SetSystem(void)
{
    /* Set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_2);
    /* Set fperiph to fgear */
    CG_SetPhiT0Src(CG_PHIT0_SRC_FGEAR);
    CG_SetPhiT0Level(CG_DIVIDE_64);
    /* Set SCOUT source */
    CG_SetSCOUTSrc(CG_SCOUT_SRC_PHIT0);
    /* Enable high-speed oscillator */
    CG_SetFosc(CG_FOSC_OSC_EXT, ENABLE);
    /* Set fosc source */
    CG_SetFoscSrc(CG_FOSC_OSC_EXT);
    /* Set low power consumption mode stop1 */
    CG_SetSTBYMode(CG_STBY_MODE_STOP1);
    /* Set pin status in stop mode to "active" */
    CG_SetPinStateInStop1Mode(ENABLE);
    /* Set up pll and wait 200us for pll to warm up , set fc source to fpll */
    CG_EnableClkMulCircuit();
}

/* CG_NormalToStop1 */
void CG_NormalToStop1(void)
{
    /* Set CG module: Normal ->STOP1 mode */
    /* after exiting STOP mode, internal oscillator starts up */
    CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_INT, CG_WUODR_INT);

    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_0, CG_INT_ACTIVE_STATE_RISING, ENABLE);

    /* Disable interrupts */
    __disable_irq();
    NVIC_ClearPendingIRQ(INT0_IRQn);
    NVIC_EnableIRQ(INT0_IRQn);
    CG_ClearINTReq(CG_INT_SRC_0);
    __enable_irq();

    __DSB();
    /* Enter stop1 mode */
    __WFI();

}

/* CG_EnableClkMulCircuit */
Result CG_EnableClkMulCircuit(void)
{
    Result retval = ERROR;
    WorkState st = BUSY;
    CG_SetPLL(DISABLE);
    CG_SetFPLLValue(CG_FPLL_MULTIPLY_8);
    retval = CG_SetPLL(ENABLE);
    if (retval == SUCCESS) {
        /* Set warm up time */
        CG_SetWarmUpTime(CG_WARM_UP_SRC_OSC_EXT, CG_WUODR_PLL);
        CG_StartWarmUp();

        do {
            st = CG_GetWarmUpState();
        } while (st != DONE);

        retval = CG_SetFcSrc(CG_FC_SRC_HALF_FPLL);
    } else {
        /*Do nothing */
    }

    return retval;
}



/*********************************** END OF FILE ******************************/
