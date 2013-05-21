/**
 *******************************************************************************
 * @file    TMPM369.h
 * @brief   CMSIS Cortex-M3 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM369' Device Series
 * @version V2.0.2.2 (Tentative)
 * @date    2011/09/29
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

/** @addtogroup TMPM369
  * @{
  */

#ifndef __TMPM369_H__
#define __TMPM369_H__

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

/******  TMPM369 Specific Interrupt Numbers *******************************************************************/
  INT0_IRQn                     = 0,         /*!< Interrupt pin 0                                             */
  INT1_IRQn                     = 1,         /*!< Interrupt pin 1                                             */
  INT2_IRQn                     = 2,         /*!< Interrupt pin 2                                             */
  INT3_IRQn                     = 3,         /*!< Interrupt pin 3                                             */
  INT4_IRQn                     = 4,         /*!< Interrupt pin 4                                             */
  INT5_IRQn                     = 5,         /*!< Interrupt pin 5                                             */
  INT6_IRQn                     = 6,         /*!< Interrupt pin 6                                             */
  INT7_IRQn                     = 7,         /*!< Interrupt pin 7                                             */
  INT8_IRQn                     = 8,         /*!< Interrupt pin 8                                             */
  INT9_IRQn                     = 9,         /*!< Interrupt pin 9                                             */
  INTA_IRQn                     = 10,        /*!< Interrupt pin A                                             */
  INTB_IRQn                     = 11,        /*!< Interrupt pin B                                             */
  INTC_IRQn                     = 12,        /*!< Interrupt pin C                                             */
  INTD_IRQn                     = 13,        /*!< Interrupt pin D                                             */
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
  INTUART4_IRQn                 = 24,        /*!< FULL UART(channel.4)                                        */
  INTUART5_IRQn                 = 25,        /*!< FULL UART(channel.5)                                        */
  INTSBI0_IRQn                  = 26,        /*!< Serial bus interface 0                                      */
  INTSBI1_IRQn                  = 27,        /*!< Serial bus interface 1                                      */
  INTSBI2_IRQn                  = 28,        /*!< Serial bus interface 2                                      */
  INTSSP0_IRQn                  = 29,        /*!< SPI serial interface 0                                      */
  INTSSP1_IRQn                  = 30,        /*!< SPI serial interface 1                                      */
  INTSSP2_IRQn                  = 31,        /*!< SPI serial interface 2                                      */
  INTUSBH_IRQn                  = 32,        /*!< USB Host Interrupt                                          */
  INTUSBD_IRQn                  = 33,        /*!< USB Device Interrupt                                        */
  INTUSBWKUP_IRQn               = 34,        /*!< USB WakeUp                                                  */
  INTCANRX_IRQn                 = 35,        /*!< CAN RX                                                      */
  INTCANTX_IRQn                 = 36,        /*!< CAN TX                                                      */
  IMTCANGB_IRQn                 = 37,        /*!< CAN STAUTS                                                  */
  INTETH_IRQn                   = 38,        /*!< EtherNET Interrupt                                          */
  INTETHWK_IRQn                 = 39,        /*!< EtherNET(magic packet detection) interrupt                  */
  INTADAHP_IRQn                 = 40,        /*!< Highest priority AD conversion complete interrupt (channel.A)*/
  INTADAM0_IRQn                 = 41,        /*!< AD conversion monitoring function interrupt 0(channel.A)    */
  INTADAM1_IRQn                 = 42,        /*!< AD conversion monitoring function interrupt 1(channel.A)    */
  INTADA_IRQn                   = 43,        /*!< AD conversion interrupt(channel.A)                          */
  INTADBHP_IRQn                 = 44,        /*!< Highest priority AD conversion complete interrupt (channel.B)*/
  INTADBM0_IRQn                 = 45,        /*!< AD conversion monitoring function interrupt 0(channel.B)    */
  INTADBM1_IRQn                 = 46,        /*!< AD conversion monitoring function interrupt 1(channel.B)    */
  INTADB_IRQn                   = 47,        /*!< AD conversion interrupt(channel.B)                          */
  INTEMG0_IRQn                  = 48,        /*!< PMD0 EMG interrupt (MPT0)                                   */
  INTPMD0_IRQn                  = 49,        /*!< PMD0 PWM interrupt (MPT0)                                   */
  INTENC0_IRQn                  = 50,        /*!< PMD0 Encoder input interrupt (MPT0)                         */
  INTEMG1_IRQn                  = 51,        /*!< PMD1 EMG interrupt (MPT1)                                   */
  INTPMD1_IRQn                  = 52,        /*!< PMD1 PWM interrupt (MPT1)                                   */
  INTENC1_IRQn                  = 53,        /*!< PMD1 Encoder input interrupt (MPT1)                         */
  INTMTEMG0_IRQn                = 54,        /*!< 16-bit MPT0 IGBT EMG interrupt                              */
  INTMTPTB00_IRQn               = 55,        /*!< 16-bit MPT0 IGBT period/ TMRB compare match detection 0     */
  INTMTTTB01_IRQn               = 56,        /*!< 16-bit MPT0 IGBT trigger/ TMRB compare match detection 1    */
  INTMTCAP00_IRQn               = 57,        /*!< 16-bit MPT0 input capture 0                                 */
  INTMTCAP01_IRQn               = 58,        /*!< 16-bit MPT0 input capture 1                                 */
  INTMTEMG1_IRQn                = 59,        /*!< 16-bit MPT1 IGBT EMG interrupt                              */
  INTMTPTB10_IRQn               = 60,        /*!< 16-bit MPT1 IGBT period/ TMRB compare match detection 0     */
  INTMTTTB11_IRQn               = 61,        /*!< 16-bit MPT1 IGBT trigger/ TMRB compare match detection 1    */
  INTMTCAP10_IRQn               = 62,        /*!< 16-bit MPT1 input capture 0                                 */
  INTMTCAP11_IRQn               = 63,        /*!< 16-bit MPT1 input capture 1                                 */
  INTMTEMG2_IRQn                = 64,        /*!< 16-bit MPT2 IGBT EMG interrupt                              */
  INTMTPTB20_IRQn               = 65,        /*!< 16-bit MPT2 IGBT period/ TMRB compare match detection 0     */
  INTMTTTB21_IRQn               = 66,        /*!< 16-bit MPT2 IGBT trigger/ TMRB compare match detection 1    */
  INTMTCAP20_IRQn               = 67,        /*!< 16-bit MPT2 input capture 0                                 */
  INTMTCAP21_IRQn               = 68,        /*!< 16-bit MPT2 input capture 1                                 */
  INTMTEMG3_IRQn                = 69,        /*!< 16-bit MPT3 IGBT EMG interrupt                              */
  INTMTPTB30_IRQn               = 70,        /*!< 16-bit MPT3 IGBT period/ TMRB compare match detection 0     */
  INTMTTTB31_IRQn               = 71,        /*!< 16-bit MPT3 IGBT trigger/ TMRB compare match detection 1    */
  INTMTCAP30_IRQn               = 72,        /*!< 16-bit MPT3 input capture 0                                 */
  INTMTCAP31_IRQn               = 73,        /*!< 16-bit MPT3 input capture 1                                 */
  INTRMCRX_IRQn                 = 74,        /*!< Remote Controller reception interrupt                       */
  INTTB0_IRQn                   = 75,        /*!< 16-bit TMRB_0 match detection 0                             */
  INTCAP00_IRQn                 = 76,        /*!< 16-bit TMRB_0 input capture 00                              */
  INTCAP01_IRQn                 = 77,        /*!< 16-bit TMRB_0 input capture 01                              */
  INTTB1_IRQn                   = 78,        /*!< 16-bit TMRB_1 match detection 1                             */
  INTCAP10_IRQn                 = 79,        /*!< 16-bit TMRB_1 input capture 10                              */
  INTCAP11_IRQn                 = 80,        /*!< 16-bit TMRB_1 input capture 11                              */
  INTTB2_IRQn                   = 81,        /*!< 16-bit TMRB_2 match detection 2                             */
  INTCAP20_IRQn                 = 82,        /*!< 16-bit TMRB_2 input capture 20                              */
  INTCAP21_IRQn                 = 83,        /*!< 16-bit TMRB_2 input capture 21                              */
  INTTB3_IRQn                   = 84,        /*!< 16-bit TMRB_3 match detection 3                             */
  INTCAP30_IRQn                 = 85,        /*!< 16-bit TMRB_3 input capture 30                              */
  INTCAP31_IRQn                 = 86,        /*!< 16-bit TMRB_3 input capture 31                              */
  INTTB4_IRQn                   = 87,        /*!< 16-bit TMRB_4 match detection 4                             */
  INTCAP40_IRQn                 = 88,        /*!< 16-bit TMRB_4 input capture 40                              */
  INTCAP41_IRQn                 = 89,        /*!< 16-bit TMRB_4 input capture 41                              */
  INTTB5_IRQn                   = 90,        /*!< 16-bit TMRB_5 match detection 5                             */
  INTCAP50_IRQn                 = 91,        /*!< 16-bit TMRB_5 input capture 50                              */
  INTCAP51_IRQn                 = 92,        /*!< 16-bit TMRB_5 input capture 51                              */
  INTTB6_IRQn                   = 93,        /*!< 16-bit TMRB_6 match detection 6                             */
  INTCAP60_IRQn                 = 94,        /*!< 16-bit TMRB_6 input capture 60                              */
  INTCAP61_IRQn                 = 95,        /*!< 16-bit TMRB_6 input capture 61                              */
  INTTB7_IRQn                   = 96,        /*!< 16-bit TMRB_7 match detection 7                             */
  INTCAP70_IRQn                 = 97,        /*!< 16-bit TMRB_7 input capture 70                              */
  INTCAP71_IRQn                 = 98,        /*!< 16-bit TMRB_7 input capture 71                              */
  INTRTC_IRQn                   = 99,        /*!< RTC(Real time clock) interrupt                              */
  INTDMAADA_IRQn                = 100,       /*!< DMA_ADC_A conversion end                                    */
  INTDMAADB_IRQn                = 101,       /*!< DMA_ADC_B conversion end                                    */
  INTDMADAA_IRQn                = 102,       /*!< DMA_DAC_A conversion trigger                                */
  INTDMADAB_IRQn                = 103,       /*!< DMA_DAC_B conversion trigger                                */
  INTDMASPR0_IRQn               = 104,       /*!< DMA_SSP_0 reception / DMA_I2C SIO_0                         */
  INTDMASPT0_IRQn               = 105,       /*!< DMA_SSP_0 transmission                                      */
  INTDMASPR1_IRQn               = 106,       /*!< DMA_SSP_1 reception                                         */
  INTDMASPT1_IRQn               = 107,       /*!< DMA_SSP_1 transmission                                      */
  INTDMASPR2_IRQn               = 108,       /*!< DMA_SSP_2 reception                                         */
  INTDMASPT2_IRQn               = 109,       /*!< DMA_SSP_2 transmission                                      */
  INTDMAUTR4_IRQn               = 110,       /*!< DMA_FUART_4 reception                                       */
  INTDMAUTT4_IRQn               = 111,       /*!< DMA_FUART_4 transmission                                    */
  INTDMAUTR5_IRQn               = 112,       /*!< DMA_FUART_5 reception                                       */
  INTDMAUTT5_IRQn               = 113,       /*!< DMA_FUART_5 transmission                                    */
  INTDMARX0_IRQn                = 114,       /*!< DMA_SIO/ UART_0 reception                                   */
  INTDMATX0_IRQn                = 115,       /*!< DMA_SIO/ UART_0 transmission                                */
  INTDMARX1_IRQn                = 116,       /*!< DMA_SIO/ UART_1 reception                                   */
  INTDMATX1_IRQn                = 117,       /*!< DMA_SIO/ UART_1 transmission                                */
  INTDMARX2_IRQn                = 118,       /*!< DMA_SIO/ UART_2 reception                                   */
  INTDMATX2_IRQn                = 119,       /*!< DMA_SIO/ UART_2 transmission                                */
  INTDMARX3_IRQn                = 120,       /*!< DMA_SIO/ UART_3 reception                                   */
  INTDMATX3_IRQn                = 121,       /*!< DMA_SIO/ UART_3 transmission                                */
  INTDMASBI1_IRQn               = 122,       /*!< DMA_I2C/ SIO_1                                              */
  INTDMASBI2_IRQn               = 123,       /*!< DMA_I2C/ SIO_2                                              */
  INTDMATB_IRQn                 = 124,       /*!< 16-bit TMRB_0-4 match detection                             */
  INTDMARQ_IRQn                 = 125,       /*!< DMA request pin                                             */
  INTDMAAERR_IRQn               = 126,       /*!< DMA_A error transfer interrupt                              */
  INTDMABERR_IRQn               = 127        /*!< DMA_B error transfer interrupt                              */
} IRQn_Type;

/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV              0x0200       /*!< Cortex-M3 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals            */
#include "system_TMPM369.h"                 /* TMPM369 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief CAN Controller (TXCAN) Mailbox RAM
  */
typedef struct
{
  __IO uint32_t ID;                /*!< CAN Mailbox Register                         */
       uint32_t RESERVED0;
  __IO uint32_t TSVMCF;            /*!< CAN Mailbox Register                         */
       uint32_t RESERVED1;
  __IO uint32_t DL;                /*!< CAN Mailbox Register                         */
       uint32_t RESERVED2;
  __IO uint32_t DH;                /*!< CAN Mailbox Register                         */
} TSB_CANMB_TypeDef;

/**
  * @brief CAN Controller (TXCAN)
  */
typedef struct
{
  __IO uint32_t MC;                /*!< CAN Mailbox Configuration Register           */
       uint32_t RESERVED0;
  __IO uint32_t MD;                /*!< CAN Mailbox Direction Register               */
       uint32_t RESERVED1;
  __IO uint32_t TRS;               /*!< CAN Transmit Request Set Register            */
       uint32_t RESERVED2;
  __IO uint32_t TRR;               /*!< CAN Transmit Request Reset Register          */
       uint32_t RESERVED3;
  __IO uint32_t TA;                /*!< CAN Transmission Acknowledge Register        */
       uint32_t RESERVED4;
  __IO uint32_t AA;                /*!< CAN Abort Acknowledge Register               */
       uint32_t RESERVED5;
  __IO uint32_t RMP;               /*!< CAN Receive Message Pending Register         */
       uint32_t RESERVED6;
  __IO uint32_t RML;               /*!< CAN Receive Message Lost Register            */
       uint32_t RESERVED7;
  __IO uint32_t LAM;               /*!< CAN Local Acceptance Mask Register           */
       uint32_t RESERVED8;
  __IO uint32_t GAM;               /*!< CAN Global Acceptance Mask Register          */
       uint32_t RESERVED9;
  __IO uint32_t MCR;               /*!< CAN Master Control Register                  */
       uint32_t RESERVED10;
  __I  uint32_t GSR;               /*!< CAN Global Status Register                   */
       uint32_t RESERVED11;
  __IO uint32_t BCR1;              /*!< CAN Bit Configuration Register 1             */
       uint32_t RESERVED12;
  __IO uint32_t BCR2;              /*!< CAN Bit Configuration Register 2             */
       uint32_t RESERVED13;
  __IO uint32_t GIF;               /*!< CAN Global Interrupt Flag Register           */
       uint32_t RESERVED14;
  __IO uint32_t GIM;               /*!< CAN Global Interrupt Mask Register           */
       uint32_t RESERVED15;
  __IO uint32_t MBTIF;             /*!< CAN Mailbox Transmit Interrupt Flag Register */
       uint32_t RESERVED16;
  __IO uint32_t MBRIF;             /*!< CAN Mailbox Receive Interrupt Flag Register  */
       uint32_t RESERVED17;
  __IO uint32_t MBIM;              /*!< CAN Mailbox Interrupt Mask Register          */
       uint32_t RESERVED18;
  __IO uint32_t CDR;               /*!< CAN Change Data Request                      */
       uint32_t RESERVED19;
  __IO uint32_t RFP;               /*!< CAN Remote Frame Pending Register            */
       uint32_t RESERVED20;
  __IO uint32_t CEC;               /*!< CAN Error Counter Register                   */
       uint32_t RESERVED21;
  __IO uint32_t TSP;               /*!< CAN Time Stamp Counter Prescaler Register    */
       uint32_t RESERVED22;
  __IO uint32_t TSC;               /*!< CAN Time Stamp Counter Register              */
} TSB_CAN_TypeDef;

/**
  * @brief USB Host Controller (USBHC)
  */
typedef struct
{
  __I  uint32_t REVISION;          /*!< USB Host Controller Revision Register        */
  __IO uint32_t CONTROL;           /*!< USB Host Controller Control Register         */
  __IO uint32_t COMMANDSTATUS;     /*!< USB Host Controller Command Status Register  */
  __IO uint32_t INTERRUPTSTATUS;   /*!< USB Host Controller Interrupt Status Register*/
  __IO uint32_t INTERRUPTENABLE;   /*!< USB Host Controller Interrupt Enable Register*/
  __IO uint32_t INTERRUPTDISABLE;  /*!< USB Host Controller Interrupt Disable Register*/
  __IO uint32_t HCCA;              /*!< USB Host Controller Communication Area Register*/
  __I  uint32_t PERIODCURRENTED;   /*!< USB Host Controller Period Current ED Register*/
  __IO uint32_t CONTROLHEADED;     /*!< USB Host Controller Control Head ED Register */
  __IO uint32_t CONTROLCURRENTED;  /*!< USB Host Controller Control Current ED Register*/
  __IO uint32_t BULKHEADED;        /*!< USB Host Controller Bulk Head ED Register    */
  __IO uint32_t BULKCURRENTED;     /*!< USB Host Controller Bulk Current ED Register */
  __I  uint32_t DONEHEAD;          /*!< USB Host Controller Done Head Register       */
  __IO uint32_t FMINTERVAL;        /*!< USB Host Controller Frame Interval Register  */
  __I  uint32_t FMREMAINING;       /*!< USB Host Controller Frame Remaining Register */
  __I  uint32_t FMNUMBER;          /*!< USB Host Controller Frame Number Register    */
  __IO uint32_t PERIODSTART;       /*!< USB Host Controller Period Start Register    */
  __IO uint32_t LSTHRESHOLD;       /*!< USB Host Controller LS Threshold Register    */
  __IO uint32_t RHDESCRIPTORA;     /*!< USB Host Controller Root Hub Descriptor Register*/
  __IO uint32_t RHDESCRIPTORB;     /*!< USB Host Controller Root Hub Descriptor Register*/
  __IO uint32_t RHSTATUS;          /*!< USB Host Controller Root Hub Status Register */
  __IO uint32_t RHPORTSTATUS1;     /*!< USB Host Controller Root Hub Port Status Register*/
       uint32_t RESERVED0[10];
  __IO uint32_t BCR0;              /*!< USB Host Controller Clock & Transceiver Control Register*/
} TSB_HC_TypeDef;

/**
  * @brief UDC2 AHB Bridge
  */
typedef struct
{
  __IO uint32_t INTSTS;            /*!< Interrupt Status Register                    */
  __IO uint32_t INTENB;            /*!< Interrupt Enable Register                    */
  __IO uint32_t MWTOUT;            /*!< Master Write Timeout Register                */
  __IO uint32_t C2STSET;           /*!< UDC2 setting                                 */
  __IO uint32_t MSTSET;            /*!< DMAC setting                                 */
  __IO uint32_t DMACRDREQ;         /*!< DMAC Read request                            */
  __I  uint32_t DMACRDVL;          /*!< DMAC Read Value                              */
  __IO uint32_t UDC2RDREQ;         /*!< UDC2 Read Request                            */
  __I  uint32_t UDC2RDVL;          /*!< UDC2 Read Value                              */
       uint32_t RESERVED0[6];
  __IO uint32_t ARBTSET;           /*!< Arbiter Setting                              */
  __IO uint32_t MWSADR;            /*!< Master Write Start Address                   */
  __IO uint32_t MWEADR;            /*!< Master Write End Address                     */
  __I  uint32_t MWCADR;            /*!< Master Write Current Address                 */
  __I  uint32_t MWAHBADR;          /*!< Master Write AHB Address                     */
  __IO uint32_t MRSADR;            /*!< Master Read Start Address                    */
  __IO uint32_t MREADR;            /*!< Master Read End Address                      */
  __I  uint32_t MRCADR;            /*!< Master Read Current Address                  */
  __I  uint32_t MRAHBADR;          /*!< Master Read AHB Address                      */
       uint32_t RESERVED1[8];
  __IO uint32_t PWCTL;             /*!< Power Detect Control                         */
  __I  uint32_t MSTSTS;            /*!< Master Status                                */
  __I  uint32_t TOUTCNT;           /*!< Timeout Count                                */
} TSB_UDFS_TypeDef;

/**
  * @brief UDC2(USB -Spec2.0 Device contoller)
  */
typedef struct
{
  __IO uint32_t ADR;               /*!< UDC2 Address State                           */
  __IO uint32_t FRM;               /*!< UDC2 Frame                                   */
       uint32_t RESERVED0;
  __IO uint32_t CMD;               /*!< UDC2 Command                                 */
  __I  uint32_t BRQ;               /*!< UDC2 bRequest-bmRequest Type                 */
  __I  uint32_t WVL;               /*!< UDC2 wValue                                  */
  __I  uint32_t WIDX;              /*!< UDC2 wIndex                                  */
  __I  uint32_t WLGTH;             /*!< UDC2 wLength                                 */
  __IO uint32_t INT;               /*!< UDC2 INT                                     */
  __IO uint32_t INTEP;             /*!< UDC2 INT_EP                                  */
  __IO uint32_t INTEPMSK;          /*!< UDC2 INT_EP_MASK                             */
  __IO uint32_t INTRX0;            /*!< UDC2 INT RX DATA0                            */
  __IO uint32_t EP0MSZ;            /*!< UDC2 EP0 Max Packet Size                     */
  __I  uint32_t EP0STS;            /*!< UDC2 EP0 Status                              */
  __I  uint32_t EP0DSZ;            /*!< UDC2 EP0 Data Size                           */
  __IO uint32_t EP0FIFO;           /*!< UDC2 EP0 FIFO                                */
  __IO uint32_t EP1MSZ;            /*!< UDC2 EP1 Max Packet Size                     */
  __IO uint32_t EP1STS;            /*!< UDC2 EP1 Status                              */
  __I  uint32_t EP1DSZ;            /*!< UDC2 EP1 Data Size                           */
  __IO uint32_t EP1FIFO;           /*!< UDC2 EP1 FIFO                                */
  __IO uint32_t EP2MSZ;            /*!< UDC2 EP2 Max Packet Size                     */
  __IO uint32_t EP2STS;            /*!< UDC2 EP2 Status                              */
  __I  uint32_t EP2DSZ;            /*!< UDC2 EP2 Data Size                           */
  __IO uint32_t EP2FIFO;           /*!< UDC2 EP2 FIFO                                */
  __IO uint32_t EP3MSZ;            /*!< UDC3 EP3 Max Packet Size                     */
  __IO uint32_t EP3STS;            /*!< UDC3 EP3 Status                              */
  __I  uint32_t EP3DSZ;            /*!< UDC3 EP3 Data Size                           */
  __IO uint32_t EP3FIFO;           /*!< UDC3 EP3 FIFO                                */
  __IO uint32_t EP4MSZ;            /*!< UDC2 EP4 Max Packet Size                     */
  __IO uint32_t EP4STS;            /*!< UDC2 EP4 Status                              */
  __I  uint32_t EP4DSZ;            /*!< UDC2 EP4 Data Size                           */
  __IO uint32_t EP4FIFO;           /*!< UDC2 EP4 FIFO                                */
  __IO uint32_t EP5MSZ;            /*!< UDC2 EP5 Max Packet Size                     */
  __IO uint32_t EP5STS;            /*!< UDC2 EP5 Status                              */
  __I  uint32_t EP5DSZ;            /*!< UDC2 EP5 Data Size                           */
  __IO uint32_t EP5FIFO;           /*!< UDC2 EP5 FIFO                                */
  __IO uint32_t EP6MSZ;            /*!< UDC2 EP6 Max Packet Size                     */
  __IO uint32_t EP6STS;            /*!< UDC2 EP6 Status                              */
  __I  uint32_t EP6DSZ;            /*!< UDC2 EP6 Data Size                           */
  __IO uint32_t EP6FIFO;           /*!< UDC2 EP6 FIFO                                */
  __IO uint32_t EP7MSZ;            /*!< UDC2 EP7 Max Packet Size                     */
  __IO uint32_t EP7STS;            /*!< UDC2 EP7 Status                              */
  __I  uint32_t EP7DSZ;            /*!< UDC2 EP7 Data Size                           */
  __IO uint32_t EP7FIFO;           /*!< UDC2 EP7 FIFO                                */
       uint32_t RESERVED1[160];
  __IO uint32_t INTNAK;            /*!< UDC2 INT NAK                                 */
  __IO uint32_t INTNAKMSK;         /*!< UDC2 INT NAK MASK                            */
} TSB_UDFS2_TypeDef;

/**
  * @brief UDC2 AHB Bridge
  */
typedef struct
{
  __I  uint32_t IFVRR;             /*!< ADiC Version/Revision Register               */
  __IO uint32_t IFCR;              /*!< ADiC MODE Setting Register                   */
       uint32_t RESERVED0[2];
  __IO uint32_t IFINTST;           /*!< ADiC  Interrupt Status Register              */
  __IO uint32_t IFINTEN;           /*!< ADiC Interrupt Enable Register               */
       uint32_t RESERVED1[1018];
  __IO uint32_t DCR;               /*!< EMDMAC Movement Control Register             */
       uint32_t RESERVED2;
  __IO uint32_t DTEN;              /*!< Transmission Instructions Register           */
       uint32_t RESERVED3;
  __IO uint32_t DREN;              /*!< Reception instructions Register              */
       uint32_t RESERVED4;
  __IO uint32_t DTDPR;             /*!< Transmission Dscripter top address setting Register*/
       uint32_t RESERVED5;
  __IO uint32_t DRDPR;             /*!< Reception Dscripter top address setting Register*/
       uint32_t RESERVED6;
  __IO uint32_t DINTST;            /*!< EMSMAC Interrupt Status Indication Register  */
       uint32_t RESERVED7;
  __IO uint32_t DINTEN;            /*!< EMDMAC Interrupt mask setting Register       */
       uint32_t RESERVED8;
  __IO uint32_t DERR;              /*!< Err Mask Setting Register                    */
       uint32_t RESERVED9;
  __IO uint32_t DMFCR;             /*!< Disposal Frame Count Register                */
       uint32_t RESERVED10;
  __IO uint32_t DTFTR;             /*!< Transmission FIFO thresholding Register      */
       uint32_t RESERVED11;
  __IO uint32_t DFCDR;             /*!< Outside FIFO Capacity Setting Register       */
       uint32_t RESERVED12;
  __IO uint32_t DRRCR;             /*!< Reception Start Reset Setting Register       */
       uint32_t RESERVED13;
  __IO uint32_t DEADR;             /*!< DMA Error Address Register                   */
  __IO uint32_t DTUFR;             /*!< Transmission FIFO Underflow Count Register   */
  __IO uint32_t DROFR;             /*!< Reception FIFO Underflow Count Register      */
       uint32_t RESERVED14;
  __IO uint32_t DRBTR;             /*!< Transmission FIFO Busy Transmission Thresholding Register*/
       uint32_t RESERVED15;
  __IO uint32_t DRPDR;             /*!< Reception Data Padding setting Register      */
  __IO uint32_t DTIMER;            /*!< Transmission Interrupt Mode Setting Register */
       uint32_t RESERVED16[18];
  __I  uint32_t DRBAR;             /*!< Reception Buffer Light Address For debugging Register*/
  __I  uint32_t DRDAR;             /*!< Reception Dscripter Read Address For Debugging Register*/
       uint32_t RESERVED17;
  __I  uint32_t DTBAR;             /*!< Transmission Read Address For Debugging Register*/
  __I  uint32_t DTDAR;             /*!< Transmission Dscripter Read Address For Debugging Register*/
       uint32_t RESERVED18[9];
  __IO uint32_t CCR;               /*!< Ether FeLic Active Mode Register             */
       uint32_t RESERVED19;
  __IO uint32_t CRFLR;             /*!< Long Frame Length Check Level Setting Register*/
       uint32_t RESERVED20;
  __IO uint32_t CINTST;            /*!< Status indication Register                   */
       uint32_t RESERVED21;
  __IO uint32_t CINTEN;            /*!< Interrupt mask setting Register              */
       uint32_t RESERVED22;
  __IO uint32_t CMIICR;            /*!< M¢ò Control Register                         */
       uint32_t RESERVED23;
  __I  uint32_t CPHYST;            /*!< Status Signal Register                       */
       uint32_t RESERVED24[9];
  __IO uint32_t CICR;              /*!< IPG Counter Setting Register                 */
  __IO uint32_t CAPR;              /*!< Auto Pause Parameter Setting Register        */
  __IO uint32_t CMPR;              /*!< Manual Pause Parameter setting Register      */
       uint32_t RESERVED25;
  __I  uint32_t CRPCR;             /*!< Reception PAUSE Frame Counter Register       */
  __IO uint32_t CPULR;             /*!< PAUSE Frame Retransmission Number Of Times Setting Register*/
  __I  uint32_t CPCR;              /*!< PAUSE Frame Retransmission Number Of Times Counter Register*/
  __IO uint32_t CBRR;              /*!< Broadcast Frame Reception Number Of Times Setting Register*/
       uint32_t RESERVED26[20];
  __IO uint32_t CMAHR;             /*!< Mac Address Register (High Rank)             */
       uint32_t RESERVED27;
  __IO uint32_t CMALR;             /*!< Mac Address Register (Low Rank)              */
       uint32_t RESERVED28;
  __IO uint32_t CTRER;             /*!< TINT1 Cunter Register                        */
  __IO uint32_t CTCDR;             /*!< TINT2 Cunter Register                        */
  __IO uint32_t CTCLR;             /*!< TINT3 Cunter Register                        */
  __IO uint32_t CTNDR;             /*!< TINT4 Cunter Register                        */
       uint32_t RESERVED29;
  __IO uint32_t CRCER;             /*!< RINT1 Cunter Register                        */
  __IO uint32_t CRFER;             /*!< RINT2 Cunter Register                        */
  __IO uint32_t CRLSR;             /*!< RINT3 Cunter Register                        */
  __IO uint32_t CRLOR;             /*!< RINT4 Cunter Register                        */
  __IO uint32_t CRRFR;             /*!< RINT5 Cunter Register                        */
  __IO uint32_t CRMFR;             /*!< RINT8 Cunter Register                        */
} TSB_EM_TypeDef;

/**
  * @brief Synchronous Serial Port
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

#if defined ( __CC_ARM   )           /* RealView Compiler */
#pragma anon_unions
#elif (defined (__ICCARM__))         /*  ICC Compiler     */
#pragma language=extended
#endif

/**
  * @brief ARM Prime Cell PL011
  */
typedef struct
{
  __IO uint32_t DR;                /*!< Data Register                                */
union {
  __I  uint32_t RSR;               /*!< Receive Status Register                      */
  __O  uint32_t ECR;               /*!< Error Clear Register                         */
  };
       uint32_t RESERVED0[4];
  __IO uint32_t FR;                /*!< Flag Register                                */
       uint32_t RESERVED1;
  __IO uint32_t ILPR;              /*!< IrDA Low-power Counter register              */
  __IO uint32_t IBDR;              /*!< Integer Baud Rate Register                   */
  __IO uint32_t FBDR;              /*!< Fractional Baud Rate Register                */
  __IO uint32_t LCR_H;             /*!< Line Control Register                        */
  __IO uint32_t CR;                /*!< Cntrol Register                              */
  __IO uint32_t IFLS;              /*!< Interrupt FIFO Level Select Register         */
  __IO uint32_t IMSC;              /*!< Interrupt Mask set/Clear Register            */
  __I  uint32_t RIS;               /*!< Raw Interrupt Status Register                */
  __I  uint32_t MIS;               /*!< Masked Interrupt Status Register             */
  __O  uint32_t ICR;               /*!< Interrupt Clear Register                     */
  __IO uint32_t DMACR;             /*!< DMA Control Register                         */
} TSB_UART_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
  __I  uint32_t STATUS;            /*!< DMA Status Register                          */
  __O  uint32_t CFG;               /*!< DMA Configuration Register                   */
  __IO uint32_t CTRLBASEPTR;       /*!< DMA Control Data Base Pointer Register       */
  __I  uint32_t ALTCTRLBASEPTR;    /*!< DMA Channel Alternate Control Data Base Pointer Register*/
       uint32_t RESERVED0;
  __O  uint32_t CHNLSWREQUEST;     /*!< DMA Channel Software Request Register        */
  __IO uint32_t CHNLUSEBURSTSET;   /*!< DMA Channel Useburst Set Register            */
  __O  uint32_t CHNLUSEBURSTCLR;   /*!< DMA Channel Useburst Clear Register          */
  __IO uint32_t CHNLREQMASKSET;    /*!< DMA Channel¡¡Request Mask Set Register       */
  __O  uint32_t CHNLREQMASKCLR;    /*!< DMA Channel Request Mask Clear Register      */
  __IO uint32_t CHNLENABLESET;     /*!< DMA Channel Enable Set Register              */
  __O  uint32_t CHNLENABLECLR;     /*!< DMA Channel Enable Clear Register            */
  __IO uint32_t CHNLPRIALTSET;     /*!< DMA Channel Primary-Alternate Set Register   */
  __O  uint32_t CHNLPRIALTCLR;     /*!< DMA Channel Primary-Alternate Clear Register */
  __IO uint32_t CHNLPRIORITYSET;   /*!< DMA Channel Priority Set Register            */
  __O  uint32_t CHNLPRIORITYCLR;   /*!< DMA Channel Priority Clear Register          */
       uint32_t RESERVED1[3];
  __IO uint32_t ERRCLR;            /*!< DMA Bus Error Clear Register                 */
} TSB_DMA_TypeDef;

/**
  * @brief Analog-to-Digital Converter (AD)
  */
typedef struct
{
  __IO uint32_t CLK;               /*!< AD Conversion Clock Setting Register         */
  __O  uint32_t MOD0;              /*!< AD Mode Control Register 0                   */
  __IO uint32_t MOD1;              /*!< AD Mode Control Register 1                   */
  __IO uint32_t MOD2;              /*!< AD Mode Control Register 2                   */
  __IO uint32_t MOD3;              /*!< AD Mode Control Register 3                   */
  __IO uint32_t MOD4;              /*!< AD Mode Control Register 4                   */
  __I  uint32_t MOD5;              /*!< AD Mode Control Register 5                   */
  __O  uint32_t MOD6;              /*!< AD Mode Control Register 6                   */
       uint32_t RESERVED0;
  __IO uint32_t CMPCR0;            /*!< AD Monitoring Setting Register 0             */
  __IO uint32_t CMPCR1;            /*!< AD Monitoring Setting Register 1             */
  __IO uint32_t CMP0;              /*!< AD Conversion Result Comparison Register 0   */
  __IO uint32_t CMP1;              /*!< AD Conversion Result Comparison Register 1   */
  __I  uint32_t REG00;             /*!< AD Conversion Result Register 00             */
  __I  uint32_t REG01;             /*!< AD Conversion Result Register 01             */
  __I  uint32_t REG02;             /*!< AD Conversion Result Register 02             */
  __I  uint32_t REG03;             /*!< AD Conversion Result Register 03             */
  __I  uint32_t REG04;             /*!< AD Conversion Result Register 04             */
  __I  uint32_t REG05;             /*!< AD Conversion Result Register 05             */
  __I  uint32_t REG06;             /*!< AD Conversion Result Register 06             */
  __I  uint32_t REG07;             /*!< AD Conversion Result Register 07             */
  __I  uint32_t REG08;             /*!< AD Conversion Result Register 08             */
  __I  uint32_t REG09;             /*!< AD Conversion Result Register 09             */
  __I  uint32_t REG10;             /*!< AD Conversion Result Register 10             */
  __I  uint32_t REG11;             /*!< AD Conversion Result Register 11             */
 	     uint32_t RESERVED1[4]; 
  __I  uint32_t REGSP;             /*!< AD Conversion Result Register SP             */
} TSB_AD_TypeDef;

/**
  * @brief Digital-to-Analog Converter (DA)
  */
typedef struct
{
  __IO uint32_t CNT;               /*!< DAC Control Register1                        */
  __IO uint32_t REG;               /*!< DAC Data Register                            */
  __IO uint32_t DCTL;              /*!< DAC Output Register                          */
  __O  uint32_t TCTL;              /*!< DAC Trigger Register                         */
  __IO uint32_t VCTL;              /*!< DAC Control Register2                        */
} TSB_DA_TypeDef;

/**
  * @brief External Bus Interface(EXB)
  */
typedef struct
{
  __IO uint32_t MOD;               /*!< External Bus Mode Register                   */
       uint32_t RESERVED0[3];
  __IO uint32_t AS0;               /*!< External Bus Base Address and CS Space setting Register 0*/
  __IO uint32_t AS1;               /*!< External Bus Base Address and CS Space setting Register 1 */
  __IO uint32_t AS2;               /*!< External Bus Base Address and CS Space setting Register 2*/
  __IO uint32_t AS3;               /*!< External Bus Base Address and CS Space setting Register 3*/
       uint32_t RESERVED1[8];
  __IO uint32_t CS0;               /*!< Chip Select and Wait Controller Register 0   */
  __IO uint32_t CS1;               /*!< Chip Select and Wait Controller Register 1   */
  __IO uint32_t CS2;               /*!< Chip Select and Wait Controller Register 2   */
  __IO uint32_t CS3;               /*!< Chip Select and Wait Controller Register 3   */
} TSB_EXB_TypeDef;

/**
  * @brief Dual ADC Configuration
  */
typedef struct
{
  __O  uint32_t VM01;              /*!< Dual Unit Mode Trigger Controller  START Register 1 */
  __IO uint32_t VM02;              /*!< Dual Unit Mode Trigger Controller  START Register 2 */
  __IO uint32_t VM03;              /*!< Dual Unit Mode Trigger Controller  START Register 3*/
} TSB_ADCI_TypeDef;

/**
  * @brief General Purpose Input/Output Port (PA)
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< PA Data Register                             */
  __IO uint32_t CR;                /*!< PA Control Register                          */
  __IO uint32_t FR1;               /*!< PA Function Register 1                       */
  __IO uint32_t FR2;               /*!< PA Function Register 2                       */
  __IO uint32_t FR3;               /*!< PA Function Register 3                       */
  __IO uint32_t FR4;               /*!< PA Function Register 4                       */
  __IO uint32_t FR5;               /*!< PA Function Register 5                       */
       uint32_t RESERVED0[3];
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
  __IO uint32_t FR2;               /*!< PB Function Register 2                       */
  __IO uint32_t FR3;               /*!< PB Function Register 3                       */
  __IO uint32_t FR4;               /*!< PB Function Register 4                       */
       uint32_t RESERVED0[4];
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
  __IO uint32_t FR2;               /*!< PC Function Register 2                       */
       uint32_t RESERVED0[6];
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
  __IO uint32_t FR4;               /*!< PE Function Register 4                       */
  __IO uint32_t FR5;               /*!< PE Function Register 5                       */
       uint32_t RESERVED0[3];
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
  __IO uint32_t FR2;               /*!< PF Function Register 2                       */
  __IO uint32_t FR3;               /*!< PF Function Register 3                       */
  __IO uint32_t FR4;               /*!< PF Function Register 4                       */
       uint32_t RESERVED0[4];
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
  __IO uint32_t FR3;               /*!< PG Function Register 3                       */
  __IO uint32_t FR4;               /*!< PG Function Register 4                       */
       uint32_t RESERVED0[4];
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
  __IO uint32_t FR4;               /*!< PH Function Register 4                       */
  __IO uint32_t FR5;               /*!< PH Function Register 5                       */
       uint32_t RESERVED0[3];
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
  __IO uint32_t DATA;              /*!< PI Data Register                             */
  __IO uint32_t CR;                /*!< PI Control Register                          */
  __IO uint32_t FR1;               /*!< PI Function Register 1                       */
  __IO uint32_t FR2;               /*!< PI Function Register 2                       */
       uint32_t RESERVED0[6];
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
  __IO uint32_t DATA;              /*!< PJ Data Register                             */
  __IO uint32_t CR;                /*!< PJ Control Register                          */
       uint32_t RESERVED0[8];
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
  __IO uint32_t DATA;              /*!< PK Data Register                             */
  __IO uint32_t CR;                /*!< PK Control Register                          */
  __IO uint32_t FR1;               /*!< PK Function Register 1                       */
  __IO uint32_t FR2;               /*!< PK Function Register 2                       */
  __IO uint32_t FR3;               /*!< PK Function Register 3                       */
  __IO uint32_t FR4;               /*!< PK Function Register 4                       */
       uint32_t RESERVED0[4];
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
  __IO uint32_t DATA;              /*!< PL Data Register                             */
  __IO uint32_t CR;                /*!< PL Control Register                          */
  __IO uint32_t FR1;               /*!< PL Function Register 1                       */
  __IO uint32_t FR2;               /*!< PL Function Register 2                       */
  __IO uint32_t FR3;               /*!< PL Function Register 3                       */
  __IO uint32_t FR4;               /*!< PL Function Register 4                       */
  __IO uint32_t FR5;               /*!< PL Function Register 5                       */
  __IO uint32_t FR6;               /*!< PL Function Register 6                       */
       uint32_t RESERVED0[2];
  __IO uint32_t OD;                /*!< PL Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PL Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PL Pull-Down Control Register                */
       uint32_t RESERVED1;
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
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< PM Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PM Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PM Pull-Down Control Register                */
       uint32_t RESERVED1;
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
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< PN Open Drain Control Register               */
  __IO uint32_t PUP;               /*!< PN Pull-Up Control Register                  */
  __IO uint32_t PDN;               /*!< PN Pull-Down Control Register                */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< PN Input Enable Control Register             */
} TSB_PN_TypeDef;

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
  __IO uint32_t DMA;                 /*!< TB DMA Enable Register                  */
} TSB_TB_TypeDef;

/**
  * @brief 16-bit Multi-Purpose Timer (MPT-TMR/IGBT)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< MPT Enable Register                          */
  __IO uint32_t RUN;               /*!< MPT RUN Register                             */
  __IO uint32_t TBCR;              /*!< MPT Control Register                         */
  __IO uint32_t TBMOD;             /*!< MPT Mode Register                            */
  __IO uint32_t TBFFCR;            /*!< MPT Flip-Flop Control Register               */
  __I  uint32_t TBST;              /*!< MPT Status Register                          */
  __IO uint32_t TBIM;              /*!< MPT Interrupt Mask Register                  */
  __I  uint32_t TBUC;              /*!< MPT Read Capture Register                    */
  __IO uint32_t RG0;               /*!< MPT RG0 Timer Register                       */
  __IO uint32_t RG1;               /*!< MPT RG1 Timer Register                       */
  __I  uint32_t CP0;               /*!< MPT CP0 Capture Register                     */
  __I  uint32_t CP1;               /*!< MPT CP1 Capture Register                     */
  __IO uint32_t IGCR;              /*!< IGBT Control Register                        */
  __O  uint32_t IGRESTA;           /*!< IGBT Timer Restart Register                  */
  __I  uint32_t IGST;              /*!< IGBT Timer Status Register                   */
  __IO uint32_t IGICR;             /*!< IGBT Input Control Register                  */
  __IO uint32_t IGOCR;             /*!< IGBT Output Control Register                 */
  __IO uint32_t IGRG2;             /*!< IGBT RG2 Timer Register                      */
  __IO uint32_t IGRG3;             /*!< IGBT RG3 Timer Register                      */
  __IO uint32_t IGRG4;             /*!< IGBT RG4 Timer Register                      */
  __IO uint32_t IGEMGCR;           /*!< IGBT EMG Control Register                    */
  __I  uint32_t IGEMGST;           /*!< IGBT EMG Status Register                     */
} TSB_MT_TypeDef;

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
  __IO uint32_t SR;                /*!< SBI Status Register (I2C Mode)               */
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
  * @brief Oscillation Frequency Detector (OFD)
  */
typedef struct
{
  __IO uint32_t CR1;               /*!< OFD Control Register 1                       */
  __IO uint32_t CR2;               /*!< OFD Control Register 2                       */
  __IO uint32_t MN0;               /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MN1;               /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MX0;               /*!< OFD Higher Detection Frequency Setting Register*/
  __IO uint32_t MX1;               /*!< OFD Higher Detection Frequency Setting Register*/
  __IO uint32_t RST;               /*!< OFD Reset Enable Control Register            */
  __I  uint32_t STAT;              /*!< OFD Status Register                          */
  __IO uint32_t MON;               /*!< OFD                                          */
} TSB_OFD_TypeDef;

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
       uint32_t RESERVED0;
  __IO uint32_t PCKSTP;            /*!< Peripheral Clock Stop Register               */
       uint32_t RESERVED1[8];
  __IO uint32_t PROTECT;           /*!< Protect Register                             */
  __IO uint32_t IMCGA;             /*!< CG Interrupt Mode Control Register A         */
  __IO uint32_t IMCGB;             /*!< CG Interrupt Mode Control Register B         */
  __IO uint32_t IMCGC;             /*!< CG Interrupt Mode Control Register C         */
  __IO uint32_t IMCGD;             /*!< CG Interrupt Mode Control Register D         */
       uint32_t RESERVED2[4];
  __O  uint32_t ICRCG;             /*!< CG Interrupt Request Clear Register          */
  __IO uint32_t RSTFLG;            /*!< Reset Flag Register                          */
  __I  uint32_t NMIFLG;            /*!< NMI Flag Register                            */
} TSB_CG_TypeDef;

/**
  * @brief Low Voltage detector control register
  */
typedef struct
{
  __IO uint32_t CR;                /*!< USB PLL Control Register                     */
  __IO uint32_t EN;                /*!< USB PLL Enable Register                      */
  __IO uint32_t SEL;               /*!< USB PLL Select Register                      */
} TSB_USBPLL_TypeDef;

/**
  * @brief Low Voltage detector control register
  */
typedef struct
{
  __IO uint32_t PRO;               /*!< Protection Register                          */
  __IO uint32_t EN;                /*!< Enable Register                              */
  __I  uint32_t INIT;              /*!< Initial Trimming Level Monitor Register      */
  __IO uint32_t SET;               /*!< Trimming Level Setting Register              */
} TSB_TRMOSC_TypeDef;

/**
  * @brief Low Voltage detector control register
  */
typedef struct
{
  __IO uint32_t RCR;               /*!< LVD-RESET Control Register                   */
  __IO uint32_t ICR;               /*!< LVD-NMI Control Register                     */
  __IO uint32_t SR;                /*!< LVD Status Control Register                  */
} TSB_LVD_TypeDef;

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
       uint32_t RESERVED0;
  __IO uint32_t MDOUT;             /*!< PMD Output Control Register                  */
  __IO uint32_t MDPOT;             /*!< PMD Output Setting Register                  */
  __O  uint32_t EMGREL;            /*!< EMG Release Register                         */
  __IO uint32_t EMGCR;             /*!< EMG Control Register                         */
  __I  uint32_t EMGSTA;            /*!< EMG Status Register                          */
       uint32_t RESERVED1[2];
  __IO uint32_t DTR;               /*!< Dead Time Register                           */
} TSB_MTPD_TypeDef;

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
  * @brief Flash Control (FC)
  */
typedef struct
{
       uint32_t RESERVED0[4];
  __IO uint32_t SECBIT;            /*!< FC Security Bit Register                     */
       uint32_t RESERVED1[3];
  __I  uint32_t FLCS;              /*!< FC Flash Control Register                    */
} TSB_FC_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)


#define TSB_CANMB0_BASE            (PERI_BASE  + 0x0005000UL)
#define TSB_CANMB1_BASE            (PERI_BASE  + 0x0005020UL)
#define TSB_CANMB2_BASE            (PERI_BASE  + 0x0005040UL)
#define TSB_CANMB3_BASE            (PERI_BASE  + 0x0005060UL)
#define TSB_CANMB4_BASE            (PERI_BASE  + 0x0005080UL)
#define TSB_CANMB5_BASE            (PERI_BASE  + 0x00050A0UL)
#define TSB_CANMB6_BASE            (PERI_BASE  + 0x00050C0UL)
#define TSB_CANMB7_BASE            (PERI_BASE  + 0x00050E0UL)
#define TSB_CANMB8_BASE            (PERI_BASE  + 0x0005100UL)
#define TSB_CANMB9_BASE            (PERI_BASE  + 0x0005120UL)
#define TSB_CANMB10_BASE           (PERI_BASE  + 0x0005140UL)
#define TSB_CANMB11_BASE           (PERI_BASE  + 0x0005160UL)
#define TSB_CANMB12_BASE           (PERI_BASE  + 0x0005180UL)
#define TSB_CANMB13_BASE           (PERI_BASE  + 0x00051A0UL)
#define TSB_CANMB14_BASE           (PERI_BASE  + 0x00051C0UL)
#define TSB_CANMB15_BASE           (PERI_BASE  + 0x00051E0UL)
#define TSB_CANMB16_BASE           (PERI_BASE  + 0x0005200UL)
#define TSB_CANMB17_BASE           (PERI_BASE  + 0x0005220UL)
#define TSB_CANMB18_BASE           (PERI_BASE  + 0x0005240UL)
#define TSB_CANMB19_BASE           (PERI_BASE  + 0x0005260UL)
#define TSB_CANMB20_BASE           (PERI_BASE  + 0x0005280UL)
#define TSB_CANMB21_BASE           (PERI_BASE  + 0x00052A0UL)
#define TSB_CANMB22_BASE           (PERI_BASE  + 0x00052C0UL)
#define TSB_CANMB23_BASE           (PERI_BASE  + 0x00052E0UL)
#define TSB_CANMB24_BASE           (PERI_BASE  + 0x0005300UL)
#define TSB_CANMB25_BASE           (PERI_BASE  + 0x0005320UL)
#define TSB_CANMB26_BASE           (PERI_BASE  + 0x0005340UL)
#define TSB_CANMB27_BASE           (PERI_BASE  + 0x0005360UL)
#define TSB_CANMB28_BASE           (PERI_BASE  + 0x0005380UL)
#define TSB_CANMB29_BASE           (PERI_BASE  + 0x00053A0UL)
#define TSB_CANMB30_BASE           (PERI_BASE  + 0x00053C0UL)
#define TSB_CANMB31_BASE           (PERI_BASE  + 0x00053E0UL)
#define TSB_CAN_BASE               (PERI_BASE  + 0x0005400UL)
#define TSB_HC_BASE                (PERI_BASE  + 0x0006000UL)
#define TSB_UDFS_BASE              (PERI_BASE  + 0x0008000UL)
#define TSB_UDFS2_BASE             (PERI_BASE  + 0x0008200UL)
#define TSB_EM_BASE                (PERI_BASE  + 0x000A000UL)
#define TSB_SSP0_BASE              (PERI_BASE  + 0x0040000UL)
#define TSB_SSP1_BASE              (PERI_BASE  + 0x0041000UL)
#define TSB_SSP2_BASE              (PERI_BASE  + 0x0042000UL)
#define TSB_UART4_BASE             (PERI_BASE  + 0x0048000UL)
#define TSB_UART5_BASE             (PERI_BASE  + 0x0049000UL)
#define TSB_DMAA_BASE              (PERI_BASE  + 0x004C000UL)
#define TSB_DMAB_BASE              (PERI_BASE  + 0x004D000UL)
#define TSB_ADA_BASE               (PERI_BASE  + 0x0050000UL)
#define TSB_ADB_BASE               (PERI_BASE  + 0x0051000UL)
#define TSB_DA0_BASE               (PERI_BASE  + 0x0054000UL)
#define TSB_DA1_BASE               (PERI_BASE  + 0x0055000UL)
#define TSB_EXB_BASE               (PERI_BASE  + 0x005C000UL)
#define TSB_ADCI_BASE              (PERI_BASE  + 0x0066000UL)
#define TSB_PA_BASE                (PERI_BASE  + 0x00C0000UL)
#define TSB_PB_BASE                (PERI_BASE  + 0x00C0100UL)
#define TSB_PC_BASE                (PERI_BASE  + 0x00C0200UL)
#define TSB_PD_BASE                (PERI_BASE  + 0x00C0300UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x00C0400UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x00C0500UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x00C0600UL)
#define TSB_PH_BASE                (PERI_BASE  + 0x00C0700UL)
#define TSB_PI_BASE                (PERI_BASE  + 0x00C0800UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x00C0900UL)
#define TSB_PK_BASE                (PERI_BASE  + 0x00C0A00UL)
#define TSB_PL_BASE                (PERI_BASE  + 0x00C0B00UL)
#define TSB_PM_BASE                (PERI_BASE  + 0x00C0C00UL)
#define TSB_PN_BASE                (PERI_BASE  + 0x00C0D00UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x00C4000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x00C4100UL)
#define TSB_TB2_BASE               (PERI_BASE  + 0x00C4200UL)
#define TSB_TB3_BASE               (PERI_BASE  + 0x00C4300UL)
#define TSB_TB4_BASE               (PERI_BASE  + 0x00C4400UL)
#define TSB_TB5_BASE               (PERI_BASE  + 0x00C4500UL)
#define TSB_TB6_BASE               (PERI_BASE  + 0x00C4600UL)
#define TSB_TB7_BASE               (PERI_BASE  + 0x00C4700UL)
#define TSB_MT0_BASE               (PERI_BASE  + 0x00C7000UL)
#define TSB_MT1_BASE               (PERI_BASE  + 0x00C7100UL)
#define TSB_MT2_BASE               (PERI_BASE  + 0x00C7200UL)
#define TSB_MT3_BASE               (PERI_BASE  + 0x00C7300UL)
#define TSB_RTC_BASE               (PERI_BASE  + 0x00CC000UL)
#define TSB_SBI0_BASE              (PERI_BASE  + 0x00E0000UL)
#define TSB_SBI1_BASE              (PERI_BASE  + 0x00E0100UL)
#define TSB_SBI2_BASE              (PERI_BASE  + 0x00E0200UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x00E1000UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00E1100UL)
#define TSB_SC2_BASE               (PERI_BASE  + 0x00E1200UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x00E1300UL)
#define TSB_RMC_BASE               (PERI_BASE  + 0x00E7000UL)
#define TSB_OFD_BASE               (PERI_BASE  + 0x00F1000UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x00F2000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x00F3000UL)
#define TSB_USBPLL_BASE            (PERI_BASE  + 0x00F3100UL)
#define TSB_TRMOSC_BASE            (PERI_BASE  + 0x00F3200UL)
#define TSB_LVD_BASE               (PERI_BASE  + 0x00F4000UL)
#define TSB_MTPD0_BASE             (PERI_BASE  + 0x00F6000UL)
#define TSB_MTPD1_BASE             (PERI_BASE  + 0x00F6100UL)
#define TSB_EN0_BASE               (PERI_BASE  + 0x00F7000UL)
#define TSB_EN1_BASE               (PERI_BASE  + 0x00F7100UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1FFF000UL)


/* Peripheral declaration */
#define TSB_CANMB0                 ((  TSB_CANMB_TypeDef *)TSB_CANMB0_BASE)
#define TSB_CANMB1                 ((  TSB_CANMB_TypeDef *)TSB_CANMB1_BASE)
#define TSB_CANMB2                 ((  TSB_CANMB_TypeDef *)TSB_CANMB2_BASE)
#define TSB_CANMB3                 ((  TSB_CANMB_TypeDef *)TSB_CANMB3_BASE)
#define TSB_CANMB4                 ((  TSB_CANMB_TypeDef *)TSB_CANMB4_BASE)
#define TSB_CANMB5                 ((  TSB_CANMB_TypeDef *)TSB_CANMB5_BASE)
#define TSB_CANMB6                 ((  TSB_CANMB_TypeDef *)TSB_CANMB6_BASE)
#define TSB_CANMB7                 ((  TSB_CANMB_TypeDef *)TSB_CANMB7_BASE)
#define TSB_CANMB8                 ((  TSB_CANMB_TypeDef *)TSB_CANMB8_BASE)
#define TSB_CANMB9                 ((  TSB_CANMB_TypeDef *)TSB_CANMB9_BASE)
#define TSB_CANMB10                ((  TSB_CANMB_TypeDef *)TSB_CANMB10_BASE)
#define TSB_CANMB11                ((  TSB_CANMB_TypeDef *)TSB_CANMB11_BASE)
#define TSB_CANMB12                ((  TSB_CANMB_TypeDef *)TSB_CANMB12_BASE)
#define TSB_CANMB13                ((  TSB_CANMB_TypeDef *)TSB_CANMB13_BASE)
#define TSB_CANMB14                ((  TSB_CANMB_TypeDef *)TSB_CANMB14_BASE)
#define TSB_CANMB15                ((  TSB_CANMB_TypeDef *)TSB_CANMB15_BASE)
#define TSB_CANMB16                ((  TSB_CANMB_TypeDef *)TSB_CANMB16_BASE)
#define TSB_CANMB17                ((  TSB_CANMB_TypeDef *)TSB_CANMB17_BASE)
#define TSB_CANMB18                ((  TSB_CANMB_TypeDef *)TSB_CANMB18_BASE)
#define TSB_CANMB19                ((  TSB_CANMB_TypeDef *)TSB_CANMB19_BASE)
#define TSB_CANMB20                ((  TSB_CANMB_TypeDef *)TSB_CANMB20_BASE)
#define TSB_CANMB21                ((  TSB_CANMB_TypeDef *)TSB_CANMB21_BASE)
#define TSB_CANMB22                ((  TSB_CANMB_TypeDef *)TSB_CANMB22_BASE)
#define TSB_CANMB23                ((  TSB_CANMB_TypeDef *)TSB_CANMB23_BASE)
#define TSB_CANMB24                ((  TSB_CANMB_TypeDef *)TSB_CANMB24_BASE)
#define TSB_CANMB25                ((  TSB_CANMB_TypeDef *)TSB_CANMB25_BASE)
#define TSB_CANMB26                ((  TSB_CANMB_TypeDef *)TSB_CANMB26_BASE)
#define TSB_CANMB27                ((  TSB_CANMB_TypeDef *)TSB_CANMB27_BASE)
#define TSB_CANMB28                ((  TSB_CANMB_TypeDef *)TSB_CANMB28_BASE)
#define TSB_CANMB29                ((  TSB_CANMB_TypeDef *)TSB_CANMB29_BASE)
#define TSB_CANMB30                ((  TSB_CANMB_TypeDef *)TSB_CANMB30_BASE)
#define TSB_CANMB31                ((  TSB_CANMB_TypeDef *)TSB_CANMB31_BASE)
#define TSB_CAN                    ((    TSB_CAN_TypeDef *)   TSB_CAN_BASE)
#define TSB_HC                     ((     TSB_HC_TypeDef *)    TSB_HC_BASE)
#define TSB_UDFS                   ((   TSB_UDFS_TypeDef *)  TSB_UDFS_BASE)
#define TSB_UDFS2                  ((  TSB_UDFS2_TypeDef *) TSB_UDFS2_BASE)
#define TSB_EM                     ((  TSB_ETHER_TypeDef *)    TSB_EM_BASE)
#define TSB_SSP0                   ((    TSB_SSP_TypeDef *)  TSB_SSP0_BASE)
#define TSB_SSP1                   ((    TSB_SSP_TypeDef *)  TSB_SSP1_BASE)
#define TSB_SSP2                   ((    TSB_SSP_TypeDef *)  TSB_SSP2_BASE)
#define TSB_UART4                  ((   TSB_UART_TypeDef *) TSB_UART4_BASE)
#define TSB_UART5                  ((   TSB_UART_TypeDef *) TSB_UART5_BASE)
#define TSB_DMAA                   ((    TSB_DMA_TypeDef *)  TSB_DMAA_BASE)
#define TSB_DMAB                   ((    TSB_DMA_TypeDef *)  TSB_DMAB_BASE)
#define TSB_ADA                    ((     TSB_AD_TypeDef *)   TSB_ADA_BASE)
#define TSB_ADB                    ((     TSB_AD_TypeDef *)   TSB_ADB_BASE)
#define TSB_DA0                    ((     TSB_DA_TypeDef *)   TSB_DA0_BASE)
#define TSB_DA1                    ((     TSB_DA_TypeDef *)   TSB_DA1_BASE)
#define TSB_EXB                    ((    TSB_EXB_TypeDef *)   TSB_EXB_BASE)
#define TSB_ADCI                   ((   TSB_ADCI_TypeDef *)  TSB_ADCI_BASE)
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
#define TSB_PM                     ((     TSB_PM_TypeDef *)    TSB_PM_BASE)
#define TSB_PN                     ((     TSB_PN_TypeDef *)    TSB_PN_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_TB2                    ((     TSB_TB_TypeDef *)   TSB_TB2_BASE)
#define TSB_TB3                    ((     TSB_TB_TypeDef *)   TSB_TB3_BASE)
#define TSB_TB4                    ((     TSB_TB_TypeDef *)   TSB_TB4_BASE)
#define TSB_TB5                    ((     TSB_TB_TypeDef *)   TSB_TB5_BASE)
#define TSB_TB6                    ((     TSB_TB_TypeDef *)   TSB_TB6_BASE)
#define TSB_TB7                    ((     TSB_TB_TypeDef *)   TSB_TB7_BASE)
#define TSB_MT0                    ((     TSB_MT_TypeDef *)   TSB_MT0_BASE)
#define TSB_MT1                    ((     TSB_MT_TypeDef *)   TSB_MT1_BASE)
#define TSB_MT2                    ((     TSB_MT_TypeDef *)   TSB_MT2_BASE)
#define TSB_MT3                    ((     TSB_MT_TypeDef *)   TSB_MT3_BASE)
#define TSB_RTC                    ((    TSB_RTC_TypeDef *)   TSB_RTC_BASE)
#define TSB_SBI0                   ((    TSB_SBI_TypeDef *)  TSB_SBI0_BASE)
#define TSB_SBI1                   ((    TSB_SBI_TypeDef *)  TSB_SBI1_BASE)
#define TSB_SBI2                   ((    TSB_SBI_TypeDef *)  TSB_SBI2_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC2                    ((     TSB_SC_TypeDef *)   TSB_SC2_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_RMC                    ((    TSB_RMC_TypeDef *)   TSB_RMC_BASE)
#define TSB_OFD                    ((    TSB_OFD_TypeDef *)   TSB_OFD_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)
#define TSB_USBPLL                 (( TSB_USBPLL_TypeDef *)TSB_USBPLL_BASE)
#define TSB_TRMOSC                 (( TSB_TRMOSC_TypeDef *)TSB_TRMOSC_BASE)
#define TSB_LVD                    ((    TSB_LVD_TypeDef *)   TSB_LVD_BASE)
#define TSB_MTPD0                  ((   TSB_MTPD_TypeDef *) TSB_MTPD0_BASE)
#define TSB_MTPD1                  ((   TSB_MTPD_TypeDef *) TSB_MTPD1_BASE)
#define TSB_EN0                    ((     TSB_EN_TypeDef *)   TSB_EN0_BASE)
#define TSB_EN1                    ((     TSB_EN_TypeDef *)   TSB_EN1_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)


/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/* CAN Controller (TXCAN) Mailbox RAM */
#define TSB_CANMB0_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,29)))
#define TSB_CANMB0_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,30)))
#define TSB_CANMB0_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,31)))
#define TSB_CANMB0_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->TSVMCF,4)))

#define TSB_CANMB1_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,29)))
#define TSB_CANMB1_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,30)))
#define TSB_CANMB1_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,31)))
#define TSB_CANMB1_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->TSVMCF,4)))

#define TSB_CANMB2_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,29)))
#define TSB_CANMB2_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,30)))
#define TSB_CANMB2_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,31)))
#define TSB_CANMB2_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->TSVMCF,4)))

#define TSB_CANMB3_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,29)))
#define TSB_CANMB3_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,30)))
#define TSB_CANMB3_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,31)))
#define TSB_CANMB3_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->TSVMCF,4)))

#define TSB_CANMB4_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,29)))
#define TSB_CANMB4_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,30)))
#define TSB_CANMB4_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,31)))
#define TSB_CANMB4_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->TSVMCF,4)))

#define TSB_CANMB5_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,29)))
#define TSB_CANMB5_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,30)))
#define TSB_CANMB5_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,31)))
#define TSB_CANMB5_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->TSVMCF,4)))

#define TSB_CANMB6_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,29)))
#define TSB_CANMB6_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,30)))
#define TSB_CANMB6_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,31)))
#define TSB_CANMB6_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->TSVMCF,4)))

#define TSB_CANMB7_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,29)))
#define TSB_CANMB7_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,30)))
#define TSB_CANMB7_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,31)))
#define TSB_CANMB7_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->TSVMCF,4)))

#define TSB_CANMB8_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,29)))
#define TSB_CANMB8_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,30)))
#define TSB_CANMB8_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,31)))
#define TSB_CANMB8_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->TSVMCF,4)))

#define TSB_CANMB9_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,29)))
#define TSB_CANMB9_ID_GAME                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,30)))
#define TSB_CANMB9_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,31)))
#define TSB_CANMB9_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->TSVMCF,4)))

#define TSB_CANMB10_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,29)))
#define TSB_CANMB10_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,30)))
#define TSB_CANMB10_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,31)))
#define TSB_CANMB10_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->TSVMCF,4)))

#define TSB_CANMB11_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,29)))
#define TSB_CANMB11_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,30)))
#define TSB_CANMB11_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,31)))
#define TSB_CANMB11_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->TSVMCF,4)))

#define TSB_CANMB12_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,29)))
#define TSB_CANMB12_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,30)))
#define TSB_CANMB12_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,31)))
#define TSB_CANMB12_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->TSVMCF,4)))

#define TSB_CANMB13_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,29)))
#define TSB_CANMB13_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,30)))
#define TSB_CANMB13_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,31)))
#define TSB_CANMB13_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->TSVMCF,4)))

#define TSB_CANMB14_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,29)))
#define TSB_CANMB14_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,30)))
#define TSB_CANMB14_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,31)))
#define TSB_CANMB14_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->TSVMCF,4)))

#define TSB_CANMB15_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,29)))
#define TSB_CANMB15_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,30)))
#define TSB_CANMB15_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,31)))
#define TSB_CANMB15_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->TSVMCF,4)))

#define TSB_CANMB16_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,29)))
#define TSB_CANMB16_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,30)))
#define TSB_CANMB16_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,31)))
#define TSB_CANMB16_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->TSVMCF,4)))

#define TSB_CANMB17_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,29)))
#define TSB_CANMB17_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,30)))
#define TSB_CANMB17_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,31)))
#define TSB_CANMB17_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->TSVMCF,4)))

#define TSB_CANMB18_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,29)))
#define TSB_CANMB18_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,30)))
#define TSB_CANMB18_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,31)))
#define TSB_CANMB18_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->TSVMCF,4)))

#define TSB_CANMB19_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,29)))
#define TSB_CANMB19_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,30)))
#define TSB_CANMB19_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,31)))
#define TSB_CANMB19_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->TSVMCF,4)))

#define TSB_CANMB20_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,29)))
#define TSB_CANMB20_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,30)))
#define TSB_CANMB20_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,31)))
#define TSB_CANMB20_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->TSVMCF,4)))

#define TSB_CANMB21_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,29)))
#define TSB_CANMB21_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,30)))
#define TSB_CANMB21_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,31)))
#define TSB_CANMB21_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->TSVMCF,4)))

#define TSB_CANMB22_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,29)))
#define TSB_CANMB22_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,30)))
#define TSB_CANMB22_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,31)))
#define TSB_CANMB22_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->TSVMCF,4)))

#define TSB_CANMB23_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,29)))
#define TSB_CANMB23_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,30)))
#define TSB_CANMB23_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,31)))
#define TSB_CANMB23_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->TSVMCF,4)))

#define TSB_CANMB24_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,29)))
#define TSB_CANMB24_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,30)))
#define TSB_CANMB24_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,31)))
#define TSB_CANMB24_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->TSVMCF,4)))

#define TSB_CANMB25_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,29)))
#define TSB_CANMB25_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,30)))
#define TSB_CANMB25_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,31)))
#define TSB_CANMB25_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->TSVMCF,4)))

#define TSB_CANMB26_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,29)))
#define TSB_CANMB26_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,30)))
#define TSB_CANMB26_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,31)))
#define TSB_CANMB26_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->TSVMCF,4)))

#define TSB_CANMB27_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,29)))
#define TSB_CANMB27_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,30)))
#define TSB_CANMB27_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,31)))
#define TSB_CANMB27_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->TSVMCF,4)))

#define TSB_CANMB28_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,29)))
#define TSB_CANMB28_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,30)))
#define TSB_CANMB28_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,31)))
#define TSB_CANMB28_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->TSVMCF,4)))

#define TSB_CANMB29_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,29)))
#define TSB_CANMB29_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,30)))
#define TSB_CANMB29_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,31)))
#define TSB_CANMB29_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->TSVMCF,4)))

#define TSB_CANMB30_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,29)))
#define TSB_CANMB30_ID_GAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,30)))
#define TSB_CANMB30_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,31)))
#define TSB_CANMB30_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->TSVMCF,4)))

#define TSB_CANMB31_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,29)))
#define TSB_CANMB31_ID_LAME                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,30)))
#define TSB_CANMB31_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,31)))
#define TSB_CANMB31_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->TSVMCF,4)))


/* CAN Controller (TXCAN) */
#define TSB_CAN_LAM_LAMI                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->LAM,31)))
#define TSB_CAN_GAM_GAMI                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GAM,31)))
#define TSB_CAN_MCR_SRES                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,0)))
#define TSB_CAN_MCR_TSCC                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,1)))
#define TSB_CAN_MCR_MTOS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,3)))
#define TSB_CAN_MCR_WUBA                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,4)))
#define TSB_CAN_MCR_SMR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,6)))
#define TSB_CAN_MCR_CCR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,7)))
#define TSB_CAN_MCR_TSTERR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,8)))
#define TSB_CAN_MCR_TSTLB                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,9)))
#define TSB_CAN_MCR_SUR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,11)))
#define TSB_CAN_GSR_EW                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,0)))
#define TSB_CAN_GSR_EP                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,1)))
#define TSB_CAN_GSR_BO                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,2)))
#define TSB_CAN_GSR_TSO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,3)))
#define TSB_CAN_GSR_SMA                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,6)))
#define TSB_CAN_GSR_CCE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,7)))
#define TSB_CAN_GSR_SUA                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,8)))
#define TSB_CAN_GSR_TM                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,10)))
#define TSB_CAN_GSR_RM                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,11)))
#define TSB_CAN_BCR2_SAM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->BCR2,7)))
#define TSB_CAN_GIM_WLIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,0)))
#define TSB_CAN_GIM_EPIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,1)))
#define TSB_CAN_GIM_BOIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,2)))
#define TSB_CAN_GIM_TSOIM                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,3)))
#define TSB_CAN_GIM_TRMABF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,4)))
#define TSB_CAN_GIM_RMLIM                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,5)))
#define TSB_CAN_GIM_WUIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,6)))
#define TSB_CAN_GIM_RFPM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,7)))


/* USB Host Controller (USBHC) */
#define TSB_HC_CONTROL_PLE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,2)))
#define TSB_HC_CONTROL_IE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,3)))
#define TSB_HC_CONTROL_CLE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,4)))
#define TSB_HC_CONTROL_BLE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,5)))
#define TSB_HC_CONTROL_IR                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,8)))
#define TSB_HC_CONTROL_RWC                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,9)))
#define TSB_HC_CONTROL_RWE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->CONTROL,10)))
#define TSB_HC_COMMANDSTATUS_HCR                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->COMMANDSTATUS,0)))
#define TSB_HC_COMMANDSTATUS_CLF                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->COMMANDSTATUS,1)))
#define TSB_HC_COMMANDSTATUS_BLF                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->COMMANDSTATUS,2)))
#define TSB_HC_COMMANDSTATUS_OCR                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->COMMANDSTATUS,3)))
#define TSB_HC_INTERRUPTSTATUS_SO                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,0)))
#define TSB_HC_INTERRUPTSTATUS_WDH                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,1)))
#define TSB_HC_INTERRUPTSTATUS_SF                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,2)))
#define TSB_HC_INTERRUPTSTATUS_RD                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,3)))
#define TSB_HC_INTERRUPTSTATUS_UE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,4)))
#define TSB_HC_INTERRUPTSTATUS_FNO                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,5)))
#define TSB_HC_INTERRUPTSTATUS_RHSC               (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,6)))
#define TSB_HC_INTERRUPTSTATUS_OC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTSTATUS,30)))
#define TSB_HC_INTERRUPTENABLE_SO                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,0)))
#define TSB_HC_INTERRUPTENABLE_WDH                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,1)))
#define TSB_HC_INTERRUPTENABLE_SF                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,2)))
#define TSB_HC_INTERRUPTENABLE_RD                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,3)))
#define TSB_HC_INTERRUPTENABLE_UE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,4)))
#define TSB_HC_INTERRUPTENABLE_FNO                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,5)))
#define TSB_HC_INTERRUPTENABLE_RHSC               (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,6)))
#define TSB_HC_INTERRUPTENABLE_OC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,30)))
#define TSB_HC_INTERRUPTENABLE_MIE                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTENABLE,31)))
#define TSB_HC_INTERRUPTDISABLE_SO                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,0)))
#define TSB_HC_INTERRUPTDISABLE_WDH               (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,1)))
#define TSB_HC_INTERRUPTDISABLE_SF                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,2)))
#define TSB_HC_INTERRUPTDISABLE_RD                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,3)))
#define TSB_HC_INTERRUPTDISABLE_UE                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,4)))
#define TSB_HC_INTERRUPTDISABLE_FNO               (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,5)))
#define TSB_HC_INTERRUPTDISABLE_RHSC              (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,6)))
#define TSB_HC_INTERRUPTDISABLE_OC                (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,30)))
#define TSB_HC_INTERRUPTDISABLE_MIE               (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->INTERRUPTDISABLE,31)))
#define TSB_HC_FMINTERVAL_FIT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->FMINTERVAL,31)))
#define TSB_HC_FMREMAINING_FRT                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_HC->FMREMAINING,31)))
#define TSB_HC_RHDESCRIPTORA_PSM                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHDESCRIPTORA,8)))
#define TSB_HC_RHDESCRIPTORA_NPS                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHDESCRIPTORA,9)))
#define TSB_HC_RHDESCRIPTORA_DT                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_HC->RHDESCRIPTORA,10)))
#define TSB_HC_RHDESCRIPTORA_OCPM                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHDESCRIPTORA,11)))
#define TSB_HC_RHDESCRIPTORA_NOCP                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHDESCRIPTORA,12)))
#define TSB_HC_RHSTATUS_OCI                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_HC->RHSTATUS,1)))
#define TSB_HC_RHSTATUS_CRWE                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_HC->RHSTATUS,31)))
#define TSB_HC_RHPORTSTATUS1_CCS                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,0)))
#define TSB_HC_RHPORTSTATUS1_PES                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,1)))
#define TSB_HC_RHPORTSTATUS1_PSS                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,2)))
#define TSB_HC_RHPORTSTATUS1_POCI                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,3)))
#define TSB_HC_RHPORTSTATUS1_PRS                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,4)))
#define TSB_HC_RHPORTSTATUS1_PPS                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,8)))
#define TSB_HC_RHPORTSTATUS1_LSDA                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,9)))
#define TSB_HC_RHPORTSTATUS1_CSC                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,16)))
#define TSB_HC_RHPORTSTATUS1_PESC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,17)))
#define TSB_HC_RHPORTSTATUS1_PSSC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,18)))
#define TSB_HC_RHPORTSTATUS1_OCIC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,19)))
#define TSB_HC_RHPORTSTATUS1_PRSC                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->RHPORTSTATUS1,20)))
#define TSB_HC_BCR0_OVCE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->BCR0,29)))
#define TSB_HC_BCR0_TRNS_SUSP                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_HC->BCR0,30)))


/* UDC2 AHB Bridge */
#define TSB_UDFS_INTSTS_INT_SETUP                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,0)))
#define TSB_UDFS_INTSTS_INT_STATUS_NAK            (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,1)))
#define TSB_UDFS_INTSTS_INT_STATUS                (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,2)))
#define TSB_UDFS_INTSTS_INT_RX_ZERO               (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,3)))
#define TSB_UDFS_INTSTS_INT_SOF                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,4)))
#define TSB_UDFS_INTSTS_INT_EP0                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,5)))
#define TSB_UDFS_INTSTS_INT_EP                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,6)))
#define TSB_UDFS_INTSTS_INT_NAK                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,7)))
#define TSB_UDFS_INTSTS_INT_SUSPEND_RESUME        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,8)))
#define TSB_UDFS_INTSTS_INT_USB_RESET             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,9)))
#define TSB_UDFS_INTSTS_INT_USB_RESET_END         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,10)))
#define TSB_UDFS_INTSTS_INT_MW_SET_ADD            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,17)))
#define TSB_UDFS_INTSTS_INT_MW_END_ADD            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,18)))
#define TSB_UDFS_INTSTS_INT_MW_TIMEOUT            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,19)))
#define TSB_UDFS_INTSTS_INT_MW_AHBERR             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,20)))
#define TSB_UDFS_INTSTS_INT_MR_END_ADD            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,21)))
#define TSB_UDFS_INTSTS_INT_MR_EP_DSET            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,22)))
#define TSB_UDFS_INTSTS_INT_MR_AHBERR             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,23)))
#define TSB_UDFS_INTSTS_INT_UDC2_REG_RD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,24)))
#define TSB_UDFS_INTSTS_INT_DMAC_REG_RD           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,25)))
#define TSB_UDFS_INTSTS_INT_POWERDETECT           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,28)))
#define TSB_UDFS_INTSTS_INT_MW_RERR               (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTSTS,29)))
#define TSB_UDFS_INTENB_SUSPEND_RESUME_EN         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,8)))
#define TSB_UDFS_INTENB_RESET_EN                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,9)))
#define TSB_UDFS_INTENB_RESET_END_EN              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,10)))
#define TSB_UDFS_INTENB_MW_SET_ADD_EN             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,17)))
#define TSB_UDFS_INTENB_MW_END_ADD_EN             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,18)))
#define TSB_UDFS_INTENB_MW_TIMEOUT_EN             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,19)))
#define TSB_UDFS_INTENB_MW_AHBERR_EN              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,20)))
#define TSB_UDFS_INTENB_MR_END_ADD_EN             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,21)))
#define TSB_UDFS_INTENB_MR_EP_DSET_EN             (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,22)))
#define TSB_UDFS_INTENB_MR_AHBERR_EN              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,23)))
#define TSB_UDFS_INTENB_UDC2_REG_RD_EN            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,24)))
#define TSB_UDFS_INTENB_DMAC_REG_RD_EN            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,25)))
#define TSB_UDFS_INTENB_POWER_DETECT_EN           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->INTENB,28)))
#define TSB_UDFS_MWTOUT_TIMEOUT_EN                (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->MWTOUT,0)))
#define TSB_UDFS_C2STSET_TX0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->C2STSET,0)))
#define TSB_UDFS_C2STSET_EOPB_ENABLE              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->C2STSET,4)))
#define TSB_UDFS_DMACRDREQ_DMARDCLR               (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->DMACRDREQ,30)))
#define TSB_UDFS_DMACRDREQ_DMARDREQ               (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->DMACRDREQ,31)))
#define TSB_UDFS_UDC2RDREQ_UDC2RDCLR              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->UDC2RDREQ,30)))
#define TSB_UDFS_UDC2RDREQ_UDC2RDREQ              (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->UDC2RDREQ,31)))
#define TSB_UDFS_ARBTSET_ABTMOD                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->ARBTSET,28)))
#define TSB_UDFS_ARBTSET_ABT_EN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->ARBTSET,31)))
#define TSB_UDFS_PWCTL_USB_RESET                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,0)))
#define TSB_UDFS_PWCTL_PW_RESETB                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,1)))
#define TSB_UDFS_PWCTL_PW_DETECT                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,2)))
#define TSB_UDFS_PWCTL_PHY_SUSPEND                (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,3)))
#define TSB_UDFS_PWCTL_SUSPEND_X                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,4)))
#define TSB_UDFS_PWCTL_PHY_RESETB                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,5)))
#define TSB_UDFS_PWCTL_PHY_REMOTE_WKUP            (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,6)))
#define TSB_UDFS_PWCTL_WAKEUP_EN                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS->PWCTL,7)))
#define TSB_UDFS_MSTSTS_MWEPDSET                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->MSTSTS,0)))
#define TSB_UDFS_MSTSTS_MREPDSET                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->MSTSTS,1)))
#define TSB_UDFS_MSTSTS_MWBFEMP                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->MSTSTS,2)))
#define TSB_UDFS_MSTSTS_MRBFEMP                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->MSTSTS,3)))
#define TSB_UDFS_MSTSTS_MREPEMPTY                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS->MSTSTS,4)))


/* UDC2(USB -Spec2.0 Device contoller) */
#define TSB_UDFS2_ADR_SUSPEND                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->ADR,11)))
#define TSB_UDFS2_ADR_EP_BI_MODE                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->ADR,14)))
#define TSB_UDFS2_ADR_STAGE_ERR                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->ADR,15)))
#define TSB_UDFS2_FRM_CREATE_SOF                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->FRM,15)))
#define TSB_UDFS2_CMD_INT_TOGGLE                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->CMD,15)))
#define TSB_UDFS2_BRQ_DIR                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->BRQ,7)))
#define TSB_UDFS2_INT_I_SETUP                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,0)))
#define TSB_UDFS2_INT_I_STATUS_NAK                (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,1)))
#define TSB_UDFS2_INT_I_STATUS                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,2)))
#define TSB_UDFS2_INT_I_RX_DATA0                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,3)))
#define TSB_UDFS2_INT_I_SOF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,4)))
#define TSB_UDFS2_INT_I_EP0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,5)))
#define TSB_UDFS2_INT_I_EP                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,6)))
#define TSB_UDFS2_INT_I_NAK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,7)))
#define TSB_UDFS2_INT_M_SETUP                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,8)))
#define TSB_UDFS2_INT_M_STATUS_NAK                (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,9)))
#define TSB_UDFS2_INT_M_STATUS                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,10)))
#define TSB_UDFS2_INT_M_RX_DATA0                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,11)))
#define TSB_UDFS2_INT_M_SOF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,12)))
#define TSB_UDFS2_INT_M_EP0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,13)))
#define TSB_UDFS2_INT_M_EP                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,14)))
#define TSB_UDFS2_INT_M_NAK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INT,15)))
#define TSB_UDFS2_INTEP_I_EP1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,1)))
#define TSB_UDFS2_INTEP_I_EP2                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,2)))
#define TSB_UDFS2_INTEP_I_EP3                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,3)))
#define TSB_UDFS2_INTEP_I_EP4                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,4)))
#define TSB_UDFS2_INTEP_I_EP5                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,5)))
#define TSB_UDFS2_INTEP_I_EP6                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,6)))
#define TSB_UDFS2_INTEP_I_EP7                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTEP,7)))
#define TSB_UDFS2_EP0MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP0MSZ,12)))
#define TSB_UDFS2_EP0MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP0MSZ,15)))
#define TSB_UDFS2_EP0STS_EP0_MASK                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP0STS,15)))
#define TSB_UDFS2_EP1MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1MSZ,12)))
#define TSB_UDFS2_EP1MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1MSZ,15)))
#define TSB_UDFS2_EP1STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1STS,7)))
#define TSB_UDFS2_EP1STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1STS,8)))
#define TSB_UDFS2_EP1STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1STS,14)))
#define TSB_UDFS2_EP1STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP1STS,15)))
#define TSB_UDFS2_EP2MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2MSZ,12)))
#define TSB_UDFS2_EP2MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2MSZ,15)))
#define TSB_UDFS2_EP2STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2STS,7)))
#define TSB_UDFS2_EP2STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2STS,8)))
#define TSB_UDFS2_EP2STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2STS,14)))
#define TSB_UDFS2_EP2STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP2STS,15)))
#define TSB_UDFS2_EP3MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3MSZ,12)))
#define TSB_UDFS2_EP3MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3MSZ,15)))
#define TSB_UDFS2_EP3STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3STS,7)))
#define TSB_UDFS2_EP3STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3STS,8)))
#define TSB_UDFS2_EP3STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3STS,14)))
#define TSB_UDFS2_EP3STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP3STS,15)))
#define TSB_UDFS2_EP4MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4MSZ,12)))
#define TSB_UDFS2_EP4MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4MSZ,15)))
#define TSB_UDFS2_EP4STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4STS,7)))
#define TSB_UDFS2_EP4STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4STS,8)))
#define TSB_UDFS2_EP4STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4STS,14)))
#define TSB_UDFS2_EP4STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP4STS,15)))
#define TSB_UDFS2_EP5MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5MSZ,12)))
#define TSB_UDFS2_EP5MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5MSZ,15)))
#define TSB_UDFS2_EP5STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5STS,7)))
#define TSB_UDFS2_EP5STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5STS,8)))
#define TSB_UDFS2_EP5STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5STS,14)))
#define TSB_UDFS2_EP5STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP5STS,15)))
#define TSB_UDFS2_EP6MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6MSZ,12)))
#define TSB_UDFS2_EP6MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6MSZ,15)))
#define TSB_UDFS2_EP6STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6STS,7)))
#define TSB_UDFS2_EP6STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6STS,8)))
#define TSB_UDFS2_EP6STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6STS,14)))
#define TSB_UDFS2_EP6STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP6STS,15)))
#define TSB_UDFS2_EP7MSZ_DSET                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7MSZ,12)))
#define TSB_UDFS2_EP7MSZ_TX_0DATA                 (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7MSZ,15)))
#define TSB_UDFS2_EP7STS_DIR                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7STS,7)))
#define TSB_UDFS2_EP7STS_DISABLE                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7STS,8)))
#define TSB_UDFS2_EP7STS_BUS_SEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7STS,14)))
#define TSB_UDFS2_EP7STS_PKT_MODE                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->EP7STS,15)))
#define TSB_UDFS2_INTNAK_I_EP1                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,1)))
#define TSB_UDFS2_INTNAK_I_EP2                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,2)))
#define TSB_UDFS2_INTNAK_I_EP3                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,3)))
#define TSB_UDFS2_INTNAK_I_EP4                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,4)))
#define TSB_UDFS2_INTNAK_I_EP5                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,5)))
#define TSB_UDFS2_INTNAK_I_EP6                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,6)))
#define TSB_UDFS2_INTNAK_I_EP7                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAK,7)))
#define TSB_UDFS2_INTNAKMSK_M_EP1                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,1)))
#define TSB_UDFS2_INTNAKMSK_M_EP2                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,2)))
#define TSB_UDFS2_INTNAKMSK_M_EP3                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,3)))
#define TSB_UDFS2_INTNAKMSK_M_EP4                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,4)))
#define TSB_UDFS2_INTNAKMSK_M_EP5                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,5)))
#define TSB_UDFS2_INTNAKMSK_M_EP6                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,6)))
#define TSB_UDFS2_INTNAKMSK_M_EP7                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_UDFS2->INTNAKMSK,7)))


/* UDC2 AHB Bridge */
#define TSB_EM_IFCR_IOTOUT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFCR,8)))
#define TSB_EM_IFCR_DMATOUT                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFCR,9)))
#define TSB_EM_IFCR_DMAERR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFCR,10)))
#define TSB_EM_IFINTST_EMDMACINT                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,0)))
#define TSB_EM_IFINTST_SLAVE0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,8)))
#define TSB_EM_IFINTST_SLAVE1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,9)))
#define TSB_EM_IFINTST_SLAVE2                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,10)))
#define TSB_EM_IFINTST_SLAVE3                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,11)))
#define TSB_EM_IFINTST_IOTOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,15)))
#define TSB_EM_IFINTST_MASTER0                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,16)))
#define TSB_EM_IFINTST_MASTER1                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,17)))
#define TSB_EM_IFINTST_MASTER2                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,18)))
#define TSB_EM_IFINTST_DMATOUT                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTST,23)))
#define TSB_EM_IFINTEN_EMDMACINT                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,0)))
#define TSB_EM_IFINTEN_SLAVE0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,8)))
#define TSB_EM_IFINTEN_SLAVE1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,9)))
#define TSB_EM_IFINTEN_SLAVE2                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,10)))
#define TSB_EM_IFINTEN_SLAVE3                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,11)))
#define TSB_EM_IFINTEN_IOTOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,15)))
#define TSB_EM_IFINTEN_MASTER0                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,16)))
#define TSB_EM_IFINTEN_MASTER1                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,17)))
#define TSB_EM_IFINTEN_MASTER2                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,18)))
#define TSB_EM_IFINTEN_DMATOUT                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->IFINTEN,23)))
#define TSB_EM_DCR_SWR                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DCR,0)))
#define TSB_EM_DCR_DE                             (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DCR,6)))
#define TSB_EM_DTEN_TRNS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DTEN,0)))
#define TSB_EM_DREN_RCV                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DREN,0)))
#define TSB_EM_DINTST_RINT1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,0)))
#define TSB_EM_DINTST_RINT2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,1)))
#define TSB_EM_DINTST_RINT3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,2)))
#define TSB_EM_DINTST_RINT4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,3)))
#define TSB_EM_DINTST_RINT5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,4)))
#define TSB_EM_DINTST_RINT8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,7)))
#define TSB_EM_DINTST_TINT1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,8)))
#define TSB_EM_DINTST_TINT2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,9)))
#define TSB_EM_DINTST_TINT3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,10)))
#define TSB_EM_DINTST_TINT4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,11)))
#define TSB_EM_DINTST_RFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,16)))
#define TSB_EM_DINTST_RDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,17)))
#define TSB_EM_DINTST_FRC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,18)))
#define TSB_EM_DINTST_TFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,19)))
#define TSB_EM_DINTST_TDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,20)))
#define TSB_EM_DINTST_FTC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,21)))
#define TSB_EM_DINTST_MINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,22)))
#define TSB_EM_DINTST_BER                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,23)))
#define TSB_EM_DINTST_RFRMER                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,24)))
#define TSB_EM_DINTST_RABT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,25)))
#define TSB_EM_DINTST_TABT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,26)))
#define TSB_EM_DINTST_TWB                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTST,30)))
#define TSB_EM_DINTEN_RINT1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,0)))
#define TSB_EM_DINTEN_RINT2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,1)))
#define TSB_EM_DINTEN_RINT3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,2)))
#define TSB_EM_DINTEN_RINT4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,3)))
#define TSB_EM_DINTEN_RINT5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,4)))
#define TSB_EM_DINTEN_RINT8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,7)))
#define TSB_EM_DINTEN_TINT1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,8)))
#define TSB_EM_DINTEN_TINT2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,9)))
#define TSB_EM_DINTEN_TINT3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,10)))
#define TSB_EM_DINTEN_TINT4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,11)))
#define TSB_EM_DINTEN_RFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,16)))
#define TSB_EM_DINTEN_RDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,17)))
#define TSB_EM_DINTEN_FRC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,18)))
#define TSB_EM_DINTEN_TFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,19)))
#define TSB_EM_DINTEN_TDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,20)))
#define TSB_EM_DINTEN_FTC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,21)))
#define TSB_EM_DINTEN_MINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,22)))
#define TSB_EM_DINTEN_BER                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,23)))
#define TSB_EM_DINTEN_RFRMER                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,24)))
#define TSB_EM_DINTEN_RABT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,25)))
#define TSB_EM_DINTEN_TABT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,26)))
#define TSB_EM_DINTEN_TWB                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DINTEN,30)))
#define TSB_EM_DERR_RINT1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,0)))
#define TSB_EM_DERR_RINT2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,1)))
#define TSB_EM_DERR_RINT3                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,2)))
#define TSB_EM_DERR_RINT4                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,3)))
#define TSB_EM_DERR_RINT5                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,4)))
#define TSB_EM_DERR_RINT8                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,7)))
#define TSB_EM_DERR_TINT1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,8)))
#define TSB_EM_DERR_TINT2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,9)))
#define TSB_EM_DERR_TINT3                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,10)))
#define TSB_EM_DERR_TINT4                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DERR,11)))
#define TSB_EM_DRRCR_RR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DRRCR,0)))
#define TSB_EM_DRRCR_RNR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DRRCR,1)))
#define TSB_EM_DTIMER_TIS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DTIMER,0)))
#define TSB_EM_DTIMER_TIM                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->DTIMER,4)))
#define TSB_EM_CCR_PRM                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,0)))
#define TSB_EM_CCR_DPM                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,1)))
#define TSB_EM_CCR_OLB                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,2)))
#define TSB_EM_CCR_ILB                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,3)))
#define TSB_EM_CCR_TPE                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,5)))
#define TSB_EM_CCR_RPE                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,6)))
#define TSB_EM_CCR_MPM                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,9)))
#define TSB_EM_CCR_CER                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,12)))
#define TSB_EM_CCR_TXF                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,16)))
#define TSB_EM_CCR_RXF                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,17)))
#define TSB_EM_CCR_PFR                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,18)))
#define TSB_EM_CCR_TPF                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,19)))
#define TSB_EM_CCR_TPC                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CCR,20)))
#define TSB_EM_CINTST_FCIDTCT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTST,0)))
#define TSB_EM_CINTST_MAGICPKT                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTST,1)))
#define TSB_EM_CINTST_LINKCHNG                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTST,2)))
#define TSB_EM_CINTST_PSRTROV                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTST,4)))
#define TSB_EM_CINTST_BRDSRCV                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTST,5)))
#define TSB_EM_CINTEN_FCIDTCT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTEN,0)))
#define TSB_EM_CINTEN_MAGICPKT                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTEN,1)))
#define TSB_EM_CINTEN_LINKCHNG                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTEN,2)))
#define TSB_EM_CINTEN_PSRTROV                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTEN,4)))
#define TSB_EM_CINTEN_BRDSRCV                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CINTEN,5)))
#define TSB_EM_CMIICR_MDC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CMIICR,0)))
#define TSB_EM_CMIICR_MMD                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CMIICR,1)))
#define TSB_EM_CMIICR_MDO                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CMIICR,2)))
#define TSB_EM_CMIICR_MDI                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EM->CMIICR,3)))
#define TSB_EM_CPHYST_LINK                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EM->CPHYST,0)))


/* Synchronous Serial Port */
#define TSB_SSP0_SR_TFE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->SR,0)))
#define TSB_SSP0_SR_TNF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->SR,1)))
#define TSB_SSP0_SR_RNE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->SR,2)))
#define TSB_SSP0_SR_RFF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->SR,3)))
#define TSB_SSP0_SR_BSY                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->SR,4)))
#define TSB_SSP0_RIS_RORRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->RIS,0)))
#define TSB_SSP0_RIS_RTRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->RIS,1)))
#define TSB_SSP0_RIS_RXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->RIS,2)))
#define TSB_SSP0_RIS_TXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->RIS,3)))
#define TSB_SSP0_MIS_RORMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->MIS,0)))
#define TSB_SSP0_MIS_RTMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->MIS,1)))
#define TSB_SSP0_MIS_RXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->MIS,2)))
#define TSB_SSP0_MIS_TXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP0->MIS,3)))

#define TSB_SSP1_SR_TFE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->SR,0)))
#define TSB_SSP1_SR_TNF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->SR,1)))
#define TSB_SSP1_SR_RNE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->SR,2)))
#define TSB_SSP1_SR_RFF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->SR,3)))
#define TSB_SSP1_SR_BSY                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->SR,4)))
#define TSB_SSP1_RIS_RORRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->RIS,0)))
#define TSB_SSP1_RIS_RTRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->RIS,1)))
#define TSB_SSP1_RIS_RXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->RIS,2)))
#define TSB_SSP1_RIS_TXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->RIS,3)))
#define TSB_SSP1_MIS_RORMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->MIS,0)))
#define TSB_SSP1_MIS_RTMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->MIS,1)))
#define TSB_SSP1_MIS_RXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->MIS,2)))
#define TSB_SSP1_MIS_TXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP1->MIS,3)))

#define TSB_SSP2_SR_TFE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->SR,0)))
#define TSB_SSP2_SR_TNF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->SR,1)))
#define TSB_SSP2_SR_RNE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->SR,2)))
#define TSB_SSP2_SR_RFF                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->SR,3)))
#define TSB_SSP2_SR_BSY                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->SR,4)))
#define TSB_SSP2_RIS_RORRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->RIS,0)))
#define TSB_SSP2_RIS_RTRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->RIS,1)))
#define TSB_SSP2_RIS_RXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->RIS,2)))
#define TSB_SSP2_RIS_TXRIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->RIS,3)))
#define TSB_SSP2_MIS_RORMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->MIS,0)))
#define TSB_SSP2_MIS_RTMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->MIS,1)))
#define TSB_SSP2_MIS_RXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->MIS,2)))
#define TSB_SSP2_MIS_TXMIS                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SSP2->MIS,3)))


/* ARM Prime Cell PL011 */
#define TSB_UART4_DR_FE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DR,8)))
#define TSB_UART4_DR_PE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DR,9)))
#define TSB_UART4_DR_BE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DR,10)))
#define TSB_UART4_DR_OE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DR,11)))
#define TSB_UART4_RSR_FE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RSR,0)))
#define TSB_UART4_RSR_PE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RSR,1)))
#define TSB_UART4_RSR_BE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RSR,2)))
#define TSB_UART4_RSR_OE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RSR,3)))
#define TSB_UART4_FR_CTS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,0)))
#define TSB_UART4_FR_DSR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,1)))
#define TSB_UART4_FR_DCD                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,2)))
#define TSB_UART4_FR_BUSY                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,3)))
#define TSB_UART4_FR_RXFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,4)))
#define TSB_UART4_FR_TXFF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,5)))
#define TSB_UART4_FR_RXFF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,6)))
#define TSB_UART4_FR_TXFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,7)))
#define TSB_UART4_FR_RI                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->FR,8)))
#define TSB_UART4_LCR_H_BRK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,0)))
#define TSB_UART4_LCR_H_PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,1)))
#define TSB_UART4_LCR_H_EPS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,2)))
#define TSB_UART4_LCR_H_STP2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,3)))
#define TSB_UART4_LCR_H_FEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,4)))
#define TSB_UART4_LCR_H_SPS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->LCR_H,7)))
#define TSB_UART4_CR_UARTEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,0)))
#define TSB_UART4_CR_SIREN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,1)))
#define TSB_UART4_CR_SIRLP                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,2)))
#define TSB_UART4_CR_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,8)))
#define TSB_UART4_CR_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,9)))
#define TSB_UART4_CR_DTR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,10)))
#define TSB_UART4_CR_RTS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,11)))
#define TSB_UART4_CR_RTSEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,14)))
#define TSB_UART4_CR_CTSEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->CR,15)))
#define TSB_UART4_IMSC_RIMIM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,0)))
#define TSB_UART4_IMSC_CTSMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,1)))
#define TSB_UART4_IMSC_DCDMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,2)))
#define TSB_UART4_IMSC_DSRMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,3)))
#define TSB_UART4_IMSC_RXIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,4)))
#define TSB_UART4_IMSC_TXIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,5)))
#define TSB_UART4_IMSC_RTIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,6)))
#define TSB_UART4_IMSC_FEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,7)))
#define TSB_UART4_IMSC_PEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,8)))
#define TSB_UART4_IMSC_BEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,9)))
#define TSB_UART4_IMSC_OEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->IMSC,10)))
#define TSB_UART4_RIS_RIRMIS                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,0)))
#define TSB_UART4_RIS_CTSRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,1)))
#define TSB_UART4_RIS_DCDRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,2)))
#define TSB_UART4_RIS_DSRRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,3)))
#define TSB_UART4_RIS_RXRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,4)))
#define TSB_UART4_RIS_TXRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,5)))
#define TSB_UART4_RIS_RTRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,6)))
#define TSB_UART4_RIS_FERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,7)))
#define TSB_UART4_RIS_PERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,8)))
#define TSB_UART4_RIS_BERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,9)))
#define TSB_UART4_RIS_OERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->RIS,10)))
#define TSB_UART4_MIS_RIMMIS                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,0)))
#define TSB_UART4_MIS_CTSMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,1)))
#define TSB_UART4_MIS_DCDMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,2)))
#define TSB_UART4_MIS_DSRMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,3)))
#define TSB_UART4_MIS_RXMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,4)))
#define TSB_UART4_MIS_TXMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,5)))
#define TSB_UART4_MIS_RTMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,6)))
#define TSB_UART4_MIS_FEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,7)))
#define TSB_UART4_MIS_PEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,8)))
#define TSB_UART4_MIS_BEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,9)))
#define TSB_UART4_MIS_OEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART4->MIS,10)))
#define TSB_UART4_DMACR_RXDMAE                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DMACR,0)))
#define TSB_UART4_DMACR_TXDMAE                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DMACR,1)))
#define TSB_UART4_DMACR_DMAONERR                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART4->DMACR,2)))

#define TSB_UART5_DR_FE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DR,8)))
#define TSB_UART5_DR_PE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DR,9)))
#define TSB_UART5_DR_BE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DR,10)))
#define TSB_UART5_DR_OE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DR,11)))
#define TSB_UART5_RSR_FE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RSR,0)))
#define TSB_UART5_RSR_PE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RSR,1)))
#define TSB_UART5_RSR_BE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RSR,2)))
#define TSB_UART5_RSR_OE                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RSR,3)))
#define TSB_UART5_FR_CTS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,0)))
#define TSB_UART5_FR_DSR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,1)))
#define TSB_UART5_FR_DCD                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,2)))
#define TSB_UART5_FR_BUSY                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,3)))
#define TSB_UART5_FR_RXFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,4)))
#define TSB_UART5_FR_TXFF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,5)))
#define TSB_UART5_FR_RXFF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,6)))
#define TSB_UART5_FR_TXFE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,7)))
#define TSB_UART5_FR_RI                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->FR,8)))
#define TSB_UART5_LCR_H_BRK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,0)))
#define TSB_UART5_LCR_H_PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,1)))
#define TSB_UART5_LCR_H_EPS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,2)))
#define TSB_UART5_LCR_H_STP2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,3)))
#define TSB_UART5_LCR_H_FEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,4)))
#define TSB_UART5_LCR_H_SPS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->LCR_H,7)))
#define TSB_UART5_CR_UARTEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,0)))
#define TSB_UART5_CR_SIREN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,1)))
#define TSB_UART5_CR_SIRLP                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,2)))
#define TSB_UART5_CR_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,8)))
#define TSB_UART5_CR_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,9)))
#define TSB_UART5_CR_DTR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,10)))
#define TSB_UART5_CR_RTS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,11)))
#define TSB_UART5_CR_RTSEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,14)))
#define TSB_UART5_CR_CTSEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->CR,15)))
#define TSB_UART5_IMSC_RIMIM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,0)))
#define TSB_UART5_IMSC_CTSMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,1)))
#define TSB_UART5_IMSC_DCDMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,2)))
#define TSB_UART5_IMSC_DSRMIM                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,3)))
#define TSB_UART5_IMSC_RXIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,4)))
#define TSB_UART5_IMSC_TXIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,5)))
#define TSB_UART5_IMSC_RTIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,6)))
#define TSB_UART5_IMSC_FEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,7)))
#define TSB_UART5_IMSC_PEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,8)))
#define TSB_UART5_IMSC_BEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,9)))
#define TSB_UART5_IMSC_OEIM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->IMSC,10)))
#define TSB_UART5_RIS_RIRMIS                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,0)))
#define TSB_UART5_RIS_CTSRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,1)))
#define TSB_UART5_RIS_DCDRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,2)))
#define TSB_UART5_RIS_DSRRMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,3)))
#define TSB_UART5_RIS_RXRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,4)))
#define TSB_UART5_RIS_TXRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,5)))
#define TSB_UART5_RIS_RTRIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,6)))
#define TSB_UART5_RIS_FERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,7)))
#define TSB_UART5_RIS_PERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,8)))
#define TSB_UART5_RIS_BERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,9)))
#define TSB_UART5_RIS_OERIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->RIS,10)))
#define TSB_UART5_MIS_RIMMIS                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,0)))
#define TSB_UART5_MIS_CTSMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,1)))
#define TSB_UART5_MIS_DCDMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,2)))
#define TSB_UART5_MIS_DSRMMIS                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,3)))
#define TSB_UART5_MIS_RXMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,4)))
#define TSB_UART5_MIS_TXMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,5)))
#define TSB_UART5_MIS_RTMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,6)))
#define TSB_UART5_MIS_FEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,7)))
#define TSB_UART5_MIS_PEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,8)))
#define TSB_UART5_MIS_BEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,9)))
#define TSB_UART5_MIS_OEMIS                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_UART5->MIS,10)))
#define TSB_UART5_DMACR_RXDMAE                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DMACR,0)))
#define TSB_UART5_DMACR_TXDMAE                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DMACR,1)))
#define TSB_UART5_DMACR_DMAONERR                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_UART5->DMACR,2)))


/* DMA Controller */
#define TSB_DMAA_STATUS_MASTER_ENABLE             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAA->STATUS,0)))
#define TSB_DMAA_CFG_MASTER_ENABLE                (*((__O  uint32_t *)BITBAND_PERI(&TSB_DMAA->CFG,0)))
#define TSB_DMAA_ERRCLR_ERR_CLR                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_DMAA->ERRCLR,0)))

#define TSB_DMAB_STATUS_MASTER_ENABLE             (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMAB->STATUS,0)))
#define TSB_DMAB_CFG_MASTER_ENABLE                (*((__O  uint32_t *)BITBAND_PERI(&TSB_DMAB->CFG,0)))
#define TSB_DMAB_ERRCLR_ERR_CLR                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_DMAB->ERRCLR,0)))


/* Analog-to-Digital Converter (AD) */
#define TSB_ADA_MOD0_ADS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD0,0)))
#define TSB_ADA_MOD0_HPADS                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD0,1)))
#define TSB_ADA_MOD1_ADHWE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,0)))
#define TSB_ADA_MOD1_ADHWS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,1)))
#define TSB_ADA_MOD1_HPADHWE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,2)))
#define TSB_ADA_MOD1_HPADHWS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,3)))
#define TSB_ADA_MOD1_RCUT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,5)))
#define TSB_ADA_MOD1_I2AD                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,6)))
#define TSB_ADA_MOD1_DACON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,7)))
#define TSB_ADA_MOD3_SCAN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD3,0)))
#define TSB_ADA_MOD3_REPEAT                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD3,1)))
#define TSB_ADA_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,4)))
#define TSB_ADA_CMPCR0_CMPCOND0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,4)))
#define TSB_ADA_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,7)))
#define TSB_ADA_CMPCR1_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,4)))
#define TSB_ADA_CMPCR1_CMPCOND0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,4)))
#define TSB_ADA_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,7)))

#define TSB_ADB_MOD0_ADS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD0,0)))
#define TSB_ADB_MOD0_HPADS                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD0,1)))
#define TSB_ADB_MOD1_ADHWE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,0)))
#define TSB_ADB_MOD1_ADHWS                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,1)))
#define TSB_ADB_MOD1_HPADHWE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,2)))
#define TSB_ADB_MOD1_HPADHWS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,3)))
#define TSB_ADB_MOD1_RCUT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,5)))
#define TSB_ADB_MOD1_I2AD                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,6)))
#define TSB_ADB_MOD1_DACON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,7)))
#define TSB_ADB_MOD3_SCAN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD3,0)))
#define TSB_ADB_MOD3_REPEAT                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD3,1)))
#define TSB_ADB_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,4)))
#define TSB_ADB_CMPCR0_CMPCOND0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,4)))
#define TSB_ADB_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,7)))
#define TSB_ADB_CMPCR1_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,4)))
#define TSB_ADB_CMPCR1_CMPCOND0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,4)))
#define TSB_ADB_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,7)))


/* Digital-to-Analog Converter (DA) */
#define TSB_DA0_CNT_OP                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA0->CNT,0)))
#define TSB_DA0_CNT_REFON                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA0->CNT,1)))
#define TSB_DA0_DCTL_DMAEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA0->DCTL,7)))
#define TSB_DA0_DCTL_TRGEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA0->DCTL,8)))
#define TSB_DA0_TCTL_SWTRG                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_DA0->TCTL,0)))
#define TSB_DA0_TCTL_DACCLR                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_DA0->TCTL,15)))

#define TSB_DA1_CNT_OP                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA1->CNT,0)))
#define TSB_DA1_CNT_REFON                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA1->CNT,1)))
#define TSB_DA1_DCTL_DMAEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA1->DCTL,7)))
#define TSB_DA1_DCTL_TRGEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_DA1->DCTL,8)))
#define TSB_DA1_TCTL_SWTRG                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_DA1->TCTL,0)))
#define TSB_DA1_TCTL_DACCLR                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_DA1->TCTL,15)))


/* External Bus Interface(EXB) */
#define TSB_EXB_MOD_EXBSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->MOD,0)))
#define TSB_EXB_CS0_CSW0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS0,0)))
#define TSB_EXB_CS0_CSW1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS0,1)))
#define TSB_EXB_CS0_CSW2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS0,2)))
#define TSB_EXB_CS1_CSW0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS1,0)))
#define TSB_EXB_CS1_CSW1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS1,1)))
#define TSB_EXB_CS1_CSW2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS1,2)))
#define TSB_EXB_CS2_CSW0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS2,0)))
#define TSB_EXB_CS2_CSW1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS2,1)))
#define TSB_EXB_CS2_CSW2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS2,2)))
#define TSB_EXB_CS3_CSW0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS3,0)))
#define TSB_EXB_CS3_CSW1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS3,1)))
#define TSB_EXB_CS3_CSW2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EXB->CS3,2)))


/* External Bus Interface(EXB) */
#define TSB_ADCI_VM01_SWATRG                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADCI->VM01,7)))
#define TSB_ADCI_VM02_TRGAEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADCI->VM02,0)))
#define TSB_ADCI_VM02_TRGASTA                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADCI->VM02,4)))
#define TSB_ADCI_VM02_ADILV                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADCI->VM02,7)))


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
#define TSB_PA_FR2_PA1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,1)))
#define TSB_PA_FR2_PA2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,2)))
#define TSB_PA_FR2_PA3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,3)))
#define TSB_PA_FR2_PA4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,4)))
#define TSB_PA_FR2_PA5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,5)))
#define TSB_PA_FR2_PA6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,6)))
#define TSB_PA_FR2_PA7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,7)))
#define TSB_PA_FR3_PA3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR3,3)))
#define TSB_PA_FR3_PA5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR3,5)))
#define TSB_PA_FR3_PA6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR3,6)))
#define TSB_PA_FR3_PA7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR3,7)))
#define TSB_PA_FR4_PA7F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR4,7)))
#define TSB_PA_FR5_PA7F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR5,7)))
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
#define TSB_PB_CR_PB0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,0)))
#define TSB_PB_CR_PB1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,1)))
#define TSB_PB_CR_PB2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,2)))
#define TSB_PB_CR_PB3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,3)))
#define TSB_PB_CR_PB4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,4)))
#define TSB_PB_CR_PB5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,5)))
#define TSB_PB_CR_PB6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,6)))
#define TSB_PB_FR1_PB0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,0)))
#define TSB_PB_FR1_PB1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,1)))
#define TSB_PB_FR1_PB2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,2)))
#define TSB_PB_FR1_PB3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,3)))
#define TSB_PB_FR1_PB4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,4)))
#define TSB_PB_FR1_PB5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,5)))
#define TSB_PB_FR1_PB6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,6)))
#define TSB_PB_FR2_PB2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR2,2)))
#define TSB_PB_FR2_PB3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR2,3)))
#define TSB_PB_FR2_PB4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR2,4)))
#define TSB_PB_FR2_PB5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR2,5)))
#define TSB_PB_FR2_PB6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR2,6)))
#define TSB_PB_FR3_PB0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,0)))
#define TSB_PB_FR3_PB1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,1)))
#define TSB_PB_FR3_PB2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,2)))
#define TSB_PB_FR3_PB3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,3)))
#define TSB_PB_FR3_PB4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,4)))
#define TSB_PB_FR3_PB5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR3,5)))
#define TSB_PB_FR4_PB2F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR4,2)))
#define TSB_PB_FR4_PB3F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR4,3)))
#define TSB_PB_FR4_PB4F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR4,4)))
#define TSB_PB_FR4_PB5F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR4,5)))
#define TSB_PB_FR4_PB6F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR4,6)))
#define TSB_PB_OD_PB0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,0)))
#define TSB_PB_OD_PB1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,1)))
#define TSB_PB_OD_PB2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,2)))
#define TSB_PB_OD_PB3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,3)))
#define TSB_PB_OD_PB4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,4)))
#define TSB_PB_OD_PB5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,5)))
#define TSB_PB_OD_PB6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,6)))
#define TSB_PB_PUP_PB0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,0)))
#define TSB_PB_PUP_PB1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,1)))
#define TSB_PB_PUP_PB2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,2)))
#define TSB_PB_PUP_PB3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,4)))
#define TSB_PB_PUP_PB5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PDN_PB0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,0)))
#define TSB_PB_PDN_PB1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,1)))
#define TSB_PB_PDN_PB2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,2)))
#define TSB_PB_PDN_PB3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,3)))
#define TSB_PB_PDN_PB4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,4)))
#define TSB_PB_PDN_PB5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,5)))
#define TSB_PB_PDN_PB6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,6)))
#define TSB_PB_IE_PB0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,0)))
#define TSB_PB_IE_PB1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,1)))
#define TSB_PB_IE_PB2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,2)))
#define TSB_PB_IE_PB3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))


/* General Purpose Input/Output Port (PC) */
#define TSB_PC_DATA_PC0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,0)))
#define TSB_PC_DATA_PC1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,1)))
#define TSB_PC_DATA_PC2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,2)))
#define TSB_PC_DATA_PC3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,3)))
#define TSB_PC_DATA_PC4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,4)))
#define TSB_PC_DATA_PC5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,5)))
#define TSB_PC_DATA_PC6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,6)))
#define TSB_PC_DATA_PC7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,7)))
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
#define TSB_PC_FR2_PC0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR2,0)))
#define TSB_PC_FR2_PC1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR2,1)))
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
#define TSB_PE_FR3_PE0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,0)))
#define TSB_PE_FR3_PE1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,1)))
#define TSB_PE_FR3_PE2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,2)))
#define TSB_PE_FR3_PE3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,3)))
#define TSB_PE_FR3_PE4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,4)))
#define TSB_PE_FR3_PE5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,5)))
#define TSB_PE_FR3_PE6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,6)))
#define TSB_PE_FR3_PE7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR3,7)))
#define TSB_PE_FR4_PE0F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR4,0)))
#define TSB_PE_FR4_PE1F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR4,1)))
#define TSB_PE_FR4_PE3F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR4,3)))
#define TSB_PE_FR4_PE4F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR4,4)))
#define TSB_PE_FR4_PE7F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR4,7)))
#define TSB_PE_FR5_PE0F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,0)))
#define TSB_PE_FR5_PE1F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,1)))
#define TSB_PE_FR5_PE2F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,2)))
#define TSB_PE_FR5_PE3F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,3)))
#define TSB_PE_FR5_PE4F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,4)))
#define TSB_PE_FR5_PE7F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR5,7)))
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
#define TSB_PF_DATA_PF5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,5)))
#define TSB_PF_DATA_PF6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,6)))
#define TSB_PF_DATA_PF7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,7)))
#define TSB_PF_CR_PF0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,1)))
#define TSB_PF_CR_PF2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,2)))
#define TSB_PF_CR_PF3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,3)))
#define TSB_PF_CR_PF4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,4)))
#define TSB_PF_CR_PF5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,5)))
#define TSB_PF_CR_PF6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,6)))
#define TSB_PF_CR_PF7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,7)))
#define TSB_PF_FR1_PF0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,0)))
#define TSB_PF_FR1_PF1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,1)))
#define TSB_PF_FR1_PF2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,2)))
#define TSB_PF_FR1_PF3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,3)))
#define TSB_PF_FR1_PF4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,4)))
#define TSB_PF_FR1_PF5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,5)))
#define TSB_PF_FR1_PF6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,6)))
#define TSB_PF_FR1_PF7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,7)))
#define TSB_PF_FR2_PF4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,4)))
#define TSB_PF_FR2_PF5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,5)))
#define TSB_PF_FR2_PF6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,6)))
#define TSB_PF_FR2_PF7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,7)))
#define TSB_PF_FR3_PF0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,0)))
#define TSB_PF_FR3_PF1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,1)))
#define TSB_PF_FR3_PF2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,2)))
#define TSB_PF_FR3_PF3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,3)))
#define TSB_PF_FR3_PF4F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,4)))
#define TSB_PF_FR3_PF5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,5)))
#define TSB_PF_FR3_PF6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,6)))
#define TSB_PF_FR3_PF7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,7)))
#define TSB_PF_FR4_PF1F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR4,1)))
#define TSB_PF_FR4_PF2F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR4,2)))
#define TSB_PF_FR4_PF5F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR4,5)))
#define TSB_PF_FR4_PF6F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR4,6)))
#define TSB_PF_FR4_PF7F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR4,7)))
#define TSB_PF_OD_PF0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,1)))
#define TSB_PF_OD_PF2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,2)))
#define TSB_PF_OD_PF3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,3)))
#define TSB_PF_OD_PF4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,4)))
#define TSB_PF_OD_PF5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,5)))
#define TSB_PF_OD_PF6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,6)))
#define TSB_PF_OD_PF7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,7)))
#define TSB_PF_PUP_PF0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,1)))
#define TSB_PF_PUP_PF2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,2)))
#define TSB_PF_PUP_PF3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,3)))
#define TSB_PF_PUP_PF4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,4)))
#define TSB_PF_PUP_PF5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,5)))
#define TSB_PF_PUP_PF6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,6)))
#define TSB_PF_PUP_PF7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,7)))
#define TSB_PF_PDN_PF0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,0)))
#define TSB_PF_PDN_PF1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,1)))
#define TSB_PF_PDN_PF2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,2)))
#define TSB_PF_PDN_PF3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,3)))
#define TSB_PF_PDN_PF4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,4)))
#define TSB_PF_PDN_PF5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,5)))
#define TSB_PF_PDN_PF6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,6)))
#define TSB_PF_PDN_PF7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,7)))
#define TSB_PF_IE_PF0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,1)))
#define TSB_PF_IE_PF2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,2)))
#define TSB_PF_IE_PF3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,3)))
#define TSB_PF_IE_PF4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,4)))
#define TSB_PF_IE_PF5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,5)))
#define TSB_PF_IE_PF6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,6)))
#define TSB_PF_IE_PF7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,7)))


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
#define TSB_PG_FR1_PG4F1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_PG->FR1,4)))
#define TSB_PG_FR1_PG5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,5)))
#define TSB_PG_FR1_PG6F1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_PG->FR1,6)))
#define TSB_PG_FR1_PG7F1                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_PG->FR1,7)))
#define TSB_PG_FR2_PG1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,1)))
#define TSB_PG_FR2_PG2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,2)))
#define TSB_PG_FR2_PG3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,3)))
#define TSB_PG_FR2_PG4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,4)))
#define TSB_PG_FR2_PG5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,5)))
#define TSB_PG_FR2_PG6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,6)))
#define TSB_PG_FR2_PG7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR2,7)))
#define TSB_PG_FR3_PG0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,0)))
#define TSB_PG_FR3_PG1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,1)))
#define TSB_PG_FR3_PG2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,2)))
#define TSB_PG_FR3_PG3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,3)))
#define TSB_PG_FR3_PG4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,4)))
#define TSB_PG_FR3_PG5F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,5)))
#define TSB_PG_FR3_PG6F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,6)))
#define TSB_PG_FR3_PG7F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR3,7)))
#define TSB_PG_FR4_PG2F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR4,2)))
#define TSB_PG_FR4_PG3F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR4,3)))
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
#define TSB_PH_FR1_PH3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,3)))
#define TSB_PH_FR1_PH5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,5)))
#define TSB_PH_FR1_PH6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,6)))
#define TSB_PH_FR1_PH7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR1,7)))
#define TSB_PH_FR2_PH0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,0)))
#define TSB_PH_FR2_PH1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,1)))
#define TSB_PH_FR2_PH2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,2)))
#define TSB_PH_FR2_PH3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,3)))
#define TSB_PH_FR2_PH5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,5)))
#define TSB_PH_FR2_PH7F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR2,7)))
#define TSB_PH_FR3_PH0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,0)))
#define TSB_PH_FR3_PH1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,1)))
#define TSB_PH_FR3_PH2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,2)))
#define TSB_PH_FR3_PH3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR3,3)))
#define TSB_PH_FR4_PH2F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR4,2)))
#define TSB_PH_FR4_PH3F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR4,3)))
#define TSB_PH_FR5_PH0F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR5,0)))
#define TSB_PH_FR5_PH1F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR5,1)))
#define TSB_PH_FR5_PH2F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR5,2)))
#define TSB_PH_FR5_PH3F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR5,3)))
#define TSB_PH_FR5_PH4F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->FR5,4)))
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
#define TSB_PH_PDN_PN0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,0)))
#define TSB_PH_PDN_PN1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,1)))
#define TSB_PH_PDN_PN2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,2)))
#define TSB_PH_PDN_PN3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,3)))
#define TSB_PH_PDN_PN4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,4)))
#define TSB_PH_PDN_PN5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,5)))
#define TSB_PH_PDN_PN6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,6)))
#define TSB_PH_PDN_PN7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,7)))
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
#define TSB_PI_DATA_PI4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,4)))
#define TSB_PI_DATA_PI5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,5)))
#define TSB_PI_DATA_PI6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,6)))
#define TSB_PI_DATA_PI7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->DATA,7)))
#define TSB_PI_CR_PI0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,0)))
#define TSB_PI_CR_PI1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,1)))
#define TSB_PI_CR_PI2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,2)))
#define TSB_PI_CR_PI3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,3)))
#define TSB_PI_CR_PI4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,4)))
#define TSB_PI_CR_PI5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,5)))
#define TSB_PI_CR_PI6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,6)))
#define TSB_PI_CR_PI7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->CR,7)))
#define TSB_PI_FR1_PI0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,0)))
#define TSB_PI_FR1_PI1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,1)))
#define TSB_PI_FR1_PI2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,2)))
#define TSB_PI_FR1_PI3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR1,3)))
#define TSB_PI_FR2_PI3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->FR2,3)))
#define TSB_PI_OD_PI0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,0)))
#define TSB_PI_OD_PI1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,1)))
#define TSB_PI_OD_PI2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,2)))
#define TSB_PI_OD_PI3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,3)))
#define TSB_PI_OD_PI4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,4)))
#define TSB_PI_OD_PI5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,5)))
#define TSB_PI_OD_PI6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,6)))
#define TSB_PI_OD_PI7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->OD,7)))
#define TSB_PI_PUP_PI0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,0)))
#define TSB_PI_PUP_PI1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,1)))
#define TSB_PI_PUP_PI2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,2)))
#define TSB_PI_PUP_PI3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,3)))
#define TSB_PI_PUP_PI4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,4)))
#define TSB_PI_PUP_PI5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,5)))
#define TSB_PI_PUP_PI6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,6)))
#define TSB_PI_PUP_PI7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PUP,7)))
#define TSB_PI_PDN_PI0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,0)))
#define TSB_PI_PDN_PI1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,1)))
#define TSB_PI_PDN_PI2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,2)))
#define TSB_PI_PDN_PI3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,3)))
#define TSB_PI_PDN_PI4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,4)))
#define TSB_PI_PDN_PI5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,5)))
#define TSB_PI_PDN_PI6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,6)))
#define TSB_PI_PDN_PI7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->PDN,7)))
#define TSB_PI_IE_PI0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,0)))
#define TSB_PI_IE_PI1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,1)))
#define TSB_PI_IE_PI2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,2)))
#define TSB_PI_IE_PI3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,3)))
#define TSB_PI_IE_PI4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,4)))
#define TSB_PI_IE_PI5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,5)))
#define TSB_PI_IE_PI6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,6)))
#define TSB_PI_IE_PI7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PI->IE,7)))


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
#define TSB_PK_DATA_PK2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,2)))
#define TSB_PK_DATA_PK3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,3)))
#define TSB_PK_DATA_PK4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,4)))
#define TSB_PK_CR_PK0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,0)))
#define TSB_PK_CR_PK1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,1)))
#define TSB_PK_CR_PK2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,2)))
#define TSB_PK_CR_PK3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,3)))
#define TSB_PK_CR_PK4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,4)))
#define TSB_PK_FR1_PK0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,0)))
#define TSB_PK_FR1_PK1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,1)))
#define TSB_PK_FR1_PK2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,2)))
#define TSB_PK_FR1_PK3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,3)))
#define TSB_PK_FR1_PK4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,4)))
#define TSB_PK_FR2_PK1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR2,1)))
#define TSB_PK_FR2_PK2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR2,2)))
#define TSB_PK_FR2_PK3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR2,3)))
#define TSB_PK_FR2_PK4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR2,4)))
#define TSB_PK_FR3_PK1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR3,1)))
#define TSB_PK_FR3_PK2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR3,2)))
#define TSB_PK_FR3_PK3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR3,3)))
#define TSB_PK_FR3_PK4F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR3,4)))
#define TSB_PK_FR4_PK1F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR4,1)))
#define TSB_PK_OD_PK0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,0)))
#define TSB_PK_OD_PK1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,1)))
#define TSB_PK_OD_PK2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,2)))
#define TSB_PK_OD_PK3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,3)))
#define TSB_PK_OD_PK4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,4)))
#define TSB_PK_PUP_PK0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,0)))
#define TSB_PK_PUP_PK1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,1)))
#define TSB_PK_PUP_PK2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,2)))
#define TSB_PK_PUP_PK3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,3)))
#define TSB_PK_PUP_PK4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,4)))
#define TSB_PK_PDN_PK0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,0)))
#define TSB_PK_PDN_PK1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,1)))
#define TSB_PK_PDN_PK2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,2)))
#define TSB_PK_PDN_PK3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,3)))
#define TSB_PK_PDN_PK4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,4)))
#define TSB_PK_IE_PK0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,0)))
#define TSB_PK_IE_PK1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,1)))
#define TSB_PK_IE_PK2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,2)))
#define TSB_PK_IE_PK3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,3)))
#define TSB_PK_IE_PK4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,4)))


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
#define TSB_PL_FR3_PL0F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,0)))
#define TSB_PL_FR3_PL1F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,1)))
#define TSB_PL_FR3_PL2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,2)))
#define TSB_PL_FR3_PL3F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR3,3)))
#define TSB_PL_FR4_PL0F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR4,0)))
#define TSB_PL_FR4_PL1F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR4,1)))
#define TSB_PL_FR4_PL2F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR4,2)))
#define TSB_PL_FR4_PL3F4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR4,3)))
#define TSB_PL_FR5_PL1F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR5,1)))
#define TSB_PL_FR5_PL2F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR5,2)))
#define TSB_PL_FR5_PL3F5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR5,3)))
#define TSB_PL_FR6_PL3F6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR6,3)))
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
#define TSB_PL_PDN_PL0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,0)))
#define TSB_PL_PDN_PL1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,1)))
#define TSB_PL_PDN_PL2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,2)))
#define TSB_PL_PDN_PL3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,3)))
#define TSB_PL_PDN_PL4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,4)))
#define TSB_PL_PDN_PL5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,5)))
#define TSB_PL_PDN_PL6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,6)))
#define TSB_PL_PDN_PL7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,7)))
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
#define TSB_PM_CR_PM0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,0)))
#define TSB_PM_CR_PM1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,1)))
#define TSB_PM_CR_PM2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,2)))
#define TSB_PM_CR_PM3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->CR,3)))
#define TSB_PM_FR1_PM0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,0)))
#define TSB_PM_FR1_PM1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,1)))
#define TSB_PM_FR1_PM2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR1,2)))
#define TSB_PM_FR2_PM0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,0)))
#define TSB_PM_FR2_PM1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,1)))
#define TSB_PM_FR2_PM2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,2)))
#define TSB_PM_FR2_PM3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->FR2,3)))
#define TSB_PM_OD_PM0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,0)))
#define TSB_PM_OD_PM1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,1)))
#define TSB_PM_OD_PM2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,2)))
#define TSB_PM_OD_PM3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->OD,3)))
#define TSB_PM_PUP_PM0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,0)))
#define TSB_PM_PUP_PM1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,1)))
#define TSB_PM_PUP_PM2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,2)))
#define TSB_PM_PUP_PM3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PUP,3)))
#define TSB_PM_PDN_PI0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,0)))
#define TSB_PM_PDN_PI1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,1)))
#define TSB_PM_PDN_PI2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,2)))
#define TSB_PM_PDN_PI3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->PDN,3)))
#define TSB_PM_IE_PM0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,0)))
#define TSB_PM_IE_PM1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,1)))
#define TSB_PM_IE_PM2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,2)))
#define TSB_PM_IE_PM3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PM->IE,3)))


/* General Purpose Input/Output Port (PN) */
#define TSB_PN_DATA_PN0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,0)))
#define TSB_PN_DATA_PN1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,1)))
#define TSB_PN_DATA_PN2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,2)))
#define TSB_PN_DATA_PN3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,3)))
#define TSB_PN_DATA_PN4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,4)))
#define TSB_PN_DATA_PN5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,5)))
#define TSB_PN_CR_PN0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,0)))
#define TSB_PN_CR_PN1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,1)))
#define TSB_PN_CR_PN2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,2)))
#define TSB_PN_CR_PN3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,3)))
#define TSB_PN_CR_PN4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,4)))
#define TSB_PN_CR_PN5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,5)))
#define TSB_PN_FR1_PN0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,0)))
#define TSB_PN_FR1_PN1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,1)))
#define TSB_PN_FR1_PN2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,2)))
#define TSB_PN_FR1_PN3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,3)))
#define TSB_PN_FR1_PN4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,4)))
#define TSB_PN_FR1_PN5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,5)))
#define TSB_PN_FR2_PN4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,4)))
#define TSB_PN_FR2_PN5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,5)))
#define TSB_PN_OD_PN0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,0)))
#define TSB_PN_OD_PN1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,1)))
#define TSB_PN_OD_PN2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,2)))
#define TSB_PN_OD_PN3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,3)))
#define TSB_PN_OD_PN4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,4)))
#define TSB_PN_OD_PN5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,5)))
#define TSB_PN_PUP_PN0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,0)))
#define TSB_PN_PUP_PN1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,1)))
#define TSB_PN_PUP_PN2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,2)))
#define TSB_PN_PUP_PN3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,3)))
#define TSB_PN_PUP_PN4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,4)))
#define TSB_PN_PUP_PN5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,5)))
#define TSB_PN_PDN_PN0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,0)))
#define TSB_PN_PDN_PN1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,1)))
#define TSB_PN_PDN_PN2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,2)))
#define TSB_PN_PDN_PN3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,3)))
#define TSB_PN_PDN_PN4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,4)))
#define TSB_PN_PDN_PN5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,5)))
#define TSB_PN_IE_PN0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,0)))
#define TSB_PN_IE_PN1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,1)))
#define TSB_PN_IE_PN2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,2)))
#define TSB_PN_IE_PN3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,3)))
#define TSB_PN_IE_PN4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,4)))
#define TSB_PN_IE_PN5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,5)))


/* 16-bit Timer/Event Counter (TB) */
#define TSB_TB0_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,6)))
#define TSB_TB0_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,0)))
#define TSB_TB0_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,1)))
#define TSB_TB0_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,2)))
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
#define TSB_TB0_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->DMA,0)))
#define TSB_TB0_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->DMA,1)))
#define TSB_TB0_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->DMA,2)))

#define TSB_TB1_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,6)))
#define TSB_TB1_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,7)))
#define TSB_TB1_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,0)))
#define TSB_TB1_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,2)))
#define TSB_TB1_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,0)))
#define TSB_TB1_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,1)))
#define TSB_TB1_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,2)))
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
#define TSB_TB1_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->DMA,0)))
#define TSB_TB1_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->DMA,1)))
#define TSB_TB1_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->DMA,2)))

#define TSB_TB2_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,6)))
#define TSB_TB2_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,7)))
#define TSB_TB2_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,0)))
#define TSB_TB2_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,2)))
#define TSB_TB2_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,0)))
#define TSB_TB2_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,1)))
#define TSB_TB2_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,2)))
#define TSB_TB2_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,3)))
#define TSB_TB2_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,5)))
#define TSB_TB2_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,7)))
#define TSB_TB2_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,3)))
#define TSB_TB2_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,6)))
#define TSB_TB2_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,2)))
#define TSB_TB2_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,3)))
#define TSB_TB2_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,4)))
#define TSB_TB2_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,5)))
#define TSB_TB2_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,0)))
#define TSB_TB2_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,1)))
#define TSB_TB2_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,2)))
#define TSB_TB2_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->DMA,0)))
#define TSB_TB2_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->DMA,1)))
#define TSB_TB2_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->DMA,2)))

#define TSB_TB3_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,6)))
#define TSB_TB3_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,7)))
#define TSB_TB3_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,0)))
#define TSB_TB3_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,2)))
#define TSB_TB3_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,0)))
#define TSB_TB3_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,1)))
#define TSB_TB3_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,2)))
#define TSB_TB3_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,3)))
#define TSB_TB3_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,5)))
#define TSB_TB3_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,7)))
#define TSB_TB3_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,3)))
#define TSB_TB3_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,6)))
#define TSB_TB3_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,2)))
#define TSB_TB3_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,3)))
#define TSB_TB3_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,4)))
#define TSB_TB3_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,5)))
#define TSB_TB3_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,0)))
#define TSB_TB3_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,1)))
#define TSB_TB3_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,2)))
#define TSB_TB3_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->DMA,0)))
#define TSB_TB3_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->DMA,1)))
#define TSB_TB3_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->DMA,2)))

#define TSB_TB4_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,6)))
#define TSB_TB4_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,7)))
#define TSB_TB4_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,0)))
#define TSB_TB4_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,2)))
#define TSB_TB4_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,0)))
#define TSB_TB4_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,1)))
#define TSB_TB4_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,2)))
#define TSB_TB4_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,3)))
#define TSB_TB4_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,5)))
#define TSB_TB4_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,7)))
#define TSB_TB4_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,3)))
#define TSB_TB4_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,6)))
#define TSB_TB4_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,2)))
#define TSB_TB4_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,3)))
#define TSB_TB4_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,4)))
#define TSB_TB4_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,5)))
#define TSB_TB4_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,0)))
#define TSB_TB4_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,1)))
#define TSB_TB4_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,2)))
#define TSB_TB4_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->DMA,0)))
#define TSB_TB4_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->DMA,1)))
#define TSB_TB4_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->DMA,2)))

#define TSB_TB5_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,6)))
#define TSB_TB5_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,7)))
#define TSB_TB5_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,0)))
#define TSB_TB5_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,2)))
#define TSB_TB5_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,0)))
#define TSB_TB5_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,1)))
#define TSB_TB5_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,2)))
#define TSB_TB5_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,3)))
#define TSB_TB5_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,5)))
#define TSB_TB5_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,7)))
#define TSB_TB5_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,3)))
#define TSB_TB5_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,6)))
#define TSB_TB5_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,2)))
#define TSB_TB5_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,3)))
#define TSB_TB5_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,4)))
#define TSB_TB5_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,5)))
#define TSB_TB5_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,0)))
#define TSB_TB5_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,1)))
#define TSB_TB5_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,2)))
#define TSB_TB5_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->DMA,0)))
#define TSB_TB5_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->DMA,1)))
#define TSB_TB5_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->DMA,2)))

#define TSB_TB6_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,6)))
#define TSB_TB6_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,7)))
#define TSB_TB6_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,0)))
#define TSB_TB6_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,2)))
#define TSB_TB6_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,0)))
#define TSB_TB6_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,1)))
#define TSB_TB6_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,2)))
#define TSB_TB6_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,3)))
#define TSB_TB6_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,5)))
#define TSB_TB6_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,7)))
#define TSB_TB6_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,3)))
#define TSB_TB6_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,6)))
#define TSB_TB6_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,2)))
#define TSB_TB6_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,3)))
#define TSB_TB6_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,4)))
#define TSB_TB6_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,5)))
#define TSB_TB6_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,0)))
#define TSB_TB6_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,1)))
#define TSB_TB6_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,2)))
#define TSB_TB6_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->DMA,0)))
#define TSB_TB6_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->DMA,1)))
#define TSB_TB6_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->DMA,2)))

#define TSB_TB7_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,6)))
#define TSB_TB7_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,7)))
#define TSB_TB7_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,0)))
#define TSB_TB7_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,2)))
#define TSB_TB7_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,0)))
#define TSB_TB7_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,1)))
#define TSB_TB7_CR_TBINSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,2)))
#define TSB_TB7_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,3)))
#define TSB_TB7_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,5)))
#define TSB_TB7_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,7)))
#define TSB_TB7_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,3)))
#define TSB_TB7_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,6)))
#define TSB_TB7_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,2)))
#define TSB_TB7_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,3)))
#define TSB_TB7_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,4)))
#define TSB_TB7_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,5)))
#define TSB_TB7_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,0)))
#define TSB_TB7_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,1)))
#define TSB_TB7_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,2)))
#define TSB_TB7_DMA_TBDMAEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->DMA,0)))
#define TSB_TB7_DMA_TBDMAEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->DMA,1)))
#define TSB_TB7_DMA_TBDMAEN2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->DMA,2)))


/* 16-bit Multi-Purpose Timer (MPT-TMR/IGBT) */
#define TSB_MT0_EN_MTMODE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->EN,0)))
#define TSB_MT0_EN_MTHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->EN,6)))
#define TSB_MT0_EN_MTEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->EN,7)))
#define TSB_MT0_RUN_MTRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->RUN,0)))
#define TSB_MT0_RUN_MTPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->RUN,2)))
#define TSB_MT0_TBCR_MTTBCSSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBCR,0)))
#define TSB_MT0_TBCR_MTTBTRGSEL                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBCR,1)))
#define TSB_MT0_TBCR_MTI2TB                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBCR,3)))
#define TSB_MT0_TBCR_MTTBWBF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBCR,7)))
#define TSB_MT0_TBMOD_MTTBCLE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBMOD,2)))
#define TSB_MT0_TBMOD_MTTBCP                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT0->TBMOD,5)))
#define TSB_MT0_TBMOD_MTTBRSWR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBMOD,6)))
#define TSB_MT0_TBFFCR_MTTBE0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBFFCR,2)))
#define TSB_MT0_TBFFCR_MTTBE1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBFFCR,3)))
#define TSB_MT0_TBFFCR_MTTBC0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBFFCR,4)))
#define TSB_MT0_TBFFCR_MTTBC1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBFFCR,5)))
#define TSB_MT0_TBIM_MTTBIM0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBIM,0)))
#define TSB_MT0_TBIM_MTTBIM1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBIM,1)))
#define TSB_MT0_TBIM_MTTBIMOF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->TBIM,2)))
#define TSB_MT0_IGCR_IGSNGL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGCR,6)))
#define TSB_MT0_IGCR_IGIDIS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGCR,10)))
#define TSB_MT0_IGRESTA_IGRESTA                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT0->IGRESTA,0)))
#define TSB_MT0_IGST_IGST                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT0->IGST,0)))
#define TSB_MT0_IGICR_IGTRGSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGICR,6)))
#define TSB_MT0_IGICR_IGTRGM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGICR,7)))
#define TSB_MT0_IGOCR_IGOEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGOCR,0)))
#define TSB_MT0_IGOCR_IGOEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGOCR,1)))
#define TSB_MT0_IGOCR_IGPOL0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGOCR,4)))
#define TSB_MT0_IGOCR_IGPOL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGOCR,5)))
#define TSB_MT0_IGEMGCR_IGEMGEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGEMGCR,0)))
#define TSB_MT0_IGEMGCR_IGEMGOC                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT0->IGEMGCR,1)))
#define TSB_MT0_IGEMGCR_IGEMGRS                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT0->IGEMGCR,2)))
#define TSB_MT0_IGEMGST_IGEMGST                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT0->IGEMGST,0)))
#define TSB_MT0_IGEMGST_IGEMGIN                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT0->IGEMGST,1)))

#define TSB_MT1_EN_MTMODE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->EN,0)))
#define TSB_MT1_EN_MTHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->EN,6)))
#define TSB_MT1_EN_MTEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->EN,7)))
#define TSB_MT1_RUN_MTRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->RUN,0)))
#define TSB_MT1_RUN_MTPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->RUN,2)))
#define TSB_MT1_TBCR_MTTBCSSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBCR,0)))
#define TSB_MT1_TBCR_MTTBTRGSEL                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBCR,1)))
#define TSB_MT1_TBCR_MTI2TB                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBCR,3)))
#define TSB_MT1_TBCR_MTTBWBF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBCR,7)))
#define TSB_MT1_TBMOD_MTTBCLE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBMOD,2)))
#define TSB_MT1_TBMOD_MTTBCP                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT1->TBMOD,5)))
#define TSB_MT1_TBMOD_MTTBRSWR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBMOD,6)))
#define TSB_MT1_TBFFCR_MTTBE0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBFFCR,2)))
#define TSB_MT1_TBFFCR_MTTBE1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBFFCR,3)))
#define TSB_MT1_TBFFCR_MTTBC0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBFFCR,4)))
#define TSB_MT1_TBFFCR_MTTBC1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBFFCR,5)))
#define TSB_MT1_TBIM_MTTBIM0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBIM,0)))
#define TSB_MT1_TBIM_MTTBIM1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBIM,1)))
#define TSB_MT1_TBIM_MTTBIMOF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->TBIM,2)))
#define TSB_MT1_IGCR_IGSNGL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGCR,6)))
#define TSB_MT1_IGCR_IGIDIS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGCR,10)))
#define TSB_MT1_IGRESTA_IGRESTA                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT1->IGRESTA,0)))
#define TSB_MT1_IGST_IGST                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT1->IGST,0)))
#define TSB_MT1_IGICR_IGTRGSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGICR,6)))
#define TSB_MT1_IGICR_IGTRGM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGICR,7)))
#define TSB_MT1_IGOCR_IGOEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGOCR,0)))
#define TSB_MT1_IGOCR_IGOEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGOCR,1)))
#define TSB_MT1_IGOCR_IGPOL0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGOCR,4)))
#define TSB_MT1_IGOCR_IGPOL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGOCR,5)))
#define TSB_MT1_IGEMGCR_IGEMGEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGEMGCR,0)))
#define TSB_MT1_IGEMGCR_IGEMGOC                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT1->IGEMGCR,1)))
#define TSB_MT1_IGEMGCR_IGEMGRS                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT1->IGEMGCR,2)))
#define TSB_MT1_IGEMGST_IGEMGST                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT1->IGEMGST,0)))
#define TSB_MT1_IGEMGST_IGEMGIN                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT1->IGEMGST,1)))

#define TSB_MT2_EN_MTMODE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->EN,0)))
#define TSB_MT2_EN_MTHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->EN,6)))
#define TSB_MT2_EN_MTEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->EN,7)))
#define TSB_MT2_RUN_MTRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->RUN,0)))
#define TSB_MT2_RUN_MTPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->RUN,2)))
#define TSB_MT2_TBCR_MTTBCSSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBCR,0)))
#define TSB_MT2_TBCR_MTTBTRGSEL                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBCR,1)))
#define TSB_MT2_TBCR_MTI2TB                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBCR,3)))
#define TSB_MT2_TBCR_MTTBWBF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBCR,7)))
#define TSB_MT2_TBMOD_MTTBCLE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBMOD,2)))
#define TSB_MT2_TBMOD_MTTBCP                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT2->TBMOD,5)))
#define TSB_MT2_TBMOD_MTTBRSWR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBMOD,6)))
#define TSB_MT2_TBFFCR_MTTBE0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBFFCR,2)))
#define TSB_MT2_TBFFCR_MTTBE1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBFFCR,3)))
#define TSB_MT2_TBFFCR_MTTBC0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBFFCR,4)))
#define TSB_MT2_TBFFCR_MTTBC1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBFFCR,5)))
#define TSB_MT2_TBIM_MTTBIM0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBIM,0)))
#define TSB_MT2_TBIM_MTTBIM1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBIM,1)))
#define TSB_MT2_TBIM_MTTBIMOF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->TBIM,2)))
#define TSB_MT2_IGCR_IGSNGL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGCR,6)))
#define TSB_MT2_IGCR_IGIDIS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGCR,10)))
#define TSB_MT2_IGRESTA_IGRESTA                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT2->IGRESTA,0)))
#define TSB_MT2_IGST_IGST                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT2->IGST,0)))
#define TSB_MT2_IGICR_IGTRGSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGICR,6)))
#define TSB_MT2_IGICR_IGTRGM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGICR,7)))
#define TSB_MT2_IGOCR_IGOEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGOCR,0)))
#define TSB_MT2_IGOCR_IGOEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGOCR,1)))
#define TSB_MT2_IGOCR_IGPOL0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGOCR,4)))
#define TSB_MT2_IGOCR_IGPOL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGOCR,5)))
#define TSB_MT2_IGEMGCR_IGEMGEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGEMGCR,0)))
#define TSB_MT2_IGEMGCR_IGEMGOC                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT2->IGEMGCR,1)))
#define TSB_MT2_IGEMGCR_IGEMGRS                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT2->IGEMGCR,2)))
#define TSB_MT2_IGEMGST_IGEMGST                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT2->IGEMGST,0)))
#define TSB_MT2_IGEMGST_IGEMGIN                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT2->IGEMGST,1)))

#define TSB_MT3_EN_MTMODE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->EN,0)))
#define TSB_MT3_EN_MTHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->EN,6)))
#define TSB_MT3_EN_MTEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->EN,7)))
#define TSB_MT3_RUN_MTRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->RUN,0)))
#define TSB_MT3_RUN_MTPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->RUN,2)))
#define TSB_MT3_TBCR_MTTBCSSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBCR,0)))
#define TSB_MT3_TBCR_MTTBTRGSEL                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBCR,1)))
#define TSB_MT3_TBCR_MTI2TB                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBCR,3)))
#define TSB_MT3_TBCR_MTTBWBF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBCR,7)))
#define TSB_MT3_TBMOD_MTTBCLE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBMOD,2)))
#define TSB_MT3_TBMOD_MTTBCP                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT3->TBMOD,5)))
#define TSB_MT3_TBMOD_MTTBRSWR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBMOD,6)))
#define TSB_MT3_TBFFCR_MTTBE0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBFFCR,2)))
#define TSB_MT3_TBFFCR_MTTBE1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBFFCR,3)))
#define TSB_MT3_TBFFCR_MTTBC0T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBFFCR,4)))
#define TSB_MT3_TBFFCR_MTTBC1T1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBFFCR,5)))
#define TSB_MT3_TBIM_MTTBIM0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBIM,0)))
#define TSB_MT3_TBIM_MTTBIM1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBIM,1)))
#define TSB_MT3_TBIM_MTTBIMOF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->TBIM,2)))
#define TSB_MT3_IGCR_IGSNGL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGCR,6)))
#define TSB_MT3_IGCR_IGIDIS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGCR,10)))
#define TSB_MT3_IGRESTA_IGRESTA                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT3->IGRESTA,0)))
#define TSB_MT3_IGST_IGST                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT3->IGST,0)))
#define TSB_MT3_IGICR_IGTRGSEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGICR,6)))
#define TSB_MT3_IGICR_IGTRGM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGICR,7)))
#define TSB_MT3_IGOCR_IGOEN0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGOCR,0)))
#define TSB_MT3_IGOCR_IGOEN1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGOCR,1)))
#define TSB_MT3_IGOCR_IGPOL0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGOCR,4)))
#define TSB_MT3_IGOCR_IGPOL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGOCR,5)))
#define TSB_MT3_IGEMGCR_IGEMGEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGEMGCR,0)))
#define TSB_MT3_IGEMGCR_IGEMGOC                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MT3->IGEMGCR,1)))
#define TSB_MT3_IGEMGCR_IGEMGRS                   (*((__O  uint32_t *)BITBAND_PERI(&TSB_MT3->IGEMGCR,2)))
#define TSB_MT3_IGEMGST_IGEMGST                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT3->IGEMGST,0)))
#define TSB_MT3_IGEMGST_IGEMGIN                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_MT3->IGEMGST,1)))


/* Real Time Clock (RTC) */
#define TSB_RTC_MONTHR_MO0                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RTC->MONTHR,0)))


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


/* Remote Control Signal Preprocessor (RMC) */
#define TSB_RMC_EN_RMCEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->EN,0)))
#define TSB_RMC_REN_RMCREN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->REN,0)))
#define TSB_RMC_RCR2_RMCPHM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->RCR2,24)))
#define TSB_RMC_RCR2_RMCLD                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->RCR2,25)))
#define TSB_RMC_RCR2_RMCEDIEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->RCR2,30)))
#define TSB_RMC_RCR2_RMCLIEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->RCR2,31)))
#define TSB_RMC_RCR4_RMCPO                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->RCR4,7)))
#define TSB_RMC_RSTAT_RMCRLDR                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC->RSTAT,7)))
#define TSB_RMC_RSTAT_RMCEDIF                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC->RSTAT,12)))
#define TSB_RMC_RSTAT_RMCDMAXIF                   (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC->RSTAT,13)))
#define TSB_RMC_RSTAT_RMCLOIF                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC->RSTAT,14)))
#define TSB_RMC_RSTAT_RMCRLIF                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_RMC->RSTAT,15)))
#define TSB_RMC_FSSEL_RMCCLK                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_RMC->FSSEL,0)))


/* Oscillation Frequency Detector (OFD) */
#define TSB_OFD_RST_OFDRSTEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_OFD->RST,0)))
#define TSB_OFD_STAT_FRQERR                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_OFD->STAT,0)))
#define TSB_OFD_STAT_OFDBUSY                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_OFD->STAT,1)))
#define TSB_OFD_MON_OFDMON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_OFD->MON,0)))


/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_I2WDT                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,2)))
#define TSB_WD_MOD_WDTE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))


/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FPSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,12)))
#define TSB_CG_SYSCR_FCSTOP                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,20)))
#define TSB_CG_OSCCR_WUEON                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_PLLON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,2)))
#define TSB_CG_OSCCR_WUPSEL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XTEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,9)))
#define TSB_CG_OSCCR_XEN3                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,10)))
#define TSB_CG_OSCCR_DRVOSCH                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,12)))
#define TSB_CG_OSCCR_DRVOSCL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,13)))
#define TSB_CG_OSCCR_XEN2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,16)))
#define TSB_CG_OSCCR_OSCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,17)))
#define TSB_CG_OSCCR_EHOSCSEL                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,18)))
#define TSB_CG_OSCCR_WUPSEL2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,19)))
#define TSB_CG_STBYCR_DRVE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,16)))
#define TSB_CG_STBYCR_PTKEEP                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,17)))
#define TSB_CG_PLLSEL_PLLSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,0)))
#define TSB_CG_PCKSTP_USBDSTP                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PCKSTP,0)))
#define TSB_CG_PCKSTP_USBHSTP                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PCKSTP,1)))
#define TSB_CG_PCKSTP_CANSTP                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PCKSTP,2)))
#define TSB_CG_PCKSTP_EMSTP                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PCKSTP,3)))
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
#define TSB_CG_IMCGD_INTUSBWKUPEN                 (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,0)))
#define TSB_CG_IMCGD_INTDEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,8)))
#define TSB_CG_IMCGD_INTRTCEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,16)))
#define TSB_CG_IMCGD_INTRMCRXEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,24)))


/* Low Voltage detector control register */
#define TSB_USBPLL_CR_USBPLLON                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_USBPLL->CR,0)))
#define TSB_USBPLL_EN_USBDEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_USBPLL->EN,0)))
#define TSB_USBPLL_EN_USBHEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_USBPLL->EN,1)))
#define TSB_USBPLL_SEL_USBPLLSEL                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_USBPLL->SEL,0)))


/* Low Voltage detector control register */
#define TSB_TRMOSC_EN_TRIMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TRMOSC->EN,0)))


/* Low Voltage detector control register */
#define TSB_LVD_RCR_LVDEN1                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->RCR,0)))
#define TSB_LVD_RCR_LVDRSTEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->RCR,5)))
#define TSB_LVD_ICR_LVDEN2                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,0)))
#define TSB_LVD_ICR_INTSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,4)))
#define TSB_LVD_ICR_LVDINTEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->ICR,5)))
#define TSB_LVD_SR_LVDST1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->SR,0)))
#define TSB_LVD_SR_LVDST2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_LVD->SR,1)))


/* 16-bit Multi-Purpose Timer (MPT-PMD) */
#define TSB_MTPD0_MDEN_PWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDEN,0)))
#define TSB_MTPD0_PORTMD_PORTMD                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->PORTMD,0)))
#define TSB_MTPD0_MDCR_PWMMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDCR,0)))
#define TSB_MTPD0_MDCR_PINT                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDCR,3)))
#define TSB_MTPD0_MDCR_DTYMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDCR,4)))
#define TSB_MTPD0_MDCR_SYNTMD                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDCR,5)))
#define TSB_MTPD0_MDCR_PWMCK                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDCR,6)))
#define TSB_MTPD0_CNTSTA_UPDWN                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD0->CNTSTA,0)))
#define TSB_MTPD0_MDOUT_UPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDOUT,8)))
#define TSB_MTPD0_MDOUT_VPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDOUT,9)))
#define TSB_MTPD0_MDOUT_WPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDOUT,10)))
#define TSB_MTPD0_MDPOT_POLL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDPOT,2)))
#define TSB_MTPD0_MDPOT_POLH                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->MDPOT,3)))
#define TSB_MTPD0_EMGCR_EMGEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->EMGCR,0)))
#define TSB_MTPD0_EMGCR_EMGRS                     (*((__O  uint32_t *)BITBAND_PERI(&TSB_MTPD0->EMGCR,1)))
#define TSB_MTPD0_EMGCR_INHEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD0->EMGCR,5)))
#define TSB_MTPD0_EMGSTA_EMGST                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD0->EMGSTA,0)))
#define TSB_MTPD0_EMGSTA_EMGI                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD0->EMGSTA,1)))

#define TSB_MTPD1_MDEN_PWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDEN,0)))
#define TSB_MTPD1_PORTMD_PORTMD                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->PORTMD,0)))
#define TSB_MTPD1_MDCR_PWMMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDCR,0)))
#define TSB_MTPD1_MDCR_PINT                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDCR,3)))
#define TSB_MTPD1_MDCR_DTYMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDCR,4)))
#define TSB_MTPD1_MDCR_SYNTMD                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDCR,5)))
#define TSB_MTPD1_MDCR_PWMCK                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDCR,6)))
#define TSB_MTPD1_CNTSTA_UPDWN                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD1->CNTSTA,0)))
#define TSB_MTPD1_MDOUT_UPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDOUT,8)))
#define TSB_MTPD1_MDOUT_VPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDOUT,9)))
#define TSB_MTPD1_MDOUT_WPWM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDOUT,10)))
#define TSB_MTPD1_MDPOT_POLL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDPOT,2)))
#define TSB_MTPD1_MDPOT_POLH                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->MDPOT,3)))
#define TSB_MTPD1_EMGCR_EMGEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->EMGCR,0)))
#define TSB_MTPD1_EMGCR_EMGRS                     (*((__O  uint32_t *)BITBAND_PERI(&TSB_MTPD1->EMGCR,1)))
#define TSB_MTPD1_EMGCR_INHEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_MTPD1->EMGCR,5)))
#define TSB_MTPD1_EMGSTA_EMGST                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD1->EMGSTA,0)))
#define TSB_MTPD1_EMGSTA_EMGI                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_MTPD1->EMGSTA,1)))




/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM369_H__ */

/** @} */ /* End of group TMPM369 */
/** @} */ /* End of group TOSHIBA_TX03_MICROCONTROLLER */
