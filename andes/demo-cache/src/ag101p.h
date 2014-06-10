#ifndef AG101P_REGS
#define AG101P_REGS
/* Check to see if this file has been included already.  */

#ifndef __ASSEMBLY__
#include <nds32_intrinsic.h>
#endif

/* System Clock */
#define MHz                     1000000

#ifdef CFG_16MB
#define CPUFREQ                 (30 * MHz)
#define HCLKFREQ                (CPUFREQ / 2)
#define PCLKFREQ                (CPUFREQ / 2)
#define UCLKFREQ                PCLKFREQ
#else
#define CPUFREQ                 (60 * MHz)
#define HCLKFREQ                (CPUFREQ / 2)
#define PCLKFREQ                (CPUFREQ / 4)
#define UCLKFREQ                PCLKFREQ
#endif

/* Different memory size defines used by SDRAM initialization */
#define SDRAM_256MB             0x0100
#define SDRAM_128MB             0x00C0
#define SDRAM_64MB              0x0040
#define SDRAM_32MB              0x0004
#define SDRAM_16MB              0x0000

#ifdef CFG_16MB
#define ORIG_RAM_BASE           0x00800000
#else
#define ORIG_RAM_BASE           0x80000000
#endif

#define REMAP_ROM_BASE          ORIG_RAM_BASE

/************************************
 *  TARGET TIMER CONSTANTS          *
 ************************************/
#ifdef CFG_16MB
#define TIMER_BASE              0x00F04000  /* Define base for all timer registers */
#else
#define TIMER_BASE              0x98400000  /* Define base for all timer registers */
#endif
#define TIMER_CNT_OFFSET(N)     (0x00 + 0x10 * (N)) /* Offset for timer N counter register */
#define TIMER_LOAD_OFFSET(N)    (0x04 + 0x10 * (N)) /* Offset for timer N load register */
#define TIMER_MATCH1_OFFSET(N)  (0x08 + 0x10 * (N)) /* Offset for timer N match1 register */
#define TIMER_MATCH2_OFFSET(N)  (0x0C + 0x10 * (N)) /* Offset for timer N match2 register */
#define TIMER_CNTRL_OFFSET      0x30        /* Offset for timer control register */
#define TIMER_INTS_OFFSET       0x34        /* Offset for timer interrupt status register */
#define TIMER_INTM_OFFSET       0x38        /* Offset for timer interrupt mask register */

/* Timer 1 ~ 3, ATC010 */
#define TM_CNTR(N)              (TIMER_BASE + TIMER_CNT_OFFSET(N))
#define TM_LOAD(N)              (TIMER_BASE + TIMER_LOAD_OFFSET(N))
#define TM_MTCH1(N)             (TIMER_BASE + TIMER_MATCH1_OFFSET(N))
#define TM_MTCH2(N)             (TIMER_BASE + TIMER_MATCH2_OFFSET(N))

#define TM_CR                   (TIMER_BASE + TIMER_CNTRL_OFFSET)
#define TM_STA                  (TIMER_BASE + TIMER_INTS_OFFSET)
#define TM_MSK                  (TIMER_BASE + TIMER_INTM_OFFSET)

/************************************
 *  TARGET PMU CONSTANTS            *
 ************************************/
#ifdef CFG_16MB
#define PMUC_BASE               0x00F01000  /* Base address of PMU */
#else
#define PMUC_BASE               0x98100000  /* Base address of PMU */
#endif
#define FSSR_OFFSET             0x04        /* Frequency Scaling Status Register */
#define PWRMODE_OFFSET          0x0C        /* Power Mode Register */
#define MFPSR_OFFSET            0x28        /* Multi-Function Port Setting Register */
#define PLLDLLCR0_OFFSET        0x30        /* PLL/DLL Control Register 0 */
#define SHTCR_OFFSET            0x4c        /* Signal Hold Time Control Register*/
#define PLL1NS_FIELD_OFF        3           /* PLL1NS field offset */
#define PLL1NS_MASK             0x00000ff8  /* PLL1NS field mask */
#define DIV_FACTOR_FIELD_OFF    4           /* Clock dividor factor field offset */
#define DIV_FACTOR_MASK         0x000000f0  /* Clock dividor factor mask */

/************************************
 *  TARGET INTERRUPT CONSTANTS      *
 ************************************/
#ifdef CFG_16MB
#define INTC_BASE               0x00F08000  /* Interrupt Controller base address */
#else
#define INTC_BASE               0x98800000  /* Interrupt Controller base address */
#endif
#define IRQSRCR_OFFSET          0x00        /* IRQ(HW1) Source Register offset */
#define IRQER_OFFSET            0x04        /* IRQ(HW1) Enable Register offset */
#define IRQICR_OFFSET           0x08        /* IRQ(HW1) Interrupt Clear Register offset */
#define IRQTMR_OFFSET           0x0C        /* IRQ(HW1) Trigger Mode Register offset */
#define IRQTLR_OFFSET           0x10        /* IRQ(HW1) Trigger Level Register offset */
#define IRQSR_OFFSET            0x14        /* IRQ(HW1) Status Register offset */
#define FIQSRCR_OFFSET          0x20        /* FIQ(HW0) Source Register offset */
#define FIQER_OFFSET            0x24        /* FIQ(HW0) Enable Register offset */
#define FIQICR_OFFSET           0x28        /* FIQ(HW0) Interrupt Clear Register offset */
#define FIQTMR_OFFSET           0x2C        /* FIQ(HW0) Trigger Mode Register offset */
#define FIQTLR_OFFSET           0x30        /* FIQ(HW0) Trigger Level Register offset */
#define FIQSR_OFFSET            0x34        /* FIQ(HW0) Status Register offset */
#define INT_ER_INIT             0x00000000  /* values used to disable all interrupts */
#define INT_CLEAR_VALUE         0xFFFFFFFF  /* values used to clear all pending interrupts */

/* Constants utilized by interrupt handler for nesting interrupts */

#define FIRST_STACK_OFFSET      40          /* First stack offset FIQ/IRQ interrupt unnset */
#define IRQER_STACK_OFFSET      40          /* INT MASK register */
#define FIQER_STACK_OFFSET      44          /* Interrupt ER OFFSET register value */
#define MASK1_STACK_OFFSET      40          /* INT MASK register */
#define IEROFF_STACK_OFFSET     44          /* Interrupt ER OFFSET register value */
#define NUM_MASK_REGS           2           /* Number of mask register (1 mask register */
                                            /* and base address of interrupt */
                                            /* control register for core module) */
#define MASK_REG_SPACE          (NUM_MASK_REGS * 4)

/************************************
 *  TARGET SMC CONSTANTS          *
 ************************************/
#ifdef CFG_16MB
#define SMC_BASE                0x00E01000  /* Static Memory Controller base address */
#else
#define SMC_BASE                0x90200000  /* Static Memory Controller base address */
#endif
#define BANK0TPR_OFFSET         0x4         /* Bank 0 timing parameter register */
#define SMC_BANK0TPR_INIT       0x00151151  /* ? */

#ifdef CFG_16MB
#define LED_BASE                (SMC_BASE+(1<<12)-4)    /* LED base address */
#else
#define LED_BASE                (SMC_BASE+(1<<20)-4)    /* LED base address */
#endif

/************************************
 *  TARGET SDRAM CONSTANTS          *
 ************************************/
#ifdef CFG_16MB
#define SDRAMC_BASE             0x00E02000  /* SDRAM Controller base address */
#else
#define SDRAMC_BASE             0x90300000  /* SDRAM Controller base address */
#endif
#define PARM1_OFFSET            0x00        /* Parameter 1 Register offset */
#define PARM2_OFFSET            0x04        /* Parameter 2 Register offset */
#define CONFIG1_OFFSET          0x08        /* Configuration 1 Register offset */
#define CONFIG2_OFFSET          0x0C        /* Configuration 2 Register offset */

#define SDRAMC_PARM1_INIT       0x00011312  /* SDRAMC Parameter 1 init value */
#define SDRAMC_PARM2_INIT       0x004800a0  /* SDRAMC Parameter 2 init value */
#ifdef CFG_16MB
#define SDRAMC_CONFIG1_INIT     0x00002023  /* SDRAMC bank 0 init value */
#else
#define SDRAMC_CONFIG1_INIT     0x00002326  /* SDRAMC bank 0 init value */
#endif
#define SDRAMC_CONFIG2_INIT     0x00000010  /* SDRAM Precharge Action Bit for Configuration Register */

/************************************
 *  TARGET DECODER CONSTANTS        *
 ************************************/
#ifdef CFG_16MB
#define AHBC_BASE               0x00E00000  /* AHB Controller base address */
#else
#define AHBC_BASE               0x90100000  /* AHB Controller base address */
#endif
#define DEVICE4_OFFSET          0x10        /* Device 4 Control Register offset */
#define DEVICE6_OFFSET          0x18        /* Device 6 Control Register offset */
#define INTC_OFFSET             0x88        /* Interrupt Control Register offset */

#define AHBC_DEV6_INIT          0x10080000  /* AHBC Device 6 init value */
#define AHBC_REMAP_BIT          0x00000001  /* AHBC remap bit for Interrupt Control Register */

#ifdef CFG_16MB
/* ROM */
#define AHBC_DEV4_SIZE_INIT     0x0000000b  /* 1MB   */
#define AHBC_DEV4_SIZE_REMAP    AHBC_DEV4_SIZE_INIT
/* RAM */
#define AHBC_DEV6_SIZE_INIT     0x0000000d  /* 4MB   */
#define AHBC_DEV6_SIZE_REMAP    0x0000000e  /* 8MB   */
#else
/* ROM */
#define AHBC_DEV4_SIZE_INIT     0x00080000  /* 256MB */
#define AHBC_DEV4_SIZE_REMAP    AHBC_DEV4_SIZE_INIT
/* RAM */
#define AHBC_DEV6_SIZE_INIT     0x00080000  /* 256MB */
#define AHBC_DEV6_SIZE_REMAP    0x000b0000  /* 2GB   */
#endif

/************************************
 *  TARGET GPIO CONSTANTS           *
 ************************************/
#ifdef CFG_16MB
#define GPIO_BASE               0x00F07000  /* GPIO base address */
#else
#define GPIO_BASE               0x98700000  /* GPIO base address */
#endif
#define GPIO_DOUT_OFFSET        0x0
#define GPIO_DIN_OFFSET         0x4
#define GPIO_DIR_OFFSET         0x8
#define GPIO_DSET_OFFSET        0x10
#define GPIO_DCLEAR_OFFSET      0x14
#define GPIO_PE_OFFSET          0x18
#define GPIO_PT_OFFSET          0x1C
#define GPIO_IE_OFFSET          0x20
#define GPIO_IS_OFFSET          0x24

#define GPIO_IT_OFFSET          0x34
#define GPIO_IC_OFFSET          0x30
#define GPIO_IB_OFFSET          0x38
#define GPIO_IR_OFFSET          0x3c
#define GPIO_BE_OFFSET          0x40 /* BounceEnable */
#define GPIO_BPS_OFFSET         0x44 /* BouncePreScale */

#define GPIO_USED_GCOV          0x01 /* Which GPIO to do GCOV */
#define GPIO_USED_MASK          0x3E /* Which GPIOs to use */

/************************************
 *  TARGET UART CONSTANTS           *
 ************************************/
#ifdef CFG_16MB
#define UART_BASE               0x00F16000
#else
#define UART_BASE               0x99600000
#endif
#define UART_RBR_OFFSET         0x00    /* Receiver Buffer Register for Read */
#define UART_THR_OFFSET         0x00    /* Transmitter Holding Register for Write */
#define UART_IER_OFFSET         0x04    /* Interrupt Enable Register */
/* Baud-Rate Divisor Latch (DL, Offset: 0x00, 0x04 when DLAB = 1) */
#define UART_DLL_OFFSET         0x00
#define UART_DLM_OFFSET         0x04
#define UART_IIR_OFFSET         0x08    /* Interrupt Identification Register */
#define UART_FCR_OFFSET         0x08    /* FIFO Control Register */
/* Prescaler Register (PSR, Offset: 0x08 when DLAB =1) */
#define UART_PSR_OFFSET         0x08
#define UART_LCR_OFFSET         0x0C    /* Line Control Register */
#define UART_MCR_OFFSET         0x10    /* Modem Control Register */
#define UART_LSR_OFFSET         0x14    /* Line Status Register for Read */
#define UART_TST_OFFSET         0x14    /* Testing Register for Write */
#define UART_MSR_OFFSET         0x18    /* Modem Status Register */
#define UART_SPR_OFFSET         0x1C    /* Scratch Pad Register */
#define UART_MDR_OFFSET         0x20    /* Mode Definition Register */
#define UART_ACR_OFFSET         0x24    /* Auxiliary Control Register */
#define UART_TXLENL_OFFSET      0x28    /* Transmit Frame-Length Register (Low) */
#define UART_TXLENH_OFFSET      0x2C    /* Transmit Frame-Length Register (High)*/
#define UART_MRXLENL_OFFSET     0x30    /* Maximum Receiver Frame-Length (Low) */
#define UART_MRXLENH_OFFSET     0x34    /* Maximum Receiver Frame-Length (High)*/
#define UART_PLR_OFFSET         0x38    /* Preamble Length Register */
#define UART_FMIIR_PIO_OFFSET   0x3C    /* Interrupt Identification Register in FIR Mode (PIO mode) */
#define UART_FMIIR_DMA_OFFSET   0x3C    /* Interrupt Identification Register in FIR Mode (DMA mode) */
#define UART_FMIIER_PIO_OFFSET  0x40    /* Interrupt Identification Enable Register in FIR Mode (PIO mode) */
#define UART_FMIIER_DMA_OFFSET  0x40    /* Interrupt Identification Enable Register in FIR Mode (DMA mode) */
#define UART_STFF_STS_OFFSET    0x44    /* Status FIFO Line Status Register */
#define UART_STFF_RXLENL_OFFSET 0x48    /* Status FIFO Received Frame-Length Register Low */
#define UART_STFF_RXLENH_OFFSET 0x4C    /* Status FIFO Received Frame-Length Register High */
#define UART_FMLSR_OFFSET       0x50    /* Link Status Register in FIR Mode */
#define UART_FMLSIER_OFFSET     0x54    /* Link Status Interrupt Enable Register in FIR Mode */
#define UART_RSR_OFFSET         0x58    /* Resume Register */
#define UART_RXFF_CNTR_OFFSET   0x5C    /* RX FIFO Count Register */
#define UART_LSTFMLENL_OFFSET   0x60    /* Last Frame Length Register Low */
#define UART_LSTFMLENH_OFFSET   0x64    /* Last Frame Length Register High */
#define UART_FEATURE_OFFSET     0x68    /* Feature Register */
#define UART_REVD1_OFFSET       0x6C    /* Revision Register Digit 1 */
#define UART_REVD2_OFFSET       0x70    /* Revision Register Digit 2 */
#define UART_REVD3_OFFSET       0x74    /* Revision Register Digit 3 */

/************************************
 *  IRQ number                      *
 ************************************/
#define HW0_FIQ                 0       // For 4GB platform only
#define HW1_IRQ                 1       // For 4GB platform only
#define HW6_SW0                 6       // For 4GB platform only

#define IRQ_CFC_CD              0
#define IRQ_CFC_DMA             1
#define IRQ_SSP1                2
#define IRQ_I2C                 3
#define IRQ_SDC                 5
#define IRQ_SSP2                6
#define IRQ_SWI                 9
#define IRQ_UART1               10
#define IRQ_UART2               11
#define IRQ_GPIO                13
#define IRQ_TIMER2              14
#define IRQ_TIMER3              15
#define IRQ_TIMER1              19
#define IRQ_APB_BRIDGE          24
#define IRQ_CPE_AHB_DMA         21
#define IRQ_CPE_APB_DMA         24
#define IRQ_MAC                 25
#define IRQ_TOUCH               28
#define IRQ_EXT_A321            30
#define IRQ_USBDEV              26      // USB device
#define IRQ_FOTG200             29      // FOTG200 device
//#define IRQ_USB_HOST11          27    // USB Host 1.1
#define IRQ_SECU                29      // security AES/DES/3DES
#define IRQ_USB_HOST20          29      // USB Host 200

/* interrupt sources */
#define IC_SWI                  (1 << IRQ_SWI)
#define IC_GPIO                 (1 << IRQ_GPIO)
#define IC_TIMER1               (1 << IRQ_TIMER1)
#define IC_TIMER2               (1 << IRQ_TIMER2)
#define IC_TIMER3               (1 << IRQ_TIMER3)

/* Low-level port I/O */
#define inw(reg)        (*((volatile unsigned int *) (reg)))
#define outw(reg, data) ((*((volatile unsigned int *)(reg)))=(unsigned int)(data))

#ifndef NDS32_INTR_DEF
/*
 * NDS32_REG_SET_BITS(addr, mask)
 * Do set bits to 1 at specified location
 * Operation: *addr = (*addr | mask)
 */
#define NDS32_SET_BITS(addr, mask)          outw(addr, inw(addr) | mask)

/*
 * NDS32_REG_WAIT4_BIT_ON(addr, mask)
 * Read the contents at addr and use mask to
 * mask off unused bits then wait until all of
 * the remaining bits are on
 *
 * Operation: while(!(*addr & mask));
 */
#define NDS32_REG_WAIT4_BIT_ON(addr, mask)  while(0 == (inw(addr) & mask))

/*
 * NDS32_REG_WAIT4_BIT_OFF(addr, mask)
 * Read the contents at addr and use mask to
 * mask off unused bits then wait until all of
 * the remaining bits are off
 *
 * Operation: while((*addr & mask));
 */
#define NDS32_REG_WAIT4_BIT_OFF(addr, mask) while(inw(addr) & mask)

/*
 * NDS32_REG_WRITE(addr, data)
 * Write data to specified location at addr
 *
 * Operation: *addr = data
 * */
#define NDS32_REG_WRITE(addr, data) outw(addr, data)

/*
 * NDS32_FMEMCPY_BYTE(dst, src, size)
 * Do forward (low address to high address) memory copy in byte
 * */
#define NDS32_FMEMCPY_BYTE(dst, src, size) \
	__asm__ __volatile__( \
		"sethi   $r3, hi20(%2)       \n\t" \
		"ori     $r3, $r3, lo12(%2)  \n\t" \
		"sethi   $r1, hi20(%0)       \n\t" \
		"ori     $r1, $r1, lo12(%0)  \n\t" \
		"sethi   $r2, hi20(%1)       \n\t" \
		"ori     $r2, $r2, lo12(%1)  \n\t" \
		"1:\n\t" \
		"lbi.bi  $r0, [$r2], 1       \n\t" \
		"sbi.bi  $r0, [$r1], 1       \n\t" \
		"addi    $r3, $r3, -1        \n\t" \
		"bnez    $r3, 1b             \n\t" \
		::"i"(dst),"i"(src),"i"(size):"$r0", "$r1","$r2","$r3")

#define NDS32_FMEMCPY(dst, src, size) \
	__asm__ __volatile__( \
		"sethi   $r3, hi20(%2)       \n\t" \
		"ori     $r3, $r3, lo12(%2)  \n\t" \
		"sethi   $r1, hi20(%0)       \n\t" \
		"ori     $r1, $r1, lo12(%0)  \n\t" \
		"sethi   $r2, hi20(%1)       \n\t" \
		"ori     $r2, $r2, lo12(%1)  \n\t" \
		"1:\n\t" \
		"lwi.bi  $r0, [$r2], 4       \n\t" \
		"swi.bi  $r0, [$r1], 4       \n\t" \
		"addi    $r3, $r3, -4        \n\t" \
		"bgtz    $r3, 1b             \n\t" \
		::"i"(dst),"i"(src),"i"(size):"$r0", "$r1","$r2","$r3")

#endif

/************************************
 *  HAL Level : Memory interface    *
 ************************************/
#define AG101P_SDRAM_INIT()                                         \
{                                                                   \
        /* SDRAM controller - set timing parameter */               \
        NDS32_REG_WRITE(SDRAMC_BASE + PARM1_OFFSET, SDRAMC_PARM1_INIT);\
        NDS32_REG_WRITE(SDRAMC_BASE + PARM2_OFFSET, SDRAMC_PARM2_INIT);\
        /* SDRAM controller - set config register */                \
        NDS32_REG_WRITE(SDRAMC_BASE + CONFIG1_OFFSET, SDRAMC_CONFIG1_INIT);\
        /* refer to ATFSDMC appendix, and boot.S of bootcode */     \
        NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, SDRAMC_CONFIG2_INIT);\
        NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0x1c);\
        NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, 0x4);         \
        NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0x1c);\
        NDS32_REG_WRITE(SDRAMC_BASE + CONFIG2_OFFSET, 0x8);         \
        NDS32_REG_WAIT4_BIT_OFF(SDRAMC_BASE + CONFIG2_OFFSET, 0x1c);\
}

#define HAL_MEMORY_SETUP(_base_)                                    \
do {                                                                \
        /* static memory bank 0 timing parameter register */        \
        NDS32_REG_WRITE(SMC_BASE + BANK0TPR_OFFSET, SMC_BANK0TPR_INIT);\
        /* PMU - PLL/DLL Control Register 0 - Enable DLL */         \
        NDS32_SET_BITS(PMUC_BASE + PLLDLLCR0_OFFSET, 0x00010000);   \
        /* Initial SDRAM controller */                              \
        AG101P_SDRAM_INIT();                                        \
        /* Enable SDRAM */                                          \
        NDS32_REG_WRITE(SDRAMC_BASE + 0x10, 0x1000 | (_base_ >> 20));\
        /* RAM (base,size) : (base, 2GB)(4GB mode) / (base, 8MB)(16MB mode) */    \
        NDS32_REG_WRITE(AHBC_BASE + DEVICE6_OFFSET, _base_ | AHBC_DEV6_SIZE_INIT);\
} while(0)

#define HAL_MEMORY_REMAP()                                          \
do {                                                                \
        /* Remapping */                                             \
        /* Bank Enable, BASE = 0x100 for haddr[31:20] of the AHB address bus. */\
        /* External Bank Configuration Registers */                 \
        NDS32_REG_WRITE(SDRAMC_BASE + 0x14, 0x0);                   \
        NDS32_REG_WRITE(SDRAMC_BASE + 0x18, 0x0);                   \
        NDS32_REG_WRITE(SDRAMC_BASE + 0x1c, 0x0);                   \
        /* Bank Enable, BASE = 0x0 for haddr[31:20] of the AHB address bus. */  \
        NDS32_REG_WRITE(SDRAMC_BASE + 0x10, 0x1000);                \
        /* When writing a 1 to this bit, the base/size configuration\
         * of AHB slaves 4 (ROM) and 6 (SDRAM/DDR) will be interchanged. */     \
        NDS32_SET_BITS(AHBC_BASE + INTC_OFFSET, 0x1);               \
} while(0)

#define HAL_MEMORY_REMAP_ADJUST()                                   \
do {                                                                \
        NDS32_REG_WRITE(AHBC_BASE + DEVICE6_OFFSET, 0x000 | AHBC_DEV6_SIZE_REMAP);\
} while(0)

/************************************
 *  HAL Level : Interrupt           *
 ************************************/
#define HW_ISR(hw)             HW##hw##_ISR
#define SET_HWISR(hw)          HW_ISR(hw)

#if !defined(CFG_16MB) && !defined(CFG_EVIC)
/* ISR function name for interrupt controller platform */
#define FIQ_ISR                SET_HWISR(HW0_FIQ)
#define IRQ_ISR                SET_HWISR(HW1_IRQ)
#define SW0_ISR                SET_HWISR(HW6_SW0)
#endif

/* ISR function name for 32IVIC/EVIC platform */
#define SWI_ISR                SET_HWISR(IRQ_SWI)
#define GPIO_ISR               SET_HWISR(IRQ_GPIO)
#define TIMER_ISR              SET_HWISR(IRQ_TIMER1)

#ifdef CFG_16MB
/* AG101P 16MB platform without interrupt controller */
#define HAL_INTC_HWIRQ_ROUTE(_vector_, _hw_)
#define HAL_INTC_IRQ_CONFIGURE(_irqs_, _edge_, _falling_)
#define HAL_INTC_IRQ_MASK(_irqs_)
#define HAL_INTC_IRQ_UNMASK(_irqs_)
#define HAL_INTC_IRQ_CLEAR(_irqs_)
#define HAL_INTC_FIQ_CONFIGURE(_irqs_, _edge_, _falling_)
#define HAL_INTC_FIQ_MASK(_irqs_)
#define HAL_INTC_FIQ_UNMASK(_irqs_)
#define HAL_INTC_FIQ_CLEAR(_irqs_)
#else
/* HAL for interrupt controller */
#define HAL_INTC_HWIRQ_ROUTE(_vector_, _hw_)

#define HAL_INTC_IRQ_CONFIGURE(_irqs_, _edge_, _falling_)           \
do {                                                                \
        if (_edge_) {                                               \
               outw(INTC_BASE + IRQTMR_OFFSET,                      \
                        inw(INTC_BASE + IRQTMR_OFFSET) | (_irqs_)); \
        } else {                                                    \
               outw(INTC_BASE + IRQTMR_OFFSET,                      \
                        inw(INTC_BASE + IRQTMR_OFFSET) & ~(_irqs_));\
        }                                                           \
        if (_falling_) {                                            \
                outw(INTC_BASE + IRQTLR_OFFSET,                     \
                        inw(INTC_BASE + IRQTLR_OFFSET) | (_irqs_)); \
        } else {                                                    \
                outw(INTC_BASE + IRQTLR_OFFSET,                     \
                        inw(INTC_BASE + IRQTLR_OFFSET) & ~(_irqs_));\
        }                                                           \
} while(0)

#define HAL_INTC_IRQ_MASK(_irqs_)                                   \
        outw(INTC_BASE + IRQER_OFFSET,                              \
                inw(INTC_BASE + IRQER_OFFSET) & ~(_irqs_))

#define HAL_INTC_IRQ_UNMASK(_irqs_)                                 \
        outw(INTC_BASE + IRQER_OFFSET,                              \
                inw(INTC_BASE + IRQER_OFFSET) | (_irqs_))

#define HAL_INTC_IRQ_CLEAR(_irqs_)                                  \
        outw(INTC_BASE + IRQICR_OFFSET, (_irqs_))

#define HAL_INTC_FIQ_CONFIGURE(_irqs_, _edge_, _falling_)           \
do {                                                                \
        if (_edge_) {                                               \
               outw(INTC_BASE + FIQTMR_OFFSET,                      \
                        inw(INTC_BASE + FIQTMR_OFFSET) | (_irqs_)); \
        } else {                                                    \
               outw(INTC_BASE + FIQTMR_OFFSET,                      \
                        inw(INTC_BASE + FIQTMR_OFFSET) & ~(_irqs_));\
        }                                                           \
        if (_falling_) {                                           \
                outw(INTC_BASE + FIQTLR_OFFSET,                     \
                        inw(INTC_BASE + FIQTLR_OFFSET) | (_irqs_)); \
        } else {                                                    \
                outw(INTC_BASE + FIQTLR_OFFSET,                     \
                        inw(INTC_BASE + FIQTLR_OFFSET) & ~(_irqs_));\
        }                                                           \
} while(0)


#define HAL_INTC_FIQ_MASK(_irqs_)                                   \
        outw(INTC_BASE + FIQER_OFFSET,                              \
                inw(INTC_BASE + FIQER_OFFSET) & ~(_irqs_))

#define HAL_INTC_FIQ_UNMASK(_irqs_)                                 \
        outw(INTC_BASE + FIQER_OFFSET,                              \
                inw(INTC_BASE + FIQER_OFFSET) | (_irqs_))

#define HAL_INTC_FIQ_CLEAR(_irqs_)                                  \
        outw(INTC_BASE + FIQICR_OFFSET, (_irqs_))
#endif

/************************************
 *  HAL Level : Timer               *
 ************************************/
#define HAL_TIMER_INITIALIZE()                                      \
do {                                                                \
        outw(TM_CR, 0);                                             \
        outw(TM_MTCH1(0), 0);                                       \
        outw(TM_MTCH1(1), 0);                                       \
        outw(TM_MTCH1(2), 0);                                       \
        outw(TM_MSK, 0);                                            \
        outw(TM_STA, 0xFFFFFFFF);                                   \
} while(0)

#define HAL_TIMER_START(_tmr_)                                      \
        outw(TM_CR, inw(TM_CR) | (0x1 << (3 * (_tmr_))))

#define HAL_TIMER_STOP(_tmr_)                                       \
        outw(TM_CR, inw(TM_CR) & ~(0x1 << (3 * (_tmr_))))

#define HAL_TIMER_READ(_tmr_, _pvalue_)                             \
        *(volatile unsigned int *)_pvalue_ =                        \
                        inw(TM_LOAD(_tmr_)) - inw(TM_CNTR(_tmr_))

#define HAL_TIMER_SET_PERIOD(_tmr_, _period_)                       \
do {                                                                \
        outw(TM_LOAD(_tmr_), _period_);                             \
        outw(TM_CNTR(_tmr_), _period_);                             \
} while(0)

#define HAL_TIMER_IRQ_ENABLE(_tmr_, _ie_)                           \
do {                                                                \
        if(_ie_)                                                    \
                outw(TM_MSK, inw(TM_MSK) & ~(0x1 << (3 * (_tmr_))));\
        else                                                        \
                outw(TM_MSK, inw(TM_MSK) | (0x1 << (3 * (_tmr_)))); \
} while(0)

#define HAL_TIMER_IRQ_STATUS(_tmr_, _pvalue_)                       \
        *(volatile unsigned int *)_pvalue_ =                        \
                        (inw(TM_STA) & (0x7 << (3 * (_tmr_))))

#define HAL_TIMER_IRQ_CLR(_tmr_)                                    \
        outw(TM_STA, (0x7 << (3 * (_tmr_))))

/************************************
 *  HAL Level : GPIO                *
 ************************************/
#define HAL_GPIO_INITIALIZE(_pin_)                                  \
do {                                                                \
        outw(GPIO_BASE + GPIO_DIR_OFFSET,                           \
                inw(GPIO_BASE + GPIO_DIR_OFFSET) & ~_pin_);         \
        outw(GPIO_BASE + GPIO_IR_OFFSET,                            \
                inw(GPIO_BASE + GPIO_IR_OFFSET) | _pin_);           \
        outw(GPIO_BASE + GPIO_DCLEAR_OFFSET, -1);                   \
        outw(GPIO_BASE + GPIO_BPS_OFFSET, 0x0000FFFF);              \
        outw(GPIO_BASE + GPIO_BE_OFFSET, _pin_);                    \
        outw(GPIO_BASE + GPIO_IC_OFFSET, -1);                       \
        outw(GPIO_BASE + GPIO_IE_OFFSET, _pin_);                    \
} while(0)

#define HAL_GPIO_READ()         inw(GPIO_BASE + GPIO_DIN_OFFSET)

#define HAL_GPIO_IRQ_CLR(_pin_) outw(GPIO_BASE + GPIO_IC_OFFSET, _pin_)

#ifdef __ASSEMBLY__
/************************************
 *  HAL : AG101P defined vectors    *
 ************************************/
.macro  hal_hw_vectors
#if defined(CFG_16MB) || defined(CFG_EVIC)
	vector Interrupt_UNDEF   //  (9) Interrupt HW0
        vector Interrupt_UNDEF   // (10) Interrupt HW1
        vector Interrupt_UNDEF   // (11) Interrupt HW2
        vector Interrupt_UNDEF   // (12) Interrupt HW3
        vector Interrupt_UNDEF   // (13) Interrupt HW4
        vector Interrupt_UNDEF   // (14) Interrupt HW5
        vector Interrupt_UNDEF   // (15) Interrupt HW6
#else
        vector Interrupt_HW0     //  (9) Interrupt HW0 (for IVB.IVIC_VER = 0, FIR)
        vector Interrupt_HW1     // (10) Interrupt HW1 (for IVB.IVIC_VER = 0, IRQ)
        vector Interrupt_UNDEF   // (11) Interrupt HW2
        vector Interrupt_UNDEF   // (12) Interrupt HW3
        vector Interrupt_UNDEF   // (13) Interrupt HW4
        vector Interrupt_UNDEF   // (14) Interrupt HW5
        vector Interrupt_HW6     // (15) Interrupt HW6 (for IVB.IVIC_VER = 0, SW0)
#endif
        vector Interrupt_UNDEF   // (16) Interrupt HW7
        vector Interrupt_UNDEF   // (17) Interrupt HW8
        vector Interrupt_HW9     // (18) Interrupt HW9 (32IVIC, SWI)
        vector Interrupt_UNDEF   // (19) Interrupt HW10
        vector Interrupt_UNDEF   // (20) Interrupt HW11
        vector Interrupt_UNDEF   // (21) Interrupt HW12
        vector Interrupt_HW13    // (22) Interrupt HW13 (32IVIC, GPIO)
        vector Interrupt_UNDEF   // (23) Interrupt HW14
        vector Interrupt_UNDEF   // (24) Interrupt HW15
        vector Interrupt_UNDEF   // (25) Interrupt HW16
        vector Interrupt_UNDEF   // (26) Interrupt HW17
        vector Interrupt_UNDEF   // (27) Interrupt HW18
        vector Interrupt_HW19    // (28) Interrupt HW19 (32IVIC, TIMER)
        vector Interrupt_UNDEF   // (29) Interrupt HW20
        vector Interrupt_UNDEF   // (30) Interrupt HW21
        vector Interrupt_UNDEF   // (31) Interrupt HW22
        vector Interrupt_UNDEF   // (32) Interrupt HW23
        vector Interrupt_UNDEF   // (33) Interrupt HW24
        vector Interrupt_UNDEF   // (34) Interrupt HW25
        vector Interrupt_UNDEF   // (35) Interrupt HW26
        vector Interrupt_UNDEF   // (36) Interrupt HW27
        vector Interrupt_UNDEF   // (37) Interrupt HW28
        vector Interrupt_UNDEF   // (38) Interrupt HW29
        vector Interrupt_UNDEF   // (39) Interrupt HW30
        vector Interrupt_UNDEF   // (40) Interrupt HW31
.endm

.macro  hal_hw_ISR
#if !defined(CFG_16MB) && !defined(CFG_EVIC)
	Os_Trap_Interrupt_HW    HW0_FIQ
        Os_Trap_Interrupt_HW    HW1_IRQ
        Os_Trap_Interrupt_HW    HW6_SW0
#endif
        Os_Trap_Interrupt_HW    IRQ_SWI
        Os_Trap_Interrupt_HW    IRQ_GPIO
        Os_Trap_Interrupt_HW    IRQ_TIMER1
.endm

.macro  hal_set_led, val
        li  $r0, \val
        li  $r1, LED_BASE
        swi $r0, [$r1]
.endm
#endif  /* __ASSEMBLY__ */

#endif  /* AG101P_REGS */
