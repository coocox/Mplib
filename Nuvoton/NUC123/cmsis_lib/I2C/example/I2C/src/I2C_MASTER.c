
/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test I2C master .
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
#include "I2C.h"

#define I2C_SLA              0xA0
#define I2C_WR               0x00
#define I2C_RD               0x01

#define FrameSize      16

char g_txBuf[FrameSize] = {0};
char g_rxBuf[FrameSize] = {0};

uint8_t txByte_Count=0;
uint8_t	rxByte_Count=0;

uint8_t rx_tx=0;

void Init_I2C(void);
void SYS_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int I2C_Master(void)
{
    int i;
    SYS_Init();

    Init_I2C();
    GPIO_SET_MODE(PB, 4, GPIO_OUTPUT);

    for(i=0;i<FrameSize;i++)
        g_txBuf[i] = i;


    while(1)
    {
        I2C_START(I2C0);
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
    CLK_HXT_ENABLE();                                    //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB));                  //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                      //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock
    SYS_LockReg();                                          //En:Lock protected registers
}


/**
 * @brief       I2C0 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     I2C0 init
 */
void Init_I2C(void)
{
    GPIO_SET_MODE(PF,2,GPIO_OPEN_DRAIN );				  //中:配置I2C脚为OD门//en:Enable I2C PIN as OD
    GPIO_SET_MODE(PF,3,GPIO_OPEN_DRAIN );

    GPIO_I2C0();                              //中:配置I2C引脚//en: confige PF.2 and PF.3 as I2C function

    /* set I2CLK = 50K */
    DrvI2C_Init(I2C0, 50000, TRUE);
}


/**
 * @brief       I2C0 ISR routine
 *
 * @param       None
 *
 * @return      None
 *
 * @details     transmit and recieve data in ISR routine
 */
void I2C0_IRQHandler(void)
{

    uint32_t status =I2C_GET_I2CSTATUS(I2C0);				   //中：先读出状态字节//en：Read the status first

    switch(status)
    {
        case 0x08 :								     //en:START has been sent
            rx_tx++;
            if(rx_tx&1==1)
                I2C_SET_DATA(I2C0,I2C_SLA | I2C_RD);
            else
                I2C_SET_DATA(I2C0,I2C_SLA | I2C_WR);
            I2C_CLEAR_SI(I2C0);
            break;
        case 0x20 :                            		 //en:SLA+W has been sent,No ACK bit will be received
        case 0x18 :									    	//en:SLA+W has been sent,ACK bit will be received
            I2C_SET_DATA(I2C0,g_txBuf[txByte_Count++]);   //en: sent first data
            I2C_CLEAR_SI(I2C0);
            break ;
        case 0x28 :										   //en: data has sent, ack back
            I2C_SET_DATA(I2C0,g_txBuf[txByte_Count++]);
            I2C_CLEAR_SI(I2C0);
            if(txByte_Count>=FrameSize)
            {
                txByte_Count=0;
            }
            break;
        case 0x30 :				//en: last data	has sent,No ack back
            I2C_STOP(I2C0);
            break ;
        case 0x10 :				//en: A repeat start has been transmitted
            break ;
        case 0x38 :				//en: Arbitration lost in SLA+R/W or data byte
            break ;
//---------------------------------------------------------------
        case 0x40 : 									 //en:SLA+R has been sent
            I2C_SET_AA(I2C0);
            I2C_CLEAR_SI(I2C0);                              //中:清零SI//en: Clear SI
            break ;

        case 0x50 : 		      							 //en: data has received, ack back
            g_rxBuf[rxByte_Count++]=I2C_GET_DATA(I2C0);
            if(rxByte_Count==(FrameSize-1))
            {
                I2C_CLEAR_AA(I2C0);						   //en:  last data,no ack back
                I2C_CLEAR_SI(I2C0);
            }
            else
            {
                I2C_SET_AA(I2C0);
                I2C_CLEAR_SI(I2C0);                             //中:清零SI//en: Clear SI
            }
            break ;

        case 0x58 :                                            //en: last data has received, no ack back
            g_rxBuf[rxByte_Count++]=I2C_GET_DATA(I2C0);
            for(rxByte_Count=0;rxByte_Count<FrameSize;rxByte_Count++)
            {
                if(g_rxBuf[rxByte_Count]!=rxByte_Count)
                while(1);						  //en：Received data is not correct
            }
            rxByte_Count=0;
            GPIO_INVERSE_PIN(PB4);					 //en:Received data is correct, toggle LED
            I2C_STOP(I2C0);
            break ;

        default :
            break ;
	}
}







