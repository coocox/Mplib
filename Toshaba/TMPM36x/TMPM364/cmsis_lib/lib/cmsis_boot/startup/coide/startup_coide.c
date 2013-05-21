//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM36x Devices Startup code for CooCox CoIDE.
//!        (x can be 1,2,3,4)
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

//External Interrupts
void WEAK  INT0_IRQHandler       (void);    //0:  Interrupt pin 0
void WEAK  INT1_IRQHandler       (void);    //1:  Interrupt pin 1
void WEAK  INT2_IRQHandler       (void);    //2:  Interrupt pin 2
void WEAK  INT3_IRQHandler       (void);    //3:  Interrupt pin 3
void WEAK  INT4_IRQHandler       (void);    //4:  Interrupt pin 4
void WEAK  INT5_IRQHandler       (void);    //5:  Interrupt pin 5
void WEAK  INT6_IRQHandler       (void);    //6:  Interrupt pin 6
void WEAK  INT7_IRQHandler       (void);    //7:  Interrupt pin 7
void WEAK  INT8_IRQHandler       (void);    //8:  Interrupt pin 8
void WEAK  INT9_IRQHandler       (void);    //9:  Interrupt pin 9
void WEAK  INTA_IRQHandler       (void);    //10: Interrupt pin A
void WEAK  INTB_IRQHandler       (void);    //11: Interrupt pin B
void WEAK  INTC_IRQHandler       (void);    //12: Interrupt pin C
void WEAK  INTD_IRQHandler       (void);    //13: Interrupt pin D
void WEAK  INTE_IRQHandler       (void);    //14: Interrupt pin E
void WEAK  INTF_IRQHandler       (void);    //15: Interrupt pin F
void WEAK  INTRX0_IRQHandler     (void);    //16: Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler     (void);    //17: Serial transmission (channel.0)
void WEAK  INTRX1_IRQHandler     (void);    //18: Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler     (void);    //19: Serial transmission (channel.1)
void WEAK  INTRX2_IRQHandler     (void);    //20: Serial reception (channel.2)
void WEAK  INTTX2_IRQHandler     (void);    //21: Serial transmission (channel.2)
void WEAK  INTRX3_IRQHandler     (void);    //22: Serial reception (channel.3)
void WEAK  INTTX3_IRQHandler     (void);    //23: Serial transmission (channel.3)
void WEAK  INTRX4_IRQHandler     (void);    //24: Serial reception (channel.4)
void WEAK  INTTX4_IRQHandler     (void);    //25: Serial transmission (channel.4)
void WEAK  INTSBI0_IRQHandler    (void);    //26: Serial bus interface (channel.0)
void WEAK  INTSBI1_IRQHandler    (void);    //27: Serial bus interface (channel.1)
void WEAK  INTCECRX_IRQHandler   (void);    //28: CEC reception
void WEAK  INTCECTX_IRQHandler   (void);    //29: CEC transmission
void WEAK  INTRMCRX0_IRQHandler  (void);    //30: Remote control signal reception (channel.0)
void WEAK  INTRMCRX1_IRQHandler  (void);    //31: Remote control signal reception (channel.1)
void WEAK  INTRTC_IRQHandler     (void);    //32: Real time clock timer
void WEAK  INTKWUP_IRQHandler    (void);    //33: Key on wake up
void WEAK  INTSBI2_IRQHandler    (void);    //34: Serial bus interface (channel.2)
void WEAK  INTSBI3_IRQHandler    (void);    //35: Serial bus interface (channel.3)
void WEAK  INTSBI4_IRQHandler    (void);    //36: Serial bus interface (channel.4)
void WEAK  INTADHP_IRQHandler    (void);    //37: Highest priority AD conversion complete interrupt 
void WEAK  INTADM0_IRQHandler    (void);    //38: AD conversion monitoring function interrupt 0
void WEAK  INTADM1_IRQHandler    (void);    //39: AD conversion monitoring function interrupt 1
void WEAK  INTTB0_IRQHandler     (void);    //40: 16bit TMRB match detection 0
void WEAK  INTTB1_IRQHandler     (void);    //41: 16bit TMRB match detection 1
void WEAK  INTTB2_IRQHandler     (void);    //42: 16bit TMRB match detection 2
void WEAK  INTTB3_IRQHandler     (void);    //43: 16bit TMRB match detection 3
void WEAK  INTTB4_IRQHandler     (void);    //44: 16bit TMRB match detection 4
void WEAK  INTTB5_IRQHandler     (void);    //45: 16bit TMRB match detection 5
void WEAK  INTTB6_IRQHandler     (void);    //46: 16bit TMRB match detection 6
void WEAK  INTTB7_IRQHandler     (void);    //47: 16bit TMRB match detection 7
void WEAK  INTTB8_IRQHandler     (void);    //48: 16bit TMRB match detection 8
void WEAK  INTTB9_IRQHandler     (void);    //49: 16bit TMRB match detection 9
void WEAK  INTTBA_IRQHandler     (void);    //50: 16bit TMRB match detection A
void WEAK  INTTBB_IRQHandler     (void);    //51: 16bit TMRB match detection B
void WEAK  INTTBC_IRQHandler     (void);    //52: 16bit TMRB match detection C
void WEAK  INTTBD_IRQHandler     (void);    //53: 16bit TMRB match detection D
void WEAK  INTTBE_IRQHandler     (void);    //54: 16bit TMRB match detection E
void WEAK  INTTBF_IRQHandler     (void);    //55: 16bit TMRB match detection F
void WEAK  INTUSB_IRQHandler     (void);    //56: USB
void WEAK  INTCANGB_IRQHandler   (void);    //57: CAN status
void WEAK  INTAD_IRQHandler      (void);    //58: ADC conversion completion
void WEAK  INTSSP_IRQHandler     (void);    //59: Synchronous Serial Port
void WEAK  INTRX5_IRQHandler     (void);    //60: Serial reception (channel.5)
void WEAK  INTTX5_IRQHandler     (void);    //61: Serial transmission (channel.5)
void WEAK  INTRX6_IRQHandler     (void);    //62: Serial reception (channel.6)
void WEAK  INTTX6_IRQHandler     (void);    //63: Serial transmission (channel.6)
void WEAK  INTRX7_IRQHandler     (void);    //64: Serial reception (channel.7)
void WEAK  INTTX7_IRQHandler     (void);    //65: Serial transmission (channel.7)
void WEAK  INTRX8_IRQHandler     (void);    //66: Serial reception (channel.8)
void WEAK  INTTX8_IRQHandler     (void);    //67: Serial transmission (channel.8)
void WEAK  INTRX9_IRQHandler     (void);    //68: Serial reception (channel.9)
void WEAK  INTTX9_IRQHandler     (void);    //69: Serial transmission (channel.9)
void WEAK  INTRX10_IRQHandler    (void);    //70: Serial reception (channel.10)
void WEAK  INTTX10_IRQHandler    (void);    //71: Serial transmission (channel.10)
void WEAK  INTRX11_IRQHandler    (void);    //72: Serial reception (channel.11)
void WEAK  INTTX11_IRQHandler    (void);    //73: Serial transmission (channel.11)
void WEAK  INTCAP10_IRQHandler   (void);    //74: 16bit TMRB input capture 10
void WEAK  INTCAP11_IRQHandler   (void);    //75: 16bit TMRB input capture 11
void WEAK  INTCAP20_IRQHandler   (void);    //76: 16bit TMRB input capture 20
void WEAK  INTCAP21_IRQHandler   (void);    //77: 16bit TMRB input capture 21
void WEAK  INTCANRX_IRQHandler   (void);    //78: CAN Reception
void WEAK  INTCANTX_IRQHandler   (void);    //79: CAN Transmission
void WEAK  INTCAP50_IRQHandler   (void);    //80: 16bit TMRB input capture 50
void WEAK  INTCAP51_IRQHandler   (void);    //81: 16bit TMRB input capture 51
void WEAK  INTCAP60_IRQHandler   (void);    //82: 16bit TMRB input capture 60
void WEAK  INTCAP61_IRQHandler   (void);    //83: 16bit TMRB input capture 61
void WEAK  INTCAP70_IRQHandler   (void);    //84: 16bit TMRB input capture 70
void WEAK  INTCAP71_IRQHandler   (void);    //85: 16bit TMRB input capture 71
void WEAK  INTCAP90_IRQHandler   (void);    //86: 16bit TMRB input capture 90
void WEAK  INTCAP91_IRQHandler   (void);    //87: 16bit TMRB input capture 91
void WEAK  INTCAPA0_IRQHandler   (void);    //88: 16bit TMRB input capture A0
void WEAK  INTCAPA1_IRQHandler   (void);    //89: 16bit TMRB input capture A1
void WEAK  INTCAPB0_IRQHandler   (void);    //90: 16bit TMRB input capture B0
void WEAK  INTCAPB1_IRQHandler   (void);    //91: 16bit TMRB input capture B1
void WEAK  INTCAPD0_IRQHandler   (void);    //92: 16bit TMRB input capture D0
void WEAK  INTCAPD1_IRQHandler   (void);    //93: 16bit TMRB input capture D1
void WEAK  INTCAPE0_IRQHandler   (void);    //94: 16bit TMRB input capture E0
void WEAK  INTCAPE1_IRQHandler   (void);    //95: 16bit TMRB input capture E1
void WEAK  INTCAPF0_IRQHandler   (void);    //96: 16bit TMRB input capture F0
void WEAK  INTCAPF1_IRQHandler   (void);    //97: 16bit TMRB input capture F1
void WEAK  INTDMACERR_IRQHandler (void);    //98: DMA transmission error
void WEAK  INTDMACTC0_IRQHandler (void);    //99: DMA transmission completion

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
                                  
    INT0_IRQHandler              ,          //0:  Interrupt pin 0
    INT1_IRQHandler              ,          //1:  Interrupt pin 1
    INT2_IRQHandler              ,          //2:  Interrupt pin 2
    INT3_IRQHandler              ,          //3:  Interrupt pin 3
    INT4_IRQHandler              ,          //4:  Interrupt pin 4
    INT5_IRQHandler              ,          //5:  Interrupt pin 5
    INT6_IRQHandler              ,          //6:  Interrupt pin 6
    INT7_IRQHandler              ,          //7:  Interrupt pin 7
    INT8_IRQHandler              ,          //8:  Interrupt pin 8
    INT9_IRQHandler              ,          //9:  Interrupt pin 9
    INTA_IRQHandler              ,          //10: Interrupt pin A
    INTB_IRQHandler              ,          //11: Interrupt pin B
    INTC_IRQHandler              ,          //12: Interrupt pin C
    INTD_IRQHandler              ,          //13: Interrupt pin D
    INTE_IRQHandler              ,          //14: Interrupt pin E
    INTF_IRQHandler              ,          //15: Interrupt pin F
    INTRX0_IRQHandler            ,          //16: Serial reception (channel.0)
    INTTX0_IRQHandler            ,          //17: Serial transmission (channel.0)
    INTRX1_IRQHandler            ,          //18: Serial reception (channel.1)
    INTTX1_IRQHandler            ,          //19: Serial transmission (channel.1)
    INTRX2_IRQHandler            ,          //20: Serial reception (channel.2)
    INTTX2_IRQHandler            ,          //21: Serial transmission (channel.2)
    INTRX3_IRQHandler            ,          //22: Serial reception (channel.3)
    INTTX3_IRQHandler            ,          //23: Serial transmission (channel.3)
    INTRX4_IRQHandler            ,          //24: Serial reception (channel.4)
    INTTX4_IRQHandler            ,          //25: Serial transmission (channel.4)
    INTSBI0_IRQHandler           ,          //26: Serial bus interface (channel.0)
    INTSBI1_IRQHandler           ,          //27: Serial bus interface (channel.1)
    INTCECRX_IRQHandler          ,          //28: CEC reception
    INTCECTX_IRQHandler          ,          //29: CEC transmission
    INTRMCRX0_IRQHandler         ,          //30: Remote control signal reception (channel.0)
    INTRMCRX1_IRQHandler         ,          //31: Remote control signal reception (channel.1)
    INTRTC_IRQHandler            ,          //32: Real time clock timer
    INTKWUP_IRQHandler           ,          //33: Key on wake up
    INTSBI2_IRQHandler           ,          //34: Serial bus interface (channel.2)
    INTSBI3_IRQHandler           ,          //35: Serial bus interface (channel.3)
    INTSBI4_IRQHandler           ,          //36: Serial bus interface (channel.4)
    INTADHP_IRQHandler           ,          //37: Highest priority AD conversion complete interrupt 
    INTADM0_IRQHandler           ,          //38: AD conversion monitoring function interrupt 0
    INTADM1_IRQHandler           ,          //39: AD conversion monitoring function interrupt 1
    INTTB0_IRQHandler            ,          //40: 16bit TMRB match detection 0
    INTTB1_IRQHandler            ,          //41: 16bit TMRB match detection 1
    INTTB2_IRQHandler            ,          //42: 16bit TMRB match detection 2
    INTTB3_IRQHandler            ,          //43: 16bit TMRB match detection 3
    INTTB4_IRQHandler            ,          //44: 16bit TMRB match detection 4
    INTTB5_IRQHandler            ,          //45: 16bit TMRB match detection 5
    INTTB6_IRQHandler            ,          //46: 16bit TMRB match detection 6
    INTTB7_IRQHandler            ,          //47: 16bit TMRB match detection 7
    INTTB8_IRQHandler            ,          //48: 16bit TMRB match detection 8
    INTTB9_IRQHandler            ,          //49: 16bit TMRB match detection 9
    INTTBA_IRQHandler            ,          //50: 16bit TMRB match detection A
    INTTBB_IRQHandler            ,          //51: 16bit TMRB match detection B
    INTTBC_IRQHandler            ,          //52: 16bit TMRB match detection C
    INTTBD_IRQHandler            ,          //53: 16bit TMRB match detection D
    INTTBE_IRQHandler            ,          //54: 16bit TMRB match detection E
    INTTBF_IRQHandler            ,          //55: 16bit TMRB match detection F
    INTUSB_IRQHandler            ,          //56: USB
    INTCANGB_IRQHandler          ,          //57: CAN status
    INTAD_IRQHandler             ,          //58: ADC conversion completion
    INTSSP_IRQHandler            ,          //59: Synchronous Serial Port
    INTRX5_IRQHandler            ,          //60: Serial reception (channel.5)
    INTTX5_IRQHandler            ,          //61: Serial transmission (channel.5)
    INTRX6_IRQHandler            ,          //62: Serial reception (channel.6)
    INTTX6_IRQHandler            ,          //63: Serial transmission (channel.6)
    INTRX7_IRQHandler            ,          //64: Serial reception (channel.7)
    INTTX7_IRQHandler            ,          //65: Serial transmission (channel.7)
    INTRX8_IRQHandler            ,          //66: Serial reception (channel.8)
    INTTX8_IRQHandler            ,          //67: Serial transmission (channel.8)
    INTRX9_IRQHandler            ,          //68: Serial reception (channel.9)
    INTTX9_IRQHandler            ,          //69: Serial transmission (channel.9)
    INTRX10_IRQHandler           ,          //70: Serial reception (channel.10)
    INTTX10_IRQHandler           ,          //71: Serial transmission (channel.10)
    INTRX11_IRQHandler           ,          //72: Serial reception (channel.11)
    INTTX11_IRQHandler           ,          //73: Serial transmission (channel.11)
    INTCAP10_IRQHandler          ,          //74: 16bit TMRB input capture 10
    INTCAP11_IRQHandler          ,          //75: 16bit TMRB input capture 11
    INTCAP20_IRQHandler          ,          //76: 16bit TMRB input capture 20
    INTCAP21_IRQHandler          ,          //77: 16bit TMRB input capture 21
    INTCANRX_IRQHandler          ,          //78: CAN Reception
    INTCANTX_IRQHandler          ,          //79: CAN Transmission
    INTCAP50_IRQHandler          ,          //80: 16bit TMRB input capture 50
    INTCAP51_IRQHandler          ,          //81: 16bit TMRB input capture 51
    INTCAP60_IRQHandler          ,          //82: 16bit TMRB input capture 60
    INTCAP61_IRQHandler          ,          //83: 16bit TMRB input capture 61
    INTCAP70_IRQHandler          ,          //84: 16bit TMRB input capture 70
    INTCAP71_IRQHandler          ,          //85: 16bit TMRB input capture 71
    INTCAP90_IRQHandler          ,          //86: 16bit TMRB input capture 90
    INTCAP91_IRQHandler          ,          //87: 16bit TMRB input capture 91
    INTCAPA0_IRQHandler          ,          //88: 16bit TMRB input capture A0
    INTCAPA1_IRQHandler          ,          //89: 16bit TMRB input capture A1
    INTCAPB0_IRQHandler          ,          //90: 16bit TMRB input capture B0
    INTCAPB1_IRQHandler          ,          //91: 16bit TMRB input capture B1
    INTCAPD0_IRQHandler          ,          //92: 16bit TMRB input capture D0
    INTCAPD1_IRQHandler          ,          //93: 16bit TMRB input capture D1
    INTCAPE0_IRQHandler          ,          //94: 16bit TMRB input capture E0
    INTCAPE1_IRQHandler          ,          //95: 16bit TMRB input capture E1
    INTCAPF0_IRQHandler          ,          //96: 16bit TMRB input capture F0
    INTCAPF1_IRQHandler          ,          //97: 16bit TMRB input capture F1
    INTDMACERR_IRQHandler        ,          //98: DMA transmission error
    INTDMACTC0_IRQHandler        ,          //99: DMA transmission completion

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
#pragma weak INT8_IRQHandler        = DefaultIntHandler 
#pragma weak INT9_IRQHandler        = DefaultIntHandler 
#pragma weak INTA_IRQHandler        = DefaultIntHandler 
#pragma weak INTB_IRQHandler        = DefaultIntHandler 
#pragma weak INTC_IRQHandler        = DefaultIntHandler 
#pragma weak INTD_IRQHandler        = DefaultIntHandler 
#pragma weak INTE_IRQHandler        = DefaultIntHandler 
#pragma weak INTF_IRQHandler        = DefaultIntHandler 
#pragma weak INTRX0_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX0_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX1_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX1_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX2_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX2_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX3_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX3_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX4_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX4_IRQHandler      = DefaultIntHandler 
#pragma weak INTSBI0_IRQHandler     = DefaultIntHandler 
#pragma weak INTSBI1_IRQHandler     = DefaultIntHandler 
#pragma weak INTCECRX_IRQHandler    = DefaultIntHandler 
#pragma weak INTCECTX_IRQHandler    = DefaultIntHandler 
#pragma weak INTRMCRX0_IRQHandler   = DefaultIntHandler 
#pragma weak INTRMCRX1_IRQHandler   = DefaultIntHandler 
#pragma weak INTRTC_IRQHandler      = DefaultIntHandler 
#pragma weak INTKWUP_IRQHandler     = DefaultIntHandler 
#pragma weak INTSBI2_IRQHandler     = DefaultIntHandler 
#pragma weak INTSBI3_IRQHandler     = DefaultIntHandler 
#pragma weak INTSBI4_IRQHandler     = DefaultIntHandler 
#pragma weak INTADHP_IRQHandler     = DefaultIntHandler 
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
#pragma weak INTTBA_IRQHandler      = DefaultIntHandler 
#pragma weak INTTBB_IRQHandler      = DefaultIntHandler 
#pragma weak INTTBC_IRQHandler      = DefaultIntHandler 
#pragma weak INTTBD_IRQHandler      = DefaultIntHandler 
#pragma weak INTTBE_IRQHandler      = DefaultIntHandler 
#pragma weak INTTBF_IRQHandler      = DefaultIntHandler 
#pragma weak INTUSB_IRQHandler      = DefaultIntHandler 
#pragma weak INTCANGB_IRQHandler    = DefaultIntHandler 
#pragma weak INTAD_IRQHandler       = DefaultIntHandler 
#pragma weak INTSSP_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX5_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX5_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX6_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX6_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX7_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX7_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX8_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX8_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX9_IRQHandler      = DefaultIntHandler 
#pragma weak INTTX9_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX10_IRQHandler     = DefaultIntHandler 
#pragma weak INTTX10_IRQHandler     = DefaultIntHandler 
#pragma weak INTRX11_IRQHandler     = DefaultIntHandler 
#pragma weak INTTX11_IRQHandler     = DefaultIntHandler 
#pragma weak INTCAP10_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP11_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP20_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP21_IRQHandler    = DefaultIntHandler 
#pragma weak INTCANRX_IRQHandler    = DefaultIntHandler 
#pragma weak INTCANTX_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP50_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP51_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP60_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP61_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP70_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP71_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP90_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAP91_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPA0_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPA1_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPB0_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPB1_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPD0_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPD1_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPE0_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPE1_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPF0_IRQHandler    = DefaultIntHandler 
#pragma weak INTCAPF1_IRQHandler    = DefaultIntHandler 
#pragma weak INTDMACERR_IRQHandler  = DefaultIntHandler 
#pragma weak INTDMACTC0_IRQHandler  = DefaultIntHandler 

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

