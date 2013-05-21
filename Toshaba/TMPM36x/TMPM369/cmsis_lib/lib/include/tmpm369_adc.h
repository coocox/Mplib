/**
 *******************************************************************************
 * @file    tmpm369_adc.h
 * @brief   This file provides all the functions prototypes for ADC driver.
 * @version V2.0.2.2
 * @date    2011/09/07
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
#ifndef __TMPM369_ADC_H
#define __TMPM369_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
#include "tx03_common.h"

#if defined(__TMPM369_ADC_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */
#define IS_ADC_UNIT(param)          (((param) == TSB_ADA) || ((param) == TSB_ADB))

#define ADC_CONVERSION_CLK_10           ((uint32_t)0x00U)
#define ADC_CONVERSION_CLK_20           ((uint32_t)0x10U)
#define ADC_CONVERSION_CLK_30           ((uint32_t)0x20U)
#define ADC_CONVERSION_CLK_40           ((uint32_t)0x30U)
#define ADC_CONVERSION_CLK_80           ((uint32_t)0x40U)
#define ADC_CONVERSION_CLK_160			((uint32_t)0x50U)
#define ADC_CONVERSION_CLK_320			((uint32_t)0x60U)
#define IS_ADC_HOLD_TIME(param)         (((param) == ADC_CONVERSION_CLK_10) || \
                                         ((param) == ADC_CONVERSION_CLK_20) || \
                                         ((param) == ADC_CONVERSION_CLK_30) || \
                                         ((param) == ADC_CONVERSION_CLK_40) || \
                                         ((param) == ADC_CONVERSION_CLK_80) || \
                                         ((param) == ADC_CONVERSION_CLK_160)|| \
                                         ((param) == ADC_CONVERSION_CLK_320))

#define ADC_FC_DIVIDE_LEVEL_1           ((uint32_t)0x00U)
#define ADC_FC_DIVIDE_LEVEL_2           ((uint32_t)0x01U)
#define ADC_FC_DIVIDE_LEVEL_4           ((uint32_t)0x02U)
#define ADC_FC_DIVIDE_LEVEL_8           ((uint32_t)0x03U)
#define ADC_FC_DIVIDE_LEVEL_16          ((uint32_t)0x04U)
#define IS_ADC_PRESCALER(param)         ((param) <= ADC_FC_DIVIDE_LEVEL_16)

/* Interrupt generation timing in fixed channel mode */
#define ADC_INT_SINGLE                  ((uint32_t)0x00U)
#define ADC_INT_CONVERSION_2            ((uint32_t)0x10U)
#define ADC_INT_CONVERSION_3            ((uint32_t)0x20U)
#define ADC_INT_CONVERSION_4            ((uint32_t)0x30U)
#define ADC_INT_CONVERSION_5            ((uint32_t)0x40U)
#define ADC_INT_CONVERSION_6            ((uint32_t)0x50U)
#define ADC_INT_CONVERSION_7            ((uint32_t)0x60U)
#define ADC_INT_CONVERSION_8            ((uint32_t)0x70U)
#define IS_ADC_INT_MODE(param)          (((param) == ADC_INT_SINGLE) || \
                                         ((param) == ADC_INT_CONVERSION_2) || \
                                         ((param) == ADC_INT_CONVERSION_3) || \
                                         ((param) == ADC_INT_CONVERSION_4) || \
                                         ((param) == ADC_INT_CONVERSION_5) || \
                                         ((param) == ADC_INT_CONVERSION_6) || \
                                         ((param) == ADC_INT_CONVERSION_7) || \
                                         ((param) == ADC_INT_CONVERSION_8))

    typedef enum {
        ADC_AN_00 = 0U,         /*!< define for Analog Input channel */
        ADC_AN_01 = 1U,
        ADC_AN_02 = 2U,
        ADC_AN_03 = 3U,
        ADC_AN_04 = 4U,
        ADC_AN_05 = 5U,
        ADC_AN_06 = 6U,
        ADC_AN_07 = 7U,
        ADC_AN_08 = 8U,
        ADC_AN_09 = 9U,
        ADC_AN_10 = 10U,
        ADC_AN_11 = 11U
    } ADC_AINx;

#define IS_ADCA_INPUT_CHANNEL(param)     ((param) <= ADC_AN_03)
#define IS_ADCA_SCAN_CHANNEL(start, range)     (((start) <= ADC_AN_03) && \
                                                 ((range) >= 1U) && \
                                                (((start) + (range)) <= 4U))

#define IS_ADCB_INPUT_CHANNEL(param)     ((param) <= ADC_AN_11)
#define IS_ADCB_SCAN_CHANNEL(start, range)      (((start) <= ADC_AN_11) && \
                                                 ((range) >= 1U) && \
                                                (((start) + (range)) <= 12U))

    typedef enum {
        ADC_REG00 = 0U,
        ADC_REG01 = 1U,
        ADC_REG02 = 2U,
        ADC_REG03 = 3U,
        ADC_REG04 = 4U,
        ADC_REG05 = 5U,
        ADC_REG06 = 6U,
        ADC_REG07 = 7U,
        ADC_REG08 = 8U,
        ADC_REG09 = 9U,
        ADC_REG10 = 10U,
        ADC_REG11 = 11U,
        ADC_REG_SP = 12U
    } ADC_REGx;

#define IS_ADCA_REG(param)    (((param) <= ADC_REG07) || ((param) == ADC_REG_SP))
#define IS_ADCB_REG(param)    ( (param) <= ADC_REG_SP)

#define ADC_APPLY_VREF_IN_CONVERSION    ((uint32_t)0x00U)
#define ADC_APPLY_VREF_AT_ANY_TIME      ((uint32_t)0x01U)
#define IS_ADC_VREF_CTRL(param)         (((param) == ADC_APPLY_VREF_IN_CONVERSION) || \
                                         ((param) == ADC_APPLY_VREF_AT_ANY_TIME))

    typedef enum {
        ADC_CMPCR_0 = 0U,
        ADC_CMPCR_1 = 1U
    } ADC_CMPCRx;
#define IS_ADC_CMPCRx(param)            ((param) <= ADC_CMPCR_1)

#define ADC_INTERLEAVE					((uint32_t)0x00U)
#define IS_ADC_INTERLEAVE(param)		((param) == ADC_INTERLEAVE)
#define IS_ADC_INTERLEAVE_TOP(param)	((param) == ADC_INTERLEAVE)

#define ADC_DUALUNIT_TRG_START_MODE		((uint32_t)0x00U)
#define ADC_DUALUNIT_INTERLEAVE_MODE	((uint32_t)0x01U)
#define IS_ADC_DUALUNIT_CONTROL_MODE(param)	(((param) == ADC_DUALUNIT_TRG_START_MODE) || \
										     ((param) == ADC_DUALUNIT_INTERLEAVE_MODE))

    typedef enum {
        ADC_DUALUNIT_SW = 0U,
        ADC_DUALUNIT_EXT = 1U,
        ADC_DUALUNIT_INTTB21 = 2U,
        ADC_DUALUNIT_INTTB31 = 3U,
        ADC_DUALUNIT_INTTB41 = 4U,
        ADC_DUALUNIT_INTTB51 = 5U,
        ADC_DUALUNIT_INTTB61 = 6U,
        ADC_DUALUNIT_INTTB71 = 7U
    } ADC_DualUnitTrg;
#define IS_ADC_DUALUNIT_TRG_INPUT(param)  ((param) <= ADC_DUALUNIT_INTTB71)

#define IS_ADC_DUALUNIT_ADJUST_COUNT(param) (((param) >= 1U) && ((param) <= 255U))

    typedef enum {
        ADC_DUALUNIT_UNIT_A = 0U,
        ADC_DUALUNIT_UNIT_B = 1U
    } ADC_DualUnit_Unitx;
#define IS_ADC_DUALUNIT_UNITx(param)	((param) <=  ADC_DUALUNIT_UNIT_B)

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
        ADC_AINx CmpChannel;    /*!< Select which ADC channel will be used */
        uint32_t CmpCnt;        /*!< How many times will valid comparisons be counted, range from 1 to 16 */
        ADC_CmpCondition Condition;     /*!< Condition to compare ADC channel with Compare Register */
        ADC_CmpCntMode CntMode; /*!< Mode to compare ADC channel with Compare Register */
        uint32_t CmpValue;      /*!< Comparison value to be set in Compare Register, max value is 4095 */
    } ADC_MonitorTypeDef;

#define IS_ADC_CMPCNT(param)            (((param) >= 1U) && ((param) <= 16U))
#define IS_ADC_CMPVALUE_12BIT(param)    ((param) <= 4095U)

/**
  * @brief Union to store ADC state
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t NormalBusy:1;      /*!< bit0, Normal A/D conversion busy flag (ADBF) */
            uint32_t NormalComplete:1;  /*!< bit1, Normal AD conversion complete flag (EOCF) */
            uint32_t TopBusy:1; /*!< bit2, Top-priority A/D conversion busy flag (HPADBF) */
            uint32_t TopComplete:1;     /*!< bit3, Top-priority AD conversion complete flag (HPEOCF) */
            uint32_t Reserved:28;       /*!< bit4 to bit 31, reserved */
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
            uint32_t Reserved:18;       /*!< bit14 to bit31, reserved */
        } Bit;
    } ADC_Result;


/** @} */
/* End of group ADC_Exported_Types */

/** @defgroup ADC_Exported_FunctionPrototypes
  * @{
  */

    void ADC_SWReset(TSB_AD_TypeDef * ADx);
    void ADC_SetClk(TSB_AD_TypeDef * ADx, uint32_t Sample_HoldTime, uint32_t Prescaler_Output);
    void ADC_Start(TSB_AD_TypeDef * ADx);
    void ADC_SetScanMode(TSB_AD_TypeDef * ADx, FunctionalState NewState);
    void ADC_SetRepeatMode(TSB_AD_TypeDef * ADx, FunctionalState NewState);
    void ADC_SetINTMode(TSB_AD_TypeDef * ADx, uint32_t INTMode);
    void ADC_SetInputChannel(TSB_AD_TypeDef * ADx, ADC_AINx InputChannel);
    void ADC_SetScanChannel(TSB_AD_TypeDef * ADx, ADC_AINx StartChannel, uint32_t Range);
    void ADC_SetVrefCut(TSB_AD_TypeDef * ADx, uint32_t VrefCtrl);
    void ADC_SetIdleMode(TSB_AD_TypeDef * ADx, FunctionalState NewState);
    void ADC_SetVref(TSB_AD_TypeDef * ADx, FunctionalState NewState);
    void ADC_SetInputChannelTop(TSB_AD_TypeDef * ADx, ADC_AINx TopInputChannel);
    void ADC_StartTopConvert(TSB_AD_TypeDef * ADx);
    void ADC_SetMonitor(TSB_AD_TypeDef * ADx, ADC_CMPCRx ADCMPx, FunctionalState NewState);
    void ADC_ConfigMonitor(TSB_AD_TypeDef * ADx, ADC_CMPCRx ADCMPx, ADC_MonitorTypeDef * Monitor);
    void ADC_SetHWTrg(TSB_AD_TypeDef * ADx, uint32_t HWSrc, FunctionalState NewState);
    void ADC_SetHWTrgTop(TSB_AD_TypeDef * ADx, uint32_t HWSrc, FunctionalState NewState);
    ADC_State ADC_GetConvertState(TSB_AD_TypeDef * ADx);
    ADC_Result ADC_GetConvertResult(TSB_AD_TypeDef * ADx, ADC_REGx ADREGx);
    void ADC_SetClkSupply(FunctionalState NewState);
    void ADC_DualUnitSetTrg(FunctionalState NewState);
    void ADC_DualUnitStartSWTrg(void);
    void ADC_DualUnitSetCtrlMode(uint32_t Mode);
    ADC_DualUnit_Unitx ADC_DualUnitGetNextTrgDst(void);
    void ADC_DualUnitSetTrgSrc(ADC_DualUnitTrg Trg);
    void ADC_DualUnitSetAdjustingCnt(uint32_t AdjustCnt);


/** @} */
/* End of group ADC_Exported_FunctionPrototypes */
/** @} */
/* End of group ADC */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM369_ADC_H) */
#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM369_ADC_H */
