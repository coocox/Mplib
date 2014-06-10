#include "config.h"
#include "interrupt.h"

	.macro vector name
        .align 2
        j OS_Trap_\name
        .endm

        .section .vector, "ax"
exception_vector:
        .align 2

!========================================================================
! Vector table
!========================================================================
        j _start                          !  (0) Trap Reset
	vector TLB_Fill                   !  (1) Trap TLB fill
        vector PTE_Not_Present            !  (2) Trap PTE not present
        vector TLB_Misc                   !  (3) Trap TLB misc
        vector TLB_VLPT_Miss              !  (4) Trap TLB VLPT miss
        vector Machine_Error              !  (5) Trap Machine error
        vector Debug_Related              !  (6) Trap Debug related
        vector General_Exception          !  (7) Trap General exception
        vector Syscall                    !  (8) Syscall
        vector Interrupt_HW0              !  (9) Interrupt HW0
        vector Interrupt_HW1              ! (10) Interrupt HW1
        vector Interrupt_HW2              ! (11) Interrupt HW2
        vector Interrupt_HW3              ! (12) Interrupt HW3
        vector Interrupt_HW4              ! (13) Interrupt HW4
        vector Interrupt_HW5              ! (14) Interrupt HW5
        vector SWI                        ! (15) Interrupt SW0

exception_vector_end:
exception_handler:
	.align  2
	.long	tlb_exception_handler
	.long	error_exception_handler
	.long	syscall_handler
ISR_TABLE:
	.long	HW0_ISR
	.long	HW1_ISR
	.long	HW2_ISR
	.long	HW3_ISR
	.long	HW4_ISR
	.long	HW5_ISR
/*
 * exception handlers
 */

/*----------------------------------------------------------------------
   Since N903 doesn't have MMU, make them share the common error handler.
----------------------------------------------------------------------*/
OS_Trap_TLB_Fill:
/*
	SAVE_ALL
	li	$r0, #0x1
	b	tlb_exception_handler
*/

OS_Trap_PTE_Not_Present:
/*
	SAVE_ALL
	li	$r0, #0x2
	b	tlb_exception_handler
*/

OS_Trap_TLB_Misc:
/*
	SAVE_ALL
	li	$r0, #0x3
	b	tlb_exception_handler
*/

OS_Trap_TLB_VLPT_Miss:
1:	b	1b
	SAVE_ALL
	/* li	$r0, #0x4*/
	b	tlb_exception_handler

OS_Trap_Machine_Error:
1:	b	1b
	SAVE_ALL
	li	$r0, #0x5
	b	error_exception_handler

OS_Trap_Debug_Related:
1:	b	1b
	SAVE_ALL
	li	$r0, #0x6
	b	error_exception_handler

OS_Trap_General_Exception:
1:	b	1b
	SAVE_ALL
	li	$r0, #0x7
	b	error_exception_handler

OS_Trap_Syscall:
	SYSCALL_SAVE_ALL
	bal	syscall_handler
	SYSCALL_RESTORE_ALL
	iret

OS_Trap_Interrupt_HW0:
	SAVE_ALL_HW0
	li	$r0, 0x0
	la	$r1, HW0_ISR
	jral	$r1
	RESTORE_ALL_HW0
	iret

common_ISR_wrapper:
	SAVE_ALL_HW
	la	$r1, ISR_TABLE
	lw	$r1, [$r1+$r0<<2]
	jral	$r1
	RESTORE_ALL_HW
	iret

OS_Trap_Interrupt_HW1:
	push	$r0
        li	$r0, 0x01
	b	common_ISR_wrapper

OS_Trap_Interrupt_HW2:
	push	$r0
	li	$r0, 0x02
	b	common_ISR_wrapper

OS_Trap_Interrupt_HW3:
	push	$r0
	li	$r0, 0x03
	b	common_ISR_wrapper

OS_Trap_Interrupt_HW4:
	push	$r0
        li	$r0, 0x04
	b	common_ISR_wrapper

OS_Trap_Interrupt_HW5:
	push	$r0
        li	$r0, 0x05
	b	common_ISR_wrapper

OS_Trap_SWI:
	SAVE_ALL
	li	$r0, 0x0f
	la	$r1, SW0_ISR
	jral	$r1
	RESTORE_ALL
	iret
