/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#ifndef __NUC123Series_H__
#define __NUC123Series_H__

              
/**
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
 
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                     */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                       */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                   */

/******  ARMIKMCU Swift specific Interrupt Numbers ************************************************/
  BOD_IRQn                  = 0,        /*!< Brown-Out Low Voltage Detected Interrupt             */ 
  WDT_IRQn                  = 1,        /*!< Watch Dog Timer Interrupt                            */
  EINT0_IRQn                = 2,        /*!< EINT0 Interrupt                                      */
  EINT1_IRQn                = 3,        /*!< EINT1 Interrupt                                      */
  GPAB_IRQn                 = 4,        /*!< GPIO_PA/PB Interrupt                                 */
  GPCDF_IRQn                = 5,        /*!< GPIO_PC/PD/PE/PF Interrupt                           */
  PWMA_IRQn                 = 6,        /*!< PWMA Interrupt                                       */
  TMR0_IRQn                 = 8,        /*!< TIMER0 Interrupt                                     */
  TMR1_IRQn                 = 9,        /*!< TIMER1 Interrupt                                     */
  TMR2_IRQn                 = 10,       /*!< TIMER2 Interrupt                                     */
  TMR3_IRQn                 = 11,       /*!< TIMER3 Interrupt                                     */
  UART0_IRQn                = 12,       /*!< UART0 Interrupt                                      */
  UART1_IRQn                = 13,       /*!< UART1 Interrupt                                      */
  SPI0_IRQn                 = 14,       /*!< SPI0 Interrupt                                       */
  SPI1_IRQn                 = 15,       /*!< SPI1 Interrupt                                       */
  SPI2_IRQn                 = 16,       /*!< SPI2 Interrupt                                       */
  I2C0_IRQn                 = 18,       /*!< I2C0 Interrupt                                       */
  I2C1_IRQn                 = 19,       /*!< I2C1 Interrupt                                       */
  USBD_IRQn                 = 23,       /*!< USB device Interrupt                                 */
  PS2_IRQn                  = 24,       /*!< PS/2 device Interrupt                                */
  PDMA_IRQn                 = 26,       /*!< PDMA Interrupt                                       */
  I2S_IRQn                  = 27,       /*!< I2S Interrupt                                        */
  PWRWU_IRQn                = 28,       /*!< Power Down Wake Up Interrupt                         */
  ADC_IRQn                  = 29,       /*!< ADC Interrupt                                        */
} IRQn_Type;


/**
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT           0       /*!< armikcmu does not provide a MPU present or not       */
#define __NVIC_PRIO_BITS        2       /*!< armikcmu Supports 2 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used         */


#include "core_cm0.h"                   /* Cortex-M0 processor and core peripherals               */
#include "system_NUC123Series.h"        /* NUC123 System                                          */

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


#define __ASM            __asm                                      /*!< asm keyword for GNU Compiler          */
#define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */



/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup NUC123_SERIES_REG NUC123 Series Registers
 @{             
*/

/*--------------------- General Purpose I/O (GPIO) ---------------------*/
/** @addtogroup NUC123_GPIO NUC123 GPIO
  Memory Mapped Structure for NUC123 Series General Purpose I/O
  @{
 */
typedef struct
{
    /**
     * PMD
     * ===================================================================================================
     * Offset: 0x00  GPIO Port [A/B/C/D/E/F] I/O Mode Control
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  PMD;                         

    /**
     * OFFD
     * ===================================================================================================
     * Offset: 0x04  GPIO Port [A/B/C/D/E/F] Pin Digital Input Path Disable Control
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  OFFD;                        

    /**
     * DOUT
     * ===================================================================================================
     * Offset: 0x08  GPIO Port [A/B/C/D/E/F] Data Output Value
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DOUT;                        

    /**
     * DMASK
     * ===================================================================================================
     * Offset: 0x0C  GPIO Port [A/B/C/D/E/F] Data Output Write Mask
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DMASK;                       

    /**
     * PIN
     * ===================================================================================================
     * Offset: 0x10  GPIO Port [A/B/C/D/E/F] Pin Value
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  PIN;                         

    /**
     * DBEN
     * ===================================================================================================
     * Offset: 0x14  GPIO Port [A/B/C/D/E/F] De-bounce Enable
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DBEN;                        

    /**
     * IMD
     * ===================================================================================================
     * Offset: 0x18  GPIO Port [A/B/C/D/E/F] Interrupt Mode Control
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  IMD;                         

    /**
     * IEN
     * ===================================================================================================
     * Offset: 0x1C  GPIO Port [A/B/C/D/E/F] Interrupt Enable Control
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  IEN;                         

    /**
     * ISRC
     * ===================================================================================================
     * Offset: 0x20  GPIO Port [A/B/C/D/E/F] Interrupt Source Flag
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  ISRC;                        
} GPIO_T;                                  
                                                
typedef struct                                  
{                                               
    /**
     * DBNCECON
     * ===================================================================================================
     * Offset: 0x180 Interrupt De-bounce Cycle Control
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DBNCECON;                    
} GPIO_DBNCECON_T;

/* GPIO PMD Bit Field Definitions */
#define GPIO_PMD_PMD15_Pos          30                                          /*!< GPIO PMD: PMD15 Position */
#define GPIO_PMD_PMD15_Msk          (0x3ul << GPIO_PMD_PMD15_Pos)               /*!< GPIO PMD: PMD15 Mask */

#define GPIO_PMD_PMD14_Pos          28                                          /*!< GPIO PMD: PMD14 Position */
#define GPIO_PMD_PMD14_Msk          (0x3ul << GPIO_PMD_PMD14_Pos)               /*!< GPIO PMD: PMD14 Mask */

#define GPIO_PMD_PMD13_Pos          26                                          /*!< GPIO PMD: PMD13 Position */
#define GPIO_PMD_PMD13_Msk          (0x3ul << GPIO_PMD_PMD13_Pos)               /*!< GPIO PMD: PMD13 Mask */

#define GPIO_PMD_PMD12_Pos          24                                          /*!< GPIO PMD: PMD12 Position */
#define GPIO_PMD_PMD12_Msk          (0x3ul << GPIO_PMD_PMD12_Pos)               /*!< GPIO PMD: PMD12 Mask */

#define GPIO_PMD_PMD11_Pos          22                                          /*!< GPIO PMD: PMD11 Position */
#define GPIO_PMD_PMD11_Msk          (0x3ul << GPIO_PMD_PMD11_Pos)               /*!< GPIO PMD: PMD11 Mask */

#define GPIO_PMD_PMD10_Pos          20                                          /*!< GPIO PMD: PMD10 Position */
#define GPIO_PMD_PMD10_Msk          (0x3ul << GPIO_PMD_PMD10_Pos)               /*!< GPIO PMD: PMD10 Mask */

#define GPIO_PMD_PMD9_Pos           18                                          /*!< GPIO PMD: PMD9 Position */
#define GPIO_PMD_PMD9_Msk           (0x3ul << GPIO_PMD_PMD9_Pos)                /*!< GPIO PMD: PMD9 Mask */

#define GPIO_PMD_PMD8_Pos           16                                          /*!< GPIO PMD: PMD8 Position */
#define GPIO_PMD_PMD8_Msk           (0x3ul << GPIO_PMD_PMD8_Pos)                /*!< GPIO PMD: PMD8 Mask */

#define GPIO_PMD_PMD7_Pos           14                                          /*!< GPIO PMD: PMD7 Position */
#define GPIO_PMD_PMD7_Msk           (0x3ul << GPIO_PMD_PMD7_Pos)                /*!< GPIO PMD: PMD7 Mask */

#define GPIO_PMD_PMD6_Pos           12                                          /*!< GPIO PMD: PMD6 Position */    
#define GPIO_PMD_PMD6_Msk           (0x3ul << GPIO_PMD_PMD6_Pos)                /*!< GPIO PMD: PMD6 Mask */

#define GPIO_PMD_PMD5_Pos           10                                          /*!< GPIO PMD: PMD5 Position */
#define GPIO_PMD_PMD5_Msk           (0x3ul << GPIO_PMD_PMD5_Pos)                /*!< GPIO PMD: PMD5 Mask */

#define GPIO_PMD_PMD4_Pos           8                                           /*!< GPIO PMD: PMD4 Position */
#define GPIO_PMD_PMD4_Msk           (0x3ul << GPIO_PMD_PMD4_Pos)                /*!< GPIO PMD: PMD4 Mask */

#define GPIO_PMD_PMD3_Pos           6                                           /*!< GPIO PMD: PMD3 Position */
#define GPIO_PMD_PMD3_Msk           (0x3ul << GPIO_PMD_PMD3_Pos)                /*!< GPIO PMD: PMD3 Mask */

#define GPIO_PMD_PMD2_Pos           4                                           /*!< GPIO PMD: PMD2 Position */
#define GPIO_PMD_PMD2_Msk           (0x3ul << GPIO_PMD_PMD2_Pos)                /*!< GPIO PMD: PMD2 Mask */

#define GPIO_PMD_PMD1_Pos           2                                           /*!< GPIO PMD: PMD1 Position */
#define GPIO_PMD_PMD1_Msk           (0x3ul << GPIO_PMD_PMD1_Pos)                /*!< GPIO PMD: PMD1 Mask */

#define GPIO_PMD_PMD0_Pos           0                                           /*!< GPIO PMD: PMD0 Position */
#define GPIO_PMD_PMD0_Msk           (0x3ul << GPIO_PMD_PMD0_Pos)                /*!< GPIO PMD: PMD0 Mask */

/* GPIO OFFD Bit Field Definitions */
#define GPIO_OFFD_OFFD15_Pos        31                                          /*!< GPIO OFFD: OFFD15 Position */
#define GPIO_OFFD_OFFD15_Msk        (1ul << GPIO_OFFD_OFFD15_Pos)               /*!< GPIO OFFD: OFFD15 Mask */

#define GPIO_OFFD_OFFD14_Pos        30                                          /*!< GPIO OFFD: OFFD14 Position */
#define GPIO_OFFD_OFFD14_Msk        (1ul << GPIO_OFFD_OFFD14_Pos)               /*!< GPIO OFFD: OFFD14 Mask */

#define GPIO_OFFD_OFFD13_Pos        29                                          /*!< GPIO OFFD: OFFD13 Position */
#define GPIO_OFFD_OFFD13_Msk        (1ul << GPIO_OFFD_OFFD13_Pos)               /*!< GPIO OFFD: OFFD13 Mask */

#define GPIO_OFFD_OFFD12_Pos        28                                          /*!< GPIO OFFD: OFFD12 Position */
#define GPIO_OFFD_OFFD12_Msk        (1ul << GPIO_OFFD_OFFD12_Pos)               /*!< GPIO OFFD: OFFD12 Mask */

#define GPIO_OFFD_OFFD11_Pos        27                                          /*!< GPIO OFFD: OFFD11 Position */
#define GPIO_OFFD_OFFD11_Msk        (1ul << GPIO_OFFD_OFFD11_Pos)               /*!< GPIO OFFD: OFFD11 Mask */

#define GPIO_OFFD_OFFD10_Pos        26                                          /*!< GPIO OFFD: OFFD10 Position */
#define GPIO_OFFD_OFFD10_Msk        (1ul << GPIO_OFFD_OFFD10_Pos)               /*!< GPIO OFFD: OFFD10 Mask */

#define GPIO_OFFD_OFFD9_Pos         25                                          /*!< GPIO OFFD: OFFD9 Position */
#define GPIO_OFFD_OFFD9_Msk         (1ul << GPIO_OFFD_OFFD9_Pos)                /*!< GPIO OFFD: OFFD9 Mask */

#define GPIO_OFFD_OFFD8_Pos         24                                          /*!< GPIO OFFD: OFFD8 Position */
#define GPIO_OFFD_OFFD8_Msk         (1ul << GPIO_OFFD_OFFD8_Pos)                /*!< GPIO OFFD: OFFD8 Mask */

#define GPIO_OFFD_OFFD7_Pos         23                                          /*!< GPIO OFFD: OFFD7 Position */
#define GPIO_OFFD_OFFD7_Msk         (1ul << GPIO_OFFD_OFFD7_Pos)                /*!< GPIO OFFD: OFFD7 Mask */

#define GPIO_OFFD_OFFD6_Pos         22                                          /*!< GPIO OFFD: OFFD6 Position */
#define GPIO_OFFD_OFFD6_Msk         (1ul << GPIO_OFFD_OFFD6_Pos)                /*!< GPIO OFFD: OFFD6 Mask */

#define GPIO_OFFD_OFFD5_Pos         21                                          /*!< GPIO OFFD: OFFD5 Position */
#define GPIO_OFFD_OFFD5_Msk         (1ul << GPIO_OFFD_OFFD5_Pos)                /*!< GPIO OFFD: OFFD5 Mask */

#define GPIO_OFFD_OFFD4_Pos         20                                          /*!< GPIO OFFD: OFFD4 Position */
#define GPIO_OFFD_OFFD4_Msk         (1ul << GPIO_OFFD_OFFD4_Pos)                /*!< GPIO OFFD: OFFD4 Mask */

#define GPIO_OFFD_OFFD3_Pos         19                                          /*!< GPIO OFFD: OFFD3 Position */
#define GPIO_OFFD_OFFD3_Msk         (1ul << GPIO_OFFD_OFFD3_Pos)                /*!< GPIO OFFD: OFFD3 Mask */

#define GPIO_OFFD_OFFD2_Pos         18                                          /*!< GPIO OFFD: OFFD2 Position */
#define GPIO_OFFD_OFFD2_Msk         (1ul << GPIO_OFFD_OFFD2_Pos)                /*!< GPIO OFFD: OFFD2 Mask */

#define GPIO_OFFD_OFFD1_Pos         17                                          /*!< GPIO OFFD: OFFD1 Position */
#define GPIO_OFFD_OFFD1_Msk         (1ul << GPIO_OFFD_OFFD1_Pos)                /*!< GPIO OFFD: OFFD1 Mask */

#define GPIO_OFFD_OFFD0_Pos         16                                          /*!< GPIO OFFD: OFFD0 Position */
#define GPIO_OFFD_OFFD0_Msk         (1ul << GPIO_OFFD_OFFD0_Pos)                /*!< GPIO OFFD: OFFD0 Mask */

/* GPIO DOUT Bit Field Definitions */                                           
#define GPIO_DOUT_DOUT_Pos          0                                           /*!< GPIO DOUT: DOUT Position */
#define GPIO_DOUT_DOUT_Msk          (0xFFFFul << GPIO_DOUT_DOUT_Pos)            /*!< GPIO DOUT: DOUT Mask */

/* GPIO DMASK Bit Field Definitions */
#define GPIO_DMASK_DMASK15_Pos      15                                          /*!< GPIO DMASK: DMASK15 Position */
#define GPIO_DMASK_DMASK15_Msk      (1ul << GPIO_DMASK_DMASK15_Pos)             /*!< GPIO DMASK: DMASK15 Mask */

#define GPIO_DMASK_DMASK14_Pos      14                                          /*!< GPIO DMASK: DMASK14 Position */
#define GPIO_DMASK_DMASK14_Msk      (1ul << GPIO_DMASK_DMASK14_Pos)             /*!< GPIO DMASK: DMASK14 Mask */

#define GPIO_DMASK_DMASK13_Pos      13                                          /*!< GPIO DMASK: DMASK13 Position */
#define GPIO_DMASK_DMASK13_Msk      (1ul << GPIO_DMASK_DMASK13_Pos)             /*!< GPIO DMASK: DMASK13 Mask */

#define GPIO_DMASK_DMASK12_Pos      12                                          /*!< GPIO DMASK: DMASK12 Position */
#define GPIO_DMASK_DMASK12_Msk      (1ul << GPIO_DMASK_DMASK12_Pos)             /*!< GPIO DMASK: DMASK12 Mask */

#define GPIO_DMASK_DMASK11_Pos      11                                          /*!< GPIO DMASK: DMASK11 Position */
#define GPIO_DMASK_DMASK11_Msk      (1ul << GPIO_DMASK_DMASK11_Pos)             /*!< GPIO DMASK: DMASK11 Mask */

#define GPIO_DMASK_DMASK10_Pos      10                                          /*!< GPIO DMASK: DMASK10 Position */
#define GPIO_DMASK_DMASK10_Msk      (1ul << GPIO_DMASK_DMASK10_Pos)             /*!< GPIO DMASK: DMASK10 Mask */

#define GPIO_DMASK_DMASK9_Pos       9                                           /*!< GPIO DMASK: DMASK9 Position */
#define GPIO_DMASK_DMASK9_Msk       (1ul << GPIO_DMASK_DMASK9_Pos)              /*!< GPIO DMASK: DMASK9 Mask */

#define GPIO_DMASK_DMASK8_Pos       8                                           /*!< GPIO DMASK: DMASK8 Position */
#define GPIO_DMASK_DMASK8_Msk       (1ul << GPIO_DMASK_DMASK8_Pos)              /*!< GPIO DMASK: DMASK8 Mask */

#define GPIO_DMASK_DMASK7_Pos       7                                           /*!< GPIO DMASK: DMASK7 Position */
#define GPIO_DMASK_DMASK7_Msk       (1ul << GPIO_DMASK_DMASK7_Pos)              /*!< GPIO DMASK: DMASK7 Mask */

#define GPIO_DMASK_DMASK6_Pos       6                                           /*!< GPIO DMASK: DMASK6 Position */
#define GPIO_DMASK_DMASK6_Msk       (1ul << GPIO_DMASK_DMASK6_Pos)              /*!< GPIO DMASK: DMASK6 Mask */

#define GPIO_DMASK_DMASK5_Pos       5                                           /*!< GPIO DMASK: DMASK5 Position */
#define GPIO_DMASK_DMASK5_Msk       (1ul << GPIO_DMASK_DMASK5_Pos)              /*!< GPIO DMASK: DMASK5 Mask */

#define GPIO_DMASK_DMASK4_Pos       4                                           /*!< GPIO DMASK: DMASK4 Position */
#define GPIO_DMASK_DMASK4_Msk       (1ul << GPIO_DMASK_DMASK4_Pos)              /*!< GPIO DMASK: DMASK4 Mask */

#define GPIO_DMASK_DMASK3_Pos       3                                           /*!< GPIO DMASK: DMASK3 Position */
#define GPIO_DMASK_DMASK3_Msk       (1ul << GPIO_DMASK_DMASK3_Pos)              /*!< GPIO DMASK: DMASK3 Mask */

#define GPIO_DMASK_DMASK2_Pos       2                                           /*!< GPIO DMASK: DMASK2 Position */
#define GPIO_DMASK_DMASK2_Msk       (1ul << GPIO_DMASK_DMASK2_Pos)              /*!< GPIO DMASK: DMASK2 Mask */

#define GPIO_DMASK_DMASK1_Pos       1                                           /*!< GPIO DMASK: DMASK1 Position */
#define GPIO_DMASK_DMASK1_Msk       (1ul << GPIO_DMASK_DMASK1_Pos)              /*!< GPIO DMASK: DMASK1 Mask */

#define GPIO_DMASK_DMASK0_Pos       0                                           /*!< GPIO DMASK: DMASK0 Position */
#define GPIO_DMASK_DMASK0_Msk       (1ul << GPIO_DMASK_DMASK0_Pos)              /*!< GPIO DMASK: DMASK0 Mask */

/* GPIO PIN Bit Field Definitions */
#define GPIO_PIN_PIN_Pos            0                                           /*!< GPIO PIN: PIN Position */   
#define GPIO_PIN_PIN_Msk            (0xFFFFul << GPIO_PIN_PIN_Pos)              /*!< GPIO PIN: PIN Mask */

/* GPIO DBEN Bit Field Definitions */
#define GPIO_DBEN_DBEN15_Pos        15                                          /*!< GPIO DBEN: DBEN15 Position */
#define GPIO_DBEN_DBEN15_Msk        (1ul << GPIO_DBEN_DBEN15_Pos)               /*!< GPIO DBEN: DBEN15 Mask */

#define GPIO_DBEN_DBEN14_Pos        14                                          /*!< GPIO DBEN: DBEN14 Position */
#define GPIO_DBEN_DBEN14_Msk        (1ul << GPIO_DBEN_DBEN14_Pos)               /*!< GPIO DBEN: DBEN14 Mask */

#define GPIO_DBEN_DBEN13_Pos        13                                          /*!< GPIO DBEN: DBEN13 Position */
#define GPIO_DBEN_DBEN13_Msk        (1ul << GPIO_DBEN_DBEN13_Pos)               /*!< GPIO DBEN: DBEN13 Mask */

#define GPIO_DBEN_DBEN12_Pos        12                                          /*!< GPIO DBEN: DBEN12 Position */
#define GPIO_DBEN_DBEN12_Msk        (1ul << GPIO_DBEN_DBEN12_Pos)               /*!< GPIO DBEN: DBEN12 Mask */

#define GPIO_DBEN_DBEN11_Pos        11                                          /*!< GPIO DBEN: DBEN11 Position */
#define GPIO_DBEN_DBEN11_Msk        (1ul << GPIO_DBEN_DBEN11_Pos)               /*!< GPIO DBEN: DBEN11 Mask */

#define GPIO_DBEN_DBEN10_Pos        10                                          /*!< GPIO DBEN: DBEN10 Position */
#define GPIO_DBEN_DBEN10_Msk        (1ul << GPIO_DBEN_DBEN10_Pos)               /*!< GPIO DBEN: DBEN10 Mask */

#define GPIO_DBEN_DBEN9_Pos         9                                           /*!< GPIO DBEN: DBEN9 Position */
#define GPIO_DBEN_DBEN9_Msk         (1ul << GPIO_DBEN_DBEN9_Pos)                /*!< GPIO DBEN: DBEN9 Mask */

#define GPIO_DBEN_DBEN8_Pos         8                                           /*!< GPIO DBEN: DBEN8 Position */
#define GPIO_DBEN_DBEN8_Msk         (1ul << GPIO_DBEN_DBEN8_Pos)                /*!< GPIO DBEN: DBEN8 Mask */

#define GPIO_DBEN_DBEN7_Pos         7                                           /*!< GPIO DBEN: DBEN7 Position */
#define GPIO_DBEN_DBEN7_Msk         (1ul << GPIO_DBEN_DBEN7_Pos)                /*!< GPIO DBEN: DBEN7 Mask */

#define GPIO_DBEN_DBEN6_Pos         6                                           /*!< GPIO DBEN: DBEN6 Position */
#define GPIO_DBEN_DBEN6_Msk         (1ul << GPIO_DBEN_DBEN6_Pos)                /*!< GPIO DBEN: DBEN6 Mask */

#define GPIO_DBEN_DBEN5_Pos         5                                           /*!< GPIO DBEN: DBEN5 Position */
#define GPIO_DBEN_DBEN5_Msk         (1ul << GPIO_DBEN_DBEN5_Pos)                /*!< GPIO DBEN: DBEN5 Mask */

#define GPIO_DBEN_DBEN4_Pos         4                                           /*!< GPIO DBEN: DBEN4 Position */
#define GPIO_DBEN_DBEN4_Msk         (1ul << GPIO_DBEN_DBEN4_Pos)                /*!< GPIO DBEN: DBEN4 Mask */

#define GPIO_DBEN_DBEN3_Pos         3                                           /*!< GPIO DBEN: DBEN3 Position */
#define GPIO_DBEN_DBEN3_Msk         (1ul << GPIO_DBEN_DBEN3_Pos)                /*!< GPIO DBEN: DBEN3 Mask */

#define GPIO_DBEN_DBEN2_Pos         2                                           /*!< GPIO DBEN: DBEN2 Position */
#define GPIO_DBEN_DBEN2_Msk         (1ul << GPIO_DBEN_DBEN2_Pos)                /*!< GPIO DBEN: DBEN2 Mask */

#define GPIO_DBEN_DBEN1_Pos         1                                           /*!< GPIO DBEN: DBEN1 Position */
#define GPIO_DBEN_DBEN1_Msk         (1ul << GPIO_DBEN_DBEN1_Pos)                /*!< GPIO DBEN: DBEN1 Mask */

#define GPIO_DBEN_DBEN0_Pos         0                                           /*!< GPIO DBEN: DBEN0 Position */
#define GPIO_DBEN_DBEN0_Msk         (1ul << GPIO_DBEN_DBEN0_Pos)                /*!< GPIO DBEN: DBEN0 Mask */

/* GPIO IMD Bit Field Definitions */
#define GPIO_IMD_IMD15_Pos          15                                          /*!< GPIO IMD: IMD15 Position */
#define GPIO_IMD_IMD15_Msk          (1ul << GPIO_IMD_IMD15_Pos)                 /*!< GPIO IMD: IMD15 Mask */

#define GPIO_IMD_IMD14_Pos          14                                          /*!< GPIO IMD: IMD14 Position */
#define GPIO_IMD_IMD14_Msk          (1ul << GPIO_IMD_IMD14_Pos)                 /*!< GPIO IMD: IMD14 Mask */

#define GPIO_IMD_IMD13_Pos          13                                          /*!< GPIO IMD: IMD13 Position */
#define GPIO_IMD_IMD13_Msk          (1ul << GPIO_IMD_IMD13_Pos)                 /*!< GPIO IMD: IMD13 Mask */

#define GPIO_IMD_IMD12_Pos          12                                          /*!< GPIO IMD: IMD12 Position */
#define GPIO_IMD_IMD12_Msk          (1ul << GPIO_IMD_IMD12_Pos)                 /*!< GPIO IMD: IMD12 Mask */

#define GPIO_IMD_IMD11_Pos          11                                          /*!< GPIO IMD: IMD11 Position */
#define GPIO_IMD_IMD11_Msk          (1ul << GPIO_IMD_IMD11_Pos)                 /*!< GPIO IMD: IMD11 Mask */

#define GPIO_IMD_IMD10_Pos          10                                          /*!< GPIO IMD: IMD10 Position */
#define GPIO_IMD_IMD10_Msk          (1ul << GPIO_IMD_IMD10_Pos)                 /*!< GPIO IMD: IMD10 Mask */

#define GPIO_IMD_IMD9_Pos           9                                           /*!< GPIO IMD: IMD9 Position */
#define GPIO_IMD_IMD9_Msk           (1ul << GPIO_IMD_IMD9_Pos)                  /*!< GPIO IMD: IMD9 Mask */

#define GPIO_IMD_IMD8_Pos           8                                           /*!< GPIO IMD: IMD8 Position */
#define GPIO_IMD_IMD8_Msk           (1ul << GPIO_IMD_IMD8_Pos)                  /*!< GPIO IMD: IMD8 Mask */

#define GPIO_IMD_IMD7_Pos           7                                           /*!< GPIO IMD: IMD7 Position */
#define GPIO_IMD_IMD7_Msk           (1ul << GPIO_IMD_IMD7_Pos)                  /*!< GPIO IMD: IMD7 Mask */

#define GPIO_IMD_IMD6_Pos           6                                           /*!< GPIO IMD: IMD6 Position */
#define GPIO_IMD_IMD6_Msk           (1ul << GPIO_IMD_IMD6_Pos)                  /*!< GPIO IMD: IMD6 Mask */

#define GPIO_IMD_IMD5_Pos           5                                           /*!< GPIO IMD: IMD5 Position */
#define GPIO_IMD_IMD5_Msk           (1ul << GPIO_IMD_IMD5_Pos)                  /*!< GPIO IMD: IMD5 Mask */

#define GPIO_IMD_IMD4_Pos           4                                           /*!< GPIO IMD: IMD4 Position */
#define GPIO_IMD_IMD4_Msk           (1ul << GPIO_IMD_IMD4_Pos)                  /*!< GPIO IMD: IMD4 Mask */

#define GPIO_IMD_IMD3_Pos           3                                           /*!< GPIO IMD: IMD3 Position */
#define GPIO_IMD_IMD3_Msk           (1ul << GPIO_IMD_IMD3_Pos)                  /*!< GPIO IMD: IMD3 Mask */

#define GPIO_IMD_IMD2_Pos           2                                           /*!< GPIO IMD: IMD2 Position */
#define GPIO_IMD_IMD2_Msk           (1ul << GPIO_IMD_IMD2_Pos)                  /*!< GPIO IMD: IMD2 Mask */

#define GPIO_IMD_IMD1_Pos           1                                           /*!< GPIO IMD: IMD1 Position */
#define GPIO_IMD_IMD1_Msk           (1ul << GPIO_IMD_IMD1_Pos)                  /*!< GPIO IMD: IMD1 Mask */

#define GPIO_IMD_IMD0_Pos           0                                           /*!< GPIO IMD: IMD0 Position */
#define GPIO_IMD_IMD0_Msk           (1ul << GPIO_IMD_IMD0_Pos)                  /*!< GPIO IMD: IMD0 Mask */

/* GPIO IEN Bit Field Definitions */
#define GPIO_IEN_IR_EN15_Pos        31                                          /*!< GPIO IEN: IR_EN15 Position */
#define GPIO_IEN_IR_EN15_Msk        (1ul << GPIO_IEN_IR_EN15_Pos)               /*!< GPIO IEN: IR_EN15 Mask */

#define GPIO_IEN_IR_EN14_Pos        30                                          /*!< GPIO IEN: IR_EN14 Position */
#define GPIO_IEN_IR_EN14_Msk        (1ul << GPIO_IEN_IR_EN14_Pos)               /*!< GPIO IEN: IR_EN14 Mask */

#define GPIO_IEN_IR_EN13_Pos        29                                          /*!< GPIO IEN: IR_EN13 Position */
#define GPIO_IEN_IR_EN13_Msk        (1ul << GPIO_IEN_IR_EN13_Pos)               /*!< GPIO IEN: IR_EN13 Mask */

#define GPIO_IEN_IR_EN12_Pos        28                                          /*!< GPIO IEN: IR_EN12 Position */
#define GPIO_IEN_IR_EN12_Msk        (1ul << GPIO_IEN_IR_EN12_Pos)               /*!< GPIO IEN: IR_EN12 Mask */

#define GPIO_IEN_IR_EN11_Pos        27                                          /*!< GPIO IEN: IR_EN11 Position */
#define GPIO_IEN_IR_EN11_Msk        (1ul << GPIO_IEN_IR_EN11_Pos)               /*!< GPIO IEN: IR_EN11 Mask */

#define GPIO_IEN_IR_EN10_Pos        26                                          /*!< GPIO IEN: IR_EN10 Position */
#define GPIO_IEN_IR_EN10_Msk        (1ul << GPIO_IEN_IR_EN10_Pos)               /*!< GPIO IEN: IR_EN10 Mask */

#define GPIO_IEN_IR_EN9_Pos         25                                          /*!< GPIO IEN: IR_EN9 Position */
#define GPIO_IEN_IR_EN9_Msk         (1ul << GPIO_IEN_IR_EN9_Pos)                /*!< GPIO IEN: IR_EN9 Mask */

#define GPIO_IEN_IR_EN8_Pos         24                                          /*!< GPIO IEN: IR_EN8 Position */
#define GPIO_IEN_IR_EN8_Msk         (1ul << GPIO_IEN_IR_EN8_Pos)                /*!< GPIO IEN: IR_EN8 Mask */

#define GPIO_IEN_IR_EN7_Pos         23                                          /*!< GPIO IEN: IR_EN7 Position */
#define GPIO_IEN_IR_EN7_Msk         (1ul << GPIO_IEN_IR_EN7_Pos)                /*!< GPIO IEN: IR_EN7 Mask */

#define GPIO_IEN_IR_EN6_Pos         22                                          /*!< GPIO IEN: IR_EN6 Position */
#define GPIO_IEN_IR_EN6_Msk         (1ul << GPIO_IEN_IR_EN6_Pos)                /*!< GPIO IEN: IR_EN6 Mask */

#define GPIO_IEN_IR_EN5_Pos         21                                          /*!< GPIO IEN: IR_EN5 Position */
#define GPIO_IEN_IR_EN5_Msk         (1ul << GPIO_IEN_IR_EN5_Pos)                /*!< GPIO IEN: IR_EN5 Mask */

#define GPIO_IEN_IR_EN4_Pos         20                                          /*!< GPIO IEN: IR_EN4 Position */
#define GPIO_IEN_IR_EN4_Msk         (1ul << GPIO_IEN_IR_EN4_Pos)                /*!< GPIO IEN: IR_EN4 Mask */

#define GPIO_IEN_IR_EN3_Pos         19                                          /*!< GPIO IEN: IR_EN3 Position */
#define GPIO_IEN_IR_EN3_Msk         (1ul << GPIO_IEN_IR_EN3_Pos)                /*!< GPIO IEN: IR_EN3 Mask */

#define GPIO_IEN_IR_EN2_Pos         18                                          /*!< GPIO IEN: IR_EN2 Position */
#define GPIO_IEN_IR_EN2_Msk         (1ul << GPIO_IEN_IR_EN2_Pos)                /*!< GPIO IEN: IR_EN2 Mask */

#define GPIO_IEN_IR_EN1_Pos         17                                          /*!< GPIO IEN: IR_EN1 Position */
#define GPIO_IEN_IR_EN1_Msk         (1ul << GPIO_IEN_IR_EN1_Pos)                /*!< GPIO IEN: IR_EN1 Mask */

#define GPIO_IEN_IR_EN0_Pos         16                                          /*!< GPIO IEN: IR_EN0 Position */
#define GPIO_IEN_IR_EN0_Msk         (1ul << GPIO_IEN_IR_EN0_Pos)                /*!< GPIO IEN: IR_EN0 Mask */

#define GPIO_IEN_IF_EN15_Pos        15                                          /*!< GPIO IEN: IF_EN15 Position */
#define GPIO_IEN_IF_EN15_Msk        (1ul << GPIO_IEN_IF_EN15_Pos)               /*!< GPIO IEN: IF_EN15 Mask */

#define GPIO_IEN_IF_EN14_Pos        14                                          /*!< GPIO IEN: IF_EN14 Position */
#define GPIO_IEN_IF_EN14_Msk        (1ul << GPIO_IEN_IF_EN14_Pos)               /*!< GPIO IEN: IF_EN14 Mask */

#define GPIO_IEN_IF_EN13_Pos        13                                          /*!< GPIO IEN: IF_EN13 Position */
#define GPIO_IEN_IF_EN13_Msk        (1ul << GPIO_IEN_IF_EN13_Pos)               /*!< GPIO IEN: IF_EN13 Mask */

#define GPIO_IEN_IF_EN12_Pos        12                                          /*!< GPIO IEN: IF_EN12 Position */
#define GPIO_IEN_IF_EN12_Msk        (1ul << GPIO_IEN_IF_EN12_Pos)               /*!< GPIO IEN: IF_EN12 Mask */

#define GPIO_IEN_IF_EN11_Pos        11                                          /*!< GPIO IEN: IF_EN11 Position */
#define GPIO_IEN_IF_EN11_Msk        (1ul << GPIO_IEN_IF_EN11_Pos)               /*!< GPIO IEN: IF_EN11 Mask */

#define GPIO_IEN_IF_EN10_Pos        10                                          /*!< GPIO IEN: IF_EN10 Position */
#define GPIO_IEN_IF_EN10_Msk        (1ul << GPIO_IEN_IF_EN10_Pos)               /*!< GPIO IEN: IF_EN10 Mask */

#define GPIO_IEN_IF_EN9_Pos         9                                           /*!< GPIO IEN: IF_EN9 Position */
#define GPIO_IEN_IF_EN9_Msk         (1ul << GPIO_IEN_IF_EN9_Pos)                /*!< GPIO IEN: IF_EN9 Mask */

#define GPIO_IEN_IF_EN8_Pos         8                                           /*!< GPIO IEN: IF_EN8 Position */
#define GPIO_IEN_IF_EN8_Msk         (1ul << GPIO_IEN_IF_EN8_Pos)                /*!< GPIO IEN: IF_EN8 Mask */

#define GPIO_IEN_IF_EN7_Pos         7                                           /*!< GPIO IEN: IF_EN7 Position */
#define GPIO_IEN_IF_EN7_Msk         (1ul << GPIO_IEN_IF_EN7_Pos)                /*!< GPIO IEN: IF_EN7 Mask */

#define GPIO_IEN_IF_EN6_Pos         6                                           /*!< GPIO IEN: IF_EN6 Position */
#define GPIO_IEN_IF_EN6_Msk         (1ul << GPIO_IEN_IF_EN6_Pos)                /*!< GPIO IEN: IF_EN6 Mask */

#define GPIO_IEN_IF_EN5_Pos         5                                           /*!< GPIO IEN: IF_EN5 Position */
#define GPIO_IEN_IF_EN5_Msk         (1ul << GPIO_IEN_IF_EN5_Pos)                /*!< GPIO IEN: IF_EN5 Mask */

#define GPIO_IEN_IF_EN4_Pos         4                                           /*!< GPIO IEN: IF_EN4 Position */
#define GPIO_IEN_IF_EN4_Msk         (1ul << GPIO_IEN_IF_EN4_Pos)                /*!< GPIO IEN: IF_EN4 Mask */

#define GPIO_IEN_IF_EN3_Pos         3                                           /*!< GPIO IEN: IF_EN3 Position */
#define GPIO_IEN_IF_EN3_Msk         (1ul << GPIO_IEN_IF_EN3_Pos)                /*!< GPIO IEN: IF_EN3 Mask */

#define GPIO_IEN_IF_EN2_Pos         2                                           /*!< GPIO IEN: IF_EN2 Position */
#define GPIO_IEN_IF_EN2_Msk         (1ul << GPIO_IEN_IF_EN2_Pos)                /*!< GPIO IEN: IF_EN2 Mask */

#define GPIO_IEN_IF_EN1_Pos         1                                           /*!< GPIO IEN: IF_EN1 Position */
#define GPIO_IEN_IF_EN1_Msk         (1ul << GPIO_IEN_IF_EN1_Pos)                /*!< GPIO IEN: IF_EN1 Mask */

#define GPIO_IEN_IF_EN0_Pos         0                                           /*!< GPIO IEN: IF_EN0 Position */
#define GPIO_IEN_IF_EN0_Msk         (1ul << GPIO_IEN_IF_EN0_Pos)                /*!< GPIO IEN: IF_EN0 Mask */

/* GPIO ISRC Bit Field Definitions */
#define GPIO_ISRC_ISRC_Pos          0                                           /*!< GPIO ISRC: ISRC Position */
#define GPIO_ISRC_ISRC_Msk          (0xFFFFul << GPIO_ISRC_ISRC_Pos)            /*!< GPIO ISRC: ISRC Mask */

/* GPIO DBNCECON Bit Field Definitions */
#define GPIO_DBNCECON_ICLK_ON_Pos   5                                           /*!< GPIO DBNCECON: ICLK_ON  Position */
#define GPIO_DBNCECON_ICLK_ON_Msk   (1ul << GPIO_DBNCECON_ICLK_ON_Pos)          /*!< GPIO DBNCECON: ICLK_ON  Mask */

#define GPIO_DBNCECON_DBCLKSRC_Pos  4                                           /*!< GPIO DBNCECON: DBCLKSRC Position */
#define GPIO_DBNCECON_DBCLKSRC_Msk  (1ul << GPIO_DBNCECON_DBCLKSRC_Pos)         /*!< GPIO DBNCECON: DBCLKSRC Mask */

#define GPIO_DBNCECON_DBCLKSEL_Pos  0                                           /*!< GPIO DBNCECON: DBCLKSEL Position */
#define GPIO_DBNCECON_DBCLKSEL_Msk  (0xFul << GPIO_DBNCECON_DBCLKSEL_Pos)       /*!< GPIO DBNCECON: DBCLKSEL Mask */
/*@}*/ /* end of group NUC123_GPIO */



/*------------------------- UART Interface Controller ------------------------*/

/** @addtogroup NUC123_UART NUC123 UART
  Memory Mapped Structure for NUC123 Series UART Serial Interface Controller
  @{
 */
typedef struct
{
                                
    union {                             
    __IO uint32_t DATA;                 

    /**
     * THR
     * ===================================================================================================
     * Offset: 0x00 Transmit Holding DATA
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |          |bitTransmittedData
     * |        |          |Transmit Holding Register
     * |        |          |By writing to this register, the UART will send out an 8-bit data through the Tx pin (LSB 
     * |        |          |first).
     */    
    __IO uint32_t THR;                  

    /**
     * RBR
     * ===================================================================================================
     * Offset: 0x00 Receive Buffer
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |          |Receive Buffer Register
     * |        |          |By reading this register, the UART will return an 8-bit data received from Rx pin (LSB first).
     */    
    __IO uint32_t RBR;                  
    };

    /**
     * IER
     * ===================================================================================================
     * Offset: 0x04  UART Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |RDA_IEN   |Receive Data Available Interrupt Enable.
     * |        |          |0 = Mask off INT_RDA
     * |        |          |1 = Enable INT_RDA
     * |[1]     |THRE_IEN  |Transmit Holding Register Empty Interrupt Enable
     * |        |          |0 = Mask off INT_THRE
     * |        |          |1 = Enable INT_THRE
     * |[2]     |RLS_IEN   |Receive Line Status Interrupt Enable 
     * |        |          |0 = Mask off INT_RLS
     * |        |          |1 = Enable INT_RLS
     * |[3]     |Modem_IEN |Modem Status Interrupt Enable 
     * |        |          |0 = Mask off INT_MOS
     * |        |          |1 = Enable INT_MOS
     * |[4]     |RTO_IEN   |Rx Time out Interrupt Enable
     * |        |          |0 = Mask off INT_tout
     * |        |          |1 = Enable INT_tout 
     * |[5]     |BUF_ERR_IEN|Buffer Error Interrupt Enable
     * |        |          |0 = Mask off INT_Buf_err
     * |        |          |1 = Enable INT_Buf_err
     * |[6]     |Wake_EN   |Wake up CPU function enable 
     * |        |          |0 = Disable UART wake up CPU function
     * |        |          |1 = Enable wake up function, when the system is in deep sleep mode, an external /CTS 
     * |        |          |change will wake up CPU from deep sleep mode.
     * |[11]    |Time_Out_EN|Time-Out Counter Enable
     * |        |          |1 = Enable Time-out counter.
     * |        |          |0 = Disable Time-out counter.
     * |[12]    |Auto_RTS_EN|RTS Auto Flow Control Enable 
     * |        |          |1 = Enable RTS auto flow control.
     * |        |          |0 = Disable RTS auto flow control.
     * |        |          |When RTS auto-flow is enabled, if the number of bytes in the Rx FIFO equals the UA_FCR 
     * |[RTS_Tri_Lev], the UART will dessert RTS signal.|[13]      |Auto_CTS_EN
     * |        |          |CTS Auto Flow Control Enable
     * |        |          |1 = Enable CTS auto flow control.
     * |        |          |0 = Disable CTS auto flow control.
     * |        |          |When CTS auto-flow is enabled, the UART will send data to external device when CTS input 
     * |        |          |assert (UART will not send data to device until CTS is asserted).
     */    
    __IO uint32_t IER;                  

    /**
     * FCR
     * ===================================================================================================
     * Offset: 0x08  UART FIFO Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |RFR       |Rx Software Reset
     * |        |          |When Rx_RST is set, all the bytes in the transmit FIFO and Rx internal state machine are 
     * |        |          |cleared.
     * |        |          |0 = Writing 0 to this bit has no effect.
     * |        |          |1 = Writing 1 to this bit will reset the Rx internal state machine and pointers.
     * |        |          |Note: This bit will auto clear and takes at least 3 UART engine clock cycles.
     * |[2]     |TFR       |Tx Software Reset
     * |        |          |When Tx_RST is set, all the bytes in the transmit FIFO and Tx internal state machine are 
     * |        |          |cleared.
     * |        |          |0 = Writing 0 to this bit has no effect.
     * |        |          |1 = Writing 1 to this bit will reset the Tx internal state machine and pointers.
     * |        |          |Note: This bit will auto clear and takes at least 3 UART engine clock cycles.
     * |[7:4]   |RFITL     |Word Length Select
     * |        |          |INTR_RDA Tigger Level(Bytes)
     * |        |          |0000 = 01 Bytes
     * |        |          |0001 = 04 Bytes
     * |        |          |0010 = 08 Bytes
     * |        |          |0011 = 14 Bytes
     * |[8]     |RX_DIS    |Receiver Disable register.
     * |        |          |The receiver is disabled or not (set 1 is disable receiver)
     * |        |          |1: Disable Receiver
     * |        |          |0: Enable Receiver
     * |        |          |Note: This field is used for RS-485 Normal Multi-drop mode. It should be programmed before 
     * |        |          |RS-485 enable function in UA_FUN_SEL. FUN_SEL is programmed.
     * |[19:16] |RTS_Tri_Lev|Word Length Select
     * |        |          |0000 = 01 Bytes
     * |        |          |0001 = 04 Bytes
     * |        |          |0010 = 08 Bytes
     * |        |          |0011 = 14 Bytes
     */    
    __IO uint32_t FCR;                  

    /**
     * LCR
     * ===================================================================================================
     * Offset: 0x0C  UART Line Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |WLS       |Word Length Select
     * |        |          |00 = 5 bits
     * |        |          |01 = 6 bits
     * |        |          |10 = 7 bits
     * |        |          |11 = 8 bits
     * |[2]     |NSB       |Number of "STOP bit"
     * |        |          |0= One "STOP bit" is generated in the transmitted data
     * |        |          |1= One and a half "STOP bit" is generated in the transmitted data when 5-bit word length is selected;
     * |        |          |Two "STOP bit" is generated when 6-, 7- and 8-bit word length is selected.
     * |[3]     |PBE       |Parity Bit Enable
     * |        |          |0 = Parity bit is not generated (transmit data) or checked (receive data) during transfer.
     * |        |          |1 = Parity bit is generated or checked between the "last data word bit" and "stop bit" of the serial data.
     * |[4]     |EPE       |Even Parity Enable
     * |        |          |0 = Odd number of logic 1's are transmitted or checked in the data word and parity bits.
     * |        |          |1 = Even number of logic 1's are transmitted or checked in the data word and parity bits.
     * |        |          |This bit has effect only when bit 3 (parity bit enable) is set.
     * |[5]     |SPE       |Stick Parity Enable 
     * |        |          |0 = Disable stick parity 
     * |        |          |1 = When bits PBE , EPE and SPE are set, the parity bit is transmitted and checked as cleared. When 
     * |        |          |PBE and SPE are set and EPE is cleared, the parity bit is transmitted and checked as set.
     * |[6]     |BCB       |Break Control Bit 
     * |        |          |When this bit is set to logic 1, the serial data output (Tx) is forced to the Spacing State (logic 0). This bit 
     * |        |          |acts only on Tx and has no effect on the transmitter logic.
     */    
    __IO uint32_t LCR;                  

    /**
     * MCR
     * ===================================================================================================
     * Offset: 0x10  UART Modem Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |RTS       |RTS (Request-To-Send) Signal 
     * |        |          |0: Drive RTS pin to logic 1 (If the Lev_RTS set to low level triggered).
     * |        |          |1: Drive RTS pin to logic 0 (If the Lev_RTS set to low level triggered).
     * |        |          |0: Drive RTS pin to logic 0 (If the Lev_RTS set to high level triggered).
     * |        |          |1: Drive RTS pin to logic 1 (If the Lev_RTS set to high level triggered).
     * |[9]     |Lev_RTS   |RTS Trigger Level 
     * |        |          |This bit can change the RTS trigger level.
     * |        |          |0= low level triggered
     * |        |          |1= high level triggered
     * |[13]    |RTS_St    |RTS Pin State 
     * |        |          |This bit is the pin status of RTS.
     */    
    __IO uint32_t MCR;                  

    /**
     * MSR
     * ===================================================================================================
     * Offset: 0x14  UART Modem Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |DCTSF     |Detect CTS State Change Flag 
     * |        |          |This bit is set whenever CTS input has change state, and it will generate Modem interrupt to CPU 
     * |        |          |when IER [Modem_IEN].
     * |        |          |NOTE: This bit is cleared by writing 1 to itself.
     * |[4]     |CTS_St    |CTS Pin Status 
     * |        |          |This bit is the pin status of CTS. 
     * |[8]     |Lev_CTS   |CTS Trigger Level
     * |        |          |This bit can change the CTS trigger level.
     * |        |          |0= low level triggered
     * |        |          |1= high level triggered
     */    
    __IO uint32_t MSR;                  

    /**
     * FSR
     * ===================================================================================================
     * Offset: 0x18  UART FIFO Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |Rx_Over_IF|Rx overflow Error IF (Read Only) 
     * |        |          |This bit is set when Rx FIFO overflow.
     * |        |          |If the number of bytes of received data is greater than Rx FIFO(UA_RBR) size, 16 bytes of 
     * |        |          |UART0/UART1, this bit will be set.
     * |        |          |NOTE: This bit is cleared by writing 1 to itself.
     * |[3]     |RS-       |485_Add_Det
     * |        |          |RS-485 Address Byte Detection Flag
     * |        |          |This bit is set to logic 1 and set UA_RS-485_CSR [RS-485_Add_EN] whenever in RS-485 
     * |        |          |mode the receiver detect any address byte received address byte character (bit9 = '1') bit", 
     * |        |          |and it is reset whenever the CPU writes 1 to this bit.
     * |        |          |Note: This field is used for RS-485 mode.
     * |[4]     |PEF       |Parity Error Flag
     * |        |          |This bit is set to logic 1 whenever the received character does not have a valid "parity bit", 
     * |        |          |and is reset whenever the CPU writes 1 to this bit.
     * |[5]     |FEF       |Framing Error Flag
     * |        |          |This bit is set to logic 1 whenever the received character does not have a valid "stop bit" (that 
     * |        |          |is, the stop bit following the last data bit or parity bit is detected as a logic 0), and is reset 
     * |        |          |whenever the CPU writes 1 to this bit.
     * |[6]     |BIF       |Break Interrupt Flag
     * |        |          |This bit is set to a logic 1 whenever the received data input(Rx) is held in the "spacing state" 
     * |        |          |(logic 0) for longer than a full word transmission time (that is, the total time of "start bit" + data 
     * |        |          |bits + parity + stop bits) and is reset whenever the CPU writes 1 to this bit.
     * |[13:8]  |Rx_Pointer|Rx FIFO pointer (Read Only)
     * |        |          |This field indicates the Rx FIFO Buffer Pointer. When UART receives one byte from external 
     * |        |          |device, Rx_Pointer increases one. When one byte of Rx FIFO is read by CPU, Rx_Pointer 
     * |        |          |decreases one.
     * |[14]    |Rx_Empty  |Receiver FIFO Empty (Read Only)
     * |        |          |This bit initiate Rx FIFO empty or not.
     * |        |          |When the last byte of Rx FIFO has been read by CPU, hardware sets this bit high. It will be 
     * |        |          |cleared when UART receives any new data.
     * |[15]    |Rx_Full   |Receiver FIFO Full (Read Only)
     * |        |          |This bit initiates Rx FIFO full or not.
     * |        |          |This bit is set when Rx_Pointer is equal to 16(UART0/UART1), otherwise is cleared by 
     * |        |          |hardware.
     * |[21:16] |Tx_Pointer|TX FIFO Pointer (Read Only)
     * |        |          |This field indicates the Tx FIFO Buffer Pointer. When CPU write one byte into UA_THR, 
     * |        |          |Tx_Pointer increases one. When one byte of Tx FIFO is transferred to Transmitter Shift 
     * |        |          |Register, Tx_Pointer decreases one.
     * |[22]    |Tx_Empty  |Transmitter FIFO Empty (Read Only)
     * |        |          |This bit indicates Tx FIFO empty or not.
     * |        |          |When the last byte of Tx FIFO has been transferred to Transmitter Shift Register, hardware 
     * |        |          |sets this bit high. It will be cleared when writing data into THR (Tx FIFO not empty).
     * |[23]    |Tx_Full   |Transmitter FIFO Full (Read Only)
     * |        |          |This bit indicates Tx FIFO full or not.
     * |        |          |This bit is set when Tx_Pointer is equal to 64/16(UART0/UART1), otherwise is cleared by 
     * |        |          |hardware.
     * |[24]    |Tx_Over_IF|Tx Overflow Error Interrupt Flag (Read Only)
     * |        |          |If Tx FIFO(UA_THR) is full, an additional write to UA_THR will cause this bit to logic 1. 
     * |        |          |NOTE: This bit is cleared by writing 1 to itself.
     * |[28]    |TE_Flag   |Transmitter Empty Flag (Read Only)
     * |        |          |Bit is set by hardware when Tx FIFO(UA_THR) is empty and the STOP bit of the last byte 
     * |        |          |has been transmitted.
     * |        |          |Bit is cleared automatically when Tx FIFO is not empty or the last byte transmission has not 
     * |        |          |completed.
     * |        |          |NOTE: This bit is read only. 
     */    
    __IO uint32_t FSR;                  

    /**
     * ISR
     * ===================================================================================================
     * Offset: 0x1C  UART Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |RDA_IF    |Receive Data Available Interrupt Flag (Read Only).
     * |        |          |When the number of bytes in the Rx FIFO equals the RFITL then the RDA_IF will be set. If 
     * |        |          |IER[RDA_IEN] is enabled, the RDA interrupt will be generated. 
     * |        |          |NOTE: This bit is read only and it will be cleared when the number of unread bytes of Rx FIFO 
     * |        |          |drops below the threshold level (RFITL).
     * |[1]     |THRE_IF   |Transmit Holding Register Empty Interrupt Flag (Read Only). 
     * |        |          |This bit is set when the last data of Tx FIFO is transferred to Transmitter Shift Register. If 
     * |        |          |IER[THRE_IEN] is enabled, the THRE interrupt will be generated.
     * |        |          |NOTE: This bit is read only and it will be cleared when writing data into THR (Tx FIFO not empty).
     * |[2]     |RLS_IF    |Receive Line Interrupt Flag (Read Only).
     * |        |          |In UART mode this bit is set when the Rx receive data have parity error, framing error or break 
     * |        |          |error (at least one of 3 bits, BIF, FEF and PEF, is set). In RS-485 mode, the field includes RS-485 
     * |        |          |Address Byte Detection Flag. If IER[RLS_IEN] is enabled, the RLS interrupt will be generated.
     * |        |          |NOTE: This bit is read only and reset to 0 when all bits of BIF, FEF, PEF and RS-485_Add_Det 
     * |        |          |are cleared.
     * |[3]     |Modem_IF  |MODEM Interrupt Flag (Read Only) 
     * |        |          |This bit is set when the CTS pin has state change (DCTSF=1). If IER[Modem_IEN] is enabled, the 
     * |        |          |Modem interrupt will be generated.
     * |        |          |NOTE: This bit is read only and reset to 0 when bit DCTSF is cleared by a write 1 on DCTSF.
     * |[4]     |Tout_IF   |Time Out Interrupt Flag (Read Only)
     * |        |          |This bit is set when the Rx FIFO is not empty and no activities occur in the Rx FIFO and the time 
     * |        |          |out counter equal to TOIC. If IER [Tout_IEN] is enabled, the Tout interrupt will be generated. 
     * |        |          |NOTE: This bit is read only and user can read UA_RBR (Rx is in active) to clear it.
     * |[5]     |Buf_Err_IF|Buffer Error Interrupt Flag (Read Only)
     * |        |          |This bit is set when the Tx or Rx FIFO overflows (Tx_Over_IF or Rx_Over_IF is set). When 
     * |        |          |Buf_Err_IF is set, the transfer maybe not correct. If IER[Buf_Err_IEN] is enabled, the buffer error 
     * |        |          |interrupt will be generated.
     * |        |          |NOTE: This bit is cleared when both Tx_Over_IF and Rx_Over_IF are cleared. 
     * |[8]     |RDA_INT   |Receive Data Available Interrupt Indicator to Interrupt Controller (INT_RDA).
     * |        |          |An AND output with inputs of RDA_IEN and RDA_IF
     * |[9]     |THRE_INT  |Transmit Holding Register Empty Interrupt Indicator to Interrupt Controller (INT_THRE).
     * |        |          |An AND output with inputs of THRE_IEN and THRE_IF
     * |[10]    |RLS_INT   |Receive Line Status Interrupt Indicator to Interrupt Controller (INT_RLS). 
     * |        |          |An AND output with inputs of RLS_IEN and RLS_IF
     * |        |          |Note: In RS-485 mode, the field includes RS-485 Address Byte Detection Flag.
     * |[11]    |Modem_INT |MODEM Status Interrupt Indicator to Interrupt Controller (INT_MOS). 
     * |        |          |An AND output with inputs of Modem_IEN and Modem_IF
     * |[12]    |Tout_INT  |Time Out Interrupt Indicator to Interrupt Controller (INT_Tout)
     * |        |          |An AND output with inputs of RTO_IEN and Tout_IF
     * |[13]    |Buf_Err_INT|Buffer Error Interrupt Indicator to Interrupt Controller (INT_Buf_err)
     * |        |          |An AND output with inputs of BUF_ERR_IEN and Buf_Err_IF
     */    
    __IO uint32_t ISR;                  

    /**
     * TOR
     * ===================================================================================================
     * Offset: 0x20  UART Time Out Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[6:0]   |TOIC      |Time Out Interrupt Comparator
     * |        |          |The time out counter resets and starts counting (the counting clock = baud rate) whenever the RX FIFO 
     * |        |          |receives a new data word. Once the content of time out counter (TOUT_CNT) is equal to that of time out 
     * |        |          |interrupt comparator (TOIC), a receiver time out interrupt (INT_TOUT) is generated if UA_IER[RTO_IEN]. 
     * |        |          |A new incoming data word or RX FIFO empty clears INT_TOUT. 
     * |[15:8]  |DLY       |TX Delay time value
     * |        |          |This field is use to programming the transfer delay time between the last stop bit leaving the TX-FIFO 
     * |        |          |and the de-assertion of by setting UA_TOR. DLY register.
     */    
    __IO uint32_t TOR;                  

    /**
     * BAUD
     * ===================================================================================================
     * Offset: 0x24  UART Baud Rate Divisor Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |BRD_LowByte|Baud Rate Divider 
     * |        |          |The low byte of the baud rate divider
     * |[15:8]  |BRD_HighByte|Baud Rate Divider 
     * |        |          |The high byte of the baud rate divider
     * |[27:24] |Divider_X |Divider X
     * |        |          |The baud rate divider M = X+1.
     * |[28]    |DIV_X_ONE |Divider X equal 1
     * |        |          |0 = Divider M = X (the equation of M = X+1, but Divider_X[27:24] must > 8)
     * |        |          |1 = Divider M = 1 (the equation of M = 1, but BRD[15:0] must > 3).
     * |[29]    |DIV_X_EN  |Divider X Enable
     * |        |          |The BRD = Baud Rate Divider, and the baud rate equation is  
     * |        |          |Baud Rate = Clock / [ M * (BRD + 2) ] ; The default value of M is 16.
     * |        |          |0 = Disable divider X (the equation of M = 16)
     * |        |          |1 = Enable divider X (the equation of M = X+1, but Divider_X[27:24 must > 8).
     * |        |          |NOTE: When in IrDA mode, this bit must disable.
     */    
    __IO uint32_t BAUD;                 

    /**
     * IRCR
     * ===================================================================================================
     * Offset: 0x28  UART IrDA Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |Tx_SELECT |Tx_SELECT
     * |        |          |1: Enable IrDA transmitter
     * |        |          |0: Enable IrDA receiver
     * |[2]     |LB        |IrDA loop back mode for self test.
     * |        |          |1: Enable IrDA loop back mode
     * |        |          |0: Disable IrDA loop back mode
     * |[5]     |INV_Tx    |INV_Tx
     * |        |          |1= Inverse Tx output signal
     * |        |          |0= No inversion
     * |[6]     |INV_Rx    |INV_Rx
     * |        |          |1= Inverse Rx input signal
     * |        |          |0= No inversion
     */    
    __IO uint32_t IRCR;                 

    /**
     * ALT_CSR
     * ===================================================================================================
     * Offset: 0x2C  UART Alternate Control/Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8]     |RS-485_NMM|RS-485 Normal Multi-drop Operation Mode (NMM)
     * |        |          |1: Enable RS-485 Normal Multi-drop Operation Mode (NMM)
     * |        |          |0: Disable RS-485 Normal Multi-drop Operation Mode (NMM)
     * |        |          |Note: It can't be active with RS-485_AAD operation mode.
     * |[9]     |RS-485_AAD|RS-485 Auto Address Detection Operation Mode (AAD)
     * |        |          |1: Enable RS-485 Auto Address Detection Operation Mode (AAD)
     * |        |          |0: Disable RS-485 Auto Address Detection Operation Mode (AAD)
     * |        |          |Note: It can't be active with RS-485_NMM operation mode.
     * |[10]    |RS-485_AUD|RS-485 Auto Direction Mode (AUD)
     * |        |          |1: Enable RS-485 Auto Direction Mode (AUD)
     * |        |          |0: Disable RS-485 Auto Direction Mode (AUD)
     * |        |          |Note: It can be active with RS-485_AAD or RS-485_NMM operation mode.
     * |[15]    |RS-485_Add_EN|RS-485 Address Detection Enable
     * |        |          |This bit is use to enable RS-485 address detection mode. 
     * |        |          |1: Enable address detection mode
     * |        |          |0: Disable address detection mode 
     * |        |          |Note: This field is used for RS-485 any operation mode.
     * |[31:24] |ADDR_MATCH|Address match value register
     * |        |          |This field contains the RS-485 address match values.
     * |        |          |Note: This field is used for RS-485 auto address detection mode.
     */    
    __IO uint32_t ALT_CSR;               

    /**
     * FUN_SEL
     * ===================================================================================================
     * Offset: 0x30  UART Function Select Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |FUN_SEL   |Function Select Enable
     * |        |          |00 = UART Function.
     * |        |          |01 = Reserved.
     * |        |          |10 = Enable IrDA Function.
     * |        |          |11 = Enable RS-485 Function.
     */    
    __IO uint32_t FUN_SEL;               
} UART_T;




/* UART THR Bit Field Definitions */
#define UART_THR_THR_Pos         0                                          /*!< UART THR: THR Position  */
#define UART_THR_THR_Msk        (0xFFul << UART_THR_THR_Pos)                 /*!< UART THR: THR Mask      */

/* UART RBR Bit Field Definitions */
#define UART_RBR_RBR_Pos         0                                          /*!< UART RBR: RBR Posistion */
#define UART_RBR_RBR_Msk        (0xFFul << UART_RBR_RBR_Pos)                 /*!< UART RBR: RBR Mask      */

/* UART IER Bit Field Definitions */
#define UART_IER_DMA_RX_EN_Pos      15                                      /*!< UART IER: RX DMA Enable Posistion */  
#define UART_IER_DMA_RX_EN_Msk      (1ul << UART_IER_DMA_RX_EN_Pos)         /*!< UART IER: RX DMA Enable Mask      */  

#define UART_IER_DMA_TX_EN_Pos      14                                      /*!< UART IER: TX DMA Enable Posistion */  
#define UART_IER_DMA_TX_EN_Msk      (1ul << UART_IER_DMA_TX_EN_Pos)         /*!< UART IER: TX DMA Enable Mask      */  

#define UART_IER_AUTO_CTS_EN_Pos    13                                      /*!< UART IER: AUTO_CTS_EN Posistion      */
#define UART_IER_AUTO_CTS_EN_Msk    (1ul << UART_IER_AUTO_CTS_EN_Pos)       /*!< UART IER: AUTO_CTS_EN Mask           */

#define UART_IER_AUTO_RTS_EN_Pos    12                                      /*!< UART IER: AUTO_RTS_EN Posistion      */
#define UART_IER_AUTO_RTS_EN_Msk    (1ul << UART_IER_AUTO_RTS_EN_Pos)       /*!< UART IER: AUTO_RTS_EN Mask           */

#define UART_IER_TIME_OUT_EN_Pos    11                                      /*!< UART IER: TIME_OUT_EN Posistion      */
#define UART_IER_TIME_OUT_EN_Msk    (1ul << UART_IER_TIME_OUT_EN_Pos)       /*!< UART IER: TIME_OUT_EN Mask           */

#define UART_IER_WAKE_EN_Pos        6                                       /*!< UART IER: WAKE_EN Posistion          */
#define UART_IER_WAKE_EN_Msk        (1ul << UART_IER_WAKE_EN_Pos)           /*!< UART IER: WAKE_EN Mask               */

#define UART_IER_BUF_ERR_IEN_Pos    5                                       /*!< UART IER: BUF_ERR_IEN Posistion      */
#define UART_IER_BUF_ERR_IEN_Msk    (1ul << UART_IER_BUF_ERR_IEN_Pos)       /*!< UART IER: BUF_ERR_IEN Mask           */

#define UART_IER_RTO_IEN_Pos        4                                       /*!< UART IER: RTO_IEN Posistion          */
#define UART_IER_RTO_IEN_Msk        (1ul << UART_IER_RTO_IEN_Pos)           /*!< UART IER: RTO_IEN Mask               */

#define UART_IER_MODEM_IEN_Pos      3                                       /*!< UART IER: MODEM_IEN Posistion        */
#define UART_IER_MODEM_IEN_Msk      (1ul << UART_IER_MODEM_IEN_Pos)         /*!< UART IER: MODEM_IEN Mask             */

#define UART_IER_RLS_IEN_Pos        2                                       /*!< UART IER: RLS_IEN Posistion          */
#define UART_IER_RLS_IEN_Msk        (1ul << UART_IER_RLS_IEN_Pos)           /*!< UART IER: RLS_IEN Mask               */

#define UART_IER_THRE_IEN_Pos       1                                       /*!< UART IER: THRE_IEN Posistion         */
#define UART_IER_THRE_IEN_Msk       (1ul << UART_IER_THRE_IEN_Pos)          /*!< UART IER: THRE_IEN Mask              */

#define UART_IER_RDA_IEN_Pos        0                                       /*!< UART IER: RDA_IEN Position           */
#define UART_IER_RDA_IEN_Msk        (1ul << UART_IER_RDA_IEN_Pos)           /*!< UART IER: RDA_IEN Mask               */

/* UART FCR Bit Field Definitions */
#define UART_FCR_RTS_TRI_LEV_Pos    16                                      /*!< UART FCR: RTS_TRI_LEV Position       */
#define UART_FCR_RTS_TRI_LEV_Msk    (0xFul << UART_FCR_RTS_TRI_LEV_Pos)     /*!< UART FCR: RTS_TRI_LEV Mask           */

#define UART_FCR_RX_DIS_Pos         8                                       /*!< UART FCR: RX_DIS Position            */
#define UART_FCR_RX_DIS_Msk         (1ul << UART_FCR_RX_DIS_Pos)            /*!< UART FCR: RX_DIS Mask                */

#define UART_FCR_RFITL_Pos          4                                       /*!< UART FCR: RFITL Position             */
#define UART_FCR_RFITL_Msk          (0xFul << UART_FCR_RFITL_Pos)           /*!< UART FCR: RFITL Mask                 */

#define UART_FCR_TFR_Pos            2                                       /*!< UART FCR: TFR Position               */
#define UART_FCR_TFR_Msk            (1ul << UART_FCR_TFR_Pos)               /*!< UART FCR: TFR Mask                   */

#define UART_FCR_RFR_Pos            1                                       /*!< UART FCR: RFR Position               */
#define UART_FCR_RFR_Msk            (1ul << UART_FCR_RFR_Pos)               /*!< UART FCR: RFR Mask                   */

/* UART LCR Bit Field Definitions */
#define UART_LCR_BCB_Pos            6                                       /*!< UART LCR: BCB Position               */
#define UART_LCR_BCB_Msk            (1ul << UART_LCR_BCB_Pos)               /*!< UART LCR: BCB Mask                   */

#define UART_LCR_SPE_Pos            5                                       /*!< UART LCR: SPE Position               */
#define UART_LCR_SPE_Msk            (1ul << UART_LCR_SPE_Pos)               /*!< UART LCR: SPE Mask                   */

#define UART_LCR_EPE_Pos            4                                       /*!< UART LCR: EPE Position               */
#define UART_LCR_EPE_Msk            (1ul << UART_LCR_EPE_Pos)               /*!< UART LCR: EPE Mask                   */

#define UART_LCR_PBE_Pos            3                                       /*!< UART LCR: PBE Position               */
#define UART_LCR_PBE_Msk            (1ul << UART_LCR_PBE_Pos)               /*!< UART LCR: PBE Mask                   */

#define UART_LCR_NSB_Pos            2                                       /*!< UART LCR: NSB Position               */
#define UART_LCR_NSB_Msk            (1ul << UART_LCR_NSB_Pos)               /*!< UART LCR: NSB Mask                   */

#define UART_LCR_WLS_Pos            0                                       /*!< UART LCR: WLS Position               */
#define UART_LCR_WLS_Msk            (0x3ul << UART_LCR_WLS_Pos)             /*!< UART LCR: WLS Mask                   */

/* UART MCR Bit Field Definitions */
#define UART_MCR_RTS_ST_Pos         13                                      /*!< UART MCR: RTS_ST Position            */
#define UART_MCR_RTS_ST_Msk         (1ul << UART_MCR_RTS_ST_Pos)            /*!< UART MCR: RTS_ST Mask                */

#define UART_MCR_LEV_RTS_Pos        9                                       /*!< UART MCR: LEV_RTS Position           */
#define UART_MCR_LEV_RTS_Msk        (1ul << UART_MCR_LEV_RTS_Pos)           /*!< UART MCR: LEV_RTS Mask               */

#define UART_MCR_RTS_Pos            1                                       /*!< UART MCR: RTS Position               */
#define UART_MCR_RTS_Msk            (1ul << UART_MCR_RTS_Pos)               /*!< UART MCR: RTS Mask                   */

/* UART MSR Bit Field Definitions */
#define UART_MSR_LEV_CTS_Pos        8                                       /*!< UART MSR: LEV_CTS Position           */
#define UART_MSR_LEV_CTS_Msk        (1ul << UART_MSR_LEV_CTS_Pos)           /*!< UART MSR: LEV_CTS Mask               */

#define UART_MSR_CTS_ST_Pos         4                                       /*!< UART MSR: CTS_ST Position            */
#define UART_MSR_CTS_ST_Msk         (1ul << UART_MSR_CTS_ST_Pos)            /*!< UART MSR: CTS_ST Mask                */

#define UART_MSR_DCTSF_Pos          0                                       /*!< UART MSR: DCTST Position             */
#define UART_MSR_DCTSF_Msk          (1ul << UART_MSR_DCTSF_Pos)             /*!< UART MSR: DCTST Mask                 */


/* UART FSR Bit Field Definitions */
#define UART_FSR_TE_FLAG_Pos        28                                      /*!< UART FSR: TE_FLAG Position           */
#define UART_FSR_TE_FLAG_Msk        (1ul << UART_FSR_TE_FLAG_Pos)           /*!< UART FSR: TE_FLAG Mask               */

#define UART_FSR_TX_OVER_IF_Pos     24                                      /*!< UART FSR: TX_OVER_IF Position        */
#define UART_FSR_TX_OVER_IF_Msk     (1ul << UART_FSR_TX_OVER_IF_Pos)        /*!< UART FSR: TX_OVER_IF Mask            */

#define UART_FSR_TX_FULL_Pos        23                                      /*!< UART FSR: TX_FULL Position           */
#define UART_FSR_TX_FULL_Msk        (1ul << UART_FSR_TX_FULL_Pos)           /*!< UART FSR: TX_FULL Mask               */

#define UART_FSR_TX_EMPTY_Pos       22                                      /*!< UART FSR: TX_EMPTY Position          */
#define UART_FSR_TX_EMPTY_Msk       (1ul << UART_FSR_TX_EMPTY_Pos)          /*!< UART FSR: TX_EMPTY Mask              */

#define UART_FSR_TX_POINTER_Pos     16                                      /*!< UART FSR: TX_POINTER Position        */
#define UART_FSR_TX_POINTER_Msk     (0x3Ful << UART_FSR_TX_POINTER_Pos)     /*!< UART FSR: TX_POINTER Mask            */

#define UART_FSR_RX_FULL_Pos        15                                      /*!< UART FSR: RX_FULL Position           */
#define UART_FSR_RX_FULL_Msk        (1ul << UART_FSR_RX_FULL_Pos)           /*!< UART FSR: RX_FULL Mask               */

#define UART_FSR_RX_EMPTY_Pos       14                                      /*!< UART FSR: RX_EMPTY Position          */
#define UART_FSR_RX_EMPTY_Msk       (1ul << UART_FSR_RX_EMPTY_Pos)          /*!< UART FSR: RX_EMPTY Mask              */

#define UART_FSR_RX_POINTER_Pos     8                                       /*!< UART FSR: RX_POINTERS Position       */
#define UART_FSR_RX_POINTER_Msk     (0x3Ful << UART_FSR_RX_POINTER_Pos)     /*!< UART FSR: RX_POINTER Mask            */

#define UART_FSR_BIF_Pos            6                                       /*!< UART FSR: BIF Position               */
#define UART_FSR_BIF_Msk            (1ul << UART_FSR_BIF_Pos)               /*!< UART FSR: BIF Mask                   */

#define UART_FSR_FEF_Pos            5                                       /*!< UART FSR: FEF Position               */
#define UART_FSR_FEF_Msk            (1ul << UART_FSR_FEF_Pos)               /*!< UART FSR: FEF Mask                   */

#define UART_FSR_PEF_Pos            4                                       /*!< UART FSR: PEF Position               */
#define UART_FSR_PEF_Msk            (1ul << UART_FSR_PEF_Pos)               /*!< UART FSR: PEF Mask                   */

#define UART_FSR_RS485_ADD_DETF_Pos 3                                       /*!< UART FSR: RS485_ADD_DETF Position    */
#define UART_FSR_RS485_ADD_DETF_Msk (1ul << UART_FSR_RS485_ADD_DETF_Pos)    /*!< UART FSR: RS485_ADD_DETF Mask        */

#define UART_FSR_RX_OVER_IF_Pos     0                                       /*!< UART FSR: RX_OVER_IF Position        */
#define UART_FSR_RX_OVER_IF_Msk     (1ul << UART_FSR_RX_OVER_IF_Pos)        /*!< UART FSR: RX_OVER_IF Mask            */

/* UART ISR Bit Field Definitions */
#define UART_ISR_HW_BUF_ERR_INT_Pos        29                                       /*!< UART ISR: HW BUF_ERR_INT Position       */
#define UART_ISR_HW_BUF_ERR_INT_Msk        (1ul << UART_ISR_HW_BUF_ERR_INT_Pos)     /*!< UART ISR: HW BUF_ERR_INT Mask           */

#define UART_ISR_HW_TOUT_INT_Pos           28                                       /*!< UART ISR: HW TOUT_INT Position          */
#define UART_ISR_HW_TOUT_INT_Msk           (1ul << UART_ISR_HW_TOUT_INT_Pos)        /*!< UART ISR: HW TOUT_INT Mask              */

#define UART_ISR_HW_MODEM_INT_Pos          27                                       /*!< UART ISR: HW MODEM_INT Position         */
#define UART_ISR_HW_MODEM_INT_Msk          (1ul << UART_ISR_HW_MODEM_INT_Pos)       /*!< UART ISR: HW MODEM_INT Mask             */
    
#define UART_ISR_HW_RLS_INT_Pos            26                                       /*!< UART ISR: HW RLS_INT Position           */
#define UART_ISR_HW_RLS_INT_Msk            (1ul << UART_ISR_HW_RLS_INT_Pos)         /*!< UART ISR: HW RLS_INT Position           */

#define UART_ISR_HW_BUF_ERR_IF_Pos         21                                       /*!< UART ISR: HW BUF_ERR_IF Position       */
#define UART_ISR_HW_BUF_ERR_IF_Msk         (1ul << UART_ISR_HW_BUF_ERR_IF_Pos)      /*!< UART ISR: HW BUF_ERR_IF Mask           */

#define UART_ISR_HW_TOUT_IF_Pos            20                                       /*!< UART ISR: HW TOUT_IF Position          */
#define UART_ISR_HW_TOUT_IF_Msk            (1ul << UART_ISR_HW_TOUT_IF_Pos)        /*!< UART ISR: HW TOUT_IF Mask              */

#define UART_ISR_HW_MODEM_IF_Pos           19                                       /*!< UART ISR: HW MODEM_IF Position         */
#define UART_ISR_HW_MODEM_IF_Msk           (1ul << UART_ISR_HW_MODEM_IF_Pos)        /*!< UART ISR: HW MODEM_IF Mask             */

#define UART_ISR_HW_RLS_IF_Pos             18                                       /*!< UART ISR: HW RLS_IF Position           */
#define UART_ISR_HW_RLS_IF_Msk             (1ul << UART_ISR_HW_RLS_IF_Pos)          /*!< UART ISR: HW RLS_IF Mark               */

#define UART_ISR_BUF_ERR_INT_Pos    13                                      /*!< UART ISR: BUF_ERR_INT Position       */
#define UART_ISR_BUF_ERR_INT_Msk    (1ul << UART_ISR_BUF_ERR_INT_Pos)       /*!< UART ISR: BUF_ERR_INT Mask           */

#define UART_ISR_TOUT_INT_Pos       12                                      /*!< UART ISR: TOUT_INT Position          */
#define UART_ISR_TOUT_INT_Msk       (1ul << UART_ISR_TOUT_INT_Pos)          /*!< UART ISR: TOUT_INT Mask              */

#define UART_ISR_MODEM_INT_Pos      11                                      /*!< UART ISR: MODEM_INT Position         */
#define UART_ISR_MODEM_INT_Msk      (1ul << UART_ISR_MODEM_INT_Pos)         /*!< UART ISR: MODEM_INT Mask             */

#define UART_ISR_RLS_INT_Pos        10                                      /*!< UART ISR: RLS_INT Position           */
#define UART_ISR_RLS_INT_Msk        (1ul << UART_ISR_RLS_INT_Pos)           /*!< UART ISR: RLS_INT Mask               */

#define UART_ISR_THRE_INT_Pos       9                                       /*!< UART ISR: THRE_INT Position          */
#define UART_ISR_THRE_INT_Msk       (1ul << UART_ISR_THRE_INT_Pos)          /*!< UART ISR: THRE_INT Mask              */

#define UART_ISR_RDA_INT_Pos        8                                       /*!< UART ISR: RDA_INT Position           */
#define UART_ISR_RDA_INT_Msk        (1ul << UART_ISR_RDA_INT_Pos)           /*!< UART ISR: RDA_INT Mask               */
           
#define UART_ISR_BUF_ERR_IF_Pos     5                                       /*!< UART ISR: BUF_ERR_IF Position        */
#define UART_ISR_BUF_ERR_IF_Msk     (1ul << UART_ISR_BUF_ERR_IF_Pos)        /*!< UART ISR: BUF_ERR_IF Mask            */

#define UART_ISR_TOUT_IF_Pos        4                                       /*!< UART ISR: TOUT_IF Position           */
#define UART_ISR_TOUT_IF_Msk        (1ul << UART_ISR_TOUT_IF_Pos)           /*!< UART ISR: TOUT_IF Mask               */

#define UART_ISR_MODEM_IF_Pos       3                                       /*!< UART ISR: MODEM_IF Position          */
#define UART_ISR_MODEM_IF_Msk       (1ul << UART_ISR_MODEM_IF_Pos)          /*!< UART ISR: MODEM_IF Mask              */

#define UART_ISR_RLS_IF_Pos         2                                       /*!< UART ISR: RLS_IF Position            */
#define UART_ISR_RLS_IF_Msk         (1ul << UART_ISR_RLS_IF_Pos)            /*!< UART ISR: RLS_IF Mask                */

#define UART_ISR_THRE_IF_Pos        1                                       /*!< UART ISR: THRE_IF Position           */
#define UART_ISR_THRE_IF_Msk        (1ul << UART_ISR_THRE_IF_Pos)           /*!< UART ISR: THRE_IF Mask               */

#define UART_ISR_RDA_IF_Pos         0                                       /*!< UART ISR: RDA_IF Position            */
#define UART_ISR_RDA_IF_Msk         (1ul << UART_ISR_RDA_IF_Pos)            /*!< UART ISR: RDA_IF Mask                */


/* UART TOR Bit Field Definitions */
#define UART_TOR_DLY_Pos           8                                        /*!< UART TOR: DLY Position               */
#define UART_TOR_DLY_Msk           (0xFFul << UART_TOR_DLY_Pos)             /*!< UART TOR: DLY Mask                   */

#define UART_TOR_TOIC_Pos          0                                        /*!< UART TOR: TOIC Position              */
#define UART_TOR_TOIC_Msk          (0xFFul << UART_TOR_TOIC_Pos)

/* UART BAUD Bit Field Definitions */
#define UART_BAUD_DIV_X_EN_Pos    29                                        /*!< UART BARD: DIV_X_EN Position         */
#define UART_BAUD_DIV_X_EN_Msk    (1ul << UART_BAUD_DIV_X_EN_Pos)           /*!< UART BARD: DIV_X_EN Mask             */

#define UART_BAUD_DIV_X_ONE_Pos   28                                        /*!< UART BARD: DIV_X_ONE Position        */
#define UART_BAUD_DIV_X_ONE_Msk   (1ul << UART_BAUD_DIV_X_ONE_Pos)          /*!< UART BARD: DIV_X_ONE Mask            */

#define UART_BAUD_DIVIDER_X_Pos   24                                        /*!< UART BARD: DIVIDER_X Position        */
#define UART_BAUD_DIVIDER_X_Msk   (0xFul << UART_BAUD_DIVIDER_X_Pos)        /*!< UART BARD: DIVIDER_X Mask            */

#define UART_BAUD_BRD_Pos         0                                         /*!< UART BARD: BRD Position              */
#define UART_BAUD_BRD_Msk         (0xFFFFul << UART_BAUD_BRD_Pos)           /*!< UART BARD: BRD Mask                  */

/* UART IRCR Bit Field Definitions */
#define UART_IRCR_INV_RX_Pos      6                                         /*!< UART IRCR: INV_RX Position           */
#define UART_IRCR_INV_RX_Msk     (1ul << UART_IRCR_INV_RX_Pos)              /*!< UART IRCR: INV_RX Mask               */

#define UART_IRCR_INV_TX_Pos      5                                         /*!< UART IRCR: INV_TX Position           */
#define UART_IRCR_INV_TX_Msk     (1ul << UART_IRCR_INV_TX_Pos)              /*!< UART IRCR: INV_TX Mask               */

#define UART_IRCR_TX_SELECT_Pos   1                                         /*!< UART IRCR: TX_SELECT Position        */
#define UART_IRCR_TX_SELECT_Msk   (1ul << UART_IRCR_TX_SELECT_Pos)          /*!< UART IRCR: TX_SELECT Mask            */

/* UART ALT_CSR Bit Field Definitions */
#define UART_ALT_CSR_ADDR_MATCH_Pos      24                                      /*!< UART ALT_CSR: ADDR_MATCH Position    */
#define UART_ALT_CSR_ADDR_MATCH_Msk     (0xFFul << UART_ALT_CSR_ADDR_MATCH_Pos)  /*!< UART ALT_CSR: ADDR_MATCH Mask        */

#define UART_ALT_CSR_RS485_ADD_EN_Pos   15                                       /*!< UART ALT_CSR: RS485_ADD_EN Position  */
#define UART_ALT_CSR_RS485_ADD_EN_Msk   (1ul << UART_ALT_CSR_RS485_ADD_EN_Pos)   /*!< UART ALT_CSR: RS485_ADD_EN Mask      */

#define UART_ALT_CSR_RS485_AUD_Pos      10                                       /*!< UART ALT_CSR: RS485_AUD Position     */
#define UART_ALT_CSR_RS485_AUD_Msk      (1ul << UART_ALT_CSR_RS485_AUD_Pos)      /*!< UART ALT_CSR: RS485_AUD Mask         */

#define UART_ALT_CSR_RS485_AAD_Pos      9                                        /*!< UART ALT_CSR: RS485_AAD Position     */
#define UART_ALT_CSR_RS485_AAD_Msk      (1ul << UART_ALT_CSR_RS485_AAD_Pos)      /*!< UART ALT_CSR: RS485_AAD Mask         */

#define UART_ALT_CSR_RS485_NMM_Pos      8                                        /*!< UART ALT_CSR: RS485_NMM Position     */
#define UART_ALT_CSR_RS485_NMM_Msk      (1ul << UART_ALT_CSR_RS485_NMM_Pos)      /*!< UART ALT_CSR: RS485_NMM Mask         */

/* UART FUN_SEL Bit Field Definitions */
#define UART_FUN_SEL_FUN_SEL_Pos        0                                        /*!< UART FUN_SEL: FUN_SEL Position       */
#define UART_FUN_SEL_FUN_SEL_Msk       (0x3ul << UART_FUN_SEL_FUN_SEL_Pos)       /*!< UART FUN_SEL: FUN_SEL Mask           */

/*@}*/ /* end of group NUC123_UART */

/*----------------------------- Timer Controller (TMR) -----------------------------*/
/** @addtogroup NUC123_TIMER NUC123 TIMER
  Memory Mapped Structure for NUC123 Series Timer Controller
  @{
 */
typedef struct
{
    /**
     * TCSR
     * ===================================================================================================
     * Offset: 0x00  Timer Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  TCSR;                

    /**
     * TCMPR
     * ===================================================================================================
     * Offset: 0x04  Timer Compare Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  TCMPR;		        

    /**
     * TISR
     * ===================================================================================================
     * Offset: 0x08  Timer Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  TISR;		        

    /**
     * TDR
     * ===================================================================================================
     * Offset: 0x0C  Timer Data Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  TDR;			        

    /**
     * TCAP
     * ===================================================================================================
     * Offset: 0x10  Timer Capture Data Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  TCAP;		        

    /**
     * TEXCON
     * ===================================================================================================
     * Offset: 0x14  Timer External Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  TEXCON;	            

    /**
     * TEXISR
     * ===================================================================================================
     * Offset: 0x18  Timer External Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  TEXISR;	            
} TIMER_T;

/* TIMER TCSR Bit Field Definitions */
#define TIMER_TCSR_DBGACK_TMR_Pos   31											/*!< TIMER TCSR: DBGACK_TMR Position */
#define TIMER_TCSR_DBGACK_TMR_Msk   (1ul << TIMER_TCSR_DBGACK_TMR_Pos)          /*!< TIMER TCSR: DBGACK_TMR Mask */

#define TIMER_TCSR_CEN_Pos          30											/*!< TIMER TCSR: CEN Position */
#define TIMER_TCSR_CEN_Msk          (1ul << TIMER_TCSR_CEN_Pos)				    /*!< TIMER TCSR: CEN Mask */

#define TIMER_TCSR_IE_Pos           29											/*!< TIMER TCSR: IE Position */
#define TIMER_TCSR_IE_Msk           (1ul << TIMER_TCSR_IE_Pos)					/*!< TIMER TCSR: IE Mask */
                                                                                 
#define TIMER_TCSR_MODE_Pos         27											/*!< TIMER TCSR: MODE Position */
#define TIMER_TCSR_MODE_Msk         (0x3ul << TIMER_TCSR_MODE_Pos)				/*!< TIMER TCSR: MODE Mask */

#define TIMER_TCSR_CRST_Pos         26											/*!< TIMER TCSR: CRST Position */
#define TIMER_TCSR_CRST_Msk         (1ul << TIMER_TCSR_CRST_Pos)				/*!< TIMER TCSR: CRST Mask */

#define TIMER_TCSR_CACT_Pos         25											/*!< TIMER TCSR: CACT Position */
#define TIMER_TCSR_CACT_Msk         (1ul << TIMER_TCSR_CACT_Pos)				/*!< TIMER TCSR: CACT Mask */

#define TIMER_TCSR_CTB_Pos          24											/*!< TIMER TCSR: CTB Position */
#define TIMER_TCSR_CTB_Msk          (1ul << TIMER_TCSR_CTB_Pos)					/*!< TIMER TCSR: CTB Mask */

#define TIMER_TCSR_WAKE_EN_Pos      23											/*!< TIMER TCSR: WAKE_EN Position */
#define TIMER_TCSR_WAKE_EN_Msk      (1ul << TIMER_TCSR_WAKE_EN_Pos)			    /*!< TIMER TCSR: WAKE_EN Mask */

#define TIMER_TCSR_TDR_EN_Pos       16											/*!< TIMER TCSR: TDR_EN Position */
#define TIMER_TCSR_TDR_EN_Msk       (1ul << TIMER_TCSR_TDR_EN_Pos)				/*!< TIMER TCSR: TDR_EN Mask */

#define TIMER_TCSR_PRESCALE_Pos     0											/*!< TIMER TCSR: PRESCALE Position */
#define TIMER_TCSR_PRESCALE_Msk     (0xFFul << TIMER_TCSR_PRESCALE_Pos)			/*!< TIMER TCSR: PRESCALE Mask */

/* TIMER TCMPR Bit Field Definitions */
#define TIMER_TCMP_TCMP_Pos         0											/*!< TIMER TCMPR: TCMP Position */
#define TIMER_TCMP_TCMP_Msk         (0xFFFFFFul << TIMER_TCMP_TCMP_Pos)		    /*!< TIMER TCMPR: TCMP Mask */

/* TIMER TISR Bit Field Definitions */
#define TIMER_TISR_TWF_Pos          1											/*!< TIMER TISR: TWF Position */
#define TIMER_TISR_TWF_Msk          (1ul << TIMER_TISR_TWF_Pos)					/*!< TIMER TISR: TWF Mask */

#define TIMER_TISR_TIF_Pos          0											/*!< TIMER TISR: TIF Position */
#define TIMER_TISR_TIF_Msk          (1ul << TIMER_TISR_TIF_Pos)					/*!< TIMER TISR: TIF Mask */

/* TIMER TDR Bit Field Definitions */
#define TIMER_TDR_TDR_Pos           0								            /*!< TIMER TDR: TDR Position */
#define TIMER_TDR_TDR_Msk           (0xFFFFFFul << TIMER_TDR_TDR_Pos)	        /*!< TIMER TDR: TDR Mask */

/* TIMER TCAP Bit Field Definitions */
#define TIMER_TCAP_TCAP_Pos         0									        /*!< TIMER TCAP: TCAP Position */
#define TIMER_TCAP_TCAP_Msk         (0xFFFFFFul << TIMER_TCAP_TCAP_Pos)         /*!< TIMER TCAP: TCAP Mask */

/* TIMER TEXCON Bit Field Definitions */
#define TIMER_TEXCON_TCDB_Pos       7											/*!< TIMER TEXCON: TCDB Position */
#define TIMER_TEXCON_TCDB_Msk       (1ul << TIMER_TEXCON_TCDB_Pos)				/*!< TIMER TEXCON: TCDB Mask */

#define TIMER_TEXCON_TEXDB_Pos      6											/*!< TIMER TEXCON: TEXDB Position */
#define TIMER_TEXCON_TEXDB_Msk      (1ul << TIMER_TEXCON_TEXDB_Pos)				/*!< TIMER TEXCON: TEXDB Mask */

#define TIMER_TEXCON_TEXIEN_Pos     5											/*!< TIMER TEXCON: TEXIEN Position */
#define TIMER_TEXCON_TEXIEN_Msk     (1ul << TIMER_TEXCON_TEXIEN_Pos)			/*!< TIMER TEXCON: TEXIEN Mask */

#define TIMER_TEXCON_RSTCAPSEL_Pos  4											/*!< TIMER TEXCON: RSTCAPSEL Position */
#define TIMER_TEXCON_RSTCAPSEL_Msk  (1ul << TIMER_TEXCON_RSTCAPSEL_Pos)			/*!< TIMER TEXCON: RSTCAPSEL Mask */

#define TIMER_TEXCON_TEXEN_Pos      3											/*!< TIMER TEXCON: TEXEN Position */
#define TIMER_TEXCON_TEXEN_Msk      (1ul << TIMER_TEXCON_TEXEN_Pos)				/*!< TIMER TEXCON: TEXEN Mask */

#define TIMER_TEXCON_TEX_EDGE_Pos   1											/*!< TIMER TEXCON: TEX_EDGE Position */
#define TIMER_TEXCON_TEX_EDGE_Msk   (0x3ul << TIMER_TEXCON_TEX_EDGE_Pos)		/*!< TIMER TEXCON: TEX_EDGE Mask */

#define TIMER_TEXCON_TX_PHASE_Pos   0											/*!< TIMER TEXCON: TX_PHASE Position */
#define TIMER_TEXCON_TX_PHASE_Msk   (1ul << TIMER_TEXCON_TX_PHASE_Pos)			/*!< TIMER TEXCON: TX_PHASE Mask */

/* TIMER TEXISR Bit Field Definitions */
#define TIMER_TEXISR_TEXIF_Pos      0											/*!< TIMER TEXISR: TEXIF Position */
#define TIMER_TEXISR_TEXIF_Msk      (1ul << TIMER_TEXISR_TEXIF_Pos)				/*!< TIMER TEXISR: TEXIF Mask */
/*@}*/ /* end of group NUC123_TIMER */


/*----------------------------- Watchdog Timer (WDT) -----------------------------*/
/** @addtogroup NUC123_WDT NUC123 WDT
  Memory Mapped Structure for NUC123 Series Watchdog Timer
  @{
 */
typedef struct
{
    /**
     * WTCR
     * ===================================================================================================
     * Offset: 0x00  Watchdog Timer Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WTCR;                 

    /**
     * WTCRALT
     * ===================================================================================================
     * Offset: 0x04  Watchdog Timer Alternative Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WTCRALT;              
} WDT_T;

/* WDT WTCR Bit Field Definitions */
#define WDT_WTCR_DBGACK_WDT_Pos 31                                              /*!< WDT WTCR : DBGACK_WDT Position */
#define WDT_WTCR_DBGACK_WDT_Msk (1ul << WDT_WTCR_DBGACK_WDT_Pos)                /*!< WDT WTCR : DBGACK_WDT Mask */

#define WDT_WTCR_WTIS_Pos       8                                               /*!< WDT WTCR : WTIS Position */
#define WDT_WTCR_WTIS_Msk       (0x7ul << WDT_WTCR_WTIS_Pos)                    /*!< WDT WTCR : WTIS Mask */

#define WDT_WTCR_WTE_Pos        7                                               /*!< WDT WTCR : WTE Position */
#define WDT_WTCR_WTE_Msk        (1ul << WDT_WTCR_WTE_Pos)                       /*!< WDT WTCR : WTE Mask */

#define WDT_WTCR_WTIE_Pos       6                                               /*!< WDT WTCR : WTIE Position */
#define WDT_WTCR_WTIE_Msk       (1ul << WDT_WTCR_WTIE_Pos)                      /*!< WDT WTCR : WTIE Mask */

#define WDT_WTCR_WTWKF_Pos      5                                               /*!< WDT WTCR : WTWKF Position */
#define WDT_WTCR_WTWKF_Msk      (1ul << WDT_WTCR_WTWKF_Pos)                     /*!< WDT WTCR : WTWKF Mask */

#define WDT_WTCR_WTWKE_Pos      4                                               /*!< WDT WTCR : WTWKE Position */
#define WDT_WTCR_WTWKE_Msk      (1ul << WDT_WTCR_WTWKE_Pos)                     /*!< WDT WTCR : WTWKE Mask */

#define WDT_WTCR_WTIF_Pos       3                                               /*!< WDT WTCR : WTIF Position */
#define WDT_WTCR_WTIF_Msk       (1ul << WDT_WTCR_WTIF_Pos)                      /*!< WDT WTCR : WTIF Mask */

#define WDT_WTCR_WTRF_Pos       2                                               /*!< WDT WTCR : WTRF Position */
#define WDT_WTCR_WTRF_Msk       (1ul << WDT_WTCR_WTRF_Pos)                      /*!< WDT WTCR : WTRF Mask */

#define WDT_WTCR_WTRE_Pos       1                                               /*!< WDT WTCR : WTRE Position */
#define WDT_WTCR_WTRE_Msk       (1ul << WDT_WTCR_WTRE_Pos)                      /*!< WDT WTCR : WTRE Mask */

#define WDT_WTCR_WTR_Pos        0                                               /*!< WDT WTCR : WTR Position */
#define WDT_WTCR_WTR_Msk        (1ul << WDT_WTCR_WTR_Pos)                       /*!< WDT WTCR : WTR Mask */

/* WDT WTCRALT Bit Field Definitions */
#define WDT_WTCRALT_WTRDSEL_Pos 0                                               /*!< WDT WTCRALT : WTRDSEL Position */
#define WDT_WTCRALT_WTRDSEL_Msk (0x3ul << WDT_WTCRALT_WTRDSEL_Pos)              /*!< WDT WTCRALT : WTRDSEL Mask */
/*@}*/ /* end of group NUC123_WDT */


/*----------------------------- Window Watchdog Timer (WWDT) -----------------------------*/
/** @addtogroup NUC123_WWDT NUC123 WWDT
  Memory Mapped Structure for NUC123 Series Window Watchdog Timer
  @{
 */
typedef struct
{
    /**
     * WWDTRLD
     * ===================================================================================================
     * Offset: 0x00  Window Watchdog Timer Reload Counter Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WWDTRLD;

    /**
     * WWDTCR
     * ===================================================================================================
     * Offset: 0x04  Window Watchdog Timer Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WWDTCR;

    /**
     * WWDTSR
     * ===================================================================================================
     * Offset: 0x08  Window Watchdog Timer Status Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WWDTSR;

    /**
     * WWDTCVR
     * ===================================================================================================
     * Offset: 0x0C  Window Watchdog Timer Counter Value Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  WWDTCVR;
} WWDT_T;

/* WWDT WWDTRLD Bit Field Definitions */
#define WWDT_WWDTRLD_WWDTRLD_Pos    0                                           /*!< WWDT WWDTRLD : WWDTRLD Position */
#define WWDT_WWDTRLD_WWDTRLD_Msk    (0xFFFFFFFFul << WWDT_WWDTRLD_WWDTRLD_Pos)  /*!< WWDT WWDTRLD : WWDTRLD Mask */

/* WWDT WWDTCR Bit Field Definitions */
#define WWDT_WWDTCR_DBGACK_WWDT_Pos 31                                          /*!< WWDT WWDTCR : DBGACK_WWDT Position */
#define WWDT_WWDTCR_DBGACK_WWDT_Msk (1ul << WWDT_WWDTCR_DBGACK_WWDT_Pos)        /*!< WWDT WWDTCR : DBGACK_WWDT Mask */

#define WWDT_WWDTCR_WINCMP_Pos      16                                          /*!< WWDT WWDTCR : WINCMP Position */
#define WWDT_WWDTCR_WINCMP_Msk      (0x3Ful << WWDT_WWDTCR_WINCMP_Pos)          /*!< WWDT WWDTCR : WINCMP Mask */

#define WWDT_WWDTCR_PERIODSEL_Pos   8                                           /*!< WWDT WWDTCR : PERIODSEL Position */
#define WWDT_WWDTCR_PERIODSEL_Msk   (0xFul << WWDT_WWDTCR_PERIODSEL_Pos)        /*!< WWDT WWDTCR : PERIODSEL Mask */

#define WWDT_WWDTCR_WWDTIE_Pos      1                                           /*!< WWDT WWDTCR : WWDTIE Position */
#define WWDT_WWDTCR_WWDTIE_Msk      (1ul << WWDT_WWDTCR_WWDTIE_Pos)             /*!< WWDT WWDTCR : WWDTIE Mask */

#define WWDT_WWDTCR_WWDTEN_Pos      0                                           /*!< WWDT WWDTCR : WWDTEN Position */
#define WWDT_WWDTCR_WWDTEN_Msk      (1ul << WWDT_WWDTCR_WWDTEN_Pos)             /*!< WWDT WWDTCR : WWDTEN Mask */

/* WWDT WWDTSR Bit Field Definitions */
#define WWDT_WWDTSR_WWDTRF_Pos      1                                           /*!< WWDT WWDTSR : WWDTRF Position */
#define WWDT_WWDTSR_WWDTRF_Msk      (1ul << WWDT_WWDTSR_WWDTRF_Pos)             /*!< WWDT WWDTSR : WWDTRF Mask */

#define WWDT_WWDTSR_WWDTIF_Pos      0                                           /*!< WWDT WWDTSR : WWDTIF Position */
#define WWDT_WWDTSR_WWDTIF_Msk      (1ul << WWDT_WWDTSR_WWDTIF_Pos)             /*!< WWDT WWDTSR : WWDTIF Mask */

/* WWDT WWDTCVR Bit Field Definitions */
#define WWDT_WWDTCVR_WWDTCVAL_Pos   0                                           /*!< WWDT WWDTCVR : WWDTRF Position */
#define WWDT_WWDTCVR_WWDTCVAL_Msk   (0x3Ful << WWDT_WWDTCVR_WWDTCVAL_Pos)       /*!< WWDT WWDTCVR : WWDTRF Mask */
/*@}*/ /* end of group NUC123_WWDT */


/*------------------------- SPI Interface Controller -------------------------*/
/** @addtogroup NUC123_SPI NUC123 SPI
  Memory Mapped Structure for NUC123 Series SPI Controller
  @{
 */
typedef struct
{
    __IO uint32_t CNTRL;      /*!< Offset: 0x00  SPI Control and Status Register   */
    __IO uint32_t DIVIDER;    /*!< Offset: 0x04  SPI Clock Divider Register        */
    __IO uint32_t SSR;        /*!< Offset: 0x08  SPI Slave Select Register         */
    __I  uint32_t RESERVE0;
    __I  uint32_t RX[2];      /*!< Offset: 0x10  Data Receive Register             */
    __I  uint32_t RESERVE1;
    __I  uint32_t RESERVE2;
    __O  uint32_t TX[2];      /*!< Offset: 0x20  Data Transmit Register            */
    __I  uint32_t RESERVE3;
    __I  uint32_t RESERVE4;
    __I  uint32_t RESERVE5;
    __IO uint32_t VARCLK;     /*!< Offset: 0x34  Variable Clock Pattern Register   */
    __IO uint32_t DMA;        /*!< Offset: 0x38  SPI DMA Control Register          */
    __IO uint32_t CNTRL2;     /*!< Offset: 0x3C  SPI Control and Status Register 2 */
    __IO uint32_t FIFO_CTL;   /*!< Offset: 0x40  SPI FIFO Control Register         */
    __IO uint32_t STATUS;     /*!< Offset: 0x44  SPI Status Register               */
} SPI_T;


/* SPI_CNTRL Bit Field Definitions */
#define SPI_CNTRL_TX_FULL_Pos      27                                     /*!< SPI CNTRL: TX_FULL Position */
#define SPI_CNTRL_TX_FULL_Msk      (1ul << SPI_CNTRL_TX_FULL_Pos)         /*!< SPI CNTRL: TX_FULL Mask     */

#define SPI_CNTRL_TX_EMPTY_Pos     26                                     /*!< SPI CNTRL: TX_EMPTY Position */
#define SPI_CNTRL_TX_EMPTY_Msk     (1ul << SPI_CNTRL_TX_EMPTY_Pos)        /*!< SPI CNTRL: TX_EMPTY Mask     */

#define SPI_CNTRL_RX_FULL_Pos      25                                     /*!< SPI CNTRL: RX_FULL Position */
#define SPI_CNTRL_RX_FULL_Msk      (1ul << SPI_CNTRL_RX_FULL_Pos)         /*!< SPI CNTRL: RX_FULL Mask     */

#define SPI_CNTRL_RX_EMPTY_Pos     24                                     /*!< SPI CNTRL: RX_EMPTY Position */
#define SPI_CNTRL_RX_EMPTY_Msk     (1ul << SPI_CNTRL_RX_EMPTY_Pos)        /*!< SPI CNTRL: RX_EMPTY Mask     */

#define SPI_CNTRL_VARCLK_EN_Pos    23                                     /*!< SPI CNTRL: VARCLK_EN Position */
#define SPI_CNTRL_VARCLK_EN_Msk    (1ul << SPI_CNTRL_VARCLK_EN_Pos)       /*!< SPI CNTRL: VARCLK_EN Mask     */

#define SPI_CNTRL_TWOB_Pos         22                                     /*!< SPI CNTRL: TWOB Position */
#define SPI_CNTRL_TWOB_Msk         (1ul << SPI_CNTRL_TWOB_Pos)            /*!< SPI CNTRL: TWOB Mask     */

#define SPI_CNTRL_FIFO_Pos         21                                     /*!< SPI CNTRL: FIFO Position */
#define SPI_CNTRL_FIFO_Msk         (1ul << SPI_CNTRL_FIFO_Pos)            /*!< SPI CNTRL: FIFO Mask     */

#define SPI_CNTRL_REORDER_Pos      19                                     /*!< SPI CNTRL: REORDER Position */
#define SPI_CNTRL_REORDER_Msk      (1ul << SPI_CNTRL_REORDER_Pos)         /*!< SPI CNTRL: REORDER Mask     */

#define SPI_CNTRL_SLAVE_Pos        18                                     /*!< SPI CNTRL: SLAVE Position */
#define SPI_CNTRL_SLAVE_Msk        (1ul << SPI_CNTRL_SLAVE_Pos)           /*!< SPI CNTRL: SLAVE Mask     */

#define SPI_CNTRL_IE_Pos           17                                     /*!< SPI CNTRL: IE Position */
#define SPI_CNTRL_IE_Msk           (1ul << SPI_CNTRL_IE_Pos)              /*!< SPI CNTRL: IE Mask     */

#define SPI_CNTRL_IF_Pos           16                                     /*!< SPI CNTRL: IF Position */
#define SPI_CNTRL_IF_Msk           (1ul << SPI_CNTRL_IF_Pos)              /*!< SPI CNTRL: IF Mask     */

#define SPI_CNTRL_SP_CYCLE_Pos     12                                     /*!< SPI CNTRL: SP_CYCLE Position */
#define SPI_CNTRL_SP_CYCLE_Msk     (0xFul << SPI_CNTRL_SP_CYCLE_Pos)      /*!< SPI CNTRL: SP_CYCLE Mask     */

#define SPI_CNTRL_CLKP_Pos         11                                     /*!< SPI CNTRL: CLKP Position */
#define SPI_CNTRL_CLKP_Msk         (1ul << SPI_CNTRL_CLKP_Pos)            /*!< SPI CNTRL: CLKP Mask     */

#define SPI_CNTRL_LSB_Pos          10                                     /*!< SPI CNTRL: LSB Position */
#define SPI_CNTRL_LSB_Msk          (1ul << SPI_CNTRL_LSB_Pos)             /*!< SPI CNTRL: LSB Mask     */

#define SPI_CNTRL_TX_BIT_LEN_Pos   3                                      /*!< SPI CNTRL: TX_BIT_LEN Position */
#define SPI_CNTRL_TX_BIT_LEN_Msk   (0x1Ful << SPI_CNTRL_TX_BIT_LEN_Pos)   /*!< SPI CNTRL: TX_BIT_LEN Mask     */

#define SPI_CNTRL_TX_NEG_Pos       2                                      /*!< SPI CNTRL: TX_NEG Position */
#define SPI_CNTRL_TX_NEG_Msk       (1ul << SPI_CNTRL_TX_NEG_Pos)          /*!< SPI CNTRL: TX_NEG Mask     */

#define SPI_CNTRL_RX_NEG_Pos       1                                      /*!< SPI CNTRL: RX_NEG Position */
#define SPI_CNTRL_RX_NEG_Msk       (1ul << SPI_CNTRL_RX_NEG_Pos)          /*!< SPI CNTRL: RX_NEG Mask     */

#define SPI_CNTRL_GO_BUSY_Pos      0                                      /*!< SPI CNTRL: GO_BUSY Position */
#define SPI_CNTRL_GO_BUSY_Msk      (1ul << SPI_CNTRL_GO_BUSY_Pos)         /*!< SPI CNTRL: GO_BUSY Mask     */

/* SPI_DIVIDER Bit Field Definitions */
#define SPI_DIVIDER_DIVIDER2_Pos   16                                     /*!< SPI DIVIDER: DIVIDER2 Position */
#define SPI_DIVIDER_DIVIDER2_Msk   (0xFFul << SPI_DIVIDER_DIVIDER2_Pos)   /*!< SPI DIVIDER: DIVIDER2 Mask */

#define SPI_DIVIDER_DIVIDER_Pos    0                                      /*!< SPI DIVIDER: DIVIDER Position */
#define SPI_DIVIDER_DIVIDER_Msk    (0xFFul << SPI_DIVIDER_DIVIDER_Pos)    /*!< SPI DIVIDER: DIVIDER Mask */

/* SPI_SSR Bit Field Definitions */
#define SPI_SSR_LTRIG_FLAG_Pos     5                                 /*!< SPI SSR: LTRIG_FLAG Position */
#define SPI_SSR_LTRIG_FLAG_Msk     (1ul << SPI_SSR_LTRIG_FLAG_Pos)   /*!< SPI SSR: LTRIG_FLAG Mask */

#define SPI_SSR_SS_LTRIG_Pos       4                                 /*!< SPI SSR: SS_LTRIG Position */
#define SPI_SSR_SS_LTRIG_Msk       (1ul << SPI_SSR_SS_LTRIG_Pos)     /*!< SPI SSR: SS_LTRIG Mask */

#define SPI_SSR_AUTOSS_Pos         3                                 /*!< SPI SSR: AUTOSS Position */
#define SPI_SSR_AUTOSS_Msk         (1ul << SPI_SSR_AUTOSS_Pos)       /*!< SPI SSR: AUTOSS Mask */

#define SPI_SSR_SS_LVL_Pos         2                                 /*!< SPI SSR: SS_LVL Position */
#define SPI_SSR_SS_LVL_Msk         (1ul << SPI_SSR_SS_LVL_Pos)       /*!< SPI SSR: SS_LVL Mask */

#define SPI_SSR_SSR_Pos            0                                 /*!< SPI SSR: SSR Position */
#define SPI_SSR_SSR_Msk            (3ul << SPI_SSR_SSR_Pos)          /*!< SPI SSR: SSR Mask */

/* SPI_DMA Bit Field Definitions */
#define SPI_DMA_PDMA_RST_Pos   2                                     /*!< SPI DMA: PDMA_RST Position */
#define SPI_DMA_PDMA_RST_Msk   (1ul << SPI_DMA_PDMA_RST_Pos)         /*!< SPI DMA: PDMA_RST Mask */

#define SPI_DMA_RX_DMA_GO_Pos   1                                    /*!< SPI DMA: RX_DMA_GO Position */
#define SPI_DMA_RX_DMA_GO_Msk   (1ul << SPI_DMA_RX_DMA_GO_Pos)       /*!< SPI DMA: RX_DMA_GO Mask */

#define SPI_DMA_TX_DMA_GO_Pos   0                                    /*!< SPI DMA: TX_DMA_GO Position */
#define SPI_DMA_TX_DMA_GO_Msk   (1ul << SPI_DMA_TX_DMA_GO_Pos)       /*!< SPI DMA: TX_DMA_GO Mask */

/* SPI_CNTRL2 Bit Field Definitions */
#define SPI_CNTRL2_BCn_Pos   31                                                      /*!< SPI CNTRL2: BCn Position */
#define SPI_CNTRL2_BCn_Msk   (1ul << SPI_CNTRL2_BCn_Pos)                             /*!< SPI CNTRL2: BCn Mask */

#define SPI_CNTRL2_SS_INT_OPT_Pos   16                                               /*!< SPI CNTRL2: SS_INT_OPT Position */
#define SPI_CNTRL2_SS_INT_OPT_Msk   (1ul << SPI_CNTRL2_SS_INT_OPT_Pos)               /*!< SPI CNTRL2: SS_INT_OPT Mask */

#define SPI_CNTRL2_DUAL_IO_EN_Pos   13                                               /*!< SPI CNTRL2: DUAL_IO_EN Position */
#define SPI_CNTRL2_DUAL_IO_EN_Msk   (1ul << SPI_CNTRL2_DUAL_IO_EN_Pos)               /*!< SPI CNTRL2: DUAL_IO_EN Mask */

#define SPI_CNTRL2_DUAL_IO_DIR_Pos   12                                              /*!< SPI CNTRL2: DUAL_IO_DIR Position */
#define SPI_CNTRL2_DUAL_IO_DIR_Msk   (1ul << SPI_CNTRL2_DUAL_IO_DIR_Pos)             /*!< SPI CNTRL2: DUAL_IO_DIR Mask */

#define SPI_CNTRL2_SLV_START_INTSTS_Pos   11                                         /*!< SPI CNTRL2: SLV_START_INTSTS Position */
#define SPI_CNTRL2_SLV_START_INTSTS_Msk   (1ul << SPI_CNTRL2_SLV_START_INTSTS_Pos)   /*!< SPI CNTRL2: SLV_START_INTSTS Mask */

#define SPI_CNTRL2_SSTA_INTEN_Pos   10                                               /*!< SPI CNTRL2: SSTA_INTEN Position */
#define SPI_CNTRL2_SSTA_INTEN_Msk   (1ul << SPI_CNTRL2_SSTA_INTEN_Pos)               /*!< SPI CNTRL2: SSTA_INTEN Mask */

#define SPI_CNTRL2_SLV_ABORT_Pos    9                                                /*!< SPI CNTRL2: SLV_ABORT Position */
#define SPI_CNTRL2_SLV_ABORT_Msk    (1ul << SPI_CNTRL2_SLV_ABORT_Pos)                /*!< SPI CNTRL2: SLV_ABORT Mask */

#define SPI_CNTRL2_NOSLVSEL_Pos     8                                                /*!< SPI CNTRL2: NOSLVSEL Position */
#define SPI_CNTRL2_NOSLVSEL_Msk     (1ul << SPI_CNTRL2_NOSLVSEL_Pos)                 /*!< SPI CNTRL2: NOSLVSEL Mask */

/* SPI_FIFO_CTL Bit Field Definitions */
#define SPI_FIFO_CTL_TX_THRESHOLD_Pos   28                                         /*!< SPI FIFO_CTL: TX_THRESHOLD Position */
#define SPI_FIFO_CTL_TX_THRESHOLD_Msk   (7ul << SPI_FIFO_CTL_TX_THRESHOLD_Pos)     /*!< SPI FIFO_CTL: TX_THRESHOLD Mask */

#define SPI_FIFO_CTL_RX_THRESHOLD_Pos   24                                         /*!< SPI FIFO_CTL: RX_THRESHOLD Position */
#define SPI_FIFO_CTL_RX_THRESHOLD_Msk   (7ul << SPI_FIFO_CTL_RX_THRESHOLD_Pos)     /*!< SPI FIFO_CTL: RX_THRESHOLD Mask */

#define SPI_FIFO_CTL_TIMEOUT_INTEN_Pos   21                                        /*!< SPI FIFO_CTL: TIMEOUT_INTEN Position */
#define SPI_FIFO_CTL_TIMEOUT_INTEN_Msk   (1ul << SPI_FIFO_CTL_TIMEOUT_INTEN_Pos)   /*!< SPI FIFO_CTL: TIMEOUT_INTEN Mask */

#define SPI_FIFO_CTL_RXOV_INTEN_Pos    6                                           /*!< SPI FIFO_CTL: RXOV_INTEN Position */
#define SPI_FIFO_CTL_RXOV_INTEN_Msk    (1ul << SPI_FIFO_CTL_RXOV_INTEN_Pos)        /*!< SPI FIFO_CTL: RXOV_INTEN Mask */

#define SPI_FIFO_CTL_TX_INTEN_Pos    3                                             /*!< SPI FIFO_CTL: TX_INTEN Position */
#define SPI_FIFO_CTL_TX_INTEN_Msk    (1ul << SPI_FIFO_CTL_TX_INTEN_Pos)            /*!< SPI FIFO_CTL: TX_INTEN Mask */

#define SPI_FIFO_CTL_RX_INTEN_Pos    2                                             /*!< SPI FIFO_CTL: RX_INTEN Position */
#define SPI_FIFO_CTL_RX_INTEN_Msk    (1ul << SPI_FIFO_CTL_RX_INTEN_Pos)            /*!< SPI FIFO_CTL: RX_INTEN Mask */

#define SPI_FIFO_CTL_TX_CLR_Pos     1                                              /*!< SPI FIFO_CTL: TX_CLR Position */
#define SPI_FIFO_CTL_TX_CLR_Msk     (1ul << SPI_FIFO_CTL_TX_CLR_Pos)               /*!< SPI FIFO_CTL: TX_CLR Mask */

#define SPI_FIFO_CTL_RX_CLR_Pos      0                                             /*!< SPI FIFO_CTL: RX_CLR Position */
#define SPI_FIFO_CTL_RX_CLR_Msk      (1ul << SPI_FIFO_CTL_RX_CLR_Pos)              /*!< SPI FIFO_CTL: RX_CLR Mask */

/* SPI_STATUS Bit Field Definitions */
#define SPI_STATUS_TX_FIFO_COUNT_Pos   28                                            /*!< SPI STATUS: TX_FIFO_COUNT Position */
#define SPI_STATUS_TX_FIFO_COUNT_Msk   (0xFul << SPI_STATUS_TX_FIFO_COUNT_Pos)       /*!< SPI STATUS: TX_FIFO_COUNT Mask */

#define SPI_STATUS_TX_FULL_Pos   27                                                  /*!< SPI STATUS: TX_FULL Position */
#define SPI_STATUS_TX_FULL_Msk   (1ul << SPI_STATUS_TX_FULL_Pos)                     /*!< SPI STATUS: TX_FULL Mask */

#define SPI_STATUS_TX_EMPTY_Pos   26                                                 /*!< SPI STATUS: TX_EMPTY Position */
#define SPI_STATUS_TX_EMPTY_Msk   (1ul << SPI_STATUS_TX_EMPTY_Pos)                   /*!< SPI STATUS: TX_EMPTY Mask */

#define SPI_STATUS_RX_FULL_Pos   25                                                  /*!< SPI STATUS: RX_FULL Position */
#define SPI_STATUS_RX_FULL_Msk   (1ul << SPI_STATUS_RX_FULL_Pos)                     /*!< SPI STATUS: RX_FULL Mask */

#define SPI_STATUS_RX_EMPTY_Pos   24                                                 /*!< SPI STATUS: RX_EMPTY Position */
#define SPI_STATUS_RX_EMPTY_Msk   (1ul << SPI_STATUS_RX_EMPTY_Pos)                   /*!< SPI STATUS: RX_EMPTY Mask */

#define SPI_STATUS_TIMEOUT_Pos   20                                                  /*!< SPI STATUS: TIMEOUT Position */
#define SPI_STATUS_TIMEOUT_Msk   (1ul << SPI_STATUS_TIMEOUT_Pos)                     /*!< SPI STATUS: TIMEOUT Mask */

#define SPI_STATUS_IF_Pos   16                                                       /*!< SPI STATUS: IF Position */
#define SPI_STATUS_IF_Msk   (1ul << SPI_STATUS_IF_Pos)                               /*!< SPI STATUS: IF Mask     */

#define SPI_STATUS_RX_FIFO_COUNT_Pos   12                                            /*!< SPI STATUS: RX_FIFO_COUNT Position */
#define SPI_STATUS_RX_FIFO_COUNT_Msk   (0xFul << SPI_STATUS_RX_FIFO_COUNT_Pos)       /*!< SPI STATUS: RX_FIFO_COUNT Mask */

#define SPI_STATUS_SLV_START_INTSTS_Pos   11                                         /*!< SPI STATUS: SLV_START_INTSTS Position */
#define SPI_STATUS_SLV_START_INTSTS_Msk   (1ul << SPI_STATUS_SLV_START_INTSTS_Pos)   /*!< SPI STATUS: SLV_START_INTSTS Mask */

#define SPI_STATUS_TX_INTSTS_Pos   4                                                 /*!< SPI STATUS: TX_INTSTS Position */
#define SPI_STATUS_TX_INTSTS_Msk   (1ul << SPI_STATUS_TX_INTSTS_Pos)                 /*!< SPI STATUS: TX_INTSTS Mask */

#define SPI_STATUS_RX_OVERRUN_Pos   2                                                /*!< SPI STATUS: RX_OVERRUN Position */
#define SPI_STATUS_RX_OVERRUN_Msk   (1ul << SPI_STATUS_RX_OVERRUN_Pos)               /*!< SPI STATUS: RX_OVERRUN Mask */

#define SPI_STATUS_RX_INTSTS_Pos   0                                                 /*!< SPI STATUS: RX_INTSTS Position */
#define SPI_STATUS_RX_INTSTS_Msk   (1ul << SPI_STATUS_RX_INTSTS_Pos)                 /*!< SPI STATUS: RX_INTSTS Mask */

/*@}*/ /* end of group NUC123_SPI */



/*------------------------------ I2C Controller ------------------------------*/
/** @addtogroup NUC123_I2C NUC123 I2C
  Memory Mapped Structure for NUC123 Series I2C Serial Interface Controller
  @{
 */
typedef struct
{
    /**
     * I2CON
     * ===================================================================================================
     * Offset: 0x00  I2C Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2]     |AA        |Assert Acknowledge control bit. 
     * |        |          |When AA=1 prior to address or data received, an acknowledged (low level to SDA) will be returned during 
     * |        |          |the acknowledge clock pulse on the SCL line when 1.) A slave is acknowledging the address sent from 
     * |        |          |master, 2.) The receiver devices are acknowledging the data sent by transmitter. When AA=0 prior to 
     * |        |          |address or data received, a Not acknowledged (high level to SDA) will be returned during the acknowledge 
     * |        |          |clock pulse on the SCL line.
     * |[3]     |SI        |I2C Interrupt Flag. 
     * |        |          |When a new SIO state is present in the I2CSTATUS register, the SI flag is set by hardware, and if bit EI 
     * |        |          |(I2CON [7]) is set, the I2C interrupt is requested. SI must be cleared by software. Clear SI is by writing one 
     * |        |          |to this bit.
     * |[4]     |STO       |I2C STOP Flag. 
     * |        |          |In master mode, setting STO to transmit a STOP condition to bus then I2C hardware will check the bus 
     * |        |          |condition if a STOP condition is detected this flag will be cleared by hardware automatically. 
     * |        |          |In a slave mode, setting STO resets I2C hardware to the defined "not addressed" slave mode. This means 
     * |        |          |it is NO LONGER in the slave receiver mode to receive data from the master transmit device.
     * |[5]     |STA       |I2C START Flag. 
     * |        |          |Setting STA to logic 1 to enter master mode, the I2C hardware sends a START or repeat START condition 
     * |        |          |to bus when the bus is free.
     * |[6]     |ENS1      |I2C controller is enabled/disable
     * |        |          |1 = Enable
     * |        |          |0 = Disable
     * |        |          |Set to enable I2C serial function block. When ENS=1 the I2C serial function enables. The multi-function 
     * |        |          |pin function of SDA and SCL must set to I2C function first.
     * |[7]     |EI        |Enable interrupt. 
     * |        |          |1 = Enable I2C interrupt.
     * |        |          |0 = Disable I2C interrupt. 
     */    
    __IO uint32_t I2CON;	
    
     /**
     * I2CADDR0
     * ===================================================================================================
     * Offset: 0x04  I2C Slave Address Register 0 
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = Disable General Call Function.
     * |        |          |1 = Enable General Call Function.
     * |[7:1]   |I2CADDR   |I2C Address Register
     * |        |          |The content of this register is irrelevant when I2C is in master mode. In the slave mode, the seven 
     * |        |          |most significant bits must be loaded with the MCU's own address. The I2C hardware will react if 
     * |        |          |either of the address is matched.
     */   
    __IO uint32_t I2CADDR0;    

    /**
     * I2CDAT
     * ===================================================================================================
     * Offset: 0x08  I2C Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |I2CDAT    |I2C Data Register
     * |        |          |Bit[7:0] is located with the 8-bit transferred data of I2C serial port. 
     */    
    __IO uint32_t I2CDAT;    
    
    /**
     * I2CSTATUS
     * ===================================================================================================
     * Offset: 0x0C  I2C Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |I2CSTATUS |I2C Status Register 
     * |        |          |The status register of I2C:
     * |        |          |The three least significant bits are always 0. The five most significant bits contain the status code. 
     * |        |          |There are 26 possible status codes. When I2STATUS contains F8H, no serial interrupt is 
     * |        |          |requested. All other I2STATUS values correspond to defined I2C states. When each of these 
     * |        |          |states is entered, a status interrupt is requested (SI = 1). A valid status code is present in 
     * |        |          |I2STATUS one machine cycle after SI is set by hardware and is still present one machine cycle 
     * |        |          |after SI has been reset by software. In addition, states 00H stands for a Bus Error. A Bus Error 
     * |        |          |occurs when a START or STOP condition is present at an illegal position in the formation frame. 
     * |        |          |Example of illegal position are during the serial transfer of an address byte, a data byte or an 
     * |        |          |acknowledge bit.
     */    
    __I  uint32_t I2CSTATUS;        
    
    /**
     * I2CLK
     * ===================================================================================================
     * Offset: 0x10  I2C Clock Divided Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |I2CLK     |I2C clock divided Register
     * |        |          |The I2C clock rate bits: Data Baud Rate of I2C = PCLK /(4x(I2CLK+1)).
     */    
    __IO uint32_t I2CLK;    
    
    /**
     * I2CTOC
     * ===================================================================================================
     * Offset: 0x14  I2C Time-Out Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TIF       |Time-Out flag. 
     * |        |          |1 = Time-Out falg is set by H/W. It can interrupt CPU.
     * |        |          |0 = S/W can clear the flag.
     * |[1]     |DIV4      |Time-Out counter input clock is divider by 4 
     * |        |          |1 = Enable
     * |        |          |0 = Disable
     * |        |          |When Enable, The time-Out period is prolong 4 times.
     * |[2]     |ENTI      |Time-out counter is enabled/disable
     * |        |          |1 = Enable
     * |        |          |0 = Disable
     * |        |          |When Enable, the 14 bit time-out counter will start counting when SI is clear. Setting flag SI to high will 
     * |        |          |reset counter and re-start up counting after SI is cleared.
     */    
    __IO uint32_t I2CTOC;    
    
    /**
     * I2CADDR1
     * ===================================================================================================
     * Offset: 0x18  I2C Slave Address Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = Disable General Call Function.
     * |        |          |1 = Enable General Call Function.
     * |[7:1]   |I2CADDR   |I2C Address Register
     * |        |          |The content of this register is irrelevant when I2C is in master mode. In the slave mode, the seven 
     * |        |          |most significant bits must be loaded with the MCU's own address. The I2C hardware will react if 
     * |        |          |either of the address is matched.
     */    
    __IO uint32_t I2CADDR1;    
    
    /**
     * I2CADDR2
     * ===================================================================================================
     * Offset: 0x1C  I2C Slave Address Register 2 
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = Disable General Call Function.
     * |        |          |1 = Enable General Call Function.
     * |[7:1]   |I2CADDR   |I2C Address Register
     * |        |          |The content of this register is irrelevant when I2C is in master mode. In the slave mode, the seven 
     * |        |          |most significant bits must be loaded with the MCU's own address. The I2C hardware will react if 
     * |        |          |either of the address is matched.
     */    
    __IO uint32_t I2CADDR2;    
    
    /**
     * I2CADDR3
     * ===================================================================================================
     * Offset: 0x20  I2C Slave Address Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = Disable General Call Function.
     * |        |          |1 = Enable General Call Function.
     * |[7:1]   |I2CADDR   |I2C Address Register
     * |        |          |The content of this register is irrelevant when I2C is in master mode. In the slave mode, the seven 
     * |        |          |most significant bits must be loaded with the MCU's own address. The I2C hardware will react if 
     * |        |          |either of the address is matched.
     */    
    __IO uint32_t I2CADDR3; 
    
    /**
     * I2CADM0
     * ===================================================================================================
     * Offset: 0x24  I2C Slave Address Mask Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:1]   |I2ADMx    |I2C Address Mask register
     * |        |          |1 = Mask enable (the received corresponding address bit is don't care.)
     * |        |          |0 = Mask disable (the received corresponding register bit should be exact the same as 
     * |        |          |address register.) 
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register. 
     * |        |          |When the bit in the address mask register is set to one, it means the received 
     * |        |          |corresponding address bit is don't-care. If the bit is set to zero, that means the received 
     * |        |          |corresponding register bit should be exact the same as address register.
     */    
    __IO uint32_t I2CADM0;    
    
    /**
     * I2CADM1
     * ===================================================================================================
     * Offset: 0x28  I2C Slave Address Mask Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:1]   |I2ADMx    |I2C Address Mask register
     * |        |          |1 = Mask enable (the received corresponding address bit is don't care.)
     * |        |          |0 = Mask disable (the received corresponding register bit should be exact the same as 
     * |        |          |address register.) 
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register. 
     * |        |          |When the bit in the address mask register is set to one, it means the received 
     * |        |          |corresponding address bit is don't-care. If the bit is set to zero, that means the received 
     * |        |          |corresponding register bit should be exact the same as address register.
     */    
    __IO uint32_t I2CADM1;    
    
    /**
     * I2CADM2
     * ===================================================================================================
     * Offset: 0x2C  I2C Slave Address Mask Register 2 
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:1]   |I2ADMx    |I2C Address Mask register
     * |        |          |1 = Mask enable (the received corresponding address bit is don't care.)
     * |        |          |0 = Mask disable (the received corresponding register bit should be exact the same as 
     * |        |          |address register.) 
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register. 
     * |        |          |When the bit in the address mask register is set to one, it means the received 
     * |        |          |corresponding address bit is don't-care. If the bit is set to zero, that means the received 
     * |        |          |corresponding register bit should be exact the same as address register.
     */    
    __IO uint32_t I2CADM2;    
    
    /**
     * I2CADM3
     * ===================================================================================================
     * Offset: 0x30  I2C Slave Address Mask Register 3 
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:1]   |I2ADMx    |I2C Address Mask register
     * |        |          |1 = Mask enable (the received corresponding address bit is don't care.)
     * |        |          |0 = Mask disable (the received corresponding register bit should be exact the same as 
     * |        |          |address register.) 
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register. 
     * |        |          |When the bit in the address mask register is set to one, it means the received 
     * |        |          |corresponding address bit is don't-care. If the bit is set to zero, that means the received 
     * |        |          |corresponding register bit should be exact the same as address register.
     */    
    __IO uint32_t I2CADM3;    
    
    /**
     * RESERVED0
     * ===================================================================================================
     * 
     * ---------------------------------------------------------------------------------------------------
     */    
    uint32_t RESERVED0[2];
      
    /**
     * I2CWKUPCON
     * ===================================================================================================
     * Offset: 0x3C  I2C Wake Up Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |WKUPEN    |I2C Wakeup Function Enable
     * |        |          |1 = Enable I2C wake up function.
     * |        |          |0 = Disable I2C wake up function.
     */    
    __IO uint32_t I2CWKUPCON;
    
    /**
     * I2CWKUPSTS
     * ===================================================================================================
     * Offset: 0x40  I2C Wake Up Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |WKUPIF    |I2C Wakeup Interrupt Flag 
     * |        |          |When chip is waked up from power down mode by I2C, this bit is set to 1. Software can 
     * |        |          |write 1 to clear this bit.
     */    
    __IO uint32_t I2CWKUPSTS;            
} I2C_T;

/* I2C I2CON Bit Field Definitions */
#define I2C_I2CON_EI_Pos                        7                                       /*!< I2C I2CON: EI Position */
#define I2C_I2CON_EI_Msk                        (1ul << I2C_I2CON_EI_Pos)               /*!< I2C I2CON: EI Mask */

#define I2C_I2CON_ENS1_Pos                      6                                       /*!< I2C I2CON: ENS1 Position */
#define I2C_I2CON_ENS1_Msk                      (1ul << I2C_I2CON_ENS1_Pos)             /*!< I2C I2CON: ENS1 Mask */

#define I2C_I2CON_STA_Pos                       5                                       /*!< I2C I2CON: STA Position */
#define I2C_I2CON_STA_Msk                       (1ul << I2C_I2CON_STA_Pos)              /*!< I2C I2CON: STA Mask */

#define I2C_I2CON_STO_Pos                       4                                       /*!< I2C I2CON: STO Position */
#define I2C_I2CON_STO_Msk                       (1ul << I2C_I2CON_STO_Pos)              /*!< I2C I2CON: STO Mask */

#define I2C_I2CON_SI_Pos                        3                                       /*!< I2C I2CON: SI Position */
#define I2C_I2CON_SI_Msk                        (1ul << I2C_I2CON_SI_Pos)               /*!< I2C I2CON: SI Mask */

#define I2C_I2CON_AA_Pos                        2                                       /*!< I2C I2CON: AA Position */
#define I2C_I2CON_AA_Msk                        (1ul << I2C_I2CON_AA_Pos)               /*!< I2C I2CON: AA Mask */

/* I2C I2CADDR Bit Field Definitions */
#define I2C_I2CADDR_I2CADDR_Pos                 1                                       /*!< I2C I2CADDR: I2CADDR Position */
#define I2C_I2CADDR_I2CADDR_Msk                 (0x7Ful << I2C_I2CADDR_I2CADDR_Pos)     /*!< I2C I2CADDR: I2CADDR Mask */

#define I2C_I2CADDR_GC_Pos                      0                                       /*!< I2C I2CADDR: GC Position */
#define I2C_I2CADDR_GC_Msk                      (1ul << I2C_I2CADDR_GC_Pos)             /*!< I2C I2CADDR: GC Mask */

/* I2C I2CDAT Bit Field Definitions */
#define I2C_I2CDAT_I2CDAT_Pos                   0                                       /*!< I2C I2CDAT: I2CDAT Position */
#define I2C_I2CDAT_I2CDAT_Msk                   (0xFFul << I2C_I2CDAT_I2CDAT_Pos)       /*!< I2C I2CDAT: I2CDAT Mask */

/* I2C I2CSTATUS Bit Field Definitions */
#define I2C_I2CSTATUS_I2CSTATUS_Pos             0                                       /*!< I2C I2CSTATUS: I2CSTATUS Position */
#define I2C_I2CSTATUS_I2CSTATUS_Msk             (0xFFul << I2C_I2CSTATUS_I2CSTATUS_Pos) /*!< I2C I2CSTATUS: I2CSTATUS Mask */

/* I2C I2CLK Bit Field Definitions */
#define I2C_I2CLK_I2CLK_Pos                     0                                       /*!< I2C I2CLK: I2CLK Position */
#define I2C_I2CLK_I2CLK_Msk                     (0xFFul << I2C_I2CLK_I2CLK_Pos)         /*!< I2C I2CLK: I2CLK Mask */

/* I2C I2CTOC Bit Field Definitions */
#define I2C_I2CTOC_ENTI_Pos                     2                                       /*!< I2C I2CTOC: ENTI Position */
#define I2C_I2CTOC_ENTI_Msk                     (1ul << I2C_I2CTOC_ENTI_Pos)            /*!< I2C I2CTOC: ENTI Mask */

#define I2C_I2CTOC_DIV4_Pos                     1                                       /*!< I2C I2CTOC: DIV4 Position */
#define I2C_I2CTOC_DIV4_Msk                     (1ul << I2C_I2CTOC_DIV4_Pos)            /*!< I2C I2CTOC: DIV4 Mask */

#define I2C_I2CTOC_TIF_Pos                      0                                       /*!< I2C I2CTOC: TIF Position */
#define I2C_I2CTOC_TIF_Msk                      (1ul << I2C_I2CTOC_TIF_Pos)             /*!< I2C I2CTOC: TIF Mask */

/* I2C I2CADM Bit Field Definitions */
#define I2C_I2CADM_I2CADM_Pos                   1                                       /*!< I2C I2CADM: I2CADM Position */
#define I2C_I2CADM_I2CADM_Msk                   (0x7Ful << I2C_I2CADM_I2CADM_Pos)       /*!< I2C I2CADM: I2CADM Mask */

/* I2C I2CWKUPCON Bit Field Definitions */
#define I2C_I2CWKUPCON_WKUPEN_Pos               0                                       /*!< I2C I2CWKUPCON: WKUPEN Position */
#define I2C_I2CWKUPCON_WKUPEN_Msk               (1ul << I2C_I2CWKUPCON_WKUPEN_Pos)      /*!< I2C I2CWKUPCON: WKUPEN Mask */

/* I2C I2CWKUPSTS Bit Field Definitions */
#define I2C_I2CWKUPSTS_WKUPIF_Pos               0                                       /*!< I2C I2CWKUPSTS: WKUPIF Position */
#define I2C_I2CWKUPSTS_WKUPIF_Msk               (1ul << I2C_I2CWKUPSTS_WKUPIF_Pos)      /*!< I2C I2CWKUPSTS: WKUPIF Mask */

/*@}*/ /* end of group NUC123_I2C */



/*----------------------------- ADC Controller -------------------------------*/
/** @addtogroup NUC123_ADC NUC123 ADC
  Memory Mapped Structure for NUC123 Series ADC Controller
  @{
 */
typedef struct
{
    __I  uint32_t ADDR[8];               /*!< Offset: 0x00  A/D Data Register              */
    __IO uint32_t ADCR;                  /*!< Offset: 0x20  A/D Control Register           */
    __IO uint32_t CHER;                /*!< Offset: 0x24  A/D Channel Enable Register    */
    __IO uint32_t CMPR[2];             /*!< Offset: 0x28  A/D Compare Register 0 & 1     */
    __IO uint32_t ADSR;                  /*!< Offset: 0x30  ADC Status Register            */
    __I  uint32_t RESERVE0[3];
    __I  uint32_t PDMA;                /*!< Offset: 0x40  ADC PDMA Current Transfer Data */
} ADC_T;


/* ADDR Bit Field Definitions */
#define ADC_ADDR_VALID_Pos      17                                /*!< ADC ADDR: VALID Position */
#define ADC_ADDR_VALID_Msk      (1ul << ADC_ADDR_VALID_Pos)       /*!< ADC ADDR: VALID Mask */

#define ADC_ADDR_OVERRUN_Pos    16                                /*!< ADC ADDR: OVERRUN Position */
#define ADC_ADDR_OVERRUN_Msk    (1ul << ADC_ADDR_OVERRUN_Pos)     /*!< ADC ADDR: OVERRUN Mask */

#define ADC_ADDR_RSLT_Pos       0                                 /*!< ADC ADDR: RSLT Position */
#define ADC_ADDR_RSLT_Msk       (0xFFFFul << ADC_ADDR_RSLT_Pos)   /*!< ADC ADDR: RSLT Mask */

/* ADCR Bit Field Definitions */
#define ADC_ADCR_ADST_Pos       11                                /*!< ADC ADCR: ADST Position */
#define ADC_ADCR_ADST_Msk       (1ul << ADC_ADCR_ADST_Pos)        /*!< ADC ADCR: ADST Mask */

#define ADC_ADCR_PTEN_Pos       9                                 /*!< ADC ADCR: PTEN Position */
#define ADC_ADCR_PTEN_Msk       (1ul << ADC_ADCR_PTEN_Pos)        /*!< ADC ADCR: PTEN Mask */

#define ADC_ADCR_TRGEN_Pos      8                                 /*!< ADC ADCR: TRGEN Position */
#define ADC_ADCR_TRGEN_Msk      (1ul << ADC_ADCR_TRGEN_Pos)       /*!< ADC ADCR: TRGEN Mask */

#define ADC_ADCR_TRGCOND_Pos    6                                 /*!< ADC ADCR: TRGCOND Position */
#define ADC_ADCR_TRGCOND_Msk    (3ul << ADC_ADCR_TRGCOND_Pos)     /*!< ADC ADCR: TRGCOND Mask */

#define ADC_ADCR_TRGS_Pos       4                                 /*!< ADC ADCR: TRGS Position */
#define ADC_ADCR_TRGS_Msk       (3ul << ADC_ADCR_TRGS_Pos)        /*!< ADC ADCR: TRGS Mask */

#define ADC_ADCR_ADMD_Pos       2                                 /*!< ADC ADCR: ADMD Position */
#define ADC_ADCR_ADMD_Msk       (3ul << ADC_ADCR_ADMD_Pos)        /*!< ADC ADCR: ADMD Mask */

#define ADC_ADCR_ADIE_Pos       1                                 /*!< ADC ADCR: ADIE Position */
#define ADC_ADCR_ADIE_Msk       (1ul << ADC_ADCR_ADIE_Pos)        /*!< ADC ADCR: ADIE Mask */

#define ADC_ADCR_ADEN_Pos       0                                 /*!< ADC ADCR: ADEN Position */
#define ADC_ADCR_ADEN_Msk       (1ul << ADC_ADCR_ADEN_Pos)        /*!< ADC ADCR: ADEN Mask */

/* ADCHER Bit Field Definitions */
#define ADC_CHER_PRESEL_Pos   8                                 /*!< ADC ADCHER: PRESEL Position */
#define ADC_CHER_PRESEL_Msk   (3ul << ADC_CHER_PRESEL_Pos)    /*!< ADC ADCHER: PRESEL Mask */

#define ADC_CHER_CHEN7_Pos    7                                 /*!< ADC ADCHER: CHEN7 Position */
#define ADC_CHER_CHEN7_Msk    (1ul << ADC_CHER_CHEN7_Pos)     /*!< ADC ADCHER: CHEN7 Mask */

#define ADC_CHER_CHEN6_Pos    6                                 /*!< ADC ADCHER: CHEN6 Position */
#define ADC_CHER_CHEN6_Msk    (1ul << ADC_CHER_CHEN6_Pos)     /*!< ADC ADCHER: CHEN6 Mask */

#define ADC_CHER_CHEN5_Pos    5                                 /*!< ADC ADCHER: CHEN5 Position */
#define ADC_CHER_CHEN5_Msk    (1ul << ADC_CHER_CHEN5_Pos)     /*!< ADC ADCHER: CHEN5 Mask */

#define ADC_CHER_CHEN4_Pos    4                                 /*!< ADC ADCHER: CHEN4 Position */
#define ADC_CHER_CHEN4_Msk    (1ul << ADC_CHER_CHEN4_Pos)     /*!< ADC ADCHER: CHEN4 Mask */

#define ADC_CHER_CHEN3_Pos    3                                 /*!< ADC ADCHER: CHEN3 Position */
#define ADC_CHER_CHEN3_Msk    (1ul << ADC_CHER_CHEN3_Pos)     /*!< ADC ADCHER: CHEN3 Mask */

#define ADC_CHER_CHEN2_Pos    2                                 /*!< ADC ADCHER: CHEN2 Position */
#define ADC_CHER_CHEN2_Msk    (1ul << ADC_CHER_CHEN2_Pos)     /*!< ADC ADCHER: CHEN2 Mask */

#define ADC_CHER_CHEN1_Pos    1                                 /*!< ADC ADCHER: CHEN1 Position */
#define ADC_CHER_CHEN1_Msk    (1ul << ADC_CHER_CHEN1_Pos)     /*!< ADC ADCHER: CHEN1 Mask */

#define ADC_CHER_CHEN0_Pos    0                                 /*!< ADC ADCHER: CHEN0 Position */
#define ADC_CHER_CHEN0_Msk    (1ul << ADC_CHER_CHEN0_Pos)     /*!< ADC ADCHER: CHEN0 Mask */

/* ADCMPR Bit Field Definitions */
#define ADC_CMPR_CMPD_Pos        16                                    /*!< ADC ADCMPR: CMPD Position */
#define ADC_CMPR_CMPD_Msk        (0xFFFul << ADC_CMPR_CMPD_Pos)      /*!< ADC ADCMPR: CMPD Mask */

#define ADC_CMPR_CMPMATCNT_Pos   8                                     /*!< ADC ADCMPR: CMPMATCNT Position */
#define ADC_CMPR_CMPMATCNT_Msk   (0xFul << ADC_CMPR_CMPMATCNT_Pos)   /*!< ADC ADCMPR: CMPMATCNT Mask */

#define ADC_CMPR_CMPCH_Pos       3                                     /*!< ADC ADCMPR: CMPCH Position */
#define ADC_CMPR_CMPCH_Msk       (7ul << ADC_CMPR_CMPCH_Pos)         /*!< ADC ADCMPR: CMPCH Mask */

#define ADC_CMPR_CMPCOND_Pos     2                                     /*!< ADC ADCMPR: CMPCOND Position */
#define ADC_CMPR_CMPCOND_Msk     (1ul << ADC_CMPR_CMPCOND_Pos)       /*!< ADC ADCMPR: CMPCOND Mask */

#define ADC_CMPR_CMPIE_Pos       1                                     /*!< ADC ADCMPR: CMPIE Position */
#define ADC_CMPR_CMPIE_Msk       (1ul << ADC_CMPR_CMPIE_Pos)         /*!< ADC ADCMPR: CMPIE Mask */

#define ADC_CMPR_CMPEN_Pos       0                                     /*!< ADC ADCMPR: CMPEN Position */
#define ADC_CMPR_CMPEN_Msk       (1ul << ADC_CMPR_CMPEN_Pos)         /*!< ADC ADCMPR: CMPEN Mask */

/* ADSR Bit Field Definitions */
#define ADC_ADSR_OVERRUN_Pos       16                                    /*!< ADC ADSR: OVERRUN Position */
#define ADC_ADSR_OVERRUN_Msk       (0xFFul << ADC_ADSR_OVERRUN_Pos)      /*!< ADC ADSR: OVERRUN Mask */

#define ADC_ADSR_VALID_Pos         8                                     /*!< ADC ADSR: VALID Position */
#define ADC_ADSR_VALID_Msk         (0xFFul << ADC_ADSR_VALID_Pos)        /*!< ADC ADSR: VALID Mask */

#define ADC_ADSR_CHANNEL_Pos       4                                     /*!< ADC ADSR: CHANNEL Position */
#define ADC_ADSR_CHANNEL_Msk       (7ul << ADC_ADSR_CHANNEL_Pos)         /*!< ADC ADSR: CHANNEL Mask */

#define ADC_ADSR_BUSY_Pos          3                                     /*!< ADC ADSR: BUSY Position */
#define ADC_ADSR_BUSY_Msk          (1ul << ADC_ADSR_BUSY_Pos)            /*!< ADC ADSR: BUSY Mask */

#define ADC_ADSR_CMPF1_Pos         2                                     /*!< ADC ADSR: CMPF1 Position */
#define ADC_ADSR_CMPF1_Msk         (1ul << ADC_ADSR_CMPF1_Pos)           /*!< ADC ADSR: CMPF1 Mask */

#define ADC_ADSR_CMPF0_Pos         1                                     /*!< ADC ADSR: CMPF0 Position */
#define ADC_ADSR_CMPF0_Msk         (1ul << ADC_ADSR_CMPF0_Pos)           /*!< ADC ADSR: CMPF0 Mask */

#define ADC_ADSR_ADF_Pos           0                                     /*!< ADC ADSR: ADF Position */
#define ADC_ADSR_ADF_Msk           (1ul << ADC_ADSR_ADF_Pos)             /*!< ADC ADSR: ADF Mask */

/* ADPDMA Bit Field Definitions */
#define ADC_PDMA_AD_PDMA_Pos     0                                     /*!< ADC ADPDMA: AD_PDMA Position */
#define ADC_PDMA_AD_PDMA_Msk     (0x3FFul << ADC_ADPDMA_AD_PDMA_Pos) /*!< ADC ADPDMA: AD_PDMA Mask */

/*@}*/ /* end of group NUC123_ADC */



/*---------------------------- Clock Controller ------------------------------*/

/** @addtogroup NUC123_CLK NUC123_CLK
  Memory Mapped Structure for NUC123 Series System Clock Controller
  @{
 */
typedef struct
{
    __IO uint32_t PWRCON;	        /*!< Offset: 0x00  System Power-down Control Register        */           
    __IO uint32_t AHBCLK;      	  /*!< Offset: 0x04  AHB Devices Clock Enable Control Register */     
    __IO uint32_t APBCLK;        	/*!< Offset: 0x08  APB Devices Clock Enable Control Register */   
    __IO uint32_t CLKSTATUS;   	  /*!< Offset: 0x0C  Clock status monitor Register             */     
    __IO uint32_t CLKSEL0;       	/*!< Offset: 0x10  Clock Source Select Control Register 0    */   
    __IO uint32_t CLKSEL1;        /*!< Offset: 0x14  Clock Source Select Control Register 1    */  
    __IO uint32_t CLKDIV;        	/*!< Offset: 0x18  Clock Divider Number Register             */   
    __IO uint32_t CLKSEL2;       	/*!< Offset: 0x1C  Clock Source Select Control Register 2    */    
    __IO uint32_t PLLCON;         /*!< Offset: 0x20  PLL Control Register                      */
    __IO uint32_t FRQDIV;         /*!< Offset: 0x24  Frequency Divider Control Register        */  
    __IO uint32_t RESERVE;
    __IO uint32_t APBDIV;         /*!< Offset: 0x2C  APB Divider Control Register              */   
} CLK_T;

/* CLK PWRCON Bit Field Definitions */
#define CLK_PWRCON_PD_WAIT_CPU_Pos           8                                    /*!< CLK PWRCON: PD_WAIT_CPU Position */
#define CLK_PWRCON_PD_WAIT_CPU_Msk           (1ul << CLK_PWRCON_PD_WAIT_CPU_Pos)  /*!< CLK PWRCON: PD_WAIT_CPU Mask */

#define CLK_PWRCON_PWR_DOWN_EN_Pos           7                                    /*!< CLK PWRCON: PWR_DOWN_EN Position */
#define CLK_PWRCON_PWR_DOWN_EN_Msk           (1ul << CLK_PWRCON_PWR_DOWN_EN_Pos)  /*!< CLK PWRCON: PWR_DOWN_EN Mask */

#define CLK_PWRCON_PD_WU_STS_Pos             6                                    /*!< CLK PWRCON: PD_WU_STS Position */
#define CLK_PWRCON_PD_WU_STS_Msk             (1ul << CLK_PWRCON_PD_WU_STS_Pos)    /*!< CLK PWRCON: PD_WU_STS Mask */

#define CLK_PWRCON_PD_WU_INT_EN_Pos          5                                    /*!< CLK PWRCON: PD_WU_INT_EN Position */
#define CLK_PWRCON_PD_WU_INT_EN_Msk          (1ul << CLK_PWRCON_PD_WU_INT_EN_Pos) /*!< CLK PWRCON: PD_WU_INT_EN Mask */

#define CLK_PWRCON_PD_WU_DLY_Pos             4                                    /*!< CLK PWRCON: PD_WU_DLY Position */
#define CLK_PWRCON_PD_WU_DLY_Msk             (1ul << CLK_PWRCON_PD_WU_DLY_Pos)    /*!< CLK PWRCON: PD_WU_DLY Mask */

#define CLK_PWRCON_LIRC_EN_Pos             3                                    /*!< CLK PWRCON: IRC10K_EN Position */
#define CLK_PWRCON_LIRC_EN_Msk             (1ul << CLK_PWRCON_LIRC_EN_Pos)    /*!< CLK PWRCON: IRC10K_EN Mask */

#define CLK_PWRCON_HIRC_EN_Pos             2                                    /*!< CLK PWRCON: IRC22M_EN Position */
#define CLK_PWRCON_HIRC_EN_Msk             (1ul << CLK_PWRCON_HIRC_EN_Pos)    /*!< CLK PWRCON: IRC22M_EN Mask */

#define CLK_PWRCON_HXT_EN_Pos             0                                    /*!< CLK PWRCON: HXT_EN Position */
#define CLK_PWRCON_HXT_EN_Msk             (1ul << CLK_PWRCON_HXT_EN_Pos)    /*!< CLK PWRCON: HXT_EN Mask */

/* CLK AHBCLK Bit Field Definitions */
#define CLK_AHBCLK_ISP_EN_Pos                2                                    /*!< CLK AHBCLK: ISP_EN Position */
#define CLK_AHBCLK_ISP_EN_Msk                (1ul << CLK_AHBCLK_ISP_EN_Pos)       /*!< CLK AHBCLK: ISP_EN Mask */

#define CLK_AHBCLK_PDMA_EN_Pos               1                                    /*!< CLK AHBCLK: PDMA_EN Position */
#define CLK_AHBCLK_PDMA_EN_Msk               (1ul << CLK_AHBCLK_PDMA_EN_Pos)      /*!< CLK AHBCLK: PDMA_EN Mask */


/* CLK APBCLK Bit Field Definitions */
#define CLK_APBCLK_PS2_EN_Pos                31                                   /*!< CLK APBCLK: PS2_EN Position */
#define CLK_APBCLK_PS2_EN_Msk                (1ul << CLK_APBCLK_PS2_EN_Pos)       /*!< CLK APBCLK: PS2_EN Mask */

#define CLK_APBCLK_I2S_EN_Pos                29                                   /*!< CLK APBCLK: I2S_EN Position */
#define CLK_APBCLK_I2S_EN_Msk                (1ul << CLK_APBCLK_I2S_EN_Pos)       /*!< CLK APBCLK: I2S_EN Mask */

#define CLK_APBCLK_ADC_EN_Pos                28                                   /*!< CLK APBCLK: ADC_EN Position */
#define CLK_APBCLK_ADC_EN_Msk                (1ul << CLK_APBCLK_ADC_EN_Pos)       /*!< CLK APBCLK: ADC_EN Mask */

#define CLK_APBCLK_USBD_EN_Pos               27                                   /*!< CLK APBCLK: USBD_EN Position */
#define CLK_APBCLK_USBD_EN_Msk               (1ul << CLK_APBCLK_USBD_EN_Pos)      /*!< CLK APBCLK: USBD_EN Mask */

#define CLK_APBCLK_PWM23_EN_Pos              21                                   /*!< CLK APBCLK: PWM23_EN Position */
#define CLK_APBCLK_PWM23_EN_Msk              (1ul << CLK_APBCLK_PWM23_EN_Pos)     /*!< CLK APBCLK: PWM23_EN Mask */

#define CLK_APBCLK_PWM01_EN_Pos              20                                   /*!< CLK APBCLK: PWM01_EN Position */
#define CLK_APBCLK_PWM01_EN_Msk              (1ul << CLK_APBCLK_PWM01_EN_Pos)     /*!< CLK APBCLK: PWM01_EN Mask */

#define CLK_APBCLK_UART1_EN_Pos              17                                   /*!< CLK APBCLK: UART1_EN Position */
#define CLK_APBCLK_UART1_EN_Msk              (1ul << CLK_APBCLK_UART1_EN_Pos)     /*!< CLK APBCLK: UART1_EN Mask */

#define CLK_APBCLK_UART0_EN_Pos              16                                   /*!< CLK APBCLK: UART0_EN Position */
#define CLK_APBCLK_UART0_EN_Msk              (1ul << CLK_APBCLK_UART0_EN_Pos)     /*!< CLK APBCLK: UART0_EN Mask */

#define CLK_APBCLK_SPI2_EN_Pos               14                                   /*!< CLK APBCLK: SPI2_EN Position */
#define CLK_APBCLK_SPI2_EN_Msk               (1ul << CLK_APBCLK_SPI2_EN_Pos)      /*!< CLK APBCLK: SPI2_EN Mask */

#define CLK_APBCLK_SPI1_EN_Pos               13                                   /*!< CLK APBCLK: SPI1_EN Position */
#define CLK_APBCLK_SPI1_EN_Msk               (1ul << CLK_APBCLK_SPI1_EN_Pos)      /*!< CLK APBCLK: SPI1_EN Mask */

#define CLK_APBCLK_SPI0_EN_Pos               12                                   /*!< CLK APBCLK: SPI0_EN Position */
#define CLK_APBCLK_SPI0_EN_Msk               (1ul << CLK_APBCLK_SPI0_EN_Pos)      /*!< CLK APBCLK: SPI0_EN Mask */

#define CLK_APBCLK_I2C1_EN_Pos               9                                    /*!< CLK APBCLK: I2C1_EN Position */
#define CLK_APBCLK_I2C1_EN_Msk               (1ul << CLK_APBCLK_I2C1_EN_Pos)      /*!< CLK APBCLK: I2C1_EN Mask */

#define CLK_APBCLK_I2C0_EN_Pos               8                                    /*!< CLK APBCLK: I2C0_EN_ Position */
#define CLK_APBCLK_I2C0_EN_Msk               (1ul << CLK_APBCLK_I2C0_EN_Pos)      /*!< CLK APBCLK: I2C0_EN_ Mask */

#define CLK_APBCLK_FDIV_EN_Pos               6                                    /*!< CLK APBCLK: FDIV_EN Position */
#define CLK_APBCLK_FDIV_EN_Msk               (1ul << CLK_APBCLK_FDIV_EN_Pos)      /*!< CLK APBCLK: FDIV_EN Mask */

#define CLK_APBCLK_TMR3_EN_Pos               5                                    /*!< CLK APBCLK: TMR3_EN Position */
#define CLK_APBCLK_TMR3_EN_Msk               (1ul << CLK_APBCLK_TMR3_EN_Pos)      /*!< CLK APBCLK: TMR3_EN Mask */

#define CLK_APBCLK_TMR2_EN_Pos               4                                    /*!< CLK APBCLK: TMR2_EN Position */
#define CLK_APBCLK_TMR2_EN_Msk               (1ul << CLK_APBCLK_TMR2_EN_Pos)      /*!< CLK APBCLK: TMR2_EN Mask */

#define CLK_APBCLK_TMR1_EN_Pos               3                                    /*!< CLK APBCLK: TMR1_EN Position */
#define CLK_APBCLK_TMR1_EN_Msk               (1ul << CLK_APBCLK_TMR1_EN_Pos)      /*!< CLK APBCLK: TMR1_EN Mask */
                                               
#define CLK_APBCLK_TMR0_EN_Pos               2                                    /*!< CLK APBCLK: TMR0_EN Position */
#define CLK_APBCLK_TMR0_EN_Msk               (1ul << CLK_APBCLK_TMR0_EN_Pos)      /*!< CLK APBCLK: TMR0_EN Mask */      

#define CLK_APBCLK_WDT_EN_Pos                0                                    /*!< CLK APBCLK: WDT_EN Position */
#define CLK_APBCLK_WDT_EN_Msk                (1ul << CLK_APBCLK_WDT_EN_Pos)       /*!< CLK APBCLK: WDT_EN Mask */

/* CLK CLKSTATUS Bit Field Definitions */
#define CLK_CLKSTATUS_CLK_SW_FAIL_Pos        7                                        /*!< CLK CLKSTATUS: CLK_SW_FAIL Position */
#define CLK_CLKSTATUS_CLK_SW_FAIL_Msk        (1ul << CLK_CLKSTATUS_CLK_SW_FAIL_Pos)   /*!< CLK CLKSTATUS: CLK_SW_FAIL Mask */

#define CLK_CLKSTATUS_HIRC_STB_Pos         4                                          /*!< CLK CLKSTATUS: IRC22M_STB Position */
#define CLK_CLKSTATUS_HIRC_STB_Msk         (1ul << CLK_CLKSTATUS_HIRC_STB_Pos)        /*!< CLK CLKSTATUS: IRC22M_STB Mask */

#define CLK_CLKSTATUS_LIRC_STB_Pos         3                                          /*!< CLK CLKSTATUS: IRC10K_STB Position */
#define CLK_CLKSTATUS_LIRC_STB_Msk         (1ul << CLK_CLKSTATUS_LIRC_STB_Pos)        /*!< CLK CLKSTATUS: IRC10K_STB Mask */

#define CLK_CLKSTATUS_PLL_STB_Pos            2                                        /*!< CLK CLKSTATUS: PLL_STB Position */
#define CLK_CLKSTATUS_PLL_STB_Msk            (1ul << CLK_CLKSTATUS_PLL_STB_Pos)       /*!< CLK CLKSTATUS: PLL_STB Mask */

#define CLK_CLKSTATUS_HXT_STB_Pos         0                                           /*!< CLK CLKSTATUS: HXT_STB Position */
#define CLK_CLKSTATUS_HXT_STB_Msk         (1ul << CLK_CLKSTATUS_HXT_STB_Pos)          /*!< CLK CLKSTATUS: HXT_STB Mask */

/* CLK CLKSEL0 Bit Field Definitions */
#define CLK_CLKSEL0_STCLK_S_Pos              3                                        /*!< CLK CLKSEL0: STCLK_S Position */
#define CLK_CLKSEL0_STCLK_S_Msk              (7ul << CLK_CLKSEL0_STCLK_S_Pos)         /*!< CLK CLKSEL0: STCLK_S Mask */

#define CLK_CLKSEL0_HCLK_S_Pos               0                                        /*!< CLK CLKSEL0: HCLK_S Position */
#define CLK_CLKSEL0_HCLK_S_Msk               (7ul << CLK_CLKSEL0_HCLK_S_Pos)          /*!< CLK CLKSEL0: HCLK_S Mask */

/* CLK CLKSEL1 Bit Field Definitions */
#define CLK_CLKSEL1_PWM23_S_Pos              30                                       /*!< CLK CLKSEL1: PWM23_S Position */
#define CLK_CLKSEL1_PWM23_S_Msk              (3ul << CLK_CLKSEL1_PWM23_S_Pos)         /*!< CLK CLKSEL1: PWM23_S Mask */

#define CLK_CLKSEL1_PWM01_S_Pos              28                                       /*!< CLK CLKSEL1: PWM01_S Position */
#define CLK_CLKSEL1_PWM01_S_Msk              (3ul << CLK_CLKSEL1_PWM01_S_Pos)         /*!< CLK CLKSEL1: PWM01_S Mask */

#define CLK_CLKSEL1_UART_S_Pos               24                                       /*!< CLK CLKSEL1: UART_S Position */
#define CLK_CLKSEL1_UART_S_Msk               (3ul << CLK_CLKSEL1_UART_S_Pos)          /*!< CLK CLKSEL1: UART_S Mask */

#define CLK_CLKSEL1_TMR3_S_Pos               20                                       /*!< CLK CLKSEL1: TMR3_S Position */
#define CLK_CLKSEL1_TMR3_S_Msk               (7ul << CLK_CLKSEL1_TMR3_S_Pos)          /*!< CLK CLKSEL1: TMR3_S Mask */

#define CLK_CLKSEL1_TMR2_S_Pos               16                                       /*!< CLK CLKSEL1: TMR2_S Position */
#define CLK_CLKSEL1_TMR2_S_Msk               (7ul << CLK_CLKSEL1_TMR2_S_Pos)          /*!< CLK CLKSEL1: TMR2_S Mask */

#define CLK_CLKSEL1_TMR1_S_Pos               12                                       /*!< CLK CLKSEL1: TMR1_S Position */
#define CLK_CLKSEL1_TMR1_S_Msk               (7ul << CLK_CLKSEL1_TMR1_S_Pos)          /*!< CLK CLKSEL1: TMR1_S Mask */

#define CLK_CLKSEL1_TMR0_S_Pos               8                                        /*!< CLK CLKSEL1: TMR0_S Position */
#define CLK_CLKSEL1_TMR0_S_Msk               (7ul << CLK_CLKSEL1_TMR0_S_Pos)          /*!< CLK CLKSEL1: TMR0_S Mask */

//#define CLK_CLKSEL1_SPI3_S_Pos               7                                      /*!< CLK CLKSEL1: SPI3_S Position */
//#define CLK_CLKSEL1_SPI3_S_Msk               (1ul << CLK_CLKSEL1_SPI3_S_Pos)        /*!< CLK CLKSEL1: SPI3_S Mask */

#define CLK_CLKSEL1_SPI2_S_Pos               6                                        /*!< CLK CLKSEL1: SPI2_S Position */
#define CLK_CLKSEL1_SPI2_S_Msk               (1ul << CLK_CLKSEL1_SPI2_S_Pos)          /*!< CLK CLKSEL1: SPI2_S Mask */

#define CLK_CLKSEL1_SPI1_S_Pos               5                                        /*!< CLK CLKSEL1: SPI1_S Position */
#define CLK_CLKSEL1_SPI1_S_Msk               (1ul << CLK_CLKSEL1_SPI1_S_Pos)          /*!< CLK CLKSEL1: SPI1_S Mask */

#define CLK_CLKSEL1_SPI0_S_Pos               4                                        /*!< CLK CLKSEL1: SPI0_S Position */
#define CLK_CLKSEL1_SPI0_S_Msk               (1ul << CLK_CLKSEL1_SPI0_S_Pos)          /*!< CLK CLKSEL1: SPI0_S Mask */

#define CLK_CLKSEL1_ADC_S_Pos                2                                        /*!< CLK CLKSEL1: ADC_S Position */
#define CLK_CLKSEL1_ADC_S_Msk                (3ul << CLK_CLKSEL1_ADC_S_Pos)           /*!< CLK CLKSEL1: ADC_S Mask */

#define CLK_CLKSEL1_WDT_S_Pos                0                                        /*!< CLK CLKSEL1: WDT_S Position */
#define CLK_CLKSEL1_WDT_S_Msk                (3ul << CLK_CLKSEL1_WDT_S_Pos)           /*!< CLK CLKSEL1: WDT_S Mask */

/* CLK CLKSEL2 Bit Field Definitions */
#define CLK_CLKSEL2_WWDT_S_Pos              16                                        /*!< CLK CLKSEL2: WWDT_S Position */
#define CLK_CLKSEL2_WWDT_S_Msk              (3ul << CLK_CLKSEL2_WWDT_S_Pos)           /*!< CLK CLKSEL2: WWDT_S Mask */

#define CLK_CLKSEL2_PWM23_S_EXT_Pos         9                                         /*!< CLK CLKSEL2: PWM23_S_EXT Position */
#define CLK_CLKSEL2_PWM23_S_EXT_Msk         (1ul << CLK_CLKSEL2_PWM23_S_EXT_Pos)      /*!< CLK CLKSEL2: PWM23_S_EXT Mask */

#define CLK_CLKSEL2_PWM01_S_EXT_Pos         8                                         /*!< CLK CLKSEL2: PWM01_S_EXT Position */
#define CLK_CLKSEL2_PWM01_S_EXT_Msk         (1ul << CLK_CLKSEL2_PWM01_S_EXT_Pos)      /*!< CLK CLKSEL2: PWM01_S_EXT Mask */

#define CLK_CLKSEL2_FRQDIV_S_Pos             2                                        /*!< CLK CLKSEL2: FRQDIV_S Position */
#define CLK_CLKSEL2_FRQDIV_S_Msk             (3ul << CLK_CLKSEL2_FRQDIV_S_Pos)        /*!< CLK CLKSEL2: FRQDIV_S Mask */

#define CLK_CLKSEL2_I2S_S_Pos                0                                        /*!< CLK CLKSEL2: I2S_S Position */
#define CLK_CLKSEL2_I2S_S_Msk                (3ul << CLK_CLKSEL2_I2S_S_Pos)           /*!< CLK CLKSEL2: I2S_S Mask */

/* CLK CLKDIV Bit Field Definitions */
#define CLK_CLKDIV_ADC_N_Pos                 16                                       /*!< CLK CLKDIV: ADC_N Position */
#define CLK_CLKDIV_ADC_N_Msk                 (0xFFul << CLK_CLKDIV_ADC_N_Pos)         /*!< CLK CLKDIV: ADC_N Mask */

#define CLK_CLKDIV_UART_N_Pos                8                                        /*!< CLK CLKDIV: UART_N Position */
#define CLK_CLKDIV_UART_N_Msk                (0xFul << CLK_CLKDIV_UART_N_Pos)         /*!< CLK CLKDIV: UART_N Mask */

#define CLK_CLKDIV_USB_N_Pos                 4                                        /*!< CLK CLKDIV: USB_N Position */
#define CLK_CLKDIV_USB_N_Msk                 (0xFul << CLK_CLKDIV_USB_N_Pos)          /*!< CLK CLKDIV: USB_N Mask */

#define CLK_CLKDIV_HCLK_N_Pos                0                                        /*!< CLK CLKDIV: HCLK_N Position */
#define CLK_CLKDIV_HCLK_N_Msk                (0xFul << CLK_CLKDIV_HCLK_N_Pos)         /*!< CLK CLKDIV: HCLK_N Mask */

/* CLK PLLCON Bit Field Definitions */
#define CLK_PLLCON_PLL_SRC_Pos               19                                       /*!< CLK PLLCON: PLL_SRC Position */
#define CLK_PLLCON_PLL_SRC_Msk               (1ul << CLK_PLLCON_PLL_SRC_Pos)          /*!< CLK PLLCON: PLL_SRC Mask */

#define CLK_PLLCON_OE_Pos                    18                                       /*!< CLK PLLCON: PLL_SRC Position */
#define CLK_PLLCON_OE_Msk                    (1ul << CLK_PLLCON_OE_Pos)               /*!< CLK PLLCON: PLL_SRC Mask */

#define CLK_PLLCON_BP_Pos                    17                                       /*!< CLK PLLCON: OE Position */
#define CLK_PLLCON_BP_Msk                    (1ul << CLK_PLLCON_BP_Pos)               /*!< CLK PLLCON: OE Mask */

#define CLK_PLLCON_PD_Pos                    16                                       /*!< CLK PLLCON: PD Position */
#define CLK_PLLCON_PD_Msk                    (1ul << CLK_PLLCON_PD_Pos)               /*!< CLK PLLCON: PD Mask */

#define CLK_PLLCON_OUT_DV_Pos                14                                       /*!< CLK PLLCON: OUT_DV Position */
#define CLK_PLLCON_OUT_DV_Msk                (3ul << CLK_PLLCON_OUT_DV_Pos)           /*!< CLK PLLCON: OUT_DV Mask */

#define CLK_PLLCON_IN_DV_Pos                 9                                        /*!< CLK PLLCON: IN_DV Position */
#define CLK_PLLCON_IN_DV_Msk                 (0x1Ful << CLK_PLLCON_IN_DV_Pos)         /*!< CLK PLLCON: IN_DV Mask */

#define CLK_PLLCON_FB_DV_Pos                 0                                        /*!< CLK PLLCON: FB_DV Position */
#define CLK_PLLCON_FB_DV_Msk                 (0x1FFul << CLK_PLLCON_FB_DV_Pos)        /*!< CLK PLLCON: FB_DV Mask */

/* CLK FRQDIV Bit Field Definitions */
#define CLK_FRQDIV_DIVIDER_EN_Pos            4                                        /*!< CLK FRQDIV: DIVIDER_EN Position */
#define CLK_FRQDIV_DIVIDER_EN_Msk            (1ul << CLK_FRQDIV_DIVIDER_EN_Pos)       /*!< CLK FRQDIV: DIVIDER_EN Mask */

#define CLK_FRQDIV_FSEL_Pos                  0                                        /*!< CLK FRQDIV: FRQDIV_FSEL Position */
#define CLK_FRQDIV_FSEL_Msk                  (0xFul << CLK_FRQDIV_FSEL_Pos)           /*!< CLK FRQDIV: FRQDIV_FSEL Mask */

/* CLK APBDIV Bit Field Definitions */
#define CLK_APBDIV_APBDIV_Pos                0                                        /*!< CLK FRQDIV: DIVIDER_EN Position */
#define CLK_APBDIV_APBDIV_Msk                (1ul << CLK_APBDIV_APBDIV_Pos)           /*!< CLK FRQDIV: DIVIDER_EN Mask */

/*@}*/ /* end of group NUC123_CLK */


/*---------------------------- Global Controller -----------------------------*/
/** @addtogroup NUC123_GCR NUC123_GCR
  Memory Mapped Structure for NUC123 Series Global Control Register
  @{
 */
typedef struct
{
    __I uint32_t PDID;				/*!< Offset: 0x00  Part Device Identification Number Register  */
    __IO uint32_t RSTSRC;			/*!< Offset: 0x04  System Reset Source Register  */
    __IO uint32_t IPRSTC1;			/*!< Offset: 0x08  IP Reset Control Register1  */
    __IO uint32_t IPRSTC2;			/*!< Offset: 0x0C  IP Reset Control Register2 */
    uint32_t RESERVE0[2];		 
    __IO uint32_t BODCR;			/*!< Offset: 0x18  Brown-out Detector Control Register*/
    uint32_t RESERVE1[2];		 
    __IO uint32_t PORCR;			/*!< Offset: 0x24  Power-On-Reset Controller Register  */
    uint32_t RESERVE2[2];		 
    __IO uint32_t GPA_MFP;			/*!< Offset: 0x30  GPIOA Multiple Function and Input Type Control Register  */
    __IO uint32_t GPB_MFP;			/*!< Offset: 0x34  GPIOB Multiple Function and Input Type Control Register  */
    __IO uint32_t GPC_MFP;			/*!< Offset: 0x38  GPIOC Multiple Function and Input Type Control Register */
    __IO uint32_t GPD_MFP;			/*!< Offset: 0x3C  GPIOD Multiple Function and Input Type Control Register */
    __IO uint32_t RESERVE3;		 
    __IO uint32_t GPF_MFP;			/*!< Offset: 0x44  GPIOF Multiple Function and Input Type Control Register */
    uint32_t RESERVE4[2];		 
    __IO uint32_t ALT_MFP;			/*!< Offset: 0x50  Alternative Multiple Function Pin Control Register */
    __IO uint32_t ALT_MFP1;			/*!< Offset: 0x54  Alternative Multiple Function Pin Control Register1 */
    uint32_t RESERVE5[26];		 
    __IO uint32_t GPA_IOCR;			/*!< Offset: 0xC0  GPIOA IO Control Register */
    __IO uint32_t GPB_IOCR;			/*!< Offset: 0xC4  GPIOB IO Control Register  */
    uint32_t RESERVE6;  		 
    __IO uint32_t GPD_IOCR; 		/*!< Offset: 0xCC  GPIOB IO Control Register */
    uint32_t RESERVE7[12];     	 
    __IO uint32_t REGWRPROT;		/*!< Offset: 0x100 Register Write Protect register */
} GCR_T;

/* GCR RSTSRC Bit Field Definitions */
#define SYS_RSTSRC_RSTS_CPU_Pos                 7                                   /*!< GCR RSTSRC: RSTS_CPU Position */
#define SYS_RSTSRC_RSTS_CPU_Msk                 (1ul << SYS_RSTSRC_RSTS_CPU_Pos)    /*!< GCR RSTSRC: RSTS_CPU Mask */

#define SYS_RSTSRC_RSTS_SYS_Pos                 5                                   /*!< GCR RSTSRC: RSTS_SYS Position */
#define SYS_RSTSRC_RSTS_SYS_Msk                 (1ul << SYS_RSTSRC_RSTS_SYS_Pos)    /*!< GCR RSTSRC: RSTS_SYS Mask */

#define SYS_RSTSRC_RSTS_BOD_Pos                 4                                   /*!< GCR RSTSRC: RSTS_BOD Position */
#define SYS_RSTSRC_RSTS_BOD_Msk                 (1ul << SYS_RSTSRC_RSTS_BOD_Pos)    /*!< GCR RSTSRC: RSTS_BOD Mask */

#define SYS_RSTSRC_RSTS_LVR_Pos                 3                                   /*!< GCR RSTSRC: RSTS_LVR Position */
#define SYS_RSTSRC_RSTS_LVR_Msk                 (1ul << SYS_RSTSRC_RSTS_LVR_Pos)    /*!< GCR RSTSRC: RSTS_LVR Mask */

#define SYS_RSTSRC_RSTS_WDT_Pos                 2                                   /*!< GCR RSTSRC: RSTS_WDT Position */
#define SYS_RSTSRC_RSTS_WDT_Msk                 (1ul << SYS_RSTSRC_RSTS_WDT_Pos)    /*!< GCR RSTSRC: RSTS_WDT Mask */

#define SYS_RSTSRC_RSTS_RESET_Pos               1                                   /*!< GCR RSTSRC: RSTS_RESET Position */
#define SYS_RSTSRC_RSTS_RESET_Msk               (1ul << SYS_RSTSRC_RSTS_RESET_Pos)  /*!< GCR RSTSRC: RSTS_RESET Mask */

#define SYS_RSTSRC_RSTS_POR_Pos                 0                                   /*!< GCR RSTSRC: RSTS_POR Position */
#define SYS_RSTSRC_RSTS_POR_Msk                 (1ul << SYS_RSTSRC_RSTS_POR_Pos)    /*!< GCR RSTSRC: RSTS_POR Mask */

/* GCR IPRSTC1 Bit Field Definitions */
#define SYS_IPRSTC1_PDMA_RST_Pos                2                                   /*!< GCR IPRSTC1: PDMA_RST Position */
#define SYS_IPRSTC1_PDMA_RST_Msk                (1ul << SYS_IPRSTC1_PDMA_RST_Pos)   /*!< GCR IPRSTC1: PDMA_RST Mask */

#define SYS_IPRSTC1_CPU_RST_Pos                 1                                   /*!< GCR IPRSTC1: CPU_RST Position */
#define SYS_IPRSTC1_CPU_RST_Msk                 (1ul << SYS_IPRSTC1_CPU_RST_Pos)    /*!< GCR IPRSTC1: CPU_RST Mask */

#define SYS_IPRSTC1_CHIP_RST_Pos                0                                   /*!< GCR IPRSTC1: CHIP_RST Position */
#define SYS_IPRSTC1_CHIP_RST_Msk                (1ul << SYS_IPRSTC1_CHIP_RST_Pos)   /*!< GCR IPRSTC1: CHIP_RST Mask */

/* GCR IPRSTC2 Bit Field Definitions */
#define SYS_IPRSTC2_I2S_RST_Pos                 29                                  /*!< GCR IPRSTC2: I2S_RST Position */
#define SYS_IPRSTC2_I2S_RST_Msk                 (1ul << SYS_IPRSTC2_I2S_RST_Pos)    /*!< GCR IPRSTC2: I2S_RST Mask */

#define SYS_IPRSTC2_ADC_RST_Pos                 28                                  /*!< GCR IPRSTC2: ADC_RST Position */
#define SYS_IPRSTC2_ADC_RST_Msk                 (1ul << SYS_IPRSTC2_ADC_RST_Pos)    /*!< GCR IPRSTC2: ADC_RST Mask */

#define SYS_IPRSTC2_USBD_RST_Pos                27                                  /*!< GCR IPRSTC2: USBD_RST Position */
#define SYS_IPRSTC2_USBD_RST_Msk                (1ul << SYS_IPRSTC2_USBD_RST_Pos)   /*!< GCR IPRSTC2: USBD_RST Mask */

#define SYS_IPRSTC2_PS2_RST_Pos                 23                                  /*!< GCR IPRSTC2: PS2_RST Position */
#define SYS_IPRSTC2_PS2_RST_Msk                 (1ul << SYS_IPRSTC2_PS2_RST_Pos)    /*!< GCR IPRSTC2: PS2_RST Mask */

#define SYS_IPRSTC2_PWM03_RST_Pos               20                                  /*!< GCR IPRSTC2: PWM03_RST Position */
#define SYS_IPRSTC2_PWM03_RST_Msk               (1ul << SYS_IPRSTC2_PWM03_RST_Pos)  /*!< GCR IPRSTC2: PWM03_RST Mask */

#define SYS_IPRSTC2_UART1_RST_Pos               17                                  /*!< GCR IPRSTC2: UART1_RST Position */
#define SYS_IPRSTC2_UART1_RST_Msk               (1ul << SYS_IPRSTC2_UART1_RST_Pos)  /*!< GCR IPRSTC2: UART1_RST Mask */

#define SYS_IPRSTC2_UART0_RST_Pos               16                                  /*!< GCR IPRSTC2: UART0_RST Position */
#define SYS_IPRSTC2_UART0_RST_Msk               (1ul << SYS_IPRSTC2_UART0_RST_Pos)  /*!< GCR IPRSTC2: UART0_RST Mask */

#define SYS_IPRSTC2_SPI2_RST_Pos                14                                  /*!< GCR IPRSTC2: SPI2_RST Position */
#define SYS_IPRSTC2_SPI2_RST_Msk                (1ul << SYS_IPRSTC2_SPI2_RST_Pos)   /*!< GCR IPRSTC2: SPI2_RST Mask */

#define SYS_IPRSTC2_SPI1_RST_Pos                13                                  /*!< GCR IPRSTC2: SPI1_RST Position */
#define SYS_IPRSTC2_SPI1_RST_Msk                (1ul << SYS_IPRSTC2_SPI1_RST_Pos)   /*!< GCR IPRSTC2: SPI1_RST Mask */

#define SYS_IPRSTC2_SPI0_RST_Pos                12                                  /*!< GCR IPRSTC2: SPI0_RST Position */
#define SYS_IPRSTC2_SPI0_RST_Msk                (1ul << SYS_IPRSTC2_SPI0_RST_Pos)   /*!< GCR IPRSTC2: SPI0_RST Mask */

#define SYS_IPRSTC2_I2C1_RST_Pos                9                                   /*!< GCR IPRSTC2: I2C1_RST Position */
#define SYS_IPRSTC2_I2C1_RST_Msk                (1ul << SYS_IPRSTC2_I2C1_RST_Pos)   /*!< GCR IPRSTC2: I2C1_RST Mask */

#define SYS_IPRSTC2_I2C0_RST_Pos                8                                   /*!< GCR IPRSTC2: I2C0_RST Position */
#define SYS_IPRSTC2_I2C0_RST_Msk                (1ul << SYS_IPRSTC2_I2C0_RST_Pos)   /*!< GCR IPRSTC2: I2C0_RST Mask */

#define SYS_IPRSTC2_TMR3_RST_Pos                5                                   /*!< GCR IPRSTC2: TMR3_RST Position */
#define SYS_IPRSTC2_TMR3_RST_Msk                (1ul << SYS_IPRSTC2_TMR3_RST_Pos)   /*!< GCR IPRSTC2: TMR3_RST Mask */

#define SYS_IPRSTC2_TMR2_RST_Pos                4                                   /*!< GCR IPRSTC2: TMR2_RST Position */
#define SYS_IPRSTC2_TMR2_RST_Msk                (1ul << SYS_IPRSTC2_TMR2_RST_Pos)   /*!< GCR IPRSTC2: TMR2_RST Mask */

#define SYS_IPRSTC2_TMR1_RST_Pos                3                                   /*!< GCR IPRSTC2: TMR1_RST Position */
#define SYS_IPRSTC2_TMR1_RST_Msk                (1ul << SYS_IPRSTC2_TMR1_RST_Pos)   /*!< GCR IPRSTC2: TMR1_RST Mask */

#define SYS_IPRSTC2_TMR0_RST_Pos                2                                   /*!< GCR IPRSTC2: TMR0_RST Position */
#define SYS_IPRSTC2_TMR0_RST_Msk                (1ul << SYS_IPRSTC2_TMR0_RST_Pos)   /*!< GCR IPRSTC2: TMR0_RST Mask */

#define SYS_IPRSTC2_GPIO_RST_Pos                1                                   /*!< GCR IPRSTC2: GPIO_RST Position */
#define SYS_IPRSTC2_GPIO_RST_Msk                (1ul << SYS_IPRSTC2_GPIO_RST_Pos)   /*!< GCR IPRSTC2: GPIO_RST Mask */

/* GCR BODCR Bit Field Definitions */
#define SYS_BODCR_LVR_EN_Pos                    7                                   /*!< GCR BODCR: LVR_EN Position */
#define SYS_BODCR_LVR_EN_Msk                    (1ul << SYS_BODCR_LVR_EN_Pos)       /*!< GCR BODCR: LVR_EN Mask */

#define SYS_BODCR_BOD_OUT_Pos                   6                                   /*!< GCR BODCR: BOD_OUT Position */
#define SYS_BODCR_BOD_OUT_Msk                   (1ul << SYS_BODCR_BOD_OUT_Pos)      /*!< GCR BODCR: BOD_OUT Mask */

#define SYS_BODCR_BOD_LPM_Pos                   5                                   /*!< GCR BODCR: BOD_LPM Position */
#define SYS_BODCR_BOD_LPM_Msk                   (1ul << SYS_BODCR_BOD_LPM_Pos)      /*!< GCR BODCR: BOD_LPM Mask */

#define SYS_BODCR_BOD_INTF_Pos                  4                                   /*!< GCR BODCR: BOD_INTF Position */
#define SYS_BODCR_BOD_INTF_Msk                  (1ul << SYS_BODCR_BOD_INTF_Pos)     /*!< GCR BODCR: BOD_INTF Mask */

#define SYS_BODCR_BOD_RSTEN_Pos                 3                                   /*!< GCR BODCR: BOD_RSTEN Position */
#define SYS_BODCR_BOD_RSTEN_Msk                 (1ul << SYS_BODCR_BOD_RSTEN_Pos)    /*!< GCR BODCR: BOD_RSTEN Mask */

#define SYS_BODCR_BOD_VL_Pos                    1                                   /*!< GCR BODCR: BOD_VL Position */
#define SYS_BODCR_BOD_VL_Msk                    (3ul << SYS_BODCR_BOD_VL_Pos)       /*!< GCR BODCR: BOD_VL Mask */

#define SYS_BODCR_BOD_EN_Pos                    0                                   /*!< GCR BODCR: BOD_EN Position */
#define SYS_BODCR_BOD_EN_Msk                    (1ul << SYS_BODCR_BOD_EN_Pos)       /*!< GCR BODCR: BOD_EN Mask */

/* GCR PORCR Bit Field Definitions */
#define SYS_PORCR_POR_DIS_CODE_Pos              0                                           /*!< GCR PORCR: POR_DIS_CODE Position */
#define SYS_PORCR_POR_DIS_CODE_Msk              (0xFFFFul << SYS_PORCR_POR_DIS_CODE_Pos)    /*!< GCR PORCR: POR_DIS_CODE Mask */

/* GCR GPAMFP Bit Field Definitions */
#define SYS_GPA_MFP_GPA_TYPE_Pos                 16                                         /*!< GCR GPA_MFP: GPA_TYPE Position */
#define SYS_GPA_MFP_GPA_TYPE_Msk                 (0xFFFFul << SYS_GPA_MFP_GPA_TYPE_Pos)     /*!< GCR GPA_MFP: GPA_TYPE Mask */

#define SYS_GPA_MFP_GPA_MFP_Pos                  0                                          /*!< GCR GPA_MFP: GPA_MFP Position */
#define SYS_GPA_MFP_GPA_MFP_Msk                  (0xFFFFul << SYS_GPA_MFP_GPA_MFP_Pos)      /*!< GCR GPA_MFP: GPA_MFP Mask */


/* GCR GPBMFP Bit Field Definitions */
#define SYS_GPB_MFP_GPB_TYPE_Pos                 16                                         /*!< GCR GPB_MFP: GPB_TYPE Position */
#define SYS_GPB_MFP_GPB_TYPE_Msk                 (0xFFFFul << SYS_GPB_MFP_GPB_TYPE_Pos)     /*!< GCR GPB_MFP: GPB_TYPE Mask */

#define SYS_GPB_MFP_GPB_MFP_Pos                  0                                          /*!< GCR GPB_MFP: GPB_MFP Position */
#define SYS_GPB_MFP_GPB_MFP_Msk                  (0xFFFFul << SYS_GPB_MFP_GPB_MFP_Pos)      /*!< GCR GPB_MFP: GPB_MFP Mask */

/* GCR GPCMFP Bit Field Definitions */
#define SYS_GPC_MFP_GPC_TYPE_Pos                 16                                         /*!< GCR GPC_MFP: GPC_TYPE Position */
#define SYS_GPC_MFP_GPC_TYPE_Msk                 (0xFFFFul << SYS_GPC_MFP_GPC_TYPE_Pos)     /*!< GCR GPC_MFP: GPC_TYPE Mask */

#define SYS_GPC_MFP_GPC_MFP_Pos                  0                                          /*!< GCR GPC_MFP: GPC_MFP Position */
#define SYS_GPC_MFP_GPC_MFP_Msk                  (0xFFFFul << SYS_GPC_MFP_GPC_MFP_Pos)      /*!< GCR GPC_MFP: GPC_MFP Mask */

/* GCR GPDMFP Bit Field Definitions */
#define SYS_GPD_MFP_GPD_TYPE_Pos                 16                                         /*!< GCR GPD_MFP: GPD_TYPE Position */
#define SYS_GPD_MFP_GPD_TYPE_Msk                 (0xFFFFul << SYS_GPD_MFP_GPD_TYPE_Pos)     /*!< GCR GPD_MFP: GPD_TYPE Mask */

#define SYS_GPD_MFP_GPD_MFP_Pos                  0                                          /*!< GCR GPD_MFP: GPD_MFP Position */
#define SYS_GPD_MFP_GPD_MFP_Msk                  (0xFFFFul << SYS_GPD_MFP_GPD_MFP_Pos)      /*!< GCR GPD_MFP: GPD_MFP Mask */

/* GCR GPFMFP Bit Field Definitions */
#define SYS_GPF_MFP_GPF_TYPE_Pos                 16                                         /*!< GCR GPF_MFP: GPF_TYPE Position */
#define SYS_GPF_MFP_GPF_TYPE_Msk                 (0xFul << SYS_GPF_MFP_GPF_TYPE_Pos)        /*!< GCR GPF_MFP: GPF_TYPE Mask */

#define SYS_GPF_MFP_GPF_MFP3_Pos                 3                                          /*!< GCR GPF_MFP: GPF_MFP3 Position */
#define SYS_GPF_MFP_GPF_MFP3_Msk                 (1ul << SYS_GPF_MFP_GPF_MFP3_Pos)          /*!< GCR GPF_MFP: GPF_MFP3 Mask */

#define SYS_GPF_MFP_GPF_MFP2_Pos                 2                                          /*!< GCR GPF_MFP: GPF_MFP2 Position */
#define SYS_GPF_MFP_GPF_MFP2_Msk                 (1ul << SYS_GPF_MFP_GPF_MFP2_Pos)          /*!< GCR GPF_MFP: GPF_MFP2 Mask */

#define SYS_GPF_MFP_GPF_MFP1_Pos                 1                                          /*!< GCR GPF_MFP: GPF_MFP1 Position */
#define SYS_GPF_MFP_GPF_MFP1_Msk                 (1ul << SYS_GPF_MFP_GPF_MFP1_Pos)          /*!< GCR GPF_MFP: GPF_MFP1 Mask */

#define SYS_GPF_MFP_GPF_MFP0_Pos                 0                                          /*!< GCR GPF_MFP: GPF_MFP0 Position */
#define SYS_GPF_MFP_GPF_MFP0_Msk                 (1ul << SYS_GPF_MFP_GPF_MFP0_Pos)          /*!< GCR GPF_MFP: GPF_MFP0 Mask */

/* GCR ALTMFP Bit Field Definitions */
#define SYS_ALT_MFP_PC5_MFP1_Pos                 30                                         /*!< GCR ALT_MFP: PC5_MFP1 Position */
#define SYS_ALT_MFP_PC5_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC5_MFP1_Pos)          /*!< GCR ALT_MFP: PC5_MFP1 Mask */

#define SYS_ALT_MFP_PC4_MFP1_Pos                 29                                         /*!< GCR ALT_MFP: PC4_MFP1 Position */
#define SYS_ALT_MFP_PC4_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC4_MFP1_Pos)          /*!< GCR ALT_MFP: PC4_MFP1 Mask */

#define SYS_ALT_MFP_PB3_MFP1_Pos                 27                                         /*!< GCR ALT_MFP: PB3_MFP1 Position */
#define SYS_ALT_MFP_PB3_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB3_MFP1_Pos)          /*!< GCR ALT_MFP: PB3_MFP1 Mask */

#define SYS_ALT_MFP_PB2_MFP1_Pos                 26                                         /*!< GCR ALT_MFP: PB2_MFP1 Position */
#define SYS_ALT_MFP_PB2_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB2_MFP1_Pos)          /*!< GCR ALT_MFP: PB3_MFP1 Mask */

#define SYS_ALT_MFP_PB15_MFP1_Pos                24                                         /*!< GCR ALT_MFP: PB15_MFP1 Position */
#define SYS_ALT_MFP_PB15_MFP1_Msk                (1ul << SYS_ALT_MFP_PB15_MFP1_Pos)         /*!< GCR ALT_MFP: PB15_MFP1 Mask */

#define SYS_ALT_MFP_PC13_MFP1_Pos                21                                         /*!< GCR ALT_MFP: PC13_MFP1 Position */
#define SYS_ALT_MFP_PC13_MFP1_Msk                (1ul << SYS_ALT_MFP_PC13_MFP1_Pos)         /*!< GCR ALT_MFP: PC13_MFP1 Mask */

#define SYS_ALT_MFP_PC12_MFP1_Pos                20                                         /*!< GCR ALT_MFP: PC12_MFP1 Position */
#define SYS_ALT_MFP_PC12_MFP1_Msk                (1ul << SYS_ALT_MFP_PC12_MFP1_Pos)         /*!< GCR ALT_MFP: PC12_MFP1 Mask */

#define SYS_ALT_MFP_PB5_MFP1_Pos                 18                                         /*!< GCR ALT_MFP: PB5_MFP1 Position */
#define SYS_ALT_MFP_PB5_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB5_MFP1_Pos)          /*!< GCR ALT_MFP: PB5_MFP1 Mask */

#define SYS_ALT_MFP_PB6_MFP1_Pos                 17                                         /*!< GCR ALT_MFP: PB6_MFP1 Position */
#define SYS_ALT_MFP_PB6_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB6_MFP1_Pos)          /*!< GCR ALT_MFP: PB6_MFP1 Mask */

#define SYS_ALT_MFP_PB7_MFP1_Pos                 16                                         /*!< GCR ALT_MFP: PB7_MFP1 Position */
#define SYS_ALT_MFP_PB7_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB7_MFP1_Pos)          /*!< GCR ALT_MFP: PB7_MFP1 Mask */

#define SYS_ALT_MFP_PB4_MFP1_Pos                 15                                         /*!< GCR ALT_MFP: PB4_MFP1 Position */
#define SYS_ALT_MFP_PB4_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB4_MFP1_Pos)          /*!< GCR ALT_MFP: PB4_MFP1 Mask */

#define SYS_ALT_MFP_PA10_MFP1_Pos                12                                         /*!< GCR ALT_MFP: PA10_MFP1 Position */
#define SYS_ALT_MFP_PA10_MFP1_Msk                (1ul << SYS_ALT_MFP_PA10_MFP1_Pos)         /*!< GCR ALT_MFP: PA10_MFP1 Mask */

#define SYS_ALT_MFP_PA11_MFP1_Pos                11                                         /*!< GCR ALT_MFP: PA11_MFP1 Position */
#define SYS_ALT_MFP_PA11_MFP1_Msk                (1ul << SYS_ALT_MFP_PA11_MFP1_Pos)         /*!< GCR ALT_MFP: PA11_MFP1 Mask */

#define SYS_ALT_MFP_PB12_MFP1_Pos                10                                         /*!< GCR ALT_MFP: PB12_MFP1 Position */
#define SYS_ALT_MFP_PB12_MFP1_Msk                (1ul << SYS_ALT_MFP_PB12_MFP1_Pos)         /*!< GCR ALT_MFP: PB12_MFP1 Mask */

#define SYS_ALT_MFP_PA15_MFP1_Pos                9                                          /*!< GCR ALT_MFP: PA15_MFP1 Position */
#define SYS_ALT_MFP_PA15_MFP1_Msk                (1ul << SYS_ALT_MFP_PA15_MFP1_Pos)         /*!< GCR ALT_MFP: PA15_MFP1 Mask */

#define SYS_ALT_MFP_PC3_MFP1_Pos                 8                                          /*!< GCR ALT_MFP: PC3_MFP1 Position */
#define SYS_ALT_MFP_PC3_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC3_MFP1_Pos)          /*!< GCR ALT_MFP: PC3_MFP1 Mask */

#define SYS_ALT_MFP_PC2_MFP1_Pos                 7                                          /*!< GCR ALT_MFP: PC2_MFP1 Position */
#define SYS_ALT_MFP_PC2_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC2_MFP1_Pos)          /*!< GCR ALT_MFP: PC2_MFP1 Mask */

#define SYS_ALT_MFP_PC1_MFP1_Pos                 6                                          /*!< GCR ALT_MFP: PC1_MFP1 Position */
#define SYS_ALT_MFP_PC1_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC1_MFP1_Pos)          /*!< GCR ALT_MFP: PC1_MFP1 Mask */

#define SYS_ALT_MFP_PC0_MFP1_Pos                 5                                          /*!< GCR ALT_MFP: PC0_MFP1 Position */
#define SYS_ALT_MFP_PC0_MFP1_Msk                 (1ul << SYS_ALT_MFP_PC0_MFP1_Pos)          /*!< GCR ALT_MFP: PC0_MFP1 Mask */

#define SYS_ALT_MFP_PB9_MFP1_Pos                 1                                          /*!< GCR ALT_MFP: PB9_MFP1 Position */
#define SYS_ALT_MFP_PB9_MFP1_Msk                 (1ul << SYS_ALT_MFP_PB9_MFP1_Pos)          /*!< GCR ALT_MFP: PB9_MFP1 Mask */

#define SYS_ALT_MFP_PB10_MFP1_Pos                0                                          /*!< GCR ALT_MFP: PB10_MFP1 Position */
#define SYS_ALT_MFP_PB10_MFP1_Msk                (1ul << SYS_ALT_MFP_PB10_MFP1_Pos)         /*!< GCR ALT_MFP: PB10_MFP1 Mask */

/* GCR ALTMFP1 Bit Field Definitions */
#define SYS_ALT_MFP1_PF3_MFP1_Pos                26                                         /*!< GCR ALT_MFP1: PF3_MFP1 Position */
#define SYS_ALT_MFP1_PF3_MFP1_Msk                (3ul << SYS_ALT_MFP1_PF3_MFP1_Pos)         /*!< GCR ALT_MFP1: PF3_MFP1 Mask */

#define SYS_ALT_MFP1_PF2_MFP1_Pos                24                                         /*!< GCR ALT_MFP1: PF2_MFP1 Position */
#define SYS_ALT_MFP1_PF2_MFP1_Msk                (3ul << SYS_ALT_MFP1_PF2_MFP1_Pos)         /*!< GCR ALT_MFP1: PF2_MFP1 Mask */

#define SYS_ALT_MFP1_PD5_MFP1_Pos                21                                         /*!< GCR ALT_MFP1: PD5_MFP1 Position */
#define SYS_ALT_MFP1_PD5_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD5_MFP1_Pos)         /*!< GCR ALT_MFP1: PD5_MFP1 Mask */

#define SYS_ALT_MFP1_PD4_MFP1_Pos                20                                         /*!< GCR ALT_MFP1: PD4_MFP1 Position */
#define SYS_ALT_MFP1_PD4_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD4_MFP1_Pos)         /*!< GCR ALT_MFP1: PD4_MFP1 Mask */

#define SYS_ALT_MFP1_PD3_MFP1_Pos                19                                         /*!< GCR ALT_MFP1: PD3_MFP1 Position */
#define SYS_ALT_MFP1_PD3_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD3_MFP1_Pos)         /*!< GCR ALT_MFP1: PD3_MFP1 Mask */

#define SYS_ALT_MFP1_PD2_MFP1_Pos                18                                         /*!< GCR ALT_MFP1: PD2_MFP1 Position */
#define SYS_ALT_MFP1_PD2_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD2_MFP1_Pos)         /*!< GCR ALT_MFP1: PD2_MFP1 Mask */

#define SYS_ALT_MFP1_PD1_MFP1_Pos                17                                         /*!< GCR ALT_MFP1: PD1_MFP1 Position */
#define SYS_ALT_MFP1_PD1_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD1_MFP1_Pos)         /*!< GCR ALT_MFP1: PD1_MFP1 Mask */

#define SYS_ALT_MFP1_PD0_MFP1_Pos                16                                         /*!< GCR ALT_MFP1: PD0_MFP1 Position */
#define SYS_ALT_MFP1_PD0_MFP1_Msk                (1ul << SYS_ALT_MFP1_PD0_MFP1_Pos)         /*!< GCR ALT_MFP1: PD0_MFP1 Mask */

/* GCR DFPCSR Bit Field Definitions */
#define SYS_DFP_CSR_DFP6_CST_Pos                 6                                          /*!< GCR DFP_CSR: DFP6_CST Position */
#define SYS_DFP_CSR_DFP6_CST_Msk                 (1ul << SYS_DFP_CSR_DFP6_CST_Pos)          /*!< GCR DFP_CSR: DFP6_CST Mask */

#define SYS_DFP_CSR_DFP5_CST_Pos                 5                                          /*!< GCR DFP_CSR: DFP5_CST Position */
#define SYS_DFP_CSR_DFP5_CST_Msk                 (1ul << SYS_DFP_CSR_DFP5_CST_Pos)          /*!< GCR DFP_CSR: DFP5_CST Mask */

#define SYS_DFP_CSR_DFP4_CST_Pos                 4                                          /*!< GCR DFP_CSR: DFP4_CST Position */
#define SYS_DFP_CSR_DFP4_CST_Msk                 (1ul << SYS_DFP_CSR_DFP4_CST_Pos)          /*!< GCR DFP_CSR: DFP4_CST Mask */

#define SYS_DFP_CSR_DFP3_CST_Pos                 3                                          /*!< GCR DFP_CSR: DFP3_CST Position */
#define SYS_DFP_CSR_DFP3_CST_Msk                 (1ul << SYS_DFP_CSR_DFP3_CST_Pos)          /*!< GCR DFP_CSR: DFP3_CST Mask */

#define SYS_DFP_CSR_DFP2_CST_Pos                 2                                          /*!< GCR DFP_CSR: DFP2_CST Position */
#define SYS_DFP_CSR_DFP2_CST_Msk                 (1ul << SYS_DFP_CSR_DFP2_CST_Pos)          /*!< GCR DFP_CSR: DFP2_CST Mask */

#define SYS_DFP_CSR_DFP1_CST_Pos                 1                                          /*!< GCR DFP_CSR: DFP1_CST Position */
#define SYS_DFP_CSR_DFP1_CST_Msk                 (1ul << SYS_DFP_CSR_DFP1_CST_Pos)          /*!< GCR DFP_CSR: DFP1_CST Mask */

#define SYS_DFP_CSR_DFP0_CST_Pos                 0                                          /*!< GCR DFP_CSR: DFP0_CST Position */
#define SYS_DFP_CSR_DFP0_CST_Msk                 (1ul << SYS_DFP_CSR_DFP0_CST_Pos)          /*!< GCR DFP_CSR: DFP0_CST Mask */

/* GCR GPAIOCR Bit Field Definitions */
#define SYS_GPA_IOCR_GPA11_DS_Pos                11                                         /*!< GCR GPA_IOCR: GPA11_DS Position */
#define SYS_GPA_IOCR_GPA11_DS_Msk                (1ul << SYS_GPA_IOCR_GPA11_DS_Pos)         /*!< GCR GPA_IOCR: GPA11_DS Mask */

#define SYS_GPA_IOCR_GPA10_DS_Pos                10                                         /*!< GCR GPA_IOCR: GPA10_DS Position */
#define SYS_GPA_IOCR_GPA10_DS_Msk                (1ul << SYS_GPA_IOCR_GPA10_DS_Pos)         /*!< GCR GPA_IOCR: GPA10_DS Mask */

/* GCR GPBIOCR Bit Field Definitions */
#define SYS_GPB_IOCR_GPB14_DS_Pos                14                                         /*!< GCR GPB_IOCR: GPB14_DS Position */
#define SYS_GPB_IOCR_GPB14_DS_Msk                (1ul << SYS_GPA_IOCR_GPB14_DS_Pos)         /*!< GCR GPB_IOCR: GPB14_DS Mask */

#define SYS_GPB_IOCR_GPB13_DS_Pos                13                                         /*!< GCR GPB_IOCR: GPB13_DS Position */
#define SYS_GPB_IOCR_GPB13_DS_Msk                (1ul << SYS_GPA_IOCR_GPB13_DS_Pos)         /*!< GCR GPB_IOCR: GPB13_DS Mask */

#define SYS_GPB_IOCR_GPB12_DS_Pos                12                                         /*!< GCR GPB_IOCR: GPB12_DS Position */
#define SYS_GPB_IOCR_GPB12_DS_Msk                (1ul << SYS_GPA_IOCR_GPB12_DS_Pos)         /*!< GCR GPB_IOCR: GPB12_DS Mask */

#define SYS_GPB_IOCR_GPB8_DS_Pos                 8                                          /*!< GCR GPB_IOCR: GPB8_DS Position */
#define SYS_GPB_IOCR_GPB8_DS_Msk                 (1ul << SYS_GPA_IOCR_GPB8_DS_Pos)          /*!< GCR GPB_IOCR: GPB8_DS Mask */

#define SYS_GPB_IOCR_GPB7_DS_Pos                 7                                          /*!< GCR GPB_IOCR: GPB7_DS Position */
#define SYS_GPB_IOCR_GPB7_DS_Msk                 (1ul << SYS_GPA_IOCR_GPB7_DS_Pos)          /*!< GCR GPB_IOCR: GPB7_DS Mask */

#define SYS_GPB_IOCR_GPB6_DS_Pos                 6                                          /*!< GCR GPB_IOCR: GPB6_DS Position */
#define SYS_GPB_IOCR_GPB6_DS_Msk                 (1ul << SYS_GPA_IOCR_GPB6_DS_Pos)          /*!< GCR GPB_IOCR: GPB6_DS Mask */

#define SYS_GPB_IOCR_GPB5_DS_Pos                 5                                          /*!< GCR GPB_IOCR: GPB5_DS Position */
#define SYS_GPB_IOCR_GPB5_DS_Msk                 (1ul << SYS_GPA_IOCR_GPB5_DS_Pos)          /*!< GCR GPB_IOCR: GPB5_DS Mask */

#define SYS_GPB_IOCR_GPB4_DS_Pos                 4                                          /*!< GCR GPB_IOCR: GPB4_DS Position */
#define SYS_GPB_IOCR_GPB4_DS_Msk                 (1ul << SYS_GPA_IOCR_GPB4_DS_Pos)          /*!< GCR GPB_IOCR: GPB4_DS Mask */

/* GCR GPDIOCR Bit Field Definitions */
#define SYS_GPD_IOCR_GPD11_DS_Pos                11                                         /*!< GCR GPD_IOCR: GPD11_DS Position */
#define SYS_GPD_IOCR_GPD11_DS_Msk                (1ul << SYS_GPD_IOCR_GPD11_DS_Pos)         /*!< GCR GPD_IOCR: GPD11_DS Mask */

#define SYS_GPD_IOCR_GPD10_DS_Pos                10                                         /*!< GCR GPD_IOCR: GPD10_DS Position */
#define SYS_GPD_IOCR_GPD10_DS_Msk                (1ul << SYS_GPD_IOCR_GPD10_DS_Pos)         /*!< GCR GPD_IOCR: GPD10_DS Mask */

#define SYS_GPD_IOCR_GPD9_DS_Pos                 9                                          /*!< GCR GPD_IOCR: GPD9_DS Position */
#define SYS_GPD_IOCR_GPD9_DS_Msk                 (1ul << SYS_GPD_IOCR_GPD9_DS_Pos)          /*!< GCR GPD_IOCR: GPD9_DS Mask */

#define SYS_GPD_IOCR_GPD8_DS_Pos                 8                                          /*!< GCR GPD_IOCR: GPD8_DS Position */
#define SYS_GPD_IOCR_GPD8_DS_Msk                 (1ul << SYS_GPD_IOCR_GPD8_DS_Pos)          /*!< GCR GPD_IOCR: GPD8_DS Mask */

/* GCR REGWRPROT Bit Field Definitions */
#define SYS_REGWRPROT_REGWRPROT_Pos             0                                           /*!< GCR REGWRPROT: REGWRPROT Position */
#define SYS_REGWRPROT_REGWRPROT_Msk             (0xFFul << SYS_REGWRPROT_REGWRPROT_Pos)     /*!< GCR REGWRPROT: REGWRPROT Mask */

/*@}*/ /* end of group NUC123_GCR */


/*-------------------------- FLASH Memory Controller -------------------------*/
/** @addtogroup NUC123_FMC NUC123 FMC
  Memory Mapped Structure for NUC123 Series Flash Memory Controller
  @{
 */
typedef struct
{
    /**
     * ISPCON
     * ===================================================================================================
     * Offset: 0x00  ISP Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ISPEN     |ISP Enable
     * |        |          |This bit is protected bit. ISP function enable bit. Set this bit to enable ISP function.
     * |        |          |1 = Enable ISP function
     * |        |          |0 = Disable ISP function
     * |[1]     |BS        |Boot Select 
     * |        |          |This bit is protected bit. Set/clear this bit to select next booting from LDROM/APROM, 
     * |        |          |respectively. This bit also functions as MCU booting status flag, which can be used to check where 
     * |        |          |MCU booted from. This bit is initiated with the inversed value of CBS in Config0 after power-
     * |        |          |on reset; It keeps the same value at other reset.
     * |        |          |1 = boot from LDROM
     * |        |          |0 = boot from APROM
     * |[4]     |CFGUEN    |Config Update Enable
     * |        |          |Writing this bit to 1 enables s/w to update Config value by ISP procedure regardless of program 
     * |        |          |code is running in APROM or LDROM.
     * |        |          |1 = Config update enable 
     * |        |          |0 = Config update disable
     * |[5]     |LDUEN     |LDROM Update Enable
     * |        |          |LDROM update enable bit. 
     * |        |          |1 = LDROM can be updated when the MCU runs in APROM.
     * |        |          |0 = LDROM cannot be updated
     * |[6]     |ISPFF     |ISP Fail Flag
     * |        |          |This bit is set by hardware when a triggered ISP meets any of the following conditions:
     * |        |          |(1) APROM writes to itself.
     * |        |          |(2) LDROM writes to itself. 
     * |        |          |(3) Destination address is illegal, such as over an available range.
     * |        |          |Write 1 to clear.
     * |[7]     |SWRST     |Software Reset
     * |        |          |Writing 1 to this bit to start software reset. 
     * |        |          |It is cleared by hardware after reset is finished.
     * |[10:8]  |PT        |Flash Program Time
     * |        |          |000 = 40 us
     * |        |          |001 = 45 us
     * |        |          |010 = 50 us
     * |        |          |011 = 55 us
     * |        |          |100 = 20 us
     * |        |          |101 = 25 us
     * |        |          |110 = 30 us
     * |        |          |111 = 35 us
     * |[14:12] |ET        |Flash Erase Time
     * |        |          |000 = 20 ms (default)
     * |        |          |001 = 25 ms 
     * |        |          |010 = 30 ms 
     * |        |          |011 = 35 ms 
     * |        |          |100 = 3  ms 
     * |        |          |101 = 5  ms 
     * |        |          |110 = 10 ms 
     * |        |          |111 = 15 ms 
     */    
    __IO uint32_t ISPCON;

    /**
     * ISPADR
     * ===================================================================================================
     * Offset: 0x04  ISP Address Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |ISPADR    |ISP Address 
     * |        |          |NuMicro M051 series equips with a maximum 16kx32 embedded flash, it supports word program 
     * |        |          |only. ISPARD[1:0] must be kept 2'b00 for ISP operation. 
     */    
    __IO uint32_t ISPADR;

    /**
     * ISPDAT
     * ===================================================================================================
     * Offset: 0x08  ISP Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |ISPDAT    |ISP Data 
     * |        |          |Write data to this register before ISP program operation
     * |        |          |Read data from this register after ISP read operation
     */    
    __IO uint32_t ISPDAT;

    /**
     * ISPCMD
     * ===================================================================================================
     * Offset: 0x0C  ISP Command Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[5:0]   |FOEN_FCEN_FCTRL|ISP Command 
     * |        |          |ISP command table is shown below:
     * |        |          |Operation Mode, FOEN, FCEN, FCTRL[3:0]
     * |        |          |Read          ,    0,    0, 0000
     * |        |          |Program       ,    1,    0, 0001
     * |        |          |Page Erase    ,    1,    0, 0010
     */    
    __IO uint32_t ISPCMD;

    /**
     * ISPTRG
     * ===================================================================================================
     * Offset: 0x10  IISP Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ISPGO     |ISP start trigger
     * |        |          |Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP 
     * |        |          |operation is finish. 
     * |        |          |1 = ISP is on going 
     * |        |          |0 = ISP done
     */    
    __IO uint32_t ISPTRG;

    /**
     * DFBADR
     * ===================================================================================================
     * Offset: 0x14  Data Flash Base Address Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DFBA      |Data Flash Base Address
     * |        |          |This register indicates data flash start address. 
     * |        |          | 
     * |        |          |It is a read only register. 
     * |        |          | 
     * |        |          |For 8/16/32/64kB flash memory device, the data flash size is 4kB and it start address is fixed at 
     * |        |          |0x01F000 by hardware internally.
     */    
    __I  uint32_t DFBADR;

    /**
     * FATCON
     * ===================================================================================================
     * Offset: 0x18  Flash Access Time Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |FPSEN     |Flash Power Save Enable
     * |        |          |If CPU clock is slower than 24 MHz, then s/w can enable flash power saving function.
     * |        |          |1 = Enable flash power saving
     * |        |          |0 = Disable flash power saving
     * |[3:1]   |FATS      |Flash Access Time Window Select
     * |        |          |These bits are used to decide flash sense amplifier active duration.
     * |        |          |000 = 40 ns
     * |        |          |001 = 50 ns
     * |        |          |010 = 60 ns
     * |        |          |011 = 70 ns
     * |        |          |100 = 80 ns
     * |        |          |101 = 90 ns
     * |        |          |110 = 100 ns
     * |        |          |111 = Reserved
     * |[4]     |L_SPEED   |Flash Low Speed Mode Enable
     * |        |          |1 = Flash access always no wait state (zero wait state)
     * |        |          |0 = Insert wait state while Flash access discontinued address. 
     * |        |          |Note: Set this bit only when HCLK <= 25MHz. If HCLK > 25MHz, CPU will fetch wrong 
     * |        |          |code and cause fail result.
     */    
    __IO uint32_t FATCON;

} FMC_T;

/* FMC ISPCON Bit Field Definitions */
#define FMC_ISPCON_ISPFF_Pos                    6                                       /*!< FMC ISPCON: ISPFF Position */
#define FMC_ISPCON_ISPFF_Msk                    (1ul << FMC_ISPCON_ISPFF_Pos)           /*!< FMC ISPCON: ISPFF Mask */

#define FMC_ISPCON_LDUEN_Pos                    5                                       /*!< FMC ISPCON: LDUEN Position */
#define FMC_ISPCON_LDUEN_Msk                    (1ul << FMC_ISPCON_LDUEN_Pos)           /*!< FMC ISPCON: LDUEN Mask */

#define FMC_ISPCON_CFGUEN_Pos                   4                                       /*!< FMC ISPCON: CFGUEN Position */
#define FMC_ISPCON_CFGUEN_Msk                   (1ul << FMC_ISPCON_CFGUEN_Pos)          /*!< FMC ISPCON: CFGUEN Mask */

#define FMC_ISPCON_APUEN_Pos                    3                                       /*!< FMC ISPCON: APUEN Position */
#define FMC_ISPCON_APUEN_Msk                    (1ul << FMC_ISPCON_APUEN_Pos)           /*!< FMC ISPCON: APUEN Mask */

#define FMC_ISPCON_BS_Pos                       1                                       /*!< FMC ISPCON: BS Position */
#define FMC_ISPCON_BS_Msk                       (1ul << FMC_ISPCON_BS_Pos)              /*!< FMC ISPCON: BS Mask */
                                                                                        
#define FMC_ISPCON_ISPEN_Pos                    0                                       /*!< FMC ISPCON: ISPEN Position */
#define FMC_ISPCON_ISPEN_Msk                    (1ul << FMC_ISPCON_ISPEN_Pos)           /*!< FMC ISPCON: ISPEN Mask */

/* FMC ISPADR Bit Field Definitions */
#define FMC_ISPADR_ISPADR_Pos                   0                                       /*!< FMC ISPADR: ISPADR Position */
#define FMC_ISPADR_ISPADR_Msk                   (0xFFFFFFFFul << FMC_ISPADR_ISPADR_Pos) /*!< FMC ISPADR: ISPADR Mask     */

/* FMC ISPADR Bit Field Definitions */
#define FMC_ISPDAT_ISPDAT_Pos                   0                                       /*!< FMC ISPDAT: ISPDAT Position */
#define FMC_ISPDAT_ISPDAT_Msk                   (0xFFFFFFFFul << FMC_ISPDAT_ISPDAT_Pos) /*!< FMC ISPDAT: ISPDAT Mask     */

/* FMC ISPCMD Bit Field Definitions */
#define FMC_ISPCMD_FOEN_Pos                     5                                       /*!< FMC ISPCMD: FOEN Position */
#define FMC_ISPCMD_FOEN_Msk                     (1ul << FMC_ISPCMD_FOEN_Pos)            /*!< FMC ISPCMD: FOEN Mask */

#define FMC_ISPCMD_FCEN_Pos                     4                                       /*!< FMC ISPCMD: FCEN Position */
#define FMC_ISPCMD_FCEN_Msk                     (1ul << FMC_ISPCMD_FCEN_Pos)            /*!< FMC ISPCMD: FCEN Mask */

#define FMC_ISPCMD_FCTRL_Pos                    0                                       /*!< FMC ISPCMD: FCTRL Position */
#define FMC_ISPCMD_FCTRL_Msk                    (0xFul << FMC_ISPCMD_FCTRL_Pos)         /*!< FMC ISPCMD: FCTRL Mask */

/* FMC ISPTRG Bit Field Definitions */
#define FMC_ISPTRG_ISPGO_Pos                    0                                       /*!< FMC ISPTRG: ISPGO Position */
#define FMC_ISPTRG_ISPGO_Msk                    (1ul << FMC_ISPTRG_ISPGO_Pos)           /*!< FMC ISPTRG: ISPGO Mask */

/* FMC DFBADR Bit Field Definitions */
#define FMC_DFBADR_DFBA_Pos                     0                                       /*!< FMC DFBADR: DFBA Position */
#define FMC_DFBADR_DFBA_Msk                     (0xFFFFFFFFul << FMC_DFBADR_DFBA_Pos)   /*!< FMC DFBADR: DFBA Mask     */

/* FMC FATCON Bit Field Definitions */
#define FMC_FATCON_MFOM_Pos                     6                                       /*!< FMC FATCON: MFOM Position */
#define FMC_FATCON_MFOM_Msk                     (1ul << FMC_FATCON_MFOM_Pos)            /*!< FMC FATCON: MFOM Mask */

#define FMC_FATCON_LFOM_Pos                     4                                       /*!< FMC FATCON: LFOM Position */
#define FMC_FATCON_LFOM_Msk                     (1ul << FMC_FATCON_LFOM_Pos)            /*!< FMC FATCON: LFOM Mask */
/*@}*/ /* end of group NUC123_FMC */


/*------------------------------ PS/2 Controller ------------------------------*/
/** @addtogroup NUC123_PS2 NUC123 PS2
  Memory Mapped Structure for NUC123 Series PS/2 Serial Interface Controller
  @{
 */
typedef struct
{
    /**
     * PS2CON
     * ===================================================================================================
     * Offset: 0x00  PS/2 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field        |Descriptions
     * | :----: | :----:      | :---- |
     * |[0]     |PS2EN        |Enable PS/2 Device
		 * |        |             |Enable PS/2 device controller.
     * |        |             |1 = Enable
     * |        |             |0 = Disable
     * |[1]     |TXINTEN      |Enable Transmit Interrupt
     * |        |             |1 = Enable data transmit complete interrupt.
     * |        |             |0 = Disable data transmit complete interrupt.
     * |[2]     |RXINTEN      |Enable Receive Interrupt
     * |        |             |1 = Enable data receive complete interrupt.
     * |        |             |0 = Disable data receive complete interrupt.
     * |[6:3]   |TXFIFO_DEPTH |Transmit data FIFO Depth
     * |        |             |There is 16 bytes buffer for data trnsmit. S/W can define the FIFO depth from 1 to 16 bytes depends
     * |        |             |on appliction.  
     * |        |             | 0 =  1 byte
     * |        |             | 1 =  2 bytes             
     * |        |             |...
     * |        |             |14 = 15 btyes
     * |        |             |15 = 16 bytes             
     * |[7]     |ACK          |Acknowledge Enable
     * |        |             |1 = if parity error or stop bit is not received correctly, acknowledge bit will not be sent to host
     * |        |             |    at 12th clock.
     * |        |             |0 = Always send acknowledge to host at 12th clock for host to device communication
     * |[8]     |CLRFIFO      |Clear TX FIFO
     * |        |             |Write 1 to this bit to terminate device to host transmission. The TXEMPTY bit in PS2STATUS bit will
     * |        |             |be set to 1 and pointer BYTEINDEX is reset to 0 regardless there is residue data in buffer or not. 
     * |        |             |The buffer content is not been cleared.
     * |        |             |1 = Clear FIFO.
     * |        |             |0 = Not active.
     * |[9]     |OVERRIDE     |Software Override PS/2 CLK/DATA Pin State
     * |        |             |1 = PS2CLK and PS2DATA pins are controlled by S/W.
     * |        |             |0 = PS2CLK and PS2DATA pins are controlled by internal state machine.
     * |[10]    |FPS2CLK      |Force PS2CLK Line
     * |        |             |It forces PS2CLK line high or low regardless of the internal state of the device controller if
     * |        |             |OVERRIDE is set to high.
     * |        |             |1 = Force PS2CLK line high.
     * |        |             |0 = Force PS2CLK line low.
     * |[11]    |FPS2DAT      |Force PS2DATA Line 
     * |        |             |It forces PS2DATA high or low regardless of the internal state of the device controller if OVERRIDE
     * |        |             |is set to high.
     * |        |             |1 = Force PS2DATA high.
     * |        |             |0 = Force PS2DATA low.                                                                         
     */  	
		__IO uint32_t PS2CON;


    /**
     * PS2TXDATAx
     * ===================================================================================================
     * Offset: 0x04+x*4  PS/2 TX DATA Register x
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |PS2TXDATAx|Transmit data
     * |        |          |Write data to this register starts device to host communication if bus is in IDLE state. S/W must 
     * |        |          |enable PS2EN before writing data to TX buffer.
     */ 						
		__IO uint32_t PS2TXDATA[4];

		
    /**
     * PS2RXDATA
     * ===================================================================================================
     * Offset: 0x14  PS/2 Receive Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |GC        |Received Data
     * |        |          |For host to device communication, after acknowledge bit is sent, the received data is copied from
     * |        |          |receive shift register to PS2RXDATA register. CPU must read this register before next byte 
     * |        |          |reception complete, otherwise the data will be overwritten and RXOVF bit in PS2STATUS[6] will be
     * |        |          |set to 1.
     */  		
		__IO uint32_t PS2RXDATA;
		
     /**
     * PS2STATUS
     * ===================================================================================================
     * Offset: 0x18  PS/2 Status Register 
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PS2CLK    |CLK Pin State
     * |        |          |This bit reflects the status of the PS2CLK line after synchronizing.
     * |[1]     |PS2DATA   |DATA Pin State
     * |        |          |This bit reflects the status of the PS2DATA line after synchronizing and sampling.
     * |[2]     |FRAMERR   |FrameError
     * |        |          |For host to device communication, if STOP bit (logic 1) is not received it is a frame error. If
     * |        |          |frame error occurs, DATA line may keep at low state after 12th clock. At this moment, S/W 
     * |        |          |overrides PS2CLK to send clock till PS2DATA release to high state. After that, device sends a 
     * |        |          |"Resend" command to host.
     * |        |          |1 = Frame error occur.
     * |        |          |0 = No Frame error.
     * |        |          |Write 1 to clear this bit.
     * |[3]     |RXPARITY  |Received Parity
     * |        |          |This bit reflects the parity bit for the last received data byte (odd parity).
     * |        |          |Read only bit.
     * |[4]     |RXBUSY    |Receive Busy
     * |        |          |This bit indicates that the PS/2 device is currently receiving data.
     * |        |          |1 = Currently receiving data.
     * |        |          |0 = Idle.
     * |        |          |Read only bit.
     * |[5]     |TXBUSY    |Transmit Busy
     * |        |          |This bit indicates that the PS/2 device is currently sending data.
     * |        |          |1 = Currently sending data.
     * |        |          |0 = Idle.
     * |        |          |Read only bit.
     * |[6]     |RXOVF     |RX Buffer Overwrite
     * |        |          |1 = Data in PS2RXDATA register is overwritten by new received data. 
     * |        |          |0 = No overwrite.
     * |        |          |Write 1 to clear this bit.                                                                      
     * |[7]     |TXEMPTY   |TX FIFO Empty
     * |        |          |When S/W writes any data to PS2TXDATA0~3 the TXEMPTY bit is cleared to 0 immediately if PS2EN is 
     * |        |          |enabled. When transmitted data byte number is equal to FIFODEPTH then TXEMPTY bit is set to 1.
     * |        |          |1 = FIFO is empty.
     * |        |          |0 = There is data to be transmitted.                         
     * |[11:8]  |BYTEIDX   |Byte Index
     * |        |          |It indicates which data byte in transmit data shift register. When all data in FIFO is 
     * |        |          |transmitted and it will be cleared to 0.
     * |        |          |It is a read only bit.
     * |        |          |
     * |        |          |BYTEIDX, DATA Transmit , BYTEIDX, DATA Transmit
     * |        |          |0000   , TXDATA0[ 7: 0], 1000   , TXDATA2[ 7: 0],
     * |        |          |0001   , TXDATA0[15: 8], 1001   , TXDATA2[15: 8],
     * |        |          |0010   , TXDATA0[23:16], 1010   , TXDATA2[23:16],
     * |        |          |0011   , TXDATA0[31:24], 1011   , TXDATA2[31:24],
     * |        |          |0100   , TXDATA1[ 7: 0], 1100   , TXDATA3[ 7: 0],
     * |        |          |0101   , TXDATA1[15: 8], 1101   , TXDATA3[15: 8],
     * |        |          |0110   , TXDATA1[23:16], 1110   , TXDATA3[23:16],                           
     * |        |          |0111   , TXDATA1[31:24], 1111   , TXDATA3[31:24],                   
     */   		
		__IO uint32_t PS2STATUS;
		
     /**
     * PS2INTID
     * ===================================================================================================
     * Offset: 0x1C  PS/2 Interrupt Identification Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |RXINT     |Receive Interrupt
	 * |        |          |This bit is set to 1 when acknowledge bit is sent for Host to device communication. Interrupt      
	 * |        |          |occurs if RXINTEN bit is set to 1.
     * |        |          |1 = Receive interrupt occurs.
     * |        |          |0 = No interrupt.
     * |        |          |Write 1 to clear this bit to 0.     
     * |[1]     |TXINT     |Transmit Interrupt 
     * |        |          |This bit is set to 1 after STOP bit is transmitted. Interrupt occur if TXINTEN bit is set to 1.
     * |        |          |1 = Transmit interrupt occurs.
     * |        |          |0 = No interrupt.
     * |        |          |Write 1 to clear this bit to 0.        
     */   		
		__IO uint32_t PS2INTID;
}PS2_T;


/* PS/2 PS2CON Bit Field Definitions */
#define PS2_PS2CON_PS2EN_Pos                       0										/*!< PS/2 PS2CON: PS2EN Position */
#define PS2_PS2CON_PS2EN_Msk                       (1ul << PS2_PS2CON_PS2EN_Pos)  			/*!< PS/2 PS2CON: PS2EN Mask */

#define PS2_PS2CON_TXINTEN_Pos                     1										/*!< PS/2 PS2CON: TXINTEN Position */
#define PS2_PS2CON_TXINTEN_Msk                     (1ul << PS2_PS2CON_TXINTEN_Pos)		    /*!< PS/2 PS2CON: TXINTEN Mask */ 

#define PS2_PS2CON_RXINTEN_Pos                     2										/*!< PS/2 PS2CON: RXINTEN Position */
#define PS2_PS2CON_RXINTEN_Msk                     (1ul << PS2_PS2CON_RXINTEN_Pos)  	    /*!< PS/2 PS2CON: RXINTEN Mask */

#define PS2_PS2CON_TXFIFO_DEPTH_Pos                3									    /*!< PS/2 PS2CON: TXFIFO_DEPTH Position */
#define PS2_PS2CON_TXFIFO_DEPTH_Msk                (0xFul << PS2_PS2CON_TXFIFO_DEPTH_Pos)	/*!< PS/2 PS2CON: TXFIFO_DEPTH Mask */

#define PS2_PS2CON_ACK_Pos                         7									    /*!< PS/2 PS2CON: ACK Position */
#define PS2_PS2CON_ACK_Msk                         (1ul << PS2_PS2CON_ACK_Pos)				/*!< PS/2 PS2CON: ACK Mask */ 

#define PS2_PS2CON_CLRFIFO_Pos                     8										/*!< PS/2 PS2CON: CLRFIFO Position */
#define PS2_PS2CON_CLRFIFO_Msk                     (1ul << PS2_PS2CON_CLRFIFO_Pos)  		/*!< PS/2 PS2CON: CLRFIFO Mask */

#define PS2_PS2CON_OVERRIDE_Pos                    9										/*!< PS/2 PS2CON: OVERRIDE Position */
#define PS2_PS2CON_OVERRIDE_Msk                    (1ul << PS2_PS2CON_OVERRIDE_Pos)  		/*!< PS/2 PS2CON: OVERRIDE Mask */

#define PS2_PS2CON_FPS2CLK_Pos                     10										/*!< PS/2 PS2CON: FPS2CLK Position */
#define PS2_PS2CON_FPS2CLK_Msk                     (1ul << PS2_PS2CON_FPS2CLK_Pos) 			/*!< PS/2 PS2CON: FPS2CLK Mask */

#define PS2_PS2CON_FPS2DAT_Pos                     11									    /*!< PS/2 PS2CON: FPS2DAT Position */
#define PS2_PS2CON_FPS2DAT_Msk                     (1ul << PS2_PS2CON_FPS2DAT_Pos) 			/*!< PS/2 PS2CON: FPS2DAT Mask */

/* PS/2 PS2RXDATA Bit Field Definitions */
#define PS2_PS2RXDATA_RXDATA_Pos                   0										/*!< PS/2 PS2RXDATA: RXDATA Position */
#define PS2_PS2RXDATA_RXDATA_Msk                   (0xFFul << PS2_PS2RXDATA_RXDATA_Pos)		/*!< PS/2 PS2RXDATA: RXDATA Mask */

/* PS/2 PS2STATUS Bit Field Definitions */
#define PS2_PS2STATUS_PS2CLK_Pos                   0									    /*!< PS/2 PS2STATUS: PS2CLK Position */
#define PS2_PS2STATUS_PS2CLK_Msk                   (1ul << PS2_PS2STATUS_PS2CLK_Pos) 		/*!< PS/2 PS2STATUS: PS2CLK Mask */

#define PS2_PS2STATUS_PS2DATA_Pos                  1										/*!< PS/2 PS2STATUS: PS2DATA Position */
#define PS2_PS2STATUS_PS2DATA_Msk                  (1ul << PS2_PS2STATUS_PS2DATA_Pos) 		/*!< PS/2 PS2STATUS: PS2DATA Mask */

#define PS2_PS2STATUS_FRAMERR_Pos                  2										/*!< PS/2 PS2STATUS: FRAMERR Position */
#define PS2_PS2STATUS_FRAMERR_Msk                  (1ul << PS2_PS2STATUS_FRAMERR_Pos)		/*!< PS/2 PS2STATUS: FRAMERR Mask */ 

#define PS2_PS2STATUS_RXPARITY_Pos                 3										/*!< PS/2 PS2STATUS: RXPARITY Position */
#define PS2_PS2STATUS_RXPARITY_Msk                 (1ul << PS2_PS2STATUS_RXPARITY_Pos) 		/*!< PS/2 PS2STATUS: RXPARITY Mask */

#define PS2_PS2STATUS_RXBUSY_Pos                   4										/*!< PS/2 PS2STATUS: RXBUSY Position */
#define PS2_PS2STATUS_RXBUSY_Msk                   (1ul << PS2_PS2STATUS_RXBUSY_Pos)		/*!< PS/2 PS2STATUS: RXBUSY Mask */

#define PS2_PS2STATUS_TXBUSY_Pos                   5										/*!< PS/2 PS2STATUS: TXBUSY Position */
#define PS2_PS2STATUS_TXBUSY_Msk                   (1ul << PS2_PS2STATUS_TXBUSY_Pos)		/*!< PS/2 PS2STATUS: TXBUSY Mask */

#define PS2_PS2STATUS_RXOVF_Pos                    6										/*!< PS/2 PS2STATUS: RXOVF Position */
#define PS2_PS2STATUS_RXOVF_Msk                    (1ul << PS2_PS2STATUS_RXOVF_Pos)			/*!< PS/2 PS2STATUS: RXOVF Mask */

#define PS2_PS2STATUS_TXEMPTY_Pos                  7										/*!< PS/2 PS2STATUS: TXEMPTY Position */
#define PS2_PS2STATUS_TXEMPTY_Msk                  (1ul << PS2_PS2STATUS_TXEMPTY_Pos)		/*!< PS/2 PS2STATUS: TXEMPTY Mask */

#define PS2_PS2STATUS_BYTEIDX_Pos                  8										/*!< PS/2 PS2STATUS: BYTEIDX Position */
#define PS2_PS2STATUS_BYTEIDX_Msk                  (0xFul << PS2_PS2STATUS_BYTEIDX_Pos)		/*!< PS/2 PS2STATUS: BYTEIDX Mask */

/* PS/2 PS2INTID Bit Field Definitions */
#define PS2_PS2INTID_RXINT_Pos                     0										/*!< PS/2 PS2INTID : RXINT Position */
#define PS2_PS2INTID_RXINT_Msk                     (1ul << PS2_PS2INTID_RXINT_Pos) 			/*!< PS/2 PS2INTID : RXINT Mask */
                     
#define PS2_PS2INTID_TXINT_Pos                     1										/*!< PS/2 PS2INTID : TXINT Position */
#define PS2_PS2INTID_TXINT_Msk                     (1ul << PS2_PS2INTID_TXINT_Pos) 			/*!< PS/2 PS2INTID : TXINT Mask */
/*@}*/ /* end of group NUC123_PS2 */
                                  

/*--------------------------- USB Device Controller --------------------------*/
/** @addtogroup NUC123_USBD NUC123 USBD
  Memory Mapped Structure for NUC123 Series USB Device Controller
  @{
 */

typedef struct
{
        __IO uint32_t BUFSEG;   /*!< Endpoint Buffer Segmentation Register   */
        
        __IO uint32_t MXPLD;    /*!< Endpoint Maximal Payload Register   */
        
        __IO uint32_t CFG;      /*!< Endpoint Configuration Register   */
        
        __IO uint32_t CFGP;     /*!< Endpoint Set Stall and Clear In/Out Ready Control Register */
    
} USBD_EP_T;

typedef struct
{
        __IO uint32_t INTEN;      /*!< Offset: 0x00  USB Interrupt Enable Register   */
        
        __IO uint32_t INTSTS;     /*!< Offset: 0x04  USB Interrupt Event Status Register   */
        
        __IO uint32_t FADDR;      /*!< Offset: 0x08  USB Device Function Address Register   */
        
        __I  uint32_t EPSTS;      /*!< Offset: 0x0C  USB Endpoint Status Register   */
        
        __IO uint32_t ATTR;       /*!< Offset: 0x10  USB Bus Status and Attribution Register   */
        
        __I  uint32_t FLDET;      /*!< Offset: 0x14  USB Floating Detected Register   */
        
        __IO uint32_t STBUFSEG;   /*!< Offset: 0x18  Setup Token Buffer Segmentation Register   */
    
        __I  uint32_t RESERVE0;
    
        USBD_EP_T EP[6];          /*!< Offset: 0x20  Endpoint Related Configuration Registers   */
    
        __I  uint32_t RESERVE1[4];
    
        __IO uint32_t DRVSE0;     /*!< Offset: 0x90  USB Driver SE0 Control Register   */
    
         __I  uint32_t RESERVE2[283];

        USBD_EP_T EP_NEW[8];      /*!< Offset: 0x500  Endpoint Related Configuration Registers   */
        
} USBD_T;

/* USBD INTEN Bit Field Definitions */
#define USBD_INTEN_INNAK_EN_Pos    15                                    /*!< USB INTEN: INNAK_EN Position */
#define USBD_INTEN_INNAK_EN_Msk    (1ul << USBD_INTEN_INNAK_EN_Pos)      /*!< USB INTEN: INNAK_EN Mask */

#define USBD_INTEN_WAKEUP_EN_Pos   8                                     /*!< USB INTEN: WAKEUP_EN Position */
#define USBD_INTEN_WAKEUP_EN_Msk   (1ul << USBD_INTEN_WAKEUP_EN_Pos)     /*!< USB INTEN: WAKEUP_EN Mask */

#define USBD_INTEN_WAKEUP_IE_Pos   3                                     /*!< USB INTEN: WAKEUP_IE Position */
#define USBD_INTEN_WAKEUP_IE_Msk   (1ul << USBD_INTEN_WAKEUP_IE_Pos)     /*!< USB INTEN: WAKEUP_IE Mask */

#define USBD_INTEN_FLDET_IE_Pos    2                                     /*!< USB INTEN: FLDET_IE Position */
#define USBD_INTEN_FLDET_IE_Msk    (1ul << USBD_INTEN_FLDET_IE_Pos)      /*!< USB INTEN: FLDET_IE Mask */

#define USBD_INTEN_USB_IE_Pos      1                                     /*!< USB INTEN: USB_IE Position */
#define USBD_INTEN_USB_IE_Msk      (1ul << USBD_INTEN_USB_IE_Pos)        /*!< USB INTEN: USB_IE Mask */

#define USBD_INTEN_BUS_IE_Pos      0                                     /*!< USB INTEN: BUS_IE Position */
#define USBD_INTEN_BUS_IE_Msk      (1ul << USBD_INTEN_BUS_IE_Pos)        /*!< USB INTEN: BUS_IE Mask */

/* USBD INTSTS Bit Field Definitions */
#define USBD_INTSTS_SETUP_Pos        31                                  /*!< USB INTSTS: SETUP Position */
#define USBD_INTSTS_SETUP_Msk        (1ul << USBD_INTSTS_SETUP_Pos)      /*!< USB INTSTS: SETUP Mask */

#define USBD_INTSTS_EPEVT_Pos        16                                  /*!< USB INTSTS: EPEVT Position */
#define USBD_INTSTS_EPEVT_Msk        (0xFFul << USBD_INTSTS_EPEVT_Pos)   /*!< USB INTSTS: EPEVT Mask */

#define USBD_INTSTS_WAKEUP_STS_Pos   3                                   /*!< USB INTSTS: WAKEUP_STS Position */
#define USBD_INTSTS_WAKEUP_STS_Msk   (1ul << USBD_INTSTS_WAKEUP_STS_Pos) /*!< USB INTSTS: WAKEUP_STS Mask */

#define USBD_INTSTS_FLDET_STS_Pos    2                                   /*!< USB INTSTS: FLDET_STS Position */
#define USBD_INTSTS_FLDET_STS_Msk    (1ul << USBD_INTSTS_FLDET_STS_Pos)  /*!< USB INTSTS: FLDET_STS Mask */

#define USBD_INTSTS_USB_STS_Pos      1                                   /*!< USB INTSTS: USB_STS Position */
#define USBD_INTSTS_USB_STS_Msk      (1ul << USBD_INTSTS_USB_STS_Pos)    /*!< USB INTSTS: USB_STS Mask */

#define USBD_INTSTS_BUS_STS_Pos      0                                   /*!< USB INTSTS: BUS_STS Position */
#define USBD_INTSTS_BUS_STS_Msk      (1ul << USBD_INTSTS_BUS_STS_Pos)    /*!< USB INTSTS: BUS_STS Mask */

/* USBD FADDR Bit Field Definitions */
#define USBD_FADDR_FADDR_Pos     0                                       /*!< USB FADDR: FADDR Position */
#define USBD_FADDR_FADDR_Msk     (0x7Ful << USBD_FADDR_FADDR_Pos)        /*!< USB FADDR: FADDR Mask */

/* USBD EPSTS Bit Field Definitions */
#define USBD_EPSTS_EPSTS7_Pos    29                                      /*!< USB EPSTS: EPSTS7 Position */
#define USBD_EPSTS_EPSTS7_Msk    (7ul << USBD_EPSTS_EPSTS7_Pos)          /*!< USB EPSTS: EPSTS7 Mask */

#define USBD_EPSTS_EPSTS6_Pos    26                                      /*!< USB EPSTS: EPSTS6 Position */
#define USBD_EPSTS_EPSTS6_Msk    (7ul << USBD_EPSTS_EPSTS6_Pos)          /*!< USB EPSTS: EPSTS6 Mask */

#define USBD_EPSTS_EPSTS5_Pos    23                                      /*!< USB EPSTS: EPSTS5 Position */
#define USBD_EPSTS_EPSTS5_Msk    (7ul << USBD_EPSTS_EPSTS5_Pos)          /*!< USB EPSTS: EPSTS5 Mask */

#define USBD_EPSTS_EPSTS4_Pos    20                                      /*!< USB EPSTS: EPSTS4 Position */
#define USBD_EPSTS_EPSTS4_Msk    (7ul << USBD_EPSTS_EPSTS4_Pos)          /*!< USB EPSTS: EPSTS5 Mask */

#define USBD_EPSTS_EPSTS3_Pos    17                                      /*!< USB EPSTS: EPSTS3 Position */
#define USBD_EPSTS_EPSTS3_Msk    (7ul << USBD_EPSTS_EPSTS3_Pos)          /*!< USB EPSTS: EPSTS3 Mask */

#define USBD_EPSTS_EPSTS2_Pos    14                                      /*!< USB EPSTS: EPSTS2 Position */
#define USBD_EPSTS_EPSTS2_Msk    (7ul << USBD_EPSTS_EPSTS2_Pos)          /*!< USB EPSTS: EPSTS2 Mask */

#define USBD_EPSTS_EPSTS1_Pos    11                                      /*!< USB EPSTS: EPSTS1 Position */
#define USBD_EPSTS_EPSTS1_Msk    (7ul << USBD_EPSTS_EPSTS1_Pos)          /*!< USB EPSTS: EPSTS1 Mask */

#define USBD_EPSTS_EPSTS0_Pos    8                                       /*!< USB EPSTS: EPSTS0 Position */
#define USBD_EPSTS_EPSTS0_Msk    (7ul << USBD_EPSTS_EPSTS0_Pos)          /*!< USB EPSTS: EPSTS0 Mask */

#define USBD_EPSTS_OVERRUN_Pos   7                                       /*!< USB EPSTS: OVERRUN Position */
#define USBD_EPSTS_OVERRUN_Msk   (1ul << USBD_EPSTS_OVERRUN_Pos)         /*!< USB EPSTS: OVERRUN Mask */

/* USBD ATTR Bit Field Definitions */
#define USBD_ATTR_BYTEM_Pos      10                                      /*!< USB ATTR: BYTEM Position */
#define USBD_ATTR_BYTEM_Msk      (1ul << USBD_ATTR_BYTEM_Pos)            /*!< USB ATTR: BYTEM Mask */

#define USBD_ATTR_PWRDN_Pos      9                                       /*!< USB ATTR: PWRDN Position */
#define USBD_ATTR_PWRDN_Msk      (1ul << USBD_ATTR_PWRDN_Pos)            /*!< USB ATTR: PWRDN Mask */

#define USBD_ATTR_DPPU_EN_Pos    8                                       /*!< USB ATTR: DPPU_EN Position */
#define USBD_ATTR_DPPU_EN_Msk    (1ul << USBD_ATTR_DPPU_EN_Pos)          /*!< USB ATTR: DPPU_EN Mask */

#define USBD_ATTR_USB_EN_Pos     7                                       /*!< USB ATTR: USB_EN Position */
#define USBD_ATTR_USB_EN_Msk     (1ul << USBD_ATTR_USB_EN_Pos)           /*!< USB ATTR: USB_EN Mask */

#define USBD_ATTR_RWAKEUP_Pos    5                                       /*!< USB ATTR: RWAKEUP Position */
#define USBD_ATTR_RWAKEUP_Msk    (1ul << USBD_ATTR_RWAKEUP_Pos)          /*!< USB ATTR: RWAKEUP Mask */

#define USBD_ATTR_PHY_EN_Pos     4                                       /*!< USB ATTR: PHY_EN Position */
#define USBD_ATTR_PHY_EN_Msk     (1ul << USBD_ATTR_PHY_EN_Pos)           /*!< USB ATTR: PHY_EN Mask */

#define USBD_ATTR_TIMEOUT_Pos    3                                       /*!< USB ATTR: TIMEOUT Position */
#define USBD_ATTR_TIMEOUT_Msk    (1ul << USBD_ATTR_TIMEOUT_Pos)          /*!< USB ATTR: TIMEOUT Mask */

#define USBD_ATTR_RESUME_Pos     2                                       /*!< USB ATTR: RESUME Position */
#define USBD_ATTR_RESUME_Msk     (1ul << USBD_ATTR_RESUME_Pos)           /*!< USB ATTR: RESUME Mask */

#define USBD_ATTR_SUSPEND_Pos    1                                       /*!< USB ATTR: SUSPEND Position */
#define USBD_ATTR_SUSPEND_Msk    (1ul << USBD_ATTR_SUSPEND_Pos)          /*!< USB ATTR: SUSPEND Mask */

#define USBD_ATTR_USBRST_Pos     0                                       /*!< USB ATTR: USBRST Position */
#define USBD_ATTR_USBRST_Msk     (1ul << USBD_ATTR_USBRST_Pos)           /*!< USB ATTR: USBRST Mask */

/* USBD FLDET Bit Field Definitions */
#define USBD_FLDET_FLDET_Pos     0                                       /*!< USB FLDET: FLDET Position */
#define USBD_FLDET_FLDET_Msk     (1ul << USBD_FLDET_FLDET_Pos)           /*!< USB FLDET: FLDET Mask */

/* USBD STBUFSEG Bit Field Definitions */
#define USBD_STBUFSEG_STBUFSEG_Pos   3                                        /*!< USB STBUFSEG: STBUFSEG Position */
#define USBD_STBUFSEG_STBUFSEG_Msk   (0x3Ful << USBD_STBUFSEG_STBUFSEG_Pos)   /*!< USB STBUFSEG: STBUFSEG Mask */

/* USBD BUFSEG Bit Field Definitions */
#define USBD_BUFSEG_BUFSEG_Pos   3                                       /*!< USB BUFSEG: BUFSEG Position */
#define USBD_BUFSEG_BUFSEG_Msk   (0x3Ful << USBD_BUFSEG_BUFSEG_Pos)      /*!< USB BUFSEG: BUFSEG Mask */

/* USBD MXPLD Bit Field Definitions */
#define USBD_MXPLD_MXPLD_Pos    0                                        /*!< USB MXPLD: MXPLD Position */
#define USBD_MXPLD_MXPLD_Msk    (0x1FFul << USBD_MXPLD_MXPLD_Pos)        /*!< USB MXPLD: MXPLD Mask */

/* USBD CFG Bit Field Definitions */
#define USBD_CFG_CSTALL_Pos     9                                        /*!< USB CFG: CSTALL Position */
#define USBD_CFG_CSTALL_Msk     (1ul << USBD_CFG_CSTALL_Pos)             /*!< USB CFG: CSTALL Mask */

#define USBD_CFG_DSQ_SYNC_Pos   7                                        /*!< USB CFG: DSQ_SYNC Position */
#define USBD_CFG_DSQ_SYNC_Msk   (1ul << USBD_CFG_DSQ_SYNC_Pos)           /*!< USB CFG: DSQ_SYNC Mask */

#define USBD_CFG_STATE_Pos      5                                        /*!< USB CFG: STATE Position */
#define USBD_CFG_STATE_Msk      (3ul << USBD_CFG_STATE_Pos)              /*!< USB CFG: STATE Mask */

#define USBD_CFG_ISOCH_Pos      4                                        /*!< USB CFG: ISOCH Position */
#define USBD_CFG_ISOCH_Msk      (1ul << USBD_CFG_ISOCH_Pos)              /*!< USB CFG: ISOCH Mask */

#define USBD_CFG_EP_NUM_Pos     0                                        /*!< USB CFG: EP_NUM Position */
#define USBD_CFG_EP_NUM_Msk     (0xFul << USBD_CFG_EP_NUM_Pos)           /*!< USB CFG: EP_NUM Mask */

/* USBD CFGP Bit Field Definitions */
#define USBD_CFGP_SSTALL_Pos    1                                        /*!< USB CFGP: SSTALL Position */
#define USBD_CFGP_SSTALL_Msk    (1ul << USBD_CFGP_SSTALL_Pos)            /*!< USB CFGP: SSTALL Mask */

#define USBD_CFGP_CLRRDY_Pos    0                                        /*!< USB CFGP: CLRRDY Position */
#define USBD_CFGP_CLRRDY_Msk    (1ul << USBD_CFGP_CLRRDY_Pos)            /*!< USB CFGP: CLRRDY Mask */

/* USBD DRVSE0 Bit Field Definitions */
#define USBD_DRVSE0_DRVSE0_Pos   0                                       /*!< USB DRVSE0: DRVSE0 Position */
#define USBD_DRVSE0_DRVSE0_Msk   (1ul << USBD_DRVSE0_DRVSE0_Pos)         /*!< USB DRVSE0: DRVSE0 Mask */

/* USBD PDMA Bit Field Definitions */
#define USBD_PDMA_PDMA_EN_Pos    1                                       /*!< USB PDMA: PDMA_EN Position */
#define USBD_PDMA_PDMA_EN_Msk    (1ul << USBD_PDMA_PDMA_EN_Pos)          /*!< USB PDMA: PDMA_EN Mask */

#define USBD_PDMA_PDMA_RW_Pos    0                                       /*!< USB PDMA: PDMA_RW Position */
#define USBD_PDMA_PDMA_RW_Msk    (1ul << USBD_PDMA_PDMA_RW_Pos)          /*!< USB PDMA: PDMA_RW Mask */

/*@}*/ /* end of group NUC123_USBD */


/*------------------------------ DMA Controller -----------------------------*/
/** @addtogroup NUC123_DMA NUC123 DMA
  Memory Mapped Structure for NUC123 Series DMA Controller 
  @{
 */
typedef struct
{
    __IO uint32_t CSR;				/*!< Offset: 0x00  PDMA Control Register   */
    __IO uint32_t SAR;				/*!< Offset: 0x04  PDMA Source Address Register   */
    __IO uint32_t DAR;				/*!< Offset: 0x08  PDMA Destination Address Register   */
    __IO uint32_t BCR;				/*!< Offset: 0x0C  PDMA Transfer Byte Count Register   */
    __I  uint32_t POINT;			/*!< Offset: 0x10  PDMA Internal buffer pointer   */
    __I  uint32_t CSAR;				/*!< Offset: 0x14  PDMA Current Source Address Register   */
    __I  uint32_t CDAR;				/*!< Offset: 0x18  PDMA Current Destination Address Register   */
    __I  uint32_t CBCR;				/*!< Offset: 0x1C  PDMA Current Transfer Byte Count Register   */
    __IO uint32_t IER;				/*!< Offset: 0x20  PDMA Interrupt Enable Register   */
    __IO uint32_t ISR;				/*!< Offset: 0x24  PDMA Interrupt Status Register   */
    __I  uint32_t RESERVE[22];
    __I  uint32_t SBUF;				/*!< Offset: 0x80  PDMA Shared Buffer FIFO   */
} PDMA_T;

typedef struct
{
    __IO uint32_t GCRCSR;			/*!< Offset: 0x00  DMA Global Control Register   */
    __IO uint32_t PDSSR0;			/*!< Offset: 0x04  DMA Service Selection Control Register 0   */
    __IO uint32_t PDSSR1;			/*!< Offset: 0x08  DMA Service Selection Control Register 0   */
    __IO uint32_t GCRISR;			/*!< Offset: 0x0C  DMA Global Interrupt Register   */
    __IO uint32_t PDSSR2;			/*!< Offset: 0x10  DMA Service Selection Control Register 0   */
} PDMA_GCR_T;

/* PDMA CSR Bit Field Definitions */
#define PDMA_CSR_TRIG_EN_Pos                        23                              /*!< PDMA CSR: TRIG_EN Position */
#define PDMA_CSR_TRIG_EN_Msk                        (1ul << PDMA_CSR_TRIG_EN_Pos)   /*!< PDMA CSR: TRIG_EN Mask */

#define PDMA_CSR_APB_TWS_Pos                        19                              /*!< PDMA CSR: APB_TWS Position */
#define PDMA_CSR_APB_TWS_Msk                        (3ul << PDMA_CSR_APB_TWS_Pos)   /*!< PDMA CSR: APB_TWS Mask */

#define PDMA_CSR_DAD_SEL_Pos                        6                               /*!< PDMA CSR: DAD_SEL Position */
#define PDMA_CSR_DAD_SEL_Msk                        (3ul << PDMA_CSR_DAD_SEL_Pos)   /*!< PDMA CSR: DAD_SEL Mask */

#define PDMA_CSR_SAD_SEL_Pos                        4                               /*!< PDMA CSR: SAD_SEL Position */
#define PDMA_CSR_SAD_SEL_Msk                        (3ul << PDMA_CSR_SAD_SEL_Pos)   /*!< PDMA CSR: SAD_SEL Mask */

#define PDMA_CSR_MODE_SEL_Pos                       2                               /*!< PDMA CSR: MODE_SEL Position */
#define PDMA_CSR_MODE_SEL_Msk                       (3ul << PDMA_CSR_MODE_SEL_Pos)  /*!< PDMA CSR: MODE_SEL Mask */

#define PDMA_CSR_SW_RST_Pos                         1                               /*!< PDMA CSR: SW_RST Position */
#define PDMA_CSR_SW_RST_Msk                         (1ul << PDMA_CSR_SW_RST_Pos)    /*!< PDMA CSR: SW_RST Mask */

#define PDMA_CSR_PDMACEN_Pos                        0                               /*!< PDMA CSR: PDMACEN Position */
#define PDMA_CSR_PDMACEN_Msk                        (1ul << PDMA_CSR_PDMACEN_Pos)   /*!< PDMA CSR: PDMACEN Mask */

/* PDMA BCR Bit Field Definitions */
#define PDMA_BCR_BCR_Pos                            0                               /*!< PDMA BCR: BCR Position */
#define PDMA_BCR_BCR_Msk                            (0xFFFFul << PDMA_BCR_BCR_Pos)  /*!< PDMA BCR: BCR Mask */

/* PDMA POINT Bit Field Definitions */
#define PDMA_POINT_POINT_Pos                        0                               /*!< PDMA POINT: POINT Position */
#define PDMA_POINT_POINT_Msk                        (0xFul << PDMA_POINT_POINT_Pos) /*!< PDMA POINT: POINT Mask */

/* PDMA CBCR Bit Field Definitions */
#define PDMA_CBCR_CBCR_Pos                          0                                   /*!< PDMA CBCR: CBCR Position */
#define PDMA_CBCR_CBCR_Msk                          (0xFFFFul << PDMA_CBCR_CBCR_Pos)    /*!< PDMA CBCR: CBCR Mask */


/* PDMA IER Bit Field Definitions */
#define PDMA_IER_BLKD_IE_Pos                        1                               /*!< PDMA IER: BLKD_IE Position */
#define PDMA_IER_BLKD_IE_Msk                        (1ul << PDMA_IER_BLKD_IE_Pos)   /*!< PDMA IER: BLKD_IE Mask */

#define PDMA_IER_TABORT_IE_Pos                      0                               /*!< PDMA IER: TABORT_IE Position */
#define PDMA_IER_TABORT_IE_Msk                      (1ul << PDMA_IER_TABORT_IE_Pos) /*!< PDMA IER: TABORT_IE Mask */

/* PDMA ISR Bit Field Definitions */
#define PDMA_ISR_BLKD_IF_Pos                        1                               /*!< PDMA ISR: BLKD_IF Position */
#define PDMA_ISR_BLKD_IF_Msk                        (1ul << PDMA_ISR_BLKD_IF_Pos)   /*!< PDMA ISR: BLKD_IF Mask */

#define PDMA_ISR_TABORT_IF_Pos                      0                               /*!< PDMA ISR: TABORT_IF Position */
#define PDMA_ISR_TABORT_IF_Msk                      (1ul << PDMA_ISR_TABORT_IF_Pos) /*!< PDMA ISR: TABORT_IF Mask */

/* PDMA GCRCSR Bit Field Definitions */
#define PDMA_GCRCSR_CRC_CLK_EN_Pos                  24                                  /*!< PDMA GCRCSR: CRC_CLK_EN Position */
#define PDMA_GCRCSR_CRC_CLK_EN_Msk                  (1ul << PDMA_GCRCSR_CRC_CLK_EN_Pos) /*!< PDMA GCRCSR: CRC_CLK_EN Mask */

#define PDMA_GCRCSR_CLK5_EN_Pos                     13                                  /*!< PDMA GCRCSR: CLK5_EN Position */
#define PDMA_GCRCSR_CLK5_EN_Msk                     (1ul << PDMA_GCRCSR_CLK5_EN_Pos)    /*!< PDMA GCRCSR: CLK5_EN Mask */

#define PDMA_GCRCSR_CLK4_EN_Pos                     12                                  /*!< PDMA GCRCSR: CLK4_EN Position */
#define PDMA_GCRCSR_CLK4_EN_Msk                     (1ul << PDMA_GCRCSR_CLK4_EN_Pos)    /*!< PDMA GCRCSR: CLK4_EN Mask */

#define PDMA_GCRCSR_CLK3_EN_Pos                     11                                  /*!< PDMA GCRCSR: CLK3_EN Position */
#define PDMA_GCRCSR_CLK3_EN_Msk                     (1ul << PDMA_GCRCSR_CLK3_EN_Pos)    /*!< PDMA GCRCSR: CLK3_EN Mask */

#define PDMA_GCRCSR_CLK2_EN_Pos                     10                                  /*!< PDMA GCRCSR: CLK2_EN Position */
#define PDMA_GCRCSR_CLK2_EN_Msk                     (1ul << PDMA_GCRCSR_CLK2_EN_Pos)    /*!< PDMA GCRCSR: CLK2_EN Mask */

#define PDMA_GCRCSR_CLK1_EN_Pos                     9                                   /*!< PDMA GCRCSR: CLK1_EN Position */
#define PDMA_GCRCSR_CLK1_EN_Msk                     (1ul << PDMA_GCRCSR_CLK1_EN_Pos)    /*!< PDMA GCRCSR: CLK1_EN Mask */

#define PDMA_GCRCSR_CLK0_EN_Pos                     8                                   /*!< PDMA GCRCSR: CLK0_EN Position */
#define PDMA_GCRCSR_CLK0_EN_Msk                     (1ul << PDMA_GCRCSR_CLK0_EN_Pos)    /*!< PDMA GCRCSR: CLK0_EN Mask */

/* PDMA PDSSR0 Bit Field Definitions */
#define PDMA_PDSSR0_SPI2_TXSEL_Pos                  20                                      /*!< PDMA PDSSR0: SPI2_TXSEL Position */
#define PDMA_PDSSR0_SPI2_TXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI2_TXSEL_Pos)   /*!< PDMA PDSSR0: SPI2_TXSEL Mask */

#define PDMA_PDSSR0_SPI2_RXSEL_Pos                  16                                      /*!< PDMA PDSSR0: SPI2_RXSEL Position */
#define PDMA_PDSSR0_SPI2_RXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI2_RXSEL_Pos)   /*!< PDMA PDSSR0: SPI2_RXSEL Mask */

#define PDMA_PDSSR0_SPI1_TXSEL_Pos                  12                                      /*!< PDMA PDSSR0: SPI1_TXSEL Position */
#define PDMA_PDSSR0_SPI1_TXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI1_TXSEL_Pos)   /*!< PDMA PDSSR0: SPI1_TXSEL Mask */

#define PDMA_PDSSR0_SPI1_RXSEL_Pos                  8                                       /*!< PDMA PDSSR0: SPI1_RXSEL Position */
#define PDMA_PDSSR0_SPI1_RXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI1_RXSEL_Pos)   /*!< PDMA PDSSR0: SPI1_RXSEL Mask */

#define PDMA_PDSSR0_SPI0_TXSEL_Pos                  4                                       /*!< PDMA PDSSR0: SPI0_TXSEL Position */
#define PDMA_PDSSR0_SPI0_TXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI0_TXSEL_Pos)   /*!< PDMA PDSSR0: SPI0_TXSEL Mask */

#define PDMA_PDSSR0_SPI0_RXSEL_Pos                  0                                       /*!< PDMA PDSSR0: SPI0_RXSEL Position */
#define PDMA_PDSSR0_SPI0_RXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI0_RXSEL_Pos)   /*!< PDMA PDSSR0: SPI0_RXSEL Mask */

/* PDMA PDSSR1 Bit Field Definitions */
#define PDMA_PDSSR1_ADC_RXSEL_Pos                   24                                      /*!< PDMA PDSSR1: ADC_RXSEL Position */
#define PDMA_PDSSR1_ADC_RXSEL_Msk                   (0xFul << PDMA_PDSSR1_ADC_RXSEL_Pos)    /*!< PDMA PDSSR1: ADC_RXSEL Mask */

#define PDMA_PDSSR1_USB_TXSEL_Pos                   20                                      /*!< PDMA PDSSR1: USB_TXSEL Position */
#define PDMA_PDSSR1_USB_TXSEL_Msk                   (0xFul << PDMA_PDSSR1_USB_TXSEL_Pos)    /*!< PDMA PDSSR1: USB_TXSEL Mask */

#define PDMA_PDSSR1_USB_RXSEL_Pos                   16                                      /*!< PDMA PDSSR1: USB_RXSEL Position */
#define PDMA_PDSSR1_USB_RXSEL_Msk                   (0xFul << PDMA_PDSSR1_USB_RXSEL_Pos)    /*!< PDMA PDSSR1: USB_RXSEL Mask */

#define PDMA_PDSSR1_UART1_TXSEL_Pos                 12                                      /*!< PDMA PDSSR1: UART1_TXSEL Position */
#define PDMA_PDSSR1_UART1_TXSEL_Msk                 (0xFul << PDMA_PDSSR1_UART1_TXSEL_Pos)  /*!< PDMA PDSSR1: UART1_TXSEL Mask */

#define PDMA_PDSSR1_UART1_RXSEL_Pos                 8                                       /*!< PDMA PDSSR1: UART1_RXSEL Position */
#define PDMA_PDSSR1_UART1_RXSEL_Msk                 (0xFul << PDMA_PDSSR1_UART1_RXSEL_Pos)  /*!< PDMA PDSSR1: UART1_RXSEL Mask */

#define PDMA_PDSSR1_UART0_TXSEL_Pos                 4                                       /*!< PDMA PDSSR1: UART0_TXSEL Position */
#define PDMA_PDSSR1_UART0_TXSEL_Msk                 (0xFul << PDMA_PDSSR1_UART0_TXSEL_Pos)  /*!< PDMA PDSSR1: UART0_TXSEL Mask */

#define PDMA_PDSSR1_UART0_RXSEL_Pos                 0                                       /*!< PDMA PDSSR1: UART0_RXSEL Position */
#define PDMA_PDSSR1_UART0_RXSEL_Msk                 (0xFul << PDMA_PDSSR1_UART0_RXSEL_Pos)  /*!< PDMA PDSSR1: UART0_RXSEL Mask */

/* PDMA GCRISR Bit Field Definitions */
#define PDMA_GCRISR_INTR_Pos                        31                              /*!< PDMA GCRISR: INTR Position */
#define PDMA_GCRISR_INTR_Msk                        (1ul << PDMA_GCRISR_INTR_Pos)   /*!< PDMA GCRISR: INTR Mask */

#define PDMA_GCRISR_INTRCRC_Pos                     16                               /*!< PDMA GCRISR: INTRCRC Position */
#define PDMA_GCRISR_INTRCRC_Msk                     (1ul << PDMA_GCRISR_INTRCRC_Pos) /*!< PDMA GCRISR: INTRCRC Mask */

#define PDMA_GCRISR_INTR5_Pos                       5                               /*!< PDMA GCRISR: INTR5 Position */
#define PDMA_GCRISR_INTR5_Msk                       (1ul << PDMA_GCRISR_INTR5_Pos)  /*!< PDMA GCRISR: INTR5 Mask */ 

#define PDMA_GCRISR_INTR4_Pos                       4                               /*!< PDMA GCRISR: INTR4 Position */
#define PDMA_GCRISR_INTR4_Msk                       (1ul << PDMA_GCRISR_INTR4_Pos)  /*!< PDMA GCRISR: INTR4 Mask */

#define PDMA_GCRISR_INTR3_Pos                       3                               /*!< PDMA GCRISR: INTR3 Position */
#define PDMA_GCRISR_INTR3_Msk                       (1ul << PDMA_GCRISR_INTR3_Pos)  /*!< PDMA GCRISR: INTR3 Mask */

#define PDMA_GCRISR_INTR2_Pos                       2                               /*!< PDMA GCRISR: INTR2 Position */
#define PDMA_GCRISR_INTR2_Msk                       (1ul << PDMA_GCRISR_INTR2_Pos)  /*!< PDMA GCRISR: INTR2 Mask */

#define PDMA_GCRISR_INTR1_Pos                       1                               /*!< PDMA GCRISR: INTR1 Position */
#define PDMA_GCRISR_INTR1_Msk                       (1ul << PDMA_GCRISR_INTR1_Pos)  /*!< PDMA GCRISR: INTR1 Mask */

#define PDMA_GCRISR_INTR0_Pos                       0                               /*!< PDMA GCRISR: INTR0 Position */
#define PDMA_GCRISR_INTR0_Msk                       (1ul << PDMA_GCRISR_INTR0_Pos)  /*!< PDMA GCRISR: INTR0 Mask */

/* PDMA PDSSR2 Bit Field Definitions */
#define PDMA_PDSSR2_PWM3_RXSEL_Pos                  20                                      /*!< PDMA PDSSR2: PWM3_RXSEL Position */
#define PDMA_PDSSR2_PWM3_RXSEL_Msk                  (0xFul << PDMA_PDSSR2_PWM3_RXSEL_Pos)   /*!< PDMA PDSSR2: PWM3_RXSEL Mask */

#define PDMA_PDSSR2_PWM2_RXSEL_Pos                  16                                      /*!< PDMA PDSSR2: PWM2_RXSEL Position */
#define PDMA_PDSSR2_PWM2_RXSEL_Msk                  (0xFul << PDMA_PDSSR2_PWM2_RXSEL_Pos)   /*!< PDMA PDSSR2: PWM2_RXSEL Mask */

#define PDMA_PDSSR2_PWM1_RXSEL_Pos                  12                                      /*!< PDMA PDSSR2: PWM1_RXSEL Position */
#define PDMA_PDSSR2_PWM1_RXSEL_Msk                  (0xFul << PDMA_PDSSR2_PWM1_RXSEL_Pos)   /*!< PDMA PDSSR2: PWM1_RXSEL Mask */

#define PDMA_PDSSR2_PWM0_RXSEL_Pos                  8                                       /*!< PDMA PDSSR2: PWM0_RXSEL Position */
#define PDMA_PDSSR2_PWM0_RXSEL_Msk                  (0xFul << PDMA_PDSSR2_PWM0_RXSEL_Pos)   /*!< PDMA PDSSR2: PWM0_RXSEL Mask */

#define PDMA_PDSSR2_I2S_TXSEL_Pos                   4                                       /*!< PDMA PDSSR2: I2S_TXSEL Position */
#define PDMA_PDSSR2_I2S_TXSEL_Msk                   (0xFul << PDMA_PDSSR2_I2S_TXSEL_Pos)    /*!< PDMA PDSSR2: I2S_TXSEL Mask */

#define PDMA_PDSSR2_I2S_RXSEL_Pos                   0                                       /*!< PDMA PDSSR2: I2S_RXSEL Position */
#define PDMA_PDSSR2_I2S_RXSEL_Msk                   (0xFul << PDMA_PDSSR2_I2S_RXSEL_Pos)    /*!< PDMA PDSSR2: I2S_RXSEL Mask */
/*@}*/ /* end of group NUC123_DMA */


/*----------------------------- Cyclic Redundancy Check (CRC) Controller -----------------------------*/
/** @addtogroup NUC123_CRC NUC123 CRC
  Memory Mapped Structure for NUC123 Series Cyclic Redundancy Check
  @{
 */
typedef struct
{
    /**
     * CRC_CTL
     * ===================================================================================================
     * Offset: 0x00  CRC Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  CTL;

    /**
     * CRC_DMASAR 
     * ===================================================================================================
     * Offset: 0x04  CRC DMA Transfer Source Address Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DMASAR;

    __I  uint32_t  RESERVED0;

    /**
     * CRC_DMABCR 
     * ===================================================================================================
     * Offset: 0x0C  CRC DMA Transfer Byte Count Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DMABCR ;

    __I  uint32_t  RESERVED1;

    /**
     * CRC_DMACSAR
     * ===================================================================================================
     * Offset: 0x14  CRC DMA Current Source Address Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  DMACSAR;

    __I  uint32_t  RESERVED2;

    /**
     * CRC_DMACBCR
     * ===================================================================================================
     * Offset: 0x1C  CRC DMA Current Byte Count Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  DMACBCR;

    /**
     * CRC_DMAIER 
     * ===================================================================================================
     * Offset: 0x20  CRC DMA Interrupt Enable Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DMAIER ;

    /**
     * CRC_DMAISR 
     * ===================================================================================================
     * Offset: 0x24  CRC DMA Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  DMAISR;

    __I  uint32_t  RESERVED3[22];

    /**
     * CRC_WDATA 
     * ===================================================================================================
     * Offset: 0x80  CRC Write Data Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  WDATA;

    /**
     * CRC_SEED 
     * ===================================================================================================
     * Offset: 0x84  CRC Seed Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t  SEED;

    /**
     * CRC_CHECKSUM
     * ===================================================================================================
     * Offset: 0x88  CRC Checksum Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t  CHECKSUM;
} CRC_T;

/* CRC CTL Bit Field Definitions */
#define CRC_CTL_CRC_MODE_Pos            30                                      /*!< CRC CRC_CTL : CRC_MODE Position */
#define CRC_CTL_CRC_MODE_Msk            (0x3ul << CRC_CTL_CRC_MODE_Pos)         /*!< CRC CRC_CTL : CRC_MODE Mask */

#define CRC_CTL_CPU_WDLEN_Pos           28                                      /*!< CRC CRC_CTL : CPU_WDLEN Position */
#define CRC_CTL_CPU_WDLEN_Msk           (0x3ul << CRC_CTL_CPU_WDLEN_Pos)        /*!< CRC CRC_CTL : CPU_WDLEN Mask */

#define CRC_CTL_CHECKSUM_COM_Pos        27                                      /*!< CRC CRC_CTL : CHECKSUM_COM Position */
#define CRC_CTL_CHECKSUM_COM_Msk        (1ul << CRC_CTL_CHECKSUM_COM_Pos)       /*!< CRC CRC_CTL : CHECKSUM_COM Mask */

#define CRC_CTL_WDATA_COM_Pos           26                                      /*!< CRC CRC_CTL : WDATA_COM Position */
#define CRC_CTL_WDATA_COM_Msk           (1ul << CRC_CTL_WDATA_COM_Pos)          /*!< CRC CRC_CTL : WDATA_COM Mask */

#define CRC_CTL_CHECKSUM_RVS_Pos        25                                      /*!< CRC CRC_CTL : CHECKSUM_RVS Position */
#define CRC_CTL_CHECKSUM_RVS_Msk        (1ul << CRC_CTL_CHECKSUM_RVS_Pos)       /*!< CRC CRC_CTL : CHECKSUM_RVS Mask */

#define CRC_CTL_WDATA_RVS_Pos           24                                      /*!< CRC CRC_CTL : WDATA_RVS Position */
#define CRC_CTL_WDATA_RVS_Msk           (1ul << CRC_CTL_WDATA_RVS_Pos)          /*!< CRC CRC_CTL : WDATA_RVS Mask */

#define CRC_CTL_TRIG_EN_Pos             23                                      /*!< CRC CRC_CTL : TRIG_EN Position */
#define CRC_CTL_TRIG_EN_Msk             (1ul << CRC_CTL_TRIG_EN_Pos)            /*!< CRC CRC_CTL : TRIG_EN Mask */
    
#define CRC_CTL_CRC_RST_Pos             1                                       /*!< CRC CRC_CTL : CRC_RST Position */
#define CRC_CTL_CRC_RST_Msk             (1ul << CRC_CTL_CRC_RST_Pos)            /*!< CRC CRC_CTL : CRC_RST Mask */

#define CRC_CTL_CRCCEN_Pos              0                                       /*!< CRC CRC_CTL : CRCCEN Position */
#define CRC_CTL_CRCCEN_Msk              (1ul << CRC_CTL_CRCCEN_Pos)             /*!< CRC CRC_CTL : CRCCEN Mask */

/* CRC DMASAR Bit Field Definitions */
#define CRC_DMASAR_CRC_DMASAR_Pos       0                                               /*!< CRC CRC_DMASAR : CRC_DMASAR Position */
#define CRC_DMASAR_CRC_DMASAR_Msk       (0xFFFFFFFFul << CRC_DMASAR_CRC_DMASAR_Pos)     /*!< CRC CRC_DMASAR : CRC_DMASAR Mask */

/* CRC DMABCR Bit Field Definitions */
#define CRC_DMABCR_CRC_DMABCR_Pos       0                                               /*!< CRC CRC_DMABCR : CRC_DMABCR Position */
#define CRC_DMABCR_CRC_DMABCR_Msk       (0xFFFFul << CRC_DMABCR_CRC_DMABCR_Pos)         /*!< CRC CRC_DMABCR : CRC_DMABCR Mask */

/* CRC DMACSAR Bit Field Definitions */
#define CRC_DMACSAR_CRC_DMACSAR_Pos     0                                               /*!< CRC CRC_DMACSAR : CRC_DMACSAR Position */
#define CRC_DMACSAR_CRC_DMACSAR_Msk     (0xFFFFFFFFul << CRC_DMACSAR_CRC_DMACSAR_Pos)   /*!< CRC CRC_DMACSAR : CRC_DMACSAR Mask */

/* CRC DMACBCR Bit Field Definitions */
#define CRC_DMACBCR_CRC_DMACBCR_Pos     0                                               /*!< CRC CRC_DMACBCR : DMACBCR Position */
#define CRC_DMACBCR_CRC_DMACBCR_Msk     (0xFFFFul << CRC_DMACBCR_CRC_DMACBCR_Pos)       /*!< CRC CRC_DMACBCR : DMACBCR Mask */

/* CRC DMAIER Bit Field Definitions */
#define CRC_DMAIER_CRC_BLKD_IE_Pos      1                                               /*!< CRC CRC_DMAIER : CRC_BLKD_IE Position */
#define CRC_DMAIER_CRC_BLKD_IE_Msk      (1ul << CRC_DMAIER_CRC_BLKD_IE_Pos)             /*!< CRC CRC_DMAIER : CRC_BLKD_IE Mask */

#define CRC_DMAIER_CRC_TABORT_IE_Pos    0                                               /*!< CRC CRC_DMAIER : CRC_TABORT_IE Position */
#define CRC_DMAIER_CRC_TABORT_IE_Msk    (1ul << CRC_DMAIER_CRC_TABORT_IE_Pos)           /*!< CRC CRC_DMAIER : CRC_TABORT_IE Mask */

/* CRC DMAISR Bit Field Definitions */
#define CRC_DMAISR_CRC_BLKD_IF_Pos      1                                               /*!< CRC CRC_DMAISR : CRC_BLKD_IF Position */
#define CRC_DMAISR_CRC_BLKD_IF_Msk      (1ul << CRC_DMAISR_CRC_BLKD_IF_Pos)             /*!< CRC CRC_DMAISR : CRC_BLKD_IF Mask */

#define CRC_DMAISR_CRC_TABORT_IF_Pos    0                                               /*!< CRC CRC_DMAISR : CRC_TABORT_IF Position */
#define CRC_DMAISR_CRC_TABORT_IF_Msk    (1ul << CRC_DMAISR_CRC_TABORT_IF_Pos)           /*!< CRC CRC_DMAISR : CRC_TABORT_IF Mask */

/* CRC WDATA Bit Field Definitions */
#define CRC_WDATA_CRC_WDATA_Pos         0                                               /*!< CRC CRC_WDATA : CRC_WDATA Position */
#define CRC_WDATA_CRC_WDATA_Msk         (0xFFFFFFFFul << CRC_WDATA_CRC_WDATA_Pos)       /*!< CRC CRC_WDATA : CRC_WDATA Mask */

/* CRC SEED Bit Field Definitions */
#define CRC_SEED_CRC_SEED_Pos           0                                               /*!< CRC CRC_SEED : CRC_SEED Position */
#define CRC_SEED_CRC_SEED_Msk           (0xFFFFFFFFul << CRC_SEED_CRC_SEED_Pos)         /*!< CRC CRC_SEED : CRC_SEED Mask */

/* CRC CHECKSUM Bit Field Definitions */
#define CRC_CHECKSUM_CRC_CHECKSUM_Pos   0                                               /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Position */
#define CRC_CHECKSUM_CRC_CHECKSUM_Msk   (0xFFFFFFFFul << CRC_CHECKSUM_CRC_CHECKSUM_Pos) /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Mask */
/*@}*/ /* end of group NUC123_CRC */

/*----------------------------- PWM Controller -------------------------------*/

/** @addtogroup NUC123_PWM NUC123 PWM
  Memory Mapped Structure for NUC123 Series PWM Generator and Capture Timer
  @{
 */
typedef struct
{
    /**
     * PPR
     * ===================================================================================================
     * Offset: 0x00  PWM Pre-Scale Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |CP01      |Clock pre-scalar 0(PWM counter 0 & 1 for group A and PWM counter 4 & 5 for group B)
     * |        |          |Clock input is divided by (CP01 + 1) before it is fed to the corresponding PWM counter
     * |        |          |If CP01=0, then the pre-scalar 0 output clock will be stopped. So corresponding PWM 
     * |        |          |counter will be stopped also.
     * |[15:8]  |CP23      |Clock pre-scalar 2(PWM counter 2 & 3 for group A and PWM counter 6 & 7 for group B)
     * |        |          |Clock input is divided by (CP23 + 1) before it is fed to the corresponding PWM counter
     * |        |          |If CP23=0, then the pre-scalar 2 output clock will be stopped. So corresponding PWM 
     * |        |          |counter will be stopped also.
     * |[23:16] |DZI01     |Dead zone interval register for pair of channel 0 and channel 1(PWM0 and PWM1 pair 
     * |        |          |for PWM group A, PWM4 and PWM5 pair for PWM group B)
     * |        |          |These 8 bits determine dead zone length.
     * |        |          |The unit time of dead zone length = [(prescale+1)*(clock source divider)]/ PWMxy_CLK
     * |        |          |where xy, could be 01 or 45, depends on selected PWM channel.
     * |[31:24] |DZI23     |Dead zone interval register for pair of channel 2 and channel 3(PWM2 and PWM3 pair 
     * |        |          |for PWM group A, PWM6 and PWM7 pair for PWM group B)
     * |        |          |These 8 bits determine dead zone length.
     * |        |          |The unit time of dead zone length = [(prescale+1)*(clock source divider)]/ PWMxy_CLK
     * |        |          |where xy, could be 23 or 67, depends on selected PWM channel.
     */    
    __IO uint32_t PPR;

    /**
     * CSR
     * ===================================================================================================
     * Offset: 0x04  PWM Clock Source Divider Select Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |CSR0      |Timer 0 Clock Source Selection(PWM timer 0 for group A and PWM timer 4 for group B)
     * |        |          |Select clock input for timer.
     * |        |          |(Table is the same as CSR3)
     * |[6:4]   |CSR1      |Timer 1 Clock Source Selection(PWM timer 1 for group A and PWM timer 5 for group B)
     * |        |          |Select clock input for timer.
     * |        |          |(Table is the same as CSR3)
     * |[10:8]  |CSR2      |Timer 2 Clock Source Selection(PWM timer 2 for group A and PWM timer 6 for group B)
     * |        |          |Select clock input for timer.
     * |        |          |(Table is the same as CSR3)
     * |[14:12] |CSR3      |Timer 3 Clock Source Selection (PWM timer 3 for group A and PWM timer 7 for group B)
     * |        |          |Select clock input for timer.
     * |        |          |CSRx[2:0] = Input clock divider
     * |        |          |100 = 1
     * |        |          |011 = 16
     * |        |          |010 = 8
     * |        |          |001 = 4
     * |        |          |000 = 2
     */    
    __IO uint32_t CSR;

    /**
     * PCR
     * ===================================================================================================
     * Offset: 0x08  PWM Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CH0EN     |PWM-Timer 0 Enable/Disable Start Run (PWM timer 0 for group A and PWM timer 4 for 
     * |        |          |group B)
     * |        |          |1 = Enable corresponding PWM-Timer Start Run
     * |        |          |0 = Stop corresponding PWM-Timer Running
     * |[2]     |CH0INV    |PWM-Timer 0 Output Inverter ON/OFF(PWM timer 0 for group A and PWM timer 4 for 
     * |        |          |group B)
     * |        |          |1 = Inverter ON
     * |        |          |0 = Inverter OFF
     * |[3]     |CH0MOD    |PWM-Timer 0 Auto-reload/One-Shot Mode(PWM timer 0 for group A and PWM timer 4 
     * |        |          |for group B)
     * |        |          |1 = Auto-reload Mode
     * |        |          |0 = One-Shot Mode
     * |        |          |Note: If there is a rising transition at this bit, it will cause CNR0 and CMR0 be clear.
     * |[4]     |DZEN01    |Dead-Zone 0 Generator Enable/Disable(PWM0 and PWM1 pair for PWM group A, 
     * |        |          |PWM4 and PWM5 pair for PWM group B)
     * |        |          |1 = Enable
     * |        |          |0 = Disable
     * |        |          |Note: When Dead-Zone Generator is enabled, the pair of PWM0 and PWM1 becomes a 
     * |        |          |complementary pair for PWM group A and the pair of PWM4 and PWM5 becomes a 
     * |        |          |complementary pair for PWM group B.
     * |[5]     |DZEN23    |Dead-Zone 2 Generator Enable/Disable(PWM2 and PWM3 pair for PWM group A, 
     * |        |          |PWM6 and PWM7 pair for PWM group B)
     * |        |          |1 = Enable
     * |        |          |0 = Disable
     * |        |          |Note: When Dead-Zone Generator is enabled, the pair of PWM2 and PWM3 becomes a 
     * |        |          |complementary pair for PWM group A and the pair of PWM6 and PWM7 becomes a 
     * |        |          |complementary pair for PWM group B.
     * |[8]     |CH1EN     |PWM-Timer 1 Enable/Disable Start Run (PWM timer 1 for group A and PWM timer 5 for 
     * |        |          |group B)
     * |        |          |1 = Enable corresponding PWM-Timer Start Run
     * |        |          |0 = Stop corresponding PWM-Timer Running
     * |[10]    |CH1INV    |PWM-Timer 1 Output Inverter ON/OFF(PWM timer 1 for group A and PWM timer 5 for 
     * |        |          |group B)
     * |        |          |1 = Inverter ON
     * |        |          |0 = Inverter OFF
     * |[11]    |CH1MOD    |PWM-Timer 1 Auto-reload/One-Shot Mode(PWM timer 1 for group A and PWM timer 5 
     * |        |          |for group B)
     * |        |          |1 = Auto-reload Mode
     * |        |          |0 = One-Shot Mode
     * |        |          |Note: If there is a rising transition at this bit, it will cause CNR1 and CMR1 be clear.
     * |[16]    |CH2EN     |PWM-Timer 2 Enable/Disable Start Run (PWM timer 2 for group A and PWM timer 6 for 
     * |        |          |group B)
     * |        |          |1 = Enable corresponding PWM-Timer Start Run
     * |        |          |0 = Stop corresponding PWM-Timer Running
     * |[18]    |CH2INV    |PWM-Timer 2 Output Inverter ON/OFF(PWM timer 2 for group A and PWM timer 6 for 
     * |        |          |group B)
     * |        |          |1 = Inverter ON
     * |        |          |0 = Inverter OFF
     * |[19]    |CH2MOD    |PWM-Timer 2 Auto-reload/One-Shot Mode(PWM timer 2 for group A and PWM timer 6 
     * |        |          |for group B)
     * |        |          |1 = Auto-reload Mode
     * |        |          |0 = One-Shot Mode
     * |        |          |Note: If there is a rising transition at this bit, it will cause CNR2 and CMR2 be clear.
     * |[24]    |CH3EN     |PWM-Timer 3 Enable/Disable Start Run (PWM timer 3 for group A and PWM timer 7 for 
     * |        |          |group B)
     * |        |          |1 = Enable corresponding PWM-Timer Start Run
     * |        |          |0 = Stop corresponding PWM-Timer Running
     * |[26]    |CH3INV    |PWM-Timer 3 Output Inverter ON/OFF(PWM timer 3 for group A and PWM timer 7 for 
     * |        |          |group B)
     * |        |          |1 = Inverter ON
     * |        |          |0 = Inverter OFF
     * |[27]    |CH3MOD    |PWM-Timer 3 Auto-reload/One-Shot Mode(PWM timer 3 for group A and PWM timer 7 
     * |        |          |for group B)
     * |        |          |1 = Auto-reload Mode
     * |        |          |0 = One-Shot Mode
     * |        |          |Note: If there is a rising transition at this bit, it will cause CNR3 and CMR3 be clear.
     */    
    __IO uint32_t PCR;

    /**
     * CNR0
     * ===================================================================================================
     * Offset: 0x0C  PWM Counter 0/Timer 0 Loaded Value
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNR       | 
     * |        |          |PWM Counter/Timer Loaded Value 
     * |        |          |CNR determines the PWM period. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CNR0;

    /**
     * CMR0
     * ===================================================================================================
     * Offset: 0x10  PWM Comparator 0 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMR       | 
     * |        |          |PWM Comparator Register 
     * |        |          |CNR determines the PWM duty. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CMR0;

    /**
     * PDR0
     * ===================================================================================================
     * Offset: 0x14  PWM Data 0 Register(current counter 0 value)
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PDR       | 
     * |        |          |PWM Data Register 
     * |        |          |User can monitor PDR to know the current value in 16-bit down counter.
     */    
    __I  uint32_t PDR0;

    /**
     * CNR1
     * ===================================================================================================
     * Offset: 0x18  PWM Counter 1/Timer 1 Loaded Value
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNR       | 
     * |        |          |PWM Counter/Timer Loaded Value 
     * |        |          |CNR determines the PWM period. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CNR1;

    /**
     * CMR1
     * ===================================================================================================
     * Offset: 0x1C  PWM Comparator 1 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMR       | 
     * |        |          |PWM Comparator Register 
     * |        |          |CNR determines the PWM duty. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CMR1;

    /**
     * PDR1
     * ===================================================================================================
     * Offset: 0x20  PWM Data 1 Register(current counter 1 value)
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PDR       | 
     * |        |          |PWM Data Register 
     * |        |          |User can monitor PDR to know the current value in 16-bit down counter.
     */    
    __I  uint32_t PDR1;

    /**
     * CNR2
     * ===================================================================================================
     * Offset: 0x24  PWM Counter 2/Timer 2 Loaded Value
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNR       | 
     * |        |          |PWM Counter/Timer Loaded Value 
     * |        |          |CNR determines the PWM period. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CNR2;

    /**
     * CMR2
     * ===================================================================================================
     * Offset: 0x28  PWM Comparator 2 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMR       | 
     * |        |          |PWM Comparator Register 
     * |        |          |CNR determines the PWM duty. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CMR2;

    /**
     * PDR2
     * ===================================================================================================
     * Offset: 0x2C  PWM Data 2 Register(current counter 2 value)
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PDR       | 
     * |        |          |PWM Data Register 
     * |        |          |User can monitor PDR to know the current value in 16-bit down counter.
     */    
    __I  uint32_t PDR2;

    /**
     * CNR3
     * ===================================================================================================
     * Offset: 0x30  PWM Counter 3/Timer 3 Loaded Value
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNR       | 
     * |        |          |PWM Counter/Timer Loaded Value 
     * |        |          |CNR determines the PWM period. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CNR3;

    /**
     * CMR3
     * ===================================================================================================
     * Offset: 0x34  PWM Comparator 3 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMR       | 
     * |        |          |PWM Comparator Register 
     * |        |          |CNR determines the PWM duty. 
     * |        |          | 
     * |        |          |PWM frequency = PWMxy_CLK/(prescale+1)/(clock divider)/(CNR+1); where xy, could be 01, 23, 
     * |        |          |45 or 67, depends on selected PWM channel. 
     * |        |          | 
     * |        |          |Duty ratio = (CMR+1)/(CNR+1). 
     * |        |          | 
     * |        |          |CMR >= CNR: PWM output is always high. 
     * |        |          | 
     * |        |          |CMR < CNR: PWM low width = (CNR-CMR) unit; PWM high width = (CMR+1) unit. 
     * |        |          | 
     * |        |          |CMR = 0: PWM low width = (CNR) unit; PWM high width = 1 unit 
     * |        |          | 
     * |        |          |(Unit = one PWM clock cycle) 
     * |        |          |Note: Any write to CNR will take effect in next PWM cycle.
     */    
    __IO uint32_t CMR3;

    /**
     * PDR3
     * ===================================================================================================
     * Offset: 0x38  PWM Data 3 Register(current counter 3 value)
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PDR       | 
     * |        |          |PWM Data Register 
     * |        |          |User can monitor PDR to know the current value in 16-bit down counter.
     */    
    __I  uint32_t PDR3;

    /**
     * PBCR
     * ===================================================================================================
     * 
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t PBCR;

    /**
     * PIER
     * ===================================================================================================
     * Offset: 0x40  PWM Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PWMIE0    |PWM channel 0 Interrupt Enable
     * |        |          |1 = Enable
     * |        |          |0 = Disable 
     * |[1]     |PWMIE1    |PWM channel 1 Interrupt Enable
     * |        |          |1 = Enable
     * |        |          |0 = Disable 
     * |[2]     |PWMIE2    |PWM channel 2 Interrupt Enable
     * |        |          |1 = Enable
     * |        |          |0 = Disable 
     * |[3]     |PWMIE3    |PWM channel 3 Interrupt Enable
     * |        |          |1 = Enable
     * |        |          |0 = Disable 
     */    
    __IO uint32_t PIER;

    /**
     * PIIR
     * ===================================================================================================
     * Offset: 0x44  PWM Interrupt Indication Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PWMIF0    |PWM channel 0 Interrupt Status
     * |        |          |Flag is set by hardware when PWM0 down counter reaches zero, software can clear this 
     * |        |          |bit by writing a one to it.
     * |[1]     |PWMIF1    |PWM channel 1 Interrupt Status
     * |        |          |Flag is set by hardware when PWM1 down counter reaches zero, software can clear this 
     * |        |          |bit by writing a one to it.
     * |[2]     |PWMIF2    |PWM channel 2 Interrupt Status
     * |        |          |Flag is set by hardware when PWM2 down counter reaches zero, software can clear this 
     * |        |          |bit by writing a one to it.
     * |[3]     |PWMIF3    |PWM channel 3 Interrupt Status
     * |        |          |Flag is set by hardware when PWM3 down counter reaches zero, software can clear this 
     * |        |          |bit by writing a one to it.
     */    
    __IO uint32_t PIIR;

    /**
     * RESERVE1
     * ===================================================================================================
     * 
     * ---------------------------------------------------------------------------------------------------
     */    
    __I uint32_t    RESERVE1[2];

    /**
     * CCR0
     * ===================================================================================================
     * Offset: 0x50  Capture 0/1 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |INV0      | 
     * |        |          |PWM Group Channel 0 Inverter ON/OFF 
     * |        |          | 
     * |        |          |1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer 
     * |        |          |0 = Inverter OFF
     * |[1]     |CRL_IE0   |PWM Group Channel 0 Rising Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable rising latch interrupt
     * |        |          |0 = Disable rising latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 0 has rising transition, Capture 
     * |        |          |issues an Interrupt.
     * |[2]     |CFL_IE0   |PWM Group Channel 0 Falling Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable falling latch interrupt
     * |        |          |0 = Disable falling latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 0 has falling transition, Capture 
     * |        |          |issues an Interrupt.
     * |[3]     |CAPCH0EN  |Capture Channel 0 transition Enable/Disable
     * |        |          |1 = Enable capture function on PWM group channel 0.
     * |        |          |0 = Disable capture function on PWM group channel 0
     * |        |          |When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising 
     * |        |          |latch) and CFLR (Falling latch).
     * |        |          |When Disable, Capture does not update CRLR and CFLR, and disable PWM group 
     * |        |          |channel 0 Interrupt.
     * |[4]     |CAPIF0    | 
     * |        |          |Capture0 Interrupt Indication Flag 
     * |        |          | 
     * |        |          |If PWM group channel 0 rising latch interrupt is enabled (CRL_IE0=1), a rising transition occurs 
     * |        |          |at PWM group channel 0 will result in CAPIF0 to high; Similarly, a falling transition will cause 
     * |        |          |CAPIF0 to be set high if PWM group channel 0 falling latch interrupt is enabled (CFL_IE0=1). 
     * |        |          |This flag is clear by software with a write 1 to itself.
     * |[6]     |CRLRI0    | 
     * |        |          |CRLR0 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 0 has a rising transition, CRLR0 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[7]     |CFLRI0    | 
     * |        |          |CFLR0 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 0 has a falling transition, CFLR0 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[16]    |INV1      | 
     * |        |          |PWM Group Channel 1 Inverter ON/OFF 
     * |        |          | 
     * |        |          |1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer 
     * |        |          |0 = Inverter OFF
     * |[17]    |CRL_IE1   |PWM Group Channel 1 Rising Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable rising latch interrupt
     * |        |          |0 = Disable rising latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 1 has rising transition, Capture 
     * |        |          |issues an Interrupt.
     * |[18]    |CFL_IE1   |PWM Group Channel 1 Falling Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable falling latch interrupt
     * |        |          |0 = Disable falling latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 1 has falling transition, Capture 
     * |        |          |issues an Interrupt.
     * |[19]    |CAPCH1EN  |Capture Channel 1 transition Enable/Disable
     * |        |          |1 = Enable capture function on PWM group channel 1.
     * |        |          |0 = Disable capture function on PWM group channel 1
     * |        |          |When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising 
     * |        |          |latch) and CFLR (Falling latch).
     * |        |          |When Disable, Capture does not update CRLR and CFLR, and disable PWM group 
     * |        |          |channel 1 Interrupt.
     * |[20]    |CAPIF1    | 
     * |        |          |Capture1 Interrupt Indication Flag 
     * |        |          | 
     * |        |          |If PWM group channel 1 rising latch interrupt is enabled (CRL_IE1=1), a rising transition occurs 
     * |        |          |at PWM group channel 1 will result in CAPIF1 to high; Similarly, a falling transition will cause 
     * |        |          |CAPIF1 to be set high if PWM group channel 1 falling latch interrupt is enabled (CFL_IE1=1). 
     * |        |          |This flag is clear by software with a write 1 to itself.
     * |[22]    |CRLRI1    | 
     * |        |          |CRLR1 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 1 has a rising transition, CRLR1 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[23]    |CFLRI1    | 
     * |        |          |CFLR1 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 1 has a falling transition, CFLR1 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     */    
    __IO uint32_t CCR0;

    /**
     * CCR2
     * ===================================================================================================
     * Offset: 0x54  Capture 2/3 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |INV2      | 
     * |        |          |PWM Group Channel 2 Inverter ON/OFF 
     * |        |          | 
     * |        |          |1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer 
     * |        |          |0 = Inverter OFF
     * |[1]     |CRL_IE2   |PWM Group Channel 2 Rising Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable rising latch interrupt
     * |        |          |0 = Disable rising latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 2 has rising transition, Capture 
     * |        |          |issues an Interrupt.
     * |[2]     |CFL_IE2   |PWM Group Channel 2 Falling Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable falling latch interrupt
     * |        |          |0 = Disable falling latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 2 has falling transition, Capture 
     * |        |          |issues an Interrupt.
     * |[3]     |CAPCH2EN  |Capture Channel 2 transition Enable/Disable
     * |        |          |1 = Enable capture function on PWM group channel 2.
     * |        |          |0 = Disable capture function on PWM group channel 2
     * |        |          |When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising 
     * |        |          |latch) and CFLR (Falling latch).
     * |        |          |When Disable, Capture does not update CRLR and CFLR, and disable PWM group 
     * |        |          |channel 2 Interrupt.
     * |[4]     |CAPIF2    | 
     * |        |          |Capture2 Interrupt Indication Flag 
     * |        |          | 
     * |        |          |If PWM group channel 2 rising latch interrupt is enabled (CRL_IE2=1), a rising transition occurs 
     * |        |          |at PWM group channel 2 will result in CAPIF2 to high; Similarly, a falling transition will cause 
     * |        |          |CAPIF2 to be set high if PWM group channel 2 falling latch interrupt is enabled (CFL_IE2=1). 
     * |        |          |This flag is clear by software with a write 1 to itself.
     * |[6]     |CRLRI2    | 
     * |        |          |CRLR2 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 2 has a rising transition, CRLR2 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[7]     |CFLRI2    | 
     * |        |          |CFLR2 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 2 has a falling transition, CFLR2 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[16]    |INV3      | 
     * |        |          |PWM Group Channel 3 Inverter ON/OFF 
     * |        |          | 
     * |        |          |1 = Inverter ON. Reverse the input signal from GPIO before fed to Capture timer 
     * |        |          |0 = Inverter OFF
     * |[17]    |CRL_IE3   |PWM Group Channel 3 Rising Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable rising latch interrupt
     * |        |          |0 = Disable rising latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 3 has rising transition, Capture 
     * |        |          |issues an Interrupt.
     * |[18]    |CFL_IE3   |PWM Group Channel 3 Falling Latch Interrupt Enable ON/OFF
     * |        |          |1 = Enable falling latch interrupt
     * |        |          |0 = Disable falling latch interrupt
     * |        |          |When Enable, if Capture detects PWM group channel 3 has falling transition, Capture 
     * |        |          |issues an Interrupt.
     * |[19]    |CAPCH3EN  |Capture Channel 3 transition Enable/Disable
     * |        |          |1 = Enable capture function on PWM group channel 3.
     * |        |          |0 = Disable capture function on PWM group channel 3
     * |        |          |When Enable, Capture latched the PWM-counter value and saved to CRLR (Rising 
     * |        |          |latch) and CFLR (Falling latch).
     * |        |          |When Disable, Capture does not update CRLR and CFLR, and disable PWM group 
     * |        |          |channel 3 Interrupt.
     * |[20]    |CAPIF3    | 
     * |        |          |Capture3 Interrupt Indication Flag 
     * |        |          | 
     * |        |          |If PWM group channel 3 rising latch interrupt is enabled (CRL_IE3=1), a rising transition occurs 
     * |        |          |at PWM group channel 3 will result in CAPIF3 to high; Similarly, a falling transition will cause 
     * |        |          |CAPIF3 to be set high if PWM group channel 3 falling latch interrupt is enabled (CFL_IE3=1). 
     * |        |          |This flag is clear by software with a write 1 to itself.
     * |[22]    |CRLRI3    | 
     * |        |          |CRLR3 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 3 has a rising transition, CRLR3 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     * |[23]    |CFLRI3    | 
     * |        |          |CFLR3 Latched Indicator Bit 
     * |        |          | 
     * |        |          |When PWM group input channel 3 has a falling transition, CFLR3 was latched with the value of 
     * |        |          |PWM down-counter and this bit is set by hardware. 
     * |        |          | 
     * |        |          |Clear this bit by writing a one to it.
     */    
    __IO uint32_t CCR2;

    /**
     * CRLR0
     * ===================================================================================================
     * Offset: 0x58  Capture 0 Rising Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CRLR      |Capture Rising Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has rising transition.
     */    
    __IO uint32_t CRLR0;

    /**
     * CFLR0
     * ===================================================================================================
     * Offset: 0x5C  Capture 0 Falling Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CFLR      |Capture Falling Latch Register
     * |        |          |Latch the PWM counter when Channel 01/2/3 has Falling transition.
     */    
    __IO uint32_t CFLR0;

    /**
     * CRLR1
     * ===================================================================================================
     * Offset: 0x60  Capture 1 Rising Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CRLR      |Capture Rising Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has rising transition.
     */    
    __IO uint32_t CRLR1;

    /**
     * CFLR1
     * ===================================================================================================
     * Offset: 0x64  Capture 1 Falling Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CFLR      |Capture Falling Latch Register
     * |        |          |Latch the PWM counter when Channel 01/2/3 has Falling transition.
     */    
    __IO uint32_t CFLR1;

    /**
     * CRLR2
     * ===================================================================================================
     * Offset: 0x68  Capture 2 Rising Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CRLR      |Capture Rising Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has rising transition.
     */    
    __IO uint32_t CRLR2;

    /**
     * CFLR2
     * ===================================================================================================
     * Offset: 0x6C  Capture 2 Falling Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CFLR      |Capture Falling Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has Falling transition.
     */    
    __IO uint32_t CFLR2;

    /**
     * CRLR3
     * ===================================================================================================
     * Offset: 0x70  Capture 3 Rising Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CRLR      |Capture Rising Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has rising transition.
     */    
    __IO uint32_t CRLR3;

    /**
     * CFLR3
     * ===================================================================================================
     * Offset: 0x74  Capture 3 Falling Latch Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CFLR      |Capture Falling Latch Register
     * |        |          |Latch the PWM counter when Channel 0/1/2/3 has Falling transition.
     */    
    __IO uint32_t CFLR3;

    /**
     * CAPENR
     * ===================================================================================================
     * Offset: 0x78  Capture Input Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CAPENR    |Capture Input Enable Register
     * |        |          |There are four capture inputs from pad. Bit0~Bit3 are used to control each inputs ON or 
     * |        |          |OFF. 
     * |        |          |0 = OFF (PWMx multi-function pin input does not affect input capture function.)
     * |        |          |1 = (PWMx multi-function pin input will affect its input capture function.)
     * |        |          |CAPENR
     * |        |          |Bit 3210 for PWM group A
     * |        |          |Bit xxx1 -> Capture channel 0 is from P2 [0] 
     * |        |          |Bit xx1x -> Capture channel 1 is from P2 [1] 
     * |        |          |Bit x1xx -> Capture channel 2 is from P2 [2]
     * |        |          |Bit 1xxx -> Capture channel 3 is from P2 [3]
     * |        |          |Bit 3210 for PWM group B
     * |        |          |Bit xxx1 -> Capture channel 0 is from P2 [4] 
     * |        |          |Bit xx1x -> Capture channel 1 is from P2 [5] 
     * |        |          |Bit x1xx -> Capture channel 2 is from P2 [6]
     * |        |          |Bit 1xxx -> Capture channel 3 is from P2 [7]
     */    
    __IO uint32_t CAPENR;

    /**
     * POE
     * ===================================================================================================
     * Offset: 0x7C  PWM Output Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PWM0      |PWM Channel 0 Output Enable Register
     * |        |          |1 = Enable PWM channel 0 output to pin.
     * |        |          |0 = Disable PWM channel 0 output to pin.
     * |        |          |Note: The corresponding GPIO pin also must be switched to PWM function.
     * |[1]     |PWM1      |PWM Channel 1 Output Enable Register
     * |        |          |1 = Enable PWM channel 1 output to pin.
     * |        |          |0 = Disable PWM channel 1 output to pin.
     * |        |          |Note: The corresponding GPIO pin also must be switched to PWM function.
     * |[2]     |PWM2      |PWM Channel 2 Output Enable Register
     * |        |          |1 = Enable PWM channel 2 output to pin.
     * |        |          |0 = Disable PWM channel 2 output to pin.
     * |        |          |Note: The corresponding GPIO pin also must be switched to PWM function.
     * |[3]     |PWM3      |PWM Channel 3 Output Enable Register
     * |        |          |1 = Enable PWM channel 3 output to pin.
     * |        |          |0 = Disable PWM channel 3 output to pin.
     * |        |          |Note: The corresponding GPIO pin also must be switched to PWM function.
     */    
    __IO uint32_t POE;

    /**
     * TCON
     * ===================================================================================================
     * Offset: 0x80  PWM Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TCON;

    /**
     * TSTATUS
     * ===================================================================================================
     * Offset: 0x84  PWM Trigger Status Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TSTATUS;

    /**
     * SYNCBUSY0
     * ===================================================================================================
     * Offset: 0x88  PWM0 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY0;

    /**
     * SYNCBUSY1
     * ===================================================================================================
     * Offset: 0x8C  PWM1 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY1;
    
    /**
     * SYNCBUSY2
     * ===================================================================================================
     * Offset: 0x90  PWM2 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY2;
    
    /**
     * SYNCBUSY3
     * ===================================================================================================
     * Offset: 0x94  PWM3 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY3;

    /**
     * RESERVE2
     * ===================================================================================================
     * 
     * ---------------------------------------------------------------------------------------------------
     */    
    __I uint32_t    RESERVE2[10];
    
    /**
     * CAPPDMACTL
     * ===================================================================================================
     * Offset: 0xC0  PWM Group A  PDMA control register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  CAPPDMACTL;
    
    /**
     * CAP0PDMA
     * ===================================================================================================
     * Offset: 0xC4  PWM Group A channel0 data register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  CAP0PDMA;
    
    /**
     * CAP1PDMA
     * ===================================================================================================
     * Offset: 0xC8  PWM Group A channel1 data register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  CAP1PDMA;
    
    /**
     * CAP2PDMA
     * ===================================================================================================
     * Offset: 0xCC  PWM Group A channel2 data register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  CAP2PDMA;
    
    /**
     * CAP3PDMA
     * ===================================================================================================
     * Offset: 0xD0  PWM Group A channel3 data register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  CAP3PDMA;
                    
} PWM_T;

/* PWM PPR Bit Field Definitions */
#define PWM_PPR_DZI23_Pos                       24                                  /*!< PWM PPR: DZI23 Position */
#define PWM_PPR_DZI23_Msk                       (0xFFul << PWM_PPR_DZI23_Pos)       /*!< PWM PPR: DZI23 Mask */

#define PWM_PPR_DZI01_Pos                       16                                  /*!< PWM PPR: DZI01 Position */
#define PWM_PPR_DZI01_Msk                       (0xFFul << PWM_PPR_DZI01_Pos)       /*!< PWM PPR: DZI01 Mask */

#define PWM_PPR_CP23_Pos                        8                                   /*!< PWM PPR: CP23 Position */
#define PWM_PPR_CP23_Msk                        (0xFFul << PWM_PPR_CP23_Pos)        /*!< PWM PPR: CP23 Mask */

#define PWM_PPR_CP01_Pos                        0                                   /*!< PWM PPR: CP01 Position */
#define PWM_PPR_CP01_Msk                        (0xFFul << PWM_PPR_CP01_Pos)        /*!< PWM PPR: CP01 Mask */

/* PWM CSR Bit Field Definitions */
#define PWM_CSR_CSR3_Pos                        12                                  /*!< PWM CSR: CSR3 Position */
#define PWM_CSR_CSR3_Msk                        (7ul << PWM_CSR_CSR3_Pos)           /*!< PWM CSR: CSR3 Mask */

#define PWM_CSR_CSR2_Pos                        8                                   /*!< PWM CSR: CSR2 Position */
#define PWM_CSR_CSR2_Msk                        (7ul << PWM_CSR_CSR2_Pos)           /*!< PWM CSR: CSR2 Mask */

#define PWM_CSR_CSR1_Pos                        4                                   /*!< PWM CSR: CSR1 Position */
#define PWM_CSR_CSR1_Msk                        (7ul << PWM_CSR_CSR1_Pos)           /*!< PWM CSR: CSR1 Mask */

#define PWM_CSR_CSR0_Pos                        0                                   /*!< PWM CSR: CSR0 Position */
#define PWM_CSR_CSR0_Msk                        (7ul << PWM_CSR_CSR0_Pos)           /*!< PWM CSR: CSR0 Mask */

/* PWM PCR Bit Field Definitions */
#define PWM_PCR_PWM23TYPE_Pos                   31                                  /*!< PWM PCR: PWM23TYPE Position */
#define PWM_PCR_PWM23TYPE_Msk                   (1ul << PWM_PCR_PWM23TYPE_Pos)      /*!< PWM PCR: PWM23TYPE Mask */

#define PWM_PCR_PWM01TYPE_Pos                   30                                  /*!< PWM PCR: PWM01TYPE Position */
#define PWM_PCR_PWM01TYPE_Msk                   (1ul << PWM_PCR_PWM01TYPE_Pos)      /*!< PWM PCR: PWM01TYPE Mask */

#define PWM_PCR_CH3MOD_Pos                      27                                  /*!< PWM PCR: CH3MOD Position */
#define PWM_PCR_CH3MOD_Msk                      (1ul << PWM_PCR_CH3MOD_Pos)         /*!< PWM PCR: CH3MOD Mask */

#define PWM_PCR_CH3INV_Pos                      26                                  /*!< PWM PCR: CH3INV Position */
#define PWM_PCR_CH3INV_Msk                      (1ul << PWM_PCR_CH3INV_Pos)         /*!< PWM PCR: CH3INV Mask */

#define PWM_PCR_CH3PINV_Pos                     25                                  /*!< PWM PCR: CH3PINV Position */
#define PWM_PCR_CH3PINV_Msk                     (1ul << PWM_PCR_CH3PINV_Pos)        /*!< PWM PCR: CH3PINV Mask */

#define PWM_PCR_CH3EN_Pos                       24                                  /*!< PWM PCR: CH3EN Position */
#define PWM_PCR_CH3EN_Msk                       (1ul << PWM_PCR_CH3EN_Pos)          /*!< PWM PCR: CH3EN Mask */

#define PWM_PCR_CH2MOD_Pos                      19                                  /*!< PWM PCR: CH2MOD Position */
#define PWM_PCR_CH2MOD_Msk                      (1ul << PWM_PCR_CH2MOD_Pos)         /*!< PWM PCR: CH2MOD Mask */

#define PWM_PCR_CH2INV_Pos                      18                                  /*!< PWM PCR: CH2INV Position */
#define PWM_PCR_CH2INV_Msk                      (1ul << PWM_PCR_CH2INV_Pos)         /*!< PWM PCR: CH2INV Mask */

#define PWM_PCR_CH2PINV_Pos                     17                                  /*!< PWM PCR: CH2PINV Position */
#define PWM_PCR_CH2PINV_Msk                     (1ul << PWM_PCR_CH2PINV_Pos)        /*!< PWM PCR: CH2PINV Mask */

#define PWM_PCR_CH2EN_Pos                       16                                  /*!< PWM PCR: CH2EN Position */
#define PWM_PCR_CH2EN_Msk                       (1ul << PWM_PCR_CH2EN_Pos)          /*!< PWM PCR: CH2EN Mask */

#define PWM_PCR_CH1MOD_Pos                      11                                  /*!< PWM PCR: CH1MOD Position */
#define PWM_PCR_CH1MOD_Msk                      (1ul << PWM_PCR_CH1MOD_Pos)         /*!< PWM PCR: CH1MOD Mask */

#define PWM_PCR_CH1INV_Pos                      10                                  /*!< PWM PCR: CH1INV Position */
#define PWM_PCR_CH1INV_Msk                      (1ul << PWM_PCR_CH1INV_Pos)         /*!< PWM PCR: CH1INV Mask */

#define PWM_PCR_CH1PINV_Pos                     9                                   /*!< PWM PCR: CH1PINV Position */
#define PWM_PCR_CH1PINV_Msk                     (1ul << PWM_PCR_CH1PINV_Pos)        /*!< PWM PCR: CH1PINV Mask */

#define PWM_PCR_CH1EN_Pos                       8                                   /*!< PWM PCR: CH1EN Position */
#define PWM_PCR_CH1EN_Msk                       (1ul << PWM_PCR_CH1EN_Pos)          /*!< PWM PCR: CH1EN Mask */

#define PWM_PCR_DZEN23_Pos                      5                                   /*!< PWM PCR: DZEN23 Position */
#define PWM_PCR_DZEN23_Msk                      (1ul << PWM_PCR_DZEN23_Pos)         /*!< PWM PCR: DZEN23 Mask */

#define PWM_PCR_DZEN01_Pos                      4                                   /*!< PWM PCR: DZEN01 Position */
#define PWM_PCR_DZEN01_Msk                      (1ul << PWM_PCR_DZEN01_Pos)         /*!< PWM PCR: DZEN01 Mask */

#define PWM_PCR_CH0MOD_Pos                      3                                   /*!< PWM PCR: CH0MOD Position */
#define PWM_PCR_CH0MOD_Msk                      (1ul << PWM_PCR_CH0MOD_Pos)         /*!< PWM PCR: CH0MOD Mask */

#define PWM_PCR_CH0INV_Pos                      2                                   /*!< PWM PCR: CH0INV Position */
#define PWM_PCR_CH0INV_Msk                      (1ul << PWM_PCR_CH0INV_Pos)         /*!< PWM PCR: CH0INV Mask */

#define PWM_PCR_CH0PINV_Pos                      1                                  /*!< PWM PCR: CH0PINV Position */
#define PWM_PCR_CH0PINV_Msk                     (1ul << PWM_PCR_CH0PINV_Pos)        /*!< PWM PCR: CH0PINV Mask */

#define PWM_PCR_CH0EN_Pos                       0                                   /*!< PWM PCR: CH0EN Position */
#define PWM_PCR_CH0EN_Msk                       (1ul << PWM_PCR_CH0EN_Pos)          /*!< PWM PCR: CH0EN Mask */

/* PWM CNR Bit Field Definitions */
#define PWM_CNR_CNR_Pos                         0                                   /*!< PWM CNR: CNR Position */
#define PWM_CNR_CNR_Msk                         (0xFFFFul << PWM_CNR_CNR_Pos)       /*!< PWM CNR: CNR Mask */

/* PWM CMR Bit Field Definitions */
#define PWM_CMR_CMR_Pos                         0                                   /*!< PWM CMR: CMR Position */
#define PWM_CMR_CMR_Msk                         (0xFFFFul << PWM_CMR_CMR_Pos)       /*!< PWM CMR: CMR Mask */

/* PWM PDR Bit Field Definitions */
#define PWM_PDR_PDR_Pos                         0                                   /*!< PWM PDR: PDR Position */
#define PWM_PDR_PDR_Msk                         (0xFFFFul << PWM_PDR_PDR_Pos)       /*!< PWM PDR: PDR Mask */

/* PWM PBCR Bit Field Definitions */
#define PWM_PBCR_BCn_Pos                         0                                  /*!< PWM PBCR: BCn Position */
#define PWM_PBCR_BCn_Msk                         (1ul << PWM_PBCR_BCn_Pos)          /*!< PWM PBCR: BCn Mask */

/* PWM PIER Bit Field Definitions */

#define PWM_PIER_INT23TYPE_Pos                  17                                  /*!< PWM PIER: INT23TYPE Position */
#define PWM_PIER_INT23TYPE_Msk                     (1ul << PWM_PIER_INT23TYPE_Pos)  /*!< PWM PIER: INT23TYPE Mask */

#define PWM_PIER_INT01TYPE_Pos                  16                                  /*!< PWM PIER: INT01TYPE Position */
#define PWM_PIER_INT01TYPE_Msk                     (1ul << PWM_PIER_INT01TYPE_Pos)  /*!< PWM PIER: INT01TYPE Mask */

#define PWM_PIER_PWMDIE3_Pos                    11                                  /*!< PWM PIER: PWMDIE3 Position */
#define PWM_PIER_PWMDIE3_Msk                     (1ul << PWM_PIER_PWMDIE3_Pos)      /*!< PWM PIER: PWMDIE3 Mask */

#define PWM_PIER_PWMDIE2_Pos                    10                                  /*!< PWM PIER: PWMDIE2 Position */
#define PWM_PIER_PWMDIE2_Msk                     (1ul << PWM_PIER_PWMDIE2_Pos)      /*!< PWM PIER: PWMDIE2 Mask */

#define PWM_PIER_PWMDIE1_Pos                    9                                   /*!< PWM PIER: PWMDIE1 Position */
#define PWM_PIER_PWMDIE1_Msk                     (1ul << PWM_PIER_PWMDIE1_Pos)      /*!< PWM PIER: PWMDIE1 Mask */

#define PWM_PIER_PWMDIE0_Pos                    8                                   /*!< PWM PIER: PWMDIE0 Position */
#define PWM_PIER_PWMDIE0_Msk                     (1ul << PWM_PIER_PWMDIE0_Pos)      /*!< PWM PIER: PWMDIE0 Mask */

#define PWM_PIER_PWMIE3_Pos                     3                                   /*!< PWM PIER: PWMIE3 Position */
#define PWM_PIER_PWMIE3_Msk                     (1ul << PWM_PIER_PWMIE3_Pos)        /*!< PWM PIER: PWMIE3 Mask */

#define PWM_PIER_PWMIE2_Pos                     2                                   /*!< PWM PIER: PWMIE2 Position */
#define PWM_PIER_PWMIE2_Msk                     (1ul << PWM_PIER_PWMIE2_Pos)        /*!< PWM PIER: PWMIE2 Mask */

#define PWM_PIER_PWMIE1_Pos                     1                                   /*!< PWM PIER: PWMIE1 Position */
#define PWM_PIER_PWMIE1_Msk                     (1ul << PWM_PIER_PWMIE1_Pos)        /*!< PWM PIER: PWMIE1 Mask */

#define PWM_PIER_PWMIE0_Pos                     0                                   /*!< PWM PIER: PWMIE0 Position */
#define PWM_PIER_PWMIE0_Msk                     (1ul << PWM_PIER_PWMIE0_Pos)        /*!< PWM PIER: PWMIE0 Mask */

/* PWM PIIR Bit Field Definitions */
#define PWM_PIIR_PWMDIF3_Pos                    11                                  /*!< PWM PIIR: PWMDIF3 Position */
#define PWM_PIIR_PWMDIF3_Msk                    (1ul << PWM_PIIR_PWMDIF3_Pos)       /*!< PWM PIIR: PWMDIF3 Mask */

#define PWM_PIIR_PWMDIF2_Pos                    10                                  /*!< PWM PIIR: PWMDIF2 Position */
#define PWM_PIIR_PWMDIF2_Msk                    (1ul << PWM_PIIR_PWMDIF2_Pos)       /*!< PWM PIIR: PWMDIF2 Mask */

#define PWM_PIIR_PWMDIF1_Pos                    9                                   /*!< PWM PIIR: PWMDIF1 Position */
#define PWM_PIIR_PWMDIF1_Msk                    (1ul << PWM_PIIR_PWMDIF1_Pos)       /*!< PWM PIIR: PWMDIF1 Mask */

#define PWM_PIIR_PWMDIF0_Pos                    8                                   /*!< PWM PIIR: PWMDIF0 Position */
#define PWM_PIIR_PWMDIF0_Msk                    (1ul << PWM_PIIR_PWMDIF0_Pos)       /*!< PWM PIIR: PWMDIF0 Mask */

#define PWM_PIIR_PWMIF3_Pos                     3                                   /*!< PWM PIIR: PWMIF3 Position */
#define PWM_PIIR_PWMIF3_Msk                     (1ul << PWM_PIIR_PWMIF3_Pos)        /*!< PWM PIIR: PWMIF3 Mask */

#define PWM_PIIR_PWMIF2_Pos                     2                                   /*!< PWM PIIR: PWMIF2 Position */
#define PWM_PIIR_PWMIF2_Msk                     (1ul << PWM_PIIR_PWMIF2_Pos)        /*!< PWM PIIR: PWMIF2 Mask */

#define PWM_PIIR_PWMIF1_Pos                     1                                   /*!< PWM PIIR: PWMIF1 Position */
#define PWM_PIIR_PWMIF1_Msk                     (1ul << PWM_PIIR_PWMIF1_Pos)        /*!< PWM PIIR: PWMIF1 Mask */

#define PWM_PIIR_PWMIF0_Pos                     0                                   /*!< PWM PIIR: PWMIF0 Position */
#define PWM_PIIR_PWMIF0_Msk                     (1ul << PWM_PIIR_PWMIF0_Pos)        /*!< PWM PIIR: PWMIF0 Mask */

/* PWM CCR0 Bit Field Definitions */
#define PWM_CCR0_CFLRI1_Pos                     23                                  /*!< PWM CCR0: CFLRI1 Position */
#define PWM_CCR0_CFLRI1_Msk                     (1ul << PWM_CCR0_CFLRI1_Pos)        /*!< PWM CCR0: CFLRI1 Mask */

#define PWM_CCR0_CRLRI1_Pos                     22                                  /*!< PWM CCR0: CRLRI1 Position */
#define PWM_CCR0_CRLRI1_Msk                     (1ul << PWM_CCR0_CRLRI1_Pos)        /*!< PWM CCR0: CRLRI1 Mask */

#define PWM_CCR0_CAPIF1_Pos                     20                                  /*!< PWM CCR0: CAPIF1 Position */
#define PWM_CCR0_CAPIF1_Msk                     (1ul << PWM_CCR0_CAPIF1_Pos)        /*!< PWM CCR0: CAPIF1 Mask */

#define PWM_CCR0_CAPCH1EN_Pos                   19                                  /*!< PWM CCR0: CAPCH1EN Position */
#define PWM_CCR0_CAPCH1EN_Msk                   (1ul << PWM_CCR0_CAPCH1EN_Pos)      /*!< PWM CCR0: CAPCH1EN Mask */

#define PWM_CCR0_CFL_IE1_Pos                    18                                  /*!< PWM CCR0: CFL_IE1 Position */
#define PWM_CCR0_CFL_IE1_Msk                    (1ul << PWM_CCR0_CFL_IE1_Pos)       /*!< PWM CCR0: CFL_IE1 Mask */

#define PWM_CCR0_CRL_IE1_Pos                    17                                  /*!< PWM CCR0: CRL_IE1 Position */
#define PWM_CCR0_CRL_IE1_Msk                    (1ul << PWM_CCR0_CRL_IE1_Pos)       /*!< PWM CCR0: CRL_IE1 Mask */

#define PWM_CCR0_INV1_Pos                       16                                  /*!< PWM CCR0: INV1 Position */
#define PWM_CCR0_INV1_Msk                       (1ul << PWM_CCR0_INV1_Pos)          /*!< PWM CCR0: INV1 Mask */

#define PWM_CCR0_CFLRI0_Pos                     7                                   /*!< PWM CCR0: CFLRI0 Position */
#define PWM_CCR0_CFLRI0_Msk                     (1ul << PWM_CCR0_CFLRI0_Pos)        /*!< PWM CCR0: CFLRI0 Mask */

#define PWM_CCR0_CRLRI0_Pos                     6                                   /*!< PWM CCR0: CRLRI0 Position */
#define PWM_CCR0_CRLRI0_Msk                     (1ul << PWM_CCR0_CRLRI0_Pos)        /*!< PWM CCR0: CRLRI0 Mask */

#define PWM_CCR0_CAPIF0_Pos                     4                                   /*!< PWM CCR0: CAPIF0 Position */
#define PWM_CCR0_CAPIF0_Msk                     (1ul << PWM_CCR0_CAPIF0_Pos)        /*!< PWM CCR0: CAPIF0 Mask */

#define PWM_CCR0_CAPCH0EN_Pos                   3                                   /*!< PWM CCR0: CAPCH0EN Position */
#define PWM_CCR0_CAPCH0EN_Msk                   (1ul << PWM_CCR0_CAPCH0EN_Pos)      /*!< PWM CCR0: CAPCH0EN Mask */

#define PWM_CCR0_CFL_IE0_Pos                    2                                   /*!< PWM CCR0: CFL_IE0 Position */
#define PWM_CCR0_CFL_IE0_Msk                    (1ul << PWM_CCR0_CFL_IE0_Pos)       /*!< PWM CCR0: CFL_IE0 Mask */

#define PWM_CCR0_CRL_IE0_Pos                    1                                   /*!< PWM CCR0: CRL_IE0 Position */
#define PWM_CCR0_CRL_IE0_Msk                    (1ul << PWM_CCR0_CRL_IE0_Pos)       /*!< PWM CCR0: CRL_IE0 Mask */

#define PWM_CCR0_INV0_Pos                       0                                   /*!< PWM CCR0: INV0 Position */
#define PWM_CCR0_INV0_Msk                       (1ul << PWM_CCR0_INV0_Pos)          /*!< PWM CCR0: INV0 Mask */

/* PWM CCR2 Bit Field Definitions */
#define PWM_CCR2_CFLRI3_Pos                     23                                  /*!< PWM CCR2: CFLRI3 Position */
#define PWM_CCR2_CFLRI3_Msk                     (1ul << PWM_CCR2_CFLRI3_Pos)        /*!< PWM CCR2: CFLRI3 Mask */

#define PWM_CCR2_CRLRI3_Pos                     22                                  /*!< PWM CCR2: CRLRI3 Position */
#define PWM_CCR2_CRLRI3_Msk                     (1ul << PWM_CCR2_CRLRI3_Pos)        /*!< PWM CCR2: CRLRI3 Mask */

#define PWM_CCR2_CAPIF3_Pos                     20                                  /*!< PWM CCR2: CAPIF3 Position */
#define PWM_CCR2_CAPIF3_Msk                     (1ul << PWM_CCR2_CAPIF3_Pos)        /*!< PWM CCR2: CAPIF3 Mask */

#define PWM_CCR2_CAPCH3EN_Pos                   19                                  /*!< PWM CCR2: CAPCH3EN Position */
#define PWM_CCR2_CAPCH3EN_Msk                   (1ul << PWM_CCR2_CAPCH3EN_Pos)      /*!< PWM CCR2: CAPCH3EN Mask */

#define PWM_CCR2_CFL_IE3_Pos                    18                                  /*!< PWM CCR2: CFL_IE3 Position */
#define PWM_CCR2_CFL_IE3_Msk                    (1ul << PWM_CCR2_CFL_IE3_Pos)       /*!< PWM CCR2: CFL_IE3 Mask */

#define PWM_CCR2_CRL_IE3_Pos                    17                                  /*!< PWM CCR2: CRL_IE3 Position */
#define PWM_CCR2_CRL_IE3_Msk                    (1ul << PWM_CCR2_CRL_IE3_Pos)       /*!< PWM CCR2: CRL_IE3 Mask */

#define PWM_CCR2_INV3_Pos                       16                                  /*!< PWM CCR2: INV3 Position */
#define PWM_CCR2_INV3_Msk                       (1ul << PWM_CCR2_INV3_Pos)          /*!< PWM CCR2: INV3 Mask */

#define PWM_CCR2_CFLRI2_Pos                     7                                   /*!< PWM CCR2: CFLRI2 Position */
#define PWM_CCR2_CFLRI2_Msk                     (1ul << PWM_CCR2_CFLRI2_Pos)        /*!< PWM CCR2: CFLRI2 Mask */

#define PWM_CCR2_CRLRI2_Pos                     6                                   /*!< PWM CCR2: CRLRI2 Position */
#define PWM_CCR2_CRLRI2_Msk                     (1ul << PWM_CCR2_CRLRI2_Pos)        /*!< PWM CCR2: CRLRI2 Mask */

#define PWM_CCR2_CAPIF2_Pos                     4                                   /*!< PWM CCR2: CAPIF2 Position */
#define PWM_CCR2_CAPIF2_Msk                     (1ul << PWM_CCR2_CAPIF2_Pos)        /*!< PWM CCR2: CAPIF2 Mask */

#define PWM_CCR2_CAPCH2EN_Pos                   3                                   /*!< PWM CCR2: CAPCH2EN Position */
#define PWM_CCR2_CAPCH2EN_Msk                   (1ul << PWM_CCR2_CAPCH2EN_Pos)      /*!< PWM CCR2: CAPCH2EN Mask */

#define PWM_CCR2_CFL_IE2_Pos                    2                                   /*!< PWM CCR2: CFL_IE2 Position */
#define PWM_CCR2_CFL_IE2_Msk                    (1ul << PWM_CCR2_CFL_IE2_Pos)       /*!< PWM CCR2: CFL_IE2 Mask */

#define PWM_CCR2_CRL_IE2_Pos                    1                                   /*!< PWM CCR2: CRL_IE2 Position */
#define PWM_CCR2_CRL_IE2_Msk                    (1ul << PWM_CCR2_CRL_IE2_Pos)       /*!< PWM CCR2: CRL_IE2 Mask */

#define PWM_CCR2_INV2_Pos                       0                                   /*!< PWM CCR2: INV2 Position */
#define PWM_CCR2_INV2_Msk                       (1ul << PWM_CCR2_INV2_Pos)          /*!< PWM CCR2: INV2 Mask */

/* PWM CRLR Bit Field Definitions */
#define PWM_CRLR_CRLR_Pos                       0                                   /*!< PWM CRLR: CRLR Position */
#define PWM_CRLR_CRLR_Msk                       (0xFFFFul << PWM_CRLR_CRLR_Pos)     /*!< PWM CRLR: CRLR Mask */

/* PWM CFLR Bit Field Definitions */
#define PWM_CFLR_CFLR_Pos                       0                                   /*!< PWM CFLR: CFLR Position */
#define PWM_CFLR_CFLR_Msk                       (0xFFFFul << PWM_CFLR_CFLR_Pos)     /*!< PWM CFLR: CFLR Mask */

/* PWM CAPENR Bit Field Definitions */
#define PWM_CAPENR_CINEN3_Pos                   3                                   /*!< PWM CAPENR: CINEN3 Position */
#define PWM_CAPENR_CINEN3_Msk                   (1ul << PWM_CAPENR_CINEN3_Pos)      /*!< PWM CAPENR: CINEN3 Mask */   

#define PWM_CAPENR_CINEN2_Pos                   2                                   /*!< PWM CAPENR: CINEN2 Position */
#define PWM_CAPENR_CINEN2_Msk                   (1ul << PWM_CAPENR_CINEN2_Pos)      /*!< PWM CAPENR: CINEN2 Mask */  

#define PWM_CAPENR_CINEN1_Pos                   1                                   /*!< PWM CAPENR: CINEN1 Position */
#define PWM_CAPENR_CINEN1_Msk                   (1ul << PWM_CAPENR_CINEN1_Pos)      /*!< PWM CAPENR: CINEN1 Mask */  

#define PWM_CAPENR_CINEN0_Pos                   0                                   /*!< PWM CAPENR: CINEN0 Position */
#define PWM_CAPENR_CINEN0_Msk                   (1ul << PWM_CAPENR_CINEN0_Pos)      /*!< PWM CAPENR: CINEN0 Mask */ 

/* PWM POE Bit Field Definitions */
#define PWM_POE_POE3_Pos                        3                                   /*!< PWM POE: POE3 Position */
#define PWM_POE_POE3_Msk                        (1ul << PWM_POE_POE3_Pos)           /*!< PWM POE: POE3 Mask */   

#define PWM_POE_POE2_Pos                        2                                   /*!< PWM POE: POE2 Position */
#define PWM_POE_POE2_Msk                        (1ul << PWM_POE_POE2_Pos)           /*!< PWM POE: POE2 Mask */  

#define PWM_POE_POE1_Pos                        1                                   /*!< PWM POE: POE1 Position */
#define PWM_POE_POE1_Msk                        (1ul << PWM_POE_POE1_Pos)           /*!< PWM POE: POE1 Mask */  

#define PWM_POE_POE0_Pos                        0                                   /*!< PWM POE: POE0 Position */
#define PWM_POE_POE0_Msk                        (1ul << PWM_POE_POE0_Pos)           /*!< PWM POE: POE0 Mask */  

/* PWM TCON Bit Field Definitions */

#define PWM_TCON_PWM3TEN_Pos                    3                                   /*!< PWM TCON: PWM3TEN Position */
#define PWM_TCON_PWM3TEN_Msk                    (1ul << PWM_TCON_PWM3TEN_Pos)       /*!< PWM TCON: PWM3TEN Mask */ 

#define PWM_TCON_PWM2TEN_Pos                    2                                   /*!< PWM TCON: PWM2TEN Position */
#define PWM_TCON_PWM2TEN_Msk                    (1ul << PWM_TCON_PWM2TEN_Pos)       /*!< PWM TCON: PWM2TEN Mask */ 

#define PWM_TCON_PWM1TEN_Pos                    1                                   /*!< PWM TCON: PWM1TEN Position */
#define PWM_TCON_PWM1TEN_Msk                    (1ul << PWM_TCON_PWM1TEN_Pos)       /*!< PWM TCON: PWM1TEN Mask */ 

#define PWM_TCON_PWM0TEN_Pos                    0                                   /*!< PWM TCON: PWM0TEN Position */
#define PWM_TCON_PWM0TEN_Msk                    (1ul << PWM_TCON_PWM0TEN_Pos)       /*!< PWM TCON: PWM0TEN Mask */ 

/* PWM TSTATUS Bit Field Definitions */

#define PWM_TSTATUS_PWM3TF_Pos                  3                                   /*!< PWM TSTATUS: PWM3TF Position */
#define PWM_TSTATUS_PWM3TF_Msk                  (1ul << PWM_TSTATUS_PWM3TF_Pos)     /*!< PWM TSTATUS: PWM3TF Mask */ 

#define PWM_TSTATUS_PWM2TF_Pos                  2                                   /*!< PWM TSTATUS: PWM2TF Position */
#define PWM_TSTATUS_PWM2TF_Msk                  (1ul << PWM_TSTATUS_PWM2TF_Pos)     /*!< PWM TSTATUS: PWM2TF Mask */ 

#define PWM_TSTATUS_PWM1TF_Pos                  1                                   /*!< PWM TSTATUS: PWM1TF Position */
#define PWM_TSTATUS_PWM1TF_Msk                  (1ul << PWM_TSTATUS_PWM1TF_Pos)     /*!< PWM TSTATUS: PWM1TF Mask */ 

#define PWM_TSTATUS_PWM0TF_Pos                  0                                   /*!< PWM TSTATUS: PWM0TF Position */
#define PWM_TSTATUS_PWM0TF_Msk                  (1ul << PWM_TSTATUS_PWM0TF_Pos)     /*!< PWM TSTATUS: PWM0TF Mask */ 

/* PWM SYNCBUSY0 Bit Field Definitions */
#define PWM_SYNCBUSY0_S_BUSY_Pos                0                                   /*!< PWM SYNCBUSY0: S_BUSY Position */
#define PWM_SYNCBUSY0_S_BUSY_Msk                (1ul << PWM_SYNCBUSY0_S_BUSY_Pos)   /*!< PWM SYNCBUSY0: S_BUSY Mask */ 

/* PWM SYNCBUSY1 Bit Field Definitions */
#define PWM_SYNCBUSY1_S_BUSY_Pos                0                                   /*!< PWM SYNCBUSY1: S_BUSY Position */
#define PWM_SYNCBUSY1_S_BUSY_Msk                (1ul << PWM_SYNCBUSY1_S_BUSY_Pos)   /*!< PWM SYNCBUSY1: S_BUSY Mask */ 

/* PWM SYNCBUSY2 Bit Field Definitions */
#define PWM_SYNCBUSY2_S_BUSY_Pos                0                                   /*!< PWM SYNCBUSY2: S_BUSY Position */
#define PWM_SYNCBUSY2_S_BUSY_Msk                (1ul << PWM_SYNCBUSY2_S_BUSY_Pos)   /*!< PWM SYNCBUSY2: S_BUSY Mask */ 

/* PWM SYNCBUSY3 Bit Field Definitions */
#define PWM_SYNCBUSY3_S_BUSY_Pos                0                                   /*!< PWM SYNCBUSY3: S_BUSY Position */
#define PWM_SYNCBUSY3_S_BUSY_Msk                (1ul << PWM_SYNCBUSY3_S_BUSY_Pos)   /*!< PWM SYNCBUSY3: S_BUSY Mask */

/* PWM CAPPDMACTL Bit Field Definitions */
#define PWM_CAPPDMACTL_CAP3RFORDER_Pos          27                                       /*!< PWM CAPPDMACTL: CAP3RFORDER Position */
#define PWM_CAPPDMACTL_CAP3RFORDER_Msk          (1ul << PWM_CAPPDMACTL_CAP3RFORDER_Pos)  /*!< PWM CAPPDMACTL: CAP3RFORDER Mask */

#define PWM_CAPPDMACTL_CAP3PDMAMOD_Pos          25                                       /*!< PWM CAPPDMACTL: CAP3PDMAMOD Position */
#define PWM_CAPPDMACTL_CAP3PDMAMOD_Msk          (3ul << PWM_CAPPDMACTL_CAP3PDMAMOD_Pos)  /*!< PWM CAPPDMACTL: CAP3PDMAMOD Mask */

#define PWM_CAPPDMACTL_CAP3PDMAEN_Pos           24                                       /*!< PWM CAPPDMACTL: CAP3PDMAEN Position */
#define PWM_CAPPDMACTL_CAP3PDMAEN_Msk           (1ul << PWM_CAPPDMACTL_CAP3PDMAEN_Pos)   /*!< PWM CAPPDMACTL: CAP3PDMAEN Mask */

#define PWM_CAPPDMACTL_CAP2RFORDER_Pos          19                                       /*!< PWM CAPPDMACTL: CAP2RFORDER Position */
#define PWM_CAPPDMACTL_CAP2RFORDER_Msk          (1ul << PWM_CAPPDMACTL_CAP2RFORDER_Pos)  /*!< PWM CAPPDMACTL: CAP2RFORDER Mask */

#define PWM_CAPPDMACTL_CAP2PDMAMOD_Pos          17                                       /*!< PWM CAPPDMACTL: CAP2PDMAMOD Position */
#define PWM_CAPPDMACTL_CAP2PDMAMOD_Msk          (3ul << PWM_CAPPDMACTL_CAP2PDMAMOD_Pos)  /*!< PWM CAPPDMACTL: CAP2PDMAMOD Mask */

#define PWM_CAPPDMACTL_CAP2PDMAEN_Pos           16                                       /*!< PWM CAPPDMACTL: CAP2PDMAEN Position */
#define PWM_CAPPDMACTL_CAP2PDMAEN_Msk           (1ul << PWM_CAPPDMACTL_CAP2PDMAEN_Pos)   /*!< PWM CAPPDMACTL: CAP2PDMAEN Mask */

#define PWM_CAPPDMACTL_CAP1RFORDER_Pos          11                                       /*!< PWM CAPPDMACTL: CAP1RFORDER Position */
#define PWM_CAPPDMACTL_CAP1RFORDER_Msk          (1ul << PWM_CAPPDMACTL_CAP1RFORDER_Pos)  /*!< PWM CAPPDMACTL: CAP1RFORDER Mask */

#define PWM_CAPPDMACTL_CAP1PDMAMOD_Pos          9                                        /*!< PWM CAPPDMACTL: CAP1PDMAMOD Position */
#define PWM_CAPPDMACTL_CAP1PDMAMOD_Msk          (3ul << PWM_CAPPDMACTL_CAP1PDMAMOD_Pos)  /*!< PWM CAPPDMACTL: CAP1PDMAMOD Mask */

#define PWM_CAPPDMACTL_CAP1PDMAEN_Pos           8                                        /*!< PWM CAPPDMACTL: CAP1PDMAEN Position */
#define PWM_CAPPDMACTL_CAP1PDMAEN_Msk           (1ul << PWM_CAPPDMACTL_CAP1PDMAEN_Pos)   /*!< PWM CAPPDMACTL: CAP1PDMAEN Mask */

#define PWM_CAPPDMACTL_CAP0RFORDER_Pos          3                                        /*!< PWM CAPPDMACTL: CAP0RFORDER Position */
#define PWM_CAPPDMACTL_CAP0RFORDER_Msk          (1ul << PWM_CAPPDMACTL_CAP0RFORDER_Pos)  /*!< PWM CAPPDMACTL: CAP0RFORDER Mask */

#define PWM_CAPPDMACTL_CAP0PDMAMOD_Pos          1                                        /*!< PWM CAPPDMACTL: CAP0PDMAMOD Position */
#define PWM_CAPPDMACTL_CAP0PDMAMOD_Msk          (3ul << PWM_CAPPDMACTL_CAP0PDMAMOD_Pos)  /*!< PWM CAPPDMACTL: CAP0PDMAMOD Mask */

#define PWM_CAPPDMACTL_CAP0PDMAEN_Pos           0                                        /*!< PWM CAPPDMACTL: CAP0PDMAEN Position */
#define PWM_CAPPDMACTL_CAP0PDMAEN_Msk           (1ul << PWM_CAPPDMACTL_CAP0PDMAEN_Pos)   /*!< PWM CAPPDMACTL: CAP0PDMAEN Mask */

/* PWM CAP0PDMA Bit Field Definitions */
#define PWM_CAP0PDMA_CAP0RFPDMA_Pos             0                                        /*!< PWM CAP0PDMA: CAP0RFPDMA Position */
#define PWM_CAP0PDMA_CAP0RFPDMA_Msk             (0xFFFF << PWM_CAP0PDMA_CAP0RFPDMA_Pos)  /*!< PWM CAP0PDMA: CAP0RFPDMA Mask */

/* PWM CAP1PDMA Bit Field Definitions */
#define PWM_CAP1PDMA_CAP0RFPDMA_Pos             0                                        /*!< PWM CAP1PDMA: CAP1RFPDMA Position */
#define PWM_CAP1PDMA_CAP0RFPDMA_Msk             (0xFFFF << PWM_CAP0PDMA_CAP1RFPDMA_Pos)  /*!< PWM CAP1PDMA: CAP1RFPDMA Mask */

/* PWM CAP2PDMA Bit Field Definitions */
#define PWM_CAP2PDMA_CAP0RFPDMA_Pos             0                                        /*!< PWM CAP2PDMA: CAP2RFPDMA Position */
#define PWM_CAP2PDMA_CAP0RFPDMA_Msk             (0xFFFF << PWM_CAP0PDMA_CAP2RFPDMA_Pos)  /*!< PWM CAP2PDMA: CAP2RFPDMA Mask */

/* PWM CAP3PDMA Bit Field Definitions */
#define PWM_CAP3PDMA_CAP0RFPDMA_Pos             0                                        /*!< PWM CAP3PDMA: CAP3RFPDMA Position */
#define PWM_CAP3PDMA_CAP0RFPDMA_Msk             (0xFFFF << PWM_CAP0PDMA_CAP3RFPDMA_Pos)  /*!< PWM CAP3PDMA: CAP3RFPDMA Mask */

/*@}*/ /* end of group NUC123_PWM */


/*----------------------------- I2S Controller -------------------------------*/
/** @addtogroup NUC123_I2S NUC123 I2S
  Memory Mapped Structure for NUC123 Series I2S Interface Controller
  @{
 */
typedef struct
{
    __IO uint32_t CON;                /*!< Offset: 0x00  I2S Control Register               */
    __IO uint32_t CLKDIV;             /*!< Offset: 0x04  I2S Clock Divider Register         */
    __IO uint32_t IE;                 /*!< Offset: 0x08  I2S Interrupt Enable Register      */
    __IO  uint32_t STATUS;             /*!< Offset: 0x0C  I2S Status Register                */
    __O  uint32_t TXFIFO;             /*!< Offset: 0x10  I2S Transmit FIFO Register         */
    __I  uint32_t RXFIFO;             /*!< Offset: 0x14  I2S Receive FIFO Register          */
} I2S_T;


/* I2S I2SCON Bit Field Definitions */
#define I2S_CON_PCM_Pos                      24                                   /*!< I2S I2SCON: PCM Position         */
#define I2S_CON_PCM_Msk                      (1ul << I2S_CON_PCM_Pos)             /*!< I2S I2SCON: PCM Mask             */

#define I2S_CON_RXLCH_Pos                    23                                   /*!< I2S I2SCON: RXLCH Position         */
#define I2S_CON_RXLCH_Msk                    (1ul << I2S_CON_RXLCH_Pos)           /*!< I2S I2SCON: RXLCH Mask             */

#define I2S_CON_RXDMA_Pos                    21                                   /*!< I2S I2SCON: RXDMA Position         */
#define I2S_CON_RXDMA_Msk                    (1ul << I2S_CON_RXDMA_Pos)           /*!< I2S I2SCON: RXDMA Mask             */

#define I2S_CON_TXDMA_Pos                    20                                   /*!< I2S I2SCON: TXDMA Position         */
#define I2S_CON_TXDMA_Msk                    (1ul << I2S_CON_TXDMA_Pos)           /*!< I2S I2SCON: TXDMA Mask             */

#define I2S_CON_CLR_RXFIFO_Pos               19                                   /*!< I2S I2SCON: CLR_RXFIFO Position    */
#define I2S_CON_CLR_RXFIFO_Msk               (1ul << I2S_CON_CLR_RXFIFO_Pos)      /*!< I2S I2SCON: CLR_RXFIFO Mask        */

#define I2S_CON_CLR_TXFIFO_Pos               18                                   /*!< I2S I2SCON: CLR_TXFIFO Position    */
#define I2S_CON_CLR_TXFIFO_Msk               (1ul << I2S_CON_CLR_TXFIFO_Pos)      /*!< I2S I2SCON: CLR_TXFIFO Mask        */

#define I2S_CON_LCHZCEN_Pos                  17                                   /*!< I2S I2SCON: LCHZCEN Position       */
#define I2S_CON_LCHZCEN_Msk                  (1ul << I2S_CON_LCHZCEN_Pos)         /*!< I2S I2SCON: LCHZCEN Mask           */

#define I2S_CON_RCHZCEN_Pos                  16                                   /*!< I2S I2SCON: RCHZCEN Position       */
#define I2S_CON_RCHZCEN_Msk                  (1ul << I2S_CON_RCHZCEN_Pos)         /*!< I2S I2SCON: RCHZCEN Mask           */

#define I2S_CON_MCLKEN_Pos                   15                                   /*!< I2S I2SCON: MCLKEN Position        */
#define I2S_CON_MCLKEN_Msk                   (1ul << I2S_CON_MCLKEN_Pos)          /*!< I2S I2SCON: MCLKEN Mask            */

#define I2S_CON_RXTH_Pos                     12                                   /*!< I2S I2SCON: RXTH Position          */
#define I2S_CON_RXTH_Msk                     (7ul << I2S_CON_RXTH_Pos)            /*!< I2S I2SCON: RXTH Mask              */

#define I2S_CON_TXTH_Pos                     9                                    /*!< I2S I2SCON: TXTH Position          */
#define I2S_CON_TXTH_Msk                     (7ul << I2S_CON_TXTH_Pos)            /*!< I2S I2SCON: TXTH Mask              */

#define I2S_CON_SLAVE_Pos                    8                                    /*!< I2S I2SCON: SLAVE Position         */
#define I2S_CON_SLAVE_Msk                    (1ul << I2S_CON_SLAVE_Pos)           /*!< I2S I2SCON: SLAVE Mask             */

#define I2S_CON_FORMAT_Pos                   7                                    /*!< I2S I2SCON: FORMAT Position        */
#define I2S_CON_FORMAT_Msk                   (1ul << I2S_CON_FORMAT_Pos)          /*!< I2S I2SCON: FORMAT Mask            */

#define I2S_CON_MONO_Pos                     6                                    /*!< I2S I2SCON: MONO Position          */
#define I2S_CON_MONO_Msk                     (1ul << I2S_CON_MONO_Pos)            /*!< I2S I2SCON: MONO Mask              */

#define I2S_CON_WORDWIDTH_Pos                4                                    /*!< I2S I2SCON: WORDWIDTH Position     */
#define I2S_CON_WORDWIDTH_Msk                (3ul << I2S_CON_WORDWIDTH_Pos)       /*!< I2S I2SCON: WORDWIDTH Mask         */

#define I2S_CON_MUTE_Pos                     3                                    /*!< I2S I2SCON: MUTE Position          */
#define I2S_CON_MUTE_Msk                     (1ul << I2S_CON_MUTE_Pos)            /*!< I2S I2SCON: MUTE Mask              */

#define I2S_CON_RXEN_Pos                     2                                    /*!< I2S I2SCON: RXEN Position          */
#define I2S_CON_RXEN_Msk                     (1ul << I2S_CON_RXEN_Pos)            /*!< I2S I2SCON: RXEN Mask              */

#define I2S_CON_TXEN_Pos                     1                                    /*!< I2S I2SCON: TXEN Position          */
#define I2S_CON_TXEN_Msk                     (1ul << I2S_CON_TXEN_Pos)            /*!< I2S I2SCON: TXEN Mask              */

#define I2S_CON_I2SEN_Pos                    0                                    /*!< I2S I2SCON: I2SEN Position         */
#define I2S_CON_I2SEN_Msk                    (1ul << I2S_CON_I2SEN_Pos)           /*!< I2S I2SCON: I2SEN Mask             */

/* I2S I2SCLKDIV Bit Field Definitions */
#define I2S_CLKDIV_BCLK_DIV_Pos              8                                       /*!< I2S I2SCLKDIV: BCLK_DIV Position   */
#define I2S_CLKDIV_BCLK_DIV_Msk              (0xFFul << I2S_CLKDIV_BCLK_DIV_Pos)  /*!< I2S I2SCLKDIV: BCLK_DIV Mask       */

#define I2S_CLKDIV_MCLK_DIV_Pos              0                                       /*!< I2S I2SCLKDIV: MCLK_DIV Position   */
#define I2S_CLKDIV_MCLK_DIV_Msk              (7ul << I2S_CLKDIV_MCLK_DIV_Pos)     /*!< I2S I2SCLKDIV: MCLK_DIV Mask       */

/* I2S I2SIE Bit Field Definitions */
#define I2S_IE_LZCIE_Pos                     12                                      /*!< I2S I2SIE: LZCIE Position          */
#define I2S_IE_LZCIE_Msk                     (1ul << I2S_IE_LZCIE_Pos)            /*!< I2S I2SIE: LZCIE Mask              */

#define I2S_IE_RZCIE_Pos                     11                                   /*!< I2S I2SIE: RZCIE Position          */
#define I2S_IE_RZCIE_Msk                     (1ul << I2S_IE_RZCIE_Pos)            /*!< I2S I2SIE: RZCIE Mask              */

#define I2S_IE_TXTHIE_Pos                    10                                   /*!< I2S I2SIE: TXTHIE Position         */
#define I2S_IE_TXTHIE_Msk                    (1ul << I2S_IE_TXTHIE_Pos)           /*!< I2S I2SIE: TXTHIE Mask             */
                                     
#define I2S_IE_TXOVFIE_Pos                   9                                    /*!< I2S I2SIE: TXOVFIE Position        */
#define I2S_IE_TXOVFIE_Msk                   (1ul << I2S_IE_TXOVFIE_Pos)          /*!< I2S I2SIE: TXOVFIE Mask            */

#define I2S_IE_TXUDFIE_Pos                   8                                    /*!< I2S I2SIE: TXUDFIE Position        */
#define I2S_IE_TXUDFIE_Msk                   (1ul << I2S_IE_TXUDFIE_Pos)          /*!< I2S I2SIE: TXUDFIE Mask            */

#define I2S_IE_RXTHIE_Pos                    2                                    /*!< I2S I2SIE: RXTHIE Position         */
#define I2S_IE_RXTHIE_Msk                    (1ul << I2S_IE_RXTHIE_Pos)           /*!< I2S I2SIE: RXTHIE Mask             */
                                     
#define I2S_IE_RXOVFIE_Pos                   1                                    /*!< I2S I2SIE: RXOVFIE Position        */
#define I2S_IE_RXOVFIE_Msk                   (1ul << I2S_IE_RXOVFIE_Pos)          /*!< I2S I2SIE: RXOVFIE Mask            */

#define I2S_IE_RXUDFIE_Pos                   0                                    /*!< I2S I2SIE: RXUDFIE Position        */
#define I2S_IE_RXUDFIE_Msk                   (1ul << I2S_IE_RXUDFIE_Pos)          /*!< I2S I2SIE: RXUDFIE Mask            */


/* I2S I2SSTATUS Bit Field Definitions */
#define I2S_STATUS_TX_LEVEL_Pos              28                                      /*!< I2S I2SSTATUS: TX_LEVEL Position   */
#define I2S_STATUS_TX_LEVEL_Msk              (0xFul << I2S_STATUS_TX_LEVEL_Pos)   /*!< I2S I2SSTATUS: TX_LEVEL Mask       */

#define I2S_STATUS_RX_LEVEL_Pos              24                                   /*!< I2S I2SSTATUS: RX_LEVEL Position   */
#define I2S_STATUS_RX_LEVEL_Msk              (0xFul << I2S_STATUS_RX_LEVEL_Pos)   /*!< I2S I2SSTATUS: RX_LEVEL Mask       */

#define I2S_STATUS_LZCF_Pos                  23                                      /*!< I2S I2SSTATUS: LZCF Position       */
#define I2S_STATUS_LZCF_Msk                  (1ul << I2S_STATUS_LZCF_Pos)         /*!< I2S I2SSTATUS: LZCF Mask           */

#define I2S_STATUS_RZCF_Pos                  22                                   /*!< I2S I2SSTATUS: RZCF Position       */
#define I2S_STATUS_RZCF_Msk                  (1ul << I2S_STATUS_RZCF_Pos)         /*!< I2S I2SSTATUS: RZCF Mask           */

#define I2S_STATUS_TXBUSY_Pos                21                                   /*!< I2S I2SSTATUS: TXBUSY Position     */
#define I2S_STATUS_TXBUSY_Msk                (1ul << I2S_STATUS_TXBUSY_Pos)       /*!< I2S I2SSTATUS: TXBUSY Mask         */

#define I2S_STATUS_TXEMPTY_Pos               20                                   /*!< I2S I2SSTATUS: TXEMPTY Position    */
#define I2S_STATUS_TXEMPTY_Msk               (1ul << I2S_STATUS_TXEMPTY_Pos)      /*!< I2S I2SSTATUS: TXEMPTY Mask        */

#define I2S_STATUS_TXFULL_Pos                19                                   /*!< I2S I2SSTATUS: TXFULL Position     */
#define I2S_STATUS_TXFULL_Msk                (1ul << I2S_STATUS_TXFULL_Pos)       /*!< I2S I2SSTATUS: TXFULL Mask         */

#define I2S_STATUS_TXTHF_Pos                 18                                   /*!< I2S I2SSTATUS: TXTHF Position      */
#define I2S_STATUS_TXTHF_Msk                 (1ul << I2S_STATUS_TXTHF_Pos)        /*!< I2S I2SSTATUS: TXTHF Mask          */

#define I2S_STATUS_TXOVF_Pos                 17                                   /*!< I2S I2SSTATUS: TXOVF Position      */
#define I2S_STATUS_TXOVF_Msk                 (1ul << I2S_STATUS_TXOVF_Pos)        /*!< I2S I2SSTATUS: TXOVF Mask          */

#define I2S_STATUS_TXUDF_Pos                 16                                   /*!< I2S I2SSTATUS: TXUDF Position      */
#define I2S_STATUS_TXUDF_Msk                 (1ul << I2S_STATUS_TXUDF_Pos)        /*!< I2S I2SSTATUS: TXUDF Mask          */

#define I2S_STATUS_RXEMPTY_Pos               12                                   /*!< I2S I2SSTATUS: RXEMPTY Position    */
#define I2S_STATUS_RXEMPTY_Msk               (1ul << I2S_STATUS_RXEMPTY_Pos)      /*!< I2S I2SSTATUS: RXEMPTY Mask        */

#define I2S_STATUS_RXFULL_Pos                11                                   /*!< I2S I2SSTATUS: RXFULL Position     */
#define I2S_STATUS_RXFULL_Msk                (1ul << I2S_STATUS_RXFULL_Pos)       /*!< I2S I2SSTATUS: RXFULL Mask         */

#define I2S_STATUS_RXTHF_Pos                 10                                   /*!< I2S I2SSTATUS: RXTHF Position      */
#define I2S_STATUS_RXTHF_Msk                 (1ul << I2S_STATUS_RXTHF_Pos)        /*!< I2S I2SSTATUS: RXTHF Mask          */

#define I2S_STATUS_RXOVF_Pos                 9                                    /*!< I2S I2SSTATUS: RXOVF Position      */
#define I2S_STATUS_RXOVF_Msk                 (1ul << I2S_STATUS_RXOVF_Pos)        /*!< I2S I2SSTATUS: RXOVF Mask          */

#define I2S_STATUS_RXUDF_Pos                 8                                    /*!< I2S I2SSTATUS: RXUDF Position      */
#define I2S_STATUS_RXUDF_Msk                 (1ul << I2S_STATUS_RXUDF_Pos)        /*!< I2S I2SSTATUS: RXUDF Mask          */

#define I2S_STATUS_RIGHT_Pos                 3                                    /*!< I2S I2SSTATUS: RIGHT Position      */
#define I2S_STATUS_RIGHT_Msk                 (1ul << I2S_STATUS_RIGHT_Pos)        /*!< I2S I2SSTATUS: RIGHT Mask          */

#define I2S_STATUS_I2STXINT_Pos              2                                    /*!< I2S I2SSTATUS: I2STXINT Position   */
#define I2S_STATUS_I2STXINT_Msk              (1ul << I2S_STATUS_I2STXINT_Pos)     /*!< I2S I2SSTATUS: I2STXINT Mask       */

#define I2S_STATUS_I2SRXINT_Pos              1                                    /*!< I2S I2SSTATUS: I2SRXINT Position   */
#define I2S_STATUS_I2SRXINT_Msk              (1ul << I2S_STATUS_I2SRXINT_Pos)     /*!< I2S I2SSTATUS: I2SRXINT Mask       */

#define I2S_STATUS_I2SINT_Pos                0                                    /*!< I2S I2SSTATUS: I2SINT Position     */
#define I2S_STATUS_I2SINT_Msk                (1ul << I2S_STATUS_I2SINT_Pos)       /*!< I2S I2SSTATUS: I2SINT Mask         */

/*@}*/ /* end of group NUC123_I2S */




/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup NUC123_SYSTEM_MEM_MAP NUC123 SYSTEM MEM MAP
  Memory Mapped Structure for NUC123 Series Peripheral
  @{
 */
/* Peripheral and SRAM base address */
#define FLASH_BASE          ((     uint32_t)0x00000000)
#define SRAM_BASE           ((     uint32_t)0x20000000)
#define AHB_BASE            ((     uint32_t)0x50000000)
#define APB1_BASE           ((     uint32_t)0x40000000)
#define APB2_BASE           ((     uint32_t)0x40100000)

/* Peripheral memory map */
#define GPIO_BASE           (AHB_BASE        + 0x4000)                   /*!< GPIO Base Address                                   */
#define PA_BASE             (GPIO_BASE               )                   /*!< GPIO PORTA Base Address                             */  
#define PB_BASE             (GPIO_BASE       + 0x0040)                   /*!< GPIO PORTB Base Address                             */
#define PC_BASE             (GPIO_BASE       + 0x0080)                   /*!< GPIO PORTC Base Address                             */
#define PD_BASE             (GPIO_BASE       + 0x00C0)                   /*!< GPIO PORTD Base Address                             */
#define PF_BASE             (GPIO_BASE       + 0x0140)                   /*!< GPIO PORTF Base Address                             */
#define GPIO_DBNCECON_BASE  (GPIO_BASE       + 0x0180)                   /*!< GPIO De-bounce Cycle Control Base Address           */
#define GPIO_PIN_DATA_BASE  (GPIO_BASE       + 0x0200)                   /*!< GPIO Pin Data Input/Output Control Base Address     */


#define UART0_BASE           (APB1_BASE      + 0x50000)
#define UART1_BASE           (APB2_BASE      + 0x50000)


#define TIMER0_BASE          (APB1_BASE      + 0x10000)                 /*!< Timer0 Base Address                              */
#define TIMER1_BASE          (APB1_BASE      + 0x10020)                 /*!< Timer1 Base Address                              */
#define TIMER2_BASE          (APB2_BASE      + 0x10000)                 /*!< Timer2 Base Address                              */
#define TIMER3_BASE          (APB2_BASE      + 0x10020)                 /*!< Timer3 Base Address                              */

#define WDT_BASE             (APB1_BASE      + 0x4000)                  /*!< Watchdog Timer Base Address                      */

#define WWDT_BASE            (APB1_BASE      + 0x4100)                  /*!< Window Watchdog Timer Base Address               */

#define SPI0_BASE            (APB1_BASE      + 0x30000)
#define SPI1_BASE            (APB1_BASE      + 0x34000)
#define SPI2_BASE            (APB2_BASE      + 0x30000)

#define I2C0_BASE            (APB1_BASE      + 0x20000)                 /*!< I2C0 Base Address                                */
#define I2C1_BASE            (APB2_BASE      + 0x20000)                 /*!< I2C1 Base Address                                */

#define ADC_BASE             (APB1_BASE      + 0xE0000)

#define CLK_BASE          (AHB_BASE       + 0x00200)                 /*!< System Clock Controller Base Address             */

#define GCR_BASE             (AHB_BASE       + 0x00000)                 /*!< System Global Controller Base Address            */

#define INT_BASE             (AHB_BASE       + 0x00300)                 /*!< Interrupt Source Controller Base Address         */

#define FMC_BASE             (AHB_BASE       + 0x0C000)

#define PS2_BASE             (APB2_BASE      + 0x00000)					/*!< PS/2 Base Address                                 */

#define USBD_BASE            (APB1_BASE      + 0x60000)
#define USBD_EP_NUM          8

#define PDMA0_BASE           (AHB_BASE       + 0x08000)                 /*!< PDMA0 Base Address                               */
#define PDMA1_BASE           (AHB_BASE       + 0x08100)                 /*!< PDMA1 Base Address                               */
#define PDMA2_BASE           (AHB_BASE       + 0x08200)                 /*!< PDMA2 Base Address                               */
#define PDMA3_BASE           (AHB_BASE       + 0x08300)                 /*!< PDMA3 Base Address                               */
#define PDMA4_BASE           (AHB_BASE       + 0x08400)                 /*!< PDMA4 Base Address                               */
#define PDMA5_BASE           (AHB_BASE       + 0x08500)                 /*!< PDMA5 Base Address                               */

#define PDMA_GCR_BASE        (AHB_BASE       + 0x08F00)                 /*!< PDMA Grobal Base Address                               */

#define CRC_BASE             (AHB_BASE       + 0x08E00)                 /*!< CRC Base Address                                 */

#define PWMA_BASE            (APB1_BASE      + 0x40000)                 /*!< PWMA Base Address                                */

#define I2S_BASE             (APB2_BASE      + 0xA0000)

/*@}*/ /* end of group NUC123_PERIPHERAL_MEM_MAP */

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/** @addtogroup NUC123_PERIPHERAL_DECLARATION NUC123 IP DECLARATION
  The Declaration of NUC123 Series Peripheral
  @{
 */
#define PA                  ((GPIO_T *) PA_BASE)                        /*!< GPIO PORTA Configuration Struct                        */
#define PB                  ((GPIO_T *) PB_BASE)                        /*!< GPIO PORTB Configuration Struct                        */
#define PC                  ((GPIO_T *) PC_BASE)                        /*!< GPIO PORTC Configuration Struct                        */
#define PD                  ((GPIO_T *) PD_BASE)                        /*!< GPIO PORTD Configuration Struct                        */
#define PF                  ((GPIO_T *) PF_BASE)                        /*!< GPIO PORTF Configuration Struct                        */
#define GPIO                ((GPIO_DBNCECON_T *) GPIO_DBNCECON_BASE)    /*!< Interrupt De-bounce Cycle Control Configuration Struct */ 

#define UART0               ((UART_T *) UART0_BASE)
#define UART1               ((UART_T *) UART1_BASE)

#define TIMER0              ((TIMER_T *) TIMER0_BASE)                   /*!< Timer0 Configuration Struct                      */
#define TIMER1              ((TIMER_T *) TIMER1_BASE)                   /*!< Timer1 Configuration Struct                      */
#define TIMER2              ((TIMER_T *) TIMER2_BASE)                   /*!< Timer2 Configuration Struct                      */
#define TIMER3              ((TIMER_T *) TIMER3_BASE)                   /*!< Timer3 Configuration Struct                      */

#define WDT                 ((WDT_T *) WDT_BASE)                        /*!< Watchdog Timer Configuration Struct              */

#define WWDT                ((WWDT_T *) WWDT_BASE)                      /*!< Window Watchdog Timer Configuration Struct       */

#define SPI0                ((SPI_T *) SPI0_BASE)
#define SPI1                ((SPI_T *) SPI1_BASE)
#define SPI2                ((SPI_T *) SPI2_BASE)

#define I2C0                ((I2C_T *) I2C0_BASE)                       /*!< I2C0 Configuration Struct                        */
#define I2C1                ((I2C_T *) I2C1_BASE)                       /*!< I2C1 Configuration Struct                        */

#define I2S                 ((I2S_T *) I2S_BASE)

#define ADC                 ((ADC_T *) ADC_BASE)

#define CLK              ((CLK_T *) CLK_BASE)                  /*!< System Clock Controller Configuration Struct     */

#define SYS                 ((GCR_T *) GCR_BASE)                        /*!< System Global Controller Configuration Struct    */

#define SYSINT              ((GCR_INT_T *) INT_BASE)                    /*!< Interrupt Source Controller Configuration Struct */

#define FMC                 ((FMC_T *) FMC_BASE)

#define PS2                 ((PS2_T *) PS2_BASE)						/*!< PS/2 Configuration Struct                        */

#define USBD                ((USBD_T *) USBD_BASE)

#define PDMA0               ((PDMA_T *) PDMA0_BASE)                     /*!< PDMA0 Configuration Struct                       */
#define PDMA1               ((PDMA_T *) PDMA1_BASE)                     /*!< PDMA1 Configuration Struct                       */
#define PDMA2               ((PDMA_T *) PDMA2_BASE)                     /*!< PDMA2 Configuration Struct                       */
#define PDMA3               ((PDMA_T *) PDMA3_BASE)                     /*!< PDMA3 Configuration Struct                       */
#define PDMA4               ((PDMA_T *) PDMA4_BASE)                     /*!< PDMA4 Configuration Struct                       */
#define PDMA5               ((PDMA_T *) PDMA5_BASE)                     /*!< PDMA5 Configuration Struct                       */

#define PDMA_GCR            ((PDMA_GCR_T *) PDMA_GCR_BASE)              /*!< PDMA Global Configuration Struct                 */

#define CRC                 ((CRC_T *) CRC_BASE)                        /*!< CRC Configuration Struct                         */

#define PWMA                ((PWM_T *) PWMA_BASE)                       /*!< PWMA Configuration Struct                        */

/*@}*/ /* end of group NUC123_PERIPHERAL_DECLARATION */
/*@}*/ /* end of group NUC123_SERIES_REG */


/** @addtogroup NUC123_REG_FUNC NUC123_REG_FUNC
  The Declaration of NUC123 Series register function
  @{
 */
#define UNLOCKREG(x)        *((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x59;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x16;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x88
#define LOCKREG(x)          *((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x00;     

#define REGCOPY(dest, src)  *((uint32_t *)&(dest)) = *((uint32_t *)&(src))
#define CLEAR(dest)         *((uint32_t *)&(dest)) = 0
/*@}*/ /* end of group NUC123_REG_FUNC */

//=============================================================================
/** @addtogroup NUC123_TYPE	NUC123 TYPE
  The Declaration of NUC123 Series variable type defination
  @{
 */
typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
#define M8(adr)  (*((vu8  *) (adr)))
#define M16(adr) (*((vu16 *) (adr)))
#define M32(adr) (*((vu32 *) (adr)))

#define outpw(port,value)   *((volatile unsigned int *)(port))=(value)
#define inpw(port)          (*((volatile unsigned int *)(port)))
#define outpb(port,value)   *((volatile unsigned char *)(port))=(value)
#define inpb(port)          (*((volatile unsigned char *)(port)))
#define outps(port,value)   *((volatile unsigned short *)(port))=(value)
#define inps(port)          (*((volatile unsigned short *)(port)))

#define outp32(port,value)  *((volatile unsigned int *)(port))=(value)
#define inp32(port)         (*((volatile unsigned int *)(port)))
#define outp8(port,value)   *((volatile unsigned char *)(port))=(value)
#define inp8(port)          (*((volatile unsigned char *)(port)))
#define outp16(port,value)  *((volatile unsigned short *)(port))=(value)
#define inp16(port)         (*((volatile unsigned short *)(port)))


//#define E_SUCCESS   0
#ifndef NULL
#define NULL        0
#endif

#define BOOL        uint8_t
#define TRUE        1
#define FALSE       0

#define ENABLE     1
#define DISABLE    0
/*@}*/ /* end of group NUC123_TYPE */

/* Define one bit mask */
/** @addtogroup NUC123_BITMASK	NUC123 BITMASK
  The Declaration of NUC123 Series Bit mask
  @{
 */
#define BIT0    0x00000001
#define BIT1    0x00000002
#define BIT2    0x00000004
#define BIT3    0x00000008
#define BIT4    0x00000010
#define BIT5    0x00000020
#define BIT6    0x00000040
#define BIT7    0x00000080
#define BIT8    0x00000100
#define BIT9    0x00000200
#define BIT10   0x00000400
#define BIT11   0x00000800
#define BIT12   0x00001000
#define BIT13   0x00002000
#define BIT14   0x00004000
#define BIT15   0x00008000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

/* Byte Mask Definitions */
#define BYTE0_Msk               (0x000000FF)
#define BYTE1_Msk               (0x0000FF00)
#define BYTE2_Msk               (0x00FF0000)
#define BYTE3_Msk               (0xFF000000)

#define _GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define _GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define _GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define _GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */
/*@}*/ /* end of group NUC123_BITMASK */

/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/ 


#endif
                                                                                                 
