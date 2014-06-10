/**
 *******************************************************************************
 * @file    tmpm341_tmrd.h
 * @brief   This file provides all the functions prototypes for TMRD driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM341_TMRD_H
#define __TMPM341_TMRD_H

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_TMRD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup TMRD
  * @{
  */

/** @defgroup TMRD_Exported_Types
  * @{
  */

/**
  * @brief TMRD Timing Structure definition
  */

    typedef struct {
        uint16_t Cycle;
        uint16_t LeadingTiming0;
        uint16_t TrailingTiming0;
        uint16_t LeadingTiming1;
        uint16_t TrailingTiming1;
        uint16_t PhaseShiftTiming;
    } TMRD_TimingTypeDef;

/** @} */
/* End of group TMRD_Exported_Types */

/** @defgroup TMRD_Exported_Constants
  * @{
  */
#define IS_TMRD_ALL_PERIPH(param)                   (((param) == TSB_TD0) || ((param) == TSB_TD1))

#define TMRD_RUN                                    ((uint8_t)0x00)
#define TMRD_STOP                                   ((uint8_t)0x01)
#define IS_TMRD_RUN_STATE(param)                    ((param) <= TMRD_STOP)

#define TMRD_MODE_BOTH_TMR                          ((uint8_t)0x00)
#define TMRD_MODE_0TMR_1PPG                         ((uint8_t)0x01)
#define TMRD_MODE_0PPG_1TMR                         ((uint8_t)0x02)
#define TMRD_MODE_BOTH_PPG                          ((uint8_t)0x03)
#define TMRD_MODE_INTERLOCK_TMR                     ((uint8_t)0x04)
#define TMRD_MODE_INTERLOCK_PPG                     ((uint8_t)0x07)
#define IS_TMRD_MODE(param)                        (((param) == TMRD_MODE_BOTH_TMR) || \
                                                    ((param) == TMRD_MODE_0TMR_1PPG) || \
                                                    ((param) == TMRD_MODE_0PPG_1TMR) || \
                                                    ((param) == TMRD_MODE_BOTH_PPG) || \
                                                    ((param) == TMRD_MODE_INTERLOCK_TMR) || \
                                                    ((param) == TMRD_MODE_INTERLOCK_PPG))

#define TMRD_PPG_CHANNEL_A0                         ((uint8_t)0x00)
#define TMRD_PPG_CHANNEL_A1                         ((uint8_t)0x01)
#define TMRD_PPG_CHANNEL_B0                         ((uint8_t)0x02)
#define TMRD_PPG_CHANNEL_B1                         ((uint8_t)0x03)
#define IS_TMRD_PPG_CHANNEL(param)                  ((param) <= TMRD_PPG_CHANNEL_B1)

#define TMRD_WAVE_EDGE_RISING                       ((uint8_t)0x00)
#define TMRD_WAVE_EDGE_FALLING                      ((uint8_t)0x01)
#define IS_TMRD_WAVE_EDGE(param)                    ((param) <= TMRD_WAVE_EDGE_FALLING)

#define TMRD_FREE_RUN                               ((uint8_t)0x00)
#define TMRD_AUTO_CLEAR                             ((uint8_t)0x01)
#define IS_TMRD_UC_CTRL(param)                      ((param) <= TMRD_AUTO_CLEAR)

#define TMRD_CLK_DIV_1                              ((uint8_t)0x00)
#define TMRD_CLK_DIV_2                              ((uint8_t)0x08)
#define TMRD_CLK_DIV_4                              ((uint8_t)0x09)
#define TMRD_CLK_DIV_8                              ((uint8_t)0x0A)
#define TMRD_CLK_DIV_16                             ((uint8_t)0x0B)
#define IS_TMRD_CLK_DIV(param)                     (((param) == TMRD_CLK_DIV_1) || \
                                                    ((param) == TMRD_CLK_DIV_2) || \
                                                    ((param) == TMRD_CLK_DIV_4) || \
                                                    ((param) == TMRD_CLK_DIV_8) || \
                                                    ((param) == TMRD_CLK_DIV_16))

#define TMRD_CMP_WRITE_DIRECT                       ((uint8_t)0x00)
#define TMRD_CMP_WRITE_INDIRECT                     ((uint8_t)0x01)
#define IS_TMRD_CMP_WRITE_PATH(param)               ((param) <= TMRD_CMP_WRITE_INDIRECT)

#define TMRD_INT_NONE                               ((uint8_t)0x00)
#define TMRD_INT_MATCH_CYCLE                        ((uint8_t)0x01)
#define TMRD_INT_MATCH_PHASE                        ((uint8_t)0x02)
#define TMRD_INT_UC_OVERFLOW                        ((uint8_t)0x03)
#define IS_TMRD_TD0_INT_SRC(param)                  ((param) <= TMRD_INT_UC_OVERFLOW)
#define IS_TMRD_TD1_INT_SRC(param)                 (((param) == TMRD_INT_NONE) || \
                                                    ((param) == TMRD_INT_MATCH_CYCLE) || \
                                                    ((param) == TMRD_INT_UC_OVERFLOW))

#define TMRD_PHASE_DELAY_OR_SAME                    ((uint8_t)0x00)
#define TMRD_PHASE_FAST_OR_SAME                     ((uint8_t)0x01)
#define IS_TMRD_PHASE_RELATION(param)               ((param) <= TMRD_PHASE_FAST_OR_SAME)

#define TMRD_TIMING_TD0_CYCLE                       ((uint8_t)0x00)
#define TMRD_TIMING_A0_LEADING                      ((uint8_t)0x01)
#define TMRD_TIMING_A0_TRAILING                     ((uint8_t)0x02)
#define TMRD_TIMING_A1_LEADING                      ((uint8_t)0x03)
#define TMRD_TIMING_A1_TRAILING                     ((uint8_t)0x04)
#define TMRD_TIMING_PHASE_SHIFT                     ((uint8_t)0x05)
#define TMRD_TIMING_TD1_CYCLE                       ((uint8_t)0x06)
#define TMRD_TIMING_B0_LEADING                      ((uint8_t)0x07)
#define TMRD_TIMING_B0_TRAILING                     ((uint8_t)0x08)
#define TMRD_TIMING_B1_LEADING                      ((uint8_t)0x09)
#define TMRD_TIMING_B1_TRAILING                     ((uint8_t)0x0A)
#define IS_TMRD_TIMING_TYPE(param)                  ((param) <= TMRD_TIMING_B1_TRAILING)

/** @} */
/* End of group TMRD_Exported_Constants */
/** @defgroup TMRD_Exported_FunctionPrototypes
  * @{
  */

    void TMRD_Enable(TSB_TD_TypeDef * TDx);
    void TMRD_Disable(TSB_TD_TypeDef * TDx);
    void TMRD_SetRunStateInHalt(uint8_t RunState);
    void TMRD_SetRunStateInIdle(TSB_TD_TypeDef * TDx, uint8_t RunState);
    void TMRD_SetMode(uint8_t Mode);
    void TMRD_SetClkDivision(TSB_TD_TypeDef * TDx, uint8_t ClkDiv);
    void TMRD_SetUpCntCtrl(TSB_TD_TypeDef * TDx, uint8_t UpCntCtrl);
    void TMRD_SetPPGInitLeadingEdge(uint8_t PPGChannel, uint8_t WaveEdge);
    void TMRD_SetCMPRegWritePath(TSB_TD_TypeDef * TDx, uint8_t WritePath);
    void TMRD_SetCMP0INTSrc(TSB_TD_TypeDef * TDx, uint8_t INTSrc);
    void TMRD_SetRunState(TSB_TD_TypeDef * TDx, uint8_t RunState);
    void TMRD_SetPhaseRelation(uint8_t PhaseRelation);
    void TMRD_EnableUpdateCMPReg(TSB_TD_TypeDef * TDx);
    void TMRD_SetDMAReq(TSB_TD_TypeDef * TDx, FunctionalState NewState);
    void TMRD_SetInitTiming(TSB_TD_TypeDef * TDx, TMRD_TimingTypeDef * TimingStruct);
    void TMRD_ChangeTiming(uint8_t TimingType, uint16_t Timing);
    uint16_t TMRD_GetTiming(uint8_t TimingType);

/** @} */
/* End of group TMRD_Exported_FunctionPrototypes */

/** @} */
/* End of group TMRD */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM341_TMRD_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM341_TMRD_H */
