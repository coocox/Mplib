/**
 *******************************************************************************
 * @file    tmpm364_smc.c
 * @brief   This file provides API functions for SMC driver.
 * @version V2.2.0
 * @date    2011/02/21
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm364_smc.h"

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup SMC 
  * @brief SMC driver modules
  * @{
  */

/** @defgroup SMC_Private_Defines
  * @{
  */

/* smc_memif_cfg (SMC Memory Interface Configuration Register) */
typedef union {
    uint32_t Data;
    struct {
        uint32_t MemoryType:2;
        uint32_t MemoryChips:2;
        uint32_t MemoryWidth:2;
        uint32_t Reserved:26;
    } Bit;
} IFConfig_Reg;

/* smc_set_cycles (SMC Set Cycles Register) */
/* smc_sram_cycles0_n (SMC SRAM Cycles Registers 0 <n=0,1,2,3>) */
typedef union {
    uint32_t Data;
    struct {
        uint32_t RC_Time:4;
        uint32_t WC_Time:4;
        uint32_t CEOE_Time:3;
        uint32_t WP_Time:3;
        uint32_t PC_Time:3;
        uint32_t TR_Time:3;
        uint32_t Reserved:12;
    } Bit;
} Cycles_Reg;

/* smc_set_opmode (SMC Set Opmode Register) */
/* smc_opmode0_n (SMC Opmode Registers 0 <n=0,1,2,3>) */
typedef union {
    uint32_t Data;
    struct {
        uint32_t BusWidth:2;
        uint32_t Reserved0:1;
        uint32_t ReadBurstLen:3;
        uint32_t Reserved1:5;
        uint32_t ALE:1;
        uint32_t Reserved2:12;
        uint32_t StartAddr:8;   /* For smc_opmode0_n <n=0,1,2,3> */
    } Bit;
} OpMode_Reg;

/* smc_direct_cmd (SMC Direct Command Register) */
typedef union {
    uint32_t Data;
    struct {
        uint32_t Reserved0:21;
        uint32_t CmdType:2;
        uint32_t ChipSelect:3;
        uint32_t Reserved1:6;
    } Bit;
} DirectCMD_Reg;

/** @} */
/* End of group SMC_Private_Defines */

/** @defgroup SMC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group SMC_Private_FunctionPrototypes */

/** @defgroup SMC_Private_Functions
  * @{
  */

/** @} */
/* End of group SMC_Private_Functions */

/** @defgroup SMC_Exported_Functions
  * @{
  */

/**
  * @brief  Set SMC bus mode.
  * @param  BusMode: Select SMC mode.
  *   This parameter can be:         
  *     For M361/3: SMC_BUS_MULTIPLEX.
  *     For M360/2/4: SMC_BUS_SEPARATE, SMC_BUS_MULTIPLEX.
  * @retval None
  */
void SMC_SetBusMode(uint8_t BusMode)
{
    /* Check the parameters */
    assert_param(IS_SMC_BUS_MODE(BusMode));

    /* Set SMCMDMODE<IFSMCMUXMD> to select bus mode. */
    TSB_SMCMD->MODE = (uint32_t) BusMode;
}

/**
  * @brief  Read SMC memory interface configuration.
  * @param  Config: Interface configuration returned by the function.
  *   This parameter is structure pointer which consists of following members:
  *   MemoryType, MemoryChips, MemoryWidth.
  * @retval None
  */
void SMC_GetIFConfig(SMC_IFConfigTypeDef * Config)
{
    IFConfig_Reg cfg = { 0U };

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(Config));

    cfg.Data = TSB_SMC->MEMIF_CFG;
    Config->MemoryType = (uint8_t) cfg.Bit.MemoryType;
    Config->MemoryChips = (uint8_t) cfg.Bit.MemoryChips;
    Config->MemoryWidth = (uint8_t) cfg.Bit.MemoryWidth;
}

/**
  * @brief  Send direct command to static memory to update registers(opmode, cycles)
  * @param  Cmd: Command type and specified memory.
  *   This parameter is structure pointer which consists of following members:
  *   CmdType, ChipSelect.
  * @retval None
  */
void SMC_SendDirectCMD(SMC_DirectCMDTypeDef * Cmd)
{
    DirectCMD_Reg command = { 0U };

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(Cmd));
    assert_param(IS_SMC_CHIP_SELECT(Cmd->ChipSelect));
    assert_param(IS_SMC_CMD(Cmd->CmdType));

    command.Bit.CmdType = Cmd->CmdType;
    command.Bit.ChipSelect = Cmd->ChipSelect;
    TSB_SMC->DIRECT_CMD = command.Data;
}

/**
  * @brief  Adjust the access cycle of static memory and should be set to satisfy
  *         the A.C. specifications of the memory to be used.
  * @param  Cycles: Static memory access cycles.
  *   This parameter is structure pointer which consists of following members:
  *   RC_Time, WC_Time, WP_Time, CEOE_Time, PC_Time, TR_Time.
  * @retval None
  */
void SMC_SetCycles(SMC_CyclesTypeDef * Cycles)
{
    Cycles_Reg set_cycles = { 0U };

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(Cycles));
    assert_param(IS_SMC_READ_CYCLE_TIME(Cycles->RC_Time));
    assert_param(IS_SMC_WRITE_CYCLE_TIME(Cycles->WC_Time));
    assert_param(IS_SMC_CEOE_DELAY_CYCLE_TIME(Cycles->CEOE_Time));
    assert_param(IS_SMC_WE_PULSE_CYCLE_TIME(Cycles->WP_Time));
    assert_param(IS_SMC_PAGE_CYCLE_TIME(Cycles->PC_Time));
    assert_param(IS_SMC_TURN_AROUND_CYCLE_TIME(Cycles->TR_Time));

    set_cycles.Bit.RC_Time = Cycles->RC_Time;
    set_cycles.Bit.WC_Time = Cycles->WC_Time;
    set_cycles.Bit.CEOE_Time = Cycles->CEOE_Time;
    set_cycles.Bit.WP_Time = Cycles->WP_Time;
    set_cycles.Bit.PC_Time = Cycles->PC_Time;
    set_cycles.Bit.TR_Time = Cycles->TR_Time;
    TSB_SMC->SET_CYCLES = set_cycles.Data;
}

/**
  * @brief  Set opmode of static memory.
  * @param  OpMode: Static memory opmode.
  *   This parameter is structure pointer which consists of following members:
  *   BusWidth, ReadBurstLen, ALE.
  * @retval None
  */
void SMC_SetOpMode(SMC_OpModeTypeDef * OpMode)
{
    OpMode_Reg set_opmode = { 0U };

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(OpMode));
    assert_param(IS_SMC_DATA_BUS(OpMode->BusWidth));
    assert_param(IS_SMC_READ_BURST(OpMode->ReadBurstLen));
    assert_param(IS_FUNCTIONAL_STATE(OpMode->ALE));

    set_opmode.Bit.BusWidth = OpMode->BusWidth;
    set_opmode.Bit.ReadBurstLen = OpMode->ReadBurstLen;
    if (OpMode->ALE == ENABLE) {
        set_opmode.Bit.ALE = 1U;
    } else {
        set_opmode.Bit.ALE = 0U;
    }
    TSB_SMC->SET_OPMODE = set_opmode.Data;
}

/**
  * @brief  Get the access cycles of specified memory.
  * @param  ChipSelect: Select Chip.
  *   This parameter can be one of the following values:
  *   SMC_CS0, SMC_CS1, SMC_CS2, SMC_CS3.
  * @param  Cycles: Static memory access cycles returned by the function.
  *   This parameter is structure pointer which consists of following members:
  *   RC_Time, WC_Time, WP_Time, CEOE_Time, PC_Time, TR_Time.
  * @retval None
  */
void SMC_GetCycles(uint8_t ChipSelect, SMC_CyclesTypeDef * Cycles)
{
    Cycles_Reg get_cycles = { 0U };

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(Cycles));
    assert_param(IS_SMC_CHIP_SELECT(ChipSelect));

    switch (ChipSelect) {
    case SMC_CS0:
        get_cycles.Data = TSB_SMC->SRAM_CYCLES0_0;
        break;
    case SMC_CS1:
        get_cycles.Data = TSB_SMC->SRAM_CYCLES0_1;
        break;
    case SMC_CS2:
        get_cycles.Data = TSB_SMC->SRAM_CYCLES0_2;
        break;
    case SMC_CS3:
        get_cycles.Data = TSB_SMC->SRAM_CYCLES0_3;
        break;
    default:
        /* Do nothing */
        break;
    }
    Cycles->RC_Time = (uint8_t) get_cycles.Bit.RC_Time;
    Cycles->WC_Time = (uint8_t) get_cycles.Bit.WC_Time;
    Cycles->CEOE_Time = (uint8_t) get_cycles.Bit.CEOE_Time;
    Cycles->WP_Time = (uint8_t) get_cycles.Bit.WP_Time;
    Cycles->PC_Time = (uint8_t) get_cycles.Bit.PC_Time;
    Cycles->TR_Time = (uint8_t) get_cycles.Bit.TR_Time;
}

/**
  * @brief  Get opmode of static memory.
  * @param  ChipSelect: Select Chip.
  *   This parameter can be one of the following values:
  *   SMC_CS0, SMC_CS1, SMC_CS2, SMC_CS3.
  * @param  OpMode: Static memory opmode returned by the function.
  *   This parameter is structure pointer which consists of following members:
  *   BusWidth, ReadBurstLen, ALE, StartAddr.
  * @retval None
  */
void SMC_GetOpMode(uint8_t ChipSelect, SMC_OpModeTypeDef * OpMode)
{
    OpMode_Reg get_opmode = { 0U };
    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(OpMode));
    assert_param(IS_SMC_CHIP_SELECT(ChipSelect));

    switch (ChipSelect) {
    case SMC_CS0:
        get_opmode.Data = TSB_SMC->OPMODE0_0;
        break;
    case SMC_CS1:
        get_opmode.Data = TSB_SMC->OPMODE0_1;
        break;
    case SMC_CS2:
        get_opmode.Data = TSB_SMC->OPMODE0_2;
        break;
    case SMC_CS3:
        get_opmode.Data = TSB_SMC->OPMODE0_3;
        break;
    default:
        /* Do nothing */
        break;
    }
    OpMode->BusWidth = (uint8_t) get_opmode.Bit.BusWidth;
    OpMode->ReadBurstLen = (uint8_t) get_opmode.Bit.ReadBurstLen;
    if (get_opmode.Bit.ALE == 1U) {
        OpMode->ALE = ENABLE;
    } else {
        OpMode->ALE = DISABLE;
    }
    OpMode->StartAddr = (uint8_t) get_opmode.Bit.StartAddr;
}

/** @} */
/* End of group SMC_Exported_Functions */

/** @} */
/* End of group SMC */

/** @} */
/* End of group TX03_Periph_Driver */
