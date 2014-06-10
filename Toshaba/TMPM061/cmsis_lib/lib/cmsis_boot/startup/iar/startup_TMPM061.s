;/**
; *******************************************************************************
; * @file    startup_TMPM061.s
; * @brief   CMSIS Cortex-M0 Core Device Startup File for the
; *          TOSHIBA 'TMPM061' Device Series
; * @version V2.0.2.1 (Tentative)
; * @date    2012/03/13
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
; * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
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
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     INTPCE_IRQHandler         ; 0:	PCE interface
                DCD     INTDSAD0_IRQHandler       ; 1:	¦¤¦²A/D conversion complee interrupt (unit0)
                DCD     INTDSAD1_IRQHandler       ; 2:	¦¤¦²A/D conversion complee interrupt (unit1)
                DCD     INTDSAD2_IRQHandler       ; 3:	¦¤¦²A/D conversion complee interrupt (unit2)
                DCD     INTLVD_IRQHandler         ; 4:	Voltage detector interrupt
                DCD     INT0_IRQHandler           ; 5:	Interrupt pin 0
                DCD     INT1_IRQHandler           ; 6:	Interrupt pin 1
                DCD     INT2_IRQHandler           ; 7:	Interrupt pin 2
                DCD     INT3_IRQHandler           ; 8:	Interrupt pin 3
                DCD     INTRX0_IRQHandler         ; 9:	Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 10:	Serial transmission (channel.0)
                DCD     INTRX1_IRQHandler         ; 11:	Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 12:	Serial transmission (channel.1)
                DCD     INTRX2_IRQHandler         ; 13:	Serial reception (channel.2)
                DCD     INTTX2_IRQHandler         ; 14:	Serial transmission (channel.2)
                DCD     INTRX3_IRQHandler         ; 15:	Serial reception (channel.3)
                DCD     INTTX3_IRQHandler         ; 16:	Serial transmission (channel.3)
                DCD     INTSBI_IRQHandler         ; 17:	Serial bus interface
                DCD     INTTB0_IRQHandler         ; 18:	16-bit TMRB match detection 0
                DCD     INTTB1_IRQHandler         ; 19:	16-bit TMRB match detection 1
                DCD     INTCAP00_IRQHandler       ; 20:	16-bit TMRB input capture 0 (channel.0)
                DCD     INTCAP01_IRQHandler       ; 21:	16-bit TMRB input capture 1 (channel.0)
                DCD     INTCAP10_IRQHandler       ; 22:	16-bit TMRB input capture 0 (channel.1)
                DCD     INTCAP11_IRQHandler       ; 23:	16-bit TMRB input capture 1 (channel.1)
                DCD     INTT16A0_IRQHandler       ; 24:	16-bit TMR16A match detection (channel.0)
                DCD     INTT16A1_IRQHandler       ; 25:	16-bit TMR16A match detection (channel.1)
                DCD     INTT16A2_IRQHandler       ; 26:	16-bit TMR16A match detection (channel.2)
                DCD     INTT16A3_IRQHandler       ; 27:	16-bit TMR16A match detection (channel.3)
                DCD     INTT16A5_IRQHandler       ; 28:	16-bit TMR16A match detection (channel.5)
                DCD     INTT16A6_IRQHandler       ; 29:	16-bit TMR16A match detection (channel.6)
                DCD     INTRTC_IRQHandler         ; 30:	Real time clock
                DCD     INTAD_IRQHandler          ; 31:	A/D conversion completion interrupt
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

                PUBWEAK SVC_Handler
                SECTION .text:CODE:REORDER(1)
SVC_Handler
                B       SVC_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:REORDER(1)
PendSV_Handler
                B       PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:REORDER(1)
SysTick_Handler
                B       SysTick_Handler

                PUBWEAK INTPCE_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPCE_IRQHandler
                B       INTPCE_IRQHandler

                PUBWEAK INTDSAD0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDSAD0_IRQHandler
                B       INTDSAD0_IRQHandler

                PUBWEAK INTDSAD1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDSAD1_IRQHandler
                B       INTDSAD1_IRQHandler

                PUBWEAK INTDSAD2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDSAD2_IRQHandler
                B       INTDSAD2_IRQHandler

                PUBWEAK INTLVD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTLVD_IRQHandler
                B       INTLVD_IRQHandler

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

                PUBWEAK INTSBI_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI_IRQHandler
                B       INTSBI_IRQHandler

                PUBWEAK INTTB0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB0_IRQHandler
                B       INTTB0_IRQHandler

                PUBWEAK INTTB1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB1_IRQHandler
                B       INTTB1_IRQHandler

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

                PUBWEAK INTT16A0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A0_IRQHandler
                B       INTT16A0_IRQHandler

                PUBWEAK INTT16A1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A1_IRQHandler
                B       INTT16A1_IRQHandler

                PUBWEAK INTT16A2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A2_IRQHandler
                B       INTT16A2_IRQHandler

                PUBWEAK INTT16A3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A3_IRQHandler
                B       INTT16A3_IRQHandler

                PUBWEAK INTT16A5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A5_IRQHandler
                B       INTT16A5_IRQHandler

                PUBWEAK INTT16A6_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTT16A6_IRQHandler
                B       INTT16A6_IRQHandler

                PUBWEAK INTRTC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRTC_IRQHandler
                B       INTRTC_IRQHandler

                PUBWEAK INTAD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTAD_IRQHandler
                B       INTAD_IRQHandler

                END
