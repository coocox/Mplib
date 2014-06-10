/**************************************************************************//**
 * @file     pac5xxx_driver_spi.h
 * @brief    Firmware driver for the PAC5XXX SPI Peripheral
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

/** @addtogroup PAC5XXX_Driver_SPI PAC5XXX SPI Peripheral
  @{
*/

#ifndef PAC5XXX_DRIVER_SPI_H
#define PAC5XXX_DRIVER_SPI_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_SPI_RAM
#define RAMFUNC_SPI	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_SPI
#endif

// Function Prototypes for support functions

///
/// Master Configuration
///

/**
 * @brief  This function configures the SPI peripheral for master mode
 *
 * @param  int_enable Set to 1 to enable SPI interrupts, 0 to disable SPI interrupts
 * @param  loopback Set to 1 to enable SPI loopback mode, 0 to disable
 * @param  mtrans Set to 1 to enable multiple transfer mode (over single assertions of SPICS<n>), 0 to disable
 * @param  mtrans_rearm Set to 1 to re-arm the multiple transfer operation upon de-assertion of SPICS<n>, 0 to disable
 * @param  single_master Set to 1 to enable single-master mode, 0 for single master mode
 * @param  rtrans Set to 1 to auto-retransmit on SCLK error, 0 to disable this function
 * @return none
 *
 * @note This function only configures the SPI peripheral, it does not enable the peripheral.
 *
 */
RAMFUNC_SPI void pac5xxx_SPI_master_config(int int_enable,
									       int loopback,
							               int mtrans,
							               int mtrans_rearm,
							               int single_master,
							               int rtrans);
					
/**
 * @brief  This function configures additional parameters for the SPI for master mode operation.
 *
 * @param  wl_select The word transmission length
 * @param  reset Set to 1 to reset the SPI module
 * @param  lsb_first Set to 1 to configure LSB bit-ordering, set to 0 to configure MSB bit-ordering
 * @param  clock_polarity The SPICLK polarity configuration
 * @param  clock_phase The clock phase for data sampling (setup/sample or sample/setup for first and second edges)
 * @param  xmit_data_phase Configures normal or data transitions that are 1/2 cycle early
 * @return none
 *
 * @note This function only configures the extended SPI functions, it does not enable the SPI module.
 */
RAMFUNC_SPI void pac5xxx_spi_master_config2(SPISCFG_WordLength_Type wl_select,
							                int reset,
							                int lsb_first,
							                SPISCFG_ClockPolarity_Type clock_polarity,
							                SPISCFG_ClockPhase_Type clock_phase,
							                SPICFG_EarlyXmitDataPhase_Type xmit_data_phase);

/**
 * @brief  This function re-arms the multiple transfer machine.
 *
 * @return none
 */
RAMFUNC_SPI static  void pac5xxx_spi_master_rearm_mtrans(void) { PAC5XXX_SPI->SPICTL.MTRARM = 1; }


/**
 * @brief  This function configures the behavior of the SPI chip select signals, when configured for master mode
 *
 * @param  cs_num The number of the chip select output to assert during the transactions (0 to n)
 * @param  cs_polarity The polarity of the chip select signal
 * @param  cs_setup This value is the minimum number of SPICLK (Baud) periods to wait from the assertion of SPICS<n> to the first SPICLK transition.
 * @param  cs_hold This value is the minimum number of SPICLK (Baud) periods to wait from the last SPICLK transition to de-assertion of SPICS<n>.
 * @param  cs_wait This value determines the minimum number of SPICLK (Baud) periods to wait between the de-assertion of SPICS<n> and the re-assertion of SPICS<n>.
 * @param  spi_clock_wait If multiple transfer mode is active, this value determines the minimum number of SPICLK (Baud) periods to wait between back-to-back transfers. During this wait time, SPICLK does not toggle, but SPICS<n> remains active.
 * @return none
 *
 */											
RAMFUNC_SPI void pac5xxx_spi_master_config_chip_select(SPICS_ChipSelectNumber_Type cs_num,
										               SPICS_ChipSelectPolarity_Type cs_polarity,
										               uint8_t cs_setup,
										               uint8_t cs_hold,
										               uint8_t cs_wait,
										               uint8_t spi_clock_wait);

/**
 * @brief  This function sets the SPI Chip Select output to the given value (0 to n)
 *
 * @param  cs_num The chip select output to select (SPICS<n> - 0 to n)
 * @return none
 */ 
RAMFUNC_SPI static void pac5xxx_spi_master_chip_select_enable(int cs_num) { PAC5XXX_SPI->SPICCSTR.CSNUM = cs_num; }

///
/// Slave Configuration
///

/**
 * @brief  This function configures the SPI peripheral for slave mode
 *
 * @param  int_enable Set to 1 to enable SPI interrupts, 0 to disable SPI interrupts
 * @param  loopback Set to 1 to enable SPI loopback mode, 0 to disable
 * @return none
 *
 * @note This function only configures the SPI peripheral, it does not enable the peripheral.
 *
 */
RAMFUNC_SPI void pac5xxx_spi_slave_config(int int_enable,
                                          int loopback);

/**
 * @brief  This function configures additional parameters for the SPI for slave mode operation.
 *
 * @param  wl_select The word transmission length
 * @param  reset Set to 1 to reset the SPI module
 * @param  lsb_first Set to 1 to configure LSB bit-ordering, set to 0 to configure MSB bit-ordering
 * @param  clock_polarity The SPISCLK polarity configuration
 * @param  clock_phase The clock phase for data sampling (setup/sample or sample/setup for first and second edges)
 * @param  xmit_data_phase Configures normal or data transitions that are 1/2 cycle early
 * @return none
 *
 * @note This function only configures the extended SPI functions, it does not enable the SPI module.
 */							
RAMFUNC_SPI void pac5xxx_spi_slave_config2(SPISCFG_WordLength_Type wl_select,
							               int reset,
							               int lsb_first,
							               SPISCFG_ClockPolarity_Type clock_polarity,
							               SPISCFG_ClockPhase_Type clock_phase,
							               SPICFG_EarlyXmitDataPhase_Type xmit_data_phase);

		 
/**
 * @brief  This function configures the behavior of the SPI chip select signals, when configured for slave mode
 *
 * @param  cs_num The number of the chip select output to assert during the transactions (0 to n)
 * @param  chip_select_polarity The polarity of the chip select signal
 * @return none
 *
 */											
RAMFUNC_SPI void pac5xxx_spi_slave_config_chip_select(SPICS_ChipSelectNumber_Type cs_num,
										              SPICS_ChipSelectPolarity_Type chip_select_polarity);

///
/// Misc Configuration
///

/**
 * @brief  This function sets the enable state of the SPI module to the given state
 *
 * @param  enable Set to 1 to enable, 0 to disable
 * @return none
 *
 */
RAMFUNC_SPI static  void pac5xxx_spi_enable(int enable) { PAC5XXX_SPI->SPICTL.SSEN = enable; }

/**
 * @brief  This function resets the SPI module
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_reset(void) { PAC5XXX_SPI->SPICFG.MRST = 1; }

/**
 * @brief  This function configures the SPI module loopback mode into the given state
 *
 * @param  enable Set to 1 to enable loopback mode, 0 to select normal operation
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_loopback(int enable) { PAC5XXX_SPI->SPICTL.LPBK = enable; }

/**
 * @brief  This function configures the SPI clock divider
 *
 * @param  divider The divider to apply to the SPI module clock input to use for the SPICLK signal
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_clock_divider(uint16_t divider) { PAC5XXX_SPI->SPICLKDIV.VAL = divider; }

/**
 * @brief  This function configures the IO ports on the device for SPI master or slave operation
 *
 * @param  master Set to 1 for SPI master, set to 0 for SPI slave
 * @param  cs_mask Chip select bit-mask (bit 0: SPICS0; bit1: SPICS1; bit2: SPICS2)
 * @return none
 *
 */
RAMFUNC_SPI void pac5xxx_spi_config_io(int master, unsigned char cs_mask);

///
/// Interrupts and status
///

/**
 * @brief  This function configures SPI interrupts to the given state
 *
 * @param  enable When set to 1, enables SPI interrupts. When set to 0, disables SPI interrupts.
 * @return none
 *
 * @note This function must be used to enable any SPI interrupts. This must be used in conjunction with another function that enables specific SPI interrupts.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable(int enable);

/**
 * @brief  This function configures the state of the Read Buffer Overflow (RDOFL) interrupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_RDOFL(int enable);

/**
 * @brief  This function configures the state of the Chip Select Leading Edge Detect (LE) interupt. 
 *
 * @param  pSpi Pointer to the SPI registers for the desired instance of the SPI peripheral (can be more than one)
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 *
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_LE(int enable);

/**
 * @brief  This function configures the state of the Underclock Condition (UCLK) interupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_UCLK(int enable);

/**
 * @brief  This function configures the state of the Cycle Done (CYC_DONE) interrupt.
 *
 * @param  enable When set to 1, enables this interrupt. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_CYC_DONE(int enable);

/**
 * @brief  This function configures the state of the Chip Select Trailing Edge Detect (TE) interupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_TE(int enable);

/**
 * @brief  This function configures the state of the Write Buffer Underflow (WRUFL) interupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_spi_int_enable() function to enable this interrupt.
 */
RAMFUNC_SPI void pac5xxx_spi_int_enable_WRUFL(int enable);

/**
 * @brief  This function indicates if the Read Buffer Overflow (RDOFL) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_RDOFL(void) { return PAC5XXX_SPI->SPISTAT.RDOFL; }

/**
 * @brief  This function indicates if the Chip Select Leading Edge Detect (LE) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_LE(void) { return PAC5XXX_SPI->SPISTAT.LE; }

/**
 * @brief  This function indicates if the Underclock Condition (UCLK) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_UCLK(void) { return PAC5XXX_SPI->SPISTAT.UCLK; }

/**
 * @brief  This function indicates if the Cycle Done (CYC_DONE) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static  int pac5xxx_spi_stat_CYC_DONE(void) { return PAC5XXX_SPI->SPISTAT.CYC_DONE; }

/**
 * @brief  This function indicates if the Chip Select Trailing Edge Detect (TE) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_TE(void) { return PAC5XXX_SPI->SPISTAT.TE; }

/**
 * @brief  This function indicates if the Write Buffer Underflow (WRUFL) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_WRUFL(void) { return PAC5XXX_SPI->SPISTAT.WRUFL; }

/**
 * @brief  This function indicates that the outgoing register is still in use (TXFULL).
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_TXFULL(void) { return PAC5XXX_SPI->SPISTAT.TXFULL; }

/**
 * @brief  This function indicates that the incoming holding register is full (RXFULL).
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 */
RAMFUNC_SPI static int pac5xxx_spi_stat_RXFULL(void) { return PAC5XXX_SPI->SPISTAT.RXFULL; }

/**
 * @brief  This function returns the SPI state machine state
 *
 * @return SPI State Machine state.
 *
 */
RAMFUNC_SPI static SPISTAT_State_Type pac5xxx_spi_state(void) { return (SPISTAT_State_Type)PAC5XXX_SPI->SPISTAT.CURSTATE; }

/**
 * @brief  This function indicates if any SPI interrupt flag is set.
 *
 * @return Non-zero if for any SPI interrupt flag, 0 if no interrupt flags are active
 *
 */
RAMFUNC_SPI static int pac5xxx_spi_int_flag(void) { return PAC5XXX_SPI->SPISTAT.SPI_INT; }

/**
 * @brief  This function clears the Read Overflow interrupt flag (RDOFL), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_int_clear_RDOFL(void) { PAC5XXX_SPI->SPISTAT.RDOFL = 1; }

/**
 * @brief  This function clears the Chip Select Leading Edge Detect interrupt flag (LE), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_int_clear_LE(void) { PAC5XXX_SPI->SPISTAT.LE = 1; }

/**
 * @brief  This function clears the Underclock Condition interrupt flag (UCLK), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_int_clear_UCLK(void) { PAC5XXX_SPI->SPISTAT.UCLK = 1; }

/**
 * @brief  This function clears the Cycle Done interrupt flag (CYC_DONE), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_int_clear_CYC_DONE(void) { PAC5XXX_SPI->SPISTAT.CYC_DONE = 1; }

/**
 * @brief  This function clears the Chip Select Trailing Edge interrupt flag (TE), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static void pac5xxx_spi_int_clear_TE(void) { PAC5XXX_SPI->SPISTAT.TE = 1; }

/**
 * @brief  This function clears the Write Buffer Underflow interrupt flag (WRUFL), if set.
 *
 * @return none
 *
 */
RAMFUNC_SPI static  void pac5xxx_spi_int_clear_WRUFL(void) { PAC5XXX_SPI->SPISTAT.WRUFL = 1; }

///
/// SPI Data
///

/**
 * @brief  This function writes 8b of data to the SPI bus
 *
 * @param  data Data to write
 * @return none
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static void pac5xxx_spi_data_write_8b(uint8_t data) { PAC5XXX_SPI->SPID.b = data; }

/**
 * @brief  This function writes 16b of data to the SPI bus
 *
 * @param  data Data to write
 * @return none
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static void pac5xxx_spi_data_write_16b(uint16_t data) { PAC5XXX_SPI->SPID.s = data; }

/**
 * @brief  This function writes 32b of data to the SPI bus
 *
 * @param  data Data to write
 * @return none
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static void pac5xxx_spi_data_write_32b(uint32_t data) { PAC5XXX_SPI->SPID.w = data; }

/**
 * @brief  This function reads 8b of data from the SPI receive register
 *
 * @return Data read from the receive register
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static uint8_t pac5xxx_spi_data_read_8b(void) { return PAC5XXX_SPI->SPID.b; }

/**
 * @brief  This function reads 16b of data from the SPI receive register
 *
 * @return Data read from the receive register
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static uint16_t pac5xxx_spi_data_read_16b(void) { return PAC5XXX_SPI->SPID.s; }

/**
 * @brief  This function reads 32b of data from the SPI receive register
 *
 * @return Data read from the receive register
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */
RAMFUNC_SPI static uint32_t pac5xxx_spi_data_read_32b(void) { return PAC5XXX_SPI->SPID.w; }

/**
 * @brief  This function indicates if the SPI character has completed transmission, and the receive register is full
 *
 * @return 0 if the data is still being sent, 1 if the data has been sent and the receive data is available
 *
 * @note The SPI peripheral must be configured for the proper data width for this function to work correctly.
 */

RAMFUNC_SPI static int pac5xxx_spi_character_sent(void) { return PAC5XXX_SPI->SPISTAT.RXFULL; }


/*@}*/ /* end of group PAC5XXX_Driver_SPI */

#endif // PAC5XXX_DRIVER_SPI_H

