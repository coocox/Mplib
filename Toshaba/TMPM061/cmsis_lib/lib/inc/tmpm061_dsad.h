/**
 *******************************************************************************
 * @file    tmpm061_DSADC.h
 * @brief   This file provides all the functions prototypes for DSADC driver.
 * @version V2.0.2.1
 * @date    2013/04/16
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
#ifndef __TMPM061_DSDSADC_H
#define __TMPM061_DSDSADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @addtogroup DSADC
  * @{
  */

/** @defgroup DSADC_Exported_Types
  * @{
  */

#define IS_DSADC_PERIPH(param)       (((param) == TSB_DSAD0)  || \
                                     ((param) == TSB_DSAD1)  || \
                                     ((param) == TSB_DSAD2))
#define     DSADC_FC_DIVIDE_LEVEL_1         0x00U
#define     DSADC_FC_DIVIDE_LEVEL_2         0x01U
#define     DSADC_FC_DIVIDE_LEVEL_4         0x02U
#define     DSADC_FC_DIVIDE_LEVEL_8         0x03U
#define     IS_DSADC_CLOCK_SEL(param)      ((param) <= DSADC_FC_DIVIDE_LEVEL_8)

#define     DSADC_GAIN_1x           0x00U
#define     DSADC_GAIN_2x           0x01U
#define     DSADC_GAIN_4x           0x02U
#define     DSADC_GAIN_8x           0x03U
#define     DSADC_GAIN_16x          0x04U

#define     IS_DSADC_GAIN(param)            ((param) <= DSADC_GAIN_16x)
#define     DSADC_A_SYNC_MODE               0x00U
#define     DSADC_SYNC_MODE                 0x01U
#define     DSADC_SINGLE_MODE               0x00U
#define     DSADC_REPEAT_MODE               0x01U
#define     IS_DSADC_1BIT_CHECK(param)      ((param) <= 1U)

    typedef struct {
        uint8_t Clk;
        uint8_t BiasEn;
        uint8_t ModulatorEn;
        uint8_t SyncMode;
        uint8_t Repeatmode;
        uint8_t Amplifier;
        uint16_t Offset;
        uint8_t CorrectEn;
    } DSADC_InitTypeDef;

    typedef union {
        uint32_t All;
        struct {
            uint32_t F_Overrun:1;
            uint32_t F_ResultStore:1;
            uint32_t F_ConvertEnd:1;
            uint32_t F_Convert:1;
            uint32_t Reserved:4;
            uint32_t ConversionResult:24;
        } Bit;
    } DSAD_status;


/** @} */
/* End of group DSADC_Exported_Types */

/** @defgroup DSADC_Exported_FunctionPrototypes
  * @{
  */
    void DSADC_SetClk(TSB_DSAD_TypeDef * DSADCx, uint32_t Clk);
    void DSADC_SWReset(TSB_DSAD_TypeDef * DSADCx);
    void DSADC_Start(TSB_DSAD_TypeDef * DSADCx);
    void DSADC_ChangeMode(TSB_DSAD_TypeDef * DSADCx, uint8_t SyncMode, uint8_t ConvMode);
    void DSADC_SetAmplifier(TSB_DSAD_TypeDef * DSADCx, uint32_t Amplifier);
    uint32_t DSADC_GetConvertResult(TSB_DSAD_TypeDef * DSADCx);
    void DSADC_Init(TSB_DSAD_TypeDef * DSADCx, DSADC_InitTypeDef * InitStruct);
    DSAD_status DSADC_GetStatus(TSB_DSAD_TypeDef * DSADCx);
    void DSADC_SetClkSupply(TSB_DSAD_TypeDef * DSADCx, FunctionalState NewState);

/** @} */
/* End of group DSADC_Exported_FunctionPrototypes */

/** @} */
/* End of group DSADC */

/** @} */
/* End of group TX00_Periph_Driver */


#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM061_DSDSADC_H */
