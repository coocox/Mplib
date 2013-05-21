;/**
; *******************************************************************************
; * @file    startup_TMPM361.s
; * @brief   CMSIS Cortex-M3 Core Device Startup File for the
; *          TOSHIBA 'TMPM361' Device Series 
; * @version V2.2.0
; * @date    2010/05/31
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
; * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
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
                DCD     0                         ; 8:  Reserved
                DCD     0                         ; 9:  Reserved
                DCD     0                         ; 10: Reserved
                DCD     0                         ; 11: Reserved
                DCD     0                         ; 12: Reserved
                DCD     0                         ; 13: Reserved
                DCD     INTE_IRQHandler           ; 14: Interrupt pin E
                DCD     INTF_IRQHandler           ; 15: Interrupt pin F
                DCD     INTRX0_IRQHandler         ; 16: Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 17: Serial transmission (channel.0)
                DCD     INTRX1_IRQHandler         ; 18: Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 19: Serial transmission (channel.1)
                DCD     INTRX2_IRQHandler         ; 20: Serial reception (channel.2)
                DCD     INTTX2_IRQHandler         ; 21: Serial transmission (channel.2)
                DCD     INTRX3_IRQHandler         ; 22: Serial reception (channel.3)
                DCD     INTTX3_IRQHandler         ; 23: Serial transmission (channel.3)
                DCD     INTRX4_IRQHandler         ; 24: Serial reception (channel.4)
                DCD     INTTX4_IRQHandler         ; 25: Serial transmission (channel.4)
                DCD     INTSBI0_IRQHandler        ; 26: Serial bus interface (channel.0)
                DCD     INTSBI1_IRQHandler        ; 27: Serial bus interface (channel.1)
                DCD     INTCECRX_IRQHandler       ; 28: CEC reception
                DCD     INTCECTX_IRQHandler       ; 29: CEC transmission
                DCD     INTRMCRX0_IRQHandler      ; 30: Remote control signal reception (channel.0)
                DCD     0                         ; 31: Reserved
                DCD     INTRTC_IRQHandler         ; 32: Real time clock timer
                DCD     INTKWUP_IRQHandler        ; 33: Key on wake up
                DCD     INTSBI2_IRQHandler        ; 34: Serial bus interface (channel.2)
                DCD     INTSBI3_IRQHandler        ; 35: Serial bus interface (channel.3)
                DCD     0                         ; 36: Reserved
                DCD     INTADHP_IRQHandler        ; 37: Highest priority AD conversion complete interrupt
                DCD     INTADM0_IRQHandler        ; 38: AD conversion monitoring function interrupt 0
                DCD     INTADM1_IRQHandler        ; 39: AD conversion monitoring function interrupt 1
                DCD     INTTB0_IRQHandler         ; 40: 16bit TMRB match detection 0
                DCD     INTTB1_IRQHandler         ; 41: 16bit TMRB match detection 1
                DCD     INTTB2_IRQHandler         ; 42: 16bit TMRB match detection 2
                DCD     INTTB3_IRQHandler         ; 43: 16bit TMRB match detection 3
                DCD     INTTB4_IRQHandler         ; 44: 16bit TMRB match detection 4
                DCD     INTTB5_IRQHandler         ; 45: 16bit TMRB match detection 5
                DCD     INTTB6_IRQHandler         ; 46: 16bit TMRB match detection 6
                DCD     INTTB7_IRQHandler         ; 47: 16bit TMRB match detection 7
                DCD     INTTB8_IRQHandler         ; 48: 16bit TMRB match detection 8
                DCD     INTTB9_IRQHandler         ; 49: 16bit TMRB match detection 9
                DCD     INTTBA_IRQHandler         ; 50: 16bit TMRB match detection A
                DCD     INTTBB_IRQHandler         ; 51: 16bit TMRB match detection B
                DCD     INTTBC_IRQHandler         ; 52: 16bit TMRB match detection C
                DCD     INTTBD_IRQHandler         ; 53: 16bit TMRB match detection D
                DCD     INTTBE_IRQHandler         ; 54: 16bit TMRB match detection E
                DCD     INTTBF_IRQHandler         ; 55: 16bit TMRB match detection F
                DCD     0                         ; 56: Reserved
                DCD     0                         ; 57: Reserved
                DCD     INTAD_IRQHandler          ; 58: ADC conversion completion
                DCD     INTSSP_IRQHandler         ; 59: Synchronous Serial Port
                DCD     0                         ; 60: Reserved
                DCD     0                         ; 61: Reserved
                DCD     0                         ; 62: Reserved
                DCD     0                         ; 63: Reserved
                DCD     0                         ; 64: Reserved
                DCD     0                         ; 65: Reserved
                DCD     0                         ; 66: Reserved
                DCD     0                         ; 67: Reserved
                DCD     0                         ; 68: Reserved
                DCD     0                         ; 69: Reserved
                DCD     0                         ; 70: Reserved
                DCD     0                         ; 71: Reserved
                DCD     0                         ; 72: Reserved
                DCD     0                         ; 73: Reserved
                DCD     INTCAP10_IRQHandler       ; 74: 16bit TMRB input capture 10
                DCD     INTCAP11_IRQHandler       ; 75: 16bit TMRB input capture 11
                DCD     INTCAP20_IRQHandler       ; 76: 16bit TMRB input capture 20
                DCD     INTCAP21_IRQHandler       ; 77: 16bit TMRB input capture 21
                DCD     0                         ; 78: Reserved
                DCD     0                         ; 79: Reserved
                DCD     INTCAP50_IRQHandler       ; 80: 16bit TMRB input capture 50
                DCD     INTCAP51_IRQHandler       ; 81: 16bit TMRB input capture 51
                DCD     INTCAP60_IRQHandler       ; 82: 16bit TMRB input capture 60
                DCD     INTCAP61_IRQHandler       ; 83: 16bit TMRB input capture 61
                DCD     INTCAP70_IRQHandler       ; 84: 16bit TMRB input capture 70
                DCD     INTCAP71_IRQHandler       ; 85: 16bit TMRB input capture 71
                DCD     INTCAP90_IRQHandler       ; 86: 16bit TMRB input capture 90
                DCD     INTCAP91_IRQHandler       ; 87: 16bit TMRB input capture 91
                DCD     0                         ; 88: Reserved
                DCD     0                         ; 89: Reserved
                DCD     0                         ; 90: Reserved
                DCD     0                         ; 91: Reserved
                DCD     0                         ; 92: Reserved
                DCD     0                         ; 93: Reserved
                DCD     0                         ; 94: Reserved
                DCD     0                         ; 95: Reserved
                DCD     0                         ; 96: Reserved
                DCD     0                         ; 97: Reserved
                DCD     INTDMACERR_IRQHandler     ; 98: DMA transmission error
                DCD     INTDMACTC0_IRQHandler     ; 99: DMA transmission completion

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

                PUBWEAK INTE_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTE_IRQHandler
                B       INTE_IRQHandler

                PUBWEAK INTF_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTF_IRQHandler
                B       INTF_IRQHandler

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

                PUBWEAK INTSBI0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI0_IRQHandler
                B       INTSBI0_IRQHandler

                PUBWEAK INTSBI1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI1_IRQHandler
                B       INTSBI1_IRQHandler

                PUBWEAK INTCECRX_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCECRX_IRQHandler
                B       INTCECRX_IRQHandler

                PUBWEAK INTCECTX_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCECTX_IRQHandler
                B       INTCECTX_IRQHandler

                PUBWEAK INTRMCRX0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRMCRX0_IRQHandler
                B       INTRMCRX0_IRQHandler

                PUBWEAK INTRTC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRTC_IRQHandler
                B       INTRTC_IRQHandler

                PUBWEAK INTKWUP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTKWUP_IRQHandler 
                B       INTKWUP_IRQHandler 

                PUBWEAK INTSBI2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI2_IRQHandler 
                B       INTSBI2_IRQHandler 

                PUBWEAK INTSBI3_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTSBI3_IRQHandler 
                B       INTSBI3_IRQHandler

                PUBWEAK INTADHP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADHP_IRQHandler
                B       INTADHP_IRQHandler

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

                PUBWEAK INTTBA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBA_IRQHandler
                B       INTTBA_IRQHandler

                PUBWEAK INTTBB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBB_IRQHandler
                B       INTTBB_IRQHandler

                PUBWEAK INTTBC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBC_IRQHandler
                B       INTTBC_IRQHandler

                PUBWEAK INTTBD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBD_IRQHandler
                B       INTTBD_IRQHandler

                PUBWEAK INTTBE_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBE_IRQHandler
                B       INTTBE_IRQHandler

                PUBWEAK INTTBF_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTBF_IRQHandler
                B       INTTBF_IRQHandler

                PUBWEAK INTAD_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTAD_IRQHandler 
                B       INTAD_IRQHandler 

                PUBWEAK INTSSP_IRQHandler 
                SECTION .text:CODE:REORDER(1)
INTSSP_IRQHandler 
                B       INTSSP_IRQHandler

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

                PUBWEAK INTCAP90_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP90_IRQHandler
                B       INTCAP90_IRQHandler

                PUBWEAK INTCAP91_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP91_IRQHandler
                B       INTCAP91_IRQHandler

                PUBWEAK INTDMACERR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMACERR_IRQHandler
                B       INTDMACERR_IRQHandler

                PUBWEAK INTDMACTC0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMACTC0_IRQHandler
                B       INTDMACTC0_IRQHandler

                END
