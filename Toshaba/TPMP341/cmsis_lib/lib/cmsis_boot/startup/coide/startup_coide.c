//*****************************************************************************
//
//! \file      startup_coide.c
//! \brief     TMPM341 Devices Startup code for CooCox CoIDE.
//!            This module performs:
//!               - Set the initial SP
//!               - Set the vector table entries with the exceptions ISR address
//!               - Initialize data and bss
//!               - Setup the microcontroller system. 			
//!               - Call the application's entry point.
//!               .
//! \version   V2.1.1.0
//! \date      $CURRENT_TIME$
//! \author    CooCox
//! \copyright
//!
//! Copyright (c)  2013, CooCox 
//! All rights reserved.
//! 
//! Redistribution and use in source and binary forms, with or without 
//! modification, are permitted provided that the following conditions 
//! are met: 
//! 
//!     * Redistributions of source code must retain the above copyright 
//! notice, this list of conditions and the following disclaimer. 
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution. 
//!     * Neither the name of the <ORGANIZATION> nor the names of its 
//! contributors may be used to endorse or promote products derived 
//! from this software without specific prior written permission. 
//! 
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

//***************************************************************************** 
//
// Stack Configuration
//
//*****************************************************************************
//
// Stack size (in Words)
//
#define STACK_SIZE       0x00000200
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];      
 
#define WEAK __attribute__ ((weak))           

//*****************************************************************************
//
// Declaration of the default fault handlers
//
//*****************************************************************************
void WEAK  Reset_Handler          (void);
void WEAK  NMI_Handler            (void);
void WEAK  HardFault_Handler      (void);
void WEAK  MemManage_Handler      (void);
void WEAK  BusFault_Handler       (void);
void WEAK  UsageFault_Handler     (void);
void WEAK  SVC_Handler            (void);
void WEAK  DebugMon_Handler       (void);
void WEAK  PendSV_Handler         (void);
void WEAK  SysTick_Handler        (void);

// External Interrupts
void WEAK  INT0_IRQHandler        (void);   // 0:  Interrupt pin 0
void WEAK  INT1_IRQHandler        (void);   // 1:  Interrupt pin 1
void WEAK  INT2_IRQHandler        (void);   // 2:  Interrupt pin 2
void WEAK  INT3_IRQHandler        (void);   // 3:  Interrupt pin 3
void WEAK  INT4_IRQHandler        (void);   // 4:  Interrupt pin 4
void WEAK  INT5_IRQHandler        (void);   // 5:  Interrupt pin 5
void WEAK  INT6_IRQHandler        (void);   // 6:  Interrupt pin 6
void WEAK  INT7_IRQHandler        (void);   // 7:  Interrupt pin 7
void WEAK  INTRX0_IRQHandler      (void);   // 8:  Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler      (void);   // 9:  Serial transmission (channel.0)
void WEAK  INTRX1_IRQHandler      (void);   // 10: Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler      (void);   // 11: Serial transmission (channel.1)
void WEAK  INTRX2_IRQHandler      (void);   // 12: Serial reception (channel.2)
void WEAK  INTTX2_IRQHandler      (void);   // 13: Serial transmission (channel.2)
void WEAK  INTSBI0_IRQHandler     (void);   // 14: Serial bus interface 0
void WEAK  INTSBI1_IRQHandler     (void);   // 15: Serial bus interface 1
void WEAK  INTADHP_IRQHandler     (void);   // 16: Highest priority AD conversion complete interrupt
void WEAK  INTAD_IRQHandler       (void);   // 17: AD conversion interrupt
void WEAK  INTADM0_IRQHandler     (void);   // 18: AD conversion monitoring function interrupt 0
void WEAK  INTADM1_IRQHandler     (void);   // 19: AD conversion monitoring function interrupt 1
void WEAK  INTTB0_IRQHandler      (void);   // 20: 16-bit TMRB match detection 0
void WEAK  INTTB1_IRQHandler      (void);   // 21: 16-bit TMRB match detection 1
void WEAK  INTTB2_IRQHandler      (void);   // 22: 16-bit TMRB match detection 2
void WEAK  INTTB3_IRQHandler      (void);   // 23: 16-bit TMRB match detection 3
void WEAK  INTTB4_IRQHandler      (void);   // 24: 16-bit TMRB match detection 4
void WEAK  INTTB5_IRQHandler      (void);   // 25: 16-bit TMRB match detection 5
void WEAK  INTTB6_IRQHandler      (void);   // 26: 16-bit TMRB match detection 6
void WEAK  INTTB7_IRQHandler      (void);   // 27: 16-bit TMRB match detection 7
void WEAK  INTTB8_IRQHandler      (void);   // 28: 16-bit TMRB match detection 8
void WEAK  INTTB9_IRQHandler      (void);   // 29: 16-bit TMRB match detection 9
void WEAK  INTTD0CMP0_IRQHandler  (void);   // 30: 16-bit TMRD0 compare interrupt 0
void WEAK  INTTD0CMP1_IRQHandler  (void);   // 31: 16-bit TMRD0 compare interrupt 1
void WEAK  INTTD0CMP2_IRQHandler  (void);   // 32: 16-bit TMRD0 compare interrupt 2
void WEAK  INTTD0CMP3_IRQHandler  (void);   // 33: 16-bit TMRD0 compare interrupt 3
void WEAK  INTTD0CMP4_IRQHandler  (void);   // 34: 16-bit TMRD0 compare interrupt 4
void WEAK  INTTD1CMP0_IRQHandler  (void);   // 35: 16-bit TMRD1 compare interrupt 0
void WEAK  INTTD1CMP1_IRQHandler  (void);   // 36: 16-bit TMRD1 compare interrupt 1
void WEAK  INTTD1CMP2_IRQHandler  (void);   // 37: 16-bit TMRD1 compare interrupt 2
void WEAK  INTTD1CMP3_IRQHandler  (void);   // 38: 16-bit TMRD1 compare interrupt 3
void WEAK  INTTD1CMP4_IRQHandler  (void);   // 39: 16-bit TMRD1 compare interrupt 4
void WEAK  INTPHT00_IRQHandler    (void);   // 40: 16-bit PHC compare interrupt 00
void WEAK  INTPHT01_IRQHandler    (void);   // 41: 16-bit PHC compare interrupt 01
void WEAK  INTPHT10_IRQHandler    (void);   // 42: 16-bit PHC compare interrupt 10
void WEAK  INTPHT11_IRQHandler    (void);   // 43: 16-bit PHC compare interrupt 11
void WEAK  INTPHT20_IRQHandler    (void);   // 44: 16-bit PHC compare interrupt 20
void WEAK  INTPHT21_IRQHandler    (void);   // 45: 16-bit PHC compare interrupt 21
void WEAK  INTPHT30_IRQHandler    (void);   // 46: 16-bit PHC compare interrupt 30
void WEAK  INTPHT31_IRQHandler    (void);   // 47: 16-bit PHC compare interrupt 31
void WEAK  INTPHEVRY0_IRQHandler  (void);   // 48: 16-bit PHC every count interrupt 0
void WEAK  INTPHEVRY1_IRQHandler  (void);   // 49: 16-bit PHC every count interrupt 1
void WEAK  INTPHEVRY2_IRQHandler  (void);   // 50: 16-bit PHC every count interrupt 2
void WEAK  INTPHEVRY3_IRQHandler  (void);   // 51: 16-bit PHC every count interrupt 3
void WEAK  INTRX3_IRQHandler      (void);   // 52: Serial reception (channel.3)
void WEAK  INTTX3_IRQHandler      (void);   // 53: Serial transmission (channel.3)
void WEAK  INTRX4_IRQHandler      (void);   // 54: Serial reception (channel.4)
void WEAK  INTTX4_IRQHandler      (void);   // 55: Serial transmission (channel.4)
void WEAK  INTCAP00_IRQHandler    (void);   // 56: 16-bit TMRB input capture 00
void WEAK  INTCAP01_IRQHandler    (void);   // 57: 16-bit TMRB input capture 01
void WEAK  INTCAP10_IRQHandler    (void);   // 58: 16-bit TMRB input capture 10
void WEAK  INTCAP11_IRQHandler    (void);   // 59: 16-bit TMRB input capture 11
void WEAK  INTCAP20_IRQHandler    (void);   // 60: 16-bit TMRB input capture 20
void WEAK  INTCAP21_IRQHandler    (void);   // 61: 16-bit TMRB input capture 21
void WEAK  INTCAP30_IRQHandler    (void);   // 62: 16-bit TMRB input capture 30
void WEAK  INTCAP31_IRQHandler    (void);   // 63: 16-bit TMRB input capture 31
void WEAK  INTCAP40_IRQHandler    (void);   // 64: 16-bit TMRB input capture 40
void WEAK  INTCAP41_IRQHandler    (void);   // 65: 16-bit TMRB input capture 41
void WEAK  INTCAP50_IRQHandler    (void);   // 66: 16-bit TMRB input capture 50
void WEAK  INTCAP51_IRQHandler    (void);   // 67: 16-bit TMRB input capture 51
void WEAK  INTCAP60_IRQHandler    (void);   // 68: 16-bit TMRB input capture 60
void WEAK  INTCAP61_IRQHandler    (void);   // 69: 16-bit TMRB input capture 61
void WEAK  INTCAP70_IRQHandler    (void);   // 70: 16-bit TMRB input capture 70
void WEAK  INTCAP71_IRQHandler    (void);   // 71: 16-bit TMRB input capture 71
void WEAK  INTCAP80_IRQHandler    (void);   // 72: 16-bit TMRB input capture 80
void WEAK  INTCAP81_IRQHandler    (void);   // 73: 16-bit TMRB input capture 81
void WEAK  INTCAP90_IRQHandler    (void);   // 74: 16-bit TMRB input capture 90
void WEAK  INTCAP91_IRQHandler    (void);   // 75: 16-bit TMRB input capture 91
void WEAK  INT8_IRQHandler        (void);   // 76: Interrupt pin 8
void WEAK  INT9_IRQHandler        (void);   // 77: Interrupt pin 9
void WEAK  INTA_IRQHandler        (void);   // 78: Interrupt pin A
void WEAK  INTB_IRQHandler        (void);   // 79: Interrupt pin B
void WEAK  INTDMAC0TC_IRQHandler  (void);   // 80: DMA terminal count status interrupt 0
void WEAK  INTDMAC1TC_IRQHandler  (void);   // 81: DMA terminal count status interrupt 1
void WEAK  INTDMAC0ERR_IRQHandler (void);   // 82: DMA error status interrupt 0
void WEAK  INTDMAC1ERR_IRQHandler (void);   // 83: DMA error status interrupt 1
void WEAK  INTSSP_IRQHandler      (void);   // 84: SPI serial interface

//*****************************************************************************
//
// Symbols defined in linker script
//
//*****************************************************************************
//
// Start address for the initialization values of the .data section.
//  
extern unsigned long _sidata;    

//
// Start address for the .data section 
//
extern unsigned long _sdata;     

//
// End address for the .data section
//
extern unsigned long _edata;     

//
// Start address for the .bss section
//
extern unsigned long _sbss;      

//
// End address for the .bss section
//
extern unsigned long _ebss;      

//
// End address for ram 
//
extern void _eram;               

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
extern int main(void);
extern void SystemInit(void);
__attribute__ ((used))
void ResetHandler(void);   
static void DefaultIntHandler(void);  

//
// The minimal vector table for a Cortex M3.  Note that the proper constructs
// must be placed on this to ensure that it ends up at physical address
// 0x00000000.
//  
__attribute__ ((used,section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void *)&pulStack[STACK_SIZE],          // The initial stack pointer
    ResetHandler                 ,          // The reset handler                        
    NMI_Handler                  ,          // The NMI handler                        
    HardFault_Handler            ,          // The hard fault handler                  
    MemManage_Handler            ,          // The MPU fault handler                  
    BusFault_Handler             ,          // The bus fault handler                   
    UsageFault_Handler           ,          // The usage fault handler                  
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    SVC_Handler                  ,          // SVCall handler                         
    DebugMon_Handler             ,          // Debug monitor handler                    
    0                            ,          // Reserved                                  
    PendSV_Handler               ,          // The PendSV handler                      
    SysTick_Handler              ,          // The SysTick handler                    
                                  
                                  
    INT0_IRQHandler              ,          // 0:  Interrupt Pin (PH0/AINA0/96pin or 98pin)
    INT1_IRQHandler              ,          // 1:  Interrupt pin 1
    INT2_IRQHandler              ,          // 2:  Interrupt pin 2
    INT3_IRQHandler              ,          // 3:  Interrupt pin 3
    INT4_IRQHandler              ,          // 4:  Interrupt pin 4
    INT5_IRQHandler              ,          // 5:  Interrupt pin 5
    INT6_IRQHandler              ,          // 6:  Interrupt pin 6
    INT7_IRQHandler              ,          // 7:  Interrupt pin 7
    INTRX0_IRQHandler            ,          // 8:  Serial reception (channel.0)
    INTTX0_IRQHandler            ,          // 9:  Serial transmission (channel.0)
    INTRX1_IRQHandler            ,          // 10: Serial reception (channel.1)
    INTTX1_IRQHandler            ,          // 11: Serial transmission (channel.1)
    INTRX2_IRQHandler            ,          // 12: Serial reception (channel.2)
    INTTX2_IRQHandler            ,          // 13: Serial transmission (channel.2)
    INTSBI0_IRQHandler           ,          // 14: Serial bus interface 0
    INTSBI1_IRQHandler           ,          // 15: Serial bus interface 1
    INTADHP_IRQHandler           ,          // 16: Highest priority AD conversion complete interrupt
    INTAD_IRQHandler             ,          // 17: AD conversion interrupt
    INTADM0_IRQHandler           ,          // 18: AD conversion monitoring function interrupt 0
    INTADM1_IRQHandler           ,          // 19: AD conversion monitoring function interrupt 1
    INTTB0_IRQHandler            ,          // 20: 16-bit TMRB match detection 0
    INTTB1_IRQHandler            ,          // 21: 16-bit TMRB match detection 1
    INTTB2_IRQHandler            ,          // 22: 16-bit TMRB match detection 2
    INTTB3_IRQHandler            ,          // 23: 16-bit TMRB match detection 3
    INTTB4_IRQHandler            ,          // 24: 16-bit TMRB match detection 4
    INTTB5_IRQHandler            ,          // 25: 16-bit TMRB match detection 5
    INTTB6_IRQHandler            ,          // 26: 16-bit TMRB match detection 6
    INTTB7_IRQHandler            ,          // 27: 16-bit TMRB match detection 7
    INTTB8_IRQHandler            ,          // 28: 16-bit TMRB match detection 8
    INTTB9_IRQHandler            ,          // 29: 16-bit TMRB match detection 9
    INTTD0CMP0_IRQHandler        ,          // 30: 16-bit TMRD0 compare interrupt 0
    INTTD0CMP1_IRQHandler        ,          // 31: 16-bit TMRD0 compare interrupt 1
    INTTD0CMP2_IRQHandler        ,          // 32: 16-bit TMRD0 compare interrupt 2
    INTTD0CMP3_IRQHandler        ,          // 33: 16-bit TMRD0 compare interrupt 3
    INTTD0CMP4_IRQHandler        ,          // 34: 16-bit TMRD0 compare interrupt 4
    INTTD1CMP0_IRQHandler        ,          // 35: 16-bit TMRD1 compare interrupt 0
    INTTD1CMP1_IRQHandler        ,          // 36: 16-bit TMRD1 compare interrupt 1
    INTTD1CMP2_IRQHandler        ,          // 37: 16-bit TMRD1 compare interrupt 2
    INTTD1CMP3_IRQHandler        ,          // 38: 16-bit TMRD1 compare interrupt 3
    INTTD1CMP4_IRQHandler        ,          // 39: 16-bit TMRD1 compare interrupt 4
    INTPHT00_IRQHandler          ,          // 40: 16-bit PHC compare interrupt 00
    INTPHT01_IRQHandler          ,          // 41: 16-bit PHC compare interrupt 01
    INTPHT10_IRQHandler          ,          // 42: 16-bit PHC compare interrupt 10
    INTPHT11_IRQHandler          ,          // 43: 16-bit PHC compare interrupt 11
    INTPHT20_IRQHandler          ,          // 44: 16-bit PHC compare interrupt 20
    INTPHT21_IRQHandler          ,          // 45: 16-bit PHC compare interrupt 21
    INTPHT30_IRQHandler          ,          // 46: 16-bit PHC compare interrupt 30
    INTPHT31_IRQHandler          ,          // 47: 16-bit PHC compare interrupt 31
    INTPHEVRY0_IRQHandler        ,          // 48: 16-bit PHC every count interrupt 0
    INTPHEVRY1_IRQHandler        ,          // 49: 16-bit PHC every count interrupt 1
    INTPHEVRY2_IRQHandler        ,          // 50: 16-bit PHC every count interrupt 2
    INTPHEVRY3_IRQHandler        ,          // 51: 16-bit PHC every count interrupt 3
    INTRX3_IRQHandler            ,          // 52: Serial reception (channel.3)
    INTTX3_IRQHandler            ,          // 53: Serial transmission (channel.3)
    INTRX4_IRQHandler            ,          // 54: Serial reception (channel.4)
    INTTX4_IRQHandler            ,          // 55: Serial transmission (channel.4)
    INTCAP00_IRQHandler          ,          // 56: 16-bit TMRB input capture 00
    INTCAP01_IRQHandler          ,          // 57: 16-bit TMRB input capture 01
    INTCAP10_IRQHandler          ,          // 58: 16-bit TMRB input capture 10
    INTCAP11_IRQHandler          ,          // 59: 16-bit TMRB input capture 11
    INTCAP20_IRQHandler          ,          // 60: 16-bit TMRB input capture 20
    INTCAP21_IRQHandler          ,          // 61: 16-bit TMRB input capture 21
    INTCAP30_IRQHandler          ,          // 62: 16-bit TMRB input capture 30
    INTCAP31_IRQHandler          ,          // 63: 16-bit TMRB input capture 31
    INTCAP40_IRQHandler          ,          // 64: 16-bit TMRB input capture 40
    INTCAP41_IRQHandler          ,          // 65: 16-bit TMRB input capture 41
    INTCAP50_IRQHandler          ,          // 66: 16-bit TMRB input capture 50
    INTCAP51_IRQHandler          ,          // 67: 16-bit TMRB input capture 51
    INTCAP60_IRQHandler          ,          // 68: 16-bit TMRB input capture 60
    INTCAP61_IRQHandler          ,          // 69: 16-bit TMRB input capture 61
    INTCAP70_IRQHandler          ,          // 70: 16-bit TMRB input capture 70
    INTCAP71_IRQHandler          ,          // 71: 16-bit TMRB input capture 71
    INTCAP80_IRQHandler          ,          // 72: 16-bit TMRB input capture 80
    INTCAP81_IRQHandler          ,          // 73: 16-bit TMRB input capture 81
    INTCAP90_IRQHandler          ,          // 74: 16-bit TMRB input capture 90
    INTCAP91_IRQHandler          ,          // 75: 16-bit TMRB input capture 91
    INT8_IRQHandler              ,          // 76: Interrupt pin 8
    INT9_IRQHandler              ,          // 77: Interrupt pin 9
    INTA_IRQHandler              ,          // 78: Interrupt pin A
    INTB_IRQHandler              ,          // 79: Interrupt pin B
    INTDMAC0TC_IRQHandler        ,          // 80: DMA terminal count status interrupt 0
    INTDMAC1TC_IRQHandler        ,          // 81: DMA terminal count status interrupt 1
    INTDMAC0ERR_IRQHandler       ,          // 82: DMA error status interrupt 0
    INTDMAC1ERR_IRQHandler       ,          // 83: DMA error status interrupt 1
    INTSSP_IRQHandler            ,          // 84: SPI serial interface

};

//*****************************************************************************
//
//! \brief This is the code that gets called when the processor first
//! starts execution following a reset event. 
//!
//! \param None.
//!
//! Only the absolutely necessary set is performed, after which the 
//! application supplied main() routine is called. 
//!
//! \return None.
//
//*****************************************************************************
void Default_ResetHandler(void)
{
    //
    // Initialize data and bss
    //
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM
    //
    pulSrc = &_sidata;

    for(pulDest = &_sdata; pulDest < &_edata; )
    {
        *(pulDest++) = *(pulSrc++);
    }

    //
    // Zero fill the bss segment.
    //
    for(pulDest = &_sbss; pulDest < &_ebss; )
    {
        *(pulDest++) = 0;
    }

    //
    // Call the application's entry point.
    //
    SystemInit();
    main();
}

//*****************************************************************************
//
// Provide weak aliases for each Exception handler to the DefaultIntHandler. 
// As they are weak aliases, any function with the same name will override 
// this definition.
//
//*****************************************************************************  

#pragma weak ResetHandler           = Default_ResetHandler 
#pragma weak NMI_Handler            = DefaultIntHandler 
#pragma weak HardFault_Handler      = DefaultIntHandler 
#pragma weak MemManage_Handler      = DefaultIntHandler 
#pragma weak BusFault_Handler       = DefaultIntHandler 
#pragma weak UsageFault_Handler     = DefaultIntHandler 
#pragma weak SVC_Handler            = DefaultIntHandler 
#pragma weak DebugMon_Handler       = DefaultIntHandler 
#pragma weak PendSV_Handler         = DefaultIntHandler 
#pragma weak SysTick_Handler        = DefaultIntHandler 

#pragma weak INT0_IRQHandler        = DefaultIntHandler   // 0:  Interrupt pin 0
#pragma weak INT1_IRQHandler        = DefaultIntHandler   // 1:  Interrupt pin 1
#pragma weak INT2_IRQHandler        = DefaultIntHandler   // 2:  Interrupt pin 2
#pragma weak INT3_IRQHandler        = DefaultIntHandler   // 3:  Interrupt pin 3
#pragma weak INT4_IRQHandler        = DefaultIntHandler   // 4:  Interrupt pin 4
#pragma weak INT5_IRQHandler        = DefaultIntHandler   // 5:  Interrupt pin 5
#pragma weak INT6_IRQHandler        = DefaultIntHandler   // 6:  Interrupt pin 6
#pragma weak INT7_IRQHandler        = DefaultIntHandler   // 7:  Interrupt pin 7
#pragma weak INTRX0_IRQHandler      = DefaultIntHandler   // 8:  Serial reception (channel.0)
#pragma weak INTTX0_IRQHandler      = DefaultIntHandler   // 9:  Serial transmission (channel.0)
#pragma weak INTRX1_IRQHandler      = DefaultIntHandler   // 10: Serial reception (channel.1)
#pragma weak INTTX1_IRQHandler      = DefaultIntHandler   // 11: Serial transmission (channel.1)
#pragma weak INTRX2_IRQHandler      = DefaultIntHandler   // 12: Serial reception (channel.2)
#pragma weak INTTX2_IRQHandler      = DefaultIntHandler   // 13: Serial transmission (channel.2)
#pragma weak INTSBI0_IRQHandler     = DefaultIntHandler   // 14: Serial bus interface 0
#pragma weak INTSBI1_IRQHandler     = DefaultIntHandler   // 15: Serial bus interface 1
#pragma weak INTADHP_IRQHandler     = DefaultIntHandler   // 16: Highest priority AD conversion complete interrupt
#pragma weak INTAD_IRQHandler       = DefaultIntHandler   // 17: AD conversion interrupt
#pragma weak INTADM0_IRQHandler     = DefaultIntHandler   // 18: AD conversion monitoring function interrupt 0
#pragma weak INTADM1_IRQHandler     = DefaultIntHandler   // 19: AD conversion monitoring function interrupt 1
#pragma weak INTTB0_IRQHandler      = DefaultIntHandler   // 20: 16-bit TMRB match detection 0
#pragma weak INTTB1_IRQHandler      = DefaultIntHandler   // 21: 16-bit TMRB match detection 1
#pragma weak INTTB2_IRQHandler      = DefaultIntHandler   // 22: 16-bit TMRB match detection 2
#pragma weak INTTB3_IRQHandler      = DefaultIntHandler   // 23: 16-bit TMRB match detection 3
#pragma weak INTTB4_IRQHandler      = DefaultIntHandler   // 24: 16-bit TMRB match detection 4
#pragma weak INTTB5_IRQHandler      = DefaultIntHandler   // 25: 16-bit TMRB match detection 5
#pragma weak INTTB6_IRQHandler      = DefaultIntHandler   // 26: 16-bit TMRB match detection 6
#pragma weak INTTB7_IRQHandler      = DefaultIntHandler   // 27: 16-bit TMRB match detection 7
#pragma weak INTTB8_IRQHandler      = DefaultIntHandler   // 28: 16-bit TMRB match detection 8
#pragma weak INTTB9_IRQHandler      = DefaultIntHandler   // 29: 16-bit TMRB match detection 9
#pragma weak INTTD0CMP0_IRQHandler  = DefaultIntHandler   // 30: 16-bit TMRD0 compare interrupt 0
#pragma weak INTTD0CMP1_IRQHandler  = DefaultIntHandler   // 31: 16-bit TMRD0 compare interrupt 1
#pragma weak INTTD0CMP2_IRQHandler  = DefaultIntHandler   // 32: 16-bit TMRD0 compare interrupt 2
#pragma weak INTTD0CMP3_IRQHandler  = DefaultIntHandler   // 33: 16-bit TMRD0 compare interrupt 3
#pragma weak INTTD0CMP4_IRQHandler  = DefaultIntHandler   // 34: 16-bit TMRD0 compare interrupt 4
#pragma weak INTTD1CMP0_IRQHandler  = DefaultIntHandler   // 35: 16-bit TMRD1 compare interrupt 0
#pragma weak INTTD1CMP1_IRQHandler  = DefaultIntHandler   // 36: 16-bit TMRD1 compare interrupt 1
#pragma weak INTTD1CMP2_IRQHandler  = DefaultIntHandler   // 37: 16-bit TMRD1 compare interrupt 2
#pragma weak INTTD1CMP3_IRQHandler  = DefaultIntHandler   // 38: 16-bit TMRD1 compare interrupt 3
#pragma weak INTTD1CMP4_IRQHandler  = DefaultIntHandler   // 39: 16-bit TMRD1 compare interrupt 4
#pragma weak INTPHT00_IRQHandler    = DefaultIntHandler   // 40: 16-bit PHC compare interrupt 00
#pragma weak INTPHT01_IRQHandler    = DefaultIntHandler   // 41: 16-bit PHC compare interrupt 01
#pragma weak INTPHT10_IRQHandler    = DefaultIntHandler   // 42: 16-bit PHC compare interrupt 10
#pragma weak INTPHT11_IRQHandler    = DefaultIntHandler   // 43: 16-bit PHC compare interrupt 11
#pragma weak INTPHT20_IRQHandler    = DefaultIntHandler   // 44: 16-bit PHC compare interrupt 20
#pragma weak INTPHT21_IRQHandler    = DefaultIntHandler   // 45: 16-bit PHC compare interrupt 21
#pragma weak INTPHT30_IRQHandler    = DefaultIntHandler   // 46: 16-bit PHC compare interrupt 30
#pragma weak INTPHT31_IRQHandler    = DefaultIntHandler   // 47: 16-bit PHC compare interrupt 31
#pragma weak INTPHEVRY0_IRQHandler  = DefaultIntHandler   // 48: 16-bit PHC every count interrupt 0
#pragma weak INTPHEVRY1_IRQHandler  = DefaultIntHandler   // 49: 16-bit PHC every count interrupt 1
#pragma weak INTPHEVRY2_IRQHandler  = DefaultIntHandler   // 50: 16-bit PHC every count interrupt 2
#pragma weak INTPHEVRY3_IRQHandler  = DefaultIntHandler   // 51: 16-bit PHC every count interrupt 3
#pragma weak INTRX3_IRQHandler      = DefaultIntHandler   // 52: Serial reception (channel.3)
#pragma weak INTTX3_IRQHandler      = DefaultIntHandler   // 53: Serial transmission (channel.3)
#pragma weak INTRX4_IRQHandler      = DefaultIntHandler   // 54: Serial reception (channel.4)
#pragma weak INTTX4_IRQHandler      = DefaultIntHandler   // 55: Serial transmission (channel.4)
#pragma weak INTCAP00_IRQHandler    = DefaultIntHandler   // 56: 16-bit TMRB input capture 00
#pragma weak INTCAP01_IRQHandler    = DefaultIntHandler   // 57: 16-bit TMRB input capture 01
#pragma weak INTCAP10_IRQHandler    = DefaultIntHandler   // 58: 16-bit TMRB input capture 10
#pragma weak INTCAP11_IRQHandler    = DefaultIntHandler   // 59: 16-bit TMRB input capture 11
#pragma weak INTCAP20_IRQHandler    = DefaultIntHandler   // 60: 16-bit TMRB input capture 20
#pragma weak INTCAP21_IRQHandler    = DefaultIntHandler   // 61: 16-bit TMRB input capture 21
#pragma weak INTCAP30_IRQHandler    = DefaultIntHandler   // 62: 16-bit TMRB input capture 30
#pragma weak INTCAP31_IRQHandler    = DefaultIntHandler   // 63: 16-bit TMRB input capture 31
#pragma weak INTCAP40_IRQHandler    = DefaultIntHandler   // 64: 16-bit TMRB input capture 40
#pragma weak INTCAP41_IRQHandler    = DefaultIntHandler   // 65: 16-bit TMRB input capture 41
#pragma weak INTCAP50_IRQHandler    = DefaultIntHandler   // 66: 16-bit TMRB input capture 50
#pragma weak INTCAP51_IRQHandler    = DefaultIntHandler   // 67: 16-bit TMRB input capture 51
#pragma weak INTCAP60_IRQHandler    = DefaultIntHandler   // 68: 16-bit TMRB input capture 60
#pragma weak INTCAP61_IRQHandler    = DefaultIntHandler   // 69: 16-bit TMRB input capture 61
#pragma weak INTCAP70_IRQHandler    = DefaultIntHandler   // 70: 16-bit TMRB input capture 70
#pragma weak INTCAP71_IRQHandler    = DefaultIntHandler   // 71: 16-bit TMRB input capture 71
#pragma weak INTCAP80_IRQHandler    = DefaultIntHandler   // 72: 16-bit TMRB input capture 80
#pragma weak INTCAP81_IRQHandler    = DefaultIntHandler   // 73: 16-bit TMRB input capture 81
#pragma weak INTCAP90_IRQHandler    = DefaultIntHandler   // 74: 16-bit TMRB input capture 90
#pragma weak INTCAP91_IRQHandler    = DefaultIntHandler   // 75: 16-bit TMRB input capture 91
#pragma weak INT8_IRQHandler        = DefaultIntHandler   // 76: Interrupt pin 8
#pragma weak INT9_IRQHandler        = DefaultIntHandler   // 77: Interrupt pin 9
#pragma weak INTA_IRQHandler        = DefaultIntHandler   // 78: Interrupt pin A
#pragma weak INTB_IRQHandler        = DefaultIntHandler   // 79: Interrupt pin B
#pragma weak INTDMAC0TC_IRQHandler  = DefaultIntHandler   // 80: DMA terminal count status interrupt 0
#pragma weak INTDMAC1TC_IRQHandler  = DefaultIntHandler   // 81: DMA terminal count status interrupt 1
#pragma weak INTDMAC0ERR_IRQHandler = DefaultIntHandler   // 82: DMA error status interrupt 0
#pragma weak INTDMAC1ERR_IRQHandler = DefaultIntHandler   // 83: DMA error status interrupt 1
#pragma weak INTSSP_IRQHandler      = DefaultIntHandler   // 84: SPI serial interface

//*****************************************************************************
//
//! \brief This is the code that gets called when the processor receives an 
//! unexpected interrupt.  
//!
//! \param None.
//!
//! This simply enters an infinite loop, preserving the system state for 
//! examination by a debugger.
//!
//! \return None.  
//*****************************************************************************  
static void DefaultIntHandler(void) 
{
    //
    // Go into an infinite loop.
    //
    while (1) 
    {
    }
}

