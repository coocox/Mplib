/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test WWDT
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
#include "WWDT.h"

void SYS_Init(void);


void WDT_IRQHandler()
{
    if(WWDT_GET_INT_FLAG())
    {
        WWDT_TIMER_RESET();			   //En: Reset WWDT timer,if not reset timer will cause chip reset
        WWDT_CLEAR_INT_FLAG();		   //En: Clear interrupt flag
    }
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
    SYS_UnlockReg();                                        //En:Unlock protected registers
    GPIO_XT1();
    CLK_HXT_ENABLE();                                    //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB));                  //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                      //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int WWDT_Example(void)
{
    SYS_Init();	                                        //中:系统初始化//en:System initiation
    DrvWWDT_Init(32,13,CLK_WWDT_LIRC);                                        //中:初始化WDT//en: Initialize WDT
    while(1);
}

