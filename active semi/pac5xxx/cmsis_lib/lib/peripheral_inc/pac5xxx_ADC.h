
/**************************************************************************//**
 * @file     pac5xxx_ADC.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX ADC
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

/*------------- Analog to Digital Converter (ADC) ----------------------*/
/** @addtogroup PAC5XXX_ADC PAC5XXX Analog to Digital Converter (ADC)
  @{
*/

/** ADC EMUX Control Type Enumeration */
typedef enum {
  ADCEMUXCTL_EMUXC_MUXDATA = 0,                /*!< EMUX is controlled by EMUXDATA                                 */
  ADCEMUXCTL_EMUXC_SEQ = 1                     /*!< EMUX is controlled by automated ADC sequencer                  */
} ADC_EMUX_CTL_Type;

/** ADC EMUX Clock Divider Type Enumeration */
typedef enum {
  ADCEMUXCTL_EMUXDIV_DIV1 = 0,                 /*!< External MUX clock divider: /1                                 */
  ADCEMUXCTL_EMUXDIV_DIV2 = 1,                 /*!< External MUX clock divider: /2                                 */
  ADCEMUXCTL_EMUXDIV_DIV3 = 2,                 /*!< External MUX clock divider: /3                                 */
  ADCEMUXCTL_EMUXDIV_DIV4 = 3,                 /*!< External MUX clock divider: /4                                 */
  ADCEMUXCTL_EMUXDIV_DIV5 = 4,                 /*!< External MUX clock divider: /5                                 */
  ADCEMUXCTL_EMUXDIV_DIV6 = 5,                 /*!< External MUX clock divider: /6                                 */
  ADCEMUXCTL_EMUXDIV_DIV7 = 6,                 /*!< External MUX clock divider: /7                                 */
  ADCEMUXCTL_EMUXDIV_DIV8 = 7                  /*!< External MUX clock divider: /8                                 */
} ADC_EMUX_DIV_Type;

/** ADCCTL Conversion Mode Enumeration Type */
typedef enum {
  ADCCTL_ADSTART_SINGLE = 0,                   /*!< Single channel conversion                                      */
  ADCCTL_ADSTART_AUTO_0 = 1,                   /*!< Automated sequencer 0 only                                     */
  ADCCTL_ADSTART_AUTO_1 = 2,                   /*!< Automated sequencer 1 only                                     */
  ADCCTL_ADSTART_AUTO_01_CHAIN = 3,            /*!< Automated sequencer 0, 1 chained                               */
  ADCCTL_ADSTART_AUTO_0_TRIG = 4,              /*!< Automated sequencer 0 with trigger                             */
  ADCCTL_ADSTART_AUTO_1_TRIG = 5,              /*!< Automated sequencer 1 with trigger                             */
  ADCCTL_ADSTART_AUTO_01_CHAIN_TRIG = 6,       /*!< Automated sequencer 0 and 1 trigger independently on AS0 trigger*/
  ADCCTL_ADSTART_AUTO_01_IND_TRIG = 7          /*!< Automated sequencer 0 and 1 trigger independently on AS0 and AS1*/
} ADCCTL_ADMODE_Type;

/** ADCCTL Positive Input MUX channel select */
typedef enum {
  ADCCTL_ADMUX_AD0 = 0,                        /*!< ADC positive input MUX channel select: AD0 (Analog die)        */
  ADCCTL_ADMUX_AD1 = 1,                        /*!< ADC positive input MUX channel select: AD1                     */
  ADCCTL_ADMUX_AD2 = 2,                        /*!< ADC positive input MUX channel select: AD2                     */
  ADCCTL_ADMUX_AD3 = 3,                        /*!< ADC positive input MUX channel select: AD3                     */
  ADCCTL_ADMUX_AD4 = 4,                        /*!< ADC positive input MUX channel select: AD4                     */
  ADCCTL_ADMUX_AD5 = 5,                        /*!< ADC positive input MUX channel select: AD5                     */
  ADCCTL_ADMUX_VSSA = 7                        /*!< ADC positive input MUX channel select: VSSA                    */
} ADCCTL_ADMUX_Type;

/** ADCCTL clock input divider */
typedef enum {
  ADCCTL_ADCDIV_DIV1 = 0,                      /*!< ADC module clock input divider: /1                             */
  ADCCTL_ADCDIV_DIV2 = 1,                      /*!< ADC module clock input divider: /2                             */
  ADCCTL_ADCDIV_DIV3 = 2,                      /*!< ADC module clock input divider: /3                             */
  ADCCTL_ADCDIV_DIV4 = 3,                      /*!< ADC module clock input divider: /4                             */
  ADCCTL_ADCDIV_DIV5 = 4,                      /*!< ADC module clock input divider: /5                             */
  ADCCTL_ADCDIV_DIV6 = 5,                      /*!< ADC module clock input divider: /6                             */
  ADCCTL_ADCDIV_DIV7 = 6,                      /*!< ADC module clock input divider: /7                             */
  ADCCTL_ADCDIV_DIV8 = 7                       /*!< ADC module clock input divider: /8                             */
} ADCCTL_CLKDIV_Type;

/** ASCTLX Sampling Trigger Source Enumeration Type */
typedef enum {
  ADCCTLX_ASTR_PWM = 0,                        /*!< Automated ADC sampling trigger: PWM                            */
  ADCCTLX_ASTR_TIMER = 1                       /*!< Automated ADC sampling trigger: Timer                          */
} ADCCTLX_STRIG_Type;

/** ASCTLX Sampling Trigger Depth Enumeration Type */
typedef enum {
  ADCCTLX_AS1D_DEPTH1 = 0,                     /*!< Automated ADC sampling depth: 1 samples                        */
  ADCCTLX_AS1D_DEPTH2 = 1,                     /*!< Automated ADC sampling depth: 2 samples                        */
  ADCCTLX_AS1D_DEPTH3 = 2,                     /*!< Automated ADC sampling depth: 3 samples                        */
  ADCCTLX_AS1D_DEPTH4 = 3,                     /*!< Automated ADC sampling depth: 4 samples                        */
  ADCCTLX_AS1D_DEPTH5 = 4,                     /*!< Automated ADC sampling depth: 5 samples                        */
  ADCCTLX_AS1D_DEPTH6 = 5,                     /*!< Automated ADC sampling depth: 6 samples                        */
  ADCCTLX_AS1D_DEPTH7 = 6,                     /*!< Automated ADC sampling depth: 7 samples                        */
  ADCCTLX_AS1D_DEPTH8 = 7                      /*!< Automated ADC sampling depth: 8 samples                        */
} ADCCTLX_SDEPTH_Type;

/** ADCCTLX Sampling Trigger Edge Enumeration Type */
typedef enum {
  ADCCTLX_TRIGEDGE_LOWTOHI = 0,                /*!< Automated ADC trigger edge: Low to High                        */
  ADCCTLX_TRIGEDGE_HITOLOW = 1                 /*!< Automated ADC trigger edge: High to Low                        */
} ADCCTLX_TRIGEDGE_Type;

/** ADCCTLX Sampling PWM Trigger Enumeration Type */
typedef enum {
  ADCCTLX_TRIGPWM_PWMA0 = 0,                   /*!< Automated ADC PWM trigger source: PWMA0                        */
  ADCCTLX_TRIGPWM_PWMA1 = 1,                   /*!< Automated ADC PWM trigger source: PWMA1                        */
  ADCCTLX_TRIGPWM_PWMA2 = 2,                   /*!< Automated ADC PWM trigger source: PWMA2                        */
  ADCCTLX_TRIGPWM_PWMA3 = 3,                   /*!< Automated ADC PWM trigger source: PWMA3                        */
  ADCCTLX_TRIGPWM_PWMA4 = 4,                   /*!< Automated ADC PWM trigger source: PWMA4                        */
  ADCCTLX_TRIGPWM_PWMA5 = 5,                   /*!< Automated ADC PWM trigger source: PWMA5                        */
  ADCCTLX_TRIGPWM_PWMA6 = 6,                   /*!< Automated ADC PWM trigger source: PWMA6                        */
  ADCCTLX_TRIGPWM_PWMA7 = 7,                   /*!< Automated ADC PWM trigger source: PWMA7                        */
  ADCCTLX_TRIGPWM_PWMB0 = 8,                   /*!< Automated ADC PWM trigger source: PWMB0                        */
  ADCCTLX_TRIGPWM_PWMB1 = 9,                   /*!< Automated ADC PWM trigger source: PWMB1                        */
  ADCCTLX_TRIGPWM_PWMC0 = 10,                  /*!< Automated ADC PWM trigger source: PWMC0                        */
  ADCCTLX_TRIGPWM_PWMC1 = 11,                  /*!< Automated ADC PWM trigger source: PWMC1                        */
  ADCCTLX_TRIGPWM_PWMD0 = 12,                  /*!< Automated ADC PWM trigger source: PWMD0                        */
  ADCCTLX_TRIGPWM_PWMD1 = 13                   /*!< Automated ADC PWM trigger source: PWMD1                        */
} ADCCTLX_TRIGPWM_Type;

/** ADCCTLX Sampling Timer Trigger Enumeration Type */
typedef enum {
  ADCCTLX_TRIGTIM_TIMERA = 0,                  /*!< Automated ADC Timer trigger source: Timer A                    */
  ADCCTLX_TRIGTIM_TIMERB = 1,                  /*!< Automated ADC Timer trigger source: Timer B                    */
  ADCCTLX_TRIGTIM_TIMERC = 2,                  /*!< Automated ADC Timer trigger source: Timer C                    */
  ADCCTLX_TRIGTIM_TIMERD = 3                   /*!< Automated ADC Timer trigger source: Timer D                    */
} ADCCTLX_TRIGTIMER_Type;

/** ASXS Sampling Trigger Delay */
typedef enum {
  ASSEQ_DELAY_0 = 0,                           /*!< Delay between trigger and S/H: 0 ADC module clocks             */
  ASSEQ_DELAY_4 = 1,                           /*!< Delay between trigger and S/H: 4 ADC module clocks             */
  ASSEQ_DELAY_8 = 2,                           /*!< Delay between trigger and S/H: 8 ADC module clocks             */
  ASSEQ_DELAY_16 = 3                           /*!< Delay between trigger and S/H: 16 ADC module clocks            */
} ASSEQ_DELAY_Type;

/** ASXS Mini SPI MUX Control Enumeration Type */
typedef enum {
  ASSEQ_MSPI_NOSEND = 0,                       /*!< When to send EMUX message: never                               */
  ASSEQ_MSPI_BEG = 1,                          /*!< When to send EMUX message: at beginning of this sequence       */
  ASSEQ_MSPI_AFTER_SH = 2                      /*!< When to send EMUX message: after S/H of ADC                    */
} ASSEQ_MSPI_Type;

/** ASCINT Sequence ID for \a ASCTR and ASCSEQ bits */
typedef enum {
  ASCINT_SEQ_0 = 1,
  ASCINT_SEQ_1 = 2
} ASCINT_SEQ_Type;

/** ADCINT bit positions */
typedef enum {
  ADCINT_ADCINT =   0x01,
  ADCINT_EMUXINT =  0x02,
  ADCINT_AS0INT =   0x04,
  ADCINT_AS1INT =   0x08,
  ADCINT_ASCINT =   0x10,
  ADCINT_ALL =      0x1F
} ADCINT_BITS;

/*!< ADC Conversion Result Register Definition */
typedef union {
  __I uint32_t w;
  struct {
      __I  uint32_t s           : 16;
           uint32_t             : 16;
    };
  struct {
  __I  uint32_t b               : 8;
       uint32_t                 : 24;
  };
  struct {
    __I  uint32_t VAL           : 10;     /*!< ADC Conversion Result Value                                    */
         uint32_t               : 22;
  };
} PAC5XXX_ADCRESULT_Type;

/*!< ADC Sampling Sequence Control Register Definition */
typedef union {
  __IO uint32_t w;
  struct {
    __IO uint32_t EMUXD         : 8;      /*!< MUX data to send                                               */
    __IO uint32_t EMUXS         : 2;      /*!< MUX Command Send Control                                       */
    __IO uint32_t DELAY         : 2;      /*!< Delay between trigger and S/H                                  */
    __IO uint32_t ADCMUX        : 3;      /*!< ADC Positive Input MUX Channel Select                          */
         uint32_t               : 17;
  };
} PAC5XXX_ADCSEQCTL_Type;
  
typedef struct
{
  /*!< EMUXCTL: Offset: 0x0000   ADC External MUX Control                      */
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
	  __IO uint32_t EMUXDIV         : 3;       /*!< External MUX Clock Divider                                     */
	  __IO uint32_t EMUXDONE        : 1;       /*!< External MUX Data Send Finished                                */
	  __I  uint32_t EMUXBUSY        : 1;       /*!< External MUX Busy                                              */
	  __IO uint32_t EMUXC           : 1;       /*!< External MUX Control                                           */
	       uint32_t                 : 26;
	};
  } EMUXCTL;

  /*!< EMUXDATA: Offset: 0x0004   ADC External MUX Data    */
  struct {
    __IO uint32_t VAL               : 8;                     /*!< EMUX Data Value                                                */
         uint32_t                   : 24;
  } EMUXDATA;
  
  /*!< ADCCTL: Offset: 0x0008   ADC Control Register                          */
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
	    __IO uint32_t ADCDIV        : 3;      	/*!< ADC module clock input divider                                 */
	    __I  uint32_t ADCDONE       : 1;		/*!< ADC conversion completed. Auto-clear on read or on new conv. 	*/
	    __IO uint32_t ADCMUX        : 3; 	    /*!< ADC MUX Input Channel Select  			                        */
	    __I  uint32_t ADCBUSY       : 1;    	/*!< ADC Busy                                                       */
             uint32_t               : 2;
	    __IO uint32_t ADCMODE       : 3;       	/*!< ADC Mode                                                       */
        __IO uint32_t ADCREPEAT     : 1;       	/*!< ADC Repeated Conversion Mode                                   */
	    __IO uint32_t ADCSTART      : 1;       	/*!< ADC Conversion Start                                           */
	    __IO uint32_t ADCEN         : 1;       	/*!< ADC Enable                                                     */
           uint32_t                 : 16;
	  };
  } ADCCTL;

  __I  PAC5XXX_ADCRESULT_Type ADCCR;          	 /*!< ADCCR Offset: 0x000C   ADC Conversion Result Register           */
  
  /*!< ADCINT: Offset: 0x0010   ADC Interrupt Control Register                */
  union {
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
      __IO uint32_t ADCINT          : 1;       /*!< ADC Conversion Finished Interrupt Flag                         */
      __IO uint32_t EMUXINT         : 1;       /*!< External MUX Interrupt Flag                                    */
      __IO uint32_t AS0INT	        : 1;       /*!< Automated Sequence 0 Finished Interrupt Flag                   */
      __IO uint32_t AS1INT          : 1;       /*!< Automated Sequence 1 Finished Interrupt Flag                   */
      __IO uint32_t ASCINT          : 1;       /*!< Automated Sequence Collision Interrupt Flag                    */
           uint32_t                 : 3;    
      __IO uint32_t ADCINT_EN       : 1;       /*!< ADC Conversion Finished Interrupt Enable                       */
      __IO uint32_t EMUXINT_EN      : 1;       /*!< External MUX Interrupt Enable                                  */
      __IO uint32_t AS0INT_EN       : 1;       /*!< Automated Sequence 0 Finished Interrupt Enable                 */
      __IO uint32_t AS1INT_EN       : 1;       /*!< Automated Sequence 1 Finished Interrupt Enable                 */
      __IO uint32_t ASCINT_EN       : 1;       /*!< Automated Sequence Collision Interrupt Enable                  */
           uint32_t                 : 3;
      __I  uint32_t ASCTR           : 2;       /*!< Last Automated Sequence to generate ASCINT                     */
      __I  uint32_t ASCSEQ          : 2;       /*!< Last Automated Sequence to run                                 */
           uint32_t                 : 12;
    };
  } ADCINT;

	uint32_t RESERVED9[11];
	
  /*!< ASCTL0: Offset: 0x0040   Automated Sampling Control 0 Register           */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b               : 8;
         uint32_t                   : 24;
    };
    struct {
      __IO uint32_t AS0TRPWM        : 4;       /*!< Automated ADC Sampling 0 Trigger PWM source                    */
      __IO uint32_t AS0TRTMR        : 2;       /*!< Automated ADC Sampling 0 Trigger Timer Source                  */
      __IO uint32_t AS0TRE          : 1;       /*!< Automated ADC Sampling 0 Trigger Edge                          */
      __IO uint32_t AS0TR           : 1;       /*!< Automated ADC Sampling 0 Trigger Source                        */
      __IO uint32_t AS0D            : 3;       /*!< Automated ADC Sampling 0 Sequence Sampling Depth               */
      __IO uint32_t AS0SEQEN        : 1;       /*!< Automated ADC Sampling 0 Sequence Enable                       */
      __I  uint32_t AS1BUSY         : 1;       /*!< Automated ADC Sampling 0 Sequence Active                       */
           uint32_t                 : 19;
    };
  } ASCTL0;
  
  __IO PAC5XXX_ADCSEQCTL_Type AS0S0;             /*!< Offset: 0x0044   Automated Sampling 0 Sequence 0 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R0;             /*!< Offset: 0x0048   Automated Sampling 0 Result 0 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S1;             /*!< Offset: 0x004C   Automated Sampling 0 Sequence 1 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R1;             /*!< Offset: 0x0050   Automated Sampling 0 Result 1 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S2;             /*!< Offset: 0x0054   Automated Sampling 0 Sequence 2 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R2;             /*!< Offset: 0x0058   Automated Sampling 0 Result 2 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S3;             /*!< Offset: 0x005C   Automated Sampling 0 Sequence 3 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R3;             /*!< Offset: 0x0060   Automated Sampling 0 Result 3 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S4;             /*!< Offset: 0x0064   Automated Sampling 0 Sequence 4 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R4;             /*!< Offset: 0x0068   Automated Sampling 0 Result 4 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S5;             /*!< Offset: 0x006C   Automated Sampling 0 Sequence 5 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R5;             /*!< Offset: 0x0070   Automated Sampling 0 Result 5 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S6;             /*!< Offset: 0x0074   Automated Sampling 0 Sequence 6 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R6;             /*!< Offset: 0x0078   Automated Sampling 0 Result 6 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS0S7;             /*!< Offset: 0x007C   Automated Sampling 0 Sequence 7 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS0R7;             /*!< Offset: 0x0080   Automated Sampling 0 Result 7 Register        */

  uint32_t RESERVED13[31];
  
  /*!< ASCTL1: Offset: 0x0100   Automated Sampling Control 0 Register           */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
	  __IO uint32_t b               : 8;
         uint32_t                   : 24;
    };
    struct {
      __IO uint32_t AS1TRPWM        : 4;       /*!< Automated ADC Sampling 1 Trigger PWM source                    */
      __IO uint32_t AS1TRTMR        : 2;       /*!< Automated ADC Sampling 1 Trigger Timer Source                  */
      __IO uint32_t AS1TRE          : 1;       /*!< Automated ADC Sampling 1 Trigger Edge                          */
      __IO uint32_t AS1TR           : 1;       /*!< Automated ADC Sampling 1 Trigger Source                        */
      __IO uint32_t AS1D            : 3;       /*!< Automated ADC Sampling 1 Sequence Sampling Depth               */
      __IO uint32_t AS1SEQEN        : 1;       /*!< Automated ADC Sampling 1 Sequence Enable                       */
      __I  uint32_t AS1BUSY         : 1;       /*!< Automated ADC Sampling 1 Sequence Active                       */
           uint32_t                 : 19;
    };
  } ASCTL1;  
 
  __IO PAC5XXX_ADCSEQCTL_Type AS1S0;             /*!< Offset: 0x0104   Automated Sampling 1 Sequence 0 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R0;             /*!< Offset: 0x0108   Automated Sampling 1 Result 0 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S1;             /*!< Offset: 0x010C   Automated Sampling 1 Sequence 1 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R1;             /*!< Offset: 0x0110   Automated Sampling 1 Result 1 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S2;             /*!< Offset: 0x0114   Automated Sampling 1 Sequence 2 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R2;             /*!< Offset: 0x0118   Automated Sampling 1 Result 2 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S3;             /*!< Offset: 0x011C   Automated Sampling 1 Sequence 3 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R3;             /*!< Offset: 0x0120   Automated Sampling 1 Result 3 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S4;             /*!< Offset: 0x0124   Automated Sampling 1 Sequence 4 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R4;             /*!< Offset: 0x0128   Automated Sampling 1 Result 4 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S5;             /*!< Offset: 0x012C   Automated Sampling 1 Sequence 5 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R5;             /*!< Offset: 0x0130   Automated Sampling 1 Result 5 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S6;             /*!< Offset: 0x0134   Automated Sampling 1 Sequence 6 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R6;             /*!< Offset: 0x0138   Automated Sampling 1 Result 6 Register        */
  __IO PAC5XXX_ADCSEQCTL_Type AS1S7;             /*!< Offset: 0x013C   Automated Sampling 1 Sequence 7 Register      */
  __IO PAC5XXX_ADCRESULT_Type AS1R7;             /*!< Offset: 0x0140   Automated Sampling 1 Result 7 Register        */

} PAC5XXX_ADC_TypeDef;

/*@}*/ /* end of group PAC5XXX_ADC */

