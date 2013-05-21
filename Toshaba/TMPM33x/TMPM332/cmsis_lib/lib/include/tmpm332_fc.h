/**
 *******************************************************************************
 * @file    tmpm332_fc.h
 * @brief   This file provides all the functions prototypes for FC driver.
 * @version V2.1.0
 * @date    2010/07/20
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
#ifndef __TMPM332_FC_H
#define __TMPM332_FC_H

#ifndef TMPM332FWUG
#define TMPM332FWUG

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM332.h"
#include "tx03_common.h"

#if defined(__TMPM330_FC_H) || defined(__TMPM332_FC_H) || defined(__TMPM333_FC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup FC
  * @{
  */

/** @addtogroup FC_Exported_types
  * @{
  */
#if defined(__TMPM330_FC_H) || defined(__TMPM333_FC_H)
#if defined(TMPM330FDFG) || defined(TMPM333FDFG)
    typedef enum {
        FC_BLOCK_0 = 0,
        FC_BLOCK_1 = 1,
        FC_BLOCK_2 = 2,
        FC_BLOCK_3 = 3,
        FC_BLOCK_4 = 4,
        FC_BLOCK_5 = 5
    } FC_BlockNum;

#define IS_FC_BLOCK_NUM(param)  (((param) == FC_BLOCK_0)|| \
                                 ((param) == FC_BLOCK_1)|| \
                                 ((param) == FC_BLOCK_2)|| \
                                 ((param) == FC_BLOCK_3)|| \
                                 ((param) == FC_BLOCK_4)|| \
                                 ((param) == FC_BLOCK_5))

#endif                          /* (TMPM330FDFG) || (TMPM333FDFG) */
#elif defined(__TMPM332_FC_H)
#ifdef TMPM332FWUG
    typedef enum {
        FC_BLOCK_0 = 0,
        FC_BLOCK_1 = 1,
        FC_BLOCK_2 = 2,
        FC_BLOCK_3 = 3
    } FC_BlockNum;

#define IS_FC_BLOCK_NUM(param)  (((param) == FC_BLOCK_0)|| \
                                 ((param) == FC_BLOCK_1)|| \
                                 ((param) == FC_BLOCK_2)|| \
                                 ((param) == FC_BLOCK_3))
#endif                          /* (TMPM332FWUG) */
#endif                          /* (__TMPM330_FC_H) */
/** @} */
/* End of group FC_Exported_types */

/** @defgroup FC_Exported_FunctionPrototypes
  * @{
  */

    void FC_SetSecurityBit(FunctionalState NewState);
    FunctionalState FC_GetSecurityBit(void);
    WorkState FC_GetBusyState(void);
    FunctionalState FC_GetBlockProtectState(FC_BlockNum BlockNum);

/** @} */
/* End of group FC_Exported_FunctionPrototypes */

/** @} */
/* End of group FC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /*(__TMPM330_FC_H) || (__TMPM332_FC_H) || (__TMPM333_FC_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* TMPM332FWUG */
#endif                          /* __TMPM332_FC_H */
