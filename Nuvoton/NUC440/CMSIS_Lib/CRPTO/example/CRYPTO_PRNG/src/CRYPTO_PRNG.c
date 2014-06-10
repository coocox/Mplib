/**************************************************************************//**
 * @file     CRYPTO_PRNG.c
 * @version  V1.10
 * $Revision: 3 $
 * $Date: 13/11/10 9:33a $
 * @brief    CRYPTO PRNG sample program for NUC400 series MCU
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "NUC400Series.h"
#include "sys.h"
#include "clk.h"
#include "crypto.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

uint32_t PllClock         = PLL_CLOCK;


#define GENERATE_COUNT      10

void SYS_Init(void);
void UART0_Init(void);

static volatile int  g_PRNG_done;


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t CRYPTO_PRNG(void)
{
    uint32_t    i, u32KeySize;
    uint32_t    au32PrngData[8];

    /* Lock protected registers */
    if(SYS->REGWRPROT == 1) // In end of main function, program issued CPU reset and write-protection will be disabled.
        SYS_LockReg();

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART0 for printf */
    UART0_Init();

    printf("+-------------------------------------------+\n");
    printf("|    NUC400 Crypto Driver PRNG Sample Code  |\n");
    printf("+-------------------------------------------+\n");

    NVIC_EnableIRQ(CRYPTO_IRQn);
    PRNG_ENABLE_INT();

    for (u32KeySize = PRNG_KEY_SIZE_64; u32KeySize <= PRNG_KEY_SIZE_256; u32KeySize++) {
        printf("\n\nPRNG Key size = %s\n\n",(u32KeySize == PRNG_KEY_SIZE_64) ? "64" :
               (u32KeySize == PRNG_KEY_SIZE_128) ? "128" :
               (u32KeySize == PRNG_KEY_SIZE_192) ? "192" :
               (u32KeySize == PRNG_KEY_SIZE_256) ? "256" : "unknown");
        PRNG_Open(u32KeySize, 0, 0);

        for (i = 0; i < GENERATE_COUNT; i++) {
            g_PRNG_done = 0;
            PRNG_Start();
            while (!g_PRNG_done);

            memset(au32PrngData, 0, sizeof(au32PrngData));
            PRNG_Read(au32PrngData);

            printf("PRNG DATA ==>\n");
            printf("    0x%08x  0x%08x  0x%08x  0x%08x\n", au32PrngData[0], au32PrngData[1], au32PrngData[2], au32PrngData[3]);
            printf("    0x%08x  0x%08x  0x%08x  0x%08x\n", au32PrngData[4], au32PrngData[5], au32PrngData[6], au32PrngData[7]);
        }
    }

    printf("\nAll done.\n");

    while (1);
}


void CRYPTO_IRQHandler()
{
    if (PRNG_GET_INT_FLAG()) {
        g_PRNG_done = 1;
        PRNG_CLR_INT_FLAG();
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

    /* Switch HCLK clock source to XTAL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HXT,CLK_CLKDIV0_HCLK(1));

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON|= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLK_S_PLL;

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable Crypto clock */
    CLK->AHBCLK |= CLK_AHBCLK_CRYPTO_EN_Msk;

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HXT,CLK_CLKDIV0_UART(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Lock protected registers */
    SYS_LockReg();
}


void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART0->LCR |=0x07;
    UART0->BAUD = 0x30000066;   /* 12MHz reference clock input, for 115200 */
}


