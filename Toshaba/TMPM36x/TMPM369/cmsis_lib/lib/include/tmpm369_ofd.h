/**
 *******************************************************************************
 * @file    tmpm369_ofd.h
 * @brief   This file provides all the functions prototypes for OFD driver.
 * @version V2.0.2.1
 * @date    2011/07/18
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
#ifndef __TMPM369_OFD_H
#define __TMPM369_OFD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM369.h"
#include "tx03_common.h"

#if defined(__TMPM369_OFD_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @addtogroup OFD
  * @{
  */
/** @addtogroup OFD_Exported_Types
  * @{
  */
#define IS_OFD_DETECT_FREQ_HIGHER(param)    ((param) <= 0x000001FFU)
#define IS_OFD_DETECT_FREQ_LOWER(param)     ((param) <= 0x000001FFU)

    typedef enum {
        OFD_IHOSC = 0U,         /* Internal High Frequency Oscillation */
        OFD_EHOSC = 1U          /* External High Frequency Oscillation */
    } OFD_OSCSource;
#define IS_OFD_OSC_SOURCE(param)            ((param) <= OFD_EHOSC)

    typedef enum {
        OFD_NORMAL = 0U,        /* Normal Detection Mode */
        OFD_MONITOR = 1U        /* Monitor Mode */
    } OFD_MonitorMode;
#define IS_OFD_MONITOR_MODE(param)            ((param) <= OFD_MONITOR)

    typedef union {
        uint32_t All;
        struct {
            uint32_t FrequencyError:1;
            uint32_t OFDBusy:1;
        } Bit;
    } OFD_Status;

/** @} */
/* End of group OFD_Exported_Types */

/** @defgroup OFD_Exported_FunctionPrototypes
  * @{
  */
    void OFD_SetRegWriteMode(FunctionalState NewState);
    void OFD_Enable(void);
    void OFD_Disable(void);
    void OFD_SetDetectionFrequency(OFD_OSCSource Source, uint32_t HigherDetectionCount,\
                                    uint32_t LowerDetectionCount);
    void OFD_Reset(FunctionalState NewState);
    OFD_Status OFD_GetStatus(void);
    void OFD_SetDetectionMonitor(OFD_MonitorMode Mode);

/** @} */
/* End of group OFD_Exported_FunctionPrototypes */
/** @} */
/* End of group OFD */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM369_OFD_H) */
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM369_OFD_H */
