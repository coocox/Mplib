/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/03 5:46p $
 * @brief    NUC200 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "SYS.h"
#include "GPIO.h"
#include "UART.h"
#include "I2C.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000


/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8DeviceAddr;
uint8_t g_au8TxData[3];
uint8_t g_u8RxData;
uint8_t g_u8DataLen;
volatile uint8_t g_u8EndFlag = 0;

typedef void (*I2C_FUNC)(uint32_t u32Status);


static I2C_FUNC s_I2C1HandlerFn = NULL;


void I2C_MasterRx(uint32_t u32Status);
void I2C1_Close(void);
void I2C1_Init(void);
void UART0_Init(void);
void SYS_Init(void);
void I2C_MasterTx(uint32_t u32Status);


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_Example (void)
{
    uint32_t i;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init I2C1 to access EEPROM */
    I2C1_Init();
    /*
        This sample code sets I2C bus clock to 100kHz. Then, accesses EEPROM 24LC64 with Byte Write
        and Byte Read operations, and check if the read data is equal to the programmed data.
    */

    printf("+-------------------------------------------------------+\n");
    printf("|    NUC200 I2C Driver Sample Code with EEPROM 24LC64   |\n");
    printf("+-------------------------------------------------------+\n");

    g_u8DeviceAddr = 0x50;

    for (i = 0; i < 0x100; i++)
    {
        g_au8TxData[0] = (uint8_t)((i & 0xFF00) >> 8);
        g_au8TxData[1] = (uint8_t)(i & 0x00FF);
        g_au8TxData[2] = (uint8_t)(g_au8TxData[1] + 3);

        g_u8DataLen = 0;
        g_u8EndFlag = 0;

        /* I2C function to write data to slave */
        s_I2C1HandlerFn = (I2C_FUNC)I2C_MasterTx;

        /* I2C as master sends START signal */
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STA);

        /* Wait I2C Tx Finish */
        while (g_u8EndFlag == 0);
        g_u8EndFlag = 0;

        /* I2C function to read data from slave */
        s_I2C1HandlerFn = (I2C_FUNC)I2C_MasterRx;

        g_u8DataLen = 0;
        g_u8DeviceAddr = 0x50;

        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STA);

        /* Wait I2C Rx Finish */
        while (g_u8EndFlag == 0);

        /* Compare data */
        if (g_u8RxData != g_au8TxData[2])
        {
            printf("I2C Byte Write/Read Failed, Data 0x%x\n", g_u8RxData);
            return -1;
        }
    }
    printf("I2C1 Access EEPROM Test OK\n");

    s_I2C1HandlerFn = NULL;

    /* Close I2C1 */
    I2C1_Close();

	while(1);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C1 IRQ Handler                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void I2C1_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = I2C1->I2CSTATUS;

    if (I2C1->I2CTOC & I2C_I2CTOC_TIF_Msk)
    {
        /* Clear I2C1 Timeout Flag */
        I2C1->I2CTOC |= I2C_I2CTOC_TIF_Msk;
    }
    else
    {
        if (s_I2C1HandlerFn != NULL)
            s_I2C1HandlerFn(u32Status);
    }
}
/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Rx Callback Function                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_MasterRx(uint32_t u32Status)
{
    if (u32Status == 0x08)                      /* START has been transmitted and prepare SLA+W */
    {
        I2C1->I2CDAT = g_u8DeviceAddr << 1;     /* Write SLA+W to Register I2CDAT */
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x18)                 /* SLA+W has been transmitted and ACK has been received */
    {
        I2C1->I2CDAT = g_au8TxData[g_u8DataLen++];
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x20)                 /* SLA+W has been transmitted and NACK has been received */
    {
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STA_STO_SI);
    }
    else if (u32Status == 0x28)                 /* DATA has been transmitted and ACK has been received */
    {
        if (g_u8DataLen != 2)
        {
            I2C1->I2CDAT = g_au8TxData[g_u8DataLen++];
            _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
        }
        else
        {
            _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STA_SI);
        }
    }
    else if (u32Status == 0x10)                 /* Repeat START has been transmitted and prepare SLA+R */
    {
        I2C1->I2CDAT = ((g_u8DeviceAddr << 1) | 0x01);   /* Write SLA+R to Register I2CDAT */
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x40)                 /* SLA+R has been transmitted and ACK has been received */
    {
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x58)                 /* DATA has been received and NACK has been returned */
    {
        g_u8RxData = I2C1->I2CDAT;
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STO_SI);
        g_u8EndFlag = 1;
    }
    else
    {
        /* TO DO */
        printf("Status 0x%x is NOT processed\n", u32Status);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Tx Callback Function                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_MasterTx(uint32_t u32Status)
{
    if (u32Status == 0x08)                      /* START has been transmitted */
    {
        I2C1->I2CDAT = g_u8DeviceAddr << 1;     /* Write SLA+W to Register I2CDAT */
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x18)                 /* SLA+W has been transmitted and ACK has been received */
    {
        I2C1->I2CDAT = g_au8TxData[g_u8DataLen++];
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
    }
    else if (u32Status == 0x20)                 /* SLA+W has been transmitted and NACK has been received */
    {
        _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STA_STO_SI);
    }
    else if (u32Status == 0x28)                 /* DATA has been transmitted and ACK has been received */
    {
        if (g_u8DataLen != 3)
        {
            I2C1->I2CDAT = g_au8TxData[g_u8DataLen++];
            _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_SI);
        }
        else
        {
            _I2C_SET_CONTROL_BITS(I2C1, I2C_I2CON_STO_SI);
            g_u8EndFlag = 1;
        }
    }
    else
    {
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
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for 12MHz clock ready */
    SYS_WaitingForClockReady( SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_XTAL;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    SYSCLK->PLLCON|= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_I2C1_EN_Msk;

    /* Select IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_XTAL;;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set GPB multi-function pins for UART0 RXD and TXD, and Clock Output */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB8_CLKO;
    SYS->ALT_MFP = SYS_ALT_MFP_PB8_CLKO;

    /* Lock protected registers */
    SYS_LockReg();

}

void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

void I2C1_Init(void)
{
	/* Set GPA10,11 multi-function pins for I2C1 SDA and SCL */
	SYS->GPA_MFP |= SYS_GPA_MFP_PA10_SDA1|SYS_GPA_MFP_PA11_SCL1;

    /* Reset I2C1 */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_I2C1_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_I2C1_RST_Msk;

    /* Enable I2C1 Controller */
    I2C1->I2CON |= I2C_I2CON_ENS1_Msk;

    /* I2C1 clock divider, I2C Bus Clock = PCLK / (4*120) = 100kHz */
    I2C1->I2CLK = I2C_I2CLK_DIV4(120);

    /* Get I2C1 Bus Clock */
    printf("I2C clock %d Hz\n", _I2C_GET_BUS_CLOCK(I2C1));

    /* Set I2C1 4 Slave Addresses */
    _I2C_SET_SLAVE_ADDRESS_0(I2C1, 0x16);   /* Slave Address : 0x15 */
    _I2C_SET_SLAVE_ADDRESS_1(I2C1, 0x36);   /* Slave Address : 0x35 */
    _I2C_SET_SLAVE_ADDRESS_2(I2C1, 0x56);   /* Slave Address : 0x55 */
    _I2C_SET_SLAVE_ADDRESS_3(I2C1, 0x76);   /* Slave Address : 0x75 */

    /* Enable I2C1 interrupt and set corresponding NVIC bit */
    I2C1->I2CON |= I2C_I2CON_EI_Msk;
    NVIC_EnableIRQ(I2C1_IRQn);
}

void I2C1_Close(void)
{
    /* Disable I2C1 interrupt and clear corresponding NVIC bit */
    I2C1->I2CON &= ~I2C_I2CON_EI_Msk;
    NVIC_DisableIRQ(I2C1_IRQn);

    /* Disable I2C1 and close I2C1 clock */
    I2C1->I2CON &= ~I2C_I2CON_ENS1_Msk;
    SYSCLK->APBCLK &= ~SYSCLK_APBCLK_I2C1_EN_Msk;

}


