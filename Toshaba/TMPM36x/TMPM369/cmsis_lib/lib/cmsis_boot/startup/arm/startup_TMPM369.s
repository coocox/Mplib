;/**
; ****************************************************************************
; * @file     startup_TMPM369.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM369' Device Series 
; * @version  V2.0.2.2 (Tentative)
; * @date     2010/09/29
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
                DCD     INT0_IRQHandler           ; 0:   Interrupt pin 0                                             
                DCD     INT1_IRQHandler           ; 1:   Interrupt pin 1                                             
                DCD     INT2_IRQHandler           ; 2:   Interrupt pin 2                                             
                DCD     INT3_IRQHandler           ; 3:   Interrupt pin 3                                             
                DCD     INT4_IRQHandler           ; 4:   Interrupt pin 4                                             
                DCD     INT5_IRQHandler           ; 5:   Interrupt pin 5                                             
                DCD     INT6_IRQHandler           ; 6:   Interrupt pin 6                                             
                DCD     INT7_IRQHandler           ; 7:   Interrupt pin 7                                             
                DCD     INT8_IRQHandler           ; 8:   Interrupt pin 8                                             
                DCD     INT9_IRQHandler           ; 9:   Interrupt pin 9                                             
                DCD     INTA_IRQHandler           ; 10:  Interrupt pin A                                             
                DCD     INTB_IRQHandler           ; 11:  Interrupt pin B                                             
                DCD     INTC_IRQHandler           ; 12:  Interrupt pin C                                             
                DCD     INTD_IRQHandler           ; 13:  Interrupt pin D                                             
                DCD     INTE_IRQHandler           ; 14:  Interrupt pin E                                             
                DCD     INTF_IRQHandler           ; 15:  Interrupt pin F                                             
                DCD     INTRX0_IRQHandler         ; 16:  Serial reception (channel.0)                                
                DCD     INTTX0_IRQHandler         ; 17:  Serial transmission (channel.0)                             
                DCD     INTRX1_IRQHandler         ; 18:  Serial reception (channel.1)                                
                DCD     INTTX1_IRQHandler         ; 19:  Serial transmission (channel.1)                             
                DCD     INTRX2_IRQHandler         ; 20:  Serial reception (channel.2)                                
                DCD     INTTX2_IRQHandler         ; 21:  Serial transmission (channel.2)                             
                DCD     INTRX3_IRQHandler         ; 22:  Serial reception (channel.3)                                
                DCD     INTTX3_IRQHandler         ; 23:  Serial transmission (channel.3)                             
                DCD     INTUART4_IRQHandler       ; 24:  FULL UART(channel.4)                                        
                DCD     INTUART5_IRQHandler       ; 25:  FULL UART(channel.5)                                        
                DCD     INTSBI0_IRQHandler        ; 26:  Serial bus interface 0                                      
                DCD     INTSBI1_IRQHandler        ; 27:  Serial bus interface 1                                      
                DCD     INTSBI2_IRQHandler        ; 28:  Serial bus interface 2                                      
                DCD     INTSSP0_IRQHandler        ; 29:  SPI serial interface 0                                      
                DCD     INTSSP1_IRQHandler        ; 30:  SPI serial interface 1                                      
                DCD     INTSSP2_IRQHandler        ; 31:  SPI serial interface 2                                      
                DCD     INTUSBH_IRQHandler        ; 32:  USB Host Interrupt                                          
                DCD     INTUSBD_IRQHandler        ; 33:  USB Device Interrupt                                        
                DCD     INTUSBWKUP_IRQHandler     ; 34:  USB WakeUp                                                  
                DCD     INTCANRX_IRQHandler       ; 35:  CAN RX                                                      
                DCD     INTCANTX_IRQHandler       ; 36:  CAN TX                                                      
                DCD     INTCANGB_IRQHandler       ; 37:  CAN STAUTS                                                  
                DCD     INTETH_IRQHandler         ; 38:  EtherNET Interrupt                                          
                DCD     INTETHWK_IRQHandler       ; 39:  EtherNET(magic packet detection) interrupt                  
                DCD     INTADAHP_IRQHandler       ; 40:  Highest priority AD conversion complete interrupt (channel.A)
                DCD     INTADAM0_IRQHandler       ; 41:  AD conversion monitoring function interrupt 0(channel.A)    
                DCD     INTADAM1_IRQHandler       ; 42:  AD conversion monitoring function interrupt 1(channel.A)    
                DCD     INTADA_IRQHandler         ; 43:  AD conversion interrupt(channel.A)                          
                DCD     INTADBHP_IRQHandler       ; 44:  Highest priority AD conversion complete interrupt (channel.B)
                DCD     INTADBM0_IRQHandler       ; 45:  AD conversion monitoring function interrupt 0(channel.B)    
                DCD     INTADBM1_IRQHandler       ; 46:  AD conversion monitoring function interrupt 1(channel.B)    
                DCD     INTADB_IRQHandler         ; 47:  AD conversion interrupt(channel.B)                          
                DCD     INTEMG0_IRQHandler        ; 48:  PMD0 EMG interrupt (MPT0)                                   
                DCD     INTPMD0_IRQHandler        ; 49:  PMD0 PWM interrupt (MPT0)                                   
                DCD     INTENC0_IRQHandler        ; 50:  PMD0 Encoder input interrupt (MPT0)                         
                DCD     INTEMG1_IRQHandler        ; 51:  PMD1 EMG interrupt (MPT1)                                   
                DCD     INTPMD1_IRQHandler        ; 52:  PMD1 PWM interrupt (MPT1)                                   
                DCD     INTENC1_IRQHandler        ; 53:  PMD1 Encoder input interrupt (MPT1)                         
                DCD     INTMTEMG0_IRQHandler      ; 54:  16-bit MPT0 IGBT EMG interrupt                              
                DCD     INTMTPTB00_IRQHandler     ; 55:  16-bit MPT0 IGBT period/ TMRB compare match detection 0     
                DCD     INTMTTTB01_IRQHandler     ; 56:  16-bit MPT0 IGBT trigger/ TMRB compare match detection 1    
                DCD     INTMTCAP00_IRQHandler     ; 57:  16-bit MPT0 input capture 0                                 
                DCD     INTMTCAP01_IRQHandler     ; 58:  16-bit MPT0 input capture 1                                 
                DCD     INTMTEMG1_IRQHandler      ; 59:  16-bit MPT1 IGBT EMG interrupt                              
                DCD     INTMTPTB10_IRQHandler     ; 60:  16-bit MPT1 IGBT period/ TMRB compare match detection 0     
                DCD     INTMTTTB11_IRQHandler     ; 61:  16-bit MPT1 IGBT trigger/ TMRB compare match detection 1    
                DCD     INTMTCAP10_IRQHandler     ; 62:  16-bit MPT1 input capture 0                                 
                DCD     INTMTCAP11_IRQHandler     ; 63:  16-bit MPT1 input capture 1                                 
                DCD     INTMTEMG2_IRQHandler      ; 64:  16-bit MPT2 IGBT EMG interrupt                              
                DCD     INTMTPTB20_IRQHandler     ; 65:  16-bit MPT2 IGBT period/ TMRB compare match detection 0     
                DCD     INTMTTTB21_IRQHandler     ; 66:  16-bit MPT2 IGBT trigger/ TMRB compare match detection 1    
                DCD     INTMTCAP20_IRQHandler     ; 67:  16-bit MPT2 input capture 0                                 
                DCD     INTMTCAP21_IRQHandler     ; 68:  16-bit MPT2 input capture 1                                 
                DCD     INTMTEMG3_IRQHandler      ; 69:  16-bit MPT3 IGBT EMG interrupt                              
                DCD     INTMTPTB30_IRQHandler     ; 70:  16-bit MPT3 IGBT period/ TMRB compare match detection 0     
                DCD     INTMTTTB31_IRQHandler     ; 71:  16-bit MPT3 IGBT trigger/ TMRB compare match detection 1    
                DCD     INTMTCAP30_IRQHandler     ; 72:  16-bit MPT3 input capture 0                                 
                DCD     INTMTCAP31_IRQHandler     ; 73:  16-bit MPT3 input capture 1                                 
                DCD     INTRMCRX_IRQHandler       ; 74:  Remote Controller reception interrupt                       
                DCD     INTTB0_IRQHandler         ; 75:  16-bit TMRB_0 match detection 0                             
                DCD     INTCAP00_IRQHandler       ; 76:  16-bit TMRB_0 input capture 00                              
                DCD     INTCAP01_IRQHandler       ; 77:  16-bit TMRB_0 input capture 01                              
                DCD     INTTB1_IRQHandler         ; 78:  16-bit TMRB_1 match detection 1                             
                DCD     INTCAP10_IRQHandler       ; 79:  16-bit TMRB_1 input capture 10                              
                DCD     INTCAP11_IRQHandler       ; 80:  16-bit TMRB_1 input capture 11                              
                DCD     INTTB2_IRQHandler         ; 81:  16-bit TMRB_2 match detection 2                             
                DCD     INTCAP20_IRQHandler       ; 82:  16-bit TMRB_2 input capture 20                              
                DCD     INTCAP21_IRQHandler       ; 83:  16-bit TMRB_2 input capture 21                              
                DCD     INTTB3_IRQHandler         ; 84:  16-bit TMRB_3 match detection 3                             
                DCD     INTCAP30_IRQHandler       ; 85:  16-bit TMRB_3 input capture 30                              
                DCD     INTCAP31_IRQHandler       ; 86:  16-bit TMRB_3 input capture 31                              
                DCD     INTTB4_IRQHandler         ; 87:  16-bit TMRB_4 match detection 4                             
                DCD     INTCAP40_IRQHandler       ; 88:  16-bit TMRB_4 input capture 40                              
                DCD     INTCAP41_IRQHandler       ; 89:  16-bit TMRB_4 input capture 41                              
                DCD     INTTB5_IRQHandler         ; 90:  16-bit TMRB_5 match detection 5                             
                DCD     INTCAP50_IRQHandler       ; 91:  16-bit TMRB_5 input capture 50                              
                DCD     INTCAP51_IRQHandler       ; 92:  16-bit TMRB_5 input capture 51                              
                DCD     INTTB6_IRQHandler         ; 93:  16-bit TMRB_6 match detection 6                             
                DCD     INTCAP60_IRQHandler       ; 94:  16-bit TMRB_6 input capture 60                              
                DCD     INTCAP61_IRQHandler       ; 95:  16-bit TMRB_6 input capture 61                              
                DCD     INTTB7_IRQHandler         ; 96:  16-bit TMRB_7 match detection 7                              
                DCD     INTCAP70_IRQHandler       ; 97:  16-bit TMRB_7 input capture 70                               
                DCD     INTCAP71_IRQHandler       ; 98:  16-bit TMRB_7 input capture 71                              
                DCD     INTRTC_IRQHandler         ; 99:  RTC(Real time clock) interrupt                              
                DCD     INTDMAADA_IRQHandler      ; 100: DMA_ADC_A conversion end                                    
                DCD     INTDMAADB_IRQHandler      ; 101: DMA_ADC_B conversion end                                    
                DCD     INTDMADAA_IRQHandler      ; 102: DMA_DAC_A conversion trigger                                
                DCD     INTDMADAB_IRQHandler      ; 103: DMA_DAC_B conversion trigger                                
                DCD     INTDMASPR0_IRQHandler     ; 104: DMA_SSP_0 reception / DMA_I2C SIO_0                         
                DCD     INTDMASPT0_IRQHandler     ; 105: DMA_SSP_0 transmission                                      
                DCD     INTDMASPR1_IRQHandler     ; 106: DMA_SSP_1 reception                                         
                DCD     INTDMASPT1_IRQHandler     ; 107: DMA_SSP_1 transmission                                      
                DCD     INTDMASPR2_IRQHandler     ; 108: DMA_SSP_2 reception                                         
                DCD     INTDMASPT2_IRQHandler     ; 109: DMA_SSP_2 transmission                                      
                DCD     INTDMAUTR4_IRQHandler     ; 110: DMA_FUART_4 reception                                       
                DCD     INTDMAUTT4_IRQHandler     ; 111: DMA_FUART_4 transmission                                    
                DCD     INTDMAUTR5_IRQHandler     ; 112: DMA_FUART_5 reception                                       
                DCD     INTDMAUTT5_IRQHandler     ; 113: DMA_FUART_5 transmission                                    
                DCD     INTDMARX0_IRQHandler      ; 114: DMA_SIO/ UART_0 reception                                   
                DCD     INTDMATX0_IRQHandler      ; 115: DMA_SIO/ UART_0 transmission                                
                DCD     INTDMARX1_IRQHandler      ; 116: DMA_SIO/ UART_1 reception                                   
                DCD     INTDMATX1_IRQHandler      ; 117: DMA_SIO/ UART_1 transmission                                
                DCD     INTDMARX2_IRQHandler      ; 118: DMA_SIO/ UART_2 reception                                   
                DCD     INTDMATX2_IRQHandler      ; 119: DMA_SIO/ UART_2 transmission                                
                DCD     INTDMARX3_IRQHandler      ; 120: DMA_SIO/ UART_3 reception                                   
                DCD     INTDMATX3_IRQHandler      ; 121: DMA_SIO/ UART_3 transmission                                
                DCD     INTDMASBI1_IRQHandler     ; 122: DMA_I2C/ SIO_1                                              
                DCD     INTDMASBI2_IRQHandler     ; 123: DMA_I2C/ SIO_2                                              
                DCD     INTDMATB_IRQHandler       ; 124: 16-bit TMRB_0-4 match detection                             
                DCD     INTDMARQ_IRQHandler       ; 125: DMA request pin                                             
                DCD     INTDMAAERR_IRQHandler     ; 126: DMA_A error transfer interrupt                              
                DCD     INTDMABERR_IRQHandler     ; 127: DMA_B error transfer interrupt                              
                
                

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
                EXPORT  INTUART4_IRQHandler       [WEAK]
                EXPORT  INTUART5_IRQHandler       [WEAK]
                EXPORT  INTSBI0_IRQHandler        [WEAK]
                EXPORT  INTSBI1_IRQHandler        [WEAK]
                EXPORT  INTSBI2_IRQHandler        [WEAK]
                EXPORT  INTSSP0_IRQHandler        [WEAK]
                EXPORT  INTSSP1_IRQHandler        [WEAK]
                EXPORT  INTSSP2_IRQHandler        [WEAK]
                EXPORT  INTUSBH_IRQHandler        [WEAK]
                EXPORT  INTUSBD_IRQHandler        [WEAK]
                EXPORT  INTUSBWKUP_IRQHandler     [WEAK]
                EXPORT  INTCANRX_IRQHandler       [WEAK]
                EXPORT  INTCANTX_IRQHandler       [WEAK]
                EXPORT  INTCANGB_IRQHandler       [WEAK]
                EXPORT  INTETH_IRQHandler         [WEAK]
                EXPORT  INTETHWK_IRQHandler       [WEAK]
                EXPORT  INTADAHP_IRQHandler       [WEAK]
                EXPORT  INTADAM0_IRQHandler       [WEAK]
                EXPORT  INTADAM1_IRQHandler       [WEAK]
                EXPORT  INTADA_IRQHandler         [WEAK]
                EXPORT  INTADBHP_IRQHandler       [WEAK]
                EXPORT  INTADBM0_IRQHandler       [WEAK]
                EXPORT  INTADBM1_IRQHandler       [WEAK]
                EXPORT  INTADB_IRQHandler         [WEAK]
                EXPORT  INTEMG0_IRQHandler        [WEAK]
                EXPORT  INTPMD0_IRQHandler        [WEAK]
                EXPORT  INTENC0_IRQHandler        [WEAK]
                EXPORT  INTEMG1_IRQHandler        [WEAK]
                EXPORT  INTPMD1_IRQHandler        [WEAK]
                EXPORT  INTENC1_IRQHandler        [WEAK]
                EXPORT  INTMTEMG0_IRQHandler      [WEAK]
                EXPORT  INTMTPTB00_IRQHandler     [WEAK]
                EXPORT  INTMTTTB01_IRQHandler     [WEAK]
                EXPORT  INTMTCAP00_IRQHandler     [WEAK]
                EXPORT  INTMTCAP01_IRQHandler     [WEAK]
                EXPORT  INTMTEMG1_IRQHandler      [WEAK]
                EXPORT  INTMTPTB10_IRQHandler     [WEAK]
                EXPORT  INTMTTTB11_IRQHandler     [WEAK]
                EXPORT  INTMTCAP10_IRQHandler     [WEAK]
                EXPORT  INTMTCAP11_IRQHandler     [WEAK]
                EXPORT  INTMTEMG2_IRQHandler      [WEAK]
                EXPORT  INTMTPTB20_IRQHandler     [WEAK]
                EXPORT  INTMTTTB21_IRQHandler     [WEAK]
                EXPORT  INTMTCAP20_IRQHandler     [WEAK]
                EXPORT  INTMTCAP21_IRQHandler     [WEAK]
                EXPORT  INTMTEMG3_IRQHandler      [WEAK]
                EXPORT  INTMTPTB30_IRQHandler     [WEAK]
                EXPORT  INTMTTTB31_IRQHandler     [WEAK]
                EXPORT  INTMTCAP30_IRQHandler     [WEAK]
                EXPORT  INTMTCAP31_IRQHandler     [WEAK]
                EXPORT  INTRMCRX_IRQHandler       [WEAK]
                EXPORT  INTTB0_IRQHandler         [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTTB1_IRQHandler         [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTTB2_IRQHandler         [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTTB3_IRQHandler         [WEAK]
                EXPORT  INTCAP30_IRQHandler       [WEAK]
                EXPORT  INTCAP31_IRQHandler       [WEAK]
                EXPORT  INTTB4_IRQHandler         [WEAK]
                EXPORT  INTCAP40_IRQHandler       [WEAK]
                EXPORT  INTCAP41_IRQHandler       [WEAK]
                EXPORT  INTTB5_IRQHandler         [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INTTB6_IRQHandler         [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTTB7_IRQHandler         [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTRTC_IRQHandler         [WEAK]
                EXPORT  INTDMAADA_IRQHandler      [WEAK]
                EXPORT  INTDMAADB_IRQHandler      [WEAK]
                EXPORT  INTDMADAA_IRQHandler      [WEAK]
                EXPORT  INTDMADAB_IRQHandler      [WEAK]
                EXPORT  INTDMASPR0_IRQHandler     [WEAK]
                EXPORT  INTDMASPT0_IRQHandler     [WEAK]
                EXPORT  INTDMASPR1_IRQHandler     [WEAK]
                EXPORT  INTDMASPT1_IRQHandler     [WEAK]
                EXPORT  INTDMASPR2_IRQHandler     [WEAK]
                EXPORT  INTDMASPT2_IRQHandler     [WEAK]
                EXPORT  INTDMAUTR4_IRQHandler     [WEAK]
                EXPORT  INTDMAUTT4_IRQHandler     [WEAK]
                EXPORT  INTDMAUTR5_IRQHandler     [WEAK]
                EXPORT  INTDMAUTT5_IRQHandler     [WEAK]
                EXPORT  INTDMARX0_IRQHandler      [WEAK]
                EXPORT  INTDMATX0_IRQHandler      [WEAK]
                EXPORT  INTDMARX1_IRQHandler      [WEAK]
                EXPORT  INTDMATX1_IRQHandler      [WEAK]
                EXPORT  INTDMARX2_IRQHandler      [WEAK]
                EXPORT  INTDMATX2_IRQHandler      [WEAK]
                EXPORT  INTDMARX3_IRQHandler      [WEAK]
                EXPORT  INTDMATX3_IRQHandler      [WEAK]
                EXPORT  INTDMASBI1_IRQHandler     [WEAK]
                EXPORT  INTDMASBI2_IRQHandler     [WEAK]
                EXPORT  INTDMATB_IRQHandler       [WEAK]
                EXPORT  INTDMARQ_IRQHandler       [WEAK]
                EXPORT  INTDMAAERR_IRQHandler     [WEAK]
                EXPORT  INTDMABERR_IRQHandler     [WEAK]
                        
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
INTUART4_IRQHandler             
INTUART5_IRQHandler             
INTSBI0_IRQHandler              
INTSBI1_IRQHandler              
INTSBI2_IRQHandler              
INTSSP0_IRQHandler              
INTSSP1_IRQHandler              
INTSSP2_IRQHandler              
INTUSBH_IRQHandler              
INTUSBD_IRQHandler              
INTUSBWKUP_IRQHandler           
INTCANRX_IRQHandler             
INTCANTX_IRQHandler             
INTCANGB_IRQHandler             
INTETH_IRQHandler               
INTETHWK_IRQHandler             
INTADAHP_IRQHandler             
INTADAM0_IRQHandler             
INTADAM1_IRQHandler             
INTADA_IRQHandler               
INTADBHP_IRQHandler             
INTADBM0_IRQHandler             
INTADBM1_IRQHandler             
INTADB_IRQHandler               
INTEMG0_IRQHandler              
INTPMD0_IRQHandler              
INTENC0_IRQHandler              
INTEMG1_IRQHandler              
INTPMD1_IRQHandler              
INTENC1_IRQHandler              
INTMTEMG0_IRQHandler            
INTMTPTB00_IRQHandler           
INTMTTTB01_IRQHandler           
INTMTCAP00_IRQHandler           
INTMTCAP01_IRQHandler           
INTMTEMG1_IRQHandler            
INTMTPTB10_IRQHandler           
INTMTTTB11_IRQHandler           
INTMTCAP10_IRQHandler           
INTMTCAP11_IRQHandler           
INTMTEMG2_IRQHandler            
INTMTPTB20_IRQHandler           
INTMTTTB21_IRQHandler           
INTMTCAP20_IRQHandler           
INTMTCAP21_IRQHandler           
INTMTEMG3_IRQHandler            
INTMTPTB30_IRQHandler           
INTMTTTB31_IRQHandler           
INTMTCAP30_IRQHandler           
INTMTCAP31_IRQHandler           
INTRMCRX_IRQHandler             
INTTB0_IRQHandler               
INTCAP00_IRQHandler             
INTCAP01_IRQHandler             
INTTB1_IRQHandler               
INTCAP10_IRQHandler             
INTCAP11_IRQHandler             
INTTB2_IRQHandler               
INTCAP20_IRQHandler             
INTCAP21_IRQHandler             
INTTB3_IRQHandler               
INTCAP30_IRQHandler             
INTCAP31_IRQHandler             
INTTB4_IRQHandler               
INTCAP40_IRQHandler             
INTCAP41_IRQHandler             
INTTB5_IRQHandler               
INTCAP50_IRQHandler             
INTCAP51_IRQHandler             
INTTB6_IRQHandler               
INTCAP60_IRQHandler             
INTCAP61_IRQHandler             
INTTB7_IRQHandler               
INTCAP70_IRQHandler             
INTCAP71_IRQHandler             
INTRTC_IRQHandler               
INTDMAADA_IRQHandler            
INTDMAADB_IRQHandler            
INTDMADAA_IRQHandler            
INTDMADAB_IRQHandler            
INTDMASPR0_IRQHandler           
INTDMASPT0_IRQHandler           
INTDMASPR1_IRQHandler           
INTDMASPT1_IRQHandler           
INTDMASPR2_IRQHandler           
INTDMASPT2_IRQHandler           
INTDMAUTR4_IRQHandler           
INTDMAUTT4_IRQHandler           
INTDMAUTR5_IRQHandler           
INTDMAUTT5_IRQHandler           
INTDMARX0_IRQHandler            
INTDMATX0_IRQHandler            
INTDMARX1_IRQHandler            
INTDMATX1_IRQHandler            
INTDMARX2_IRQHandler            
INTDMATX2_IRQHandler            
INTDMARX3_IRQHandler            
INTDMATX3_IRQHandler            
INTDMASBI1_IRQHandler           
INTDMASBI2_IRQHandler           
INTDMATB_IRQHandler             
INTDMARQ_IRQHandler             
INTDMAAERR_IRQHandler           
INTDMABERR_IRQHandler           

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
