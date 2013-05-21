//*****************************************************************************
//
//! \file startup_coide.c
//! \brief TMPM369 Devices Startup code for CooCox CoIDE.
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
void WEAK  ResetHandler           (void);
void WEAK  NMIIntHandler          (void);
void WEAK  HardFaultIntHandler    (void);
void WEAK  MemManageIntHandler    (void);
void WEAK  BusFaultIntHandler     (void);
void WEAK  UsageFaultIntHandler   (void);
void WEAK  SVCIntHandler          (void);
void WEAK  DebugMonIntHandler     (void);
void WEAK  PendSVIntHandler       (void);
void WEAK  SysTickIntHandler      (void);


// External Interrupts
void WEAK  INT0_IRQHandler        (void);   //0:   Interrupt pin 0
void WEAK  INT1_IRQHandler        (void);   //1:   Interrupt pin 1
void WEAK  INT2_IRQHandler        (void);   //2:   Interrupt pin 2
void WEAK  INT3_IRQHandler        (void);   //3:   Interrupt pin 3
void WEAK  INT4_IRQHandler        (void);   //4:   Interrupt pin 4
void WEAK  INT5_IRQHandler        (void);   //5:   Interrupt pin 5
void WEAK  INT6_IRQHandler        (void);   //6:   Interrupt pin 6
void WEAK  INT7_IRQHandler        (void);   //7:   Interrupt pin 7
void WEAK  INT8_IRQHandler        (void);   //8:   Interrupt pin 8
void WEAK  INT9_IRQHandler        (void);   //9:   Interrupt pin 9
void WEAK  INTA_IRQHandler        (void);   //10:  Interrupt pin A
void WEAK  INTB_IRQHandler        (void);   //11:  Interrupt pin B
void WEAK  INTC_IRQHandler        (void);   //12:  Interrupt pin C
void WEAK  INTD_IRQHandler        (void);   //13:  Interrupt pin D
void WEAK  INTE_IRQHandler        (void);   //14:  Interrupt pin E
void WEAK  INTF_IRQHandler        (void);   //15:  Interrupt pin F
void WEAK  INTRX0_IRQHandler      (void);   //16:  Serial reception (channel.0)
void WEAK  INTTX0_IRQHandler      (void);   //17:  Serial transmission (channel.0)
void WEAK  INTRX1_IRQHandler      (void);   //18:  Serial reception (channel.1)
void WEAK  INTTX1_IRQHandler      (void);   //19:  Serial transmission (channel.1)
void WEAK  INTRX2_IRQHandler      (void);   //20:  Serial reception (channel.2)
void WEAK  INTTX2_IRQHandler      (void);   //21:  Serial transmission (channel.2)
void WEAK  INTRX3_IRQHandler      (void);   //22:  Serial reception (channel.3)
void WEAK  INTTX3_IRQHandler      (void);   //23:  Serial transmission (channel.3)
void WEAK  INTUART4_IRQHandler    (void);   //24:  FULL UART(channel.4)
void WEAK  INTUART5_IRQHandler    (void);   //25:  FULL UART(channel.5)
void WEAK  INTSBI0_IRQHandler     (void);   //26:  Serial bus interface 0
void WEAK  INTSBI1_IRQHandler     (void);   //27:  Serial bus interface 1
void WEAK  INTSBI2_IRQHandler     (void);   //28:  Serial bus interface 2
void WEAK  INTSSP0_IRQHandler     (void);   //29:  SPI serial interface 0
void WEAK  INTSSP1_IRQHandler     (void);   //30:  SPI serial interface 1
void WEAK  INTSSP2_IRQHandler     (void);   //31:  SPI serial interface 2
void WEAK  INTUSBH_IRQHandler     (void);   //32:  USB Host Interrupt
void WEAK  INTUSBD_IRQHandler     (void);   //33:  USB Device Interrupt
void WEAK  INTUSBWKUP_IRQHandler  (void);   //34:  USB WakeUp
void WEAK  INTCANRX_IRQHandler    (void);   //35:  CAN RX
void WEAK  INTCANTX_IRQHandler    (void);   //36:  CAN TX
void WEAK  INTCANGB_IRQHandler    (void);   //37:  CAN STAUTS
void WEAK  INTETH_IRQHandler      (void);   //38:  EtherNET Interrupt
void WEAK  INTETHWK_IRQHandler    (void);   //39:  EtherNET(magic packet detection) interrupt
void WEAK  INTADAHP_IRQHandler    (void);   //40:  Highest priority AD conversion complete interrupt (channel.A)
void WEAK  INTADAM0_IRQHandler    (void);   //41:  AD conversion monitoring function interrupt 0(channel.A)
void WEAK  INTADAM1_IRQHandler    (void);   //42:  AD conversion monitoring function interrupt 1(channel.A)
void WEAK  INTADA_IRQHandler      (void);   //43:  AD conversion interrupt(channel.A)
void WEAK  INTADBHP_IRQHandler    (void);   //44:  Highest priority AD conversion complete interrupt (channel.B)
void WEAK  INTADBM0_IRQHandler    (void);   //45:  AD conversion monitoring function interrupt 0(channel.B)
void WEAK  INTADBM1_IRQHandler    (void);   //46:  AD conversion monitoring function interrupt 1(channel.B)
void WEAK  INTADB_IRQHandler      (void);   //47:  AD conversion interrupt(channel.B)
void WEAK  INTEMG0_IRQHandler     (void);   //48:  PMD0 EMG interrupt (MPT0)
void WEAK  INTPMD0_IRQHandler     (void);   //49:  PMD0 PWM interrupt (MPT0)
void WEAK  INTENC0_IRQHandler     (void);   //50:  PMD0 Encoder input interrupt (MPT0)
void WEAK  INTEMG1_IRQHandler     (void);   //51:  PMD1 EMG interrupt (MPT1)
void WEAK  INTPMD1_IRQHandler     (void);   //52:  PMD1 PWM interrupt (MPT1)
void WEAK  INTENC1_IRQHandler     (void);   //53:  PMD1 Encoder input interrupt (MPT1)
void WEAK  INTMTEMG0_IRQHandler   (void);   //54:  16-bit MPT0 IGBT EMG interrupt
void WEAK  INTMTPTB00_IRQHandler  (void);   //55:  16-bit MPT0 IGBT period/ TMRB compare match detection 0
void WEAK  INTMTTTB01_IRQHandler  (void);   //56:  16-bit MPT0 IGBT trigger/ TMRB compare match detection 1
void WEAK  INTMTCAP00_IRQHandler  (void);   //57:  16-bit MPT0 input capture 0
void WEAK  INTMTCAP01_IRQHandler  (void);   //58:  16-bit MPT0 input capture 1
void WEAK  INTMTEMG1_IRQHandler   (void);   //59:  16-bit MPT1 IGBT EMG interrupt
void WEAK  INTMTPTB10_IRQHandler  (void);   //60:  16-bit MPT1 IGBT period/ TMRB compare match detection 0
void WEAK  INTMTTTB11_IRQHandler  (void);   //61:  16-bit MPT1 IGBT trigger/ TMRB compare match detection 1
void WEAK  INTMTCAP10_IRQHandler  (void);   //62:  16-bit MPT1 input capture 0
void WEAK  INTMTCAP11_IRQHandler  (void);   //63:  16-bit MPT1 input capture 1
void WEAK  INTMTEMG2_IRQHandler   (void);   //64:  16-bit MPT2 IGBT EMG interrupt
void WEAK  INTMTPTB20_IRQHandler  (void);   //65:  16-bit MPT2 IGBT period/ TMRB compare match detection 0
void WEAK  INTMTTTB21_IRQHandler  (void);   //66:  16-bit MPT2 IGBT trigger/ TMRB compare match detection 1
void WEAK  INTMTCAP20_IRQHandler  (void);   //67:  16-bit MPT2 input capture 0
void WEAK  INTMTCAP21_IRQHandler  (void);   //68:  16-bit MPT2 input capture 1
void WEAK  INTMTEMG3_IRQHandler   (void);   //69:  16-bit MPT3 IGBT EMG interrupt
void WEAK  INTMTPTB30_IRQHandler  (void);   //70:  16-bit MPT3 IGBT period/ TMRB compare match detection 0
void WEAK  INTMTTTB31_IRQHandler  (void);   //71:  16-bit MPT3 IGBT trigger/ TMRB compare match detection 1
void WEAK  INTMTCAP30_IRQHandler  (void);   //72:  16-bit MPT3 input capture 0
void WEAK  INTMTCAP31_IRQHandler  (void);   //73:  16-bit MPT3 input capture 1
void WEAK  INTRMCRX_IRQHandler    (void);   //74:  Remote Controller reception interrupt
void WEAK  INTTB0_IRQHandler      (void);   //75:  16-bit TMRB_0 match detection 0
void WEAK  INTCAP00_IRQHandler    (void);   //76:  16-bit TMRB_0 input capture 00
void WEAK  INTCAP01_IRQHandler    (void);   //77:  16-bit TMRB_0 input capture 01
void WEAK  INTTB1_IRQHandler      (void);   //78:  16-bit TMRB_1 match detection 1
void WEAK  INTCAP10_IRQHandler    (void);   //79:  16-bit TMRB_1 input capture 10
void WEAK  INTCAP11_IRQHandler    (void);   //80:  16-bit TMRB_1 input capture 11
void WEAK  INTTB2_IRQHandler      (void);   //81:  16-bit TMRB_2 match detection 2
void WEAK  INTCAP20_IRQHandler    (void);   //82:  16-bit TMRB_2 input capture 20
void WEAK  INTCAP21_IRQHandler    (void);   //83:  16-bit TMRB_2 input capture 21
void WEAK  INTTB3_IRQHandler      (void);   //84:  16-bit TMRB_3 match detection 3
void WEAK  INTCAP30_IRQHandler    (void);   //85:  16-bit TMRB_3 input capture 30
void WEAK  INTCAP31_IRQHandler    (void);   //86:  16-bit TMRB_3 input capture 31
void WEAK  INTTB4_IRQHandler      (void);   //87:  16-bit TMRB_4 match detection 4
void WEAK  INTCAP40_IRQHandler    (void);   //88:  16-bit TMRB_4 input capture 40
void WEAK  INTCAP41_IRQHandler    (void);   //89:  16-bit TMRB_4 input capture 41
void WEAK  INTTB5_IRQHandler      (void);   //90:  16-bit TMRB_5 match detection 5
void WEAK  INTCAP50_IRQHandler    (void);   //91:  16-bit TMRB_5 input capture 50
void WEAK  INTCAP51_IRQHandler    (void);   //92:  16-bit TMRB_5 input capture 51
void WEAK  INTTB6_IRQHandler      (void);   //93:  16-bit TMRB_6 match detection 6
void WEAK  INTCAP60_IRQHandler    (void);   //94:  16-bit TMRB_6 input capture 60
void WEAK  INTCAP61_IRQHandler    (void);   //95:  16-bit TMRB_6 input capture 61
void WEAK  INTTB7_IRQHandler      (void);   //96:  16-bit TMRB_7 match detection 7
void WEAK  INTCAP70_IRQHandler    (void);   //97:  16-bit TMRB_7 input capture 70
void WEAK  INTCAP71_IRQHandler    (void);   //98:  16-bit TMRB_7 input capture 71
void WEAK  INTRTC_IRQHandler      (void);   //99:  RTC(Real time clock) interrupt
void WEAK  INTDMAADA_IRQHandler   (void);   //100: DMA_ADC_A conversion end
void WEAK  INTDMAADB_IRQHandler   (void);   //101: DMA_ADC_B conversion end
void WEAK  INTDMADAA_IRQHandler   (void);   //102: DMA_DAC_A conversion trigger
void WEAK  INTDMADAB_IRQHandler   (void);   //103: DMA_DAC_B conversion trigger
void WEAK  INTDMASPR0_IRQHandler  (void);   //104: DMA_SSP_0 reception / DMA_I2C SIO_0
void WEAK  INTDMASPT0_IRQHandler  (void);   //105: DMA_SSP_0 transmission
void WEAK  INTDMASPR1_IRQHandler  (void);   //106: DMA_SSP_1 reception
void WEAK  INTDMASPT1_IRQHandler  (void);   //107: DMA_SSP_1 transmission
void WEAK  INTDMASPR2_IRQHandler  (void);   //108: DMA_SSP_2 reception
void WEAK  INTDMASPT2_IRQHandler  (void);   //109: DMA_SSP_2 transmission
void WEAK  INTDMAUTR4_IRQHandler  (void);   //110: DMA_FUART_4 reception
void WEAK  INTDMAUTT4_IRQHandler  (void);   //111: DMA_FUART_4 transmission
void WEAK  INTDMAUTR5_IRQHandler  (void);   //112: DMA_FUART_5 reception
void WEAK  INTDMAUTT5_IRQHandler  (void);   //113: DMA_FUART_5 transmission
void WEAK  INTDMARX0_IRQHandler   (void);   //114: DMA_SIO/ UART_0 reception
void WEAK  INTDMATX0_IRQHandler   (void);   //115: DMA_SIO/ UART_0 transmission
void WEAK  INTDMARX1_IRQHandler   (void);   //116: DMA_SIO/ UART_1 reception
void WEAK  INTDMATX1_IRQHandler   (void);   //117: DMA_SIO/ UART_1 transmission
void WEAK  INTDMARX2_IRQHandler   (void);   //118: DMA_SIO/ UART_2 reception
void WEAK  INTDMATX2_IRQHandler   (void);   //119: DMA_SIO/ UART_2 transmission
void WEAK  INTDMARX3_IRQHandler   (void);   //120: DMA_SIO/ UART_3 reception
void WEAK  INTDMATX3_IRQHandler   (void);   //121: DMA_SIO/ UART_3 transmission
void WEAK  INTDMASBI1_IRQHandler  (void);   //122: DMA_I2C/ SIO_1
void WEAK  INTDMASBI2_IRQHandler  (void);   //123: DMA_I2C/ SIO_2
void WEAK  INTDMATB_IRQHandler    (void);   //124: 16-bit TMRB_0-4 match detection
void WEAK  INTDMARQ_IRQHandler    (void);   //125: DMA request pin
void WEAK  INTDMAAERR_IRQHandler  (void);   //126: DMA_A error transfer interrupt
void WEAK  INTDMABERR_IRQHandler  (void);   //127: DMA_B error transfer interrupt

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
    INT0_IRQHandler              , //0:   Interrupt pin 0
    INT1_IRQHandler              , //1:   Interrupt pin 1
    INT2_IRQHandler              , //2:   Interrupt pin 2
    INT3_IRQHandler              , //3:   Interrupt pin 3
    INT4_IRQHandler              , //4:   Interrupt pin 4
    INT5_IRQHandler              , //5:   Interrupt pin 5
    INT6_IRQHandler              , //6:   Interrupt pin 6
    INT7_IRQHandler              , //7:   Interrupt pin 7
    INT8_IRQHandler              , //8:   Interrupt pin 8
    INT9_IRQHandler              , //9:   Interrupt pin 9
    INTA_IRQHandler              , //10:  Interrupt pin A
    INTB_IRQHandler              , //11:  Interrupt pin B
    INTC_IRQHandler              , //12:  Interrupt pin C
    INTD_IRQHandler              , //13:  Interrupt pin D
    INTE_IRQHandler              , //14:  Interrupt pin E
    INTF_IRQHandler              , //15:  Interrupt pin F
    INTRX0_IRQHandler            , //16:  Serial reception (channel.0)
    INTTX0_IRQHandler            , //17:  Serial transmission (channel.0)
    INTRX1_IRQHandler            , //18:  Serial reception (channel.1)
    INTTX1_IRQHandler            , //19:  Serial transmission (channel.1)
    INTRX2_IRQHandler            , //20:  Serial reception (channel.2)
    INTTX2_IRQHandler            , //21:  Serial transmission (channel.2)
    INTRX3_IRQHandler            , //22:  Serial reception (channel.3)
    INTTX3_IRQHandler            , //23:  Serial transmission (channel.3)
    INTUART4_IRQHandler          , //24:  FULL UART(channel.4)
    INTUART5_IRQHandler          , //25:  FULL UART(channel.5)
    INTSBI0_IRQHandler           , //26:  Serial bus interface 0
    INTSBI1_IRQHandler           , //27:  Serial bus interface 1
    INTSBI2_IRQHandler           , //28:  Serial bus interface 2
    INTSSP0_IRQHandler           , //29:  SPI serial interface 0
    INTSSP1_IRQHandler           , //30:  SPI serial interface 1
    INTSSP2_IRQHandler           , //31:  SPI serial interface 2
    INTUSBH_IRQHandler           , //32:  USB Host Interrupt
    INTUSBD_IRQHandler           , //33:  USB Device Interrupt
    INTUSBWKUP_IRQHandler        , //34:  USB WakeUp
    INTCANRX_IRQHandler          , //35:  CAN RX
    INTCANTX_IRQHandler          , //36:  CAN TX
    INTCANGB_IRQHandler          , //37:  CAN STAUTS
    INTETH_IRQHandler            , //38:  EtherNET Interrupt
    INTETHWK_IRQHandler          , //39:  EtherNET(magic packet detection) interrupt
    INTADAHP_IRQHandler          , //40:  Highest priority AD conversion complete interrupt (channel.A)
    INTADAM0_IRQHandler          , //41:  AD conversion monitoring function interrupt 0(channel.A)
    INTADAM1_IRQHandler          , //42:  AD conversion monitoring function interrupt 1(channel.A)
    INTADA_IRQHandler            , //43:  AD conversion interrupt(channel.A)
    INTADBHP_IRQHandler          , //44:  Highest priority AD conversion complete interrupt (channel.B)
    INTADBM0_IRQHandler          , //45:  AD conversion monitoring function interrupt 0(channel.B)
    INTADBM1_IRQHandler          , //46:  AD conversion monitoring function interrupt 1(channel.B)
    INTADB_IRQHandler            , //47:  AD conversion interrupt(channel.B)
    INTEMG0_IRQHandler           , //48:  PMD0 EMG interrupt (MPT0)
    INTPMD0_IRQHandler           , //49:  PMD0 PWM interrupt (MPT0)
    INTENC0_IRQHandler           , //50:  PMD0 Encoder input interrupt (MPT0)
    INTEMG1_IRQHandler           , //51:  PMD1 EMG interrupt (MPT1)
    INTPMD1_IRQHandler           , //52:  PMD1 PWM interrupt (MPT1)
    INTENC1_IRQHandler           , //53:  PMD1 Encoder input interrupt (MPT1)
    INTMTEMG0_IRQHandler         , //54:  16-bit MPT0 IGBT EMG interrupt
    INTMTPTB00_IRQHandler        , //55:  16-bit MPT0 IGBT period/ TMRB compare match detection 0
    INTMTTTB01_IRQHandler        , //56:  16-bit MPT0 IGBT trigger/ TMRB compare match detection 1
    INTMTCAP00_IRQHandler        , //57:  16-bit MPT0 input capture 0
    INTMTCAP01_IRQHandler        , //58:  16-bit MPT0 input capture 1
    INTMTEMG1_IRQHandler         , //59:  16-bit MPT1 IGBT EMG interrupt
    INTMTPTB10_IRQHandler        , //60:  16-bit MPT1 IGBT period/ TMRB compare match detection 0
    INTMTTTB11_IRQHandler        , //61:  16-bit MPT1 IGBT trigger/ TMRB compare match detection 1
    INTMTCAP10_IRQHandler        , //62:  16-bit MPT1 input capture 0
    INTMTCAP11_IRQHandler        , //63:  16-bit MPT1 input capture 1
    INTMTEMG2_IRQHandler         , //64:  16-bit MPT2 IGBT EMG interrupt
    INTMTPTB20_IRQHandler        , //65:  16-bit MPT2 IGBT period/ TMRB compare match detection 0
    INTMTTTB21_IRQHandler        , //66:  16-bit MPT2 IGBT trigger/ TMRB compare match detection 1
    INTMTCAP20_IRQHandler        , //67:  16-bit MPT2 input capture 0
    INTMTCAP21_IRQHandler        , //68:  16-bit MPT2 input capture 1
    INTMTEMG3_IRQHandler         , //69:  16-bit MPT3 IGBT EMG interrupt
    INTMTPTB30_IRQHandler        , //70:  16-bit MPT3 IGBT period/ TMRB compare match detection 0
    INTMTTTB31_IRQHandler        , //71:  16-bit MPT3 IGBT trigger/ TMRB compare match detection 1
    INTMTCAP30_IRQHandler        , //72:  16-bit MPT3 input capture 0
    INTMTCAP31_IRQHandler        , //73:  16-bit MPT3 input capture 1
    INTRMCRX_IRQHandler          , //74:  Remote Controller reception interrupt
    INTTB0_IRQHandler            , //75:  16-bit TMRB_0 match detection 0
    INTCAP00_IRQHandler          , //76:  16-bit TMRB_0 input capture 00
    INTCAP01_IRQHandler          , //77:  16-bit TMRB_0 input capture 01
    INTTB1_IRQHandler            , //78:  16-bit TMRB_1 match detection 1
    INTCAP10_IRQHandler          , //79:  16-bit TMRB_1 input capture 10
    INTCAP11_IRQHandler          , //80:  16-bit TMRB_1 input capture 11
    INTTB2_IRQHandler            , //81:  16-bit TMRB_2 match detection 2
    INTCAP20_IRQHandler          , //82:  16-bit TMRB_2 input capture 20
    INTCAP21_IRQHandler          , //83:  16-bit TMRB_2 input capture 21
    INTTB3_IRQHandler            , //84:  16-bit TMRB_3 match detection 3
    INTCAP30_IRQHandler          , //85:  16-bit TMRB_3 input capture 30
    INTCAP31_IRQHandler          , //86:  16-bit TMRB_3 input capture 31
    INTTB4_IRQHandler            , //87:  16-bit TMRB_4 match detection 4
    INTCAP40_IRQHandler          , //88:  16-bit TMRB_4 input capture 40
    INTCAP41_IRQHandler          , //89:  16-bit TMRB_4 input capture 41
    INTTB5_IRQHandler            , //90:  16-bit TMRB_5 match detection 5
    INTCAP50_IRQHandler          , //91:  16-bit TMRB_5 input capture 50
    INTCAP51_IRQHandler          , //92:  16-bit TMRB_5 input capture 51
    INTTB6_IRQHandler            , //93:  16-bit TMRB_6 match detection 6
    INTCAP60_IRQHandler          , //94:  16-bit TMRB_6 input capture 60
    INTCAP61_IRQHandler          , //95:  16-bit TMRB_6 input capture 61
    INTTB7_IRQHandler            , //96:  16-bit TMRB_7 match detection 7
    INTCAP70_IRQHandler          , //97:  16-bit TMRB_7 input capture 70
    INTCAP71_IRQHandler          , //98:  16-bit TMRB_7 input capture 71
    INTRTC_IRQHandler            , //99:  RTC(Real time clock) interrupt
    INTDMAADA_IRQHandler         , //100: DMA_ADC_A conversion end
    INTDMAADB_IRQHandler         , //101: DMA_ADC_B conversion end
    INTDMADAA_IRQHandler         , //102: DMA_DAC_A conversion trigger
    INTDMADAB_IRQHandler         , //103: DMA_DAC_B conversion trigger
    INTDMASPR0_IRQHandler        , //104: DMA_SSP_0 reception / DMA_I2C SIO_0
    INTDMASPT0_IRQHandler        , //105: DMA_SSP_0 transmission
    INTDMASPR1_IRQHandler        , //106: DMA_SSP_1 reception
    INTDMASPT1_IRQHandler        , //107: DMA_SSP_1 transmission
    INTDMASPR2_IRQHandler        , //108: DMA_SSP_2 reception
    INTDMASPT2_IRQHandler        , //109: DMA_SSP_2 transmission
    INTDMAUTR4_IRQHandler        , //110: DMA_FUART_4 reception
    INTDMAUTT4_IRQHandler        , //111: DMA_FUART_4 transmission
    INTDMAUTR5_IRQHandler        , //112: DMA_FUART_5 reception
    INTDMAUTT5_IRQHandler        , //113: DMA_FUART_5 transmission
    INTDMARX0_IRQHandler         , //114: DMA_SIO/ UART_0 reception
    INTDMATX0_IRQHandler         , //115: DMA_SIO/ UART_0 transmission
    INTDMARX1_IRQHandler         , //116: DMA_SIO/ UART_1 reception
    INTDMATX1_IRQHandler         , //117: DMA_SIO/ UART_1 transmission
    INTDMARX2_IRQHandler         , //118: DMA_SIO/ UART_2 reception
    INTDMATX2_IRQHandler         , //119: DMA_SIO/ UART_2 transmission
    INTDMARX3_IRQHandler         , //120: DMA_SIO/ UART_3 reception
    INTDMATX3_IRQHandler         , //121: DMA_SIO/ UART_3 transmission
    INTDMASBI1_IRQHandler        , //122: DMA_I2C/ SIO_1
    INTDMASBI2_IRQHandler        , //123: DMA_I2C/ SIO_2
    INTDMATB_IRQHandler          , //124: 16-bit TMRB_0-4 match detection
    INTDMARQ_IRQHandler          , //125: DMA request pin
    INTDMAAERR_IRQHandler        , //126: DMA_A error transfer interrupt
    INTDMABERR_IRQHandler        , //127: DMA_B error transfer interrupt

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

// External Interrupts
#pragma weak INT0_IRQHandler        = DefaultIntHandler //0:   Interrupt pin 0
#pragma weak INT1_IRQHandler        = DefaultIntHandler //1:   Interrupt pin 1
#pragma weak INT2_IRQHandler        = DefaultIntHandler //2:   Interrupt pin 2
#pragma weak INT3_IRQHandler        = DefaultIntHandler //3:   Interrupt pin 3
#pragma weak INT4_IRQHandler        = DefaultIntHandler //4:   Interrupt pin 4
#pragma weak INT5_IRQHandler        = DefaultIntHandler //5:   Interrupt pin 5
#pragma weak INT6_IRQHandler        = DefaultIntHandler //6:   Interrupt pin 6
#pragma weak INT7_IRQHandler        = DefaultIntHandler //7:   Interrupt pin 7
#pragma weak INT8_IRQHandler        = DefaultIntHandler //8:   Interrupt pin 8
#pragma weak INT9_IRQHandler        = DefaultIntHandler //9:   Interrupt pin 9
#pragma weak INTA_IRQHandler        = DefaultIntHandler //10:  Interrupt pin A
#pragma weak INTB_IRQHandler        = DefaultIntHandler //11:  Interrupt pin B
#pragma weak INTC_IRQHandler        = DefaultIntHandler //12:  Interrupt pin C
#pragma weak INTD_IRQHandler        = DefaultIntHandler //13:  Interrupt pin D
#pragma weak INTE_IRQHandler        = DefaultIntHandler //14:  Interrupt pin E
#pragma weak INTF_IRQHandler        = DefaultIntHandler //15:  Interrupt pin F
#pragma weak INTRX0_IRQHandler      = DefaultIntHandler //16:  Serial reception (channel.0)
#pragma weak INTTX0_IRQHandler      = DefaultIntHandler //17:  Serial transmission (channel.0)
#pragma weak INTRX1_IRQHandler      = DefaultIntHandler //18:  Serial reception (channel.1)
#pragma weak INTTX1_IRQHandler      = DefaultIntHandler //19:  Serial transmission (channel.1)
#pragma weak INTRX2_IRQHandler      = DefaultIntHandler //20:  Serial reception (channel.2)
#pragma weak INTTX2_IRQHandler      = DefaultIntHandler //21:  Serial transmission (channel.2)
#pragma weak INTRX3_IRQHandler      = DefaultIntHandler //22:  Serial reception (channel.3)
#pragma weak INTTX3_IRQHandler      = DefaultIntHandler //23:  Serial transmission (channel.3)
#pragma weak INTUART4_IRQHandler    = DefaultIntHandler //24:  FULL UART(channel.4)
#pragma weak INTUART5_IRQHandler    = DefaultIntHandler //25:  FULL UART(channel.5)
#pragma weak INTSBI0_IRQHandler     = DefaultIntHandler //26:  Serial bus interface 0
#pragma weak INTSBI1_IRQHandler     = DefaultIntHandler //27:  Serial bus interface 1
#pragma weak INTSBI2_IRQHandler     = DefaultIntHandler //28:  Serial bus interface 2
#pragma weak INTSSP0_IRQHandler     = DefaultIntHandler //29:  SPI serial interface 0
#pragma weak INTSSP1_IRQHandler     = DefaultIntHandler //30:  SPI serial interface 1
#pragma weak INTSSP2_IRQHandler     = DefaultIntHandler //31:  SPI serial interface 2
#pragma weak INTUSBH_IRQHandler     = DefaultIntHandler //32:  USB Host Interrupt
#pragma weak INTUSBD_IRQHandler     = DefaultIntHandler //33:  USB Device Interrupt
#pragma weak INTUSBWKUP_IRQHandler  = DefaultIntHandler //34:  USB WakeUp
#pragma weak INTCANRX_IRQHandler    = DefaultIntHandler //35:  CAN RX
#pragma weak INTCANTX_IRQHandler    = DefaultIntHandler //36:  CAN TX
#pragma weak INTCANGB_IRQHandler    = DefaultIntHandler //37:  CAN STAUTS
#pragma weak INTETH_IRQHandler      = DefaultIntHandler //38:  EtherNET Interrupt
#pragma weak INTETHWK_IRQHandler    = DefaultIntHandler //39:  EtherNET(magic packet detection) interrupt
#pragma weak INTADAHP_IRQHandler    = DefaultIntHandler //40:  Highest priority AD conversion complete interrupt (channel.A)
#pragma weak INTADAM0_IRQHandler    = DefaultIntHandler //41:  AD conversion monitoring function interrupt 0(channel.A)
#pragma weak INTADAM1_IRQHandler    = DefaultIntHandler //42:  AD conversion monitoring function interrupt 1(channel.A)
#pragma weak INTADA_IRQHandler      = DefaultIntHandler //43:  AD conversion interrupt(channel.A)
#pragma weak INTADBHP_IRQHandler    = DefaultIntHandler //44:  Highest priority AD conversion complete interrupt (channel.B)
#pragma weak INTADBM0_IRQHandler    = DefaultIntHandler //45:  AD conversion monitoring function interrupt 0(channel.B)
#pragma weak INTADBM1_IRQHandler    = DefaultIntHandler //46:  AD conversion monitoring function interrupt 1(channel.B)
#pragma weak INTADB_IRQHandler      = DefaultIntHandler //47:  AD conversion interrupt(channel.B)
#pragma weak INTEMG0_IRQHandler     = DefaultIntHandler //48:  PMD0 EMG interrupt (MPT0)
#pragma weak INTPMD0_IRQHandler     = DefaultIntHandler //49:  PMD0 PWM interrupt (MPT0)
#pragma weak INTENC0_IRQHandler     = DefaultIntHandler //50:  PMD0 Encoder input interrupt (MPT0)
#pragma weak INTEMG1_IRQHandler     = DefaultIntHandler //51:  PMD1 EMG interrupt (MPT1)
#pragma weak INTPMD1_IRQHandler     = DefaultIntHandler //52:  PMD1 PWM interrupt (MPT1)
#pragma weak INTENC1_IRQHandler     = DefaultIntHandler //53:  PMD1 Encoder input interrupt (MPT1)
#pragma weak INTMTEMG0_IRQHandler   = DefaultIntHandler //54:  16-bit MPT0 IGBT EMG interrupt
#pragma weak INTMTPTB00_IRQHandler  = DefaultIntHandler //55:  16-bit MPT0 IGBT period/ TMRB compare match detection 0
#pragma weak INTMTTTB01_IRQHandler  = DefaultIntHandler //56:  16-bit MPT0 IGBT trigger/ TMRB compare match detection 1
#pragma weak INTMTCAP00_IRQHandler  = DefaultIntHandler //57:  16-bit MPT0 input capture 0
#pragma weak INTMTCAP01_IRQHandler  = DefaultIntHandler //58:  16-bit MPT0 input capture 1
#pragma weak INTMTEMG1_IRQHandler   = DefaultIntHandler //59:  16-bit MPT1 IGBT EMG interrupt
#pragma weak INTMTPTB10_IRQHandler  = DefaultIntHandler //60:  16-bit MPT1 IGBT period/ TMRB compare match detection 0
#pragma weak INTMTTTB11_IRQHandler  = DefaultIntHandler //61:  16-bit MPT1 IGBT trigger/ TMRB compare match detection 1
#pragma weak INTMTCAP10_IRQHandler  = DefaultIntHandler //62:  16-bit MPT1 input capture 0
#pragma weak INTMTCAP11_IRQHandler  = DefaultIntHandler //63:  16-bit MPT1 input capture 1
#pragma weak INTMTEMG2_IRQHandler   = DefaultIntHandler //64:  16-bit MPT2 IGBT EMG interrupt
#pragma weak INTMTPTB20_IRQHandler  = DefaultIntHandler //65:  16-bit MPT2 IGBT period/ TMRB compare match detection 0
#pragma weak INTMTTTB21_IRQHandler  = DefaultIntHandler //66:  16-bit MPT2 IGBT trigger/ TMRB compare match detection 1
#pragma weak INTMTCAP20_IRQHandler  = DefaultIntHandler //67:  16-bit MPT2 input capture 0
#pragma weak INTMTCAP21_IRQHandler  = DefaultIntHandler //68:  16-bit MPT2 input capture 1
#pragma weak INTMTEMG3_IRQHandler   = DefaultIntHandler //69:  16-bit MPT3 IGBT EMG interrupt
#pragma weak INTMTPTB30_IRQHandler  = DefaultIntHandler //70:  16-bit MPT3 IGBT period/ TMRB compare match detection 0
#pragma weak INTMTTTB31_IRQHandler  = DefaultIntHandler //71:  16-bit MPT3 IGBT trigger/ TMRB compare match detection 1
#pragma weak INTMTCAP30_IRQHandler  = DefaultIntHandler //72:  16-bit MPT3 input capture 0
#pragma weak INTMTCAP31_IRQHandler  = DefaultIntHandler //73:  16-bit MPT3 input capture 1
#pragma weak INTRMCRX_IRQHandler    = DefaultIntHandler //74:  Remote Controller reception interrupt
#pragma weak INTTB0_IRQHandler      = DefaultIntHandler //75:  16-bit TMRB_0 match detection 0
#pragma weak INTCAP00_IRQHandler    = DefaultIntHandler //76:  16-bit TMRB_0 input capture 00
#pragma weak INTCAP01_IRQHandler    = DefaultIntHandler //77:  16-bit TMRB_0 input capture 01
#pragma weak INTTB1_IRQHandler      = DefaultIntHandler //78:  16-bit TMRB_1 match detection 1
#pragma weak INTCAP10_IRQHandler    = DefaultIntHandler //79:  16-bit TMRB_1 input capture 10
#pragma weak INTCAP11_IRQHandler    = DefaultIntHandler //80:  16-bit TMRB_1 input capture 11
#pragma weak INTTB2_IRQHandler      = DefaultIntHandler //81:  16-bit TMRB_2 match detection 2
#pragma weak INTCAP20_IRQHandler    = DefaultIntHandler //82:  16-bit TMRB_2 input capture 20
#pragma weak INTCAP21_IRQHandler    = DefaultIntHandler //83:  16-bit TMRB_2 input capture 21
#pragma weak INTTB3_IRQHandler      = DefaultIntHandler //84:  16-bit TMRB_3 match detection 3
#pragma weak INTCAP30_IRQHandler    = DefaultIntHandler //85:  16-bit TMRB_3 input capture 30
#pragma weak INTCAP31_IRQHandler    = DefaultIntHandler //86:  16-bit TMRB_3 input capture 31
#pragma weak INTTB4_IRQHandler      = DefaultIntHandler //87:  16-bit TMRB_4 match detection 4
#pragma weak INTCAP40_IRQHandler    = DefaultIntHandler //88:  16-bit TMRB_4 input capture 40
#pragma weak INTCAP41_IRQHandler    = DefaultIntHandler //89:  16-bit TMRB_4 input capture 41
#pragma weak INTTB5_IRQHandler      = DefaultIntHandler //90:  16-bit TMRB_5 match detection 5
#pragma weak INTCAP50_IRQHandler    = DefaultIntHandler //91:  16-bit TMRB_5 input capture 50
#pragma weak INTCAP51_IRQHandler    = DefaultIntHandler //92:  16-bit TMRB_5 input capture 51
#pragma weak INTTB6_IRQHandler      = DefaultIntHandler //93:  16-bit TMRB_6 match detection 6
#pragma weak INTCAP60_IRQHandler    = DefaultIntHandler //94:  16-bit TMRB_6 input capture 60
#pragma weak INTCAP61_IRQHandler    = DefaultIntHandler //95:  16-bit TMRB_6 input capture 61
#pragma weak INTTB7_IRQHandler      = DefaultIntHandler //96:  16-bit TMRB_7 match detection 7
#pragma weak INTCAP70_IRQHandler    = DefaultIntHandler //97:  16-bit TMRB_7 input capture 70
#pragma weak INTCAP71_IRQHandler    = DefaultIntHandler //98:  16-bit TMRB_7 input capture 71
#pragma weak INTRTC_IRQHandler      = DefaultIntHandler //99:  RTC(Real time clock) interrupt
#pragma weak INTDMAADA_IRQHandler   = DefaultIntHandler //100: DMA_ADC_A conversion end
#pragma weak INTDMAADB_IRQHandler   = DefaultIntHandler //101: DMA_ADC_B conversion end
#pragma weak INTDMADAA_IRQHandler   = DefaultIntHandler //102: DMA_DAC_A conversion trigger
#pragma weak INTDMADAB_IRQHandler   = DefaultIntHandler //103: DMA_DAC_B conversion trigger
#pragma weak INTDMASPR0_IRQHandler  = DefaultIntHandler //104: DMA_SSP_0 reception / DMA_I2C SIO_0
#pragma weak INTDMASPT0_IRQHandler  = DefaultIntHandler //105: DMA_SSP_0 transmission
#pragma weak INTDMASPR1_IRQHandler  = DefaultIntHandler //106: DMA_SSP_1 reception
#pragma weak INTDMASPT1_IRQHandler  = DefaultIntHandler //107: DMA_SSP_1 transmission
#pragma weak INTDMASPR2_IRQHandler  = DefaultIntHandler //108: DMA_SSP_2 reception
#pragma weak INTDMASPT2_IRQHandler  = DefaultIntHandler //109: DMA_SSP_2 transmission
#pragma weak INTDMAUTR4_IRQHandler  = DefaultIntHandler //110: DMA_FUART_4 reception
#pragma weak INTDMAUTT4_IRQHandler  = DefaultIntHandler //111: DMA_FUART_4 transmission
#pragma weak INTDMAUTR5_IRQHandler  = DefaultIntHandler //112: DMA_FUART_5 reception
#pragma weak INTDMAUTT5_IRQHandler  = DefaultIntHandler //113: DMA_FUART_5 transmission
#pragma weak INTDMARX0_IRQHandler   = DefaultIntHandler //114: DMA_SIO/ UART_0 reception
#pragma weak INTDMATX0_IRQHandler   = DefaultIntHandler //115: DMA_SIO/ UART_0 transmission
#pragma weak INTDMARX1_IRQHandler   = DefaultIntHandler //116: DMA_SIO/ UART_1 reception
#pragma weak INTDMATX1_IRQHandler   = DefaultIntHandler //117: DMA_SIO/ UART_1 transmission
#pragma weak INTDMARX2_IRQHandler   = DefaultIntHandler //118: DMA_SIO/ UART_2 reception
#pragma weak INTDMATX2_IRQHandler   = DefaultIntHandler //119: DMA_SIO/ UART_2 transmission
#pragma weak INTDMARX3_IRQHandler   = DefaultIntHandler //120: DMA_SIO/ UART_3 reception
#pragma weak INTDMATX3_IRQHandler   = DefaultIntHandler //121: DMA_SIO/ UART_3 transmission
#pragma weak INTDMASBI1_IRQHandler  = DefaultIntHandler //122: DMA_I2C/ SIO_1
#pragma weak INTDMASBI2_IRQHandler  = DefaultIntHandler //123: DMA_I2C/ SIO_2
#pragma weak INTDMATB_IRQHandler    = DefaultIntHandler //124: 16-bit TMRB_0-4 match detection
#pragma weak INTDMARQ_IRQHandler    = DefaultIntHandler //125: DMA request pin
#pragma weak INTDMAAERR_IRQHandler  = DefaultIntHandler //126: DMA_A error transfer interrupt
#pragma weak INTDMABERR_IRQHandler  = DefaultIntHandler //127: DMA_B error transfer interrupt

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

