/**
 ****************************************************************************
 * @file     system_TMPM061.c
 * @brief    CMSIS Cortex-M3 Device Peripheral Access Layer Source File for the
 *           TOSHIBA 'TMPM061' Device Series 
 * @version  V2.0.2.3 (Tentative)
 * @date     2013/04/08
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
 *****************************************************************************
 */

#include "TMPM061.h"

/*-------- <<< Start of configuration section >>> ----------------------------*/

/* Watchdog Timer (WD) Configuration */
#define WD_SETUP    1
#define WDMOD_Val   (0x00000000UL)
#define WDCR_Val    (0x000000B1UL)

/* Clock Generator (CG) Configuration */
#define CLOCK_SETUP 1
#define SYSCR_Val        (0x00001000UL)

/* #define INTERNAL_OSCILLATION */

#ifdef  INTERNAL_OSCILLATION
#define OSCCR_Val        (0x00010030UL) /* Use the internal high speed oscillation */
#else
//#define OSCCR_Val        (0x000A0130UL) /* Use the external high speed oscillation */
#define OSCCR_Val   (0x000E0130UL)
#endif

/*-------- <<< End of configuration section >>> ------------------------------*/

/*-------- DEFINES -----------------------------------------------------------*/
/* Define clocks */
#define XTALH     (10000000UL)  /* Internal high-speed oscillator freq */
#define EXTALH    (16000000UL)  /* External high-speed oscillator freq */
#define EXTALL    (32768UL)     /* External low-speed oscillator freq  */

/* Configure Warm-up time */
#define HZ_1M                   1000000UL
#define WU_TIME_EXT             5000UL          /* warm-up time for EXT is 5ms   */
#define OSCCR_WUODR_MASK        (0x000FFFFFUL)
#define OSCCR_WUODR_EXT         ((WU_TIME_EXT * EXTALH / HZ_1M / 16U) << 20U) /* OSCCR<WUPODR11:0> = warm-up time(us) * EXTALH(MHz) / 16 */


/* Determine core clock frequency according to settings */
#if (CKSEL_Val & (1U << 1))     /* If system clock is low-speed clock  */
  #define __CORE_CLK (EXTALL)
#else                           /* If system clock is high-speed clock */
  #if (OSCCR_Val & (1U<<17))
    #define CORE_TALH (EXTALH)      /* If use High-speed oscillator 1(External) */
  #else
    #define CORE_TALH (XTALH)       /* If use High-speed oscillator 2(Internal) */
  #endif
  #if   ((SYSCR_Val & 7U) == 0U)  /* Gear -> fc                         */
    #define __CORE_CLK   (CORE_TALH)
  #elif ((SYSCR_Val & 7U) == 4U)  /* Gear -> fc/2                       */
    #define __CORE_CLK   (CORE_TALH / 2U)
  #elif ((SYSCR_Val & 7U) == 5U)  /* Gear -> fc/4                       */
    #define __CORE_CLK   (CORE_TALH / 4U)
  #elif ((SYSCR_Val & 7U) == 6U)  /* Gear -> fc/8                       */
    #define __CORE_CLK   (CORE_TALH / 8U)
  #elif ((SYSCR_Val & 7U) == 7U)  /* Gear -> fc/16                      */
    #define __CORE_CLK   (CORE_TALH / 16U)
  #else                           /* Gear -> reserved                   */
    #define __CORE_CLK   (0U)
  #endif
#endif
/* Clock Variable definitions */
uint32_t SystemCoreClock = __CORE_CLK;  /*!< System Clock Frequency (Core Clock) */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Update SystemCoreClock according register values.
 */
void SystemCoreClockUpdate(void)
{                               /* Get Core Clock Frequency            */
    uint32_t CoreClock = 0U;
    /* Determine clock frequency according to clock register values             */
    if(TSB_CG->CKSEL & ((uint32_t)0x01 << 0U)) {
        SystemCoreClock = EXTALL;
    } else {                    /* If system clock is high-speed clock */
        if (TSB_CG->OSCCR & ((uint32_t)0x01 << 17U) ) {      /* If system clock is External high-speed oscillator freq */
            CoreClock = EXTALH;
        } else {                /* If system clock is Internal high-speed oscillator freq */
            CoreClock = XTALH;
        }

        switch (TSB_CG->SYSCR & 7U) {
        case 0U:               /* Gear -> fc          */
            SystemCoreClock = CoreClock;
            break;
        case 1U:
        case 2U:
        case 3U:               /* Gear -> reserved    */
            SystemCoreClock = 0U;
            break;
        case 4U:               /* Gear -> fc/2        */
            SystemCoreClock = CoreClock / 2U;
            break;
        case 5U:               /* Gear -> fc/4        */
            SystemCoreClock = CoreClock / 4U;
            break;
        case 6U:               /* Gear -> fc/8        */
            SystemCoreClock = CoreClock / 8U;
            break;
        case 7U:               /* Gear -> fc/16       */
            SystemCoreClock = CoreClock / 16U;
            break;
        default:
            SystemCoreClock = 0U;
            break;
        }
    }
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit(void)
{
    uint32_t tmp = 0U;
    
#if (WD_SETUP)                  /* Watchdog Setup */
    TSB_WD->MOD = WDMOD_Val;
    if (! ( TSB_WD->MOD & ((uint32_t)0x01 << 7U)) ) {    /* If watchdog is to be disabled */
        TSB_WD->CR = WDCR_Val;
    }

#endif

#if (CLOCK_SETUP)               /* Clock Setup */
    TSB_CG->SYSCR = SYSCR_Val;

    if (OSCCR_Val & (1U << 17U)) {       /* Use the external oscillation */
        tmp = TSB_CG->OSCCR;
        tmp &= OSCCR_WUODR_MASK;
        tmp |= OSCCR_WUODR_EXT;
        tmp |= ((1U << 18U) | (1U << 8U) | (1U << 0U) ); 
        tmp &= 0xFFF7FFF7U; //WUPSEL2 = 0,WUPSEL1 = 0
        TSB_CG->OSCCR = tmp;

        while (TSB_CG->OSCCR & (1U << 1U) ) {
        }                       /* Warm-up */
        
        TSB_CG->OSCCR |= OSCCR_Val;
    } else {                    /* Use the internal oscillation */
        TSB_CG->OSCCR |= OSCCR_Val;
    }
    

#endif
}
