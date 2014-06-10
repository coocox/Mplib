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
#include "PS2.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000

uint32_t SystemFrequency  = PLL_CLOCK;   /*!< System Clock Frequency (Core Clock) */

#define DEVICE_ID                   0x00

#define PS2CMD_RESET                0xFF
#define PS2CMD_RESEND               0xFE
#define PS2CMD_SET_DEFAULTS         0xF6
#define PS2CMD_DISABLE_DATA_REPORT  0xF5
#define PS2CMD_ENABLE_DATA_REPORT   0xF4
#define PS2CMD_SET_SAMPLE_RATE      0xF3
#define PS2CMD_GET_DEVICE_ID        0xF2
#define PS2CMD_SET_REMOTE_MODE      0xF0
#define PS2CMD_SET_WARP_MODE        0xEE
#define PS2CMD_RESET_WARP_MODE      0xEC
#define PS2CMD_READ_DATA            0xEB
#define PS2CMD_SET_STREAM_MODE      0xEA
#define PS2CMD_STATUS_REQUEST       0xE9
#define PS2CMD_SET_RESOLUTION       0xE8
#define PS2CMD_SET_SCALLING2        0xE7
#define PS2CMD_SET_SCALLING1        0xE6

#define PS2ACK          0xFA
#define PS2PASS         0xAA

#define PS2MOD_RESET    0x0
#define PS2MOD_STREAM   0x1
#define PS2MOD_REMOTE   0x2
#define PS2MOD_WARP     0x3

#define DBG_PRINTF printf
void SYS_Init(void);
void UART0_Init(void);
void PS2_Init(void);

uint8_t g_opMode = PS2MOD_RESET;
uint8_t g_sampleRate = 0;
uint8_t g_resolution = 0;
uint8_t g_scalling = 0;
uint8_t g_dataReportEnable = 0;
uint32_t g_mouseData = 0;
uint8_t g_cmd[2] = {0};

uint32_t g_cnt = 0;
void SysTick_Handler(void)
{
	/* Set TX data fifo depth 3byts */
	_PS2_SET_TX_FIFO_DEPTH(3);

    if(g_opMode == PS2MOD_STREAM && g_dataReportEnable)
    {
		if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
        {
            /* PS2 mouse a packet is 3 bytes */
			_PS2_SET_TX_FIFO_DEPTH(3);

		    /* Calcuate cursor moving data */
			g_cnt++;
            if(g_cnt < 101)
                g_mouseData = (0x0 << 16) | (0x01 << 8) | 0x08;  // move right */
            else if(g_cnt < 201)
                g_mouseData = (0xFF << 16) | (0x00 << 8) | 0x28; // move down */
            else if(g_cnt < 301)
                g_mouseData = (0x0 << 16) | (0xFF << 8) | 0x18;  // move left */
            else if(g_cnt < 401)
                g_mouseData = (0x1 << 16) | (0x00 << 8) | 0x08;  // move up */
			else if(g_cnt >401)
                g_cnt = 1;

			/* Transmit data*/
			_PS2_WRITE_TX_DATA0(g_mouseData);

            if((g_cnt & 0x0F) == 0)
			{
            	DBG_PRINTF("Device->Host: Data report 0x%06x\n", g_mouseData);
			}
        }
    }
}

void PS2_IRQHandler(void)
{
    uint32_t rxData;

    /* RXINT */
	if(_PS2_GET_RX_INT_FLAG())
    {
		/* Clear PS2 Receive Interrupt flag */
		_PS2_CLEAR_RX_INT_FLAG();

		/* Get Receive Data */
		rxData=_PS2_GET_RX_DATA();

        if(g_cmd[0])
        {
            /* If g_cmd[0] is not 0, it should be in data phase */
            if(g_cmd[0] == PS2CMD_SET_SAMPLE_RATE)
            {
                DBG_PRINTF("Host->Device: Set sample rate data %d\n", rxData);

                if(rxData < 10)	 rxData = 10;
                if(rxData > 200) rxData = 200;
                g_sampleRate = rxData;
                g_cmd[0] = 0;

                /* Wait Tx ready */
				if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                {
                    DBG_PRINTF("Device->Host: ACK\n");

					_PS2_SET_TX_FIFO_DEPTH(1);
					_PS2_WRITE_TX_DATA0(PS2ACK);
                }
                else
                {
 					DBG_PRINTF("Something wrong!! Stop code!\n");

					_PS2_FORCE_CLK_PIN_LO();
					_PS2_FORCE_DATA_PIN_HI();
					_PS2_SOFTWARE_OVERRIDE_ENABLE();
                    while(1);
                }

            }
            else if(g_cmd[0] == PS2CMD_SET_RESOLUTION)
            {
                DBG_PRINTF("Host->Device: Set resolution data %d\n", rxData);

                if(rxData < 1) rxData = 1;
                if(rxData > 3) rxData = 3;
                g_resolution = (1 << rxData);
                g_cmd[0] = 0;

                /* Wait Tx ready */
				if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                {
                    DBG_PRINTF("Device->Host: ACK\n");

					_PS2_SET_TX_FIFO_DEPTH(1);
					_PS2_WRITE_TX_DATA0(PS2ACK);
                }
                else
                {
                    DBG_PRINTF("Something Wrong!! Stop code!\n");

					_PS2_FORCE_CLK_PIN_LO();
					_PS2_FORCE_DATA_PIN_HI();
					_PS2_SOFTWARE_OVERRIDE_ENABLE();
                    while(1);
                }
            }
        }
        else
        {
            /* Only support PS2CMD_DISABLE_DATA_REPORT command when data report enabled */
            if((rxData == PS2CMD_DISABLE_DATA_REPORT) || (g_dataReportEnable == 0))
            {
                /* Process the command phase */
                if(rxData == PS2CMD_RESET)
                {
                    DBG_PRINTF("Host->Device: Reset\n");

                    /* Reset command */
                    g_opMode = PS2MOD_RESET;
                    g_cmd[0] = 0;

                   /* Clear FIFO */
				   PS2_CLEAR_TX_FIFO();

                   /* Wait Tx ready */
				   if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                   {
                        DBG_PRINTF("Device->Host: ACK\n");

						_PS2_SET_TX_FIFO_DEPTH(3);
						_PS2_WRITE_TX_DATA0((DEVICE_ID<<16)|(PS2PASS<<8)|PS2ACK);
                   }

                }
                else if(rxData == PS2CMD_SET_SAMPLE_RATE)
                {
                    DBG_PRINTF("Host->Device: Set sample rate\n");

                    /* Set sample rate */
                    g_cmd[0] = PS2CMD_SET_SAMPLE_RATE;

                    /* Wait Tx ready */
				    if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                    {
                        DBG_PRINTF("Device->Host: ACK\n");
						_PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }

                }
                else if(rxData == PS2CMD_GET_DEVICE_ID)
                {
                    DBG_PRINTF("Host->Device: Get device ID\n");

                    g_cmd[0] = 0;

					DBG_PRINTF("(PS2->STATUS).TXEMPTY is (%0x)\n", _PS2_GET_TX_FIFO_EMPTY_FLAG());

				    /* Wait Tx ready */
				    if(PS2->PS2STATUS&PS2_PS2STATUS_TXEMPTY_Msk)
                    {
                        DBG_PRINTF("Device->Host: ACK + Device ID(0x%x)\n", DEVICE_ID);

						_PS2_SET_TX_FIFO_DEPTH(2);
					    _PS2_WRITE_TX_DATA0((DEVICE_ID << 8) | PS2ACK);
                    }
                 }
                else if(rxData == PS2CMD_SET_SCALLING2)
                {
                    DBG_PRINTF("Host->Device: Set scalling 2\n");

                    g_scalling = 2;
                    g_cmd[0] = 0;
                    /* Wait Tx ready */
				    if(PS2->PS2STATUS&PS2_PS2STATUS_TXEMPTY_Msk)
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

						_PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_SCALLING1)
                {
                    DBG_PRINTF("Host->Device: Set scalling 1\n");

                    g_scalling = 1;
                    g_cmd[0] = 0;
                     /* Wait Tx ready */
				    if(PS2->PS2STATUS&PS2_PS2STATUS_TXEMPTY_Msk)
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

						_PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_ENABLE_DATA_REPORT)
                {
                    DBG_PRINTF("Host->Device: Enable data report\n");

                    g_dataReportEnable = 1;
                    g_cmd[0] = 0;

                    /* Set the timer for g_sampleRate */
                    /* The sample rate could be 10 ~ 200 samples/sec */
                    SysTick_Config(SystemFrequency / g_sampleRate);

                    /* Wait Tx ready */
					if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

						_PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_DISABLE_DATA_REPORT)
                {
                    DBG_PRINTF("Host->Device: Disable data report\n");

                    g_dataReportEnable = 0;
                    g_cmd[0] = 0;

                    SysTick->CTRL = 0;

                    /* Wait Tx ready */
				    if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

						_PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_RESOLUTION)
                {
                    DBG_PRINTF("Host->Device: Set resolution\n");

                    g_cmd[0] = PS2CMD_SET_RESOLUTION;

                    /* Wait Tx ready */
					if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

					    _PS2_SET_TX_FIFO_DEPTH(1);
					    _PS2_WRITE_TX_DATA0(PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_STATUS_REQUEST)
                {

                    DBG_PRINTF("Host->Device: PS2CMD_STATUS_REQUEST\n");

                    g_cmd[0] = 0;

                    /* Wait Tx ready */
				    if(_PS2_GET_TX_FIFO_EMPTY_FLAG())
                    {
                        DBG_PRINTF("Device->Host: ACK\n");

					    _PS2_SET_TX_FIFO_DEPTH(4);
					    _PS2_WRITE_TX_DATA0((0x64<<24)|PS2ACK);
                    }
                }
            }
        }
    }

    /* TXINT */
	if(_PS2_GET_TX_INT_FLAG())
    {
		while(_PS2_GET_TX_INT_FLAG())
		{
			_PS2_CLEAR_RX_INT_FLAG();
		}

    }

}

void PS2_Example(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init PS2 device */
    PS2_Init();

	g_cmd[0] = 0;

//    printf("\n\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  PS2 Demo Code Test                                       |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The demo code will show the cursor moving on the       |\n");
    printf("|    screen.                                                |\n");
    printf("+-----------------------------------------------------------+\n");

    while(1)
    {
        if(g_opMode == PS2MOD_RESET)
        {
            /* Reset to default configuration */
            g_sampleRate = 100;
            g_resolution = 4;
            g_scalling = 1;
            g_dataReportEnable = 0;

            /* Do self test ... */

            /* One byte per trnasfer */
			_PS2_SET_TX_FIFO_DEPTH(1);

            /* Report 0xAA for successful self-test or 0xFC for error */

            /* Waiting for transmit */
			while(_PS2_GET_TX_FIFO_EMPTY_FLAG()==0)
			{
			 	printf("B4 PS2PASS CHECK!!\n");
			}

		    _PS2_WRITE_TX_DATA0(PS2PASS);

			 printf("Device->Host: PS2PASS!!\n");


            /* Report device ID */
			while((PS2->PS2STATUS&PS2_PS2STATUS_TXEMPTY_Msk) == 0)
			{
			 	printf("B4 DEVICE_ID CHECK!!\n");
			}

			_PS2_WRITE_TX_DATA0(DEVICE_ID);

			printf("Device->Host: DEVICE_ID!!\n");

            /* Enter Stream mode */
            g_opMode = PS2MOD_STREAM;
        }
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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_PS2_EN_Msk;

    /* Select IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_XTAL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD and TXD  */
    SYS->GPB_MFP = SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB0_RXD0;

	/* Set PF multi-function pins for PS2 PS2DAT and PS2CLK */
	SYS->GPF_MFP = SYS_GPF_MFP_PF2_PS2DAT |	 SYS_GPF_MFP_PF3_PS2CLK;

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

void PS2_Init(void)
{
	/* Reset PS2 device */
	PS2_ResetIP();

	/* Enable PS2 engine clock */
	SYSCLK->APBCLK |= SYSCLK_APBCLK_PS2_EN_Msk;

	/* Enalbe PS2 deveice, enable transmit & receive Interrupt, set transmit data fifo depth*/
	PS2->PS2CON = PS2_PS2CON_PS2EN_Msk | PS2_PS2CON_RXINTEN_Msk | PS2_PS2CON_TXINTEN_Msk & ~PS2_PS2CON_TXFIFO_DEPTH_Msk;

    /* Clear TX FIFO */
	PS2_CLEAR_TX_FIFO();

	/*Enable PS2 of NVIC, and PS2 IRQ*/
	NVIC_SetPriority (PS2_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
	NVIC_EnableIRQ(PS2_IRQn);
}

