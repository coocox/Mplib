/**
 *******************************************************************************
 * @file    tmpm061_fc.h
 * @brief   This file provides all the functions prototypes for FC driver.
 * @version V2.0.2.1
 * @date    2012/03/30
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
#ifndef __TMPM061_FC_H
#define __TMPM061_FC_H

          

/* #define _SINGLE_BOOT_MODE */

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

#if defined(__TMPM061_FC_H)
/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @addtogroup FC
  * @{
  */

/** @defgroup FC_Exported_Types
  * @{
  */
    typedef enum {
        FC_SUCCESS = 0U,
        FC_ERROR_PROTECTED = 1U,
        FC_ERROR_OVER_TIME = 2U
    } FC_Result;

/** @} */
/* End of group FC_Exported_Types */

/** @defgroup FC_Exported_Constants
  * @{
  */
#define FLASH_PAGE_SIZE                 ((uint32_t)0x00000080)  /* Page Size 32 words */


#define FC_BLOCK_0                      ((uint8_t)0x00)
#define FC_BLOCK_1                      ((uint8_t)0x01)
#define FC_BLOCK_2                      ((uint8_t)0x02)
#define FC_BLOCK_3                      ((uint8_t)0x03)


#define FLASH_CHIP_SIZE                 ((uint32_t)0x00020000)  /* Flash chip size is 128KByte */
#define IS_FC_BLOCK_NUM(param)          (((param) == FC_BLOCK_0) || \
                                         ((param) == FC_BLOCK_1) || \
                                         ((param) == FC_BLOCK_2) || \
                                         ((param) == FC_BLOCK_3))

#define FC_BLOCK_GROUP_0                 ((uint8_t)0x00)

#define IS_FC_BLOCK_GROUP(param)        ((param) == FC_BLOCK_GROUP_0)


#ifdef SINGLE_BOOT_MODE
#define FLASH_START_ADDR                 ((uint32_t)0x3F800000) /* SINGLE_BOOT_MODE */
#else
#define FLASH_START_ADDR                 ((uint32_t)0x00000000) /* User Boot Mode As Default */
#endif

#define FLASH_END_ADDR                   (FLASH_START_ADDR + FLASH_CHIP_SIZE - 1U)

#ifdef SINGLE_BOOT_MODE
#define IS_FC_ADDR(param)                (((param) >= FLASH_START_ADDR) && \
                                          ((param) <= FLASH_END_ADDR))
#else
#define IS_FC_ADDR(param)                ((param) <= FLASH_END_ADDR)
#endif

#define IS_FC_PAGE_ADDR(param)          ((((param) - FLASH_START_ADDR) % FLASH_PAGE_SIZE) == 0U)

/** @} */
/* End of group FC_Exported_Constants */


/** @defgroup FC_Exported_FunctionPrototypes
  * @{
  */

    void FC_SetSecurityBit(FunctionalState NewState);
    FunctionalState FC_GetSecurityBit(void);
    WorkState FC_GetBusyState(void);
    FunctionalState FC_GetBlockProtectState(uint8_t BlockNum);
    FC_Result FC_ProgramBlockProtectState(uint8_t BlockNum);
    FC_Result FC_EraseBlockProtectState(uint8_t BlockGroup);
    FC_Result FC_WritePage(uint32_t PageAddr, uint32_t * Data);
    FC_Result FC_EraseBlock(uint32_t BlockAddr);
    FC_Result FC_EraseChip(void);

/** @} */
/* End of group FC_Exported_FunctionPrototypes */

/** @} */
/* End of group FC */

/** @} */
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_FC_H)*/

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM061_FC_H */
