/**
 *******************************************************************************
 * @file    tmpm363_kwup.h
 * @brief   This file provides all the functions prototypes for KWUP driver.
 * @version V2.2.0
 * @date    2010/08/16
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
#ifndef __TMPM363_KWUP_H
#define __TMPM363_KWUP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM363.h"
#include "tx03_common.h"

#if defined(__TMPM360_KWUP_H) || defined(__TMPM361_KWUP_H) || defined(__TMPM362_KWUP_H) ||  \
    defined(__TMPM363_KWUP_H) || defined(__TMPM364_KWUP_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup KWUP
  * @{
  */

/** @defgroup KWUP_Exported_Types
  * @{
  */

    typedef enum {
        KWUP_INPUT_0 = 0U,
        KWUP_INPUT_1 = 1U,
        KWUP_INPUT_2 = 2U,
        KWUP_INPUT_3 = 3U
    } KWUP_Input;
#define IS_KWUP_INPUT(param)         (((param) == KWUP_INPUT_0) || \
                                      ((param) == KWUP_INPUT_1) || \
                                      ((param) == KWUP_INPUT_2) || \
                                      ((param) == KWUP_INPUT_3))

    typedef enum {
        KWUP_PUP_CTRL_BY_STATIC = 0U,
        KWUP_PUP_CTRL_BY_DYNAMIC = 1U
    } KWUP_PullUpCtrl;
#define IS_KWUP_PULL_UP_CTRL(param)         (((param) == KWUP_PUP_CTRL_BY_STATIC) || \
                                             ((param) == KWUP_PUP_CTRL_BY_DYNAMIC))

    typedef enum {
        KWUP_ACTIVE_BY_L_LEVEL = 0U,
        KWUP_ACTIVE_BY_H_LEVEL = 1U,
        KWUP_ACTIVE_BY_RISING_EDGE = 2U,
        KWUP_ACTIVE_BY_FALLING_EDGE = 3U,
        KWUP_ACTIVE_BY_BOTH_EDGES = 4U
    } KWUP_ActiveState;
#define IS_KWUP_ACTIVE_STATE(param)         (((param) == KWUP_ACTIVE_BY_L_LEVEL) || \
                                             ((param) == KWUP_ACTIVE_BY_H_LEVEL) || \
                                             ((param) == KWUP_ACTIVE_BY_RISING_EDGE) || \
                                             ((param) == KWUP_ACTIVE_BY_FALLING_EDGE)|| \
                                             ((param) == KWUP_ACTIVE_BY_BOTH_EDGES))

    typedef enum {
        KWUP_CYCLES_2_FS = 0U,
        KWUP_CYCLES_4_FS = 1U,
        KWUP_CYCLES_8_FS = 2U,
        KWUP_CYCLES_16_FS = 3U,
        KWUP_CYCLES_256_FS = 4U,
        KWUP_CYCLES_512_FS = 5U,
        KWUP_CYCLES_1024_FS = 6U,
        KWUP_CYCLES_2048_FS = 7U,
    } KWUP_PullUpCycles;
#define IS_KWUP_PULL_UP_CYCLES_T1(param)         (((param) == KWUP_CYCLES_2_FS) || \
                                                  ((param) == KWUP_CYCLES_4_FS) || \
                                                  ((param) == KWUP_CYCLES_8_FS) || \
                                                  ((param) == KWUP_CYCLES_16_FS))
#define IS_KWUP_PULL_UP_CYCLES_T2(param)         (((param) == KWUP_CYCLES_256_FS) || \
                                                  ((param) == KWUP_CYCLES_512_FS) || \
                                                  ((param) == KWUP_CYCLES_1024_FS) || \
                                                  ((param) == KWUP_CYCLES_2048_FS))


    typedef struct {
        KWUP_Input KeyN;
        KWUP_PullUpCtrl PullUpCtrl;
        KWUP_ActiveState ActiveState;
        FunctionalState INTNewState;
    } KWUP_SettingTypeDef;

    typedef union {
        uint32_t All;
        struct {
            uint32_t Key0:1;
            uint32_t Key1:1;
            uint32_t Key2:1;
            uint32_t Key3:1;
        } Bit;
    } KWUP_PortStatus;

    typedef union {
        uint32_t All;
        struct {
            uint32_t Key0:1;
            uint32_t Key1:1;
            uint32_t Key2:1;
            uint32_t Key3:1;
        } Bit;
    } KWUP_INTStatus;

/** @} */
/* End of group KWUP_Exported_Types */

/** @defgroup KWUP_Exported_FunctionPrototypes
  * @{
  */
    void KWUP_SetConfig(KWUP_SettingTypeDef * Settings);
    KWUP_PortStatus KWUP_GetPortStatus(void);
    void KWUP_SetPullUpConfig(KWUP_PullUpCycles T1, KWUP_PullUpCycles T2);
    void KWUP_ClearINTReq(void);
    KWUP_INTStatus KWUP_GetINTStatus(void);

/** @} */
/* End of group KWUP_Exported_FunctionPrototypes */

/** @} */
/* End of group KWUP */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /*__TMPM360_KWUP_H||__TMPM361_KWUP_H||__TMPM362_KWUP_H||__TMPM363_KWUP_H||__TMPM364_KWUP_H*/

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM363_KWUP_H */
