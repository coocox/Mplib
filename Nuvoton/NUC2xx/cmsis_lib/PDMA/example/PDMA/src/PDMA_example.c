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
#include "PDMA.h"


/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000


int32_t UART_TEST_LENGTH =64;
volatile uint32_t SrcArray[16];
volatile uint32_t DestArray[16];
volatile int32_t IntCnt;
volatile int32_t IsTestOver;
extern char uart_getchar(void);
volatile uint32_t g_u32TwoChannelPdmaTest=0;
void PDMA_Callback_0(void);
void PDMA_Callback_1(void);

/*---------------------------------------------------------------------------------------------------------*/
/* Function:     PDMA_IRQHandler     		                                                               */
/*                                                                                                         */
/* Parameter:        																					   */
/*				 None 												                                       */
/* Returns:                                                                                                */
/*               None                                                                                      */
/* Description:                                                                                            */
/*               The function is used to  PDMA ISR                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void PDMA_IRQHandler(void)
{
    if((PDMA0->ISR&PDMA_ISR_BLKD_IF_Msk) == PDMA_ISR_BLKD_IF_Msk)
    {
        PDMA0->ISR = PDMA_ISR_BLKD_IF_Msk;   //Clear Block transfer down interrupt flag
        if(g_u32TwoChannelPdmaTest == 1)
        {
            PDMA_Callback_0();
        }
        else if(g_u32TwoChannelPdmaTest == 0)
        {
            PDMA_Callback_1();
        }
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/* Interrupt Handler                                                                                 	   */
/*---------------------------------------------------------------------------------------------------------*/
void UART02_IRQHandler(void)
{
    if((UART0->ISR & UART_ISR_RDA_IF_Msk) == UART_ISR_RDA_IF_Msk)
        UART1->DATA = UART0->DATA;
}


/*---------------------------------------------------------------------------------------------------------*/
/* Clear buffer funcion                                                                              	   */
/*---------------------------------------------------------------------------------------------------------*/

void ClearBuf(uint32_t u32Addr, uint32_t u32Length,uint8_t u8Pattern)
{
	uint8_t* pu8Ptr;
	uint32_t i;

	pu8Ptr = (uint8_t *)u32Addr;

	for (i=0; i<u32Length; i++)
	{
		*pu8Ptr++ = u8Pattern;
	}
}

/*---------------------------------------------------------------------------------------------------------*/
/* Bulid Src Pattern function                                                                         	   */
/*---------------------------------------------------------------------------------------------------------*/

void BuildSrcPattern(uint32_t u32Addr, uint32_t u32Length)
{
    uint32_t i=0,j,loop;
    uint8_t* pAddr;

    pAddr = (uint8_t *)u32Addr;

    do {
        if (u32Length > 256)
	    	loop = 256;
	    else
	    	loop = u32Length;

	   	u32Length = u32Length - loop;

        for(j=0;j<loop;j++)
            *pAddr++ = (uint8_t)(j+i);

	    i++;
	} while ((loop !=0) || (u32Length !=0));
}

/*---------------------------------------------------------------------------------------------------------*/
/* PDMA Callback function                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/

void PDMA_Callback_0(void)
{
	extern volatile int32_t IntCnt;
	printf("\tTransfer Done %02d!\r",++IntCnt);

	if(IntCnt<10)
	{
        PDMA1->CSR|= PDMA_CSR_TRIG_EN_Msk;
        PDMA0->CSR|= PDMA_CSR_TRIG_EN_Msk;
	}
	else
	{
		IsTestOver = TRUE;
	}
}


void PDMA_Callback_1(void)
{
	extern volatile int32_t IntCnt;
	int32_t i ;

	printf("\tTransfer Done %02d!\t",++IntCnt);
	for(i=0;i<UART_TEST_LENGTH;i++)
        printf(" 0x%2x(%c),",inpb(((uint32_t)DestArray+i)),inpb(((uint32_t)DestArray+i)));
//	printf("\n");
	if(IntCnt<10)
	{
		PDMA0->CSR|= PDMA_CSR_TRIG_EN_Msk;
	}
	else
	{
		IsTestOver = TRUE;
	}
}


/*---------------------------------------------------------------------------------------------------------*/
/* PDMA Sample Code:                                                                                  	   */
/*         i32option : ['1'] UART1 TX/RX PDMA Loopback                                                     */
/*                     [Others] UART1 RX PDMA test                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void PDMA_UART(int32_t i32option)
{
    uint32_t  UARTPort;

    volatile uint32_t i;
	BuildSrcPattern((uint32_t)SrcArray,UART_TEST_LENGTH);

   	UARTPort = UART1_BASE;
    ClearBuf((uint32_t)DestArray, UART_TEST_LENGTH,0xFF);

    SYSCLK->AHBCLK|= SYSCLK_AHBCLK_PDMA_EN_Msk;

	if(i32option =='1')
	{
		printf("  [Using TWO PDMA channel]. \n");
	 	printf("  This sample code will use PDMA to do UART1 loopback 10 times test. \n");
        printf("  Please connect GPB4 <--> GPB5 before testing.\n");
	    printf("  After connecting GPB4 <--> GPB5, press any key to start transfer.\n");
	    g_u32TwoChannelPdmaTest = 1;
        uart_getchar();
	}
	else
	{
		UART_TEST_LENGTH = 2;	   /* Test Length */
 		printf("  [Using ONE PDMA channel]. \n");
	 	printf("  This sample code will use PDMA to do UART1 Rx test ten times. \n");
        printf("  Please connect GPB4 <--> GPB5 before testing.\n");
	    printf("  After connecting GPB4 <--> GPB5, press any key to start transfer.\n");
        g_u32TwoChannelPdmaTest = 0;
	    uart_getchar();
		printf("  Please input %d bytes to trigger PDMA one time.(Ex: Press 'a''b')\n",UART_TEST_LENGTH);
	}

	if(g_u32TwoChannelPdmaTest==1)
	{
		/* PDMA Setting */
        _PDMAGCR_PDSSR1_UART1_TXSEL(1);

		/* CH1 TX Setting */
        /* Enable PDMA channel 1 clock */
        PDMA_GCR->GCRCSR|= PDMA_GCRCSR_CLK1_EN_Msk;

        /* Enable PDMA channel 1, Set Source/destination transfer direction,
           Set PDMA mode, Set peripheral transfer width */
        PDMA1->CSR = PDMA_CSR_PDMACEN_Msk | PDMA_CSR_SAD_SEL_INCREASE | PDMA_CSR_DAD_SEL_FIXED |
                     PDMA_CSR_APB_TWS_8BITS | PDMA_CSR_MODE_SEL_M2P;
        PDMA1->SAR = (uint32_t)SrcArray;    /* Set Source Address */
        PDMA1->DAR = UARTPort;              /* Set Destination Address */
        PDMA1->BCR = UART_TEST_LENGTH;
	}

	/* PDMA Setting */
    _PDMAGCR_PDSSR1_UART1_RXSEL(0);

 	/* CH0 RX Setting */
    /* Enable PDMA channel 0 clock */
    PDMA_GCR->GCRCSR|= PDMA_GCRCSR_CLK0_EN_Msk;

    /* Enable PDMA channel 0, Set Source/destination transfer direction,
       Set PDMA mode, Set peripheral transfer width */
    PDMA0->CSR = PDMA_CSR_PDMACEN_Msk | PDMA_CSR_SAD_SEL_FIXED | PDMA_CSR_DAD_SEL_INCREASE |
                 PDMA_CSR_APB_TWS_8BITS | PDMA_CSR_MODE_SEL_P2M;
    PDMA0->SAR = UARTPort;              /* Set Source Address */
    PDMA0->DAR = (uint32_t)DestArray;   /* Set Destination Address */
    PDMA0->BCR = UART_TEST_LENGTH;

	/* Enable PDMA Block Transfer Done Interrupt */
    PDMA0->IER = PDMA_IER_BLKD_IE_Msk;

    NVIC_EnableIRQ(PDMA_IRQn);

    if(g_u32TwoChannelPdmaTest==0)
    {
        UART0->IER|= UART_IER_RDA_IEN_Msk;
        NVIC_EnableIRQ(UART02_IRQn);
    }

	/* Trigger PDMA0 */
    PDMA0->CSR|= PDMA_CSR_TRIG_EN_Msk;

	if(g_u32TwoChannelPdmaTest==1)
        PDMA1->CSR|= PDMA_CSR_TRIG_EN_Msk;

    /* Enable UART1 TX and RX DMA function */
    if(g_u32TwoChannelPdmaTest==1)
	    UART1->IER|= UART_IER_DMA_TX_EN_Msk;
    else
        UART1->IER&= ~UART_IER_DMA_TX_EN_Msk;

	UART1->IER|= UART_IER_DMA_RX_EN_Msk;

	IntCnt = 0;

	/* Trigger PDMA 10 time and the S/W Flag will be change in PDMA callback funtion */
	while(IsTestOver==FALSE);

	/* Disable PDMA clock */
    SYSCLK->AHBCLK&= ~SYSCLK_AHBCLK_PDMA_EN_Msk;
    /* Disable UART0 RDA interrupt */
    UART0->IER&= ~UART_IER_RDA_IEN_Msk;
    NVIC_DisableIRQ(UART02_IRQn);
	return;

}


void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable external 12MHz XTAL */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk | SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */
    SYSCLK->AHBCLK = SYSCLK_AHBCLK_PDMA_EN_Msk;
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_UART1_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL;

    /* Reset PDMA and UART0/1*/
    SYS->IPRSTC1 = SYS_IPRSTC1_PDMA_RST_Msk;
    SYS->IPRSTC1 = 0;
    SYS->IPRSTC2 = SYS_IPRSTC2_UART0_RST_Msk | SYS_IPRSTC2_UART1_RST_Msk;
    SYS->IPRSTC2 = 0;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB0/PB1 multi-function pins for UART0 RXD and TXD  */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0 |
                   SYS_GPB_MFP_PB4_RXD1 | SYS_GPB_MFP_PB5_TXD1;

    /* Lock protected registers */
    SYS_LockReg();
}


void UART0_Init(void)
{

/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

void UART1_Init(void)
{

/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART1, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}



/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                           	   			   */
/*---------------------------------------------------------------------------------------------------------*/

void PDMA_Example()
{
   	uint8_t unItem;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART0 for printf */
    UART0_Init();
    /* Init UART1 for PDMA test */
    UART1_Init();

	do
	{
		/* PDMA Sample Code: UART1 Tx/Rx Loopback */
//		printf("\n\n");
		printf("+------------------------------------------------------------------------+\n");
	    printf("|                         PDMA Driver Sample Code                        |\n");
	    printf("|                                                                        |\n");
	    printf("+------------------------------------------------------------------------+\n");
		printf("| [1] Using TWO PDMA channel to test. < TX1(CH1)-->RX1(CH0) >            |\n");
	    printf("| [2] Using ONE PDMA channel to test. < TX1-->RX1(CH0) >                 |\n");
		printf("+------------------------------------------------------------------------+\n");
		unItem = uart_getchar();

		IsTestOver =FALSE;
        if((unItem=='1') || (unItem == '2'))
        {
		    PDMA_UART(unItem);
//            printf("\n\n  PDMA sample code is complete.\n");
        }
    }while(unItem!=0x27);
//	return 0;
}
