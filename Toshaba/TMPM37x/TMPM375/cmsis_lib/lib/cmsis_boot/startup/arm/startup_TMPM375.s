;/**
; *******************************************************************************
; * @file    startup_TMPM375.s
; * @brief   CMSIS Cortex-M3 Core Device Startup File for the
; *          TOSHIBA 'TMPM375' Device Series
; * @version V2.0.2.1 (Tentative)
; * @date    2013/01/28
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
; * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
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
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
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

                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTVCNB_IRQHandler        [WEAK]
                EXPORT  INTEMG1_IRQHandler        [WEAK]
                EXPORT  INTOVV1_IRQHandler        [WEAK]
                EXPORT  INTADBPDB_IRQHandler      [WEAK]
                EXPORT  INTTB00_IRQHandler        [WEAK]
                EXPORT  INTTB01_IRQHandler        [WEAK]
                EXPORT  INTTB40_IRQHandler        [WEAK]
                EXPORT  INTTB41_IRQHandler        [WEAK]
                EXPORT  INTTB50_IRQHandler        [WEAK]
                EXPORT  INTTB51_IRQHandler        [WEAK]
                EXPORT  INTPMD1_IRQHandler        [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INT6_IRQHandler           [WEAK]
                EXPORT  INT7_IRQHandler           [WEAK]
                EXPORT  INTADBCPA_IRQHandler      [WEAK]
                EXPORT  INTADBCPB_IRQHandler      [WEAK]
                EXPORT  INTADBSFT_IRQHandler      [WEAK]
                EXPORT  INTADBTMR_IRQHandler      [WEAK]
                EXPORT  INTENC0_IRQHandler        [WEAK]
                EXPORT  INTTB70_IRQHandler        [WEAK]
                EXPORT  INTTB71_IRQHandler        [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTC_IRQHandler           [WEAK]
                EXPORT  INTSBI0_IRQHandler        [WEAK]

INTRX0_IRQHandler
INTTX0_IRQHandler
INTRX1_IRQHandler
INTTX1_IRQHandler
INTVCNB_IRQHandler
INTEMG1_IRQHandler
INTOVV1_IRQHandler
INTADBPDB_IRQHandler
INTTB00_IRQHandler
INTTB01_IRQHandler
INTTB40_IRQHandler
INTTB41_IRQHandler
INTTB50_IRQHandler
INTTB51_IRQHandler
INTPMD1_IRQHandler
INTCAP00_IRQHandler
INTCAP01_IRQHandler
INTCAP50_IRQHandler
INTCAP51_IRQHandler
INT6_IRQHandler
INT7_IRQHandler
INTADBCPA_IRQHandler
INTADBCPB_IRQHandler
INTADBSFT_IRQHandler
INTADBTMR_IRQHandler
INTENC0_IRQHandler
INTTB70_IRQHandler
INTTB71_IRQHandler
INTCAP70_IRQHandler
INTCAP71_IRQHandler
INTC_IRQHandler
INTSBI0_IRQHandler

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

