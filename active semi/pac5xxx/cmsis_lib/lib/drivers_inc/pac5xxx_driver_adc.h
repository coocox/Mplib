/**************************************************************************//**
 * @file     pac5xxx_driver_adc.h
 * @brief    Firmware driver for the PAC5XXX ADC
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

/** @addtogroup PAC5XXX_Driver_ADC PAC5XXX ADC
  @{
*/

#ifndef PAC5XXX_DRIVER_ADC_H
#define PAC5XXX_DRIVER_ADC_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_ADC_RAM
#define RAMFUNC_ADC	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_ADC
#endif

// Function Prototypes for support functions

// EMUX SUPPORT

/**
 * @brief  This function configures the ADC's external MUX
 *
 * @param  control_type Type of external mux control
 * @param  divider External MUX clock divider
 * @return none
 *
 */
RAMFUNC_ADC void pac5xxx_adc_emux_config(ADC_EMUX_CTL_Type control_type, ADC_EMUX_DIV_Type divider);

/**
 * @brief  This function writes a character to the ADC external MUX
 *
 * @param  data 8b of data to write
 * @return none
 *
 */
RAMFUNC_ADC static  void pac5xxx_adc_emux_data_write(unsigned char data) { PAC5XXX_ADC->EMUXDATA.VAL = data; }

//
// ADC CONFIGURATION
//

/**
 * @brief  This function configures the ADC
 *
 * @param  adc_mode The ADC mode from \a ADCCTL_MODE
 * @param  clock_divider Clock divider for the ADC clock
 * @param  repeat Set to 1 to perform repeated conversions of the selected channel
 * @return none
 *
 * @note This function does not enable the ADC
 */
RAMFUNC_ADC void pac5xxx_adc_config(ADCCTL_ADMODE_Type adc_mode, ADCCTL_CLKDIV_Type clock_divider, int repeat);

/**
 * @brief  This function configures the IO ports on the device for the given ADC channels
 *
 * @param  channel_mask Bit-mask of the ADC channels to enable or disable IOs for
 * @return none
 *
 */
RAMFUNC_ADC void pac5xxx_adc_config_io(uint8_t channel_mask);

/**
 * @brief  This function configures the EMUX IO ports on the device for EMUX output
 *
 * @return none
 *
 */
RAMFUNC_ADC void pac5xxx_adc_config_emux_io(void);

/**
 * @brief  This function sets the enable state of the ADC
 *
 * @param  enable If set to a 1, enables the ADC. If set to a 0, disables the ADC
 * @return none
 */
RAMFUNC_ADC static void pac5xxx_adc_enable(int enable) { PAC5XXX_ADC->ADCCTL.ADCEN = enable; }

/**
 * @brief  This function sets the ADC MUX channel
 *
 * @param  mux_channel ADC MUX channel to set from \a ADCCTL_ADMUX_Type
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_set_mux(ADCCTL_ADMUX_Type mux_channel) { PAC5XXX_ADC->ADCCTL.ADCMUX = mux_channel; }

/**
 * @brief  This function sets the ADC MUX and starts a conversion
 *
 * @param  channel The ADC channel to set from \a ADCCTL_ADMUX_Type
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_set_mux_and_start(ADCCTL_ADMUX_Type channel) { PAC5XXX_ADC->ADCCTL.ADCMUX = channel; PAC5XXX_ADC->ADCCTL.ADCSTART = 1; }

/**
 * @brief  This function starts an ADC Conversion with the current configuration
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_start(void) { PAC5XXX_ADC->ADCCTL.ADCSTART = 1; }

/**
 * @brief  This function stops the ADC
 *
 * @return none
 */
RAMFUNC_ADC static void pac5xxx_adc_stop(void) { PAC5XXX_ADC->ADCCTL.ADCSTART = 0; }

/**
 * @brief  This function indicates if the last conversion has completed
 *
 * @return Non-zero if the conversion has completed
 */
RAMFUNC_ADC static  int pac5xxx_adc_conversion_complete(void) { return PAC5XXX_ADC->ADCINT.ADCINT; }

/**
 * @brief  This function returns the result of the last ADC conversion
 *
 * @return Conversion result
 */
RAMFUNC_ADC static  uint16_t pac5xxx_adc_get_result(void) { return PAC5XXX_ADC->ADCCR.VAL; }

//
// INTERRUPT SUPPORT
//

/**
 * @brief  This function enables the interrupt enable state for the EMUX
 *
 * @param  enable If set to a 1, enables the interrupt. If set to 0, disables the interrupt
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_enable_emux(int enable) { PAC5XXX_ADC->ADCINT.EMUXINT_EN = enable; }

/**
 * @brief  This function clears the interrupt flag for the EMUX
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_clear_emux(void) { PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_EMUXINT); }

/**
 *  @brief This function returns the interrupt flag status for the ADC EMUX
 *
 * @return 1 if interrupt flag is set, 0 if not
 */
RAMFUNC_ADC static  int pac5xxx_adc_int_emux(void) { return (PAC5XXX_ADC->ADCINT.EMUXINT & PAC5XXX_ADC->ADCINT.EMUXINT_EN); }

/**
 * @brief  This function clears the interrupt flag and sets the interrupt state for the ADC
 *
 * @param  enable If set to a 1, enables the interrupt. If set to 0, disables the interrupt
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_enable_adc(int enable) { PAC5XXX_ADC->ADCINT.ADCINT_EN = enable; }

/**
 * @brief  This function clears the interrupt flag for the ADC
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_clear_adc(void) { PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_ADCINT); }

/**
 *  @brief This function returns the interrupt flag status for the ADC manual conversions
 *
 * @return 1 if interrupt flag is set, 0 if not
 */
RAMFUNC_ADC static  int pac5xxx_adc_int_adc(void) { return (PAC5XXX_ADC->ADCINT.ADCINT & PAC5XXX_ADC->ADCINT.ADCINT_EN); }


/**
 * @brief  This function clears the interrupt flag and sets the interrupt state for the unit
 *
 * @param  enable If set to a 1, enables the interrupt. If set to 0, disables the interrupt
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_enable_as0(int enable) { PAC5XXX_ADC->ADCINT.AS0INT_EN = enable; }

/**
 * @brief  This function clears the interrupt flag for the ASC0 unit
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_clear_as0() { PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_AS0INT); }

/**
 *  @brief This function returns the interrupt flag status for the ADC ASC0 
 *
 * @return 1 if interrupt flag is set, 0 if not
 */
RAMFUNC_ADC static  int pac5xxx_adc_int_as0() { return (PAC5XXX_ADC->ADCINT.AS0INT & PAC5XXX_ADC->ADCINT.AS0INT_EN); }

/**
 * @brief  This function clears the interrupt flag and sets the interrupt state for the unit
 *
 * @param  enable If set to a 1, enables the interrupt. If set to 0, disables the interrupt
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_enable_as1(int enable) { PAC5XXX_ADC->ADCINT.AS1INT_EN = enable; }

/**
 * @brief  This function clears the interrupt flag for the ASC1 unit
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_clear_as1() { PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_AS1INT); }
/**
 *  @brief This function returns the interrupt flag status for the ADC ASC1
 *
 * @return 1 if interrupt flag is set, 0 if not
 */
RAMFUNC_ADC static  int pac5xxx_adc_int_as1() { return (PAC5XXX_ADC->ADCINT.AS1INT & PAC5XXX_ADC->ADCINT.AS1INT_EN); }

/**
 * @brief  This function clears the interrupt flag and sets the interrupt state for the ASC
 *
 * @param  enable If set to a 1, enables the interrupt. If set to 0, disables the interrupt
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_enable_asc(int enable) { PAC5XXX_ADC->ADCINT.ASCINT_EN = enable; }

/**
 * @brief  This function clears the interrupt flag for the ASC unit
 *
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_int_clear_asc() { PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_ASCINT); }

/**
 *  @brief This function returns the interrupt flag status for the ADC ASC
 *
 * @return 1 if interrupt flag is set, 0 if not
 */
RAMFUNC_ADC static  int pac5xxx_adc_int_asc() { return (PAC5XXX_ADC->ADCINT.ASCINT & PAC5XXX_ADC->ADCINT.ASCINT_EN); }


//
// AUTOMATED SAMPLING CONTROL SUPPORT
//

/**
 * @brief  This function configures the ASC0 unit for use non-trigger auto sequences
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_as0_config(ADCCTLX_SDEPTH_Type sample_depth) { PAC5XXX_ADC->ASCTL0.AS0D = sample_depth; PAC5XXX_ADC->ASCTL0.AS0SEQEN = 1; }

/**
 * @brief  This function configures the ASC1 unit for use non-trigger auto sequences
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @return none
 */
RAMFUNC_ADC static  void pac5xxx_adc_as1_config(ADCCTLX_SDEPTH_Type sample_depth) { PAC5XXX_ADC->ASCTL1.AS1D = sample_depth;  PAC5XXX_ADC->ASCTL1.AS1SEQEN = 1; }

/**
 * @brief  This function configures the ASC0 unit for use with a timer trigger
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @param trig_timer_source The trigger source for the sequence when configure for Timer, from \a ADCCTLX_TRIGTIMER_Type
 * @return none
 */
RAMFUNC_ADC void pac5xxx_adc_as0_config_timer(ADCCTLX_SDEPTH_Type sample_depth,
						                                 ADCCTLX_TRIGTIMER_Type trig_timer_source);

/**
 * @brief  This function configures the ASC0 unit for use with a PWM trigger
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @param trig_edge The trigger edge for the sequence from \a ADCCTLX_TRIGEDGE_Type
 * @param trig_pwm_source The trigger source for the sequence when configured for PWM, from \a ADCCTLX_TRIGPWM_Type
 * @return none
 */
RAMFUNC_ADC void pac5xxx_adc_as0_config_pwm(ADCCTLX_SDEPTH_Type sample_depth,
						                               ADCCTLX_TRIGEDGE_Type trig_edge, 
                                           ADCCTLX_TRIGPWM_Type trig_pwm_source);

/**
 * @brief  This function configures the ASC1 unit for use with a timer trigger
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @param trig_timer_source The trigger source for the sequence when configure for Timer, from \a ADCCTLX_TRIGTIMER_Type
 * @return none
 */
RAMFUNC_ADC void pac5xxx_adc_as1_config_timer(ADCCTLX_SDEPTH_Type sample_depth,
						                                 ADCCTLX_TRIGTIMER_Type trig_timer_source);

/**
 * @brief  This function configures the ASC1 unit for use with a PWM trigger
 *
 * @param sample_depth The sample depth from \a ADCCTLX_SDEPTH_Type
 * @param trig_edge The trigger edge for the sequence from \a ADCCTLX_TRIGEDGE_Type
 * @param trig_pwm_source The trigger source for the sequence when configured for PWM, from \a ADCCTLX_TRIGPWM_Type
 * @return none
 */
RAMFUNC_ADC void pac5xxx_adc_as1_config_pwm(ADCCTLX_SDEPTH_Type sample_depth,
						                               ADCCTLX_TRIGEDGE_Type trig_edge, 
                                           ADCCTLX_TRIGPWM_Type trig_pwm_source);

/**
 * @brief  This function returns the last ASC sequence that ran
 * 
 * @return Sequence ID
 */
RAMFUNC_ADC static  ASCINT_SEQ_Type pac5xxx_adc_asc_last_sequence(void) { return (ASCINT_SEQ_Type)PAC5XXX_ADC->ADCINT.ASCSEQ; }

/**
 * @brief This function returns the last ASC sequence that caused assertion of the ASCINT
 *
 * @return Sequence ID
 */
RAMFUNC_ADC static  ASCINT_SEQ_Type pac5xxx_adc_asc_last_asc_sequence(void) { return (ASCINT_SEQ_Type)PAC5XXX_ADC->ADCINT.ASCTR; }

/**
 * @brief  This function configures the given sequence number for the ASC0 unit
 *
 * @param  seq_num The sequence number to configure
 * @param  mux_select The ADC MUX selection for the sequence from \a ADCCTL_ADMUX_Type
 * @param  emux_control When to change the EMUX from the \a ASSEQ_MSPI_Type
 * @param  emux_data The EMUX data to send for the given sequence
 * @param  seq_delay The delay to apply for the given sequence from \a ADCCTLX_DELAY_Type
 * @return Non-zero if sequence complete
 */
RAMFUNC_ADC void pac5xxx_adc_as0_sequence_config(int seq_num,
									ADCCTL_ADMUX_Type mux_select,
									ASSEQ_MSPI_Type emux_control,
									uint8_t emux_data,
									ASSEQ_DELAY_Type seq_delay);

/**
 * @brief  This function configures the given sequence number for the ASC1 unit
 *
 * @param  seq_num The sequence number to configure
 * @param  mux_select When to change the EMUX from the \a ASSEQ_MSPI_Type
 * @param  emux_control The EMUX control to use for the given sequence from \a ADC_EMUX_CTL_Type
 * @param  emux_data The EMUX data to send for the given sequence
 * @param  seq_delay The delay to apply for the given sequence from \a ADCCTLX_DELAY_Type
 * @return Non-zero if sequence complete
 */
RAMFUNC_ADC void pac5xxx_adc_as1_sequence_config(int seq_num,
									ADCCTL_ADMUX_Type mux_select,
                  ASSEQ_MSPI_Type emux_control,
									uint8_t emux_data,
									ASSEQ_DELAY_Type seq_delay);
						   
/**
 * @brief  This function returns the ADC result for the given sequence number for the ASC0 unit
 *
 * @param  seq_num sequence number
 * @return ADC conversion result for \a seq_num
 */
RAMFUNC_ADC uint16_t pac5xxx_adc_as0_seq_get_result(int seq_num);

/**
 * @brief  This function returns the ADC result for the given sequence number for the ASC1 unit
 *
 * @param  seq_num sequence number
 * @return ADC conversion result for \a seq_num
 */
RAMFUNC_ADC uint16_t pac5xxx_adc_as1_seq_get_result(int seq_num);

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq0_get_result(void) { return PAC5XXX_ADC->AS0R0.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq1_get_result(void) { return PAC5XXX_ADC->AS0R1.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq2_get_result(void) { return PAC5XXX_ADC->AS0R2.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq3_get_result(void) { return PAC5XXX_ADC->AS0R3.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq4_get_result(void) { return PAC5XXX_ADC->AS0R4.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq5_get_result(void) { return PAC5XXX_ADC->AS0R5.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq6_get_result(void) { return PAC5XXX_ADC->AS0R6.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as0_seq7_get_result(void) { return PAC5XXX_ADC->AS0R7.VAL; }


/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq0_get_result(void) { return PAC5XXX_ADC->AS1R0.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq1_get_result(void) { return PAC5XXX_ADC->AS1R1.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq2_get_result(void) { return PAC5XXX_ADC->AS1R2.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq3_get_result(void) { return PAC5XXX_ADC->AS1R3.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq4_get_result(void) { return PAC5XXX_ADC->AS1R4.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq5_get_result(void) { return PAC5XXX_ADC->AS1R5.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq6_get_result(void) { return PAC5XXX_ADC->AS1R6.VAL; }

/**
 *  @brief  This function returns the last converted ADC result for the given series and sequence
 *
 *  @param  n/a
 *  @return ADC conversion result
 */
RAMFUNC_ADC static uint16_t pac5xxx_adc_as1_seq7_get_result(void) { return PAC5XXX_ADC->AS1R7.VAL; }



/*@}*/ /* end of group PAC5XXX_Driver_ADC */

#endif // PAC5XXX_DRIVER_ADC_H
