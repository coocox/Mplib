/**
 *******************************************************************************
 * @file    tmpm341_exb.c
 * @brief   This file provides API functions for EXB driver.
 * @version V2.0.2.1
 * @date    2011/02/15
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
#include "tmpm341_exb.h"


#if defined(__TMPM341_EXB_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup EXB 
  * @brief EXB driver modules
  * @{
  */
/** @defgroup EXB_Private_Defines
  * @{
  */
#define MODE_EXBWAIT_MASK    ((uint32_t)0x00000001)
#define EXB_CS_MASK          ((uint32_t)0x00000001)
#define EXB_AS_FIXED_BITS    ((uint32_t)0x60000000)
#define CSX_CSW_CLEAR        ((uint32_t)0xFFFFFFF1)

/** @} */
/* End of group EXB_Private_Defines */

/** @defgroup EXB_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group EXB_Private_FunctionPrototypes */

/** @defgroup EXB_Private_Functions
  * @{
  */

/** @} */
/* End of group group EXB_Private_Functions */

/** @defgroup EXB_Exported_Functions
  * @{
  */

/**
  * @brief  Set EXB bus mode
  * @param  BusMode: Select EXB mode.
  *         This parameter can be: EXB_BUS_SEPARATE or EXB_BUS_MULTIPLEX.
  * @retval None
  */
void EXB_SetBusMode(uint8_t BusMode)
{
    /* Check the parameters */
    assert_param(IS_EXB_BUS_MODE(BusMode));

    /* Set EXBMOD<EXBSEL> to select bus mode. */
    if (BusMode == EXB_BUS_SEPARATE) {
        TSB_EXB_MOD_EXBSEL = 1U;
    } else {
        TSB_EXB_MOD_EXBSEL = 0U;
    }
}

/**
  * @brief  Set the setup, wait and recovery of the bus cycle to be double or quadruple
  * @param  Cycle: Set the bus cycle to be double or quadruple.
  *         This parameter can be:
  *         EXB_CYCLE_NONE, EXB_CYCLE_DOUBLE or EXB_CYCLE_QUADRUPLE
  * @retval None
  */
void EXB_SetBusCycleExtension(uint8_t Cycle)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_EXB_BUS_CYCLE_EXTENSION(Cycle));

    tmp = TSB_EXB->MOD;
    tmp &= MODE_EXBWAIT_MASK;
    tmp |= (uint32_t) Cycle;
    /* Set EXBMOD<EXBWAIT1:0> to set bus cycle extension. */
    TSB_EXB->MOD = tmp;
}

/**
  * @brief  Enable the specified chip
  * @param  ChipSelect: Select Chip
  *         This parameter can be one of the following values:
  *         EXB_CS0, EXB_CS1
  * @retval None
  */
void EXB_Enable(uint8_t ChipSelect)
{
    /* Check the parameters */
    assert_param(IS_EXB_CHIP_SELECT(ChipSelect));

    if (ChipSelect == EXB_CS0) {
        TSB_EXB_CS0_CSW0 = 1U;
    } else {
        TSB_EXB_CS1_CSW0 = 1U;
    }
}

/**
  * @brief  Disable the specified chip
  * @param  ChipSelect: Select Chip
  *         This parameter can be one of the following values:
  *         EXB_CS0, EXB_CS1
  * @retval None
  */
void EXB_Disable(uint8_t ChipSelect)
{
    /* Check the parameters */
    assert_param(IS_EXB_CHIP_SELECT(ChipSelect));

    if (ChipSelect == EXB_CS0) {
        TSB_EXB_CS0_CSW0 = 0U;
    } else {
        TSB_EXB_CS1_CSW0 = 0U;
    }
}

/**
  * @brief  Initialize the specified chip
  * @param  ChipSelect: Select Chip
  *         This parameter can be one of the following values:
  *         EXB_CS0, EXB_CS1
  * @param  InitStruct: The structure containing basic EXB configuration.
  *         This parameter is structure pointer which consists of following members:
  *         AddrSpaceSize, StartAddr, BusWidth and Cycles
  * @retval None
  */
void EXB_Init(uint8_t ChipSelect, EXB_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_EXB_CHIP_SELECT(ChipSelect));
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_EXB_ADDR_SPACE_SIZE(InitStruct->AddrSpaceSize));
    assert_param(IS_EXB_DATA_BUS_WIDTH(InitStruct->BusWidth));
    assert_param(IS_EXB_INTERNAL_WAIT(InitStruct->Cycles.InternalWait));
    assert_param(IS_EXB_RW_SETUP_CYCLE(InitStruct->Cycles.ReadSetupCycle));
    assert_param(IS_EXB_RW_SETUP_CYCLE(InitStruct->Cycles.WriteSetupCycle));
    assert_param(IS_EXB_ALE_WAIT_CYCLE(InitStruct->Cycles.ALEWaitCycle));
    assert_param(IS_EXB_RW_RECOVERY_CYCLE(InitStruct->Cycles.ReadRecoveryCycle));
    assert_param(IS_EXB_RW_RECOVERY_CYCLE(InitStruct->Cycles.WriteRecoveryCycle));
    assert_param(IS_EXB_CS_RECOVERY_CYCLE(InitStruct->Cycles.ChipSelectRecoveryCycle));

    tmp |= (uint32_t) InitStruct->AddrSpaceSize | ((uint32_t) InitStruct->StartAddr << 16U);
    tmp |= EXB_AS_FIXED_BITS;

    /* Initialize EXB ASx register */
    if (ChipSelect == EXB_CS0) {
        TSB_EXB->AS0 = tmp;
    } else {
        TSB_EXB->AS1 = tmp;
    }

    tmp = ((uint32_t) InitStruct->Cycles.InternalWait << 8U) |
        ((uint32_t) InitStruct->Cycles.ReadRecoveryCycle << 24U) |
        ((uint32_t) InitStruct->Cycles.WriteRecoveryCycle << 27U);
    tmp |= (InitStruct->Cycles.ReadSetupCycle == EXB_CYCLE_4) ?
        ((uint32_t) (InitStruct->Cycles.ReadSetupCycle - 1UL) << 16U) :
        ((uint32_t) InitStruct->Cycles.ReadSetupCycle << 16U);
    tmp |= (InitStruct->Cycles.WriteSetupCycle == EXB_CYCLE_4) ?
        ((uint32_t) (InitStruct->Cycles.WriteSetupCycle - 1UL) << 18U) :
        ((uint32_t) InitStruct->Cycles.WriteSetupCycle << 18U);

    if (TSB_EXB_MOD_EXBSEL == 0U) {
        /* Set ALE wait cycle for multiplex bus */
        tmp |= (InitStruct->Cycles.ALEWaitCycle == EXB_CYCLE_4) ?
            ((uint32_t) (InitStruct->Cycles.ALEWaitCycle - 1UL) << 20U) :
            ((uint32_t) InitStruct->Cycles.ALEWaitCycle << 20U);
    } else {
        /* No need ALE wait cycle for separate bus */
        InitStruct->Cycles.ALEWaitCycle = EXB_CYCLE_0;
        tmp |= (uint32_t) InitStruct->Cycles.ALEWaitCycle << 20U;
    }

    tmp |= (InitStruct->Cycles.ChipSelectRecoveryCycle == EXB_CYCLE_4) ?
        ((uint32_t) (InitStruct->Cycles.ChipSelectRecoveryCycle - 1UL) << 30U) :
        ((uint32_t) InitStruct->Cycles.ChipSelectRecoveryCycle << 30U);
    tmp |= (uint32_t) InitStruct->BusWidth;

    /* Initialize EXB CSx register */
    if (ChipSelect == EXB_CS0) {
        TSB_EXB->CS0 = tmp;
    } else {
        TSB_EXB->CS1 = tmp;
    }
}

/** @} */
/* End of group EXB_Exported_Functions */

/** @} */
/* End of group EXB */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM341_EXB_H) */
