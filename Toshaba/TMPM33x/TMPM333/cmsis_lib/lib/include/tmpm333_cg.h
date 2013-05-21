/**
 *******************************************************************************
 * @file    tmpm333_cg.h
 * @brief   This file provides all the functions prototypes for CG driver.
 * @version V2.1.0
 * @date    2010/07/05
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
#ifndef __TMPM333_CG_H
#define __TMPM333_CG_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM333.h"
#include "tx03_common.h"

#if defined(__TMPM330_CG_H) || defined(__TMPM332_CG_H) || defined(__TMPM333_CG_H)
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
        CG_DIVIDE_1 = 0,
        CG_DIVIDE_2 = 1,
        CG_DIVIDE_4 = 2,
        CG_DIVIDE_8 = 3,
        CG_DIVIDE_16 = 4,
        CG_DIVIDE_32 = 5,
        CG_DIVIDE_64 = 6,
        CG_DIVIDE_128 = 7,
        CG_DIVIDE_256 = 8,
        CG_DIVIDE_UNKNOWN = 9,
        CG_DIVIDE_MAX = 10
    } CG_DivideLevel;
#define IS_CG_GEAR_DIVIDE_LEVEL(param)  (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8))
#define IS_CG_T0_DIVIDE_LEVEL(param)    (((param) == CG_DIVIDE_1) || \
                                         ((param) == CG_DIVIDE_2) || \
                                         ((param) == CG_DIVIDE_4) || \
                                         ((param) == CG_DIVIDE_8) || \
                                         ((param) == CG_DIVIDE_16) || \
                                         ((param) == CG_DIVIDE_32) || \
                                         ((param) == CG_DIVIDE_64)|| \
                                         ((param) == CG_DIVIDE_128) || \
                                         ((param) == CG_DIVIDE_256))

    typedef enum {
        CG_SCOUT_SRC_FS = 0,
        CG_SCOUT_SRC_HALF_FSYS = 1,
        CG_SCOUT_SRC_FSYS = 2,
        CG_SCOUT_SRC_PHIT0 = 3,
    } CG_SCOUTSrc;
#define IS_CG_SCOUT_SRC(param)    (((param) == CG_SCOUT_SRC_FS) || \
                                   ((param) == CG_SCOUT_SRC_HALF_FSYS) || \
                                   ((param) == CG_SCOUT_SRC_FSYS) || \
                                   ((param) == CG_SCOUT_SRC_PHIT0))

    typedef enum {
        CG_WARM_UP_SRC_X1 = 0,
        CG_WARM_UP_SRC_XT1 = 1
    } CG_WarmUpSrc;
#define IS_CG_WARM_UP_SRC(param)    (((param) == CG_WARM_UP_SRC_X1) || \
                                    ((param) == CG_WARM_UP_SRC_XT1))

    typedef enum {
        CG_WARM_UP_TIME_NONE = 0,
        CG_WARM_UP_TIME_EXP_6 = 1,
        CG_WARM_UP_TIME_EXP_7 = 2,
        CG_WARM_UP_TIME_EXP_8 = 3,
        CG_WARM_UP_TIME_EXP_10 = 4,
        CG_WARM_UP_TIME_EXP_11 = 5,
        CG_WARM_UP_TIME_EXP_12 = 6,
        CG_WARM_UP_TIME_EXP_13 = 7,
        CG_WARM_UP_TIME_EXP_14 = 8,
        CG_WARM_UP_TIME_EXP_15 = 9,
        CG_WARM_UP_TIME_EXP_16 = 10,
        CG_WARM_UP_TIME_EXP_17 = 11,
        CG_WARM_UP_TIME_EXP_18 = 12
    } CG_WarmUpTime;
#define IS_CG_WARM_UP_TIME(param)    (((param) == CG_WARM_UP_TIME_EXP_6) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_7) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_8) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_10) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_11) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_12) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_13) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_14) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_15) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_16) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_17) || \
                                     ((param) == CG_WARM_UP_TIME_EXP_18) || \
                                     ((param) == CG_WARM_UP_TIME_NONE))


    typedef enum {
        CG_STBY_MODE_STOP = 0,
        CG_STBY_MODE_SLEEP = 1,
        CG_STBY_MODE_IDLE = 2,
        CG_STBY_MODE_UNKNOWN = 3,
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)    (((param) == CG_STBY_MODE_STOP) || \
                                   ((param) == CG_STBY_MODE_SLEEP) || \
                                   ((param) == CG_STBY_MODE_IDLE))

    typedef enum {
        CG_FC_SRC_FOSC = 0,
        CG_FC_SRC_FPLL = 1
    } CG_FcSrc;
#define IS_CG_FC_SRC(param)    (((param) == CG_FC_SRC_FOSC) || \
                                ((param) == CG_FC_SRC_FPLL))

    typedef enum {
        CG_FSYS_SRC_FGEAR = 0,
        CG_FSYS_SRC_FS = 1
    } CG_FsysSrc;
#define IS_CG_FSYS_SRC(param)    (((param) == CG_FSYS_SRC_FGEAR) || \
                                  ((param) == CG_FSYS_SRC_FS))
#if defined(__TMPM330_CG_H)
    typedef enum {
        CG_INT_SRC_0 = 0,
        CG_INT_SRC_1 = 1,
        CG_INT_SRC_2 = 2,
        CG_INT_SRC_3 = 3,
        CG_INT_SRC_4 = 4,
        CG_INT_SRC_5 = 5,
        CG_INT_SRC_CEC_RX = 6,
        CG_INT_SRC_RMC_RX_0 = 7,
        CG_INT_SRC_RTC = 8,
        CG_INT_SRC_6 = 9,
        CG_INT_SRC_7 = 10,
        CG_INT_SRC_RMC_RX_1 = 11,
        CG_INT_SRC_CEC_TX = 12
    } CG_INTSrc;


#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_RMC_RX_1) || \
                                 ((param) == CG_INT_SRC_CEC_TX))
#elif defined(__TMPM332_CG_H)
    typedef enum {
        CG_INT_SRC_0 = 0,
        CG_INT_SRC_1 = 1,
        CG_INT_SRC_2 = 2,
        CG_INT_SRC_3 = 3,
        CG_INT_SRC_4 = 4,
        CG_INT_SRC_CEC_RX = 6,
        CG_INT_SRC_RMC_RX_0 = 7,
        CG_INT_SRC_RTC = 8,
        CG_INT_SRC_CEC_TX = 12
    } CG_INTSrc;
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_CEC_TX))
#elif defined(__TMPM333_CG_H)
    typedef enum {
        CG_INT_SRC_0 = 0,
        CG_INT_SRC_1 = 1,
        CG_INT_SRC_2 = 2,
        CG_INT_SRC_3 = 3,
        CG_INT_SRC_4 = 4,
        CG_INT_SRC_5 = 5,
        CG_INT_SRC_RTC = 8,
        CG_INT_SRC_6 = 9,
        CG_INT_SRC_7 = 10
    } CG_INTSrc;
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7))
#endif                          /* defined(__TMPM330_CG_H) */
    typedef enum {
        CG_INT_ACTIVE_STATE_L = 0,
        CG_INT_ACTIVE_STATE_H = 1,
        CG_INT_ACTIVE_STATE_FALLING = 2,
        CG_INT_ACTIVE_STATE_RISING = 3,
        CG_INT_ACTIVE_STATE_BOTH_EDGES = 4,
        CG_INT_ACTIVE_STATE_INVALID = 5
    } CG_INTActiveState;
#define IS_CG_INT_ACTIVE_STATE(param)    (((param) == CG_INT_ACTIVE_STATE_L) || \
                                          ((param) == CG_INT_ACTIVE_STATE_H) || \
                                          ((param) == CG_INT_ACTIVE_STATE_FALLING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_RISING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_BOTH_EDGES) || \
                                          ((param) == CG_INT_ACTIVE_STATE_INVALID))

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
          uint32_t PowerOn    : 1;
          uint32_t ResetPin   : 1;
          uint32_t WDTReset   : 1;
          uint32_t            : 1;
          uint32_t DebugReset : 1;
        } Bit;
    } CG_ResetFlag;

/** @} */
/* End of group CG_Exported_types */

/** @defgroup CG_Exported_FunctionPrototypes
  * @{
  */
    void CG_SetFgearLevel(CG_DivideLevel DivideFgearFromFc);
    CG_DivideLevel CG_GetFgearLevel(void);
    Result CG_SetPhiT0Level(CG_DivideLevel DividePhiT0FromFc);
    CG_DivideLevel CG_GetPhiT0Level(void);
    void CG_SetSCOUTSrc(CG_SCOUTSrc Source);
    CG_SCOUTSrc CG_GetSCOUTSrc(void);
    Result CG_SetWarmUpTime(CG_WarmUpSrc Source, CG_WarmUpTime Time);
    void CG_StartWarmUp(void);
    WorkState CG_GetWarmUpState(void);
    Result CG_SetPLL(FunctionalState NewState);
    FunctionalState CG_GetPLLState(void);
    Result CG_SetFosc(FunctionalState NewState);
    FunctionalState CG_GetFoscState(void);
    Result CG_SetFs(FunctionalState NewState);
    FunctionalState CG_GetFsState(void);
    void CG_SetSTBYMode(CG_STBYMode Mode);
    CG_STBYMode CG_GetSTBYMode(void);
    void CG_SetExitStopModeFosc(FunctionalState NewState);
    FunctionalState CG_GetExitStopModeFoscState(void);
    void CG_SetExitStopModeFs(FunctionalState NewState);
    FunctionalState CG_GetExitStopModeFsState(void);
    void CG_SetPinStateInStopMode(FunctionalState NewState);
    FunctionalState CG_GetPinStateInStopMode(void);
    Result CG_SetFcSrc(CG_FcSrc Source);
    CG_FcSrc CG_GetFcSrc(void);
    Result CG_SetFsysSrc(CG_FsysSrc Source);
    CG_FsysSrc CG_GetFsysSrc(void);
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

#endif                          /* defined(__TMPM330_CG_H) || defined(__TMPM332_CG_H) || defined(__TMPM333_CG_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM333_CG_H */
