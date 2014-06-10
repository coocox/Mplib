/**************************************************************************//**
 * @file     pac5xxx_driver_gpio.h
 * @brief    Firmware driver for the PAC5XXX GPIO
 * @version  V0.1
 * @date     10 Sep 2011
 *
 * @note
 * Copyright (C) 2011 Active Semiconductor. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

/** @addtogroup PAC5XXX_Driver_GPIO PAC5XXX GPIO Peripheral
  @{
*/

#ifndef PAC5XXX_DRIVER_GPIO_H
#define PAC5XXX_DRIVER_GPIO_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_GPIO_RAM
#define RAMFUNC_GPIO PAC5XXX_RAMFUNC
#else
#define RAMFUNC_GPIO
#endif

// Type enumerations


    
// Function Prototypes for support functions

/**
 * @brief  This function writes the port state of GPIO port A
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output set to logic high.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_a(uint8_t port_mask) { PAC5XXX_GPIOA->OUT.b = port_mask; }

/**
 * @brief  This function writes the port state of GPIO port B
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output set to logic high.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_b(uint8_t port_mask) { PAC5XXX_GPIOB->OUT.b = port_mask; }

/**
 * @brief  This function writes the port state of GPIO port C
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output set to logic high.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_c(uint8_t port_mask) { PAC5XXX_GPIOC->OUT.b = port_mask; }

/**
 * @brief  This function writes the port state of GPIO port D
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output set to logic high.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_d(uint8_t port_mask) { PAC5XXX_GPIOD->OUT.b = port_mask; }

/**
 * @brief  This function writes the port state of GPIO port E
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output set to logic high.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_e(uint8_t port_mask) { PAC5XXX_GPIOE->OUT.b = port_mask; }

/**
 * @brief  This function toggles the selected pins of GPIO port A
 *
 * @param  toggle_mask Mask of port pins to toggle. Each bit that is set to 1 is toggled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_toggle_a(uint8_t toggle_mask) { PAC5XXX_GPIOA->OUT.b ^= toggle_mask; }

/**
 * @brief  This function toggles the selected pins of GPIO port B
 *
 * @param  toggle_mask Mask of port pins to toggle. Each bit that is set to 1 is toggled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_toggle_b(uint8_t toggle_mask) { PAC5XXX_GPIOB->OUT.b ^= toggle_mask; }

/**
 * @brief  This function toggles the selected pins of GPIO port C
 *
 * @param  toggle_mask Mask of port pins to toggle. Each bit that is set to 1 is toggled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_toggle_c(uint8_t toggle_mask) { PAC5XXX_GPIOC->OUT.b ^= toggle_mask; }

/**
 * @brief  This function toggles the selected pins of GPIO port D
 *
 * @param  toggle_mask Mask of port pins to toggle. Each bit that is set to 1 is toggled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_toggle_d(uint8_t toggle_mask) { PAC5XXX_GPIOD->OUT.b ^= toggle_mask; }

/**
 * @brief  This function toggles the selected pins of GPIO port E
 *
 * @param  toggle_mask Mask of port pins to toggle. Each bit that is set to 1 is toggled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_toggle_e(uint8_t toggle_mask) { PAC5XXX_GPIOE->OUT.b ^= toggle_mask; }

/**
 *  @brief	This function sets the given pin for the given port to logic high
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_set_a(int bit_num) { PAC5XXX_GPIOA->OUT.b |= (1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic high
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_set_b(int bit_num) { PAC5XXX_GPIOB->OUT.b |= (1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic high
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_set_c(int bit_num) { PAC5XXX_GPIOC->OUT.b |= (1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic high
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_set_d(int bit_num) { PAC5XXX_GPIOD->OUT.b |= (1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic high
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_set_e(int bit_num) { PAC5XXX_GPIOE->OUT.b |= (1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic low
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_clear_a(int bit_num) { PAC5XXX_GPIOA->OUT.b &= ~(1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic low
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_clear_b(int bit_num) { PAC5XXX_GPIOB->OUT.b &= ~(1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic low
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_clear_c(int bit_num) { PAC5XXX_GPIOC->OUT.b &= ~(1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic low
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_clear_d(int bit_num) { PAC5XXX_GPIOD->OUT.b &= ~(1 << bit_num); }

/**
 *  @brief	This function sets the given pin for the given port to logic low
 *
 *  @param	bit_num The bit number (0-7) to set
 *  @return none
 */
RAMFUNC_GPIO static void pac5xxx_gpio_out_pin_clear_e(int bit_num) { PAC5XXX_GPIOE->OUT.b &= ~(1 << bit_num); }



/**
 * @brief  This function enables the output for the given pins on port A
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output enabled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_enable_a(uint8_t port_mask) { PAC5XXX_GPIOA->OUTEN.b |= port_mask; }

/**
 * @brief  This function enables the output for the given pins on port B
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output enabled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_enable_b(uint8_t port_mask) { PAC5XXX_GPIOB->OUTEN.b |= port_mask; }

/**
 * @brief  This function enables the output for the given pins on port C
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output enabled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_enable_c(uint8_t port_mask) { PAC5XXX_GPIOC->OUTEN.b |= port_mask; }

/**
 * @brief  This function enables the output for the given pins on port D
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output enabled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_enable_d(uint8_t port_mask) { PAC5XXX_GPIOD->OUTEN.b |= port_mask; }

/**
 * @brief  This function enables the output for the given pins on port E
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has that output enabled.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_enable_e(uint8_t port_mask) { PAC5XXX_GPIOE->OUTEN.b |= port_mask; }

/**
 * @brief  This function sets the output drive strength for the given pins on port A
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the drive strength set to 16mA. Bits set to 0
 *                   has the drive strength set to 8mA.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_drive_strength_a(uint8_t port_mask) { PAC5XXX_GPIOA->DS.b |= port_mask; }

/**
 * @brief  This function sets the output drive strength for the given pins on port B
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the drive strength set to 16mA. Bits set to 0
 *                   has the drive strength set to 8mA.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_drive_strength_b(uint8_t port_mask) { PAC5XXX_GPIOB->DS.b |= port_mask; }

/**
 * @brief  This function sets the output drive strength for the given pins on port D
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the drive strength set to 16mA. Bits set to 0
 *                   has the drive strength set to 8mA.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_drive_strength_d(uint8_t port_mask) { PAC5XXX_GPIOD->DS.b |= port_mask; }

/**
 * @brief  This function sets the output drive strength for the given pins on port E
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the drive strength set to 16mA. Bits set to 0
 *                   has the drive strength set to 8mA.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_drive_strength_e(uint8_t port_mask) { PAC5XXX_GPIOE->DS.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-up state for the given pins on port A
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-up enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_up_a(uint8_t port_mask) { PAC5XXX_GPIOA->PU.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-up state for the given pins on port B
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-up enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_up_b(uint8_t port_mask) { PAC5XXX_GPIOB->PU.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-up state for the given pins on port D
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-up enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_up_d(uint8_t port_mask) { PAC5XXX_GPIOD->PU.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-up state for the given pins on port E
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-up enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_up_e(uint8_t port_mask) { PAC5XXX_GPIOE->PU.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-down state for the given pins on port A
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-down enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_down_a(uint8_t port_mask) { PAC5XXX_GPIOA->PD.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-down state for the given pins on port B
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-down enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_down_b(uint8_t port_mask) { PAC5XXX_GPIOB->PD.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-down state for the given pins on port D
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-down enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_down_d(uint8_t port_mask) { PAC5XXX_GPIOD->PD.b |= port_mask; }

/**
 * @brief  This function sets the output weak pull-down state for the given pins on port E
 *
 * @param  port_mask Mask of port pins. Each bit that is set to 1 has the weak pull-down enabled
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_out_pull_down_e(uint8_t port_mask) { PAC5XXX_GPIOE->PD.b |= port_mask; }

/**
 * @brief  This function reads the port state from GPIO port A
 *
 * @return Port state mask from the GPIO port.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_in_a(void) { return PAC5XXX_GPIOA->IN.b; }

/**
 * @brief  This function reads the port state from GPIO port B
 *
 * @return Port state mask from the GPIO port.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_in_b(void) { return PAC5XXX_GPIOB->IN.b; }

/**
 * @brief  This function reads the port state from GPIO port C
 *
 * @return Port state mask from the GPIO port.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_in_c(void) { return PAC5XXX_GPIOC->IN.b; }

/**
 * @brief  This function reads the port state from GPIO port D
 *
 * @return Port state mask from the GPIO port.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_in_d(void) { return PAC5XXX_GPIOD->IN.b; }

/**
 * @brief  This function reads the port state from GPIO port E
 *
 * @return Port state mask from the GPIO port.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_in_e(void) { return PAC5XXX_GPIOE->IN.b; }

/**
 * @brief This function tests the given pin for the given port and returns its state.
 *
 * @param pin Pin number within the given port (0 to 7)
 * @return 0 if pin clear, non-zero if pin set.
 */
RAMFUNC_GPIO static int pac5xxx_gpio_in_pin_a(int pin) { return (PAC5XXX_GPIOA->IN.b & (1 << pin)); }

/**
 * @brief This function tests the given pin for the given port and returns its state.
 *
 * @param pin Pin number within the given port (0 to 7)
 * @return 0 if pin clear, non-zero if pin set.
 */
RAMFUNC_GPIO static int pac5xxx_gpio_in_pin_b(int pin) { return (PAC5XXX_GPIOB->IN.b & (1 << pin)); }

/**
 * @brief This function tests the given pin for the given port and returns its state.
 *
 * @param pin Pin number within the given port (0 to 7)
 * @return 0 if pin clear, non-zero if pin set.
 */
RAMFUNC_GPIO static int pac5xxx_gpio_in_pin_c(int pin) { return (PAC5XXX_GPIOC->IN.b & (1 << pin)); }

/**
 * @brief This function tests the given pin for the given port and returns its state.
 *
 * @param pin Pin number within the given port (0 to 7)
 * @return 0 if pin clear, non-zero if pin set.
 */
RAMFUNC_GPIO static int pac5xxx_gpio_in_pin_d(int pin) { return (PAC5XXX_GPIOD->IN.b & (1 << pin)); }

/**
 * @brief This function tests the given pin for the given port and returns its state.
 *
 * @param pin Pin number within the given port (0 to 7)
 * @return 0 if pin clear, non-zero if pin set.
 */
RAMFUNC_GPIO static int pac5xxx_gpio_in_pin_e(int pin) { return (PAC5XXX_GPIOE->IN.b & (1 << pin)); }

/**
 * @brief  This function configures Port C to be able to perform digital input/output
 *
 * @param  port_mask The mask of ports to set the digital enable state for.
 * @return none
 *
 * @note If Port C is to be used for either digital input or output, then the bits for the requisite pins must be set in this mask.
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_digital_enable_c(uint8_t port_mask) { PAC5XXX_GPIOC->INE.b = port_mask; }

/**
 * @brief  This function configures the peripheral selection for GPIO port A
 *
 * @param select_mask Peripheral selection mask. Each bit that is set is assigned to the peripheral function, instead of GPIO.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_peripheral_select_a(uint16_t select_mask) { PAC5XXX_GPIOA->PSEL.s = select_mask; }

/**
 * @brief  This function configures the peripheral selection for GPIO port B
 *
 * @param select_mask Peripheral selection mask. Each bit that is set is assigned to the peripheral function, instead of GPIO.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_peripheral_select_b(uint16_t select_mask) { PAC5XXX_GPIOB->PSEL.s = select_mask; }

/**
 * @brief  This function configures the peripheral selection for GPIO port C
 *
 * @param select_mask Peripheral selection mask. Each bit that is set is assigned to the peripheral function, instead of GPIO.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_peripheral_select_c(uint16_t select_mask) { PAC5XXX_GPIOC->PSEL.s = select_mask; }

/**
 * @brief  This function configures the peripheral selection for GPIO port D
 *
 * @param select_mask Peripheral selection mask. Each bit that is set is assigned to the peripheral function, instead of GPIO.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_peripheral_select_d(uint16_t select_mask) { PAC5XXX_GPIOD->PSEL.s = select_mask; }

/**
 * @brief  This function configures the peripheral selection for GPIO port E
 *
 * @param select_mask Peripheral selection mask. Each bit that is set is assigned to the peripheral function, instead of GPIO.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_peripheral_select_e(uint16_t select_mask) { PAC5XXX_GPIOE->PSEL.s = select_mask; }

/**
 * @brief  This function configures the given IO pin for GPIO
 *
 * @param pin_num Pin number to configure for GPIO (0 to 7)
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_io_pin_a(int pin_num) { PAC5XXX_GPIOA->PSEL.s &= ~(3 << (pin_num << 1)); }

/**
 * @brief  This function configures the given IO pin for GPIO
 *
 * @param pin_num Pin number to configure for GPIO (0 to 7)
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_io_pin_b(int pin_num) { PAC5XXX_GPIOB->PSEL.s &= ~(3 << (pin_num << 1)); }

/**
 * @brief  This function configures the given IO pin for GPIO
 *
 * @param pin_num Pin number to configure for GPIO (0 to 7)
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_io_pin_c(int pin_num) { PAC5XXX_GPIOC->PSEL.s &= ~(3 << (pin_num << 1)); }

/**
 * @brief  This function configures the given IO pin for GPIO
 *
 * @param pin_num Pin number to configure for GPIO (0 to 7)
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_io_pin_d(int pin_num) { PAC5XXX_GPIOD->PSEL.s &= ~(3 << (pin_num << 1)); }

/**
 * @brief  This function configures the given IO pin for GPIO
 *
 * @param pin_num Pin number to configure for GPIO (0 to 7)
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_io_pin_e(int pin_num) { PAC5XXX_GPIOE->PSEL.s &= ~(3 << (pin_num << 1)); }

/**
 * @brief  This function configures the interrupt polarity for GPIO port A
 *
 * @param polarity_mask Mask of the pins for interrupt polarity selection. Each bit that is set to 0 is configured for high-to-low transitions and bits set to 1 support low-to-high transitions.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_polarity_a(uint8_t polarity_mask) { PAC5XXX_GPIOA->INTP.b = polarity_mask; }

/**
 * @brief  This function configures the interrupt polarity for GPIO port B
 *
 * @param polarity_mask Mask of the pins for interrupt polarity selection. Each bit that is set to 0 is configured for high-to-low transitions and bits set to 1 support low-to-high transitions.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_polarity_b(uint8_t polarity_mask) { PAC5XXX_GPIOB->INTP.b = polarity_mask; }

/**
 * @brief  This function configures the interrupt polarity for GPIO port C
 *
 * @param polarity_mask Mask of the pins for interrupt polarity selection. Each bit that is set to 0 is configured for high-to-low transitions and bits set to 1 support low-to-high transitions.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_polarity_c(uint8_t polarity_mask) { PAC5XXX_GPIOC->INTP.b = polarity_mask; }

/**
 * @brief  This function configures the interrupt polarity for GPIO port D
 *
 * @param polarity_mask Mask of the pins for interrupt polarity selection. Each bit that is set to 0 is configured for high-to-low transitions and bits set to 1 support low-to-high transitions.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_polarity_d(uint8_t polarity_mask) { PAC5XXX_GPIOD->INTP.b = polarity_mask; }

/**
 * @brief  This function configures the interrupt polarity for GPIO port E
 *
 * @param polarity_mask Mask of the pins for interrupt polarity selection. Each bit that is set to 0 is configured for high-to-low transitions and bits set to 1 support low-to-high transitions.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_polarity_e(uint8_t polarity_mask) { PAC5XXX_GPIOE->INTP.b = polarity_mask; }

/**
 * @brief  This function configures the interrupt enable state for GPIO port A
 *
 * @param enable_mask Mask of the pins to enable interrupts on. Each bit that is set to a 1 has interrupts enabled on that pin.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_enable_a(uint8_t enable_mask) { PAC5XXX_GPIOA->INTE.b = enable_mask; }

/**
 * @brief  This function configures the interrupt enable state for GPIO port B
 *
 * @param enable_mask Mask of the pins to enable interrupts on. Each bit that is set to a 1 has interrupts enabled on that pin.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_enable_b(uint8_t enable_mask) { PAC5XXX_GPIOB->INTE.b = enable_mask; }

/**
 * @brief  This function configures the interrupt enable state for GPIO port C
 *
 * @param enable_mask Mask of the pins to enable interrupts on. Each bit that is set to a 1 has interrupts enabled on that pin.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_enable_c(uint8_t enable_mask) { PAC5XXX_GPIOC->INTE.b = enable_mask; }

/**
 * @brief  This function configures the interrupt enable state for GPIO port D
 *
 * @param enable_mask Mask of the pins to enable interrupts on. Each bit that is set to a 1 has interrupts enabled on that pin.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_enable_d(uint8_t enable_mask) { PAC5XXX_GPIOD->INTE.b = enable_mask; }

/**
 * @brief  This function configures the interrupt enable state for GPIO port E
 *
 * @param enable_mask Mask of the pins to enable interrupts on. Each bit that is set to a 1 has interrupts enabled on that pin.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_enable_e(uint8_t enable_mask) { PAC5XXX_GPIOE->INTE.b = enable_mask; }

/**
 * @brief  This function disables interrupts for the given pins for GPIO port A
 *
 * @param disable_mask Mask of the pins to disable interrupts on. Each bit that is set to a 1 has interrupts disabled on that pin.
 *                     Bits that are not set are not affected.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_disable_a(uint8_t disable_mask) { PAC5XXX_GPIOA->INTE.b &= ~disable_mask; }

/**
 * @brief  This function disables interrupts for the given pins for GPIO port B
 *
 * @param disable_mask Mask of the pins to disable interrupts on. Each bit that is set to a 1 has interrupts disabled on that pin.
 *                     Bits that are not set are not affected.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_disable_b(uint8_t disable_mask) { PAC5XXX_GPIOB->INTE.b &= ~disable_mask; }

/**
 * @brief  This function disables interrupts for the given pins for GPIO port C
 *
 * @param disable_mask Mask of the pins to disable interrupts on. Each bit that is set to a 1 has interrupts disabled on that pin.
 *                     Bits that are not set are not affected.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_disable_c(uint8_t disable_mask) { PAC5XXX_GPIOC->INTE.b &= ~disable_mask; }

/**
 * @brief  This function disables interrupts for the given pins for GPIO port D
 *
 * @param disable_mask Mask of the pins to disable interrupts on. Each bit that is set to a 1 has interrupts disabled on that pin.
 *                     Bits that are not set are not affected.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_disable_d(uint8_t disable_mask) { PAC5XXX_GPIOD->INTE.b &= ~disable_mask; }

/**
 * @brief  This function disables interrupts for the given pins for GPIO port E
 *
 * @param disable_mask Mask of the pins to disable interrupts on. Each bit that is set to a 1 has interrupts disabled on that pin.
 *                     Bits that are not set are not affected.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_disable_e(uint8_t disable_mask) { PAC5XXX_GPIOE->INTE.b &= ~disable_mask; }

/**
 * @brief  This function sets the interrupt mask state for GPIO port A. Pins that are masked will not generate interrupts.
 *
 * @param port_mask Mask of the pins that will have interrupts masked.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_mask_a(uint8_t port_mask) { PAC5XXX_GPIOA->INTM.b = port_mask; }
/**
 * @brief  This function sets the interrupt mask state for GPIO port B. Pins that are masked will not generate interrupts.
 *
 * @param port_mask Mask of the pins that will have interrupts masked.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_mask_b(uint8_t port_mask) { PAC5XXX_GPIOB->INTM.b = port_mask; }

/**
 * @brief  This function sets the interrupt mask state for GPIO port C. Pins that are masked will not generate interrupts.
 *
 * @param port_mask Mask of the pins that will have interrupts masked.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_mask_c(uint8_t port_mask) { PAC5XXX_GPIOC->INTM.b = port_mask; }

/**
 * @brief  This function sets the interrupt mask state for GPIO port D. Pins that are masked will not generate interrupts.
 *
 * @param port_mask Mask of the pins that will have interrupts masked.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_mask_d(uint8_t port_mask) { PAC5XXX_GPIOD->INTM.b = port_mask; }

/**
 * @brief  This function sets the interrupt mask state for GPIO port E. Pins that are masked will not generate interrupts.
 *
 * @param port_mask Mask of the pins that will have interrupts masked.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_mask_e(uint8_t port_mask) { PAC5XXX_GPIOE->INTM.b = port_mask; }

/**
 * @brief This function returns the interrupt flag mask for the given GPIO port.
 * @param none
 *
 * @return bit-mask of flags for this GPIO port
 */
RAMFUNC_GPIO static int pac5xxx_gpio_int_flag_a(void) { return PAC5XXX_GPIOA->INTF.b; }

/**
 * @brief This function returns the interrupt flag mask for the given GPIO port.
 * @param none
 *
 * @return bit-mask of flags for this GPIO port
 */
RAMFUNC_GPIO static int pac5xxx_gpio_int_flag_b(void) { return PAC5XXX_GPIOB->INTF.b; }

/**
 * @brief This function returns the interrupt flag mask for the given GPIO port.
 * @param none
 *
 * @return bit-mask of flags for this GPIO port
 */
RAMFUNC_GPIO static int pac5xxx_gpio_int_flag_c(void) { return PAC5XXX_GPIOC->INTF.b; }

/**
 * @brief This function returns the interrupt flag mask for the given GPIO port.
 * @param none
 *
 * @return bit-mask of flags for this GPIO port
 */
RAMFUNC_GPIO static int pac5xxx_gpio_int_flag_d(void) { return PAC5XXX_GPIOD->INTF.b; }

/**
 * @brief This function returns the interrupt flag mask for the given GPIO port.
 * @param none
 *
 * @return bit-mask of flags for this GPIO port
 */
RAMFUNC_GPIO static int pac5xxx_gpio_int_flag_e(void) { return PAC5XXX_GPIOE->INTF.b; }

/**
 * @brief  This function clears the interrupt flags for the select pins within GPIO port A.
 *
 * @param port_mask Mask of interrupt flags to clear. Each bit set to 1 will clear that interrupt flag.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_flag_clear_a(uint8_t port_mask) { PAC5XXX_GPIOA->INTF.b = port_mask; }

/**
 * @brief  This function clears the interrupt flags for the select pins within GPIO port B.
 *
 * @param port_mask Mask of interrupt flags to clear. Each bit set to 1 will clear that interrupt flag.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_flag_clear_b(uint8_t port_mask) { PAC5XXX_GPIOB->INTF.b = port_mask; }

/**
 * @brief  This function clears the interrupt flags for the select pins within GPIO port C.
 *
 * @param port_mask Mask of interrupt flags to clear. Each bit set to 1 will clear that interrupt flag.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_flag_clear_c(uint8_t port_mask) { PAC5XXX_GPIOC->INTF.b = port_mask; }

/**
 * @brief  This function clears the interrupt flags for the select pins within GPIO port D.
 *
 * @param port_mask Mask of interrupt flags to clear. Each bit set to 1 will clear that interrupt flag.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_flag_clear_d(uint8_t port_mask) { PAC5XXX_GPIOD->INTF.b = port_mask; }

/**
 * @brief  This function clears the interrupt flags for the select pins within GPIO port E.
 *
 * @param port_mask Mask of interrupt flags to clear. Each bit set to 1 will clear that interrupt flag.
 * @return none
 *
 */
RAMFUNC_GPIO static  void pac5xxx_gpio_int_flag_clear_e(uint8_t port_mask) { PAC5XXX_GPIOE->INTF.b = port_mask; }

/**
 * @brief  This function indicates the interrupt flag state for the pins for GPIO port A.
 *
 * @return Mask of interrupt flags that are set.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_int_flag_set_a(void) { return PAC5XXX_GPIOA->INTF.b; }

/**
 * @brief  This function indicates the interrupt flag state for the pins for GPIO port B.
 *
 * @return Mask of interrupt flags that are set.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_int_flag_set_b(void) { return PAC5XXX_GPIOB->INTF.b; }

/**
 * @brief  This function indicates the interrupt flag state for the pins for GPIO port C.
 *
 * @return Mask of interrupt flags that are set.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_int_flag_set_c(void) { return PAC5XXX_GPIOC->INTF.b; }

/**
 * @brief  This function indicates the interrupt flag state for the pins for GPIO port D.
 *
 * @return Mask of interrupt flags that are set.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_int_flag_set_d(void) { return PAC5XXX_GPIOD->INTF.b; }

/**
 * @brief  This function indicates the interrupt flag state for the pins for GPIO port E.
 *
 * @return Mask of interrupt flags that are set.
 *
 */
RAMFUNC_GPIO static  uint8_t pac5xxx_gpio_int_flag_set_e(void) { return PAC5XXX_GPIOE->INTF.b; }

/**
 * @brief  This function configures the IO controller to IO mode for the given ports
 *
 * @param  port_mask Port mask of pins with this port to enable IO for (1: Set to IO mode, 0: do nothing)
 */
RAMFUNC_GPIO void pac5xxx_gpio_io_enable_a(uint8_t port_mask);

/**
 * @brief  This function configures the IO controller to IO mode for the given ports
 *
 * @param  port_mask Port mask of pins with this port to enable IO for (1: Set to IO mode, 0: do nothing)
 */
RAMFUNC_GPIO void pac5xxx_gpio_io_enable_b(uint8_t port_mask);

/**
 * @brief  This function configures the IO controller to IO mode for the given ports
 *
 * @param  port_mask Port mask of pins with this port to enable IO for (1: Set to IO mode, 0: do nothing)
 */
RAMFUNC_GPIO void pac5xxx_gpio_io_enable_c(uint8_t port_mask);

/**
 * @brief  This function configures the IO controller to IO mode for the given ports
 *
 * @param  port_mask Port mask of pins with this port to enable IO for (1: Set to IO mode, 0: do nothing)
 */
RAMFUNC_GPIO void pac5xxx_gpio_io_enable_d(uint8_t port_mask);

/**
 * @brief  This function configures the IO controller to IO mode for the given ports
 *
 * @param  port_mask Port mask of pins with this port to enable IO for (1: Set to IO mode, 0: do nothing)
 */
RAMFUNC_GPIO void pac5xxx_gpio_io_enable_e(uint8_t port_mask);

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_a(uint8_t port_mask, uint8_t active_high_mask);

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_b(uint8_t port_mask, uint8_t active_high_mask);

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_c(uint8_t port_mask, uint8_t active_high_mask);

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_d(uint8_t port_mask, uint8_t active_high_mask);

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_e(uint8_t port_mask, uint8_t active_high_mask);


/*@}*/ /* end of group PAC5XXX_Driver_GPIO */

#endif // PAC5XXX_DRIVER_GPIO_H

