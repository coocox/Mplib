/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include "NUC123Series.h"
#include "CLOCK.h"


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock  = __HSI;   /*!< System Clock Frequency (Core Clock) */
uint32_t CyclesPerUs      = (__HSI / 1000000); /* Cycles per micro second */
uint32_t PllClock         = __HSI;              /*!< PLL Output Clock Frequency          */
uint32_t gau32ClkSrcTbl[] = {__XTAL, __HSI, __IRC10K, __IRC22M};

/*----------------------------------------------------------------------------
  Clock functions
  This function is used to update the variable SystemCoreClock 
  and must be called whenever the core clock is changed.
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
    uint32_t u32Freq, u32ClkSrc;
    uint32_t u32HclkDiv;

    /* Update PLL Clock */
    PllClock = CLK_GetPLLClockFreq();
 
    u32ClkSrc = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;

    if(u32ClkSrc != CLK_HCLK_PLL)
    {
        /* Use the clock sources directly */
        u32Freq = gau32ClkSrcTbl[u32ClkSrc];
    }
    else
    {
        /* Use PLL clock */
        u32Freq = PllClock;
    }
 
    u32HclkDiv = (CLK->CLKDIV & CLK_CLKDIV_HCLK_N_Msk) + 1; 
    
    /* Update System Core Clock */
    SystemCoreClock = u32Freq/u32HclkDiv;

    CyclesPerUs = (SystemCoreClock + 500000) / 1000000;
}

/*---------------------------------------------------------------------------------------------------------*/
/* Function: SystemInit                                                                                    */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*      None                                                                                               */
/*                                                                                                         */
/* Returns:                                                                                                */
/*      None                                                                                               */
/*                                                                                                         */
/* Description:                                                                                            */
/*      The necessary initializaiton of systerm.                                                           */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void SystemInit (void)
{
#ifdef INIT_SYSCLK_AT_BOOTING
    int32_t i32TimeoutCnt;
    uint32_t u32HclkSelect;
    int8_t i8IsPllEn;

    PllClock = 0;
    i8IsPllEn = 0;
    u32HclkSelect = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;
    if(u32HclkSelect == CLK_HCLK_XTL12M)
    {
        /* Set to 72MHz system clock frequency when clock source is from external 12MHz */
        CLK_SET_PLL_FRQ(CLK_PLLSRC_XTL12M, 0x4222);      
        
        /* Waiting for PLL ready */
        i32TimeoutCnt = (__XTAL / 1000); /* Timeout is about 1ms */
        while(!CLK_IS_STABLE(CLK_PLL_STB))
        {
            if(i32TimeoutCnt-- <= 0)
                break;    
        }

        i8IsPllEn = 1;
    }
    else if(u32HclkSelect == CLK_HCLK_OSC22M)
    {
        /* Set to 72MHz system clock frequency when clock source is from internal 22.1184MHz RC clock */
        CLK_SET_PLL_FRQ(CLK_PLLSRC_OSC22M, 0x5246);       
        
        /* Waiting for PLL ready */
        i32TimeoutCnt = (__IRC22M / 1000); /* Timeout is about 1ms */
        while(!CLK_IS_STABLE(CLK_PLL_STB))
        {
            if(i32TimeoutCnt-- <= 0)
                break;    
        }

        i8IsPllEn = 1;
    }

    if(i8IsPllEn)    
    {
        /* Set PLL as HCLK clock source (HCLK_S is locked setting)*/
        SYS_UnlockReg();
        CLK_SET_HCLK_SRC(CLK_HCLK_PLL);
        SYS_LockReg();
    }
#endif
}
