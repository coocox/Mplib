/**
 *******************************************************************************
 * @file    tmpm376_cg.h
 * @brief   This file provides all the functions prototypes for CG driver.
 * @version V2.0.2.1
 * @date    2012/01/17
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
#ifndef __TMPM376_CG_H
#define __TMPM376_CG_H


#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "TMPM376.h"
#include "tx03_common.h"

#if defined(__TMPM376_CG_H) || defined(__TMPM377_CG_H)
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
        CG_FOSC_OSC1 = 0U,      /* External High speed OSC */
        CG_FOSC_OSC2 = 1U       /* Internal High speed OSC */
    } CG_FoscSrc;
#define IS_CG_FOSC_SRC(param)     (((param) == CG_FOSC_OSC1) || \
                                   ((param) == CG_FOSC_OSC2))

    typedef enum {
        CG_WARM_UP_SRC_OSC1 = 0U,   /* External High speed OSC */
        CG_WARM_UP_SRC_OSC2 = 1U    /* Internal High speed OSC */
    } CG_WarmUpSrc;
#define IS_CG_WARM_UP_SRC(param)    (((param) == CG_WARM_UP_SRC_OSC1) || \
                                     ((param) == CG_WARM_UP_SRC_OSC2))

#define IS_CG_WARM_UP_TIME_X1(param)     ((param) < 0x1000U)

    typedef enum {
        CG_PORTM_AS_GPIO = 0U,
        CG_PORTM_AS_HOSC = 1U
    } CG_PortMMode;
#define IS_CG_PROTM_FUNCTION(param)    (((param) == CG_PORTM_AS_GPIO) || \
                                        ((param) == CG_PORTM_AS_HOSC))
    typedef enum {
        CG_INT_REQ = 0U,
        CG_NO_INT_REQ = 1U
    } CG_INTReqState;


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
#define IS_CG_GEAR_DIVIDE_LEVEL(param)  (((param) <= CG_DIVIDE_16))

#define IS_CG_DIVIDE_FC_LEVEL(param)    (((param) <= CG_DIVIDE_32))

#define IS_CG_DIVIDE_FGEAR_LEVEL(param) (((param)<= CG_DIVIDE_512))

    typedef enum {
        CG_FC_SRC_FOSC = 0U,
        CG_FC_SRC_FPLL = 1U
    } CG_FcSrc;
#define IS_CG_FC_SRC(param)    (((param) == CG_FC_SRC_FOSC) || \
                                ((param) == CG_FC_SRC_FPLL))

    typedef enum {
        CG_STBY_MODE_UNKNOWN = 0U,
        CG_STBY_MODE_STOP = 1U,
        CG_STBY_MODE_IDLE = 3U,
    } CG_STBYMode;
#define IS_CG_STBY_MODE(param)    (((param) == CG_STBY_MODE_STOP) || \
                                   ((param) == CG_STBY_MODE_IDLE))

    typedef enum {
        CG_PHIT0_SRC_FGEAR = 0U,
        CG_PHIT0_SRC_FC = 1U,
    } CG_PhiT0Src;
#define IS_CG_PHIT0_SRC(param)  (((param) == CG_PHIT0_SRC_FGEAR) || \
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
        CG_INT_SRC_8 = 8U,
        CG_INT_SRC_9 = 9U,
        CG_INT_SRC_A = 10U,
        CG_INT_SRC_B = 11U,
        CG_INT_SRC_C = 12U,
        CG_INT_SRC_D = 13U,
        CG_INT_SRC_E = 14U,
        CG_INT_SRC_F = 15U
    } CG_INTSrc;

#if defined(__TMPM376_CG_H)
#define IS_CG_INT_SRC(param)    (((param) <= CG_INT_SRC_F))

#else  /* M377 */
#define IS_CG_INT_SRC(param)    ( ((param) == CG_INT_SRC_3) ||
                                  ((param) == CG_INT_SRC_4) ||
                                  ((param) == CG_INT_SRC_6) ||
                                  ((param) == CG_INT_SRC_7) ||
                                  ((param) == CG_INT_SRC_B) )
#endif

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
        } Bit;
    } CG_NMIFactor;


    typedef union {
        uint32_t All;
        struct {
            uint32_t PowerOn:1;
            uint32_t ResetPin:1;
            uint32_t WDTReset:1;
            uint32_t VLTDReset:1;
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
    void CG_SetWarmUpTime(CG_WarmUpSrc Source, uint16_t Time);
    void CG_StartWarmUp(void);
    WorkState CG_GetWarmUpState(void);
    Result CG_SetPLL(FunctionalState NewState);
    FunctionalState CG_GetPLLState(void);
    Result CG_SetFosc(CG_FoscSrc Source, FunctionalState NewState);
    void CG_SetFoscSrc(CG_FoscSrc Source);
    CG_FoscSrc CG_GetFoscSrc(void);
    FunctionalState CG_GetFoscState(CG_FoscSrc Source);
    void CG_SetPortM(CG_PortMMode Mode);
    CG_INTReqState CG_GetINTReq(CG_INTSrc INTSource);
    void CG_SetSTBYMode(CG_STBYMode Mode);
    CG_STBYMode CG_GetSTBYMode(void);
    void CG_SetPinStateInStopMode(FunctionalState NewState);
    FunctionalState CG_GetPinStateInStopMode(void);
    Result CG_SetFcSrc(CG_FcSrc Source);
    CG_FcSrc CG_GetFcSrc(void);
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
#endif                          /* defined(__TMPM376_CG_H) || defined(__TMPM377_CG_H)  */


#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* defined(__TMPM376_CG_H) */
