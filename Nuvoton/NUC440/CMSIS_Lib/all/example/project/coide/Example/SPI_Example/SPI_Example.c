/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test SPI master mode.
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
#include "SPI.h"


#define FrameSize	32

char g_txBuf[FrameSize];
char g_rxBuf[FrameSize];

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int SPI_Example(void)
{
    int i;
    SYS_Init();
    SPI0_Init();
    for(i=0;i<FrameSize;i++)
        g_txBuf[i] = i;
    GPIO_SET_MODE(PB, 4, GPIO_OUTPUT);

    /*waiting for slave ready*/
    do
    {
    	SPI_WRITE_TX0(SPI0, 0x55);
        SPI_SET_GO(SPI0);
        while(SPI_IS_BUSY(SPI0));
        SYS_SysTickDelay(100);				 //En:Delay 100us;
    }while(SPI_GET_RX0_DATA(SPI0)!=0xAA);	   //en: slave is ready

    /*waiting for slave ready*/
    SYS_SysTickDelay(100);				 //En:Delay 100us;

    while(1)
    {
    	/* Send package and Receive at the same time*/
        for(i=0;i<FrameSize;i++)
        {
            SPI_WRITE_TX0(SPI0, g_txBuf[i]);
            SPI_SET_GO(SPI0);
            while(SPI_IS_BUSY(SPI0));

            g_rxBuf[i] = SPI_GET_RX0_DATA(SPI0);
            if(g_rxBuf[i] != g_txBuf[i])
            {
                while(1);						//en: Received data is error
            }
            SYS_SysTickDelay(1000);				 //En:Delay 1000us;
        }

        GPIO_INVERSE_PIN(PB4);			//en: Received data is correct, toggle LED
        memset(g_rxBuf, 0, sizeof(g_rxBuf));
        SYS_SysTickDelay(100000);
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
    CLK_HXT_ENABLE();                                       //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB));                  //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                         //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}

/**
 * @brief       SPI0 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     SPI0 init
 */
void SPI0_Init(void)
{
    /* Enable IP clock */
    SET_SPI0_CLKSRC(CLK_SPI0_HCLK);			   //En:Select SPI0 clock source

    GPIO_SPI0();                          		   //中:配置PC0~3为SPI功能//en:Configure PC0~3 as SPI function

    DrvSPI_Init(SPI0, SPI_MASTER, SPI_TYPE2, 8);
    SPI_SET_DIVIDER(SPI0, 2);                      //中:设置SPI的分频值//en:Set divider of SPI_CLK  SPIclk = Pclk/((DIVIDER+1)*2)

    SPI_SET_MSB_FIRST(SPI0);					  //En:MSB first
    SPI_SET_SS(SPI0, SPI_SS_HIGH_TRIGGER, SPI_SW_SS/*SPI_AUTO_SS*/); //En: Set slave auto select, high active
    SPI_SET_SS0(SPI0);	//En:active SS0
}

