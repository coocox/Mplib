/******************************************************************************
 * @file     nano1xx_sys.c
 * @brief    NANO1xx SYS driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvSYS_FUNC Sysmte Driver API
  * @{
  */

#if 0
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

/// @cond 
static uint16_t _DrvSYS_PLL_Table[5][6] = {
     /* Output Freq. */
     /* 45MHz,                48MHz,               90MHz,               96MHz,               120MHz,               128MHz */
		{PLL_NOT_SUPPORTED,   PLL_IN_4M_OUT_48M,   PLL_NOT_SUPPORTED,   PLL_IN_4M_OUT_96M,   PLL_IN_4M_OUT_120M,   PLL_IN_4M_OUT_128M},		/* Input 4MHz */
		{PLL_NOT_SUPPORTED,   PLL_IN_8M_OUT_48M,   PLL_NOT_SUPPORTED,   PLL_IN_8M_OUT_96M,   PLL_NOT_SUPPORTED,    PLL_IN_8M_OUT_128M},		/* Input 8MHz */
		{PLL_NOT_SUPPORTED,   PLL_IN_12M_OUT_48M,  PLL_NOT_SUPPORTED,   PLL_IN_12M_OUT_96M,  PLL_IN_12M_OUT_120M,  PLL_NOT_SUPPORTED},		/* Input 12MHz */
		{PLL_IN_15M_OUT_45M,  PLL_NOT_SUPPORTED,   PLL_IN_15M_OUT_90M,  PLL_NOT_SUPPORTED,   PLL_IN_15M_OUT_120M,  PLL_NOT_SUPPORTED},		/* Input 15MHz */
		{PLL_NOT_SUPPORTED,   PLL_IN_24M_OUT_48M,  PLL_NOT_SUPPORTED,   PLL_IN_24M_OUT_96M,  PLL_IN_24M_OUT_120M,  PLL_NOT_SUPPORTED}		/* Input 24MHz */
};

/// @endcond


/**
  * @brief  Calculate current PLL clock frquency. 
  * @param  None.
  * @return PLL clock frquency. The clock UNIT is in Hz.
  */
uint32_t DrvSYS_GetPLLClockFreq(void)
{
    uint32_t u32Freq =0, u32PLLSrc;
    uint32_t u32NO, u32NR, u32IN_DV, u32PllReg;

    u32PllReg = CLK->PLLCON;

    if (u32PllReg & CLK_PLLCON_PD_EN)  
        return 0;	 /* PLL is in power down mode */
	
    if (u32PllReg & CLK_PLLSRC_HIRC)
        u32PLLSrc = __IRC22M;
    else
        u32PLLSrc = __XTAL;

    u32NO = (u32PllReg & CLK_PLLCTL_OUT_DV) ? 2: 1;

    u32IN_DV = (u32PllReg & CLK_PLLCTL_IN_DIVIDER_MASK) >> 8;
    if (u32IN_DV == 0)
        u32NR = 2;
    else if (u32IN_DV == 1)
        u32NR = 4;
    else if (u32IN_DV == 2)
        u32NR = 8;
    else
        u32NR = 16;

    u32Freq = u32PLLSrc * ((u32PllReg & CLK_PLLCTL_FB_DIVIDER_MASK) +32) / u32NR / u32NO;

    return u32Freq;
}
#endif

/**
  * @brief  Get current HCLK clock frquency. 
  * @param  None.
  * @return HCLK clock frquency. The clock UNIT is in Hz.
  */
uint32_t DrvSYS_GetHCLKFreq(void)
{
	
    uint32_t u32Freqout, u32AHBDivider, u32ClkSel;

    u32ClkSel = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;

    if (u32ClkSel == CLK_HCLK_HXT)	/* external HXT crystal clock */
    {
        u32Freqout = __XTAL;	
    }
    else if((u32ClkSel == CLK_HCLK_PLL) || (u32ClkSel == CLK_HCLK_PLL_2))		/* PLL clock */
    {
        u32Freqout = CLK_GetPLLClockFreq();
        if(u32ClkSel == CLK_HCLK_PLL_2)
            u32Freqout /= 2;
    }
    else if(u32ClkSel == CLK_HCLK_LIRC)	/* internal LIRC oscillator clock */
    {
        u32Freqout = __IRC10K;
    }
    else									/* internal HIRC oscillator clock */
    {
        u32Freqout = __IRC22M;
	
    }
    u32AHBDivider = (CLK->CLKDIV & CLK_CLKDIV_HCLK_N_Msk) + 1 ;
	
    return (u32Freqout/u32AHBDivider);	
}

#if 0
/**
  * @brief  Enable chip clock sources including HXT, LXT, LIRX, HIRC and PLL. And then set HCLK clock source and divider.
  *         If the second parameter is NOT NULL, also enable the clock and set the source/divider of peripheral functions. 
  * @param  sChipCfg    - [in], The pointer to the structure which stores the configuration of chip clock source and HCLK.
  *                              u32ChipClkEn : CLK_PWRCTL_XXX_EN, where XXX could be HXT, LXT, HIRC or LIRC
  *                              u32PLLClkSrc : CLK_PLLCTL_PLLSRC_HIRC or CLK_PLLCTL_PLLSRC_HXT
  *                              u8PLLEnable : 1 to enable PLL, 0 to disable PLL        
  *                              ePLLInFreq  : E_SYS_PLLIN_4M, _8M, _12M, _15M or _24M                     
  *                              ePLLOutFreq : E_SYS_PLLOUT_45M, _48M, _90M, _96M, _120M or _128M  
  *                              u32HClkSrc : CLK_CLKSEL0_HCLK_XXX, where XXX could be HXT, LXT, PLL, HIRC or LIRC
  *                              u32HClkDiv : 0 ~ 15       
  *                                                                                                         
  * @param  sIPCfg      - [in], The pointer to the structure which stores the configuration of peripheral functions.                                         
  *                                 u32AHBClkEn : The combination of CLK_AHBCLK_XXX_EN, where XXX can be GPIO, PDMA, ISP, EBI, SRAM, TICK            
  *                                 u32APBClkEn : The combination of CLK_APBCLK_XXX_EN, the XXX can be :            
  *                                               WDT, RTC, TMR0~3, FDIV, SC0~2, I2C0~1, SPI0~2, UART0~1, PWM0_CH01, PWM0_CH23,     
  *                                               PWM1_CH01, PWM1_CH23, TK, DAC, LCD, USBD, ADC, I2S.           
  *                                                  													    
  *                                 u32ClkSel1  : The combination of CLK_CLKSEL1_XXX_YYY, search "CLK_CLKSEL1_" in nano1xx.h for possible values.			    
  *                                 u32ClkSel2  : The combination of CLK_CLKSEL2_XXX_YYY, search "CLK_CLKSEL2_" in nano1xx.h for possible values.		    
  *                                 sClkDiv     : Structure to store clock divider of devices. The elements  
  *                                               are listed below.										    
  *                                                    u8USBDiv  : 0 ~ 15, USBD clock divider			    
  *                                                    u8UARTDiv : 0 ~ 15, UART clock divider			   
  *                                                    u8I2SDiv  : 0 ~ 15, I2S clock divider				   
  *                                                    u8ADCDiv  : 0 ~ 255, ADC clock divider 			   
  *                                                    u8TKDiv   : 0 ~ 15, TK clock divider                 
  *                                                    u8SC0Div  : 0 ~ 15, SC0 clock divider                	
  *                                                    u8SC1Div  : 0 ~ 15, SC1 clock divider                
  * @return Execution result.
  * @retval  0 Success                                                              
  * @retval  -1 The chip clock sources are not stable
  * @retval  -2 The selected PLL setting is not supported
  * * retval -3 The PLL clock output is not stable
  */
int32_t SYS_InitChipClock(S_SYS_CHIP_CLKCFG *sChipCfg)
{
    uint32_t u32ClkEn, u32ClkSts, u32PllCtl;	
    volatile uint32_t delayCnt;
	
    assert_param(CHECK_CLK_CONFIG(sChipCfg));               /* Check input parameter */
    assert_param(CHECK_HCLK_SOURCE(sChipCfg->u32HClkSrc));  /* Check HCLK clock select */

    /* enable chip clock sources */
    u32ClkEn = u32ClkSts = (sChipCfg->u32ChipClkEn) & 0x0F; 
    if (u32ClkSts & CLK_PWRCTL_HIRC_EN) 
        u32ClkSts = (u32ClkSts & ~CLK_PWRCTL_HIRC_EN) | CLK_CLKSTATUS_HIRC_STB;
	
    SYS_SetChipClockSrc(u32ClkEn, 1);  /* enable the selected chip clock sources */
	
    for (delayCnt=0; delayCnt<100000; delayCnt++)
        if ((CLK->CLKSTATUS & u32ClkSts) == u32ClkSts)
            break;

    if (delayCnt == 100000)
        return -1;

    /* enable PLL */
    if (sChipCfg->u8PLLEnable == 1)  {

        /* check PLL in clock freq. */
        assert_param(CHECK_PLLIN_CLK(sChipCfg->ePLLInFreq));
        assert_param(CHECK_PLLOUT_CLK(sChipCfg->ePLLOutFreq));
		
        u32PllCtl = _DrvSYS_PLL_Table[sChipCfg->ePLLInFreq][sChipCfg->ePLLOutFreq];

        if (u32PllCtl == PLL_NOT_SUPPORTED)
            return -2;

        /* select correct pll clock source */
        u32PllCtl |= sChipCfg->u32PLLClkSrc;

        /* set PLL control reg and waits for PLL clock stable */
        CLK->PLLCTL = u32PllCtl;

        for (delayCnt=0; delayCnt<100000; delayCnt++)
            if (CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB)
                break;

        if (delayCnt == 100000)
            return -3;		
    }

	/* set HCLK divider and source */
    CLK->CLKDIV0 = (CLK->CLKDIV0 & ~CLK_CLKDIV0_HCLK_MASK) | sChipCfg->u32HClkDiv;
    SYS_SelectHCLKSource(sChipCfg->u32HClkSrc); /* select required clock source for HCLk */

    return 0;
}
#endif


/*@}*/ /* end of group DrvSYS_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
