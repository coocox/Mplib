/**
 *******************************************************************************
 * @file    tmpm061_tmr16a.c
 * @brief   This file provides API functions for TMR16A driver.
 * @version V2.0.2.2
 * @date    2013/03/21
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm061_tmr16a.h"

#if defined(__TMPM061_TMR16A_H)
/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @defgroup TMR16A
  * @brief TMR16A driver modules
  * @{
  */

/** @defgroup TMR16A_Private_Defines
  * @{
  */
#define CR_UCCR_SET         ((uint32_t)0x00008000)
#define CR_CLK_SYSCK        ((uint32_t)0xFFFFFFFE)
#define CR_CLK_PRCK         ((uint32_t)0x00000001)
#define CR_FF_MASK          ((uint32_t)0xFFFFFF4F)

#define EN_I2T16A_SET       ((uint32_t)0x00000001)
#define EN_I2T16A_CLEAR     ((uint32_t)0xFFFFFFFE)

#define CP_CP_CLEAR         ((uint32_t)0xFFFF0000)
/** @} */
/* End of group TMR16A_Private_Defines */

/** @defgroup TMR16A_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group TMR16A_Private_FunctionPrototypes */

/** @defgroup TMR16A_Private_Functions
  * @{
  */

/** @} */
/* End of group TMR16A_Private_Functions */

/** @defgroup TMR16A_Exported_Functions
  * @{
  */

/**
  * @brief  Start or stop counter of the specified TMR16A channel.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param  Cmd: The command for the counter.
  *   This parameter can be TMR16A_RUN or TMR16A_STOP.
  * @retval None
  */
void TMR16A_SetRunState(TSB_T16A_TypeDef * T16Ax, uint32_t Cmd)
{
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_TMR16A_CMD(Cmd));

    /* Write command into RUN register */
    T16Ax->RUN = Cmd;
}

/**
  * @brief  Start or stop counter of the specified TMR16A channel.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param  SrcClk: The command for the counter.
  *   This parameter can be TMR16A_SYSCK or TMR16A_PRCK.
  * @retval None
  */
void TMR16A_SetSrcClk(TSB_T16A_TypeDef * T16Ax, uint32_t SrcClk)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_TMR16A_SRCCLK(SrcClk));

    /* Set T16AxCR<UCCR> to 1 */
    tmp = T16Ax->CR;
    tmp |= CR_UCCR_SET;
    /* Write Sorce clock into  register */
    if (SrcClk == TMR16A_PRCK) {
        /* Set T16AxCR<CLK>  Source clock to PRCK */
        tmp |= CR_CLK_PRCK;
    } else {
        /* Clear T16AxCR<CLK> Source clock to SYSCK */
        tmp &= CR_CLK_SYSCK;
    }
    T16Ax->CR = tmp;
}

/**
  * @brief  Configure the flip-flop function.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param FFStruct: The structure containing TMR16A flip-flop configuration
  * @retval None
  */
void TMR16A_SetFlipFlop(TSB_T16A_TypeDef * T16Ax, TMR16A_FFOutputTypeDef * FFStruct)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(FFStruct));
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_TMR16A_FLIPFLOP_CTRL(FFStruct->TMR16AFlipflopCtrl));
    assert_param(IS_TMR16A_FLIPFLOP_TRG(FFStruct->TMR16AFlipflopReverseTrg));

    /* Configure the flip-flop function of T16Ax */
    tmp = T16Ax->CR;
    tmp &= CR_FF_MASK;
    tmp |= (FFStruct->TMR16AFlipflopCtrl | FFStruct->TMR16AFlipflopReverseTrg);
    T16Ax->CR = tmp;
}

/**
  * @brief  Change cycle value of T16Ax.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param  Cycle: New cycle value, max 0xFFFF.
  * @retval None
  */
void TMR16A_ChangeCycle(TSB_T16A_TypeDef * T16Ax, uint32_t Cycle)
{
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_TMR16A_VALUE(Cycle));

    /* Write cycle into RG1 */
    T16Ax->RG = Cycle;
}

/**
  * @brief  Get TMR16A capture value of T16Ax.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @retval Capture value of T16Ax
  */
uint16_t TMR16A_GetCaptureValue(TSB_T16A_TypeDef * T16Ax)
{
    uint16_t CapVal;

    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));

    CapVal = (uint16_t)T16Ax->CP;

    return CapVal;
}

/**
  * @brief  Clear TMR16A capture value of T16Ax.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @retval None
  */
void TMR16A_ClrCaptureValue(TSB_T16A_TypeDef * T16Ax)
{
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));

    /* Clear the capture */
    T16Ax->CP &= CP_CP_CLEAR;
}

/**
  * @brief  Enable or disable TMR16A when system is in idle mode.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param  NewState: New state of TMR16A in system idle mode.
  *   This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void TMR16A_SetIdleMode(TSB_T16A_TypeDef * T16Ax, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set T16AxCR<I2T16A> to enable T16Ax in system idle mode */
        T16Ax->EN |= EN_I2T16A_SET;
    } else {
        /* Clear T16AxCR<I2T16A> to disable T16Ax in system idle mode */
        T16Ax->EN &= EN_I2T16A_CLEAR;
    }
}

/**
  * @brief  Enable or disable clock operation during debug HALT.
  * @param  T16Ax: Select the TMR16A channel.
  *   This parameter can be one of the following values:
  *   TSB_T16A0, TSB_T16A1, TSB_T16A2, TSB_T16A3, TSB_T16A4, TSB_T16A5, TSB_T16A6.
  * @param  ClkState: Timer state in HALT mode.
  *   This parameter can be TMR16A_RUNNING_IN_CORE_HALT or TMR16A_STOP_IN_CORE_HALT.
  * @retval None
  */
void TMR16A_SetClkInCoreHalt(TSB_T16A_TypeDef * T16Ax, uint8_t ClkState)
{
    /* Check the parameters */
    assert_param(IS_TMR16A_ALL_PERIPH(T16Ax));
    assert_param(IS_TMR16A_CLK_IN_CORE_HALT(ClkState));

    if (ClkState == TMR16A_STOP_IN_CORE_HALT) {
        /* Set T16AEN<T16AHALT> */
        T16Ax->EN |= (uint32_t) TMR16A_STOP_IN_CORE_HALT;
    } else {
        /* Clear T16AEN<T16AHALT> */
        T16Ax->EN &= ~(uint32_t) TMR16A_STOP_IN_CORE_HALT;
    }
}

/** @} */
/* End of group TMR16A_Exported_Functions */

/** @} */
/* End of group TMR16A */

/** @} */
/* End of group TX00_Periph_Driver */

#endif                          /* defined(__TMPM061_TMR16A_H) */
