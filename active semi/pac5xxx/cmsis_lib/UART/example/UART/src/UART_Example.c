/**************************************************************************//**
 * @file     UART_Example.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    Main function of this demo is to test UART transmit and recieve.
 *
 * @note
 * Copyright (C) 2011 Coocox. All rights reserved.
 *
 ******************************************************************************/

#include<stdio.h>
#include<string.h>
#include"pac5xxx_driver_system.h"
#include"pac5xxx_driver_uart.h"




void SYS_Init(void);
void UART_Init(void);
char buf[20];

void UART_Example(void)
{
	int i=0;
	UART_Init();
	SYS_Init();

	printf("\n\rPlease enter your name\n\r");

	while(1)
	{
		if(PAC5XXX_UART->LSR.DR==1)
		{
			buf[i]= pac5xxx_uart_read();
			if(buf[i]=='\r')
			{
				printf("%s\r\n",buf);
				printf("OK\r\n");
				break;
			}
			i++;
		}

	}

}

void SYS_Init(void)
{
	/*Configures the PAC5XXX clock control system*/
	pac5xxx_sys_ccs_config(CCSCTL_CLKIN_CLKREF, CCSCTL_ACLKDIV_DIV1, CCSCTL_HCLKDIV_DIV1);
	pac5xxx_sys_pll_config_100mhz(CCSCTL_HCLKDIV_DIV2, CCSCTL_ACLKDIV_DIV2);

	/* PLL clock as the system clock input for the ACLK and FCLK*/
	pac5xxx_sys_ccs_pll_select();
	/*Enable PLL*/
	pac5xxx_sys_pll_enable(500);

}

void UART_Init(void)
{
	pac5xxx_uart_io_config();
	pac5xxx_uart_config_LCR(UART_BPC_8,UART_STOP_BITS_1,0,UART_PARITY_ODD,0,UART_BRKCTL_NORMAL,UART_DIVLACCESS_FIFO_IER);

	PAC5XXX_UART->DL_L2.VAL=0X1B;
	pac5xxx_uart_config_fractional_divisor(0x21);

	pac5xxx_uart_rx_fifo_threshold_remapped(UARTFCTL_RT_14B);
	pac5xxx_uart_fifo_enable(1);

}


