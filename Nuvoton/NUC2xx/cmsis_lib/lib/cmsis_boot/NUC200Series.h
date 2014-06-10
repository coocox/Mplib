    /*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#ifndef __NUC200Series_H__
#define __NUC200Series_H__

              
/*
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
  GPCDEF_IRQn               = 5,        /*!< GPIO_PC/PD/PE/PF Interrupt                           */
  PWMA_IRQn                 = 6,        /*!< PWMA Interrupt                                       */
  PWMB_IRQn                 = 7,        /*!< PWMB Interrupt                                       */
  TMR0_IRQn                 = 8,        /*!< TIMER0 Interrupt                                     */
  TMR1_IRQn                 = 9,        /*!< TIMER1 Interrupt                                     */
  TMR2_IRQn                 = 10,       /*!< TIMER2 Interrupt                                     */
  TMR3_IRQn                 = 11,       /*!< TIMER3 Interrupt                                     */
  UART02_IRQn               = 12,      /*!< UART0/UART2 Interrupt                                */
  UART1_IRQn                = 13,       /*!< UART1 Interrupt                                      */
  SPI0_IRQn                 = 14,       /*!< SPI0 Interrupt                                       */
  SPI1_IRQn                 = 15,       /*!< SPI1 Interrupt                                       */
  SPI2_IRQn                 = 16,       /*!< SPI2 Interrupt                                       */
  SPI3_IRQn                 = 17,       /*!< SPI3 Interrupt                                       */
  I2C0_IRQn                 = 18,       /*!< I2C0 Interrupt                                       */
  I2C1_IRQn                 = 19,       /*!< I2C1 Interrupt                                       */
  CAN0_IRQn                 = 20,       /*!< CAN0 Interrupt                                       */
  CAN1_IRQn                 = 21,       /*!< CAN1 Interrupt                                       */
  SC012_IRQn                = 22,       /*!< SC0/SC1/SC2 Interrupt                                */
  USBD_IRQn                 = 23,       /*!< USB device Interrupt                                 */
  PS2_IRQn                  = 24,       /*!< PS/2 device Interrupt                                */
  ACMP_IRQn                 = 25,       /*!< ACMP0 Interrupt                                      */
  PDMA_IRQn                 = 26,       /*!< PDMA Interrupt                                       */
  I2S_IRQn                  = 27,       /*!< I2S Interrupt                                        */
  PWRWU_IRQn                = 28,       /*!< Power Down Wake Up Interrupt                         */
  ADC_IRQn                  = 29,       /*!< ADC Interrupt                                        */
  IRC_IRQn                  = 30,       /*!< IRC TRIM Interrupt                                   */
  RTC_IRQn                  = 31        /*!< RTC Interrupt                                        */
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT           0       /*!< armikcmu does not provide a MPU present or not       */
#define __NVIC_PRIO_BITS        2       /*!< armikcmu Supports 2 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used         */


#include "core_cm0.h"                   /* Cortex-M0 processor and core peripherals               */
#include "system_NUC200Series.h"              /* NUC200 System                                          */

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


/*-------------------------------- Device Specific Peripheral registers structures ---------------------*/
/** @addtogroup NUC200 NUC200 Peripheral Register
  NUC200 Series Peripheral Control Registers
  @{
 */


/*--------------------- General Purpose I/O (GPIO) ---------------------*/
/** @addtogroup NUC200_GPIO NUC200 GPIO
  Memory Mapped Structure for NUC200 Series General Purpose I/O
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
#define GPIO_ISRC_ISRC_Pos          0                                           /*!< GPIO ISRC: ISRC Position */
#define GPIO_ISRC_ISRC_Msk          (0xFFFFul << GPIO_ISRC_ISRC_Pos)            /*!< GPIO ISRC: ISRC Mask */

/* GPIO DBNCECON Bit Field Definitions */
#define GPIO_DBNCECON_ICLK_ON_Pos   5                                           /*!< GPIO DBNCECON: ICLK_ON  Position */
#define GPIO_DBNCECON_ICLK_ON_Msk   (1ul << GPIO_DBNCECON_ICLK_ON_Pos)          /*!< GPIO DBNCECON: ICLK_ON  Mask */

#define GPIO_DBNCECON_DBCLKSRC_Pos  4                                           /*!< GPIO DBNCECON: DBCLKSRC Position */
#define GPIO_DBNCECON_DBCLKSRC_Msk  (1ul << GPIO_DBNCECON_DBCLKSRC_Pos)         /*!< GPIO DBNCECON: DBCLKSRC Mask */

#define GPIO_DBNCECON_DBCLKSEL_Pos  0                                           /*!< GPIO DBNCECON: DBCLKSEL Position */
#define GPIO_DBNCECON_DBCLKSEL_Msk  (0xFul << GPIO_DBNCECON_DBCLKSEL_Pos)       /*!< GPIO DBNCECON: DBCLKSEL Mask */
/*@}*/ /* end of group NUC200_GPIO */



/*------------------------- UART Interface Controller ------------------------*/

/** @addtogroup NUC200_UART NUC200 UART
  Memory Mapped Structure for NUC200 Series UART Serial Interface Controller
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
    __IO uint32_t LIN_CTL; 
    __IO uint32_t LIN_SR; 
} UART_T;




/* UART THR Bit Field Definitions */
#define UART_THR_THR_Pos         0                                          /*!< UART THR: THR Position  */
#define UART_THR_THR_Msk        (0xFul << UART_THR_THR_Pos)                 /*!< UART THR: THR Mask      */

/* UART RBR Bit Field Definitions */
#define UART_RBR_RBR_Pos         0                                          /*!< UART RBR: RBR Posistion */
#define UART_RBR_RBR_Msk        (0xFul << UART_RBR_RBR_Pos)                 /*!< UART RBR: RBR Mask      */

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

#define UART_IER_LIN_RX_BRK_IEN_Pos 8                                       /*!< UART IER: LIN_RX_BRK_IEN Posistion   */
#define UART_IER_LIN_RX_BRK_IEN_Msk (1ul << UART_IER_LIN_RX_BRK_IEN_Pos)    /*!< UART IER: LIN_RX_BRK_IEN Mask        */

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

/*@}*/ /* end of group NUC200_UART */


/*----------------------------- Timer Controller (TMR) -----------------------------*/
/** @addtogroup NUC200_TIMER NUC200 TIMER
  Memory Mapped Structure for NUC200 Series Timer Controller
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
/*@}*/ /* end of group NUC200_TIMER */


/*----------------------------- Watchdog Timer (WDT) -----------------------------*/
/** @addtogroup NUC200_WDT NUC200 WDT
  Memory Mapped Structure for NUC200 Series Watchdog Timer
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
/*@}*/ /* end of group NUC200_WDT */


/*----------------------------- Window Watchdog Timer (WWDT) -----------------------------*/
/** @addtogroup NUC200_WWDT NUC200 WWDT
  Memory Mapped Structure for NUC200 Series Window Watchdog Timer
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
/*@}*/ /* end of group NUC200_WWDT */


/*------------------------- SPI Interface Controller -------------------------*/
/** @addtogroup NUC200_SPI NUC200 SPI
  Memory Mapped Structure for NUC200 Series SPI Controller
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

/*@}*/ /* end of group NUC200_SPI */



/*------------------------------ I2C Controller ------------------------------*/
/** @addtogroup NUC200_I2C NUC200 I2C
  Memory Mapped Structure for NUC200 Series I2C Serial Interface Controller
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

/*@}*/ /* end of group NUC200_I2C */


/*-----------------------  Real Time Clock (RTC) ------------------*/
/** @addtogroup NUC200_RTC NUC200 RTC
  Memory Mapped Structure for NUC200 Series Real Time Clock
  @{
 */
typedef struct
{
    /**
     * INIR
     * ===================================================================================================
     * Offset: 0x00  RTC Initiation Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t INIR;

    /**
     * AER
     * ===================================================================================================
     * Offset: 0x04  RTC Access Enable Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t AER;

    /**
     * FCR
     * ===================================================================================================
     * Offset: 0x08  RTC Frequency Compensation Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t FCR;

    /**
     * TLR
     * ===================================================================================================
     * Offset: 0x0C  RTC Time Loading Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TLR;

    /**
     * CLR
     * ===================================================================================================
     * Offset: 0x10  RTC Calendar Loading Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t CLR;

    /**
     * TSSR
     * ===================================================================================================
     * Offset: 0x14  RTC Time Scale Selection Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TSSR;

    /**
     * DWR
     * ===================================================================================================
     * Offset: 0x18  RTC Day of the Week Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t DWR;

    /**
     * TAR
     * ===================================================================================================
     * Offset: 0x1C  RTC Time Alarm Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TAR;

    /**
     * CAR
     * ===================================================================================================
     * Offset: 0x20  RTC Calendar Alarm Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t CAR;

    /**
     * LIR
     * ===================================================================================================
     * Offset: 0x24  RTC Leap Year Indication Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __I  uint32_t LIR;

    /**
     * RIER
     * ===================================================================================================
     * Offset: 0x28  RTC Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t RIER;

    /**
     * RIIR
     * ===================================================================================================
     * Offset: 0x2C  RTC Interrupt Indication Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t RIIR;

    /**
     * TTR
     * ===================================================================================================
     * Offset: 0x30  RTC Time Tick Register
     * ---------------------------------------------------------------------------------------------------
     */    
    __IO uint32_t TTR;
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
/*@}*/ /* end of group NUC200_RTC */



/*----------------------------- ADC Controller -------------------------------*/
/** @addtogroup NUC200_ADC NUC200 ADC
  Memory Mapped Structure for NUC200 Series ADC Controller
  @{
 */
typedef struct
{
    __I  uint32_t ADDR[8];               /*!< Offset: 0x00  A/D Data Register              */
    __IO uint32_t ADCR;                  /*!< Offset: 0x20  A/D Control Register           */
    __IO uint32_t ADCHER;                /*!< Offset: 0x24  A/D Channel Enable Register    */
    __IO uint32_t ADCMPR[2];             /*!< Offset: 0x28  A/D Compare Register 0 & 1     */
    __IO uint32_t ADSR;                  /*!< Offset: 0x30  ADC Status Register            */
    __I  uint32_t RESERVE0[3];
    __I  uint32_t ADPDMA;                /*!< Offset: 0x40  ADC PDMA Current Transfer Data */
} ADC_T;


/* ADDR Bit Field Definitions */
#define ADC_ADDR_VALID_Pos      17                                /*!< ADC ADDR: VALID Position */
#define ADC_ADDR_VALID_Msk      (1ul << ADC_ADDR_VALID_Pos)       /*!< ADC ADDR: VALID Mask */

#define ADC_ADDR_OVERRUN_Pos    16                                /*!< ADC ADDR: OVERRUN Position */
#define ADC_ADDR_OVERRUN_Msk    (1ul << ADC_ADDR_OVERRUN_Pos)     /*!< ADC ADDR: OVERRUN Mask */

#define ADC_ADDR_RSLT_Pos       0                                 /*!< ADC ADDR: RSLT Position */
#define ADC_ADDR_RSLT_Msk       (0xFFFFul << ADC_ADDR_RSLT_Pos)   /*!< ADC ADDR: RSLT Mask */

/* ADCR Bit Field Definitions */
#define ADC_ADCR_DMOF_Pos       31                                /*!< ADC ADCR: DMOF Position */
#define ADC_ADCR_DMOF_Msk       (1ul << ADC_ADCR_DMOF_Pos)        /*!< ADC ADCR: DMOF Mask */

#define ADC_ADCR_ADST_Pos       11                                /*!< ADC ADCR: ADST Position */
#define ADC_ADCR_ADST_Msk       (1ul << ADC_ADCR_ADST_Pos)        /*!< ADC ADCR: ADST Mask */

#define ADC_ADCR_DIFFEN_Pos     10                                /*!< ADC ADCR: DIFFEN Position */
#define ADC_ADCR_DIFFEN_Msk     (1ul << ADC_ADCR_DIFFEN_Pos)      /*!< ADC ADCR: DIFFEN Mask */

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
#define ADC_ADCHER_PRESEL_Pos   8                                 /*!< ADC ADCHER: PRESEL Position */
#define ADC_ADCHER_PRESEL_Msk   (3ul << ADC_ADCHER_PRESEL_Pos)    /*!< ADC ADCHER: PRESEL Mask */

#define ADC_ADCHER_CHEN_Pos     0                                 /*!< ADC ADCHER: CHEN Position */
#define ADC_ADCHER_CHEN_Msk     (0xFFul << ADC_ADCHER_CHEN_Pos)   /*!< ADC ADCHER: CHEN Mask */

/* ADCMPR Bit Field Definitions */
#define ADC_ADCMPR_CMPD_Pos        16                                    /*!< ADC ADCMPR: CMPD Position */
#define ADC_ADCMPR_CMPD_Msk        (0xFFFul << ADC_ADCMPR_CMPD_Pos)      /*!< ADC ADCMPR: CMPD Mask */

#define ADC_ADCMPR_CMPMATCNT_Pos   8                                     /*!< ADC ADCMPR: CMPMATCNT Position */
#define ADC_ADCMPR_CMPMATCNT_Msk   (0xFul << ADC_ADCMPR_CMPMATCNT_Pos)   /*!< ADC ADCMPR: CMPMATCNT Mask */

#define ADC_ADCMPR_CMPCH_Pos       3                                     /*!< ADC ADCMPR: CMPCH Position */
#define ADC_ADCMPR_CMPCH_Msk       (7ul << ADC_ADCMPR_CMPCH_Pos)         /*!< ADC ADCMPR: CMPCH Mask */

#define ADC_ADCMPR_CMPCOND_Pos     2                                     /*!< ADC ADCMPR: CMPCOND Position */
#define ADC_ADCMPR_CMPCOND_Msk     (1ul << ADC_ADCMPR_CMPCOND_Pos)       /*!< ADC ADCMPR: CMPCOND Mask */

#define ADC_ADCMPR_CMPIE_Pos       1                                     /*!< ADC ADCMPR: CMPIE Position */
#define ADC_ADCMPR_CMPIE_Msk       (1ul << ADC_ADCMPR_CMPIE_Pos)         /*!< ADC ADCMPR: CMPIE Mask */

#define ADC_ADCMPR_CMPEN_Pos       0                                     /*!< ADC ADCMPR: CMPEN Position */
#define ADC_ADCMPR_CMPEN_Msk       (1ul << ADC_ADCMPR_CMPEN_Pos)         /*!< ADC ADCMPR: CMPEN Mask */

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
#define ADC_ADPDMA_AD_PDMA_Pos     0                                     /*!< ADC ADPDMA: AD_PDMA Position */
#define ADC_ADPDMA_AD_PDMA_Msk     (0x3FFFFul << ADC_ADPDMA_AD_PDMA_Pos) /*!< ADC ADPDMA: AD_PDMA Mask */

/*@}*/ /* end of group NUC200_ADC */


/*---------------------- Analog Comparator Controller -------------------------*/
/** @addtogroup NUC200_ACMP NUC200 ACMP
  Memory Mapped Structure for NUC200 Series ACMP Controller
  @{
 */
typedef struct
{
        __IO uint32_t CMPCR[2];        /*!< Offset: 0x00  ACMP Comparator Control Register   */
        __IO uint32_t CMPSR;           /*!< Offset: 0x08  ACMP Comparator Status Register   */

} ACMP_T;


/* CMPCR Bit Field Definitions */
#define ACMP_CMPCR_CMPCN_Pos       4                                   /*!< ACMP CMPCR: CMPCN Position */
#define ACMP_CMPCR_CMPCN_Msk       (1ul << ACMP_CMPCR_CMPCN_Pos)       /*!< ACMP CMPCR: CMPCN Mask */

#define ACMP_CMPCR_CMP_HYSEN_Pos   2                                   /*!< ACMP CMPCR: CMP_HYSEN Position */
#define ACMP_CMPCR_CMP_HYSEN_Msk   (1ul << ACMP_CMPCR_CMP_HYSEN_Pos)   /*!< ACMP CMPCR: CMP_HYSEN Mask */

#define ACMP_CMPCR_CMPIE_Pos       1                                   /*!< ACMP CMPCR: CMPIE Position */
#define ACMP_CMPCR_CMPIE_Msk       (1ul << ACMP_CMPCR_CMPIE_Pos)       /*!< ACMP CMPCR: CMPIE Mask */

#define ACMP_CMPCR_CMPEN_Pos       0                                   /*!< ACMP CMPCR: CMPEN Position */
#define ACMP_CMPCR_CMPEN_Msk       (1ul << ACMP_CMPCR_CMPEN_Pos)       /*!< ACMP CMPCR: CMPEN Mask */

/* CMPSR Bit Field Definitions */
#define ACMP_CMPSR_CO1_Pos     3                                 /*!< ACMP CMPSR: CO1 Position */
#define ACMP_CMPSR_CO1_Msk     (1ul << ACMP_CMPSR_CO1_Pos)       /*!< ACMP CMPSR: CO1 Mask */

#define ACMP_CMPSR_CO0_Pos     2                                 /*!< ACMP CMPSR: CO0 Position */
#define ACMP_CMPSR_CO0_Msk     (1ul << ACMP_CMPSR_CO0_Pos)       /*!< ACMP CMPSR: CO0 Mask */

#define ACMP_CMPSR_CMPF1_Pos   1                                 /*!< ACMP CMPSR: CMPF1 Position */
#define ACMP_CMPSR_CMPF1_Msk   (1ul << ACMP_CMPSR_CMPF1_Pos)     /*!< ACMP CMPSR: CMPF1 Mask */

#define ACMP_CMPSR_CMPF0_Pos   0                                 /*!< ACMP CMPSR: CMPF0 Position */
#define ACMP_CMPSR_CMPF0_Msk   (1ul << ACMP_CMPSR_CMPF0_Pos)     /*!< ACMP CMPSR: CMPF0 Mask */

/*@}*/ /* end of group NUC200_ACMP */



/*---------------------------- Clock Controller ------------------------------*/
/** @addtogroup NUC200_SYSCLK NUC200 System Clock Controller
  Memory Mapped Structure for NUC200 Series System Clock Controller
  @{
 */
typedef struct
{
    __IO uint32_t PWRCON;           
    __IO uint32_t AHBCLK;           
    __IO uint32_t APBCLK;           
    __IO uint32_t CLKSTATUS;        
    __IO uint32_t CLKSEL0;          
    __IO uint32_t CLKSEL1;          
    __IO uint32_t CLKDIV;           
    __IO uint32_t CLKSEL2;           
    __IO uint32_t PLLCON;           
    __IO uint32_t FRQDIV;           
    __IO uint32_t RESERVE[2];           
    __IO uint32_t APBCLK1;             
    __IO uint32_t CLKSEL3;          
    __IO uint32_t CLKDIV1;                        
} SYSCLK_T;

/* SYSCLK PWRCON Bit Field Definitions */
#define SYSCLK_PWRCON_PD_WAIT_CPU_Pos           8                                       /*!< SYSCLK PWRCON: PD_WAIT_CPU Position */
#define SYSCLK_PWRCON_PD_WAIT_CPU_Msk           (1ul << SYSCLK_PWRCON_PD_WAIT_CPU_Pos)  /*!< SYSCLK PWRCON: PD_WAIT_CPU Mask */

#define SYSCLK_PWRCON_PWR_DOWN_EN_Pos           7                                       /*!< SYSCLK PWRCON: PWR_DOWN_EN Position */
#define SYSCLK_PWRCON_PWR_DOWN_EN_Msk           (1ul << SYSCLK_PWRCON_PWR_DOWN_EN_Pos)  /*!< SYSCLK PWRCON: PWR_DOWN_EN Mask */

#define SYSCLK_PWRCON_PD_WU_STS_Pos             6                                       /*!< SYSCLK PWRCON: PD_WU_STS Position */
#define SYSCLK_PWRCON_PD_WU_STS_Msk             (1ul << SYSCLK_PWRCON_PD_WU_STS_Pos)    /*!< SYSCLK PWRCON: PD_WU_STS Mask */

#define SYSCLK_PWRCON_PD_WU_INT_EN_Pos          5                                       /*!< SYSCLK PWRCON: PD_WU_INT_EN Position */
#define SYSCLK_PWRCON_PD_WU_INT_EN_Msk          (1ul << SYSCLK_PWRCON_PD_WU_INT_EN_Pos) /*!< SYSCLK PWRCON: PD_WU_INT_EN Mask */

#define SYSCLK_PWRCON_PD_WU_DLY_Pos             4                                       /*!< SYSCLK PWRCON: PD_WU_DLY Position */
#define SYSCLK_PWRCON_PD_WU_DLY_Msk             (1ul << SYSCLK_PWRCON_PD_WU_DLY_Pos)    /*!< SYSCLK PWRCON: PD_WU_DLY Mask */

#define SYSCLK_PWRCON_IRC10K_EN_Pos             3                                       /*!< SYSCLK PWRCON: IRC10K_EN Position */
#define SYSCLK_PWRCON_IRC10K_EN_Msk             (1ul << SYSCLK_PWRCON_IRC10K_EN_Pos)    /*!< SYSCLK PWRCON: IRC10K_EN Mask */

#define SYSCLK_PWRCON_IRC22M_EN_Pos             2                                       /*!< SYSCLK PWRCON: IRC22M_EN Position */
#define SYSCLK_PWRCON_IRC22M_EN_Msk             (1ul << SYSCLK_PWRCON_IRC22M_EN_Pos)    /*!< SYSCLK PWRCON: IRC22M_EN Mask */

#define SYSCLK_PWRCON_XTL32K_EN_Pos             1                                       /*!< SYSCLK PWRCON: XTL32K_EN Position */
#define SYSCLK_PWRCON_XTL32K_EN_Msk             (1ul << SYSCLK_PWRCON_XTL32K_EN_Pos)    /*!< SYSCLK PWRCON: XTL32K_EN Mask */

#define SYSCLK_PWRCON_XTL12M_EN_Pos             0                                       /*!< SYSCLK PWRCON: XTL12M_EN Position */
#define SYSCLK_PWRCON_XTL12M_EN_Msk             (1ul << SYSCLK_PWRCON_XTL12M_EN_Pos)    /*!< SYSCLK PWRCON: XTL12M_EN Mask */

/* SYSCLK AHBCLK Bit Field Definitions */
#define SYSCLK_AHBCLK_ISP_EN_Pos                2                                       /*!< SYSCLK AHBCLK: ISP_EN Position */
#define SYSCLK_AHBCLK_ISP_EN_Msk                (1ul << SYSCLK_AHBCLK_ISP_EN_Pos)       /*!< SYSCLK AHBCLK: ISP_EN Mask */

#define SYSCLK_AHBCLK_PDMA_EN_Pos               1                                       /*!< SYSCLK AHBCLK: PDMA_EN Position */
#define SYSCLK_AHBCLK_PDMA_EN_Msk               (1ul << SYSCLK_AHBCLK_PDMA_EN_Pos)      /*!< SYSCLK AHBCLK: PDMA_EN Mask */


/* SYSCLK APBCLK Bit Field Definitions */
#define SYSCLK_APBCLK_PS2_EN_Pos                31                                      /*!< SYSCLK APBCLK: PS2_EN Position */
#define SYSCLK_APBCLK_PS2_EN_Msk                (1ul << SYSCLK_APBCLK_PS2_EN_Pos)       /*!< SYSCLK APBCLK: PS2_EN Mask */

#define SYSCLK_APBCLK_ACMP_EN_Pos               30                                      /*!< SYSCLK APBCLK: ACMP_EN Position */
#define SYSCLK_APBCLK_ACMP_EN_Msk               (1ul << SYSCLK_APBCLK_ACMP_EN_Pos)      /*!< SYSCLK APBCLK: ACMP_EN Mask */

#define SYSCLK_APBCLK_I2S_EN_Pos                29                                      /*!< SYSCLK APBCLK: I2S_EN Position */
#define SYSCLK_APBCLK_I2S_EN_Msk                (1ul << SYSCLK_APBCLK_I2S_EN_Pos)       /*!< SYSCLK APBCLK: I2S_EN Mask */

#define SYSCLK_APBCLK_ADC_EN_Pos                28                                      /*!< SYSCLK APBCLK: ADC_EN Position */
#define SYSCLK_APBCLK_ADC_EN_Msk                (1ul << SYSCLK_APBCLK_ADC_EN_Pos)       /*!< SYSCLK APBCLK: ADC_EN Mask */

#define SYSCLK_APBCLK_USBD_EN_Pos               27                                      /*!< SYSCLK APBCLK: USBD_EN Position */
#define SYSCLK_APBCLK_USBD_EN_Msk               (1ul << SYSCLK_APBCLK_USBD_EN_Pos)      /*!< SYSCLK APBCLK: USBD_EN Mask */

#define SYSCLK_APBCLK_CAN1_EN_Pos               25                                      /*!< SYSCLK APBCLK: CAN1_EN Position */
#define SYSCLK_APBCLK_CAN1_EN_Msk               (1ul << SYSCLK_APBCLK_CAN1_EN_Pos)      /*!< SYSCLK APBCLK: CAN1_EN Mask */

#define SYSCLK_APBCLK_CAN0_EN_Pos               24                                      /*!< SYSCLK APBCLK: CAN0_EN Position */
#define SYSCLK_APBCLK_CAN0_EN_Msk               (1ul << SYSCLK_APBCLK_CAN0_EN_Pos)      /*!< SYSCLK APBCLK: CAN0_EN Mask */

#define SYSCLK_APBCLK_PWM67_EN_Pos              23                                      /*!< SYSCLK APBCLK: PWM67_EN Position */
#define SYSCLK_APBCLK_PWM67_EN_Msk              (1ul << SYSCLK_APBCLK_PWM67_EN_Pos)     /*!< SYSCLK APBCLK: PWM67_EN Mask */

#define SYSCLK_APBCLK_PWM45_EN_Pos              22                                      /*!< SYSCLK APBCLK: PWM45_EN Position */
#define SYSCLK_APBCLK_PWM45_EN_Msk              (1ul << SYSCLK_APBCLK_PWM45_EN_Pos)     /*!< SYSCLK APBCLK: PWM45_EN Mask */

#define SYSCLK_APBCLK_PWM23_EN_Pos              21                                      /*!< SYSCLK APBCLK: PWM23_EN Position */
#define SYSCLK_APBCLK_PWM23_EN_Msk              (1ul << SYSCLK_APBCLK_PWM23_EN_Pos)     /*!< SYSCLK APBCLK: PWM23_EN Mask */

#define SYSCLK_APBCLK_PWM01_EN_Pos              20                                      /*!< SYSCLK APBCLK: PWM01_EN Position */
#define SYSCLK_APBCLK_PWM01_EN_Msk              (1ul << SYSCLK_APBCLK_PWM01_EN_Pos)     /*!< SYSCLK APBCLK: PWM01_EN Mask */

#define SYSCLK_APBCLK_UART2_EN_Pos              18                                      /*!< SYSCLK APBCLK: UART2_EN Position */
#define SYSCLK_APBCLK_UART2_EN_Msk              (1ul << SYSCLK_APBCLK_UART2_EN_Pos)     /*!< SYSCLK APBCLK: UART2_EN Mask */

#define SYSCLK_APBCLK_UART1_EN_Pos              17                                      /*!< SYSCLK APBCLK: UART1_EN Position */
#define SYSCLK_APBCLK_UART1_EN_Msk              (1ul << SYSCLK_APBCLK_UART1_EN_Pos)     /*!< SYSCLK APBCLK: UART1_EN Mask */

#define SYSCLK_APBCLK_UART0_EN_Pos              16                                      /*!< SYSCLK APBCLK: UART0_EN Position */
#define SYSCLK_APBCLK_UART0_EN_Msk              (1ul << SYSCLK_APBCLK_UART0_EN_Pos)     /*!< SYSCLK APBCLK: UART0_EN Mask */

#define SYSCLK_APBCLK_SPI3_EN_Pos               15                                      /*!< SYSCLK APBCLK: SPI3_EN Position */
#define SYSCLK_APBCLK_SPI3_EN_Msk               (1ul << SYSCLK_APBCLK_SPI3_EN_Pos)      /*!< SYSCLK APBCLK: SPI3_EN Mask */

#define SYSCLK_APBCLK_SPI2_EN_Pos               14                                      /*!< SYSCLK APBCLK: SPI2_EN Position */
#define SYSCLK_APBCLK_SPI2_EN_Msk               (1ul << SYSCLK_APBCLK_SPI2_EN_Pos)      /*!< SYSCLK APBCLK: SPI2_EN Mask */

#define SYSCLK_APBCLK_SPI1_EN_Pos               13                                      /*!< SYSCLK APBCLK: SPI1_EN Position */
#define SYSCLK_APBCLK_SPI1_EN_Msk               (1ul << SYSCLK_APBCLK_SPI1_EN_Pos)      /*!< SYSCLK APBCLK: SPI1_EN Mask */

#define SYSCLK_APBCLK_SPI0_EN_Pos               12                                      /*!< SYSCLK APBCLK: SPI0_EN Position */
#define SYSCLK_APBCLK_SPI0_EN_Msk               (1ul << SYSCLK_APBCLK_SPI0_EN_Pos)      /*!< SYSCLK APBCLK: SPI0_EN Mask */

#define SYSCLK_APBCLK_I2C1_EN_Pos               9                                       /*!< SYSCLK APBCLK: I2C1_EN Position */
#define SYSCLK_APBCLK_I2C1_EN_Msk               (1ul << SYSCLK_APBCLK_I2C1_EN_Pos)      /*!< SYSCLK APBCLK: I2C1_EN Mask */

#define SYSCLK_APBCLK_I2C0_EN_Pos               8                                       /*!< SYSCLK APBCLK: I2C0_EN_ Position */
#define SYSCLK_APBCLK_I2C0_EN_Msk               (1ul << SYSCLK_APBCLK_I2C0_EN_Pos)      /*!< SYSCLK APBCLK: I2C0_EN_ Mask */

#define SYSCLK_APBCLK_FDIV_EN_Pos               6                                       /*!< SYSCLK APBCLK: FDIV_EN Position */
#define SYSCLK_APBCLK_FDIV_EN_Msk               (1ul << SYSCLK_APBCLK_FDIV_EN_Pos)      /*!< SYSCLK APBCLK: FDIV_EN Mask */

#define SYSCLK_APBCLK_TMR3_EN_Pos               5                                       /*!< SYSCLK APBCLK: TMR3_EN Position */
#define SYSCLK_APBCLK_TMR3_EN_Msk               (1ul << SYSCLK_APBCLK_TMR3_EN_Pos)      /*!< SYSCLK APBCLK: TMR3_EN Mask */

#define SYSCLK_APBCLK_TMR2_EN_Pos               4                                       /*!< SYSCLK APBCLK: TMR2_EN Position */
#define SYSCLK_APBCLK_TMR2_EN_Msk               (1ul << SYSCLK_APBCLK_TMR2_EN_Pos)      /*!< SYSCLK APBCLK: TMR2_EN Mask */

#define SYSCLK_APBCLK_TMR1_EN_Pos               3                                       /*!< SYSCLK APBCLK: TMR1_EN Position */
#define SYSCLK_APBCLK_TMR1_EN_Msk               (1ul << SYSCLK_APBCLK_TMR1_EN_Pos)      /*!< SYSCLK APBCLK: TMR1_EN Mask */
                                                
#define SYSCLK_APBCLK_TMR0_EN_Pos               2                                       /*!< SYSCLK APBCLK: TMR0_EN Position */
#define SYSCLK_APBCLK_TMR0_EN_Msk               (1ul << SYSCLK_APBCLK_TMR0_EN_Pos)      /*!< SYSCLK APBCLK: TMR0_EN Mask */      

#define SYSCLK_APBCLK_RTC_EN_Pos                1                                       /*!< SYSCLK APBCLK: RTC_EN Position */
#define SYSCLK_APBCLK_RTC_EN_Msk                (1ul << SYSCLK_APBCLK_RTC_EN_Pos)       /*!< SYSCLK APBCLK: RTC_EN Mask */

#define SYSCLK_APBCLK_WDT_EN_Pos                0                                       /*!< SYSCLK APBCLK: WDT_EN Position */
#define SYSCLK_APBCLK_WDT_EN_Msk                (1ul << SYSCLK_APBCLK_WDT_EN_Pos)       /*!< SYSCLK APBCLK: WDT_EN Mask */

/* SYSCLK APBCLK1 Bit Field Definitions */
#define SYSCLK_APBCLK1_SC2_EN_Pos                2                                      /*!< SYSCLK APBCLK1: SC2_EN Position */
#define SYSCLK_APBCLK1_SC2_EN_Msk                (1ul << SYSCLK_APBCLK1_SC2_EN_Pos)     /*!< SYSCLK APBCLK1: SC2_EN Mask */

#define SYSCLK_APBCLK1_SC1_EN_Pos                1                                      /*!< SYSCLK APBCLK1: SC1_EN Position */
#define SYSCLK_APBCLK1_SC1_EN_Msk                (1ul << SYSCLK_APBCLK1_SC1_EN_Pos)     /*!< SYSCLK APBCLK1: SC1_EN Mask */

#define SYSCLK_APBCLK1_SC0_EN_Pos                0                                      /*!< SYSCLK APBCLK1: SC0_EN Position */
#define SYSCLK_APBCLK1_SC0_EN_Msk                (1ul << SYSCLK_APBCLK1_SC0_EN_Pos)     /*!< SYSCLK APBCLK1: SC0_EN Mask */

/* SYSCLK CLKSTATUS Bit Field Definitions */
#define SYSCLK_CLKSTATUS_CLK_SW_FAIL_Pos        7                                           /*!< SYSCLK CLKSTATUS: CLK_SW_FAIL Position */
#define SYSCLK_CLKSTATUS_CLK_SW_FAIL_Msk        (1ul << SYSCLK_CLKSTATUS_CLK_SW_FAIL_Pos)   /*!< SYSCLK CLKSTATUS: CLK_SW_FAIL Mask */

#define SYSCLK_CLKSTATUS_IRC22M_STB_Pos         4                                           /*!< SYSCLK CLKSTATUS: IRC22M_STB Position */
#define SYSCLK_CLKSTATUS_IRC22M_STB_Msk         (1ul << SYSCLK_CLKSTATUS_IRC22M_STB_Pos)    /*!< SYSCLK CLKSTATUS: IRC22M_STB Mask */

#define SYSCLK_CLKSTATUS_IRC10K_STB_Pos         3                                           /*!< SYSCLK CLKSTATUS: IRC10K_STB Position */
#define SYSCLK_CLKSTATUS_IRC10K_STB_Msk         (1ul << SYSCLK_CLKSTATUS_IRC10K_STB_Pos)    /*!< SYSCLK CLKSTATUS: IRC10K_STB Mask */

#define SYSCLK_CLKSTATUS_PLL_STB_Pos            2                                           /*!< SYSCLK CLKSTATUS: PLL_STB Position */
#define SYSCLK_CLKSTATUS_PLL_STB_Msk            (1ul << SYSCLK_CLKSTATUS_PLL_STB_Pos)       /*!< SYSCLK CLKSTATUS: PLL_STB Mask */

#define SYSCLK_CLKSTATUS_XTL32K_STB_Pos         1                                           /*!< SYSCLK CLKSTATUS: XTL32K_STB Position */
#define SYSCLK_CLKSTATUS_XTL32K_STB_Msk         (1ul << SYSCLK_CLKSTATUS_XTL32K_STB_Pos)    /*!< SYSCLK CLKSTATUS: XTL32K_STB Mask */

#define SYSCLK_CLKSTATUS_XTL12M_STB_Pos         0                                           /*!< SYSCLK CLKSTATUS: XTL12M_STB Position */
#define SYSCLK_CLKSTATUS_XTL12M_STB_Msk         (1ul << SYSCLK_CLKSTATUS_XTL12M_STB_Pos)    /*!< SYSCLK CLKSTATUS: XTL12M_STB Mask */

/* SYSCLK CLKSEL0 Bit Field Definitions */
#define SYSCLK_CLKSEL0_STCLK_S_Pos              3                                           /*!< SYSCLK CLKSEL0: STCLK_S Position */
#define SYSCLK_CLKSEL0_STCLK_S_Msk              (7ul << SYSCLK_CLKSEL0_STCLK_S_Pos)         /*!< SYSCLK CLKSEL0: STCLK_S Mask */

#define SYSCLK_CLKSEL0_HCLK_S_Pos               0                                           /*!< SYSCLK CLKSEL0: HCLK_S Position */
#define SYSCLK_CLKSEL0_HCLK_S_Msk               (7ul << SYSCLK_CLKSEL0_HCLK_S_Pos)          /*!< SYSCLK CLKSEL0: HCLK_S Mask */

/* SYSCLK CLKSEL1 Bit Field Definitions */
#define SYSCLK_CLKSEL1_PWM23_S_Pos              30                                      /*!< SYSCLK CLKSEL1: PWM23_S Position */
#define SYSCLK_CLKSEL1_PWM23_S_Msk              (3ul << SYSCLK_CLKSEL1_PWM23_S_Pos)     /*!< SYSCLK CLKSEL1: PWM23_S Mask */

#define SYSCLK_CLKSEL1_PWM01_S_Pos              28                                      /*!< SYSCLK CLKSEL1: PWM01_S Position */
#define SYSCLK_CLKSEL1_PWM01_S_Msk              (3ul << SYSCLK_CLKSEL1_PWM01_S_Pos)     /*!< SYSCLK CLKSEL1: PWM01_S Mask */

#define SYSCLK_CLKSEL1_UART_S_Pos               24                                      /*!< SYSCLK CLKSEL1: UART_S Position */
#define SYSCLK_CLKSEL1_UART_S_Msk               (3ul << SYSCLK_CLKSEL1_UART_S_Pos)      /*!< SYSCLK CLKSEL1: UART_S Mask */

#define SYSCLK_CLKSEL1_TMR3_S_Pos               20                                      /*!< SYSCLK CLKSEL1: TMR3_S Position */
#define SYSCLK_CLKSEL1_TMR3_S_Msk               (7ul << SYSCLK_CLKSEL1_TMR3_S_Pos)      /*!< SYSCLK CLKSEL1: TMR3_S Mask */

#define SYSCLK_CLKSEL1_TMR2_S_Pos               16                                      /*!< SYSCLK CLKSEL1: TMR2_S Position */
#define SYSCLK_CLKSEL1_TMR2_S_Msk               (7ul << SYSCLK_CLKSEL1_TMR2_S_Pos)      /*!< SYSCLK CLKSEL1: TMR2_S Mask */

#define SYSCLK_CLKSEL1_TMR1_S_Pos               12                                      /*!< SYSCLK CLKSEL1: TMR1_S Position */
#define SYSCLK_CLKSEL1_TMR1_S_Msk               (7ul << SYSCLK_CLKSEL1_TMR1_S_Pos)      /*!< SYSCLK CLKSEL1: TMR1_S Mask */

#define SYSCLK_CLKSEL1_TMR0_S_Pos               8                                       /*!< SYSCLK CLKSEL1: TMR0_S Position */
#define SYSCLK_CLKSEL1_TMR0_S_Msk               (7ul << SYSCLK_CLKSEL1_TMR0_S_Pos)      /*!< SYSCLK CLKSEL1: TMR0_S Mask */

#define SYSCLK_CLKSEL1_SPI3_S_Pos               7                                       /*!< SYSCLK CLKSEL1: SPI3_S Position */
#define SYSCLK_CLKSEL1_SPI3_S_Msk               (1ul << SYSCLK_CLKSEL1_SPI3_S_Pos)      /*!< SYSCLK CLKSEL1: SPI3_S Mask */

#define SYSCLK_CLKSEL1_SPI2_S_Pos               6                                       /*!< SYSCLK CLKSEL1: SPI2_S Position */
#define SYSCLK_CLKSEL1_SPI2_S_Msk               (1ul << SYSCLK_CLKSEL1_SPI2_S_Pos)      /*!< SYSCLK CLKSEL1: SPI2_S Mask */

#define SYSCLK_CLKSEL1_SPI1_S_Pos               5                                       /*!< SYSCLK CLKSEL1: SPI1_S Position */
#define SYSCLK_CLKSEL1_SPI1_S_Msk               (1ul << SYSCLK_CLKSEL1_SPI1_S_Pos)      /*!< SYSCLK CLKSEL1: SPI1_S Mask */

#define SYSCLK_CLKSEL1_SPI0_S_Pos               4                                       /*!< SYSCLK CLKSEL1: SPI0_S Position */
#define SYSCLK_CLKSEL1_SPI0_S_Msk               (1ul << SYSCLK_CLKSEL1_SPI0_S_Pos)      /*!< SYSCLK CLKSEL1: SPI0_S Mask */

#define SYSCLK_CLKSEL1_ADC_S_Pos                2                                       /*!< SYSCLK CLKSEL1: ADC_S Position */
#define SYSCLK_CLKSEL1_ADC_S_Msk                (3ul << SYSCLK_CLKSEL1_ADC_S_Pos)       /*!< SYSCLK CLKSEL1: ADC_S Mask */

#define SYSCLK_CLKSEL1_WDT_S_Pos                0                                       /*!< SYSCLK CLKSEL1: WDT_S Position */
#define SYSCLK_CLKSEL1_WDT_S_Msk                (3ul << SYSCLK_CLKSEL1_WDT_S_Pos)       /*!< SYSCLK CLKSEL1: WDT_S Mask */

/* SYSCLK CLKSEL2 Bit Field Definitions */
#define SYSCLK_CLKSEL2_WWDT_S_Pos              16                                       /*!< SYSCLK CLKSEL2: WWDT_S Position */
#define SYSCLK_CLKSEL2_WWDT_S_Msk              (3ul << SYSCLK_CLKSEL2_WWDT_S_Pos)       /*!< SYSCLK CLKSEL2: WWDT_S Mask */

#define SYSCLK_CLKSEL2_PWM67_S_EXT_Pos         11                                       /*!< SYSCLK CLKSEL2: PWM67_S_EXT Position */
#define SYSCLK_CLKSEL2_PWM67_S_EXT_Msk         (1ul << SYSCLK_CLKSEL2_PWM67_S_EXT_Pos)  /*!< SYSCLK CLKSEL2: PWM67_S_EXT Mask */

#define SYSCLK_CLKSEL2_PWM45_S_EXT_Pos         10                                       /*!< SYSCLK CLKSEL2: PWM45_S_EXT Position */
#define SYSCLK_CLKSEL2_PWM45_S_EXT_Msk         (1ul << SYSCLK_CLKSEL2_PWM45_S_EXT_Pos)  /*!< SYSCLK CLKSEL2: PWM45_S_EXT Mask */

#define SYSCLK_CLKSEL2_PWM23_S_EXT_Pos         9                                        /*!< SYSCLK CLKSEL2: PWM23_S_EXT Position */
#define SYSCLK_CLKSEL2_PWM23_S_EXT_Msk         (1ul << SYSCLK_CLKSEL2_PWM23_S_EXT_Pos)  /*!< SYSCLK CLKSEL2: PWM23_S_EXT Mask */

#define SYSCLK_CLKSEL2_PWM01_S_EXT_Pos         8                                        /*!< SYSCLK CLKSEL2: PWM01_S_EXT Position */
#define SYSCLK_CLKSEL2_PWM01_S_EXT_Msk         (1ul << SYSCLK_CLKSEL2_PWM01_S_EXT_Pos)  /*!< SYSCLK CLKSEL2: PWM01_S_EXT Mask */

#define SYSCLK_CLKSEL2_PWM67_S_Pos              6                                       /*!< SYSCLK CLKSEL2: PWM67_S_ Position */
#define SYSCLK_CLKSEL2_PWM67_S_Msk              (3ul << SYSCLK_CLKSEL2_PWM67_S_Pos)     /*!< SYSCLK CLKSEL2: PWM67_S_ Mask */

#define SYSCLK_CLKSEL2_PWM45_S_Pos              4                                       /*!< SYSCLK CLKSEL2: PWM45_S Position */
#define SYSCLK_CLKSEL2_PWM45_S_Msk              (3ul << SYSCLK_CLKSEL2_PWM45_S_Pos)      /*!< SYSCLK CLKSEL2: PWM45_S Mask */

#define SYSCLK_CLKSEL2_FRQDIV_S_Pos             2                                       /*!< SYSCLK CLKSEL2: FRQDIV_S Position */
#define SYSCLK_CLKSEL2_FRQDIV_S_Msk             (3ul << SYSCLK_CLKSEL2_FRQDIV_S_Pos)    /*!< SYSCLK CLKSEL2: FRQDIV_S Mask */

#define SYSCLK_CLKSEL2_I2S_S_Pos                0                                       /*!< SYSCLK CLKSEL2: I2S_S Position */
#define SYSCLK_CLKSEL2_I2S_S_Msk                (3ul << SYSCLK_CLKSEL2_I2S_S_Pos)       /*!< SYSCLK CLKSEL2: I2S_S Mask */

/* SYSCLK CLKSEL3 Bit Field Definitions */
#define SYSCLK_CLKSEL3_SC2_S_Pos                4                                       /*!< SYSCLK CLKSEL3: SC2_S Position */
#define SYSCLK_CLKSEL3_SC2_S_Msk                (3ul << SYSCLK_CLKSEL3_SC2_S_Pos)       /*!< SYSCLK CLKSEL3: SC2_S Mask */

#define SYSCLK_CLKSEL3_SC1_S_Pos                2                                       /*!< SYSCLK CLKSEL3: SC1_S Position */
#define SYSCLK_CLKSEL3_SC1_S_Msk                (3ul << SYSCLK_CLKSEL3_SC1_S_Pos)       /*!< SYSCLK CLKSEL3: SC1_S Mask */

#define SYSCLK_CLKSEL3_SC0_S_Pos                0                                       /*!< SYSCLK CLKSEL3: SC0_S Position */
#define SYSCLK_CLKSEL3_SC0_S_Msk                (3ul << SYSCLK_CLKSEL3_SC0_S_Pos)       /*!< SYSCLK CLKSEL3: SC0_S Mask */

/* SYSCLK CLKDIV Bit Field Definitions */
#define SYSCLK_CLKDIV_ADC_N_Pos                 16                                      /*!< SYSCLK CLKDIV: ADC_N Position */
#define SYSCLK_CLKDIV_ADC_N_Msk                 (0xFFul << SYSCLK_CLKDIV_ADC_N_Pos)     /*!< SYSCLK CLKDIV: ADC_N Mask */

#define SYSCLK_CLKDIV_UART_N_Pos                8                                       /*!< SYSCLK CLKDIV: UART_N Position */
#define SYSCLK_CLKDIV_UART_N_Msk                (0xFul << SYSCLK_CLKDIV_UART_N_Pos)     /*!< SYSCLK CLKDIV: UART_N Mask */

#define SYSCLK_CLKDIV_USB_N_Pos                 4                                       /*!< SYSCLK CLKDIV: USB_N Position */
#define SYSCLK_CLKDIV_USB_N_Msk                 (0xFul << SYSCLK_CLKDIV_USB_N_Pos)      /*!< SYSCLK CLKDIV: USB_N Mask */

#define SYSCLK_CLKDIV_HCLK_N_Pos                0                                       /*!< SYSCLK CLKDIV: HCLK_N Position */
#define SYSCLK_CLKDIV_HCLK_N_Msk                (0xFul << SYSCLK_CLKDIV_HCLK_N_Pos)     /*!< SYSCLK CLKDIV: HCLK_N Mask */

/* SYSCLK CLKDIV1 Bit Field Definitions */
#define SYSCLK_CLKDIV1_SC2_N_Pos                16                                      /*!< SYSCLK CLKDIV: SC2_N Position */
#define SYSCLK_CLKDIV1_SC2_N_Msk                (0xFFul << SYSCLK_CLKDIV1_SC2_N_Pos)    /*!< SYSCLK CLKDIV: SC2_N Mask */

#define SYSCLK_CLKDIV1_SC1_N_Pos                8                                       /*!< SYSCLK CLKDIV: SC1_N Position */
#define SYSCLK_CLKDIV1_SC1_N_Msk                (0xFFul << SYSCLK_CLKDIV1_SC1_N_Pos)    /*!< SYSCLK CLKDIV: SC1_N Mask */

#define SYSCLK_CLKDIV1_SC0_N_Pos                0                                       /*!< SYSCLK CLKDIV: SC0_N Position */
#define SYSCLK_CLKDIV1_SC0_N_Msk                (0xFFul << SYSCLK_CLKDIV1_SC0_N_Pos)    /*!< SYSCLK CLKDIV: SC0_N Mask */

/* SYSCLK PLLCON Bit Field Definitions */
#define SYSCLK_PLLCON_PLL_SRC_Pos               19                                      /*!< SYSCLK PLLCON: PLL_SRC Position */
#define SYSCLK_PLLCON_PLL_SRC_Msk               (1ul << SYSCLK_PLLCON_PLL_SRC_Pos)      /*!< SYSCLK PLLCON: PLL_SRC Mask */

#define SYSCLK_PLLCON_OE_Pos                    18                                      /*!< SYSCLK PLLCON: PLL_SRC Position */
#define SYSCLK_PLLCON_OE_Msk                    (1ul << SYSCLK_PLLCON_OE_Pos)           /*!< SYSCLK PLLCON: PLL_SRC Mask */

#define SYSCLK_PLLCON_BP_Pos                    17                                      /*!< SYSCLK PLLCON: OE Position */
#define SYSCLK_PLLCON_BP_Msk                    (1ul << SYSCLK_PLLCON_BP_Pos)           /*!< SYSCLK PLLCON: OE Mask */

#define SYSCLK_PLLCON_PD_Pos                    16                                      /*!< SYSCLK PLLCON: PD Position */
#define SYSCLK_PLLCON_PD_Msk                    (1ul << SYSCLK_PLLCON_PD_Pos)           /*!< SYSCLK PLLCON: PD Mask */

#define SYSCLK_PLLCON_OUT_DV_Pos                14                                      /*!< SYSCLK PLLCON: OUT_DV Position */
#define SYSCLK_PLLCON_OUT_DV_Msk                (3ul << SYSCLK_PLLCON_OUT_DV_Pos)       /*!< SYSCLK PLLCON: OUT_DV Mask */

#define SYSCLK_PLLCON_IN_DV_Pos                 9                                       /*!< SYSCLK PLLCON: IN_DV Position */
#define SYSCLK_PLLCON_IN_DV_Msk                 (0x1Ful << SYSCLK_PLLCON_IN_DV_Pos)     /*!< SYSCLK PLLCON: IN_DV Mask */

#define SYSCLK_PLLCON_FB_DV_Pos                 0                                       /*!< SYSCLK PLLCON: FB_DV Position */
#define SYSCLK_PLLCON_FB_DV_Msk                 (0x1FFul << SYSCLK_PLLCON_FB_DV_Pos)    /*!< SYSCLK PLLCON: FB_DV Mask */

/* SYSCLK FRQDIV Bit Field Definitions */
#define SYSCLK_FRQDIV_DIVIDER_EN_Pos            4                                       /*!< SYSCLK FRQDIV: DIVIDER_EN Position */
#define SYSCLK_FRQDIV_DIVIDER_EN_Msk            (1ul << SYSCLK_FRQDIV_DIVIDER_EN_Pos)   /*!< SYSCLK FRQDIV: DIVIDER_EN Mask */

#define SYSCLK_FRQDIV_FSEL_Pos                  0                                       /*!< SYSCLK FRQDIV: FRQDIV_FSEL Position */
#define SYSCLK_FRQDIV_FSEL_Msk                  (0xFul << SYSCLK_FRQDIV_FSEL_Pos)       /*!< SYSCLK FRQDIV: FRQDIV_FSEL Mask */

/*@}*/ /* end of group NUC200_SYSCLK */

/*---------------------------- Global Controller -----------------------------*/
/** @addtogroup NUC200_SYS NUC200 System Controller
  Memory Mapped Structure for NUC200 Series System Controller
  @{
 */

typedef struct
{
    __I uint32_t PDID;
    __IO uint32_t RSTSRC;
    __IO uint32_t IPRSTC1;
    __IO uint32_t IPRSTC2;
    __IO uint32_t IPRSTC3;   
    uint32_t RESERVE0;
    __IO uint32_t BODCR;
    __IO uint32_t TEMPCR;
    uint32_t RESERVE1;
    __IO uint32_t PORCR;
    uint32_t RESERVE2[2];
    __IO uint32_t GPA_MFP;
    __IO uint32_t GPB_MFP;
    __IO uint32_t GPC_MFP;
    __IO uint32_t GPD_MFP;
    __IO uint32_t GPE_MFP;
    __IO uint32_t GPF_MFP;
    uint32_t RESERVE3[2];
    __IO uint32_t ALT_MFP;
    uint32_t RESERVE4;
    __IO uint32_t ALT_MFP1;
    uint32_t RESERVE5[9];
    __IO uint32_t IRCTRIMCTL;
    __IO uint32_t IRCTRIMIEN;  
    __IO uint32_t IRCTRIMINT; 
    uint32_t RESERVE6[29];       
    __IO uint32_t REGWRPROT;
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

#define SYS_IPRSTC2_CAN1_RST_Pos                25                                  /*!< GCR IPRSTC2: CAN1_RST Position */
#define SYS_IPRSTC2_CAN1_RST_Msk                (1ul << SYS_IPRSTC2_CAN1_RST_Pos)   /*!< GCR IPRSTC2: CAN1_RST Mask */

#define SYS_IPRSTC2_CAN0_RST_Pos                24                                  /*!< GCR IPRSTC2: CAN0_RST Position */
#define SYS_IPRSTC2_CAN0_RST_Msk                (1ul << SYS_IPRSTC2_CAN0_RST_Pos)   /*!< GCR IPRSTC2: CAN0_RST Mask */

#define SYS_IPRSTC2_PS2_RST_Pos                 23                                  /*!< GCR IPRSTC2: PS2_RST Position */
#define SYS_IPRSTC2_PS2_RST_Msk                 (1ul << SYS_IPRSTC2_PS2_RST_Pos)    /*!< GCR IPRSTC2: PS2_RST Mask */

#define SYS_IPRSTC2_ACMP_RST_Pos                22                                  /*!< GCR IPRSTC2: ACMP_RST Position */
#define SYS_IPRSTC2_ACMP_RST_Msk                (1ul << SYS_IPRSTC2_ACMP_RST_Pos)   /*!< GCR IPRSTC2: ACMP_RST Mask */

#define SYS_IPRSTC2_PWM47_RST_Pos               21                                  /*!< GCR IPRSTC2: PWM47_RST Position */
#define SYS_IPRSTC2_PWM47_RST_Msk               (1ul << SYS_IPRSTC2_PWM47_RST_Pos)  /*!< GCR IPRSTC2: PWM47_RST Mask */

#define SYS_IPRSTC2_PWM03_RST_Pos               20                                  /*!< GCR IPRSTC2: PWM03_RST Position */
#define SYS_IPRSTC2_PWM03_RST_Msk               (1ul << SYS_IPRSTC2_PWM03_RST_Pos)  /*!< GCR IPRSTC2: PWM03_RST Mask */

#define SYS_IPRSTC2_UART2_RST_Pos               18                                  /*!< GCR IPRSTC2: UART2_RST Position */
#define SYS_IPRSTC2_UART2_RST_Msk               (1ul << SYS_IPRSTC2_UART2_RST_Pos)  /*!< GCR IPRSTC2: UART2_RST Mask */

#define SYS_IPRSTC2_UART1_RST_Pos               17                                  /*!< GCR IPRSTC2: UART1_RST Position */
#define SYS_IPRSTC2_UART1_RST_Msk               (1ul << SYS_IPRSTC2_UART1_RST_Pos)  /*!< GCR IPRSTC2: UART1_RST Mask */

#define SYS_IPRSTC2_UART0_RST_Pos               16                                  /*!< GCR IPRSTC2: UART0_RST Position */
#define SYS_IPRSTC2_UART0_RST_Msk               (1ul << SYS_IPRSTC2_UART0_RST_Pos)  /*!< GCR IPRSTC2: UART0_RST Mask */

#define SYS_IPRSTC2_SPI3_RST_Pos                15                                  /*!< GCR IPRSTC2: SPI3_RST Position */
#define SYS_IPRSTC2_SPI3_RST_Msk                (1ul << SYS_IPRSTC2_SPI3_RST_Pos)   /*!< GCR IPRSTC2: SPI3_RST Mask */

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

/* GCR IPRSTC3 Bit Field Definitions */
#define SYS_IPRSTC3_SC2_RST_Pos                 2                                   /*!< GCR IPRSTC3: SC2_RST Position */
#define SYS_IPRSTC3_SC2_RST_Msk                 (1ul << SYS_IPRSTC3_SC2_RST_Pos)    /*!< GCR IPRSTC3: SC2_RST Mask */

#define SYS_IPRSTC3_SC1_RST_Pos                 1                                   /*!< GCR IPRSTC3: SC1_RST Position */
#define SYS_IPRSTC3_SC1_RST_Msk                 (1ul << SYS_IPRSTC3_SC1_RST_Pos)    /*!< GCR IPRSTC3: SC1_RST Mask */

#define SYS_IPRSTC3_SC0_RST_Pos                 0                                   /*!< GCR IPRSTC3: SC0_RST Position */
#define SYS_IPRSTC3_SC0_RST_Msk                 (1ul << SYS_IPRSTC3_SC0_RST_Pos)    /*!< GCR IPRSTC3: SC0_RST Mask */

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

/* GCR TEMPCR Bit Field Definitions */
#define SYS_TEMPCR_VTEMP_EN_Pos                 0                                   /*!< GCR TEMPCR: VTEMP_EN Position */
#define SYS_TEMPCR_VTEMP_EN_Msk                 (1ul << SYS_TEMPCR_VTEMP_EN_Pos)    /*!< GCR TEMPCR: VTEMP_EN Mask */

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

/* GCR GPEMFP Bit Field Definitions */
#define SYS_GPE_MFP_GPE_TYPE_Pos                 16                                         /*!< GCR GPE_MFP: GPE_TYPE Position */
#define SYS_GPE_MFP_GPE_TYPE_Msk                 (0xFFFFul << SYS_GPE_MFP_GPE_TYPE_Pos)     /*!< GCR GPE_MFP: GPE_TYPE Mask */

#define SYS_GPE_MFP_GPE_MFP5_Pos                 5                                          /*!< GCR GPE_MFP: GPE_MFP5 Position */     
#define SYS_GPE_MFP_GPE_MFP5_Msk                 (1ul << SYS_GPE_MFP_GPE_MFP5_Pos)          /*!< GCR GPE_MFP: GPE_MFP5 Mask */

#define SYS_GPE_MFP_GPE_MFP1_Pos                 1                                          /*!< GCR GPE_MFP: GPE_MFP1 Position */
#define SYS_GPE_MFP_GPE_MFP1_Msk                 (1ul << SYS_GPE_MFP_GPE_MFP1_Pos)          /*!< GCR GPE_MFP: GPE_MFP1 Mask */

#define SYS_GPE_MFP_GPE_MFP0_Pos                 0                                          /*!< GCR GPE_MFP: GPE_MFP0 Position */
#define SYS_GPE_MFP_GPE_MFP0_Msk                 (1ul << SYS_GPE_MFP_GPE_MFP0_Pos)          /*!< GCR GPE_MFP: GPE_MFP0 Mask */

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
#define SYS_ALT_MFP_PB2_CPO0_Pos                30                                          /*!< GCR ALT_MFP: PB2_CPO0 Position */
#define SYS_ALT_MFP_PB2_CPO0_Msk                (1ul << SYS_ALT_MFP_PB2_CPO0_Pos)           /*!< GCR ALT_MFP: PB2_CPO0 Mask */

#define SYS_ALT_MFP_PB8_CLKO_Pos                29                                         /*!< GCR ALT_MFP: PB8_CLKO Position */
#define SYS_ALT_MFP_PB8_CLKO_Msk                (1ul << SYS_ALT_MFP_PB8_CLKO_Pos)      /*!< GCR ALT_MFP: PB8_CLKO Mask */

#define SYS_ALT_MFP_PA10_11_CAN1_Pos             28                                         /*!< GCR ALT_MFP: PA10_11_CAN1 Position */
#define SYS_ALT_MFP_PA10_11_CAN1_Msk             (1ul << SYS_ALT_MFP_PA10_11_CAN1_Pos)      /*!< GCR ALT_MFP: PA10_11_CAN1 Mask */

#define SYS_ALT_MFP_PB3_T3EX_Pos                 27                                         /*!< GCR ALT_MFP: PB3_T3EX Position */
#define SYS_ALT_MFP_PB3_T3EX_Msk                 (1ul << SYS_ALT_MFP_PB3_T3EX_Pos)          /*!< GCR ALT_MFP: PB3_T3EX Mask */

#define SYS_ALT_MFP_PB2_T2EX_Pos                 26                                         /*!< GCR ALT_MFP: PB2_T2EX Position */
#define SYS_ALT_MFP_PB2_T2EX_Msk                 (1ul << SYS_ALT_MFP_PB2_T2EX_Pos)          /*!< GCR ALT_MFP: PB3_T3EX Mask */

#define SYS_ALT_MFP_PE5_T1EX_Pos                 25                                         /*!< GCR ALT_MFP: PE5_T1EX Position */
#define SYS_ALT_MFP_PE5_T1EX_Msk                 (1ul << SYS_ALT_MFP_PE5_T1EX_Pos)          /*!< GCR ALT_MFP: PE5_T1EX Mask */

#define SYS_ALT_MFP_PB15_T0EX_Pos                24                                         /*!< GCR ALT_MFP: PB15_T0EX Position */
#define SYS_ALT_MFP_PB15_T0EX_Msk                (1ul << SYS_ALT_MFP_PB15_T0EX_Pos)         /*!< GCR ALT_MFP: PB15_T0EX Mask */

#define SYS_ALT_MFP_PB12_CLKO_Pos                10                                         /*!< GCR ALT_MFP: PB12_CLKO Position */
#define SYS_ALT_MFP_PB12_CLKO_Msk                (1ul << SYS_ALT_MFP_PB12_CLKO_Pos)         /*!< GCR ALT_MFP: PB12_CLKO Mask */

#define SYS_ALT_MFP_PA15_I2SMCLK_Pos             9                                          /*!< GCR ALT_MFP: PA15_I2SMCLK Position */
#define SYS_ALT_MFP_PA15_I2SMCLK_Msk             (1ul << SYS_ALT_MFP_PA15_I2SMCLK_Pos)      /*!< GCR ALT_MFP: PA15_I2SMCLK Mask */

#define SYS_ALT_MFP_PC3_I2SDO_Pos                8                                          /*!< GCR ALT_MFP: PC3_I2SDO Position */
#define SYS_ALT_MFP_PC3_I2SDO_Msk                (1ul << SYS_ALT_MFP_PC3_I2SDO_Pos)         /*!< GCR ALT_MFP: PC3_I2SDO Mask */

#define SYS_ALT_MFP_PC2_I2SDI_Pos                7                                          /*!< GCR ALT_MFP: PC2_I2SDI Position */
#define SYS_ALT_MFP_PC2_I2SDI_Msk                (1ul << SYS_ALT_MFP_PC2_I2SDI_Pos)         /*!< GCR ALT_MFP: PC2_I2SDI Mask */

#define SYS_ALT_MFP_PC1_I2SBCLK_Pos              6                                          /*!< GCR ALT_MFP: PC1_I2SBCLK Position */
#define SYS_ALT_MFP_PC1_I2SBCLK_Msk              (1ul << SYS_ALT_MFP_PC1_I2SBCLK_Pos)       /*!< GCR ALT_MFP: PC1_I2SBCLK Mask */

#define SYS_ALT_MFP_PC0_I2SLRCLK_Pos             5                                          /*!< GCR ALT_MFP: PC0_I2SLRCLK Position */
#define SYS_ALT_MFP_PC0_I2SLRCLK_Msk             (1ul << SYS_ALT_MFP_PC0_I2SLRCLK_Pos)      /*!< GCR ALT_MFP: PC0_I2SLRCLK Mask */

#define SYS_ALT_MFP_PB11_PWM4_Pos                4                                          /*!< GCR ALT_MFP: PB11_PWM4 Position */
#define SYS_ALT_MFP_PB11_PWM4_Msk                (1ul << SYS_ALT_MFP_PB11_PWM4_Pos)         /*!< GCR ALT_MFP: PB11_PWM4 Mask */

#define SYS_ALT_MFP_PB14_S31_Pos                 3                                          /*!< GCR ALT_MFP: PB14_S31 Position */
#define SYS_ALT_MFP_PB14_S31_Msk                 (1ul << SYS_ALT_MFP_PB14_S31_Pos)          /*!< GCR ALT_MFP: PB14_S31 Mask */

#define SYS_ALT_MFP_PA7_S21_Pos                  2                                          /*!< GCR ALT_MFP: PA7_S21 Position */
#define SYS_ALT_MFP_PA7_S21_Msk                  (1ul << SYS_ALT_MFP_PA7_S21_Pos)           /*!< GCR ALT_MFP: PA7_S21 Mask */

#define SYS_ALT_MFP_PB9_S11_Pos                  1                                          /*!< GCR ALT_MFP: PB9_S11 Position */
#define SYS_ALT_MFP_PB9_S11_Msk                  (1ul << SYS_ALT_MFP_PB9_S11_Pos)           /*!< GCR ALT_MFP: PB9_S11 Mask */

#define SYS_ALT_MFP_PB10_S01_Pos                 0                                          /*!< GCR ALT_MFP: PB10_S01 Position */
#define SYS_ALT_MFP_PB10_S01_Msk                 (1ul << SYS_ALT_MFP_PB10_S01_Pos)          /*!< GCR ALT_MFP: PB10_S01 Mask */

/* GCR ALTMFP1 Bit Field Definitions */
#define SYS_ALT_MFP1_PB3_SC2CD_Pos              14                                          /*!< GCR ALT_MFP1: PB3_SC2CD Position */
#define SYS_ALT_MFP1_PB3_SC2CD_Msk              (1ul << SYS_ALT_MFP1_PB3_SC2CD_Pos)         /*!< GCR ALT_MFP1: PB3_SC2CD Mask */

#define SYS_ALT_MFP1_PA14_SC2RST_Pos            13                                          /*!< GCR ALT_MFP1: PA14_SC2RST Position */
#define SYS_ALT_MFP1_PA14_SC2RST_Msk            (1ul << SYS_ALT_MFP1_PA14_SC2RST_Pos)       /*!< GCR ALT_MFP1: PA14_SC2RST Mask */

#define SYS_ALT_MFP1_PA15_SC2PWR_Pos            12                                          /*!< GCR ALT_MFP1: PA15_SC2PWR Position */
#define SYS_ALT_MFP1_PA15_SC2PWR_Msk            (1ul << SYS_ALT_MFP1_PA15_SC2PWR_Pos)       /*!< GCR ALT_MFP1: PA15_SC2PWR Mask */

#define SYS_ALT_MFP1_PA12_SC2DAT_Pos             11                                          /*!< GCR ALT_MFP1: PA12_SC2DAT Position */
#define SYS_ALT_MFP1_PA12_SC2DAT_Msk             (1ul << SYS_ALT_MFP1_PA12_SC2DAT_Pos)        /*!< GCR ALT_MFP1: PA12_SC2DAT Mask */

#define SYS_ALT_MFP1_PA13_SC2CLK_Pos             10                                          /*!< GCR ALT_MFP1: PA13_SC2CLK Position */
#define SYS_ALT_MFP1_PA13_SC2CLK_Msk             (1ul << SYS_ALT_MFP1_PA13_SC2CLK_Pos)        /*!< GCR ALT_MFP1: PA13_SC2CLK Mask */

#define SYS_ALT_MFP1_PC7_SC1CD_Pos             9                                          /*!< GCR ALT_MFP1: PC7_SC1CD Position */
#define SYS_ALT_MFP1_PC7_SC1CD_Msk             (1ul << SYS_ALT_MFP1_PC7_SC1CD_Pos)        /*!< GCR ALT_MFP1: PC7_SC1CD Mask */

#define SYS_ALT_MFP1_PA5_SC1RST_Pos             8                                           /*!< GCR ALT_MFP1: PA5_SC1RST Position */
#define SYS_ALT_MFP1_PA5_SC1RST_Msk             (1ul << SYS_ALT_MFP1_PA5_SC1RST_Pos)        /*!< GCR ALT_MFP1: PA5_SC1RST Mask */

#define SYS_ALT_MFP1_PA4_SC1PWR_Pos             7                                           /*!< GCR ALT_MFP1: PA4_SC1PWR Position */
#define SYS_ALT_MFP1_PA4_SC1PWR_Msk             (1ul << SYS_ALT_MFP1_PA4_SC1PWR_Pos)        /*!< GCR ALT_MFP1: PA4_SC1PWR Mask */

#define SYS_ALT_MFP1_PA7_SC1DAT_Pos             6                                           /*!< GCR ALT_MFP1: PA7_SC1DAT Position */
#define SYS_ALT_MFP1_PA7_SC1DAT_Msk             (1ul << SYS_ALT_MFP1_PA7_SC1DAT_Pos)        /*!< GCR ALT_MFP1: PA7_SC1DAT Mask */

#define SYS_ALT_MFP1_PA6_SC1CLK_Pos             5                                           /*!< GCR ALT_MFP1: PA6_SC1CLK Position */
#define SYS_ALT_MFP1_PA6_SC1CLK_Msk             (1ul << SYS_ALT_MFP1_PA6_SC1CLK_Pos)        /*!< GCR ALT_MFP1: PA6_SC1CLK Mask */

#define SYS_ALT_MFP1_PC6_SC0CD_Pos              4                                           /*!< GCR ALT_MFP1: PC6_SC0CD Position */
#define SYS_ALT_MFP1_PC6_SC0CD_Msk              (1ul << SYS_ALT_MFP1_PC6_SC0CD_Pos)         /*!< GCR ALT_MFP1: PC6_SC0CD Mask */

#define SYS_ALT_MFP1_PA1_SC0RST_Pos             3                                           /*!< GCR ALT_MFP1: PA1_SC0RST Position */
#define SYS_ALT_MFP1_PA1_SC0RST_Msk             (1ul << SYS_ALT_MFP1_PA1_SC0RST_Pos)        /*!< GCR ALT_MFP1: PA1_SC0RST Mask */

#define SYS_ALT_MFP1_PA0_SC0PWR_Pos             2                                           /*!< GCR ALT_MFP1: PA0_SC0PWR Position */
#define SYS_ALT_MFP1_PA0_SC0PWR_Msk             (1ul << SYS_ALT_MFP1_PA0_SC0PWR_Pos)        /*!< GCR ALT_MFP1: PA0_SC0PWR Mask */

#define SYS_ALT_MFP1_PA3_SC0DAT_Pos             1                                           /*!< GCR ALT_MFP1: PA3_SC0DAT Position */
#define SYS_ALT_MFP1_PA3_SC0DAT_Msk             (1ul << SYS_ALT_MFP1_PA3_SC0DAT_Pos)        /*!< GCR ALT_MFP1: PA3_SC0DAT Mask */

#define SYS_ALT_MFP1_PA2_SC0CLK_Pos             0                                           /*!< GCR ALT_MFP1: PA2_SC0CLK Position */
#define SYS_ALT_MFP1_PA2_SC0CLK_Msk             (1ul << SYS_ALT_MFP1_PA2_SC0CLK_Pos)        /*!< GCR ALT_MFP1: PA2_SC0CLK Mask */

/* GCR IRCTRIMCTL Bit Field Definitions */
#define SYS_IRCTRIMCTL_CLKERR_STOP_EN_Pos       8                                           /*!< GCR IRCTRIMCTL: CLKERR_STOP_EN Position */
#define SYS_IRCTRIMCTL_CLKERR_STOP_EN_Msk       (1ul << SYS_IRCTRIMCTL_CLKERR_STOP_EN_Pos)  /*!< GCR IRCTRIMCTL: CLKERR_STOP_EN Mask */

#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos       6                                           /*!< GCR IRCTRIMCTL: TRIM_RETRY_CNT Position */
#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Msk       (3ul << SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos)  /*!< GCR IRCTRIMCTL: TRIM_RETRY_CNT Mask */

#define SYS_IRCTRIMCTL_TRIM_LOOP_Pos            4                                           /*!< GCR IRCTRIMCTL: TRIM_LOOP Position */
#define SYS_IRCTRIMCTL_TRIM_LOOP_Msk            (3ul << SYS_IRCTRIMCTL_TRIM_LOOP_Pos)       /*!< GCR IRCTRIMCTL: TRIM_LOOP Mask */

#define SYS_IRCTRIMCTL_TRIM_SEL_Pos             0                                           /*!< GCR IRCTRIMCTL: TRIM_SEL Position */
#define SYS_IRCTRIMCTL_TRIM_SEL_Msk             (3ul << SYS_IRCTRIMCTL_TRIM_SEL_Pos)        /*!< GCR IRCTRIMCTL: TRIM_SEL Mask */

/* GCR IRCTRIMIEN Bit Field Definitions */
#define SYS_IRCTRIMIEN_CLKERR_IEN_Pos           2                                           /*!< GCR IRCTRIMIEN: CLKERR_IEN Position */
#define SYS_IRCTRIMIEN_CLKERR_IEN_Msk           (1ul << SYS_IRCTRIMIEN_CLKERR_IEN_Pos)      /*!< GCR IRCTRIMIEN: CLKERR_IEN Mask */

#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos        1                                           /*!< GCR IRCTRIMIEN: TRIM_FAIL_IEN Position */
#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Msk        (1ul << SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos)   /*!< GCR IRCTRIMIEN: TRIM_FAIL_IEN Mask */

/* GCR IRCTRIMINT Bit Field Definitions */
#define SYS_IRCTRIMINT_CLKERR_INT_Pos           2                                           /*!< GCR IRCTRIMINT: CLKERR_INT Position */
#define SYS_IRCTRIMINT_CLKERR_INT_Msk           (1ul << SYS_IRCTRIMINT_CLKERR_INT_Pos)      /*!< GCR IRCTRIMINT: CLKERR_INT Mask */

#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos        1                                           /*!< GCR IRCTRIMINT: TRIM_FAIL_INT Position */
#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Msk        (1ul << SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos)   /*!< GCR IRCTRIMINT: TRIM_FAIL_INT Mask */

#define SYS_IRCTRIMINT_FREQ_LOCK_Pos            0                                           /*!< GCR IRCTRIMINT: FREQ_LOCK Position */
#define SYS_IRCTRIMINT_FREQ_LOCK_Msk            (1ul << SYS_IRCTRIMINT_FREQ_LOCK_Pos)       /*!< GCR IRCTRIMINT: FREQ_LOCK Mask */

/* GCR REGWRPROT Bit Field Definitions */
#define SYS_REGWRPROT_REGWRPROT_Pos             0                                           /*!< GCR REGWRPROT: REGWRPROT Position */
#define SYS_REGWRPROT_REGWRPROT_Msk             (0xFFul << SYS_REGWRPROT_REGWRPROT_Pos)     /*!< GCR REGWRPROT: REGWRPROT Mask */


typedef struct
{
    __I uint32_t IRQSRC[32];
    __IO uint32_t NMISEL;
    __IO uint32_t MCUIRQ;
} GCR_INT_T;

/* INT IRQSRC Bit Field Definitions */
#define INT_IRQSRC_INT_SRC_Pos                  0                                   /*!< INT IRQSRC: INT_SRC Position */ 
#define INT_IRQSRC_INT_SRC_Msk                  (0xFul << INT_IRQSRC_INT_SRC_Pos)

/* INT NMI_SEL Bit Field Definitions */
#define INT_NMI_SEL_NMI_EN_Pos                  8                                   /*!< INT NMI_SEL: NMI_EN Position */      
#define INT_NMI_SEL_NMI_EN_Msk                  (1ul << INT_NMI_SEL_NMI_EN_Pos)     /*!< INT NMI_SEL: NMI_EN Mask */

#define INT_NMI_SEL_NMI_SEL_Pos                 0                                   /*!< INT NMI_SEL: NMI_SEL Position */
#define INT_NMI_SEL_NMI_SEL_Msk                 (0x1Ful << INT_NMI_SEL_NMI_SEL_Pos) /*!< INT NMI_SEL: NMI_SEL Mask */
/*@}*/ /* end of group NUC200_SYS */

/*-------------------------- FLASH Memory Controller -------------------------*/
/** @addtogroup NUC200_FMC NUC200 FMC
  Memory Mapped Structure for NUC200 Series Flash Memory Controller
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
    
    __I  uint32_t  RESERVED[9];

    __IO uint32_t ISPSTA;

} FMC_T;

/* FMC ISPCON Bit Field Definitions */
#define FMC_ISPCON_ET_Pos                       12                                      /*!< FMC ISPCON: ET Position */
#define FMC_ISPCON_ET_Msk                       (7ul << FMC_ISPCON_ET_Pos)              /*!< FMC ISPCON: ET Mask     */

#define FMC_ISPCON_PT_Pos                       8                                       /*!< FMC ISPCON: PT Position */
#define FMC_ISPCON_PT_Msk                       (7ul << FMC_ISPCON_PT_Pos)              /*!< FMC ISPCON: PT Mask     */

#define FMC_ISPCON_ISPFF_Pos                    6                                       /*!< FMC ISPCON: ISPFF Position */
#define FMC_ISPCON_ISPFF_Msk                    (1ul << FMC_ISPCON_ISPFF_Pos)           /*!< FMC ISPCON: ISPFF Mask */

#define FMC_ISPCON_LDUEN_Pos                    5                                       /*!< FMC ISPCON: LDUEN Position */
#define FMC_ISPCON_LDUEN_Msk                    (1ul << FMC_ISPCON_LDUEN_Pos)           /*!< FMC ISPCON: LDUEN Mask */

#define FMC_ISPCON_CFGUEN_Pos                   4                                       /*!< FMC ISPCON: CFGUEN Position */
#define FMC_ISPCON_CFGUEN_Msk                   (1ul << FMC_ISPCON_CFGUEN_Pos)          /*!< FMC ISPCON: CFGUEN Mask */

#define FMC_ISPCON_APUEN_Pos                    3                                       /*!< FMC ISPCON: APUEN Position */
#define FMC_ISPCON_APUEN_Msk                    (1ul << FMC_ISPCON_APUEN_Pos)           /*!< FMC ISPCON: APUEN Mask */

#define FMC_ISPCON_BS_Pos                       1                                       /*!< FMC ISPCON: BS Position */
#define FMC_ISPCON_BS_Msk                       (0x1ul << FMC_ISPCON_BS_Pos)            /*!< FMC ISPCON: BS Mask */
                                                                                        
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

#define FMC_FATCON_FATS_Pos                     1                                       /*!< FMC FATCON: FATS Position */
#define FMC_FATCON_FATS_Msk                     (7ul << FMC_FATCON_FATS_Pos)            /*!< FMC FATCON: FATS Mask */

#define FMC_FATCON_FPSEN_Pos                    0                                       /*!< FMC FATCON: FPSEN Position */
#define FMC_FATCON_FPSEN_Msk                    (1ul << FMC_FATCON_FPSEN_Pos)           /*!< FMC FATCON: FPSEN Mask */


#define FMC_ISPSTA_ISPGO_Pos                    0                                       /*!< FMC ISPSTA: ISPGO Position */
#define FMC_ISPSTA_ISPGO_Msk                    (1ul << FMC_ISPSTA_ISPGO_Pos)           /*!< FMC ISPSTA: ISPGO Mask */

#define FMC_ISPSTA_CBS_Pos                      1                                       /*!< FMC ISPSTA: CBS Position */
#define FMC_ISPSTA_CBS_Msk                      (0x3ul << FMC_ISPSTA_CBS_Pos)           /*!< FMC ISPSTA: CBS Mask */

#define FMC_ISPSTA_ISPFF_Pos                    6                                       /*!< FMC ISPSTA: ISPFF Position */
#define FMC_ISPSTA_ISPFF_Msk                    (0x3ul << FMC_ISPSTA_ISPFF_Pos)         /*!< FMC ISPSTA: ISPFF Mask */

#define FMC_ISPSTA_VECMAP_Pos                   9                                       /*!< FMC ISPSTA: VECMAP Position */
#define FMC_ISPSTA_VECMAP_Msk                   (0xFFFul << FMC_ISPSTA_VECMAP_Pos)      /*!< FMC ISPSTA: VECMAP Mask */


/*@}*/ /* end of group NUC200_FMC */


/*------------------------------ PS2 Controller ------------------------------*/
/** @addtogroup NUC200_PS2 NUC200 PS2
  Memory Mapped Structure for NUC200 Series PS2 Serial Interface Controller
  @{
 */
typedef struct
{
    /**
     * PS2CON
     * ===================================================================================================
     * Offset: 0x00  PS2 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field        |Descriptions
     * | :----: | :----:      | :---- |
     * |[0]     |PS2EN        |Enable PS2 Device
		 * |        |             |Enable PS2 device controller.
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
     * |[9]     |OVERRIDE     |Software Override PS2 CLK/DATA Pin State
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
     * PS2TXDATA0
     * ===================================================================================================
     * Offset: 0x04  PS2 TX DATA Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |PS2TXDATAx|Transmit data
     * |        |          |Write data to this register starts device to host communication if bus is in IDLE state. S/W must 
     * |        |          |enable PS2EN before writing data to TX buffer.
     */ 						
		__IO uint32_t PS2TXDATA0;
		
    /**
     * PS2TXDATA1
     * ===================================================================================================
     * Offset: 0x08  PS2 TX DATA Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |PS2TXDATAx|Transmit data
     * |        |          |Write data to this register starts device to host communication if bus is in IDLE state. S/W must 
     * |        |          |enable PS2EN before writing data to TX buffer.
     */ 		
		__IO uint32_t PS2TXDATA1;
		
    /**
     * PS2TXDATA2
     * ===================================================================================================
     * Offset: 0x0C  PS2 TX DATA Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |PS2TXDATAx|Transmit data
     * |        |          |Write data to this register starts device to host communication if bus is in IDLE state. S/W must 
     * |        |          |enable PS2EN before writing data to TX buffer.
     */ 			
		__IO uint32_t PS2TXDATA2;
		
    /**
     * PS2TXDATA3
     * ===================================================================================================
     * Offset: 0x10  PS2 TX DATA Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |PS2TXDATAx|Transmit data
     * |        |          |Write data to this register starts device to host communication if bus is in IDLE state. S/W must 
     * |        |          |enable PS2EN before writing data to TX buffer.
     */ 		
		__IO uint32_t PS2TXDATA3;
		
    /**
     * PS2RXDATA
     * ===================================================================================================
     * Offset: 0x14  PS2 Receive Data Register
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
     * Offset: 0x18  PS2 Status Register 
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
     * |        |          |This bit indicates that the PS2 device is currently receiving data.
     * |        |          |1 = Currently receiving data.
     * |        |          |0 = Idle.
     * |        |          |Read only bit.
     * |[5]     |TXBUSY    |Transmit Busy
     * |        |          |This bit indicates that the PS2 device is currently sending data.
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
     * Offset: 0x1C  PS2 Interrupt Identification Register
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


/* PS2 PS2CON Bit Field Definitions */
#define PS2_PS2CON_PS2EN_Pos                       0										/*!< PS2 PS2CON: PS2EN Position */
#define PS2_PS2CON_PS2EN_Msk                       (1ul << PS2_PS2CON_PS2EN_Pos)  			/*!< PS2 PS2CON: PS2EN Mask */

#define PS2_PS2CON_TXINTEN_Pos                     1										/*!< PS2 PS2CON: TXINTEN Position */
#define PS2_PS2CON_TXINTEN_Msk                     (1ul << PS2_PS2CON_TXINTEN_Pos)		    /*!< PS2 PS2CON: TXINTEN Mask */ 

#define PS2_PS2CON_RXINTEN_Pos                     2										/*!< PS2 PS2CON: RXINTEN Position */
#define PS2_PS2CON_RXINTEN_Msk                     (1ul << PS2_PS2CON_RXINTEN_Pos)  	    /*!< PS2 PS2CON: RXINTEN Mask */

#define PS2_PS2CON_TXFIFO_DEPTH_Pos                3									    /*!< PS2 PS2CON: TXFIFO_DEPTH Position */
#define PS2_PS2CON_TXFIFO_DEPTH_Msk                (0xFul << PS2_PS2CON_TXFIFO_DEPTH_Pos)	/*!< PS2 PS2CON: TXFIFO_DEPTH Mask */

#define PS2_PS2CON_ACK_Pos                         7									    /*!< PS2 PS2CON: ACK Position */
#define PS2_PS2CON_ACK_Msk                         (1ul << PS2_PS2CON_ACK_Pos)				/*!< PS2 PS2CON: ACK Mask */ 

#define PS2_PS2CON_CLRFIFO_Pos                     8										/*!< PS2 PS2CON: CLRFIFO Position */
#define PS2_PS2CON_CLRFIFO_Msk                     (1ul << PS2_PS2CON_CLRFIFO_Pos)  		/*!< PS2 PS2CON: CLRFIFO Mask */

#define PS2_PS2CON_OVERRIDE_Pos                    9										/*!< PS2 PS2CON: OVERRIDE Position */
#define PS2_PS2CON_OVERRIDE_Msk                    (1ul << PS2_PS2CON_OVERRIDE_Pos)  		/*!< PS2 PS2CON: OVERRIDE Mask */

#define PS2_PS2CON_FPS2CLK_Pos                     10										/*!< PS2 PS2CON: FPS2CLK Position */
#define PS2_PS2CON_FPS2CLK_Msk                     (1ul << PS2_PS2CON_FPS2CLK_Pos) 			/*!< PS2 PS2CON: FPS2CLK Mask */

#define PS2_PS2CON_FPS2DAT_Pos                     11									    /*!< PS2 PS2CON: FPS2DAT Position */
#define PS2_PS2CON_FPS2DAT_Msk                     (1ul << PS2_PS2CON_FPS2DAT_Pos) 			/*!< PS2 PS2CON: FPS2DAT Mask */

/* PS/2 PS2RXDATA Bit Field Definitions */
#define PS2_PS2RXDATA_RXDATA_Pos                   0										/*!< PS2 PS2RXDATA: RXDATA Position */
#define PS2_PS2RXDATA_RXDATA_Msk                   (0xFFul << PS2_PS2RXDATA_RXDATA_Pos)		/*!< PS2 PS2RXDATA: RXDATA Mask */

/* PS/2 PS2STATUS Bit Field Definitions */
#define PS2_PS2STATUS_PS2CLK_Pos                   0									    /*!< PS2 PS2STATUS: PS2CLK Position */
#define PS2_PS2STATUS_PS2CLK_Msk                   (1ul << PS2_PS2STATUS_PS2CLK_Pos) 		/*!< PS2 PS2STATUS: PS2CLK Mask */

#define PS2_PS2STATUS_PS2DATA_Pos                  1										/*!< PS2 PS2STATUS: PS2DATA Position */
#define PS2_PS2STATUS_PS2DATA_Msk                  (1ul << PS2_PS2STATUS_PS2DATA_Pos) 		/*!< PS2 PS2STATUS: PS2DATA Mask */

#define PS2_PS2STATUS_FRAMERR_Pos                  2										/*!< PS2 PS2STATUS: FRAMERR Position */
#define PS2_PS2STATUS_FRAMERR_Msk                  (1ul << PS2_PS2STATUS_FRAMERR_Pos)		/*!< PS2 PS2STATUS: FRAMERR Mask */ 

#define PS2_PS2STATUS_RXPARITY_Pos                 3										/*!< PS2 PS2STATUS: RXPARITY Position */
#define PS2_PS2STATUS_RXPARITY_Msk                 (1ul << PS2_PS2STATUS_RXPARITY_Pos) 		/*!< PS2 PS2STATUS: RXPARITY Mask */

#define PS2_PS2STATUS_RXBUSY_Pos                   4										/*!< PS2 PS2STATUS: RXBUSY Position */
#define PS2_PS2STATUS_RXBUSY_Msk                   (1ul << PS2_PS2STATUS_RXBUSY_Pos)		/*!< PS2 PS2STATUS: RXBUSY Mask */

#define PS2_PS2STATUS_TXBUSY_Pos                   5										/*!< PS2 PS2STATUS: TXBUSY Position */
#define PS2_PS2STATUS_TXBUSY_Msk                   (1ul << PS2_PS2STATUS_TXBUSY_Pos)		/*!< PS2 PS2STATUS: TXBUSY Mask */

#define PS2_PS2STATUS_RXOVF_Pos                    6										/*!< PS2 PS2STATUS: RXOVF Position */
#define PS2_PS2STATUS_RXOVF_Msk                    (1ul << PS2_PS2STATUS_RXOVF_Pos)			/*!< PS2 PS2STATUS: RXOVF Mask */

#define PS2_PS2STATUS_TXEMPTY_Pos                  7										/*!< PS2 PS2STATUS: TXEMPTY Position */
#define PS2_PS2STATUS_TXEMPTY_Msk                  (1ul << PS2_PS2STATUS_TXEMPTY_Pos)		/*!< PS2 PS2STATUS: TXEMPTY Mask */

#define PS2_PS2STATUS_BYTEIDX_Pos                  8										/*!< PS2 PS2STATUS: BYTEIDX Position */
#define PS2_PS2STATUS_BYTEIDX_Msk                  (0xFul << PS2_PS2STATUS_BYTEIDX_Pos)		/*!< PS2 PS2STATUS: BYTEIDX Mask */

/* PS/2 PS2INTID Bit Field Definitions */
#define PS2_PS2INTID_RXINT_Pos                     0										/*!< PS2 PS2INTID : RXINT Position */
#define PS2_PS2INTID_RXINT_Msk                     (1ul << PS2_PS2INTID_RXINT_Pos) 			/*!< PS2 PS2INTID : RXINT Mask */
                     
#define PS2_PS2INTID_TXINT_Pos                     1										/*!< PS2 PS2INTID : TXINT Position */
#define PS2_PS2INTID_TXINT_Msk                     (1ul << PS2_PS2INTID_TXINT_Pos) 			/*!< PS2 PS2INTID : TXINT Mask */
/*@}*/ /* end of group NUC200_PS2 */

/*----------------------------- CAN Controller ------------------------------*/
/** @addtogroup NUC200_CAN NUC200 CAN
  Register Structure for NUC200 Series CAN Device Controller 
  @{
 */

typedef struct
{
    __IO uint32_t CREQ;
    __IO uint32_t CMASK;
    __IO uint32_t MASK1;
    __IO uint32_t MASK2;
    __IO uint32_t ARB1;
    __IO uint32_t ARB2;	
    __IO uint32_t MCON;			
    __IO uint32_t DAT_A1;			
    __IO uint32_t DAT_A2;		
    __IO uint32_t DAT_B1;
    __IO uint32_t DAT_B2;		
    __I uint32_t RESERVE0[13];        
                                    
} CAN_IF_T;

typedef struct
{
    __IO uint32_t   CON;		 	
    __IO uint32_t   STATUS;	
    __IO uint32_t   ERR;     		
    __IO uint32_t   BTIME;
    __IO uint32_t   IIDR;
    __IO uint32_t   TEST;
    __IO uint32_t   BRPE;
    __I uint32_t   	RESERVE0[1];     
    CAN_IF_T        IF[2];             
 	__I uint32_t   	RESERVE1[8];
    __IO uint32_t   TXREQ1;
    __IO uint32_t   TXREQ2;
    __I uint32_t   	RESERVE2[6];        
    __IO uint32_t   NDAT1;
    __IO uint32_t   NDAT2;
    __I uint32_t   	RESERVE3[6];
    __IO uint32_t   IPND1;
    __IO uint32_t   IPND2;
    __I uint32_t   	RESERVE4[6];
    __IO uint32_t   MVLD1;
    __IO uint32_t   MVLD2;
    __IO uint32_t   WU_EN;            
    __IO uint32_t   WU_STATUS;
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

#define CAN_IF_DAT_B2_DATA6_Pos    8                                    /*!< CAN IFnDATAB2: DATA6 Position */ 
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
/*@}*/ /* end of group NUC200_CAN */                                  

/*--------------------------- USB Device Controller --------------------------*/
/** @addtogroup NUC200_USBD NUC200 USBD
  Memory Mapped Structure for NUC200 Series USB Device Controller
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
#define USBD_INTSTS_EPEVT_Msk        (0x3Ful << USBD_INTSTS_EPEVT_Pos)   /*!< USB INTSTS: EPEVT Mask */

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

/*@}*/ /* end of group NUC200_USBD */


/*------------------------------ DMA Controller -----------------------------*/
/** @addtogroup NUC200_PWM NUC200 PWM
  Memory Mapped Structure for NUC200 Series DMA Controller 
  @{
 */
typedef struct
{
    __IO uint32_t CSR;
    __IO uint32_t SAR;
    __IO uint32_t DAR;
    __IO uint32_t BCR;
    __I  uint32_t POINT;
    __I  uint32_t CSAR;
    __I  uint32_t CDAR;
    __I  uint32_t CBCR;
    __IO uint32_t IER;
    __IO uint32_t ISR;
    __I  uint32_t RESERVE[22];
    __I  uint32_t SBUF;
} PDMA_T;

typedef struct
{
    __IO uint32_t GCRCSR;
    __IO uint32_t PDSSR0;
    __IO uint32_t PDSSR1;
    __IO uint32_t GCRISR;
    __IO uint32_t PDSSR2;
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

#define PDMA_GCRCSR_CLK8_EN_Pos                     16                                  /*!< PDMA GCRCSR: CLK8_EN Position */
#define PDMA_GCRCSR_CLK8_EN_Msk                     (1ul << PDMA_GCRCSR_CLK8_EN_Pos)    /*!< PDMA GCRCSR: CLK8_EN Mask */

#define PDMA_GCRCSR_CLK7_EN_Pos                     15                                  /*!< PDMA GCRCSR: CLK7_EN Position */
#define PDMA_GCRCSR_CLK7_EN_Msk                     (1ul << PDMA_GCRCSR_CLK7_EN_Pos)    /*!< PDMA GCRCSR: CLK7_EN Mask */

#define PDMA_GCRCSR_CLK6_EN_Pos                     14                                  /*!< PDMA GCRCSR: CLK6_EN Position */
#define PDMA_GCRCSR_CLK6_EN_Msk                     (1ul << PDMA_GCRCSR_CLK6_EN_Pos)    /*!< PDMA GCRCSR: CLK6_EN Mask */

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
#define PDMA_PDSSR0_SPI3_TXSEL_Pos                  28                                      /*!< PDMA PDSSR0: SPI3_TXSEL Position */
#define PDMA_PDSSR0_SPI3_TXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI3_TXSEL_Pos)   /*!< PDMA PDSSR0: SPI3_TXSEL Mask */

#define PDMA_PDSSR0_SPI3_RXSEL_Pos                  24                                      /*!< PDMA PDSSR0: SPI3_RXSEL Position */
#define PDMA_PDSSR0_SPI3_RXSEL_Msk                  (0xFul << PDMA_PDSSR0_SPI3_RXSEL_Pos)   /*!< PDMA PDSSR0: SPI3_RXSEL Mask */

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

#define PDMA_GCRISR_INTR8_Pos                       8                               /*!< PDMA GCRISR: INTR8 Position */
#define PDMA_GCRISR_INTR8_Msk                       (1ul << PDMA_GCRISR_INTR8_Pos)  /*!< PDMA GCRISR: INTR8 Mask */

#define PDMA_GCRISR_INTR7_Pos                       7                               /*!< PDMA GCRISR: INTR7 Position */
#define PDMA_GCRISR_INTR7_Msk                       (1ul << PDMA_GCRISR_INTR7_Pos)  /*!< PDMA GCRISR: INTR7 Mask */

#define PDMA_GCRISR_INTR6_Pos                       6                               /*!< PDMA GCRISR: INTR6 Position */
#define PDMA_GCRISR_INTR6_Msk                       (1ul << PDMA_GCRISR_INTR6_Pos)  /*!< PDMA GCRISR: INTR6 Mask */

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
#define PDMA_PDSSR2_I2S_TXSEL_Pos                   4                                       /*!< PDMA PDSSR2: I2S_TXSEL Position */
#define PDMA_PDSSR2_I2S_TXSEL_Msk                   (0xFul << PDMA_PDSSR2_I2S_TXSEL_Pos)    /*!< PDMA PDSSR2: I2S_TXSEL Mask */

#define PDMA_PDSSR2_I2S_RXSEL_Pos                   0                                       /*!< PDMA PDSSR2: I2S_RXSEL Position */
#define PDMA_PDSSR2_I2S_RXSEL_Msk                   (0xFul << PDMA_PDSSR2_I2S_RXSEL_Pos)    /*!< PDMA PDSSR2: I2S_RXSEL Mask */
/*@}*/ /* end of group NUC200_DMA */


/*----------------------------- Cyclic Redundancy Check (CRC) Controller -----------------------------*/
/** @addtogroup NUC200_CRC NUC200 CRC
  Memory Mapped Structure for NUC200 Series Cyclic Redundancy Check
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
/*@}*/ /* end of group NUC200_CRC */

/*----------------------------- PWM Controller -------------------------------*/

/** @addtogroup NUC200_PWM NUC200 PWM
  Memory Mapped Structure for NUC200 Series PWM Generator and Capture Timer
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
     * SYNCBUSY0
     * ===================================================================================================
     * Offset: 0x8C  PWM1 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY1;
    
    /**
     * SYNCBUSY0
     * ===================================================================================================
     * Offset: 0x90  PWM2 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY2;
    
    /**
     * SYNCBUSY0
     * ===================================================================================================
     * Offset: 0x94  PWM3 Synchronous Busy Status Register
     * ---------------------------------------------------------------------------------------------------
     */     
    __IO uint32_t  SYNCBUSY3;
                    
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
/*@}*/ /* end of group NUC200_PWM */


/*----------------------------- I2S Controller -------------------------------*/
/** @addtogroup NUC200_I2S NUC200 I2S
  Memory Mapped Structure for NUC200 Series I2S Interface Controller
  @{
 */
typedef struct
{
    __IO uint32_t CON;                /*!< Offset: 0x00  I2S Control Register               */
    __IO uint32_t CLKDIV;             /*!< Offset: 0x04  I2S Clock Divider Register         */
    __IO uint32_t IE;                 /*!< Offset: 0x08  I2S Interrupt Enable Register      */
    __I  uint32_t STATUS;             /*!< Offset: 0x0C  I2S Status Register                */
    __O  uint32_t TXFIFO;             /*!< Offset: 0x10  I2S Transmit FIFO Register         */
    __I  uint32_t RXFIFO;             /*!< Offset: 0x14  I2S Receive FIFO Register          */
} I2S_T;


/* I2S I2SCON Bit Field Definitions */
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

/*@}*/ /* end of group NUC200_I2S */



/*----------------------------- Smart Card Host Interface -------------------------------*/

/** @addtogroup NUC200_SMARTCARD NUC200 SMARTCARD
  Memory Mapped Structure for NUC200 Series Smart Card Host Interface
  @{
 */
typedef struct
{  
    union {
        __I  uint32_t  RBR;     /*!< Offset: 0x00  SC Receiving Buffer Register */
        __O  uint32_t  THR;     /*!< Offset: 0x00  SC Transmit Holding Register */
    };
  
    __IO uint32_t  CTL;         /*!< Offset: 0x04  SC Control Register */
    __IO uint32_t  ALTCTL;      /*!< Offset: 0x08  SC Alternate Control State Register */
    __IO uint32_t  EGTR;        /*!< Offset: 0x0C  SC Extend Guard Time Register */        
    __IO uint32_t  RFTMR;       /*!< Offset: 0x10  SC Receiver buffer Time Out Register */
    __IO uint32_t  ETUCR;       /*!< Offset: 0x14  SC ETU Control Register */
    __IO uint32_t  IER;         /*!< Offset: 0x18  SC Interrupt Enable Register */
    __IO uint32_t  ISR;         /*!< Offset: 0x1C  SC Interrupt Status Register (Read Only) */
    __IO uint32_t  TRSR;        /*!< Offset: 0x20  SC Transfer Status Register (Read Only) */
    __IO uint32_t  PINCSR;      /*!< Offset: 0x24  SC Pin Control State Register  */
    __IO uint32_t  TMR0;        /*!< Offset: 0x28  SC Internal Timer Control Register 0 */
    __IO uint32_t  TMR1;        /*!< Offset: 0x2C  SC Internal Timer Control Register 1 */
    __IO uint32_t  TMR2;        /*!< Offset: 0x30  SC Internal Timer Control Register 2 */
    uint32_t       RESERVE0[1]; /*!< Offset: 0x34  SC Reserve */
    __I  uint32_t  TDRA;        /*!< Offset: 0x38  SC Timer Current Data Register A */
    __I  uint32_t  TDRB;        /*!< Offset: 0x3C  SC Timer Current Data Register B */
} SC_T;

/* SC RBR Bit Field Definitions */
#define SC_RBR_RBR_Pos                      0                                /*!< SC RBR: RBR Position */
#define SC_RBR_RBR_Msk                      (0xFFul << SC_RBR_RBR_Pos)       /*!< SC RBR: RBR Mask */

/* SC THR Bit Field Definitions */
#define SC_THR_THR_Pos                      0                                /*!< SC THR: THR Position */
#define SC_THR_THR_Msk                      (0xFFul << SC_THR_THR_Pos)       /*!< SC THR: THR Mask */

/* SC CTL Bit Field Definitions */
#define SC_CTL_CD_DEB_SEL_Pos               24                               /*!< SC CTL: CD_DEB_SEL Position */
#define SC_CTL_CD_DEB_SEL_Msk               (3ul << SC_CTL_CD_DEB_SEL_Pos)   /*!< SC CTL: CD_DEB_SEL Mask */

#define SC_CTL_TX_ERETRY_EN_Pos             23                               /*!< SC CTL: TX_ERETRY_EN Position */
#define SC_CTL_TX_ERETRY_EN_Msk             (1ul << SC_CTL_TX_ERETRY_EN_Pos) /*!< SC CTL: TX_ERETRY_EN Mask */

#define SC_CTL_TX_ERETRY_Pos                20                               /*!< SC CTL: TX_ERETRY Position */
#define SC_CTL_TX_ERETRY_Msk                (7ul << SC_CTL_TX_ERETRY_Pos)    /*!< SC CTL: TX_ERETRY Mask */

#define SC_CTL_RX_ERETRY_EN_Pos             19                               /*!< SC CTL: RX_ERETRY_EN Position */
#define SC_CTL_RX_ERETRY_EN_Msk             (1ul << SC_CTL_RX_ERETRY_EN_Pos) /*!< SC CTL: RX_ERETRY_EN Mask */

#define SC_CTL_RX_ERETRY_Pos                16                               /*!< SC CTL: RX_ERETRY Position */
#define SC_CTL_RX_ERETRY_Msk                (7ul << SC_CTL_RX_ERETRY_Pos)    /*!< SC CTL: RX_ERETRY Mask */

#define SC_CTL_SLEN_Pos                     15                               /*!< SC CTL: SLEN Position */
#define SC_CTL_SLEN_Msk                     (1ul << SC_CTL_SLEN_Pos)         /*!< SC CTL: SLEN Mask */

#define SC_CTL_TMR_SEL_Pos                  13                               /*!< SC CTL: TMR_SEL Position */
#define SC_CTL_TMR_SEL_Msk                  (3ul << SC_CTL_TMR_SEL_Pos)      /*!< SC CTL: TMR_SEL Mask */

#define SC_CTL_BGT_Pos                      8                                /*!< SC CTL: BGT Position */
#define SC_CTL_BGT_Msk                      (0x1Ful << SC_CTL_BGT_Pos)       /*!< SC CTL: BGT Mask */

#define SC_CTL_RX_FTRI_LEV_Pos              6                                /*!< SC CTL: RX_FTRI_LEV Position */
#define SC_CTL_RX_FTRI_LEV_Msk              (3ul << SC_CTL_RX_FTRI_LEV_Pos)  /*!< SC CTL: RX_FTRI_LEV Mask */

#define SC_CTL_CON_SEL_Pos                  4                                /*!< SC CTL: CON_SEL Position */
#define SC_CTL_CON_SEL_Msk                  (3ul << SC_CTL_CON_SEL_Pos)      /*!< SC CTL: CON_SEL Mask */

#define SC_CTL_AUTO_CON_EN_Pos              3                                /*!< SC CTL: AUTO_CON_EN Position */
#define SC_CTL_AUTO_CON_EN_Msk              (1ul << SC_CTL_AUTO_CON_EN_Pos)  /*!< SC CTL: AUTO_CON_EN Mask */

#define SC_CTL_DIS_TX_Pos                   2                                /*!< SC CTL: DIS_TX Position */
#define SC_CTL_DIS_TX_Msk                   (1ul << SC_CTL_DIS_TX_Pos)       /*!< SC CTL: DIS_TX Mask */

#define SC_CTL_DIS_RX_Pos                   1                                /*!< SC CTL: DIS_RX Position */
#define SC_CTL_DIS_RX_Msk                   (1ul << SC_CTL_DIS_RX_Pos)       /*!< SC CTL: DIS_RX Mask */

#define SC_CTL_SC_CEN_Pos                   0                                /*!< SC CTL: SC_CEN Position */
#define SC_CTL_SC_CEN_Msk                   (1ul << SC_CTL_SC_CEN_Pos)       /*!< SC CTL: SC_CEN Mask */

/* SC ALTCTL Bit Field Definitions */
#define SC_ALTCTL_TMR2_ATV_Pos              15                               /*!< SC ALTCTL: TMR2_ATV Position */
#define SC_ALTCTL_TMR2_ATV_Msk              (1ul << SC_ALTCTL_TMR2_ATV_Pos)  /*!< SC ALTCTL: TMR2_ATV Mask */

#define SC_ALTCTL_TMR1_ATV_Pos              14                               /*!< SC ALTCTL: TMR1_ATV Position */
#define SC_ALTCTL_TMR1_ATV_Msk              (1ul << SC_ALTCTL_TMR1_ATV_Pos)  /*!< SC ALTCTL: TMR1_ATV Mask */

#define SC_ALTCTL_TMR0_ATV_Pos              13                               /*!< SC ALTCTL: TMR0_ATV Position */
#define SC_ALTCTL_TMR0_ATV_Msk              (1ul << SC_ALTCTL_TMR0_ATV_Pos)  /*!< SC ALTCTL: TMR0_ATV Mask */

#define SC_ALTCTL_RX_BGT_EN_Pos             12                               /*!< SC ALTCTL: RX_BGT_EN Position */
#define SC_ALTCTL_RX_BGT_EN_Msk             (1ul << SC_ALTCTL_RX_BGT_EN_Pos) /*!< SC ALTCTL: RX_BGT_EN Mask */

#define SC_ALTCTL_INIT_SEL_Pos              8                                /*!< SC ALTCTL: INIT_SEL Position */
#define SC_ALTCTL_INIT_SEL_Msk              (3ul << SC_ALTCTL_INIT_SEL_Pos)  /*!< SC ALTCTL: INIT_SEL Mask */

#define SC_ALTCTL_TMR2_SEN_Pos              7                                /*!< SC ALTCTL: TMR2_SEN Position */
#define SC_ALTCTL_TMR2_SEN_Msk              (1ul << SC_ALTCTL_TMR2_SEN_Pos)  /*!< SC ALTCTL: TMR2_SEN Mask */

#define SC_ALTCTL_TMR1_SEN_Pos              6                                /*!< SC ALTCTL: TMR1_SEN Position */
#define SC_ALTCTL_TMR1_SEN_Msk              (1ul << SC_ALTCTL_TMR1_SEN_Pos)  /*!< SC ALTCTL: TMR1_SEN Mask */

#define SC_ALTCTL_TMR0_SEN_Pos              5                                /*!< SC ALTCTL: TMR0_SEN Position */
#define SC_ALTCTL_TMR0_SEN_Msk              (1ul << SC_ALTCTL_TMR0_SEN_Pos)  /*!< SC ALTCTL: TMR0_SEN Mask */

#define SC_ALTCTL_WARST_EN_Pos              4                                /*!< SC ALTCTL: WARST_EN Position */
#define SC_ALTCTL_WARST_EN_Msk              (1ul << SC_ALTCTL_WARST_EN_Pos)  /*!< SC ALTCTL: WARST_EN Mask */

#define SC_ALTCTL_ACT_EN_Pos                3                                /*!< SC ALTCTL: ACT_EN Position */
#define SC_ALTCTL_ACT_EN_Msk                (1ul << SC_ALTCTL_ACT_EN_Pos)    /*!< SC ALTCTL: ACT_EN Mask */

#define SC_ALTCTL_DACT_EN_Pos               2                                /*!< SC ALTCTL: DACT_EN Position */
#define SC_ALTCTL_DACT_EN_Msk               (1ul << SC_ALTCTL_DACT_EN_Pos)   /*!< SC ALTCTL: DACT_EN Mask */

#define SC_ALTCTL_RX_RST_Pos                1                                /*!< SC ALTCTL: RX_RST Position */
#define SC_ALTCTL_RX_RST_Msk                (1ul << SC_ALTCTL_RX_RST_Pos)    /*!< SC ALTCTL: RX_RST Mask */

#define SC_ALTCTL_TX_RST_Pos                0                                /*!< SC ALTCTL: TX_RST Position */
#define SC_ALTCTL_TX_RST_Msk                (1ul << SC_ALTCTL_TX_RST_Pos)    /*!< SC ALTCTL: TX_RST Mask */

/* SC EGTR Bit Field Definitions */
#define SC_EGTR_EGT_Pos                     0                               /*!< SC EGTR: EGT Position */
#define SC_EGTR_EGT_Msk                     (0xFFul << SC_EGTR_EGT_Pos)     /*!< SC EGTR: EGT Mask */

/* SC RFTMR Bit Field Definitions */
#define SC_RFTMR_RFTM_Pos                   0                               /*!< SC RFTMR: RFTM Position */
#define SC_RFTMR_RFTM_Msk                   (0x1FFul << SC_RFTMR_RFTM_Pos)  /*!< SC RFTMR: RFTM Mask */

/* SC ETUCR Bit Field Definitions */
#define SC_ETUCR_COMPEN_EN_Pos              15                               /*!< SC ETUCR: COMPEN_EN Position */
#define SC_ETUCR_COMPEN_EN_Msk              (1ul << SC_ETUCR_COMPEN_EN_Pos)  /*!< SC ETUCR: COMPEN_EN Mask */

#define SC_ETUCR_ETU_RDIV_Pos               0                                   /*!< SC ETUCR: ETU_RDIV Position */
#define SC_ETUCR_ETU_RDIV_Msk               (0xFFFul << SC_ETUCR_ETU_RDIV_Pos)  /*!< SC ETUCR: ETU_RDIV Mask */

/* SC IER Bit Field Definitions */
#define SC_IER_ACON_ERR_IE_Pos              10                                  /*!< SC IER: ACON_ERR_IE Position */
#define SC_IER_ACON_ERR_IE_Msk              (1ul << SC_IER_ACON_ERR_IE_Pos)     /*!< SC IER: ACON_ERR_IE Mask */

#define SC_IER_RTMR_IE_Pos                  9                               /*!< SC IER: RTMR_IE Position */
#define SC_IER_RTMR_IE_Msk                  (1ul << SC_IER_RTMR_IE_Pos)     /*!< SC IER: RTMR_IE Mask */

#define SC_IER_INIT_IE_Pos                  8                               /*!< SC IER: INIT_IE Position */
#define SC_IER_INIT_IE_Msk                  (1ul << SC_IER_INIT_IE_Pos)     /*!< SC IER: INIT_IE Mask */

#define SC_IER_CD_IE_Pos                    7                               /*!< SC IER: CD_IE Position */
#define SC_IER_CD_IE_Msk                    (1ul << SC_IER_CD_IE_Pos)       /*!< SC IER: CD_IE Mask */

#define SC_IER_BGT_IE_Pos                   6                               /*!< SC IER: BGT_IE Position */
#define SC_IER_BGT_IE_Msk                   (1ul << SC_IER_BGT_IE_Pos)      /*!< SC IER: BGT_IE Mask */

#define SC_IER_TMR2_IE_Pos                  5                               /*!< SC IER: TMR2_IE Position */
#define SC_IER_TMR2_IE_Msk                  (1ul << SC_IER_TMR2_IE_Pos)     /*!< SC IER: TMR2_IE Mask */

#define SC_IER_TMR1_IE_Pos                  4                               /*!< SC IER: TMR1_IE Position */
#define SC_IER_TMR1_IE_Msk                  (1ul << SC_IER_TMR1_IE_Pos)     /*!< SC IER: TMR1_IE Mask */

#define SC_IER_TMR0_IE_Pos                  3                               /*!< SC IER: TMR0_IE Position */
#define SC_IER_TMR0_IE_Msk                  (1ul << SC_IER_TMR0_IE_Pos)     /*!< SC IER: TMR0_IE Mask */

#define SC_IER_TERR_IE_Pos                  2                               /*!< SC IER: TERR_IE Position */
#define SC_IER_TERR_IE_Msk                  (1ul << SC_IER_TERR_IE_Pos)     /*!< SC IER: TERR_IE Mask */

#define SC_IER_TBE_IE_Pos                   1                               /*!< SC IER: TBE_IE Position */
#define SC_IER_TBE_IE_Msk                   (1ul << SC_IER_TBE_IE_Pos)      /*!< SC IER: TBE_IE Mask */

#define SC_IER_RDA_IE_Pos                   0                               /*!< SC IER: RDA_IE Position */
#define SC_IER_RDA_IE_Msk                   (1ul << SC_IER_RDA_IE_Pos)      /*!< SC IER: RDA_IE Mask */

/* SC ISR Bit Field Definitions */
#define SC_ISR_ACON_ERR_IS_Pos              10                              /*!< SC ISR: ACON_ERR_IS Position */
#define SC_ISR_ACON_ERR_IS_Msk              (1ul << SC_ISR_ACON_ERR_IS_Pos) /*!< SC ISR: ACON_ERR_IS Mask */

#define SC_ISR_RTMR_IS_Pos                  9                               /*!< SC ISR: RTMR_IS Position */
#define SC_ISR_RTMR_IS_Msk                  (1ul << SC_ISR_RTMR_IS_Pos)     /*!< SC ISR: RTMR_IS Mask */

#define SC_ISR_INIT_IS_Pos                  8                               /*!< SC ISR: INIT_IS Position */
#define SC_ISR_INIT_IS_Msk                  (1ul << SC_ISR_INIT_IS_Pos)     /*!< SC ISR: INIT_IS Mask */

#define SC_ISR_CD_IS_Pos                    7                               /*!< SC ISR: CD_IS Position */
#define SC_ISR_CD_IS_Msk                    (1ul << SC_ISR_CD_IS_Pos)       /*!< SC ISR: CD_IS Mask */

#define SC_ISR_BGT_IS_Pos                   6                               /*!< SC ISR: BGT_IS Position */
#define SC_ISR_BGT_IS_Msk                   (1ul << SC_ISR_BGT_IS_Pos)      /*!< SC ISR: BGT_IS Mask */

#define SC_ISR_TMR2_IS_Pos                  5                               /*!< SC ISR: TMR2_IS Position */
#define SC_ISR_TMR2_IS_Msk                  (1ul << SC_ISR_TMR2_IS_Pos)     /*!< SC ISR: TMR2_IS Mask */

#define SC_ISR_TMR1_IS_Pos                  4                               /*!< SC ISR: TMR1_IS Position */
#define SC_ISR_TMR1_IS_Msk                  (1ul << SC_ISR_TMR1_IS_Pos)     /*!< SC ISR: TMR1_IS Mask */

#define SC_ISR_TMR0_IS_Pos                  3                               /*!< SC ISR: TMR0_IS Position */
#define SC_ISR_TMR0_IS_Msk                  (1ul << SC_ISR_TMR0_IS_Pos)     /*!< SC ISR: TMR0_IS Mask */

#define SC_ISR_TERR_IS_Pos                  2                               /*!< SC ISR: TERR_IS Position */
#define SC_ISR_TERR_IS_Msk                  (1ul << SC_ISR_TERR_IS_Pos)     /*!< SC ISR: TERR_IS Mask */

#define SC_ISR_TBE_IS_Pos                   1                               /*!< SC ISR: TXBE_IS Position */
#define SC_ISR_TBE_IS_Msk                   (1ul << SC_ISR_TBE_IS_Pos)      /*!< SC ISR: TXBE_IS Mask */

#define SC_ISR_RDA_IS_Pos                   0                               /*!< SC ISR: RDA_IS Position */
#define SC_ISR_RDA_IS_Msk                   (1ul << SC_ISR_RDA_IS_Pos)      /*!< SC ISR: RDA_IS Mask */


/* SC TRSR Bit Field Definitions */
#define SC_TRSR_TX_ATV_Pos                  31                              /*!< SC TRSR: TX_ATV Position */
#define SC_TRSR_TX_ATV_Msk                  (1ul << SC_TRSR_TX_ATV_Pos)     /*!< SC TRSR: TX_ATV Mask */

#define SC_TRSR_TX_OVER_REERR_Pos           30                                  /*!< SC TRSR: TX_OVER_REERR Position */
#define SC_TRSR_TX_OVER_REERR_Msk           (1ul << SC_TRSR_TX_OVER_REERR_Pos)  /*!< SC TRSR: TX_OVER_REERR Mask */

#define SC_TRSR_TX_REERR_Pos                29                               /*!< SC TRSR: TX_REERR Position */
#define SC_TRSR_TX_REERR_Msk                (1ul << SC_TRSR_TX_REERR_Pos)    /*!< SC TRSR: TX_REERR Mask */

#define SC_TRSR_TX_POINT_F_Pos              24                               /*!< SC TRSR: TX_POINT_F Position */
#define SC_TRSR_TX_POINT_F_Msk              (7ul << SC_TRSR_TX_POINT_F_Pos)  /*!< SC TRSR: TX_POINT_F Mask */

#define SC_TRSR_RX_ATV_Pos                  23                               /*!< SC TRSR: RX_ATV Position */
#define SC_TRSR_RX_ATV_Msk                  (1ul << SC_TRSR_RX_ATV_Pos)      /*!< SC TRSR: RX_ATV Mask */

#define SC_TRSR_RX_OVER_REERR_Pos           22                                  /*!< SC TRSR: RX_OVER_REERR Position */
#define SC_TRSR_RX_OVER_REERR_Msk           (1ul << SC_TRSR_RX_OVER_REERR_Pos)  /*!< SC TRSR: RX_OVER_REERR Mask */

#define SC_TRSR_RX_REERR_Pos                21                                  /*!< SC TRSR: RX_REERR Position */
#define SC_TRSR_RX_REERR_Msk                (1ul << SC_TRSR_RX_REERR_Pos)       /*!< SC TRSR: RX_REERR Mask */

#define SC_TRSR_RX_POINT_F_Pos              16                                  /*!< SC TRSR: RX_POINT_F Position */
#define SC_TRSR_RX_POINT_F_Msk              (7ul << SC_TRSR_RX_POINT_F_Pos)     /*!< SC TRSR: RX_POINT_F Mask */

#define SC_TRSR_TX_FULL_F_Pos               10                                  /*!< SC TRSR: TX_FULL_F Position */
#define SC_TRSR_TX_FULL_F_Msk               (1ul << SC_TRSR_TX_FULL_F_Pos)      /*!< SC TRSR: TX_FULL_F Mask */

#define SC_TRSR_TX_EMPTY_F_Pos              9                                   /*!< SC TRSR: TX_EMPTY_F Position */
#define SC_TRSR_TX_EMPTY_F_Msk              (1ul << SC_TRSR_TX_EMPTY_F_Pos)     /*!< SC TRSR: TX_EMPTY_F Mask */

#define SC_TRSR_TX_OVER_F_Pos               8                                   /*!< SC TRSR: TX_OVER_F Position */
#define SC_TRSR_TX_OVER_F_Msk               (1ul << SC_TRSR_TX_OVER_F_Pos)      /*!< SC TRSR: TX_OVER_F Mask */

#define SC_TRSR_RX_EBR_F_Pos                6                                   /*!< SC TRSR: RX_EBR_F Position */
#define SC_TRSR_RX_EBR_F_Msk                (1ul << SC_TRSR_RX_EBR_F_Pos)       /*!< SC TRSR: RX_EBR_F Mask */

#define SC_TRSR_RX_EFR_F_Pos                5                                   /*!< SC TRSR: RX_EFR_F Position */
#define SC_TRSR_RX_EFR_F_Msk                (1ul << SC_TRSR_RX_EFR_F_Pos)       /*!< SC TRSR: RX_EFR_F Mask */

#define SC_TRSR_RX_EPA_F_Pos                4                                   /*!< SC TRSR: RX_EPA_F Position */
#define SC_TRSR_RX_EPA_F_Msk                (1ul << SC_TRSR_RX_EPA_F_Pos)       /*!< SC TRSR: RX_EPA_F Mask */

#define SC_TRSR_RX_FULL_F_Pos               2                                   /*!< SC TRSR: RX_FULL_F Position */
#define SC_TRSR_RX_FULL_F_Msk               (1ul << SC_TRSR_RX_FULL_F_Pos)      /*!< SC TRSR: RX_FULL_F Mask */

#define SC_TRSR_RX_EMPTY_F_Pos              1                                   /*!< SC TRSR: RX_EMPTY_F Position */
#define SC_TRSR_RX_EMPTY_F_Msk              (1ul << SC_TRSR_RX_EMPTY_F_Pos)     /*!< SC TRSR: RX_EMPTY_F Mask */

#define SC_TRSR_RX_OVER_F_Pos               0                                   /*!< SC TRSR: RX_OVER_F Position */
#define SC_TRSR_RX_OVER_F_Msk               (1ul << SC_TRSR_RX_OVER_F_Pos)      /*!< SC TRSR: RX_OVER_F Mask */

/* SC PINCSR Bit Field Definitions */
#define SC_PINCSR_SC_DATA_I_ST_Pos          16                                  /*!< SC PINCSR: SC_DATA_I_ST Position */
#define SC_PINCSR_SC_DATA_I_ST_Msk          (1ul << SC_PINCSR_SC_DATA_I_ST_Pos) /*!< SC PINCSR: SC_DATA_I_ST Mask */

#define SC_PINCSR_POW_INV_Pos               11                                  /*!< SC PINCSR: POW_INV Position */
#define SC_PINCSR_POW_INV_Msk               (1ul << SC_PINCSR_POW_INV_Pos)      /*!< SC PINCSR: POW_INV Mask */

#define SC_PINCSR_CD_LEV_Pos                10                                  /*!< SC PINCSR: CD_LEV Position */
#define SC_PINCSR_CD_LEV_Msk                (1ul << SC_PINCSR_CD_LEV_Pos)       /*!< SC PINCSR: CD_LEV Mask */

#define SC_PINCSR_SC_DATA_O_Pos             9                                   /*!< SC PINCSR: SC_DATA_O Position */
#define SC_PINCSR_SC_DATA_O_Msk             (1ul << SC_PINCSR_SC_DATA_O_Pos)    /*!< SC PINCSR: SC_DATA_O Mask */

#define SC_PINCSR_SC_OEN_ST_Pos             8                                   /*!< SC PINCSR: SC_OEN_ST Position */
#define SC_PINCSR_SC_OEN_ST_Msk             (1ul << SC_PINCSR_SC_OEN_ST_Pos)    /*!< SC PINCSR: SC_OEN_ST Mask */

#define SC_PINCSR_ADAC_CD_EN_Pos            7                                   /*!< SC PINCSR: ADAC_CD_EN Position */
#define SC_PINCSR_ADAC_CD_EN_Msk            (1ul << SC_PINCSR_ADAC_CD_EN_Pos)   /*!< SC PINCSR: ADAC_CD_EN Mask */

#define SC_PINCSR_CLK_KEEP_Pos              6                                   /*!< SC PINCSR: CLK_KEEP Position */
#define SC_PINCSR_CLK_KEEP_Msk              (1ul << SC_PINCSR_CLK_KEEP_Pos)     /*!< SC PINCSR: CLK_KEEP Mask */

#define SC_PINCSR_CLK_STOP_LEV_Pos          5                                   /*!< SC PINCSR: CLK_STOP_LEV Position */
#define SC_PINCSR_CLK_STOP_LEV_Msk          (1ul << SC_PINCSR_CLK_STOP_LEV_Pos) /*!< SC PINCSR: CLK_STOP_LEV Mask */

#define SC_PINCSR_CD_PIN_ST_Pos             4                                   /*!< SC PINCSR: CD_PIN_ST Position */
#define SC_PINCSR_CD_PIN_ST_Msk             (1ul << SC_PINCSR_CD_PIN_ST_Pos)    /*!< SC PINCSR: CD_PIN_ST Mask */

#define SC_PINCSR_CD_INS_F_Pos              3                                   /*!< SC PINCSR: CD_INS_F Position */
#define SC_PINCSR_CD_INS_F_Msk              (1ul << SC_PINCSR_CD_INS_F_Pos)     /*!< SC PINCSR: CD_INS_F Mask */

#define SC_PINCSR_CD_REM_F_Pos              2                                   /*!< SC PINCSR: CD_REM_F Position */
#define SC_PINCSR_CD_REM_F_Msk              (1ul << SC_PINCSR_CD_REM_F_Pos)     /*!< SC PINCSR: CD_REM_F Mask */

#define SC_PINCSR_SC_RST_Pos                1                                   /*!< SC PINCSR: SC_RST Position */
#define SC_PINCSR_SC_RST_Msk                (1ul << SC_PINCSR_SC_RST_Pos)       /*!< SC PINCSR: SC_RST Mask */

#define SC_PINCSR_POW_EN_Pos                0                                   /*!< SC PINCSR: POW_EN Position */
#define SC_PINCSR_POW_EN_Msk                (1ul << SC_PINCSR_POW_EN_Pos)       /*!< SC PINCSR: POW_EN Mask */

/* SC TMR0 Bit Field Definitions */
#define SC_TMR0_MODE_Pos                    24                              /*!< SC TMR0: MODE Position */
#define SC_TMR0_MODE_Msk                    (0xFul << SC_TMR0_MODE_Pos)     /*!< SC TMR0: MODE Mask */

#define SC_TMR0_CNT_Pos                     0                               /*!< SC TMR0: CNT Position */
#define SC_TMR0_CNT_Msk                     (0xFFFFFFul << SC_TMR0_CNT_Pos) /*!< SC TMR0: CNT Mask */

/* SC TMR1 Bit Field Definitions */
#define SC_TMR1_MODE_Pos                    24                              /*!< SC TMR1: MODE Position */
#define SC_TMR1_MODE_Msk                    (0xFul << SC_TMR1_MODE_Pos)     /*!< SC TMR1: MODE Mask */

#define SC_TMR1_CNT_Pos                     0                               /*!< SC TMR1: CNT Position */
#define SC_TMR1_CNT_Msk                     (0xFFul << SC_TMR1_CNT_Pos)     /*!< SC TMR1: CNT Mask */

/* SC TMR2 Bit Field Definitions */
#define SC_TMR2_MODE_Pos                    24                              /*!< SC TMR2: MODE Position */
#define SC_TMR2_MODE_Msk                    (0xFul << SC_TMR2_MODE_Pos)     /*!< SC TMR2: MODE Mask */

#define SC_TMR2_CNT_Pos                     0                               /*!< SC TMR2: CNT Position */
#define SC_TMR2_CNT_Msk                     (0xFFul << SC_TMR2_CNT_Pos)     /*!< SC TMR2: CNT Mask */

/* SC TDRA Bit Field Definitions */
#define SC_TDRA_TDR0_Pos                    0                                   /*!< SC TDRA: TDR0 Position */
#define SC_TDRA_TDR0_Msk                    (0xFFFFFFul << SC_TDRA_TDR0_Pos)    /*!< SC TDRA: TDR0 Mask */

/* SC TDRB Bit Field Definitions */
#define SC_TDRB_TDR2_Pos                    8                               /*!< SC TDRB: TDR2 Position */
#define SC_TDRB_TDR2_Msk                    (0xFFul << SC_TDRB_TDR2_Pos)    /*!< SC TDRB: TDR2 Mask */

#define SC_TDRB_TDR1_Pos                    0                               /*!< SC TDRB: TDR1 Position */
#define SC_TDRB_TDR1_Msk                    (0xFFul << SC_TDRB_TDR1_Pos)    /*!< SC TDRB: TDR1 Mask */


/*@}*/ /* end of group NUC200_SMARTCARD */
/*@}*/ /* end of group NUC200 */


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup NUC200_PERIPHERAL_MEM_MAP NUC200 Peripheral Memory Map
  Memory Mapped Structure for NUC200 Series Peripheral
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
#define PE_BASE             (GPIO_BASE       + 0x0100)                   /*!< GPIO PORTE Base Address                             */
#define PF_BASE             (GPIO_BASE       + 0x0140)                   /*!< GPIO PORTF Base Address                             */
#define GPIO_DBNCECON_BASE  (GPIO_BASE       + 0x0180)                   /*!< GPIO De-bounce Cycle Control Base Address           */
#define GPIO_PIN_DATA_BASE  (GPIO_BASE       + 0x0200)                   /*!< GPIO Pin Data Input/Output Control Base Address     */


#define UART0_BASE           (APB1_BASE      + 0x50000)
#define UART1_BASE           (APB2_BASE      + 0x50000)
#define UART2_BASE           (APB2_BASE      + 0x54000)


#define TIMER0_BASE          (APB1_BASE      + 0x10000)                 /*!< Timer0 Base Address                              */
#define TIMER1_BASE          (APB1_BASE      + 0x10020)                 /*!< Timer1 Base Address                              */
#define TIMER2_BASE          (APB2_BASE      + 0x10000)                 /*!< Timer2 Base Address                              */
#define TIMER3_BASE          (APB2_BASE      + 0x10020)                 /*!< Timer3 Base Address                              */

#define WDT_BASE             (APB1_BASE      + 0x4000)                  /*!< Watchdog Timer Base Address                      */

#define WWDT_BASE            (APB1_BASE      + 0x4100)                  /*!< Window Watchdog Timer Base Address               */

#define SPI0_BASE            (APB1_BASE      + 0x30000)
#define SPI1_BASE            (APB1_BASE      + 0x34000)
#define SPI2_BASE            (APB2_BASE      + 0x30000)
#define SPI3_BASE            (APB2_BASE      + 0x34000)

#define I2C0_BASE            (APB1_BASE      + 0x20000)                 /*!< I2C0 Base Address                                */
#define I2C1_BASE            (APB2_BASE      + 0x20000)                 /*!< I2C1 Base Address                                */

#define RTC_BASE             (APB1_BASE      + 0x08000)                 /*!< RTC Base Address                                 */

#define ADC_BASE             (APB1_BASE      + 0xE0000)

#define ACMP_BASE            (APB1_BASE      + 0xD0000)   

#define SYSCLK_BASE          (AHB_BASE       + 0x00200)                 /*!< System Clock Controller Base Address             */

#define GCR_BASE             (AHB_BASE       + 0x00000)                 /*!< System Global Controller Base Address            */

#define INT_BASE             (AHB_BASE       + 0x00300)                 /*!< Interrupt Source Controller Base Address         */

#define FMC_BASE             (AHB_BASE       + 0x0C000)

#define PS2_BASE             (APB2_BASE      + 0x00000)					/*!< PS/2 Base Address                                 */

#define CAN0_BASE            (APB2_BASE      + 0x80000)
#define CAN1_BASE            (APB2_BASE      + 0x84000)
#define C_CAN_BASE           (APB2_BASE      + 0x88000)

#define USBD_BASE            (APB1_BASE      + 0x60000)

#define PDMA0_BASE           (AHB_BASE       + 0x08000)                 /*!< PDMA0 Base Address                               */
#define PDMA1_BASE           (AHB_BASE       + 0x08100)                 /*!< PDMA1 Base Address                               */
#define PDMA2_BASE           (AHB_BASE       + 0x08200)                 /*!< PDMA2 Base Address                               */
#define PDMA3_BASE           (AHB_BASE       + 0x08300)                 /*!< PDMA3 Base Address                               */
#define PDMA4_BASE           (AHB_BASE       + 0x08400)                 /*!< PDMA4 Base Address                               */
#define PDMA5_BASE           (AHB_BASE       + 0x08500)                 /*!< PDMA5 Base Address                               */
#define PDMA6_BASE           (AHB_BASE       + 0x08600)                 /*!< PDMA6 Base Address                               */
#define PDMA7_BASE           (AHB_BASE       + 0x08700)                 /*!< PDMA7 Base Address                               */
#define PDMA8_BASE           (AHB_BASE       + 0x08800)                 /*!< PDMA8 Base Address                               */

#define PDMA_GCR_BASE        (AHB_BASE       + 0x08F00)                 /*!< PDMA Grobal Base Address                               */

#define CRC_BASE             (AHB_BASE       + 0x08E00)                 /*!< CRC Base Address                                 */

#define PWMA_BASE            (APB1_BASE      + 0x40000)                 /*!< PWMA Base Address                                */
#define PWMB_BASE            (APB2_BASE      + 0x40000)                 /*!< PWMB Base Address                                */

#define SC0_BASE             (APB2_BASE      + 0x90000)                 /*!< SC0 Base Address                                */
#define SC1_BASE             (APB2_BASE      + 0x94000)                 /*!< SC1 Base Address                               */
#define SC2_BASE             (APB2_BASE      + 0x98000)                 /*!< SC2 Base Address                               */

#define I2S_BASE             (APB2_BASE      + 0xA0000)

/*@}*/ /* end of group NUC200_PERIPHERAL_MEM_MAP */

/******************************************************************************/
/*                         Peripheral Definitions                             */
/******************************************************************************/

/** @addtogroup NUC200_PERIPHERAL NUC200 Peripheral Definitions
  The Definitions of NUC200 Series Peripheral
  @{
 */
#define PA                  ((GPIO_T *) PA_BASE)                        /*!< GPIO PORTA Configuration Struct                        */
#define PB                  ((GPIO_T *) PB_BASE)                        /*!< GPIO PORTB Configuration Struct                        */
#define PC                  ((GPIO_T *) PC_BASE)                        /*!< GPIO PORTC Configuration Struct                        */
#define PD                  ((GPIO_T *) PD_BASE)                        /*!< GPIO PORTD Configuration Struct                        */
#define PE                  ((GPIO_T *) PE_BASE)                        /*!< GPIO PORTE Configuration Struct                        */
#define PF                  ((GPIO_T *) PF_BASE)                        /*!< GPIO PORTF Configuration Struct                        */
#define GPIO                ((GPIO_DBNCECON_T *) GPIO_DBNCECON_BASE)    /*!< Interrupt De-bounce Cycle Control Configuration Struct */ 

#define UART0               ((UART_T *) UART0_BASE)
#define UART1               ((UART_T *) UART1_BASE)
#define UART2               ((UART_T *) UART2_BASE)

#define TIMER0              ((TIMER_T *) TIMER0_BASE)                   /*!< Timer0 Configuration Struct                      */
#define TIMER1              ((TIMER_T *) TIMER1_BASE)                   /*!< Timer1 Configuration Struct                      */
#define TIMER2              ((TIMER_T *) TIMER2_BASE)                   /*!< Timer2 Configuration Struct                      */
#define TIMER3              ((TIMER_T *) TIMER3_BASE)                   /*!< Timer3 Configuration Struct                      */

#define WDT                 ((WDT_T *) WDT_BASE)                        /*!< Watchdog Timer Configuration Struct              */

#define WWDT                ((WWDT_T *) WWDT_BASE)                      /*!< Window Watchdog Timer Configuration Struct       */

#define SPI0                ((SPI_T *) SPI0_BASE)
#define SPI1                ((SPI_T *) SPI1_BASE)
#define SPI2                ((SPI_T *) SPI2_BASE)
#define SPI3                ((SPI_T *) SPI3_BASE)

#define I2C0                ((I2C_T *) I2C0_BASE)                       /*!< I2C0 Configuration Struct                        */
#define I2C1                ((I2C_T *) I2C1_BASE)                       /*!< I2C1 Configuration Struct                        */

#define I2S                 ((I2S_T *) I2S_BASE)

#define RTC                 ((RTC_T *) RTC_BASE)                        /*!< RTC Configuration Struct                         */

#define ADC                 ((ADC_T *) ADC_BASE)

#define ACMP                ((ACMP_T *) ACMP_BASE)

#define SYSCLK              ((SYSCLK_T *) SYSCLK_BASE)                  /*!< System Clock Controller Configuration Struct     */

#define SYS                 ((GCR_T *) GCR_BASE)                        /*!< System Global Controller Configuration Struct    */

#define SYSINT              ((GCR_INT_T *) INT_BASE)                    /*!< Interrupt Source Controller Configuration Struct */

#define FMC                 ((FMC_T *) FMC_BASE)

#define PS2                 ((PS2_T *) PS2_BASE)						/*!< PS/2 Configuration Struct                        */

#define CAN                 ((CAN_T *) CAN0_BASE)
#define CAN0                ((CAN_T *) CAN0_BASE)
#define CAN1                ((CAN_T *) CAN1_BASE)

#define USBD                ((USBD_T *) USBD_BASE)

#define PDMA0               ((PDMA_T *) PDMA0_BASE)                     /*!< PDMA0 Configuration Struct                       */
#define PDMA1               ((PDMA_T *) PDMA1_BASE)                     /*!< PDMA1 Configuration Struct                       */
#define PDMA2               ((PDMA_T *) PDMA2_BASE)                     /*!< PDMA2 Configuration Struct                       */
#define PDMA3               ((PDMA_T *) PDMA3_BASE)                     /*!< PDMA3 Configuration Struct                       */
#define PDMA4               ((PDMA_T *) PDMA4_BASE)                     /*!< PDMA4 Configuration Struct                       */
#define PDMA5               ((PDMA_T *) PDMA5_BASE)                     /*!< PDMA5 Configuration Struct                       */
#define PDMA6               ((PDMA_T *) PDMA6_BASE)                     /*!< PDMA6 Configuration Struct                       */
#define PDMA7               ((PDMA_T *) PDMA7_BASE)                     /*!< PDMA7 Configuration Struct                       */
#define PDMA8               ((PDMA_T *) PDMA8_BASE)                     /*!< PDMA8 Configuration Struct                       */

#define PDMA_GCR            ((PDMA_GCR_T *) PDMA_GCR_BASE)              /*!< PDMA Global Configuration Struct                 */

#define CRC                 ((CRC_T *) CRC_BASE)                        /*!< CRC Configuration Struct                         */

#define PWMA                ((PWM_T *) PWMA_BASE)                       /*!< PWMA Configuration Struct                        */
#define PWMB                ((PWM_T *) PWMB_BASE)                       /*!< PWMB Configuration Struct                        */

#define SC0                 ((SC_T *) SC0_BASE)                         /*!< SC0 Configuration Struct                        */
#define SC1                 ((SC_T *) SC1_BASE)                         /*!< SC1 Configuration Struct                        */
#define SC2                 ((SC_T *) SC2_BASE)                         /*!< SC2 Configuration Struct                        */

/*@}*/ /* end of group NUC200_PERIPHERAL */

#define UNLOCKREG(x)        do{*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x59;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x16;*((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x88}while(*((__IO uint32_t *)(GCR_BASE + 0x100))==0)
#define LOCKREG(x)          *((__IO uint32_t *)(GCR_BASE + 0x100)) = 0x00;     

#define REGCOPY(dest, src)  *((uint32_t *)&(dest)) = *((uint32_t *)&(src))
#define CLEAR(dest)         *((uint32_t *)&(dest)) = 0

//=============================================================================
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


#define E_SUCCESS   0
#ifndef NULL
#define NULL        0
#endif

#define TRUE        1
#define FALSE       0

#define ENABLE     1
#define DISABLE    0

/* Define one bit mask */
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


/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/ 

#endif
                                                                                                 
