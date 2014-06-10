/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    NUC123 Series General Purpose I/O Driver Sample Code
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

void SYS_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int Example_LED(void)
{
    SYS_Init();                                  //En:Init System clock

    GPIO_SET_MODE(PB, 4, GPIO_OUTPUT);   //En:Configure PB.4 as Output mode

    while(1)
    {
        GPIO_SET_PIN(PB4);                //En:Set PB.4 high level to switch led off
        SYS_SysTickDelay(500000);				 //En:Delay 500ms
        GPIO_CLR_PIN(PB4);              //En:Set PB.4 low level to switch led on
        SYS_SysTickDelay(500000);				 //En:Delay 500ms
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
    CLK_HXT_ENABLE();                                        //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB)); //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                  //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}

