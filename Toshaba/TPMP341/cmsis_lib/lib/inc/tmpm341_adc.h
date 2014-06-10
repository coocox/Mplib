/**
 *******************************************************************************
 * @file    tmpm341_adc.h
 * @brief   This file provides all the functions prototypes for ADC driver.
 * @version V2.0.2.1
 * @date    2011/03/11
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
#ifndef __TMPM341_ADC_H
#define __TMPM341_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_ADC_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */

#define ADC_CONVERSION_CLK_10           ((uint8_t)0x00)
#define ADC_CONVERSION_CLK_20           ((uint8_t)0x10)
#define ADC_CONVERSION_CLK_30           ((uint8_t)0x20)
#define ADC_CONVERSION_CLK_40           ((uint8_t)0x30)
#define ADC_CONVERSION_CLK_80           ((uint8_t)0x40)
#define IS_ADC_HOLD_TIME(param)         (((param) == ADC_CONVERSION_CLK_10) || \
                                         ((param) == ADC_CONVERSION_CLK_20) || \
                                         ((param) == ADC_CONVERSION_CLK_30) || \
                                         ((param) == ADC_CONVERSION_CLK_40) || \
                                         ((param) == ADC_CONVERSION_CLK_80))

#define ADC_FC_DIVIDE_LEVEL_1           ((uint8_t)0x00)
#define ADC_FC_DIVIDE_LEVEL_2           ((uint8_t)0x01)
#define ADC_FC_DIVIDE_LEVEL_4           ((uint8_t)0x02)
#define ADC_FC_DIVIDE_LEVEL_8           ((uint8_t)0x03)
#define IS_ADC_PRESCALER(param)         ((param) <= ADC_FC_DIVIDE_LEVEL_8)

#define ADC_INT_SINGLE                  ((uint8_t)0x00)
#define ADC_INT_CONVERSION_2            ((uint8_t)0x10)
#define ADC_INT_CONVERSION_3            ((uint8_t)0x20)
#define ADC_INT_CONVERSION_4            ((uint8_t)0x30)
#define ADC_INT_CONVERSION_5            ((uint8_t)0x40)
#define ADC_INT_CONVERSION_6            ((uint8_t)0x50)
#define ADC_INT_CONVERSION_7            ((uint8_t)0x60)
#define ADC_INT_CONVERSION_8            ((uint8_t)0x70)
#define IS_ADC_INT_MODE(param)          (((param) == ADC_INT_SINGLE) || \
                                         ((param) == ADC_INT_CONVERSION_2) || \
                                         ((param) == ADC_INT_CONVERSION_3) || \
                                         ((param) == ADC_INT_CONVERSION_4) || \
                                         ((param) == ADC_INT_CONVERSION_5) || \
                                         ((param) == ADC_INT_CONVERSION_6) || \
                                         ((param) == ADC_INT_CONVERSION_7) || \
                                         ((param) == ADC_INT_CONVERSION_8))

#define ADC_AN_00                       ((uint8_t)0x00)
#define ADC_AN_01                       ((uint8_t)0x01)
#define ADC_AN_02                       ((uint8_t)0x02)
#define ADC_AN_03                       ((uint8_t)0x03)
#define ADC_AN_04                       ((uint8_t)0x04)
#define ADC_AN_05                       ((uint8_t)0x05)
#define ADC_AN_06                       ((uint8_t)0x06)
#define ADC_AN_07                       ((uint8_t)0x07)
#define ADC_AN_08                       ((uint8_t)0x08)
#define ADC_AN_09                       ((uint8_t)0x09)
#define ADC_AN_10                       ((uint8_t)0x0A)
#define ADC_AN_11                       ((uint8_t)0x0B)
#define ADC_AN_12                       ((uint8_t)0x0C)
#define ADC_AN_13                       ((uint8_t)0x0D)
#define ADC_AN_14                       ((uint8_t)0x0E)
#define IS_ADC_INPUT_CHANNEL(param)     ((param) <= ADC_AN_14)

#define IS_ADC_SCAN_CHANNEL(start, range)       (((start) <= ADC_AN_14) && \
                                                 ((range) >= 1U) && \
                                                (((start) + (range)) <= 15U))

#define ADC_REG_00                      ((uint8_t)0x00)
#define ADC_REG_01                      ((uint8_t)0x01)
#define ADC_REG_02                      ((uint8_t)0x02)
#define ADC_REG_03                      ((uint8_t)0x03)
#define ADC_REG_04                      ((uint8_t)0x04)
#define ADC_REG_05                      ((uint8_t)0x05)
#define ADC_REG_06                      ((uint8_t)0x06)
#define ADC_REG_07                      ((uint8_t)0x07)
#define ADC_REG_08                      ((uint8_t)0x08)
#define ADC_REG_09                      ((uint8_t)0x09)
#define ADC_REG_10                      ((uint8_t)0x0A)
#define ADC_REG_11                      ((uint8_t)0x0B)
#define ADC_REG_12                      ((uint8_t)0x0C)
#define ADC_REG_13                      ((uint8_t)0x0D)
#define ADC_REG_14                      ((uint8_t)0x0E)
#define ADC_REG_SP                      ((uint8_t)0x0F)
#define IS_ADC_REG(param)               ((param) <= ADC_REG_SP)

#define ADC_EXT_TRG                     ((uint8_t)0x00)
#define ADC_MATCH_TB5RG0                ((uint8_t)0x02)
#define IS_ADC_HW_TRG_NORMAL(param)     (((param) == ADC_EXT_TRG) || \
                                         ((param) == ADC_MATCH_TB5RG0))

#define ADC_MATCH_TB4RG0                ((uint8_t)0x08)
#define IS_ADC_HW_TRG_TOP(param)        (((param) == ADC_EXT_TRG) || \
                                         ((param) == ADC_MATCH_TB4RG0))

#define ADC_APPLY_VREF_IN_CONVERSION    ((uint8_t)0x00)
#define ADC_APPLY_VREF_AT_ANY_TIME      ((uint8_t)0x01)
#define IS_ADC_VREF_CTRL(param)         (((param) == ADC_APPLY_VREF_IN_CONVERSION) || \
                                         ((param) == ADC_APPLY_VREF_AT_ANY_TIME))

    typedef enum {
        ADC_CMPCR_0 = 0U,
        ADC_CMPCR_1 = 1U
    } ADC_CMPCRx;
#define IS_ADC_CMPCRx(param)            ((param) <= ADC_CMPCR_1)

    typedef enum {
        ADC_LARGER_THAN_CMP_REG = 0U,
        ADC_SMALLER_THAN_CMP_REG = 1U
    } ADC_CmpCondition;
#define IS_ADC_CMPCONDITION(param)      ((param) <= ADC_SMALLER_THAN_CMP_REG)

    typedef enum {
        ADC_SEQUENCE_CMP_MODE = 0U,
        ADC_CUMULATION_CMP_MODE = 1U
    } ADC_CmpCntMode;
#define IS_ADC_CMPMODE(param)           ((param) <= ADC_CUMULATION_CMP_MODE)

/**
  * @brief  ADC Monitor Configuration Structure definition
  */
    typedef struct {
        uint8_t CmpChannel;     /*!< Select which ADC channel among ADC_AN_00 to ADC_AN_14 will be used */
        uint32_t CmpCnt;        /*!< How many times will valid comparisons be counted, range from 1 to 16 */
        ADC_CmpCondition Condition;     /*!< Conditon to compare AINx with ADCMPy. (x = 00 to 14, y = 0 to 1) */
        ADC_CmpCntMode CntMode; /*!< Mode to compare AINx with ADCMPy. (x = 00 to 14, y = 0 to 1) */
        uint32_t CmpValue;      /*!< Comparison value to be set in ADCMP0 or ADCMP1, max value is 4095 */
    } ADC_MonitorTypeDef;

#define IS_ADC_CMPCNT(param)            (((param) >= 1U) && ((param) <= 16U))
#define IS_ADC_CMPVALUE_12BIT(param)    ((param) <= 4095U)

/**
  * @brief Union to store ADC state
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Reserved0:1;       /*!< bit0, reserved */
            uint32_t NormalComplete:1;  /*!< bit1, normal AD conversion complete flag */
            uint32_t Reserved1:1;       /*!< bit2, reserved */
            uint32_t TopComplete:1;     /*!< bit3, top-priority AD conversion complete flag */
            uint32_t Reserved2:28;      /*!< bit4 to bit 31, reserved */
        } Bit;
    } ADC_State;

/**
  * @brief Union to store ADC result
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t ADResult:12;       /*!< bit0 to bit11, store AD result */
            uint32_t Stored:1;  /*!< bit12, AD result has been stored */
            uint32_t OverRun:1; /*!< bit13, new AD result is stored before the old one is read */
            uint32_t OutputSwitching:1; /*!< bit14, The output switching flag of AIN port */
            uint32_t Reserved:17;       /*!< bit15 to bit31, reserved */
        } Bit;
    } ADC_Result;

#define ADC_DMA_REQ_NORMAL              ((uint8_t)0x00)
#define ADC_DMA_REQ_TOP                 ((uint8_t)0x01)
#define IS_ADC_DMA_REQ(param)           ((param) <= ADC_DMA_REQ_TOP)

/** @} */
/* End of group ADC_Exported_Types */

/** @defgroup ADC_Exported_FunctionPrototypes
  * @{
  */
    void ADC_SWReset(void);
    void ADC_SetClk(uint32_t Sample_HoldTime, uint32_t Prescaler_Output);
    void ADC_Start(void);
    void ADC_SetScanMode(FunctionalState NewState);
    void ADC_SetRepeatMode(FunctionalState NewState);
    void ADC_SetINTMode(uint8_t INTMode);
    void ADC_SetInputChannel(uint8_t InputChannel);
    void ADC_SetScanChannel(uint8_t StartChannel, uint8_t Range);
    void ADC_SetVrefCut(uint8_t VrefCtrl);
    void ADC_SetIdleMode(FunctionalState NewState);
    void ADC_SetVref(FunctionalState NewState);
    void ADC_SetInputChannelTop(uint8_t TopInputChannel);
    void ADC_StartTopConvert(void);
    void ADC_SetMonitor(ADC_CMPCRx ADCMPx, FunctionalState NewState);
    void ADC_ConfigMonitor(ADC_CMPCRx ADCMPx, ADC_MonitorTypeDef * Monitor);
    void ADC_SetHWTrg(uint8_t HwSource, FunctionalState NewState);
    void ADC_SetHWTrgTop(uint8_t HwSource, FunctionalState NewState);
    ADC_State ADC_GetConvertState(void);
    ADC_Result ADC_GetConvertResult(uint8_t ADREGx);
    void ADC_SetClkSupply(FunctionalState NewState);
    void ADC_SetDMAReq(uint8_t DMAReq, FunctionalState NewState);

/** @} */
/* End of group ADC_Exported_FunctionPrototypes */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_ADC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM341_ADC_H */
