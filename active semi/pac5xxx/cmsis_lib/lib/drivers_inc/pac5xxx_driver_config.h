/**************************************************************************//**
 * @file     pac5xxx_driver_config.h
 * @brief    Firmware driver configuration for the PAC5XXX
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

/** @addtogroup PAC5XXX_Driver_Config PAC5XXX Driver Config
  @{
*/

#ifndef PAC5XXX_DRIVER_CONFIG_H
#define PAC5XXX_DRIVER_CONFIG_H

//#define ALL_RAM

#ifdef ALL_RAM
#define PAC5XXX_DRIVER_GPIO_RAM		    /*!< Link GPIO driver functions in RAM    				*/
#define PAC5XXX_DRIVER_SPI_RAM		    /*!< Link SPI driver functions in RAM     				*/
#define PAC5XXX_DRIVER_SOCBRIDGE_RAM		/*!< Link SOC Bridge driver functions in RAM 			*/
#define PAC5XXX_DRIVER_TIMER_RAM		  /*!< Link Timer driver functions in RAM    				*/
#define PAC5XXX_DRIVER_I2C_RAM	  		/*!< Link I2C driver functions in RAM    				*/
#define PAC5XXX_DRIVER_SYSTEM_RAM     /*!< Link System driver functions in RAM    			*/
#define PAC5XXX_DRIVER_UART_RAM       /*!< Link UART driver functions in RAM    				*/
#define PAC5XXX_DRIVER_ADC_RAM        /*!< Link ADC driver functions in RAM    				*/
#define PAC5XXX_DRIVER_MEMORY_RAM     /*!< Link Memory Controller driver functions in RAM    	*/
#define PAC5XXX_DRIVER_WATCHDOG_RAM   /*!< Link Watchdog Timer driver functions in RAM    	*/
#define PAC5XXX_DRIVER_RTC_RAM        /*!< Link Real-time Clock driver functions in RAM */
#define PAC5XXX_DRIVER_ARM_RAM        /*!< Link ARM driver functions into RAM        */
#define PAC5XXX_DRIVER_TILE_RAM		/*!< Link Tile driver functions into RAM		*/
#else
//#define PAC5XXX_DRIVER_GPIO_RAM		    /*!< Link GPIO driver functions in RAM    				*/
//#define PAC5XXX_DRIVER_SPI_RAM		    /*!< Link SPI driver functions in RAM     				*/
//#define PAC5XXX_DRIVER_SOCBRIDGE_RAM		/*!< Link SOC Bridge driver functions in RAM 			*/
//#define PAC5XXX_DRIVER_TIMER_RAM		  /*!< Link Timer driver functions in RAM    				*/
//#define PAC5XXX_DRIVER_I2C_RAM	  		/*!< Link I2C driver functions in RAM    				*/
//#define PAC5XXX_DRIVER_SYSTEM_RAM     /*!< Link System driver functions in RAM    			*/
//#define PAC5XXX_DRIVER_UART_RAM       /*!< Link UART driver functions in RAM    				*/
//#define PAC5XXX_DRIVER_ADC_RAM        /*!< Link ADC driver functions in RAM    				*/
//#define PAC5XXX_DRIVER_MEMORY_RAM     /*!< Link Memory Controller driver functions in RAM    	*/
//#define PAC5XXX_DRIVER_WATCHDOG_RAM   /*!< Link Watchdog Timer driver functions in RAM    	*/
//#define PAC5XXX_DRIVER_RTC_RAM        /*!< Link Real-time Clock driver functions in RAM */
//#define PAC5XXX_DRIVER_ARM_RAM        /*!< Link ARM driver functions into RAM        */
//#define PAC5XXX_DRIVER_TILE_RAM			/*!< Link tile driver functions into RAM		*/
#endif

/*@}*/ /* end of group PAC5XXX_Driver_Config */

#endif

