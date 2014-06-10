/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/06/12 2:19p $
 * @brief    NUC200 Series ADC Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/

/*---------------------------------------------------------------------------------------------------------*/
/* Include related header files                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC200Series.h"
#include "ADC.h"
#include "SYS.h"
#include "UART.h"
#include "GPIO.h"


#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000



/*---------------------------------------------------------------------------------------------------------*/
/* Define Function Prototypes                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
void SYS_Init(void);
void UART0_Init(void);
void AdcSingleModeTest(void);
void AdcSingleCycleModeTest(void);
void AdcContScanModeTest(void);
void AdcResultMonitorTest(void);
void AdcIntCallback_BurstMode(void);

/*---------------------------------------------------------------------------------------------------------*/
/* Define global variables and constants                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define BURST_COUNT 20
volatile uint32_t g_u32AdcIntFlag;
volatile uint32_t g_u32AdcCmp0IntFlag;
volatile uint32_t g_u32AdcCmp1IntFlag;
volatile uint32_t g_u32AdcDataCount;
uint16_t g_au16AdcData[BURST_COUNT];


/*---------------------------------------------------------------------------------------------------------*/
/* Main function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
void ADC_Example(void)
{
    uint8_t u8Option;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("\nSystem clock rate: %dHz", SystemCoreClock);

    do{
        printf("\n\nConversion rate: %d samples/second\n", ADC_GetConversionRate());
//        printf("\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("|                            ADC sample code                           |\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("  [1] ADC single mode test\n");
        printf("  [2] ADC single cycle mode test\n");
        printf("  [3] ADC continuous scan mode test\n");
        printf("  [4] ADC compare function test\n");
        printf("  [Q or q] Quit\n");
        printf("Please choose a test item.\n");
        u8Option = uart_getchar();
        printf("%c\n",u8Option);
        switch(u8Option)
        {
            case '1':   AdcSingleModeTest();        break;
            case '2':   AdcSingleCycleModeTest();   break;
            case '3':   AdcContScanModeTest();      break;
            case '4':   AdcResultMonitorTest();     break;
            default:    break;
        }
    }while( (u8Option != 'Q') && (u8Option != 'q') );

    ADC_ResetIP();
    _ADC_DISABLE_CLOCK();
    NVIC_DisableIRQ(ADC_IRQn);
    printf("Exit ADC sample code\n");

    return 0;
}

/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock, IP clock, I/O multi-function and UART0                                               */
/*---------------------------------------------------------------------------------------------------------*/
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
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_ADC_EN_Msk ;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_XTAL | SYSCLK_CLKSEL1_ADC_XTAL ;

    /* Set ADC divisor */
    _ADC_SET_CLK_DIV(7);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set GPB multi-function pins for UART0 RXD and TXD  */
    SYS->GPB_MFP = SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB0_RXD0;

    /* Disable the GPA0 - GPA3 digital input path to avoid the leakage current. */
    PA->OFFD = (GPIO_OFFD_ENABLE(0)|GPIO_OFFD_ENABLE(1)|GPIO_OFFD_ENABLE(2)|GPIO_OFFD_ENABLE(3));
    /* Configure the GPA0 - GPA3 ADC analog input pins */
    SYS->GPA_MFP = SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1 | SYS_GPA_MFP_PA2_ADC2 | SYS_GPA_MFP_PA3_ADC3 ;
    SYS->ALT_MFP1 = 0;

    /* Lock protected registers */
    SYS_LockReg();
}

/*---------------------------------------------------------------------------------------------------------*/
/* Init UART0                                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
void UART0_Init(void)
{
    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(__XTAL, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

/*---------------------------------------------------------------------------------------------------------*/
/* Function: AdcSingleModeTest                                                                             */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Returns:                                                                                                */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Description:                                                                                            */
/*   ADC single mode test.                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void AdcSingleModeTest()
{
    uint8_t  u8Option;
    int32_t  i32ConversionData;

    printf("\n=== Single mode test ===\n");

    while(1)
    {
        printf("Select input mode:\n");
        printf("  [1] Single end input (channel 2 only)\n");
        printf("  [2] Differential input (channel pair 1 only)\n");
        printf("  Other keys: exit single mode test\n");
        u8Option = uart_getchar();
        if(u8Option=='1')
        {
            /* Set the ADC operation mode as single, input mode as single-end and enable the ADC converter */
            ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 2 */
            _ADC_SET_CHANNEL(1<<2);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* Enable the ADC interrupt */
            _ADC_ENABLE_ADC_INT();
            NVIC_EnableIRQ(ADC_IRQn);

            /* Reset the ADC interrupt indicator and Start A/D conversion */
            g_u32AdcIntFlag = 0;
            _ADC_START_CONVERT();

            /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler Fuction)*/
            while(g_u32AdcIntFlag==0);

            /* Disable the ADC interrupt */
            _ADC_DISABLE_ADC_INT();

            /* Get the conversion result of the ADC channel 2 */
            i32ConversionData = _ADC_GET_CONVERSION_DATA(2);
            printf("Conversion result of channel 2: 0x%X (%d)\n\n", i32ConversionData, i32ConversionData);
        }
        else if(u8Option=='2')
        {
            /* Set the ADC operation mode as single, input mode as differential and enable the ADC converter */
            ADC->ADCR = (ADC_ADCR_ADMD_SINGLE | ADC_ADCR_DIFFEN_DIFFERENTIAL | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 2 for differential input channel pair 1 */
            _ADC_SET_CHANNEL(1<<2);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* Enable the ADC interrupt */
            _ADC_ENABLE_ADC_INT();
            NVIC_EnableIRQ(ADC_IRQn);

            /* Reset the ADC interrupt indicator and Start A/D conversion */
            g_u32AdcIntFlag = 0;
            _ADC_START_CONVERT();

            /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler Fuction)*/
            while(g_u32AdcIntFlag==0);

            /* Disable the ADC interrupt */
            _ADC_DISABLE_ADC_INT();

            /* Get the conversion result of the specified ADC channel */
            i32ConversionData = _ADC_GET_CONVERSION_DATA(2);
            printf("Conversion result of channel pair 1: 0x%X (%d)\n\n", i32ConversionData, i32ConversionData);
        }
        else
            return ;

    }
}



/*---------------------------------------------------------------------------------------------------------*/
/* Function: AdcSingleCycleModeTest                                                                        */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Returns:                                                                                                */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Description:                                                                                            */
/*   ADC single cycle scan mode test.                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void AdcSingleCycleModeTest()
{
    uint8_t  u8Option;
    uint32_t u32ChannelCount;
    int32_t  i32ConversionData;

    printf("\n=== Single cycle scan mode test ===\n");

    while(1)
    {
        printf("\n\nSelect input mode:\n");
        printf("  [1] Single end input (channel 0, 1, 2 and 3)\n");
        printf("  [2] Differential input (input channel pair 0 and 1)\n");
        printf("  Other keys: exit single cycle scan mode test\n");
        u8Option = uart_getchar();
        if(u8Option=='1')
        {
            /* Set the ADC operation mode as single-cycle, input mode as single-end and enable the ADC converter  */
            ADC->ADCR = (ADC_ADCR_ADMD_SINGLE_CYCLE | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 0, 1, 2 and 3 */
            _ADC_SET_CHANNEL(0xF);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* start A/D conversion */
            _ADC_START_CONVERT();

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            for(u32ChannelCount=0; u32ChannelCount<4; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount);
                printf("Conversion result of channel %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }
        }
        else if(u8Option=='2')
        {
            /* Set the ADC operation mode as single-cycle, input mode as differential and enable the ADC converter */
            ADC->ADCR = (ADC_ADCR_ADMD_SINGLE_CYCLE | ADC_ADCR_DIFFEN_DIFFERENTIAL | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 0 and 2 */
            _ADC_SET_CHANNEL(0x5);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* start A/D conversion */
            _ADC_START_CONVERT();

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            for(u32ChannelCount=0; u32ChannelCount<2; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount*2);
                printf("Conversion result of differential input pair %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }
        }
        else
            return ;

    }
}

/*---------------------------------------------------------------------------------------------------------*/
/* Function: AdcContScanModeTest                                                                           */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Returns:                                                                                                */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Description:                                                                                            */
/*   ADC continuous scan mode test.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
void AdcContScanModeTest()
{
    uint8_t  u8Option;
    uint32_t u32ChannelCount;
    int32_t  i32ConversionData;

    printf("\n=== Continuous scan mode test ===\n");
    printf("\nIn this test, software will get 2 cycles of conversion result from the specified channels.\n");

    while(1)
    {
        printf("\n\nSelect input mode:\n");
        printf("  [1] Single end input (channel 0, 1, 2 and 3)\n");
        printf("  [2] Differential input (input channel pair 0 and 1)\n");
        printf("  Other keys: exit continuous scan mode test\n");
        u8Option = uart_getchar();
        if(u8Option=='1')
        {
            /* Set the ADC operation mode as continous scan, input mode as single-end and enable the ADC converter */
            ADC->ADCR = (ADC_ADCR_ADMD_CONTINUOUS | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 0, 1, 2 and 3 */
            _ADC_SET_CHANNEL(0xF);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* start A/D conversion */
            _ADC_START_CONVERT();

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            /* Clear the ADC interrupt flag */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            for(u32ChannelCount=0; u32ChannelCount<4; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount);
                printf("Conversion result of channel %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            /* Stop A/D conversion */
            _ADC_STOP_CONVERT();

            for(u32ChannelCount=0; u32ChannelCount<4; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount);
                printf("Conversion result of channel %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }

            /* Clear the ADC interrupt flag */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

        }
        else if(u8Option=='2')
        {
            /* Set the ADC operation mode as continous scan, input mode as differential and enable the ADC converter */
            ADC->ADCR = (ADC_ADCR_ADMD_CONTINUOUS | ADC_ADCR_DIFFEN_DIFFERENTIAL | ADC_ADCR_ADEN_CONVERTER_ENABLE);
            /* Enable analog input channel 0 and 2 */
            _ADC_SET_CHANNEL(0x5);

            /* clear the A/D interrupt flag for safe */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            /* start A/D conversion */
            _ADC_START_CONVERT();

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            /* Clear the ADC interrupt flag */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

            for(u32ChannelCount=0; u32ChannelCount<2; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount*2);
                printf("Conversion result of differential input pair %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }

            /* Wait conversion done */
            _ADC_WAIT_COVERSION_DONE();

            /* Stop A/D conversion */
            _ADC_STOP_CONVERT();

            for(u32ChannelCount=0; u32ChannelCount<2; u32ChannelCount++)
            {
                i32ConversionData = _ADC_GET_CONVERSION_DATA(u32ChannelCount*2);
                printf("Conversion result of differential input pair %d: 0x%X (%d)\n", u32ChannelCount, i32ConversionData, i32ConversionData);
            }

            /* Clear the ADC interrupt flag */
            ADC->ADSR = ADC_ADSR_ADF_Msk;

        }
        else
            return ;

    }
}


/*---------------------------------------------------------------------------------------------------------*/
/* Function: AdcResultMonitorTest                                                                          */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Returns:                                                                                                */
/*   None.                                                                                                 */
/*                                                                                                         */
/* Description:                                                                                            */
/*   ADC result monitor function test.                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
void AdcResultMonitorTest()
{
    printf("\n=== ADC compare function test ===\n");
    printf("\nIn this test, software will compare the conversion result of channel 2.\n");

    /* Set the ADC operation mode as continuous scan, input mode as single-end and enable the ADC converter */
    ADC->ADCR = (ADC_ADCR_ADMD_CONTINUOUS | ADC_ADCR_DIFFEN_SINGLE_END | ADC_ADCR_ADEN_Msk);

    /* Set the ADC channel 2 */
    _ADC_ENABLE_CHANNEL(2);

    /* Enable ADC comparator 0. Compare condition: conversion result < 0x800; match Count=5. */
    printf("   Set the compare condition of comparator 0: channel 2 is less than 0x800; match count is 5.\n");
    _ADC_SET_CMP0(2, ADC_LESS_THAN, 0x800, 5);
    _ADC_ENABLE_CMP(0);

    /* Enable ADC comparator 1. Compare condition: conversion result >= 0x800; match Count=5. */
    printf("   Set the compare condition of comparator 1 : channel 2 is greater than or equal to 0x800; match count is 5.\n");
    _ADC_SET_CMP1(2, ADC_GREATER_OR_EQUAL, 0x800, 5);
    _ADC_ENABLE_CMP(1);

    /* clear the ADC comparator 0 interrupt flag for safe */
    _ADC_CLEAR_CMP0_INT_FLAG();
    /* enable ADC comparator 0 interrupt */
    _ADC_ENABLE_CMP_INT(0);

    /* clear the ADC comparator 1 interrupt flag for safe */
    _ADC_CLEAR_CMP1_INT_FLAG();
    /* enable ADC comparator 1 interrupt */
    _ADC_ENABLE_CMP_INT(1);

    NVIC_EnableIRQ(ADC_IRQn);

    g_u32AdcCmp0IntFlag = 0;
    g_u32AdcCmp1IntFlag = 0;

    /* Clear the ADC interrupt flag */
    ADC->ADSR = ADC_ADSR_ADF_Msk;

    /* start A/D conversion */
    _ADC_START_CONVERT();

    /* Wait ADC compare interrupt */
    while((g_u32AdcCmp0IntFlag==0)&&(g_u32AdcCmp1IntFlag==0));

    /* Stop A/D conversion */
    _ADC_STOP_CONVERT();
    /* Disable ADC comparator interrupt */
    _ADC_DISABLE_CMP_INT(0);
    _ADC_DISABLE_CMP_INT(1);
    /* Disable compare function */
    _ADC_DISABLE_CMP(0);
    _ADC_DISABLE_CMP(1);

    if(g_u32AdcCmp0IntFlag==1)
    {
        printf("Comparator 0 interrupt occurs.\nThe conversion result of channel 2 is less than 0x800\n");
    }
    else
    {
        printf("Comparator 1 interrupt occurs.\nThe conversion result of channel 2 is greater than or equal to 0x800\n");
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/* ADC interrupt handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void ADC_IRQHandler(void)
{
    uint32_t u32OperationMode;

    if(ADC->ADSR & ADC_ADSR_ADF_Msk)
    {
        u32OperationMode = _ADC_GET_OPMODE();
        if(u32OperationMode==ADC_SINGLE_MODE)
        {
            g_u32AdcIntFlag = 1;
        }
        else if(u32OperationMode==ADC_SINGLE_CYCLE_MODE)
        {
            /* Add your callback function */
        }
        else if(u32OperationMode==ADC_CONTINUOUS_MODE)
        {
            /* Add your callback function */
        }
        ADC->ADSR = ADC_ADSR_ADF_Msk;      /* clear the A/D conversion flag */
    }

    if(ADC->ADSR & ADC_ADSR_CMPF0_Msk)
    {
        g_u32AdcCmp0IntFlag = 1;
        _ADC_CLEAR_CMP0_INT_FLAG();     /* clear the A/D compare flag 0 */
    }

    if(ADC->ADSR & ADC_ADSR_CMPF1_Msk)
    {
        g_u32AdcCmp1IntFlag = 1;
        _ADC_CLEAR_CMP1_INT_FLAG();     /* clear the A/D compare flag 1 */
    }
}



