/**************************************************************************//**
 * @file     I2S_NAU8822.c
 * @version  V2.00
 * $Revision: 7 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 Series I2S Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "uart.h"
#include "gpio.h"
#include "i2c.h"
#include "i2s.h"
#include "config.h"
#define NAU8822_ADDR    0x1A                /* NAU8822 Device ID */

uint32_t PcmBuff[BUFF_LEN] = {0};
uint32_t volatile u32BuffPos = 0;

void I2C3_Init(void);
void Delay(int count);
void I2C_WriteWAU8822(uint8_t u8addr, uint16_t u16data);
void WAU8822_Setup();
void SYS_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t I2S_NAU8822(void)
{
    uint32_t u32startFlag = 1;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);

    printf("+------------------------------------------------------------------------+\n");
    printf("|                   I2S Driver Sample Code with WAU8822                  |\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("  NOTE: This sample code needs to work with WAU8822.\n");

    /* Init I2C3 to access WAU8822 */
    I2C3_Init();

    // Plug-In DET
    SYS->GPA_MFPL = (SYS->GPA_MFPL & ~(SYS_GPA_MFPL_PA4_MFP_Msk));
    GPIO_SetMode(PA, BIT4, GPIO_PMD_OUTPUT);
    PA4 = 1;

#ifdef INPUT_IS_LIN
    I2S_Open(I2S1, I2S_MODE_SLAVE, 16000, I2S_DATABIT_16, I2S_STEREO, I2S_FORMAT_I2S, I2S_I2S);
#else
    I2S_Open(I2S1, I2S_MODE_SLAVE, 16000, I2S_DATABIT_16, I2S_MONO, I2S_FORMAT_I2S, I2S_I2S);
#endif

    // select source from HXT(12MHz)
    CLK_SetModuleClock(I2S1_MODULE, CLK_CLKSEL3_I2S1_S_HXT, 0);

    /* Initialize WAU8822 codec */
    WAU8822_Setup();

    /* Set MCLK and enable MCLK */
    I2S_Enable_MCLK(I2S1, 12000000);

#ifndef INPUT_IS_LIN
    I2S_SET_MONO_RX_CHANNEL(I2S1, I2S_MONO_LEFT);       //WAU8822 will store data in left channel
#endif

    /* Enable Rx threshold level interrupt */
    I2S_EnableInt(I2S1, I2S_IE_RXTHIE_Msk);

    /* Enable I2S Rx function to receive data */
    I2S_ENABLE_RX(I2S1);

    while(1) {
        if (u32startFlag) {
            /* Enable I2S Tx function to send data when data in the buffer is more than half of buffer size */
            if (u32BuffPos >= BUFF_LEN/2) {
                I2S_EnableInt(I2S1, I2S_IE_TXTHIE_Msk);
                I2S_ENABLE_TX(I2S1);
                u32startFlag = 0;
            }
        }
    }
}


void Delay(int count)
{
    volatile uint32_t i;
    for (i = 0; i < count ; i++);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Write 9-bit data to 7-bit address register of WAU8822 with I2C0                                        */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_WriteWAU8822(uint8_t u8addr, uint16_t u16data)
{

    I2C_START(I2C3);
    I2C_WAIT_READY(I2C3);

    I2C_SET_DATA(I2C3, NAU8822_ADDR<<1);
    I2C_SET_CONTROL_REG(I2C3, I2C_SI);
    I2C_WAIT_READY(I2C3);

    I2C_SET_DATA(I2C3, (uint8_t)((u8addr << 1) | (u16data >> 8)));
    I2C_SET_CONTROL_REG(I2C3, I2C_SI);
    I2C_WAIT_READY(I2C3);

    I2C_SET_DATA(I2C3, (uint8_t)(u16data & 0x00FF));
    I2C_SET_CONTROL_REG(I2C3, I2C_SI);
    I2C_WAIT_READY(I2C3);

    I2C_STOP(I2C3);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  WAU8822 Settings with I2C interface                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
void WAU8822_Setup()
{
    printf("\nConfigure WAU8822 ...");

    I2C_WriteWAU8822(0,  0x000);   /* Reset all registers */
    Delay(0x200);

#ifdef INPUT_IS_LIN //input source is LIN
    I2C_WriteWAU8822(1,  0x02F);
    I2C_WriteWAU8822(2,  0x1B3);   /* Enable L/R Headphone, ADC Mix/Boost, ADC */
    I2C_WriteWAU8822(3,  0x07F);   /* Enable L/R main mixer, DAC */
    I2C_WriteWAU8822(4,  0x010);   /* 16-bit word length, I2S format, Stereo */
    I2C_WriteWAU8822(5,  0x000);   /* Companding control and loop back mode (all disable) */
    I2C_WriteWAU8822(6,  0x1AD);   /* Divide by 6, 16K */
    I2C_WriteWAU8822(7,  0x006);   /* 16K for internal filter coefficients */
    I2C_WriteWAU8822(10, 0x008);   /* DAC soft mute is disabled, DAC oversampling rate is 128x */
    I2C_WriteWAU8822(14, 0x108);   /* ADC HP filter is disabled, ADC oversampling rate is 128x */
    I2C_WriteWAU8822(15, 0x1EF);   /* ADC left digital volume control */
    I2C_WriteWAU8822(16, 0x1EF);   /* ADC right digital volume control */

    I2C_WriteWAU8822(44, 0x000);   /* LLIN/RLIN is not connected to PGA */
    I2C_WriteWAU8822(47, 0x050);   /* LLIN connected, and its Gain value */
    I2C_WriteWAU8822(48, 0x050);   /* RLIN connected, and its Gain value */
    I2C_WriteWAU8822(50, 0x001);   /* Left DAC connected to LMIX */
    I2C_WriteWAU8822(51, 0x001);   /* Right DAC connected to RMIX */
#else   //input source is MIC
    I2C_WriteWAU8822(1,  0x03F);
    I2C_WriteWAU8822(2,  0x1BF);   /* Enable L/R Headphone, ADC Mix/Boost, ADC */
    I2C_WriteWAU8822(3,  0x07F);   /* Enable L/R main mixer, DAC */
    I2C_WriteWAU8822(4,  0x010);   /* 16-bit word length, I2S format, Stereo */
    I2C_WriteWAU8822(5,  0x000);   /* Companding control and loop back mode (all disable) */
    I2C_WriteWAU8822(6,  0x1AD);   /* Divide by 6, 16K */
    I2C_WriteWAU8822(7,  0x006);   /* 16K for internal filter coefficients */
    I2C_WriteWAU8822(10, 0x008);   /* DAC soft mute is disabled, DAC oversampling rate is 128x */
    I2C_WriteWAU8822(14, 0x108);   /* ADC HP filter is disabled, ADC oversampling rate is 128x */
    I2C_WriteWAU8822(15, 0x1EF);   /* ADC left digital volume control */
    I2C_WriteWAU8822(16, 0x1EF);   /* ADC right digital volume control */
    I2C_WriteWAU8822(44, 0x033);   /* LMICN/LMICP is connected to PGA */
    I2C_WriteWAU8822(50, 0x001);   /* Left DAC connected to LMIX */
    I2C_WriteWAU8822(51, 0x001);   /* Right DAC connected to RMIX */
#endif

    printf("[OK]\n");
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
    CLK_EnableModuleClock(I2S1_MODULE);

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

    /* Set multi function pin for I2S1 */
    /* GPG7, GPG8, GPG9, GPI11, GPI12 */
    SYS->GPG_MFPL = (SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7_MFP_Msk) | SYS_GPG_MFPL_PG7_MFP_I2S1_MCLK;
    SYS->GPG_MFPH = (SYS->GPG_MFPH & ~(SYS_GPG_MFPH_PG8_MFP_Msk | SYS_GPG_MFPH_PG9_MFP_Msk)) | (SYS_GPG_MFPH_PG8_MFP_I2S1_DO | SYS_GPG_MFPH_PG9_MFP_I2S1_DI);
    SYS->GPI_MFPH = (SYS->GPI_MFPH & ~(SYS_GPI_MFPH_PI11_MFP_Msk | SYS_GPI_MFPH_PI12_MFP_Msk)) | (SYS_GPI_MFPH_PI11_MFP_I2S1_BCLK | SYS_GPI_MFPH_PI12_MFP_I2S1_LRCK);

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
}

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
