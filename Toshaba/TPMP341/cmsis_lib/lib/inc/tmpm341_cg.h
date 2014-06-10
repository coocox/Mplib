/**
 *******************************************************************************
 * @file    TMPM341_cg.h
 * @brief   This file provides all the functions prototypes for CG driver.
 * @version V2.0.2.5
 * @date    2011/03/23
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
#ifndef __TMPM341_CG_H
#define __TMPM341_CG_H


#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_CG_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup CG
  * @{
  */

/** @addtogroup CG_Exported_types
  * @{
  */

    typedef enum {
        CG_DIVIDE_1 = 0U,
        CG_DIVIDE_2 = 1U,
        CG_DIVIDE_4 = 2U,
        CG_DIVIDE_8 = 3U,
        CG_DIVIDE_16 = 4U,
        CG_DIVIDE_32 = 5U,
        CG_DIVIDE_64 = 6U,
        CG_DIVIDE_128 = 7U,
        CG_DIVIDE_256 = 8U,
        CG_DIVIDE_512 = 9U,
        CG_DIVIDE_UNKNOWN = 10U,
        CG_DIVIDE_MAX = 11U
    } CG_DivideLevel;
#define IS_CG_GEAR_DIVIDE_LEVEL(param)  (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8) || \
                                         ((param) == CG_DIVIDE_16))

#define IS_CG_DIVIDE_FC_LEVEL(param)    (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8) || \
                                         ((param) == CG_DIVIDE_16)|| \
                                         ((param) == CG_DIVIDE_32) || \
                                         ((param) == CG_DIVIDE_64) || \
                                         ((param) == CG_DIVIDE_128) || \
                                         ((param) == CG_DIVIDE_256) || \
                                         ((param) == CG_DIVIDE_512))


    typedef enum {
        CG_FOSC_OSC_EXT = 0U,
        CG_FOSC_OSC_INT = 1U,
        CG_FOSC_CLKIN_EXT = 2U,
    } CG_FoscSrc;
#define IS_CG_FOSC_SRC(param)           (((param) == CG_FOSC_OSC_EXT) || \
                                         ((param) == CG_FOSC_OSC_INT) || \
                                         ((param) == CG_FOSC_CLKIN_EXT))
#define IS_CG_FOSC_STATE(param)         (((param) == CG_FOSC_OSC_EXT) || \
                                         ((param) == CG_FOSC_OSC_INT) )

    typedef enum {
        CG_SCOUT_SRC_UNKNOWN = 0U,
        CG_SCOUT_SRC_HALF_FSYS = 1U,
        CG_SCOUT_SRC_FSYS = 2U,
        CG_SCOUT_SRC_PHIT0 = 3U
    } CG_SCOUTSrc;
#define IS_CG_SCOUT_SRC(param)        (((param) == CG_SCOUT_SRC_HALF_FSYS) || \
                                       ((param) == CG_SCOUT_SRC_FSYS) || \
                                       ((param) == CG_SCOUT_SRC_PHIT0))

    typedef enum {
        CG_WARM_UP_SRC_OSC_EXT = 0U,
        CG_WARM_UP_SRC_OSC_INT = 1U,
    } CG_WarmUpSrc;
#define IS_CG_WARM_UP_SRC(param)      (((param) == CG_WARM_UP_SRC_OSC_EXT) || \
                                       ((param) == CG_WARM_UP_SRC_OSC_INT))

#define IS_CG_WARM_UP_TIME(param)     ((param) < 0xFFFFU)

    typedef enum {
        CG_FC_SRC_FOSC = 0U,
        CG_FC_SRC_QUARTER_FPLL = 1U
    } CG_FcSrc;
#define IS_CG_FC_SRC(param)         (((param) == CG_FC_SRC_FOSC) || \
                                     ((param) == CG_FC_SRC_QUARTER_FPLL))

    typedef enum {
        CG_FTMRD_SRC_FPLL = 0U,
        CG_FTMRD_SRC_HALF_FPLL = 1U,
        CG_FTMRD_SRC_QUARTER_FPLL = 2U,
        CG_FTMRD_SRC_UNKNOWN = 3U
    } CG_FtmrdSrc;
#define IS_CG_FTMRD_SRC(param)      (((param) == CG_FTMRD_SRC_FPLL) || \
                                     ((param) == CG_FTMRD_SRC_HALF_FPLL)|| \
                                     ((param) == CG_FTMRD_SRC_QUARTER_FPLL))

    typedef enum {
        CG_FPLL_MULTIPLY_8 = 0U,
        CG_FPLL_MULTIPLY_16 = 1U,
        CG_FPLL_MULTIPLY_UNKNOWN = 2U
    } CG_FpllValue;
#define IS_CG_FPLL_VALUE(param)      (((param) == CG_FPLL_MULTIPLY_8) || \
                                      ((param) == CG_FPLL_MULTIPLY_16))

    typedef enum {
        CG_STBY_MODE_UNKNOWN = 0U,
        CG_STBY_MODE_STOP1 = 1U,
        CG_STBY_MODE_IDLE = 3U,
        CG_STBY_MODE_STOP2 = 5U,
        CG_STBY_MODE_MAX = 8U
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)      (((param) == CG_STBY_MODE_STOP1) || \
                                     ((param) == CG_STBY_MODE_IDLE)|| \
                                     ((param) == CG_STBY_MODE_STOP2))

    typedef enum {
        CG_PHIT0_SRC_FGEAR = 0U,
        CG_PHIT0_SRC_FC = 1U,
        CG_PHIT0_SRC_MAX = 2U
    } CG_PhiT0Src;
#define IS_CG_PHIT0_SRC(param)      (((param) == CG_PHIT0_SRC_FGEAR) || \
                                     ((param) == CG_PHIT0_SRC_FC))

    typedef enum {
        CG_INT_SRC_0 = 0U,
        CG_INT_SRC_1 = 1U,
        CG_INT_SRC_2 = 2U,
        CG_INT_SRC_3 = 3U,
        CG_INT_SRC_4 = 4U,
        CG_INT_SRC_5 = 5U,
        CG_INT_SRC_6 = 6U,
        CG_INT_SRC_7 = 7U,
        CG_INT_SRC_PHT_00 = 8U,
        CG_INT_SRC_PHT_01 = 9U,
        CG_INT_SRC_PHT_10 = 10U,
        CG_INT_SRC_PHT_11 = 11U,
        CG_INT_SRC_PHT_20 = 12U,
        CG_INT_SRC_PHT_21 = 13U,
        CG_INT_SRC_PHT_30 = 14U,
        CG_INT_SRC_PHT_31 = 15U,
        CG_INT_SRC_PHEVRY_0 = 16U,
        CG_INT_SRC_PHEVRY_1 = 17U,
        CG_INT_SRC_PHEVRY_2 = 18U,
        CG_INT_SRC_PHEVRY_3 = 19U,
        CG_INT_SRC_8 = 20U,
        CG_INT_SRC_9 = 21U,
        CG_INT_SRC_A = 22U,
        CG_INT_SRC_B = 23U,
    } CG_INTSrc;
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_PHT_00) || \
                                 ((param) == CG_INT_SRC_PHT_01) || \
                                 ((param) == CG_INT_SRC_PHT_10) || \
                                 ((param) == CG_INT_SRC_PHT_11) || \
                                 ((param) == CG_INT_SRC_PHT_20) || \
                                 ((param) == CG_INT_SRC_PHT_21) || \
                                 ((param) == CG_INT_SRC_PHT_30) || \
                                 ((param) == CG_INT_SRC_PHT_31) || \
                                 ((param) == CG_INT_SRC_PHEVRY_0) || \
                                 ((param) == CG_INT_SRC_PHEVRY_1) || \
                                 ((param) == CG_INT_SRC_PHEVRY_2) || \
                                 ((param) == CG_INT_SRC_PHEVRY_3) || \
                                 ((param) == CG_INT_SRC_8) || \
                                 ((param) == CG_INT_SRC_9) || \
                                 ((param) == CG_INT_SRC_A) || \
                                 ((param) == CG_INT_SRC_B))

    typedef enum {
        CG_INT_ACTIVE_STATE_L = 0x00U,
        CG_INT_ACTIVE_STATE_H = 0x10U,
        CG_INT_ACTIVE_STATE_FALLING = 0x20U,
        CG_INT_ACTIVE_STATE_RISING = 0x30U,
        CG_INT_ACTIVE_STATE_BOTH_EDGES = 0x40U,
        CG_INT_ACTIVE_STATE_INVALID = 0x50U
    } CG_INTActiveState;
#define IS_CG_INT_ACTIVE_STATE(param)    (((param) == CG_INT_ACTIVE_STATE_L) || \
                                          ((param) == CG_INT_ACTIVE_STATE_H) || \
                                          ((param) == CG_INT_ACTIVE_STATE_FALLING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_RISING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_BOTH_EDGES))

    typedef union {
        uint32_t All;
        struct {
            uint32_t WDT:1;
            uint32_t NMIPin:1;
        } Bit;
    } CG_NMIFactor;

    typedef union {
        uint32_t All;
        struct {
            uint32_t ResetPin:1;
            uint32_t Reserved:1;
            uint32_t WDTReset:1;
            uint32_t STOP2Reset:1;
            uint32_t DebugReset:1;
            uint32_t OFDReset:1;
        } Bit;
    } CG_ResetFlag;

/** @} */
/* End of group CG_Exported_types */

/** @defgroup CG_Exported_FunctionPrototypes
  * @{
  */
    void CG_SetFgearLevel(CG_DivideLevel DivideFgearFromFc);
    CG_DivideLevel CG_GetFgearLevel(void);
    void CG_SetPhiT0Src(CG_PhiT0Src PhiT0Src);
    CG_PhiT0Src CG_GetPhiT0Src(void);
    Result CG_SetPhiT0Level(CG_DivideLevel DividePhiT0FromFc);
    CG_DivideLevel CG_GetPhiT0Level(void);
    void CG_SetSCOUTSrc(CG_SCOUTSrc Source);
    CG_SCOUTSrc CG_GetSCOUTSrc(void);
    void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time);
    void CG_StartWarmUp(void);
    WorkState CG_GetWarmUpState(void);
    Result CG_SetFPLLValue(CG_FpllValue NewValue);
    CG_FpllValue CG_GetFPLLValue(void);
    Result CG_SetPLL(FunctionalState NewState);
    FunctionalState CG_GetPLLState(void);
    Result CG_SetFosc(CG_FoscSrc Source, FunctionalState NewState);
    void CG_SetFoscSrc(CG_FoscSrc Source);
    CG_FoscSrc CG_GetFoscSrc(void);
    FunctionalState CG_GetFoscState(CG_FoscSrc Source);
    void CG_SetSTBYMode(CG_STBYMode Mode);
    CG_STBYMode CG_GetSTBYMode(void);
    void CG_SetPinStateInStop1Mode(FunctionalState NewState);
    FunctionalState CG_GetPinStateInStop1Mode(void);
    void CG_SetPortKeepInStop2Mode(FunctionalState NewState);
    FunctionalState CG_GetPortKeepInStop2Mode(void);
    Result CG_SetFcSrc(CG_FcSrc Source);
    CG_FcSrc CG_GetFcSrc(void);
    void CG_SetFtmrdSrc(CG_FtmrdSrc FtmrdSrc);
    CG_FtmrdSrc CG_GetFtmrdSrc(void);
    void CG_SetTMRDClk(FunctionalState NewState);
    FunctionalState CG_GetTMRDClkState(void);
    void CG_SetProtectCtrl(FunctionalState NewState);
    void CG_SetSTBYReleaseINTSrc(CG_INTSrc INTSource,
                                 CG_INTActiveState ActiveState, FunctionalState NewState);
    CG_INTActiveState CG_GetSTBYReleaseINTState(CG_INTSrc INTSource);
    void CG_ClearINTReq(CG_INTSrc INTSource);
    CG_NMIFactor CG_GetNMIFlag(void);
    CG_ResetFlag CG_GetResetFlag(void);

/** @} */
/* End of group CG_Exported_FunctionPrototype */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /*defined(__TMPM341_CG_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM341_CG_H */
