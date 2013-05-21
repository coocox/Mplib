/**
 *******************************************************************************
 * @file    tmpm362_fc.c
 * @brief   This file provides API functions for FC driver.
 * @version V2.2.0
 * @date    2010/08/02
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
#include "tmpm362_fc.h"

#if defined(__TMPM361_FC_H) || defined(__TMPM362_FC_H) || defined(__TMPM363_FC_H) || defined(__TMPM364_FC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup FC 
  * @brief FC driver modules
  * @{
  */

/** @defgroup FC_Private_Defines
  * @{
  */

/** @} */
/* End of group FC_Private_Defines */

/** @defgroup FC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group FC_Private_FunctionPrototypes */

/** @defgroup FC_Private_Functions
  * @{
  */
#define SECBIT_SECBIT_PASSWORD   ((uint32_t)0xa74a9d23)
#define SECBIT_SECBIT_SET        ((uint32_t)0x00000001)
#define SECBIT_SECBIT_CLEAR      ((uint32_t)0xFFFFFFFE)

#define SECBIT_SECURITY_MASK     ((uint32_t)0x00000001)
#define SECBIT_DISABLE_FLAG      ((uint32_t)0x00000000)

#define FLCS_BUSY_MASK           ((uint32_t)0x00000001)
#define FLCS_BUSY_FLAG           ((uint32_t)0x00000000)

#define FLCS_BLOCK0_MASK         ((uint32_t)0x00010000)
#define FLCS_BLOCK1_MASK         ((uint32_t)0x00020000)
#define FLCS_BLOCK2_MASK         ((uint32_t)0x00040000)
#define FLCS_BLOCK3_MASK         ((uint32_t)0x00080000)
#define FLCS_BLOCK4_MASK         ((uint32_t)0x00100000)
#define FLCS_BLOCK5_MASK         ((uint32_t)0x00200000)
#define FLCS_BLOCK6_MASK         ((uint32_t)0x00400000)
#define FLCS_BLOCK7_MASK         ((uint32_t)0x00800000)
#define FLCS_BLOCK8_MASK         ((uint32_t)0x01000000)
#define FLCS_BLOCK9_MASK         ((uint32_t)0x02000000)

#define FLCS_BLOCK_FLAG          ((uint32_t)0x00000000)


/** @} */
/* End of group FC_Private_Functions */

/** @defgroup FC_Exported_Functions
  * @{
  */



/**
  * @brief  Set the value of SECBIT register,and this function shouldn't be interrupted.
  * @param  NewState: The value of SECBIT register.
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE.
  * @retval None
  */
void FC_SetSecurityBit(FunctionalState NewState)
{
    uint32_t tmp = TSB_FC->SECBIT;
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set FCSECBIT<SECBIT> to "1" that enable security function  */
        tmp |= SECBIT_SECBIT_SET;
    } else {
        /* Set FCSECBIT<SECBIT> to "0" that disable security function  */
        tmp &= SECBIT_SECBIT_CLEAR;
    }
    TSB_FC->SECBIT = SECBIT_SECBIT_PASSWORD;
    TSB_FC->SECBIT = tmp;
}

/**
  * @brief  Get the value of SECBIT register.
  * @param  None
  * @retval DISABLE or ENABLE
  *
  */
FunctionalState FC_GetSecurityBit(void)
{
    uint32_t tmp = 0U;
    FunctionalState retval = ENABLE;

    tmp = TSB_FC->SECBIT & SECBIT_SECURITY_MASK;

    /* Check disable flag */
    if (tmp == SECBIT_DISABLE_FLAG) {
        retval = DISABLE;
    } else {                    /* Check enable flag */
        retval = ENABLE;
    }
    return retval;
}

/**
  * @brief  Get the status of the flash auto operation.
  * @param  None
  * @retval BUSY or DONE
  *
  */
WorkState FC_GetBusyState(void)
{
    uint32_t tmp = 0U;
    WorkState retval = DONE;

    tmp = TSB_FC->FLCS & FLCS_BUSY_MASK;

    /* Check busy flag */
    if (tmp == FLCS_BUSY_FLAG) {
        retval = BUSY;
    } else {                    /* Check ready flag */
        retval = DONE;
    }
    return retval;
}

/**
  * @brief  Get the block Protection status.
  * @param  BlockNum: The flash block number.
  *   This parameter can be one of the following values:
  *   FC_BLOCK_0, FC_BLOCK_1, FC_BLOCK_2, FC_BLOCK_3,
  *   FC_BLOCK_4, FC_BLOCK_5, FC_BLOCK_6, FC_BLOCK_7,
  *   FC_BLOCK_8, FC_BLOCK_9
  * @retval DISABLE or ENABLE
  *
  */
FunctionalState FC_GetBlockProtectState(FC_BlockNum BlockNum)
{
    uint32_t tmp = FLCS_BLOCK_FLAG;
    FunctionalState retval = ENABLE;

    /* Check the parameters */
    assert_param(IS_FC_BLOCK_NUM(BlockNum));

    switch (BlockNum) {
    case FC_BLOCK_0:
        tmp = TSB_FC->FLCS & FLCS_BLOCK0_MASK;
        break;
    case FC_BLOCK_1:
        tmp = TSB_FC->FLCS & FLCS_BLOCK1_MASK;
        break;
    case FC_BLOCK_2:
        tmp = TSB_FC->FLCS & FLCS_BLOCK2_MASK;
        break;
    case FC_BLOCK_3:
        tmp = TSB_FC->FLCS & FLCS_BLOCK3_MASK;
        break;
    case FC_BLOCK_4:
        tmp = TSB_FC->FLCS & FLCS_BLOCK4_MASK;
        break;
    case FC_BLOCK_5:
        tmp = TSB_FC->FLCS & FLCS_BLOCK5_MASK;
        break;
    case FC_BLOCK_6:
        tmp = TSB_FC->FLCS & FLCS_BLOCK6_MASK;
        break;
    case FC_BLOCK_7:
        tmp = TSB_FC->FLCS & FLCS_BLOCK7_MASK;
        break;
    case FC_BLOCK_8:
        tmp = TSB_FC->FLCS & FLCS_BLOCK8_MASK;
        break;
    case FC_BLOCK_9:
        tmp = TSB_FC->FLCS & FLCS_BLOCK9_MASK;
        break;
    default:
        /* Do nothing */
        break;
    }
    if (tmp == FLCS_BLOCK_FLAG) {
        /* Return protection status of each block */
        retval = DISABLE;
    } else {
        retval = ENABLE;
    }
    return retval;
}

/** @} */
/* End of group FC_Exported_Functions */

/** @} */
/* End of group FC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM361_FC_H) || (__TMPM362_FC_H) || (__TMPM363_FC_H) || (__TMPM364_FC_H) */
