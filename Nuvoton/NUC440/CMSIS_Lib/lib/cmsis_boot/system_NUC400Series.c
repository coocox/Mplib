/**************************************************************************//**
 * @file     system_NUC400Series.c
 * @version  V1.00
 * $Revision: 10 $
 * $Date: 13/11/10 9:32a $
 * @brief    NUC400 series system clock init code and assert handler
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "NUC400Series.h"
#include "rtc.h"
#include "clk.h"
/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __HSI;               /*!< System Clock Frequency (Core Clock)*/
uint32_t CyclesPerUs      = (__HSI / 1000000);  /*!< Cycles per micro second            */
uint32_t gau32ClkSrcTbl[] = {__HXT, __LXT, 0, __LIRC, 0, 0, 0, __HIRC}; /*!< System clock source table */



/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
    uint32_t u32Freq, u32ClkSrc;
    uint32_t u32HclkDiv;

    u32ClkSrc = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;

    if(u32ClkSrc != CLK_CLKSEL0_HCLK_S_PLL) {
        /* Use the clock sources directly */
        u32Freq = gau32ClkSrcTbl[u32ClkSrc];
    } else {
        /* Use PLL clock */
        u32Freq = CLK_GetPLLClockFreq();
    }

    u32HclkDiv = (CLK->CLKDIV0 & CLK_CLKDIV0_HCLK_N_Msk) + 1;

    /* Update System Core Clock */
    SystemCoreClock = u32Freq/u32HclkDiv;

    CyclesPerUs = (SystemCoreClock + 500000) / 1000000;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 */
void SystemInit (void)
{
    uint32_t u32RTC_EN_Flag = 0;

    /* FPU settings ------------------------------------------------------------*/
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2) |                 /* set CP10 Full Access */
                   (3UL << 11*2)  );               /* set CP11 Full Access */
#endif

    /* ------------------ Release Tamper pin ---------------------------------*/
    /* Waiting for 10kHz clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_LIRC_STB_Msk);

    u32RTC_EN_Flag = ((CLK->APBCLK0 & CLK_APBCLK0_RTC_EN_Msk) >> CLK_APBCLK0_RTC_EN_Pos);

    if(!u32RTC_EN_Flag) {
        CLK->APBCLK0 |= CLK_APBCLK0_RTC_EN_Msk; // RTC Clock Enable
    }

    RTC->INIR = RTC_INIT_KEY;
    while(RTC->INIR != 0x1);

    if(!(RTC->TAMPCTRL & RTC_TAMPCTRL_TIEN_Msk)) {
        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));

        RTC->SPRCTL |= RTC_SPRCTL_SPREN_Msk;

        while(!(RTC->SPRCTL & RTC_SPRCTL_SPRRDY_Msk));

        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));

        RTC->SPR[23] = 0x80000000;
        while(!(RTC->SPRCTL & RTC_SPRCTL_SPRRDY_Msk));

        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));

        RTC->SPRCTL &= ~RTC_SPRCTL_SPREN_Msk;
        while(!(RTC->SPRCTL & RTC_SPRCTL_SPRRDY_Msk));

        RTC->AER = RTC_WRITE_KEY;
        while(!(RTC->AER & RTC_AER_ENF_Msk));

        RTC->RIIR = RTC_RIIR_TIF_Msk;
    }

    if(!u32RTC_EN_Flag) {
        CLK->APBCLK0 &= ~CLK_APBCLK0_RTC_EN_Msk; // RTC Clock Disable
    }
    /*------------------------------------------------------------------------*/

}
/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
