#include <nds32_intrinsic.h>
#include "config.h"
#ifdef CONFIG_AG101P_16MB
#include "ag101_16mb.h"
#else
#include "ag101.h"
#endif

inline void GIE_ENABLE()
{
	__nds32__setgie_en();
	__nds32__dsb();
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
	if (edge)
		outw(INTC_BASE + IRQTMR_OFFSET, inw(INTC_BASE + IRQTMR_OFFSET) | mask);	//Trigger Mode , edge
	else
		outw(INTC_BASE + IRQTMR_OFFSET, inw(INTC_BASE + IRQTMR_OFFSET) & ~mask);	//Trigger Mode, level

	if (neg)
		outw(INTC_BASE + IRQTLR_OFFSET, inw(INTC_BASE + IRQTLR_OFFSET) | mask);	//Trigger Level, active high
	else
		outw(INTC_BASE + IRQTLR_OFFSET, inw(INTC_BASE + IRQTLR_OFFSET) & ~mask);	//Trigger Level, active low

	outw(INTC_BASE + IRQER_OFFSET, inw(INTC_BASE + IRQER_OFFSET) | mask);	//Enable Register 

}

void enableFiqIntr(unsigned int mask, int edge, int neg)
{
	if (edge)
		outw(INTC_BASE + FIQTMR_OFFSET, inw(INTC_BASE + FIQTMR_OFFSET) | mask);	//Trigger Mode , edge
	else
		outw(INTC_BASE + FIQTMR_OFFSET, inw(INTC_BASE + FIQTMR_OFFSET) & ~mask);	//Trigger Mode, level

	if (neg)
		outw(INTC_BASE + FIQTLR_OFFSET, inw(INTC_BASE + FIQTLR_OFFSET) | mask);	//Trigger Level, active high
	else
		outw(INTC_BASE + FIQTLR_OFFSET, inw(INTC_BASE + FIQTLR_OFFSET) & ~mask);	//Trigger Level, active low

	outw(INTC_BASE + FIQER_OFFSET, inw(INTC_BASE + FIQER_OFFSET) | mask);	//Enable Register

}

#define MHz 1000000
#define TICK_HZ	1
#ifdef CONFIG_AG101P_16MB
#define MB_PCLK (40 * MHz)
#else
#define MB_PCLK (20 * MHz)
#endif

void Tmr_TickInit()
{
	/* timer1 will interrupt in every 4 secs */
	unsigned int period;
	period = 4 * (MB_PCLK / TICK_HZ);
	outw(TM1_LOAD, period);
	outw(TM1_CNTR, period);
	outw(TM1_MTCH1, 0);
	outw(TM_MSK, (TM_STA_TM1M1));
	outw(TM_CR, (TM_CR_TM1ENA | TM_CR_TM1OEN));
}

void intc_reset()
{
	/* HW1(+0x4)Enable Regiter, interrupt disabled */
	outw(INTC_BASE + IRQER_OFFSET, INT_ER_INIT);
	/* HW1(+0x8)Interrupt Clear Register, write 1 to clear */
	outw(INTC_BASE + IRQICR_OFFSET, INT_CLEAR_VALUE);

	/* HW0(+0x24)Enable Regiter, interrupt disabled */
	outw(INTC_BASE + FIQER_OFFSET, INT_ER_INIT);
	/* HW0(+0x28)Interrupt Clear Register, write 1 to clear */
	outw(INTC_BASE + FIQICR_OFFSET, INT_CLEAR_VALUE);
}

void initIntr()
{
	/* enable SW0, HW0 and HW1 */
	__nds32__mtsr(0x10003, NDS32_SR_INT_MASK);
	intc_reset();

	/* Init GPIO */
	outw(GPIO_BASE + GPIO_IR_OFFSET, 0xFFFFFFFF);
	outw(GPIO_BASE + GPIO_IE_OFFSET, 0xFFFFFFFF);

	/* Init timer */
	Tmr_TickInit();

	/* Timer is edge-trigger and falling-edge */
	enableIntr(IC_TIMER1, 1, 0);
	/* GPIO is level-trigger and active-high */
	enableFiqIntr(IC_GPIO, 0, 0);
}

void initIntr_standby()
{
	/* enable HW1 */
	__nds32__mtsr(0x0002, NDS32_SR_INT_MASK);
	intc_reset();
	/* Init GPIO */
	outw(GPIO_BASE + GPIO_IR_OFFSET, 0xFFFFFFFF);
	outw(GPIO_BASE + GPIO_IE_OFFSET, 0xFFFFFFFF);
	/* GPIO is level-trigger and active-high */
	enableFiqIntr(IC_GPIO, 0, 0);
}

void clear_swi()
{
	unsigned int int_pend;

	int_pend = 0x10;
	__nds32__mtsr(int_pend, NDS32_SR_INT_PEND);
	__nds32__dsb();
}

/* User can use our handler or Default_Handler */
#if 0
void exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	puts("exception handler\n");
	while (1) ;
}

void tlb_exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	puts("tlb exception handler\n");
	while (1) ;
}

void error_exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	puts("error exception handler\n");
	while (1) ;
}
#endif

void syscall_handler()
{
	static int cnt = 0;

	if (++cnt < 5)
		asm("syscall 0x5000\n\t");

	puts("Syscall handler\n");
}

void HW0_ISR()
{
	puts("* Enter HW0 ISR with GPIO *\n");
	outw(GPIO_BASE + GPIO_IC_OFFSET, 0xFFFFFFFF);

	/* This service will take 6 secs */
	unsigned int period;
	period = 6 * (MB_PCLK / TICK_HZ);
	outw(TM2_LOAD, period);
	outw(TM2_CNTR, 0);
	outw(TM_CR, (inw(TM_CR) | TM_CR_TM2ENA | TM_CR_TM2UP));
	while (1) {
		unsigned int tm2_cntr = inw(TM2_CNTR);
		if (tm2_cntr > period)
			break;
	}
	puts("* End of HW0 ISR it takes 6 secs *\n");
}

void HW1_ISR()
{
	puts("* Enter HW1 ISR, It comes in every 4 secs. *\n");
	/* Clear interrupt status */
	outw(INTC_BASE + IRQICR_OFFSET, IC_TIMER1);
	outw(TM_STA, 0);
	puts("* Top-Half of HW1 is done. Enable GIE *\n");
	GIE_ENABLE();
	/* This service will take 2 secs */
	unsigned int period;
	period = 2 * (MB_PCLK / TICK_HZ);
	outw(TM3_LOAD, period);
	outw(TM3_CNTR, 0);
	outw(TM_CR, (inw(TM_CR) | TM_CR_TM3ENA | TM_CR_TM3UP));
	while (1) {
		unsigned int tm3_cntr = inw(TM3_CNTR);
		if (tm3_cntr > period)
			break;
	}
	puts("* Bottom-Half of HW1 is done and it takes 2 secs. Enable it self.*\n");
}

void SW0_ISR()
{
	puts("A software interrupt occurs ...\n");
	clear_swi();
	return;
}

#if 0
void SYSirq_Disable_Interrupts_Save_Flags(unsigned int *flags)
{
	unsigned int tmp_flags;

	*flags = __nds32__mfsr(NDS32_SR_PSW) & 0x1;
	__nds32__setgie_dis();
	__nds32__dsb();
}

void SYSirq_Enable_Interrupts_Save_Flags(unsigned int *flags)
{
	unsigned int tmp_flags;

	*flags = __nds32__mfsr(NDS32_SR_PSW) & 0x1;
	__nds32__setgie_en();
	__nds32__dsb();
}

void SYSirq_Interrupts_Restore_Flags(unsigned int flags)
{
	unsigned int tmp;

	tmp = __nds32__mfsr(NDS32_SR_PSW);
	tmp = __nds32__bclr(tmp, 0) | flags;
	__nds32__mtsr(tmp, NDS32_SR_PSW);
	__nds32__dsb();
}
#endif
