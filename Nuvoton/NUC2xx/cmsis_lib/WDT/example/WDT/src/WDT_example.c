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
#include "WDT.h"
#include "TIMER.h"


#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000



/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);
volatile uint8_t  g_u8IsWDTTimeoutINT = 0, g_u8IsWDTWakeupINT = 0, g_u8IsWWDTCompareINT = 0;

void PowerDownFunction(void);
void UART0_Init(void);
void SYS_Init(void);
void WWDT_CompareMatchInterruptTest(void);
void WDT_TimeoutWakeupTest(void);
void WDT_TimeoutInterruptTest(void);

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void WDT_Example (void)
{
	uint8_t	u8Item = 0x0;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
    printf("+---------------------------------------------+\n");
    printf("|    NUC200 WDT and WWDT Driver Sample Code   |\n");
    printf("+---------------------------------------------+\n");
//	printf("\n");

    /* To check if WWDT reset occurred or not */
    if (_WWDT_GET_RESET_FLAG() == 1)
    {
        _WWDT_CLEAR_RESET_FLAG();
	    printf("WWDT reset occurred. \n\n");
    }

    /*
        The clock source setings as below
            WDT:    IRC 10 kHz
            WWDT:   HCLK/2048
            TIMER0: 12 MHz ... to measure WDT timeout period time
            TIMER1: IRC 10 kHz ... to measure Power Down period time after WDT wakeup event occured
    */

    do
    {
        printf("+-------------------------------------------------------+ \n");
        printf("| Select an item to test                                | \n");
        printf("+-------------------------------------------------------+ \n");
        printf("| [0] WDT timeout interrupt test                        | \n");
        printf("| [1] Power Down and waken-up by WDT timeout interrupt  | \n");
        printf("| [2] WWDT compare match interrupt test                 | \n");
        printf("| [ESC] Quit                                            | \n");
        printf("+-------------------------------------------------------+ \n");
//        printf("\n");
        u8Item = uart_getchar();

        switch (u8Item)
        {
            case '0':
                WDT_TimeoutInterruptTest();             break;

            case '1':
                WDT_TimeoutWakeupTest();                break;

            case '2':
                WWDT_CompareMatchInterruptTest();       break;
        }
    } while (u8Item != 27);

    printf("\nExit WDT and WWDT Sample Code. \n");

    return 0;
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


/**
 * @brief       IRQ Handler for WDT and WWDT Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The WDT_IRQHandler is default IRQ of WDT and WWDT, declared in startup_NUC200Series.s.
 */
void WDT_IRQHandler(void)
{
    if ((_WDT_GET_TIMEOUT_INT_FLAG() == 1) && (_WDT_GET_TIMEOUT_WAKEUP_FLAG() == 1))
    {
        /* Clear WDT Timeout Interrupt and Wake-up Flag */
        _WDT_CLEAR_TIMEOUT_INT_FLAG();
        _WDT_CLEAR_TIMEOUT_WAKEUP_FLAG();

        g_u8IsWDTWakeupINT = 1;

        printf("WDT Timeout Wake-up occurred. \n");
    }

    if (_WDT_GET_TIMEOUT_INT_FLAG() == 1)
    {
        /* Clear WDT Timeout Interrupt Flag */
        _WDT_CLEAR_TIMEOUT_INT_FLAG();

        g_u8IsWDTTimeoutINT = 1;

        printf("WDT Timeout occurred. \n");
    }

    if (_WWDT_GET_CMP_INT_FLAG() == 1)
    {
        /* Clear WWDT Compare Matcht Interrupt Flag */
        _WWDT_CLEAR_CMP_INT_FLAG();

        g_u8IsWWDTCompareINT++;

        if (g_u8IsWWDTCompareINT < 10)
        {
            /* To reload the WWDT counter value to 0x3F */
            _WWDT_RELOAD_COUNTER();
        }

        printf("WWDT Compare Match Interrupt occurred. (%d)\n", g_u8IsWWDTCompareINT);
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*  WDT Timeout Interrupt Test                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
void WDT_TimeoutInterruptTest(void)
{
    uint32_t u32TDRValue;

    printf("# WDT Settings: \n");
    printf("  Clock source is IRC 10 kHz; Enable interrupt; Timeout interval is 2^14 * WDT clock. \n");
    printf("# When WDT statr counting, system will generate a WDT timeout interrupt after 1.6384 ~ 1.7408 s. \n");
    printf("  But the real timeout period time is based on bulit-in IRC 10 kHz frequency of each chip. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();

    /* Because of all bits can be written in WDT Control Register are write-protected;
       To program it needs to disable register protection first. */
    SYS_UnlockReg();

    g_u8IsWDTTimeoutINT = g_u8IsWDTWakeupINT = 0;

    /* Enable WDT and WWDT NVIC */
    NVIC_EnableIRQ(WDT_IRQn);

    /* Configure TIMER0 clock source as 12 MHz, run in One-Shot mode and one TDR count is about 10 us */
    _TIMER_RESET(TIMER0);
    TIMER0->TCMPR = 0xFFFFFF;
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(120);

    /* Enable WDT interrupt and select timeout interval to 2^14 * WDT clock then start WDT counting */
    WDT->WTCR = WDT_WTCR_INT_2POW14;

    /* Check if WDT timeout interrupt occurred */
    while (g_u8IsWDTTimeoutINT == 0);

    /* Get TDR value */
    u32TDRValue = TIMER0->TDR;

    /* Disable WDT counting */
    _WDT_DISABLE_COUNTING();

    /* Stop TIMER0 countuing */
    _TIMER_RESET(TIMER0);

    printf("And timeout period is about %d us\n", u32TDRValue*10);

    g_u8IsWDTTimeoutINT = 0;

    /* Lock protected registers */
    SYS_LockReg();

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  WDT Timeout Wake-up Function Test                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void WDT_TimeoutWakeupTest(void)
{
    uint32_t u32TDRValue;

    printf("# WDT Settings: \n");
    printf("  Clock source is 10 kHz; Enable interrupt; Enable Wake-up; Timeout interval is 2^16 * WDT clock. \n");
    printf("# When WDT statr counting, system will generate a WDT timeout interrupt after 6.5536 ~ 6.656 s. \n");
    printf("  But the real timeout period time is based on bulit-in IRC 10 kHz frequency of each chip. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();

    /* Because of all bits can be written in WDT Control Register are write-protected;
       To program it needs to disable register protection first. */
    SYS_UnlockReg();

    g_u8IsWDTTimeoutINT = g_u8IsWDTWakeupINT = 0;

    /* Enable WDT and WWDT NVIC */
    NVIC_EnableIRQ(WDT_IRQn);

    /* Configure TIMER1 clock source as 10 kHz, run in One-Shot mode and one TDR count is about 100 us */
    _TIMER_RESET(TIMER1);
    TIMER1->TCMPR = 0xFFFFFF;
    TIMER1->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    /* Enable WDT interrupt and select timeout interval to 2^16 * WDT clock then start WDT counting */
    WDT->WTCR = WDT_WTCR_WAKEUP_INT_2POW16;

    /* System entry into Power Down Mode */
    PowerDownFunction();

    /* Check if WDT timeout interrupt and Power Down Wake-up Interrupt Flag occurred */
    while (1)
    {
        if (((SYSCLK->PWRCON & SYSCLK_PWRCON_PD_WU_STS_Msk) == SYSCLK_PWRCON_PD_WU_STS_Msk) && (g_u8IsWDTWakeupINT == 1))
            break;
    }

    /* Get TDR value */
    u32TDRValue = TIMER1->TDR;

    /* Clear Power Down Wake-up Interrupt Flag */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_PD_WU_STS_Msk;

    /* Disable WDT counting */
    _WDT_DISABLE_COUNTING();

    /* Stop TIMER0 countuing */
    _TIMER_RESET(TIMER0);

    printf("And power down period is about %d us\n", u32TDRValue*100);

    g_u8IsWDTWakeupINT = 0;

    /* Lock protected registers */
    SYS_LockReg();

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  WWDT Compare Match Interrupt Test                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void WWDT_CompareMatchInterruptTest(void)
{
    uint32_t u32TDRValue;
    double fPeriodTime;

    fPeriodTime = (((double)(1000000*2048)/(double)SystemCoreClock)*1024)*32;

    printf("# WWDT Settings: \n");
    printf("  Clock source is HCLK/2048(%d Hz); Enable interrupt;  Window Compare value is 32; \n", SystemCoreClock/2048);
    printf("  Time-out period is 1024 * (64 * WWDT_clock); \n");
    printf("# When WWDT statr counting, system will generate first WWDT compare match interrupt after %.2f us. \n", fPeriodTime);
    printf("# And reload WWDT counter value to 0x3F if WWDT interrupt counts less than 10 to avoid WWDT reset occurred. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();

    g_u8IsWDTTimeoutINT = g_u8IsWDTWakeupINT = g_u8IsWWDTCompareINT = 0;

    /* Enable WDT and WWDT NVIC */
    NVIC_EnableIRQ(WDT_IRQn);

    /* Configure TIMER0 clock source as 12 MHz, run in One-Shot mode and one TDR count is about 10 us */
    _TIMER_RESET(TIMER0);
    TIMER0->TCMPR = 0xFFFFFF;
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(120);

    /* Configure WWDT compare value is 32, time-out period is 1024*(64*WWDT_clk) and enable WWDT interrupt then start WWDT counting */
    /* Note: WWDTCR register can be written only one time after chip is powered on or reset */
    WWDT->WWDTCR = WWDT_WWDTCR_WINCMP(32) | WWDT_WWDTCR_PERIODSEL_1024 | WWDT_WWDTCR_WWDTIE_Msk | WWDT_WWDTCR_WWDTEN_Msk;

    /* Check if WWDT timeout interrupt occurred */
    while (g_u8IsWWDTCompareINT == 0);

    /* Get TDR value */
    u32TDRValue = TIMER0->TDR;

    /* Stop TIMER0 countuing */
    _TIMER_RESET(TIMER0);

    printf("And counter period time is about %d us\n\n", u32TDRValue*10);

    while (g_u8IsWWDTCompareINT < 11);
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

    /* Enable internal 10 kHz Oscillator */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_IRC10K_EN_Msk;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_XTL12M_STB_Msk | SYSCLK_CLKSTATUS_IRC10K_STB_Msk);

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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_WDT_EN_Msk | SYSCLK_APBCLK_TMR0_EN_Msk | SYSCLK_APBCLK_TMR1_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL | SYSCLK_CLKSEL1_WDT_IRC10K | SYSCLK_CLKSEL2_WWDT_HCLK_DIV2048 |
                        SYSCLK_CLKSEL1_TMR0_XTAL | SYSCLK_CLKSEL1_TMR1_IRC10K;

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


