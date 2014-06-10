/**************************************************************************//**
 * @file     RTC.h
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 12/08/06 8:08p $
 * @brief    NUC200 Series Real Time Clock Timer Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __RTC_H__
#define __RTC_H__

#include "NUC200Series.h"

/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup RTC_FUNC RTC Device Function Interface
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* INIR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_INIR_VALUE              0xA5EB1357UL  /*!< RTC Initiation value to make RTC leaving reset state */


/*---------------------------------------------------------------------------------------------------------*/
/* AER Constants Definitions                                                                               */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_AER_VALUE               0x0000A965UL  /*!< RTC AER value to enable RTC access and keep 1024 RTC clock */


/*---------------------------------------------------------------------------------------------------------*/
/* FCR Constants Definitions                                                                               */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_FCR_INTEGER(x)          ((32776 - (x)) << RTC_FCR_INTEGER_Pos) /*!< x is integer part of detected RTC frequency and 32761 <= x <= 32776 */
#define RTC_FCR_FRACTION(x)         ((uint32_t)((x) * 60))                 /*!< x is fraction part of detected RTC frequency */
                                                            

/*---------------------------------------------------------------------------------------------------------*/
/* Time Data Constants Definitions                                                                         */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_TIME_10HR(x)            ((x) << RTC_TLR_10HR_Pos)  /*!< 10-Hour Time Digit of Current/Alarm Time, 0 <= x <= 2 */
#define RTC_TIME_1HR(x)             ((x) << RTC_TLR_1HR_Pos)   /*!< 1-Hour Time Digit of Current/Alarm Time, 0 <= x <= 9 */
#define RTC_TIME_10MIN(x)           ((x) << RTC_TLR_10MIN_Pos) /*!< 10-Min Time Digit of Current/Alarm Time, 0 <= x <= 5 */
#define RTC_TIME_1MIN(x)            ((x) << RTC_TLR_1MIN_Pos)  /*!< 1-Min Time Digit of Current/Alarm Time, 0 <= x <= 9 */
#define RTC_TIME_10SEC(x)           ((x) << RTC_TLR_10SEC_Pos) /*!< 10-Sec Time Digit of Current/Alarm Time, 0 <= x <= 5 */
#define RTC_TIME_1SEC(x)            ((x) << RTC_TLR_1SEC_Pos)  /*!< 1-Sec Time Digit of Current/Alarm Time, 0 <= x <= 9 */


/*---------------------------------------------------------------------------------------------------------*/
/* Calendar Data Constants Definitions                                                                     */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_CALENDAR_10YEAR(x)      ((x) << RTC_CLR_10YEAR_Pos) /*!< 10-Year Calendar Digit of Current/Alarm Calendar, 0 <= x <= 9 */
#define RTC_CALENDAR_1YEAR(x)       ((x) << RTC_CLR_1YEAR_Pos)  /*!< 1-Year Calendar Digit of Current/Alarm Calendar, 0 <= x <= 9 */
#define RTC_CALENDAR_10MON(x)       ((x) << RTC_CLR_10MON_Pos)  /*!< 10-Month Calendar Digit of Current/Alarm Calendar, 0 <= x <= 1 */
#define RTC_CALENDAR_1MON(x)        ((x) << RTC_CLR_1MON_Pos)   /*!< 1-Month Calendar Digit of Current/Alarm Calendar, 0 <= x <= 9 */
#define RTC_CALENDAR_10DAY(x)       ((x) << RTC_CLR_10DAY_Pos)  /*!< 10-Day Calendar Digit of Current/Alarm Calendar, 0 <= x <= 3 */
#define RTC_CALENDAR_1DAY(x)        ((x) << RTC_CLR_1DAY_Pos)   /*!< 1-Day Calendar Digit of Current/Alarm Calendar, 0 <= x <= 9 */


/*---------------------------------------------------------------------------------------------------------*/
/* TSSR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_TSSR_12H                0x0UL /*!< Selected as 12-hour time scale with AM and PM indication */
#define RTC_TSSR_24H                0x1UL /*!< Selected as 24-hour time scale */


/*---------------------------------------------------------------------------------------------------------*/
/* DWR Constants Definitions                                                                               */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_DWR_SUNDAY              0x0UL /*!< Day of the Week is Sunday */
#define RTC_DWR_MONDAY              0x1UL /*!< Day of the Week is Monday */
#define RTC_DWR_TUESDAY             0x2UL /*!< Day of the Week is Tuesday */
#define RTC_DWR_WEDNESDAY           0x3UL /*!< Day of the Week is Wednesday */
#define RTC_DWR_THURSDAY            0x4UL /*!< Day of the Week is Thursday */
#define RTC_DWR_FRIDAY              0x5UL /*!< Day of the Week is Friday */
#define RTC_DWR_SATURDAY            0x6UL /*!< Day of the Week is Saturday */


/*---------------------------------------------------------------------------------------------------------*/
/* RIER Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_RIER_AIER_ENABLE        0x01UL /*!< Alarm Interrupt Enable */
#define RTC_RIER_AIER_DISABLE       0x00UL /*!< Alarm Interrupt Disable */
#define RTC_RIER_TIER_ENABLE        0x02UL /*!< Time Tick Interrupt Enable */
#define RTC_RIER_TIER_DISABLE       0x00UL /*!< Time Tick Interrupt Disable */


/*---------------------------------------------------------------------------------------------------------*/
/* TTR Constants Definitions                                                                               */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_TTR_1                   0x00UL /*!< RTC time tick period is 1 sec */
#define RTC_TTR_1DIV2               0x01UL /*!< RTC time tick period is 1/2 sec */
#define RTC_TTR_1DIV4               0x02UL /*!< RTC time tick period is 1/4 sec */
#define RTC_TTR_1DIV8               0x03UL /*!< RTC time tick period is 1/8 sec */
#define RTC_TTR_1DIV16              0x04UL /*!< RTC time tick period is 1/16 sec */
#define RTC_TTR_1DIV32              0x05UL /*!< RTC time tick period is 1/32 sec */
#define RTC_TTR_1DIV64              0x06UL /*!< RTC time tick period is 1/64 sec */
#define RTC_TTR_1DIV128             0x07UL /*!< RTC time tick period is 1/128 sec */


/*---------------------------------------------------------------------------------------------------------*/
/* RTC Macro Definitions                                                                                   */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     Initial RTC and run at normal active state
 */
#define _RTC_INIT()                         (RTC->INIR = RTC_INIR_VALUE)


/**
 * @details     To check if RTC is at normal active state or not
 */
#define _RTC_IS_ACTIVE()                    ((RTC->INIR == 1)? 1:0)


/**
 * @details     Enable RTC access and will keep 1024 RTC clock
 */
#define _RTC_ENABLE_AER()                   (RTC->AER = RTC_AER_VALUE)


/**
 * @details     To check if AER is enabled for read/write or not
 */
#define _RTC_IS_AER_ENABLE()                (((RTC->AER & RTC_AER_ENF_Msk) == RTC_AER_ENF_Msk)? 1:0) 


/**
 * @brief       Set RTC Frequency Compensation
 *
 * @param[in]   integer     Integer part of detected RTC frequency and 32761 <= integer <= 32776.
 * @param[in]   fraction    Fraction part of detected RTC frequency.
 *
 * @return      None
 *
 * @details     Set RTC frequency compensation of detected frequency.
 */
#define _RTC_SET_FCR(integer, fraction)     (RTC->FCR = (RTC_FCR_INTEGER(integer) | RTC_FCR_FRACTION(fraction)))


/**
 * @details     Get RTC Hour Data in 24-Hour Mode
 */
#define _RTC_GET_HOUR()                     (((_GET_BYTE2(RTC->TLR) >> 4) * 10) + (_GET_BYTE2(RTC->TLR) & 0xF))


/**
 * @details     Get RTC Min Data
 */
#define _RTC_GET_MIN()                      (((_GET_BYTE1(RTC->TLR) >> 4) * 10) + (_GET_BYTE1(RTC->TLR) & 0xF))


/**
 * @details     Get RTC Sec Data
 */
#define _RTC_GET_SEC()                      (((_GET_BYTE0(RTC->TLR) >> 4) * 10) + (_GET_BYTE0(RTC->TLR) & 0xF))


/**
 * @details     Get RTC Year Data
 */
#define _RTC_GET_YEAR()                     (((_GET_BYTE2(RTC->CLR) >> 4) * 10) + (_GET_BYTE2(RTC->CLR) & 0xF))


/**
 * @details     Get RTC Mon Data
 */
#define _RTC_GET_MON()                      (((_GET_BYTE1(RTC->CLR) >> 4) * 10) + (_GET_BYTE1(RTC->CLR) & 0xF))


/**
 * @details     Get RTC Day Data
 */
#define _RTC_GET_DAY()                      (((_GET_BYTE0(RTC->CLR) >> 4) * 10) + (_GET_BYTE0(RTC->CLR) & 0xF))


/**
 * @details     Get RTC Alarm Hour Data in 24-Hour Mode
 */
#define _RTC_GET_ALARM_HOUR()               (((_GET_BYTE2(RTC->TAR) >> 4) * 10) + (_GET_BYTE2(RTC->TAR) & 0xF))


/**
 * @details     Get RTC Alarm Min Data
 */
#define _RTC_GET_ALARM_MIN()                (((_GET_BYTE1(RTC->TAR) >> 4) * 10) + (_GET_BYTE1(RTC->TAR) & 0xF))


/**
 * @details     Get RTC Alarm Sec Data
 */
#define _RTC_GET_ALARM_SEC()                (((_GET_BYTE0(RTC->TAR) >> 4) * 10) + (_GET_BYTE0(RTC->TAR) & 0xF))


/**
 * @details     Get RTC Alarm Year Data
 */
#define _RTC_GET_ALARM_YEAR()               (((_GET_BYTE2(RTC->CAR) >> 4) * 10) + (_GET_BYTE2(RTC->CAR) & 0xF))


/**
 * @details     Get RTC Alarm Mon Data
 */
#define _RTC_GET_ALARM_MON()                (((_GET_BYTE1(RTC->CAR) >> 4) * 10) + (_GET_BYTE1(RTC->CAR) & 0xF))


/**
 * @details     Get RTC Alarm Day Data
 */
#define _RTC_GET_ALARM_DAY()                (((_GET_BYTE0(RTC->CAR) >> 4) * 10) + (_GET_BYTE0(RTC->CAR) & 0xF))


/**
 * @brief       Set RTC Day of the Week 
 *
 * @param[in]   fraction    Fraction part of detected RTC frequency.
 * @param[in]   dwr         Specify RTC day of the week. It could be \n
 *                          RTC_DWR_SUNDAY, RTC_DWR_MONDAY, RTC_DWR_TUESDAY, RTC_DWR_WEDNESDAY, \n
 *                          RTC_DWR_THURSDAY, RTC_DWR_FRIDAY, RTC_DWR_SATURDAY.
 *
 * @return      None
 *
 * @details     Set current RTC Day of the Week.
 */
#define _RTC_SET_DWR(dwr)                   (RTC->DWR = (dwr))


/**
 * @details     Get RTC Day of the Week
 */
#define _RTC_GET_DWR()                      (RTC->DWR)


/**
 * @details     Enable RTC Alarm Interrupt
 */
#define _RTC_ALARM_INT_ENABLE()             (RTC->RIER |= RTC_RIER_AIER_ENABLE)


/**
 * @details     Disable RTC Alarm Interrupt
 */
#define _RTC_ALARM_INT_DISABLE()            (RTC->RIER &= ~RTC_RIER_AIER_Msk)


/**
 * @details     Enable RTC Tick Interrupt
 */
#define _RTC_TICK_INT_ENABLE()              (RTC->RIER |= RTC_RIER_TIER_ENABLE)


/**
 * @details     Disable RTC Tick Interrupt
 */
#define _RTC_TICK_INT_DISABLE()             (RTC->RIER &= ~RTC_RIER_TIER_Msk)


/**
 * @details     Get RTC Alarm Interrupt Flag
 */
#define _RTC_GET_ALARM_INT_FLAG()           (((RTC->RIIR & RTC_RIIR_AIF_Msk) == RTC_RIIR_AIF_Msk)? 1:0)


/**
 * @details     Clear RTC Alarm Interrupt Flag
 */
#define _RTC_CLEAR_ALARM_INT_FLAG()         (RTC->RIIR = RTC_RIIR_AIF_Msk)
                                               

/**
 * @details     Get RTC Tick Interrupt Flag
 */
#define _RTC_GET_TICK_INT_FLAG()            (((RTC->RIIR & RTC_RIIR_TIF_Msk) == RTC_RIIR_TIF_Msk)? 1:0)


/**
 * @details     Clear RTC Tick Interrupt Flag
 */
#define _RTC_CLEAR_TICK_INT_FLAG()          (RTC->RIIR = RTC_RIIR_TIF_Msk)
                                               

/**
 * @brief       Set RTC Time Tick Period 
 *
 * @param[in]   ttr         Specify RTC time tick period. It could be \n
 *                          RTC_TTR_1, RTC_TTR_1DIV2, RTC_TTR_1DIV4, RTC_TTR_1DIV8, \n
 *                          RTC_TTR_1DIV16, RTC_TTR_1DIV32, RTC_TTR_1DIV64 and RTC_TTR_1DIV128.
 *
 * @return      None
 *
 * @details     Set current RTC Day of the Week.
 */
#define _RTC_SET_TTR(ttr)                   (RTC->TTR = (ttr))


/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Set RTC Time
 *
 * @param[in]   u32Hour     Specify RTC Hour data in 24-Hour mode
 * @param[in]   u32Min      Specify RTC Min data
 * @param[in]   u32Sec      Specify RTC Sec data
 *
 * @return      None
 *
 * @details     Set current RTC Time in 24-Hour mode.
 */
static __INLINE void RTC_SetCurrentTime(uint32_t u32Hour, uint32_t u32Min, uint32_t u32Sec)
{
    RTC->TSSR = RTC_TSSR_24H;

    RTC->TLR = RTC_TIME_10HR(u32Hour/10) | RTC_TIME_1HR(u32Hour%10) |
               RTC_TIME_10MIN(u32Min/10) | RTC_TIME_1MIN(u32Min%10) |
               RTC_TIME_10SEC(u32Sec/10) | RTC_TIME_1SEC(u32Sec%10);
}


/**
 * @brief       Set RTC Calendar
 *
 * @param[in]   u32Year     Specify RTC Year data and 0 <= u32Year <= 99
 * @param[in]   u32Mon      Specify RTC Mon data
 * @param[in]   u32Day      Specify RTC Day data
 *
 * @return      None
 *
 * @details     Set current RTC Calendar.
 */
static __INLINE void RTC_SetCurrentCalendar(uint32_t u32Year, uint32_t u32Mon, uint32_t u32Day)
{
    RTC->CLR = RTC_CALENDAR_10YEAR(u32Year/10) | RTC_CALENDAR_1YEAR(u32Year%10) |
               RTC_CALENDAR_10MON(u32Mon/10)   | RTC_CALENDAR_1MON(u32Mon%10)   |
               RTC_CALENDAR_10DAY(u32Day/10)   | RTC_CALENDAR_1DAY(u32Day%10);
}


/**
 * @brief       Set RTC Alarm Time
 *
 * @param[in]   u32Hour     Specify RTC Alarm Hour data in 24-Hour mode
 * @param[in]   u32Mon      Specify RTC Alarm Mon data
 * @param[in]   u32Day      Specify RTC Alarm Day data
 *
 * @return      None
 *
 * @details     Set current RTC Alarm Time in 24-Hour mode.
 */
static __INLINE void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Min, uint32_t u32Sec)
{
    RTC->TSSR = RTC_TSSR_24H;

    RTC->TAR = RTC_TIME_10HR(u32Hour/10) | RTC_TIME_1HR(u32Hour%10) |
               RTC_TIME_10MIN(u32Min/10) | RTC_TIME_1MIN(u32Min%10) |
               RTC_TIME_10SEC(u32Sec/10) | RTC_TIME_1SEC(u32Sec%10);
}


/**
 * @brief       Set RTC Alarm Calendar
 *
 * @param[in]   u32Year     Specify RTC Alarm Year data and 0 <= u32Year <= 99
 * @param[in]   u32Mon      Specify RTC Alarm Mon data
 * @param[in]   u32Day      Specify RTC Alarm Day data
 *
 * @return      None
 *
 * @details     Set current RTC Alarm Calendar.
 */
static __INLINE void RTC_SetAlarmCalendar(uint32_t u32Year, uint32_t u32Mon, uint32_t u32Day)
{
    RTC->CAR = RTC_CALENDAR_10YEAR(u32Year/10) | RTC_CALENDAR_1YEAR(u32Year%10) |
               RTC_CALENDAR_10MON(u32Mon/10)   | RTC_CALENDAR_1MON(u32Mon%10)   |
               RTC_CALENDAR_10DAY(u32Day/10)   | RTC_CALENDAR_1DAY(u32Day%10);
}


/**
 * @brief       Wait RTC AER Enable
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Wait RCT AER bit enable for access RTC registers.
 */
static __INLINE void RTC_WaitAccessEnable(void)
{
    /* Wait AER disabled and enable AER again */
    while (_RTC_IS_AER_ENABLE() == 1);
    _RTC_ENABLE_AER();

    /* Check if AER has enabled for accress RTC registers */
    while (_RTC_IS_AER_ENABLE() == 0);
}


/**
  * @} End of RTC Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 


#endif  // __RTC_H__ 
