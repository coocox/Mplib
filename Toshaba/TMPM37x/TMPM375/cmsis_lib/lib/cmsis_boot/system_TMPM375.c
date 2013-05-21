/**
 *******************************************************************************
 * @file    system_TMPM375.c
 * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Source File for the
 *          TOSHIBA 'TMPM375' Device Series 
 * @version V2.0.2.2 (Tentative)
 * @date    2013/04/08
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

#include "TMPM375.h"

/*-------- <<< Start of configuration section >>> ----------------------------*/

/* Watchdog Timer (WD) Configuration */
#define WD_SETUP                1
#define WDMOD_Val               (0x00000000UL)
#define WDCR_Val                (0x000000B1UL)

/* Clock Generator (CG) Configuration */
#define CLOCK_SETUP             1
#define SYSCR_Val               (0x00010000UL)
#define OSCCR_Val               (0x000E0104UL) /* OSCCR<OSCSEL> = 1, OSCCR<XEN2> = 0, OSCCR<XEN1> = 1, OSCCR<PLLON> = 1, <HOSCON> = 1, <WUPSEL2> = 1*/

#define STBYCR_Val              (0x00000103UL)

#define PLLSEL_Ready            (0x0000680FUL<<1U)
#define PLLSEL_Val              (PLLSEL_Ready|1U)

/*-------- <<< End of configuration section >>> ------------------------------*/

/*-------- DEFINES -----------------------------------------------------------*/
/* Define clocks */
#define XTALH     (10000000UL)          /* Internal high-speed oscillator freq */
#define EXTALH    (10000000UL)          /* External high-speed oscillator freq */

/* Configure Warm-up time */
#define HZ_1M                   1000000UL
#define WU_TIME_EXT             5000UL          /* warm-up time for EXT is 5ms   */
#define WU_TIME_PLL             200UL           /* warm-up time for PLL is 200us */
#define OSCCR_WUODR_MASK        (0x000FFFFFUL)
#define OSCCR_WUODR_EXT         ((WU_TIME_EXT * EXTALH / HZ_1M / 16U) << 20U) /* OSCCR<WUPODR11:0> = warm-up time(us) * EXTALH(MHz) / 16 */
#define OSCCR_WUODR_PLL         ((WU_TIME_PLL * EXTALH / HZ_1M / 16U) << 20U)

#if (CLOCK_SETUP)               /* Clock(external) Setup */

/* Determine core clock frequency according to settings */
/* System clock is high-speed clock*/
#if (OSCCR_Val & (1U<<17))
  #define CORE_TALH (EXTALH)
#else
  #define CORE_TALH (XTALH)
#endif

#if ((PLLSEL_Val & (1U<<0)) && (OSCCR_Val & (1U<<2))) /* If PLL selected and enabled */
  #if   ((SYSCR_Val & 7U) == 0U)      /* Gear -> fc                         */
    #define __CORE_SYS   (CORE_TALH * 4U )
  #elif ((SYSCR_Val & 7U) == 4U)      /* Gear -> fc/2                       */
    #define __CORE_SYS   (CORE_TALH * 4U / 2U)
  #elif ((SYSCR_Val & 7U) == 5U)      /* Gear -> fc/4                       */
    #define __CORE_SYS   (CORE_TALH * 4U / 4U )
  #elif ((SYSCR_Val & 7U) == 6U)      /* Gear -> fc/8                       */
    #define __CORE_SYS   (CORE_TALH * 4U / 8U)
  #elif ((SYSCR_Val & 7U) == 7U)      /* Gear -> fc/16                      */
    #define __CORE_SYS   (CORE_TALH * 4U / 16U)
  #else                               /* Gear -> reserved                   */
    #define __CORE_SYS   (0U)
#endif
#else                                 /* If PLL not used                    */
  #if   ((SYSCR_Val & 7U) == 0U)      /* Gear -> fc                         */
    #define __CORE_SYS   (CORE_TALH)
  #elif ((SYSCR_Val & 7U) == 4U)      /* Gear -> fc/2                       */
    #define __CORE_SYS   (CORE_TALH / 2U)
  #elif ((SYSCR_Val & 7U) == 5U)      /* Gear -> fc/4                       */
    #define __CORE_SYS   (CORE_TALH / 4U)
  #elif ((SYSCR_Val & 7U) == 6U)      /* Gear -> fc/8                       */
    #define __CORE_SYS   (CORE_TALH / 8U)
  #elif ((SYSCR_Val & 7U) == 7U)      /* Gear -> fc/16                       */
    #define __CORE_SYS   (CORE_TALH / 16U)
  #else                               /* Gear -> reserved                   */
    #define __CORE_SYS   (0U)
  #endif
#endif

#else
  #define __CORE_SYS   (XTALH)
#endif                                                  /* clock Setup */


/* Clock Variable definitions */
uint32_t SystemCoreClock = __CORE_SYS;  /*!< System Clock Frequency (Core Clock) */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Update SystemCoreClock according register values.
 */
void SystemCoreClockUpdate(void)
{                               /* Get Core Clock Frequency */
    uint32_t CoreClock = 0U;
    /* Determine clock frequency according to clock register values */
    /* System clock is high-speed clock */
    if (TSB_CG_OSCCR_OSCSEL) {  /* If system clock is External high-speed oscillator freq */
        CoreClock = EXTALH;
    } else {                    /* If system clock is Internal high-speed oscillator freq */
        CoreClock = XTALH;
    }
    if (TSB_CG_PLLSEL_PLLSEL && TSB_CG_OSCCR_PLLON) {   /* If PLL enabled      */
     switch (TSB_CG->SYSCR & 7U) {
       case 0U:                                 /* Gear -> fc          */
         SystemCoreClock = CoreClock * 4U ;
         break;
       case 1U:
       case 2U:
       case 3U:                                 /* Gear -> reserved   */
         SystemCoreClock = 0U;
         break;
       case 4U:                                 /* Gear -> fc/2      */
         SystemCoreClock = CoreClock * 4U / 2U;
         break;
       case 5U:                                 /* Gear -> fc/4      */
         SystemCoreClock = CoreClock * 4U / 4U;
         break;
       case 6U:                                 /* Gear -> fc/8      */
         SystemCoreClock = CoreClock * 4U / 8U;
         break;
       case 7U:                                 /* Gear -> fc/16      */
         SystemCoreClock = CoreClock * 4U / 16U;
         break;
       default:
         SystemCoreClock = 0U;
   }
   
 } else {                                     /* If PLL not used      */
   switch (TSB_CG->SYSCR & 7U) {
     case 0U:                                 /* Gear -> fc          */
       SystemCoreClock = CoreClock;
       break;
     case 1U:
     case 2U:
     case 3U:
     case 7U:                                 /* Gear -> reserved    */
       SystemCoreClock = 0U;
       break;
     case 4U:                                 /* Gear -> fc/2        */
       SystemCoreClock = CoreClock / 2U;
       break;
     case 5U:                                 /* Gear -> fc/4        */
       SystemCoreClock = CoreClock / 4U;
       break;
     case 6U:                                 /* Gear -> fc/8        */
       SystemCoreClock = CoreClock / 8U;
       break;
     default:
       SystemCoreClock = 0U;
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
#if (WD_SETUP)                  /* Watchdog Setup */
    TSB_WD->MOD = WDMOD_Val;
    if (!TSB_WD_MOD_WDTE) {     /* If watchdog is to be disabled */
        TSB_WD->CR = WDCR_Val;
    }
#endif

#if (CLOCK_SETUP)               /* Clock(external) Setup */
    TSB_CG->SYSCR = SYSCR_Val;
    TSB_CG->OSCCR &= OSCCR_WUODR_MASK;
    TSB_CG->OSCCR |= OSCCR_WUODR_EXT;
    TSB_CG_OSCCR_HOSCON = 1U;
    TSB_CG_OSCCR_XEN1 = 1U;
    TSB_CG_OSCCR_WUPSEL2 = 1U;
    TSB_CG_OSCCR_WUEON = 1U;
    TSB_CG->PLLSEL = PLLSEL_Ready;
    while (TSB_CG_OSCCR_WUEF) {
    }                           /* Warm-up */
    TSB_CG_OSCCR_OSCSEL = 1U;
    TSB_CG_OSCCR_XEN2 = 0U;

    TSB_CG->OSCCR &= OSCCR_WUODR_MASK;
    TSB_CG->OSCCR |= OSCCR_WUODR_PLL;
    TSB_CG_OSCCR_PLLON = 1U;    /* PLL enabled */
    TSB_CG->STBYCR = STBYCR_Val;
    TSB_CG_OSCCR_WUEON = 1U;
    while (TSB_CG_OSCCR_WUEF) {
    }                           /* Warm-up */

    TSB_CG->PLLSEL = PLLSEL_Val;
#endif
}
