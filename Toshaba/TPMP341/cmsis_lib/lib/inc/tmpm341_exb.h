/**
 *******************************************************************************
 * @file    tmpm341_exb.h
 * @brief   This file provides all the functions prototypes for EXB driver.
 * @version V2.0.2.1
 * @date    2011/02/15
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM341_EXB_H
#define __TMPM341_EXB_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup EXB
  * @{
  */

/** @addtogroup EXB_Exported_types
  * @{
  */

#define EXB_BUS_MULTIPLEX      ((uint8_t)0x00)
#define EXB_BUS_SEPARATE       ((uint8_t)0x01)
#define IS_EXB_BUS_MODE(param)  (((param) == EXB_BUS_MULTIPLEX) || \
                                 ((param) == EXB_BUS_SEPARATE))

#define EXB_CYCLE_NONE                 ((uint8_t)0x00)
#define EXB_CYCLE_DOUBLE               ((uint8_t)0x02)
#define EXB_CYCLE_QUADRUPLE            ((uint8_t)0x04)
#define IS_EXB_BUS_CYCLE_EXTENSION(param)  (((param) == EXB_CYCLE_NONE) || \
                                            ((param) == EXB_CYCLE_DOUBLE) || \
                                            ((param) == EXB_CYCLE_QUADRUPLE))

#define EXB_16M_BYTE              ((uint8_t)0x00)
#define EXB_8M_BYTE               ((uint8_t)0x01)
#define EXB_4M_BYTE               ((uint8_t)0x02)
#define EXB_2M_BYTE               ((uint8_t)0x03)
#define EXB_1M_BYTE               ((uint8_t)0x04)
#define EXB_512K_BYTE             ((uint8_t)0x05)
#define EXB_256K_BYTE             ((uint8_t)0x06)
#define EXB_128K_BYTE             ((uint8_t)0x07)
#define EXB_64K_BYTE              ((uint8_t)0x08)
#define IS_EXB_ADDR_SPACE_SIZE(param) ((param) < 0x09U)

#define EXB_BUS_WIDTH_BIT_8              ((uint8_t)0x00)
#define EXB_BUS_WIDTH_BIT_16             ((uint8_t)0x02)
#define IS_EXB_DATA_BUS_WIDTH(param)  (((param) == EXB_BUS_WIDTH_BIT_8) || \
                                       ((param) == EXB_BUS_WIDTH_BIT_16))

#define EXB_INTERNAL_WAIT_0             ((uint8_t)0x00)
#define EXB_INTERNAL_WAIT_1             ((uint8_t)0x01)
#define EXB_INTERNAL_WAIT_2             ((uint8_t)0x02)
#define EXB_INTERNAL_WAIT_3             ((uint8_t)0x03)
#define EXB_INTERNAL_WAIT_4             ((uint8_t)0x04)
#define EXB_INTERNAL_WAIT_5             ((uint8_t)0x05)
#define EXB_INTERNAL_WAIT_6             ((uint8_t)0x06)
#define EXB_INTERNAL_WAIT_7             ((uint8_t)0x07)
#define EXB_INTERNAL_WAIT_8             ((uint8_t)0x08)
#define EXB_INTERNAL_WAIT_9             ((uint8_t)0x09)
#define EXB_INTERNAL_WAIT_10            ((uint8_t)0x0A)
#define EXB_INTERNAL_WAIT_11            ((uint8_t)0x0B)
#define EXB_INTERNAL_WAIT_12            ((uint8_t)0x0C)
#define EXB_INTERNAL_WAIT_13            ((uint8_t)0x0D)
#define EXB_INTERNAL_WAIT_14            ((uint8_t)0x0E)
#define EXB_INTERNAL_WAIT_15            ((uint8_t)0x0F)
#define IS_EXB_INTERNAL_WAIT(param)     ((param) <= EXB_INTERNAL_WAIT_15)

#define EXB_CYCLE_0              ((uint8_t)0x00)
#define EXB_CYCLE_1              ((uint8_t)0x01)
#define EXB_CYCLE_2              ((uint8_t)0x02)
#define EXB_CYCLE_3              ((uint8_t)0x03)
#define EXB_CYCLE_4              ((uint8_t)0x04)
#define EXB_CYCLE_5              ((uint8_t)0x05)
#define EXB_CYCLE_6              ((uint8_t)0x06)
#define EXB_CYCLE_8              ((uint8_t)0x07)
#define IS_EXB_RW_SETUP_CYCLE(param)  ((param) <= EXB_CYCLE_4)

#define IS_EXB_ALE_WAIT_CYCLE(param)  ((param) <= EXB_CYCLE_4)

#define IS_EXB_RW_RECOVERY_CYCLE(param)  ((param) <= EXB_CYCLE_8)

#define IS_EXB_CS_RECOVERY_CYCLE(param)  ((param) <= EXB_CYCLE_4)

#define EXB_CS0              ((uint8_t)0x00)
#define EXB_CS1              ((uint8_t)0x01)
#define IS_EXB_CHIP_SELECT(param)  (((param) == EXB_CS0) || \
                                    ((param) == EXB_CS1))

    typedef struct {
        uint8_t InternalWait;
        uint8_t ReadSetupCycle;
        uint8_t WriteSetupCycle;
        uint8_t ALEWaitCycle;
        uint8_t ReadRecoveryCycle;
        uint8_t WriteRecoveryCycle;
        uint8_t ChipSelectRecoveryCycle;
    } EXB_CyclesTypeDef;

    typedef struct {
        uint8_t AddrSpaceSize;
        uint8_t StartAddr;
        uint8_t BusWidth;
        EXB_CyclesTypeDef Cycles;
    } EXB_InitTypeDef;

/** @} */
/* End of group EXB_Exported_types */

/** @defgroup EXB_Exported_FunctionPrototypes
  * @{
  */

    void EXB_SetBusMode(uint8_t BusMode);
    void EXB_SetBusCycleExtension(uint8_t Cycle);
    void EXB_Enable(uint8_t ChipSelect);
    void EXB_Disable(uint8_t ChipSelect);
    void EXB_Init(uint8_t ChipSelect, EXB_InitTypeDef * InitStruct);

/** @} */
/* End of group EXB_Exported_FunctionPrototypes */

/** @} */
/* End of group EXB */

/** @} */
/* End of group TX03_Periph_Driver */

#ifdef __cplusplus
}
#endif
#endif /*__TMPM341_EXB_H */
