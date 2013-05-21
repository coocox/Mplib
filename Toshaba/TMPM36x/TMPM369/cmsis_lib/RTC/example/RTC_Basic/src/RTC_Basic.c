/**
 *******************************************************************************
 * @file    RTC_Basic.c
 * @brief   The application functions of RTC_Basic demo for the
 *          TOSHIBA 'TMPM369' Device Series 
 * @version V1.000
 * @date    2011/9/16
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm369_cg.h"
#include "tmpm369_gpio.h"
#include "tmpm369_rtc.h"
#include "tmpm369_uart.h"

void RTC_Init(void);
void RTC_Display(void);
void UART0_Print(char *string);
void SIO_Configuration(void);
void SIO_ChInit(void);


uint8_t fRTC_1HZ_INT = 0U;

/**
  * @brief  main function.
  * @param  None
  * @retval None
  */

void RTC_Basic(void)
{
    CG_SetFs(ENABLE);
    SIO_Configuration();
	  SIO_ChInit();
    __disable_irq();
    /* enable RTC interrupt */
    NVIC_ClearPendingIRQ(INTRTC_IRQn);
    
    /* enable RTC interrupt */
    CG_SetSTBYReleaseINTSrc(CG_INT_SRC_RTC, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
    RTC_Init();
    NVIC_EnableIRQ(INTRTC_IRQn);
    __enable_irq();
    
    /* waiting for RTC register set finish */
    while (fRTC_1HZ_INT != 1U) {
        /* Do nothing */
    }
    fRTC_1HZ_INT = 0U;

    /* Enable RTC Clock function */
    RTC_EnableClock();

    while (1) {
        if (fRTC_1HZ_INT == 1U) {
            fRTC_1HZ_INT = 0U;

            RTC_Display();
        } else {
            /* Do nothing */
        }
    }
}

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
  * @brief  Send RTC Date value Time value to UART.
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

    UART0_Print(RTC_Disp_YMD);
    UART0_Print("\n\r");		

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

    UART0_Print(RTC_Disp_HMS);
    UART0_Print("\n\r");			
}

/**
  * @brief  UART0 Print
  * @param  string
  * @retval None
  */
void UART0_Print(char *string)
{
	  char *p = string;
	  uint32_t i;
	  while(*p)
	  {
		    UART_SetTxData(UART0, (uint32_t)(*p));
		    p++;
		    for(i = 0U; i < 0xFFFFU; i ++);
	  }
}

/**
  * @brief  SIO Configuration.
  * @param  None
  * @retval None
  */
void SIO_Configuration(void)
{ 
     GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_2, ENABLE);
     GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_2, DISABLE);
     GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_2);
}

/**
  * @brief  SIO Configuration Initialize the uart port (SIO1).
  * @param  None
  * @retval None
  */
void SIO_ChInit(void)
{
    UART_InitTypeDef myUART;

    /* configure SIO0 for reception */
    UART_Enable(UART0);
    myUART.BaudRate = 115200U;  /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Init(UART0, &myUART);
}

/**
  * @brief  The RTC interrupt request function.
  * @param  None
  * @retval None
  */
void INTRTC_IRQHandler(void)
{
    fRTC_1HZ_INT = 1U;
    /*clear RTC interrupt request */
    CG_ClearINTReq(CG_INT_SRC_RTC);
}
