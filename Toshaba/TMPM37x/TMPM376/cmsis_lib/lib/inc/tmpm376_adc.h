/**
 ****************************************************************************
 * @file    tmpm376_adc.h
 * @brief   This file provides all the functions prototypes for M376 ADC driver.
 * @version V2.0.2.1
 * @date    2012/02/02
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
#ifndef __TMPM376_ADC_H
#define __TMPM376_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM376.h"
#include "tx03_common.h"

#if defined(__TMPM376_ADC_H) || defined(__TMPM377_ADC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/** @addtogroup ADC_Exported_types
  * @{
  */

#define IS_ADC_UNIT(param)          (((param) == TSB_ADA) || ((param) == TSB_ADB))

/* macros to set Analog Input channel or Program number together with its Enable/Disable setting for the trigger registers */
#define TRG_ENABLE(AINx_ProgX)   ((uint8_t)(0x80U | (AINx_ProgX)))
#define TRG_DISABLE(AINx_ProgX)  ((uint8_t)(AINx_ProgX))

#define ADC_HOLD_FIX                ((uint32_t)0x09U << 3U)     /* must write 0b1001 to this area */
#define IS_ADC_SAMPLEHOLD(param)    ((param) == ADC_HOLD_FIX)

    typedef enum {
        ADC_FC_DIVIDE_LEVEL_NONE = 0U,
        ADC_FC_DIVIDE_LEVEL_2 = 1U,
        ADC_FC_DIVIDE_LEVEL_4 = 2U,
        ADC_FC_DIVIDE_LEVEL_8 = 3U,
        ADC_FC_DIVIDE_LEVEL_16 = 4U
    } ADC_PRESCALER;
#define IS_ADC_PRESCALER(param)     ((param) <= ADC_FC_DIVIDE_LEVEL_16)


    typedef enum {
        ADC_TRG_SW = 0U,
        ADC_TRG_CONSTANT = 1U,
        ADC_TRG_TIMER = 2U,
        ADC_TRG_PMD = 3U
    } ADC_TrgType;
#define IS_ADC_TRGTYPE(param)       ((param) <= ADC_TRG_PMD)
#define IS_ADC_START(param)         ((param) <= ADC_TRG_CONSTANT)


    typedef enum {
        ADC_CMPCR_0 = 0U,
        ADC_CMPCR_1 = 1U
    } ADC_CMPCRx;
#define IS_ADC_CMPCRx(param)        ((param) <= ADC_CMPCR_1)


    typedef enum {
        ADC_REG0 = 0U,
        ADC_REG1 = 1U,
        ADC_REG2 = 2U,
        ADC_REG3 = 3U,
        ADC_REG4 = 4U,
        ADC_REG5 = 5U,
        ADC_REG6 = 6U,
        ADC_REG7 = 7U,
        ADC_REG8 = 8U,
        ADC_REG9 = 9U,
        ADC_REG10 = 10U,
        ADC_REG11 = 11U
    } ADC_REGx;
#define IS_ADC_REGx(param)          ((param) <= ADC_REG11)


    typedef enum {
        ADC_LARGER_THAN_CMP_REG = 0U,
        ADC_SMALLER_THAN_CMP_REG = 1U
    } ADC_CmpCondition;
#define IS_ADC_CMPCONDITION(param)   ((param) <= ADC_SMALLER_THAN_CMP_REG)


/**
  * @brief  ADC Monitor Init Structure definition
  */
    typedef struct {

        ADC_CMPCRx CMPCRx;      /*!< Select ADC_CMPCR_0 for ADxCMPCR0 or ADC_CMPCR_1 for ADxCMPCR1  x = A, B */
        ADC_REGx ResultREGx;    /*!< Select which result register among ADC_REG0 to ADC_REG11 will be used */
        uint32_t CmpTimes;      /*!< How many times will Comparison be counted, range from 1 to 16 */
        ADC_CmpCondition Condition;     /*!< Conditon to compare ADxREGm with ADxCMPn. (x = A, B; m = 0 to 11; n = 0, 1) */
        uint32_t CmpValue;      /*!< Comparison value to be set in ADxCMP0 or ADxCMP1, max value is 4095 . (x = A, B) */
    } ADC_MonitorTypeDef;
#define IS_ADC_CMPTIMES(param)  (((param) >= 1U) && ((param) <= 16U))
#define IS_ADC_CMPVALUE_12BIT(param)   ((param) <= 4095U)


    typedef enum {
        PMD_TRG_PROG_SEL0 = 0U,
        PMD_TRG_PROG_SEL1 = 1U,
        PMD_TRG_PROG_SEL2 = 2U,
        PMD_TRG_PROG_SEL3 = 3U,
        PMD_TRG_PROG_SEL4 = 4U,
        PMD_TRG_PROG_SEL5 = 5U,
        PMD_TRG_PROG_SEL6 = 6U,
        PMD_TRG_PROG_SEL7 = 7U,
        PMD_TRG_PROG_SEL8 = 8U,
        PMD_TRG_PROG_SEL9 = 9U,
        PMD_TRG_PROG_SEL10 = 10U,
        PMD_TRG_PROG_SEL11 = 11U
    } PMD_TRG_PROG_SELx;
#define IS_PMD_TRG_PROG_SELx(param)   ((param) <= PMD_TRG_PROG_SEL11)


    typedef enum {
        PMD_PROG0 = 0U,
        PMD_PROG1 = 1U,
        PMD_PROG2 = 2U,
        PMD_PROG3 = 3U,
        PMD_PROG4 = 4U,
        PMD_PROG5 = 5U
    } PMD_PROGx;
#define IS_PMD_PROGx(param)   ((param) <= PMD_PROG5)


/* PMD_PROGx to be set for ADBPSELn, use with macro TRG_ENABLE() and TRG_DISABLE() */
#define IS_PMD_PROGx_ENABLE_DISABLE(param)\
                                 ((((param) >= TRG_ENABLE(PMD_PROG0))  && \
                                   ((param) <= TRG_ENABLE(PMD_PROG5))) || \
                                   ((param) <= TRG_DISABLE(PMD_PROG5)))

    typedef enum {
        PMD_INTNONE = 0U,
        PMD_INTADPDA = 1U,
        PMD_INTADPDB = 2U
    } PMD_INT_NAME;
#define IS_PMD_INT_NAME(param)   ((param) <= PMD_INTADPDB)


    /*!< to select and set the interrupt to be generated for PMD_PROG0 to PMD_PROG5 */
    typedef struct {
        PMD_INT_NAME INTProg0;
        PMD_INT_NAME INTProg1;
        PMD_INT_NAME INTProg2;
        PMD_INT_NAME INTProg3;
        PMD_INT_NAME INTProg4;
        PMD_INT_NAME INTProg5;
    } PMD_TrgProgINTTypeDef;

    typedef enum {
        ADC_AIN0 = 0U,          /*!< define for Analog Input channel */
        ADC_AIN1 = 1U,
        ADC_AIN2 = 2U,
        ADC_AIN3 = 3U,
        ADC_AIN4 = 4U,
        ADC_AIN5 = 5U,
        ADC_AIN6 = 6U,
        ADC_AIN7 = 7U,
        ADC_AIN8 = 8U,
        ADC_AIN9 = 9U,
        ADC_AIN10 = 10U,
        ADC_AIN11 = 11U,
        ADC_AIN12 = 12U,        /*!< Unit B only */
    } ADC_AINx;

#if defined(__TMPM376_ADC_H)
/* Analog Input channel to be set for trigger register, use with macro TRG_ENABLE() and TRG_DISABLE() */
/* AINA: 12channels. 0,1,2, ....11 */
/* AINB: 13channels. 0,1,2, ....12 */
#define IS_UNIT_A_AINx(param)   ((((param) >= TRG_ENABLE(ADC_AIN0))   && \
                                  ((param) <= TRG_ENABLE(ADC_AIN11))) || \
                                  ((param) <= TRG_DISABLE(ADC_AIN11)))

#define IS_UNIT_B_AINx(param)   ((((param) >= TRG_ENABLE(ADC_AIN0))   && \
                                  ((param) <= TRG_ENABLE(ADC_AIN12))) || \
                                  ((param) <= TRG_DISABLE(ADC_AIN12)))
#else  /* M377 */
/* Analog Input channel to be set for trigger register, use with macro TRG_ENABLE() and TRG_DISABLE() */
/* AINA: 7channels. 5,6,7,..11  */
/* AINB: 8channels. 0,1,2,...7  */
#define IS_UNIT_A_AINx(param)   ((((param) >=   TRG_ENABLE(ADC_AIN5))   && \
                                  ((param) <=   TRG_ENABLE(ADC_AIN11))) || \
                                 ((((param) >= TRG_DISABLE(ADC_AIN5)) && \
                                  ((param) <= TRG_DISABLE(ADC_AIN11)))))

#define IS_UNIT_B_AINx(param)   ((((param) >= TRG_ENABLE(ADC_AIN0))  && \
                                  ((param) <= TRG_ENABLE(ADC_AIN7))) || \
                                  ((param) <= TRG_DISABLE(ADC_AIN7)))

#endif


    typedef enum {
        VE_PHASE_NONE = 0U,
        VE_PHASE_U = 1U,
        VE_PHASE_V = 2U,
        VE_PHASE_W = 3U
    } VE_PHASE;
#define IS_VE_PHASE(param)      ((param) <= VE_PHASE_W)

/**
  * @brief ADC PMD Trigger Program Register Setting Structure definition
  *   Reg0_AINx to Reg3_AINx must be inputed with macro as the format below:
  *     TRG_ENABLE(y), TRG_DISABLE(y).
  *   'y' above can be one of the following values:
  *     ADC unit A: ADC_AIN0 to ADC_AIN11
  *     ADC unit B: ADC_AIN0 to ADC_AIN12
  */
    typedef struct {            /* in ADxPSETn below: (x = A, B; n = 0 to 5) */
        PMD_PROGx ProgNum;      /*!< select PMD_PROG0 to PMD_PROG5 for ADxPSETn  */
        VE_PHASE Reg0_Phase;    /*!< select phase for REG0 in ADxPSETn */
        VE_PHASE Reg1_Phase;    /*!< select phase for REG1 in ADxPSETn */
        VE_PHASE Reg2_Phase;    /*!< select phase for REG2 in ADxPSETn */
        VE_PHASE Reg3_Phase;    /*!< select phase for REG3 in ADxPSETn */
        uint8_t Reg0_AINx;      /*!< select Analog Input channel together with its enabled or disabled setting for REG0 in ADxPSETn */
        uint8_t Reg1_AINx;      /*!< For REG1 in ADxPSETn. Other information is same as above. */
        uint8_t Reg2_AINx;      /*!< For REG2 in ADxPSETn. Other information is same as above. */
        uint8_t Reg3_AINx;      /*!< For REG3 in ADxPSETn. Other information is same as above. */
    } PMD_TrgTypeDef;

/**
  * @brief Union to store ADC result
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Stored:1;  /*!< bit0, AD result has been stored */
            uint32_t OverRun:1; /*!< bit1, OverRun, new AD result is stored before the old one been read */
            uint32_t Reserved1:2;       /*!< bit2 to bit3, reserved */
            uint32_t ADResult:12;       /*!< bit4 to bit15, store AD result */
            uint32_t Reserved2:16;      /*!< bit16 to bit31, reserved */
        } Bit;
    } ADC_Result;

/** @} */
/* End of group ADC_Exported_types */

/** @defgroup ADC_Exported_FunctionPrototypes
  * @{
  */
    void ADC_SetClk(TSB_AD_TypeDef * ADx, uint32_t Sample_HoldTime, ADC_PRESCALER Prescaler_Output);
    void ADC_Enable(TSB_AD_TypeDef * ADx);
    void ADC_Disable(TSB_AD_TypeDef * ADx);
    void ADC_Start(TSB_AD_TypeDef * ADx, ADC_TrgType Trg);
    void ADC_StopConstantTrg(TSB_AD_TypeDef * ADx);
    WorkState ADC_GetConvertState(TSB_AD_TypeDef * ADx, ADC_TrgType Trg);
    void ADC_SetMonitor(TSB_AD_TypeDef * ADx, ADC_MonitorTypeDef * Monitor);
    void ADC_DisableMonitor(TSB_AD_TypeDef * ADx, ADC_CMPCRx CMPCRx);
    ADC_Result ADC_GetConvertResult(TSB_AD_TypeDef * ADx, ADC_REGx ResultREGx);
    void ADC_SelectPMDTrgProgNum(TSB_AD_TypeDef * ADx, PMD_TRG_PROG_SELx SELx,
                                 uint8_t MacroProgNum);
    void ADC_SetPMDTrgProgINT(TSB_AD_TypeDef * ADx, PMD_TrgProgINTTypeDef * TrgProgINT);
    void ADC_SetPMDTrg(TSB_AD_TypeDef * ADx, PMD_TrgTypeDef * PMDTrg);
    void ADC_SetTimerTrg(TSB_AD_TypeDef * ADx, ADC_REGx ResultREGx, uint8_t MacroAINx);
    void ADC_SetSWTrg(TSB_AD_TypeDef * ADx, ADC_REGx ResultREGx, uint8_t MacroAINx);
    void ADC_SetConstantTrg(TSB_AD_TypeDef * ADx, ADC_REGx ResultREGx, uint8_t MacroAINx);

/** @} */
/* End of group ADC_Exported_FunctionPrototypes */

/** @} */
/* End of group ADC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM376_ADC_H) || defined(__TMPM377_ADC_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /*__TMPM376_ADC_H */
