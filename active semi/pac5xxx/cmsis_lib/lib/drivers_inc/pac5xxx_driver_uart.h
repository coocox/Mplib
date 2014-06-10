/**************************************************************************//**
 * @file     pac5xxx_driver_uart.h
 * @brief    Firmware driver for the PAC5XXX UART
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

/** @addtogroup PAC5XXX_Driver_UART PAC5XXX UART
  @{
*/

#ifndef PAC5XXX_DRIVER_UART_H
#define PAC5XXX_DRIVER_UART_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_UART_RAM
#define RAMFUNC_UART	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_UART
#endif

// Function Prototypes for support functions



///
/// Configuration
///

/**
 * @brief  This function configures IO for use with the UART peripheral
 *
 * @return none
 */ 
RAMFUNC_UART void pac5xxx_uart_io_config(void);

/**
 * @brief  This function configures the UART LCR (Line Control Register)
 *
 * @param  bpc Bits per character
 * @param  stop_bits Number of Stop Bits
 * @param  parity_enabled Set to 1 to enable parity, 0 to disable
 * @param  parity The type of parity to apply, if parity is enabled (even or odd)
 * @param  stick_parity Set to 1 to enable stick parity, 0 to disable
 * @param  break_control Break Control
 * @param  div_latch_access Divisor Latch Access
 * @return none
 *
 */
RAMFUNC_UART void pac5xxx_uart_config_LCR(UART_BitsPerChar_Type bpc,
                            UART_StopBits_Type stop_bits,
							int parity_enabled,
						    UART_Parity_Type parity,
						    int stick_parity,
						    UART_BreakControl_Type break_control,
						    UART_DivLatchAccess_Type div_latch_access);
						  
/**
 * @brief  This function configures the UART MCR (Modem Control Register)
 *
 * @param  DTR_asserted Set to 1 to assert DTR_N, 0 to de-assert
 * @param  RTS_asserted Set to 1 to assert RTS_N, 0 to de-assert
 * @param  BIT1_asserted Set to 1 to assert BIT_OUT1_N, 0 to de-assert
 * @param  BIT2_asserted Set to 1 to assert BIT_OUT2_N, 0 to de-assert
 * @param  loopback_mode Set to 1 to enable loopback mode, 0 to disable
 * @return none
 *
 */						  
RAMFUNC_UART void pac5xxx_uart_config_MCR(int DTR_asserted,
                           int RTS_asserted,
						   int BIT1_asserted,
						   int BIT2_asserted,
						   int loopback_mode);

/**
 * @brief  	This function configures the UART to have access to the divisor latch.
 *
 * @return 	none
 *
 * @note	Users must call this function before calling any other function that accesses the divisor
 *          latch registers.
 *
 */
RAMFUNC_UART static void pac5xxx_uart_div_latch_access(void) { PAC5XXX_UART->LCR.DLAB = 1; }

/**
 * @brief  	This function configures the UART to have access to the UART RX/TX FIFO.
 *
 * @return 	none
 *
 * @note	Users must call this function before calling any other function that accesses the RX or TX FIFO.
 *
 */
RAMFUNC_UART static void pac5xxx_uart_fifo_access(void) { PAC5XXX_UART->LCR.DLAB = 0; }


/**
 * @brief  This function writes a character to the UART Transmit FIFO
 *
 * @param  data Character to send
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_write(uint8_t data) { PAC5XXX_UART->RXTX.VAL = data; }

/**
 * @brief  This function reads the next character from the UART Receive FIFO
 *
 * @return Character read from FIFO
 * @note This function does not check if a character is available in the RX FIFO. It just returns the first character from the FIFO.
 */
RAMFUNC_UART static  uint8_t pac5xxx_uart_read(void) { return (uint8_t)PAC5XXX_UART->RXTX.w; }

/**
 * @brief  This function configures the divisor latch
 *
 * @param  latch_value 16b divisor latch value
 * @return none
 *
 */
RAMFUNC_UART void pac5xxx_uart_config_divisor_latch(uint16_t latch_value);

/**
 * @brief  This function configures the divisor latch using the remapped DL_L2 and DL_H2 registers
 *
 * @param  latch_value 16b divisor latch value
 * @return none
 *
 */
RAMFUNC_UART void pac5xxx_uart_config_divisor_latch_remapped(uint16_t latch_value);

/**
 * @brief  This function configures the Fractional Divisor and UART clock source
 *
 * @param  divisor_value The Divisor Latch value
 * @return none
 *
 */
RAMFUNC_UART void pac5xxx_uart_config_fractional_divisor(uint8_t divisor_value);

///
/// FIFO Operations
///

/**
 * @brief  This function sets the enable state of the UART FIFO to the given value
 *
 * @param  enable If set to 1, enables the FIFO. If set to 0, disables the FIFO.
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_fifo_enable(int enable) { PAC5XXX_UART->FCTL.EN = enable; }

/**
 * @brief  This function sets the enable state of the UART FIFO to the given value using the remapped register (FCTL2).
 *
 * @param  enable If set to 1, enables the FIFO. If set to 0, disables the FIFO.
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_fifo_enable_remapped(int enable) { PAC5XXX_UART->FCTL2.EN = enable; }

 /**
 * @brief  This function resets the Receive FIFO.
 *
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_rx_fifo_reset(void) { PAC5XXX_UART->FCTL.RR = 1; }

/**
 * @brief  This function resets the Receive FIFO using the remapped FCTL2 register.
 *
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_rx_fifo_reset_remapped() { PAC5XXX_UART->FCTL2.RR = 1; }

/**
 * @brief  This function resets the Transmit FIFO.
 *
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_tx_fifo_reset(void) { PAC5XXX_UART->FCTL.TR = 1; }

/**
 * @brief  This function resets the Transmit FIFO using the remapped FCTL2 register.
 *
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_tx_fifo_reset_remapped(void) { PAC5XXX_UART->FCTL2.TR = 1; }

/**
 * @brief  This function configures the Receive FIFO depth.
 *
 * @param depth FIFO depth from \a UART_FIFO_Depth_Type.
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_rx_fifo_threshold(UART_FIFO_Depth_Type depth) { PAC5XXX_UART->FCTL.RT = depth; }

/**
 * @brief  This function configures the Receive FIFO depth using the remapped FCTL2 register.
 *
 * @param depth FIFO depth from \a UART_FIFO_Depth_Type.
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_rx_fifo_threshold_remapped(UART_FIFO_Depth_Type depth) { PAC5XXX_UART->FCTL2.RT = depth; }

///
/// INTERRUPT SUPPORT
///

/**
 * @brief  This function sets the interrupt state for the Receive Data Available (RDAI).
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_RDAI(int enable) { PAC5XXX_UART->IER.RDAI = enable; }

/**
 * @brief  This function sets the interrupt state for the Receive Data Available (RDAI) using the remapped IER2 register.
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_RDAI_remapped(int enable) { PAC5XXX_UART->IER2.RDAI = enable; }

/**
 * @brief  This function sets the interrupt state for the Transmit Holding Register Empty Condition (THREI).
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_THREI(int enable) { PAC5XXX_UART->IER.THREI = enable; }

/**
 * @brief  This function sets the interrupt state for the Transmit Holding Register Empty Condition (THREI) using the remapped IER2 register.
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_THREI_remapped(int enable) { PAC5XXX_UART->IER2.THREI = enable; }

/**
 * @brief  This function sets the interrupt state for the Receive Line Status Condition (RLSI).
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_RLSI(int enable) { PAC5XXX_UART->IER.RLSI = enable; }

/**
 * @brief  This function sets the interrupt state for the Receive Line Status Condition (RLSI) using the remapped IER2 register.
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_RLSI_remapped(int enable) { PAC5XXX_UART->IER2.RLSI = enable; }

/**
 * @brief  This function sets the interrupt state for the Modem Status condition (MSI).
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_MSI(int enable) { PAC5XXX_UART->IER.MSI = enable; }

/**
 * @brief  This function sets the interrupt state for the Modem Status condition (MSI) using the remapped IER2 register.
 *
 * @param enable Set to 1 to enable the interrupt, 0 to disable.
 * @return none
 *
 */
RAMFUNC_UART static void pac5xxx_uart_int_enable_MSI_remapped(int enable) { PAC5XXX_UART->IER2.MSI = enable; }


/**
 * @brief  This function returns the interrupt pending state.
 *
 * @return Non-zero if there is an interrupt pending.
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_int_pending(void) { return (PAC5XXX_UART->IIR.PI); }

/**
 * @brief  This function returns the pending interrupt ID
 *
 * @return Interrupt ID from \a UART_IID_Type
 *
 */
RAMFUNC_UART static  UART_IID_Type pac5xxx_uart_interrupt_id(void) { return (UART_IID_Type)PAC5XXX_UART->IIR.IID; }

// 
// STATUS INDICATORS
//

/**
 * @brief  This function returns the Transmit FIFO enable state
 *
 * @return Non-zero if Transmit FIFO enabled, 0 if disabled
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_tx_fifo_enable(void) { return (PAC5XXX_UART->IIR.TXFEN); }

/**
 * @brief  This function returns the Receive FIFO enable state
 *
 * @return Non-zero if Receive FIFO enabled, 0 if disabled
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_rx_fifo_enable(void) { return (PAC5XXX_UART->IIR.RXFEN); }

/**
 * @brief  This function returns a byte-mask of the Line Status Register (LSR) bits
 *
 * @return Byte-mask of LSR status bits
 *
 */
RAMFUNC_UART static  uint8_t pac5xxx_uart_lsr_status(void) { return PAC5XXX_UART->LSR.b; }

/**
 * @brief  This function returns the state of the Data Ready (DR) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_DR(void) { return PAC5XXX_UART->LSR.DR; }

/**
 * @brief  This function returns the state of the Overrun Error (OE) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_OE(void) { return PAC5XXX_UART->LSR.OE; }

/**
 * @brief  This function returns the state of the Parity Error (PE) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_PE(void) { return PAC5XXX_UART->LSR.PE; }

/**
 * @brief  This function returns the state of the Framing Error (FE) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_FE(void) { return PAC5XXX_UART->LSR.FE; }

/**
 * @brief  This function returns the state of the Break Indicator (BI) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_BI(void) { return PAC5XXX_UART->LSR.BI; }

/**
 * @brief  This function returns the state of the Transmit FIFO Empty (THR) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_THR(void) { return PAC5XXX_UART->LSR.THR; }

/**
 * @brief  This function returns the state of the Transmit Empty (TE) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_TE(void) { return PAC5XXX_UART->LSR.TE; }

/**
 * @brief  This function returns the state of the Receive FIFO Error (RFE) LSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_lsr_RFE(void) { return PAC5XXX_UART->LSR.RFE; }

/**
 * @brief  This function returns a byte-mask of the Modem Status Register (MSR) bits
 *
 * @return Byte-mask of MSR status bits
 *
 */
RAMFUNC_UART static  uint8_t pac5xxx_uart_msr_status(void) { return PAC5XXX_UART->MSR.b; }

/**
 * @brief  This function returns the state of the Delta CTS Detect (DCTS) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_DCTS(void) { return PAC5XXX_UART->MSR.DCTS; }

/**
 * @brief  This function returns the state of the Delta DSR Detect (DDSR) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_DDSR(void) { return PAC5XXX_UART->MSR.DDSR; }

/**
 * @brief  This function returns the state of the Trailing Edge RI Detect (TERI) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_TERI(void) { return PAC5XXX_UART->MSR.TERI; }

/**
 * @brief  This function returns the state of the Delta DCD Detect (DDCD) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_DDCD(void) { return PAC5XXX_UART->MSR.DDCD; }

/**
 * @brief  This function returns the state of the Clear to Send (CTS) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_CTS(void) { return PAC5XXX_UART->MSR.CTS; }

/**
 * @brief  This function returns the state of the Data Set Ready (DSR) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_DSR(void) { return PAC5XXX_UART->MSR.DSR; }

/**
 * @brief  This function returns the state of the Ring Indicator (RI) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_RI(void) { return PAC5XXX_UART->MSR.RI; }

/**
 * @brief  This function returns the state of the Data Carrier Detect (DCD) MSR status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_msr_DCD(void) { return PAC5XXX_UART->MSR.DCD; }

/**
 * @brief  This function returns a byte-mask of the Supplmental Status Register (STAT) bits
 *
 * @return Byte-mask of STAT status bits
 *
 */
RAMFUNC_UART static  uint8_t pac5xxx_uart_s_status(void) { return PAC5XXX_UART->STAT.b; }

/**
 * @brief  This function returns the state of the Transmit FIFO Empty (TXEMPTY) STAT status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_s_status_TXEMPTY(void) { return PAC5XXX_UART->STAT.TXEMPTY; }

/**
 * @brief  This function returns the state of the Transmit FIFO Full (TXFULL) STAT status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_s_status_TXFULL(void) { return PAC5XXX_UART->STAT.TXFULL; }

/**
 * @brief  This function returns the state of the Receive FIFO Empty (RXEMPTY) STAT status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_s_status_RXEMPTY(void) { return PAC5XXX_UART->STAT.RXEMPTY; }

/**
 * @brief  This function returns the state of the Receive FIFO Full (RXFULL) STAT status bit
 *
 * @return Non-zero if set, 0 if clear
 *
 */
RAMFUNC_UART static  int pac5xxx_uart_s_status_RXFULL(void) { return PAC5XXX_UART->STAT.RXFULL; }

///
/// MISC Support
///

/**
 * @brief  This function writes the scratchpad register with the given character
 * @param  data Data character to write
 *
 * @return none
 *
 */
RAMFUNC_UART static  void pac5xxx_uart_scratchpad_write(uint8_t data) { PAC5XXX_UART->SP.VAL = data; }

/**
 * @brief  This function reads a character from the scratchpad register
 *
 * @return Data character from the scratchpad register
 *
 */
RAMFUNC_UART static  uint8_t pac5xxx_uart_scratchpad_read(void) { return PAC5XXX_UART->SP.VAL; }


/*@}*/ /* end of group PAC5XXX_Driver_Uart */

#endif // PAC5XXX_DRIVER_UART_H

