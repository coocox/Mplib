/**************************************************************************//**
 * @file     NUC400Series.h
 * @version  V1.00
 * $Revision: 45 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series peripheral access layer header file.
 *           This file contains all the peripheral register's definitions,
 *           bits definitions and memory mapping for NuMicro NUC400 series MCU.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
/**
   \mainpage NuMicro NUC400 Series MCU Driver Reference Guide
   *
   * <b>Introduction</b>
   *
   * This user manual describes the usage of NUC400 Series MCU device driver
   *
   * <b>Disclaimer</b>
   *
   * The Software is furnished "AS IS", without warranty as to performance or results, and
   * the entire risk as to performance or results is assumed by YOU. Nuvoton disclaims all
   * warranties, express, implied or otherwise, with regard to the Software, its use, or
   * operation, including without limitation any and all warranties of merchantability, fitness
   * for a particular purpose, and non-infringement of intellectual property rights.
   *
   * <b>Important Notice</b>
   *
   * Nuvoton Products are neither intended nor warranted for usage in systems or equipment,
   * any malfunction or failure of which may cause loss of human life, bodily injury or severe
   * property damage. Such applications are deemed, "Insecure Usage".
   *
   * Insecure usage includes, but is not limited to: equipment for surgical implementation,
   * atomic energy control instruments, airplane or spaceship instruments, the control or
   * operation of dynamic, brake or safety systems designed for vehicular use, traffic signal
   * instruments, all types of safety devices, and other applications intended to support or
   * sustain life.
   *
   * All Insecure Usage shall be made at customer's risk, and in the event that third parties
   * lay claims to Nuvoton as a result of customer's Insecure Usage, customer shall indemnify
   * the damages and liabilities thus incurred by Nuvoton.
   *
   * Please note that all data and specifications are subject to change without notice. All the
   * trademarks of products and companies mentioned in this datasheet belong to their respective
   * owners.
   *
   * <b>Copyright Notice</b>
   *
   * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
   */
/**
  * \page pg1 NuMicro NUC400 BSP Directory Structure
  * The NUC400 board supporting package (BSP) contains CMSIS 3.01 under the "Library\CMSIS" directory,
  * Peripheral standard driver under the "Library\StdDriver" directory, USB host library under the
  * "Library\UsbHostLib" directory, and smartcard 7816-3 library under the "Library\SmartcardLib" directory.
  *
  * There are also sample codes which demonstrate the usage of standard drivers, lwIP network protocol
  * stack, uC/OS-II, uC/OS-III, and FreeRTOS under the "SampleCode" directory.
  *
  * The "ThirdParty" directory contains third party source code, including fatfs, lwIP, and FreeRTOS.
  * Due to license issue, uC/OS-II and uC/OS-III source code are not included and the directory is empty.
  * The source code could be downloaded from Micrium official website.
  *
  * The BSP directory structure is shown in following figures.
  *
  * \image html dir.jpg "BSP Directory Structure"
  * \image latex dir.jpg "BSP Directory Structure"
  * <BR>
  * \image html samplecode.jpg "BSP Sample Code Directory Structure"
  * \image latex samplecode.jpg "BSP Sample Code Directory Structure"
  * <BR>
  * \image html thirdparty.jpg "BSP Third Party Directory Structure"
  * \image latex thirdparty.jpg "BSP Third Party Directory Structure"
  *
  * \page pg2 Revision History
  *
  * <b>Revision 1.00.000</b>
  * \li Added CAN, SD, SC, SCUART driver and samples.
  * \li Added smartcard 7816-3 library.
  * \li Added NUC472 Tiny Board sample.
  * \li Renamed I2C_GetClockBusFreq() to I2C_GetBusClockFreq().
  * \li Renamed I2C_SetClockBusFreq() to I2C_SetBusClockFreq().
  * \li Renamed I2C_SetSlaveMask() to I2C_SetSlaveAddrMask().
  * \li Minor bug fix.
  *
  * <b>Revision 0.10.000</b>
  * \li Added I2S, PDMA driver.
  * \li Added Learning Board and Standard Driver samples.
  * \li Added FreeRTOS lwIP sample.
  *
  * <b>Revision 0.09.000</b>
  * \li Added CAP, EBI, I2C, PWM, SPI, USBD, USBH drivers and samples.
  * \li Added uCOS-II and uCOS-III samples.
  * \li Added FreeRTOS source code and sample.
  *
  * <b>Revision 0.08.000</b>
  * \li Preliminary release.
*/
#ifndef __NUC400SERIES_H__
#define __NUC400SERIES_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup NUC400_Definitions NUC400 Definitions
  This file defines all structures and symbols for NUC400:
    - registers and bit fields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup NUC400_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M4 Processor and Core Peripherals
  @{
*/

/**
 * @details  Interrupt Number Definition.
 */
typedef enum IRQn {
    /******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
    MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt                   */
    BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt                           */
    UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt                         */
    SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
    DebugMonitor_IRQn             = -4,       /*!< 12 Debug Monitor Interrupt                       */
    PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
    SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

    /******  NUC400 Specific Interrupt Numbers ********************************************************/

    BOD_IRQn                      = 0,        /*!< Brown Out detection Interrupt                    */
    IRC_IRQn                      = 1,        /*!< Internal RC Interrupt                            */
    PWRWU_IRQn                    = 2,        /*!< Power Down Wake Up Interrupt                     */
    SRAMF_IRQn                    = 3,        /*!< SRAM Parity Check Failed Interrupt               */
    CLKF_IRQn                     = 4,        /*!< Clock Detection Failed Interrupt                 */
    RTC_IRQn                      = 6,        /*!< Real Time Clock Interrupt                        */
    TAMPER_IRQn                   = 7,        /*!< Tamper detection Interrupt                       */
    EINT0_IRQn                    = 8,        /*!< External Input 0 Interrupt                       */
    EINT1_IRQn                    = 9,        /*!< External Input 1 Interrupt                       */
    EINT2_IRQn                    = 10,       /*!< External Input 2 Interrupt                       */
    EINT3_IRQn                    = 11,       /*!< External Input 3 Interrupt                       */
    EINT4_IRQn                    = 12,       /*!< External Input 4 Interrupt                       */
    EINT5_IRQn                    = 13,       /*!< External Input 5 Interrupt                       */
    EINT6_IRQn                    = 14,       /*!< External Input 6 Interrupt                       */
    EINT7_IRQn                    = 15,       /*!< External Input 7 Interrupt                       */
    GPA_IRQn                      = 16,       /*!< GPIO Port A Interrupt                            */
    GPB_IRQn                      = 17,       /*!< GPIO Port B Interrupt                            */
    GPC_IRQn                      = 18,       /*!< GPIO Port C Interrupt                            */
    GPD_IRQn                      = 19,       /*!< GPIO Port D Interrupt                            */
    GPE_IRQn                      = 20,       /*!< GPIO Port E Interrupt                            */
    GPF_IRQn                      = 21,       /*!< GPIO Port F Interrupt                            */
    GPG_IRQn                      = 22,       /*!< GPIO Port G Interrupt                            */
    GPH_IRQn                      = 23,       /*!< GPIO Port H Interrupt                            */
    GPI_IRQn                      = 24,       /*!< GPIO Port I Interrupt                            */
    TMR0_IRQn                     = 32,       /*!< Timer 0 Interrupt                                */
    TMR1_IRQn                     = 33,       /*!< Timer 1 Interrupt                                */
    TMR2_IRQn                     = 34,       /*!< Timer 2 Interrupt                                */
    TMR3_IRQn                     = 35,       /*!< Timer 3 Interrupt                                */
    PDMA_IRQn                     = 40,       /*!< Peripheral DMA Interrupt                         */
    ADC_IRQn                      = 42,       /*!< ADC Interrupt                                    */
    WDT_IRQn                      = 46,       /*!< Watch Dog Timer Interrupt                        */
    WWDT_IRQn                     = 47,       /*!< Window Watch Dog Timer Interrupt                 */
    EADC0_IRQn                    = 48,       /*!< Enhanced ADC 0 Interrupt                         */
    EADC1_IRQn                    = 49,       /*!< Enhanced ADC 1 Interrupt                         */
    EADC2_IRQn                    = 50,       /*!< Enhanced ADC 2 Interrupt                         */
    EADC3_IRQn                    = 51,       /*!< Enhanced ADC 3 Interrupt                         */
    ACMP_IRQn                     = 56,       /*!< Analog Comparator Interrupt                      */
    OPA0_IRQn                     = 60,       /*!< OPA 0 Interrupt                                  */
    OPA1_IRQn                     = 61,       /*!< OPA 1 Interrupt                                  */
    ICAP0_IRQn                    = 62,       /*!< Input Capture 0 Interrupt                        */
    ICAP1_IRQn                    = 63,       /*!< Input Capture 1 Interrupt                        */
    PWM0CH0_IRQn                  = 64,       /*!< PWM 0 Channel 0 Interrupt                        */
    PWM0CH1_IRQn                  = 65,       /*!< PWM 0 Channel 1 Interrupt                        */
    PWM0CH2_IRQn                  = 66,       /*!< PWM 0 Channel 2 Interrupt                        */
    PWM0CH3_IRQn                  = 67,       /*!< PWM 0 Channel 3 Interrupt                        */
    PWM0CH4_IRQn                  = 68,       /*!< PWM 0 Channel 4 Interrupt                        */
    PWM0CH5_IRQn                  = 69,       /*!< PWM 0 Channel 5 Interrupt                        */
    PWM0_BRK_IRQn                 = 70,       /*!< PWM 0 Break Interrupt                            */
    QEI0_IRQn                     = 71,       /*!< QEI 0  Interrupt                                 */
    PWM1CH0_IRQn                  = 72,       /*!< PWM 1 Channel 0 Interrupt                        */
    PWM1CH1_IRQn                  = 73,       /*!< PWM 1 Channel 1 Interrupt                        */
    PWM1CH2_IRQn                  = 74,       /*!< PWM 1 Channel 2 Interrupt                        */
    PWM1CH3_IRQn                  = 75,       /*!< PWM 1 Channel 3 Interrupt                        */
    PWM1CHCH4_IRQn                = 76,       /*!< PWM 1 Channel 4 Interrupt                        */
    PWM1CH5_IRQn                  = 77,       /*!< PWM 1 Channel 5 Interrupt                        */
    PWM1_BRK_IRQn                 = 78,       /*!< PWM 1 Break Interrupt                            */
    QEI1_IRQn                     = 79,       /*!< QEI 1  Interrupt                                 */
    EPWM0_IRQn                    = 80,       /*!< Enhanced PWM 0 Interrupt                         */
    EPWM0BRK_IRQn                 = 81,       /*!< Enhanced PWM 0 Break Interrupt                   */
    EPWM1_IRQn                    = 82,       /*!< Enhanced PWM 1 Interrupt                         */
    EPWM1BRK_IRQn                 = 83,       /*!< Enhanced PWM 1 Break Interrupt                   */
    USBD_IRQn                     = 88,       /*!< USB FS Device Interrupt                          */
    USBH_IRQn                     = 89,       /*!< USB FS Host Interrupt                            */
    USB_OTG_IRQn                  = 90,       /*!< USB OTG Interrupt                                */
    EMAC_TX_IRQn                  = 92,       /*!< Ethernet MAC TX Interrupt                        */
    EMAC_RX_IRQn                  = 93,       /*!< Ethernet MAC RX Interrupt                        */
    SPI0_IRQn                     = 96,       /*!< SPI 0 Interrupt                                  */
    SPI1_IRQn                     = 97,       /*!< SPI 1 Interrupt                                  */
    SPI2_IRQn                     = 98,       /*!< SPI 2 Interrupt                                  */
    SPI3_IRQn                     = 99,       /*!< SPI 3 Interrupt                                  */
    UART0_IRQn                    = 104,      /*!< UART 0 Interrupt                                 */
    UART1_IRQn                    = 105,      /*!< UART 1 Interrupt                                 */
    UART2_IRQn                    = 106,      /*!< UART 2 Interrupt                                 */
    UART3_IRQn                    = 107,      /*!< UART 3 Interrupt                                 */
    UART4_IRQn                    = 108,      /*!< UART 4 Interrupt                                 */
    UART5_IRQn                    = 109,      /*!< UART 5 Interrupt                                 */
    I2C0_IRQn                     = 112,      /*!< I2C 0 Interrupt                                  */
    I2C1_IRQn                     = 113,      /*!< I2C 1 Interrupt                                  */
    I2C2_IRQn                     = 114,      /*!< I2C 2 Interrupt                                  */
    I2C3_IRQn                     = 115,      /*!< I2C 3 Interrupt                                  */
    I2C4_IRQn                     = 116,      /*!< I2C 4 Interrupt                                  */
    SC0_IRQn                      = 120,      /*!< Smart Card 0 Interrupt                           */
    SC1_IRQn                      = 121,      /*!< Smart Card 1 Interrupt                           */
    SC2_IRQn                      = 122,      /*!< Smart Card 2 Interrupt                           */
    SC3_IRQn                      = 123,      /*!< Smart Card 3 Interrupt                           */
    SC4_IRQn                      = 124,      /*!< Smart Card 4 Interrupt                           */
    SC5_IRQn                      = 125,      /*!< Smart Card 5 Interrupt                           */
    CAN0_IRQn                     = 128,      /*!< CAN 0 Interrupt                                  */
    CAN1_IRQn                     = 129,      /*!< CAN 1 Interrupt                                  */
    I2S0_IRQn                     = 132,      /*!< I2S 0 Interrupt                                  */
    I2S1_IRQn                     = 133,      /*!< I2S 1 Interrupt                                  */
    SD_IRQn                       = 136,      /*!< SD Host Interrupt                                */
    PS2D_IRQn                     = 138,      /*!< PS/2 device Interrupt                            */
    CAP_IRQn                      = 139,      /*!< VCAP Interrupt                                   */
    CRYPTO_IRQn                   = 140,      /*!< CRYPTO Interrupt                                 */
    CRC_IRQn                      = 141,      /*!< CRC Interrupt                                    */
}
IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M# Processor and Core Peripherals */
#define __CM4_REV                 0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          4         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             1         /*!< MPU present or not                               */
#define __FPU_PRESENT             1         /*!< FPU present or not                               */

/*@}*/ /* end of group NUC400_CMSIS */


#include "core_cm4.h"                       /* Cortex-M4 processor and core peripherals           */
#include "system_NUC400Series.h"            /* NUC400 System include file                         */
#include <stdint.h>

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup NUC400_Peripherals NUC400 Peripherals
  NUC400 Device Specific Peripheral registers structures
  @{
*/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


/*------------- Global Control Register (GCR) -----------------------------*/
/** @addtogroup NUC400_GCR NUC400 Global Control Register (GCR)
  @{
*/
/**
  * @brief GCR register map
  */
typedef struct {
    __I  uint32_t PDID;                       /*!< Offset: 0x0000   Part Device Identification Number Register         */
    __IO uint32_t RSTSRC;                     /*!< Offset: 0x0004   System Reset Source Register                       */
    __IO uint32_t IPRSTC1;                    /*!< Offset: 0x0008   IP Reset Control Register 1                        */
    __IO uint32_t IPRSTC2;                    /*!< Offset: 0x000C   IP Reset Control Register 2                        */
    __IO uint32_t IPRSTC3;                    /*!< Offset: 0x0010   IP Reset Control Register 3                        */
    __IO uint32_t ITESTCR;                    /*!< Offset: 0x0014   I/O self test mode for PWM and QEI test            */
    __IO uint32_t BODCR;                      /*!< Offset: 0x0018   Brown-Out Detector Control Register                */
    __IO uint32_t TEMPCR;                     /*!< Offset: 0x001C   Temperature Sensor Control Register                */
    __IO uint32_t VCID;                       /*!< Offset: 0x0020   Hardware version control Register                  */
    __IO uint32_t PORCR;                      /*!< Offset: 0x0024   Power-On-Reset Controller Register                 */
    __IO uint32_t VREFCR;                     /*!< Offset: 0x0028   ADC VREF control Register                          */
    __IO uint32_t USBPHYCR;                   /*!< Offset: 0x002C   USB PHY Control Register                           */
    __IO uint32_t GPA_MFPL;                   /*!< Offset: 0x0030   GPIOA low byte multiple function control Register  */
    __IO uint32_t GPA_MFPH;                   /*!< Offset: 0x0034   GPIOA high byte multiple function control Register */
    __IO uint32_t GPB_MFPL;                   /*!< Offset: 0x0038   GPIOB low byte multiple function control Register  */
    __IO uint32_t GPB_MFPH;                   /*!< Offset: 0x003C   GPIOB high byte multiple function control Register */
    __IO uint32_t GPC_MFPL;                   /*!< Offset: 0x0040   GPIOC low byte multiple function control Register  */
    __IO uint32_t GPC_MFPH;                   /*!< Offset: 0x0044   GPIOC high byte multiple function control Register */
    __IO uint32_t GPD_MFPL;                   /*!< Offset: 0x0048   GPIOD low byte multiple function control Register  */
    __IO uint32_t GPD_MFPH;                   /*!< Offset: 0x004C   GPIOD high byte multiple function control Register */
    __IO uint32_t GPE_MFPL;                   /*!< Offset: 0x0050   GPIOE low byte multiple function control Register  */
    __IO uint32_t GPE_MFPH;                   /*!< Offset: 0x0054   GPIOE high byte multiple function control Register */
    __IO uint32_t GPF_MFPL;                   /*!< Offset: 0x0058   GPIOF low byte multiple function control Register  */
    __IO uint32_t GPF_MFPH;                   /*!< Offset: 0x005C   GPIOF high byte multiple function control Register */
    __IO uint32_t GPG_MFPL;                   /*!< Offset: 0x0060   GPIOG low byte multiple function control Register  */
    __IO uint32_t GPG_MFPH;                   /*!< Offset: 0x0064   GPIOG high byte multiple function control Register */
    __IO uint32_t GPH_MFPL;                   /*!< Offset: 0x0068   GPIOH low byte multiple function control Register  */
    __IO uint32_t GPH_MFPH;                   /*!< Offset: 0x006C   GPIOH high byte multiple function control Register */
    __IO uint32_t GPI_MFPL;                   /*!< Offset: 0x0070   GPIOI low byte multiple function control Register  */
    __IO uint32_t GPI_MFPH;                   /*!< Offset: 0x0074   GPIOI high byte multiple function control Register */
    uint32_t RESERVED3[18];              /*!< Offset: 0x0078 ~ 0x00BC  Reserved                                   */
    __IO uint32_t SRAMF_INTCR;                /*!< Offset: 0x00C0   SRAM interrupt enable control  register            */
    __IO uint32_t SRAMF;                      /*!< Offset: 0x00C4   SRAM parity check error Flag                       */
    __IO uint32_t SRAMF_ADDR;                 /*!< Offset: 0x00C8   SRAM parity check error first address1             */
    __IO uint32_t SRAMF_ADDR2;                /*!< Offset: 0x00CC   SRAM parity check error first address2             */
    uint32_t RESERVED4[8];               /*!< Offset: 0x00D0 ~ 0x00EC  Reserved                                   */
    __IO uint32_t IRCTRIMCTL;                 /*!< Offset: 0x00F0   IRC Trim Control Register                          */
    __IO uint32_t IRCTRIMIEM;                 /*!< Offset: 0x00F4   IRC Trim Interrupt Enable Register                 */
    __IO uint32_t IRCTRIMINT;                 /*!< Offset: 0x00F8   IRC Trim Interrupt Status Register                 */
    uint32_t RESERVED6;                  /*!< Offset: 0x00FC   Reserved                                           */
    __IO uint32_t REGWRPROT;                  /*!< Offset: 0x0100   Register Write-Protection Control Register         */
} GCR_T;

/* SYS PDID Bit Field Definitions */
#define SYS_PDID_PDID_Pos    0                                     /*!< SYS PDID: PDID Position */
#define SYS_PDID_PDID_Msk    (1ul<<SYS_PDID_PDID_Pos)              /*!< SYS PDID: PDID Mask */
/* SYS RSTSRC Bit Field Definitions */
#define SYS_RSTSRC_RSTS_POR_Pos        0                                          /*!< SYS RSTSRC: RSTS_POR Position */
#define SYS_RSTSRC_RSTS_POR_Msk        (1ul<<SYS_RSTSRC_RSTS_POR_Pos)             /*!< SYS RSTSRC: RSTS_POR Mask */

#define SYS_RSTSRC_RSTS_RESET_Pos    1                                             /*!< SYS RSTSRC: RSTS_RESET Position */
#define SYS_RSTSRC_RSTS_RESET_Msk    (1ul<<SYS_RSTSRC_RSTS_RESET_Pos)              /*!< SYS RSTSRC: RSTS_RESET Mask */

#define SYS_RSTSRC_RSTS_WDT_Pos        2                                          /*!< SYS RSTSRC: RSTS_WDT Position */
#define SYS_RSTSRC_RSTS_WDT_Msk        (1ul<<SYS_RSTSRC_RSTS_WDT_Pos)             /*!< SYS RSTSRC: RSTS_WDT Mask */

#define SYS_RSTSRC_RSTS_LVR_Pos        3                                          /*!< SYS RSTSRC: RSTS_LVR Position */
#define SYS_RSTSRC_RSTS_LVR_Msk        (1ul<<SYS_RSTSRC_RSTS_LVR_Pos)             /*!< SYS RSTSRC: RSTS_LVR Mask */

#define SYS_RSTSRC_RSTS_BOD_Pos        4                                          /*!< SYS RSTSRC: RSTS_BOD Position */
#define SYS_RSTSRC_RSTS_BOD_Msk        (1ul<<SYS_RSTSRC_RSTS_BOD_Pos)             /*!< SYS RSTSRC: RSTS_BOD Mask */

#define SYS_RSTSRC_RSTS_SYS_Pos        5                                          /*!< SYS RSTSRC: RSTS_SYS Position */
#define SYS_RSTSRC_RSTS_SYS_Msk        (1ul<<SYS_RSTSRC_RSTS_SYS_Pos)             /*!< SYS RSTSRC: RSTS_SYS Mask */

#define SYS_RSTSRC_RSTS_CPU_Pos        7                                          /*!< SYS RSTSRC: RSTS_CPU Position */
#define SYS_RSTSRC_RSTS_CPU_Msk        (1ul<<SYS_RSTSRC_RSTS_CPU_Pos)             /*!< SYS RSTSRC: RSTS_CPU Mask */

#define SYS_RSTSRC_CPUINST_Pos        8                                          /*!< SYS RSTSRC: CPUINST Position */
#define SYS_RSTSRC_CPUINST_Msk        (1ul<<SYS_RSTSRC_CPUINST_Pos)              /*!< SYS RSTSRC: CPUINST Mask */


/* SYS IPRSTC1 Bit Field Definitions */
#define SYS_IPRSTC1_CHIP_RST_Pos        0                                          /*!< SYS IPRSTC1: CHIP_RST Position */
#define SYS_IPRSTC1_CHIP_RST_Msk        (1ul<<SYS_IPRSTC1_CHIP_RST_Pos)            /*!< SYS IPRSTC1: CHIP_RST Mask */

#define SYS_IPRSTC1_CPU_RST_Pos            1                                          /*!< SYS IPRSTC1: CPU_RST Position */
#define SYS_IPRSTC1_CPU_RST_Msk            (1ul<<SYS_IPRSTC1_CPU_RST_Pos)             /*!< SYS IPRSTC1: CPU_RST Mask */

#define SYS_IPRSTC1_PDMA_RST_Pos        2                                          /*!< SYS IPRSTC1: PDMA Position */
#define SYS_IPRSTC1_PDMA_RST_Msk        (1ul<<SYS_IPRSTC1_PDMA_RST_Pos)              /*!< SYS IPRSTC1: PDMA Mask */

#define SYS_IPRSTC1_EBI_RST_Pos            3                                          /*!< SYS IPRSTC1: EBI_RST Position */
#define SYS_IPRSTC1_EBI_RST_Msk            (1ul<<SYS_IPRSTC1_EBI_RST_Pos)              /*!< SYS IPRSTC1: EBI_RST Mask */

#define SYS_IPRSTC1_UHC_RST_Pos            4                                              /*!< SYS IPRSTC1: UHC_RST Position */
#define SYS_IPRSTC1_UHC_RST_Msk            (1ul<<SYS_IPRSTC1_UHC_RST_Pos)                 /*!< SYS IPRSTC1: UHC_RST Mask */

#define SYS_IPRSTC1_EMAC_RST_Pos            5                                          /*!< SYS IPRSTC1: EMAC_RST Position */
#define SYS_IPRSTC1_EMAC_RST_Msk            (1ul<<SYS_IPRSTC1_EMAC_RST_Pos)            /*!< SYS IPRSTC1: EMAC_RST Mask */

#define SYS_IPRSTC1_SD_RST_Pos        6                                          /*!< SYS IPRSTC1: SD_RST Position */
#define SYS_IPRSTC1_SD_RST_Msk        (1ul<<SYS_IPRSTC1_SD_RST_Pos)              /*!< SYS IPRSTC1: SD_RST Mask */

#define SYS_IPRSTC1_CRC_RST_Pos            7                                          /*!< SYS IPRSTC1: CRC_RST Position */
#define SYS_IPRSTC1_CRC_RST_Msk            (1ul<<SYS_IPRSTC1_CRC_RST_Pos)             /*!< SYS IPRSTC1: CRC_RST Mask */

#define SYS_IPRSTC1_CAP_RST_Pos        8                                          /*!< SYS IPRSTC1: CAP_RST Position */
#define SYS_IPRSTC1_CAP_RST_Msk        (1ul<<SYS_IPRSTC1_CAP_RST_Pos)             /*!< SYS IPRSTC1: CAP_RST Mask */

#define SYS_IPRSTC1_SPACC_RST_Pos        12                                          /*!< SYS IPRSTC1: SPACC_RST Position */
#define SYS_IPRSTC1_SPACC_RST_Msk        (1ul<<SYS_IPRSTC1_SPACC_RST_Pos)            /*!< SYS IPRSTC1: SPACC_RST Mask */

/* SYS IPRSTC2 Bit Field Definitions */
#define SYS_IPRSTC2_GPIO_RST_Pos        1                                          /*!< SYS IPRSTC2: GPIO_RST Position */
#define SYS_IPRSTC2_GPIO_RST_Msk        (1ul<<SYS_IPRSTC2_GPIO_RST_Pos)              /*!< SYS IPRSTC2: GPIO_RST Mask */

#define SYS_IPRSTC2_TMR0_RST_Pos        2                                          /*!< SYS IPRSTC2: TMR0_RST Position */
#define SYS_IPRSTC2_TMR0_RST_Msk        (1ul<<SYS_IPRSTC2_TMR0_RST_Pos)              /*!< SYS IPRSTC2: TMR0_RST Mask */

#define SYS_IPRSTC2_TMR1_RST_Pos        3                                          /*!< SYS IPRSTC2: TMR1_RST Position */
#define SYS_IPRSTC2_TMR1_RST_Msk        (1ul<<SYS_IPRSTC2_TMR1_RST_Pos)              /*!< SYS IPRSTC2: TMR1_RST Mask */

#define SYS_IPRSTC2_TMR2_RST_Pos        4                                          /*!< SYS IPRSTC2: TMR2_RST Position */
#define SYS_IPRSTC2_TMR2_RST_Msk        (1ul<<SYS_IPRSTC2_TMR2_RST_Pos)              /*!< SYS IPRSTC2: TMR2_RST Mask */

#define SYS_IPRSTC2_TMR3_RST_Pos        5                                          /*!< SYS IPRSTC2: TMR3_RST Position */
#define SYS_IPRSTC2_TMR3_RST_Msk        (1ul<<SYS_IPRSTC2_TMR3_RST_Pos)              /*!< SYS IPRSTC2: TMR3_RST Mask */

#define SYS_IPRSTC2_ACMP_RST_Pos        7                                          /*!< SYS IPRSTC2: ACMP_RST Position */
#define SYS_IPRSTC2_ACMP_RST_Msk        (1ul<<SYS_IPRSTC2_ACMP_RST_Pos)              /*!< SYS IPRSTC2: ACMP_RST Mask */

#define SYS_IPRSTC2_I2C0_RST_Pos        8                                          /*!< SYS IPRSTC2: I2C0_RST Position */
#define SYS_IPRSTC2_I2C0_RST_Msk        (1ul<<SYS_IPRSTC2_I2C0_RST_Pos)              /*!< SYS IPRSTC2: I2C0_RST Mask */

#define SYS_IPRSTC2_I2C1_RST_Pos        9                                          /*!< SYS IPRSTC2: I2C1_RST Position */
#define SYS_IPRSTC2_I2C1_RST_Msk        (1ul<<SYS_IPRSTC2_I2C1_RST_Pos)              /*!< SYS IPRSTC2: I2C1_RST Mask */

#define SYS_IPRSTC2_I2C2_RST_Pos        10                                          /*!< SYS IPRSTC2: I2C2_RST Position */
#define SYS_IPRSTC2_I2C2_RST_Msk        (1ul<<SYS_IPRSTC2_I2C2_RST_Pos)              /*!< SYS IPRSTC2: I2C2_RST Mask */

#define SYS_IPRSTC2_I2C3_RST_Pos        11                                          /*!< SYS IPRSTC2: I2C3_RST Position */
#define SYS_IPRSTC2_I2C3_RST_Msk        (1ul<<SYS_IPRSTC2_I2C3_RST_Pos)              /*!< SYS IPRSTC2: I2C3_RST Mask */

#define SYS_IPRSTC2_SPI0_RST_Pos        12                                          /*!< SYS IPRSTC2: SPI0_RST Position */
#define SYS_IPRSTC2_SPI0_RST_Msk        (1ul<<SYS_IPRSTC2_SPI0_RST_Pos)              /*!< SYS IPRSTC2: SPI0_RST Mask */

#define SYS_IPRSTC2_SPI1_RST_Pos        13                                          /*!< SYS IPRSTC2: SPI1_RST Position */
#define SYS_IPRSTC2_SPI1_RST_Msk        (1ul<<SYS_IPRSTC2_SPI1_RST_Pos)              /*!< SYS IPRSTC2: SPI1_RST Mask */

#define SYS_IPRSTC2_SPI2_RST_Pos        14                                          /*!< SYS IPRSTC2: SPI2_RST Position */
#define SYS_IPRSTC2_SPI2_RST_Msk        (1ul<<SYS_IPRSTC2_SPI2_RST_Pos)              /*!< SYS IPRSTC2: SPI2_RST Mask */

#define SYS_IPRSTC2_SPI3_RST_Pos        15                                          /*!< SYS IPRSTC2: SPI3_RST Position */
#define SYS_IPRSTC2_SPI3_RST_Msk        (1ul<<SYS_IPRSTC2_SPI3_RST_Pos)              /*!< SYS IPRSTC2: SPI3_RST Mask */

#define SYS_IPRSTC2_UART0_RST_Pos        16                                          /*!< SYS IPRSTC2: UART0_RST Position */
#define SYS_IPRSTC2_UART0_RST_Msk        (1ul<<SYS_IPRSTC2_UART0_RST_Pos)              /*!< SYS IPRSTC2: UART0_RST Mask */

#define SYS_IPRSTC2_UART1_RST_Pos        17                                          /*!< SYS IPRSTC2: UART1_RST Position */
#define SYS_IPRSTC2_UART1_RST_Msk        (1ul<<SYS_IPRSTC2_UART1_RST_Pos)              /*!< SYS IPRSTC2: UART1_RST Mask */

#define SYS_IPRSTC2_UART2_RST_Pos        18                                          /*!< SYS IPRSTC2: UART2_RST Position */
#define SYS_IPRSTC2_UART2_RST_Msk        (1ul<<SYS_IPRSTC2_UART2_RST_Pos)              /*!< SYS IPRSTC2: UART2_RST Mask */

#define SYS_IPRSTC2_UART3_RST_Pos        19                                          /*!< SYS IPRSTC2: UART3_RST Position */
#define SYS_IPRSTC2_UART3_RST_Msk        (1ul<<SYS_IPRSTC2_GUART3_RST_Pos)              /*!< SYS IPRSTC2: UART3_RST Mask */

#define SYS_IPRSTC2_UART4_RST_Pos        20                                          /*!< SYS IPRSTC2: UART4_RST Position */
#define SYS_IPRSTC2_UART4_RST_Msk        (1ul<<SYS_IPRSTC2_UART4_RST_Pos)              /*!< SYS IPRSTC2: UART4_RST Mask */

#define SYS_IPRSTC2_UART5_RST_Pos        21                                          /*!< SYS IPRSTC2: UART5_RST Position */
#define SYS_IPRSTC2_UART5_RST_Msk        (1ul<<SYS_IPRSTC2_UART5_RST_Pos)              /*!< SYS IPRSTC2: UART5_RST Mask */

#define SYS_IPRSTC2_CAN0_RST_Pos        24                                          /*!< SYS IPRSTC2: CAN0_RST Position */
#define SYS_IPRSTC2_CAN0_RST_Msk        (1ul<<SYS_IPRSTC2_CAN0_RST_Pos)              /*!< SYS IPRSTC2: CAN0_RST Mask */

#define SYS_IPRSTC2_CAN1_RST_Pos        25                                          /*!< SYS IPRSTC2: CAN1_RST Position */
#define SYS_IPRSTC2_CAN1_RST_Msk        (1ul<<SYS_IPRSTC2_CAN1_RST_Pos)              /*!< SYS IPRSTC2: CAN1_RST Mask */

#define SYS_IPRSTC2_OTG_RST_Pos            26                                          /*!< SYS IPRSTC2: OTG_RST Position */
#define SYS_IPRSTC2_OTG_RST_Msk            (1ul<<SYS_IPRSTC2_OTG_RST_Pos)              /*!< SYS IPRSTC2: OTG_RST Mask */

#define SYS_IPRSTC2_USBD_RST_Pos        27                                          /*!< SYS IPRSTC2: USBD_RST Position */
#define SYS_IPRSTC2_USBD_RST_Msk        (1ul<<SYS_IPRSTC2_USBD_RST_Pos)              /*!< SYS IPRSTC2: USBD_RST Mask */

#define SYS_IPRSTC2_ADC_RST_Pos            28                                          /*!< SYS IPRSTC2: ADC_RST Position */
#define SYS_IPRSTC2_ADC_RST_Msk            (1ul<<SYS_IPRSTC2_ADC_RST_Pos)              /*!< SYS IPRSTC2: ADC_RST Mask */

#define SYS_IPRSTC2_I2S_RST_Pos            29                                          /*!< SYS IPRSTC2: I2S_RST Position */
#define SYS_IPRSTC2_I2S_RST_Msk        (1ul<<SYS_IPRSTC2_I2S_RST_Pos)              /*!< SYS IPRSTC2: I2S_RST Mask */

#define SYS_IPRSTC2_I2S1_RST_Pos        30                                          /*!< SYS IPRSTC2: I2S1_RST Position */
#define SYS_IPRSTC2_I2S1_RST_Msk        (1ul<<SYS_IPRSTC2_I2S1_RST_Pos)              /*!< SYS IPRSTC2: I2S1_RST Mask */

#define SYS_IPRSTC2_PS2_RST_Pos            31                                          /*!< SYS IPRSTC2: PS2_RST Position */
#define SYS_IPRSTC2_PS2_RST_Msk            (1ul<<SYS_IPRSTC2_PS2_RST_Pos)              /*!< SYS IPRSTC2: PS2_RST Mask */

/* SYS IPRSTC3 Bit Field Definitions */
#define SYS_IPRSTC3_SC0_RST_Pos        0                                          /*!< SYS IPRSTC3: SC0_RST Position */
#define SYS_IPRSTC3_SC0_RST_Msk        (1ul<<SYS_IPRSTC3_SC0_RST_Pos)              /*!< SYS IPRSTC3: SC0_RST Mask */

#define SYS_IPRSTC3_SC1_RST_Pos        1                                          /*!< SYS IPRSTC3: SC1_RST Position */
#define SYS_IPRSTC3_SC1_RST_Msk        (1ul<<SYS_IPRSTC3_SC1_RST_Pos)              /*!< SYS IPRSTC3: SC1_RST Mask */

#define SYS_IPRSTC3_SC2_RST_Pos        2                                          /*!< SYS IPRSTC3: SC2_RST Position */
#define SYS_IPRSTC3_SC2_RST_Msk        (1ul<<SYS_IPRSTC3_SC2_RST_Pos)              /*!< SYS IPRSTC3: SC2_RST Mask */

#define SYS_IPRSTC3_SC3_RST_Pos        3                                          /*!< SYS IPRSTC3: SC3_RST Position */
#define SYS_IPRSTC3_SC3_RST_Msk        (1ul<<SYS_IPRSTC3_SC3_RST_Pos)              /*!< SYS IPRSTC3: SC3_RST Mask */

#define SYS_IPRSTC3_SC4_RST_Pos        4                                          /*!< SYS IPRSTC3: SC4_RST Position */
#define SYS_IPRSTC3_SC4_RST_Msk        (1ul<<SYS_IPRSTC3_SC4_RST_Pos)              /*!< SYS IPRSTC3: SC4_RST Mask */

#define SYS_IPRSTC3_SC5_RST_Pos        5                                          /*!< SYS IPRSTC3: SC5_RST Position */
#define SYS_IPRSTC3_SC5_RST_Msk        (1ul<<SYS_IPRSTC3_SC5_RST_Pos)              /*!< SYS IPRSTC3: SC5_RST Mask */

#define SYS_IPRSTC3_I2C4_RST_Pos        8                                          /*!< SYS IPRSTC3: I2C4_RST Position */
#define SYS_IPRSTC3_I2C4_RST_Msk        (1ul<<SYS_IPRSTC3_I2C4_RST_Pos)              /*!< SYS IPRSTC3: I2C4_RST Mask */

#define SYS_IPRSTC3_PWM0_RST_Pos        16                                          /*!< SYS IPRSTC3: PWM0_RST Position */
#define SYS_IPRSTC3_PWM0_RST_Msk        (1ul<<SYS_IPRSTC3_PWM0_RST_Pos)              /*!< SYS IPRSTC3: PWM0_RST Mask */

#define SYS_IPRSTC3_PWM1_RST_Pos        17                                          /*!< SYS IPRSTC3: PWM1_RST Position */
#define SYS_IPRSTC3_PWM1_RST_Msk        (1ul<<SYS_IPRSTC3_PWM0_RST_Pos)              /*!< SYS IPRSTC3: PWM1_RST Mask */

#define SYS_IPRSTC3_QEI0_RST_Pos        22                                          /*!< SYS IPRSTC3: QEI0_RST Position */
#define SYS_IPRSTC3_QEI0_RST_Msk        (1ul<<SYS_IPRSTC3_QEI0_RST_Pos)              /*!< SYS IPRSTC3: QEI0_RST Mask */

#define SYS_IPRSTC3_QEI1_RST_Pos        23                                          /*!< SYS IPRSTC3: QEI1_RST Position */
#define SYS_IPRSTC3_QEI1_RST_Msk        (1ul<<SYS_IPRSTC3_QEI1_RST_Pos)              /*!< SYS IPRSTC3: QEI1_RST Mask */

#define SYS_IPRSTC3_EPWM0_RST_Pos        24                                          /*!< SYS IPRSTC3: EPWM0_RST Position */
#define SYS_IPRSTC3_EPWM0_RST_Msk        (1ul<<SYS_IPRSTC3_EPWM1_RST_Pos)              /*!< SYS IPRSTC3: EPWM0_RST Mask */

#define SYS_IPRSTC3_EPWM1_RST_Pos        25                                          /*!< SYS IPRSTC3: EPWM1_RST Position */
#define SYS_IPRSTC3_EPWM1_RST_Msk        (1ul<<SYS_IPRSTC3_EPWM1_RST_Pos)              /*!< SYS IPRSTC3: EPWM1_RST Mask */

#define SYS_IPRSTC3_ECAP0_RST_Pos        26                                          /*!< SYS IPRSTC3: ECAP0_RST Position */
#define SYS_IPRSTC3_ECAP0_RST_Msk        (1ul<<SYS_IPRSTC3_ECAP0_RST_Pos)              /*!< SYS IPRSTC3: ECAP0_RST Mask */

#define SYS_IPRSTC3_ECAP1_RST_Pos        27                                          /*!< SYS IPRSTC3: ECAP0_RST Position */
#define SYS_IPRSTC3_ECAP1_RST_Msk        (1ul<<SYS_IPRSTC3_ECAP1_RST_Pos)              /*!< SYS IPRSTC3: ECAP0_RST Mask */

/* SYS BODCR Bit Field Definitions */
#define SYS_BODCR_BOD_EN_Pos        0                                              /*!< SYS BODCR: BOD_EN Position */
#define SYS_BODCR_BOD_EN_Msk        (1ul<<SYS_BODCR_BOD_EN_Pos)                      /*!< SYS BODCR: BOD_EN Mask */

#define SYS_BODCR_BOD_VL_Pos        1                                              /*!< SYS BODCR: BOD_VL Position */
#define SYS_BODCR_BOD_VL_Msk        (0x3ul<<SYS_BODCR_BOD_VL_Pos)                      /*!< SYS BODCR: BOD_VL Mask */

#define SYS_BODCR_BOD_RSTEN_Pos        3                                              /*!< SYS BODCR: BOD_RSTEN Position */
#define SYS_BODCR_BOD_RSTEN_Msk        (1ul<<SYS_BODCR_BOD_RSTEN_Pos)                      /*!< SYS BODCR: BOD_RSTEN Mask */

#define SYS_BODCR_BOD_INTF_Pos        4                                              /*!< SYS BODCR: BOD_INTF Position */
#define SYS_BODCR_BOD_INTF_Msk        (1ul<<SYS_BODCR_BOD_INTF_Pos)                      /*!< SYS BODCR: BOD_INTF Mask */

#define SYS_BODCR_BOD_LPM_Pos        5                                              /*!< SYS BODCR: BOD_LPM Position */
#define SYS_BODCR_BOD_LPM_Msk        (1ul<<SYS_BODCR_BOD_LPM_Pos)                      /*!< SYS BODCR: BOD_LPM Mask */

#define SYS_BODCR_BOD_OUT_Pos        6                                              /*!< SYS BODCR: BOD_OUT Position */
#define SYS_BODCR_BOD_OUT_Msk        (1ul<<SYS_BODCR_BOD_OUT_Pos)                      /*!< SYS BODCR: BOD_OUT Mask */

#define SYS_BODCR_LVR_EN_Pos        7                                              /*!< SYS BODCR: LVR_EN Position */
#define SYS_BODCR_LVR_EN_Msk        (1ul<<SYS_BODCR_BOD_EN_Pos)                      /*!< SYS BODCR: LVR_EN Mask */

/* SYS TEMPCR Bit Field Definitions */
#define SYS_TEMPCR_VTEMP_EN_Pos        0                                              /*!< SYS TEMPCR: VTEMP_EN Position */
#define SYS_TEMPCR_VTEMP_EN_Msk        (1ul<<SYS_TEMPCR_VTEMP_EN_Pos)                  /*!< SYS TEMPCR: VTEMP_EN Mask */

/* SYS VCID Bit Field Definitions */
#define SYS_VCID_VCID_Pos        0                                                  /*!< SYS VCID: VCID Position */
#define SYS_VCID_VCID_Msk        (0xFFFFul<<SYS_VCID_VCID_Pos)                          /*!< SYS VCID: VCID Mask */

/* SYS PORCR Bit Field Definitions */
#define SYS_PORCR_POR_DIS_CODE_Pos        0                                          /*!< SYS PORCR: POR_DIS_CODE Position */
#define SYS_PORCR_POR_DIS_CODE_Msk        (0xFFFFul<<SYS_VCID_POR_DIS_CODE_Pos)          /*!< SYS PORCR: POR_DIS_CODE Mask */

/* SYS VREFCR Bit Field Definitions */
#define SYS_VREFCR_VREF_ENG_Pos        0                                              /*!< SYS VREFCR: VREF_ENG Position */
#define SYS_VREFCR_VREF_ENG_Msk        (1ul<<SYS_VREFCR_VREF_ENG_Pos)                  /*!< SYS VREFCR: VREF_ENG Mask */

#define SYS_VREFCR_VREF_ENREG_Pos        1                                          /*!< SYS VREFCR: VREF_ENREG Position */
#define SYS_VREFCR_VREF_ENREG_Msk        (1ul<<SYS_VREFCR_VREF_ENREG_Pos)              /*!< SYS VREFCR: VREF_ENREG Mask */

#define SYS_VREFCR_VREF_SEL_Pos        2                                              /*!< SYS VREFCR: VREF_SEL Position */
#define SYS_VREFCR_VREF_SEL_Msk        (0x3ul<<SYS_VREFCR_VREF_SEL_Pos)                  /*!< SYS VREFCR: VREF_SEL Mask */

#define SYS_VREFCR_ADC_VREFSEL_Pos        4                                          /*!< SYS VREFCR: ADC_VREFSEL Position */
#define SYS_VREFCR_ADC_VREFSEL_Msk        (1ul<<SYS_VREFCR_ADC_VREFSEL_Pos)              /*!< SYS VREFCR: ADC_VREFSEL Mask */

#define SYS_VREFCR_ADC_SEL_Pos        8                                              /*!< SYS VREFCR: ADC_SEL Position */
#define SYS_VREFCR_ADC_SEL_Msk        (1ul<<SYS_VREFCR_ADC_SEL_Pos)                      /*!< SYS VREFCR: ADC_SEL Mask */

#define SYS_VREFCR_PWM_MODE_Pos        9                                              /*!< SYS VREFCR: PWM_MODE Position */
#define SYS_VREFCR_PWM_MODE_Msk        (1ul<<SYS_VREFCR_PWM_MODE_Pos)                  /*!< SYS VREFCR: PWM_MODE Mask */

/* SYS USBPHYCR Bit Field Definitions */
#define SYS_USBPHYCR_OTG_ROLE_Pos       0                                       /*!< SYS USBPHYCR: USB Role Option Position */
#define SYS_USBPHYCR_OTG_ROLE_Msk       (3ul<<SYS_USBPHYCR_OTG_ROLE_Pos)        /*!< SYS USBPHYCR: USB Role Option Mask */

#define SYS_USBPHYCR_OTG_V33_EN_Pos     8                                       /*!< SYS USBPHYCR: LDO33 Enable Control Position */
#define SYS_USBPHYCR_OTG_V33_EN_Msk     (1ul<<SYS_USBPHYCR_OTG_V33_EN_Pos)      /*!< SYS USBPHYCR: LDO33 Enable Control Mask */

/* SYS GPA_MFPL Bit Field Definitions */
#define SYS_GPA_MFPL_PA0_MFP_Pos 0                                                                        /*!< SYS GPA_MFPL: PA0_MFP Position */
#define SYS_GPA_MFPL_PA0_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA0_MFP_Pos)            /*!< SYS GPA_MFPL: PA0_MFP Mask  */

#define SYS_GPA_MFPL_PA1_MFP_Pos 4                                                                        /*!< SYS GPA_MFPL: PA1_MFP Position */
#define SYS_GPA_MFPL_PA1_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA1_MFP_Pos)            /*!< SYS GPA_MFPL: PA1_MFP Mask  */

#define SYS_GPA_MFPL_PA2_MFP_Pos 8                                                                        /*!< SYS GPA_MFPL: PA2_MFP Position */
#define SYS_GPA_MFPL_PA2_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA2_MFP_Pos)            /*!< SYS GPA_MFPL: PA2_MFP Mask */

#define SYS_GPA_MFPL_PA3_MFP_Pos 12                                                                        /*!< SYS GPA_MFPL: PA3_MFP Position */
#define SYS_GPA_MFPL_PA3_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA3_MFP_Pos)            /*!< SYS GPA_MFPL: PA3_MFP Mask */

#define SYS_GPA_MFPL_PA4_MFP_Pos 16                                                                        /*!< SYS GPA_MFPL: PA4_MFP Position */
#define SYS_GPA_MFPL_PA4_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA4_MFP_Pos)            /*!< SYS GPA_MFPL: PA4_MFP Mask */

#define SYS_GPA_MFPL_PA5_MFP_Pos 20                                                                        /*!< SYS GPA_MFPL: PA5_MFP Position */
#define SYS_GPA_MFPL_PA5_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA5_MFP_Pos)            /*!< SYS GPA_MFPL: PA5_MFP Mask */

#define SYS_GPA_MFPL_PA6_MFP_Pos 24                                                                        /*!< SYS GPA_MFPL: PA6_MFP Position */
#define SYS_GPA_MFPL_PA6_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA6_MFP_Pos)            /*!< SYS GPA_MFPL: PA6_MFP Mask */

#define SYS_GPA_MFPL_PA7_MFP_Pos 28                                                                        /*!< SYS GPA_MFPL: PA7_MFP Position */
#define SYS_GPA_MFPL_PA7_MFP_Msk    (0xFul<<SYS_GPA_MFPL_PA7_MFP_Pos)            /*!< SYS GPA_MFPL: PA7_MFP Mask */

/* SYS GPA_MFPH Bit Field Definitions */
#define SYS_GPA_MFPH_PA8_MFP_Pos 0                                                                        /*!< SYS GPA_MFPH: PA8_MFP Position */
#define SYS_GPA_MFPH_PA8_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA8_MFP_Pos)            /*!< SYS GPA_MFPH: PA8_MFP Mask  */

#define SYS_GPA_MFPH_PA9_MFP_Pos 4                                                                        /*!< SYS GPA_MFPH: PA9_MFP Position */
#define SYS_GPA_MFPH_PA9_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA9_MFP_Pos)            /*!< SYS GPA_MFPH: PA9_MFP Mask  */

#define SYS_GPA_MFPH_PA10_MFP_Pos 8                                                                        /*!< SYS GPA_MFPH: PA10_MFP Position */
#define SYS_GPA_MFPH_PA10_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA10_MFP_Pos)        /*!< SYS GPA_MFPH: PA10_MFP Mask */

#define SYS_GPA_MFPH_PA11_MFP_Pos 12                                                                    /*!< SYS GPA_MFPH: PA11_MFP Position */
#define SYS_GPA_MFPH_PA11_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA11_MFP_Pos)        /*!< SYS GPA_MFPH: PA11_MFP Mask */

#define SYS_GPA_MFPH_PA12_MFP_Pos 16                                                                    /*!< SYS GPA_MFPH: PA12_MFP Position */
#define SYS_GPA_MFPH_PA12_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA12_MFP_Pos)        /*!< SYS GPA_MFPH: PA12_MFP Mask */

#define SYS_GPA_MFPH_PA13_MFP_Pos 20                                                                    /*!< SYS GPA_MFPH: PA13_MFP Position */
#define SYS_GPA_MFPH_PA13_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA13_MFP_Pos)        /*!< SYS GPA_MFPH: PA13_MFP Mask */

#define SYS_GPA_MFPH_PA14_MFP_Pos 24                                                                    /*!< SYS GPA_MFPH: PA14_MFP Position */
#define SYS_GPA_MFPH_PA14_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA14_MFP_Pos)        /*!< SYS GPA_MFPH: PA14_MFP Mask */

#define SYS_GPA_MFPH_PA15_MFP_Pos 28                                                                    /*!< SYS GPA_MFPH: PA15_MFP Position */
#define SYS_GPA_MFPH_PA15_MFP_Msk    (0xFul<<SYS_GPA_MFPH_PA15_MFP_Pos)        /*!< SYS GPA_MFPH: PA15_MFP Mask */

/* SYS GPB_MFPL Bit Field Definitions */
#define SYS_GPB_MFPL_PB0_MFP_Pos 0                                                                        /*!< SYS GPB_MFPL: PB0_MFP Position */
#define SYS_GPB_MFPL_PB0_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB0_MFP_Pos)            /*!< SYS GPB_MFPL: PB0_MFP Mask  */

#define SYS_GPB_MFPL_PB1_MFP_Pos 4                                                                        /*!< SYS GPB_MFPL: PB1_MFP Position */
#define SYS_GPB_MFPL_PB1_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB1_MFP_Pos)            /*!< SYS GPB_MFPL: PB1_MFP Mask  */

#define SYS_GPB_MFPL_PB2_MFP_Pos 8                                                                        /*!< SYS GPB_MFPL: PB2_MFP Position */
#define SYS_GPB_MFPL_PB2_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB2_MFP_Pos)            /*!< SYS GPB_MFPL: PB2_MFP Mask */

#define SYS_GPB_MFPL_PB3_MFP_Pos 12                                                                        /*!< SYS GPB_MFPL: PB3_MFP Position */
#define SYS_GPB_MFPL_PB3_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB3_MFP_Pos)            /*!< SYS GPB_MFPL: PB3_MFP Mask */

#define SYS_GPB_MFPL_PB4_MFP_Pos 16                                                                        /*!< SYS GPB_MFPL: PB4_MFP Position */
#define SYS_GPB_MFPL_PB4_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB4_MFP_Pos)            /*!< SYS GPB_MFPL: PB4_MFP Mask */

#define SYS_GPB_MFPL_PB5_MFP_Pos 20                                                                        /*!< SYS GPB_MFPL: PB5_MFP Position */
#define SYS_GPB_MFPL_PB5_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB5_MFP_Pos)            /*!< SYS GPB_MFPL: PB5_MFP Mask */

#define SYS_GPB_MFPL_PB6_MFP_Pos 24                                                                        /*!< SYS GPB_MFPL: PB6_MFP Position */
#define SYS_GPB_MFPL_PB6_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB6_MFP_Pos)            /*!< SYS GPB_MFPL: PB6_MFP Mask */

#define SYS_GPB_MFPL_PB7_MFP_Pos 28                                                                        /*!< SYS GPB_MFPL: PB7_MFP Position */
#define SYS_GPB_MFPL_PB7_MFP_Msk    (0xFul<<SYS_GPB_MFPL_PB7_MFP_Pos)            /*!< SYS GPB_MFPL: PB7_MFP Mask */

/* SYS GPB_MFPH Bit Field Definitions */
#define SYS_GPB_MFPH_PB8_MFP_Pos 0                                                                        /*!< SYS GPB_MFPH: PB8_MFP Position */
#define SYS_GPB_MFPH_PB8_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB8_MFP_Pos)            /*!< SYS GPB_MFPH: PB8_MFP Mask  */

#define SYS_GPB_MFPH_PB9_MFP_Pos 4                                                                        /*!< SYS GPB_MFPH: PB9_MFP Position */
#define SYS_GPB_MFPH_PB9_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB9_MFP_Pos)            /*!< SYS GPB_MFPH: PB9_MFP Mask  */

#define SYS_GPB_MFPH_PB10_MFP_Pos 8                                                                        /*!< SYS GPB_MFPH: PB10_MFP Position */
#define SYS_GPB_MFPH_PB10_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB10_MFP_Pos)        /*!< SYS GPB_MFPH: PB10_MFP Mask */

#define SYS_GPB_MFPH_PB11_MFP_Pos 12                                                                    /*!< SYS GPB_MFPH: PB11_MFP Position */
#define SYS_GPB_MFPH_PB11_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB11_MFP_Pos)        /*!< SYS GPB_MFPH: PB11_MFP Mask */

#define SYS_GPB_MFPH_PB12_MFP_Pos 16                                                                    /*!< SYS GPB_MFPH: PB12_MFP Position */
#define SYS_GPB_MFPH_PB12_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB12_MFP_Pos)        /*!< SYS GPB_MFPH: PB12_MFP Mask */

#define SYS_GPB_MFPH_PB13_MFP_Pos 20                                                                    /*!< SYS GPB_MFPH: PB13_MFP Position */
#define SYS_GPB_MFPH_PB13_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB13_MFP_Pos)        /*!< SYS GPB_MFPH: PB13_MFP Mask */

#define SYS_GPB_MFPH_PB14_MFP_Pos 24                                                                    /*!< SYS GPB_MFPH: PB14_MFP Position */
#define SYS_GPB_MFPH_PB14_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB14_MFP_Pos)        /*!< SYS GPB_MFPH: PB14_MFP Mask */

#define SYS_GPB_MFPH_PB15_MFP_Pos 28                                                                    /*!< SYS GPB_MFPH: PB15_MFP Position */
#define SYS_GPB_MFPH_PB15_MFP_Msk    (0xFul<<SYS_GPB_MFPH_PB15_MFP_Pos)        /*!< SYS GPB_MFPH: PB15_MFP Mask */

/* SYS GPC_MFPL Bit Field Definitions */
#define SYS_GPC_MFPL_PC0_MFP_Pos 0                                                                        /*!< SYS GPC_MFPL: PC0_MFP Position */
#define SYS_GPC_MFPL_PC0_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC0_MFP_Pos)            /*!< SYS GPC_MFPL: PC0_MFP Mask  */

#define SYS_GPC_MFPL_PC1_MFP_Pos 4                                                                        /*!< SYS GPC_MFPL: PC1_MFP Position */
#define SYS_GPC_MFPL_PC1_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC1_MFP_Pos)            /*!< SYS GPC_MFPL: PC1_MFP Mask  */

#define SYS_GPC_MFPL_PC2_MFP_Pos 8                                                                        /*!< SYS GPC_MFPL: PC2_MFP Position */
#define SYS_GPC_MFPL_PC2_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC2_MFP_Pos)            /*!< SYS GPC_MFPL: PC2_MFP Mask */

#define SYS_GPC_MFPL_PC3_MFP_Pos 12                                                                        /*!< SYS GPC_MFPL: PC3_MFP Position */
#define SYS_GPC_MFPL_PC3_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC3_MFP_Pos)            /*!< SYS GPC_MFPL: PC3_MFP Mask */

#define SYS_GPC_MFPL_PC4_MFP_Pos 16                                                                        /*!< SYS GPC_MFPL: PC4_MFP Position */
#define SYS_GPC_MFPL_PC4_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC4_MFP_Pos)            /*!< SYS GPC_MFPL: PC4_MFP Mask */

#define SYS_GPC_MFPL_PC5_MFP_Pos 20                                                                        /*!< SYS GPC_MFPL: PC5_MFP Position */
#define SYS_GPC_MFPL_PC5_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC5_MFP_Pos)            /*!< SYS GPC_MFPL: PC5_MFP Mask */

#define SYS_GPC_MFPL_PC6_MFP_Pos 24                                                                        /*!< SYS GPC_MFPL: PC6_MFP Position */
#define SYS_GPC_MFPL_PC6_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC6_MFP_Pos)            /*!< SYS GPC_MFPL: PC6_MFP Mask */

#define SYS_GPC_MFPL_PC7_MFP_Pos 28                                                                        /*!< SYS GPC_MFPL: PC7_MFP Position */
#define SYS_GPC_MFPL_PC7_MFP_Msk    (0xFul<<SYS_GPC_MFPL_PC7_MFP_Pos)            /*!< SYS GPC_MFPL: PC7_MFP Mask */

/* SYS GPC_MFPH Bit Field Definitions */
#define SYS_GPC_MFPH_PC8_MFP_Pos 0                                                                        /*!< SYS GPC_MFPH: PC8_MFP Position */
#define SYS_GPC_MFPH_PC8_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC8_MFP_Pos)            /*!< SYS GPC_MFPH: PC8_MFP Mask  */

#define SYS_GPC_MFPH_PC9_MFP_Pos 4                                                                        /*!< SYS GPC_MFPH: PC9_MFP Position */
#define SYS_GPC_MFPH_PC9_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC9_MFP_Pos)            /*!< SYS GPC_MFPH: PC9_MFP Mask  */

#define SYS_GPC_MFPH_PC10_MFP_Pos 8                                                                        /*!< SYS GPC_MFPH: PC10_MFP Position */
#define SYS_GPC_MFPH_PC10_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC10_MFP_Pos)        /*!< SYS GPC_MFPH: PC10_MFP Mask */

#define SYS_GPC_MFPH_PC11_MFP_Pos 12                                                                    /*!< SYS GPC_MFPH: PC11_MFP Position */
#define SYS_GPC_MFPH_PC11_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC11_MFP_Pos)        /*!< SYS GPC_MFPH: PC11_MFP Mask */

#define SYS_GPC_MFPH_PC12_MFP_Pos 16                                                                    /*!< SYS GPC_MFPH: PC12_MFP Position */
#define SYS_GPC_MFPH_PC12_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC12_MFP_Pos)        /*!< SYS GPC_MFPH: PC12_MFP Mask */

#define SYS_GPC_MFPH_PC13_MFP_Pos 20                                                                    /*!< SYS GPC_MFPH: PC13_MFP Position */
#define SYS_GPC_MFPH_PC13_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC13_MFP_Pos)        /*!< SYS GPC_MFPH: PC13_MFP Mask */

#define SYS_GPC_MFPH_PC14_MFP_Pos 24                                                                    /*!< SYS GPC_MFPH: PC14_MFP Position */
#define SYS_GPC_MFPH_PC14_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC14_MFP_Pos)        /*!< SYS GPC_MFPH: PC14_MFP Mask */

#define SYS_GPC_MFPH_PC15_MFP_Pos 28                                                                    /*!< SYS GPC_MFPH: PC15_MFP Position */
#define SYS_GPC_MFPH_PC15_MFP_Msk    (0xFul<<SYS_GPC_MFPH_PC15_MFP_Pos)        /*!< SYS GPC_MFPH: PC15_MFP Mask */

/* SYS GPD_MFPL Bit Field Definitions */
#define SYS_GPD_MFPL_PD0_MFP_Pos 0                                                                        /*!< SYS GPD_MFPL: PD0_MFP Position */
#define SYS_GPD_MFPL_PD0_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD0_MFP_Pos)            /*!< SYS GPD_MFPL: PD0_MFP Mask  */

#define SYS_GPD_MFPL_PD1_MFP_Pos 4                                                                        /*!< SYS GPD_MFPL: PD1_MFP Position */
#define SYS_GPD_MFPL_PD1_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD1_MFP_Pos)            /*!< SYS GPD_MFPL: PD1_MFP Mask  */

#define SYS_GPD_MFPL_PD2_MFP_Pos 8                                                                        /*!< SYS GPD_MFPL: PD2_MFP Position */
#define SYS_GPD_MFPL_PD2_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD2_MFP_Pos)            /*!< SYS GPD_MFPL: PD2_MFP Mask */

#define SYS_GPD_MFPL_PD3_MFP_Pos 12                                                                        /*!< SYS GPD_MFPL: PD3_MFP Position */
#define SYS_GPD_MFPL_PD3_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD3_MFP_Pos)            /*!< SYS GPD_MFPL: PD3_MFP Mask */

#define SYS_GPD_MFPL_PD4_MFP_Pos 16                                                                        /*!< SYS GPD_MFPL: PD4_MFP Position */
#define SYS_GPD_MFPL_PD4_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD4_MFP_Pos)            /*!< SYS GPD_MFPL: PD4_MFP Mask */

#define SYS_GPD_MFPL_PD5_MFP_Pos 20                                                                        /*!< SYS GPD_MFPL: PD5_MFP Position */
#define SYS_GPD_MFPL_PD5_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD5_MFP_Pos)            /*!< SYS GPD_MFPL: PD5_MFP Mask */

#define SYS_GPD_MFPL_PD6_MFP_Pos 24                                                                        /*!< SYS GPD_MFPL: PD6_MFP Position */
#define SYS_GPD_MFPL_PD6_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD6_MFP_Pos)            /*!< SYS GPD_MFPL: PD6_MFP Mask */

#define SYS_GPD_MFPL_PD7_MFP_Pos 28                                                                        /*!< SYS GPD_MFPL: PD7_MFP Position */
#define SYS_GPD_MFPL_PD7_MFP_Msk    (0xFul<<SYS_GPD_MFPL_PD7_MFP_Pos)            /*!< SYS GPD_MFPL: PD7_MFP Mask */

/* SYS GPD_MFPH Bit Field Definitions */
#define SYS_GPD_MFPH_PD8_MFP_Pos 0                                                                        /*!< SYS GPD_MFPH: PD8_MFP Position */
#define SYS_GPD_MFPH_PD8_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD8_MFP_Pos)            /*!< SYS GPD_MFPH: PD8_MFP Mask  */

#define SYS_GPD_MFPH_PD9_MFP_Pos 4                                                                        /*!< SYS GPD_MFPH: PD9_MFP Position */
#define SYS_GPD_MFPH_PD9_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD9_MFP_Pos)            /*!< SYS GPD_MFPH: PD9_MFP Mask  */

#define SYS_GPD_MFPH_PD10_MFP_Pos 8                                                                        /*!< SYS GPD_MFPH: PD10_MFP Position */
#define SYS_GPD_MFPH_PD10_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD10_MFP_Pos)        /*!< SYS GPD_MFPH: PD10_MFP Mask */

#define SYS_GPD_MFPH_PD11_MFP_Pos 12                                                                    /*!< SYS GPD_MFPH: PD11_MFP Position */
#define SYS_GPD_MFPH_PD11_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD11_MFP_Pos)        /*!< SYS GPD_MFPH: PD11_MFP Mask */

#define SYS_GPD_MFPH_PD12_MFP_Pos 16                                                                    /*!< SYS GPD_MFPH: PD12_MFP Position */
#define SYS_GPD_MFPH_PD12_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD12_MFP_Pos)        /*!< SYS GPD_MFPH: PD12_MFP Mask */

#define SYS_GPD_MFPH_PD13_MFP_Pos 20                                                                    /*!< SYS GPD_MFPH: PD13_MFP Position */
#define SYS_GPD_MFPH_PD13_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD13_MFP_Pos)        /*!< SYS GPD_MFPH: PD13_MFP Mask */

#define SYS_GPD_MFPH_PD14_MFP_Pos 24                                                                    /*!< SYS GPD_MFPH: PD14_MFP Position */
#define SYS_GPD_MFPH_PD14_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD14_MFP_Pos)        /*!< SYS GPD_MFPH: PD14_MFP Mask */

#define SYS_GPD_MFPH_PD15_MFP_Pos 28                                                                    /*!< SYS GPD_MFPH: PD15_MFP Position */
#define SYS_GPD_MFPH_PD15_MFP_Msk    (0xFul<<SYS_GPD_MFPH_PD15_MFP_Pos)        /*!< SYS GPD_MFPH: PD15_MFP Mask */

/* SYS GPE_MFPL Bit Field Definitions */
#define SYS_GPE_MFPL_PE0_MFP_Pos 0                                                                        /*!< SYS GPE_MFPL: PE0_MFP Position */
#define SYS_GPE_MFPL_PE0_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE0_MFP_Pos)            /*!< SYS GPE_MFPL: PE0_MFP Mask  */

#define SYS_GPE_MFPL_PE1_MFP_Pos 4                                                                        /*!< SYS GPE_MFPL: PE1_MFP Position */
#define SYS_GPE_MFPL_PE1_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE1_MFP_Pos)            /*!< SYS GPE_MFPL: PE1_MFP Mask  */

#define SYS_GPE_MFPL_PE2_MFP_Pos 8                                                                        /*!< SYS GPE_MFPL: PE2_MFP Position */
#define SYS_GPE_MFPL_PE2_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE2_MFP_Pos)            /*!< SYS GPE_MFPL: PE2_MFP Mask */

#define SYS_GPE_MFPL_PE3_MFP_Pos 12                                                                        /*!< SYS GPE_MFPL: PE3_MFP Position */
#define SYS_GPE_MFPL_PE3_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE3_MFP_Pos)            /*!< SYS GPE_MFPL: PE3_MFP Mask */

#define SYS_GPE_MFPL_PE4_MFP_Pos 16                                                                        /*!< SYS GPE_MFPL: PE4_MFP Position */
#define SYS_GPE_MFPL_PE4_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE4_MFP_Pos)            /*!< SYS GPE_MFPL: PE4_MFP Mask */

#define SYS_GPE_MFPL_PE5_MFP_Pos 20                                                                        /*!< SYS GPE_MFPL: PE5_MFP Position */
#define SYS_GPE_MFPL_PE5_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE5_MFP_Pos)            /*!< SYS GPE_MFPL: PE5_MFP Mask */

#define SYS_GPE_MFPL_PE6_MFP_Pos 24                                                                        /*!< SYS GPE_MFPL: PE6_MFP Position */
#define SYS_GPE_MFPL_PE6_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE6_MFP_Pos)            /*!< SYS GPE_MFPL: PE6_MFP Mask */

#define SYS_GPE_MFPL_PE7_MFP_Pos 28                                                                        /*!< SYS GPE_MFPL: PE7_MFP Position */
#define SYS_GPE_MFPL_PE7_MFP_Msk    (0xFul<<SYS_GPE_MFPL_PE7_MFP_Pos)            /*!< SYS GPE_MFPL: PE7_MFP Mask */

/* SYS GPE_MFPH Bit Field Definitions */
#define SYS_GPE_MFPH_PE8_MFP_Pos 0                                                                        /*!< SYS GPE_MFPH: PE8_MFP Position */
#define SYS_GPE_MFPH_PE8_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE8_MFP_Pos)            /*!< SYS GPE_MFPH: PE8_MFP Mask  */

#define SYS_GPE_MFPH_PE9_MFP_Pos 4                                                                        /*!< SYS GPE_MFPH: PE9_MFP Position */
#define SYS_GPE_MFPH_PE9_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE9_MFP_Pos)            /*!< SYS GPE_MFPH: PE9_MFP Mask  */

#define SYS_GPE_MFPH_PE10_MFP_Pos 8                                                                        /*!< SYS GPE_MFPH: PE10_MFP Position */
#define SYS_GPE_MFPH_PE10_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE10_MFP_Pos)        /*!< SYS GPE_MFPH: PE10_MFP Mask */

#define SYS_GPE_MFPH_PE11_MFP_Pos 12                                                                    /*!< SYS GPE_MFPH: PE11_MFP Position */
#define SYS_GPE_MFPH_PE11_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE11_MFP_Pos)        /*!< SYS GPE_MFPH: PE11_MFP Mask */

#define SYS_GPE_MFPH_PE12_MFP_Pos 16                                                                    /*!< SYS GPE_MFPH: PE12_MFP Position */
#define SYS_GPE_MFPH_PE12_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE12_MFP_Pos)        /*!< SYS GPE_MFPH: PE12_MFP Mask */

#define SYS_GPE_MFPH_PE13_MFP_Pos 20                                                                    /*!< SYS GPE_MFPH: PE13_MFP Position */
#define SYS_GPE_MFPH_PE13_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE13_MFP_Pos)        /*!< SYS GPE_MFPH: PE13_MFP Mask */

#define SYS_GPE_MFPH_PE14_MFP_Pos 24                                                                    /*!< SYS GPE_MFPH: PE14_MFP Position */
#define SYS_GPE_MFPH_PE14_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE14_MFP_Pos)        /*!< SYS GPE_MFPH: PE14_MFP Mask */

#define SYS_GPE_MFPH_PE15_MFP_Pos 28                                                                    /*!< SYS GPE_MFPH: PE15_MFP Position */
#define SYS_GPE_MFPH_PE15_MFP_Msk    (0xFul<<SYS_GPE_MFPH_PE15_MFP_Pos)        /*!< SYS GPE_MFPH: PE15_MFP Mask */

/* SYS GPF_MFPL Bit Field Definitions */
#define SYS_GPF_MFPL_PF0_MFP_Pos 0                                                                        /*!< SYS GPF_MFPL: PF0_MFP Position */
#define SYS_GPF_MFPL_PF0_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF0_MFP_Pos)            /*!< SYS GPF_MFPL: PF0_MFP Mask  */

#define SYS_GPF_MFPL_PF1_MFP_Pos 4                                                                        /*!< SYS GPF_MFPL: PF1_MFP Position */
#define SYS_GPF_MFPL_PF1_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF1_MFP_Pos)            /*!< SYS GPF_MFPL: PF1_MFP Mask  */

#define SYS_GPF_MFPL_PF2_MFP_Pos 8                                                                        /*!< SYS GPF_MFPL: PF2_MFP Position */
#define SYS_GPF_MFPL_PF2_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF2_MFP_Pos)            /*!< SYS GPF_MFPL: PF2_MFP Mask */

#define SYS_GPF_MFPL_PF3_MFP_Pos 12                                                                        /*!< SYS GPF_MFPL: PF3_MFP Position */
#define SYS_GPF_MFPL_PF3_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF3_MFP_Pos)            /*!< SYS GPF_MFPL: PF3_MFP Mask */

#define SYS_GPF_MFPL_PF4_MFP_Pos 16                                                                        /*!< SYS GPF_MFPL: PF4_MFP Position */
#define SYS_GPF_MFPL_PF4_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF4_MFP_Pos)            /*!< SYS GPF_MFPL: PF4_MFP Mask */

#define SYS_GPF_MFPL_PF5_MFP_Pos 20                                                                        /*!< SYS GPF_MFPL: PF5_MFP Position */
#define SYS_GPF_MFPL_PF5_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF5_MFP_Pos)            /*!< SYS GPF_MFPL: PF5_MFP Mask */

#define SYS_GPF_MFPL_PF6_MFP_Pos 24                                                                        /*!< SYS GPF_MFPL: PF6_MFP Position */
#define SYS_GPF_MFPL_PF6_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF6_MFP_Pos)            /*!< SYS GPF_MFPL: PF6_MFP Mask */

#define SYS_GPF_MFPL_PF7_MFP_Pos 28                                                                        /*!< SYS GPF_MFPL: PF7_MFP Position */
#define SYS_GPF_MFPL_PF7_MFP_Msk    (0xFul<<SYS_GPF_MFPL_PF7_MFP_Pos)            /*!< SYS GPF_MFPL: PF7_MFP Mask */

/* SYS GPF_MFPH Bit Field Definitions */
#define SYS_GPF_MFPH_PF8_MFP_Pos 0                                                                        /*!< SYS GPF_MFPH: PF8_MFP Position */
#define SYS_GPF_MFPH_PF8_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF8_MFP_Pos)            /*!< SYS GPF_MFPH: PF8_MFP Mask  */

#define SYS_GPF_MFPH_PF9_MFP_Pos 4                                                                        /*!< SYS GPF_MFPH: PF9_MFP Position */
#define SYS_GPF_MFPH_PF9_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF9_MFP_Pos)            /*!< SYS GPF_MFPH: PF9_MFP Mask  */

#define SYS_GPF_MFPH_PF10_MFP_Pos 8                                                                        /*!< SYS GPF_MFPH: PF10_MFP Position */
#define SYS_GPF_MFPH_PF10_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF10_MFP_Pos)        /*!< SYS GPF_MFPH: PF10_MFP Mask */

#define SYS_GPF_MFPH_PF11_MFP_Pos 12                                                                    /*!< SYS GPF_MFPH: PF11_MFP Position */
#define SYS_GPF_MFPH_PF11_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF11_MFP_Pos)        /*!< SYS GPF_MFPH: PF11_MFP Mask */

#define SYS_GPF_MFPH_PF12_MFP_Pos 16                                                                    /*!< SYS GPF_MFPH: PF12_MFP Position */
#define SYS_GPF_MFPH_PF12_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF12_MFP_Pos)        /*!< SYS GPF_MFPH: PF12_MFP Mask */

#define SYS_GPF_MFPH_PF13_MFP_Pos 20                                                                    /*!< SYS GPF_MFPH: PF13_MFP Position */
#define SYS_GPF_MFPH_PF13_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF13_MFP_Pos)        /*!< SYS GPF_MFPH: PF13_MFP Mask */

#define SYS_GPF_MFPH_PF14_MFP_Pos 24                                                                    /*!< SYS GPF_MFPH: PF14_MFP Position */
#define SYS_GPF_MFPH_PF14_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF14_MFP_Pos)        /*!< SYS GPF_MFPH: PF14_MFP Mask */

#define SYS_GPF_MFPH_PF15_MFP_Pos 28                                                                    /*!< SYS GPF_MFPH: PF15_MFP Position */
#define SYS_GPF_MFPH_PF15_MFP_Msk    (0xFul<<SYS_GPF_MFPH_PF15_MFP_Pos)        /*!< SYS GPF_MFPH: PF15_MFP Mask */

/* SYS GPG_MFPL Bit Field Definitions */
#define SYS_GPG_MFPL_PG0_MFP_Pos 0                                                                        /*!< SYS GPG_MFPL: PG0_MFP Position */
#define SYS_GPG_MFPL_PG0_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG0_MFP_Pos)            /*!< SYS GPG_MFPL: PG0_MFP Mask  */

#define SYS_GPG_MFPL_PG1_MFP_Pos 4                                                                        /*!< SYS GPG_MFPL: PG1_MFP Position */
#define SYS_GPG_MFPL_PG1_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG1_MFP_Pos)            /*!< SYS GPG_MFPL: PG1_MFP Mask  */

#define SYS_GPG_MFPL_PG2_MFP_Pos 8                                                                        /*!< SYS GPG_MFPL: PG2_MFP Position */
#define SYS_GPG_MFPL_PG2_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG2_MFP_Pos)            /*!< SYS GPG_MFPL: PG2_MFP Mask */

#define SYS_GPG_MFPL_PG3_MFP_Pos 12                                                                        /*!< SYS GPG_MFPL: PG3_MFP Position */
#define SYS_GPG_MFPL_PG3_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG3_MFP_Pos)            /*!< SYS GPG_MFPL: PG3_MFP Mask */

#define SYS_GPG_MFPL_PG4_MFP_Pos 16                                                                        /*!< SYS GPG_MFPL: PG4_MFP Position */
#define SYS_GPG_MFPL_PG4_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG4_MFP_Pos)            /*!< SYS GPG_MFPL: PG4_MFP Mask */

#define SYS_GPG_MFPL_PG5_MFP_Pos 20                                                                        /*!< SYS GPG_MFPL: PG5_MFP Position */
#define SYS_GPG_MFPL_PG5_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG5_MFP_Pos)            /*!< SYS GPG_MFPL: PG5_MFP Mask */

#define SYS_GPG_MFPL_PG6_MFP_Pos 24                                                                        /*!< SYS GPG_MFPL: PG6_MFP Position */
#define SYS_GPG_MFPL_PG6_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG6_MFP_Pos)            /*!< SYS GPG_MFPL: PG6_MFP Mask */

#define SYS_GPG_MFPL_PG7_MFP_Pos 28                                                                        /*!< SYS GPG_MFPL: PG7_MFP Position */
#define SYS_GPG_MFPL_PG7_MFP_Msk    (0xFul<<SYS_GPG_MFPL_PG7_MFP_Pos)            /*!< SYS GPG_MFPL: PG7_MFP Mask */

/* SYS GPG_MFPH Bit Field Definitions */
#define SYS_GPG_MFPH_PG8_MFP_Pos 0                                                                        /*!< SYS GPG_MFPH: PG8_MFP Position */
#define SYS_GPG_MFPH_PG8_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG8_MFP_Pos)            /*!< SYS GPG_MFPH: PG8_MFP Mask  */

#define SYS_GPG_MFPH_PG9_MFP_Pos 4                                                                        /*!< SYS GPG_MFPH: PG9_MFP Position */
#define SYS_GPG_MFPH_PG9_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG9_MFP_Pos)            /*!< SYS GPG_MFPH: PG9_MFP Mask  */

#define SYS_GPG_MFPH_PG10_MFP_Pos 8                                                                        /*!< SYS GPG_MFPH: PG10_MFP Position */
#define SYS_GPG_MFPH_PG10_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG10_MFP_Pos)        /*!< SYS GPG_MFPH: PG10_MFP Mask */

#define SYS_GPG_MFPH_PG11_MFP_Pos 12                                                                    /*!< SYS GPG_MFPH: PG11_MFP Position */
#define SYS_GPG_MFPH_PG11_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG11_MFP_Pos)        /*!< SYS GPG_MFPH: PG11_MFP Mask */

#define SYS_GPG_MFPH_PG12_MFP_Pos 16                                                                    /*!< SYS GPG_MFPH: PG12_MFP Position */
#define SYS_GPG_MFPH_PG12_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG12_MFP_Pos)        /*!< SYS GPG_MFPH: PG12_MFP Mask */

#define SYS_GPG_MFPH_PG13_MFP_Pos 20                                                                    /*!< SYS GPG_MFPH: PG13_MFP Position */
#define SYS_GPG_MFPH_PG13_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG13_MFP_Pos)        /*!< SYS GPG_MFPH: PG13_MFP Mask */

#define SYS_GPG_MFPH_PG14_MFP_Pos 24                                                                    /*!< SYS GPG_MFPH: PG14_MFP Position */
#define SYS_GPG_MFPH_PG14_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG14_MFP_Pos)        /*!< SYS GPG_MFPH: PG14_MFP Mask */

#define SYS_GPG_MFPH_PG15_MFP_Pos 28                                                                    /*!< SYS GPG_MFPH: PG15_MFP Position */
#define SYS_GPG_MFPH_PG15_MFP_Msk    (0xFul<<SYS_GPG_MFPH_PG15_MFP_Pos)        /*!< SYS GPG_MFPH: PG15_MFP Mask */

/* SYS GPH_MFPL Bit Field Definitions */
#define SYS_GPH_MFPL_PH0_MFP_Pos 0                                                                        /*!< SYS GPH_MFPL: PH0_MFP Position */
#define SYS_GPH_MFPL_PH0_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH0_MFP_Pos)            /*!< SYS GPH_MFPL: PH0_MFP Mask  */

#define SYS_GPH_MFPL_PH1_MFP_Pos 4                                                                        /*!< SYS GPH_MFPL: PH1_MFP Position */
#define SYS_GPH_MFPL_PH1_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH1_MFP_Pos)            /*!< SYS GPH_MFPL: PH1_MFP Mask  */

#define SYS_GPH_MFPL_PH2_MFP_Pos 8                                                                        /*!< SYS GPH_MFPL: PH2_MFP Position */
#define SYS_GPH_MFPL_PH2_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH2_MFP_Pos)            /*!< SYS GPH_MFPL: PH2_MFP Mask */

#define SYS_GPH_MFPL_PH3_MFP_Pos 12                                                                        /*!< SYS GPH_MFPL: PH3_MFP Position */
#define SYS_GPH_MFPL_PH3_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH3_MFP_Pos)            /*!< SYS GPH_MFPL: PH3_MFP Mask */

#define SYS_GPH_MFPL_PH4_MFP_Pos 16                                                                        /*!< SYS GPH_MFPL: PH4_MFP Position */
#define SYS_GPH_MFPL_PH4_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH4_MFP_Pos)            /*!< SYS GPH_MFPL: PH4_MFP Mask */

#define SYS_GPH_MFPL_PH5_MFP_Pos 20                                                                        /*!< SYS GPH_MFPL: PH5_MFP Position */
#define SYS_GPH_MFPL_PH5_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH5_MFP_Pos)            /*!< SYS GPH_MFPL: PH5_MFP Mask */

#define SYS_GPH_MFPL_PH6_MFP_Pos 24                                                                        /*!< SYS GPH_MFPL: PH6_MFP Position */
#define SYS_GPH_MFPL_PH6_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH6_MFP_Pos)            /*!< SYS GPH_MFPL: PH6_MFP Mask */

#define SYS_GPH_MFPL_PH7_MFP_Pos 28                                                                        /*!< SYS GPH_MFPL: PH7_MFP Position */
#define SYS_GPH_MFPL_PH7_MFP_Msk    (0xFul<<SYS_GPH_MFPL_PH7_MFP_Pos)            /*!< SYS GPH_MFPL: PH7_MFP Mask */

/* SYS GPH_MFPH Bit Field Definitions */
#define SYS_GPH_MFPH_PH8_MFP_Pos 0                                                                        /*!< SYS GPH_MFPH: PH8_MFP Position */
#define SYS_GPH_MFPH_PH8_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH8_MFP_Pos)            /*!< SYS GPH_MFPH: PH8_MFP Mask  */

#define SYS_GPH_MFPH_PH9_MFP_Pos 4                                                                        /*!< SYS GPH_MFPH: PH9_MFP Position */
#define SYS_GPH_MFPH_PH9_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH9_MFP_Pos)            /*!< SYS GPH_MFPH: PH9_MFP Mask  */

#define SYS_GPH_MFPH_PH10_MFP_Pos 8                                                                        /*!< SYS GPH_MFPH: PH10_MFP Position */
#define SYS_GPH_MFPH_PH10_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH10_MFP_Pos)        /*!< SYS GPH_MFPH: PH10_MFP Mask */

#define SYS_GPH_MFPH_PH11_MFP_Pos 12                                                                    /*!< SYS GPH_MFPH: PH11_MFP Position */
#define SYS_GPH_MFPH_PH11_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH11_MFP_Pos)        /*!< SYS GPH_MFPH: PH11_MFP Mask */

#define SYS_GPH_MFPH_PH12_MFP_Pos 16                                                                    /*!< SYS GPH_MFPH: PH12_MFP Position */
#define SYS_GPH_MFPH_PH12_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH12_MFP_Pos)        /*!< SYS GPH_MFPH: PH12_MFP Mask */

#define SYS_GPH_MFPH_PH13_MFP_Pos 20                                                                    /*!< SYS GPH_MFPH: PH13_MFP Position */
#define SYS_GPH_MFPH_PH13_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH13_MFP_Pos)        /*!< SYS GPH_MFPH: PH13_MFP Mask */

#define SYS_GPH_MFPH_PH14_MFP_Pos 24                                                                    /*!< SYS GPH_MFPH: PH14_MFP Position */
#define SYS_GPH_MFPH_PH14_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH14_MFP_Pos)        /*!< SYS GPH_MFPH: PH14_MFP Mask */

#define SYS_GPH_MFPH_PH15_MFP_Pos 28                                                                    /*!< SYS GPH_MFPH: PH15_MFP Position */
#define SYS_GPH_MFPH_PH15_MFP_Msk    (0xFul<<SYS_GPH_MFPH_PH15_MFP_Pos)        /*!< SYS GPH_MFPH: PH15_MFP Mask */

/* SYS GPI_MFPL Bit Field Definitions */
#define SYS_GPI_MFPL_PI0_MFP_Pos 0                                                                        /*!< SYS GPI_MFPL: PI0_MFP Position */
#define SYS_GPI_MFPL_PI0_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI0_MFP_Pos)            /*!< SYS GPI_MFPL: PI0_MFP Mask  */

#define SYS_GPI_MFPL_PI1_MFP_Pos 4                                                                        /*!< SYS GPI_MFPL: PI1_MFP Position */
#define SYS_GPI_MFPL_PI1_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI1_MFP_Pos)            /*!< SYS GPI_MFPL: PI1_MFP Mask  */

#define SYS_GPI_MFPL_PI2_MFP_Pos 8                                                                        /*!< SYS GPI_MFPL: PI2_MFP Position */
#define SYS_GPI_MFPL_PI2_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI2_MFP_Pos)            /*!< SYS GPI_MFPL: PI2_MFP Mask */

#define SYS_GPI_MFPL_PI3_MFP_Pos 12                                                                        /*!< SYS GPI_MFPL: PI3_MFP Position */
#define SYS_GPI_MFPL_PI3_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI3_MFP_Pos)            /*!< SYS GPI_MFPL: PI3_MFP Mask */

#define SYS_GPI_MFPL_PI4_MFP_Pos 16                                                                        /*!< SYS GPI_MFPL: PI4_MFP Position */
#define SYS_GPI_MFPL_PI4_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI4_MFP_Pos)            /*!< SYS GPI_MFPL: PI4_MFP Mask */

#define SYS_GPI_MFPL_PI5_MFP_Pos 20                                                                        /*!< SYS GPI_MFPL: PI5_MFP Position */
#define SYS_GPI_MFPL_PI5_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI5_MFP_Pos)            /*!< SYS GPI_MFPL: PI5_MFP Mask */

#define SYS_GPI_MFPL_PI6_MFP_Pos 24                                                                        /*!< SYS GPI_MFPL: PI6_MFP Position */
#define SYS_GPI_MFPL_PI6_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI6_MFP_Pos)            /*!< SYS GPI_MFPL: PI6_MFP Mask */

#define SYS_GPI_MFPL_PI7_MFP_Pos 28                                                                        /*!< SYS GPI_MFPL: PI7_MFP Position */
#define SYS_GPI_MFPL_PI7_MFP_Msk    (0xFul<<SYS_GPI_MFPL_PI7_MFP_Pos)            /*!< SYS GPI_MFPL: PI7_MFP Mask */

/* SYS GPI_MFPH Bit Field Definitions */
#define SYS_GPI_MFPH_PI8_MFP_Pos 0                                                                        /*!< SYS GPI_MFPH: PI8_MFP Position */
#define SYS_GPI_MFPH_PI8_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI8_MFP_Pos)            /*!< SYS GPI_MFPH: PI8_MFP Mask  */

#define SYS_GPI_MFPH_PI9_MFP_Pos 4                                                                        /*!< SYS GPI_MFPH: PI9_MFP Position */
#define SYS_GPI_MFPH_PI9_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI9_MFP_Pos)            /*!< SYS GPI_MFPH: PI9_MFP Mask  */

#define SYS_GPI_MFPH_PI10_MFP_Pos 8                                                                        /*!< SYS GPI_MFPH: PI10_MFP Position */
#define SYS_GPI_MFPH_PI10_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI10_MFP_Pos)        /*!< SYS GPI_MFPH: PI10_MFP Mask */

#define SYS_GPI_MFPH_PI11_MFP_Pos 12                                                                    /*!< SYS GPI_MFPH: PI11_MFP Position */
#define SYS_GPI_MFPH_PI11_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI11_MFP_Pos)        /*!< SYS GPI_MFPH: PI11_MFP Mask */

#define SYS_GPI_MFPH_PI12_MFP_Pos 16                                                                    /*!< SYS GPI_MFPH: PI12_MFP Position */
#define SYS_GPI_MFPH_PI12_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI12_MFP_Pos)        /*!< SYS GPI_MFPH: PI12_MFP Mask */

#define SYS_GPI_MFPH_PI13_MFP_Pos 20                                                                    /*!< SYS GPI_MFPH: PI13_MFP Position */
#define SYS_GPI_MFPH_PI13_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI13_MFP_Pos)        /*!< SYS GPI_MFPH: PI13_MFP Mask */

#define SYS_GPI_MFPH_PI14_MFP_Pos 24                                                                    /*!< SYS GPI_MFPH: PI14_MFP Position */
#define SYS_GPI_MFPH_PI14_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI14_MFP_Pos)        /*!< SYS GPI_MFPH: PI14_MFP Mask */

#define SYS_GPI_MFPH_PI15_MFP_Pos 28                                                                    /*!< SYS GPI_MFPH: PI15_MFP Position */
#define SYS_GPI_MFPH_PI15_MFP_Msk    (0xFul<<SYS_GPI_MFPH_PI15_MFP_Pos)        /*!< SYS GPI_MFPH: PI15_MFP Mask */

/* SYS SRAMFINTCR Bit Field Definitions */
#define SYS_SRAMFINTCR_SRAMFINTEN_Pos 0                                                                            /*!< SYS SRAMFINTCR: SRAMFINTEN Position */
#define SYS_SRAMFINTCR_SRAMFINTEN_Msk    (1ul<<SYS_SRAMFINTCR_SRAMFINTEN_Pos)        /*!< SYS SRAMFINTCR: SRAMFINTEN Mask */

/* SYS SRAMF Bit Field Definitions */
#define SYS_SRAMF_SRAMF0_Pos 0                                                                                /*!< SYS SRAMF: SRAMF0 Position */
#define SYS_SRAMF_SRAMF0_Msk    (1ul<<SYS_SRAMF_SRAMF0_Pos)                                /*!< SYS SRAMF: SRAMF0 Mask */

#define SYS_SRAMF_SRAMF1_Pos 1                                                                                /*!< SYS SRAMF: SRAMF1 Position */
#define SYS_SRAMF_SRAMF1_Msk    (1ul<<SYS_SRAMF_SRAMF1_Pos)                                /*!< SYS SRAMF: SRAMF1 Mask */

/* SYS SRAMF_ADDR Bit Field Definitions */
#define SYS_SRAM0F_ADDR_SRAM0F_ADDR_Pos 0                                                                                                /*!< SYS SRAM0F_ADDR: SRAM0F_ADDR Position */
#define SYS_SRAM0F_ADDR_SRAM0F_ADDR_Msk    (0xFFFFFFFFul<<SYS_SRAM0F_ADDR_SRAM0F_ADDR_Pos)        /*!< SYS SRAM0F_ADDR: SRAM0F_ADDR Mask */

/* SYS SRAMF_ADDR2 Bit Field Definitions */
#define SYS_SRAM1F_ADDR_SRAM1F_ADDR_Pos 0                                                                                                /*!< SYS SRAM1F_ADDR: SRAM1F_ADDR Position */
#define SYS_SRAM1F_ADDR_SRAM1F_ADDR_Msk    (0xFFFFFFFFul<<SYS_SRAM1F_ADDR_SRAM1F_ADDR_Pos)        /*!< SYS SRAM1F_ADDR: SRAM1F_ADDR Mask */

/* SYS IRCTRIMCTL Bit Field Definitions */
#define SYS_IRCTRIMCTL_TRIM_SEL_Pos 0                                                                                                    /*!< SYS IRCTRIMCTL: TRIM_SEL Position */
#define SYS_IRCTRIMCTL_TRIM_SEL_Msk    (0x3ul<<SYS_IRCTRIMCTL_TRIM_SEL_Pos)                                /*!< SYS IRCTRIMCTL: TRIM_SEL Mask */

#define SYS_IRCTRIMCTL_TRIM_LOOP_Pos 4                                                                                                /*!< SYS IRCTRIMCTL: TRIM_LOOP Position */
#define SYS_IRCTRIMCTL_TRIM_LOOP_Msk    (0x3ul<<SYS_IRCTRIMCTL_TRIM_LOOP_Pos)                            /*!< SYS IRCTRIMCTL: TRIM_LOOP Mask */

#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos 6                                                                                        /*!< SYS IRCTRIMCTL: TRIM_RETRY_CNT Position */
#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Msk    (0x3ul<<SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos)        /*!< SYS IRCTRIMCTL: TRIM_RETRY_CNT Mask */

#define SYS_IRCTRIMCTL_CLKERR_STOP_EN_Pos 8                                                                                        /*!< SYS IRCTRIMCTL: CLKERR_STOP_EN Position */
#define SYS_IRCTRIMCTL_CLKERR_STOP_EN_Msk    (1ul<<SYS_IRCTRIMCTL_CLKERR_STOP_EN_Pos)            /*!< SYS IRCTRIMCTL: CLKERR_STOP_EN Mask */
/* SYS IRCTRIMIEN Bit Field Definitions */
#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos 1                                                                                        /*!< SYS IRCTRIMIEN: TRIM_FAIL_IEN Position */
#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Msk    (1ul<<SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos)                /*!< SYS IRCTRIMIEN: TRIM_FAIL_IEN Mask */

#define SYS_IRCTRIMIEN_CLKERR_IEN_Pos 2                                                                                                /*!< SYS IRCTRIMIEN: CLKERR_IEN Position */
#define SYS_IRCTRIMIEN_CLKERR_IEN_Msk    (1ul<<SYS_IRCTRIMIEN_CLKERR_IEN_Pos)                            /*!< SYS IRCTRIMIEN: CLKERR_IEN Mask */

/* SYS IRCTRIMINT Bit Field Definitions */
#define SYS_IRCTRIMINT_FREQ_LOCK_Pos 0                                                                                                /*!< SYS IRCTRIMINT: FREQ_LOCK Position */
#define SYS_IRCTRIMINT_FREQ_LOCK_Msk    (1ul<<SYS_IRCTRIMINT_FREQ_LOCK_Pos)                                /*!< SYS IRCTRIMINT: FREQ_LOCK Mask */

#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos 1                                                                                        /*!< SYS IRCTRIMINT: TRIM_FAIL_INT Position */
#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Msk    (1ul<<SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos)                /*!< SYS IRCTRIMINT: TRIM_FAIL_INT Mask */

#define SYS_IRCTRIMINT_CLKERR_INT_Pos 2                                                                                                /*!< SYS IRCTRIMINT: CLKERR_INT Position */
#define SYS_IRCTRIMINT_CLKERR_INT_Msk    (1ul<<SYS_IRCTRIMINT_CLKERR_INT_Pos)                            /*!< SYS IRCTRIMINT: CLKERR_INT Mask */

/* SYS REGWRPROT Bit Field Definitions */
#define SYS_REGWRPROT_REGPROTDIS_Pos 0                                                                                                /*!< SYS REGWRPROT: REGPROTDIS Position */
#define SYS_REGWRPROT_REGPROTDIS_Msk    (1ul<<SYS_REGWRPROT_REGPROTDIS_Pos)                            /*!< SYS REGWRPROT: REGPROTDIS Mask */

#define SYS_REGWRPROT_REGWRPROT_Pos 1                                                                                                /*!< SYS REGWRPROT: REGWRPROT Position */
#define SYS_REGWRPROT_REGWRPROT_Msk    (0x7Ful<<SYS_REGWRPROT_REGWRPROT_Pos)                            /*!< SYS REGWRPROT: REGWRPROT Mask */


/*@}*/ /* end of group NUC400_GCR */


/*------------- Clock Control Register (CLK) -----------------------------*/
/** @addtogroup NUC400_CLK NUC400 Clock Control Register (CLK)
  @{
*/
typedef struct {
    __IO uint32_t PWRCON;                        /*!< Offset: 0x0000   System Power Down Register                          */
    __IO uint32_t AHBCLK;                        /*!< Offset: 0x0004   AHB Devices Clock Enable Control Register          */
    __IO uint32_t APBCLK0;                    /*!< Offset: 0x0008   APB Devices Clock Enable Control Register          */
    __IO uint32_t APBCLK1;                    /*!< Offset: 0x000C   APB Devices Clock Enable Control Register 1        */
    __IO uint32_t CLKSEL0;                    /*!< Offset: 0x0010   Clock Source Select Control Register 0             */
    __IO uint32_t CLKSEL1;                    /*!< Offset: 0x0014   Clock Source Select Control Register 1             */
    __IO uint32_t CLKSEL2;                    /*!< Offset: 0x0018   Clock Source Select Control Register 2             */
    __IO uint32_t CLKSEL3;                    /*!< Offset: 0x001C   Clock Source Select Control Register 3             */
    __IO uint32_t CLKDIV0;                    /*!< Offset: 0x0020   Clock Divider Number Register    0                     */
    __IO uint32_t CLKDIV1;                    /*!< Offset: 0x0024   Clock Divider Number Register    1                     */
    __IO uint32_t CLKDIV2;                    /*!< Offset: 0x0028   Clock Divider Number Register    2                     */
    __IO uint32_t CLKDIV3;                    /*!< Offset: 0x002C   Clock Divider Number Register    3                     */
    uint32_t RESERVED0[4];                /*!< Offset: 0x0030 ~ 0x003C  Reserved                                   */
    __IO uint32_t PLLCON;                        /*!< Offset: 0x0040   PLL Control Register                                 */
    __IO uint32_t PLL2CON;                    /*!< Offset: 0x0044   PLL2 Control Register                                 */
    uint32_t RESERVED1[2];                /*!< Offset: 0x0048 ~ 0x004C  Reserved                                   */
    __IO uint32_t CLKSTATUS;                    /*!< Offset: 0x0050   Clock Status Monitor Register                      */
    uint32_t RESERVED2[3];                /*!< Offset: 0x0054 ~ 0x005C  Reserved                                   */
    __IO uint32_t FRQDIV;                        /*!< Offset: 0x0060   Frequency Divider Control Register                 */
    uint32_t RESERVED3[3];                /*!< Offset: 0x0064 ~ 0x006C  Reserved                                   */
    __IO uint32_t CLKFCR;                           /*!< Offset: 0x0070   Clock Stop Detector Control Register               */
    uint32_t RESERVED4[31];                /*!< Offset: 0x0074 ~ 0x00EC  Reserved                                   */
    __IO uint32_t CLKTRIM;                        /*!< Offset: 0x00F0   TRIM control  register                             */
} CLK_T;

/* CLK PWRCON Bit Field Definitions */
#define CLK_PWRCON_HXT_EN_Pos    0                                          /*!< CLK PWRCON: XTL12M_EN Position */
#define CLK_PWRCON_HXT_EN_Msk    (1ul<<CLK_PWRCON_HXT_EN_Pos)              /*!< CLK PWRCON: XTL12M_EN Mask */

#define CLK_PWRCON_LXT_EN_Pos    1                                          /*!< CLK PWRCON: XTL32K_EN Position */
#define CLK_PWRCON_LXT_EN_Msk    (1ul<<CLK_PWRCON_LXT_EN_Pos)              /*!< CLK PWRCON: XTL32K_EN Mask */

#define CLK_PWRCON_HIRC_EN_Pos    2                                          /*!< CLK PWRCON: OSC22M_EN Position */
#define CLK_PWRCON_HIRC_EN_Msk    (1ul<<CLK_PWRCON_HIRC_EN_Pos)              /*!< CLK PWRCON: OSC22M_EN Mask */

#define CLK_PWRCON_LIRC_EN_Pos    3                                          /*!< CLK PWRCON: OSC10K_EN Position */
#define CLK_PWRCON_LIRC_EN_Msk    (1ul<<CLK_PWRCON_LIRC_EN_Pos)              /*!< CLK PWRCON: OSC10K_EN Mask */

#define CLK_PWRCON_PD_WU_DLY_Pos    4                                          /*!< CLK PWRCON: PD_WU_DLY Position */
#define CLK_PWRCON_PD_WU_DLY_Msk    (1ul<<CLK_PWRCON_PD_WU_DLY_Pos)              /*!< CLK PWRCON: PD_WU_DLY Mask */

#define CLK_PWRCON_PD_WU_INT_EN_Pos    5                                          /*!< CLK PWRCON: PD_WU_INT_EN Position */
#define CLK_PWRCON_PD_WU_INT_EN_Msk    (1ul<<CLK_PWRCON_PD_WU_INT_EN_Pos)          /*!< CLK PWRCON: PD_WU_INT_EN Mask */

#define CLK_PWRCON_PD_WU_STS_Pos    6                                          /*!< CLK PWRCON: PD_WU_STS Position */
#define CLK_PWRCON_PD_WU_STS_Msk    (1ul<<CLK_PWRCON_PD_WU_STS_Pos)              /*!< CLK PWRCON: PD_WU_STS Mask */

#define CLK_PWRCON_PWR_DOWN_EN_Pos    7                                          /*!< CLK PWRCON: PWR_DOWN_EN Position */
#define CLK_PWRCON_PWR_DOWN_EN_Msk    (1ul<<CLK_PWRCON_PWR_DOWN_EN_Pos)              /*!< CLK PWRCON: PWR_DOWN_EN Mask */

#define CLK_PWRCON_PD_WAIT_CPU_Pos    8                                          /*!< CLK PWRCON: PD_WAIT_CPU Position */
#define CLK_PWRCON_PD_WAIT_CPU_Msk    (1ul<<CLK_PWRCON_PD_WAIT_CPU_Pos)              /*!< CLK PWRCON: PD_WAIT_CPU Mask */

#define CLK_PWRCON_DBPDEN_Pos    9                                              /*!< CLK PWRCON: DBPDEN Position */
#define CLK_PWRCON_DBPDEN_Msk    (1ul<<CLK_PWRCON_DBPDEN_Pos)                      /*!< CLK PWRCON: DBPDEN Mask */
/* CLK AHBCLK Bit Field Definitions */
#define CLK_AHBCLK_PDMA_EN_Pos    1                                              /*!< CLK AHBCLK: PDMA_EN Position */
#define CLK_AHBCLK_PDMA_EN_Msk    (1ul<<CLK_AHBCLK_PDMA_EN_Pos)                      /*!< CLK AHBCLK: PDMA_EN Mask */

#define CLK_AHBCLK_ISP_EN_Pos    2                                              /*!< CLK AHBCLK: ISP_EN Position */
#define CLK_AHBCLK_ISP_EN_Msk    (1ul<<CLK_AHBCLK_ISP_EN_Pos)                      /*!< CLK AHBCLK: ISP_EN Mask */

#define CLK_AHBCLK_EBI_EN_Pos    3                                              /*!< CLK AHBCLK: EBI_EN Position */
#define CLK_AHBCLK_EBI_EN_Msk    (1ul<<CLK_AHBCLK_EBI_EN_Pos)                      /*!< CLK AHBCLK: EBI_EN Mask */

#define CLK_AHBCLK_USBH_EN_Pos    4                                              /*!< CLK AHBCLK: USBH_EN Position */
#define CLK_AHBCLK_USBH_EN_Msk    (1ul<<CLK_AHBCLK_USBH_EN_Pos)                      /*!< CLK AHBCLK: USBH_EN Mask */

#define CLK_AHBCLK_EMAC_EN_Pos    5                                              /*!< CLK AHBCLK: EMAC_EN Position */
#define CLK_AHBCLK_EMAC_EN_Msk    (1ul<<CLK_AHBCLK_EMAC_EN_Pos)                      /*!< CLK AHBCLK: EMAC_EN Mask */

#define CLK_AHBCLK_SD_EN_Pos    6                                              /*!< CLK AHBCLK: SD_EN Position */
#define CLK_AHBCLK_SD_EN_Msk    (1ul<<CLK_AHBCLK_SD_EN_Pos)                      /*!< CLK AHBCLK: SD_EN Mask */

#define CLK_AHBCLK_CRC_EN_Pos    7                                              /*!< CLK AHBCLK: CRC_EN Position */
#define CLK_AHBCLK_CRC_EN_Msk    (1ul<<CLK_AHBCLK_CRC_EN_Pos)                      /*!< CLK AHBCLK: CRC_EN Mask */

#define CLK_AHBCLK_CAP_EN_Pos    8                                              /*!< CLK AHBCLK: CAP_EN Position */
#define CLK_AHBCLK_CAP_EN_Msk    (1ul<<CLK_AHBCLK_CAP_EN_Pos)                      /*!< CLK AHBCLK: CAP_EN Mask */

#define CLK_AHBCLK_SENCLK_EN_Pos    9                                              /*!< CLK AHBCLK: SENCLK_EN Position */
#define CLK_AHBCLK_SENCLK_EN_Msk    (1ul<<CLK_AHBCLK_SENCLK_EN_Pos)                  /*!< CLK AHBCLK: SENCLK_EN Mask */

#define CLK_AHBCLK_UDC20_EN_Pos    10                                              /*!< CLK AHBCLK: UDC20_EN Position */
#define CLK_AHBCLK_UDC20_EN_Msk    (1ul<<CLK_AHBCLK_UDC20_EN_Pos)                  /*!< CLK AHBCLK: UDC20_EN Mask */

#define CLK_AHBCLK_CRYPTO_EN_Pos    12                                              /*!< CLK AHBCLK: CRYPTO_EN Position */
#define CLK_AHBCLK_CRYPTO_EN_Msk    (1ul<<CLK_AHBCLK_CRYPTO_EN_Pos)                  /*!< CLK AHBCLK: CRYPTO_EN Mask */

/* CLK APBCLK0 Bit Field Definitions */
#define CLK_APBCLK0_WDT_EN_Pos    0                                              /*!< CLK APBCLK0: WDT_EN Position */
#define CLK_APBCLK0_WDT_EN_Msk    (1ul<<CLK_APBCLK0_WDT_EN_Pos)                      /*!< CLK APBCLK0: WDT_EN Mask */

#define CLK_APBCLK0_RTC_EN_Pos    1                                              /*!< CLK APBCLK0: RTC_EN Position */
#define CLK_APBCLK0_RTC_EN_Msk    (1ul<<CLK_APBCLK0_RTC_EN_Pos)                      /*!< CLK APBCLK0: RTC_EN Mask */

#define CLK_APBCLK0_TMR0_EN_Pos    2                                              /*!< CLK APBCLK0: TMR0_EN Position */
#define CLK_APBCLK0_TMR0_EN_Msk    (1ul<<CLK_APBCLK0_TMR0_EN_Pos)                      /*!< CLK APBCLK0: TMR0_EN Mask */

#define CLK_APBCLK0_TMR1_EN_Pos    3                                              /*!< CLK APBCLK0: TMR1_EN Position */
#define CLK_APBCLK0_TMR1_EN_Msk    (1ul<<CLK_APBCLK0_TMR1_EN_Pos)                      /*!< CLK APBCLK0: TMR1_EN Mask */

#define CLK_APBCLK0_TMR2_EN_Pos    4                                              /*!< CLK APBCLK0: TMR2_EN Position */
#define CLK_APBCLK0_TMR2_EN_Msk    (1ul<<CLK_APBCLK0_TMR2_EN_Pos)                      /*!< CLK APBCLK0: TMR2_EN Mask */

#define CLK_APBCLK0_TMR3_EN_Pos    5                                              /*!< CLK APBCLK0: TMR3_EN Position */
#define CLK_APBCLK0_TMR3_EN_Msk    (1ul<<CLK_APBCLK0_TMR3_EN_Pos)                      /*!< CLK APBCLK0: TMR3_EN Mask */

#define CLK_APBCLK0_FDIV_EN_Pos    6                                              /*!< CLK APBCLK0: FDIV_EN Position */
#define CLK_APBCLK0_FDIV_EN_Msk    (1ul<<CLK_APBCLK0_FDIV_EN_Pos)                      /*!< CLK APBCLK0: FDIV_EN Mask */

#define CLK_APBCLK0_ACMP_EN_Pos    7                                              /*!< CLK APBCLK0: ACMP_EN Position */
#define CLK_APBCLK0_ACMP_EN_Msk    (1ul<<CLK_APBCLK0_ACMP_EN_Pos)                      /*!< CLK APBCLK0: ACMP_EN Mask */

#define CLK_APBCLK0_I2C0_EN_Pos    8                                              /*!< CLK APBCLK0: I2C0_EN Position */
#define CLK_APBCLK0_I2C0_EN_Msk    (1ul<<CLK_APBCLK0_I2C0_EN_Pos)                      /*!< CLK APBCLK0: I2C0_EN Mask */

#define CLK_APBCLK0_I2C1_EN_Pos    9                                              /*!< CLK APBCLK0: I2C1_EN Position */
#define CLK_APBCLK0_I2C1_EN_Msk    (1ul<<CLK_APBCLK0_I2C1_EN_Pos)                      /*!< CLK APBCLK0: I2C1_EN Mask */

#define CLK_APBCLK0_I2C2_EN_Pos    10                                              /*!< CLK APBCLK0: I2C2_EN Position */
#define CLK_APBCLK0_I2C2_EN_Msk    (1ul<<CLK_APBCLK0_I2C2_EN_Pos)                      /*!< CLK APBCLK0: I2C2_EN Mask */

#define CLK_APBCLK0_I2C3_EN_Pos    11                                              /*!< CLK APBCLK0: I2C3_EN Position */
#define CLK_APBCLK0_I2C3_EN_Msk    (1ul<<CLK_APBCLK0_I2C3_EN_Pos)                      /*!< CLK APBCLK0: I2C3_EN Mask */

#define CLK_APBCLK0_SPI0_EN_Pos    12                                              /*!< CLK APBCLK0: SPI0_EN Position */
#define CLK_APBCLK0_SPI0_EN_Msk    (1ul<<CLK_APBCLK0_SPI0_EN_Pos)                      /*!< CLK APBCLK0: SPI0_EN Mask */

#define CLK_APBCLK0_SPI1_EN_Pos    13                                              /*!< CLK APBCLK0: SPI1_EN Position */
#define CLK_APBCLK0_SPI1_EN_Msk    (1ul<<CLK_APBCLK0_SPI1_EN_Pos)                      /*!< CLK APBCLK0: SPI1_EN Mask */

#define CLK_APBCLK0_SPI2_EN_Pos    14                                              /*!< CLK APBCLK0: SPI2_EN Position */
#define CLK_APBCLK0_SPI2_EN_Msk    (1ul<<CLK_APBCLK0_SPI2_EN_Pos)                      /*!< CLK APBCLK0: SPI2_EN Mask */

#define CLK_APBCLK0_SPI3_EN_Pos    15                                              /*!< CLK APBCLK0: SPI3_EN Position */
#define CLK_APBCLK0_SPI3_EN_Msk    (1ul<<CLK_APBCLK0_SPI3_EN_Pos)                      /*!< CLK APBCLK0: SPI3_EN Mask */

#define CLK_APBCLK0_UART0_EN_Pos    16                                              /*!< CLK APBCLK0: UART0_EN Position */
#define CLK_APBCLK0_UART0_EN_Msk    (1ul<<CLK_APBCLK0_UART0_EN_Pos)                      /*!< CLK APBCLK0: UART0_EN Mask */

#define CLK_APBCLK0_UART1_EN_Pos    17                                              /*!< CLK APBCLK0: UART1_EN Position */
#define CLK_APBCLK0_UART1_EN_Msk    (1ul<<CLK_APBCLK0_UART1_EN_Pos)                      /*!< CLK APBCLK0: UART1_EN Mask */

#define CLK_APBCLK0_UART2_EN_Pos    18                                              /*!< CLK APBCLK0: UART2_EN Position */
#define CLK_APBCLK0_UART2_EN_Msk    (1ul<<CLK_APBCLK0_UART2_EN_Pos)                      /*!< CLK APBCLK0: UART2_EN Mask */

#define CLK_APBCLK0_UART3_EN_Pos    19                                              /*!< CLK APBCLK0: UART3_EN Position */
#define CLK_APBCLK0_UART3_EN_Msk    (1ul<<CLK_APBCLK0_UART3_EN_Pos)                      /*!< CLK APBCLK0: UART3_EN Mask */

#define CLK_APBCLK0_UART4_EN_Pos    20                                              /*!< CLK APBCLK0: UART4_EN Position */
#define CLK_APBCLK0_UART4_EN_Msk    (1ul<<CLK_APBCLK0_UART4_EN_Pos)                      /*!< CLK APBCLK0: UART4_EN Mask */

#define CLK_APBCLK0_UART5_EN_Pos    21                                              /*!< CLK APBCLK0: UART5_EN Position */
#define CLK_APBCLK0_UART5_EN_Msk    (1ul<<CLK_APBCLK0_UART5_EN_Pos)                      /*!< CLK APBCLK0: UART5_EN Mask */

#define CLK_APBCLK0_CAN0_EN_Pos    24                                                  /*!< CLK APBCLK0: CAN0_EN Position */
#define CLK_APBCLK0_CAN0_EN_Msk    (1ul<<CLK_APBCLK0_CAN0_EN_Pos)                      /*!< CLK APBCLK0: CAN0_EN Mask */

#define CLK_APBCLK0_CAN1_EN_Pos    25                                              /*!< CLK APBCLK0: CAN1_EN Position */
#define CLK_APBCLK0_CAN1_EN_Msk    (1ul<<CLK_APBCLK0_CAN1_EN_Pos)                      /*!< CLK APBCLK0: CAN1_EN Mask */

#define CLK_APBCLK0_OTG_EN_Pos    26                                              /*!< CLK APBCLK0: OTG_EN Position */
#define CLK_APBCLK0_OTG_EN_Msk    (1ul<<CLK_APBCLK0_OTG_EN_Pos)                      /*!< CLK APBCLK0: OTG_EN Mask */

#define CLK_APBCLK0_ADC_EN_Pos    28                                              /*!< CLK APBCLK0: ADC_EN Position */
#define CLK_APBCLK0_ADC_EN_Msk    (1ul<<CLK_APBCLK0_ADC_EN_Pos)                      /*!< CLK APBCLK0: ADC_EN Mask */

#define CLK_APBCLK0_I2S0_EN_Pos    29                                              /*!< CLK APBCLK0: I2S0_EN Position */
#define CLK_APBCLK0_I2S0_EN_Msk    (1ul<<CLK_APBCLK0_I2S0_EN_Pos)                      /*!< CLK APBCLK0: I2S0_EN Mask */

#define CLK_APBCLK0_I2S1_EN_Pos    30                                              /*!< CLK APBCLK0: I2S1_EN Position */
#define CLK_APBCLK0_I2S1_EN_Msk    (1ul<<CLK_APBCLK0_I2S1_EN_Pos)                      /*!< CLK APBCLK0: I2S1_EN Mask */

#define CLK_APBCLK0_PS2_EN_Pos    31                                              /*!< CLK APBCLK0: PS2_EN Position */
#define CLK_APBCLK0_PS2_EN_Msk    (1ul<<CLK_APBCLK0_PS2_EN_Pos)                      /*!< CLK APBCLK0: PS2_EN Mask */


/* CLK APBCLK1 Bit Field Definitions */
#define CLK_APBCLK1_SC0_EN_Pos    0                                              /*!< CLK APBCLK1: SC0_EN Position */
#define CLK_APBCLK1_SC0_EN_Msk    (1ul<<CLK_APBCLK1_SC0_EN_Pos)                      /*!< CLK APBCLK1: SC0_EN Mask */

#define CLK_APBCLK1_SC1_EN_Pos    1                                              /*!< CLK APBCLK1: SC1_EN Position */
#define CLK_APBCLK1_SC1_EN_Msk    (1ul<<CLK_APBCLK1_SC1_EN_Pos)                      /*!< CLK APBCLK1: SC1_EN Mask */

#define CLK_APBCLK1_SC2_EN_Pos    2                                              /*!< CLK APBCLK1: SC2_EN Position */
#define CLK_APBCLK1_SC2_EN_Msk    (1ul<<CLK_APBCLK1_SC2_EN_Pos)                      /*!< CLK APBCLK1: SC2_EN Mask */

#define CLK_APBCLK1_SC3_EN_Pos    3                                              /*!< CLK APBCLK1: SC3_EN Position */
#define CLK_APBCLK1_SC3_EN_Msk    (1ul<<CLK_APBCLK1_SC3_EN_Pos)                      /*!< CLK APBCLK1: SC3_EN Mask */

#define CLK_APBCLK1_SC4_EN_Pos    4                                              /*!< CLK APBCLK1: SC4_EN Position */
#define CLK_APBCLK1_SC4_EN_Msk    (1ul<<CLK_APBCLK1_SC4_EN_Pos)                      /*!< CLK APBCLK1: SC4_EN Mask */

#define CLK_APBCLK1_SC5_EN_Pos    5                                              /*!< CLK APBCLK1: SC5_EN Position */
#define CLK_APBCLK1_SC5_EN_Msk    (1ul<<CLK_APBCLK1_SC5_EN_Pos)                      /*!< CLK APBCLK1: SC5_EN Mask */

#define CLK_APBCLK1_I2C4_EN_Pos    8                                              /*!< CLK APBCLK1: I2C4_EN Position */
#define CLK_APBCLK1_I2C4_EN_Msk    (1ul<<CLK_APBCLK1_I2C4_EN_Pos)                      /*!< CLK APBCLK1: I2C4_EN Mask */

#define CLK_APBCLK1_PWM0CH01_EN_Pos    16                                              /*!< CLK APBCLK1: PWM0CH01_EN Position */
#define CLK_APBCLK1_PWM0CH01_EN_Msk    (1ul<<CLK_APBCLK1_PWM0CH01_EN_Pos)                      /*!< CLK APBCLK1: PWM0CH01_EN Mask */

#define CLK_APBCLK1_PWM0CH23_EN_Pos    17                                              /*!< CLK APBCLK1: PWM0CH23_EN Position */
#define CLK_APBCLK1_PWM0CH23_EN_Msk    (1ul<<CLK_APBCLK1_PWM0CH23_EN_Pos)                      /*!< CLK APBCLK1: PWM0CH23_EN Mask */

#define CLK_APBCLK1_PWM0CH45_EN_Pos    18                                              /*!< CLK APBCLK1: PWM0CH45_EN Position */
#define CLK_APBCLK1_PWM0CH45_EN_Msk    (1ul<<CLK_APBCLK1_PWM0CH45_EN_Pos)                      /*!< CLK APBCLK1: PWM0CH45_EN Mask */

#define CLK_APBCLK1_PWM1CH01_EN_Pos    19                                              /*!< CLK APBCLK1: PWM1CH01_EN Position */
#define CLK_APBCLK1_PWM1CH01_EN_Msk    (1ul<<CLK_APBCLK1_PWM1CH01_EN_Pos)                      /*!< CLK APBCLK1: PWM1CH01_EN Mask */

#define CLK_APBCLK1_PWM1CH23_EN_Pos    20                                              /*!< CLK APBCLK1: PWM1CH23_EN Position */
#define CLK_APBCLK1_PWM1CH23_EN_Msk    (1ul<<CLK_APBCLK1_PWM1CH23_EN_Pos)                      /*!< CLK APBCLK1: PWM1CH23_EN Mask */

#define CLK_APBCLK1_PWM1CH45_EN_Pos    21                                              /*!< CLK APBCLK1: PWM1CH45_EN Position */
#define CLK_APBCLK1_PWM1CH45_EN_Msk    (1ul<<CLK_APBCLK1_PWM1CH45_EN_Pos)                      /*!< CLK APBCLK1: PWM1CH45_EN Mask */

#define CLK_APBCLK1_QEI0_EN_Pos    22                                              /*!< CLK APBCLK1: QEI0_EN Position */
#define CLK_APBCLK1_QEI0_EN_Msk    (1ul<<CLK_APBCLK1_QEI0_EN_Pos)                      /*!< CLK APBCLK1: QEI0_EN Mask */

#define CLK_APBCLK1_QEI1_EN_Pos    23                                              /*!< CLK APBCLK1: QEI1_EN Position */
#define CLK_APBCLK1_QEI1_EN_Msk    (1ul<<CLK_APBCLK1_QEI1_EN_Pos)                      /*!< CLK APBCLK1: QEI1_EN Mask */

#define CLK_APBCLK1_TAMPER_EN_Pos    24                                              /*!< CLK APBCLK1: TAMPER_EN Position */
#define CLK_APBCLK1_TAMPER_EN_Msk    (1ul<<CLK_APBCLK1_TAMPER_EN_Pos)                      /*!< CLK APBCLK1: TAMPER_EN Mask */

#define CLK_APBCLK1_ECAP0_EN_Pos    26                                              /*!< CLK APBCLK1: ECAP0_EN Position */
#define CLK_APBCLK1_ECAP0_EN_Msk    (1ul<<CLK_APBCLK1_ECAP0_EN_Pos)                      /*!< CLK APBCLK1: ECAP0_EN Mask */

#define CLK_APBCLK1_ECAP1_EN_Pos    27                                              /*!< CLK APBCLK1: ECAP1_EN Position */
#define CLK_APBCLK1_ECAP1_EN_Msk    (1ul<<CLK_APBCLK1_ECAP1_EN_Pos)                      /*!< CLK APBCLK1: ECAP1_EN Mask */

#define CLK_APBCLK1_EPWM0_EN_Pos    28                                              /*!< CLK APBCLK1: EPWM0_EN Position */
#define CLK_APBCLK1_EPWM0_EN_Msk    (1ul<<CLK_APBCLK1_EPWM0_EN_Pos)                      /*!< CLK APBCLK1: EPWM0_EN Mask */

#define CLK_APBCLK1_EPWM1_EN_Pos    29                                              /*!< CLK APBCLK1: EPWM1_EN Position */
#define CLK_APBCLK1_EPWM1_EN_Msk    (1ul<<CLK_APBCLK1_EPWM1_EN_Pos)                      /*!< CLK APBCLK1: EPWM1_EN Mask */

#define CLK_APBCLK1_OPA_EN_Pos    30                                              /*!< CLK APBCLK1: OPA_EN Position */
#define CLK_APBCLK1_OPA_EN_Msk    (1ul<<CLK_APBCLK1_OPA_EN_Pos)                      /*!< CLK APBCLK1: OPA_EN Mask */

#define CLK_APBCLK1_EADC_EN_Pos    31                                              /*!< CLK APBCLK1: EADC_EN Position */
#define CLK_APBCLK1_EADC_EN_Msk    (1ul<<CLK_APBCLK1_EADC_EN_Pos)                      /*!< CLK APBCLK1: EADC_EN Mask */

/* CLK CLKSEL0 Bit Field Definitions */
#define CLK_CLKSEL0_HCLK_S_Pos    0                                              /*!< CLK CLKSEL0: HCLK_S Position */
#define CLK_CLKSEL0_HCLK_S_Msk    (0x7ul<<CLK_CLKSEL0_HCLK_S_Pos)                      /*!< CLK CLKSEL0: HCLK_S Mask */

#define CLK_CLKSEL0_STCLK_S_Pos    3                                              /*!< CLK CLKSEL0: STCLK_S Position */
#define CLK_CLKSEL0_STCLK_S_Msk    (0x7ul<<CLK_CLKSEL0_STCLK_S_Pos)                      /*!< CLK CLKSEL0: STCLK_S Mask */

#define CLK_CLKSEL0_PCLK_S_Pos    6                                              /*!< CLK CLKSEL0: PCLK_S Position */
#define CLK_CLKSEL0_PCLK_S_Msk    (1ul<<CLK_CLKSEL0_PCLK_S_Pos)                      /*!< CLK CLKSEL0: PCLK_S Mask */

#define CLK_CLKSEL0_USB_S_Pos    8                                              /*!< CLK CLKSEL0: USB_S Position */
#define CLK_CLKSEL0_USB_S_Msk    (1ul<<CLK_CLKSEL0_USB_S_Pos)                      /*!< CLK CLKSEL0: USB_S Mask */

#define CLK_CLKSEL0_EMAC_S_Pos    10                                              /*!< CLK CLKSEL0: EMAC_S Position */
#define CLK_CLKSEL0_EMAC_S_Msk    (1ul<<CLK_CLKSEL0_EMAC_S_Pos)                      /*!< CLK CLKSEL0: EMAC_S Mask */

#define CLK_CLKSEL0_CAP_S_Pos    16                                              /*!< CLK CLKSEL0: CAP_S Position */
#define CLK_CLKSEL0_CAP_S_Msk    (0x3ul<<CLK_CLKSEL0_CAP_S_Pos)                      /*!< CLK CLKSEL0: CAP_S Mask */

#define CLK_CLKSEL0_SDHOST_S_Pos    20                                              /*!< CLK CLKSEL0: SD_S Position */
#define CLK_CLKSEL0_SDHOST_S_Msk    (0x3ul<<CLK_CLKSEL0_SDHOST_S_Pos)                      /*!< CLK CLKSEL0: SDIO_S Mask */

/* CLK CLKSEL1 Bit Field Definitions */
#define CLK_CLKSEL1_WDT_S_Pos    0                                              /*!< CLK CLKSEL1: WDT_S Position */
#define CLK_CLKSEL1_WDT_S_Msk    (0x3ul<<CLK_CLKSEL1_WDT_S_Pos)                      /*!< CLK CLKSEL1: WDT_S Mask */

#define CLK_CLKSEL1_ADC_S_Pos    2                                              /*!< CLK CLKSEL1: ADC_S Position */
#define CLK_CLKSEL1_ADC_S_Msk    (0x3ul<<CLK_CLKSEL1_ADC_S_Pos)                      /*!< CLK CLKSEL1: ADC_S Mask */

#define CLK_CLKSEL1_SPI0_S_Pos    4                                              /*!< CLK CLKSEL1: SPI0_S Position */
#define CLK_CLKSEL1_SPI0_S_Msk    (1ul<<CLK_CLKSEL1_SPI0_S_Pos)                      /*!< CLK CLKSEL1: SPI0_S Mask */

#define CLK_CLKSEL1_SPI1_S_Pos    5                                              /*!< CLK CLKSEL1: SPI1_S Position */
#define CLK_CLKSEL1_SPI1_S_Msk    (1ul<<CLK_CLKSEL1_SPI1_S_Pos)                      /*!< CLK CLKSEL1: SPI1_S Mask */

#define CLK_CLKSEL1_SPI2_S_Pos    6                                              /*!< CLK CLKSEL1: SPI2_S Position */
#define CLK_CLKSEL1_SPI2_S_Msk    (1ul<<CLK_CLKSEL1_SPI2_S_Pos)                      /*!< CLK CLKSEL1: SPI2_S Mask */

#define CLK_CLKSEL1_SPI3_S_Pos    7                                              /*!< CLK CLKSEL1: SPI3_S Position */
#define CLK_CLKSEL1_SPI3_S_Msk    (1ul<<CLK_CLKSEL1_SPI3_S_Pos)                      /*!< CLK CLKSEL1: SPI3_S Mask */

#define CLK_CLKSEL1_TMR0_S_Pos    8                                              /*!< CLK CLKSEL1: TMR0_S Position */
#define CLK_CLKSEL1_TMR0_S_Msk    (0x7ul<<CLK_CLKSEL1_TMR0_S_Pos)                      /*!< CLK CLKSEL1: TMR0_S Mask */

#define CLK_CLKSEL1_TMR1_S_Pos    12                                              /*!< CLK CLKSEL1: TMR1_S Position */
#define CLK_CLKSEL1_TMR1_S_Msk    (0x7ul<<CLK_CLKSEL1_TMR1_S_Pos)                      /*!< CLK CLKSEL1: TMR1_S Mask */

#define CLK_CLKSEL1_TMR2_S_Pos    16                                              /*!< CLK CLKSEL1: TMR2_S Position */
#define CLK_CLKSEL1_TMR2_S_Msk    (0x7ul<<CLK_CLKSEL1_TMR2_S_Pos)                      /*!< CLK CLKSEL1: TMR2_S Mask */

#define CLK_CLKSEL1_TMR3_S_Pos    20                                              /*!< CLK CLKSEL1: TMR3_S Position */
#define CLK_CLKSEL1_TMR3_S_Msk    (0x7ul<<CLK_CLKSEL1_TMR3_S_Pos)                      /*!< CLK CLKSEL1: TMR3_S Mask */

#define CLK_CLKSEL1_UART_S_Pos    24                                              /*!< CLK CLKSEL1: UART_S Position */
#define CLK_CLKSEL1_UART_S_Msk    (0x3ul<<CLK_CLKSEL1_UART_S_Pos)                      /*!< CLK CLKSEL1: UART_S Mask */

#define CLK_CLKSEL1_FRQDIV_S_Pos    28                                              /*!< CLK CLKSEL1: FRQDIV_S Position */
#define CLK_CLKSEL1_FRQDIV_S_Msk    (0x3ul<<CLK_CLKSEL1_FRQDIV_S_Pos)                      /*!< CLK CLKSEL1: FRQDIV_S Mask */

#define CLK_CLKSEL1_WWDT_S_Pos    30                                              /*!< CLK CLKSEL1: WWDT_S Position */
#define CLK_CLKSEL1_WWDT_S_Msk    (0x3ul<<CLK_CLKSEL1_WWDT_S_Pos)                      /*!< CLK CLKSEL1: WWDT_S Mask */

/* CLK CLKSEL2 Bit Field Definitions */
#define CLK_CLKSEL2_PWM0CH01_S_Pos    0                                                  /*!< CLK CLKSEL2: PWM0CH01_S Position */
#define CLK_CLKSEL2_PWM0CH01_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM0CH01_S_Pos)                      /*!< CLK CLKSEL2: PWM0CH01_S Mask */

#define CLK_CLKSEL2_PWM0CH23_S_Pos    4                                                  /*!< CLK CLKSEL2: PWM0CH23_S Position */
#define CLK_CLKSEL2_PWM0CH23_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM0CH23_S_Pos)                      /*!< CLK CLKSEL2: PWM0CH23_S Mask */

#define CLK_CLKSEL2_PWM0CH45_S_Pos    8                                                  /*!< CLK CLKSEL2: PWM0CH45_S Position */
#define CLK_CLKSEL2_PWM0CH45_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM0CH45_S_Pos)                      /*!< CLK CLKSEL2: PWM0CH45_S Mask */

#define CLK_CLKSEL2_PWM1CH01_S_Pos    12                                                  /*!< CLK CLKSEL2: PWM1CH01_S Position */
#define CLK_CLKSEL2_PWM1CH01_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM1CH01_S_Pos)                      /*!< CLK CLKSEL2: PWM1CH01_S Mask */

#define CLK_CLKSEL2_PWM1CH23_S_Pos    16                                                  /*!< CLK CLKSEL2: PWM1CH23_S Position */
#define CLK_CLKSEL2_PWM1CH23_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM1CH23_S_Pos)                      /*!< CLK CLKSEL2: PWM1CH23_S Mask */

#define CLK_CLKSEL2_PWM1CH45_S_Pos    20                                                  /*!< CLK CLKSEL2: PWM1CH45_S Position */
#define CLK_CLKSEL2_PWM1CH45_S_Msk    (0x7ul<<CLK_CLKSEL2_PWM1CH45_S_Pos)                      /*!< CLK CLKSEL2: PWM1CH45_S Mask */

/* CLK CLKSEL3 Bit Field Definitions */
#define CLK_CLKSEL3_SC0_S_Pos    0                                                  /*!< CLK CLKSEL3: SC0_S Position */
#define CLK_CLKSEL3_SC0_S_Msk    (0x3ul<<CLK_CLKSEL3_SC0_S_Pos)                      /*!< CLK CLKSEL3: SC0_S Mask */

#define CLK_CLKSEL3_SC1_S_Pos    2                                                  /*!< CLK CLKSEL3: SC1_S Position */
#define CLK_CLKSEL3_SC1_S_Msk    (0x3ul<<CLK_CLKSEL3_SC1_S_Pos)                      /*!< CLK CLKSEL3: SC1_S Mask */

#define CLK_CLKSEL3_SC2_S_Pos    4                                                  /*!< CLK CLKSEL3: SC2_S Position */
#define CLK_CLKSEL3_SC2_S_Msk    (0x3ul<<CLK_CLKSEL3_SC2_S_Pos)                      /*!< CLK CLKSEL3: SC2_S Mask */

#define CLK_CLKSEL3_SC3_S_Pos    6                                                  /*!< CLK CLKSEL3: SC3_S Position */
#define CLK_CLKSEL3_SC3_S_Msk    (0x3ul<<CLK_CLKSEL3_SC3_S_Pos)                      /*!< CLK CLKSEL3: SC3_S Mask */

#define CLK_CLKSEL3_SC4_S_Pos    8                                                  /*!< CLK CLKSEL3: SC4_S Position */
#define CLK_CLKSEL3_SC4_S_Msk    (0x3ul<<CLK_CLKSEL3_SC4_S_Pos)                      /*!< CLK CLKSEL3: SC4_S Mask */

#define CLK_CLKSEL3_SC5_S_Pos    10                                                  /*!< CLK CLKSEL3: SC5_S Position */
#define CLK_CLKSEL3_SC5_S_Msk    (0x3ul<<CLK_CLKSEL3_SC5_S_Pos)                      /*!< CLK CLKSEL3: SC5_S Mask */

#define CLK_CLKSEL3_I2S_S_Pos    16                                                  /*!< CLK CLKSEL3: I2S_S Position */
#define CLK_CLKSEL3_I2S_S_Msk    (0x3ul<<CLK_CLKSEL3_I2S_S_Pos)                      /*!< CLK CLKSEL3: I2S_S Mask */

#define CLK_CLKSEL3_I2S1_S_Pos    18                                                  /*!< CLK CLKSEL3: I2S1_S Position */
#define CLK_CLKSEL3_I2S1_S_Msk    (0x3ul<<CLK_CLKSEL3_I2S1_S_Pos)                      /*!< CLK CLKSEL3: I2S1_S Mask */

/* CLK CLKDIV0 Bit Field Definitions */
#define CLK_CLKDIV0_HCLK_N_Pos    0                                                  /*!< CLK CLKDIV0: HCLK_N Position */
#define CLK_CLKDIV0_HCLK_N_Msk    (0xFul<<CLK_CLKDIV0_HCLK_N_Pos)                      /*!< CLK CLKDIV0: HCLK_N Mask */

#define CLK_CLKDIV0_USB_N_Pos    4                                                  /*!< CLK CLKDIV0: USB_N Position */
#define CLK_CLKDIV0_USB_N_Msk    (0xFul<<CLK_CLKDIV0_USB_N_Pos)                      /*!< CLK CLKDIV0: USB_N Mask */

#define CLK_CLKDIV0_UART_N_Pos    8                                                  /*!< CLK CLKDIV0: UART_N Position */
#define CLK_CLKDIV0_UART_N_Msk    (0xFul<<CLK_CLKDIV0_UART_N_Pos)                      /*!< CLK CLKDIV0: UART_N Mask */

#define CLK_CLKDIV0_ADC_N_Pos    16                                                  /*!< CLK CLKDIV0: ADC_N Position */
#define CLK_CLKDIV0_ADC_N_Msk    (0xFFul<<CLK_CLKDIV0_ADC_N_Pos)                      /*!< CLK CLKDIV0: ADC_N Mask */

#define CLK_CLKDIV0_SD_N_Pos    24                                                  /*!< CLK CLKDIV0: SD_N Position */
#define CLK_CLKDIV0_SD_N_Msk    (0xFFul<<CLK_CLKDIV0_SD_N_Pos)                      /*!< CLK CLKDIV0: SD_N Mask */

/* CLK CLKDIV1 Bit Field Definitions */
#define CLK_CLKDIV1_SC0_N_Pos    0                                                  /*!< CLK CLKDIV1: SC0_N Position */
#define CLK_CLKDIV1_SC0_N_Msk    (0xFFul<<CLK_CLKDIV1_SC0_N_Pos)                      /*!< CLK CLKDIV1: SC0_N Mask */

#define CLK_CLKDIV1_SC1_N_Pos    8                                                  /*!< CLK CLKDIV1: SC1_N Position */
#define CLK_CLKDIV1_SC1_N_Msk    (0xFFul<<CLK_CLKDIV1_SC1_N_Pos)                      /*!< CLK CLKDIV1: SC1_N Mask */

#define CLK_CLKDIV1_SC2_N_Pos    16                                                  /*!< CLK CLKDIV1: SC2_N Position */
#define CLK_CLKDIV1_SC2_N_Msk    (0xFFul<<CLK_CLKDIV1_SC2_N_Pos)                      /*!< CLK CLKDIV1: SC2_N Mask */

#define CLK_CLKDIV1_SC3_N_Pos    24                                                  /*!< CLK CLKDIV1: SC3_N Position */
#define CLK_CLKDIV1_SC3_N_Msk    (0xFFul<<CLK_CLKDIV1_SC3_N_Pos)                      /*!< CLK CLKDIV1: SC3_N Mask */


/* CLK CLKDIV2 Bit Field Definitions */
#define CLK_CLKDIV2_SC4_N_Pos    0                                                  /*!< CLK CLKDIV2: SC4_N Position */
#define CLK_CLKDIV2_SC4_N_Msk    (0xFFul<<CLK_CLKDIV2_SC4_N_Pos)                      /*!< CLK CLKDIV2: SC4_N Mask */

#define CLK_CLKDIV2_SC5_N_Pos    8                                                  /*!< CLK CLKDIV2: SC5_N Position */
#define CLK_CLKDIV2_SC5_N_Msk    (0xFFul<<CLK_CLKDIV2_SC5_N_Pos)                      /*!< CLK CLKDIV2: SC5_N Mask */

#define CLK_CLKDIV2_SD2_N_Pos    16                                                  /*!< CLK CLKDIV2: SD2_N Position */
#define CLK_CLKDIV2_SD2_N_Msk    (0xFFul<<CLK_CLKDIV2_SD2_N_Pos)                      /*!< CLK CLKDIV2: SD2_N Mask */

/* CLK CLKDIV3 Bit Field Definitions */
#define CLK_CLKDIV3_CAP_N_Pos    0                                                  /*!< CLK CLKDIV3: CAP_N Position */
#define CLK_CLKDIV3_CAP_N_Msk    (0xFFul<<CLK_CLKDIV3_CAP_N_Pos)                      /*!< CLK CLKDIV3: CAP_N Mask */

#define CLK_CLKDIV3_VASENSOR_N_Pos    8                                                  /*!< CLK CLKDIV3: VASENSOR_N Position */
#define CLK_CLKDIV3_VASENSOR_N_Msk    (0xFFul<<CLK_CLKDIV3_VASENSOR_N_Pos)                      /*!< CLK CLKDIV3: VASENSOR_N Mask */

#define CLK_CLKDIV3_EMAC_MDCLK_N_Pos    16                                                  /*!< CLK CLKDIV3: EMAC_MDCLK_N Position */
#define CLK_CLKDIV3_EMAC_MDCLK_N_Msk    (0xFFul<<CLK_CLKDIV3_EMAC_MDCLK_N_Pos)                      /*!< CLK CLKDIV3: EMAC_MDCLK_N Mask */

/* CLK PLLCON Bit Field Definitions */
#define CLK_PLLCON_PLL_remap_Pos               20                                      /*!< CLK PLLCON: PLL_remap Position */
#define CLK_PLLCON_PLL_remap_Msk               (1ul<< CLK_PLLCON_PLL_SRC_Pos)          /*!< CLK PLLCON: PLL_remap Mask */

#define CLK_PLLCON_PLL_SRC_Pos               19                                       /*!< CLK PLLCON: PLL_SRC Position */
#define CLK_PLLCON_PLL_SRC_Msk               (1ul<< CLK_PLLCON_PLL_SRC_Pos)          /*!< CLK PLLCON: PLL_SRC Mask */

#define CLK_PLLCON_OE_Pos                    18                                       /*!< CLK PLLCON: PLL_SRC Position */
#define CLK_PLLCON_OE_Msk                    (1ul<< CLK_PLLCON_OE_Pos)               /*!< CLK PLLCON: PLL_SRC Mask */

#define CLK_PLLCON_BP_Pos                    17                                       /*!< CLK PLLCON: OE Position */
#define CLK_PLLCON_BP_Msk                    (1ul<< CLK_PLLCON_BP_Pos)               /*!< CLK PLLCON: OE Mask */

#define CLK_PLLCON_PD_Pos                    16                                       /*!< CLK PLLCON: PD Position */
#define CLK_PLLCON_PD_Msk                    (1ul<< CLK_PLLCON_PD_Pos)               /*!< CLK PLLCON: PD Mask */

#define CLK_PLLCON_OUT_DV_Pos                14                                       /*!< CLK PLLCON: OUT_DV Position */
#define CLK_PLLCON_OUT_DV_Msk                (3ul<< CLK_PLLCON_OUT_DV_Pos)           /*!< CLK PLLCON: OUT_DV Mask */

#define CLK_PLLCON_IN_DV_Pos                 9                                        /*!< CLK PLLCON: IN_DV Position */
#define CLK_PLLCON_IN_DV_Msk                 (0x1Ful<< CLK_PLLCON_IN_DV_Pos)         /*!< CLK PLLCON: IN_DV Mask */

#define CLK_PLLCON_FB_DV_Pos                 0                                        /*!< CLK PLLCON: FB_DV Position */
#define CLK_PLLCON_FB_DV_Msk                 (0x1FFul<< CLK_PLLCON_FB_DV_Pos)        /*!< CLK PLLCON: FB_DV Mask */

/* CLK PLL2CON Bit Field Definitions */
#define CLK_PLL2CON_USBPLL_N_Pos                 0                                        /*!< CLK PLLCON2: USBPLL_N Position */
#define CLK_PLL2CON_USBPLL_N_Msk                 (0xFFul<< CLK_PLL2CON_USBPLL_N_Pos)        /*!< CLK PLLCON2: USBPLL_N Mask */

#define CLK_PLL2CON_USBPLL_EN_Pos                    8                                        /*!< CLK PLLCON2: USBPLL_EN Position */
#define CLK_PLL2CON_USBPLL_EN_Msk                    (0x1ul<< CLK_PLL2CON_USBPLL_EN_Pos)        /*!< CLK PLLCON2: USBPLL_EN Mask */


/* CLK CLKSTATUS Bit Field Definitions */
#define CLK_CLKSTATUS_HXT_STB_Pos                 0                                            /*!< CLK CLKSTATUS: XTL12M_STB Position */
#define CLK_CLKSTATUS_HXT_STB_Msk                 (1ul<< CLK_CLKSTATUS_HXT_STB_Pos)        /*!< CLK CLKSTATUS: XTL12M_STB Mask */

#define CLK_CLKSTATUS_LXT_STB_Pos                 1                                            /*!< CLK CLKSTATUS: XTL32K_STB Position */
#define CLK_CLKSTATUS_LXT_STB_Msk                 (1ul<< CLK_CLKSTATUS_LXT_STB_Pos)        /*!< CLK CLKSTATUS: XTL32K_STB Mask */

#define CLK_CLKSTATUS_PLL_STB_Pos                 2                                            /*!< CLK CLKSTATUS: PLL_STB Position */
#define CLK_CLKSTATUS_PLL_STB_Msk                 (1ul<< CLK_CLKSTATUS_PLL_STB_Pos)        /*!< CLK CLKSTATUS: PLL_STB Mask */

#define CLK_CLKSTATUS_LIRC_STB_Pos                 3                                            /*!< CLK CLKSTATUS: OSC10K_STB Position */
#define CLK_CLKSTATUS_LIRC_STB_Msk                 (1ul<< CLK_CLKSTATUS_LIRC_STB_Pos)        /*!< CLK CLKSTATUS: OSC10K_STB Mask */

#define CLK_CLKSTATUS_HIRC_STB_Pos                 4                                            /*!< CLK CLKSTATUS: OSC22M_STB Position */
#define CLK_CLKSTATUS_HIRC_STB_Msk                 (1ul<< CLK_CLKSTATUS_HIRC_STB_Pos)        /*!< CLK CLKSTATUS: OSC22M_STB Mask */

#define CLK_CLKSTATUS_PLL2_STB_Pos                 5                                            /*!< CLK CLKSTATUS: PLL2_STB Position */
#define CLK_CLKSTATUS_PLL2_STB_Msk                 (1ul<< CLK_CLKSTATUS_PLL2_STB_Pos)        /*!< CLK CLKSTATUS: PLL2_STB Mask */

#define CLK_CLKSTATUS_CLK_SW_FAIL_Pos                 7                                            /*!< CLK CLKSTATUS: CLK_SW_FAIL Position */
#define CLK_CLKSTATUS_CLK_SW_FAIL_Msk                 (1ul<< CLK_CLKSTATUS_CLK_SW_FAIL_Pos)        /*!< CLK CLKSTATUS: CLK_SW_FAIL Mask */

/* CLK FRQDIV Bit Field Definitions */
#define CLK_FRQDIV_DIVIDER1_Pos            5                                        /*!< CLK FRQDIV: DIVIDER1 Position */
#define CLK_FRQDIV_DIVIDER1_Msk            (1ul<< CLK_FRQDIV_DIVIDER1_Pos)       /*!< CLK FRQDIV: DIVIDER1 Mask */

#define CLK_FRQDIV_DIVIDER_EN_Pos            4                                        /*!< CLK FRQDIV: DIVIDER_EN Position */
#define CLK_FRQDIV_DIVIDER_EN_Msk            (1ul<< CLK_FRQDIV_DIVIDER_EN_Pos)       /*!< CLK FRQDIV: DIVIDER_EN Mask */

#define CLK_FRQDIV_FSEL_Pos                  0                                        /*!< CLK FRQDIV: FRQDIV_FSEL Position */
#define CLK_FRQDIV_FSEL_Msk                  (0xFul<< CLK_FRQDIV_FSEL_Pos)           /*!< CLK FRQDIV: FRQDIV_FSEL Mask */

/* CLK CLKFCR Bit Field Definitions */
#define CLK_CLKFCR_SYSC_DET_EN_Pos                  0                                        /*!< CLK CLKFCR: FRQDIV_SYSC_DET_EN Position */
#define CLK_CLKFCR_SYSC_DET_EN_Msk                  (0x1ul << CLK_CLKFCR_SYSC_DET_EN_Pos)           /*!< CLK CLKFCR: FRQDIV_SYSC_DET_EN Mask */

#define CLK_CLKFCR_SYSF_INT_EN_Pos                  1                                        /*!< CLK CLKFCR: FRQDIV_SYSF_INT_EN Position */
#define CLK_CLKFCR_SYSF_INT_EN_Msk                  (0x1ul << CLK_CLKFCR_SYSF_INT_EN_Pos)           /*!< CLK CLKFCR: FRQDIV_SYSF_INT_EN Mask */

#define CLK_CLKFCR_SYS_F_Pos                  2                                        /*!< CLK CLKFCR: FRQDIV_SYS_F Position */
#define CLK_CLKFCR_SYS_F_Msk                  (0x1ul << CLK_CLKFCR_SYS_F_Pos)           /*!< CLK CLKFCR: FRQDIV_SYS_F Mask */

#define CLK_CLKFCR_RC_DET_EN_Pos                  8                                        /*!< CLK CLKFCR: FRQDIV_RC_DET_EN Position */
#define CLK_CLKFCR_RC_DET_EN_Msk                  (0x1ul << CLK_CLKFCR_RC_DET_EN_Pos)           /*!< CLK CLKFCR: FRQDIV_RC_DET_EN Mask */

#define CLK_CLKFCR_IRC_INT_EN_Pos                  9                                        /*!< CLK CLKFCR: FRQDIV_IRC_INT_EN Position */
#define CLK_CLKFCR_IRC_INT_EN_Msk                  (0x1ul << CLK_CLKFCR_IRC_INT_EN_Pos)           /*!< CLK CLKFCR: FRQDIV_IRC_INT_EN Mask */

#define CLK_CLKFCR_IRC_F_Pos                  10                                       /*!< CLK CLKFCR: FRQDIV_IRC_F Position */
#define CLK_CLKFCR_IRC_F_Msk                  (0x1ul << CLK_CLKFCR_IRC_F_Pos)           /*!< CLK CLKFCR: FRQDIV_IRC_F Mask */

/* CLKDETCR Bit Field Definitions */
#define CLK_CLKDETCR_SYS_DET_EN_Pos     0                                                  /*!< CLK_CLKDETCR: System Clock Detector Enable */
#define CLK_CLKDETCR_SYS_DET_EN_Msk       (0x1ul << CLK_CLKDETCR_SYS_DET_EN_Pos)            /*!< CLK CLKDETCR: SYS_DET_EN Mask */
#define CLK_CLKDETCR_SYS_INT_EN_Pos     1                                                  /*!< CLK_CLKDETCR: System  Clock Detector Interrupt Enable */
#define CLK_CLKDETCR_SYS_INT_EN_Msk       (0x1ul << CLK_CLKDETCR_SYS_INT_EN_Pos)            /*!< CLK CLKDETCR: SYS_INT_EN Mask */
#define CLK_CLKDETCR_SYS_F_Pos             2                                                  /*!< CLK_CLKDETCR: System Clock Detect Fail Flag */
#define CLK_CLKDETCR_SYS_F_Msk           (0x1ul << CLK_CLKDETCR_SYS_F_Pos)                /*!< CLK CLKDETCR: SYS_F Mask */
#define CLK_CLKDETCR_IRC_DET_EN_Pos     8                                                  /*!< CLK_CLKDETCR: Internal RC Clock Detector Enable */
#define CLK_CLKDETCR_IRC_DET_EN_Msk       (0x1ul << CLK_CLKDETCR_IRC_DET_EN_Pos)            /*!< CLK CLKDETCR: IRC_DET_EN Mask */
#define CLK_CLKDETCR_IRC_INT_EN_Pos     9                                                  /*!< CLK_CLKDETCR: Internal RC Clock Detector Interrupt Enable */
#define CLK_CLKDETCR_IRC_INT_EN_Msk       (0x1ul << CLK_CLKDETCR_IRC_INT_EN_Pos)            /*!< CLK CLKDETCR: IRC_INT_EN Mask */
#define CLK_CLKDETCR_IRC_F_Pos             10                                              /*!< CLK_CLKDETCR: Internal RC Clock Fail Flag */
#define CLK_CLKDETCR_IRC_F_Msk           (0x1ul << CLK_CLKDETCR_IRC_F_Pos)                /*!< CLK CLKDETCR: IRC_F Mask */

/*@}*/ /* end of group NUC400_CLK */

/*------------- General Purpose I/O (GPIO) -----------------------------*/
/** @addtogroup NUC400_GPIO NUC400 General Purpose I/O (GPIO)
  @{
*/
typedef struct {
    __IO uint32_t PMD;                  /*!< Offset: 0x0000   GPIO Port Bit Mode Control                        */
    __IO uint32_t OFFD;                 /*!< Offset: 0x0004   GPIO Port Bit Off Digital Enable                  */
    __IO uint32_t DOUT;                 /*!< Offset: 0x0008   GPIO Port Data Output                             */
    __IO uint32_t DMASK;                /*!< Offset: 0x000C   GPIO Port Data Output Write Mask                  */
    __I  uint32_t PIN;                  /*!< Offset: 0x0010   GPIO Port Pin Value                               */
    __IO uint32_t DBEN;                 /*!< Offset: 0x0014   GPIO Port De-bounce Enable                        */
    __IO uint32_t IMD;                  /*!< Offset: 0x0018   GPIO Port Interrupt Mode Select                   */
    __IO uint32_t IEN;                  /*!< Offset: 0x001C   GPIO Port Interrupt Enable                        */
    __IO uint32_t ISRC;                 /*!< Offset: 0x0020   GPIO Port Interrupt Source Flag                   */
    __IO uint32_t TYPE;                 /*!< Offset: 0x0024   GPIO Port input Schmitt Trigger function          */
    __IO uint32_t HS;                   /*!< Offset: 0x0028   GPIO Higher Speed Control                         */

} GPIO_T;

typedef struct {
    __IO uint32_t DBNCECON;             /*!< Offset: 0x0000   Interrupt De-bounce Cycle Control                 */

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
#define GPIO_OFFD_OFFD_Pos          16                                          /*!< GPIO OFFD: OFFD Position */
#define GPIO_OFFD_OFFD_Msk          (0xFFFFul << GPIO_OFFD_OFFD_Pos)            /*!< GPIO OFFD: OFFD Mask */

/* GPIO DOUT Bit Field Definitions */
#define GPIO_DOUT_DOUT_Pos          0                                           /*!< GPIO DOUT: DOUT Position */
#define GPIO_DOUT_DOUT_Msk          (0xFFFFul << GPIO_DOUT_DOUT_Pos)            /*!< GPIO DOUT: DOUT Mask */

/* GPIO DMASK Bit Field Definitions */
#define GPIO_DMASK_DMASK_Pos        0                                           /*!< GPIO DMASK: DMASK Position */
#define GPIO_DMASK_DMASK_Msk        (0xFFFFul << GPIO_DMASK_DMASK_Pos)          /*!< GPIO DMASK: DMASK Mask */

/* GPIO PIN Bit Field Definitions */
#define GPIO_PIN_PIN_Pos            0                                           /*!< GPIO PIN: PIN Position */
#define GPIO_PIN_PIN_Msk            (0xFFFFul << GPIO_PIN_PIN_Pos)              /*!< GPIO PIN: PIN Mask */

/* GPIO DBEN Bit Field Definitions */
#define GPIO_DBEN_DBEN_Pos          0                                           /*!< GPIO DBEN: DBEN Position */
#define GPIO_DBEN_DBEN_Msk          (0xFFFFul << GPIO_DBEN_DBEN_Pos)            /*!< GPIO DBEN: DBEN Mask */

/* GPIO IMD Bit Field Definitions */
#define GPIO_IMD_IMD_Pos            0                                           /*!< GPIO IMD: IMD Position */
#define GPIO_IMD_IMD_Msk            (0xFFFFul << GPIO_IMD_IMD_Pos)              /*!< GPIO IMD: IMD Mask */

/* GPIO IEN Bit Field Definitions */
#define GPIO_IEN_IR_EN_Pos          16                                          /*!< GPIO IEN: IR_EN Position */
#define GPIO_IEN_IR_EN_Msk          (0xFFFFul << GPIO_IEN_IR_EN_Pos)            /*!< GPIO IEN: IR_EN Mask */

#define GPIO_IEN_IF_EN_Pos          0                                           /*!< GPIO IEN: IF_EN Position */
#define GPIO_IEN_IF_EN_Msk          (0xFFFFul << GPIO_IEN_IF_EN_Pos)            /*!< GPIO IEN: IF_EN Mask */

/* GPIO ISRC Bit Field Definitions */
#define GPIO_ISRC_ISRC_Pos         0                                            /*!< GPIO ISRC: ISRC Position */
#define GPIO_ISRC_ISRC_Msk         (0xFFFFul << GPIO_ISRC_ISRC_Pos)             /*!< GPIO ISRC: ISRC Mask */

/* GPIO TYPE Bit Field Definitions */
#define GPIO_TYPE_TYPE_Pos          0                                           /*!< GPIO TYPE: TYPE Position */
#define GPIO_TYPE_TYPEF_Msk         (0xFFFFul << GPIO_TYPE_TYPE_Pos)            /*!< GPIO TYPE: TYPE Mask */

/* GPIO HS Bit Field Definitions */
#define GPIO_HS_TYPE_Pos            0                                           /*!< GPIO HS: TYPE Position */
#define GPIO_HS_TYPEF_Msk           (0xFFFFul << GPIO_TYPE_TYPE_Pos)            /*!< GPIO HS: TYPE Mask */

/* GPIO DBNCECON Bit Field Definitions */
#define GPIO_DBNCECON_ICLK_ON_Pos   5                                           /*!< GPIO DBNCECON: ICLK_ON  Position */
#define GPIO_DBNCECON_ICLK_ON_Msk   (1ul << GPIO_DBNCECON_ICLK_ON_Pos)          /*!< GPIO DBNCECON: ICLK_ON  Mask */

#define GPIO_DBNCECON_DBCLKSRC_Pos  4                                           /*!< GPIO DBNCECON: DBCLKSRC Position */
#define GPIO_DBNCECON_DBCLKSRC_Msk  (1ul << GPIO_DBNCECON_DBCLKSRC_Pos)         /*!< GPIO DBNCECON: DBCLKSRC Mask */

#define GPIO_DBNCECON_DBCLKSEL_Pos  0                                           /*!< GPIO DBNCECON: DBCLKSEL Position */
#define GPIO_DBNCECON_DBCLKSEL_Msk  (0xFul << GPIO_DBNCECON_DBCLKSEL_Pos)       /*!< GPIO DBNCECON: DBCLKSEL Mask */
/*@}*/ /* end of group NUC400_GPIO */


/*------------- CRC Control Register (CRC) -----------------------------*/
/** @addtogroup NUC400_CRC NUC400 CRC Control Register (CRC)
  @{
*/
typedef struct {
    __IO uint32_t  CTL;                          /*!< Offset: 0x0000   CRC Control Register */
    __IO uint32_t  WDATA;                        /*!< Offset: 0x0004   CRC Write Data Register */
    __IO uint32_t  SEED;                         /*!< Offset: 0x0008   CRC Seed Register */
    __I  uint32_t  CHECKSUM;                     /*!< Offset: 0x000C   CRC Check Sum Register */

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

#define CRC_CTL_CRC_RST_Pos             1                                       /*!< CRC CRC_CTL : CRC_RST Position */
#define CRC_CTL_CRC_RST_Msk             (1ul << CRC_CTL_CRC_RST_Pos)            /*!< CRC CRC_CTL : CRC_RST Mask */

#define CRC_CTL_CRCCEN_Pos              0                                       /*!< CRC CRC_CTL : CRCCEN Position */
#define CRC_CTL_CRCCEN_Msk              (1ul << CRC_CTL_CRCCEN_Pos)             /*!< CRC CRC_CTL : CRCCEN Mask */

/* CRC WDATA Bit Field Definitions */
#define CRC_WDATA_CRC_WDATA_Pos         0                                               /*!< CRC CRC_WDATA : CRC_WDATA Position */
#define CRC_WDATA_CRC_WDATA_Msk         (0xFFFFFFFFul << CRC_WDATA_CRC_WDATA_Pos)       /*!< CRC CRC_WDATA : CRC_WDATA Mask */

/* CRC SEED Bit Field Definitions */
#define CRC_SEED_CRC_SEED_Pos           0                                               /*!< CRC CRC_SEED : CRC_SEED Position */
#define CRC_SEED_CRC_SEED_Msk           (0xFFFFFFFFul << CRC_SEED_CRC_SEED_Pos)         /*!< CRC CRC_SEED : CRC_SEED Mask */

/* CRC CHECKSUM Bit Field Definitions */
#define CRC_CHECKSUM_CRC_CHECKSUM_Pos   0                                               /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Position */
#define CRC_CHECKSUM_CRC_CHECKSUM_Msk   (0xFFFFFFFFul << CRC_CHECKSUM_CRC_CHECKSUM_Pos) /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Mask */

/*@}*/ /* end of group NUC400_CRC */


/*------------- PDMA Control Register (PDMA) -----------------------------*/
/** @addtogroup NUC400_PDMA NUC400 PDMA Control Register (PDMA)
  @{
*/
typedef struct {
    __IO uint32_t CTRL;                 /*!< Offset: 0x0000   Descriptor Table Control Register of DMA Channel */
    __IO uint32_t ENDSAR;               /*!< Offset: 0x0004   End Source Address Register of DMA Channel */
    __IO uint32_t ENDDAR;               /*!< Offset: 0x0008   End Destination Address Register of DMA Channel */
    __IO uint32_t NEXT;                 /*!< Offset: 0x000C   First Scatter-Gather Descriptor Table Offset Address of DMA Channel */

} SCAT_T;

typedef struct {
    SCAT_T DSCT[16];                    /*!< Offset: 0x0000 ~ 0x00FC   DMA Embedded Description Table */
    __I uint32_t RESERVED0[192];        /*!< Offset: 0x0100 ~ 0x03FC   Reserved */
    __IO uint32_t CHCON;                /*!< Offset: 0x0400   DMA Channel Control Register */
    __O  uint32_t STOP;                 /*!< Offset: 0x0404   DMA Stop Transfer Register */
    __O  uint32_t SWREQ;                /*!< Offset: 0x0408   DMA Software Request Register */
    __I  uint32_t REQACTF;              /*!< Offset: 0x040C   DMA Request Active Flag Register */
    __IO uint32_t FPSET;                /*!< Offset: 0x0410   DMA Fix Priority Setting Register */
    __O  uint32_t FPCLR;                /*!< Offset: 0x0414   DMA Fix Priority Clear Register */
    __IO uint32_t IER;                  /*!< Offset: 0x0418   DMA Interrupt Enable Register */
    __IO  uint32_t ISR;                 /*!< Offset: 0x041C   DMA Interrupt Status Register */
    __IO uint32_t ABTF;                 /*!< Offset: 0x0420   DMA Read/Write Target Abort Flag Register */
    __IO uint32_t TDF;                  /*!< Offset: 0x0424   DMA Transfer Done Flag Register */
    __IO uint32_t SCATDF;               /*!< Offset: 0x0428   DMA Scatter-Gather Transfer Done Flag Register */
    __IO uint32_t ACTF;                 /*!< Offset: 0x042C   DMA Transfer On Active Flag Register */
    uint32_t RESERVED1[3];              /*!< Offset: 0x0430 ~ 0x0038   Reserved */
    __IO uint32_t SCATBA;               /*!< Offset: 0x043C   DMA Scatter-Gather Descriptor Table  Base Address  Register */
    __IO uint32_t TOC0;                 /*!< Offset: 0x0440   DMA Time Out Counter Ch1 and Ch0 Register */
    __IO uint32_t TOC1;                 /*!< Offset: 0x0444   DMA Time Out Counter Ch3 and Ch2 Register */
    __IO uint32_t TOC2;                 /*!< Offset: 0x0448   DMA Time Out Counter Ch5 and Ch4 Register */
    __IO uint32_t TOC3;                 /*!< Offset: 0x044C   DMA Time Out Counter Ch7 and Ch6 Register */
    __IO uint32_t TOC4;                 /*!< Offset: 0x0450   DMA Time Out Counter Ch9 and Ch8 Register */
    __IO uint32_t TOC5;                 /*!< Offset: 0x0454   DMA Time Out Counter Ch11 and Ch10 Register */
    __IO uint32_t TOC6;                 /*!< Offset: 0x0458   DMA Time Out Counter Ch13 and Ch12 Register */
    __IO uint32_t TOC7;                 /*!< Offset: 0x045C   DMA Time Out Counter Ch15 and Ch14 Register */
    uint32_t RESERVED2[8];              /*!< Offset: 0x0460 ~ 0x007C   Reserved */
    __IO uint32_t SMSEL0;               /*!< Offset: 0x0480   DMA Source Module Select Register 0 */
    __IO uint32_t SMSEL1;               /*!< Offset: 0x0484   DMA Source Module Select Register 1 */
    __IO uint32_t SMSEL2;               /*!< Offset: 0x0488   DMA Source Module Select Register 2 */
    __IO uint32_t SMSEL3;               /*!< Offset: 0x048C   DMA Source Module Select Register 3 */

} PDMA_T;

/* PDMA DSCT CTRL Bit Field Definitions */
#define PDMA_DSCT_CTRL_TFR_CNT_Pos          16                                          /*!< PDMA DSCT CTRL: TFR_CNT Position */
#define PDMA_DSCT_CTRL_TFR_CNT_Msk          (0x3FFFul << PDMA_DSCT_CTRL_TFR_CNT_Pos)    /*!< PDMA DSCT CTRL: TFR_CNT Mask */

#define PDMA_DSCT_CTRL_TWS_Pos              12                                          /*!< PDMA DSCT CTRL: TWS Position */
#define PDMA_DSCT_CTRL_TWS_Msk              (0x3ul << PDMA_DSCT_CTRL_TWS_Pos)           /*!< PDMA DSCT CTRL: TWS Mask */

#define PDMA_DSCT_CTRL_DAR_INC_Pos          10                                          /*!< PDMA DSCT CTRL: DAR_INC Position */
#define PDMA_DSCT_CTRL_DAR_INC_Msk          (0x3ul << PDMA_DSCT_CTRL_DAR_INC_Pos)       /*!< PDMA DSCT CTRL: DAR_INC Mask */

#define PDMA_DSCT_CTRL_SAR_INC_Pos          8                                           /*!< PDMA DSCT CTRL: SAR_INC Position */
#define PDMA_DSCT_CTRL_SAR_INC_Msk          (0x3ul << PDMA_DSCT_CTRL_SAR_INC_Pos)       /*!< PDMA DSCT CTRL: SAR_INC Mask */

#define PDMA_DSCT_CTRL_TABINT_DIS_Pos       7                                           /*!< PDMA DSCT CTRL: TABINT_DIS Position */
#define PDMA_DSCT_CTRL_TABINT_DIS_Msk       (1ul << PDMA_DSCT_CTRL_TABINT_DIS_Pos)      /*!< PDMA DSCT CTRL: TABINT_DIS Mask */

#define PDMA_DSCT_CTRL_BUR_SIZE_Pos         4                                           /*!< PDMA DSCT CTRL: BUR_SIZE Position */
#define PDMA_DSCT_CTRL_BUR_SIZE_Msk         (0x7ul << PDMA_DSCT_CTRL_BUR_SIZE_Pos)      /*!< PDMA DSCT CTRL: BUR_SIZE Mask */

#define PDMA_DSCT_CTRL_REQ_TYPE_Pos         2                                           /*!< PDMA DSCT CTRL: REQ_TYPE Position */
#define PDMA_DSCT_CTRL_REQ_TYPE_Msk         (1ul << PDMA_DSCT_CTRL_REQ_TYPE_Pos)        /*!< PDMA DSCT CTRL: REQ_TYPE Mask */

#define PDMA_DSCT_CTRL_DMA_MODE_Pos         0                                           /*!< PDMA DSCT CTRL: DMA_MODE Position */
#define PDMA_DSCT_CTRL_DMA_MODE_Msk         (0x3ul << PDMA_DSCT_CTRL_DMA_MODE_Pos)      /*!< PDMA DSCT CTRL: DMA_MODE Mask */

/* PDMA DSCT_SAR Bit Field Definitions */
#define PDMA_DSCT_SAR_Pos                   0                                           /*!< PDMA DSCT_SAR: ENDSAR Position */
#define PDMA_DSCT_SAR_Msk                   (0xFFFFFFFFul << PDMA_DSCT_SAR_Pos)         /*!< PDMA DSCT_SAR: ENDSAR Mask */

/* PDMA DSCT_DAR Bit Field Definitions */
#define PDMA_DSCT_DAR_Pos                   0                                           /*!< PDMA DSCT_DAR: ENDDAR Position */
#define PDMA_DSCT_DAR_Msk                   (0xFFFFFFFFul << PDMA_DSCT_DAR_Pos)         /*!< PDMA DSCT_DAR: ENDDAR Mask */

/* PDMA DSCT_NEXT Bit Field Definitions */
#define PDMA_DSCT_NEXT_OFFSET_Pos           0                                           /*!< PDMA DSCT_NEXT: OFFSET Position */
#define PDMA_DSCT_NEXT_OFFSET_Msk           (0xFFFFul << PDMA_DSCT_NEXT_OFFSET_Pos)     /*!< PDMA DSCT_NEXT: OFFSET Mask */

/* PDMA CHCON Bit Field Definitions */
#define PDMA_CHCON_CEN_Pos          0                                           /*!< PDMA CHCON: CENx Position */
#define PDMA_CHCON_CEN_Msk          (0xFFFFul << PDMA_CTL_CEN_Pos)              /*!< PDMA CHCON: CENx Mask */

/* PDMA STOP Bit Field Definitions */
#define PDMA_STOP_STOP_Pos          0                                           /*!< PDMA STOP: STOPx Position */
#define PDMA_STOP_STOP_Msk          (0xFFFFul << PDMA_STOP_STOP_Pos)            /*!< PDMA STOP: STOPx Mask */

/* PDMA SWREQ Bit Field Definitions */
#define PDMA_SWREQ_SW_REQ_Pos       0                                           /*!< PDMA SWREQ: SW_REQx Position */
#define PDMA_SWREQ_SW_REQ_Msk       (0xFFFFul << PDMA_SWREQ_SW_REQ_Pos)         /*!< PDMA SWREQ: SW_REQx Mask */

/* PDMA REQACTF Bit Field Definitions */
#define PDMA_REQACTF_RACT_F_Pos     0                                           /*!< PDMA REQACTF: RACT_Fx Position */
#define PDMA_REQACTF_RACT_F_Msk     (0xFFFFul << PDMA_REQACTF_RACT_F_Pos)       /*!< PDMA REQACTF: RACT_Fx Mask */

/* PDMA FPSET Bit Field Definitions */
#define PDMA_FPSET_FPIO_SET_Pos     0                                           /*!< PDMA FPSET: FPIO_SETx Position */
#define PDMA_FPSET_FPIO_SET_Msk     (0xFFFFul << PDMA_FPSET_FPIO_SET_Pos)       /*!< PDMA FPSET: FPIO_SETx Mask */

/* PDMA FPCLR Bit Field Definitions */
#define PDMA_FPCLR_FPIO_CLR_Pos     0                                           /*!< PDMA FPCLR: FPIO_CLRx Position */
#define PDMA_FPCLR_FPIO_CLR_Msk     (0xFFFFul << PDMA_FPCLR_FPIO_CLR_Pos)       /*!< PDMA FPCLR: FPIO_CLRx Mask */

/* PDMA IER Bit Field Definitions */
#define PDMA_IER_IEN_Pos            0                                           /*!< PDMA IER: IENx Position */
#define PDMA_IER_IEN_Msk            (0xFFFFul << PDMA_IER_IEN_Pos)              /*!< PDMA IER: IENx Mask */

/* PDMA ISR Bit Field Definitions */
#define PDMA_ISR_TmOut15_Pos        23                                          /*!< PDMA ISR: TmOut15 Position */
#define PDMA_ISR_TmOut15_Msk        (1ul << PDMA_ISR_TmOut15_Pos)               /*!< PDMA ISR: TmOut15 Mask */

#define PDMA_ISR_TmOut14_Pos        22                                          /*!< PDMA ISR: TmOut14 Position */
#define PDMA_ISR_TmOut14_Msk        (1ul << PDMA_ISR_TmOut14_Pos)               /*!< PDMA ISR: TmOut14 Mask */

#define PDMA_ISR_TmOut13_Pos        21                                          /*!< PDMA ISR: TmOut13 Position */
#define PDMA_ISR_TmOut13_Msk        (1ul << PDMA_ISR_TmOut13_Pos)               /*!< PDMA ISR: TmOut13 Mask */

#define PDMA_ISR_TmOut12_Pos        20                                          /*!< PDMA ISR: TmOut12 Position */
#define PDMA_ISR_TmOut12_Msk        (1ul << PDMA_ISR_TmOut12_Pos)               /*!< PDMA ISR: TmOut12 Mask */

#define PDMA_ISR_TmOut11_Pos        19                                          /*!< PDMA ISR: TmOut11 Position */
#define PDMA_ISR_TmOut11_Msk        (1ul << PDMA_ISR_TmOut11_Pos)               /*!< PDMA ISR: TmOut11 Mask */

#define PDMA_ISR_TmOut10_Pos        18                                          /*!< PDMA ISR: TmOut10 Position */
#define PDMA_ISR_TmOut10_Msk        (1ul << PDMA_ISR_TmOut10_Pos)               /*!< PDMA ISR: TmOut10 Mask */

#define PDMA_ISR_TmOut9_Pos         17                                          /*!< PDMA ISR: TmOut9 Position */
#define PDMA_ISR_TmOut9_Msk         (1ul << PDMA_ISR_TmOut9_Pos)                /*!< PDMA ISR: TmOut9 Mask */

#define PDMA_ISR_TmOut8_Pos         16                                          /*!< PDMA ISR: TmOut8 Position */
#define PDMA_ISR_TmOut8_Msk         (1ul << PDMA_ISR_TmOut8_Pos)                /*!< PDMA ISR: TmOut8 Mask */

#define PDMA_ISR_TmOut7_Pos         15                                          /*!< PDMA ISR: TmOut7 Position */
#define PDMA_ISR_TmOut7_Msk         (1ul << PDMA_ISR_TmOut7_Pos)                /*!< PDMA ISR: TmOut7 Mask */

#define PDMA_ISR_TmOut6_Pos         14                                          /*!< PDMA ISR: TmOut6 Position */
#define PDMA_ISR_TmOut6_Msk         (1ul << PDMA_ISR_TmOut6_Pos)                /*!< PDMA ISR: TmOut6 Mask */

#define PDMA_ISR_TmOut5_Pos         13                                          /*!< PDMA ISR: TmOut5 Position */
#define PDMA_ISR_TmOut5_Msk         (1ul << PDMA_ISR_TmOut5_Pos)                /*!< PDMA ISR: TmOut5 Mask */

#define PDMA_ISR_TmOut4_Pos         12                                          /*!< PDMA ISR: TmOut4 Position */
#define PDMA_ISR_TmOut4_Msk         (1ul << PDMA_ISR_TmOut4_Pos)                /*!< PDMA ISR: TmOut4 Mask */

#define PDMA_ISR_TmOut3_Pos         11                                          /*!< PDMA ISR: TmOut3 Position */
#define PDMA_ISR_TmOut3_Msk         (1ul << PDMA_ISR_TmOut3_Pos)                /*!< PDMA ISR: TmOut3 Mask */

#define PDMA_ISR_TmOut2_Pos         10                                          /*!< PDMA ISR: TmOut2 Position */
#define PDMA_ISR_TmOut2_Msk         (1ul << PDMA_ISR_TmOut2_Pos)                /*!< PDMA ISR: TmOut2 Mask */

#define PDMA_ISR_TmOut1_Pos         9                                           /*!< PDMA ISR: TmOut1 Position */
#define PDMA_ISR_TmOut1_Msk         (1ul << PDMA_ISR_TmOut1_Pos)                /*!< PDMA ISR: TmOut1 Mask */

#define PDMA_ISR_TmOut0_Pos         8                                           /*!< PDMA ISR: TmOut0 Position */
#define PDMA_ISR_TmOut0_Msk         (1ul << PDMA_ISR_TmOut0_Pos)                /*!< PDMA ISR: TmOut0 Mask */

#define PDMA_ISR_TEMPTY_F_Pos       2                                           /*!< PDMA ISR: TEMPTY_F Position */
#define PDMA_ISR_TEMPTY_F_Msk       (1ul << PDMA_ISR_TEMPTY_F_Pos)              /*!< PDMA ISR: TEMPTY_F Mask */

#define PDMA_ISR_TD_F_Pos           1                                           /*!< PDMA ISR: TD_F Position */
#define PDMA_ISR_TD_F_Msk           (1ul << PDMA_ISR_TD_F_Pos)                  /*!< PDMA ISR: TD_F Mask */

#define PDMA_ISR_TABORT_F_Pos       0                                           /*!< PDMA ISR: TABORT_F Position */
#define PDMA_ISR_TABORT_F_Msk       (1ul << PDMA_ISR_TABORT_F_Pos)              /*!< PDMA ISR: TABORT_F Mask */

/* PDMA ABTF Bit Field Definitions */
#define PDMA_ABTF_TABORT_F_Pos      0                                           /*!< PDMA ABTF: TABORT_Fx Position */
#define PDMA_ABTF_TABORT_F_Msk      (0xFFFFul << PDMA_ABTF_TABORT_F_Pos)        /*!< PDMA ABTF: TABORT_Fx Mask */

/* PDMA TDF Bit Field Definitions */
#define PDMA_TDF_TD_F_Pos           0                                           /*!< PDMA TDF: TD_Fx Position */
#define PDMA_TDF_TD_F_Msk           (0xFFFFul << PDMA_TDF_TD_F_Pos)             /*!< PDMA TDF: TD_Fx Mask */

/* PDMA SCATDF Bit Field Definitions */
#define PDMA_SCATDF_TEMPTY_F_Pos    0                                           /*!< PDMA SCATDF: TEMPTY_Fx Position */
#define PDMA_SCATDF_TEMPTY_F_Msk    (0xFFFFul << PDMA_SCATDF_TEMPTY_F_Pos)      /*!< PDMA SCATDF: TEMPTY_Fx Mask */

/* PDMA ACTF Bit Field Definitions */
#define PDMA_ACTF_ACTF_F_Pos        0                                           /*!< PDMA ACTF: ACTF_Fx Position */
#define PDMA_ACTF_ACTF_F_Msk        (0xFFFFul << PDMA_ACTF_ACTF_F_Pos)          /*!< PDMA ACTF: ACTF_Fx Mask */

/* PDMA SCATBA Bit Field Definitions */
#define PDMA_SCATBA_SCATBA_Pos      16                                          /*!< PDMA SCATBA: SCATBA Position */
#define PDMA_SCATBA_SCATBA_Msk      (0xFFFFul << PDMA_SCATBA_SCATBA_Pos)        /*!< PDMA SCATBA: SCATBA Mask */

/* PDMA TOC0 Bit Field Definitions */
#define PDMA_TOC0_TmOut1_Pos        16                                          /*!< PDMA TOC0: TmOut1 Position */
#define PDMA_TOC0_TmOut1_Msk        (0xFFFFul << PDMA_TOC0_TmOut1_Pos)          /*!< PDMA TOC0: TmOut1 Mask */
#define PDMA_TOC0_TmOut0_Pos        0                                           /*!< PDMA TOC0: TmOut0 Position */
#define PDMA_TOC0_TmOut0_Msk        (0xFFFFul << PDMA_TOC0_TmOut0_Pos)          /*!< PDMA TOC0: TmOut0 Mask */

/* PDMA TOC1 Bit Field Definitions */
#define PDMA_TOC1_TmOut3_Pos        16                                          /*!< PDMA TOC1: TmOut3 Position */
#define PDMA_TOC1_TmOut3_Msk        (0xFFFFul << PDMA_TOC1_TmOut3_Pos)          /*!< PDMA TOC1: TmOut3 Mask */
#define PDMA_TOC1_TmOut2_Pos        0                                           /*!< PDMA TOC1: TmOut2 Position */
#define PDMA_TOC1_TmOut2_Msk        (0xFFFFul << PDMA_TOC1_TmOut2_Pos)          /*!< PDMA TOC1: TmOut2 Mask */

/* PDMA TOC2 Bit Field Definitions */
#define PDMA_TOC2_TmOut5_Pos        16                                          /*!< PDMA TOC2: TmOut5 Position */
#define PDMA_TOC2_TmOut5_Msk        (0xFFFFul << PDMA_TOC2_TmOut5_Pos)          /*!< PDMA TOC2: TmOut5 Mask */
#define PDMA_TOC2_TmOut4_Pos        0                                           /*!< PDMA TOC2: TmOut4 Position */
#define PDMA_TOC2_TmOut4_Msk        (0xFFFFul << PDMA_TOC2_TmOut4_Pos)          /*!< PDMA TOC2: TmOut4 Mask */

/* PDMA TOC3 Bit Field Definitions */
#define PDMA_TOC3_TmOut7_Pos        16                                          /*!< PDMA TOC3: TmOut7 Position */
#define PDMA_TOC3_TmOut7_Msk        (0xFFFFul << PDMA_TOC3_TmOut7_Pos)          /*!< PDMA TOC3: TmOut7 Mask */
#define PDMA_TOC3_TmOut6_Pos        0                                           /*!< PDMA TOC3: TmOut6 Position */
#define PDMA_TOC3_TmOut6_Msk        (0xFFFFul << PDMA_TOC3_TmOut6_Pos)          /*!< PDMA TOC3: TmOut6 Mask */

/* PDMA TOC4 Bit Field Definitions */
#define PDMA_TOC4_TmOut9_Pos        16                                          /*!< PDMA TOC4: TmOut9 Position */
#define PDMA_TOC4_TmOut9_Msk        (0xFFFFul << PDMA_TOC4_TmOut9_Pos)          /*!< PDMA TOC4: TmOut9 Mask */
#define PDMA_TOC4_TmOut8_Pos        0                                           /*!< PDMA TOC4: TmOut8 Position */
#define PDMA_TOC4_TmOut8_Msk        (0xFFFFul << PDMA_TOC4_TmOut8_Pos)          /*!< PDMA TOC4: TmOut8 Mask */

/* PDMA TOC5 Bit Field Definitions */
#define PDMA_TOC5_TmOut11_Pos       16                                          /*!< PDMA TOC5: TmOut11 Position */
#define PDMA_TOC5_TmOut11_Msk       (0xFFFFul << PDMA_TOC5_TmOut11_Pos)         /*!< PDMA TOC5: TmOut11 Mask */
#define PDMA_TOC5_TmOut10_Pos       0                                           /*!< PDMA TOC5: TmOut10 Position */
#define PDMA_TOC5_TmOut10_Msk       (0xFFFFul << PDMA_TOC5_TmOut10_Pos)         /*!< PDMA TOC5: TmOut10 Mask */

/* PDMA TOC6 Bit Field Definitions */
#define PDMA_TOC6_TmOut13_Pos       16                                          /*!< PDMA TOC6: TmOut13 Position */
#define PDMA_TOC6_TmOut13_Msk       (0xFFFFul << PDMA_TOC6_TmOut13_Pos)         /*!< PDMA TOC6: TmOut13 Mask */
#define PDMA_TOC6_TmOut12_Pos       0                                           /*!< PDMA TOC6: TmOut12 Position */
#define PDMA_TOC6_TmOut12_Msk       (0xFFFFul << PDMA_TOC6_TmOut12_Pos)         /*!< PDMA TOC6: TmOut12 Mask */

/* PDMA TOC7 Bit Field Definitions */
#define PDMA_TOC7_TmOut15_Pos       16                                          /*!< PDMA TOC7: TmOut15 Position */
#define PDMA_TOC7_TmOut15_Msk       (0xFFFFul << PDMA_TOC7_TmOut15_Pos)         /*!< PDMA TOC7: TmOut15 Mask */
#define PDMA_TOC7_TmOut14_Pos       0                                           /*!< PDMA TOC7: TmOut14 Position */
#define PDMA_TOC7_TmOut14_Msk       (0xFFFFul << PDMA_TOC7_TmOut14_Pos)         /*!< PDMA TOC7: TmOut14 Mask */

/* PDMA SMSEL0 Bit Field Definitions */
#define PDMA_SMSEL0_CH3_SEL_Pos     24                                          /*!< PDMA SMSEL0: CH3_SEL Position */
#define PDMA_SMSEL0_CH3_SEL_Msk     (0x1Ful << PDMA_SMSEL0_CH3_SEL_Pos)         /*!< PDMA SMSEL0: CH3_SEL Mask */
#define PDMA_SMSEL0_CH2_SEL_Pos     16                                          /*!< PDMA SMSEL0: CH2_SEL Position */
#define PDMA_SMSEL0_CH2_SEL_Msk     (0x1Ful << PDMA_SMSEL0_CH2_SEL_Pos)         /*!< PDMA SMSEL0: CH2_SEL Mask */
#define PDMA_SMSEL0_CH1_SEL_Pos     8                                           /*!< PDMA SMSEL0: CH1_SEL Position */
#define PDMA_SMSEL0_CH1_SEL_Msk     (0x1Ful << PDMA_SMSEL0_CH1_SEL_Pos)         /*!< PDMA SMSEL0: CH1_SEL Mask */
#define PDMA_SMSEL0_CH0_SEL_Pos     0                                           /*!< PDMA SMSEL0: CH0_SEL Position */
#define PDMA_SMSEL0_CH0_SEL_Msk     (0x1Ful << PDMA_SMSEL0_CH0_SEL_Pos)         /*!< PDMA SMSEL0: CH0_SEL Mask */

/* PDMA SMSEL1 Bit Field Definitions */
#define PDMA_SMSEL1_CH7_SEL_Pos     24                                          /*!< PDMA SMSEL1: CH7_SEL Position */
#define PDMA_SMSEL1_CH7_SEL_Msk     (0x1Ful << PDMA_SMSEL1_CH7_SEL_Pos)         /*!< PDMA SMSEL1: CH7_SEL Mask */
#define PDMA_SMSEL1_CH6_SEL_Pos     16                                          /*!< PDMA SMSEL1: CH6_SEL Position */
#define PDMA_SMSEL1_CH6_SEL_Msk     (0x1Ful << PDMA_SMSEL1_CH6_SEL_Pos)         /*!< PDMA SMSEL1: CH6_SEL Mask */
#define PDMA_SMSEL1_CH5_SEL_Pos     8                                           /*!< PDMA SMSEL1: CH5_SEL Position */
#define PDMA_SMSEL1_CH5_SEL_Msk     (0x1Ful << PDMA_SMSEL1_CH5_SEL_Pos)         /*!< PDMA SMSEL1: CH5_SEL Mask */
#define PDMA_SMSEL1_CH4_SEL_Pos     0                                           /*!< PDMA SMSEL1: CH4_SEL Position */
#define PDMA_SMSEL1_CH4_SEL_Msk     (0x1Ful << PDMA_SMSEL1_CH4_SEL_Pos)         /*!< PDMA SMSEL1: CH4_SEL Mask */

/* PDMA SMSEL2 Bit Field Definitions */
#define PDMA_SMSEL2_CH11_SEL_Pos    24                                          /*!< PDMA SMSEL2: CH11_SEL Position */
#define PDMA_SMSEL2_CH11_SEL_Msk    (0x1Ful << PDMA_SMSEL2_CH11_SEL_Pos)        /*!< PDMA SMSEL2: CH11_SEL Mask */
#define PDMA_SMSEL2_CH10_SEL_Pos    16                                          /*!< PDMA SMSEL2: CH10_SEL Position */
#define PDMA_SMSEL2_CH10_SEL_Msk    (0x1Ful << PDMA_SMSEL2_CH10_SEL_Pos)        /*!< PDMA SMSEL2: CH10_SEL Mask */
#define PDMA_SMSEL2_CH9_SEL_Pos     8                                           /*!< PDMA SMSEL2: CH9_SEL Position */
#define PDMA_SMSEL2_CH9_SEL_Msk     (0x1Ful << PDMA_SMSEL2_CH9_SEL_Pos)         /*!< PDMA SMSEL2: CH9_SEL Mask */
#define PDMA_SMSEL2_CH8_SEL_Pos     0                                           /*!< PDMA SMSEL2: CH8_SEL Position */
#define PDMA_SMSEL2_CH8_SEL_Msk     (0x1Ful << PDMA_SMSEL2_CH8_SEL_Pos)         /*!< PDMA SMSEL2: CH8_SEL Mask */

/* PDMA SMSEL3 Bit Field Definitions */
#define PDMA_SMSEL3_CH15_SEL_Pos    24                                          /*!< PDMA SMSEL3: CH15_SEL Position */
#define PDMA_SMSEL3_CH15_SEL_Msk    (0x1Ful << PDMA_SMSEL3_CH15_SEL_Pos)        /*!< PDMA SMSEL3: CH15_SEL Mask */
#define PDMA_SMSEL3_CH14_SEL_Pos    16                                          /*!< PDMA SMSEL3: CH14_SEL Position */
#define PDMA_SMSEL3_CH14_SEL_Msk    (0x1Ful << PDMA_SMSEL3_CH14_SEL_Pos)        /*!< PDMA SMSEL3: CH14_SEL Mask */
#define PDMA_SMSEL3_CH13_SEL_Pos    8                                           /*!< PDMA SMSEL3: CH13_SEL Position */
#define PDMA_SMSEL3_CH13_SEL_Msk    (0x1Ful << PDMA_SMSEL3_CH13_SEL_Pos)        /*!< PDMA SMSEL3: CH13_SEL Mask */
#define PDMA_SMSEL3_CH12_SEL_Pos    0                                           /*!< PDMA SMSEL3: CH12_SEL Position */
#define PDMA_SMSEL3_CH12_SEL_Msk    (0x1Ful << PDMA_SMSEL3_CH12_SEL_Pos)        /*!< PDMA SMSEL3: CH12_SEL Mask */


/*@}*/ /* end of group NUC400_PDMA */



/*------------- USB Host OHCI Controller (USBH) -----------------------------*/
/** @addtogroup NUC400_USBH NUC400 Host OHCI Controller Register (USBH)
  @{
*/
typedef struct {
    __I  uint32_t HcRev;                        /*!< Offset: 0x0000   Host Controller Revision Register                  */
    __IO uint32_t HcControl;                    /*!< Offset: 0x0004   Host Controller Control Register                   */
    __IO uint32_t HcComSts;                    /*!< Offset: 0x0008   Host Controller Command Status Register            */
    __IO uint32_t HcIntSts;                    /*!< Offset: 0x000C   Host Controller Interrupt Status Register          */
    __IO uint32_t HcIntEn;                    /*!< Offset: 0x0010   Host Controller Interrupt Enable Register          */
    __IO uint32_t HcIntDis;                    /*!< Offset: 0x0014   Host Controller Interrupt Disable Register         */
    __IO uint32_t HcHCCA;                        /*!< Offset: 0x0018   Host Controller Communication Area Register        */
    __IO uint32_t HcPerCED;                    /*!< Offset: 0x001C   Host Controller Period Current ED Register         */
    __IO uint32_t HcCtrHED;                    /*!< Offset: 0x0020   Host Controller Control Head ED Register           */
    __IO uint32_t HcCtrCED;                    /*!< Offset: 0x0024   Host Controller Control Current ED Register        */
    __IO uint32_t HcBlkHED;                    /*!< Offset: 0x0028   Host Controller Bulk Head ED Register              */
    __IO uint32_t HcBlkCED;                    /*!< Offset: 0x002C   Host Controller Bulk Current ED Register           */
    __IO uint32_t HcDoneH;                    /*!< Offset: 0x0030   Host Controller Done Head Register                 */
    __IO uint32_t HcFmIntv;                    /*!< Offset: 0x0034   Host Controller Frame Interval Register            */
    __I  uint32_t HcFmRem;                    /*!< Offset: 0x0038   Host Controller Frame Remaining Register           */
    __I  uint32_t HcFNum;                        /*!< Offset: 0x003C   Host Controller Frame Number Register             */
    __IO uint32_t HcPerSt;                    /*!< Offset: 0x0040   Host Controller Periodic Start Register            */
    __IO uint32_t HcLSTH;                         /*!< Offset: 0x0044   Host Controller Low Speed Threshold Register       */
    __IO  uint32_t HcRhDeA;                    /*!< Offset: 0x0048   Host Controller Root Hub Descriptor A Register     */
    __I  uint32_t HcRhDeB;                    /*!< Offset: 0x004C   Host Controller Root Hub Descriptor A Register     */
    __IO uint32_t HcRhSts;                    /*!< Offset: 0x0050   Host Controller Root Hub Status Register           */
    __IO uint32_t HcRhPrt[2];                    /*!< Offset: 0x0054   Host Controller Root Hub Port Status [1]           */
    uint32_t RESERVED0[105];             /*!< Offset: 0x005C ~ 0x01FC   Reserved                                  */
    __IO uint32_t MiscCtrl;                    /*!< Offset: 0x0200   USB Miscellaneous Control Register                 */
    __IO uint32_t OpModEn;                    /*!< Offset: 0x0204   USB Operational Mode Enable Register               */
} USBH_T;

/********************* Bit definition of HcRev register ***********************/
#define USBH_HcRev_Rev_Pos                0                                    /*!<USBH HcRev: Rev Position */
#define USBH_HcRev_Rev_Msk                (1ul << USBH_HcRev_Rev_Pos)           /*!<USBH HcRev: Rev Mask */

/********************* Bit definition of HcControl register ***********************/
#define USBH_HcControl_CtrlBlkRatio_Pos    0                                    /*!<USBH HcControl: CtrlBlkRatio Position */
#define USBH_HcControl_CtrlBlkRatio_Msk    (3ul << USBH_HcControl_CtrlBlkRatio_Pos) /*!<USBH HcControl: CtrlBlkRatio Mask */
#define USBH_HcControl_PeriEn_Pos        2                                    /*!<USBH HcControl: PeriEn Position */
#define USBH_HcControl_PeriEn_Msk        (1ul << USBH_HcControl_PeriEn_Pos)     /*!<USBH HcControl: PeriEn Mask */
#define USBH_HcControl_ISOEn_Pos        3                                    /*!<USBH HcControl: ISOEn Position */
#define USBH_HcControl_ISOEn_Msk        (1ul << USBH_HcControl_ISOEn_Pos)     /*!<USBH HcControl: ISOEn Mask */
#define USBH_HcControl_CtrlEn_Pos        4                                    /*!<USBH HcControl: CtrlEn Position */
#define USBH_HcControl_CtrlEn_Msk        (1ul << USBH_HcControl_CtrlEn_Pos)     /*!<USBH HcControl: CtrlEn Mask */
#define USBH_HcControl_BlkEn_Pos        5                                    /*!<USBH HcControl: BlkEn Position */
#define USBH_HcControl_BlkEn_Msk        (1ul << USBH_HcControl_BlkEn_Pos)     /*!<USBH HcControl: BlkEn Mask */
#define USBH_HcControl_HcFunc_Pos        6                                    /*!<USBH HcControl: HcFunc Position */
#define USBH_HcControl_HcFunc_Msk        (3ul << USBH_HcControl_HcFunc_Pos)     /*!<USBH HcControl: HcFunc Mask */
#define USBH_HcControl_IntRoute_Pos        8                                    /*!<USBH HcControl: IntRoute Position */
#define USBH_HcControl_IntRoute_Msk        (1ul << USBH_HcControl_IntRoute_Pos)/*!<USBH HcControl: IntRoute Mask */
#define USBH_HcControl_RWake_Pos        9                                    /*!<USBH HcControl: RWake Position */
#define USBH_HcControl_RWake_Msk        (1ul << USBH_HcControl_RWake_Pos)     /*!<USBH HcControl: RWake Mask */
#define USBH_HcControl_RWakeEn_Pos        10                                    /*!<USBH HcControl: RWakeEn Position */
#define USBH_HcControl_RWakeEn_Msk        (1ul << USBH_HcControl_RWakeEn_Pos) /*!<USBH HcControl: RWakeEn Mask */

/********************* Bit definition of HcComSts register ********************/
#define USBH_HcComSts_HCReset_Pos        0                                    /*!<USBH HcComSts: HCReset Position */
#define USBH_HcComSts_HCReset_Msk        (1ul << USBH_HcComSts_HCReset_Pos)     /*!<USBH HcComSts: HCReset Mask */
#define USBH_HcComSts_CtrlFill_Pos        1                                    /*!<USBH HcComSts: CtrlFill Position */
#define USBH_HcComSts_CtrlFill_Msk        (1ul << USBH_HcComSts_CtrlFill_Pos) /*!<USBH HcComSts: CtrlFill Mask */
#define USBH_HcComSts_BlkFill_Pos        2                                    /*!<USBH HcComSts: BlkFill Position */
#define USBH_HcComSts_BlkFill_Msk        (1ul << USBH_HcComSts_BlkFill_Pos)     /*!<USBH HcComSts: BlkFill Mask */
#define USBH_HcComSts_OCReq_Pos            3                                    /*!<USBH HcComSts: OCReq Position */
#define USBH_HcComSts_OCReq_Msk            (1ul << USBH_HcComSts_OCReq_Pos)     /*!<USBH HcComSts: OCReq Mask */
#define USBH_HcComSts_SchOverRun_Pos    16                                    /*!<USBH HcComSts: SchOverRun Position */
#define USBH_HcComSts_SchOverRun_Msk    (3ul << USBH_HcComSts_SchOverRun_Pos)     /*!<USBH HcComSts: SchOverRun Mask */

/********************* Bit definition of HcIntSts register ********************/
#define USBH_HcIntSts_SchOR_Pos            0                                    /*!<USBH HcIntSts: SchOR Position */
#define USBH_HcIntSts_SchOR_Msk            (1ul << USBH_HcIntSts_SchOR_Pos)     /*!<USBH HcIntSts: SchOR Mask */
#define USBH_HcIntSts_WBDnHD_Pos        1                                    /*!<USBH HcIntSts: WBDnHD Position */
#define USBH_HcIntSts_WBDnHD_Msk        (1ul << USBH_HcIntSts_WBDnHD_Pos)     /*!<USBH HcIntSts: WBDnHD Mask */
#define USBH_HcIntSts_SOF_Pos            2                                    /*!<USBH HcIntSts: SOF Position */
#define USBH_HcIntSts_SOF_Msk            (1ul << USBH_HcIntSts_SOF_Pos)         /*!<USBH HcIntSts: SOF Mask */
#define USBH_HcIntSts_Resume_Pos        3                                    /*!<USBH HcIntSts: Resume Position */
#define USBH_HcIntSts_Resume_Msk        (1ul << USBH_HcIntSts_Resume_Pos)     /*!<USBH HcIntSts: Resume Mask */
#define USBH_HcIntSts_UnRecErr_Pos        4                                    /*!<USBH HcIntSts: UnRecErr Position */
#define USBH_HcIntSts_UnRecErr_Msk        (1ul << USBH_HcIntSts_UnRecErr_Pos) /*!<USBH HcIntSts: UnRecErr Mask */
#define USBH_HcIntSts_FNOF_Pos            5                                    /*!<USBH HcIntSts: FNOF Position */
#define USBH_HcIntSts_FNOF_Msk            (1ul << USBH_HcIntSts_FNOF_Pos)     /*!<USBH HcIntSts: FNOF Mask */
#define USBH_HcIntSts_RHSC_Pos            6                                    /*!<USBH HcIntSts: RHSC Position */
#define USBH_HcIntSts_RHSC_Msk            (1ul << USBH_HcIntSts_RHSC_Pos)     /*!<USBH HcIntSts: RHSC Mask */
#define USBH_HcIntSts_OC_Pos            30                                    /*!<USBH HcIntSts: OC Position */
#define USBH_HcIntSts_OC_Msk            (1ul << USBH_HcIntSts_OC_Pos)         /*!<USBH HcIntSts: OC Mask */

/********************* Bit definition of HcIntEn register *********************/
#define USBH_HcIntEn_SchOREn_Pos        0                                    /*!<USBH HcIntEn: SchOREn Position */
#define USBH_HcIntEn_SchOREn_Msk        (1ul << USBH_HcIntEn_SchOREn_Pos)     /*!<USBH HcIntEn: SchOREn Mask */
#define USBH_HcIntEn_WBDHEn_Pos            1                                    /*!<USBH HcIntEn: WBDHEn Position */
#define USBH_HcIntEn_WBDHEn_Msk            (1ul << USBH_HcIntEn_WBDHEn_Pos)     /*!<USBH HcIntEn: WBDHEn Mask */
#define USBH_HcIntEn_SOFEn_Pos            2                                    /*!<USBH HcIntEn: SOFEn Position */
#define USBH_HcIntEn_SOFEn_Msk            (1ul << USBH_HcIntEn_SOFEn_Pos)     /*!<USBH HcIntEn: SOFEn Mask */
#define USBH_HcIntEn_ResuEn_Pos            3                                    /*!<USBH HcIntEn: ResuEn Position */
#define USBH_HcIntEn_ResuEn_Msk            (1ul << USBH_HcIntEn_ResuEn_Pos)     /*!<USBH HcIntEn: ResuEn Mask */
#define USBH_HcIntEn_URErrEn_Pos        4                                    /*!<USBH HcIntEn: URErrEn Position */
#define USBH_HcIntEn_URErrEn_Msk        (1ul << USBH_HcIntEn_URErrEn_Pos)     /*!<USBH HcIntEn: URErrEn Mask */
#define USBH_HcIntEn_FNOFEn_Pos            5                                    /*!<USBH HcIntEn: FNOFEn Position */
#define USBH_HcIntEn_FNOFEn_Msk            (1ul << USBH_HcIntEn_FNOFEn_Pos)     /*!<USBH HcIntEn: FNOFEn Mask */
#define USBH_HcIntEn_RHSCEn_Pos            6                                    /*!<USBH HcIntEn: RHSCEn Position */
#define USBH_HcIntEn_RHSCEn_Msk            (1ul << USBH_HcIntEn_RHSCEn_Pos)     /*!<USBH HcIntEn: RHSCEn Mask */
#define USBH_HcIntEn_OCEn_Pos            30                                    /*!<USBH HcIntEn: OCEn Position */
#define USBH_HcIntEn_OCEn_Msk            (1ul << USBH_HcIntEn_OCEn_Pos)         /*!<USBH HcIntEn: OCEn Mask */
#define USBH_HcIntEn_IntEn_Pos            31                                    /*!<USBH HcIntEn: IntEn Position */
#define USBH_HcIntEn_IntEn_Msk            (1ul << USBH_HcIntEn_IntEn_Pos)     /*!<USBH HcIntEn: IntEn Mask */

/********************* Bit definition of HcIntDis register ********************/
#define USBH_HcIntDis_SchORDis_Pos        0                                    /*!<USBH HcIntDis: SchORDis Position */
#define USBH_HcIntDis_SchORDis_Msk        (1ul << USBH_HcIntDis_SchORDis_Pos) /*!<USBH HcIntDis: SchORDis Mask */
#define USBH_HcIntDis_WBDHDis_Pos        1                                    /*!<USBH HcIntDis: WBDHDis Position */
#define USBH_HcIntDis_WBDHDis_Msk        (1ul << USBH_HcIntDis_WBDHDis_Pos)     /*!<USBH HcIntDis: WBDHDis Mask */
#define USBH_HcIntDis_SOFDis_Pos        2                                    /*!<USBH HcIntDis: SOFDis Position */
#define USBH_HcIntDis_SOFDis_Msk        (1ul << USBH_HcIntDis_SOFDis_Pos)     /*!<USBH HcIntDis: SOFDis Mask */
#define USBH_HcIntDis_ResuDis_Pos        3                                    /*!<USBH HcIntDis: ResuDis Position */
#define USBH_HcIntDis_ResuDis_Msk        (1ul << USBH_HcIntDis_ResuDis_Pos)     /*!<USBH HcIntDis: ResuDis Mask */
#define USBH_HcIntDis_URErrDis_Pos        4                                    /*!<USBH HcIntDis: URErrDis Position */
#define USBH_HcIntDis_URErrDis_Msk        (1ul << USBH_HcIntDis_URErrDis_Pos) /*!<USBH HcIntDis: URErrDis Mask */
#define USBH_HcIntDis_FNOFDis_Pos        5                                    /*!<USBH HcIntDis: FNOFDis Position */
#define USBH_HcIntDis_FNOFDis_Msk        (1ul << USBH_HcIntDis_FNOFDis_Pos)     /*!<USBH HcIntDis: FNOFDis Mask */
#define USBH_HcIntDis_RHSCDis_Pos        6                                    /*!<USBH HcIntDis: RHSCDis Position */
#define USBH_HcIntDis_RHSCDis_Msk        (1ul << USBH_HcIntDis_RHSCDis_Pos)     /*!<USBH HcIntDis: RHSCDis Mask */
#define USBH_HcIntDis_OCDis_Pos            30                                    /*!<USBH HcIntDis: OCDis Position */
#define USBH_HcIntDis_OCDis_Msk            (1ul << USBH_HcIntDis_OCDis_Pos)     /*!<USBH HcIntDis: OCDis Mask */
#define USBH_HcIntDis_IntDis_Pos        31                                    /*!<USBH HcIntDis: IntDis Position */
#define USBH_HcIntDis_IntDis_Msk        (1ul << USBH_HcIntDis_IntDis_Pos)     /*!<USBH HcIntDis: IntDis Mask */

/********************* Bit definition of HcFmIntv register ********************/
#define USBH_HcFmIntv_FmInterval_Pos    0                                    /*!<USBH HcFmIntv: FmInterval Position */
#define USBH_HcFmIntv_FmInterval_Msk    (0x3ffful << USBH_HcFmIntv_FmInterval_Pos)     /*!<USBH HcFmIntv: FmInterval Mask */
#define USBH_HcFmIntv_FSDPktCnt_Pos        16                                    /*!<USBH HcFmIntv: FSDPktCnt Position */
#define USBH_HcFmIntv_FSDPktCnt_Msk        (0x7ffful << USBH_HcFmIntv_FSDPktCnt_Pos)     /*!<USBH HcFmIntv: FSDPktCnt Mask */
#define USBH_HcFmIntv_FmIntvT_Pos        31                                    /*!<USBH HcFmIntv: FmIntvT Position */
#define USBH_HcFmIntv_FmIntvT_Msk        (1ul << USBH_HcFmIntv_FmIntvT_Pos)     /*!<USBH HcFmIntv: FmIntvT Mask */

/********************* Bit definition of HcFmRem register *********************/
#define USBH_HcFmRem_FmRemain_Pos        0                                    /*!<USBH HcFmRem: FmRemain Position */
#define USBH_HcFmRem_FmRemain_Msk        (0x3ffful << USBH_HcFmRem_FmRemain_Pos)     /*!<USBH HcFmRem: FmRemain Mask */
#define USBH_HcFmRem_FmRemT_Pos            31                                    /*!<USBH HcFmRem: FmRemT Position */
#define USBH_HcFmRem_FmRemT_Msk            (1ul << USBH_HcFmRem_FmRemT_Pos)     /*!<USBH HcFmRem: FmRemT Mask */

/********************* Bit definition of HcFmRem register *********************/
#define USBH_HcFNum_FmNum_Pos            0                                    /*!<USBH HcFNum: FmNum Position */
#define USBH_HcFNum_FmNum_Msk            (0xfffful << USBH_HcFNum_FmNum_Pos) /*!<USBH HcFNum: FmNum Mask */

/********************* Bit definition of HcPerSt register *********************/
#define USBH_HcPerSt_PeriStart_Pos        0                                    /*!<USBH HcPerSt: PeriStart Position */
#define USBH_HcPerSt_PeriStart_Msk        (0x3ffful << USBH_HcPerSt_PeriStart_Pos) /*!<USBH HcPerSt: PeriStart Mask */

/********************* Bit definition of HcLSTH register **********************/
#define USBH_HcLSTH_LST_Pos                0                                    /*!<USBH HcLSTH: LST Position */
#define USBH_HcLSTH_LST_Msk                (0xffful << USBH_HcLSTH_LST_Pos)    /*!<USBH HcLSTH: LST Mask */

/********************* Bit definition of HcRhDeA register *********************/
#define USBH_HcRhDeA_DPortNum_Pos        0                                    /*!<USBH HcRhDeA: DPortNum Position */
#define USBH_HcRhDeA_DPortNum_Msk        (0xfful << USBH_HcRhDeA_DPortNum_Pos)    /*!<USBH HcRhDeA: DPortNum Mask */
#define USBH_HcRhDeA_PSM_Pos            8                                    /*!<USBH HcRhDeA: PSM Position */
#define USBH_HcRhDeA_PSM_Msk            (1ul << USBH_HcRhDeA_PSM_Pos)        /*!<USBH HcRhDeA: PSM Mask */
#define USBH_HcRhDeA_NPS_Pos            9                                    /*!<USBH HcRhDeA: NPS Position */
#define USBH_HcRhDeA_NPS_Msk            (1ul << USBH_HcRhDeA_NPS_Pos)        /*!<USBH HcRhDeA: NPS Mask */
#define USBH_HcRhDeA_DevType_Pos        10                                    /*!<USBH HcRhDeA: DevType Position */
#define USBH_HcRhDeA_DevType_Msk        (1ul << USBH_HcRhDeA_DevType_Pos)    /*!<USBH HcRhDeA: DevType Mask */
#define USBH_HcRhDeA_OCPM_Pos            11                                    /*!<USBH HcRhDeA: OCPM Position */
#define USBH_HcRhDeA_OCPM_Msk            (1ul << USBH_HcRhDeA_OCPM_Pos)        /*!<USBH HcRhDeA: OCPM Mask */
#define USBH_HcRhDeA_NOCP_Pos            12                                    /*!<USBH HcRhDeA: NOCP Position */
#define USBH_HcRhDeA_NOCP_Msk            (1ul << USBH_HcRhDeA_NOCP_Pos)        /*!<USBH HcRhDeA: NOCP Mask */
#define USBH_HcRhDeA_PwrGDT_Pos            24                                    /*!<USBH HcRhDeA: PwrGDT Position */
#define USBH_HcRhDeA_PwrGDT_Msk            (0xfful << USBH_HcRhDeA_PwrGDT_Pos)    /*!<USBH HcRhDeA: PwrGDT Mask */

/********************* Bit definition of HcRhDeB register *********************/
#define USBH_HcRhDeB_DevRemove_Pos        0                                    /*!<USBH HcRhDeB: DevRemove Position */
#define USBH_HcRhDeB_DevRemove_Msk        (0xfffful << USBH_HcRhDeB_DevRemove_Pos)    /*!<USBH HcRhDeB: DevRemove Mask */
#define USBH_HcRhDeB_PPCM_Pos            16                                    /*!<USBH HcRhDeB: PPCM Position */
#define USBH_HcRhDeB_PPCM_Msk            (0xfffful << USBH_HcRhDeB_PPCM_Pos)    /*!<USBH HcRhDeB: PPCM Mask */

/********************* Bit definition of HcRhSts register *********************/
#define USBH_HcRhSts_LPS_Pos            0                                /*!<USBH HcRhSts: LPS Position */
#define USBH_HcRhSts_LPS_Msk            (1ul << USBH_HcRhSts_LPS_Pos)    /*!<USBH HcRhSts: LPS Mask */
#define USBH_HcRhSts_OC_Pos                1                                /*!<USBH HcRhSts: OC Position */
#define USBH_HcRhSts_OC_Msk                (1ul << USBH_HcRhSts_OC_Pos)    /*!<USBH HcRhSts: OC Mask */
#define USBH_HcRhSts_DRWEn_Pos            15                                /*!<USBH HcRhSts: DRWEn Position */
#define USBH_HcRhSts_DRWEn_Msk            (1ul << USBH_HcRhSts_DRWEn_Pos)    /*!<USBH HcRhSts: DRWEn Mask */
#define USBH_HcRhSts_LPSC_Pos            16                                /*!<USBH HcRhSts: LPSC Position */
#define USBH_HcRhSts_LPSC_Msk            (1ul << USBH_HcRhSts_LPSC_Pos)    /*!<USBH HcRhSts: LPSC Mask */
#define USBH_HcRhSts_OCIC_Pos            17                                /*!<USBH HcRhSts: OCIC Position */
#define USBH_HcRhSts_OCIC_Msk            (1ul << USBH_HcRhSts_OCIC_Pos)    /*!<USBH HcRhSts: OCIC Mask */
#define USBH_HcRhSts_RWEClr_Pos            31                                /*!<USBH HcRhSts: RWEClr Position */
#define USBH_HcRhSts_RWEClr_Msk            (1ul << USBH_HcRhSts_RWEClr_Pos)/*!<USBH HcRhSts: RWEClr Mask */

/********************* Bit definition of HcRhPrt1/2 register*******************/
#define USBH_HcRhPrt_CC_Pos                0                                /*!<USBH HcRhPrt: CC Position */
#define USBH_HcRhPrt_CC_Msk                (1ul << USBH_HcRhSts_CC_Pos)    /*!<USBH HcRhPrt: CC Mask */
#define USBH_HcRhPrt_PE_Pos                1                                /*!<USBH HcRhPrt: PE Position */
#define USBH_HcRhPrt_PE_Msk                (1ul << USBH_HcRhSts_PE_Pos)    /*!<USBH HcRhPrt: PE Mask */
#define USBH_HcRhPrt_PS_Pos                2                                /*!<USBH HcRhPrt: PS Position */
#define USBH_HcRhPrt_PS_Msk                (1ul << USBH_HcRhSts_PS_Pos)    /*!<USBH HcRhPrt: PS Mask */
#define USBH_HcRhPrt_POC_Pos            3                                /*!<USBH HcRhPrt: POC Position */
#define USBH_HcRhPrt_POC_Msk            (1ul << USBH_HcRhSts_POC_Pos)    /*!<USBH HcRhPrt: POC Mask */
#define USBH_HcRhPrt_PR_Pos                4                                /*!<USBH HcRhPrt: PR Position */
#define USBH_HcRhPrt_PR_Msk                (1ul << USBH_HcRhSts_PR_Pos)    /*!<USBH HcRhPrt: PR Mask */
#define USBH_HcRhPrt_PPS_Pos            8                                /*!<USBH HcRhPrt: PPS Position */
#define USBH_HcRhPrt_PPS_Msk            (1ul << USBH_HcRhSts_PPS_Pos)    /*!<USBH HcRhPrt: PPS Mask */
#define USBH_HcRhPrt_LSDev_Pos            9                                /*!<USBH HcRhPrt: LSDev Position */
#define USBH_HcRhPrt_LSDev_Msk            (1ul << USBH_HcRhSts_LSDev_Pos)    /*!<USBH HcRhPrt: LSDev Mask */
#define USBH_HcRhPrt_CSC_Pos            16                                /*!<USBH HcRhPrt: CSC Position */
#define USBH_HcRhPrt_CSC_Msk            (1ul << USBH_HcRhSts_CSC_Pos)    /*!<USBH HcRhPrt: CSC Mask */
#define USBH_HcRhPrt_PESC_Pos            17                                /*!<USBH HcRhPrt: PESC Position */
#define USBH_HcRhPrt_PESC_Msk            (1ul << USBH_HcRhSts_PESC_Pos)    /*!<USBH HcRhPrt: PESC Mask */
#define USBH_HcRhPrt_PSSC_Pos            18                                /*!<USBH HcRhPrt: PSSC Position */
#define USBH_HcRhPrt_PSSC_Msk            (1ul << USBH_HcRhSts_PSSC_Pos)    /*!<USBH HcRhPrt: PSSC Mask */
#define USBH_HcRhPrt_POCIC_Pos            19                                /*!<USBH HcRhPrt: POCIC Position */
#define USBH_HcRhPrt_POCIC_Msk            (1ul << USBH_HcRhSts_POCIC_Pos)    /*!<USBH HcRhPrt: POCIC Mask */
#define USBH_HcRhPrt_PRSC_Pos            20                                /*!<USBH HcRhPrt: PRSC Position */
#define USBH_HcRhPrt_PRSC_Msk            (1ul << USBH_HcRhSts_PRSC_Pos)    /*!<USBH HcRhPrt: PRSC Mask */

/********************* Bit definition of MiscCtrl register*********************/
#define USBH_MiscCtrl_StbyEn_Pos        27                                /*!<USBH MiscCtrl: StbyEn Position */
#define USBH_MiscCtrl_StbyEn_Msk        (1ul << USBH_MiscCtrl_StbyEn_Pos)    /*!<USBH MiscCtrl: StbyEn Mask */

/********************* Bit definition of OpModEn register**********************/
#define USBH_OpModEn_DBR16_Pos            0                                /*!<USBH OpModEn: DBR16 Position */
#define USBH_OpModEn_DBR16_Msk            (1ul << USBH_OpModEn_DBR16_Pos)    /*!<USBH OpModEn: DBR16 Mask */
#define USBH_OpModEn_ABORT_Pos            1                                /*!<USBH OpModEn: ABORT Position */
#define USBH_OpModEn_ABORT_Msk            (1ul << USBH_OpModEn_ABORT_Msk)    /*!<USBH OpModEn: ABORT Mask */
#define USBH_OpModEn_OCALow_Pos            3                                /*!<USBH OpModEn: OCALow Position */
#define USBH_OpModEn_OCALow_Msk            (1ul << USBH_OpModEn_OCALow_Pos)/*!<USBH OpModEn: OCALow Mask */
#define USBH_OpModEn_PPCLow_Pos            4                                /*!<USBH OpModEn: PPCLow Position */
#define USBH_OpModEn_PPCLow_Msk            (1ul << USBH_OpModEn_PPCLow_Pos)/*!<USBH OpModEn: PPCLow Mask */
#define USBH_OpModEn_SIEPDis_Pos        8                                /*!<USBH OpModEn: SIEPDis Position */
#define USBH_OpModEn_SIEPDis_Msk        (1ul << USBH_OpModEn_SIEPDis_Pos)/*!<USBH OpModEn: SIEPDis Mask */
#define USBH_OpModEn_DisPrt1_Pos        16                                /*!<USBH OpModEn: DisPrt1 Position */
#define USBH_OpModEn_DisPrt1_Msk        (1ul << USBH_OpModEn_DisPrt1_Pos)/*!<USBH OpModEn: DisPrt1 Mask */
#define USBH_OpModEn_DisPrt2_Pos        17                                /*!<USBH OpModEn: DisPrt2 Position */
#define USBH_OpModEn_DisPrt2_Msk        (1ul << USBH_OpModEn_DisPrt2_Pos)/*!<USBH OpModEn: DisPrt2 Mask */

/*@}*/ /* end of group NUC400_USBH */


/*------------- Ethernet MAC Register (EMAC) -----------------------------*/
/** @addtogroup NUC400_EMAC NUC400 Ethernet MAC (EMAC)
  @{
*/
/**
  * @brief EMAC register map
  */
typedef struct {
    __IO uint32_t CAMCMR;                           /*!< Offset: 0x0000   CAM Command register                                   */
    __IO uint32_t CAMEN;                            /*!< Offset: 0x0004   CAM Enable register                                    */
    __IO uint32_t CAM0M;                            /*!< Offset: 0x0008   CAM0 Most Significant Word Register                    */
    __IO uint32_t CAM0L;                            /*!< Offset: 0x000C   CAM0 Least Significant Word Register                   */
    __IO uint32_t CAM1M;                            /*!< Offset: 0x0010   CAM1 Most Significant Word Register                    */
    __IO uint32_t CAM1L;                            /*!< Offset: 0x0014   CAM1 Least Significant Word Register                   */
    __IO uint32_t CAM2M;                            /*!< Offset: 0x0018   CAM2 Most Significant Word Register                    */
    __IO uint32_t CAM2L;                            /*!< Offset: 0x001C   CAM2 Least Significant Word Register                   */
    __IO uint32_t CAM3M;                            /*!< Offset: 0x0020   CAM3 Most Significant Word Register                    */
    __IO uint32_t CAM3L;                            /*!< Offset: 0x0024   CAM3 Least Significant Word Register                   */
    __IO uint32_t CAM4M;                            /*!< Offset: 0x0028   CAM4 Most Significant Word Register                    */
    __IO uint32_t CAM4L;                            /*!< Offset: 0x002C   CAM4 Least Significant Word Register                   */
    __IO uint32_t CAM5M;                            /*!< Offset: 0x0030   CAM5 Most Significant Word Register                    */
    __IO uint32_t CAM5L;                            /*!< Offset: 0x0034   CAM5 Least Significant Word Register                   */
    __IO uint32_t CAM6M;                            /*!< Offset: 0x0038   CAM6 Most Significant Word Register                    */
    __IO uint32_t CAM6L;                            /*!< Offset: 0x003C   CAM6 Least Significant Word Register                   */
    __IO uint32_t CAM7M;                            /*!< Offset: 0x0040   CAM7 Most Significant Word Register                    */
    __IO uint32_t CAM7L;                            /*!< Offset: 0x0044   CAM7 Least Significant Word Register                   */
    __IO uint32_t CAM8M;                            /*!< Offset: 0x0048   CAM8 Most Significant Word Register                    */
    __IO uint32_t CAM8L;                            /*!< Offset: 0x004C   CAM8 Least Significant Word Register                   */
    __IO uint32_t CAM9M;                            /*!< Offset: 0x0050   CAM9 Most Significant Word Register                    */
    __IO uint32_t CAM9L;                            /*!< Offset: 0x0054   CAM9 Least Significant Word Register                   */
    __IO uint32_t CAM10M;                           /*!< Offset: 0x0058   CAM10 Most Significant Word Register                   */
    __IO uint32_t CAM10L;                           /*!< Offset: 0x005C   CAM10 Least Significant Word Register                  */
    __IO uint32_t CAM11M;                           /*!< Offset: 0x0060   CAM11 Most Significant Word Register                   */
    __IO uint32_t CAM11L;                           /*!< Offset: 0x0064   CAM11 Least Significant Word Register                  */
    __IO uint32_t CAM12M;                           /*!< Offset: 0x0068   CAM12 Most Significant Word Register                   */
    __IO uint32_t CAM12L;                           /*!< Offset: 0x006C   CAM12 Least Significant Word Register                  */
    __IO uint32_t CAM13M;                           /*!< Offset: 0x0070   CAM13 Most Significant Word Register                   */
    __IO uint32_t CAM13L;                           /*!< Offset: 0x0074   CAM13 Least Significant Word Register                  */
    __IO uint32_t CAM14M;                           /*!< Offset: 0x0078   CAM14 Most Significant Word Register                   */
    __IO uint32_t CAM14L;                           /*!< Offset: 0x007C   CAM14 Least Significant Word Register                  */
    __IO uint32_t CAM15M;                           /*!< Offset: 0x0080   CAM15 Most Significant Word Register                   */
    __IO uint32_t CAM15L;                           /*!< Offset: 0x0084   CAM15 Least Significant Word Register                  */
    __IO uint32_t TXDLSA;                           /*!< Offset: 0x0088   Transmit Descriptor Link List Start Address Register   */
    __IO uint32_t RXDLSA;                           /*!< Offset: 0x008C   Receive Descriptor Link List Start Address Register    */
    __IO uint32_t MCMDR;                            /*!< Offset: 0x0090   MAC Command Register                                   */
    __IO uint32_t MIID;                             /*!< Offset: 0x0094   MII Management Data Register                           */
    __IO uint32_t MIIDA;                            /*!< Offset: 0x0098   MII Management Control and Address Register            */
    __IO uint32_t FFTCR;                            /*!< Offset: 0x009C   FIFO Threshold Control Register                        */
    __IO uint32_t TSDR;                             /*!< Offset: 0x00A0   Transmit Start Demand Register                         */
    __IO uint32_t RSDR;                             /*!< Offset: 0x00A4   Receive Start Demand Register                          */
    __IO uint32_t DMARFC;                           /*!< Offset: 0x00A8   Maximum Receive Frame Control Register                 */
    __IO uint32_t MIEN;                             /*!< Offset: 0x00AC   MAC Interrupt Enable Register                          */
    __IO uint32_t MISTA;                            /*!< Offset: 0x00B0   MAC Interrupt Status Register                          */
    __IO uint32_t MGSTA;                            /*!< Offset: 0x00B4   MAC General Status Register                            */
    __IO uint32_t MPCNT;                            /*!< Offset: 0x00B8   Missed Packet Count Register                           */
    __I  uint32_t MRPC;                             /*!< Offset: 0x00BC   MAC Receive Pause Count Register                       */
    uint32_t RESERVED0[2];                     /*!< Offset: 0x00C0 ~ 0x00C4   Reserved                                      */
    __IO uint32_t DMARFS;                           /*!< Offset: 0x00C8   DMA Receive Frame Status Register                      */
    __I  uint32_t CTXDSA;                           /*!< Offset: 0x00CC   Current Transmit Descriptor Start Address Register     */
    __I  uint32_t CTXBSA;                           /*!< Offset: 0x00D0   Current Transmit Buffer Start Address Register         */
    __I  uint32_t CRXDSA;                           /*!< Offset: 0x00D4   Current Receive Descriptor Start Address Register      */
    __I  uint32_t CRXBSA;                           /*!< Offset: 0x00D8   Current Receive Buffer Start Address Register          */
    uint32_t RESERVED1[9];                     /*!< Offset: 0x00DC ~ 0x00FC   Reserved                                      */
    __IO uint32_t TSCR;                             /*!< Offset: 0x0100   Time Stamp Control Register                            */
    uint32_t RESERVED2[3];                     /*!< Offset: 0x0104 ~ 0x010C   Reserved                                      */
    __I  uint32_t TSMSR;                            /*!< Offset: 0x0110   Time Stamp Most Significant Register                   */
    __I  uint32_t TSLSR;                            /*!< Offset: 0x0114   Time Stamp Least Significant Register                  */
    __IO uint32_t TSIR;                             /*!< Offset: 0x0118   Time Stamp Increment Register                          */
    __IO uint32_t TSAR;                             /*!< Offset: 0x011C   Time Stamp Addend Register                             */
    __IO uint32_t TSMSUR;                           /*!< Offset: 0x0120   Time Stamp Most Significant Update Register            */
    __IO uint32_t TSLSUR;                           /*!< Offset: 0x0124   Time Stamp Least Significant Update Register           */
    __IO uint32_t TSMSAR;                           /*!< Offset: 0x0128   Time Stamp Most Significant Alarm Register             */
    __IO uint32_t TSLSAR;                           /*!< Offset: 0x012C   Time Stamp Least Significant Alarm Register            */
} EMAC_T;

/* EMAC CAMCMR Bit Field Definitions */
#define EMAC_CAMCMR_ECMP_Pos                4                                       /*!<EMAC CAMCMR: ECMP Position      */
#define EMAC_CAMCMR_ECMP_Msk                (1ul << EMAC_CAMCMR_ECMP_Pos)           /*!<EMAC CAMCMR: ECMP Mask          */
#define EMAC_CAMCMR_CCAM_Pos                3                                       /*!<EMAC CAMCMR: CCAM Position      */
#define EMAC_CAMCMR_CCAM_Msk                (1ul << EMAC_CAMCMR_CCAM_Pos)           /*!<EMAC CAMCMR: CCAM Mask          */
#define EMAC_CAMCMR_ABP_Pos                 2                                       /*!<EMAC CAMCMR: ABP Position       */
#define EMAC_CAMCMR_ABP_Msk                 (1ul << EMAC_CAMCMR_ABP_Pos)            /*!<EMAC CAMCMR: ABP Mask           */
#define EMAC_CAMCMR_AMP_Pos                 1                                       /*!<EMAC CAMCMR: AMP Position       */
#define EMAC_CAMCMR_AMP_Msk                 (1ul << EMAC_CAMCMR_AMP_Pos)            /*!<EMAC CAMCMR: AMP Mask           */
#define EMAC_CAMCMR_AUP_Pos                 0                                       /*!<EMAC CAMCMR: AUP Position       */
#define EMAC_CAMCMR_AUP_Msk                 (1ul << EMAC_CAMCMR_AUP_Pos)            /*!<EMAC CAMCMR: AUP Mask           */

/* EMAC CAMEN Bit Field Definitions */
#define EMAC_CAMEN_CAM15EN_Pos              15                                      /*!<EMAC CAMEN: CAM15EN Position    */
#define EMAC_CAMEN_CAM15EN_Msk              (1ul << EMAC_CAMEN_CAM15EN_Pos)         /*!<EMAC CAMEN: CAM15EN Mask        */
#define EMAC_CAMEN_CAM14EN_Pos              14                                      /*!<EMAC CAMEN: CAM14EN Position    */
#define EMAC_CAMEN_CAM14EN_Msk              (1ul << EMAC_CAMEN_CAM14EN_Pos)         /*!<EMAC CAMEN: CAM14EN Mask        */
#define EMAC_CAMEN_CAM13EN_Pos              13                                      /*!<EMAC CAMEN: CAM13EN Position    */
#define EMAC_CAMEN_CAM13EN_Msk              (1ul << EMAC_CAMEN_CAM13EN_Pos)         /*!<EMAC CAMEN: CAM13EN Mask        */
#define EMAC_CAMEN_CAM12EN_Pos              12                                      /*!<EMAC CAMEN: CAM12EN Position    */
#define EMAC_CAMEN_CAM12EN_Msk              (1ul << EMAC_CAMEN_CAM12EN_Pos)         /*!<EMAC CAMEN: CAM12EN Mask        */
#define EMAC_CAMEN_CAM11EN_Pos              11                                      /*!<EMAC CAMEN: CAM11EN Position    */
#define EMAC_CAMEN_CAM11EN_Msk              (1ul << EMAC_CAMEN_CAM11EN_Pos)         /*!<EMAC CAMEN: CAM11EN Mask        */
#define EMAC_CAMEN_CAM10EN_Pos              10                                      /*!<EMAC CAMEN: CAM10EN Position    */
#define EMAC_CAMEN_CAM10EN_Msk              (1ul << EMAC_CAMEN_CAM10EN_Pos)         /*!<EMAC CAMEN: CAM10EN Mask        */
#define EMAC_CAMEN_CAM9EN_Pos               9                                       /*!<EMAC CAMEN: CAM9EN Position     */
#define EMAC_CAMEN_CAM9EN_Msk               (1ul << EMAC_CAMEN_CAM9EN_Pos)          /*!<EMAC CAMEN: CAM9EN Mask         */
#define EMAC_CAMEN_CAM8EN_Pos               8                                       /*!<EMAC CAMEN: CAM8EN Position     */
#define EMAC_CAMEN_CAM8EN_Msk               (1ul << EMAC_CAMEN_CAM8EN_Pos)          /*!<EMAC CAMEN: CAM8EN Mask         */
#define EMAC_CAMEN_CAM7EN_Pos               7                                       /*!<EMAC CAMEN: CAM7EN Position     */
#define EMAC_CAMEN_CAM7EN_Msk               (1ul << EMAC_CAMEN_CAM7EN_Pos)          /*!<EMAC CAMEN: CAM7EN Mask         */
#define EMAC_CAMEN_CAM6EN_Pos               6                                       /*!<EMAC CAMEN: CAM6EN Position     */
#define EMAC_CAMEN_CAM6EN_Msk               (1ul << EMAC_CAMEN_CAM6EN_Pos)          /*!<EMAC CAMEN: CAM6EN Mask         */
#define EMAC_CAMEN_CAM5EN_Pos               5                                       /*!<EMAC CAMEN: CAM5EN Position     */
#define EMAC_CAMEN_CAM5EN_Msk               (1ul << EMAC_CAMEN_CAM5EN_Pos)          /*!<EMAC CAMEN: CAM5EN Mask         */
#define EMAC_CAMEN_CAM4EN_Pos               4                                       /*!<EMAC CAMEN: CAM4EN Position     */
#define EMAC_CAMEN_CAM4EN_Msk               (1ul << EMAC_CAMEN_CAM4EN_Pos)          /*!<EMAC CAMEN: CAM4EN Mask         */
#define EMAC_CAMEN_CAM3EN_Pos               3                                       /*!<EMAC CAMEN: CAM3EN Position     */
#define EMAC_CAMEN_CAM3EN_Msk               (1ul << EMAC_CAMEN_CAM3EN_Pos)          /*!<EMAC CAMEN: CAM3EN Mask         */
#define EMAC_CAMEN_CAM2EN_Pos               2                                       /*!<EMAC CAMEN: CAM2EN Position     */
#define EMAC_CAMEN_CAM2EN_Msk               (1ul << EMAC_CAMEN_CAM2EN_Pos)          /*!<EMAC CAMEN: CAM2EN Mask         */
#define EMAC_CAMEN_CAM1EN_Pos               1                                       /*!<EMAC CAMEN: CAM1EN Position     */
#define EMAC_CAMEN_CAM1EN_Msk               (1ul << EMAC_CAMEN_CAM1EN_Pos)          /*!<EMAC CAMEN: CAM1EN Mask         */
#define EMAC_CAMEN_CAM0EN_Pos               0                                       /*!<EMAC CAMEN: CAM0EN Position     */
#define EMAC_CAMEN_CAM0EN_Msk               (1ul << EMAC_CAMEN_CAM0EN_Pos)          /*!<EMAC CAMEN: CAM0EN Mask         */

/* EMAC CAMxL Bit Field Definitions */
#define EMAC_CAMxL_LSW_Pos                  16                                      /*!<EMAC CAMxL: LSW Position        */
#define EMAC_CAMxL_LSW_Msk                  (0xFFFFul << EMAC_CAMxL_LSW_Pos)        /*!<EMAC CAMxL: LSW Mask            */

/* EMAC CAM15M Bit Field Definitions */
#define EMAC_CAM15M_LEN_TYPE_Pos            16                                      /*!<EMAC CAM15M: LEN_TYPE Position  */
#define EMAC_CAM15M_LEN_TYPE_Msk            (0xFFFFul << EMAC_CAM15M_LEN_TYPE_Pos)  /*!<EMAC CAM15M: LEN_TYPE Mask      */
#define EMAC_CAM15M_OP_CODE_Pos             0                                       /*!<EMAC CAM15M: OP_CODE Position   */
#define EMAC_CAM15M_OP_CODE_Msk             (0xFFFFul << EMAC_CAM15M_OP_CODE_Pos)   /*!<EMAC CAM15M: OP_CODE Mask       */

/* EMAC CAM15L Bit Field Definitions */
#define EMAC_CAM15L_OPERAND_Pos             24                                      /*!<EMAC CAM15L: OPERAND Position   */
#define EMAC_CAM15L_OPERAND_Msk             (0xFFul << EMAC_CAM15L_OPERAND_Pos)     /*!<EMAC CAM15L: OPERAND Mask       */

/* EMAC MCMDR Bit Field Definitions */
#define EMAC_MCMDR_SWR_Pos                  24                                      /*!<EMAC MCMDR: SWR Position        */
#define EMAC_MCMDR_SWR_Msk                  (1ul << EMAC_MCMDR_SWR_Pos)             /*!<EMAC MCMDR: SWR Mask            */
#define EMAC_MCMDR_ENRMII_Pos               22                                      /*!<EMAC MCMDR: ENRMII Position     */
#define EMAC_MCMDR_ENRMII_Msk               (1ul << EMAC_MCMDR_ENRMII_Pos)          /*!<EMAC MCMDR: ENRMII Mask         */
#define EMAC_MCMDR_LBK_Pos                  21                                      /*!<EMAC MCMDR: LBK Position        */
#define EMAC_MCMDR_LBK_Msk                  (1ul << EMAC_MCMDR_LBK_Pos)             /*!<EMAC MCMDR: LBK Mask            */
#define EMAC_MCMDR_OPMOD_Pos                20                                      /*!<EMAC MCMDR: OPMOD Position      */
#define EMAC_MCMDR_OPMOD_Msk                (1ul << EMAC_MCMDR_OPMOD_Pos)           /*!<EMAC MCMDR: OPMOD Mask          */
#define EMAC_MCMDR_ENMDC_Pos                19                                      /*!<EMAC MCMDR: ENMDC Position      */
#define EMAC_MCMDR_ENMDC_Msk                (1ul << EMAC_MCMDR_ENMDC_Pos)           /*!<EMAC MCMDR: ENMDC Mask          */
#define EMAC_MCMDR_FDUP_Pos                 18                                      /*!<EMAC MCMDR: FDUP Position       */
#define EMAC_MCMDR_FDUP_Msk                 (1ul << EMAC_MCMDR_FDUP_Pos)            /*!<EMAC MCMDR: FDUP Mask           */
#define EMAC_MCMDR_ENSQE_Pos                17                                      /*!<EMAC MCMDR: ENSQE Position      */
#define EMAC_MCMDR_ENSQE_Msk                (1ul << EMAC_MCMDR_ENSQE_Pos)           /*!<EMAC MCMDR: ENSQE Mask          */
#define EMAC_MCMDR_SDPZ_Pos                 16                                      /*!<EMAC MCMDR: SDPZ Position       */
#define EMAC_MCMDR_SDPZ_Msk                 (1ul << EMAC_MCMDR_SDPZ_Pos)            /*!<EMAC MCMDR: SDPZ Mask           */
#define EMAC_MCMDR_NDEF_Pos                 9                                       /*!<EMAC MCMDR: NDEF Position       */
#define EMAC_MCMDR_NDEF_Msk                 (1ul << EMAC_MCMDR_NDEF_Pos)            /*!<EMAC MCMDR: NDEF Mask           */
#define EMAC_MCMDR_TXON_Pos                 8                                       /*!<EMAC MCMDR: TXON Position       */
#define EMAC_MCMDR_TXON_Msk                 (1ul << EMAC_MCMDR_TXON_Pos)            /*!<EMAC MCMDR: TXON Mask           */
#define EMAC_MCMDR_MGP_WAKE_Pos             6                                       /*!<EMAC MCMDR: MGP_WAKE Position   */
#define EMAC_MCMDR_MGP_WAKE_Msk             (1ul << EMAC_MCMDR_MGP_WAKE_Pos)        /*!<EMAC MCMDR: MGP_WAKE Mask       */
#define EMAC_MCMDR_SPCRC_Pos                5                                       /*!<EMAC MCMDR: SPCRC Position      */
#define EMAC_MCMDR_SPCRC_Msk                (1ul << EMAC_MCMDR_SPCRC_Pos)           /*!<EMAC MCMDR: SPCRC Mask          */
#define EMAC_MCMDR_AEP_Pos                  4                                       /*!<EMAC MCMDR: AEP Position        */
#define EMAC_MCMDR_AEP_Msk                  (1ul << EMAC_MCMDR_AEP_Pos)             /*!<EMAC MCMDR: AEP Mask            */
#define EMAC_MCMDR_ACP_Pos                  3                                       /*!<EMAC MCMDR: ACP Position        */
#define EMAC_MCMDR_ACP_Msk                  (1ul << EMAC_MCMDR_ACP_Pos)             /*!<EMAC MCMDR: ACP Mask            */
#define EMAC_MCMDR_ARP_Pos                  2                                       /*!<EMAC MCMDR: ARP Position        */
#define EMAC_MCMDR_ARP_Msk                  (1ul << EMAC_MCMDR_ARP_Pos)             /*!<EMAC MCMDR: ARP Mask            */
#define EMAC_MCMDR_ALP_Pos                  1                                       /*!<EMAC MCMDR: ALP Position        */
#define EMAC_MCMDR_ALP_Msk                  (1ul << EMAC_MCMDR_ALP_Pos)             /*!<EMAC MCMDR: ALP Mask            */
#define EMAC_MCMDR_RXON_Pos                 0                                       /*!<EMAC MCMDR: RXON Position       */
#define EMAC_MCMDR_RXON_Msk                 (1ul << EMAC_MCMDR_RXON_Pos)            /*!<EMAC MCMDR: RXON Mask           */

/* EMAC MIID Bit Field Definitions */
#define EMAC_MIID_DATA_Pos                  0                                       /*!<EMAC MIID: DATA Position        */
#define EMAC_MIID_DATA_Msk                  (0xFFFFul << EMAC_MIID_DATA_Pos)        /*!<EMAC MIID: DATA Mask            */

/* EMAC MIIDA Bit Field Definitions */
#define EMAC_MIIDA_MDCON_Pos                19                                      /*!<EMAC MIIDA: MDCON Position      */
#define EMAC_MIIDA_MDCON_Msk                (1ul << EMAC_MIIDA_MDCON_Pos)           /*!<EMAC MIIDA: MDCON Mask          */
#define EMAC_MIIDA_PRESP_Pos                18                                      /*!<EMAC MIIDA: PRESP Position      */
#define EMAC_MIIDA_PRESP_Msk                (1ul << EMAC_MIIDA_PRESP_Pos)           /*!<EMAC MIIDA: PRESP Mask          */
#define EMAC_MIIDA_BUSY_Pos                 17                                      /*!<EMAC MIIDA: BUSY Position       */
#define EMAC_MIIDA_BUSY_Msk                 (1ul << EMAC_MIIDA_BUSY_Pos)            /*!<EMAC MIIDA: BUSY Mask           */
#define EMAC_MIIDA_WRITE_Pos                16                                      /*!<EMAC MIIDA: WRITE Position      */
#define EMAC_MIIDA_WRITE_Msk                (1ul << EMAC_MIIDA_WRITE_Pos)           /*!<EMAC MIIDA: WRITE Mask          */
#define EMAC_MIIDA_PHYAD_Pos                8                                       /*!<EMAC MIIDA: PHYAD Position      */
#define EMAC_MIIDA_PHYAD_Msk                (0x1Ful << EMAC_MIIDA_PHYAD_Pos)        /*!<EMAC MIIDA: PHYAD Mask          */
#define EMAC_MIIDA_PHYRAD_Pos               0                                       /*!<EMAC MIIDA: PHYRAD Position     */
#define EMAC_MIIDA_PHYRAD_Msk               (0x1Ful << EMAC_MIIDA_PHYRAD_Pos)       /*!<EMAC MIIDA: PHYRAD Mask         */

/* EMAC FFTCR Bit Field Definitions */
#define EMAC_FFTCR_BLENGH_Pos               20                                      /*!<EMAC FFTCR: BLENGH Position     */
#define EMAC_FFTCR_BLENGH_Msk               (3ul << EMAC_FFTCR_BLENGH_Pos)          /*!<EMAC FFTCR: BLENGH Mask         */
#define EMAC_FFTCR_TXTHD_Pos                8                                       /*!<EMAC FFTCR: TXTHD Position      */
#define EMAC_FFTCR_TXTHD_Msk                (3ul << EMAC_FFTCR_TXTHD_Pos)           /*!<EMAC FFTCR: TXTHD Mask          */
#define EMAC_FFTCR_RXTHD_Pos                0                                       /*!<EMAC FFTCR: RXTHD Position      */
#define EMAC_FFTCR_RXTHD_Msk                (3ul << EMAC_FFTCR_RXTHD_Pos)           /*!<EMAC FFTCR: RXTHD Mask          */

/* EMAC DMARFC Bit Field Definitions */
#define EMAC_DMARFC_RXMS_Pos                0                                       /*!<EMAC DMARFC: RXMS Position      */
#define EMAC_DMARFC_RXMS_Msk                (0xFFFFul << EMAC_DMARFC_RXMS_Pos)      /*!<EMAC DMARFC: RXMS Mask          */

/* EMAC MIEN Bit Field Definitions */
#define EMAC_MIEN_ENTSALS_Pos               28                                      /*!<EMAC MIEN: ENTSALS Position     */
#define EMAC_MIEN_ENTSALS_Msk               (1ul << EMAC_MIEN_ENTSALS_Pos)          /*!<EMAC MIEN: ENTSALS Mask         */
#define EMAC_MIEN_ENTXBERR_Pos              24                                      /*!<EMAC MIEN: ENTXBERR Position    */
#define EMAC_MIEN_ENTXBERR_Msk              (1ul << EMAC_MIEN_ENTXBERR_Pos)         /*!<EMAC MIEN: ENTXBERR Mask        */
#define EMAC_MIEN_ENTDU_Pos                 23                                      /*!<EMAC MIEN: ENTDU Position       */
#define EMAC_MIEN_ENTDU_Msk                 (1ul << EMAC_MIEN_ENTDU_Pos)            /*!<EMAC MIEN: ENTDU Mask           */
#define EMAC_MIEN_ENLC_Pos                  22                                      /*!<EMAC MIEN: ENLC Position        */
#define EMAC_MIEN_ENLC_Msk                  (1ul << EMAC_MIEN_ENLC_Pos)             /*!<EMAC MIEN: ENLC Mask            */
#define EMAC_MIEN_ENTXABT_Pos               21                                      /*!<EMAC MIEN: ENTXABT Position     */
#define EMAC_MIEN_ENTXABT_Msk               (1ul << EMAC_MIEN_ENTXABT_Pos)          /*!<EMAC MIEN: ENTXABT Mask         */
#define EMAC_MIEN_ENNCS_Pos                 20                                      /*!<EMAC MIEN: ENNCS Position       */
#define EMAC_MIEN_ENNCS_Msk                 (1ul << EMAC_MIEN_ENNCS_Pos)            /*!<EMAC MIEN: ENNCS Mask           */
#define EMAC_MIEN_ENEXDEF_Pos               19                                      /*!<EMAC MIEN: ENEXDEF Position     */
#define EMAC_MIEN_ENEXDEF_Msk               (1ul << EMAC_MIEN_ENEXDEF_Pos)          /*!<EMAC MIEN: ENEXDEF Mask         */
#define EMAC_MIEN_ENTXCP_Pos                18                                      /*!<EMAC MIEN: ENTXCP Position      */
#define EMAC_MIEN_ENTXCP_Msk                (1ul << EMAC_MIEN_ENTXCP_Pos)           /*!<EMAC MIEN: ENTXCP Mask          */
#define EMAC_MIEN_ENTXEMP_Pos               17                                      /*!<EMAC MIEN: ENTXEMP Position     */
#define EMAC_MIEN_ENTXEMP_Msk               (1ul << EMAC_MIEN_ENTXEMP_Pos)          /*!<EMAC MIEN: ENTXEMP Mask         */
#define EMAC_MIEN_ENTXINTR_Pos              16                                      /*!<EMAC MIEN: ENTXINTR Position    */
#define EMAC_MIEN_ENTXINTR_Msk              (1ul << EMAC_MIEN_ENTXINTR_Pos)         /*!<EMAC MIEN: ENTXINTR Mask        */
#define EMAC_MIEN_ENMPR_Pos                 15                                      /*!<EMAC MIEN: ENMPR Position       */
#define EMAC_MIEN_ENMPR_Msk                 (1ul << EMAC_MIEN_ENMPR_Pos)            /*!<EMAC MIEN: ENMPR Mask           */
#define EMAC_MIEN_ENCFR_Pos                 14                                      /*!<EMAC MIEN: ENCFR Position       */
#define EMAC_MIEN_ENCFR_Msk                 (1ul << EMAC_MIEN_ENCFR_Pos)            /*!<EMAC MIEN: ENCFR Mask           */
#define EMAC_MIEN_ENRXBERR_Pos              11                                      /*!<EMAC MIEN: ENRXBERR Position    */
#define EMAC_MIEN_ENRXBERR_Msk              (1ul << EMAC_MIEN_ENRXBERR_Pos)         /*!<EMAC MIEN: ENRXBERR Mask        */
#define EMAC_MIEN_ENRDU_Pos                 10                                      /*!<EMAC MIEN: ENRDU Position       */
#define EMAC_MIEN_ENRDU_Msk                 (1ul << EMAC_MIEN_ENRDU_Pos)            /*!<EMAC MIEN: ENRDU Mask           */
#define EMAC_MIEN_ENDEN_Pos                 9                                       /*!<EMAC MIEN: ENDEN Position       */
#define EMAC_MIEN_ENDEN_Msk                 (1ul << EMAC_MIEN_ENDEN_Pos)            /*!<EMAC MIEN: ENDEN Mask           */
#define EMAC_MIEN_ENDFO_Pos                 8                                       /*!<EMAC MIEN: ENDFO Position       */
#define EMAC_MIEN_ENDFO_Msk                 (1ul << EMAC_MIEN_ENDFO_Pos)            /*!<EMAC MIEN: ENDFO Mask           */
#define EMAC_MIEN_ENMMP_Pos                 7                                       /*!<EMAC MIEN: ENMMP Position       */
#define EMAC_MIEN_ENMMP_Msk                 (1ul << EMAC_MIEN_ENMMP_Pos)            /*!<EMAC MIEN: ENMMP Mask           */
#define EMAC_MIEN_ENRP_Pos                  6                                       /*!<EMAC MIEN: ENRP Position        */
#define EMAC_MIEN_ENRP_Msk                  (1ul << EMAC_MIEN_ENRP_Pos)             /*!<EMAC MIEN: ENRP Mask            */
#define EMAC_MIEN_ENALIE_Pos                5                                       /*!<EMAC MIEN: ENALIE Position      */
#define EMAC_MIEN_ENALIE_Msk                (1ul << EMAC_MIEN_ENALIE_Pos)           /*!<EMAC MIEN: ENALIE Mask          */
#define EMAC_MIEN_ENRXGD_Pos                4                                       /*!<EMAC MIEN: ENRXGD Position      */
#define EMAC_MIEN_ENRXGD_Msk                (1ul << EMAC_MIEN_ENRXGD_Pos)           /*!<EMAC MIEN: ENRXGD Mask          */
#define EMAC_MIEN_ENPTLE_Pos                3                                       /*!<EMAC MIEN: ENPTLE Position      */
#define EMAC_MIEN_ENPTLE_Msk                (1ul << EMAC_MIEN_ENPTLE_Pos)           /*!<EMAC MIEN: ENPTLE Mask          */
#define EMAC_MIEN_ENRXOV_Pos                2                                       /*!<EMAC MIEN: ENRXOV Position      */
#define EMAC_MIEN_ENRXOV_Msk                (1ul << EMAC_MIEN_ENRXOV_Pos)           /*!<EMAC MIEN: ENRXOV Mask          */
#define EMAC_MIEN_ENCRCE_Pos                1                                       /*!<EMAC MIEN: ENCRCE Position      */
#define EMAC_MIEN_ENCRCE_Msk                (1ul << EMAC_MIEN_ENCRCE_Pos)           /*!<EMAC MIEN: ENCRCE Mask          */
#define EMAC_MIEN_ENRXINTR_Pos              0                                       /*!<EMAC MIEN: ENRXINTR Position    */
#define EMAC_MIEN_ENRXINTR_Msk              (1ul << EMAC_MIEN_ENRXINTR_Pos)         /*!<EMAC MIEN: ENRXINTR Mask        */

/* EMAC MISTA Bit Field Definitions */
#define EMAC_MISTA_TSALS_Pos                28                                      /*!<EMAC MISTA: TSALS Position      */
#define EMAC_MISTA_TSALS_Msk                (1ul << EMAC_MISTA_TSALS_Pos)           /*!<EMAC MISTA: TSALS Mask          */
#define EMAC_MISTA_TXBERR_Pos               24                                      /*!<EMAC MISTA: TXBERR Position     */
#define EMAC_MISTA_TXBERR_Msk               (1ul << EMAC_MISTA_TXBERR_Pos)          /*!<EMAC MISTA: TXBERR Mask         */
#define EMAC_MISTA_TDU_Pos                  23                                      /*!<EMAC MISTA: TXBERR Position     */
#define EMAC_MISTA_TDU_Msk                  (1ul << EMAC_MISTA_TDU_Pos)             /*!<EMAC MISTA: TXBERR Mask         */
#define EMAC_MISTA_LC_Pos                   22                                      /*!<EMAC MISTA: LC Position         */
#define EMAC_MISTA_LC_Msk                   (1ul << EMAC_MISTA_LC_Pos)              /*!<EMAC MISTA: LC Mask             */
#define EMAC_MISTA_TXABT_Pos                21                                      /*!<EMAC MISTA: TXABT Position      */
#define EMAC_MISTA_TXABT_Msk                (1ul << EMAC_MISTA_TXABT_Pos)           /*!<EMAC MISTA: TXABT Mask          */
#define EMAC_MISTA_NCS_Pos                  20                                      /*!<EMAC MISTA: NCS Position        */
#define EMAC_MISTA_NCS_Msk                  (1ul << EMAC_MISTA_NCS_Pos)             /*!<EMAC MISTA: NCS Mask            */
#define EMAC_MISTA_EXDEF_Pos                19                                      /*!<EMAC MISTA: EXDEF Position      */
#define EMAC_MISTA_EXDEF_Msk                (1ul << EMAC_MISTA_EXDEF_Pos)           /*!<EMAC MISTA: EXDEF Mask          */
#define EMAC_MISTA_TXCP_Pos                 18                                      /*!<EMAC MISTA: TXCP Position       */
#define EMAC_MISTA_TXCP_Msk                 (1ul << EMAC_MISTA_TXCP_Pos)            /*!<EMAC MISTA: TXCP Mask           */
#define EMAC_MISTA_TXEMP_Pos                17                                      /*!<EMAC MISTA: TXEMP Position      */
#define EMAC_MISTA_TXEMP_Msk                (1ul << EMAC_MISTA_TXEMP_Pos)           /*!<EMAC MISTA: TXEMP Mask          */
#define EMAC_MISTA_TXINTR_Pos               16                                      /*!<EMAC MISTA: TXINTR Position     */
#define EMAC_MISTA_TXINTR_Msk               (1ul << EMAC_MISTA_TXINTR_Pos)          /*!<EMAC MISTA: TXINTR Mask         */
#define EMAC_MISTA_MPR_Pos                  15                                      /*!<EMAC MISTA: MPR Position        */
#define EMAC_MISTA_MPR_Msk                  (1ul << EMAC_MISTA_MPR_Pos)             /*!<EMAC MISTA: MPR Mask            */
#define EMAC_MISTA_CFR_Pos                  14                                      /*!<EMAC MISTA: CFR Position        */
#define EMAC_MISTA_CFR_Msk                  (1ul << EMAC_MISTA_CFR_Pos)             /*!<EMAC MISTA: CFR Mask            */
#define EMAC_MISTA_RXBERR_Pos               11                                      /*!<EMAC MISTA: RXBERR Position     */
#define EMAC_MISTA_RXBERR_Msk               (1ul << EMAC_MISTA_RXBERR_Pos)          /*!<EMAC MISTA: RXBERR Mask         */
#define EMAC_MISTA_RDU_Pos                  10                                      /*!<EMAC MISTA: RDU Position        */
#define EMAC_MISTA_RDU_Msk                  (1ul << EMAC_MISTA_RDU_Pos)             /*!<EMAC MISTA: RDU Mask            */
#define EMAC_MISTA_DENI_Pos                 9                                       /*!<EMAC MISTA: DENI Position       */
#define EMAC_MISTA_DENI_Msk                 (1ul << EMAC_MISTA_DENI_Pos)            /*!<EMAC MISTA: DENI Mask           */
#define EMAC_MISTA_DFOI_Pos                 8                                       /*!<EMAC MISTA: DFOI Position       */
#define EMAC_MISTA_DFOI_Msk                 (1ul << EMAC_MISTA_DFOI_Pos)            /*!<EMAC MISTA: DFOI Mask           */
#define EMAC_MISTA_MMP_Pos                  7                                       /*!<EMAC MISTA: MMP Position        */
#define EMAC_MISTA_MMP_Msk                  (1ul << EMAC_MISTA_MMP_Pos)             /*!<EMAC MISTA: MMP Mask            */
#define EMAC_MISTA_RP_Pos                   6                                       /*!<EMAC MISTA: RP Position         */
#define EMAC_MISTA_RP_Msk                   (1ul << EMAC_MISTA_RP_Pos)              /*!<EMAC MISTA: RP Mask             */
#define EMAC_MISTA_ALIE_Pos                 5                                       /*!<EMAC MISTA: ALIE Position       */
#define EMAC_MISTA_ALIE_Msk                 (1ul << EMAC_MISTA_ALIE_Pos)            /*!<EMAC MISTA: ALIE Mask           */
#define EMAC_MISTA_RXGD_Pos                 4                                       /*!<EMAC MISTA: RXGD Position       */
#define EMAC_MISTA_RXGD_Msk                 (1ul << EMAC_MISTA_RXGD_Pos)            /*!<EMAC MISTA: RXGD Mask           */
#define EMAC_MISTA_PTLE_Pos                 3                                       /*!<EMAC MISTA: PTLE Position       */
#define EMAC_MISTA_PTLE_Msk                 (1ul << EMAC_MISTA_PTLE_Pos)            /*!<EMAC MISTA: PTLE Mask           */
#define EMAC_MISTA_RXOV_Pos                 2                                       /*!<EMAC MISTA: RXOV Position       */
#define EMAC_MISTA_RXOV_Msk                 (1ul << EMAC_MISTA_RXOV_Pos)            /*!<EMAC MISTA: RXOV Mask           */
#define EMAC_MISTA_CRCE_Pos                 1                                       /*!<EMAC MISTA: CRCE Position       */
#define EMAC_MISTA_CRCE_Msk                 (1ul << EMAC_MISTA_CRCE_Pos)            /*!<EMAC MISTA: CRCE Mask           */
#define EMAC_MISTA_RXINTR_Pos               0                                       /*!<EMAC MISTA: RXINTR Position     */
#define EMAC_MISTA_RXINTR_Msk               (1ul << EMAC_MISTA_RXINTR_Pos)          /*!<EMAC MISTA: RXINTR Mask         */

/* EMAC MGSTA Bit Field Definitions */
#define EMAC_MGSTA_RPAU_Pos                 12                                      /*!<EMAC MGSTA: RPAU Position       */
#define EMAC_MGSTA_RPAU_Msk                 (1ul << EMAC_MGSTA_RPAU_Pos)            /*!<EMAC MGSTA: RPAU Mask           */
#define EMAC_MGSTA_TXHA_Pos                 11                                      /*!<EMAC MGSTA: TXHA Position       */
#define EMAC_MGSTA_TXHA_Msk                 (1ul << EMAC_MGSTA_TXHA_Pos)            /*!<EMAC MGSTA: TXHA Mask           */
#define EMAC_MGSTA_SQE_Pos                  10                                      /*!<EMAC MGSTA: SQE Position        */
#define EMAC_MGSTA_SQE_Msk                  (1ul << EMAC_MGSTA_SQE_Pos)             /*!<EMAC MGSTA: SQE Mask            */
#define EMAC_MGSTA_PAU_Pos                  9                                       /*!<EMAC MGSTA: PAU Position        */
#define EMAC_MGSTA_PAU_Msk                  (1ul << EMAC_MGSTA_PAU_Pos)             /*!<EMAC MGSTA: PAU Mask            */
#define EMAC_MGSTA_DEF_Pos                  8                                       /*!<EMAC MGSTA: DEF Position        */
#define EMAC_MGSTA_DEF_Msk                  (1ul << EMAC_MGSTA_DEF_Pos)             /*!<EMAC MGSTA: DEF Mask            */
#define EMAC_MGSTA_CCNT_Pos                 4                                       /*!<EMAC MGSTA: CCNT Position       */
#define EMAC_MGSTA_CCNT_Msk                 (0xFul << EMAC_MGSTA_CCNT_Pos)          /*!<EMAC MGSTA: CCNT Mask           */
#define EMAC_MGSTA_RFFULL_Pos               2                                       /*!<EMAC MGSTA: RFFULL Position     */
#define EMAC_MGSTA_RFFULL_Msk               (1ul << EMAC_MGSTA_RFFULL_Pos)          /*!<EMAC MGSTA: RFFULL Mask         */
#define EMAC_MGSTA_RXHA_Pos                 1                                       /*!<EMAC MGSTA: RXHA Position       */
#define EMAC_MGSTA_RXHA_Msk                 (1ul << EMAC_MGSTA_RXHA_Pos)            /*!<EMAC MGSTA: RXHA Mask           */
#define EMAC_MGSTA_CFR_Pos                  0                                       /*!<EMAC MGSTA: CFR Position        */
#define EMAC_MGSTA_CFR_Msk                  (1ul << EMAC_MGSTA_CFR_Pos)             /*!<EMAC MGSTA: CFR Mask            */

/* EMAC MPCNT Bit Field Definitions */
#define EMAC_MPCNT_MPC_Pos                  0                                       /*!<EMAC MPCNT: MPC Position        */
#define EMAC_MPCNT_MPC_Msk                  (0xFFFFul << EMAC_MPCNT_MPC_Pos)        /*!<EMAC MPCNT: MPC Mask            */

/* EMAC MRPC Bit Field Definitions */
#define EMAC_MRPC_MRPC_Pos                  0                                       /*!<EMAC MRPC: MRPC Position        */
#define EMAC_MRPC_MRPC_Msk                  (0xFFFFul << EMAC_MRPC_MRPC_Pos)        /*!<EMAC MRPC: MRPC Mask            */

/* EMAC DMARFS Bit Field Definitions */
#define EMAC_DMARFS_RXFLT_Pos               0                                       /*!<EMAC DMARFS: RXFLT Position     */
#define EMAC_DMARFS_RXFLT_Msk               (0xFFFFul << EMAC_DMARFS_RXFLT_Pos)     /*!<EMAC DMARFS: RXFLT Mask */

/* EMAC TSCR Bit Field Definitions */
#define EMAC_TSCR_TSALEN_Pos                5                                       /*!<EMAC TSCR: TSALEN Position      */
#define EMAC_TSCR_TSALEN_Msk                (1ul << EMAC_TSCR_TSALEN_Pos)           /*!<EMAC TSCR: TSALEN Mask          */
#define EMAC_TSCR_TSTUEN_Pos                3                                       /*!<EMAC TSCR: TSTUEN Position      */
#define EMAC_TSCR_TSTUEN_Msk                (1ul << EMAC_TSCR_TSTUEN_Pos)           /*!<EMAC TSCR: TSTUEN Mask          */
#define EMAC_TSCR_TSFUEN_Pos                2                                       /*!<EMAC TSCR: TSFUEN Position      */
#define EMAC_TSCR_TSFUEN_Msk                (1ul << EMAC_TSCR_TSFUEN_Pos)           /*!<EMAC TSCR: TSFUEN Mask          */
#define EMAC_TSCR_TSIEN_Pos                 1                                       /*!<EMAC TSCR: TSIEN Position       */
#define EMAC_TSCR_TSIEN_Msk                 (1ul << EMAC_TSCR_TSIEN_Pos)            /*!<EMAC TSCR: TSIEN Mask           */
#define EMAC_TSCR_TSEN_Pos                  0                                       /*!<EMAC TSCR: TSEN Position        */
#define EMAC_TSCR_TSEN_Msk                  (1ul << EMAC_TSCR_TSEN_Pos)             /*!<EMAC TSCR: TSEN Mask            */

/* EMAC TSIR Bit Field Definitions */
#define EMAC_TSIR_TSCI_Pos                  0                                       /*!<EMAC TSIR: TSCI Position        */
#define EMAC_TSIR_TSCI_Msk                  (0xFF << EMAC_TSIR_TSCI_Pos)            /*!<EMAC TSIR: TSCI Mask            */

/*@}*/ /* end of group NUC400_EMAC */


/*------------- Flash Memory Controller (FMC) -----------------------------*/
/** @addtogroup NUC400_FMC NUC400 Flash Memory Controller Register (FMC)
  @{
*/
typedef struct {
    __IO uint32_t ISPCON;                     /*!< Offset: 0x0000   ISP Control Register                               */
    __IO uint32_t ISPADR;                     /*!< Offset: 0x0004   ISP Address Register                               */
    __IO uint32_t ISPDAT;                     /*!< Offset: 0x0008   ISP Data Register                                  */
    __IO uint32_t ISPCMD;                     /*!< Offset: 0x000C   ISP Command Register                               */
    __IO uint32_t ISPTRG;                     /*!< Offset: 0x0010   ISP Trigger Register                               */
    __I  uint32_t DFBADR;                     /*!< Offset: 0x0014   Data Flash Start Address (CONFIG1)                 */
    __IO uint32_t FATCON;                     /*!< Offset: 0x0018   Flash Access Window Control Register               */
    uint32_t RESERVED0[9];               /*!< Offset: 0x001C ~ 0x003C   Reserved                                  */
    __IO uint32_t ISPSTA;                     /*!< Offset: 0x0040   ISP Status Register                                */
    __IO uint32_t FBWP;                       /*!< Offset: 0x0044   Flash Block Write Protect Control Register         */
    uint32_t RESERVED1[14];              /*!< Offset: 0x0048 ~ 0x007C   Reserved                                  */
    __IO uint32_t ISPDAT0;                    /*!< Offset: 0x0080   ISP Data0 Register                                 */
    __IO uint32_t ISPDAT1;                    /*!< Offset: 0x0084   ISP Data1 Register                                 */
    __IO uint32_t ISPDAT2;                    /*!< Offset: 0x0088   ISP Data2 Register                                 */
    __IO uint32_t ISPDAT3;                    /*!< Offset: 0x008C   ISP Data3 Register                                 */
    uint32_t RESERVED2[12];              /*!< Offset: 0x0090 ~ 0x00BC   Reserved                                  */
    __IO uint32_t ISPPSTA;                    /*!< Offset: 0x00C0   ISP Page Program status                            */
    __IO uint32_t ISPPADR;                    /*!< Offset: 0x00C4   ISP Page Program Address status                    */
} FMC_T;

/********************* Bit definition of ISPCON register **********************/
#define FMC_ISPCON_ISPEN_Pos        0                                /*!<FMC ISPCON: ISPEN Position */
#define FMC_ISPCON_ISPEN_Msk        (1ul << FMC_ISPCON_ISPEN_Pos)    /*!<FMC ISPCON: ISPEN Mask */
#define FMC_ISPCON_BS_Pos           1                                /*!<FMC ISPCON: BS Position */
#define FMC_ISPCON_BS_Msk           (1ul << FMC_ISPCON_BS_Pos)       /*!<FMC ISPCON: BS Mask */
#define FMC_ISPCON_APUEN_Pos        3                                /*!<FMC ISPCON: APUEN Position */
#define FMC_ISPCON_APUEN_Msk        (1ul << FMC_ISPCON_APUEN_Pos)    /*!<FMC ISPCON: APUEN Mask */
#define FMC_ISPCON_CFGUEN_Pos       4                                /*!<FMC ISPCON: CFGUEN Position */
#define FMC_ISPCON_CFGUEN_Msk       (1ul << FMC_ISPCON_CFGUEN_Pos)   /*!<FMC ISPCON: CFGUEN Mask */
#define FMC_ISPCON_LDUEN_Pos        5                                /*!<FMC ISPCON: LDUEN Position */
#define FMC_ISPCON_LDUEN_Msk        (1ul << FMC_ISPCON_LDUEN_Pos)    /*!<FMC ISPCON: LDUEN Mask */
#define FMC_ISPCON_ISPFF_Pos        6                                /*!<FMC ISPCON: ISPFF Position */
#define FMC_ISPCON_ISPFF_Msk        (1ul << FMC_ISPCON_ISPFF_Pos)    /*!<FMC ISPCON: ISPFF Mask */

/********************* Bit definition of ISPCMD register **********************/
#define FMC_ISPCMD_FCTRL_Pos        0                                /*!<FMC ISPCMD: FCTRL Position */
#define FMC_ISPCMD_FCTRL_Msk        (15ul << FMC_ISPCMD_FCTRL_Pos)   /*!<FMC ISPCMD: FCTRL Mask */
#define FMC_ISPCMD_FCEN_Pos         4                                /*!<FMC ISPCMD: FCEN Position */
#define FMC_ISPCMD_FCEN_Msk         (1ul << FMC_ISPCMD_FCEN_Pos)     /*!<FMC ISPCMD: FCEN Mask */
#define FMC_ISPCMD_FOEN_Pos         5                                /*!<FMC ISPCMD: FOEN Position */
#define FMC_ISPCMD_FOEN_Msk         (1ul << FMC_ISPCMD_FOEN_Pos)     /*!<FMC ISPCMD: FOEN Mask */
#define FMC_ISPCMD_D64_Pos          6                                /*!<FMC ISPCMD: D64 Position */
#define FMC_ISPCMD_D64_Msk          (1ul << FMC_ISPCMD_D64_Pos)      /*!<FMC ISPCMD: D64 Mask */

/********************* Bit definition of ISPTRG register **********************/
#define FMC_ISPTRG_ISPGO_Pos        0                                /*!<FMC ISPTRG: ISPGO Position */
#define FMC_ISPTRG_ISPGO_Msk        (1ul << FMC_ISPTRG_ISPGO_Pos)    /*!<FMC ISPTRG: ISPGO Mask */

/********************* Bit definition of FATCON register **********************/
#define FMC_FATCON_FOM_Pos          4                                /*!<FMC FATCON: FOM Position */
#define FMC_FATCON_FOM_Msk          (7ul << FMC_FATCON_FOM_Pos)      /*!<FMC FATCON: FOM Mask */
#define FMC_FATCON_FB_DIS_Pos       7                                /*!<FMC FATCON: FB_DIS Position */
#define FMC_FATCON_FB_DIS_Msk       (1ul << FMC_FATCON_FB_DIS_Pos)   /*!<FMC FATCON: FB_DIS Mask */

/********************* Bit definition of ISPSTA register **********************/
#define FMC_ISPSTA_ISPGO_Pos        0                                /*!<FMC ISPSTA: ISPGO Position */
#define FMC_ISPSTA_ISPGO_Msk        (1ul << FMC_ISPSTA_ISPGO_Pos)    /*!<FMC ISPSTA: ISPGO Mask */
#define FMC_ISPSTA_CBS_Pos          1                                /*!<FMC ISPSTA: CBS Position */
#define FMC_ISPSTA_CBS_Msk          (3ul << FMC_ISPSTA_CBS_Pos)      /*!<FMC ISPSTA: CBS Mask */
#define FMC_ISPSTA_LDWF_Pos         3                                /*!<FMC ISPSTA: LDWF Position */
#define FMC_ISPSTA_LDWF_Msk         (1ul << FMC_ISPSTA_LDWF_Pos)     /*!<FMC ISPSTA: LDWF Mask */
#define FMC_ISPSTA_ISPFF_Pos        6                                /*!<FMC ISPSTA: ISPFF Position */
#define FMC_ISPSTA_ISPFF_Msk        (1ul << FMC_ISPSTA_ISPFF_Pos)    /*!<FMC ISPSTA: ISPFF Mask */
#define FMC_ISPSTA_VECMAP_Pos       9                                /*!<FMC ISPSTA: VECMAP Position */
#define FMC_ISPSTA_VECMAP_Msk       (0xffful << FMC_ISPSTA_VECMAP_Pos) /*!<FMC ISPSTA: VECMAP Mask */
#define FMC_ISPSTA_CFGCRCF_Pos      26                               /*!<FMC ISPSTA: CFGCRCF Position */
#define FMC_ISPSTA_CFGCRCF_Msk      (1ul << FMC_ISPSTA_CFGCRCF_Pos)  /*!<FMC ISPSTA: CFGCRCF Mask */

/********************* Bit definition of ISPPSTA register *********************/
#define FMC_ISPPSTA_ISPGO_Pos        0                               /*!<FMC ISPPSTA: ISPGO Position */
#define FMC_ISPPSTA_ISPGO_Msk        (1ul << FMC_ISPPSTA_ISPGO_Pos)  /*!<FMC ISPPSTA: ISPGO Mask */
#define FMC_ISPPSTA_PPGO_Pos         1                               /*!<FMC ISPPSTA: PPGO Position */
#define FMC_ISPPSTA_PPGO_Msk         (1ul << FMC_ISPPSTA_PPGO_Pos)   /*!<FMC ISPPSTA: PPGO Mask */
#define FMC_ISPPSTA_ISPFF_Pos        2                               /*!<FMC ISPPSTA: ISPFF Position */
#define FMC_ISPPSTA_ISPFF_Msk        (1ul << FMC_ISPPSTA_ISPFF_Pos)  /*!<FMC ISPPSTA: ISPFF Mask */
#define FMC_ISPPSTA_D0_Pos           4                               /*!<FMC ISPPSTA: D0 Position */
#define FMC_ISPPSTA_D0_Msk           (1ul << FMC_ISPPSTA_D0_Pos)     /*!<FMC ISPPSTA: D0 Mask */
#define FMC_ISPPSTA_D1_Pos           5                               /*!<FMC ISPPSTA: D1 Position */
#define FMC_ISPPSTA_D1_Msk           (1ul << FMC_ISPPSTA_D1_Pos)     /*!<FMC ISPPSTA: D1 Mask */
#define FMC_ISPPSTA_D2_Pos           6                               /*!<FMC ISPPSTA: D2 Position */
#define FMC_ISPPSTA_D2_Msk           (1ul << FMC_ISPPSTA_D2_Pos)     /*!<FMC ISPPSTA: D2 Mask */
#define FMC_ISPPSTA_D3_Pos           7                               /*!<FMC ISPPSTA: D3 Position */
#define FMC_ISPPSTA_D3_Msk           (1ul << FMC_ISPPSTA_D3_Pos)     /*!<FMC ISPPSTA: D3 Mask */

/*@}*/ /* end of group NUC400_FMC */

/*------------- SD Control Register (SD) -----------------------------*/
/** @addtogroup NUC400_SD NUC400 SD Control Register
  @{
*/
typedef struct {
    __IO uint32_t FMI_FB_0;                    /*!< Offset: 0x0000   DMAC Shared Buffer (FIFO)                                */
    uint32_t RESERVED0[255];                /*!< Offset: 0x0004 ~ 0x03FC Reserved                                    */
    __IO uint32_t DMACCSR;                    /*!< Offset: 0x0400   DMAC Control and Status Register                    */
    uint32_t RESERVED1;                    /*!< Offset: 0x0404      Reserved                                              */
    __IO uint32_t DMACSAR;                    /*!< Offset: 0x0408   DMAC Transfer Starting Address Registr             */
    __I  uint32_t DMACBCR;                       /*!< Offset: 0x040C   DMAC Byte Count Register                              */
    __IO uint32_t DMACIER;                    /*!< Offset: 0x0410   DMAC Interrupt Enable Register                      */
    __IO uint32_t DMACISR;                    /*!< Offset: 0x0414   DMAC Interrupt Status Register                      */
    uint32_t RESERVED2[250];                 /*!< Offset: 0x0418 ~ 0x07FC Reserved                                    */
    __IO uint32_t FMICR;                        /*!< Offset: 0x0800   FMI Global Control and Status Register              */
    __IO uint32_t FMIIER;                        /*!< Offset: 0x0804   FMI Interrupt Control Register                      */
    __IO uint32_t FMIISR;                        /*!< Offset: 0x0808   FMI Interrupt Status Register                      */
    uint32_t RESERVED3[5];                /*!< Offset: 0x080C ~ 0x081C Reserved                                    */
    __IO uint32_t SDCR;                        /*!< Offset: 0x0820   SD Control and Status Register                      */
    __IO uint32_t SDARG;                        /*!< Offset: 0x0824   SD Control Argument Register                            */
    __IO uint32_t SDIER;                        /*!< Offset: 0x0828   SD Interrupt Control Register                      */
    __IO uint32_t SDISR;                        /*!< Offset: 0x082C   SD Interrupt Status Register                           */
    __I  uint32_t SDRSP0;                       /*!< Offset: 0x0830   SD Receiving Resonse Token Register 0              */
    __I  uint32_t SDRSP1;                       /*!< Offset: 0x0834   SD Receiving Resonse Token Register 0              */
    __IO uint32_t SDBLEN;                        /*!< Offset: 0x0838   SD Block Length Register                               */
    __IO uint32_t SDTMOUT;                       /*!< Offset: 0x083C   SD Response/Data-in Timeout                          */
} SD_T;


/* SD DMACCSR Bit Field Definitions */
#define SD_DMACCSR_DMACEN_Pos         0                                    /*!< SD DMACCSR: DMACEN Position      */
#define SD_DMACCSR_DMACEN_Msk         (1ul << SD_DMACCSR_DMACEN_Pos)     /*!< SD DMACCSR: DMACEN Mask          */

#define SD_DMACCSR_SW_RST_Pos         1                                    /*!< SD DMACCSR: SW_RST Position      */
#define SD_DMACCSR_SW_RST_Msk         (1ul << SD_DMACCSR_SW_RST_Pos)     /*!< SD DMACCSR: SW_RST Mask          */

#define SD_DMACCSR_SG_EN2_Pos         3                                    /*!< SD DMACCSR: SG_EN2 Position      */
#define SD_DMACCSR_SG_EN2_Msk         (1ul << SD_DMACCSR_DMACEN_Pos)     /*!< SD DMACCSR: SG_EN2 Mask          */

#define SD_DMACCSR_FMI_BUSY_Pos         9                                      /*!< SD DMACCSR: FMI_BUSY Position      */
#define SD_DMACCSR_FMI_BUSY_Msk         (1ul << SD_DMACCSR_FMI_BUSY_Pos)     /*!< SD DMACCSR: FMI_BUSY Mask          */

/* SD DMACSAR Bit Field Definitions */
#define SD_DMACSAR_DMACSA_Pos         0                                    /*!< SD DMACSAR: DMACSA Position      */
#define SD_DMACSAR_DMACSA_Msk         (0xFFFFFFFFul << SD_DMACSAR_DMACSA_Pos)     /*!< SD DMACSAR: DMACSA Mask          */

#define SD_DMACSAR_ORDER_Pos             0                                    /*!< SD DMACSAR: ORDER Position      */
#define SD_DMACSAR_ORDER_Msk             (1ul << SD_DMACSAR_ORDER_Pos)     /*!< SD DMACSAR: ORDER Mask          */

/* SD DMACBCR Bit Field Definitions */
#define SD_DMACBCR_BCNT_Pos             0                                    /*!< SD DMACBCR: BCNT Position      */
#define SD_DMACBCR_BCNT_Msk             (0xFFFFFFul << SD_DMACBCR_BCNT_Pos)     /*!< SD DMACBCR: BCNT Mask          */

/* SD DMACIER Bit Field Definitions */
#define SD_DMACIER_TABORT_IE_Pos             0                                    /*!< SD DMACIER: TABORT_IE Position      */
#define SD_DMACIER_TABORT_IE_Msk             (1ul << SD_DMACIER_TABORT_IE_Pos)     /*!< SD DMACIER: TABORT_IE Mask          */

#define SD_DMACIER_WEOT_IE_Pos             1                                    /*!< SD DMACIER: WEOT_IE Position      */
#define SD_DMACIER_WEOT_IE_Msk             (1ul << SD_DMACIER_WEOT_IE_Pos)     /*!< SD DMACIER: WEOT_IE Mask          */

/* SD DMACISR Bit Field Definitions */
#define SD_DMACISR_TABORT_IF_Pos             0                                    /*!< SD DMACISR: TABORT_IF Position      */
#define SD_DMACISR_TABORT_IF_Msk             (1ul << SD_DMACISR_TABORT_IF_Pos)     /*!< SD DMACISR: TABORT_IF Mask          */

#define SD_DMACISR_WEOT_IF_Pos             1                                    /*!< SD DMACISR: WEOT_IF Position      */
#define SD_DMACISR_WEOT_IF_Msk             (1ul << SD_DMACISR_WEOT_IF_Pos)     /*!< SD DMACISR: WEOT_IF Mask          */

/* SD FMICR Bit Field Definitions */
#define SD_FMICR_SW_RST_Pos             0                                    /*!< SD FMICR: SW_RST Position      */
#define SD_FMICR_SW_RST_Msk             (1ul << SD_FMICR_SW_RST_Pos)     /*!< SD FMICR: SW_RST Mask          */

#define SD_FMICR_SD_EN_Pos             1                                    /*!< SD FMICR: SD_EN Position      */
#define SD_FMICR_SD_EN_Msk             (1ul << SD_FMICR_SD_EN_Pos)     /*!< SD FMICR: SD_EN Mask          */

/* SD FMIIER Bit Field Definitions */
#define SD_FMIIER_DTA_IE_Pos             0                                    /*!< SD FMIIER: DTA_IE Position      */
#define SD_FMIIER_DTA_IE_Msk             (1ul << SD_FMIIER_DTA_IE_Pos)     /*!< SD FMIIER: DTA_IE Mask          */

/* SD FMIISR Bit Field Definitions */
#define SD_FMIISR_DTA_IE_Pos             0                                    /*!< SD FMIISR: DTA_IE Position      */
#define SD_FMIISR_DTA_IE_Msk             (1ul << SD_FMIISR_DTA_IE_Pos)     /*!< SD FMIISR: DTA_IE Mask          */

/* SD SDCR Bit Field Definitions */
#define SD_SDCR_CO_EN_Pos             0                                    /*!< SD SDCR: CO_EN Position      */
#define SD_SDCR_CO_EN_Msk             (1ul << SD_SDCR_CO_EN_Pos)     /*!< SD SDCR: CO_EN Mask          */

#define SD_SDCR_RI_EN_Pos             1                                    /*!< SD SDCR: RI_EN Position      */
#define SD_SDCR_RI_EN_Msk             (1ul << SD_SDCR_RI_EN_Pos)     /*!< SD SDCR: RI_EN Mask          */

#define SD_SDCR_DI_EN_Pos             2                                    /*!< SD SDCR: DI_EN Position      */
#define SD_SDCR_DI_EN_Msk             (1ul << SD_SDCR_DI_EN_Pos)     /*!< SD SDCR: DI_EN Mask          */

#define SD_SDCR_DO_EN_Pos             3                                    /*!< SD SDCR: DO_EN Position      */
#define SD_SDCR_DO_EN_Msk             (1ul << SD_SDCR_DO_EN_Pos)     /*!< SD SDCR: DO_EN Mask          */

#define SD_SDCR_R2_EN_Pos             4                                    /*!< SD SDCR: R2_EN Position      */
#define SD_SDCR_R2_EN_Msk             (1ul << SD_SDCR_R2_EN_Pos)     /*!< SD SDCR: R2_EN Mask          */

#define SD_SDCR_CLK74_OE_Pos             5                                    /*!< SD SDCR: CLK74_OE Position      */
#define SD_SDCR_CLK74_OE_Msk             (1ul << SD_SDCR_CLK74_OE_Pos)     /*!< SD SDCR: CLK74_OE Mask          */

#define SD_SDCR_CLK8_OE_Pos             6                                    /*!< SD SDCR: CLK8_OE Position      */
#define SD_SDCR_CLK8_OE_Msk             (1ul << SD_SDCR_CLK8_OE_Pos)     /*!< SD SDCR: CLK8_OE Mask          */

#define SD_SDCR_CLK_KEEP0_Pos         7                                    /*!< SD SDCR: CLK_KEEP0 Position      */
#define SD_SDCR_CLK_KEEP0_Msk         (1ul << SD_SDCR_CLK_KEEP0_Pos)     /*!< SD SDCR: CLK_KEEP0 Mask          */

#define SD_SDCR_CMD_CODE_Pos             8                                    /*!< SD SDCR: CMD_CODE Position      */
#define SD_SDCR_CMD_CODE_Msk             (0x3Ful << SD_SDCR_CMD_CODE_Pos)     /*!< SD SDCR: CMD_CODE Mask          */

#define SD_SDCR_SW_RST_Pos             14                                    /*!< SD SDCR: SW_RST Position      */
#define SD_SDCR_SW_RST_Msk             (1ul << SD_SDCR_SW_RST_Pos)     /*!< SD SDCR: SW_RST Mask          */

#define SD_SDCR_DBW_Pos                 15                                    /*!< SD SDCR: DBW Position      */
#define SD_SDCR_DBW_Msk                 (1ul << SD_SDCR_DBW_Pos)     /*!< SD SDCR: DBW Mask          */

#define SD_SDCR_BLK_CNT_Pos             16                                    /*!< SD SDCR: BLK_CNT Position      */
#define SD_SDCR_BLK_CNT_Msk             (0xFFul << SD_SDCR_BLK_CNT_Pos)     /*!< SD SDCR: BLK_CNT Mask          */

#define SD_SDCR_SDNWR_Pos             24                                    /*!< SD SDCR: SDNWR Position      */
#define SD_SDCR_SDNWR_Msk             (0xFul << SD_SDCR_SDNWR_Pos)     /*!< SD SDCR: SDNWR Mask          */

#define SD_SDCR_CLK_KEEP2_Pos         28                                    /*!< SD SDCR: CLK_KEEP2 Position      */
#define SD_SDCR_CLK_KEEP2_Msk         (1ul << SD_SDCR_CLK_KEEP2_Pos)     /*!< SD SDCR: CLK_KEEP2 Mask          */

#define SD_SDCR_SDPORT_Pos             29                                    /*!< SD SDCR: SDPORT Position      */
#define SD_SDCR_SDPORT_Msk             (3ul << SD_SDCR_SDPORT_Pos)     /*!< SD SDCR: SDPORT Mask          */

#define SD_SDCR_CLK_KEEP1_Pos         31                                   /*!< SD SDCR: CLK_KEEP1 Position      */
#define SD_SDCR_CLK_KEEP1_Msk         (1ul << SD_SDCR_CLK_KEEP1_Pos)     /*!< SD SDCR: CLK_KEEP1 Mask          */

/* SD SDARG Bit Field Definitions */
#define SD_SDARG_SD_CMD_ARG_Pos         0                                    /*!< SD SDARG: SD_CMD_ARG Position      */
#define SD_SDARG_SD_CMD_ARG_Msk         (0xFFFFFFFFul << SD_SDARG_SD_CMD_ARG_Pos)     /*!< SD SDARG: SD_CMD_ARG Mask          */

/* SD SDIER Bit Field Definitions */
#define SD_SDIER_BLKD_IE_Pos         0                                    /*!< SD SDIER: BLKD_IE Position      */
#define SD_SDIER_BLKD_IE_Msk         (1ul << SD_SDIER_BLKD_IE_Pos)     /*!< SD SDIER: BLKD_IE Mask          */

#define SD_SDIER_CRC_IE_Pos         1                                    /*!< SD SDIER: CRC_IE Position      */
#define SD_SDIER_CRC_IE_Msk         (1ul << SD_SDIER_CRC_IE_Pos)         /*!< SD SDIER: CRC_IE Mask          */

#define SD_SDIER_CD0_IE_Pos         8                                    /*!< SD SDIER: CD0_IE Position      */
#define SD_SDIER_CD0_IE_Msk         (1ul << SD_SDIER_CD0_IE_Pos)         /*!< SD SDIER: CD0_IE Mask          */

#define SD_SDIER_CD1_IE_Pos         9                                    /*!< SD SDIER: CD1_IE Position      */
#define SD_SDIER_CD1_IE_Msk         (1ul << SD_SDIER_CD1_IE_Pos)         /*!< SD SDIER: CD1_IE Mask          */

#define SD_SDIER_SD0_IE_Pos        10                                    /*!< SD SDIER: SD0_IE Position      */
#define SD_SDIER_SD0_IE_Msk        (1ul << SD_SDIER_SD0_IE_Pos)     /*!< SD SDIER: SD0_IE Mask          */

#define SD_SDIER_SD1_IE_Pos        11                                    /*!< SD SDIER: SD1_IE Position      */
#define SD_SDIER_SD1_IE_Msk        (1ul << SD_SDIER_SD1_IE_Pos)     /*!< SD SDIER: SD1_IE Mask          */

#define SD_SDIER_RITO_IE_Pos        12                                    /*!< SD SDIER: RITO_IE Position      */
#define SD_SDIER_RITO_IE_Msk        (1ul << SD_SDIER_RITO_IE_Pos)     /*!< SD SDIER: RITO_IE Mask          */

#define SD_SDIER_DITO_IE_Pos        13                                    /*!< SD SDIER: DITO_IE Position      */
#define SD_SDIER_DITO_IE_Msk        (1ul << SD_SDIER_DITO_IE_Pos)     /*!< SD SDIER: DITO_IE Mask          */

#define SD_SDIER_WKUP_EN_Pos        14                                    /*!< SD SDIER: WKUP_EN Position      */
#define SD_SDIER_WKUP_EN_Msk        (1ul << SD_SDIER_WKUP_EN_Pos)     /*!< SD SDIER: WKUP_EN Mask          */

#define SD_SDIER_CD0SRC_Pos        30                                    /*!< SD SDIER: CD0SRC Position      */
#define SD_SDIER_CD0SRC_Msk        (1ul << SD_SDIER_CD0SRC_Pos)         /*!< SD SDIER: CD0SRC Mask          */

#define SD_SDIER_CD1SRC_Pos        31                                    /*!< SD SDIER: CD1SRC Position      */
#define SD_SDIER_CD1SRC_Msk        (1ul << SD_SDIER_CD1SRC_Pos)         /*!< SD SDIER: CD1SRC Mask          */

/* SD SDISR Bit Field Definitions */
#define SD_SDISR_BLKD_IF_Pos        0                                    /*!< SD SDISR: BLKD_IF Position      */
#define SD_SDISR_BLKD_IF_Msk        (1ul << SD_SDISR_BLKD_IF_Pos)     /*!< SD SDISR: BLKD_IF Mask          */

#define SD_SDISR_CRC_IF_Pos        1                                    /*!< SD SDISR: CRC_IF Position      */
#define SD_SDISR_CRC_IF_Msk        (1ul << SD_SDISR_CRC_IF_Pos)         /*!< SD SDISR: CRC_IF Mask          */

#define SD_SDISR_CRC_7_Pos        2                                    /*!< SD SDISR: CRC_7 Position      */
#define SD_SDISR_CRC_7_Msk        (1ul << SD_SDISR_CRC_7_Pos)         /*!< SD SDISR: CRC_7 Mask          */

#define SD_SDISR_CRC_16_Pos        3                                    /*!< SD SDISR: CRC_16 Position      */
#define SD_SDISR_CRC_16_Msk        (1ul << SD_SDISR_CRC_16_Pos)         /*!< SD SDISR: CRC_16 Mask          */

#define SD_SDISR_CRCSTAT_Pos        4                                    /*!< SD SDISR: CRCSTAT Position      */
#define SD_SDISR_CRCSTAT_Msk        (7ul << SD_SDISR_CRCSTAT_Pos)     /*!< SD SDISR: CRCSTAT Mask          */

#define SD_SDISR_SDDAT0_Pos        7                                    /*!< SD SDISR: SDDAT0 Position      */
#define SD_SDISR_SDDAT0_Msk        (1ul << SD_SDISR_SDDAT0_Pos)         /*!< SD SDISR: SDDAT0 Mask          */

#define SD_SDISR_CD0_IF_Pos        8                                    /*!< SD SDISR: CD0_IF Position      */
#define SD_SDISR_CD0_IF_Msk        (1ul << SD_SDISR_CD0_IF_Pos)         /*!< SD SDISR: CD0_IF Mask          */

#define SD_SDISR_CD1_IF_Pos        9                                    /*!< SD SDISR: CD1_IF Position      */
#define SD_SDISR_CD1_IF_Msk        (1ul << SD_SDISR_CD1_IF_Pos)         /*!< SD SDISR: CD1_IF Mask          */

#define SD_SDISR_SD0_IF_Pos        10                                    /*!< SD SDISR: SD0_IF Position  */
#define SD_SDISR_SD0_IF_Msk        (1ul << SD_SDISR_SD0_IF_Pos)     /*!< SD SDISR: SD0_IF Mask      */

#define SD_SDISR_SD1_IF_Pos        11                                    /*!< SD SDISR: SD0_IF Position  */
#define SD_SDISR_SD1_IF_Msk        (1ul << SD_SDISR_SD1_IF_Pos)     /*!< SD SDISR: SD1_IF Mask      */

#define SD_SDISR_RITO_IF_Pos        12                                    /*!< SD SDISR: RITO_IF Position      */
#define SD_SDISR_RITO_IF_Msk        (1ul << SD_SDISR_RITO_IF_Pos)     /*!< SD SDISR: RITO_IF Mask          */

#define SD_SDISR_DITO_IF_Pos        13                                    /*!< SD SDISR: DITO_IF Position      */
#define SD_SDISR_DITO_IF_Msk        (1ul << SD_SDISR_DITO_IF_Pos)     /*!< SD SDISR: DITO_IF Mask          */

#define SD_SDISR_CDPS0_Pos        16                                    /*!< SD SDISR: CDPS0 Position      */
#define SD_SDISR_CDPS0_Msk        (1ul << SD_SDISR_CDPS0_Pos)         /*!< SD SDISR: CDPS0 Mask          */

#define SD_SDISR_CDPS1_Pos        17                                    /*!< SD SDISR: CDPS1 Position      */
#define SD_SDISR_CDPS1_Msk        (1ul << SD_SDISR_CDPS1_Pos)         /*!< SD SDISR: CDPS1 Mask          */

#define SD_SDISR_SDDAT1_Pos        18                                    /*!< SD SDISR: SDDAT1 Position      */
#define SD_SDISR_SDDAT1_Msk        (1ul << SD_SDISR_SDDAT1_Pos)         /*!< SD SDISR: SDDAT1 Mask          */

/* SD SDRSP0 Bit Field Definitions */
#define SD_SDRSP0_SD_RSP_TK0_Pos        0                                                /*!< SD SDRSP0: SD_RSP_TK0 Position      */
#define SD_SDRSP0_SD_RSP_TK0_Msk        (0xFFFFFFFFul << SD_SDRSP0_SD_RSP_TK0_Pos)     /*!< SD SDRSP0: SD_RSP_TK0 Mask          */

/* SD SDRSP1 Bit Field Definitions */
#define SD_SDRSP1_SD_RSP_TK1_Pos        0                                            /*!< SD SDRSP1: SD_RSP_TK1 Position      */
#define SD_SDRSP1_SD_RSP_TK1_Msk        (0xFFul << SD_SDRSP1_SD_RSP_TK1_Pos)     /*!< SD SDRSP1: SD_RSP_TK1 Mask          */

/* SD SDBLEN Bit Field Definitions */
#define SD_SDBLEN_SDBLEN_Pos        0                                        /*!< SD SDBLEN: SDBLEN Position      */
#define SD_SDBLEN_SDBLEN_Msk        (0x7FFul << SD_SDBLEN_SDBLEN_Pos)     /*!< SD SDBLEN: SDBLEN Mask          */

/* SD SDTMOUT Bit Field Definitions */
#define SD_SDTMOUT_SDTMOUT_Pos        0                                            /*!< SD SDTMOUT: SDTMOUT Position      */
#define SD_SDTMOUT_SDTMOUT_Msk        (0xFFFFFFul << SD_SDTMOUT_SDTMOUT_Pos)     /*!< SD SDTMOUT: SDTMOUT Mask          */

/*@}*/ /* end of group NUC400_SD */

/*------------- External Bus Interface Control Register (EBI) -----------------------------*/
/** @addtogroup NUC400_EBI NUC400 External Bus Interface Control Register (EBI)
  @{
*/
typedef struct {
    __IO uint32_t EBICON;                        /*!< Offset: 0x0000  External Bus Interface General Control Register     */
    __IO uint32_t EXTIME0;                        /*!< Offset: 0x0004  External Bus Interface Bank0 Timing Control Register*/
    __IO uint32_t EXTIME1;                        /*!< Offset: 0x0008  External Bus Interface Bank1 Timing Control Register*/
    __IO uint32_t EXTIME2;                        /*!< Offset: 0x000C  External Bus Interface Bank2 Timing Control Register*/
    __IO uint32_t EXTIME3;                        /*!< Offset: 0x0010  External Bus Interface Bank3 Timing Control Register*/
    __IO uint32_t KEY_W0;                        /*!< Offset: 0x0014  External Bus Interface Crypto Key Word 0            */
    __IO uint32_t KEY_W1;                        /*!< Offset: 0x0018  External Bus Interface Crypto Key Word 1            */
    __IO uint32_t KEY_W2;                        /*!< Offset: 0x001C  External Bus Interface Crypto Key Word 2            */
    __IO uint32_t KEY_W3;                        /*!< Offset: 0x0020  External Bus Interface Crypto Key Word 3            */
} EBI_T;


/* EBI_EBICON Bit Field Definitions */
#define EBI_EBICON_EXTCS3_Pos     31                                      /*!< EBI EBICON: Chip 3 Chip Select Active */
#define EBI_EBICON_EXTCS3_Msk     (0x1ul << EBI_EBICON_EXTCS3_Pos)        /*!< EBI EBICON: EXTCS3 Mask */
#define EBI_EBICON_EXTCS2_Pos     30                                      /*!< EBI EBICON: Chip 2 Chip Select Active */
#define EBI_EBICON_EXTCS2_Msk     (0x1ul << EBI_EBICON_EXTCS2_Pos)        /*!< EBI EBICON: EXTCS2 Mask */
#define EBI_EBICON_EXTCS1_Pos     29                                      /*!< EBI EBICON: Chip 1 Chip Select Active */
#define EBI_EBICON_EXTCS1_Msk     (0x1ul << EBI_EBICON_EXTCS1_Pos)        /*!< EBI EBICON: EXTCS1 Mask */
#define EBI_EBICON_EXTCS0_Pos     28                                      /*!< EBI EBICON: Chip 0 Chip Select Active */
#define EBI_EBICON_EXTCS0_Msk     (0x1ul << EBI_EBICON_EXTCS0_Pos)        /*!< EBI EBICON: EXTCS0 Mask */
#define EBI_EBICON_EXTCS_Msk      (0xFul << EBI_EBICON_EXTCS0_Pos)        /*!< EBI EBICON: EXTCS Mask */
#define EBI_EBICON_CRYPT3_Pos     27                                      /*!< EBI EBICON: Chip 3 Encrypt/Decrypt Function Enable Register */
#define EBI_EBICON_CRYPT3_Msk     (0x1ul << EBI_EBICON_CRYPT3_Pos)        /*!< EBI EBICON: CRYPT3 Mask */
#define EBI_EBICON_CRYPT2_Pos     26                                      /*!< EBI EBICON: Chip 2 Encrypt/Decrypt Function Enable Register */
#define EBI_EBICON_CRYPT2_Msk     (0x1ul << EBI_EBICON_CRYPT2_Pos)        /*!< EBI EBICON: CRYPT2 Mask */
#define EBI_EBICON_CRYPT1_Pos     25                                      /*!< EBI EBICON: Chip 1 Encrypt/Decrypt Function Enable Register */
#define EBI_EBICON_CRYPT1_Msk     (0x1ul << EBI_EBICON_CRYPT1_Pos)        /*!< EBI EBICON: CRYPT1 Mask */
#define EBI_EBICON_CRYPT0_Pos     24                                      /*!< EBI EBICON: Chip 0 Encrypt/Decrypt Function Enable Register */
#define EBI_EBICON_CRYPT0_Msk     (0x1ul << EBI_EBICON_CRYPT0_Pos)        /*!< EBI EBICON: CRYPT0 Mask */
#define EBI_EBICON_CRYPT_Msk      (0xFul << EBI_EBICON_CRYPT0_Pos)        /*!< EBI EBICON: CRYPT Mask */
#define EBI_EBICON_MCLKDIV_Pos    8                                       /*!< EBI EBICON: External Output Clock Divider */
#define EBI_EBICON_MCLKDIV_Msk    (0x7ul << EBI_EBICON_MCLKDIV_Pos)       /*!< EBI EBICON: MCLKDIV Mask */

/* EBI_EXTIMEx Bit Field Definitions */
#define EBI_EXTIME_SEPEN_Pos      30                                      /*!< EBI EBICON: EBI Bank Address/Data Bus Separating Enable */
#define EBI_EXTIME_SEPEN_Msk      (0x1ul << EBI_EXTIME_SEPEN_Pos)         /*!< EBI EBICON: SEPEN Mask */
#define EBI_EXTIME_BW16_Pos       29                                      /*!< EBI EBICON: Bank data width */
#define EBI_EXTIME_BW16_Msk       (0x1ul << EBI_EXTIME_BW16_Pos)          /*!< EBI EBICON: BW16 Mask */
#define EBI_EXTIME_EXTEN_Pos      28                                      /*!< EBI EBICON: EBI function Enabled */
#define EBI_EXTIME_EXTEN_Msk      (0x1ul << EBI_EXTIME_EXTEN_Pos)         /*!< EBI EBICON: EXTEN Mask */
#define EBI_EXTIME_IR2R_Pos       24                                      /*!< EBI EBICON: Bank Idle State Cycle Between Read-Read */
#define EBI_EXTIME_IR2R_Msk       (0xFul << EBI_EXTIME_IR2R_Pos)          /*!< EBI EBICON: IR2R Mask */
#define EBI_EXTIME_IR2W_Pos       16                                      /*!< EBI EBICON: Bank Idle State Cycle Between Read-Write */
#define EBI_EXTIME_IR2W_Msk       (0xFul << EBI_EXTIME_IR2W_Pos)          /*!< EBI EBICON: IR2W Mask */
#define EBI_EXTIME_IW2X_Pos       12                                      /*!< EBI EBICON: Bank Idle State Cycle After Write */
#define EBI_EXTIME_IW2X_Msk       (0xFul << EBI_EXTIME_IW2X_Pos)          /*!< EBI EBICON: IW2X Mask */
#define EBI_EXTIME_TAHD_Pos       8                                       /*!< EBI EBICON: Bank Data Access Hold Time */
#define EBI_EXTIME_TAHD_Msk       (0x7ul << EBI_EXTIME_TAHD_Pos)          /*!< EBI EBICON: TAHD Mask */
#define EBI_EXTIME_TACC_Pos       3                                       /*!< EBI EBICON: Bank Data Access Time */
#define EBI_EXTIME_TACC_Msk       (0x1Ful << EBI_EXTIME_TACC_Pos)         /*!< EBI EBICON: TACC Mask */
#define EBI_EXTIME_ETALE_Pos      0                                       /*!< EBI EBICON: Bank Expand Time of ALE */
#define EBI_EXTIME_ETALE_Msk      (0x7ul << EBI_EXTIME_ETALE_Pos)         /*!< EBI EBICON: ETALE Mask */
/*@}*/ /* end of group NUC400_EBI */


/*------------- Watchdog Timer Control Register (WDT) -----------------------------*/
/** @addtogroup NUC400_WDT NUC400 Watchdog Timer Control Register (WDT)
  @{
*/
/**
  * @brief WDT register map
  */
typedef struct {
    __IO uint32_t WTCR;                       /*!< Offset: 0x0000   Watchdog Timer Control Register                    */
    __IO uint32_t WTCRALT;                    /*!< Offset: 0x0004   Watchdog Timer Alternative Control Register        */
    __I  uint32_t RESERVED;                   /*!< Offset: 0x0008   Reserved                                           */
    __IO uint32_t WDTIPVER;                   /*!< Offset: 0x0010   Watchdog Timer IP Version Register                 */
} WDT_T;

/* WDT WTCR Bit Field Definitions */
#define WDT_WTCR_DBGACK_WDT_Pos 31                                              /*!< WDT WTCR : DBGACK_WDT Position */
#define WDT_WTCR_DBGACK_WDT_Msk (1ul << WDT_WTCR_DBGACK_WDT_Pos)                /*!< WDT WTCR : DBGACK_WDT Mask     */

#define WDT_WTCR_WTIS_Pos       8                                               /*!< WDT WTCR : WTIS Position */
#define WDT_WTCR_WTIS_Msk       (0x7ul << WDT_WTCR_WTIS_Pos)                    /*!< WDT WTCR : WTIS Mask     */

#define WDT_WTCR_WTE_Pos        7                                               /*!< WDT WTCR : WTE Position */
#define WDT_WTCR_WTE_Msk        (1ul << WDT_WTCR_WTE_Pos)                       /*!< WDT WTCR : WTE Mask     */

#define WDT_WTCR_WTIE_Pos       6                                               /*!< WDT WTCR : WTIE Position */
#define WDT_WTCR_WTIE_Msk       (1ul << WDT_WTCR_WTIE_Pos)                      /*!< WDT WTCR : WTIE Mask     */

#define WDT_WTCR_WTWKF_Pos      5                                               /*!< WDT WTCR : WTWKF Position */
#define WDT_WTCR_WTWKF_Msk      (1ul << WDT_WTCR_WTWKF_Pos)                     /*!< WDT WTCR : WTWKF Mask     */

#define WDT_WTCR_WTWKE_Pos      4                                               /*!< WDT WTCR : WTWKE Position */
#define WDT_WTCR_WTWKE_Msk      (1ul << WDT_WTCR_WTWKE_Pos)                     /*!< WDT WTCR : WTWKE Mask     */

#define WDT_WTCR_WTIF_Pos       3                                               /*!< WDT WTCR : WTIF Position */
#define WDT_WTCR_WTIF_Msk       (1ul << WDT_WTCR_WTIF_Pos)                      /*!< WDT WTCR : WTIF Mask     */

#define WDT_WTCR_WTRF_Pos       2                                               /*!< WDT WTCR : WTRF Position */
#define WDT_WTCR_WTRF_Msk       (1ul << WDT_WTCR_WTRF_Pos)                      /*!< WDT WTCR : WTRF Mask     */

#define WDT_WTCR_WTRE_Pos       1                                               /*!< WDT WTCR : WTRE Position */
#define WDT_WTCR_WTRE_Msk       (1ul << WDT_WTCR_WTRE_Pos)                      /*!< WDT WTCR : WTRE Mask     */

#define WDT_WTCR_WTR_Pos        0                                               /*!< WDT WTCR : WTR Position */
#define WDT_WTCR_WTR_Msk        (1ul << WDT_WTCR_WTR_Pos)                       /*!< WDT WTCR : WTR Mask     */

/* WDT WTCRALT Bit Field Definitions */
#define WDT_WTCRALT_WTRDSEL_Pos 0                                               /*!< WDT WTCRALT : WTRDSEL Position */
#define WDT_WTCRALT_WTRDSEL_Msk (0x3ul << WDT_WTCRALT_WTRDSEL_Pos)              /*!< WDT WTCRALT : WTRDSEL Mask     */

/* WDT WDTIPVER Bit Field Definitions */
#define WDT_WTCRALT_WDTIPVER_Pos 0                                              /*!< WDT WDTIPVER : WTRDSEL Position */
#define WDT_WTCRALT_WDTIPVER_Msk (0x3ul << WDT_WTCRALT_WTRDSEL_Pos)             /*!< WDT WDTIPVER : WTRDSEL Mask     */
/*@}*/ /* end of group NUC400_WDT */


/*------------- Window Watchdog Timer Control Register (WWDT) -----------------------------*/
/** @addtogroup NUC400_WWDT NUC400 Watchdog Timer Control Register (WWDT)
  @{
*/
/**
  * @brief WWDT register map
  */
typedef struct {
    __O  uint32_t WWDTRLD;                   /*!< Offset: 0x0000   Window Watchdog Timer Reload Counter Register     */
    __IO uint32_t WWDTCR;                    /*!< Offset: 0x0004   Window Watchdog Timer Control Register            */
    __IO uint32_t WWDTSR;                    /*!< Offset: 0x0008   Window Watchdog Timer Status Register             */
    __I  uint32_t WWDTCVR;                   /*!< Offset: 0x000C   Window Watchdog Timer Counter Value Register      */
} WWDT_T;

/* WWDT WWDTRLD Bit Field Definitions */
#define WWDT_WWDTRLD_WWDTRLD_Pos    0                                           /*!< WWDT WWDTRLD : WWDTRLD Position */
#define WWDT_WWDTRLD_WWDTRLD_Msk    (0xFFFFFFFFul << WWDT_WWDTRLD_WWDTRLD_Pos)  /*!< WWDT WWDTRLD : WWDTRLD Mask     */

/* WWDT WWDTCR Bit Field Definitions */
#define WWDT_WWDTCR_DBGACK_WWDT_Pos 31                                          /*!< WWDT WWDTCR : DBGACK_WWDT Position */
#define WWDT_WWDTCR_DBGACK_WWDT_Msk (1ul << WWDT_WWDTCR_DBGACK_WWDT_Pos)        /*!< WWDT WWDTCR : DBGACK_WWDT Mask     */

#define WWDT_WWDTCR_WINCMP_Pos      16                                          /*!< WWDT WWDTCR : WINCMP Position */
#define WWDT_WWDTCR_WINCMP_Msk      (0x3Ful << WWDT_WWDTCR_WINCMP_Pos)          /*!< WWDT WWDTCR : WINCMP Mask     */

#define WWDT_WWDTCR_PERIODSEL_Pos   8                                           /*!< WWDT WWDTCR : PERIODSEL Position */
#define WWDT_WWDTCR_PERIODSEL_Msk   (0xFul << WWDT_WWDTCR_PERIODSEL_Pos)        /*!< WWDT WWDTCR : PERIODSEL Mask     */

#define WWDT_WWDTCR_WWDTIE_Pos      1                                           /*!< WWDT WWDTCR : WWDTIE Position */
#define WWDT_WWDTCR_WWDTIE_Msk      (1ul << WWDT_WWDTCR_WWDTIE_Pos)             /*!< WWDT WWDTCR : WWDTIE Mask     */

#define WWDT_WWDTCR_WWDTEN_Pos      0                                           /*!< WWDT WWDTCR : WWDTEN Position */
#define WWDT_WWDTCR_WWDTEN_Msk      (1ul << WWDT_WWDTCR_WWDTEN_Pos)             /*!< WWDT WWDTCR : WWDTEN Mask     */

/* WWDT WWDTSTS Bit Field Definitions */
#define WWDT_WWDTSR_WWDTRF_Pos      1                                           /*!< WWDT WWDTSR : WWDTRF Position */
#define WWDT_WWDTSR_WWDTRF_Msk      (1ul << WWDT_WWDTSR_WWDTRF_Pos)             /*!< WWDT WWDTSR : WWDTRF Mask     */

#define WWDT_WWDTSR_WWDTIF_Pos      0                                           /*!< WWDT WWDTSR : WWDTIF Position */
#define WWDT_WWDTSR_WWDTIF_Msk      (1ul << WWDT_WWDTSR_WWDTIF_Pos)             /*!< WWDT WWDTSR : WWDTIF Mask     */

/* WWDT WWDTCVR Bit Field Definitions */
#define WWDT_WWDTCVR_WWDTCVAL_Pos   0                                           /*!< WWDT WWDTCVR : WWDTRF Position */
#define WWDT_WWDTCVR_WWDTCVAL_Msk   (0x3Ful << WWDT_WWDTCVR_WWDTCVAL_Pos)       /*!< WWDT WWDTCVR : WWDTRF Mask     */
/*@}*/ /* end of group NUC400_WWDT */


/*----------------------------- Real Time Clock Controller -------------------------------*/
/** @addtogroup NUC400_RTC NUC400 Real Time Clock (RTC)
  @{
*/
typedef struct {
    __IO uint32_t INIR;                        /*!< Offset: 0x0000   RTC Initiation Register                            */

    __IO uint32_t AER;                        /*!< Offset: 0x0004   RTC Access Enable Register                        */

    __IO uint32_t FCR;                        /*!< Offset: 0x0008   RTC Frequency Compensation Register                */

    __IO uint32_t TLR;                        /*!< Offset: 0x000C   Time Loading Register                                */

    __IO uint32_t CLR;                        /*!< Offset: 0x0010   Calendar Loading Register                            */

    __IO uint32_t TSSR;                        /*!< Offset: 0x0014   Time Scale Selection Register                        */

    __IO uint32_t DWR;                       /*!< Offset: 0x0018   Day of the Week Register                              */

    __IO uint32_t TAR;                      /*!< Offset: 0x001C   Time Alarm Register                                */

    __IO uint32_t CAR;                        /*!< Offset: 0x0020   Calendar Alarm Register                            */

    __I  uint32_t LIR;                        /*!< Offset: 0x0024   Leap Year Indicator Register                        */

    __IO uint32_t RIER;                        /*!< Offset: 0x0028   RTC Interrupt Enable Register                        */

    __IO uint32_t RIIR;                        /*!< Offset: 0x002C   RTC Interrupt Indicator Register                    */

    __IO uint32_t TTR;                        /*!< Offset: 0x0030   RTC Time Tick Register                            */

    __I  uint32_t RESERVED0[2];                /*!< Offset: 0x0034 ~ 0x0038   Reserved                                    */

    __IO uint32_t SPRCTL;                    /*!< Offset: 0x003C   RTC Spare Functional Control Register                */

    __IO uint32_t SPR[24];                    /*!< Offset: 0x0040 ~ 0x009C   RTC Spare Register 0 ~ 23                */

    __I  uint32_t RESERVED1[28];            /*!< Offset: 0x00A0 ~ 0x010C   Reserved                                    */

    __IO uint32_t TAMPCTRL;                    /*!< Offset: 0x0110   Tamper Control Register                            */

    __IO uint32_t TAMPSTS ;                    /*!< Offset: 0x0114   Tamper Status  Register                            */

    __I  uint32_t RESERVED2[2];                /*!< Offset: 0x0118 ~ 0x011C   Reserved                                    */

    __IO uint32_t X32KOSCGAIN;                /*!< Offset: 0x0120   Trim value for OSC32K                                */

    __IO uint32_t SDI0_PADCTL;                /*!< Offset: 0x0124   SDI0 Pin I/O Mode Control                            */

    __IO uint32_t SDI1_PADCTL;                /*!< Offset: 0x0128   SDI1 Pin I/O Mode Control                            */

    __IO uint32_t XI32_PADCTL;                /*!< Offset: 0x012C   32K Input Pin I/O Mode Control                    */

    __IO uint32_t XO32_PADCTL;                /*!< Offset: 0x0130   32K Output Pin I/O Mode Control                    */

    __I  uint32_t RESERVED3[3];                /*!< Offset: 0x0134 ~ 0x013C   Reserved                                    */

    __IO uint32_t MTAR;                        /*!< Offset: 0x0140   Time Alarm MASK Register                             */

    __IO uint32_t MCAR;                        /*!< Offset: 0x0144   Calendar Alarm MASK Register                         */
} RTC_T;

/* RTC INIR Bit Field Definitions */
#define RTC_INIR_INIR_Pos       0                                               /*!< RTC INIR: INIR Position */
#define RTC_INIR_INIR_Msk       (0xFFFFFFFFul << RTC_INIR_INIR_Pos)             /*!< RTC INIR: INIR Mask */

#define RTC_INIR_ACTIVE_Pos     0                                               /*!< RTC INIR: ACTIVE Position */
#define RTC_INIR_ACTIVE_Msk     (1ul << RTC_INIR_ACTIVE_Pos)                    /*!< RTC INIR: ACTIVE Mask */

/* RTC AER Bit Field Definitions */
#define RTC_AER_ENF_Pos         16                                              /*!< RTC AER: ENF Position */
#define RTC_AER_ENF_Msk         (1ul << RTC_AER_ENF_Pos)                        /*!< RTC AER: ENF Mask */

#define RTC_AER_AER_Pos         0                                               /*!< RTC AER: AER Position */
#define RTC_AER_AER_Msk         (0xFFFFul << RTC_AER_AER_Pos)                   /*!< RTC AER: AER Mask */

/* RTC FCR Bit Field Definitions */
#define RTC_FCR_INTEGER_Pos     8                                               /*!< RTC FCR: INTEGER Position */
#define RTC_FCR_INTEGER_Msk     (0xFul << RTC_FCR_INTEGER_Pos)                  /*!< RTC FCR: INTEGER Mask */

#define RTC_FCR_FRACTION_Pos    0                                               /*!< RTC FCR: FRACTION Position */
#define RTC_FCR_FRACTION_Msk    (0x3Ful << RTC_FCR_FRACTION_Pos)                /*!< RTC FCR: FRACTION Mask */

/* RTC TLR Bit Field Definitions */
#define RTC_TLR_10HR_Pos        20                                              /*!< RTC TLR: 10HR Position */
#define RTC_TLR_10HR_Msk        (0x3ul << RTC_TLR_10HR_Pos)                     /*!< RTC TLR: 10HR Mask */

#define RTC_TLR_1HR_Pos         16                                              /*!< RTC TLR: 1HR Position */
#define RTC_TLR_1HR_Msk         (0xFul << RTC_TLR_1HR_Pos)                      /*!< RTC TLR: 1HR Mask */

#define RTC_TLR_10MIN_Pos       12                                              /*!< RTC TLR: 10MIN Position */
#define RTC_TLR_10MIN_Msk       (0x7ul << RTC_TLR_10MIN_Pos)                    /*!< RTC TLR: 10MIN Mask */

#define RTC_TLR_1MIN_Pos        8                                               /*!< RTC TLR: 1MIN Position */
#define RTC_TLR_1MIN_Msk        (0xFul << RTC_TLR_1MIN_Pos)                     /*!< RTC TLR: 1MIN Mask */

#define RTC_TLR_10SEC_Pos       4                                               /*!< RTC TLR: 10SEC Position */
#define RTC_TLR_10SEC_Msk       (0x7ul << RTC_TLR_10SEC_Pos)                    /*!< RTC TLR: 10SEC Mask */

#define RTC_TLR_1SEC_Pos        0                                               /*!< RTC TLR: 1SEC Position */
#define RTC_TLR_1SEC_Msk        (0xFul << RTC_TLR_1SEC_Pos)                     /*!< RTC TLR: 1SEC Mask */

/* RTC CLR Bit Field Definitions */
#define RTC_CLR_10YEAR_Pos      20                                              /*!< RTC CLR: 10YEAR Position */
#define RTC_CLR_10YEAR_Msk      (0xFul << RTC_CLR_10YEAR_Pos)                   /*!< RTC CLR: 10YEAR Mask */

#define RTC_CLR_1YEAR_Pos       16                                              /*!< RTC CLR: 1YEAR Position */
#define RTC_CLR_1YEAR_Msk       (0xFul << RTC_CLR_1YEAR_Pos)                    /*!< RTC CLR: 1YEAR Mask */

#define RTC_CLR_10MON_Pos       12                                              /*!< RTC CLR: 10MON Position */
#define RTC_CLR_10MON_Msk       (1ul << RTC_CLR_10MON_Pos)                      /*!< RTC CLR: 10MON Mask */

#define RTC_CLR_1MON_Pos        8                                               /*!< RTC CLR: 1MON Position */
#define RTC_CLR_1MON_Msk        (0xFul << RTC_CLR_1MON_Pos)                     /*!< RTC CLR: 1MON Mask */

#define RTC_CLR_10DAY_Pos       4                                               /*!< RTC CLR: 10DAY Position */
#define RTC_CLR_10DAY_Msk       (0x3ul << RTC_CLR_10DAY_Pos)                    /*!< RTC CLR: 10DAY Mask */

#define RTC_CLR_1DAY_Pos        0                                               /*!< RTC CLR: 1DAY Position */
#define RTC_CLR_1DAY_Msk        (0xFul << RTC_CLR_1DAY_Pos)                     /*!< RTC CLR: 1DAY Mask */

/* RTC TSSR Bit Field Definitions */
#define RTC_TSSR_24H_12H_Pos    0                                               /*!< RTC TSSR: 24H_12H Position */
#define RTC_TSSR_24H_12H_Msk    (1ul << RTC_TSSR_24H_12H_Pos)                   /*!< RTC TSSR: 24H_12H Mask */

/* RTC DWR Bit Field Definitions */
#define RTC_DWR_DWR_Pos         0                                               /*!< RTC DWR: DWR Position */
#define RTC_DWR_DWR_Msk         (0x7ul << RTC_DWR_DWR_Pos)                      /*!< RTC DWR: DWR Mask */

/* RTC TAR Bit Field Definitions */
#define RTC_TAR_10HR_Pos        20                                              /*!< RTC TAR: 10HR Position */
#define RTC_TAR_10HR_Msk        (0x3ul << RTC_TAR_10HR_Pos)                     /*!< RTC TAR: 10HR Mask */

#define RTC_TAR_1HR_Pos         16                                              /*!< RTC TAR: 1HR Position */
#define RTC_TAR_1HR_Msk         (0xFul << RTC_TAR_1HR_Pos)                      /*!< RTC TAR: 1HR Mask */

#define RTC_TAR_10MIN_Pos       12                                              /*!< RTC TAR: 10MIN Position */
#define RTC_TAR_10MIN_Msk       (0x7ul << RTC_TAR_10MIN_Pos)                    /*!< RTC TAR: 10MIN Mask */

#define RTC_TAR_1MIN_Pos        8                                               /*!< RTC TAR: 1MIN Position */
#define RTC_TAR_1MIN_Msk        (0xFul << RTC_TAR_1MIN_Pos)                     /*!< RTC TAR: 1MIN Mask */

#define RTC_TAR_10SEC_Pos       4                                               /*!< RTC TAR: 10SEC Position */
#define RTC_TAR_10SEC_Msk       (0x7ul << RTC_TAR_10SEC_Pos)                    /*!< RTC TAR: 10SEC Mask */

#define RTC_TAR_1SEC_Pos        0                                               /*!< RTC TAR: 1SEC Position */
#define RTC_TAR_1SEC_Msk        (0xFul << RTC_TAR_1SEC_Pos)                     /*!< RTC TAR: 1SEC Mask */

/* RTC CAR Bit Field Definitions */
#define RTC_CAR_10YEAR_Pos      20                                              /*!< RTC CAR: 10YEAR Position */
#define RTC_CAR_10YEAR_Msk      (0xFul << RTC_CAR_10YEAR_Pos)                   /*!< RTC CAR: 10YEAR Mask */

#define RTC_CAR_1YEAR_Pos       16                                              /*!< RTC CAR: 1YEAR Position */
#define RTC_CAR_1YEAR_Msk       (0xFul << RTC_CAR_1YEAR_Pos)                    /*!< RTC CAR: 1YEAR Mask */

#define RTC_CAR_10MON_Pos       12                                              /*!< RTC CAR: 10MON Position */
#define RTC_CAR_10MON_Msk       (1ul << RTC_CAR_10MON_Pos)                      /*!< RTC CAR: 10MON Mask */

#define RTC_CAR_1MON_Pos        8                                               /*!< RTC CAR: 1MON Position */
#define RTC_CAR_1MON_Msk        (0xFul << RTC_CAR_1MON_Pos)                     /*!< RTC CAR: 1MON Mask */

#define RTC_CAR_10DAY_Pos       4                                               /*!< RTC CAR: 10DAY Position */
#define RTC_CAR_10DAY_Msk       (0x3ul << RTC_CAR_10DAY_Pos)                    /*!< RTC CAR: 10DAY Mask */

#define RTC_CAR_1DAY_Pos        0                                               /*!< RTC CAR: 1DAY Position */
#define RTC_CAR_1DAY_Msk        (0xFul << RTC_CAR_1DAY_Pos)                     /*!< RTC CAR: 1DAY Mask */

/* RTC LIR Bit Field Definitions */
#define RTC_LIR_LIR_Pos         0                                               /*!< RTC LIR: LIR Position */
#define RTC_LIR_LIR_Msk         (1ul << RTC_LIR_LIR_Pos)                        /*!< RTC LIR: LIR Mask */

/* RTC RIER Bit Field Definitions */
#define RTC_RIER_TIER_Pos       1                                               /*!< RTC RIER: TIER Position */
#define RTC_RIER_TIER_Msk       (1ul << RTC_RIER_TIER_Pos)                      /*!< RTC RIER: TIER Mask */

#define RTC_RIER_AIER_Pos       0                                               /*!< RTC RIER: AIER Position */
#define RTC_RIER_AIER_Msk       (1ul << RTC_RIER_AIER_Pos)                      /*!< RTC RIER: AIER Mask */

/* RTC RIIR Bit Field Definitions */
#define RTC_RIIR_TIF_Pos        1                                               /*!< RTC RIIR: TIF Position */
#define RTC_RIIR_TIF_Msk        (1ul << RTC_RIIR_TIF_Pos)                       /*!< RTC RIIR: TIF Mask */

#define RTC_RIIR_AIF_Pos        0                                               /*!< RTC RIIR: AIF Position */
#define RTC_RIIR_AIF_Msk        (1ul << RTC_RIIR_AIF_Pos)                       /*!< RTC RIIR: AIF Mask */

/* RTC TTR Bit Field Definitions */
#define RTC_TTR_TTR_Pos         0                                               /*!< RTC TTR: TTR Position */
#define RTC_TTR_TTR_Msk         (0x7ul << RTC_TTR_TTR_Pos)                      /*!< RTC TTR: TTR Mask */

/* RTC SPRCTL Bit Field Definitions */
#define RTC_SPRCTL_SPRRDY_Pos   7                                               /*!< RTC SPRCTL: SPRRDY Position */
#define RTC_SPRCTL_SPRRDY_Msk   (1ul << RTC_SPRCTL_SPRRDY_Pos)                  /*!< RTC SPRCTL: SPRRDY Mask */

#define RTC_SPRCTL_SPREN_Pos    2                                               /*!< RTC SPRCTL: SPREN Position */
#define RTC_SPRCTL_SPREN_Msk    (1ul << RTC_SPRCTL_SPREN_Pos)                   /*!< RTC SPRCTL: SPREN Mask */

/* RTC TAMPCTRL Bit Field Definitions */
#define RTC_TAMPCTRL_SDI1LV_Pos     7                                           /*!< RTC TAMPCTRL: SDI1LV Position */
#define RTC_TAMPCTRL_SDI1LV_Msk     (1ul << RTC_TAMPCTRL_SDI1LV_Pos)            /*!< RTC TAMPCTRL: SDI1LV Mask */

#define RTC_TAMPCTRL_SDI0LV_Pos     6                                           /*!< RTC TAMPCTRL: SDI0LV Position */
#define RTC_TAMPCTRL_SDI0LV_Msk     (1ul << RTC_TAMPCTRL_SDI0LV_Pos)            /*!< RTC TAMPCTRL: SDI0LV Mask */

#define RTC_TAMPCTRL_SDIDBEN1_Pos   5                                           /*!< RTC TAMPCTRL: SDIDBEN1 Position */
#define RTC_TAMPCTRL_SDIDBEN1_Msk   (1ul << RTC_TAMPCTRL_SDIDBEN1_Pos)          /*!< RTC TAMPCTRL: SDIDBEN1 Mask */

#define RTC_TAMPCTRL_SDIDBEN0_Pos   4                                           /*!< RTC TAMPCTRL: SDIDBEN0 Position */
#define RTC_TAMPCTRL_SDIDBEN0_Msk   (1ul << RTC_TAMPCTRL_SDIDBEN0_Pos)          /*!< RTC TAMPCTRL: SDIDBEN0 Mask */

#define RTC_TAMPCTRL_SDIEN1_Pos     3                                           /*!< RTC TAMPCTRL: SDIEN1 Position */
#define RTC_TAMPCTRL_SDIEN1_Msk     (1ul << RTC_TAMPCTRL_SDIEN1_Pos)            /*!< RTC TAMPCTRL: SDIEN1 Mask */

#define RTC_TAMPCTRL_SDIEN0_Pos     2                                           /*!< RTC TAMPCTRL: SDIEN0 Position */
#define RTC_TAMPCTRL_SDIEN0_Msk     (1ul << RTC_TAMPCTRL_SDIEN0_Pos)            /*!< RTC TAMPCTRL: SDIEN0 Mask */

#define RTC_TAMPCTRL_DESTROYEN_Pos  1                                           /*!< RTC TAMPCTRL: DESTROYEN Position */
#define RTC_TAMPCTRL_DESTROYEN_Msk  (1ul << RTC_TAMPCTRL_DESTROYEN_Pos)         /*!< RTC TAMPCTRL: DESTROYEN Mask */

#define RTC_TAMPCTRL_TIEN_Pos       0                                           /*!< RTC TAMPCTRL: TIEN Position */
#define RTC_TAMPCTRL_TIEN_Msk       (1ul << RTC_TAMPCTRL_TIEN_Pos)              /*!< RTC TAMPCTRL: TIEN Mask */

/* RTC TAMPSTS Bit Field Definitions */
#define RTC_TAMPSTS_SDI1STS_Pos     1                                           /*!< RTC TAMPSTS : SDI1STS Position */
#define RTC_TAMPSTS_SDI1STS_Msk     (1ul << RTC_TAMPSTS_SDI1STS_Pos)            /*!< RTC TAMPSTS : SDI1STS Mask */

#define RTC_TAMPSTS_SDI0STS_Pos     0                                           /*!< RTC TAMPSTS : SDI0STS Position */
#define RTC_TAMPSTS_SDI0STS_Msk     (1ul << RTC_TAMPSTS_SDI0STS_Pos)            /*!< RTC TAMPSTS : SDI0STS Mask */

/* RTC OSC32KGAIN Bit Field Definitions */
#define RTC_OSC32KGAIN_OSC32KGAIN_Pos   0                                           /*!< RTC OSC32KGAIN : OSC32KGAIN Position */
#define RTC_OSC32KGAIN_OSC32KGAIN_Msk   (0xFul << RTC_OSC32KGAIN_OSC32KGAIN_Pos)    /*!< RTC OSC32KGAIN : OSC32KGAIN Mask */

/* RTC SDI0_PADCTL Bit Field Definitions */
#define RTC_SDI0_PADCTL_OFFD_Pos    4                                           /*!< RTC SDI0_PADCTL : OFFD Position */
#define RTC_SDI0_PADCTL_OFFD_Msk    (1ul << RTC_SDI0_PADCTL_OFFD_Pos)           /*!< RTC SDI0_PADCTL : OFFD Mask */

#define RTC_SDI0_PADCTL_TYPE_Pos    3                                           /*!< RTC SDI0_PADCTL : TYPE Position */
#define RTC_SDI0_PADCTL_TYPE_Msk    (1ul << RTC_SDI0_PADCTL_TYPE_Pos)           /*!< RTC SDI0_PADCTL : TYPE Mask */

#define RTC_SDI0_PADCTL_TRI_EN_Pos  2                                           /*!< RTC SDI0_PADCTL : TRI_EN Position */
#define RTC_SDI0_PADCTL_TRI_EN_Msk  (1ul << RTC_SDI0_PADCTL_TRI_EN_Pos)         /*!< RTC SDI0_PADCTL : TRI_EN Mask */

#define RTC_SDI0_PADCTL_DOUT_EN_Pos 1                                           /*!< RTC SDI0_PADCTL : DOUT_EN Position */
#define RTC_SDI0_PADCTL_DOUT_EN_Msk (1ul << RTC_SDI0_PADCTL_DOUT_EN_Pos)        /*!< RTC SDI0_PADCTL : DOUT_EN Mask */

#define RTC_SDI0_PADCTL_DOUT_LV_Pos 0                                           /*!< RTC SDI0_PADCTL : DOUT_LV Position */
#define RTC_SDI0_PADCTL_DOUT_LV_Msk (1ul << RTC_SDI0_PADCTL_DOUT_LV_Pos)        /*!< RTC SDI0_PADCTL : DOUT_LV Mask */

/* RTC SDI1_PADCTL Bit Field Definitions */
#define RTC_SDI1_PADCTL_OFFD_Pos    4                                           /*!< RTC SDI1_PADCTL : OFFD Position */
#define RTC_SDI1_PADCTL_OFFD_Msk    (1ul << RTC_SDI1_PADCTL_OFFD_Pos)           /*!< RTC SDI1_PADCTL : OFFD Mask */

#define RTC_SDI1_PADCTL_TYPE_Pos    3                                           /*!< RTC SDI1_PADCTL : TYPE Position */
#define RTC_SDI1_PADCTL_TYPE_Msk    (1ul << RTC_SDI1_PADCTL_TYPE_Pos)           /*!< RTC SDI1_PADCTL : TYPE Mask */

#define RTC_SDI1_PADCTL_TRI_EN_Pos  2                                           /*!< RTC SDI1_PADCTL : TRI_EN Position */
#define RTC_SDI1_PADCTL_TRI_EN_Msk  (1ul << RTC_SDI1_PADCTL_TRI_EN_Pos)         /*!< RTC SDI1_PADCTL : TRI_EN Mask */

#define RTC_SDI1_PADCTL_DOUT_EN_Pos 1                                           /*!< RTC SDI1_PADCTL : DOUT_EN Position */
#define RTC_SDI1_PADCTL_DOUT_EN_Msk (1ul << RTC_SDI1_PADCTL_DOUT_EN_Pos)        /*!< RTC SDI1_PADCTL : DOUT_EN Mask */

#define RTC_SDI1_PADCTL_DOUT_LV_Pos 0                                           /*!< RTC SDI1_PADCTL : DOUT_LV Position */
#define RTC_SDI1_PADCTL_DOUT_LV_Msk (1ul << RTC_SDI1_PADCTL_DOUT_LV_Pos)        /*!< RTC SDI1_PADCTL : DOUT_LV Mask */

/* RTC XI32_PADCTL Bit Field Definitions */
#define RTC_XI32_PADCTL_OFFD_Pos    4                                           /*!< RTC XI32_PADCTL : OFFD Position */
#define RTC_XI32_PADCTL_OFFD_Msk    (1ul << RTC_XI32_PADCTL_OFFD_Pos)           /*!< RTC XI32_PADCTL : OFFD Mask */

#define RTC_XI32_PADCTL_TYPE_Pos    3                                           /*!< RTC XI32_PADCTL : TYPE Position */
#define RTC_XI32_PADCTL_TYPE_Msk    (1ul << RTC_XI32_PADCTL_TYPE_Pos)           /*!< RTC XI32_PADCTL : TYPE Mask */

#define RTC_XI32_PADCTL_TRI_EN_Pos  2                                           /*!< RTC XI32_PADCTL : TRI_EN Position */
#define RTC_XI32_PADCTL_TRI_EN_Msk  (1ul << RTC_XI32_PADCTL_TRI_EN_Pos)         /*!< RTC XI32_PADCTL : TRI_EN Mask */

#define RTC_XI32_PADCTL_DOUT_EN_Pos 1                                           /*!< RTC XI32_PADCTL : DOUT_EN Position */
#define RTC_XI32_PADCTL_DOUT_EN_Msk (1ul << RTC_XI32_PADCTL_DOUT_EN_Pos)        /*!< RTC XI32_PADCTL : DOUT_EN Mask */

#define RTC_XI32_PADCTL_DOUT_LV_Pos 0                                           /*!< RTC XI32_PADCTL : DOUT_LV Position */
#define RTC_XI32_PADCTL_DOUT_LV_Msk (1ul << RTC_XI32_PADCTL_DOUT_LV_Pos)        /*!< RTC XI32_PADCTL : DOUT_LV Mask */

/* RTC XO32_PADCTL Bit Field Definitions */
#define RTC_XO32_PADCTL_OFFD_Pos    4                                           /*!< RTC XO32_PADCTL : OFFD Position */
#define RTC_XO32_PADCTL_OFFD_Msk    (1ul << RTC_XO32_PADCTL_OFFD_Pos)           /*!< RTC XO32_PADCTL : OFFD Mask */

#define RTC_XO32_PADCTL_TYPE_Pos    3                                           /*!< RTC XO32_PADCTL : TYPE Position */
#define RTC_XO32_PADCTL_TYPE_Msk    (1ul << RTC_XO32_PADCTL_TYPE_Pos)           /*!< RTC XO32_PADCTL : TYPE Mask */

#define RTC_XO32_PADCTL_TRI_EN_Pos  2                                           /*!< RTC XO32_PADCTL : TRI_EN Position */
#define RTC_XO32_PADCTL_TRI_EN_Msk  (1ul << RTC_XO32_PADCTL_TRI_EN_Pos)         /*!< RTC XO32_PADCTL : TRI_EN Mask */

#define RTC_XO32_PADCTL_DOUT_EN_Pos 1                                           /*!< RTC XO32_PADCTL : DOUT_EN Position */
#define RTC_XO32_PADCTL_DOUT_EN_Msk (1ul << RTC_XO32_PADCTL_DOUT_EN_Pos)        /*!< RTC XO32_PADCTL : DOUT_EN Mask */

#define RTC_XO32_PADCTL_DOUT_LV_Pos 0                                           /*!< RTC XO32_PADCTL : DOUT_LV Position */
#define RTC_XO32_PADCTL_DOUT_LV_Msk (1ul << RTC_XO32_PADCTL_DOUT_LV_Pos)        /*!< RTC XO32_PADCTL : DOUT_LV Mask */

/* RTC MTAR Bit Field Definitions */
#define RTC_MTAR_M10HR_Pos          5                                           /*!< RTC MTAR : M10HR Position */
#define RTC_MTAR_M10HR_Msk          (1ul << RTC_MTAR_M10HR_Pos)                 /*!< RTC MTAR : M10HR Mask */

#define RTC_MTAR_M1HR_Pos           4                                           /*!< RTC MTAR : M1HR Position */
#define RTC_MTAR_M1HR_Msk           (1ul << RTC_MTAR_M1HR_Pos)                  /*!< RTC MTAR : M1HR Mask */

#define RTC_MTAR_M10MIN_Pos         3                                           /*!< RTC MTAR : M10MIN Position */
#define RTC_MTAR_M10MIN_Msk         (1ul << RTC_MTAR_M10MIN_Pos)                /*!< RTC MTAR : M10MIN Mask */

#define RTC_MTAR_M1MIN_Pos          2                                           /*!< RTC MTAR : M1MIN Position */
#define RTC_MTAR_M1MIN_Msk          (1ul << RTC_MTAR_M1MIN_Pos)                 /*!< RTC MTAR : M1MIN Mask */

#define RTC_MTAR_M10SEC_Pos         1                                           /*!< RTC MTAR : M10SEC Position */
#define RTC_MTAR_M10SEC_Msk         (1ul << RTC_MTAR_M10SEC_Pos)                /*!< RTC MTAR : M10SEC Mask */

#define RTC_MTAR_M1SEC_Pos          0                                           /*!< RTC MTAR : M1SEC Position */
#define RTC_MTAR_M1SEC_Msk          (1ul << RTC_MTAR_M1SEC_Pos)                 /*!< RTC MTAR : M1SEC Mask */


/* RTC MCAR Bit Field Definitions */
#define RTC_MCAR_M10YEAR_Pos        5                                           /*!< RTC MCAR : M10YEAR Position */
#define RTC_MCAR_M10YEAR_Msk        (1ul << RTC_MCAR_M10YEAR_Pos)               /*!< RTC MCAR : M10YEAR Mask */

#define RTC_MCAR_M1YEAR_Pos         4                                           /*!< RTC MCAR : M1YEAR Position */
#define RTC_MCAR_M1YEAR_Msk         (1ul << RTC_MCAR_M1YEAR_Pos)                /*!< RTC MCAR : M1YEAR Mask */

#define RTC_MCAR_M10MON_Pos         3                                           /*!< RTC MCAR : M10MON Position */
#define RTC_MCAR_M10MON_Msk         (1ul << RTC_MCAR_M10MON_Pos)                /*!< RTC MCAR : M10MON Mask */

#define RTC_MCAR_M1MON_Pos          2                                           /*!< RTC MCAR : M1MON Position */
#define RTC_MCAR_M1MON_Msk          (1ul << RTC_MCAR_M1MON_Pos)                 /*!< RTC MCAR : M1MON Mask */

#define RTC_MCAR_M10DAY_Pos         1                                           /*!< RTC MCAR : M10DAY Position */
#define RTC_MCAR_M10DAY_Msk         (1ul << RTC_MCAR_M10DAY_Pos)                /*!< RTC MCAR : M10DAY Mask */

#define RTC_MCAR_M1DAY_Pos          0                                           /*!< RTC MCAR : M1DAY Position */
#define RTC_MCAR_M1DAY_Msk          (1ul << RTC_MCAR_M1DAY_Msk)                 /*!< RTC MCAR : M1DAY Mask */
/*@}*/ /* end of group NUC400_RTC */


/*----------------------------- ADC Controller -------------------------------*/
/** @addtogroup NUC400_ADC NUC400 A/D Converter (ADC)
  @{
*/
typedef struct {
    __I  uint32_t DR0;                        /*!< Offset: 0x0000   ADC Data Register 0 */

    __I  uint32_t DR1;                        /*!< Offset: 0x0004   ADC Data Register 1 */

    __I  uint32_t DR2;                        /*!< Offset: 0x0008   ADC Data Register 2 */

    __I  uint32_t DR3;                        /*!< Offset: 0x000C   ADC Data Register 3 */

    __I  uint32_t DR4;                        /*!< Offset: 0x0010   ADC Data Register 4 */

    __I  uint32_t DR5;                        /*!< Offset: 0x0014   ADC Data Register 5 */

    __I  uint32_t DR6;                        /*!< Offset: 0x0018   ADC Data Register 6 */

    __I  uint32_t DR7;                        /*!< Offset: 0x001C   ADC Data Register 7 */

    __I  uint32_t DR8;                        /*!< Offset: 0x0020   ADC Data Register 8 */

    __I  uint32_t DR9;                        /*!< Offset: 0x0024   ADC Data Register 9 */

    __I  uint32_t DR10;                       /*!< Offset: 0x0028   ADC Data Register 10 */

    __I  uint32_t DR11;                       /*!< Offset: 0x002C   ADC Data Register 11 */

    __I  uint32_t DR12;                       /*!< Offset: 0x0030   ADC Data Register for Internal Temperature Sensor  */

    __I  uint32_t DR13;                       /*!< Offset: 0x0034   ADC Data Register for Internal Band-Gap Voltage    */

    uint32_t RESERVED0[2];               /*!< Offset: 0x0038 ~ 0x003C   Reserved                                  */

    __IO uint32_t CR;                         /*!< Offset: 0x0040   ADC Control Register                               */

    __IO uint32_t CHER;                       /*!< Offset: 0x0044   ADC Channel Enable Register                        */

    __IO uint32_t CMPR0;                      /*!< Offset: 0x0048   ADC Compare Register 0                */

    __IO uint32_t CMPR1;                      /*!< Offset: 0x004C   ADC Compare Register 1                */

    __IO uint32_t SR0;                        /*!< Offset: 0x0050   ADC Status Register                                */

    __IO uint32_t SR1;                        /*!< Offset: 0x0054   ADC Status Register 1                              */

    uint32_t RESERVED1[2];               /*!< Offset: 0x0058 ~ 0x005C   Reserved                                  */

    __I  uint32_t PDMADATA;                   /*!< Offset: 0x0060   ADC PDMA Current Transfer Data                     */
} ADC_T;


/* ADC_DR Bit Field Definitions */
#define ADC_DR_RSLT_Pos           0                               /*!< ADC DR: RSLT Position */
#define ADC_DR_RSLT_Msk           (0xFFFFul << ADC_DR_RSLT_Pos)   /*!< ADC DR: RSLT Mask */
#define ADC_DR_OVERRUN_Pos        16                              /*!< ADC DR: OVERRUN Position */
#define ADC_DR_OVERRUN_Msk        (1ul << ADC_DR_OVERRUN_Pos)     /*!< ADC DR: OVERRUN Mask */
#define ADC_DR_VALID_Pos          17                              /*!< ADC DR: VALID Position */
#define ADC_DR_VALID_Msk          (1ul << ADC_DR_VALID_Pos)       /*!< ADC DR: VALID Mask */

/* ADC_CR Bit Field Definitions */
#define ADC_CR_ADC_EN_Pos         0                                 /*!< ADC CR: ADC_EN Position */
#define ADC_CR_ADC_EN_Msk         (1ul << ADC_CR_ADC_EN_Pos)        /*!< ADC CR: ADC_EN Mask */
#define ADC_CR_ADC_IE_Pos         1                                 /*!< ADC CR: ADC_IE Position */
#define ADC_CR_ADC_IE_Msk         (1ul << ADC_CR_ADC_IE_Pos)        /*!< ADC CR: ADC_IE Mask */
#define ADC_CR_ADC_OPMODE_Pos     2                                 /*!< ADC CR: ADC_OPMODE Position */
#define ADC_CR_ADC_OPMODE_Msk     (3ul << ADC_CR_ADC_OPMODE_Pos)    /*!< ADC CR: ADC_OPMODE Mask */
#define ADC_CR_HWTRG_SRC_Pos      4                                 /*!< ADC CR: HWTRG_SRC Position */
#define ADC_CR_HWTRG_SRC_Msk      (3ul << ADC_CR_HWTRG_SRC_Pos)     /*!< ADC CR: HWTRG_SRC Mask */
#define ADC_CR_PINTRG_COND_Pos    6                                 /*!< ADC CR: PINTRG_COND Position */
#define ADC_CR_PINTRG_COND_Msk    (3ul << ADC_CR_PINTRG_COND_Pos)   /*!< ADC CR: PINTRG_COND Mask */
#define ADC_CR_HWTRG_EN_Pos       8                                 /*!< ADC CR: HWTRG_EN Position */
#define ADC_CR_HWTRG_EN_Msk       (1ul << ADC_CR_HWTRG_EN_Pos)      /*!< ADC CR: HWTRG_EN Mask */
#define ADC_CR_PDMA_EN_Pos        9                                 /*!< ADC CR: PDMA_EN Position */
#define ADC_CR_PDMA_EN_Msk        (1ul << ADC_CR_PDMA_EN_Pos)       /*!< ADC CR: PDMA_EN Mask */
#define ADC_CR_DIFFEN_Pos         10                                /*!< ADC CR: DIFFEN Position */
#define ADC_CR_DIFFEN_Msk         (1ul << ADC_CR_DIFFEN_Pos)        /*!< ADC CR: DIFFEN Mask */
#define ADC_CR_ADST_Pos           11                                /*!< ADC CR: ADST Position */
#define ADC_CR_ADST_Msk           (1ul << ADC_CR_ADST_Pos)          /*!< ADC CR: ADST Mask */
#define ADC_CR_REFVSEL_Pos        15                                /*!< ADC CR: REFVSEL Position */
#define ADC_CR_REFVSEL_Msk        (1ul << ADC_CR_REFVSEL_Pos)       /*!< ADC CR: REFVSEL Mask */
#define ADC_CR_PWMTRG_DT_Pos      16                                /*!< ADC CR: PWMTRG_DT Position */
#define ADC_CR_PWMTRG_DT_Msk      (0xFFul << ADC_CR_PWMTRG_DT_Pos)  /*!< ADC CR: PWMTRG_DT Mask */
#define ADC_CR_DMOF_Pos           31                                /*!< ADC CR: DMOF Position */
#define ADC_CR_DMOF_Msk           (1ul << ADC_CR_DMOF_Pos)          /*!< ADC CR: DMOF Mask */

/* ADC_CHER Bit Field Definitions */
#define ADC_CHER_CHEN_Pos         0                                 /*!< ADC CHER: CHEN Position */
#define ADC_CHER_CHEN_Msk         (0xFFFul << ADC_CHER_CHEN_Pos)    /*!< ADC CHER: CHEN Mask */
#define ADC_CHER_ADTS_EN_Pos      16                                /*!< ADC CHER: ADTS_EN Position */
#define ADC_CHER_ADTS_EN_Msk      (1ul << ADC_CHER_ADTS_EN_Pos)     /*!< ADC CHER: ADTS_EN Mask */
#define ADC_CHER_ADBG_EN_Pos      17                                /*!< ADC CHER: ADBG_EN Position */
#define ADC_CHER_ADBG_EN_Msk      (1ul << ADC_CHER_ADBG_EN_Pos)     /*!< ADC CHER: ADBG_EN Mask */

/* ADC_CMPR Bit Field Definitions */
#define ADC_CMPR_CMPEN_Pos        0                                 /*!< ADC CMPR: CMPEN Position */
#define ADC_CMPR_CMPEN_Msk        (1ul << ADC_CMPR_CMPEN_Pos)       /*!< ADC CMPR: CMPEN Mask */
#define ADC_CMPR_CMPIE_Pos        1                                 /*!< ADC CMPR: CMPIE Position */
#define ADC_CMPR_CMPIE_Msk        (1ul << ADC_CMPR_CMPIE_Pos)       /*!< ADC CMPR: CMPIE Mask */
#define ADC_CMPR_CMPIE_Pos        1                                 /*!< ADC CMPR: CMPIE Position */
#define ADC_CMPR_CMPIE_Msk        (1ul << ADC_CMPR_CMPIE_Pos)       /*!< ADC CMPR: CMPIE Mask */
#define ADC_CMPR_CMPCOND_Pos      2                                 /*!< ADC CMPR: CMPCOND Position */
#define ADC_CMPR_CMPCOND_Msk      (1ul << ADC_CMPR_CMPCOND_Pos)     /*!< ADC CMPR: CMPCOND Mask */
#define ADC_CMPR_CMPCH_Pos        3                                 /*!< ADC CMPR: CMPCH Position */
#define ADC_CMPR_CMPCH_Msk        (0xFul << ADC_CMPR_CMPCH_Pos)     /*!< ADC CMPR: CMPCH Mask */
#define ADC_CMPR_CMPMATCNT_Pos    8                                 /*!< ADC CMPR: CMPMATCNT Position */
#define ADC_CMPR_CMPMATCNT_Msk    (0xFul << ADC_CMPR_CMPMATCNT_Pos) /*!< ADC CMPR: CMPMATCNT Mask */
#define ADC_CMPR_CMPD_Pos         16                                /*!< ADC CMPR: CMPD Position */
#define ADC_CMPR_CMPD_Msk         (0xFFFul << ADC_CMPR_CMPD_Pos)    /*!< ADC CMPR: CMPD Mask */

/* ADC_SR0 Bit Field Definitions */
#define ADC_SR0_ADC_IF_Pos        0                                 /*!< ADC SR0: ADC_IF Position */
#define ADC_SR0_ADC_IF_Msk        (1ul << ADC_SR0_ADC_IF_Pos)       /*!< ADC SR0: ADC_IF Mask */
#define ADC_SR0_CMPIF0_Pos        1                                 /*!< ADC SR0: CMPIF0 Position */
#define ADC_SR0_CMPIF0_Msk        (1ul << ADC_SR0_CMPIF0_Pos)       /*!< ADC SR0: CMPIF0 Mask */
#define ADC_SR0_CMPIF1_Pos        2                                 /*!< ADC SR0: CMPIF1 Position */
#define ADC_SR0_CMPIF1_Msk        (1ul << ADC_SR0_CMPIF1_Pos)       /*!< ADC SR0: CMPIF1 Mask */
#define ADC_SR0_BUSY_Pos          3                                 /*!< ADC SR0: BUSY Position */
#define ADC_SR0_BUSY_Msk          (1ul << ADC_SR0_BUSY_Pos)         /*!< ADC SR0: BUSY Mask */
#define ADC_SR0_CHANNEL_Pos       4                                 /*!< ADC SR0: CHANNEL Position */
#define ADC_SR0_CHANNEL_Msk       (0xFul << ADC_SR0_CHANNEL_Pos)    /*!< ADC SR0: CHANNEL Mask */

/* ADC_SR1 Bit Field Definitions */
#define ADC_SR1_VALID_Pos        0                                  /*!< ADC SR1: VALID Position */
#define ADC_SR1_VALID_Msk        (0x3FFFul << ADC_SR1_VALID_Pos)    /*!< ADC SR1: VALID Mask */
#define ADC_SR1_OVERRUN_Pos      16                                 /*!< ADC SR1: OVERRUN Position */
#define ADC_SR1_OVERRUN_Msk      (0x3FFFul << ADC_SR1_OVERRUN_Pos)  /*!< ADC SR1: OVERRUN Mask */

/* ADC_PDMADATA Bit Field Definitions */
#define ADC_PDMADATA_AD_PDMA_Pos   0                                         /*!< ADC PDMADATA: AD_PDMA Position */
#define ADC_PDMADATA_AD_PDMA_Msk   (0x3FFFFul << ADC_PDMADATA_AD_PDMA_Pos)   /*!< ADC PDMADATA: AD_PDMA Mask */

/*@}*/ /* end of group NUC400_ADC */


/*------------------------- Analog Comparator (ACMP) --------------------------*/
/** @addtogroup NUC400_ACMP NUC400 Analog Comparator (ACMP)
  @{
*/
typedef struct {
    __IO uint32_t CR0;                      /*!< Offset: 0x0000   Analog Comparator Control Register 0    */
    __IO uint32_t CR1;                      /*!< Offset: 0x0004   Analog Comparator Control Register 1    */
    __IO uint32_t CR2;                      /*!< Offset: 0x0008   Analog Comparator Control Register 2    */
    __IO uint32_t SR;                       /*!< Offset: 0x000C   Analog Comparator Status Register       */
    __IO uint32_t RVCR;                     /*!< Offset: 0x0010   Analog Comparator Reference Voltage Control Register */
} ACMP_T;


/* ACMP_CR Bit Field Definitions */
#define ACMP_CR_ACMPEN_Pos        0                             /*!< ACMP CR: ACMPEN Position */
#define ACMP_CR_ACMPEN_Msk        (1ul << ACMP_CR_ACMPEN_Pos)   /*!< ACMP CR: ACMPEN Mask */
#define ACMP_CR_ACMPIE_Pos        1                             /*!< ACMP CR: ACMPIE Position */
#define ACMP_CR_ACMPIE_Msk        (1ul << ACMP_CR_ACMPIE_Pos)   /*!< ACMP CR: ACMPIE Mask */
#define ACMP_CR_HYSEN_Pos         2                             /*!< ACMP CR: HYSEN Position */
#define ACMP_CR_HYSEN_Msk         (1ul << ACMP_CR_HYSEN_Pos)    /*!< ACMP CR: HYSEN Mask */
#define ACMP_CR_ACMPOINV_Pos      3                             /*!< ACMP CR: ACMPOINV Position */
#define ACMP_CR_ACMPOINV_Msk      (1ul << ACMP_CR_ACMPOINV_Pos) /*!< ACMP CR: ACMPOINV Mask */
#define ACMP_CR_NEGSEL_Pos        4                             /*!< ACMP CR: NEGSEL Position */
#define ACMP_CR_NEGSEL_Msk        (1ul << ACMP_CR_NEGSEL_Pos)   /*!< ACMP CR: NEGSEL Mask */
#define ACMP_CR_POSSEL_Pos        5                             /*!< ACMP CR: POSSEL Position */
#define ACMP_CR_POSSEL_Msk        (7ul << ACMP_CR_POSSEL_Pos)   /*!< ACMP CR: POSSEL Mask */

/* ACMP_SR Bit Field Definitions */
#define ACMP_SR_ACMPF0_Pos        0                             /*!< ACMP SR: ACMPF0 Position */
#define ACMP_SR_ACMPF0_Msk        (1ul << ACMP_SR_ACMPF0_Pos)   /*!< ACMP SR: ACMPF0 Mask */
#define ACMP_SR_ACMPF1_Pos        1                             /*!< ACMP SR: ACMPF1 Position */
#define ACMP_SR_ACMPF1_Msk        (1ul << ACMP_SR_ACMPF1_Pos)   /*!< ACMP SR: ACMPF1 Mask */
#define ACMP_SR_ACMPF2_Pos        2                             /*!< ACMP SR: ACMPF2 Position */
#define ACMP_SR_ACMPF2_Msk        (1ul << ACMP_SR_ACMPF2_Pos)   /*!< ACMP SR: ACMPF2 Mask */
#define ACMP_SR_ACMPO0_Pos        3                             /*!< ACMP SR: ACMPO0 Position */
#define ACMP_SR_ACMPO0_Msk        (1ul << ACMP_SR_ACMPO0_Pos)   /*!< ACMP SR: ACMPO0 Mask */
#define ACMP_SR_ACMPO1_Pos        4                             /*!< ACMP SR: ACMPO1 Position */
#define ACMP_SR_ACMPO1_Msk        (1ul << ACMP_SR_ACMPO1_Pos)   /*!< ACMP SR: ACMPO1 Mask */
#define ACMP_SR_ACMPO2_Pos        5                             /*!< ACMP SR: ACMPO2 Position */
#define ACMP_SR_ACMPO2_Msk        (1ul << ACMP_SR_ACMPO2_Pos)   /*!< ACMP SR: ACMPO2 Mask */

/* ACMP_RVCR Bit Field Definitions */
#define ACMP_RVCR_CRVS_Pos        0                                 /*!< ACMP RVCRR: CRVS Position */
#define ACMP_RVCR_CRVS_Msk        (0xFul << ACMP_RVCR_CRVS_Pos)     /*!< ACMP RVCRR: CRVS Mask */
#define ACMP_RVCR_CRVSRC_SEL_Pos  6                                 /*!< ACMP RVCRR: CRVSRC_SEL Position */
#define ACMP_RVCR_CRVSRC_SEL_Msk  (1ul << ACMP_RVCR_CRVSRC_SEL_Pos) /*!< ACMP RVCRR: CRVSRC_SEL Mask */
#define ACMP_RVCR_INTREF_SEL_Pos  7                                 /*!< ACMP RVCRR: INTREF_SEL Position */
#define ACMP_RVCR_INTREF_SEL_Msk  (1ul << ACMP_RVCR_INTREF_SEL_Pos) /*!< ACMP RVCRR: INTREF_SEL Mask */

/*@}*/ /* end of group NUC400_ACMP */

/*------------- I2S Control Register (I2S) -----------------------------*/
/** @addtogroup NUC400_I2S NUC400 I2S Control Register (I2S)
  @{
*/
typedef struct {
    __IO uint32_t CON;                        /*!< Offset: 0x0000   I2S Control Register                                */
    __IO uint32_t CLKDIV;                        /*!< Offset: 0x0004   I2S Clock Divider Control Register                  */
    __IO uint32_t IE;                            /*!< Offset: 0x0008   I2S Interrupt Enable Register                      */
    __IO uint32_t STATUS;                        /*!< Offset: 0x000C   I2S Status Register                                  */
    __O  uint32_t TXFIFO;                        /*!< Offset: 0x0010   I2S Transmit FIFO    Register                         */
    __I  uint32_t RXFIFO;                        /*!< Offset: 0x0014   I2S Receive FIFO Register                             */
} I2S_T;


/* I2S_CON Bit Field Definitions */
#define I2S_CON_I2SEN_Pos             0                                       /*!< I2S_CON: I2S enable */
#define I2S_CON_I2SEN_Msk             (0x1ul << I2S_CON_I2SEN_Pos)            /*!< I2S_CON: I2SEN Mask */
#define I2S_CON_TXEN_Pos             1                                       /*!< I2S_CON: Data transmit enable */
#define I2S_CON_TXEN_Msk             (0x1ul << I2S_CON_TXEN_Pos)                /*!< I2S_CON: TXEN Mask */
#define I2S_CON_RXEN_Pos             2                                       /*!< I2S_CON: Data receive enable */
#define I2S_CON_RXEN_Msk             (0x1ul << I2S_CON_RXEN_Pos)                /*!< I2S_CON: RXEN Mask */
#define I2S_CON_MUTE_Pos             3                                       /*!< I2S_CON: Transmit mute enable */
#define I2S_CON_MUTE_Msk             (0x1ul << I2S_CON_MUTE_Pos)                /*!< I2S_CON: MUTE Mask */
#define I2S_CON_WORDWIDTH_Pos         4                                       /*!< I2S_CON: Word length */
#define I2S_CON_WORDWIDTH_Msk         (0x3ul << I2S_CON_WORDWIDTH_Pos)        /*!< I2S_CON: WORDWIDTH Mask */
#define I2S_CON_MONO_Pos             6                                       /*!< I2S_CON: Stereo or mono format select */
#define I2S_CON_MONO_Msk             (0x1ul << I2S_CON_MONO_Pos)                /*!< I2S_CON: MONO Mask */
#define I2S_CON_FORMAT_Pos             7                                       /*!< I2S_CON: I2S or MSB-justified format select */
#define I2S_CON_FORMAT_Msk             (0x1ul << I2S_CON_FORMAT_Pos)            /*!< I2S_CON: FORMAT Mask */
#define I2S_CON_SLAVE_Pos             8                                       /*!< I2S_CON: Slave or master mode */
#define I2S_CON_SLAVE_Msk             (0x1ul << I2S_CON_SLAVE_Pos)            /*!< I2S_CON: SLAVE Mask */
#define I2S_CON_TXTH_Pos             9                                       /*!< I2S_CON: Transmit FIFO threshold level */
#define I2S_CON_TXTH_Msk             (0x7ul << I2S_CON_TXTH_Pos)                /*!< I2S_CON: TXTH Mask */
#define I2S_CON_RXTH_Pos             12                                      /*!< I2S_CON: Receive FIFO threshold level */
#define I2S_CON_RXTH_Msk             (0x7ul << I2S_CON_RXTH_Pos)                /*!< I2S_CON: RXTH Mask */
#define I2S_CON_MCLKEN_Pos             15                                      /*!< I2S_CON: Master clock enable */
#define I2S_CON_MCLKEN_Msk             (0x1ul << I2S_CON_MCLKEN_Pos)            /*!< I2S_CON: MCLKEN Mask */
#define I2S_CON_RCHZCEN_Pos         16                                      /*!< I2S_CON: Right channel zero-cross detection enable */
#define I2S_CON_RCHZCEN_Msk         (0x1ul << I2S_CON_RCHZCEN_Pos)            /*!< I2S_CON: RCHZCEN Mask */
#define I2S_CON_LCHZCEN_Pos         17                                      /*!< I2S_CON: Left channel zero-cross detect enable */
#define I2S_CON_LCHZCEN_Msk         (0x1ul << I2S_CON_LCHZCEN_Pos)            /*!< I2S_CON: LCHZCEN Mask */
#define I2S_CON_CLR_TXFIFO_Pos         18                                      /*!< I2S_CON: Clear transmit FIFO */
#define I2S_CON_CLR_TXFIFO_Msk         (0x1ul << I2S_CON_CLR_TXFIFO_Pos)       /*!< I2S_CON: CLR_TXFIFO Mask */
#define I2S_CON_CLR_RXFIFO_Pos         19                                      /*!< I2S_CON: Clear receive FIFO */
#define I2S_CON_CLR_RXFIFO_Msk         (0x1ul << I2S_CON_CLR_RXFIFO_Pos)       /*!< I2S_CON: CLR_RXFIFO Mask */
#define I2S_CON_TXDMA_Pos             20                                      /*!< I2S_CON: Enable transmit DMA */
#define I2S_CON_TXDMA_Msk             (0x1ul << I2S_CON_TXDMA_Pos)               /*!< I2S_CON: TXDMA Mask */
#define I2S_CON_RXDMA_Pos             21                                      /*!< I2S_CON: Enable receive DMA */
#define I2S_CON_RXDMA_Msk             (0x1ul << I2S_CON_RXDMA_Pos)               /*!< I2S_CON: RXDMA Mask */
#define I2S_CON_RXLCH_Pos             23                                      /*!< I2S_CON: Receive left channel enable */
#define I2S_CON_RXLCH_Msk             (0x1ul << I2S_CON_RXLCH_Pos)               /*!< I2S_CON: RXLCH Mask */
#define I2S_CON_PCM_Pos             24                                      /*!< I2S_CON: PCM interface enable */
#define I2S_CON_PCM_Msk             (0x1ul << I2S_CON_PCM_Pos)               /*!< I2S_CON: PCM Mask */

/* I2S_CLKDIV Bit Field Definitions */
#define I2S_CLKDIV_MCLK_DIV_Pos        0                                       /*!< I2S_CLKDIV: Master clock divider */
#define I2S_CLKDIV_MCLK_DIV_Msk        (0x3Ful << I2S_CLKDIV_MCLK_DIV_Pos)        /*!< I2S_CLKDIV: MCLK_DIV Mask */
#define I2S_CLKDIV_BCLK_DIV_Pos        8                                       /*!< I2S_CLKDIV: Bit clock divider */
#define I2S_CLKDIV_BCLK_DIV_Msk        (0x1FFul << I2S_CLKDIV_BCLK_DIV_Pos)       /*!< I2S_CLKDIV: BCLK_DIV Mask */

/* I2S_IE Bit Field Definitions */
#define I2S_IE_RXUDFIE_Pos            0                                       /*!< I2S_IE: Receive FIFO underflow interrupt enable */
#define I2S_IE_RXUDFIE_Msk            (0x1ul << I2S_IE_RXUDFIE_Pos)            /*!< I2S_IE: RXUDFIE Mask */
#define I2S_IE_RXOVFIE_Pos            1                                       /*!< I2S_IE: Receive FIFO overflow interrupt enable */
#define I2S_IE_RXOVFIE_Msk            (0x1ul << I2S_IE_RXOVFIE_Pos)           /*!< I2S_IE: RXOVFIE Mask */
#define I2S_IE_RXTHIE_Pos            2                                       /*!< I2S_IE: Receive FIFO underflow interrupt enable */
#define I2S_IE_RXTHIE_Msk            (0x1ul << I2S_IE_RXTHIE_Pos)            /*!< I2S_IE: RXTHIE Mask */
#define I2S_IE_TXUDFIE_Pos            8                                       /*!< I2S_IE: Transmit FIFO underflow interrupt enable */
#define I2S_IE_TXUDFIE_Msk            (0x1ul << I2S_IE_TXUDFIE_Pos)           /*!< I2S_IE: TXUDFIE Mask */
#define I2S_IE_TXOVFIE_Pos            9                                       /*!< I2S_IE: Transmit FIFO overflow interrupt enable */
#define I2S_IE_TXOVFIE_Msk            (0x1ul << I2S_IE_TXOVFIE_Pos)           /*!< I2S_IE: TXOVFIE_ Mask */
#define I2S_IE_TXTHIE_Pos            10                                      /*!< I2S_IE: Transmit FIFO threshold level interrupt enable */
#define I2S_IE_TXTHIE_Msk            (0x1ul << I2S_IE_TXTHIE_Pos)            /*!< I2S_IE: TXTHIE Mask */
#define I2S_IE_RZCIE_Pos            11                                      /*!< I2S_IE: Right channel zero-cross interrupt enable */
#define I2S_IE_RZCIE_Msk            (0x1ul << I2S_IE_RZCIE_Pos)               /*!< I2S_IE: RZCIE Mask */
#define I2S_IE_LZCIE_Pos            12                                      /*!< I2S_IE: Left channel zero-cross interrupt enable */
#define I2S_IE_LZCIE_Msk            (0x1ul << I2S_IE_LZCIE_Pos)               /*!< I2S_IE: LZCIE Mask */

/* I2S_STATUS Bit Field Definitions */
#define I2S_STATUS_I2SINT_Pos        0                                       /*!< I2S_STATUS: I2S interrupt flag */
#define I2S_STATUS_I2SINT_Msk        (0x1ul << I2S_STATUS_I2SINT_Pos)        /*!< I2S_STATUS: I2SINT Mask */
#define I2S_STATUS_I2SRXINT_Pos        1                                       /*!< I2S_STATUS: Receive interrupt flag */
#define I2S_STATUS_I2SRXINT_Msk        (0x1ul << I2S_STATUS_I2SRXINT_Pos)        /*!< I2S_STATUS: I2SRXINT Mask */
#define I2S_STATUS_I2STXINT_Pos        2                                       /*!< I2S_STATUS: Transmit interrupt flag */
#define I2S_STATUS_I2STXINT_Msk        (0x1ul << I2S_STATUS_I2STXINT_Pos)        /*!< I2S_STATUS: I2STXINT Mask */
#define I2S_STATUS_RIGHT_Pos        3                                       /*!< I2S_STATUS: Right or left channel select */
#define I2S_STATUS_RIGHT_Msk        (0x1ul << I2S_STATUS_RIGHT_Pos)            /*!< I2S_STATUS: RIGHT Mask */
#define I2S_STATUS_RXUDF_Pos        8                                       /*!< I2S_STATUS: Receive FIFO underflow flag */
#define I2S_STATUS_RXUDF_Msk        (0x1ul << I2S_STATUS_RXUDF_Pos)            /*!< I2S_STATUS: RXUDF Mask */
#define I2S_STATUS_RXOVF_Pos        9                                       /*!< I2S_STATUS: Receive FIFO overflow flag */
#define I2S_STATUS_RXOVF_Msk        (0x1ul << I2S_STATUS_RXOVF_Pos)            /*!< I2S_STATUS: RXOVF Mask */
#define I2S_STATUS_RXTHF_Pos        10                                      /*!< I2S_STATUS: Receive FIFO threshold flag */
#define I2S_STATUS_RXTHF_Msk        (0x1ul << I2S_STATUS_RXTHF_Pos)            /*!< I2S_STATUS: RXTHF Mask */
#define I2S_STATUS_RXFULL_Pos        11                                      /*!< I2S_STATUS: Receive FIFO full flag */
#define I2S_STATUS_RXFULL_Msk        (0x1ul << I2S_STATUS_RXFULL_Pos)        /*!< I2S_STATUS: RXFULL Mask */
#define I2S_STATUS_RXEMPTY_Pos        12                                      /*!< I2S_STATUS: Receive FIFO empty flag */
#define I2S_STATUS_RXEMPTY_Msk        (0x1ul << I2S_STATUS_RXEMPTY_Pos)        /*!< I2S_STATUS: RXEMPTY Mask */
#define I2S_STATUS_TXUDF_Pos        16                                      /*!< I2S_STATUS: Transmit FIFO underflow flag */
#define I2S_STATUS_TXUDF_Msk        (0x1ul << I2S_STATUS_TXUDF_Pos)            /*!< I2S_STATUS: TXUDF Mask */
#define I2S_STATUS_TXOVF_Pos        17                                      /*!< I2S_STATUS: Transmit FIFO overflow flag */
#define I2S_STATUS_TXOVF_Msk        (0x1ul << I2S_STATUS_TXOVF_Pos)            /*!< I2S_STATUS: TXOVF Mask */
#define I2S_STATUS_TXTHF_Pos        18                                      /*!< I2S_STATUS: Transmit FIFO threshold flag */
#define I2S_STATUS_TXTHF_Msk        (0x1ul << I2S_STATUS_TXTHF_Pos)            /*!< I2S_STATUS: TXTHF Mask */
#define I2S_STATUS_TXFULL_Pos        19                                      /*!< I2S_STATUS: Transmit FIFO full flag */
#define I2S_STATUS_TXFULL_Msk        (0x1ul << I2S_STATUS_TXFULL_Pos)        /*!< I2S_STATUS: TXFULL Mask */
#define I2S_STATUS_TXEMPTY_Pos        20                                      /*!< I2S_STATUS: Transmit FIFO empty flag */
#define I2S_STATUS_TXEMPTY_Msk        (0x1ul << I2S_STATUS_TXEMPTY_Pos)        /*!< I2S_STATUS: TXEMPTY Mask */
#define I2S_STATUS_TXBUSY_Pos        21                                      /*!< I2S_STATUS: Transmit under busy */
#define I2S_STATUS_TXBUSY_Msk        (0x1ul << I2S_STATUS_TXBUSY_Pos)        /*!< I2S_STATUS: TXBUSY Mask */
#define I2S_STATUS_RZCIE_Pos        22                                      /*!< I2S_STATUS: Right channel zero-cross flag */
#define I2S_STATUS_RZCIE_Msk        (0x1ul << I2S_STATUS_RZCIE_Pos)            /*!< I2S_STATUS: RZCIE Mask */
#define I2S_STATUS_LZCIE_Pos        23                                      /*!< I2S_STATUS: Left channel zero-cross flag */
#define I2S_STATUS_LZCIE_Msk        (0x1ul << I2S_STATUS_LZCIE_Pos)            /*!< I2S_STATUS: LZCIE Mask */
#define I2S_STATUS_RX_LEVEL_Pos        24                                      /*!< I2S_STATUS: Receive FIFO level */
#define I2S_STATUS_RX_LEVEL_Msk        (0xFul << I2S_STATUS_RX_LEVEL_Pos)        /*!< I2S_STATUS: RX_LEVEL Mask */
#define I2S_STATUS_TX_LEVEL_Pos        28                                      /*!< I2S_STATUS: Transmit FIFO level */
#define I2S_STATUS_TX_LEVEL_Msk        (0xFul << I2S_STATUS_TX_LEVEL_Pos)        /*!< I2S_STATUS: TX_LEVEL Mask */

/*@}*/ /* end of group NUC400_I2S */

/*------------- USB Device Control Register (USBD) -----------------------------*/
/** @addtogroup NUC400_USBD NUC400 USB Device Control Register (USBD)
  @{
*/
typedef struct {
    __IO uint32_t IRQ_STAT_L;                    /*!< Offset: 0x0000   Interrupt Register */
    uint32_t RESERVED0;                          /*!< Offset: 0x0004   Reserved */
    __IO uint32_t IRQ_ENB_L;                     /*!< Offset: 0x0008   Interrupt Enable Low Register */
    uint32_t RESERVED1;                          /*!< Offset: 0x000C   Reserved */
    __IO uint32_t IRQ_STAT;                      /*!< Offset: 0x0010   USB Interrupt Status Register */
    __IO uint32_t IRQ_ENB;                       /*!< Offset: 0x0014   USB Interrupt Enable Register */
    __IO uint32_t OPER;                          /*!< Offset: 0x0018   USB Operational Register */
    __I  uint32_t FRAME_CNT;                     /*!< Offset: 0x001C   USB Frame Count Register */
    __IO uint32_t ADDR;                          /*!< Offset: 0x0020   USB Address Register */
    __IO uint32_t TEST;                          /*!< Offset: 0x0024   USB Test Mode Register */
    union {
        __IO uint32_t CEP_DATA_BUF;                  /*!< Offset: 0x0028   Control-ep Data Buffer */
        __IO uint8_t  CEP_DATA_BUF_BYTE;
    };
    __IO uint32_t CEP_CTRL_STAT;                 /*!< Offset: 0x002C   Control-ep Control and Status */
    __IO uint32_t CEP_IRQ_ENB;                   /*!< Offset: 0x0030   Control-ep Interrupt Enable */
    __IO uint32_t CEP_IRQ_STAT;                  /*!< Offset: 0x0034   Control-ep Interrupt Status */
    __IO uint32_t IN_TRF_CNT;                    /*!< Offset: 0x0038   In-transfer Data Count */
    __I  uint32_t OUT_TRF_CNT;                   /*!< Offset: 0x003C   Out-transfer Data Count */
    __I  uint32_t CEP_CNT;                       /*!< Offset: 0x0040   Control-ep Data Count */
    __I  uint32_t SETUP1_0;                      /*!< Offset: 0x0044   Setup1 & Setup0 bytes */
    __I  uint32_t SETUP3_2;                      /*!< Offset: 0x0048   Setup3 & Setup2 bytes */
    __I  uint32_t SETUP5_4;                      /*!< Offset: 0x004C   Setup5 & Setup4 bytes */
    __I  uint32_t SETUP7_6;                      /*!< Offset: 0x0050   Setup7 & Setup6 bytes */
    __IO uint32_t CEP_START_ADDR;                /*!< Offset: 0x0054   Control-ep RAM Start Address Register */
    __IO uint32_t CEP_END_ADDR;                  /*!< Offset: 0x0058   Control-ep RAM End Address Register */
    __IO uint32_t DMA_CTRL_STS;                  /*!< Offset: 0x005C   DMA Control Status Register */
    __IO uint32_t DMA_CNT;                       /*!< Offset: 0x0060   DMA Count Register */
    union {
        __IO uint32_t EPA_DATA_BUF;                  /*!< Offset: 0x0064   Endpoint A Data Register */
        __IO uint8_t EPA_DATA_BUF_BYTE;
    };
    __IO uint32_t EPA_IRQ_STAT;                  /*!< Offset: 0x0068   Endpoint A Interrupt Status Register */
    __IO uint32_t EPA_IRQ_ENB;                   /*!< Offset: 0x006C   Endpoint A Interrupt Enable Register */
    __I  uint32_t EPA_DATA_CNT;                  /*!< Offset: 0x0070   Endpoint A Data Available count Register */
    __IO uint32_t EPA_RSP_SC;                    /*!< Offset: 0x0074   Endpoint A Response Set/Clear Register */
    __IO uint32_t EPA_MPS;                       /*!< Offset: 0x0078   Endpoint A Maximum Packet Size Register */
    __IO uint32_t EPA_TRF_CNT;                   /*!< Offset: 0x007C   Endpoint A Transfer Count Register */
    __IO uint32_t EPA_CFG;                       /*!< Offset: 0x0080   Endpoint A Configuration Register */
    __IO uint32_t EPA_START_ADDR;                /*!< Offset: 0x0084   Endpoint A RAM Start Address Register */
    __IO uint32_t EPA_END_ADDR;                  /*!< Offset: 0x0088   Endpoint A RAM End Address Register */
    union {
        __IO uint32_t EPB_DATA_BUF;                  /*!< Offset: 0x008c   Endpoint B Data Register */
        __IO uint8_t EPB_DATA_BUF_BYTE;
    };
    __IO uint32_t EPB_IRQ_STAT;                  /*!< Offset: 0x0090   Endpoint B Interrupt Status Register */
    __IO uint32_t EPB_IRQ_ENB;                   /*!< Offset: 0x0094   Endpoint B Interrupt Enable Register */
    __I  uint32_t EPB_DATA_CNT;                  /*!< Offset: 0x0098   Endpoint B Data Available count Register */
    __IO uint32_t EPB_RSP_SC;                    /*!< Offset: 0x009C   Endpoint B Response Set/Clear Register */
    __IO uint32_t EPB_MPS;                       /*!< Offset: 0x00A0   Endpoint B Maximum Packet Size Register */
    __IO uint32_t EPB_TRF_CNT;                   /*!< Offset: 0x00A4   Endpoint B Transfer Count Register */
    __IO uint32_t EPB_CFG;                       /*!< Offset: 0x00A8   Endpoint B Configuration Register */
    __IO uint32_t EPB_START_ADDR;                /*!< Offset: 0x00AC   Endpoint B RAM Start Address Register */
    __IO uint32_t EPB_END_ADDR;                  /*!< Offset: 0x00B0   Endpoint B RAM End Address Register */
    union {
        __IO uint32_t EPC_DATA_BUF;                  /*!< Offset: 0x00B4   Endpoint C Data Register */
        __IO uint8_t EPC_DATA_BUF_BYTE;
    };
    __IO uint32_t EPC_IRQ_STAT;                  /*!< Offset: 0x00B8   Endpoint C Interrupt Status Register */
    __IO uint32_t EPC_IRQ_ENB;                   /*!< Offset: 0x00BC   Endpoint C Interrupt Enable Register */
    __I  uint32_t EPC_DATA_CNT;                  /*!< Offset: 0x00C0   Endpoint C Data Available count Register */
    __IO uint32_t EPC_RSP_SC;                    /*!< Offset: 0x00C4   Endpoint C Response Set/Clear Register */
    __IO uint32_t EPC_MPS;                       /*!< Offset: 0x00C8   Endpoint C Maximum Packet Size Register */
    __IO uint32_t EPC_TRF_CNT;                   /*!< Offset: 0x00CC   Endpoint C Transfer Count Register */
    __IO uint32_t EPC_CFG;                       /*!< Offset: 0x00D0   Endpoint C Configuration Register */
    __IO uint32_t EPC_START_ADDR;                /*!< Offset: 0x00D4   Endpoint C RAM Start Address Register */
    __IO uint32_t EPC_END_ADDR;                  /*!< Offset: 0x00D8   Endpoint C RAM End Address Register */
    union {
        __IO uint32_t EPD_DATA_BUF;                  /*!< Offset: 0x00dc   Endpoint D Data Register */
        __IO uint8_t EPD_DATA_BUF_BYTE;
    };
    __IO uint32_t EPD_IRQ_STAT;                  /*!< Offset: 0x00E0   Endpoint D Interrupt Status Register */
    __IO uint32_t EPD_IRQ_ENB;                   /*!< Offset: 0x00E4   Endpoint D Interrupt Enable Register */
    __I  uint32_t EPD_DATA_CNT;                  /*!< Offset: 0x00E8   Endpoint D Data Available count Register */
    __IO uint32_t EPD_RSP_SC;                    /*!< Offset: 0x00EC   Endpoint D Response Set/Clear Register */
    __IO uint32_t EPD_MPS;                       /*!< Offset: 0x00F0   Endpoint D Maximum Packet Size Register */
    __IO uint32_t EPD_TRF_CNT;                   /*!< Offset: 0x00F4   Endpoint D Transfer Count Register */
    __IO uint32_t EPD_CFG;                       /*!< Offset: 0x00F8   Endpoint D Configuration Register */
    __IO uint32_t EPD_START_ADDR;                /*!< Offset: 0x00FC   Endpoint D RAM Start Address Register */
    __IO uint32_t EPD_END_ADDR;                  /*!< Offset: 0x0100   Endpoint D RAM End Address Register */
    union {
        __IO uint32_t EPE_DATA_BUF;                  /*!< Offset: 0x0104   Endpoint E Data Register */
        __IO uint8_t EPE_DATA_BUF_BYTE;
    };
    __IO uint32_t EPE_IRQ_STAT;                  /*!< Offset: 0x0108   Endpoint E Interrupt Status Register */
    __IO uint32_t EPE_IRQ_ENB;                   /*!< Offset: 0x010C   Endpoint E Interrupt Enable Register */
    __I  uint32_t EPE_DATA_CNT;                  /*!< Offset: 0x0110   Endpoint E Data Available count Register */
    __IO uint32_t EPE_RSP_SC;                    /*!< Offset: 0x0114   Endpoint E Response Set/Clear Register */
    __IO uint32_t EPE_MPS;                       /*!< Offset: 0x0118   Endpoint E Maximum Packet Size Register */
    __IO uint32_t EPE_TRF_CNT;                   /*!< Offset: 0x011C   Endpoint E Transfer Count Register */
    __IO uint32_t EPE_CFG;                       /*!< Offset: 0x0120   Endpoint E Configuration Register */
    __IO uint32_t EPE_START_ADDR;                /*!< Offset: 0x0124   Endpoint E RAM Start Address Register */
    __IO uint32_t EPE_END_ADDR;                  /*!< Offset: 0x0128   Endpoint E RAM End Address Register */
    union {
        __IO uint32_t EPF_DATA_BUF;                  /*!< Offset: 0x012c   Endpoint F Data Register */
        __IO uint8_t EPF_DATA_BUF_BYTE;
    };
    __IO uint32_t EPF_IRQ_STAT;                  /*!< Offset: 0x0130   Endpoint F Interrupt Status Register */
    __IO uint32_t EPF_IRQ_ENB;                   /*!< Offset: 0x0134   Endpoint F Interrupt Enable Register */
    __I  uint32_t EPF_DATA_CNT;                  /*!< Offset: 0x0138   Endpoint F Data Available count Register */
    __IO uint32_t EPF_RSP_SC;                    /*!< Offset: 0x013C   Endpoint F Response Set/Clear Register */
    __IO uint32_t EPF_MPS;                       /*!< Offset: 0x0140   Endpoint F Maximum Packet Size Register */
    __IO uint32_t EPF_TRF_CNT;                   /*!< Offset: 0x0144   Endpoint F Transfer Count Register */
    __IO uint32_t EPF_CFG;                       /*!< Offset: 0x0148   Endpoint F Configuration Register */
    __IO uint32_t EPF_START_ADDR;                /*!< Offset: 0x014C   Endpoint F RAM Start Address Register */
    __IO uint32_t EPF_END_ADDR;                  /*!< Offset: 0x0150   Endpoint F RAM End Address Register */
    union {
        __IO uint32_t EPG_DATA_BUF;                  /*!< Offset: 0x0154   Endpoint F Data Register */
        __IO uint8_t EPG_DATA_BUF_BYTE;
    };
    __IO uint32_t EPG_IRQ_STAT;                  /*!< Offset: 0x0158   Endpoint G Interrupt Status Register */
    __IO uint32_t EPG_IRQ_ENB;                   /*!< Offset: 0x015C   Endpoint G Interrupt Enable Register */
    __I  uint32_t EPG_DATA_CNT;                  /*!< Offset: 0x0160   Endpoint G Data Available count Register */
    __IO uint32_t EPG_RSP_SC;                    /*!< Offset: 0x0164   Endpoint G Response Set/Clear Register */
    __IO uint32_t EPG_MPS;                       /*!< Offset: 0x0168   Endpoint G Maximum Packet Size Register */
    __IO uint32_t EPG_TRF_CNT;                   /*!< Offset: 0x016C   Endpoint G Transfer Count Register */
    __IO uint32_t EPG_CFG;                       /*!< Offset: 0x0170   Endpoint G Configuration Register */
    __IO uint32_t EPG_START_ADDR;                /*!< Offset: 0x0174   Endpoint G RAM Start Address Register */
    __IO uint32_t EPG_END_ADDR;                  /*!< Offset: 0x0178   Endpoint G RAM End Address Register */
    union {
        __IO uint32_t EPH_DATA_BUF;                  /*!< Offset: 0x017c   Endpoint H Data Register */
        __IO uint8_t EPH_DATA_BUF_BYTE;
    };
    __IO uint32_t EPH_IRQ_STAT;                  /*!< Offset: 0x0180   Endpoint H Interrupt Status Register */
    __IO uint32_t EPH_IRQ_ENB;                   /*!< Offset: 0x0184   Endpoint H Interrupt Enable Register */
    __I  uint32_t EPH_DATA_CNT;                  /*!< Offset: 0x0188   Endpoint H Data Available count Register */
    __IO uint32_t EPH_RSP_SC;                    /*!< Offset: 0x018C   Endpoint H Response Set/Clear Register */
    __IO uint32_t EPH_MPS;                       /*!< Offset: 0x0190   Endpoint H Maximum Packet Size Register */
    __IO uint32_t EPH_TRF_CNT;                   /*!< Offset: 0x0194   Endpoint H Transfer Count Register */
    __IO uint32_t EPH_CFG;                       /*!< Offset: 0x0198   Endpoint H Configuration Register */
    __IO uint32_t EPH_START_ADDR;                /*!< Offset: 0x019C   Endpoint H RAM Start Address Register */
    __IO uint32_t EPH_END_ADDR;                  /*!< Offset: 0x01A0   Endpoint H RAM End Address Register */
    union {
        __IO uint32_t EPI_DATA_BUF;                  /*!< Offset: 0x01A4   Endpoint I Data Register */
        __IO uint8_t EPI_DATA_BUF_BYTE;
    };
    __IO uint32_t EPI_IRQ_STAT;                  /*!< Offset: 0x01A8   Endpoint I Interrupt Status Register */
    __IO uint32_t EPI_IRQ_ENB;                   /*!< Offset: 0x01AC   Endpoint I Interrupt Enable Register */
    __I  uint32_t EPI_DATA_CNT;                  /*!< Offset: 0x01B0   Endpoint I Data Available count Register */
    __IO uint32_t EPI_RSP_SC;                    /*!< Offset: 0x01B4   Endpoint I Response Set/Clear Register */
    __IO uint32_t EPI_MPS;                       /*!< Offset: 0x01B8   Endpoint I Maximum Packet Size Register */
    __IO uint32_t EPI_TRF_CNT;                   /*!< Offset: 0x01BC   Endpoint I Transfer Count Register */
    __IO uint32_t EPI_CFG;                       /*!< Offset: 0x01C0   Endpoint I Configuration Register */
    __IO uint32_t EPI_START_ADDR;                /*!< Offset: 0x01C4   Endpoint I RAM Start Address Register */
    __IO uint32_t EPI_END_ADDR;                  /*!< Offset: 0x01C8   Endpoint I RAM End Address Register */
    union {
        __IO uint32_t EPJ_DATA_BUF;                  /*!< Offset: 0x01cc   Endpoint J Data Register */
        __IO uint8_t EPJ_DATA_BUF_BYTE;
    };
    __IO uint32_t EPJ_IRQ_STAT;                  /*!< Offset: 0x01D0   Endpoint J Interrupt Status Register */
    __IO uint32_t EPJ_IRQ_ENB;                   /*!< Offset: 0x01D4   Endpoint J Interrupt Enable Register */
    __I  uint32_t EPJ_DATA_CNT;                  /*!< Offset: 0x01D8   Endpoint J Data Available count Register */
    __IO uint32_t EPJ_RSP_SC;                    /*!< Offset: 0x01DC   Endpoint J Response Set/Clear Register */
    __IO uint32_t EPJ_MPS;                       /*!< Offset: 0x01E0   Endpoint J Maximum Packet Size Register */
    __IO uint32_t EPJ_TRF_CNT;                   /*!< Offset: 0x01E4   Endpoint J Transfer Count Register */
    __IO uint32_t EPJ_CFG;                       /*!< Offset: 0x01E8   Endpoint J Configuration Register */
    __IO uint32_t EPJ_START_ADDR;                /*!< Offset: 0x01EC   Endpoint J RAM Start Address Register */
    __IO uint32_t EPJ_END_ADDR;                  /*!< Offset: 0x01F0   Endpoint J RAM End Address Register */
    union {
        __IO uint32_t EPK_DATA_BUF;                  /*!< Offset: 0x01f4   Endpoint K Data Register */
        __IO uint8_t EPK_DATA_BUF_BYTE;
    };
    __IO uint32_t EPK_IRQ_STAT;                  /*!< Offset: 0x01F8   Endpoint K Interrupt Status Register */
    __IO uint32_t EPK_IRQ_ENB;                   /*!< Offset: 0x01FC   Endpoint K Interrupt Enable Register */
    __I  uint32_t EPK_DATA_CNT;                  /*!< Offset: 0x0200   Endpoint K Data Available count Register */
    __IO uint32_t EPK_RSP_SC;                    /*!< Offset: 0x0204   Endpoint K Response Set/Clear Register */
    __IO uint32_t EPK_MPS;                       /*!< Offset: 0x0208   Endpoint K Maximum Packet Size Register */
    __IO uint32_t EPK_TRF_CNT;                   /*!< Offset: 0x020C   Endpoint K Transfer Count Register */
    __IO uint32_t EPK_CFG;                       /*!< Offset: 0x0210   Endpoint K Configuration Register */
    __IO uint32_t EPK_START_ADDR;                /*!< Offset: 0x0214   Endpoint K RAM Start Address Register */
    __IO uint32_t EPK_END_ADDR;                  /*!< Offset: 0x0218   Endpoint K RAM End Address Register */
    union {
        __IO uint32_t EPL_DATA_BUF;                  /*!< Offset: 0x021c   Endpoint L Data Register */
        __IO uint8_t EPL_DATA_BUF_BYTE;
    };
    __IO uint32_t EPL_IRQ_STAT;                  /*!< Offset: 0x0220   Endpoint L Interrupt Status Register */
    __IO uint32_t EPL_IRQ_ENB;                   /*!< Offset: 0x0224   Endpoint L Interrupt Enable Register */
    __I  uint32_t EPL_DATA_CNT;                  /*!< Offset: 0x0228   Endpoint L Data Available count Register */
    __IO uint32_t EPL_RSP_SC;                    /*!< Offset: 0x022C   Endpoint L Response Set/Clear Register */
    __IO uint32_t EPL_MPS;                       /*!< Offset: 0x0230   Endpoint L Maximum Packet Size Register */
    __IO uint32_t EPL_TRF_CNT;                   /*!< Offset: 0x0234   Endpoint L Transfer Count Register */
    __IO uint32_t EPL_CFG;                       /*!< Offset: 0x0238   Endpoint L Configuration Register */
    __IO uint32_t EPL_START_ADDR;                /*!< Offset: 0x023C   Endpoint L RAM Start Address Register */
    __IO uint32_t EPL_END_ADDR;                  /*!< Offset: 0x0240   Endpoint L RAM End Address Register */
    uint32_t RESERVED2;                       /*!< Offset: 0x0244   Reserved */
    __IO uint32_t HEAD_WORD0;                    /*!< Offset: 0x0248   USB head word 0 Register */
    __IO uint32_t HEAD_WORD1;                    /*!< Offset: 0x024C   USB head word 1 Register */
    __IO uint32_t HEAD_WORD2;                    /*!< Offset: 0x0250   USB head word 2 Register */
    __IO uint32_t EPA_HEAD_CNT;                  /*!< Offset: 0x0254   Endpoint A head count Register */
    __IO uint32_t EPB_HEAD_CNT;                  /*!< Offset: 0x0258   Endpoint B head count Register */
    __IO uint32_t EPC_HEAD_CNT;                  /*!< Offset: 0x025C   Endpoint C head count Register */
    __IO uint32_t EPD_HEAD_CNT;                  /*!< Offset: 0x0260   Endpoint D head count Register */
    __IO uint32_t EPE_HEAD_CNT;                  /*!< Offset: 0x0264   Endpoint E head count Register */
    __IO uint32_t EPF_HEAD_CNT;                  /*!< Offset: 0x0268   Endpoint F head count Register */
    __IO uint32_t EPG_HEAD_CNT;                  /*!< Offset: 0x026C   Endpoint G head count Register */
    __IO uint32_t EPH_HEAD_CNT;                  /*!< Offset: 0x0270   Endpoint H head count Register */
    __IO uint32_t EPI_HEAD_CNT;                  /*!< Offset: 0x0274   Endpoint I head count Register */
    __IO uint32_t EPJ_HEAD_CNT;                  /*!< Offset: 0x0278   Endpoint J head count Register */
    __IO uint32_t EPK_HEAD_CNT;                  /*!< Offset: 0x027C   Endpoint K head count Register */
    __IO uint32_t EPL_HEAD_CNT;                  /*!< Offset: 0x0280   Endpoint L head count Register */
    uint32_t RESERVED3[287];                     /*!< Offset: 0x0284 ~ 0x6FC   Reserved  */
    __IO uint32_t AHB_DMA_ADDR;                  /*!< Offset: 0x0700   AHB Address Register */
    __IO uint32_t PHY_CTL;                       /*!< Offset: 0x0704   USB PHY Control Register */

} USBD_T;

/* USBD IRQ_STAT_L Bit Field Definitions */
#define USBD_IRQ_STAT_L_EPL_Pos            13                                      /*!< USBD IRQ_STAT_L : EPL Position */
#define USBD_IRQ_STAT_L_EPL_Msk            (1ul << USBD_IRQ_STAT_L_EPL_Pos)        /*!< USBD IRQ_STAT_L : EPL Mask */

#define USBD_IRQ_STAT_L_EPK_Pos            12                                      /*!< USBD IRQ_STAT_L : EPK Position */
#define USBD_IRQ_STAT_L_EPK_Msk            (1ul << USBD_IRQ_STAT_L_EPK_Pos)        /*!< USBD IRQ_STAT_L : EPK Mask */

#define USBD_IRQ_STAT_L_EPJ_Pos            11                                      /*!< USBD IRQ_STAT_L : EPJ Position */
#define USBD_IRQ_STAT_L_EPJ_Msk            (1ul << USBD_IRQ_STAT_L_EPJ_Pos)        /*!< USBD IRQ_STAT_L : EPJ Mask */

#define USBD_IRQ_STAT_L_EPI_Pos            10                                      /*!< USBD IRQ_STAT_L : EPI Position */
#define USBD_IRQ_STAT_L_EPI_Msk            (1ul << USBD_IRQ_STAT_L_EPI_Pos)        /*!< USBD IRQ_STAT_L : EPI Mask */

#define USBD_IRQ_STAT_L_EPH_Pos            9                                       /*!< USBD IRQ_STAT_L : EPH Position */
#define USBD_IRQ_STAT_L_EPH_Msk            (1ul << USBD_IRQ_STAT_L_EPH_Pos)        /*!< USBD IRQ_STAT_L : EPH Mask */

#define USBD_IRQ_STAT_L_EPG_Pos            8                                       /*!< USBD IRQ_STAT_L : EPG Position */
#define USBD_IRQ_STAT_L_EPG_Msk            (1ul << USBD_IRQ_STAT_L_EPG_Pos)        /*!< USBD IRQ_STAT_L : EPG Mask */

#define USBD_IRQ_STAT_L_EPF_Pos            7                                       /*!< USBD IRQ_STAT_L : EPF Position */
#define USBD_IRQ_STAT_L_EPF_Msk            (1ul << USBD_IRQ_STAT_L_EPF_Pos)        /*!< USBD IRQ_STAT_L : EPF Mask */

#define USBD_IRQ_STAT_L_EPE_Pos            6                                       /*!< USBD IRQ_STAT_L : EPE Position */
#define USBD_IRQ_STAT_L_EPE_Msk            (1ul << USBD_IRQ_STAT_L_EPE_Pos)        /*!< USBD IRQ_STAT_L : EPE Mask */

#define USBD_IRQ_STAT_L_EPD_Pos            5                                       /*!< USBD IRQ_STAT_L : EPD Position */
#define USBD_IRQ_STAT_L_EPD_Msk            (1ul << USBD_IRQ_STAT_L_EPD_Pos)        /*!< USBD IRQ_STAT_L : EPD Mask */

#define USBD_IRQ_STAT_L_EPC_Pos            4                                       /*!< USBD IRQ_STAT_L : EPC Position */
#define USBD_IRQ_STAT_L_EPC_Msk            (1ul << USBD_IRQ_STAT_L_EPC_Pos)        /*!< USBD IRQ_STAT_L : EPC Mask */

#define USBD_IRQ_STAT_L_EPB_Pos            3                                       /*!< USBD IRQ_STAT_L : EPB Position */
#define USBD_IRQ_STAT_L_EPB_Msk            (1ul << USBD_IRQ_STAT_L_EPB_Pos)        /*!< USBD IRQ_STAT_L : EPB Mask */

#define USBD_IRQ_STAT_L_EPA_Pos            2                                       /*!< USBD IRQ_STAT_L : EPA Position */
#define USBD_IRQ_STAT_L_EPA_Msk            (1ul << USBD_IRQ_STAT_L_EPA_Pos)        /*!< USBD IRQ_STAT_L : EPA Mask */

#define USBD_IRQ_STAT_L_CEP_Pos            1                                       /*!< USBD IRQ_STAT_L : CEP Position */
#define USBD_IRQ_STAT_L_CEP_Msk            (1ul << USBD_IRQ_STAT_L_CEP_Pos)        /*!< USBD IRQ_STAT_L : CEP Mask */

#define USBD_IRQ_STAT_L_USB_Pos            0                                       /*!< USBD IRQ_STAT_L : USB Position */
#define USBD_IRQ_STAT_L_USB_Msk            (1ul << USBD_IRQ_STAT_L_USB_Pos)        /*!< USBD IRQ_STAT_L : USB Mask */

/* USBD IRQ_ENB_L Bit Field Definitions */
#define USBD_IRQ_ENB_L_EPL_Pos            13                                      /*!< USBD IRQ_ENB_L : EPL Position */
#define USBD_IRQ_ENB_L_EPL_Msk            (1ul << USBD_IRQ_ENB_L_EPL_Pos)         /*!< USBD IRQ_ENB_L : EPL Mask */

#define USBD_IRQ_ENB_L_EPK_Pos            12                                      /*!< USBD IRQ_ENB_L : EPK Position */
#define USBD_IRQ_ENB_L_EPK_Msk            (1ul << USBD_IRQ_ENB_L_EPK_Pos)         /*!< USBD IRQ_ENB_L : EPK Mask */

#define USBD_IRQ_ENB_L_EPJ_Pos            11                                      /*!< USBD IRQ_ENB_L : EPJ Position */
#define USBD_IRQ_ENB_L_EPJ_Msk            (1ul << USBD_IRQ_ENB_L_EPJ_Pos)         /*!< USBD IRQ_ENB_L : EPJ Mask */

#define USBD_IRQ_ENB_L_EPI_Pos            10                                      /*!< USBD IRQ_ENB_L : EPI Position */
#define USBD_IRQ_ENB_L_EPI_Msk            (1ul << USBD_IRQ_ENB_L_EPI_Pos)         /*!< USBD IRQ_ENB_L : EPI Mask */

#define USBD_IRQ_ENB_L_EPH_Pos            9                                       /*!< USBD IRQ_ENB_L : EPH Position */
#define USBD_IRQ_ENB_L_EPH_Msk            (1ul << USBD_IRQ_ENB_L_EPH_Pos)         /*!< USBD IRQ_ENB_L : EPH Mask */

#define USBD_IRQ_ENB_L_EPG_Pos            8                                       /*!< USBD IRQ_ENB_L : EPG Position */
#define USBD_IRQ_ENB_L_EPG_Msk            (1ul << USBD_IRQ_ENB_L_EPG_Pos)         /*!< USBD IRQ_ENB_L : EPG Mask */

#define USBD_IRQ_ENB_L_EPF_Pos            7                                       /*!< USBD IRQ_ENB_L : EPF Position */
#define USBD_IRQ_ENB_L_EPF_Msk            (1ul << USBD_IRQ_ENB_L_EPF_Pos)         /*!< USBD IRQ_ENB_L : EPF Mask */

#define USBD_IRQ_ENB_L_EPE_Pos            6                                       /*!< USBD IRQ_ENB_L : EPE Position */
#define USBD_IRQ_ENB_L_EPE_Msk            (1ul << USBD_IRQ_ENB_L_EPE_Pos)         /*!< USBD IRQ_ENB_L : EPE Mask */

#define USBD_IRQ_ENB_L_EPD_Pos            5                                       /*!< USBD IRQ_ENB_L : EPD Position */
#define USBD_IRQ_ENB_L_EPD_Msk            (1ul << USBD_IRQ_ENB_L_EPD_Pos)         /*!< USBD IRQ_ENB_L : EPD Mask */

#define USBD_IRQ_ENB_L_EPC_Pos            4                                       /*!< USBD IRQ_ENB_L : EPC Position */
#define USBD_IRQ_ENB_L_EPC_Msk            (1ul << USBD_IRQ_ENB_L_EPC_Pos)         /*!< USBD IRQ_ENB_L : EPC Mask */

#define USBD_IRQ_ENB_L_EPB_Pos            3                                       /*!< USBD IRQ_ENB_L : EPB Position */
#define USBD_IRQ_ENB_L_EPB_Msk            (1ul << USBD_IRQ_ENB_L_EPB_Pos)         /*!< USBD IRQ_ENB_L : EPB Mask */

#define USBD_IRQ_ENB_L_EPA_Pos            2                                       /*!< USBD IRQ_ENB_L : EPA Position */
#define USBD_IRQ_ENB_L_EPA_Msk            (1ul << USBD_IRQ_ENB_L_EPA_Pos)         /*!< USBD IRQ_ENB_L : EPA Mask */

#define USBD_IRQ_ENB_L_CEP_Pos            1                                       /*!< USBD IRQ_ENB_L : CEP Position */
#define USBD_IRQ_ENB_L_CEP_Msk            (1ul << USBD_IRQ_ENB_L_CEP_Pos)         /*!< USBD IRQ_ENB_L : CEP Mask */

#define USBD_IRQ_ENB_L_USB_Pos            0                                       /*!< USBD IRQ_ENB_L : USB Position */
#define USBD_IRQ_ENB_L_USB_Msk            (1ul << USBD_IRQ_ENB_L_USB_Pos)         /*!< USBD IRQ_ENB_L : USB Mask */

/* USBD IRQ_STAT Bit Field Definitions */
#define USBD_IRQ_STAT_FLODET_Pos          8                                      /*!< USBD IRQ_STAT : FLODET Position */
#define USBD_IRQ_STAT_FLODET_Msk          (1ul << USBD_IRQ_STAT_FLODET_Pos)      /*!< USBD IRQ_STAT : FLODET Mask */

#define USBD_IRQ_STAT_TCLKOK_Pos          6                                      /*!< USBD IRQ_STAT : TCLKOK Position */
#define USBD_IRQ_STAT_TCLKOK_Msk          (1ul << USBD_IRQ_STAT_TCLKOK_Pos)      /*!< USBD IRQ_STAT : TCLKOK Mask */

#define USBD_IRQ_STAT_DMACOM_Pos          5                                      /*!< USBD IRQ_STAT : DMACOM Position */
#define USBD_IRQ_STAT_DMACOM_Msk          (1ul << USBD_IRQ_STAT_DMACOM_Pos)      /*!< USBD IRQ_STAT : DMACOM Mask */

#define USBD_IRQ_STAT_HISPD_Pos           4                                      /*!< USBD IRQ_STAT : HISPD Position */
#define USBD_IRQ_STAT_HISPD_Msk           (1ul << USBD_IRQ_STAT_HISPD_Pos)       /*!< USBD IRQ_STAT : HISPD Mask */

#define USBD_IRQ_STAT_SUS_Pos             3                                      /*!< USBD IRQ_STAT : SUS Position */
#define USBD_IRQ_STAT_SUS_Msk             (1ul << USBD_IRQ_STAT_SUS_Pos)         /*!< USBD IRQ_STAT : SUS Mask */

#define USBD_IRQ_STAT_RUM_Pos             2                                      /*!< USBD IRQ_STAT : RUM Position */
#define USBD_IRQ_STAT_RUM_Msk             (1ul << USBD_IRQ_STAT_RUM_Pos)         /*!< USBD IRQ_STAT : RUM Mask */

#define USBD_IRQ_STAT_RST_Pos             1                                      /*!< USBD IRQ_STAT : RST Position */
#define USBD_IRQ_STAT_RST_Msk             (1ul << USBD_IRQ_STAT_RST_Pos)         /*!< USBD IRQ_STAT : RST Mask */

#define USBD_IRQ_STAT_SOF_Pos             0                                      /*!< USBD IRQ_STAT : SOF Position */
#define USBD_IRQ_STAT_SOF_Msk             (1ul << USBD_IRQ_STAT_SOF_Pos)         /*!< USBD IRQ_STAT : SOF Mask */

/* USBD IRQ_ENB Bit Field Definitions */
#define USBD_IRQ_ENB_FLODET_Pos           8                                      /*!< USBD IRQ_ENB : FLODET Position */
#define USBD_IRQ_ENB_FLODET_Msk           (1ul << USBD_IRQ_ENB_FLODET_Pos)       /*!< USBD IRQ_ENB : FLODET Mask */

#define USBD_IRQ_ENB_TCLKOK_Pos           6                                      /*!< USBD IRQ_ENB : TCLKOK Position */
#define USBD_IRQ_ENB_TCLKOK_Msk           (1ul << USBD_IRQ_ENB_TCLKOK_Pos)       /*!< USBD IRQ_ENB : TCLKOK Mask */

#define USBD_IRQ_ENB_DMACOM_Pos           5                                      /*!< USBD IRQ_ENB : DMACOM Position */
#define USBD_IRQ_ENB_DMACOM_Msk           (1ul << USBD_IRQ_ENB_DMACOM_Pos)       /*!< USBD IRQ_ENB : DMACOM Mask */

#define USBD_IRQ_ENB_HISPD_Pos            4                                      /*!< USBD IRQ_ENB : HISPD Position */
#define USBD_IRQ_ENB_HISPD_Msk            (1ul << USBD_IRQ_ENB_HISPD_Pos)        /*!< USBD IRQ_ENB : HISPD Mask */

#define USBD_IRQ_ENB_SUS_Pos              3                                      /*!< USBD IRQ_ENB : SUS Position */
#define USBD_IRQ_ENB_SUS_Msk              (1ul << USBD_IRQ_ENB_SUS_Pos)          /*!< USBD IRQ_ENB : SUS Mask */

#define USBD_IRQ_ENB_RUM_Pos              2                                      /*!< USBD IRQ_ENB : RUM Position */
#define USBD_IRQ_ENB_RUM_Msk              (1ul << USBD_IRQ_ENB_RUM_Pos)          /*!< USBD IRQ_ENB : RUM Mask */

#define USBD_IRQ_ENB_RST_Pos              1                                      /*!< USBD IRQ_ENB : RST Position */
#define USBD_IRQ_ENB_RST_Msk              (1ul << USBD_IRQ_ENB_RST_Pos)          /*!< USBD IRQ_ENB : RST Mask */

#define USBD_IRQ_ENB_SOF_Pos              0                                      /*!< USBD IRQ_ENB : SOF Position */
#define USBD_IRQ_ENB_SOF_Msk              (1ul << USBD_IRQ_ENB_SOF_Pos)          /*!< USBD IRQ_ENB : SOF Mask */

/* USBD OPER Bit Field Definitions */
#define USBD_OPER_CUR_SPD_Pos             2                                      /*!< USBD OPER : CUR_SPD Position */
#define USBD_OPER_CUR_SPD_Msk             (1ul << USBD_OPER_CUR_SPD_Pos)         /*!< USBD OPER : CUR_SPD Mask */

#define USBD_OPER_SET_HISPD_Pos           1                                      /*!< USBD OPER : SET_HISPD Position */
#define USBD_OPER_SET_HISPD_Msk           (1ul << USBD_OPER_SET_HISPD_Pos)       /*!< USBD OPER : SET_HISPD Mask */

#define USBD_OPER_GEN_RUM_Pos             0                                      /*!< USBD OPER : GEN_RUM Position */
#define USBD_OPER_GEN_RUM_Msk             (1ul << USBD_OPER_GEN_RUM_Pos)         /*!< USBD OPER : GEN_RUM Mask */

/* USBD FRAME_CNT Bit Field Definitions */
#define USBD_FRAME_CNT_FRAME_CNT_Pos      3                                          /*!< USBD FRAME_CNT : FRAME_CNT Position */
#define USBD_FRAME_CNT_FRAME_CNT_Msk      (0X7FFul << USBD_FRAME_CNT_FRAME_CNT_Pos)  /*!< USBD FRAME_CNT : FRAME_CNT Mask */

#define USBD_FRAME_CNT_MFRAME_CNT_Pos     0                                          /*!< USBD FRAME_CNT : MFRAME_CNT Position */
#define USBD_FRAME_CNT_MFRAME_CNT_Msk     (0X7ul << USBD_FRAME_CNT_MFRAME_CNT_Pos)   /*!< USBD FRAME_CNT : MFRAME_CNT Mask */

/* USBD ADDR Bit Field Definitions */
#define USBD_ADDR_ADDR_Pos                3                                          /*!< USBD ADDR : ADDR Position */
#define USBD_ADDR_ADDR_Msk                (0X7FFul << USBD_ADDR_ADDR_Pos)            /*!< USBD ADDR : ADDR Mask */

/* USBD CEP_DATA_BUF Bit Field Definitions */
#define USBD_CEP_DATA_BUF_Pos             0                                          /*!< USBD CEP_DATA_BUF : DATA_BUF Position */
#define USBD_CEP_DATA_BUF_Msk             (0XFFFFFFFFul << USBD_CEP_DATA_BUF_Pos)    /*!< USBD CEP_DATA_BUF : DATA_BUF Mask */

/* USBD CEP_CTRL_STAT Bit Field Definitions */
#define USBD_CEP_CTRL_STAT_FLUSH_Pos      3                                          /*!< USBD CEP_CTRL_STAT : FLUSH Position */
#define USBD_CEP_CTRL_STAT_FLUSH_Msk      (1ul << USBD_CEP_CTRL_STAT_FLUSH_Pos)      /*!< USBD CEP_CTRL_STAT : FLUSH Mask */

#define USBD_CEP_CTRL_STAT_ZEROLEN_Pos    2                                          /*!< USBD CEP_CTRL_STAT : ZEROLEN Position */
#define USBD_CEP_CTRL_STAT_ZEROLEN_Msk    (1ul << USBD_CEP_CTRL_STAT_ZEROLEN_Pos)    /*!< USBD CEP_CTRL_STAT : ZEROLEN Mask */

#define USBD_CEP_CTRL_STAT_STLALL_Pos     1                                          /*!< USBD CEP_CTRL_STAT : STLALL Position */
#define USBD_CEP_CTRL_STAT_STLALL_Msk     (1ul << USBD_CEP_CTRL_STAT_STLALL_Pos)     /*!< USBD CEP_CTRL_STAT : STLALL Mask */

#define USBD_CEP_CTRL_STAT_NAK_CLEAR_Pos  0                                          /*!< USBD CEP_CTRL_STAT : NAK_CLEAR Position */
#define USBD_CEP_CTRL_STAT_NAK_CLEAR_Msk  (1ul << USBD_CEP_CTRL_STAT_NAK_CLEAR_Pos)  /*!< USBD CEP_CTRL_STAT : NAK_CLEAR Mask */

/* USBD CEP_IRQ_ENB Bit Field Definitions */
#define USBD_CEP_IRQ_ENB_EMPTY_Pos        12                                         /*!< USBD CEP_IRQ_ENB : EMPTY Position */
#define USBD_CEP_IRQ_ENB_EMPTY_Msk        (1ul << USBD_CEP_IRQ_ENB_EMPTY_Pos)        /*!< USBD CEP_IRQ_ENB : EMPTY Mask */

#define USBD_CEP_IRQ_ENB_FULL_Pos         11                                         /*!< USBD CEP_IRQ_ENB : FULL Position */
#define USBD_CEP_IRQ_ENB_FULL_Msk         (1ul << USBD_CEP_IRQ_ENB_FULL_Pos)         /*!< USBD CEP_IRQ_ENB : FULL Mask */

#define USBD_CEP_IRQ_ENB_STACOM_Pos       10                                         /*!< USBD CEP_IRQ_ENB : STACOM Position */
#define USBD_CEP_IRQ_ENB_STACOM_Msk       (1ul << USBD_CEP_IRQ_ENB_STACOM_Pos)       /*!< USBD CEP_IRQ_ENB : STACOM Mask */

#define USBD_CEP_IRQ_ENB_ERR_Pos          9                                          /*!< USBD CEP_IRQ_ENB : ERR Position */
#define USBD_CEP_IRQ_ENB_ERR_Msk          (1ul << USBD_CEP_IRQ_ENB_ERR_Pos)          /*!< USBD CEP_IRQ_ENB : ERR Mask */

#define USBD_CEP_IRQ_ENB_STALL_Pos        8                                          /*!< USBD CEP_IRQ_ENB : STALL Position */
#define USBD_CEP_IRQ_ENB_STALL_Msk        (1ul << USBD_CEP_IRQ_ENB_STALL_Pos)        /*!< USBD CEP_IRQ_ENB : STALL Mask */

#define USBD_CEP_IRQ_ENB_NAK_Pos          7                                          /*!< USBD CEP_IRQ_ENB : NAK Position */
#define USBD_CEP_IRQ_ENB_NAK_Msk          (1ul << USBD_CEP_IRQ_ENB_NAK_Pos)          /*!< USBD CEP_IRQ_ENB : NAK Mask */

#define USBD_CEP_IRQ_ENB_DATA_RxED_Pos    6                                          /*!< USBD CEP_IRQ_ENB : DATA_RxED Position */
#define USBD_CEP_IRQ_ENB_DATA_RxED_Msk    (1ul << USBD_CEP_IRQ_ENB_DATA_RxED_Pos)    /*!< USBD CEP_IRQ_ENB : DATA_RxED Mask */

#define USBD_CEP_IRQ_ENB_DATA_TxED_Pos    5                                          /*!< USBD CEP_IRQ_ENB : DATA_TxED Position */
#define USBD_CEP_IRQ_ENB_DATA_TxED_Msk    (1ul << USBD_CEP_IRQ_ENB_DATA_TxED_Pos)    /*!< USBD CEP_IRQ_ENB : DATA_TxED Mask */

#define USBD_CEP_IRQ_ENB_PING_Pos         4                                          /*!< USBD CEP_IRQ_ENB : PING Position */
#define USBD_CEP_IRQ_ENB_PING_Msk         (1ul << USBD_CEP_IRQ_ENB_PING_Pos)         /*!< USBD CEP_IRQ_ENB : PING Mask */

#define USBD_CEP_IRQ_ENB_IN_TK_Pos        3                                          /*!< USBD CEP_IRQ_ENB : IN_TK Position */
#define USBD_CEP_IRQ_ENB_IN_TK_Msk        (1ul << USBD_CEP_IRQ_ENB_IN_TK_Pos)        /*!< USBD CEP_IRQ_ENB : IN_TK Mask */

#define USBD_CEP_IRQ_ENB_OUT_TK_Pos       2                                          /*!< USBD CEP_IRQ_ENB : OUT_TK Position */
#define USBD_CEP_IRQ_ENB_OUT_TK_Msk       (1ul << USBD_CEP_IRQ_ENB_OUT_TK_Pos)       /*!< USBD CEP_IRQ_ENB : OUT_TK Mask */

#define USBD_CEP_IRQ_ENB_SETUP_PK_Pos     1                                          /*!< USBD CEP_IRQ_ENB : SETUP_PK Position */
#define USBD_CEP_IRQ_ENB_SETUP_PK_Msk     (1ul << USBD_CEP_IRQ_ENB_SETUP_PK_Pos)     /*!< USBD CEP_IRQ_ENB : SETUP_PK Mask */

#define USBD_CEP_IRQ_ENB_SETUP_TK_Pos     0                                          /*!< USBD CEP_IRQ_ENB : SETUP_TK Position */
#define USBD_CEP_IRQ_ENB_SETUP_TK_Msk     (1ul << USBD_CEP_IRQ_ENB_SETUP_TK_Pos)     /*!< USBD CEP_IRQ_ENB : SETUP_TK Mask */

/* USBD CEP_IRQ_STAT Bit Field Definitions */
#define USBD_CEP_IRQ_STAT_EMPTY_Pos       12                                         /*!< USBD CEP_IRQ_STAT : EMPTY Position */
#define USBD_CEP_IRQ_STAT_EMPTY_Msk       (1ul << USBD_CEP_IRQ_STAT_EMPTY_Pos)       /*!< USBD CEP_IRQ_STAT : EMPTY Mask */

#define USBD_CEP_IRQ_STAT_FULL_Pos        11                                         /*!< USBD CEP_IRQ_STAT : FULL Position */
#define USBD_CEP_IRQ_STAT_FULL_Msk        (1ul << USBD_CEP_IRQ_STAT_FULL_Pos)        /*!< USBD CEP_IRQ_STAT : FULL Mask */

#define USBD_CEP_IRQ_STAT_STACOM_Pos      10                                         /*!< USBD CEP_IRQ_STAT : STACOM Position */
#define USBD_CEP_IRQ_STAT_STACOM_Msk      (1ul << USBD_CEP_IRQ_STAT_STACOM_Pos)      /*!< USBD CEP_IRQ_STAT : STACOM Mask */

#define USBD_CEP_IRQ_STAT_ERR_Pos         9                                          /*!< USBD CEP_IRQ_STAT : ERR Position */
#define USBD_CEP_IRQ_STAT_ERR_Msk         (1ul << USBD_CEP_IRQ_STAT_ERR_Pos)         /*!< USBD CEP_IRQ_STAT : ERR Mask */

#define USBD_CEP_IRQ_STAT_STALL_Pos       8                                          /*!< USBD CEP_IRQ_STAT : STALL Position */
#define USBD_CEP_IRQ_STAT_STALL_Msk       (1ul << USBD_CEP_IRQ_STAT_STALL_Pos)       /*!< USBD CEP_IRQ_STAT : STALL Mask */

#define USBD_CEP_IRQ_STAT_NAK_Pos         7                                          /*!< USBD CEP_IRQ_STAT : NAK Position */
#define USBD_CEP_IRQ_STAT_NAK_Msk         (1ul << USBD_CEP_IRQ_STAT_NAK_Pos)         /*!< USBD CEP_IRQ_STAT : NAK Mask */

#define USBD_CEP_IRQ_STAT_DATA_RxED_Pos   6                                          /*!< USBD CEP_IRQ_STAT : DATA_RxED Position */
#define USBD_CEP_IRQ_STAT_DATA_RxED_Msk   (1ul << USBD_CEP_IRQ_STAT_DATA_RxED_Pos)   /*!< USBD CEP_IRQ_STAT : DATA_RxED Mask */

#define USBD_CEP_IRQ_STAT_DATA_TxED_Pos   5                                          /*!< USBD CEP_IRQ_STAT : DATA_TxED Position */
#define USBD_CEP_IRQ_STAT_DATA_TxED_Msk   (1ul << USBD_CEP_IRQ_STAT_DATA_TxED_Pos)   /*!< USBD CEP_IRQ_STAT : DATA_TxED Mask */

#define USBD_CEP_IRQ_STAT_PING_Pos        4                                          /*!< USBD CEP_IRQ_STAT : PING Position */
#define USBD_CEP_IRQ_STAT_PING_Msk        (1ul << USBD_CEP_IRQ_STAT_PING_Pos)        /*!< USBD CEP_IRQ_STAT : PING Mask */

#define USBD_CEP_IRQ_STAT_IN_TK_Pos       3                                          /*!< USBD CEP_IRQ_STAT : IN_TK Position */
#define USBD_CEP_IRQ_STAT_IN_TK_Msk       (1ul << USBD_CEP_IRQ_STAT_IN_TK_Pos)       /*!< USBD CEP_IRQ_STAT : IN_TK Mask */

#define USBD_CEP_IRQ_STAT_OUT_TK_Pos      2                                          /*!< USBD CEP_IRQ_STAT : OUT_TK Position */
#define USBD_CEP_IRQ_STAT_OUT_TK_Msk      (1ul << USBD_CEP_IRQ_STAT_OUT_TK_Pos)      /*!< USBD CEP_IRQ_STAT : OUT_TK Mask */

#define USBD_CEP_IRQ_STAT_SETUP_PK_Pos    1                                          /*!< USBD CEP_IRQ_STAT : SETUP_PK Position */
#define USBD_CEP_IRQ_STAT_SETUP_PK_Msk    (1ul << USBD_CEP_IRQ_STAT_SETUP_PK_Pos)    /*!< USBD CEP_IRQ_STAT : SETUP_PK Mask */

#define USBD_CEP_IRQ_STAT_SETUP_TK_Pos    0                                          /*!< USBD CEP_IRQ_STAT : SETUP_TK Position */
#define USBD_CEP_IRQ_STAT_SETUP_TK_Msk    (1ul << USBD_CEP_IRQ_STAT_SETUP_TK_Pos)    /*!< USBD CEP_IRQ_ENB : SETUP_TK Mask */

/* USBD IN_TRF_CNT Bit Field Definitions */
#define USBD_IN_TRF_CNT_Pos               0                                          /*!< USBD IN_TRF_CNT : IN_TRF_CNT Position */
#define USBD_IN_TRF_CNT_Msk               (0XFFul << USBD_IN_TRF_CNT_Pos)            /*!< USBD IN_TRF_CNT : IN_TRF_CNT Mask */

/* USBD OUT_TRF_CNT Bit Field Definitions */
#define USBD_OUT_TRF_CNT_Pos              0                                          /*!< USBD OUT_TRF_CNT : OUT_TRF_CNT Position */
#define USBD_OUT_TRF_CNT_Msk              (0XFFFFul << USBD_OUT_TRF_CNT_Pos)         /*!< USBD OUT_TRF_CNT : OUT_TRF_CNT Mask */

/* USBD CEP_CNT Bit Field Definitions */
#define USBD_CEP_CNT_Pos                  0                                          /*!< USBD CEP_CNT : CEP_CNT Position */
#define USBD_CEP_CNT_Msk                  (0XFFFFul << USBD_CEP_CNT_Pos)             /*!< USBD CEP_CNT : CEP_CNT Mask */

/* USBD SETUP1_0 Bit Field Definitions */
#define USBD_SETUP1_0_SETUP1_Pos          8                                          /*!< USBD SETUP1_0 : SETUP1 Position */
#define USBD_SETUP1_0_SETUP1_Msk          (0XFFul << USBD_SETUP1_0_SETUP1_Pos)       /*!< USBD SETUP1_0 : SETUP1 Mask */

#define USBD_SETUP1_0_SETUP0_Pos          0                                          /*!< USBD SETUP1_0 : SETUP0 Position */
#define USBD_SETUP1_0_SETUP0_Msk          (0XFFul << USBD_SETUP1_0_SETUP0_Pos)       /*!< USBD SETUP1_0 : SETUP0 Mask */

/* USBD SETUP3_2 Bit Field Definitions */
#define USBD_SETUP3_2_SETUP3_Pos          8                                          /*!< USBD SETUP3_2 : SETUP3 Position */
#define USBD_SETUP3_2_SETUP3_Msk          (0XFFul << USBD_SETUP3_2_SETUP3_Pos)       /*!< USBD SETUP3_2 : SETUP3 Mask */

#define USBD_SETUP3_2_SETUP2_Pos          0                                          /*!< USBD SETUP3_2 : SETUP2 Position */
#define USBD_SETUP3_2_SETUP2_Msk          (0XFFul << USBD_SETUP3_2_SETUP2_Pos)       /*!< USBD SETUP3_2 : SETUP2 Mask */

/* USBD SETUP5_4 Bit Field Definitions */
#define USBD_SETUP5_4_SETUP5_Pos          8                                          /*!< USBD SETUP5_4 : SETUP5 Position */
#define USBD_SETUP5_4_SETUP5_Msk          (0XFFul << USBD_SETUP5_4_SETUP5_Pos)       /*!< USBD SETUP5_4 : SETUP5 Mask */

#define USBD_SETUP5_4_SETUP4_Pos          0                                          /*!< USBD SETUP5_4 : SETUP4 Position */
#define USBD_SETUP5_4_SETUP4_Msk          (0XFFul << USBD_SETUP5_4_SETUP4_Pos)       /*!< USBD SETUP5_4 : SETUP4 Mask */

/* USBD SETUP7_6 Bit Field Definitions */
#define USBD_SETUP7_6_SETUP7_Pos          8                                          /*!< USBD SETUP7_6 : SETUP7 Position */
#define USBD_SETUP7_6_SETUP7_Msk          (0XFFul << USBD_SETUP7_6_SETUP7_Pos)       /*!< USBD SETUP7_6 : SETUP7 Mask */

#define USBD_SETUP7_6_SETUP6_Pos          0                                          /*!< USBD SETUP7_6 : SETUP6 Position */
#define USBD_SETUP7_6_SETUP6_Msk          (0XFFul << USBD_SETUP7_6_SETUP6_Pos)       /*!< USBD SETUP7_6 : SETUP6 Mask */

/* USBD CEP_START_ADDR Bit Field Definitions */
#define USBD_CEP_START_ADDR_Pos           0                                          /*!< USBD CEP_START_ADDR : CEP_START_ADDR Position */
#define USBD_CEP_START_ADDR_Msk           (0X7FFul << USBD_CEP_START_ADDR_Pos)       /*!< USBD CEP_START_ADDR : CEP_START_ADDR Mask */

/* USBD CEP_END_ADDR Bit Field Definitions */
#define USBD_CEP_END_ADDR_Pos             0                                          /*!< USBD CEP_END_ADDR : CEP_END_ADDR Position */
#define USBD_CEP_END_ADDR_Msk             (0X7FFul << USBD_CEP_END_ADDR_Pos)         /*!< USBD CEP_END_ADDR : CEP_END_ADDR Mask */

/* USBD DMA_CTRL_STS Bit Field Definitions */
#define USBD_DMA_CTRL_STS_RST_DMA_Pos     7                                          /*!< USBD DMA_CTRL_STS : RST_DMA Position */
#define USBD_DMA_CTRL_STS_RST_DMA_Msk     (1ul << USBD_DMA_CTRL_STS_RST_DMA_Pos)     /*!< USBD DMA_CTRL_STS : RST_DMA Mask */

#define USBD_DMA_CTRL_STS_SCAT_GA_EN_Pos  6                                          /*!< USBD DMA_CTRL_STS : SCAT_GA_EN Position */
#define USBD_DMA_CTRL_STS_SCAT_GA_EN_Msk  (1ul << USBD_DMA_CTRL_STS_SCAT_GA_EN_Pos)  /*!< USBD DMA_CTRL_STS : SCAT_GA_EN Mask */

#define USBD_DMA_CTRL_STS_DMA_EN_Pos      5                                          /*!< USBD DMA_CTRL_STS : DMA_EN Position */
#define USBD_DMA_CTRL_STS_DMA_EN_Msk      (1ul << USBD_DMA_CTRL_STS_DMA_EN_Pos)      /*!< USBD DMA_CTRL_STS : DMA_EN Mask */

#define USBD_DMA_CTRL_STS_DMA_RD_Pos      4                                          /*!< USBD DMA_CTRL_STS : DMA_RD Position */
#define USBD_DMA_CTRL_STS_DMA_RD_Msk      (1ul << USBD_DMA_CTRL_STS_DMA_RD_Pos)      /*!< USBD DMA_CTRL_STS : DMA_RD Mask */

#define USBD_DMA_CTRL_STS_DMA_ADDR_Pos    0                                          /*!< USBD DMA_CTRL_STS : DMA_ADDR Position */
#define USBD_DMA_CTRL_STS_DMA_ADDR_Msk    (0xFul << USBD_DMA_CTRL_STS_DMA_ADDR_Pos)  /*!< USBD DMA_CTRL_STS : DMA_ADDR Mask */

/* USBD DMA_CNT Bit Field Definitions */
#define USBD_DMA_CNT_Pos                  0                                          /*!< USBD DMA_CNT : DMA_CNT Position */
#define USBD_DMA_CNT_Msk                  (0XFFFFFul << USBD_DMA_CNT_Pos)            /*!< USBD DMA_CNT : DMA_CNT Mask */

/* USBD EPx_DATA_BUF Bit Field Definitions */
#define USBD_EP_DATA_BUF_Pos              0                                          /*!< USBD EPx_DATA_BUF : EP_DATA_BUF Position */
#define USBD_EP_DATA_BUF_Msk              (0XFFFFFFFFul << USBD_EPx_DATA_BUF_Pos)    /*!< USBD EPx_DATA_BUF : EP_DATA_BUF Mask */

/* USBD EPx_IRQ_STAT Bit Field Definitions */
#define USBD_EP_IRQ_STAT_O_SHORT_PKT_Pos  12                                         /*!< USBD EPx_IRQ_STAT : O_SHORT_PKT Position */
#define USBD_EP_IRQ_STAT_O_SHORT_PKT_Msk  (1ul << USBD_EP_IRQ_STAT_O_SHORT_PKT_Pos)  /*!< USBD EPx_IRQ_STAT : O_SHORT_PKT Mask */

#define USBD_EP_IRQ_STAT_ERR_Pos          11                                         /*!< USBD EPx_IRQ_STAT : ERR Position */
#define USBD_EP_IRQ_STAT_ERR_Msk          (1ul << USBD_EP_IRQ_STAT_ERR_Pos)          /*!< USBD EPx_IRQ_STAT : ERR Mask */

#define USBD_EP_IRQ_STAT_NYET_Pos         10                                         /*!< USBD EPx_IRQ_STAT : NYET Position */
#define USBD_EP_IRQ_STAT_NYET_Msk         (1ul << USBD_EP_IRQ_STAT_NYET_Pos)         /*!< USBD EPx_IRQ_STAT : NYET Mask */

#define USBD_EP_IRQ_STAT_STALL_Pos        9                                          /*!< USBD EPx_IRQ_STAT : STALL Position */
#define USBD_EP_IRQ_STAT_STALL_Msk        (1ul << USBD_EP_IRQ_STAT_STALL_Pos)        /*!< USBD EPx_IRQ_STAT : STALL Mask */

#define USBD_EP_IRQ_STAT_NAK_Pos          8                                          /*!< USBD EPx_IRQ_STAT : NAK Position */
#define USBD_EP_IRQ_STAT_NAK_Msk          (1ul << USBD_EP_IRQ_STAT_NAK_Pos)          /*!< USBD EPx_IRQ_STAT : NAK Mask */

#define USBD_EP_IRQ_STAT_PING_Pos         7                                          /*!< USBD EPx_IRQ_STAT : PING Position */
#define USBD_EP_IRQ_STAT_PING_Msk         (1ul << USBD_EP_IRQ_STAT_PING_Pos)         /*!< USBD EPx_IRQ_STAT : PING Mask */

#define USBD_EP_IRQ_STAT_IN_TK_Pos        6                                          /*!< USBD EPx_IRQ_STAT : IN_TK Position */
#define USBD_EP_IRQ_STAT_IN_TK_Msk        (1ul << USBD_EP_IRQ_STAT_IN_TK_Pos)        /*!< USBD EPx_IRQ_STAT : IN_TK Mask */

#define USBD_EP_IRQ_STAT_OUT_TK_Pos       5                                          /*!< USBD EPx_IRQ_STAT : OUT_TK Position */
#define USBD_EP_IRQ_STAT_OUT_TK_Msk       (1ul << USBD_EP_IRQ_STAT_OUT_TK_Pos)       /*!< USBD EPx_IRQ_STAT : OUT_TK Mask */

#define USBD_EP_IRQ_STAT_DATA_RxED_Pos    4                                          /*!< USBD EPx_IRQ_STAT : DATA_RxED Position */
#define USBD_EP_IRQ_STAT_DATA_RxED_Msk    (1ul << USBD_EP_IRQ_STAT_DATA_RxED_Pos)    /*!< USBD EPx_IRQ_STAT : DATA_RxED Mask */

#define USBD_EP_IRQ_STAT_DATA_TxED_Pos    3                                          /*!< USBD EPx_IRQ_STAT : DATA_TxED Position */
#define USBD_EP_IRQ_STAT_DATA_TxED_Msk    (1ul << USBD_EP_IRQ_STAT_DATA_TxED_Pos)    /*!< USBD EPx_IRQ_STAT : DATA_TxED Mask */

#define USBD_EP_IRQ_STAT_SHORT_PKT_Pos    2                                          /*!< USBD EPx_IRQ_STAT : SHORT_PKT Position */
#define USBD_EP_IRQ_STAT_SHORT_PKT_Msk    (1ul << USBD_EP_IRQ_STAT_SHORT_PKT_Pos)    /*!< USBD EPx_IRQ_STAT : SHORT_PKT Mask */

#define USBD_EP_IRQ_STAT_EMPTY_Pos        1                                          /*!< USBD EPx_IRQ_STAT : EMPTY Position */
#define USBD_EP_IRQ_STAT_EMPTY_Msk        (1ul << USBD_EP_IRQ_STAT_EMPTY_Pos)        /*!< USBD EPx_IRQ_STAT : EMPTY Mask */

#define USBD_EP_IRQ_STAT_FULL_Pos         0                                          /*!< USBD EPx_IRQ_STAT : FULL Position */
#define USBD_EP_IRQ_STAT_FULL_Msk         (1ul << USBD_EP_IRQ_STAT_FULL_Pos)         /*!< USBD EPx_IRQ_STAT : FULL Mask */

/* USBD EPx_IRQ_ENB Bit Field Definitions */
#define USBD_EP_IRQ_ENB_O_SHORT_PKT_Pos   12                                         /*!< USBD EPx_IRQ_ENB : O_SHORT_PKT Position */
#define USBD_EP_IRQ_ENB_O_SHORT_PKT_Msk   (1ul << USBD_EP_IRQ_ENB_O_SHORT_PKT_Pos)   /*!< USBD EPx_IRQ_ENB : O_SHORT_PKT Mask */

#define USBD_EP_IRQ_ENB_ERR_Pos           11                                         /*!< USBD EPx_IRQ_ENB : ERR Position */
#define USBD_EP_IRQ_ENB_ERR_Msk           (1ul << USBD_EP_IRQ_ENB_ERR_Pos)           /*!< USBD EPx_IRQ_ENB : ERR Mask */

#define USBD_EP_IRQ_ENB_NYET_Pos          10                                         /*!< USBD EPx_IRQ_ENB : NYET Position */
#define USBD_EP_IRQ_ENB_NYET_Msk          (1ul << USBD_EP_IRQ_ENB_NYET_Pos)          /*!< USBD EPx_IRQ_ENB : NYET Mask */

#define USBD_EP_IRQ_ENB_STALL_Pos         9                                          /*!< USBD EPx_IRQ_ENB : STALL Position */
#define USBD_EP_IRQ_ENB_STALL_Msk         (1ul << USBD_EP_IRQ_ENB_STALL_Pos)         /*!< USBD EPx_IRQ_ENB : STALL Mask */

#define USBD_EP_IRQ_ENB_NAK_Pos           8                                          /*!< USBD EPx_IRQ_ENB : NAK Position */
#define USBD_EP_IRQ_ENB_NAK_Msk           (1ul << USBD_EP_IRQ_ENB_NAK_Pos)           /*!< USBD EPx_IRQ_ENB : NAK Mask */

#define USBD_EP_IRQ_ENB_PING_Pos          7                                          /*!< USBD EPx_IRQ_ENB : PING Position */
#define USBD_EP_IRQ_ENB_PING_Msk          (1ul << USBD_EP_IRQ_ENB_PING_Pos)          /*!< USBD EPx_IRQ_ENB : PING Mask */

#define USBD_EP_IRQ_ENB_IN_TK_Pos         6                                          /*!< USBD EPx_IRQ_ENB : IN_TK Position */
#define USBD_EP_IRQ_ENB_IN_TK_Msk         (1ul << USBD_EP_IRQ_ENB_IN_TK_Pos)         /*!< USBD EPx_IRQ_ENB : IN_TK Mask */

#define USBD_EP_IRQ_ENB_OUT_TK_Pos        5                                          /*!< USBD EPx_IRQ_ENB : OUT_TK Position */
#define USBD_EP_IRQ_ENB_OUT_TK_Msk        (1ul << USBD_EP_IRQ_ENB_OUT_TK_Pos)        /*!< USBD EPx_IRQ_ENB : OUT_TK Mask */

#define USBD_EP_IRQ_ENB_DATA_RxED_Pos     4                                          /*!< USBD EPx_IRQ_ENB : DATA_RxED Position */
#define USBD_EP_IRQ_ENB_DATA_RxED_Msk     (1ul << USBD_EP_IRQ_ENB_DATA_RxED_Pos)     /*!< USBD EPx_IRQ_ENB : DATA_RxED Mask */

#define USBD_EP_IRQ_ENB_DATA_TxED_Pos     3                                          /*!< USBD EPx_IRQ_ENB : DATA_TxED Position */
#define USBD_EP_IRQ_ENB_DATA_TxED_Msk     (1ul << USBD_EP_IRQ_ENB_DATA_TxED_Pos)     /*!< USBD EPx_IRQ_ENB : DATA_TxED Mask */

#define USBD_EP_IRQ_ENB_SHORT_PKT_Pos     2                                          /*!< USBD EPx_IRQ_ENB : SHORT_PKT Position */
#define USBD_EP_IRQ_ENB_SHORT_PKT_Msk     (1ul << USBD_EP_IRQ_ENB_SHORT_PKT_Pos)     /*!< USBD EPx_IRQ_ENB : SHORT_PKT Mask */

#define USBD_EP_IRQ_ENB_EMPTY_Pos         1                                          /*!< USBD EPx_IRQ_ENB : EMPTY Position */
#define USBD_EP_IRQ_ENB_EMPTY_Msk         (1ul << USBD_EP_IRQ_ENB_EMPTY_Pos)         /*!< USBD EPx_IRQ_ENB : EMPTY Mask */

#define USBD_EP_IRQ_ENB_FULL_Pos          0                                          /*!< USBD EPx_IRQ_ENB : FULL Position */
#define USBD_EP_IRQ_ENB_FULL_Msk          (1ul << USBD_EP_IRQ_ENB_FULL_Pos)          /*!< USBD EPx_IRQ_ENB : FULL Mask */

/* USBD EPx_DATA_CNT Bit Field Definitions */
#define USBD_EP_DATA_CNT_DMA_LOOP_Pos     16                                           /*!< USBD EPx_DATA_CNT : DMA_LOOP Position */
#define USBD_EP_DATA_CNT_DMA_LOOP_Msk     (0X7FFFul << USBD_EP_DATA_CNT_DMA_LOOP_Pos)  /*!< USBD EPx_DATA_CNT : DMA_LOOP Mask */

#define USBD_EP_DATA_CNT_DATA_CNT_Pos     0                                            /*!< USBD EPx_DATA_CNT : DATA_CNT Position */
#define USBD_EP_DATA_CNT_DATA_CNT_Msk     (0XFFFFul << USBD_EP_DATA_CNT_DATA_CNT_Pos)  /*!< USBD EPx_DATA_CNT : DATA_CNT Mask */

/* USBD EPx_RSP_SC Bit Field Definitions */
#define USBD_EP_RSP_SC_DIS_BUF_Pos        7                                          /*!< USBD EPx_RSP_SC : DIS_BUF Position */
#define USBD_EP_RSP_SC_DIS_BUF_Msk        (1ul << USBD_EP_RSP_SC_DIS_BUF_Pos)        /*!< USBD EPx_RSP_SC : DIS_BUF Mask */

#define USBD_EP_RSP_SC_PK_END_Pos         6                                          /*!< USBD EPx_RSP_SC : PK_END Position */
#define USBD_EP_RSP_SC_PK_END_Msk         (1ul << USBD_EP_RSP_SC_PK_END_Pos)         /*!< USBD EPx_RSP_SC : PK_END Mask */

#define USBD_EP_RSP_SC_ZEROLEN_Pos        5                                          /*!< USBD EPx_RSP_SC : ZEROLEN Position */
#define USBD_EP_RSP_SC_ZEROLEN_Msk        (1ul << USBD_EP_RSP_SC_ZEROLEN_Pos)        /*!< USBD EPx_RSP_SC : ZEROLEN Mask */

#define USBD_EP_RSP_SC_HALT_Pos           4                                          /*!< USBD EPx_RSP_SC : HALT Position */
#define USBD_EP_RSP_SC_HALT_Msk           (1ul << USBD_EP_RSP_SC_HALT_Pos)           /*!< USBD EPx_RSP_SC : HALT Mask */

#define USBD_EP_RSP_SC_TOGGLE_Pos         3                                          /*!< USBD EPx_RSP_SC : TOGGLE Position */
#define USBD_EP_RSP_SC_TOGGLE_Msk         (1ul << USBD_EP_RSP_SC_TOGGLE_Pos)         /*!< USBD EPx_RSP_SC : TOGGLE Mask */

#define USBD_EP_RSP_SC_MODE_Pos           1                                          /*!< USBD EPx_RSP_SC : MODE Position */
#define USBD_EP_RSP_SC_MODE_Msk           (3ul << USBD_EP_RSP_SC_MODE_Pos)           /*!< USBD EPx_RSP_SC : MODE Mask */

#define USBD_EP_RSP_SC_BUF_FLUSH_Pos      0                                          /*!< USBD EPx_RSP_SC : BUF_FLUSH Position */
#define USBD_EP_RSP_SC_BUF_FLUSH_Msk      (1ul << USBD_EP_RSP_SC_BUF_FLUSH_Pos)      /*!< USBD EPx_RSP_SC : BUF_FLUSH Mask */

/* USBD EPx_MPS Bit Field Definitions */
#define USBD_EP_MPS_Pos                   0                                          /*!< USBD EPx_MPS : MPS Position */
#define USBD_EP_MPS_Msk                   (0X7FFul << USBD_EP_MPS_Pos)               /*!< USBD EPx_MPS : MPS Mask */

/* USBD EPx_TRF_CNT Bit Field Definitions */
#define USBD_EP_TRF_CNT_Pos               0                                          /*!< USBD EPx_TRF_CNT : TRF_CNT Position */
#define USBD_EP_TRF_CNT_Msk               (0X7FFul << USBD_EP_TRF_CNT_Pos)           /*!< USBD EPx_TRF_CNT : TRF_CNT Mask */

/* USBD EPx_CFG Bit Field Definitions */
#define USBD_EP_CFG_EP_MULT_Pos           8                                          /*!< USBD EPx_CFG : EP_MULT Position */
#define USBD_EP_CFG_EP_MULT_Msk           (3ul << USBD_EP_CFG_EP_MULT_Pos)           /*!< USBD EPx_CFG : EP_MULT Mask */

#define USBD_EP_CFG_EP_NUM_Pos            4                                          /*!< USBD EPx_CFG : EP_NUM Position */
#define USBD_EP_CFG_EP_NUM_Msk            (0xFul << USBD_EP_CFG_EP_NUM_Pos)          /*!< USBD EPx_CFG : EP_NUM Mask */

#define USBD_EP_CFG_EP_DIR_Pos            3                                          /*!< USBD EPx_CFG : EP_DIR Position */
#define USBD_EP_CFG_EP_DIR_Msk            (1ul << USBD_EP_CFG_EP_DIR_Pos)            /*!< USBD EPx_CFG : EP_DIR Mask */

#define USBD_EP_CFG_EP_TYPE_Pos           1                                          /*!< USBD EPx_CFG : EP_TYPE Position */
#define USBD_EP_CFG_EP_TYPE_Msk           (3ul << USBD_EP_CFG_EP_TYPE_Pos)           /*!< USBD EPx_CFG : EP_TYPE Mask */

#define USBD_EP_CFG_EP_VALID_Pos          0                                          /*!< USBD EPx_CFG : EP_VALID Position */
#define USBD_EP_CFG_EP_VALID_Msk          (1ul << USBD_EP_CFG_EP_VALID_Pos)          /*!< USBD EPx_CFG : EP_VALID Mask */

/* USBD EPx_START_ADDR Bit Field Definitions */
#define USBD_EP_START_ADDR_Pos            0                                          /*!< USBD EPx_START_ADDR : START_ADDR Position */
#define USBD_EP_START_ADDR_Msk            (0X7FFul << USBD_EP_START_ADDR_Pos)        /*!< USBD EPx_START_ADDR : START_ADDR Mask */

/* USBD EPx_END_ADDR Bit Field Definitions */
#define USBD_EP_END_ADDR_Pos              0                                          /*!< USBD EPx_END_ADDR : END_ADDR Position */
#define USBD_EP_END_ADDR_Msk              (0X7FFul << USBD_EP_END_ADDR_Pos)          /*!< USBD EPx_END_ADDR : END_ADDR Mask */

/* USBD HEAD_WORDx Bit Field Definitions */
#define USBD_HEAD_WORD_Pos                0                                          /*!< USBD HEAD_WORDx : HEAD_WORDx Position */
#define USBD_HEAD_WORD_Msk                (0XFFFFFFFFul << USBD_HEAD_WORD_Pos)       /*!< USBD HEAD_WORDx : HEAD_WORDx Mask */

/* USBD EPx_HEAD_CNT Bit Field Definitions */
#define USBD_EP_HEAD_CNT_Pos              0                                          /*!< USBD EPx_HEAD_CNT : HEAD_CNT Position */
#define USBD_EP_HEAD_CNT_Msk              (0X7FFul << USBD_EP_HEAD_CNT_Pos)          /*!< USBD EPx_HEAD_CNT : HEAD_CNT Mask */

/* USBD AHB_DMA_ADDR Bit Field Definitions */
#define USBD_AHB_DMA_ADDR_Pos             0                                          /*!< USBD AHB_DMA_ADDR : AHB_DMA_ADDR Position */
#define USBD_AHB_DMA_ADDR_Msk             (0XFFFFFFFFul << USBD_AHB_DMA_ADDR_Pos)    /*!< USBD AHB_DMA_ADDR : AHB_DMA_ADDR Mask */

/* USBD PHY_CTL Bit Field Definitions */
#define USBD_PHY_CTL_VBUS_STATUS_Pos      31                                         /*!< USBD PHY_CTL : VBUS_STATUS Position */
#define USBD_PHY_CTL_VBUS_STATUS_Msk      (1ul << USBD_PHY_CTL_VBUS_STATUS_Pos)      /*!< USBD PHY_CTL : VBUS_STATUS Mask */

#define USBD_PHY_CTL_PHY_SUSPEND_Pos      9                                          /*!< USBD PHY_CTL : PHY_SUSPEND Position */
#define USBD_PHY_CTL_PHY_SUSPEND_Msk      (1ul << USBD_PHY_CTL_PHY_SUSPEND_Pos)      /*!< USBD PHY_CTL : PHY_SUSPEND Mask */

#define USBD_PHY_CTL_DP_PULLUP_Pos        8                                          /*!< USBD PHY_CTL : DP_PULLUP Position */
#define USBD_PHY_CTL_DP_PULLUP_Msk        (1ul << USBD_PHY_CTL_DP_PULLUP_Pos)        /*!< USBD PHY_CTL : DP_PULLUP Mask */

/*@}*/ /* end of group NUC400_USBD */


/*------------- USB OTG Control Register (OTG) -----------------------------*/
/** @addtogroup NUC400_OTG NUC400 USB OTG Control Register (OTG)
  @{
*/
typedef struct {
    __IO uint32_t CTL;                           /*!< Offset: 0x0000   OTG Control Register */
    __IO uint32_t PHYCTL;                        /*!< Offset: 0x0004   OTG Phy Control Register */
    __IO uint32_t IER;                           /*!< Offset: 0x0008   Interrupt Enable Register */
    __IO uint32_t ISR;                           /*!< Offset: 0x000C   Interrupt Status Register */
    __I  uint32_t STS;                           /*!< Offset: 0x0010   Status Register */

} OTG_T;

/* OTG CTL Bit Field Definitions */
#define OTG_CTL_WAKE_EN_Pos            8                                      /*!< OTG OTG_CTL : WK_EN Position */
#define OTG_CTL_WAKE_EN_Msk            (1ul << OTG_CTL_WAKE_EN_Pos)           /*!< OTG OTG_CTL : WK_EN Mask */

#define OTG_CTL_UDC_CLK_ON_Pos         7                                      /*!< OTG OTG_CTL : UDC_CLK_ON Position */
#define OTG_CTL_UDC_CLK_ON_Msk         (1ul << OTG_CTL_UDC_CLK_ON_Pos)        /*!< OTG OTG_CTL : UDC_CLK_ON Mask */

#define OTG_CTL_FORCE_A_IDLE_Pos       5                                      /*!< OTG OTG_CTL : FORCE_A_IDLE Position */
#define OTG_CTL_FORCE_A_IDLE_Msk       (1ul << OTG_CTL_FORCE_A_IDLE_Pos)      /*!< OTG OTG_CTL : FORCE_A_IDLE Mask */

#define OTG_CTL_OTG_ST_EN_Pos          4                                      /*!< OTG OTG_CTL : OTG_ST_EN Position */
#define OTG_CTL_OTG_ST_EN_Msk          (1ul << OTG_CTL_WAKE_EN_Pos)           /*!< OTG OTG_CTL : OTG_ST_EN Mask */

#define OTG_CTL_SRP_COMPLIANT_Pos      3                                      /*!< OTG OTG_CTL : SRP_COMPLIANT Position */
#define OTG_CTL_SRP_COMPLIANT_Msk      (1ul << OTG_CTL_SRP_COMPLIANT_Pos)     /*!< OTG OTG_CTL : SRP_COMPLIANT Mask */

#define OTG_CTL_B_HNP_ENREQ_Pos        2                                      /*!< OTG OTG_CTL : B_HNP_ENREQ Position */
#define OTG_CTL_B_HNP_ENREQ_Msk        (1ul << OTG_CTL_B_HNP_ENREQ_Pos)       /*!< OTG OTG_CTL : B_HNP_ENREQ Mask */

#define OTG_CTL_BUS_REQ_Pos            1                                      /*!< OTG OTG_CTL : BUS_REQ Position */
#define OTG_CTL_BUS_REQ_Msk            (1ul << OTG_CTL_BUS_REQ_Pos)           /*!< OTG OTG_CTL : BUS_REQ Mask */

#define OTG_CTL_VBUS_DROP_Pos          0                                      /*!< OTG OTG_CTL : VBUS_DROP Position */
#define OTG_CTL_VBUS_DROP_Msk          (1ul << OTG_CTL_VBUS_DROP_Pos)         /*!< OTG OTG_CTL : VBUS_DROP Mask */

/* OTG PHYCTL Bit Field Definitions */
#define OTG_PHYCTL_OTG_SUS_Pos         9                                      /*!< OTG OTG_PHYCTL : OTG_SUS Position */
#define OTG_PHYCTL_OTG_SUS_Msk         (1ul << OTG_PHYCTL_OTG_SUS_Pos)        /*!< OTG OTG_PHYCTL : OTG_SUS Mask */

#define OTG_PHYCTL_PHYCLK_S_Pos        8                                      /*!< OTG OTG_PHYCTL : PHYCLK_S Position */
#define OTG_PHYCTL_PHYCLK_S_Msk        (1ul << OTG_PHYCTL_PHYCLK_S_Pos)       /*!< OTG OTG_PHYCTL : PHYCLK_S Mask */

#define OTG_PHYCTL_ID_PU_EN_Pos        7                                      /*!< OTG OTG_PHYCTL : ID_PU_EN Position */
#define OTG_PHYCTL_ID_PU_EN_Msk        (1ul << OTG_PHYCTL_ID_PU_EN_Pos)       /*!< OTG OTG_PHYCTL : ID_PU_EN Mask */

#define OTG_PHYCTL_EN_VBUS_INV_Pos     6                                      /*!< OTG OTG_PHYCTL : EN_VBUS_INV Position */
#define OTG_PHYCTL_EN_VBUS_INV_Msk     (1ul << OTG_PHYCTL_EN_VBUS_INV_Pos)    /*!< OTG OTG_PHYCTL : EN_VBUS_INV Mask */

#define OTG_PHYCTL_BUS_VALID_INV_Pos   5                                      /*!< OTG OTG_PHYCTL : BUS_VALID_INV Position */
#define OTG_PHYCTL_BUS_VALID_INV_Msk   (1ul << OTG_PHYCTL_BUS_VALID_INV_Pos)  /*!< OTG OTG_PHYCTL : BUS_VALID_INV Mask */

#define OTG_PHYCTL_VBUS_VALID_SEL_Pos  3                                      /*!< OTG OTG_PHYCTL : VBUS_VALID_SEL Position */
#define OTG_PHYCTL_VBUS_VALID_SEL_Msk  (3ul << OTG_PHYCTL_VBUS_VALID_SEL_Pos) /*!< OTG OTG_PHYCTL : VBUS_VALID_SEL Mask */

#define OTG_PHYCTL_DMPD_EN_Pos         2                                      /*!< OTG OTG_PHYCTL : DMPD_EN Position */
#define OTG_PHYCTL_DMPD_EN_Msk         (1ul << OTG_PHYCTL_DMPD_EN_Pos)        /*!< OTG OTG_PHYCTL : DMPD_EN Mask */

#define OTG_PHYCTL_DPPD_EN_Pos         1                                      /*!< OTG OTG_PHYCTL : DPPD_EN Position */
#define OTG_PHYCTL_DPPD_EN_Msk         (1ul << OTG_PHYCTL_DPPD_EN_Pos)        /*!< OTG OTG_PHYCTL : DPPD_EN Mask */

#define OTG_PHYCTL_SPD_EN_Pos          0                                      /*!< OTG OTG_PHYCTL : SPD_EN Position */
#define OTG_PHYCTL_SPD_EN_Msk          (1ul << OTG_PHYCTL_SPD_EN_Pos)         /*!< OTG OTG_PHYCTL : SPD_EN Mask */

/* OTG IER Bit Field Definitions */
#define OTG_IER_SRP_DET_Pos            13                                     /*!< OTG OTG_IER : SRP_DET Position */
#define OTG_IER_SRP_DET_Msk            (1ul << OTG_IER_SRP_DET_Pos)           /*!< OTG OTG_IER : SRP_DET Mask */

#define OTG_IER_SRP_PWERR_IE_Pos       12                                     /*!< OTG OTG_IER : SRP_PWERR_IE Position */
#define OTG_IER_SRP_PWERR_IE_Msk       (1ul << OTG_IER_SRP_PWERR_IE_Pos)      /*!< OTG OTG_IER : SRP_PWERR_IE Mask */

#define OTG_IER_SESS_END_IE_Pos        11                                     /*!< OTG OTG_IER : SESS_END_IE Position */
#define OTG_IER_SESS_END_IE_Msk        (1ul << OTG_IER_SESS_END_IE_Pos)       /*!< OTG OTG_IER : SESS_END_IE Mask */

#define OTG_IER_VBUS_VALID_IE_Pos      10                                     /*!< OTG OTG_IER : VBUS_VALID_IE Position */
#define OTG_IER_VBUS_VALID_IE_Msk      (1ul << OTG_IER_VBUS_VALID_IE_Pos)     /*!< OTG OTG_IER : VBUS_VALID_IE Mask */

#define OTG_IER_A_VALID_IE_Pos         9                                      /*!< OTG OTG_IER : A_VALID_IE Position */
#define OTG_IER_A_VALID_IE_Msk         (1ul << OTG_IER_A_VALID_IE_Pos)        /*!< OTG OTG_IER : A_VALID_IE Mask */

#define OTG_IER_B_VALID_IE_Pos         8                                      /*!< OTG OTG_IER : B_VALID_IE Position */
#define OTG_IER_B_VALID_IE_Msk         (1ul << OTG_IER_B_VALID_IE_Pos)        /*!< OTG OTG_IER : B_VALID_IE Mask */

#define OTG_IER_ACT_AS_HOST_IE_Pos     7                                      /*!< OTG OTG_IER : ACT_AS_HOST_IE Position */
#define OTG_IER_ACT_AS_HOST_IE_Msk     (1ul << OTG_IER_ACT_AS_HOST_IE_Pos)    /*!< OTG OTG_IER : ACT_AS_HOST_IE Mask */

#define OTG_IER_ACT_AS_PERI_IE_Pos     6                                      /*!< OTG OTG_IER : ACT_AS_PERI_IE Position */
#define OTG_IER_ACT_AS_PERI_IE_Msk     (1ul << OTG_IER_ACT_AS_PERI_IE_Pos)    /*!< OTG OTG_IER : ACT_AS_PERI_IE Mask */

#define OTG_IER_IDDIG_IE_Pos           5                                      /*!< OTG OTG_IER : IDDIG_IE Position */
#define OTG_IER_IDDIG_IE_Msk           (1ul << OTG_IER_IDDIG_IE_Pos)          /*!< OTG OTG_IER : IDDIG_IE Mask */

#define OTG_IER_GO_IDLE_IE_Pos         4                                      /*!< OTG OTG_IER : GO_IDLE_IE Position */
#define OTG_IER_GO_IDLE_IE_Msk         (1ul << OTG_IER_GO_IDLE_IE_Pos)        /*!< OTG OTG_IER : GO_IDLE_IE Mask */

#define OTG_IER_HNP_FAIL_IE_Pos        3                                      /*!< OTG OTG_IER : HNP_FAIL_IE Position */
#define OTG_IER_HNP_FAIL_IE_Msk        (1ul << OTG_IER_HNP_FAIL_IE_Pos)       /*!< OTG OTG_IER : HNP_FAIL_IE Mask */

#define OTG_IER_SRP_FAIL_IE_Pos        2                                      /*!< OTG OTG_IER : SRP_FAIL_IE Position */
#define OTG_IER_SRP_FAIL_IE_Msk        (1ul << OTG_IER_SRP_FAIL_IE_Pos)       /*!< OTG OTG_IER : SRP_FAIL_IE Mask */

#define OTG_IER_VBUS_ERR_IE_Pos        1                                      /*!< OTG OTG_IER : VBUS_ERR_IE Position */
#define OTG_IER_VBUS_ERR_IE_Msk        (1ul << OTG_IER_VBUS_ERR_IE_Pos)       /*!< OTG OTG_IER : VBUS_ERR_IE Mask */

#define OTG_IER_ROLE_CHG_IE_Pos        0                                      /*!< OTG OTG_IER : ROLE_CHG_IE Position */
#define OTG_IER_ROLE_CHG_IE_Msk        (1ul << OTG_IER_ROLE_CHG_IE_Pos)       /*!< OTG OTG_IER : ROLE_CHG_IE Mask */

/* OTG ISR Bit Field Definitions */
#define OTG_ISR_SRP_DET_Pos            13                                     /*!< OTG OTG_ISR : SRP_DET Position */
#define OTG_ISR_SRP_DET_Msk            (1ul << OTG_ISR_SRP_DET_Pos)           /*!< OTG OTG_ISR : SRP_DET Mask */

#define OTG_ISR_SRP_PWERR_IS_Pos       12                                     /*!< OTG OTG_ISR : SRP_PWERR_IS Position */
#define OTG_ISR_SRP_PWERR_IS_Msk       (1ul << OTG_ISR_SRP_PWERR_IS_Pos)      /*!< OTG OTG_ISR : SRP_PWERR_IS Mask */

#define OTG_ISR_SESS_END_IS_Pos        11                                     /*!< OTG OTG_ISR : SESS_END_IS Position */
#define OTG_ISR_SESS_END_IS_Msk        (1ul << OTG_ISR_SESS_END_IS_Pos)       /*!< OTG OTG_ISR : SESS_END_IS Mask */

#define OTG_ISR_VBUS_VALID_IS_Pos      10                                     /*!< OTG OTG_ISR : VBUS_VALID_IS Position */
#define OTG_ISR_VBUS_VALID_IS_Msk      (1ul << OTG_ISR_VBUS_VALID_IS_Pos)     /*!< OTG OTG_ISR : VBUS_VALID_IS Mask */

#define OTG_ISR_A_VALID_IS_Pos         9                                      /*!< OTG OTG_ISR : A_VALID_IS Position */
#define OTG_ISR_A_VALID_IS_Msk         (1ul << OTG_ISR_A_VALID_IS_Pos)        /*!< OTG OTG_ISR : A_VALID_IS Mask */

#define OTG_ISR_B_VALID_IS_Pos         8                                      /*!< OTG OTG_ISR : B_VALID_IS Position */
#define OTG_ISR_B_VALID_IS_Msk         (1ul << OTG_ISR_B_VALID_IS_Pos)        /*!< OTG OTG_ISR : B_VALID_IS Mask */

#define OTG_ISR_ACT_AS_HOST_IS_Pos     7                                      /*!< OTG OTG_ISR : ACT_AS_HOST_IS Position */
#define OTG_ISR_ACT_AS_HOST_IS_Msk     (1ul << OTG_ISR_ACT_AS_HOST_IS_Pos)    /*!< OTG OTG_ISR : ACT_AS_HOST_IS Mask */

#define OTG_ISR_ACT_AS_PERI_IS_Pos     6                                      /*!< OTG OTG_ISR : ACT_AS_PERI_IS Position */
#define OTG_ISR_ACT_AS_PERI_IS_Msk     (1ul << OTG_ISR_ACT_AS_PERI_IS_Pos)    /*!< OTG OTG_ISR : ACT_AS_PERI_IS Mask */

#define OTG_ISR_IDDIG_IS_Pos           5                                      /*!< OTG OTG_ISR : IDDIG_IS Position */
#define OTG_ISR_IDDIG_IS_Msk           (1ul << OTG_ISR_IDDIG_IS_Pos)          /*!< OTG OTG_ISR : IDDIG_IS Mask */

#define OTG_ISR_GO_IDLE_IS_Pos         4                                      /*!< OTG OTG_ISR : GO_IDLE_IS Position */
#define OTG_ISR_GO_IDLE_IS_Msk         (1ul << OTG_ISR_GO_IDLE_IS_Pos)        /*!< OTG OTG_ISR : GO_IDLE_IS Mask */

#define OTG_ISR_HNP_FAIL_IS_Pos        3                                      /*!< OTG OTG_ISR : HNP_FAIL_IS Position */
#define OTG_ISR_HNP_FAIL_IS_Msk        (1ul << OTG_ISR_HNP_FAIL_IS_Pos)       /*!< OTG OTG_ISR : HNP_FAIL_IS Mask */

#define OTG_ISR_SRP_FAIL_IS_Pos        2                                      /*!< OTG OTG_ISR : SRP_FAIL_IS Position */
#define OTG_ISR_SRP_FAIL_IS_Msk        (1ul << OTG_ISR_SRP_FAIL_IS_Pos)       /*!< OTG OTG_ISR : SRP_FAIL_IS Mask */

#define OTG_ISR_VBUS_ERR_IS_Pos        1                                      /*!< OTG OTG_ISR : VBUS_ERR_IS Position */
#define OTG_ISR_VBUS_ERR_IS_Msk        (1ul << OTG_ISR_VBUS_ERR_IS_Pos)       /*!< OTG OTG_ISR : VBUS_ERR_IS Mask */

#define OTG_ISR_ROLE_CHG_IS_Pos        0                                      /*!< OTG OTG_ISR : ROLE_CHG_IS Position */
#define OTG_ISR_ROLE_CHG_IS_Msk        (1ul << OTG_ISR_ROLE_CHG_IS_Pos)       /*!< OTG OTG_ISR : ROLE_CHG_IS Mask */

/* OTG STS Bit Field Definitions */
#define OTG_STS_VBUS_VALID_Pos         5                                      /*!< OTG OTG_STS : VBUS_VALID Position */
#define OTG_STS_VBUS_VALID_Msk         (1ul << OTG_STS_VBUS_VALID_Pos)        /*!< OTG OTG_STS : VBUS_VALID Mask */

#define OTG_STS_B_VALID_Pos            4                                      /*!< OTG OTG_STS : B_VALID Position */
#define OTG_STS_B_VALID_Msk            (1ul << OTG_STS_B_VALID_Pos)           /*!< OTG OTG_STS : B_VALID Mask */

#define OTG_STS_A_VALID_Pos            3                                      /*!< OTG OTG_STS : A_VALID Position */
#define OTG_STS_A_VALID_Msk            (1ul << OTG_STS_A_VALID_Pos)           /*!< OTG OTG_STS : A_VALID Mask */

#define OTG_STS_SESS_END_Pos           2                                      /*!< OTG OTG_STS : SESS_END Position */
#define OTG_STS_SESS_END_Msk           (1ul << OTG_STS_SESS_END_Pos)          /*!< OTG OTG_STS : SESS_END Mask */

#define OTG_STS_IDDIG_Pos              1                                      /*!< OTG OTG_STS : IDDIG Position */
#define OTG_STS_IDDIG_Msk              (1ul << OTG_STS_IDDIG_Pos)             /*!< OTG OTG_STS : IDDIG Mask */

#define OTG_STS_VRISE_FAIL_Pos         0                                      /*!< OTG OTG_STS : VRISE_FAIL Position */
#define OTG_STS_VRISE_FAIL_Msk         (1ul << OTG_STS_VRISE_FAIL_Pos)        /*!< OTG OTG_STS : VRISE_FAIL Mask */


/*@}*/ /* end of group NUC400_OTG */


/*------------- Timer Control Register (TIMER) -----------------------------*/
/** @addtogroup NUC400_TIMER NUC400 TIMER Control Register (TIMER)
  @{
*/
/**
  * @brief Timer register map
  */
typedef struct {
    __IO uint32_t TCSR;                     /*!< Offset: 0x0000   Timer Control and Status Register                 */
    __IO uint32_t TCMPR;                    /*!< Offset: 0x0004   Timer Compare Register                            */
    __IO uint32_t TISR;                     /*!< Offset: 0x0008   Timer Interrupt Status Register                   */
    __I  uint32_t TDR;                      /*!< Offset: 0x000C   Timer Data Register                               */
    __I  uint32_t TCAP;                     /*!< Offset: 0x0010   Timer Capture Data Register                       */
    __IO uint32_t TEXCON;                   /*!< Offset: 0x0014   Timer External Control Register                   */
    __IO uint32_t TEXISR;                   /*!< Offset: 0x0018   Timer External Interrupt Status Register          */
} TIMER_T;

/* TIMER TCSR Bit Field Definitions */
#define TIMER_TCSR_DBGACK_TMR_Pos   31                                            /*!< TIMER TCSR: DBGACK_TMR Position */
#define TIMER_TCSR_DBGACK_TMR_Msk   (1ul << TIMER_TCSR_DBGACK_TMR_Pos)            /*!< TIMER TCSR: DBGACK_TMR Mask     */

#define TIMER_TCSR_CEN_Pos          30                                            /*!< TIMER TCSR: CEN Position */
#define TIMER_TCSR_CEN_Msk          (1ul << TIMER_TCSR_CEN_Pos)                   /*!< TIMER TCSR: CEN Mask     */

#define TIMER_TCSR_IE_Pos           29                                            /*!< TIMER TCSR: IE Position */
#define TIMER_TCSR_IE_Msk           (1ul << TIMER_TCSR_IE_Pos)                    /*!< TIMER TCSR: IE Mask     */

#define TIMER_TCSR_MODE_Pos         27                                            /*!< TIMER TCSR: MODE Position */
#define TIMER_TCSR_MODE_Msk         (0x3ul << TIMER_TCSR_MODE_Pos)                /*!< TIMER TCSR: MODE Mask     */

#define TIMER_TCSR_CRST_Pos         26                                            /*!< TIMER TCSR: CRST Position */
#define TIMER_TCSR_CRST_Msk         (1ul << TIMER_TCSR_CRST_Pos)                  /*!< TIMER TCSR: CRST Mask     */

#define TIMER_TCSR_CACT_Pos         25                                            /*!< TIMER TCSR: CACT Position */
#define TIMER_TCSR_CACT_Msk         (1ul << TIMER_TCSR_CACT_Pos)                  /*!< TIMER TCSR: CACT Mask     */

#define TIMER_TCSR_CTB_Pos          24                                            /*!< TIMER TCSR: CTB Position */
#define TIMER_TCSR_CTB_Msk          (1ul << TIMER_TCSR_CTB_Pos)                   /*!< TIMER TCSR: CTB Mask     */

#define TIMER_TCSR_WAKE_EN_Pos      23                                            /*!< TIMER TCSR: WAKE_EN Position */
#define TIMER_TCSR_WAKE_EN_Msk      (1ul << TIMER_TCSR_WAKE_EN_Pos)               /*!< TIMER TCSR: WAKE_EN Mask     */

#define TIMER_TCSR_OFFTOUT_2_Pos    22                                            /*!< TIMER TCSR: OFFTOUT_2 Position */
#define TIMER_TCSR_OFFTOUT_2_Msk    (1ul << TIMER_TCSR_OFFTOUT_2_Pos)             /*!< TIMER TCSR: OFFTOUT_2 Mask     */

#define TIMER_TCSR_OFFTOUT_1_Pos    21                                            /*!< TIMER TCSR: OFFTOUT_1 Position */
#define TIMER_TCSR_OFFTOUT_1_Msk    (1ul << TIMER_TCSR_OFFTOUT_1_Pos)             /*!< TIMER TCSR: OFFTOUT_1 Mask     */

#define TIMER_TCSR_TDR_EN_Pos       16                                            /*!< TIMER TCSR: TDR_EN Position */
#define TIMER_TCSR_TDR_EN_Msk       (1ul << TIMER_TCSR_TDR_EN_Pos)                /*!< TIMER TCSR: TDR_EN Mask     */

#define TIMER_TCSR_PRESCALE_Pos     0                                             /*!< TIMER TCSR: PRESCALE Position */
#define TIMER_TCSR_PRESCALE_Msk     (0xFFul << TIMER_TCSR_PRESCALE_Pos)           /*!< TIMER TCSR: PRESCALE Mask     */

/* TIMER TCMPR Bit Field Definitions */
#define TIMER_TCMP_TCMP_Pos         0                                             /*!< TIMER TCMPR: TCMP Position */
#define TIMER_TCMP_TCMP_Msk         (0xFFFFFFul << TIMER_TCMP_TCMP_Pos)           /*!< TIMER TCMPR: TCMP Mask     */

/* TIMER TISR Bit Field Definitions */
#define TIMER_TISR_TWF_Pos          1                                            /*!< TIMER TISR: TWF Position */
#define TIMER_TISR_TWF_Msk          (1ul << TIMER_TISR_TWF_Pos)                  /*!< TIMER TISR: TWF Mask     */

#define TIMER_TISR_TIF_Pos          0                                            /*!< TIMER TISR: TIF Position */
#define TIMER_TISR_TIF_Msk          (1ul << TIMER_TISR_TIF_Pos)                  /*!< TIMER TISR: TIF Mask     */

/* TIMER TDR Bit Field Definitions */
#define TIMER_TDR_TDR_Pos           0                                            /*!< TIMER TDR: TDR Position */
#define TIMER_TDR_TDR_Msk           (0xFFFFFFul << TIMER_TDR_TDR_Pos)            /*!< TIMER TDR: TDR Mask     */

/* TIMER TCAP Bit Field Definitions */
#define TIMER_TCAP_TCAP_Pos         0                                            /*!< TIMER TCAP: TCAP Position */
#define TIMER_TCAP_TCAP_Msk         (0xFFFFFFul << TIMER_TCAP_TCAP_Pos)          /*!< TIMER TCAP: TCAP Mask     */

/* TIMER TEXCON Bit Field Definitions */
#define TIMER_TEXCON_TCDB_Pos       7                                            /*!< TIMER TEXCON: TCDB Position */
#define TIMER_TEXCON_TCDB_Msk       (1ul << TIMER_TEXCON_TCDB_Pos)               /*!< TIMER TEXCON: TCDB Mask     */

#define TIMER_TEXCON_TEXDB_Pos      6                                            /*!< TIMER TEXCON: TEXDB Position */
#define TIMER_TEXCON_TEXDB_Msk      (1ul << TIMER_TEXCON_TEXDB_Pos)              /*!< TIMER TEXCON: TEXDB Mask     */

#define TIMER_TEXCON_TEXIEN_Pos     5                                            /*!< TIMER TEXCON: TEXIEN Position */
#define TIMER_TEXCON_TEXIEN_Msk     (1ul << TIMER_TEXCON_TEXIEN_Pos)             /*!< TIMER TEXCON: TEXIEN Mask     */

#define TIMER_TEXCON_RSTCAPSEL_Pos  4                                            /*!< TIMER TEXCON: RSTCAPSEL Position */
#define TIMER_TEXCON_RSTCAPSEL_Msk  (1ul << TIMER_TEXCON_RSTCAPSEL_Pos)          /*!< TIMER TEXCON: RSTCAPSEL Mask     */

#define TIMER_TEXCON_TEXEN_Pos      3                                            /*!< TIMER TEXCON: TEXEN Position */
#define TIMER_TEXCON_TEXEN_Msk      (1ul << TIMER_TEXCON_TEXEN_Pos)              /*!< TIMER TEXCON: TEXEN Mask     */

#define TIMER_TEXCON_TEX_EDGE_Pos   1                                            /*!< TIMER TEXCON: TEX_EDGE Position */
#define TIMER_TEXCON_TEX_EDGE_Msk   (0x3ul << TIMER_TEXCON_TEX_EDGE_Pos)         /*!< TIMER TEXCON: TEX_EDGE Mask     */

#define TIMER_TEXCON_TX_PHASE_Pos   0                                            /*!< TIMER TEXCON: TX_PHASE Position */
#define TIMER_TEXCON_TX_PHASE_Msk   (1ul << TIMER_TEXCON_TX_PHASE_Pos)           /*!< TIMER TEXCON: TX_PHASE Mask     */

/* TIMER TEXISR Bit Field Definitions */
#define TIMER_TEXISR_TEXIF_Pos      0                                            /*!< TIMER TEXISR: TEXIF Position */
#define TIMER_TEXISR_TEXIF_Msk      (1ul << TIMER_TEXISR_TEXIF_Pos)              /*!< TIMER TEXISR: TEXIF Mask     */
/*@}*/ /* end of group NUC400_TIMER */

/*----------------------------- PWM Controller ----------------------------*/
/** @addtogroup NUC400_PWM NUC400 PWM Control Register (PWM)
  @{
*/
typedef struct {
    __IO uint32_t CPR;     /*!< Offset: 0x0000   PWM Clock Prescale Register    */
    __IO uint32_t CDR;     /*!< Offset: 0x0004   PWM Clock Divide Register    */
    __IO uint32_t CONR;    /*!< Offset: 0x0008   PWM Control Register    */
    __IO uint32_t CER;     /*!< Offset: 0x000C   PWM Counter Enable Control Register    */
    __IO uint32_t CNR0;    /*!< Offset: 0x0010   PWM Counter Register 0    */
    __IO uint32_t CNR1;    /*!< Offset: 0x0014   PWM Counter Register 1    */
    __IO uint32_t CNR2;    /*!< Offset: 0x0018   PWM Counter Register 2    */
    __IO uint32_t CNR3;    /*!< Offset: 0x001C   PWM Counter Register 3    */
    __IO uint32_t CNR4;    /*!< Offset: 0x0020   PWM Counter Register 4    */
    __IO uint32_t CNR5;    /*!< Offset: 0x0024   PWM Counter Register 5    */
    __IO uint32_t CMR0;    /*!< Offset: 0x0028   PWM Comparator Register 0    */
    __IO uint32_t CMR1;    /*!< Offset: 0x002C   PWM Comparator Register 1    */
    __IO uint32_t CMR2;    /*!< Offset: 0x0030   PWM Comparator Register 2    */
    __IO uint32_t CMR3;    /*!< Offset: 0x0034   PWM Comparator Register 3    */
    __IO uint32_t CMR4;    /*!< Offset: 0x0038   PWM Comparator Register 4    */
    __IO uint32_t CMR5;    /*!< Offset: 0x003C   PWM Comparator Register 5    */
    __IO uint32_t DR0;     /*!< Offset: 0x0040   PWM Data Register 0    */
    __IO uint32_t DR1;     /*!< Offset: 0x0044   PWM Data Register 1    */
    __IO uint32_t DR2;     /*!< Offset: 0x0048   PWM Data Register 2    */
    __IO uint32_t DR3;     /*!< Offset: 0x004C   PWM Data Register 3    */
    __IO uint32_t DR4;     /*!< Offset: 0x0050   PWM Data Register 4    */
    __IO uint32_t DR5;     /*!< Offset: 0x0054   PWM Data Register 5    */
    __IO uint32_t MCR;     /*!< Offset: 0x0058   PWM Mask Control Register */
    __IO uint32_t MDR;     /*!< Offset: 0x005C   PWM Mask Data Register    */
    __IO uint32_t DZCR;    /*!< Offset: 0x0060   PWM Dead-zone Control Register  */
    __IO uint32_t TCR;     /*!< Offset: 0x0064   PWM Trigger Control Register    */
    __IO uint32_t TIR;     /*!< Offset: 0x0068   PWM Trigger Indication Register */
    __IO uint32_t BCR;     /*!< Offset: 0x006C   PWM Brake Control Register      */
    __IO uint32_t ICR;     /*!< Offset: 0x0070   PWM Interrupt Control Register  */
    __IO uint32_t IER;     /*!< Offset: 0x0074   PWM Interrupt Enable Register   */
    __IO uint32_t IFR;     /*!< Offset: 0x0078   PWM Interrupt Flag Register     */
    __IO uint32_t OER;     /*!< Offset: 0x007C   PWM Output Enable Register      */
    __IO uint32_t CCR;     /*!< Offset: 0x0080   PWM Capture Control Register    */
    __IO uint32_t CINER;   /*!< Offset: 0x0084   PWM Capture Input Enable Register */
    __IO uint32_t CAPSR;   /*!< Offset: 0x0088   PWM Capture Status Register     */
    uint32_t RESERVED0;
    __IO uint32_t CRLR0;   /*!< Offset: 0x0090   PWM Capture Rising Latch Register (channel 0)  */
    __IO uint32_t CFLR0;   /*!< Offset: 0x0094   PWM Capture Falling Latch Register (channel 0) */
    __IO uint32_t CRLR1;   /*!< Offset: 0x0098   PWM Capture Rising Latch Register (channel 1)  */
    __IO uint32_t CFLR1;   /*!< Offset: 0x009C   PWM Capture Falling Latch Register (channel 1) */
    __IO uint32_t CRLR2;   /*!< Offset: 0x00A0   PWM Capture Rising Latch Register (channel 2)  */
    __IO uint32_t CFLR2;   /*!< Offset: 0x00A4   PWM Capture Falling Latch Register (channel 2) */
    __IO uint32_t CRLR3;   /*!< Offset: 0x00A8   PWM Capture Rising Latch Register (channel 3)  */
    __IO uint32_t CFLR3;   /*!< Offset: 0x00AC   PWM Capture Falling Latch Register (channel 3) */
    __IO uint32_t CRLR4;   /*!< Offset: 0x00B0   PWM Capture Rising Latch Register (channel 4)  */
    __IO uint32_t CFLR4;   /*!< Offset: 0x00B4   PWM Capture Falling Latch Register (channel 4) */
    __IO uint32_t CRLR5;   /*!< Offset: 0x00B8   PWM Capture Rising Latch Register (channel 5)  */
    __IO uint32_t CFLR5;   /*!< Offset: 0x00BC   PWM Capture Falling Latch Register (channel 5) */
    uint32_t RESERVED1[8];
    __IO uint32_t SBS0;    /*!< Offset: 0x00E0   PWM Synchronous Busy Status Register */
    __IO uint32_t SBS1;    /*!< Offset: 0x00E4   PWM Synchronous Busy Status Register */
    __IO uint32_t SBS2;    /*!< Offset: 0x00E8   PWM Synchronous Busy Status Register */
    __IO uint32_t SBS3;    /*!< Offset: 0x00EC   PWM Synchronous Busy Status Register */
    __IO uint32_t SBS4;    /*!< Offset: 0x00F0   PWM Synchronous Busy Status Register */
    __IO uint32_t SBS5;    /*!< Offset: 0x00F4   PWM Synchronous Busy Status Register */
    __IO uint32_t VER_NUM;
} PWM_T;


/* PWM_CPR Bit Field Definitions */
#define PWM_CPR_CBP01_Pos       0                                     /*!< PWM CPR: PWM Counter Base-clock Pre-scale for PWM Pair of Channel 0 and Channel 1 */
#define PWM_CPR_CBP01_Msk       (0xFFul << PWM_CPR_CBP01_Pos)         /*!< PWM CPR: CPR01 Mask */
#define PWM_CPR_CBP23_Pos       8                                     /*!< PWM CPR: PWM Counter Base-clock Pre-scale for PWM Pair of Channel 2 and Channel 3 */
#define PWM_CPR_CBP23_Msk       (0xFFul << PWM_CPR_CBP23_Pos)         /*!< PWM CPR: CPR23 Mask */
#define PWM_CPR_CBP45_Pos       16                                    /*!< PWM CPR: PWM Counter Base-clock Pre-scale for PWM Pair of Channel 4 and Channel 5 */
#define PWM_CPR_CBP45_Msk       (0xFFul << PWM_CPR_CBP45_Pos)        /*!< PWM CPR: CPR45 Mask */

/* PWM_CDR Bit Field Definitions */
#define PWM_CDR_CBD0_Pos        0                                     /*!< PWM CDR: PWM Counter Base-clock Divide for PWM0 */
#define PWM_CDR_CBD0_Msk        (0x7ul << PWM_CDR_CBD0_Pos)           /*!< PWM CDR: CBD0 Mask */
#define PWM_CDR_CBD1_Pos        4                                     /*!< PWM CDR: PWM Counter Base-clock Divide for PWM1 */
#define PWM_CDR_CBD1_Msk        (0x7ul << PWM_CDR_CBD1_Pos)           /*!< PWM CDR: CBD1 Mask */
#define PWM_CDR_CBD2_Pos        8                                     /*!< PWM CDR: PWM Counter Base-clock Divide for PWM2 */
#define PWM_CDR_CBD2_Msk        (0x7ul << PWM_CDR_CBD2_Pos)           /*!< PWM CDR: CBD2 Mask */
#define PWM_CDR_CBD3_Pos        12                                    /*!< PWM CDR: PWM Counter Base-clock Divide for PWM3 */
#define PWM_CDR_CBD3_Msk        (0x7ul << PWM_CDR_CBD2_Pos)           /*!< PWM CDR: CBD3 Mask */
#define PWM_CDR_CBD4_Pos        16                                    /*!< PWM CDR: PWM Counter Base-clock Divide for PWM4 */
#define PWM_CDR_CBD4_Msk        (0x7ul << PWM_CDR_CBD2_Pos)           /*!< PWM CDR: CBD4 Mask */
#define PWM_CDR_CBD5_Pos        20                                    /*!< PWM CDR: PWM Counter Base-clock Divide for PWM5 */
#define PWM_CDR_CBD5_Msk        (0x7ul << PWM_CDR_CBD2_Pos)           /*!< PWM CDR: CBD5 Mask */

/* PWM_CONR Bit Field Definitions */
#define PWM_CONR_CMPINV_Pos     0                                     /*!< PWM CONR: PWM Comparator Output Inverter Enable */
#define PWM_CONR_CMPINV_Msk     (0x3Ful << PWM_CONR_CMPINV_Pos)       /*!< PWM CONR: CMPINV Mask */
#define PWM_CONR_OUTMD_Pos      6                                     /*!< PWM CONR: PWM Output Mode */
#define PWM_CONR_OUTMD_Msk      (0x1ul << PWM_CONR_OUTMD_Pos)         /*!< PWM CONR: OUTMD Mask */
#define PWM_CONR_GRP_EN_Pos     7                                     /*!< PWM CONR: Group Mode Enable */
#define PWM_CONR_GRP_EN_Msk     (0x1ul << PWM_CONR_GRP_EN_Pos)        /*!< PWM CONR: GRP_EN Mask */
#define PWM_CONR_PINV_Pos       8                                     /*!< PWM CONR: PWM Output Polar Inverse Enable */
#define PWM_CONR_PINV_Msk       (0x3Ful << PWM_CONR_PINV_Pos)         /*!< PWM CONR: PINV Mask */
#define PWM_CONR_SYNC_EN_Pos    15                                    /*!< PWM CONR: Synchronous Mode Enable */
#define PWM_CONR_SYNC_EN_Msk    (0x1ul << PWM_CONR_SYNC_EN_Pos)       /*!< PWM CONR: SYNC_EN Mask */
#define PWM_CONR_CNTMODE_Pos    16                                    /*!< PWM CONR: PWM Counter Operation Mode */
#define PWM_CONR_CNTMODE_Msk    (0x3Ful << PWM_CONR_CNTMODE_Pos)      /*!< PWM CONR: CNTMODE Mask */
#define PWM_CONR_CNTTYPE_Pos    24                                    /*!< PWM CONR: PWM Counter Operation Aligned Type */
#define PWM_CONR_CNTTYPE_Msk    (0x3Ful << PWM_CONR_CNTTYPE_Pos)      /*!< PWM CONR: CNTTYPE Mask */
#define PWM_CONR_SELFTEST_Pos 30                                    /*!< PWM CONR: Self Test Enable  */
#define PWM_CONR_SELFTEST_Msk (0x1ul << PWM_CONR_SELFTEST_Pos)    /*!< PWM CONR: SelfTest Mask */
#define PWM_CONR_DBGACK_PWM_Pos 31                                    /*!< PWM CONR: ICE debug mode acknowledge Disable  */
#define PWM_CONR_DBGACK_PWM_Msk (0x1ul << PWM_CONR_DBGACK_PWM_Pos)    /*!< PWM CONR: DBGACK_PWM Mask */

/* PWM_DZCR Bit Field Definitions */
#define PWM_DZCR_DZI01_Pos      0                                     /*!< PWM CONR: Dead-zone Interval for PWM Pair of Channel 0 and Channel 1 */
#define PWM_DZCR_DZI01_Msk      (0xFFul << PWM_DZCR_DZI01_Pos)        /*!< PWM CONR: DZI01 Mask */
#define PWM_DZCR_DZI23_Pos      8                                     /*!< PWM CONR: Dead-zone Interval for PWM Pair of Channel 2 and Channel 3 */
#define PWM_DZCR_DZI23_Msk      (0xFFul << PWM_DZCR_DZI23_Pos)        /*!< PWM CONR: DZI23 Mask */
#define PWM_DZCR_DZI45_Pos      16                                    /*!< PWM CONR: Dead-zone Interval for PWM Pair of Channel 4 and Channel 5 */
#define PWM_DZCR_DZI45_Msk      (0xFFul << PWM_DZCR_DZI45_Pos)        /*!< PWM CONR: DZI45 Mask */
#define PWM_DZCR_ZDDIV_Pos      24                                    /*!< Dead-zone Generator Divider */
#define PWM_DZCR_ZDDIV_Msk      (0x3ul << PWM_DZCR_ZDDIV_Pos)         /*!< PWM CONR: ZDDIV Mask */
#define PWM_DZCR_DZEN01_Pos     28                                    /*!< Dead-zone Enable for PWM Pair of Channel 0 and Channel 1 */
#define PWM_DZCR_DZEN01_Msk     (0x1ul << PWM_DZCR_DZEN01_Pos)        /*!< PWM CONR: DZEN01 Mask */
#define PWM_DZCR_DZEN23_Pos     29                                    /*!< Dead-zone Enable for PWM Pair of Channel 2 and Channel 3 */
#define PWM_DZCR_DZEN23_Msk     (0x1ul << PWM_DZCR_DZEN01_Pos)        /*!< PWM CONR: DZEN23 Mask */
#define PWM_DZCR_DZEN45_Pos     30                                    /*!< Dead-zone Enable for PWM Pair of Channel 4 and Channel 5 */
#define PWM_DZCR_DZEN45_Msk     (0x1ul << PWM_DZCR_DZEN01_Pos)        /*!< PWM CONR: DZEN45 Mask */

/* PWM_TCR Bit Field Definitions */
#define PWM_TCR_PTRG_EN_Pos     0                                     /*!< PWM TCR: PWM Period Point Trigger Enable */
#define PWM_TCR_PTRG_EN_Msk     (0x3Ful << PWM_TCR_PTRG_EN_Pos)       /*!< PWM TCR: PTRG_EN Mask */
#define PWM_TCR_CTRG_EN_Pos     8                                     /*!< PWM TCR: PWM Center Point Trigger Enable */
#define PWM_TCR_CTRG_EN_Msk     (0x3Ful << PWM_TCR_CTRG_EN_Pos)       /*!< PWM TCR: CTRG_EN Mask */
#define PWM_TCR_FETRG_EN_Pos    16                                    /*!< PWM TCR: PWM Falling Edge Point Trigger Enable */
#define PWM_TCR_FETRG_EN_Msk    (0x3Ful << PWM_TCR_CFETRG_EN_Pos)     /*!< PWM TCR: FETRG_EN Mask */
#define PWM_TCR_RETRG_EN_Pos    24                                    /*!< PWM TCR: PWM Rising Edge Point Trigger Enable */
#define PWM_TCR_RETRG_EN_Msk    (0x3Ful << PWM_TCR_CFETRG_EN_Pos)     /*!< PWM TCR: RETRG_EN Mask */

/* PWM_TIR Bit Field Definitions */
#define PWM_TIR_PTRGI_Pos       0                                     /*!< PWM TIR: PWM Period Point Trigger Indicator */
#define PWM_TIR_PTRGI_Msk       (0x3Ful << PWM_TIR_PTRGI_EN_Pos)      /*!< PWM TIR: PTRGI Mask */
#define PWM_TIR_CTRGI_Pos       8                                     /*!< PWM TIR: PWM Center Point Trigger Indicator */
#define PWM_TIR_CTRGI_Msk       (0x3Ful << PWM_TCR_CTRG_EN_Pos)       /*!< PWM TIR: CTRGI Mask */
#define PWM_TIR_FETRGI_Pos      16                                    /*!< PWM TIR: PWM Falling Edge Point Trigger Indicator */
#define PWM_TIR_FETRGI_Msk      (0x3Ful << PWM_TCR_CFETRG_EN_Pos)     /*!< PWM TIR: FETRGI Mask */
#define PWM_TIR_RETRGI_Pos      24                                    /*!< PWM TIR: PWM Rising Edge Point Trigger Indicator */
#define PWM_TIR_RETRGI_Msk      (0x3Ful << PWM_TCR_CFETRG_EN_Pos)     /*!< PWM TIR: RETRGI Mask */

/* PWM_BCR Bit Field Definitions */
#define PWM_BCR_BK0EN_Pos       0                                     /*!< PWM BCR: Brake0 Function Enable */
#define PWM_BCR_BK0EN_Msk       (0x1ul << PWM_BCR_BK0EN_Pos)          /*!< PWM BCR: BK0EN Mask */
#define PWM_BCR_BK0NF_DIS_Pos   1                                     /*!< PWM BCR: PWM Brake 0 Noise Filter Disable */
#define PWM_BCR_BK0NF_DIS_Msk   (0x1ul << PWM_BCR_BK0NF_DIS_Pos)      /*!< PWM BCR: BK0NF_DIS Mask */
#define PWM_BCR_BK0PINV_Pos     2                                     /*!< PWM BCR: Inverse BKP0 State */
#define PWM_BCR_BK0PINV_Msk     (0x1ul << PWM_BCR_BK0PINV_Pos)        /*!< PWM BCR: BK0PINV Mask */
#define PWM_BCR_BK0FSEL_Pos     6                                     /*!< PWM BCR: Brake 0 (BKPx0 pin) Edge Detector Filter Clock Selection */
#define PWM_BCR_BK0FSEL_Msk     (0x3ul << PWM_BCR_BK0FSEL_Pos)        /*!< PWM BCR: BK0FSEL Mask */
#define PWM_BCR_BK1EN_Pos       8                                     /*!< PWM BCR: Brake1 Function Enable */
#define PWM_BCR_BK1EN_Msk       (0x1ul << PWM_BCR_BK1EN_Pos)          /*!< PWM BCR: BK1EN Mask */
#define PWM_BCR_BK1NF_DIS_Pos   9                                     /*!< PWM BCR: PWM Brake 1 Noise Filter Disable */
#define PWM_BCR_BK1NF_DIS_Msk   (0x1ul << PWM_BCR_BK1NF_DIS_Pos)      /*!< PWM BCR: BK1NF_DIS Mask */
#define PWM_BCR_BK1PINV_Pos     10                                    /*!< PWM BCR: Inverse BKP1 State */
#define PWM_BCR_BK1PINV_Msk     (0x1ul << PWM_BCR_BK1PINV_Pos)        /*!< PWM BCR: BK1PINV Mask */
#define PWM_BCR_BK1SEL_Pos      12                                    /*!< PWM BCR: Brake Function 1 Source Selection */
#define PWM_BCR_BK1SEL_Msk      (0x3ul << PWM_BCR_BK1SEL_Pos)         /*!< PWM BCR: BK1SEL Mask */
#define PWM_BCR_BK1FSEL_Pos     14                                    /*!< PWM BCR: Brake 1 (BKPx1 pin) Edge Detector Filter Clock Selection */
#define PWM_BCR_BK1FSEL_Msk     (0x3ul << PWM_BCR_BK1FSEL_Pos)        /*!< PWM BCR: BK1FSEL Mask */
#define PWM_BCR_CPO0BKEN_Pos    16                                    /*!< PWM BCR: Enable CPO0 Digital Output as Brake0 Source */
#define PWM_BCR_CPO0BKEN_Msk    (0x1ul << PWM_BCR_CPO0BKEN_Pos)       /*!< PWM BCR: CPO0BKEN Mask */
#define PWM_BCR_CPO1BKEN_Pos    17                                    /*!< PWM BCR: Enable CPO1 Digital Output as Brake0 Source */
#define PWM_BCR_CPO1BKEN_Msk    (0x1ul << PWM_BCR_CPO1BKEN_Pos)       /*!< PWM BCR: CPO1BKEN Mask */
#define PWM_BCR_CPO2BKEN_Pos    18                                    /*!< PWM BCR: Enable CPO2 Digital Output as Brake0 Source */
#define PWM_BCR_CPO2BKEN_Msk    (0x1ul << PWM_BCR_CPO2BKEN_Pos)       /*!< PWM BCR: CPO2BKEN Mask */
#define PWM_BCR_LVDBKEN_Pos     19                                    /*!< PWM BCR: Low-level Detection Trigger PWM Brake Function 1 Enable */
#define PWM_BCR_LVDBKEN_Msk     (0x1ul << PWM_BCR_LVDBKEN_Pos)        /*!< PWM BCR: LVDBKEN Mask */
#define PWM_BCR_BKOD_Pos        24                                    /*!< PWM BCR: PWM Brake Output Data Register */
#define PWM_BCR_BKOD_Msk        (0x3Ful << PWM_BCR_BKOD_Pos)          /*!< PWM BCR: BKOD Mask */

/* PWM_ICR Bit Field Definitions */
#define PWM_ICR_PINTTYPE_Pos    0                                     /*!< PWM ICR: PWM Period Interrupt Type Selection */
#define PWM_ICR_PINTTYPE_Msk    (0x3Ful << PWM_IER_PINTTYPE_Pos)      /*!< PWM ICR: PINTTYPE Mask */
#define PWM_ICR_DINTTYPE_Pos    8                                     /*!< PWM ICR: PWM Duty Interrupt Type Selection */
#define PWM_ICR_DINTTYPE_Msk    (0x3Ful << PWM_IER_DINTTYPE_Pos)      /*!< PWM ICR: DINTTYPE Mask */

/* PWM_IER Bit Field Definitions */
#define PWM_IER_PPIE_Pos        0                                     /*!< PWM IER: PWM Period Interrupt Enable */
#define PWM_IER_PPIE_Msk        (0x3Ful << PWM_IER_PPIE_Pos)          /*!< PWM IER: PPIE Mask */
#define PWM_IER_BRKIE_Pos       6                                     /*!< PWM IER: Brake0 and Brake1 Interrupt Enable */
#define PWM_IER_BRKIE_Msk       (0x1ul << PWM_IER_PPIE_Pos)           /*!< PWM IER: BRKIE Mask */
#define PWM_IER_PDIE_Pos        8                                     /*!< PWM IER: PWM Duty Interrupt Enable */
#define PWM_IER_PDIE_Msk        (0x3Ful << PWM_IER_PDIE_Pos)          /*!< PWM IER: PDIE Mask */
#define PWM_IER_RLIE_Pos        16                                    /*!< PWM IER: Rising Latch Interrupt Enable */
#define PWM_IER_RLIE_Msk        (0x3Ful << PWM_IER_RLIE_Pos)          /*!< PWM IER: RLIE Mask */
#define PWM_IER_FLIE_Pos        24                                    /*!< PWM IER: Falling Latch Interrupt Enable */
#define PWM_IER_FLIE_Msk        (0x3Ful << PWM_IER_FLIE_Pos)          /*!< PWM IER: FLIE Mask */

/* PWM_IFR Bit Field Definitions */
#define PWM_IFR_PPIF_Pos        0                                     /*!< PWM IFR: PWM Period Interrupt Flag */
#define PWM_IFR_PPIF_Msk        (0x3Ful << PWM_IFR_PPIF_Pos)          /*!< PWM IFR: PPIF Mask */
#define PWM_IFR_BKIF0_Pos       6                                     /*!< PWM IFR: PWM Brake0 Flag */
#define PWM_IFR_BKIF0_Msk       (0x1ul << PWM_IFR_BKIF0_Pos)          /*!< PWM IFR: BKIF0 Mask */
#define PWM_IFR_BKIF1_Pos       7                                     /*!< PWM IFR: PWM Brake1 Flag*/
#define PWM_IFR_BKIF1_Msk       (0x1ul << PWM_IFR_BKIF1_Pos)          /*!< PWM IFR: BKIF1 Mask */
#define PWM_IFR_PDIF_Pos        8                                     /*!< PWM IFR: PWM Duty Interrupt Flag */
#define PWM_IFR_PDIF_Msk        (0x3Ful << PWM_IFR_PDIF_Pos)          /*!< PWM IFR: PDIF Mask */
#define PWM_IFR_BKLK0_Pos       14                                    /*!< PWM IFR: PWM Brake0 Locked */
#define PWM_IFR_BKLK0_Msk       (0x1ul << PWM_IFR_BKLK0_Pos)          /*!< PWM IFR: BKLK0 Mask */
#define PWM_IFR_CRLIF_Pos       16                                    /*!< PWM IFR: Capture Rising Latch Interrupt Flag */
#define PWM_IFR_CRLIF_Msk       (0x3Ful << PWM_IFR_CRLIF_Pos)         /*!< PWM IFR: CRLIF Mask */
#define PWM_IFR_CFLIF_Pos       24                                    /*!< PWM IFR: Capture Falling Latch Interrupt Flag */
#define PWM_IFR_CFLIF_Msk       (0x3Ful << PWM_IFR_CFLIF_Pos)         /*!< PWM IFR: CFLIF Mask */

/* PWM_CCR Bit Field Definitions */
#define PWM_CCR_CAPEN_Pos       0                                     /*!< PWM CCR: Capture Function Enable */
#define PWM_CCR_CAPEN_Msk       (0x3Ful << PWM_CCR_CAPEN_Pos)         /*!< PWM CCR: PTRGI Mask */
#define PWM_CCR_CAPINV_Pos      8                                     /*!< PWM CCR: PWM Center Point Trigger Indicator */
#define PWM_CCR_CAPINV_Msk      (0x3Ful << PWM_CCR_CAPINV_Pos)        /*!< PWM CCR: CTRGI Mask */
#define PWM_CCR_RLRLDEN_Pos     16                                    /*!< PWM CCR: PWM Falling Edge Point Trigger Indicator */
#define PWM_CCR_RLRLDEN_Msk     (0x3Ful << PWM_CCR_RLRLDEN_Pos)       /*!< PWM CCR: FETRGI Mask */
#define PWM_CCR_FLRLDEN_Pos     24                                    /*!< PWM CCR: PWM Rising Edge Point Trigger Indicator */
#define PWM_CCR_FLRLDEN_Msk     (0x3Ful << PWM_CCR_FLRLDEN_Pos)       /*!< PWM CCR: RETRGI Mask */

/* PWM_CAPSR Bit Field Definitions */
#define PWM_CAPSR_RLIFOV_Pos    0                                     /*!< PWM CAPSR: Rising Latch Interrupt Flag Overrun Status */
#define PWM_CAPSR_RLIFOV_Msk    (0x3Ful << PWM_CAPSR_RLIFOV_Pos)      /*!< PWM CAPSR: PTRGI Mask */
#define PWM_CAPSR_FLIFOV_Pos    8                                     /*!< PWM CAPSR: Falling Latch Interrupt Flag Overrun Status */
#define PWM_CAPSR_FLIFOV_Msk    (0x3Ful << PWM_CAPSR_FLIFOV_Pos)      /*!< PWM CAPSR: CTRGI Mask */

/*@}*/ /* end of group NUC400_PWM */
/*----------------------------- EPWM Controller ----------------------------*/
/** @addtogroup NUC400_EPWM NUC400 Enhanced PWM Control Register (EPWM)
  @{
*/
typedef struct {

    __IO uint32_t PWMCON;
    __IO uint32_t PWMSTS;
    __IO uint32_t PWMP;
    __IO uint32_t PWM0;
    __IO uint32_t PWM2;
    __IO uint32_t PWM4;
    __IO uint32_t PMSKE;
    __IO uint32_t PMSKD;
    __IO uint32_t ASPWM0;
    __IO uint32_t ASPWM2;
    __IO uint32_t ASPWM4;
    __IO uint32_t PDTC;
    __IO uint32_t PWMBO;
    __IO uint32_t PNP;
    __IO uint32_t ASPWMCON;
    __IO uint32_t PWMFCNT;
    __IO uint32_t PWMEIC;
    __IO uint32_t PWMOE;
} EPWM_T;

/* EPWM_PWMCON Bit Field Definitions */
#define EPWM_PWMCON_PWMMOD_Pos      0                                       /*!< EPWM PWMCON: PWM Mode Selection */
#define EPWM_PWMCON_PWMMOD_Msk      (0x3ul << EPWM_PWMCON_PWMMOD_Pos)       /*!< EPWM PWMCON: PWMMOD Mask */
#define EPWM_PWMCON_PWMDIV_Pos      2                                       /*!< EPWM PWMCON: PWM Clock Pre-divider Selection */
#define EPWM_PWMCON_PWMDIV_Msk      (0x3ul << EPWM_PWMCON_PWMDIV_Pos)       /*!< EPWM PWMCON: PWMDIV Mask */
#define EPWM_PWMCON_PWMI_EN_Pos     4                                       /*!< EPWM PWMCON: Enable PWM Interrupt */
#define EPWM_PWMCON_PWMI_EN_Msk     (0x1ul << EPWM_PWMCON_PWMI_EN_Pos)      /*!< EPWM PWMCON: PWMI_EN Mask */
#define EPWM_PWMCON_BRKI_EN_Pos     5                                       /*!< EPWM PWMCON: Enable Brake0 and Brake1 Interrupt */
#define EPWM_PWMCON_BRKI_EN_Msk     (0x1ul << EPWM_PWMCON_BRKI_EN_Pos)      /*!< EPWM PWMCON: BRKI_EN Mask */
#define EPWM_PWMCON_LOAD_Pos        6                                       /*!< EPWM PWMCON: Re-load PWM period registers (PWMP) and PWM duty registers (PWM0~3) control bit */
#define EPWM_PWMCON_LOAD_Msk        (0x1ul << EPWM_PWMCON_LOAD_Pos)         /*!< EPWM PWMCON: LOAD Mask */
#define EPWM_PWMCON_PWMRUN_Pos      7                                       /*!< EPWM PWMCON: Start PWMRUN Control Bit */
#define EPWM_PWMCON_PWMRUN_Msk      (0x1ul << EPWM_PWMCON_PWMRUN_Pos)       /*!< EPWM PWMCON: PWMRUN Mask */
#define EPWM_PWMCON_INT_TYPE_Pos    8                                       /*!< EPWM PWMCON: PWM Interrupt Type Selection Bit */
#define EPWM_PWMCON_INT_TYPE_Msk    (0x1ul << EPWM_PWMCON_INT_TYPE_Pos)     /*!< EPWM PWMCON: INT_TYPE Mask */
#define EPWM_PWMCON_PWMINV_Pos      9                                       /*!< EPWM PWMCON: Inverse PWM Comparator Output */
#define EPWM_PWMCON_PWMINV_Msk      ( 0x1ul << EPWM_PWMCON_PWMINV_Pos)      /*!< EPWM PWMCON: PWMINV Mask */
#define EPWM_PWMCON_CLRPWM_Pos      11                                      /*!< EPWM PWMCON: Clear PWM Counter Control Bit */
#define EPWM_PWMCON_CLRPWM_Msk      ( 0x1ul << EPWM_PWMCON_CLRPWM_Pos)      /*!< EPWM PWMCON: CLRPWM Mask */
#define EPWM_PWMCON_PWMTYPE_Pos     12                                      /*!< EPWM PWMCON: PWM Aligned Type Selection Bit */
#define EPWM_PWMCON_PWMTYPE_Msk     ( 0x1ul << EPWM_PWMCON_PWMTYPE_Pos)     /*!< EPWM PWMCON: PWMTYPE Mask */
#define EPWM_PWMCON_GRP_Pos         13                                      /*!< EPWM PWMCON: Group bit */
#define EPWM_PWMCON_GRP_Msk         ( 0x1ul << EPWM_PWMCON_GRP_Pos)         /*!< EPWM PWMCON: GRP Mask */
#define EPWM_PWMCON_INVBKP0_Pos     14                                      /*!< EPWM PWMCON: Inverse BKP0 State */
#define EPWM_PWMCON_INVBKP0_Msk     ( 0x1ul << EPWM_PWMCON_INVBKP0_Pos)     /*!< EPWM PWMCON: INVBKP0 Mask */
#define EPWM_PWMCON_INVBKP1_Pos     15                                      /*!< EPWM PWMCON: Inverse BKP1 State */
#define EPWM_PWMCON_INVBKP1_Msk     ( 0x1ul << EPWM_PWMCON_INVBKP1_Pos)     /*!< EPWM PWMCON: INVBKP1 Mask */
#define EPWM_PWMCON_BKEN0_Pos       16                                      /*!< EPWM PWMCON: BKPx0 Pin Trigger Brake Function0 Enable */
#define EPWM_PWMCON_BKEN0_Msk       ( 0x1ul << EPWM_PWMCON_BKEN0_Pos)       /*!< EPWM PWMCON: BKEN0 Mask */
#define EPWM_PWMCON_BKEN1_Pos       17                                      /*!< EPWM PWMCON: BKPx1 Pin Trigger Brake Function1 Enable */
#define EPWM_PWMCON_BKEN1_Msk       ( 0x1ul << EPWM_PWMCON_BKEN1_Pos)       /*!< EPWM PWMCON: BKEN1 Mask */
#define EPWM_PWMCON_BK1SEL_Pos      18                                      /*!< EPWM PWMCON: Brake Function 1 Source Selection */
#define EPWM_PWMCON_BK1SEL_Msk      ( 0x3ul << EPWM_PWMCON_BK1SEL_Pos)      /*!< EPWM PWMCON: BK1SEL Mask */
#define EPWM_PWMCON_BK0FILT_Pos     20                                      /*!< EPWM PWMCON: Brake 0 (BKPx0 pin) Edge Detector Filter Clock Selection */
#define EPWM_PWMCON_BK0FILT_Msk     ( 0x3ul << EPWM_PWMCON_BK0FILT_Pos)     /*!< EPWM PWMCON: BK0FILT Mask */
#define EPWM_PWMCON_BK1FILT_Pos     22                                      /*!< EPWM PWMCON: Brake 1 (BKPx1 pin) Edge Detector Filter Clock Selection */
#define EPWM_PWMCON_BK1FILT_Msk     ( 0x3ul << EPWM_PWMCON_BK1FILT_Pos)     /*!< EPWM PWMCON: BK1FILT Mask */
#define EPWM_PWMCON_CPO0BK_EN_Pos   24                                      /*!< EPWM PWMCON: Enable CPO0 Digital Output as Brake0 Source */
#define EPWM_PWMCON_CPO0BK_EN_Msk   ( 0x1ul << EPWM_PWMCON_CPO0BK_EN_Pos)   /*!< EPWM PWMCON: CPO0BK_EN Mask */
#define EPWM_PWMCON_CPO1BK_EN_Pos   25                                      /*!< EPWM PWMCON: Enable CPO1 Digital Output as Brake0 Source */
#define EPWM_PWMCON_CPO1BK_EN_Msk   ( 0x1ul << EPWM_PWMCON_CPO1BK_EN_Pos)   /*!< EPWM PWMCON: CPO1BK_EN Mask */
#define EPWM_PWMCON_CPO2BK_EN_Pos   26                                      /*!< EPWM PWMCON: Enable CPO2 Digital Output as Brake0 Source */
#define EPWM_PWMCON_CPO2BK_EN_Msk   ( 0x1ul << EPWM_PWMCON_CPO2BK_EN_Pos)   /*!< EPWM PWMCON: CPO2BK_EN Mask */
#define EPWM_PWMCON_LVDBK_EN_Pos    27                                      /*!< EPWM PWMCON: Low-level Detection Trigger PWM Brake Function 1 Enable */
#define EPWM_PWMCON_LVDBK_EN_Msk    ( 0x1ul << EPWM_PWMCON_LVDBK_EN_Pos)    /*!< EPWM PWMCON: LVDBK_EN Mask */
#define EPWM_PWMCON_BK0NF_DIS_Pos   28                                      /*!< EPWM PWMCON: PWM Brake 0 Noise Filter Disable */
#define EPWM_PWMCON_BK0NF_DIS_Msk   ( 0x1ul << EPWM_PWMCON_BK0NF_DIS_Pos)   /*!< EPWM PWMCON: BK0NF_DIS Mask */
#define EPWM_PWMCON_BK1NF_DIS_Pos   29                                      /*!< EPWM PWMCON: PWM Brake 1 Noise Filter Disable */
#define EPWM_PWMCON_BK1NF_DIS_Msk   ( 0x1ul << EPWM_PWMCON_BK1NF_DIS_Pos)   /*!< EPWM PWMCON: BK1NF_DIS Mask */
#define EPWM_PWMCON_CLDMD_Pos       31                                      /*!< EPWM PWMCON: Center Reload Mode Enable */
#define EPWM_PWMCON_CLDMD_Msk       ( 0x1ul << EPWM_PWMCON_CLDMD_Pos)       /*!< EPWM PWMCON: CLDMD Mask */

/* EPWM_PWMSTS Bit Field Definitions */
#define EPWM_PWMSTS_BKF0_Pos        0                                       /*!< EPWM PWMCON: PWM Brake0 Flag */
#define EPWM_PWMSTS_BKF0_Msk        (0x1ul << EPWM_PWMSTS_BKF0_Pos)         /*!< EPWM PWMCON: BKF0 Mask */
#define EPWM_PWMSTS_BKF1_Pos        0                                       /*!< EPWM PWMCON: PWM Brake1 Flag */
#define EPWM_PWMSTS_BKF1_Msk        (0x1ul << EPWM_PWMSTS_BKF1_Pos)         /*!< EPWM PWMCON: BKF1 Mask */
#define EPWM_PWMSTS_PWMF_Pos        0                                       /*!< EPWM PWMCON: PWM Period Flag */
#define EPWM_PWMSTS_PWMF_Msk        (0x1ul << EPWM_PWMSTS_PWMF_Pos)         /*!< EPWM PWMCON: PWMF Mask */
#define EPWM_PWMSTS_PWM0EF_Pos      0                                       /*!< EPWM PWMCON: PWMx0 Edge Flag */
#define EPWM_PWMSTS_PWM0EF_Msk      (0x1ul << EPWM_PWMSTS_PWM0EF_Pos)       /*!< EPWM PWMCON: PWM0EF Mask */
#define EPWM_PWMSTS_PWM2EF_Pos      0                                       /*!< EPWM PWMCON: PWMx2 Edge Flag */
#define EPWM_PWMSTS_PWM2EF_Msk      (0x1ul << EPWM_PWMSTS_PWM2EF_Pos)       /*!< EPWM PWMCON: PWM2EF Mask */
#define EPWM_PWMSTS_PWM4EF_Pos      0                                       /*!< EPWM PWMCON: PWMx4 Edge Flag */
#define EPWM_PWMSTS_PWM4EF_Msk      (0x1ul << EPWM_PWMSTS_PWM4EF_Pos)       /*!< EPWM PWMCON: PWM4EF Mask */
#define EPWM_PWMSTS_BKLK0_Pos       0                                       /*!< EPWM PWMCON: PWM Brake0 Locked */
#define EPWM_PWMSTS_BKLK0_Msk       (0x1ul << EPWM_PWMSTS_BKLK0_Pos)        /*!< EPWM PWMCON: BKLK0 Mask */

/* EPWM_ASPWMCON Bit Field Definitions */
#define EPWM_ASPWMCON_ASPWMEN_Pos   0                                       /*!< EPWM ASPWMEN: Asymmetric PWM Enable bit */
#define EPWM_ASPWMCON_ASPWMEN_Msk   (0x1ul << EPWM_ASPWMCON_ASPWMEN_Pos)    /*!< EPWM ASPWMEN: BKF0 Mask */
#define EPWM_ASPWMCON_ASPLDM0_Pos   8                                       /*!< EPWM ASPWMEN: Asymmetric PWMx0 Reload Mode Setting */
#define EPWM_ASPWMCON_ASPLDM0_Msk   (0x3ul << EPWM_ASPWMCON_ASPLDM0_Pos)    /*!< EPWM ASPWMEN: ASPLDM0 Mask */
#define EPWM_ASPWMCON_ASPLDM2_Pos   16                                      /*!< EPWM ASPWMEN: Asymmetric PWMx2 Reload Mode Setting */
#define EPWM_ASPWMCON_ASPLDM2_Msk   (0x3ul << EPWM_ASPWMCON_ASPLDM2_Pos)    /*!< EPWM ASPWMEN: ASPLDM2 Mask */
#define EPWM_ASPWMCON_ASPLDM4_Pos   24                                      /*!< EPWM ASPWMEN: Asymmetric PWMx4 Reload Mode Setting */
#define EPWM_ASPWMCON_ASPLDM4_Msk   (0x3ul << EPWM_ASPWMCON_ASPLDM4_Pos)    /*!< EPWM ASPWMEN: ASPLDM4 Mask */

/* EPWM_PDTC Bit Field Definitions */
#define EPWM_PDTC_DTCNT_Pos         0                                       /*!< EPWM PDTC: Dead-time counter */
#define EPWM_PDTC_DTCNT_Msk         (0x7FFul << EPWM_PDTC_DTCNT_Pos)        /*!< EPWM PDTC: DTCNT Mask */
#define EPWM_PDTC_DTEN0_Pos         16                                      /*!< EPWM PDTC: Enable dead-time insertion for PWMx pair (PWM0, PWM1) */
#define EPWM_PDTC_DTEN0_Msk         (0x1ul << EPWM_PDTC_DTEN0_Pos)          /*!< EPWM PDTC: DTEN0 Mask */
#define EPWM_PDTC_DTEN2_Pos         17                                      /*!< EPWM PDTC: Enable dead-time insertion for PWMx pair (PWM2, PWM3) */
#define EPWM_PDTC_DTEN2_Msk         (0x1ul << EPWM_PDTC_DTEN2_Pos)          /*!< EPWM PDTC: DTEN2 Mask */
#define EPWM_PDTC_DTEN4_Pos         18                                      /*!< EPWM PDTC: Enable dead-time insertion for PWMx pair (PWM4, PWM5) */
#define EPWM_PDTC_DTEN4_Msk         (0x1ul << EPWM_PDTC_DTEN4_Pos)          /*!< EPWM PDTC: DTEN4 Mask */

/* EPWM_PWMEIC Bit Field Definitions */
#define EPWM_PWMEIC_PWM0EI_EN_Pos   0                                       /*!< EPWM PWMEIC: Enable PWMx0 Edge Interrupt */
#define EPWM_PWMEIC_PWM0EI_EN_Msk   (0x7FFul << EPWM_PWMEIC_PWM0EI_EN_Pos)  /*!< EPWM PWMEIC: PWM0EI_EN Mask */
#define EPWM_PWMEIC_PWM2EI_EN_Pos   1                                       /*!< EPWM PWMEIC: Enable PWMx2 Edge Interrupt */
#define EPWM_PWMEIC_PWM2EI_EN_Msk   (0x7FFul << EPWM_PWMEIC_PWM2EI_EN_Pos)  /*!< EPWM PWMEIC: PWM2EI_EN Mask */
#define EPWM_PWMEIC_PWM4EI_EN_Pos   2                                       /*!< EPWM PWMEIC: Enable PWMx4 Edge Interrupt */
#define EPWM_PWMEIC_PWM4EI_EN_Msk   (0x7FFul << EPWM_PWMEIC_PWM4EI_EN_Pos)  /*!< EPWM PWMEIC: PWM4EI_EN Mask */
#define EPWM_PWMEIC_EINT0_TYPE_Pos  8                                       /*!< EPWM PWMEIC: PWMx0 Edge Interrupt Type */
#define EPWM_PWMEIC_EINT0_TYPE_Msk  (0x7FFul << EPWM_PWMEIC_EINT0_TYPE_Pos) /*!< EPWM PWMEIC: PWM0EI_EN Mask */
#define EPWM_PWMEIC_EINT2_TYPE_Pos  9                                       /*!< EPWM PWMEIC: PWMx2 Edge Interrupt Type */
#define EPWM_PWMEIC_EINT2_TYPE_Msk  (0x7FFul << EPWM_PWMEIC_EINT2_TYPE_Pos) /*!< EPWM PWMEIC: PWM2EI_EN Mask */
#define EPWM_PWMEIC_EINT4_TYPE_Pos  10                                      /*!< EPWM PWMEIC: PWMx4 Edge Interrupt Type */
#define EPWM_PWMEIC_EINT4_TYPE_Msk  (0x7FFul << EPWM_PWMEIC_EINT4_TYPE_Pos) /*!< EPWM PWMEIC: PWM4EI_EN Mask */
/*@}*/ /* end of group NUC400_EPWM */

/*----------------------------- QEI Controller ----------------------------*/
/** @addtogroup NUC400_QEI NUC400 QEI Control Register
  @{
*/
typedef struct {
    __IO uint32_t CNT;
    __IO uint32_t CNTHLD;
    __IO uint32_t CNTILAT;
    __IO uint32_t CNTCMP;
    uint32_t RESERVED0[1];
    __IO uint32_t MAXCNT;
    __IO uint32_t CTR;
    uint32_t RESERVED1[4];                       /*!< Offset: 0x001C ~ 0x0028  Reserved                                  */
    __IO uint32_t STS;
} QEI_T;

/* QEI_CTR Bit Field Definitions */
#define QEI_CTR_NFCLK_S_Pos         0                                     /*!< QEI CTR: Noise Filter Clock Pre-divided Selection */
#define QEI_CTR_NFCLK_S_Msk         (0x3ul << QEI_CTR_NFCLK_S_Pos)        /*!< QEI CTR: NFCLK_S Mask */
#define QEI_CTR_QEINF_DIS_Pos       3                                     /*!< QEI CTR: Disable QEI Controller Input Noise Filter */
#define QEI_CTR_QEINF_DIS_Msk       (0x1ul << QEI_CTR_QEINF_DIS_Pos)      /*!< QEI CTR: QEINF_DIS Mask */
#define QEI_CTR_QEA_EN_Pos          4                                     /*!< QEI CTR: Enable QEA Input to QEI Controller */
#define QEI_CTR_QEA_EN_Msk          (0x1ul << QEI_CTR_QEA_EN_Pos)         /*!< QEI CTR: QEA_EN Mask */
#define QEI_CTR_QEB_EN_Pos          5                                     /*!< QEI CTR: Enable QEB Input to QEI Controller */
#define QEI_CTR_QEB_EN_Msk          (0x1ul << QEI_CTR_QEB_EN_Pos)         /*!< QEI CTR: QEB_EN Mask */
#define QEI_CTR_IDX_EN_Pos          6                                     /*!< QEI CTR: Enable IDX Input to QEI Controller */
#define QEI_CTR_IDX_EN_Msk          (0x1ul << QEI_CTR_IDX_EN_Pos)         /*!< QEI CTR: IDX_EN Mask */
#define QEI_CTR_QEIMODE_Pos         8                                     /*!< QEI CTR: QEI Counting Mode Selection */
#define QEI_CTR_QEIMODE_Msk         (0x1ul << QEI_CTR_QEIMODE_Pos)        /*!< QEI CTR: QEIMODE Mask */
#define QEI_CTR_QEA_INV_Pos         12                                    /*!< QEI CTR: Inverse QEA Input Polarity */
#define QEI_CTR_QEA_INV_Msk         (0x1ul << QEI_CTR_QEA_INV_Pos)        /*!< QEI CTR: QEA_INV Mask */
#define QEI_CTR_QEB_INV_Pos         13                                    /*!< QEI CTR: Inverse QEB Input Polarity */
#define QEI_CTR_QEB_INV_Msk         (0x1ul << QEI_CTR_QEB_INV_Pos)        /*!< QEI CTR: QEB_INV Mask */
#define QEI_CTR_IDX_INV_Pos         14                                    /*!< QEI CTR: Inverse IDX Input Polarity */
#define QEI_CTR_IDX_INV_Msk         (0x1ul << QEI_CTR_IDX_INV_Pos)        /*!< QEI CTR: IDX_INV Mask */
#define QEI_CTR_OVUN_IEN_Pos        16                                    /*!< QEI CTR: Enable OVUNF Trigger QEI Interrupt */
#define QEI_CTR_OVUN_IEN_Msk        (0x1ul << QEI_CTR_OVUN_IEN_Pos)       /*!< QEI CTR: OVUN_IEN Mask */
#define QEI_CTR_DIR_IEN_Pos         17                                    /*!< QEI CTR: Enable DIRF Trigger QEI Interrupt */
#define QEI_CTR_DIR_IEN_Msk         (0x1ul << QEI_CTR_DIR_IEN_Pos)        /*!< QEI CTR: DIR_IEN Mask */
#define QEI_CTR_CMP_IEN_Pos         18                                    /*!< QEI CTR: Enable CMPF Trigger QEI Interrupt */
#define QEI_CTR_CMP_IEN_Msk         (0x1ul << QEI_CTR_CMP_IEN_Pos)        /*!< QEI CTR: CMP_IEN Mask */
#define QEI_CTR_IDX_IEN_Pos         19                                    /*!< QEI CTR: Enable IDXF Trigger QEI Interrupt */
#define QEI_CTR_IDX_IEN_Msk         (0x1ul << QEI_CTR_IDX_IEN_Pos)        /*!< QEI CTR: IDX_IEN Mask */
#define QEI_CTR_HOLDBYT0_Pos        20                                    /*!< QEI CTR: Hold QEI_CNT by Timer 0*/
#define QEI_CTR_HOLDBYT0_Msk        (0x1ul << QEI_CTR_HOLDBYT0_Pos)       /*!< QEI CTR: HOLDBYT0 Mask */
#define QEI_CTR_HOLDBYT1_Pos        21                                    /*!< QEI CTR: Hold QEI_CNT by Timer 1 */
#define QEI_CTR_HOLDBYT1_Msk        (0x1ul << QEI_CTR_HOLDBYT1_Pos)       /*!< QEI CTR: HOLDBYT1 Mask */
#define QEI_CTR_HOLDBYT2_Pos        22                                    /*!< QEI CTR: Hold QEI_CNT by Timer 2 */
#define QEI_CTR_HOLDBYT2_Msk        (0x1ul << QEI_CTR_HOLDBYT2_Pos)       /*!< QEI CTR: HOLDBYT2 Mask */
#define QEI_CTR_HOLDBYT3_Pos        23                                    /*!< QEI CTR: Hold QEI_CNT by Timer  */
#define QEI_CTR_HOLDBYT3_Msk        (0x1ul << QEI_CTR_HOLDBYT3_Pos)       /*!< QEI CTR: HOLDBYT3 Mask */
#define QEI_CTR_HOLDCNT_Pos         24                                    /*!< QEI CTR: Hold QEI_CNT Control Bit */
#define QEI_CTR_HOLDCNT_Msk         (0x1ul << QEI_CTR_HOLDCNT_Pos)        /*!< QEI CTR: HOLDCNT Mask */
#define QEI_CTR_IDXLAT_Pos          25                                    /*!< QEI CTR: Index Latch QEI_CNT Enable Bit */
#define QEI_CTR_IDXLAT_Msk          (0x1ul << QEI_CTR_IDXLAT_Pos)         /*!< QEI CTR: IDXLAT Mask */
#define QEI_CTR_IDXRLD_EN_Pos       27                                    /*!< QEI CTR: Index Trigger QEI_CNT Reload Enable Bit */
#define QEI_CTR_IDXRLD_EN_Msk       (0x1ul << QEI_CTR_IDXRLD_EN_Pos)      /*!< QEI CTR: IDXRLD_EN Mask */
#define QEI_CTR_CMP_EN_Pos          28                                    /*!< QEI CTR: The Compare Function Enable Bit*/
#define QEI_CTR_CMP_EN_Msk          (0x1ul << QEI_CTR_CMP_EN_Pos)         /*!< QEI CTR: CMP_EN Mask */
#define QEI_CTR_QEI_EN_Pos          29                                    /*!< QEI CTR: Quadrature Encoder Interface Controller Enable Bit */
#define QEI_CTR_QEI_EN_Msk          (0x1ul << QEI_CTR_QEI_EN_Pos)         /*!< QEI CTR: QEI_EN Mask */
/*@}*/ /* end of group NUC400_QEI */

/*----------------------------- ECAP Controller ----------------------------*/
/** @addtogroup NUC400_ECAP NUC400 Enhanced Capture Control Register (ECAP)
  @{
*/
typedef struct {
    __IO uint32_t CNT;
    __IO uint32_t HLD0;
    __IO uint32_t HLD1;
    __IO uint32_t HLD2;
    __IO uint32_t CNTCMP;
    __IO uint32_t CTR0;
    __IO uint32_t CTR1;
    __IO uint32_t STS;
} ECAP_T;

/* ECAP_CTR0 Bit Field Definitions */
#define ECAP_CTR0_NFCLK_S_Pos       0                                     /*!< ECAP CTR0: Noise Filter Clock Pre-divided Selection */
#define ECAP_CTR0_NFCLK_S_Msk       (0x3ul << ECAP_CTR0_NFCLK_S_Pos)      /*!< ECAP CTR0: NFCLK_S Mask */
#define ECAP_CTR0_CAPNF_DIS_Pos     3                                     /*!< ECAP CTR0: Disable Input Capture Noise Filter */
#define ECAP_CTR0_CAPNF_DIS_Msk     (0x1ul << ECAP_CTR0_CAPNF_DIS_Pos)    /*!< ECAP CTR0: CAPNF_DIS Mask */
#define ECAP_CTR0_IC0_EN_Pos        4                                     /*!< ECAP CTR0: Enable Port Pin IC0 Input to Input Capture Unit */
#define ECAP_CTR0_IC0_EN_Msk        (0x1ul << ECAP_CTR0_IC0_EN_Pos)       /*!< ECAP CTR0: IC0_EN Mask */
#define ECAP_CTR0_IC1_EN_Pos        5                                     /*!< ECAP CTR0: Enable Port Pin IC1 Input to Input Capture Unit */
#define ECAP_CTR0_IC1_EN_Msk        (0x1ul << ECAP_CTR0_IC1_EN_Pos)       /*!< ECAP CTR0: IC1_EN Mask */
#define ECAP_CTR0_IC2_EN_Pos        6                                     /*!< ECAP CTR0: Enable Port Pin IC2 Input to Input Capture Unit */
#define ECAP_CTR0_IC2_EN_Msk        (0x1ul << ECAP_CTR0_IC2_EN_Pos)       /*!< ECAP CTR0: IC2_EN Mask */
#define ECAP_CTR0_CAPSEL0_Pos       8                                     /*!< ECAP CTR0: CAP0 Input Source Selection Bit */
#define ECAP_CTR0_CAPSEL0_Msk       (0x3ul << ECAP_CTR0_CAPSEL0_Pos)      /*!< ECAP CTR0: CAPSEL0 Mask */
#define ECAP_CTR0_CAPSEL1_Pos       10                                    /*!< ECAP CTR0: CAP0 Input Source Selection Bit */
#define ECAP_CTR0_CAPSEL1_Msk       (0x3ul << ECAP_CTR0_CAPSEL1_Pos)      /*!< ECAP CTR0: CAPSEL1 Mask */
#define ECAP_CTR0_CAPSEL2_Pos       12                                    /*!< ECAP CTR0: CAP0 Input Source Selection Bit */
#define ECAP_CTR0_CAPSEL2_Msk       (0x3ul << ECAP_CTR0_CAPSEL2_Pos)      /*!< ECAP CTR0: CAPSEL2 Mask */
#define ECAP_CTR0_CAPTF0_IEN_Pos    16                                    /*!< ECAP CTR0: Enable Input Capture Channel 0 Interrupt */
#define ECAP_CTR0_CAPTF0_IEN_Msk    (0x1ul << ECAP_CTR0_CAPTF0_IEN_Pos)   /*!< ECAP CTR0: CAPTF0_IEN Mask */
#define ECAP_CTR0_CAPTF1_IEN_Pos    17                                    /*!< ECAP CTR0: Enable Input Capture Channel 1 Interrupt */
#define ECAP_CTR0_CAPTF1_IEN_Msk    (0x1ul << ECAP_CTR0_CAPTF1_IEN_Pos)   /*!< ECAP CTR0: CAPTF1_IEN Mask */
#define ECAP_CTR0_CAPTF2_IEN_Pos    18                                    /*!< ECAP CTR0: Enable Input Capture Channel 2 Interrupt */
#define ECAP_CTR0_CAPTF2_IEN_Msk    (0x1ul << ECAP_CTR0_CAPTF2_IEN_Pos)   /*!< ECAP CTR0: CAPTF2_IEN Mask */
#define ECAP_CTR0_CAPOV_IEN_Pos     20                                    /*!< ECAP CTR0: Enable CAPOVF Trigger Input Capture Interrupt */
#define ECAP_CTR0_CAPOV_IEN_Msk     (0x1ul << ECAP_CTR0_CAPOV_IEN_Pos)    /*!< ECAP CTR0: CAPOV_IEN Mask */
#define ECAP_CTR0_CAPCMP_IEN_Pos    21                                    /*!< ECAP CTR0: Enable CAPCMPF Trigger Input Capture Interrupt */
#define ECAP_CTR0_CAPCMP_IEN_Msk    (0x1ul << ECAP_CTR0_CAPCMP_IEN_Pos)   /*!< ECAP CTR0: CAPCMP_IEN Mask */
#define ECAP_CTR0_CPST_Pos          24                                    /*!< ECAP CTR0: Input Capture Counter Start Bit */
#define ECAP_CTR0_CPST_Msk          (0x1ul << ECAP_CTR0_CPST_Pos)         /*!< ECAP CTR0: CPST Mask */
#define ECAP_CTR0_CMPCLR_Pos        25                                    /*!< ECAP CTR0: Input Capture Counter Clear by Compare-match Control Bit */
#define ECAP_CTR0_CMPCLR_Msk        (0x1ul << ECAP_CTR0_CMPCLR_Pos)       /*!< ECAP CTR0: CMPCLR Mask */
#define ECAP_CTR0_CPTCLR_Pos        26                                    /*!< ECAP CTR0: Input Capture Counter Clear by Capture Events Control Bit */
#define ECAP_CTR0_CPTCLR_Msk        (0x1ul << ECAP_CTR0_CPTCLR_Pos)       /*!< ECAP CTR0: CPTCLR Mask */
#define ECAP_CTR0_RLD_EN_Pos        27                                    /*!< ECAP CTR0: The Reload Function Enable Bit */
#define ECAP_CTR0_RLD_EN_Msk        (0x1ul << ECAP_CTR0_RLD_EN_Pos)       /*!< ECAP CTR0: RLD_EN Mask */
#define ECAP_CTR0_CMP_EN_Pos        28                                    /*!< ECAP CTR0: The Compare Function Enable Bit */
#define ECAP_CTR0_CMP_EN_Msk        (0x1ul << ECAP_CTR0_CMP_EN_Pos)       /*!< ECAP CTR0: CMP_EN Mask */
#define ECAP_CTR0_CAP_EN_Pos        29                                    /*!< ECAP CTR0: Input Capture Timer/Counter Enable Bit */
#define ECAP_CTR0_CAP_EN_Msk        (0x1ul << ECAP_CTR0_CAP_EN_Pos)       /*!< ECAP CTR0: CAP_EN Mask */

/* ECAP_CTR1 Bit Field Definitions */
#define ECAP_CTR1_CAPEDG0_Pos       0                                     /*!< ECAP CTR1: Channel 0 Captured Edge Selection */
#define ECAP_CTR1_CAPEDG0_Msk       (0x3ul << ECAP_CTR1_CAPEDG0_Pos)      /*!< ECAP CTR1: CAPEDG0 Mask */
#define ECAP_CTR1_CAPEDG1_Pos       2                                     /*!< ECAP CTR1: Channel 1 Captured Edge Selection */
#define ECAP_CTR1_CAPEDG1_Msk       (0x3ul << ECAP_CTR1_CAPEDG1_Pos)      /*!< ECAP CTR1: CAPEDG1 Mask */
#define ECAP_CTR1_CAPEDG2_Pos       4                                     /*!< ECAP CTR1: Channel 2 Captured Edge Selection */
#define ECAP_CTR1_CAPEDG2_Msk       (0x3ul << ECAP_CTR1_CAPEDG2_Pos)      /*!< ECAP CTR1: CAPEDG2 Mask */
#define ECAP_CTR1_CPRLD_S_Pos       8                                     /*!< ECAP CTR1: CAPCNT Reload Trigger Source Selection */
#define ECAP_CTR1_CPRLD_S_Msk       (0x7ul << ECAP_CTR1_CPRLD_S_Pos)      /*!< ECAP CTR1: CPRLD_S Mask */
#define ECAP_CTR1_CAPDIV_Pos        12                                    /*!< ECAP CTR1: Capture Timer Clock Divide Selection */
#define ECAP_CTR1_CAPDIV_Msk        (0x7ul << ECAP_CTR1_CAPDIV_Pos)       /*!< ECAP CTR1: CAPDIV Mask */
#define ECAP_CTR1_CAPCNT_SRC_Pos    16                                    /*!< ECAP CTR1: Capture Timer/Counter Clock Source Select */
#define ECAP_CTR1_CAPCNT_SRC_Msk    (0x3ul << ECAP_CTR1_CAPCNT_SRC_Pos)   /*!< ECAP CTR1: CAPCNT_SRC Mask */

/* ECAP_STS Bit Field Definitions */
#define ECAP_STS_CAPTF0_Pos         0                                     /*!< ECAP STS: Input Capture Channel 0 Captured Flag */
#define ECAP_STS_CAPTF0_Msk         (0x1ul << ECAP_STS_CAPTF0_Pos)        /*!< ECAP STS: CAPTF0 Mask */
#define ECAP_STS_CAPTF1_Pos         1                                     /*!< ECAP STS: Input Capture Channel 1 Captured Flag */
#define ECAP_STS_CAPTF1_Msk         (0x1ul << ECAP_STS_CAPTF1_Pos)        /*!< ECAP STS: CAPTF1 Mask */
#define ECAP_STS_CAPTF2_Pos         2                                     /*!< ECAP STS: Input Capture Channel 2 Captured Flag */
#define ECAP_STS_CAPTF2_Msk         (0x1ul << ECAP_STS_CAPTF2_Pos)        /*!< ECAP STS: CAPTF2 Mask */
#define ECAP_STS_CAPCMPF_Pos        4                                     /*!< ECAP STS: Input Capture Compare-match Flag */
#define ECAP_STS_CAPCMPF_Msk        (0x1ul << ECAP_STS_CAPCMPF_Pos)       /*!< ECAP STS: CAPCMPF Mask */
#define ECAP_STS_CAPOVF_Pos         5                                     /*!< ECAP STS: Input Capture Counter Overflow Flag */
#define ECAP_STS_CAPOVF_Msk         (0x1ul << ECAP_STS_CAPOVF_Pos)        /*!< ECAP STS: CAPOVF Mask */
/*@}*/ /* end of group NUC400_ECAP */

/*-------------------- Serial Peripheral Interface (SPI) ----------------------*/
/** @addtogroup NUC400_SPI NUC400 Serial Peripheral Interface (SPI)
  @{
 */
typedef struct {
    __IO uint32_t CTL;                        /*!< Offset: 0x0000   SPI Control Register                               */
    __IO uint32_t CLKDIV;                     /*!< Offset: 0x0004   SPI Clock Divider Register                         */
    __IO uint32_t SSCR;                       /*!< Offset: 0x0008   SPI Slave Select Control Register                  */
    __IO uint32_t PDMACTL;                    /*!< Offset: 0x000C   SPI PDMA Control Register                          */
    __IO uint32_t FIFOCTL;                    /*!< Offset: 0x0010   SPI FIFO Control Register                          */
    __IO uint32_t STATUS;                     /*!< Offset: 0x0014   SPI Status Register                                */
    __I  uint32_t RESERVED0[2];               /*!< Offset: 0x0018 ~ 0x001C   Reserved                                  */
    __O  uint32_t TX;                         /*!< Offset: 0x0020   Data Transmit Register                             */
    __I uint32_t RESERVE1[3];                 /*!< Offset: 0x0024 ~ 0x002C   Reserved                                  */
    __I  uint32_t RX;                         /*!< Offset: 0x0030   Data Receive Register                              */
} SPI_T;


/* SPI_CTL Bit Field Definitions */
#define SPI_CTL_SPIEN_Pos         0                            /*!< SPI CTL: SPIEN Position */
#define SPI_CTL_SPIEN_Msk         (1ul << SPI_CTL_SPIEN_Pos)   /*!< SPI CTL: SPIEN Mask */
#define SPI_CTL_RX_NEG_Pos        1                            /*!< SPI CTL: RX_NEG Position */
#define SPI_CTL_RX_NEG_Msk        (1ul << SPI_CTL_RX_NEG_Pos)  /*!< SPI CTL: RX_NEG Mask */
#define SPI_CTL_TX_NEG_Pos        2                            /*!< SPI CTL: TX_NEG Position */
#define SPI_CTL_TX_NEG_Msk        (1ul << SPI_CTL_TX_NEG_Pos)  /*!< SPI CTL: TX_NEG Mask */
#define SPI_CTL_CLKP_Pos          3                            /*!< SPI CTL: CLKP Position */
#define SPI_CTL_CLKP_Msk          (1ul << SPI_CTL_CLKP_Pos)    /*!< SPI CTL: CLKP Mask */
#define SPI_CTL_SP_CYCLE_Pos      4                            /*!< SPI CTL: SP_CYCLE Position */
#define SPI_CTL_SP_CYCLE_Msk      (0xFul << SPI_CTL_SP_CYCLE_Pos)    /*!< SPI CTL: SP_CYCLE Mask */
#define SPI_CTL_DWIDTH_Pos        8                                  /*!< SPI CTL: DWIDTH Position */
#define SPI_CTL_DWIDTH_Msk        (0x1Ful << SPI_CTL_DWIDTH_Pos)   /*!< SPI CTL: DWIDTH Mask */
#define SPI_CTL_LSB_Pos           13                                 /*!< SPI CTL: LSB Position */
#define SPI_CTL_LSB_Msk           (1ul << SPI_CTL_LSB_Pos)     /*!< SPI CTL: LSB Mask */
#define SPI_CTL_TWOB_Pos          16                           /*!< SPI CTL: TWOB Position */
#define SPI_CTL_TWOB_Msk          (1ul << SPI_CTL_TWOB_Pos)    /*!< SPI CTL: TWOB Mask */
#define SPI_CTL_UNIT_INTEN_Pos    17                           /*!< SPI CTL: UNIT_INTEN Position */
#define SPI_CTL_UNIT_INTEN_Msk    (1ul << SPI_CTL_UNIT_INTEN_Pos)    /*!< SPI CTL: UNIT_INTEN Mask */
#define SPI_CTL_SLAVE_Pos         18                                 /*!< SPI CTL: SLAVE Position */
#define SPI_CTL_SLAVE_Msk         (1ul << SPI_CTL_SLAVE_Pos)         /*!< SPI CTL: SLAVE Mask */
#define SPI_CTL_REORDER_Pos       19                                 /*!< SPI CTL: REORDER Position */
#define SPI_CTL_REORDER_Msk       (1ul << SPI_CTL_REORDER_Pos)       /*!< SPI CTL: REORDER Mask */
#define SPI_CTL_QD_IO_DIR_Pos     20                                 /*!< SPI CTL: QD_IO_DIR Position */
#define SPI_CTL_QD_IO_DIR_Msk     (1ul << SPI_CTL_QD_IO_DIR_Pos)     /*!< SPI CTL: QD_IO_DIR Mask */
#define SPI_CTL_DUAL_IO_EN_Pos    21                                 /*!< SPI CTL: DUAL_IO_EN Position */
#define SPI_CTL_DUAL_IO_EN_Msk    (1ul << SPI_CTL_DUAL_IO_EN_Pos)    /*!< SPI CTL: DUAL_IO_EN Mask */
#define SPI_CTL_QUAD_IO_EN_Pos    22                                 /*!< SPI CTL: QUAD_IO_EN Position */
#define SPI_CTL_QUAD_IO_EN_Msk    (1ul << SPI_CTL_QUAD_IO_EN_Pos)    /*!< SPI CTL: QUAD_IO_EN Mask */

/* SPI_CLKDIV Bit Field Definitions */
#define SPI_CLKDIV_DIVIDER_Pos    0                                  /*!< SPI CLKDIV: DIVIDER Position */
#define SPI_CLKDIV_DIVIDER_Msk    (0xFFul << SPI_CLKDIV_DIVIDER_Pos) /*!< SPI CLKDIV: DIVIDER Mask */

/* SPI_SSCR Bit Field Definitions */
#define SPI_SSCR_SS_Pos           0                                   /*!< SPI SSCR: SS Position */
#define SPI_SSCR_SS_Msk           (3ul << SPI_SSCR_SS_Pos)            /*!< SPI SSCR: SS Mask */
#define SPI_SSCR_SS_LVL_Pos       2                                   /*!< SPI SSCR: SS_LVL Position */
#define SPI_SSCR_SS_LVL_Msk       (1ul << SPI_SSCR_SS_LVL_Pos)        /*!< SPI SSCR: SS_LVL Mask */
#define SPI_SSCR_AUTOSS_Pos       3                                   /*!< SPI SSCR: AUTOSS Position */
#define SPI_SSCR_AUTOSS_Msk       (1ul << SPI_SSCR_AUTOSS_Pos)        /*!< SPI SSCR: AUTOSS Mask */
#define SPI_SSCR_SLV3WIRE_Pos     4                                   /*!< SPI SSCR: SLV3WIRE Position */
#define SPI_SSCR_SLV3WIRE_Msk     (1ul << SPI_SSCR_SLV3WIRE_Pos)      /*!< SPI SSCR: SLV3WIRE Mask */
#define SPI_SSCR_SLVTO_INTEN_Pos  5                                   /*!< SPI SSCR: SLVTO_INTEN Position */
#define SPI_SSCR_SLVTO_INTEN_Msk  (1ul << SPI_SSCR_SLVTO_INTEN_Pos)   /*!< SPI SSCR: SLVTO_INTEN Mask */
#define SPI_SSCR_SLVTO_FFCLR_Pos  6                                   /*!< SPI SSCR: SLVTO_FFCLR Position */
#define SPI_SSCR_SLVTO_FFCLR_Msk  (1ul << SPI_SSCR_SLVTO_FFCLR_Pos)   /*!< SPI SSCR: SLVTO_FFCLR Mask */
#define SPI_SSCR_SLVER0_INTEN_Pos 8                                   /*!< SPI SSCR: SLVER0_INTEN Position */
#define SPI_SSCR_SLVER0_INTEN_Msk (1ul << SPI_SSCR_SLVER0_INTEN_Pos)  /*!< SPI SSCR: SLVER0_INTEN Mask */
#define SPI_SSCR_SLVER1_INTEN_Pos 9                                   /*!< SPI SSCR: SLVER1_INTEN Position */
#define SPI_SSCR_SLVER1_INTEN_Msk (1ul << SPI_SSCR_SLVER1_INTEN_Pos)  /*!< SPI SSCR: SLVER1_INTEN Mask */
#define SPI_SSCR_SSACT_INTEN_Pos  12                                  /*!< SPI SSCR: SSACT_INTEN Position */
#define SPI_SSCR_SSACT_INTEN_Msk  (1ul << SPI_SSCR_SSACT_INTEN_Pos)   /*!< SPI SSCR: SSACT_INTEN Mask */
#define SPI_SSCR_SSINA_INTEN_Pos  13                                  /*!< SPI SSCR: SSINA_INTEN Position */
#define SPI_SSCR_SSINA_INTEN_Msk  (1ul << SPI_SSCR_SSINA_INTEN_Pos)   /*!< SPI SSCR: SSINA_INTEN Mask */
#define SPI_SSCR_SLVTOPRD_Pos     16                                  /*!< SPI SSCR: SLVTOPRD Position */
#define SPI_SSCR_SLVTOPRD_Msk     (0xFFFFul << SPI_SSCR_SLVTOPRD_Pos) /*!< SPI SSCR: SLVTOPRD Mask */

/* SPI_PDMACTL Bit Field Definitions */
#define SPI_PDMACTL_TXPDMA_EN_Pos   0                                   /*!< SPI PDMACTL: TXPDMA_EN Position */
#define SPI_PDMACTL_TXPDMA_EN_Msk   (1ul << SPI_PDMACTL_TXPDMA_EN_Pos)  /*!< SPI PDMACTL: TXPDMA_EN Mask */
#define SPI_PDMACTL_RXPDMA_EN_Pos   1                                   /*!< SPI PDMACTL: RXPDMA_EN Position */
#define SPI_PDMACTL_RXPDMA_EN_Msk   (1ul << SPI_PDMACTL_RXPDMA_EN_Pos)  /*!< SPI PDMACTL: RXPDMA_EN Mask */
#define SPI_PDMACTL_PDMA_RST_Pos    2                                   /*!< SPI PDMACTL: PDMA_RST Position */
#define SPI_PDMACTL_PDMA_RST_Msk    (1ul << SPI_PDMACTL_PDMA_RST_Pos)   /*!< SPI PDMACTL: PDMA_RST Mask */

/* SPI_FIFOCTL Bit Field Definitions */
#define SPI_FIFOCTL_RX_CLR_Pos         0                                      /*!< SPI FIFOCTL: RX_CLR Position */
#define SPI_FIFOCTL_RX_CLR_Msk         (1ul << SPI_FIFOCTL_RX_CLR_Pos)        /*!< SPI FIFOCTL: RX_CLR Mask */
#define SPI_FIFOCTL_TX_CLR_Pos         1                                      /*!< SPI FIFOCTL: TX_CLR Position */
#define SPI_FIFOCTL_TX_CLR_Msk         (1ul << SPI_FIFOCTL_TX_CLR_Pos)        /*!< SPI FIFOCTL: TX_CLR Mask */
#define SPI_FIFOCTL_RXTH_INTEN_Pos     2                                      /*!< SPI FIFOCTL: RXTH_INTEN Position */
#define SPI_FIFOCTL_RXTH_INTEN_Msk     (1ul << SPI_FIFOCTL_RXTH_INTEN_Pos)    /*!< SPI FIFOCTL: RXTH_INTEN Mask */
#define SPI_FIFOCTL_TXTH_INTEN_Pos     3                                      /*!< SPI FIFOCTL: TXTH_INTEN Position */
#define SPI_FIFOCTL_TXTH_INTEN_Msk     (1ul << SPI_FIFOCTL_TXTH_INTEN_Pos)    /*!< SPI FIFOCTL: TXTH_INTEN Mask */
#define SPI_FIFOCTL_RXTO_INTEN_Pos     4                                      /*!< SPI FIFOCTL: RXTO_INTEN Position */
#define SPI_FIFOCTL_RXTO_INTEN_Msk     (1ul << SPI_FIFOCTL_RXTO_INTEN_Pos)    /*!< SPI FIFOCTL: RXTO_INTEN Mask */
#define SPI_FIFOCTL_RXOV_INTEN_Pos     5                                      /*!< SPI FIFOCTL: RXOV_INTEN Position */
#define SPI_FIFOCTL_RXOV_INTEN_Msk     (1ul << SPI_FIFOCTL_RXOV_INTEN_Pos)    /*!< SPI FIFOCTL: RXOV_INTEN Mask */
#define SPI_FIFOCTL_TXUDR_DO_Pos       6                                      /*!< SPI FIFOCTL: TXUDR_DO Position */
#define SPI_FIFOCTL_TXUDR_DO_Msk       (1ul << SPI_FIFOCTL_TXUDR_DO_Pos)      /*!< SPI FIFOCTL: TXUDR_DO Mask */
#define SPI_FIFOCTL_TXUDR_INTEN_Pos    7                                      /*!< SPI FIFOCTL: TXUDR_INTEN Position */
#define SPI_FIFOCTL_TXUDR_INTEN_Msk    (1ul << SPI_FIFOCTL_TXUDR_INTEN_Pos)   /*!< SPI FIFOCTL: TXUDR_INTEN Mask */
#define SPI_FIFOCTL_RX_THRESHOLD_Pos   24                                     /*!< SPI FIFOCTL: RX_THRESHOLD Position */
#define SPI_FIFOCTL_RX_THRESHOLD_Msk   (7ul << SPI_FIFOCTL_RX_THRESHOLD_Pos)  /*!< SPI FIFOCTL: RX_THRESHOLD Mask */
#define SPI_FIFOCTL_TX_THRESHOLD_Pos   28                                     /*!< SPI FIFOCTL: TX_THRESHOLD Position */
#define SPI_FIFOCTL_TX_THRESHOLD_Msk   (7ul << SPI_FIFOCTL_TX_THRESHOLD_Pos)  /*!< SPI FIFOCTL: TX_THRESHOLD Mask */

/* SPI_STATUS Bit Field Definitions */
#define SPI_STATUS_BUSY_Pos            0                                       /*!< SPI STATUS: BUSY Position */
#define SPI_STATUS_BUSY_Msk            (1ul << SPI_STATUS_BUSY_Pos)            /*!< SPI STATUS: BUSY Mask */
#define SPI_STATUS_UNIT_INTSTS_Pos     1                                       /*!< SPI STATUS: UNIT_INTSTS Position */
#define SPI_STATUS_UNIT_INTSTS_Msk     (1ul << SPI_STATUS_UNIT_INTSTS_Pos)     /*!< SPI STATUS: UNIT_INTSTS Mask */
#define SPI_STATUS_SSACT_INTSTS_Pos    2                                       /*!< SPI STATUS: SSACT_INTSTS Position */
#define SPI_STATUS_SSACT_INTSTS_Msk    (1ul << SPI_STATUS_SSACT_INTSTS_Pos)    /*!< SPI STATUS: SSACT_INTSTS Mask */
#define SPI_STATUS_SSINA_INTSTS_Pos    3                                       /*!< SPI STATUS: SSINA_INTSTS Position */
#define SPI_STATUS_SSINA_INTSTS_Msk    (1ul << SPI_STATUS_SSINA_INTSTS_Pos)    /*!< SPI STATUS: SSINA_INTSTS Mask */
#define SPI_STATUS_SS_LINE_Pos         4                                       /*!< SPI STATUS: SS_LINE Position */
#define SPI_STATUS_SS_LINE_Msk         (1ul << SPI_STATUS_SS_LINE_Pos)         /*!< SPI STATUS: SS_LINE Mask */
#define SPI_STATUS_SLVTO_INTSTS_Pos    5                                       /*!< SPI STATUS: SLVTO_INTSTS Position */
#define SPI_STATUS_SLVTO_INTSTS_Msk    (1ul << SPI_STATUS_SLVTO_INTSTS_Pos)    /*!< SPI STATUS: SLVTO_INTSTS Mask */
#define SPI_STATUS_SLVER0_INTSTS_Pos   6                                       /*!< SPI STATUS: SLVER0_INTSTS Position */
#define SPI_STATUS_SLVER0_INTSTS_Msk   (1ul << SPI_STATUS_SLVER0_INTSTS_Pos)   /*!< SPI STATUS: SLVER0_INTSTS Mask */
#define SPI_STATUS_SLVER1_INTSTS_Pos   7                                       /*!< SPI STATUS: SLVER1_INTSTS Position */
#define SPI_STATUS_SLVER1_INTSTS_Msk   (1ul << SPI_STATUS_SLVER1_INTSTS_Pos)   /*!< SPI STATUS: SLVER1_INTSTS Mask */
#define SPI_STATUS_RX_EMPTY_Pos        8                                       /*!< SPI STATUS: RX_EMPTY Position */
#define SPI_STATUS_RX_EMPTY_Msk        (1ul << SPI_STATUS_RX_EMPTY_Pos)        /*!< SPI STATUS: RX_EMPTY Mask */
#define SPI_STATUS_RX_FULL_Pos         9                                       /*!< SPI STATUS: RX_FULL Position */
#define SPI_STATUS_RX_FULL_Msk         (1ul << SPI_STATUS_RX_FULL_Pos)         /*!< SPI STATUS: RX_FULL Mask */
#define SPI_STATUS_RXTH_INTSTS_Pos     10                                      /*!< SPI STATUS: RXTH_INTSTS Position */
#define SPI_STATUS_RXTH_INTSTS_Msk     (1ul << SPI_STATUS_RXTH_INTSTS_Pos)     /*!< SPI STATUS: RXTH_INTSTS Mask */
#define SPI_STATUS_RXOVR_INTSTS_Pos    11                                      /*!< SPI STATUS: RXOVR_INTSTS Position */
#define SPI_STATUS_RXOVR_INTSTS_Msk    (1ul << SPI_STATUS_RXOVR_INTSTS_Pos)    /*!< SPI STATUS: RXOVR_INTSTS Mask */
#define SPI_STATUS_RXTO_INTSTS_Pos     12                                      /*!< SPI STATUS: RXTO_INTSTS Position */
#define SPI_STATUS_RXTO_INTSTS_Msk     (1ul << SPI_STATUS_RXTO_INTSTS_Pos)     /*!< SPI STATUS: RXTO_INTSTS Mask */
#define SPI_STATUS_SPIEN_STS_Pos       15                                      /*!< SPI STATUS: SPIEN_STS Position */
#define SPI_STATUS_SPIEN_STS_Msk       (1ul << SPI_STATUS_SPIEN_STS_Pos)       /*!< SPI STATUS: SPIEN_STS Mask */
#define SPI_STATUS_TX_EMPTY_Pos        16                                      /*!< SPI STATUS: TX_EMPTY Position */
#define SPI_STATUS_TX_EMPTY_Msk        (1ul << SPI_STATUS_TX_EMPTY_Pos)        /*!< SPI STATUS: TX_EMPTY Mask */
#define SPI_STATUS_TX_FULL_Pos         17                                      /*!< SPI STATUS: TX_FULL Position */
#define SPI_STATUS_TX_FULL_Msk         (1ul << SPI_STATUS_TX_FULL_Pos)         /*!< SPI STATUS: TX_FULL Mask */
#define SPI_STATUS_TXTH_INTSTS_Pos     18                                      /*!< SPI STATUS: TXTH_INTSTS Position */
#define SPI_STATUS_TXTH_INTSTS_Msk     (1ul << SPI_STATUS_TXTH_INTSTS_Pos)     /*!< SPI STATUS: TXTH_INTSTS Mask */
#define SPI_STATUS_TXUDR_INTSTS_Pos    19                                      /*!< SPI STATUS: TXUDR_INTSTS Position */
#define SPI_STATUS_TXUDR_INTSTS_Msk    (1ul << SPI_STATUS_TXUDR_INTSTS_Pos)    /*!< SPI STATUS: TXUDR_INTSTS Mask */
#define SPI_STATUS_FFCLR_STS_Pos       23                                      /*!< SPI STATUS: FFCLR_STS Position */
#define SPI_STATUS_FFCLR_STS_Msk       (1ul << SPI_STATUS_FFCLR_STS_Pos)       /*!< SPI STATUS: FFCLR_STS Mask */
#define SPI_STATUS_RX_FIFO_COUNT_Pos   24                                      /*!< SPI STATUS: RX_FIFO_COUNT Position */
#define SPI_STATUS_RX_FIFO_COUNT_Msk   (0xFul << SPI_STATUS_RX_FIFO_COUNT_Pos) /*!< SPI STATUS: RX_FIFO_COUNT Mask */
#define SPI_STATUS_TX_FIFO_COUNT_Pos   28                                      /*!< SPI STATUS: TX_FIFO_COUNT Position */
#define SPI_STATUS_TX_FIFO_COUNT_Msk   (0xFul << SPI_STATUS_TX_FIFO_COUNT_Pos) /*!< SPI STATUS: TX_FIFO_COUNT Mask */

/*@}*/ /* end of group NUC400_SPI */


/*------------- UART -----------------------------*/
/** @addtogroup NUC400_UART NUC400 UART Control Register (UART)
  @{
*/
typedef struct {
    union {
        __IO uint32_t RBR;                        /*!< Offset: 0x0000   Receive Buffer Register                    */
        __IO uint32_t THR;                        /*!< Offset: 0x0000   Transmit Holding Register                  */
    };

    __IO uint32_t IER;                        /*!< Offset: 0x0004   Interrupt Enable Register                  */
    __IO uint32_t FCR;                        /*!< Offset: 0x0008   FIFO Control Register                      */
    __IO uint32_t LCR;                        /*!< Offset: 0x000C   Line Control Register                      */
    __IO uint32_t MCR;                        /*!< Offset: 0x0010   Modem Control Register                     */
    __IO uint32_t MSR;                        /*!< Offset: 0x0014   Modem Status Register                      */
    __IO uint32_t FSR;                        /*!< Offset: 0x0018   FIFO Status Register                       */
    __IO uint32_t ISR;                        /*!< Offset: 0x001C   Interrupt Status Register                  */
    __IO uint32_t TOR;                        /*!< Offset: 0x0020   Time Out Register                          */
    __IO uint32_t BAUD;                       /*!< Offset: 0x0024   Baud Rate Divisor Register                 */
    __IO uint32_t IRCR;                       /*!< Offset: 0x0028   IrDA Control Register                      */
    __IO uint32_t ALT_CSR;                    /*!< Offset: 0x002C   Alternate Control/Status Register          */
    __IO uint32_t FUN_SEL;                    /*!< Offset: 0x0030   Function Select Register                   */
    __IO uint32_t LIN_CTL;                    /*!< Offset: 0x0034   LIN Control Register                       */
    __IO uint32_t LIN_SR;                     /*!< Offset: 0x0038   LIN Status Register                        */
    __IO uint32_t DEBUG;                      /*!< Offset: 0x003C   Debug Register                             */
    __IO uint32_t SC_CTL;                     /*!< Offset: 0x0040   SC Control Register                        */
    __IO uint32_t SC_FSR;                     /*!< Offset: 0x0044   SC Flag Status Register                    */

} UART_T;



/* UART THR Bit Field Definitions */
#define UART_THR_THR_Pos         0                                          /*!< UART THR: THR Position  */
#define UART_THR_THR_Msk        (0xFFul << UART_THR_THR_Pos)                 /*!< UART THR: THR Mask      */

/* UART RBR Bit Field Definitions */
#define UART_RBR_RBR_Pos         0                                          /*!< UART RBR: RBR Position */
#define UART_RBR_RBR_Msk        (0xFFul << UART_RBR_RBR_Pos)                 /*!< UART RBR: RBR Mask      */

/* UART IER Bit Field Definitions */
#define UART_IER_DMA_RX_EN_Pos      15                                      /*!< UART IER: RX DMA Enable Position */
#define UART_IER_DMA_RX_EN_Msk      (1ul << UART_IER_DMA_RX_EN_Pos)         /*!< UART IER: RX DMA Enable Mask      */

#define UART_IER_DMA_TX_EN_Pos      14                                      /*!< UART IER: TX DMA Enable Position */
#define UART_IER_DMA_TX_EN_Msk      (1ul << UART_IER_DMA_TX_EN_Pos)         /*!< UART IER: TX DMA Enable Mask      */

#define UART_IER_AUTO_CTS_EN_Pos    13                                      /*!< UART IER: AUTO_CTS_EN Position      */
#define UART_IER_AUTO_CTS_EN_Msk    (1ul << UART_IER_AUTO_CTS_EN_Pos)       /*!< UART IER: AUTO_CTS_EN Mask           */

#define UART_IER_AUTO_RTS_EN_Pos    12                                      /*!< UART IER: AUTO_RTS_EN Position      */
#define UART_IER_AUTO_RTS_EN_Msk    (1ul << UART_IER_AUTO_RTS_EN_Pos)       /*!< UART IER: AUTO_RTS_EN Mask           */

#define UART_IER_TIME_OUT_EN_Pos    11                                      /*!< UART IER: TIME_OUT_EN Position      */
#define UART_IER_TIME_OUT_EN_Msk    (1ul << UART_IER_TIME_OUT_EN_Pos)       /*!< UART IER: TIME_OUT_EN Mask           */

#define UART_IER_LIN_RX_BRK_IEN_Pos 8                                       /*!< UART IER: LIN_RX_BRK_IEN Position   */
#define UART_IER_LIN_RX_BRK_IEN_Msk (1ul << UART_IER_LIN_RX_BRK_IEN_Pos)    /*!< UART IER: LIN_RX_BRK_IEN Mask        */

#define UART_IER_WAKE_EN_Pos        6                                       /*!< UART IER: WAKE_EN Position          */
#define UART_IER_WAKE_EN_Msk        (1ul << UART_IER_WAKE_EN_Pos)           /*!< UART IER: WAKE_EN Mask               */

#define UART_IER_BUF_ERR_IEN_Pos    5                                       /*!< UART IER: BUF_ERR_IEN Position      */
#define UART_IER_BUF_ERR_IEN_Msk    (1ul << UART_IER_BUF_ERR_IEN_Pos)       /*!< UART IER: BUF_ERR_IEN Mask           */

#define UART_IER_RTO_IEN_Pos        4                                       /*!< UART IER: RTO_IEN Position          */
#define UART_IER_RTO_IEN_Msk        (1ul << UART_IER_RTO_IEN_Pos)           /*!< UART IER: RTO_IEN Mask               */

#define UART_IER_MODEM_IEN_Pos      3                                       /*!< UART IER: MODEM_IEN Position        */
#define UART_IER_MODEM_IEN_Msk      (1ul << UART_IER_MODEM_IEN_Pos)         /*!< UART IER: MODEM_IEN Mask             */

#define UART_IER_RLS_IEN_Pos        2                                       /*!< UART IER: RLS_IEN Position          */
#define UART_IER_RLS_IEN_Msk        (1ul << UART_IER_RLS_IEN_Pos)           /*!< UART IER: RLS_IEN Mask               */

#define UART_IER_THRE_IEN_Pos       1                                       /*!< UART IER: THRE_IEN Position         */
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
#define UART_ISR_HW_LIN_RX_BREAK_INT_Pos   31                                           /*!< UART ISR: HW LIN_RX_BREAK_INT Position       */
#define UART_ISR_HW_LIN_RX_BREAK_INT_Msk   (1ul << UART_ISR_HW_LIN_RX_BREAK_INT_Pos)    /*!< UART ISR: HW LIN_RX_BREAK_INT Mask           */

#define UART_ISR_HW_BUF_ERR_INT_Pos        29                                       /*!< UART ISR: HW BUF_ERR_INT Position       */
#define UART_ISR_HW_BUF_ERR_INT_Msk        (1ul << UART_ISR_HW_BUF_ERR_INT_Pos)     /*!< UART ISR: HW BUF_ERR_INT Mask           */

#define UART_ISR_HW_TOUT_INT_Pos           28                                       /*!< UART ISR: HW TOUT_INT Position          */
#define UART_ISR_HW_TOUT_INT_Msk           (1ul << UART_ISR_HW_TOUT_INT_Pos)        /*!< UART ISR: HW TOUT_INT Mask              */

#define UART_ISR_HW_MODEM_INT_Pos          27                                       /*!< UART ISR: HW MODEM_INT Position         */
#define UART_ISR_HW_MODEM_INT_Msk          (1ul << UART_ISR_HW_MODEM_INT_Pos)       /*!< UART ISR: HW MODEM_INT Mask             */

#define UART_ISR_HW_RLS_INT_Pos            26                                       /*!< UART ISR: HW RLS_INT Position           */
#define UART_ISR_HW_RLS_INT_Msk            (1ul << UART_ISR_HW_RLS_INT_Pos)         /*!< UART ISR: HW RLS_INT Position           */

#define UART_ISR_HW_LIN_RX_BREAK_IF_Pos    23                                       /*!< UART ISR: HW LIN_RX_BREAK_IF Position  */
#define UART_ISR_HW_LIN_RX_BREAK_IF_Msk    (1ul << UART_ISR_HW_LIN_RX_BREAK_IF_Pos) /*!< UART ISR: HW LIN_RX_BREAK_IF Mask      */

#define UART_ISR_HW_BUF_ERR_IF_Pos         21                                       /*!< UART ISR: HW BUF_ERR_IF Position       */
#define UART_ISR_HW_BUF_ERR_IF_Msk         (1ul << UART_ISR_HW_BUF_ERR_IF_Pos)      /*!< UART ISR: HW BUF_ERR_IF Mask           */

#define UART_ISR_HW_TOUT_IF_Pos            20                                       /*!< UART ISR: HW TOUT_IF Position          */
#define UART_ISR_HW_TOUT_IF_Msk            (1ul << UART_ISR_HW_TOUT_IFF_Pos)        /*!< UART ISR: HW TOUT_IF Mask              */

#define UART_ISR_HW_MODEM_IF_Pos           19                                       /*!< UART ISR: HW MODEM_IF Position         */
#define UART_ISR_HW_MODEM_IF_Msk           (1ul << UART_ISR_HW_MODEM_IF_Pos)        /*!< UART ISR: HW MODEM_IF Mask             */

#define UART_ISR_HW_RLS_IF_Pos             18                                       /*!< UART ISR: HW RLS_IF Position           */
#define UART_ISR_HW_RLS_IF_Msk             (1ul << UART_ISR_HW_RLS_IF_Pos)          /*!< UART ISR: HW RLS_IF Mark               */

#define UART_ISR_LIN_RX_BREAK_INT_Pos    15                                      /*!< UART ISR: LIN_RX_BREAK_INT Position       */
#define UART_ISR_LIN_RX_BREAK_INT_Msk    (1ul << UART_ISR_LIN_RX_BREAK_INT_Pos)  /*!< UART ISR: LIN_RX_BREAK_INT Mask           */

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

#define UART_ISR_LIN_RX_BREAK_IF_Pos 7                                      /*!< UART ISR: LIN RX BREAK IF Position   */
#define UART_ISR_LIN_RX_BREAK_IF_Msk (1ul << UART_ISR_LIN_RX_BREAK_IF_Pos)  /*!< UART ISR: LIN RX BREAK IF Mask       */

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

#define UART_ALT_CSR_LIN_TX_EN_Pos      7                                        /*!< UART ALT_CSR: LIN TX Break Mode Enable Position     */
#define UART_ALT_CSR_LIN_TX_EN_Msk      (1ul << UART_ALT_CSR_LIN_TX_EN_Pos)      /*!< UART ALT_CSR: LIN TX Break Mode Enable Mask         */

#define UART_ALT_CSR_LIN_RX_EN_Pos      6                                        /*!< UART ALT_CSR: LIN RX Enable Position     */
#define UART_ALT_CSR_LIN_RX_EN_Msk      (1ul << UART_ALT_CSR_LIN_RX_EN_Pos)      /*!< UART ALT_CSR: LIN RX Enable Mask         */

#define UART_ALT_CSR_UA_LIN_BKFL_Pos    0                                        /*!< UART ALT_CSR: UART LIN Break Field Length Position     */
#define UART_ALT_CSR_UA_LIN_BKFL_Msk    (0xFul << UART_ALT_CSR_UA_LIN_BKFL_Pos)  /*!< UART ALT_CSR: UART LIN Break Field Length Mask         */

/* UART FUN_SEL Bit Field Definitions */
#define UART_FUN_SEL_FUN_SEL_Pos        0                                        /*!< UART FUN_SEL: FUN_SEL Position       */
#define UART_FUN_SEL_FUN_SEL_Msk       (0x3ul << UART_FUN_SEL_FUN_SEL_Pos)       /*!< UART FUN_SEL: FUN_SEL Mask           */

/* UART LIN_CTL Bit Field Definitions */
#define UART_LIN_CTL_LIN_PID_Pos        24                                        /*!< UART LIN_CTL: LIN_PID Position       */
#define UART_LIN_CTL_LIN_PID_Msk        (0xFFul << UART_LIN_CTL_LIN_PID_Pos)      /*!< UART LIN_CTL: LIN_PID Mask           */

#define UART_LIN_CTL_LIN_HEAD_SEL_Pos   22                                        /*!< UART LIN_CTL: LIN_HEAD_SEL Position       */
#define UART_LIN_CTL_LIN_HEAD_SEL_Msk   (0x3ul << UART_LIN_CTL_LIN_HEAD_SEL_Pos)  /*!< UART LIN_CTL: LIN_HEAD_SEL Mask           */

#define UART_LIN_CTL_LIN_BS_LEN_Pos     20                                        /*!< UART LIN_CTL: LIN_BS_LEN Position       */
#define UART_LIN_CTL_LIN_BS_LEN_Msk     (0x3ul << UART_LIN_CTL_LIN_BS_LEN_Pos)    /*!< UART LIN_CTL: LIN_BS_LEN Mask           */

#define UART_LIN_CTL_LIN_BKFL_Pos       16                                        /*!< UART LIN_CTL: LIN_BKFL Position       */
#define UART_LIN_CTL_LIN_BKFL_Msk       (0xFul << UART_LIN_CTL_LIN_BKFL_Pos)      /*!< UART LIN_CTL: LIN_BKFL Mask           */

#define UART_LIN_CTL_BIT_ERR_EN_Pos     12                                        /*!< UART LIN_CTL: BIT_ERR_EN Position       */
#define UART_LIN_CTL_BIT_ERR_EN_Msk     (1ul << UART_LIN_CTL_BIT_ERR_EN_Pos)      /*!< UART LIN_CTL: BIT_ERR_EN Mask           */

#define UART_LIN_CTL_LIN_RX_DIS_Pos     11                                        /*!< UART LIN_CTL: LIN_RX_DIS Position       */
#define UART_LIN_CTL_LIN_RX_DIS_Msk     (1ul << UART_LIN_CTL_LIN_RX_DIS_Pos)      /*!< UART LIN_CTL: LIN_RX_DIS Mask           */

#define UART_LIN_CTL_LIN_BKDET_EN_Pos   10                                        /*!< UART LIN_CTL: LIN_BKDET_EN Position       */
#define UART_LIN_CTL_LIN_BKDET_EN_Msk   (1ul << UART_LIN_CTL_LIN_BKDET_EN_Pos)    /*!< UART LIN_CTL: LIN_BKDET_EN Mask           */

#define UART_LIN_CTL_LIN_IDPEN_Pos      9                                         /*!< UART LIN_CTL: LIN_IDPEN Position       */
#define UART_LIN_CTL_LIN_IDPEN_Msk      (1ul << UART_LIN_CTL_LIN_IDPEN_Pos)       /*!< UART LIN_CTL: LIN_IDPEN Mask           */

#define UART_LIN_CTL_LIN_SHD_Pos        8                                         /*!< UART LIN_CTL: LIN_SHD Position       */
#define UART_LIN_CTL_LIN_SHD_Msk        (1ul << UART_LIN_CTL_LIN_SHD_Pos)         /*!< UART LIN_CTL: LIN_SHD Mask           */

#define UART_LIN_CTL_LIN_WAKE_EN_Pos    4                                          /*!< UART LIN_CTL: LIN_WAKE_EN Position       */
#define UART_LIN_CTL_LIN_WAKE_EN_Msk    (1ul << UART_LIN_CTL_LIN_WAKE_EN_Pos)      /*!< UART LIN_CTL: LIN_WAKE_EN Mask           */

#define UART_LIN_CTL_LINS_DUM_EN_Pos    3                                          /*!< UART LIN_CTL: LINS_DUM_EN Position       */
#define UART_LIN_CTL_LINS_DUM_EN_Msk    (1ul << UART_LIN_CTL_LINS_DUM_EN_Pos)      /*!< UART LIN_CTL: LINS_DUM_EN Mask           */

#define UART_LIN_CTL_LINS_ARS_EN_Pos    2                                          /*!< UART LIN_CTL: LINS_ARS_EN Position       */
#define UART_LIN_CTL_LINS_ARS_EN_Msk    (1ul << UART_LIN_CTL_LINS_ARS_EN_Pos)      /*!< UART LIN_CTL: LINS_ARS_EN Mask           */

#define UART_LIN_CTL_LINS_HDET_EN_Pos   1                                          /*!< UART LIN_CTL: LINS_HDET_EN Position       */
#define UART_LIN_CTL_LINS_HDET_EN_Msk   (1ul << UART_LIN_CTL_LINS_HDET_EN_Pos)     /*!< UART LIN_CTL: LINS_HDET_EN Mask           */

#define UART_LIN_CTL_LINS_EN_Pos        0                                          /*!< UART LIN_CTL: LINS_EN Position       */
#define UART_LIN_CTL_LINS_EN_Msk        (1ul << UART_LIN_CTL_LINS_EN_Pos)          /*!< UART LIN_CTL: LINS_EN Mask           */

/* UART LIN_SR Bit Field Definitions */
#define UART_LIN_SR_LINS_SYNC_F_Pos     3                                           /*!< UART LIN_SR: LINS_SYNC_F Position       */
#define UART_LIN_SR_LINS_SYNC_F_Msk     (1ul << UART_LIN_SR_LINS_SYNC_F_Pos)        /*!< UART LIN_SR: LINS_SYNC_F Mask           */

#define UART_LIN_SR_LINS_IDPERR_F_Pos   2                                           /*!< UART LIN_SR: LINS_IDPERR_F Position       */
#define UART_LIN_SR_LINS_IDPERR_F_Msk   (1ul << UART_LIN_SR_LINS_IDPERR_F_Pos)      /*!< UART LIN_SR: LINS_IDPERR_F Mask           */

#define UART_LIN_SR_LINS_HERR_F_Pos     1                                           /*!< UART LIN_SR: LINS_HERR_F Position       */
#define UART_LIN_SR_LINS_HERR_F_Msk     (1ul << UART_LIN_SR_LINS_HERR_F_Pos)        /*!< UART LIN_SR: LINS_HERR_F Mask           */

#define UART_LIN_SR_LINS_HDET_F_Pos     0                                           /*!< UART LIN_SR: LINS_HDET_F Position       */
#define UART_LIN_SR_LINS_HDET_F_Msk     (1ul << UART_LIN_SR_LINS_HDET_F_Pos)        /*!< UART LIN_SR: LINS_HDET_F Mask           */

/* UART DEBUG Bit Field Definitions */
#define UART_DEBUG_ERR_DIVIA_F_Pos         0                                           /*!< UART DEBUG: ERR_DIVIA_F Position       */
#define UART_DEBUG_ERR_DIVIA_F_Msk         (1ul << UART_DEBUG_ERR_DIVIA_F_Pos)            /*!< UART DEBUG: ERR_DIVIA_F Mask           */

#define UART_DEBUG_ERR_HETIME_OUT_F_Pos 1                                           /*!< UART DEBUG: ERR_HETIME_OUT_F Position  */
#define UART_DEBUG_ERR_HETIME_OUT_F_Msk (1ul << UART_DEBUG_ERR_HETIME_OUT_F_Pos)    /*!< UART DEBUG: ERR_HETIME_OUT_F Mask        */

#define UART_DEBUG_ERR_HEFE_F_Pos         2                                           /*!< UART DEBUG: ERR_HEFE_F Position           */
#define UART_DEBUG_ERR_HEFE_F_Msk         (1ul << UART_DEBUG_ERR_HEFE_F_Pos)            /*!< UART DEBUG: ERR_HEFE_F Mask               */

#define UART_DEBUG_ERR_SYNC_F_Pos         3                                           /*!< UART DEBUG: ERR_SYNC_F Position           */
#define UART_DEBUG_ERR_SYNC_F_Msk         (1ul << UART_DEBUG_ERR_SYNC_F_Pos)            /*!< UART DEBUG: ERR_SYNC_F Mask               */

/* UART SC_CTL Bit Field Definitions */
#define UART_SC_CTL_RX_ERETRY_Pos         0                                              /*!< UART SC_CTL: RX_ERETRY Position           */
#define UART_SC_CTL_RX_ERETRY_Msk         (7ul << UART_SC_CTL_RX_ERETRY_Pos)            /*!< UART SC_CTL: RX_ERETRY Mask               */

#define UART_SC_CTL_RX_ERETRY_EN_Pos    3                                              /*!< UART SC_CTL: RX_ERETRY_EN Position     */
#define UART_SC_CTL_RX_ERETRY_EN_Msk    (1ul << UART_SC_CTL_RX_ERETRY_EN_Pos)       /*!< UART SC_CTL: RX_ERETRY_EN Mask         */

#define UART_SC_CTL_TX_ERETRY_Pos         4                                              /*!< UART SC_CTL: TX_ERETRY Position           */
#define UART_SC_CTL_TX_ERETRY_Msk         (7ul << UART_SC_CTL_TX_ERETRY_Pos)            /*!< UART SC_CTL: TX_ERETRY Mask               */

#define UART_SC_CTL_TX_ERETRY_EN_Pos    7                                              /*!< UART SC_CTL: TX_ERETRY_EN Position     */
#define UART_SC_CTL_TX_ERETRY_EN_Msk    (1ul << UART_SC_CTL_TX_ERETRY_EN_Pos)       /*!< UART SC_CTL: TX_ERETRY_EN Mask         */

/* UART SC_FSR Bit Field Definitions */
#define UART_SC_FSR_RX_OVER_ERETRY_Pos         0                                       /*!< UART SC_FSR: RX_OVER_ERETRY Position      */
#define UART_SC_FSR_RX_OVER_ERETRY_Msk         (1ul << UART_SC_FSR_RX_OVER_ERETRY_Pos) /*!< UART SC_FSR: RX_OVER_ERETRY Mask          */

#define UART_SC_FSR_TX_OVER_ERETRY_Pos         1                                       /*!< UART SC_FSR: TX_OVER_ERETRY Position      */
#define UART_SC_FSR_TX_OVER_ERETRY_Msk         (1ul << UART_SC_FSR_TX_OVER_ERETRY_Pos) /*!< UART SC_FSR: TX_OVER_ERETRY Mask          */

#define UART_SC_FSR_RX_ERETRY_F_Pos         8                                       /*!< UART SC_FSR: RX_ERETRY_F Position      */
#define UART_SC_FSR_RX_ERETRY_F_Msk         (1ul << UART_SC_FSR_RX_ERETRY_F_Pos)     /*!< UART SC_FSR: RX_ERETRY_F Mask          */

#define UART_SC_FSR_TX_ERETRY_F_Pos         9                                       /*!< UART SC_FSR: TX_ERETRY_F Position      */
#define UART_SC_FSR_TX_ERETRY_F_Msk         (1ul << UART_SC_FSR_TX_ERETRY_F_Pos)     /*!< UART SC_FSR: TX_ERETRY_F Mask          */

/*@}*/ /* end of group NUC400_UART */

/*------------- I2C Serial Interface Controller (Master/Slave) (I2C) -----------------------------*/
/** @addtogroup NUC400_I2C NUC400 I2C Controller Register (I2C)
  @{
*/
typedef struct {
    __IO uint32_t I2CON;                     /*!< Offset: 0x0000   I2C Control Register                               */
    __IO uint32_t I2CADDR0;                  /*!< Offset: 0x0004   I2C Slave Address Register0                        */
    __IO uint32_t I2CDAT;                    /*!< Offset: 0x0008   I2C DATA Register                                  */
    __IO  uint32_t I2CSTATUS;                /*!< Offset: 0x000C   I2C Status Register                                */
    __IO uint32_t I2CLK;                     /*!< Offset: 0x0010   I2C Clock Divided Register                         */
    __IO uint32_t I2CTOC;                    /*!< Offset: 0x0014   I2C Time Out Control Register                      */
    __IO uint32_t I2CADDR1;                  /*!< Offset: 0x0018   I2C Slave Address Register1                        */
    __IO uint32_t I2CADDR2;                  /*!< Offset: 0x001C   I2C Slave Address Register2                        */
    __IO uint32_t I2CADDR3;                  /*!< Offset: 0x0020   I2C Slave Address Register3                        */
    __IO uint32_t I2CADM0;                   /*!< Offset: 0x0024   I2C Slave Address Mask Register0                   */
    __IO uint32_t I2CADM1;                   /*!< Offset: 0x0028   I2C Slave Address Mask Register1                   */
    __IO uint32_t I2CADM2;                   /*!< Offset: 0x002C   I2C Slave Address Mask Register2                   */
    __IO uint32_t I2CADM3;                   /*!< Offset: 0x0030   I2C Slave Address Mask Register3                   */
    __IO uint32_t I2CWKCON;                  /*!< Offset: 0x003C   I2C Wakeup Control Register                        */
    __IO uint32_t I2CWKSTS;                  /*!< Offset: 0x0040   I2C Wakeup Status Register                         */
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
#define I2C_I2CWKCON_WKUPEN_Pos                 0                                       /*!< I2C I2CWKUPCON: WKUPEN Position */
#define I2C_I2CWKCON_WKUPEN_Msk                 (1ul << I2C_I2CWKCON_WKUPEN_Pos)        /*!< I2C I2CWKUPCON: WKUPEN Mask */

/* I2C I2CWKUPSTS Bit Field Definitions */
#define I2C_I2CWKSTS_WKUPIF_Pos                 0                                       /*!< I2C I2CWKUPSTS: WKUPIF Position */
#define I2C_I2CWKSTS_WKUPIF_Msk                 (1ul << I2C_I2CWKSTS_WKUPIF_Pos)        /*!< I2C I2CWKUPSTS: WKUPIF Mask */

/*@}*/ /* end of group NUC400_I2C */

/*------------- Smart Card Control Register (SC) -----------------------------*/
/** @addtogroup NUC400_SC NUC400 Smart Card Control Register (SC)
  @{
*/
/**
  * @brief SC register map
  */
typedef struct {
    union {
        __I  uint32_t  RBR;                         /*!< Offset: 0x0000  SC Receiving Buffer Register                          */
        __O  uint32_t  THR;                         /*!< Offset: 0x0000  SC Transmit Holding Register                          */
    };
    __IO uint32_t  CTL;                         /*!< Offset: 0x0004  SC Control Register                                   */
    __IO uint32_t  ALTCTL;                      /*!< Offset: 0x0008  SC Alternate Control State Register                   */
    __IO uint32_t  EGTR;                        /*!< Offset: 0x000C  SC Extend Guard Time Register                         */
    __IO uint32_t  RFTMR;                       /*!< Offset: 0x0010  SC Receiver Buffer Time-Out Register                  */
    __IO uint32_t  ETUCR;                       /*!< Offset: 0x0014  SC ETU Control Register                               */
    __IO uint32_t  IER;                         /*!< Offset: 0x0018  SC Interrupt Enable Register                          */
    __IO uint32_t  ISR;                         /*!< Offset: 0x001C  SC Interrupt Status Register (Read Only)              */
    __IO uint32_t  SR;                          /*!< Offset: 0x0020  SC Status Register (Read Only)                        */
    __IO uint32_t  PINCSR;                      /*!< Offset: 0x0024  SC Pin Control State Register                         */
    __IO uint32_t  TMR0;                        /*!< Offset: 0x0028  SC Internal Timer Control Register 0                  */
    __IO uint32_t  TMR1;                        /*!< Offset: 0x002C  SC Internal Timer Control Register 1                  */
    __IO uint32_t  TMR2;                        /*!< Offset: 0x0030  SC Internal Timer Control Register 2                  */
    __IO uint32_t  UACTL;                       /*!< Offset: 0x0034  SC UART Control Register                              */
    __I  uint32_t  TDRA;                        /*!< Offset: 0x0038  SC Timer Current Data Register A                      */
    __I  uint32_t  TDRB;                        /*!< Offset: 0x003C  SC Timer Current Data Register B                      */
} SC_T;


/* SC RBR Bit Field Definitions */
#define SC_RBR_RBR_Pos                      0                                /*!< SC RBR: RBR Position */
#define SC_RBR_RBR_Msk                      (0xFFul << SC_RBR_RBR_Pos)       /*!< SC RBR: RBR Mask     */

/* SC THR Bit Field Definitions */
#define SC_THR_THR_Pos                      0                                /*!< SC THR: THR Position */
#define SC_THR_THR_Msk                      (0xFFul << SC_THR_THR_Pos)       /*!< SC THR: THR Mask     */

/* SC CTL Bit Field Definitions */
#define SC_CTL_SYNC_Pos                     30                               /*!< SC CTL: SYNC Position */
#define SC_CTL_SYNC_Msk                     (1ul << SC_CTL_SYNC_Pos)         /*!< SC CTL: SYNC Mask     */

#define SC_CTL_CD_LEV_Pos                   26                               /*!< SC CTL: CD_LEV Position */
#define SC_CTL_CD_LEV_Msk                   (1ul << SC_CTL_CD_LEV_Pos)       /*!< SC CTL: CD_LEV Mask     */

#define SC_CTL_CD_DEB_SEL_Pos               24                               /*!< SC CTL: CD_DEB_SEL Position */
#define SC_CTL_CD_DEB_SEL_Msk               (3ul << SC_CTL_CD_DEB_SEL_Pos)   /*!< SC CTL: CD_DEB_SEL Mask     */

#define SC_CTL_TX_ERETRY_EN_Pos             23                               /*!< SC CTL: TX_ERETRY_EN Position */
#define SC_CTL_TX_ERETRY_EN_Msk             (1ul << SC_CTL_TX_ERETRY_EN_Pos) /*!< SC CTL: TX_ERETRY_EN Mask     */

#define SC_CTL_TX_ERETRY_Pos                20                               /*!< SC CTL: TX_ERETRY Position */
#define SC_CTL_TX_ERETRY_Msk                (7ul << SC_CTL_TX_ERETRY_Pos)    /*!< SC CTL: TX_ERETRY Mask     */

#define SC_CTL_RX_ERETRY_EN_Pos             19                               /*!< SC CTL: RX_ERETRY_EN Position */
#define SC_CTL_RX_ERETRY_EN_Msk             (1ul << SC_CTL_RX_ERETRY_EN_Pos) /*!< SC CTL: RX_ERETRY_EN Mask     */

#define SC_CTL_RX_ERETRY_Pos                16                               /*!< SC CTL: RX_ERETRY Position */
#define SC_CTL_RX_ERETRY_Msk                (7ul << SC_CTL_RX_ERETRY_Pos)    /*!< SC CTL: RX_ERETRY Mask     */

#define SC_CTL_SLEN_Pos                     15                               /*!< SC CTL: SLEN Position */
#define SC_CTL_SLEN_Msk                     (1ul << SC_CTL_SLEN_Pos)         /*!< SC CTL: SLEN Mask     */

#define SC_CTL_TMR_SEL_Pos                  13                               /*!< SC CTL: TMR_SEL Position */
#define SC_CTL_TMR_SEL_Msk                  (3ul << SC_CTL_TMR_SEL_Pos)      /*!< SC CTL: TMR_SEL Mask     */

#define SC_CTL_BGT_Pos                      8                                /*!< SC CTL: BGT Position */
#define SC_CTL_BGT_Msk                      (0x1Ful << SC_CTL_BGT_Pos)       /*!< SC CTL: BGT Mask     */

#define SC_CTL_RX_FTRI_LEV_Pos              6                                /*!< SC CTL: RX_FTRI_LEV Position */
#define SC_CTL_RX_FTRI_LEV_Msk              (3ul << SC_CTL_RX_FTRI_LEV_Pos)  /*!< SC CTL: RX_FTRI_LEV Mask     */

#define SC_CTL_CON_SEL_Pos                  4                                /*!< SC CTL: CON_SEL Position */
#define SC_CTL_CON_SEL_Msk                  (3ul << SC_CTL_CON_SEL_Pos)      /*!< SC CTL: CON_SEL Mask     */

#define SC_CTL_AUTO_CON_EN_Pos              3                                /*!< SC CTL: AUTO_CON_EN Position */
#define SC_CTL_AUTO_CON_EN_Msk              (1ul << SC_CTL_AUTO_CON_EN_Pos)  /*!< SC CTL: AUTO_CON_EN Mask     */

#define SC_CTL_DIS_TX_Pos                   2                                /*!< SC CTL: DIS_TX Position */
#define SC_CTL_DIS_TX_Msk                   (1ul << SC_CTL_DIS_TX_Pos)       /*!< SC CTL: DIS_TX Mask     */

#define SC_CTL_DIS_RX_Pos                   1                                /*!< SC CTL: DIS_RX Position */
#define SC_CTL_DIS_RX_Msk                   (1ul << SC_CTL_DIS_RX_Pos)       /*!< SC CTL: DIS_RX Mask     */

#define SC_CTL_SC_CEN_Pos                   0                                /*!< SC CTL: SC_CEN Position */
#define SC_CTL_SC_CEN_Msk                   (1ul << SC_CTL_SC_CEN_Pos)       /*!< SC CTL: SC_CEN Mask     */

/* SC ALTCTL Bit Field Definitions */
#define SC_ALTCTL_TMR2_ATV_Pos              15                               /*!< SC ALTCTL: TMR2_ATV Position */
#define SC_ALTCTL_TMR2_ATV_Msk              (1ul << SC_ALTCTL_TMR2_ATV_Pos)  /*!< SC ALTCTL: TMR2_ATV Mask     */

#define SC_ALTCTL_TMR1_ATV_Pos              14                               /*!< SC ALTCTL: TMR1_ATV Position */
#define SC_ALTCTL_TMR1_ATV_Msk              (1ul << SC_ALTCTL_TMR1_ATV_Pos)  /*!< SC ALTCTL: TMR1_ATV Mask     */

#define SC_ALTCTL_TMR0_ATV_Pos              13                               /*!< SC ALTCTL: TMR0_ATV Position */
#define SC_ALTCTL_TMR0_ATV_Msk              (1ul << SC_ALTCTL_TMR0_ATV_Pos)  /*!< SC ALTCTL: TMR0_ATV Mask     */

#define SC_ALTCTL_RX_BGT_EN_Pos             12                               /*!< SC ALTCTL: RX_BGT_EN Position */
#define SC_ALTCTL_RX_BGT_EN_Msk             (1ul << SC_ALTCTL_RX_BGT_EN_Pos) /*!< SC ALTCTL: RX_BGT_EN Mask     */

#define SC_ALTCTL_ADAC_CD_EN_Pos            11                               /*!< SC ALTCTL: ADAC_CD_EN Position */
#define SC_ALTCTL_ADAC_CD_EN_Msk            (1ul << SC_ALTCTL_ADAC_CD_EN_Pos) /*!< SC ALTCTL: ADAC_CD_EN Mask    */

#define SC_ALTCTL_INIT_SEL_Pos              8                                /*!< SC ALTCTL: INIT_SEL Position */
#define SC_ALTCTL_INIT_SEL_Msk              (3ul << SC_ALTCTL_INIT_SEL_Pos)  /*!< SC ALTCTL: INIT_SEL Mask     */

#define SC_ALTCTL_TMR2_SEN_Pos              7                                /*!< SC ALTCTL: TMR2_SEN Position */
#define SC_ALTCTL_TMR2_SEN_Msk              (1ul << SC_ALTCTL_TMR2_SEN_Pos)  /*!< SC ALTCTL: TMR2_SEN Mask     */

#define SC_ALTCTL_TMR1_SEN_Pos              6                                /*!< SC ALTCTL: TMR1_SEN Position */
#define SC_ALTCTL_TMR1_SEN_Msk              (1ul << SC_ALTCTL_TMR1_SEN_Pos)  /*!< SC ALTCTL: TMR1_SEN Mask     */

#define SC_ALTCTL_TMR0_SEN_Pos              5                                /*!< SC ALTCTL: TMR0_SEN Position */
#define SC_ALTCTL_TMR0_SEN_Msk              (1ul << SC_ALTCTL_TMR0_SEN_Pos)  /*!< SC ALTCTL: TMR0_SEN Mask     */

#define SC_ALTCTL_WARST_EN_Pos              4                                /*!< SC ALTCTL: WARST_EN Position */
#define SC_ALTCTL_WARST_EN_Msk              (1ul << SC_ALTCTL_WARST_EN_Pos)  /*!< SC ALTCTL: WARST_EN Mask     */

#define SC_ALTCTL_ACT_EN_Pos                3                                /*!< SC ALTCTL: ACT_EN Position */
#define SC_ALTCTL_ACT_EN_Msk                (1ul << SC_ALTCTL_ACT_EN_Pos)    /*!< SC ALTCTL: ACT_EN Mask     */

#define SC_ALTCTL_DACT_EN_Pos               2                                /*!< SC ALTCTL: DACT_EN Position */
#define SC_ALTCTL_DACT_EN_Msk               (1ul << SC_ALTCTL_DACT_EN_Pos)   /*!< SC ALTCTL: DACT_EN Mask     */

#define SC_ALTCTL_RX_RST_Pos                1                                /*!< SC ALTCTL: RX_RST Position */
#define SC_ALTCTL_RX_RST_Msk                (1ul << SC_ALTCTL_RX_RST_Pos)    /*!< SC ALTCTL: RX_RST Mask     */

#define SC_ALTCTL_TX_RST_Pos                0                                /*!< SC ALTCTL: TX_RST Position */
#define SC_ALTCTL_TX_RST_Msk                (1ul << SC_ALTCTL_TX_RST_Pos)    /*!< SC ALTCTL: TX_RST Mask     */

/* SC EGTR Bit Field Definitions */
#define SC_EGTR_EGT_Pos                     0                               /*!< SC EGTR: EGT Position */
#define SC_EGTR_EGT_Msk                     (0xFFul << SC_EGTR_EGT_Pos)     /*!< SC EGTR: EGT Mask     */

/* SC RFTMR Bit Field Definitions */
#define SC_RFTMR_RFTM_Pos                   0                               /*!< SC RFTMR: RFTM Position */
#define SC_RFTMR_RFTM_Msk                   (0x1FFul << SC_RFTMR_RFTM_Pos)  /*!< SC RFTMR: RFTM Mask     */

/* SC ETUCR Bit Field Definitions */
#define SC_ETUCR_COMPEN_EN_Pos              15                               /*!< SC ETUCR: COMPEN_EN Position */
#define SC_ETUCR_COMPEN_EN_Msk              (1ul << SC_ETUCR_COMPEN_EN_Pos)  /*!< SC ETUCR: COMPEN_EN Mask     */

#define SC_ETUCR_ETU_RDIV_Pos               0                                   /*!< SC ETUCR: ETU_RDIV Position */
#define SC_ETUCR_ETU_RDIV_Msk               (0xFFFul << SC_ETUCR_ETU_RDIV_Pos)  /*!< SC ETUCR: ETU_RDIV Mask     */

/* SC IER Bit Field Definitions */
#define SC_IER_ACON_ERR_IE_Pos              10                                  /*!< SC IER: ACON_ERR_IE Position */
#define SC_IER_ACON_ERR_IE_Msk              (1ul << SC_IER_ACON_ERR_IE_Pos)     /*!< SC IER: ACON_ERR_IE Mask     */

#define SC_IER_RTMR_IE_Pos                  9                               /*!< SC IER: RTMR_IE Position */
#define SC_IER_RTMR_IE_Msk                  (1ul << SC_IER_RTMR_IE_Pos)     /*!< SC IER: RTMR_IE Mask     */

#define SC_IER_INIT_IE_Pos                  8                               /*!< SC IER: INIT_IE Position */
#define SC_IER_INIT_IE_Msk                  (1ul << SC_IER_INIT_IE_Pos)     /*!< SC IER: INIT_IE Mask     */

#define SC_IER_CD_IE_Pos                    7                               /*!< SC IER: CD_IE Position */
#define SC_IER_CD_IE_Msk                    (1ul << SC_IER_CD_IE_Pos)       /*!< SC IER: CD_IE Mask     */

#define SC_IER_BGT_IE_Pos                   6                               /*!< SC IER: BGT_IE Position */
#define SC_IER_BGT_IE_Msk                   (1ul << SC_IER_BGT_IE_Pos)      /*!< SC IER: BGT_IE Mask     */

#define SC_IER_TMR2_IE_Pos                  5                               /*!< SC IER: TMR2_IE Position */
#define SC_IER_TMR2_IE_Msk                  (1ul << SC_IER_TMR2_IE_Pos)     /*!< SC IER: TMR2_IE Mask     */

#define SC_IER_TMR1_IE_Pos                  4                               /*!< SC IER: TMR1_IE Position */
#define SC_IER_TMR1_IE_Msk                  (1ul << SC_IER_TMR1_IE_Pos)     /*!< SC IER: TMR1_IE Mask     */

#define SC_IER_TMR0_IE_Pos                  3                               /*!< SC IER: TMR0_IE Position */
#define SC_IER_TMR0_IE_Msk                  (1ul << SC_IER_TMR0_IE_Pos)     /*!< SC IER: TMR0_IE Mask     */

#define SC_IER_TERR_IE_Pos                  2                               /*!< SC IER: TERR_IE Position */
#define SC_IER_TERR_IE_Msk                  (1ul << SC_IER_TERR_IE_Pos)     /*!< SC IER: TERR_IE Mask     */

#define SC_IER_TBE_IE_Pos                   1                               /*!< SC IER: TBE_IE Position */
#define SC_IER_TBE_IE_Msk                   (1ul << SC_IER_TBE_IE_Pos)      /*!< SC IER: TBE_IE Mask     */

#define SC_IER_RDA_IE_Pos                   0                               /*!< SC IER: RDA_IE Position */
#define SC_IER_RDA_IE_Msk                   (1ul << SC_IER_RDA_IE_Pos)      /*!< SC IER: RDA_IE Mask     */

/* SC ISR Bit Field Definitions */
#define SC_ISR_ACON_ERR_IS_Pos              10                              /*!< SC ISR: ACON_ERR_IS Position */
#define SC_ISR_ACON_ERR_IS_Msk              (1ul << SC_ISR_ACON_ERR_IS_Pos) /*!< SC ISR: ACON_ERR_IS Mask     */

#define SC_ISR_RTMR_IS_Pos                  9                               /*!< SC ISR: RTMR_IS Position */
#define SC_ISR_RTMR_IS_Msk                  (1ul << SC_ISR_RTMR_IS_Pos)     /*!< SC ISR: RTMR_IS Mask     */

#define SC_ISR_INIT_IS_Pos                  8                               /*!< SC ISR: INIT_IS Position */
#define SC_ISR_INIT_IS_Msk                  (1ul << SC_ISR_INIT_IS_Pos)     /*!< SC ISR: INIT_IS Mask     */

#define SC_ISR_CD_IS_Pos                    7                               /*!< SC ISR: CD_IS Position */
#define SC_ISR_CD_IS_Msk                    (1ul << SC_ISR_CD_IS_Pos)       /*!< SC ISR: CD_IS Mask     */

#define SC_ISR_BGT_IS_Pos                   6                               /*!< SC ISR: BGT_IS Position */
#define SC_ISR_BGT_IS_Msk                   (1ul << SC_ISR_BGT_IS_Pos)      /*!< SC ISR: BGT_IS Mask     */

#define SC_ISR_TMR2_IS_Pos                  5                               /*!< SC ISR: TMR2_IS Position */
#define SC_ISR_TMR2_IS_Msk                  (1ul << SC_ISR_TMR2_IS_Pos)     /*!< SC ISR: TMR2_IS Mask     */

#define SC_ISR_TMR1_IS_Pos                  4                               /*!< SC ISR: TMR1_IS Position */
#define SC_ISR_TMR1_IS_Msk                  (1ul << SC_ISR_TMR1_IS_Pos)     /*!< SC ISR: TMR1_IS Mask     */

#define SC_ISR_TMR0_IS_Pos                  3                               /*!< SC ISR: TMR0_IS Position */
#define SC_ISR_TMR0_IS_Msk                  (1ul << SC_ISR_TMR0_IS_Pos)     /*!< SC ISR: TMR0_IS Mask     */

#define SC_ISR_TERR_IS_Pos                  2                               /*!< SC ISR: TERR_IS Position */
#define SC_ISR_TERR_IS_Msk                  (1ul << SC_ISR_TERR_IS_Pos)     /*!< SC ISR: TERR_IS Mask     */

#define SC_ISR_TBE_IS_Pos                   1                               /*!< SC ISR: TXBE_IS Position */
#define SC_ISR_TBE_IS_Msk                   (1ul << SC_ISR_TBE_IS_Pos)      /*!< SC ISR: TXBE_IS Mask     */

#define SC_ISR_RDA_IS_Pos                   0                               /*!< SC ISR: RDA_IS Position */
#define SC_ISR_RDA_IS_Msk                   (1ul << SC_ISR_RDA_IS_Pos)      /*!< SC ISR: RDA_IS Mask     */


/* SC SR Bit Field Definitions */
#define SC_SR_TX_ATV_Pos                  31                                /*!< SC SR: TX_ATV Position */
#define SC_SR_TX_ATV_Msk                  (1ul << SC_SR_TX_ATV_Pos)         /*!< SC SR: TX_ATV Mask     */

#define SC_SR_TX_OVER_REERR_Pos           30                                /*!< SC SR: TX_OVER_REERR Position */
#define SC_SR_TX_OVER_REERR_Msk           (1ul << SC_SR_TX_OVER_REERR_Pos)  /*!< SC SR: TX_OVER_REERR Mask     */

#define SC_SR_TX_REERR_Pos                29                                /*!< SC SR: TX_REERR Position */
#define SC_SR_TX_REERR_Msk                (1ul << SC_SR_TX_REERR_Pos)       /*!< SC SR: TX_REERR Mask     */

#define SC_SR_TX_POINT_F_Pos              24                                /*!< SC SR: TX_POINT_F Position */
#define SC_SR_TX_POINT_F_Msk              (7ul << SC_SR_TX_POINT_F_Pos)     /*!< SC SR: TX_POINT_F Mask     */

#define SC_SR_RX_ATV_Pos                  23                                /*!< SC SR: RX_ATV Position */
#define SC_SR_RX_ATV_Msk                  (1ul << SC_SR_RX_ATV_Pos)         /*!< SC SR: RX_ATV Mask     */

#define SC_SR_RX_OVER_REERR_Pos           22                                /*!< SC SR: RX_OVER_REERR Position */
#define SC_SR_RX_OVER_REERR_Msk           (1ul << SC_SR_RX_OVER_REERR_Pos)  /*!< SC SR: RX_OVER_REERR Mask     */

#define SC_SR_RX_REERR_Pos                21                                /*!< SC SR: RX_REERR Position */
#define SC_SR_RX_REERR_Msk                (1ul << SC_SR_RX_REERR_Pos)       /*!< SC SR: RX_REERR Mask     */

#define SC_SR_RX_POINT_F_Pos              16                                /*!< SC SR: RX_POINT_F Position */
#define SC_SR_RX_POINT_F_Msk              (7ul << SC_SR_RX_POINT_F_Pos)     /*!< SC SR: RX_POINT_F Mask     */

#define SC_SR_CD_PIN_ST_Pos               13                                /*!< SC SR: CD_PIN_ST Position */
#define SC_SR_CD_PIN_ST_Msk               (1ul << SC_SR_CD_PIN_ST_Pos)      /*!< SC SR: CD_PIN_ST Mask     */

#define SC_SR_CD_INS_F_Pos                12                                /*!< SC SR: CD_INS_F Position */
#define SC_SR_CD_INS_F_Msk                (1ul << SC_SR_CD_INS_F_Pos)       /*!< SC SR: CD_INS_F Mask     */

#define SC_SR_CD_REM_F_Pos                11                                /*!< SC SR: CD_REM_F Position */
#define SC_SR_CD_REM_F_Msk                (1ul << SC_SR_CD_REM_F_Pos)       /*!< SC SR: CD_REM_F Mask     */

#define SC_SR_TX_FULL_F_Pos               10                                /*!< SC SR: TX_FULL_F Position */
#define SC_SR_TX_FULL_F_Msk               (1ul << SC_SR_TX_FULL_F_Pos)      /*!< SC SR: TX_FULL_F Mask     */

#define SC_SR_TX_EMPTY_F_Pos              9                                 /*!< SC SR: TX_EMPTY_F Position */
#define SC_SR_TX_EMPTY_F_Msk              (1ul << SC_SR_TX_EMPTY_F_Pos)     /*!< SC SR: TX_EMPTY_F Mask     */

#define SC_SR_TX_OVER_F_Pos               8                                 /*!< SC SR: TX_OVER_F Position */
#define SC_SR_TX_OVER_F_Msk               (1ul << SC_SR_TX_OVER_F_Pos)      /*!< SC SR: TX_OVER_F Mask     */

#define SC_SR_RX_EBR_F_Pos                6                                 /*!< SC SR: RX_EBR_F Position */
#define SC_SR_RX_EBR_F_Msk                (1ul << SC_SR_RX_EBR_F_Pos)       /*!< SC SR: RX_EBR_F Mask     */

#define SC_SR_RX_EFR_F_Pos                5                                 /*!< SC SR: RX_EFR_F Position */
#define SC_SR_RX_EFR_F_Msk                (1ul << SC_SR_RX_EFR_F_Pos)       /*!< SC SR: RX_EFR_F Mask     */

#define SC_SR_RX_EPA_F_Pos                4                                 /*!< SC SR: RX_EPA_F Position */
#define SC_SR_RX_EPA_F_Msk                (1ul << SC_SR_RX_EPA_F_Pos)       /*!< SC SR: RX_EPA_F Mask     */

#define SC_SR_RX_FULL_F_Pos               2                                 /*!< SC SR: RX_FULL_F Position */
#define SC_SR_RX_FULL_F_Msk               (1ul << SC_SR_RX_FULL_F_Pos)      /*!< SC SR: RX_FULL_F Mask     */

#define SC_SR_RX_EMPTY_F_Pos              1                                 /*!< SC SR: RX_EMPTY_F Position */
#define SC_SR_RX_EMPTY_F_Msk              (1ul << SC_SR_RX_EMPTY_F_Pos)     /*!< SC SR: RX_EMPTY_F Mask     */

#define SC_SR_RX_OVER_F_Pos               0                                 /*!< SC SR: RX_OVER_F Position */
#define SC_SR_RX_OVER_F_Msk               (1ul << SC_SR_RX_OVER_F_Pos)      /*!< SC SR: RX_OVER_F Mask     */

/* SC PINCSR Bit Field Definitions */
#define SC_PINCSR_SYNC_Pos                  30                                  /*!< SC PINCSR: SYNC Position */
#define SC_PINCSR_SYNC_Msk                  (1ul << SC_PINCSR_SYNC_Pos)         /*!< SC PINCSR: SYNC Mask     */

#define SC_PINCSR_RST_ST_Pos                18                                  /*!< SC PINCSR: RST_ST Position */
#define SC_PINCSR_RST_ST_Msk                (1ul << SC_PINCSR_RST_ST_Pos)       /*!< SC PINCSR: RST_ST Mask     */

#define SC_PINCSR_PWR_ST_Pos                17                                  /*!< SC PINCSR: PWR_ST Position */
#define SC_PINCSR_PWR_ST_Msk                (1ul << SC_PINCSR_PWR_ST_Pos)       /*!< SC PINCSR: PWR_ST Mask     */

#define SC_PINCSR_DAT_ST_Pos                16                                  /*!< SC PINCSR: DAT_ST Position */
#define SC_PINCSR_DAT_ST_Msk                (1ul << SC_PINCSR_DAT_ST_Pos)       /*!< SC PINCSR: DAT_ST Mask     */

#define SC_PINCSR_POW_INV_Pos               11                                  /*!< SC PINCSR: POW_INV Position */
#define SC_PINCSR_POW_INV_Msk               (1ul << SC_PINCSR_POW_INV_Pos)      /*!< SC PINCSR: POW_INV Mask     */

#define SC_PINCSR_SC_DATA_O_Pos             9                                   /*!< SC PINCSR: SC_DATA_O Position */
#define SC_PINCSR_SC_DATA_O_Msk             (1ul << SC_PINCSR_SC_DATA_O_Pos)    /*!< SC PINCSR: SC_DATA_O Mask     */

#define SC_PINCSR_SC_OEN_ST_Pos             8                                   /*!< SC PINCSR: SC_OEN_ST Position */
#define SC_PINCSR_SC_OEN_ST_Msk             (1ul << SC_PINCSR_SC_OEN_ST_Pos)    /*!< SC PINCSR: SC_OEN_ST Mask     */

#define SC_PINCSR_CLK_KEEP_Pos              6                                   /*!< SC PINCSR: CLK_KEEP Position */
#define SC_PINCSR_CLK_KEEP_Msk              (1ul << SC_PINCSR_CLK_KEEP_Pos)     /*!< SC PINCSR: CLK_KEEP Mask     */

#define SC_PINCSR_SC_RST_Pos                1                                   /*!< SC PINCSR: SC_RST Position */
#define SC_PINCSR_SC_RST_Msk                (1ul << SC_PINCSR_SC_RST_Pos)       /*!< SC PINCSR: SC_RST Mask     */

#define SC_PINCSR_POW_EN_Pos                0                                   /*!< SC PINCSR: POW_EN Position */
#define SC_PINCSR_POW_EN_Msk                (1ul << SC_PINCSR_POW_EN_Pos)       /*!< SC PINCSR: POW_EN Mask     */

/* SC TMR0 Bit Field Definitions */
#define SC_TMR0_MODE_Pos                    24                              /*!< SC TMR0: MODE Position */
#define SC_TMR0_MODE_Msk                    (0xFul << SC_TMR0_MODE_Pos)     /*!< SC TMR0: MODE Mask     */

#define SC_TMR0_CNT_Pos                     0                               /*!< SC TMR0: CNT Position */
#define SC_TMR0_CNT_Msk                     (0xFFFFFFul << SC_TMR0_CNT_Pos) /*!< SC TMR0: CNT Mask     */

/* SC TMR1 Bit Field Definitions */
#define SC_TMR1_MODE_Pos                    24                              /*!< SC TMR1: MODE Position */
#define SC_TMR1_MODE_Msk                    (0xFul << SC_TMR1_MODE_Pos)     /*!< SC TMR1: MODE Mask     */

#define SC_TMR1_CNT_Pos                     0                               /*!< SC TMR1: CNT Position */
#define SC_TMR1_CNT_Msk                     (0xFFul << SC_TMR1_CNT_Pos)     /*!< SC TMR1: CNT Mask     */

/* SC TMR2 Bit Field Definitions */
#define SC_TMR2_MODE_Pos                    24                              /*!< SC TMR2: MODE Position */
#define SC_TMR2_MODE_Msk                    (0xFul << SC_TMR2_MODE_Pos)     /*!< SC TMR2: MODE Mask     */

#define SC_TMR2_CNT_Pos                     0                               /*!< SC TMR2: CNT Position */
#define SC_TMR2_CNT_Msk                     (0xFFul << SC_TMR2_CNT_Pos)     /*!< SC TMR2: CNT Mask     */

/* SC UACTL Bit Field Definitions */
#define SC_UACTL_OPE_Pos                    7                               /*!< SC UACTL: OPE Position */
#define SC_UACTL_OPE_Msk                    (0x1ul << SC_UACTL_OPE_Pos)     /*!< SC UACTL: OPE Mask     */

#define SC_UACTL_PBDIS_Pos                  6                               /*!< SC UACTL: PBDIS Position */
#define SC_UACTL_PBDIS_Msk                  (0x1ul << SC_UACTL_PBDIS_Pos)   /*!< SC UACTL: PBDIS Mask     */

#define SC_UACTL_DATA_LEN_Pos               5                                   /*!< SC UACTL: DATA_LEN Position */
#define SC_UACTL_DATA_LEN_Msk               (0x1ul << SC_UACTL_DATA_LEN_Pos)    /*!< SC UACTL: DATA_LEN Mask     */

#define SC_UACTL_UA_MODE_EN_Pos             0                                   /*!< SC UACTL: UA_MODE_EN Position */
#define SC_UACTL_UA_MODE_EN_Msk             (0x1ul << SC_UACTL_UA_MODE_EN_Pos)  /*!< SC UACTL: UA_MODE_EN Mask     */

/* SC TDRA Bit Field Definitions */
#define SC_TDRA_TDR0_Pos                    0                                   /*!< SC TDRA: TDR0 Position */
#define SC_TDRA_TDR0_Msk                    (0xFFFFFFul << SC_TDRA_TDR0_Pos)    /*!< SC TDRA: TDR0 Mask     */

/* SC TDRB Bit Field Definitions */
#define SC_TDRB_TDR2_Pos                    8                               /*!< SC TDRB: TDR2 Position */
#define SC_TDRB_TDR2_Msk                    (0xFFul << SC_TDRB_TDR2_Pos)    /*!< SC TDRB: TDR2 Mask     */

#define SC_TDRB_TDR1_Pos                    0                               /*!< SC TDRB: TDR1 Position */
#define SC_TDRB_TDR1_Msk                    (0xFFul << SC_TDRB_TDR1_Pos)    /*!< SC TDRB: TDR1 Mask     */

/*@}*/ /* end of group NUC400_SC */

/*--------------------------- C_CAN Controller (CAN) --------------------------*/
/** @addtogroup NUC400_CAN NUC400 C_CAN Control Register (CAN)
  @{
*/
typedef struct {
    __IO uint32_t CREQ;            /*!< Offset: 0x0000   IFn Command Request Registers */
    __IO uint32_t CMASK;           /*!< Offset: 0x0004   IFn Command Mask Registers    */
    __IO uint32_t MASK1;           /*!< Offset: 0x0008   IFn Mask 1 Register           */
    __IO uint32_t MASK2;           /*!< Offset: 0x000C   IFn Mask 2 Register           */
    __IO uint32_t ARB1;            /*!< Offset: 0x0010   IFn Arbitration 1 Register    */
    __IO uint32_t ARB2;            /*!< Offset: 0x0014   IFn Arbitration 2 Register    */
    __IO uint32_t MCON;            /*!< Offset: 0x0018   IFn Message Control Registers */
    __IO uint32_t DAT_A1;          /*!< Offset: 0x001C   IFn Data A1 Registers         */
    __IO uint32_t DAT_A2;          /*!< Offset: 0x0020   IFn Data A2 Registers         */
    __IO uint32_t DAT_B1;          /*!< Offset: 0x0024   IFn Data B1 Registers         */
    __IO uint32_t DAT_B2;          /*!< Offset: 0x0028   IFn Data B2 Registers         */
    __I uint32_t RESERVE0[13];

} CAN_IF_T;

typedef struct {
    __IO uint32_t CON;                        /*!< Offset: 0x0000   CAN Control Register                                  */
    __IO uint32_t STATUS;                        /*!< Offset: 0x0004   CAN Status Register                                   */
    __IO uint32_t ERR;                        /*!< Offset: 0x0008   Error Counter Register                               */
    __IO uint32_t BTIME;                        /*!< Offset: 0x000C   Bit Timing Register                                   */
    __IO uint32_t IIDR;                        /*!< Offset: 0x0010   Interrupt Identifier Register                      */
    __IO uint32_t TEST;                        /*!< Offset: 0x0014   Test Register                                       */
    __IO uint32_t BRPE;                        /*!< Offset: 0x0018   BRP Extension Register                               */
    __I  uint32_t RESERVED0[1];                /*!< Offset: 0x001C   Reserved                                           */
    CAN_IF_T      IF[2];                        /*!< Offset: 0x0020      IF1 Registers */
    /*!< Offset: 0x0080      IF2 Registers */
    uint32_t RESERVED1[8];                /*!< Offset: 0x00AC ~ 0x00FC   Reserved                                  */
    __I  uint32_t TXREQ1;                        /*!< Offset: 0x0100   Transmission Request Registers 1                     */
    __I  uint32_t TXREQ2;                        /*!< Offset: 0x0104   Transmission Request Registers 2                      */
    uint32_t RESERVED2[6];                /*!< Offset: 0x0108 ~ 0x011C   Reserved                                  */
    __I  uint32_t NDAT1;                        /*!< Offset: 0x0120   New Data Registers 1                                  */
    __I  uint32_t NDAT2;                        /*!< Offset: 0x0124   New Data Registers 2                                  */
    uint32_t RESERVED3[6];                /*!< Offset: 0x0128 ~ 0x013C   Reserved                                  */
    __I  uint32_t IPND1;                        /*!< Offset: 0x0140   Interrupt Pending Registers 1                      */
    __I  uint32_t IPND2;                        /*!< Offset: 0x0144   Interrupt Pending Registers 2                      */
    uint32_t RESERVED4[6];                /*!< Offset: 0x0148 ~ 0x015C   Reserved                                  */
    __I  uint32_t MVLD1;                        /*!< Offset: 0x0160   Message Valid Registers 1                          */
    __I  uint32_t MVLD2;                        /*!< Offset: 0x0164   Message Valid Registers 1                          */
    __IO uint32_t WU_IE;                        /*!< Offset: 0x0168   Wake Up Function Enable Registers                  */
    __IO uint32_t WU_STATUS;                    /*!< Offset: 0x016C   Wake Up Function Status Registers                  */
} CAN_T;

/* CAN CON Bit Field Definitions */
#define CAN_CON_TEST_Pos           7                                    /*!< CAN CON: TEST Position */
#define CAN_CON_TEST_Msk           (1ul << CAN_CON_TEST_Pos)            /*!< CAN CON: TEST Mask     */

#define CAN_CON_CCE_Pos            6                                    /*!< CAN CON: CCE Position  */
#define CAN_CON_CCE_Msk            (1ul << CAN_CON_CCE_Pos)             /*!< CAN CON: CCE Mask      */

#define CAN_CON_DAR_Pos            5                                    /*!< CAN CON: DAR Position  */
#define CAN_CON_DAR_Msk            (1ul << CAN_CON_DAR_Pos)             /*!< CAN CON: DAR Mask      */

#define CAN_CON_EIE_Pos            3                                    /*!< CAN CON: EIE Position  */
#define CAN_CON_EIE_Msk            (1ul << CAN_CON_EIE_Pos)             /*!< CAN CON: EIE Mask      */

#define CAN_CON_SIE_Pos            2                                    /*!< CAN CON: SIE Position  */
#define CAN_CON_SIE_Msk            (1ul << CAN_CON_SIE_Pos)             /*!< CAN CON: SIE Mask      */

#define CAN_CON_IE_Pos             1                                    /*!< CAN CON: IE Position   */
#define CAN_CON_IE_Msk             (1ul << CAN_CON_IE_Pos)              /*!< CAN CON: IE Mask       */

#define CAN_CON_INIT_Pos           0                                    /*!< CAN CON: INIT Position */
#define CAN_CON_INIT_Msk           (1ul << CAN_CON_INIT_Pos)            /*!< CAN CON: INIT Mask     */

/* CAN STATUS Bit Field Definitions */
#define CAN_STATUS_BOFF_Pos        7                                    /*!< CAN STATUS: BOFF Position  */
#define CAN_STATUS_BOFF_Msk        (1ul << CAN_STATUS_BOFF_Pos)         /*!< CAN STATUS: BOFF Mask      */

#define CAN_STATUS_EWARN_Pos       6                                    /*!< CAN STATUS: EWARN Position */
#define CAN_STATUS_EWARN_Msk       (1ul << CAN_STATUS_EWARN_Pos)        /*!< CAN STATUS: EWARN Mask     */

#define CAN_STATUS_EPASS_Pos       5                                    /*!< CAN STATUS: EPASS Position */
#define CAN_STATUS_EPASS_Msk       (1ul << CAN_STATUS_EPASS_Pos)        /*!< CAN STATUS: EPASS Mask     */

#define CAN_STATUS_RXOK_Pos        4                                    /*!< CAN STATUS: RXOK Position  */
#define CAN_STATUS_RXOK_Msk        (1ul << CAN_STATUS_RXOK_Pos)         /*!< CAN STATUS: RXOK Mask      */

#define CAN_STATUS_TXOK_Pos        3                                    /*!< CAN STATUS: TXOK Position  */
#define CAN_STATUS_TXOK_Msk        (1ul << CAN_STATUS_RXOK_Pos)         /*!< CAN STATUS: TXOK Mask      */

#define CAN_STATUS_LEC_Pos         0                                    /*!< CAN STATUS: LEC Position   */
#define CAN_STATUS_LEC_Msk         (0x3ul << CAN_STATUS_LEC_Pos)        /*!< CAN STATUS: LEC Mask       */

/* CAN ERR Bit Field Definitions */
#define CAN_ERR_RP_Pos             15                                   /*!< CAN ERR: RP Position       */
#define CAN_ERR_RP_Msk             (1ul << CAN_ERR_RP_Pos)              /*!< CAN ERR: RP Mask           */

#define CAN_ERR_REC_Pos            8                                    /*!< CAN ERR: REC Position      */
#define CAN_ERR_REC_Msk            (0x7Ful << CAN_ERR_REC_Pos)          /*!< CAN ERR: REC Mask          */

#define CAN_ERR_TEC_Pos            0                                    /*!< CAN ERR: TEC Position      */
#define CAN_ERR_TEC_Msk            (0xFFul << CAN_ERR_TEC_Pos)          /*!< CAN ERR: TEC Mask          */

/* CAN BTIME Bit Field Definitions */
#define CAN_BTIME_TSEG2_Pos        12                                   /*!< CAN BTIME: TSEG2 Position  */
#define CAN_BTIME_TSEG2_Msk        (0x7ul << CAN_BTIME_TSEG2_Pos)       /*!< CAN BTIME: TSEG2 Mask      */

#define CAN_BTIME_TSEG1_Pos        8                                    /*!< CAN BTIME: TSEG1 Position  */
#define CAN_BTIME_TSEG1_Msk        (0xFul << CAN_BTIME_TSEG1_Pos)       /*!< CAN BTIME: TSEG1 Mask      */

#define CAN_BTIME_SJW_Pos          6                                    /*!< CAN BTIME: SJW Position    */
#define CAN_BTIME_SJW_Msk          (0x3ul << CAN_BTIME_SJW_Pos)         /*!< CAN BTIME: SJW Mask        */

#define CAN_BTIME_BRP_Pos          0                                    /*!< CAN BTIME: BRP Position    */
#define CAN_BTIME_BRP_Msk          (0x3Ful << CAN_BTIME_BRP_Pos)        /*!< CAN BTIME: BRP Mask        */

/* CAN IIDR Bit Field Definitions */
#define CAN_IIDR_INTID_Pos         0                                    /*!< CAN IIDR: INTID Position   */
#define CAN_IIDR_INTID_Msk         (0xFFFFul << CAN_IIDR_INTID_Pos)     /*!< CAN IIDR: INTID Mask       */

/* CAN TEST Bit Field Definitions */
#define CAN_TEST_RX_Pos            7                                    /*!< CAN TEST: RX Position      */
#define CAN_TEST_RX_Msk            (1ul << CAN_TEST_RX_Pos)             /*!< CAN TEST: RX Mask          */

#define CAN_TEST_TX_Pos            5                                    /*!< CAN TEST: TX Position      */
#define CAN_TEST_TX_Msk            (0x3ul << CAN_TEST_TX_Pos)           /*!< CAN TEST: TX Mask          */

#define CAN_TEST_LBACK_Pos         4                                    /*!< CAN TEST: LBACK Position   */
#define CAN_TEST_LBACK_Msk         (1ul << CAN_TEST_LBACK_Pos)          /*!< CAN TEST: LBACK Mask       */

#define CAN_TEST_SILENT_Pos        3                                    /*!< CAN TEST: Silent Position  */
#define CAN_TEST_SILENT_Msk        (1ul << CAN_TEST_SILENT_Pos)         /*!< CAN TEST: Silent Mask      */

#define CAN_TEST_BASIC_Pos         2                                    /*!< CAN TEST: Basic Position   */
#define CAN_TEST_BASIC_Msk         (1ul << CAN_TEST_BASIC_Pos)          /*!< CAN TEST: Basic Mask       */

/* CAN BPRE Bit Field Definitions */
#define CAN_BRPE_BRPE_Pos          0                                    /*!< CAN BRPE: BRPE Position    */
#define CAN_BRPE_BRPE_Msk          (0xFul << CAN_BRPE_BRPE_Pos)         /*!< CAN BRPE: BRPE Mask        */

/* CAN IFn_CREQ Bit Field Definitions */
#define CAN_IF_CREQ_BUSY_Pos       15                                   /*!< CAN IFnCREQ: BUSY Position */
#define CAN_IF_CREQ_BUSY_Msk       (1ul << CAN_IF_CREQ_BUSY_Pos)        /*!< CAN IFnCREQ: BUSY Mask     */

#define CAN_IF_CREQ_MSGNUM_Pos     0                                    /*!< CAN IFnCREQ: MSGNUM Position */
#define CAN_IF_CREQ_MSGNUM_Msk     (0x3Ful << CAN_IF_CREQ_MSGNUM_Pos)   /*!< CAN IFnCREQ: MSGNUM Mask     */

/* CAN IFn_CMASK Bit Field Definitions */
#define CAN_IF_CMASK_WRRD_Pos      7                                    /*!< CAN IFnCMASK: WRRD Position */
#define CAN_IF_CMASK_WRRD_Msk      (1ul << CAN_IF_CMASK_WRRD_Pos)       /*!< CAN IFnCMASK: WRRD Mask     */

#define CAN_IF_CMASK_MASK_Pos      6                                    /*!< CAN IFnCMASK: MASK Position */
#define CAN_IF_CMASK_MASK_Msk      (1ul << CAN_IF_CMASK_MASK_Pos)       /*!< CAN IFnCMASK: MASK Mask     */

#define CAN_IF_CMASK_ARB_Pos       5                                    /*!< CAN IFnCMASK: ARB Position  */
#define CAN_IF_CMASK_ARB_Msk       (1ul << CAN_IF_CMASK_ARB_Pos)        /*!< CAN IFnCMASK: ARB Mask      */

#define CAN_IF_CMASK_CONTROL_Pos   4                                    /*!< CAN IFnCMASK: CONTROL Position */
#define CAN_IF_CMASK_CONTROL_Msk   (1ul << CAN_IF_CMASK_CONTROL_Pos)    /*!< CAN IFnCMASK: CONTROL Mask */

#define CAN_IF_CMASK_CLRINTPND_Pos 3                                    /*!< CAN IFnCMASK: CLRINTPND Position */
#define CAN_IF_CMASK_CLRINTPND_Msk (1ul << CAN_IF_CMASK_CLRINTPND_Pos)  /*!< CAN IFnCMASK: CLRINTPND Mask */

#define CAN_IF_CMASK_TXRQSTNEWDAT_Pos 2                                         /*!< CAN IFnCMASK: TXRQSTNEWDAT Position */
#define CAN_IF_CMASK_TXRQSTNEWDAT_Msk (1ul << CAN_IF_CMASK_TXRQSTNEWDAT_Pos)    /*!< CAN IFnCMASK: TXRQSTNEWDAT Mask     */

#define CAN_IF_CMASK_DATAA_Pos     1                                    /*!< CAN IFnCMASK: DATAA Position */
#define CAN_IF_CMASK_DATAA_Msk     (1ul << CAN_IF_CMASK_DATAA_Pos)      /*!< CAN IFnCMASK: DATAA Mask     */

#define CAN_IF_CMASK_DATAB_Pos     0                                    /*!< CAN IFnCMASK: DATAB Position */
#define CAN_IF_CMASK_DATAB_Msk     (1ul << CAN_IF_CMASK_DATAB_Pos)      /*!< CAN IFnCMASK: DATAB Mask     */

/* CAN IFn_MASK1 Bit Field Definitions */
#define CAN_IF_MASK1_MSK_Pos       0                                    /*!< CAN IFnMASK1: MSK Position   */
#define CAN_IF_MASK1_MSK_Msk       (0xFFul << CAN_IF_MASK1_MSK_Pos)     /*!< CAN IFnMASK1: MSK Mask       */

/* CAN IFn_MASK2 Bit Field Definitions */
#define CAN_IF_MASK2_MXTD_Pos      15                                   /*!< CAN IFnMASK2: MXTD Position */
#define CAN_IF_MASK2_MXTD_Msk      (1ul << CAN_IF_MASK2_MXTD_Pos)       /*!< CAN IFnMASK2: MXTD Mask     */

#define CAN_IF_MASK2_MDIR_Pos      14                                   /*!< CAN IFnMASK2: MDIR Position */
#define CAN_IF_MASK2_MDIR_Msk      (1ul << CAN_IF_MASK2_MDIR_Pos)       /*!< CAN IFnMASK2: MDIR Mask     */

#define CAN_IF_MASK2_MSK_Pos       0                                    /*!< CAN IFnMASK2: MSK Position */
#define CAN_IF_MASK2_MSK_Msk       (0x1FFul << CAN_IF_MASK2_MSK_Pos)    /*!< CAN IFnMASK2: MSK Mask     */

/* CAN IFn_ARB1 Bit Field Definitions */
#define CAN_IF_ARB1_ID_Pos         0                                    /*!< CAN IFnARB1: ID Position   */
#define CAN_IF_ARB1_ID_Msk         (0xFFFFul << CAN_IF_ARB1_ID_Pos)     /*!< CAN IFnARB1: ID Mask       */

/* CAN IFn_ARB2 Bit Field Definitions */
#define CAN_IF_ARB2_MSGVAL_Pos     15                                   /*!< CAN IFnARB2: MSGVAL Position */
#define CAN_IF_ARB2_MSGVAL_Msk     (1ul << CAN_IF_ARB2_MSGVAL_Pos)      /*!< CAN IFnARB2: MSGVAL Mask     */

#define CAN_IF_ARB2_XTD_Pos        14                                   /*!< CAN IFnARB2: XTD Position    */
#define CAN_IF_ARB2_XTD_Msk        (1ul << CAN_IF_ARB2_XTD_Pos)         /*!< CAN IFnARB2: XTD Mask        */

#define CAN_IF_ARB2_DIR_Pos        13                                   /*!< CAN IFnARB2: DIR Position    */
#define CAN_IF_ARB2_DIR_Msk        (1ul << CAN_IF_ARB2_DIR_Pos)         /*!< CAN IFnARB2: DIR Mask        */

#define CAN_IF_ARB2_ID_Pos         0                                    /*!< CAN IFnARB2: ID Position     */
#define CAN_IF_ARB2_ID_Msk         (0x1FFFul << CAN_IF_ARB2_ID_Pos)     /*!< CAN IFnARB2: ID Mask         */

/* CAN IFn_MCON Bit Field Definitions */
#define CAN_IF_MCON_NEWDAT_Pos     15                                   /*!< CAN IFnMCON: NEWDAT Position */
#define CAN_IF_MCON_NEWDAT_Msk     (1ul << CAN_IF_MCON_NEWDAT_Pos)      /*!< CAN IFnMCON: NEWDAT Mask     */

#define CAN_IF_MCON_MSGLST_Pos     14                                   /*!< CAN IFnMCON: MSGLST Position */
#define CAN_IF_MCON_MSGLST_Msk     (1ul << CAN_IF_MCON_MSGLST_Pos)      /*!< CAN IFnMCON: MSGLST Mask     */

#define CAN_IF_MCON_INTPND_Pos     13                                   /*!< CAN IFnMCON: INTPND Position */
#define CAN_IF_MCON_INTPND_Msk     (1ul << CAN_IF_MCON_INTPND_Pos)      /*!< CAN IFnMCON: INTPND Mask     */

#define CAN_IF_MCON_UMASK_Pos      12                                   /*!< CAN IFnMCON: UMASK Position  */
#define CAN_IF_MCON_UMASK_Msk      (1ul << CAN_IF_MCON_UMASK_Pos)       /*!< CAN IFnMCON: UMASK Mask      */

#define CAN_IF_MCON_TXIE_Pos       11                                   /*!< CAN IFnMCON: TXIE Position   */
#define CAN_IF_MCON_TXIE_Msk       (1ul << CAN_IF_MCON_TXIE_Pos)        /*!< CAN IFnMCON: TXIE Mask       */

#define CAN_IF_MCON_RXIE_Pos       10                                   /*!< CAN IFnMCON: RXIE Position   */
#define CAN_IF_MCON_RXIE_Msk       (1ul << CAN_IF_MCON_RXIE_Pos)        /*!< CAN IFnMCON: RXIE Mask       */

#define CAN_IF_MCON_RMTEN_Pos      9                                    /*!< CAN IFnMCON: RMTEN Position  */
#define CAN_IF_MCON_RMTEN_Msk      (1ul << CAN_IF_MCON_RMTEN_Pos)       /*!< CAN IFnMCON: RMTEN Mask      */

#define CAN_IF_MCON_TXRQST_Pos     8                                    /*!< CAN IFnMCON: TXRQST Position */
#define CAN_IF_MCON_TXRQST_Msk     (1ul << CAN_IF_MCON_TXRQST_Pos)      /*!< CAN IFnMCON: TXRQST Mask     */

#define CAN_IF_MCON_EOB_Pos        7                                    /*!< CAN IFnMCON: EOB Position    */
#define CAN_IF_MCON_EOB_Msk        (1ul << CAN_IF_MCON_EOB_Pos)         /*!< CAN IFnMCON: EOB Mask        */

#define CAN_IF_MCON_DLC_Pos        0                                    /*!< CAN IFnMCON: DLC Position    */
#define CAN_IF_MCON_DLC_Msk        (0xFul << CAN_IF_MCON_DLC_Pos)       /*!< CAN IFnMCON: DLC Mask        */

/* CAN IFn_DATA_A1 Bit Field Definitions */
#define CAN_IF_DAT_A1_DATA1_Pos    8                                    /*!< CAN IFnDATAA1: DATA1 Position */
#define CAN_IF_DAT_A1_DATA1_Msk    (0xFFul << CAN_IF_DAT_A1_DATA1_Pos)  /*!< CAN IFnDATAA1: DATA1 Mask     */

#define CAN_IF_DAT_A1_DATA0_Pos    0                                    /*!< CAN IFnDATAA1: DATA0 Position */
#define CAN_IF_DAT_A1_DATA0_Msk    (0xFFul << CAN_IF_DAT_A1_DATA0_Pos)  /*!< CAN IFnDATAA1: DATA0 Mask     */

/* CAN IFn_DATA_A2 Bit Field Definitions */
#define CAN_IF_DAT_A2_DATA3_Pos    8                                    /*!< CAN IFnDATAA1: DATA3 Position */
#define CAN_IF_DAT_A2_DATA3_Msk    (0xFFul << CAN_IF_DAT_A2_DATA3_Pos)  /*!< CAN IFnDATAA1: DATA3 Mask     */

#define CAN_IF_DAT_A2_DATA2_Pos    0                                    /*!< CAN IFnDATAA1: DATA2 Position */
#define CAN_IF_DAT_A2_DATA2_Msk    (0xFFul << CAN_IF_DAT_A2_DATA2_Pos)  /*!< CAN IFnDATAA1: DATA2 Mask     */

/* CAN IFn_DATA_B1 Bit Field Definitions */
#define CAN_IF_DAT_B1_DATA5_Pos    8                                    /*!< CAN IFnDATAB1: DATA5 Position */
#define CAN_IF_DAT_B1_DATA5_Msk    (0xFFul << CAN_IF_DAT_B1_DATA5_Pos)  /*!< CAN IFnDATAB1: DATA5 Mask */

#define CAN_IF_DAT_B1_DATA4_Pos    0                                    /*!< CAN IFnDATAB1: DATA4 Position */
#define CAN_IF_DAT_B1_DATA4_Msk    (0xFFul << CAN_IF_DAT_B1_DATA4_Pos)  /*!< CAN IFnDATAB1: DATA4 Mask */

/* CAN IFn_DATA_B2 Bit Field Definitions */
#define CAN_IF_DAT_B2_DATA7_Pos    8                                    /*!< CAN IFnDATAB2: DATA7 Position */
#define CAN_IF_DAT_B2_DATA7_Msk    (0xFFul << CAN_IF_DAT_B2_DATA7_Pos)  /*!< CAN IFnDATAB2: DATA7 Mask     */

#define CAN_IF_DAT_B2_DATA6_Pos    0                                    /*!< CAN IFnDATAB2: DATA6 Position */
#define CAN_IF_DAT_B2_DATA6_Msk    (0xFFul << CAN_IF_DAT_B2_DATA6_Pos)  /*!< CAN IFnDATAB2: DATA6 Mask     */

/* CAN IFn_TXRQST1 Bit Field Definitions */
#define CAN_IF_TXRQST1_TXRQST_Pos  0                                        /*!< CAN IFnTXRQST1: TXRQST Position */
#define CAN_IF_TXRQST1_TXRQST_Msk  (0xFFFFul << CAN_IF_TXRQST1_TXRQST_Pos)  /*!< CAN IFnTXRQST1: TXRQST Mask     */

/* CAN IFn_TXRQST2 Bit Field Definitions */
#define CAN_IF_TXRQST2_TXRQST_Pos  0                                        /*!< CAN IFnTXRQST2: TXRQST Position  */
#define CAN_IF_TXRQST2_TXRQST_Msk  (0xFFFFul << CAN_IF_TXRQST2_TXRQST_Pos)  /*!< CAN IFnTXRQST2: TXRQST Mask      */

/* CAN IFn_NDAT1 Bit Field Definitions */
#define CAN_IF_NDAT1_NEWDATA_Pos   0                                        /*!< CAN IFnNDAT1: NEWDATA Position */
#define CAN_IF_NDAT1_NEWDATA_Msk   (0xFFFFul << CAN_IF_NDAT1_NEWDATA_Pos)   /*!< CAN IFnNDAT1: NEWDATA Mask     */

/* CAN IFn_NDAT2 Bit Field Definitions */
#define CAN_IF_NDAT2_NEWDATA_Pos   0                                        /*!< CAN IFnNDAT2: NEWDATA Position */
#define CAN_IF_NDAT2_NEWDATA_Msk   (0xFFFFul << CAN_IF_NDAT2_NEWDATA_Pos)   /*!< CAN IFnNDAT2: NEWDATA Mask     */

/* CAN IFn_IPND1 Bit Field Definitions */
#define CAN_IF_IPND1_INTPND_Pos   0                                         /*!< CAN IFnIPND1: INTPND Position */
#define CAN_IF_IPND1_INTPND_Msk   (0xFFFFul << CAN_IF_IPND1_INTPND_Pos)     /*!< CAN IFnIPND1: INTPND Mask     */

/* CAN IFn_IPND2 Bit Field Definitions */
#define CAN_IF_IPND2_INTPND_Pos   0                                         /*!< CAN IFnIPND2: INTPND Position */
#define CAN_IF_IPND2_INTPND_Msk   (0xFFFFul << CAN_IF_IPND2_INTPND_Pos)     /*!< CAN IFnIPND2: INTPND Mask     */

/* CAN IFn_MVLD1 Bit Field Definitions */
#define CAN_IF_MVLD1_MSGVAL_Pos   0                                         /*!< CAN IFnMVLD1: MSGVAL Position */
#define CAN_IF_MVLD1_MSGVAL_Msk   (0xFFFFul << CAN_IF_MVLD1_MSGVAL_Pos)     /*!< CAN IFnMVLD1: MSGVAL Mask     */

/* CAN IFn_MVLD2 Bit Field Definitions */
#define CAN_IF_MVLD2_MSGVAL_Pos   0                                         /*!< CAN IFnMVLD2: MSGVAL Position */
#define CAN_IF_MVLD2_MSGVAL_Msk   (0xFFFFul << CAN_IF_MVLD2_MSGVAL_Pos)     /*!< CAN IFnMVLD2: MSGVAL Mask     */

/* CAN WUEN Bit Field Definitions */
#define CAN_WUEN_WAKUP_EN_Pos     0                                         /*!< CAN WUEN: WAKUP_EN Position */
#define CAN_WUEN_WAKUP_EN_Msk    (1ul << CAN_WUEN_WAKUP_EN_Pos)             /*!< CAN WUEN: WAKUP_EN Mask     */

/* CAN WUSTATUS Bit Field Definitions */
#define CAN_WUSTATUS_WAKUP_STS_Pos     0                                    /*!< CAN WUSTATUS: WAKUP_STS Position */
#define CAN_WUSTATUS_WAKUP_STS_Msk    (1ul << CAN_WUSTATUS_WAKUP_STS_Pos)   /*!< CAN WUSTATUS: WAKUP_STS Mask     */



/*@}*/ /* end of group NUC400_CAN */


/*------------- PS/2 Device Controller Register (PS2D) -----------------------------*/
/** @addtogroup NUC400_PS2D NUC400 PS/2 Device Controller (PS2D)
  @{
*/
typedef struct {

    __IO uint32_t PS2CON;                        /*!< Offset: 0x0000   PS/2 Control Register                              */

    __IO uint32_t PS2TXDATA0;                /*!< Offset: 0x0004   PS/2 Transmit DATA Register 0                      */

    __IO uint32_t PS2TXDATA1;       /*!< Offset: 0x0008   PS/2 Transmit DATA Register 1                      */

    __IO uint32_t PS2TXDATA2;                /*!< Offset: 0x000C   PS/2 Transmit DATA Register 2                      */

    __IO uint32_t PS2TXDATA3;              /*!< Offset: 0x0010   PS/2 Transmit DATA Register 3                      */

    __I uint32_t PS2RXDATA;                    /*!< Offset: 0x0014   PS/2 Receive DATA Register                         */

    __IO uint32_t PS2STATUS;                /*!< Offset: 0x0018   PS/2 Status Register                               */

    __IO uint32_t PS2INTID;                  /*!< Offset: 0x001C   PS/2 Interrupt Identification Register             */

} PS2_T;

#define PS2_PS2CON_PS2EN_Pos                       0                                                                            /*!< PS2 PS2CON: PS2EN Position */
#define PS2_PS2CON_PS2EN_Msk                       (1ul << PS2_PS2CON_PS2EN_Pos)                  /*!< PS2 PS2CON: PS2EN Mask */

#define PS2_PS2CON_TXINTEN_Pos                     1                                                                            /*!< PS2 PS2CON: TXINTEN Position */
#define PS2_PS2CON_TXINTEN_Msk                     (1ul << PS2_PS2CON_TXINTEN_Pos)              /*!< PS2 PS2CON: TXINTEN Mask */

#define PS2_PS2CON_RXINTEN_Pos                     2                                                                            /*!< PS2 PS2CON: RXINTEN Position */
#define PS2_PS2CON_RXINTEN_Msk                     (1ul << PS2_PS2CON_RXINTEN_Pos)            /*!< PS2 PS2CON: RXINTEN Mask */

#define PS2_PS2CON_TXFIFO_DEPTH_Pos                3                                                                        /*!< PS2 PS2CON: TXFIFO_DEPTH Position */
#define PS2_PS2CON_TXFIFO_DEPTH_Msk                (0xFul << PS2_PS2CON_TXFIFO_DEPTH_Pos)    /*!< PS2 PS2CON: TXFIFO_DEPTH Mask */

#define PS2_PS2CON_ACK_Pos                         7                                                                        /*!< PS2 PS2CON: ACK Position */
#define PS2_PS2CON_ACK_Msk                         (1ul << PS2_PS2CON_ACK_Pos)                        /*!< PS2 PS2CON: ACK Mask */

#define PS2_PS2CON_CLRFIFO_Pos                     8                                                                            /*!< PS2 PS2CON: CLRFIFO Position */
#define PS2_PS2CON_CLRFIFO_Msk                     (1ul << PS2_PS2CON_CLRFIFO_Pos)              /*!< PS2 PS2CON: CLRFIFO Mask */

#define PS2_PS2CON_OVERRIDE_Pos                    9                                                                            /*!< PS2 PS2CON: OVERRIDE Position */
#define PS2_PS2CON_OVERRIDE_Msk                    (1ul << PS2_PS2CON_OVERRIDE_Pos)              /*!< PS2 PS2CON: OVERRIDE Mask */

#define PS2_PS2CON_FPS2CLK_Pos                     10                                                                            /*!< PS2 PS2CON: FPS2CLK Position */
#define PS2_PS2CON_FPS2CLK_Msk                     (1ul << PS2_PS2CON_FPS2CLK_Pos)                 /*!< PS2 PS2CON: FPS2CLK Mask */

#define PS2_PS2CON_FPS2DAT_Pos                     11                                                                            /*!< PS2 PS2CON: FPS2DAT Position */
#define PS2_PS2CON_FPS2DAT_Msk                     (1ul << PS2_PS2CON_FPS2DAT_Pos)                 /*!< PS2 PS2CON: FPS2DAT Mask */

#define PS2_PS2RXDATA_RXDATA_Pos                   0                                                                            /*!< PS2 PS2RXDATA: RXDATA Position */
#define PS2_PS2RXDATA_RXDATA_Msk                   (0xFFul << PS2_PS2RXDATA_RXDATA_Pos)        /*!< PS2 PS2RXDATA: RXDATA Mask */

/*@}*/ /* end of group NUC400_PS2D */

/*------------- Cryptographic Accelerator Register (CRYPTO) -----------------------------*/
/** @addtogroup NUC400_CRYPTO NUC400 Cryptographic Accelerator Controller (CRYPTO)
  @{
*/
typedef struct {
    __IO uint32_t CRYPTO_INT_EN;              /*!< Offset: 0x0000   CRYPTO interrupt enable                             */
    __IO uint32_t CRYPTO_INT_FLAG;            /*!< Offset: 0x0004   CRYPTO interrupt flag                               */
    __IO uint32_t PRNG_CTL;                   /*!< Offset: 0x0008   PRNG  control register                             */
    __IO uint32_t PRNG_SEED;                  /*!< Offset: 0x000C   Store  random seed                                 */
    __IO uint32_t PRNG_key0;                  /*!< Offset: 0x0010   PRNG  generated  Key0                              */
    __IO uint32_t PRNG_key1;                  /*!< Offset: 0x0014   PRNG  generated  Key1                              */
    __IO uint32_t PRNG_key2;                  /*!< Offset: 0x0018   PRNG  generated  Key2                              */
    __IO uint32_t PRNG_key3;                  /*!< Offset: 0x001C   PRNG  generated  Key3                              */
    __IO uint32_t PRNG_key4;                  /*!< Offset: 0x0020   PRNG  generated  Key4                              */
    __IO uint32_t PRNG_key5;                  /*!< Offset: 0x0024   PRNG  generated  Key5                              */
    __IO uint32_t PRNG_key6;                  /*!< Offset: 0x0028   PRNG  generated  Key6                              */
    __IO uint32_t PRNG_key7;                  /*!< Offset: 0x002C   PRNG  generated  Key7                              */
    uint32_t RESERVED1[8];               /*!< Offset: 0x0030 ~ 0x004C   Reserved                                  */
    __IO uint32_t AES_FEEDBACK_0;             /*!< Offset: 0x0050   AES engine 0 Output feedback data after cryptographic operation */
    __IO uint32_t AES_FEEDBACK_1;             /*!< Offset: 0x0054   AES engine 1 Output feedback data after cryptographic operation */
    __IO uint32_t AES_FEEDBACK_2;             /*!< Offset: 0x0058   AES engine 2 Output feedback data after cryptographic operation */
    __IO uint32_t AES_FEEDBACK_3;             /*!< Offset: 0x005C   AES engine 3 Output feedback data after cryptographic operation */
    __IO uint32_t TDES_FEEDBACK_H;            /*!< Offset: 0x0060   Triple DES engine Output higher feedback data after cryptographic operation */
    __IO uint32_t TDES_FEEDBACK_L;            /*!< Offset: 0x0064   Triple DES engine Output lower feedback data after cryptographic operation */
    uint32_t RESERVED2[38];              /*!< Offset: 0x0068 ~ 0x00FC   Reserved                                  */
    __IO uint32_t AES_CTL;                    /*!< Offset: 0x0100   AES engine setting                                 */
    __IO uint32_t AES_FLAG;                   /*!< Offset: 0x0104   AES engine flag                                    */
    __IO uint32_t AES_DATAIN;                 /*!< Offset: 0x0108   AES engine data input port                         */
    __IO uint32_t AES_DATAOUT;                /*!< Offset: 0x010C   AES engine data output port                        */
    __IO uint32_t AES0_KEY_0;                 /*!< Offset: 0x0110   AES0 Key Word 0 Register                            */
    __IO uint32_t AES0_KEY_1;                 /*!< Offset: 0x0114   AES0 Key Word 1 Register                            */
    __IO uint32_t AES0_KEY_2;                 /*!< Offset: 0x0118   AES0 Key Word 2 Register                            */
    __IO uint32_t AES0_KEY_3;                 /*!< Offset: 0x011C   AES0 Key Word 3 Register                            */
    __IO uint32_t AES0_KEY_4;                 /*!< Offset: 0x0120   AES0 Key Word 4 Register                            */
    __IO uint32_t AES0_KEY_5;                 /*!< Offset: 0x0124   AES0 Key Word 5 Register                            */
    __IO uint32_t AES0_KEY_6;                 /*!< Offset: 0x0128   AES0 Key Word 6 Register                            */
    __IO uint32_t AES0_KEY_7;                 /*!< Offset: 0x012C   AES0 Key Word 7 Register                            */
    __IO uint32_t AES0_IV0;                   /*!< Offset: 0x0130   AES0 Initial Vector Word 0 Register                 */
    __IO uint32_t AES0_IV1;                   /*!< Offset: 0x0134   AES0 Initial Vector Word 1 Register                 */
    __IO uint32_t AES0_IV2;                   /*!< Offset: 0x0138   AES0 Initial Vector Word 2 Register                 */
    __IO uint32_t AES0_IV3;                   /*!< Offset: 0x013C   AES0 Initial Vector Word 3 Register                 */
    __IO uint32_t AES0_SADR;                  /*!< Offset: 0x0140   AES0 Source Address Register                        */
    __IO uint32_t AES0_DADR;                  /*!< Offset: 0x0144   AES0 Destination Address Register                   */
    __IO uint32_t AES0_CNT;                   /*!< Offset: 0x0148   AES0 Byte Count Register                            */
    __IO uint32_t AES1_KEY_0;                 /*!< Offset: 0x014C   AES1 Key Word 0 Register                           */
    __IO uint32_t AES1_KEY_1;                 /*!< Offset: 0x0150   AES1 Key Word 1 Register                           */
    __IO uint32_t AES1_KEY_2;                 /*!< Offset: 0x0154   AES1 Key Word 2 Register                           */
    __IO uint32_t AES1_KEY_3;                 /*!< Offset: 0x0158   AES1 Key Word 3 Register                           */
    __IO uint32_t AES1_KEY_4;                 /*!< Offset: 0x015C   AES1 Key Word 4 Register                           */
    __IO uint32_t AES1_KEY_5;                 /*!< Offset: 0x0160   AES1 Key Word 5 Register                           */
    __IO uint32_t AES1_KEY_6;                 /*!< Offset: 0x0164   AES1 Key Word 6 Register                           */
    __IO uint32_t AES1_KEY_7;                 /*!< Offset: 0x0168   AES1 Key Word 7 Register                           */
    __IO uint32_t AES1_IV0;                   /*!< Offset: 0x016C   AES1 Initial Vector Word 0 Register                */
    __IO uint32_t AES1_IV1;                   /*!< Offset: 0x0170   AES1 Initial Vector Word 1 Register                */
    __IO uint32_t AES1_IV2;                   /*!< Offset: 0x0174   AES1 Initial Vector Word 2 Register                */
    __IO uint32_t AES1_IV3;                   /*!< Offset: 0x0178   AES1 Initial Vector Word 3 Register                */
    __IO uint32_t AES1_SADR;                  /*!< Offset: 0x017C   AES1 Source Address Register                       */
    __IO uint32_t AES1_DADR;                  /*!< Offset: 0x0180   AES1 Destination Address Register                  */
    __IO uint32_t AES1_CNT;                   /*!< Offset: 0x0184   AES1 Byte Count Register                           */
    __IO uint32_t AES2_KEY_0;                 /*!< Offset: 0x0188   AES2 Key Word 0 Register                           */
    __IO uint32_t AES2_KEY_1;                 /*!< Offset: 0x018C   AES2 Key Word 1 Register                           */
    __IO uint32_t AES2_KEY_2;                 /*!< Offset: 0x0190   AES2 Key Word 2 Register                           */
    __IO uint32_t AES2_KEY_3;                 /*!< Offset: 0x0194   AES2 Key Word 3 Register                           */
    __IO uint32_t AES2_KEY_4;                 /*!< Offset: 0x0198   AES2 Key Word 4 Register                           */
    __IO uint32_t AES2_KEY_5;                 /*!< Offset: 0x019C   AES2 Key Word 5 Register                           */
    __IO uint32_t AES2_KEY_6;                 /*!< Offset: 0x01A0   AES2 Key Word 6 Register                           */
    __IO uint32_t AES2_KEY_7;                 /*!< Offset: 0x01A4   AES2 Key Word 7 Register                           */
    __IO uint32_t AES2_IV0;                   /*!< Offset: 0x01A8   AES2 Initial Vector Word 0 Register                */
    __IO uint32_t AES2_IV1;                   /*!< Offset: 0x01AC   AES2 Initial Vector Word 1 Register                */
    __IO uint32_t AES2_IV2;                   /*!< Offset: 0x01B0   AES2 Initial Vector Word 2 Register                */
    __IO uint32_t AES2_IV3;                   /*!< Offset: 0x01B4   AES2 Initial Vector Word 3 Register                */
    __IO uint32_t AES2_SADR;                  /*!< Offset: 0x01B8   AES2 Source Address Register                       */
    __IO uint32_t AES2_DADR;                  /*!< Offset: 0x01BC   AES2 Destination Address Register                  */
    __IO uint32_t AES2_CNT;                   /*!< Offset: 0x01C0   AES2 Byte Count Register                           */
    __IO uint32_t AES3_KEY_0;                 /*!< Offset: 0x01C4   AES3 Key Word 0 Register                           */
    __IO uint32_t AES3_KEY_1;                 /*!< Offset: 0x01C8   AES3 Key Word 1 Register                           */
    __IO uint32_t AES3_KEY_2;                 /*!< Offset: 0x01CC   AES3 Key Word 2 Register                           */
    __IO uint32_t AES3_KEY_3;                 /*!< Offset: 0x01D0   AES3 Key Word 3 Register                           */
    __IO uint32_t AES3_KEY_4;                 /*!< Offset: 0x01D4   AES3 Key Word 4 Register                           */
    __IO uint32_t AES3_KEY_5;                 /*!< Offset: 0x01D8   AES3 Key Word 5 Register                           */
    __IO uint32_t AES3_KEY_6;                 /*!< Offset: 0x01DC   AES3 Key Word 6 Register                           */
    __IO uint32_t AES3_KEY_7;                 /*!< Offset: 0x01E0   AES3 Key Word 7 Register                           */
    __IO uint32_t AES3_IV0;                   /*!< Offset: 0x01E4   AES3 Initial Vector Word 0 Register                */
    __IO uint32_t AES3_IV1;                   /*!< Offset: 0x01E8   AES3 Initial Vector Word 1 Register                */
    __IO uint32_t AES3_IV2;                   /*!< Offset: 0x01EC   AES3 Initial Vector Word 2 Register                */
    __IO uint32_t AES3_IV3;                   /*!< Offset: 0x01F0   AES3 Initial Vector Word 3 Register                */
    __IO uint32_t AES3_SADR;                  /*!< Offset: 0x01F4   AES3 Source Address Register                       */
    __IO uint32_t AES3_DADR;                  /*!< Offset: 0x01F8   AES3 Destination Address Register                  */
    __IO uint32_t AES3_CNT;                   /*!< Offset: 0x01FC   AES3 Byte Count Register                           */
    __IO uint32_t TDES_CTL;                   /*!< Offset: 0x0200   TDES engine parameter  setting                     */
    __IO uint32_t TDES_FLAG;                  /*!< Offset: 0x0204   TDES flag setting                                  */
    __IO uint32_t TDES0_KEY1H;                /*!< Offset: 0x0208   TDES0 Key 1 Higher Word Register                */
    __IO uint32_t TDES0_KEY1L;                /*!< Offset: 0x020C   TDES0 Key 1 Lower Word Register                 */
    __IO uint32_t TDES0_KEY2H;                /*!< Offset: 0x0210   TDES0 Key 2 Higher Word Register                    */
    __IO uint32_t TDES0_KEY2L;                /*!< Offset: 0x0214   TDES0 Key 2 Lower Word Register                     */
    __IO uint32_t TDES0_KEY3H;                /*!< Offset: 0x0218   TDES0 Key 3 Higher Word Register                    */
    __IO uint32_t TDES0_KEY3L;                /*!< Offset: 0x021C   TDES0 Key 3 Lower Word Register                     */
    __IO uint32_t TDES0_IVH;                  /*!< Offset: 0x0220   TDES0 Initial Vector Higher Word Register           */
    __IO uint32_t TDES0_IVL;                  /*!< Offset: 0x0224   TDES0 Initial Vector Lower Word Register            */
    __IO uint32_t TDES0_SADR;                 /*!< Offset: 0x0228   TDES0 Source Address Register                   */
    __IO uint32_t TDES0_DADR;                 /*!< Offset: 0x022C   TDES0 Destination Address Register              */
    __IO uint32_t TDES0_CNT;                  /*!< Offset: 0x0230   TDES0 Block Count Register                      */
    __IO uint32_t TDES_DATAIN;                /*!< Offset: 0x0234   TDES engine Input Word data Register           */
    __IO uint32_t TDES_DATAOUT;               /*!< Offset: 0x0238   TDES engine Output Word data Register          */
    uint32_t RESERVED3[3];               /*!< Offset: 0x023C ~ 0x0244   Reserved                                  */
    __IO uint32_t TDES1_KEY1H;                /*!< Offset: 0x0248   TDES1 Key 1 Higher Word Register                */
    __IO uint32_t TDES1_KEY1L;                /*!< Offset: 0x024C   TDES1 Key 1 Lower Word Register                 */
    __IO uint32_t TDES1_KEY2H;                /*!< Offset: 0x0250   TDES1 Key 2 Higher Word Register                    */
    __IO uint32_t TDES1_KEY2L;                /*!< Offset: 0x0254   TDES1 Key 2 Lower Word Register                     */
    __IO uint32_t TDES1_KEY3H;                /*!< Offset: 0x0258   TDES1 Key 3 Higher Word Register                    */
    __IO uint32_t TDES1_KEY3L;                /*!< Offset: 0x025C   TDES1 Key 3 Lower Word Register                     */
    __IO uint32_t TDES1_IVH;                  /*!< Offset: 0x0260   TDES1 Initial Vector Higher Word Register           */
    __IO uint32_t TDES1_IVL;                  /*!< Offset: 0x0264   TDES1 Initial Vector Lower Word Register            */
    __IO uint32_t TDES1_SADR;                 /*!< Offset: 0x0268   TDES1 Source Address Register                   */
    __IO uint32_t TDES1_DADR;                 /*!< Offset: 0x026C   TDES1 Destination Address Register              */
    __IO uint32_t TDES1_CNT;                  /*!< Offset: 0x0270   TDES1 Block Count Register                      */
    uint32_t RESERVED4[5];               /*!< Offset: 0x0274 ~ 0x0284   Reserved                                  */
    __IO uint32_t TDES2_KEY1H;                /*!< Offset: 0x0288   TDES2 Key 1 Higher Word Register                */
    __IO uint32_t TDES2_KEY1L;                /*!< Offset: 0x028C   TDES2 Key 1 Lower Word Register                 */
    __IO uint32_t TDES2_KEY2H;                /*!< Offset: 0x0290   TDES2 Key 2 Higher Word Register                    */
    __IO uint32_t TDES2_KEY2L;                /*!< Offset: 0x0294   TDES2 Key 2 Lower Word Register                     */
    __IO uint32_t TDES2_KEY3H;                /*!< Offset: 0x0298   TDES2 Key 3 Higher Word Register                    */
    __IO uint32_t TDES2_KEY3L;                /*!< Offset: 0x029C   TDES2 Key 3 Lower Word Register                     */
    __IO uint32_t TDES2_IVH;                  /*!< Offset: 0x02A0   TDES2 Initial Vector Higher Word Register           */
    __IO uint32_t TDES2_IVL;                  /*!< Offset: 0x02A4   TDES2 Initial Vector Lower Word Register            */
    __IO uint32_t TDES2_SADR;                 /*!< Offset: 0x02A8   TDES2 Source Address Register                   */
    __IO uint32_t TDES2_DADR;                 /*!< Offset: 0x02AC   TDES2 Destination Address Register              */
    __IO uint32_t TDES2_CNT;                  /*!< Offset: 0x02B0   TDES2 Block Count Register                      */
    uint32_t RESERVED5[5];               /*!< Offset: 0x02B4 ~ 0x02C4   Reserved                                  */
    __IO uint32_t TDES3_KEY1H;                /*!< Offset: 0x02C8   TDES3 Key 1 Higher Word Register                */
    __IO uint32_t TDES3_KEY1L;                /*!< Offset: 0x02CC   TDES3 Key 1 Lower Word Register                 */
    __IO uint32_t TDES3_KEY2H;                /*!< Offset: 0x02D0   TDES3 Key 2 Higher Word Register                    */
    __IO uint32_t TDES3_KEY2L;                /*!< Offset: 0x02D4   TDES3 Key 2 Lower Word Register                     */
    __IO uint32_t TDES3_KEY3H;                /*!< Offset: 0x02D8   TDES3 Key 3 Higher Word Register                    */
    __IO uint32_t TDES3_KEY3L;                /*!< Offset: 0x02DC   TDES3 Key 3 Lower Word Register                     */
    __IO uint32_t TDES3_IVH;                  /*!< Offset: 0x02E0   TDES3 Initial Vector Higher Word Register           */
    __IO uint32_t TDES3_IVL;                  /*!< Offset: 0x02E4   TDES3 Initial Vector Lower Word Register            */
    __IO uint32_t TDES3_SADR;                 /*!< Offset: 0x02E8   TDES3 Source Address Register                   */
    __IO uint32_t TDES3_DADR;                 /*!< Offset: 0x02EC   TDES3 Destination Address Register              */
    __IO uint32_t TDES3_CNT;                  /*!< Offset: 0x02F0   TDES3 Block Count Register                      */
    uint32_t RESERVED6[3];               /*!< Offset: 0x02F4 ~ 0x02FC   Reserved                                  */
    __IO uint32_t SHA_CTL;                    /*!< Offset: 0x0300   SHA engine parameter  setting                      */
    __IO uint32_t SHA_FLAG;                   /*!< Offset: 0x0304   SHA status flag                                    */
    __IO uint32_t SHA_H0;                     /*!< Offset: 0x0308   SHA digest message 0                               */
    __IO uint32_t SHA_H1;                     /*!< Offset: 0x030C   SHA digest message 1                               */
    __IO uint32_t SHA_H2;                     /*!< Offset: 0x0310   SHA digest message 2                               */
    __IO uint32_t SHA_H3;                     /*!< Offset: 0x0314   SHA digest message 3                               */
    __IO uint32_t SHA_H4;                     /*!< Offset: 0x0318   SHA digest message 4                               */
    __IO uint32_t SHA_H5;                     /*!< Offset: 0x031C   SHA digest message 5                               */
    __IO uint32_t SHA_H6;                     /*!< Offset: 0x0320   SHA digest message 6                               */
    __IO uint32_t SHA_H7;                     /*!< Offset: 0x0324   SHA digest message 7                               */
    uint32_t RESERVED7[9];               /*!< Offset: 0x0328 ~ 0x0348   Reserved                                  */
    __IO uint32_t SHA_SADR;                   /*!< Offset: 0x034C   SHA DMA Source Address Register                    */
    __IO uint32_t SHA_DMA_CNT;                /*!< Offset: 0x0350   SHA DMA count                                      */
    __IO uint32_t SHA_DATAIN;                 /*!< Offset: 0x0354   SHA software write to engine port                  */
} CRYPTO_T;

/********************* Bit definition of CRYPTO_INT_EN register **********************/
#define CRYPTO_AES_INT_EN_Pos       0                                  /*!<CRYPTO CRYPTO_INT_EN: AES_INT_EN Position */
#define CRYPTO_AES_INT_EN_Msk       (1ul << CRYPTO_AES_INT_EN_Pos)     /*!<CRYPTO CRYPTO_INT_EN: AES_INT_EN Mask */
#define CRYPTO_AES_ERR_EN_Pos       1                                  /*!<CRYPTO CRYPTO_INT_EN: AES_ERR_EN Position */
#define CRYPTO_AES_ERR_EN_Msk       (1ul << CRYPTO_AES_ERR_EN_Pos)     /*!<CRYPTO CRYPTO_INT_EN: AES_ERR_EN Mask */
#define CRYPTO_TDES_INT_EN_Pos      8                                  /*!<CRYPTO CRYPTO_INT_EN: TDES_INT_EN Position */
#define CRYPTO_TDES_INT_EN_Msk      (1ul << CRYPTO_TDES_INT_EN_Pos)    /*!<CRYPTO CRYPTO_INT_EN: TDES_INT_EN Mask */
#define CRYPTO_TDES_ERR_EN_Pos      9                                  /*!<CRYPTO CRYPTO_INT_EN: TDES_ERR_EN Position */
#define CRYPTO_TDES_ERR_EN_Msk      (1ul << CRYPTO_TDES_ERR_EN_Pos)    /*!<CRYPTO CRYPTO_INT_EN: TDES_ERR_EN Mask */
#define CRYPTO_PRNG_INT_EN_Pos      16                                 /*!<CRYPTO CRYPTO_INT_EN: PRNG_INT_EN Position */
#define CRYPTO_PRNG_INT_EN_Msk      (1ul << CRYPTO_PRNG_INT_EN_Pos)    /*!<CRYPTO CRYPTO_INT_EN: PRNG_INT_EN Mask */
#define CRYPTO_SHA_INT_EN_Pos       24                                 /*!<CRYPTO CRYPTO_INT_EN: SHA_INT_EN Position */
#define CRYPTO_SHA_INT_EN_Msk       (1ul << CRYPTO_SHA_INT_EN_Pos)     /*!<CRYPTO CRYPTO_INT_EN: SHA_INT_EN Mask */
#define CRYPTO_SHA_ERR_EN_Pos       25                                 /*!<CRYPTO CRYPTO_INT_EN: SHA_ERR_EN Position */
#define CRYPTO_SHA_ERR_EN_Msk       (1ul << CRYPTO_SHA_ERR_EN_Pos)     /*!<CRYPTO CRYPTO_INT_EN: SHA_ERR_EN Mask */

/********************* Bit definition of CRYPTO_INT_FLAG register **********************/
#define CRYPTO_AES_INT_FLAG_Pos     0                                  /*!<CRYPTO CRYPTO_INT_FLAG: AES_INT_FLAG Position */
#define CRYPTO_AES_INT_FLAG_Msk     (1ul << CRYPTO_AES_INT_FLAG_Pos)   /*!<CRYPTO CRYPTO_INT_FLAG: AES_INT_FLAG Mask */
#define CRYPTO_AES_ERR_FLAG_Pos     1                                  /*!<CRYPTO CRYPTO_INT_FLAG: AES_ERR_FLAG Position */
#define CRYPTO_AES_ERR_FLAG_Msk     (1ul << CRYPTO_AES_ERR_FLAG_Pos)   /*!<CRYPTO CRYPTO_INT_FLAG: AES_ERR_FLAG Mask */
#define CRYPTO_TDES_INT_FLAG_Pos    8                                  /*!<CRYPTO CRYPTO_INT_FLAG: TDES_INT_FLAG Position */
#define CRYPTO_TDES_INT_FLAG_Msk    (1ul << CRYPTO_TDES_INT_FLAG_Pos)  /*!<CRYPTO CRYPTO_INT_FLAG: TDES_INT_FLAG Mask */
#define CRYPTO_TDES_ERR_FLAG_Pos    9                                  /*!<CRYPTO CRYPTO_INT_FLAG: TDES_ERR_FLAG Position */
#define CRYPTO_TDES_ERR_FLAG_Msk    (1ul << CRYPTO_TDES_ERR_FLAG_Pos)  /*!<CRYPTO CRYPTO_INT_FLAG: TDES_ERR_FLAG Mask */
#define CRYPTO_PRNG_INT_FLAG_Pos    16                                 /*!<CRYPTO CRYPTO_INT_FLAG: PRNG_INT_FLAG Position */
#define CRYPTO_PRNG_INT_FLAG_Msk    (1ul << CRYPTO_PRNG_INT_FLAG_Pos)  /*!<CRYPTO CRYPTO_INT_FLAG: PRNG_INT_FLAG Mask */
#define CRYPTO_SHA_INT_FLAG_Pos     24                                 /*!<CRYPTO CRYPTO_INT_FLAG: SHA_INT_FLAG Position */
#define CRYPTO_SHA_INT_FLAG_Msk     (1ul << CRYPTO_SHA_INT_FLAG_Pos)   /*!<CRYPTO CRYPTO_INT_FLAG: SHA_INT_FLAG Mask */
#define CRYPTO_SHA_ERR_FLAG_Pos     25                                 /*!<CRYPTO CRYPTO_INT_FLAG: SHA_ERR_FLAG Position */
#define CRYPTO_SHA_ERR_FLAG_Msk     (1ul << CRYPTO_SHA_ERR_FLAG_Pos)   /*!<CRYPTO CRYPTO_INT_FLAG: SHA_ERR_FLAG Mask */

/********************* Bit definition of PRNG_CTL register **********************/
#define CRYPTO_PRNG_START_Pos       0                                  /*!<CRYPTO PRNG_CTL: PRNG_START Position */
#define CRYPTO_PRNG_START_Msk       (1ul << CRYPTO_PRNG_START_Pos)     /*!<CRYPTO PRNG_CTL: PRNG_START Mask */
#define CRYPTO_PRNG_SEED_RELOAD_Pos 1                                  /*!<CRYPTO PRNG_CTL: PRNG_SEDD_RELOAD Position */
#define CRYPTO_PRNG_SEED_RELOAD_Msk (1ul << CRYPTO_PRNG_SEED_RELOAD_Pos) /*!<CRYPTO PRNG_CTL: PENG_SEDD_RELOAD Mask */
#define CRYPTO_PRNG_KEY_SIZE_Pos    2                                  /*!<CRYPTO PRNG_CTL: PRNG_KEY_SIZE Position */
#define CRYPTO_PRNG_KEY_SIZE_Msk    (3ul << CRYPTO_PRNG_KEY_SIZE_Pos)  /*!<CRYPTO PRNG_CTL: PRNG_KEY_SIZE Mask */
#define CRYPTO_PRNG_BUSY_Pos        8                                  /*!<CRYPTO PRNG_CTL: PRNG_BUSY Position */
#define CRYPTO_PRNG_BUSY_Msk        (1ul << CRYPTO_PRNG_BUSY_Pos)      /*!<CRYPTO PRNG_CTL: PRNG_BUSY Mask */

/********************* Bit definition of AES_CTL register **********************/
#define CRYPTO_AES_START_Pos        0                                  /*!<CRYPTO AES_CTL: AES_START Position */
#define CRYPTO_AES_START_Msk        (1ul << CRYPTO_AES_START_Pos)      /*!<CRYPTO AES_CTL: AES_START Mask */
#define CRYPTO_AES_STOP_Pos         1                                  /*!<CRYPTO AES_CTL: AES_STOP Position */
#define CRYPTO_AES_STOP_Msk         (1ul << CRYPTO_AES_STOP_Pos)       /*!<CRYPTO AES_CTL: AES_STOP Mask */
#define CRYPTO_AES_KEY_SIZE_Pos     2                                  /*!<CRYPTO AES_CTL: AES_KEY_SIZE Position */
#define CRYPTO_AES_KEY_SIZE_Msk     (3ul << CRYPTO_AES_KEY_SIZE_Pos)   /*!<CRYPTO AES_CTL: AES_KEY_SIZE Mask */
#define CRYPTO_AES_LAST_Pos         5                                  /*!<CRYPTO AES_CTL: AES_LAST Position */
#define CRYPTO_AES_LAST_Msk         (1ul << CRYPTO_AES_LAST_Pos)       /*!<CRYPTO AES_CTL: AES_LAST Mask */
#define CRYPTO_AES_DMA_CASCADE_Pos  6                                  /*!<CRYPTO AES_CTL: AES_DMA_CASCADE Position */
#define CRYPTO_AES_DMA_CASCADE_Msk  (1ul << CRYPTO_AES_DMA_CASCADE_Pos)/*!<CRYPTO AES_CTL: AES_DMA_CASCADE Mask */
#define CRYPTO_AES_DMA_EN_Pos       7                                  /*!<CRYPTO AES_CTL: AES_DMA_EN Position */
#define CRYPTO_AES_DMA_EN_Msk       (1ul << CRYPTO_AES_DMA_EN_Pos)     /*!<CRYPTO AES_CTL: AES_DMA_EN Mask */
#define CRYPTO_AES_OP_MODE_Pos      8                                  /*!<CRYPTO AES_CTL: AES_OP_MODE Position */
#define CRYPTO_AES_OP_MODE_Msk      (0xfful << CRYPTO_AES_OP_MODE_Pos) /*!<CRYPTO AES_CTL: AES_OP_MODE Mask */
#define CRYPTO_AES_E_D_Pos          16                                 /*!<CRYPTO AES_CTL: AES_E_D Position */
#define CRYPTO_AES_E_D_Msk          (1ul << CRYPTO_AES_E_D_Pos)        /*!<CRYPTO AES_CTL: AES_E_D Mask */
#define CRYPTO_AES_OUT_SWAP_Pos     22                                 /*!<CRYPTO AES_CTL: AES_OUT_SWAP Position */
#define CRYPTO_AES_OUT_SWAP_Msk     (1ul << CRYPTO_AES_OUT_SWAP_Pos)   /*!<CRYPTO AES_CTL: AES_OUT_SWAP Mask */
#define CRYPTO_AES_IN_SWAP_Pos      23                                 /*!<CRYPTO AES_CTL: AES_IN_SWAP Position */
#define CRYPTO_AES_IN_SWAP_Msk      (1ul << CRYPTO_AES_IN_SWAP_Pos)    /*!<CRYPTO AES_CTL: AES_IN_SWAP Mask */
#define CRYPTO_AES_CHANNEL_Pos      24                                 /*!<CRYPTO AES_CTL: AES_CHANNEL Position */
#define CRYPTO_AES_CHANNEL_Msk      (3ul << CRYPTO_AES_CHANNEL_Pos)    /*!<CRYPTO AES_CTL: AES_CHANNEL Mask */
#define CRYPTO_AES_KEY_UNPROTECT_Pos 26                                /*!<CRYPTO AES_CTL: AES_KEY_UNPROTECT Position */
#define CRYPTO_AES_KEY_UNPROTECT_Msk (0x1ful << CRYPTO_AES_KEY_UNPROTECT_Pos) /*!<CRYPTO AES_CTL: AES_KEY_UNPROTECT Mask */
#define CRYPTO_AES_KEY_PROTECT_Pos  31                                 /*!<CRYPTO AES_CTL: AES_KEY_PROTECT Position */
#define CRYPTO_AES_KEY_PROTECT_Msk  (1ul << CRYPTO_AES_KEY_PROTECT_Pos)/*!<CRYPTO AES_CTL: AES_KEY_PROTECT Mask */

/********************* Bit definition of AES_FLAG register **********************/
#define CRYPTO_AES_BUSY_Pos           0                                /*!<CRYPTO AES_FLAG: AES_BUSY Position */
#define CRYPTO_AES_BUSY_Msk           (1ul << CRYPTO_AES_BUSY_Pos)     /*!<CRYPTO AES_FLAG: AES_BUSY Mask */
#define CRYPTO_AES_IN_BUFF_EMPTY_Pos  8                                /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_EMPTY Position */
#define CRYPTO_AES_IN_BUFF_EMPTY_Msk  (1ul << CRYPTO_AES_IN_BUFF_EMPTY_Pos)  /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_EMPTY Mask */
#define CRYPTO_AES_IN_BUFF_FULL_Pos   9                                /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_FULL Position */
#define CRYPTO_AES_IN_BUFF_FULL_Msk   (1ul << CRYPTO_AES_IN_BUFF_FULL_Pos)   /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_FULL Mask */
#define CRYPTO_AES_IN_BUFF_ERR_Pos    10                               /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_ERROR Position */
#define CRYPTO_AES_IN_BUFF_ERR_Msk    (1ul << CRYPTO_AES_IN_BUFF_ERR_Pos)    /*!<CRYPTO AES_FLAG: AES_IN_BUFFER_ERROR Mask */
#define CRYPTO_AES_CNT_ERR_Pos        12                               /*!<CRYPTO AES_FLAG: AES_CNT_ERR Position */
#define CRYPTO_AES_CNT_ERR_Msk        (1ul << CRYPTO_AES_CNT_ERR_Pos)  /*!<CRYPTO AES_FLAG: AES_CNT_ERR Mask */
#define CRYPTO_AES_OUT_BUFF_EMPTY_Pos 16                               /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_EMPTY Position */
#define CRYPTO_AES_OUT_BUFF_EMPTY_Msk (1ul << CRYPTO_AES_OUT_BUFF_EMPTY_Pos) /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_EMPTY Mask */
#define CRYPTO_AES_OUT_BUFF_FULL_Pos  17                               /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_FULL Position */
#define CRYPTO_AES_OUT_BUFF_FULL_Msk  (1ul << CRYPTO_AES_OUT_BUFF_FULL_Pos)  /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_FULL Mask */
#define CRYPTO_AES_OUT_BUFF_ERR_Pos   18                               /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_ERROR Position */
#define CRYPTO_AES_OUT_BUFF_ERR_Msk   (1ul << CRYPTO_AES_OUT_BUFF_ERR_Pos)   /*!<CRYPTO AES_FLAG: AES_OUT_BUFFER_ERROR Mask */
#define CRYPTO_AES_BUS_ERR_Pos        20                               /*!<CRYPTO AES_FLAG: AES_BUS_ERR Position */
#define CRYPTO_AES_BUS_ERR_Msk        (1ul << CRYPTO_AES_BUS_ERR_Pos)  /*!<CRYPTO AES_FLAG: AES_BUS_ERR Mask */

/********************* Bit definition of TDES_CTL register **********************/
#define CRYPTO_TDES_START_Pos       0                                  /*!<CRYPTO TDES_CTL: TDES_START Position */
#define CRYPTO_TDES_START_Msk       (1ul << CRYPTO_TDES_START_Pos)     /*!<CRYPTO TDES_CTL: TDES_START Mask */
#define CRYPTO_TDES_STOP_Pos        1                                  /*!<CRYPTO TDES_CTL: TDES_STOP Position */
#define CRYPTO_TDES_STOP_Msk        (1ul << CRYPTO_TDES_STOP_Pos)      /*!<CRYPTO TDES_CTL: TDES_STOP Mask */
#define CRYPTO_TDES_TRIPLE_MODE_Pos 2                                  /*!<CRYPTO TDES_CTL: TDES_TRIPLE_MODE Position */
#define CRYPTO_TDES_TRIPLE_MODE_Msk (1ul << CRYPTO_TDES_TRIPLE_MODE_Pos)   /*!<CRYPTO TDES_CTL: TDES_TRIPLE_MODE Mask */
#define CRYPTO_TDES_3KEYS_Pos       3                                  /*!<CRYPTO TDES_CTL: TDES_3KEYS Position */
#define CRYPTO_TDES_3KEYS_Msk       (1ul << CRYPTO_TDES_3KEYS_Pos)     /*!<CRYPTO TDES_CTL: TDES_3KEYS Mask */
#define CRYPTO_TDES_LAST_START_Pos  5                                  /*!<CRYPTO TDES_CTL: TDES_LAST_START Position */
#define CRYPTO_TDES_LAST_START_Msk  (1ul << CRYPTO_TDES_LAST_START_Pos)/*!<CRYPTO TDES_CTL: TDES_LAST_START Mask */
#define CRYPTO_TDES_CASCADE_Pos     6                                  /*!<CRYPTO TDES_CTL: TDES_CASCADE Position */
#define CRYPTO_TDES_CASCADE_Msk     (1ul << CRYPTO_TDES_CASCADE_Pos)   /*!<CRYPTO TDES_CTL: TDES_CASCADE Mask */
#define CRYPTO_TDES_DMA_EN_Pos      7                                  /*!<CRYPTO TDES_CTL: TDES_DMA_EN Position */
#define CRYPTO_TDES_DMA_EN_Msk      (1ul << CRYPTO_TDES_DMA_EN_Pos)    /*!<CRYPTO TDES_CTL: TDES_DMA_EN Mask */
#define CRYPTO_TDES_OP_MODE_Pos     8                                  /*!<CRYPTO TDES_CTL: TDES_OP_MODE Position */
#define CRYPTO_TDES_OP_MODE_Msk     (7ul << CRYPTO_TDES_DMA_EN_Pos)    /*!<CRYPTO TDES_CTL: TDES_OP_MODE Mask */
#define CRYPTO_TDES_E_D_Pos         16                                 /*!<CRYPTO TDES_CTL: TDES_E_D Position */
#define CRYPTO_TDES_E_D_Msk         (1ul << CRYPTO_TDES_E_D_Pos)       /*!<CRYPTO TDES_CTL: TDES_E_D Mask */
#define CRYPTO_TDES_BLK_FMT_Pos     21                                 /*!<CRYPTO TDES_CTL: TDES_BLOCK_FORMAT Position */
#define CRYPTO_TDES_BLK_FMT_Msk     (1ul << CRYPTO_TDES_BLK_FMT_Pos)   /*!<CRYPTO TDES_CTL: TDES_BLOCK_FORMAT Mask */
#define CRYPTO_TDES_OUT_SWAP_Pos    22                                 /*!<CRYPTO TDES_CTL: TDES_OUT_SWAP Position */
#define CRYPTO_TDES_OUT_SWAP_Msk    (1ul << CRYPTO_TDES_OUT_SWAP_Pos)  /*!<CRYPTO TDES_CTL: TDES_OUT_SWAP Mask */
#define CRYPTO_TDES_IN_SWAP_Pos     23                                 /*!<CRYPTO TDES_CTL: TDES_IN_SWAP Position */
#define CRYPTO_TDES_IN_SWAP_Msk     (1ul << CRYPTO_TDES_IN_SWAP_Pos)   /*!<CRYPTO TDES_CTL: TDES_IN_SWAP Mask */
#define CRYPTO_TDES_CHANNEL_Pos     24                                 /*!<CRYPTO TDES_CTL: TDES_CHANNEL Position */
#define CRYPTO_TDES_CHANNEL_Msk     (3ul << CRYPTO_TDES_CHANNEL_Pos)   /*!<CRYPTO TDES_CTL: TDES_CHANNEL Mask */
#define CRYPTO_TDES_KEY_UNPROTECT_Pos 26                               /*!<CRYPTO TDES_CTL: TDES_KEY_UNPROTECT Position */
#define CRYPTO_TDES_KEY_UNPROTECT_Msk (0x1ful << CRYPTO_TDES_KEY_UNPROTECT_Pos) /*!<CRYPTO TDES_CTL: TDES_KEY_UNPROTECT Mask */
#define CRYPTO_TDES_KEY_PROTECT_Pos 31                                 /*!<CRYPTO TDES_CTL: TDES_KEY_PROTECT Position */
#define CRYPTO_TDES_KEY_PROTECT_Msk (1ul << CRYPTO_TDES_KEY_PROTECT_Pos)    /*!<CRYPTO TDES_CTL: TDES_KEY_PROTECT Mask */

/********************* Bit definition of TDES_FLAG register **********************/
#define CRYPTO_TDES_BUSY_Pos          0                                /*!<CRYPTO TDES_FLAG: TDES_BUSY Position */
#define CRYPTO_TDES_BUSY_Msk          (1ul << CRYPTO_TDES_BUSY_Pos)    /*!<CRYPTO TDES_FLAG: TDES_BUSY Mask */
#define CRYPTO_TDES_IN_BUFF_EMPTY_Pos 8                                /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_EMPTY Position */
#define CRYPTO_TDES_IN_BUFF_EMPTY_Msk (1ul << CRYPTO_TDES_IN_BUFF_EMPTY_Pos)  /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_EMPTY Mask */
#define CRYPTO_TDES_IN_BUFF_FULL_Pos  9                                /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_FULL Position */
#define CRYPTO_TDES_IN_BUFF_FULL_Msk  (1ul << CRYPTO_TDES_IN_BUFF_FULL_Pos)   /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_FULL Mask */
#define CRYPTO_TDES_IN_BUFF_ERR_Pos   10                               /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_ERROR Position */
#define CRYPTO_TDES_IN_BUFF_ERR_Msk   (1ul << CRYPTO_TDES_IN_BUFF_ERR_Pos)    /*!<CRYPTO TDES_FLAG: TDES_IN_BUFFER_ERROR Mask */
#define CRYPTO_TDES_OUT_BUFF_EMPTY_Pos 16                              /*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_EMPTY Position */
#define CRYPTO_TDES_OUT_BUFF_EMPTY_Msk (1ul << CRYPTO_TDES_OUT_BUFF_EMPTY_Pos)/*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_EMPTY Mask */
#define CRYPTO_TDES_OUT_BUFF_FULL_Pos 17                               /*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_FULL Position */
#define CRYPTO_TDES_OUT_BUFF_FULL_Msk (1ul << CRYPTO_TDES_OUT_BUFF_FULL_Pos)  /*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_FULL Mask */
#define CRYPTO_TDES_OUT_BUFF_ERR_Pos  18                               /*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_ERROR Position */
#define CRYPTO_TDES_OUT_BUFF_ERR_Msk  (1ul << CRYPTO_TDES_OUT_BUFF_ERR_Pos)   /*!<CRYPTO TDES_FLAG: TDES_OUT_BUFFER_ERROR Mask */

/********************* Bit definition of SHA_CTL register **********************/
#define CRYPTO_SHA_START_Pos        0                                  /*!<CRYPTO SHA_CTL: SHA_START Position */
#define CRYPTO_SHA_START_Msk        (1ul << CRYPTO_SHA_START_Pos)      /*!<CRYPTO SHA_CTL: SHA_START Mask */
#define CRYPTO_SHA_STOP_Pos         1                                  /*!<CRYPTO SHA_CTL: SHA_STOP Position */
#define CRYPTO_SHA_STOP_Msk         (1ul << CRYPTO_SHA_STOP_Pos)       /*!<CRYPTO SHA_CTL: SHA_STOP Mask */
#define CRYPTO_SHA_LAST_Pos         5                                  /*!<CRYPTO SHA_CTL: SHA_LAST Position */
#define CRYPTO_SHA_LAST_Msk         (1ul << CRYPTO_SHA_LAST_Pos)       /*!<CRYPTO SHA_CTL: SHA_LAST Mask */
#define CRYPTO_SHA_DMA_EN_Pos       7                                  /*!<CRYPTO SHA_CTL: SHA_DMA_EN Position */
#define CRYPTO_SHA_DMA_EN_Msk       (1ul << CRYPTO_SHA_DMA_EN_Pos)     /*!<CRYPTO SHA_CTL: SHA_DMA_EN Mask */
#define CRYPTO_SHA_OP_MODE_Pos      8                                  /*!<CRYPTO SHA_CTL: SHA_OP_MODE Position */
#define CRYPTO_SHA_OP_MODE_Msk      (7ul << CRYPTO_SHA_OP_MODE_Pos)    /*!<CRYPTO SHA_CTL: SHA_OP_MODE Mask */
#define CRYPTO_SHA_OUT_SWAP_Pos     22                                 /*!<CRYPTO SHA_CTL: SHA_OUT_SWAP Position */
#define CRYPTO_SHA_OUT_SWAP_Msk     (1ul << CRYPTO_SHA_OUT_SWAP_Pos)   /*!<CRYPTO SHA_CTL: SHA_OUT_SWAP Mask */
#define CRYPTO_SHA_IN_SWAP_Pos      23                                 /*!<CRYPTO SHA_CTL: SHA_IN_SWAP Position */
#define CRYPTO_SHA_IN_SWAP_Msk      (1ul << CRYPTO_SHA_IN_SWAP_Pos)    /*!<CRYPTO SHA_CTL: SHA_IN_SWAP Mask */

/********************* Bit definition of SHA_FLAG register **********************/
#define CRYPTO_SHA_BUSY_Pos         0                                  /*!<CRYPTO SHA_FLAG: SHA_BUSY Position */
#define CRYPTO_SHA_BUSY_Msk         (1ul << CRYPTO_SHA_BUSY_Pos)       /*!<CRYPTO SHA_FLAG: SHA_BUSY Mask */
#define CRYPTO_SHA_DMA_BUSY_Pos     1                                  /*!<CRYPTO SHA_FLAG: SHA_DMA_BUSY Position */
#define CRYPTO_SHA_DMA_BUSY_Msk     (1ul << CRYPTO_SHA_DMA_BUSY_Pos)   /*!<CRYPTO SHA_FLAG: SHA_DMA_BUSY Mask */
#define CRYPTO_SHA_DMA_ERR_Pos      8                                  /*!<CRYPTO SHA_FLAG: SHA_DMA_ERR Position */
#define CRYPTO_SHA_DMA_ERR_Msk      (1ul << CRYPTO_SHA_DMA_ERR_Pos)    /*!<CRYPTO SHA_FLAG: SHA_DMA_ERR Mask */
#define CRYPTO_SHA_DIN_REQ_Pos      16                                 /*!<CRYPTO SHA_FLAG: SHA_DIN_REQ Position */
#define CRYPTO_SHA_DIN_REQ_Msk      (1ul << CRYPTO_SHA_DIN_REQ_Pos)    /*!<CRYPTO SHA_FLAG: SHA_DIN_REQ Mask */

/*@}*/ /* end of group NUC400_CRYPTO */


/*------------- Image Capture Interface Register (CAP) -----------------------------*/
/** @addtogroup NUC400_CAP NUC400 Image Capture Interface Register (CAP)
  @{
*/
typedef struct {
    __IO uint32_t CAPCTL;                /*!< Offset: 0x0000  Image Capture Control Register */
    __IO uint32_t CAPPAR;                /*!< Offset: 0x0004  Image Capture Parameter Register */
    __IO uint32_t CAPINT;                /*!< Offset: 0x0008  Image Capture Interrupt Register */
    __IO uint32_t POSTERIZE;             /*!< Offset: 0x000C  YUV Component Posterizing Factor Register */
    __IO uint32_t MD;                    /*!< Offset: 0x0010  Motion Detection Register */
    __IO uint32_t MDADDR;                /*!< Offset: 0x0014  Motion Detection Output Address Register */
    __IO uint32_t MDYADDR;               /*!< Offset: 0x0018  Motion Detection Temp Y Output Address Register */
    __IO uint32_t SEPIA;                 /*!< Offset: 0x001C  Sepia Effect Control Register */
    __IO uint32_t CWSP;                  /*!< Offset: 0x0020  Cropping Window Starting Address Register */
    __IO uint32_t CWS;                   /*!< Offset: 0x0024  Cropping Window Size Register */
    __IO uint32_t PKDSL;                 /*!< Offset: 0x0028  Packet Scaling Vertical/Horizontal Factor Register (LSB)*/
    __IO uint32_t PNDSL;                 /*!< Offset: 0x002C  Planar Scaling Vertical/Horizontal Factor Register (LSB)*/
    __IO uint32_t FRC;                   /*!< Offset: 0x0030  Scaling Frame Rate Factor Register*/
    __IO uint32_t STRIDE;                /*!< Offset: 0x0034  Frame Output Pixel Stride Width Register*/
    uint32_t RESERVED0[1];          /*!< Offset: 0x0038  Reserved */
    __IO uint32_t FIFO_THD;              /*!< Offset: 0x003C  FIFO Threshold Register*/
    __IO uint32_t CMPADDR;               /*!< Offset: 0x0040  Compare Memory Base Address Register */
    uint32_t RESERVED1[1];          /*!< Offset: 0x0044  Reserved */
    __IO uint32_t PKDSH;                 /*!< Offset: 0x0048  Packet Scaling Vertical/Horizontal Factor Register (MSB)*/
    __IO uint32_t PNDSH;                 /*!< Offset: 0x004C  Planar Scaling Vertical/Horizontal Factor Register (MSB)*/
    __IO uint32_t CURADDRP;              /*!< Offset: 0x0050  Current Packet Output Memory Size Register */
    __IO uint32_t CURADDRY;              /*!< Offset: 0x0054  Current Planar Y Output Memory Size Register */
    __IO uint32_t CURADDRU;              /*!< Offset: 0x0058  Current Planar U Output Memory Size Register */
    __IO uint32_t CURADDRV;              /*!< Offset: 0x005C  Current Planar V Output Memory Size Register */
    __IO uint32_t PACBA0;                /*!< Offset: 0x0060  System Memory Packet Base Address 0 Register */
    __IO uint32_t PACBA1;                /*!< Offset: 0x0064  System Memory Packet Base Address 1 Register */
    uint32_t RESERVED2[6];          /*!< Offset: 0x0068 ~0x7C Reserved */
    __IO uint32_t YBA0;                  /*!< Offset: 0x0080  System Memory Planar Y Base Address Register */
    __IO uint32_t UBA0;                  /*!< Offset: 0x0084  System Memory Planar U Base Address Register */
    __IO uint32_t VBA0;                  /*!< Offset: 0x0088  System Memory Planar V Base Address Register */
} CAP_T;

/* CAP CAPCTL Bit Field Definitions */
#define CAP_CAPCTL_CAPEN_Pos      0                                   /*!< CAP CAPCTL: CAPEN Position */
#define CAP_CAPCTL_CAPEN_Msk      (1ul<<CAP_CAPCTL_CAPEN_Pos)         /*!< CAP CAPCTL: CAPEN Mask */

#define CAP_CAPCTL_ADDRSW_Pos     3                                   /*!< CAP CAPCTL: ADDRSW Position */
#define CAP_CAPCTL_ADDRSW_Msk     (1ul<<CAP_CAPCTL_ADDRSW_Pos)        /*!< CAP CAPCTL: ADDRSW Mask */

#define CAP_CAPCTL_PNEN_Pos       5                                   /*!< CAP CAPCTL: PNEN Position */
#define CAP_CAPCTL_PNEN_Msk       (1ul<<CAP_CAPCTL_PNEN_Pos)          /*!< CAP CAPCTL: PNEN Mask */

#define CAP_CAPCTL_PKEN_Pos       6                                   /*!< CAP CAPCTL: PKEN Position */
#define CAP_CAPCTL_PKEN_Msk       (1ul<<CAP_CAPCTL_PKEN_Pos)          /*!< CAP CAPCTL: PKEN Mask */

#define CAP_CAPCTL_BIST_Pos       8                                   /*!< CAP CAPCTL: BIST Position */
#define CAP_CAPCTL_BIST_Msk       (1ul<<CAP_CAPCTL_BIST_Pos)          /*!< CAP CAPCTL: BIST Mask */

#define CAP_CAPCTL_SHUTTER_Pos    16                                  /*!< CAP CAPCTL: SHUTTER Position */
#define CAP_CAPCTL_SHUTTER_Msk    (1ul<<CAP_CAPCTL_SHUTTER_Pos)       /*!< CAP CAPCTL: SHUTTER Mask */

#define CAP_CAPCTL_UPDATE_Pos     20                                  /*!< CAP CAPCTL: UPDATE Position */
#define CAP_CAPCTL_UPDATE_Msk     (1ul<<CAP_CAPCTL_UPDATE_Pos)        /*!< CAP CAPCTL: UPDATE Mask */

#define CAP_CAPCTL_VPRST_Pos      24                                  /*!< CAP CAPCTL: VPRST Position */
#define CAP_CAPCTL_VPRST_Msk      (1ul<<CAP_CAPCTL_VPRST_Pos)         /*!< CAP CAPCTL: VPRST Mask */

/* CAP CAPPAR Bit Field Definitions */
#define CAP_CAPPAR_INFMT_Pos      0                                   /*!< CAP CAPPAR: INFMT Position */
#define CAP_CAPPAR_INFMT_Msk      (1ul<<CAP_CAPPAR_INFMT_Pos)         /*!< CAP CAPPAR: INFMT Mask */

#define CAP_CAPPAR_SNRTYPE_Pos    1                                   /*!< CAP CAPPAR: SNRTYPE Position */
#define CAP_CAPPAR_SNRTYPE_Msk    (1ul<<CAP_CAPPAR_SNRTYPE_Pos)       /*!< CAP CAPPAR: SNRTYPE Mask */

#define CAP_CAPPAR_PDORD_Pos      2                                   /*!< CAP CAPPAR: PDORD Position */
#define CAP_CAPPAR_PDORD_Msk      (0x3ul<<CAP_CAPPAR_PDORD_Pos)       /*!< CAP CAPPAR: PDORD Mask */

#define CAP_CAPPAR_OUTFMT_Pos     4                                   /*!< CAP CAPPAR: OUTFMT Position */
#define CAP_CAPPAR_OUTFMT_Msk     (0x3ul<<CAP_CAPPAR_OUTFMT_Pos)      /*!< CAP CAPPAR: OUTFMT Mask */

#define CAP_CAPPAR_RANGE_Pos      6                                   /*!< CAP CAPPAR: RANGE Position */
#define CAP_CAPPAR_RANGE_Msk      (1ul<<CAP_CAPPAR_RANGE_Pos)         /*!< CAP CAPPAR: RANGE Mask */

#define CAP_CAPPAR_PNFMT_Pos      7                                   /*!< CAP CAPPAR: PNFMT Position */
#define CAP_CAPPAR_PNFMT_Msk      (1ul<<CAP_CAPPAR_PNFMT_Pos)         /*!< CAP CAPPAR: PNFMT Mask */

#define CAP_CAPPAR_PCLKP_Pos      8                                   /*!< CAP CAPPAR: PCLKP Position */
#define CAP_CAPPAR_PCLKP_Msk      (1ul<<CAP_CAPPAR_PCLKP_Pos)         /*!< CAP CAPPAR: PCLKP Mask */

#define CAP_CAPPAR_HSP_Pos        9                                   /*!< CAP CAPPAR: HSP Position */
#define CAP_CAPPAR_HSP_Msk        (1ul<<CAP_CAPPAR_HSP_Pos)           /*!< CAP CAPPAR: HSP Mask */

#define CAP_CAPPAR_VSP_Pos        10                                  /*!< CAP CAPPAR: VSP Position */
#define CAP_CAPPAR_VSP_Msk        (1ul<<CAP_CAPPAR_VSP_Pos)           /*!< CAP CAPPAR: VSP Mask */

#define CAP_CAPPAR_Color_Effect_Pos    11                                          /*!< CAP CAPPAR: Color_Effect Position */
#define CAP_CAPPAR_Color_Effect_Msk    (0x3ul<<CAP_CAPPAR_VColor_EFFect_Pos)       /*!< CAP CAPPAR: Color_Effect Mask */

#define CAP_CAPPAR_FBB_Pos        18                                  /*!< CAP CAPPAR: FBB Position */
#define CAP_CAPPAR_FBB_Msk        (1ul<<CAP_CAPPAR_FBB_Pos)           /*!< CAP CAPPAR: FBB Mask */

#define CAP_CAPPAR_BFAIL_Pos      24                                  /*!< CAP CAPPAR: FBB Position */
#define CAP_CAPPAR_BFAIL_Msk      (0xFul<<CAP_CAPPAR_BFAIL_Pos)       /*!< CAP CAPPAR: FBB Mask */

#define CAP_CAPPAR_BFIN_Pos       28                                  /*!< CAP CAPPAR: BFIN Position */
#define CAP_CAPPAR_BFIN_Msk       (1ul<<CAP_CAPPAR_CAPBFIN_Pos)       /*!< CAP CAPPAR: BFIN Mask */

/* CAP CAPINT Bit Field Definitions */
#define CAP_CAPINT_VINT_Pos    0                                      /*!< CAP CAPINT: VINT Position */
#define CAP_CAPINT_VINT_Msk    (1ul<<CAP_CAPINT_VINT_Pos)             /*!< CAP CAPINT: VINT Mask */

#define CAP_CAPINT_MEINT_Pos    1                                     /*!< CAP CAPINT: MEINT Position */
#define CAP_CAPINT_MEINT_Msk    (1ul<<CAP_CAPINT_MEINT_Pos)           /*!< CAP CAPINT: MEINT Mask */

#define CAP_CAPINT_ADDRMINT_Pos    3                                  /*!< CAP CAPINT: ADDRMINT Position */
#define CAP_CAPINT_ADDRMINT_Msk    (1ul<<CAP_CAPINT_ADDRMINT_Pos)     /*!< CAP CAPINT: ADDRMINT Mask */

#define CAP_CAPINT_MDINT_Pos    4                                     /*!< CAP CAPINT: MDINT Position */
#define CAP_CAPINT_MDINT_Msk    (1ul<<CAP_CAPINT_MDINT_Pos)           /*!< CAP CAPINT: MDINT Mask */

#define CAP_CAPINT_VINTEN_Pos    16                                   /*!< CAP CAPINT: VINTEN Position */
#define CAP_CAPINT_VINTEN_Msk    (1ul<<CAP_CAPINT_VINTEN_Pos)         /*!< CAP CAPINT: VINTEN Mask */

#define CAP_CAPINT_MEINTEN_Pos    17                                  /*!< CAP CAPINT: MEINTEN Position */
#define CAP_CAPINT_MEINTEN_Msk    (1ul<<CAP_CAPINT_MEINTEN_Pos)       /*!< CAP CAPINT: MEINTEN Mask */

#define CAP_CAPINT_ADDRMEN_Pos    19                                  /*!< CAP CAPINT: ADDRMEN Position */
#define CAP_CAPINT_ADDRMEN_Msk    (1ul<<CAP_CAPINT_ADDRMEN_Pos)       /*!< CAP CAPINT: ADDRMEN Mask */

#define CAP_CAPINT_MDINTEN_Pos    20                                  /*!< CAP CAPINT: MDINTEN Position */
#define CAP_CAPINT_MDINTEN_Msk    (1ul<<CAP_CAPINT_MDINTEN_Pos)       /*!< CAP CAPINT: MDINTEN Mask */

/* CAP VPOSTERIZE Bit Field Definitions */

#define CAP_POSTERIZE_Y_Pos    0                                      /*!< CAP POSTERIZE: Y Position */
#define CAP_POSTERIZE_Y_Msk    (0xFFul<<CAP_POSTERIZE_Y_Pos)          /*!< CAP POSTERIZE: Y Mask */
#define CAP_POSTERIZE_U_Pos    8                                      /*!< CAP POSTERIZE: U Position */
#define CAP_POSTERIZE_U_Msk    (0xFFul<<CAP_POSTERIZE_U_Pos)          /*!< CAP POSTERIZE: U Mask */
#define CAP_POSTERIZE_V_Pos    16                                     /*!< CAP POSTERIZE: V Position */
#define CAP_POSTERIZE_V_Msk    (0xFFul<<CAP_POSTERIZE_V_Pos)          /*!< CAP POSTERIZE: V Mask */


/* CAP MD Bit Field Definitions */

#define CAP_MD_MDEN_Pos        0                                   /*!< CAP MD: MDEN Position */
#define CAP_MD_MDEN_Msk        (1ul<<CAP_MD_MDEN_Pos)              /*!< CAP MD: MDEN Mask */

#define CAP_MD_MDBS_Pos        8                                   /*!< CAP MD: MDBS Position */
#define CAP_MD_MDBS_Msk        (1ul<<CAP_MD_MDBS_Pos)              /*!< CAP MD: MDBS Mask */

#define CAP_MD_MDSM_Pos        9                                   /*!< CAP MD: MDSM Position */
#define CAP_MD_MDSM_Msk        (1ul<<CAP_MD_MDSM_Pos)              /*!< CAP MD: MDSM Mask */

#define CAP_MD_MDDF_Pos        10                                  /*!< CAP MD: MDDF Position */
#define CAP_MD_MDDF_Msk        (0x3ul<<CAP_MD_MDDF_Pos)            /*!< CAP MD: MDDF Mask */

#define CAP_MD_MDTHR_Pos       16                                  /*!< CAP MD: MDTHR  Position */
#define CAP_MD_MDTHR_Msk       (0x1Ful<<CAP_MD_MDTHR_Pos)          /*!< CAP MD: MDTHR  Mask */

/* CAP MDADDR Bit Field Definitions */
#define CAP_MDADDR_MDADDR_Pos  0                                           /*!< CAP MDADDR: MDADDR Position */
#define CAP_MDADDR_MDADDR_Msk  (0xFFFFFFFFul<<CAP_MDADDR_MDADDR_Pos)       /*!< CAP MDADDR: MDADDR Mask */

/* CAP MDYADDR Bit Field Definitions */
#define CAP_MDYADDR_MDYADDR_Pos 0                                          /*!< CAP MDYADDR: MDYADDR Position */
#define CAP_MDYADDR_MDYADDR_Msk (0xFFFFFFFFul<<CAP_MDYADDR_MDYADDR_Pos)    /*!< CAP MDYADDR: MDYADDR Mask */

/* CAP SEPIA Bit Field Definitions */
#define CAP_SEPIA_SepiaU_Pos    0                                  /*!< CAP SEPIA: SepiaU Position */
#define CAP_SEPIA_SepiaU_Msk    (0xFFul<<CAP_VSEPIA_SepiaU_Pos)    /*!< CAP SEPIA: SepiaU Mask */

#define CAP_SEPIA_SepiaV_Pos    8                                  /*!< CAP SEPIA: SepiaV Position */
#define CAP_SEPIA_SepiaV_Msk    (0xFFul<<CAP_VSEPIA_SepiaV_Pos)    /*!< CAP SEPIA: SepiaV Mask */

/* CAP CWSP Bit Field Definitions */
#define CAP_CWSP_CWSPH_Pos    0                                    /*!< CAP CWSP: CWSPH Position */
#define CAP_CWSP_CWSPH_Msk    (0x7FFul<<CAP_CWSP_CWSPH_Pos)        /*!< CAP CWSP: CWSPH Mask */

#define CAP_CWSP_CWSPV_Pos    16                                   /*!< CAP CWSP: CWSPV Position */
#define CAP_CWSP_CWSPV_Msk    (0x7FFul<<CAP_CWSP_CWSPV_Pos)        /*!< CAP CWSP: CWSPV Mask */

/* CAP CWS Bit Field Definitions */
#define CAP_CWS_CWSW_Pos    0                                      /*!< CAP CWS: CWSW Position */
#define CAP_CWS_CWSW_Msk    (0x7FFul<<CAP_CWS_CWSW_Pos)            /*!< CAP CWS: CWSW Mask */

#define CAP_CWS_CWSH_Pos    16                                     /*!< CAP CWS: CWSH Position */
#define CAP_CWS_CWSH_Msk    (0x7FFul<<CAP_CWS_CWSH_Pos)            /*!< CAP CWS: CWSH Mask */

/* CAP PKDSL Bit Field Definitions */
#define CAP_PKDSL_PKDSHML_Pos    0                                 /*!< CAP PKDSL: PKDSHML Position */
#define CAP_PKDSL_PKDSHML_Msk    (0xFFul<<CAP_PKDSL_PKDSHML_Pos)   /*!< CAP PKDSL: PKDSHML Mask */

#define CAP_PKDSL_PKDSHNL_Pos    8                                 /*!< CAP PKDSL: PKDSHNL Position */
#define CAP_PKDSL_PKDSHNL_Msk    (0xFFul<<CAP_PKDSL_PKDSHNL_Pos)   /*!< CAP PKDSL: PKDSHNL Mask */

#define CAP_PKDSL_PKDSVML_Pos    16                                /*!< CAP PKDSL: PKDSVML Position */
#define CAP_PKDSL_PKDSVML_Msk    (0xFFul<<CAP_PKDSL_PKDSVML_Pos)   /*!< CAP PKDSL: PKDSVML Mask */

#define CAP_PKDSL_PKDSVNL_Pos    24                                /*!< CAP PKDSL: PKDSVNL Position */
#define CAP_PKDSL_PKDSVNL_Msk    (0xFFul<<CAP_PKDSL_PKDSVNL_Pos)   /*!< CAP PKDSL: PKDSVNL Mask */

/* CAP PNDSL Bit Field Definitions */
#define CAP_PNDSL_PNDSHML_Pos    0                                 /*!< CAP PNDSL: PNDSHML Position */
#define CAP_PNDSL_PNDSHML_Msk    (0xFFul<<CAP_PNDSL_PNDSHML_Pos)   /*!< CAP PNDSL: PNDSHML Mask */

#define CAP_PNDSL_PNDSHNL_Pos    8                                 /*!< CAP PNDSL: PNDSHNL Position */
#define CAP_PNDSL_PNDSHNL_Msk    (0xFFul<<CAP_PNDSL_PNDSHNL_Pos)   /*!< CAP PNDSL: PNDSHNL Mask */

#define CAP_PNDSL_PNDSVML_Pos    16                                /*!< CAP PNDSL: PNDSVML Position */
#define CAP_PNDSL_PNDSVML_Msk    (0xFFul<<CAP_PNDSL_PNDSVML_Pos)   /*!< CAP PNDSL: PNDSVML Mask */

#define CAP_PNDSL_PNDSVNL_Pos    24                                /*!< CAP PNDSL: PNDSVNL Position */
#define CAP_PNDSL_PNDSVNL_Msk    (0xFFul<<CAP_PNDSL_PNDSVNL_Pos)   /*!< CAP PNDSL: PNDSVNL Mask */

/* CAP PKDSH Bit Field Definitions */
#define CAP_PKDSH_PKDSHMH_Pos    0                                 /*!< CAP PKDSH: PKDSHMH Position */
#define CAP_PKDSH_PKDSHMH_Msk    (0xFFul<<CAP_PKDSH_PKDSHMH_Pos)   /*!< CAP PKDSH: PKDSHMH Mask */

#define CAP_PKDSH_PKDSHNH_Pos    8                                 /*!< CAP PKDSH: PKDSHNH Position */
#define CAP_PKDSH_PKDSHNH_Msk    (0xFFul<<CAP_PKDSH_PKDSHNH_Pos)   /*!< CAP PKDSH: PKDSHNH Mask */

#define CAP_PKDSH_PKDSVMH_Pos    16                                /*!< CAP PKDSH: PKDSVMH Position */
#define CAP_PKDSH_PKDSVMH_Msk    (0xFFul<<CAP_PKDSH_PKDSVMH_Pos)   /*!< CAP PKDSH: PKDSVMH Mask */

#define CAP_PKDSH_PKDSVNH_Pos    24                                /*!< CAP PKDSH: PKDSVNH Position */
#define CAP_PKDSH_PKDSVNH_Msk    (0xFFul<<CAP_PKDSH_PKDSVNH_Pos)   /*!< CAP PKDSH: PKDSVNH Mask */

/* CAP PNDSH Bit Field Definitions */
#define CAP_PNDSH_PNDSHMH_Pos    0                                 /*!< CAP PNDSH: PNDSHMH Position */
#define CAP_PNDSH_PNDSHMH_Msk    (0xFFul<<CAP_PNDSH_PNDSHMH_Pos)   /*!< CAP PNDSH: PNDSHMH Mask */

#define CAP_PNDSH_PNDSHNH_Pos    8                                 /*!< CAP PNDSH: PNDSHNH Position */
#define CAP_PNDSH_PNDSHNH_Msk    (0xFFul<<CAP_PNDSH_PNDSHNH_Pos)   /*!< CAP PNDSH: PNDSHNH Mask */

#define CAP_PNDSH_PNDSVMH_Pos    16                                /*!< CAP PNDSH: PNDSVMH Position */
#define CAP_PNDSH_PNDSVMH_Msk    (0xFFul<<CAP_PNDSH_PNDSVMH_Pos)   /*!< CAP PNDSH: PNDSVMH Mask */

#define CAP_PNDSH_PNDSVNH_Pos    24                                /*!< CAP PNDSH: PNDSVNH Position */
#define CAP_PNDSH_PNDSVNH_Msk    (0xFFul<<CAP_PNDSH_PNDSVNH_Pos)   /*!< CAP PNDSH: PNDSVNH Mask */

/* CAP FRC Bit Field Definitions */
#define CAP_FRC_FRCM_Pos    0                                      /*!< CAP FRC: FRCM Position */
#define CAP_FRC_FRCM_Msk    (0x3Ful<<CAP_FRC_FRCM_Pos)             /*!< CAP FRC: FRCM Mask */

#define CAP_FRC_FRCN_Pos    8                                      /*!< CAP FRC: FRCN Position */
#define CAP_FRC_FRCN_Msk    (0x3Ful<<CAP_FRC_FRCN_Pos)             /*!< CAP FRC: FRCN Mask */

/* CAP STRIDE Bit Field Definitions */
#define CAP_STRIDE_PKSTRIDE_Pos    0                                          /*!< CAP STRIDE: PKSTRIDE  Position */
#define CAP_STRIDE_PKSTRIDE_Msk    (0x3FFFul<<CAP_STRIDE_PKSTRIDE_Pos)        /*!< CAP STRIDE: PKSTRIDE  Mask */

#define CAP_STRIDE_PNSTRIDE_Pos    16                                         /*!< CAP STRIDE: PNSTRIDE Position */
#define CAP_STRIDE_PNSTRIDE_Msk    (0x3FFFul<<CAP_STRIDE_PNSTRIDE_Pos)        /*!< CAP STRIDE: PNSTRIDE Mask */

/* CAP FIFO_THD Bit Field Definitions */
#define CAP_FIFO_THD_FTHV_Pos    0                                  /*!< CAP FIFO_THD: FTHV Position */
#define CAP_FIFO_THD_FTHV_Msk    (0xFul<<CAP_FIFO_THD_FTHV_Pos)     /*!< CAP FIFO_THD: FTHV Mask */

#define CAP_FIFO_THD_FTHU_Pos    8                                  /*!< CAP FIFO_THD: FTHU Position */
#define CAP_FIFO_THD_FTHU_Msk    (0xFul<<CAP_FIFO_THD_FTHU_Pos)     /*!< CAP FIFO_THD: FTHU Mask */

#define CAP_FIFO_THD_FTHY_Pos    16                                 /*!< CAP FIFO_THD: FTHY Position */
#define CAP_FIFO_THD_FTHY_Msk    (0xFul<<CAP_FIFO_THD_FTHY_Pos)     /*!< CAP FIFO_THD: FTHY Mask */

#define CAP_FIFO_THD_FTHP_Pos    24                                 /*!< CAP FIFO_THD: FTHP Position */
#define CAP_FIFO_THD_FTHP_Msk    (0xFul<<CAP_FIFO_THD_FTHP_Pos)     /*!< CAP FIFO_THD: FTHP Mask */

#define CAP_VFIFO_OVFL_Pos       31                                 /*!< CAP FIFO_THD: OVFL Position */
#define CAP_VFIFO_OVFL_Msk       (1ul<<CAP_FIFO_THD_OVFL_Pos)       /*!< CAP FIFO_THD: OVFL Mask */

/* CAP CMPADDR Bit Field Definitions */
#define CAP_CMPADDR_CMPADDR_Pos    0                                              /*!< CAP CMPADDR: CMPADDR Position */
#define CAP_CMPADDR_CMPADDR_Msk    (0xFFFFFFFFul<<CAP_CMPADDR_CMPADDR_Pos)        /*!< CAP CMPADDR: CMPADDR Mask */

/* CAP CURADDRP Bit Field Definitions */
#define CAP_CURADDRP_CURADDRP_Pos    0                                            /*!< CAP CURADDRP: CURADDRP Position */
#define CAP_CURADDRP_CURADDRP_Msk    (0xFFFFFFFFul<<CAP_CURADDRP_CURADDRP_Pos)    /*!< CAP CURADDRP: CURADDRP Mask */

/* CAP CURADDRY Bit Field Definitions */
#define CAP_CURADDRY_CURADDRY_Pos    0                                            /*!< CAP CURADDRY: CURADDRY Position */
#define CAP_CURADDRY_CURADDRY_Msk    (0xFFFFFFFFul<<CAP_CURADDRY_CURADDRY_Pos)    /*!< CAP CURADDRY: CURADDRY Mask */

/* CAP CURADDRU Bit Field Definitions */
#define CAP_CURADDRU_CURADDRU_Pos    0                                            /*!< CAP CURADDRU: CURADDRU Position */
#define CAP_CURADDRU_CURADDRU_Msk    (0xFFFFFFFFul<<CAP_CURADDRU_CURADDRU_Pos)    /*!< CAP CURADDRU: CURADDRU Mask */

/* CAP CURADDRV Bit Field Definitions */
#define CAP_CURADDRV_CURADDRV_Pos    0                                            /*!< CAP CURADDRV: CURADDRV Position */
#define CAP_CURADDRV_CURADDRV_Msk    (0xFFFFFFFFul<<CAP_CURADDRV_CURADDRV_Pos)    /*!< CAP CURADDRV: CURADDRV Mask */

/* CAP PACBA0 Bit Field Definitions */
#define CAP_PACBA0_PACBA0_Pos    0                                                /*!< CAP PACBA0: PACBA0 Position */
#define CAP_PACBA0_PACBA0_Msk    (0xFFFFFFFFul<<CAP_PACBA0_PACBA0_Pos)            /*!< CAP PACBA0: PACBA0 Mask */

/* CAP PACBA1 Bit Field Definitions */
#define CAP_PACBA1_PACBA1_Pos    0                                                /*!< CAP PACBA1: PACBA1 Position */
#define CAP_PACBA1_PACBA1_Msk    (0xFFFFFFFFul<<CAP_PACBA1_PACBA1_Pos)            /*!< CAP PACBA1: PACBA1 Mask */

/* CAP YBA0 Bit Field Definitions */
#define CAP_YBA0_YBA0_Pos    0                                                    /*!< CAP YBA0: YBA0 Position */
#define CAP_YBA0_YBA0_Msk    (0xFFFFFFFFul<<CAP_YBA0_YBA0_Pos)                    /*!< CAP YBA0: YBA0 Mask */

/* CAP UBA0 Bit Field Definitions */
#define CAP_UBA0_UBA0_Pos    0                                                    /*!< CAP UBA0: UBA0 Position */
#define CAP_UBA0_UBA0_Msk    (0xFFFFFFFFul<<CAP_UBA0_UBA0_Pos)                    /*!< CAP UBA0: UBA0 Mask */

/* CAP VBA0 Bit Field Definitions */
#define CAP_VBA0_VBA0_Pos    0                                                    /*!< CAP VBA0: VBA0 Position */
#define CAP_VBA0_VBA0_Msk    (0xFFFFFFFFul<<CAP_VBA0_VBA0_Pos)                    /*!< CAP VBA0: VBA0 Mask */


/*@}*/ /* end of group NUC400_CAP */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif



/** @addtogroup NUC400_PERIPHERAL_MEM_MAP NUC400 Peripheral Memory Map
  Memory Mapped Structure for NUC400 Series Peripheral
  @{
 */
/* Peripheral and SRAM base address */
#define FLASH_BASE           ((uint32_t)0x00000000)      /*!< Flash base address      */
#define SRAM_BASE            ((uint32_t)0x20000000)      /*!< SRAM Base Address       */
#define PERIPH_BASE          ((uint32_t)0x40000000)      /*!< Peripheral Base Address */
#define AHBPERIPH_BASE       PERIPH_BASE                 /*!< AHB Base Address */
#define APBPERIPH_BASE       (PERIPH_BASE + 0x00040000)  /*!< APB Base Address */

/*!< AHB peripherals */
#define GCR_BASE               (AHBPERIPH_BASE + 0x00000)
#define CLK_BASE               (AHBPERIPH_BASE + 0x00200)
#define GPIOA_BASE             (AHBPERIPH_BASE + 0x04000)
#define GPIOB_BASE             (AHBPERIPH_BASE + 0x04040)
#define GPIOC_BASE             (AHBPERIPH_BASE + 0x04080)
#define GPIOD_BASE             (AHBPERIPH_BASE + 0x040C0)
#define GPIOE_BASE             (AHBPERIPH_BASE + 0x04100)
#define GPIOF_BASE             (AHBPERIPH_BASE + 0x04140)
#define GPIOG_BASE             (AHBPERIPH_BASE + 0x04180)
#define GPIOH_BASE             (AHBPERIPH_BASE + 0x041C0)
#define GPIOI_BASE             (AHBPERIPH_BASE + 0x04200)
#define GPIO_DBNCECON_BASE     (AHBPERIPH_BASE + 0x04440)
#define GPIO_PIN_DATA_BASE     (AHBPERIPH_BASE + 0x04800)
#define PDMA_BASE              (AHBPERIPH_BASE + 0x08000)
#define USBH_BASE              (AHBPERIPH_BASE + 0x09000)
#define EMAC_BASE              (AHBPERIPH_BASE + 0x0B000)
#define FMC_BASE               (AHBPERIPH_BASE + 0x0C000)
#define SD_BASE                (AHBPERIPH_BASE + 0x0D000)
#define EBI_BASE               (AHBPERIPH_BASE + 0x10000)
#define UDC20_BASE             (AHBPERIPH_BASE + 0x19000)
#define CAP_BASE               (AHBPERIPH_BASE + 0x30000)
#define CRC_BASE               (AHBPERIPH_BASE + 0x31000)
#define TAMPER_BASE            (AHBPERIPH_BASE + 0xE1000)

/*!< APB2 peripherals */
#define WDT_BASE              (APBPERIPH_BASE + 0x00000)
#define WWDT_BASE             (APBPERIPH_BASE + 0x00100)
#define OPA_BASE              (APBPERIPH_BASE + 0x06000)
#define I2S0_BASE             (APBPERIPH_BASE + 0x08000)
#define TIMER0_BASE           (APBPERIPH_BASE + 0x10000)
#define TIMER1_BASE           (APBPERIPH_BASE + 0x10020)
#define PWM0_BASE             (APBPERIPH_BASE + 0x18000)
#define EPWM0_BASE            (APBPERIPH_BASE + 0x1C000)
#define SPI0_BASE             (APBPERIPH_BASE + 0x20000)
#define SPI2_BASE             (APBPERIPH_BASE + 0x22000)
#define UART0_BASE            (APBPERIPH_BASE + 0x30000)
#define UART2_BASE            (APBPERIPH_BASE + 0x32000)
#define UART4_BASE            (APBPERIPH_BASE + 0x34000)
#define I2C0_BASE             (APBPERIPH_BASE + 0x40000)
#define I2C2_BASE             (APBPERIPH_BASE + 0x42000)
#define I2C4_BASE             (APBPERIPH_BASE + 0x44000)
#define SC0_BASE              (APBPERIPH_BASE + 0x50000)
#define SC2_BASE              (APBPERIPH_BASE + 0x52000)
#define SC4_BASE              (APBPERIPH_BASE + 0x54000)
#define CAN0_BASE             (APBPERIPH_BASE + 0x60000)
#define QEI0_BASE             (APBPERIPH_BASE + 0x70000)
#define ECAP0_BASE            (APBPERIPH_BASE + 0x74000)
#define PS2D_BASE             (APBPERIPH_BASE + 0xA0000)

/*!< APB1 peripherals */
#define RTC_BASE              (APBPERIPH_BASE + 0x01000)
#define ADC_BASE              (APBPERIPH_BASE + 0x03000)
#define ACMP_BASE             (APBPERIPH_BASE + 0x05000)
#define I2S1_BASE             (APBPERIPH_BASE + 0x09000)
#define OTG_BASE              (APBPERIPH_BASE + 0x0D000)
#define TIMER2_BASE           (APBPERIPH_BASE + 0x11000)
#define TIMER3_BASE           (APBPERIPH_BASE + 0x11020)
#define PWM1_BASE             (APBPERIPH_BASE + 0x19000)
#define EPWM1_BASE            (APBPERIPH_BASE + 0x1D000)
#define SPI1_BASE             (APBPERIPH_BASE + 0x21000)
#define SPI3_BASE             (APBPERIPH_BASE + 0x23000)
#define UART1_BASE            (APBPERIPH_BASE + 0x31000)
#define UART3_BASE            (APBPERIPH_BASE + 0x33000)
#define UART5_BASE            (APBPERIPH_BASE + 0x35000)
#define I2C1_BASE             (APBPERIPH_BASE + 0x41000)
#define I2C3_BASE             (APBPERIPH_BASE + 0x43000)
#define SC1_BASE              (APBPERIPH_BASE + 0x51000)
#define SC3_BASE              (APBPERIPH_BASE + 0x53000)
#define SC5_BASE              (APBPERIPH_BASE + 0x55000)
#define CAN1_BASE             (APBPERIPH_BASE + 0x61000)
#define QEI1_BASE             (APBPERIPH_BASE + 0x71000)
#define ECAP1_BASE            (APBPERIPH_BASE + 0x75000)
#define CRYPTO_BASE           (0x50080000UL)

/*@}*/ /* end of group NUC400_PERIPHERAL_MEM_MAP */


/** @addtogroup NUC400_PERIPHERAL_DECLARATION NUC400 Peripheral Declaration
  The Declaration of NUC400 Series Peripheral
  @{
 */

#define SYS                  ((GCR_T *)   GCR_BASE)
#define CLK                  ((CLK_T *)   CLK_BASE)
#define PA                   ((GPIO_T *)  GPIOA_BASE)
#define PB                   ((GPIO_T *)  GPIOB_BASE)
#define PC                   ((GPIO_T *)  GPIOC_BASE)
#define PD                   ((GPIO_T *)  GPIOD_BASE)
#define PE                   ((GPIO_T *)  GPIOE_BASE)
#define PF                   ((GPIO_T *)  GPIOF_BASE)
#define PG                   ((GPIO_T *)  GPIOG_BASE)
#define PH                   ((GPIO_T *)  GPIOH_BASE)
#define PI                   ((GPIO_T *)  GPIOI_BASE)
#define GPIO                 ((GPIO_DBNCECON_T *) GPIO_DBNCECON_BASE)
#define PDMA                 ((PDMA_T *)  PDMA_BASE)
#define USBH                 ((USBH_T *)  USBH_BASE)
#define EMAC                 ((EMAC_T *)  EMAC_BASE)
#define FMC                  ((FMC_T *)   FMC_BASE)
#define SD                   ((SD_T *)    SD_BASE)
#define SIC                  ((SIC_T *)   SIC_BASE)
#define EBI                  ((EBI_T *)   EBI_BASE)
#define CAP                  ((CAP_T *)   CAP_BASE)
#define SPACC                ((SPACC_T *) SPACC_BASE)
#define CRC                  ((CRC_T *)   CRC_BASE)
#define TAMPER               ((TAMPER_T *) TAMPER_BASE)

#define WDT                  ((WDT_T *)   WDT_BASE)
#define WWDT                 ((WWDT_T *)  WWDT_BASE)
#define RTC                  ((RTC_T *)   RTC_BASE)
#define ADC                  ((ADC_T *)   ADC_BASE)
#define ACMP                 ((ACMP_T *)  ACMP_BASE)

#define I2S0                 ((I2S_T *)   I2S0_BASE)
#define I2S1                 ((I2S_T *)   I2S1_BASE)
#define USBD                 ((USBD_T *)  UDC20_BASE)
#define OTG                  ((OTG_T *)   OTG_BASE)
#define TIMER0               ((TIMER_T *) TIMER0_BASE)
#define TIMER1               ((TIMER_T *) TIMER1_BASE)
#define TIMER2               ((TIMER_T *) TIMER2_BASE)
#define TIMER3               ((TIMER_T *) TIMER3_BASE)
#define PWM0                 ((PWM_T *)   PWM0_BASE)
#define PWM1                 ((PWM_T *)   PWM1_BASE)
#define EPWM0                ((EPWM_T *)  EPWM0_BASE)
#define EPWM1                ((EPWM_T *)  EPWM1_BASE)
#define ECAP0                ((ECAP_T *)  ECAP0_BASE)
#define ECAP1                ((ECAP_T *)  ECAP1_BASE)
#define QEI0                 ((QEI_T *)   QEI0_BASE)
#define QEI1                 ((QEI_T *)   QEI1_BASE)
#define SPI0                 ((SPI_T *)   SPI0_BASE)
#define SPI1                 ((SPI_T *)   SPI1_BASE)
#define SPI2                 ((SPI_T *)   SPI2_BASE)
#define SPI3                 ((SPI_T *)   SPI3_BASE)
#define UART0                ((UART_T *)  UART0_BASE)
#define UART1                ((UART_T *)  UART1_BASE)
#define UART2                ((UART_T *)  UART2_BASE)
#define UART3                ((UART_T *)  UART3_BASE)
#define UART4                ((UART_T *)  UART4_BASE)
#define UART5                ((UART_T *)  UART5_BASE)
#define I2C0                 ((I2C_T *)   I2C0_BASE)
#define I2C1                 ((I2C_T *)   I2C1_BASE)
#define I2C2                 ((I2C_T *)   I2C2_BASE)
#define I2C3                 ((I2C_T *)   I2C3_BASE)
#define I2C4                 ((I2C_T *)   I2C4_BASE)
#define SC0                  ((SC_T *)    SC0_BASE)
#define SC1                  ((SC_T *)    SC1_BASE)
#define SC2                  ((SC_T *)    SC2_BASE)
#define SC3                  ((SC_T *)    SC3_BASE)
#define SC4                  ((SC_T *)    SC4_BASE)
#define SC5                  ((SC_T *)    SC5_BASE)
#define CAN0                 ((CAN_T *)   CAN0_BASE)
#define CAN1                 ((CAN_T *)   CAN1_BASE)
#define PS2D                 ((PS2D_T *)  PS2D_BASE)
#define CRYPTO               ((CRYPTO_T *) CRYPTO_BASE)
/*@}*/ /* end of group NUC400_PERIPHERAL_DECLARATION */
/*@}*/ /* end of group NUC400_Peripherals */

/** @addtogroup NUC400_IO_ROUTINE NUC400 I/O routines
  The Declaration of NUC400 I/O routines
  @{
 */

typedef volatile unsigned char  vu8;        ///< Define 8-bit unsigned volatile data type
typedef volatile unsigned short vu16;       ///< Define 16-bit unsigned volatile data type
typedef volatile unsigned long  vu32;       ///< Define 32-bit unsigned volatile data type

/**
  * @brief Get a 8-bit unsigned value from specified address
  * @param[in] addr Address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified address
  */
#define M8(addr)  (*((vu8  *) (addr)))

/**
  * @brief Get a 16-bit unsigned value from specified address
  * @param[in] addr Address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified address
  * @note The input address must be 16-bit aligned
  */
#define M16(addr) (*((vu16 *) (addr)))

/**
  * @brief Get a 32-bit unsigned value from specified address
  * @param[in] addr Address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified address
  * @note The input address must be 32-bit aligned
  */
#define M32(addr) (*((vu32 *) (addr)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)            (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)            (*((volatile unsigned char *)(port)))


/*@}*/ /* end of group NUC400_IO_ROUTINE */

/******************************************************************************/
/*                Legacy Constants                                            */
/******************************************************************************/
/** @addtogroup NUC400_legacy_Constants NUC400 Legacy Constants
  NUC400 Legacy Constants
  @{
*/

#ifndef NULL
#define NULL           (0)      ///< NULL pointer
#endif

#define TRUE           (1)      ///< Boolean true, define to use in API parameters or return value
#define FALSE          (0)      ///< Boolean false, define to use in API parameters or return value

#define ENABLE         (1)      ///< Enable, define to use in API parameters
#define DISABLE        (0)      ///< Disable, define to use in API parameters

/* Define one bit mask */
#define BIT0     (0x00000001)       ///< Bit 0 mask of an 32 bit integer
#define BIT1     (0x00000002)       ///< Bit 1 mask of an 32 bit integer
#define BIT2     (0x00000004)       ///< Bit 2 mask of an 32 bit integer
#define BIT3     (0x00000008)       ///< Bit 3 mask of an 32 bit integer
#define BIT4     (0x00000010)       ///< Bit 4 mask of an 32 bit integer
#define BIT5     (0x00000020)       ///< Bit 5 mask of an 32 bit integer
#define BIT6     (0x00000040)       ///< Bit 6 mask of an 32 bit integer
#define BIT7     (0x00000080)       ///< Bit 7 mask of an 32 bit integer
#define BIT8     (0x00000100)       ///< Bit 8 mask of an 32 bit integer
#define BIT9     (0x00000200)       ///< Bit 9 mask of an 32 bit integer
#define BIT10    (0x00000400)       ///< Bit 10 mask of an 32 bit integer
#define BIT11    (0x00000800)       ///< Bit 11 mask of an 32 bit integer
#define BIT12    (0x00001000)       ///< Bit 12 mask of an 32 bit integer
#define BIT13    (0x00002000)       ///< Bit 13 mask of an 32 bit integer
#define BIT14    (0x00004000)       ///< Bit 14 mask of an 32 bit integer
#define BIT15    (0x00008000)       ///< Bit 15 mask of an 32 bit integer
#define BIT16    (0x00010000)       ///< Bit 16 mask of an 32 bit integer
#define BIT17    (0x00020000)       ///< Bit 17 mask of an 32 bit integer
#define BIT18    (0x00040000)       ///< Bit 18 mask of an 32 bit integer
#define BIT19    (0x00080000)       ///< Bit 19 mask of an 32 bit integer
#define BIT20    (0x00100000)       ///< Bit 20 mask of an 32 bit integer
#define BIT21    (0x00200000)       ///< Bit 21 mask of an 32 bit integer
#define BIT22    (0x00400000)       ///< Bit 22 mask of an 32 bit integer
#define BIT23    (0x00800000)       ///< Bit 23 mask of an 32 bit integer
#define BIT24    (0x01000000)       ///< Bit 24 mask of an 32 bit integer
#define BIT25    (0x02000000)       ///< Bit 25 mask of an 32 bit integer
#define BIT26    (0x04000000)       ///< Bit 26 mask of an 32 bit integer
#define BIT27    (0x08000000)       ///< Bit 27 mask of an 32 bit integer
#define BIT28    (0x10000000)       ///< Bit 28 mask of an 32 bit integer
#define BIT29    (0x20000000)       ///< Bit 29 mask of an 32 bit integer
#define BIT30    (0x40000000)       ///< Bit 30 mask of an 32 bit integer
#define BIT31    (0x80000000)       ///< Bit 31 mask of an 32 bit integer

/* Byte Mask Definitions */
#define BYTE0_Msk              (0x000000FF)         ///< Mask to get bit0~bit7 from a 32 bit integer
#define BYTE1_Msk              (0x0000FF00)         ///< Mask to get bit8~bit15 from a 32 bit integer
#define BYTE2_Msk              (0x00FF0000)         ///< Mask to get bit16~bit23 from a 32 bit integer
#define BYTE3_Msk              (0xFF000000)         ///< Mask to get bit24~bit31 from a 32 bit integer

#define GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

/*@}*/ /* end of group NUC400_legacy_Constants */
/*@}*/ /* end of group NUC400_Definitions */

/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
//#include "sys.h"
//#include "clk.h"
//
//#include "adc.h"
//#include "cap.h"
//#include "crypto.h"
//#include "pdma.h"
//#include "ebi.h"
//#include "emac.h"
//#include "fmc.h"
//#include "gpio.h"
//#include "i2c.h"
//#include "pwm.h"
//#include "rtc.h"
//#include "sc.h"
//#include "scuart.h"
//#include "spi.h"
//#include "timer.h"
//#include "uart.h"
//#include "usbd.h"
//#include "wdt.h"
//#include "wwdt.h"
//#include "i2s.h"
//#include "can.h"
//#include "sd.h"

#ifdef __cplusplus
}
#endif

#endif  /* __NUC400SERIES_H__ */

/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/
