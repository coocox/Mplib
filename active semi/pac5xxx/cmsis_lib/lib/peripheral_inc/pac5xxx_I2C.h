
/**************************************************************************//**
 * @file     pac5xxx_I2C.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX I2C Controller
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

/*------------- I2C Controller (I2C) ----------------------*/
/** @addtogroup PAC5XXX_I2C PAC5XXX I2C Controller (I2C)
  @{
*/

/** I2C Address Mode Enumeration Type */
typedef enum {
	I2CCTL_ADDR_MODE_7B = 0,               /*!< I2C Address Mode: 7b                                           */
	I2CCTL_ADDR_MODE_10B = 1               /*!< I2C Address Mode: 10b                                          */
} I2C_AddrMode_Type;

/** I2C Transfer Type Enumeration Type */
typedef enum {
	I2CMCTRL_XFER_TYPE_WRITE = 0,          /*!< I2C Transfer Type: I2C Write                                   */
	I2CMCTRL_XFER_TYPE_READ = 1            /*!< I2C Transfer Type: I2C Read                                    */
} I2C_TransferType_Type;

typedef struct
{
  /*!< I2CCFG: Offset: 0x0000   I2C Configuration Register                    */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 	: 16;
           uint32_t                   	: 16;
    };
    struct {
	  __IO uint32_t b                   : 8;
           uint32_t                     : 24;
    };
	struct {
    	__IO uint32_t SLV_ENBL          : 1;     /*!< I2C Slave Mode Enabled                                         */
	         uint32_t                   : 1;     /*!< Reserved: Write as 0 for proper operation                      */
	    __IO uint32_t MST_ENBL          : 1;     /*!< I2C Master Mode Enabled                                        */
	         uint32_t                   : 1;     /*!< Reserved: Write as 0 for proper operation                      */
	    __IO uint32_t ADDR_MODE         : 1;     /*!< I2C Address Mode (7b or 10b)                                   */
	    __IO uint32_t DSBL_PULSE_FILTER : 1;     /*!< Disable Pulse Filter                                           */
           uint32_t                   : 26;
	  };
  } CFG;
  
  /*!< I2CSTATUS: Offset: 0x0004   I2C Status Register                           */
  union
  {
    __I  uint32_t w;
    struct {
           uint32_t                   	: 16;
      __I  uint32_t s                 	: 16;
    };
    struct {
	  __I  uint32_t b                   : 8;
         uint32_t                     	: 24;
    };
  	struct {
	    __I  uint32_t MST_TX_EMPTIED    : 1;     /*!< I2C Master Data Transmitted to I2C Bus                         */
	    __I  uint32_t MST_ACC_CTL_EMP   : 1;     /*!< I2C_MCTRL sent to I2C Bus                                      */
	    __I  uint32_t MST_RX_FILLED     : 1;     /*!< I2C Master Data Received from I2C Bus                          */
	         uint32_t                   : 5;
	    __I  uint32_t MST_XFER_DONE     : 1;     /*!< I2C Master Transfer Completed                                  */
	    __I  uint32_t MST_A_NACK_ACK    : 1;     /*!< I2C Master Address Acknowledged                                */
	    __I  uint32_t MST_LOST_ARB      : 1;     /*!< I2C Master Lost Arbitration                                    */
	    __I  uint32_t MST_D_NACK_ACK    : 1;     /*!< I2C Master Data Acknowledged                                   */
	         uint32_t                   : 4;      
	    __I  uint32_t SLV_ADDR_MATCH    : 1;     /*!< I2C Slave Address Match                                        */
	    __I  uint32_t SLV_TX_EMPTIED    : 1;     /*!< I2C Slave Data Transmitted to I2C Bus                          */
	    __I  uint32_t SLV_RX_FILLED     : 1;     /*!< I2C Slave Data Received from I2C Bus                           */
	         uint32_t                   : 5;
	    __I  uint32_t SLV_XFER_DONE     : 1;     /*!< I2C Slave Transfer Complete                                    */
           uint32_t                   	: 7;
	  };
  } STATUS;
  
  /*!< I2CIE: Offset: 0x0008   I2C Interrupt Enable Register                 */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 	: 16;
           uint32_t         			: 16;
    };
    struct {
	  __IO uint32_t b                 	: 8;
           uint32_t           			: 24;
    };
	  struct {
  	  __IO uint32_t MST_TX_EMP_IE       : 1;     /*!< Master Transmit Data Register Interrupt Enable                 */
  	  __IO uint32_t MST_ACC_CTL_EMP_IE  : 1;     /*!< Master Control Register Emptied Interrupt Enable               */
      __IO uint32_t MST_RX_FILLED_IE    : 1;     /*!< Master Received Data From I2C Bus Interrupt Enable             */
	       uint32_t                     : 5;
      __IO uint32_t MST_XFER_DONE_IE    : 1;     /*!< Master Transfer Complete Interrupt Enable                      */
           uint32_t                     : 7;
  	  __IO uint32_t SLV_ADDR_MATCH_IE   : 1;     /*!< Slave Address Match Interrupt Enable                           */
  	  __IO uint32_t SLV_TX_EMP_IE       : 1;     /*!< Slave Transmit Data Register Interrupt Enable                  */
	  __IO uint32_t SLV_RX_FILLED_IE    : 1;     /*!< Slave Recieve Data Interrupt Enable                            */
	       uint32_t                     : 5;
	  __IO uint32_t SLV_XFER_DONE_IE    : 1;     /*!< Slave Transfer Complete Interrupt Enable                       */
	       uint32_t                     : 7;
  	};
  } IE;

       uint32_t RESERVED17[9];

  /*!< I2CMCTRL: Offset: 0x0030   I2C Master Control Register                   */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 : 16;
           uint32_t                   : 16;
    };
    struct {
    __IO uint32_t b                   : 8;
         uint32_t                     : 24;
	};
    struct {
    	__IO uint32_t LOWER_I2C_ADDR    : 7;     /*!< Lower 7b of 7b/10b I2C Address                                 */
    	__IO uint32_t UPPER_I2C_ADDR    : 3;     /*!< Upper 3b of 10b I2C Address                                    */
    	__IO uint32_t AUTONO_XFER       : 1;     /*!< Issue I2C Stop at the end of the current transfer              */
    	__IO uint32_t XFER_TYPE         : 1;     /*!< I2C Transaction Type (Write/Read)                              */
    	     uint32_t                   : 1;
    	__I  uint32_t REG_FULL_FLAG     : 1;     /*!< MCTRL Register Full                                            */
    	     uint32_t                   : 18;
    };
  } MCTRL;
 
  /*!< I2CMRXDATA: Offset: 0x0034   I2C Master Receive Data Register              */
  union
  {
    __IO uint32_t w;
    struct {
           uint32_t                   : 16;
      __IO uint32_t s                 : 16;
    };
    struct {
         uint32_t                     : 24;
	  __IO uint32_t b                 : 8;
    };
	struct {
           uint32_t                   : 22;
      __IO uint32_t REG_FULL_FLAG     : 1;     /*!< I2CMRXDATA Register Filled                                     */
      __IO uint32_t VAL               : 8;     /*!< Master data byte received from I2C Controller                  */
    };
  } MRXDATA; 	
 
  /*!< I2CMTXDATA: Offset: 0x0038   I2C Master Transmit Data Register              */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 : 16;
           uint32_t                   : 16;
    };
    struct {
	    __IO uint32_t b               : 8;
             uint32_t                 : 24;
    };
	  struct {
	    __IO uint32_t VAL             : 8;    /*!< Master data byte to transfer to I2C Controller                 */
	    __I  uint32_t REG_FULL_FLAG   : 1;    /*!< I2CMTXDATA Register Full                                       */
	    __I  uint32_t LAST_BYTE_FLAG  : 1;    /*!< Last byte of transfer (Read or Write)                          */
             uint32_t                 : 22;
	  };
  } MTXDATA;
  
  uint32_t RESERVED28;

  /*!< I2CBAUD: Offset: 0x0040   I2C Master Baud Rate Configuration Register   */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 : 16;
           uint32_t                   : 16;
    };
    struct {
	  __IO uint32_t b                   : 8;
         uint32_t                     : 24;
    };
	  struct {
      __IO uint32_t SCL_LOW_CLOCKS    : 11;    /*!< Number of input clock periods (SCLK) for low clock time        */
           uint32_t                   : 5;
	    __IO uint32_t SCL_HIGH_CLOCKS   : 11;    /*!< Number of input clock periods (SCLK) for high clock time       */
	         uint32_t                   : 5;
    };
  } BAUD;

  uint32_t RESERVED33[11];

  /*!< I2CSRXDATA: Offset: 0x0070   I2C Slave Receive Data Register               */
  union
  {
    __I  uint32_t w;
    struct {
      __I  uint32_t s                 : 16;
           uint32_t                   : 16;
    };
    struct {
	  __I  uint32_t b                   : 8;
         uint32_t                     : 24;
    };
	  struct {
	    __I  uint32_t VAL               : 8;     /*!< Slave data byte received from I2C Write operation              */
	    __I  uint32_t REG_FULL_FLAG     : 1;     /*!< I2CSRXDATA Register Full Flag                                  */
	         uint32_t                   : 23;
	  };
  } SRXDATA;

  /*!< I2CSTXDATA: Offset: 0x0074   I2C Slave Transmit Data Register               */
  union
  {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b                 : 8;
         uint32_t                   : 24;
    };
	  struct {
	    __IO uint32_t VAL             : 8;     /*!< Slave data byte received from I2C Write operation              */
	    __IO uint32_t NACK            : 1;     /*!< Issue NACK on I2C Write                                        */
	    __I  uint32_t REG_FULL_FLAG   : 1;     /*!< I2CSRXDATA Register Full Flag                                  */
	         uint32_t                 : 22;
	  };
  } STXDATA;

  /*!< I2CSADDR: Offset: 0x0078   I2C Slave Address Register                    */
  union
  {
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
	    __IO uint32_t SADDR_LSB       : 7;     /*!< 7b LSB of 7b/10b slave address                                  */
	    __IO uint32_t SADDR_MSB       : 3;     /*!< 3b MSB of 10-bit slave address                                  */
           uint32_t                 : 22;
	  };
  } SADDR;
  
} PAC5XXX_I2C_TypeDef;

/*@}*/ /* end of group PAC5XXX_I2C */
