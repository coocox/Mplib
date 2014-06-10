/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/03 5:46p $
 * @brief    NUC200 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "SYS.h"
#include "GPIO.h"
#include "UART.h"
#include "RTC.h"
#include "TIMER.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000


/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);
volatile uint32_t  g_u32RTCTickINT = 0;
volatile uint8_t  g_u8IsRTCAlarmINT = 0;

void PowerDownFunction(void);
void SetRTCStartupDateTime(void);
void RTC_DateTimeTest(void);
void SYS_Init(void);
void RTC_AlarmAndWakeupTest(void);
void UART0_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void RTC_Example (void)
{
	uint8_t	u8Item = 0x0;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
    printf("+------------------------------------+\n");
    printf("|    NUC200 RTC Driver Sample Code   |\n");
    printf("+------------------------------------+\n");
//	printf("\n");

    /* Initial RTC to make RTC leaving reset state */
    _RTC_INIT();
    while (1)
    {
        if (_RTC_IS_ACTIVE())
            break;
    }

    /* Set RTC start-up Date/Time */
    SetRTCStartupDateTime();

    do
    {
        printf("+-------------------------------------------------+ \n");
        printf("| Select an item to test                          | \n");
        printf("+-------------------------------------------------+ \n");
        printf("| [0] RTC Date/Time test                          | \n");
        printf("| [1] RTC Tick Interrupt test                     | \n");
        printf("| [2] RTC Alarm and waken-up from Power Down test | \n");
        printf("| [ESC] Quit                                      | \n");
        printf("+-------------------------------------------------+ \n");
//        printf("\n");
        u8Item = uart_getchar();

        switch (u8Item)
        {
            case '0':
                RTC_DateTimeTest();         break;

            case '1':
                RTC_TickInterruptTest();    break;

            case '2':
                RTC_AlarmAndWakeupTest();   break;
        }
    } while (u8Item != 27);

    printf("\nExit RTC Sample Code. \n");

    return ;
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Function for System Entry to Power Down Mode                                                           */
/*---------------------------------------------------------------------------------------------------------*/
void PowerDownFunction(void)
{
    SYS_UnlockReg();

    /* To check if all the debug messages are finished */
//    while (IsDebugFifoEmpty() == 0);

    SCB->SCR = 4;

    SYSCLK->PWRCON = (SYSCLK->PWRCON & ~(SYSCLK_PWRCON_PWR_DOWN_EN_Msk | SYSCLK_PWRCON_PD_WAIT_CPU_Msk)) |
                        SYSCLK_PWRCON_PD_WAIT_CPU_Msk | SYSCLK_PWRCON_PD_WU_INT_EN_Msk;
    SYSCLK->PWRCON |= SYSCLK_PWRCON_PWR_DOWN_EN_Msk;

    __WFI();
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Set RTC Date/Time is 2012/07/10 08:40:00 on Tuesday                                                    */
/*---------------------------------------------------------------------------------------------------------*/
void SetRTCStartupDateTime(void)
{
    /* Wait RTC Register Access Enable */
    RTC_WaitAccessEnable();

    RTC_SetCurrentCalendar(12, 7, 10);
    RTC_SetCurrentTime(8, 40, 0);
    _RTC_SET_DWR(RTC_DWR_TUESDAY);

    /* Check if RTC Date/Time are ok except [SEC] data */
    if ((_RTC_GET_YEAR() != 12) || (_RTC_GET_MON() != 7)  || (_RTC_GET_DAY() != 10) ||
        (_RTC_GET_HOUR() != 8)  || (_RTC_GET_MIN() != 40) || (_RTC_GET_DWR() != RTC_DWR_TUESDAY))
    {
        printf("Set RTC start-up Date/Time fail. \n\n");
        return ;
    }

    printf("# Set RTC start-up Date/Time is 2012/07/10 08:40:00 on Tuesday. \n");
}


/**
 * @brief       IRQ Handler for RTC Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The RTC_IRQHandler is default IRQ of RTC, declared in startup_NUC200Series.s.
 */
void RTC_IRQHandler(void)
{
    if (_RTC_GET_TICK_INT_FLAG() == 1)
    {
        /* Clear RTC Tick Interrupt Flag */
        _RTC_CLEAR_TICK_INT_FLAG();

        g_u32RTCTickINT++;
    }

    if (_RTC_GET_ALARM_INT_FLAG() == 1)
    {
        /* Clear RTC Alarm Interrupt Flag */
        _RTC_CLEAR_ALARM_INT_FLAG();

        g_u8IsRTCAlarmINT++;
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*  RTC Date/Time Test                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
void RTC_DateTimeTest(void)
{
    uint8_t u8Loop;

    printf("# Use TIMER0 Periodic mode to generate periodic interrupt events every one second. \n");
    printf("# Showing RTC Date/Time on UART-0. \n");
    printf("Press any key to start test ... \n\n");
    uart_getchar();

    /* Configure TIMER0 clock source as 12 MHz, run in Periodic mode */
    _TIMER_RESET(TIMER0);
    TIMER0->TCMPR = __XTAL;
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    printf("Date/Time is: \n");
    for (u8Loop=0; u8Loop<10; u8Loop++)
    {
        /* Wait TIMER0 Compare Match Interrupt Flag then show current RTC Date/Time */
        while (_TIMER_GET_CMP_INT_FLAG(TIMER0) == 0);
        _TIMER_CLEAR_CMP_INT_FLAG(TIMER0);
        printf("    %d/%02d/%02d %02d:%02d:%02d \n",
                (2000+_RTC_GET_YEAR()), _RTC_GET_MON(), _RTC_GET_DAY(), _RTC_GET_HOUR(), _RTC_GET_MIN(), _RTC_GET_SEC());
    }

    /* Stop TIMER0 countuing */
    _TIMER_RESET(TIMER0);

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  RTC Tick Interrupt Test                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void RTC_TickInterruptTest(void)
{
    printf("# Set RTC Tick Interrupt Period Time is 1/8 second. \n");
    printf("# Use TIMER0 One-Shot mode to gererate interrupt event after 2 second, \n");
    printf("  and the RTC Tick Interrupt counts should be 16. \n");
    printf("Press any key to start test ... \n\n");
    uart_getchar();

    /* Configure TIMER0 clock source as 12 MHz, run in One-Shot mode */
    _TIMER_RESET(TIMER0);
    TIMER0->TCMPR = __XTAL;

    /* Wait RTC Register Access Enable */
    RTC_WaitAccessEnable();

    /* Enable RTC NVIC */
    NVIC_EnableIRQ(RTC_IRQn);

    /* Set RTC tick period time 1/8 sec */
    _RTC_SET_TTR(RTC_TTR_1DIV8);

    /* Enable RTC tick interrupt */
    _RTC_TICK_INT_ENABLE();

    g_u32RTCTickINT = 0;

    /* Start TIMER0 counting */
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(2);

    /* Wait TIMER0 Compare Match Interrupt Flag then show current RTC Date/Time */
    while (_TIMER_GET_CMP_INT_FLAG(TIMER0) == 0);
    _TIMER_CLEAR_CMP_INT_FLAG(TIMER0);

    /* Disable RTC NVIC */
    NVIC_DisableIRQ(RTC_IRQn);

    /* Disable RTC tick interrupt */
    _RTC_TICK_INT_DISABLE();

    /* Stop TIMER0 countuing */
    _TIMER_RESET(TIMER0);

    printf("RTC Tick Interrupt event counts is %d in 2 second time period. \n", g_u32RTCTickINT);

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  RTC Alarm and Wakk-up Test                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
void RTC_AlarmAndWakeupTest(void)
{
    printf("# Set RTC Current Date/Time is: 2012/07/10 13:10:55. \n");
    printf("# Set RTC Alarm Date/Time is:   2012/07/10 13:11:07. \n");
    printf("# System enter to Power Down on RTC Date/Time 2012/07/10 13:10:55; \n");
    printf("                and waken-up on RTC Date/Time 2012/07/10 13:11:07. \n");
    printf("Press any key to start test ... \n\n");
    uart_getchar();

    /* Wait RTC Register Access Enable */
    RTC_WaitAccessEnable();

    /* Set RTC Current Date/Time */
    RTC_SetCurrentCalendar(12, 7, 10);
    RTC_SetCurrentTime(13, 10, 55);
    _RTC_SET_DWR(RTC_DWR_TUESDAY);

    /* Set RTC Alarm Date/Time */
    RTC_SetAlarmCalendar(12, 7, 10);
    RTC_SetAlarmTime(13, 11, 7);

    /* Wait RTC Register Access Enable */
    RTC_WaitAccessEnable();

    /* Check if RTC Current Date/Time are ok except [SEC] data */
    if ((_RTC_GET_YEAR() != 12) || (_RTC_GET_MON() != 7)  || (_RTC_GET_DAY() != 10) ||
        (_RTC_GET_HOUR() != 13)  || (_RTC_GET_MIN() != 10))
    {
        printf("Set RTC Current Date/Time fail. \n\n");
        return ;
    }

    /* Check if RTC current Date/Time are ok */
    if ((_RTC_GET_ALARM_YEAR() != 12) || (_RTC_GET_ALARM_MON() != 7)  || (_RTC_GET_ALARM_DAY() != 10) ||
        (_RTC_GET_ALARM_HOUR() != 13)  || (_RTC_GET_ALARM_MIN() != 11) || (_RTC_GET_ALARM_SEC() != 7))
    {
        printf("Set RTC Alarm Date/Time fail. \n\n");
        return ;
    }

    /* Enable RTC NVIC */
    NVIC_EnableIRQ(RTC_IRQn);

    /* Enable RTC Alarm Interrupt */
    _RTC_ALARM_INT_ENABLE();

    printf("Cunnret Date/Time is 2012/07/10 13:10:55 and system enter to Power Down. \n");

    g_u8IsRTCAlarmINT = 0;

    /* System enter to Power Down */
    PowerDownFunction();

    while (g_u8IsRTCAlarmINT == 0);

    printf("System waken-up and current Date/Time is %d/%02d/%02d %02d:%02d:%02d. \n",
            (2000+_RTC_GET_YEAR()), _RTC_GET_MON(), _RTC_GET_DAY(), _RTC_GET_HOUR(), _RTC_GET_MIN(), _RTC_GET_SEC());

    /* Disable RTC NVIC */
    NVIC_DisableIRQ(RTC_IRQn);

    /* Disable RTC Alarm Interrupt */
    _RTC_ALARM_INT_DISABLE();

//    printf("\n");
}


void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Enable external 32 kHz XTAL */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL32K_EN_Msk;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_XTL12M_STB_Msk | SYSCLK_CLKSTATUS_XTL32K_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_XTAL;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_RTC_EN_Msk | SYSCLK_APBCLK_TMR0_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL | SYSCLK_CLKSEL1_TMR0_XTAL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD, UART0 TXD */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;

    /* Lock protected registers */
    SYS_LockReg();
}


void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART0_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

