/**
 *******************************************************************************
 * @file    rtc.c
 * @brief   The application functions of RTC_Basic demo for the
 *          TOSHIBA 'TMPM061' Device Series 
 * @version V0.100
 * @date    2012/04/18
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

/**
  * @brief  Initialize RTC register and variables
  * @param  None
  * @retval None
  */

void RTC_Init(void)
{
    RTC_DateTypeDef Date_Struct;
    RTC_TimeTypeDef Time_Struct;

    Date_Struct.LeapYear = RTC_LEAP_YEAR_2;
    Date_Struct.Year = (uint8_t) 10U;
    Date_Struct.Month = (uint8_t) 10U;
    Date_Struct.Date = (uint8_t) 22U;
    Date_Struct.Day = RTC_FRI;

    Time_Struct.HourMode = RTC_24_HOUR_MODE;
    Time_Struct.Hour = (uint8_t) 12U;
    Time_Struct.Min = (uint8_t) 50U;
    Time_Struct.Sec = (uint8_t) 55U;

    RTC_DisableClock();
    RTC_DisableAlarm();

    /* Reset RTC sec counter */
    RTC_ResetClockSec();   
    RTC_EnableClock();
    RTC_EnableAlarm();
    
    /* Set RTC Time value */
    RTC_SetTimeValue(&Time_Struct);
    /* Set RTC Date value */
    RTC_SetDateValue(&Date_Struct);

    /* Enable 1Hz interrupt */
    RTC_SetAlarmOutput(RTC_PULSE_1_HZ);
    /* Enable RTCINT */
    RTC_SetRTCINT(ENABLE);
    
   
}

/**
  * @brief  Send RTC Date value Time value to LCD.
  * @param  None
  * @retval None
  */
void RTC_Display(void)
{
    uint8_t Year, Month, Date;
    uint8_t Hour, Min, Sec;

    char RTC_Disp_YMD[16];
    char RTC_Disp_HMS[16];

    /* Send RTC Date value to LCD */
    /* Get RTC Date value */
    Year = RTC_GetYear();
    Month = RTC_GetMonth();
    Date = RTC_GetDate(RTC_CLOCK_MODE);

    /* Set LCD display */
    /* Dispaly year */
    RTC_Disp_YMD[0] = '2';
    RTC_Disp_YMD[1] = '0';
    RTC_Disp_YMD[2] = (Year / 10U) + 0x30U;
    RTC_Disp_YMD[3] = (Year % 10U) + 0x30U;
    RTC_Disp_YMD[4] = '/';
    /* Display month */
    RTC_Disp_YMD[5] = (Month / 10U) + 0x30U;
    RTC_Disp_YMD[6] = (Month % 10U) + 0x30U;
    RTC_Disp_YMD[7] = '/';
    /* Display date */
    RTC_Disp_YMD[8] = (Date / 10U) + 0x30U;
    RTC_Disp_YMD[9] = (Date % 10U) + 0x30U;

    RTC_Disp_YMD[10] = 0U;

    Send_To_LCD(FIRST_LINE, LCD_COMMAND);
    Send_LCD_Text(RTC_Disp_YMD);

    /* Send RTC Time value to LCD */
    /* Get RTC Time value */
    Hour = RTC_GetHour(RTC_CLOCK_MODE);
    Min = RTC_GetMin(RTC_CLOCK_MODE);
    Sec = RTC_GetSec();

    /* Display hour */
    RTC_Disp_HMS[0] = (Hour / 10U) + 0x30U;
    RTC_Disp_HMS[1] = (Hour % 10U) + 0x30U;
    RTC_Disp_HMS[2] = ':';
    /* Display min */
    RTC_Disp_HMS[3] = (Min / 10U) + 0x30U;
    RTC_Disp_HMS[4] = (Min % 10U) + 0x30U;
    RTC_Disp_HMS[5] = ':';
    /* Display sec */
    RTC_Disp_HMS[6] = (Sec / 10U) + 0x30U;
    RTC_Disp_HMS[7] = (Sec % 10U) + 0x30U;
    RTC_Disp_HMS[8] = 0U;

    /* LCD Display */
    Send_To_LCD(SECOND_LINE, LCD_COMMAND);
    Send_LCD_Text(RTC_Disp_HMS);
}
