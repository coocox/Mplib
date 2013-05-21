/**
 *******************************************************************************
 * @file    tmpm363_rc.h
 * @brief   This file provides all the functions prototypes for RC driver.
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
#ifndef __TMPM363_RC_H
#define __TMPM363_RC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM363.h"
#include "tx03_common.h"

#if defined(__TMPM360_RC_H) || defined(__TMPM361_RC_H) || defined(__TMPM362_RC_H) || defined(__TMPM363_RC_H) || defined(__TMPM364_RC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup RC
  * @{
  */

/** @addtogroup RC_Exported_types
  * @{
  */

    typedef enum {
        RC_RAMWAIT_0 = 0U,
        RC_RAMWAIT_1 = 1U
    } RC_RAMWait;

#define IS_RC_RAMWAIT(param)  (((param) == RC_RAMWAIT_0)||((param) == RC_RAMWAIT_1))

/** @} */
/* End of group RC_Exported_types */

/** @defgroup RC_Exported_FunctionPrototypes
  * @{
  */

    void RC_SetRAMWait(RC_RAMWait RAMWait);
    RC_RAMWait RC_GetRAMWait(void);

/** @} */
/* End of group RC_Exported_FunctionPrototypes */

/** @} */
/* End of group RC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /*(__TMPM360_RC_H) || (__TMPM361_RC_H) || (__TMPM362_RC_H) || (__TMPM363_RC_H) || (__TMPM364_RC_H)  */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM363_RC_H */
