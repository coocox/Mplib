/**
 *******************************************************************************
 * @file    tmpm369_igbt.h
 * @brief   This file provides all the functions prototypes for IGBT driver.
 * @version V2.0.2.1
 * @date    2011/07/25
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
#ifndef __TMPM369_IGBT_H
#define __TMPM369_IGBT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
#include "tx03_common.h"

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup IGBT
  * @{
  */

/** @defgroup IGBT_Exported_Types
  * @{
  */

/** 
  * @brief IGBT Initialization Structure definition
  */

    typedef struct {
        uint8_t StartMode;      /*!< Select start mode */
        uint8_t OperationMode;  /*!< Select operation mode */
        uint8_t CntStopState;   /*!< Specify the output state when counter stops */
        FunctionalState ActiveAcceptTrg;        /*!< Select whether the trigger is accepted
                                                   when IGBT outputs active level */
        uint8_t INTPeriod;      /*!< Specify the interrupt period */
        uint8_t ClkDiv;         /*!< Specify the division for MPT source clock in IGBT mode */
        uint8_t Output0Init;    /*!< Initialize the IGBT output 0 */
        uint8_t Output1Init;    /*!< Initialize the IGBT output 1 */
        uint8_t TrgDenoiseDiv;  /*!< Select the division for noise elimination time for 
                                   trigger input in IGBT mode */
        uint16_t Output0ActiveTiming;   /*!< Specify the active timing of output 0 */
        uint16_t Output0InactiveTiming; /*!< Specify the inactive timing of output 0 */
        uint16_t Output1ActiveTiming;   /*!< Specify the active timing of output 1 */
        uint16_t Output1InactiveTiming; /*!< Specify the inactive timing of output 1 */
        uint16_t Period;        /*!< Specify the period of IGBT output */
        uint8_t EMGFunction;    /*!< Specify the EMG stop function */
        uint8_t EMGDenoiseDiv;  /*!< Select the division of noise elimination time for
                                   EMG input in IGBT mode */
    } IGBT_InitTypeDef;

/** 
  * @brief IGBT EMG status enum and structure definition
  */

    typedef enum {
        IGBT_EMG_INPUT_LOW = 0U,
        IGBT_EMG_INPUT_HIGH = 1U
    } IGBT_EMGInputState;

    typedef enum {
        IGBT_EMG_NORMAL = 0U,
        IGBT_EMG_PROTECT = 1U
    } IGBT_EMGProtectState;

    typedef struct {
        IGBT_EMGInputState EMGInputState;       /*!< EMG input status after noise elimination */
        IGBT_EMGProtectState EMGProtectState;   /*!< EMG protection status */
    } IGBT_EMGStateTypeDef;

/** @} */
/* End of group IGBT_Exported_Types */

/** @defgroup IGBT_Exported_Constants
  * @{
  */
#define IGBT0    TSB_MT0
#define IGBT1    TSB_MT1
#define IGBT2    TSB_MT2
#define IGBT3    TSB_MT3

#define IS_IGBT_PERIPH(param)       (((param) == IGBT0) || \
                                     ((param) == IGBT1) || \
                                     ((param) == IGBT2) || \
                                     ((param) == IGBT3))

#define IGBT_CMD_START                          ((uint8_t)0x00)
#define IGBT_CMD_START_NO_START_INT             ((uint8_t)0x01)
#define IGBT_CMD_FALLING_TRG_START              ((uint8_t)0x44)
#define IGBT_CMD_FALLING_TRG_START_NO_START_INT ((uint8_t)0x45)
#define IGBT_CMD_RISING_TRG_START               ((uint8_t)0x04)
#define IGBT_CMD_RISING_TRG_START_NO_START_INT  ((uint8_t)0x05)
#define IGBT_FALLING_TRG_START                  ((uint8_t)0x48)
#define IGBT_RISING_TRG_START                   ((uint8_t)0x08)
#define IS_IGBT_START_MODE(param)               (((param) == IGBT_CMD_START) || \
                                                 ((param) == IGBT_CMD_START_NO_START_INT) || \
                                                 ((param) == IGBT_CMD_FALLING_TRG_START) || \
                                                 ((param) == IGBT_CMD_FALLING_TRG_START_NO_START_INT) || \
                                                 ((param) == IGBT_CMD_RISING_TRG_START) || \
                                                 ((param) == IGBT_CMD_RISING_TRG_START_NO_START_INT) || \
                                                 ((param) == IGBT_FALLING_TRG_START) || \
                                                 ((param) == IGBT_RISING_TRG_START))

#define IGBT_CONTINUOUS_OUTPUT             ((uint8_t)0x00)
#define IGBT_ONE_TIME_OUTPUT               ((uint8_t)0x40)
#define IS_IGBT_OPERATION_MODE(param)      (((param) == IGBT_CONTINUOUS_OUTPUT) || \
                                            ((param) == IGBT_ONE_TIME_OUTPUT))

#define IGBT_OUTPUT_INACTIVE               ((uint8_t)0x00)
#define IGBT_OUTPUT_MAINTAINED             ((uint8_t)0x10)
#define IGBT_OUTPUT_NORMAL                 ((uint8_t)0x20)
#define IS_IGBT_CNT_STOP_STATE(param)      (((param) == IGBT_OUTPUT_INACTIVE) || \
                                            ((param) == IGBT_OUTPUT_MAINTAINED) || \
                                            ((param) == IGBT_OUTPUT_NORMAL))

#define IGBT_INT_PERIOD_1           ((uint8_t)0x00)
#define IGBT_INT_PERIOD_2           ((uint8_t)0x01)
#define IGBT_INT_PERIOD_4           ((uint8_t)0x02)
#define IS_IGBT_INT_PERIOD(param)   (((param) == IGBT_INT_PERIOD_1) || \
                                     ((param) == IGBT_INT_PERIOD_2) || \
                                     ((param) == IGBT_INT_PERIOD_4))

#define IGBT_CLK_DIV_1              ((uint8_t)0x00)
#define IGBT_CLK_DIV_2              ((uint8_t)0x01)
#define IGBT_CLK_DIV_4              ((uint8_t)0x02)
#define IGBT_CLK_DIV_8              ((uint8_t)0x03)
#define IS_IGBT_CLK_DIV(param)      (((param) == IGBT_CLK_DIV_1) || \
                                     ((param) == IGBT_CLK_DIV_2) || \
                                     ((param) == IGBT_CLK_DIV_4) || \
                                     ((param) == IGBT_CLK_DIV_8))

#define IGBT_OUTPUT_DISABLE         ((uint8_t)0x00)
#define IGBT_OUTPUT_LOW_ACTIVE      ((uint8_t)0x11)
#define IGBT_OUTPUT_HIGH_ACTIVE     ((uint8_t)0x01)
#define IS_IGBT_INIT_OUTPUT(param)  (((param) == IGBT_OUTPUT_DISABLE) || \
                                     ((param) == IGBT_OUTPUT_LOW_ACTIVE) || \
                                     ((param) == IGBT_OUTPUT_HIGH_ACTIVE))

#define IGBT_NO_DENOISE             ((uint8_t)0x00)
#define IGBT_DENOISE_DIV_16         ((uint8_t)0x01)
#define IGBT_DENOISE_DIV_32         ((uint8_t)0x02)
#define IGBT_DENOISE_DIV_48         ((uint8_t)0x03)
#define IGBT_DENOISE_DIV_64         ((uint8_t)0x04)
#define IGBT_DENOISE_DIV_80         ((uint8_t)0x05)
#define IGBT_DENOISE_DIV_96         ((uint8_t)0x06)
#define IGBT_DENOISE_DIV_112        ((uint8_t)0x07)
#define IGBT_DENOISE_DIV_128        ((uint8_t)0x08)
#define IGBT_DENOISE_DIV_144        ((uint8_t)0x09)
#define IGBT_DENOISE_DIV_160        ((uint8_t)0x0A)
#define IGBT_DENOISE_DIV_176        ((uint8_t)0x0B)
#define IGBT_DENOISE_DIV_192        ((uint8_t)0x0C)
#define IGBT_DENOISE_DIV_208        ((uint8_t)0x0D)
#define IGBT_DENOISE_DIV_224        ((uint8_t)0x0E)
#define IGBT_DENOISE_DIV_240        ((uint8_t)0x0F)
#define IS_IGBT_DENOISE_DIV(param)  (((param) == IGBT_NO_DENOISE) || \
                                     ((param) == IGBT_DENOISE_DIV_16) || \
                                     ((param) == IGBT_DENOISE_DIV_32) || \
                                     ((param) == IGBT_DENOISE_DIV_48) || \
                                     ((param) == IGBT_DENOISE_DIV_64) || \
                                     ((param) == IGBT_DENOISE_DIV_80) || \
                                     ((param) == IGBT_DENOISE_DIV_96) || \
                                     ((param) == IGBT_DENOISE_DIV_112) || \
                                     ((param) == IGBT_DENOISE_DIV_128) || \
                                     ((param) == IGBT_DENOISE_DIV_144) || \
                                     ((param) == IGBT_DENOISE_DIV_160) || \
                                     ((param) == IGBT_DENOISE_DIV_176) || \
                                     ((param) == IGBT_DENOISE_DIV_192) || \
                                     ((param) == IGBT_DENOISE_DIV_208) || \
                                     ((param) == IGBT_DENOISE_DIV_224) || \
                                     ((param) == IGBT_DENOISE_DIV_240))

#define IGBT_DISABLE_EMG            ((uint8_t)0x00)
#define IGBT_EMG_OUTPUT_INACTIVE    ((uint8_t)0x01)
#define IGBT_EMG_OUTPUT_HIZ         ((uint8_t)0x03)
#define IS_IGBT_EMG_OUTPUT(param)   (((param) == IGBT_DISABLE_EMG) || \
                                     ((param) == IGBT_EMG_OUTPUT_INACTIVE) || \
                                     ((param) == IGBT_EMG_OUTPUT_HIZ))

#define IGBT_RUNNING_IN_CORE_HALT        ((uint8_t)0x00)
#define IGBT_STOP_IN_CORE_HALT           ((uint8_t)0x40)
#define IS_IGBT_CLK_IN_CORE_HALT(param)  (((param) == IGBT_RUNNING_IN_CORE_HALT) || \
                                          ((param) == IGBT_STOP_IN_CORE_HALT))

#define IGBT_RUN                    ((uint8_t)0x05)
#define IGBT_STOP                   ((uint8_t)0x00)
#define IS_IGBT_CMD(param)          (((param) == IGBT_RUN) || ((param) == IGBT_STOP))

#define IGBT_CAPTURE_0              ((uint8_t)0x00)
#define IGBT_CAPTURE_1              ((uint8_t)0x01)
#define IS_IGBT_CAPTURE_REG(param)  (((param) == IGBT_CAPTURE_0) || ((param) == IGBT_CAPTURE_1))

#define IGBT_OUTPUT_0               ((uint8_t)0x00)
#define IGBT_OUTPUT_1               ((uint8_t)0x01)
#define IS_IGBT_OUTPUT(param)       (((param) == IGBT_OUTPUT_0) || ((param) == IGBT_OUTPUT_1))

#define IS_IGBT_VAILD_PERIOD(param1, param2)   ((param1) >= (param2))

#define IS_IGBT_ACTIVE_TIMING(param1, param2)    (((param1) > 0U) && \
                                                  ((param1) < (param2)))

#define IS_IGBT_INACTIVE_TIMING(param1, param2, param3) (((param1) <= (param2)) && \
                                                         ((param1) > (param3)))
/** @} */
/* End of group IGBT_Exported_Constants */

/** @defgroup IGBT_Exported_FunctionPrototypes
  * @{
  */

    void IGBT_Enable(TSB_MT_TypeDef * IGBTx);
    void IGBT_Disable(TSB_MT_TypeDef * IGBTx);
    void IGBT_SetClkInCoreHalt(TSB_MT_TypeDef * IGBTx, uint8_t ClkState);
    void IGBT_SetSWRunState(TSB_MT_TypeDef * IGBTx, uint8_t Cmd);
    uint16_t IGBT_GetCaptureValue(TSB_MT_TypeDef * IGBTx, uint8_t CapReg);
    void IGBT_Init(TSB_MT_TypeDef * IGBTx, IGBT_InitTypeDef * InitStruct);
    void IGBT_Recount(TSB_MT_TypeDef * IGBTx);
    void IGBT_ChangeOutputActiveTiming(TSB_MT_TypeDef * IGBTx, uint8_t Output, uint16_t Timing);
    void IGBT_ChangeOutputInactiveTiming(TSB_MT_TypeDef * IGBTx, uint8_t Output, uint16_t Timing);
    void IGBT_ChangePeriod(TSB_MT_TypeDef * IGBTx, uint16_t Period);
    WorkState IGBT_GetCntState(TSB_MT_TypeDef * IGBTx);
    Result IGBT_CancelEMGState(TSB_MT_TypeDef * IGBTx);
    IGBT_EMGStateTypeDef IGBT_GetEMGState(TSB_MT_TypeDef * IGBTx);

/** @} */
/* End of group IGBT_Exported_FunctionPrototypes */

/** @} */
/* End of group IGBT */

/** @} */
/* End of group TX03_Periph_Driver */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM369_IGBT_H */
