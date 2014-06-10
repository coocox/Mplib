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
#include "I2S.h"
#include "WAU8822.h"

//-------------------------------------------------------------------------------
// Select one of following options
//
#define DEMO_OPT_SLAVE          1  // I2S works in slave mode
//#define DEMO_OPT_MASTER_NOUSB   1  // I2S works in master mode and don't use USB
//#define DEMO_OPT_MASTER_USB     1    // I2S works in master mode and need to work with USB

//-------------------------------------------------------------------------------


#ifdef DEMO_OPT_SLAVE
# define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
# define PLL_CLOCK           50000000
# define HCLK_DIV            1
#elif defined(DEMO_OPT_MASTER_NOUSB)
# define PLLCON_SETTING      SYSCLK_PLLCON_FOR_I2S
# define PLL_CLOCK           147428571
# define HCLK_DIV            6
#elif defined(DEMO_OPT_MASTER_USB)
# define PLLCON_SETTING      SYSCLK_PLLCON_48MHz_XTAL
# define PLL_CLOCK           48000000
# define HCLK_DIV            1
#else
# error "No option definition"
#endif

#define MUTE_OFF(x)         PE->DOUT &= ~(1 << 14)
#define MUTE_ON(x)          PE->DOUT |=  (1 << 14)


#define SIN_SAMPLES     32
int32_t i32SinIdx = 0;
int16_t i16Sin[SIN_SAMPLES] = {
    0,3203,6284,9124,11612,13655,15172,16106,16423,16107,15172,13655,
    11613,9124,6284,3204,1,-3205,-6284,-9124,-11613,-13654,-15173,-16107,
    -16422,-16106,-15172,-13655,-11613,-9123,-6285,-3203
};

void SYS_Init(void);
void I2C_Init(void);
void I2S_Init(int32_t i32Master, int32_t fs);

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void I2S_Example (void)
{

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init I2C */
    I2C_Init();

#if defined(DEMO_OPT_SLAVE) // I2S is slave
    /*
       I2S is initialized to be slave mode.
       I2S must output 6MHz MCLK to WAU8822.
       Init Codec WAU8822 to be in master mode
       WAU8822 will use MCLK of I2S to generate required 256fs(ex: 12.288MHz) and output BCLK, LR.
       Let WAU8822 be master could get more precise sampling rate.

       Supported sample rate are (Deviation dependent on codec):
            48kHz, 32kHz, 24kHz, 16kHz, 12kHz and 8kHz.

       Clock configuration summary:

           XTAL = 12MHz
           PLL = According to HCLK (Independent to sampling rate)
           HCLK = User define (Independent to sampling rate)
           I2S_S = XTAL
           MCLK = 6MHz (XTAL / 2)
           BCLK = (From codec)
           fs   = 8000Hz, 12000Hz, ... 48000Hz

    */
    I2S_Init(0, 0); // I2S Slave Init, MCLK = 6MHz
    WAU8822_Init(WAU8822_INIT_MASTER | WAU8822_INIT_SR32000 |
                 WAU8822_INIT_OUT_HP_L | WAU8822_INIT_OUT_HP_R |
                 WAU8822_INIT_IN_MIC_L //|
                 //WAU8822_INIT_IN_AUX_L | WAU8822_INIT_IN_AUX_R
                );
#elif defined(DEMO_OPT_MASTER_NOUSB) // I2S is master without USB applications
    /*
       I2S is initialized to be master mode.
       I2S must output 256*fs MCLK to WAU8822.
       Init Codec WAU8822 to be in slave mode.

       Supported sample rate are (Deviation for 48kHz, 32kHz,... are all 0.0186%):

            47991.071Hz, 31994.048Hz, 23995.536Hz, 15997.024Hz, 11997.768Hz, (7998.5119Hz)


       Clock configuration summary for 47991.071Hz, 31994.048Hz, 23995.536Hz, 15997.024Hz:

           XTAL = 12MHz
           PLL = 147428571.4Hz (PLLCON = SYSCLK_PLLCON_FOR_I2S)
           HCLK = PLL / 3 = 49142857.14Hz
           I2S_S = HCLK
           MCLK = 256*fs (MCLK DIV = 4, 6, 8, 12)
           BCLK = 8*fs (BCLK DIV = 32, 48, 64, 96)
           fs = 47991.071Hz, 31994.048Hz, 23995.536Hz, 15997.024Hz

       Clock configuration summary for 11997.768Hz, 7998.5119Hz:

           XTAL = 12MHz
           PLL = 147428571.4Hz (PLLCON = 0xA54)
           HCLK = PLL / 6 = 24571428.57Hz
           I2S_S = HCLK
           MCLK = 256*fs (MCLK DIV = 8, 12)
           BCLK = 8*fs (BCLK DIV = 64, 96)
           fs = 11997.768Hz, 7998.5119Hz

    */
    I2S_Init(1, 32000); // I2S Init to Master, MCLK = 256 * fs
    WAU8822_Init(WAU8822_INIT_SLAVE | WAU8822_INIT_SR32000 |
                 WAU8822_INIT_OUT_HP_L | WAU8822_INIT_OUT_HP_R |
                 WAU8822_INIT_IN_MIC_L //|
                 //WAU8822_INIT_IN_AUX_L | WAU8822_INIT_IN_AUX_R
                );

#elif defined(DEMO_OPT_MASTER_USB) // I2S is master with USB applications
    /*
       I2S is initialized to be master mode and work with USB (48MHz clock is necessary)
       I2S must output 256*fs MCLK to WAU8822.
       Init Codec WAU8822 to be in slave mode.

       Supported sample rate are (Deviation for 48kHz, 32kHz, ... are all 2.3438%):

            46875Hz, 31250Hz, 23437.5Hz, 15625Hz, 11718.75Hz, (7812.5Hz)


       Clock configuration summary for 46875Hz, 31250Hz, 23437.5Hz, 15625Hz:

           XTAL = 12MHz
           PLL = 48MHz (PLLCON = SYSCLK_PLLCON_48MHz_XTAL)
           HCLK = PLL / 1 = 48MHz
           I2S_S = HCLK
           MCLK = 256*fs (MCLK DIV = 4, 6, 8, 12)
           BCLK = 8*fs (BCLK DIV = 32, 48, 64, 96)
           fs = 46875Hz, 31250Hz, 23437.5Hz, 15625Hz

       Clock configuration summary for 11718.75Hz, 7812.5Hz:

           XTAL = 12MHz
           PLL = 48MHz (PLLCON = SYSCLK_PLLCON_48MHz_XTAL)
           HCLK = PLL / 2 = 24MHz
           I2S_S = HCLK
           MCLK = 256*fs (MCLK DIV = 8, 12)
           BCLK = 8*fs (BCLK DIV = 64, 96)
           fs = 11718.75Hz, 7812.5Hz

    */
    I2S_Init(1, 12000); // I2S Master Init, MCLK = 256*fs
    WAU8822_Init(WAU8822_INIT_SLAVE | WAU8822_INIT_SR12000 |
                 WAU8822_INIT_OUT_HP_L | WAU8822_INIT_OUT_HP_R |
                 WAU8822_INIT_IN_MIC_L //|
                 //WAU8822_INIT_IN_AUX_L | WAU8822_INIT_IN_AUX_R
                );
#endif

    MUTE_OFF();

    printf("+----------------------------------------------+\n");
    printf("|        NUC200 I2S Driver Sample Code         |\n");
    printf("+----------------------------------------------+\n");
//	printf("\n");
    printf("    Working ...\n");
    printf("    User can measure LRCLK to check sampling rate.\n");

    /* Toggle PC15 to indicate we are working. */
    while(1)
    {
        SYS_SysTickDelay(100000);
        PC15 ^= 1;
    }

}


void I2S_IRQHandler(void)
{
    uint32_t u32Tmp;

    /* Fill sin samples to I2S until Tx FIFO full */
    while((I2S->STATUS & I2S_STATUS_TXFULL_Msk) == 0)
    {

#if 0 // Just loop Rx FIFO to Tx FIFO
        I2S->TXFIFO = I2S->RXFIFO;
#elif 0 // Mono data in Rx FIFO and duplicate it to stereo to Tx FIFO
        u32Tmp = I2S->RXFIFO & 0xFFFF0000UL;
        u32Tmp |= u32Tmp >> 16;
        I2S->TXFIFO = u32Tmp;
#else // Output Sin Wave
        u32Tmp = i16Sin[i32SinIdx];
        u32Tmp &= 0xFFFFUL;
        u32Tmp |= u32Tmp << 16;
        I2S->TXFIFO = u32Tmp;
        i32SinIdx++;
        if(i32SinIdx >= SIN_SAMPLES)
            i32SinIdx = 0;
#endif
    }

    PC->DOUT ^= (1 << 14);
}


void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Set clock divder */
    SYSCLK->CLKDIV = SYSCLK_CLKDIV_HCLK(HCLK_DIV) | SYSCLK_CLKDIV_USB(1);

    /* Enable External XTAL (4~24 MHz) */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for 12MHz clock ready */
    SYS_WaitingForClockReady( SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_XTAL;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_I2S_EN_Msk | SYSCLK_APBCLK_I2C0_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_XTAL | SYSCLK_CLKSEL1_WDT_IRC10K |
                      SYSCLK_CLKSEL1_TMR0_XTAL | SYSCLK_CLKSEL1_TMR1_HCLK | SYSCLK_CLKSEL1_TMR2_IRC22M | SYSCLK_CLKSEL1_TMR3_XTAL;

#ifdef DEMO_OPT_SLAVE
    /* Use external 12MHz as I2S clock source */
    SYSCLK->CLKSEL2 = SYSCLK_CLKSEL2_I2S_XTAL;
#else
    /* Use external HCLK as I2S clock source */
    SYSCLK->CLKSEL2 = SYSCLK_CLKSEL2_I2S_HCLK;
#endif


    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / HCLK_DIV; // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PA multi-function pins for I2C0 SDA, SCL, I2S MCLK */
    SYS->GPA_MFP = SYS_GPA_MFP_PA8_SDA0 | SYS_GPA_MFP_PA9_SCL0 | SYS_GPA_MFP_PA15_I2SMCLK;

    /* Set PB multi-function pins for UART0 RXD, TXD */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;

    /* Set PC multi-function pins for I2S LRCLK, BCLK, SDI, SDO */
    SYS->GPC_MFP = SYS_GPC_MFP_PC0_I2SLRCLK | SYS_GPC_MFP_PC1_I2SBCLK | SYS_GPC_MFP_PC2_I2SDI |
                   SYS_GPC_MFP_PC3_I2SDO;

    SYS->ALT_MFP = SYS_ALT_MFP_PC0_I2SLRCLK | SYS_ALT_MFP_PC1_I2SBCLK | SYS_ALT_MFP_PC2_I2SDI |
                   SYS_ALT_MFP_PC3_I2SDO | SYS_ALT_MFP_PA15_I2SMCLK;

    SYS->ALT_MFP1 = SYS_ALT_MFP1_PA15_I2SMCLK;

    /* Lock protected registers */
    //SYS_LockReg();
}


void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

/* fs must be 8000, 12000, ~ 48000 */
void I2S_Init(int32_t i32Master, int32_t fs)
{

    if(i32Master)
    {
        /* I2S need to output MCLK, BCLK, LR to Codec in master mode */
        if(fs == 8000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(12) | I2S_CLKDIV_BCLK(96);
        else if(fs == 12000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(8) | I2S_CLKDIV_BCLK(64);
        else if(fs == 16000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(12) | I2S_CLKDIV_BCLK(96);
        else if(fs == 24000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(8) | I2S_CLKDIV_BCLK(64);
        else if(fs == 32000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(6) | I2S_CLKDIV_BCLK(48);
        else if(fs == 48000)
            I2S->CLKDIV = I2S_CLKDIV_MCLK(4) | I2S_CLKDIV_BCLK(32);

        // Init Play/Record/Stereo/16-bit PCM. Output MCLK
        I2S->CON = I2S_CON_ENABLE | I2S_CON_FMT_I2S | I2S_CON_STEREO | I2S_CON_WORDWIDTH_16 |
                   I2S_CON_PLAY_EN | I2S_CON_TX_TH(2) | I2S_CON_MASTER | I2S_CON_MCLK_EN |
                   I2S_CON_REC_EN;
    }
    else
    {
        /* I2S only output MCLK to codec in slave mode. BCLK and LR are from codec */

        // MCLK = 12MHz / 2 = 6MHz
        I2S->CLKDIV = I2S_CLKDIV_MCLK(2) | I2S_CLKDIV_BCLK(0);

        // Init Play/Record/Stereo/16-bit PCM. Output MCLK
        I2S->CON = I2S_CON_ENABLE | I2S_CON_FMT_I2S | I2S_CON_STEREO | I2S_CON_WORDWIDTH_16 |
                   I2S_CON_PLAY_EN | I2S_CON_TX_TH(2) | I2S_CON_SLAVE | I2S_CON_MCLK_EN |
                   I2S_CON_REC_EN;
    }

    // Enable IRQ
    I2S->IE = I2S_IE_TXTHIE_Msk;
    NVIC_EnableIRQ(I2S_IRQn);

}

void I2C_Init(void)
{
    I2C0->I2CLK = I2C_I2CLK_DIV4(180); /* 72000000Hz / 4 / 180 = 100000Hz */
}


