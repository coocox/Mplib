/**
 *******************************************************************************
 * @file    main.c
 * @brief   the application functions of EXB demo for the 
 *          TOSHIBA 'TMPM341' Device Series 
 * @version V0.100
 * @date    2011/03/02
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
#include "tmpm341_exb.h"
#include "tmpm341_gpio.h"


void EXB_Demo(void);

#define SRAM_RW

#ifdef SRAM_RW
#define TEST_DATA_LEN           ((uint16_t)0x0010)
#define EXB_SRAM_START_ADDR     ((uint32_t)0x60000000)
void EXB_GPIOConfig(void);
Result rw_result = ERROR;
#endif

/* The demo is for external 16-bit SRAM, multiplex bus mode */
/*int main(void)*/
void EXB_Demo(void)
{
    uint8_t chip = EXB_CS1;
    uint8_t BusMode = EXB_BUS_MULTIPLEX;        /* Address bus and data bus are multiplexed */
    uint8_t Cycle = EXB_CYCLE_NONE;

    /* Initial process demo */
#ifdef SRAM_RW
    uint32_t w_data[TEST_DATA_LEN] = { 0U };
    uint32_t r_data[TEST_DATA_LEN] = { 0U };
    uint16_t rw_cnt = 0U;
    uint32_t *addr = NULL;
    uint16_t i = 0U;
#endif

    EXB_InitTypeDef InitStruct = { 0U };

    InitStruct.AddrSpaceSize = EXB_1M_BYTE;
    InitStruct.StartAddr = 0x00;
    InitStruct.BusWidth = EXB_BUS_WIDTH_BIT_16;
    /* Set cycles time according to AC timing of SRAM datasheet,base clock: EXBCLK(fsys) */
    InitStruct.Cycles.InternalWait = EXB_INTERNAL_WAIT_2;
    InitStruct.Cycles.ReadSetupCycle = EXB_CYCLE_1;
    InitStruct.Cycles.WriteSetupCycle = EXB_CYCLE_1;
    InitStruct.Cycles.ALEWaitCycle = EXB_CYCLE_1;
    InitStruct.Cycles.ReadRecoveryCycle = EXB_CYCLE_1;
    InitStruct.Cycles.WriteRecoveryCycle = EXB_CYCLE_1;
    InitStruct.Cycles.ChipSelectRecoveryCycle = EXB_CYCLE_1;

#ifdef SRAM_RW
    EXB_GPIOConfig();
#endif

    EXB_SetBusMode(BusMode);
    EXB_SetBusCycleExtension(Cycle);
    EXB_Init(chip, &InitStruct);
    EXB_Enable(chip);

#ifdef SRAM_RW
    /* SRAM Read/Write demo */
    addr = (uint32_t *) (((uint32_t) InitStruct.StartAddr) | EXB_SRAM_START_ADDR);

    for (i = 0U; i < TEST_DATA_LEN; i++) {
        w_data[i] = i;
    }

    rw_cnt = TEST_DATA_LEN * sizeof(w_data[0]);
    memcpy(addr, w_data, (uint32_t) rw_cnt);
    __DSB();
    memcpy(r_data, addr, (uint32_t) rw_cnt);

    /* check rw_result to see if SRAM write/read is sucessful or not */
    if (memcmp(w_data, r_data, (uint32_t) rw_cnt) == 0U) {
        rw_result = SUCCESS;
    } else {
        rw_result = ERROR;
    }
#endif
    while (1) {
        /* Do nothing */
    }
}

/**
  * @brief  Configure GPIO to EXB
  * @param  None
  * @retval None
  */
void EXB_GPIOConfig(void)
{
    GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_ALL, ENABLE);
    GPIO_EnableFuncReg(GPIO_PA, GPIO_FUNC_REG_1, GPIO_PA_FR1_BIT_ALL);
    GPIO_SetInputEnableReg(GPIO_PA, GPIO_BIT_ALL, ENABLE);

    GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_ALL, ENABLE);
    GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_1, GPIO_PB_FR1_BIT_ALL);
    GPIO_SetInputEnableReg(GPIO_PB, GPIO_BIT_ALL, ENABLE);

    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_ALL, ENABLE);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_2, GPIO_PE_FR2_BIT_ALL);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_ALL, ENABLE);

    GPIO_SetOutputEnableReg(GPIO_PF, 0xFE, ENABLE);
    GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, 0xFE);
    GPIO_SetInputEnableReg(GPIO_PF, 0xFE, ENABLE);
}

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
