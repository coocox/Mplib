/**
 ******************************************************************************
 * @file      startup_PAC5XXX_CooCox.c
 * @author    mds
 * @version   V0.1
 * @date      01/13/2012
 * @brief     PAC5XXX startup code for CooCox IDE (CoIde)
 *            This module performs:
 *                - Set the initial SP
 *                - Set the vector table entries 
 *                - Initialize data and bss 			
 *                - Call the application's entry point.
 *            After Reset the Cortex-M0 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 *******************************************************************************
 */
 
#include "system_pac5xxx.h"

/*----------Stack Configuration-----------------------------------------------*/  
#define STACK_SIZE       0x000000FF      /*!< Stack size (in Words)           */
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];      


/*----------Macro definition--------------------------------------------------*/  
#define WEAK __attribute__ ((weak))           


/*----------Declaration of the default fault handlers-------------------------*/  
/* System exception vector handler */
void WEAK  Reset_Handler(void);
void WEAK  NMI_Handler(void);
void WEAK  HardFault_Handler(void);
void WEAK  SVC_Handler(void);
void WEAK  PendSV_Handler(void);
void WEAK  SysTick_Handler(void);
void WEAK  MemCtl_IRQHandler(void);                   /*!< Memory controller bad address fetch 	*/
void WEAK  SysClk_IRQHandler(void);                   /*!< unused 								*/
void WEAK  Wdt_IRQHandler(void);                      /*!< WDT Interval timer					*/
void WEAK  GpioA_IRQHandler(void);                    /*!< GPIOA - PA[0:7]						*/
void WEAK  GpioB_IRQHandler(void);                    /*!< GPIOB - PB[0:7]						*/
void WEAK  GpioC_IRQHandler(void);                    /*!< GPIOC - PC[0:7]						*/
void WEAK  GpioD_IRQHandler(void);                    /*!< GPIOD - PD[0:7]						*/
void WEAK  GpioE_IRQHandler(void);                    /*!< GPIOE - PE[0:7]						*/
void WEAK  TimerA_IRQHandler(void);                   /*!< Timer A (Base, CC 0-5)				*/
void WEAK  TimerAExt_IRQHandler(void);	              /*!< Timer A Extended (CC 6-7)			*/
void WEAK  TimerB_IRQHandler(void);                   /*!< Timer B (Base + CC)					*/
void WEAK  TimerC_IRQHandler(void);                   /*!< Timer C (Base + CC)					*/
void WEAK  TimerD_IRQHandler(void);                   /*!< Timer D (Base + CC)					*/
void WEAK  ADC_IRQHandler(void);                      /*!< ADC (ADCINT, AS0, AS1, ASC)			*/
void WEAK  SocBridge_IRQHandler(void);                /*!< SocBridge							*/
void WEAK  SPIB_IRQHandler(void);                     /*!< SPI-B								*/
void WEAK  UART_IRQHandler(void);                     /*!< UART									*/
void WEAK  I2C_IRQHandler(void);                      /*!< I2C									*/
void WEAK  EMUX_IRQHandler(void);                     /*!< ADC EMUX								*/
void WEAK  RTC_IRQHandler(void);                      /*!< RTC (Real-time Clock)                */


/*----------Symbols defined in linker script----------------------------------*/  
extern unsigned long _sidata;    /*!< Start address for the initialization 
                                      values of the .data section.            */
extern unsigned long _sdata;     /*!< Start address for the .data section     */    
extern unsigned long _edata;     /*!< End address for the .data section       */    
extern unsigned long _sbss;      /*!< Start address for the .bss section      */
extern unsigned long _ebss;      /*!< End address for the .bss section        */      
extern void _eram;               /*!< End address for ram                     */

extern uint32_t fault_mask;

/*----------Function prototypes-----------------------------------------------*/  
extern int main(void);           /*!< The entry point for the application.    */
void Default_Reset_Handler(void);   /*!< Default reset handler                */
static void Default_Handler(void);  /*!< Default exception handler            */


/**
  *@brief The minimal vector table for a Cortex M0.  Note that the proper constructs
  *       must be placed on this to ensure that it ends up at physical address
  *       0x00000000.  
  */
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
  /*----------Core Exceptions------------------------------------------------ */
  (void *)&pulStack[STACK_SIZE],       /*!< The initial stack pointer         */
  Reset_Handler,                       /*!< The reset handler                 */
  NMI_Handler,                         /*!< The NMI handler                   */ 
  HardFault_Handler,                   /*!< The hard fault handler            */
  0,0,0,0,0,0,0,                       /*!< Reserved                          */
  SVC_Handler,                         /*!< SVCall handler                    */
  0, 0,                                /*!< Reserved                          */
  PendSV_Handler,                      /*!< The PendSV handler                */
  SysTick_Handler,                     /*!< The SysTick handler               */ 
  
  /*----------External Exceptions---------------------------------------------*/
  MemCtl_IRQHandler,                   /*!< Memory controller handler         */
  SysClk_IRQHandler,                   /*!< unused                            */
  Wdt_IRQHandler,                      /*!< WDT handler                       */
  GpioA_IRQHandler,                    /*!< GPIOA handler                     */
  GpioB_IRQHandler,                    /*!< GPIOB handler                     */
  GpioC_IRQHandler,                    /*!< GPIOC handler                     */
  GpioD_IRQHandler,                    /*!< GPIOD handler                     */
  GpioE_IRQHandler,                    /*!< GPIOE handler                     */
  TimerA_IRQHandler,                   /*!< Timer A handler                   */
  TimerAExt_IRQHandler,	               /*!< Timer A Extended handler          */
  TimerB_IRQHandler,                   /*!< Timer B handler                   */
  TimerC_IRQHandler,                   /*!< Timer C handler                   */
  TimerD_IRQHandler,                   /*!< Timer D handler                   */
  ADC_IRQHandler,                      /*!< ADC handler                       */
  SocBridge_IRQHandler,                /*!< SocBridge handler                 */
  SPIB_IRQHandler,                     /*!< SPI-B handler                     */
  UART_IRQHandler,                     /*!< UART handler                      */
  I2C_IRQHandler,                      /*!< I2C handler                       */
  EMUX_IRQHandler,                     /*!< ADC EMUX handler                  */
  RTC_IRQHandler                       /*!< RTC handler                       */
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
  
  /* Zero fill the bss segment. */
  for(pulDest = &_sbss; pulDest < &_ebss; )
  {
    *(pulDest++) = 0;
  }
	
  /* Call SystemInit for device initialization before letting user have control */
  SystemInit();

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
#pragma weak SVC_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler
#pragma weak MemCtl_IRQHandler = Default_Handler
#pragma weak SysClk_IRQHandler = Default_Handler
#pragma weak Wdt_IRQHandler = Default_Handler
#pragma weak GpioA_IRQHandler = Default_Handler
#pragma weak GpioB_IRQHandler = Default_Handler
#pragma weak GpioC_IRQHandler = Default_Handler
#pragma weak GpioD_IRQHandler = Default_Handler
#pragma weak GpioE_IRQHandler = Default_Handler
#pragma weak TimerA_IRQHandler = Default_Handler
#pragma weak TimerAExt_IRQHandler = Default_Handler
#pragma weak TimerB_IRQHandler = Default_Handler
#pragma weak TimerC_IRQHandler = Default_Handler
#pragma weak TimerD_IRQHandler = Default_Handler
#pragma weak ADC_IRQHandler = Default_Handler
#pragma weak SocBridge_IRQHandler = Default_Handler
#pragma weak SPIB_IRQHandler = Default_Handler
#pragma weak UART_IRQHandler = Default_Handler
#pragma weak I2C_IRQHandler = Default_Handler
#pragma weak EMUX_IRQHandler = Default_Handler
#pragma weak RTC_IRQHandler = Default_Handler


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
	while (1);
}


/*********************** (C) COPYRIGHT 2009 Coocox ************END OF FILE*****/
