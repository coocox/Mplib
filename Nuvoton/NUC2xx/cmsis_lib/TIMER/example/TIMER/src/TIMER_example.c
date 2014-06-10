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
#include "TIMER.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000



/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);
volatile uint32_t g_au32TMRINTCount[4] = {0};

void PowerDownFunction(void);
void UART0_Init(void);
void SYS_Init(void);
void TIMER_PowerDownAndWakeupTest(void);
void TIMER_ExternalCaptureFunctionTest(void);
void TIMER_ExternalCounterFunctionTest(void);
void TIMER_DelayTimeByInterruptTicksTest(void);
void TIMER_InterruptAndFrequencyTest(void);
void GeneratePACounter(uint32_t u32Pin, uint32_t u32Counts);
void TIMER_DelayIntTicks(uint32_t u32TimerCH, uint32_t u32DelayTicks);


/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_Example (void)
{
	uint8_t	u8Item = 0x0;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("+--------------------------------------+\n");
    printf("|    NUC200 TIMER Driver Sample Code   |\n");
    printf("+--------------------------------------+\n");
//	printf("\n");

    do
    {
        /*
            The clock source of Timer are
                TIMER0: 12 MHz
                TIMER1: 48 MHz from HCLK
                TIMER2: IRC 10 kHz
                TIMER3: IRC 22.1184 MHz
        */
        printf("+-------------------------------------------------------+ \n");
        printf("| Select an item to test                                | \n");
        printf("+-------------------------------------------------------+ \n");
        printf("| [1] TIMER0/1/2/3 timeout interrupt and frequency test | \n");
        printf("| [2] Delay time by TIMER0 interrupt ticks test         | \n");
        printf("| [3] TIMER1 External Counter Pin and Function test     | \n");
        printf("| [4] TIMER1 External Capture Pin and Function test     | \n");
        printf("| [5] Power Down and waken-up by TIMER2 interrupt event | \n");
        printf("| [ESC] Quit                                            | \n");
        printf("+-------------------------------------------------------+ \n");
//        printf("\n");
        u8Item = uart_getchar();

        switch (u8Item)
        {
            case '1':
                TIMER_InterruptAndFrequencyTest();      break;

            case '2':
                TIMER_DelayTimeByInterruptTicksTest();  break;

            case '3':
                TIMER_ExternalCounterFunctionTest();    break;

            case '4':
                TIMER_ExternalCaptureFunctionTest();    break;

            case '5':
                TIMER_PowerDownAndWakeupTest();         break;
        }
    } while (u8Item != 27);

    printf("\nExit TIMER Sample Code. \n");

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


/*---------------------------------------------------------------------------------------------------------*/
/*  Create Counter Source by GPIO PORT-A                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void GeneratePACounter(uint32_t u32Pin, uint32_t u32Counts)
{
    while (u32Counts--)
    {
        GPIO_PIN_DATA(0, u32Pin) = 1;
        GPIO_PIN_DATA(0, u32Pin) = 0;
    }
}


/**
 * @brief       Timer-0 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The TIMER0 default IRQ, declared in startup_NUC200Series.s.
 */
void TMR0_IRQHandler(void)
{
    /* Clear TIMER0 Timeout Interrupt Flag */
    _TIMER_CLEAR_CMP_INT_FLAG(TIMER0);

    g_au32TMRINTCount[0]++;
}


/**
 * @brief       Timer-1 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The TIMER1 default IRQ, declared in startup_NUC200Series.s.
 */
void TMR1_IRQHandler(void)
{
    if (_TIMER_GET_CMP_INT_FLAG(TIMER1) == 1)
    {
        /* Clear TIMER1 Timeout Interrupt Flag */
        _TIMER_CLEAR_CMP_INT_FLAG(TIMER1);
    }else
    if (_TIMER_GET_CAP_INT_FLAG(TIMER1) == 1)
    {
        /* Clear TIMER1 Capture Interrupt Flag */
        _TIMER_CLEAR_CAP_INT_FLAG(TIMER1);
    }

    g_au32TMRINTCount[1]++;
}


/**
 * @brief       Timer-2 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The TIMER2 default IRQ, declared in startup_NUC200Series.s.
 */
void TMR2_IRQHandler(void)
{
    if (_TIMER_GET_CMP_INT_FLAG(TIMER2) == 1)
    {
        /* Clear TIMER2 Timeout Interrupt Flag */
        _TIMER_CLEAR_CMP_INT_FLAG(TIMER2);
    }

    if (_TIMER_GET_WAKEUP_INT_FLAG(TIMER2) == 1)
    {
        /* Clear TIMER2 Wake-up Flag */
        _TIMER_CLEAR_WAKEUP_INT_FLAG(TIMER2);
    }

    g_au32TMRINTCount[2]++;
}


/**
 * @brief       Timer-3 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The TIMER3 default IRQ, declared in startup_NUC200Series.s.
 */
void TMR3_IRQHandler(void)
{
    /* Clear TIMER3 Timeout Interrupt Flag */
    _TIMER_CLEAR_CMP_INT_FLAG(TIMER3);

    g_au32TMRINTCount[3]++;
}


/*---------------------------------------------------------------------------------------------------------*/
/*  To Delay Specified Interrupt Ticks                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_DelayIntTicks(uint32_t u32TimerCH, uint32_t u32DelayTicks)
{
    g_au32TMRINTCount[u32TimerCH] = 0;

    while (g_au32TMRINTCount[u32TimerCH] < u32DelayTicks);
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Timer Interrupt Ticks and Frequency Test                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_InterruptAndFrequencyTest(void)
{
    uint32_t u32InitCount;

    printf("# TIMER Settings: \n");
    printf("  TIMER0: Clock source 12 MHz;     Periodic mode; Enable interrupt; 1 interrupt tick/sec.  \n");
    printf("  TIMER1: Clock source 48 MHz;     Periodic mode; Enable interrupt; 2 interrupt ticks/sec. \n");
    printf("  TIMER2: Clock source IRC 10 kHz; Periodic mode; Enable interrupt; 4 interrupt ticks/sec. \n");
    printf("  TIMER3: Clock source IRC 22 MHz; Periodic mode; Enable interrupt; 8 interrupt ticks/sec. \n");
    printf("# Check all Timer interrupt counts are reasonable or not. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();
//    printf("\n");

    /* Reset and stop TIMER0, TIMER1, TIMER2 and TIMER3 counting first */
    _TIMER_RESET(TIMER0);
    _TIMER_RESET(TIMER1);
    _TIMER_RESET(TIMER2);
    _TIMER_RESET(TIMER3);

    /* Enable TIMER0, TIMER1, TIMER2 and TIMER3 NVIC */
    NVIC_EnableIRQ(TMR0_IRQn);
    NVIC_EnableIRQ(TMR1_IRQn);
    NVIC_EnableIRQ(TMR2_IRQn);
    NVIC_EnableIRQ(TMR3_IRQn);

    /* To Configure TCMPR values based on Timer clock source and pre-scale value */
    TIMER0->TCMPR = __XTAL;                  // For 1 tick per second when using external 12 MHz (Prescale = 1)
    TIMER1->TCMPR = ((SystemCoreClock/4)/2); // For 2 ticks per second when using HCLK 48 MHz (Prescale = 4)
    TIMER2->TCMPR = ((__IRC10K/1)/4);        // For 4 ticks per second when using IRC 10 kHz (Prescale = 1)
    TIMER3->TCMPR = ((__IRC22M/2)/8);        // For 8 ticks per second when using IRC 22.1184 MHz (Prescale = 2)

    /* Start TIMER0 counting */
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk |
                      TIMER_TCSR_PRESCALE(1);

    /* Start TIMER1 counting */
    TIMER1->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk |
                      TIMER_TCSR_PRESCALE(4);

    /* Start TIMER2 counting */
    TIMER2->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk |
                      TIMER_TCSR_PRESCALE(1);

    /* Start TIMER3 counting */
    TIMER3->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk |
                      TIMER_TCSR_PRESCALE(2);

    /* Clear Timer interrupt ticks to 0 */
    g_au32TMRINTCount[0] = g_au32TMRINTCount[1] = g_au32TMRINTCount[2] = g_au32TMRINTCount[3] = 0;

    /* Check Timer interrupt counts */
    u32InitCount = g_au32TMRINTCount[0];
    printf("# Timer interrupt counts :  \n");
    while (g_au32TMRINTCount[0] <= 10)
    {
        if (g_au32TMRINTCount[0] != u32InitCount)
        {
            printf("TMR0:%d  TMR1:%d  TMR2:%d  TMR3:%d \n",
                    g_au32TMRINTCount[0], g_au32TMRINTCount[1], g_au32TMRINTCount[2], g_au32TMRINTCount[3]);
            u32InitCount = g_au32TMRINTCount[0];
        }
    }

    /* Reset and stop TIMER0, TIMER1, TIMER2 and TIMER3 counting */
    _TIMER_RESET(TIMER0);
    _TIMER_RESET(TIMER1);
    _TIMER_RESET(TIMER2);
    _TIMER_RESET(TIMER3);

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Delay Time By Timer Interrupt Ticks Test                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_DelayTimeByInterruptTicksTest(void)
{
    printf("# TIMER Settings: \n");
    printf("  TIMER0: Clock source 12 MHz; Periodic mode; Enable interrupt; Pre-scale 1; 100000 interrupt ticks/sec. \n");
    printf("# Check delay time period is 2.5 s. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();
//    printf("\n");

    /* Reset and stop TIMER0 counting first */
    _TIMER_RESET(TIMER0);

    /* Enable TIMER0 NVIC */
    NVIC_EnableIRQ(TMR0_IRQn);

    /* Configure TCMP values of TIMER0 */
    TIMER0->TCMPR = __XTAL/100000;  // For 100kHz when using external 12MHz

    /* Start TIMER0 counting */
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_TDR_EN_Msk |
                      TIMER_TCSR_PRESCALE(1);

    printf("Start Timer counting ...... \n");

    /* Delay 2.5 sec. (1 interrupt tick = 10 us) */
    TIMER_DelayIntTicks(0, 250000);

    printf("Sotp Timer counting ...... \n");

    /* Reset and stop TIMER0 counting */
    _TIMER_RESET(TIMER0);

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Timer External Counter Function Test                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_ExternalCounterFunctionTest(void)
{
    printf("# TIMER Settings: \n");
    printf("  a) TIMER1: Clock source is HCLK(48 MHz); Counter pin enable; One-Shot mode; Enable interrupt; Pre-scale 1; TCMP is 1234.  \n");
    printf("  b) TIMER1: Clock source is HCLK(48 MHz); Counter pin enable; Periodic mode; Enable interrupt; Pre-scale 1; TCMP is 56789. \n");
    printf("# Connect PA.0 to TM1 pin. and pull PA.0 High/Low as TM1 counter input source. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();
//    printf("\n");

    /* Configure PA.0 as GPIO output pin and pull pin status to Low first */
    _GPIO_SET_PIN_MODE(PA, 0, GPIO_PMD_OUTPUT);
    PA0 = 0;

    /* Reset and stop TIMER1 counting first */
    _TIMER_RESET(TIMER1);

    /* Enable TIMER1 NVIC */
    NVIC_EnableIRQ(TMR1_IRQn);

    /* Configure TCMP values of TIMER1 */
    TIMER1->TCMPR = 1234;

    /* Clear Timer interrupt ticks to 0 */
    g_au32TMRINTCount[1] = 0;

    /* Start TIMER1 counting as Timer Counter mode */
    TIMER1->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_CTB_ENABLE |
                      TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    /* To check if TDR of TIMER1 must be 0 as default value */
    if (_TIMER_GET_TDR(TIMER1) != 0)
    {
        printf("Get unexpect counter value and exit test. \n");

        /* Reset and stop TIMER1 */
        _TIMER_RESET(TIMER1);
        return ;
    }

    /* Use PA.0 to generate 1 count to TM1 pin */
    GeneratePACounter(0, 1);

    /* To check if TIMER1 TDR must be 1 after generate 1 count */
    if (_TIMER_GET_TDR(TIMER1) == 1)
    {
        printf("TM1 get 1 count ... \n");
    }else
    {
        printf("Can not get correct counter value and exit test. \n");

        /* Reset and stop TIMER1 */
        _TIMER_RESET(TIMER1);
        return ;
    }

    /* Use PA.0 to generate remains counts to TM1 pin */
    GeneratePACounter(0, (1234 - 1));

    while (1)
    {
        if ((g_au32TMRINTCount[1] == 1) && (_TIMER_GET_TDR(TIMER1) == 0) && ((TIMER1->TCSR&TIMER_TCSR_CEN_ENABLE) == 0))
        {
            printf("TIMER1 External Counter Pin(TM1) test pass at Timer One-Shot mode. \n");
            break;
        }
    }

    /* Reset and stop TIMER1 counting */
    _TIMER_RESET(TIMER1);

    /* Configure TCMP values of TIMER1 */
    TIMER1->TCMPR = 56789;

    /* Clear Timer interrupt ticks to 0 */
    g_au32TMRINTCount[1] = 0;

    /* Start TIMER1 counting as Timer Counter mode */
    TIMER1->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_CTB_ENABLE |
                      TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    /* To check if TDR of TIMER1 must be 0 as default value */
    if (_TIMER_GET_TDR(TIMER1) != 0)
    {
        printf("Get unexpect counter value and exit test. \n");

        /* Reset and stop TIMER1 */
        _TIMER_RESET(TIMER1);
        return ;
    }

    /* Use PA.0 to generate counts to TM1 pin */
    GeneratePACounter(0, (56789 - 1));
    GeneratePACounter(0, 1);

    while (1)
    {
        if ((g_au32TMRINTCount[1] == 1) && (_TIMER_GET_TDR(TIMER1) == 0) && ((TIMER1->TCSR&TIMER_TCSR_CEN_ENABLE) == TIMER_TCSR_CEN_ENABLE))
        {
            printf("TIMER1 External Counter Pin(TM1) test pass at Timer Periodic mode. \n");
            break;
        }
    }

    /* Reset and stop TIMER1 counting */
    _TIMER_RESET(TIMER1);

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Timer External Capture Function Test                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_ExternalCaptureFunctionTest(void)
{
    uint32_t u32InitCount;

    printf("# TIMER Settings: \n");
    printf("  TIMER0: Clock source is 12 MHz; Toggle-Out mode and frequency is 500 Hz; Disable interrupt. \n");
    printf("  TIMER3: Clock source is 12 MHz; Toggle-Out mode and frequency is 1 Hz; Disable interrupt.   \n");
    printf("  TIMER1: Clock source is HCLK(48 MHz); Periodic mode; Disable interrupt; Pre-scale 1; TCMP is 0xFFFFFF; \n");
    printf("          Counter pin enable; Capture pin enable; \n");
    printf("# Generate 500 Hz frequency from TM0 and connect TM0 to TM1 counter pin. \n");
    printf("# Generate 1 Hz frequency from TM3 and connect TM3 to T1EX capture pin. \n");
    printf("# Get 500 ccounts from TM1 pin when each T1EX pin interrupt occurred.  \n");
    printf("Press any key to start test ... \n");
    uart_getchar();
//    printf("\n");

    /* Change TIMER clock source to 12 MHz */
    SYSCLK->CLKSEL1 &= ~SYSCLK_CLKSEL1_TMR3_S_Msk;
    SYSCLK->CLKSEL1 |= SYSCLK_CLKSEL1_TMR3_XTAL;

    /* Reset and stop TIMER0, TIMER1 and TIMER3 counting first */
    _TIMER_RESET(TIMER0);
    _TIMER_RESET(TIMER1);
    _TIMER_RESET(TIMER3);

    /* Enable TIMER1 NVIC for T1EX interrupt */
    NVIC_EnableIRQ(TMR1_IRQn);

    /* Configure TCMP values of TIMER0 and TIMER3 */
    TIMER0->TCMPR = (__XTAL/1000);  // For 1000Hz (Equal to 500Hz toggle rate)
    TIMER3->TCMPR = (__XTAL/2);     // For 2Hz (Prescale = 1)

    /* Start TIMER0 counting and output T0 frequency - 500 Hz*/
    TIMER0->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_TOGGLE | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    /* Start TIMER3 counting and output T3 frequency - 1 Hz */
    TIMER3->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_MODE_TOGGLE | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);

    /* Enable TIMER1 counter and capture function */
    TIMER1->TCMPR = 0xFFFFFF;
    TIMER1->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_CONTINUOUS | TIMER_TCSR_CTB_ENABLE |
                      TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_PRESCALE(1);
    TIMER1->TEXCON = TIMER_TEXCON_MODE_CAP | TIMER_TEXCON_TEXIEN_ENABLE | TIMER_TEXCON_TEXEN_ENABLE;

    /* Check T1EX interrupt counts */
    u32InitCount = g_au32TMRINTCount[1] = 0;
    while (g_au32TMRINTCount[1] <= 10)
    {
        if (g_au32TMRINTCount[1] != u32InitCount)
        {
            printf("   [%d]- %d \n", g_au32TMRINTCount[1], _TIMER_GET_TCAP(TIMER1));
            u32InitCount = g_au32TMRINTCount[1];
        }
    }

    /* Reset and stop TIMER0, TIMER1 and TIMER3 counting */
    _TIMER_RESET(TIMER0);
    _TIMER_RESET(TIMER1);
    _TIMER_RESET(TIMER3);

    /* Restore TIMER3 clock source to IRC 22.1188 MHz */
    SYSCLK->CLKSEL1 &= ~SYSCLK_CLKSEL1_TMR3_S_Msk;
    SYSCLK->CLKSEL1 |= SYSCLK_CLKSEL1_TMR3_IRC22M;

//    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Timer Wake-up Function Test                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void TIMER_PowerDownAndWakeupTest(void)
{
    printf("# TIMER Settings: \n");
    printf("  TIMER2: Clock source IRC 10 kHz; One-Shot mode; Enable interrupt; Enable Wake-up; Pre-scale 1; 2 interrupt ticks/sec. \n");
    printf("# Check system can be waken-up by TIMER2 interrupt event occurred and Power Down period time is about 500 ms. \n");
    printf("Press any key to start test ... \n");
    uart_getchar();
//    printf("\n");

    /* Reset and stop TIMER2 counting first */
    _TIMER_RESET(TIMER2);

    /* Enable TIMER0 NVIC */
    NVIC_EnableIRQ(TMR2_IRQn);

    /* Configure TCMP values of TIMER2 */
    TIMER2->TCMPR = (__IRC10K/2);  // For 2 ticks per second when using IRC 10 kHz (Prescale = 1)

    printf("Start Timer counting and enter to Power Down ...... \n");

    /* Start TIMER2 counting */
    TIMER2->TCSR = TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_WAKE_EN_Msk |
                    TIMER_TCSR_PRESCALE(1);

    g_au32TMRINTCount[2] = 0;

    /* System entry into Power Down Mode */
    PowerDownFunction();

    /* Check if TIMER2 interrupt occurred and Power Down Wake-up Interrupt Flag occurred */
    while (1)
    {
        if (((SYSCLK->PWRCON & SYSCLK_PWRCON_PD_WU_STS_Msk) == SYSCLK_PWRCON_PD_WU_STS_Msk) && (g_au32TMRINTCount[2] == 1))
            break;
    }

    /* Clear Power Down Wake-up Interrupt Flag */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_PD_WU_STS_Msk;

    /* Check if TIMER2 CEN and CACT are auto-cleared by hardward in One-Shot mode */
    while (1)
    {
        if ((TIMER2->TCSR & (TIMER_TCSR_CACT_Msk | TIMER_TCSR_CEN_Msk)) == 0x0)
            break;
    }
    printf("Waken-up by TIMER2 interrupt occurred ...... \n");

    /* Reset and stop TIMER2 counting */
    _TIMER_RESET(TIMER2);

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

    /* Enable internal 10 kHz Oscillator */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_IRC10K_EN_Msk;

    /* Enable internal 22.1184 MHz Oscillator */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_IRC22M_EN_Msk;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_XTL12M_STB_Msk | SYSCLK_CLKSTATUS_IRC10K_STB_Msk | SYSCLK_CLKSTATUS_IRC22M_STB_Msk);

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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_TMR0_EN_Msk | SYSCLK_APBCLK_TMR1_EN_Msk | SYSCLK_APBCLK_TMR2_EN_Msk | SYSCLK_APBCLK_TMR3_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL | SYSCLK_CLKSEL1_TMR0_XTAL | SYSCLK_CLKSEL1_TMR1_HCLK | SYSCLK_CLKSEL1_TMR2_IRC10K | SYSCLK_CLKSEL1_TMR3_IRC22M;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD, UART0 TXD; TMR0 ~ TMR3 external counter pins; TMR0, TMR2 and TMR3 external capture pins */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0 |
                    SYS_GPB_MFP_PB8_TM0 | SYS_GPB_MFP_PB9_TM1 | SYS_GPB_MFP_PB10_TM2 | SYS_GPB_MFP_PB11_TM3 |
                    SYS_GPB_MFP_PB15_T0EX | SYS_GPB_MFP_PB2_T2EX | SYS_GPB_MFP_PB3_T3EX;

    /* Set PE multi-function pin for TMR1 external capture pin */
    SYS->GPE_MFP = SYS_GPE_MFP_PE5_T1EX;

    /* Set ALT MPF settings for TMR0 ~ TMR3 external counter and capture functions */
    SYS->ALT_MFP = SYS_ALT_MFP_PB8_TM0 | SYS_ALT_MFP_PB9_TM1 | SYS_ALT_MFP_PB10_TM2 | SYS_ALT_MFP_PB11_TM3 |
                  SYS_ALT_MFP_PB15_T0EX | SYS_ALT_MFP_PE5_T1EX | SYS_ALT_MFP_PB2_T2EX | SYS_ALT_MFP_PB3_T3EX;

    /* Set ALT MPF1 settings for TMR3 external capture */
    SYS->ALT_MFP1 = SYS_ALT_MFP1_PB3_T3EX;

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

