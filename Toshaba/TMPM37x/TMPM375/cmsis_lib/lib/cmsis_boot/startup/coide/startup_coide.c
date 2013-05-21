//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM375 Devices Startup code for CooCox CoIDE.
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
#define STACK_SIZE       0x00000400
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

// External Interrupts
void WEAK INTRX0_IRQHandler     (void); //0:    Serial reception (channel.0)
void WEAK INTTX0_IRQHandler     (void); //1:    Serial transmit (channel.0)
void WEAK INTRX1_IRQHandler     (void); //2:    Serial reception (channel.1)
void WEAK INTTX1_IRQHandler     (void); //3:    Serial transmit (channel.1)
void WEAK INTVCNB_IRQHandler    (void); //4:    Vector Engine interrupt B
void WEAK INTEMG1_IRQHandler    (void); //5:    PMD1 EMG interrupt
void WEAK INTOVV1_IRQHandler    (void); //6:    PMD1 OVV interrupt
void WEAK INTADBPDB_IRQHandler  (void); //7:    ADCB conversion triggered by PMD1 is finished
void WEAK INTTB00_IRQHandler    (void); //8:    16bit TMRB0 compare match detection 0/ Over flow
void WEAK INTTB01_IRQHandler    (void); //9:    16bit TMRB0 compare match detection 1
void WEAK INTTB40_IRQHandler    (void); //10:   16bit TMRB4 compare match detection 0/ Over flow
void WEAK INTTB41_IRQHandler    (void); //11:   16bit TMRB4 compare match detection 1
void WEAK INTTB50_IRQHandler    (void); //12:   16bit TMRB5 compare match detection 0/ Over flow
void WEAK INTTB51_IRQHandler    (void); //13:   16bit TMRB5 compare match detection 1
void WEAK INTPMD1_IRQHandler    (void); //14:   PMD1 PWM interrupt
void WEAK INTCAP00_IRQHandler   (void); //15:   16bit TMRB0 input capture 0
void WEAK INTCAP01_IRQHandler   (void); //16:   16bit TMRB0 input capture 1
void WEAK INTCAP50_IRQHandler   (void); //17:   16bit TMRB5 input capture 0
void WEAK INTCAP51_IRQHandler   (void); //18:   16bit TMRB5 input capture 1
void WEAK INT6_IRQHandler       (void); //19:   Interrupt Pin (PE6/TB3IN//17pin or 19pin)
void WEAK INT7_IRQHandler       (void); //20:   Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
void WEAK INTADBCPA_IRQHandler  (void); //21:   ADCB conversion monitoring function interrupt A
void WEAK INTADBCPB_IRQHandler  (void); //22:   ADCB conversion monitoring function interrupt B
void WEAK INTADBSFT_IRQHandler  (void); //23:   ADC1 conversion started by software is finished
void WEAK INTADBTMR_IRQHandler  (void); //24:   ADC1 conversion triggered by timer is finished
void WEAK INTENC0_IRQHandler    (void); //25:   Ender input0 interrupt
void WEAK INTTB70_IRQHandler    (void); //26:   16bit TMRB7 compare match detection 0 / Over flow
void WEAK INTTB71_IRQHandler    (void); //27:   16bit TMRB7 compare match detection 1
void WEAK INTCAP70_IRQHandler   (void); //28:   16bit TMRB7 input capture 0
void WEAK INTCAP71_IRQHandler   (void); //29:   16bit TMRB7 input capture 1
void WEAK INTC_IRQHandler       (void); //30:   Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
void WEAK INTSBI0_IRQHandler    (void); //31:   Serial Bus Interface0


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


    // External Interrupts
    INTRX0_IRQHandler            ,          //0: Serial reception (channel.0)
    INTTX0_IRQHandler            ,          //1: Serial transmit (channel.0)
    INTRX1_IRQHandler            ,          //2: Serial reception (channel.1)
    INTTX1_IRQHandler            ,          //3: Serial transmit (channel.1)
    INTVCNB_IRQHandler           ,          //4: Vector Engine interrupt B
    INTEMG1_IRQHandler           ,          //5: PMD1 EMG interrupt
    INTOVV1_IRQHandler           ,          //6: PMD1 OVV interrupt
    INTADBPDB_IRQHandler         ,          //7: ADCB conversion triggered by PMD1 is finished
    INTTB00_IRQHandler           ,          //8: 16bit TMRB0 compare match detection 0/ Over flow
    INTTB01_IRQHandler           ,          //9: 16bit TMRB0 compare match detection 1
    INTTB40_IRQHandler           ,          //10:    16bit TMRB4 compare match detection 0/ Over flow
    INTTB41_IRQHandler           ,          //11:    16bit TMRB4 compare match detection 1
    INTTB50_IRQHandler           ,          //12:    16bit TMRB5 compare match detection 0/ Over flow
    INTTB51_IRQHandler           ,          //13:    16bit TMRB5 compare match detection 1
    INTPMD1_IRQHandler           ,          //14:    PMD1 PWM interrupt
    INTCAP00_IRQHandler          ,          //15:    16bit TMRB0 input capture 0
    INTCAP01_IRQHandler          ,          //16:    16bit TMRB0 input capture 1
    INTCAP50_IRQHandler          ,          //17:    16bit TMRB5 input capture 0
    INTCAP51_IRQHandler          ,          //18:    16bit TMRB5 input capture 1
    INT6_IRQHandler              ,          //19:    Interrupt Pin (PE6/TB3IN//17pin or 19pin)
    INT7_IRQHandler              ,          //20:    Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
    INTADBCPA_IRQHandler         ,          //21:    ADCB conversion monitoring function interrupt A
    INTADBCPB_IRQHandler         ,          //22:    ADCB conversion monitoring function interrupt B
    INTADBSFT_IRQHandler         ,          //23:    ADC1 conversion started by software is finished
    INTADBTMR_IRQHandler         ,          //24:    ADC1 conversion triggered by timer is finished
    INTENC0_IRQHandler           ,          //25:    Ender input0 interrupt
    INTTB70_IRQHandler           ,          //26:    16bit TMRB7 compare match detection 0 / Over flow
    INTTB71_IRQHandler           ,          //27:    16bit TMRB7 compare match detection 1
    INTCAP70_IRQHandler          ,          //28:    16bit TMRB7 input capture 0
    INTCAP71_IRQHandler          ,          //29:    16bit TMRB7 input capture 1
    INTC_IRQHandler              ,          //30:    Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
    INTSBI0_IRQHandler           ,          //31:    Serial Bus Interface0

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

#pragma weak INTRX0_IRQHandler    = DefaultIntHandler
#pragma weak INTTX0_IRQHandler    = DefaultIntHandler
#pragma weak INTRX1_IRQHandler    = DefaultIntHandler
#pragma weak INTTX1_IRQHandler    = DefaultIntHandler
#pragma weak INTVCNB_IRQHandler   = DefaultIntHandler
#pragma weak INTEMG1_IRQHandler   = DefaultIntHandler
#pragma weak INTOVV1_IRQHandler   = DefaultIntHandler
#pragma weak INTADBPDB_IRQHandler = DefaultIntHandler
#pragma weak INTTB00_IRQHandler   = DefaultIntHandler
#pragma weak INTTB01_IRQHandler   = DefaultIntHandler
#pragma weak INTTB40_IRQHandler   = DefaultIntHandler
#pragma weak INTTB41_IRQHandler   = DefaultIntHandler
#pragma weak INTTB50_IRQHandler   = DefaultIntHandler
#pragma weak INTTB51_IRQHandler   = DefaultIntHandler
#pragma weak INTPMD1_IRQHandler   = DefaultIntHandler
#pragma weak INTCAP00_IRQHandler  = DefaultIntHandler
#pragma weak INTCAP01_IRQHandler  = DefaultIntHandler
#pragma weak INTCAP50_IRQHandler  = DefaultIntHandler
#pragma weak INTCAP51_IRQHandler  = DefaultIntHandler
#pragma weak INT6_IRQHandler      = DefaultIntHandler
#pragma weak INT7_IRQHandler      = DefaultIntHandler
#pragma weak INTADBCPA_IRQHandler = DefaultIntHandler
#pragma weak INTADBCPB_IRQHandler = DefaultIntHandler
#pragma weak INTADBSFT_IRQHandler = DefaultIntHandler
#pragma weak INTADBTMR_IRQHandler = DefaultIntHandler
#pragma weak INTENC0_IRQHandler   = DefaultIntHandler
#pragma weak INTTB70_IRQHandler   = DefaultIntHandler
#pragma weak INTTB71_IRQHandler   = DefaultIntHandler
#pragma weak INTCAP70_IRQHandler  = DefaultIntHandler
#pragma weak INTCAP71_IRQHandler  = DefaultIntHandler
#pragma weak INTC_IRQHandler      = DefaultIntHandler
#pragma weak INTSBI0_IRQHandler   = DefaultIntHandler


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

