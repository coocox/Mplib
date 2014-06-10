/**************************************************************************//**
 * @file     CAP_MotionDetection.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 13/12/04 9:40a $
 * @brief    NUC400 Series Image Capture Driver Sample Code
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "NUC400Series.h"
#include "sensor.h"
#include <stdio.h>
#include "SYS.h"
#include "CLK.h"
#include "CAP.h"

#define PLLCON_SETTING      CLK_PLLCON_84MHz_HXT
#define PLL_CLOCK           84000000

#define SIGNATURE       0x125ab234
#define FLAG_ADDR       0x20000FFC


/*------------------------------------------------------------------------------------------*/
/* To run CAP_InterruptHandler, when VIN frame end interrupt                                */
/*------------------------------------------------------------------------------------------*/
volatile uint32_t u32FramePass = 0;
void CAP_InterruptHandler(void);
void CAP_SetFreq(uint32_t u32ModFreqKHz,uint32_t u32SensorFreq);
void SYS_Init(void);
void UART0_Init(void);
void MotionDetection8x8(void);


#define SENSOR_IN_WIDTH                640
#define SENSOR_IN_HEIGHT            480
#define SYSTEM_WIDTH                160
#define SYSTEM_HEIGHT                120
uint8_t u8FrameBuffer[SYSTEM_WIDTH*SYSTEM_HEIGHT*2];

uint8_t u8MDOutputBuffer[SYSTEM_WIDTH/8*SYSTEM_HEIGHT/8];
uint8_t u8MDOutputYBuffer[SYSTEM_WIDTH/8*SYSTEM_HEIGHT/8];


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t CAP_MotionDetection(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init Engine clock and Sensor clock */
    CAP_SetFreq(7000000 ,7000000);

    /* Motion Detection */
    MotionDetection8x8();

    return 0;
}


void CAP_InterruptHandler(void)
{
    u32FramePass++;
}

/*------------------------------------------------------------------------------------------*/
/*  CAP_IRQHandler                                                                          */
/*------------------------------------------------------------------------------------------*/
void CAP_IRQHandler(void)
{
    uint32_t u32CapInt;
    u32CapInt = CAP->CAPINT;
    if( (u32CapInt & (CAP_CAPINT_VINTEN_Msk | CAP_CAPINT_VINT_Msk )) == (CAP_CAPINT_VINTEN_Msk | CAP_CAPINT_VINT_Msk)) {
        CAP_InterruptHandler();
        CAP->CAPINT |= CAP_CAPINT_VINT_Msk;        /* Clear Frame end interrupt */
        u32EscapeFrame = u32EscapeFrame+1;
    }

    if((u32CapInt & (CAP_CAPINT_ADDRMEN_Msk|CAP_CAPINT_ADDRMINT_Msk)) == (CAP_CAPINT_ADDRMEN_Msk|CAP_CAPINT_ADDRMINT_Msk)) {
        CAP->CAPINT |= CAP_CAPINT_ADDRMINT_Msk; /* Clear Address match interrupt */
    }

    if ((u32CapInt & (CAP_CAPINT_MEINTEN_Msk|CAP_CAPINT_MEINT_Msk)) == (CAP_CAPINT_MEINTEN_Msk|CAP_CAPINT_MEINT_Msk)) {
        CAP->CAPINT |= CAP_CAPINT_MEINT_Msk;    /* Clear Memory error interrupt */
    }

    if ((u32CapInt & (CAP_CAPINT_MDINTEN_Msk|CAP_CAPINT_MDINT_Msk)) == (CAP_CAPINT_MDINTEN_Msk|CAP_CAPINT_MDINT_Msk)) {
        CAP->CAPINT |= CAP_CAPINT_MDINT_Msk;    /* Clear Motion Detection interrupt */
    }
    CAP->CAPCTL = CAP->CAPCTL | CAP_CAPCTL_UPDATE;
}

void CAP_SetFreq(uint32_t u32ModFreqKHz,uint32_t u32SensorFreq)
{
    int32_t i32Div;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable CAP Clock */
    CLK->AHBCLK |= CLK_AHBCLK_CAP_EN_Msk;

    /* Enable Sensor Clock */
    CLK->AHBCLK |= CLK_AHBCLK_SENCLK_EN_Msk;

    /* Reset IP */
    SYS->IPRSTC1 |= SYS_IPRSTC1_CAP_RST_Msk;
    SYS->IPRSTC1 &= ~SYS_IPRSTC1_CAP_RST_Msk;

    /* Specified sensor clock */
    CLK->CLKSEL0 = (CLK->CLKSEL0 & ~CLK_CLKSEL0_CAP_S_Msk) | CLK_CLKSEL0_CAP_S_HCLK ;

    i32Div = CLK_GetHCLKFreq()/u32SensorFreq-1;
    if(i32Div < 0) i32Div = 0;
    CLK->CLKDIV3 = (CLK->CLKDIV3 & ~CLK_CLKDIV3_VASENSOR_N_Msk) | i32Div<<CLK_CLKDIV3_VASENSOR_N_Pos;

    /* Specified engine clock */
    i32Div = CLK_GetHCLKFreq()/u32ModFreqKHz-1;
    if(i32Div < 0) i32Div = 0;
    CLK->CLKDIV3 = (CLK->CLKDIV3 & ~CLK_CLKDIV3_CAP_N_Msk) | i32Div<<CLK_CLKDIV3_CAP_N_Pos;

    /* lock protected registers */
    SYS_LockReg();
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    CLK->PWRCON |= CLK_PWRCON_HXT_EN_Msk;

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady( CLK_CLKSTATUS_HXT_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLK_S_HXT;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    CLK->PLLCON|= CLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    CLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLK_S_PLL;

    /* Enable IP clock */
    CLK->APBCLK0 = CLK_APBCLK0_UART0_EN_Msk;

    /* Select IP clock source */
    CLK->CLKSEL1 = CLK_CLKSEL1_UART_S_HXT;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set GPG multi-function pins for UART0 RXD and TXD */
    SYS->GPG_MFPL = SYS_GPG_MFPL_PG1_MFP_UART0_RXD | SYS_GPG_MFPL_PG2_MFP_UART0_TXD ;

    /* Set multi-function pins for CAP */
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0_MFP_Msk)  | SYS_GPD_MFPL_PD0_MFP_CAP_DATA3;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1_MFP_Msk)  | SYS_GPD_MFPL_PD1_MFP_CAP_DATA2;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD2_MFP_Msk)  | SYS_GPD_MFPL_PD2_MFP_CAP_DATA1;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD3_MFP_Msk)  | SYS_GPD_MFPL_PD3_MFP_CAP_DATA0;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4_MFP_Msk)  | SYS_GPD_MFPL_PD4_MFP_CAP_SCLK;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5_MFP_Msk)  | SYS_GPD_MFPL_PD5_MFP_CAP_VSYNC;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD6_MFP_Msk)  | SYS_GPD_MFPL_PD6_MFP_CAP_HSYNC;
    SYS->GPD_MFPL = (SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD7_MFP_Msk)  | SYS_GPD_MFPL_PD7_MFP_CAP_PIXCLK;
    SYS->GPC_MFPH = (SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12_MFP_Msk) | SYS_GPC_MFPH_PC12_MFP_CAP_DATA7;
    SYS->GPC_MFPH = (SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13_MFP_Msk) | SYS_GPC_MFPH_PC13_MFP_CAP_DATA6;
    SYS->GPC_MFPH = (SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14_MFP_Msk) | SYS_GPC_MFPH_PC14_MFP_CAP_DATA5;
    SYS->GPC_MFPH = (SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15_MFP_Msk) | SYS_GPC_MFPH_PC15_MFP_CAP_DATA4;

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART0_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART0->LCR |=0x07;
    UART0->BAUD = 0x30000066;    /* 12MHz reference clock input, for 115200 */
}

void MotionDetection8x8(void)
{
    uint32_t i;
    uint8_t *pu8MotionDetAddr;

    /* Initialize NT99141 sensor and set NT99141 output YUV422 format  */
    if(InitNT99141_VGA_YUV422()==FALSE) return;

    /* Enable External VIN Interrupt */
    NVIC_EnableIRQ(CAP_IRQn);

    /* Enable External VIN Interrupt & Motion Detection Interrupt */
    CAP_EnableInt(CAP_CAPINT_VINTEN_Msk | CAP_CAPINT_MDINTEN_Msk);

    /* Set Vsync polarity, Hsync polarity, pixel clock polarity, Sensor Format and Order */
    CAP_Open(NT99141SensorPolarity | NT99141DataFormatAndOrder, CAP_CAPCTL_PKEN );

    /* Set Cropping Window Vertical/Horizontal Starting Address and Cropping Window Size */
    CAP_SetCroppingWindow(0,0,SENSOR_IN_HEIGHT,SENSOR_IN_WIDTH);

    /* Set System Memory Packet Base Address Register */
    CAP_SetPacketBuf((uint32_t)u8FrameBuffer);

    /* Set Packet Scaling Vertical/Horizontal Factor Register */
    CAP_SetPacketScaling(SYSTEM_HEIGHT,SENSOR_IN_HEIGHT,SYSTEM_WIDTH,SENSOR_IN_WIDTH);

    /* Set Packet Frame Output Pixel Stride Width */
    CAP_SetPacketStride(SYSTEM_WIDTH);

    /* Enable Motion Detection */
    CAP_EnableMotionDet(0,TRUE,FALSE,20,(uint32_t)u8MDOutputYBuffer,(uint32_t)u8MDOutputBuffer);

    /* Image Capture Interface Start */
    CAP_Start();

    u32FramePass = 0;
    while( (u32FramePass<5) );

    while(1) {

        /* Enable Image Capture Interface */
        CAP_Start();

        printf("Press and key to get background image\n");
        i=getchar();

        CAP_Stop(TRUE);    /* Set one shutter mode */

        printf("Press and key to get difference image\n");
        i=getchar();

        CAP_Stop(TRUE);    /* Set one shutter mode */

        pu8MotionDetAddr=u8MDOutputBuffer;
        for(i=0; i<SYSTEM_WIDTH/8*SYSTEM_HEIGHT/8; i=i+1) {
            uint32_t u32Div = SYSTEM_WIDTH/8;
            if( ((i%u32Div)==0) ) {
                printf("\n");
                if(((SYSTEM_WIDTH/8)%4)!=0)
                    pu8MotionDetAddr = pu8MotionDetAddr+(4-(SYSTEM_WIDTH/8)%4);
            }
            if(((*pu8MotionDetAddr++) & 0x80)==0x80)
                printf("*");
            else
                printf("+");
        }
        printf("\n");
    }
}

