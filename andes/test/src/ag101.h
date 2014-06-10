
/* Check to see if this file has been included already.  */

#ifndef         AG101_REGS
#define         AG101_REGS

/* Different memory size defines used by SDRAM initialization */

#define    SDRAM_256MB            0x0100
#define    SDRAM_128MB            0x00C0
#define    SDRAM_64MB             0x0040
#define    SDRAM_32MB             0x0004
#define    SDRAM_16MB             0x0000
#define    ORIG_RAM_BASE	  0x10000000

#define TIMER_BASE             0x98400000  /* Define base for all timer registers */
#define TIMER1_CNT_OFFSET      0x00        /* Offset for timer1 counter register */
#define TIMER1_LOAD_OFFSET     0x04        /* Offset for timer1 load register */
#define TIMER1_MATCH1_OFFSET   0x08        /* Offset for timer1 counter */
#define TIMER1_MATCH2_OFFSET   0x0c        /* Offset for timer1 counter */
#define TIMER2_CNT_OFFSET      0x10        /* Offset for timer2 counter register */
#define TIMER2_LOAD_OFFSET     0x14        /* Offset for timer2 load register */
#define TIMER2_MATCH1_OFFSET   0x18        /* Offset for timer2 counter */
#define TIMER2_MATCH2_OFFSET   0x1c        /* Offset for timer2 counter */
#define TIMER3_CNT_OFFSET      0x20        /* Offset for timer3 counter register */
#define TIMER3_LOAD_OFFSET     0x24        /* Offset for timer3 load register */
#define TIMER3_MATCH1_OFFSET   0x28        /* Offset for timer3 counter */
#define TIMER3_MATCH2_OFFSET   0x2c        /* Offset for timer3 counter */
#define TIMER_CNTRL_OFFSET     0x30        /* Offset for timer control register */
#define TIMER_INTS_OFFSET      0x34        /* Offset for timer interrupt status register */
#define TIMER_INTM_OFFSET      0x38        /* Offset for timer interrupt mask register */

/* interrupt sources */

#define IC_GPIO     (1 << IRQ_GPIO)

#define IC_TIMER1   (1 << IRQ_TIMER1)
#define IC_TIMER2   (1 << IRQ_TIMER2)
#define IC_TIMER3   (1 << IRQ_TIMER3)

/* Timer 1 ~ 3, ATC010 */
#define TM1_CNTR  ((0x000 + TIMER_BASE))
#define TM1_LOAD  ((0x004 + TIMER_BASE))
#define TM1_MTCH1 ((0x008 + TIMER_BASE))
#define TM1_MTCH2 ((0x00c + TIMER_BASE))

#define TM2_CNTR  ((0x010 + TIMER_BASE))
#define TM2_LOAD  ((0x014 + TIMER_BASE))
#define TM2_MTCH1 ((0x018 + TIMER_BASE))
#define TM2_MTCH2 ((0x01c + TIMER_BASE))

#define TM3_CNTR  ((0x020 + TIMER_BASE))
#define TM3_LOAD  ((0x024 + TIMER_BASE))
#define TM3_MTCH1 ((0x028 + TIMER_BASE))
#define TM3_MTCH2 ((0x02c + TIMER_BASE))

#define TM_CR     ((0x030 + TIMER_BASE))
#define TM_STA    ((0x034 + TIMER_BASE))
#define TM_MSK    ((0x038 + TIMER_BASE))

/* TmCR */
#define TM_CR_TM1ENA (0x1 << 0)  //1/enable
#define TM_CR_TM1CLK (0x1 << 1)  //1/EXT1CLK, 0/PCLK
#define TM_CR_TM1OEN (0x1 << 2)  //1/enable overflow interrupt
#define TM_CR_TM2ENA (0x1 << 3)  //1/enable
#define TM_CR_TM2CLK (0x1 << 4)  //1/EXT1CLK, 0/PCLK
#define TM_CR_TM2OEN (0x1 << 5)  //1/enable overflow interrupt
#define TM_CR_TM3ENA (0x1 << 6)  //1/enable
#define TM_CR_TM3CLK (0x1 << 7)  //1/EXT1CLK, 0/PCLK
#define TM_CR_TM3OEN (0x1 << 8)  //1/enable overflow interrupt
#define TM_CR_TM1UP  (0x1 << 9)  //1/up count
#define TM_CR_TM2UP  (0x1 << 10) //1/up count
#define TM_CR_TM3UP  (0x1 << 11) //1/up count

/* IntrState */
#define TM_STA_TM1M1 (0x1 << 0)
#define TM_STA_TM1M2 (0x1 << 1)
#define TM_STA_TM1OV (0x1 << 2)
#define TM_STA_TM2M1 (0x1 << 3)
#define TM_STA_TM2M2 (0x1 << 4)
#define TM_STA_TM2OV (0x1 << 5)
#define TM_STA_TM3M1 (0x1 << 6)
#define TM_STA_TM3M2 (0x1 << 7)
#define TM_STA_TM3OV (0x1 << 8)

/* IntrMask */
#define TM_MSK_TM1M1 TM_STA_TM1M1
#define TM_MSK_TM1M2 TM_STA_TM1M2
#define TM_MSK_TM1OV TM_STA_TM1OV
#define TM_MSK_TM2M1 TM_STA_TM2M1
#define TM_MSK_TM2M2 TM_STA_TM2M2
#define TM_MSK_TM2OV TM_STA_TM2OV
#define TM_MSK_TM3M1 TM_STA_TM3M1
#define TM_MSK_TM3M2 TM_STA_TM3M2
#define TM_MSK_TM3OV TM_STA_TM3OV

#define INTC_TIMER1_MASK        0x00080000  /* Mask to enable timer interrupt */
#define INTC_TIMER1_CLEAR_VALUE 0x00080000  /* Value to clear pending timer1 interrupt */
#define INTC_TIMER_CLEAR_VALUE  0x0008c000  /* Value to clear all pending timer interrupt */
#define INTC_TIMER1_TRIGGER     0x00080000  /* bit 19  = 1: Edge trigger */
#define INTC_TIMER1_LEVEL       0x00000000  /* bit 19  = 0: Falling edge Trigger */

#define TIMER1_INTM_INIT        0x00000003  /* Mask out timer1 match interrupts */
#define TIMER_CNTRL_DISABLE     0x00000000  /* Value to disable timer */
#define TIMER1_CTRL_INIT        0x00000005  /* Bit 2   = 1, enalbe timer1 interrupt */
                                            /* Bit 1   = 1, clock source, PCLK */
					    /* Bit 0   = 1, enable timer1 */
#define TIMER1_INTS_CLEAR_MASK  0xfffffff8  /* Clear mask of timer status register */

#define PMUC_BASE               0x98100000  /* Base address of PMU */
#define FSSR_OFFSET		0x04	    /* Frequency Scaling Status Register */
#define PWRMODE_OFFSET          0x0C        /* Power Mode Register */
#define MFPSR_OFFSET		0x28	    /* Multi-Function Port Setting Register */
#define PLLDLLCR0_OFFSET        0x30        /* PLL/DLL Control Register 0 */
#define SHTCR_OFFSET		0x4c	    /* Signal Hold Time Control Register*/
#define PLL1NS_FIELD_OFF        3           /* PLL1NS field offset */
#define PLL1NS_MASK             0x00000ff8  /* PLL1NS field mask */
#define DIV_FACTOR_FIELD_OFF    4           /* Clock dividor factor field offset */
#define DIV_FACTOR_MASK         0x000000f0  /* Clock dividor factor mask */

/************************************
 *  TARGET INTERRUPT CONSTANTS      *
 ************************************/

#define INTC_BASE              0x98800000  /* Interrupt Controller base address */
#define IRQSRCR_OFFSET         0x00        /* IRQ(HW1) Source Register offset */
#define IRQER_OFFSET           0x04        /* IRQ(HW1) Enable Register offset */
#define IRQICR_OFFSET          0x08        /* IRQ(HW1) Interrupt Clear Register offset */
#define IRQTMR_OFFSET          0x0C        /* IRQ(HW1) Trigger Mode Register offset */
#define IRQTLR_OFFSET          0x10        /* IRQ(HW1) Trigger Level Register offset */
#define IRQSR_OFFSET           0x14        /* IRQ(HW1) Status Register offset */
#define FIQSRCR_OFFSET         0x20        /* FIQ(HW0) Source Register offset */
#define FIQER_OFFSET           0x24        /* FIQ(HW0) Enable Register offset */
#define FIQICR_OFFSET          0x28        /* FIQ(HW0) Interrupt Clear Register offset */
#define FIQTMR_OFFSET          0x2C        /* FIQ(HW0) Trigger Mode Register offset */
#define FIQTLR_OFFSET          0x30        /* FIQ(HW0) Trigger Level Register offset */
#define FIQSR_OFFSET           0x34        /* FIQ(HW0) Status Register offset */
#define INT_ER_INIT            0x00000000  /* values used to disable all interrupts */
#define INT_CLEAR_VALUE        0xFFFFFFFF  /* values used to clear all pending interrupts */

/* Constants utilized by interrupt handler for nesting interrupts */

#define FIRST_STACK_OFFSET     40          /* First stack offset FIQ/IRQ interrupt unnset */
#define IRQER_STACK_OFFSET     40          /* INT MASK register */
#define FIQER_STACK_OFFSET     44          /* Interrupt ER OFFSET register value */
#define MASK1_STACK_OFFSET     40          /* INT MASK register */
#define IEROFF_STACK_OFFSET    44          /* Interrupt ER OFFSET register value */
#define NUM_MASK_REGS          2           /* Number of mask register (1 mask register */
                                           /* and base address of interrupt */
                                           /* control register for core module) */
#define MASK_REG_SPACE         (NUM_MASK_REGS * 4)

/************************************
 *  TARGET SMC CONSTANTS          *
 ************************************/

#define SMC_BASE            	0x90200000	/* Static Memory Controller base address */
#define BANK0TPR_OFFSET		0x4		/* Bank 0 timing parameter register */
#define LED_BASE		0x902ffffc	/* LED base address */
/************************************
 *  TARGET SDRAM CONSTANTS          *
 ************************************/

#define SDRAMC_BASE            0x90300000  /* SDRAM Controller base address */
#define PARM1_OFFSET           0x00        /* Parameter 1 Register offset */
#define PARM2_OFFSET           0x04        /* Parameter 2 Register offset */
#define CONFIG1_OFFSET         0x08        /* Configuration 1 Register offset */
#define CONFIG2_OFFSET         0x0C        /* Configuration 2 Register offset */

#define SDRAMC_PARM1_INIT      0x00011312  /* SDRAMC Parameter 1 init value */
#define SDRAMC_PARM2_INIT      0x00480180  /* SDRAMC Parameter 2 init value */
#define SDRAMC_CONFIG1_INIT    0x00002326  /* SDRAMC bank 0 init value */
#define SDRAMC_CONFIG2_INIT    0x00000010  /* SDRAM Precharge Action Bit for Configuration Register */

/************************************
 *  TARGET DECODER CONSTANTS        *
 ************************************/

#define AHBC_BASE              0x90100000  /* AHB Controller base address */
#define DEVICE6_OFFSET         0x18        /* Device 6 Control Register offset */
#define INTC_OFFSET            0x88        /* Interrupt Control Register offset */

#define AHBC_DEV6_INIT         0x10080000  /* AHBC Device 6 init value */
#define AHBC_REMAP_BIT         0x00000001  /* AHBC remap bit for Interrupt Control Register */

/************************************
 *  GPIO controller                 *
 ************************************/

#define	inw(reg)		(*((volatile unsigned int *) (reg)))
#define	outw(reg, data) 	((*((volatile unsigned int *)(reg)))=(unsigned int)(data))

#ifndef NDS32_INTR_DEF
/* 
 * NDS32_REG_SET_BITS(addr, mask)
 * Do set bits to 1 at specified location
 * Operation: *addr = (*addr | mask)
 * */
#define NDS32_SET_BITS(addr, mask) \
__asm__ __volatile__(\
"	sethi 	$r1, hi20(%1)		\n\t"	\
"	ori   	$r1, $r1, lo12(%1)	\n\t"	\
"	sethi 	$r2, hi20(%0)		\n\t"	\
"	ori   	$r2, $r2, lo12(%0)	\n\t"	\
"	lwi   	$r0, [$r2]		\n\t"	\
"	or    	$r0, $r0, $r1		\n\t"	\
"	sw      $r0, [$r2]		\n\t"	\
	::"i"(addr),"i"(mask):"$r0", "$r1", "$r2")
/*
 * NDS32_REG_WAIT4_BIT_ON(addr, mask)
 * Read the contents at addr and use mask to 
 * mask off unused bits then wait until all of 
 * the remaining bits are on
 *
 * Operation: while(!(*addr & mask));
 * */
#define NDS32_REG_WAIT4_BIT_ON(addr, mask) \
__asm__ __volatile__(\
"	sethi  $r1, hi20(%1)		\n\t"	\
"	ori    $r1, $r1, lo12(%1)	\n\t"	\
"	sethi  $r2, hi20(%0)		\n\t"	\
"	ori    $r2, $r2, lo12(%0)	\n\t"	\
"1:	lwi    $r0, [$r2]		\n\t"	\
"	and    $r0, $r0, $r1		\n\t"	\
"	beqz   $r0, 1b			\n\t"	\
        ::"i"(addr),"i"(mask):"$r0", "$r1", "$r2")

/*
 * NDS32_REG_WAIT4_BIT_OFF(addr, mask)
 * Read the contents at addr and use mask to 
 * mask off unused bits then wait until all of 
 * the remaining bits are off
 *
 * Operation: while((*addr & mask));
 * */
#define NDS32_REG_WAIT4_BIT_OFF(addr, mask) \
__asm__ __volatile__(\
"	sethi  $r1, hi20(%1)		\n\t"	\
"	ori    $r1, $r1, lo12(%1)	\n\t"	\
"	sethi  $r2, hi20(%0)		\n\t"	\
"	ori    $r2, $r2, lo12(%0)	\n\t"	\
"1:	lwi    $r0, [$r2]		\n\t"	\
"	and    $r0, $r0, $r1		\n\t"	\
"	bnez   $r0, 1b			\n\t"	\
        ::"i"(addr),"i"(mask):"$r0", "$r1", "$r2")

/*
 * NDS32_REG_WRITE(addr, data)
 * Write data to specified location at addr
 *
 * Operation: *addr = data
 * */
#define NDS32_REG_WRITE(addr, data) \
__asm__ __volatile__(\
"	sethi 	$r1, hi20(%1)		\n\t"	\
"	ori   	$r1, $r1, lo12(%1)	\n\t"	\
"	sethi 	$r0, hi20(%0)		\n\t"	\
"	swi   	$r1, [$r0 + lo12(%0)]	\n\t"	\
	::"i"(addr),"i"(data):"$r0", "$r1")

/*
 * NDS32_FMEMCPY_BYTE(dst, src, size)
 * Do forward (low address to high address) memory copy in byte 
 * */
#define NDS32_FMEMCPY_BYTE(dst, src, size) \
__asm__ __volatile__(\
"	sethi	$r3, hi20(%2)		\n\t"	\
"	ori	$r3, $r3, lo12(%2)	\n\t"	\
"	sethi	$r1, hi20(%0)		\n\t"	\
"	ori	$r1, $r1, lo12(%0)	\n\t"	\
"	sethi	$r2, hi20(%1)		\n\t"	\
"	ori	$r2, $r2, lo12(%1)	\n\t"	\
"1:	lbi.bi	$r0, [$r2], 1		\n\t"	\
"	sbi.bi	$r0, [$r1], 1		\n\t"	\
"	addi	$r3, $r3, -1		\n\t"	\
"	bnez	$r3, 1b			\n\t"	\
	::"i"(dst),"i"(src),"i"(size):"$r0", "$r1","$r2","$r3")

#define NDS32_FMEMCPY(dst, src, size) \
__asm__ __volatile__(\
"	sethi	$r3, hi20(%2)		\n\t"	\
"	ori	$r3, $r3, lo12(%2)	\n\t"	\
"	sethi	$r1, hi20(%0)		\n\t"	\
"	ori	$r1, $r1, lo12(%0)	\n\t"	\
"	sethi	$r2, hi20(%1)		\n\t"	\
"	ori	$r2, $r2, lo12(%1)	\n\t"	\
"1:	lwi.bi	$r0, [$r2], 4 		\n\t"	\
"	swi.bi	$r0, [$r1], 4		\n\t"	\
"	addi	$r3, $r3, -4		\n\t"	\
"	bgtz	$r3, 1b			\n\t"	\
	::"i"(dst),"i"(src),"i"(size):"$r0", "$r1","$r2","$r3")

#endif

#define GPIO_BASE				0x98700000  /* GPIO base address */
#define	GPIO_DOUT_OFFSET	   	0x0
#define	GPIO_DIN_OFFSET			0x4
#define	GPIO_DIR_OFFSET			0x8
#define	GPIO_DSET_OFFSET		0x10
#define	GPIO_DCLEAR_OFFSET		0x14
#define	GPIO_PE_OFFSET			0x18
#define	GPIO_PT_OFFSET			0x1C
#define	GPIO_IE_OFFSET			0x20
#define	GPIO_IS_OFFSET			0x24

#define	GPIO_IT_OFFSET			0x34
#define	GPIO_IC_OFFSET			0x30
#define	GPIO_IB_OFFSET			0x38
#define	GPIO_IR_OFFSET			0x3c

/******************************************************************
        UART register mapping
 *****************************************************************/
#define UART_BASE 				0x99600000
#define UART_RBR_OFFSET         0x00 	/* Receiver Buffer Register for Read */
#define UART_THR_OFFSET         0x00 	/* Transmitter Holding Register for Write */
#define UART_IER_OFFSET         0x04 	/* Interrupt Enable Register */
                                        /* Baud-Rate Divisor Latch (DL, Offset: 0x00, 0x04 when DLAB = 1) */
#define UART_IIR_OFFSET         0x08 	/* Interrupt Identification Register */
#define UART_FCR_OFFSET         0x08 	/* FIFO Control Register */
										/* Prescaler Register (PSR, Offset: 0x08 when DLAB =1) */
#define UART_LCR_OFFSET         0x0C 	/* Line Control Register */
#define UART_MCR_OFFSET         0x10 	/* Modem Control Register */
#define UART_LSR_OFFSET         0x14 	/* Line Status Register for Read */
#define UART_TST_OFFSET         0x14 	/* Testing Register for Write */
#define UART_MSR_OFFSET         0x18 	/* Modem Status Register */
#define UART_SPR_OFFSET         0x1C 	/* Scratch Pad Register */
#define UART_MDR_OFFSET         0x20 	/* Mode Definition Register */
#define UART_ACR_OFFSET         0x24	/* Auxiliary Control Register */
#define UART_TXLENL_OFFSET      0x28	/* Transmit Frame-Length Register (Low) */
#define UART_TXLENH_OFFSET      0x2C	/* Transmit Frame-Length Register (High)*/
#define UART_MRXLENL_OFFSET     0x30	/* Maximum Receiver Frame-Length (Low) */
#define UART_MRXLENH_OFFSET     0x34	/* Maximum Receiver Frame-Length (High)*/
#define UART_PLR_OFFSET         0x38	/* Preamble Length Register */
#define UART_FMIIR_PIO_OFFSET   0x3C	/* Interrupt Identification Register in FIR Mode (PIO mode) */
#define UART_FMIIR_DMA_OFFSET   0x3C	/* Interrupt Identification Register in FIR Mode (DMA mode) */
#define UART_FMIIER_PIO_OFFSET  0x40	/* Interrupt Identification Enable Register in FIR Mode (PIO mode) */
#define UART_FMIIER_DMA_OFFSET  0x40	/* Interrupt Identification Enable Register in FIR Mode (DMA mode) */
#define UART_STFF_STS_OFFSET    0x44	/* Status FIFO Line Status Register */
#define UART_STFF_RXLENL_OFFSET 0x48	/* Status FIFO Received Frame-Length Register Low */
#define UART_STFF_RXLENH_OFFSET 0x4C	/* Status FIFO Received Frame-Length Register High */
#define UART_FMLSR_OFFSET       0x50	/* Link Status Register in FIR Mode */
#define UART_FMLSIER_OFFSET     0x54	/* Link Status Interrupt Enable Register in FIR Mode */
#define UART_RSR_OFFSET         0x58	/* Resume Register */
#define UART_RXFF_CNTR_OFFSET   0x5C	/* RX FIFO Count Register */
#define UART_LSTFMLENL_OFFSET   0x60	/* Last Frame Length Register Low */
#define UART_LSTFMLENH_OFFSET   0x64	/* Last Frame Length Register High */
#define UART_FEATURE_OFFSET     0x68	/* Feature Register */
#define UART_REVD1_OFFSET       0x6C	/* Revision Register Digit 1 */
#define UART_REVD2_OFFSET       0x70	/* Revision Register Digit 2 */
#define UART_REVD3_OFFSET       0x74	/* Revision Register Digit 3 */

/******************************************************************
        AHB/APB device register mapping
 *****************************************************************/

//irq number
#define IRQ_CFC_CD                      0
#define IRQ_CFC_DMA                     1
#define IRQ_SSP1                        2
#define IRQ_I2C                         3
#define IRQ_SDC                         5
#define IRQ_SSP2                        6
#define IRQ_UART1                       10
#define IRQ_UART2                       11
#define IRQ_GPIO                        13
#define IRQ_TIMER2                      14
#define IRQ_TIMER3                      15
#define IRQ_TIMER1                      19
#define IRQ_APB_BRIDGE                  24
#define IRQ_CPE_AHB_DMA                 21
#define IRQ_CPE_APB_DMA                 24
#define IRQ_MAC                         25
#define IRQ_TOUCH                       28
#define IRQ_EXT_A321                    30
#define IRQ_USBDEV                      26   // USB device
#define IRQ_FOTG200                     29   // FOTG200 device
//#define IRQ_USB_HOST11                  27   // USB Host 1.1
#define IRQ_SECU                        29   // security AES/DES/3DES
#define IRQ_USB_HOST20                  29   // USB Host 200


#endif  /* AG101_REGS */
