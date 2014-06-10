#include "config.h"
#include "assert_demos.h"
#include <nds32_intrinsic.h>
#include <stdio.h>

extern int uart_puts(const char *s);

void do_sys_getcmdline(unsigned int cmdbuf_addr)
{
	uart_puts("do_sys_getcmdline()\n");

	char cmdline[] = "Hello Cruel World";
	volatile char *src = cmdline;
	volatile char *dest = (volatile char *) cmdbuf_addr;
	int size = sizeof(cmdline);
	int i;

	for (i = 0; i < size; i++)
		*dest++ = *src++;
}

void syscall_handler(
	unsigned int arg0,
	unsigned int arg1,
	unsigned int arg2,
	unsigned int arg3,
	unsigned int arg4,
	unsigned int arg5)
{
	unsigned swid = 0x7FFF & (__nds32__mfsr(NDS32_SR_ITYPE) >> 16);

	/* Get Cmdline */
	if (swid == 6002) {
		do_sys_getcmdline(arg0);
	} else if (3 == swid) {
		uart_puts("Syscall exit\n");
		while(1)/**/;
	} else {
		uart_puts("Syscall handler\n");
	}
}

#define NOINLINE	__attribute__((noinline))
double f3 = 0;

NOINLINE int geti()
{
	int i;
	i = 100;
	i = i + i;
	return i;		/* i is 200 */
}

NOINLINE int calc2(int a, int b, int c, int d, int e, int f, int g, int h)
{
	int i = geti();
	a = a + b + c + d + e + f + g + h + i;
#if (defined(NDS32_EXT_FPU_DP) || defined(NDS32_EXT_FPU_SP))
	double f1 = 0.22;
	double f2 = 0.8;
	f3 = f1 + f2;
#endif
	return a;		/* a = 1800 */
}

NOINLINE int calc(int a, int b, int c, int d, int e, int f, int g, int h)
{
	int i = geti();
	a = a * 2;
	b = b * 2;
	c = c * 2;
	d = d * 2;
	e = e * 2;
	f = f * 2;
	g = g * 2;
	h = h * 2;
	a = calc2(a, b, c, d, e, f, g, h) + i;
	return a;		/* a = 2000 */
}

volatile int global = 5;
volatile int global_bss;
volatile int a, b, c, d, e, f, g, h;

char *__itoa(int value, char *string, int radix)
{
	char tmp[33];
	char *tp = tmp;
	int i;
	unsigned v;
	int sign;
	char *sp;

	if (radix > 36 || radix <= 1) {
		uart_puts("itoa error ....\n");
		return 0;
	}

	sign = (radix == 10 && value < 0);
	if (sign)
		v = -value;
	else
		v = (unsigned)value;
	while (v || tp == tmp) {
		i = v % radix;
		v = v / radix;
		if (i < 10)
			*tp++ = i + '0';
		else
			*tp++ = i + 'a' - 10;
	}

	sp = string;

	if (sign)
		*sp++ = '-';
	while (tp > tmp)
		*sp++ = *--tp;
	*sp = 0;
	return string;
}

int main(int argc, char *argv[])
{
        int i;
        char buf[0x1000];
        char *ptr;

	if (global != 5) {
		uart_puts("data section copy failed.\n");
		while (1) ;
	}
	uart_puts("data section copy successfully.\n");
	if (global_bss != 0) {
		uart_puts("bss section clear failed.\n");
		while (1) ;
	}
	uart_puts("bss section clean successfully.\n");

        ptr = buf;
        ptr += sprintf(ptr, "argc: %d\n", argc);
        for (i = 0; i < argc; i++) {
            ptr += sprintf(ptr, "argv[%d]: '%s'\n", i, argv[i]);
        }
	uart_puts(buf);

        /* To test if stack works normally.
         * You can comment it if it is not
         * necessary. */
        a= b= c= d= e= f= g= h= 100;
        a = calc(a, b, c, d, e, f, g, h);
        if ((a != 2000)
#if (defined(NDS32_EXT_FPU_DP) || defined(NDS32_EXT_FPU_SP))
                        || (f3 != 1.02)
#endif
           ) {
#if (defined(NDS32_EXT_FPU_DP) || defined(NDS32_EXT_FPU_SP))
                if (f3 != 1.02)
                        uart_puts("\nFPU error!\n");
#endif
                uart_puts("\nSome thing wrong!\n");
                return 1;
        }

        return 0;
}
