#include <nds32_intrinsic.h>
#include "config.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
#include "ag101p.h"
#endif

extern int uart_puts(const char *s);

inline void GIE_ENABLE()
{
	__nds32__setgie_en();
}

inline void GIE_DISABLE()
{
	__nds32__setgie_dis();
	__nds32__dsb();
}

 /* this function generates a s/w interrupt */
void gen_swi()
{
	unsigned int int_pend;

	int_pend = __nds32__mfsr(NDS32_SR_INT_PEND);
	int_pend |= 0x10000;
	__nds32__mtsr(int_pend, NDS32_SR_INT_PEND);
	__nds32__dsb();
}

void enableIntr(unsigned int mask, int edge, int neg)
{
	HAL_INTC_IRQ_CONFIGURE(mask, edge, neg);
	HAL_INTC_IRQ_UNMASK(mask);
}

void enableFiqIntr(unsigned int mask, int edge, int neg)
{
	HAL_INTC_FIQ_CONFIGURE(mask, edge, neg);
	HAL_INTC_FIQ_UNMASK(mask);
}

#define TICK_HZ		1

#ifdef CFG_SIMU
 #define SIMU_FACTOR (8)
#else
 #define SIMU_FACTOR (0)
#endif

#define TIMER1		0
#define TIMER2		1
#define TIMER3		2

void Tmr_TickInit()
{
	/* timer1 will interrupt in every 4 secs */
	unsigned int period = (4 * (PCLKFREQ / TICK_HZ)) >> SIMU_FACTOR;

	/* Initialize all Timers */
	HAL_TIMER_INITIALIZE();

	/* Start Timer1 with interrupt enabled */
	HAL_TIMER_SET_PERIOD(TIMER1, period);
	HAL_TIMER_IRQ_ENABLE(TIMER1, 1);
	HAL_TIMER_START(TIMER1);
}

void intc_reset()
{
	HAL_INTC_IRQ_MASK(0xFFFFFFFF);
	HAL_INTC_IRQ_CLEAR(0xFFFFFFFF);
	HAL_INTC_FIQ_MASK(0xFFFFFFFF);
	HAL_INTC_FIQ_CLEAR(0xFFFFFFFF);
}

void initIntr()
{
	/* Init GPIO */
	HAL_GPIO_INITIALIZE(GPIO_USED_MASK);

	/* Init timer */
	Tmr_TickInit();

	/* Interrupt controller */
	intc_reset();

	/* Timer is edge-trigger and falling-edge */
	enableIntr(IC_TIMER1, 1, 0);
	/* GPIO is level-trigger and active-high */
	enableIntr(IC_GPIO, 0, 0);
}

/* GPIO and Timer hardware interrupt ISR */
void GPIO_ISR(unsigned int num)
{
	/* Unmask interrupt and clear */
	HAL_INTC_IRQ_MASK(1 << num);
	HAL_INTC_IRQ_CLEAR(1 << num);

	uart_puts("* Enter GPIO ISR *\n");
	HAL_GPIO_IRQ_CLR(0xFFFFFFFF);
	GIE_ENABLE();

	/* This service will take 6 secs */
	unsigned int period;
	period = (6 * (PCLKFREQ / TICK_HZ)) >> SIMU_FACTOR;
	HAL_TIMER_SET_PERIOD(TIMER2, period << 1);
	HAL_TIMER_START(TIMER2);
	while (1) {
		unsigned int tm2_cntr;
		HAL_TIMER_READ(TIMER2, &tm2_cntr);
		if (tm2_cntr > period)
			break;
	}
	HAL_TIMER_STOP(TIMER2);

	uart_puts("* End of GPIO ISR it takes 6 secs *\n");

	/* Unmask interrupt */
	GIE_DISABLE();
	HAL_INTC_IRQ_UNMASK(1 << num);
}

void TIMER_ISR(unsigned int num)
{
	/* Unmask interrupt and clear */
	HAL_INTC_IRQ_MASK(1 << num);
	HAL_INTC_IRQ_CLEAR(1 << num);

	uart_puts("* Enter Timer ISR, It comes in every 4 secs. *\n");
	/* Clear HW/Timer1 interrupt status */
	HAL_TIMER_IRQ_CLR(TIMER1);

	uart_puts("* Top-Half of Timer ISR is done. Enable GIE *\n");
	GIE_ENABLE();

	/* This service will take 2 secs */
	unsigned int period;
	period = (2 * (PCLKFREQ / TICK_HZ)) >> SIMU_FACTOR;
	HAL_TIMER_SET_PERIOD(TIMER3, period << 1);
	HAL_TIMER_START(TIMER3);
	while (1) {
		unsigned int tm3_cntr;
		HAL_TIMER_READ(TIMER3, &tm3_cntr);
		if (tm3_cntr > period)
			break;
	}
	HAL_TIMER_STOP(TIMER3);

	uart_puts("* Bottom-Half of Timer ISR is done and it takes 2 secs. Enable it self.*\n");

	/* Unmask interrupt */
	GIE_DISABLE();
	HAL_INTC_IRQ_UNMASK(1 << num);
}
