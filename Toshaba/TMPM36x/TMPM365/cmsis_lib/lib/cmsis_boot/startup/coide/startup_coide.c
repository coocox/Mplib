//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM365 Devices Startup code for CooCox CoIDE.
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
void WEAK  ResetHandler          (void);
void WEAK  NMIIntHandler         (void);
void WEAK  HardFaultIntHandler   (void);
void WEAK  MemManageIntHandler   (void);
void WEAK  BusFaultIntHandler    (void);
void WEAK  UsageFaultIntHandler  (void);
void WEAK  SVCIntHandler         (void);
void WEAK  DebugMonIntHandler    (void);
void WEAK  PendSVIntHandler      (void);
void WEAK  SysTickIntHandler     (void);

// External Interrupts
void WEAK  INT0_IRQHandler       (void); //0:  Interrupt pin 0
void WEAK  INT1_IRQHandler       (void); //1:  Interrupt pin 1
void WEAK  INT2_IRQHandler       (void); //2:  Interrupt pin 2
void WEAK  INT3_IRQHandler       (void); //3:  Interrupt pin 3
void WEAK  INT4_IRQHandler       (void); //4:  Interrupt pin 4
void WEAK  INT5_IRQHandler       (void); //5:  Interrupt pin 5
void WEAK  INT6_IRQHandler       (void); //6:  Interrupt pin 6
void WEAK  INT7_IRQHandler       (void); //7:  Interrupt pin 7
void WEAK  INTRX0_IRQHandler     (void); //8:  Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler     (void); //9:  Serial transmission (channel.0)
void WEAK  INTRX1_IRQHandler     (void); //10: Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler     (void); //11: Serial transmission (channel.1)
void WEAK  INTUSBWKUP_IRQHandler (void); //12: USB WakeUp
void WEAK  INTSBI0_IRQHandler    (void); //14: Serial bus interface 0
void WEAK  INTSBI1_IRQHandler    (void); //15: Serial bus interface 1
void WEAK  INTADHP_IRQHandler    (void); //16: Highest priority AD conversion complete interrupt
void WEAK  INTAD_IRQHandler      (void); //17: AD conversion interrupt
void WEAK  INTADM0_IRQHandler    (void); //18: AD conversion monitoring function interrupt 0
void WEAK  INTADM1_IRQHandler    (void); //19: AD conversion monitoring function interrupt 1
void WEAK  INTTB0_IRQHandler     (void); //20: 16-bit TMRB match detection 0
void WEAK  INTTB1_IRQHandler     (void); //21: 16-bit TMRB match detection 1
void WEAK  INTTB2_IRQHandler     (void); //22: 16-bit TMRB match detection 2
void WEAK  INTTB3_IRQHandler     (void); //23: 16-bit TMRB match detection 3
void WEAK  INTTB4_IRQHandler     (void); //24: 16-bit TMRB match detection 4
void WEAK  INTTB5_IRQHandler     (void); //25: 16-bit TMRB match detection 5
void WEAK  INTTB6_IRQHandler     (void); //26: 16-bit TMRB match detection 6
void WEAK  INTTB7_IRQHandler     (void); //27: 16-bit TMRB match detection 7
void WEAK  INTTB8_IRQHandler     (void); //28: 16-bit TMRB match detection 8
void WEAK  INTTB9_IRQHandler     (void); //29: 16-bit TMRB match detection 9
void WEAK  INTUSB_IRQHandler     (void); //30: USB Interrupt
void WEAK  INTUSBPON_IRQHandler  (void); //34: USB Power On connection detectioninterrupt
void WEAK  INTCAP00_IRQHandler   (void); //36: 16-bit TMRB0 input capture 0
void WEAK  INTCAP01_IRQHandler   (void); //37: 16-bit TMRB0 input capture 1
void WEAK  INTCAP10_IRQHandler   (void); //38: 16-bit TMRB1 input capture 0
void WEAK  INTCAP11_IRQHandler   (void); //39: 16-bit TMRB1 input capture 1
void WEAK  INTCAP20_IRQHandler   (void); //40: 16-bit TMRB2 input capture 0
void WEAK  INTCAP21_IRQHandler   (void); //41: 16-bit TMRB2 input capture 1
void WEAK  INTCAP30_IRQHandler   (void); //42: 16-bit TMRB3 input capture 0
void WEAK  INTCAP31_IRQHandler   (void); //43: 16-bit TMRB3 input capture 1
void WEAK  INTCAP40_IRQHandler   (void); //44: 16-bit TMRB4 input capture 0
void WEAK  INTCAP41_IRQHandler   (void); //45: 16-bit TMRB4 input capture 1
void WEAK  INTCAP50_IRQHandler   (void); //46: 16-bit TMRB5 input capture 0
void WEAK  INTCAP51_IRQHandler   (void); //47: 16-bit TMRB5 input capture 1
void WEAK  INTCAP60_IRQHandler   (void); //48: 16-bit TMRB6 input capture 0
void WEAK  INTCAP61_IRQHandler   (void); //49: 16-bit TMRB6 input capture 1
void WEAK  INTCAP70_IRQHandler   (void); //50: 16-bit TMRB7 input capture 0
void WEAK  INTCAP71_IRQHandler   (void); //51: 16-bit TMRB7 input capture 1
void WEAK  INTCAP80_IRQHandler   (void); //52: 16-bit TMRB8 input capture 0
void WEAK  INTCAP81_IRQHandler   (void); //53: 16-bit TMRB8 input capture 1
void WEAK  INTCAP90_IRQHandler   (void); //54: 16-bit TMRB9 input capture 0
void WEAK  INTCAP91_IRQHandler   (void); //55: 16-bit TMRB9 input capture 1
void WEAK  INT8_IRQHandler       (void); //56: Interrupt pin 8
void WEAK  INT9_IRQHandler       (void); //57: Interrupt pin 9
void WEAK  INTDMAC0TC_IRQHandler (void); //60: DMA terminal count status interrupt 0
void WEAK  INTABTLOSS0_IRQHandler(void); //61: I2C arbitration lost interrupt 0
void WEAK  INTDMAC0ERR_IRQHandler(void); //62: DMA error status interrupt 0
void WEAK  INTABTLOSS1_IRQHandler(void); //63: I2C arbitration lost interrupt 1

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
    (void *)&pulStack[STACK_SIZE], // The initial stack pointer
    ResetHandler                 , // The reset handler
    NMIIntHandler                , // The NMI handler
    HardFaultIntHandler          , // The hard fault handler
    MemManageIntHandler          , // The MPU fault handler
    BusFaultIntHandler           , // The bus fault handler
    UsageFaultIntHandler         , // The usage fault handler
    0                            , // Reserved
    0                            , // Reserved
    0                            , // Reserved
    0                            , // Reserved
    SVCIntHandler                , // SVCall handler
    DebugMonIntHandler           , // Debug monitor handler
    0                            , // Reserved
    PendSVIntHandler             , // The PendSV handler
    SysTickIntHandler            , // The SysTick handler

    // External Interrupts
    INT0_IRQHandler              , //0:  Interrupt pin 0
    INT1_IRQHandler              , //1:  Interrupt pin 1
    INT2_IRQHandler              , //2:  Interrupt pin 2
    INT3_IRQHandler              , //3:  Interrupt pin 3
    INT4_IRQHandler              , //4:  Interrupt pin 4
    INT5_IRQHandler              , //5:  Interrupt pin 5
    INT6_IRQHandler              , //6:  Interrupt pin 6
    INT7_IRQHandler              , //7:  Interrupt pin 7
    INTRX0_IRQHandler            , //8:  Serial reception (channel.0)
    INTTX0_IRQHandler            , //9:  Serial transmission (channel.0)
    INTRX1_IRQHandler            , //10: Serial reception (channel.1)
    INTTX1_IRQHandler            , //11: Serial transmission (channel.1)
    INTUSBWKUP_IRQHandler        , //12: USB WakeUp
    0                            , //13: Reserved
    INTSBI0_IRQHandler           , //14: Serial bus interface 0
    INTSBI1_IRQHandler           , //15: Serial bus interface 1
    INTADHP_IRQHandler           , //16: Highest priority AD conversion complete interrupt
    INTAD_IRQHandler             , //17: AD conversion interrupt
    INTADM0_IRQHandler           , //18: AD conversion monitoring function interrupt 0
    INTADM1_IRQHandler           , //19: AD conversion monitoring function interrupt 1
    INTTB0_IRQHandler            , //20: 16-bit TMRB match detection 0
    INTTB1_IRQHandler            , //21: 16-bit TMRB match detection 1
    INTTB2_IRQHandler            , //22: 16-bit TMRB match detection 2
    INTTB3_IRQHandler            , //23: 16-bit TMRB match detection 3
    INTTB4_IRQHandler            , //24: 16-bit TMRB match detection 4
    INTTB5_IRQHandler            , //25: 16-bit TMRB match detection 5
    INTTB6_IRQHandler            , //26: 16-bit TMRB match detection 6
    INTTB7_IRQHandler            , //27: 16-bit TMRB match detection 7
    INTTB8_IRQHandler            , //28: 16-bit TMRB match detection 8
    INTTB9_IRQHandler            , //29: 16-bit TMRB match detection 9
    INTUSB_IRQHandler            , //30: USB Interrupt
    0                            , //31: Reserved
    0                            , //32: Reserved
    0                            , //33: Reserved
    INTUSBPON_IRQHandler         , //34: USB Power On connection detectioninterrupt
    0                            , //35: Reserved
    INTCAP00_IRQHandler          , //36: 16-bit TMRB0 input capture 0
    INTCAP01_IRQHandler          , //37: 16-bit TMRB0 input capture 1
    INTCAP10_IRQHandler          , //38: 16-bit TMRB1 input capture 0
    INTCAP11_IRQHandler          , //39: 16-bit TMRB1 input capture 1
    INTCAP20_IRQHandler          , //40: 16-bit TMRB2 input capture 0
    INTCAP21_IRQHandler          , //41: 16-bit TMRB2 input capture 1
    INTCAP30_IRQHandler          , //42: 16-bit TMRB3 input capture 0
    INTCAP31_IRQHandler          , //43: 16-bit TMRB3 input capture 1
    INTCAP40_IRQHandler          , //44: 16-bit TMRB4 input capture 0
    INTCAP41_IRQHandler          , //45: 16-bit TMRB4 input capture 1
    INTCAP50_IRQHandler          , //46: 16-bit TMRB5 input capture 0
    INTCAP51_IRQHandler          , //47: 16-bit TMRB5 input capture 1
    INTCAP60_IRQHandler          , //48: 16-bit TMRB6 input capture 0
    INTCAP61_IRQHandler          , //49: 16-bit TMRB6 input capture 1
    INTCAP70_IRQHandler          , //50: 16-bit TMRB7 input capture 0
    INTCAP71_IRQHandler          , //51: 16-bit TMRB7 input capture 1
    INTCAP80_IRQHandler          , //52: 16-bit TMRB8 input capture 0
    INTCAP81_IRQHandler          , //53: 16-bit TMRB8 input capture 1
    INTCAP90_IRQHandler          , //54: 16-bit TMRB9 input capture 0
    INTCAP91_IRQHandler          , //55: 16-bit TMRB9 input capture 1
    INT8_IRQHandler              , //56: Interrupt pin 8
    INT9_IRQHandler              , //57: Interrupt pin 9
    0                            , //58: Reserved
    0                            , //59: Reserved
    INTDMAC0TC_IRQHandler        , //60: DMA terminal count status interrupt 0
    INTABTLOSS0_IRQHandler       , //61: I2C arbitration lost interrupt 0
    INTDMAC0ERR_IRQHandler       , //62: DMA error status interrupt 0
    INTABTLOSS1_IRQHandler       , //63: I2C arbitration lost interrupt 1

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
#pragma weak NMIIntHandler          = DefaultIntHandler
#pragma weak HardFaultIntHandler    = DefaultIntHandler
#pragma weak MemManageIntHandler    = DefaultIntHandler
#pragma weak BusFaultIntHandler     = DefaultIntHandler
#pragma weak UsageFaultIntHandler   = DefaultIntHandler
#pragma weak SVCIntHandler          = DefaultIntHandler
#pragma weak DebugMonIntHandler     = DefaultIntHandler
#pragma weak PendSVIntHandler       = DefaultIntHandler
#pragma weak SysTickIntHandler      = DefaultIntHandler

#pragma weak INT0_IRQHandler        = DefaultIntHandler
#pragma weak INT1_IRQHandler        = DefaultIntHandler
#pragma weak INT2_IRQHandler        = DefaultIntHandler
#pragma weak INT3_IRQHandler        = DefaultIntHandler
#pragma weak INT4_IRQHandler        = DefaultIntHandler
#pragma weak INT5_IRQHandler        = DefaultIntHandler
#pragma weak INT6_IRQHandler        = DefaultIntHandler
#pragma weak INT7_IRQHandler        = DefaultIntHandler
#pragma weak INTRX0_IRQHandler      = DefaultIntHandler
#pragma weak INTTX0_IRQHandler      = DefaultIntHandler
#pragma weak INTRX1_IRQHandler      = DefaultIntHandler
#pragma weak INTTX1_IRQHandler      = DefaultIntHandler
#pragma weak INTUSBWKUP_IRQHandler  = DefaultIntHandler
#pragma weak INTSBI0_IRQHandler     = DefaultIntHandler
#pragma weak INTSBI1_IRQHandler     = DefaultIntHandler
#pragma weak INTADHP_IRQHandler     = DefaultIntHandler
#pragma weak INTAD_IRQHandler       = DefaultIntHandler
#pragma weak INTADM0_IRQHandler     = DefaultIntHandler
#pragma weak INTADM1_IRQHandler     = DefaultIntHandler
#pragma weak INTTB0_IRQHandler      = DefaultIntHandler
#pragma weak INTTB1_IRQHandler      = DefaultIntHandler
#pragma weak INTTB2_IRQHandler      = DefaultIntHandler
#pragma weak INTTB3_IRQHandler      = DefaultIntHandler
#pragma weak INTTB4_IRQHandler      = DefaultIntHandler
#pragma weak INTTB5_IRQHandler      = DefaultIntHandler
#pragma weak INTTB6_IRQHandler      = DefaultIntHandler
#pragma weak INTTB7_IRQHandler      = DefaultIntHandler
#pragma weak INTTB8_IRQHandler      = DefaultIntHandler
#pragma weak INTTB9_IRQHandler      = DefaultIntHandler
#pragma weak INTUSB_IRQHandler      = DefaultIntHandler
#pragma weak INTUSBPON_IRQHandler   = DefaultIntHandler
#pragma weak INTCAP00_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP01_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP10_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP11_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP20_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP21_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP30_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP31_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP40_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP41_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP50_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP51_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP60_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP61_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP70_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP71_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP80_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP81_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP90_IRQHandler    = DefaultIntHandler
#pragma weak INTCAP91_IRQHandler    = DefaultIntHandler
#pragma weak INT8_IRQHandler        = DefaultIntHandler
#pragma weak INT9_IRQHandler        = DefaultIntHandler
#pragma weak INTDMAC0TC_IRQHandler  = DefaultIntHandler
#pragma weak INTABTLOSS0_IRQHandler = DefaultIntHandler
#pragma weak INTDMAC0ERR_IRQHandler = DefaultIntHandler
#pragma weak INTABTLOSS1_IRQHandler = DefaultIntHandler

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

