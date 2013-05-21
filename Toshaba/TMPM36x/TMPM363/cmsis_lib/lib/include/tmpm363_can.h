/**
 *******************************************************************************
 * @file    tmpm363_can.h
 * @brief   This file provides all the functions prototypes for CAN driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM363_CAN_H
#define __TMPM363_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM363.h"
#include "tx03_common.h"

#if defined(__TMPM363_CAN_H) || defined(__TMPM364_CAN_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup CAN
  * @{
  */

/** @defgroup CAN_Exported_Types
  * @{
  */

/**
  * @brief CAN mailbox status union definition
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Mbx0:1;
            uint32_t Mbx1:1;
            uint32_t Mbx2:1;
            uint32_t Mbx3:1;
            uint32_t Mbx4:1;
            uint32_t Mbx5:1;
            uint32_t Mbx6:1;
            uint32_t Mbx7:1;
            uint32_t Mbx8:1;
            uint32_t Mbx9:1;
            uint32_t Mbx10:1;
            uint32_t Mbx11:1;
            uint32_t Mbx12:1;
            uint32_t Mbx13:1;
            uint32_t Mbx14:1;
            uint32_t Mbx15:1;
            uint32_t Mbx16:1;
            uint32_t Mbx17:1;
            uint32_t Mbx18:1;
            uint32_t Mbx19:1;
            uint32_t Mbx20:1;
            uint32_t Mbx21:1;
            uint32_t Mbx22:1;
            uint32_t Mbx23:1;
            uint32_t Mbx24:1;
            uint32_t Mbx25:1;
            uint32_t Mbx26:1;
            uint32_t Mbx27:1;
            uint32_t Mbx28:1;
            uint32_t Mbx29:1;
            uint32_t Mbx30:1;
            uint32_t Mbx31:1;
        } Bit;
    } CAN_MbxState;

/**
  * @brief CAN acceptance mask ID structure definition
  */
    typedef struct {
        uint8_t MbxType;        /*!< MailBox type: Global or Local */
        uint32_t MaskIDBit;     /*!< ID bit to be masked */
        FunctionalState ExtIDState;     /*!< Extension bit masked status */
        FunctionalState MaskState;      /*!< ID bit masked status */
    } CAN_RxMaskIDTypeDef;

/**
  * @brief CAN interrupt flag union definition
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t WarningLevel:1;
            uint32_t ErrPassive:1;
            uint32_t BusOff:1;
            uint32_t TimeStampOverFlow:1;
            uint32_t TxAbort:1;
            uint32_t RxLost:1;
            uint32_t WakeUp:1;
            uint32_t RmtFramePending:1;
            uint32_t Reserverd:24;
        } GlobalBit;
        struct {
            uint32_t Mbx0:1;
            uint32_t Mbx1:1;
            uint32_t Mbx2:1;
            uint32_t Mbx3:1;
            uint32_t Mbx4:1;
            uint32_t Mbx5:1;
            uint32_t Mbx6:1;
            uint32_t Mbx7:1;
            uint32_t Mbx8:1;
            uint32_t Mbx9:1;
            uint32_t Mbx10:1;
            uint32_t Mbx11:1;
            uint32_t Mbx12:1;
            uint32_t Mbx13:1;
            uint32_t Mbx14:1;
            uint32_t Mbx15:1;
            uint32_t Mbx16:1;
            uint32_t Mbx17:1;
            uint32_t Mbx18:1;
            uint32_t Mbx19:1;
            uint32_t Mbx20:1;
            uint32_t Mbx21:1;
            uint32_t Mbx22:1;
            uint32_t Mbx23:1;
            uint32_t Mbx24:1;
            uint32_t Mbx25:1;
            uint32_t Mbx26:1;
            uint32_t Mbx27:1;
            uint32_t Mbx28:1;
            uint32_t Mbx29:1;
            uint32_t Mbx30:1;
            uint32_t Mbx31:1;
        } MbxBit;
    } CAN_INTFactor;

/**
  * @brief CAN global status union definition
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t WarningStatus:1;
            uint32_t ErrPassiveStatus:1;
            uint32_t BusOffStatus:1;
            uint32_t TimeStampOverFlow:1;
            uint32_t Reserverd2:2;
            uint32_t SleepModeAck:1;
            uint32_t ChangeConfig:1;
            uint32_t SuspendModeAck:1;
            uint32_t Reserverd1:1;
            uint32_t TxMode:1;
            uint32_t RxMode:1;
            uint32_t MsgInSlot:5;
            uint32_t Reserverd0:15;
        } Bit;
    } CAN_GlobalState;

/**
  * @brief CAN bit timing configuration structure definition
  */
    typedef struct {
        uint16_t Brp;           /*!< Baud rate prescaler, 10bits */
        uint8_t Tseg1;          /*!< Bit Timing 1 */
        uint8_t Tseg2;          /*!< Bit Timing 2 */
        uint8_t Sam;            /*!< Single or Triple Sampling */
        uint8_t Sjw;            /*!< Number of TQ when re-synchronizing */
    } CAN_BitTimingTypeDef;

/**
  * @brief CAN mailbox message structure definition
  */
    typedef struct {
        uint32_t MsgID;         /*!< 29 bit identifier */
        uint8_t MsgData[8];     /*!< Data field */
        uint8_t MsgDataLen;     /*!< Length of data field in bytes, 0~8 */
        uint8_t MsgFormat;      /*!< STANDARD or EXTENDED FORMAT */
        uint8_t MsgFrameType;   /*!< DATA FRAME or REMOTE FRAME */
        uint16_t MsgTimeStamp;  /*!< TimeStamp value */
        uint8_t RmtFrameHandleMode;     /*!< Remote Frame handling mode, SW or AUTO */
        FunctionalState RxMaskState;    /*!< Use or unuse Rx mask */
    } CAN_MsgTypeDef;
/** @} */
/* End of group CAN_Exported_Types */

/** @defgroup CAN_Exported_Constants
  * @{
  */
#define CAN_MBX_0                            ((uint32_t)0x00000001)
#define CAN_MBX_1                            ((uint32_t)0x00000002)
#define CAN_MBX_2                            ((uint32_t)0x00000004)
#define CAN_MBX_3                            ((uint32_t)0x00000008)
#define CAN_MBX_4                            ((uint32_t)0x00000010)
#define CAN_MBX_5                            ((uint32_t)0x00000020)
#define CAN_MBX_6                            ((uint32_t)0x00000040)
#define CAN_MBX_7                            ((uint32_t)0x00000080)
#define CAN_MBX_8                            ((uint32_t)0x00000100)
#define CAN_MBX_9                            ((uint32_t)0x00000200)
#define CAN_MBX_10                           ((uint32_t)0x00000400)
#define CAN_MBX_11                           ((uint32_t)0x00000800)
#define CAN_MBX_12                           ((uint32_t)0x00001000)
#define CAN_MBX_13                           ((uint32_t)0x00002000)
#define CAN_MBX_14                           ((uint32_t)0x00004000)
#define CAN_MBX_15                           ((uint32_t)0x00008000)
#define CAN_MBX_16                           ((uint32_t)0x00010000)
#define CAN_MBX_17                           ((uint32_t)0x00020000)
#define CAN_MBX_18                           ((uint32_t)0x00040000)
#define CAN_MBX_19                           ((uint32_t)0x00080000)
#define CAN_MBX_20                           ((uint32_t)0x00100000)
#define CAN_MBX_21                           ((uint32_t)0x00200000)
#define CAN_MBX_22                           ((uint32_t)0x00400000)
#define CAN_MBX_23                           ((uint32_t)0x00800000)
#define CAN_MBX_24                           ((uint32_t)0x01000000)
#define CAN_MBX_25                           ((uint32_t)0x02000000)
#define CAN_MBX_26                           ((uint32_t)0x04000000)
#define CAN_MBX_27                           ((uint32_t)0x08000000)
#define CAN_MBX_28                           ((uint32_t)0x10000000)
#define CAN_MBX_29                           ((uint32_t)0x20000000)
#define CAN_MBX_30                           ((uint32_t)0x40000000)
#define CAN_MBX_31                           ((uint32_t)0x80000000)
#define CAN_MBX_ALL                          ((uint32_t)0xFFFFFFFF)

#define CAN_ID_BIT_0                         ((uint32_t)0x00000001)
#define CAN_ID_BIT_1                         ((uint32_t)0x00000002)
#define CAN_ID_BIT_2                         ((uint32_t)0x00000004)
#define CAN_ID_BIT_3                         ((uint32_t)0x00000008)
#define CAN_ID_BIT_4                         ((uint32_t)0x00000010)
#define CAN_ID_BIT_5                         ((uint32_t)0x00000020)
#define CAN_ID_BIT_6                         ((uint32_t)0x00000040)
#define CAN_ID_BIT_7                         ((uint32_t)0x00000080)
#define CAN_ID_BIT_8                         ((uint32_t)0x00000100)
#define CAN_ID_BIT_9                         ((uint32_t)0x00000200)
#define CAN_ID_BIT_10                        ((uint32_t)0x00000400)
#define CAN_ID_BIT_11                        ((uint32_t)0x00000800)
#define CAN_ID_BIT_12                        ((uint32_t)0x00001000)
#define CAN_ID_BIT_13                        ((uint32_t)0x00002000)
#define CAN_ID_BIT_14                        ((uint32_t)0x00004000)
#define CAN_ID_BIT_15                        ((uint32_t)0x00008000)
#define CAN_ID_BIT_16                        ((uint32_t)0x00010000)
#define CAN_ID_BIT_17                        ((uint32_t)0x00020000)
#define CAN_ID_BIT_18                        ((uint32_t)0x00040000)
#define CAN_ID_BIT_19                        ((uint32_t)0x00080000)
#define CAN_ID_BIT_20                        ((uint32_t)0x00100000)
#define CAN_ID_BIT_21                        ((uint32_t)0x00200000)
#define CAN_ID_BIT_22                        ((uint32_t)0x00400000)
#define CAN_ID_BIT_23                        ((uint32_t)0x00800000)
#define CAN_ID_BIT_24                        ((uint32_t)0x01000000)
#define CAN_ID_BIT_25                        ((uint32_t)0x02000000)
#define CAN_ID_BIT_26                        ((uint32_t)0x04000000)
#define CAN_ID_BIT_27                        ((uint32_t)0x08000000)
#define CAN_ID_BIT_28                        ((uint32_t)0x10000000)
#define CAN_ID_BIT_ALL                       ((uint32_t)0x1FFFFFFF)

#define IS_CAN_EXT_ID(param)                 ((param) <= CAN_ID_BIT_ALL)
#define IS_CAN_STD_ID(param)                 ((param) < CAN_ID_BIT_11)

#define IS_CAN_GLOBAL_MBX_NUM(param)         ((param) < CAN_MBX_31)
#define IS_CAN_SINGLE_MBX_NUM(param)        (((param) == CAN_MBX_0) || \
                                             ((param) == CAN_MBX_1) || \
                                             ((param) == CAN_MBX_2) || \
                                             ((param) == CAN_MBX_3) || \
                                             ((param) == CAN_MBX_4) || \
                                             ((param) == CAN_MBX_5) || \
                                             ((param) == CAN_MBX_6) || \
                                             ((param) == CAN_MBX_7) || \
                                             ((param) == CAN_MBX_8) || \
                                             ((param) == CAN_MBX_9) || \
                                             ((param) == CAN_MBX_10)|| \
                                             ((param) == CAN_MBX_11)|| \
                                             ((param) == CAN_MBX_12)|| \
                                             ((param) == CAN_MBX_13)|| \
                                             ((param) == CAN_MBX_14)|| \
                                             ((param) == CAN_MBX_15)|| \
                                             ((param) == CAN_MBX_16)|| \
                                             ((param) == CAN_MBX_17)|| \
                                             ((param) == CAN_MBX_18)|| \
                                             ((param) == CAN_MBX_19)|| \
                                             ((param) == CAN_MBX_20)|| \
                                             ((param) == CAN_MBX_21)|| \
                                             ((param) == CAN_MBX_22)|| \
                                             ((param) == CAN_MBX_23)|| \
                                             ((param) == CAN_MBX_24)|| \
                                             ((param) == CAN_MBX_25)|| \
                                             ((param) == CAN_MBX_26)|| \
                                             ((param) == CAN_MBX_27)|| \
                                             ((param) == CAN_MBX_28)|| \
                                             ((param) == CAN_MBX_29)|| \
                                             ((param) == CAN_MBX_30)|| \
                                             ((param) == CAN_MBX_31))

#define IS_CAN_DATA_LEN(param)               ((param) <= 0x08U)

#define CAN_STD_FORMAT                       ((uint8_t)0x00)
#define CAN_EXT_FORMAT                       ((uint8_t)0x01)
#define IS_CAN_FORMAT(param)                (((param) == CAN_STD_FORMAT) || ((param) == CAN_EXT_FORMAT))

#define CAN_DATA_FRAME                       ((uint8_t)0x00)
#define CAN_RMT_FRAME                        ((uint8_t)0x01)
#define IS_CAN_FRAME_TYPE(param)            (((param) == CAN_DATA_FRAME) || ((param) == CAN_RMT_FRAME))

#define CAN_RMT_FRAME_SW_HANDLE              ((uint8_t)0x00)
#define CAN_RMT_FRAME_AUTO_HANDLE            ((uint8_t)0x01)
#define IS_CAN_RMT_FRAME_HANDLE(param)      (((param) == CAN_RMT_FRAME_SW_HANDLE) || ((param) == CAN_RMT_FRAME_AUTO_HANDLE))

#define CAN_MBX_GLOBAL                       ((uint8_t)0x00)
#define CAN_MBX_LOCAL                        ((uint8_t)0x01)
#define IS_CAN_MBX_TYPE(param)              (((param) == CAN_MBX_GLOBAL) || ((param) == CAN_MBX_LOCAL))

#define CAN_STATE_ID_TX_ACK                  ((uint8_t)0x00)
#define CAN_STATE_ID_TX_ABORT                ((uint8_t)0x01)
#define CAN_STATE_ID_RX_ACK                  ((uint8_t)0x02)
#define CAN_STATE_ID_RX_LOST                 ((uint8_t)0x03)
#define CAN_STATE_ID_RX_RMT_FRAME            ((uint8_t)0x04)
#define IS_CAN_STATE_ID(param)              (((param) == CAN_STATE_ID_TX_ACK) || \
                                             ((param) == CAN_STATE_ID_TX_ABORT) || \
                                             ((param) == CAN_STATE_ID_RX_ACK) || \
                                             ((param) == CAN_STATE_ID_RX_LOST)|| \
                                             ((param) == CAN_STATE_ID_RX_RMT_FRAME))

#define CAN_INT_TYPE_GLOBAL                  ((uint8_t)0x00)
#define CAN_INT_TYPE_TX                      ((uint8_t)0x01)
#define CAN_INT_TYPE_RX                      ((uint8_t)0x02)
#define IS_CAN_INT_TYPE_ID(param)           (((param) == CAN_INT_TYPE_GLOBAL) || \
                                             ((param) == CAN_INT_TYPE_TX) || \
                                             ((param) == CAN_INT_TYPE_RX))

#define CAN_INT_GLOBAL_MASK                  ((uint8_t)0x00)
#define CAN_INT_MBX_MASK                     ((uint8_t)0x01)
#define CAN_INT_MASK_TYPE(param)            (((param) == CAN_INT_GLOBAL_MASK) || ((param) == CAN_INT_MBX_MASK))

#define CAN_MBX_TX                           ((uint8_t)0x00)
#define CAN_MBX_RX                           ((uint8_t)0x01)
#define IS_CAN_MBX_DIRECTION(param)         (((param) == CAN_MBX_TX) || ((param) == CAN_MBX_RX))

#define CAN_NORMAL_MODE                      ((uint32_t)0x00000000)
#define CAN_SUSPEND_MODE                     ((uint32_t)0x00000800)
#define CAN_CONFIG_MODE                      ((uint32_t)0x00000080)
#define CAN_SLEEP_MODE                       ((uint32_t)0x00000040)
#define IS_CAN_MODE(param)                  (((param) == CAN_NORMAL_MODE) || \
                                             ((param) == CAN_SUSPEND_MODE)|| \
                                             ((param) == CAN_CONFIG_MODE) || \
                                             ((param) == CAN_SLEEP_MODE))

#define CAN_TEST_LOOP_BACK_MODE              ((uint8_t)0x00)
#define CAN_TEST_ERR_MODE                    ((uint8_t)0x01)
#define IS_CAN_TEST_MODE(param)             (((param) == CAN_TEST_LOOP_BACK_MODE) || ((param) == CAN_TEST_ERR_MODE))

#define CAN_TX_ORDER_MBX_NUM                 ((uint8_t)0x00)
#define CAN_TX_ORDER_ID                      ((uint8_t)0x01)
#define IS_CAN_TX_ORDER(param)              (((param) == CAN_TX_ORDER_MBX_NUM) || ((param) == CAN_TX_ORDER_ID))

#define CAN_TIMING_SJW_1TQ                   ((uint8_t)0x00)
#define CAN_TIMING_SJW_2TQ                   ((uint8_t)0x01)
#define CAN_TIMING_SJW_3TQ                   ((uint8_t)0x02)
#define CAN_TIMING_SJW_4TQ                   ((uint8_t)0x03)
#define IS_CAN_TIMING_SJW(param)            (((param) == CAN_TIMING_SJW_1TQ) || \
                                             ((param) == CAN_TIMING_SJW_2TQ) || \
                                             ((param) == CAN_TIMING_SJW_3TQ) || \
                                             ((param) == CAN_TIMING_SJW_4TQ))

#define CAN_SINGLE_SAMPLING                  ((uint8_t)0x00)
#define CAN_TRIPLE_SAMPLING                  ((uint8_t)0x01)
#define IS_CAN_SAMPLING_MODE(param)         (((param) == CAN_SINGLE_SAMPLING) || ((param) == CAN_TRIPLE_SAMPLING))
#define IS_CAN_SAMPLING_SINGLE_MODE(param)   ((param) == CAN_SINGLE_SAMPLING)

#define CAN_TIMING_TSEG2_2TQ                 ((uint8_t)0x01)
#define CAN_TIMING_TSEG2_3TQ                 ((uint8_t)0x02)
#define CAN_TIMING_TSEG2_4TQ                 ((uint8_t)0x03)
#define CAN_TIMING_TSEG2_5TQ                 ((uint8_t)0x04)
#define CAN_TIMING_TSEG2_6TQ                 ((uint8_t)0x05)
#define CAN_TIMING_TSEG2_7TQ                 ((uint8_t)0x06)
#define CAN_TIMING_TSEG2_8TQ                 ((uint8_t)0x07)
#define IS_CAN_TIMING_TSEG2(param)          (((param) == CAN_TIMING_TSEG2_2TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_3TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_4TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_5TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_6TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_7TQ) || \
                                             ((param) == CAN_TIMING_TSEG2_8TQ))

#define CAN_TIMING_TSEG1_2TQ                 ((uint8_t)0x01)
#define CAN_TIMING_TSEG1_3TQ                 ((uint8_t)0x02)
#define CAN_TIMING_TSEG1_4TQ                 ((uint8_t)0x03)
#define CAN_TIMING_TSEG1_5TQ                 ((uint8_t)0x04)
#define CAN_TIMING_TSEG1_6TQ                 ((uint8_t)0x05)
#define CAN_TIMING_TSEG1_7TQ                 ((uint8_t)0x06)
#define CAN_TIMING_TSEG1_8TQ                 ((uint8_t)0x07)
#define CAN_TIMING_TSEG1_9TQ                 ((uint8_t)0x08)
#define CAN_TIMING_TSEG1_10TQ                ((uint8_t)0x09)
#define CAN_TIMING_TSEG1_11TQ                ((uint8_t)0x0A)
#define CAN_TIMING_TSEG1_12TQ                ((uint8_t)0x0B)
#define CAN_TIMING_TSEG1_13TQ                ((uint8_t)0x0C)
#define CAN_TIMING_TSEG1_14TQ                ((uint8_t)0x0D)
#define CAN_TIMING_TSEG1_15TQ                ((uint8_t)0x0E)
#define CAN_TIMING_TSEG1_16TQ                ((uint8_t)0x0F)
#define IS_CAN_TIMING_TSEG1(param)          (((param) == CAN_TIMING_TSEG1_2TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_3TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_4TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_5TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_6TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_7TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_8TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_9TQ) || \
                                             ((param) == CAN_TIMING_TSEG1_10TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_11TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_12TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_13TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_14TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_15TQ)|| \
                                             ((param) == CAN_TIMING_TSEG1_16TQ))

#define IS_CAN_TIMING_CHECK(Sjw, Tseg1, Tseg2)     (((Tseg1) >= (Tseg2)) && ((Sjw) <= (Tseg2)))
#define IS_CAN_TIMING_BRP(param)             ((param) <= 0x03FFU)
#define IS_CAN_TIMING_BRP0_TSEG2(param)      ((param) >= CAN_TIMING_TSEG2_3TQ)
#define IS_CAN_TIME_STAMP_PRESCALER(param)   ((param) <= 0x0FU)
/** @} */
/* End of group CAN_Exported_Constants */
/** @defgroup CAN_Exported_FunctionPrototypes
  * @{
  */
    void CAN_SetMbxMsg(uint32_t MbxNum, CAN_MsgTypeDef * MsgStruct);
    void CAN_GetMbxMsg(uint32_t MbxNum, CAN_MsgTypeDef * MsgStruct);
    void CAN_SetMbxDirection(uint32_t MbxNum, uint8_t MbxDirection);
    void CAN_EnableMbx(uint32_t MbxNum);
    void CAN_DisableMbx(uint32_t MbxNum);
    void CAN_SetTxReq(uint32_t MbxNum, FunctionalState NewState);
    CAN_MbxState CAN_GetMbxTRxState(uint8_t StateID);
    void CAN_ClearMbxTRxState(uint8_t StateID);
    void CAN_SetTxLock(uint32_t MbxNum, FunctionalState NewState);
    void CAN_SetRxMaskID(CAN_RxMaskIDTypeDef * MaskIDStruct);
    void CAN_SetMode(uint32_t Mode);
    void CAN_SetTestMode(uint8_t TestModeID, FunctionalState NewState);
    void CAN_SetWakeUpOnBusActivity(FunctionalState NewState);
    void CAN_SetTxOrder(uint8_t TxOrder);
    void CAN_ClearTimeStampCnt(void);
    void CAN_SWReset(void);
    void CAN_ConfigBitTiming(CAN_BitTimingTypeDef * BitTimingStruct);
    void CAN_SetTimeStampCnt(uint16_t CntValue, uint8_t Prescaler);
    void CAN_GetErrCnt(uint8_t * TxErrCnt, uint8_t * RxErrCnt);
    void CAN_SetErrCnt(uint8_t TRxErrCnt);
    CAN_GlobalState CAN_GetGlobalState(void);
    CAN_INTFactor CAN_GetINTFlag(uint8_t INTTypeID);
    void CAN_ClearINTFlag(uint8_t INTTypeID);
    void CAN_SetINTMask(uint8_t INTMaskType, CAN_INTFactor * INTMaskStruct);

/** @} */
/* End of group CAN_Exported_FunctionPrototypes */

/** @} */
/* End of group CAN */

/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /* defined(__TMPM363_CAN_H) || defined(__TMPM364_CAN_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM363_CAN_H */
