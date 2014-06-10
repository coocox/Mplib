/**
 *******************************************************************************
 * @file    TMPM370.h
 * @brief   CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM370' Device Series
 * @version V2.2.0
 * @date    2011/04/15
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

/** @addtogroup TMPM370
  * @{
  */

#ifndef __TMPM370_H__
#define __TMPM370_H__

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

/******  TMPM370 Specific Interrupt Numbers *******************************************************************/
  INT0_IRQn                     = 0,         /*!< Interrupt Pin (PH0/AINA0/96pin or 98pin)                    */
  INT1_IRQn                     = 1,         /*!< Interrupt Pin (PH1/AINA1/95pin or 97pin)                    */
  INT2_IRQn                     = 2,         /*!< Interrupt Pin (PH2/AINA2/94pin or 96pin)                    */
  INT3_IRQn                     = 3,         /*!< Interrupt Pin (PA0/TB0IN/2pin or 4pin)                      */
  INT4_IRQn                     = 4,         /*!< Interrupt Pin (PA2/TB1IN/4pin or 6pin)                      */
  INT5_IRQn                     = 5,         /*!< Interrupt Pin (PE4/TB2IN//15pin or 17pin)                   */
  INTRX0_IRQn                   = 6,         /*!< Serial reception (channel.0)                                */
  INTTX0_IRQn                   = 7,         /*!< Serial transmit (channel.0)                                 */
  INTRX1_IRQn                   = 8,         /*!< Serial reception (channel.1)                                */
  INTTX1_IRQn                   = 9,         /*!< Serial transmit (channel.1)                                 */
  INTVCNA_IRQn                  = 10,        /*!< Vector Engine interrupt A                                   */
  INTVCNB_IRQn                  = 11,        /*!< Vector Engine interrupt B                                   */
  INTEMG0_IRQn                  = 12,        /*!< PMD0 EMG interrupt                                          */
  INTEMG1_IRQn                  = 13,        /*!< PMD1 EMG interrupt                                          */
  INTOVV0_IRQn                  = 14,        /*!< PMD0 OVV interrupt                                          */
  INTOVV1_IRQn                  = 15,        /*!< PMD1 OVV interrupt                                          */
  INTADAPDA_IRQn                = 16,        /*!< ADCA conversion triggered by PMD0 is finished               */
  INTADBPDA_IRQn                = 17,        /*!< ADCB conversion triggered by PMD0 is finished               */
  INTADAPDB_IRQn                = 18,        /*!< ADCA conversion triggered by PMD1 is finished               */
  INTADBPDB_IRQn                = 19,        /*!< ADCB conversion triggered by PMD1 is finished               */
  INTTB00_IRQn                  = 20,        /*!< 16bit TMRB0 compare match detection 0/ Over flow            */
  INTTB01_IRQn                  = 21,        /*!< 16bit TMRB0 compare match detection 1                       */
  INTTB10_IRQn                  = 22,        /*!< 16bit TMRB1 compare match detection 0/ Over flow            */
  INTTB11_IRQn                  = 23,        /*!< 16bit TMRB1 compare match detection 1                       */
  INTTB40_IRQn                  = 24,        /*!< 16bit TMRB4 compare match detection 0/ Over flow            */
  INTTB41_IRQn                  = 25,        /*!< 16bit TMRB4 compare match detection 1                       */
  INTTB50_IRQn                  = 26,        /*!< 16bit TMRB5 compare match detection 0/ Over flow            */
  INTTB51_IRQn                  = 27,        /*!< 16bit TMRB5 compare match detection 1                       */
  INTPMD0_IRQn                  = 28,        /*!< PMD0 PWM interrupt                                          */
  INTPMD1_IRQn                  = 29,        /*!< PMD1 PWM interrupt                                          */
  INTCAP00_IRQn                 = 30,        /*!< 16bit TMRB0 input capture 0                                 */
  INTCAP01_IRQn                 = 31,        /*!< 16bit TMRB0 input capture 1                                 */
  INTCAP10_IRQn                 = 32,        /*!< 16bit TMRB1 input capture 0                                 */
  INTCAP11_IRQn                 = 33,        /*!< 16bit TMRB1 input capture 1                                 */
  INTCAP40_IRQn                 = 34,        /*!< 16bit TMRB4 input capture 0                                 */
  INTCAP41_IRQn                 = 35,        /*!< 16bit TMRB4 input capture 1                                 */
  INTCAP50_IRQn                 = 36,        /*!< 16bit TMRB5 input capture 0                                 */
  INTCAP51_IRQn                 = 37,        /*!< 16bit TMRB5 input capture 1                                 */
  INT6_IRQn                     = 38,        /*!< Interrupt Pin (PE6/TB3IN//17pin or 19pin)                   */
  INT7_IRQn                     = 39,        /*!< Interrupt Pin (PE7/TB3OUT/18pin or 20pin)                   */
  INTRX2_IRQn                   = 40,        /*!< Serial reception (channel.2)                                */
  INTTX2_IRQn                   = 41,        /*!< Serial transmit (channel.2)                                 */
  INTADACPA_IRQn                = 42,        /*!< ADCA conversion monitoring function interrupt A             */
  INTADBCPA_IRQn                = 43,        /*!< ADCB conversion monitoring function interrupt A             */
  INTADACPB_IRQn                = 44,        /*!< ADCA conversion monitoring function interrupt B             */
  INTADBCPB_IRQn                = 45,        /*!< ADCB conversion monitoring function interrupt B             */
  INTTB20_IRQn                  = 46,        /*!< 16bit TMRB2 compare match detection 0/ Over flow            */
  INTTB21_IRQn                  = 47,        /*!< 16bit TMRB2 compare match detection 1                       */
  INTTB30_IRQn                  = 48,        /*!< 16bit TMRB3 compare match detection 0/ Over flow            */
  INTTB31_IRQn                  = 49,        /*!< 16bit TMRB3 compare match detection 1                       */
  INTCAP20_IRQn                 = 50,        /*!< 16bit TMRB2 input capture 0                                 */
  INTCAP21_IRQn                 = 51,        /*!< 16bit TMRB2 input capture 1                                 */
  INTCAP30_IRQn                 = 52,        /*!< 16bit TMRB3 input capture 0                                 */
  INTCAP31_IRQn                 = 53,        /*!< 16bit TMRB3 input capture 1                                 */
  INTADASFT_IRQn                = 54,        /*!< ADCA conversion started by software is finished             */
  INTADBSFT_IRQn                = 55,        /*!< ADCB conversion started by software is finished             */
  INTADATMR_IRQn                = 56,        /*!< ADCA conversion triggered by timer is finished              */
  INTADBTMR_IRQn                = 57,        /*!< ADCB conversion triggered by timer is finished              */
  INT8_IRQn                     = 58,        /*!< Interrupt Pin (PA7/TB4IN/9pin or 11pin)                     */
  INT9_IRQn                     = 59,        /*!< Interrupt Pin (PD3/33pin or 35pin)                          */
  INTA_IRQn                     = 60,        /*!< Interrupt Pin (PL1/21pin or 23pin)                          */
  INTB_IRQn                     = 61,        /*!< Interrupt Pin (PL0/20pin or 22pin)                          */
  INTENC0_IRQn                  = 62,        /*!< Ender input0 interrupt                                      */
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
#include "system_TMPM370.h"                 /* TMPM370 System                                      */

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
       uint32_t RESERVED0[8];
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
  __IO uint32_t DATA;              /*!< PC Register                                  */
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
  __IO uint32_t DATA;              /*!< PD Register                                  */
  __IO uint32_t CR;                /*!< PD Control Register                          */
  __IO uint32_t FR1;               /*!< PD Function Register 1                       */
  __IO uint32_t FR2;               /*!< PD Function Register 2                       */
       uint32_t RESERVED0[6];
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
  * @brief General Purpose Input/Output Port (PH)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PH Register                                  */
  __IO uint32_t CR;                /*!< PH Control Register                          */
  __IO uint32_t FR1;               /*!< PH Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PH Open Drain Control Register               */
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
  * @brief General Purpose Input/Output Port (PL)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PL Register                                  */
       uint32_t RESERVED0;
  __IO uint32_t FR1;               /*!< PL Function Register 1                       */
       uint32_t RESERVED1[11];
  __IO uint32_t IE;                /*!< PL Input Enable Control Register             */
} TSB_PL_TypeDef;

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
  __IO uint32_t PSEL0;             /*!< PMD Trigger Program Number Select Register 0 */
  __IO uint32_t PSEL1;             /*!< PMD Trigger Program Number Select Register 1 */
  __IO uint32_t PSEL2;             /*!< PMD Trigger Program Number Select Register 2 */
  __IO uint32_t PSEL3;             /*!< PMD Trigger ProgramNumber Select Register 3  */
  __IO uint32_t PSEL4;             /*!< PMD Trigger ProgramNumber Select Register 4  */
  __IO uint32_t PSEL5;             /*!< PMD Trigger ProgramNumber Select Register 5  */
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
  __IO uint32_t MOD3;              /*!< AD Mode Setting Register 3                   */
} TSB_AD_TypeDef;

/**
  * @brief Op-Amps/Analog Comparators
  */
typedef struct
{
  __IO uint32_t CTLA;              /*!< Amp A Control Register                       */
       uint32_t RESERVED0;
  __IO uint32_t CTLB;              /*!< Amp B Control Register                       */
       uint32_t RESERVED1;
  __IO uint32_t CTLC;              /*!< Amp C Control Register                       */
       uint32_t RESERVED2;
  __IO uint32_t CTLD;              /*!< Amp D Control Register                       */
} TSB_AMP_TypeDef;

/**
  * @brief Op-Amps/Analog Comparators
  */
typedef struct
{
  __IO uint32_t CTLA;              /*!< Comparator A Control Register                */
       uint32_t RESERVED0;
  __IO uint32_t CTLB;              /*!< Comparator B Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t CTLC;              /*!< Comparator C Control Register                */
       uint32_t RESERVED2;
  __IO uint32_t CTLD;              /*!< Comparator D Control Register                */
} TSB_CMP_TypeDef;

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
  __I  uint32_t NMIFLG;            /*!< NMI Flag Register                            */
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
  __IO uint32_t MCTLF0;            /*!< Status flags                                 */
  __IO uint32_t MODE0;             /*!< Task control mode                            */
  __IO uint32_t FMODE0;            /*!< Flow control                                 */
  __IO uint32_t TPWM0;             /*!< PWM period rate (PWM period [s] ¡Á maximum speed*1 ¡Á 2^16) */
  __IO uint32_t OMEGA0;            /*!< Rotation speed (speed [Hz]¡Â maximum speed *1¡ù1 ¡Á 2^15) */
  __IO uint32_t THETA0;            /*!< Motor phase (motor phase [deg]/360 ¡Á 2^16) */
  __IO uint32_t IDREF0;            /*!< d-axis reference value (current [A] ¡Â maximum current*2 ¡Á 2^15) */
  __IO uint32_t IQREF0;            /*!< q-axis reference value (current [A] ¡Â maximum current *2 ¡Á 2^15) */
  __IO uint32_t VD0;               /*!< d-axis voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^31)*/
  __IO uint32_t VQ0;               /*!< q-axis voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^31)*/
  __IO uint32_t CIDKI0;            /*!< Integral coefficient for PI control of d-axis */
  __IO uint32_t CIDKP0;            /*!< Proportional coefficient for PI control of d-axis */
  __IO uint32_t CIQKI0;            /*!< Integral coefficient for PI control of q-axis */
  __IO uint32_t CIQKP0;            /*!< Proportional coefficient for PI control of q-axis */
  __IO uint32_t VDIH0;             /*!< Upper 32 bits of integral term (VDI ) of d-axis voltage */
  __IO uint32_t VDILH0;            /*!< Lower 32 bits of integral term (VDI) of d-axis voltage */
  __IO uint32_t VQIH0;             /*!< Upper 32 bits of integral term (VQI) of q-axis voltage */
  __IO uint32_t VQILH0;            /*!< Lower 32 bits of integral term (VQI) of q-axis voltage */
  __IO uint32_t FPWMCHG0;          /*!< Switching speed (for 2-phase modulation and shift PWM) */
  __IO uint32_t MDPRD0;            /*!< PWM period (to be set identically with PMD¡¯s PWM period) */
  __IO uint32_t MINPLS0;           /*!< Minimum pulse width                          */
  __IO uint32_t TRGCRC0;           /*!< Synchronizing trigger correction value       */
       uint32_t RESERVED1;
  __IO uint32_t COS0;              /*!< Cosine value at THETA for output conversion (Q15 data) */
  __IO uint32_t SIN0;              /*!< Sine value at THETA for output conversion (Q15 data) */
  __IO uint32_t COSM0;             /*!< Previous cosine value for input processing (Q15 data) */
  __IO uint32_t SINM0;             /*!< Previous sine value for input processing (Q15 data) */
  __IO uint32_t SECTOR0;           /*!< Sector information (0-11)                    */
  __IO uint32_t SECTORM0;          /*!< Previous sector information for input processing (0-11) */
  __IO uint32_t IA00;              /*!< AD conversion result of a-phase zero-current *4 */
  __IO uint32_t IB00;              /*!< AD conversion result of b-phase zero-current *4 */
  __IO uint32_t IC00;              /*!< AD conversion result of c-phase zero-current *4 */
  __IO uint32_t IAADC0;            /*!< AD conversion result of a-phase current *4    */
  __IO uint32_t IBADC0;            /*!< AD conversion result of b-phase current *4    */
  __IO uint32_t ICADC0;            /*!< AD conversion result of c-phase current *4    */
  __IO uint32_t VDC0;              /*!< DC supply voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^15) */
  __IO uint32_t ID0;               /*!< d-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
  __IO uint32_t IQ0;               /*!< q-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
  __IO uint32_t MCTLF1;            /*!< Status flags                                 */
  __IO uint32_t MODE1;             /*!< Task control mode                            */
  __IO uint32_t FMODE1;            /*!< Flow control                                 */
  __IO uint32_t TPWM1;             /*!< PWM period rate (PWM period [s] ¡Á maximum speed*1 ¡Á 2^16) */
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
  __IO uint32_t VDILH1;            /*!< Lower 32 bits of integral term (VDI) of d-axis voltage  */
  __IO uint32_t VQIH1;             /*!< Upper 32 bits of integral term (VQI) of q-axis voltage  */
  __IO uint32_t VQILH1;            /*!< Lower 32 bits of integral term (VQI) of q-axis voltage  */
  __IO uint32_t FPWMCHG1;          /*!< Switching speed (for 2-phase modulation and shift PWM)  */
  __IO uint32_t MDPRD1;            /*!< PWM period (to be set identically with PMD¡¯s PWM period)*/
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
  __IO uint32_t IAADC1;            /*!< AD conversion result of a-phase current *4 */
  __IO uint32_t IBADC1;            /*!< AD conversion result of b-phase current *4 */
  __IO uint32_t ICADC1;            /*!< AD conversion result of c-phase current *4 */
  __IO uint32_t VDC1;              /*!< DC supply voltage (voltage [V] ¡Â maximum voltage *3 ¡Á 2^15) */
  __IO uint32_t ID1;               /*!< d-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
  __IO uint32_t IQ1;               /*!< q-axis current (current [A] ¡Â maximum current *2 ¡Á 2^31) */
       uint32_t RESERVED3;
  __IO uint32_t TADC;              /*!< Common ADC conversion time (based on PWM clock) */
  __IO uint32_t VCMPU0;            /*!< PMD control: CMPU setting                    */
  __IO uint32_t VCMPV0;            /*!< PMD control: CMPV setting                    */
  __IO uint32_t VCMPW0;            /*!< PMD control: CMPW setting                    */
  __IO uint32_t OUTCR0;            /*!< PMD control: Output control (MDOUT)          */
  __IO uint32_t VTRGCMP00;         /*!< PMD control: TRGCMP0 setting                 */
  __IO uint32_t VTRGCMP10;         /*!< PMD control: TRGCMP1 setting                 */
  __IO uint32_t VTRGSEL0;          /*!< PMD control: Trigger selection               */
  __O  uint32_t EMGRS0;            /*!< PMD control: EMG return (EMGCR[EMGRS])       */
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
#define TSB_PC_BASE                (PERI_BASE  + 0x0000080UL)
#define TSB_PD_BASE                (PERI_BASE  + 0x00000C0UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x0000100UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x0000140UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x0000180UL)
#define TSB_PH_BASE                (PERI_BASE  + 0x00001C0UL)
#define TSB_PI_BASE                (PERI_BASE  + 0x0000200UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x0000240UL)
#define TSB_PK_BASE                (PERI_BASE  + 0x0000280UL)
#define TSB_PL_BASE                (PERI_BASE  + 0x00002C0UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x0010000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x0010040UL)
#define TSB_TB2_BASE               (PERI_BASE  + 0x0010080UL)
#define TSB_TB3_BASE               (PERI_BASE  + 0x00100C0UL)
#define TSB_TB4_BASE               (PERI_BASE  + 0x0010100UL)
#define TSB_TB5_BASE               (PERI_BASE  + 0x0010140UL)
#define TSB_TB6_BASE               (PERI_BASE  + 0x0010180UL)
#define TSB_TB7_BASE               (PERI_BASE  + 0x00101C0UL)
#define TSB_EN0_BASE               (PERI_BASE  + 0x0010400UL)
#define TSB_EN1_BASE               (PERI_BASE  + 0x0010500UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x0020080UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00200C0UL)
#define TSB_SC2_BASE               (PERI_BASE  + 0x0020100UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x0020140UL)
#define TSB_ADA_BASE               (PERI_BASE  + 0x0030000UL)
#define TSB_ADB_BASE               (PERI_BASE  + 0x0030200UL)
#define TSB_AMP_BASE               (PERI_BASE  + 0x0030400UL)
#define TSB_CMP_BASE               (PERI_BASE  + 0x0030420UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x0040000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x0040200UL)
#define TSB_OFD_BASE               (PERI_BASE  + 0x0040800UL)
#define TSB_VD_BASE                (PERI_BASE  + 0x0040900UL)
#define TSB_VE_BASE                (PERI_BASE  + 0x0050000UL)
#define TSB_PMD0_BASE              (PERI_BASE  + 0x0050400UL)
#define TSB_PMD1_BASE              (PERI_BASE  + 0x0050480UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1FFF010UL)


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
#define TSB_PL                     ((     TSB_PL_TypeDef *)    TSB_PL_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_TB2                    ((     TSB_TB_TypeDef *)   TSB_TB2_BASE)
#define TSB_TB3                    ((     TSB_TB_TypeDef *)   TSB_TB3_BASE)
#define TSB_TB4                    ((     TSB_TB_TypeDef *)   TSB_TB4_BASE)
#define TSB_TB5                    ((     TSB_TB_TypeDef *)   TSB_TB5_BASE)
#define TSB_TB6                    ((     TSB_TB_TypeDef *)   TSB_TB6_BASE)
#define TSB_TB7                    ((     TSB_TB_TypeDef *)   TSB_TB7_BASE)
#define TSB_EN0                    ((     TSB_EN_TypeDef *)   TSB_EN0_BASE)
#define TSB_EN1                    ((     TSB_EN_TypeDef *)   TSB_EN1_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC2                    ((     TSB_SC_TypeDef *)   TSB_SC2_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_ADA                    ((     TSB_AD_TypeDef *)   TSB_ADA_BASE)
#define TSB_ADB                    ((     TSB_AD_TypeDef *)   TSB_ADB_BASE)
#define TSB_AMP                    ((    TSB_AMP_TypeDef *)   TSB_AMP_BASE)
#define TSB_CMP                    ((    TSB_CMP_TypeDef *)   TSB_CMP_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)
#define TSB_OFD                    ((    TSB_OFD_TypeDef *)   TSB_OFD_BASE)
#define TSB_VD                     ((     TSB_VD_TypeDef *)    TSB_VD_BASE)
#define TSB_VE                     ((     TSB_VE_TypeDef *)    TSB_VE_BASE)
#define TSB_PMD0                   ((    TSB_PMD_TypeDef *)  TSB_PMD0_BASE)
#define TSB_PMD1                   ((    TSB_PMD_TypeDef *)  TSB_PMD1_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)


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
#define TSB_PA_FR2_PA0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,0)))
#define TSB_PA_FR2_PA2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,2)))
#define TSB_PA_FR2_PA4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,4)))
#define TSB_PA_FR2_PA5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,5)))
#define TSB_PA_FR2_PA6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,6)))
#define TSB_PA_FR2_PA7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,7)))
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
#define TSB_PB_PUP_PB0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,0)))
#define TSB_PB_PUP_PB1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,1)))
#define TSB_PB_PUP_PB2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,2)))
#define TSB_PB_PUP_PB3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PUP_PB7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,7)))
#define TSB_PB_PDN_PB4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,4)))
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
#define TSB_PD_CR_PD0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,0)))
#define TSB_PD_CR_PD1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,1)))
#define TSB_PD_CR_PD2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,2)))
#define TSB_PD_CR_PD3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,3)))
#define TSB_PD_CR_PD4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,4)))
#define TSB_PD_CR_PD5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,5)))
#define TSB_PD_CR_PD6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,6)))
#define TSB_PD_FR1_PD0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,0)))
#define TSB_PD_FR1_PD1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,1)))
#define TSB_PD_FR1_PD2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,2)))
#define TSB_PD_FR1_PD3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,3)))
#define TSB_PD_FR1_PD4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,4)))
#define TSB_PD_FR1_PD5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,5)))
#define TSB_PD_FR1_PD6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,6)))
#define TSB_PD_FR2_PD0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,0)))
#define TSB_PD_FR2_PD1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,1)))
#define TSB_PD_FR2_PD4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,4)))
#define TSB_PD_OD_PD0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,0)))
#define TSB_PD_OD_PD1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,1)))
#define TSB_PD_OD_PD2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,2)))
#define TSB_PD_OD_PD3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,3)))
#define TSB_PD_OD_PD4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,4)))
#define TSB_PD_OD_PD5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,5)))
#define TSB_PD_OD_PD6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,6)))
#define TSB_PD_PUP_PD0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,0)))
#define TSB_PD_PUP_PD1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,1)))
#define TSB_PD_PUP_PD2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,2)))
#define TSB_PD_PUP_PD3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,3)))
#define TSB_PD_PUP_PD4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,4)))
#define TSB_PD_PUP_PD5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,5)))
#define TSB_PD_PUP_PD6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,6)))
#define TSB_PD_PDN_PD0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,0)))
#define TSB_PD_PDN_PD1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,1)))
#define TSB_PD_PDN_PD2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,2)))
#define TSB_PD_PDN_PD3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,3)))
#define TSB_PD_PDN_PD4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,4)))
#define TSB_PD_PDN_PD5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,5)))
#define TSB_PD_PDN_PD6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,6)))
#define TSB_PD_IE_PD0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,0)))
#define TSB_PD_IE_PD1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,1)))
#define TSB_PD_IE_PD2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,2)))
#define TSB_PD_IE_PD3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,3)))
#define TSB_PD_IE_PD4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,4)))
#define TSB_PD_IE_PD5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,5)))
#define TSB_PD_IE_PD6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,6)))


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
#define TSB_PE_FR2_PE2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_FR2_PE4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,4)))
#define TSB_PE_FR2_PE6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,6)))
#define TSB_PE_FR2_PE7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,7)))
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
#define TSB_PF_DATA_PF2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,2)))
#define TSB_PF_DATA_PF3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,3)))
#define TSB_PF_DATA_PF4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,4)))
#define TSB_PF_CR_PF0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,1)))
#define TSB_PF_CR_PF2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,2)))
#define TSB_PF_CR_PF3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,3)))
#define TSB_PF_CR_PF4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,4)))
#define TSB_PF_FR1_PF0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,0)))
#define TSB_PF_FR1_PF1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,1)))
#define TSB_PF_FR1_PF2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,2)))
#define TSB_PF_FR1_PF3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,3)))
#define TSB_PF_FR1_PF4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,4)))
#define TSB_PF_FR2_PF2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,2)))
#define TSB_PF_FR2_PF3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,3)))
#define TSB_PF_FR2_PF4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,4)))
#define TSB_PF_FR3_PF2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,2)))
#define TSB_PF_OD_PF0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,1)))
#define TSB_PF_OD_PF2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,2)))
#define TSB_PF_OD_PF3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,3)))
#define TSB_PF_OD_PF4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,4)))
#define TSB_PF_PUP_PF0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,1)))
#define TSB_PF_PUP_PF2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,2)))
#define TSB_PF_PUP_PF3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,3)))
#define TSB_PF_PUP_PF4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,4)))
#define TSB_PF_PDN_PF0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,0)))
#define TSB_PF_PDN_PF1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,1)))
#define TSB_PF_PDN_PF2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,2)))
#define TSB_PF_PDN_PF3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,3)))
#define TSB_PF_PDN_PF4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,4)))
#define TSB_PF_IE_PF0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,1)))
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


/* General Purpose Input/Output Port (PH) */
#define TSB_PH_DATA_PH0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,0)))
#define TSB_PH_DATA_PH1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,1)))
#define TSB_PH_DATA_PH2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,2)))
#define TSB_PH_DATA_PH3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,3)))
#define TSB_PH_DATA_PH4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,4)))
#define TSB_PH_DATA_PH5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,5)))
#define TSB_PH_DATA_PH6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,6)))
#define TSB_PH_DATA_PH7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,7)))
#define TSB_PH_CR_PH0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,0)))
#define TSB_PH_CR_PH1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,1)))
#define TSB_PH_CR_PH2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,2)))
#define TSB_PH_CR_PH3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,3)))
#define TSB_PH_CR_PH4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,4)))
#define TSB_PH_CR_PH5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,5)))
#define TSB_PH_CR_PH6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,6)))
#define TSB_PH_CR_PH7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,7)))
#define TSB_PH_FR1_PH0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,0)))
#define TSB_PH_FR1_PH1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,1)))
#define TSB_PH_FR1_PH2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,2)))
#define TSB_PH_OD_PH0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,0)))
#define TSB_PH_OD_PH1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,1)))
#define TSB_PH_OD_PH2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,2)))
#define TSB_PH_OD_PH3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,3)))
#define TSB_PH_OD_PH4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,4)))
#define TSB_PH_OD_PH5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,5)))
#define TSB_PH_OD_PH6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,6)))
#define TSB_PH_OD_PH7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,7)))
#define TSB_PH_PUP_PH0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,0)))
#define TSB_PH_PUP_PH1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,1)))
#define TSB_PH_PUP_PH2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,2)))
#define TSB_PH_PUP_PH3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,3)))
#define TSB_PH_PUP_PH4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,4)))
#define TSB_PH_PUP_PH5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,5)))
#define TSB_PH_PUP_PH6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,6)))
#define TSB_PH_PUP_PH7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,7)))
#define TSB_PH_PDN_PH0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,0)))
#define TSB_PH_PDN_PH1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,1)))
#define TSB_PH_PDN_PH2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,2)))
#define TSB_PH_PDN_PH3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,3)))
#define TSB_PH_PDN_PH4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,4)))
#define TSB_PH_PDN_PH5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,5)))
#define TSB_PH_PDN_PH6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,6)))
#define TSB_PH_PDN_PH7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,7)))
#define TSB_PH_IE_PH0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,0)))
#define TSB_PH_IE_PH1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,1)))
#define TSB_PH_IE_PH2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,2)))
#define TSB_PH_IE_PH3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,3)))
#define TSB_PH_IE_PH4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,4)))
#define TSB_PH_IE_PH5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,5)))
#define TSB_PH_IE_PH6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,6)))
#define TSB_PH_IE_PH7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,7)))


/* General Purpose Input/Output Port (PI) */
#define TSB_PI_DATA_PI0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,0)))
#define TSB_PI_DATA_PI1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,1)))
#define TSB_PI_DATA_PI2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,2)))
#define TSB_PI_DATA_PI3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,3)))
#define TSB_PI_CR_PI0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,0)))
#define TSB_PI_CR_PI1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,1)))
#define TSB_PI_CR_PI2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,2)))
#define TSB_PI_CR_PI3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_OD_PI0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,0)))
#define TSB_PI_OD_PI1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,1)))
#define TSB_PI_OD_PI2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,2)))
#define TSB_PI_OD_PI3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,3)))
#define TSB_PI_PUP_PI0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,0)))
#define TSB_PI_PUP_PI1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,1)))
#define TSB_PI_PUP_PI2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,2)))
#define TSB_PI_PUP_PI3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,3)))
#define TSB_PI_PDN_PI0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,0)))
#define TSB_PI_PDN_PI1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,1)))
#define TSB_PI_PDN_PI2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,2)))
#define TSB_PI_PDN_PI3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,3)))
#define TSB_PI_IE_PI0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,0)))
#define TSB_PI_IE_PI1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,1)))
#define TSB_PI_IE_PI2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,2)))
#define TSB_PI_IE_PI3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))


/* General Purpose Input/Output Port (PJ) */
#define TSB_PJ_DATA_PJ0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,1)))
#define TSB_PJ_DATA_PJ2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,2)))
#define TSB_PJ_DATA_PJ3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,3)))
#define TSB_PJ_DATA_PJ4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,4)))
#define TSB_PJ_DATA_PJ5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,5)))
#define TSB_PJ_DATA_PJ6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,6)))
#define TSB_PJ_DATA_PJ7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,7)))
#define TSB_PJ_CR_PJ0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,0)))
#define TSB_PJ_CR_PJ1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,1)))
#define TSB_PJ_CR_PJ2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,2)))
#define TSB_PJ_CR_PJ3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,3)))
#define TSB_PJ_CR_PJ4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,4)))
#define TSB_PJ_CR_PJ5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,5)))
#define TSB_PJ_CR_PJ6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,6)))
#define TSB_PJ_CR_PJ7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,7)))
#define TSB_PJ_FR1_PJ6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,6)))
#define TSB_PJ_FR1_PJ7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR1,7)))
#define TSB_PJ_OD_PJ0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,0)))
#define TSB_PJ_OD_PJ1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,1)))
#define TSB_PJ_OD_PJ2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,2)))
#define TSB_PJ_OD_PJ3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,3)))
#define TSB_PJ_OD_PJ4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,4)))
#define TSB_PJ_OD_PJ5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,5)))
#define TSB_PJ_OD_PJ6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,6)))
#define TSB_PJ_OD_PJ7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,7)))
#define TSB_PJ_PUP_PJ0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,1)))
#define TSB_PJ_PUP_PJ2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,2)))
#define TSB_PJ_PUP_PJ3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,3)))
#define TSB_PJ_PUP_PJ4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,4)))
#define TSB_PJ_PUP_PJ5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,5)))
#define TSB_PJ_PUP_PJ6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,6)))
#define TSB_PJ_PUP_PJ7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,7)))
#define TSB_PJ_PDN_PJ0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,0)))
#define TSB_PJ_PDN_PJ1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,1)))
#define TSB_PJ_PDN_PJ2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,2)))
#define TSB_PJ_PDN_PJ3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,3)))
#define TSB_PJ_PDN_PJ4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,4)))
#define TSB_PJ_PDN_PJ5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,5)))
#define TSB_PJ_PDN_PJ6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,6)))
#define TSB_PJ_PDN_PJ7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,7)))
#define TSB_PJ_IE_PJ0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,1)))
#define TSB_PJ_IE_PJ2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,2)))
#define TSB_PJ_IE_PJ3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,3)))
#define TSB_PJ_IE_PJ4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,4)))
#define TSB_PJ_IE_PJ5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,5)))
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


/* General Purpose Input/Output Port (PL) */
#define TSB_PL_DATA_PL0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,0)))
#define TSB_PL_DATA_PL1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,1)))
#define TSB_PL_FR1_PL0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,0)))
#define TSB_PL_FR1_PL1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,1)))
#define TSB_PL_IE_PL0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,0)))
#define TSB_PL_IE_PL1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,1)))


/* 16-bit Timer/Event Counter (TB) */
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
#define TSB_EN0_TNCR_INTEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,3)))
#define TSB_EN0_TNCR_ENRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,6)))
#define TSB_EN0_TNCR_ZEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,7)))
#define TSB_EN0_TNCR_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,8)))
#define TSB_EN0_TNCR_ZESEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,9)))
#define TSB_EN0_TNCR_ENCLR                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,10)))
#define TSB_EN0_TNCR_SFTCAP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,11)))
#define TSB_EN0_TNCR_ZDET                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,12)))
#define TSB_EN0_TNCR_UD                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,13)))
#define TSB_EN0_TNCR_REVERR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,14)))
#define TSB_EN0_TNCR_CMP                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,15)))
#define TSB_EN0_TNCR_P3EN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,16)))

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
#define TSB_SC2_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,6)))
#define TSB_SC2_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,7)))
#define TSB_SC2_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,6)))
#define TSB_SC2_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,7)))
#define TSB_SC2_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->RST,7)))
#define TSB_SC2_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->TST,7)))
#define TSB_SC2_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,0)))
#define TSB_SC2_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,1)))
#define TSB_SC2_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,2)))
#define TSB_SC2_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,3)))
#define TSB_SC2_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,4)))

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
#define TSB_ADA_MOD0_ADSS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD0,0)))
#define TSB_ADA_MOD1_ADAS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,0)))
#define TSB_ADA_MOD1_ADEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,7)))
#define TSB_ADA_MOD2_ADBFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD2,0)))
#define TSB_ADA_MOD2_ADSFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD2,1)))
#define TSB_ADA_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,4)))
#define TSB_ADA_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,7)))
#define TSB_ADA_CMPCR1_ADBIG1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,4)))
#define TSB_ADA_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,7)))
#define TSB_ADA_PSEL0_PENS0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL0,7)))
#define TSB_ADA_PSEL1_PENS1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL1,7)))
#define TSB_ADA_PSEL2_PENS2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL2,7)))
#define TSB_ADA_PSEL3_PENS3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL3,7)))
#define TSB_ADA_PSEL4_PENS4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL4,7)))
#define TSB_ADA_PSEL5_PENS5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL5,7)))
#define TSB_ADA_PSEL6_PENS6                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL6,7)))
#define TSB_ADA_PSEL7_PENS7                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL7,7)))
#define TSB_ADA_PSEL8_PENS8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL8,7)))
#define TSB_ADA_PSEL9_PENS9                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL9,7)))
#define TSB_ADA_PSEL10_PENS10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL10,7)))
#define TSB_ADA_PSEL11_PENS11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL11,7)))
#define TSB_ADA_PSET0_ENSP00                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,7)))
#define TSB_ADA_PSET0_ENSP01                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,15)))
#define TSB_ADA_PSET0_ENSP02                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,23)))
#define TSB_ADA_PSET0_ENSP03                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,31)))
#define TSB_ADA_PSET1_ENSP10                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,7)))
#define TSB_ADA_PSET1_ENSP11                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,15)))
#define TSB_ADA_PSET1_ENSP12                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,23)))
#define TSB_ADA_PSET1_ENSP13                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,31)))
#define TSB_ADA_PSET2_ENSP20                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,7)))
#define TSB_ADA_PSET2_ENSP21                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,15)))
#define TSB_ADA_PSET2_ENSP22                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,23)))
#define TSB_ADA_PSET2_ENSP23                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,31)))
#define TSB_ADA_PSET3_ENSP30                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,7)))
#define TSB_ADA_PSET3_ENSP31                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,15)))
#define TSB_ADA_PSET3_ENSP32                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,23)))
#define TSB_ADA_PSET3_ENSP33                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,31)))
#define TSB_ADA_PSET4_ENSP40                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,7)))
#define TSB_ADA_PSET4_ENSP41                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,15)))
#define TSB_ADA_PSET4_ENSP42                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,23)))
#define TSB_ADA_PSET4_ENSP43                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,31)))
#define TSB_ADA_PSET5_ENSP50                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,7)))
#define TSB_ADA_PSET5_ENSP51                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,15)))
#define TSB_ADA_PSET5_ENSP52                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,23)))
#define TSB_ADA_PSET5_ENSP53                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,31)))
#define TSB_ADA_TSET03_ENST0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,7)))
#define TSB_ADA_TSET03_ENST1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,15)))
#define TSB_ADA_TSET03_ENST2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,23)))
#define TSB_ADA_TSET03_ENST3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,31)))
#define TSB_ADA_TSET47_ENST4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,7)))
#define TSB_ADA_TSET47_ENST5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,15)))
#define TSB_ADA_TSET47_ENST6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,23)))
#define TSB_ADA_TSET47_ENST7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,31)))
#define TSB_ADA_TSET811_ENST8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,7)))
#define TSB_ADA_TSET811_ENST9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,15)))
#define TSB_ADA_TSET811_ENST10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,23)))
#define TSB_ADA_TSET811_ENST11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,31)))
#define TSB_ADA_SSET03_ENSS0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,7)))
#define TSB_ADA_SSET03_ENSS1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,15)))
#define TSB_ADA_SSET03_ENSS2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,23)))
#define TSB_ADA_SSET03_ENSS3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,31)))
#define TSB_ADA_SSET47_ENSS4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,7)))
#define TSB_ADA_SSET47_ENSS5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,15)))
#define TSB_ADA_SSET47_ENSS6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,23)))
#define TSB_ADA_SSET47_ENSS7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,31)))
#define TSB_ADA_SSET811_ENSS8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,7)))
#define TSB_ADA_SSET811_ENSS9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,15)))
#define TSB_ADA_SSET811_ENSS10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,23)))
#define TSB_ADA_SSET811_ENSS11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,31)))
#define TSB_ADA_ASET03_ENSA0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,7)))
#define TSB_ADA_ASET03_ENSA1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,15)))
#define TSB_ADA_ASET03_ENSA2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,23)))
#define TSB_ADA_ASET03_ENSA3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,31)))
#define TSB_ADA_ASET47_ENSA4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,7)))
#define TSB_ADA_ASET47_ENSA5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,15)))
#define TSB_ADA_ASET47_ENSA6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,23)))
#define TSB_ADA_ASET47_ENSA7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,31)))
#define TSB_ADA_ASET811_ENSA8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,7)))
#define TSB_ADA_ASET811_ENSA9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,15)))
#define TSB_ADA_ASET811_ENSA10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,23)))
#define TSB_ADA_ASET811_ENSA11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,31)))

#define TSB_ADB_MOD0_ADSS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD0,0)))
#define TSB_ADB_MOD1_ADAS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,0)))
#define TSB_ADB_MOD1_ADEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,7)))
#define TSB_ADB_MOD2_ADBFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,0)))
#define TSB_ADB_MOD2_ADSFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,1)))
#define TSB_ADB_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,4)))
#define TSB_ADB_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,7)))
#define TSB_ADB_CMPCR1_ADBIG1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,4)))
#define TSB_ADB_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,7)))
#define TSB_ADB_PSEL0_PENS0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL0,7)))
#define TSB_ADB_PSEL1_PENS1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL1,7)))
#define TSB_ADB_PSEL2_PENS2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL2,7)))
#define TSB_ADB_PSEL3_PENS3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL3,7)))
#define TSB_ADB_PSEL4_PENS4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL4,7)))
#define TSB_ADB_PSEL5_PENS5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL5,7)))
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


/* Op-Amps/Analog Comparators */
#define TSB_AMP_CTLA_AMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AMP->CTLA,0)))
#define TSB_AMP_CTLB_AMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AMP->CTLB,0)))
#define TSB_AMP_CTLC_AMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AMP->CTLC,0)))
#define TSB_AMP_CTLD_AMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AMP->CTLD,0)))


/* Op-Amps/Analog Comparators */
#define TSB_CMP_CTLA_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLA,0)))
#define TSB_CMP_CTLA_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLA,1)))
#define TSB_CMP_CTLB_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLB,0)))
#define TSB_CMP_CTLB_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLB,1)))
#define TSB_CMP_CTLC_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLC,0)))
#define TSB_CMP_CTLC_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLC,1)))
#define TSB_CMP_CTLD_CMPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLD,0)))
#define TSB_CMP_CTLD_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CMP->CTLD,1)))


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
#define TSB_CG_IMCGA_INT0EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,0)))
#define TSB_CG_IMCGA_INT1EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,8)))
#define TSB_CG_IMCGA_INT2EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,16)))
#define TSB_CG_IMCGA_INT3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))
#define TSB_CG_IMCGB_INT6EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,16)))
#define TSB_CG_IMCGB_INT7EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,24)))
#define TSB_CG_IMCGC_INT8EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,0)))
#define TSB_CG_IMCGC_INT9EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,8)))
#define TSB_CG_IMCGC_INTAEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,16)))
#define TSB_CG_IMCGC_INTBEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,24)))
#define TSB_CG_IMCGD_INTCEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,0)))
#define TSB_CG_IMCGD_INTDEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,8)))
#define TSB_CG_IMCGD_INTEEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,16)))
#define TSB_CG_IMCGD_INTFEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,24)))


/* Power-On Reset Circuit (POR) */
#define TSB_VD_CR_VDEN                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_VD->CR,0)))
#define TSB_VD_CR_VDLVL0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_VD->CR,1)))
#define TSB_VD_CR_VDLVL1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_VD->CR,2)))


/* Vector Engine (VE) */
#define TSB_VE_EN_VEEN                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EN,0)))
#define TSB_VE_EN_VEIDLEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EN,1)))
#define TSB_VE_ERRINTEN_VERRENA                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->ERRINTEN,0)))
#define TSB_VE_ERRINTEN_VERRENB                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->ERRINTEN,1)))
#define TSB_VE_SCHTASKRUN_VRSCHA                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_VE->SCHTASKRUN,0)))
#define TSB_VE_SCHTASKRUN_VRSCHB                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_VE->SCHTASKRUN,5)))
#define TSB_VE_MCTLF0_LAVF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF0,0)))
#define TSB_VE_MCTLF0_LAVFM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF0,1)))
#define TSB_VE_MCTLF0_LVTF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF0,2)))
#define TSB_VE_MCTLF0_PLSLF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF0,4)))
#define TSB_VE_MCTLF0_PLSLFM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF0,5)))
#define TSB_VE_MODE0_PVIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE0 ,0)))
#define TSB_VE_MODE0_ZIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE0 ,1)))
#define TSB_VE_FMODE0_C2PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE0,0)))
#define TSB_VE_FMODE0_SPWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE0,1)))
#define TSB_VE_FMODE0_PMDSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE0,4)))
#define TSB_VE_FMODE0_MREGDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE0,9)))
#define TSB_VE_MCTLF1_LAVF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1 ,0)))
#define TSB_VE_MCTLF1_LAVFM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1 ,1)))
#define TSB_VE_MCTLF1_LVTF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1 ,2)))
#define TSB_VE_MCTLF1_PLSLF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1 ,4)))
#define TSB_VE_MCTLF1_PLSLFM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MCTLF1 ,5)))
#define TSB_VE_MODE1_PVIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE1 ,0)))
#define TSB_VE_MODE1_ZIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->MODE1 ,1)))
#define TSB_VE_FMODE1_C2PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,0)))
#define TSB_VE_FMODE1_SPWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,1)))
#define TSB_VE_FMODE1_PMDSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,4)))
#define TSB_VE_FMODE1_MREGDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->FMODE1,9)))
#define TSB_VE_OUTCR0_UPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR0,6)))
#define TSB_VE_OUTCR0_VPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR0,7)))
#define TSB_VE_OUTCR0_WPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR0,8)))
#define TSB_VE_EMGRS0_EMGRS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EMGRS0,0)))
#define TSB_VE_OUTCR1_UPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,6)))
#define TSB_VE_OUTCR1_VPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,7)))
#define TSB_VE_OUTCR1_WPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->OUTCR1,8)))
#define TSB_VE_EMGRS1_EMGRS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE->EMGRS1 ,0)))


/* 16-bit Multi-Purpose Timer (MPT-PMD) */
#define TSB_PMD0_MDEN_PWMEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDEN,0)))
#define TSB_PMD0_MDCR_PWMMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,0)))
#define TSB_PMD0_MDCR_PINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,3)))
#define TSB_PMD0_MDCR_DTYMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,4)))
#define TSB_PMD0_MDCR_SYNTMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,5)))
#define TSB_PMD0_MDCR_PWMCK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,6)))
#define TSB_PMD0_CNTSTA_UPDWN                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->CNTSTA,0)))
#define TSB_PMD0_MODESEL_MDSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,0)))
#define TSB_PMD0_MDOUT_UPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,8)))
#define TSB_PMD0_MDOUT_VPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,9)))
#define TSB_PMD0_MDOUT_WPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,10)))
#define TSB_PMD0_MDPOT_POLL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDPOT,2)))
#define TSB_PMD0_MDPOT_POLH                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDPOT,3)))
#define TSB_PMD0_EMGCR_EMGEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,0)))
#define TSB_PMD0_EMGCR_EMGRS                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,1)))
#define TSB_PMD0_EMGCR_EMGISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,2)))
#define TSB_PMD0_EMGCR_INHEN                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,5)))
#define TSB_PMD0_EMGSTA_EMGST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGSTA,0)))
#define TSB_PMD0_EMGSTA_EMGI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGSTA,1)))
#define TSB_PMD0_OVVCR_OVVEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,0)))
#define TSB_PMD0_OVVCR_OVVRS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,1)))
#define TSB_PMD0_OVVCR_OVVISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,2)))
#define TSB_PMD0_OVVCR_ADIN0EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,5)))
#define TSB_PMD0_OVVCR_ADIN1EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,6)))
#define TSB_PMD0_OVVSTA_OVVST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVSTA,0)))
#define TSB_PMD0_OVVSTA_OVVI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVSTA,1)))
#define TSB_PMD0_TRGCR_TRG0BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,3)))
#define TSB_PMD0_TRGCR_TRG1BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,7)))
#define TSB_PMD0_TRGCR_TRG2BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,11)))
#define TSB_PMD0_TRGCR_TRG3BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,15)))
#define TSB_PMD0_TRGMD_EMGTGE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGMD,0)))
#define TSB_PMD0_TRGMD_TRGOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGMD,1)))

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
#define TSB_PMD1_EMGCR_EMGISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,2)))
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

#endif  /* __TMPM370_H__ */

/** @} */ /* End of group TMPM370 */
/** @} */ /* End of group TOSHIBA_TX03_MICROCONTROLLER */
