#include <nds32_intrinsic.h>
#include "config.h"
#include "assert_demos.h"

/* It will use Default_Handler if you don't have one */
#pragma weak tlb_exception_handler   = Default_Handler
#pragma weak error_exception_handler = Default_Handler
#pragma weak syscall_handler         = Default_Handler
#pragma weak HW0_ISR   = Default_Handler
#pragma weak HW1_ISR   = Default_Handler
#pragma weak HW2_ISR   = Default_Handler
#pragma weak HW3_ISR   = Default_Handler
#pragma weak HW4_ISR   = Default_Handler
#pragma weak HW5_ISR   = Default_Handler
#pragma weak HW6_ISR   = Default_Handler
#pragma weak HW7_ISR   = Default_Handler
#pragma weak HW8_ISR   = Default_Handler
#pragma weak HW9_ISR   = Default_Handler
#pragma weak HW10_ISR  = Default_Handler
#pragma weak HW11_ISR  = Default_Handler
#pragma weak HW12_ISR  = Default_Handler
#pragma weak HW13_ISR  = Default_Handler
#pragma weak HW14_ISR  = Default_Handler
#pragma weak HW15_ISR  = Default_Handler
#pragma weak HW16_ISR  = Default_Handler
#pragma weak HW17_ISR  = Default_Handler
#pragma weak HW18_ISR  = Default_Handler
#pragma weak HW19_ISR  = Default_Handler
#pragma weak HW20_ISR  = Default_Handler
#pragma weak HW21_ISR  = Default_Handler
#pragma weak HW22_ISR  = Default_Handler
#pragma weak HW23_ISR  = Default_Handler
#pragma weak HW24_ISR  = Default_Handler
#pragma weak HW25_ISR  = Default_Handler
#pragma weak HW26_ISR  = Default_Handler
#pragma weak HW27_ISR  = Default_Handler
#pragma weak HW28_ISR  = Default_Handler
#pragma weak HW29_ISR  = Default_Handler
#pragma weak HW30_ISR  = Default_Handler
#pragma weak HW31_ISR  = Default_Handler
#pragma weak SW0_ISR   = Default_Handler
#pragma weak VEP0_ISR  = Default_Handler
#pragma weak VEP1_ISR  = Default_Handler
#pragma weak VEP2_ISR  = Default_Handler
#pragma weak VEP3_ISR  = Default_Handler
#pragma weak VEP4_ISR  = Default_Handler
#pragma weak VEP5_ISR  = Default_Handler
#pragma weak VEP6_ISR  = Default_Handler
#pragma weak VEP7_ISR  = Default_Handler
#pragma weak VEP8_ISR  = Default_Handler
#pragma weak VEP9_ISR  = Default_Handler
#pragma weak VEP10_ISR = Default_Handler
#pragma weak VEP11_ISR = Default_Handler
#pragma weak VEP12_ISR = Default_Handler
#pragma weak VEP13_ISR = Default_Handler
#pragma weak VEP14_ISR = Default_Handler
#pragma weak VEP15_ISR = Default_Handler
#pragma weak VEP16_ISR = Default_Handler
#pragma weak VEP17_ISR = Default_Handler
#pragma weak VEP18_ISR = Default_Handler
#pragma weak VEP19_ISR = Default_Handler
#pragma weak VEP20_ISR = Default_Handler
#pragma weak VEP21_ISR = Default_Handler
#pragma weak VEP22_ISR = Default_Handler
#pragma weak VEP23_ISR = Default_Handler
#pragma weak VEP24_ISR = Default_Handler
#pragma weak VEP25_ISR = Default_Handler
#pragma weak VEP26_ISR = Default_Handler
#pragma weak VEP27_ISR = Default_Handler
#pragma weak VEP28_ISR = Default_Handler
#pragma weak VEP29_ISR = Default_Handler
#pragma weak VEP30_ISR = Default_Handler
#pragma weak VEP31_ISR = Default_Handler
#pragma weak VEP32_ISR = Default_Handler
#pragma weak VEP33_ISR = Default_Handler
#pragma weak VEP34_ISR = Default_Handler
#pragma weak VEP35_ISR = Default_Handler
#pragma weak VEP36_ISR = Default_Handler
#pragma weak VEP37_ISR = Default_Handler
#pragma weak VEP38_ISR = Default_Handler
#pragma weak VEP39_ISR = Default_Handler
#pragma weak VEP40_ISR = Default_Handler
#pragma weak VEP41_ISR = Default_Handler
#pragma weak VEP42_ISR = Default_Handler
#pragma weak VEP43_ISR = Default_Handler
#pragma weak VEP44_ISR = Default_Handler
#pragma weak VEP45_ISR = Default_Handler
#pragma weak VEP46_ISR = Default_Handler
#pragma weak VEP47_ISR = Default_Handler
#pragma weak VEP48_ISR = Default_Handler
#pragma weak VEP49_ISR = Default_Handler
#pragma weak VEP50_ISR = Default_Handler
#pragma weak VEP51_ISR = Default_Handler
#pragma weak VEP52_ISR = Default_Handler
#pragma weak VEP53_ISR = Default_Handler
#pragma weak VEP54_ISR = Default_Handler
#pragma weak VEP55_ISR = Default_Handler
#pragma weak VEP56_ISR = Default_Handler
#pragma weak VEP57_ISR = Default_Handler
#pragma weak VEP58_ISR = Default_Handler
#pragma weak VEP59_ISR = Default_Handler
#pragma weak VEP60_ISR = Default_Handler
#pragma weak VEP61_ISR = Default_Handler
#pragma weak VEP62_ISR = Default_Handler
#pragma weak VEP63_ISR = Default_Handler

int uart_puts(const char *);

__attribute__((unused))
static void Default_Handler()
{
	uart_puts("Default Handler");
	while (1) ;
}

#pragma weak __soc_init = __null_function

void __null_function()
{;
}

void __c_init()
{
/* Use compiler builtin memcpy and memset */
#define MEMCPY(des, src, n) __builtin_memcpy ((des), (src), (n))
#define MEMSET(s, c, n) __builtin_memset ((s), (c), (n))

	extern char _end;
	extern char __bss_start;
	int size;

	/* If we load code to RAM we don't need to copy
	 * data section and lma will be equal to vma.
	 * */
#if defined(CFG_LLINIT) && !defined(CFG_REMAP) && !defined(CFG_SIMU)
	/* data section will be copied before we remap.
	 * We don't need to copy data section here. */
	extern char __data_lmastart;
	extern char __data_start;
	extern char _edata;
	/* Copy data section to RAM */
	size = &_edata - &__data_start;
	MEMCPY(&__data_start, &__data_lmastart, size);
#endif
	/* Clear bss section */
	size = &_end - &__bss_start;
	MEMSET(&__bss_start, 0, size);
	return;
}

void __attribute__ ((optimize("Os"))) __cpu_init()
{
	unsigned int tmp;

	/* turn on BTB */
	tmp = 0x0;
	__nds32__mtsr(tmp, NDS32_SR_MISC_CTL);

	/* disable all hardware interrupts */
	__nds32__mtsr(0x0, NDS32_SR_INT_MASK);
#if (defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	if (__nds32__mfsr(NDS32_SR_IVB) & 0x01)
		__nds32__mtsr(0x0, NDS32_SR_INT_MASK);
#endif

#if defined(CFG_EVIC)
	/* set EVIC, vector size: 4 bytes, base: 0x0 */
	__nds32__mtsr(0x1<<13, NDS32_SR_IVB);
#else
# if defined(USE_C_EXT)
	/* If we use v3/v3m toolchain and want to use
	 * C extension please use USE_C_EXT in CFLAGS
	 */
#ifdef NDS32_BASELINE_V3
	/* set IVIC, vector size: 4 bytes, base: 0x0 */
	__nds32__mtsr(0x0, NDS32_SR_IVB);
#else
	/* set IVIC, vector size: 16 bytes, base: 0x0 */
	__nds32__mtsr(0x1<<14, NDS32_SR_IVB);
#endif
# else
	/* set IVIC, vector size: 4 bytes, base: 0x0
	 * If we use v3/v3m toolchain and want to use
	 * assembly version please don't use USE_C_EXT
	 * in CFLAGS */
	__nds32__mtsr(0x0, NDS32_SR_IVB);
# endif
#endif
	/* Set PSW INTL to 0 */
	tmp = __nds32__mfsr(NDS32_SR_PSW);
	tmp = tmp & 0xfffffff9;
#if (defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* Set PSW CPL to 7 to allow any priority */
	tmp = tmp | 0x70008;
#endif
	__nds32__mtsr(tmp, NDS32_SR_PSW);
	__nds32__dsb();
#if (defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* Check interrupt priority programmable*
	* IVB.PROG_PRI_LVL
	*      0: Fixed priority       -- no exist ir18 1r19
	*      1: Programmable priority
	*/
	if (__nds32__mfsr(NDS32_SR_IVB) & 0x01) {
		/* Set PPL2FIX_EN to 0 to enable Programmable
	 	* Priority Level */
		__nds32__mtsr(0x0, NDS32_SR_INT_CTRL);
		/* Check IVIC numbers (IVB.NIVIC) */
		if ((__nds32__mfsr(NDS32_SR_IVB) & 0x0E)>>1 == 5) {        // 32IVIC
			/* set priority HW9: 0, HW13: 1, HW19: 2,
			* HW#-: 0 */
			__nds32__mtsr(0x04000000, NDS32_SR_INT_PRI);
			__nds32__mtsr(0x00000080, NDS32_SR_INT_PRI2);
		} else {
			/* set priority HW0: 0, HW1: 1, HW2: 2, HW3: 3
			* HW4-: 0 */
			__nds32__mtsr(0x000000e4, NDS32_SR_INT_PRI);
		}
	}
#endif
	/* enable FPU if the CPU support FPU */
#if defined(NDS32_EXT_FPU_DP) || defined(NDS32_EXT_FPU_SP)
	tmp = __nds32__mfsr(NDS32_SR_FUCOP_EXIST);
	if ((tmp & 0x80000001) == 0x80000001) {
		tmp = __nds32__mfsr(NDS32_SR_FUCOP_CTL);
		__nds32__mtsr((tmp | 0x1), NDS32_SR_FUCOP_CTL);
	}
#endif
	return;
}

void __soc_init();

void __init()
{
/*----------------------------------------------------------
   !!  Users should NOT add any code before this comment  !!
------------------------------------------------------------*/
	__cpu_init();
	__c_init();     //copy data section, clean bss

	__soc_init();
}
