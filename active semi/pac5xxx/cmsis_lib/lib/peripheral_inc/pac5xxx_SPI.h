
/**************************************************************************//**
 * @file     pac5xxx_SPI.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX SPI Controller
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


/*------------- SPI Controller (SPI) ----------------------*/
/** @addtogroup PAC5XXX_SPI PAC5XXX SPI Controller (SPI)
  @{
*/

/** SPI Data Phase Enumeration Type */
typedef enum {
	SPISCFG_TDAT_PH_NORMAL = 0, 	           /*!< Normal transmit data phase, transitions are on edge of SCLK    */
	SPISCFG_TDAT_PH_HALF = 1                   /*!< Transitions occur 1/2 period sooner than normal                */
} SPICFG_EarlyXmitDataPhase_Type;

/** SPI Clock Polarity Enumeration Type */
typedef enum {
    SPISCFG_SCLK_ACTHIGH = 0,                  /*!< Clock polarity is active high                       */
	  SPISCFG_SCLK_ACTLOW = 1                    /*!< Clock polarity is active low                        */
} SPISCFG_ClockPolarity_Type;

/** SPI Clock Phase Config Enumeration Type */
typedef enum {
    SPISCFG_SMP_SETUP = 0,                     /*!< First clock transition is used to sample data                  */
    SPISCFG_SETUP_SMP = 1                      /*!< Second clock transition is used to sample data                 */
} SPISCFG_ClockPhase_Type;

/** SPI Word Length Enumeration Type */
typedef enum {
    SPISCFG_WL_8B  = 0,                        /*!< Word Length Select: 8b                                         */
    SPISCFG_WL_16B = 1,                        /*!< Word Length Select: 16b                                        */
    SPISCFG_WL_24B = 2,                        /*!< Word Length Select: 24b                                        */
    SPISCFG_WL_32B = 3                         /*!< Word Length Select: 32b                                        */
} SPISCFG_WordLength_Type;

/** SPI Status State Enumeration Type */
typedef enum {
    SPISTAT_CURSTATE_IDLE = 0,                 /*!< SPI State: Idle                                                */
    SPISTAT_CURSTATE_CSSETUP = 1,              /*!< SPI State: Chip Select Setup                                   */
    SPISTAT_CURSTATE_TRANSFER = 2,             /*!< SPI State: Transfer Data                                       */
    SPISTAT_CURSTATE_CSHOLD = 3,               /*!< SPI State: Chip Select Hold                                    */
    SPISTAT_CURSTATE_CSWAIT = 4,               /*!< SPI State: Chip Select Wait                                    */
    SPISTAT_CURSTATE_CKWAIT = 5,               /*!< SPI State: Clock Wait                                          */
    SPISTAT_CURSTATE_MTRANS = 6,               /*!< SPI State: Master Transfer                                     */
    SPISTAT_CURSTATE_CSBEGIN = 7               /*!< SPI State: Chip Select begin                                   */
} SPISTAT_State_Type;

/** Chip Select Polarity Enumeration Type */
typedef enum {
	SPICS_CS_ACTLOW = 0,                       /*!< Chip Select polarity active low                                */
	SPICS_CS_ACTHIGH = 1                       /*!< Chip Select polarity active high                               */
} SPICS_ChipSelectPolarity_Type;

/** Chip Select Number Enumeration Type */
typedef enum {
  SPICS_SELECT_CS0,                          /*!< Chip Select slave SPIxCS0                                      */
	SPICS_SELECT_CS1,                          /*!< Chip Select slave SPIxCS1                                      */
	SPICS_SELECT_CS2,                          /*!< Chip Select slave SPIxCS2                                      */
	SPICS_SELECT_CS3                           /*!< Chip Select slave SPIxCS3                                      */
} SPICS_ChipSelectNumber_Type;

typedef struct
{
  /*!< SPICTL: Offset: 0x0000   SPI Control Register                                                             */
  union {
     __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b               : 8;
           uint32_t                 : 24;
    };
    struct {
      __IO uint32_t SSEN            : 1;    /*!< SPI System Enable                                                 */
      __IO uint32_t SIE             : 1;    /*!< SPI Interrupt Enable                                              */
      __IO uint32_t LPBK            : 1;    /*!< Internal Loopback Mode                                            */
      __IO uint32_t SE              : 1;    /*!< Slave enable                                                      */
           uint32_t                 : 1;    /*!< Must write as 0                                                   */
      __IO uint32_t MTRARM          : 1;    /*!< MTRANS re-arm                                                     */
      __IO uint32_t MTRANS          : 1;    /*!< Multiple-transfer mode                                            */
      __IO uint32_t MMST_N          : 1;    /*!< Multi-master mode                                                 */
      __IO uint32_t RTRANS          : 1;    /*!< Auto-retransmit on SCLK error                                     */
           uint32_t                 : 23;
	  };
  } SPICTL;

  /*!< SPICFG: Offset: 0x0004   SPI Configuration Register                                                       */
  union {
     __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b               : 8;
           uint32_t                 : 24;
    };
    struct {
      __IO uint32_t WL              : 2;    /*!< Word Length Select                                                */
      __IO uint32_t MRST            : 1;    /*!< Module Reset                                                      */
      __IO uint32_t LB1ST           : 1;    /*!< LSB First                                                         */
      __IO uint32_t CP              : 1;    /*!< Master Mode Clock Polarity                                        */
      __IO uint32_t CPH             : 1;    /*!< Master Mode Clock Phase                                           */
      __IO uint32_t RCVCP           : 1;    /*!< Slave Mode Clock Polarity                                         */
      __IO uint32_t RCVCPH          : 1;    /*!< Slave Mode Clock Phase                                            */
           uint32_t                 : 1;    /*!< Must write as 0                                                   */
      __IO uint32_t TDAT_PH         : 1;    /*!< Early Transmit Data Phase                                         */
      __IO uint32_t TXDBUF          : 1;    /*!< Transmit data double-buffer                                       */
      __IO uint32_t MTURBO          : 1;    /*!< Master turbo mode (2x/clk)                                        */
           uint32_t                 : 20;
    };
  }	SPICFG;

  /*!< SPICLKDIV: Offset: 0x0008   SPI Input Clock Divisor Register                                               */
  struct {
    __IO uint32_t VAL               : 16;   /*!< Clock divisor for master-mode SPIxSCLK                            */
         uint32_t                   : 16;
  } SPICLKDIV;

  uint32_t RESERVED10[2];

  /*!< SPISTAT: Offset: 0x0014   SPI Status Register                                                             */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
	       uint32_t                 : 16;
    };
    struct {
      __IO uint32_t b               : 8;
	       uint32_t                 : 24;
    };
    struct {
      __I  uint32_t SPI_INT         : 1;      /*!< SPI Interrupt                                                     */
	       uint32_t                 : 1;
      __IO uint32_t RDOFL           : 1;      /*!< Read Buffer Overflow                                              */
      __IO uint32_t LE              : 1;      /*!< Chip Select Leading  Edge Detect                                  */
      __IO uint32_t UCLK            : 1;      /*!< Under-clock condition                                             */
      __IO uint32_t CYC_DONE        : 1;      /*!< Cycle Done                                                        */
      __IO uint32_t TE              : 1;      /*!< Chip Select Trailing Edge Detect                                  */
           uint32_t                 : 1;
      __IO uint32_t WRUFL           : 1;      /*!< Write Buffer underflow                                            */
      __I  uint32_t TXFULL          : 1;      /*!< Raw indicator that the transmit outgoing register is still in use */
      __I  uint32_t RXFULL          : 1;      /*!< Raw indicator that the receiving incoming holding reg is full     */
           uint32_t                 : 1;
      __I  uint32_t CURSTATE        : 2;      /*!< Raw Status of the SPI Master State Machine's "current_state" reg  */
      uint32_t                      : 18;
    };
  } SPISTAT;
  
  /*!< SPICSSTR: Offset: 0x0018   SPI CS Steering Register                                                          */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
	       uint32_t                 : 16;
    };
    struct {
      __IO uint32_t b               : 8;
	       uint32_t                 : 24;
    };
    struct {
      __IO uint32_t CSNUM           : 2;      /*!< Chip Select Number                                                */
      __IO uint32_t CSL             : 1;      /*!< Chip Select Active Level Select                                   */
	       uint32_t               : 5;
      __IO uint32_t CSSETUP         : 4;      /*!< Chip Select Setup                                                 */
      __IO uint32_t CSHOLD          : 4;      /*!< Chip Select Hold                                                  */
      __IO uint32_t CSWAIT          : 4;      /*!< Chip Select Wait                                                  */
      __IO uint32_t CKWAIT          : 4;      /*!< SPI Clock Wait                                                    */		   
           uint32_t                 : 8;
	  };
  } SPICCSTR;
  
  /*!< SPID: Offset: 0x001C   SPI Data Register                                                                    */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
      __IO uint32_t b               : 8;
	       uint32_t                 : 24;
    };
  } SPID;

  /*!< SPIINT_EN: Offset: 0x0020   SPI Interrupt Enable Register                                                    */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 : 16;
	       uint32_t                     : 16;
    };
    struct {
      __IO uint32_t b                 : 8;
	       uint32_t                     : 24;
    };
	  struct {
           uint32_t                   : 2;	
      __IO uint32_t RDOFL_EN          : 1;     /*!< Enable SPIxSTAT:FDOFL Interrupt                                   */
      __IO uint32_t LE_EN             : 1;     /*!< Enable SPIxSTAT:LE Interrupt                                      */
      __IO uint32_t UCLK_EN           : 1;     /*!< Enable SPIxSTAT:UCLK Interrupt                                    */
      __IO uint32_t CYC_DONE_EN       : 1;     /*!< Enable SPIxSTAT:CYC_DONE Interrupt                                */
      __IO uint32_t TE_EN             : 1;     /*!< Enable SPIxSTAT:TE Interrupt                                      */
           uint32_t                   : 1;
      __IO uint32_t WRUFL_EN          : 1;     /*!< Enable SPIxSTAT:WRUFL Interrupt                                   */
	       uint32_t                   : 23;
    };		   
  } SPIINT_EN;
  
} PAC5XXX_SPI_TypeDef;
/*@}*/ /* end of group PAC5XXX_SPI */
