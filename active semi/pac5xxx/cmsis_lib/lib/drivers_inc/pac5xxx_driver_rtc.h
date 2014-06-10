
/**************************************************************************//**
 * @file     pac5xxx_driver_rtc.h
 * @brief    Firmware driver for the PAC5XXX real-time clock
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

/** @addtogroup PAC5XXX_Driver_Rtc PAC5XXX Real-Time Clock
  @{
*/

#ifndef PAC5XXX_DRIVER_RTC_H
#define PAC5XXX_DRIVER_RTC_H

#include "pac5xxx.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_RTC_RAM
#define RAMFUNC_RTC	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_RTC
#endif

// Function Prototypes for support functions

/**
 * @brief  This function configures Real-time Clock
 *
 * @param  ie_en Set to non-zero to enable Watchdog Timer interval interrupt
 * @param  cdv The Real-time clock count-down value in clock ticks
 * @param  prescale The input clock pre-scaler for the RTC
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_config(int ie_en, uint16_t cdv, RTCCTL_PS_Type prescale);

/**
 * @brief  This function resets the watchdog timer
 *
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_reset(void);

/**
 * @brief  This function clears the Real-Time Clock interrupt flag
 *
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_clear_if(void);

/**
 * @brief  This function indicates whether or not the RTC has completed its last register write
 *
 * @returns 0: Not busy, non-zero: busy
 */
RAMFUNC_RTC static int pac5xxx_rtc_write_busy(void) { return ((PAC5XXX_RTC->RTCCTL & RTCCTL_WRBUSY_MASK) != 0); }


/*@}*/ /* end of group PAC5XXX_Driver_Rtc */


#endif // PAC5XXX_DRIVER_RTC_H

