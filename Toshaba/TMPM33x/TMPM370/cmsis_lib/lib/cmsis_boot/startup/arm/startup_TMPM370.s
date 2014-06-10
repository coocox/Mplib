;/**
; ***************************************************************************
; * @file     startup_TMPM370.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM370' Device Series 
; * @version  V2.2.0
; * @date     2010/12/08
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
; * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
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
                DCD     INT0_IRQHandler           ; 0:  Interrupt Pin (PH0/AINA0/96pin or 98pin)
                DCD     INT1_IRQHandler           ; 1:  Interrupt Pin (PH1/AINA1/95pin or 97pin)
                DCD     INT2_IRQHandler           ; 2:  Interrupt Pin (PH2/AINA2/94pin or 96pin)
                DCD     INT3_IRQHandler           ; 3:  Interrupt Pin (PA0/TB0IN/2pin or 4pin)
                DCD     INT4_IRQHandler           ; 4:  Interrupt Pin (PA2/TB1IN/4pin or 6pin)
                DCD     INT5_IRQHandler           ; 5:  Interrupt Pin (PE4/TB2IN//15pin or 17pin)
                DCD     INTRX0_IRQHandler         ; 6:  Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 7:  Serial transmit (channel.0)
                DCD     INTRX1_IRQHandler         ; 8:  Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 9:  Serial transmit (channel.1)
                DCD     INTVCNA_IRQHandler        ; 10: Vector Engine interrupt A
                DCD     INTVCNB_IRQHandler        ; 11: Vector Engine interrupt B
                DCD     INTEMG0_IRQHandler        ; 12: PMD0 EMG interrupt
                DCD     INTEMG1_IRQHandler        ; 13: PMD1 EMG interrupt
                DCD     INTOVV0_IRQHandler        ; 14: PMD0 OVV interrupt
                DCD     INTOVV1_IRQHandler        ; 15: PMD1 OVV interrupt
                DCD     INTADAPDA_IRQHandler      ; 16: ADCA conversion triggered by PMD0 is finished
                DCD     INTADBPDA_IRQHandler      ; 17: ADCB conversion triggered by PMD0 is finished
                DCD     INTADAPDB_IRQHandler      ; 18: ADCA conversion triggered by PMD1 is finished
                DCD     INTADBPDB_IRQHandler      ; 19: ADCB conversion triggered by PMD1 is finished
                DCD     INTTB00_IRQHandler        ; 20: 16bit TMRB0 compare match detection 0/ Over flow
                DCD     INTTB01_IRQHandler        ; 21: 16bit TMRB0 compare match detection 1
                DCD     INTTB10_IRQHandler        ; 22: 16bit TMRB1 compare match detection 0/ Over flow
                DCD     INTTB11_IRQHandler        ; 23: 16bit TMRB1 compare match detection 1
                DCD     INTTB40_IRQHandler        ; 24: 16bit TMRB4 compare match detection 0/ Over flow
                DCD     INTTB41_IRQHandler        ; 25: 16bit TMRB4 compare match detection 1
                DCD     INTTB50_IRQHandler        ; 26: 16bit TMRB5 compare match detection 0/ Over flow
                DCD     INTTB51_IRQHandler        ; 27: 16bit TMRB5 compare match detection 1
                DCD     INTPMD0_IRQHandler        ; 28: PMD0 PWM interrupt
                DCD     INTPMD1_IRQHandler        ; 29: PMD1 PWM interrupt
                DCD     INTCAP00_IRQHandler       ; 30: 16bit TMRB0 input capture 0
                DCD     INTCAP01_IRQHandler       ; 31: 16bit TMRB0 input capture 1
                DCD     INTCAP10_IRQHandler       ; 32: 16bit TMRB1 input capture 0
                DCD     INTCAP11_IRQHandler       ; 33: 16bit TMRB1 input capture 1
                DCD     INTCAP40_IRQHandler       ; 34: 16bit TMRB4 input capture 0
                DCD     INTCAP41_IRQHandler       ; 35: 16bit TMRB4 input capture 1
                DCD     INTCAP50_IRQHandler       ; 36: 16bit TMRB5 input capture 0
                DCD     INTCAP51_IRQHandler       ; 37: 16bit TMRB5 input capture 1
                DCD     INT6_IRQHandler           ; 38: Interrupt Pin (PE6/TB3IN//17pin or 19pin)
                DCD     INT7_IRQHandler           ; 39: Interrupt Pin (PE7/TB3OUT/18pin or 20pin)
                DCD     INTRX2_IRQHandler         ; 40: Serial reception (channel.2)
                DCD     INTTX2_IRQHandler         ; 41: Serial transmit (channel.2)
                DCD     INTADACPA_IRQHandler      ; 42: ADCA conversion monitoring function interrupt A
                DCD     INTADBCPA_IRQHandler      ; 43: ADCB conversion monitoring function interrupt A
                DCD     INTADACPB_IRQHandler      ; 44: ADCA conversion monitoring function interrupt B
                DCD     INTADBCPB_IRQHandler      ; 45: ADCB conversion monitoring function interrupt B
                DCD     INTTB20_IRQHandler        ; 46: 16bit TMRB2 compare match detection 0/ Over flow
                DCD     INTTB21_IRQHandler        ; 47: 16bit TMRB2 compare match detection 1
                DCD     INTTB30_IRQHandler        ; 48: 16bit TMRB3 compare match detection 0/ Over flow
                DCD     INTTB31_IRQHandler        ; 49: 16bit TMRB3 compare match detection 1
                DCD     INTCAP20_IRQHandler       ; 50: 16bit TMRB2 input capture 0
                DCD     INTCAP21_IRQHandler       ; 51: 16bit TMRB2 input capture 1
                DCD     INTCAP30_IRQHandler       ; 52: 16bit TMRB3 input capture 0
                DCD     INTCAP31_IRQHandler       ; 53: 16bit TMRB3 input capture 1
                DCD     INTADASFT_IRQHandler      ; 54: ADCA conversion started by software is finished
                DCD     INTADBSFT_IRQHandler      ; 55: ADCB conversion started by software is finished
                DCD     INTADATMR_IRQHandler      ; 56: ADCA conversion triggered by timer is finished
                DCD     INTADBTMR_IRQHandler      ; 57: ADCB conversion triggered by timer is finished
                DCD     INT8_IRQHandler           ; 58: Interrupt Pin (PA7/TB4IN/9pin or 11pin)
                DCD     INT9_IRQHandler           ; 59: Interrupt Pin (PD3/33pin or 35pin)
                DCD     INTA_IRQHandler           ; 60: Interrupt Pin (PL1/21pin or 23pin)
                DCD     INTB_IRQHandler           ; 61: Interrupt Pin (PL0/20pin or 22pin)
                DCD     INTENC0_IRQHandler        ; 62: Ender input0 interrupt
                DCD     INTENC1_IRQHandler        ; 63: Ender input1 interrupt
                DCD     INTRX3_IRQHandler         ; 64: Serial reception (channel.3)
                DCD     INTTX3_IRQHandler         ; 65: Serial transmit (channel.3)
                DCD     INTTB60_IRQHandler        ; 66: 16bit TMRB6 compare match detection 0 / Over flow
                DCD     INTTB61_IRQHandler        ; 67: 16bit TMRB6 compare match detection 1
                DCD     INTTB70_IRQHandler        ; 68: 16bit TMRB7 compare match detection 0 / Over flow
                DCD     INTTB71_IRQHandler        ; 69: 16bit TMRB7 compare match detection 1
                DCD     INTCAP60_IRQHandler       ; 70: 16bit TMRB6 input capture 0
                DCD     INTCAP61_IRQHandler       ; 71: 16bit TMRB6 input capture 1
                DCD     INTCAP70_IRQHandler       ; 72: 16bit TMRB7 input capture 0
                DCD     INTCAP71_IRQHandler       ; 73: 16bit TMRB7 input capture 1
                DCD     INTC_IRQHandler           ; 74: Interrupt Pin (PJ6/AINB9/74pin or 76 pin)
                DCD     INTD_IRQHandler           ; 75: Interrupt Pin (PJ7/AINB10/73pin or 75pin)
                DCD     INTE_IRQHandler           ; 76: Interrupt Pin (PK0/AINB11/72pin or 74pin)
                DCD     INTF_IRQHandler           ; 77: Interrupt Pin (PK1/AINB12/71pin or 73pin)


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
                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTVCNA_IRQHandler        [WEAK]
                EXPORT  INTVCNB_IRQHandler        [WEAK]
                EXPORT  INTEMG0_IRQHandler        [WEAK]
                EXPORT  INTEMG1_IRQHandler        [WEAK]
                EXPORT  INTOVV0_IRQHandler        [WEAK]
                EXPORT  INTOVV1_IRQHandler        [WEAK]
                EXPORT  INTADAPDA_IRQHandler      [WEAK]
                EXPORT  INTADBPDA_IRQHandler      [WEAK]
                EXPORT  INTADAPDB_IRQHandler      [WEAK]
                EXPORT  INTADBPDB_IRQHandler      [WEAK]
                EXPORT  INTTB00_IRQHandler        [WEAK]
                EXPORT  INTTB01_IRQHandler        [WEAK]
                EXPORT  INTTB10_IRQHandler        [WEAK]
                EXPORT  INTTB11_IRQHandler        [WEAK]
                EXPORT  INTTB40_IRQHandler        [WEAK]
                EXPORT  INTTB41_IRQHandler        [WEAK]
                EXPORT  INTTB50_IRQHandler        [WEAK]
                EXPORT  INTTB51_IRQHandler        [WEAK]
                EXPORT  INTPMD0_IRQHandler        [WEAK]
                EXPORT  INTPMD1_IRQHandler        [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTCAP40_IRQHandler       [WEAK]
                EXPORT  INTCAP41_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INT6_IRQHandler           [WEAK]
                EXPORT  INT7_IRQHandler           [WEAK]
                EXPORT  INTRX2_IRQHandler         [WEAK]
                EXPORT  INTTX2_IRQHandler         [WEAK]
                EXPORT  INTADACPA_IRQHandler      [WEAK]
                EXPORT  INTADBCPA_IRQHandler      [WEAK]
                EXPORT  INTADACPB_IRQHandler      [WEAK]
                EXPORT  INTADBCPB_IRQHandler      [WEAK]
                EXPORT  INTTB20_IRQHandler        [WEAK]
                EXPORT  INTTB21_IRQHandler        [WEAK]
                EXPORT  INTTB30_IRQHandler        [WEAK]
                EXPORT  INTTB31_IRQHandler        [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTCAP30_IRQHandler       [WEAK]
                EXPORT  INTCAP31_IRQHandler       [WEAK]
                EXPORT  INTADASFT_IRQHandler      [WEAK]
                EXPORT  INTADBSFT_IRQHandler      [WEAK]
                EXPORT  INTADATMR_IRQHandler      [WEAK]
                EXPORT  INTADBTMR_IRQHandler      [WEAK]
                EXPORT  INT8_IRQHandler           [WEAK]
                EXPORT  INT9_IRQHandler           [WEAK]
                EXPORT  INTA_IRQHandler           [WEAK]
                EXPORT  INTB_IRQHandler           [WEAK]
                EXPORT  INTENC0_IRQHandler        [WEAK]
                EXPORT  INTENC1_IRQHandler        [WEAK]
                EXPORT  INTRX3_IRQHandler         [WEAK]
                EXPORT  INTTX3_IRQHandler         [WEAK]
                EXPORT  INTTB60_IRQHandler        [WEAK]
                EXPORT  INTTB61_IRQHandler        [WEAK]
                EXPORT  INTTB70_IRQHandler        [WEAK]
                EXPORT  INTTB71_IRQHandler        [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTC_IRQHandler           [WEAK]
                EXPORT  INTD_IRQHandler           [WEAK]
                EXPORT  INTE_IRQHandler           [WEAK]
                EXPORT  INTF_IRQHandler           [WEAK]

INT0_IRQHandler
INT1_IRQHandler
INT2_IRQHandler
INT3_IRQHandler
INT4_IRQHandler
INT5_IRQHandler
INTRX0_IRQHandler
INTTX0_IRQHandler
INTRX1_IRQHandler
INTTX1_IRQHandler
INTVCNA_IRQHandler
INTVCNB_IRQHandler
INTEMG0_IRQHandler
INTEMG1_IRQHandler
INTOVV0_IRQHandler
INTOVV1_IRQHandler
INTADAPDA_IRQHandler
INTADBPDA_IRQHandler
INTADAPDB_IRQHandler
INTADBPDB_IRQHandler
INTTB00_IRQHandler
INTTB01_IRQHandler
INTTB10_IRQHandler
INTTB11_IRQHandler
INTTB40_IRQHandler
INTTB41_IRQHandler
INTTB50_IRQHandler
INTTB51_IRQHandler
INTPMD0_IRQHandler
INTPMD1_IRQHandler
INTCAP00_IRQHandler
INTCAP01_IRQHandler
INTCAP10_IRQHandler
INTCAP11_IRQHandler
INTCAP40_IRQHandler
INTCAP41_IRQHandler
INTCAP50_IRQHandler
INTCAP51_IRQHandler
INT6_IRQHandler
INT7_IRQHandler
INTRX2_IRQHandler
INTTX2_IRQHandler
INTADACPA_IRQHandler
INTADBCPA_IRQHandler
INTADACPB_IRQHandler
INTADBCPB_IRQHandler
INTTB20_IRQHandler
INTTB21_IRQHandler
INTTB30_IRQHandler
INTTB31_IRQHandler
INTCAP20_IRQHandler
INTCAP21_IRQHandler
INTCAP30_IRQHandler
INTCAP31_IRQHandler
INTADASFT_IRQHandler
INTADBSFT_IRQHandler
INTADATMR_IRQHandler
INTADBTMR_IRQHandler
INT8_IRQHandler
INT9_IRQHandler
INTA_IRQHandler
INTB_IRQHandler
INTENC0_IRQHandler
INTENC1_IRQHandler
INTRX3_IRQHandler
INTTX3_IRQHandler
INTTB60_IRQHandler
INTTB61_IRQHandler
INTTB70_IRQHandler
INTTB71_IRQHandler
INTCAP60_IRQHandler
INTCAP61_IRQHandler
INTCAP70_IRQHandler
INTCAP71_IRQHandler
INTC_IRQHandler
INTD_IRQHandler
INTE_IRQHandler
INTF_IRQHandler

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
