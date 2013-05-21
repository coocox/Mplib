;/**
; ***************************************************************************
; * @file     startup_TMPM364.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM364' Device Series 
; * @version  V2.2.0
; * @date     2010/11/24
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
; *****************************************************************************
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
                DCD     INT8_IRQHandler           ; 8:  Interrupt pin 8
                DCD     INT9_IRQHandler           ; 9:  Interrupt pin 9
                DCD     INTA_IRQHandler           ; 10: Interrupt pin A
                DCD     INTB_IRQHandler           ; 11: Interrupt pin B
                DCD     INTC_IRQHandler           ; 12: Interrupt pin C
                DCD     INTD_IRQHandler           ; 13: Interrupt pin D
                DCD     0                         ; 14: Reserved
                DCD     0                         ; 15: Reserved
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
                DCD     INTRMCRX1_IRQHandler      ; 31: Remote control signal reception (channel.1)
                DCD     INTRTC_IRQHandler         ; 32: Real time clock timer
                DCD     INTKWUP_IRQHandler        ; 33: Key on wake up
                DCD     INTSBI2_IRQHandler        ; 34: Serial bus interface (channel.2)
                DCD     INTSBI3_IRQHandler        ; 35: Serial bus interface (channel.3)
                DCD     INTSBI4_IRQHandler        ; 36: Serial bus interface (channel.4)
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
                DCD     INTUSB_IRQHandler         ; 56: USB
                DCD     INTCANGB_IRQHandler       ; 57: CAN status
                DCD     INTAD_IRQHandler          ; 58: A/D conversion completion
                DCD     INTSSP_IRQHandler         ; 59: Synchronous Serial Port
                DCD     INTRX5_IRQHandler         ; 60: Serial reception (channel.5)
                DCD     INTTX5_IRQHandler         ; 61: Serial transmission (channel.5)
                DCD     INTRX6_IRQHandler         ; 62: Serial reception (channel.6)
                DCD     INTTX6_IRQHandler         ; 63: Serial transmission (channel.6)
                DCD     INTRX7_IRQHandler         ; 64: Serial reception (channel.7)
                DCD     INTTX7_IRQHandler         ; 65: Serial transmission (channel.7)
                DCD     INTRX8_IRQHandler         ; 66: Serial reception (channel.8)
                DCD     INTTX8_IRQHandler         ; 67: Serial transmission (channel.8)
                DCD     INTRX9_IRQHandler         ; 68: Serial reception (channel.9)
                DCD     INTTX9_IRQHandler         ; 69: Serial transmission (channel.9)
                DCD     INTRX10_IRQHandler        ; 70: Serial reception (channel.10)
                DCD     INTTX10_IRQHandler        ; 71: Serial transmission (channel.10)
                DCD     INTRX11_IRQHandler        ; 72: Serial reception (channel.11)
                DCD     INTTX11_IRQHandler        ; 73: Serial transmission (channel.11)
                DCD     INTCAP10_IRQHandler       ; 74: 16bit TMRB input capture 10
                DCD     INTCAP11_IRQHandler       ; 75: 16bit TMRB input capture 11
                DCD     INTCAP20_IRQHandler       ; 76: 16bit TMRB input capture 20
                DCD     INTCAP21_IRQHandler       ; 77: 16bit TMRB input capture 21
                DCD     INTCANRX_IRQHandler       ; 78: CAN Reception
                DCD     INTCANTX_IRQHandler       ; 79: CAN Transmission
                DCD     INTCAP50_IRQHandler       ; 80: 16bit TMRB input capture 50
                DCD     INTCAP51_IRQHandler       ; 81: 16bit TMRB input capture 51
                DCD     INTCAP60_IRQHandler       ; 82: 16bit TMRB input capture 60
                DCD     INTCAP61_IRQHandler       ; 83: 16bit TMRB input capture 61
                DCD     INTCAP70_IRQHandler       ; 84: 16bit TMRB input capture 70
                DCD     INTCAP71_IRQHandler       ; 85: 16bit TMRB input capture 71
                DCD     INTCAP90_IRQHandler       ; 86: 16bit TMRB input capture 90
                DCD     INTCAP91_IRQHandler       ; 87: 16bit TMRB input capture 91
                DCD     INTCAPA0_IRQHandler       ; 88: 16bit TMRB input capture A0
                DCD     INTCAPA1_IRQHandler       ; 89: 16bit TMRB input capture A1
                DCD     INTCAPB0_IRQHandler       ; 90: 16bit TMRB input capture B0
                DCD     INTCAPB1_IRQHandler       ; 91: 16bit TMRB input capture B1
                DCD     INTCAPD0_IRQHandler       ; 92: 16bit TMRB input capture D0
                DCD     INTCAPD1_IRQHandler       ; 93: 16bit TMRB input capture D1
                DCD     INTCAPE0_IRQHandler       ; 94: 16bit TMRB input capture E0
                DCD     INTCAPE1_IRQHandler       ; 95: 16bit TMRB input capture E1
                DCD     INTCAPF0_IRQHandler       ; 96: 16bit TMRB input capture F0
                DCD     INTCAPF1_IRQHandler       ; 97: 16bit TMRB input capture F1
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
                EXPORT  INT8_IRQHandler           [WEAK]
                EXPORT  INT9_IRQHandler           [WEAK]
                EXPORT  INTA_IRQHandler           [WEAK]
                EXPORT  INTB_IRQHandler           [WEAK]
                EXPORT  INTC_IRQHandler           [WEAK]
                EXPORT  INTD_IRQHandler           [WEAK]
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
                EXPORT  INTRMCRX1_IRQHandler      [WEAK]
                EXPORT  INTRTC_IRQHandler         [WEAK]
                EXPORT  INTKWUP_IRQHandler        [WEAK]
                EXPORT  INTSBI2_IRQHandler        [WEAK]
                EXPORT  INTSBI3_IRQHandler        [WEAK]
                EXPORT  INTSBI4_IRQHandler        [WEAK]
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
                EXPORT  INTUSB_IRQHandler         [WEAK]
                EXPORT  INTCANGB_IRQHandler       [WEAK]
                EXPORT  INTAD_IRQHandler          [WEAK]
                EXPORT  INTSSP_IRQHandler         [WEAK]
                EXPORT  INTRX5_IRQHandler         [WEAK]
                EXPORT  INTTX5_IRQHandler         [WEAK]
                EXPORT  INTRX6_IRQHandler         [WEAK]
                EXPORT  INTTX6_IRQHandler         [WEAK]
                EXPORT  INTRX7_IRQHandler         [WEAK]
                EXPORT  INTTX7_IRQHandler         [WEAK]
                EXPORT  INTRX8_IRQHandler         [WEAK]
                EXPORT  INTTX8_IRQHandler         [WEAK]
                EXPORT  INTRX9_IRQHandler         [WEAK]
                EXPORT  INTTX9_IRQHandler         [WEAK]
                EXPORT  INTRX10_IRQHandler        [WEAK]
                EXPORT  INTTX10_IRQHandler        [WEAK]
                EXPORT  INTRX11_IRQHandler        [WEAK]
                EXPORT  INTTX11_IRQHandler        [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTCANRX_IRQHandler       [WEAK]
                EXPORT  INTCANTX_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTCAP90_IRQHandler       [WEAK]
                EXPORT  INTCAP91_IRQHandler       [WEAK]
                EXPORT  INTCAPA0_IRQHandler       [WEAK]
                EXPORT  INTCAPA1_IRQHandler       [WEAK]
                EXPORT  INTCAPB0_IRQHandler       [WEAK]
                EXPORT  INTCAPB1_IRQHandler       [WEAK]
                EXPORT  INTCAPD0_IRQHandler       [WEAK]
                EXPORT  INTCAPD1_IRQHandler       [WEAK]
                EXPORT  INTCAPE0_IRQHandler       [WEAK]
                EXPORT  INTCAPE1_IRQHandler       [WEAK]
                EXPORT  INTCAPF0_IRQHandler       [WEAK]
                EXPORT  INTCAPF1_IRQHandler       [WEAK]
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
INT8_IRQHandler
INT9_IRQHandler
INTA_IRQHandler
INTB_IRQHandler
INTC_IRQHandler
INTD_IRQHandler
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
INTRMCRX1_IRQHandler
INTRTC_IRQHandler
INTKWUP_IRQHandler
INTSBI2_IRQHandler
INTSBI3_IRQHandler
INTSBI4_IRQHandler
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
INTUSB_IRQHandler
INTCANGB_IRQHandler
INTAD_IRQHandler
INTSSP_IRQHandler
INTRX5_IRQHandler
INTTX5_IRQHandler
INTRX6_IRQHandler
INTTX6_IRQHandler
INTRX7_IRQHandler
INTTX7_IRQHandler
INTRX8_IRQHandler
INTTX8_IRQHandler
INTRX9_IRQHandler
INTTX9_IRQHandler
INTRX10_IRQHandler
INTTX10_IRQHandler
INTRX11_IRQHandler
INTTX11_IRQHandler
INTCAP10_IRQHandler
INTCAP11_IRQHandler
INTCAP20_IRQHandler
INTCAP21_IRQHandler
INTCANRX_IRQHandler
INTCANTX_IRQHandler
INTCAP50_IRQHandler
INTCAP51_IRQHandler
INTCAP60_IRQHandler
INTCAP61_IRQHandler
INTCAP70_IRQHandler
INTCAP71_IRQHandler
INTCAP90_IRQHandler
INTCAP91_IRQHandler
INTCAPA0_IRQHandler
INTCAPA1_IRQHandler
INTCAPB0_IRQHandler
INTCAPB1_IRQHandler
INTCAPD0_IRQHandler
INTCAPD1_IRQHandler
INTCAPE0_IRQHandler
INTCAPE1_IRQHandler
INTCAPF0_IRQHandler
INTCAPF1_IRQHandler
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
