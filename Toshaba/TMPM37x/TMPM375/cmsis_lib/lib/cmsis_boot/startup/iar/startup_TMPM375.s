;/**
; *******************************************************************************
; * @file    startup_TMPM375.s
; * @brief   CMSIS Cortex-M3 Core Device Startup File for the
; *          TOSHIBA 'TMPM375' Device Series
; * @version V2.0.2.1 (Tentative)
; * @date    2013/01/28
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
; * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
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
                DCD     INTRX0_IRQHandler         ; 0:	Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 1:	Serial transmit (channel.0)
                DCD     INTRX1_IRQHandler         ; 2:	Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 3:	Serial transmit (channel.1)
                DCD     INTVCNB_IRQHandler        ; 4:	Vector Engine interrupt B
                DCD     INTEMG1_IRQHandler        ; 5:	PMD1 EMG interrupt
                DCD     INTOVV1_IRQHandler        ; 6:	PMD1 OVV interrupt
                DCD     INTADBPDB_IRQHandler      ; 7:	ADCB conversion triggered by PMD1 is finished
                DCD     INTTB00_IRQHandler        ; 8:	16bit TMRB0 compare match detection 0/ Over flow
                DCD     INTTB01_IRQHandler        ; 9:	16bit TMRB0 compare match detection 1
                DCD     INTTB40_IRQHandler        ; 10:	16bit TMRB4 compare match detection 0/ Over flow
                DCD     INTTB41_IRQHandler        ; 11:	16bit TMRB4 compare match detection 1
                DCD     INTTB50_IRQHandler        ; 12:	16bit TMRB5 compare match detection 0/ Over flow
                DCD     INTTB51_IRQHandler        ; 13:	16bit TMRB5 compare match detection 1
                DCD     INTPMD1_IRQHandler        ; 14:	PMD1 PWM interrupt
                DCD     INTCAP00_IRQHandler       ; 15:	16bit TMRB0 input capture 0
                DCD     INTCAP01_IRQHandler       ; 16:	16bit TMRB0 input capture 1
                DCD     INTCAP50_IRQHandler       ; 17:	16bit TMRB5 input capture 0
                DCD     INTCAP51_IRQHandler       ; 18:	16bit TMRB5 input capture 1
                DCD     INT6_IRQHandler           ; 19:	Interrupt Pin (PE6/TB3IN//17pin or 19pin)
                DCD     INT7_IRQHandler           ; 20:	Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
                DCD     INTADBCPA_IRQHandler      ; 21:	ADCB conversion monitoring function interrupt A
                DCD     INTADBCPB_IRQHandler      ; 22:	ADCB conversion monitoring function interrupt B
                DCD     INTADBSFT_IRQHandler      ; 23:	ADC1 conversion started by software is finished
                DCD     INTADBTMR_IRQHandler      ; 24:	ADC1 conversion triggered by timer is finished
                DCD     INTENC0_IRQHandler        ; 25:	Ender input0 interrupt
                DCD     INTTB70_IRQHandler        ; 26:	16bit TMRB7 compare match detection 0 / Over flow
                DCD     INTTB71_IRQHandler        ; 27:	16bit TMRB7 compare match detection 1
                DCD     INTCAP70_IRQHandler       ; 28:	16bit TMRB7 input capture 0
                DCD     INTCAP71_IRQHandler       ; 29:	16bit TMRB7 input capture 1
                DCD     INTC_IRQHandler           ; 30:	Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
                DCD     INTSBI0_IRQHandler        ; 31:	Serial Bus Interface0
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

                PUBWEAK INTVCNB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTVCNB_IRQHandler
                B       INTVCNB_IRQHandler

                PUBWEAK INTEMG1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTEMG1_IRQHandler
                B       INTEMG1_IRQHandler

                PUBWEAK INTOVV1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTOVV1_IRQHandler
                B       INTOVV1_IRQHandler

                PUBWEAK INTADBPDB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBPDB_IRQHandler
                B       INTADBPDB_IRQHandler

                PUBWEAK INTTB00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB00_IRQHandler
                B       INTTB00_IRQHandler

                PUBWEAK INTTB01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB01_IRQHandler
                B       INTTB01_IRQHandler

                PUBWEAK INTTB40_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB40_IRQHandler
                B       INTTB40_IRQHandler

                PUBWEAK INTTB41_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB41_IRQHandler
                B       INTTB41_IRQHandler

                PUBWEAK INTTB50_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB50_IRQHandler
                B       INTTB50_IRQHandler

                PUBWEAK INTTB51_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB51_IRQHandler
                B       INTTB51_IRQHandler

                PUBWEAK INTPMD1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPMD1_IRQHandler
                B       INTPMD1_IRQHandler

                PUBWEAK INTCAP00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP00_IRQHandler
                B       INTCAP00_IRQHandler

                PUBWEAK INTCAP01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP01_IRQHandler
                B       INTCAP01_IRQHandler

                PUBWEAK INTCAP50_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP50_IRQHandler
                B       INTCAP50_IRQHandler

                PUBWEAK INTCAP51_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP51_IRQHandler
                B       INTCAP51_IRQHandler

                PUBWEAK INT6_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT6_IRQHandler
                B       INT6_IRQHandler

                PUBWEAK INT7_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT7_IRQHandler
                B       INT7_IRQHandler

                PUBWEAK INTADBCPA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBCPA_IRQHandler
                B       INTADBCPA_IRQHandler

                PUBWEAK INTADBCPB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBCPB_IRQHandler
                B       INTADBCPB_IRQHandler

                PUBWEAK INTADBSFT_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBSFT_IRQHandler
                B       INTADBSFT_IRQHandler

                PUBWEAK INTADBTMR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBTMR_IRQHandler
                B       INTADBTMR_IRQHandler

                PUBWEAK INTENC0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTENC0_IRQHandler
                B       INTENC0_IRQHandler

                PUBWEAK INTTB70_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB70_IRQHandler
                B       INTTB70_IRQHandler

                PUBWEAK INTTB71_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB71_IRQHandler
                B       INTTB71_IRQHandler

                PUBWEAK INTCAP70_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP70_IRQHandler
                B       INTCAP70_IRQHandler

                PUBWEAK INTCAP71_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP71_IRQHandler
                B       INTCAP71_IRQHandler

                PUBWEAK INTC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTC_IRQHandler
                B       INTC_IRQHandler

                PUBWEAK INTSBI0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI0_IRQHandler
                B       INTSBI0_IRQHandler

                END
