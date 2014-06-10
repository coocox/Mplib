/**************************************************************************//**
 * @file     rtc.c
 * @version  V1.00
 * $Revision: 10 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 series RTC driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/


#include <stdio.h>
#include "rtc.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Includes of local headers                                                                               */
/*---------------------------------------------------------------------------------------------------------*/



/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_RTC_Driver RTC Driver
  @{
*/
/// @cond HIDDEN_SYMBOLS

/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define RTC_GLOBALS

/*---------------------------------------------------------------------------------------------------------*/
/* Global file scope (static) variables                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
static volatile uint32_t g_u32Reg, g_u32Reg1,g_u32hiYear,g_u32loYear,g_u32hiMonth,g_u32loMonth,g_u32hiDay,g_u32loDay;
static volatile uint32_t g_u32hiHour,g_u32loHour,g_u32hiMin,g_u32loMin,g_u32hiSec,g_u32loSec;

/// @endcond HIDDEN_SYMBOLS

/** @addtogroup NUC400_RTC_EXPORTED_FUNCTIONS RTC Exported Functions
  @{
*/


/**
 *  @brief    Set Frequency Compensation Data
 *
 *  @param    i32FrequencyX100    Specify the RTC clock X100, ex: 3277365 means 32773.65.
 *
 *  @return   None
 *
 */
void RTC_32KCalibration(int32_t i32FrequencyX100)
{
    int32_t i32RegInt,i32RegFra ;

    /* Compute Integer and Fraction for RTC register*/
    i32RegInt = (i32FrequencyX100/100) - RTC_FCR_REFERENCE;
    i32RegFra = (((i32FrequencyX100%100)) * 60) / 100;

    /* Judge Integer part is reasonable */
    if ( (i32RegInt < 0) | (i32RegInt > 15) ) {
        return;
    }

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->FCR = (uint32_t)((i32RegInt<<8) | i32RegFra);

}

/**
 *  @brief    This function is used to: \n
 *            1. Write initial key to let RTC start count.  \n
 *            2. Input parameter indicates start time.      \n
 *            Null pointer for using default starting time. \n
 *
 *  @param    sPt \n
 *                     Specify the time property and current time. It includes:                          \n
 *                     u32Year: Year value.                                                               \n
 *                     u32Month: Month value.                                                             \n
 *                     u32Day: Day value.                                                                 \n
 *                     u32DayOfWeek: Day of week. [RTC_SUNDAY / RTC_MONDAY / RTC_TUESDAY /
 *                                                 RTC_WEDNESDAY / RTC_THURSDAY / RTC_FRIDAY /
 *                                                 RTC_SATURDAY]                                       \n
 *                     u32Hour: Hour value.                                                               \n
 *                     u32Minute: Minute value.                                                           \n
 *                     u32Second: Second value.                                                           \n
 *                     u32TimeScale: [RTC_CLOCK_12 / RTC_CLOCK_24]                                  \n
 *                     u8AmPm: [RTC_AM / RTC_PM]                                                    \n
 *
 *  @return   None
 *
 */
void RTC_Open (S_RTC_TIME_DATA_T *sPt)
{
    uint32_t u32Reg;

    volatile int32_t i32delay=1000;

    if(RTC->INIR != 0x1) {
        RTC->INIR = RTC_INIT_KEY;

        while(RTC->INIR != 0x1);
    }

    if(sPt == NULL)
        return;

    /*-----------------------------------------------------------------------------------------------------*/
    /* Second, set RTC 24/12 hour setting                                                                  */
    /*-----------------------------------------------------------------------------------------------------*/
    if (sPt->u32TimeScale == RTC_CLOCK_12) {
        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));
        RTC->TSSR &= ~RTC_TSSR_24H_12H_Msk;

        /*-------------------------------------------------------------------------------------------------*/
        /* important, range of 12-hour PM mode is 21 up to 32                                               */
        /*-------------------------------------------------------------------------------------------------*/
        if (sPt->u32AmPm == RTC_PM)
            sPt->u32Hour += 20;
    } else {                                                                           /* RTC_CLOCK_24 */
        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));
        RTC->TSSR |= RTC_TSSR_24H_12H_Msk;
    }

    /*-----------------------------------------------------------------------------------------------------*/
    /* Set RTC Calender Loading                                                                            */
    /*-----------------------------------------------------------------------------------------------------*/
    u32Reg     = ((sPt->u32Year - RTC_YEAR2000) / 10) << 20;
    u32Reg    |= (((sPt->u32Year - RTC_YEAR2000) % 10) << 16);
    u32Reg    |= ((sPt->u32Month  / 10) << 12);
    u32Reg    |= ((sPt->u32Month  % 10) << 8);
    u32Reg    |= ((sPt->u32Day    / 10) << 4);
    u32Reg    |= (sPt->u32Day     % 10);
    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->CLR = (uint32_t)g_u32Reg;

    /*-----------------------------------------------------------------------------------------------------*/
    /* Set RTC Time Loading                                                                                */
    /*-----------------------------------------------------------------------------------------------------*/
    u32Reg     = ((sPt->u32Hour / 10) << 20);
    u32Reg    |= ((sPt->u32Hour % 10) << 16);
    u32Reg    |= ((sPt->u32Minute / 10) << 12);
    u32Reg    |= ((sPt->u32Minute % 10) << 8);
    u32Reg    |= ((sPt->u32Second / 10) << 4);
    u32Reg    |= (sPt->u32Second % 10);
    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TLR = (uint32_t)g_u32Reg;

    RTC->DWR = sPt->u32DayOfWeek;

    /* Waiting for RTC settings stable */
    while(i32delay--);

}

/**
 *  @brief    Read current date/time from RTC setting
 *
 *  @param    sPt \n
 *                     Specify the time property and current time. It includes: \n
 *                     u32Year: Year value                                      \n
 *                     u32Month: Month value                                    \n
 *                     u32Day: Day value                                        \n
 *                     u32DayOfWeek: Day of week                                \n
 *                     u32Hour: Hour value                                      \n
 *                     u32Minute: Minute value                                  \n
 *                     u32Second: Second value                                  \n
 *                     u32TimeScale: RTC_CLOCK_12 / RTC_CLOCK_24          \n
 *                     u8AmPm: RTC_AM / RTC_PM                            \n
 *
 *  @return   None
 *
 */
void RTC_GetDatAndTime(S_RTC_TIME_DATA_T *sPt)
{
    uint32_t u32Tmp;

    sPt->u32TimeScale = RTC->TSSR & RTC_TSSR_24H_12H_Msk;    /* 12/24-hour */
    sPt->u32DayOfWeek = RTC->DWR & RTC_DWR_DWR_Msk;          /* Day of week */

    g_u32hiYear  = (RTC->CLR & RTC_CLR_10YEAR_Msk) >> RTC_CLR_10YEAR_Pos;
    g_u32loYear  = (RTC->CLR & RTC_CLR_1YEAR_Msk) >> RTC_CLR_1YEAR_Pos;
    g_u32hiMonth = (RTC->CLR & RTC_CLR_10MON_Msk) >> RTC_CLR_10MON_Pos;
    g_u32loMonth = (RTC->CLR & RTC_CLR_1MON_Msk) >> RTC_CLR_1MON_Pos;
    g_u32hiDay   = (RTC->CLR & RTC_CLR_10DAY_Msk) >> RTC_CLR_10DAY_Pos;
    g_u32loDay   = (RTC->CLR & RTC_CLR_1DAY_Msk);

    g_u32hiHour =  (RTC->TLR & RTC_TLR_10HR_Msk) >> RTC_TLR_10HR_Pos;
    g_u32loHour =  (RTC->TLR & RTC_TLR_1HR_Msk) >> RTC_TLR_1HR_Pos;
    g_u32hiMin  =  (RTC->TLR & RTC_TLR_10MIN_Msk) >> RTC_TLR_10MIN_Pos;
    g_u32loMin  =  (RTC->TLR & RTC_TLR_1MIN_Msk) >> RTC_TLR_1MIN_Pos;
    g_u32hiSec  =  (RTC->TLR & RTC_TLR_10SEC_Msk) >> RTC_TLR_10SEC_Pos;
    g_u32loSec  =  (RTC->TLR & RTC_TLR_1SEC_Msk);

    u32Tmp  = (g_u32hiYear * 10);              /* Compute to 20XX year */
    u32Tmp += g_u32loYear;
    sPt->u32Year = u32Tmp + RTC_YEAR2000;

    u32Tmp = (g_u32hiMonth * 10);              /* Compute 0~12 month */
    sPt->u32Month = u32Tmp + g_u32loMonth;

    u32Tmp = (g_u32hiDay * 10);                /* Compute 0~31 day */
    sPt->u32Day   =  u32Tmp  + g_u32loDay;

    if (sPt->u32TimeScale == RTC_CLOCK_12) { /* Compute12/24 hour */
        u32Tmp = (g_u32hiHour * 10);
        u32Tmp+= g_u32loHour;
        sPt->u32Hour = u32Tmp;                 /* AM: 1~12. PM: 21~32. */

        if (sPt->u32Hour >= 21) {
            sPt->u32AmPm = RTC_PM;
            sPt->u32Hour -= 20;
        } else {
            sPt->u32AmPm = RTC_AM;
        }

        u32Tmp = (g_u32hiMin  * 10);
        u32Tmp+= g_u32loMin;
        sPt->u32Minute = u32Tmp;

        u32Tmp = (g_u32hiSec  * 10);
        u32Tmp+= g_u32loSec;
        sPt->u32Second = u32Tmp;

    } else {
        /* RTC_CLOCK_24 */
        u32Tmp  = (g_u32hiHour * 10);
        u32Tmp += g_u32loHour;
        sPt->u32Hour = u32Tmp;

        u32Tmp  = (g_u32hiMin * 10);
        u32Tmp +=  g_u32loMin;
        sPt->u32Minute = u32Tmp;

        u32Tmp  = (g_u32hiSec * 10);
        u32Tmp += g_u32loSec;
        sPt->u32Second = u32Tmp;
    }

}



/**
 *  @brief    Read alarm date/time from RTC setting
 *
 *  @param    sPt \n
 *                     Specify the time property and current time. It includes: \n
 *                     u32Year: Year value                                      \n
 *                     u32Month: Month value                                    \n
 *                     u32Day: Day value                                        \n
 *                     u32DayOfWeek: Day of week                                \n
 *                     u32Hour: Hour value                                      \n
 *                     u32Minute: Minute value                                  \n
 *                     u32Second: Second value                                  \n
 *                     u32TimeScale: RTC_CLOCK_12 / RTC_CLOCK_24          \n
 *                     u8AmPm: RTC_AM / RTC_PM                            \n
 *
 *  @return   None
 *
 */
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt)
{
    uint32_t u32Tmp;

    sPt->u32TimeScale = RTC->TSSR & RTC_TSSR_24H_12H_Msk;  /* 12/24-hour */
    sPt->u32DayOfWeek = RTC->DWR & RTC_DWR_DWR_Msk;        /* Day of week */

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    g_u32hiYear  = (RTC->CAR & RTC_CAR_10YEAR_Msk) >> RTC_CAR_10YEAR_Pos;
    g_u32loYear  = (RTC->CAR & RTC_CAR_1YEAR_Msk)  >> RTC_CAR_1YEAR_Pos;
    g_u32hiMonth = (RTC->CAR & RTC_CAR_10MON_Msk)  >> RTC_CAR_10MON_Pos;
    g_u32loMonth = (RTC->CAR & RTC_CAR_1MON_Msk)   >> RTC_CAR_1MON_Pos;
    g_u32hiDay   = (RTC->CAR & RTC_CAR_10DAY_Msk)  >> RTC_CAR_10DAY_Pos;
    g_u32loDay   = (RTC->CAR & RTC_CAR_1DAY_Msk);

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    g_u32hiHour =  (RTC->TAR & RTC_TAR_10HR_Msk)  >> RTC_TAR_10HR_Pos;
    g_u32loHour =  (RTC->TAR & RTC_TAR_1HR_Msk)   >> RTC_TAR_1HR_Pos;
    g_u32hiMin    =  (RTC->TAR & RTC_TAR_10MIN_Msk) >> RTC_TAR_10MIN_Pos;
    g_u32loMin    =  (RTC->TAR & RTC_TAR_1MIN_Msk)  >> RTC_TAR_1MIN_Pos;
    g_u32hiSec    =  (RTC->TAR & RTC_TAR_10SEC_Msk) >> RTC_TAR_10SEC_Pos;
    g_u32loSec    =  (RTC->TAR & RTC_TAR_1SEC_Msk);

    u32Tmp  = (g_u32hiYear * 10);                                    /* Compute to 20XX year */
    u32Tmp += g_u32loYear;
    sPt->u32Year = u32Tmp + RTC_YEAR2000;

    u32Tmp = (g_u32hiMonth * 10);                                    /* Compute 0~12 month */
    sPt->u32Month = u32Tmp + g_u32loMonth;

    u32Tmp = (g_u32hiDay * 10);                                        /* Compute 0~31 day */
    sPt->u32Day = u32Tmp + g_u32loDay;

    if (sPt->u32TimeScale == RTC_CLOCK_12) {                /* Compute12/24 hour */
        u32Tmp  = (g_u32hiHour * 10);
        u32Tmp += g_u32loHour;
        sPt->u32Hour = u32Tmp;                                        /* AM: 1~12. PM: 21~32. */

        if (sPt->u32Hour >= 21) {
            sPt->u32AmPm  = RTC_PM;
            sPt->u32Hour -= 20;
        } else {
            sPt->u32AmPm = RTC_AM;
        }

        u32Tmp  = (g_u32hiMin * 10);
        u32Tmp += g_u32loMin;
        sPt->u32Minute = u32Tmp;

        u32Tmp  = (g_u32hiSec * 10);
        u32Tmp += g_u32loSec;
        sPt->u32Second = u32Tmp;

    } else {
        /* RTC_CLOCK_24 */
        u32Tmp  = (g_u32hiHour * 10);
        u32Tmp +=  g_u32loHour;
        sPt->u32Hour = u32Tmp;

        u32Tmp = (g_u32hiMin * 10);
        u32Tmp+= g_u32loMin;
        sPt->u32Minute = u32Tmp;

        u32Tmp  = (g_u32hiSec * 10);
        u32Tmp += g_u32loSec;
        sPt->u32Second = u32Tmp;
    }

}



/**
 *  @brief    This function is used to update date/time to RTC.
 *
 *  @param    sPt \n
 *                     Specify the time property and current time. It includes:                          \n
 *                     u32Year: Year value.                                                               \n
 *                     u32Month: Month value.                                                             \n
 *                     u32Day: Day value.                                                                 \n
 *                     u32DayOfWeek: Day of week. [RTC_SUNDAY / RTC_MONDAY / RTC_TUESDAY /
 *                                                 RTC_WEDNESDAY / RTC_THURSDAY / RTC_FRIDAY /
 *                                                 RTC_SATURDAY]                                       \n
 *                     u32Hour: Hour value.                                                               \n
 *                     u32Minute: Minute value.                                                           \n
 *                     u32Second: Second value.                                                           \n
 *                     u32TimeScale: [RTC_CLOCK_12 / RTC_CLOCK_24]                                  \n
 *                     u8AmPm: [RTC_AM / RTC_PM]                                                    \n
 *
 *
 *  @return   None
 *
 *
 */
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt)
{
    uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if (sPt->u32TimeScale == RTC_CLOCK_12) {
        RTC->TSSR &= ~RTC_TSSR_24H_12H_Msk;

        /*-----------------------------------------------------------------------------------------*/
        /* important, range of 12-hour PM mode is 21 up to 32                                       */
        /*-----------------------------------------------------------------------------------------*/
        if (sPt->u32AmPm == RTC_PM)
            sPt->u32Hour += 20;
    } else {                                                              /* RTC_CLOCK_24 */
        RTC->TSSR |= RTC_TSSR_24H_12H_Msk;
    }

    RTC->DWR = sPt->u32DayOfWeek & RTC_DWR_DWR_Msk;

    u32Reg     = ((sPt->u32Year - RTC_YEAR2000) / 10) << 20;
    u32Reg    |= (((sPt->u32Year - RTC_YEAR2000) % 10) << 16);
    u32Reg    |= ((sPt->u32Month  / 10) << 12);
    u32Reg    |= ((sPt->u32Month  % 10) << 8);
    u32Reg    |= ((sPt->u32Day    / 10) << 4);
    u32Reg    |=  (sPt->u32Day    % 10);
    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->CLR = (uint32_t)g_u32Reg;

    u32Reg     = ((sPt->u32Hour   / 10) << 20);
    u32Reg    |= ((sPt->u32Hour   % 10) << 16);
    u32Reg    |= ((sPt->u32Minute / 10) << 12);
    u32Reg    |= ((sPt->u32Minute % 10) << 8);
    u32Reg    |= ((sPt->u32Second / 10) << 4);
    u32Reg    |=  (sPt->u32Second % 10);
    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TLR = (uint32_t)g_u32Reg;

}

/**
 *  @brief    This function is used to set alarm date/time to RTC.
 *
 *  @param    sPt \n
 *                     Specify the time property and current time. It includes:                          \n
 *                     u32Year: Year value.                                                               \n
 *                     u32Month: Month value.                                                             \n
 *                     u32Day: Day value.                                                                 \n
 *                     u32DayOfWeek: Day of week. [RTC_SUNDAY / RTC_MONDAY / RTC_TUESDAY /
 *                                                 RTC_WEDNESDAY / RTC_THURSDAY / RTC_FRIDAY /
 *                                                 RTC_SATURDAY]                                       \n
 *                     u32Hour: Hour value.                                                               \n
 *                     u32Minute: Minute value.                                                           \n
 *                     u32Second: Second value.                                                           \n
 *                     u32TimeScale: [RTC_CLOCK_12 / RTC_CLOCK_24]                                  \n
 *                     u8AmPm: [RTC_AM / RTC_PM]                                                    \n
 *
 *  @return   None
 *
 */
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt)
{
    uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if (sPt->u32TimeScale == RTC_CLOCK_12) {
        RTC->TSSR &= ~RTC_TSSR_24H_12H_Msk;

        /*-----------------------------------------------------------------------------------------*/
        /* important, range of 12-hour PM mode is 21 up to 32                                       */
        /*-----------------------------------------------------------------------------------------*/
        if (sPt->u32AmPm == RTC_PM)
            sPt->u32Hour += 20;
    } else {                                                              /* RTC_CLOCK_24 */
        RTC->TSSR |= RTC_TSSR_24H_12H_Msk;
    }

    RTC->DWR = sPt->u32DayOfWeek & RTC_DWR_DWR_Msk;


    u32Reg     = ((sPt->u32Year - RTC_YEAR2000) / 10) << 20;
    u32Reg    |= (((sPt->u32Year - RTC_YEAR2000) % 10) << 16);
    u32Reg    |= ((sPt->u32Month  / 10) << 12);
    u32Reg    |= ((sPt->u32Month  % 10) << 8);
    u32Reg    |= ((sPt->u32Day     / 10) << 4);
    u32Reg    |=  (sPt->u32Day    % 10);
    g_u32Reg   = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->CAR = (uint32_t)g_u32Reg;

    u32Reg     = ((sPt->u32Hour   / 10) << 20);
    u32Reg    |= ((sPt->u32Hour   % 10) << 16);
    u32Reg    |= ((sPt->u32Minute / 10) << 12);
    u32Reg    |= ((sPt->u32Minute % 10) << 8);
    u32Reg    |= ((sPt->u32Second / 10) << 4);
    u32Reg    |=  (sPt->u32Second % 10);
    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TAR = (uint32_t)g_u32Reg;

}


/**
 *  @brief    This function is used to update date to RTC
 *
 *  @param    u32Year       The Year Calendar Digit of Alarm Setting
 *  @param    u32Month      The Month Calendar Digit of Alarm Setting
 *  @param    u32Day        The Day Calendar Digit of Alarm Setting
 *  @param    u32DayOfWeek  The Day of Week. [RTC_SUNDAY / RTC_MONDAY / RTC_TUESDAY /
 *                                            RTC_WEDNESDAY / RTC_THURSDAY / RTC_FRIDAY /
 *                                            RTC_SATURDAY]
 *
 *  @return   None
 *
 */
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek)
{
    __IO uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->DWR = u32DayOfWeek & RTC_DWR_DWR_Msk;

    u32Reg     = ((u32Year - RTC_YEAR2000) / 10) << 20;
    u32Reg    |= (((u32Year - RTC_YEAR2000) % 10) << 16);
    u32Reg    |= ((u32Month  / 10) << 12);
    u32Reg    |= ((u32Month  % 10) << 8);
    u32Reg    |= ((u32Day    / 10) << 4);
    u32Reg    |=  (u32Day    % 10);
    g_u32Reg   = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->CLR = (uint32_t)g_u32Reg;

}

/**
 *  @brief    This function is used to update time to RTC.
 *
 *  @param    u32Hour     The Hour Time Digit of Alarm Setting.
 *  @param    u32Minute   The Month Calendar Digit of Alarm Setting
 *  @param    u32Second   The Day Calendar Digit of Alarm Setting
 *  @param    u32TimeMode The 24-Hour / 12-Hour Time Scale Selection. [RTC_CLOCK_12 / RTC_CLOCK_24]
 *  @param    u32AmPm     12-hour time scale with AM and PM indication. Only Time Scale select 12-hour used. [RTC_AM / RTC_PM]
 *
 *  @return   None
 *
 */
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm)
{
    __IO uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if (u32TimeMode == RTC_CLOCK_12) {
        RTC->TSSR &= ~RTC_TSSR_24H_12H_Msk;

        if (u32AmPm == RTC_PM)    /* important, range of 12-hour PM mode is 21 up to 32 */
            u32Hour += 20;
    } else if(u32TimeMode == RTC_CLOCK_24) {
        RTC->TSSR |= RTC_TSSR_24H_12H_Msk;
    }

    u32Reg     = ((u32Hour   / 10) << 20);
    u32Reg    |= ((u32Hour   % 10) << 16);
    u32Reg    |= ((u32Minute / 10) << 12);
    u32Reg    |= ((u32Minute % 10) << 8);
    u32Reg    |= ((u32Second / 10) << 4);
    u32Reg    |=  (u32Second % 10);

    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TLR = (uint32_t)g_u32Reg;

}

/**
 *  @brief    This function is used to set alarm date to RTC
 *
 *  @param    u32Year    The Year Calendar Digit of Alarm Setting
 *  @param    u32Month   The Month Calendar Digit of Alarm Setting
 *  @param    u32Day     The Day Calendar Digit of Alarm Setting
 *
 *  @return   None
 *
 */
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day)
{
    __IO uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    u32Reg       = ((u32Year - RTC_YEAR2000) / 10) << 20;
    u32Reg      |= (((u32Year - RTC_YEAR2000) % 10) << 16);
    u32Reg      |= ((u32Month  / 10) << 12);
    u32Reg      |= ((u32Month  % 10) << 8);
    u32Reg      |= ((u32Day    / 10) << 4);
    u32Reg      |=  (u32Day    % 10);
    g_u32Reg   = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->CAR = (uint32_t)g_u32Reg;

}

/**
 *  @brief    This function is used to set alarm date to RTC
 *
 *  @param     u32Hour     The Hour Time Digit of Alarm Setting.
 *  @param     u32Minute   The Month Calendar Digit of Alarm Setting
 *  @param     u32Second   The Day Calendar Digit of Alarm Setting
 *  @param     u32TimeMode The 24-Hour / 12-Hour Time Scale Selection. [RTC_CLOCK_12 / RTC_CLOCK_24]
 *  @param     u32AmPm     12-hour time scale with AM and PM indication. Only Time Scale select 12-hour used. [RTC_AM / RTC_PM]
 *
 *  @return   None
 *
 */
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm)
{
    __IO uint32_t u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if (u32TimeMode == RTC_CLOCK_12) {
        RTC->TSSR &= ~RTC_TSSR_24H_12H_Msk;

        if (u32AmPm == RTC_PM)    /* important, range of 12-hour PM mode is 21 up to 32 */
            u32Hour += 20;
    } else if(u32TimeMode == RTC_CLOCK_24) {
        RTC->TSSR |= RTC_TSSR_24H_12H_Msk;
    }

    u32Reg     = ((u32Hour   / 10) << 20);
    u32Reg    |= ((u32Hour   % 10) << 16);
    u32Reg    |= ((u32Minute / 10) << 12);
    u32Reg    |= ((u32Minute % 10) <<  8);
    u32Reg    |= ((u32Second / 10) <<  4);
    u32Reg    |=  (u32Second % 10);

    g_u32Reg = u32Reg;

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TAR = (uint32_t)g_u32Reg;

}


/**
 *  @brief    The spare registers access enable
 *
 *  @return   None
 *
 */
void RTC_EnableSpareAccess(void)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->SPRCTL |= RTC_SPRCTL_SPREN_Msk;

    while(!(RTC->SPRCTL & RTC_SPRCTL_SPRRDY_Msk));
}


/**
 *  @brief    This function is used to:                       \n
 *            1. Enable tamper detection function.            \n
 *            2. Set tamper detect pin number.                \n
 *            3. Set tamper control register, interrupt.      \n
 *            4. Clear tamper status.                         \n
 *            5. Destroy Spare Register when tamper detected  \n
 *
 *  @param    u32PinNumber    tamper detect pin number. [RTC_TAMPER_0 / RTC_TAMPER_1]
 *  @param    u32PinCondition set tamper detection condition: 1=High level detect, 0=Low level detect
 *  @param    u32IntFlag Enable/Disable tamper interrupt: 1=Enable, 0=Disable
 *  @param    u32ClearFlag Clear tamper status
 *  @param    u32DestroyEn Enable/Disable Destroy Spare Register when tamper detected: 1=Enable, 0=Disable
 *
 *  @return   None
 *
 */
void RTC_EnableTamperDetection(uint32_t u32PinNumber, uint32_t u32PinCondition, uint32_t u32IntFlag, uint32_t u32ClearFlag, uint32_t u32DestroyEn)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if(u32PinNumber == RTC_TAMPER_0) {
        if(u32ClearFlag)
            RTC->TAMPSTS |= RTC_TAMPSTS_SDI0STS_Msk;

        if(u32PinCondition)
            RTC->TAMPCTRL |= RTC_TAMPCTRL_SDI0LV_Msk;
        else
            RTC->TAMPCTRL &= ~RTC_TAMPCTRL_SDI0LV_Msk;

        RTC->TAMPCTRL |= RTC_TAMPCTRL_SDIDBEN0_Msk;
        RTC->TAMPCTRL |= RTC_TAMPCTRL_SDIEN0_Msk;
    } else if(u32PinNumber == RTC_TAMPER_1) {
        if(u32ClearFlag)
            RTC->TAMPSTS |= RTC_TAMPSTS_SDI1STS_Msk;

        if(u32PinCondition)
            RTC->TAMPCTRL |= RTC_TAMPCTRL_SDI1LV_Msk;
        else
            RTC->TAMPCTRL &= ~RTC_TAMPCTRL_SDI1LV_Msk;

        RTC->TAMPCTRL |= RTC_TAMPCTRL_SDIDBEN1_Msk;
        RTC->TAMPCTRL |= RTC_TAMPCTRL_SDIEN1_Msk;
    }

    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if(u32IntFlag)
        RTC->TAMPCTRL |= RTC_TAMPCTRL_TIEN_Msk;
    else
        RTC->TAMPCTRL &= ~RTC_TAMPCTRL_TIEN_Msk;

    if(u32DestroyEn)
        RTC->TAMPCTRL |= RTC_TAMPCTRL_DESTROYEN_Msk;
    else
        RTC->TAMPCTRL &= ~RTC_TAMPCTRL_DESTROYEN_Msk;

}

/**
 *  @brief    This function is used to disable tamper detection function.
 *
 *  @param    u32PinNumber    tamper detect pin number: RTC_TAMPER_0, RTC_TAMPER_1
 *
 *  @return   None
 *
 */
void RTC_DisableTamperDetection(uint32_t u32PinNumber)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if(u32PinNumber == RTC_TAMPER_0) {
        RTC->TAMPCTRL &= ~RTC_TAMPCTRL_SDIEN0_Msk;
    } else if(u32PinNumber == RTC_TAMPER_1) {
        RTC->TAMPCTRL &= ~RTC_TAMPCTRL_SDIEN1_Msk;
    }

}

uint32_t RTC_GetDayOfWeek(void)
{
    return (RTC->DWR & RTC_DWR_DWR_Msk);
}


/**
 *  @brief    The function is used to set time tick period for periodic time tick Interrupt.
 *
 *  @param    u32TickSelection
 *                       It is used to set the RTC time tick period for Periodic Time Tick Interrupt request.
 *                       It consists of: \n
 *                       RTC_TICK_1_SEC: Time tick is 1 second        \n
 *                       RTC_TICK_1_2_SEC: Time tick is 1/2 second    \n
 *                       RTC_TICK_1_4_SEC: Time tick is 1/4 second    \n
 *                       RTC_TICK_1_8_SEC: Time tick is 1/8 second    \n
 *                       RTC_TICK_1_16_SEC: Time tick is 1/16 second  \n
 *                       RTC_TICK_1_32_SEC: Time tick is 1/32 second  \n
 *                       RTC_TICK_1_64_SEC: Time tick is 1/64 second  \n
 *                       RTC_TICK_1_128_SEC: Time tick is 1/128 second
 *
 *  @return   None
 *
 */
void RTC_SetTickPeriod(uint32_t u32TickSelection)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->TTR = RTC->TTR & ~RTC_TTR_TTR_Msk | u32TickSelection;
}

/**
 *  @brief    The function is used to enable specified interrupt.
 *
 *  @param    u32IntFlagMask      The structure of interrupt source. It consists of: \n
 *                                RTC_RIER_AIER_Msk: Alarm interrupt                  \n
 *                                RTC_RIER_TIER_Msk: Tick interrupt                    \n
 *
 *  @return   None
 *
 */
void RTC_EnableInt(uint32_t u32IntFlagMask)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    RTC->RIER |= u32IntFlagMask;
}

/**
 *  @brief    The function is used to disable specified interrupt.
 *
 *  @param    u32IntFlagMask      The structure of interrupt source. It consists of: \n
 *                                RTC_RIER_AIER_Msk: Alarm interrupt                  \n
 *                                RTC_RIER_TIER_Msk: Tick interrupt                    \n
 *
 *  @return  None
 *
 */
void RTC_DisableInt(uint32_t u32IntFlagMask)
{
    RTC->AER = RTC_WRITE_KEY;
    while(!(RTC->AER & RTC_AER_ENF_Msk));

    if(u32IntFlagMask & RTC_RIER_TIER_Msk) {
        RTC->RIER &= ~RTC_RIER_TIER_Msk;
        RTC->RIIR |= RTC_RIIR_TIF_Msk;
    }

    if(u32IntFlagMask & RTC_RIER_AIER_Msk) {
        RTC->RIER &= ~RTC_RIER_AIER_Msk;
        RTC->RIIR |= RTC_RIIR_AIF_Msk;
    }

}

/**
 *  @brief    Disable RTC clock.
 *
 *  @return   None
 *
 */
void RTC_Close (void)
{
    CLK->APBCLK0  &= ~CLK_APBCLK0_RTC_EN_Msk;
}


/*@}*/ /* end of group NUC400_RTC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_RTC_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


