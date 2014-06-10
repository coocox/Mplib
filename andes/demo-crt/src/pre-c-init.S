!
! Note: __pre_c_init is in the condition that sp is not initialezed.
!

#include "config.h"
#if defined(CFG_AG102)
#include "ag102.h"
#elif defined(CFG_AE210P)
#include "ae210p.h"
#else
//#include "ag101p.h"
#endif

#ifdef CFG_LLINIT
#ifdef CFG_REMAP
#define LED_VALUE (0x66) //Burn
#else
#define LED_VALUE (0x11) //xIp
#endif
#else
#define LED_VALUE (0x00) //lOad
#endif
	.macro LED x
	//hal_set_led \x
	.endm

	.weak _SDA_BASE_
	.weak _FP_BASE_

	.section .rodata
msg:
	.asciz "\r\n__pre_c_init() is called\r\n"

	.section .text
	.align 2
	.globl __pre_c_init
	.func  __pre_c_init
	.type  __pre_c_init, @function
__pre_c_init:
#ifndef CFG_SIMU
	! light LED
	LED LED_VALUE
#endif

#ifdef CFG_LLINIT
	move $sp, $lp       ! push $lp, as $sp not initialized
	bal _nds32_init_mem ! $lp corrupted (remap within)
	move $lp, $sp       ! pop $lp, trick!

	la  $gp, _SDA_BASE_ ! init GP for small data access
	la  $fp, _FP_BASE_  ! init FP
	la  $sp, _stack     ! init SP
#endif

	pushm $gp, $lp      ! $gp only for 8-byte-align
	bal __init          !

	la $r0, msg
	bal uart_puts

	popm $gp, $lp
	ret5 $lp
	.endfunc

