/**
 *******************************************************************************
 * @file    tmpm361_cg.h
 * @brief   This file provides all the functions prototypes for CG driver.
 * @version V2.2.0
 * @date    2010/12/01
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
#ifndef __TMPM361_CG_H
#define __TMPM361_CG_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM361.h"
#include "tx03_common.h"

#if defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
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
        CG_DIVIDE_UNKNOWN = 9U,
        CG_DIVIDE_MAX = 10U
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
        CG_WARM_UP_SRC_X1 = 0U,
        CG_WARM_UP_SRC_XT1 = 1U
    } CG_WarmUpSrc;
#define IS_CG_WARM_UP_SRC(param)    (((param) == CG_WARM_UP_SRC_X1) || \
                                    ((param) == CG_WARM_UP_SRC_XT1))

#define IS_CG_WARM_UP_TIME_X1(param)    ((param) < 0x1000U)
#define IS_CG_WARM_UP_TIME_XT1(param)    ((param) < 0x4000U)

    typedef enum {
        CG_FC_SRC_FOSC = 0U,
        CG_FC_SRC_FPLL = 1U
    } CG_FcSrc;
#define IS_CG_FC_SRC(param)    (((param) == CG_FC_SRC_FOSC) || \
                                ((param) == CG_FC_SRC_FPLL))

#if defined(__TMPM360_CG_H)
    typedef enum {
        CG_STBY_MODE_UNKNOWN = 0U,
        CG_STBY_MODE_STOP = 1U,
        CG_STBY_MODE_SLEEP = 2U,
        CG_STBY_MODE_IDLE2 = 3U,
        CG_STBY_MODE_IDLE1 = 7U,
        CG_STBY_MODE_MAX = 8U
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)    (((param) == CG_STBY_MODE_STOP) || \
                                   ((param) == CG_STBY_MODE_SLEEP)|| \
                                   ((param) == CG_STBY_MODE_IDLE2) || \
                                   ((param) == CG_STBY_MODE_IDLE1))
#else
/*defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)*/

    typedef enum {
        CG_STBY_MODE_UNKNOWN = 0U,
        CG_STBY_MODE_STOP = 1U,
        CG_STBY_MODE_SLEEP = 2U,
        CG_STBY_MODE_IDLE2 = 3U,
        CG_STBY_MODE_BACKUP_STOP = 5U,
        CG_STBY_MODE_BACKUP_SLEEP = 6U,
        CG_STBY_MODE_IDLE1 = 7U,
        CG_STBY_MODE_MAX = 8U
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)    (((param) == CG_STBY_MODE_STOP) || \
                                   ((param) == CG_STBY_MODE_SLEEP)|| \
                                   ((param) == CG_STBY_MODE_IDLE2) || \
                                   ((param) == CG_STBY_MODE_BACKUP_STOP) || \
                                   ((param) == CG_STBY_MODE_BACKUP_SLEEP) || \
                                   ((param) == CG_STBY_MODE_IDLE1))

    typedef enum {
        CG_PHIT0_SRC_FPSCALER = 0U,
        CG_PHIT0_SRC_FS = 1U
    } CG_PhiT0Src;
#define IS_CG_PHIT0_SRC(param)  (((param) == CG_PHIT0_SRC_FPSCALER) || \
                                 ((param) == CG_PHIT0_SRC_FS))
#endif

    typedef enum {
        CG_FSYS_SRC_FGEAR = 0U,
        CG_FSYS_SRC_FS = 1U
    } CG_FsysSrc;
#define IS_CG_FSYS_SRC(param)    (((param) == CG_FSYS_SRC_FGEAR) || \
                                  ((param) == CG_FSYS_SRC_FS))

    typedef enum {
        CG_INT_SRC_0 = 0U,
        CG_INT_SRC_1 = 1U,
        CG_INT_SRC_2 = 2U,
        CG_INT_SRC_3 = 3U,
        CG_INT_SRC_4 = 4U,
        CG_INT_SRC_5 = 5U,
        CG_INT_SRC_6 = 6U,
        CG_INT_SRC_7 = 7U,
#if defined(__TMPM360_CG_H) || defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        CG_INT_SRC_8 = 8U,
        CG_INT_SRC_9 = 9U,
        CG_INT_SRC_A = 10U,
        CG_INT_SRC_B = 11U,
        CG_INT_SRC_C = 12U,
        CG_INT_SRC_D = 13U,
#endif
#if defined(__TMPM360_CG_H) || defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H)
        CG_INT_SRC_E = 14U,
        CG_INT_SRC_F = 15U,
#endif
        CG_INT_SRC_CEC_RX = 16U,
        CG_INT_SRC_CEC_TX = 17U,
        CG_INT_SRC_RMC_RX_0 = 18U,
#if defined(__TMPM360_CG_H) || defined(__TMPM362_CG_H) || defined(__TMPM364_CG_H)
        CG_INT_SRC_RMC_RX_1 = 19U,
#endif
        CG_INT_SRC_RTC = 20U,
        CG_INT_SRC_KWUP = 21U,
    } CG_INTSrc;

#if defined(__TMPM360_CG_H) || defined(__TMPM362_CG_H)
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_8) || \
                                 ((param) == CG_INT_SRC_9) || \
                                 ((param) == CG_INT_SRC_A) || \
                                 ((param) == CG_INT_SRC_B) || \
                                 ((param) == CG_INT_SRC_C) || \
                                 ((param) == CG_INT_SRC_D) || \
                                 ((param) == CG_INT_SRC_E) || \
                                 ((param) == CG_INT_SRC_F) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_CEC_TX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RMC_RX_1) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_KWUP))
#elif defined(__TMPM361_CG_H)
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_E) || \
                                 ((param) == CG_INT_SRC_F) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_CEC_TX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_KWUP))
#elif defined(__TMPM363_CG_H)
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_CEC_TX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_KWUP))
#elif defined(__TMPM364_CG_H)
#define IS_CG_INT_SRC(param)    (((param) == CG_INT_SRC_0) || \
                                 ((param) == CG_INT_SRC_1) || \
                                 ((param) == CG_INT_SRC_2) || \
                                 ((param) == CG_INT_SRC_3) || \
                                 ((param) == CG_INT_SRC_4) || \
                                 ((param) == CG_INT_SRC_5) || \
                                 ((param) == CG_INT_SRC_6) || \
                                 ((param) == CG_INT_SRC_7) || \
                                 ((param) == CG_INT_SRC_8) || \
                                 ((param) == CG_INT_SRC_9) || \
                                 ((param) == CG_INT_SRC_A) || \
                                 ((param) == CG_INT_SRC_B) || \
                                 ((param) == CG_INT_SRC_C) || \
                                 ((param) == CG_INT_SRC_D) || \
                                 ((param) == CG_INT_SRC_CEC_RX) || \
                                 ((param) == CG_INT_SRC_CEC_TX) || \
                                 ((param) == CG_INT_SRC_RMC_RX_0) || \
                                 ((param) == CG_INT_SRC_RMC_RX_1) || \
                                 ((param) == CG_INT_SRC_RTC) || \
                                 ((param) == CG_INT_SRC_KWUP))
#endif

    typedef enum {
        CG_INT_ACTIVE_STATE_L = 0x00U,
        CG_INT_ACTIVE_STATE_H = 0x10U,
        CG_INT_ACTIVE_STATE_FALLING = 0x20U,
        CG_INT_ACTIVE_STATE_RISING = 0x30U,
        CG_INT_ACTIVE_STATE_BOTH_EDGES = 0x40U,
        CG_INT_ACTIVE_STATE_INVALID = 0x50U,
    } CG_INTActiveState;
#define IS_CG_INT_ACTIVE_STATE(param)    (((param) == CG_INT_ACTIVE_STATE_L) || \
                                          ((param) == CG_INT_ACTIVE_STATE_H) || \
                                          ((param) == CG_INT_ACTIVE_STATE_FALLING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_RISING) || \
                                          ((param) == CG_INT_ACTIVE_STATE_BOTH_EDGES))

    typedef enum {
        CG_MUL_4TIMES,
        CG_MUL_8TIMES
    } CG_ClkMul;

#define IS_CG_CLK_MUL(param)            (((param) == CG_MUL_4TIMES)||\
                                        ((param) == CG_MUL_8TIMES))

    typedef union {
        uint32_t All;
        struct {
            uint32_t WDT:1;
            uint32_t NMIPin:1;
        } Bit;
    } CG_NMIFactor;
#if defined(__TMPM360_CG_H)
    typedef union {
        uint32_t All;
        struct {
            uint32_t PowerOn:1;
            uint32_t ResetPin:1;
            uint32_t WDTReset:1;
            uint32_t reserve:1;
            uint32_t DebugReset:1;
        } Bit;
    } CG_ResetFlag;
#else
    typedef union {
        uint32_t All;
        struct {
            uint32_t PowerOn:1;
            uint32_t ResetPin:1;
            uint32_t WDTReset:1;
            uint32_t BKPReset:1;
            uint32_t DebugReset:1;
        } Bit;
    } CG_ResetFlag;
#endif
/** @} */
/* End of group CG_Exported_types */

/** @defgroup CG_Exported_FunctionPrototypes
  * @{
  */
    void CG_SetFgearLevel(CG_DivideLevel DivideFgearFromFc);
    CG_DivideLevel CG_GetFgearLevel(void);

#if defined(__TMPM361_CG_H) || defined(__TMPM362_CG_H) ||  \
    defined(__TMPM363_CG_H) || defined(__TMPM364_CG_H)
    void CG_SetPhiT0Src(CG_PhiT0Src PhiT0Src);
    CG_PhiT0Src CG_GetPhiT0Src(void);
#endif

    Result CG_SetPhiT0Level(CG_DivideLevel DividePhiT0FromFc);
    CG_DivideLevel CG_GetPhiT0Level(void);
    void CG_SetSCOUTSrc(CG_SCOUTSrc Source);
    CG_SCOUTSrc CG_GetSCOUTSrc(void);
    void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time);
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

    Result CG_SetPortKeep(FunctionalState NewState);

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
    void CG_SetClkMulTimes(CG_ClkMul MulTimes);



/** @} */
/* End of group CG_Exported_FunctionPrototype */

/** @} */
/* End of group CG */

/** @} */
/* End of group TX03_Periph_Driver */
#endif        /*__TMPM360_CG_H||__TMPM361_CG_H||__TMPM362_CG_H||__TMPM363_CG_H||__TMPM364_CG_H*/

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM361_CG_H */
