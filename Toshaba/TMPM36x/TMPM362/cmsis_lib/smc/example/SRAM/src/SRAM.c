/**
 *******************************************************************************
 * @file    SRAM.c
 * @brief   the application functions of SRAM demo for the 
 *          TOSHIBA 'TMPM362' Device Series 
 * @version V0.140
 * @date    2011/02/22
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */
#include <string.h>
#include "tmpm362_smc.h"
#include "tmpm362_uart.h"

#define UART UART0

void UART_Configuration(TSB_SC_TypeDef * SCx);
void UART_Print(TSB_SC_TypeDef * UARTx, char *string);
uint8_t SMC_GetBusMode(void);

uint8_t SMC_GetBusMode(void)
{
    uint8_t BusMode = 0xFFU;

    BusMode = (uint8_t) TSB_SMCMD->MODE;
    return BusMode;
}

/* The demo is for external 16-bit SRAM, separate bus mode */
void SRAM(void)
{
    uint8_t chip = 0xFFU;
    SMC_IFConfigTypeDef config = { 0U };
    uint8_t bus_w = 0xFFU;
    uint8_t bus_r = 0xFFU;
    SMC_CyclesTypeDef cycles_w = { 0U };
    SMC_CyclesTypeDef cycles_r = { 0U };
    SMC_OpModeTypeDef opmode_w = { 0U };
    SMC_OpModeTypeDef opmode_r = { 0U };
    SMC_DirectCMDTypeDef cmd = { 0U };
	uint8_t retval = 0U;

	UART_Configuration(UART);
	UART_Print(UART, "This is an example for SMC\n\r");
	UART_Print(UART, "Initializing the SRAM...\n\r");

    /* Initial process demo */

    /* Herein describe SRAM model number and basic infomation */
    /* CS0: 0x60000000 ~ 0x60FFFFFF(16MB) */
    /* CS1: 0x61000000 ~ 0x61FFFFFF(16MB) */
    /* CS2: 0x62000000 ~ 0x62FFFFFF(16MB) */
    /* CS3: 0x63000000 ~ 0x63FFFFFF(16MB) */
    chip = SMC_CS2;

    bus_w = SMC_BUS_MULTIPLEX;  /* Address bus and data bus are multiplexed */
    SMC_SetBusMode(bus_w);

    bus_r = SMC_GetBusMode();
    if (bus_w != bus_r) {
        retval |= 0x01U;
    }

    SMC_GetIFConfig(&config);
    if (config.MemoryType != SMC_MULTIPLEX_SRAM) {
        /* If multiplex bus mode, MemoryType is SMC_MULTIPLEX_SRAM */
        retval = 0x02U;
    }
    if (config.MemoryWidth != SMC_DATA_BUS_16BIT) {
        /* SMC_DATA_BUS_16BIT can not be read out if no external memory, */
        /* and default value of "0x02" will be read out. */
        retval |= 0x04U;
    }
    if ((config.MemoryChips) != SMC_MEMORY_CHIPS_4) {
        retval |= 0x08U;
    }

    /* Set cycles time according to AC timing of SRAM datasheet,base clock: SMCCLK(fsys*1/2) */

    /* Separate bus mode:tCEOE + SMCCLK*1clk <= tRC  */
    /* Multiplex bus mode:tCEOE + SMCCLK*2clk <= tRC */
    cycles_w.RC_Time = SMC_READ_CYCLE_TIME_5;
    /* Separate bus mode:tWP + SMCCLK*2clk <= tWC  */
    /* Multiplex bus mode:tWP + SMCCLK*3clk <= tWC */
    cycles_w.WC_Time = SMC_WRITE_CYCLE_TIME_5;
    cycles_w.CEOE_Time = SMC_CEOE_DELAY_CYCLE_TIME_1;
    cycles_w.WP_Time = SMC_WE_PULSE_CYCLE_TIME_1;

    /* PC_Time is only effective for separate bus mode */
    /* It's necessary to also set to pass parameter check in multiplex bus mode */
    cycles_w.PC_Time = SMC_PAGE_CYCLE_TIME_5;

    cycles_w.TR_Time = SMC_TURN_AROUND_CYCLE_TIME_1;
    SMC_SetCycles(&cycles_w);

    opmode_w.BusWidth = SMC_DATA_BUS_16BIT;
    opmode_w.ReadBurstLen = SMC_READ_BURST_4BEAT;
    opmode_w.ALE = ENABLE;      /* ALE must be enabled in multiplex bus mode */
    SMC_SetOpMode(&opmode_w);

    /* Make sure SMC_SetCycles and SMC_SetOpMode are performed before SMC_SendDirectCMD */
    cmd.CmdType = SMC_CMD_UPDATEREGS;
    cmd.ChipSelect = chip;
    SMC_SendDirectCMD(&cmd);

    /* Read cycles and opmode for verify */
    SMC_GetCycles(chip, &cycles_r);
    if (memcmp(&cycles_r, &cycles_w, sizeof(SMC_CyclesTypeDef)) != 0) {
        retval |= 0x10U;
    }

    SMC_GetOpMode(chip, &opmode_r);
    opmode_w.StartAddr = SMC_START_ADDR_CHIP0 | (uint8_t) chip; /* For compare with read out opmode */
    if (memcmp(&opmode_r, &opmode_w, sizeof(SMC_OpModeTypeDef)) != 0) {
        retval |= 0x20U;
    }

    /* check retval to see if SRAM initialization is sucessful or not */
    if (retval == 0U) {
		UART_Print(UART, "SRAM initialization is sucessful!\n\r");/* Sucessful */
    } else {
		UART_Print(UART, "SRAM initialization is failed!\n\r");/* Failed */
    }
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
        TSB_PE_CR_PE4C = 1;
        TSB_PE_FR2_PE4F2 = 1;
        TSB_PE_FR2_PE5F2 = 1;
        TSB_PE_IE_PE5IE = 1;
    } else {
		//do nothing
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
