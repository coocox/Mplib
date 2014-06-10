/**************************************************************************//**
 * @file     can.h
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series CAN driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef  __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CAN_Driver CAN Driver
  @{
*/

/** @addtogroup NUC400_CAN_EXPORTED_TYPEDEF CAN Exported Type Defines
  @{
*/

/* Message ID types*/
typedef enum {
    CAN_STD_ID = 0,
    CAN_EXT_ID = 1
} E_CAN_ID_TYPE;

/* Message Frame types*/
typedef enum {
    REMOTE_FRAME = 0,
    DATA_FRAME   = 1
} E_CAN_FRAME_TYPE;

/* CAN message structure*/
typedef struct {
    uint32_t  IdType;
    uint32_t  FrameType;
    uint32_t  Id;
    uint8_t   DLC;
    uint8_t   Data[8];
} STR_CANMSG_T;

/* CAN mask message structure*/
typedef struct {
    uint8_t   u8Xtd;
    uint8_t   u8Dir;
    uint32_t  u32Id;
    uint8_t   u8IdType;
} STR_CANMASK_T;

typedef enum {
    CAN_NOTMAL_MODE = 1,
    CAN_BASIC_MODE = 2
} CAN_MODE_SELECT;

#define ALL_MSG  32
#define MSG(id)  id


/*@}*/ /* end of group NUC400_CAN_EXPORTED_TYPEDEF */


/** @addtogroup NUC400_CAN_EXPORTED_FUNCTIONS CAN Exported Functions
  @{
*/

/**
 *  @brief    Get interrupt status
 *
 *  @param    can  The base address of can module
 *
 *  @return   CAN module status register value
 */
#define CAN_GET_INT_STATUS(can)    (can->STATUS)

/**
 *  @brief    Get specified interrupt pending status
 *
 *  @param    can  The base address of can module
 *
 *  @return   The source of the interrupt.
 */
#define CAN_GET_INT_PENDING_STATUS(can)     (can->IIDR)

/**
 *  @brief    Disable Wakeup function
 *
 *  @param    can  The base address of can module
 *
 *  @return   None
 */
#define CAN_DISABLE_WAKEUP(can)             (can->WU_IE = 0)

/**
 *  @brief    Enable Wakeup function
 *
 *  @param    can  The base address of can module
 *
 *  @return   None
 */
#define CAN_ENABLE_WAKEUP(can)              (can->WU_IE = CAN_WUEN_WAKUP_EN_Msk)

/**
 *  @brief    Get specified Message Object new data into bit value
 *
 *  @param    can        The base address of can module
 *  @param    u32MsgNum  Specified Message Object number. (0 ~ 31)
 *
 *  @return   Specified Message Object new data into bit value.
 */
#define CAN_GET_NEW_DATA_IN_BIT(can, u32MsgNum)    (u32MsgNum < 16 ? can->NDAT1 & (1 << u32MsgNum) : can->NDAT2 & (1 << (u32MsgNum-16)))


/*---------------------------------------------------------------------------------------------------------*/
/* Define CAN functions prototype                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
uint32_t CAN_SetBaudRate(CAN_T *tCAN, uint32_t u32BaudRate);
uint32_t CAN_Open(CAN_T *tCAN, uint32_t u32BaudRate, uint32_t u32Mode);
int32_t CAN_Transmit(CAN_T *tCAN, uint32_t u32MsgNum , STR_CANMSG_T* pCanMsg);
int32_t CAN_Receive(CAN_T *tCAN, uint32_t u32MsgNum , STR_CANMSG_T* pCanMsg);
void CAN_CLR_INT_PENDING_BIT(CAN_T *tCAN, uint8_t u32MsgNum);
void CAN_EnableInt(CAN_T  *tCAN, uint32_t u32Mask);
void CAN_DisableInt(CAN_T  *tCAN, uint32_t u32Mask);
int32_t CAN_SetMultiRxMsg(CAN_T *tCAN, uint32_t u32MsgNum , uint32_t u32MsgCount, uint32_t u32IDType, uint32_t u32ID);
int32_t CAN_SetRxMsg(CAN_T *tCAN, uint32_t u32MsgNum , uint32_t u32IDType, uint32_t u32ID);
int32_t CAN_SetTxMsg(CAN_T *tCAN, uint32_t u32MsgNum , STR_CANMSG_T* pCanMsg);
int32_t CAN_TriggerTxMsg(CAN_T  *tCAN, uint32_t u32MsgNum);

/*@}*/ /* end of group NUC400_CAN_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CAN_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__CAN_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/





