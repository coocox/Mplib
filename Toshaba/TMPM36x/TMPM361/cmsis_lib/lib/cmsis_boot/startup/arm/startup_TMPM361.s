;/**
; *******************************************************************************
; * @file    startup_TMPM361.s
; * @brief   CMSIS Cortex-M3 Core Device Startup File for the
; *          TOSHIBA 'TMPM361' Device Series 
; * @version V2.2.0
; * @date    2010/05/31
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
; * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
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

                EXPORT  INT0_IRQHandler           [WEAK]
                EXPORT  INT1_IRQHandler           [WEAK]
                EXPORT  INT2_IRQHandler           [WEAK]
                EXPORT  INT3_IRQHandler           [WEAK]
                EXPORT  INT4_IRQHandler           [WEAK]
                EXPORT  INT5_IRQHandler           [WEAK]
                EXPORT  INT6_IRQHandler           [WEAK]
                EXPORT  INT7_IRQHandler           [WEAK]
                EXPORT  INTE_IRQHandler           [WEAK]
                EXPORT  INTF_IRQHandler           [WEAK]
                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTRX2_IRQHandler         [WEAK]
                EXPORT  INTTX2_IRQHandler         [WEAK]
                EXPORT  INTRX3_IRQHandler         [WEAK]
                EXPORT  INTTX3_IRQHandler         [WEAK]
                EXPORT  INTRX4_IRQHandler         [WEAK]
                EXPORT  INTTX4_IRQHandler         [WEAK]
                EXPORT  INTSBI0_IRQHandler        [WEAK]
                EXPORT  INTSBI1_IRQHandler        [WEAK]
                EXPORT  INTCECRX_IRQHandler       [WEAK]
                EXPORT  INTCECTX_IRQHandler       [WEAK]
                EXPORT  INTRMCRX0_IRQHandler      [WEAK]
                EXPORT  INTRTC_IRQHandler         [WEAK]
                EXPORT  INTKWUP_IRQHandler        [WEAK]
                EXPORT  INTSBI2_IRQHandler        [WEAK]
                EXPORT  INTSBI3_IRQHandler        [WEAK]
                EXPORT  INTADHP_IRQHandler        [WEAK]
                EXPORT  INTADM0_IRQHandler        [WEAK]
                EXPORT  INTADM1_IRQHandler        [WEAK]
                EXPORT  INTTB0_IRQHandler         [WEAK]
                EXPORT  INTTB1_IRQHandler         [WEAK]
                EXPORT  INTTB2_IRQHandler         [WEAK]
                EXPORT  INTTB3_IRQHandler         [WEAK]
                EXPORT  INTTB4_IRQHandler         [WEAK]
                EXPORT  INTTB5_IRQHandler         [WEAK]
                EXPORT  INTTB6_IRQHandler         [WEAK]
                EXPORT  INTTB7_IRQHandler         [WEAK]
                EXPORT  INTTB8_IRQHandler         [WEAK]
                EXPORT  INTTB9_IRQHandler         [WEAK]
                EXPORT  INTTBA_IRQHandler         [WEAK]
                EXPORT  INTTBB_IRQHandler         [WEAK]
                EXPORT  INTTBC_IRQHandler         [WEAK]
                EXPORT  INTTBD_IRQHandler         [WEAK]
                EXPORT  INTTBE_IRQHandler         [WEAK]
                EXPORT  INTTBF_IRQHandler         [WEAK]
                EXPORT  INTAD_IRQHandler          [WEAK]
                EXPORT  INTSSP_IRQHandler         [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTCAP90_IRQHandler       [WEAK]
                EXPORT  INTCAP91_IRQHandler       [WEAK]
                EXPORT  INTDMACERR_IRQHandler     [WEAK]
                EXPORT  INTDMACTC0_IRQHandler     [WEAK]

INT0_IRQHandler
INT1_IRQHandler
INT2_IRQHandler
INT3_IRQHandler
INT4_IRQHandler
INT5_IRQHandler
INT6_IRQHandler
INT7_IRQHandler
INTE_IRQHandler
INTF_IRQHandler
INTRX0_IRQHandler
INTTX0_IRQHandler
INTRX1_IRQHandler
INTTX1_IRQHandler
INTRX2_IRQHandler
INTTX2_IRQHandler
INTRX3_IRQHandler
INTTX3_IRQHandler
INTRX4_IRQHandler
INTTX4_IRQHandler
INTSBI0_IRQHandler
INTSBI1_IRQHandler
INTCECRX_IRQHandler
INTCECTX_IRQHandler
INTRMCRX0_IRQHandler
INTRTC_IRQHandler
INTKWUP_IRQHandler
INTSBI2_IRQHandler
INTSBI3_IRQHandler
INTADHP_IRQHandler
INTADM0_IRQHandler
INTADM1_IRQHandler
INTTB0_IRQHandler
INTTB1_IRQHandler
INTTB2_IRQHandler
INTTB3_IRQHandler
INTTB4_IRQHandler
INTTB5_IRQHandler
INTTB6_IRQHandler
INTTB7_IRQHandler
INTTB8_IRQHandler
INTTB9_IRQHandler
INTTBA_IRQHandler
INTTBB_IRQHandler
INTTBC_IRQHandler
INTTBD_IRQHandler
INTTBE_IRQHandler
INTTBF_IRQHandler
INTAD_IRQHandler
INTSSP_IRQHandler
INTCAP10_IRQHandler
INTCAP11_IRQHandler
INTCAP20_IRQHandler
INTCAP21_IRQHandler
INTCAP50_IRQHandler
INTCAP51_IRQHandler
INTCAP60_IRQHandler
INTCAP61_IRQHandler
INTCAP70_IRQHandler
INTCAP71_IRQHandler
INTCAP90_IRQHandler
INTCAP91_IRQHandler
INTDMACERR_IRQHandler
INTDMACTC0_IRQHandler

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
