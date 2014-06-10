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

/* Set the corresponding IRQ source to be routed to HW vector. */
void setIRQ_ivic(unsigned int vector, int hw)
{
	HAL_INTC_HWIRQ_ROUTE(vector, hw);
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

	/* Check IVIC numbers (IVB.NIVIC) */
	if ((__nds32__mfsr(NDS32_SR_IVB) & 0x0E) != 0) {	// 32IVIC
#if (defined(NDS32_BASELINE_V3) || defined(NDS32_BASELINE_V3M))
		/* set TIMER1 priority to low */
#if IRQ_TIMER1 < 16
		__nds32__mtsr(1 << (IRQ_TIMER1 * 2), NDS32_SR_INT_PRI);
#else
		__nds32__mtsr(1 << ((IRQ_TIMER1 - 16) * 2), NDS32_SR_INT_PRI2);
#endif
		/* enable HW# (timer1, GPIO & SWI) */
		__nds32__mtsr(IC_TIMER1 | IC_GPIO | IC_SWI, NDS32_SR_INT_MASK2);
		/* Interrupt pending register, write 1 to clear */
		__nds32__mtsr(0xFFFFFFFF, NDS32_SR_INT_PEND2);
#endif
	} else {
		/* Interrupt controller */
		intc_reset();

		/* IRQ source to be routed to HW0/HW1 */
		setIRQ_ivic(IRQ_TIMER1, 1);
		setIRQ_ivic(IRQ_GPIO, 0);

		/* Timer is edge-trigger and falling-edge */
		enableIntr(IC_TIMER1, 1, 0);
		/* GPIO is level-trigger and active-high */
		enableFiqIntr(IC_GPIO, 0, 0);

		/* enable SW0, HW0 and HW1 */
		__nds32__mtsr(0x10003, NDS32_SR_INT_MASK);
	}
}

void initIntr_standby()
{
	/* Init GPIO */
	HAL_GPIO_INITIALIZE(GPIO_USED_MASK);

	/* Check IVIC numbers (IVB.NIVIC) */
	if ((__nds32__mfsr(NDS32_SR_IVB) & 0x0E) != 0) {	// 32IVIC
#if (defined(NDS32_BASELINE_V3) || defined(NDS32_BASELINE_V3M))
		/* enable HW (GPIO) */
		__nds32__mtsr(IC_GPIO, NDS32_SR_INT_MASK2);
		/* Interrupt pending register, write 1 to clear */
		__nds32__mtsr(0xFFFFFFFF, NDS32_SR_INT_PEND2);
#endif
	} else {
		/* Reset interrupt controller */
		intc_reset();
		/* GPIO source to be routed to HW0 */
                setIRQ_ivic(IRQ_GPIO, 0);
		/* GPIO is level-trigger and active-high */
		enableFiqIntr(IC_GPIO, 0, 0);
		/* enable HW0 */
		__nds32__mtsr(0x0001, NDS32_SR_INT_MASK);
	}
}

void clear_swi()
{
	unsigned int int_pend;

	int_pend = 0x10;
	__nds32__mtsr(int_pend, NDS32_SR_INT_PEND);
	__nds32__dsb();
}

#if (defined(FIQ_ISR) && defined(IRQ_ISR))
/* HW0, HW1 and SW0 interrupts will only occur on IVIC version (IVB.IVIC_VER) = 0. */
void FIQ_ISR()
{
	uart_puts("* Enter HW0 ISR with GPIO *\n");
	HAL_GPIO_IRQ_CLR(0xFFFFFFFF);

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
	uart_puts("* End of HW0 ISR it takes 6 secs *\n");
}

void IRQ_ISR()
{
	uart_puts("* Enter HW1 ISR, It comes in every 4 secs. *\n");
	/* Unmask Timer interrupt and clear */
	HAL_INTC_IRQ_MASK(IC_TIMER1);
	HAL_INTC_IRQ_CLEAR(IC_TIMER1);

	/* Clear Timer1 interrupt status */
	HAL_TIMER_IRQ_CLR(TIMER1);

	uart_puts("* Top-Half of HW1 is done. Enable GIE *\n");
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
	uart_puts("* Bottom-Half of HW1 is done and it takes 2 secs. Enable it self.*\n");

	/* Enable Timer Interrupt */
	HAL_INTC_IRQ_UNMASK(IC_TIMER1);
}
#endif

void SW0_ISR()
{
	uart_puts("A software interrupt occurs ...\n");
	clear_swi();
	return;
}

#if (defined(NDS32_BASELINE_V3) || defined(NDS32_BASELINE_V3M))
/* SW, GPIO and Timer hardware interrupt will only occur on IVIC version (IVB.IVIC_VER) = 1. */
void SWI_ISR(unsigned int num)
{
	__nds32__mtsr((1 << num), NDS32_SR_INT_PEND2);
	SW0_ISR();
}

void GPIO_ISR(unsigned int num)
{
	unsigned int msk = (1 << num);

	/* Mask and clear HW interrupt vector */
	__nds32__mtsr(__nds32__mfsr(NDS32_SR_INT_MASK2) & ~msk, NDS32_SR_INT_MASK2);
	__nds32__dsb();
	__nds32__mtsr(msk, NDS32_SR_INT_PEND2);

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

	/* Unmask HW interrupt vector */
	GIE_DISABLE();
	__nds32__mtsr(__nds32__mfsr(NDS32_SR_INT_MASK2) | msk, NDS32_SR_INT_MASK2);
}

void TIMER_ISR(unsigned int num)
{
	unsigned int msk = (1 << num);

	/* Mask and clear HW interrupt vector */
	__nds32__mtsr(__nds32__mfsr(NDS32_SR_INT_MASK2) & ~msk, NDS32_SR_INT_MASK2);
	__nds32__dsb();
	__nds32__mtsr(msk, NDS32_SR_INT_PEND2);

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

	/* Unmask HW interrupt vector */
	GIE_DISABLE();
        __nds32__mtsr(__nds32__mfsr(NDS32_SR_INT_MASK2) | msk, NDS32_SR_INT_MASK2);
}
#endif
