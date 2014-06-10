/**************************************************************************//**
 * @file     I2C_Slave.c
 * @version  V2.00
 * $Revision: 5 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 Series I2C Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "uart.h"
#include "i2c.h"
uint32_t slave_buff_addr;
uint8_t g_u8SlvData[256];
uint8_t g_au8RxData[3];
/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8DeviceAddr;
uint8_t g_au8TxData[3];
uint8_t g_u8RxData;
uint8_t g_u8DataLen;

typedef void (*I2C_FUNC)(uint32_t u32Status);

static I2C_FUNC s_I2C3HandlerFn = NULL;
void I2C_SlaveTRx(uint32_t u32Status);
void SYS_Init(void);
void I2C3_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t I2C_Slave(void)
{
    uint32_t i;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    /*
        This sample code sets I2C bus clock to 100kHz. Then, Master accesses Slave with Byte Write
        and Byte Read operations, and check if the read data is equal to the programmed data.
    */

    printf("+-------------------------------------------------------+\n");
    printf("|        NUC400 I2C Driver Sample Code(Slave)           |\n");
    printf("+-------------------------------------------------------+\n");

    /* Init I2C3 */
    I2C3_Init();

    /* I2C enter no address SLV mode */
    I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);

    for (i = 0; i < 0x100; i++) {
        g_u8SlvData[i] = 0;
    }

    /* I2C function to Slave receive/transmit data */
    s_I2C3HandlerFn=I2C_SlaveTRx;

    printf("\n");
    printf("I2C Slave Mode is Running.\n");

    while(1);
}



/*---------------------------------------------------------------------------------------------------------*/
/*  I2C3 IRQ Handler                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void I2C3_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = I2C3->I2CSTATUS;

    if (I2C3->I2CTOC & I2C_I2CTOC_TIF_Msk) {
        /* Clear I2C3 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C3);
    } else {
        if (s_I2C3HandlerFn != NULL)
            s_I2C3HandlerFn(u32Status);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C TRx Callback Function                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_SlaveTRx(uint32_t u32Status)
{
    if (u32Status == 0x60) {                    /* Own SLA+W has been receive; ACK has been return */
        g_u8DataLen = 0;
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else if (u32Status == 0x80)                 /* Previously address with own SLA address
                                                   Data has been received; ACK has been returned*/
    {
        g_au8RxData[g_u8DataLen] = I2C_GET_DATA(I2C3);;
        g_u8DataLen++;

        if (g_u8DataLen == 2) {
            slave_buff_addr = (g_au8RxData[0] << 8) + g_au8RxData[1];
        }
        if (g_u8DataLen == 3) {
            g_u8SlvData[slave_buff_addr] = g_au8RxData[2];
            g_u8DataLen = 0;
        }
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else if(u32Status == 0xA8) {              /* Own SLA+R has been receive; ACK has been return */

        I2C_SET_DATA(I2C3, g_u8SlvData[slave_buff_addr]);
        slave_buff_addr++;
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else if (u32Status == 0xC0)                 /* Data byte or last data in I2CDAT has been transmitted
                                                   Not ACK has been received */
    {
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else if (u32Status == 0x88)                 /* Previously addressed with own SLA address; NOT ACK has
                                                   been returned */
    {
        g_u8DataLen = 0;
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else if (u32Status == 0xA0)                 /* A STOP or repeated START has been received while still
                                                   addressed as Slave/Receiver*/
    {
        g_u8DataLen = 0;
        I2C_SET_CONTROL_REG(I2C3, I2C_SI | I2C_AA);
    } else {
        /* TO DO */
        printf("Status 0x%x is NOT processed\n", u32Status);
    }
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK_EnableXtalRC(CLK_PWRCON_HXT_EN_Msk);

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to HXT */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = CLK_PLLCON_84MHz_HXT;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(I2C3_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV0_UART(1));
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();


    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Set GPH3,GPH4 multi-function pins for I2C3 */
    SYS->GPH_MFPL = SYS_GPH_MFPL_PH3_MFP_I2C3_SCL | SYS_GPH_MFPL_PH4_MFP_I2C3_SDA ;

    /* Lock protected registers */
    SYS_LockReg();
}

void I2C3_Init(void)
{
    /* Open I2C3 and set clock to 100k */
    I2C_Open(I2C3, 100000);

    /* Get I2C3 Bus Clock */
    printf("I2C clock %d Hz\n", I2C_GetBusClockFreq(I2C3));

    /* Set I2C3 4 Slave Addresses */
    I2C_SetSlaveAddr(I2C3, 0, 0x15, I2C_GCMODE_DISABLE);   /* Slave Address : 0x15 */
    I2C_SetSlaveAddr(I2C3, 1, 0x35, I2C_GCMODE_DISABLE);   /* Slave Address : 0x35 */
    I2C_SetSlaveAddr(I2C3, 2, 0x55, I2C_GCMODE_DISABLE);   /* Slave Address : 0x55 */
    I2C_SetSlaveAddr(I2C3, 3, 0x75, I2C_GCMODE_DISABLE);   /* Slave Address : 0x75 */

    I2C_SetSlaveAddrMask(I2C3, 0, 0x01);
    I2C_SetSlaveAddrMask(I2C3, 1, 0x04);
    I2C_SetSlaveAddrMask(I2C3, 2, 0x01);
    I2C_SetSlaveAddrMask(I2C3, 3, 0x04);

    I2C_EnableInt(I2C3);
    NVIC_EnableIRQ(I2C3_IRQn);
}

