//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM33x Devices Startup code for CooCox CoIDE.
//!        (x can be 0,2,3)
//!        This module performs:
//!           - Set the initial SP
//!           - Set the vector table entries with the exceptions ISR address
//!           - Initialize data and bss
//!           - Setup the microcontroller system. 			
//!           - Call the application's entry point.
//!           .
//! \version V2.1.1.0
//! \date 5/8/2013
//! \author CooCox
//! \copy
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
void WEAK  ResetHandler         (void);
void WEAK  NMIIntHandler        (void);
void WEAK  HardFaultIntHandler  (void);
void WEAK  MemManageIntHandler  (void);
void WEAK  BusFaultIntHandler   (void);
void WEAK  UsageFaultIntHandler (void);
void WEAK  SVCIntHandler        (void);
void WEAK  DebugMonIntHandler   (void);
void WEAK  PendSVIntHandler     (void);
void WEAK  SysTickIntHandler    (void);

//External Interrupts
void WEAK  INT0_IRQHandler      (void);  //0:  Interrupt pin (PJ0/70pin)
void WEAK  INT1_IRQHandler      (void);  //1:  Interrupt pin (PJ1/49pin)
void WEAK  INT2_IRQHandler      (void);  //2:  Interrupt pin (PJ2/86pin)
void WEAK  INT3_IRQHandler      (void);  //3:  Interrupt pin (PJ3/87pin)
void WEAK  INT4_IRQHandler      (void);  //4:  Interrupt pin (PG3/6pin)
void WEAK  INT5_IRQHandler      (void);  //5:  Interrupt pin (PF7/19pin)
void WEAK  INTRX0_IRQHandler    (void);  //6:  Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler    (void);  //7:  Serial transmission (channel.0)
void WEAK  INTRX1_IRQHandler    (void);  //8:  Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler    (void);  //9:  Serial transmission (channel.1)
void WEAK  INTSBI0_IRQHandler   (void);  //10: Serial bus interface 0
void WEAK  INTSBI1_IRQHandler   (void);  //11: Serial bus interface 1
void WEAK  INTCECRX_IRQHandler  (void);  //12: CEC reception
void WEAK  INTCECTX_IRQHandler  (void);  //13: CEC transmission
void WEAK  INTRMCRX0_IRQHandler (void);  //14: Remote control signal reception (channel.0)
void WEAK  INTADHP_IRQHandler   (void);  //15: Highest priority AD conversion complete interrupt
void WEAK  INTADM0_IRQHandler   (void);  //16: AD conversion monitoring function interrupt 0
void WEAK  INTADM1_IRQHandler   (void);  //17: AD conversion monitoring function interrupt 1
void WEAK  INTTB0_IRQHandler    (void);  //18: 16-bit TMRB match detection 0
void WEAK  INTTB1_IRQHandler    (void);  //19: 16-bit TMRB match detection 1
void WEAK  INTTB2_IRQHandler    (void);  //20: 16-bit TMRB match detection 2
void WEAK  INTTB3_IRQHandler    (void);  //21: 16-bit TMRB match detection 3
void WEAK  INTTB4_IRQHandler    (void);  //22: 16-bit TMRB match detection 4
void WEAK  INTTB5_IRQHandler    (void);  //23: 16-bit TMRB match detection 5
void WEAK  INTTB6_IRQHandler    (void);  //24: 16-bit TMRB match detection 6
void WEAK  INTRTC_IRQHandler    (void);  //25: Real time clock timer
void WEAK  INTCAP00_IRQHandler  (void);  //26: 16-bit TMRB input capture 00
void WEAK  INTCAP01_IRQHandler  (void);  //27: 16-bit TMRB input capture 01
void WEAK  INTCAP10_IRQHandler  (void);  //28: 16-bit TMRB input capture 10
void WEAK  INTCAP11_IRQHandler  (void);  //29: 16-bit TMRB input capture 11
void WEAK  INTCAP50_IRQHandler  (void);  //30: 16-bit TMRB input capture 50
void WEAK  INTCAP51_IRQHandler  (void);  //31: 16-bit TMRB input capture 51
void WEAK  INTCAP60_IRQHandler  (void);  //32: 16-bit TMRB input capture 60
void WEAK  INTCAP61_IRQHandler  (void);  //33: 16-bit TMRB input capture 61
void WEAK  INT6_IRQHandler      (void);  //34: Interrupt pin (PJ6/39 pin)
void WEAK  INT7_IRQHandler      (void);  //35: Interrupt pin (PJ7/58 pin)
void WEAK  INTRX2_IRQHandler    (void);  //36: Serial reception (channel.2)
void WEAK  INTTX2_IRQHandler    (void);  //37: Serial transmission (channel.2)
void WEAK  INTSBI2_IRQHandler   (void);  //38: Serial bus interface 2
void WEAK  INTRMCRX1_IRQHandler (void);  //39: Remote control signal reception (channel.1)
void WEAK  INTTB7_IRQHandler    (void);  //40: 16-bit TMRB match detection 7
void WEAK  INTTB8_IRQHandler    (void);  //41: 16-bit TMRB match detection 8
void WEAK  INTTB9_IRQHandler    (void);  //42: 16-bit TMRB match detection 9
void WEAK  INTCAP20_IRQHandler  (void);  //43: 16-bit TMRB input capture 20
void WEAK  INTCAP21_IRQHandler  (void);  //44: 16-bit TMRB input capture 21
void WEAK  INTCAP30_IRQHandler  (void);  //45: 16-bit TMRB input capture 30
void WEAK  INTCAP31_IRQHandler  (void);  //46: 16-bit TMRB input capture 31
void WEAK  INTCAP40_IRQHandler  (void);  //47: 16-bit TMRB input capture 40
void WEAK  INTCAP41_IRQHandler  (void);  //48: 16-bit TMRB input capture 41
void WEAK  INTAD_IRQHandler     (void);  //49: A/D conversion completion


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
    NMIIntHandler                ,          // The NMI handler                        
    HardFaultIntHandler          ,          // The hard fault handler                  
    MemManageIntHandler          ,          // The MPU fault handler                  
    BusFaultIntHandler           ,          // The bus fault handler                   
    UsageFaultIntHandler         ,          // The usage fault handler                  
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    0                            ,          // Reserved                            
    SVCIntHandler                ,          // SVCall handler                         
    DebugMonIntHandler           ,          // Debug monitor handler                    
    0                            ,          // Reserved                                  
    PendSVIntHandler             ,          // The PendSV handler                      
    SysTickIntHandler            ,          // The SysTick handler                    
                                  
    //External Interrupts
    INT0_IRQHandler              ;          //0:  Interrupt pin (PJ0/70pin)
    INT1_IRQHandler              ;          //1:  Interrupt pin (PJ1/49pin)
    INT2_IRQHandler              ;          //2:  Interrupt pin (PJ2/86pin)
    INT3_IRQHandler              ;          //3:  Interrupt pin (PJ3/87pin)
    INT4_IRQHandler              ;          //4:  Interrupt pin (PG3/6pin)
    INT5_IRQHandler              ;          //5:  Interrupt pin (PF7/19pin)
    INTRX0_IRQHandler            ;          //6:  Serial reception (channel.0)
    INTTX0_IRQHandler            ;          //7:  Serial transmission (channel.0)
    INTRX1_IRQHandler            ;          //8:  Serial reception (channel.1)
    INTTX1_IRQHandler            ;          //9:  Serial transmission (channel.1)
    INTSBI0_IRQHandler           ;          //10: Serial bus interface 0
    INTSBI1_IRQHandler           ;          //11: Serial bus interface 1
    INTCECRX_IRQHandler          ;          //12: CEC reception
    INTCECTX_IRQHandler          ;          //13: CEC transmission
    INTRMCRX0_IRQHandler         ;          //14: Remote control signal reception (channel.0)
    INTADHP_IRQHandler           ;          //15: Highest priority AD conversion complete interrupt
    INTADM0_IRQHandler           ;          //16: AD conversion monitoring function interrupt 0
    INTADM1_IRQHandler           ;          //17: AD conversion monitoring function interrupt 1
    INTTB0_IRQHandler            ;          //18: 16-bit TMRB match detection 0
    INTTB1_IRQHandler            ;          //19: 16-bit TMRB match detection 1
    INTTB2_IRQHandler            ;          //20: 16-bit TMRB match detection 2
    INTTB3_IRQHandler            ;          //21: 16-bit TMRB match detection 3
    INTTB4_IRQHandler            ;          //22: 16-bit TMRB match detection 4
    INTTB5_IRQHandler            ;          //23: 16-bit TMRB match detection 5
    INTTB6_IRQHandler            ;          //24: 16-bit TMRB match detection 6
    INTRTC_IRQHandler            ;          //25: Real time clock timer
    INTCAP00_IRQHandler          ;          //26: 16-bit TMRB input capture 00
    INTCAP01_IRQHandler          ;          //27: 16-bit TMRB input capture 01
    INTCAP10_IRQHandler          ;          //28: 16-bit TMRB input capture 10
    INTCAP11_IRQHandler          ;          //29: 16-bit TMRB input capture 11
    INTCAP50_IRQHandler          ;          //30: 16-bit TMRB input capture 50
    INTCAP51_IRQHandler          ;          //31: 16-bit TMRB input capture 51
    INTCAP60_IRQHandler          ;          //32: 16-bit TMRB input capture 60
    INTCAP61_IRQHandler          ;          //33: 16-bit TMRB input capture 61
    INT6_IRQHandler              ;          //34: Interrupt pin (PJ6/39 pin)
    INT7_IRQHandler              ;          //35: Interrupt pin (PJ7/58 pin)
    INTRX2_IRQHandler            ;          //36: Serial reception (channel.2)
    INTTX2_IRQHandler            ;          //37: Serial transmission (channel.2)
    INTSBI2_IRQHandler           ;          //38: Serial bus interface 2
    INTRMCRX1_IRQHandler         ;          //39: Remote control signal reception (channel.1)
    INTTB7_IRQHandler            ;          //40: 16-bit TMRB match detection 7
    INTTB8_IRQHandler            ;          //41: 16-bit TMRB match detection 8
    INTTB9_IRQHandler            ;          //42: 16-bit TMRB match detection 9
    INTCAP20_IRQHandler          ;          //43: 16-bit TMRB input capture 20
    INTCAP21_IRQHandler          ;          //44: 16-bit TMRB input capture 21
    INTCAP30_IRQHandler          ;          //45: 16-bit TMRB input capture 30
    INTCAP31_IRQHandler          ;          //46: 16-bit TMRB input capture 31
    INTCAP40_IRQHandler          ;          //47: 16-bit TMRB input capture 40
    INTCAP41_IRQHandler          ;          //48: 16-bit TMRB input capture 41
    INTAD_IRQHandler             ;          //49: A/D conversion completion

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

#pragma weak ResetHandler         = Default_ResetHandler 
#pragma weak NMIIntHandler        = DefaultIntHandler 
#pragma weak HardFaultIntHandler  = DefaultIntHandler 
#pragma weak MemManageIntHandler  = DefaultIntHandler 
#pragma weak BusFaultIntHandler   = DefaultIntHandler 
#pragma weak UsageFaultIntHandler = DefaultIntHandler 
#pragma weak SVCIntHandler        = DefaultIntHandler 
#pragma weak DebugMonIntHandler   = DefaultIntHandler 
#pragma weak PendSVIntHandler     = DefaultIntHandler 
#pragma weak SysTickIntHandler    = DefaultIntHandler 

#pragma weak INT0_IRQHandler      = DefaultIntHandler 
#pragma weak INT1_IRQHandler      = DefaultIntHandler 
#pragma weak INT2_IRQHandler      = DefaultIntHandler 
#pragma weak INT3_IRQHandler      = DefaultIntHandler 
#pragma weak INT4_IRQHandler      = DefaultIntHandler 
#pragma weak INT5_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX0_IRQHandler    = DefaultIntHandler 
#pragma weak INTTX0_IRQHandler    = DefaultIntHandler 
#pragma weak INTRX1_IRQHandler    = DefaultIntHandler 
#pragma weak INTTX1_IRQHandler    = DefaultIntHandler 
#pragma weak INTSBI0_IRQHandler   = DefaultIntHandler 
#pragma weak INTSBI1_IRQHandler   = DefaultIntHandler 
#pragma weak INTCECRX_IRQHandler  = DefaultIntHandler 
#pragma weak INTCECTX_IRQHandler  = DefaultIntHandler 
#pragma weak INTRMCRX0_IRQHandler = DefaultIntHandler 
#pragma weak INTADHP_IRQHandler   = DefaultIntHandler 
#pragma weak INTADM0_IRQHandler   = DefaultIntHandler 
#pragma weak INTADM1_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB0_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB1_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB2_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB3_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB4_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB5_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB6_IRQHandler    = DefaultIntHandler 
#pragma weak INTRTC_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP00_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP01_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP10_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP11_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP50_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP51_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP60_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP61_IRQHandler  = DefaultIntHandler 
#pragma weak INT6_IRQHandler      = DefaultIntHandler 
#pragma weak INT7_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX2_IRQHandler    = DefaultIntHandler 
#pragma weak INTTX2_IRQHandler    = DefaultIntHandler 
#pragma weak INTSBI2_IRQHandler   = DefaultIntHandler 
#pragma weak INTRMCRX1_IRQHandler = DefaultIntHandler 
#pragma weak INTTB7_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB8_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB9_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP20_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP21_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP30_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP31_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP40_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP41_IRQHandler  = DefaultIntHandler 
#pragma weak INTAD_IRQHandler     = DefaultIntHandler 


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

