/**
 *******************************************************************************
 * @file    tmpm061_cg.h
 * @brief   This file provides all the functions prototypes for CG driver.
 * @version V2.0.2.2
 * @date    2012/08/17
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
#ifndef __TMPM061_CG_H
#define __TMPM061_CG_H


#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

#if defined(__TMPM061_CG_H)
/** @addtogroup TX00_Periph_Driver
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

#define IS_CG_DIVIDE_FS_FC_LEVEL(param) (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8) || \
                                         ((param) == CG_DIVIDE_16) || \
                                         ((param) == CG_DIVIDE_32))

#define IS_CG_DIVIDE_FGEAR_LEVEL(param) (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8) || \
                                         ((param) == CG_DIVIDE_16) || \
                                         ((param) == CG_DIVIDE_32) || \
                                         ((param) == CG_DIVIDE_64)|| \
                                         ((param) == CG_DIVIDE_128) || \
                                         ((param) == CG_DIVIDE_256) || \
                                         ((param) == CG_DIVIDE_512))

    typedef enum {
        CG_FOSC_OSC1 = 0U,
        CG_FOSC_OSC2 = 1U
    } CG_FoscSrc;
#define IS_CG_FOSC_SRC(param)     (((param) == CG_FOSC_OSC1) || \
                                   ((param) == CG_FOSC_OSC2))

    typedef enum {
        CG_SCOUT_SRC_FS = 0U,
        CG_SCOUT_SRC_HALF_FSYS = 1U,
        CG_SCOUT_SRC_FSYS = 2U,
        CG_SCOUT_SRC_PHIT0 = 3U
    } CG_SCOUTSrc;
#define IS_CG_SCOUT_SRC(param)    (((param) == CG_SCOUT_SRC_FS) || \
                                   ((param) == CG_SCOUT_SRC_HALF_FSYS) || \
                                   ((param) == CG_SCOUT_SRC_FSYS) || \
                                   ((param) == CG_SCOUT_SRC_PHIT0))

    typedef enum {
        CG_WARM_UP_SRC_OSC1 = 0U,
        CG_WARM_UP_SRC_OSC2 = 1U,
        CG_WARM_UP_SRC_XT1 = 2U
    } CG_WarmUpSrc;
#define IS_CG_WARM_UP_SRC(param)    (((param) == CG_WARM_UP_SRC_OSC1) || \
                                     ((param) == CG_WARM_UP_SRC_OSC2)  || \
                                     ((param) == CG_WARM_UP_SRC_XT1))

#define IS_CG_WARM_UP_TIME_X1(param)     ((param) < 0x1000U)
#define IS_CG_WARM_UP_TIME_XT1(param)    ((param) < 0x4000U)

    typedef enum {
        CG_STBY_MODE_UNKNOWN = 0U,
        CG_STBY_MODE_STOP = 1U,
        CG_STBY_MODE_SLEEP = 2U,
        CG_STBY_MODE_IDLE = 3U,
        CG_STBY_MODE_MAX = 8U
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)    (((param) == CG_STBY_MODE_STOP) || \
                                   ((param) == CG_STBY_MODE_SLEEP)|| \
                                   ((param) == CG_STBY_MODE_IDLE))

    typedef enum {
        CG_PHIT0_SRC_FGEAR = 0U,
        CG_PHIT0_SRC_FC = 1U,
        CG_PHIT0_SRC_FS = 2U,
        CG_PHIT0_SRC_MAX = 4U
    } CG_PhiT0Src;
#define IS_CG_PHIT0_SRC(param)  (((param) == CG_PHIT0_SRC_FGEAR) || \
                                 ((param) == CG_PHIT0_SRC_FC) || \
                                 ((param) == CG_PHIT0_SRC_FS))

    typedef enum {
        CG_FSYS_SRC_FGEAR = 0U,
        CG_FSYS_SRC_FS = 1U
    } CG_FsysSrc;
#define IS_CG_FSYS_SRC(param)    (((param) == CG_FSYS_SRC_FGEAR) || \
                                  ((param) == CG_FSYS_SRC_FS))

    typedef enum {
        CG_PORTM_AS_GPIO = 0U,
        CG_PORTM_AS_HOSC = 1U
    } CG_PortMMode;
#define IS_CG_PROTM_FUNCTION(param)    (((param) == CG_PORTM_AS_GPIO) || \
                                        ((param) == CG_PORTM_AS_HOSC))

    typedef enum {
        CG_LOSC_OSC = 0U,
        CG_LOSC_CLK = 1U
    } CG_LoscSrc;
#define IS_CG_LOSC_FUNCTION(param)    (((param) == CG_LOSC_OSC) || \
                                       ((param) == CG_LOSC_CLK))
    typedef enum {
        CG_EHCLK_OSCSEL = 0U,
        CG_EHCLK_OSC2   = 1U
    } CG_EHClkSrc;
#define IS_CG_EHCLK_FUNCTION(param)    (((param) == CG_EHCLK_OSCSEL) || \
                                        ((param) == CG_EHCLK_OSC2))
    typedef enum {
        CG_INT_SRC_INTLVD = 0U,
        CG_INT_SRC_0 = 1U,
        CG_INT_SRC_1 = 2U,
        CG_INT_SRC_2 = 3U,
        CG_INT_SRC_3 = 4U,
        CG_INT_SRC_RTC = 5U
    } CG_INTSrc;

#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_INTLVD) || \
                                 ((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_RTC))
                                 
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
            uint32_t ResetPin:1;
            uint32_t Reserved1:1;
            uint32_t WDTReset:1;
            uint32_t Reserved2:1;
            uint32_t DebugReset:1;
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
    Result CG_SetFosc(CG_FoscSrc Source, FunctionalState NewState);
    void CG_SetFoscSrc(CG_FoscSrc Source);
    CG_FoscSrc CG_GetFoscSrc(void);
    FunctionalState CG_GetFoscState(CG_FoscSrc Source);
    Result CG_SetFs(FunctionalState NewState);
    FunctionalState CG_GetFsState(void);
    void CG_SetPortM(CG_PortMMode Mode);
    void CG_SetLowOscSrc(CG_LoscSrc Source);
    void CG_SetExtHighClk(FunctionalState NewState);
    void CG_SetSTBYMode(CG_STBYMode Mode);
    CG_STBYMode CG_GetSTBYMode(void);
    void CG_SetExitStopModeFosc(FunctionalState NewState);
    FunctionalState CG_GetExitStopModeFoscState(void);
    void CG_SetExitStopModeFs(FunctionalState NewState);
    FunctionalState CG_GetExitStopModeFsState(void);
    void CG_SetPinStateInStopMode(FunctionalState NewState);
    FunctionalState CG_GetPinStateInStopMode(void);
    void CG_SelExtHighClk(CG_EHClkSrc Source);
    Result CG_SetFsysSrc(CG_FsysSrc Source);
    CG_FsysSrc CG_GetFsysSrc(void);
    void CG_SetSTBYReleaseINTSrc(CG_INTSrc INTSource,
                                 CG_INTActiveState ActiveState, FunctionalState NewState);
    CG_INTActiveState CG_GetSTBYReleaseINTState(CG_INTSrc INTSource);
    void CG_ClearINTReq(CG_INTSrc INTSource);
    CG_ResetFlag CG_GetResetFlag(void);

/** @} */
/* End of group CG_Exported_FunctionPrototype */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_CG_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM061_CG_H */
