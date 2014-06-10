/**************************************************************************//**
 * @file     GPIO_Example.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 14/06/4 11:27a $
 * @brief    Main function of this demo is to configure system clock test.
 *
 * @note
 * Copyright (C) 2014 Coocox. All rights reserved.
 *
 ******************************************************************************/

#include<stdio.h>
#include"pac5xxx_driver_system.h"
#include"pac5xxx_driver_gpio.h"
#include"pac5xxx_driver_uart.h"
void SYS_Init(void);
void UART_Init(void);
void Delay(void);

void LED_Toggle(void)
{
	SYS_Init();
	UART_Init();
	pac5xxx_gpio_out_enable_a(1);
	printf("This example show how to use GPIO Port to control LED\t\n");
	while(1)
	{
		pac5xxx_gpio_out_pin_set_a(0);
		Delay();
		pac5xxx_gpio_out_pin_clear_a(0);
		Delay();

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

void Delay(void)
{
	int i=0,count=5000;
	for(i=0;i<50;i++)
	{
		while(count--);
		count=5000;

	}
}

