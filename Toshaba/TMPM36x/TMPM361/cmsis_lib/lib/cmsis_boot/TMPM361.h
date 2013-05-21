/**
 *******************************************************************************
 * @file    TMPM361.h
 * @brief   CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM361' Device Series
 * @version V2.2.0
 * @date    2011/04/25
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

/** @addtogroup TMPM361
  * @{
  */

#ifndef __TMPM361_H__
#define __TMPM361_H__

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

/******  TMPM361 Specific Interrupt Numbers *******************************************************************/
  INT0_IRQn                     = 0,         /*!< Interrupt pin 0                                             */
  INT1_IRQn                     = 1,         /*!< Interrupt pin 1                                             */
  INT2_IRQn                     = 2,         /*!< Interrupt pin 2                                             */
  INT3_IRQn                     = 3,         /*!< Interrupt pin 3                                             */
  INT4_IRQn                     = 4,         /*!< Interrupt pin 4                                             */
  INT5_IRQn                     = 5,         /*!< Interrupt pin 5                                             */
  INT6_IRQn                     = 6,         /*!< Interrupt pin 6                                             */
  INT7_IRQn                     = 7,         /*!< Interrupt pin 7                                             */
  INTE_IRQn                     = 14,        /*!< Interrupt pin E                                             */
  INTF_IRQn                     = 15,        /*!< Interrupt pin F                                             */
  INTRX0_IRQn                   = 16,        /*!< Serial reception (channel.0)                                */
  INTTX0_IRQn                   = 17,        /*!< Serial transmission (channel.0)                             */
  INTRX1_IRQn                   = 18,        /*!< Serial reception (channel.1)                                */
  INTTX1_IRQn                   = 19,        /*!< Serial transmission (channel.1)                             */
  INTRX2_IRQn                   = 20,        /*!< Serial reception (channel.2)                                */
  INTTX2_IRQn                   = 21,        /*!< Serial transmission (channel.2)                             */
  INTRX3_IRQn                   = 22,        /*!< Serial reception (channel.3)                                */
  INTTX3_IRQn                   = 23,        /*!< Serial transmission (channel.3)                             */
  INTRX4_IRQn                   = 24,        /*!< Serial reception (channel.4)                                */
  INTTX4_IRQn                   = 25,        /*!< Serial transmission (channel.4)                             */
  INTSBI0_IRQn                  = 26,        /*!< Serial bus interface (channel.0)                            */
  INTSBI1_IRQn                  = 27,        /*!< Serial bus interface (channel.1)                            */
  INTCECRX_IRQn                 = 28,        /*!< CEC reception                                               */
  INTCECTX_IRQn                 = 29,        /*!< CEC transmission                                            */
  INTRMCRX0_IRQn                = 30,        /*!< Remote control signal reception (channel.0)                 */
  INTRTC_IRQn                   = 32,        /*!< Real time clock timer                                       */
  INTKWUP_IRQn                  = 33,        /*!< Key on wake up                                              */
  INTSBI2_IRQn                  = 34,        /*!< Serial bus interface (channel.2)                            */
  INTSBI3_IRQn                  = 35,        /*!< Serial bus interface (channel.3)                            */
  INTADHP_IRQn                  = 37,        /*!< Highest priority AD conversion complete interrupt           */
  INTADM0_IRQn                  = 38,        /*!< AD conversion monitoring function interrupt 0               */
  INTADM1_IRQn                  = 39,        /*!< AD conversion monitoring function interrupt 1               */
  INTTB0_IRQn                   = 40,        /*!< 16bit TMRB match detection 0                                */
  INTTB1_IRQn                   = 41,        /*!< 16bit TMRB match detection 1                                */
  INTTB2_IRQn                   = 42,        /*!< 16bit TMRB match detection 2                                */
  INTTB3_IRQn                   = 43,        /*!< 16bit TMRB match detection 3                                */
  INTTB4_IRQn                   = 44,        /*!< 16bit TMRB match detection 4                                */
  INTTB5_IRQn                   = 45,        /*!< 16bit TMRB match detection 5                                */
  INTTB6_IRQn                   = 46,        /*!< 16bit TMRB match detection 6                                */
  INTTB7_IRQn                   = 47,        /*!< 16bit TMRB match detection 7                                */
  INTTB8_IRQn                   = 48,        /*!< 16bit TMRB match detection 8                                */
  INTTB9_IRQn                   = 49,        /*!< 16bit TMRB match detection 9                                */
  INTTBA_IRQn                   = 50,        /*!< 16bit TMRB match detection A                                */
  INTTBB_IRQn                   = 51,        /*!< 16bit TMRB match detection B                                */
  INTTBC_IRQn                   = 52,        /*!< 16bit TMRB match detection C                                */
  INTTBD_IRQn                   = 53,        /*!< 16bit TMRB match detection D                                */
  INTTBE_IRQn                   = 54,        /*!< 16bit TMRB match detection E                                */
  INTTBF_IRQn                   = 55,        /*!< 16bit TMRB match detection F                                */
  INTAD_IRQn                    = 58,        /*!< AD conversion completion                                    */
  INTSSP_IRQn                   = 59,        /*!< Synchronus serial port                                      */
  INTCAP10_IRQn                 = 74,        /*!< 16bit TMRB input capture 10                                 */
  INTCAP11_IRQn                 = 75,        /*!< 16bit TMRB input capture 11                                 */
  INTCAP20_IRQn                 = 76,        /*!< 16bit TMRB input capture 20                                 */
  INTCAP21_IRQn                 = 77,        /*!< 16bit TMRB input capture 21                                 */
  INTCAP50_IRQn                 = 80,        /*!< 16bit TMRB input capture 50                                 */
  INTCAP51_IRQn                 = 81,        /*!< 16bit TMRB input capture 51                                 */
  INTCAP60_IRQn                 = 82,        /*!< 16bit TMRB input capture 60                                 */
  INTCAP61_IRQn                 = 83,        /*!< 16bit TMRB input capture 61                                 */
  INTCAP70_IRQn                 = 84,        /*!< 16bit TMRB input capture 70                                 */
  INTCAP71_IRQn                 = 85,        /*!< 16bit TMRB input capture 71                                 */
  INTCAP90_IRQn                 = 86,        /*!< 16bit TMRB input capture 90                                 */
  INTCAP91_IRQn                 = 87,        /*!< 16bit TMRB input capture 91                                 */
  INTDMACERR_IRQn               = 98,        /*!< DMA transmission error                                      */
  INTDMACTC0_IRQn               = 99         /*!< DMA transmission completion                                 */
} IRQn_Type;

/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV              0x0200       /*!< Cortex-M3 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals            */
#include "system_TMPM361.h"                 /* TMPM361 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief Single Master DMA Controller (DMAC)
  */
typedef struct
{
  __I  uint32_t INTSTATUS;         /*!< DMAC Interrupt Status Register               */
  __I  uint32_t INTTCSTATUS;       /*!< DMAC Interrupt Terminal Count Status Register*/
  __O  uint32_t INTTCCLEAR;        /*!< DMAC Interrupt Terminal Count Clear Register */
  __I  uint32_t INTERRORSTATUS;    /*!< DMAC Interrupt Error Status Register         */
  __O  uint32_t INTERRCLR;         /*!< DMAC Interrupt Error Clear Register          */
  __I  uint32_t RAWINTTCSTATUS;    /*!< DMAC Raw Interrupt Terminal Count Status Register*/
  __I  uint32_t RAWINTERRORSTATUS; /*!< DMAC Raw Error Interrupt Status Register     */
  __I  uint32_t ENBLDCHNS;         /*!< DMAC Enabled Channel Register                */
  __IO uint32_t SOFTBREQ;          /*!< DMAC Software Burst Request Register         */
  __IO uint32_t SOFTSREQ;          /*!< DMAC Software Single Request Register        */
       uint32_t RESERVED0[2];
  __IO uint32_t CONFIGURATION;     /*!< DMAC Configuration Register                  */
       uint32_t RESERVED1[51];
  __IO uint32_t C0SRCADDR;         /*!< DMAC Channel0 Source Address Register        */
  __IO uint32_t C0DESTADDR;        /*!< DMAC Channel0 Destination Address Register   */
  __IO uint32_t C0LLI;             /*!< DMAC Channel0 Linked List Item Register      */
  __IO uint32_t C0CONTROL;         /*!< DMAC Channel0 Control Register               */
  __IO uint32_t C0CONFIGURATION;   /*!< DMAC Channel0 Configuration Register         */
       uint32_t RESERVED2[3];
  __IO uint32_t C1SRCADDR;         /*!< DMAC Channel1 Source Address Register        */
  __IO uint32_t C1DESTADDR;        /*!< DMAC Channel1 Destination Address Register   */
  __IO uint32_t C1LLI;             /*!< DMAC Channel1 Linked List Item Register      */
  __IO uint32_t C1CONTROL;         /*!< DMAC Channel1 Control Register               */
  __IO uint32_t C1CONFIGURATION;   /*!< DMAC Channel1 Configuration Register         */
} TSB_DMAC_TypeDef;

/**
  * @brief Static Memory Controller (SMC)
  */
typedef struct
{
       uint32_t RESERVED0;
  __I  uint32_t MEMIF_CFG;         /*!< SMC Memory Interface Configuration Register  */
       uint32_t RESERVED1[2];
  __O  uint32_t DIRECT_CMD;        /*!< SMC Direct Command Register                  */
  __O  uint32_t SET_CYCLES;        /*!< SMC Set Cycles Register                      */
  __O  uint32_t SET_OPMODE;        /*!< SMC Set Opmode Register                      */
       uint32_t RESERVED2[57];
  __I  uint32_t SRAM_CYCLES0_0;    /*!< SMC SRAM Cycles Register 0_0                 */
  __I  uint32_t OPMODE0_0;         /*!< SMC Opmode Register 0_0                      */
       uint32_t RESERVED3[6];
  __I  uint32_t SRAM_CYCLES0_1;    /*!< SMC SRAM Cycles Register 0_1                 */
  __I  uint32_t OPMODE0_1;         /*!< SMC Opmode Register 0_1                      */
       uint32_t RESERVED4[6];
  __I  uint32_t SRAM_CYCLES0_2;    /*!< SMC SRAM Cycles Register 0_2                 */
  __I  uint32_t OPMODE0_2;         /*!< SMC Opmode Register 0_2                      */
       uint32_t RESERVED5[6];
  __I  uint32_t SRAM_CYCLES0_3;    /*!< SMC SRAM Cycles Register 0_3                 */
  __I  uint32_t OPMODE0_3;         /*!< SMC Opmode Register 0_3                      */
} TSB_SMC_TypeDef;

/**
  * @brief Synchronous Serial Port (SSP)
  */
typedef struct
{
  __IO uint32_t CR0;               /*!< SSP Control Register 0                       */
  __IO uint32_t CR1;               /*!< SSP Control Register 1                       */
  __IO uint32_t DR;                /*!< SSP Data Register                            */
  __I  uint32_t SR;                /*!< SSP Status Register                          */
  __IO uint32_t CPSR;              /*!< SSP Clock Prescaler Register                 */
  __IO uint32_t IMSC;              /*!< SSP Interrupt Mask Set and Clear Register    */
  __I  uint32_t RIS;               /*!< SSP Raw Interrupt Status Register            */
  __I  uint32_t MIS;               /*!< SSP Masked Interrupt Status Register         */
  __O  uint32_t ICR;               /*!< SSP Interrupt Clear Register                 */
  __IO uint32_t DMACR;             /*!< SSP DMA Control Register                     */
} TSB_SSP_TypeDef;

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
       uint32_t RESERVED1[2];
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
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PB Input Enable Control Register             */
} TSB_PB_TypeDef;

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
       uint32_t RESERVED1[2];
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
       uint32_t RESERVED1[2];
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
  __IO uint32_t FR3;               /*!< PG Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PG Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PG Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PG Input Enable Control Register             */
} TSB_PG_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PI)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PI Data Register                             */
  __IO uint32_t CR;                /*!< PI Control Register                          */
  __IO uint32_t FR1;               /*!< PI Function Register 1                       */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< PI Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PI Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PI Input Enable Control Register             */
} TSB_PI_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PJ)
  */
typedef struct
{
  __I  uint32_t DATA;              /*!< PJ Data Register                             */
       uint32_t RESERVED0[2];
  __IO uint32_t FR2;               /*!< PJ Function Register 2                       */
       uint32_t RESERVED1[7];
  __IO uint32_t PUP;               /*!< PJ Pull-Up Control Register                  */
       uint32_t RESERVED2[2];
  __IO uint32_t IE;                /*!< PJ Input Enable Control Register             */
} TSB_PJ_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PL)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PL Data Register                             */
  __IO uint32_t CR;                /*!< PL Control Register                          */
  __IO uint32_t FR1;               /*!< PL Function Register 1                       */
  __IO uint32_t FR2;               /*!< PL Function Register 2                       */
  __IO uint32_t FR3;               /*!< PL Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PL Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PL Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PL Input Enable Control Register             */
} TSB_PL_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PM)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PM Data Register                             */
  __IO uint32_t CR;                /*!< PM Control Register                          */
  __IO uint32_t FR1;               /*!< PM Function Register 1                       */
  __IO uint32_t FR2;               /*!< PM Function Register 2                       */
  __IO uint32_t FR3;               /*!< PM Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PM Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PM Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PM Input Enable Control Register             */
} TSB_PM_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PN)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PN Data Register                             */
  __IO uint32_t CR;                /*!< PN Control Register                          */
  __IO uint32_t FR1;               /*!< PN Function Register 1                       */
  __IO uint32_t FR2;               /*!< PN Function Register 2                       */
  __IO uint32_t FR3;               /*!< PN Function Register 3                       */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< PN Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PN Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PN Input Enable Control Register             */
} TSB_PN_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PP)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PP Data Register                             */
  __IO uint32_t CR;                /*!< PP Control Register                          */
  __IO uint32_t FR1;               /*!< PP Function Register 1                       */
  __IO uint32_t FR2;               /*!< PP Function Register 2                       */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< PP Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PP Pull-Up Control Register                  */
       uint32_t RESERVED1[2];
  __IO uint32_t IE;                /*!< PP Input Enable Control Register             */
} TSB_PP_TypeDef;

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
  * @brief Consumer Electronics Control (CEC)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< CEC Enable Register                          */
  __IO uint32_t ADD;               /*!< CEC Logical Address Register                 */
  __O  uint32_t RESET;             /*!< CEC Software Reset Register                  */
  __IO uint32_t REN;               /*!< CEC Receive Enable Register                  */
  __I  uint32_t RBUF;              /*!< CEC Receive Buffer Register                  */
  __IO uint32_t RCR1;              /*!< CEC Receive Control Register 1               */
  __IO uint32_t RCR2;              /*!< CEC Receive Control Register 2               */
  __IO uint32_t RCR3;              /*!< CEC Receive Control Register 3               */
  __IO uint32_t TEN;               /*!< CEC Transmit Enable Register                 */
  __IO uint32_t TBUF;              /*!< CEC Transmit Buffer Register                 */
  __IO uint32_t TCR;               /*!< CEC Transmit Control Register                */
  __I  uint32_t RSTAT;             /*!< CEC Receive Interrupt Status Register        */
  __I  uint32_t TSTAT;             /*!< CEC Transmit Interrupt Status Register       */
  __IO uint32_t FSSEL;             /*!< CEC Frequency Select Register                */
} TSB_CEC_TypeDef;

/**
  * @brief Remote Control Signal Preprocessor (RMC)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< RMC Enable Register                          */
  __IO uint32_t REN;               /*!< RMC Receive Enable Register                  */
  __I  uint32_t RBUF1;             /*!< RMC Receive Data Buffer Register 1           */
  __I  uint32_t RBUF2;             /*!< RMC Receive Data Buffer Register 2           */
  __I  uint32_t RBUF3;             /*!< RMC Receive Data Buffer Register 3           */
  __IO uint32_t RCR1;              /*!< RMC Receive Control Register 1               */
  __IO uint32_t RCR2;              /*!< RMC Receive Control Register 2               */
  __IO uint32_t RCR3;              /*!< RMC Receive Control Register 3               */
  __IO uint32_t RCR4;              /*!< RMC Receive Control Register 4               */
  __I  uint32_t RSTAT;             /*!< RMC Receive Status Register                  */
  __IO uint32_t END1;              /*!< RMC Receive End Bit Number Register 1        */
  __IO uint32_t END2;              /*!< RMC Receive End Bit Number Register 2        */
  __IO uint32_t END3;              /*!< RMC Receive End Bit Number Register 3        */
  __IO uint32_t FSSEL;             /*!< RMC Frequency Selection Register             */
} TSB_RMC_TypeDef;

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
       uint32_t RESERVED0;
  __IO uint32_t CBAS;              /*!< AD Conversion Accuracy Setting Register      */
       uint32_t RESERVED1[3];
  __I  uint32_t REG08;             /*!< AD Conversion Result Register 08             */
  __I  uint32_t REG19;             /*!< AD Conversion Result Register 19             */
  __I  uint32_t REG2A;             /*!< AD Conversion Result Register 2A             */
  __I  uint32_t REG3B;             /*!< AD Conversion Result Register 3B             */
  __I  uint32_t REG4C;             /*!< AD Conversion Result Register 4C             */
  __I  uint32_t REG5D;             /*!< AD Conversion Result Register 5D             */
  __I  uint32_t REG6E;             /*!< AD Conversion Result Register 6E             */
  __I  uint32_t REG7F;             /*!< AD Conversion Result Register 7F             */
  __I  uint32_t REGSP;             /*!< AD Conversion Result Register SP             */
  __IO uint32_t CMP0;              /*!< AD Conversion Result Comparison Register 0   */
  __IO uint32_t CMP1;              /*!< AD Conversion Result Comparison Register 1   */
} TSB_AD_TypeDef;

/**
  * @brief Key On Wake Up (KWUP)
  */
typedef struct
{
  __IO uint32_t CR0;               /*!< KWUP Control Register 0                      */
  __IO uint32_t CR1;               /*!< KWUP Control Register 1                      */
  __IO uint32_t CR2;               /*!< KWUP Control Register 2                      */
  __IO uint32_t CR3;               /*!< KWUP Control Register 3                      */
       uint32_t RESERVED0[28];
  __I  uint32_t PKEY;              /*!< KWUP Port Monitor Register                   */
  __IO uint32_t CNT;               /*!< KWUP Control Register                        */
  __O  uint32_t CLR;               /*!< KWUP Interrupt All Clear Register            */
  __I  uint32_t INT;               /*!< KWUP Interrupt Monitor Register              */
} TSB_KWUP_TypeDef;

/**
  * @brief Watchdog Timer (WD)
  */
typedef struct
{
  __IO uint32_t MOD;               /*!< WD Mode Register                             */
  __O  uint32_t CR;                /*!< WD Control Register                          */
} TSB_WD_TypeDef;

/**
  * @brief Real Time Clock (RTC)
  */
typedef struct
{
  __IO uint8_t  SECR;              /*!< RTC Second Column Register                   */
  __IO uint8_t  MINR;              /*!< RTC Minute Column Register                   */
  __IO uint8_t  HOURR;             /*!< RTC Hour Column Register                     */
       uint8_t  RESERVED0;
  __IO uint8_t  DAYR;              /*!< RTC Day of the Week Column Register          */
  __IO uint8_t  DATER;             /*!< RTC Day Column Register                      */
  __IO uint8_t  MONTHR;            /*!< RTC Month Column Register                    */
  __IO uint8_t  YEARR;             /*!< RTC Year Column Register                     */
  __IO uint8_t  PAGER;             /*!< RTC PAGE Register                            */
       uint8_t  RESERVED1[3];
  __IO uint8_t  RESTR;             /*!< RTC Reset Register                           */
} TSB_RTC_TypeDef;

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
       uint32_t RESERVED0;
  __IO uint32_t IMCGD;             /*!< CG Interrupt Mode Control Register D         */
  __IO uint32_t IMCGE;             /*!< CG Interrupt Mode Control Register E         */
  __IO uint32_t IMCGF;             /*!< CG Interrupt Mode Control Register F         */
} TSB_CG_TypeDef;

/**
  * @brief Flash Control (FC)
  */
typedef struct
{
       uint32_t RESERVED0[4];
  __IO uint32_t SECBIT;            /*!< FC Security Bit Register                     */
       uint32_t RESERVED1[3];
  __I  uint32_t FLCS;              /*!< FC Flash Control Register                    */
} TSB_FC_TypeDef;

/**
  * @brief RAM Control (RC)
  */
typedef struct
{
  __IO uint32_t WAIT;              /*!< RAM WAIT Control Register                    */
} TSB_RC_TypeDef;

/**
  * @brief Static Memory Controller Mode (SMCMD)
  */
typedef struct
{
  __IO uint32_t MODE;              /*!< SMC Mode Register                            */
} TSB_SMCMD_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)


#define TSB_DMAC_BASE              (PERI_BASE  + 0x0000000UL)
#define TSB_SMC_BASE               (PERI_BASE  + 0x0001000UL)
#define TSB_SSP_BASE               (PERI_BASE  + 0x0040000UL)
#define TSB_PA_BASE                (PERI_BASE  + 0x00C0000UL)
#define TSB_PB_BASE                (PERI_BASE  + 0x00C0100UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x00C0400UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x00C0500UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x00C0600UL)
#define TSB_PI_BASE                (PERI_BASE  + 0x00C0800UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x00C0900UL)
#define TSB_PL_BASE                (PERI_BASE  + 0x00C0B00UL)
#define TSB_PM_BASE                (PERI_BASE  + 0x00C0C00UL)
#define TSB_PN_BASE                (PERI_BASE  + 0x00C0D00UL)
#define TSB_PP_BASE                (PERI_BASE  + 0x00C0F00UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x00D0000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x00D0100UL)
#define TSB_TB2_BASE               (PERI_BASE  + 0x00D0200UL)
#define TSB_TB3_BASE               (PERI_BASE  + 0x00D0300UL)
#define TSB_TB4_BASE               (PERI_BASE  + 0x00D0400UL)
#define TSB_TB5_BASE               (PERI_BASE  + 0x00D0500UL)
#define TSB_TB6_BASE               (PERI_BASE  + 0x00D0600UL)
#define TSB_TB7_BASE               (PERI_BASE  + 0x00D0700UL)
#define TSB_TB8_BASE               (PERI_BASE  + 0x00D0800UL)
#define TSB_TB9_BASE               (PERI_BASE  + 0x00D0900UL)
#define TSB_TBA_BASE               (PERI_BASE  + 0x00D0A00UL)
#define TSB_TBB_BASE               (PERI_BASE  + 0x00D0B00UL)
#define TSB_TBC_BASE               (PERI_BASE  + 0x00D0C00UL)
#define TSB_TBD_BASE               (PERI_BASE  + 0x00D0D00UL)
#define TSB_TBE_BASE               (PERI_BASE  + 0x00D0E00UL)
#define TSB_TBF_BASE               (PERI_BASE  + 0x00D0F00UL)
#define TSB_SBI0_BASE              (PERI_BASE  + 0x00E0000UL)
#define TSB_SBI1_BASE              (PERI_BASE  + 0x00E0100UL)
#define TSB_SBI2_BASE              (PERI_BASE  + 0x00E0200UL)
#define TSB_SBI3_BASE              (PERI_BASE  + 0x00E0300UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x00E1000UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00E1100UL)
#define TSB_SC2_BASE               (PERI_BASE  + 0x00E1200UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x00E1300UL)
#define TSB_SC4_BASE               (PERI_BASE  + 0x00E1400UL)
#define TSB_CEC_BASE               (PERI_BASE  + 0x00E2000UL)
#define TSB_RMC0_BASE              (PERI_BASE  + 0x00E3000UL)
#define TSB_AD_BASE                (PERI_BASE  + 0x00F0000UL)
#define TSB_KWUP_BASE              (PERI_BASE  + 0x00F1000UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x00F2000UL)
#define TSB_RTC_BASE               (PERI_BASE  + 0x00F3000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x00F4000UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1FFF000UL)
#define TSB_RC_BASE                (PERI_BASE  + 0x1FFF058UL)
#define TSB_SMCMD_BASE             (PERI_BASE  + 0x1FFF100UL)


/* Peripheral declaration */
#define TSB_DMAC                   ((   TSB_DMAC_TypeDef *)  TSB_DMAC_BASE)
#define TSB_SMC                    ((    TSB_SMC_TypeDef *)   TSB_SMC_BASE)
#define TSB_SSP                    ((    TSB_SSP_TypeDef *)   TSB_SSP_BASE)
#define TSB_PA                     ((     TSB_PA_TypeDef *)    TSB_PA_BASE)
#define TSB_PB                     ((     TSB_PB_TypeDef *)    TSB_PB_BASE)
#define TSB_PE                     ((     TSB_PE_TypeDef *)    TSB_PE_BASE)
#define TSB_PF                     ((     TSB_PF_TypeDef *)    TSB_PF_BASE)
#define TSB_PG                     ((     TSB_PG_TypeDef *)    TSB_PG_BASE)
#define TSB_PI                     ((     TSB_PI_TypeDef *)    TSB_PI_BASE)
#define TSB_PJ                     ((     TSB_PJ_TypeDef *)    TSB_PJ_BASE)
#define TSB_PL                     ((     TSB_PL_TypeDef *)    TSB_PL_BASE)
#define TSB_PM                     ((     TSB_PM_TypeDef *)    TSB_PM_BASE)
#define TSB_PN                     ((     TSB_PN_TypeDef *)    TSB_PN_BASE)
#define TSB_PP                     ((     TSB_PP_TypeDef *)    TSB_PP_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_TB2                    ((     TSB_TB_TypeDef *)   TSB_TB2_BASE)
#define TSB_TB3                    ((     TSB_TB_TypeDef *)   TSB_TB3_BASE)
#define TSB_TB4                    ((     TSB_TB_TypeDef *)   TSB_TB4_BASE)
#define TSB_TB5                    ((     TSB_TB_TypeDef *)   TSB_TB5_BASE)
#define TSB_TB6                    ((     TSB_TB_TypeDef *)   TSB_TB6_BASE)
#define TSB_TB7                    ((     TSB_TB_TypeDef *)   TSB_TB7_BASE)
#define TSB_TB8                    ((     TSB_TB_TypeDef *)   TSB_TB8_BASE)
#define TSB_TB9                    ((     TSB_TB_TypeDef *)   TSB_TB9_BASE)
#define TSB_TBA                    ((     TSB_TB_TypeDef *)   TSB_TBA_BASE)
#define TSB_TBB                    ((     TSB_TB_TypeDef *)   TSB_TBB_BASE)
#define TSB_TBC                    ((     TSB_TB_TypeDef *)   TSB_TBC_BASE)
#define TSB_TBD                    ((     TSB_TB_TypeDef *)   TSB_TBD_BASE)
#define TSB_TBE                    ((     TSB_TB_TypeDef *)   TSB_TBE_BASE)
#define TSB_TBF                    ((     TSB_TB_TypeDef *)   TSB_TBF_BASE)
#define TSB_SBI0                   ((    TSB_SBI_TypeDef *)  TSB_SBI0_BASE)
#define TSB_SBI1                   ((    TSB_SBI_TypeDef *)  TSB_SBI1_BASE)
#define TSB_SBI2                   ((    TSB_SBI_TypeDef *)  TSB_SBI2_BASE)
#define TSB_SBI3                   ((    TSB_SBI_TypeDef *)  TSB_SBI3_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC2                    ((     TSB_SC_TypeDef *)   TSB_SC2_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_SC4                    ((     TSB_SC_TypeDef *)   TSB_SC4_BASE)
#define TSB_CEC                    ((    TSB_CEC_TypeDef *)   TSB_CEC_BASE)
#define TSB_RMC0                   ((    TSB_RMC_TypeDef *)  TSB_RMC0_BASE)
#define TSB_AD                     ((     TSB_AD_TypeDef *)    TSB_AD_BASE)
#define TSB_KWUP                   ((   TSB_KWUP_TypeDef *)  TSB_KWUP_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_RTC                    ((    TSB_RTC_TypeDef *)   TSB_RTC_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)
#define TSB_RC                     ((     TSB_RC_TypeDef *)    TSB_RC_BASE)
#define TSB_SMCMD                  ((  TSB_SMCMD_TypeDef *) TSB_SMCMD_BASE)


/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/* Single Master DMA Controller (DMAC) */
#define TSB_DMAC_INTSTATUS_INTSTATUS0             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTSTATUS,0)))
#define TSB_DMAC_INTSTATUS_INTSTATUS1             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTSTATUS,1)))
#define TSB_DMAC_INTTCSTATUS_INTTCSTATUS0         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTTCSTATUS,0)))
#define TSB_DMAC_INTTCSTATUS_INTTCSTATUS1         (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTTCSTATUS,1)))
#define TSB_DMAC_INTERRORSTATUS_INTERRSTATUS0     (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTERRORSTATUS,0)))
#define TSB_DMAC_INTERRORSTATUS_INTERRSTATUS1     (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->INTERRORSTATUS,1)))
#define TSB_DMAC_RAWINTTCSTATUS_RAWINTTCS0        (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->RAWINTTCSTATUS,0)))
#define TSB_DMAC_RAWINTTCSTATUS_RAWINTTCS1        (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->RAWINTTCSTATUS,1)))
#define TSB_DMAC_RAWINTERRORSTATUS_RAWINTERRS0    (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->RAWINTERRORSTATUS,0)))
#define TSB_DMAC_RAWINTERRORSTATUS_RAWINTERRS1    (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->RAWINTERRORSTATUS,1)))
#define TSB_DMAC_ENBLDCHNS_ENABLEDCH0             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->ENBLDCHNS,0)))
#define TSB_DMAC_ENBLDCHNS_ENABLEDCH1             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->ENBLDCHNS,1)))
#define TSB_DMAC_C0CONFIGURATION_ACTIVE           (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->C0CONFIGURATION,17)))
#define TSB_DMAC_C1CONFIGURATION_ACTIVE           (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAC->C1CONFIGURATION,17)))


/* Static Memory Controller (SMC) */
#define TSB_SMC_OPMODE0_0_ADV                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_SMC->OPMODE0_0,11)))
#define TSB_SMC_OPMODE0_1_ADV                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_SMC->OPMODE0_1,11)))
#define TSB_SMC_OPMODE0_2_ADV                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_SMC->OPMODE0_2,11)))
#define TSB_SMC_OPMODE0_3_ADV                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_SMC->OPMODE0_3,11)))


/* Synchronous Serial Port (SSP) */
#define TSB_SSP_SR_TFE                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->SR,0)))
#define TSB_SSP_SR_TNF                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->SR,1)))
#define TSB_SSP_SR_RNE                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->SR,2)))
#define TSB_SSP_SR_RFF                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->SR,3)))
#define TSB_SSP_SR_BSY                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->SR,4)))
#define TSB_SSP_RIS_RORRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->RIS,0)))
#define TSB_SSP_RIS_RTRIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->RIS,1)))
#define TSB_SSP_RIS_RXRIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->RIS,2)))
#define TSB_SSP_RIS_TXRIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->RIS,3)))
#define TSB_SSP_MIS_RORMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->MIS,0)))
#define TSB_SSP_MIS_RTMIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->MIS,1)))
#define TSB_SSP_MIS_RXMIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->MIS,2)))
#define TSB_SSP_MIS_TXMIS                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP->MIS,3)))


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
#define TSB_PB_IE_PB0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,0)))
#define TSB_PB_IE_PB1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,1)))
#define TSB_PB_IE_PB2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,2)))
#define TSB_PB_IE_PB3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))
#define TSB_PB_IE_PB7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,7)))


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
#define TSB_PE_FR2_PE0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,0)))
#define TSB_PE_FR2_PE1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,1)))
#define TSB_PE_FR2_PE2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_FR2_PE3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,3)))
#define TSB_PE_FR2_PE4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,4)))
#define TSB_PE_FR2_PE5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,5)))
#define TSB_PE_FR2_PE6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,6)))
#define TSB_PE_FR2_PE7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,7)))
#define TSB_PE_FR3_PE6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,6)))
#define TSB_PE_FR3_PE7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,7)))
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
#define TSB_PG_FR2_PG0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,0)))
#define TSB_PG_FR2_PG1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,1)))
#define TSB_PG_FR2_PG4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,4)))
#define TSB_PG_FR2_PG5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,5)))
#define TSB_PG_FR3_PG2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,2)))
#define TSB_PG_FR3_PG3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,3)))
#define TSB_PG_FR3_PG6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,6)))
#define TSB_PG_FR3_PG7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,7)))
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
#define TSB_PG_IE_PG0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,0)))
#define TSB_PG_IE_PG1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,1)))
#define TSB_PG_IE_PG2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,2)))
#define TSB_PG_IE_PG3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,3)))
#define TSB_PG_IE_PG4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,4)))
#define TSB_PG_IE_PG5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,5)))
#define TSB_PG_IE_PG6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,6)))
#define TSB_PG_IE_PG7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,7)))


/* General Purpose Input/Output Port (PI) */
#define TSB_PI_DATA_PI0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,0)))
#define TSB_PI_DATA_PI1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,1)))
#define TSB_PI_DATA_PI2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,2)))
#define TSB_PI_DATA_PI3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,3)))
#define TSB_PI_CR_PI0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,0)))
#define TSB_PI_CR_PI1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,1)))
#define TSB_PI_CR_PI2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,2)))
#define TSB_PI_CR_PI3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_FR1_PI1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,1)))
#define TSB_PI_FR1_PI2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,2)))
#define TSB_PI_FR1_PI3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,3)))
#define TSB_PI_OD_PI0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,0)))
#define TSB_PI_OD_PI2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,2)))
#define TSB_PI_OD_PI3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,3)))
#define TSB_PI_PUP_PI0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,0)))
#define TSB_PI_IE_PI0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,0)))
#define TSB_PI_IE_PI1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,1)))
#define TSB_PI_IE_PI2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,2)))
#define TSB_PI_IE_PI3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))


/* General Purpose Input/Output Port (PJ) */
#define TSB_PJ_DATA_PJ0                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ1                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,1)))
#define TSB_PJ_DATA_PJ2                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,2)))
#define TSB_PJ_DATA_PJ3                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,3)))
#define TSB_PJ_DATA_PJ4                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,4)))
#define TSB_PJ_DATA_PJ5                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,5)))
#define TSB_PJ_DATA_PJ6                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,6)))
#define TSB_PJ_DATA_PJ7                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,7)))
#define TSB_PJ_FR2_PJ3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,3)))
#define TSB_PJ_FR2_PJ4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,4)))
#define TSB_PJ_FR2_PJ5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,5)))
#define TSB_PJ_FR2_PJ6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,6)))
#define TSB_PJ_FR2_PJ7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->FR2,7)))
#define TSB_PJ_PUP_PJ0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,1)))
#define TSB_PJ_PUP_PJ2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,2)))
#define TSB_PJ_PUP_PJ3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,3)))
#define TSB_PJ_PUP_PJ4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,4)))
#define TSB_PJ_PUP_PJ5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,5)))
#define TSB_PJ_PUP_PJ6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,6)))
#define TSB_PJ_PUP_PJ7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,7)))
#define TSB_PJ_IE_PJ0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,1)))
#define TSB_PJ_IE_PJ2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,2)))
#define TSB_PJ_IE_PJ3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,3)))
#define TSB_PJ_IE_PJ4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,4)))
#define TSB_PJ_IE_PJ5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,5)))
#define TSB_PJ_IE_PJ6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,6)))
#define TSB_PJ_IE_PJ7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,7)))


/* General Purpose Input/Output Port (PL) */
#define TSB_PL_DATA_PL0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,0)))
#define TSB_PL_DATA_PL1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,1)))
#define TSB_PL_DATA_PL2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,2)))
#define TSB_PL_DATA_PL3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,3)))
#define TSB_PL_DATA_PL4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,4)))
#define TSB_PL_DATA_PL5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,5)))
#define TSB_PL_DATA_PL6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,6)))
#define TSB_PL_DATA_PL7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,7)))
#define TSB_PL_CR_PL0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,0)))
#define TSB_PL_CR_PL1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,1)))
#define TSB_PL_CR_PL2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,2)))
#define TSB_PL_CR_PL3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,3)))
#define TSB_PL_CR_PL4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,4)))
#define TSB_PL_CR_PL5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,5)))
#define TSB_PL_CR_PL6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,6)))
#define TSB_PL_CR_PL7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,7)))
#define TSB_PL_FR1_PL0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,0)))
#define TSB_PL_FR1_PL1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,1)))
#define TSB_PL_FR1_PL2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,2)))
#define TSB_PL_FR1_PL3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,3)))
#define TSB_PL_FR1_PL4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,4)))
#define TSB_PL_FR1_PL5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,5)))
#define TSB_PL_FR1_PL6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,6)))
#define TSB_PL_FR1_PL7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,7)))
#define TSB_PL_FR2_PL0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,0)))
#define TSB_PL_FR2_PL1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,1)))
#define TSB_PL_FR2_PL2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,2)))
#define TSB_PL_FR2_PL3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,3)))
#define TSB_PL_FR2_PL4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,4)))
#define TSB_PL_FR2_PL5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,5)))
#define TSB_PL_FR2_PL6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,6)))
#define TSB_PL_FR2_PL7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR2,7)))
#define TSB_PL_FR3_PL4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,4)))
#define TSB_PL_FR3_PL5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,5)))
#define TSB_PL_FR3_PL6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,6)))
#define TSB_PL_OD_PL0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,0)))
#define TSB_PL_OD_PL1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,1)))
#define TSB_PL_OD_PL2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,2)))
#define TSB_PL_OD_PL3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,3)))
#define TSB_PL_OD_PL4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,4)))
#define TSB_PL_OD_PL5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,5)))
#define TSB_PL_OD_PL6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,6)))
#define TSB_PL_OD_PL7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,7)))
#define TSB_PL_PUP_PL0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,0)))
#define TSB_PL_PUP_PL1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,1)))
#define TSB_PL_PUP_PL2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,2)))
#define TSB_PL_PUP_PL3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,3)))
#define TSB_PL_PUP_PL4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,4)))
#define TSB_PL_PUP_PL5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,5)))
#define TSB_PL_PUP_PL6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,6)))
#define TSB_PL_PUP_PL7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,7)))
#define TSB_PL_IE_PL0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,0)))
#define TSB_PL_IE_PL1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,1)))
#define TSB_PL_IE_PL2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,2)))
#define TSB_PL_IE_PL3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,3)))
#define TSB_PL_IE_PL4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,4)))
#define TSB_PL_IE_PL5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,5)))
#define TSB_PL_IE_PL6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,6)))
#define TSB_PL_IE_PL7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,7)))


/* General Purpose Input/Output Port (PM) */
#define TSB_PM_DATA_PM0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,0)))
#define TSB_PM_DATA_PM1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,1)))
#define TSB_PM_DATA_PM2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,2)))
#define TSB_PM_DATA_PM3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,3)))
#define TSB_PM_DATA_PM4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,4)))
#define TSB_PM_DATA_PM5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,5)))
#define TSB_PM_DATA_PM6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,6)))
#define TSB_PM_DATA_PM7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->DATA,7)))
#define TSB_PM_CR_PM0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,0)))
#define TSB_PM_CR_PM1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,1)))
#define TSB_PM_CR_PM2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,2)))
#define TSB_PM_CR_PM3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,3)))
#define TSB_PM_CR_PM4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,4)))
#define TSB_PM_CR_PM5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,5)))
#define TSB_PM_CR_PM6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,6)))
#define TSB_PM_CR_PM7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,7)))
#define TSB_PM_FR1_PM0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,0)))
#define TSB_PM_FR1_PM1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,1)))
#define TSB_PM_FR1_PM2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,2)))
#define TSB_PM_FR1_PM3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,3)))
#define TSB_PM_FR1_PM4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,4)))
#define TSB_PM_FR1_PM5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,5)))
#define TSB_PM_FR1_PM6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,6)))
#define TSB_PM_FR1_PM7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,7)))
#define TSB_PM_FR2_PM0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,0)))
#define TSB_PM_FR2_PM1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,1)))
#define TSB_PM_FR2_PM2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,2)))
#define TSB_PM_FR2_PM3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,3)))
#define TSB_PM_FR3_PM0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR3,0)))
#define TSB_PM_FR3_PM4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR3,4)))
#define TSB_PM_OD_PM0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,0)))
#define TSB_PM_OD_PM1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,1)))
#define TSB_PM_OD_PM2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,2)))
#define TSB_PM_OD_PM3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,3)))
#define TSB_PM_OD_PM4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,4)))
#define TSB_PM_OD_PM5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,5)))
#define TSB_PM_OD_PM6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,6)))
#define TSB_PM_OD_PM7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,7)))
#define TSB_PM_PUP_PM0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,0)))
#define TSB_PM_PUP_PM1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,1)))
#define TSB_PM_PUP_PM2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,2)))
#define TSB_PM_PUP_PM3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,3)))
#define TSB_PM_PUP_PM4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,4)))
#define TSB_PM_PUP_PM5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,5)))
#define TSB_PM_PUP_PM6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,6)))
#define TSB_PM_PUP_PM7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,7)))
#define TSB_PM_IE_PM0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,0)))
#define TSB_PM_IE_PM1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,1)))
#define TSB_PM_IE_PM2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,2)))
#define TSB_PM_IE_PM3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,3)))
#define TSB_PM_IE_PM4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,4)))
#define TSB_PM_IE_PM5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,5)))
#define TSB_PM_IE_PM6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,6)))
#define TSB_PM_IE_PM7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,7)))


/* General Purpose Input/Output Port (PN) */
#define TSB_PN_DATA_PN0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,0)))
#define TSB_PN_DATA_PN1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,1)))
#define TSB_PN_DATA_PN2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,2)))
#define TSB_PN_DATA_PN3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,3)))
#define TSB_PN_CR_PN0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,0)))
#define TSB_PN_CR_PN1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,1)))
#define TSB_PN_CR_PN2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,2)))
#define TSB_PN_CR_PN3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,3)))
#define TSB_PN_FR1_PN0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,0)))
#define TSB_PN_FR1_PN1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,1)))
#define TSB_PN_FR1_PN2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,2)))
#define TSB_PN_FR1_PN3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,3)))
#define TSB_PN_FR2_PN2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,2)))
#define TSB_PN_FR2_PN3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,3)))
#define TSB_PN_FR3_PN2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR3,2)))
#define TSB_PN_FR3_PN3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR3,3)))
#define TSB_PN_OD_PN0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,0)))
#define TSB_PN_OD_PN1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,1)))
#define TSB_PN_OD_PN2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,2)))
#define TSB_PN_OD_PN3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,3)))
#define TSB_PN_PUP_PN0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,0)))
#define TSB_PN_PUP_PN1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,1)))
#define TSB_PN_PUP_PN2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,2)))
#define TSB_PN_PUP_PN3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,3)))
#define TSB_PN_IE_PN0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,0)))
#define TSB_PN_IE_PN1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,1)))
#define TSB_PN_IE_PN2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,2)))
#define TSB_PN_IE_PN3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,3)))


/* General Purpose Input/Output Port (PP) */
#define TSB_PP_DATA_PP0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,0)))
#define TSB_PP_DATA_PP1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,1)))
#define TSB_PP_DATA_PP2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,2)))
#define TSB_PP_DATA_PP3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,3)))
#define TSB_PP_DATA_PP4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,4)))
#define TSB_PP_DATA_PP5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,5)))
#define TSB_PP_DATA_PP6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,6)))
#define TSB_PP_CR_PP0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,0)))
#define TSB_PP_CR_PP1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,1)))
#define TSB_PP_CR_PP2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,2)))
#define TSB_PP_CR_PP3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,3)))
#define TSB_PP_CR_PP4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,4)))
#define TSB_PP_CR_PP5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,5)))
#define TSB_PP_CR_PP6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,6)))
#define TSB_PP_FR1_PP0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,0)))
#define TSB_PP_FR1_PP1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,1)))
#define TSB_PP_FR1_PP2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,2)))
#define TSB_PP_FR1_PP3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,3)))
#define TSB_PP_FR1_PP4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,4)))
#define TSB_PP_FR1_PP5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,5)))
#define TSB_PP_FR1_PP6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR1,6)))
#define TSB_PP_FR2_PP2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR2,2)))
#define TSB_PP_FR2_PP3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR2,3)))
#define TSB_PP_FR2_PP4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR2,4)))
#define TSB_PP_FR2_PP5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->FR2,5)))
#define TSB_PP_OD_PP0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,0)))
#define TSB_PP_OD_PP1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,1)))
#define TSB_PP_OD_PP2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,2)))
#define TSB_PP_OD_PP3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,3)))
#define TSB_PP_OD_PP4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,4)))
#define TSB_PP_OD_PP5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,5)))
#define TSB_PP_OD_PP6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,6)))
#define TSB_PP_PUP_PP0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,0)))
#define TSB_PP_PUP_PP1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,1)))
#define TSB_PP_PUP_PP2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,2)))
#define TSB_PP_PUP_PP3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,3)))
#define TSB_PP_PUP_PP4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,4)))
#define TSB_PP_PUP_PP5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,5)))
#define TSB_PP_PUP_PP6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,6)))
#define TSB_PP_IE_PP0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,0)))
#define TSB_PP_IE_PP1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,1)))
#define TSB_PP_IE_PP2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,2)))
#define TSB_PP_IE_PP3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,3)))
#define TSB_PP_IE_PP4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,4)))
#define TSB_PP_IE_PP5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,5)))
#define TSB_PP_IE_PP6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,6)))


/* 16-bit Timer/Event Counter (TB) */
#define TSB_TB0_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,3)))
#define TSB_TB0_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,5)))
#define TSB_TB0_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,7)))
#define TSB_TB0_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,2)))
#define TSB_TB0_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,5)))
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
#define TSB_TB1_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,3)))
#define TSB_TB1_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,5)))
#define TSB_TB1_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,7)))
#define TSB_TB1_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,2)))
#define TSB_TB1_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,5)))
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
#define TSB_TB2_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,3)))
#define TSB_TB2_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,5)))
#define TSB_TB2_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,7)))
#define TSB_TB2_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,2)))
#define TSB_TB2_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,5)))
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
#define TSB_TB3_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,3)))
#define TSB_TB3_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,5)))
#define TSB_TB3_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,7)))
#define TSB_TB3_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,2)))
#define TSB_TB3_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,5)))
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
#define TSB_TB4_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,3)))
#define TSB_TB4_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,5)))
#define TSB_TB4_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,7)))
#define TSB_TB4_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,2)))
#define TSB_TB4_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,5)))
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
#define TSB_TB5_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,3)))
#define TSB_TB5_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,5)))
#define TSB_TB5_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,7)))
#define TSB_TB5_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,2)))
#define TSB_TB5_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,5)))
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
#define TSB_TB6_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,3)))
#define TSB_TB6_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,5)))
#define TSB_TB6_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,7)))
#define TSB_TB6_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,2)))
#define TSB_TB6_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,5)))
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
#define TSB_TB7_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,3)))
#define TSB_TB7_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,5)))
#define TSB_TB7_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,7)))
#define TSB_TB7_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,2)))
#define TSB_TB7_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,5)))
#define TSB_TB7_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,2)))
#define TSB_TB7_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,3)))
#define TSB_TB7_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,4)))
#define TSB_TB7_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,5)))
#define TSB_TB7_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,0)))
#define TSB_TB7_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,1)))
#define TSB_TB7_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,2)))

#define TSB_TB8_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->EN,7)))
#define TSB_TB8_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,0)))
#define TSB_TB8_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,2)))
#define TSB_TB8_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,3)))
#define TSB_TB8_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,5)))
#define TSB_TB8_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,7)))
#define TSB_TB8_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,2)))
#define TSB_TB8_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,5)))
#define TSB_TB8_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,2)))
#define TSB_TB8_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,3)))
#define TSB_TB8_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,4)))
#define TSB_TB8_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,5)))
#define TSB_TB8_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,0)))
#define TSB_TB8_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,1)))
#define TSB_TB8_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,2)))

#define TSB_TB9_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->EN,7)))
#define TSB_TB9_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,0)))
#define TSB_TB9_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,2)))
#define TSB_TB9_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,3)))
#define TSB_TB9_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,5)))
#define TSB_TB9_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,7)))
#define TSB_TB9_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,2)))
#define TSB_TB9_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,5)))
#define TSB_TB9_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,2)))
#define TSB_TB9_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,3)))
#define TSB_TB9_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,4)))
#define TSB_TB9_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,5)))
#define TSB_TB9_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,0)))
#define TSB_TB9_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,1)))
#define TSB_TB9_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,2)))

#define TSB_TBA_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->EN,7)))
#define TSB_TBA_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->RUN,0)))
#define TSB_TBA_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->RUN,2)))
#define TSB_TBA_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->CR,3)))
#define TSB_TBA_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->CR,5)))
#define TSB_TBA_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->CR,7)))
#define TSB_TBA_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->MOD,2)))
#define TSB_TBA_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBA->MOD,5)))
#define TSB_TBA_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->FFCR,2)))
#define TSB_TBA_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->FFCR,3)))
#define TSB_TBA_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->FFCR,4)))
#define TSB_TBA_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->FFCR,5)))
#define TSB_TBA_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->IM,0)))
#define TSB_TBA_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->IM,1)))
#define TSB_TBA_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBA->IM,2)))

#define TSB_TBB_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->EN,7)))
#define TSB_TBB_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->RUN,0)))
#define TSB_TBB_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->RUN,2)))
#define TSB_TBB_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->CR,3)))
#define TSB_TBB_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->CR,5)))
#define TSB_TBB_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->CR,7)))
#define TSB_TBB_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->MOD,2)))
#define TSB_TBB_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBB->MOD,5)))
#define TSB_TBB_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->FFCR,2)))
#define TSB_TBB_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->FFCR,3)))
#define TSB_TBB_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->FFCR,4)))
#define TSB_TBB_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->FFCR,5)))
#define TSB_TBB_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->IM,0)))
#define TSB_TBB_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->IM,1)))
#define TSB_TBB_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBB->IM,2)))

#define TSB_TBC_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->EN,7)))
#define TSB_TBC_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->RUN,0)))
#define TSB_TBC_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->RUN,2)))
#define TSB_TBC_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->CR,3)))
#define TSB_TBC_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->CR,5)))
#define TSB_TBC_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->CR,7)))
#define TSB_TBC_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->MOD,2)))
#define TSB_TBC_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBC->MOD,5)))
#define TSB_TBC_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->FFCR,2)))
#define TSB_TBC_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->FFCR,3)))
#define TSB_TBC_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->FFCR,4)))
#define TSB_TBC_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->FFCR,5)))
#define TSB_TBC_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->IM,0)))
#define TSB_TBC_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->IM,1)))
#define TSB_TBC_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBC->IM,2)))

#define TSB_TBD_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->EN,7)))
#define TSB_TBD_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->RUN,0)))
#define TSB_TBD_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->RUN,2)))
#define TSB_TBD_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->CR,3)))
#define TSB_TBD_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->CR,5)))
#define TSB_TBD_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->CR,7)))
#define TSB_TBD_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->MOD,2)))
#define TSB_TBD_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBD->MOD,5)))
#define TSB_TBD_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->FFCR,2)))
#define TSB_TBD_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->FFCR,3)))
#define TSB_TBD_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->FFCR,4)))
#define TSB_TBD_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->FFCR,5)))
#define TSB_TBD_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->IM,0)))
#define TSB_TBD_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->IM,1)))
#define TSB_TBD_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBD->IM,2)))

#define TSB_TBE_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->EN,7)))
#define TSB_TBE_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->RUN,0)))
#define TSB_TBE_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->RUN,2)))
#define TSB_TBE_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->CR,3)))
#define TSB_TBE_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->CR,5)))
#define TSB_TBE_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->CR,7)))
#define TSB_TBE_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->MOD,2)))
#define TSB_TBE_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBE->MOD,5)))
#define TSB_TBE_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->FFCR,2)))
#define TSB_TBE_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->FFCR,3)))
#define TSB_TBE_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->FFCR,4)))
#define TSB_TBE_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->FFCR,5)))
#define TSB_TBE_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->IM,0)))
#define TSB_TBE_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->IM,1)))
#define TSB_TBE_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBE->IM,2)))

#define TSB_TBF_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->EN,7)))
#define TSB_TBF_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->RUN,0)))
#define TSB_TBF_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->RUN,2)))
#define TSB_TBF_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->CR,3)))
#define TSB_TBF_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->CR,5)))
#define TSB_TBF_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->CR,7)))
#define TSB_TBF_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->MOD,2)))
#define TSB_TBF_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TBF->MOD,5)))
#define TSB_TBF_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->FFCR,2)))
#define TSB_TBF_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->FFCR,3)))
#define TSB_TBF_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->FFCR,4)))
#define TSB_TBF_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->FFCR,5)))
#define TSB_TBF_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->IM,0)))
#define TSB_TBF_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->IM,1)))
#define TSB_TBF_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TBF->IM,2)))


/* Serial Bus Interface (SBI) */
#define TSB_SBI0_CR0_SBIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->CR0,7)))
#define TSB_SBI0_CR1_SWRMON                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->CR1,0)))
#define TSB_SBI0_I2CAR_ALS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->I2CAR,0)))
#define TSB_SBI0_SR_LRB                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,0)))
#define TSB_SBI0_SR_ADO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,1)))
#define TSB_SBI0_SR_AAS                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,2)))
#define TSB_SBI0_SR_AL                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,3)))
#define TSB_SBI0_SR_PIN                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,4)))
#define TSB_SBI0_SR_BB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,5)))
#define TSB_SBI0_SR_TRX                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,6)))
#define TSB_SBI0_SR_MST                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,7)))
#define TSB_SBI0_SR_SEF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,2)))
#define TSB_SBI0_SR_SIOF                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI0->SR,3)))
#define TSB_SBI0_BR0_I2SBI                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI0->BR0,6)))

#define TSB_SBI1_CR0_SBIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->CR0,7)))
#define TSB_SBI1_CR1_SWRMON                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->CR1,0)))
#define TSB_SBI1_I2CAR_ALS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->I2CAR,0)))
#define TSB_SBI1_SR_LRB                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,0)))
#define TSB_SBI1_SR_ADO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,1)))
#define TSB_SBI1_SR_AAS                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,2)))
#define TSB_SBI1_SR_AL                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,3)))
#define TSB_SBI1_SR_PIN                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,4)))
#define TSB_SBI1_SR_BB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,5)))
#define TSB_SBI1_SR_TRX                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,6)))
#define TSB_SBI1_SR_MST                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,7)))
#define TSB_SBI1_SR_SEF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,2)))
#define TSB_SBI1_SR_SIOF                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI1->SR,3)))
#define TSB_SBI1_BR0_I2SBI                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI1->BR0,6)))

#define TSB_SBI2_CR0_SBIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->CR0,7)))
#define TSB_SBI2_CR1_SWRMON                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->CR1,0)))
#define TSB_SBI2_I2CAR_ALS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->I2CAR,0)))
#define TSB_SBI2_SR_LRB                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,0)))
#define TSB_SBI2_SR_ADO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,1)))
#define TSB_SBI2_SR_AAS                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,2)))
#define TSB_SBI2_SR_AL                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,3)))
#define TSB_SBI2_SR_PIN                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,4)))
#define TSB_SBI2_SR_BB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,5)))
#define TSB_SBI2_SR_TRX                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,6)))
#define TSB_SBI2_SR_MST                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,7)))
#define TSB_SBI2_SR_SEF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,2)))
#define TSB_SBI2_SR_SIOF                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI2->SR,3)))
#define TSB_SBI2_BR0_I2SBI                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI2->BR0,6)))

#define TSB_SBI3_CR0_SBIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI3->CR0,7)))
#define TSB_SBI3_CR1_SWRMON                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->CR1,0)))
#define TSB_SBI3_I2CAR_ALS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI3->I2CAR,0)))
#define TSB_SBI3_SR_LRB                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,0)))
#define TSB_SBI3_SR_ADO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,1)))
#define TSB_SBI3_SR_AAS                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,2)))
#define TSB_SBI3_SR_AL                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,3)))
#define TSB_SBI3_SR_PIN                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,4)))
#define TSB_SBI3_SR_BB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,5)))
#define TSB_SBI3_SR_TRX                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,6)))
#define TSB_SBI3_SR_MST                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI3->SR,7)))
#define TSB_SBI3_BR0_I2SBI                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI3->BR0,6)))


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

#define TSB_SC4_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->EN,0)))
#define TSB_SC4_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD0,4)))
#define TSB_SC4_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD0,5)))
#define TSB_SC4_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD0,6)))
#define TSB_SC4_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD0,7)))
#define TSB_SC4_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->BRCR,6)))
#define TSB_SC4_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD1,4)))
#define TSB_SC4_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD1,7)))
#define TSB_SC4_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,2)))
#define TSB_SC4_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,3)))
#define TSB_SC4_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,4)))
#define TSB_SC4_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,5)))
#define TSB_SC4_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,6)))
#define TSB_SC4_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC4->MOD2,7)))
#define TSB_SC4_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->RFC,6)))
#define TSB_SC4_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC4->RFC,7)))
#define TSB_SC4_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->TFC,6)))
#define TSB_SC4_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC4->TFC,7)))
#define TSB_SC4_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC4->RST,7)))
#define TSB_SC4_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC4->TST,7)))
#define TSB_SC4_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->FCNF,0)))
#define TSB_SC4_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->FCNF,1)))
#define TSB_SC4_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->FCNF,2)))
#define TSB_SC4_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->FCNF,3)))
#define TSB_SC4_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC4->FCNF,4)))


/* Consumer Electronics Control (CEC) */
#define TSB_CEC_EN_CECEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->EN,0)))
#define TSB_CEC_RESET_CECRESET                    (*((__O  uint32_t *)BITBAND_PERI(&TSB_CEC->RESET,0)))
#define TSB_CEC_REN_CECREN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->REN,0)))
#define TSB_CEC_RBUF_CECEOM                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RBUF,8)))
#define TSB_CEC_RBUF_CECACK                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RBUF,9)))
#define TSB_CEC_RCR1_CECOTH                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->RCR1,0)))
#define TSB_CEC_RCR1_CECRIHLD                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->RCR1,1)))
#define TSB_CEC_RCR1_CECACKDIS                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->RCR1,24)))
#define TSB_CEC_RCR3_CECWAVEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->RCR3,0)))
#define TSB_CEC_RCR3_CECRSTAEN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->RCR3,1)))
#define TSB_CEC_TEN_CECTEN                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CEC->TEN,0)))
#define TSB_CEC_TEN_CECTRANS                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TEN,1)))
#define TSB_CEC_TBUF_CECTEOM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->TBUF,8)))
#define TSB_CEC_TCR_CECBRD                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->TCR,4)))
#define TSB_CEC_RSTAT_CECRIEND                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,0)))
#define TSB_CEC_RSTAT_CECRISTA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,1)))
#define TSB_CEC_RSTAT_CECRIMAX                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,2)))
#define TSB_CEC_RSTAT_CECRIMIN                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,3)))
#define TSB_CEC_RSTAT_CECRIACK                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,4)))
#define TSB_CEC_RSTAT_CECRIOR                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,5)))
#define TSB_CEC_RSTAT_CECRIWAV                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->RSTAT,6)))
#define TSB_CEC_TSTAT_CECTISTA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TSTAT,0)))
#define TSB_CEC_TSTAT_CECTIEND                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TSTAT,1)))
#define TSB_CEC_TSTAT_CECTIAL                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TSTAT,2)))
#define TSB_CEC_TSTAT_CECTIACK                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TSTAT,3)))
#define TSB_CEC_TSTAT_CECTIUR                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CEC->TSTAT,4)))
#define TSB_CEC_FSSEL_CECCLK                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CEC->FSSEL,0)))


/* Remote Control Signal Preprocessor (RMC) */
#define TSB_RMC0_EN_RMCEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->EN,0)))
#define TSB_RMC0_REN_RMCREN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->REN,0)))
#define TSB_RMC0_RCR2_RMCPHM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->RCR2,24)))
#define TSB_RMC0_RCR2_RMCLD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->RCR2,25)))
#define TSB_RMC0_RCR2_RMCEDIEN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->RCR2,30)))
#define TSB_RMC0_RCR2_RMCLIEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->RCR2,31)))
#define TSB_RMC0_RCR4_RMCPO                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->RCR4,7)))
#define TSB_RMC0_RSTAT_RMCRLDR                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC0->RSTAT,7)))
#define TSB_RMC0_RSTAT_RMCEDIF                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC0->RSTAT,12)))
#define TSB_RMC0_RSTAT_RMCDMAXIF                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC0->RSTAT,13)))
#define TSB_RMC0_RSTAT_RMCLOIF                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC0->RSTAT,14)))
#define TSB_RMC0_RSTAT_RMCRLIF                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC0->RSTAT,15)))
#define TSB_RMC0_FSSEL_RMCCLK                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC0->FSSEL,0)))


/* Analog-to-Digital Converter (AD) */
#define TSB_AD_MOD0_ADS                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,0)))
#define TSB_AD_MOD0_SCAN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,1)))
#define TSB_AD_MOD0_REPEAT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,2)))
#define TSB_AD_MOD0_ADBFN                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,6)))
#define TSB_AD_MOD0_EOCFN                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD0,7)))
#define TSB_AD_MOD1_ADSCN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,5)))
#define TSB_AD_MOD1_I2AD                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,6)))
#define TSB_AD_MOD1_VREFON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD1,7)))
#define TSB_AD_MOD2_HPADCE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,5)))
#define TSB_AD_MOD2_ADBFHP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,6)))
#define TSB_AD_MOD2_EOCFHP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_AD->MOD2,7)))
#define TSB_AD_MOD3_ADOBSV0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,0)))
#define TSB_AD_MOD3_ADOBIC0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD3,5)))
#define TSB_AD_MOD5_ADOBSV1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,0)))
#define TSB_AD_MOD5_ADOBIC1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_AD->MOD5,5)))


/* Key On Wake Up (KWUP) */
#define TSB_KWUP_CR0_KEY0EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR0,0)))
#define TSB_KWUP_CR0_DPE0                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR0,7)))
#define TSB_KWUP_CR1_KEY1EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR1,0)))
#define TSB_KWUP_CR1_DPE1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR1,7)))
#define TSB_KWUP_CR2_KEY2EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR2,0)))
#define TSB_KWUP_CR2_DPE2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR2,7)))
#define TSB_KWUP_CR3_KEY3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR3,0)))
#define TSB_KWUP_CR3_DPE3                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_KWUP->CR3,7)))
#define TSB_KWUP_PKEY_PKEY0                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->PKEY,0)))
#define TSB_KWUP_PKEY_PKEY1                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->PKEY,1)))
#define TSB_KWUP_PKEY_PKEY2                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->PKEY,2)))
#define TSB_KWUP_PKEY_PKEY3                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->PKEY,3)))
#define TSB_KWUP_INT_KEYINT0                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->INT,0)))
#define TSB_KWUP_INT_KEYINT1                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->INT,1)))
#define TSB_KWUP_INT_KEYINT2                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->INT,2)))
#define TSB_KWUP_INT_KEYINT3                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_KWUP->INT,3)))


/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_I2WDT                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,2)))
#define TSB_WD_MOD_WDTE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))


/* Real Time Clock (RTC) */
#define TSB_RTC_MONTHR_MO0                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RTC->MONTHR,0)))


/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FPSEL0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,12)))
#define TSB_CG_SYSCR_FPSEL1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,13)))
#define TSB_CG_SYSCR_FCSTOP                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,20)))
#define TSB_CG_OSCCR_WUEON                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_PLLON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,2)))
#define TSB_CG_OSCCR_WUPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XTEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,9)))
#define TSB_CG_STBYCR_RXEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,8)))
#define TSB_CG_STBYCR_RXTEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,9)))
#define TSB_CG_STBYCR_DRVE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,16)))
#define TSB_CG_STBYCR_PTKEEP                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,17)))
#define TSB_CG_PLLSEL_PLLSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,0)))
#define TSB_CG_PLLSEL_C2S                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,8)))
#define TSB_CG_CKSEL_SYSCKFLG                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,0)))
#define TSB_CG_CKSEL_SYSCK                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->CKSEL,1)))
#define TSB_CG_RSTFLG_PONRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,0)))
#define TSB_CG_RSTFLG_PINRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,1)))
#define TSB_CG_RSTFLG_WDTRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,2)))
#define TSB_CG_RSTFLG_BUPRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,3)))
#define TSB_CG_RSTFLG_SYSRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,4)))
#define TSB_CG_IMCGA_INT0EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,0)))
#define TSB_CG_IMCGA_INT1EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,8)))
#define TSB_CG_IMCGA_INT2EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,16)))
#define TSB_CG_IMCGA_INT3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))
#define TSB_CG_IMCGB_INT6EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,16)))
#define TSB_CG_IMCGB_INT7EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,24)))
#define TSB_CG_IMCGD_INTEEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,16)))
#define TSB_CG_IMCGD_INTFEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,24)))
#define TSB_CG_IMCGE_INTGEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGE,0)))
#define TSB_CG_IMCGE_INTHEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGE,8)))
#define TSB_CG_IMCGE_INTIEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGE,16)))
#define TSB_CG_IMCGF_INTKEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGF,0)))
#define TSB_CG_IMCGF_INTLEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGF,8)))




/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM361_H__ */

/** @} */ /* End of group TMPM361 */
/** @} */ /* End of group TOSHIBA_TX03_MICROCONTROLLER */
