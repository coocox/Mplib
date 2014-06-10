//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM37x Devices Startup code for CooCox CoIDE.
//!        (x can be 0,2,3,4)
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

void WEAK  INT0_IRQHandler      (void);     //0:  Interrupt Pin (PH0/AINA0/96pin or 98pin)
void WEAK  INT1_IRQHandler      (void);     //1:  Interrupt Pin (PH1/AINA1/95pin or 97pin)
void WEAK  INT2_IRQHandler      (void);     //2:  Interrupt Pin (PH2/AINA2/94pin or 96pin)
void WEAK  INT3_IRQHandler      (void);     //3:  Interrupt Pin (PA0/TB0IN/2pin or 4pin)
void WEAK  INT4_IRQHandler      (void);     //4:  Interrupt Pin (PA2/TB1IN/4pin or 6pin)
void WEAK  INT5_IRQHandler      (void);     //5:  Interrupt Pin (PE4/TB2IN//15pin or 17pin)
void WEAK  INTRX0_IRQHandler    (void);     //6:  Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler    (void);     //7:  Serial transmit (channel.0)
void WEAK  INTRX1_IRQHandler    (void);     //8:  Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler    (void);     //9:  Serial transmit (channel.1)
void WEAK  INTVCNA_IRQHandler   (void);     //10: Vector Engine interrupt A
void WEAK  INTVCNB_IRQHandler   (void);     //11: Vector Engine interrupt B
void WEAK  INTEMG0_IRQHandler   (void);     //12: PMD0 EMG interrupt
void WEAK  INTEMG1_IRQHandler   (void);     //13: PMD1 EMG interrupt
void WEAK  INTOVV0_IRQHandler   (void);     //14: PMD0 OVV interrupt
void WEAK  INTOVV1_IRQHandler   (void);     //15: PMD1 OVV interrupt
void WEAK  INTADAPDA_IRQHandler (void);     //16: ADCA conversion triggered by PMD0 is finished
void WEAK  INTADBPDA_IRQHandler (void);     //17: ADCB conversion triggered by PMD0 is finished
void WEAK  INTADAPDB_IRQHandler (void);     //18: ADCA conversion triggered by PMD1 is finished
void WEAK  INTADBPDB_IRQHandler (void);     //19: ADCB conversion triggered by PMD1 is finished
void WEAK  INTTB00_IRQHandler   (void);     //20: 16bit TMRB0 compare match detection 0/ Over flow
void WEAK  INTTB01_IRQHandler   (void);     //21: 16bit TMRB0 compare match detection 1
void WEAK  INTTB10_IRQHandler   (void);     //22: 16bit TMRB1 compare match detection 0/ Over flow
void WEAK  INTTB11_IRQHandler   (void);     //23: 16bit TMRB1 compare match detection 1
void WEAK  INTTB40_IRQHandler   (void);     //24: 16bit TMRB4 compare match detection 0/ Over flow
void WEAK  INTTB41_IRQHandler   (void);     //25: 16bit TMRB4 compare match detection 1
void WEAK  INTTB50_IRQHandler   (void);     //26: 16bit TMRB5 compare match detection 0/ Over flow
void WEAK  INTTB51_IRQHandler   (void);     //27: 16bit TMRB5 compare match detection 1
void WEAK  INTPMD0_IRQHandler   (void);     //28: PMD0 PWM interrupt
void WEAK  INTPMD1_IRQHandler   (void);     //29: PMD1 PWM interrupt
void WEAK  INTCAP00_IRQHandler  (void);     //30: 16bit TMRB0 input capture 0
void WEAK  INTCAP01_IRQHandler  (void);     //31: 16bit TMRB0 input capture 1
void WEAK  INTCAP10_IRQHandler  (void);     //32: 16bit TMRB1 input capture 0
void WEAK  INTCAP11_IRQHandler  (void);     //33: 16bit TMRB1 input capture 1
void WEAK  INTCAP40_IRQHandler  (void);     //34: 16bit TMRB4 input capture 0
void WEAK  INTCAP41_IRQHandler  (void);     //35: 16bit TMRB4 input capture 1
void WEAK  INTCAP50_IRQHandler  (void);     //36: 16bit TMRB5 input capture 0
void WEAK  INTCAP51_IRQHandler  (void);     //37: 16bit TMRB5 input capture 1
void WEAK  INT6_IRQHandler      (void);     //38: Interrupt Pin (PE6/TB3IN//17pin or 19pin)
void WEAK  INT7_IRQHandler      (void);     //39: Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
void WEAK  INTRX2_IRQHandler    (void);     //40: Serial reception (channel.2)
void WEAK  INTTX2_IRQHandler    (void);     //41: Serial transmit (channel.2)
void WEAK  INTADACPA_IRQHandler (void);     //42: ADCA conversion monitoring function interrupt A
void WEAK  INTADBCPA_IRQHandler (void);     //43: ADCB conversion monitoring function interrupt A
void WEAK  INTADACPB_IRQHandler (void);     //44: ADCA conversion monitoring function interrupt B
void WEAK  INTADBCPB_IRQHandler (void);     //45: ADCB conversion monitoring function interrupt B
void WEAK  INTTB20_IRQHandler   (void);     //46: 16bit TMRB2 compare match detection 0/ Over flow
void WEAK  INTTB21_IRQHandler   (void);     //47: 16bit TMRB2 compare match detection 1
void WEAK  INTTB30_IRQHandler   (void);     //48: 16bit TMRB3 compare match detection 0/ Over flow
void WEAK  INTTB31_IRQHandler   (void);     //49: 16bit TMRB3 compare match detection 1
void WEAK  INTCAP20_IRQHandler  (void);     //50: 16bit TMRB2 input capture 0
void WEAK  INTCAP21_IRQHandler  (void);     //51: 16bit TMRB2 input capture 1
void WEAK  INTCAP30_IRQHandler  (void);     //52: 16bit TMRB3 input capture 0
void WEAK  INTCAP31_IRQHandler  (void);     //53: 16bit TMRB3 input capture 1
void WEAK  INTADASFT_IRQHandler (void);     //54: ADCA conversion started by software is finished
void WEAK  INTADBSFT_IRQHandler (void);     //55: ADCB conversion started by software is finished
void WEAK  INTADATMR_IRQHandler (void);     //56: ADCA conversion triggered by timer is finished
void WEAK  INTADBTMR_IRQHandler (void);     //57: ADCB conversion triggered by timer is finished
void WEAK  INT8_IRQHandler      (void);     //58: Interrupt Pin (PA7/TB4IN/9pin or 11pin)
void WEAK  INT9_IRQHandler      (void);     //59: Interrupt Pin (PD3/33pin or 35pin)
void WEAK  INTA_IRQHandler      (void);     //60: Interrupt Pin (PL1/21pin or 23pin)
void WEAK  INTB_IRQHandler      (void);     //61: Interrupt Pin (PL0/20pin or 22pin)
void WEAK  INTENC0_IRQHandler   (void);     //62: Ender input0 interrupt
void WEAK  INTENC1_IRQHandler   (void);     //63: Ender input1 interrupt
void WEAK  INTRX3_IRQHandler    (void);     //64: Serial reception (channel.3)
void WEAK  INTTX3_IRQHandler    (void);     //65: Serial transmit (channel.3)
void WEAK  INTTB60_IRQHandler   (void);     //66: 16bit TMRB6 compare match detection 0 / Over flow
void WEAK  INTTB61_IRQHandler   (void);     //67: 16bit TMRB6 compare match detection 1
void WEAK  INTTB70_IRQHandler   (void);     //68: 16bit TMRB7 compare match detection 0 / Over flow
void WEAK  INTTB71_IRQHandler   (void);     //69: 16bit TMRB7 compare match detection 1
void WEAK  INTCAP60_IRQHandler  (void);     //70: 16bit TMRB6 input capture 0
void WEAK  INTCAP61_IRQHandler  (void);     //71: 16bit TMRB6 input capture 1
void WEAK  INTCAP70_IRQHandler  (void);     //72: 16bit TMRB7 input capture 0
void WEAK  INTCAP71_IRQHandler  (void);     //73: 16bit TMRB7 input capture 1
void WEAK  INTC_IRQHandler      (void);     //74: Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
void WEAK  INTD_IRQHandler      (void);     //75: Interrupt Pin (PJ7/AINB10/73pin or 75pin)
void WEAK  INTE_IRQHandler      (void);     //76: Interrupt Pin (PK0/AINB11/72pin or 74pin)
void WEAK  INTF_IRQHandler      (void);     //77: Interrupt Pin (PK1/AINB12/71pin or 73pin)


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
                                  
                                  
    INT0_IRQHandler              ,          //0:  Interrupt Pin (PH0/AINA0/96pin or 98pin)
    INT1_IRQHandler              ,          //1:  Interrupt Pin (PH1/AINA1/95pin or 97pin)
    INT2_IRQHandler              ,          //2:  Interrupt Pin (PH2/AINA2/94pin or 96pin)
    INT3_IRQHandler              ,          //3:  Interrupt Pin (PA0/TB0IN/2pin or 4pin)
    INT4_IRQHandler              ,          //4:  Interrupt Pin (PA2/TB1IN/4pin or 6pin)
    INT5_IRQHandler              ,          //5:  Interrupt Pin (PE4/TB2IN//15pin or 17pin)
    INTRX0_IRQHandler            ,          //6:  Serial reception (channel.0)
    INTTX0_IRQHandler            ,          //7:  Serial transmit (channel.0)
    INTRX1_IRQHandler            ,          //8:  Serial reception (channel.1)
    INTTX1_IRQHandler            ,          //9:  Serial transmit (channel.1)
    INTVCNA_IRQHandler           ,          //10: Vector Engine interrupt A
    INTVCNB_IRQHandler           ,          //11: Vector Engine interrupt B
    INTEMG0_IRQHandler           ,          //12: PMD0 EMG interrupt
    INTEMG1_IRQHandler           ,          //13: PMD1 EMG interrupt
    INTOVV0_IRQHandler           ,          //14: PMD0 OVV interrupt
    INTOVV1_IRQHandler           ,          //15: PMD1 OVV interrupt
    INTADAPDA_IRQHandler         ,          //16: ADCA conversion triggered by PMD0 is finished
    INTADBPDA_IRQHandler         ,          //17: ADCB conversion triggered by PMD0 is finished
    INTADAPDB_IRQHandler         ,          //18: ADCA conversion triggered by PMD1 is finished
    INTADBPDB_IRQHandler         ,          //19: ADCB conversion triggered by PMD1 is finished
    INTTB00_IRQHandler           ,          //20: 16bit TMRB0 compare match detection 0/ Over flow
    INTTB01_IRQHandler           ,          //21: 16bit TMRB0 compare match detection 1
    INTTB10_IRQHandler           ,          //22: 16bit TMRB1 compare match detection 0/ Over flow
    INTTB11_IRQHandler           ,          //23: 16bit TMRB1 compare match detection 1
    INTTB40_IRQHandler           ,          //24: 16bit TMRB4 compare match detection 0/ Over flow
    INTTB41_IRQHandler           ,          //25: 16bit TMRB4 compare match detection 1
    INTTB50_IRQHandler           ,          //26: 16bit TMRB5 compare match detection 0/ Over flow
    INTTB51_IRQHandler           ,          //27: 16bit TMRB5 compare match detection 1
    INTPMD0_IRQHandler           ,          //28: PMD0 PWM interrupt
    INTPMD1_IRQHandler           ,          //29: PMD1 PWM interrupt
    INTCAP00_IRQHandler          ,          //30: 16bit TMRB0 input capture 0
    INTCAP01_IRQHandler          ,          //31: 16bit TMRB0 input capture 1
    INTCAP10_IRQHandler          ,          //32: 16bit TMRB1 input capture 0
    INTCAP11_IRQHandler          ,          //33: 16bit TMRB1 input capture 1
    INTCAP40_IRQHandler          ,          //34: 16bit TMRB4 input capture 0
    INTCAP41_IRQHandler          ,          //35: 16bit TMRB4 input capture 1
    INTCAP50_IRQHandler          ,          //36: 16bit TMRB5 input capture 0
    INTCAP51_IRQHandler          ,          //37: 16bit TMRB5 input capture 1
    INT6_IRQHandler              ,          //38: Interrupt Pin (PE6/TB3IN//17pin or 19pin)
    INT7_IRQHandler              ,          //39: Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
    INTRX2_IRQHandler            ,          //40: Serial reception (channel.2)
    INTTX2_IRQHandler            ,          //41: Serial transmit (channel.2)
    INTADACPA_IRQHandler         ,          //42: ADCA conversion monitoring function interrupt A
    INTADBCPA_IRQHandler         ,          //43: ADCB conversion monitoring function interrupt A
    INTADACPB_IRQHandler         ,          //44: ADCA conversion monitoring function interrupt B
    INTADBCPB_IRQHandler         ,          //45: ADCB conversion monitoring function interrupt B
    INTTB20_IRQHandler           ,          //46: 16bit TMRB2 compare match detection 0/ Over flow
    INTTB21_IRQHandler           ,          //47: 16bit TMRB2 compare match detection 1
    INTTB30_IRQHandler           ,          //48: 16bit TMRB3 compare match detection 0/ Over flow
    INTTB31_IRQHandler           ,          //49: 16bit TMRB3 compare match detection 1
    INTCAP20_IRQHandler          ,          //50: 16bit TMRB2 input capture 0
    INTCAP21_IRQHandler          ,          //51: 16bit TMRB2 input capture 1
    INTCAP30_IRQHandler          ,          //52: 16bit TMRB3 input capture 0
    INTCAP31_IRQHandler          ,          //53: 16bit TMRB3 input capture 1
    INTADASFT_IRQHandler         ,          //54: ADCA conversion started by software is finished
    INTADBSFT_IRQHandler         ,          //55: ADCB conversion started by software is finished
    INTADATMR_IRQHandler         ,          //56: ADCA conversion triggered by timer is finished
    INTADBTMR_IRQHandler         ,          //57: ADCB conversion triggered by timer is finished
    INT8_IRQHandler              ,          //58: Interrupt Pin (PA7/TB4IN/9pin or 11pin)
    INT9_IRQHandler              ,          //59: Interrupt Pin (PD3/33pin or 35pin)
    INTA_IRQHandler              ,          //60: Interrupt Pin (PL1/21pin or 23pin)
    INTB_IRQHandler              ,          //61: Interrupt Pin (PL0/20pin or 22pin)
    INTENC0_IRQHandler           ,          //62: Ender input0 interrupt
    INTENC1_IRQHandler           ,          //63: Ender input1 interrupt
    INTRX3_IRQHandler            ,          //64: Serial reception (channel.3)
    INTTX3_IRQHandler            ,          //65: Serial transmit (channel.3)
    INTTB60_IRQHandler           ,          //66: 16bit TMRB6 compare match detection 0 / Over flow
    INTTB61_IRQHandler           ,          //67: 16bit TMRB6 compare match detection 1
    INTTB70_IRQHandler           ,          //68: 16bit TMRB7 compare match detection 0 / Over flow
    INTTB71_IRQHandler           ,          //69: 16bit TMRB7 compare match detection 1
    INTCAP60_IRQHandler          ,          //70: 16bit TMRB6 input capture 0
    INTCAP61_IRQHandler          ,          //71: 16bit TMRB6 input capture 1
    INTCAP70_IRQHandler          ,          //72: 16bit TMRB7 input capture 0
    INTCAP71_IRQHandler          ,          //73: 16bit TMRB7 input capture 1
    INTC_IRQHandler              ,          //74: Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
    INTD_IRQHandler              ,          //75: Interrupt Pin (PJ7/AINB10/73pin or 75pin)
    INTE_IRQHandler              ,          //76: Interrupt Pin (PK0/AINB11/72pin or 74pin)
    INTF_IRQHandler              ,          //77: Interrupt Pin (PK1/AINB12/71pin or 73pin)

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
#pragma weak INTVCNA_IRQHandler   = DefaultIntHandler 
#pragma weak INTVCNB_IRQHandler   = DefaultIntHandler 
#pragma weak INTEMG0_IRQHandler   = DefaultIntHandler 
#pragma weak INTEMG1_IRQHandler   = DefaultIntHandler 
#pragma weak INTOVV0_IRQHandler   = DefaultIntHandler 
#pragma weak INTOVV1_IRQHandler   = DefaultIntHandler 
#pragma weak INTADAPDA_IRQHandler = DefaultIntHandler 
#pragma weak INTADBPDA_IRQHandler = DefaultIntHandler 
#pragma weak INTADAPDB_IRQHandler = DefaultIntHandler 
#pragma weak INTADBPDB_IRQHandler = DefaultIntHandler 
#pragma weak INTTB00_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB01_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB10_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB11_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB40_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB41_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB50_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB51_IRQHandler   = DefaultIntHandler 
#pragma weak INTPMD0_IRQHandler   = DefaultIntHandler 
#pragma weak INTPMD1_IRQHandler   = DefaultIntHandler 
#pragma weak INTCAP00_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP01_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP10_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP11_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP40_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP41_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP50_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP51_IRQHandler  = DefaultIntHandler 
#pragma weak INT6_IRQHandler      = DefaultIntHandler 
#pragma weak INT7_IRQHandler      = DefaultIntHandler 
#pragma weak INTRX2_IRQHandler    = DefaultIntHandler 
#pragma weak INTTX2_IRQHandler    = DefaultIntHandler 
#pragma weak INTADACPA_IRQHandler = DefaultIntHandler 
#pragma weak INTADBCPA_IRQHandler = DefaultIntHandler 
#pragma weak INTADACPB_IRQHandler = DefaultIntHandler 
#pragma weak INTADBCPB_IRQHandler = DefaultIntHandler 
#pragma weak INTTB20_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB21_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB30_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB31_IRQHandler   = DefaultIntHandler 
#pragma weak INTCAP20_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP21_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP30_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP31_IRQHandler  = DefaultIntHandler 
#pragma weak INTADASFT_IRQHandler = DefaultIntHandler 
#pragma weak INTADBSFT_IRQHandler = DefaultIntHandler 
#pragma weak INTADATMR_IRQHandler = DefaultIntHandler 
#pragma weak INTADBTMR_IRQHandler = DefaultIntHandler 
#pragma weak INT8_IRQHandler      = DefaultIntHandler 
#pragma weak INT9_IRQHandler      = DefaultIntHandler 
#pragma weak INTA_IRQHandler      = DefaultIntHandler 
#pragma weak INTB_IRQHandler      = DefaultIntHandler 
#pragma weak INTENC0_IRQHandler   = DefaultIntHandler 
#pragma weak INTENC1_IRQHandler   = DefaultIntHandler 
#pragma weak INTRX3_IRQHandler    = DefaultIntHandler 
#pragma weak INTTX3_IRQHandler    = DefaultIntHandler 
#pragma weak INTTB60_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB61_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB70_IRQHandler   = DefaultIntHandler 
#pragma weak INTTB71_IRQHandler   = DefaultIntHandler 
#pragma weak INTCAP60_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP61_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP70_IRQHandler  = DefaultIntHandler 
#pragma weak INTCAP71_IRQHandler  = DefaultIntHandler 
#pragma weak INTC_IRQHandler      = DefaultIntHandler 
#pragma weak INTD_IRQHandler      = DefaultIntHandler 
#pragma weak INTE_IRQHandler      = DefaultIntHandler 
#pragma weak INTF_IRQHandler      = DefaultIntHandler 

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

