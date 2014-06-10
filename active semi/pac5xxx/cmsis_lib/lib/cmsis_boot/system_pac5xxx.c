/**************************************************************************//**
 * @file     system_.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the Active Semiconductor  Device Series
 * @version  V2.10
 * @date     20. July 2011
 *
 * @note
 * Copyright (C) 2010-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include "pac5xxx_driver_system.h"
#include "pac5xxx_driver_gpio.h"

/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
    
/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __SYS_OSC_CLK     (    4000000UL)    /* Main oscillator frequency      */
#define __SYSTEM_CLOCK    (__SYS_OSC_CLK)	 /* System clock uses internal osc */


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
RAMFUNC_SYSTEM void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  SystemCoreClock = __SYSTEM_CLOCK;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the micro-controller system.
 *         Initialize the System.
 */
RAMFUNC_SYSTEM void SystemInit (void)
{
	SystemCoreClock = __SYSTEM_CLOCK;

	// Small delay to give SWD a chance to attach to device in case of bad program

	// Configure SysTick the number of SysTick clock ticks passed into this function.
	SysTick->LOAD = 1662000; // 0.5s
	SysTick->VAL = 0;

	// Enable SysTick timer countdown and set the clock to reference clock
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	// Wait until it reaches 0 and then return
	while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);

	// Disable SysTick timer
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


