;/**
; ***************************************************************************
; * @file     startup_TMPM365.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM365' Device Series 
; * @version  V2.0.2.1 (Tentative)
; * @date     2012/7/9
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
                DCD     INTRX0_IRQHandler         ; 8:  Serial reception (channel.0)
                DCD     INTTX0_IRQHandler         ; 9:  Serial transmission (channel.0)
                DCD     INTRX1_IRQHandler         ; 10: Serial reception (channel.1)
                DCD     INTTX1_IRQHandler         ; 11: Serial transmission (channel.1)
                DCD     INTUSBWKUP_IRQHandler     ; 12: USB WakeUp 
                DCD     0                         ; 13: Reserved    
                DCD     INTSBI0_IRQHandler        ; 14: Serial bus interface 0
                DCD     INTSBI1_IRQHandler        ; 15: Serial bus interface 1
                DCD     INTADHP_IRQHandler        ; 16: Highest priority AD conversion complete interrupt
                DCD     INTAD_IRQHandler          ; 17: AD conversion interrupt             
                DCD     INTADM0_IRQHandler        ; 18: AD conversion monitoring function interrupt 0
                DCD     INTADM1_IRQHandler        ; 19: AD conversion monitoring function interrupt 1
                DCD     INTTB0_IRQHandler         ; 20:	16-bit TMRB match detection 0
                DCD     INTTB1_IRQHandler         ; 21:	16-bit TMRB match detection 1
                DCD     INTTB2_IRQHandler         ; 22:	16-bit TMRB match detection 2
                DCD     INTTB3_IRQHandler         ; 23:	16-bit TMRB match detection 3
                DCD     INTTB4_IRQHandler         ; 24:	16-bit TMRB match detection 4
                DCD     INTTB5_IRQHandler         ; 25:	16-bit TMRB match detection 5
                DCD     INTTB6_IRQHandler         ; 26:	16-bit TMRB match detection 6
                DCD     INTTB7_IRQHandler         ; 27:	16-bit TMRB match detection 7
                DCD     INTTB8_IRQHandler         ; 28:	16-bit TMRB match detection 8
                DCD     INTTB9_IRQHandler         ; 29:	16-bit TMRB match detection 9
                DCD     INTUSB_IRQHandler         ; 30: USB Interrupt
                DCD     0                         ; 31: Reserved  
                DCD     0                         ; 32: Reserved  
                DCD     0                         ; 33: Reserved  
                DCD     INTUSBPON_IRQHandler      ; 34: USB Power On connection detectioninterrupt
                DCD     0                         ; 35: Reserved
                DCD     INTCAP00_IRQHandler       ; 36:	16-bit TMRB0 input capture 0
                DCD     INTCAP01_IRQHandler       ; 37:	16-bit TMRB0 input capture 1
                DCD     INTCAP10_IRQHandler       ; 38:	16-bit TMRB1 input capture 0
                DCD     INTCAP11_IRQHandler       ; 39:	16-bit TMRB1 input capture 1
                DCD     INTCAP20_IRQHandler       ; 40:	16-bit TMRB2 input capture 0
                DCD     INTCAP21_IRQHandler       ; 41:	16-bit TMRB2 input capture 1  
                DCD     INTCAP30_IRQHandler       ; 42:	16-bit TMRB3 input capture 0
                DCD     INTCAP31_IRQHandler       ; 43:	16-bit TMRB3 input capture 1
                DCD     INTCAP40_IRQHandler       ; 44:	16-bit TMRB4 input capture 0
                DCD     INTCAP41_IRQHandler       ; 45:	16-bit TMRB4 input capture 1
                DCD     INTCAP50_IRQHandler       ; 46: 16-bit TMRB5 input capture 0
                DCD     INTCAP51_IRQHandler       ; 47: 16-bit TMRB5 input capture 1
                DCD     INTCAP60_IRQHandler       ; 48: 16-bit TMRB6 input capture 0
                DCD     INTCAP61_IRQHandler       ; 49: 16-bit TMRB6 input capture 1  
                DCD     INTCAP70_IRQHandler       ; 50: 16-bit TMRB7 input capture 0
                DCD     INTCAP71_IRQHandler       ; 51: 16-bit TMRB7 input capture 1
                DCD     INTCAP80_IRQHandler       ; 52: 16-bit TMRB8 input capture 0
                DCD     INTCAP81_IRQHandler       ; 53: 16-bit TMRB8 input capture 1
                DCD     INTCAP90_IRQHandler       ; 54: 16-bit TMRB9 input capture 0
                DCD     INTCAP91_IRQHandler       ; 55: 16-bit TMRB9 input capture 1 
                DCD     INT8_IRQHandler           ; 56: Interrupt pin 8
                DCD     INT9_IRQHandler           ; 57: Interrupt pin 9                
                DCD     0                         ; 58: Reserved  
                DCD     0                         ; 59: Reserved                                                               
                DCD     INTDMAC0TC_IRQHandler     ; 60: DMA terminal count status interrupt 0
                DCD     INTABTLOSS0_IRQHandler    ; 61: I2C arbitration lost interrupt 0
                DCD     INTDMAC0ERR_IRQHandler    ; 62: DMA error status interrupt 0
                DCD     INTABTLOSS1_IRQHandler    ; 63: I2C arbitration lost interrupt 1
                
                

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
                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTUSBWKUP_IRQHandler     [WEAK]                
                EXPORT  INTSBI0_IRQHandler        [WEAK]
                EXPORT  INTSBI1_IRQHandler        [WEAK]
                EXPORT  INTADHP_IRQHandler        [WEAK]  
                              
                EXPORT  INTAD_IRQHandler          [WEAK]
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
                EXPORT  INTUSB_IRQHandler         [WEAK]
                EXPORT  INTUSBPON_IRQHandler      [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTCAP30_IRQHandler       [WEAK]
                EXPORT  INTCAP31_IRQHandler       [WEAK]
                EXPORT  INTCAP40_IRQHandler       [WEAK]
                EXPORT  INTCAP41_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTCAP80_IRQHandler       [WEAK]
                EXPORT  INTCAP81_IRQHandler       [WEAK]
                EXPORT  INTCAP90_IRQHandler       [WEAK]
                EXPORT  INTCAP91_IRQHandler       [WEAK]                                                                                                                                                                                               
                EXPORT  INT8_IRQHandler           [WEAK]
                EXPORT  INT9_IRQHandler           [WEAK]
                EXPORT  INTDMAC0TC_IRQHandler     [WEAK]
                EXPORT  INTABTLOSS0_IRQHandler    [WEAK]
                EXPORT  INTDMAC0ERR_IRQHandler    [WEAK]
                EXPORT  INTABTLOSS1_IRQHandler    [WEAK]


INT0_IRQHandler        
INT1_IRQHandler        
INT2_IRQHandler        
INT3_IRQHandler        
INT4_IRQHandler        
INT5_IRQHandler        
INT6_IRQHandler        
INT7_IRQHandler        
INTRX0_IRQHandler      
INTTX0_IRQHandler      
INTRX1_IRQHandler      
INTTX1_IRQHandler      
INTUSBWKUP_IRQHandler  
INTSBI0_IRQHandler     
INTSBI1_IRQHandler     
INTADHP_IRQHandler     
                        
INTAD_IRQHandler       
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
INTUSB_IRQHandler      
INTUSBPON_IRQHandler   
INTCAP00_IRQHandler       
INTCAP01_IRQHandler       
INTCAP10_IRQHandler     
INTCAP11_IRQHandler           
INTCAP20_IRQHandler       
INTCAP21_IRQHandler       
INTCAP30_IRQHandler    
INTCAP31_IRQHandler      
INTCAP40_IRQHandler       
INTCAP41_IRQHandler         
INTCAP50_IRQHandler    
INTCAP51_IRQHandler       
INTCAP60_IRQHandler       
INTCAP61_IRQHandler      
INTCAP70_IRQHandler       
INTCAP71_IRQHandler        
INTCAP80_IRQHandler       
INTCAP81_IRQHandler       
INTCAP90_IRQHandler       
INTCAP91_IRQHandler        
INT8_IRQHandler        
INT9_IRQHandler        
INTDMAC0TC_IRQHandler  
INTABTLOSS0_IRQHandler 
INTDMAC0ERR_IRQHandler 
INTABTLOSS1_IRQHandler 


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
