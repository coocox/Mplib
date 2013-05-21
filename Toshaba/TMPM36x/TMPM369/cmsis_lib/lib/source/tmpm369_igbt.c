/**
 *******************************************************************************
 * @file    tmpm369_igbt.c
 * @brief   This file provides API functions for IGBT driver.
 * @version V2.0.2.1
 * @date    2011/08/05
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
#include "tmpm369_igbt.h"

#if defined(__TMPM369_IGBT_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup IGBT
  * @brief IGBT driver modules
  * @{
  */

/** @defgroup IGBT_Private_Defines
  * @{
  */

#define MTEN_MTEN_SET          ((uint32_t)0x00000080)
#define MTEN_MTHALT_SET        ((uint32_t)0x00000040)
#define MTEN_MTMODE_SET        ((uint32_t)0x00000001)
#define MTIGICR_IGTRGM_SET     ((uint32_t)0x00000080)
#define MTIGICR_IGOEN0_MASK    ((uint32_t)0x00000001)
#define MTIGICR_IGOEN1_MASK    ((uint32_t)0x00000002)
#define MTIGRESTA_IGRESTA_SET  ((uint32_t)0x00000001)
#define MTIGEMGCR_IGEMGRS_SET  ((uint32_t)0x00000004)
#define MTIGEMGST_IGEMGIN_MASK ((uint32_t)0x00000002)
#define MTIGEMGST_IGEMGST_MASK ((uint32_t)0x00000001)

#define IGBT_STARTMODE_MASK    ((uint8_t)0x0C)
#define IGBT_TRGEDGE_MASK      ((uint8_t)0x40)
#define IGBT_STARTINT_MASK     ((uint8_t)0x01)

/** @} */
/* End of group IGBT_Private_Defines */

/** @defgroup IGBT_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group IGBT_Private_FunctionPrototypes */

/** @defgroup IGBT_Private_Functions
  * @{
  */

/** @} */
/* End of group IGBT_Private_Functions */

/** @defgroup IGBT_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the specified MPT channel in IGBT mode.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval None.
  */
void IGBT_Enable(TSB_MT_TypeDef * IGBTx)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    tmp = IGBTx->EN;
    /* Set MTEN<MTEN>&<MTMODE> to enable IGBT module */
    tmp |= (MTEN_MTEN_SET | MTEN_MTMODE_SET);
    IGBTx->EN = tmp;
}

/**
  * @brief  Disable the specified MPT channel in IGBT mode.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval None.
  */
void IGBT_Disable(TSB_MT_TypeDef * IGBTx)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    /* Clear MTEN<MTEN> to disable IGBT module */
    IGBTx->EN &= ~MTEN_MTEN_SET;
}

/**
  * @brief  Control the clock in Core Halt when MPT operates in IGBT mode.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  ClkState: The clock state in Core HALT during debug mode..
  *         This parameter can be IGBT_RUNNING_IN_CORE_HALT or IGBT_STOP_IN_CORE_HALT.
  * @retval None.
  */
void IGBT_SetClkInCoreHalt(TSB_MT_TypeDef * IGBTx, uint8_t ClkState)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_CLK_IN_CORE_HALT(ClkState));

    if (ClkState == IGBT_STOP_IN_CORE_HALT) {
        /* Set MTEN<MTHALT> */
        IGBTx->EN |= IGBT_STOP_IN_CORE_HALT;
    } else {
        /* Clear MTEN<MTHALT> */
        IGBTx->EN &= ~(uint32_t) IGBT_STOP_IN_CORE_HALT;
    }
}

/**
  * @brief  Start or stop MPT counter in IGBT mode by software command.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  Cmd: The command in IGBT mode to control the MPT counter.
  *         This parameter can be IGBT_RUN or IGBT_STOP.
  * @retval None.
  */
void IGBT_SetSWRunState(TSB_MT_TypeDef * IGBTx, uint8_t Cmd)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_CMD(Cmd));

    IGBTx->RUN = Cmd;
}

/**
  * @brief  Get the value captured when MPT operates in IGBT mode and
  *         start mode is "command start and trigger capture mode".
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  CapReg: Select the capture register.
  *         This parameter can be IGBT_CAPTURE_0 or IGBT_CAPTURE_1.
  * @retval The value captured.
  */
uint16_t IGBT_GetCaptureValue(TSB_MT_TypeDef * IGBTx, uint8_t CapReg)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_CAPTURE_REG(CapReg));

    return CapReg ? (uint16_t) IGBTx->CP1 : (uint16_t) IGBTx->CP0;
}

/**
  * @brief  Initialize and configure IGBT mode.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  InitStruct: The structure containing configuration for MPT 
  *         in IGBT mode.
  * @retval None.
  */
void IGBT_Init(TSB_MT_TypeDef * IGBTx, IGBT_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_START_MODE(InitStruct->StartMode));
    assert_param(IS_IGBT_OPERATION_MODE(InitStruct->OperationMode));
    assert_param(IS_IGBT_CNT_STOP_STATE(InitStruct->CntStopState));
    assert_param(IS_FUNCTIONAL_STATE(InitStruct->ActiveAcceptTrg));
    assert_param(IS_IGBT_INT_PERIOD(InitStruct->INTPeriod));
    assert_param(IS_IGBT_CLK_DIV(InitStruct->ClkDiv));
    assert_param(IS_IGBT_INIT_OUTPUT(InitStruct->Output0Init));
    assert_param(IS_IGBT_INIT_OUTPUT(InitStruct->Output1Init));
    assert_param(IS_IGBT_DENOISE_DIV(InitStruct->TrgDenoiseDiv));
    if (InitStruct->Output0Init != IGBT_OUTPUT_DISABLE) {
        assert_param(IS_IGBT_ACTIVE_TIMING(InitStruct->Output0ActiveTiming,
                                           InitStruct->Output0InactiveTiming));
        assert_param(IS_IGBT_INACTIVE_TIMING(InitStruct->Output0InactiveTiming,
                                             InitStruct->Period, InitStruct->Output0ActiveTiming));
    } else {
        /* Do nothing */
    }
    if (InitStruct->Output1Init != IGBT_OUTPUT_DISABLE) {
        assert_param(IS_IGBT_ACTIVE_TIMING(InitStruct->Output1ActiveTiming,
                                           InitStruct->Output1InactiveTiming));
        assert_param(IS_IGBT_INACTIVE_TIMING(InitStruct->Output1InactiveTiming,
                                             InitStruct->Period, InitStruct->Output1ActiveTiming));
    } else {
        /* Do nothing */
    }
    assert_param(IS_IGBT_EMG_OUTPUT(InitStruct->EMGFunction));
    assert_param(IS_IGBT_DENOISE_DIV(InitStruct->EMGDenoiseDiv));

    /* Write initial configuration into MTIGCR */
    tmp = ((uint32_t) InitStruct->ClkDiv |
           InitStruct->CntStopState |
           InitStruct->OperationMode | ((uint32_t) InitStruct->INTPeriod << 8));
    tmp |= ((uint32_t) InitStruct->StartMode & IGBT_STARTMODE_MASK);
    tmp |= (((uint32_t) InitStruct->StartMode & IGBT_STARTINT_MASK) << 10);
    IGBTx->IGCR = tmp;

    /* Write initial configuration into MTIGICR */
    tmp = (InitStruct->TrgDenoiseDiv | ((uint32_t) InitStruct->StartMode & IGBT_TRGEDGE_MASK));
    if (InitStruct->ActiveAcceptTrg == ENABLE) {
        /* Always accept trigger edges */
        IGBTx->IGICR = tmp;
    } else {
        /* Do not accept trigger edges during active output */
        IGBTx->IGICR = tmp | MTIGICR_IGTRGM_SET;
    }

    /* Initialize output timing */
    if (InitStruct->Output0Init != IGBT_OUTPUT_DISABLE) {
        IGBTx->RG0 = (uint32_t) InitStruct->Output0ActiveTiming;
        IGBTx->RG1 = (uint32_t) InitStruct->Output0InactiveTiming;
    } else {
        /* Do nothing */
    }
    if (InitStruct->Output1Init != IGBT_OUTPUT_DISABLE) {
        IGBTx->IGRG2 = (uint32_t) InitStruct->Output1ActiveTiming;
        IGBTx->IGRG3 = (uint32_t) InitStruct->Output1InactiveTiming;
    } else {
        /* Do nothing */
    }
    IGBTx->IGRG4 = (uint32_t) InitStruct->Period;

    /* Initialize EMG function */
    if (InitStruct->EMGFunction != IGBT_DISABLE_EMG) {
        tmp = ((uint32_t) InitStruct->EMGFunction | (uint8_t) (InitStruct->EMGDenoiseDiv << 4));
    } else {
        tmp = (uint32_t) IGBT_DISABLE_EMG;
    }
    IGBTx->IGEMGCR = tmp;

    /* Initialize output level */
    tmp = ((uint32_t) InitStruct->Output0Init | (uint8_t) (InitStruct->Output1Init << 1));
    IGBTx->IGOCR = tmp;
}

/**
  * @brief  Clean and restart the counter.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval None.
  */
void IGBT_Recount(TSB_MT_TypeDef * IGBTx)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    /* Set MTIGRESTA<IGRESTA> to restart the counter */
    IGBTx->IGRESTA = MTIGRESTA_IGRESTA_SET;
}

/**
  * @brief  Change the active timing of IGBT output 0 or IGBT output 1.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  Output: Select the IGBT of output port.
  *         This parameter can be IGBT_OUTPUT_0 or IGBT_OUTPUT_1.
  * @param  Timing: New output active timing.
  * @retval None.
  */
void IGBT_ChangeOutputActiveTiming(TSB_MT_TypeDef * IGBTx, uint8_t Output, uint16_t Timing)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_OUTPUT(Output));

    if (Output == IGBT_OUTPUT_0) {
        assert_param(IS_IGBT_ACTIVE_TIMING(Timing, IGBTx->RG1));
        IGBTx->RG0 = Timing;
    } else {
        assert_param(IS_IGBT_ACTIVE_TIMING(Timing, IGBTx->IGRG3));
        IGBTx->IGRG2 = Timing;
    }
}

/**
  * @brief  Change the inactive timing of IGBT output 0 or IGBT output 1.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  Output: Select the IGBT of output port.
  *         This parameter can be IGBT_OUTPUT_0 or IGBT_OUTPUT_1.
  * @param  Timing: New output inactive timing.
  * @retval None.
  */
void IGBT_ChangeOutputInactiveTiming(TSB_MT_TypeDef * IGBTx, uint8_t Output, uint16_t Timing)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));
    assert_param(IS_IGBT_OUTPUT(Output));

    if (Output == IGBT_OUTPUT_0) {
        assert_param(IS_IGBT_INACTIVE_TIMING(Timing, IGBTx->IGRG4, IGBTx->RG0));
        IGBTx->RG1 = Timing;
    } else {
        assert_param(IS_IGBT_INACTIVE_TIMING(Timing, IGBTx->IGRG4, IGBTx->IGRG2));
        IGBTx->IGRG3 = Timing;
    }
}

/**
  * @brief  Change the period of IGBT output.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @param  Period: New IGBT period.
  * @retval None.
  */
void IGBT_ChangePeriod(TSB_MT_TypeDef * IGBTx, uint16_t Period)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    if ((IGBTx->IGOCR & MTIGICR_IGOEN0_MASK) == MTIGICR_IGOEN0_MASK) {
        assert_param(IS_IGBT_VAILD_PERIOD(Period, IGBTx->RG1));
    } else {
        /* Do nothing */
    }
    if ((IGBTx->IGOCR & MTIGICR_IGOEN1_MASK) == MTIGICR_IGOEN1_MASK) {
        assert_param(IS_IGBT_VAILD_PERIOD(Period, IGBTx->IGRG3));
    } else {
        /* Do nothing */
    }

    IGBTx->IGRG4 = Period;
}

/**
  * @brief  Get the counter state.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval The counter state, which could be 
  *         BUSY or DONE.
  */
WorkState IGBT_GetCntState(TSB_MT_TypeDef * IGBTx)
{
    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    return (IGBTx->IGST == 0U) ? DONE : BUSY;
}

/**
  * @brief  Cancel the EMG state of IGBT.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval The result of EMG state canceling, which could be
  *         SUCCESS or ERROR.
  */
Result IGBT_CancelEMGState(TSB_MT_TypeDef * IGBTx)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    tmp = IGBTx->IGEMGST & MTIGEMGST_IGEMGIN_MASK;
    if ((IGBTx->IGST == 0U) && (tmp == MTIGEMGST_IGEMGIN_MASK)) {
        /* Set MTIGEMGCR<IGEMGRS> to cancel EMG state */
        IGBTx->IGEMGCR = MTIGEMGCR_IGEMGRS_SET;
        retval = SUCCESS;
    } else {
        /* Do nothing */
    }

    return retval;
}

/**
  * @brief  Get the EMG state.
  * @param  IGBTx: Select the MPT channel.
  *         This parameter can be one of the following values:
  *         IGBT0, IGBT1, IGBT2 or IGBT3.
  * @retval The EMG state, which includes input and protection status.
  */
IGBT_EMGStateTypeDef IGBT_GetEMGState(TSB_MT_TypeDef * IGBTx)
{
    IGBT_EMGStateTypeDef EMGState = { IGBT_EMG_INPUT_LOW, IGBT_EMG_NORMAL };

    /* Check the parameters */
    assert_param(IS_IGBT_PERIPH(IGBTx));

    EMGState.EMGInputState =
        (IGBTx->IGEMGST & MTIGEMGST_IGEMGIN_MASK) ? (IGBT_EMG_INPUT_HIGH) : (IGBT_EMG_INPUT_LOW);
    EMGState.EMGProtectState =
        (IGBTx->IGEMGST & MTIGEMGST_IGEMGST_MASK) ? (IGBT_EMG_PROTECT) : (IGBT_EMG_NORMAL);

    return EMGState;
}

/** @} */
/* End of group IGBT_Exported_Functions */

/** @} */
/* End of group IGBT */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM369_IGBT_H) */
