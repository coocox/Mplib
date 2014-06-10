#define DEMO_CACHE

#include "config.h"
#include "assert_demos.h"
#include <nds32_intrinsic.h>

volatile unsigned int g_original = 0, g_selfmodify = 0;
unsigned int iset, iway, isize;
unsigned int dset, dway, dsize;

unsigned int lp;

#define NDS32_PERFCTL_EN0   (1UL << 0)
#define NDS32_PERFCTL_EN1   (1UL << 1)
#define NDS32_PERFCTL_EN2   (1UL << 2)
#define NDS32_PERFCTL_IE0   (1UL << 3)
#define NDS32_PERFCTL_IE1   (1UL << 4)
#define NDS32_PERFCTL_IE2   (1UL << 5)
#define NDS32_PERFCTL_OVF0  (1UL << 6)
#define NDS32_PERFCTL_OVF1  (1UL << 7)
#define NDS32_PERFCTL_OVF2  (1UL << 8)
#define NDS32_PERFCTL_KS0   (1UL << 9)
#define NDS32_PERFCTL_KS1   (1UL << 10)
#define NDS32_PERFCTL_KS2   (1UL << 11)
#define NDS32_PERFCTL_KU0   (1UL << 12)
#define NDS32_PERFCTL_KU1   (1UL << 13)
#define NDS32_PERFCTL_KU2   (1UL << 14)
#define NDS32_PERFCTL_SEL0_C (0UL << 15)
#define NDS32_PERFCTL_SEL0_I (1UL << 15)
#define NDS32_PERFCTL_SEL1  (0x3f << 16)
#define NDS32_PERFCTL_SEL2  (0x3f << 22)

#define NDS32_ISET          (0x07 << 0)
#define NDS32_IWAY          (0x07 << 3)
#define NDS32_ISIZE         (0x07 << 6)
#define NDS32_DSET          (0x07 << 0)
#define NDS32_DWAY          (0x07 << 3)
#define NDS32_DSIZE         (0x07 << 6)

extern char injectHere;
extern char injectDesEnd;
extern char injectionStart;
extern char injectionEnd;

extern int  uart_puts(const char *s);

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

void initValue(char *pValue, int count)
{
	int i;
	for (i = 0; i < count; i++)
		pValue[i] = '\0';
}

void printS(const char *msg, unsigned int value, int radix)
{
	char str_value[33];
	char *pValue;

	initValue(str_value, 33);
	pValue = __itoa(value, str_value, radix);
	uart_puts(msg);
	uart_puts((const char *)pValue);
	uart_puts("\n");

}

void startPFM()
{
	unsigned int counter0 = 0, counter1 = 0, counter2 = 0;
	unsigned int ctrl = 0, msc_cfg = 0;

	msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
	if (!(msc_cfg & 0x4)) {
		uart_puts("This CPU config doesn't have pfm to use.\n");
		return;
	}
	//Counter0
	__nds32__mtsr(counter0, NDS32_SR_PFMC0);
	__nds32__dsb();

	//Counter1
	__nds32__mtsr(counter1, NDS32_SR_PFMC1);
	__nds32__dsb();

	//Counter2
	__nds32__mtsr(counter2, NDS32_SR_PFMC2);
	__nds32__dsb();

	/* Enable performance counter0 , counter1, counter2 */
	ctrl |= NDS32_PERFCTL_EN0 | NDS32_PERFCTL_EN1 | NDS32_PERFCTL_EN2;
	/* Enable interrupt for counter0, counter1, counter2 */
	ctrl |= NDS32_PERFCTL_IE0 | NDS32_PERFCTL_IE1 | NDS32_PERFCTL_IE2;
	/* Calculate Cycles for counter0 */
	ctrl |= NDS32_PERFCTL_SEL0_C;
	/* Calculate ICache access for counter1 */
	ctrl |= (0x11 << 16);
	/* Calculate DCache access for counter2 */
	ctrl |= (0x14 << 22);

	__nds32__mtsr(ctrl, NDS32_SR_PFM_CTL);

}

void stopPFM()
{
	unsigned int pfm_ctl, msc_cfg = 0;

	msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
	if (!(msc_cfg & 0x4)) {
		uart_puts("This CPU config doesn't have pfm to use.\n");
		return;
	}

	pfm_ctl = __nds32__mfsr(NDS32_SR_PFM_CTL);
	//Disable all counters
	pfm_ctl = pfm_ctl & 0xFFFFFFF8;
	__nds32__mtsr(pfm_ctl, NDS32_SR_PFM_CTL);

}

int enableIDCache()
{

	unsigned int cache_ctl=0, mmu_ctl, icm_cfg, dcm_cfg;

	/* Get ICache ways, sets, line size  */
	icm_cfg = __nds32__mfsr(NDS32_SR_ICM_CFG);
	if ((icm_cfg & NDS32_ISET) < 7)
		iset = 1 << ((icm_cfg & NDS32_ISET) + 6);
	else
		iset = 0;
	printS("The ICache sets = ", iset, 10);

	iway = ((icm_cfg & NDS32_IWAY) >> 3) + 1;
	printS("The ICache ways = ", iway, 10);

	if (((icm_cfg & NDS32_ISIZE) >> 6)
	    && ((icm_cfg & NDS32_ISIZE) >> 6) <= 5)
		isize = 1 << (((icm_cfg & NDS32_ISIZE) >> 6) + 2);
	else if (((icm_cfg & NDS32_ISIZE) >> 6) >= 6) {
		uart_puts("Warning i cacheline size is reserved value\n");
		isize = 0;
	} else
		isize = 0;
	printS("The ICache line size = ", isize, 10);
	if (isize == 0) {
		uart_puts("This CPU doesn't have ICache.\n");
		return 0;	
	}
	else {
		cache_ctl = __nds32__mfsr(NDS32_SR_CACHE_CTL);
		cache_ctl |= 0x1;
		/* Enable I Cache */
		__nds32__mtsr(cache_ctl, NDS32_SR_CACHE_CTL);
	}
	/* Get DCache ways, sets, line size  */
	dcm_cfg = __nds32__mfsr(NDS32_SR_DCM_CFG);
	if ((dcm_cfg & NDS32_DSET) < 7)
		dset = 1 << ((dcm_cfg & NDS32_DSET) + 6);
	else
		dset = 0;
	printS("The DCache sets = ", dset, 10);

	dway = ((dcm_cfg & NDS32_DWAY) >> 3) + 1;
	printS("The DCache ways = ", dway, 10);

	if (((dcm_cfg & NDS32_DSIZE) >> 6)
	    && ((dcm_cfg & NDS32_DSIZE) >> 6) <= 5)
		dsize = 1 << (((dcm_cfg & NDS32_DSIZE) >> 6) + 2);
	else if (((dcm_cfg & NDS32_DSIZE) >> 6) >= 6) {
		uart_puts("Warning d cacheline size is reserved value\n");
		dsize = 0;
	} else
		dsize = 0;
	printS("The DCache line size = ", dsize, 10);
	if (dsize == 0) {
		uart_puts("This CPU doesn't have DCache.\n");
		return 0;	
	}
	else {
		cache_ctl = __nds32__mfsr(NDS32_SR_CACHE_CTL);
		cache_ctl |= 0x2;
		/* Enable D Cache */
		__nds32__mtsr(cache_ctl, NDS32_SR_CACHE_CTL);
	}

	/* Cacheable/Write-Back for NTC0 */
	mmu_ctl = __nds32__mfsr(NDS32_SR_MMU_CTL);
	mmu_ctl |= 0x2 << 1;
	__nds32__mtsr(mmu_ctl, NDS32_SR_MMU_CTL);
	__nds32__isb();
	if (cache_ctl & 0x1)
		uart_puts("Enable I cache\n");
	if (cache_ctl & 0x2)
		uart_puts("Enable D cache\n");
	if (!(cache_ctl & 0x3))
		uart_puts("Can't enable I/D cache\n");
	return 1;
}

void getResults()
{
	unsigned int msc_cfg = 0;
	msc_cfg = __nds32__mfsr(NDS32_SR_MSC_CFG);
	if (!(msc_cfg & 0x4)) {
		uart_puts("This CPU config doesn't have pfm to use.\n");
		return;
	}
	//uart_puts("Reading Performance Monitor Results for Cache.\n");
	unsigned int counter0 = __nds32__mfsr(NDS32_SR_PFMC0);
	unsigned int counter1 = __nds32__mfsr(NDS32_SR_PFMC1);
	unsigned int counter2 = __nds32__mfsr(NDS32_SR_PFMC2);

	//Read cycles count for counter0
	printS("The cycles for counter0 is = 0x", counter0, 16);
	//Read ICache access count for counter1
	printS("The I-Cache access count for counter1 is = 0x", counter1, 16);
	//Read DCache access count for counter2
	printS("The D-Cache access count for counter2 is = 0x", counter2, 16);
}

void cacheOp()
{
	unsigned long iend, icache_line;
	unsigned long dend, dcache_line;

	uart_puts("Calling cacheOp\n");

	/* DCache writeback and invalidate all */
	dcache_line = dsize;
	dend = dcache_line * dway * dset;
	do {
		dend -= dcache_line;
		__nds32__cctlidx_wbinval(NDS32_CCTL_L1D_IX_WB, dend);
		__nds32__cctlidx_wbinval(NDS32_CCTL_L1D_IX_INVAL, dend);
		__nds32__dsb();
	} while (dend > 0);

	/* ICache invalidate all */
	icache_line = isize;
	iend = icache_line * iway * iset;
	do {
		iend -= icache_line;
		__nds32__cctlidx_wbinval(NDS32_CCTL_L1I_IX_INVAL, iend);
		__nds32__dsb();
	} while (iend > 0);

	uart_puts("End of Calling cacheOp\n");
}

void dummyTextContext(void)
{
	asm volatile ("injectionStart:");

	/*  do what you like here but keep it relocatable
	   fire up objdump, gdb or whatever to check what you get */
	g_selfmodify = 7777777;

	/* take the return address and return to main */
	asm volatile ("la $r0, exit_selfModifyCode; jr $r0":::"$r0");
	asm volatile ("injectionEnd:");
}

#if 0 /* old version, drawback: when text on ROM, cache WB would fail. */
int selfModifyCode()
{
	/* save the return address to a global variable lp */
	char *pSrc, *pDes;
	unsigned int size, des_size = 0, i, stop;

	stop = g_original + 2;
	while (stop > g_original) {
		asm volatile ("injectHere:"); /* ground zero */

		/* a few stats to ease debugging (and some code to fill our loop too) */
		uart_puts("Execute original self modify code.\n");
		g_original += 1;
		/* To reserve more space for code to copy and execute */
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		__nds32__nop();
		asm volatile ("injectDesEnd:");

		pDes = (char*)&injectHere;
		pSrc = (char*)&injectionStart;
		size = (unsigned int)&injectionEnd - (unsigned int)&injectionStart;
		printS("The size copied is ", size, 10);
		des_size = (unsigned int)&injectDesEnd - (unsigned int)&injectHere;
		printS("The size of des is ", des_size, 10);
		printS("The g_selfmodify = ", g_selfmodify, 10);
		if (des_size < size) {
			uart_puts("It will overwrite the next context. please reserve more space to copy\n");
			return -1;
		}
		for (i = 0; i < size; i++)
			*pDes++ = *pSrc++;

		/* Call Icache invalidate and Dcache writeback, invalidate */
		cacheOp();
		uart_puts("After calling cacheOp().....\n");
	}

	asm volatile ("exit_selfModifyCode:");
	return 0;
}
#else
int selfModifyCode()
{
	char buf[0x100];
	void (*fun)(void)=(void*)buf;

	/* save the return address to a global variable lp */
	char *pSrc, *pDes;
	unsigned int size, des_size = sizeof(buf), i;

	uart_puts("Execute original self modify code.\n");
	pDes = (char*)&buf;
	pSrc = (char*)&injectionStart;
	size = (unsigned int)&injectionEnd - (unsigned int)&injectionStart;
	printS("The size copied is ", size, 10);
	printS("The g_selfmodify = ", g_selfmodify, 10);
	if (des_size < size) {
		uart_puts("It will overwrite the next context. please reserve more space to copy\n");
		return -1;
	}

	for (i = 0; i < size; i++)
		*pDes++ = *pSrc++;

	/* Call Icache invalidate and Dcache writeback, invalidate */
	cacheOp();
	uart_puts("After calling cacheOp().....\n");

	fun(); /* invoke copied code in buf */

	asm volatile ("exit_selfModifyCode:");
	return 0;
}
#endif

int main()
{
	uart_puts("\nI/D Cache Sample code.\n");

	startPFM();
	if(enableIDCache()){
		selfModifyCode();
		if (g_selfmodify == 7777777)
			uart_puts("selfModifyCode() run successfully.\n");
		else
			uart_puts("We didn't run selfModifyCode().\n");
		stopPFM();
		getResults();
		printS("The g_selfmodify = ", g_selfmodify, 10);
		uart_puts("Completed.\n");
		while (1) ;
	} else
		while (1) ;
}
