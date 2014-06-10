/**
 *******************************************************************************
 * @file    tmpm341_ssp.c
 * @brief   This file provides API functions for SSP driver.
 * @version V2.0.2.1
 * @date    2011/03/02
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
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "tmpm341_ssp.h"

#if defined(__TMPM341_SSP_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup SSP
  * @brief SSP driver modules
  * @{
  */

/** @defgroup SSP_Private_Defines
  * @{
  */

#define SSP_ENABLE_SET                 ((uint32_t)0x00000002)
#define SSP_CR1_MASK                   ((uint32_t)0x0000000F)
#define SSP_ENABLE_CLEAR               ((uint32_t)0x0000000D)

#define SSP_SCR_MASK                   ((uint32_t)0x000000FF)
#define SSP_FORMAT_MASK                ((uint32_t)0x0000FFCF)
#define SSP_SPO_MASK                   ((uint32_t)0x0000FFBF)
#define SSP_SPH_MASK                   ((uint32_t)0x0000FF7F)
#define SSP_DSS_MASK                   ((uint32_t)0x0000FFF0)
#define SSP_SOD_SET                    ((uint32_t)0x00000008)
#define SSP_SOD_CLEAR                  ((uint32_t)0x00000007)

#define SSP_MS_SETSLAVE                ((uint32_t)0x00000004)
#define SSP_MS_MASK                    ((uint32_t)0x0000000B)

#define SSP_LBM_SET                    ((uint32_t)0x00000001)
#define SSP_LBM_CLEAR                  ((uint32_t)0x0000000E)

#define SSP_BSY_MASK                   ((uint32_t)0x00000010)

#define SSP_TXFIFO_SR_MASK             ((uint32_t)0x00000003)
#define SSP_RXFIFO_SR_MASK             ((uint32_t)0x0000000C)

#define SSP_IMSC_MASK                  ((uint32_t)0x0000000F)
#define SSP_RIS_MASK                   ((uint32_t)0x0000000F)
#define SSP_MIS_MASK                   ((uint32_t)0x0000000F)

#define SSP_DMA_MASK                   ((uint32_t)0x00000003)


#define SSP_TXFIFO_FULL       0U
#define SSP_TXFIFO_INVALID    1U
#define SSP_TXFIFO_NORMAL     2U
#define SSP_TXFIFO_EMPTY      3U

#define SSP_RXFIFO_FULL       3U
#define SSP_RXFIFO_INVALID    2U
#define SSP_RXFIFO_NORMAL     1U
#define SSP_RXFIFO_EMPTY      0U

/** @} */
/* End of group SSP_Private_Defines */

/** @defgroup SSP_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group SSP_Private_FunctionPrototypes */

/** @defgroup SSP_Private_Functions
  * @{
  */

/** @} */
/* End of group SSP_Private_Functions */

/** @defgroup SSP_Exported_Functions
  * @{
  */

/**
  * @brief Enable the SSP channel
  * @param None
  * @retval None
  */
void SSP_Enable(void)
{
    uint32_t tmp = 0U;

    tmp = TSB_SSP->CR1 & SSP_CR1_MASK;

    /* Set bit1 which is CR1<SSE> to enable SSP module */
    tmp |= SSP_ENABLE_SET;

    TSB_SSP->CR1 = tmp;
}

/**
  * @brief Disable the SSP channel
  * @param None
  * @retval None
  */
void SSP_Disable(void)
{
    /* clear CR1<SSE>, bit1, to disable SSP module */
    TSB_SSP->CR1 &= SSP_ENABLE_CLEAR;
}

/**
  * @brief Initialize the SSP channel through the data in structure SSP_InitTypeDef
  * @param  InitStruct:  Parameters to configure SSP module,
  *     It includes data to set Frame Format, Bit Rate, Clock Phase and Polority, DataSize and Mode.
  * @retval None
  */
void SSP_Init(SSP_InitTypeDef * InitStruct)
{
    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(InitStruct));

    SSP_SetFrameFormat(InitStruct->FrameFormat);
    SSP_SetClkPreScale(InitStruct->PreScale, InitStruct->ClkRate);
    SSP_SetClkPolarity(InitStruct->ClkPolarity);
    SSP_SetClkPhase(InitStruct->ClkPhase);
    SSP_SetDataSize(InitStruct->DataSize);
    SSP_SetMSMode(InitStruct->Mode);
}

/**
  * @brief Set the bit rate for transmit and receive for the SSP channel.
  *          BitRate = fSYS / (PreScale x (1 + ClkRate))
  * @param  PreScale: Clock prescale divider(even number from 2 to 254)
  * @param  ClkRate: serial clock rate (From 0 to 255)
  * @retval None
  */
void SSP_SetClkPreScale(uint8_t PreScale, uint8_t ClkRate)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_PRE_SCALE(PreScale));

    tmp = TSB_SSP->CR0 & SSP_SCR_MASK;
    tmp |= ((uint32_t) ClkRate) << 8U;
    /*Set serial clock rate */
    TSB_SSP->CR0 = tmp;

    /*Set clock prescale divider */
    TSB_SSP->CPSR = (uint32_t) PreScale;
}

/**
  * @brief Specify the Frame Format of SSP channel.
  * @param  FrameFormat: Frame Format of SSP
  *   This parameter can be one of the following values:
  *         SSP_FORMAT_SPI,
  *         SSP_FORMAT_SSI,
  *         SSP_FORMAT_MICROWIRE
  * @retval None
  */
void SSP_SetFrameFormat(SSP_FrameFormat FrameFormat)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_FRAME_FORMAT(FrameFormat));

    tmp = TSB_SSP->CR0 & SSP_FORMAT_MASK;
    tmp |= ((uint32_t) FrameFormat) << 4U;
    /*Set Frame Format */
    TSB_SSP->CR0 = tmp;
}

/**
  * @brief When SSP channel is configured as SPI mode, specify the clock polarity in its idle state.
  * @param  ClkPolarity: SPI clock polarity
  *  This parameter can be one of the following values:
  *         SSP_POLARITY_LOW,
  *         SSP_POLARITY_HIGH
  * @retval None
  */
void SSP_SetClkPolarity(SSP_ClkPolarity ClkPolarity)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_CLK_POLARITY(ClkPolarity));

    tmp = TSB_SSP->CR0 & SSP_SPO_MASK;
    tmp |= ((uint32_t) ClkPolarity) << 6U;
    /*Set clock polarity */
    TSB_SSP->CR0 = tmp;
}

/**
  * @brief When SSP channel is configured as SPI mode, specify its clock phase.
  * @param  ClkPolarity: SPI clock phase
  *  This parameter can be one of the following values:
  *         SSP_PHASE_FIRST_EDGE,
  *         SSP_PHASE_SECOND_EDGE
  * @retval None
  */
void SSP_SetClkPhase(SSP_ClkPhase ClkPhase)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_CLK_PHASE(ClkPhase));

    tmp = TSB_SSP->CR0 & SSP_SPH_MASK;
    tmp |= ((uint32_t) ClkPhase) << 7U;
    /*Set clock phase */
    TSB_SSP->CR0 = tmp;
}

/**
  * @brief Set the Rx/Tx data size for the SSP channel.
  * @param  DataSize: Data size select. From 4 to 16
  * @retval None
  */
void SSP_SetDataSize(uint8_t DataSize)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_DATA_BIT_SIZE(DataSize));

    tmp = TSB_SSP->CR0 & SSP_DSS_MASK;
    tmp |= ((uint32_t) DataSize - 1U);
    /*Set Rx/Tx Data Size */
    TSB_SSP->CR0 = tmp;
}

/**
  * @brief Enable/Disable slave mode output for the SSP channel.
  * @param  NewState: New state of slave mode output setting.
  *    This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void SSP_SetSlaveOutputCtrl(FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* read SFR then clear other bits, also clear bit3 as Enable it */
    tmp = TSB_SSP->CR1 & SSP_SOD_CLEAR;

    if (NewState == DISABLE) {
        /* if disable, Set bit3 : CR1<SOD>  */
        tmp |= SSP_SOD_SET;
    } else {
        /* do nothing */
    }

    TSB_SSP->CR1 = tmp;
}

/**
  * @brief Set the SSP Master or Slave mode for the SSP channel.
  * @param  Mode: SSP device mode
  *   This parameter can be SSP_MASTER or SSP_SLAVE.
  * @retval None
  */
void SSP_SetMSMode(SSP_MS_Mode Mode)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_MS_MODE(Mode));

    /* read SFR then clear other bits, also clear bit2 as select Master Mode */
    tmp = TSB_SSP->CR1 & SSP_MS_MASK;

    if (Mode == SSP_SLAVE) {
        /* if select slave, Set bit2 : CR1<MS>  */
        tmp |= SSP_MS_SETSLAVE;
    } else {
        /* do nothing */
    }

    TSB_SSP->CR1 = tmp;
}

/**
  * @brief Set loop back mode of SSP for the SSP channel.
  * @param  NewState: New state of loop back mode.
  *     This parameter can be one of the following values:
  *         ENABLE,
  *         DISABLE
  * @retval None
  */
void SSP_SetLoopBackMode(FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* read SFR then clear other bits, also clear bit0 as disable it */
    tmp = TSB_SSP->CR1 & SSP_LBM_CLEAR;

    if (NewState == ENABLE) {
        /* if enable, Set bit0: CR1<LBM> */
        tmp |= SSP_LBM_SET;
    } else {
        /* do nothing */
    }

    TSB_SSP->CR1 = tmp;
}

/**
  * @brief Set the data to be sent into Tx FIFO of the SSP channel.
  * @param  Data: the 4~16bit data to be send
  * @retval None
  */
void SSP_SetTxData(uint16_t Data)
{
    TSB_SSP->DR = (uint32_t) Data;
}

/**
  * @brief Read the data received from Rx FIFO of the SSP channel.
  * @retval The 4~16bit data received from FIFO.
  */
uint16_t SSP_GetRxData(void)
{
    return ((uint16_t) (TSB_SSP->DR));
}

/**
  * @brief Get the Busy or Idle state of the SSP channel
  * @retval The state of SSP, which can be BUSY or DONE
  */
WorkState SSP_GetWorkState(void)
{
    WorkState tmp = DONE;

    /*check the bit 'BSY'(bit4) of register SSPSR, */
    /* 1 == busy, 0 == idle or done */
    if (TSB_SSP->SR & SSP_BSY_MASK) {
        tmp = BUSY;
    } else {
        tmp = DONE;
    }

    return tmp;
}

/**
  * @brief Get the Rx/Tx FIFO state of the SSP channel
  * @param Direction: the communication direction which will be check.
  *     it can be one of the following values:
  *         SSP_TX
            SSP_RX
  * @retval The state of Rx/Tx FIFO,
  *     it can be one of the following values:
            SSP_FIFO_EMPTY
            SSP_FIFO_NORMAL
            SSP_FIFO_INVALID
            SSP_FIFO_FULL
  */
SSP_FIFOState SSP_GetFIFOState(SSP_Direction Direction)
{
    uint32_t src = 0U;
    SSP_FIFOState tgt = SSP_FIFO_EMPTY;

    /* Check the parameters */
    assert_param(IS_SSP_DIRECTION(Direction));

    src = TSB_SSP->SR;
    if (Direction == SSP_TX) {
        src &= SSP_TXFIFO_SR_MASK;
        switch (src) {
        case SSP_TXFIFO_FULL:
            tgt = SSP_FIFO_FULL;
            break;
        case SSP_TXFIFO_INVALID:
            tgt = SSP_FIFO_INVALID;
            break;
        case SSP_TXFIFO_NORMAL:
            tgt = SSP_FIFO_NORMAL;
            break;
        case SSP_TXFIFO_EMPTY:
            tgt = SSP_FIFO_EMPTY;
            break;
        default:
            /* do nothing */
            break;
        }
    } else {
        src &= SSP_RXFIFO_SR_MASK;
        src >>= 2U;
        switch (src) {
        case SSP_RXFIFO_FULL:
            tgt = SSP_FIFO_FULL;
            break;
        case SSP_RXFIFO_INVALID:
            tgt = SSP_FIFO_INVALID;
            break;
        case SSP_RXFIFO_NORMAL:
            tgt = SSP_FIFO_NORMAL;
            break;
        case SSP_RXFIFO_EMPTY:
            tgt = SSP_FIFO_EMPTY;
            break;
        default:
            /* do nothing */
            break;
        }
    }

    return tgt;
}

/**
  * @brief Enable/Disable interrupt source of the SSP channel
  * @param INTSrc: The id for interrupt source to be enabled or disabled.
  *     To disnable all interrupt source,use the parameter:
  *             SSP_INTCFG_NONE
  *     To enable the interrupt one by one, use the ¡°OR¡± operation with below parameter:
  *             SSP_INTCFG_RX_OVERRUN  Receive overrun interrupt
  *             SSP_INTCFG_RX_TIMEOUT  Receive timeout interrupt
  *             SSP_INTCFG_RX    Receive FIFO interrupt(at least half full)
  *             SSP_INTCFG_TX    Transmit FIFO interrupt(at least half empty)
  *     To enable all the 4 interrupt above together, use the parameter:
  *             SSP_INTCFG_ALL
  * @retval None
  */
void SSP_SetINTConfig(uint32_t IntSrc)
{
    /* Check the parameters */
    assert_param(IS_SSP_INT_SRC(IntSrc));

    TSB_SSP->IMSC = IntSrc & SSP_IMSC_MASK;
}

/**
  * @brief Get the Enable/Disable setting for each Interrupt source in the SSP channel
  * @param None
  * @retval data in union SSP_INTState.
  */
SSP_INTState SSP_GetINTConfig(void)
{
    SSP_INTState state = { 0U };

    state.All = TSB_SSP->IMSC & SSP_IMSC_MASK;

    return state;
}

/**
  * @brief Get the raw status of each interrupt source in the SSP channel
  * @param None
  * @retval data in union SSP_INTState.
  */
SSP_INTState SSP_GetPreEnableINTState(void)
{
    SSP_INTState state = { 0U };

    state.All = TSB_SSP->RIS & SSP_RIS_MASK;

    return state;
}

/**
  * @brief Get the SSP channel post-enable interrupt status.( after masked)
  * @param None
  * @retval data in union SSP_INTState.
  */
SSP_INTState SSP_GetPostEnableINTState(void)
{
    SSP_INTState state = { 0U };

    state.All = TSB_SSP->MIS & SSP_MIS_MASK;

    return state;
}

/**
  * @brief Clear interrupt flag of SSP channel by writing '1' to correspond bit.
  * @param INTSrc: The interrupt source to be cleared.
  *     it can be one of the following values:
  *         SSP_INTCFG_RX_OVERRUN  Receive overrun interrupt
  *         SSP_INTCFG_RX_TIMEOUT  Receive timeout interrupt
  *         SSP_INTCFG_ALL         All interrupt flags above
  * @retval None
  */
void SSP_ClearINTFlag(uint32_t IntSrc)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_CLEAR_INT_SRC(IntSrc));

    if (IntSrc == SSP_INTCFG_RX_OVERRUN) {
        tmp = 1U;
    } else if (IntSrc == SSP_INTCFG_RX_TIMEOUT) {
        tmp = 2U;
    } else {
        tmp = 3U;
    }

    TSB_SSP->ICR = tmp;
}

/**
  * @brief Enable/Disable the DMA FIFO for Rx/Tx of SSP channel
  * @param Direction: DMA type,
  *     it can be one of the following values:
  *         SSP_RX,
  *         SSP_TX
  * @param  NewState: New state of DMA FIFO mode.
  *     it can be one of the following values:
  *         ENABLE,
  *         DISABLE
  * @retval None
  */
void SSP_SetDMACtrl(SSP_Direction Direction, FunctionalState NewState)
{
    uint32_t tmp = 0U;
    uint32_t tmpDMASet = 0U;

    /* Check the parameters */
    assert_param(IS_SSP_DIRECTION(Direction));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Direction == SSP_RX) {
        /* bit0 is for Rx */
        tmp = 1U;
    } else {
        /* bit1 is for Tx */
        tmp = 2U;
    }

    /* read, then clear all bits except bit0 and bit1  */
    tmpDMASet = TSB_SSP->DMACR & SSP_DMA_MASK;

    if (NewState == ENABLE) {
        tmpDMASet |= tmp;
    } else {
        /* disable, clear bit */
        tmpDMASet &= (uint32_t) ~ tmp & SSP_DMA_MASK;
    }

    TSB_SSP->DMACR = tmpDMASet;
}

/** @} */
/* End of group SSP_Exported_Functions */

/** @} */
/* End of group SSP */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /*defined(__TMPM341_SSP_H) */
