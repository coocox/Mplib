/**
 *******************************************************************************
 * @file    TMPM061.h
 * @brief   CMSIS Cortex-M0 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM061' Device Series
 * @version V2.0.2.3 (Tentative)
 * @date    2013/03/05
 * 
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 * 
 * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
 * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
 * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
 * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/** @addtogroup TOSHIBA_TX00_MICROCONTROLLER
  * @{
  */
  
/** @addtogroup TMPM061
  * @{
  */

#ifndef __TMPM061_H__
#define __TMPM061_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/** Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************************/
  NonMaskableInt_IRQn           = -14,       /*!< 2 Non Maskable Interrupt                                    */
  HardFault_IRQn                = -13,       /*!< 3 Cortex-M0 Hard Fault Interrupt                            */
  MemoryManagement_IRQn         = -12,       /*!< 4 Cortex-M0 Memory Management Interrupt                     */
  SVCall_IRQn                   = -5,        /*!< 11 Cortex-M0 SV Call Interrupt                              */
  PendSV_IRQn                   = -2,        /*!< 14 Cortex-M0 Pend SV Interrupt                              */
  SysTick_IRQn                  = -1,        /*!< 15 Cortex-M0 System Tick Interrupt                          */

/******  TMPM061 Specific Interrupt Numbers *******************************************************************/
  INTPCE_IRQn                   = 0,         /*!< PCE interface                                               */
  INTDSAD0_IRQn                 = 1,         /*!< ¦¤¦²A/D conversion complete interrupt (unit0)                 */
  INTDSAD1_IRQn                 = 2,         /*!< ¦¤¦²A/D conversion complete interrupt (unit1)                 */
  INTDSAD2_IRQn                 = 3,         /*!< ¦¤¦²A/D conversion complete interrupt (unit2)                 */
  INTLVD_IRQn                   = 4,         /*!< Voltage detector interrupt                                  */
  INT0_IRQn                     = 5,         /*!< Interrupt pin 0                                             */
  INT1_IRQn                     = 6,         /*!< Interrupt pin 1                                             */
  INT2_IRQn                     = 7,         /*!< Interrupt pin 2                                             */
  INT3_IRQn                     = 8,         /*!< Interrupt pin 3                                             */
  INTRX0_IRQn                   = 9,         /*!< Serial reception (channel.0)                                */
  INTTX0_IRQn                   = 10,        /*!< Serial transmission (channel.0)                             */
  INTRX1_IRQn                   = 11,        /*!< Serial reception (channel.1)                                */
  INTTX1_IRQn                   = 12,        /*!< Serial transmission (channel.1)                             */
  INTRX2_IRQn                   = 13,        /*!< Serial reception (channel.2)                                */
  INTTX2_IRQn                   = 14,        /*!< Serial transmission (channel.2)                             */
  INTRX3_IRQn                   = 15,        /*!< Serial reception (channel.3)                                */
  INTTX3_IRQn                   = 16,        /*!< Serial transmission (channel.3)                             */
  INTSBI_IRQn                   = 17,        /*!< Serial bus interface                                        */
  INTTB0_IRQn                   = 18,        /*!< 16-bit TMRB match detection 0                               */
  INTTB1_IRQn                   = 19,        /*!< 16-bit TMRB match detection 1                               */
  INTCAP00_IRQn                 = 20,        /*!< 16-bit TMRB input capture 0 (channel.0)                     */
  INTCAP01_IRQn                 = 21,        /*!< 16-bit TMRB input capture 1 (channel.0)                     */
  INTCAP10_IRQn                 = 22,        /*!< 16-bit TMRB input capture 0 (channel.1)                     */
  INTCAP11_IRQn                 = 23,        /*!< 16-bit TMRB input capture 1 (channel.1)                     */
  INTT16A0_IRQn                 = 24,        /*!< 16-bit TMR16A match detection (channel.0)                   */
  INTT16A1_IRQn                 = 25,        /*!< 16-bit TMR16A match detection (channel.1)                   */
  INTT16A2_IRQn                 = 26,        /*!< 16-bit TMR16A match detection (channel.2)                   */
  INTT16A3_IRQn                 = 27,        /*!< 16-bit TMR16A match detection (channel.3)                   */
  INTT16A5_IRQn                 = 28,        /*!< 16-bit TMR16A match detection (channel.5)                   */
  INTT16A6_IRQn                 = 29,        /*!< 16-bit TMR16A match detection (channel.6)                   */
  INTRTC_IRQn                   = 30,        /*!< Real time clock                                             */
  INTAD_IRQn                    = 31         /*!< A/D conversion completion interrupt                         */
} IRQn_Type;

/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV              0x0000       /*!< Cortex-M0 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals            */
#include "system_TMPM061.h"                 /* TMPM061 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief General Purpose Input/Output Port (PA)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PA Data Register                             */
  __IO uint32_t CR;                /*!< PA Control Register                          */
  __IO uint32_t FR1;               /*!< PA Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PA Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PA Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PA Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PA Input Enable Control Register             */
} TSB_PA_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PB)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PB Data Register                             */
  __IO uint32_t CR;                /*!< PB Control Register                          */
  __IO uint32_t FR1;               /*!< PB Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PB Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PB Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PB Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PB Input Enable Control Register             */
} TSB_PB_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PC)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PC Data Register                             */
  __IO uint32_t CR;                /*!< PC Control Register                          */
  __IO uint32_t FR1;               /*!< PC Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PC Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PC Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PC Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PC Input Enable Control Register             */
} TSB_PC_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PD)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PD Data Register                             */
  __IO uint32_t CR;                /*!< PD Control Register                          */
  __IO uint32_t FR1;               /*!< PD Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PD Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PD Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PD Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PD Input Enable Control Register             */
} TSB_PD_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PE)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PE Data Register                             */
  __IO uint32_t CR;                /*!< PE Control Register                          */
  __IO uint32_t FR1;               /*!< PE Function Register 1                       */
  __IO uint32_t FR2;               /*!< PE Function Register 2                       */
  __IO uint32_t FR3;               /*!< PE Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PE Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PE Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PE Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PE Input Enable Control Register             */
} TSB_PE_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PF)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PF Data Register                             */
  __IO uint32_t CR;                /*!< PF Control Register                          */
  __IO uint32_t FR1;               /*!< PF Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PF Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PF Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PF Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PF Input Enable Control Register             */
} TSB_PF_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PG)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PG Data Register                             */
  __IO uint32_t CR;                /*!< PG Control Register                          */
  __IO uint32_t FR1;               /*!< PG Function Register 1                       */
  __IO uint32_t FR2;               /*!< PG Function Register 2                       */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< PG Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PG Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PG Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PG Input Enable Control Register             */
} TSB_PG_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PH)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PH Data Register                             */
  __IO uint32_t CR;                /*!< PH Control Register                          */
  __IO uint32_t FR1;               /*!< PH Function Register 1                       */
  __IO uint32_t FR2;               /*!< PH Function Register 2                       */
  __IO uint32_t FR3;               /*!< PH Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PH OPHn Drain Control Register               */
  __IO uint32_t PUP;               /*!< PH Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PH Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PH Input Enable Control Register             */
} TSB_PH_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PI)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PI Data Register                             */
  __IO uint32_t CR;                /*!< PI Control Register                          */
  __IO uint32_t FR1;               /*!< PI Function Register 1                       */
  __IO uint32_t FR2;               /*!< PI Function Register 2                       */
  __IO uint32_t FR3;               /*!< PI Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PI OPIn Drain Control Register               */
  __IO uint32_t PUP;               /*!< PI Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PI Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PI Input Enable Control Register             */
} TSB_PI_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PJ)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PJ Data Register                             */
  __IO uint32_t CR;                /*!< PJ Control Register                          */
  __IO uint32_t FR1;               /*!< PJ Function Register 1                       */
  __IO uint32_t FR2;               /*!< PJ Function Register 2                       */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< PJ OPJn Drain Control Register               */
  __IO uint32_t PUP;               /*!< PJ Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PJ Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PJ Input Enable Control Register             */
} TSB_PJ_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PK)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PK Data Register                             */
  __IO uint32_t CR;                /*!< PK Control Register                          */
  __IO uint32_t FR1;               /*!< PK Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PK Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PK Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PK Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PK Input Enable Control Register             */
} TSB_PK_TypeDef;

/**
  * @brief 16-bit Timer/Event Counter (TB)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< TB Enable Register                           */
  __IO uint32_t RUN;               /*!< TB RUN Register                              */
  __IO uint32_t CR;                /*!< TB Control Register                          */
  __IO uint32_t MOD;               /*!< TB Mode Register                             */
  __IO uint32_t FFCR;              /*!< TB Flip-Flop Control Register                */
  __I  uint32_t ST;                /*!< TB Status Register                           */
  __IO uint32_t IM;                /*!< TB Interrupt Mask Register                   */
  __I  uint32_t UC;                /*!< TB Read Capture Register                     */
  __IO uint32_t RG0;               /*!< TB RG0 Timer Register                        */
  __IO uint32_t RG1;               /*!< TB RG1 Timer Register                        */
  __I  uint32_t CP0;               /*!< TB CP0 Capture Register                      */
  __I  uint32_t CP1;               /*!< TB CP1 Capture Register                      */
} TSB_TB_TypeDef;

/**
  * @brief 16-bit TimerA
  */
typedef struct
{
  __IO uint32_t EN;                /*!< Enable Register                              */
  __IO uint32_t RUN;               /*!< RUN Register                                 */
  __IO uint32_t CR;                /*!< Control Register                             */
  __IO uint32_t RG;                /*!< Timer Register                               */
  __IO  uint32_t CP;               /*!< Capture Register                             */
} TSB_T16A_TypeDef;

/**
  * @brief Watchdog Timer (WD)
  */
typedef struct
{
  __IO uint32_t MOD;               /*!< WD Mode Register                             */
  __O  uint32_t CR;                /*!< WD Control Register                          */
} TSB_WD_TypeDef;

/**
  * @brief Serial Channel (SC)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< SC Enable Register                           */
  __IO uint32_t BUF;               /*!< SC Buffer Register                           */
  __IO uint32_t CR;                /*!< SC Control Register                          */
  __IO uint32_t MOD0;              /*!< SC Mode Control Register 0                   */
  __IO uint32_t BRCR;              /*!< SC Baud Rate Generator Control Register      */
  __IO uint32_t BRADD;             /*!< SC Baud Rate Generator Control Register 2    */
  __IO uint32_t MOD1;              /*!< SC Mode Control Register 1                   */
  __IO uint32_t MOD2;              /*!< SC Mode Control Register 2                   */
} TSB_SC_TypeDef;

#if defined ( __CC_ARM   )           /* RealView Compiler */
#pragma anon_unions
#elif (defined (__ICCARM__))         /*  ICC Compiler     */
#pragma language=extended
#endif

/**
  * @brief Serial Bus Interface (SBI)
  */
typedef struct
{
  __IO uint32_t CR0;               /*!< SBI Control Register 0                       */
  __IO uint32_t CR1;               /*!< SBI Control Register 1 (I2C Mode)            */
  __IO uint32_t DBR;               /*!< SBI Data Buffer Register                     */
  __IO uint32_t I2CAR;             /*!< SBI I2C Bus Address Register                 */
union {
  __O  uint32_t CR2;               /*!< SBI Control Register 2 (I2C Mode)            */
  __I  uint32_t SR;                /*!< SBI Status Register (I2C Mode)               */
  };
  __IO uint32_t BR0;               /*!< SBI Baud Rate Register 0                     */
} TSB_SBI_TypeDef;

/**
  * @brief Analog-to-Digital Converter (AD)
  */
typedef struct
{
  __IO uint32_t CLK;               /*!< AD Conversion Clock Setting Register         */
  __IO uint32_t MOD0;              /*!< AD Mode Control Register 0                   */
  __IO uint32_t MOD1;              /*!< AD Mode Control Register 1                   */
  __IO uint32_t MOD2;              /*!< AD Mode Control Register 2                   */
  __IO uint32_t MOD3;              /*!< AD Mode Control Register 3                   */
  __IO uint32_t MOD4;              /*!< AD Mode Control Register 4                   */
  __IO uint32_t MOD5;              /*!< AD Mode Control Register 5                   */
       uint32_t RESERVED0[5];
  __I  uint32_t REG0;              /*!< AD Conversion Result Register 0              */
  __I  uint32_t REG1;              /*!< AD Conversion Result Register 1              */
  __I  uint32_t REG2;              /*!< AD Conversion Result Register 2              */
  __I  uint32_t REG3;              /*!< AD Conversion Result Register 3              */
  __I  uint32_t REG4;              /*!< AD Conversion Result Register 4              */
  __I  uint32_t REG5;              /*!< AD Conversion Result Register 5              */
  __I  uint32_t REG6;              /*!< AD Conversion Result Register 6              */
  __I  uint32_t REG7;              /*!< AD Conversion Result Register 7              */
  __I  uint32_t REG8;              /*!< AD Conversion Result Register 8              */
  __I  uint32_t REG9;              /*!< AD Conversion Result Register 9              */
  __I  uint32_t REG10;             /*!< AD Conversion Result Register 10             */
  __I  uint32_t REG11;             /*!< AD Conversion Result Register 11             */
  __I  uint32_t REGSP;             /*!< AD Conversion Result Register SP             */
  __IO uint32_t CMP0;              /*!< AD Conversion Result Comparison Register 0   */
  __IO uint32_t CMP1;              /*!< AD Conversion Result Comparison Register 1   */
} TSB_AD_TypeDef;

/**
  * @brief 16-bit Delta Sigma AD Converter (DSAD)
  */
typedef struct
{
  __IO uint32_t CLK;               /*!< DSAD Conversion Clock Setting Register       */
  __IO uint32_t CR0;               /*!< DSAD Control Register 0                      */
  __IO uint32_t CR1;               /*!< DSAD Control Register 1                      */
  __IO uint32_t CR2;               /*!< DSAD Control Register 2                      */
  __IO uint32_t CR3;               /*!< DSAD Control Register 3                      */
  __IO uint32_t CR4;               /*!< DSAD Control Register 4                      */
       uint32_t RESERVED0[6];
  __IO uint32_t ADJ;               /*!< DSAD Adjust Register                         */
       uint32_t RESERVED1[3];
  __IO uint32_t ST;                /*!< DSAD Status Register                         */
  __IO uint32_t RES;               /*!< DSAD Result Register                         */
} TSB_DSAD_TypeDef;

/**
  * @brief Temperature Sensor (TEMP)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< TEMP Enable Register                         */
  __IO uint32_t CR;                /*!< TEMP Control Register                        */
} TSB_TEMP_TypeDef;

/**
  * @brief Low Voltage detector control register
  */
typedef struct
{
       uint32_t RESERVED0;
  __IO uint32_t ICR;               /*!< LVD-NMI Control Register                     */
  __I  uint32_t SR;                /*!< LVD Status Control Register                  */
} TSB_LVD_TypeDef;

/**
  * @brief Real Time Clock (RTC)
  */
typedef struct
{
  __IO uint8_t  SECR;              /*!< RTC Sec setting register                     */
  __IO uint8_t  MINR;              /*!< RTC Min settging register                    */
  __IO uint8_t  HOURR;             /*!< RTC Hour setting register                    */
       uint8_t  RESERVED0;
  __IO uint8_t  DAYR;              /*!< RTC Day setting register                     */
  __IO uint8_t  DATER;             /*!< RTC Date setting register                    */
  __IO uint8_t  MONTHR;            /*!< RTC Month settging register PAGE0            */
  __IO uint8_t  YEARR;             /*!< RTC Year setting register PAGE0              */
  __IO uint8_t  PAGER;             /*!< RTC Page register                            */
       uint8_t  RESERVED1[3];
  __IO uint8_t  RESTR;             /*!< RTC Reset register                           */
       uint8_t  RESERVED2;
  __IO uint8_t  PROTECT;           /*!< RTC clock adjust control register            */
  __IO uint8_t  ADJCTL;            /*!< RTC protect register                         */
  __IO uint16_t ADJDAT;            /*!< RTC clock adjust data register               */
} TSB_RTC_TypeDef;

/**
  * @brief LCD Driver (LCD)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< Enable register                              */
  __IO uint32_t CR1;               /*!< Control register 1                           */
  __IO uint32_t CR2;               /*!< Control register 2                           */
  __IO uint32_t BUF00;             /*!< Buffer register 0                            */
  __IO uint32_t BUF01;             /*!< Buffer register 1                            */
  __IO uint32_t BUF02;             /*!< Buffer register 2                            */
  __IO uint32_t BUF03;             /*!< Buffer register 3                            */
  __IO uint32_t BUF04;             /*!< Buffer register 4                            */
  __IO uint32_t BUF05;             /*!< Buffer register 5                            */
  __IO uint32_t BUF06;             /*!< Buffer register 6                            */
  __IO uint32_t BUF07;             /*!< Buffer register 7                            */
  __IO uint32_t BUF08;             /*!< Buffer register 8                            */
  __IO uint32_t BUF09;             /*!< Buffer register 9                            */
  __IO uint32_t BUF10;             /*!< Buffer register 10                           */
  __IO uint32_t BUF11;             /*!< Buffer register 11                           */
  __IO uint32_t BUF12;             /*!< Buffer register 12                           */
  __IO uint32_t BUF13;             /*!< Buffer register 13                           */
  __IO uint32_t BUF14;             /*!< Buffer register 14                           */
  __IO uint32_t BUF15;             /*!< Buffer register 15                           */
  __IO uint32_t BUF16;             /*!< Buffer register 16                           */
  __IO uint32_t BUF17;             /*!< Buffer register 17                           */
  __IO uint32_t BUF18;             /*!< Buffer register 18                           */
  __IO uint32_t BUF19;             /*!< Buffer register 19                           */
} TSB_LCD_TypeDef;

/**
  * @brief Flash Control (FC)
  */
typedef struct
{
       uint32_t RESERVED0[4];
  __IO uint32_t SECBIT;            /*!< FC Security Bit Register                     */
       uint32_t RESERVED1[3];
  __I  uint32_t FLCS;              /*!< FC Flash Control Register                    */
       uint32_t RESERVED2[14];
  __IO uint32_t DBGEN;             /*!< FC Debug enable monitor Register             */
} TSB_FC_TypeDef;

/**
  * @brief Clock Generator (CG)
  */
typedef struct
{
  __IO uint32_t SYSCR;             /*!< System Control Register                      */
  __IO uint32_t OSCCR;             /*!< Oscillation Control Register                 */
  __IO uint32_t STBYCR;            /*!< Standby Control Register                     */
  __IO uint32_t EHCLKSEL;          /*!< External High-speed clock select register    */
  __IO uint32_t CKSEL;             /*!< System Clock Selection Register              */
  __O  uint32_t ICRCG;             /*!< CG Interrupt Request Clear Register          */
       uint32_t RESERVED0;
  __IO uint32_t RSTFLG;            /*!< Reset Flag Register                          */
  __IO uint32_t IMCGA;             /*!< CG Interrupt Mode Control Register A         */
  __IO uint32_t IMCGB;             /*!< CG Interrupt Mode Control Register B         */
} TSB_CG_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)


#define TSB_PA_BASE                (PERI_BASE  + 0x00C0000UL)
#define TSB_PB_BASE                (PERI_BASE  + 0x00C0100UL)
#define TSB_PC_BASE                (PERI_BASE  + 0x00C0200UL)
#define TSB_PD_BASE                (PERI_BASE  + 0x00C0300UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x00C0400UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x00C0500UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x40C0600UL)
#define TSB_PH_BASE                (PERI_BASE  + 0x00C0700UL)
#define TSB_PI_BASE                (PERI_BASE  + 0x00C0800UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x00C0900UL)
#define TSB_PK_BASE                (PERI_BASE  + 0x00C0A00UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x00C4000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x40C4100UL)
#define TSB_T16A0_BASE             (PERI_BASE  + 0x008D000UL)
#define TSB_T16A1_BASE             (PERI_BASE  + 0x008E000UL)
#define TSB_T16A2_BASE             (PERI_BASE  + 0x008F000UL)
#define TSB_T16A3_BASE             (PERI_BASE  + 0x0090000UL)
#define TSB_T16A4_BASE             (PERI_BASE  + 0x0091000UL)
#define TSB_T16A5_BASE             (PERI_BASE  + 0x4092000UL)
#define TSB_T16A6_BASE             (PERI_BASE  + 0x4093000UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x00F2000UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x00E1000UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00E1100UL)
#define TSB_SC2_BASE               (PERI_BASE  + 0x00E1200UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x00E1300UL)
#define TSB_SBI_BASE               (PERI_BASE  + 0x00E0000UL)
#define TSB_AD_BASE                (PERI_BASE  + 0x00FC000UL)
#define TSB_DSAD0_BASE             (PERI_BASE  + 0x4067000UL)
#define TSB_DSAD1_BASE             (PERI_BASE  + 0x4068000UL)
#define TSB_DSAD2_BASE             (PERI_BASE  + 0x4069000UL)
#define TSB_TEMP_BASE              (PERI_BASE  + 0x005D000UL)
#define TSB_LVD_BASE               (PERI_BASE  + 0x00F4000UL)
#define TSB_RTC_BASE               (PERI_BASE  + 0x00CC000UL)
#define TSB_LCD_BASE               (PERI_BASE  + 0x006E000UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1FFF000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x00F3000UL)


/* Peripheral declaration */
#define TSB_PA                     ((     TSB_PA_TypeDef *)    TSB_PA_BASE)
#define TSB_PB                     ((     TSB_PB_TypeDef *)    TSB_PB_BASE)
#define TSB_PC                     ((     TSB_PC_TypeDef *)    TSB_PC_BASE)
#define TSB_PD                     ((     TSB_PD_TypeDef *)    TSB_PD_BASE)
#define TSB_PE                     ((     TSB_PE_TypeDef *)    TSB_PE_BASE)
#define TSB_PF                     ((     TSB_PF_TypeDef *)    TSB_PF_BASE)
#define TSB_PG                     ((     TSB_PG_TypeDef *)    TSB_PG_BASE)
#define TSB_PH                     ((     TSB_PH_TypeDef *)    TSB_PH_BASE)
#define TSB_PI                     ((     TSB_PI_TypeDef *)    TSB_PI_BASE)
#define TSB_PJ                     ((     TSB_PJ_TypeDef *)    TSB_PJ_BASE)
#define TSB_PK                     ((     TSB_PK_TypeDef *)    TSB_PK_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_T16A0                  ((   TSB_T16A_TypeDef *) TSB_T16A0_BASE)
#define TSB_T16A1                  ((   TSB_T16A_TypeDef *) TSB_T16A1_BASE)
#define TSB_T16A2                  ((   TSB_T16A_TypeDef *) TSB_T16A2_BASE)
#define TSB_T16A3                  ((   TSB_T16A_TypeDef *) TSB_T16A3_BASE)
#define TSB_T16A4                  ((   TSB_T16A_TypeDef *) TSB_T16A4_BASE)
#define TSB_T16A5                  ((   TSB_T16A_TypeDef *) TSB_T16A5_BASE)
#define TSB_T16A6                  ((   TSB_T16A_TypeDef *) TSB_T16A6_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC2                    ((     TSB_SC_TypeDef *)   TSB_SC2_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_SBI                    ((    TSB_SBI_TypeDef *)   TSB_SBI_BASE)
#define TSB_AD                     ((     TSB_AD_TypeDef *)    TSB_AD_BASE)
#define TSB_DSAD0                  ((   TSB_DSAD_TypeDef *) TSB_DSAD0_BASE)
#define TSB_DSAD1                  ((   TSB_DSAD_TypeDef *) TSB_DSAD1_BASE)
#define TSB_DSAD2                  ((   TSB_DSAD_TypeDef *) TSB_DSAD2_BASE)
#define TSB_TEMP                   ((   TSB_TEMP_TypeDef *)  TSB_TEMP_BASE)
#define TSB_LVD                    ((    TSB_LVD_TypeDef *)   TSB_LVD_BASE)
#define TSB_RTC                    ((    TSB_RTC_TypeDef *)   TSB_RTC_BASE)
#define TSB_LCD                    ((    TSB_LCD_TypeDef *)   TSB_LCD_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)


/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/* General Purpose Input/Output Port (PA) */
#define TSB_PA_DATA_PA0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,0)))
#define TSB_PA_DATA_PA1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,1)))
#define TSB_PA_DATA_PA2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,2)))
#define TSB_PA_DATA_PA3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,3)))
#define TSB_PA_DATA_PA4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,4)))
#define TSB_PA_DATA_PA5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,5)))
#define TSB_PA_DATA_PA6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,6)))
#define TSB_PA_DATA_PA7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,7)))
#define TSB_PA_CR_PA0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,0)))
#define TSB_PA_CR_PA1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,1)))
#define TSB_PA_CR_PA2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,2)))
#define TSB_PA_CR_PA3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,3)))
#define TSB_PA_CR_PA4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,4)))
#define TSB_PA_CR_PA5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,5)))
#define TSB_PA_CR_PA6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,6)))
#define TSB_PA_CR_PA7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,7)))
#define TSB_PA_FR1_PA0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,0)))
#define TSB_PA_FR1_PA1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,1)))
#define TSB_PA_FR1_PA2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,2)))
#define TSB_PA_FR1_PA3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,3)))
#define TSB_PA_FR1_PA4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,4)))
#define TSB_PA_FR1_PA5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,5)))
#define TSB_PA_FR1_PA6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,6)))
#define TSB_PA_FR1_PA7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,7)))
#define TSB_PA_OD_PA0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,0)))
#define TSB_PA_OD_PA1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,1)))
#define TSB_PA_OD_PA2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,2)))
#define TSB_PA_OD_PA3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,3)))
#define TSB_PA_OD_PA4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,4)))
#define TSB_PA_OD_PA5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,5)))
#define TSB_PA_OD_PA6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,6)))
#define TSB_PA_OD_PA7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,7)))
#define TSB_PA_PUP_PA0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,0)))
#define TSB_PA_PUP_PA1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,1)))
#define TSB_PA_PUP_PA2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,2)))
#define TSB_PA_PUP_PA3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,3)))
#define TSB_PA_PUP_PA4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,4)))
#define TSB_PA_PUP_PA5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,5)))
#define TSB_PA_PUP_PA6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,6)))
#define TSB_PA_PUP_PA7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,7)))
#define TSB_PA_PDN_PA0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,0)))
#define TSB_PA_PDN_PA1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,1)))
#define TSB_PA_PDN_PA2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,2)))
#define TSB_PA_PDN_PA3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,3)))
#define TSB_PA_PDN_PA4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,4)))
#define TSB_PA_PDN_PA5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,5)))
#define TSB_PA_PDN_PA6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,6)))
#define TSB_PA_PDN_PA7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,7)))
#define TSB_PA_IE_PA0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,0)))
#define TSB_PA_IE_PA1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,1)))
#define TSB_PA_IE_PA2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,2)))
#define TSB_PA_IE_PA3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,3)))
#define TSB_PA_IE_PA4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,4)))
#define TSB_PA_IE_PA5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,5)))
#define TSB_PA_IE_PA6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,6)))
#define TSB_PA_IE_PA7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,7)))


/* General Purpose Input/Output Port (PB) */
#define TSB_PB_DATA_PB0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,0)))
#define TSB_PB_DATA_PB1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,1)))
#define TSB_PB_DATA_PB2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,2)))
#define TSB_PB_DATA_PB3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,3)))
#define TSB_PB_DATA_PB4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,4)))
#define TSB_PB_DATA_PB5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,5)))
#define TSB_PB_DATA_PB6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,6)))
#define TSB_PB_DATA_PB7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,7)))
#define TSB_PB_CR_PB0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,0)))
#define TSB_PB_CR_PB1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,1)))
#define TSB_PB_CR_PB2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,2)))
#define TSB_PB_CR_PB3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,3)))
#define TSB_PB_CR_PB4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,4)))
#define TSB_PB_CR_PB5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,5)))
#define TSB_PB_CR_PB6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,6)))
#define TSB_PB_CR_PB7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,7)))
#define TSB_PB_FR1_PB0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,0)))
#define TSB_PB_FR1_PB1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,1)))
#define TSB_PB_FR1_PB2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,2)))
#define TSB_PB_FR1_PB3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,3)))
#define TSB_PB_FR1_PB4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,4)))
#define TSB_PB_FR1_PB5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,5)))
#define TSB_PB_FR1_PB6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,6)))
#define TSB_PB_FR1_PB7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,7)))
#define TSB_PB_OD_PB0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,0)))
#define TSB_PB_OD_PB1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,1)))
#define TSB_PB_OD_PB2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,2)))
#define TSB_PB_OD_PB3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,3)))
#define TSB_PB_OD_PB4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,4)))
#define TSB_PB_OD_PB5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,5)))
#define TSB_PB_OD_PB6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,6)))
#define TSB_PB_OD_PB7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,7)))
#define TSB_PB_PUP_PB0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,0)))
#define TSB_PB_PUP_PB1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,1)))
#define TSB_PB_PUP_PB2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,2)))
#define TSB_PB_PUP_PB3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,4)))
#define TSB_PB_PUP_PB5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PUP_PB7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,7)))
#define TSB_PB_PDN_PB0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,0)))
#define TSB_PB_PDN_PB1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,1)))
#define TSB_PB_PDN_PB2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,2)))
#define TSB_PB_PDN_PB3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,3)))
#define TSB_PB_PDN_PB4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,4)))
#define TSB_PB_PDN_PB5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,5)))
#define TSB_PB_PDN_PB6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,6)))
#define TSB_PB_PDN_PB7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,7)))
#define TSB_PB_IE_PB0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,0)))
#define TSB_PB_IE_PB1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,1)))
#define TSB_PB_IE_PB2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,2)))
#define TSB_PB_IE_PB3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))
#define TSB_PB_IE_PB7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,7)))


/* General Purpose Input/Output Port (PC) */
#define TSB_PC_DATA_PC0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,0)))
#define TSB_PC_DATA_PC1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,1)))
#define TSB_PC_DATA_PC2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,2)))
#define TSB_PC_DATA_PC3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,3)))
#define TSB_PC_DATA_PC4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,4)))
#define TSB_PC_DATA_PC5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,5)))
#define TSB_PC_DATA_PC6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,6)))
#define TSB_PC_DATA_PC7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,7)))
#define TSB_PC_CR_PC0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,0)))
#define TSB_PC_CR_PC1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,1)))
#define TSB_PC_CR_PC2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,2)))
#define TSB_PC_CR_PC3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,3)))
#define TSB_PC_CR_PC4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,4)))
#define TSB_PC_CR_PC5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,5)))
#define TSB_PC_CR_PC6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,6)))
#define TSB_PC_CR_PC7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,7)))
#define TSB_PC_FR1_PC0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,0)))
#define TSB_PC_FR1_PC1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,1)))
#define TSB_PC_FR1_PC2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,2)))
#define TSB_PC_FR1_PC3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,3)))
#define TSB_PC_FR1_PC4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,4)))
#define TSB_PC_FR1_PC5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,5)))
#define TSB_PC_FR1_PC6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,6)))
#define TSB_PC_FR1_PC7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,7)))
#define TSB_PC_OD_PC0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,0)))
#define TSB_PC_OD_PC1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,1)))
#define TSB_PC_OD_PC2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,2)))
#define TSB_PC_OD_PC3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,3)))
#define TSB_PC_OD_PC4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,4)))
#define TSB_PC_OD_PC5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,5)))
#define TSB_PC_OD_PC6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,6)))
#define TSB_PC_OD_PC7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,7)))
#define TSB_PC_PUP_PC0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,0)))
#define TSB_PC_PUP_PC1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,1)))
#define TSB_PC_PUP_PC2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,2)))
#define TSB_PC_PUP_PC3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,3)))
#define TSB_PC_PUP_PC4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,4)))
#define TSB_PC_PUP_PC5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,5)))
#define TSB_PC_PUP_PC6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,6)))
#define TSB_PC_PUP_PC7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,7)))
#define TSB_PC_PDN_PC0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,0)))
#define TSB_PC_PDN_PC1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,1)))
#define TSB_PC_PDN_PC2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,2)))
#define TSB_PC_PDN_PC3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,3)))
#define TSB_PC_PDN_PC4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,4)))
#define TSB_PC_PDN_PC5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,5)))
#define TSB_PC_PDN_PC6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,6)))
#define TSB_PC_PDN_PC7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,7)))
#define TSB_PC_IE_PC0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,0)))
#define TSB_PC_IE_PC1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,1)))
#define TSB_PC_IE_PC2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,2)))
#define TSB_PC_IE_PC3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,3)))
#define TSB_PC_IE_PC4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,4)))
#define TSB_PC_IE_PC5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,5)))
#define TSB_PC_IE_PC6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,6)))
#define TSB_PC_IE_PC7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,7)))


/* General Purpose Input/Output Port (PD) */
#define TSB_PD_DATA_PD0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,0)))
#define TSB_PD_DATA_PD1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,1)))
#define TSB_PD_DATA_PD2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,2)))
#define TSB_PD_DATA_PD3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,3)))
#define TSB_PD_DATA_PD4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,4)))
#define TSB_PD_DATA_PD5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,5)))
#define TSB_PD_DATA_PD6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,6)))
#define TSB_PD_DATA_PD7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,7)))
#define TSB_PD_CR_PD0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,0)))
#define TSB_PD_CR_PD1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,1)))
#define TSB_PD_CR_PD2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,2)))
#define TSB_PD_CR_PD3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,3)))
#define TSB_PD_CR_PD4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,4)))
#define TSB_PD_CR_PD5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,5)))
#define TSB_PD_CR_PD6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,6)))
#define TSB_PD_CR_PD7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,7)))
#define TSB_PD_FR1_PD0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,0)))
#define TSB_PD_FR1_PD1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,1)))
#define TSB_PD_FR1_PD2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,2)))
#define TSB_PD_FR1_PD3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,3)))
#define TSB_PD_FR1_PD4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,4)))
#define TSB_PD_FR1_PD5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,5)))
#define TSB_PD_FR1_PD6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,6)))
#define TSB_PD_FR1_PD7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,7)))
#define TSB_PD_OD_PD0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,0)))
#define TSB_PD_OD_PD1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,1)))
#define TSB_PD_OD_PD2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,2)))
#define TSB_PD_OD_PD3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,3)))
#define TSB_PD_OD_PD4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,4)))
#define TSB_PD_OD_PD5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,5)))
#define TSB_PD_OD_PD6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,6)))
#define TSB_PD_OD_PD7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,7)))
#define TSB_PD_PUP_PD0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,0)))
#define TSB_PD_PUP_PD1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,1)))
#define TSB_PD_PUP_PD2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,2)))
#define TSB_PD_PUP_PD3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,3)))
#define TSB_PD_PUP_PD4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,4)))
#define TSB_PD_PUP_PD5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,5)))
#define TSB_PD_PUP_PD6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,6)))
#define TSB_PD_PUP_PD7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,7)))
#define TSB_PD_PDN_PD0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,0)))
#define TSB_PD_PDN_PD1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,1)))
#define TSB_PD_PDN_PD2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,2)))
#define TSB_PD_PDN_PD3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,3)))
#define TSB_PD_PDN_PD4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,4)))
#define TSB_PD_PDN_PD5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,5)))
#define TSB_PD_PDN_PD6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,6)))
#define TSB_PD_PDN_PD7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,7)))
#define TSB_PD_IE_PD0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,0)))
#define TSB_PD_IE_PD1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,1)))
#define TSB_PD_IE_PD2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,2)))
#define TSB_PD_IE_PD3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,3)))
#define TSB_PD_IE_PD4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,4)))
#define TSB_PD_IE_PD5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,5)))
#define TSB_PD_IE_PD6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,6)))
#define TSB_PD_IE_PD7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,7)))


/* General Purpose Input/Output Port (PE) */
#define TSB_PE_DATA_PE0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,0)))
#define TSB_PE_DATA_PE1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,1)))
#define TSB_PE_DATA_PE2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,2)))
#define TSB_PE_DATA_PE3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,3)))
#define TSB_PE_DATA_PE4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,4)))
#define TSB_PE_DATA_PE5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,5)))
#define TSB_PE_DATA_PE6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,6)))
#define TSB_PE_DATA_PE7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,7)))
#define TSB_PE_CR_PE0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,0)))
#define TSB_PE_CR_PE1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,1)))
#define TSB_PE_CR_PE2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,2)))
#define TSB_PE_CR_PE3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,3)))
#define TSB_PE_CR_PE4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,4)))
#define TSB_PE_CR_PE5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,5)))
#define TSB_PE_CR_PE6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,6)))
#define TSB_PE_CR_PE7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,7)))
#define TSB_PE_FR1_PE0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,0)))
#define TSB_PE_FR1_PE1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,1)))
#define TSB_PE_FR1_PE2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,2)))
#define TSB_PE_FR1_PE3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,3)))
#define TSB_PE_FR1_PE4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,4)))
#define TSB_PE_FR1_PE5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,5)))
#define TSB_PE_FR1_PE6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,6)))
#define TSB_PE_FR1_PE7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,7)))
#define TSB_PE_FR2_PE0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,0)))
#define TSB_PE_FR2_PE1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,1)))
#define TSB_PE_FR2_PE2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_FR2_PE3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,3)))
#define TSB_PE_FR2_PE4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,4)))
#define TSB_PE_FR2_PE5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,5)))
#define TSB_PE_FR2_PE6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,6)))
#define TSB_PE_FR2_PE7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,7)))
#define TSB_PE_FR3_PE3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,3)))
#define TSB_PE_OD_PE0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,0)))
#define TSB_PE_OD_PE1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,1)))
#define TSB_PE_OD_PE2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,2)))
#define TSB_PE_OD_PE3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,3)))
#define TSB_PE_OD_PE4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,4)))
#define TSB_PE_OD_PE5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,5)))
#define TSB_PE_OD_PE6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,6)))
#define TSB_PE_OD_PE7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,7)))
#define TSB_PE_PUP_PE0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,0)))
#define TSB_PE_PUP_PE1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,1)))
#define TSB_PE_PUP_PE2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,2)))
#define TSB_PE_PUP_PE3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,3)))
#define TSB_PE_PUP_PE4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,4)))
#define TSB_PE_PUP_PE5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,5)))
#define TSB_PE_PUP_PE6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,6)))
#define TSB_PE_PUP_PE7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,7)))
#define TSB_PE_PDN_PE0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,0)))
#define TSB_PE_PDN_PE1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,1)))
#define TSB_PE_PDN_PE2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,2)))
#define TSB_PE_PDN_PE3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,3)))
#define TSB_PE_PDN_PE4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,4)))
#define TSB_PE_PDN_PE5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,5)))
#define TSB_PE_PDN_PE6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,6)))
#define TSB_PE_PDN_PE7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,7)))
#define TSB_PE_IE_PE0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,0)))
#define TSB_PE_IE_PE1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,1)))
#define TSB_PE_IE_PE2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,2)))
#define TSB_PE_IE_PE3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,3)))
#define TSB_PE_IE_PE4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,4)))
#define TSB_PE_IE_PE5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,5)))
#define TSB_PE_IE_PE6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,6)))
#define TSB_PE_IE_PE7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,7)))


/* General Purpose Input/Output Port (PF) */
#define TSB_PF_DATA_PF0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,0)))
#define TSB_PF_DATA_PF1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,1)))
#define TSB_PF_CR_PF0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,1)))
#define TSB_PF_FR1_PF1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,1)))
#define TSB_PF_OD_PF0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,1)))
#define TSB_PF_PUP_PF0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,1)))
#define TSB_PF_PDN_PF0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,0)))
#define TSB_PF_PDN_PF1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,1)))
#define TSB_PF_IE_PF0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,1)))


/* General Purpose Input/Output Port (PG) */
#define TSB_PG_DATA_PG0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,0)))
#define TSB_PG_CR_PG0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,0)))
#define TSB_PG_FR1_PG0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,0)))
#define TSB_PG_FR2_PG0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,0)))
#define TSB_PG_OD_PG0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,0)))
#define TSB_PG_PUP_PG0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,0)))
#define TSB_PG_PDN_PG0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,0)))
#define TSB_PG_IE_PG0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,0)))


/* General Purpose Input/Output Port (PH) */
#define TSB_PH_DATA_PH0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,0)))
#define TSB_PH_DATA_PH1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,1)))
#define TSB_PH_DATA_PH2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,2)))
#define TSB_PH_DATA_PH3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,3)))
#define TSB_PH_DATA_PH4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,4)))
#define TSB_PH_DATA_PH5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,5)))
#define TSB_PH_CR_PH0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,0)))
#define TSB_PH_CR_PH1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,1)))
#define TSB_PH_CR_PH2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,2)))
#define TSB_PH_CR_PH3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,3)))
#define TSB_PH_CR_PH4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,4)))
#define TSB_PH_CR_PH5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,5)))
#define TSB_PH_FR1_PH0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,0)))
#define TSB_PH_FR1_PH1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,1)))
#define TSB_PH_FR1_PH2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,2)))
#define TSB_PH_FR1_PH3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,3)))
#define TSB_PH_FR1_PH4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,4)))
#define TSB_PH_FR1_PH5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,5)))
#define TSB_PH_FR2_PH0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,0)))
#define TSB_PH_FR2_PH2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,2)))
#define TSB_PH_FR2_PH3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,3)))
#define TSB_PH_FR2_PH5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,5)))
#define TSB_PH_FR3_PH2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,2)))
#define TSB_PH_FR3_PH5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,5)))
#define TSB_PH_OD_PH0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,0)))
#define TSB_PH_OD_PH1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,1)))
#define TSB_PH_OD_PH2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,2)))
#define TSB_PH_OD_PH3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,3)))
#define TSB_PH_OD_PH4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,4)))
#define TSB_PH_OD_PH5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,5)))
#define TSB_PH_PUP_PH0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,0)))
#define TSB_PH_PUP_PH1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,1)))
#define TSB_PH_PUP_PH2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,2)))
#define TSB_PH_PUP_PH3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,3)))
#define TSB_PH_PUP_PH4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,4)))
#define TSB_PH_PUP_PH5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,5)))
#define TSB_PH_PDN_PH0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,0)))
#define TSB_PH_PDN_PH1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,1)))
#define TSB_PH_PDN_PH2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,2)))
#define TSB_PH_PDN_PH3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,3)))
#define TSB_PH_PDN_PH4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,4)))
#define TSB_PH_PDN_PH5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,5)))
#define TSB_PH_IE_PH0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,0)))
#define TSB_PH_IE_PH1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,1)))
#define TSB_PH_IE_PH2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,2)))
#define TSB_PH_IE_PH3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,3)))
#define TSB_PH_IE_PH4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,4)))
#define TSB_PH_IE_PH5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,5)))


/* General Purpose Input/Output Port (PI) */
#define TSB_PI_DATA_PI0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,0)))
#define TSB_PI_DATA_PI1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,1)))
#define TSB_PI_DATA_PI2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,2)))
#define TSB_PI_DATA_PI3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,3)))
#define TSB_PI_DATA_PI4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,4)))
#define TSB_PI_DATA_PI5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,5)))
#define TSB_PI_DATA_PI6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,6)))
#define TSB_PI_CR_PI0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,0)))
#define TSB_PI_CR_PI1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,1)))
#define TSB_PI_CR_PI2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,2)))
#define TSB_PI_CR_PI3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_CR_PI4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,4)))
#define TSB_PI_CR_PI5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,5)))
#define TSB_PI_CR_PI6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,6)))
#define TSB_PI_FR1_PI0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,0)))
#define TSB_PI_FR1_PI1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,1)))
#define TSB_PI_FR1_PI2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,2)))
#define TSB_PI_FR1_PI3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,3)))
#define TSB_PI_FR1_PI4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,4)))
#define TSB_PI_FR1_PI5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,5)))
#define TSB_PI_FR1_PI6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,6)))
#define TSB_PI_FR2_PI0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR2,0)))
#define TSB_PI_FR2_PI2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR2,2)))
#define TSB_PI_FR2_PI6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR2,6)))
#define TSB_PI_FR3_PI2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR3,2)))
#define TSB_PI_FR3_PI6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR3,6)))
#define TSB_PI_OD_PI0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,0)))
#define TSB_PI_OD_PI1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,1)))
#define TSB_PI_OD_PI2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,2)))
#define TSB_PI_OD_PI3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,3)))
#define TSB_PI_OD_PI4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,4)))
#define TSB_PI_OD_PI5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,5)))
#define TSB_PI_OD_PI6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,6)))
#define TSB_PI_PUP_PI0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,0)))
#define TSB_PI_PUP_PI1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,1)))
#define TSB_PI_PUP_PI2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,2)))
#define TSB_PI_PUP_PI3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,3)))
#define TSB_PI_PUP_PI4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,4)))
#define TSB_PI_PUP_PI5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,5)))
#define TSB_PI_PUP_PI6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,6)))
#define TSB_PI_PDN_PI0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,0)))
#define TSB_PI_PDN_PI1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,1)))
#define TSB_PI_PDN_PI2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,2)))
#define TSB_PI_PDN_PI3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,3)))
#define TSB_PI_PDN_PI4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,4)))
#define TSB_PI_PDN_PI5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,5)))
#define TSB_PI_PDN_PI6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,6)))
#define TSB_PI_IE_PI0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,0)))
#define TSB_PI_IE_PI1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,1)))
#define TSB_PI_IE_PI2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,2)))
#define TSB_PI_IE_PI3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))
#define TSB_PI_IE_PI4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,4)))
#define TSB_PI_IE_PI5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,5)))
#define TSB_PI_IE_PI6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,6)))


/* General Purpose Input/Output Port (PJ) */
#define TSB_PJ_DATA_PJ0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,1)))
#define TSB_PJ_DATA_PJ2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,2)))
#define TSB_PJ_DATA_PJ3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,3)))
#define TSB_PJ_DATA_PJ4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,4)))
#define TSB_PJ_DATA_PJ5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,5)))
#define TSB_PJ_CR_PJ0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,0)))
#define TSB_PJ_CR_PJ1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,1)))
#define TSB_PJ_CR_PJ2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,2)))
#define TSB_PJ_CR_PJ3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,3)))
#define TSB_PJ_CR_PJ4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,4)))
#define TSB_PJ_FR1_PJ0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,0)))
#define TSB_PJ_FR1_PJ1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,1)))
#define TSB_PJ_FR1_PJ2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,2)))
#define TSB_PJ_FR1_PJ3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,3)))
#define TSB_PJ_FR1_PJ4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,4)))
#define TSB_PJ_FR1_PJ5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,5)))
#define TSB_PJ_FR2_PJ2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,2)))
#define TSB_PJ_FR2_PJ4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,4)))
#define TSB_PJ_FR2_PJ5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,5)))
#define TSB_PJ_OD_PJ0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,0)))
#define TSB_PJ_OD_PJ1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,1)))
#define TSB_PJ_OD_PJ2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,2)))
#define TSB_PJ_OD_PJ3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,3)))
#define TSB_PJ_OD_PJ4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,4)))
#define TSB_PJ_PUP_PJ0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,1)))
#define TSB_PJ_PUP_PJ2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,2)))
#define TSB_PJ_PUP_PJ3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,3)))
#define TSB_PJ_PUP_PJ4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,4)))
#define TSB_PJ_PDN_PJ0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,0)))
#define TSB_PJ_PDN_PJ1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,1)))
#define TSB_PJ_PDN_PJ2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,2)))
#define TSB_PJ_PDN_PJ3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,3)))
#define TSB_PJ_PDN_PJ4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,4)))
#define TSB_PJ_IE_PJ0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,1)))
#define TSB_PJ_IE_PJ2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,2)))
#define TSB_PJ_IE_PJ3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,3)))
#define TSB_PJ_IE_PJ4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,4)))
#define TSB_PJ_IE_PJ5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,5)))


/* General Purpose Input/Output Port (PK) */
#define TSB_PK_DATA_PK0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,0)))
#define TSB_PK_DATA_PK1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,1)))
#define TSB_PK_CR_PK0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,0)))
#define TSB_PK_CR_PK1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,1)))
#define TSB_PK_FR1_PK0F1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_PK->FR1,0)))
#define TSB_PK_FR1_PK1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,1)))
#define TSB_PK_OD_PK0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,0)))
#define TSB_PK_OD_PK1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,1)))
#define TSB_PK_PUP_PK0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,0)))
#define TSB_PK_PUP_PK1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,1)))
#define TSB_PK_PDN_PK0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,0)))
#define TSB_PK_PDN_PK1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,1)))
#define TSB_PK_IE_PK0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,0)))
#define TSB_PK_IE_PK1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,1)))


/* 16-bit Timer/Event Counter (TB) */
#define TSB_TB0_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,6)))
#define TSB_TB0_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,0)))
#define TSB_TB0_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,1)))
#define TSB_TB0_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,3)))
#define TSB_TB0_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,5)))
#define TSB_TB0_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,7)))
#define TSB_TB0_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,3)))
#define TSB_TB0_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,6)))
#define TSB_TB0_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,2)))
#define TSB_TB0_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,3)))
#define TSB_TB0_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,4)))
#define TSB_TB0_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,5)))
#define TSB_TB0_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,0)))
#define TSB_TB0_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,1)))
#define TSB_TB0_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,2)))

#define TSB_TB1_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,6)))
#define TSB_TB1_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,7)))
#define TSB_TB1_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,0)))
#define TSB_TB1_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,2)))
#define TSB_TB1_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,0)))
#define TSB_TB1_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,1)))
#define TSB_TB1_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,3)))
#define TSB_TB1_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,5)))
#define TSB_TB1_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,7)))
#define TSB_TB1_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,3)))
#define TSB_TB1_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,6)))
#define TSB_TB1_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,2)))
#define TSB_TB1_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,3)))
#define TSB_TB1_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,4)))
#define TSB_TB1_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,5)))
#define TSB_TB1_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,0)))
#define TSB_TB1_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,1)))
#define TSB_TB1_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,2)))


/* 16-bit TimerA */
#define TSB_T16A0_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->EN,0)))
#define TSB_T16A0_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->EN,1)))
#define TSB_T16A0_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->RUN,0)))
#define TSB_T16A0_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->CR,0)))
#define TSB_T16A0_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->CR,7)))
#define TSB_T16A0_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A0->CR,15)))

#define TSB_T16A1_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->EN,0)))
#define TSB_T16A1_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->EN,1)))
#define TSB_T16A1_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->RUN,0)))
#define TSB_T16A1_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->CR,0)))
#define TSB_T16A1_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->CR,7)))
#define TSB_T16A1_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A1->CR,15)))

#define TSB_T16A2_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->EN,0)))
#define TSB_T16A2_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->EN,1)))
#define TSB_T16A2_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->RUN,0)))
#define TSB_T16A2_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->CR,0)))
#define TSB_T16A2_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->CR,7)))
#define TSB_T16A2_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A2->CR,15)))

#define TSB_T16A3_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->EN,0)))
#define TSB_T16A3_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->EN,1)))
#define TSB_T16A3_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->RUN,0)))
#define TSB_T16A3_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->CR,0)))
#define TSB_T16A3_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->CR,7)))
#define TSB_T16A3_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A3->CR,15)))

#define TSB_T16A4_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->EN,0)))
#define TSB_T16A4_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->EN,1)))
#define TSB_T16A4_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->RUN,0)))
#define TSB_T16A4_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->CR,0)))
#define TSB_T16A4_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->CR,7)))
#define TSB_T16A4_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A4->CR,15)))

#define TSB_T16A5_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->EN,0)))
#define TSB_T16A5_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->EN,1)))
#define TSB_T16A5_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->RUN,0)))
#define TSB_T16A5_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->CR,0)))
#define TSB_T16A5_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->CR,7)))
#define TSB_T16A5_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A5->CR,15)))

#define TSB_T16A6_EN_I2T16A                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->EN,0)))
#define TSB_T16A6_EN_HALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->EN,1)))
#define TSB_T16A6_RUN_RUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->RUN,0)))
#define TSB_T16A6_CR_CLK                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->CR,0)))
#define TSB_T16A6_CR_FFEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->CR,7)))
#define TSB_T16A6_CR_UCCR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_T16A6->CR,15)))


/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_I2WDT                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,2)))
#define TSB_WD_MOD_WDTE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))


/* Serial Channel (SC) */
#define TSB_SC0_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->EN,0)))
#define TSB_SC0_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,4)))
#define TSB_SC0_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,5)))
#define TSB_SC0_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,6)))
#define TSB_SC0_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,7)))
#define TSB_SC0_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->BRCR,6)))
#define TSB_SC0_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,4)))
#define TSB_SC0_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,7)))
#define TSB_SC0_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,2)))
#define TSB_SC0_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,3)))
#define TSB_SC0_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,4)))
#define TSB_SC0_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,5)))
#define TSB_SC0_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,6)))
#define TSB_SC0_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,7)))

#define TSB_SC1_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->EN,0)))
#define TSB_SC1_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,4)))
#define TSB_SC1_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,5)))
#define TSB_SC1_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,6)))
#define TSB_SC1_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,7)))
#define TSB_SC1_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->BRCR,6)))
#define TSB_SC1_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,4)))
#define TSB_SC1_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,7)))
#define TSB_SC1_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,2)))
#define TSB_SC1_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,3)))
#define TSB_SC1_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,4)))
#define TSB_SC1_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,5)))
#define TSB_SC1_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,6)))
#define TSB_SC1_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,7)))

#define TSB_SC2_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->EN,0)))
#define TSB_SC2_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,4)))
#define TSB_SC2_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,5)))
#define TSB_SC2_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,6)))
#define TSB_SC2_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,7)))
#define TSB_SC2_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->BRCR,6)))
#define TSB_SC2_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,4)))
#define TSB_SC2_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,7)))
#define TSB_SC2_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,2)))
#define TSB_SC2_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,3)))
#define TSB_SC2_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,4)))
#define TSB_SC2_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,5)))
#define TSB_SC2_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,6)))
#define TSB_SC2_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,7)))

#define TSB_SC3_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->EN,0)))
#define TSB_SC3_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,4)))
#define TSB_SC3_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,5)))
#define TSB_SC3_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,6)))
#define TSB_SC3_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,7)))
#define TSB_SC3_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->BRCR,6)))
#define TSB_SC3_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD1,4)))
#define TSB_SC3_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD1,7)))
#define TSB_SC3_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,2)))
#define TSB_SC3_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,3)))
#define TSB_SC3_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,4)))
#define TSB_SC3_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,5)))
#define TSB_SC3_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,6)))
#define TSB_SC3_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,7)))


/* Serial Bus Interface (SBI) */
#define TSB_SBI_CR0_SBIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->CR0,7)))
#define TSB_SBI_CR1_SWRMON                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->CR1,0)))
#define TSB_SBI_I2CAR_ALS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->I2CAR,0)))
#define TSB_SBI_SR_LRB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,0)))
#define TSB_SBI_SR_ADO                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,1)))
#define TSB_SBI_SR_AAS                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,2)))
#define TSB_SBI_SR_AL                             (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,3)))
#define TSB_SBI_SR_PIN                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,4)))
#define TSB_SBI_SR_BB                             (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,5)))
#define TSB_SBI_SR_TRX                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,6)))
#define TSB_SBI_SR_MST                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,7)))
#define TSB_SBI_SR_SEF                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,2)))
#define TSB_SBI_SR_SIOF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,3)))
#define TSB_SBI_BR0_I2SBI                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->BR0,6)))


/* Analog-to-Digital Converter (AD) */
#define TSB_AD_MOD0_ADS                           (*((__O  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,0)))
#define TSB_AD_MOD0_SCAN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,1)))
#define TSB_AD_MOD0_REPEAT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,2)))
#define TSB_AD_MOD0_ADBFN                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,6)))
#define TSB_AD_MOD0_EOCFN                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,7)))
#define TSB_AD_MOD1_I2AD                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,6)))
#define TSB_AD_MOD1_VREFON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,7)))
#define TSB_AD_MOD2_HPADCE                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,5)))
#define TSB_AD_MOD2_ADBFHP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,6)))
#define TSB_AD_MOD2_EOCFHP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,7)))
#define TSB_AD_MOD3_ADOBSV0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,0)))
#define TSB_AD_MOD3_ADOBIC0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,5)))
#define TSB_AD_MOD4_ADHTG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD4,4)))
#define TSB_AD_MOD4_ADHS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD4,5)))
#define TSB_AD_MOD4_HADHTG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD4,6)))
#define TSB_AD_MOD4_HADHS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD4,7)))
#define TSB_AD_MOD5_ADOBSV1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,0)))
#define TSB_AD_MOD5_ADOBIC1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,5)))
#define TSB_AD_REG0_ADR0RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG0,0)))
#define TSB_AD_REG0_OVR0                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG0,1)))
#define TSB_AD_REG1_ADR1RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG1,0)))
#define TSB_AD_REG1_OVR1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG1,1)))
#define TSB_AD_REG2_ADR2RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG2,0)))
#define TSB_AD_REG2_OVR2                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG2,1)))
#define TSB_AD_REG3_ADR3RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG3,0)))
#define TSB_AD_REG3_OVR3                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG3,1)))
#define TSB_AD_REG4_ADR4RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG4,0)))
#define TSB_AD_REG4_OVR4                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG4,1)))
#define TSB_AD_REG5_ADR5RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG5,0)))
#define TSB_AD_REG5_OVR5                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG5,1)))
#define TSB_AD_REG6_ADR6RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG6,0)))
#define TSB_AD_REG6_OVR6                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG6,1)))
#define TSB_AD_REG7_ADR7RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG7,0)))
#define TSB_AD_REG7_OVR7                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG7,1)))
#define TSB_AD_REG8_ADR8RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG8,0)))
#define TSB_AD_REG8_OVR8                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG8,1)))
#define TSB_AD_REG9_ADR9RF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG9,0)))
#define TSB_AD_REG9_OVR9                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG9,1)))
#define TSB_AD_REG10_ADR10RF                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG10,0)))
#define TSB_AD_REG10_OVR10                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG10,1)))
#define TSB_AD_REG11_ADR11RF                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG11,0)))
#define TSB_AD_REG11_OVR11                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REG11,1)))
#define TSB_AD_REGSP_ADRSPRF                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REGSP,0)))
#define TSB_AD_REGSP_OVRSP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->REGSP,1)))


/* 16-bit Delta Sigma AD Converter (DSAD) */
#define TSB_DSAD0_CR1_MODEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD0->CR1,0)))
#define TSB_DSAD0_CR1_BIASEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD0->CR1,1)))
#define TSB_DSAD0_CR2_ADS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_DSAD0->CR2,0)))
#define TSB_DSAD0_CR3_REPEAT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD0->CR3,0)))
#define TSB_DSAD0_CR3_ADSYNC                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD0->CR3,8)))
#define TSB_DSAD0_ADJ_ADJ                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD0->ADJ,0)))
#define TSB_DSAD0_ST_ADBF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD0->ST,0)))
#define TSB_DSAD0_ST_EOCF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD0->ST,1)))
#define TSB_DSAD0_RES_ADRF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD0->RES,0)))
#define TSB_DSAD0_RES_ADOVR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD0->RES,1)))

#define TSB_DSAD1_CR1_MODEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD1->CR1,0)))
#define TSB_DSAD1_CR1_BIASEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD1->CR1,1)))
#define TSB_DSAD1_CR2_ADS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_DSAD1->CR2,0)))
#define TSB_DSAD1_CR3_REPEAT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD1->CR3,0)))
#define TSB_DSAD1_CR3_ADSYNC                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD1->CR3,8)))
#define TSB_DSAD1_ADJ_ADJ                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD1->ADJ,0)))
#define TSB_DSAD1_ST_ADBF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD1->ST,0)))
#define TSB_DSAD1_ST_EOCF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD1->ST,1)))
#define TSB_DSAD1_RES_ADRF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD1->RES,0)))
#define TSB_DSAD1_RES_ADOVR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD1->RES,1)))

#define TSB_DSAD2_CR1_MODEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD2->CR1,0)))
#define TSB_DSAD2_CR1_BIASEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD2->CR1,1)))
#define TSB_DSAD2_CR2_ADS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_DSAD2->CR2,0)))
#define TSB_DSAD2_CR3_REPEAT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD2->CR3,0)))
#define TSB_DSAD2_CR3_ADSYNC                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD2->CR3,8)))
#define TSB_DSAD2_ADJ_ADJ                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_DSAD2->ADJ,0)))
#define TSB_DSAD2_ST_ADBF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD2->ST,0)))
#define TSB_DSAD2_ST_EOCF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD2->ST,1)))
#define TSB_DSAD2_RES_ADRF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD2->RES,0)))
#define TSB_DSAD2_RES_ADOVR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_DSAD2->RES,1)))


/* Temperature Sensor (TEMP) */
#define TSB_TEMP_EN_EN0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TEMP->EN,0)))
#define TSB_TEMP_EN_EN1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TEMP->EN,1)))
#define TSB_TEMP_CR_CR0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TEMP->CR,0)))


/* Low Voltage detector control register */
#define TSB_LVD_ICR_LVDEN2                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,0)))
#define TSB_LVD_ICR_INTSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,4)))
#define TSB_LVD_ICR_LVDINTEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,5)))
#define TSB_LVD_SR_LVDST2                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_LVD->SR,1)))


/* Real Time Clock (RTC) */
#define TSB_RTC_ADJCTL_AJEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_RTC->ADJCTL,0)))


/* LCD Driver (LCD) */
#define TSB_LCD_EN_LCDE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_LCD->EN,0)))
#define TSB_LCD_CR1_EDSP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_LCD->CR1,7)))
#define TSB_LCD_CR2_BRSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_LCD->CR2,3)))
#define TSB_LCD_CR2_BRH                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_LCD->CR2,4)))


/* Flash Control (FC) */
#define TSB_FC_SECBIT_SECBIT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_FC->SECBIT,0)))
#define TSB_FC_FLCS_RDY_BSY                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,0)))
#define TSB_FC_DBGEN_EN0                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->DBGEN,0)))
#define TSB_FC_DBGEN_EN1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->DBGEN,1)))


/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FCSTOP                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,20)))
#define TSB_CG_OSCCR_WUEON                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_WUPSEL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XTEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,9)))
#define TSB_CG_OSCCR_LOSCSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,10)))
#define TSB_CG_OSCCR_EHCLKEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,11)))
#define TSB_CG_OSCCR_XEN2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,16)))
#define TSB_CG_OSCCR_OSCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,17)))
#define TSB_CG_OSCCR_HOSCON                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,18)))
#define TSB_CG_OSCCR_WUPSEL2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,19)))
#define TSB_CG_STBYCR_RXEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,8)))
#define TSB_CG_STBYCR_RXTEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,9)))
#define TSB_CG_STBYCR_DRVE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,16)))
#define TSB_CG_EHCLKSEL_EHCLKSEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->EHCLKSEL,0)))
#define TSB_CG_CKSEL_SYSCKFLG                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,0)))
#define TSB_CG_CKSEL_SYSCK                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,1)))
#define TSB_CG_RSTFLG_PINRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,0)))
#define TSB_CG_RSTFLG_WDTRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,2)))
#define TSB_CG_RSTFLG_DBGRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,4)))
#define TSB_CG_IMCGA_INT0EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,0)))
#define TSB_CG_IMCGA_INT1EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,8)))
#define TSB_CG_IMCGA_INT2EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,16)))
#define TSB_CG_IMCGA_INT3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))

/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM061_H__ */

/** @} */ /* End of group TMPM061 */
/** @} */ /* End of group TOSHIBA_TX00_MICROCONTROLLER */
