/*
	This file includes weak (i.e. optional) functions to perform SoC related
	initialization. They are:
	1). _nds32_init_mem():
		Executed before C language initialization to make memory
		ready so that program data can be initialized. An example
		is to initialize DRAM.
		Since this is called before C initialization, please
		use provided macros to avoid problems.
	2). __soc_init():
		Further SoC intialization. Called after C language
		initialization, so it is a typical C function.
*/

#include <nds32_intrinsic.h>
#include "config.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
#include "ag101p.h"
#endif

#ifdef CFG_LLINIT
/* This must be a leave function, no child funcion. */
void _nds32_init_mem(void) __attribute__((no_prologue, optimize("Os")));
void _nds32_init_mem(void) //The function is weak (optional)
{
#ifndef CFG_NORAM
	HAL_MEMORY_SETUP(ORIG_RAM_BASE);
#ifdef CFG_REMAP
	/* remap */
        extern char _edata;
        /* relocation, copy ROM code to SDRAM */
        NDS32_FMEMCPY(ORIG_RAM_BASE, 0x0, &_edata);

	HAL_MEMORY_REMAP();
	__nds32__isb();

	HAL_MEMORY_REMAP_ADJUST();
#endif	// CFG_REMAP
#else
#if !defined(CFG_REMAP) && !defined(CFG_SIMU)
	/* System without RAM. Use data local memory as system memory. */
        extern char __data_start;
        register unsigned int dlmsize;

        dlmsize = 0x1000 << ((__nds32__mfsr(NDS32_SR_DLMB) >> 1) & 0xf);

        /* Set DLM base to .data start address and enable it */
        __nds32__mtsr((unsigned)&__data_start|1, NDS32_SR_DLMB);
        __nds32__dsb();

        /* Update stack pointer to end of DLM
         * We suppose the .data + .bss + stack less then DLM size */
        __nds32__set_current_sp((unsigned)&__data_start + dlmsize);
#endif
#endif
}
#endif

void __soc_init() //The function is weak (optional)
{
#ifdef CFG_LLINIT
	void uart_init(void);
	uart_init();
#endif
}

