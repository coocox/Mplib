/**
 *******************************************************************************
 * @file    RTC_Basic.c
 * @brief   The application functions of RTC demo for the
 *          TOSHIBA 'TMPM362' Device Series 
 * @version V1.300
 * @date    2010/07/15
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

/* include file */
#include "tmpm362_rtc.h"
#include "tmpm362_uart.h"

#define CG_IMCGC_RTC_EDGE		((uint32_t)0x00000020)	/* RTC Interrupt Edge */
#define CG_IMCGC_RTC_INTEN		((uint32_t)0x00000021)	/* RTC Interrupt ON   */
#define UART UART0
/*  Function declaration */
void demo0(void);
void demo1(void);
void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);

/* User ram definition  */
RTC_DateTypeDef Date_Struct;
RTC_TimeTypeDef Time_Struct;

uint8_t fRTCSetting_ok = 0U;

char RTC_Disp_YMD[16];
char RTC_Disp_HMS[16];
uint8_t Year;
uint8_t Month;
uint8_t Date;
uint8_t Day;
uint8_t Hour;
uint8_t Min;
uint8_t Sec;

void RTC_Basic(void)
{
    SystemInit();
	UART_Configuration(UART);
    __disable_irq();
    /* enable RTC interrupt */
    NVIC_ClearPendingIRQ(INTRTC_IRQn);
    TSB_CG->IMCGF = CG_IMCGC_RTC_EDGE;
    TSB_CG->IMCGF = CG_IMCGC_RTC_INTEN;
    NVIC_EnableIRQ(INTRTC_IRQn);

    Date_Struct.LeapYear = RTC_LEAP_YEAR_2;
    Date_Struct.Year = (uint8_t) 10;
    Date_Struct.Month = (uint8_t) 12;
    Date_Struct.Date = (uint8_t) 31;
    Date_Struct.Day = RTC_FRI;

    Time_Struct.HourMode = RTC_12_HOUR_MODE;
    Time_Struct.Hour = (uint8_t) 11;
    Time_Struct.AmPm = RTC_PM_MODE;
    Time_Struct.Min = (uint8_t) 59;
    Time_Struct.Sec = (uint8_t) 50;

    RTC_DisableClock();
    RTC_DisableAlarm();

    /* Reset RTC sec counter */
    RTC_ResetClockSec();
    /* Set RTC Time value */
    RTC_SetTimeValue(&Time_Struct);
    /* Set RTC Date value */
    RTC_SetDateValue(&Date_Struct);

    /* Enable 1Hz interrupt */
    RTC_SetAlarmOutput(RTC_PULSE_1_HZ);
    /* Enable RTCINT */
    RTC_SetRTCINT(ENABLE);
    __enable_irq();

    /* waiting for RTC register set finish */
    while (fRTCSetting_ok != 1U) {
        /* Do nothing */
    }
    fRTCSetting_ok = 0U;

    /* Enable RTC Clock function */
    RTC_EnableClock();

    while (1) {
        if (fRTCSetting_ok == 1U) {
            fRTCSetting_ok = 0U;
            demo0();
            demo1();
        } else {
            /* Do nothing */
        }
    }
}


/* Send RTC Date value to hyperterminal */
void demo0(void)
{
    /* Get RTC Date value */
    Year = RTC_GetYear();
    Month = RTC_GetMonth();
    Date = RTC_GetDate(RTC_CLOCK_MODE);
    Day = RTC_GetDay(RTC_CLOCK_MODE);
    /* Set UART0 display */
    /* Dispaly year */
    RTC_Disp_YMD[0] = ' ';
    RTC_Disp_YMD[1] = (Year / 10U) + 0x30U;
    RTC_Disp_YMD[2] = (Year % 10U) + 0x30U;
    RTC_Disp_YMD[3] = '-';
    /* Display month */
    RTC_Disp_YMD[4] = (Month / 10U) + 0x30U;
    RTC_Disp_YMD[5] = (Month % 10U) + 0x30U;
    RTC_Disp_YMD[6] = '-';
    /* Display date */
    RTC_Disp_YMD[7] = (Date / 10U) + 0x30U;
    RTC_Disp_YMD[8] = (Date % 10U) + 0x30U;

    RTC_Disp_YMD[9] = ' ';
    RTC_Disp_YMD[10] = ' ';
    RTC_Disp_YMD[11] = ' ';
    /* Display day */
    switch (Day) {
    case RTC_SUN:
        RTC_Disp_YMD[12] = 'S';
        RTC_Disp_YMD[13] = 'U';
        RTC_Disp_YMD[14] = 'N';
        break;
    case RTC_MON:
        RTC_Disp_YMD[12] = 'M';
        RTC_Disp_YMD[13] = 'O';
        RTC_Disp_YMD[14] = 'N';
        break;
    case RTC_TUE:
        RTC_Disp_YMD[12] = 'T';
        RTC_Disp_YMD[13] = 'U';
        RTC_Disp_YMD[14] = 'E';
        break;
    case RTC_WED:
        RTC_Disp_YMD[12] = 'W';
        RTC_Disp_YMD[13] = 'E';
        RTC_Disp_YMD[14] = 'D';
        break;
    case RTC_THU:
        RTC_Disp_YMD[12] = 'T';
        RTC_Disp_YMD[13] = 'H';
        RTC_Disp_YMD[14] = 'U';
        break;
    case RTC_FRI:
        RTC_Disp_YMD[12] = 'F';
        RTC_Disp_YMD[13] = 'R';
        RTC_Disp_YMD[14] = 'I';
        break;
    case RTC_SAT:
        RTC_Disp_YMD[12] = 'S';
        RTC_Disp_YMD[13] = 'A';
        RTC_Disp_YMD[14] = 'T';
        break;
    default:
        /* Do nothing */
        break;
    }
    RTC_Disp_YMD[15] = '\0';
	UART_Print(UART, RTC_Disp_YMD);
}

/* Send RTC Time value to hyperterminal */
void demo1(void)
{
    RTC_GetTimeValue(&Time_Struct);
    /* UART0 Display */
    RTC_Disp_HMS[0] = ' ';
    if (Time_Struct.AmPm == RTC_PM_MODE) {
        RTC_Disp_HMS[1] = 'P';
        RTC_Disp_HMS[2] = 'M';
    } else {
        RTC_Disp_HMS[1] = 'A';
        RTC_Disp_HMS[2] = 'M';
    }
    RTC_Disp_HMS[3] = ' ';
    /* Display hour */
    RTC_Disp_HMS[4] = (Time_Struct.Hour / 10U) + 0x30U;
    RTC_Disp_HMS[5] = (Time_Struct.Hour % 10U) + 0x30U;
    RTC_Disp_HMS[6] = ':';
    /* Display min */
    RTC_Disp_HMS[7] = (Time_Struct.Min / 10U) + 0x30U;
    RTC_Disp_HMS[8] = (Time_Struct.Min % 10U) + 0x30U;
    RTC_Disp_HMS[9] = ':';
    /* Display sec */
    RTC_Disp_HMS[10] = (Time_Struct.Sec / 10U) + 0x30U;
    RTC_Disp_HMS[11] = (Time_Struct.Sec % 10U) + 0x30U;
    RTC_Disp_HMS[12] = ' ';
    RTC_Disp_HMS[13] = '\n';
    RTC_Disp_HMS[14] = '\r';
    RTC_Disp_HMS[15] = '\0';
	UART_Print(UART, RTC_Disp_HMS);
}


void UART_Print(TSB_SC_TypeDef * UARTx, char *string)
{
	  char *p = string;
	  int i;
	  while(*p)
	  {
		    UART_SetTxData(UARTx, (uint32_t)(*p));
		    p++;
		    for(i = 0; i < 1000; i ++);
	  }
}

void UART_Configuration(TSB_SC_TypeDef * SCx)
{
    UART_InitTypeDef myUART;
    if (SCx == UART0) {
        TSB_PE_CR_PE4C = 1;
        TSB_PE_FR2_PE4F2 = 1;
        TSB_PE_FR2_PE5F2 = 1;
        TSB_PE_IE_PE5IE = 1;
    } else {
		//do nothing
	}
    myUART.BaudRate = 115200U;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(SCx);
    UART_Init(SCx, &myUART);
}


/**
  * @brief  The RTC interrupt request function.
  * @param  None
  * @retval None
  */
void INTRTC_IRQHandler(void)
{
    fRTCSetting_ok = 1U;
    TSB_CG->ICRCG = (uint32_t) 0x14;
}
