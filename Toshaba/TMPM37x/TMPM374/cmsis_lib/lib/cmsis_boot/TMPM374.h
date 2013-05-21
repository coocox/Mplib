/**
 *******************************************************************************
 * @file    TMPM374.h
 * @brief   CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM374' Device Series
 * @version V2.2.0
 * @date    2011/03/23
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/** @addtogroup TOSHIBA_TX03_MICROCONTROLLER
  * @{
  */

/** @addtogroup TMPM374
  * @{
  */

#ifndef __TMPM374_H__
#define __TMPM374_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/** Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************************/
  NonMaskableInt_IRQn           = -14,       /*!< 2 Non Maskable Interrupt                                    */
  HardFault_IRQn                = -13,       /*!< 3 Cortex-M3 Hard Fault Interrupt                            */
  MemoryManagement_IRQn         = -12,       /*!< 4 Cortex-M3 Memory Management Interrupt                     */
  BusFault_IRQn                 = -11,       /*!< 5 Cortex-M3 Bus Fault Interrupt                             */
  UsageFault_IRQn               = -10,       /*!< 6 Cortex-M3 Usage Fault Interrupt                           */
  SVCall_IRQn                   = -5,        /*!< 11 Cortex-M3 SV Call Interrupt                              */
  DebugMonitor_IRQn             = -4,        /*!< 12 Cortex-M3 Debug Monitor Interrupt                        */
  PendSV_IRQn                   = -2,        /*!< 14 Cortex-M3 Pend SV Interrupt                              */
  SysTick_IRQn                  = -1,        /*!< 15 Cortex-M3 System Tick Interrupt                          */

/******  TMPM374 Specific Interrupt Numbers *******************************************************************/
  INT5_IRQn                     = 5,         /*!< Interrupt Pin (PE4/TB2IN//15pin or 17pin)                   */
  INTRX0_IRQn                   = 6,         /*!< Serial reception (channel.0)                                */
  INTTX0_IRQn                   = 7,         /*!< Serial transmit (channel.0)                                 */
  INTRX1_IRQn                   = 8,         /*!< Serial reception (channel.1)                                */
  INTTX1_IRQn                   = 9,         /*!< Serial transmit (channel.1)                                 */
  INTVCNB_IRQn                  = 11,        /*!< Vector Engine interrupt B                                   */
  INTEMG1_IRQn                  = 13,        /*!< PMD1 EMG interrupt                                          */
  INTOVV1_IRQn                  = 15,        /*!< PMD1 OVV interrupt                                          */
  INTADBPDB_IRQn                = 19,        /*!< ADCB conversion triggered by PMD1 is finished               */
  INTTB00_IRQn                  = 20,        /*!< 16bit TMRB0 compare match detection 0/ Over flow            */
  INTTB01_IRQn                  = 21,        /*!< 16bit TMRB0 compare match detection 1                       */
  INTTB10_IRQn                  = 22,        /*!< 16bit TMRB1 compare match detection 0/ Over flow            */
  INTTB11_IRQn                  = 23,        /*!< 16bit TMRB1 compare match detection 1                       */
  INTTB40_IRQn                  = 24,        /*!< 16bit TMRB4 compare match detection 0/ Over flow            */
  INTTB41_IRQn                  = 25,        /*!< 16bit TMRB4 compare match detection 1                       */
  INTTB50_IRQn                  = 26,        /*!< 16bit TMRB5 compare match detection 0/ Over flow            */
  INTTB51_IRQn                  = 27,        /*!< 16bit TMRB5 compare match detection 1                       */
  INTPMD1_IRQn                  = 29,        /*!< PMD1 PWM interrupt                                          */
  INTCAP00_IRQn                 = 30,        /*!< 16bit TMRB0 input capture 0                                 */
  INTCAP10_IRQn                 = 32,        /*!< 16bit TMRB1 input capture 0                                 */
  INTCAP40_IRQn                 = 34,        /*!< 16bit TMRB4 input capture 0                                 */
  INTCAP50_IRQn                 = 36,        /*!< 16bit TMRB5 input capture 0                                 */
  INT6_IRQn                     = 38,        /*!< Interrupt Pin (PE6/TB3IN//17pin or 19pin)                   */
  INT7_IRQn                     = 39,        /*!< Interrupt Pin (PE7/TB3OUT/18pin or 20pin)                   */
  INTADBCPA_IRQn                = 43,        /*!< ADCB conversion monitoring function interrupt A             */
  INTADBCPB_IRQn                = 45,        /*!< ADCB conversion monitoring function interrupt B             */
  INTTB20_IRQn                  = 46,        /*!< 16bit TMRB2 compare match detection 0/ Over flow            */
  INTTB21_IRQn                  = 47,        /*!< 16bit TMRB2 compare match detection 1                       */
  INTTB30_IRQn                  = 48,        /*!< 16bit TMRB3 compare match detection 0/ Over flow            */
  INTTB31_IRQn                  = 49,        /*!< 16bit TMRB3 compare match detection 1                       */
  INTCAP20_IRQn                 = 50,        /*!< 16bit TMRB2 input capture 0                                 */
  INTCAP21_IRQn                 = 51,        /*!< 16bit TMRB2 input capture 1                                 */
  INTCAP30_IRQn                 = 52,        /*!< 16bit TMRB3 input capture 0                                 */
  INTCAP31_IRQn                 = 53,        /*!< 16bit TMRB3 input capture 1                                 */
  INTADBSFT_IRQn                = 55,        /*!< ADC1 conversion started by software is finished             */
  INTADBTMR_IRQn                = 57,        /*!< ADC1 conversion triggered by timer is finished              */
  INTENC1_IRQn                  = 63,        /*!< Ender input1 interrupt                                      */
  INTRX3_IRQn                   = 64,        /*!< Serial reception (channel.3)                                */
  INTTX3_IRQn                   = 65,        /*!< Serial transmit (channel.3)                                 */
  INTTB60_IRQn                  = 66,        /*!< 16bit TMRB6 compare match detection 0 / Over flow           */
  INTTB61_IRQn                  = 67,        /*!< 16bit TMRB6 compare match detection 1                       */
  INTTB70_IRQn                  = 68,        /*!< 16bit TMRB7 compare match detection 0 / Over flow           */
  INTTB71_IRQn                  = 69,        /*!< 16bit TMRB7 compare match detection 1                       */
  INTCAP60_IRQn                 = 70,        /*!< 16bit TMRB6 input capture 0                                 */
  INTCAP61_IRQn                 = 71,        /*!< 16bit TMRB6 input capture 1                                 */
  INTCAP70_IRQn                 = 72,        /*!< 16bit TMRB7 input capture 0                                 */
  INTCAP71_IRQn                 = 73,        /*!< 16bit TMRB7 input capture 1                                 */
  INTC_IRQn                     = 74,        /*!< Interrupt Pin (PJ6/AINB9/74pin or 76 pin)                   */
  INTD_IRQn                     = 75,        /*!< Interrupt Pin (PJ7/AINB10/73pin or 75pin)                   */
  INTE_IRQn                     = 76,        /*!< Interrupt Pin (PK0/AINB11/72pin or 74pin)                   */
  INTF_IRQn                     = 77         /*!< Interrupt Pin (PK1/AINB12/71pin or 73pin)                   */
} IRQn_Type;

/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV              0x0200       /*!< Cortex-M3 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals            */
#include "system_TMPM374.h"                 /* TMPM374 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief General Purpose Input/Output Port (PA)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PA Register                                  */
  __IO uint32_t CR;                /*!< PA Control Register                          */
  __IO uint32_t FR1;               /*!< PA Function Register 1                       */
  __IO uint32_t FR2;               /*!< PA Function Register 2                       */
       uint32_t RESERVED0[6];
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
  __IO uint32_t DATA;              /*!< PB Register                                  */
  __IO uint32_t CR;                /*!< PB Control Register                          */
  __IO uint32_t FR1;               /*!< PB Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PA Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PB Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PB Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PB Input Enable Control Register             */
} TSB_PB_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PE)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PE Register                                  */
  __IO uint32_t CR;                /*!< PE Control Register                          */
  __IO uint32_t FR1;               /*!< PE Function Register 1                       */
  __IO uint32_t FR2;               /*!< PE Function Register 2                       */
       uint32_t RESERVED0[6];
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
  __IO uint32_t DATA;              /*!< PF Register                                  */
  __IO uint32_t CR;                /*!< PF Control Register                          */
  __IO uint32_t FR1;               /*!< PF Function Register 1                       */
  __IO uint32_t FR2;               /*!< PF Function Register 2                       */
  __IO uint32_t FR3;               /*!< PF Function Register 3                       */
       uint32_t RESERVED0[5];
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
  __IO uint32_t DATA;              /*!< PG Register                                  */
  __IO uint32_t CR;                /*!< PG Control Register                          */
  __IO uint32_t FR1;               /*!< PG Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PG Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PG Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PG Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PG Input Enable Control Register             */
} TSB_PG_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PI)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PI Register                                  */
  __IO uint32_t CR;                /*!< PI Control Register                          */
       uint32_t RESERVED0[8];
  __IO uint32_t OD;                /*!< PI Open Drain Control Register               */
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
  __IO uint32_t DATA;              /*!< PJ Register                                  */
  __IO uint32_t CR;                /*!< PJ Control Register                          */
  __IO uint32_t FR1;               /*!< PJ Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PJ Open Drain Control Register               */
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
  __IO uint32_t DATA;              /*!< PK Register                                  */
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
  * @brief General Purpose Input/Output Port (PM)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PM Register                                  */
  __IO uint32_t CR;                /*!< PM Control Register                          */
       uint32_t RESERVED0[8];
  __IO uint32_t OD;                /*!< PM Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PM Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PM Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PM Input Enable Control Register             */
} TSB_PM_TypeDef;

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
  * @brief Encoder Input (ENC)
  */
typedef struct
{
  __IO uint32_t TNCR;              /*!< Encoder Input Control Register               */
  __IO uint32_t RELOAD;            /*!< Encoder Counter Reload Register              */
  __IO uint32_t INT;               /*!< Encoder Compare Register                     */
  __IO uint32_t CNT;               /*!< Encoder Counter Register                     */
} TSB_EN_TypeDef;

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
  __IO uint32_t RFC;               /*!< SC RX FIFO Configuration Register            */
  __IO uint32_t TFC;               /*!< SC TX FIFO Configuration Register            */
  __I  uint32_t RST;               /*!< SC RX FIFO Status Register                   */
  __I  uint32_t TST;               /*!< SC TX FIFO Status Register                   */
  __IO uint32_t FCNF;              /*!< SC FIFO Configuration Register               */
} TSB_SC_TypeDef;

/**
  * @brief Analog-to-Digital Converter (AD)
  */
typedef struct
{
  __IO uint32_t CLK;               /*!< AD Conversion Clock Setting Register         */
  __IO uint32_t MOD0;              /*!< AD Mode Setting Register 0                   */
  __IO uint32_t MOD1;              /*!< AD Mode Setting Register 1                   */
  __I  uint32_t MOD2;              /*!< AD Mode Setting Register 2                   */
  __IO uint32_t CMPCR0;            /*!< AD Monitoring Setting Register 0             */
  __IO uint32_t CMPCR1;            /*!< AD Monitoring Setting Register 1             */
  __IO uint32_t CMP0;              /*!< AD Conversion Result Compare Register 0      */
  __IO uint32_t CMP1;              /*!< AD Conversion Result Compare Register 1      */
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
       uint32_t RESERVED0[6];
  __IO uint32_t PSEL6;             /*!< PMD Trigger ProgramNumber Select Register 6  */
  __IO uint32_t PSEL7;             /*!< PMD Trigger ProgramNumber Select Register 7  */
  __IO uint32_t PSEL8;             /*!< PMD Trigger ProgramNumber Select Register 8  */
  __IO uint32_t PSEL9;             /*!< PMD Trigger ProgramNumber Select Register 9  */
  __IO uint32_t PSEL10;            /*!< PMD Trigger ProgramNumber Select Register 10 */
  __IO uint32_t PSEL11;            /*!< PMD Trigger ProgramNumber Select Register 11 */
  __IO uint32_t PINTS0;            /*!< PMD Trigger Interrupt Select Register 0      */
  __IO uint32_t PINTS1;            /*!< PMD Trigger Interrupt Select Register 1      */
  __IO uint32_t PINTS2;            /*!< PMD Trigger Interrupt Select Register 2      */
  __IO uint32_t PINTS3;            /*!< PMD Trigger Interrupt Select Register 3      */
  __IO uint32_t PINTS4;            /*!< PMD Trigger Interrupt Select Register 4      */
  __IO uint32_t PINTS5;            /*!< PMD Trigger Interrupt Select Register 5      */
  __IO uint32_t PSET0;             /*!< PMD Trigger Program Register 0               */
  __IO uint32_t PSET1;             /*!< PMD Trigger Program Register 1               */
  __IO uint32_t PSET2;             /*!< PMD Trigger Program Register 2               */
  __IO uint32_t PSET3;             /*!< PMD Trigger Program Register 3               */
  __IO uint32_t PSET4;             /*!< PMD Trigger Program Register 4               */
  __IO uint32_t PSET5;             /*!< PMD Trigger Program Register 5               */
  __IO uint32_t TSET03;            /*!< Timer Trigger Program Register 03            */
  __IO uint32_t TSET47;            /*!< Timer Trigger Program Register 47            */
  __IO uint32_t TSET811;           /*!< Timer Trigger Program Register 811           */
  __IO uint32_t SSET03;            /*!< Software Trigger Program Register 03         */
  __IO uint32_t SSET47;            /*!< Software Trigger Program Register 47         */
  __IO uint32_t SSET811;           /*!< Software Trigger Program Register 811        */
  __IO uint32_t ASET03;            /*!< Constant Trigger Program Register 03         */
  __IO uint32_t ASET47;            /*!< Constant Trigger Program Register 47         */
  __IO uint32_t ASET811;           /*!< Constant Trigger Program Register 811        */
} TSB_AD_TypeDef;

/**
  * @brief Watchdog Timer (WD)
  */
typedef struct
{
  __IO uint32_t MOD;               /*!< WD Mode Register                             */
  __O  uint32_t CR;                /*!< WD Control Register                          */
} TSB_WD_TypeDef;

/**
  * @brief Clock Generator (CG)
  */
typedef struct
{
  __IO uint32_t SYSCR;             /*!< System Control Register                      */
  __IO uint32_t OSCCR;             /*!< Oscillation Control Register                 */
  __IO uint32_t STBYCR;            /*!< Standby Control Register                     */
  __IO uint32_t PLLSEL;            /*!< PLL Selection Register                       */
  __IO uint32_t CKSEL;             /*!< System Clock Selection Register              */
  __O  uint32_t ICRCG;             /*!< CG Interrupt Request Clear Register          */
       uint32_t RESERVED0;
  __IO uint32_t RSTFLG;            /*!< Reset Flag Register                          */
  __IO uint32_t IMCGA;             /*!< CG Interrupt Mode Control Register A         */
  __IO uint32_t IMCGB;             /*!< CG Interrupt Mode Control Register B         */
  __IO uint32_t IMCGC;             /*!< CG Interrupt Mode Control Register C         */
  __IO uint32_t IMCGD;             /*!< CG Interrupt Mode Control Register D         */
} TSB_CG_TypeDef;

/**
  * @brief Oscillation Frequency Detector (OFD)
  */
typedef struct
{
  __IO uint32_t CR1;               /*!< OFD Control Register 1                       */
  __IO uint32_t CR2;               /*!< OFD Control Register 2                       */
  __IO uint32_t MNPLLOFF;          /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MNPLLON;           /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MXPLLOFF;          /*!< OFD Higher Detection Frequency Setting Register*/
  __IO uint32_t MXPLLON;           /*!< OFD Higher Detection Frequency Setting Register*/
} TSB_OFD_TypeDef;

/**
  * @brief Power-On Reset Circuit (POR)
  */
typedef struct
{
  __IO uint32_t CR;                /*!< VD Control Register                          */
} TSB_VD_TypeDef;

/**
  * @brief Vector Engine (VE)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< VE enable/disable                            */
  __O  uint32_t CPURUNTRG;         /*!< CPU start trigger selection                  */
  __IO uint32_t TASKAPP;           /*!< Task selection                               */
  __IO uint32_t ACTSCH;            /*!< Operation schedule selection                 */
  __IO uint32_t REPTIME;           /*!< Schedule repeat count                        */
  __IO uint32_t TRGMODE;           /*!< Start trigger mode                           */
  __IO uint32_t ERRINTEN;          /*!< Error interrupt enable/disable               */
  __O  uint32_t COMPEND;           /*!< VE forced termination                        */
  __I  uint32_t ERRDET;            /*!< Error detection                              */
  __I  uint32_t SCHTASKRUN;        /*!< Schedule executing flag/executing task       */
       uint32_t RESERVED0;
  __IO uint32_t TMPREG0;           /*!< Temporary register                           */
  __IO uint32_t TMPREG1;           /*!< Temporary register                           */
  __IO uint32_t TMPREG2;           /*!< Temporary register                           */
  __IO uint32_t TMPREG3;           /*!< Temporary register                           */
  __IO uint32_t TMPREG4;           /*!< Temporary register                           */
  __IO uint32_t TMPREG5;           /*!< Temporary register                           */
       uint32_t RESERVED1[38];
  __IO uint32_t MCTLF1;            /*!< Status flags                                 */
  __IO uint32_t MODE1;             /*!< Task control mode                            */
  __IO uint32_t FMODE1;            /*!< Flow control                                 */
  __IO uint32_t TPWM1;             /*!< 0PWM period rate (PWM period [s] ¡Á maximum speed*1 ¡Á 2^16) */
  __IO uint32_t OMEGA1;            /*!< Rotation speed (speed [Hz]¡Â maximum speed *1¡ù1 ¡Á 2^15) */
  __IO uint32_t THETA1;            /*!< Motor phase (motor phase [deg]/360 ¡Á 2^16)   */
  __IO uint32_t IDREF1;            /*!< d-axis reference value (current [A] ¡Â maximum current*2 ¡Á 2^15) */
  __IO uint32_t IQREF1;            /*!< q-axis reference value (current [A] ¡Â maximum current *2 ¡Á 2^15) */
  __IO uint32_t VD1;               /*!< d-axis voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^31) */
  __IO uint32_t VQ1;               /*!< q-axis voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^31) */
  __IO uint32_t CIDKI1;            /*!< Integral coefficient for PI control of d-axis */
  __IO uint32_t CIDKP1;            /*!< Proportional coefficient for PI control of d-axis */
  __IO uint32_t CIQKI1;            /*!< Integral coefficient for PI control of q-axis */
  __IO uint32_t CIQKP1;            /*!< Proportional coefficient for PI control of q-axis */
  __IO uint32_t VDIH1;             /*!< Upper 32 bits of integral term (VDI ) of d-axis voltage */
  __IO uint32_t VDILH1;            /*!< Lower 32 bits of integral term (VDI) of d-axis voltage */
  __IO uint32_t VQIH1;             /*!< Upper 32 bits of integral term (VQI) of q-axis voltage */
  __IO uint32_t VQILH1;            /*!< Lower 32 bits of integral term (VQI) of q-axis voltage */
  __IO uint32_t FPWMCHG1;          /*!< Switching speed (for 2-phase modulation and shift PWM) */
  __IO uint32_t MDPRD1;            /*!< PWM period (to be set identically with PMD¡¯s PWM period) */
  __IO uint32_t MINPLS1;           /*!< Minimum pulse width                          */
  __IO uint32_t TRGCRC1;           /*!< Synchronizing trigger correction value       */
       uint32_t RESERVED2;
  __IO uint32_t COS1;              /*!< Cosine value at THETA for output conversion (Q15 data) */
  __IO uint32_t SIN1;              /*!< Sine value at THETA for output conversion (Q15 data) */
  __IO uint32_t COSM1;             /*!< Previous cosine value for input processing (Q15 data) */
  __IO uint32_t SINM1;             /*!< Previous sine value for input processing (Q15 data) */
  __IO uint32_t SECTOR1;           /*!< Sector information (0-11)                    */
  __IO uint32_t SECTORM1;          /*!< Previous sector information for input processing (0-11) */
  __IO uint32_t IAO1;              /*!< AD conversion result of a-phase zero-current *4 */
  __IO uint32_t IBO1;              /*!< AD conversion result of b-phase zero-current *4 */
  __IO uint32_t ICO1;              /*!< AD conversion result of c-phase zero-current *4 */
  __IO uint32_t IAADC1;            /*!< AD conversion result of a-phase current *4   */
  __IO uint32_t IBADC1;            /*!< AD conversion result of b-phase current *4   */
  __IO uint32_t ICADC1;            /*!< AD conversion result of c-phase current *4   */
  __IO uint32_t VDC1;              /*!< DC supply voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^15) */
  __IO uint32_t ID1;               /*!< d-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
  __IO uint32_t IQ1;               /*!< q-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
       uint32_t RESERVED3;
  __IO uint32_t TADC;              /*!< Common ADC conversion time (based on PWM clock) */
       uint32_t RESERVED4[8];
  __IO uint32_t VCMPU1;            /*!< PMD control: CMPU setting                    */
  __IO uint32_t VCMPV1;            /*!< PMD control: CMPV setting                    */
  __IO uint32_t VCMPW1;            /*!< PMD control: CMPW setting                    */
  __IO uint32_t OUTCR1;            /*!< PMD control: Output control (MDOUT)          */
  __IO uint32_t VTRGCMP01;         /*!< PMD control: TRGCMP0 setting                 */
  __IO uint32_t VTRGCMP11;         /*!< PMD control: TRGCMP1 setting                 */
  __IO uint32_t VTRGSEL1;          /*!< PMD control: Trigger selection               */
  __O  uint32_t EMGRS1;            /*!< PMD control: EMG return (EMGCR[EMGRS])       */
} TSB_VE_TypeDef;

/**
  * @brief 16-bit Multi-Purpose Timer (MPT-PMD)
  */
typedef struct
{
  __IO uint32_t MDEN;              /*!< PMD Enable Register                          */
  __IO uint32_t PORTMD;            /*!< Port Output Mode Register                    */
  __IO uint32_t MDCR;              /*!< PMD Control Register                         */
  __I  uint32_t CNTSTA;            /*!< PWM Counter Status Register                  */
  __I  uint32_t MDCNT;             /*!< PWM Counter Register                         */
  __IO uint32_t MDPRD;             /*!< PWM Period Register                          */
  __IO uint32_t CMPU;              /*!< PWM Compare Register                         */
  __IO uint32_t CMPV;              /*!< PWM Compare Register                         */
  __IO uint32_t CMPW;              /*!< PWM Compare Register                         */
  __IO uint32_t MODESEL;           /*!< PWM Mode Select Register                     */
  __IO uint32_t MDOUT;             /*!< PMD Output Control Register                  */
  __IO uint32_t MDPOT;             /*!< PMD Output Setting Register                  */
  __O  uint32_t EMGREL;            /*!< EMG Release Register                         */
  __IO uint32_t EMGCR;             /*!< EMG Control Register                         */
  __I  uint32_t EMGSTA;            /*!< EMG Status Register                          */
  __IO uint32_t OVVCR;             /*!< OVV Control Register                         */
  __I  uint32_t OVVSTA;            /*!< OVV Status Register                          */
  __IO uint32_t DTR;               /*!< Dead Time Register                           */
  __IO uint32_t TRGCMP0;           /*!< Trigger Compare Register 0                   */
  __IO uint32_t TRGCMP1;           /*!< Trigger Compare Register 1                   */
  __IO uint32_t TRGCMP2;           /*!< Trigger Compare Register 2                   */
  __IO uint32_t TRGCMP3;           /*!< Trigger Compare Register 3                   */
  __IO uint32_t TRGCR;             /*!< Trigger Control Register                     */
  __IO uint32_t TRGMD;             /*!< Trigger Output Mode Setting Register         */
  __IO uint32_t TRGSEL;            /*!< Trigger Output Select Register               */
} TSB_PMD_TypeDef;

/**
  * @brief Flash Control (FC)
  */
typedef struct
{
  __IO uint32_t SECBIT;            /*!< FC Security Bit Register                     */
       uint32_t RESERVED0[3];
  __I  uint32_t FLCS;              /*!< FC Register                                  */
} TSB_FC_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)


#define TSB_PA_BASE                (PERI_BASE  + 0x0000000UL)
#define TSB_PB_BASE                (PERI_BASE  + 0x0000040UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x0000100UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x0000140UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x0000180UL)
#define TSB_PI_BASE                (PERI_BASE  + 0x0000200UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x0000240UL)
#define TSB_PK_BASE                (PERI_BASE  + 0x0000280UL)
#define TSB_PM_BASE                (PERI_BASE  + 0x0000280UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x0010000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x0010040UL)
#define TSB_TB2_BASE               (PERI_BASE  + 0x0010080UL)
#define TSB_TB3_BASE               (PERI_BASE  + 0x00100C0UL)
#define TSB_TB4_BASE               (PERI_BASE  + 0x0010100UL)
#define TSB_TB5_BASE               (PERI_BASE  + 0x0010140UL)
#define TSB_TB6_BASE               (PERI_BASE  + 0x0010180UL)
#define TSB_TB7_BASE               (PERI_BASE  + 0x00101C0UL)
#define TSB_EN1_BASE               (PERI_BASE  + 0x0010500UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x0020080UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00200C0UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x0020140UL)
#define TSB_ADB_BASE               (PERI_BASE  + 0x0030200UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x0040000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x0040200UL)
#define TSB_OFD_BASE               (PERI_BASE  + 0x0040800UL)
#define TSB_VD_BASE                (PERI_BASE  + 0x0040900UL)
#define TSB_VE_BASE                (PERI_BASE  + 0x0050000UL)
#define TSB_PMD1_BASE              (PERI_BASE  + 0x0050480UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1FFF010UL)


/* Peripheral declaration */
#define TSB_PA                     ((     TSB_PA_TypeDef *)    TSB_PA_BASE)
#define TSB_PB                     ((     TSB_PB_TypeDef *)    TSB_PB_BASE)
#define TSB_PE                     ((     TSB_PE_TypeDef *)    TSB_PE_BASE)
#define TSB_PF                     ((     TSB_PF_TypeDef *)    TSB_PF_BASE)
#define TSB_PG                     ((     TSB_PG_TypeDef *)    TSB_PG_BASE)
#define TSB_PI                     ((     TSB_PI_TypeDef *)    TSB_PI_BASE)
#define TSB_PJ                     ((     TSB_PJ_TypeDef *)    TSB_PJ_BASE)
#define TSB_PK                     ((     TSB_PK_TypeDef *)    TSB_PK_BASE)
#define TSB_PM                     ((     TSB_PM_TypeDef *)    TSB_PM_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_TB2                    ((     TSB_TB_TypeDef *)   TSB_TB2_BASE)
#define TSB_TB3                    ((     TSB_TB_TypeDef *)   TSB_TB3_BASE)
#define TSB_TB4                    ((     TSB_TB_TypeDef *)   TSB_TB4_BASE)
#define TSB_TB5                    ((     TSB_TB_TypeDef *)   TSB_TB5_BASE)
#define TSB_TB6                    ((     TSB_TB_TypeDef *)   TSB_TB6_BASE)
#define TSB_TB7                    ((     TSB_TB_TypeDef *)   TSB_TB7_BASE)
#define TSB_EN1                    ((     TSB_EN_TypeDef *)   TSB_EN1_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_ADB                    ((     TSB_AD_TypeDef *)   TSB_ADB_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)
#define TSB_OFD                    ((    TSB_OFD_TypeDef *)   TSB_OFD_BASE)
#define TSB_VD                     ((     TSB_VD_TypeDef *)    TSB_VD_BASE)
#define TSB_VE                     ((     TSB_VE_TypeDef *)    TSB_VE_BASE)
#define TSB_PMD1                   ((    TSB_PMD_TypeDef *)  TSB_PMD1_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)


/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/* General Purpose Input/Output Port (PA) */
#define TSB_PA_DATA_PA4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,4)))
#define TSB_PA_DATA_PA5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,5)))
#define TSB_PA_DATA_PA6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,6)))
#define TSB_PA_CR_PA4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,4)))
#define TSB_PA_CR_PA5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,5)))
#define TSB_PA_CR_PA6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,6)))
#define TSB_PA_FR1_PA4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,4)))
#define TSB_PA_FR1_PA5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,5)))
#define TSB_PA_FR1_PA6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,6)))
#define TSB_PA_FR2_PA4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,4)))
#define TSB_PA_FR2_PA5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,5)))
#define TSB_PA_FR2_PA6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,6)))
#define TSB_PA_OD_PA4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,4)))
#define TSB_PA_OD_PA5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,5)))
#define TSB_PA_OD_PA6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,6)))
#define TSB_PA_PUP_PA4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,4)))
#define TSB_PA_PUP_PA5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,5)))
#define TSB_PA_PUP_PA6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,6)))
#define TSB_PA_PDN_PA4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,4)))
#define TSB_PA_PDN_PA5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,5)))
#define TSB_PA_PDN_PA6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,6)))
#define TSB_PA_IE_PA4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,4)))
#define TSB_PA_IE_PA5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,5)))
#define TSB_PA_IE_PA6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,6)))


/* General Purpose Input/Output Port (PB) */
#define TSB_PB_DATA_PB3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,3)))
#define TSB_PB_DATA_PB4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,4)))
#define TSB_PB_DATA_PB5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,5)))
#define TSB_PB_DATA_PB6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,6)))
#define TSB_PB_CR_PB3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,3)))
#define TSB_PB_CR_PB4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,4)))
#define TSB_PB_CR_PB5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,5)))
#define TSB_PB_CR_PB6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,6)))
#define TSB_PB_FR1_PB3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,3)))
#define TSB_PB_FR1_PB4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,4)))
#define TSB_PB_FR1_PB5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,5)))
#define TSB_PB_FR1_PB6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,6)))
#define TSB_PB_OD_PB3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,3)))
#define TSB_PB_OD_PB4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,4)))
#define TSB_PB_OD_PB5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,5)))
#define TSB_PB_OD_PB6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,6)))
#define TSB_PB_PUP_PB3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,4)))
#define TSB_PB_PUP_PB5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PDN_PB3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,3)))
#define TSB_PB_PDN_PB4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,4)))
#define TSB_PB_PDN_PB5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,5)))
#define TSB_PB_PDN_PB6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,6)))
#define TSB_PB_IE_PB3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))



/* General Purpose Input/Output Port (PE) */
#define TSB_PE_DATA_PE0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,0)))
#define TSB_PE_DATA_PE1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,1)))
#define TSB_PE_DATA_PE2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,2)))
#define TSB_PE_DATA_PE4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,4)))
#define TSB_PE_DATA_PE6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,6)))
#define TSB_PE_DATA_PE7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,7)))
#define TSB_PE_CR_PE0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,0)))
#define TSB_PE_CR_PE1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,1)))
#define TSB_PE_CR_PE2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,2)))
#define TSB_PE_CR_PE4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,4)))
#define TSB_PE_CR_PE6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,6)))
#define TSB_PE_CR_PE7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,7)))
#define TSB_PE_FR1_PE0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,0)))
#define TSB_PE_FR1_PE1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,1)))
#define TSB_PE_FR1_PE2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,2)))
#define TSB_PE_FR1_PE4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,4)))
#define TSB_PE_FR1_PE6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,6)))
#define TSB_PE_FR1_PE7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,7)))
#define TSB_PE_FR2_PE2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_FR2_PE4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,4)))
#define TSB_PE_FR2_PE6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,6)))
#define TSB_PE_FR2_PE7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,7)))
#define TSB_PE_OD_PE0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,0)))
#define TSB_PE_OD_PE1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,1)))
#define TSB_PE_OD_PE2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,2)))
#define TSB_PE_OD_PE4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,4)))
#define TSB_PE_OD_PE6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,6)))
#define TSB_PE_OD_PE7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,7)))
#define TSB_PE_PUP_PE0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,0)))
#define TSB_PE_PUP_PE1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,1)))
#define TSB_PE_PUP_PE2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,2)))
#define TSB_PE_PUP_PE4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,4)))
#define TSB_PE_PUP_PE6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,6)))
#define TSB_PE_PUP_PE7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,7)))
#define TSB_PE_PDN_PE0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,0)))
#define TSB_PE_PDN_PE1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,1)))
#define TSB_PE_PDN_PE2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,2)))
#define TSB_PE_PDN_PE4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,4)))
#define TSB_PE_PDN_PE6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,6)))
#define TSB_PE_PDN_PE7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,7)))
#define TSB_PE_IE_PE0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,0)))
#define TSB_PE_IE_PE1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,1)))
#define TSB_PE_IE_PE2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,2)))
#define TSB_PE_IE_PE4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,4)))
#define TSB_PE_IE_PE6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,6)))
#define TSB_PE_IE_PE7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,7)))


/* General Purpose Input/Output Port (PF) */
#define TSB_PF_DATA_PF0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,0)))
#define TSB_PF_DATA_PF2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,2)))
#define TSB_PF_DATA_PF3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,3)))
#define TSB_PF_DATA_PF4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,4)))
#define TSB_PF_CR_PF0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,2)))
#define TSB_PF_CR_PF3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,3)))
#define TSB_PF_CR_PF4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,4)))
#define TSB_PF_FR1_PF0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,0)))
#define TSB_PF_FR1_PF2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,2)))
#define TSB_PF_FR1_PF3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,3)))
#define TSB_PF_FR1_PF4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,4)))
#define TSB_PF_FR2_PF2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,2)))
#define TSB_PF_FR2_PF3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,3)))
#define TSB_PF_FR2_PF4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,4)))
#define TSB_PF_FR3_PF2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,2)))
#define TSB_PF_OD_PF0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,2)))
#define TSB_PF_OD_PF3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,3)))
#define TSB_PF_OD_PF4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,4)))
#define TSB_PF_PUP_PF0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,2)))
#define TSB_PF_PUP_PF3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,3)))
#define TSB_PF_PUP_PF4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,4)))
#define TSB_PF_PDN_PF0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,0)))
#define TSB_PF_PDN_PF2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,2)))
#define TSB_PF_PDN_PF3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,3)))
#define TSB_PF_PDN_PF4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,4)))
#define TSB_PF_IE_PF0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,2)))
#define TSB_PF_IE_PF3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,3)))
#define TSB_PF_IE_PF4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,4)))


/* General Purpose Input/Output Port (PG) */
#define TSB_PG_DATA_PG0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,0)))
#define TSB_PG_DATA_PG1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,1)))
#define TSB_PG_DATA_PG2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,2)))
#define TSB_PG_DATA_PG3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,3)))
#define TSB_PG_DATA_PG4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,4)))
#define TSB_PG_DATA_PG5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,5)))
#define TSB_PG_DATA_PG6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,6)))
#define TSB_PG_DATA_PG7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,7)))
#define TSB_PG_CR_PG0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,0)))
#define TSB_PG_CR_PG1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,1)))
#define TSB_PG_CR_PG2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,2)))
#define TSB_PG_CR_PG3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,3)))
#define TSB_PG_CR_PG4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,4)))
#define TSB_PG_CR_PG5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,5)))
#define TSB_PG_CR_PG6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,6)))
#define TSB_PG_CR_PG7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,7)))
#define TSB_PG_FR1_PG0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,0)))
#define TSB_PG_FR1_PG1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,1)))
#define TSB_PG_FR1_PG2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,2)))
#define TSB_PG_FR1_PG3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,3)))
#define TSB_PG_FR1_PG4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,4)))
#define TSB_PG_FR1_PG5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,5)))
#define TSB_PG_FR1_PG6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,6)))
#define TSB_PG_FR1_PG7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,7)))
#define TSB_PG_OD_PG0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,0)))
#define TSB_PG_OD_PG1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,1)))
#define TSB_PG_OD_PG2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,2)))
#define TSB_PG_OD_PG3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,3)))
#define TSB_PG_OD_PG4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,4)))
#define TSB_PG_OD_PG5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,5)))
#define TSB_PG_OD_PG6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,6)))
#define TSB_PG_OD_PG7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,7)))
#define TSB_PG_PUP_PG0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,0)))
#define TSB_PG_PUP_PG1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,1)))
#define TSB_PG_PUP_PG2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,2)))
#define TSB_PG_PUP_PG3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,3)))
#define TSB_PG_PUP_PG4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,4)))
#define TSB_PG_PUP_PG5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,5)))
#define TSB_PG_PUP_PG6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,6)))
#define TSB_PG_PUP_PG7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,7)))
#define TSB_PG_PDN_PG0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,0)))
#define TSB_PG_PDN_PG1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,1)))
#define TSB_PG_PDN_PG2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,2)))
#define TSB_PG_PDN_PG3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,3)))
#define TSB_PG_PDN_PG4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,4)))
#define TSB_PG_PDN_PG5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,5)))
#define TSB_PG_PDN_PG6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,6)))
#define TSB_PG_PDN_PG7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,7)))
#define TSB_PG_IE_PG0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,0)))
#define TSB_PG_IE_PG1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,1)))
#define TSB_PG_IE_PG2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,2)))
#define TSB_PG_IE_PG3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,3)))
#define TSB_PG_IE_PG4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,4)))
#define TSB_PG_IE_PG5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,5)))
#define TSB_PG_IE_PG6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,6)))
#define TSB_PG_IE_PG7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,7)))


/* General Purpose Input/Output Port (PI) */
#define TSB_PI_DATA_PI3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,3)))
#define TSB_PI_CR_PI3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_OD_PI3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,3)))
#define TSB_PI_PUP_PI3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,3)))
#define TSB_PI_PDN_PI3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,3)))
#define TSB_PI_IE_PI3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))


/* General Purpose Input/Output Port (PJ) */
#define TSB_PJ_DATA_PJ0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,6)))
#define TSB_PJ_DATA_PJ7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,7)))
#define TSB_PJ_CR_PJ0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,0)))
#define TSB_PJ_CR_PJ6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,6)))
#define TSB_PJ_CR_PJ7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,7)))
#define TSB_PJ_FR1_PJ6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,6)))
#define TSB_PJ_FR1_PJ7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,7)))
#define TSB_PJ_OD_PJ0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,0)))
#define TSB_PJ_OD_PJ6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,6)))
#define TSB_PJ_OD_PJ7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,7)))
#define TSB_PJ_PUP_PJ0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,6)))
#define TSB_PJ_PUP_PJ7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,7)))
#define TSB_PJ_PDN_PJ0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,0)))
#define TSB_PJ_PDN_PJ6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,6)))
#define TSB_PJ_PDN_PJ7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,7)))
#define TSB_PJ_IE_PJ0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,6)))
#define TSB_PJ_IE_PJ7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,7)))


/* General Purpose Input/Output Port (PK) */
#define TSB_PK_DATA_PK0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,0)))
#define TSB_PK_DATA_PK1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,1)))
#define TSB_PK_CR_PK0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,0)))
#define TSB_PK_CR_PK1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,1)))
#define TSB_PK_FR1_PK0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,0)))
#define TSB_PK_FR1_PK1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,1)))
#define TSB_PK_OD_PK0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,0)))
#define TSB_PK_OD_PK1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,1)))
#define TSB_PK_PUP_PK0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,0)))
#define TSB_PK_PUP_PK1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,1)))
#define TSB_PK_PDN_PK0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,0)))
#define TSB_PK_PDN_PK1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,1)))
#define TSB_PK_IE_PK0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,0)))
#define TSB_PK_IE_PK1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,1)))


/* General Purpose Input/Output Port (PM) */
#define TSB_PM_DATA_PM0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,0)))
#define TSB_PM_DATA_PM1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,1)))
#define TSB_PM_CR_PM0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,0)))
#define TSB_PM_CR_PM1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,1)))
#define TSB_PM_OD_PM0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,0)))
#define TSB_PM_OD_PM1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,1)))
#define TSB_PM_PUP_PM0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,0)))
#define TSB_PM_PUP_PM1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,1)))
#define TSB_PM_PDN_PM0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,0)))
#define TSB_PM_PDN_PM1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,1)))
#define TSB_PM_IE_PM0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,0)))
#define TSB_PM_IE_PM1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,1)))


/* 16-bit Timer/Event Counter (TB) */
#define TSB_TB0_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,6)))
#define TSB_TB0_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,0)))
#define TSB_TB0_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,1)))
#define TSB_TB0_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,3)))
#define TSB_TB0_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,7)))
#define TSB_TB0_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,2)))
#define TSB_TB0_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,5)))
#define TSB_TB0_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,6)))
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
#define TSB_TB1_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,7)))
#define TSB_TB1_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,2)))
#define TSB_TB1_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,5)))
#define TSB_TB1_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,6)))
#define TSB_TB1_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,2)))
#define TSB_TB1_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,3)))
#define TSB_TB1_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,4)))
#define TSB_TB1_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,5)))
#define TSB_TB1_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,0)))
#define TSB_TB1_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,1)))
#define TSB_TB1_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,2)))

#define TSB_TB2_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,6)))
#define TSB_TB2_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,7)))
#define TSB_TB2_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,0)))
#define TSB_TB2_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,2)))
#define TSB_TB2_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,0)))
#define TSB_TB2_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,1)))
#define TSB_TB2_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,3)))
#define TSB_TB2_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,7)))
#define TSB_TB2_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,2)))
#define TSB_TB2_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,5)))
#define TSB_TB2_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,6)))
#define TSB_TB2_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,2)))
#define TSB_TB2_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,3)))
#define TSB_TB2_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,4)))
#define TSB_TB2_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,5)))
#define TSB_TB2_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,0)))
#define TSB_TB2_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,1)))
#define TSB_TB2_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,2)))

#define TSB_TB3_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,6)))
#define TSB_TB3_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,7)))
#define TSB_TB3_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,0)))
#define TSB_TB3_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,2)))
#define TSB_TB3_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,0)))
#define TSB_TB3_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,1)))
#define TSB_TB3_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,3)))
#define TSB_TB3_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,7)))
#define TSB_TB3_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,2)))
#define TSB_TB3_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,5)))
#define TSB_TB3_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,6)))
#define TSB_TB3_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,2)))
#define TSB_TB3_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,3)))
#define TSB_TB3_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,4)))
#define TSB_TB3_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,5)))
#define TSB_TB3_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,0)))
#define TSB_TB3_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,1)))
#define TSB_TB3_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,2)))

#define TSB_TB4_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,6)))
#define TSB_TB4_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,7)))
#define TSB_TB4_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,0)))
#define TSB_TB4_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,2)))
#define TSB_TB4_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,0)))
#define TSB_TB4_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,1)))
#define TSB_TB4_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,3)))
#define TSB_TB4_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,7)))
#define TSB_TB4_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,2)))
#define TSB_TB4_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,5)))
#define TSB_TB4_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,6)))
#define TSB_TB4_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,2)))
#define TSB_TB4_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,3)))
#define TSB_TB4_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,4)))
#define TSB_TB4_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,5)))
#define TSB_TB4_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,0)))
#define TSB_TB4_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,1)))
#define TSB_TB4_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,2)))

#define TSB_TB5_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,6)))
#define TSB_TB5_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,7)))
#define TSB_TB5_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,0)))
#define TSB_TB5_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,2)))
#define TSB_TB5_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,0)))
#define TSB_TB5_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,1)))
#define TSB_TB5_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,3)))
#define TSB_TB5_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,7)))
#define TSB_TB5_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,2)))
#define TSB_TB5_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,5)))
#define TSB_TB5_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,6)))
#define TSB_TB5_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,2)))
#define TSB_TB5_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,3)))
#define TSB_TB5_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,4)))
#define TSB_TB5_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,5)))
#define TSB_TB5_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,0)))
#define TSB_TB5_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,1)))
#define TSB_TB5_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,2)))

#define TSB_TB6_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,6)))
#define TSB_TB6_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,7)))
#define TSB_TB6_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,0)))
#define TSB_TB6_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,2)))
#define TSB_TB6_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,0)))
#define TSB_TB6_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,1)))
#define TSB_TB6_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,3)))
#define TSB_TB6_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,7)))
#define TSB_TB6_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,2)))
#define TSB_TB6_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,5)))
#define TSB_TB6_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,6)))
#define TSB_TB6_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,2)))
#define TSB_TB6_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,3)))
#define TSB_TB6_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,4)))
#define TSB_TB6_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,5)))
#define TSB_TB6_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,0)))
#define TSB_TB6_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,1)))
#define TSB_TB6_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,2)))

#define TSB_TB7_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,6)))
#define TSB_TB7_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,7)))
#define TSB_TB7_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,0)))
#define TSB_TB7_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,2)))
#define TSB_TB7_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,0)))
#define TSB_TB7_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,1)))
#define TSB_TB7_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,3)))
#define TSB_TB7_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,7)))
#define TSB_TB7_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,2)))
#define TSB_TB7_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,5)))
#define TSB_TB7_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,6)))
#define TSB_TB7_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,2)))
#define TSB_TB7_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,3)))
#define TSB_TB7_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,4)))
#define TSB_TB7_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,5)))
#define TSB_TB7_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,0)))
#define TSB_TB7_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,1)))
#define TSB_TB7_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,2)))


/* Encoder Input (ENC) */
#define TSB_EN1_TNCR_INTEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,3)))
#define TSB_EN1_TNCR_ENRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,6)))
#define TSB_EN1_TNCR_ZEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,7)))
#define TSB_EN1_TNCR_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,8)))
#define TSB_EN1_TNCR_ZESEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,9)))
#define TSB_EN1_TNCR_ENCLR                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,10)))
#define TSB_EN1_TNCR_SFTCAP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,11)))
#define TSB_EN1_TNCR_ZDET                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,12)))
#define TSB_EN1_TNCR_UD                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,13)))
#define TSB_EN1_TNCR_REVERR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,14)))
#define TSB_EN1_TNCR_CMP                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,15)))
#define TSB_EN1_TNCR_P3EN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,16)))


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
#define TSB_SC0_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,6)))
#define TSB_SC0_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,7)))
#define TSB_SC0_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,6)))
#define TSB_SC0_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,7)))
#define TSB_SC0_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->RST,7)))
#define TSB_SC0_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->TST,7)))
#define TSB_SC0_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,0)))
#define TSB_SC0_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,1)))
#define TSB_SC0_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,2)))
#define TSB_SC0_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,3)))
#define TSB_SC0_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,4)))

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
#define TSB_SC1_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,6)))
#define TSB_SC1_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,7)))
#define TSB_SC1_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,6)))
#define TSB_SC1_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,7)))
#define TSB_SC1_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->RST,7)))
#define TSB_SC1_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->TST,7)))
#define TSB_SC1_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,0)))
#define TSB_SC1_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,1)))
#define TSB_SC1_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,2)))
#define TSB_SC1_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,3)))
#define TSB_SC1_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,4)))

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
#define TSB_SC3_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->RFC,6)))
#define TSB_SC3_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC3->RFC,7)))
#define TSB_SC3_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->TFC,6)))
#define TSB_SC3_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC3->TFC,7)))
#define TSB_SC3_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->RST,7)))
#define TSB_SC3_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->TST,7)))
#define TSB_SC3_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,0)))
#define TSB_SC3_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,1)))
#define TSB_SC3_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,2)))
#define TSB_SC3_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,3)))
#define TSB_SC3_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,4)))


/* Analog-to-Digital Converter (AD) */
#define TSB_ADB_MOD0_ADSS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD0,0)))
#define TSB_ADB_MOD1_ADAS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,0)))
#define TSB_ADB_MOD1_ADEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,7)))
#define TSB_ADB_MOD2_ADBFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,0)))
#define TSB_ADB_MOD2_ADSFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,1)))
#define TSB_ADB_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,4)))
#define TSB_ADB_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,7)))
#define TSB_ADB_CMPCR1_ADBIG1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,4)))
#define TSB_ADB_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,7)))
#define TSB_ADB_PSEL6_PENS6                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL6,7)))
#define TSB_ADB_PSEL7_PENS7                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL7,7)))
#define TSB_ADB_PSEL8_PENS8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL8,7)))
#define TSB_ADB_PSEL9_PENS9                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL9,7)))
#define TSB_ADB_PSEL10_PENS10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL10,7)))
#define TSB_ADB_PSEL11_PENS11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL11,7)))
#define TSB_ADB_PSET0_ENSP00                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,7)))
#define TSB_ADB_PSET0_ENSP01                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,15)))
#define TSB_ADB_PSET0_ENSP02                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,23)))
#define TSB_ADB_PSET0_ENSP03                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,31)))
#define TSB_ADB_PSET1_ENSP10                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,7)))
#define TSB_ADB_PSET1_ENSP11                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,15)))
#define TSB_ADB_PSET1_ENSP12                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,23)))
#define TSB_ADB_PSET1_ENSP13                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,31)))
#define TSB_ADB_PSET2_ENSP20                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,7)))
#define TSB_ADB_PSET2_ENSP21                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,15)))
#define TSB_ADB_PSET2_ENSP22                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,23)))
#define TSB_ADB_PSET2_ENSP23                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,31)))
#define TSB_ADB_PSET3_ENSP30                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,7)))
#define TSB_ADB_PSET3_ENSP31                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,15)))
#define TSB_ADB_PSET3_ENSP32                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,23)))
#define TSB_ADB_PSET3_ENSP33                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,31)))
#define TSB_ADB_PSET4_ENSP40                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,7)))
#define TSB_ADB_PSET4_ENSP41                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,15)))
#define TSB_ADB_PSET4_ENSP42                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,23)))
#define TSB_ADB_PSET4_ENSP43                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,31)))
#define TSB_ADB_PSET5_ENSP50                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,7)))
#define TSB_ADB_PSET5_ENSP51                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,15)))
#define TSB_ADB_PSET5_ENSP52                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,23)))
#define TSB_ADB_PSET5_ENSP53                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,31)))
#define TSB_ADB_TSET03_ENST0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,7)))
#define TSB_ADB_TSET03_ENST1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,15)))
#define TSB_ADB_TSET03_ENST2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,23)))
#define TSB_ADB_TSET03_ENST3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,31)))
#define TSB_ADB_TSET47_ENST4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,7)))
#define TSB_ADB_TSET47_ENST5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,15)))
#define TSB_ADB_TSET47_ENST6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,23)))
#define TSB_ADB_TSET47_ENST7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,31)))
#define TSB_ADB_TSET811_ENST8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,7)))
#define TSB_ADB_TSET811_ENST9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,15)))
#define TSB_ADB_TSET811_ENST10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,23)))
#define TSB_ADB_TSET811_ENST11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,31)))
#define TSB_ADB_SSET03_ENSS0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,7)))
#define TSB_ADB_SSET03_ENSS1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,15)))
#define TSB_ADB_SSET03_ENSS2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,23)))
#define TSB_ADB_SSET03_ENSS3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,31)))
#define TSB_ADB_SSET47_ENSS4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,7)))
#define TSB_ADB_SSET47_ENSS5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,15)))
#define TSB_ADB_SSET47_ENSS6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,23)))
#define TSB_ADB_SSET47_ENSS7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,31)))
#define TSB_ADB_SSET811_ENSS8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,7)))
#define TSB_ADB_SSET811_ENSS9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,15)))
#define TSB_ADB_SSET811_ENSS10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,23)))
#define TSB_ADB_SSET811_ENSS11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,31)))
#define TSB_ADB_ASET03_ENSA0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,7)))
#define TSB_ADB_ASET03_ENSA1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,15)))
#define TSB_ADB_ASET03_ENSA2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,23)))
#define TSB_ADB_ASET03_ENSA3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,31)))
#define TSB_ADB_ASET47_ENSA4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,7)))
#define TSB_ADB_ASET47_ENSA5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,15)))
#define TSB_ADB_ASET47_ENSA6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,23)))
#define TSB_ADB_ASET47_ENSA7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,31)))
#define TSB_ADB_ASET811_ENSA8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,7)))
#define TSB_ADB_ASET811_ENSA9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,15)))
#define TSB_ADB_ASET811_ENSA10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,23)))
#define TSB_ADB_ASET811_ENSA11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,31)))


/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_I2WDT                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,2)))
#define TSB_WD_MOD_WDTE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))


/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FPSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,12)))
#define TSB_CG_OSCCR_WUEON                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_PLLON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,2)))
#define TSB_CG_OSCCR_WUPSEL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XEN2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,16)))
#define TSB_CG_OSCCR_OSCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,17)))
#define TSB_CG_OSCCR_HOSCON                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,18)))
#define TSB_CG_OSCCR_WUPSEL2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,19)))
#define TSB_CG_STBYCR_RXEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,8)))
#define TSB_CG_STBYCR_DRVE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,16)))
#define TSB_CG_PLLSEL_PLLSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,0)))
#define TSB_CG_CKSEL_SYSCKFLG                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,0)))
#define TSB_CG_CKSEL_SYSCK                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,1)))
#define TSB_CG_RSTFLG_PONRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,0)))
#define TSB_CG_RSTFLG_PINRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,1)))
#define TSB_CG_RSTFLG_WDTRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,2)))
#define TSB_CG_RSTFLG_VLTDRSTF                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,3)))
#define TSB_CG_RSTFLG_DBGRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,4)))
#define TSB_CG_RSTFLG_OFDRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,5)))
#define TSB_CG_IMCGA_INT3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))
#define TSB_CG_IMCGB_INT6EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,16)))
#define TSB_CG_IMCGB_INT7EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,24)))
#define TSB_CG_IMCGC_INT8EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,0)))
#define TSB_CG_IMCGD_INTCEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,0)))
#define TSB_CG_IMCGD_INTDEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,8)))
#define TSB_CG_IMCGD_INTEEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,16)))
#define TSB_CG_IMCGD_INTFEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,24)))



/* Power-On Reset Circuit (POR) */
#define TSB_VD_CR_VDEN                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_VD->CR,0)))


/* Vector Engine (VE) */
#define TSB_VE_EN_VEEN                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EN,0)))
#define TSB_VE_EN_VEIDLEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EN,1)))
#define TSB_VE_ERRINTEN_VERRENB                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->ERRINTEN,1)))
#define TSB_VE_SCHTASKRUN_VRSCHB                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_VE->SCHTASKRUN,5)))
#define TSB_VE_MCTLF1_LAVF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1,0)))
#define TSB_VE_MCTLF1_LAVFM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1,1)))
#define TSB_VE_MCTLF1_LVTF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1,2)))
#define TSB_VE_MCTLF1_PLSLF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1,4)))
#define TSB_VE_MCTLF1_PLSLFM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1,5)))
#define TSB_VE_MODE1_PVIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE1,0)))
#define TSB_VE_MODE1_ZIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE1,1)))
#define TSB_VE_FMODE1_C2PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,0)))
#define TSB_VE_FMODE1_SPWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,1)))
#define TSB_VE_FMODE1_MREGDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,9)))
#define TSB_VE_OUTCR1_UPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,6)))
#define TSB_VE_OUTCR1_VPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,7)))
#define TSB_VE_OUTCR1_WPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,8)))
#define TSB_VE_EMGRS1_EMGRS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EMGRS1,0)))


/* 16-bit Multi-Purpose Timer (MPT-PMD) */
#define TSB_PMD1_MDEN_PWMEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDEN,0)))
#define TSB_PMD1_MDCR_PWMMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,0)))
#define TSB_PMD1_MDCR_PINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,3)))
#define TSB_PMD1_MDCR_DTYMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,4)))
#define TSB_PMD1_MDCR_SYNTMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,5)))
#define TSB_PMD1_MDCR_PWMCK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,6)))
#define TSB_PMD1_CNTSTA_UPDWN                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->CNTSTA,0)))
#define TSB_PMD1_MODESEL_MDSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,0)))
#define TSB_PMD1_MDOUT_UPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,8)))
#define TSB_PMD1_MDOUT_VPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,9)))
#define TSB_PMD1_MDOUT_WPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,10)))
#define TSB_PMD1_MDPOT_POLL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDPOT,2)))
#define TSB_PMD1_MDPOT_POLH                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDPOT,3)))
#define TSB_PMD1_EMGCR_EMGEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,0)))
#define TSB_PMD1_EMGCR_EMGRS                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,1)))
#define TSB_PMD1_EMGCR_INHEN                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,5)))
#define TSB_PMD1_EMGSTA_EMGST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGSTA,0)))
#define TSB_PMD1_EMGSTA_EMGI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGSTA,1)))
#define TSB_PMD1_OVVCR_OVVEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,0)))
#define TSB_PMD1_OVVCR_OVVRS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,1)))
#define TSB_PMD1_OVVCR_OVVISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,2)))
#define TSB_PMD1_OVVCR_ADIN0EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,5)))
#define TSB_PMD1_OVVCR_ADIN1EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,6)))
#define TSB_PMD1_OVVSTA_OVVST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVSTA,0)))
#define TSB_PMD1_OVVSTA_OVVISEL                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVSTA,1)))
#define TSB_PMD1_TRGCR_TRG0BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,3)))
#define TSB_PMD1_TRGCR_TRG1BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,7)))
#define TSB_PMD1_TRGCR_TRG2BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,11)))
#define TSB_PMD1_TRGCR_TRG3BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,15)))
#define TSB_PMD1_TRGMD_EMGTGE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGMD,0)))
#define TSB_PMD1_TRGMD_TRGOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGMD,1)))


/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM374_H__ */

/** @} */ /* End of group TMPM374 */
/** @} */ /* End of group TOSHIBA_TX03_MICROCONTROLLER */
