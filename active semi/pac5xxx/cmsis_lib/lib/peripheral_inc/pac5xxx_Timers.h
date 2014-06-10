
/**************************************************************************//**
 * @file     pac5xxx_Timers.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX Timers
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
 
/*------------- Timer with 8 CC/PWM units (Timer8CC) ----------------------*/
/** @addtogroup PAC5XXX_Timer8CC PAC5XXX Timer Capture/Compare/PWM outputs (TIMER8CC)
  @{
*/

/** TXCTRL Timer Mode Enumeration Type */
typedef enum {
  TxCTL_MODE_DISABLED = 0,                    /*!< Timer mode: disabled                                            */
  TxCTL_MODE_UP = 1,                          /*!< Timer mode: up                                                  */
  TxCTL_MODE_UPDOWN = 2                       /*!< Timer mode: up/down                                             */
} TXCTRL_MODE_Type;

/** TXCTRL Clock Input Enumeration Type */
typedef enum {
  TxCTL_CS_HCLK = 0,                          /*!< Timer clock source: HCLK                                        */
  TxCTL_CS_ACLK = 1                           /*!< Timer clock source: ACLK                                       */
} TXCTRL_CLKIN_Type;

/** TXCTRL Clock Input Pre-scaler Enumeration Type */
typedef enum {
  TxCTL_PS_DIV1 = 0,                          /*!< Timer pre-scaler: /1                                            */
  TxCTL_PS_DIV2 = 1,                          /*!< Timer pre-scaler: /2                                            */ 
  TxCTL_PS_DIV4 = 2,                          /*!< Timer pre-scaler: /4                                            */
  TxCTL_PS_DIV8 = 3,                          /*!< Timer pre-scaler: /8                                            */
  TxCTL_PS_DIV16 = 4,                         /*!< Timer pre-scaler: /16                                           */
  TxCTL_PS_DIV32 = 5,                         /*!< Timer pre-scaler: /32                                           */
  TxCTL_PS_DIV64 = 6,                         /*!< Timer pre-scaler: /64                                           */
  TxCTL_PS_DIV128 = 7                         /*!< Timer pre-scaler: /128                                          */
} TXCTRL_PS_Type;

/** TXCTRL Counter Period Latch Enumeration Type */
typedef enum {
  TxCTL_CLPRD_PRD = 0,                        /*!< Timer Compare Latch Period: TxPRD - 1 (up mode, or counting up) */
  TxCTL_CLPRD_0 = 1                           /*!< Timer Compare Latch Period: 1 (up/down mode counting down)      */
} TXCCTRL_LATCH_Type;

/** TXCTRL Capture Edge Enumeration Type */
typedef enum {
  TxCCTL_CED_HIGHTOLOW = 0,                   /*!< Timer Capture edge high-to-low transition                       */
  TxCCTL_CED_LOWTOHIGH = 1,                   /*!< Timer Capture edge low-to-high transition                       */
  TxCCTL_CED_BOTH = 2                         /*!< Timer Capture edge both high-to-low and low-to-high transition  */
} TXCCTRL_CAPEDGE_Type;

/*!< TxCCTRL<n> Register Definition */
typedef union {
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
    __IO uint32_t CCEDGE            : 2;        /*!< Capture Edge Detect                                             */
    __IO uint32_t CCINT             : 1;        /*!< Capture/Compare Interrupt Flag                                  */
    __IO uint32_t CCINTEN           : 1;        /*!< Capture/Compare Interrupt Enabled                               */
    __IO uint32_t CCMODE            : 1;        /*!< Capture Mode                                                    */
         uint32_t                   : 27;
  };
} PAC5XXX_TIMERCC_TypeDef;
	
/*!< DTGCTL<n> Register Definition */
typedef union {
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
	     uint32_t                   : 4;
    __IO uint32_t INV_B             : 1;        /*!< Invert PWM_OUT[n+1]                                               */
    __IO uint32_t INV_A             : 1;        /*!< Invert PWM_OUT[n]                                                 */
    __IO uint32_t OTP               : 1;        /*!< Pulse on-time preservation                                        */
    __IO uint32_t BYPASS            : 1;        /*!< Pass-through mode                                                 */
         uint32_t                   : 24;
  };
} PAC5XXX_DTGCTL_TypeDef;

/*------------- Timer with 4 CC/PWM units (Timer2CC) ----------------------*/
/** @addtogroup PAC5XXX_Timer4CC PAC5XXX Timer Capture/Compare/PWM outputs (TIMER4CC)
  @{
*/
typedef struct
{
  /*!< TxCTRL<n>: Offset: 0x0000      Timer Control Register                                                        */
  union {                         
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b                 : 8;
         uint32_t                   : 24;
    };
    struct {
      __IO uint32_t PRDL            : 1;       /*!< Compare Latch Period                                           */
           uint32_t                 : 1;       
      __IO uint32_t CLR             : 1;       /*!< Timer Clear                                                    */
      __IO uint32_t SS              : 1;       /*!< Single-shot mode                                               */
      __IO uint32_t INT             : 1;       /*!< Base Timer interrupt flag                                      */
      __IO uint32_t INTEN           : 1;       /*!< Base Timer interrupt enable                                    */
      __IO uint32_t CLKDIV          : 3;       /*!< Timer Input Clock divider                                      */
      __IO uint32_t CLK             : 1;       /*!< Timer Input Clock Source                                       */
      __IO uint32_t MODE            : 2;       /*!< Timer Mode                                                     */
      __IO uint32_t SYNC            : 1;       /*!< Timer Sync                                                     */
      __IO uint32_t DTGCLKDIVEN     : 1;       /*!< DTG clock divider enabled                                  */
      uint32_t                      : 18;
	  };
  } CTL;

  __IO uint32_t PRD;                           /*!< Offset: 0x0004   Timer Period Register                         */
  __I  uint32_t CTR;                           /*!< Offset: 0x0008   Timer Counter Register                        */
       uint32_t RESERVED5[13];                     

  __IO PAC5XXX_TIMERCC_TypeDef CCTRL0;           /*!< Offset: 0x0040   Timer Capture/Compare 0 Control Register      */
  __IO uint32_t CTR0;                          /*!< Offset: 0x0044   Timer Capture/Compare 0 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL1;           /*!< Offset: 0x0048   Timer Capture/Compare 1 Control Register      */
  __IO uint32_t CTR1;                          /*!< Offset: 0x004C   Timer Capture/Compare 1 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL2;           /*!< Offset: 0x0050   Timer Capture/Compare 2 Control Register      */
  __IO uint32_t CTR2;                          /*!< Offset: 0x0054   Timer Capture/Compare 2 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL3;           /*!< Offset: 0x0058   Timer Capture/Compare 3 Control Register      */
  __IO uint32_t CTR3;                          /*!< Offset: 0x005C   Timer Capture/Compare 3 Counter Register      */
  
       uint32_t RESERVED6[16]; 
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL0;           /*!< Offset: 0x00A0   Dead-Time Generator 0 Control Register        */
  __IO uint32_t DTGLED0;                       /*!< Offset: 0x00A4   Dead-Time Generator 0 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED0;                       /*!< Offset: 0x00A8   Dead-Time Generator 0 Trailing-Edge Delay Reg */

  } PAC5XXX_Timer4CC_TypeDef;
/*@}*/ /* end of group PAC5XXX_Timer4 */

typedef struct
{
  /*!< TxCTRL<n>: Offset: 0x0000      Timer Control Register                                                        */
  union {                         
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b                 : 8;
         uint32_t                   : 24;
    };
    struct {
      __IO uint32_t PRDL            : 1;       /*!< Compare Latch Period                                           */
           uint32_t                 : 1;
      __IO uint32_t CLR             : 1;       /*!< Timer Clear                                                    */
      __IO uint32_t SS              : 1;       /*!< Single-shot mode                                               */
      __IO uint32_t INT             : 1;       /*!< Base Timer interrupt flag                                      */
      __IO uint32_t INTEN           : 1;       /*!< Base Timer interrupt enable                                    */
      __IO uint32_t CLKDIV          : 3;       /*!< Timer Input Clock pre-scaler                                   */
      __IO uint32_t CLK             : 1;       /*!< Timer Input Clock Source                                       */
      __IO uint32_t MODE            : 2;       /*!< Timer Mode                                                     */
      __IO uint32_t SYNC            : 1;       /*!< Timer Sync                                                     */
      __IO uint32_t DTGCLKDIVEN     : 1;       /*!< DTG clock divider enabled                                  */
           uint32_t                 : 18;
	  };
  } CTL;
    
  __IO uint32_t PRD;                           /*!< Offset: 0x0004   Timer Period Register                         */
  __I  uint32_t CTR;                           /*!< Offset: 0x0008   Timer Counter Register                        */
       uint32_t RESERVED0[13];                     

  __IO PAC5XXX_TIMERCC_TypeDef CCTRL0;           /*!< Offset: 0x0040   Timer Capture/Compare 0 Control Register      */
  __IO uint32_t CTR0;                          /*!< Offset: 0x0044   Timer Capture/Compare 0 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL1;           /*!< Offset: 0x0048   Timer Capture/Compare 1 Control Register      */
  __IO uint32_t CTR1;                          /*!< Offset: 0x004C   Timer Capture/Compare 1 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL2;           /*!< Offset: 0x0050   Timer Capture/Compare 2 Control Register      */
  __IO uint32_t CTR2;                          /*!< Offset: 0x0054   Timer Capture/Compare 2 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL3;           /*!< Offset: 0x0058   Timer Capture/Compare 3 Control Register      */
  __IO uint32_t CTR3;                          /*!< Offset: 0x005C   Timer Capture/Compare 3 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL4;           /*!< Offset: 0x0060   Timer Capture/Compare 4 Control Register      */
  __IO uint32_t CTR4;                          /*!< Offset: 0x0064   Timer Capture/Compare 4 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL5;           /*!< Offset: 0x0068   Timer Capture/Compare 5 Control Register      */
  __IO uint32_t CTR5;                          /*!< Offset: 0x006C   Timer Capture/Compare 5 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL6;           /*!< Offset: 0x0070   Timer Capture/Compare 6 Control Register      */
  __IO uint32_t CTR6;                          /*!< Offset: 0x0074   Timer Capture/Compare 6 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL7;           /*!< Offset: 0x0078   Timer Capture/Compare 7 Control Register      */
  __IO uint32_t CTR7;                          /*!< Offset: 0x007C   Timer Capture/Compare 7 Counter Register      */
       uint32_t RESERVED1[8]; 
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL0;           /*!< Offset: 0x00A0   Dead-Time Generator 0 Control Register        */
  __IO uint32_t DTGLED0;                       /*!< Offset: 0x00A4   Dead-Time Generator 0 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED0;                       /*!< Offset: 0x00A8   Dead-Time Generator 0 Trailing-Edge Delay Reg */
       uint32_t RESERVED2;
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL1;           /*!< Offset: 0x00B0   Dead-Time Generator 1 Control Register        */
  __IO uint32_t DTGLED1;                       /*!< Offset: 0x00B4   Dead-Time Generator 1 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED1;                       /*!< Offset: 0x00B8   Dead-Time Generator 1 Trailing-Edge Delay Reg */
       uint32_t RESERVED3;
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL2;           /*!< Offset: 0x00C0   Dead-Time Generator 2 Control Register        */
  __IO uint32_t DTGLED2;                       /*!< Offset: 0x00C4   Dead-Time Generator 2 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED2;                       /*!< Offset: 0x00C8   Dead-Time Generator 2 Trailing-Edge Delay Reg */
       uint32_t RESERVED4;
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL3;           /*!< Offset: 0x00D0   Dead-Time Generator 3 Control Register        */
  __IO uint32_t DTGLED3;                       /*!< Offset: 0x00D4   Dead-Time Generator 3 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED3;                       /*!< Offset: 0x00D8   Dead-Time Generator 3 Trailing-Edge Delay Reg */

  } PAC5XXX_Timer8CC_TypeDef;
/*@}*/ /* end of group PAC5XXX_Timer8CC */


/*------------- Timer with 2 CC/PWM units (Timer2CC) ----------------------*/
/** @addtogroup PAC5XXX_Timer2CC PAC5XXX Timer Capture/Compare/PWM outputs (TIMER2CC)
  @{
*/
typedef struct
{
  /*!< TxCTRL<n>: Offset: 0x0000      Timer Control Register                                                        */
  union {                         
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b                 : 8;
         uint32_t                   : 24;
    };
    struct {
      __IO uint32_t PRDL           : 1;       /*!< Compare Latch Period                                           */
           uint32_t                 : 1;       
      __IO uint32_t CLR             : 1;       /*!< Timer Clear                                                    */
      __IO uint32_t SS              : 1;       /*!< Single-shot mode                                               */
      __IO uint32_t INT             : 1;       /*!< Base Timer interrupt flag                                      */
      __IO uint32_t INTEN           : 1;       /*!< Base Timer interrupt enable                                    */
      __IO uint32_t CLKDIV          : 3;       /*!< Timer Input Clock pre-scaler                                   */
      __IO uint32_t CLK             : 1;       /*!< Timer Input Clock Source                                       */
      __IO uint32_t MODE            : 2;       /*!< Timer Mode                                                     */
      __IO uint32_t SYNC            : 1;       /*!< Timer Sync                                                     */
      __IO uint32_t DTGCLKDIVEN        : 1;       /*!< DTG clock pre-scaling enabled                                  */
      uint32_t                      : 18;
	  };
  } CTL;

  __IO uint32_t PRD;                           /*!< Offset: 0x0004   Timer Period Register                         */
  __I  uint32_t CTR;                           /*!< Offset: 0x0008   Timer Counter Register                        */
       uint32_t RESERVED5[13];                     

  __IO PAC5XXX_TIMERCC_TypeDef CCTRL0;           /*!< Offset: 0x0040   Timer Capture/Compare 0 Control Register      */
  __IO uint32_t CTR0;                          /*!< Offset: 0x0044   Timer Capture/Compare 0 Counter Register      */
  __IO PAC5XXX_TIMERCC_TypeDef CCTRL1;           /*!< Offset: 0x0048   Timer Capture/Compare 1 Control Register      */
  __IO uint32_t CTR1;                          /*!< Offset: 0x004C   Timer Capture/Compare 1 Counter Register      */
       uint32_t RESERVED6[20]; 
  __IO PAC5XXX_DTGCTL_TypeDef DTGCTL0;           /*!< Offset: 0x00A0   Dead-Time Generator 0 Control Register        */
  __IO uint32_t DTGLED0;                       /*!< Offset: 0x00A4   Dead-Time Generator 0 Leading-Edge Delay Reg  */
  __IO uint32_t DTGTED0;                       /*!< Offset: 0x00A8   Dead-Time Generator 0 Trailing-Edge Delay Reg */

  } PAC5XXX_Timer2CC_TypeDef;
/*@}*/ /* end of group PAC5XXX_Timer2 */


