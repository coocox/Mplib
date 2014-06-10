;/**
; *******************************************************************************
; * @file    startup_TMPM341.s
; * @brief   CMSIS Cortex-M3 Core Device Startup File for the
; *          TOSHIBA 'TMPM341' Device Series 
; * @version V2.0.2.5 (Tentative)
; * @date    2011/03/01
; * 
; * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
; * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
; * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
; * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
; * 
; * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
; * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
; * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
; * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
; * 
; * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
; * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
; * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
; * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
; * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
; * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
; * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
; * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
; * 
; * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
; *******************************************************************************
; */
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; Cortex-M version
;

                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table

                DATA
__vector_table  DCD     sfe(CSTACK)
                DCD     Reset_Handler

                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     INT0_IRQHandler           ; 0:  Interrupt pin 0
                DCD     INT1_IRQHandler           ; 1:  Interrupt pin 1
                DCD     INT2_IRQHandler           ; 2:  Interrupt pin 2
                DCD     INT3_IRQHandler           ; 3:  Interrupt pin 3
                DCD     INT4_IRQHandler           ; 4:  Interrupt pin 4
                DCD     INT5_IRQHandler           ; 5:  Interrupt pin 5
                DCD     INT6_IRQHandler           ; 6:  Interrupt pin 6
                DCD     INT7_IRQHandler           ; 7:  Interrupt pin 7
                DCD     INTRX0_IRQHandler         ; 8:  Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 9:  Serial transmission (channel.0)
                DCD     INTRX1_IRQHandler         ; 10: Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 11: Serial transmission (channel.1)
                DCD     INTRX2_IRQHandler         ; 12: Serial reception (channel.2)
                DCD     INTTX2_IRQHandler         ; 13: Serial transmission (channel.2)
                DCD     INTSBI0_IRQHandler        ; 14: Serial bus interface 0
                DCD     INTSBI1_IRQHandler        ; 15: Serial bus interface 1
                DCD     INTADHP_IRQHandler        ; 16: Highest priority AD conversion complete interrupt
                DCD     INTAD_IRQHandler          ; 17: AD conversion interrupt
                DCD     INTADM0_IRQHandler        ; 18: AD conversion monitoring function interrupt 0
                DCD     INTADM1_IRQHandler        ; 19: AD conversion monitoring function interrupt 1
                DCD     INTTB0_IRQHandler         ; 20: 16-bit TMRB match detection 0
                DCD     INTTB1_IRQHandler         ; 21: 16-bit TMRB match detection 1
                DCD     INTTB2_IRQHandler         ; 22: 16-bit TMRB match detection 2
                DCD     INTTB3_IRQHandler         ; 23: 16-bit TMRB match detection 3
                DCD     INTTB4_IRQHandler         ; 24: 16-bit TMRB match detection 4
                DCD     INTTB5_IRQHandler         ; 25: 16-bit TMRB match detection 5
                DCD     INTTB6_IRQHandler         ; 26: 16-bit TMRB match detection 6
                DCD     INTTB7_IRQHandler         ; 27: 16-bit TMRB match detection 7
                DCD     INTTB8_IRQHandler         ; 28: 16-bit TMRB match detection 8
                DCD     INTTB9_IRQHandler         ; 29: 16-bit TMRB match detection 9
                DCD     INTTD0CMP0_IRQHandler     ; 30: 16-bit TMRD0 compare interrupt 0
                DCD     INTTD0CMP1_IRQHandler     ; 31: 16-bit TMRD0 compare interrupt 1
                DCD     INTTD0CMP2_IRQHandler     ; 32: 16-bit TMRD0 compare interrupt 2
                DCD     INTTD0CMP3_IRQHandler     ; 33: 16-bit TMRD0 compare interrupt 3
                DCD     INTTD0CMP4_IRQHandler     ; 34: 16-bit TMRD0 compare interrupt 4
                DCD     INTTD1CMP0_IRQHandler     ; 35: 16-bit TMRD1 compare interrupt 0
                DCD     INTTD1CMP1_IRQHandler     ; 36: 16-bit TMRD1 compare interrupt 1
                DCD     INTTD1CMP2_IRQHandler     ; 37: 16-bit TMRD1 compare interrupt 2
                DCD     INTTD1CMP3_IRQHandler     ; 38: 16-bit TMRD1 compare interrupt 3
                DCD     INTTD1CMP4_IRQHandler     ; 39: 16-bit TMRD1 compare interrupt 4
                DCD     INTPHT00_IRQHandler       ; 40: 16-bit PHC compare interrupt 00
                DCD     INTPHT01_IRQHandler       ; 41: 16-bit PHC compare interrupt 01
                DCD     INTPHT10_IRQHandler       ; 42: 16-bit PHC compare interrupt 10
                DCD     INTPHT11_IRQHandler       ; 43: 16-bit PHC compare interrupt 11
                DCD     INTPHT20_IRQHandler       ; 44: 16-bit PHC compare interrupt 20
                DCD     INTPHT21_IRQHandler       ; 45: 16-bit PHC compare interrupt 21
                DCD     INTPHT30_IRQHandler       ; 46: 16-bit PHC compare interrupt 30
                DCD     INTPHT31_IRQHandler       ; 47: 16-bit PHC compare interrupt 31
                DCD     INTPHEVRY0_IRQHandler     ; 48: 16-bit PHC every count interrupt 0
                DCD     INTPHEVRY1_IRQHandler     ; 49: 16-bit PHC every count interrupt 1
                DCD     INTPHEVRY2_IRQHandler     ; 50: 16-bit PHC every count interrupt 2
                DCD     INTPHEVRY3_IRQHandler     ; 51: 16-bit PHC every count interrupt 3
                DCD     INTRX3_IRQHandler         ; 52: Serial reception (channel.3)
                DCD     INTTX3_IRQHandler         ; 53: Serial transmission (channel.3)
                DCD     INTRX4_IRQHandler         ; 54: Serial reception (channel.4)
                DCD     INTTX4_IRQHandler         ; 55: Serial transmission (channel.4)
                DCD     INTCAP00_IRQHandler       ; 56: 16-bit TMRB input capture 00
                DCD     INTCAP01_IRQHandler       ; 57: 16-bit TMRB input capture 01
                DCD     INTCAP10_IRQHandler       ; 58: 16-bit TMRB input capture 10
                DCD     INTCAP11_IRQHandler       ; 59: 16-bit TMRB input capture 11
                DCD     INTCAP20_IRQHandler       ; 60: 16-bit TMRB input capture 20
                DCD     INTCAP21_IRQHandler       ; 61: 16-bit TMRB input capture 21
                DCD     INTCAP30_IRQHandler       ; 62: 16-bit TMRB input capture 30
                DCD     INTCAP31_IRQHandler       ; 63: 16-bit TMRB input capture 31
                DCD     INTCAP40_IRQHandler       ; 64: 16-bit TMRB input capture 40
                DCD     INTCAP41_IRQHandler       ; 65: 16-bit TMRB input capture 41
                DCD     INTCAP50_IRQHandler       ; 66: 16-bit TMRB input capture 50
                DCD     INTCAP51_IRQHandler       ; 67: 16-bit TMRB input capture 51
                DCD     INTCAP60_IRQHandler       ; 68: 16-bit TMRB input capture 60
                DCD     INTCAP61_IRQHandler       ; 69: 16-bit TMRB input capture 61
                DCD     INTCAP70_IRQHandler       ; 70: 16-bit TMRB input capture 70
                DCD     INTCAP71_IRQHandler       ; 71: 16-bit TMRB input capture 71
                DCD     INTCAP80_IRQHandler       ; 72: 16-bit TMRB input capture 80
                DCD     INTCAP81_IRQHandler       ; 73: 16-bit TMRB input capture 81
                DCD     INTCAP90_IRQHandler       ; 74: 16-bit TMRB input capture 90
                DCD     INTCAP91_IRQHandler       ; 75: 16-bit TMRB input capture 91
                DCD     INT8_IRQHandler           ; 76: Interrupt pin 8
                DCD     INT9_IRQHandler           ; 77: Interrupt pin 9
                DCD     INTA_IRQHandler           ; 78: Interrupt pin A
                DCD     INTB_IRQHandler           ; 79: Interrupt pin B
                DCD     INTDMAC0TC_IRQHandler     ; 80: DMA terminal count status interrupt 0
                DCD     INTDMAC1TC_IRQHandler     ; 81: DMA terminal count status interrupt 1
                DCD     INTDMAC0ERR_IRQHandler    ; 82: DMA error status interrupt 0
                DCD     INTDMAC1ERR_IRQHandler    ; 83: DMA error status interrupt 1
                DCD     INTSSP_IRQHandler         ; 84: SPI serial interface

                THUMB
; Dummy Exception Handlers (infinite loops which can be modified)

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER(2)
Reset_Handler
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                SECTION .text:CODE:REORDER(1)
NMI_Handler
                B       NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:REORDER(1)
HardFault_Handler
                B       HardFault_Handler

                PUBWEAK MemManage_Handler
                SECTION .text:CODE:REORDER(1)
MemManage_Handler
                B       MemManage_Handler

                PUBWEAK BusFault_Handler
                SECTION .text:CODE:REORDER(1)
BusFault_Handler
                B       BusFault_Handler

                PUBWEAK UsageFault_Handler
                SECTION .text:CODE:REORDER(1)
UsageFault_Handler
                B       UsageFault_Handler

                PUBWEAK SVC_Handler
                SECTION .text:CODE:REORDER(1)
SVC_Handler
                B       SVC_Handler

                PUBWEAK DebugMon_Handler
                SECTION .text:CODE:REORDER(1)
DebugMon_Handler
                B       DebugMon_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:REORDER(1)
PendSV_Handler
                B       PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:REORDER(1)
SysTick_Handler
                B       SysTick_Handler

                PUBWEAK INT0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT0_IRQHandler
                B       INT0_IRQHandler

                PUBWEAK INT1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT1_IRQHandler
                B       INT1_IRQHandler

                PUBWEAK INT2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT2_IRQHandler
                B       INT2_IRQHandler

                PUBWEAK INT3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT3_IRQHandler
                B       INT3_IRQHandler

                PUBWEAK INT4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT4_IRQHandler
                B       INT4_IRQHandler

                PUBWEAK INT5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT5_IRQHandler
                B       INT5_IRQHandler

                PUBWEAK INT6_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT6_IRQHandler
                B       INT6_IRQHandler

                PUBWEAK INT7_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT7_IRQHandler
                B       INT7_IRQHandler

                PUBWEAK INTRX0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX0_IRQHandler
                B       INTRX0_IRQHandler

                PUBWEAK INTTX0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX0_IRQHandler
                B       INTTX0_IRQHandler

                PUBWEAK INTRX1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX1_IRQHandler
                B       INTRX1_IRQHandler

                PUBWEAK INTTX1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX1_IRQHandler
                B       INTTX1_IRQHandler

                PUBWEAK INTRX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX2_IRQHandler
                B       INTRX2_IRQHandler

                PUBWEAK INTTX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX2_IRQHandler
                B       INTTX2_IRQHandler

                PUBWEAK INTSBI0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI0_IRQHandler
                B       INTSBI0_IRQHandler

                PUBWEAK INTSBI1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI1_IRQHandler
                B       INTSBI1_IRQHandler

                PUBWEAK INTADHP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADHP_IRQHandler
                B       INTADHP_IRQHandler

                PUBWEAK INTAD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTAD_IRQHandler
                B       INTAD_IRQHandler

                PUBWEAK INTADM0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADM0_IRQHandler
                B       INTADM0_IRQHandler

                PUBWEAK INTADM1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADM1_IRQHandler
                B       INTADM1_IRQHandler

                PUBWEAK INTTB0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB0_IRQHandler
                B       INTTB0_IRQHandler

                PUBWEAK INTTB1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB1_IRQHandler
                B       INTTB1_IRQHandler

                PUBWEAK INTTB2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB2_IRQHandler
                B       INTTB2_IRQHandler

                PUBWEAK INTTB3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB3_IRQHandler
                B       INTTB3_IRQHandler

                PUBWEAK INTTB4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB4_IRQHandler
                B       INTTB4_IRQHandler

                PUBWEAK INTTB5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB5_IRQHandler
                B       INTTB5_IRQHandler

                PUBWEAK INTTB6_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB6_IRQHandler
                B       INTTB6_IRQHandler

                PUBWEAK INTTB7_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB7_IRQHandler
                B       INTTB7_IRQHandler

                PUBWEAK INTTB8_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB8_IRQHandler
                B       INTTB8_IRQHandler

                PUBWEAK INTTB9_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB9_IRQHandler
                B       INTTB9_IRQHandler

                PUBWEAK INTTD0CMP0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD0CMP0_IRQHandler
                B       INTTD0CMP0_IRQHandler

                PUBWEAK INTTD0CMP1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD0CMP1_IRQHandler
                B       INTTD0CMP1_IRQHandler

                PUBWEAK INTTD0CMP2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD0CMP2_IRQHandler
                B       INTTD0CMP2_IRQHandler

                PUBWEAK INTTD0CMP3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD0CMP3_IRQHandler 
                B       INTTD0CMP3_IRQHandler

                PUBWEAK INTTD0CMP4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD0CMP4_IRQHandler 
                B       INTTD0CMP4_IRQHandler

                PUBWEAK INTTD1CMP0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD1CMP0_IRQHandler
                B       INTTD1CMP0_IRQHandler

                PUBWEAK INTTD1CMP1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD1CMP1_IRQHandler 
                B       INTTD1CMP1_IRQHandler

                PUBWEAK INTTD1CMP2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD1CMP2_IRQHandler
                B       INTTD1CMP2_IRQHandler

                PUBWEAK INTTD1CMP3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD1CMP3_IRQHandler
                B       INTTD1CMP3_IRQHandler

                PUBWEAK INTTD1CMP4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTD1CMP4_IRQHandler
                B       INTTD1CMP4_IRQHandler

                PUBWEAK INTPHT00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT00_IRQHandler
                B       INTPHT00_IRQHandler

                PUBWEAK INTPHT01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT01_IRQHandler
                B       INTPHT01_IRQHandler

                PUBWEAK INTPHT10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT10_IRQHandler
                B       INTPHT10_IRQHandler

                PUBWEAK INTPHT11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT11_IRQHandler
                B       INTPHT11_IRQHandler

                PUBWEAK INTPHT20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT20_IRQHandler
                B       INTPHT20_IRQHandler

                PUBWEAK INTPHT21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT21_IRQHandler
                B       INTPHT21_IRQHandler

                PUBWEAK INTPHT30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT30_IRQHandler
                B       INTPHT30_IRQHandler

                PUBWEAK INTPHT31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHT31_IRQHandler
                B       INTPHT31_IRQHandler

                PUBWEAK INTPHEVRY0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHEVRY0_IRQHandler
                B       INTPHEVRY0_IRQHandler

                PUBWEAK INTPHEVRY1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHEVRY1_IRQHandler
                B       INTPHEVRY1_IRQHandler

                PUBWEAK INTPHEVRY2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHEVRY2_IRQHandler
                B       INTPHEVRY2_IRQHandler

                PUBWEAK INTPHEVRY3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPHEVRY3_IRQHandler
                B       INTPHEVRY3_IRQHandler

                PUBWEAK INTRX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX3_IRQHandler
                B       INTRX3_IRQHandler

                PUBWEAK INTTX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX3_IRQHandler
                B       INTTX3_IRQHandler

                PUBWEAK INTRX4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX4_IRQHandler
                B       INTRX4_IRQHandler

                PUBWEAK INTTX4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX4_IRQHandler
                B       INTTX4_IRQHandler

                PUBWEAK INTCAP00_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP00_IRQHandler 
                B       INTCAP00_IRQHandler 

                PUBWEAK INTCAP01_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP01_IRQHandler 
                B       INTCAP01_IRQHandler 

                PUBWEAK INTCAP10_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP10_IRQHandler
                B       INTCAP10_IRQHandler

                PUBWEAK INTCAP11_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP11_IRQHandler
                B       INTCAP11_IRQHandler

                PUBWEAK INTCAP20_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP20_IRQHandler
                B       INTCAP20_IRQHandler

                PUBWEAK INTCAP21_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP21_IRQHandler
                B       INTCAP21_IRQHandler

                PUBWEAK INTCAP30_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP30_IRQHandler
                B       INTCAP30_IRQHandler

                PUBWEAK INTCAP31_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP31_IRQHandler
                B       INTCAP31_IRQHandler

                PUBWEAK INTCAP40_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP40_IRQHandler
                B       INTCAP40_IRQHandler

                PUBWEAK INTCAP41_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP41_IRQHandler
                B       INTCAP41_IRQHandler

                PUBWEAK INTCAP50_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP50_IRQHandler
                B       INTCAP50_IRQHandler

                PUBWEAK INTCAP51_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP51_IRQHandler
                B       INTCAP51_IRQHandler

                PUBWEAK INTCAP60_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP60_IRQHandler
                B       INTCAP60_IRQHandler

                PUBWEAK INTCAP61_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP61_IRQHandler
                B       INTCAP61_IRQHandler

                PUBWEAK INTCAP70_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP70_IRQHandler
                B       INTCAP70_IRQHandler

                PUBWEAK INTCAP71_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP71_IRQHandler
                B       INTCAP71_IRQHandler

                PUBWEAK INTCAP80_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP80_IRQHandler
                B       INTCAP80_IRQHandler

                PUBWEAK INTCAP81_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP81_IRQHandler
                B       INTCAP81_IRQHandler

                PUBWEAK INTCAP90_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTCAP90_IRQHandler
                B       INTCAP90_IRQHandler

                PUBWEAK INTCAP91_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP91_IRQHandler
                B       INTCAP91_IRQHandler

                PUBWEAK INT8_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT8_IRQHandler
                B       INT8_IRQHandler

                PUBWEAK INT9_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT9_IRQHandler
                B       INT9_IRQHandler

                PUBWEAK INTA_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTA_IRQHandler
                B       INTA_IRQHandler

                PUBWEAK INTB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTB_IRQHandler
                B       INTB_IRQHandler

                PUBWEAK INTDMAC0TC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAC0TC_IRQHandler
                B       INTDMAC0TC_IRQHandler

                PUBWEAK INTDMAC1TC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAC1TC_IRQHandler
                B       INTDMAC1TC_IRQHandler

                PUBWEAK INTDMAC0ERR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAC0ERR_IRQHandler
                B       INTDMAC0ERR_IRQHandler

                PUBWEAK INTDMAC1ERR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAC1ERR_IRQHandler
                B       INTDMAC1ERR_IRQHandler

                PUBWEAK INTSSP_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTSSP_IRQHandler
                B       INTSSP_IRQHandler

                END
