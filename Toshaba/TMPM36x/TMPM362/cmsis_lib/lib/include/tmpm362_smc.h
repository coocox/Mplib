/**
 *******************************************************************************
 * @file    tmpm362_smc.h
 * @brief   This file provides all the functions prototypes for SMC driver.
 * @version V2.2.0
 * @date    2011/02/21
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
#ifndef __TMPM362_SMC_H
#define __TMPM362_SMC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM362.h"
#include "tx03_common.h"

#if defined(__TMPM360_SMC_H) || defined(__TMPM361_SMC_H) || defined(__TMPM362_SMC_H) || defined(__TMPM363_SMC_H) || defined(__TMPM364_SMC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup SMC
  * @{
  */

/** @addtogroup SMC_Exported_types
  * @{
  */
#define SMC_CMD_UPDATEREGS                 ((uint8_t)0x02)
#define IS_SMC_CMD(param)  ((param) == SMC_CMD_UPDATEREGS)

#define SMC_DATA_BUS_16BIT                 ((uint8_t)0x01)
#define IS_SMC_DATA_BUS(param)  ((param) == SMC_DATA_BUS_16BIT)

#define SMC_READ_BURST_1BEAT             ((uint8_t)0x00)
#define SMC_READ_BURST_4BEAT             ((uint8_t)0x01)
#define IS_SMC_READ_BURST(param) (((param) == SMC_READ_BURST_1BEAT) ||\
                                  ((param) == SMC_READ_BURST_4BEAT))

#define SMC_START_ADDR_CHIP0            ((uint8_t)0x60)
#define SMC_START_ADDR_CHIP1            ((uint8_t)0x61)
#define SMC_START_ADDR_CHIP2            ((uint8_t)0x62)
#define SMC_START_ADDR_CHIP3            ((uint8_t)0x63)

#define SMC_SEPARATE_SRAM               ((uint8_t)0x01)
#define SMC_MULTIPLEX_SRAM              ((uint8_t)0x03)

#define SMC_MEMORY_CHIPS_1              ((uint8_t)0x00)
#define SMC_MEMORY_CHIPS_2              ((uint8_t)0x01)
#define SMC_MEMORY_CHIPS_3              ((uint8_t)0x02)
#define SMC_MEMORY_CHIPS_4              ((uint8_t)0x03)

#define SMC_BUS_SEPARATE       ((uint8_t)0x00)
#define SMC_BUS_MULTIPLEX      ((uint8_t)0x01)

#if defined(__TMPM361_SMC_H) || defined(__TMPM363_SMC_H)
#define IS_SMC_BUS_MODE(param)  ((param) == SMC_BUS_MULTIPLEX)
#else                           /*defined(__TMPM360_SMC_H) || defined(__TMPM362_SMC_H) || defined(__TMPM364_SMC_H) */
#define IS_SMC_BUS_MODE(param)  (((param) == SMC_BUS_SEPARATE) || \
                                 ((param) == SMC_BUS_MULTIPLEX))
#endif                          /*defined(__TMPM361_SMC_H) || defined(__TMPM363_SMC_H) */

#define SMC_READ_CYCLE_TIME_2              ((uint8_t)0x02)
#define SMC_READ_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_READ_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_READ_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_READ_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_READ_CYCLE_TIME_7              ((uint8_t)0x07)
#define SMC_READ_CYCLE_TIME_8              ((uint8_t)0x08)
#define SMC_READ_CYCLE_TIME_9              ((uint8_t)0x09)
#define SMC_READ_CYCLE_TIME_10             ((uint8_t)0x0A)
#define SMC_READ_CYCLE_TIME_11             ((uint8_t)0x0B)
#define SMC_READ_CYCLE_TIME_12             ((uint8_t)0x0C)
#define SMC_READ_CYCLE_TIME_13             ((uint8_t)0x0D)
#define SMC_READ_CYCLE_TIME_14             ((uint8_t)0x0E)
#define SMC_READ_CYCLE_TIME_15             ((uint8_t)0x0F)

#define IS_SMC_READ_CYCLE_TIME(param)  (((param) == SMC_READ_CYCLE_TIME_2) || \
                                        ((param) == SMC_READ_CYCLE_TIME_3) || \
                                        ((param) == SMC_READ_CYCLE_TIME_4) || \
                                        ((param) == SMC_READ_CYCLE_TIME_5) || \
                                        ((param) == SMC_READ_CYCLE_TIME_6) || \
                                        ((param) == SMC_READ_CYCLE_TIME_7) || \
                                        ((param) == SMC_READ_CYCLE_TIME_8) || \
                                        ((param) == SMC_READ_CYCLE_TIME_9) || \
                                        ((param) == SMC_READ_CYCLE_TIME_10) || \
                                        ((param) == SMC_READ_CYCLE_TIME_11) || \
                                        ((param) == SMC_READ_CYCLE_TIME_12) || \
                                        ((param) == SMC_READ_CYCLE_TIME_13) || \
                                        ((param) == SMC_READ_CYCLE_TIME_14) || \
                                        ((param) == SMC_READ_CYCLE_TIME_15))

#define SMC_WRITE_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_WRITE_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_WRITE_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_WRITE_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_WRITE_CYCLE_TIME_7              ((uint8_t)0x07)
#define SMC_WRITE_CYCLE_TIME_8              ((uint8_t)0x08)
#define SMC_WRITE_CYCLE_TIME_9              ((uint8_t)0x09)
#define SMC_WRITE_CYCLE_TIME_10             ((uint8_t)0x0A)
#define SMC_WRITE_CYCLE_TIME_11             ((uint8_t)0x0B)
#define SMC_WRITE_CYCLE_TIME_12             ((uint8_t)0x0C)
#define SMC_WRITE_CYCLE_TIME_13             ((uint8_t)0x0D)
#define SMC_WRITE_CYCLE_TIME_14             ((uint8_t)0x0E)
#define SMC_WRITE_CYCLE_TIME_15             ((uint8_t)0x0F)
#define IS_SMC_WRITE_CYCLE_TIME(param)  (((param) == SMC_WRITE_CYCLE_TIME_3) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_4) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_5) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_6) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_7) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_8) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_9) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_10) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_11) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_12) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_13) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_14) || \
                                         ((param) == SMC_WRITE_CYCLE_TIME_15))

#define SMC_CEOE_DELAY_CYCLE_TIME_1              ((uint8_t)0x01)
#define SMC_CEOE_DELAY_CYCLE_TIME_2              ((uint8_t)0x02)
#define SMC_CEOE_DELAY_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_CEOE_DELAY_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_CEOE_DELAY_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_CEOE_DELAY_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_CEOE_DELAY_CYCLE_TIME_7              ((uint8_t)0x07)
#define IS_SMC_CEOE_DELAY_CYCLE_TIME(param)  (((param) == SMC_CEOE_DELAY_CYCLE_TIME_1) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_2) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_3) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_4) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_5) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_6) || \
                                              ((param) == SMC_CEOE_DELAY_CYCLE_TIME_7))

#define SMC_WE_PULSE_CYCLE_TIME_1              ((uint8_t)0x01)
#define SMC_WE_PULSE_CYCLE_TIME_2              ((uint8_t)0x02)
#define SMC_WE_PULSE_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_WE_PULSE_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_WE_PULSE_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_WE_PULSE_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_WE_PULSE_CYCLE_TIME_7              ((uint8_t)0x07)
#define IS_SMC_WE_PULSE_CYCLE_TIME(param)  (((param) == SMC_WE_PULSE_CYCLE_TIME_1) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_2) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_3) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_4) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_5) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_6) || \
                                            ((param) == SMC_WE_PULSE_CYCLE_TIME_7))

#define SMC_PAGE_CYCLE_TIME_1              ((uint8_t)0x01)
#define SMC_PAGE_CYCLE_TIME_2              ((uint8_t)0x02)
#define SMC_PAGE_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_PAGE_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_PAGE_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_PAGE_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_PAGE_CYCLE_TIME_7              ((uint8_t)0x07)

#define IS_SMC_PAGE_CYCLE_TIME(param)  (((param) == SMC_PAGE_CYCLE_TIME_1) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_2) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_3) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_4) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_5) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_6) || \
                                        ((param) == SMC_PAGE_CYCLE_TIME_7))

#define SMC_TURN_AROUND_CYCLE_TIME_1              ((uint8_t)0x01)
#define SMC_TURN_AROUND_CYCLE_TIME_2              ((uint8_t)0x02)
#define SMC_TURN_AROUND_CYCLE_TIME_3              ((uint8_t)0x03)
#define SMC_TURN_AROUND_CYCLE_TIME_4              ((uint8_t)0x04)
#define SMC_TURN_AROUND_CYCLE_TIME_5              ((uint8_t)0x05)
#define SMC_TURN_AROUND_CYCLE_TIME_6              ((uint8_t)0x06)
#define SMC_TURN_AROUND_CYCLE_TIME_7              ((uint8_t)0x07)

#define IS_SMC_TURN_AROUND_CYCLE_TIME(param)  (((param) == SMC_TURN_AROUND_CYCLE_TIME_1) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_2) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_3) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_4) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_5) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_6) || \
                                               ((param) == SMC_TURN_AROUND_CYCLE_TIME_7))

#define SMC_CS0              ((uint8_t)0x00)
#define SMC_CS1              ((uint8_t)0x01)
#define SMC_CS2              ((uint8_t)0x02)
#define SMC_CS3              ((uint8_t)0x03)

#define IS_SMC_CHIP_SELECT(param)  (((param) == SMC_CS0) || \
                                    ((param) == SMC_CS1) || \
                                    ((param) == SMC_CS2) || \
                                    ((param) == SMC_CS3))

    typedef struct {
        uint8_t MemoryType;
        uint8_t MemoryChips;
        uint8_t MemoryWidth;
    } SMC_IFConfigTypeDef;

    typedef struct {
        uint8_t RC_Time;
        uint8_t WC_Time;
        uint8_t CEOE_Time;
        uint8_t WP_Time;
        uint8_t PC_Time;
        uint8_t TR_Time;
    } SMC_CyclesTypeDef;

    typedef struct {
        uint8_t BusWidth;
        uint8_t ReadBurstLen;
        FunctionalState ALE;
        uint8_t StartAddr;
    } SMC_OpModeTypeDef;

    typedef struct {
        uint8_t CmdType;
        uint8_t ChipSelect;
    } SMC_DirectCMDTypeDef;

/** @} */
/* End of group SMC_Exported_types */

/** @defgroup SMC_Exported_FunctionPrototypes
  * @{
  */

    void SMC_SetBusMode(uint8_t BusMode);
    void SMC_GetIFConfig(SMC_IFConfigTypeDef * Config);
    void SMC_SendDirectCMD(SMC_DirectCMDTypeDef * Cmd);
    void SMC_SetCycles(SMC_CyclesTypeDef * Cycles);
    void SMC_SetOpMode(SMC_OpModeTypeDef * OpMode);
    void SMC_GetCycles(uint8_t ChipSelect, SMC_CyclesTypeDef * Cycles);
    void SMC_GetOpMode(uint8_t ChipSelect, SMC_OpModeTypeDef * OpMode);

/** @} */
/* End of group SMC_Exported_FunctionPrototypes */

/** @} */
/* End of group SMC */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM360_SMC_H) || defined(__TMPM361_SMC_H) || defined(__TMPM362_SMC_H) || defined(__TMPM363_SMC_H) || defined(__TMPM364_SMC_H) */

#ifdef __cplusplus
}
#endif
#endif /*__TMPM362_SMC_H */
