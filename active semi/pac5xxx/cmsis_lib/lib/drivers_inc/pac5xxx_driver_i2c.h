/**************************************************************************//**
 * @file     pac5xxx_driver_i2c.h
 * @brief    Firmware driver for the PAC5XXX I2C Peripheral
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

/** @addtogroup PAC5XXX_Driver_I2C PAC5XXX I2C Peripheral
  @{
*/

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifndef PAC5XXX_DRIVER_I2C_H
#define PAC5XXX_DRIVER_I2C_H

#ifdef PAC5XXX_DRIVER_I2C_RAM
#define RAMFUNC_I2C	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_I2C
#endif

// Function Prototypes for support functions

///
/// Master Configuration
///

/**
 * @brief  This function configures I2C peripheral for master mode
 *
 * @param  addr_type The type of addressing used (7b or 10b)
 * @param  disable_pulse_filter When set to 1, disables the pulse filter. When set to 0 the pulse filter is active.
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_master_config(I2C_AddrMode_Type addr_type, int disable_pulse_filter);

/**
 * @brief  This function configures the IO for use with the I2C peripheral
 *
 * @param  master Set to 1 if this is an I2C master, 0 for I2C slave
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_io_config(int master);
/**
 * @brief  This function sets the I2C baud rate when configured for master mode
 *
 * @param  scl_high_clocks The number of clock periods that the SCL will stay high when mastering the bus
 * @param  scl_low_clocks The number of clock periods that the SCL will stay low when mastering the bus
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_set_baud(int scl_low_clocks, int scl_high_clocks);

/**
 * @brief  This function sets the I2C address to use when configured for master mode
 *
 * @param  addr The 7b I2C address when configured for 7b addressing mode. The least-significant 7b of the address when configured for 10b addressing mode.
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_set_addr(uint8_t addr) { PAC5XXX_I2C->MCTRL.LOWER_I2C_ADDR = addr; }

/**
 * @brief  This function sets the upper 3 bits of the I2C address to use when configured for master mode for 10b addressing
 *
 * @param  addr The upper 3b of the address
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_set_addr_ext(uint8_t addr) { PAC5XXX_I2C->MCTRL.UPPER_I2C_ADDR = addr; }

/**
 * @brief  This function configures the I2C bus to issue an I2C STOP condition after the next data byte is sent, when in master mode.
 *
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_issue_stop(void) { PAC5XXX_I2C->MCTRL.AUTONO_XFER = 1; }

/**
 * @brief  This function configures the I2C bus to not issue an I2C STOP condition after the next data byte is sent, when in master mode.
 *
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_clear_stop(void) { PAC5XXX_I2C->MCTRL.AUTONO_XFER = 0; }

/**
 * @brief  This function configures the transfer type for the I2C bus, when in master mode.
 *
 * @param transfer_type The transfer type (read or write)
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_xfer_type(I2C_TransferType_Type transfer_type) { PAC5XXX_I2C->MCTRL.XFER_TYPE = transfer_type; }

/**
 * @brief  This function indicates whether or not the MCTRL register has been written from the I2C bus controller, since it was last read.
 *
 * @return Non-zero if the MCTRL register has been written since last read, 0 if not.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_master_MCTRL_reg_full(void) { return PAC5XXX_I2C->MCTRL.REG_FULL_FLAG; }

/**
 * @brief  This function indicates whether or not the MRXDATA register has been written from the I2C Controller, since it was last read.
 *
 * @return Non-zero if the register has been written since last read, 0 if not.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_master_rx_reg_full(void) { return PAC5XXX_I2C->MRXDATA.REG_FULL_FLAG; }

/**
 * @brief  This function returns the last data read from the I2C controller, when in master mode.
 *
 * @return Last 7b data read from bus.
 * @note This function does not check to see if the data in the RX register is valid, it just returns the last data read from the bus when in master mode.
 *
 */
RAMFUNC_I2C static  unsigned char pac5xxx_i2c_master_rx_data(void) { return PAC5XXX_I2C->MRXDATA.VAL; }

/**
 * @brief  This function indicates whether or not the MTXDATA register has been read from the I2C controller, since it was written.
 *
 * @return Non-zero if the register has been read from the controller, 0 if not.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_master_tx_reg_full(void) { return PAC5XXX_I2C->MTXDATA.REG_FULL_FLAG; }

/**
 * @brief  This function indicates whether or not the last byte of the I2C transaction has been received, when in master mode.
 *
 * @return Non-zero if the last byte has been received, 0 if not.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_master_tx_last_byte_read(void) { return PAC5XXX_I2C->MTXDATA.LAST_BYTE_FLAG; }

/**
 * @brief  This function writes 8b of data from the given character to the I2C bus, when in master mode
 *
 * @param data 8b data to write to the bus
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_master_tx_data(uint8_t data) { PAC5XXX_I2C->MTXDATA.VAL = data; }

/**
 * @brief  This function writes multiple bytes of data to the I2C slave
 *
 * @param data Pointer to data to write to the bus
 * @param num_bytes Number of bytes to write
 * @return 0: success; non-zero: failure
 *
 */
RAMFUNC_I2C int pac5xxx_i2c_master_write(uint8_t *data, int num_bytes);

/**
 * @brief  This function performs and I2C read to the slave by writing a set of bytes, then reading the
 *         given number of bytes back from the slave.
 *
 * @param  write_data Pointer to data to write
 * @param  bytes_to_write Number of bytes to write
 * @param  read_data Pointer to storage for data read from I2C bus
 * @param  Number of bytes to read
 * @return 0: Success; non-zero: failure
 *
 */
RAMFUNC_I2C int act02_i2c_master_read(uint8_t *write_data, int bytes_to_write, uint8_t *read_data, int bytes_to_read);


//
// Slave Configuration
//

/**
 * @brief  This function configures the I2C bus for slave mode
 *
 * @param addr_type The address type (7b or 10b)
 * @param disable_pulse_filter When set to 1, disables the pulse filter. When set to 0, the pulse filter is active.
 * @return Non-zero if the last byte has been received, 0 if not.
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_slave_config(I2C_AddrMode_Type addr_type, int disable_pulse_filter);

/**
 * @brief  This function sets the I2C slave address, when in slave mode
 *
 * @param addr The 7b slave address when in 7b address mode, or the least-significant 7b of the address when in 10b address mode
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_slave_set_addr(uint8_t addr) { PAC5XXX_I2C->SADDR.SADDR_LSB = addr; }

/**
 * @brief  This function sets the most-significant 3b of the I2C slave address, when in slave mode for 10b addressing
 *
 * @param addr The upper 3b of the address for 10b address mode
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_slave_set_addr_ext(uint8_t addr) { PAC5XXX_I2C->SADDR.SADDR_MSB = addr; }

/**
 * @brief  This function returns the last data read from the I2C bus, when in slave mode
 *
 * @return The last data read from the I2C bus, when in slave mode
 * @note This function does not check if the data is valid, it only returns the contents of the data register from the I2C controller
 *
 */
RAMFUNC_I2C static  uint8_t pac5xxx_i2c_slave_rx_data(void) { return PAC5XXX_I2C->SRXDATA.VAL; }

/**
 * @brief  This function indicates whether or not the SRXDATA register has been written from the I2C controller since last read, when in slave mode
 *
 * @return Non-zero if the SRXDATA register has been written from the I2C controller since last read, 0 if not
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_slave_rx_reg_full(void) { return PAC5XXX_I2C->SRXDATA.REG_FULL_FLAG; }

/**
 * @brief  This function transmits data to the bus for I2C read operations, when in slave mode
 *
 * @param data The 8b data character to send to the bus
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_slave_tx_data(uint8_t data) { PAC5XXX_I2C->STXDATA.VAL = data; }

/**
 * @brief  This function indicates whether or not the STXDATA register has been read from the I2C controller since last written, when in slave mode.
 *
 * @return Non-zero if the register has been read from the I2C controller, 0 if not.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_slave_tx_reg_full(void) { return PAC5XXX_I2C->STXDATA.REG_FULL_FLAG; }

/**
 * @brief  This function configures the I2C controller to issue a NACK after the next byte, when in slave mode
 *
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_slave_issue_nack(void) { PAC5XXX_I2C->STXDATA.NACK = 1; }

/**
 * @brief  This function configures the I2C controller to not issue a NACK after the next byte, when in slave mode
 *
 * @return none
 *
 */
RAMFUNC_I2C static  void pac5xxx_i2c_slave_clear_nack(void) { PAC5XXX_I2C->STXDATA.NACK = 0; }

//
// MISC Configuration
//

/**
 * @brief  This function disables the I2C bus controller
 *
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_disable(void);

//
// Interrupt Support
//

// Interrupt Enable

/**
 * @brief  This function enables or disables the MST_TX_EMPTIED interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_TX_EMPTIED(int enable);

/**
 * @brief  This function enables or disables the MST_ACC_CTL_EMP interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_ACC_CTL_EMP(int enable);

/**
 * @brief  This function enables or disables the MST_RX_FILLED interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_RX_FILLED(int enable);

/**
 * @brief  This function enables or disables the MST_XFER_DONE interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_XFER_DONE(int enable);

/**
 * @brief  This function enables or disables the MST_A_NACK_ACK interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_A_NACK_ACK(int enable);

/**
 * @brief  This function enables or disables the MST_LOST_ARB interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_LOST_ARB(int enable);

/**
 * @brief  This function enables or disables the MST_D_NACK_ACK interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_D_NACK_ACK(int enable);

/**
 * @brief  This function enables or disables the SLV_ADDR_MATCH interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_ADDR_MATCH(int enable);

/**
 * @brief  This function enables or disables the SLV_TX_EMPTIED interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_TX_EMPTIED(int enable);

/**
 * @brief  This function enables or disables the SLV_RX_FILLED interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_RX_FILLED(int enable);

/**
 * @brief  This function enables or disables the SLV_XFER_DONE interrupt.
 *
 * @param enable Set to 1 to enable interrupt, 0 to disable
 * @return none
 *
 */
RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_XFER_DONE(int enable);

// Interrupt Status (read to clear)

/**
 * @brief  This function indicates whether or not the MST_TX_EMPTIED status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_TX_EMPTIED(void) { return PAC5XXX_I2C->STATUS.MST_TX_EMPTIED; }

/**
 * @brief  This function indicates whether or not the MST_ACC_CTL_EMP status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_ACC_CTL_EMP(void) { return PAC5XXX_I2C->STATUS.MST_ACC_CTL_EMP; }

/**
 * @brief  This function indicates whether or not the MST_RX_FILLED status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_RX_FILLED(void) { return PAC5XXX_I2C->STATUS.MST_RX_FILLED; }

/**
 * @brief  This function indicates whether or not the MST_XFER_DONE status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_XFER_DONE(void) { return PAC5XXX_I2C->STATUS.MST_XFER_DONE; }

/**
 * @brief  This function indicates whether or not the MST_A_NACK_ACK status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_A_NACK_ACK(void) { return PAC5XXX_I2C->STATUS.MST_A_NACK_ACK; }

/**
 * @brief  This function indicates whether or not the MST_LOST_ARB status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_LOST_ARB(void) { return PAC5XXX_I2C->STATUS.MST_LOST_ARB; }

/**
 * @brief  This function indicates whether or not the MST_D_NACK_ACK status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_MST_D_NACK_ACK(void) { return PAC5XXX_I2C->STATUS.MST_D_NACK_ACK; }

/**
 * @brief  This function indicates whether or not the SLV_ADDR_MATCH status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_SLV_ADDR_MATCH(void) { return PAC5XXX_I2C->STATUS.SLV_ADDR_MATCH; }

/**
 * @brief  This function indicates whether or not the SLV_TX_EMPTIED status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_SLV_TX_EMPTIED(void) { return PAC5XXX_I2C->STATUS.SLV_TX_EMPTIED; }

/**
 * @brief  This function indicates whether or not the SLV_RX_FILLED status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_SLV_RX_FILLED(void) { return PAC5XXX_I2C->STATUS.SLV_RX_FILLED; }

/**
 * @brief  This function indicates whether or not the SLV_XFER_DONE status condition is set.
 *
 * @return Non-zero if set, 0 if clear.
 * @note If this bit is read as set, it will clear on read.
 *
 */
RAMFUNC_I2C static  int pac5xxx_i2c_int_SLV_XFER_DONE(void) { return PAC5XXX_I2C->STATUS.SLV_XFER_DONE; }


/*@}*/ /* end of group PAC5XXX_Driver_I2C */

#endif // PAC5XXX_DRIVER_I2C_H

