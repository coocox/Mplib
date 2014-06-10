
/**************************************************************************//**
 * @file     pac5xxx_driver_arm.h
 * @brief    Firmware driver for the PAC5XXX ARM functions
 * @version  V0.2
 * @date     17 May 2012
 *
 * @note
 * Copyright (C) 2012 Active Semiconductor. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifndef PAC5XXX_DRIVER_ADC_H
#define PAC5XXX_DRIVER_ADC_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_ARM_RAM
#define RAMFUNC_ARM	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_ARM
#endif

// Function Prototypes for support functions

/**
 * @brief  This function sets the ARM up to enter deep sleep mode, when sleep mode
 *         is entered
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_deep_enable(void) { SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; }

/**
 * @brief  This function sets the ARM up to enter normal sleep mode, when sleep mode
 *         is entered (not deep sleep mode)
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_deep_disable(void) { SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk; }

/**
 * @brief  This function sets the ARM up to enter sleep mode upon returning from handler mode
 *         to thread mode. When the WFI or WFE instructions are executed, either sleep or deep sleep
 *         modes will be entered after exiting handler mode.
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_on_exit_enable(void) { SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk; }

/**
 * @brief  This function sets the ARM up to enter either sleep mode or deep sleep mode when the WFI or WFE 
 * instructions are executed.
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_on_exit_disable(void) { SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk; }

/**
 * @brief  This function enters the sleep mode on the ARM using the WFI 
 *         (wait for interrupt) instruction and performs clock management
 *         before entering sleep mode
 *
 * @return none
 *
 */
RAMFUNC_ARM void pac5xxx_arm_sleep_wfi(void);

/**
 * @brief  This function enters the sleep mode on the ARM using the WFE 
 *         (wait for event) instruction and performs clock management
 *         before entering sleep mode
 *
 * @return none
 *
 */
RAMFUNC_ARM void pac5xxx_arm_sleep_wfe(void);



#endif // PAC5XXX_DRIVER_ARM_H

