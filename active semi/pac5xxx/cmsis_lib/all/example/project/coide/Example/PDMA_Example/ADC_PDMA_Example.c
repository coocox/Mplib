
/**************************************************************************//**
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/


#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
#include "ADC.h"
#include "PDMA.h"
#include "UART.h"


#define DBG_PRINT      printf

#define	ADC_CH_NUM     3
#define ADC_SMP_COUNT  100
#define ADC_BUF_SIZE   (ADC_SMP_COUNT*ADC_CH_NUM)

volatile BOOL bIsPDMAInt = FALSE;
static uint16_t u16ADCBuf[ADC_BUF_SIZE];

void SYS_Init(void);
void UART0_Init(void);
void ADC_Init(void);
void PDMA_Init(void);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int PDMA_Example (void)
{
    int32_t i;

    SYS_Init();                                  //En:Init System
    UART0_Init();                                //En:Init UART0

    DBG_PRINT("ADC PDMA channel 0, 2, 3 continuous mode test ...... \n");

    ADC_Init();                                //En:Init ADC
    PDMA_Init();                                //En:Init PDMA
    PDMA_TRG_ENABLE(PDMA0);                  //En:Trigger PDMA
    ADC_START_CONVERSION();                    //En:Enable ADC conversion start

    while(1)
    {
        if(bIsPDMAInt)
        {
            bIsPDMAInt = FALSE;
            ADC_STOP_CONVERSION();                    //En:Stop ADC conversion
            ADC_PDMA_DISABLE();

            DBG_PRINT("\nConversion result:ADC0 = \n{\n");
            for(i=0; i<ADC_SMP_COUNT; i++)
            {
                DBG_PRINT("%d,", u16ADCBuf[i*ADC_CH_NUM]);
                if((i+1)%10 == 0)
                    DBG_PRINT("\n");
            }
            DBG_PRINT("}\n");

            DBG_PRINT("\nConversion result:ADC2 = \n{\n");
            for(i=0; i<ADC_SMP_COUNT; i++)
            {
                DBG_PRINT("%d,", u16ADCBuf[i*ADC_CH_NUM+1]);
                if((i+1)%10 == 0)
                    DBG_PRINT("\n");
            }
            DBG_PRINT("}\n");

            DBG_PRINT("\nConversion result:ADC3 = \n{\n");
            for(i=0; i<ADC_SMP_COUNT; i++)
            {
                DBG_PRINT("%d,", u16ADCBuf[i*ADC_CH_NUM+2]);
                if((i+1)%10 == 0)
                    DBG_PRINT("\n");
            }
            DBG_PRINT("}\n");

            SYS_SysTickDelay(1000000);
            if(ADC_IS_RSLT_VALID(0))
                ADC_GET_RSLT(0);
            if(ADC_IS_RSLT_VALID(2))
                ADC_GET_RSLT(2);
            if(ADC_IS_RSLT_VALID(3))
                ADC_GET_RSLT(3);
            ADC_PDMA_ENABLE();
            PDMA_TRG_ENABLE(PDMA0);                  //En:Trigger PDMA
            ADC_START_CONVERSION();                    //En:Enable ADC conversion start
        }
    }
}

/**
 * @brief       PDMA interrupt handler
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PDMA interrupt handler
 */
void PDMA_IRQHandler(void)
{
    if(PDMA_GET_IF(PDMA0, PDMA_TABORT_INT))
    {
        PDMA_CLR_IF(PDMA0, PDMA_TABORT_INT);               //En:Clear PDMA interrupt status
        DBG_PRINT("PDMA Target Abort\n");
    }
    else if(PDMA_GET_IF(PDMA0, PDMA_BLKD_INT))
    {
        PDMA_CLR_IF(PDMA0, PDMA_BLKD_INT);               //En:Clear PDMA interrupt status
        bIsPDMAInt = TRUE;
    }
}

/**
 * @brief       System init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock, GPIO multi-function setting
 */
void SYS_Init(void)
{
    SYS_UnlockReg();                                        //En:Unlock protected registers
    GPIO_XT1();
    CLK_HXT_ENABLE();                                        //En:Enable External XTAL (4~24 MHz)
    while(!CLK_IS_STABLE(CLK_HXT_STB)); //En:Waiting for 12MHz clock ready
    SET_HCLK_CLKSRC(CLK_HCLK_HXT);                  //En:Switch HCLK clock source to XTAL
    SystemCoreClockUpdate();                                //En:Update the variable SystemCoreClock

    GPIO_UART0_RXTX();           //En:Set PB multi-function pins for UART0 RXD, UART0 TXD

    GPIO_ADC0();        //En:Set GPIOD.0 to ADC channel 0 mode
    GPIO_ADC2();        //En:Set GPIOD.2 to ADC channel 2 mode
    GPIO_ADC3();        //En:Set GPIOD.3 to ADC channel 3 mode

    GPIO_SET_MODE(PD, 0, GPIO_INPUT);
    GPIO_DISABLE_DIGITAL_PATH(PD, 0);

    GPIO_SET_MODE(PD, 2, GPIO_INPUT);
    GPIO_DISABLE_DIGITAL_PATH(PD, 2);

    GPIO_SET_MODE(PD, 3, GPIO_INPUT);
    GPIO_DISABLE_DIGITAL_PATH(PD, 3);

    SYS_LockReg();                                          //En:Lock protected registers
}

/**
 * @brief       UART0 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set UART0 8n1, 115200bps
 */
void UART0_Init(void)
{
    STR_UART_T sParam;

    sParam.u32ClkSrc = CLK_UART_HXT;
    sParam.u32ClkDiv = 1;
    sParam.u32ClkFreq = __XTAL;
    sParam.u32BaudRate = 115200;
    sParam.u32cDataBits = UART_WORD_LEN_8;
    sParam.u32cStopBits = UART_STOP_BIT_1;
    sParam.u32cParity = UART_PARITY_NONE;
    sParam.u32cRxTriggerLevel = UART_FCR_RFITL_1BYTE;
    sParam.u32BaudMode = UART_BAUD_MODE2;
    DrvUART_Init (UART0, &sParam);
}

/**
 * @brief       ADC init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable ADC channel 0, 2, 3 continuous mode, PDMA transfer
 */
void ADC_Init(void)
{
    DrvADC_Init(ADC_CONT_SCAN, 0x0D, CLK_ADC_HXT, 6);
    ADC_PDMA_ENABLE();
}

/**
 * @brief       PDMA init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set PDMA channel 0 for ADC_RX use
 */
void PDMA_Init(void)
{
    STR_PDMA_T sParam;

    AHBCLK_ENABLE(CLK_PDMA);
    SYS_RESET_IP1(SYS_RST_PDMA);

    sParam.u32SrcCtrl    = PDMA_SAD_FIXED;
    sParam.u32SrcAddr    = (uint32_t)&ADC->PDMA;
    sParam.u32DestCtrl   = PDMA_DAD_INC;
    sParam.u32DestAddr   = (uint32_t)&u16ADCBuf[0];
    sParam.u32TransWidth = PDMA_APB_TWS_16BIT;
    sParam.u32Mode       = PDMA_MD_APB2MEM;
    sParam.u32ByteCnt    = ADC_BUF_SIZE*sizeof(u16ADCBuf[0]);

    DrvPDMA_Init(PDMA0, &sParam);
    PDMA_SET_ADC_RX_CH(PDMA_ADC_RX_CH0); //En:Select PDMA0 as ADC_RX PDMA transfer channel
    DrvPDMA_EnableInt(PDMA0, PDMA_BLKD_INT | PDMA_TABORT_INT);
}

