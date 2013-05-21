/**
 *******************************************************************************
 * @file    tmpm363_can.c
 * @brief   This file provides API functions for CAN driver.
 * @version V2.2.0
 * @date    2011/03/21
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
#include "tmpm363_can.h"

#if defined(__TMPM363_CAN_H) || defined(__TMPM364_CAN_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup CAN
  * @brief CAN driver modules
  * @{
  */

/** @defgroup CAN_Private_Defines
  * @{
  */

#define ID_ID_MASK            ((uint32_t)0x1FFFFFFF)
#define ID_RFH_SET            ((uint32_t)0x20000000)
#define ID_RFH_CLEAR          ((uint32_t)0xDFFFFFFF)
#define ID_GAME_SET           ((uint32_t)0x40000000)
#define ID_GAME_CLEAR         ((uint32_t)0xBFFFFFFF)
#define ID_IDE_SET            ((uint32_t)0x80000000)
#define ID_IDE_CLEAR          ((uint32_t)0x7FFFFFFF)
#define MCF_DLC_MASK          ((uint32_t)0x0000000F)
#define MCF_RTR_SET           ((uint32_t)0x00000010)
#define MCF_RTR_CLEAR         ((uint32_t)0xFFFFFFEF)
#define GAM_GAMI_SET          ((uint32_t)0x80000000)
#define GAM_GAMI_CLEAR        ((uint32_t)0x7FFFFFFF)
#define MCR_MODE_CLEAR        ((uint32_t)0xFFFFF71F)
#define MCR_TSTLB_SET         ((uint32_t)0x00000200)
#define MCR_TSTLB_CLEAR       ((uint32_t)0xFFFFFDFF)
#define MCR_TSTERR_SET        ((uint32_t)0x00000100)
#define MCR_TSTERR_CLEAR      ((uint32_t)0xFFFFFEFF)
#define MCR_INTLB_SET         ((uint32_t)0x00000400)
#define MCR_INTLB_CLEAR       ((uint32_t)0xFFFFFBFF)
#define MCR_TSBTEST_CLEAR     ((uint32_t)0xFFFFFFDF)
#define MCR_WUBA_SET          ((uint32_t)0x00000010)
#define MCR_WUBA_CLEAR        ((uint32_t)0xFFFFFFEF)
#define MCR_MTOS_SET          ((uint32_t)0x00000008)
#define MCR_MTOS_CLEAR        ((uint32_t)0xFFFFFFF7)
#define MCR_TSCC_SET          ((uint32_t)0x00000002)
#define MCR_SRES_SET          ((uint32_t)0x00000001)
#define BCR2_SAM_SET          ((uint32_t)0x00000080)
#define BCR2_SAM_CLEAR        ((uint32_t)0xFFFFFF7F)
#define GIF_INT_MASK          ((uint32_t)0x000000FF)
#define MBTIF_INT_MASK        ((uint32_t)0x7FFFFFFF)
#define MBX_NUM_MAX           32U


/** @} */
/* End of group CAN_Private_Defines */

/** @defgroup CAN_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group CAN_Private_FunctionPrototypes */

/** @defgroup CAN_Private_Functions
  * @{
  */

/** @} */
/* End of group CAN_Private_Functions */

/** @defgroup CAN_Exported_Functions
  * @{
  */

/**
  * @brief  Set the message data, ID, control bits in mailbox.
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_31, CAN_MBX_ALL or their combination.
  * @param  MsgStruct: The structure contains message data, ID 
  *         and control information.
  * @retval None.
  */
void CAN_SetMbxMsg(uint32_t MbxNum, CAN_MsgTypeDef * MsgStruct)
{
    TSB_CANMB_TypeDef *TSB_CANMBX = 0U;
    uint32_t i = 0U;
    uint32_t tmp1 = 0U;
    uint32_t tmp2 = 0U;
    uint32_t numbit = 1U;
    uint32_t mbxaddr = 0U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(MsgStruct));
    assert_param(IS_CAN_DATA_LEN(MsgStruct->MsgDataLen));
    assert_param(IS_CAN_FORMAT(MsgStruct->MsgFormat));
    assert_param(IS_CAN_FRAME_TYPE(MsgStruct->MsgFrameType));
    assert_param(IS_CAN_RMT_FRAME_HANDLE(MsgStruct->RmtFrameHandleMode));
    assert_param(IS_FUNCTIONAL_STATE(MsgStruct->RxMaskState));

    /* Check the parameters of standard or extended ID */
    if (MsgStruct->MsgFormat == CAN_STD_FORMAT) {
        assert_param(IS_CAN_STD_ID(MsgStruct->MsgID));
        /* Standard ID, CANMBxID<IDE>=0 */
        tmp1 = MsgStruct->MsgID << 18U;
        tmp1 &= ID_IDE_CLEAR;
    } else {
        /* Extended ID, CANMBxID<IDE>=1 */
        assert_param(IS_CAN_EXT_ID(MsgStruct->MsgID));
        tmp1 = MsgStruct->MsgID;
        tmp1 |= ID_IDE_SET;
    }

    /* Remote frame handle mode, auto: CANMBxID<RFH>=1, sw: CANMBxID<RFH>=0 */
    tmp1 =
        (MsgStruct->RmtFrameHandleMode ==
         CAN_RMT_FRAME_AUTO_HANDLE) ? (tmp1 | ID_RFH_SET) : (tmp1 & ID_RFH_CLEAR);
    /* Acceptance mask, use: CANMBxID<GAME>=1, no use: CANMBxID<GAME>=0 */
    tmp1 = (MsgStruct->RxMaskState == ENABLE) ? (tmp1 | ID_GAME_SET) : (tmp1 & ID_GAME_CLEAR);

    /* Data length, should<=8 */
    tmp2 = (uint32_t) MsgStruct->MsgDataLen;
    /* Message frame type, remote frame: CANMBxTSVMCF<RTR>=1, data frame: CANMBxTSVMCF<RTR>=0 */
    tmp2 =
        (MsgStruct->MsgFrameType == CAN_RMT_FRAME) ? (tmp2 | MCF_RTR_SET) : (tmp2 & MCF_RTR_CLEAR);
    /* Time stamp */
    tmp2 |= (uint32_t) MsgStruct->MsgTimeStamp << 16U;
    /* Set all mailboxes specified by MbxNum */
    for (i = 0U; i < MBX_NUM_MAX; i++) {
        if ((MbxNum & numbit) == numbit) {
            /* Set offset address, the size of a mailbox is 32bytes */
            mbxaddr = (uint32_t) TSB_CANMB0 + (i * 0x20U);
            TSB_CANMBX = (TSB_CANMB_TypeDef *) mbxaddr;
            TSB_CANMBX->ID = tmp1;
            TSB_CANMBX->TSVMCF = tmp2;
            /* Copy data to CANMBxDH/CANMBxDL */
            TSB_CANMBX->DL =
                (((uint32_t) (MsgStruct->MsgData[3]) << 24U) |
                 ((uint32_t) (MsgStruct->MsgData[2]) << 16U) |
                 ((uint32_t) (MsgStruct->MsgData[1]) << 8U) | (uint32_t) (MsgStruct->MsgData[0]));
            TSB_CANMBX->DH =
                (((uint32_t) (MsgStruct->MsgData[7]) << 24U) |
                 ((uint32_t) (MsgStruct->MsgData[6]) << 16U) |
                 ((uint32_t) (MsgStruct->MsgData[5]) << 8U) | (uint32_t) (MsgStruct->MsgData[4]));
        } else {
            /* Do nothing */
        }
        /* Mailbox mask */
        numbit <<= 1U;
    }
}

/**
  * @brief  Get message data, ID, control bits from mailbox.
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_31(not support combination).
  * @param  MsgStruct: The structure used to receive message 
  *         data, ID and control information.
  * @retval None.
  */
void CAN_GetMbxMsg(uint32_t MbxNum, CAN_MsgTypeDef * MsgStruct)
{
    TSB_CANMB_TypeDef *TSB_CANMBX = 0U;
    uint32_t mbxaddr = 0U;
    uint32_t i = 0U;
    uint32_t tmp = 0U;
    uint32_t numbit = 1U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(MsgStruct));
    assert_param(IS_CAN_SINGLE_MBX_NUM(MbxNum));

    /* Get the mailbox specified by MbxNum */
    for (i = 0U; i < MBX_NUM_MAX; i++) {
        if ((MbxNum & numbit) == numbit) {
            mbxaddr = (uint32_t) TSB_CANMB0 + (i * 0x20U);
            TSB_CANMBX = (TSB_CANMB_TypeDef *) mbxaddr;
            break;
        } else {
            /* Do nothing */
        }
        numbit <<= 1U;
    }
    /* Get ID from CANMBxID */
    tmp = TSB_CANMBX->ID;
    /* Get remote frame handle mode from CANMBxID<RFH> */
    MsgStruct->RmtFrameHandleMode =
        (tmp & ID_RFH_SET) ? (CAN_RMT_FRAME_AUTO_HANDLE) : (CAN_RMT_FRAME_SW_HANDLE);
    /* Get Acceptance mask from CANMBxID<GAME> */
    MsgStruct->RxMaskState = (tmp & ID_GAME_SET) ? (ENABLE) : (DISABLE);
    /* Get message format from CANMBxID<IDE> */
    MsgStruct->MsgFormat = (tmp & ID_IDE_SET) ? (CAN_EXT_FORMAT) : (CAN_STD_FORMAT);
    /* Get message ID from CANMBxID<ID> */
    MsgStruct->MsgID = tmp & ID_ID_MASK;
    /* Get standard message ID from CANMBxID<18:28> */
    if (MsgStruct->MsgFormat == CAN_STD_FORMAT) {
        MsgStruct->MsgID >>= 18U;
    } else {
        /* Do nothing */
    }

    tmp = TSB_CANMBX->TSVMCF;
    /* Get data length from CANMBxTSVMCF<DLC> */
    MsgStruct->MsgDataLen = (uint8_t) (tmp & MCF_DLC_MASK);
    /* Get message frame type from CANMBxTSVMCF<RTR> */
    MsgStruct->MsgFrameType = (tmp & MCF_RTR_SET) ? (CAN_RMT_FRAME) : (CAN_DATA_FRAME);
    /* Get time stamp from CANMBxTSVMCF<TSV> */
    MsgStruct->MsgTimeStamp = (uint16_t) (tmp >> 16U);
    /* Get data[0]~data[3] from CANMBxDL */
    for (i = 0U; i < 4U; i++) {
        MsgStruct->MsgData[i] = (uint8_t) (TSB_CANMBX->DL >> (i * 8U));
    }
    /* Get data[4]~data[7] from CANMBxDH */
    for (i = 4U; i < 8U; i++) {
        MsgStruct->MsgData[i] = (uint8_t) (TSB_CANMBX->DH >> ((i - 4U) * 8U));
    }
}


/**
  * @brief  Set mailbox direction, transmission or receiving.
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_31, CAN_MBX_ALL or their combination.
  * @param  MbxDirection: The direction of the message mailbox.
  *         This parameter can be CAN_MBX_TX or CAN_MBX_RX.
  * @retval None.
  */
void CAN_SetMbxDirection(uint32_t MbxNum, uint8_t MbxDirection)
{
    /* Check the parameters */
    assert_param(IS_CAN_MBX_DIRECTION(MbxDirection));

    /* Mailbox direction, tx: CANMD<MDn>=0, rx: CANMD<MDn>=1 */
    if (MbxDirection == CAN_MBX_TX) {
        assert_param(IS_CAN_GLOBAL_MBX_NUM(MbxNum));
        TSB_CAN->MD &= ~MbxNum;
    } else {
        TSB_CAN->MD |= MbxNum;
    }
}

/**
  * @brief  Enable specified mailbox(es).
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_31, CAN_MBX_ALL or their combination.
  * @retval None.
  */
void CAN_EnableMbx(uint32_t MbxNum)
{
    /* Set CANMC<MCn> */
    TSB_CAN->MC |= MbxNum;
}

/**
  * @brief  Disable specified mailbox(es).
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_31, CAN_MBX_ALL or their combination.
  * @retval None.
  */
void CAN_DisableMbx(uint32_t MbxNum)
{
    /* Clear CANMC<MCn> */
    TSB_CAN->MC &= ~MbxNum;
}

/**
  * @brief  Set or cancel the transmission of specified mailbox.
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_30, or their combination.
  * @param  NewState: Set or cancel the transmission request.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None.
  */
void CAN_SetTxReq(uint32_t MbxNum, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CAN_GLOBAL_MBX_NUM(MbxNum));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set CANTRS<TRSn> Tx request */
        TSB_CAN->TRS |= MbxNum;
    } else {
        /* Set CANTRR<TRRn> to cancel Tx request */
        TSB_CAN->TRR |= MbxNum;
    }
}

/**
  * @brief  Get the specified transmission/receiving state of all mailboxes.
  * @param  StateID: Select the transmission/receiving state intended to get.
  *         This parameter can be one of the following values:
  *         CAN_STATE_ID_TX_ACK, CAN_STATE_ID_TX_ABORT, CAN_STATE_ID_RX_ACK, 
  *         CAN_STATE_ID_RX_LOST, CAN_STATE_ID_RX_RMT_FRAME.
  * @retval The state of each mailbox Mbxn(bit0~bit31) or entire state of 
  *         mailbox0~31(All)
  */
CAN_MbxState CAN_GetMbxTRxState(uint8_t StateID)
{
    CAN_MbxState retval = { 0U };

    /* Check the parameters */
    assert_param(IS_CAN_STATE_ID(StateID));

    switch (StateID) {
    case CAN_STATE_ID_TX_ACK:
        /* Get the value of CANTA */
        retval.All = TSB_CAN->TA;
        break;
    case CAN_STATE_ID_TX_ABORT:
        /* Get the value of CANAA */
        retval.All = TSB_CAN->AA;
        break;
    case CAN_STATE_ID_RX_ACK:
        /* Get the value of CANRMP */
        retval.All = TSB_CAN->RMP;
        break;
    case CAN_STATE_ID_RX_LOST:
        /* Get the value of CANRML */
        retval.All = TSB_CAN->RML;
        break;
    case CAN_STATE_ID_RX_RMT_FRAME:
        /* Get the value of CANRFP */
        retval.All = TSB_CAN->RFP;
        break;
    default:
        /* Do nothing */
        break;
    }
    return retval;
}

/**
  * @brief  Clear the specified transmission/receiving state of all mailboxes.
  * @param  StateID: Select the transmission/receiving state intended to clear.
  *         This parameter can be one of the following values:
  *         CAN_STATE_ID_TX_ACK, CAN_STATE_ID_TX_ABORT, CAN_STATE_ID_RX_ACK, 
  *         CAN_STATE_ID_RX_LOST, CAN_STATE_ID_RX_RMT_FRAME.
  * @retval None.
  */
void CAN_ClearMbxTRxState(uint8_t StateID)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_STATE_ID(StateID));

    switch (StateID) {
    case CAN_STATE_ID_TX_ACK:
        /* Clear CANTA<TAn> */
        tmp = TSB_CAN->TA;
        TSB_CAN->TA = tmp;
        break;
    case CAN_STATE_ID_TX_ABORT:
        /* Clear CANAA<AAn> */
        tmp = TSB_CAN->AA;
        TSB_CAN->AA = tmp;
        break;
    case CAN_STATE_ID_RX_ACK:
    case CAN_STATE_ID_RX_LOST:
    case CAN_STATE_ID_RX_RMT_FRAME:
        /* Clear CANRMP<RMPn> */
        tmp = TSB_CAN->RMP;
        TSB_CAN->RMP = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Lock or unlock the transmission request of specified mailbox.
  * @param  MbxNum: Select the message mailbox.
  *         This parameter can be one of the following values:
  *         CAN_MBX_0~CAN_MBX_30, or their combination.
  * @param  NewState: Lock or unlock the transmission request.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None.
  */
void CAN_SetTxLock(uint32_t MbxNum, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CAN_GLOBAL_MBX_NUM(MbxNum));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Transmission lock, lock:CANCDR<CDRn>=1, unlock:CANCDR<CDRn>=0 */
    TSB_CAN->CDR = (NewState == ENABLE) ? (TSB_CAN->CDR | MbxNum) : (TSB_CAN->CDR & ~MbxNum);
}

/**
  * @brief  Set the acceptance filter of receiving mailbox.
  * @param  MaskIDStruct: The structure used to specify the 
  *         mailbox type, ID bits to be masked, extension bit 
  *         masked and ID bit masked status.
  * @retval None.
  */
void CAN_SetRxMaskID(CAN_RxMaskIDTypeDef * MaskIDStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(MaskIDStruct));
    assert_param(IS_CAN_MBX_TYPE(MaskIDStruct->MbxType));
    assert_param(IS_CAN_EXT_ID(MaskIDStruct->MaskIDBit));
    assert_param(IS_FUNCTIONAL_STATE(MaskIDStruct->ExtIDState));
    assert_param(IS_FUNCTIONAL_STATE(MaskIDStruct->MaskState));

    /* Extension bit masked status, mask:CANGAM<GAMIn>=1, unmask:CANGAM<GAMIn>=0 */
    tmp = (MaskIDStruct->ExtIDState == ENABLE) ? (tmp | GAM_GAMI_SET) : (tmp & GAM_GAMI_CLEAR);
    /* ID bit masked status, mask:CANGAM<GAMn>=1, unmask:CANGAM<GAMn>=0 */
    tmp =
        (MaskIDStruct->MaskState ==
         ENABLE) ? (tmp | MaskIDStruct->MaskIDBit) : (tmp & ~MaskIDStruct->MaskIDBit);
    /* Global mailbox:CANGAM, local mailbox:CANLAM */
    if (MaskIDStruct->MbxType == CAN_MBX_GLOBAL) {
        TSB_CAN->GAM = tmp;
    } else {
        TSB_CAN->LAM = tmp;
    }
}

/**
  * @brief  Set operating mode of TXCAN.
  * @param  Mode: Select the operation mode.
  *         This parameter can be one of the following values:
  *         CAN_NORMAL_MODE, CAN_SUSPEND_MODE, CAN_CONFIG_MODE, CAN_SLEEP_MODE.
  * @retval None.
  */
void CAN_SetMode(uint32_t Mode)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_MODE(Mode));

    tmp = TSB_CAN->MCR;
    /* Clear CANMCR<SUR,CCR,SMR> */
    tmp &= MCR_MODE_CLEAR;
    tmp |= Mode;
    TSB_CAN->MCR = tmp;
}

/**
  * @brief  Enable or disable test loop back mode or test error mode.
  * @param  TestModeID: Select the test mode to enable or disable.
  *         This parameter can be one of the following values:
  *         CAN_TEST_LOOP_BACK_MODE, CAN_TEST_ERR_MODE.
  * @param  NewState: the status of the specified test mode by TestModeID.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None.
  */
void CAN_SetTestMode(uint8_t TestModeID, FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_TEST_MODE(TestModeID));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    tmp = TSB_CAN->MCR;
    switch (TestModeID) {
    case CAN_TEST_LOOP_BACK_MODE:
        /* Test loop back mode, enable:CANMCR<TSTLB>=1, disable:CANMCR<TSTLB>=0 */
        tmp = (NewState == ENABLE) ? (tmp | MCR_TSTLB_SET) : (tmp & MCR_TSTLB_CLEAR);
        tmp &= MCR_TSBTEST_CLEAR;
        TSB_CAN->MCR = tmp;
        break;
    case CAN_TEST_ERR_MODE:
        /* Test error mode, enable:CANMCR<TSTERR>=1, disable:CANMCR<TSTERR>=0 */
        tmp = (NewState == ENABLE) ? (tmp | MCR_TSTERR_SET) : (tmp & MCR_TSTERR_CLEAR);
        tmp &= MCR_TSBTEST_CLEAR;
        TSB_CAN->MCR = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable or disable the function of exiting the sleep mode
  *         by detecting bus activity.
  * @param  NewState: the status of the function of exiting the sleep 
  *         mode by detecting bus activity.
  *         This parameter can be ENABLE or DISABLE.
  * @retval None.
  */
void CAN_SetWakeUpOnBusActivity(FunctionalState NewState)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Wakeup on bus activity, enable:CANMCR<WUBA>=1, disable:CANMCR<WUBA>=0 */
    tmp = TSB_CAN->MCR;
    tmp = (NewState == ENABLE) ? (tmp | MCR_WUBA_SET) : (tmp & MCR_WUBA_CLEAR);
    tmp &= MCR_TSBTEST_CLEAR;
    TSB_CAN->MCR = tmp;
}

/**
  * @brief  Select mailbox transmission order, by mailbox number or message ID.
  * @param  TxOrder: Select mailbox transmission order.
  *         This parameter can be CAN_TX_ORDER_MBX_NUM, CAN_TX_ORDER_ID.
  * @retval None.
  */
void CAN_SetTxOrder(uint8_t TxOrder)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_TX_ORDER(TxOrder));

    /* Mailbox Tx order, ID:CANMCR<MTOS>=1, mailbox number:CANMCR<MTOS>=0 */
    tmp = TSB_CAN->MCR;
    tmp = (TxOrder == CAN_TX_ORDER_ID) ? (tmp | MCR_MTOS_SET) : (tmp & MCR_MTOS_CLEAR);
    tmp &= MCR_TSBTEST_CLEAR;
    TSB_CAN->MCR = tmp;
}

/**
  * @brief  Clear time stamp counter.
  * @param  None.
  * @retval None.
  */
void CAN_ClearTimeStampCnt(void)
{
    uint32_t tmp = 0U;
    /* Set CANMCR<TSCC> */
    tmp = TSB_CAN->MCR;
    tmp |= MCR_TSCC_SET;
    tmp &= MCR_TSBTEST_CLEAR;
    TSB_CAN->MCR = tmp;
}

/**
  * @brief  Software reset of the module(all parameters will reset to their initial values).
  * @param  None.
  * @retval None.
  */
void CAN_SWReset(void)
{
    uint32_t tmp = 0U;
    /* Set CANMCR<SRES> */
    tmp = TSB_CAN->MCR;
    tmp |= MCR_SRES_SET;
    tmp &= MCR_TSBTEST_CLEAR;
    TSB_CAN->MCR = tmp;
}

/**
  * @brief  Configure the bit timing and sampling parameters.
  * @param  BitTimingStruct: The structure used to specify the baud rate 
  *         prescaler, bit timing parameter Sjw, Tseg1, Tseg2
  *         and sampling method.
  * @retval None.
  */
void CAN_ConfigBitTiming(CAN_BitTimingTypeDef * BitTimingStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(BitTimingStruct));
    assert_param(IS_CAN_TIMING_BRP(BitTimingStruct->Brp));
    assert_param(IS_CAN_TIMING_SJW(BitTimingStruct->Sjw));
    assert_param(IS_CAN_SAMPLING_MODE(BitTimingStruct->Sam));
    assert_param(IS_CAN_TIMING_TSEG1(BitTimingStruct->Tseg1));
    assert_param(IS_CAN_TIMING_TSEG2(BitTimingStruct->Tseg2));
    assert_param(IS_CAN_TIMING_CHECK
                 (BitTimingStruct->Sjw, BitTimingStruct->Tseg1, BitTimingStruct->Tseg2));

    if (BitTimingStruct->Brp == 0U) {
        assert_param(IS_CAN_TIMING_BRP0_TSEG2(BitTimingStruct->Tseg2));
        assert_param(IS_CAN_SAMPLING_SINGLE_MODE(BitTimingStruct->Sam));
    } else {
        if (BitTimingStruct->Brp < 4U) {
            assert_param(IS_CAN_SAMPLING_SINGLE_MODE(BitTimingStruct->Sam));
        } else {
            /* Do nothing */
        }
    }

    /* Set baud rate prescaler CANBCR1<BRP> */
    tmp = (uint32_t) BitTimingStruct->Brp;
    TSB_CAN->BCR1 = tmp;
    /* Set bit timing parameters CANBCR2<SJW,TSEG2,TSEG1> */
    tmp = 0U;
    tmp |= (uint32_t) BitTimingStruct->Tseg1 |
        ((uint32_t) BitTimingStruct->Tseg2 << 4U) | ((uint32_t) BitTimingStruct->Sjw << 8U);
    /* Set sampling method, single sampling:CANBCR2<SAM>=0, triple sampling:CANBCR2<SAM>=1 */
    tmp = (BitTimingStruct->Sam ==
           CAN_TRIPLE_SAMPLING) ? (tmp | BCR2_SAM_SET) : (tmp & BCR2_SAM_CLEAR);

    TSB_CAN->BCR2 = tmp;
}

/**
  * @brief  Set time stamp counter value and prescaler.
  * @param  CntValue: 16-bits time stamp counter value.
  * @param  Prescaler: Time stamp counter prescaler, and 
  *         this value should be equal or less than 0xF.
  * @retval None.
  */
void CAN_SetTimeStampCnt(uint16_t CntValue, uint8_t Prescaler)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_TIME_STAMP_PRESCALER(Prescaler));

    /* Set time stamp counter prescaler CANTSP<TSP> */
    tmp = (uint32_t) Prescaler;
    TSB_CAN->TSP = tmp;
    /* Set time stamp counter CANTSC<TSC> */
    tmp = (uint32_t) CntValue;
    TSB_CAN->TSC = tmp;
}

/**
  * @brief  Get the transmission/receiving error counter value.
  * @param  TxErrCnt: The pointer to store transmission error counter value.
  * @param  RxErrCnt: The pointer to store receiving error counter value.
  * @retval None.
  */
void CAN_GetErrCnt(uint8_t * TxErrCnt, uint8_t * RxErrCnt)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(TxErrCnt));
    assert_param(IS_POINTER_NOT_NULL(RxErrCnt));

    tmp = TSB_CAN->CEC;
    /* Get Tx error counter CANCEC<TEC> */
    *TxErrCnt = (uint8_t) (tmp >> 8U);
    /* Get Rx error counter CANCEC<REC> */
    *RxErrCnt = (uint8_t) tmp;
}

/**
  * @brief  Set the transmission/receiving error counter value in test error mode.
  * @param  TRxErrCnt: The value to set transmission error counter and receiving error counter, 
  *         these two counters should be set the same value at the same time in test error mode.
  * @retval None.
  */
void CAN_SetErrCnt(uint8_t TRxErrCnt)
{
    uint32_t tmp = 0U;

    /* Set TRx error counter CANCEC<TEC,REC> */
    tmp = (uint32_t) TRxErrCnt | ((uint32_t) (TRxErrCnt) << 8U);
    TSB_CAN->CEC = tmp;
}

/**
  * @brief  Get the global state flag of the module.
  * @param  None.
  * @retval If the specified state happens, the bit will be set.
  */
CAN_GlobalState CAN_GetGlobalState(void)
{
    CAN_GlobalState retval = { 0U };

    /* Get global status CANGSR */
    retval.All = TSB_CAN->GSR;
    return retval;
}

/**
  * @brief  Get the global or mailbox interrupt flag.
  * @param  INTTypeID: Select the global, mailbox transmission/receiving 
  *         interrupt flag intended to get. This parameter can 
  *         be one of the following values:
  *         CAN_INT_TYPE_GLOBAL, CAN_INT_TYPE_TX, CAN_INT_TYPE_RX.
  * @retval The structure used to store interrupt flag. If the specified 
  *         interrupt happens, the flag will be set.
  */
CAN_INTFactor CAN_GetINTFlag(uint8_t INTTypeID)
{
    CAN_INTFactor retval = { 0U };

    /* Check the parameters */
    assert_param(IS_CAN_INT_TYPE_ID(INTTypeID));

    switch (INTTypeID) {
    case CAN_INT_TYPE_GLOBAL:
        /* Get global interrupt flag CANGIF */
        retval.All = TSB_CAN->GIF;
        retval.All &= GIF_INT_MASK;
        break;
    case CAN_INT_TYPE_TX:
        /* Get mailbox Tx interrupt flag CANMBTIF */
        retval.All = TSB_CAN->MBTIF;
        retval.All &= MBTIF_INT_MASK;
        break;
    case CAN_INT_TYPE_RX:
        /* Get mailbox Rx interrupt flag CANMBRIF */
        retval.All = TSB_CAN->MBRIF;
        break;
    default:
        /* Do nothing */
        break;
    }
    return retval;
}

/**
  * @brief  Clear the global or mailbox interrupt flag.
  * @param  INTTypeID: Select the global, mailbox transmission/receiving 
  *         interrupt flag intended to clear. This parameter can 
  *         be one of the following values:
  *         CAN_INT_TYPE_GLOBAL, CAN_INT_TYPE_TX, CAN_INT_TYPE_RX.
  * @retval None.
  */
void CAN_ClearINTFlag(uint8_t INTTypeID)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_CAN_INT_TYPE_ID(INTTypeID));

    switch (INTTypeID) {
    case CAN_INT_TYPE_GLOBAL:
        /* Get global interrupt flag CANGIF */
        tmp = TSB_CAN->GIF;
        tmp &= GIF_INT_MASK;
        /* Clear global interrupt flag CANGIF */
        TSB_CAN->GIF = tmp;
        break;
    case CAN_INT_TYPE_TX:
        /* Get mailbox Tx interrupt flag CANMBTIF */
        tmp = TSB_CAN->MBTIF;
        tmp &= MBTIF_INT_MASK;
        /* Clear mailbox Tx interrupt flag CANMBTIF */
        TSB_CAN->MBTIF = tmp;
        break;
    case CAN_INT_TYPE_RX:
        /* Get mailbox Rx interrupt flag CANMBRIF */
        tmp = TSB_CAN->MBRIF;
        /* Clear mailbox Rx interrupt flag CANMBRIF */
        TSB_CAN->MBRIF = tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set the global or mailbox interrupt mask.
  * @param  INTMaskType: Select the global, mailbox transmission/receiving 
  *         interrupt intended to mask. This parameter can be one of the 
  *         following values:
  *         CAN_INT_GLOBAL_MASK, CAN_INT_MBX_MASK.
  * @param  INTMaskStruct: The structure used to enable or disable specified 
  *         interrupt. If the specified bit is set, the interrupt will be enabled.
  * @retval None.
  */
void CAN_SetINTMask(uint8_t INTMaskType, CAN_INTFactor * INTMaskStruct)
{
    uint32_t tmp = 0U;

    /* Check the parameters */
    assert_param(CAN_INT_MASK_TYPE(INTMaskType));
    assert_param(IS_POINTER_NOT_NULL(INTMaskStruct));

    tmp = INTMaskStruct->All;
    if (INTMaskType == CAN_INT_GLOBAL_MASK) {
        /* Set global interrupt mask CANGIM */
        tmp &= GIF_INT_MASK;
        TSB_CAN->GIM = tmp;
    } else if (INTMaskType == CAN_INT_MBX_MASK) {
        /* Set mailbox interrupt mask CANMBIM */
        TSB_CAN->MBIM = tmp;
    } else {
        /* Do nothing */
    }
}

/** @} */
/* End of group CAN_Exported_Functions */

/** @} */
/* End of group CAN */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM363_CAN_H) || defined(__TMPM364_CAN_H) */
