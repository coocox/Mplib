/**************************************************************************//**
 * @file     pac5xxx_driver_socbridge.h
 * @brief    Firmware driver for the PAC5XXX SOC Bridge
 * @version  v0.2
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

/** @addtogroup PAC5XXX_Driver_SocBridge PAC5XXX SOC Bridge Peripheral
  @{
*/

#ifndef PAC5XXX_DRIVER_SOCBRIDGE_H
#define PAC5XXX_DRIVER_SOCBRIDGE_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"
#include "pac5xxx_driver_gpio.h"

#ifdef PAC5XXX_DRIVER_SOCBRIDGE_RAM
#define RAMFUNC_SOCBRIDGE	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_SOCBRIDGE
#endif

#define SOCBRIDGE_SOFT		// uncomment to peform soc bridge bit-banging

/**
 * @brief  This function configures and enables the SOC bridge
 *
 * @paramn enable Set to 1 to enable SOC Bridge, 0 to disable
 * @param  int_enable Set to 1 to enable interrupts, 0 to disable interrupts
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config(int enable, int int_enable);

/**
 * @brief  This function configures the behavior of the SOC bridge chip select signal
 *
 * @param  cs_setup This value is the minimum number of clock periods to wait from the assertion of the chip select to the first clock transition.
 * @param  cs_hold This value is the minimum number of clock periods to wait from the last clock transition to de-assertion of the chip select signal.
 * @param  cs_wait This value determines the minimum number of clock periods to wait between the de-assertion of the chip select and the re-assertion of the chip select signal.
 * @return none
 *
 */											
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config_chip_select(uint8_t cs_setup,
										                  uint8_t cs_hold,
										                  uint8_t cs_wait);
/**
 * @brief  This function resets the SOC Bridge module
 *
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_reset(void) { PAC5XXX_SOCBRIDGE->SOCBCFG.MRST = 1; }

/**
 * @brief  This function configures the IO ports on the device for SOC bridge operation
 *
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config_io(void);

///
/// Interrupts and status
///

/**
 * @brief  This function configures SOC Bridge interrupts to the given state
 *
 * @param  enable When set to 1, enables interrupts. When set to 0, disables interrupts.
 * @return none
 *
 * @note This function must be used to enable any interrupts. This must be used in conjunction with another function that enables specific interrupts.
 *       This function does not enable interrupts in the Cortex NVIC. That must be done explictly using the 
 *       CMSIS API functions for the NVIC.
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_int_enable(int enable);

/**
 * @brief  This function configures the state of the Read Buffer Overflow (RDOFL) interrupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_socbridge_int_enable() function to enable this interrupt.
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_int_enable_RDOFL(int enable);

/**
 * @brief  This function configures the state of the Cycle Done (CYC_DONE) interrupt.
 *
 * @param  enable When set to 1, enables this interrupt. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_socbridge_int_enable() function to enable this interrupt.
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_int_enable_CYC_DONE(int enable);

/**
 * @brief  This function configures the state of the Write Buffer Underflow (WRUFL) interupt. 
 *
 * @param  enable When set to 1, enables this interrupts. When set to 0, disables this interrupt.
 * @return none
 *
 * @note This function must be used in conjunction with the \a pac5xxx_socbridge_int_enable() function to enable this interrupt.
 */
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_int_enable_WRUFL(int enable);

/**
 * @brief  This function indicates if the Read Buffer Overflow (RDOFL) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SPI Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */

RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_stat_RDOFL(void)	{ return PAC5XXX_SOCBRIDGE->SOCBSTAT.RDOFL; }

/**
 * @brief  This function indicates if the Cycle Done (CYC_DONE) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SOC Bridge Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SOCBRIDGE static  int pac5xxx_socbridge_stat_CYC_DONE(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE; }

/**
 * @brief  This function indicates if the Write Buffer Underflow (WRUFL) condition has happened.
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 * @note SOC BridgeB Status bits are write to clear, so calling this function will not clear this status bit. To clear the bit, use the explicit clear function below.
 */
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_stat_WRUFL(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.WRUFL; }

/**
 * @brief  This function indicates that the outgoing register is still in use (TXFULL).
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 */
#ifndef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_stat_TXFULL(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.TXFULL; }
#else
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_stat_TXFULL(void) { return 0; }
#endif


/**
 * @brief  This function indicates that the incoming holding register is full (RXFULL).
 *
 * @return Non-zero if the condition is set, 0 if not set.
 *
 */
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_stat_RXFULL(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.RXFULL; }

/**
 * @brief  This function returns the SOC Bridge state machine state
 *
 * @return SOC Bridge State Machine state.
 *
 */
RAMFUNC_SOCBRIDGE static SocBridge_State_Type pac5xxx_socbridge_state(void) { return (SPISTAT_State_Type)PAC5XXX_SOCBRIDGE->SOCBSTAT.CURSTATE; }

/**
 * @brief  This function indicates if any SPI interrupt flag is set.
 *
 * @return Non-zero if for any SPI interrupt flag, 0 if no interrupt flags are active
 *
 */
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_int_flag(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.SOCB_INT; }

/**
 * @brief  This function clears the Read Overflow interrupt flag (RDOFL), if set.
 *
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_int_clear_RDOFL(void) { PAC5XXX_SOCBRIDGE->SOCBSTAT.RDOFL = 1; }


/**
 * @brief  This function clears the Cycle Done interrupt flag (CYC_DONE), if set.
 *
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_int_clear_CYC_DONE(void) { PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE = 1; }

/**
 * @brief  This function clears the Write Buffer Underflow interrupt flag (WRUFL), if set.
 *
 * @return none
 *
 */
RAMFUNC_SOCBRIDGE static  void pac5xxx_socbridge_int_clear_WRUFL(void) { PAC5XXX_SOCBRIDGE->SOCBSTAT.WRUFL = 1; }

///
/// SOC Bridge Data
///

/**
 * @brief  This function writes 8b of data to the SOC Bridge
 *
 * @param  data Data to write
 * @return none
 */

#ifdef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_data_write_8b(uint8_t data);
#else
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_data_write_8b(uint8_t data) { PAC5XXX_SOCBRIDGE->SOCBD.b = data; }
#endif

/**
 * @brief  This function reads 8b of data from the SOC Bridge receive register
 * @param  Data to write on MOSI during read operation
 *
 * @return Data read from the receive register
 */
#ifdef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE uint8_t pac5xxx_socbridge_data_read_8b(uint8_t tx_data);
#else
RAMFUNC_SOCBRIDGE uint8_t pac5xxx_socbridge_data_read_8b(uint8_t tx_data);
#endif

/**
 * @brief  This function indicates if the SOC Bridge character has completed transmission, and the receive register is full
 *
 * @return 0 if the data is still being sent, 1 if the data has been sent and the receive data is available
 */

#ifdef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_character_sent(void) { return 1; }
#else
RAMFUNC_SOCBRIDGE static int pac5xxx_socbridge_character_sent(void) { return PAC5XXX_SOCBRIDGE->SOCBSTAT.RXFULL; }
#endif

/**
 * @brief  This function asserts the chip select
 *
 * @return none
 */

#ifndef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_assert_cs(void) { ; }
#else
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_assert_cs(void) { PAC5XXX_GPIOB->OUT.b &= ~0x02; }
#endif


/**
 * @brief  This function de-asserts the chip select after a series of characters has been sent over the SOC bridge
 *
 * @return none
 */
#ifndef SOCBRIDGE_SOFT
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_deassert_cs(void) { PAC5XXX_SOCBRIDGE->SOCBCTL.b |= 0x20; }
#else
RAMFUNC_SOCBRIDGE static void pac5xxx_socbridge_deassert_cs(void) { PAC5XXX_GPIOB->OUT.b |= 0x02; }
#endif

/*@}*/ /* end of group PAC5XXX_Driver_SocBridge */

#endif // PAC5XXX_DRIVER_SOCBRIDGE_H

