
/**************************************************************************//**
 * @file     pac5xxx_driver_timer.h
 * @brief    Firmware driver for the PAC5XXX timer and DTG units
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
/** @addtogroup PAC5XXX_Driver_Timer PAC5XXX Analog Timer and DTG Driver
  @{
*/

#ifndef PAC5XXX_DRIVER_TIMER_H
#define PAC5XXX_DRIVER_TIMER_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#define PAC5XXX_DRIVER_TIMER_RAM
#ifdef PAC5XXX_DRIVER_TIMER_RAM
#define RAMFUNC_TIMER	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_TIMER
#endif

/** Timer Instance for Timer Driver Configuration */
typedef enum { 
  TimerA,
  TimerB,
  TimerC,
  TimerD
} TimerInstance; 

/** Dead-Time Generator Instance for DTG Driver Configuration */
typedef enum { 
  DTGA0,
  DTGA1,
  DTGA2,
  DTGA3,
  DTGB,
  DTGC,
  DTGD
} DtgInstance; 


/**
 * @brief  This function selects PA0 for PWMA0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma0_pa0(void) { PAC5XXX_GPIOA->PSEL.P0 = 1; }

/**
 * @brief  This function selects PA1 for PWMA1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma1_pa1(void) { PAC5XXX_GPIOA->PSEL.P1 = 1; }

/**
 * @brief  This function selects PA2 for PWMA2 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma2_pa2(void) { PAC5XXX_GPIOA->PSEL.P2 = 1; }

/**
 * @brief  This function selects PA3 for PWMA3 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma3_pa3(void) { PAC5XXX_GPIOA->PSEL.P3 = 1; }

/**
 * @brief  This function selects PD2 for PWMA3 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma3_pd2(void) { PAC5XXX_GPIOD->PSEL.P2 = 1; }

/**
 * @brief  This function selects PD2 for PWMA4 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma4_pd2(void) { PAC5XXX_GPIOD->PSEL.P2 = 2; }

/**
 * @brief  This function selects PA3 for PWMA4 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma4_pa3(void) { PAC5XXX_GPIOA->PSEL.P3 = 2; }

/**
 * @brief  This function selects PA6 for PWMA4 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma4_pa6(void) { PAC5XXX_GPIOA->PSEL.P6 = 1; }

/**
 * @brief  This function selects PD3 for PWMA5 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma5_pd3(void) { PAC5XXX_GPIOD->PSEL.P3 = 1; }

/**
 * @brief  This function selects PD5 for PWMA5 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma5_pd5(void) { PAC5XXX_GPIOD->PSEL.P5 = 1; }

/**
 * @brief  This function selects PA4 for PWMA5 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma5_pa4(void) { PAC5XXX_GPIOA->PSEL.P4 = 1; }

/**
 * @brief  This function selects PA7 for PWMA5 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma5_pa7(void) { PAC5XXX_GPIOA->PSEL.P7 = 1; }

/**
 * @brief  This function selects PD7 for PWMA6 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma6_pd7(void) { PAC5XXX_GPIOD->PSEL.P7 = 1; }

/**
 * @brief  This function selects PA5 for PWMA6 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma6_pa5(void) { PAC5XXX_GPIOA->PSEL.P5 = 1; }

/**
 * @brief  This function selects PD3 for PWMA7 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma7_pd3(void) { PAC5XXX_GPIOD->PSEL.P3 = 2; }

/**
 * @brief  This function selects PD6 for PWMA7 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma7_pd6(void) { PAC5XXX_GPIOD->PSEL.P6 = 1; }

/**
 * @brief  This function selects PA7 for PWMA7 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwma7_pa7(void) { PAC5XXX_GPIOA->PSEL.P7 = 2; }

/**
 * @brief  This function selects PD2 for PWMB0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmb0_pd2(void) { PAC5XXX_GPIOD->PSEL.P2 = 3; }

/**
 * @brief  This function selects PA3 for PWMB0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmb0_pa3(void) { PAC5XXX_GPIOA->PSEL.P3 = 3; }

/**
 * @brief  This function selects PA6 for PWMB0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmb0_pa6(void) { PAC5XXX_GPIOA->PSEL.P6 = 2; }

/**
 * @brief  This function selects PD3 for PWMB1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmb1_pd3(void) { PAC5XXX_GPIOD->PSEL.P3 = 3; }

/**
 * @brief  This function selects PD6 for PWMB1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmb1_pd6(void) { PAC5XXX_GPIOD->PSEL.P6 = 2; }

/**
 * @brief  This function selects PA4 for PWMC0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmc0_pa4(void) { PAC5XXX_GPIOA->PSEL.P4 = 2; }

/**
 * @brief  This function selects PD5 for PWMC1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmc1_pd5(void) { PAC5XXX_GPIOD->PSEL.P5 = 2; }

/**
 * @brief  This function selects PA7 for PWMC1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmc1_pa7(void) { PAC5XXX_GPIOA->PSEL.P7 = 3; }

/**
 * @brief  This function selects PD7 for PWMD0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmd0_pd7(void) { PAC5XXX_GPIOD->PSEL.P7 = 2; }

/**
 * @brief  This function selects PA5 for PWMD0 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmd0_pa5(void) { PAC5XXX_GPIOA->PSEL.P5 = 2; }

/**
 * @brief  This function selects PD4 for PWMD1 output or capture input.
 *
 * @return none
 */
RAMFUNC_TIMER static  void pac5xxx_timer_io_select_pwmd1_pd4(void) { PAC5XXX_GPIOD->PSEL.P4 = 1; }





// Function Prototypes for support functions

/**
 * @brief  This function configures the base timer period, mode and single-use mode
 *         for the given timer
 *
 * @param  timer Timer Instance
 * @param  period Timer Period in clock ticks
 * @param  single_shot Set to 1 for single-use timer mode, 0 for auto-reload
 * @param  mode Timer Mode (up, up/down, etc.)
 * @param  sync Timer slave synchronize (set for slave sync) if set to 1
 * @return none
 *
 */
RAMFUNC_TIMER void pac5xxx_timer_base_config(TimerInstance timer, uint16_t period, int single_shot, TXCTRL_MODE_Type mode, int sync);

/**
 * @brief  This function configures the clock source and pre-scaler for the given timer
 *
 * @param  timer Timer Instance
 * @param  source Timer clock input source
 * @param  prescale Timer pre-scaler
 * @return none
 *
 */
RAMFUNC_TIMER void pac5xxx_timer_clock_config(TimerInstance timer, TXCTRL_CLKIN_Type source, TXCTRL_PS_Type prescale);

/**
 * @brief  This function disables the timer
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_disable(void) { PAC5XXX_TIMERA->CTL.MODE = TxCTL_MODE_DISABLED; }


/**
 * @brief  This function disables the timer
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_disable(void) { PAC5XXX_TIMERB->CTL.MODE = TxCTL_MODE_DISABLED; }


/**
 * @brief  This function disables the timer
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_disable(void) { PAC5XXX_TIMERC->CTL.MODE = TxCTL_MODE_DISABLED; }


/**
 * @brief  This function disables the timer
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_disable(void) { PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_DISABLED; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr0_value(void) { return PAC5XXX_TIMERA->CTR0; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr1_value(void) { return PAC5XXX_TIMERA->CTR1; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr2_value(void) { return PAC5XXX_TIMERA->CTR2; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr3_value(void) { return PAC5XXX_TIMERA->CTR3; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr4_value(void) { return PAC5XXX_TIMERA->CTR4; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr5_value(void) { return PAC5XXX_TIMERA->CTR5; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr6_value(void) { return PAC5XXX_TIMERA->CTR6; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_a_ccctr7_value(void) { return PAC5XXX_TIMERA->CTR7; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_b_ccctr0_value(void) { return PAC5XXX_TIMERB->CTR0; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_b_ccctr1_value(void) { return PAC5XXX_TIMERB->CTR1; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_b_ccctr2_value(void) { return PAC5XXX_TIMERB->CTR2; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_b_ccctr3_value(void) { return PAC5XXX_TIMERB->CTR3; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_c_ccctr0_value(void) { return PAC5XXX_TIMERC->CTR0; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_c_ccctr1_value(void) { return PAC5XXX_TIMERC->CTR1; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_d_ccctr0_value(void) { return PAC5XXX_TIMERD->CTR0; }

/**
 * @brief  This function returns the counter value for the given timer and capture unit
 *
 * @return 16b counter value 
 */
RAMFUNC_TIMER static  uint16_t pac5xxx_timer_d_ccctr1_value(void) { return PAC5XXX_TIMERD->CTR1; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr0_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR0 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr1_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR1 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr2_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR2 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr3_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR3 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr4_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR4 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr5_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR5 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr6_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR6 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_a_ccctr7_value_set(uint16_t value) { PAC5XXX_TIMERA->CTR7 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_b_ccctr0_value_set(uint16_t value) { PAC5XXX_TIMERB->CTR0 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_b_ccctr1_value_set(uint16_t value) { PAC5XXX_TIMERB->CTR1 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_b_ccctr2_value_set(uint16_t value) { PAC5XXX_TIMERB->CTR2 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_b_ccctr3_value_set(uint16_t value) { PAC5XXX_TIMERB->CTR3 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_c_ccctr0_value_set(uint16_t value) { PAC5XXX_TIMERC->CTR0 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_c_ccctr1_value_set(uint16_t value) { PAC5XXX_TIMERC->CTR1 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_d_ccctr0_value_set(uint16_t value) { PAC5XXX_TIMERD->CTR0 = value; }

/**
 * @brief  This function sets the compare value for the given timer and capture unit
 *
 * @param  value 16b compare value
 * @return None
 */
RAMFUNC_TIMER static void pac5xxx_timer_d_ccctr1_value_set(uint16_t value) { PAC5XXX_TIMERD->CTR1 = value; }

/**
 * @brief  This function clears (resets) the given timer, or releases the given timer from reset
 *
 * @param  timer Timer Instance
 * @param  asserted Timer clear signal asserted if set to 1, deassert if set to 0
 * @return none
 *
 * @note This function clears and then resets the clear of the timer, to manually reload a single-shot timer
 */
RAMFUNC_TIMER void pac5xxx_timer_clear(TimerInstance timer, int asserted);

/**
 * @brief  This function clears Timer A
 *
 * @return none
 * @note   This function will set the timer clear bit, which will clear the timer counter, as well as hold the timer in
 *         reset until this bit is cleared. It will also assert the clear output signal to other timers that need to be
 *         synchronized if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_clear_assert(void) { PAC5XXX_TIMERA->CTL.CLR = 1; }

/**
 * @brief  This function releases the clear for Timer A
 *
 * @return none
 * @note   This function will clear the timer clear bit, which will release the timer from reset (if the mode is set to 
 *         up or up/down modes, as well as de-assert the timer clear signal to other timers that need to be synchronzied
 *         if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_clear_deassert(void) { PAC5XXX_TIMERA->CTL.CLR = 0; }

/**
 * @brief  This function clears Timer B
 *
 * @return none
 * @note   This function will set the timer clear bit, which will clear the timer counter, as well as hold the timer in
 *         reset until this bit is cleared. It will also assert the clear output signal to other timers that need to be
 *         synchronized if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_clear_assert(void) { PAC5XXX_TIMERB->CTL.CLR = 1; }

/**
 * @brief  This function releases the clear for Timer B
 *
 * @return none
 * @note   This function will clear the timer clear bit, which will release the timer from reset (if the mode is set to 
 *         up or up/down modes, as well as de-assert the timer clear signal to other timers that need to be synchronzied
 *         if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_clear_deassert(void) { PAC5XXX_TIMERB->CTL.CLR = 0; }

/**
 * @brief  This function clears Timer C
 *
 * @return none
 * @note   This function will set the timer clear bit, which will clear the timer counter, as well as hold the timer in
 *         reset until this bit is cleared. It will also assert the clear output signal to other timers that need to be
 *         synchronized if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_clear_assert(void) { PAC5XXX_TIMERC->CTL.CLR = 1; }

/**
 * @brief  This function releases the clear for Timer C
 *
 * @return none
 * @note   This function will clear the timer clear bit, which will release the timer from reset (if the mode is set to 
 *         up or up/down modes, as well as de-assert the timer clear signal to other timers that need to be synchronzied
 *         if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_clear_deassert(void) { PAC5XXX_TIMERC->CTL.CLR = 0; }

/**
 * @brief  This function clears Timer D
 *
 * @return none
 * @note   This function will set the timer clear bit, which will clear the timer counter, as well as hold the timer in
 *         reset until this bit is cleared. It will also assert the clear output signal to other timers that need to be
 *         synchronized if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_clear_assert(void) { PAC5XXX_TIMERD->CTL.CLR = 1; }

/**
 * @brief  This function releases the clear for Timer D
 *
 * @return none
 * @note   This function will clear the timer clear bit, which will release the timer from reset (if the mode is set to 
 *         up or up/down modes, as well as de-assert the timer clear signal to other timers that need to be synchronzied
 *         if their timer SYNC bit is set.
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_clear_deassert(void) { PAC5XXX_TIMERD->CTL.CLR = 0; }

/**
 * @brief  This function sets the timer period for the given period
 *
 * @param  timer Timer Instance
 * @param  period Timer period in timer clocks
 * @return none
 *
 * @note The user must make sure that this function is called at a time when the timer will not
 *       be in danger of latching the timer counter value.
 */
RAMFUNC_TIMER void pac5xxx_timer_set_period(TimerInstance timer, uint16_t period);

/**
 * @brief  This function enables the base timer interrupt for the given timer
 *
 * @param  timer Timer Instance
 * @param  enable Set to non-zero to enable this interrupt, set to 0 to disable
 * @return none
 *
 * @note This function clears the base timer interrupt flag (if set) before it sets the timer interrupt state
 */
RAMFUNC_TIMER void pac5xxx_timer_base_int_enable(TimerInstance timer, int enable);

/**
 * @brief  This function indicates if the base timer interrupt flag is set
 *
 * @param  timer Timer Instance
 * @return 1 if flag is set, 0 if not set
 *
 */
RAMFUNC_TIMER int pac5xxx_timer_base_int(TimerInstance timer);

/**
 * @brief  This function indicates if the base timer interrupt flag is set for Timer A
 *
 * @return 1 if flag is set, 0 if not set
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_base_int(void) { return (PAC5XXX_TIMERA->CTL.INT & PAC5XXX_TIMERA->CTL.INTEN); }

/**
 * @brief  This function indicates if the base timer interrupt flag is set for Timer B
 *
 * @return 1 if flag is set, 0 if not set
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_b_base_int(void) { return (PAC5XXX_TIMERB->CTL.INT & PAC5XXX_TIMERB->CTL.INTEN); }

/**
 * @brief  This function indicates if the base timer interrupt flag is set for Timer C
 *
 * @return 1 if flag is set, 0 if not set
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_c_base_int(void) { return (PAC5XXX_TIMERC->CTL.INT & PAC5XXX_TIMERC->CTL.INTEN); }

/**
 * @brief  This function indicates if the base timer interrupt flag is set for Timer D
 *
 * @return 1 if flag is set, 0 if not set
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_d_base_int(void) { return (PAC5XXX_TIMERD->CTL.INT & PAC5XXX_TIMERD->CTL.INTEN); }

/**
 * @brief  This function clears the base timer interrupt flag for the given timer
 *
 * @param  timer Timer Instance
 * @return none
 *
 */
RAMFUNC_TIMER void pac5xxx_timer_base_int_clear(TimerInstance timer);

/**
 * @brief  This function clears the base timer interrupt flag for Timer A
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_base_int_clear(void) { PAC5XXX_TIMERA->CTL.INT = 1; }

/**
 * @brief  This function clears the base timer interrupt flag for Timer B
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_base_int_clear(void) { PAC5XXX_TIMERB->CTL.INT = 1; }

/**
 * @brief  This function clears the base timer interrupt flag for Timer C
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_base_int_clear(void) { PAC5XXX_TIMERC->CTL.INT = 1; }

/**
 * @brief  This function clears the base timer interrupt flag for Timer D
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_base_int_clear(void) { PAC5XXX_TIMERD->CTL.INT = 1; }

/**
 * @brief  This function configures the compare latch time for the given timer. User may set this value
 *         to latch either when the timer counts from the period value to 0 in up mode or from 1 to 0 in 
 *         up/down mode
 *
 * @param  timer Timer Instance
 * @param  latch_config The period latch configuration mode
 * @return none
 *
 */
RAMFUNC_TIMER void pac5xxx_timer_capture_latch_config(TimerInstance timer, TXCCTRL_LATCH_Type latch_config);

/**
 * @brief  This function configures the given capture and compare unit for the given timer.
 *
 * @param  timer Timer Instance
 * @param  cc_num Capture/Compare unit number (0 to n)
 * @param  compare_value The compare value for the given compare unit
 * @param  int_en Set to 1 in order to enable interrupts for the given capture/compare unit, 0 to disable
 * @return none
 *
 * @note   This function does not enable or disable the NVIC IRQn interrupt. This must be done outside of this
 *         function by calling the /a NVIC_EnableIRQ() and /a NVIC_DisableIRQ() functions.
 */
RAMFUNC_TIMER void pac5xxx_timer_cctrl_config(TimerInstance timer, int cc_num, uint16_t compare_value, int int_en);

/**
 * @brief  This function configures the given capture/compare unit into capture mode
 *
 * @param  timer Timer Instance
 * @param  enabled Set to 1 to enable capture on the given Capture/Compare Unit, 0 to disable
 * @param  cc_num Capture/Compare unit number (0 to n)
 * @param  int_en Set to 1 in order to enable interrupts for the given capture/compare unit, 0 to disable
 * @param  cap_edge_det The capture edge to detect (rising, falling, both) when capture is enabled
 * @return none
 *
 * @note Note that this function also configures the GPIO pins for input capture that are selected for the given timer and capture unit
 *
 */
RAMFUNC_TIMER void pac5xxx_timer_cctrl_capture_config(TimerInstance timer, int enabled, int cc_num, int int_en, TXCCTRL_CAPEDGE_Type cap_edge_det);

/**
 * @brief  This function configures sets the interrupt enable state for the given timer and CCR unit
 *
 * @param  timer Timer Instance
 * @param  ccr_num Capture/Compare unit number (0 to n)
 * @param  enable Set to 1 to enable interrupts on the given Capture/Compare Unit, 0 to disable
 * @return none
 *
 * @note   This function does not enable or disable the NVIC IRQn interrupt. This must be done outside of this
 *         function by calling the /a NVIC_EnableIRQ() and /a NVIC_DisableIRQ() functions.
 */
RAMFUNC_TIMER void pac5xxx_timer_cctrl_int_enable(TimerInstance timer, int ccr_num, int enable);

/**
 * @brief  This function indicates if there is a pending interrupt on the given timer and CCR unit
 *
 * @param  timer Timer Instance
 * @param  ccr_num Capture/Compare unit number (0 to n)
 * @return 1 if interrupt pending, 0 if not
 *
 * @note If the ccr_num argument is invalid, this function does nothing.
 */
RAMFUNC_TIMER int pac5xxx_timer_cctrl_int(TimerInstance timer, int ccr_num);

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 0
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_0_int(void) { return (PAC5XXX_TIMERA->CCTRL0.CCINT & PAC5XXX_TIMERA->CCTRL0.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 1
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_1_int(void) { return (PAC5XXX_TIMERA->CCTRL1.CCINT & PAC5XXX_TIMERA->CCTRL1.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 2
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_2_int(void) { return (PAC5XXX_TIMERA->CCTRL2.CCINT & PAC5XXX_TIMERA->CCTRL2.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 3
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_3_int(void) { return (PAC5XXX_TIMERA->CCTRL3.CCINT & PAC5XXX_TIMERA->CCTRL3.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 4
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_4_int(void) { return (PAC5XXX_TIMERA->CCTRL4.CCINT & PAC5XXX_TIMERA->CCTRL4.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 5
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_5_int(void) { return (PAC5XXX_TIMERA->CCTRL5.CCINT & PAC5XXX_TIMERA->CCTRL5.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 6
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_6_int(void) { return (PAC5XXX_TIMERA->CCTRL6.CCINT & PAC5XXX_TIMERA->CCTRL6.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer A, CCTRL 7
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_a_cctrl_7_int(void) { return (PAC5XXX_TIMERA->CCTRL7.CCINT & PAC5XXX_TIMERA->CCTRL7.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer B, CCTRL 0
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_b_cctrl_0_int(void) { return (PAC5XXX_TIMERB->CCTRL0.CCINT & PAC5XXX_TIMERB->CCTRL0.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer B, CCTRL 1
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_b_cctrl_1_int(void) { return (PAC5XXX_TIMERB->CCTRL1.CCINT & PAC5XXX_TIMERB->CCTRL1.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer B, CCTRL 2
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_b_cctrl_2_int(void) { return (PAC5XXX_TIMERB->CCTRL2.CCINT & PAC5XXX_TIMERB->CCTRL2.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer B, CCTRL 3
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_b_cctrl_3_int(void) { return (PAC5XXX_TIMERB->CCTRL3.CCINT & PAC5XXX_TIMERB->CCTRL3.CCINTEN); }



/**
 * @brief  This function indicates if there is a pending interrupt for Timer C, CCTRL 0
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_c_cctrl_0_int(void) { return (PAC5XXX_TIMERC->CCTRL0.CCINT & PAC5XXX_TIMERC->CCTRL0.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer C, CCTRL 1
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_c_cctrl_1_int(void) { return (PAC5XXX_TIMERC->CCTRL1.CCINT & PAC5XXX_TIMERC->CCTRL1.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer D, CCTRL 0
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_d_cctrl_0_int(void) { return (PAC5XXX_TIMERD->CCTRL0.CCINT & PAC5XXX_TIMERD->CCTRL0.CCINTEN); }

/**
 * @brief  This function indicates if there is a pending interrupt for Timer D, CCTRL 1
 *
 * @return 1 if interrupt pending, 0 if not
 *
 */
RAMFUNC_TIMER static  int pac5xxx_timer_d_cctrl_1_int(void) { return (PAC5XXX_TIMERD->CCTRL1.CCINT & PAC5XXX_TIMERD->CCTRL1.CCINTEN); }

/**
 * @brief  This function clears the interrupt flag for the given timer and CCR unit
 *
 * @param  timer Timer Instance
 * @param  ccr_num Capture/Compare unit number (0 to n)
 * @return none
 *
 * @note If the ccr_num argument is invalid, this function will return 0.
 */
RAMFUNC_TIMER void pac5xxx_timer_cctrl_int_clear(TimerInstance timer, int ccr_num);

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 0
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_0_int_clear(void) { PAC5XXX_TIMERA->CCTRL0.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 1
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_1_int_clear(void) { PAC5XXX_TIMERA->CCTRL1.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 2
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_2_int_clear(void) { PAC5XXX_TIMERA->CCTRL2.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 3
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_3_int_clear(void) { PAC5XXX_TIMERA->CCTRL3.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 4
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_4_int_clear(void) { PAC5XXX_TIMERA->CCTRL4.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 5
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_5_int_clear(void) { PAC5XXX_TIMERA->CCTRL5.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 6
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_6_int_clear(void) { PAC5XXX_TIMERA->CCTRL6.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer A, CCR unit 7
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_a_cctrl_7_int_clear(void) { PAC5XXX_TIMERA->CCTRL7.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer B, CCR unit 0
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_cctrl_0_int_clear(void) { PAC5XXX_TIMERB->CCTRL0.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer B, CCR unit 1
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_cctrl_1_int_clear(void) { PAC5XXX_TIMERB->CCTRL1.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer B, CCR unit 2
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_cctrl_2_int_clear(void) { PAC5XXX_TIMERB->CCTRL2.CCINT = 1; }


/**
 * @brief  This function clears the interrupt flag for Timer B, CCR unit 3
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_b_cctrl_3_int_clear(void) { PAC5XXX_TIMERB->CCTRL3.CCINT = 1; }


/**
 * @brief  This function clears the interrupt flag for Timer C, CCR unit 0
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_cctrl_0_int_clear(void) { PAC5XXX_TIMERC->CCTRL0.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer C, CCR unit 1
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_c_cctrl_1_int_clear(void) { PAC5XXX_TIMERC->CCTRL1.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer D, CCR unit 0
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_cctrl_0_int_clear(void) { PAC5XXX_TIMERD->CCTRL0.CCINT = 1; }

/**
 * @brief  This function clears the interrupt flag for Timer D, CCR unit 1
 *
 * @return none
 *
 */
RAMFUNC_TIMER static  void pac5xxx_timer_d_cctrl_1_int_clear(void) { PAC5XXX_TIMERD->CCTRL1.CCINT = 1; }

/**
 * @brief  This function configures the given Dead-Time Generator (DTG)
 *
 * @param  dtg DTG Instance
 * @param  led Leading Edge Delay
 * @param  ted Trailing Edge Delay
 * @param  inv_a Set to 1 to invert OUT[n] output, 0 to not invert
 * @param  inv_b Set to 1 to invert OUT[n+1] output, 0 to not invert
 * @param  pass Set to 1 to configure pass-through mode, 0 for normal operation
 * @param  otp Set to 1 to configure on-time preservation PWM mode, 0 for normal operation
 * @return none
 *
 */
RAMFUNC_TIMER void pac5xxx_dtg_config(DtgInstance dtg, uint16_t led, uint16_t ted, int inv_a, int inv_b, int pass, int otp);

/**
 * @brief This function enables the clock pre-scaling (divider) for the dead-time generator
 *
 * @param timer Timer instance for the DTG clock configuration
 * @param enabled 0: Disable clock pre-scaling (DTG clock is timer input clock before pre-scaling); 1: Enable clock pre-scaling (DTG clock is timer input clock after pre-scaling).
 * @return none
 */
RAMFUNC_TIMER void pac5xxx_dtg_clock_prescale(TimerInstance timer, int enabled);


/*@}*/ /* end of group PAC5XXX_Driver_Timer */

#endif // PAC5XXX_DRIVER_TIMER_H

