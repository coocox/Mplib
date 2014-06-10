    
    .macro gie_disable
        setgie.d
        dsb
    .endm

    .macro gie_enable
        setgie.e
        dsb
    .endm

    .macro push_d0d1
#if (defined(NDS32_BASELINE_V2) && defined(NDS32_DX_REGS)) || (!defined(NDS32_BASELINE_V2) && (defined(NDS32_DIV)||defined(NDS32_MAC)))
	mfusr   $r1, $d1.lo
	mfusr   $r2, $d1.hi
	mfusr   $r3, $d0.lo
	mfusr   $r4, $d0.hi
	pushm	$r1, $r4
#endif
    .endm

    .macro pop_d0d1
#if (defined(NDS32_BASELINE_V2) && defined(NDS32_DX_REGS)) || (!defined(NDS32_BASELINE_V2) && (defined(NDS32_DIV)||defined(NDS32_MAC)))
	popm	$r1, $r4
	mtusr   $r1, $d1.lo
	mtusr   $r2, $d1.hi
	mtusr   $r3, $d0.lo
	mtusr   $r4, $d0.hi
#endif
    .endm
    .macro SAVE_FPU_REGS_00
	addi	$sp, $sp, -8
	fsdi.bi	$fd2, [$sp], -8
	fsdi.bi	$fd1, [$sp], -8
	fsdi.bi	$fd0, [$sp], -8
	addi	$sp, $sp, 8
    .endm
    .macro SAVE_FPU_REGS_01
	addi	$sp, $sp, -8
	fsdi.bi	$fd6, [$sp], -8
	fsdi.bi	$fd4, [$sp], -8
	fsdi.bi	$fd2, [$sp], -8
	fsdi.bi	$fd1, [$sp], -8
	fsdi.bi	$fd0, [$sp], -8
	addi	$sp, $sp, 8
    .endm
    .macro SAVE_FPU_REGS_02
	addi	$sp, $sp, -8 
	fsdi.bi	$fd14, [$sp], -8
	fsdi.bi	$fd12, [$sp], -8
	fsdi.bi	$fd10, [$sp], -8
	fsdi.bi	$fd8, [$sp], -8
	fsdi.bi	$fd6, [$sp], -8
	fsdi.bi	$fd4, [$sp], -8
	fsdi.bi	$fd2, [$sp], -8
	fsdi.bi	$fd1, [$sp], -8
	fsdi.bi	$fd0, [$sp], -8
	addi	$sp, $sp, 8
    .endm
    .macro SAVE_FPU_REGS_03
	addi	$sp, $sp, -8
	fsdi.bi	$fd30, [$sp], -8
	fsdi.bi	$fd28, [$sp], -8
	fsdi.bi	$fd26, [$sp], -8
	fsdi.bi	$fd24, [$sp], -8
	fsdi.bi	$fd22, [$sp], -8
	fsdi.bi	$fd20, [$sp], -8
	fsdi.bi	$fd18, [$sp], -8
	fsdi.bi	$fd16, [$sp], -8
	fsdi.bi	$fd14, [$sp], -8
	fsdi.bi	$fd12, [$sp], -8
	fsdi.bi	$fd10, [$sp], -8
	fsdi.bi	$fd8, [$sp], -8
	fsdi.bi	$fd6, [$sp], -8
	fsdi.bi	$fd4, [$sp], -8
	fsdi.bi	$fd2, [$sp], -8
	fsdi.bi	$fd1, [$sp], -8
	fsdi.bi	$fd0, [$sp], -8
	addi	$sp, $sp, 8
    .endm
    .macro push_fpu
#if defined(NDS32_EXT_FPU_CONFIG_0)
        SAVE_FPU_REGS_00
#elif defined(NDS32_EXT_FPU_CONFIG_1)
       	SAVE_FPU_REGS_01
#elif defined(NDS32_EXT_FPU_CONFIG_2)
	SAVE_FPU_REGS_02
#elif defined(NDS32_EXT_FPU_CONFIG_3)
        SAVE_FPU_REGS_03
#else
#endif
    .endm
    .macro RESTORE_FPU_REGS_00
	fldi.bi	$fd0, [$sp], 8
	fldi.bi	$fd1, [$sp], 8
        fldi.bi	$fd2, [$sp], 8
    .endm
    .macro RESTORE_FPU_REGS_01
	fldi.bi	$fd0, [$sp], 8
        fldi.bi	$fd1, [$sp], 8
	fldi.bi	$fd2, [$sp], 8
	fldi.bi	$fd4, [$sp], 8
	fldi.bi	$fd6, [$sp], 8
    .endm
    .macro RESTORE_FPU_REGS_02
	fldi.bi	$fd0, [$sp], 8
	fldi.bi	$fd1, [$sp], 8
        fldi.bi	$fd2, [$sp], 8
	fldi.bi	$fd4, [$sp], 8
	fldi.bi	$fd6, [$sp], 8
	fldi.bi	$fd8, [$sp], 8
	fldi.bi	$fd10, [$sp], 8
	fldi.bi	$fd12, [$sp], 8
	fldi.bi	$fd14, [$sp], 8
    .endm
    .macro RESTORE_FPU_REGS_03
	fldi.bi	$fd0, [$sp], 8
	fldi.bi	$fd1, [$sp], 8
        fldi.bi	$fd2, [$sp], 8
	fldi.bi	$fd4, [$sp], 8
	fldi.bi	$fd6, [$sp], 8
	fldi.bi	$fd8, [$sp], 8
	fldi.bi	$fd10, [$sp], 8
	fldi.bi	$fd12, [$sp], 8
	fldi.bi	$fd14, [$sp], 8
	fldi.bi	$fd16, [$sp], 8
	fldi.bi	$fd18, [$sp], 8
	fldi.bi	$fd20, [$sp], 8
	fldi.bi	$fd22, [$sp], 8
	fldi.bi	$fd24, [$sp], 8
	fldi.bi	$fd26, [$sp], 8
	fldi.bi	$fd28, [$sp], 8
	fldi.bi	$fd30, [$sp], 8
    .endm
    .macro pop_fpu
#if defined(NDS32_EXT_FPU_CONFIG_0)
        RESTORE_FPU_REGS_00
#elif defined(NDS32_EXT_FPU_CONFIG_1)
       	RESTORE_FPU_REGS_01
#elif defined(NDS32_EXT_FPU_CONFIG_2)
	RESTORE_FPU_REGS_02
#elif defined(NDS32_EXT_FPU_CONFIG_3)
        RESTORE_FPU_REGS_03
#else
#endif
    .endm


    .macro  SAVE_ALL
	pushm	$r0, $r5
	pushm	$r15,$r30
	push_d0d1
	mfsr    $r0, $PSW
	mfsr    $r1, $IPC
	mfsr    $r2, $IPSW
	pushm	$r0, $r2
	
	/* Descend interrupt level */
	addi	$r0, $r0, #-2
	mtsr    $r0, $PSW
	dsb

	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	andi	$r1, $sp, #4
	subri   $r1, $r1, #4            ! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
#endif
	push	$r2
	push_fpu
    .endm

    .macro  RESTORE_ALL
	pop_fpu
	lwi	$sp, [$sp]
	popm    $r0, $r2
	mtsr    $r0, $PSW
	dsb
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW
	pop_d0d1
	popm	$r15,$r30
	popm	$r0, $r5
   .endm

   .macro  SYSCALL_SAVE_ALL
	pushm	$r0, $r5
	pushm	$r15,$r30
	push_d0d1
	mfsr    $r0, $PSW
	mfsr    $r1, $IPC
	addi	$r1, $r1, 4
	mfsr    $r2, $IPSW
	pushm	$r0, $r2
	
	/* Descend interrupt level */
	addi	$r0, $r0, #-2
	mtsr    $r0, $PSW
	dsb
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	andi	$r1, $sp, #4
	subri   $r1, $r1, #4            ! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
#endif
	push	$r2
	push_fpu
   .endm

   .macro  SYSCALL_RESTORE_ALL
	pop_fpu
	lwi	$sp, [$sp]
	popm    $r0, $r2
	mtsr    $r0, $PSW
	dsb
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW
	pop_d0d1
	popm	$r15,$r30
	addi	$sp, $sp, 4
	popm	$r1, $r5
   .endm

    .macro  SAVE_ALL_HW0
	pushm	$r0, $r5
	pushm	$r15,$r30
	push_d0d1
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	andi	$r1, $sp, #4
	subri   $r1, $r1, #4            ! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
#else
	/* We need to push 2 $sp to make it 8-byte aligned */
	push	$r2
#endif
	push	$r2
	push_fpu
    .endm

    .macro  RESTORE_ALL_HW0
	pop_fpu
	lwi	$sp, [$sp]
	pop_d0d1
	popm	$r15,$r30
	popm	$r0, $r5
   .endm

    .macro  SAVE_ALL_HW		!should not touch $r0
	/* push caller-saved gpr */
	pushm	$r1, $r5
	pushm	$r15, $r30
	push_d0d1
	
#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* push $INT_MASK */
	mfsr	$r1, $INT_MASK
	push	$r1		!push $INT_MASK

	/* disable low priority and 
	 * enable high priority interrupt */
	ori	$r1, $r1, 0x3f	! r1= {mask[31:6],000000}
	li	$r2, 1
	sll	$r2, $r2, $r0	! 1<<r0
	subri	$r2, $r2, 64	! 64 - (1 << r0)
	sub	$r1, $r1, $r2	! {mask[31:6],000000} - (64- (1<<r0))
	
	mtsr	$r1, $INT_MASK

#endif
	/* push $PSW, $IPC, $IPSW */
	mfsr    $r1, $PSW
	mfsr    $r2, $IPC
	mfsr    $r3, $IPSW
	pushm	$r1, $r3
	
	/* You can use -1 if you want to 
	 * descend interrupt level and enable gie or
	 * you can enable gie when you finish your top
	 * half isr. */
	/* Descend interrupt level */
	addi	$r1, $r1, #-2
	mtsr    $r1, $PSW
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	andi	$r3, $sp, #4
	subri   $r3, $r3, #4            ! bit2==0? 4 : 0
	sub	$sp, $sp, $r3		! bit2==0? (sp-=4) : (sp-=0)
#endif
	push	$r2
	push_fpu
    .endm

    .macro  RESTORE_ALL_HW
	/* pop fpu*/
	pop_fpu
	lwi	$sp, [$sp]

	/* pop $PSW, $IPC, $IPSW*/
	popm	$r0, $r2
	gie_disable
	mtsr    $r0, $PSW
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW

#if !(defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* pop $INT_MASK */
	pop	$r0		! get $INT_MASK
	mtsr	$r0, $INT_MASK	! restore $INT_MASK
#endif
	/* pop d0d1 */
	pop_d0d1

	/* pop gpr */
	popm	$r15,$r30
	popm	$r1, $r5
	pop	$r0
   .endm
