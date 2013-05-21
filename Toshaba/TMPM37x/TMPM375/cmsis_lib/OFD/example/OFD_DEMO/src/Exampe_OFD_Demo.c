/**
 *******************************************************************************
 * @file    Exampe_OFD_Demo.c
 * @brief   the application functions of OFD demo for the
 *          TOSHIBA 'TMPM375' Device Series
 * @version V0.100
 * @date    2013/03/12
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


#include "main.h"

/* declaration ---------------------------------------------------------------*/
void ChangeToEHOSC(void);
void Delay(void);
#define DEMO2

/**
  * @brief  The main routine of OFD demo
  * @param  None
  * @retval None
  */
void Exampe_OFD_Demo (void)
{
    uint8_t OFDReset = 0U;
    CG_ResetFlag resetFlag = { 0U };
    LED_Init();
    resetFlag = CG_GetResetFlag();
    if (resetFlag.Bit.OFDReset == 0U) {
        /*Change to external oscillator */
        ChangeToEHOSC();
        /* OFD initial */
        OFD_SetRegWriteMode(ENABLE);
        OFD_SetDetectionFrequency(OFD_PLL_OFF,0x25, 0x1D);
#ifdef DEMO2
        OFD_SetDetectionFrequency(OFD_PLL_ON,OFD_HIGHER_COUNT_ABNORMAL, OFD_LOWER_COUNT_ABNORMAL);
#else
        OFD_SetDetectionFrequency(OFD_PLL_ON,OFD_HIGHER_COUNT, OFD_LOWER_COUNT);
#endif

        OFD_Enable();
    } else {
        OFD_Disable();
        OFDReset = 1U;
    }
    while (1U) {
        if (OFDReset == 1U) {
            LED_On(LED2);
            Delay();
            LED_Off(LED2);
            Delay();
        } else {
            LED_On(LED1);
            Delay();
            LED_Off(LED1);
            Delay();
        }
    }
}

/**
  * @brief  Change the system clock to external oscillator.
  * @param  None
  * @retval None
  */
void ChangeToEHOSC(void)
{
    /* Use the external oscillation */
    TSB_CG->SYSCR = 0x00010000UL;
    TSB_CG->OSCCR &= 0x000FFFFFUL;
    TSB_CG->OSCCR |= 0xC3500000UL;      /*Set the warm up time WUODR[13:2] */
    TSB_CG_OSCCR_HOSCON = 1U;   /*Set port as X1/X2 for external oscillator */
    TSB_CG_OSCCR_XEN1 = 1U;     /*Enable external oscillator */
    TSB_CG_OSCCR_WUPSEL2 = 1U;
    TSB_CG_OSCCR_WUPSEL1 = 0U;  /*Select warm-up clock */
    TSB_CG_OSCCR_WUEON = 1U;    /*Start warm up */
    TSB_CG->PLLSEL = (0x0000680FUL<<1U);
    while (TSB_CG_OSCCR_WUEF) {
    }                           /* Warm-up */
    TSB_CG_OSCCR_OSCSEL = 1U;   /* Use the external oscillation */
    TSB_CG_OSCCR_XEN2 = 1U;
    TSB_CG->OSCCR &= 0x000FFFFFUL;
    TSB_CG->OSCCR |= 0x03E80000UL;
    TSB_CG_OSCCR_PLLON = 1U;    /* PLL enabled */
    TSB_CG->STBYCR = 0x00000103UL;    
    TSB_CG_OSCCR_WUEON = 1U;
    while (TSB_CG_OSCCR_WUEF) {
    }                           /* Warm-up */

    TSB_CG->PLLSEL = ((0x0000680FUL<<1U)|1U);
}

/**
  * @brief  Delay.
  * @param  None
  * @retval None
  */
void Delay(void)
{
    uint32_t tmp;
    for (tmp = 0U; tmp < 0x5ffffU; tmp++);

}

#if 0
/**
 * @brief Initialize the system
 * @param  none
 * @return none
 */
void SystemInit(void)
{
#if (WD_SETUP)                  /* Watchdog Setup */
    TSB_WD->MOD = WDMOD_Val;
    if (!TSB_WD_MOD_WDTE) {     /* If watchdog is to be disabled */
        TSB_WD->CR = WDCR_Val;
    }
#endif
}
#endif

/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */
#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1U) {
        __NOP();
    }
}
#endif
