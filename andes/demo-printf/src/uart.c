#include "config.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
#include "ag101p.h"
#endif

#define BAUD_RATE(n)		(UCLKFREQ / (n) / 16)

#ifdef CFG_LLINIT
void uart_init(void)
{
	/* mode select (UART) */
	outw(UART_BASE + UART_MDR_OFFSET,
	     inw(UART_BASE + UART_MDR_OFFSET) & ~(0x3));
	/* Set DLAB to 1 */
	outw(UART_BASE + UART_LCR_OFFSET,
	     inw(UART_BASE + UART_LCR_OFFSET) | 0x80);

	/* Set DLL for baudrate */
	outw(UART_BASE + UART_DLL_OFFSET, (BAUD_RATE(38400) >> 0) & 0xff);
	outw(UART_BASE + UART_DLM_OFFSET, (BAUD_RATE(38400) >> 8) & 0xff);

	/* baud 38400 , LCR: Length 8, no parity, 1 stop bit. */
	outw(UART_BASE + UART_LCR_OFFSET, 0x03);
	/* FCR: Enable FIFO, reset TX and RX. */
	outw(UART_BASE + UART_FCR_OFFSET, 0x07);
}
#endif

#define SERIAL_LSR_THRE		0x20

int uart_puts(const char *s)
{
	volatile unsigned *status =
	    (volatile unsigned *)(UART_BASE + UART_LSR_OFFSET);
	int len = 0;
	while (*s) {
		while ((*status & SERIAL_LSR_THRE) == 0) ;

		*(volatile unsigned *)(UART_BASE + UART_THR_OFFSET) = (unsigned)*s;

		if (*s == '\n') {
			while ((*status & SERIAL_LSR_THRE) == 0) ;
			*(volatile unsigned *)(UART_BASE + UART_THR_OFFSET) = '\r';
		}
		s++;
		len++;
	}
	return len;
}
