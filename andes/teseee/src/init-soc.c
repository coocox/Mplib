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

#include "nds32_intrinsic.h"
#include "config.h"
#ifdef CONFIG_AG101P_16MB
#include "ag101_16mb.h"
#else
#include "ag101.h"
#endif

#if BURN
/* This must be a leave function, no child funcion. */
void _nds32_init_mem(void) __attribute__((no_prologue));
void _nds32_init_mem(void) 	//The function is weak (optional)
{
//Example of initializing (DRAM) memory controller for AG101 before first use
	/* Memory bank 0 timing parameter register */
#ifdef CONFIG_AG101P_16MB
	NDS32_REG_WRITE(SMC_BASE + BANK0TPR_OFFSET, 0x000ff3ff);
#else
	NDS32_REG_WRITE(SMC_BASE + BANK0TPR_OFFSET, 0x00151151);
#endif
	/* PMU - PLL/DLL Control Register 0 - Enable DLL */
	NDS32_SET_BITS(PMUC_BASE + PLLDLLCR0_OFFSET, 0x00010000);
#ifdef AG101
	NDS32_SET_BITS(PMUC_BASE + PLLDLLCR0_OFFSET, 0x00e00000);
	NDS32_SET_BITS(PMUC_BASE + MFPSR_OFFSET, 0x00000010);
	NDS32_SET_BITS(PMUC_BASE + SHTCR_OFFSET, 0x0007f000);
#endif
	/* SDRAM controller - set timing parameter */
	NDS32_REG_WRITE(SDRAMC_BASE + PARM1_OFFSET, SDRAMC_PARM1_INIT);
	NDS32_REG_WRITE(SDRAMC_BASE + PARM2_OFFSET, SDRAMC_PARM2_INIT);
	/* SDRAM controller - set config register */
	NDS32_REG_WRITE(SDRAMC_BASE + CONFIG1_OFFSET, SDRAMC_CONFIG1_INIT);
	NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, SDRAMC_CONFIG2_INIT);

	NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0x1c);
	NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, 0x00000004);
	NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0xffffffff);
	NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, 0x00000000);
	NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0xffffffff);

#ifdef REMAP
	/* remap */
	extern char _edata;
	/* relocation, copy ROM code to SDRAM(current is at 0x10000000 in 4GB or 0x800000 in 16MB) */
	NDS32_REG_WRITE(SDRAMC_BASE + 0x10, 0x00001100);
	NDS32_FMEMCPY(ORIG_RAM_BASE, 0x0, &_edata);
	/* Remapping */
	/* Bank Enable, BASE = 0x100 for haddr[31:20] of the AHB address bus. */
	/* External Bank Configuration Registers */
	NDS32_REG_WRITE(SDRAMC_BASE + 0x14, 0x0);
	NDS32_REG_WRITE(SDRAMC_BASE + 0x18, 0x0);
	NDS32_REG_WRITE(SDRAMC_BASE + 0x1c, 0x0);
	/* Bank Enable, BASE = 0x0 for haddr[31:20] of the AHB address bus. */
	NDS32_REG_WRITE(SDRAMC_BASE + 0x10, 0x1000);
	NDS32_SET_BITS(AHBC_BASE + INTC_OFFSET, 0x1);
	__nds32__isb();
#ifdef CONFIG_AG101P_16MB
	/* 
	 * If it is N9 16MB, we need to do this setting.
	 *
	 * $r0 = ($cr0 & 0xff000000) >> 24
	 * if($r0 != 9)
	 *      don't need to do this 2 setting
	 * else
	 *      need to set this AHBC
	 * */
	asm("mfsr	$r0,	$cr0			\n\t");
	asm("srli	$r0,	$r0,	#24		\n\t");
	asm("movi	$r1,	#0x9			\n\t");
	asm("bne	$r0,	$r1,	1f		\n\t");
	NDS32_REG_WRITE(AHBC_BASE + 0x10, 0x80080000);
	NDS32_REG_WRITE(AHBC_BASE + 0x18, 0x000B0000);
	asm("1:					\n\t");
#endif

	/* When writing a 1 to this bit, the base/size configuration
	 * of AHB slaves 4 (ROM) and 6 (SDRAM) will be interchanged. */
#ifdef AG101
	NDS32_REG_WRITE(SMC_BASE + 0x8, 0x10400062);
	NDS32_REG_WRITE(SMC_BASE + 0xc, 0x000ff3ff);
#else
#ifdef CONFIG_AG101P_16MB
	NDS32_REG_WRITE(SMC_BASE, 0x10800052);
#else
	/*64 MB, Memory data width is 32 */
	NDS32_REG_WRITE(SMC_BASE, 0x10400062);
#endif
#endif
#endif
}
#endif

void __soc_init()		//The function is weak (optional)
{
#if BURN
	uart_init();
#endif
}
