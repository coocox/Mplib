/**
 *******************************************************************************
 * @file    tmpm375_enc.h
 * @brief   This file provides all the functions prototypes for ENC driver. 
 * @version V2.0.2.1
 * @date    2013/02/04
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM375_ENC_H
#define __TMPM375_ENC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM375.h"
#include "tx03_common.h"

/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @addtogroup ENC
  * @{
  */

/** @addtogroup ENC Exported_types
  * @{
  */

/** @brief ENC input control structure definition
  * @{
  */
    typedef struct {
        uint32_t ModeType;      /* Encoder input mode selection */
        uint32_t PhaseType;     /* 2-phase / 3-phase input selection (sensor mode) */
        uint32_t EdgeType;      /* Edge selection of ENCZ (timer mode) */
        uint32_t CompareStatus; /* Enable or disable the encoder compare function */
        uint32_t ZphaseStatus;  /* Enable or disable the Z-phase (Encoder mode/timer mode) */
        uint32_t FilterValue;   /* Set the noise filter effect Value  */
        uint32_t IntEn;         /* Enable or disable the encoder interrupt */
        uint32_t PulseDivFactor;        /* Set the encoder pulse division factor */
    } ENC_InitTypeDef;

/** @brief ENC flag union definition
  * @{
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Reserved1:12;      /* bit 0 to bit 11,Reserved */
            uint32_t ZPhaseDetectFlag:1;        /* bit 12,ENC Z-phase detect flag */
            uint32_t RotationDirection:1;       /* bit 13,ENC rotation direction */
            uint32_t ReverseErrorFlag:1;        /* bit 14,ENC sensor mode (at time count) reverse error flag */
            uint32_t CompareFlag:1;     /* bit 15,ENC compare flag */
            uint32_t Reserved2:16;      /* bit 16 to bit 31,Reserved */
        } Bit;
    } ENC_FlagStatus;

/** @} */
/* End of ENC_Exported_types */

/** @defgroup ENC_Exported_Constants
  * @{
  */
#define EN0    TSB_EN0
#define IS_ENC_PERIPH(param)          (((param) == EN0))

#define ENC_ENCODER_MODE              ((uint32_t)0x00000000)
#define ENC_SENSOR_EVENT_MODE         ((uint32_t)0x00000001)
#define ENC_SENSOR_TIME_MODE          ((uint32_t)0x00000002)
#define ENC_TIMER_MODE                ((uint32_t)0x00000003)
#define IS_ENC_MODE(param)            (((param)== ENC_ENCODER_MODE)||\
                                        ((param)== ENC_SENSOR_EVENT_MODE)||\
                                        ((param)== ENC_SENSOR_TIME_MODE)||\
                                        ((param)== ENC_TIMER_MODE))

#define IS_ENC_ENCODER_MODE(param)    (((param)== ENC_ENCODER_MODE))

#define IS_ENC_SW_MODE(param)         (((param)== ENC_TIMER_MODE)||\
                                        ((param)== ENC_SENSOR_TIME_MODE))

#define ENC_TWO_PHASE                 ((uint32_t)0x00000000)
#define ENC_THREE_PHASE               ((uint32_t)0x00000001)
#define IS_ENC_PHASE(param)           (((param)== ENC_TWO_PHASE)||\
                                        ((param)== ENC_THREE_PHASE))

#define ENC_NO_FILTER                 ((uint32_t)0x00000000)
#define ENC_FILTER_VALUE31            ((uint32_t)0x00000001)    /* Filters out pulses narrower than 31/fsys as noise  */
#define ENC_FILTER_VALUE63            ((uint32_t)0x00000002)
#define ENC_FILTER_VALUE127           ((uint32_t)0x00000003)
#define IS_ENC_FILTERVALUE(param)     (((param)== ENC_NO_FILTER)||\
                                        ((param)== ENC_FILTER_VALUE31)||\
                                        ((param)== ENC_FILTER_VALUE63)||\
                                        ((param)== ENC_FILTER_VALUE127))
/* Encoder pulse division factor */
#define ENC_PULSE_DIV1                ((uint32_t)0x00000000)
#define ENC_PULSE_DIV2                ((uint32_t)0x00000001)
#define ENC_PULSE_DIV4                ((uint32_t)0x00000002)
#define ENC_PULSE_DIV8                ((uint32_t)0x00000003)
#define ENC_PULSE_DIV16               ((uint32_t)0x00000004)
#define ENC_PULSE_DIV32               ((uint32_t)0x00000005)
#define ENC_PULSE_DIV64               ((uint32_t)0x00000006)
#define ENC_PULSE_DIV128              ((uint32_t)0x00000007)
#define IS_ENC_DIV_FACTOR(param)      (((param)== ENC_PULSE_DIV1)||\
                                        ((param)== ENC_PULSE_DIV2)||\
                                        ((param)== ENC_PULSE_DIV4)||\
                                        ((param)== ENC_PULSE_DIV8)||\
                                        ((param)== ENC_PULSE_DIV16)||\
                                        ((param)== ENC_PULSE_DIV32)||\
                                        ((param)== ENC_PULSE_DIV64)||\
                                        ((param)== ENC_PULSE_DIV128))

#define ENC_RISING_EDGE               ((uint32_t)0x00000000)
#define ENC_FALLING_EDGE              ((uint32_t)0x00000001)
#define IS_ENC_EDGE(param)            (((param)== ENC_RISING_EDGE)||\
                                       ((param)== ENC_FALLING_EDGE))

#define ENC_COMPARE_DISABLE           ((uint32_t)0x00000000)
#define ENC_COMPARE_ENABLE            ((uint32_t)0x00000001)
#define IS_ENC_CMPEN_STATUS(param)    (((param)== ENC_COMPARE_ENABLE)||\
                                       ((param)== ENC_COMPARE_DISABLE))

#define ENC_ZPHASE_DISABLE            ((uint32_t)0x00000000)
#define ENC_ZPHASE_ENABLE             ((uint32_t)0x00000001)
#define IS_ENC_ZPHASE_STATUS(param)    (((param)== ENC_ZPHASE_ENABLE)||\
                                       ((param)== ENC_ZPHASE_DISABLE))

#define ENC_INTERRUPT_DISABLE         ((uint32_t)0x00000000)
#define ENC_INTERRUPT_ENABLE          ((uint32_t)0x00000001)
#define IS_ENC_INT_STATUS(param)      (((param)== ENC_INTERRUPT_DISABLE)||\
                                       ((param)== ENC_INTERRUPT_ENABLE))

#define IS_ENC_24BITVALUE(param)    (((param) <= 0xFFFFFFU))
#define IS_ENC_16BITVALUE(param)    (((param) <= 0xFFFFU))

/** @} */
/* End of group ENC_Exported_Constants */


/** @defgroup ENC_Exported_FunctionPrototypes
  * @{
  */
    void ENC_Enable(TSB_EN_TypeDef * ENx);
    void ENC_Disable(TSB_EN_TypeDef * ENx);
    void ENC_Init(TSB_EN_TypeDef * ENx, ENC_InitTypeDef * InitStruct);
    void ENC_SetSWCapture(TSB_EN_TypeDef * ENx, uint32_t ENC_Mode);
    void ENC_ClearCounter(TSB_EN_TypeDef * ENx);
    ENC_FlagStatus ENC_GetENCFlag(TSB_EN_TypeDef * ENx);
    void ENC_SetCounterReload(TSB_EN_TypeDef * ENx, uint32_t PeriodValue);
    void ENC_SetCompareValue(TSB_EN_TypeDef * ENx, uint32_t ENC_Mode, uint32_t CompareValue);
    uint32_t ENC_GetCompareValue(TSB_EN_TypeDef * ENx);
    uint32_t ENC_GetCounterValue(TSB_EN_TypeDef * ENx);
/** @} */
/* End of group ENC_Exported_FunctionPrototypes */

/** @} */
/* End of group ENC */

/** @} */
/* End of group TX03_Periph_Driver */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM375_ENC_H */
