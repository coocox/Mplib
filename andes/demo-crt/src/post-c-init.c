#include "config.h"
#include "assert_demos.h"

int  uart_puts(const char *s);

void __post_c_init(void)
{
	uart_puts("__post_c_init() is called\n");
}
