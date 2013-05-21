/**
 *******************************************************************************
 * @file    TMPM333.h
 * @brief   CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the 
 *          TOSHIBA 'TMPM333' Device Series 
 * @version V2.1.0
 * @date    2010/07/20
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/** @addtogroup TOSHIBA_TX03_MICROCONTROLLER
  * @{
  */

/** @addtogroup TMPM333
  * @{
  */

#ifndef __TMPM333_H__
#define __TMPM333_H__

#ifdef __cplusplus
extern "C" {
#endif 

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/** Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ****************************************************/
  NonMaskableInt_IRQn           = -14,      /*!< 2 Non Maskable Interrupt                          */
  HardFault_IRQn                = -13,      /*!< 3 Cortex-M3 Hard Fault Interrupt                  */
  MemoryManagement_IRQn         = -12,      /*!< 4 Cortex-M3 Memory Management Interrupt           */
  BusFault_IRQn                 = -11,      /*!< 5 Cortex-M3 Bus Fault Interrupt                   */
  UsageFault_IRQn               = -10,      /*!< 6 Cortex-M3 Usage Fault Interrupt                 */
  SVCall_IRQn                   = -5,       /*!< 11 Cortex-M3 SV Call Interrupt                    */
  DebugMonitor_IRQn             = -4,       /*!< 12 Cortex-M3 Debug Monitor Interrupt              */
  PendSV_IRQn                   = -2,       /*!< 14 Cortex-M3 Pend SV Interrupt                    */
  SysTick_IRQn                  = -1,       /*!< 15 Cortex-M3 System Tick Interrupt                */

/******  TMPM333 Specific Interrupt Numbers ********************************************************/
  INT0_IRQn                     = 0,        /*!< Interrupt pin (PJ0/70 pin)                        */
  INT1_IRQn                     = 1,        /*!< Interrupt pin (PJ1/49 pin)                        */
  INT2_IRQn                     = 2,        /*!< Interrupt pin (PJ2/86 pin)                        */
  INT3_IRQn                     = 3,        /*!< Interrupt pin (PJ3/87 pin)                        */
  INT4_IRQn                     = 4,        /*!< Interrupt pin (PG3/6  pin)                        */
  INT5_IRQn                     = 5,        /*!< Interrupt pin (PF7/19 pin)                        */
  INTRX0_IRQn                   = 6,        /*!< Serial reception (channel.0)                      */
  INTTX0_IRQn                   = 7,        /*!< Serial transmission (channel.0)                   */
  INTRX1_IRQn                   = 8,        /*!< Serial reception (channel.1)                      */
  INTTX1_IRQn                   = 9,        /*!< Serial transmission (channel.1)                   */
  INTSBI0_IRQn                  = 10,       /*!< Serial bus interface 0                            */
  INTSBI1_IRQn                  = 11,       /*!< Serial bus interface 1                            */
  INTADHP_IRQn                  = 15,       /*!< Highest priority AD conversion complete interrupt */
  INTADM0_IRQn                  = 16,       /*!< AD conversion monitoring function interrupt 0     */
  INTADM1_IRQn                  = 17,       /*!< AD conversion monitoring function interrupt 1     */
  INTTB0_IRQn                   = 18,       /*!< 16-bit TMRB match detection 0                     */
  INTTB1_IRQn                   = 19,       /*!< 16-bit TMRB match detection 1                     */
  INTTB2_IRQn                   = 20,       /*!< 16-bit TMRB match detection 2                     */
  INTTB3_IRQn                   = 21,       /*!< 16-bit TMRB match detection 3                     */
  INTTB4_IRQn                   = 22,       /*!< 16-bit TMRB match detection 4                     */
  INTTB5_IRQn                   = 23,       /*!< 16-bit TMRB match detection 5                     */
  INTTB6_IRQn                   = 24,       /*!< 16-bit TMRB match detection 6                     */
  INTRTC_IRQn                   = 25,       /*!< Real time clock timer                             */
  INTCAP00_IRQn                 = 26,       /*!< 16-bit TMRB input capture 00                      */
  INTCAP01_IRQn                 = 27,       /*!< 16-bit TMRB input capture 01                      */
  INTCAP10_IRQn                 = 28,       /*!< 16-bit TMRB input capture 10                      */
  INTCAP11_IRQn                 = 29,       /*!< 16-bit TMRB input capture 11                      */
  INTCAP50_IRQn                 = 30,       /*!< 16-bit TMRB input capture 50                      */
  INTCAP51_IRQn                 = 31,       /*!< 16-bit TMRB input capture 51                      */
  INTCAP60_IRQn                 = 32,       /*!< 16-bit TMRB input capture 60                      */
  INTCAP61_IRQn                 = 33,       /*!< 16-bit TMRB input capture 61                      */
  INT6_IRQn                     = 34,       /*!< Interrupt pin (PJ6/39 pin)                        */
  INT7_IRQn                     = 35,       /*!< Interrupt pin (PJ7/58 pin)                        */
  INTRX2_IRQn                   = 36,       /*!< Serial reception (channel.2)                      */
  INTTX2_IRQn                   = 37,       /*!< Serial transmission (channel.2)                   */
  INTSBI2_IRQn                  = 38,       /*!< Serial bus interface 2                            */
  INTTB7_IRQn                   = 40,       /*!< 16-bit TMRB match detection 7                     */
  INTTB8_IRQn                   = 41,       /*!< 16-bit TMRB match detection 8                     */
  INTTB9_IRQn                   = 42,       /*!< 16-bit TMRB match detection 9                     */
  INTCAP20_IRQn                 = 43,       /*!< 16-bit TMRB input capture 20                      */
  INTCAP21_IRQn                 = 44,       /*!< 16-bit TMRB input capture 21                      */
  INTCAP30_IRQn                 = 45,       /*!< 16-bit TMRB input capture 30                      */
  INTCAP31_IRQn                 = 46,       /*!< 16-bit TMRB input capture 31                      */
  INTCAP40_IRQn                 = 47,       /*!< 16-bit TMRB input capture 40                      */
  INTCAP41_IRQn                 = 48,       /*!< 16-bit TMRB input capture 41                      */
  INTAD_IRQn                    = 49        /*!< A/D conversion completion                         */
} IRQn_Type;


/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV              0x0101       /*!< Cortex-M3 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals            */
#include "system_TMPM333.h"                 /* TMPM333 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief Clock Generator (CG)
  */
typedef struct
{
  __IO uint32_t SYSCR;          /*!< System Control Register              */
  __IO uint32_t OSCCR;          /*!< Oscillation Control Register         */
  __IO uint32_t STBYCR;         /*!< Standby Control Register             */
  __IO uint32_t PLLSEL;         /*!< PLL Selection Register               */
  __IO uint32_t CKSEL;          /*!< System Clock Selection Register      */
  __O  uint32_t ICRCG;          /*!< CG Interrupt Request Clear Register  */
  __I  uint32_t NMIFLG;         /*!< NMI Flag Register                    */
  __IO uint32_t RSTFLG;         /*!< Reset Flag Register                  */
  __IO uint32_t IMCGA;          /*!< CG Interrupt Mode Control Register A */
  __IO uint32_t IMCGB;          /*!< CG Interrupt Mode Control Register B */
  __IO uint32_t IMCGC;          /*!< CG Interrupt Mode Control Register C */
} TSB_CG_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PA)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PA Data Register                 */
  __IO uint32_t CR;             /*!< PA Control Register              */
  __IO uint32_t FR1;            /*!< PA Function Register 1           */
       uint32_t RESERVED0[8];
  __IO uint32_t PUP;            /*!< PA Pull-Up Control Register      */
  __IO uint32_t PDN;            /*!< PA Pull-Down Control Register    */
       uint32_t RESERVED1;
  __IO uint32_t IE;             /*!< PA Input Enable Control Register */
} TSB_PA_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PB)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PB Data Register                 */
  __IO uint32_t CR;             /*!< PB Control Register              */
  __IO uint32_t FR1;            /*!< PB Function Register 1           */
       uint32_t RESERVED0[8];
  __IO uint32_t PUP;            /*!< PB Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PB Input Enable Control Register */
} TSB_PB_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PC)
  */
typedef struct
{
  __I  uint32_t DATA;           /*!< PC Data Register                 */
       uint32_t RESERVED0[10];
  __IO uint32_t PUP;            /*!< PC Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PC Input Enable Control Register */
} TSB_PC_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PD)
  */
typedef struct
{
  __I  uint32_t DATA;           /*!< PD Data Register                 */
       uint32_t RESERVED0;
  __IO uint32_t FR1;            /*!< PD Function Register 1           */
       uint32_t RESERVED1[8];
  __IO uint32_t PUP;            /*!< PD Pull-Up Control Register      */
       uint32_t RESERVED2[2];
  __IO uint32_t IE;             /*!< PD Input Enable Control Register */
} TSB_PD_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PE)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PE Data Register                 */
  __IO uint32_t CR;             /*!< PE Control Register              */
  __IO uint32_t FR1;            /*!< PE Function Register 1           */
  __IO uint32_t FR2;            /*!< PE Function Register 2           */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;             /*!< PE Open Drain Control Register   */
  __IO uint32_t PUP;            /*!< PE Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PE Input Enable Control Register */
} TSB_PE_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PF)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PF Data Register                 */
  __IO uint32_t CR;             /*!< PF Control Register              */
  __IO uint32_t FR1;            /*!< PF Function Register 1           */
  __IO uint32_t FR2;            /*!< PF Function Register 2           */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;             /*!< PF Open Drain Control Register   */
  __IO uint32_t PUP;            /*!< PF Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PF Input Enable Control Register */
} TSB_PF_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PG)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PG Data Register                 */
  __IO uint32_t CR;             /*!< PG Control Register              */
  __IO uint32_t FR1;            /*!< PG Function Register 1           */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;             /*!< PG Open Drain Control Register   */
  __IO uint32_t PUP;            /*!< PG Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PG Input Enable Control Register */
} TSB_PG_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PH)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PH Data Register                 */
  __IO uint32_t CR;             /*!< PH Control Register              */
  __IO uint32_t FR1;            /*!< PH Function Register 1           */
       uint32_t RESERVED0[8];
  __IO uint32_t PUP;            /*!< PH Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PH Input Enable Control Register */
} TSB_PH_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PI)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PI Data Register                 */
  __IO uint32_t CR;             /*!< PI Control Register              */
  __IO uint32_t FR1;            /*!< PI Function Register 1           */
       uint32_t RESERVED0[8];
  __IO uint32_t PUP;            /*!< PI Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PI Input Enable Control Register */
} TSB_PI_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PJ)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PJ Data Register                 */
  __IO uint32_t CR;             /*!< PJ Control Register              */
  __IO uint32_t FR1;            /*!< PJ Function Register 1           */
       uint32_t RESERVED0[8];
  __IO uint32_t PUP;            /*!< PJ Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PJ Input Enable Control Register */
} TSB_PJ_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PK)
  */
typedef struct
{
  __IO uint32_t DATA;           /*!< PK Data Register                 */
  __IO uint32_t CR;             /*!< PK Control Register              */
  __IO uint32_t FR1;            /*!< PK Function Register 1           */
  __IO uint32_t FR2;            /*!< PK Function Register 2           */
       uint32_t RESERVED0[7];
  __IO uint32_t PUP;            /*!< PK Pull-Up Control Register      */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;             /*!< PK Input Enable Control Register */
} TSB_PK_TypeDef;

/**
  * @brief 16-bit Timer/Event Counter (TB)
  */
typedef struct
{
  __IO uint32_t EN;             /*!< TB Enable Register            */
  __IO uint32_t RUN;            /*!< TB RUN Register               */
  __IO uint32_t CR;             /*!< TB Control Register           */
  __IO uint32_t MOD;            /*!< TB Mode Register              */
  __IO uint32_t FFCR;           /*!< TB Flip-Flop Control Register */
  __I  uint32_t ST;             /*!< TB Status Register            */
  __IO uint32_t IM;             /*!< TB Interrupt Mask Register    */
  __I  uint32_t UC;             /*!< TB Read Capture Register      */
  __IO uint32_t RG0;            /*!< TB RG0 Timer Register         */
  __IO uint32_t RG1;            /*!< TB RG1 Timer Register         */
  __I  uint32_t CP0;            /*!< TB CP0 Capture Register       */
  __I  uint32_t CP1;            /*!< TB CP1 Capture Register       */
} TSB_TB_TypeDef;

/**
  * @brief Serial Bus Interface (SBI)
  */
typedef struct
{
  __IO uint32_t CR0;            /*!< SBI Control Register 0       */
  __IO uint32_t CR1;            /*!< SBI Control Register 1       */
  __IO uint32_t DBR;            /*!< SBI Data Buffer Register     */
  __IO uint32_t I2CAR;          /*!< SBI I2C Bus Address Register */
  union {
  __O  uint32_t CR2;            /*!< SBI Control Register 2       */
  __I  uint32_t SR;             /*!< SBI Status Register          */
  }CR2SR;
  __IO uint32_t BR0;            /*!< SBI Baud Rate Register 0     */
} TSB_SBI_TypeDef;
#define CR2 CR2SR.CR2
#define SR  CR2SR.SR

/**
  * @brief Serial Channel (SC)
  */
typedef struct
{
  __IO uint32_t EN;             /*!< SC Enable Register                        */
  __IO uint32_t BUF;            /*!< SC Buffer Register                        */
  __IO uint32_t CR;             /*!< SC Control Register                       */
  __IO uint32_t MOD0;           /*!< SC Mode Control Register 0                */
  __IO uint32_t BRCR;           /*!< SC Baud Rate Generator Control Register   */
  __IO uint32_t BRADD;          /*!< SC Baud Rate Generator Control Register 2 */
  __IO uint32_t MOD1;           /*!< SC Mode Control Register 1                */
  __IO uint32_t MOD2;           /*!< SC Mode Control Register 2                */
  __IO uint32_t RFC;            /*!< SC RX FIFO Configuration Register         */
  __IO uint32_t TFC;            /*!< SC TX FIFO Configuration Register         */
  __I  uint32_t RST;            /*!< SC RX FIFO Status Register                */
  __I  uint32_t TST;            /*!< SC TX FIFO Status Register                */
  __IO uint32_t FCNF;           /*!< SC FIFO Configuration Register            */
} TSB_SC_TypeDef;

/**
  * @brief Analog-to-Digital Converter (AD)
  */
typedef struct
{
  __IO uint32_t CLK;            /*!< AD Conversion Clock Setting Register       */
  __IO uint32_t MOD0;           /*!< AD Mode Control Register 0                 */
  __IO uint32_t MOD1;           /*!< AD Mode Control Register 1                 */
  __IO uint32_t MOD2;           /*!< AD Mode Control Register 2                 */
  __IO uint32_t MOD3;           /*!< AD Mode Control Register 3                 */
  __IO uint32_t MOD4;           /*!< AD Mode Control Register 4                 */
  __IO uint32_t MOD5;           /*!< AD Mode Control Register 5                 */
       uint32_t RESERVED0;
  __IO uint32_t CBAS;           /*!< AD Conversion Accuracy Setting Register    */
       uint32_t RESERVED1[3];
  __I  uint32_t REG08;          /*!< AD Conversion Result Register 08           */
  __I  uint32_t REG19;          /*!< AD Conversion Result Register 19           */
  __I  uint32_t REG2A;          /*!< AD Conversion Result Register 2A           */
  __I  uint32_t REG3B;          /*!< AD Conversion Result Register 3B           */
  __I  uint32_t REG4C;          /*!< AD Conversion Result Register 4C           */
  __I  uint32_t REG5D;          /*!< AD Conversion Result Register 5D           */
  __I  uint32_t REG6E;          /*!< AD Conversion Result Register 6E           */
  __I  uint32_t REG7F;          /*!< AD Conversion Result Register 7F           */
  __I  uint32_t REGSP;          /*!< AD Conversion Result Register SP           */
  __IO uint32_t CMP0;           /*!< AD Conversion Result Comparison Register 0 */
  __IO uint32_t CMP1;           /*!< AD Conversion Result Comparison Register 1 */
} TSB_AD_TypeDef;

/**
  * @brief Watchdog Timer (WD)
  */
typedef struct
{
  __IO uint32_t MOD;            /*!< WD Mode Register    */
  __O  uint32_t CR;             /*!< WD Control Register */
} TSB_WD_TypeDef;

/**
  * @brief Real Time Clock (RTC)
  */
typedef struct
{
  __IO uint8_t SECR;            /*!< RTC Second Column Register          */
  __IO uint8_t MINR;            /*!< RTC Minute Column Register          */
  __IO uint8_t HOURR;           /*!< RTC Hour Column Register            */
       uint8_t RESERVED0;
  __IO uint8_t DAYR;            /*!< RTC Day of the Week Column Register */
  __IO uint8_t DATER;           /*!< RTC Day Column Register             */
  __IO uint8_t MONTHR;          /*!< RTC Month Column Register           */
  __IO uint8_t YEARR;           /*!< RTC Year Column Register            */
  __IO uint8_t PAGER;           /*!< RTC PAGE Register                   */
       uint8_t RESERVED1[3];
  __IO uint8_t RESTR;           /*!< RTC Reset Register                  */
} TSB_RTC_TypeDef;

/**
  * @brief Flash Control (FC)
  */
typedef struct
{
  __IO uint32_t SECBIT;         /*!< FC Security Bit Register  */
       uint32_t RESERVED0[7];
  __I  uint32_t FLCS;           /*!< FC Flash Control Register */
} TSB_FC_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)

#define TSB_PA_BASE               (PERI_BASE  + 0x00000UL)
#define TSB_PB_BASE               (PERI_BASE  + 0x00040UL)
#define TSB_PC_BASE               (PERI_BASE  + 0x00080UL)
#define TSB_PD_BASE               (PERI_BASE  + 0x000C0UL)
#define TSB_PE_BASE               (PERI_BASE  + 0x00100UL)
#define TSB_PF_BASE               (PERI_BASE  + 0x00140UL)
#define TSB_PG_BASE               (PERI_BASE  + 0x00180UL)
#define TSB_PH_BASE               (PERI_BASE  + 0x001C0UL)
#define TSB_PI_BASE               (PERI_BASE  + 0x00200UL)
#define TSB_PJ_BASE               (PERI_BASE  + 0x00240UL)
#define TSB_PK_BASE               (PERI_BASE  + 0x00280UL)
#define TSB_TB0_BASE              (PERI_BASE  + 0x10000UL)
#define TSB_TB1_BASE              (PERI_BASE  + 0x10040UL)
#define TSB_TB2_BASE              (PERI_BASE  + 0x10080UL)
#define TSB_TB3_BASE              (PERI_BASE  + 0x100C0UL)
#define TSB_TB4_BASE              (PERI_BASE  + 0x10100UL)
#define TSB_TB5_BASE              (PERI_BASE  + 0x10140UL)
#define TSB_TB6_BASE              (PERI_BASE  + 0x10180UL)
#define TSB_TB7_BASE              (PERI_BASE  + 0x101C0UL)
#define TSB_TB8_BASE              (PERI_BASE  + 0x10200UL)
#define TSB_TB9_BASE              (PERI_BASE  + 0x10240UL)
#define TSB_SBI0_BASE             (PERI_BASE  + 0x20000UL)
#define TSB_SBI1_BASE             (PERI_BASE  + 0x20020UL)
#define TSB_SBI2_BASE             (PERI_BASE  + 0x20040UL)
#define TSB_SC0_BASE              (PERI_BASE  + 0x20080UL)
#define TSB_SC1_BASE              (PERI_BASE  + 0x200C0UL)
#define TSB_SC2_BASE              (PERI_BASE  + 0x20100UL)
#define TSB_AD_BASE               (PERI_BASE  + 0x30000UL)
#define TSB_WD_BASE               (PERI_BASE  + 0x40000UL)
#define TSB_RTC_BASE              (PERI_BASE  + 0x40100UL)
#define TSB_CG_BASE               (PERI_BASE  + 0x40200UL)
#define TSB_FC_BASE               (PERI_BASE  + 0x40500UL)


/* Peripheral declaration */
#define TSB_PA                    ((     TSB_PA_TypeDef *)       TSB_PA_BASE)
#define TSB_PB                    ((     TSB_PB_TypeDef *)       TSB_PB_BASE)
#define TSB_PC                    ((     TSB_PC_TypeDef *)       TSB_PC_BASE)
#define TSB_PD                    ((     TSB_PD_TypeDef *)       TSB_PD_BASE)
#define TSB_PE                    ((     TSB_PE_TypeDef *)       TSB_PE_BASE)
#define TSB_PF                    ((     TSB_PF_TypeDef *)       TSB_PF_BASE)
#define TSB_PG                    ((     TSB_PG_TypeDef *)       TSB_PG_BASE)
#define TSB_PH                    ((     TSB_PH_TypeDef *)       TSB_PH_BASE)
#define TSB_PI                    ((     TSB_PI_TypeDef *)       TSB_PI_BASE)
#define TSB_PJ                    ((     TSB_PJ_TypeDef *)       TSB_PJ_BASE)
#define TSB_PK                    ((     TSB_PK_TypeDef *)       TSB_PK_BASE)
#define TSB_TB0                   ((     TSB_TB_TypeDef *)      TSB_TB0_BASE)
#define TSB_TB1                   ((     TSB_TB_TypeDef *)      TSB_TB1_BASE)
#define TSB_TB2                   ((     TSB_TB_TypeDef *)      TSB_TB2_BASE)
#define TSB_TB3                   ((     TSB_TB_TypeDef *)      TSB_TB3_BASE)
#define TSB_TB4                   ((     TSB_TB_TypeDef *)      TSB_TB4_BASE)
#define TSB_TB5                   ((     TSB_TB_TypeDef *)      TSB_TB5_BASE)
#define TSB_TB6                   ((     TSB_TB_TypeDef *)      TSB_TB6_BASE)
#define TSB_TB7                   ((     TSB_TB_TypeDef *)      TSB_TB7_BASE)
#define TSB_TB8                   ((     TSB_TB_TypeDef *)      TSB_TB8_BASE)
#define TSB_TB9                   ((     TSB_TB_TypeDef *)      TSB_TB9_BASE)
#define TSB_SBI0                  ((    TSB_SBI_TypeDef *)     TSB_SBI0_BASE)
#define TSB_SBI1                  ((    TSB_SBI_TypeDef *)     TSB_SBI1_BASE)
#define TSB_SBI2                  ((    TSB_SBI_TypeDef *)     TSB_SBI2_BASE)
#define TSB_SC0                   ((     TSB_SC_TypeDef *)      TSB_SC0_BASE)
#define TSB_SC1                   ((     TSB_SC_TypeDef *)      TSB_SC1_BASE)
#define TSB_SC2                   ((     TSB_SC_TypeDef *)      TSB_SC2_BASE)
#define TSB_AD                    ((     TSB_AD_TypeDef *)       TSB_AD_BASE)
#define TSB_WD                    ((     TSB_WD_TypeDef *)       TSB_WD_BASE)
#define TSB_RTC                   ((    TSB_RTC_TypeDef *)      TSB_RTC_BASE)
#define TSB_CG                    ((     TSB_CG_TypeDef *)       TSB_CG_BASE)
#define TSB_FC                    ((     TSB_FC_TypeDef *)       TSB_FC_BASE)

/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))

/* General Purpose Input/Output Port (PA) */
#define TSB_PA_DATA_PA0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,0)))
#define TSB_PA_DATA_PA1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,1)))
#define TSB_PA_DATA_PA2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,2)))
#define TSB_PA_DATA_PA3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,3)))
#define TSB_PA_DATA_PA4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,4)))
#define TSB_PA_DATA_PA5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,5)))
#define TSB_PA_DATA_PA6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,6)))
#define TSB_PA_DATA_PA7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,7)))
#define TSB_PA_CR_PA0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,0)))
#define TSB_PA_CR_PA1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,1)))
#define TSB_PA_CR_PA2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,2)))
#define TSB_PA_CR_PA3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,3)))
#define TSB_PA_CR_PA4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,4)))
#define TSB_PA_CR_PA5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,5)))
#define TSB_PA_CR_PA6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,6)))
#define TSB_PA_CR_PA7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,7)))
#define TSB_PA_FR1_PA0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,0)))
#define TSB_PA_FR1_PA1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,1)))
#define TSB_PA_FR1_PA2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,2)))
#define TSB_PA_FR1_PA3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,3)))
#define TSB_PA_FR1_PA4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,4)))
#define TSB_PA_FR1_PA5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,5)))
#define TSB_PA_FR1_PA6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,6)))
#define TSB_PA_PUP_PA0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,0)))
#define TSB_PA_PUP_PA2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,2)))
#define TSB_PA_PUP_PA3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,3)))
#define TSB_PA_PUP_PA4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,4)))
#define TSB_PA_PUP_PA5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,5)))
#define TSB_PA_PUP_PA6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,6)))
#define TSB_PA_PUP_PA7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,7)))
#define TSB_PA_PDN_PA1DN          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,1)))
#define TSB_PA_IE_PA0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,0)))
#define TSB_PA_IE_PA1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,1)))
#define TSB_PA_IE_PA2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,2)))
#define TSB_PA_IE_PA3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,3)))
#define TSB_PA_IE_PA4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,4)))
#define TSB_PA_IE_PA5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,5)))
#define TSB_PA_IE_PA6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,6)))
#define TSB_PA_IE_PA7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,7)))

/* General Purpose Input/Output Port (PB) */
#define TSB_PB_DATA_PB0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,0)))
#define TSB_PB_DATA_PB1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,1)))
#define TSB_PB_DATA_PB2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,2)))
#define TSB_PB_DATA_PB3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,3)))
#define TSB_PB_DATA_PB4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,4)))
#define TSB_PB_DATA_PB5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,5)))
#define TSB_PB_DATA_PB6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,6)))
#define TSB_PB_DATA_PB7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,7)))
#define TSB_PB_CR_PB0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,0)))
#define TSB_PB_CR_PB1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,1)))
#define TSB_PB_CR_PB2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,2)))
#define TSB_PB_CR_PB3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,3)))
#define TSB_PB_CR_PB4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,4)))
#define TSB_PB_CR_PB5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,5)))
#define TSB_PB_CR_PB6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,6)))
#define TSB_PB_CR_PB7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,7)))
#define TSB_PB_FR1_PB0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,0)))
#define TSB_PB_FR1_PB1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,1)))
#define TSB_PB_FR1_PB2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,2)))
#define TSB_PB_PUP_PB0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,0)))
#define TSB_PB_PUP_PB1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,1)))
#define TSB_PB_PUP_PB2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,2)))
#define TSB_PB_PUP_PB3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,4)))
#define TSB_PB_PUP_PB5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PUP_PB7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,7)))
#define TSB_PB_IE_PB0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,0)))
#define TSB_PB_IE_PB1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,1)))
#define TSB_PB_IE_PB2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,2)))
#define TSB_PB_IE_PB3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))
#define TSB_PB_IE_PB7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,7)))

/* General Purpose Input/Output Port (PC) */
#define TSB_PC_DATA_PC0           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PC->DATA,0)))
#define TSB_PC_DATA_PC1           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PC->DATA,1)))
#define TSB_PC_DATA_PC2           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PC->DATA,2)))
#define TSB_PC_DATA_PC3           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PC->DATA,3)))
#define TSB_PC_PUP_PC0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,0)))
#define TSB_PC_PUP_PC1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,1)))
#define TSB_PC_PUP_PC2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,2)))
#define TSB_PC_PUP_PC3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,3)))
#define TSB_PC_IE_PC0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,0)))
#define TSB_PC_IE_PC1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,1)))
#define TSB_PC_IE_PC2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,2)))
#define TSB_PC_IE_PC3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,3)))

/* General Purpose Input/Output Port (PD) */
#define TSB_PD_DATA_PD0           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,0)))
#define TSB_PD_DATA_PD1           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,1)))
#define TSB_PD_DATA_PD2           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,2)))
#define TSB_PD_DATA_PD3           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,3)))
#define TSB_PD_DATA_PD4           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,4)))
#define TSB_PD_DATA_PD5           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,5)))
#define TSB_PD_DATA_PD6           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,6)))
#define TSB_PD_DATA_PD7           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PD->DATA,7)))
#define TSB_PD_FR1_PD0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,0)))
#define TSB_PD_FR1_PD1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,1)))
#define TSB_PD_FR1_PD2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,2)))
#define TSB_PD_FR1_PD3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,3)))
#define TSB_PD_PUP_PD0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,0)))
#define TSB_PD_PUP_PD1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,1)))
#define TSB_PD_PUP_PD2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,2)))
#define TSB_PD_PUP_PD3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,3)))
#define TSB_PD_PUP_PD4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,4)))
#define TSB_PD_PUP_PD5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,5)))
#define TSB_PD_PUP_PD6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,6)))
#define TSB_PD_PUP_PD7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,7)))
#define TSB_PD_IE_PD0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,0)))
#define TSB_PD_IE_PD1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,1)))
#define TSB_PD_IE_PD2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,2)))
#define TSB_PD_IE_PD3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,3)))
#define TSB_PD_IE_PD4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,4)))
#define TSB_PD_IE_PD5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,5)))
#define TSB_PD_IE_PD6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,6)))
#define TSB_PD_IE_PD7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,7)))

/* General Purpose Input/Output Port (PE) */
#define TSB_PE_DATA_PE0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,0)))
#define TSB_PE_DATA_PE1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,1)))
#define TSB_PE_DATA_PE2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,2)))
#define TSB_PE_DATA_PE3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,3)))
#define TSB_PE_DATA_PE4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,4)))
#define TSB_PE_DATA_PE5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,5)))
#define TSB_PE_DATA_PE6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,6)))
#define TSB_PE_CR_PE0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,0)))
#define TSB_PE_CR_PE1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,1)))
#define TSB_PE_CR_PE2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,2)))
#define TSB_PE_CR_PE3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,3)))
#define TSB_PE_CR_PE4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,4)))
#define TSB_PE_CR_PE5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,5)))
#define TSB_PE_CR_PE6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,6)))
#define TSB_PE_FR1_PE0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,0)))
#define TSB_PE_FR1_PE1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,1)))
#define TSB_PE_FR1_PE2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,2)))
#define TSB_PE_FR1_PE3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,3)))
#define TSB_PE_FR1_PE4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,4)))
#define TSB_PE_FR1_PE5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,5)))
#define TSB_PE_FR1_PE6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,6)))
#define TSB_PE_FR2_PE2F2          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_FR2_PE6F2          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,6)))
#define TSB_PE_OD_PE0OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,0)))
#define TSB_PE_OD_PE1OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,1)))
#define TSB_PE_OD_PE2OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,2)))
#define TSB_PE_OD_PE3OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,3)))
#define TSB_PE_OD_PE4OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,4)))
#define TSB_PE_OD_PE5OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,5)))
#define TSB_PE_OD_PE6OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,6)))
#define TSB_PE_PUP_PE0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,0)))
#define TSB_PE_PUP_PE1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,1)))
#define TSB_PE_PUP_PE2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,2)))
#define TSB_PE_PUP_PE3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,3)))
#define TSB_PE_PUP_PE4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,4)))
#define TSB_PE_PUP_PE5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,5)))
#define TSB_PE_PUP_PE6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,6)))
#define TSB_PE_IE_PE0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,0)))
#define TSB_PE_IE_PE1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,1)))
#define TSB_PE_IE_PE2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,2)))
#define TSB_PE_IE_PE3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,3)))
#define TSB_PE_IE_PE4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,4)))
#define TSB_PE_IE_PE5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,5)))
#define TSB_PE_IE_PE6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,6)))

/* General Purpose Input/Output Port (PF) */
#define TSB_PF_DATA_PF0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,0)))
#define TSB_PF_DATA_PF1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,1)))
#define TSB_PF_DATA_PF2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,2)))
#define TSB_PF_DATA_PF3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,3)))
#define TSB_PF_DATA_PF4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,4)))
#define TSB_PF_DATA_PF5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,5)))
#define TSB_PF_DATA_PF6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,6)))
#define TSB_PF_DATA_PF7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,7)))
#define TSB_PF_CR_PF0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,1)))
#define TSB_PF_CR_PF2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,2)))
#define TSB_PF_CR_PF3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,3)))
#define TSB_PF_CR_PF4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,4)))
#define TSB_PF_CR_PF5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,5)))
#define TSB_PF_CR_PF6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,6)))
#define TSB_PF_CR_PF7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,7)))
#define TSB_PF_FR1_PF0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,0)))
#define TSB_PF_FR1_PF1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,1)))
#define TSB_PF_FR1_PF2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,2)))
#define TSB_PF_FR1_PF3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,3)))
#define TSB_PF_FR1_PF4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,4)))
#define TSB_PF_FR1_PF5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,5)))
#define TSB_PF_FR1_PF6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,6)))
#define TSB_PF_FR1_PF7F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,7)))
#define TSB_PF_FR2_PF2F2          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,2)))
#define TSB_PF_OD_PF0OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF1OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,1)))
#define TSB_PF_OD_PF2OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,2)))
#define TSB_PF_OD_PF3OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,3)))
#define TSB_PF_OD_PF4OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,4)))
#define TSB_PF_OD_PF5OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,5)))
#define TSB_PF_OD_PF6OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,6)))
#define TSB_PF_OD_PF7OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,7)))
#define TSB_PF_PUP_PF0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,1)))
#define TSB_PF_PUP_PF2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,2)))
#define TSB_PF_PUP_PF3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,3)))
#define TSB_PF_PUP_PF4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,4)))
#define TSB_PF_PUP_PF5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,5)))
#define TSB_PF_PUP_PF6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,6)))
#define TSB_PF_PUP_PF7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,7)))
#define TSB_PF_IE_PF0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,1)))
#define TSB_PF_IE_PF2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,2)))
#define TSB_PF_IE_PF3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,3)))
#define TSB_PF_IE_PF4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,4)))
#define TSB_PF_IE_PF5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,5)))
#define TSB_PF_IE_PF6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,6)))
#define TSB_PF_IE_PF7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,7)))

/* General Purpose Input/Output Port (PG) */
#define TSB_PG_DATA_PG0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,0)))
#define TSB_PG_DATA_PG1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,1)))
#define TSB_PG_DATA_PG2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,2)))
#define TSB_PG_DATA_PG3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,3)))
#define TSB_PG_DATA_PG4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,4)))
#define TSB_PG_DATA_PG5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,5)))
#define TSB_PG_DATA_PG6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,6)))
#define TSB_PG_DATA_PG7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,7)))
#define TSB_PG_CR_PG0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,0)))
#define TSB_PG_CR_PG1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,1)))
#define TSB_PG_CR_PG2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,2)))
#define TSB_PG_CR_PG3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,3)))
#define TSB_PG_CR_PG4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,4)))
#define TSB_PG_CR_PG5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,5)))
#define TSB_PG_CR_PG6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,6)))
#define TSB_PG_CR_PG7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,7)))
#define TSB_PG_FR1_PG0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,0)))
#define TSB_PG_FR1_PG1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,1)))
#define TSB_PG_FR1_PG2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,2)))
#define TSB_PG_FR1_PG3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,3)))
#define TSB_PG_FR1_PG4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,4)))
#define TSB_PG_FR1_PG5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,5)))
#define TSB_PG_FR1_PG6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,6)))
#define TSB_PG_FR1_PG7F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,7)))
#define TSB_PG_OD_PG0OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,0)))
#define TSB_PG_OD_PG1OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,1)))
#define TSB_PG_OD_PG2OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,2)))
#define TSB_PG_OD_PG3OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,3)))
#define TSB_PG_OD_PG4OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,4)))
#define TSB_PG_OD_PG5OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,5)))
#define TSB_PG_OD_PG6OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,6)))
#define TSB_PG_OD_PG7OD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,7)))
#define TSB_PG_PUP_PG0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,0)))
#define TSB_PG_PUP_PG1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,1)))
#define TSB_PG_PUP_PG2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,2)))
#define TSB_PG_PUP_PG3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,3)))
#define TSB_PG_PUP_PG4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,4)))
#define TSB_PG_PUP_PG5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,5)))
#define TSB_PG_PUP_PG6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,6)))
#define TSB_PG_PUP_PG7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,7)))
#define TSB_PG_IE_PG0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,0)))
#define TSB_PG_IE_PG1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,1)))
#define TSB_PG_IE_PG2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,2)))
#define TSB_PG_IE_PG3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,3)))
#define TSB_PG_IE_PG4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,4)))
#define TSB_PG_IE_PG5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,5)))
#define TSB_PG_IE_PG6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,6)))
#define TSB_PG_IE_PG7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,7)))

/* General Purpose Input/Output Port (PH) */
#define TSB_PH_DATA_PH0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,0)))
#define TSB_PH_DATA_PH1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,1)))
#define TSB_PH_DATA_PH2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,2)))
#define TSB_PH_DATA_PH3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,3)))
#define TSB_PH_DATA_PH4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,4)))
#define TSB_PH_DATA_PH5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,5)))
#define TSB_PH_DATA_PH6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,6)))
#define TSB_PH_DATA_PH7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,7)))
#define TSB_PH_CR_PH0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,0)))
#define TSB_PH_CR_PH1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,1)))
#define TSB_PH_CR_PH2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,2)))
#define TSB_PH_CR_PH3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,3)))
#define TSB_PH_CR_PH4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,4)))
#define TSB_PH_CR_PH5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,5)))
#define TSB_PH_CR_PH6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,6)))
#define TSB_PH_CR_PH7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,7)))
#define TSB_PH_FR1_PH0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,0)))
#define TSB_PH_FR1_PH1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,1)))
#define TSB_PH_FR1_PH2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,2)))
#define TSB_PH_FR1_PH3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,3)))
#define TSB_PH_FR1_PH4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,4)))
#define TSB_PH_FR1_PH5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,5)))
#define TSB_PH_FR1_PH6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,6)))
#define TSB_PH_FR1_PH7F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,7)))
#define TSB_PH_PUP_PH0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,0)))
#define TSB_PH_PUP_PH1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,1)))
#define TSB_PH_PUP_PH2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,2)))
#define TSB_PH_PUP_PH3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,3)))
#define TSB_PH_PUP_PH4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,4)))
#define TSB_PH_PUP_PH5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,5)))
#define TSB_PH_PUP_PH6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,6)))
#define TSB_PH_PUP_PH7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,7)))
#define TSB_PH_IE_PH0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,0)))
#define TSB_PH_IE_PH1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,1)))
#define TSB_PH_IE_PH2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,2)))
#define TSB_PH_IE_PH3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,3)))
#define TSB_PH_IE_PH4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,4)))
#define TSB_PH_IE_PH5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,5)))
#define TSB_PH_IE_PH6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,6)))
#define TSB_PH_IE_PH7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,7)))

/* General Purpose Input/Output Port (PI) */
#define TSB_PI_DATA_PI0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,0)))
#define TSB_PI_DATA_PI1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,1)))
#define TSB_PI_DATA_PI2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,2)))
#define TSB_PI_DATA_PI3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,3)))
#define TSB_PI_DATA_PI4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,4)))
#define TSB_PI_DATA_PI5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,5)))
#define TSB_PI_DATA_PI6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,6)))
#define TSB_PI_DATA_PI7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,7)))
#define TSB_PI_CR_PI0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,0)))
#define TSB_PI_CR_PI1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,1)))
#define TSB_PI_CR_PI2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,2)))
#define TSB_PI_CR_PI3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_CR_PI4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,4)))
#define TSB_PI_CR_PI5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,5)))
#define TSB_PI_CR_PI6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,6)))
#define TSB_PI_CR_PI7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,7)))
#define TSB_PI_FR1_PI0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,0)))
#define TSB_PI_FR1_PI1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,1)))
#define TSB_PI_FR1_PI2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,2)))
#define TSB_PI_FR1_PI3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,3)))
#define TSB_PI_FR1_PI4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,4)))
#define TSB_PI_FR1_PI5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,5)))
#define TSB_PI_FR1_PI6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,6)))
#define TSB_PI_FR1_PI7F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,7)))
#define TSB_PI_PUP_PI0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,0)))
#define TSB_PI_PUP_PI1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,1)))
#define TSB_PI_PUP_PI2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,2)))
#define TSB_PI_PUP_PI3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,3)))
#define TSB_PI_PUP_PI4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,4)))
#define TSB_PI_PUP_PI5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,5)))
#define TSB_PI_PUP_PI6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,6)))
#define TSB_PI_PUP_PI7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,7)))
#define TSB_PI_IE_PI0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,0)))
#define TSB_PI_IE_PI1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,1)))
#define TSB_PI_IE_PI2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,2)))
#define TSB_PI_IE_PI3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))
#define TSB_PI_IE_PI4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,4)))
#define TSB_PI_IE_PI5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,5)))
#define TSB_PI_IE_PI6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,6)))
#define TSB_PI_IE_PI7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,7)))

/* General Purpose Input/Output Port (PJ) */
#define TSB_PJ_DATA_PJ0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,1)))
#define TSB_PJ_DATA_PJ2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,2)))
#define TSB_PJ_DATA_PJ3           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,3)))
#define TSB_PJ_DATA_PJ4           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,4)))
#define TSB_PJ_DATA_PJ5           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,5)))
#define TSB_PJ_DATA_PJ6           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,6)))
#define TSB_PJ_DATA_PJ7           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,7)))
#define TSB_PJ_CR_PJ0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,0)))
#define TSB_PJ_CR_PJ1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,1)))
#define TSB_PJ_CR_PJ2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,2)))
#define TSB_PJ_CR_PJ3C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,3)))
#define TSB_PJ_CR_PJ4C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,4)))
#define TSB_PJ_CR_PJ5C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,5)))
#define TSB_PJ_CR_PJ6C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,6)))
#define TSB_PJ_CR_PJ7C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,7)))
#define TSB_PJ_FR1_PJ0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,0)))
#define TSB_PJ_FR1_PJ1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,1)))
#define TSB_PJ_FR1_PJ2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,2)))
#define TSB_PJ_FR1_PJ3F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,3)))
#define TSB_PJ_FR1_PJ4F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,4)))
#define TSB_PJ_FR1_PJ5F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,5)))
#define TSB_PJ_FR1_PJ6F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,6)))
#define TSB_PJ_FR1_PJ7F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,7)))
#define TSB_PJ_PUP_PJ0UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,1)))
#define TSB_PJ_PUP_PJ2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,2)))
#define TSB_PJ_PUP_PJ3UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,3)))
#define TSB_PJ_PUP_PJ4UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,4)))
#define TSB_PJ_PUP_PJ5UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,5)))
#define TSB_PJ_PUP_PJ6UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,6)))
#define TSB_PJ_PUP_PJ7UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,7)))
#define TSB_PJ_IE_PJ0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,1)))
#define TSB_PJ_IE_PJ2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,2)))
#define TSB_PJ_IE_PJ3IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,3)))
#define TSB_PJ_IE_PJ4IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,4)))
#define TSB_PJ_IE_PJ5IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,5)))
#define TSB_PJ_IE_PJ6IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,6)))
#define TSB_PJ_IE_PJ7IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,7)))

/* General Purpose Input/Output Port (PK) */
#define TSB_PK_DATA_PK0           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,0)))
#define TSB_PK_DATA_PK1           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,1)))
#define TSB_PK_DATA_PK2           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,2)))
#define TSB_PK_CR_PK0C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,0)))
#define TSB_PK_CR_PK1C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,1)))
#define TSB_PK_CR_PK2C            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,2)))
#define TSB_PK_FR1_PK0F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,0)))
#define TSB_PK_FR1_PK1F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,1)))
#define TSB_PK_FR1_PK2F1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,2)))
#define TSB_PK_FR2_PK1F2          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR2,1)))
#define TSB_PK_PUP_PK1UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,1)))
#define TSB_PK_PUP_PK2UP          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,2)))
#define TSB_PK_IE_PK0IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,0)))
#define TSB_PK_IE_PK1IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,1)))
#define TSB_PK_IE_PK2IE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,2)))

/* 16-bit Timer/Event Counter (TB) */
#define TSB_TB0_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,3)))
#define TSB_TB0_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,5)))
#define TSB_TB0_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,7)))
#define TSB_TB0_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,2)))
#define TSB_TB0_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,5)))
#define TSB_TB0_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,2)))
#define TSB_TB0_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,3)))
#define TSB_TB0_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,4)))
#define TSB_TB0_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,5)))
#define TSB_TB0_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,0)))
#define TSB_TB0_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,1)))
#define TSB_TB0_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,2)))

#define TSB_TB1_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,7)))
#define TSB_TB1_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,0)))
#define TSB_TB1_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,2)))
#define TSB_TB1_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,3)))
#define TSB_TB1_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,5)))
#define TSB_TB1_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,7)))
#define TSB_TB1_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,2)))
#define TSB_TB1_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,5)))
#define TSB_TB1_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,2)))
#define TSB_TB1_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,3)))
#define TSB_TB1_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,4)))
#define TSB_TB1_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,5)))
#define TSB_TB1_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,0)))
#define TSB_TB1_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,1)))
#define TSB_TB1_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,2)))

#define TSB_TB2_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,7)))
#define TSB_TB2_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,0)))
#define TSB_TB2_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,2)))
#define TSB_TB2_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,3)))
#define TSB_TB2_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,5)))
#define TSB_TB2_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,7)))
#define TSB_TB2_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,2)))
#define TSB_TB2_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,5)))
#define TSB_TB2_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,2)))
#define TSB_TB2_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,3)))
#define TSB_TB2_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,4)))
#define TSB_TB2_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,5)))
#define TSB_TB2_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,0)))
#define TSB_TB2_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,1)))
#define TSB_TB2_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,2)))

#define TSB_TB3_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,7)))
#define TSB_TB3_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,0)))
#define TSB_TB3_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,2)))
#define TSB_TB3_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,3)))
#define TSB_TB3_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,5)))
#define TSB_TB3_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,7)))
#define TSB_TB3_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,2)))
#define TSB_TB3_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,5)))
#define TSB_TB3_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,2)))
#define TSB_TB3_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,3)))
#define TSB_TB3_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,4)))
#define TSB_TB3_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,5)))
#define TSB_TB3_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,0)))
#define TSB_TB3_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,1)))
#define TSB_TB3_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,2)))

#define TSB_TB4_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,7)))
#define TSB_TB4_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,0)))
#define TSB_TB4_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,2)))
#define TSB_TB4_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,3)))
#define TSB_TB4_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,5)))
#define TSB_TB4_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,7)))
#define TSB_TB4_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,2)))
#define TSB_TB4_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,5)))
#define TSB_TB4_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,2)))
#define TSB_TB4_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,3)))
#define TSB_TB4_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,4)))
#define TSB_TB4_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,5)))
#define TSB_TB4_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,0)))
#define TSB_TB4_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,1)))
#define TSB_TB4_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,2)))

#define TSB_TB5_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,7)))
#define TSB_TB5_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,0)))
#define TSB_TB5_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,2)))
#define TSB_TB5_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,3)))
#define TSB_TB5_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,5)))
#define TSB_TB5_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,7)))
#define TSB_TB5_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,2)))
#define TSB_TB5_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,5)))
#define TSB_TB5_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,2)))
#define TSB_TB5_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,3)))
#define TSB_TB5_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,4)))
#define TSB_TB5_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,5)))
#define TSB_TB5_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,0)))
#define TSB_TB5_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,1)))
#define TSB_TB5_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,2)))

#define TSB_TB6_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,7)))
#define TSB_TB6_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,0)))
#define TSB_TB6_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,2)))
#define TSB_TB6_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,3)))
#define TSB_TB6_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,5)))
#define TSB_TB6_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,7)))
#define TSB_TB6_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,2)))
#define TSB_TB6_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,5)))
#define TSB_TB6_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,2)))
#define TSB_TB6_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,3)))
#define TSB_TB6_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,4)))
#define TSB_TB6_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,5)))
#define TSB_TB6_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,0)))
#define TSB_TB6_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,1)))
#define TSB_TB6_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,2)))

#define TSB_TB7_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,7)))
#define TSB_TB7_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,0)))
#define TSB_TB7_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,2)))
#define TSB_TB7_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,3)))
#define TSB_TB7_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,5)))
#define TSB_TB7_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,7)))
#define TSB_TB7_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,2)))
#define TSB_TB7_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,5)))
#define TSB_TB7_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,2)))
#define TSB_TB7_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,3)))
#define TSB_TB7_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,4)))
#define TSB_TB7_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,5)))
#define TSB_TB7_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,0)))
#define TSB_TB7_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,1)))
#define TSB_TB7_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,2)))

#define TSB_TB8_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->EN,7)))
#define TSB_TB8_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,0)))
#define TSB_TB8_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,2)))
#define TSB_TB8_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,3)))
#define TSB_TB8_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,5)))
#define TSB_TB8_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,7)))
#define TSB_TB8_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,2)))
#define TSB_TB8_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,5)))
#define TSB_TB8_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,2)))
#define TSB_TB8_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,3)))
#define TSB_TB8_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,4)))
#define TSB_TB8_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,5)))
#define TSB_TB8_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,0)))
#define TSB_TB8_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,1)))
#define TSB_TB8_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,2)))

#define TSB_TB9_EN_TBEN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->EN,7)))
#define TSB_TB9_RUN_TBRUN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,0)))
#define TSB_TB9_RUN_TBPRUN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,2)))
#define TSB_TB9_CR_I2TB           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,3)))
#define TSB_TB9_CR_TBSYNC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,5)))
#define TSB_TB9_CR_TBWBF          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,7)))
#define TSB_TB9_MOD_TBCLE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,2)))
#define TSB_TB9_MOD_TBCP          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,5)))
#define TSB_TB9_FFCR_TBE0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,2)))
#define TSB_TB9_FFCR_TBE1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,3)))
#define TSB_TB9_FFCR_TBC0T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,4)))
#define TSB_TB9_FFCR_TBC1T1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,5)))
#define TSB_TB9_IM_TBIM0          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,0)))
#define TSB_TB9_IM_TBIM1          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,1)))
#define TSB_TB9_IM_TBIMOF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,2)))

/* Serial Bus Interface (SBI) */
#define TSB_SBI0_CR0_SBIEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->CR0,7)))
#define TSB_SBI0_CR1_SWRMON       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->CR1,0)))
#define TSB_SBI0_I2CAR_ALS        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->I2CAR,0)))
#define TSB_SBI0_SR_LRB           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,0)))
#define TSB_SBI0_SR_ADO           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,1)))
#define TSB_SBI0_SR_AAS           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,2)))
#define TSB_SBI0_SR_AL            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,3)))
#define TSB_SBI0_SR_PIN           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,4)))
#define TSB_SBI0_SR_BB            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,5)))
#define TSB_SBI0_SR_TRX           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,6)))
#define TSB_SBI0_SR_MST           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,7)))
#define TSB_SBI0_SR_SEF           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,2)))
#define TSB_SBI0_SR_SIOF          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,3)))
#define TSB_SBI0_BR0_I2SBI        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->BR0,6)))

#define TSB_SBI1_CR0_SBIEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->CR0,7)))
#define TSB_SBI1_CR1_SWRMON       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->CR1,0)))
#define TSB_SBI1_I2CAR_ALS        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->I2CAR,0)))
#define TSB_SBI1_SR_LRB           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,0)))
#define TSB_SBI1_SR_ADO           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,1)))
#define TSB_SBI1_SR_AAS           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,2)))
#define TSB_SBI1_SR_AL            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,3)))
#define TSB_SBI1_SR_PIN           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,4)))
#define TSB_SBI1_SR_BB            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,5)))
#define TSB_SBI1_SR_TRX           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,6)))
#define TSB_SBI1_SR_MST           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,7)))
#define TSB_SBI1_SR_SEF           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,2)))
#define TSB_SBI1_SR_SIOF          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,3)))
#define TSB_SBI1_BR0_I2SBI        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->BR0,6)))

#define TSB_SBI2_CR0_SBIEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->CR0,7)))
#define TSB_SBI2_CR1_SWRMON       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->CR1,0)))
#define TSB_SBI2_I2CAR_ALS        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->I2CAR,0)))
#define TSB_SBI2_SR_LRB           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,0)))
#define TSB_SBI2_SR_ADO           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,1)))
#define TSB_SBI2_SR_AAS           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,2)))
#define TSB_SBI2_SR_AL            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,3)))
#define TSB_SBI2_SR_PIN           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,4)))
#define TSB_SBI2_SR_BB            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,5)))
#define TSB_SBI2_SR_TRX           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,6)))
#define TSB_SBI2_SR_MST           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,7)))
#define TSB_SBI2_SR_SEF           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,2)))
#define TSB_SBI2_SR_SIOF          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,3)))
#define TSB_SBI2_BR0_I2SBI        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->BR0,6)))

/* Serial Channel (SC) */
#define TSB_SC0_EN_SIOE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->EN,0)))
#define TSB_SC0_MOD0_WU           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,4)))
#define TSB_SC0_MOD0_RXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,5)))
#define TSB_SC0_MOD0_CTSE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,6)))
#define TSB_SC0_MOD0_TB8          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,7)))
#define TSB_SC0_BRCR_BRADDE       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->BRCR,6)))
#define TSB_SC0_MOD1_TXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,4)))
#define TSB_SC0_MOD1_I2SC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,7)))
#define TSB_SC0_MOD2_WBUF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,2)))
#define TSB_SC0_MOD2_DRCHG        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,3)))
#define TSB_SC0_MOD2_SBLEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,4)))
#define TSB_SC0_MOD2_TXRUN        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,5)))
#define TSB_SC0_MOD2_RBFLL        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,6)))
#define TSB_SC0_MOD2_TBEMP        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,7)))
#define TSB_SC0_RFC_RFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,6)))
#define TSB_SC0_RFC_RFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,7)))
#define TSB_SC0_TFC_TFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,6)))
#define TSB_SC0_TFC_TFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,7)))
#define TSB_SC0_RST_ROR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->RST,7)))
#define TSB_SC0_TST_TUR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->TST,7)))
#define TSB_SC0_FCNF_CNFG         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,0)))
#define TSB_SC0_FCNF_RXTXCNT      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,1)))
#define TSB_SC0_FCNF_RFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,2)))
#define TSB_SC0_FCNF_TFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,3)))
#define TSB_SC0_FCNF_RFST         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,4)))

#define TSB_SC1_EN_SIOE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->EN,0)))
#define TSB_SC1_MOD0_WU           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,4)))
#define TSB_SC1_MOD0_RXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,5)))
#define TSB_SC1_MOD0_CTSE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,6)))
#define TSB_SC1_MOD0_TB8          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,7)))
#define TSB_SC1_BRCR_BRADDE       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->BRCR,6)))
#define TSB_SC1_MOD1_TXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,4)))
#define TSB_SC1_MOD1_I2SC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,7)))
#define TSB_SC1_MOD2_WBUF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,2)))
#define TSB_SC1_MOD2_DRCHG        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,3)))
#define TSB_SC1_MOD2_SBLEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,4)))
#define TSB_SC1_MOD2_TXRUN        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,5)))
#define TSB_SC1_MOD2_RBFLL        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,6)))
#define TSB_SC1_MOD2_TBEMP        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,7)))
#define TSB_SC1_RFC_RFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,6)))
#define TSB_SC1_RFC_RFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,7)))
#define TSB_SC1_TFC_TFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,6)))
#define TSB_SC1_TFC_TFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,7)))
#define TSB_SC1_RST_ROR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->RST,7)))
#define TSB_SC1_TST_TUR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->TST,7)))
#define TSB_SC1_FCNF_CNFG         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,0)))
#define TSB_SC1_FCNF_RXTXCNT      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,1)))
#define TSB_SC1_FCNF_RFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,2)))
#define TSB_SC1_FCNF_TFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,3)))
#define TSB_SC1_FCNF_RFST         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,4)))

#define TSB_SC2_EN_SIOE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->EN,0)))
#define TSB_SC2_MOD0_WU           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,4)))
#define TSB_SC2_MOD0_RXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,5)))
#define TSB_SC2_MOD0_CTSE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,6)))
#define TSB_SC2_MOD0_TB8          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,7)))
#define TSB_SC2_BRCR_BRADDE       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->BRCR,6)))
#define TSB_SC2_MOD1_TXE          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,4)))
#define TSB_SC2_MOD1_I2SC         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,7)))
#define TSB_SC2_MOD2_WBUF         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,2)))
#define TSB_SC2_MOD2_DRCHG        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,3)))
#define TSB_SC2_MOD2_SBLEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,4)))
#define TSB_SC2_MOD2_TXRUN        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,5)))
#define TSB_SC2_MOD2_RBFLL        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,6)))
#define TSB_SC2_MOD2_TBEMP        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,7)))
#define TSB_SC2_RFC_RFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,6)))
#define TSB_SC2_RFC_RFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,7)))
#define TSB_SC2_TFC_TFIS          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,6)))
#define TSB_SC2_TFC_TFCS          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,7)))
#define TSB_SC2_RST_ROR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->RST,7)))
#define TSB_SC2_TST_TUR           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->TST,7)))
#define TSB_SC2_FCNF_CNFG         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,0)))
#define TSB_SC2_FCNF_RXTXCNT      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,1)))
#define TSB_SC2_FCNF_RFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,2)))
#define TSB_SC2_FCNF_TFIE         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,3)))
#define TSB_SC2_FCNF_RFST         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,4)))

/* Analog-to-Digital Converter (AD) */
#define TSB_AD_MOD0_ADS           (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,0)))
#define TSB_AD_MOD0_SCAN          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,1)))
#define TSB_AD_MOD0_REPEAT        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,2)))
#define TSB_AD_MOD0_ADBFN         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,6)))
#define TSB_AD_MOD0_EOCFN         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,7)))
#define TSB_AD_MOD1_ADSCN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,5)))
#define TSB_AD_MOD1_I2AD          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,6)))
#define TSB_AD_MOD1_VREFON        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,7)))
#define TSB_AD_MOD2_HPADCE        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,5)))
#define TSB_AD_MOD2_ADBFHP        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,6)))
#define TSB_AD_MOD2_EOCFHP        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,7)))
#define TSB_AD_MOD3_ADOBSV0       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,0)))
#define TSB_AD_MOD3_ADOBIC0       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,5)))
#define TSB_AD_MOD5_ADOBSV1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,0)))
#define TSB_AD_MOD5_ADOBIC1       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,5)))

/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_I2WDT          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,2)))
#define TSB_WD_MOD_WDTE           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))

/* Real Time Clock (RTC) */
#define TSB_RTC_MONTHR_MO0        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RTC->MONTHR,0)))

/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FPSEL        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,12)))
#define TSB_CG_OSCCR_WUEON        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_PLLON        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,2)))
#define TSB_CG_OSCCR_WUPSEL       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XTEN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,9)))
#define TSB_CG_STBYCR_RXEN        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,8)))
#define TSB_CG_STBYCR_RXTEN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,9)))
#define TSB_CG_STBYCR_DRVE        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,16)))
#define TSB_CG_PLLSEL_PLLSEL      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,0)))
#define TSB_CG_CKSEL_SYSCKFLG     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,0)))
#define TSB_CG_CKSEL_SYSCK        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,1)))
#define TSB_CG_RSTFLG_PONRSTF     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,0)))
#define TSB_CG_RSTFLG_PINRSTF     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,1)))
#define TSB_CG_RSTFLG_WDTRSTF     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,2)))
#define TSB_CG_RSTFLG_SYSRSTF     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,4)))
#define TSB_CG_IMCGA_INT0EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,0)))
#define TSB_CG_IMCGA_INT1EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,8)))
#define TSB_CG_IMCGA_INT2EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,16)))
#define TSB_CG_IMCGA_INT3EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))
#define TSB_CG_IMCGC_INT8EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,0)))
#define TSB_CG_IMCGC_INT9EN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,8)))
#define TSB_CG_IMCGC_INTAEN       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,16)))

/* Flash Control (FC) */
#define TSB_FC_SECBIT_SECBIT      (*((__IO uint32_t *)BITBAND_PERI(&TSB_FC->SECBIT,0)))
#define TSB_FC_FLCS_RDY_BSY       (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,0)))
#define TSB_FC_FLCS_BLPRO0        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,16)))
#define TSB_FC_FLCS_BLPRO1        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,17)))
#define TSB_FC_FLCS_BLPRO2        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,18)))
#define TSB_FC_FLCS_BLPRO3        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,19)))
#define TSB_FC_FLCS_BLPRO4        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,20)))
#define TSB_FC_FLCS_BLPRO5        (*((__I  uint32_t *)BITBAND_PERI(&TSB_FC->FLCS,21)))

/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM333_H__ */

/** @} */ /* End of group TMPM333 */
/** @} */ /* End of group TOSHIBA_TX03_MICROCONTROLLER */
