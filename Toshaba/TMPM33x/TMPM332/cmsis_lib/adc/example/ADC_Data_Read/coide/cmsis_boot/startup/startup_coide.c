/**
 ******************************************************************************
 * @file      startup_TMPM330
 * @author    Coocox
 * @version   V2.1.0
 * @date      04/08/2013
 * @brief     TMPM330 Devices Startup code.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the vector table entries with the exceptions ISR address
 *                - Initialize data and bss
 *                - Setup the microcontroller system.
 *                - Call the application's entry point.
 *            After Reset the Cortex-M3 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 *******************************************************************************
 */
 
 
 /*----------Stack Configuration----------------------------------------------*/
#define STACK_SIZE       0x00000200      /*!< Stack size (in Words)           */
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];


/*----------Macro definition--------------------------------------------------*/
#define WEAK __attribute__ ((weak))


/*----------Declaration of the default fault handlers-------------------------*/
/* System exception vector handler */
void WEAK  Reset_Handler(void);
void WEAK  NMI_Handler(void);
void WEAK  HardFault_Handler(void);
void WEAK  MemManage_Handler(void);
void WEAK  BusFault_Handler(void);
void WEAK  UsageFault_Handler(void);
void WEAK  SVC_Handler(void);
void WEAK  DebugMon_Handler(void);
void WEAK  PendSV_Handler(void);
void WEAK  SysTick_Handler(void);

void WEAK  INT0_IRQHandler(void);
void WEAK  INT1_IRQHandler(void);
void WEAK  INT2_IRQHandler(void);
void WEAK  INT3_IRQHandler(void);
void WEAK  INT4_IRQHandler(void);
void WEAK  INT5_IRQHandler(void);
void WEAK  INTRX0_IRQHandler(void);
void WEAK  INTTX0_IRQHandler(void);
void WEAK  INTRX1_IRQHandler(void);
void WEAK  INTTX1_IRQHandler(void);
void WEAK  INTSBI0_IRQHandler(void);
void WEAK  INTSBI1_IRQHandler(void);
void WEAK  INTCECRX_IRQHandler(void);
void WEAK  INTCECTX_IRQHandler(void);
void WEAK  INTRMCRX0_IRQHandler(void);
void WEAK  INTADHP_IRQHandler(void);
void WEAK  INTADM0_IRQHandler(void);
void WEAK  INTADM1_IRQHandler(void);
void WEAK  INTTB0_IRQHandler(void);
void WEAK  INTTB1_IRQHandler(void);
void WEAK  INTTB2_IRQHandler(void);
void WEAK  INTTB3_IRQHandler(void);
void WEAK  INTTB4_IRQHandler(void);
void WEAK  INTTB5_IRQHandler(void);
void WEAK  INTTB6_IRQHandler(void);
void WEAK  INTRTC_IRQHandler(void);
void WEAK  INTCAP00_IRQHandler(void);
void WEAK  INTCAP01_IRQHandler(void);
void WEAK  INTCAP10_IRQHandler(void);
void WEAK  INTCAP11_IRQHandler(void);
void WEAK  INTCAP50_IRQHandler(void);
void WEAK  INTCAP51_IRQHandler(void);
void WEAK  INTCAP60_IRQHandler(void);
void WEAK  INTCAP61_IRQHandler(void);
void WEAK  INT6_IRQHandler(void);
void WEAK  INT7_IRQHandler(void);
void WEAK  INTRX2_IRQHandler(void);
void WEAK  INTTX2_IRQHandler(void);
void WEAK  INTSBI2_IRQHandler(void);
void WEAK  INTRMCRX1_IRQHandler(void);
void WEAK  INTTB7_IRQHandler(void);
void WEAK  INTTB8_IRQHandler(void);
void WEAK  INTTB9_IRQHandler(void);
void WEAK  INTCAP20_IRQHandler(void);
void WEAK  INTCAP21_IRQHandler(void);
void WEAK  INTCAP30_IRQHandler(void);
void WEAK  INTCAP31_IRQHandler(void);
void WEAK  INTCAP40_IRQHandler(void);
void WEAK  INTCAP41_IRQHandler(void);
void WEAK  INTAD_IRQHandler(void);

/*----------Symbols defined in linker script----------------------------------*/
extern unsigned long _sidata;    /*!< Start address for the initialization
                                      values of the .data section.            */
extern unsigned long _sdata;     /*!< Start address for the .data section     */
extern unsigned long _edata;     /*!< End address for the .data section       */
extern unsigned long _sbss;      /*!< Start address for the .bss section      */
extern unsigned long _ebss;      /*!< End address for the .bss section        */
extern void _eram;               /*!< End address for ram                     */


/*----------Function prototypes-----------------------------------------------*/
extern int main(void);           /*!< The entry point for the application.    */
//extern void SystemInit(void);    /*!< Setup the microcontroller system(CMSIS) */
void Default_Reset_Handler(void);   /*!< Default reset handler                */
static void Default_Handler(void);  /*!< Default exception handler            */


/**
  *@brief The minimal vector table for a Cortex M3. Note that the proper constructs
  *       must be placed on this to ensure that it ends up at physical address
  *       0x00000000.
  */
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  /*----------Core Exceptions------------------------------------------------ */
  (void *)&pulStack[STACK_SIZE-1],     /*!< The initial stack pointer         */
  Reset_Handler,             /*!< Reset Handler                               */
  NMI_Handler,               /*!< NMI Handler                                 */
  HardFault_Handler,         /*!< Hard Fault Handler                          */
  MemManage_Handler,         /*!< MPU Fault Handler                           */
  BusFault_Handler,          /*!< Bus Fault Handler                           */
  UsageFault_Handler,        /*!< Usage Fault Handler                         */
  0,0,0,0,                   /*!< Reserved                                    */
  SVC_Handler,               /*!< SVCall Handler                              */
  DebugMon_Handler,          /*!< Debug Monitor Handler                       */
  0,                         /*!< Reserved                                    */
  PendSV_Handler,            /*!< PendSV Handler                              */
  SysTick_Handler,           /*!< SysTick Handler                             */

  /*----------External Exceptions---------------------------------------------*/
  INT0_IRQHandler,           /*!<  0: Interrupt pin (PJ0/70 pin)                             */
  INT1_IRQHandler,           /*!<  1:  Interrupt pin (PJ1/49 pin)                            */
  INT2_IRQHandler,           /*!<  2:  Interrupt pin (PJ2/86 pin)                            */
  INT3_IRQHandler,           /*!<  3:  Interrupt pin (PJ3/87 pin)                            */
  INT4_IRQHandler,           /*!<  4:  Interrupt pin (PG3/6  pin)                            */
  INT5_IRQHandler,           /*!<  5:  Interrupt pin (PF7/19 pin)                            */
  INTRX0_IRQHandler,         /*!<  6:  Serial reception (channel.0)                          */
  INTTX0_IRQHandler,         /*!<  7:  Serial transmission (channel.0)                       */
  INTRX1_IRQHandler,         /*!<  8:  Serial reception (channel.1)                          */
  INTTX1_IRQHandler,         /*!<  9:  Serial transmission (channel.1)                       */
  INTSBI0_IRQHandler,        /*!<  10: Serial bus interface 0                                */
  INTSBI1_IRQHandler,        /*!<  11: Serial bus interface 1                                */
  INTCECRX_IRQHandler,       /*!<  12: CEC reception                                         */
  INTCECTX_IRQHandler,       /*!<  13: CEC transmission                                      */
  INTRMCRX0_IRQHandler,      /*!<  14: Remote control signal reception (channel.0)           */
  INTADHP_IRQHandler,        /*!<  15: Highest priority AD conversion complete interrupt     */
  INTADM0_IRQHandler,        /*!<  16: AD conversion monitoring function interrupt 0         */
  INTADM1_IRQHandler,        /*!<  17: AD conversion monitoring function interrupt 1         */
  INTTB0_IRQHandler,         /*!<  18: 16-bit TMRB match detection 0                         */
  INTTB1_IRQHandler,         /*!<  19: 16-bit TMRB match detection 1                         */
  INTTB2_IRQHandler,         /*!<  20: 16-bit TMRB match detection 2                         */
  INTTB3_IRQHandler,         /*!<  21: 16-bit TMRB match detection 3                         */
  INTTB4_IRQHandler,         /*!<  22: 16-bit TMRB match detection 4                         */
  INTTB5_IRQHandler,         /*!<  23: 16-bit TMRB match detection 5                         */
  INTTB6_IRQHandler,         /*!<  24: 16-bit TMRB match detection 6                         */
  INTRTC_IRQHandler,         /*!<  25: Real time clock timer                                 */
  INTCAP00_IRQHandler,       /*!<  26: 16-bit TMRB input capture 00                          */
  INTCAP01_IRQHandler,       /*!<  27: 16-bit TMRB input capture 01                          */
  INTCAP10_IRQHandler,       /*!<  28: 16-bit TMRB input capture 10                          */
  INTCAP11_IRQHandler,       /*!<  29: 16-bit TMRB input capture 11                          */
  INTCAP50_IRQHandler,       /*!<  30: 16-bit TMRB input capture 50                          */
  INTCAP51_IRQHandler,       /*!<  31: 16-bit TMRB input capture 51                          */
  INTCAP60_IRQHandler,       /*!<  32: 16-bit TMRB input capture 60                          */
  INTCAP61_IRQHandler,       /*!<  33: 16-bit TMRB input capture 61                          */
  INT6_IRQHandler,           /*!<  34: Interrupt pin (PJ6/39 pin)                            */
  INT7_IRQHandler,           /*!<  35: Interrupt pin (PJ7/58 pin)                            */
  INTRX2_IRQHandler,         /*!<  36: Serial reception (channel.2)                          */
  INTTX2_IRQHandler,         /*!<  37: Serial transmission (channel.2)                       */
  INTSBI2_IRQHandler,        /*!<  38: Serial bus interface 2                                */
  INTRMCRX1_IRQHandler,      /*!<  39: Remote control signal reception (channel.1)           */
  INTTB7_IRQHandler,         /*!<  40: 16-bit TMRB match detection 7                         */
  INTTB8_IRQHandler,         /*!<  41: 16-bit TMRB match detection 8                         */
  INTTB9_IRQHandler,         /*!<  42: 16-bit TMRB match detection 9                         */
  INTCAP20_IRQHandler,       /*!<  43: 16-bit TMRB input capture 20                          */
  INTCAP21_IRQHandler,       /*!<  44: 16-bit TMRB input capture 21                          */
  INTCAP30_IRQHandler,       /*!<  45: 16-bit TMRB input capture 30                          */
  INTCAP31_IRQHandler,       /*!<  46: 16-bit TMRB input capture 31                          */
  INTCAP40_IRQHandler,       /*!<  47: 16-bit TMRB input capture 40                          */
  INTCAP41_IRQHandler,       /*!<  48: 16-bit TMRB input capture 41                          */
  INTAD_IRQHandler,          /*!< 49: A/D conversion completion                              */
};



/**
  * @brief  This is the code that gets called when the processor first
  *         starts execution following a reset event. Only the absolutely
  *         necessary set is performed, after which the application
  *         supplied main() routine is called.
  * @param  None
  * @retval None
  */
void Default_Reset_Handler(void)
{
  /* Initialize data and bss */
  unsigned long *pulSrc, *pulDest;

  /* Copy the data segment initializers from flash to SRAM */
  pulSrc = &_sidata;

  for(pulDest = &_sdata; pulDest < &_edata; )
  {
    *(pulDest++) = *(pulSrc++);
  }

  /* Zero fill the bss segment.  This is done with inline assembly since this
     will clear the value of pulDest if it is not kept in a register. */
  __asm("  ldr     r0, =_sbss\n"
        "  ldr     r1, =_ebss\n"
        "  mov     r2, #0\n"
        "  .thumb_func\n"
        "zero_loop:\n"
        "    cmp     r0, r1\n"
        "    it      lt\n"
        "    strlt   r2, [r0], #4\n"
        "    blt     zero_loop");

  /* Call the application's entry point.*/
  main();
}


/**
  *@brief Provide weak aliases for each Exception handler to the Default_Handler.
  *       As they are weak aliases, any function with the same name will override
  *       this definition.
  */
#pragma weak Reset_Handler = Default_Reset_Handler
#pragma weak NMI_Handler = Default_Handler
#pragma weak HardFault_Handler = Default_Handler
#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler

#pragma weak INT0_IRQHandler = Default_Handler
#pragma weak INT1_IRQHandler = Default_Handler
#pragma weak INT2_IRQHandler = Default_Handler
#pragma weak INT3_IRQHandler = Default_Handler
#pragma weak INT4_IRQHandler = Default_Handler
#pragma weak INT5_IRQHandler = Default_Handler
#pragma weak INTRX0_IRQHandler = Default_Handler
#pragma weak INTTX0_IRQHandler = Default_Handler
#pragma weak INTRX1_IRQHandler = Default_Handler
#pragma weak INTTX1_IRQHandler = Default_Handler
#pragma weak INTSBI0_IRQHandler = Default_Handler
#pragma weak INTSBI1_IRQHandler = Default_Handler
#pragma weak INTCECRX_IRQHandler = Default_Handler
#pragma weak INTCECTX_IRQHandler = Default_Handler
#pragma weak INTRMCRX0_IRQHandler = Default_Handler
#pragma weak INTADHP_IRQHandler = Default_Handler
#pragma weak INTADM0_IRQHandler = Default_Handler
#pragma weak INTADM1_IRQHandler = Default_Handler
#pragma weak INTTB0_IRQHandler = Default_Handler
#pragma weak INTTB1_IRQHandler = Default_Handler
#pragma weak INTTB2_IRQHandler = Default_Handler
#pragma weak INTTB3_IRQHandler = Default_Handler
#pragma weak INTTB4_IRQHandler = Default_Handler
#pragma weak INTTB5_IRQHandler = Default_Handler
#pragma weak INTTB6_IRQHandler = Default_Handler
#pragma weak INTRTC_IRQHandler = Default_Handler
#pragma weak INTCAP00_IRQHandler = Default_Handler
#pragma weak INTCAP01_IRQHandler = Default_Handler
#pragma weak INTCAP10_IRQHandler = Default_Handler
#pragma weak INTCAP11_IRQHandler = Default_Handler
#pragma weak INTCAP50_IRQHandler = Default_Handler
#pragma weak INTCAP51_IRQHandler = Default_Handler
#pragma weak INTCAP60_IRQHandler = Default_Handler
#pragma weak INTCAP61_IRQHandler = Default_Handler
#pragma weak INT6_IRQHandler = Default_Handler
#pragma weak INT7_IRQHandler = Default_Handler
#pragma weak INTRX2_IRQHandler = Default_Handler
#pragma weak INTTX2_IRQHandler = Default_Handler
#pragma weak INTSBI2_IRQHandler = Default_Handler
#pragma weak INTRMCRX1_IRQHandler = Default_Handler
#pragma weak INTTB7_IRQHandler = Default_Handler
#pragma weak INTTB8_IRQHandler = Default_Handler
#pragma weak INTTB9_IRQHandler = Default_Handler
#pragma weak INTCAP20_IRQHandler = Default_Handler
#pragma weak INTCAP21_IRQHandler = Default_Handler
#pragma weak INTCAP30_IRQHandler = Default_Handler
#pragma weak INTCAP31_IRQHandler = Default_Handler
#pragma weak INTCAP40_IRQHandler = Default_Handler
#pragma weak INTCAP41_IRQHandler = Default_Handler
#pragma weak INTAD_IRQHandler = Default_Handler


/**
  * @brief  This is the code that gets called when the processor receives an
  *         unexpected interrupt.  This simply enters an infinite loop,
  *         preserving the system state for examination by a debugger.
  * @param  None
  * @retval None
  */
static void Default_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}

/*********************** (C) COPYRIGHT 2012 Coocox ************END OF FILE*****/
