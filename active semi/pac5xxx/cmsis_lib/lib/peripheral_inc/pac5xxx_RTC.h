
/**************************************************************************//**
 * @file     pac5xxx_RTC.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX RTC
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

/*------------- Real-Time Clock (RTC) ----------------------*/
/** @addtogroup PAC5XXX_RTC PAC5XXX Real-Time Clock (RTC)
  @{
*/

#define RTCCTL_PASS_WRITE          0x4A000000    /*!< RTC Write Register Password                                 */
#define RTCCTL_PASS_READ           0x63000000    /*!< RTC Read Register Password                                  */

#define RTCCTL_IF_SHIFT            4             /*!< RTC interrupt flag bit-shift                                */
#define RTCCTL_IF_MASK             0x00000010    /*!< RTC interrupt flag mask                                     */

#define RTCCTL_RST_SHIFT           0             /*!< RTC reset key bit-shift                                     */
#define RTCCTL_RST_VAL             0x00000005    /*!< RTC reset key value                                         */

#define RTCCTL_IE_SHIFT            3            /*!< RTC interrupt enable bit-shift                              */
#define RTCCTL_IE_MASK             0x00000008    /*!< RTC interrupt enable mask                                   */

#define RTCCTL_WRBUSY_SHIFT        11            /*!< RTC Write Busy bit-shift                                    */
#define RTCCTL_WRBUSY_MASK         0x00000800   /*!< RTC Write Busy mask                                         */

#define RTC_WAIT_WRITE_BLOCK       while ((PAC5XXX_RTC->RTCCTL & RTCCTL_WRBUSY_MASK) != 0);

/** RTCCTL Pre-scaler Enumeration Type */
typedef enum {
  RTCCTL_PS_DIV2 = 0,                            /*!< RTC Pre-Scaler (/2)                                         */
  RTCCTL_PS_DIV4 = 1,                            /*!< RTC Pre-Scaler (/4)                                         */
  RTCCTL_PS_DIV8 = 2,                            /*!< RTC Pre-Scaler (/8)                                         */
  RTCCTL_PS_DIV16 = 3,                           /*!< RTC Pre-Scaler (/16)                                        */
  RTCCTL_PS_DIV32 = 4,                           /*!< RTC Pre-Scaler (/32)                                        */
  RTCCTL_PS_DIV64 = 5,                           /*!< RTC Pre-Scaler (/64)                                        */
  RTCCTL_PS_DIV128 = 6,                          /*!< RTC Pre-Scaler (/128)                                       */
  RTCCTL_PS_DIV256 = 7,                          /*!< RTC Pre-Scaler (/128)                                       */
  RTCCTL_PS_DIV512 = 8,                          /*!< RTC Pre-Scaler (/512)                                       */
  RTCCTL_PS_DIV1024 = 9,                         /*!< RTC Pre-Scaler (/1024)                                      */
  RTCCTL_PS_DIV2048 = 10,                        /*!< RTC Pre-Scaler (/2048)                                      */
  RTCCTL_PS_DIV4096 = 11,                        /*!< RTC Pre-Scaler (/4096)                                      */
  RTCCTL_PS_DIV8192 = 12,                        /*!< RTC Pre-Scaler (/8192)                                      */
  RTCCTL_PS_DIV16384 = 13,                       /*!< RTC Pre-Scaler (/16384)                                     */
  RTCCTL_PS_DIV32767 = 14,                       /*!< RTC Pre-Scaler (/32767)                                     */
  RTCCTL_PS_DIV65536 = 15                        /*!< RTC Pre-Scaler (/65536)                                     */
} RTCCTL_PS_Type;

#define RTCCTL_PS_SHIFT            6            /*!< RTC Pre-scaler bit-shift                                    */

typedef struct
{
  /*!< RTCCTL:      Offset: 0x0000             Watchdog Timer Control Register       */
  __IO uint32_t RTCCTL;

  /*!< RTCCDV:       Offset: 0x0004            Watchdog Timer Countdown Value Reg    */  
  __IO uint32_t RTCCDV;
  
  /*!< RTCCDR:       Offset: 0x0008            Watchdog Timer Countdown Register     */
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
      __I uint32_t VAL              : 24;          /*!< Countdown Register Value         */
	        uint32_t                : 8;
    };
  } RTCCTR;
  
} PAC5XXX_RTC_TypeDef;
/*@}*/ /* end of group PAC5XXX_RTC */
