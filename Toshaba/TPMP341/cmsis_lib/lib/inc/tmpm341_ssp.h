/**
 *******************************************************************************
 * @file    tmpm341_ssp.h
 * @brief   This file provides all the functions prototypes for SSP driver.
 * @version V2.0.2.1
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
#ifndef __TMPM341_SSP_H
#define __TMPM341_SSP_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_SSP_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup SSP
  * @{
  */

/** @addtogroup SSP_Exported_types
  * @{
  */

    typedef enum {
        SSP_FORMAT_SPI = 0U,
        SSP_FORMAT_SSI = 1U,
        SSP_FORMAT_MICROWIRE = 2U
    } SSP_FrameFormat;
#define IS_SSP_FRAME_FORMAT(param)  (((param) == SSP_FORMAT_SPI) || \
                                     ((param) == SSP_FORMAT_SSI) || \
                                     ((param) == SSP_FORMAT_MICROWIRE))
    typedef enum {
        SSP_POLARITY_LOW = 0U,
        SSP_POLARITY_HIGH = 1U
    } SSP_ClkPolarity;
#define IS_SSP_CLK_POLARITY(param)  (((param) == SSP_POLARITY_LOW) || \
                                     ((param) == SSP_POLARITY_HIGH))

    typedef enum {
        SSP_PHASE_FIRST_EDGE = 0U,
        SSP_PHASE_SECOND_EDGE = 1U
    } SSP_ClkPhase;
#define IS_SSP_CLK_PHASE(param)  (((param) == SSP_PHASE_FIRST_EDGE) || \
                                  ((param) == SSP_PHASE_SECOND_EDGE))

    typedef enum {
        SSP_MASTER = 0U,
        SSP_SLAVE = 1U
    } SSP_MS_Mode;
#define IS_SSP_MS_MODE(param)  (((param) == SSP_MASTER) || \
                                ((param) == SSP_SLAVE))

    typedef enum {
        SSP_FIFO_EMPTY = 0U,
        SSP_FIFO_NORMAL = 1U,
        SSP_FIFO_INVALID = 2U,
        SSP_FIFO_FULL = 3U
    } SSP_FIFOState;

#define IS_SSP_PRE_SCALE(param)          (((param)>=2U)&&((param)<=254U)&&(((param)%2U)==0U))
#define IS_SSP_DATA_BIT_SIZE(param)      (((param)>=4U)&&((param)<=16U))

    typedef enum {
        SSP_RX = 0U,
        SSP_TX = 1U
    } SSP_Direction;
#define IS_SSP_DIRECTION(param)  (((param) == SSP_RX) || \
                                  ((param) == SSP_TX))

    typedef struct {
        SSP_FrameFormat FrameFormat;
        uint8_t PreScale;
        uint8_t ClkRate;
        SSP_ClkPolarity ClkPolarity;
        SSP_ClkPhase ClkPhase;
        uint8_t DataSize;
        SSP_MS_Mode Mode;
    } SSP_InitTypeDef;

/* parameter to config SSP Interrupt Enable/Disable Register */
#define SSP_INTCFG_NONE         ((uint32_t)0x00000000)
#define SSP_INTCFG_RX_OVERRUN   ((uint32_t)0x00000001)
#define SSP_INTCFG_RX_TIMEOUT   ((uint32_t)0x00000002)
#define SSP_INTCFG_RX           ((uint32_t)0x00000004)
#define SSP_INTCFG_TX           ((uint32_t)0x00000008)
#define SSP_INTCFG_ALL          ((uint32_t)0x0000000F)

#define IS_SSP_INT_SRC(param)  ((param) <= SSP_INTCFG_ALL )

#define IS_SSP_CLEAR_INT_SRC(param)  (((param) == SSP_INTCFG_RX_OVERRUN) || \
                                      ((param) == SSP_INTCFG_RX_TIMEOUT) || \
                                      ((param) == SSP_INTCFG_ALL) )

    typedef union {
        uint32_t All;
        struct {
            uint32_t OverRun:1; /* bit 0 , for TSB-M3 in IAR EWARM */
            uint32_t TimeOut:1;
            uint32_t Rx:1;
            uint32_t Tx:1;
            uint32_t Reserved:28;       /* bit 4 to 31 */
        } Bit;
    } SSP_INTState;

/** @} */
/* End of group SSP_Exported_types */

/** @defgroup SSP_Exported_FunctionPrototypes
  * @{
  */
    void SSP_Enable(void);
    void SSP_Disable(void);
    void SSP_Init(SSP_InitTypeDef * InitStruct);
    void SSP_SetClkPreScale(uint8_t PreScale, uint8_t ClkRate);
    void SSP_SetFrameFormat(SSP_FrameFormat FrameFormat);
    void SSP_SetClkPolarity(SSP_ClkPolarity ClkPolarity);
    void SSP_SetClkPhase(SSP_ClkPhase ClkPhase);
    void SSP_SetDataSize(uint8_t DataSize);
    void SSP_SetSlaveOutputCtrl(FunctionalState NewState);
    void SSP_SetMSMode(SSP_MS_Mode Mode);
    void SSP_SetLoopBackMode(FunctionalState NewState);
    void SSP_SetTxData(uint16_t Data);
    uint16_t SSP_GetRxData(void);
    WorkState SSP_GetWorkState(void);
    SSP_FIFOState SSP_GetFIFOState(SSP_Direction Direction);
    void SSP_SetINTConfig(uint32_t IntSrc);
    SSP_INTState SSP_GetINTConfig(void);
    SSP_INTState SSP_GetPreEnableINTState(void);
    SSP_INTState SSP_GetPostEnableINTState(void);
    void SSP_ClearINTFlag(uint32_t IntSrc);
    void SSP_SetDMACtrl(SSP_Direction Direction, FunctionalState NewState);
/** @} */
/* End of group SSP_Exported_FunctionPrototypes */

/** @} */
/* End of group SSP */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_SSP_H) */

#ifdef __cplusplus
}
#endif
#endif /*__TMPM341_SSP_H */
