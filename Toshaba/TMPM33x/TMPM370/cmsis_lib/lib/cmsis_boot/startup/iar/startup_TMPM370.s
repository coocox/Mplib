;/**
; ***************************************************************************
; * @file     startup_TMPM370.s
; * @brief    CMSIS Cortex-M3 Core Device Startup File for the
; *           TOSHIBA 'TMPM370' Device Series 
; * @version  V2.2.0
; * @date     2010/12/09
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
;*/
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

                PUBWEAK INTVCNA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTVCNA_IRQHandler
                B       INTVCNA_IRQHandler

                PUBWEAK INTVCNB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTVCNB_IRQHandler
                B       INTVCNB_IRQHandler

                PUBWEAK INTEMG0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTEMG0_IRQHandler
                B       INTEMG0_IRQHandler

                PUBWEAK INTEMG1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTEMG1_IRQHandler
                B       INTEMG1_IRQHandler

                PUBWEAK INTOVV0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTOVV0_IRQHandler
                B       INTOVV0_IRQHandler

                PUBWEAK INTOVV1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTOVV1_IRQHandler
                B       INTOVV1_IRQHandler

                PUBWEAK INTADAPDA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADAPDA_IRQHandler
                B       INTADAPDA_IRQHandler

                PUBWEAK INTADBPDA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBPDA_IRQHandler
                B       INTADBPDA_IRQHandler

                PUBWEAK INTADAPDB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADAPDB_IRQHandler
                B       INTADAPDB_IRQHandler

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

                PUBWEAK INTTB10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB10_IRQHandler
                B       INTTB10_IRQHandler

                PUBWEAK INTTB11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB11_IRQHandler
                B       INTTB11_IRQHandler

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

                PUBWEAK INTPMD0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTPMD0_IRQHandler
                B       INTPMD0_IRQHandler

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

                PUBWEAK INTCAP10_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP10_IRQHandler
                B       INTCAP10_IRQHandler

                PUBWEAK INTCAP11_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP11_IRQHandler
                B       INTCAP11_IRQHandler

                PUBWEAK INTCAP40_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP40_IRQHandler
                B       INTCAP40_IRQHandler

                PUBWEAK INTCAP41_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP41_IRQHandler
                B       INTCAP41_IRQHandler

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

                PUBWEAK INTRX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX2_IRQHandler
                B       INTRX2_IRQHandler

                PUBWEAK INTTX2_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX2_IRQHandler
                B       INTTX2_IRQHandler

                PUBWEAK INTADACPA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADACPA_IRQHandler
                B       INTADACPA_IRQHandler

                PUBWEAK INTADBCPA_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBCPA_IRQHandler
                B       INTADBCPA_IRQHandler

                PUBWEAK INTADACPB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADACPB_IRQHandler
                B       INTADACPB_IRQHandler

                PUBWEAK INTADBCPB_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBCPB_IRQHandler
                B       INTADBCPB_IRQHandler

                PUBWEAK INTTB20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB20_IRQHandler
                B       INTTB20_IRQHandler

                PUBWEAK INTTB21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB21_IRQHandler
                B       INTTB21_IRQHandler

                PUBWEAK INTTB30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB30_IRQHandler
                B       INTTB30_IRQHandler

                PUBWEAK INTTB31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB31_IRQHandler
                B       INTTB31_IRQHandler

                PUBWEAK INTCAP20_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP20_IRQHandler
                B       INTCAP20_IRQHandler

                PUBWEAK INTCAP21_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP21_IRQHandler
                B       INTCAP21_IRQHandler

                PUBWEAK INTCAP30_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP30_IRQHandler
                B       INTCAP30_IRQHandler

                PUBWEAK INTCAP31_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP31_IRQHandler
                B       INTCAP31_IRQHandler

                PUBWEAK INTADASFT_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADASFT_IRQHandler
                B       INTADASFT_IRQHandler

                PUBWEAK INTADBSFT_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBSFT_IRQHandler
                B       INTADBSFT_IRQHandler

                PUBWEAK INTADATMR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADATMR_IRQHandler
                B       INTADATMR_IRQHandler

                PUBWEAK INTADBTMR_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTADBTMR_IRQHandler
                B       INTADBTMR_IRQHandler

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

                PUBWEAK INTENC0_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTENC0_IRQHandler
                B       INTENC0_IRQHandler

                PUBWEAK INTENC1_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTENC1_IRQHandler
                B       INTENC1_IRQHandler

                PUBWEAK INTRX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTRX3_IRQHandler
                B       INTRX3_IRQHandler

                PUBWEAK INTTX3_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTX3_IRQHandler
                B       INTTX3_IRQHandler

                PUBWEAK INTTB60_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB60_IRQHandler
                B       INTTB60_IRQHandler

                PUBWEAK INTTB61_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB61_IRQHandler
                B       INTTB61_IRQHandler

                PUBWEAK INTTB70_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB70_IRQHandler
                B       INTTB70_IRQHandler

                PUBWEAK INTTB71_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTTB71_IRQHandler
                B       INTTB71_IRQHandler

                PUBWEAK INTCAP60_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP60_IRQHandler
                B       INTCAP60_IRQHandler

                PUBWEAK INTCAP61_IRQHandler
                SECTION .text:CODE:REORDER(1)
INTCAP61_IRQHandler
                B       INTCAP61_IRQHandler

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

                END
