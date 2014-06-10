##==============================================================================
##
##  crt0.S
##
##  nds32 startup code
##
##==============================================================================
##
## Copyright (c) 1995, 1996, 1997, 1998 Cygnus Solutions
##
## The authors hereby grant permission to use, copy, modify, distribute,
## and license this software and its documentation for any purpose, provided
## that existing copyright notices are retained in all copies and that this
## notice is included verbatim in any distributions. No written agreement,
## license, or royalty fee is required for any of the authorized uses.
## Modifications to this software may be copyrighted by their authors
## and need not follow the licensing terms described here, provided that
## the new terms are clearly indicated on the first page of each file where
## they apply.
##

#include "config.h"
#include "interrupt.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
//#include "ag101p.h"
#endif

##------------------------------------------------------------------------------
	.macro vector name
	.align 2
	j OS_Trap_\name
	.endm

	.macro OS_Trap_Interrupt_HW num
OS_Trap_Interrupt_HW\num:
	push $r0
	li  $r0, \num
	b   common_ISR_wrapper
	.endm

	.macro LED x
	//hal_set_led \x
	.endm

	.section .nds32_init, "ax"
!========================================================================
! Vector table
!========================================================================
	.align 2
exception_vector:
	j _start                    !  (0) Trap Reset
	vector TLB_Fill             !  (1) Trap TLB fill
	vector PTE_Not_Present      !  (2) Trap PTE not present
	vector TLB_Misc             !  (3) Trap TLB misc
	vector TLB_VLPT_Miss        !  (4) Trap TLB VLPT miss
	vector Machine_Error        !  (5) Trap Machine error
	vector Debug_Related        !  (6) Trap Debug related
	vector General_Exception    !  (7) Trap General exception
	vector Syscall              !  (8) Syscall

	/* HW interrupt vector layout */
	//hal_hw_vectors

	.align  2
exception_vector_end:
exception_handler:
	.long tlb_exception_handler
	.long error_exception_handler
	.long syscall_handler
ISR_TABLE:
	.long HW0_ISR
	.long HW1_ISR
	.long HW2_ISR
	.long HW3_ISR
	.long HW4_ISR
	.long HW5_ISR
	.long HW6_ISR
	.long HW7_ISR
	.long HW8_ISR
	.long HW9_ISR
	.long HW10_ISR
	.long HW11_ISR
	.long HW12_ISR
	.long HW13_ISR
	.long HW14_ISR
	.long HW15_ISR
	.long HW16_ISR
	.long HW17_ISR
	.long HW18_ISR
	.long HW19_ISR
	.long HW20_ISR
	.long HW21_ISR
	.long HW22_ISR
	.long HW23_ISR
	.long HW24_ISR
	.long HW25_ISR
	.long HW26_ISR
	.long HW27_ISR
	.long HW28_ISR
	.long HW29_ISR
	.long HW30_ISR
	.long HW31_ISR
/*
 * exception handlers
 */

/*----------------------------------------------------------------------
   Since N903 doesn't have MMU, make them share the common error handler.
----------------------------------------------------------------------*/
OS_Trap_TLB_Fill:
/*
	SAVE_ALL
	li  $r0, #0x1
	b   tlb_exception_handler
*/

OS_Trap_PTE_Not_Present:
/*
	SAVE_ALL
	li  $r0, #0x2
	b   tlb_exception_handler
*/

OS_Trap_TLB_Misc:
/*
	SAVE_ALL
	li  $r0, #0x3
	b   tlb_exception_handler
*/

OS_Trap_TLB_VLPT_Miss:
1:  b   1b
	SAVE_ALL
//	li  $r0, #0x4
	b   tlb_exception_handler

OS_Trap_Machine_Error:
1:  b   1b
	SAVE_ALL
	li  $r0, #0x5
	b   error_exception_handler

OS_Trap_Debug_Related:
1:  b   1b
	SAVE_ALL
	li  $r0, #0x6
	b   error_exception_handler

OS_Trap_General_Exception:
1:  b   1b
	SAVE_ALL
	li  $r0, #0x7
	b   error_exception_handler

OS_Trap_Syscall:
	SYSCALL_SAVE_ALL
	bal syscall_handler
	SYSCALL_RESTORE_ALL
	iret

common_ISR_wrapper:
	SAVE_ALL_HW
	la  $r1, ISR_TABLE
	lw  $r1, [$r1+$r0<<2]
	jral $r1
	RESTORE_ALL_HW
	iret

OS_Trap_Interrupt_UNDEF:
	push $r0
	li  $r0, 0xff
	b   common_ISR_wrapper

	/* Other HW interrupt handlers */
	//hal_hw_ISR

##------------------------------------------------------------------------------
## Startup code

#ifdef CFG_LLINIT
#ifdef CFG_REMAP
#define LED_VALUE (0x66) //Burn
#else
#define LED_VALUE (0x11) //xIp
#endif
#else
#define LED_VALUE (0x00) //lOad
#endif

	.section .text
	.global _start
	.weak _call_exit
	.weak _SDA_BASE_
	.weak _FP_BASE_
	.func _start
	.type _start, @function

	.align 2
_start:
	!************************** Begin of do-not-modify **************************
	! Please don’t modify this code
	! Initialize the registers used by the compiler
#ifndef CONFIG_NO_NDS32_EXT_EX9
	! make sure the instruction before setting ITB
	! will not be optimized with ex9
	.no_ex9_begin           ! disable ex9 generation
#endif

	! Support Relax, Set $gp to _SDA_BASE_
	la  $gp, _SDA_BASE_     ! init GP for small data access

#ifdef CFG_DEBUG
	mfsr $r0, $MSC_CFG

#ifndef CONFIG_NO_NDS32_EXT_EX9
	li  $r1, (1 << 24)      ! EIT
	and $r2, $r0, $r1
1:	beqz $r2, 1b
#endif

#ifdef __NDS32_EXT_IFC__
	li  $r1, (1 << 19)      ! IFC
	and $r2, $r0, $r1
1:	beqz $r2, 1b
#endif

#endif //#ifdef CFG_DEBUG

#ifndef CONFIG_NO_NDS32_EXT_EX9
	! Initialize the table base of EX9 instruction
	la      $r0, _ITB_BASE_ ! init ITB
	mtusr   $r0, $ITB
	.no_ex9_end
#endif
	!*************************** End of do-not-modify ***************************

	la  $fp, _FP_BASE_      ! init FP
	la  $sp, _stack         ! init SP
#ifndef CFG_SIMU
	! light LED
	LED LED_VALUE
#endif
#ifdef CFG_LLINIT
	bal _nds32_init_mem
#endif
	bal __init
	bal main
1:  b   1b

	.size _start, .-_start

	.end
