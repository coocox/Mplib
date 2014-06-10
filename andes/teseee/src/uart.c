#include "config.h"
#ifdef CONFIG_AG101P_16MB
#include "ag101_16mb.h"
#else
#include "ag101.h"
#endif

#if BURN
uart_init(void)
{
	/* mode select (UART) */
	outw(UART_BASE + UART_MDR_OFFSET,
	     inw(UART_BASE + UART_MDR_OFFSET) & ~(0x3));
	/* Set DLAB to 1 */
	outw(UART_BASE + UART_LCR_OFFSET,
	     inw(UART_BASE + UART_LCR_OFFSET) | 0x80);
	/* DLL = 0x18 */
	outw(UART_BASE + 0x00, 0x18);
	/* DLM = 0 */
	outw(UART_BASE + 0x04, 0x0);
	/* baud 38400 , LCR: Length 8, no parity, 1 stop bit. */
	outw(UART_BASE + UART_LCR_OFFSET, 0x03);
	/* FCR: Enable FIFO, reset TX and RX. */
	outw(UART_BASE + UART_FCR_OFFSET, 0x07);
}
#endif

void bsp_outbyte(unsigned char c)
{
	/* tx fifo full */
	while (inw(UART_BASE + 0x08) & 0x10) ;
	outw(UART_BASE + 0x00, c);
}

#define SERIAL_THR                     	0x00
#define SERIAL_LSR                      0x14
#define SERIAL_LSR_THRE                 0x20

void puts(const char *s)
{
	volatile unsigned *status =
	    (volatile unsigned *)(UART_BASE + SERIAL_LSR);
	while (*s) {
		while ((*status & SERIAL_LSR_THRE) == 0) ;

		*(volatile unsigned *)(UART_BASE + SERIAL_THR) = (unsigned)*s;

		if (*s == '\n') {
			while ((*status & SERIAL_LSR_THRE) == 0) ;
			*(volatile unsigned *)(UART_BASE + SERIAL_THR) = '\r';
		}
		s++;
	}
}
