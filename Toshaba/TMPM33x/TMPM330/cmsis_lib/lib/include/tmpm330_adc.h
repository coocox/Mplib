/**
 *******************************************************************************
 * @file    tmpm330_adc.h
 * @brief   This file provides all the functions prototypes for ADC driver.
 * @version V2.1.0
 * @date    2010/07/20
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM330_ADC_H
#define __TMPM330_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM330.h"
#include "tx03_common.h"

#if defined(__TMPM330_ADC_H) || defined(__TMPM332_ADC_H) || defined(__TMPM333_ADC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */

#define ADC_HOLD_CLK_8                  ((uint8_t)0x80)
#define ADC_HOLD_CLK_16                 ((uint8_t)0x90)
#define ADC_HOLD_CLK_24                 ((uint8_t)0xA0)
#define ADC_HOLD_CLK_32                 ((uint8_t)0xB0)
#define ADC_HOLD_CLK_64                 ((uint8_t)0x30)
#define ADC_HOLD_CLK_128                ((uint8_t)0xC0)
#define ADC_HOLD_CLK_512                ((uint8_t)0xD0)
#define IS_ADC_HOLD_TIME(param)         (((param) == ADC_HOLD_CLK_8) || \
                                         ((param) == ADC_HOLD_CLK_16) || \
                                         ((param) == ADC_HOLD_CLK_24) || \
                                         ((param) == ADC_HOLD_CLK_32) || \
                                         ((param) == ADC_HOLD_CLK_64) || \
                                         ((param) == ADC_HOLD_CLK_128) || \
                                         ((param) == ADC_HOLD_CLK_512))

#define ADC_FC_DIVIDE_LEVEL_1           ((uint8_t)0x00)
#define ADC_FC_DIVIDE_LEVEL_2           ((uint8_t)0x01)
#define ADC_FC_DIVIDE_LEVEL_4           ((uint8_t)0x02)
#define ADC_FC_DIVIDE_LEVEL_8           ((uint8_t)0x03)
#define ADC_FC_DIVIDE_LEVEL_16          ((uint8_t)0x04)
#define IS_ADC_PRESCALER(param)         (((param) == ADC_FC_DIVIDE_LEVEL_1) || \
                                         ((param) == ADC_FC_DIVIDE_LEVEL_2) || \
                                         ((param) == ADC_FC_DIVIDE_LEVEL_4) || \
                                         ((param) == ADC_FC_DIVIDE_LEVEL_8) || \
                                         ((param) == ADC_FC_DIVIDE_LEVEL_16))

#define ADC_INT_SIGNLE                  ((uint8_t)0x00)
#define ADC_INT_CONVERSION_4            ((uint8_t)0x08)
#define ADC_INT_CONVERSION_8            ((uint8_t)0x10)
#define IS_ADC_INT_MODE(param)          (((param) == ADC_INT_SIGNLE) || \
                                         ((param) == ADC_INT_CONVERSION_4) || \
                                         ((param) == ADC_INT_CONVERSION_8))

#if defined(__TMPM332_ADC_H)
#define ADC_AN_4                        ((uint8_t)0x04)
#define ADC_AN_5                        ((uint8_t)0x05)
#define ADC_AN_6                        ((uint8_t)0x06)
#define ADC_AN_7                        ((uint8_t)0x07)
#define ADC_AN_8                        ((uint8_t)0x08)
#define ADC_AN_9                        ((uint8_t)0x09)
#define ADC_AN_10                       ((uint8_t)0x0A)
#define ADC_AN_11                       ((uint8_t)0x0B)
#define ADC_AN_4_5                      ((uint8_t)0x05)
#define ADC_AN_4_6                      ((uint8_t)0x06)
#define ADC_AN_4_7                      ((uint8_t)0x07)
#define ADC_AN_8_9                      ((uint8_t)0x09)
#define ADC_AN_8_10                     ((uint8_t)0x0A)
#define ADC_AN_8_11                     ((uint8_t)0x0B)
#define IS_ADC_INPUT_CH(param)          (((param) == ADC_AN_4) || \
                                         ((param) == ADC_AN_5) || \
                                         ((param) == ADC_AN_6) || \
                                         ((param) == ADC_AN_7) || \
                                         ((param) == ADC_AN_8) || \
                                         ((param) == ADC_AN_9) || \
                                         ((param) == ADC_AN_10) || \
                                         ((param) == ADC_AN_11) || \
                                         ((param) == ADC_AN_4_5) || \
                                         ((param) == ADC_AN_4_6) || \
                                         ((param) == ADC_AN_4_7) || \
                                         ((param) == ADC_AN_8_9) || \
                                         ((param) == ADC_AN_8_10) || \
                                         ((param) == ADC_AN_8_11))
#else                           /*(__TMPM330_ADC_H) || (__TMPM333_ADC_H) */
#define ADC_AN_0                        ((uint8_t)0x00)
#define ADC_AN_1                        ((uint8_t)0x01)
#define ADC_AN_2                        ((uint8_t)0x02)
#define ADC_AN_3                        ((uint8_t)0x03)
#define ADC_AN_4                        ((uint8_t)0x04)
#define ADC_AN_5                        ((uint8_t)0x05)
#define ADC_AN_6                        ((uint8_t)0x06)
#define ADC_AN_7                        ((uint8_t)0x07)
#define ADC_AN_8                        ((uint8_t)0x08)
#define ADC_AN_9                        ((uint8_t)0x09)
#define ADC_AN_10                       ((uint8_t)0x0A)
#define ADC_AN_11                       ((uint8_t)0x0B)
#define ADC_AN_0_1                      ((uint8_t)0x01)
#define ADC_AN_0_2                      ((uint8_t)0x02)
#define ADC_AN_0_3                      ((uint8_t)0x03)
#define ADC_AN_0_4                      ((uint8_t)0x04)
#define ADC_AN_0_5                      ((uint8_t)0x05)
#define ADC_AN_0_6                      ((uint8_t)0x06)
#define ADC_AN_0_7                      ((uint8_t)0x07)
#define ADC_AN_4_5                      ((uint8_t)0x05)
#define ADC_AN_4_6                      ((uint8_t)0x06)
#define ADC_AN_4_7                      ((uint8_t)0x07)
#define ADC_AN_8_9                      ((uint8_t)0x09)
#define ADC_AN_8_10                     ((uint8_t)0x0A)
#define ADC_AN_8_11                     ((uint8_t)0x0B)
#define IS_ADC_INPUT_CH(param)          (((param) == ADC_AN_0) || \
                                         ((param) == ADC_AN_1) || \
                                         ((param) == ADC_AN_2) || \
                                         ((param) == ADC_AN_3) || \
                                         ((param) == ADC_AN_4) || \
                                         ((param) == ADC_AN_5) || \
                                         ((param) == ADC_AN_6) || \
                                         ((param) == ADC_AN_7) || \
                                         ((param) == ADC_AN_8) || \
                                         ((param) == ADC_AN_9) || \
                                         ((param) == ADC_AN_10) || \
                                         ((param) == ADC_AN_11) || \
                                         ((param) == ADC_AN_0_1) || \
                                         ((param) == ADC_AN_0_2) || \
                                         ((param) == ADC_AN_0_3) || \
                                         ((param) == ADC_AN_0_4) || \
                                         ((param) == ADC_AN_0_5) || \
                                         ((param) == ADC_AN_0_6) || \
                                         ((param) == ADC_AN_0_7) || \
                                         ((param) == ADC_AN_4_5) || \
                                         ((param) == ADC_AN_4_6) || \
                                         ((param) == ADC_AN_4_7) || \
                                         ((param) == ADC_AN_8_9) || \
                                         ((param) == ADC_AN_8_10) || \
                                         ((param) == ADC_AN_8_11))
#endif                          /*(__TMPM332_ADC_H) */

#define ADC_CMP_0                       ((uint16_t)0x0000)
#define ADC_CMP_1                       ((uint16_t)0x0001)
#define IS_ADC_CMP(param)               (((param) == ADC_CMP_0) || \
                                         ((param) == ADC_CMP_1))

#define ADC_REG_08                      ((uint8_t)0x00)
#define ADC_REG_19                      ((uint8_t)0x02)
#define ADC_REG_2A                      ((uint8_t)0x04)
#define ADC_REG_3B                      ((uint8_t)0x06)
#define ADC_REG_4C                      ((uint8_t)0x08)
#define ADC_REG_5D                      ((uint8_t)0x0A)
#define ADC_REG_6E                      ((uint8_t)0x0C)
#define ADC_REG_7F                      ((uint8_t)0x0E)
#define ADC_REG_SP                      ((uint8_t)0x10)
#define IS_ADC_REG(param)               (((param) == ADC_REG_08) || \
                                         ((param) == ADC_REG_19) || \
                                         ((param) == ADC_REG_2A) || \
                                         ((param) == ADC_REG_3B) || \
                                         ((param) == ADC_REG_4C) || \
                                         ((param) == ADC_REG_5D) || \
                                         ((param) == ADC_REG_6E) || \
                                         ((param) == ADC_REG_7F) || \
                                         ((param) == ADC_REG_SP))

#define ADC_EXT_TRG                     ((uint8_t)0x00)
#define ADC_MATCH_TB6RG0                ((uint8_t)0x20)
#define IS_ADC_HW_TRG_NORMAL(param)     (((param) == ADC_EXT_TRG) || \
                                         ((param) == ADC_MATCH_TB6RG0))

#define ADC_MATCH_TB5RG0                ((uint8_t)0x80)
#define IS_ADC_HW_TRG_TOP(param)        (((param) == ADC_EXT_TRG) || \
                                         ((param) == ADC_MATCH_TB5RG0))

#define IS_ADC_CMP_VALUE(param)         ((param) <= (uint16_t)0x03ff)

    typedef enum {
        ADC_NO_OVERRUN = 0,
        ADC_OVERRUN = 1
    } ADC_OverrunState;

    typedef enum {
        ADC_SCAN_4CH = 0,
        ADC_SCAN_8CH = 1
    } ADC_ChannelScanMode;
#define IS_ADC_CH_SCAN_MODE(param)      (((param) == ADC_SCAN_4CH) || \
                                         ((param) == ADC_SCAN_8CH))

    typedef enum {
        ADC_COMPARISON_SMALLER = 0,
        ADC_COMPARISON_LARGER = 1
    } ADC_ComparisonState;
#define IS_ADC_CMP_INT(param)           (((param) == ADC_COMPARISON_SMALLER) || \
                                         ((param) == ADC_COMPARISON_LARGER))

    typedef struct {
        WorkState ADCResultStored;      /*!< ADC result storage flag    */
        ADC_OverrunState ADCOverrunState;       /*!< ADC overrun flag           */
        uint32_t ADCResultValue;        /*!< ADC result value           */
    } ADC_ResultTypeDef;


/** @} */
/* End of group ADC_Exported_Types */

/** @defgroup ADC_Exported_FunctionPrototypes
  * @{
  */
    void ADC_SWReset(void);
    void ADC_SetAccuracy(void);
    void ADC_SetClk(uint32_t Sample_HoldTime, uint32_t Prescaler_Output);
    void ADC_Start(void);
    void ADC_SetScanMode(FunctionalState NewState);
    void ADC_SetRepeatMode(FunctionalState NewState);
    void ADC_SetINTMode(uint8_t INTMode);
    WorkState ADC_GetConvertState(void);
    void ADC_SetInputChannel(uint8_t InputChannel);
    void ADC_SetChannelScanMode(ADC_ChannelScanMode ScanMode);
    void ADC_SetIdleMode(FunctionalState NewState);
    void ADC_SetVref(FunctionalState NewState);
    void ADC_SetInputChannelTop(uint8_t TopInputChannel);
    void ADC_StartTopConvert(void);
    WorkState ADC_GetTopConvertState(void);
    void ADC_SetMonitor(uint16_t ADCMPx, FunctionalState NewState);
    void ADC_SetResultCmpReg(uint16_t ADCMPx, uint8_t ResultComparison);
    void ADC_SetMonitorINT(uint16_t ADCMPx, ADC_ComparisonState NewState);
    void ADC_SetHWTrg(uint8_t HwSource, FunctionalState NewState);
    void ADC_SetHWTrgTop(uint8_t HwSource, FunctionalState NewState);
    ADC_ResultTypeDef ADC_GetConvertResult(uint8_t ADREGx);
    void ADC_SetCmpValue(uint16_t ADCMPx, uint16_t value);

/** @} */
/* End of group ADC_Exported_FunctionPrototypes */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM330_ADC_H) || (__TMPM332_ADC_H) || (__TMPM333_ADC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM330_ADC_H */
