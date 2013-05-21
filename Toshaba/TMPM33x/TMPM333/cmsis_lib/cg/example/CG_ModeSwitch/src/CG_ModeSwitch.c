/**
 *******************************************************************************
 * @file    CG_ModeSwitch.c
 * @brief   The demo functions of CG for the TOSHIBA 'TMPM333' Device Series 
 * @version V1.200
 * @date    2010/06/22
 * 
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 * 
 * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
 * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
 * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
 * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

#include "tmpm333_cg.h"
#include "tmpm333_uart.h"

#define MODE_NORMAL         ((uint8_t)0x00)
#define MODE_TOBESLEEP      ((uint8_t)0x01)
#define MODE_INSLEEP        ((uint8_t)0x02)
#define MODE_TOBENORMAL     ((uint8_t)0x03)

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
Result CG_EnableClkMulCircuit(void);
uint8_t gStandByMode = MODE_NORMAL;

void CG_ModeSwitch(void)
{
    /*SystemInit(); */
    /* Set CG Module  */
    TSB_WD_MOD_WDTE = 0U;
    TSB_WD->CR = 0x000000B1;
    /* set fgear = fc/2 */
    CG_SetFgearLevel(CG_DIVIDE_2);
    /* set fperi = fgear  fpreclk = fperi/32 */
    CG_SetPhiT0Level(CG_DIVIDE_64);
    /* set SCOUT source to fT0 */
    CG_SetSCOUTSrc(CG_SCOUT_SRC_PHIT0);
    /* enable high-speed oscillation */
    CG_SetFosc(ENABLE);
    /* enable low-speed oscillation */
    CG_SetFs(ENABLE);
    /* set low power consumption mode sleep */
    CG_SetSTBYMode(CG_STBY_MODE_SLEEP);
    /* set high-speed and low-speed oscillation to be enabled after releasing stop mode */
    CG_SetExitStopModeFosc(ENABLE);
    CG_SetExitStopModeFs(ENABLE);
    /* set pin status in stop mode to "active" */
    CG_SetPinStateInStopMode(ENABLE);
    /*set up pll and wait 200us for pll to warm up , set fc source to fpll */
    CG_EnableClkMulCircuit();
    /* set system clock to fgear */
    CG_SetFsysSrc(CG_FSYS_SRC_FGEAR);
    
    UART_Configuration(UART0);
		
    do {
	UART_Print(UART0, "Nrml->Slow->Slp\n\r");
	UART_Print(UART0, "Press K1: Start\n\r");
        gStandByMode = MODE_TOBESLEEP;

        if (MODE_TOBESLEEP == gStandByMode) {
	    UART_Print(UART0, "\n\r");
	    UART_Print(UART0, "\n\r");
            /* set CG module: Normal ->Slow mode */
            /*... add code here to disable modules (except CPU,RTC,I/O,CEC and RMC) if it has been enabled... */
            /* then set system clock to fs */
            CG_SetFsysSrc(CG_FSYS_SRC_FS);
            /* then stop high-speed oscillation */
            CG_SetFosc(DISABLE);

	    UART_Print(UART0, "in slow mode\n\r");

            /* Set CG Module : Slow ->Sleep mode */
            __disable_irq();
            /* set source(RTC interrupt) to exit sleep mode */
            CG_SetSTBYReleaseINTSrc(CG_INT_SRC_RTC, CG_INT_ACTIVE_STATE_FALLING, ENABLE);
            /* enable RTC interrupt */
            NVIC_ClearPendingIRQ(INTRTC_IRQn);
            NVIC_EnableIRQ(INTRTC_IRQn);
            /*clear interrupt request */
            CG_ClearINTReq(CG_INT_SRC_RTC);
            /* set current time */
            TSB_RTC->RESTR = 0xf0U;
            TSB_RTC->PAGER = 0x00U;
            TSB_RTC->SECR = 0x00U;
            TSB_RTC->MINR = 0x00U;
            TSB_RTC->HOURR = 0x00U;
            TSB_RTC->DAYR = 0x01U;
            TSB_RTC->DATER = 0x01U;
            TSB_RTC->MONTHR = 0x01U;
            TSB_RTC->YEARR = 0x01U;

            /* alarm disable, page =1 */
            TSB_RTC->PAGER = 0x1U;
            /* set alarm time = clock+2min */
            TSB_RTC->MINR = 0x02U;
            TSB_RTC->HOURR = 0x00U;
            TSB_RTC->DAYR = 0x01U;
            TSB_RTC->DATER = 0x01U;
            TSB_RTC->MONTHR = 0x01U;
            /* enable alarm */
            TSB_RTC->PAGER = 0x0cU;
            /* enable RTC interrupt */
            TSB_RTC->PAGER = 0x8cU;
            __enable_irq();

	    UART_Print(UART0, "to be sleep mode\n\r");
            gStandByMode = MODE_INSLEEP;
            /* enter sleep mode */
            __WFI();
            /* Interrupt is needed to exit sleep mode */
            /* wait 2 min to generate RTC interrupt */
            //LCD_Light(ON);
        }

        if (MODE_TOBENORMAL == gStandByMode) {
	    UART_Print(UART0, "wk up, slow mode\n\r");
            /* set CG module :Slow -> Normal */
            /* start high-speed oscillation */
            CG_SetFosc(ENABLE);
            /* wait 1.953ms for fosc to warm up */
            CG_SetWarmUpTime(CG_WARM_UP_SRC_XT1, CG_WARM_UP_TIME_EXP_6);
            /* start warm up */
            CG_StartWarmUp();
            /* check whether warm up ends or not */
            /* check whether warm up ends or not */
            while (CG_GetWarmUpState() == BUSY);
            /* set system clock to clock-gear */
            CG_SetFsysSrc(CG_FSYS_SRC_FGEAR);
            gStandByMode = MODE_NORMAL;
        }
    } while (1);
}

void INTRTC_IRQHandler()
{
    gStandByMode = MODE_TOBENORMAL;
    CG_ClearINTReq(CG_INT_SRC_RTC);
}


Result CG_EnableClkMulCircuit(void)
{
    Result retval = ERROR;
    WorkState st = BUSY;
    retval = CG_SetPLL(ENABLE);    
    if (retval == SUCCESS) {
        /*set warm up time to about 200us */
        retval = CG_SetWarmUpTime(CG_WARM_UP_SRC_X1, CG_WARM_UP_TIME_EXP_11);
        if (retval == SUCCESS) {
            CG_StartWarmUp();
            /*wait warm up to end */
            do {
                st = CG_GetWarmUpState();
            } while (st != DONE);
            retval = CG_SetFcSrc(CG_FC_SRC_FPLL);
        } else {
            /*Do nothing */
        }
    } else {
        /*Do nothing */
    }
    return retval;
}

void UART_Print(TSB_SC_TypeDef * UARTx, char *string)
{
	  char *p = string;
	  int i;
	  while(*p)
	  {
		    UART_SetTxData(UARTx, (uint32_t)(*p));
		    p++;
		    for(i = 0; i < 1000; i ++);
	  }
}

void UART_Configuration(TSB_SC_TypeDef * SCx)
{
    UART_InitTypeDef myUART;
    if (SCx == UART0) {
        TSB_PE_CR_PE0C = 1U;
        TSB_PE_FR1_PE0F1 = 1U;
        TSB_PE_FR1_PE1F1 = 1U;
        TSB_PE_IE_PE1IE = 1U;
    } else if (SCx == UART1) {
        TSB_PE_CR_PE4C = 1U;
        TSB_PE_FR1_PE4F1 = 1U;
        TSB_PE_FR1_PE5F1 = 1U;
        TSB_PE_IE_PE5IE = 1U;
    } else if (SCx == UART2) {
        TSB_PF_CR_PF0C = 1U;
        TSB_PF_FR1_PF0F1 = 1U;
        TSB_PF_FR1_PF1F1 = 1U;
        TSB_PF_IE_PF1IE = 1U;
    } else {
        /* Do nothing */
    }
    myUART.BaudRate = 115200U;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(SCx);
    UART_Init(SCx, &myUART);
}
