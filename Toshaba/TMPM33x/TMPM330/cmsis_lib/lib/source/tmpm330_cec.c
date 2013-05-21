/**
 *******************************************************************************
 * @file    tmpm330_cec.c
 * @brief   This file provides API functions for CEC driver.
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm330_cec.h"

#if defined(__TMPM330_CEC_H) || defined(__TMPM332_CEC_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup CEC 
  * @brief CEC driver modules
  * @{
  */

/** @defgroup CEC_Private_Defines
  * @{
  */
#define LOGICAL_ADDR_MASK                     ((uint32_t)0x00000000)

#define RX_EOM_BIT_MASK                       ((uint32_t)0x00000100)
#define RX_ACK_BIT_MASK                       ((uint32_t)0x00000200)
#define TX_EOM_BIT_SET                        ((uint32_t)0x00000100)

#define CEC_RSTATE_MASK                       ((uint32_t)0x0000007F)
#define CEC_TSTATE_MASK                       ((uint32_t)0x0000001F)

#define NOISE_CANCELLATION_MASK               ((uint32_t)0xFFC8FFFF)
#define CEC_CYCLE_MASK                        ((uint32_t)0xFFFF88FF)
#define CEC_VALID_DATA_MASK                   ((uint32_t)0xFFFFFF8F)
#define CEC_TIMEOUT_MASK                      ((uint32_t)0xFFFFFFF3)

#define CEC_RX_WAVE_ERR_MASK                  ((uint32_t)0xFF8888FF)
#define CEC_RX_START_BIT_WAVE_MASK            ((uint32_t)0xFFFF8888)

#define CEC_TX_WAVE_MASK                      ((uint32_t)0xFF8880FF)
#define CEC_BUS_FREE_MASK                     ((uint32_t)0xFFFFFFF0)

/** @} */
/* End of group CEC_Private_Defines */

/** @defgroup CEC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group CEC_Private_FunctionPrototypes */

/** @defgroup CEC_Private_Functions
  * @{
  */

/** @} */
/* End of group CEC_Private_Functions */

/** @defgroup CEC_Exported_Functions
  * @{
  */

/**
  * @brief Enable CEC moudle
  * @param None
  * @retval None
  */
void CEC_Enable(void)
{
    /* Set TSB_CEC_EN_CECEN to enable CEC IP */
    TSB_CEC_EN_CECEN = 1U;
}

/**
  * @brief Disable CEC IP
  * @param None
  * @retval None
  */
void CEC_Disable(void)
{
    /* clear TSB_CEC_EN_CECEN to disable CEC IP */
    TSB_CEC_EN_CECEN = 0U;
}

/**
  * @brief Reset the CEC IP
  * @param None
  * @retval None
  */
void CEC_SWReset(void)
{
    /* Set TSB_CEC_RESET_CECRESET to reset all the CEC register */
    TSB_CEC_RESET_CECRESET = 1U;
}

/**
  * @brief Initialize the CEC in the default configuration
  * @param None
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_DefaultConfig(void)
{
    Result retval = ERROR;
    /* Enable CEC IP */
    CEC_Enable();
    /* Enable the Idle mode */
    CEC_SetIdleMode(ENABLE);
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            /* Set Noise Cancellation: LowLevel : 1 cycle  HighLevel : 1 cycle */
            CEC_SetNoiseCancellation(CEC_LOW_CANCELLATION_1, CEC_HIGH_CANCELLATION_1);
            /* Set the Rx Cycle define: Min : 2.05ms  Max : 2.75ms */
            CEC_SetCycleConfig(CEC_CYCLE_MIN_0, CEC_CYCLE_MAX_0);
            /* Set the Rx Valid Data time: 1.05 ms */
            CEC_SetDataValidTime(CEC_VALID_TIME_0);
            /* Set the Rx TimeOut define: 1 bit cycle */
            CEC_SetTimeOutMode(CEC_TIME_OUT_1_BIT);
            /* Set the Rx start bit wave define: Rising Time Min: 3.5ms  Rising Time Max: 3.9ms Cycle Min: 4.3ms  Cycle Max: 4.7ms */
            CEC_SetRxStartBitWaveConfig(CEC_START_BIT_RISING_TIME_MIN_0,
                                        CEC_START_BIT_RISING_TIME_MAX_0,
                                        CEC_START_BIT_CYCLE_MIN_0, CEC_START_BIT_CYCLE_MAX_0);
            /* Set the Rx Bit wave define: "1" Rising Time Min: 0.4ms  "1" Rising Time Max: 0.8ms  "0" Rising Time Min: 1.3ms  "1" Rising Time Max: 1.7ms  */
            CEC_SetRxDetectWaveConfig(CEC_LOGICAL_1_RISING_TIME_MIN_0,
                                      CEC_LOGICAL_1_RISING_TIME_MAX_0,
                                      CEC_LOGICAL_0_RISING_TIME_MIN_0,
                                      CEC_LOGICAL_0_RISING_TIME_MAX_0);
            /* Set Tx Wave: Data Bit Cycle: 2.4ms  Start Bit Rising Time: 0.6ms("1")/1.5ms("0")  Start Bit Cycle: 4.5ms  Start Bit Rising Time: 3.7ms   */
            CEC_SetTxWaveConfig(CEC_TX_DATA_BIT_CYCLE_0,
                                CEC_TX_DATA_BIT_RISING_TIME_0,
                                CEC_TX_START_BIT_CYCLE_0, CEC_TX_START_BIT_RISING_TIME_0);
            /* Set the Bus Free Time : 5 bit cycle */
            CEC_SetBusFreeTime(CEC_BUS_FREE_5_BIT);
            /* Enable Snoop Mode */
            CEC_SetSnoopMode(ENABLE);
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specifies the logical address assigned to CEC
  * @param LogicalAddr: The logical address of  CEC
  *   This parameter can be one of the following values:
  *   CEC_TV, CEC_RECORDING_DEVICE_1, CEC_RECORDING_DEVICE_2,
  *   CEC_STB_1, CEC_DVD_1,CEC_AUDIO_SYSTEM, CEC_STB_2,
  *   CEC_STB_3, CEC_DVD_2,CEC_RECORDING_DEVICE_3, CEC_FREE_USE,
  *   CEC_BROADCAST
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetLogicalAddr(CEC_LogicalAddr LogicalAddr)
{
    uint32_t tmp = 1U;
    uint32_t LogicalAddrtmp = 0U;
    Result retval = ERROR;

    /* Check the parameters */
    assert_param(IS_CEC_LOGICAL_ADDR(LogicalAddr));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            LogicalAddrtmp = TSB_CEC->ADD & LOGICAL_ADDR_MASK;
            /* specifies the logical address to CECADD */
            LogicalAddrtmp |= tmp << ((uint32_t) LogicalAddr);
            TSB_CEC->ADD = LogicalAddrtmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Add new logical address to CEC device
  * @param LogicalAddr: The logical address of  CEC
  *   This parameter can be one of the following values:
  *   CEC_TV, CEC_RECORDING_DEVICE_1, CEC_RECORDING_DEVICE_2,
  *   CEC_STB_1, CEC_DVD_1,CEC_AUDIO_SYSTEM, CEC_STB_2,
  *   CEC_STB_3, CEC_DVD_2,CEC_RECORDING_DEVICE_3, CEC_FREE_USE,
  *   CEC_BROADCAST
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_AddLogicalAddr(CEC_LogicalAddr LogicalAddr)
{
    uint32_t tmp = 1U;
    Result retval = ERROR;
    uint32_t LogicalAddrtmp = 0U;
    /* Check the parameters */
    assert_param(IS_CEC_LOGICAL_ADDR(LogicalAddr));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            /* add the logical address to CECADD */
            LogicalAddrtmp = tmp << ((uint32_t) LogicalAddr);
            TSB_CEC->ADD |= LogicalAddrtmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Remove new logical address to CEC device
  * @param LogicalAddr: The logical address of  CEC
  *   This parameter can be one of the following values:
  *   CEC_TV, CEC_RECORDING_DEVICE_1, CEC_RECORDING_DEVICE_2,
  *   CEC_STB_1, CEC_DVD_1,CEC_AUDIO_SYSTEM, CEC_STB_2, 
  *   CEC_STB_3, CEC_DVD_2,CEC_RECORDING_DEVICE_3, CEC_FREE_USE,
  *   CEC_BROADCAST
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_RemoveLogicalAddr(CEC_LogicalAddr LogicalAddr)
{
    uint32_t tmp = 1U;
    Result retval = ERROR;
    uint32_t LogicalAddrtmp = 0U;
    /* Check the parameters */
    assert_param(IS_CEC_LOGICAL_ADDR(LogicalAddr));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            /* remove the logical address to CECADD */
            LogicalAddrtmp = tmp << ((uint32_t) LogicalAddr);
            TSB_CEC->ADD &= ~LogicalAddrtmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Get  the logical address of device
  * @param None
  * @retval The logical address list of CEC
  */
CEC_AddrListTypeDef CEC_GetLogicalAddr(void)
{
    uint32_t Index = 0U;
    uint32_t tmp = 1U;
    uint32_t LogicalAddrtmp = 0U;
    CEC_AddrListTypeDef AddrList;
    CEC_LogicalAddr ReferenceAddrList[13] =
        { CEC_TV, CEC_RECORDING_DEVICE_1, CEC_RECORDING_DEVICE_2,
        CEC_STB_1, CEC_DVD_1, CEC_AUDIO_SYSTEM, CEC_STB_2, CEC_STB_3,
        CEC_DVD_2, CEC_RECORDING_DEVICE_3, CEC_FREE_USE,
        CEC_BROADCAST, CEC_UNKNOWN
    };
    /*initialize the logical address list */
    AddrList.AddrNumber = 0U;
    for (Index = 0U; Index < 16U; Index++) {
        AddrList.AddrList[Index] = CEC_UNKNOWN;
    }
    Index = 0U;
    while (ReferenceAddrList[Index] != CEC_UNKNOWN) {
        LogicalAddrtmp = tmp << ((uint32_t) ReferenceAddrList[Index]);
        if ((TSB_CEC->ADD & LogicalAddrtmp) == LogicalAddrtmp) {
            /*Add the logical address to AdrList */
            AddrList.AddrList[AddrList.AddrNumber] = ReferenceAddrList[Index];
            AddrList.AddrNumber++;
        }
        Index++;
    }
    return AddrList;
}

/**
  * @brief Enable/Disable data reception of CEC
  * @param  NewState: New state of the CEC reception
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CEC_SetRxCtrl(FunctionalState NewState)
{
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState == ENABLE) {
        /*Enable CEC reception */
        TSB_CEC_REN_CECREN = 1U;
    } else {
        /*Disable CEC reception */
        TSB_CEC_REN_CECREN = 0U;
    }
}

/**
  * @brief Start data transmission of CEC
  * @param None
  * @retval The value returned can be:
  *   SUCCESS or ERROR
  */
Result CEC_StartTx(void)
{
    Result retval = ERROR;
    if (CEC_GetTxState() == DONE) {
        /*Set transmission start bit */
        TSB_CEC_TEN_CECTEN = 1U;
        retval = SUCCESS;
    }
    return retval;
}

/**
  * @brief Stop data transmission of CEC
  * @param None
  * @retval None
  */
void CEC_StopTx(void)
{
    /*clear transmission start bit */
    TSB_CEC_TEN_CECTEN = 0U;
}

/**
  * @brief Read the data received
  * @param None
  * @retval CEC receive data following the structure of CEC_DataTypeDef  
  */
CEC_DataTypeDef CEC_GetRxData(void)
{
    CEC_DataTypeDef ReceiveData = { 0U, CEC_NO_ACK, CEC_NO_EOM }; 
    uint32_t tmp = 0U;
    /*save received data */
    tmp = TSB_CEC->RBUF;
    ReceiveData.Data = (uint8_t) (tmp & 0xFFU);
    /*save EOM Bit value */
    if ((tmp & RX_EOM_BIT_MASK) == RX_EOM_BIT_MASK) {
        ReceiveData.EOMBit = CEC_EOM;
    } else {
        ReceiveData.EOMBit = CEC_NO_EOM;
    }
    /*save ACK Bit value */
    if ((tmp & RX_ACK_BIT_MASK) == RX_ACK_BIT_MASK) {
        ReceiveData.ACKBit = CEC_ACK;
    } else {
        ReceiveData.ACKBit = CEC_NO_ACK;
    }
    return ReceiveData;
}

/**
  * @brief Set the data to be sent
  * @param Data: The byte to be sent
  * @param EOM_Flag: The EOM flag of data
  *   This parameter can be: CEC_EOM, CEC_NO_EOM
  * @retval None
  */
void CEC_SetTxData(uint8_t Data, CEC_EOMBit EOM_Flag)
{
    uint32_t TxDataTemp = 0U;
    assert_param(IS_EOM_BIT(EOM_Flag));
    TxDataTemp = (uint32_t) Data & 0x0FFU;
    if (EOM_Flag == CEC_EOM) {
        /*Set EOM Bit */
        TxDataTemp = (uint32_t) Data | TX_EOM_BIT_SET;
    }
    /*Set Tx Data to register */
    TSB_CEC->TBUF = TxDataTemp;
}

/**
  * @brief Controls the CEC operation at the IDLE mode
  * @param  NewState: New state of the CEC in Idle
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CEC_SetIdleMode(FunctionalState NewState)
{
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState == ENABLE) {
        /*Enable Idle mode */
        TSB_CEC_EN_I2CEC = 1U;
    } else {
        /*Disable Idle mode */
        TSB_CEC_EN_I2CEC = 0U;
    }
}

/**
  * @brief Get the Receive state of CEC
  * @param None
  * @retval The value returned can be one of the following values:
  *   ENABLE or DISABLE
  */
FunctionalState CEC_GetRxState(void)
{
    FunctionalState retval = DISABLE;
    if (TSB_CEC_REN_CECREN == 1U) {
        /*Return Receive state is Enable */
        retval = ENABLE;
    }
    return retval;
}

/**
  * @brief Get the transmission state of CEC
  * @param None
  * @retval The state of CEC transmission , which can be 
  *   BUSY or DONE
  */
WorkState CEC_GetTxState(void)
{
    WorkState retval = BUSY;
    /* Get the value of TSB_CEC_TEN_CECTRANS */
    if (TSB_CEC_TEN_CECTRANS == 1U) {
        /*Return the Transmission is in progress */
        retval = BUSY;
    } else {
        /*Return the Transmission is completed or an interrupt is generated */
        retval = DONE;
    }
    return retval;
}

/**
  * @brief Get the receive interrupt state of CEC
  * @param None
  * @retval The state of CEC Rx interrupt state
  */
CEC_RxINTState CEC_GetRxINTState(void)
{
    CEC_RxINTState RxINTState;
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CEC->RSTAT;
    tmp = regval & CEC_RSTATE_MASK;
    RxINTState.All = tmp;
    return RxINTState;
}

/**
  * @brief Get the transmission interrupt state of CEC
  * @param None
  * @retval The state of CEC Tx interrupt state
  */
CEC_TxINTState CEC_GetTxINTState(void)
{
    CEC_TxINTState TxINTState;
    uint32_t tmp = 0U;
    uint32_t regval = TSB_CEC->TSTAT;
    tmp = regval & CEC_TSTATE_MASK;
    TxINTState.All = tmp;
    return TxINTState;
}

/**
  * @brief Set the ACK response mode of CEC
  * @param  NewState: New state of the ACK Response Mode
  *   This parameter can be: ENABLE or DISABLE.
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetACKResponseMode(FunctionalState NewState)
{
    Result retval = ERROR;
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            if (NewState == DISABLE) {
                /*Disable Response Mode */
                TSB_CEC_RCR1_CECACKDIS = 1U;
            } else {
                /*Enable Response Mode */
                TSB_CEC_RCR1_CECACKDIS = 0U;
            }
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Set the Noise Cancellation Mode of CEC
  * @param  LowCancellation: The number of "0" samplings for noise   
  *   This parameter can be: CEC_LOW_CANCELLATION_1,CEC_LOW_CANCELLATION_2,
  *   CEC_LOW_CANCELLATION_3,CEC_LOW_CANCELLATION_4,CEC_LOW_CANCELLATION_5,
  *   CEC_LOW_CANCELLATION_6,CEC_LOW_CANCELLATION_7 or CEC_LOW_CANCELLATION_8
  * @param  HighCancellation: The number of "1" samplings for noise Cancellation   
  *   This parameter can be: CEC_HIGH_CANCELLATION_1,CEC_HIGH_CANCELLATION_2,
  *   CEC_HIGH_CANCELLATION_3 or CEC_HIGH_CANCELLATION_4
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetNoiseCancellation(CEC_LowCancellation LowCancellation,
                                CEC_HighCancellation HighCancellation)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_LOW_CANCELLATION(LowCancellation));
    assert_param(IS_CEC_HIGH_CANCELLATION(HighCancellation));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            /*Set Noise Cancellation */
            tmp = TSB_CEC->RCR1 & NOISE_CANCELLATION_MASK;
            tmp |= ((uint32_t) LowCancellation) << 16U;
            tmp |= ((uint32_t) HighCancellation) << 20U;
            /*Set Noise Cancellation register */
            TSB_CEC->RCR1 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Set the cycle error detected configuration  of CEC
  * @param  CycleMin: Time to identify as min. cycle error 
  *   This parameter can be: CEC_CYCLE_MIN_0,CEC_CYCLE_MIN_1,
  *   CEC_CYCLE_MIN_2,CEC_CYCLE_MIN_3,CEC_CYCLE_MIN_4,
  *   CEC_CYCLE_MIN_5,CEC_CYCLE_MIN_6 or CEC_CYCLE_MIN_7
  * @param  CycleMax: Time to identify as max. cycle error
  *   This parameter can be: CEC_CYCLE_MAX_0,CEC_CYCLE_MAX_1,
  *   CEC_CYCLE_MAX_2,CEC_CYCLE_MAX_3,CEC_CYCLE_MAX_4,
  *   CEC_CYCLE_MAX_5,CEC_CYCLE_MAX_6 or CEC_CYCLE_MAX_7
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetCycleConfig(CEC_CycleMin CycleMin, CEC_CycleMax CycleMax)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_CYCLE_MIN(CycleMin));
    assert_param(IS_CEC_CYCLE_MAX(CycleMax));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            tmp = TSB_CEC->RCR1 & CEC_CYCLE_MASK;
            tmp |= ((uint32_t) CycleMin) << 12U;
            tmp |= ((uint32_t) CycleMax) << 8U;
            /*Set cycle configuration register */
            TSB_CEC->RCR1 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify the point of determining the data as 0 or 1
  * @param  ValidTime: Point of determining the data as 0 or 1
  *   This parameter can be: CEC_VALID_TIME_0,CEC_VALID_TIME_1,
  *   CEC_VALID_TIME_2,CEC_VALID_TIME_3,CEC_VALID_TIME_4,
  *   CEC_VALID_TIME_5 or CEC_VALID_TIME_6
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetDataValidTime(CEC_ValidTime ValidTime)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_DATA_VALID_TIME(ValidTime));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            tmp = TSB_CEC->RCR1 & CEC_VALID_DATA_MASK;
            tmp |= ((uint32_t) ValidTime) << 4U;
            /*Set Valid Time configuration register */
            TSB_CEC->RCR1 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify the time to determine a timeout
  * @param  TimeOut: The Number of Cycle to identify timeout
  *   This parameter can be: CEC_TIME_OUT_1_BIT,CEC_TIME_OUT_2_BIT or CEC_TIME_OUT_3_BIT
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetTimeOutMode(CEC_TimeOut TimeOut)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_TIME_OUT(TimeOut));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            tmp = TSB_CEC->RCR1 & CEC_TIMEOUT_MASK;
            tmp |= ((uint32_t) TimeOut) << 2U;
            /*Set TimeOut configuration register */
            TSB_CEC->RCR1 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify if a receive error interrupt is suspended or not.
  * @param  NewState: New state of the  receive error interrupt mode
  *   This parameter can be: ENABLE or DISABLE.
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetRxErrINTSuspend(FunctionalState NewState)
{
    Result retval = ERROR;
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            if (NewState == ENABLE) {
                /*Disable Error Interrupt Mode */
                TSB_CEC_RCR1_CECRIHLD = 1U;
            } else {
                /*Enable Error Interrupt Mode */
                TSB_CEC_RCR1_CECRIHLD = 0U;
            }
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify if data is received or not when destination address does not 
  *   correspond with the address set in the logical address register
  * @param  NewState: New state of the Snoop Mode
  *   This parameter can be: ENABLE or DISABLE.
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetSnoopMode(FunctionalState NewState)
{
    Result retval = ERROR;
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            if (NewState == ENABLE) {
                /*Enable Snoop Mode */
                TSB_CEC_RCR1_CECOTH = 1U;
            } else {
                /*Disable Snoop Mode */
                TSB_CEC_RCR1_CECOTH = 0U;
            }
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify waveform error detection range
  * @param  Logical1RisingTimeMin: The fastest rising timing of logical "1" determined as proper
  *   This parameter can be:
  *   CEC_LOGICAL_1_RISING_TIME_MIN_0,CEC_LOGICAL_1_RISING_TIME_MIN_1,CEC_LOGICAL_1_RISING_TIME_MIN_2,
  *   CEC_LOGICAL_1_RISING_TIME_MIN_3,CEC_LOGICAL_1_RISING_TIME_MIN_4,CEC_LOGICAL_1_RISING_TIME_MIN_5,
  *   CEC_LOGICAL_1_RISING_TIME_MIN_6 or CEC_LOGICAL_1_RISING_TIME_MIN_7
  * @param  Logical1RisingTimeMax: The latest rising timing of logical "1" determined as proper waveform
  *   This parameter can be:
  *   CEC_LOGICAL_1_RISING_TIME_MAX_0,CEC_LOGICAL_1_RISING_TIME_MAX_1,CEC_LOGICAL_1_RISING_TIME_MAX_2,
  *   CEC_LOGICAL_1_RISING_TIME_MAX_3,CEC_LOGICAL_1_RISING_TIME_MAX_4,CEC_LOGICAL_1_RISING_TIME_MAX_5,
  *   CEC_LOGICAL_1_RISING_TIME_MAX_6 or CEC_LOGICAL_1_RISING_TIME_MAX_7
  * @param  Logical0RisingTimeMin: The fastest rising timing of logical "0" determined as proper
  *   This parameter can be:
  *   CEC_LOGICAL_0_RISING_TIME_MIN_0,CEC_LOGICAL_0_RISING_TIME_MIN_1,CEC_LOGICAL_0_RISING_TIME_MIN_2,
  *   CEC_LOGICAL_0_RISING_TIME_MIN_3,CEC_LOGICAL_0_RISING_TIME_MIN_4,CEC_LOGICAL_0_RISING_TIME_MIN_5,
  *   CEC_LOGICAL_0_RISING_TIME_MIN_6 or CEC_LOGICAL_0_RISING_TIME_MIN_7
  * @param  Logical0RisingTimeMax: The latest rising timing of logical "0" determined as proper waveform
  *   This parameter can be:
  *   CEC_LOGICAL_0_RISING_TIME_MAX_0,CEC_LOGICAL_0_RISING_TIME_MAX_1,CEC_LOGICAL_0_RISING_TIME_MAX_2,
  *   CEC_LOGICAL_0_RISING_TIME_MAX_3,CEC_LOGICAL_0_RISING_TIME_MAX_4,CEC_LOGICAL_0_RISING_TIME_MAX_5,
  *   CEC_LOGICAL_0_RISING_TIME_MAX_6 or CEC_LOGICAL_0_RISING_TIME_MAX_7
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetRxDetectWaveConfig(CEC_Logical1RisingTimeMin Logical1RisingTimeMin,
                                 CEC_Logical1RisingTimeMax Logical1RisingTimeMax,
                                 CEC_Logical0RisingTimeMin Logical0RisingTimeMin,
                                 CEC_Logical0RisingTimeMax Logical0RisingTimeMax)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_LOGICAL_1_RISING_TIME_MIN(Logical1RisingTimeMin));
    assert_param(IS_LOGICAL_1_RISING_TIME_MAX(Logical1RisingTimeMax));
    assert_param(IS_LOGICAL_0_RISING_TIME_MIN(Logical0RisingTimeMin));
    assert_param(IS_LOGICAL_0_RISING_TIME_MAX(Logical0RisingTimeMax));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            tmp = TSB_CEC->RCR3 & CEC_RX_WAVE_ERR_MASK;
            tmp |= ((uint32_t) Logical1RisingTimeMin) << 8U;
            tmp |= ((uint32_t) Logical1RisingTimeMax) << 12U;
            tmp |= ((uint32_t) Logical0RisingTimeMin) << 16U;
            tmp |= ((uint32_t) Logical0RisingTimeMax) << 20U;
            /*Set Rx Detect Wave configuration register */
            TSB_CEC->RCR3 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify the cycles to detect a start bit and the rising timing of a start bit in its detection
  * @param  RisingTimeMin: Min. time of start bit rising timing
  *   This parameter can be:
  *   CEC_START_BIT_RISING_TIME_MIN_0,CEC_START_BIT_RISING_TIME_MIN_1,CEC_START_BIT_RISING_TIME_MIN_2,
  *   CEC_START_BIT_RISING_TIME_MIN_3,CEC_START_BIT_RISING_TIME_MIN_4,CEC_START_BIT_RISING_TIME_MIN_5,
  *   CEC_START_BIT_RISING_TIME_MIN_6 or CEC_START_BIT_RISING_TIME_MIN_7
  * @param  RisingTimeMax: Max. time of start bit rising timing
  *   This parameter can be:
  *   CEC_START_BIT_RISING_TIME_MAX_0,CEC_START_BIT_RISING_TIME_MAX_1,CEC_START_BIT_RISING_TIME_MAX_2,
  *   CEC_START_BIT_RISING_TIME_MAX_3,CEC_START_BIT_RISING_TIME_MAX_4,CEC_START_BIT_RISING_TIME_MAX_5,
  *   CEC_START_BIT_RISING_TIME_MAX_6 or CEC_START_BIT_RISING_TIME_MAX_7
  * @param  CycleMin: Min. cycle to detect start bit
  *   This parameter can be:
  *   CEC_START_BIT_CYCLE_MIN_0,CEC_START_BIT_CYCLE_MIN_1,CEC_START_BIT_CYCLE_MIN_2,
  *   CEC_START_BIT_CYCLE_MIN_3,CEC_START_BIT_CYCLE_MIN_4,CEC_START_BIT_CYCLE_MIN_5,
  *   CEC_START_BIT_CYCLE_MIN_6 or CEC_START_BIT_CYCLE_MIN_7
  * @param  CycleMax: Max. cycle to detect start bit
  *   This parameter can be:
  *   CEC_START_BIT_CYCLE_MAX_0,CEC_START_BIT_CYCLE_MAX_1,CEC_START_BIT_CYCLE_MAX_2,
  *   CEC_START_BIT_CYCLE_MAX_3,CEC_START_BIT_CYCLE_MAX_4,CEC_START_BIT_CYCLE_MAX_5,
  *   CEC_START_BIT_CYCLE_MAX_6 or CEC_START_BIT_CYCLE_MAX_7
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetRxStartBitWaveConfig(CEC_StartBitRisingTimeMin RisingTimeMin,
                                   CEC_StartBitRisingTimeMax RisingTimeMax,
                                   CEC_StartBitCycleMin CycleMin,
                                   CEC_StartBitCycleMax CycleMax)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_START_BIT_RISING_TIME_MIN(RisingTimeMin));
    assert_param(IS_CEC_START_BIT_RISING_TIME_MAX(RisingTimeMax));
    assert_param(IS_CEC_START_BIT_CYCLE_MIN(CycleMin));
    assert_param(IS_CEC_START_BIT_CYCLE_MAX(CycleMax));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            tmp = TSB_CEC->RCR2 & CEC_RX_START_BIT_WAVE_MASK;
            tmp |= (uint32_t) RisingTimeMin;
            tmp |= ((uint32_t) RisingTimeMax) << 4U;
            tmp |= ((uint32_t) CycleMin) << 8U;
            tmp |= ((uint32_t) CycleMax) << 12U;
            /*Set Rx Detect Wave configuration register */
            TSB_CEC->RCR2 = tmp;
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Enable or disable the function that detects a received waveform
  *   does not identical to the one defined and generates waveform error interrupt
  * @param  NewState: The state of Waveform error detection Mode
  *   This parameter can be: ENABLE or DISABLE.
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetRxWaveErrDetect(FunctionalState NewState)
{
    Result retval = ERROR;
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (CEC_GetTxState() == DONE) {
        if (CEC_GetRxState() == DISABLE) {
            if (NewState == ENABLE) {
                /*Enable Rx Wave Err Detect */
                TSB_CEC_RCR3_CECWAVEN = 1U;
            } else {
                /*Disable Rx Wave Err Detect */
                TSB_CEC_RCR3_CECWAVEN = 0U;
            }
            retval = SUCCESS;
        }
    }
    return retval;
}

/**
  * @brief Specify the waveform parameter for transmit
  * @param  DataBitCycle: the cycle of a data bit
  *   This parameter can be:
  *   CEC_TX_DATA_BIT_CYCLE_0,CEC_TX_DATA_BIT_CYCLE_1,CEC_TX_DATA_BIT_CYCLE_2,CEC_TX_DATA_BIT_CYCLE_3,
  *   CEC_TX_DATA_BIT_CYCLE_4,CEC_TX_DATA_BIT_CYCLE_5,CEC_TX_DATA_BIT_CYCLE_6,CEC_TX_DATA_BIT_CYCLE_7,
  *   CEC_TX_DATA_BIT_CYCLE_8,CEC_TX_DATA_BIT_CYCLE_9,CEC_TX_DATA_BIT_CYCLE_10,CEC_TX_DATA_BIT_CYCLE_11,
  *   CEC_TX_DATA_BIT_CYCLE_12,CEC_TX_DATA_BIT_CYCLE_13,CEC_TX_DATA_BIT_CYCLE_14 or CEC_TX_DATA_BIT_CYCLE_15
  * @param  DataBitRisingTime: The rising timing of a data bit.
  *   This parameter can be:
  *   CEC_TX_DATA_BIT_RISING_TIME_0,CEC_TX_DATA_BIT_RISING_TIME_1,CEC_TX_DATA_BIT_RISING_TIME_2,
  *   CEC_TX_DATA_BIT_RISING_TIME_3,CEC_TX_DATA_BIT_RISING_TIME_4,CEC_TX_DATA_BIT_RISING_TIME_5,
  *   CEC_TX_DATA_BIT_RISING_TIME_6 or CEC_TX_DATA_BIT_RISING_TIME_7
  * @param  StartBitCycle: the cycle of a start bit.
  *   This parameter can be:
  *   CEC_TX_START_BIT_CYCLE_0,CEC_TX_START_BIT_CYCLE_1,CEC_TX_START_BIT_CYCLE_2,
  *   CEC_TX_START_BIT_CYCLE_3,CEC_TX_START_BIT_CYCLE_4,CEC_TX_START_BIT_CYCLE_5,
  *   CEC_TX_START_BIT_CYCLE_6 or CEC_TX_START_BIT_CYCLE_7
  * @param  StartBitRisingTime: the rising timing of a start bit.
  *   This parameter can be:
  *   CEC_TX_START_BIT_RISING_TIME_0,CEC_TX_START_BIT_RISING_TIME_1,CEC_TX_START_BIT_RISING_TIME_2,
  *   CEC_TX_START_BIT_RISING_TIME_3,CEC_TX_START_BIT_RISING_TIME_4,CEC_TX_START_BIT_RISING_TIME_5,
  *   CEC_TX_START_BIT_RISING_TIME_6 or CEC_TX_START_BIT_RISING_TIME_7
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetTxWaveConfig(CEC_TxDataBitCycle DataBitCycle,
                           CEC_TxDataBitRisingTime DataBitRisingTime,
                           CEC_TxStartBitCycle StartBitCycle,
                           CEC_TxStartBitRisingTime StartBitRisingTime)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_TX_DATA_BIT_CYCLE(DataBitCycle));
    assert_param(IS_CEC_TX_DATA_BIT_RISING_TIME(DataBitRisingTime));
    assert_param(IS_CEC_TX_START_BIT_CYCLE(StartBitCycle));
    assert_param(IS_CEC_TX_START_BIT_RISING_TIME(StartBitRisingTime));
    if (CEC_GetTxState() == DONE) {
        tmp = TSB_CEC->TCR & CEC_TX_WAVE_MASK;
        tmp |= ((uint32_t) DataBitCycle) << 8U;
        tmp |= ((uint32_t) DataBitRisingTime) << 12U;
        tmp |= ((uint32_t) StartBitCycle) << 16U;
        tmp |= ((uint32_t) StartBitRisingTime) << 20U;
        /*Set Tx Wave configuration register */
        TSB_CEC->TCR = tmp;
        retval = SUCCESS;
    }
    return retval;
}

/**
  * @brief Set message as a broadcast message or not
  * @param  NewState: The state of Waveform error detection Mode
  *   This parameter can be: ENABLE or DISABLE.
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetTxBroadcast(FunctionalState NewState)
{
    Result retval = ERROR;
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (CEC_GetTxState() == DONE) {
        if (NewState == ENABLE) {
            /*Set Broadcaset Mode */
            TSB_CEC_TCR_CECBRD = 1U;
        } else {
            /*Set NoBroadcaset Mode */
            TSB_CEC_TCR_CECBRD = 0U;
        }
        retval = SUCCESS;
    }
    return retval;
}

/**
  * @brief Specify time of a bus to be free that checked before transmission
  * @param  BusFree: the cycle of a data bit
  *   This parameter can be:
  *   CEC_BUS_FREE_1_BIT,CEC_BUS_FREE_2_BIT,CEC_BUS_FREE_3_BIT,CEC_BUS_FREE_4_BIT
  *   CEC_BUS_FREE_5_BIT,CEC_BUS_FREE_6_BIT,CEC_BUS_FREE_7_BIT,CEC_BUS_FREE_8_BIT,
  *   CEC_BUS_FREE_9_BIT,CEC_BUS_FREE_10_BIT,CEC_BUS_FREE_11_BIT,CEC_BUS_FREE_12_BIT,
  *   CEC_BUS_FREE_13_BIT,CEC_BUS_FREE_14_BIT,CEC_BUS_FREE_15_BIT or CEC_BUS_FREE_16_BIT
  * @retval The value returned can be one of the following values:
  *   SUCCESS or ERROR
  */
Result CEC_SetBusFreeTime(CEC_BusFree BusFree)
{
    Result retval = ERROR;
    uint32_t tmp = 0U;
    assert_param(IS_CEC_BUS_FREE(BusFree));
    if (CEC_GetTxState() == DONE) {
        tmp = TSB_CEC->TCR & CEC_BUS_FREE_MASK;
        tmp |= (uint32_t) BusFree;
        /*Set BusFreeTime register */
        TSB_CEC->TCR = tmp;
        retval = SUCCESS;
    }
    return retval;
}

/** @} */
/* End of group CEC_Exported_Functions */

/** @} */
/* End of group CEC */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM330_CEC_H) || defined(__TMPM332_CEC_H) */

