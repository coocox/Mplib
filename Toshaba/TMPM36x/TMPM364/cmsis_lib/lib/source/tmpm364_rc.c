/**
 *******************************************************************************
 * @file    tmpm364_rc.c
 * @brief   This file provides API functions for RC driver.
 * @version V2.2.0
 * @date    2010/06/23
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm364_rc.h"

#if defined(__TMPM360_RC_H) || defined(__TMPM361_RC_H) || defined(__TMPM362_RC_H) || defined(__TMPM363_RC_H) || defined(__TMPM364_RC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup RC 
  * @brief RC driver modules
  * @{
  */

/** @defgroup RC_Private_Defines
  * @{
  */
#define RCWAIT_RAMWAIT_SET     ((uint32_t)0x00000001)
#define RCWAIT_RAMWAIT_CLEAR   ((uint32_t)0x00000000)

#define RCWAIT_RAMWAIT_MASK    ((uint32_t)0x00000001)
#define RCWAIT_RAMWAIT_FLAG    ((uint32_t)0x00000001)

/** @} */
/* End of group RC_Private_Defines */

/** @defgroup RC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group RC_Private_FunctionPrototypes */

/** @defgroup RC_Private_Functions
  * @{
  */

/** @} */
/* End of group RC_Private_Functions */

/** @defgroup RC_Exported_Functions
  * @{
  */



/**
  * @brief  Set the value of RCWAIT register.
  * @param  RAMWait: The value of RCWAIT register.
  *   This parameter can be one of the following values:
  *   RC_RAMWAIT_0 or RC_RAMWAIT_1.
  * @retval None
  */
void RC_SetRAMWait(RC_RAMWait RAMWait)
{
    uint32_t tmp = TSB_RC->WAIT;
    /* Check the parameters */
    assert_param(IS_RC_RAMWAIT(RAMWait));

    if (RAMWait == RC_RAMWAIT_1) {
        /* Set RCWAIT<RAM1WAIT> to "1" */
        tmp |= RCWAIT_RAMWAIT_SET;
    } else {
        /* Set RCWAIT<RAM1WAIT> to "0" */
        tmp &= RCWAIT_RAMWAIT_CLEAR;
    }
    TSB_RC->WAIT = tmp;
}

/**
  * @brief  Get the value of RCWAIT register.
  * @param  None
  * @retval RC_RAMWAIT_0 or RC_RAMWAIT_1
  *
  */
RC_RAMWait RC_GetRAMWait(void)
{
    uint32_t tmp = 0U;
    RC_RAMWait retval = RC_RAMWAIT_1;

    tmp = TSB_RC->WAIT & RCWAIT_RAMWAIT_MASK;

    /* Check RAMWait flag */
    if (tmp == RCWAIT_RAMWAIT_FLAG) {
        retval = RC_RAMWAIT_1;
    } else {
        retval = RC_RAMWAIT_0;
    }
    return retval;
}

/** @} */
/* End of group RC_Exported_Functions */

/** @} */
/* End of group RC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM360_RC_H) || (__TMPM361_RC_H) || (__TMPM362_RC_H) || (__TMPM363_RC_H) || (__TMPM364_RC_H) */
