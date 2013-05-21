/**
 *******************************************************************************
 * @file    tmpm362_rmc.c
 * @brief   This file provides API functions for RMC driver.
 * @version V2.2.0
 * @date    2011/04/25
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm362_rmc.h"

#if defined(__TMPM360_RMC_H) || defined(__TMPM361_RMC_H) || defined(__TMPM362_RMC_H) || defined(__TMPM363_RMC_H) || defined(__TMPM364_RMC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @defgroup RMC 
  * @brief RMC driver modules
  * @{
  */
/** @defgroup RMC_Private_Defines
  * @{
  */

#define EN_RMCEN_SET                   ((uint32_t)0x00000003)
#define EN_RMCEN_CLEAR                 ((uint32_t)0x00000002)

#define EN_RMCREN_SET                  ((uint32_t)0x00000001)
#define EN_RMCREN_CLEAR                ((uint32_t)0xFFFFFFFE)

#define EN_I2RMC_SET                   ((uint32_t)0x00000002)
#define EN_I2RMC_CLEAR                 ((uint32_t)0xFFFFFFFD)

#define RCR2_RMCLD_SET                 ((uint32_t)0x02000000)
#define RCR2_RMCLD_CLEAR               ((uint32_t)0xFDFFFFFF)

#define RCR2_RMCLIEN_SET               ((uint32_t)0x80000000)
#define RCR2_RMCLIEN_CLEAR             ((uint32_t)0x7FFFFFFF)

#define RCR2_RMCEDIEN_SET              ((uint32_t)0x40000000)
#define RCR2_RMCEDIEN_CLEAR            ((uint32_t)0xBFFFFFFF)

#define RCR2_RMCPHM_PHASE              ((uint32_t)0x01000000)
#define RCR2_RMCPHM_CYCLE              ((uint32_t)0xFEFFFFFF)

#define RCR2_RX_TRG_MASK               ((uint32_t)0xFF000000)

#define RCR4_REVERSE_SET               ((uint32_t)0x00000080)
#define RCR4_REVERSE_CLEAR             ((uint32_t)0xFFFFFF7F)

#define RCR4_RMCNC_MASK                ((uint32_t)0xFFFFFFF0)

#define RMCRSTAT_INT_FACTOR            ((uint32_t)0x0000F000)

#define RMCRSTAT_LEADER_DETECT_MASK    ((uint32_t)0x00000080)
#define RMCRSTAT_LEADER_DETECTED       ((uint8_t)0x80)

#define RMCCLK_TBBOUT_SET              ((uint32_t)0x00000001)
#define RMCCLK_LOW_FREQUENCY_MASK      ((uint32_t)0xFFFFFFFE)

/** @} */
/* End of group RMC_Private_Defines */

/** @defgroup RMC_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the function of specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  * @retval None
  */
void RMC_Enable(TSB_RMC_TypeDef * RMCx)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    /* Set RMCxEN<RMCEN> to enable RMCx */
    RMCx->EN = EN_RMCEN_SET;
}

/**
  * @brief  Disable the function of specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1
  * @retval None
  */
void RMC_Disable(TSB_RMC_TypeDef * RMCx)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    /* Clear  RMCxEN<RMCEN> to disable RMCx */
    RMCx->EN = EN_RMCEN_CLEAR;
}

/**
  * @brief  RMC registers initial, the basic RMC configuration set to the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         RMC_InitStruct: The structure containing the basic RMC configuration.
  * @retval None
  */
void RMC_Init(TSB_RMC_TypeDef * RMCx, RMC_InitTypeDef * RMC_InitStruct)
{
    assert_param(IS_POINTER_NOT_NULL(RMC_InitStruct));

    RMC_SetRxCtrl(RMCx, DISABLE);
    RMC_SetLeaderDetection(RMCx, RMC_InitStruct->LeaderPara);
    RMC_SetFallingEdgeINT(RMCx, RMC_InitStruct->FallingEdgeINTState);
    RMC_SetSignalRxMethod(RMCx, RMC_InitStruct->SignalRxMethod);
    RMC_SetRxTrg(RMCx, RMC_InitStruct->LowWidth, RMC_InitStruct->MaxDataBitCycle);
    RMC_SetThreshold(RMCx, RMC_InitStruct->LargerThreshold, RMC_InitStruct->SmallerThreshold);
    RMC_SetInputSignalReversed(RMCx, RMC_InitStruct->InputSignalReversedState);
    RMC_SetNoiseCancellation(RMCx, RMC_InitStruct->NoiseCancellationTime);
}

/**
  * @brief  Enable or disable reception of the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         NewState: the new state of enable or disable
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void RMC_SetRxCtrl(TSB_RMC_TypeDef * RMCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set RMCxREN<RMCREN> to enable RMCx */
        RMCx->REN |= EN_RMCREN_SET;
    } else {
        /* Clear RMCxREN<RMCREN> to disable RMCx */
        RMCx->REN &= EN_RMCREN_CLEAR;
    }
}

/**
  * @brief  Get the received data from the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  * @retval The data received by RMC.
  */
RMC_RxDataTypeDef RMC_GetRxData(TSB_RMC_TypeDef * RMCx)
{
    uint8_t temp = 0U;
    RMC_RxDataTypeDef RMC_RxData = { 0U, 0U, 0U, 0U };

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));

    /*Save the received data */
    RMC_RxData.RxBuf1 = RMCx->RBUF1;
    RMC_RxData.RxBuf2 = RMCx->RBUF2;
    temp = (uint8_t) (RMCx->RBUF3 & 0xFFU);
    RMC_RxData.RxBuf3 = temp;
    temp = (uint8_t) (RMCx->RSTAT & 0x7FU);
    RMC_RxData.RxDataBits = temp;

    return RMC_RxData;
}

/**
  * @brief  Configure the RMC receive control register of leader
  *         detection for the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         LeaderPara: parameters to configure leader detection.
  * @retval None
  */
void RMC_SetLeaderDetection(TSB_RMC_TypeDef * RMCx, RMC_LeaderParameterTypeDef LeaderPara)
{
    uint32_t temp = 0U;

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_FUNCTIONAL_STATE(LeaderPara.LeaderDetectionState));
    assert_param(IS_FUNCTIONAL_STATE(LeaderPara.LeaderINTState));
    assert_param(IS_RMC_LEADER_PARAMETER(LeaderPara.MaxCycle, LeaderPara.MinCycle,
                                         LeaderPara.MaxLowWidth, LeaderPara.MinLowWidth));

    /*Set the parameters to RMCxRCR2<RMCLD> register. */
    if (LeaderPara.LeaderDetectionState == ENABLE) {
        RMCx->RCR2 |= RCR2_RMCLD_SET;   /*Enable RMC to receive the remote control signal with or without leader. */

        /*Set the parameters to RMCxRCR1<RMCLCMAX7:0><RMCLCMIN7:0><RMCLLMAX7:0><RMCLLMIN7:0> register. */
        temp = ((uint32_t) LeaderPara.MaxCycle << 24U) | ((uint32_t) LeaderPara.MinCycle << 16U);
        temp |= ((uint32_t) LeaderPara.MaxLowWidth << 8U);
        RMCx->RCR1 = temp | ((uint32_t) LeaderPara.MinLowWidth);

        /*Set the parameters to RMCxRCR2<RMCLIEN> register. */
        if (LeaderPara.LeaderINTState == ENABLE) {
            RMCx->RCR2 |= RCR2_RMCLIEN_SET;     /*Enables to generate a leader detection interrupt by detecting a leader. */
        } else {
            RMCx->RCR2 &= RCR2_RMCLIEN_CLEAR;   /*Disable to generate a leader detection interrupt by detecting a leader. */
        }
    } else {
        /*Disable RMC to receive the remote control signal with or without leader. */
        /*Disable to generate a leader detection interrupt by detecting a leader. */
        temp = RCR2_RMCLD_CLEAR & RCR2_RMCLIEN_CLEAR;
        RMCx->RCR2 &= temp;
    }
}

/**
  * @brief  Enable or disable the input falling edge interrupt for
  *         the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         NewState: the new state of enable or disable
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void RMC_SetFallingEdgeINT(TSB_RMC_TypeDef * RMCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set RMCxRCR2<RMCEDIEN> to enable input falling edge interupt */
        RMCx->RCR2 |= RCR2_RMCEDIEN_SET;
    } else {
        /* Clear RMCxRCR2<RMCEDIEN> to disable input falling edge interupt */
        RMCx->RCR2 &= RCR2_RMCEDIEN_CLEAR;
    }
}

/**
  * @brief  Select the method of receiving a remote control signal.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         Method: which method of receiving a remote control signal.
  *             This parameter can be one of the following values:
  *             RMC_RX_IN_CYCLE_METHOD or RMC_RX_IN_PHASE_METHOD
  * @retval None
  */
void RMC_SetSignalRxMethod(TSB_RMC_TypeDef * RMCx, RMC_RxMethod Method)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_RMC_RX_METHOD(Method));

    if (Method == RMC_RX_IN_PHASE_METHOD) {
        /* Set RMCxRCR2<RMCPHM> to receive in phase method */
        RMCx->RCR2 |= RCR2_RMCPHM_PHASE;
    } else {
        /* Clear RMCxRCR2<RMCPHM> to receive in cycle method */
        RMCx->RCR2 &= RCR2_RMCPHM_CYCLE;
    }
}

/**
  * @brief  Set the parameters that triggers reception completion 
  *         and interrupt generation for the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         LowWidth: Excess low width that triggers reception
  *                   completion and interrupt generation.
  *         MaxDataBitCycle: Maximum data bit cycle that triggers
  *                    reception completion and interrupt generation.
  * @retval None
  */
void RMC_SetRxTrg(TSB_RMC_TypeDef * RMCx, uint8_t LowWidth, uint8_t MaxDataBitCycle)
{
    uint32_t data = 0U;
    uint32_t temp = 0U;

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));

    /*Set the parameters to RMCxRCR2<RMCLL7:0><RMCDMAX7:0> register. */
    data = ((uint32_t) LowWidth << 8U) | ((uint32_t) MaxDataBitCycle);
    temp = RMCx->RCR2;
    temp &= RCR2_RX_TRG_MASK;
    temp |= data;
    RMCx->RCR2 = temp;
}

/**
  * @brief  Set the parameters of threshold to determine 0 or 1 for 
  *         the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         LargerThreshold: Larger threshold to determine a signal pattern in a phase method,
  *                          which should be less than 0x80
  *         SmallerThreshold: Smaller threshold to determine a pattern in a phase method, 
  *                           which should be less than 0x80
  * @retval None
  */
void RMC_SetThreshold(TSB_RMC_TypeDef * RMCx, uint8_t LargerThreshold, uint8_t SmallerThreshold)
{
    uint32_t temp = 0U;

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_RMC_PHASE_LARGER_THRESHOLD(LargerThreshold));
    assert_param(IS_RMC_PHASE_SMALLER_THRESHOLD(SmallerThreshold));

    /*Set the parameters to RMCxRCR3<RMCDATH6:0><RMCDATL6:0> register. */
    /*For threshold to determine 0 or 1 */
    temp = ((uint32_t) LargerThreshold << 8U) | ((uint32_t) SmallerThreshold);
    RMCx->RCR3 = temp;
}

/**
  * @brief  Enable or disable of reversing input signal for the 
  *         specified RMC channel
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         NewState: The new state of enable or disable.
  *             This parameter can be one of the following values:
  *             ENABLE or DISABLE
  * @retval None
  */
void RMC_SetInputSignalReversed(TSB_RMC_TypeDef * RMCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set RMCxRCR4<RMCPO> to enable signal reversed */
        RMCx->RCR4 |= RCR4_REVERSE_SET;
    } else {
        /* Clear RMCxRCR4<RMCPO> to disable signal reversed */
        RMCx->RCR4 &= RCR4_REVERSE_CLEAR;
    }
}

/**
  * @brief  Set the noise cancellation time for the specified RMC channel. 
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         NoiseCancellationTime: Noise cancellation time,which should be less than 0x10.
* @retval None
  */
void RMC_SetNoiseCancellation(TSB_RMC_TypeDef * RMCx, uint8_t NoiseCancellationTime)
{
    uint32_t temp = 0U;

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_RMC_NOISE_CANCELLATION_TIME(NoiseCancellationTime));

    /*Set the parameters to RMCxRCR4<RMCNC3:0> register for noise cancellation time. */
    temp = RMCx->RCR4;
    temp &= RCR4_RMCNC_MASK;
    temp |= NoiseCancellationTime;
    RMCx->RCR4 = temp;
}

/**
  * @brief  Get the interrupt factor for the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  * @retval: The structure includes the Interrupt factors.
  */
RMC_INTFactor RMC_GetINTFactor(TSB_RMC_TypeDef * RMCx)
{
    uint32_t temp = 0U;
    RMC_INTFactor retval = { 0U };

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));

    /*Read the interrupt factor infomation from RMCxRSTAT<RMCRLIF><RMCLOIF> <RMCDMAX> <RMCEDIF> register. */
    temp = RMCx->RSTAT;
    retval.All = temp & RMCRSTAT_INT_FACTOR;
    return retval;
}

/**
  * @brief  Get the leader detection result for the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  * @retval Leader detection result:
  *             It can be the following values:
  *             RMC_NO_LEADER or RMC_LEADER_DETECTED
  */
RMC_LeaderDetection RMC_GetLeader(TSB_RMC_TypeDef * RMCx)
{
    uint8_t tmp = 0U;
    RMC_LeaderDetection retval = RMC_NO_LEADER;

    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));

    /*Read the leader detection result from RMCxRSTAT<RMCRLDR> register. */
    tmp = (uint8_t) (RMCx->RSTAT & (RMCRSTAT_LEADER_DETECT_MASK));
    if (tmp == RMCRSTAT_LEADER_DETECTED) {
        retval = RMC_LEADER_DETECTED;   /* leader detected */
    } else {
        retval = RMC_NO_LEADER; /* Leader not detected */
    }
    return retval;
}

/**
  * @brief  Specifies that the number of receive data bit for the specified RMC channel.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         Reg_x: Select the set register.
  *             It can be the following values:
  *             RMC_RX_END_BITS_REG_1, RMC_RX_END_BITS_REG_2 or RMC_RX_END_BITS_REG_3
  *         BitNum: Specifies that the number of receive data bit.
* @retval None
  */
void RMC_SetRxEndBitNum(TSB_RMC_TypeDef * RMCx, RMC_RxEndBitsReg Reg_x, uint8_t BitNum)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_RMC_RX_END_BITS_REG(Reg_x));
    assert_param(IS_RMC_RX_END_BITS(BitNum));

    /* Set the number of receive data bit to the RMCxEND1, RMCxEND2 or RMCxEND3 */
    switch (Reg_x) {
    case RMC_RX_END_BITS_REG_1:
        RMCx->END1 = BitNum;
        break;
    case RMC_RX_END_BITS_REG_2:
        RMCx->END2 = BitNum;
        break;
    case RMC_RX_END_BITS_REG_3:
        RMCx->END3 = BitNum;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Specifies sampling clock of RMC function.
  * @param  RMCx: Select the RMC channel.
  *             This parameter can be one of the following values:
  *             TSB_RMC0, TSB_RMC1(Only for M360/M362/M364)
  *         Clk: RMC sampling clock
  *             This parameter can be one of the following values:
  *             RMC_CLK_LOW_FREQUENCY, RMC_CLK_TBBOUT
* @retval None
  */
void RMC_SetSrcClk(TSB_RMC_TypeDef * RMCx, RMC_SrcClk Clk)
{
    /* Check the parameters */
    assert_param(IS_RMC_PERIPH(RMCx));
    assert_param(IS_RMC_SRC_CLK(Clk));

    /*Set the RMCxFSSEL<RMCCLK> for RMC sampling clock */
    if (Clk == RMC_CLK_TBBOUT) {
        RMCx->FSSEL |= RMCCLK_TBBOUT_SET;
    } else {
        RMCx->FSSEL &= RMCCLK_LOW_FREQUENCY_MASK;
    }
}

/** @} */
/* End of group RMC_Exported_Functions */
/** @} */
/* End of group RMC */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* (__TMPM360_RMC_H) || (__TMPM361_RMC_H) || (__TMPM362_RMC_H) || (__TMPM363_RMC_H) || (__TMPM364_RMC_H) */
