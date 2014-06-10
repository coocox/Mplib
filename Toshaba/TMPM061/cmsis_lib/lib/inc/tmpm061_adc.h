/**
 *******************************************************************************
 * @file    tmpm061_adc.h
 * @brief   This file provides all the functions prototypes for ADC driver.
 * @version V2.0.2.1
 * @date    2012/04/25
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM061_ADC_H
#define __TMPM061_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

#if defined(__TMPM061_ADC_H)

/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */


#define ADC_CONVERSION_35_CLOCK           ((uint8_t)0x00)       /* actually 35.5 clock */
#define ADC_CONVERSION_42_CLOCK           ((uint8_t)0x40)
#define ADC_CONVERSION_68_CLOCK           ((uint8_t)0x80)
#define ADC_CONVERSION_81_CLOCK           ((uint8_t)0xC0)
#define IS_ADC_CONVERSION_TIME(param)   (((param) == ADC_CONVERSION_35_CLOCK) || \
                                         ((param) == ADC_CONVERSION_42_CLOCK) || \
                                         ((param) == ADC_CONVERSION_68_CLOCK) || \
                                         ((param) == ADC_CONVERSION_81_CLOCK))


#define ADC_FC_DIVIDE_LEVEL_1           ((uint8_t)0x00)
#define ADC_FC_DIVIDE_LEVEL_2           ((uint8_t)0x01)
#define ADC_FC_DIVIDE_LEVEL_4           ((uint8_t)0x02)
#define ADC_FC_DIVIDE_LEVEL_8           ((uint8_t)0x03)
#define ADC_FC_DIVIDE_LEVEL_16          ((uint8_t)0x04)
#define IS_ADC_PRESCALER(param)         ((param) <= ADC_FC_DIVIDE_LEVEL_16)


#define ADC_INT_SINGLE                  ((uint8_t)0x00)
#define ADC_INT_CONVERSION_4            ((uint8_t)0x08)
#define ADC_INT_CONVERSION_8            ((uint8_t)0x10)
#define IS_ADC_INT_MODE(param)          (((param) == ADC_INT_SINGLE) || \
                                         ((param) == ADC_INT_CONVERSION_4) || \
                                         ((param) == ADC_INT_CONVERSION_8))

#define ADC_AN_0                        ((uint8_t)0x00)
#define ADC_AN_1                        ((uint8_t)0x01)
#define ADC_AN_2                        ((uint8_t)0x02) /* ch2 is fixed for inner temperature sensor */
#define IS_ADC_INPUT_CH(param)          ((param) <= ADC_AN_2)


#define ADC_REG_0                      ((uint8_t)0x00)
#define ADC_REG_1                      ((uint8_t)0x01)
#define ADC_REG_2                      ((uint8_t)0x02)
#define IS_ADC_REG(param)              ((param) <= ADC_REG_2)

    typedef enum {
        ADC_SCAN_4CH = 0U,
        ADC_SCAN_8CH = 1U,
        ADC_SCAN_12CH = 2U
    } ADC_ChannelScanMode;
#define IS_ADC_CH_SCAN_MODE(param)      ((param) <= ADC_SCAN_12CH)

/**
  * @brief Union to store ADC result
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Stored:1;  /*!< bit0, AD result has been stored */
            uint32_t OverRun:1; /*!< bit1, OverRun, new AD result is stored before the old one been read */
            uint32_t Reserved1:4;       /*!< bit2 to bit5, reserved */
            uint32_t ADResult:10;       /*!< bit6 to bit15, store AD result */
            uint32_t Reserved2:16;      /*!< bit16 to bit31, reserved */
        } Bit;
    } ADC_Result;


/** @} */
/* End of group ADC_Exported_Types */

/** @defgroup ADC_Exported_FunctionPrototypes
  * @{
  */
    void ADC_SWReset(void);
    void ADC_SetClk(uint32_t Conversion_Time, uint32_t Prescaler_Output);
    void ADC_Start(void);
    void ADC_SetScanMode(FunctionalState NewState);
    void ADC_SetRepeatMode(FunctionalState NewState);
    void ADC_SetINTMode(uint8_t INTMode);
    WorkState ADC_GetConvertState(void);
    void ADC_SetInputChannel(uint8_t InputChannel);
    void ADC_SetChannelScanMode(ADC_ChannelScanMode ScanMode);
    void ADC_SetIdleMode(FunctionalState NewState);
    void ADC_SetVref(FunctionalState NewState);
    ADC_Result ADC_GetConvertResult(uint8_t ADREGx);


/** @} */
/* End of group ADC_Exported_FunctionPrototypes */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX00_Periph_Driver */

#endif                          /* (__TMPM061_ADC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM061_ADC_H */
