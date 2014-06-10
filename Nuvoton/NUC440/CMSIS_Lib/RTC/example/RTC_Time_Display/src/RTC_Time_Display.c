/****************************************************************************
 * @file     RTC_Time_Display.c
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 13/11/10 9:33a $
 * @brief    NUC470 Series RTC Interface Controller Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "SYS.h"
#include "CLK.h"
#include "UART.h"
#include "RTC.h"
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

volatile uint32_t  g_u32TICK = false;
void UART0_Init();
void Delay(uint32_t ucnt);
void SYS_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/

int32_t RTC_Time_Display(void)
{
    S_RTC_TIME_DATA_T sInitTime;

    SYS_Init();
    UART0_Init();

    /* Time Setting */
    sInitTime.u32Year       = 2013;
    sInitTime.u32Month      = 10;
    sInitTime.u32Day        = 15;
    sInitTime.u32Hour       = 12;
    sInitTime.u32Minute     = 30;
    sInitTime.u32Second     = 0;
    sInitTime.u32DayOfWeek  = RTC_TUESDAY;
    sInitTime.u32TimeScale  = RTC_CLOCK_24;

    RTC_Open(&sInitTime);

    printf("\n RTC Time Display Test (Exit after 5 seconds)\n\n");

    /* Set Tick Period */
    RTC_SetTickPeriod(RTC_TICK_1_SEC);

    /* Enable RTC Tick Interrupt */
    RTC_EnableInt(RTC_RIER_TIER_Msk);
    NVIC_EnableIRQ(RTC_IRQn);

    g_u32TICK = 0;
    while(g_u32TICK < 5);

    printf("\n RTC Time Display Test End !!\n");

    /* Disable RTC Tick Interrupt */
    RTC_DisableInt(RTC_RIER_TIER_Msk);
    NVIC_DisableIRQ(RTC_IRQn);

    while(1);

}

/*---------------------------------------------------------------------------------------------------------*/
/* RTC Tick Handle                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
void RTC_TickHandle(void)
{
    S_RTC_TIME_DATA_T sCurTime;

    /* Get the current time */
    RTC_GetDatAndTime(&sCurTime);

    printf(" Current Time:%d/%02d/%02d %02d:%02d:%02d\n",sCurTime.u32Year,sCurTime.u32Month,sCurTime.u32Day,sCurTime.u32Hour,sCurTime.u32Minute,sCurTime.u32Second);

    g_u32TICK++;
}

/**
  * @brief  RTC ISR to handle interrupt event
  * @param  None
  * @retval None
  */
void RTC_IRQHandler(void)
{

    if ( (RTC->RIER & RTC_RIER_TIER_Msk) && (RTC->RIIR & RTC_RIIR_TIF_Msk) ) {      /* tick interrupt occurred */
        RTC->RIIR = 0x2;

        RTC_TickHandle();
    }

}

void Delay(uint32_t ucnt)
{
    volatile uint32_t i = ucnt;

    while (i--);
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK->PWRCON |= CLK_PWRCON_HXT_EN_Msk; // XTAL12M (HXT) Enabled

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HXT;

    /* Enable IP clock */
    CLK->APBCLK0 |= CLK_APBCLK0_UART0_EN_Msk; // UART0 Clock Enable
    CLK->APBCLK0 |= CLK_APBCLK0_RTC_EN_Msk; // RTC Clock Enable

    /* Select IP clock source */
    CLK->CLKSEL1 &= ~CLK_CLKSEL1_UART_S_Msk;
    CLK->CLKSEL1 |= (0x0 << CLK_CLKSEL1_UART_S_Pos);// Clock source from external 12 MHz or 32 KHz crystal clock

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set PG multi-function pins for UART0 RXD, TXD */
    SYS->GPG_MFPL &= ~(SYS_GPG_MFPL_PG1_MFP_Msk | SYS_GPG_MFPL_PG2_MFP_Msk);
    SYS->GPG_MFPL |= (SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD);

    /* Lock protected registers */
    SYS_LockReg();

}

void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    UART_Open(UART0, 115200);
}





/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/



