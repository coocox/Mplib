/**************************************************************************//**
 * @file     pac5xxx.h
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File 
 *           for the Active Semiconductor PAC5XXX Device Series
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

#ifndef PAC5XXX_H
#define PAC5XXX_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* RAMFUNC definitions for linking to RAM */

#ifdef IAR
#define PAC5XXX_RAMFUNC __ramfunc
#elif defined GCC
#define PAC5XXX_RAMFUNC __attribute__((section(".data")))
#else
#define PAC5XXX_RAMFUNC
#endif

/** @addtogroup PAC5XXX_Definitions PAC5XXX Definitions
  This file defines all structures and symbols for PAC5XXX:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup PAC5XXX_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/

  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
  HardFault_IRQn                = -13,      /*!<  3 Hard Fault Interrupt                          */
  SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
  PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
  SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

/******  Device Specific Interrupt Numbers ********************************************************/

  MemCtl_IRQn                   = 0,        /*!< Memory Controller Interrupt                      */
  SysClk_IRQn                   = 1,        /*!< Clock/System Controller Interrupt                */
  Wdt_IRQn                      = 2,        /*!< Watchdog Timer Interrupt                         */
  GpioA_IRQn                    = 3,        /*!< GPIO Port A Interrupt                            */
  GpioB_IRQn                    = 4,        /*!< GPIO Port B Interrupt                            */
  GpioC_IRQn                    = 5,        /*!< GPIO Port C Interrupt                            */
  GpioD_IRQn                    = 6,        /*!< GPIO Port D Interrupt                            */
  GpioE_IRQn                    = 7,        /*!< GPIO Port E Interrupt                            */
  TimerA_IRQn                   = 8,        /*!< Timer A Interrupt (Base, CC0-5)                  */
  TimerAExt_IRQn                = 9,        /*!< Timer A Extended Interrupt (CC6-7)               */
  TimerB_IRQn                   = 10,        /*!< Timer B Interrupt                               */
  TimerC_IRQn                   = 11,       /*!< Timer C Interrupt                                */
  TimerD_IRQn                   = 12,       /*!< Timer D Interrupt                                */
  ADC_IRQn                      = 13,       /*!< ADC Interrupt                                    */
  SocBridge_IRQn                = 14,       /*!< SocBridge Interrupt                              */
  SPI_IRQn                     = 15,       /*!< SPI_B Interrupt                                  */
  UART_IRQn                     = 16,       /*!< UART Interrupt                                   */
  I2C_IRQn                      = 17,       /*!< I2C Interrupt                                    */
  EMUX_IRQn                     = 18,       /*!< EMUX Interrupt                                   */
  RTC_IRQn                      = 19        /*!< RTC Interrupt                                    */

  } IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */

#define __CM0_REV                 0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */

/*@}*/ /* end of group PAC5XXX_CMSIS */

#include <core_cm0.h>                       /* Cortex-M# processor and core peripherals           */
#include "system_pac5xxx.h"                 /* PAC5XXX System  include file                         */

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup PAC5XXX_Peripherals PAC5XXX Peripherals
  PAC5XXX Device Specific Peripheral registers structures
  @{
*/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

#include "pac5xxx_ADC.h"                      	/* PAC5XXX ADC include file                             */
#include "pac5xxx_GPIO.h"                     	/* PAC5XXX GPIO include file                            */
#include "pac5xxx_I2C.h"                      	/* PAC5XXX I2C include file                             */
#include "pac5xxx_Memory.h"                   	/* PAC5XXX Memory Controller include file               */
#include "pac5xxx_SPI.h"                     	/* PAC5XXX SPI include file                             */
#include "pac5xxx_SocBridge.h"					/* PAC5XXX SOC Bridge include file                      */
#include "pac5xxx_SYS.h"                      	/* PAC5XXX System/Clock System include file             */
#include "pac5xxx_Timers.h"                   	/* PAC5XXX Timers include file                          */
#include "pac5xxx_UART.h"                     	/* PAC5XXX UART include file                            */
#include "pac5xxx_WDT.h"                      	/* PAC5XXX Watchdog Timer include file                  */
#include "pac5xxx_RTC.h"                      	/* PAC5XXX Real-Time Clock include file                 */
#include "pac5xxx_tile_SignalManager.h"			/* PAC5XXX Signal Manager Tile include file				  */
#include "pac5xxx_tile_SystemManager.h"			/* PAC5XXX System Manager Tile include file				  */
#include "pac5xxx_tile_DriverManager.h"			/* PAC5XXX Driver Manager Tile include file				  */
#include "pac5xxx_tile_PowerManager.h"			/* PAC5XXX Power Manager Tile include file                */

/*@}*/ /* end of group PAC5XXX_Peripherals */


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup PAC5XXX_MemoryMap PAC5XXX Memory Mapping
  @{
*/

/* Peripheral and SRAM base address */
#define PAC5XXX_FLASH_BASE                      (0x00000000UL)                              /*!< FLASH        Base Address            */
#define PAC5XXX_FLASH_SEG0_BASE                 (0x00000000UL)                              /*!< FLASH segment 0 Base Address         */
#define PAC5XXX_FLASH_SEG1_BASE                 (0x00000400UL)                              /*!< FLASH segment 1 Base Address         */
#define PAC5XXX_FLASH_SEG2_BASE                 (0x00000800UL)                              /*!< FLASH segment 2 Base Address         */
#define PAC5XXX_FLASH_SEG3_BASE                 (0x00000C00UL)                              /*!< FLASH segment 3 Base Address         */
#define PAC5XXX_FLASH_SEG4_BASE                 (0x00001000UL)                              /*!< FLASH segment 4 Base Address         */
#define PAC5XXX_FLASH_SEG5_BASE                 (0x00001400UL)                              /*!< FLASH segment 5 Base Address         */
#define PAC5XXX_FLASH_SEG6_BASE                 (0x00001800UL)                              /*!< FLASH segment 6 Base Address         */
#define PAC5XXX_FLASH_SEG7_BASE                 (0x00001C00UL)                              /*!< FLASH segment 7 Base Address         */
#define PAC5XXX_FLASH_SEG8_BASE                 (0x00002000UL)                              /*!< FLASH segment 8 Base Address         */
#define PAC5XXX_FLASH_SEG9_BASE                 (0x00002400UL)                              /*!< FLASH segment 9 Base Address         */
#define PAC5XXX_FLASH_SEG10_BASE                (0x00002800UL)                              /*!< FLASH segment 10 Base Address        */
#define PAC5XXX_FLASH_SEG11_BASE                (0x00002C00UL)                              /*!< FLASH segment 11 Base Address        */
#define PAC5XXX_FLASH_SEG12_BASE                (0x00003000UL)                              /*!< FLASH segment 12 Base Address        */
#define PAC5XXX_FLASH_SEG13_BASE                (0x00003400UL)                              /*!< FLASH segment 13 Base Address        */
#define PAC5XXX_FLASH_SEG14_BASE                (0x00003800UL)                              /*!< FLASH segment 14 Base Address        */
#define PAC5XXX_FLASH_SEG15_BASE                (0x00003C00UL)                              /*!< FLASH segment 15 Base Address        */
#define PAC5XXX_FLASH_SEG16_BASE                (0x00004000UL)                              /*!< FLASH segment 0 Base Address         */
#define PAC5XXX_FLASH_SEG17_BASE                (0x00004400UL)                              /*!< FLASH segment 1 Base Address         */
#define PAC5XXX_FLASH_SEG18_BASE                (0x00004800UL)                              /*!< FLASH segment 2 Base Address         */
#define PAC5XXX_FLASH_SEG19_BASE                (0x00004C00UL)                              /*!< FLASH segment 3 Base Address         */
#define PAC5XXX_FLASH_SEG20_BASE                (0x00005000UL)                              /*!< FLASH segment 4 Base Address         */
#define PAC5XXX_FLASH_SEG21_BASE                (0x00005400UL)                              /*!< FLASH segment 5 Base Address         */
#define PAC5XXX_FLASH_SEG22_BASE                (0x00005800UL)                              /*!< FLASH segment 6 Base Address         */
#define PAC5XXX_FLASH_SEG23_BASE                (0x00005C00UL)                              /*!< FLASH segment 7 Base Address         */
#define PAC5XXX_FLASH_SEG24_BASE                (0x00006000UL)                              /*!< FLASH segment 8 Base Address         */
#define PAC5XXX_FLASH_SEG25_BASE                (0x00006400UL)                              /*!< FLASH segment 9 Base Address         */
#define PAC5XXX_FLASH_SEG26_BASE                (0x00006800UL)                              /*!< FLASH segment 10 Base Address        */
#define PAC5XXX_FLASH_SEG27_BASE                (0x00006C00UL)                              /*!< FLASH segment 11 Base Address        */
#define PAC5XXX_FLASH_SEG28_BASE                (0x00007000UL)                              /*!< FLASH segment 12 Base Address        */
#define PAC5XXX_FLASH_SEG29_BASE                (0x00007400UL)                              /*!< FLASH segment 13 Base Address        */
#define PAC5XXX_FLASH_SEG30_BASE                (0x00007800UL)                              /*!< FLASH segment 14 Base Address        */
#define PAC5XXX_FLASH_SEG31_BASE                (0x00007C00UL)                              /*!< FLASH segment 15 Base Address        */

#define PAC5XXX_SRAM_BASE                       (0x20000000UL)                              /*!< SRAM         Base Address            */
#define PAC5XXX_PERIPH_BASE                     (0x40000000UL)                              /*!< Peripheral   Base Address            */

/* Peripheral memory map */
#define PAC5XXX_SYSCTL_BASE                     (PAC5XXX_PERIPH_BASE)                         /*!< System/Clock Control    Base Address */
#define PAC5XXX_MEMCTL_BASE                     (PAC5XXX_PERIPH_BASE + 0x20000)               /*!< FLASH Memory Controller Base Address */
#define PAC5XXX_WDT_BASE                        (PAC5XXX_PERIPH_BASE + 0x30000)               /*!< Watchdog Timer          Base Address */
#define PAC5XXX_RTC_BASE                        (PAC5XXX_PERIPH_BASE + 0x40000)               /*!< RTC                     Base Address */
#define PAC5XXX_GPIOA_BASE                      (PAC5XXX_PERIPH_BASE + 0x70000)               /*!< GPIO A                  Base Address */
#define PAC5XXX_GPIOB_BASE                      (PAC5XXX_PERIPH_BASE + 0x70040)               /*!< GPIO B                  Base Address */
#define PAC5XXX_GPIOAB_BASE                     (PAC5XXX_PERIPH_BASE + 0x70080)               /*!< GPIO A/B                Base Address */
#define PAC5XXX_GPIOC_BASE                      (PAC5XXX_PERIPH_BASE + 0x80000)               /*!< GPIO C                  Base Address */
#define PAC5XXX_GPIOD_BASE                      (PAC5XXX_PERIPH_BASE + 0x80040)               /*!< GPIO D                  Base Address */
#define PAC5XXX_GPIOCD_BASE                     (PAC5XXX_PERIPH_BASE + 0x80080)               /*!< GPIO C/D                Base Address */
#define PAC5XXX_GPIOE_BASE                      (PAC5XXX_PERIPH_BASE + 0x90000)               /*!< GPIO E                  Base Address */
#define PAC5XXX_TIMERA_BASE                     (PAC5XXX_PERIPH_BASE + 0xD0000)               /*!< Timer A/DTGA[0:3]       Base Address */
#define PAC5XXX_TIMERB_BASE                     (PAC5XXX_PERIPH_BASE + 0xE0000)               /*!< Timer B/DTGB            Base Address */
#define PAC5XXX_TIMERC_BASE                     (PAC5XXX_PERIPH_BASE + 0xF0000)               /*!< Timer C/DTGC            Base Address */
#define PAC5XXX_TIMERD_BASE                     (PAC5XXX_PERIPH_BASE + 0x100000)              /*!< Timer D/DTGD            Base Address */
#define PAC5XXX_ADC_BASE                        (PAC5XXX_PERIPH_BASE + 0x150000)              /*!< ADC                     Base Address */
#define PAC5XXX_I2C_BASE                        (PAC5XXX_PERIPH_BASE + 0x1B0000)              /*!< I2C                     Base Address */
#define PAC5XXX_UART_BASE                       (PAC5XXX_PERIPH_BASE + 0x1D0000)              /*!< UART                    Base Address */
#define PAC5XXX_SOCBRIDGE_BASE                  (PAC5XXX_PERIPH_BASE + 0x200000)              /*!< SOC Bridge              Base Address */
#define PAC5XXX_SPI_BASE                       (PAC5XXX_PERIPH_BASE + 0x210000)               /*!< SPI                    Base Address */
/*@}*/ /* end of group PAC5XXX_MemoryMap */


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/** @addtogroup PAC5XXX_PeripheralDecl PAC5XXX Peripheral Declaration
  @{
*/

#define PAC5XXX_SYSCTL                           ((PAC5XXX_SYSCLKCTL_TypeDef *) PAC5XXX_SYSCTL_BASE)
#define PAC5XXX_MEMCTL                           ((PAC5XXX_MEMCTL_TypeDef *) PAC5XXX_MEMCTL_BASE)
#define PAC5XXX_WDT                              ((PAC5XXX_WDT_TypeDef *) PAC5XXX_WDT_BASE)
#define PAC5XXX_RTC                              ((PAC5XXX_RTC_TypeDef *) PAC5XXX_RTC_BASE)
#define PAC5XXX_GPIOA                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOA_BASE)
#define PAC5XXX_GPIOB                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOB_BASE)
#define PAC5XXX_GPIOAB                           ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOAB_BASE)
#define PAC5XXX_GPIOC                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOC_BASE)
#define PAC5XXX_GPIOD                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOD_BASE)
#define PAC5XXX_GPIOCD                           ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOCD_BASE)
#define PAC5XXX_GPIOE                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOE_BASE)
#define PAC5XXX_TIMERA                           ((PAC5XXX_Timer8CC_TypeDef *) PAC5XXX_TIMERA_BASE)
#define PAC5XXX_TIMERB                           ((PAC5XXX_Timer4CC_TypeDef *) PAC5XXX_TIMERB_BASE)
#define PAC5XXX_TIMERC                           ((PAC5XXX_Timer2CC_TypeDef *) PAC5XXX_TIMERC_BASE)
#define PAC5XXX_TIMERD                           ((PAC5XXX_Timer2CC_TypeDef *) PAC5XXX_TIMERD_BASE)
#define PAC5XXX_ADC                              ((PAC5XXX_ADC_TypeDef *) PAC5XXX_ADC_BASE)
#define PAC5XXX_I2C                              ((PAC5XXX_I2C_TypeDef *) PAC5XXX_I2C_BASE)
#define PAC5XXX_UART                             ((PAC5XXX_UART_TypeDef *) PAC5XXX_UART_BASE)
#define PAC5XXX_SPI                              ((PAC5XXX_SPI_TypeDef *) PAC5XXX_SPI_BASE)
#define PAC5XXX_SOCBRIDGE                        ((PAC5XXX_SocBridge_TypeDef *) PAC5XXX_SOCBRIDGE_BASE)

/*@}*/ /* end of group PAC5XXX_PeripheralDecl */


/*@}*/ /* end of group PAC5XXX_Definitions */

#ifdef __cplusplus
}
#endif

#endif  /* PAC5XXX_H */
