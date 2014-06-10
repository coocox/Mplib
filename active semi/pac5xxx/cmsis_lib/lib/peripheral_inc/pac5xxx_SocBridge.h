
/**************************************************************************//**
 * @file     pac5xxx_SocBridge.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX SOC Bridge
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


/*------------- SOC Bridge (SocBridge) ----------------------*/
/** @addtogroup PAC5XXX_SocBridge PAC5XXX SOC Bridge
  @{
*/

/** SPI Status State Enumeration Type */
typedef enum {
	SOCBSTAT_CURSTATE_IDLE = 0,                 /*!< SOC Bridge State: Idle                                                */
	SOCBSTAT_CURSTATE_CSSETUP = 1,              /*!< SOC Bridge State: Chip Select Setup                                   */
	SOCBSTAT_CURSTATE_TRANSFER = 2,             /*!< SOC Bridge State: Transfer Data                                       */
	SOCBSTAT_CURSTATE_CSHOLD = 3,               /*!< SOC Bridge State: Chip Select Hold                                    */
	SOCBSTAT_CURSTATE_CSWAIT = 4,               /*!< SOC Bridge State: Chip Select Wait                                    */
	SOCBSTAT_CURSTATE_CKWAIT = 5,               /*!< SOC Bridge State: Clock Wait                                          */
	SOCBSTAT_CURSTATE_MTRANS = 6,               /*!< SOC Bridge State: Master Transfer                                     */
    SOCBSTAT_CURSTATE_CSBEGIN = 7               /*!< SOC Bridge State: Chip Select begin                                   */
} SocBridge_State_Type;

typedef struct
{
  /*!< SOCBCTL: Offset: 0x0000   SOC bus bridge control register                                                   */
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
      __IO uint32_t SSEN            : 1;    /*!< SocBridge Enable                                                  */
      __IO uint32_t SIE             : 1;    /*!< SocBridge Interrupt Enable                                        */
           uint32_t                 : 4;
      __IO uint32_t SETTO3          : 2;    /*!< Must write to 3 (11b)                                             */
           uint32_t                 : 24;
	  };
  } SOCBCTL;

  /*!< SOCBCFG: Offset: 0x0004   SOC bus bridge configuration register                                             */
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
           uint32_t                 : 2;    /*!< Must write as 0                                                   */
      __IO uint32_t MRST            : 1;    /*!< Module Reset                                                      */
           uint32_t                 : 6;
      __IO uint32_t SETTO0          : 1;    /*!< Must write as 0                                                   */
      __IO uint32_t SETTO3          : 2;    /*!< Must write as 3 (11b)                                             */
           uint32_t                 : 20;   /*!< Must write as 0                                                   */
    };
  }	SOCBCFG;

  /*!< SOCBCLKDIV: Offset: 0x0008   SOC bus bridge Input Clock Divisor Register                                       */
  struct {
    __IO uint32_t VAL               : 16;   /*!< Input clock divisor                                               */
         uint32_t                   : 16;
  } SOCBCLKDIV;

  uint32_t RESERVED10[2];

  /*!< SOCBSTAT: Offset: 0x0014   SOC bus bridge status register                                                   */
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
      __I  uint32_t SOCB_INT        : 1;      /*!< SOC Bus Bridge Interrupt                                          */
	       uint32_t                 : 1;
      __IO uint32_t RDOFL           : 1;      /*!< Read Buffer Overflow                                              */
           uint32_t                 : 1;
           uint32_t                 : 1;
      __IO uint32_t CYC_DONE        : 1;      /*!< Cycle Done                                                        */
           uint32_t                 : 2;
      __IO uint32_t WRUFL           : 1;      /*!< Write Buffer underflow                                            */
      __I  uint32_t TXFULL          : 1;      /*!< Raw indicator that the transmit outgoing register is still in use */
      __I  uint32_t RXFULL          : 1;      /*!< Raw indicator that the receiving incoming holding reg is full     */
           uint32_t                 : 1;
      __I  uint32_t CURSTATE        : 2;      /*!< Current state of the SOC Bus Bridge state machine                 */
      uint32_t                      : 18;
    };
  } SOCBSTAT;
  
  /*!< SOCBCSSTR: Offset: 0x0018   SOC Bus Bridge Steering Register                                                  */
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
           uint32_t                 : 8;
      __IO uint32_t CSSETUP         : 4;      /*!< Chip Select Setup                                                 */
      __IO uint32_t CSHOLD          : 4;      /*!< Chip Select Hold                                                  */
      __IO uint32_t CSWAIT          : 4;      /*!< Chip Select Wait                                                  */
      __IO uint32_t CKWAIT          : 4;      /*!< SOC Bus Bridge Clock Wait                                         */
           uint32_t                 : 8;
	  };
  } SOCBCSSTR;
  
  /*!< SOCBD: Offset: 0x001C   SOC Bus Bridge Data Register                                                          */
  struct {
	  __IO uint32_t DATA            : 8;
           uint32_t                 : 24;
  } SOCBD;

  /*!< SOCBINT_EN: Offset: 0x0020   SOC Bus Bridge Interrupt Enable Register                                           */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s                 : 16;
	       uint32_t                   : 16;
    };
    struct {
      __IO uint32_t b                 : 8;
	       uint32_t                   : 24;
    };
	struct {
           uint32_t                   : 2;	
      __IO uint32_t RDOFL_EN          : 1;     /*!< Enable FDOFL Interrupt                                   */
           uint32_t                   : 2;     /*!< Enable UCLK Interrupt                                    */
      __IO uint32_t CYC_DONE_EN       : 1;     /*!< Enable CYC_DONE Interrupt                                */
           uint32_t                   : 2;
      __IO uint32_t WRUFL_EN          : 1;     /*!< Enable WRUFL Interrupt                                   */
	       uint32_t                   : 23;
    };		   
  } SOCBINT_EN;
  
} PAC5XXX_SocBridge_TypeDef;
/*@}*/ /* end of group PAC5XXX_SocBridge */
