;/**
; ***************************************************************************
; * @file     startup_TMPM369.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM369' Device Series 
; * @version  V2.0.2.2 (Tentative)
; * @date     2011/09/29
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

                PUBWEAK INT8_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT8_IRQHandler
                B       INT8_IRQHandler

                PUBWEAK INT9_IRQHandler
                SECTION .text:CODE:REORDER(1)
INT9_IRQHandler
                B       INT9_IRQHandler

                PUBWEAK INTA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTA_IRQHandler
                B       INTA_IRQHandler

                PUBWEAK INTB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTB_IRQHandler
                B       INTB_IRQHandler

                PUBWEAK INTC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTC_IRQHandler
                B       INTC_IRQHandler

                PUBWEAK INTD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTD_IRQHandler
                B       INTD_IRQHandler

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

                PUBWEAK INTUART4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTUART4_IRQHandler
                B       INTUART4_IRQHandler

                PUBWEAK INTUART5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTUART5_IRQHandler
                B       INTUART5_IRQHandler

                PUBWEAK INTSBI0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI0_IRQHandler
                B       INTSBI0_IRQHandler

                PUBWEAK INTSBI1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI1_IRQHandler
                B       INTSBI1_IRQHandler

                PUBWEAK INTSBI2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSBI2_IRQHandler
                B       INTSBI2_IRQHandler

                PUBWEAK INTSSP0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSSP0_IRQHandler
                B       INTSSP0_IRQHandler

                PUBWEAK INTSSP1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSSP1_IRQHandler
                B       INTSSP1_IRQHandler

                PUBWEAK INTSSP2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTSSP2_IRQHandler
                B       INTSSP2_IRQHandler

                PUBWEAK INTUSBH_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTUSBH_IRQHandler
                B       INTUSBH_IRQHandler

                PUBWEAK INTUSBD_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTUSBD_IRQHandler
                B       INTUSBD_IRQHandler

                PUBWEAK INTUSBWKUP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTUSBWKUP_IRQHandler
                B       INTUSBWKUP_IRQHandler

                PUBWEAK INTCANRX_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCANRX_IRQHandler
                B       INTCANRX_IRQHandler

                PUBWEAK INTCANTX_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCANTX_IRQHandler
                B       INTCANTX_IRQHandler

                PUBWEAK INTCANGB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCANGB_IRQHandler
                B       INTCANGB_IRQHandler

                PUBWEAK INTETH_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTETH_IRQHandler
                B       INTETH_IRQHandler

                PUBWEAK INTETHWK_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTETHWK_IRQHandler
                B       INTETHWK_IRQHandler

                PUBWEAK INTADAHP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADAHP_IRQHandler
                B       INTADAHP_IRQHandler

                PUBWEAK INTADAM0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADAM0_IRQHandler
                B       INTADAM0_IRQHandler

                PUBWEAK INTADAM1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADAM1_IRQHandler
                B       INTADAM1_IRQHandler

                PUBWEAK INTADA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADA_IRQHandler
                B       INTADA_IRQHandler

                PUBWEAK INTADBHP_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBHP_IRQHandler
                B       INTADBHP_IRQHandler

                PUBWEAK INTADBM0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBM0_IRQHandler
                B       INTADBM0_IRQHandler

                PUBWEAK INTADBM1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBM1_IRQHandler
                B       INTADBM1_IRQHandler

                PUBWEAK INTADB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADB_IRQHandler
                B       INTADB_IRQHandler

                PUBWEAK INTEMG0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTEMG0_IRQHandler
                B       INTEMG0_IRQHandler

                PUBWEAK INTPMD0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPMD0_IRQHandler
                B       INTPMD0_IRQHandler

                PUBWEAK INTENC0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTENC0_IRQHandler
                B       INTENC0_IRQHandler

                PUBWEAK INTEMG1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTEMG1_IRQHandler
                B       INTEMG1_IRQHandler

                PUBWEAK INTPMD1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPMD1_IRQHandler
                B       INTPMD1_IRQHandler

                PUBWEAK INTENC1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTENC1_IRQHandler
                B       INTENC1_IRQHandler

                PUBWEAK INTMTEMG0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTEMG0_IRQHandler
                B       INTMTEMG0_IRQHandler

                PUBWEAK INTMTPTB00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTPTB00_IRQHandler
                B       INTMTPTB00_IRQHandler

                PUBWEAK INTMTTTB01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTTTB01_IRQHandler
                B       INTMTTTB01_IRQHandler

                PUBWEAK INTMTCAP00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP00_IRQHandler
                B       INTMTCAP00_IRQHandler

                PUBWEAK INTMTCAP01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP01_IRQHandler
                B       INTMTCAP01_IRQHandler

                PUBWEAK INTMTEMG1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTEMG1_IRQHandler
                B       INTMTEMG1_IRQHandler

                PUBWEAK INTMTPTB10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTPTB10_IRQHandler
                B       INTMTPTB10_IRQHandler

                PUBWEAK INTMTTTB11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTTTB11_IRQHandler
                B       INTMTTTB11_IRQHandler

                PUBWEAK INTMTCAP10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP10_IRQHandler
                B       INTMTCAP10_IRQHandler

                PUBWEAK INTMTCAP11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP11_IRQHandler
                B       INTMTCAP11_IRQHandler

                PUBWEAK INTMTEMG2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTEMG2_IRQHandler
                B       INTMTEMG2_IRQHandler

                PUBWEAK INTMTPTB20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTPTB20_IRQHandler
                B       INTMTPTB20_IRQHandler

                PUBWEAK INTMTTTB21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTTTB21_IRQHandler
                B       INTMTTTB21_IRQHandler

                PUBWEAK INTMTCAP20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP20_IRQHandler
                B       INTMTCAP20_IRQHandler

                PUBWEAK INTMTCAP21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP21_IRQHandler
                B       INTMTCAP21_IRQHandler

                PUBWEAK INTMTEMG3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTEMG3_IRQHandler
                B       INTMTEMG3_IRQHandler

                PUBWEAK INTMTPTB30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTPTB30_IRQHandler
                B       INTMTPTB30_IRQHandler

                PUBWEAK INTMTTTB31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTTTB31_IRQHandler
                B       INTMTTTB31_IRQHandler

                 PUBWEAK INTMTCAP30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP30_IRQHandler
                B       INTMTCAP30_IRQHandler

                 PUBWEAK INTMTCAP31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTMTCAP31_IRQHandler
                B       INTMTCAP31_IRQHandler

                 PUBWEAK INTRMCRX_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRMCRX_IRQHandler
                B       INTRMCRX_IRQHandler

                 PUBWEAK INTTB0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB0_IRQHandler
                B       INTTB0_IRQHandler

                 PUBWEAK INTCAP00_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP00_IRQHandler
                B       INTCAP00_IRQHandler

                 PUBWEAK INTCAP01_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP01_IRQHandler
                B       INTCAP01_IRQHandler

                 PUBWEAK INTTB1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB1_IRQHandler
                B       INTTB1_IRQHandler

                 PUBWEAK INTCAP10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP10_IRQHandler
                B       INTCAP10_IRQHandler

                 PUBWEAK INTCAP11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP11_IRQHandler
                B       INTCAP11_IRQHandler

                 PUBWEAK INTTB2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB2_IRQHandler
                B       INTTB2_IRQHandler

                 PUBWEAK INTCAP20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP20_IRQHandler
                B       INTCAP20_IRQHandler

                 PUBWEAK INTCAP21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP21_IRQHandler
                B       INTCAP21_IRQHandler

                 PUBWEAK INTTB3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB3_IRQHandler
                B       INTTB3_IRQHandler

                 PUBWEAK INTCAP30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP30_IRQHandler
                B       INTCAP30_IRQHandler

                 PUBWEAK INTCAP31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP31_IRQHandler
                B       INTCAP31_IRQHandler

                 PUBWEAK INTTB4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB4_IRQHandler
                B       INTTB4_IRQHandler

                 PUBWEAK INTCAP40_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP40_IRQHandler
                B       INTCAP40_IRQHandler

                 PUBWEAK INTCAP41_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP41_IRQHandler
                B       INTCAP41_IRQHandler

                 PUBWEAK INTTB5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB5_IRQHandler
                B       INTTB5_IRQHandler

                 PUBWEAK INTCAP50_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP50_IRQHandler
                B       INTCAP50_IRQHandler

                 PUBWEAK INTCAP51_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP51_IRQHandler
                B       INTCAP51_IRQHandler

                 PUBWEAK INTTB6_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB6_IRQHandler
                B       INTTB6_IRQHandler

                 PUBWEAK INTCAP60_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP60_IRQHandler
                B       INTCAP60_IRQHandler

                 PUBWEAK INTCAP61_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP61_IRQHandler
                B       INTCAP61_IRQHandler

                 PUBWEAK INTTB7_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB7_IRQHandler
                B       INTTB7_IRQHandler

                 PUBWEAK INTCAP70_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP70_IRQHandler
                B       INTCAP70_IRQHandler

                 PUBWEAK INTCAP71_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP71_IRQHandler
                B       INTCAP71_IRQHandler

                 PUBWEAK INTRTC_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRTC_IRQHandler
                B       INTRTC_IRQHandler

                 PUBWEAK INTDMAADA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAADA_IRQHandler
                B       INTDMAADA_IRQHandler

                 PUBWEAK INTDMAADB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAADB_IRQHandler
                B       INTDMAADB_IRQHandler

                 PUBWEAK INTDMADAA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMADAA_IRQHandler
                B       INTDMADAA_IRQHandler

                 PUBWEAK INTDMADAB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMADAB_IRQHandler
                B       INTDMADAB_IRQHandler

                 PUBWEAK INTDMASPR0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPR0_IRQHandler
                B       INTDMASPR0_IRQHandler

                 PUBWEAK INTDMASPT0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPT0_IRQHandler
                B       INTDMASPT0_IRQHandler

                 PUBWEAK INTDMASPR1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPR1_IRQHandler
                B       INTDMASPR1_IRQHandler

                 PUBWEAK INTDMASPT1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPT1_IRQHandler
                B       INTDMASPT1_IRQHandler

                PUBWEAK INTDMASPR2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPR2_IRQHandler
                B       INTDMASPR2_IRQHandler

                PUBWEAK INTDMASPT2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASPT2_IRQHandler
                B       INTDMASPT2_IRQHandler

                PUBWEAK INTDMAUTR4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAUTR4_IRQHandler
                B       INTDMAUTR4_IRQHandler

                PUBWEAK INTDMAUTT4_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAUTT4_IRQHandler
                B       INTDMAUTT4_IRQHandler

                PUBWEAK INTDMAUTR5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAUTR5_IRQHandler
                B       INTDMAUTR5_IRQHandler

                PUBWEAK INTDMAUTT5_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAUTT5_IRQHandler
                B       INTDMAUTT5_IRQHandler

                PUBWEAK INTDMARX0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMARX0_IRQHandler
                B       INTDMARX0_IRQHandler

                PUBWEAK INTDMATX0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMATX0_IRQHandler
                B       INTDMATX0_IRQHandler

                PUBWEAK INTDMARX1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMARX1_IRQHandler
                B       INTDMARX1_IRQHandler

                PUBWEAK INTDMATX1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMATX1_IRQHandler
                B       INTDMATX1_IRQHandler

                PUBWEAK INTDMARX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMARX2_IRQHandler
                B       INTDMARX2_IRQHandler

                PUBWEAK INTDMATX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMATX2_IRQHandler
                B       INTDMATX2_IRQHandler

                PUBWEAK INTDMARX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMARX3_IRQHandler
                B       INTDMARX3_IRQHandler

                PUBWEAK INTDMATX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMATX3_IRQHandler
                B       INTDMATX3_IRQHandler

                PUBWEAK INTDMASBI1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASBI1_IRQHandler
                B       INTDMASBI1_IRQHandler

                PUBWEAK INTDMASBI2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMASBI2_IRQHandler
                B       INTDMASBI2_IRQHandler

                PUBWEAK INTDMATB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMATB_IRQHandler
                B       INTDMATB_IRQHandler

                PUBWEAK INTDMARQ_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMARQ_IRQHandler
                B       INTDMARQ_IRQHandler

                PUBWEAK INTDMAAERR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMAAERR_IRQHandler
                B       INTDMAAERR_IRQHandler

                PUBWEAK INTDMABERR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTDMABERR_IRQHandler
                B       INTDMABERR_IRQHandler
              
                END
