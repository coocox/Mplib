/**
 *******************************************************************************
 * @file    tmpm333_rtc.h
 * @brief   This file provides all the functions prototypes for RTC driver.
 * @version V2.1.0
 * @date    2010/07/20
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM333_RTC_H
#define __TMPM333_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM333.h"
#include "tx03_common.h"

#if defined(__TMPM330_RTC_H) || defined(__TMPM332_RTC_H) || defined(__TMPM333_RTC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup RTC
  * @{
  */

/** @defgroup RTC_Exported_Types
  * @{
  */

/** 
  * @brief  RTC Structure definition  
  */

    typedef struct {
        uint8_t HourMode;       /*!< Select RTC 12-Hour mode or 24-Hour mode */
        uint8_t Hour;           /*!< Set RTC hour value                      */
        uint8_t AmPm;           /*!< Select AM/PM mode in 12H mode           */
        uint8_t Min;            /*!< Set RTC minute value                    */
        uint8_t Sec;            /*!< Set RTC second value                    */
    } RTC_TimeTypeDef;

    typedef struct {
        uint8_t LeapYear;       /*!< Select RTC Leap-Year status */
        uint8_t Year;           /*!< Set RTC year value          */
        uint8_t Month;          /*!< Set RTC month value         */
        uint8_t Date;           /*!< Set RTC date value          */
        uint8_t Day;            /*!< Set RTC day value           */
    } RTC_DateTypeDef;

    typedef struct {
        uint8_t Date;           /*!< Set alarm date value          */
        uint8_t Day;            /*!< Set alarm day value           */
        uint8_t Hour;           /*!< Set alarm hour value          */
        uint8_t AmPm;           /*!< Select AM/PM mode in 12H mode */
        uint8_t Min;            /*!< Set alarm minute value        */
    } RTC_AlarmTypeDef;

/** @} */
/* End of group RTC_Exported_Types */

/** @defgroup RTC_Exported_Constants
  * @{
  */

#define RTC_24_HOUR_MODE      ((uint8_t)0x01)
#define RTC_12_HOUR_MODE      ((uint8_t)0x00)
#define IS_RTC_HOUR_MODE(param)      (((param) == RTC_24_HOUR_MODE) || \
                                      ((param) == RTC_12_HOUR_MODE))


#define RTC_AM_MODE      ((uint8_t)0x00)
#define RTC_PM_MODE      ((uint8_t)0x01)
#define RTC_AMPM_INVALID ((uint8_t)0x02)
#define IS_RTC_AMPM_MODE(param)      (((param) == RTC_AM_MODE) || \
                                      ((param) == RTC_PM_MODE))


#define RTC_LEAP_YEAR_0             ((uint8_t)0x00)
#define RTC_LEAP_YEAR_1             ((uint8_t)0x01)
#define RTC_LEAP_YEAR_2             ((uint8_t)0x02)
#define RTC_LEAP_YEAR_3             ((uint8_t)0x03)
#define IS_RTC_LEAP_YEAR(param)   (((param) == RTC_LEAP_YEAR_0) || \
                                   ((param) == RTC_LEAP_YEAR_1) || \
                                   ((param) == RTC_LEAP_YEAR_2) || \
                                   ((param) == RTC_LEAP_YEAR_3))


#define RTC_SUN             ((uint8_t)0x00)
#define RTC_MON             ((uint8_t)0x01)
#define RTC_TUE             ((uint8_t)0x02)
#define RTC_WED             ((uint8_t)0x03)
#define RTC_THU             ((uint8_t)0x04)
#define RTC_FRI             ((uint8_t)0x05)
#define RTC_SAT             ((uint8_t)0x06)
#define IS_RTC_DAY(param)  (((param) == RTC_SUN) || \
                            ((param) == RTC_MON) || \
                            ((param) == RTC_TUE) || \
                            ((param) == RTC_WED) || \
                            ((param) == RTC_THU) || \
                            ((param) == RTC_FRI) || \
                            ((param) == RTC_SAT))


#define RTC_LOW_LEVEL               ((uint8_t)0x00)
#define RTC_PULSE_1_HZ              ((uint8_t)0x01)
#define RTC_PULSE_16_HZ             ((uint8_t)0x02)
#define IS_RTC_ALARM_OUTPUT(param)   (((param) == RTC_LOW_LEVEL) || \
                                      ((param) == RTC_PULSE_1_HZ) || \
                                      ((param) == RTC_PULSE_16_HZ))


#define IS_RTC_YEAR(param)        ((param) <= 99U)
#define IS_RTC_MONTH(param)       (((param) >= 1U)&&((param) <= 12U))
#define IS_RTC_DATE(param)        (((param) >= 1U)&&((param) <= 31U))
#define IS_RTC_HOUR_24(param)     ((param) <= 23U)
#define IS_RTC_HOUR_12(param)     ((param) <= 11U)
#define IS_RTC_MINUTE(param)      ((param) <= 59U)
#define IS_RTC_SECOND(param)      ((param) <= 59U)

/** @} */
/* End of group RTC_Exported_Constants */

/** @defgroup RTC_Exported_Types
  * @{
  */

    typedef enum {
        RTC_NO_REQ = 0U,
        RTC_REQ = 1U
    } RTC_ReqState;

    typedef enum {
        RTC_CLOCK_MODE = 0U,
        RTC_ALARM_MODE = !RTC_CLOCK_MODE
    } RTC_FuncMode;
#define IS_RTC_FUNC_MODE(param)       (((param) == RTC_CLOCK_MODE) || \
                                       ((param) == RTC_ALARM_MODE))

/** @} */
/* End of group RTC_Exported_Types */

/** @defgroup RTC_Exported_FunctionPrototypes
  * @{
  */

    void RTC_SetSec(uint8_t Sec);
    uint8_t RTC_GetSec(void);
    void RTC_SetMin(RTC_FuncMode NewMode, uint8_t Min);
    uint8_t RTC_GetMin(RTC_FuncMode NewMode);
    uint8_t RTC_GetAMPM(RTC_FuncMode NewMode);
    void RTC_SetHour24(RTC_FuncMode NewMode, uint8_t Hour);
    void RTC_SetHour12(RTC_FuncMode NewMode, uint8_t Hour, uint8_t AmPm);
    uint8_t RTC_GetHour(RTC_FuncMode NewMode);
    void RTC_SetDay(RTC_FuncMode NewMode, uint8_t Day);
    uint8_t RTC_GetDay(RTC_FuncMode NewMode);
    void RTC_SetDate(RTC_FuncMode NewMode, uint8_t Date);
    uint8_t RTC_GetDate(RTC_FuncMode NewMode);
    void RTC_SetMonth(uint8_t Month);
    uint8_t RTC_GetMonth(void);
    void RTC_SetYear(uint8_t Year);
    uint8_t RTC_GetYear(void);
    void RTC_SetHourMode(uint8_t HourMode);
    uint8_t RTC_GetHourMode(void);
    void RTC_SetLeapYear(uint8_t LeapYear);
    uint8_t RTC_GetLeapYear(void);
    void RTC_SetTimeAdjustReq(void);
    RTC_ReqState RTC_GetTimeAdjustReq(void);
    void RTC_EnableClock(void);
    void RTC_DisableClock(void);
    void RTC_EnableAlarm(void);
    void RTC_DisableAlarm(void);
    void RTC_SetRTCINT(FunctionalState NewState);
    void RTC_SetAlarmOutput(uint8_t Output);
    void RTC_ResetClockSec(void);
    RTC_ReqState RTC_GetResetClockSecReq(void);
    void RTC_ResetAlarm(void);
    void RTC_SetDateValue(RTC_DateTypeDef * DateStruct);
    void RTC_GetDateValue(RTC_DateTypeDef * DateStruct);
    void RTC_SetTimeValue(RTC_TimeTypeDef * TimeStruct);
    void RTC_GetTimeValue(RTC_TimeTypeDef * TimeStruct);
    void RTC_SetClockValue(RTC_DateTypeDef * DateStruct, RTC_TimeTypeDef * TimeStruct);
    void RTC_GetClockValue(RTC_DateTypeDef * DateStruct, RTC_TimeTypeDef * TimeStruct);
    void RTC_SetAlarmValue(RTC_AlarmTypeDef * AlarmStruct);
    void RTC_GetAlarmValue(RTC_AlarmTypeDef * AlarmStruct);

/** @} */
/* End of group RTC_Exported_FunctionPrototype */

/** @} */
/* End of group RTC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined (__TMPM330_RTC_H) || (__TMPM332_RTC_H) || (__TMPM333_RTC_H) */
#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM333_RTC_H */
