
/**************************************************************************//**
 * @file     pac5xxx_UART.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX UART Controller
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

/*------------- UART Controller (UART) ----------------------*/
/** @addtogroup PAC5XXX_UART PAC5XXX UART Controller (UART)
  @{
*/

/** UART Interrupt ID Enumeration Type */
typedef enum {
    UARTIIR_IID_MODEM_STATUS =      0,     /*!< UART Interrupt ID: Modem Status                                 */
    UARTIIR_IID_TX_HOLD_EMPTY =     1,     /*!< UART Interrupt ID: Transmit Hold Register Empty                 */
    UARTIIR_IID_RX_DATA_AVAIL =     2,     /*!< UART Interrupt ID: Receive Data Available                       */
    UARTIIR_IID_RX_LINE_STATUS =    3,     /*!< UART Interrupt ID: Receive Line Status                          */
    UARTIIR_IID_TIMEOUT =           6      /*!< UART Interrupt ID: Timeout                                      */
} UART_IID_Type;

/** UART FIFO Depth Enumeration Type */
typedef enum {
	UARTFCTL_RT_1B =                0,      /*!< UART FIFO Control: 1 byte in FIFO                               */
	UARTFCTL_RT_4B =                1,      /*!< UART FIFO Control: 4 bytes in FIFO                              */
	UARTFCTL_RT_8B =                2,      /*!< UART FIFO Control: 8 bytes in FIFO                              */
	UARTFCTL_RT_14B =               3       /*!< UART FIFO Control: 14B bytes in FIFO                            */
} UART_FIFO_Depth_Type;

/** UART Bits per Character Enumeration Type */
typedef enum {
	UART_BPC_5 = 0,							/*!< 5 bits per character                                            */
	UART_BPC_6 = 1,                         /*!< 6 bits per character                                            */
	UART_BPC_7 = 2,                         /*!< 7 bits per character                                            */
	UART_BPC_8 = 3                          /*!< 8 bits per character                                            */
} UART_BitsPerChar_Type;

/** UART Stop Bits Enumeration Type */
typedef enum {
    UART_STOP_BITS_1 = 0,                   /*!< 1 stop bit                                                      */
	UART_STOP_BITS_2 = 1                    /*!< 2 stops bits (1.5 if WLS = 00b)                                 */
} UART_StopBits_Type;

/** UART Parity Select Enumeration Type */
typedef enum {
    UART_PARITY_ODD = 0,                    /*!< Generate ODD parity                                             */
	UART_PARITY_EVEN = 1                    /*!< Generate EVEN parity                                            */
} UART_Parity_Type;

/** UART Break Control Enumeration Type */
typedef enum {
    UART_BRKCTL_NORMAL = 0,                 /*!< Normal TX Operation                                             */
	UART_BRKCTL_FORCE_0 = 1                 /*!< Force serial_out to 0                                           */
} UART_BreakControl_Type;

/** UART Divisor Latch Access Enumeration Type */
typedef enum {
    UART_DIVLACCESS_FIFO_IER = 0,           /*!< Access FIFO, IER                                                */
	UART_DIVLACCESS_DIV_LATCH = 1           /*!< Access divisor latch                                            */
} UART_DivLatchAccess_Type;

typedef struct
{
  /*!< RXTX: Offset: 0x0000   Receive/Transmit FIFO Register (LCR.DLAB = 0)	                                     */
  /*!< DL_L: Offset: 0x0000   Divisor Latch, LO byte Register (LCR.DLAB = 1)                                     */
  union { 
    union {
      __IO uint32_t w;
      struct {
        __IO uint32_t s                : 16;
	           uint32_t                  : 16;
      };
      struct {
	    __IO uint32_t b                  : 8;
	         uint32_t                    : 24;
      };
      struct {	
	    __IO uint32_t VAL                : 8;    /*!< Rx/Tx Data value                                              */
		     uint32_t                    : 24;
      };
    } RXTX;
    union {
      __IO uint32_t w;
      struct {
        __IO uint32_t s                : 16;
	           uint32_t                  : 16;
      };
      struct {
        __IO uint32_t b                : 8;
	           uint32_t                  : 24;
      };
      struct {	
        __IO uint32_t VAL              : 8;    /*!< Divisor latch, LO byte                                        */
		         uint32_t                  : 24;
      };
    } DL_L;
  };

  /*!< IER:  Offset: 0x0004   Interrupt Enable Register (LCR.DLAB = 0)	                                          */
  /*!< DL_H: Offset: 0x0004   Divisor Latch, LO byte Register (LCR.DLAB = 1)	                                  */
  union { 
    union {
	  __IO uint32_t w;
      struct {
	    __IO uint32_t s                  : 16;
	         uint32_t                    : 16;
      };
      struct {
	    __IO uint32_t b                  : 8;
	         uint32_t                    : 24;
      };
      struct {	
  	    __IO uint32_t RDAI             : 1;    /*!< RX Data Available Interrupt                              */
  	    __IO uint32_t THREI            : 1;    /*!< TX Holding Register Empty Interrupt                      */
        __IO uint32_t MSI              : 1;    /*!< Modem Status Interrupt                                   */
        __IO uint32_t RLSI             : 1;    /*!< Receive Line Status Interrupt                            */
  		       uint32_t                  : 28;
      };
    } IER;
    union {
      __IO uint32_t w;
      struct {
        __IO uint32_t s                : 16;
	           uint32_t                  : 16;
      };
      struct {
        __IO uint32_t b                : 8;
	           uint32_t                  : 24;
      };
      struct {	
        __IO uint32_t VAL              : 8;    /*!< Divisor latch, HI byte                                   */
             uint32_t                  : 24;
      };
    } DL_H;
  };
 
  /*!< IIR:  Offset: 0x0008   Interrupt ID Register (READ-ONLY)                                              */
  /*!< FCTL: Offset: 0x0008   FIFO Control Register (WRITE-ONLY)                                             */
  union { 
    union {
	  __I  uint32_t w;
      struct {
	    __I  uint32_t s                  : 16;
	         uint32_t                    : 16;
      };
      struct {
	    __I  uint32_t b                  : 8;
	         uint32_t                    : 24;
      };
      struct {	
        __I  uint32_t PI                 : 1;   /*!< Pending Interrupt                         */
        __I  uint32_t IID                : 3;   /*!< Interrupt ID                              */
	           uint32_t                  : 2;
	      __I  uint32_t TXFEN            : 1;   /*!< Transmit FIFO enable indicator            */
        __I  uint32_t RXFEN              : 1;   /*!< Receive FIFO enable indicator             */
             uint32_t                    : 24;
      };
    } IIR;
    union {
      __O uint32_t w;
     struct {
       __O uint32_t s                 : 16;
	           uint32_t                  : 16;
      };
      struct {
        __O uint32_t b                : 8;
	           uint32_t                  : 24;
      };
      struct {	
	      __O  uint32_t EN               : 1;   /*!< FIFO Enable                                                   */		
	      __O  uint32_t RR               : 1;   /*!< Receive FIFO Reset (WTC)                                      */
	      __O  uint32_t TR               : 1;   /*!< Transmit FIFO Reset (WTC)                                     */
		         uint32_t                  : 2;
        __O  uint32_t RT               : 2;   /*!< Receive FIFO Threshold                                        */
		         uint32_t                  : 24;
      };
    } FCTL;
  };
  
  /*!< Offset: 0x000C   Line Control Register (LCR)                   */
  union {
    __IO uint32_t w;
    struct {
		   uint32_t                        : 16;
	  __IO uint32_t s                    : 16;
    };
    struct {
		   uint32_t                        : 24;
	  __IO uint32_t b                    : 8;
    };
    struct {
      __IO uint32_t BPC                : 2;  /*!< Bits per Character                                             */
      __IO uint32_t STB                : 1;  /*!< Stop Bits                                                      */
      __IO uint32_t PEN                : 1;  /*!< Parity Enable                                                  */
      __IO uint32_t EPS                : 1;  /*!< Even Parity Select                                             */
      __IO uint32_t SP                 : 1;  /*!< Stick Parity                                                   */
      __IO uint32_t SB                 : 1;  /*!< Break Control                                                  */
      __IO uint32_t DLAB               : 1;  /*!< Divisor Latch Access                                           */
	       uint32_t                      : 24;
    };
  } LCR;
   
   /*!< Offset: 0x0010   Modem Control Register (MCR)                  */
   union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                  : 16;
           uint32_t                    : 16;
    };
    struct {
      __IO uint32_t b                  : 8;
           uint32_t                    : 24;
    };
    struct {
      __IO uint32_t DTR                : 1;  /*!< Data Ready asserted                                           */
      __IO uint32_t RTS                : 1;  /*!< Ready to Send asserted                                        */
      __IO uint32_t BIT1               : 1;  /*!< BIT_OUT1_N asserted                                           */
      __IO uint32_t BIT2               : 1;  /*!< BIT_OUT2_N asserted                                           */
      __IO uint32_t LP                 : 1;  /*!< Loopback                                                      */
	         uint32_t                    : 27;
    };
  } MCR;
  
  /*!< Offset: 0x0014   Line Status Register (LSR)                    */
  union {
    __I  uint32_t w;
    struct {
      __I  uint32_t s                  : 16;
		       uint32_t                    : 16;
    };
    struct {
      __I  uint32_t b                  : 8;
		       uint32_t                    : 24;
    };
	  struct {
      __I  uint32_t DR                 : 1;  /*!< Data Ready                                                     */
      __I  uint32_t OE                 : 1;  /*!< Overrun Error                                                  */
      __I  uint32_t PE                 : 1;  /*!< Parity Error                                                   */
      __I  uint32_t FE                 : 1;  /*!< Framing Error                                                  */
      __I  uint32_t BI                 : 1;  /*!< Break Indicator                                                */
      __I  uint32_t THR                : 1;  /*!< Transmit FIFO Empty                                            */
      __I  uint32_t TE                 : 1;  /*!< Transmit Empty                                                 */
      __I  uint32_t RFE                : 1;  /*!< Receive FIFO Error                                             */
	         uint32_t                    : 24;
    };
  } LSR;

  /*!< Offset: 0x0018   Modem Status Register (MSR)                                                                */
  union {
    __I  uint32_t w;
    struct {
      __I  uint32_t s                  : 16;
		       uint32_t                    : 16;
    };
    struct {
      __I  uint32_t b                  : 8;
		       uint32_t                    : 24;
    };
	  struct {
      __I  uint32_t DCTS               : 1;  /*!< Delta CTS Detect                                               */
      __I  uint32_t DDSR               : 1;  /*!< Delta DSR Detect                                               */
      __I  uint32_t TERI               : 1;  /*!< Trailing Edge RI Detect                                        */
      __I  uint32_t DDCD               : 1;  /*!< Delta DCD detect                                               */
      __I  uint32_t CTS                : 1;  /*!< Clear to Send                                                  */
      __I  uint32_t DSR                : 1;  /*!< Data Set Ready                                                 */
      __I  uint32_t RI                 : 1;  /*!< Ring Indicator                                                 */
      __I  uint32_t DCD                : 1;  /*!< Data Carrier Detect                                            */
           uint32_t                    : 24;
    };
  } MSR;

  /*!< SP: Offset: 0x001C   Scratchpad Register (remapped)                                                         */
  struct {
    __IO uint32_t VAL                  : 8;  /*!< Scratch pad value                                              */
         uint32_t                      : 24;
  } SP;

  /*!< FCTL2: OFfset: 0x0020 FIFO Control Register (remapped)                                                      */
  union {
    __IO uint32_t w;
    struct {
	  __IO uint32_t s                    : 16;
	  	   uint32_t                      : 16;
    };
    struct {
	  __IO uint32_t b                    : 8;
		   uint32_t                        : 24;
    };
    struct {	
      __IO uint32_t EN                 : 1;   /*!< FIFO Enable                                                   */		
      __O  uint32_t RR                 : 1;   /*!< Receive FIFO Reset (WTC)                                      */
      __O  uint32_t TR                 : 1;   /*!< Transmit FIFO Reset (WTC)                                     */
	         uint32_t                    : 2;
      __IO uint32_t RT                 : 2;   /*!< Receive FIFO Threshold                                        */
	         uint32_t                    : 24;
    };
  } FCTL2;

  /*!< IER2: Offset: 0x0024   Interrupt Enable Register (remapped)                                               */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                  : 16;
	    	   uint32_t                    : 16;
    };
    struct {
      __IO uint32_t b                  : 8;
		       uint32_t                    : 24;
    };
    struct {	
      __IO uint32_t RDAI               : 1;   /*!< Receive Data Available Interrupt                               */
      __IO uint32_t THREI              : 1;   /*!< Transmit Holding Register Empty Interrupt                      */
      __IO uint32_t RLSI               : 1;   /*!< Receive Line Status Interrupt                                  */
      __IO uint32_t MSI                : 1;   /*!< Modem Status Interrupt                                         */
		       uint32_t                    : 28;
    };
  } IER2;

  /*!< DL_L2: Offset: 0x0028   Divisor Latch LO byte Register (remapped)     */
  struct {
    __IO uint32_t VAL                  : 8;  /*!< Divisor Latch, LO byte                                         */
         uint32_t                      : 24;
  } DL_L2;
  
  /*!< DL_H2: Offset: 0x002C   Divisor Latch HI byte Register (remapped)     */
  struct {
    __IO uint32_t VAL                  : 8;  /*!< Divisor Latch, HI byte                                         */
         uint32_t                      : 24;
  } DL_H2;

  uint32_t RESERVED[2];
  
  /*!< FD_F: Offset: 0x0038   Fractional Divisor/Value Register                                                    */
  struct {
	__IO uint32_t VAL                    : 8;  /*!< Fractional Portion of Divisor Value                            */
         uint32_t                      : 24;
  } FD_F;

  uint32_t RESERVED2;

  /*!< STAT: Offset: 0x0040   Supplemental Status Register                                                         */
  union {
    struct {
      __IO uint32_t b                  : 8;
		       uint32_t                    : 24;
    };
    struct {
      __I  uint32_t TXEMPTY              : 1;  /*!< Transmit FIFO Empty                                            */
      __I  uint32_t TXFULL               : 1;  /*!< Transmit FIFO Full                                             */
      __I  uint32_t RXEMPTY              : 1;  /*!< Receive FIFO Empty                                             */
      __I  uint32_t RXFULL               : 1;  /*!< Receive FIFO Full                                              */
           uint32_t                      : 28;
    };
  } STAT;
  
  
} PAC5XXX_UART_TypeDef;

/*@}*/ /* end of group PAC5XXX_UART */

