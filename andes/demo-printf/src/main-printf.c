#include "config.h"
#include <stdio.h>
#include "assert_demos.h"

int main()
{
	uart_puts("\n\r");
	uart_puts(">>> demo printf: start <<<\n\r");
	uart_puts("if you see all messages in UPPER case, then nds_write() is overridden!\n\r");
	uart_puts("=== demo printf: end ===\n\r");

	while (1) ;
}

/*
 * override putchar
 */
#include "config.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
#include "ag101p.h"
#endif

#include <ctype.h> /* for toupper() */

#undef putchar
inline int putchar(int c)
{
	c = toupper(c);

	/* tx fifo full */
	while ((inw(UART_BASE + UART_LSR_OFFSET) & 0x20) == 0);
	outw(UART_BASE + UART_THR_OFFSET, c);
	return c;
}

void nds_write(const unsigned char *buf, int size)
{
	int    i;
	for (i = 0; i < size; i++)
		putchar(buf[i]);
}
