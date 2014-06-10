#include <stdio.h>
#include <stdlib.h>

extern int uart_puts(const char *s);

void _call_exit(int code)
{
        uart_puts("\n_call_exit is called\n");

        if (code == 0)
                uart_puts("Program terminated normally\n");
        else
                uart_puts("Program terminated abnormally\n");

        fflush(stdout);
        exit(code);
}
