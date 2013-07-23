/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "NUC123Series.h"
#include "VCOMSys.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
void SYS_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function									                                           			   */
/*---------------------------------------------------------------------------------------------------------*/
void Smpl_VCOM (void)
{
    SYS_Init();
    VCOM_MainProcess();					//en: Execute VCOM process
}


/**
 * @brief       System init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock
 */
void SYS_Init(void)
{
    UNLOCKREG();						//en: Unlock the locked registers

    GPIO_XT1();						//en: Enable XTAL PINs
    CLK_HXT_ENABLE();				//en: Enable XTAL
    while(!CLK_IS_STABLE(CLK_HXT_STB));	//en: Wait XTAL Stable

    //en: configure PLL
    SET_PLL_CLKSRC(CLK_PLLSRC_HXT);		//en: Configure PLL Source is HXT
    CLK_SET_PLL_NO(CLK_PLLCON_NO_4);
    CLK_SET_PLL_NR(7);
    CLK_SET_PLL_NF(112);
    CLK_PLL_PD_DISABLE();
    CLK_PLL_OUTP_EN();
    while(!CLK_IS_STABLE(CLK_PLL_STB));		//en: Wait PLL Stable
    SET_HCLK_CLKSRC(CLK_HCLK_PLL);			//en: Configure HCLK to be PLL output

    SystemCoreClockUpdate();				//en: Update system core clock

    LOCKREG(); //en: Re-lock the locked registers
}

