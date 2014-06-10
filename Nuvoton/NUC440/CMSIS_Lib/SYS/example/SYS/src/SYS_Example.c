/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 8 $
 * $Date: 13/11/10 10:17a $
 * @brief    NUC400 Series Global Control and Clock Control Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>"
#include "NUC400Series.h"
#include "clk.h"
#include "sys.h"
#include "uart.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

#define SIGNATURE       0x125ab234
#define FLAG_ADDR       0x20000FFC




/*---------------------------------------------------------------------------------------------------------*/
/*  Simple calculation test function                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#define PI_NUM  256
int32_t f[PI_NUM+1];
uint32_t piTbl[19] = {
    3141,
    5926,
    5358,
    9793,
    2384,
    6264,
    3383,
    2795,
    288,
    4197,
    1693,
    9937,
    5105,
    8209,
    7494,
    4592,
    3078,
    1640,
    6284
};

int32_t piResult[19];

uint32_t g_au32PllSetting[] = {
    25000000, /* PLL = 25MHz */
    29000000, /* PLL = 29MHz */
    33000000, /* PLL = 33MHz */
    37000000, /* PLL = 37MHz */
    41000000, /* PLL = 41MHz */
    45000000, /* PLL = 45MHz */
    49000000, /* PLL = 49MHz */
    84000000, /* PLL = 84MHz */
    96000000, /* PLL = 96MHz */
};
void SYS_Init(void);
void SYS_PLL_Test(void);
void UART0_Init(void);
void BOD_IRQHandler(void);
void PWRWU_IRQHandler(void);
void Delay(uint32_t x);
int32_t pi(void);
/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t SYS_Example ( )
{
    uint32_t u32data;


    /* Lock protected registers */
    if(SYS->REGWRPROT == 1) // In end of main function, program issued CPU reset and write-protection will be disabled.
        SYS_LockReg();

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART0 for printf */
    UART0_Init();

    printf("\r\nCPU @ %dHz\n", SystemCoreClock);
    /*
        This sample code will show some function about system manager controller and clock controller:
        1. Read PDID
        2. Get and clear reset source
        3. Setting about BOD
        4. Change system clock depended on different PLL settings
        5. Output system clock from CKO pin, and the output frequency = system clock / 4
    */

    printf("+---------------------------------------+\n");
    printf("|    NUC400 System Driver Sample Code   |\n");
    printf("+---------------------------------------+\n");

    if (M32(FLAG_ADDR) == SIGNATURE)
    {
        printf("  CPU Reset success!\n");
        while(1);

    }

    /*---------------------------------------------------------------------------------------------------------*/
    /* Misc system function test                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Read Part Device ID */
    printf("Product ID 0x%x\n", SYS->PDID);

    /* Get reset source from last operation */
    u32data = SYS->RSTSRC;
    printf("Reset Source 0x%x\n", u32data);

    /* Clear reset source */
    SYS->RSTSRC = u32data;

    /* Unlock protected registers for Brown-Out Detector settings */
    SYS_UnlockReg();

    /* Check if the write-protected registers are unlocked before BOD setting and CPU Reset */
    if (SYS->REGWRPROT != 0) {
        printf("Protected Address is Unlocked\n");
    }

    /* Enable Brown-Out Detector and Low Voltage Reset function, and set Brown-Out Detector voltage 2.7V */
    SYS->BODCR =SYS_BODCR_BOD_EN_Msk | SYS_BODCR_BOD_VL_2_7V | SYS_BODCR_LVR_EN_Msk;

    /* Enable Brown-Out Interrupt function */
    SYS->BODCR &= ~SYS_BODCR_BOD_RSTEN_Msk;
    NVIC_EnableIRQ(BOD_IRQn);

    /* Get system clock frequency and PLL clock frequency */
    printf("  Change system clock to %d Hz and PLL clock is %d Hz\n", SystemCoreClock, CLK_GetPLLClockFreq());

    /* Run PLL Test */
    SYS_PLL_Test();

    /* Write a signature work to SRAM to check if it is reset by software */
    M32(FLAG_ADDR) = SIGNATURE;
    printf("\n\n  >>> Reset CPU <<<\n");

    /* Waiting for message send out */
    //_UART_WAIT_TX_EMPTY(UART0);

    /* Switch HCLK clock source to Internal 22MHz */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLK_S_HIRC;

    /* Set PLL to Power down mode and HW will also clear PLL_STB bit in CLKSTATUS register */
    CLK->PLLCON |= CLK_PLLCON_PD_Msk;

    /* Reset CPU */
    SYS_ResetCPU();
}

int32_t pi(void)
{
    int32_t i,i32Err;
    int32_t a=10000, b=0, c=PI_NUM, d=0, e=0, g=0;

    for(; b-c;)
        f[b++]=a/5;

    i = 0;
    for(; d=0,g=c*2; c -=14,/*printf("%.4d\n",e+d/a),*/ piResult[i++] = e+d/a,e=d%a) {
        if(i==19)
            break;

        for(b=c; d+=f[b]*a,f[b]=d%--g,d/=g--,--b; d*=b);
    }
    i32Err = 0;
    for(i=0; i<19; i++) {
        if(piTbl[i] != piResult[i])
            i32Err = -1;
    }

    return i32Err;
}

void Delay(uint32_t x)
{
    int32_t i;

    for(i=0; i<x; i++) {
        __NOP();
        __NOP();
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
    CLK->PLLCON|= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_PLL,CLK_CLKDIV0_HCLK(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE,CLK_CLKSEL1_UART_S_HXT,CLK_CLKDIV0_UART(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Set GPG multi-function pins for CKO */
    SYS->GPC_MFPL = (SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5_MFP_Msk) | SYS_GPC_MFPL_PC5_MFP_CLK_O ;

    /* Lock protected registers */
    SYS_LockReg();
}

void SYS_PLL_Test(void)
{
    int32_t  i;
    /*---------------------------------------------------------------------------------------------------------*/
    /* PLL clock configuration test                                                                             */
    /*---------------------------------------------------------------------------------------------------------*/

    printf("\n-------------------------[ Test PLL ]-----------------------------\n");

    for (i = 0; i < sizeof(g_au32PllSetting)/sizeof(g_au32PllSetting[0]) ; i++) {
        /* Set HCLK clock */
        CLK_SetCoreClock(g_au32PllSetting[i]);

        printf("  Change system clock to %d Hz ......................... ", SystemCoreClock);

        /* Output selected clock to CKO, CKO Clock = HCLK / 2^(1 + 1) */
        CLK_EnableCKO(CLK_CLKSEL1_FRQDIV_S_HCLK, 1, 0);

        /* The delay loop is used to check if the CPU speed is increasing */
        Delay(0x400000);

        if (pi()) {
            printf("[FAIL]\n");
        } else {
            printf("[OK]\n");
        }

        /* Disable CKO clock */
        CLK_DisableCKO();
    }
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
    UART0->BAUD = 0x30000066; /* 12MHz reference clock input, for 115200 */
    //UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    //_UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Brown Out Detector IRQ Handler                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void BOD_IRQHandler(void)
{
    /* Clear Interrupt Flag */
    SYS->BODCR |= SYS_BODCR_BOD_INTF_Msk;

    printf("Brown Out is Detected\n");
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Power Down Wake Up IRQ Handler                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void PWRWU_IRQHandler(void)
{
    /* Clear Power Down Wake Up interrupt flag */
    CLK->PWRCON |= CLK_PWRCON_PD_WU_STS_Msk;

    printf("Wake Up Interrupt is asserted\n");
}

