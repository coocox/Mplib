/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    NUC123 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
#include "PS2.h"
#include "UART.h"

#define DBG_PRINT    //printf

uint32_t SystemFrequency  = __XTAL;   /*!< System Clock Frequency (Core Clock) */

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


uint8_t g_opMode = PS2MOD_RESET;
uint8_t g_sampleRate = 0;
uint8_t g_resolution = 0;
uint8_t g_scalling = 0;
uint8_t g_dataReportEnable = 0;
uint32_t g_mouseData = 0;
uint8_t g_cmd[2] = {0};

uint32_t g_cnt = 0;

void SYS_Init(void);
void UART0_Init(void);
void PS2_Init(void);


int PS2_Example(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for DBG_PRINT */
    UART0_Init();

    /* Init PS2 device */
    PS2_Init();

    g_cmd[0] = 0;

    DBG_PRINT("\n\n");
    DBG_PRINT("+-----------------------------------------------------------+\n");
    DBG_PRINT("|  PS2 Demo Code Test                                       |\n");
    DBG_PRINT("+-----------------------------------------------------------+\n");
    DBG_PRINT("|  Description :                                            |\n");
    DBG_PRINT("|    The demo code will show the cursor moving on the       |\n");
    DBG_PRINT("|    screen.                                                |\n");
    DBG_PRINT("+-----------------------------------------------------------+\n");

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
            PS2_SET_TXFIFO_DEPTH(1);

            /* Report 0xAA for successful self-test or 0xFC for error */

            /* Waiting for transmit */
            while(!PS2_IS_TXFIFO_EMPTY())
            {
                DBG_PRINT("B4 PS2PASS CHECK!!\n");
            }
            PS2_SET_PS2TXDATA(0, PS2PASS);

            DBG_PRINT("Device->Host: PS2PASS!!\n");

            /* Report device ID */
            while(!PS2_IS_TXFIFO_EMPTY())
            {
                DBG_PRINT("B4 DEVICE_ID CHECK!!\n");
            }

            PS2_SET_PS2TXDATA(0, DEVICE_ID);

            DBG_PRINT("Device->Host: DEVICE_ID!!\n");

            /* Enter Stream mode */
            g_opMode = PS2MOD_STREAM;
        }
    }
}


void SysTick_Handler(void)
{
    /* Set TX data fifo depth 3byts */
    PS2_SET_TXFIFO_DEPTH(3);

    if(g_opMode == PS2MOD_STREAM && g_dataReportEnable)
    {
        if(PS2_IS_TXFIFO_EMPTY())
        {
            /* PS2 mouse a packet is 3 bytes */
            PS2_SET_TXFIFO_DEPTH(3);

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
            PS2_SET_PS2TXDATA(0, g_mouseData);

            if((g_cnt & 0x0F) == 0)
            {
            	DBG_PRINT("Device->Host: Data report 0x%06x\n", g_mouseData);
            }
        }
    }
}

void PS2_IRQHandler(void)
{
    uint32_t rxData;

    /* RXINT */
    if(PS2_GET_RXINT_STS())
    {
        /* Clear PS2 Receive Interrupt flag */
        PS2_CLR_RXINT_STS();

        /* Get Receive Data */
        rxData = PS2_GET_PS2RXDATA();

        if(g_cmd[0])
        {
            /* If g_cmd[0] is not 0, it should be in data phase */
            if(g_cmd[0] == PS2CMD_SET_SAMPLE_RATE)
            {
                DBG_PRINT("Host->Device: Set sample rate data %d\n", rxData);

                if(rxData < 10)	 rxData = 10;
                if(rxData > 200) rxData = 200;
                g_sampleRate = rxData;
                g_cmd[0] = 0;

                /* Wait Tx ready */
                if(PS2_IS_TXFIFO_EMPTY())
                {
                    DBG_PRINT("Device->Host: ACK\n");

                    PS2_SET_TXFIFO_DEPTH(1);
                    PS2_SET_PS2TXDATA(0, PS2ACK);
                }
                else
                {
                    DBG_PRINT("Something wrong!! Stop code!\n");

                    PS2_FORCE_PS2CLK_LOW();
                    PS2_FORCE_PS2DATA_HIGH();
                    while(1);
                }
            }
            else if(g_cmd[0] == PS2CMD_SET_RESOLUTION)
            {
                DBG_PRINT("Host->Device: Set resolution data %d\n", rxData);

                if(rxData < 1) rxData = 1;
                if(rxData > 3) rxData = 3;
                g_resolution = (1 << rxData);
                g_cmd[0] = 0;

                /* Wait Tx ready */
                if(PS2_IS_TXFIFO_EMPTY())
                {
                    DBG_PRINT("Device->Host: ACK\n");

                    PS2_SET_TXFIFO_DEPTH(1);
                    PS2_SET_PS2TXDATA(0, PS2ACK);
                }
                else
                {
                    DBG_PRINT("Something Wrong!! Stop code!\n");

                    PS2_FORCE_PS2CLK_LOW();
                    PS2_FORCE_PS2DATA_HIGH();
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
                    DBG_PRINT("Host->Device: Reset\n");

                    /* Reset command */
                    g_opMode = PS2MOD_RESET;
                    g_cmd[0] = 0;

                    /* Clear FIFO */
                    PS2_CLR_TXFIFO();

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(3);
                        PS2_SET_PS2TXDATA(0, (DEVICE_ID<<16)|(PS2PASS<<8)|PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_SAMPLE_RATE)
                {
                    DBG_PRINT("Host->Device: Set sample rate\n");

                    /* Set sample rate */
                    g_cmd[0] = PS2CMD_SET_SAMPLE_RATE;

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");
                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_GET_DEVICE_ID)
                {
                    DBG_PRINT("Host->Device: Get device ID\n");

                    g_cmd[0] = 0;

                    DBG_PRINT("(PS2->STATUS).TXEMPTY is (%0x)\n", PS2_IS_TXFIFO_EMPTY());

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK + Device ID(0x%x)\n", DEVICE_ID);

                        PS2_SET_TXFIFO_DEPTH(2);
                        PS2_SET_PS2TXDATA(0, (DEVICE_ID << 8) | PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_SCALLING2)
                {
                    DBG_PRINT("Host->Device: Set scalling 2\n");

                    g_scalling = 2;
                    g_cmd[0] = 0;
                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_SCALLING1)
                {
                    DBG_PRINT("Host->Device: Set scalling 1\n");

                    g_scalling = 1;
                    g_cmd[0] = 0;
                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_ENABLE_DATA_REPORT)
                {
                    DBG_PRINT("Host->Device: Enable data report\n");

                    g_dataReportEnable = 1;
                    g_cmd[0] = 0;

                    /* Set the timer for g_sampleRate */
                    /* The sample rate could be 10 ~ 200 samples/sec */
                    SysTick_Config(SystemFrequency / g_sampleRate);

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_DISABLE_DATA_REPORT)
                {
                    DBG_PRINT("Host->Device: Disable data report\n");

                    g_dataReportEnable = 0;
                    g_cmd[0] = 0;

                    SysTick->CTRL = 0;

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_SET_RESOLUTION)
                {
                    DBG_PRINT("Host->Device: Set resolution\n");

                    g_cmd[0] = PS2CMD_SET_RESOLUTION;

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(1);
                        PS2_SET_PS2TXDATA(0, PS2ACK);
                    }
                }
                else if(rxData == PS2CMD_STATUS_REQUEST)
                {
                    DBG_PRINT("Host->Device: PS2CMD_STATUS_REQUEST\n");

                    g_cmd[0] = 0;

                    /* Wait Tx ready */
                    if(PS2_IS_TXFIFO_EMPTY())
                    {
                        DBG_PRINT("Device->Host: ACK\n");

                        PS2_SET_TXFIFO_DEPTH(4);
                        PS2_SET_PS2TXDATA(0, (0x64<<24)|PS2ACK);
                    }
                }
            }
        }
    }

    /* TXINT */
    if(PS2_GET_TXINT_STS())
    {
        while(PS2_GET_TXINT_STS())
        {
            PS2_CLR_TXINT_STS();
        }
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
    GPIO_PS2(); //En:Set PF multi-function pins for PS2 PS2DAT and PS2CLK

    SYS_LockReg();                                          //En:Lock protected registers
}

/**
 * @brief       PS2 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 init function
 */
void PS2_Init(void)
{
    SYS_RESET_IP2(SYS_RST_PS2);                  //En:Reset PS2 IP
    APBCLK_ENABLE(CLK_PS2);                                //En:Enable PS2 clock

    PS2_ENABLE();     //En:Enable PS2
    PS2_SET_TXFIFO_DEPTH(1); //En:Set TX FIFO depth
    PS2_CLR_TXFIFO(); //En:Clear TX FIFO

    PS2_RXINT_ENABLE(); //En:Enable PS2 RX interrupt
    PS2_TXINT_ENABLE(); //En:Enable PS2 TX interrupt
    NVIC_SetPriority (PS2_IRQn, (1<<__NVIC_PRIO_BITS) - 1); //En:Set PS2_IRQn priority
    NVIC_EnableIRQ(PS2_IRQn); //En:Enable NVIC PS2_IRQn
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

