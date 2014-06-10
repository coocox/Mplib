/**
 *******************************************************************************
 * @file    tmpm341_tmrd.c
 * @brief   This file provides API functions for TMRD driver.
 * @version V2.0.2.1
 * @date    2011/02/28
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
#include "tmpm341_tmrd.h"

#if defined(__TMPM341_TMRD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup TMRD
  * @brief TMRD driver modules
  * @{
  */

/** @defgroup TMRD_Private_Defines
  * @{
  */

#define EN_TDEN1_SET          (0x00000080UL)
#define EN_TDEN1_CLEAR        (0xFFFFFF7FUL)
#define EN_TDEN0_SET          (0x00000040UL)
#define EN_TDEN0_CLEAR        (0xFFFFFFBFUL)
#define EN_TDHALT_SET         (0x00000020UL)
#define EN_TDHALT_CLEAR       (0xFFFFFFDFUL)
#define CONF_TDI2TD1_SET      (0x00000080UL)
#define CONF_TDI2TD1_CLEAR    (0xFFFFFF7FUL)
#define CONF_TDI2TD0_SET      (0x00000040UL)
#define CONF_TDI2TD0_CLEAR    (0xFFFFFFBFUL)
#define CONF_TMRDMOD_MASK     (0xFFFFFFF8UL)
#define MOD_TDIV1_SET         (0x00000080UL)
#define MOD_TDIV1_CLEAR       (0xFFFFFF7FUL)
#define MOD_TDIV0_SET         (0x00000040UL)
#define MOD_TDIV0_CLEAR       (0xFFFFFFBFUL)
#define MOD_TDCLE_SET         (0x00000010UL)
#define MOD_TDCLE_CLEAR       (0xFFFFFFEFUL)
#define MOD_TDCLK_MASK        (0xFFFFFFF0UL)
#define CR_TDRDE_SET          (0x00000004UL)
#define CR_TDRDE_CLEAR        (0xFFFFFFFBUL)
#define CR_TDISO_MASK         (0xFFFFFFFCUL)
#define RUN_TDRUN_SET         (0x00000001UL)
#define RUN_TDRUN_CLEAR       (0x00000000UL)
#define BCR_PHSCHG_SET        (0x00000002UL)
#define BCR_PHSCHG_CLEAR      (0x00000000UL)
#define BCR_TDSFT_SET         (0x00000001UL)
#define DMA_DMAEN_SET         (0x00000001UL)
#define DMA_DMAEN_CLEAR       (0x00000000UL)

/** @} */
/* End of group TMRD_Private_Defines */

/** @defgroup TMRD_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group TMRD_Private_FunctionPrototypes */

/** @defgroup TMRD_Private_Functions
  * @{
  */

/** @} */
/* End of group TMRD_Private_Functions */

/** @defgroup TMRD_Exported_Functions
  * @{
  */

/**
  * @brief  Enable clock signal input to TMRD.
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @retval None
  */
void TMRD_Enable(TSB_TD_TypeDef * TDx)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));

    /* Set TD0EN<TDEN0, TDEN1> */
    TSB_TD0->EN |= (TDx == TSB_TD0) ? (EN_TDEN0_SET) : (EN_TDEN1_SET);
}

/**
  * @brief  Disable clock signal input to TMRD.
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @retval None
  */
void TMRD_Disable(TSB_TD_TypeDef * TDx)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));

    /* Clear TD0EN<TDEN0, TDEN1> */
    TSB_TD0->EN &= (TDx == TSB_TD0) ? (EN_TDEN0_CLEAR) : (EN_TDEN1_CLEAR);
}

/**
  * @brief  Set TMRD operation if a HALT instruction is 
  *   executed during debugging.
  * @param  RunState: TMRD operation status setting.
  *   This parameter can be one of the following values:
  *   TMRD_RUN, TMRD_STOP.
  * @retval None
  */
void TMRD_SetRunStateInHalt(uint8_t RunState)
{
    /* Check the parameters */
    assert_param(IS_TMRD_RUN_STATE(RunState));

    /* Set TD0EN<TDHALT> */
    TSB_TD0->EN = (RunState == TMRD_RUN) ? (TSB_TD0->EN | EN_TDHALT_SET) :
        (TSB_TD0->EN & EN_TDHALT_CLEAR);
}

/**
  * @brief  Set TMRD operation during the IDLE mode. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  RunState: TMRD operation status setting.
  *   This parameter can be one of the following values:
  *   TMRD_RUN, TMRD_STOP.
  * @retval None
  */
void TMRD_SetRunStateInIdle(TSB_TD_TypeDef * TDx, uint8_t RunState)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_TMRD_RUN_STATE(RunState));

    /* Set TD0CONF<TDI2TD0, TDI2TD1> */
    if (RunState == TMRD_RUN) {
        TSB_TD0->CONF |= (TDx == TSB_TD0) ? (CONF_TDI2TD0_SET) : (CONF_TDI2TD1_SET);
    } else {
        TSB_TD0->CONF &= (TDx == TSB_TD0) ? (CONF_TDI2TD0_CLEAR) : (CONF_TDI2TD1_CLEAR);
    }
}

/**
  * @brief  Set the operation mode for TMRD0 and TMRD1. 
  * @param  Mode: Operation mode of TMRD.
  *   This parameter can be one of the following values:
  *   TMRD_MODE_BOTH_TMR, TMRD_MODE_0TMR_1PPG, 
  *   TMRD_MODE_0PPG_1TMR, TMRD_MODE_BOTH_PPG, 
  *   TMRD_MODE_INTERLOCK_TMR, TMRD_MODE_INTERLOCK_PPG.
  * @retval None
  */
void TMRD_SetMode(uint8_t Mode)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_TMRD_MODE(Mode));

    /* Set TD0CONF<TMRDMOD> */
    tmp = TSB_TD0->CONF & CONF_TMRDMOD_MASK;
    tmp |= Mode;
    TSB_TD0->CONF = tmp;
}

/**
  * @brief  Set the clock prescaler of TMRD0 and TMRD1. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  ClkDiv: Clock prescaler factor.
  *   This parameter can be one of the following values:
  *   TMRD_CLK_DIV_1, TMRD_CLK_DIV_2, TMRD_CLK_DIV_4, 
  *   TMRD_CLK_DIV_8, TMRD_CLK_DIV_16.
  * @retval None
  */
void TMRD_SetClkDivision(TSB_TD_TypeDef * TDx, uint8_t ClkDiv)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_TMRD_CLK_DIV(ClkDiv));

    /* Set TDxMOD<TDCLK> */
    tmp = TDx->MOD & MOD_TDCLK_MASK;
    tmp |= ClkDiv;
    TDx->MOD = tmp;
}

/**
  * @brief  Select the timer upcounter operation when match the cycle. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  UpCntCtrl: Up counter clear operation mode.
  *   This parameter can be one of the following values:
  *   TMRD_FREE_RUN, TMRD_AUTO_CLEAR. 
  * @retval None
  */
void TMRD_SetUpCntCtrl(TSB_TD_TypeDef * TDx, uint8_t UpCntCtrl)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_TMRD_UC_CTRL(UpCntCtrl));

    /* Set TDxMOD<TDCLE> */
    TDx->MOD = (UpCntCtrl == TMRD_AUTO_CLEAR) ? (TDx->MOD | MOD_TDCLE_SET) :
        (TDx->MOD & MOD_TDCLE_CLEAR);
}

/**
  * @brief  Set the initial leading/trailing edge of PPG channels.
  * @param  PPGChannel: PPG output channel.
  *   This parameter can be one of the following values:
  *   TMRD_PPG_CHANNEL_A0, TMRD_PPG_CHANNEL_A1, 
  *   TMRD_PPG_CHANNEL_B0, TMRD_PPG_CHANNEL_B1.
  * @param  WaveEdge: Wave edge of signal.
  *   This parameter can be one of the following values:
  *   TMRD_WAVE_EDGE_RISING, TMRD_WAVE_EDGE_FALLING. 
  * @retval None
  */
void TMRD_SetPPGInitLeadingEdge(uint8_t PPGChannel, uint8_t WaveEdge)
{
    /* Check the parameters */
    assert_param(IS_TMRD_PPG_CHANNEL(PPGChannel));
    assert_param(IS_TMRD_WAVE_EDGE(WaveEdge));

    /* Set TDxMOD<TDIV0, TDIV1> */
    switch (PPGChannel) {
    case TMRD_PPG_CHANNEL_A0:
        TSB_TD0->MOD = (WaveEdge == TMRD_WAVE_EDGE_FALLING) ? (TSB_TD0->MOD | MOD_TDIV0_SET) :
            (TSB_TD0->MOD & MOD_TDIV0_CLEAR);
        break;
    case TMRD_PPG_CHANNEL_A1:
        TSB_TD0->MOD = (WaveEdge == TMRD_WAVE_EDGE_FALLING) ? (TSB_TD0->MOD | MOD_TDIV1_SET) :
            (TSB_TD0->MOD & MOD_TDIV1_CLEAR);
        break;
    case TMRD_PPG_CHANNEL_B0:
        TSB_TD1->MOD = (WaveEdge == TMRD_WAVE_EDGE_FALLING) ? (TSB_TD1->MOD | MOD_TDIV0_SET) :
            (TSB_TD1->MOD & MOD_TDIV0_CLEAR);
        break;
    case TMRD_PPG_CHANNEL_B1:
        TSB_TD1->MOD = (WaveEdge == TMRD_WAVE_EDGE_FALLING) ? (TSB_TD1->MOD | MOD_TDIV1_SET) :
            (TSB_TD1->MOD & MOD_TDIV1_CLEAR);
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set a write path to the compare register. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  WritePath: The path to update compare register.
  *   This parameter can be one of the following values:
  *   TMRD_CMP_WRITE_DIRECT, TMRD_CMP_WRITE_INDIRECT. 
  * @retval None
  */
void TMRD_SetCMPRegWritePath(TSB_TD_TypeDef * TDx, uint8_t WritePath)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_TMRD_CMP_WRITE_PATH(WritePath));

    /* Set TDxCR<TDRDE> */
    TDx->CR = (WritePath == TMRD_CMP_WRITE_INDIRECT) ? (TDx->CR | CR_TDRDE_SET) :
        (TDx->CR & CR_TDRDE_CLEAR);
}

/**
  * @brief  Set the interrupt source of compare interrupt 0. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  INTSrc: Select the interrupt factor.
  *   This parameter can be one of the following values:
  *   TMRD_INT_NONE, TMRD_INT_MATCH_CYCLE, 
  *   TMRD_INT_MATCH_PHASE (only TMRD0 has), TMRD_INT_UC_OVERFLOW. 
  * @retval None
  */
void TMRD_SetCMP0INTSrc(TSB_TD_TypeDef * TDx, uint8_t INTSrc)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    if (TDx == TSB_TD0) {
        assert_param(IS_TMRD_TD0_INT_SRC(INTSrc));
    } else {
        assert_param(IS_TMRD_TD1_INT_SRC(INTSrc));
    }

    /* Set TDxCR<TDISO> */
    tmp = TDx->CR & CR_TDISO_MASK;
    tmp |= INTSrc;
    TDx->CR = tmp;
}

/**
  * @brief  Set the count operation of TMRD. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  RunState: The counter operation of TMRD.
  *   This parameter can be one of the following values:
  *   TMRD_RUN, TMRD_STOP. 
  * @retval None
  */
void TMRD_SetRunState(TSB_TD_TypeDef * TDx, uint8_t RunState)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_TMRD_RUN_STATE(RunState));

    /* Set TDxRUN<TDRUN> */
    TDx->RUN = (RunState == TMRD_RUN) ? (RUN_TDRUN_SET) : (RUN_TDRUN_CLEAR);
}

/**
  * @brief  Set the phase relation of phase B to phase A. 
  * @param  PhaseRelation: The phase relation of phase B to the phase A.
  *   This parameter can be one of the following values:
  *   TMRD_PHASE_DELAY_OR_SAME, TMRD_PHASE_FAST_OR_SAME.
  * @retval None
  */
void TMRD_SetPhaseRelation(uint8_t PhaseRelation)
{
    /* Check the parameters */
    assert_param(IS_TMRD_PHASE_RELATION(PhaseRelation));

    /* Set TD0BCR<PHSCHG> */
    TSB_TD0->BCR = (PhaseRelation == TMRD_PHASE_FAST_OR_SAME) ? (BCR_PHSCHG_SET) :
        (BCR_PHSCHG_CLEAR);
}

/**
  * @brief  Enable to update the compare register. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1. 
  * @retval None
  */
void TMRD_EnableUpdateCMPReg(TSB_TD_TypeDef * TDx)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));

    /* Set TDxBCR<TDSFT> */
    TDx->BCR = (TDx == TSB_TD0) ? (TSB_TD0->BCR | BCR_TDSFT_SET) : (BCR_TDSFT_SET);
}

/**
  * @brief  Enable or disable the DMA request of INTTDxCMP0 signal. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  NewState: The state of DMA request.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE. 
  * @retval None
  */
void TMRD_SetDMAReq(TSB_TD_TypeDef * TDx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Set TDxDMA<DMAEN> */
    TDx->DMA = (NewState == ENABLE) ? (DMA_DMAEN_SET) : (DMA_DMAEN_CLEAR);
}

/**
  * @brief  Initialize TMRD timing parameters. 
  * @param  TDx: Select the TMRD channel.
  *   This parameter can be one of the following values:
  *   TSB_TD0, TSB_TD1.
  * @param  TimingStruct: The pointer of TMRD timing 
  *   parameters structure.
  * @retval None
  */
void TMRD_SetInitTiming(TSB_TD_TypeDef * TDx, TMRD_TimingTypeDef * TimingStruct)
{
    /* Check the parameters */
    assert_param(IS_TMRD_ALL_PERIPH(TDx));
    assert_param(IS_POINTER_NOT_NULL(TimingStruct));

    /* Set TDxRGm */
    TDx->RG0 = TimingStruct->Cycle;
    TDx->RG1 = TimingStruct->LeadingTiming0;
    TDx->RG2 = TimingStruct->TrailingTiming0;
    TDx->RG3 = TimingStruct->LeadingTiming1;
    TDx->RG4 = TimingStruct->TrailingTiming1;

    if (TDx == TSB_TD0) {
        TSB_TD0->RG5 = TimingStruct->PhaseShiftTiming;
    } else {
        /* Do nothing */
    }
}

/**
  * @brief  Change the specified TMRD timing value. 
  * @param  TimingType: Timing parameters type.
  *   This parameter can be one of the following values:
  *   TMRD_TIMING_TD0_CYCLE, TMRD_TIMING_A0_LEADING, 
  *   TMRD_TIMING_A0_TRAILING, TMRD_TIMING_A1_LEADING, 
  *   TMRD_TIMING_A1_TRAILING, TMRD_TIMING_PHASE_SHIFT, 
  *   TMRD_TIMING_TD1_CYCLE, TMRD_TIMING_B0_LEADING, 
  *   TMRD_TIMING_B0_TRAILING, TMRD_TIMING_B1_LEADING, 
  *   TMRD_TIMING_B1_TRAILING.
  * @param  Timing: 16bits timing value.
  * @retval None
  */
void TMRD_ChangeTiming(uint8_t TimingType, uint16_t Timing)
{
    /* Check the parameters */
    assert_param(IS_TMRD_TIMING_TYPE(TimingType));

    /* Set TDxRGm */
    switch (TimingType) {
    case TMRD_TIMING_TD0_CYCLE:
        TSB_TD0->RG0 = Timing;
        break;
    case TMRD_TIMING_A0_LEADING:
        TSB_TD0->RG1 = Timing;
        break;
    case TMRD_TIMING_A0_TRAILING:
        TSB_TD0->RG2 = Timing;
        break;
    case TMRD_TIMING_A1_LEADING:
        TSB_TD0->RG3 = Timing;
        break;
    case TMRD_TIMING_A1_TRAILING:
        TSB_TD0->RG4 = Timing;
        break;
    case TMRD_TIMING_PHASE_SHIFT:
        TSB_TD0->RG5 = Timing;
        break;
    case TMRD_TIMING_TD1_CYCLE:
        TSB_TD1->RG0 = Timing;
        break;
    case TMRD_TIMING_B0_LEADING:
        TSB_TD1->RG1 = Timing;
        break;
    case TMRD_TIMING_B0_TRAILING:
        TSB_TD1->RG2 = Timing;
        break;
    case TMRD_TIMING_B1_LEADING:
        TSB_TD1->RG3 = Timing;
        break;
    case TMRD_TIMING_B1_TRAILING:
        TSB_TD1->RG4 = Timing;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Get the specified TMRD timing value. 
  * @param  TimingType: Timing parameters type.
  *   This parameter can be one of the following values:
  *   TMRD_TIMING_TD0_CYCLE, TMRD_TIMING_A0_LEADING, 
  *   TMRD_TIMING_A0_TRAILING, TMRD_TIMING_A1_LEADING, 
  *   TMRD_TIMING_A1_TRAILING, TMRD_TIMING_PHASE_SHIFT, 
  *   TMRD_TIMING_TD1_CYCLE, TMRD_TIMING_B0_LEADING, 
  *   TMRD_TIMING_B0_TRAILING, TMRD_TIMING_B1_LEADING, 
  *   TMRD_TIMING_B1_TRAILING.
  * @retval Specified TMRD compare register timing.
  */
uint16_t TMRD_GetTiming(uint8_t TimingType)
{
    uint16_t retval = 0U;
    /* Check the parameters */
    assert_param(IS_TMRD_TIMING_TYPE(TimingType));

    /* Get TDxRGm */
    switch (TimingType) {
    case TMRD_TIMING_TD0_CYCLE:
        retval = (uint16_t) TSB_TD0->CP0;
        break;
    case TMRD_TIMING_A0_LEADING:
        retval = (uint16_t) TSB_TD0->CP1;
        break;
    case TMRD_TIMING_A0_TRAILING:
        retval = (uint16_t) TSB_TD0->CP2;
        break;
    case TMRD_TIMING_A1_LEADING:
        retval = (uint16_t) TSB_TD0->CP3;
        break;
    case TMRD_TIMING_A1_TRAILING:
        retval = (uint16_t) TSB_TD0->CP4;
        break;
    case TMRD_TIMING_PHASE_SHIFT:
        retval = (uint16_t) TSB_TD0->CP5;
        break;
    case TMRD_TIMING_TD1_CYCLE:
        retval = (uint16_t) TSB_TD1->CP0;
        break;
    case TMRD_TIMING_B0_LEADING:
        retval = (uint16_t) TSB_TD1->CP1;
        break;
    case TMRD_TIMING_B0_TRAILING:
        retval = (uint16_t) TSB_TD1->CP2;
        break;
    case TMRD_TIMING_B1_LEADING:
        retval = (uint16_t) TSB_TD1->CP3;
        break;
    case TMRD_TIMING_B1_TRAILING:
        retval = (uint16_t) TSB_TD1->CP4;
        break;
    default:
        /* Do nothing */
        break;
    }
    return retval;
}

/** @} */
/* End of group TMRD_Exported_Functions */

/** @} */
/* End of group TMRD */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_TMRD_H) */
