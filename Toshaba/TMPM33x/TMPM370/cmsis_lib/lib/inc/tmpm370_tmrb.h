/**
 *******************************************************************************
 * @file    tmpm370_tmrb.h
 * @brief   This file provides all the functions prototypes for TMRB driver.
 * @version V2.2.0
 * @date    2011/06/08
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
#ifndef __TMPM370_TMRB_H
#define __TMPM370_TMRB_H

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "TMPM370.h"
#include "tx03_common.h"

#if defined(__TMPM370_TMRB_H) || defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup TMRB
  * @{
  */

/** @defgroup TMRB_Exported_Types
  * @{
  */

/**
  * @brief TMRB Init Structure definition
  */

    typedef struct {
        uint32_t Mode;          /*!< Select TMRB mode between internal interval
                                   timer mode and external event counter */
        uint32_t ClkDiv;        /*!< Select the division for TMRB source clock */
        uint32_t Cycle;         /*!< Specify the cycle value to be written 
                                   into TBnRG1 */
        uint32_t UpCntCtrl;     /*!< Select up-counter work mode between 
                                   freerun and auto-reload */
        uint32_t Duty;          /*!< Specify the duty value to be written 
                                   into TBnRG0 */
    } TMRB_InitTypeDef;

/**
  * @brief TMRB Flip-flop Structure definition
  */

    typedef struct {
        uint32_t FlipflopCtrl;  /*!< Select TMRB flip-flop output level */
        uint32_t FlipflopReverseTrg;    /*!< Specify TMRB flip-flop reverse trigger */
    } TMRB_FFOutputTypeDef;

/**
  * @brief TMRB Interrupt factor Union definition
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t MatchDuty:1;
            uint32_t MatchCycle:1;
            uint32_t OverFlow:1;
            uint32_t Reserverd:29;
        } Bit;
    } TMRB_INTFactor;

/** @} */
/* End of group TMRB_Exported_Types */

/** @defgroup TMRB_Exported_Constants
  * @{
  */
#define IS_TMRB_ALL_PERIPH(param)    (((param) == TSB_TB0) || \
                                      ((param) == TSB_TB1) || \
                                      ((param) == TSB_TB2) || \
                                      ((param) == TSB_TB3) || \
                                      ((param) == TSB_TB4) || \
                                      ((param) == TSB_TB5) || \
                                      ((param) == TSB_TB6) || \
                                      ((param) == TSB_TB7))

#if defined(__TMPM370_TMRB_H)
#define IS_TMRB_IN_PERIPH             IS_TMRB_ALL_PERIPH
#define IS_TMRB_OUT_PERIPH            IS_TMRB_ALL_PERIPH
#endif                          /* defined(__TMPM370_TMRB_H) */

#if defined(__TMPM372_TMRB_H)
#define IS_TMRB_IN_PERIPH(param)               (((param) == TSB_TB0) || \
                                               ((param) == TSB_TB1) || \
                                               ((param) == TSB_TB2) || \
                                               ((param) == TSB_TB3) || \
                                               ((param) == TSB_TB4) || \
                                               ((param) == TSB_TB6) || \
                                               ((param) == TSB_TB7))
#define IS_TMRB_OUT_PERIPH            IS_TMRB_IN_PERIPH
#endif                          /* defined(__TMPM372_TMRB_H) */

#if defined(__TMPM373_TMRB_H)
#define IS_TMRB_IN_PERIPH(param)               (((param) == TSB_TB1) || \
                                               ((param) == TSB_TB2) || \
                                               ((param) == TSB_TB3) || \
                                               ((param) == TSB_TB6) || \
                                               ((param) == TSB_TB7))
#define IS_TMRB_OUT_PERIPH(param)              (((param) == TSB_TB3) || \
                                               ((param) == TSB_TB6) || \
                                               ((param) == TSB_TB7))
#endif                          /* defined(__TMPM373_TMRB_H) */

#if defined(__TMPM374_TMRB_H)
#define IS_TMRB_IN_PERIPH(param)               (((param) == TSB_TB2) || \
                                               ((param) == TSB_TB3) || \
                                               ((param) == TSB_TB6) || \
                                               ((param) == TSB_TB7))
#define IS_TMRB_OUT_PERIPH(param)              (((param) == TSB_TB3) || \
                                               ((param) == TSB_TB6))
#endif                          /* defined(__TMPM374_TMRB_H) */


#define TMRB_INTERVAL_TIMER          ((uint32_t)0x00000001)
#define TMRB_EVENT_CNT               ((uint32_t)0x00000000)
#define IS_TMRB_MODE(param)          (((param) == TMRB_INTERVAL_TIMER) || \
                                      ((param) == TMRB_EVENT_CNT))

#define TMRB_CLK_DIV_2               ((uint32_t)0x00000001)
#define TMRB_CLK_DIV_8               ((uint32_t)0x00000002)
#define TMRB_CLK_DIV_32              ((uint32_t)0x00000003)
#define IS_TMRB_CLK_DIV(param)       (((param) == TMRB_CLK_DIV_2) || \
                                      ((param) == TMRB_CLK_DIV_8) || \
                                      ((param) == TMRB_CLK_DIV_32))

#define TMRB_FREE_RUN                ((uint32_t)0x00000000)
#define TMRB_AUTO_CLEAR              ((uint32_t)0x00000004)
#define IS_TMRB_UC_CTRL(param)       (((param) == TMRB_FREE_RUN) || \
                                      ((param) == TMRB_AUTO_CLEAR))

#define TMRB_FLIPFLOP_INVERT         ((uint32_t)0x00000000)
#define TMRB_FLIPFLOP_SET            ((uint32_t)0x00000001)
#define TMRB_FLIPFLOP_CLEAR          ((uint32_t)0x00000002)
#define IS_TMRB_FLIPFLOP_CTRL(param) (((param) == TMRB_FLIPFLOP_INVERT) || \
                                      ((param) == TMRB_FLIPFLOP_SET) || \
                                      ((param) == TMRB_FLIPFLOP_CLEAR))

#define TMRB_DISABLE_FLIPFLOP        ((uint32_t)0x00000000)
#define TMRB_FLIPFLOP_TAKE_CAPTURE_0 ((uint32_t)0x00000010)
#define TMRB_FLIPFLOP_TAKE_CAPTURE_1 ((uint32_t)0x00000020)
#define TMRB_FLIPFLOP_MATCH_CYCLE    ((uint32_t)0x00000008)
#define TMRB_FLIPFLOP_MATCH_DUTY     ((uint32_t)0x00000004)
#define IS_TMRB_FLIPFLOP_TRG(param)  (((param) == TMRB_DISABLE_FLIPFLOP) || \
                                      ((param) == TMRB_FLIPFLOP_TAKE_CAPTURE_0) || \
                                      ((param) == TMRB_FLIPFLOP_TAKE_CAPTURE_1) || \
                                      ((param) == TMRB_FLIPFLOP_MATCH_CYCLE) || \
                                      ((param) == TMRB_FLIPFLOP_MATCH_DUTY) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_TAKE_CAPTURE_1)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_MATCH_CYCLE)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_CYCLE)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_CYCLE)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_DUTY)) || \
                                      ((param) == (TMRB_FLIPFLOP_TAKE_CAPTURE_0 | TMRB_FLIPFLOP_TAKE_CAPTURE_1 | TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY)))

#define TMRB_DISABLE_CAPTURE                ((uint32_t)0x00000000)
#define TMRB_CAPTURE_IN_RISING              ((uint32_t)0x00000008)
#define TMRB_CAPTURE_IN_RISING_FALLING      ((uint32_t)0x00000010)
#define IS_TMRB_CAPTURE_TIMING(param)       (((param) == TMRB_DISABLE_CAPTURE) || \
                                             ((param) == TMRB_CAPTURE_IN_RISING) || \
                                             ((param) == TMRB_CAPTURE_IN_RISING_FALLING))

#define TMRB_RUN                      ((uint32_t)0x00000005)
#define TMRB_STOP                     ((uint32_t)0x00000000)
#define IS_TMRB_CMD(param)            (((param) == TMRB_RUN) || ((param) == TMRB_STOP))

#define TMRB_CAPTURE_0                ((uint8_t)0x00)
#define TMRB_CAPTURE_1                ((uint8_t)0x01)
#define IS_TMRB_CAPTURE_REG(param)    (((param) == TMRB_CAPTURE_0) || ((param) == TMRB_CAPTURE_1))

#define TMRB_NO_INT_MASK              ((uint32_t)0x00000000)
#define TMRB_MASK_MATCH_DUTY_INT      ((uint32_t)0x00000001)
#define TMRB_MASK_MATCH_CYCLE_INT     ((uint32_t)0x00000002)
#define TMRB_MASK_OVERFLOW_INT        ((uint32_t)0x00000004)
#define IS_TMRB_INT_MASK(param)       (((param) == TMRB_NO_INT_MASK) || \
                                       ((param) == TMRB_MASK_MATCH_DUTY_INT) || \
                                       ((param) == TMRB_MASK_MATCH_CYCLE_INT) || \
                                       ((param) == TMRB_MASK_OVERFLOW_INT) || \
                                       ((param) == (TMRB_MASK_MATCH_DUTY_INT | TMRB_MASK_MATCH_CYCLE_INT)) || \
                                       ((param) == (TMRB_MASK_MATCH_DUTY_INT | TMRB_MASK_OVERFLOW_INT)) || \
                                       ((param) == (TMRB_MASK_MATCH_CYCLE_INT | TMRB_MASK_OVERFLOW_INT)) || \
                                       ((param) == (TMRB_MASK_MATCH_DUTY_INT | TMRB_MASK_MATCH_CYCLE_INT | TMRB_MASK_OVERFLOW_INT)))

#define TMRB_TRG_EDGE_RISING          ((uint8_t)0x00)
#define TMRB_TRG_EDGE_FALLING         ((uint8_t)0x02)
#define IS_TMRB_TRG_EDGE(param)       (((param) == TMRB_TRG_EDGE_RISING) || \
                                       ((param) == TMRB_TRG_EDGE_FALLING))

#define TMRB_WRITE_REG_SEPARATE       ((uint8_t)0x00)
#define TMRB_WRITE_REG_SIMULTANEOUS   ((uint8_t)0x40)
#define IS_TMRB_WRITE_REG_MODE(param) (((param) == TMRB_WRITE_REG_SEPARATE) || \
                                       ((param) == TMRB_WRITE_REG_SIMULTANEOUS))

#if defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H)
#define TMRB_RUNNING_IN_CORE_HALT        ((uint8_t)0x00)
#define TMRB_STOP_IN_CORE_HALT           ((uint8_t)0x40)
#define IS_TMRB_CLK_IN_CORE_HALT(param)  (((param) == TMRB_RUNNING_IN_CORE_HALT) || \
                                          ((param) == TMRB_STOP_IN_CORE_HALT))
#endif                          /* defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H) */

#define IS_TMRB_VALUE(param)          ((param) <= 0x0000FFFFU)
#define IS_VALID_DUTY(param1, param2) ((param1) <= (param2))


/** @} */
/* End of group TMRB_Exported_Constants */
/** @defgroup TMRB_Exported_FunctionPrototypes
  * @{
  */
    void TMRB_Enable(TSB_TB_TypeDef * TBx);
    void TMRB_Disable(TSB_TB_TypeDef * TBx);
    void TMRB_SetRunState(TSB_TB_TypeDef * TBx, uint32_t Cmd);
    void TMRB_Init(TSB_TB_TypeDef * TBx, TMRB_InitTypeDef * InitStruct);
    void TMRB_SetCaptureTiming(TSB_TB_TypeDef * TBx, uint32_t CaptureTiming);
    void TMRB_SetFlipFlop(TSB_TB_TypeDef * TBx, TMRB_FFOutputTypeDef * FFStruct);
    TMRB_INTFactor TMRB_GetINTFactor(TSB_TB_TypeDef * TBx);
    void TMRB_SetINTMask(TSB_TB_TypeDef * TBx, uint32_t INTMask);
    void TMRB_ChangeDuty(TSB_TB_TypeDef * TBx, uint32_t Duty);
    void TMRB_ChangeCycle(TSB_TB_TypeDef * TBx, uint32_t Cycle);
    uint16_t TMRB_GetUpCntValue(TSB_TB_TypeDef * TBx);
    uint16_t TMRB_GetCaptureValue(TSB_TB_TypeDef * TBx, uint8_t CapReg);
    void TMRB_ExecuteSWCapture(TSB_TB_TypeDef * TBx);
    void TMRB_SetIdleMode(TSB_TB_TypeDef * TBx, FunctionalState NewState);
    void TMRB_SetDoubleBuf(TSB_TB_TypeDef * TBx, FunctionalState NewState, uint8_t WriteRegMode);
    void TMRB_SetExtStartTrg(TSB_TB_TypeDef * TBx, FunctionalState NewState, uint8_t TrgMode);
#if defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H)
    void TMRB_SetClkInCoreHalt(TSB_TB_TypeDef * TBx, uint8_t ClkState);
#endif                          /* defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H) */

/** @} */
/* End of group TMRB_Exported_FunctionPrototypes */

/** @} */
/* End of group TMRB */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM370_TMRB_H) || defined(__TMPM372_TMRB_H) || defined(__TMPM373_TMRB_H) || defined(__TMPM374_TMRB_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM370_TMRB_H */
