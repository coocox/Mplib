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
#include "SC.h"


/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_HAVE_SC0
//#define SC_HAVE_SC1
//#define SC_HAVE_SC2
#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000

void SYS_Init(void);
void UART0_Init(void);
void Delay(uint32_t ucnt);

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void SC_Example(void)
{
	bool bLoop = true;
	int32_t i, j;
	int32_t atrlength;
	uint8_t atrbuf[50];
#ifdef SC_HAVE_SC0
	int32_t C0_state = 0, open0 = 0, C0_flag = 0;
#endif
#ifdef SC_HAVE_SC1
	int32_t C1_state = 0, open1 = 0, C1_flag = 0;
#endif
#ifdef SC_HAVE_SC2
	int32_t C2_state = 0, open2 = 0, C2_flag = 0;
#endif

    /* Init System, IP clock and multi-function I/O */
    SYS_Init(); //In the end of SYS_Init() will issue SYS_LockReg() to lock protected register. If user want to write protected register, please issue SYS_UnlockReg() to unlock protected register.

    /* Init UART0 for printf */
    UART0_Init();
    printf("+------------------------------------------------------------------------+\n");
    printf("|                          Smart Card Driver Sample Code                 |\n");
    printf("|                                                                        |\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("  This sample code will get smart card ATR data via SC0 port.\n  If more than one smart card designed in your system,\nuser can define SC_HAVE_SC1 and SC_HAVE_SC2 to enable SC1 and SC2 engine.\n");
    printf("  I/O configuration:\n");
    printf("  SC0CLK <--> smart card slot clock pin\n");
    printf("  SC0DAT <--> smart card slot data pin\n");
    printf("  SC0PWR <--> smart card slot power pin\n");
    printf("  SC0RST <--> smart card slot reset pin\n");
    printf("  SC0CD  <--> smart card slot card detect pin\n");

    printf("Please insert smart card to slot and press any key to continue.\n");
    uart_getchar();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);

	//SYS_UnlockReg();

#ifdef SC_HAVE_SC0
	SC_Init(SC0);
	SC_PowerActiveLevel(SC0, 1);
	SC_CardDetectEdge(SC0, 1);
	if(SC_STAUS_PRESENT == SC_CheckCardPresent(SC0))
    {
		open0 = 1;
		C0_state = 1;
	}
#endif

#ifdef SC_HAVE_SC1
	SC_Init(SC1);
	SC_PowerActiveLevel(SC1, 1);
    SC_CardDetectEdge(SC1, 1);
	if(SC_STAUS_PRESENT == SC_CheckCardPresent(SC1))
    {
		open1 = 1;
		C1_state = 1;
	}
#endif

#ifdef SC_HAVE_SC2
	SC_Init(SC2);
	SC_PowerActiveLevel(SC2, 1);
    SC_CardDetectEdge(SC2, 1);
	if(SC_STAUS_PRESENT == SC_CheckCardPresent(SC2))
    {
		open2 = 1;
		C2_state = 1;
    }
#endif

//	printf("\n");

	while ( bLoop )
	{
#ifdef SC_HAVE_SC0
		if(open0 == 1)
		{
			i = SC_Open(SC0);
			if(i < 0)
				printf("open card0 failed\n\n");
			else {
				atrlength = SC_GetATRBuffer(SC0, atrbuf, sizeof(atrbuf));
				printf("[CARD 0] ATR:");
				for (j = 0;j < atrlength;j++)
				{
					printf(" %x ", atrbuf[j]);
				}
				printf("\n\n\n");
			}
		}
        open0 = 0;
#endif

#ifdef SC_HAVE_SC1
		if(open1 == 1)
		{
			i = SC_Open(SC1);
			if(i < 0)
				printf("open card1 failed\n\n");
			else {
				atrlength = SC_GetATRBuffer(SC1, atrbuf, sizeof(atrbuf));
				printf("[CARD 1] ATR:");
				for (j = 0;j < atrlength;j++)
				{
					printf(" %x ", atrbuf[j]);
				}
				printf("\n\n\n");
			}
		}
        open1 = 0;
#endif

#ifdef SC_HAVE_SC2
		if(open2 == 1)
		{
			i = SC_Open(SC2);
			if(i < 0)
				printf("open card2 failed\n\n");
			else {
				atrlength = SC_GetATRBuffer(SC2, atrbuf, sizeof(atrbuf));
				printf("[CARD 2] ATR:");
				for (j = 0;j < atrlength;j++)
				{
					printf(" %x ", atrbuf[j]);
				}
				printf("\n\n\n");
			}
		}
        open2 = 0;
#endif

		while(1)
		{
#ifdef SC_HAVE_SC0
			if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC0)) && (C0_state==1))
				C0_flag = 1;	// insert -> remove
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC0)) && (C0_state==1) && (C0_flag==1))
				C0_flag = 2;	// reomve -> insert
			else if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC0)) && (C0_state==0))
				C0_state = 0;
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC0)) && (C0_state==0))
            {
				C0_flag = 2;	// card present
				C0_state = 1;
			}
			if(C0_flag == 2)
            {
				C0_flag = 0;
				open0 = 1;
				break;
			}
#endif

#ifdef SC_HAVE_SC1
			if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC1)) && (C1_state==1))
				C1_flag = 1;	// insert -> remove
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC1)) && (C1_state==1) && (C1_flag==1))
				C1_flag = 2;	// remove -> insert
			else if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC1)) && (C1_state==0))
				C1_state = 0;
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC1)) && (C1_state==0))
            {
				C1_flag = 2;	// card present
				C1_state = 1;
			}
			if(C1_flag == 2)
            {
				C1_flag = 0;
				open1 = 1;
				break;
			}
#endif

#ifdef SC_HAVE_SC2
			if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC2)) && (C2_state==1))
				C2_flag = 1;	// insert -> remove
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC2)) && (C2_state==1) && (C2_flag==1))
				C2_flag = 2;	// remove -> insert
			else if((SC_STAUS_ABSENT==SC_CheckCardPresent(SC2)) && (C2_state==0))
				C2_state = 0;
			else if((SC_STAUS_PRESENT==SC_CheckCardPresent(SC2)) && (C2_state==0))
            {
				C2_flag = 2;	// card present
				C2_state = 1;
			}

			if(C2_flag == 2)
            {
				C2_flag = 0;
				open2 = 1;
				break;
			}
#endif
		}

	}
	return true;
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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk;
    SYSCLK->APBCLK1 = SYSCLK_APBCLK1_SC0_EN_Msk|SYSCLK_APBCLK1_SC1_EN_Msk|SYSCLK_APBCLK1_SC2_EN_Msk;

    /* Select IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL;
    SYSCLK->CLKSEL3 = SYSCLK_CLKSEL3_SC0_XTAL|SYSCLK_CLKSEL3_SC1_XTAL|SYSCLK_CLKSEL3_SC2_XTAL;

    /* Reset SC0~2 */
    SYS->IPRSTC3 = SYS_IPRSTC3_SC0_RST_Msk|SYS_IPRSTC3_SC1_RST_Msk|SYS_IPRSTC3_SC2_RST_Msk;
    SYS->IPRSTC3 = 0;

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
    /* Set multi-function pins for SC0 ~ SC2 */
    /* SC0CLK = PA2, SC0DAT = PA3, SC0PWR = PA0, SC0RST = PA1, SC0CD = PC6,
       SC1CLK = PA6, SC1DAT = PA7, SC1PWR = PA4, SC1RST = PA5, SC1CD = PC7,
       SC2CLK = PA13,SC2DAT = PA12,SC2PWR = PA15,SC2RST = PA14,SC2CD = PB3 */

    SYS->GPA_MFP = SYS_GPA_MFP_PA0_SC0PWR | SYS_GPA_MFP_PA1_SC0RST | SYS_GPA_MFP_PA2_SC0CLK |
                   SYS_GPA_MFP_PA3_SC0DAT | SYS_GPA_MFP_PA4_SC1PWR | SYS_GPA_MFP_PA5_SC1RST |
                   SYS_GPA_MFP_PA6_SC1CLK | SYS_GPA_MFP_PA7_SC1DAT | SYS_GPA_MFP_PA12_SC2DAT|
                   SYS_GPA_MFP_PA13_SC2CLK| SYS_GPA_MFP_PA14_SC2RST| SYS_GPA_MFP_PA15_SC2PWR;
    SYS->GPB_MFP = SYS_GPB_MFP_PB3_SC2CD  | SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;
    SYS->GPC_MFP = SYS_GPC_MFP_PC6_SC0CD | SYS_GPC_MFP_PC7_SC1CD;
    SYS->ALT_MFP = SYS_ALT_MFP_PA7_SC1DAT | SYS_ALT_MFP_PA15_SC2PWR | SYS_ALT_MFP_PB3_SC2CD;
    SYS->ALT_MFP1= SYS_ALT_MFP1_PA0_SC0PWR | SYS_ALT_MFP1_PA1_SC0RST | SYS_ALT_MFP1_PA2_SC0CLK |
                   SYS_ALT_MFP1_PA3_SC0DAT | SYS_ALT_MFP1_PA4_SC1PWR | SYS_ALT_MFP1_PA5_SC1RST |
                   SYS_ALT_MFP1_PA6_SC1CLK | SYS_ALT_MFP1_PA7_SC1DAT | SYS_ALT_MFP1_PA12_SC2DAT|
                   SYS_ALT_MFP1_PA13_SC2CLK| SYS_ALT_MFP1_PA14_SC2RST| SYS_ALT_MFP1_PA15_SC2PWR|
                   SYS_ALT_MFP1_PB3_SC2CD | SYS_ALT_MFP1_PC6_SC0CD | SYS_ALT_MFP1_PC7_SC1CD;

    /* Set SC clock divider*/
    SYSCLK->CLKDIV1 = SYSCLK_CLKDIV1_SC0(3) | SYSCLK_CLKDIV1_SC1(3) | SYSCLK_CLKDIV1_SC2(3);
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
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}

void Delay(uint32_t ucnt)
{
    volatile uint32_t i = ucnt;

    while (i--);
}

