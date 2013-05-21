/**
 *******************************************************************************
 * @file    tmpm330_cec.h
 * @brief   This file provides all the functions prototypes for CEC driver.
 * @version V2.1.0
 * @date    2010/06/24
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
#ifndef __TMPM330_CEC_H
#define __TMPM330_CEC_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM330.h"
#include "tx03_common.h"

#if defined(__TMPM330_CEC_H) || defined(__TMPM332_CEC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup CEC
  * @{
  */

/** @addtogroup CEC_Exported_types
  * @{
  */
    typedef enum {
        CEC_TV = 0,
        CEC_RECORDING_DEVICE_1 = 1,
        CEC_RECORDING_DEVICE_2 = 2,
        CEC_STB_1 = 3,
        CEC_DVD_1 = 4,
        CEC_AUDIO_SYSTEM = 5,
        CEC_STB_2 = 6,
        CEC_STB_3 = 7,
        CEC_DVD_2 = 8,
        CEC_RECORDING_DEVICE_3 = 9,
        CEC_FREE_USE = 14,
        CEC_BROADCAST = 15,
        CEC_UNKNOWN = 16
    } CEC_LogicalAddr;
#define IS_CEC_LOGICAL_ADDR(param)  (((param) == CEC_TV) || \
                                     ((param) == CEC_RECORDING_DEVICE_1) || \
                                     ((param) == CEC_RECORDING_DEVICE_2) || \
                                     ((param) == CEC_STB_1) || \
                                     ((param) == CEC_DVD_1) || \
                                     ((param) == CEC_AUDIO_SYSTEM) || \
                                     ((param) == CEC_STB_2) || \
                                     ((param) == CEC_STB_3) || \
                                     ((param) == CEC_DVD_2) || \
                                     ((param) == CEC_RECORDING_DEVICE_3) || \
                                     ((param) == CEC_FREE_USE) || \
                                     ((param) == CEC_BROADCAST))

    typedef enum {
        CEC_HIGH_CANCELLATION_1 = 0,    /*!< 1 cycle */
        CEC_HIGH_CANCELLATION_2 = 1,    /*!< 2 cycles */
        CEC_HIGH_CANCELLATION_3 = 2,    /*!< 3 cycles */
        CEC_HIGH_CANCELLATION_4 = 3,    /*!< 4 cycles */
    } CEC_HighCancellation;
#define IS_CEC_HIGH_CANCELLATION(param)    (((param) == CEC_HIGH_CANCELLATION_1) || \
                                            ((param) == CEC_HIGH_CANCELLATION_2) || \
                                            ((param) == CEC_HIGH_CANCELLATION_3) || \
                                            ((param) == CEC_HIGH_CANCELLATION_4))

    typedef enum {
        CEC_LOW_CANCELLATION_1 = 0,     /*!< 1 cycle */
        CEC_LOW_CANCELLATION_2 = 1,     /*!< 2 cycles */
        CEC_LOW_CANCELLATION_3 = 2,     /*!< 3 cycles */
        CEC_LOW_CANCELLATION_4 = 3,     /*!< 4 cycles */
        CEC_LOW_CANCELLATION_5 = 4,     /*!< 5 cycles */
        CEC_LOW_CANCELLATION_6 = 5,     /*!< 6 cycles */
        CEC_LOW_CANCELLATION_7 = 6,     /*!< 7 cycles */
        CEC_LOW_CANCELLATION_8 = 7      /*!< 8 cycles */
    } CEC_LowCancellation;
#define IS_CEC_LOW_CANCELLATION(param)    (((param) == CEC_LOW_CANCELLATION_1) || \
                                           ((param) == CEC_LOW_CANCELLATION_2) || \
                                           ((param) == CEC_LOW_CANCELLATION_3) || \
                                           ((param) == CEC_LOW_CANCELLATION_4) || \
                                           ((param) == CEC_LOW_CANCELLATION_5) || \
                                           ((param) == CEC_LOW_CANCELLATION_6) || \
                                           ((param) == CEC_LOW_CANCELLATION_7) || \
                                           ((param) == CEC_LOW_CANCELLATION_8))

    typedef enum {
        CEC_CYCLE_MIN_0 = 0,    /*!< 2.05ms */
        CEC_CYCLE_MIN_1 = 1,    /*!< 2.05ms+1cycle */
        CEC_CYCLE_MIN_2 = 2,    /*!< 2.05ms+2cycles */
        CEC_CYCLE_MIN_3 = 3,    /*!< 2.05ms+3cycles */
        CEC_CYCLE_MIN_4 = 4,    /*!< 2.05ms-1cycle */
        CEC_CYCLE_MIN_5 = 5,    /*!< 2.05ms-2cycles */
        CEC_CYCLE_MIN_6 = 6,    /*!< 2.05ms-3cycles */
        CEC_CYCLE_MIN_7 = 7     /*!< 2.05ms-4cycles */
    } CEC_CycleMin;
#define IS_CEC_CYCLE_MIN(param)    (((param) == CEC_CYCLE_MIN_0) || \
                                    ((param) == CEC_CYCLE_MIN_1) || \
                                    ((param) == CEC_CYCLE_MIN_2) || \
                                    ((param) == CEC_CYCLE_MIN_3) || \
                                    ((param) == CEC_CYCLE_MIN_4) || \
                                    ((param) == CEC_CYCLE_MIN_5) || \
                                    ((param) == CEC_CYCLE_MIN_6) || \
                                    ((param) == CEC_CYCLE_MIN_7))

    typedef enum {
        CEC_CYCLE_MAX_0 = 0,    /*!< 2.75ms */
        CEC_CYCLE_MAX_1 = 1,    /*!< 2.75ms+1cycles */
        CEC_CYCLE_MAX_2 = 2,    /*!< 2.75ms+2cycles */
        CEC_CYCLE_MAX_3 = 3,    /*!< 2.75ms+3cycles */
        CEC_CYCLE_MAX_4 = 4,    /*!< 2.75ms-1cycles */
        CEC_CYCLE_MAX_5 = 5,    /*!< 2.75ms-2cycles */
        CEC_CYCLE_MAX_6 = 6,    /*!< 2.75ms-3cycles */
        CEC_CYCLE_MAX_7 = 7     /*!< 2.75ms-4cycles */
    } CEC_CycleMax;
#define IS_CEC_CYCLE_MAX(param)    (((param) == CEC_CYCLE_MAX_0) || \
                                    ((param) == CEC_CYCLE_MAX_1) || \
                                    ((param) == CEC_CYCLE_MAX_2) || \
                                    ((param) == CEC_CYCLE_MAX_3) || \
                                    ((param) == CEC_CYCLE_MAX_4) || \
                                    ((param) == CEC_CYCLE_MAX_5) || \
                                    ((param) == CEC_CYCLE_MAX_6) || \
                                    ((param) == CEC_CYCLE_MAX_7))

    typedef enum {
        CEC_VALID_TIME_0 = 0,   /*!< 1.05ms */
        CEC_VALID_TIME_1 = 1,   /*!< 1.05ms+2cycles */
        CEC_VALID_TIME_2 = 2,   /*!< 1.05ms+4cycles */
        CEC_VALID_TIME_3 = 3,   /*!< 1.05ms+6cycles */
        CEC_VALID_TIME_4 = 4,   /*!< 1.05ms-2cycles */
        CEC_VALID_TIME_5 = 5,   /*!< 1.05ms-4cycles */
        CEC_VALID_TIME_6 = 6    /*!< 1.05ms-6cycles */
    } CEC_ValidTime;
#define IS_CEC_DATA_VALID_TIME(param)    (((param) == CEC_VALID_TIME_0) ||\
                                          ((param) == CEC_VALID_TIME_1) ||\
                                          ((param) == CEC_VALID_TIME_2) ||\
                                          ((param) == CEC_VALID_TIME_3) ||\
                                          ((param) == CEC_VALID_TIME_4) ||\
                                          ((param) == CEC_VALID_TIME_5) ||\
                                          ((param) == CEC_VALID_TIME_6))

    typedef enum {
        CEC_TIME_OUT_1_BIT = 0, /*!< 1 bit cycle */
        CEC_TIME_OUT_2_BIT = 1, /*!< 2 bit cycle */
        CEC_TIME_OUT_3_BIT = 2  /*!< 3 bit cycle */
    } CEC_TimeOut;
#define IS_CEC_TIME_OUT(param)    (((param) == CEC_TIME_OUT_1_BIT) ||\
                                   ((param) == CEC_TIME_OUT_2_BIT) ||\
                                   ((param) == CEC_TIME_OUT_3_BIT))

    typedef enum {
        CEC_LOGICAL_1_RISING_TIME_MIN_0 = 0,    /*!< 0.4ms */
        CEC_LOGICAL_1_RISING_TIME_MIN_1 = 1,    /*!< 0.4ms-1cycle */
        CEC_LOGICAL_1_RISING_TIME_MIN_2 = 2,    /*!< 0.4ms-2cycles */
        CEC_LOGICAL_1_RISING_TIME_MIN_3 = 3,    /*!< 0.4ms-3cycles */
        CEC_LOGICAL_1_RISING_TIME_MIN_4 = 4,    /*!< 0.4ms-4cycles */
        CEC_LOGICAL_1_RISING_TIME_MIN_5 = 5,    /*!< 0.4ms-5cycles */
        CEC_LOGICAL_1_RISING_TIME_MIN_6 = 6,    /*!< 0.4ms-6cycles */
        CEC_LOGICAL_1_RISING_TIME_MIN_7 = 7     /*!< 0.4ms-7cycles */
    } CEC_Logical1RisingTimeMin;
#define IS_LOGICAL_1_RISING_TIME_MIN(param)    (((param) == CEC_LOGICAL_1_RISING_TIME_MIN_0) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_1) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_2) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_3) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_4) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_5) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_6) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MIN_7 ))

    typedef enum {
        CEC_LOGICAL_1_RISING_TIME_MAX_0 = 0,    /*!< 0.8ms */
        CEC_LOGICAL_1_RISING_TIME_MAX_1 = 1,    /*!< 0.8ms+1cycle */
        CEC_LOGICAL_1_RISING_TIME_MAX_2 = 2,    /*!< 0.8ms+2cycles */
        CEC_LOGICAL_1_RISING_TIME_MAX_3 = 3,    /*!< 0.8ms+3cycles */
        CEC_LOGICAL_1_RISING_TIME_MAX_4 = 4,    /*!< 0.8ms+4cycles */
        CEC_LOGICAL_1_RISING_TIME_MAX_5 = 5,    /*!< 0.8ms+5cycles */
        CEC_LOGICAL_1_RISING_TIME_MAX_6 = 6,    /*!< 0.8ms+6cycles */
        CEC_LOGICAL_1_RISING_TIME_MAX_7 = 7     /*!< 0.8ms+7cycles */
    } CEC_Logical1RisingTimeMax;
#define IS_LOGICAL_1_RISING_TIME_MAX(param)    (((param) == CEC_LOGICAL_1_RISING_TIME_MAX_0) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_1) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_2) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_3) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_4) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_5) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_6) || \
                                                ((param) == CEC_LOGICAL_1_RISING_TIME_MAX_7 ))

    typedef enum {
        CEC_LOGICAL_0_RISING_TIME_MIN_0 = 0,    /*!< 1.3ms */
        CEC_LOGICAL_0_RISING_TIME_MIN_1 = 1,    /*!< 1.3ms-1cycle */
        CEC_LOGICAL_0_RISING_TIME_MIN_2 = 2,    /*!< 1.3ms-2cycles */
        CEC_LOGICAL_0_RISING_TIME_MIN_3 = 3,    /*!< 1.3ms-3cycles */
        CEC_LOGICAL_0_RISING_TIME_MIN_4 = 4,    /*!< 1.3ms-4cycles */
        CEC_LOGICAL_0_RISING_TIME_MIN_5 = 5,    /*!< 1.3ms-5cycles */
        CEC_LOGICAL_0_RISING_TIME_MIN_6 = 6,    /*!< 1.3ms-6cycles */
        CEC_LOGICAL_0_RISING_TIME_MIN_7 = 7     /*!< 1.3ms-7cycles */
    } CEC_Logical0RisingTimeMin;
#define IS_LOGICAL_0_RISING_TIME_MIN(param)    (((param) == CEC_LOGICAL_0_RISING_TIME_MIN_0) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_1) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_2) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_3) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_4) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_5) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_6) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MIN_7 ))

    typedef enum {
        CEC_LOGICAL_0_RISING_TIME_MAX_0 = 0,    /*!< 1.7ms */
        CEC_LOGICAL_0_RISING_TIME_MAX_1 = 1,    /*!< 1.7ms+1cycle */
        CEC_LOGICAL_0_RISING_TIME_MAX_2 = 2,    /*!< 1.7ms+2cycles */
        CEC_LOGICAL_0_RISING_TIME_MAX_3 = 3,    /*!< 1.7ms+3cycles */
        CEC_LOGICAL_0_RISING_TIME_MAX_4 = 4,    /*!< 1.7ms+4cycles */
        CEC_LOGICAL_0_RISING_TIME_MAX_5 = 5,    /*!< 1.7ms+5cycles */
        CEC_LOGICAL_0_RISING_TIME_MAX_6 = 6,    /*!< 1.7ms+6cycles */
        CEC_LOGICAL_0_RISING_TIME_MAX_7 = 7     /*!< 1.7ms+7cycles */
    } CEC_Logical0RisingTimeMax;
#define IS_LOGICAL_0_RISING_TIME_MAX(param)    (((param) == CEC_LOGICAL_0_RISING_TIME_MAX_0) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_1) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_2) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_3) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_4) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_5) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_6) || \
                                                ((param) == CEC_LOGICAL_0_RISING_TIME_MAX_7 ))

    typedef enum {
        CEC_START_BIT_RISING_TIME_MIN_0 = 0,    /*!< 3.5ms */
        CEC_START_BIT_RISING_TIME_MIN_1 = 1,    /*!< 3.5ms-1cycle */
        CEC_START_BIT_RISING_TIME_MIN_2 = 2,    /*!< 3.5ms-2cycles */
        CEC_START_BIT_RISING_TIME_MIN_3 = 3,    /*!< 3.5ms-3cycles */
        CEC_START_BIT_RISING_TIME_MIN_4 = 4,    /*!< 3.5ms-4cycles */
        CEC_START_BIT_RISING_TIME_MIN_5 = 5,    /*!< 3.5ms-5cycles */
        CEC_START_BIT_RISING_TIME_MIN_6 = 6,    /*!< 3.5ms-6cycles */
        CEC_START_BIT_RISING_TIME_MIN_7 = 7     /*!< 3.5ms-7cycles */
    } CEC_StartBitRisingTimeMin;
#define IS_CEC_START_BIT_RISING_TIME_MIN(param)    (((param) == CEC_START_BIT_RISING_TIME_MIN_0) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_1) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_2) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_3) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_4) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_5) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_6) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MIN_7 ))

    typedef enum {
        CEC_START_BIT_RISING_TIME_MAX_0 = 0,    /*!< 3.9ms */
        CEC_START_BIT_RISING_TIME_MAX_1 = 1,    /*!< 3.9ms+1cycle */
        CEC_START_BIT_RISING_TIME_MAX_2 = 2,    /*!< 3.9ms+2cycles */
        CEC_START_BIT_RISING_TIME_MAX_3 = 3,    /*!< 3.9ms+3cycles */
        CEC_START_BIT_RISING_TIME_MAX_4 = 4,    /*!< 3.9ms+4cycles */
        CEC_START_BIT_RISING_TIME_MAX_5 = 5,    /*!< 3.9ms+5cycles */
        CEC_START_BIT_RISING_TIME_MAX_6 = 6,    /*!< 3.9ms+6cycles */
        CEC_START_BIT_RISING_TIME_MAX_7 = 7     /*!< 3.9ms+7cycles */
    } CEC_StartBitRisingTimeMax;
#define IS_CEC_START_BIT_RISING_TIME_MAX(param)    (((param) == CEC_START_BIT_RISING_TIME_MAX_0) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_1) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_2) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_3) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_4) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_5) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_6) || \
                                                    ((param) == CEC_START_BIT_RISING_TIME_MAX_7 ))

    typedef enum {
        CEC_START_BIT_CYCLE_MIN_0 = 0,  /*!< 4.3ms */
        CEC_START_BIT_CYCLE_MIN_1 = 1,  /*!< 4.3ms-1cycle */
        CEC_START_BIT_CYCLE_MIN_2 = 2,  /*!< 4.3ms-2cycles */
        CEC_START_BIT_CYCLE_MIN_3 = 3,  /*!< 4.3ms-3cycles */
        CEC_START_BIT_CYCLE_MIN_4 = 4,  /*!< 4.3ms-4cycles */
        CEC_START_BIT_CYCLE_MIN_5 = 5,  /*!< 4.3ms-5cycles */
        CEC_START_BIT_CYCLE_MIN_6 = 6,  /*!< 4.3ms-6cycles */
        CEC_START_BIT_CYCLE_MIN_7 = 7   /*!< 4.3ms-7cycles */
    } CEC_StartBitCycleMin;
#define IS_CEC_START_BIT_CYCLE_MIN(param)    (((param) == CEC_START_BIT_CYCLE_MIN_0) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_1) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_2) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_3) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_4) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_5) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_6) || \
                                              ((param) == CEC_START_BIT_CYCLE_MIN_7 ))

    typedef enum {
        CEC_START_BIT_CYCLE_MAX_0 = 0,  /*!< 4.7ms */
        CEC_START_BIT_CYCLE_MAX_1 = 1,  /*!< 4.7ms+1cycle */
        CEC_START_BIT_CYCLE_MAX_2 = 2,  /*!< 4.7ms+2cycles */
        CEC_START_BIT_CYCLE_MAX_3 = 3,  /*!< 4.7ms+3cycles */
        CEC_START_BIT_CYCLE_MAX_4 = 4,  /*!< 4.7ms+4cycles */
        CEC_START_BIT_CYCLE_MAX_5 = 5,  /*!< 4.7ms+5cycles */
        CEC_START_BIT_CYCLE_MAX_6 = 6,  /*!< 4.7ms+6cycles */
        CEC_START_BIT_CYCLE_MAX_7 = 7   /*!< 4.7ms+7cycles */
    } CEC_StartBitCycleMax;
#define IS_CEC_START_BIT_CYCLE_MAX(param)    (((param) == CEC_START_BIT_CYCLE_MAX_0) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_1) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_2) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_3) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_4) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_5) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_6) || \
                                              ((param) == CEC_START_BIT_CYCLE_MAX_7 ))

    typedef enum {
        CEC_TX_DATA_BIT_CYCLE_0 = 0,    /*!< RV (Reference value: 2.4ms approx.) */
        CEC_TX_DATA_BIT_CYCLE_1 = 1,    /*!< RV-1cycle */
        CEC_TX_DATA_BIT_CYCLE_2 = 2,    /*!< RV-2cycles */
        CEC_TX_DATA_BIT_CYCLE_3 = 3,    /*!< RV-3cycles */
        CEC_TX_DATA_BIT_CYCLE_4 = 4,    /*!< RV-4cycles */
        CEC_TX_DATA_BIT_CYCLE_5 = 5,    /*!< RV-5cycles */
        CEC_TX_DATA_BIT_CYCLE_6 = 6,    /*!< RV-6cycles */
        CEC_TX_DATA_BIT_CYCLE_7 = 7,    /*!< RV-7cycles */
        CEC_TX_DATA_BIT_CYCLE_8 = 8,    /*!< RV-8cycles */
        CEC_TX_DATA_BIT_CYCLE_9 = 9,    /*!< RV-9cycles */
        CEC_TX_DATA_BIT_CYCLE_10 = 10,  /*!< RV-10cycles */
        CEC_TX_DATA_BIT_CYCLE_11 = 11,  /*!< RV-11cycles */
        CEC_TX_DATA_BIT_CYCLE_12 = 12,  /*!< RV-12cycles */
        CEC_TX_DATA_BIT_CYCLE_13 = 13,  /*!< RV-13cycles */
        CEC_TX_DATA_BIT_CYCLE_14 = 14,  /*!< RV-14cycles */
        CEC_TX_DATA_BIT_CYCLE_15 = 15   /*!< RV-15cycles */
    } CEC_TxDataBitCycle;
#define IS_CEC_TX_DATA_BIT_CYCLE(param)    (((param) == CEC_TX_DATA_BIT_CYCLE_0) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_1) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_2) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_3) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_4) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_5) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_6) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_7) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_8) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_9) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_10) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_11) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_12) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_13) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_14) || \
                                            ((param) == CEC_TX_DATA_BIT_CYCLE_15 ))

    typedef enum {
        CEC_TX_DATA_BIT_RISING_TIME_0 = 0,      /*!< RV (logical "1": 0.6 ms approx.,logical "0": 1.5 ms approx) */
        CEC_TX_DATA_BIT_RISING_TIME_1 = 1,      /*!< RV-1cycle */
        CEC_TX_DATA_BIT_RISING_TIME_2 = 2,      /*!< RV-2cycles */
        CEC_TX_DATA_BIT_RISING_TIME_3 = 3,      /*!< RV-3cycles */
        CEC_TX_DATA_BIT_RISING_TIME_4 = 4,      /*!< RV-4cycles */
        CEC_TX_DATA_BIT_RISING_TIME_5 = 5,      /*!< RV-5cycles */
        CEC_TX_DATA_BIT_RISING_TIME_6 = 6,      /*!< RV-6cycles */
        CEC_TX_DATA_BIT_RISING_TIME_7 = 7       /*!< RV-7cycles */
    } CEC_TxDataBitRisingTime;
#define IS_CEC_TX_DATA_BIT_RISING_TIME(param)    (((param) == CEC_TX_DATA_BIT_RISING_TIME_0) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_1) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_2) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_3) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_4) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_5) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_6) || \
                                                  ((param) == CEC_TX_DATA_BIT_RISING_TIME_7 ))

    typedef enum {
        CEC_TX_START_BIT_CYCLE_0 = 0,   /*!< RV (4.5ms approx.) */
        CEC_TX_START_BIT_CYCLE_1 = 1,   /*!< RV-1cycle */
        CEC_TX_START_BIT_CYCLE_2 = 2,   /*!< RV-2cycles */
        CEC_TX_START_BIT_CYCLE_3 = 3,   /*!< RV-3cycles */
        CEC_TX_START_BIT_CYCLE_4 = 4,   /*!< RV-4cycles */
        CEC_TX_START_BIT_CYCLE_5 = 5,   /*!< RV-5cycles */
        CEC_TX_START_BIT_CYCLE_6 = 6,   /*!< RV-6cycles */
        CEC_TX_START_BIT_CYCLE_7 = 7    /*!< RV-7cycles */
    } CEC_TxStartBitCycle;
#define IS_CEC_TX_START_BIT_CYCLE(param)    (((param) == CEC_TX_START_BIT_CYCLE_0) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_1) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_2) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_3) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_4) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_5) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_6) || \
                                             ((param) == CEC_TX_START_BIT_CYCLE_7 ))

    typedef enum {
        CEC_TX_START_BIT_RISING_TIME_0 = 0,     /*!< RV (3.7ms approx.) */
        CEC_TX_START_BIT_RISING_TIME_1 = 1,     /*!< RV-1cycle */
        CEC_TX_START_BIT_RISING_TIME_2 = 2,     /*!< RV-2cycles */
        CEC_TX_START_BIT_RISING_TIME_3 = 3,     /*!< RV-3cycles */
        CEC_TX_START_BIT_RISING_TIME_4 = 4,     /*!< RV-4cycles */
        CEC_TX_START_BIT_RISING_TIME_5 = 5,     /*!< RV-5cycles */
        CEC_TX_START_BIT_RISING_TIME_6 = 6,     /*!< RV-6cycles */
        CEC_TX_START_BIT_RISING_TIME_7 = 7      /*!< RV-7cycles */
    } CEC_TxStartBitRisingTime;
#define IS_CEC_TX_START_BIT_RISING_TIME(param)    (((param) == CEC_TX_START_BIT_RISING_TIME_0) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_1) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_2) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_3) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_4) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_5) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_6) || \
                                                   ((param) == CEC_TX_START_BIT_RISING_TIME_7 ))


    typedef enum {
        CEC_BUS_FREE_1_BIT = 0, /*!< 1 bit cycle */
        CEC_BUS_FREE_2_BIT = 1, /*!< 2 bit cycle */
        CEC_BUS_FREE_3_BIT = 2, /*!< 3 bit cycle */
        CEC_BUS_FREE_4_BIT = 3, /*!< 4 bit cycle */
        CEC_BUS_FREE_5_BIT = 4, /*!< 5 bit cycle */
        CEC_BUS_FREE_6_BIT = 5, /*!< 6 bit cycle */
        CEC_BUS_FREE_7_BIT = 6, /*!< 7 bit cycle */
        CEC_BUS_FREE_8_BIT = 7, /*!< 8 bit cycle */
        CEC_BUS_FREE_9_BIT = 8, /*!< 9 bit cycle */
        CEC_BUS_FREE_10_BIT = 9,        /*!< 10 bit cycle */
        CEC_BUS_FREE_11_BIT = 10,       /*!< 11 bit cycle */
        CEC_BUS_FREE_12_BIT = 11,       /*!< 12 bit cycle */
        CEC_BUS_FREE_13_BIT = 12,       /*!< 13 bit cycle */
        CEC_BUS_FREE_14_BIT = 13,       /*!< 14 bit cycle */
        CEC_BUS_FREE_15_BIT = 14,       /*!< 15 bit cycle */
        CEC_BUS_FREE_16_BIT = 15        /*!< 16 bit cycle */
    } CEC_BusFree;
#define IS_CEC_BUS_FREE(param)    (((param) == CEC_BUS_FREE_1_BIT) || \
                                   ((param) == CEC_BUS_FREE_2_BIT) || \
                                   ((param) == CEC_BUS_FREE_3_BIT) || \
                                   ((param) == CEC_BUS_FREE_4_BIT) || \
                                   ((param) == CEC_BUS_FREE_5_BIT) || \
                                   ((param) == CEC_BUS_FREE_6_BIT) || \
                                   ((param) == CEC_BUS_FREE_7_BIT) || \
                                   ((param) == CEC_BUS_FREE_8_BIT) || \
                                   ((param) == CEC_BUS_FREE_9_BIT) || \
                                   ((param) == CEC_BUS_FREE_10_BIT) || \
                                   ((param) == CEC_BUS_FREE_11_BIT) || \
                                   ((param) == CEC_BUS_FREE_12_BIT) || \
                                   ((param) == CEC_BUS_FREE_13_BIT) || \
                                   ((param) == CEC_BUS_FREE_14_BIT) || \
                                   ((param) == CEC_BUS_FREE_15_BIT) || \
                                   ((param) == CEC_BUS_FREE_16_BIT ))

    typedef enum {
        CEC_NO_ACK = 0,
        CEC_ACK = !CEC_NO_ACK
    } CEC_ACKState;
#define IS_ACK_STATE(param) (((param) == CEC_ACK) || ((param) == CEC_NO_ACK))

    typedef enum {
        CEC_NO_EOM = 0,
        CEC_EOM = !CEC_NO_EOM
    } CEC_EOMBit;
#define IS_EOM_BIT(param) (((param) == CEC_EOM) || ((param) == CEC_NO_EOM))

    typedef union {
        uint32_t All;
        struct {
            uint32_t RxEnd:1;
            uint32_t RxStartBit:1;
            uint32_t MAXCycleErr:1;
            uint32_t MINCycleErr:1;
            uint32_t ACKCollision:1;
            uint32_t BufOverrun:1;
            uint32_t WaveformErr:1;
        } Bit;
    } CEC_RxINTState;

    typedef union {
        uint32_t All;
        struct {
            uint32_t TxStart:1;
            uint32_t TxEnd:1;
            uint32_t ArbitrationLost:1;
            uint32_t ACKErr:1;
            uint32_t BufUnderrun:1;
        } Bit;
    } CEC_TxINTState;

    typedef struct {
        uint8_t Data;
        CEC_ACKState ACKBit;
        CEC_EOMBit EOMBit;
    } CEC_DataTypeDef;

    typedef struct {
        uint8_t AddrNumber;
        CEC_LogicalAddr AddrList[16];
    } CEC_AddrListTypeDef;
/** @} */
/* End of group CEC_Exported_types */


/** @defgroup CEC_Exported_FunctionPrototypes
  * @{
  */
    void CEC_Enable(void);
    void CEC_Disable(void);
    void CEC_SWReset(void);
    Result CEC_DefaultConfig(void);
    Result CEC_SetLogicalAddr(CEC_LogicalAddr LogicalAddr);
    Result CEC_AddLogicalAddr(CEC_LogicalAddr LogicalAddr);
    Result CEC_RemoveLogicalAddr(CEC_LogicalAddr LogicalAddr);
    CEC_AddrListTypeDef CEC_GetLogicalAddr(void);
    void CEC_SetRxCtrl(FunctionalState NewState);
    Result CEC_StartTx(void);
    void CEC_StopTx(void);
    CEC_DataTypeDef CEC_GetRxData(void);
    void CEC_SetTxData(uint8_t Data, CEC_EOMBit EOM_Flag);
    void CEC_SetIdleMode(FunctionalState NewState);
    FunctionalState CEC_GetRxState(void);
    WorkState CEC_GetTxState(void);
    CEC_RxINTState CEC_GetRxINTState(void);
    CEC_TxINTState CEC_GetTxINTState(void);
    Result CEC_SetACKResponseMode(FunctionalState NewState);
    Result CEC_SetNoiseCancellation(CEC_LowCancellation LowCancellation,
                                    CEC_HighCancellation HighCancellation);
    Result CEC_SetCycleConfig(CEC_CycleMin CycleMin, CEC_CycleMax CycleMax);
    Result CEC_SetDataValidTime(CEC_ValidTime ValidTime);
    Result CEC_SetTimeOutMode(CEC_TimeOut TimeOut);
    Result CEC_SetRxErrINTSuspend(FunctionalState NewState);
    Result CEC_SetSnoopMode(FunctionalState NewState);
    Result CEC_SetRxDetectWaveConfig(CEC_Logical1RisingTimeMin Logical1RisingTimeMin,
                                     CEC_Logical1RisingTimeMax Logical1RisingTimeMax,
                                     CEC_Logical0RisingTimeMin Logical0RisingTimeMin,
                                     CEC_Logical0RisingTimeMax Logical0RisingTimeMax);
    Result CEC_SetRxStartBitWaveConfig(CEC_StartBitRisingTimeMin RisingTimeMin,
                                       CEC_StartBitRisingTimeMax RisingTimeMax,
                                       CEC_StartBitCycleMin CycleMin,
                                       CEC_StartBitCycleMax CycleMax);
    Result CEC_SetRxWaveErrDetect(FunctionalState NewState);
    Result CEC_SetTxWaveConfig(CEC_TxDataBitCycle DataBitCycle,
                               CEC_TxDataBitRisingTime DataBitRisingTime,
                               CEC_TxStartBitCycle StartBitCycle,
                               CEC_TxStartBitRisingTime StartBitRisingTime);
    Result CEC_SetTxBroadcast(FunctionalState NewState);
    Result CEC_SetBusFreeTime(CEC_BusFree BusFree);
/** @} */
/* End of group CEC_Exported_FunctionPrototypes */

/** @} */
/* End of group CEC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM330_CEC_H) || defined(__TMPM332_CEC_H) */

#ifdef __cplusplus
}
#endif
#endif /*__TMPM330_CEC_H */

