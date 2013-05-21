/**
 *******************************************************************************
 * @file    system_TMPM369.c
 * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Source File for the
 *          TOSHIBA 'TMPM369' Device Series 
 * @version V2.0.2.3 (Tentative)
 * @date    2011/09/29
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

#include <stdint.h>
#include "TMPM369.h"

/*-------- <<< Start of configuration section >>> ----------------------------*/

/* Watchdog Timer (WD) Configuration */
#define WD_SETUP    1
#define WDMOD_Val   (0x00000000UL)
#define WDCR_Val    (0x000000B1UL)

/* Clock Generator (CG) Configuration */
#define CLOCK_SETUP      1
#define SYSCR_Val        (0x00010000UL)
#define OSCCR_Val        (0x000E0134UL) /* OSCCR<OSCSEL> = 1, OSCCR<XEN2> = 0, OSCCR<XEN1> = 1, OSCCR<PLLON> = 1, <EHOSCSEL> = 1 */
#define OSCCR_WUODR_MASK (0x000FFFFFUL)
#define OSCCR_WUODR_EXT  (0xC3500000UL) /* OSCCR<WUPODR11:0> = 50000/16, warm-up time is 5ms @ XTALH = 10MHz */
#define OSCCR_WUODR_PLL  (0x03E80000UL) /* OSCCR<WUPODR11:0> = 1000/16, warm-up time is 100us @ XTALH = 10MHz */
#define STBYCR_Val       (0x00000003UL)
#define PLLSEL_Ready     (0x00007524UL)
#define PLLSEL_Val       (0x00007525UL)


/*-------- <<< End of configuration section >>> ------------------------------*/

/*-------- DEFINES -----------------------------------------------------------*/
/* Define clocks */
#define EXTALH (16000000UL)     /* External high-speed oscillator freq */
#define XTALH  (10000000UL)     /* Internal high-speed oscillator freq */

#if (CLOCK_SETUP)               /* Clock(external) Setup */
/* Determine core clock frequency according to settings */
/* System clock is high-speed clock*/
#if (OSCCR_Val & (1U<<17))
  #define CORE_TALH (EXTALH)
#else
  #define CORE_TALH (XTALH)
#endif

#if ((PLLSEL_Val & (1U<<0)) && (OSCCR_Val & (1U<<2)))   /* If PLL selected and enabled */
  #if (CORE_TALH == 8000000UL)                          /* If input is 8MHz */
    #if ((PLLSEL_Val & 0x0000FFFEUL) == 0xB22EUL)         /* If PLLSET[14:0] is 0x5917 */
      #define __CORE_CLK   (CORE_TALH * 6U )            /* output clock is 48MHz */
    #elif ((PLLSEL_Val & 0x0000FFFEUL) == 0xB34CUL)       /* If PLLSET[14:0] is 0x59A6 */
      #define __CORE_CLK   (CORE_TALH * 10U )           /* output clock is 80MHz */
    #else                                               /* fc -> reserved            */
      #define __CORE_CLK   (0U)
    #endif                                              /* End input is 8MHz         */
  #elif (CORE_TALH == 10000000UL)                       /* If input is 10MHz */
    #if ((PLLSEL_Val & 0x0000FFFEUL) == 0xE53CUL)         /* If PLLSET[14:0] is 0x729E */
      #define __CORE_CLK   (CORE_TALH * 8U )            /* output clock is 80MHz */
    #else                                               /* fc -> reserved              */
      #define __CORE_CLK   (0U)
    #endif                                              /* End input is 10MHz         */
  #elif (CORE_TALH == 12000000UL)                       /* If input is 12MHz */
    #if ((PLLSEL_Val & 0x0000FFFEUL) == 0xB41EUL)         /* If PLLSET[14:0] is 0x5A0F */
      #define __CORE_CLK   (CORE_TALH * 4U )            /* output clock is 48MHz */
    #elif ((PLLSEL_Val & 0x0000FFFEUL) == 0xC52CUL)       /* If PLLSET[14:0] is 0x6296 */
      #define __CORE_CLK   (CORE_TALH * 6U )            /* output clock is 72MHz */
    #else                                               /* fc -> reserved            */
      #define __CORE_CLK   (0U)
    #endif                                              /* End input is 12MHz         */
  #elif (CORE_TALH == 16000000UL)                       /* If input is 16MHz */
    #if ((PLLSEL_Val & 0x0000FFFEUL) == 0xE416UL)         /* If PLLSET[14:0] is 0x720B */
      #define __CORE_CLK   (CORE_TALH * 3U )            /* output clock is 48MHz */
    #elif ((PLLSEL_Val & 0x0000FFFEUL) == 0x7524UL)       /* If PLLSET[14:0] is 0x3A92 */
      #define __CORE_CLK   (CORE_TALH * 5U )            /* output clock is 80MHz */
    #else                                               /* fc -> reserved        */
      #define __CORE_CLK   (0U)
    #endif                                              /* End input is 16MHz         */
  #else                                                 /* input clock not known        */
    #define __CORE_CLK   (0U)
    #error "Core Oscillator Frequency invalid!"
  #endif                                                /* End switch input clock         */
#else
  #define __CORE_CLK   (CORE_TALH)
#endif

#if   ((SYSCR_Val & 7U) == 0U)                          /* Gear -> fc             */
  #define __CORE_SYS   (__CORE_CLK)
#elif ((SYSCR_Val & 7U) == 4U)                          /* Gear -> fc/2           */
  #define __CORE_SYS   (__CORE_CLK / 2U)
#elif ((SYSCR_Val & 7U) == 5U)                          /* Gear -> fc/4           */
  #define __CORE_SYS   (__CORE_CLK / 4U)
#elif ((SYSCR_Val & 7U) == 6U)                          /* Gear -> fc/8           */
  #define __CORE_SYS   (__CORE_CLK / 8U)
#elif ((SYSCR_Val & 7U) == 7U)                          /* Gear -> fc/16          */
  #define __CORE_SYS   (__CORE_CLK / 16U)
#else                                                   /* Gear -> reserved       */
  #define __CORE_SYS   (0U)
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
{                               /* Get Core Clock Frequency      */
    uint32_t CoreClock = 0U;
    uint32_t CoreClockInput = 0U;
    /* Determine clock frequency according to clock register values        */
    /* System clock is high-speed clock */
    if (TSB_CG_OSCCR_OSCSEL) {  /* If system clock is External high-speed oscillator freq */
        CoreClock = EXTALH;
    } else {                    /* If system clock is Internal high-speed oscillator freq */
        CoreClock = XTALH;
    }
    if (TSB_CG_PLLSEL_PLLSEL && TSB_CG_OSCCR_PLLON) {                        /* If PLL enabled      */
        if (CoreClock == 8000000UL) {                                          /* If input is 8MHz */ 
            if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000B22EUL) {             /* If PLLSET[14:0] is 0x5917 */          
                CoreClockInput = CoreClock * 6U;                             /* output clock is 48MHz */  
            } else if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000B3C4UL) {      /* If PLLSET[14:0] is 0x59A6 */      
                CoreClockInput = CoreClock * 10U;                            /* output clock is 80MHz */  
            } else {                                                               
                CoreClockInput = 0U;                                         /* fc -> reserved            */  
            }                                                                                                 
        } else if (CoreClock == 10000000UL) {                                  /* If input is 10MHz */                                 
            if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000E53CUL) {             /* If PLLSET[14:0] is 0x729E */          
                CoreClockInput = CoreClock * 8U;                             /* output clock is 80MHz */ 
            } else {                                                               
                CoreClockInput = 0U;                                         /* fc -> reserved              */
            }                                                                                                 
        } else if (CoreClock == 12000000UL) {                                  /* If input is 12MHz */                                 
            if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000B41EUL) {             /* If PLLSET[14:0] is 0x5A0F */          
                CoreClockInput = CoreClock * 4U;                             /* output clock is 48MHz */  
            } else if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000C52CUL) {      /* If PLLSET[14:0] is 0x6296 */     
                CoreClockInput = CoreClock * 6U;                             /* output clock is 72MHz */  
            } else {                                                               
                CoreClockInput = 0U;                                         /* fc -> reserved            */  
            }                                                                                                 
        } else if (CoreClock == 16000000UL) {                                  /* If input is 16MHz */                                  
            if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x0000E416UL) {             /* If PLLSET[14:0] is 0x720B */          
                CoreClockInput = CoreClock * 3U;                             /* output clock is 48MHz */ 
            } else if ((TSB_CG->PLLSEL & 0x0000FFFEUL) == 0x00007524UL) {      /* If PLLSET[14:0] is 0x3A92 */      
                CoreClockInput = CoreClock * 5U;                             /* output clock is 80MHz */ 
            } else {                                                               
                CoreClockInput = 0U;                                         /* fc -> reserved        */      
            }                                                                                                 
        } else {                                                                                              
            CoreClockInput = 0U;                                             
        }                                                                    
    } else {                                                                 
        CoreClockInput = CoreClock;                                          
    }                                                                        
    switch (TSB_CG->SYSCR & 7U) {                                            
    case 0U:                                                                 
        SystemCoreClock = CoreClockInput;                                    /* Gear -> fc          */    
        break;                                                               
    case 1U:                                                                 
    case 2U:                                                                 
    case 3U:                                                                 /* Gear -> reserved    */                     
        SystemCoreClock = 0U;                                                
        break;                                                               
    case 4U:                                                                 /* Gear -> fc/2        */                     
        SystemCoreClock = CoreClockInput / 2U;                               
        break;                                                               
    case 5U:                                                                 /* Gear -> fc/4        */                     
        SystemCoreClock = CoreClockInput / 4U;
        break;
    case 6U:                                                                 /* Gear -> fc/8        */
        SystemCoreClock = CoreClockInput / 8U;
        break;
    case 7U:                                                                 /* Gear -> fc/16       */
        if (CoreClockInput >= 16000000UL){
        SystemCoreClock = CoreClockInput / 16U;
      }else{
      	SystemCoreClock = 0U;
      }
        break;
    default:
        SystemCoreClock = 0U;
        break;
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
void SystemInit(void)           /* the used clock: external ocsilltior :16MHz, Pll: 5*/
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
    TSB_CG_OSCCR_EHOSCSEL = 1U;
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
