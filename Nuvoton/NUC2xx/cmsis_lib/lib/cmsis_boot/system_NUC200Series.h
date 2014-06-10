/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#ifndef __SYSTEM_NUC1xx_H
#define __SYSTEM_NUC1xx_H

#ifdef __cplusplus
 extern "C" {
#endif 
/*---------------------------------------------------------------------------------------------------------*/
/* Macro Definition                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

//#define DEBUG_ENABLE_SEMIHOST   /* To enable semihosted. !!!The SEMIHOSTED of startup_NUC1xx.s must be {TRUE} */

/* Using UART0 or UART1 */  
#define DEBUG_PORT   UART0

/**
 *
 * @details    This is used to enable PLL to speed up booting at startup. Remove it will cause system using 
 *             default clock source (External crystal or internal 22.1184MHz IRC).
 *             Enable this option will casue system booting in 50MHz(By XTAL) or 50.1918MHz(By IRC22M) according to
 *             user configuration setting in CONFIG0
 *             
 */
#define INIT_SYSCLK_AT_BOOTING
/*----------------------------------------------------------------------------
  Define SYSCLK
 *----------------------------------------------------------------------------*/
#define __XTAL      (12000000UL)    /*!< External Crystal Clock Frequency     */
#define __RTC_XTAL  (32768UL)       /*!< External Crystal Clock Frequency 32.768KHz */
#define __IRC22M    (22118400UL)    /*!< Internal 22M RC Oscillator Frequency */
#define __IRC10K    (10000UL)       /*!< Internal 10K RC Oscillator Frequency */
#define __HSI       (50000000UL)     /*!< PLL default output is 50MHz */

extern uint32_t SystemCoreClock;                   /*!< System Clock Frequency (Core Clock) */
extern uint32_t CyclesPerUs;                       /*!< Cycles per micro second              */
extern uint32_t PllClock;                          /*!< PLL Output Clock Frequency           */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system
 *         Initialise GPIO directions and values
 */
extern void SystemInit(void);


/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock 
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif
