/**************************************************************************//**
 * @file     pac5xxx_driver_system.h
 * @brief    Firmware driver for the PAC5XXX system and clock controllers
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

/*------------- Analog to Digital Converter (ADC) ----------------------*/
/** @addtogroup PAC5XXX_Driver_System PAC5XXX System and Clock Controller
  @{
*/

#ifndef PAC5XXX_DRIVER_SYSTEM_H
#define PAC5XXX_DRIVER_SYSTEM_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_SYSTEM_RAM
#define RAMFUNC_SYSTEM	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_SYSTEM
#endif

// Function Prototypes for support functions

/**
 * @brief  This function configures the PAC5XXX clock control system
 *
 * @param  clock_select The input clock select for FRCLK
 * @param  aclk_div The ACLK divider
 * @param  fclk_div The FCLK divider
 * @return none
 *
 */
RAMFUNC_SYSTEM void pac5xxx_sys_ccs_config(CCSCTL_CLKIN_Type clock_select, CCSCTL_ACLKDIV_Type aclk_div, CCSCTL_HCLKDIV_Type fclk_div);

/**
 * @brief  This function selects the PLL clock output as the system clock input for the ACLK and FCLK dividers
 *
 * @return none
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_ccs_pll_select(void) { PAC5XXX_SYSCTL->CCSCTL.FCLK = 1; }

/**
 * @brief  This function selects the FRCLK as the system clock input for the ACLK and FCLK dividers
 *
 * @return none
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_ccs_frclk_select(void) { PAC5XXX_SYSCTL->CCSCTL.FCLK = 0; }

/**
 * @brief  This function configures the PAC5XXX internal oscillator
 *
 * @param  freq_select Oscillator frequency select
 * @return none
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_osc_config(OSCCTL_FREQSEL_Type freq_select) { PAC5XXX_SYSCTL->OSCCTL.OSCP = freq_select; }

/**
 * @brief  This function enables the PAC5XXX internal oscillator
 *
 * @return none
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_osc_enable(void) { PAC5XXX_SYSCTL->OSCCTL.OSCEN = 1; }

/**
 * @brief  This function disables the PAC5XXX internal oscillator
 *
 * @return none
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_osc_disable(void) { PAC5XXX_SYSCTL->OSCCTL.OSCEN = 0; }

/**
 * @brief  This function configures the PAC5XXX PLL dividers
 *
 * @param  input_div Input clock divider
 * @param  feedback_div Feedback divider 
 * @param  output_div Output divider
 * @return none
 *
 */
RAMFUNC_SYSTEM void pac5xxx_sys_pll_config_dividers(uint8_t input_div, uint16_t feedback_div, uint8_t output_div);

/**
 * @brief  This function enables the PAC5XXX PLL
 * @param  delay The number of SysTick clocks to delay
 * @return none
 *
 * @note The user should make sure that PLL bypass is active, by calling the function:
 *       \a pac5xxx_sys_pll_bypass_enable() before calling this function.
 *
 * @note There is a mandatory 500us delay after the PLL is enabled before it is stable and 
 *       ready to use. This function will enforce the passed in delay after it enables the PLL
 *       before it returns control to the user. At that point, the user may remove the PLL
 *       bypass by calling \a pac5xxx_sys_pll_bypass_disable(). This time delay is enforced
 *       by polling the SysTick timer.
 *
 *       
 */
RAMFUNC_SYSTEM void pac5xxx_sys_pll_enable(int delay);

/**
 * @brief  This function disables the PAC5XXX PLL
 * @return none
 *
 * @note The user should make sure that the PLL bypass is enabled before this function
 *       is called. Otherwise, the clock to the PAC5XXX may stop, halting the processor.
 *       The user should also make sure that the clock control mux is set properly to 
 *       supply the processor a clock before disabling the PLL.
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_pll_disable(void) { PAC5XXX_SYSCTL->PLLCTL.PLLEN = 0; }

/**
 * @brief  This function configures and enables the PLL for a 100MHz output
 *
 * @param  fclk_div HCLK output divider after PLL stage
 * @param  aclk_div ACLK output divider after PLL stage
 *
 * @note   This function configures and enables the PLL from the internal reference (CLKREF), with the
 *         given HCLK and FCLK dividers. After the 500us wait time (for the PLL to lock), the FCLK output
 *         is switched from CLKREF to the PLL output.
 */
RAMFUNC_SYSTEM void pac5xxx_sys_pll_config_100mhz(CCSCTL_HCLKDIV_Type fclk_div, CCSCTL_ACLKDIV_Type aclk_div);

/**
 * @brief  This function configures and enables the PLL with the given frequency output
 *
 * @param  frequency_mhz Output frequency in MHz
 *
 * @note   This function configures and enables the PLL from the internal reference (CLKREF). After the 500us
 *         wait time (for the PLL to lock), the FCLK output is switched from CLKREF to the PLL output.
 */
RAMFUNC_SYSTEM void pac5xxx_sys_pll_config(int frequency_mhz);

/**
 * @brief  This function enables the PAC5XXX Crystal Oscillator
 *
 * @return none
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_xtal_enable(void) { PAC5XXX_SYSCTL->XTALCTL.XTALEN = 1; }

/**
 * @brief  This function disables the PAC5XXX Crystal Oscillator
 *
 * @return none
 *
 */
RAMFUNC_SYSTEM static  void pac5xxx_sys_xtal_disable(void) { PAC5XXX_SYSCTL->XTALCTL.XTALEN = 0; }

/*@}*/ /* end of group PAC5XXX_Driver_System */

#endif // PAC5XXX_DRIVER_ADC_H

