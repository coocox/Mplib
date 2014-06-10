#include "config.h"
#include "assert_demos.h"
#include <nds32_intrinsic.h>
#include <stdio.h>

inline void GIE_ENABLE();
inline void GIE_DISABLE();
void initIntr();
void gen_swi();
int uart_puts(const char *s);

void syscall_handler()
{
	static int cnt = 0;
	char buf[0x100];

	sprintf(buf, "Syscall handler #%d\n", cnt);
	uart_puts(buf);

	if (++cnt < 5)
		asm("syscall 0x5000\n\t":::"$r0");
}

#define NOINLINE __attribute__((noinline))
double f3 = 0;

NOINLINE int geti()
{
	int i;
	i = 100;
	i = i + i;
	return i;   /* i is 200 */
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
	return a;   /* a = 1800 */
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
	return a;   /* a = 2000 */
}

volatile int global = 5;
volatile int global_bss;
volatile int a, b, c, d, e, f, g, h;

int main()
{
	uart_puts("\nISR in C example\n");

	/* Enable global interrupt */
	GIE_ENABLE();

	if (global !=5) {
		uart_puts("data section copy failed.\n");
		while (1) ;
	}
	uart_puts("data section copy successfully.\n");
	if (global_bss != 0) {
		uart_puts("bss section clear failed.\n");
		while (1) ;
	}
	uart_puts("bss section clean successfully.\n");

	/* This is syscall test.
	 * You can comment it if it is not necessary. */
	/* Generate system call */
	asm("syscall 0x5000":::"$r0");

	/* Initialize interrupt */
	initIntr();

	/* These are software interrupt test.
	 * You can comment it if it is not necessary. */
	/* Generate software interrupt */
#ifndef CFG_EVIC
	gen_swi();
#endif

	while (1) {
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
			GIE_DISABLE();
			while (1) ;
		}
	}
	return 0;
}
