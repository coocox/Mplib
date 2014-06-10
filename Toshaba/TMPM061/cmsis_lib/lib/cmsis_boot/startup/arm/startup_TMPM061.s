;/**
; *******************************************************************************
; * @file    startup_TMPM061.s
; * @brief   CMSIS Cortex-M0 Core Device Startup File for the
; *          TOSHIBA 'TMPM061' Device Series
; * @version V2.0.2.1 (Tentative)
; * @date    2012/03/13
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
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

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
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



                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  INTPCE_IRQHandler         [WEAK]
                EXPORT  INTDSAD0_IRQHandler       [WEAK]
                EXPORT  INTDSAD1_IRQHandler       [WEAK]
                EXPORT  INTDSAD2_IRQHandler       [WEAK]
                EXPORT  INTLVD_IRQHandler         [WEAK]
                EXPORT  INT0_IRQHandler           [WEAK]
                EXPORT  INT1_IRQHandler           [WEAK]
                EXPORT  INT2_IRQHandler           [WEAK]
                EXPORT  INT3_IRQHandler           [WEAK]
                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTRX2_IRQHandler         [WEAK]
                EXPORT  INTTX2_IRQHandler         [WEAK]
                EXPORT  INTRX3_IRQHandler         [WEAK]
                EXPORT  INTTX3_IRQHandler         [WEAK]
                EXPORT  INTSBI_IRQHandler         [WEAK]
                EXPORT  INTTB0_IRQHandler         [WEAK]
                EXPORT  INTTB1_IRQHandler         [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTT16A0_IRQHandler       [WEAK]
                EXPORT  INTT16A1_IRQHandler       [WEAK]
                EXPORT  INTT16A2_IRQHandler       [WEAK]
                EXPORT  INTT16A3_IRQHandler       [WEAK]
                EXPORT  INTT16A5_IRQHandler       [WEAK]
                EXPORT  INTT16A6_IRQHandler       [WEAK]
                EXPORT  INTRTC_IRQHandler         [WEAK]
                EXPORT  INTAD_IRQHandler          [WEAK]

INTPCE_IRQHandler
INTDSAD0_IRQHandler
INTDSAD1_IRQHandler
INTDSAD2_IRQHandler
INTLVD_IRQHandler
INT0_IRQHandler
INT1_IRQHandler
INT2_IRQHandler
INT3_IRQHandler
INTRX0_IRQHandler
INTTX0_IRQHandler
INTRX1_IRQHandler
INTTX1_IRQHandler
INTRX2_IRQHandler
INTTX2_IRQHandler
INTRX3_IRQHandler
INTTX3_IRQHandler
INTSBI_IRQHandler
INTTB0_IRQHandler
INTTB1_IRQHandler
INTCAP00_IRQHandler
INTCAP01_IRQHandler
INTCAP10_IRQHandler
INTCAP11_IRQHandler
INTT16A0_IRQHandler
INTT16A1_IRQHandler
INTT16A2_IRQHandler
INTT16A3_IRQHandler
INTT16A5_IRQHandler
INTT16A6_IRQHandler
INTRTC_IRQHandler
INTAD_IRQHandler

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

