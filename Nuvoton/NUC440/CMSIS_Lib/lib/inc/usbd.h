/**************************************************************************//**
 * @file     usbd.h
 * @version  V1.00
 * $Revision: 10 $
 * $Date: 13/12/04 10:36a $
 * @brief    NUC400 series USBD driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __USBD_H__
#define __USBD_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_USBD_Driver USBD Driver
  @{
*/

/** @addtogroup NUC400_USBD_EXPORTED_CONSTANTS USBD Exported Constants
  @{
*/
#define USBD_MAX_EP     12

#define Maximum(a,b)    (a)>(b) ? (a) : (b)
#define Minimum(a,b)    (a)<(b) ? (a) : (b)


#define CEP     0xff    /*!< Control Endpoint */
#define EPA     0       /*!< Endpoint A */
#define EPB     1       /*!< Endpoint B */
#define EPC     2       /*!< Endpoint C */
#define EPD     3       /*!< Endpoint D */
#define EPE     4       /*!< Endpoint E */
#define EPF     5       /*!< Endpoint F */
#define EPG     6       /*!< Endpoint G */
#define EPH     7       /*!< Endpoint H */
#define EPI     8       /*!< Endpoint I */
#define EPJ     9       /*!< Endpoint J */
#define EPK     10      /*!< Endpoint K */
#define EPL     11      /*!< Endpoint L */

/*!<USB Request Type */
#define REQ_STANDARD        0x00
#define REQ_CLASS           0x20
#define REQ_VENDOR          0x40

/*!<USB Standard Request */
#define GET_STATUS          0x00
#define CLEAR_FEATURE       0x01
#define SET_FEATURE         0x03
#define SET_ADDRESS         0x05
#define GET_DESCRIPTOR      0x06
#define SET_DESCRIPTOR      0x07
#define GET_CONFIGURATION   0x08
#define SET_CONFIGURATION   0x09
#define GET_INTERFACE       0x0A
#define SET_INTERFACE       0x0B
#define SYNC_FRAME          0x0C

/*!<USB Descriptor Type */
#define DESC_DEVICE         0x01
#define DESC_CONFIG         0x02
#define DESC_STRING         0x03
#define DESC_INTERFACE      0x04
#define DESC_ENDPOINT       0x05
#define DESC_QUALIFIER      0x06
#define DESC_OTHERSPEED     0x07
#define DESC_IFPOWER        0x08
#define DESC_OTG            0x09

/*!<USB HID Descriptor Type */
#define DESC_HID            0x21
#define DESC_HID_RPT        0x22

/*!<USB Descriptor Length */
#define LEN_DEVICE          18
#define LEN_QUALIFIER       10
#define LEN_CONFIG          9
#define LEN_INTERFACE       9
#define LEN_ENDPOINT        7
#define LEN_OTG             5
#define LEN_HID             9

/*!<USB Endpoint Type */
#define EP_ISO              0x01
#define EP_BULK             0x02
#define EP_INT              0x03

#define EP_INPUT            0x80
#define EP_OUTPUT           0x00

/*!<USB Feature Selector */
#define FEATURE_DEVICE_REMOTE_WAKEUP    0x01
#define FEATURE_ENDPOINT_HALT           0x00

/********************* Bit definition of CEP_CTRL_STAT register **********************/
#define USB_CEP_CTRL_STAT_NAK_CLEAR     ((uint32_t)0x00000000)      /*!<NAK clear */
#define USB_CEP_CTRL_STAT_STALL         ((uint32_t)0x00000002)      /*!<Stall */
#define USB_CEP_CTRL_STAT_ZEROLEN       ((uint32_t)0x00000004)      /*!<Zero length packet */
#define USB_CEP_CTRL_STAT_FLUSH         ((uint32_t)0x00000008)      /*!<CEP flush */

/********************* Bit definition of EPx_RSP_SC register **********************/
#define USB_EP_RSP_SC_BUF_FLUSH         ((uint32_t)0x00000001)      /*!<Buffer Flush */
#define USB_EP_RSP_SC_MODE_AUTO         ((uint32_t)0x00000000)      /*!<Auto-Validate Mode */
#define USB_EP_RSP_SC_MODE_MANUAL       ((uint32_t)0x00000002)      /*!<Manual-Validate Mode */
#define USB_EP_RSP_SC_MODE_FLY          ((uint32_t)0x00000004)      /*!<Fly Mode */
#define USB_EP_RSP_SC_MODE_MASK         ((uint32_t)0x00000006)      /*!<Mode Mask */
#define USB_EP_RSP_SC_TOGGLE            ((uint32_t)0x00000008)      /*!<Clear Toggle bit */
#define USB_EP_RSP_SC_HALT              ((uint32_t)0x00000010)      /*!<Endpoint halt */
#define USB_EP_RSP_SC_ZEROLEN           ((uint32_t)0x00000020)      /*!<Zero length packet IN */
#define USB_EP_RSP_SC_PK_END            ((uint32_t)0x00000040)      /*!<Packet end */
#define USB_EP_RSP_SC_DIS_BUF           ((uint32_t)0x00000080)      /*!<Disable buffer */

/********************* Bit definition of EPx_CFG register **********************/
#define USB_EP_CFG_VALID                ((uint32_t)0x00000001)      /*!<Endpoint Valid */
#define USB_EP_CFG_TYPE_BULK            ((uint32_t)0x00000002)      /*!<Endpoint type - bulk */
#define USB_EP_CFG_TYPE_INT             ((uint32_t)0x00000004)      /*!<Endpoint type - interrupt */
#define USB_EP_CFG_TYPE_ISO             ((uint32_t)0x00000006)      /*!<Endpoint type - isochronous */
#define USB_EP_CFG_TYPE_MASK            ((uint32_t)0x00000006)      /*!<Endpoint type mask */
#define USB_EP_CFG_DIR_OUT              ((uint32_t)0x00000000)      /*!<OUT endpoint */
#define USB_EP_CFG_DIR_IN               ((uint32_t)0x00000008)      /*!<IN endpoint */


/*@}*/ /* end of group NUC400_USBD_EXPORTED_CONSTANTS */

/** @addtogroup NUC400_USBD_EXPORTED_STRUCT USBD Exported Struct
  @{
*/

typedef void (*CLASS_REQ)(void);
typedef void (*SET_INTERFACE_REQ)(void);

/*!<USB Setup Packet Structure */
typedef struct USBD_CMD_STRUCT {
    uint8_t  bmRequestType;
    uint8_t  bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;

} S_USBD_CMD_T;



/*!<USB Information Structure */
typedef struct s_usbd_info {
    uint8_t *gu8DevDesc;
    uint8_t *gu8ConfigDesc;
    uint8_t *gu8StrLangDesc;
    uint8_t *gu8StrVendorDesc;
    uint8_t *gu8StrProductDesc;
    uint8_t *gu8QualDesc;
    uint8_t *gu8OtherConfigDesc;
    uint8_t *gu8HidReportDesc;

} S_USBD_INFO_T;


/*@}*/ /* end of group NUC400_USBD_EXPORTED_STRUCT */

/// @cond HIDDEN_SYMBOLS
extern uint32_t volatile g_usbd_DmaDone;
extern uint32_t g_usbd_UsbAddr;
extern uint32_t g_usbd_CtrlInSize;
extern uint32_t g_usbd_ShortPacket;
extern uint8_t g_usbd_EpHalt[];
extern S_USBD_INFO_T gsInfo;
extern S_USBD_CMD_T gUsbCmd;
/// @endcond HIDDEN_SYMBOLS

/** @addtogroup NUC400_USBD_EXPORTED_MACROS USBD Exported Macros
  @{
*/

/*!<Enable USB */
#define USBD_ENABLE_USB()               ((uint32_t)(USBD->PHY_CTL |= (USBD_PHY_CTL_PHY_SUSPEND_Msk|USBD_PHY_CTL_DP_PULLUP_Msk)))

/*!<Disable USB */
#define USBD_DISABLE_USB()              ((uint32_t)(USBD->PHY_CTL &= ~USBD_PHY_CTL_DP_PULLUP_Msk))

/*!<Enable PHY */
#define USBD_ENABLE_PHY()               ((uint32_t)(USBD->PHY_CTL |= USBD_PHY_CTL_PHY_SUSPEND_Msk))

/*!<Disable PHY */
#define USBD_DISABLE_PHY()              ((uint32_t)(USBD->PHY_CTL &= ~USBD_PHY_CTL_PHY_SUSPEND_Msk))

/*!<Enable SE0, Force USB PHY Transceiver to Drive SE0 */
#define USBD_SET_SE0()                  ((uint32_t)(USBD->PHY_CTL &= ~USBD_PHY_CTL_DP_PULLUP_Msk))

/*!<Disable SE0 */
#define USBD_CLR_SE0()                  ((uint32_t)(USBD->PHY_CTL |= USBD_PHY_CTL_DP_PULLUP_Msk))

/*!<Set USB address */
#define USBD_SET_ADDR(addr)             (USBD->ADDR = (addr))

/*!<Get USB address */
#define USBD_GET_ADDR()                 ((uint32_t)(USBD->ADDR))

/*!<Enable USB Interrupt */
#define UBSD_ENABLE_USB_INT(intr)       (USBD->IRQ_ENB_L = (intr))

/*!<Enable BUS Interrupt */
#define UBSD_ENABLE_BUS_INT(intr)       (USBD->IRQ_ENB = (intr))

/*!<Clear Bus interrupt flag */
#define USBD_CLR_BUS_INT_FLAG(flag)     (USBD->IRQ_STAT = flag)

/*!<Enable CEP Interrupt */
#define UBSD_ENABLE_CEP_INT(intr)       (USBD->CEP_IRQ_ENB = (intr))

/*!<Clear CEP interrupt flag */
#define USBD_CLR_CEP_INT_FLAG(flag)     (USBD->CEP_IRQ_STAT = flag)

/*!<Set CEP state */
#define USBD_SET_CEP_STATE(flag)        (USBD->CEP_CTRL_STAT = flag)

/*!<Start CEP IN Transfer */
#define USBD_START_CEP_IN(size)         (USBD->IN_TRF_CNT = size)

/*!<Set EPx Maximum Packet Size */
#define UBSD_SET_MAX_PAYLOAD(ep, size)  (*((__IO uint32_t *) ((uint32_t)&USBD->EPA_MPS + (uint32_t)((ep)*0x28))) = (size))

/*!<Enable EPx Interrupt */
#define UBSD_ENABLE_EP_INT(ep, intr)    (*((__IO uint32_t *) ((uint32_t)&USBD->EPA_IRQ_ENB + (uint32_t)((ep)*0x28))) = (intr))

/*!<Get EPx interrupt flag */
#define USBD_GET_EP_INT_FLAG(ep)        (*((__IO uint32_t *) ((uint32_t)&USBD->EPA_IRQ_STAT + (uint32_t)((ep)*0x28))))

/*!<Clear EPx interrupt flag */
#define USBD_CLR_EP_INT_FLAG(ep, flag)  (*((__IO uint32_t *) ((uint32_t)&USBD->EPA_IRQ_STAT + (uint32_t)((ep)*0x28))) = (flag))

/*!<Set DMA transfer length */
#define USBD_SET_DMA_LEN(len)           (USBD->DMA_CNT = len)

/*!<Set DMA transfer address */
#define USBD_SET_DMA_ADDR(addr)         (USBD->AHB_DMA_ADDR = addr)

/*!<Set DMA transfer type */
#define USBD_SET_DMA_READ(epnum)    (USBD->DMA_CTRL_STS = (USBD->DMA_CTRL_STS & ~USBD_DMA_CTRL_STS_DMA_ADDR_Msk) | USBD_DMA_CTRL_STS_DMA_RD_Msk | epnum)
#define USBD_SET_DMA_WRITE(epnum)   (USBD->DMA_CTRL_STS = (USBD->DMA_CTRL_STS & ~(USBD_DMA_CTRL_STS_DMA_ADDR_Msk | USBD_DMA_CTRL_STS_DMA_RD_Msk)) | epnum)

/*!<Enable DMA transfer */
#define USBD_ENABLE_DMA()               (USBD->DMA_CTRL_STS |= USBD_DMA_CTRL_STS_DMA_EN_Msk)

/*!<Check cable connect state */
#define USBD_IS_ATTACHED()              ((uint32_t)(USBD->PHY_CTL & USBD_PHY_CTL_VBUS_STATUS_Msk))


/*@}*/ /* end of group NUC400_USBD_EXPORTED_MACROS */

/** @addtogroup NUC400_USBD_EXPORTED_FUNCTIONS USBD Exported Functions
  @{
*/
/**
  * @brief  USBD_memcpy, Copy bytes hardware limitation
  * @param  u8Dst   Destination pointer.
  * @param  u8Src   Source pointer.
  * @param  i32Size Copy size.
  * @retval None.
  */
static __INLINE void USBD_MemCopy(uint8_t *u8Dst, uint8_t *u8Src, int32_t i32Size)
{
    while (i32Size--) *u8Dst++ = *u8Src++;
}

/**
  * @brief  USBD_ResetDMA
  * @param  None
  * @retval None.
  */
static __INLINE void USBD_ResetDMA(void)
{
    USBD->DMA_CNT = 0;
    USBD->DMA_CTRL_STS = 0x80;
    USBD->DMA_CTRL_STS = 0x00;
}
/**
  * @brief  USBD_SetEpBufAddr, Set Endpoint buffer address
  * @param  u32Ep      Endpoint Number
  * @param  u32Base    Buffer Start Address
  * @param  u32Len     Buffer length
  * @retval None.
  */
static __INLINE void USBD_SetEpBufAddr(uint32_t u32Ep, uint32_t u32Base, uint32_t u32Len)
{
    if (u32Ep == CEP) {
        USBD->CEP_START_ADDR = u32Base;
        USBD->CEP_END_ADDR = u32Base + u32Len - 1;
    } else {
        *((__IO uint32_t *) ((uint32_t)&USBD->EPA_START_ADDR + (uint32_t)(u32Ep*0x28))) = u32Base;
        *((__IO uint32_t *) ((uint32_t)&USBD->EPA_END_ADDR + (uint32_t)(u32Ep*0x28))) = u32Base + u32Len - 1;
    }
}

/**
  * @brief  USBD_ConfigEp, Config Endpoint
  * @param  u32Ep      USB endpoint
  * @param  u32EpNum   Endpoint number
  * @param  u32EpType  Endpoint type
  * @param  u32EpDir   Endpoint direction
  * @retval None.
  */
static __INLINE void USBD_ConfigEp(uint32_t u32Ep, uint32_t u32EpNum, uint32_t u32EpType, uint32_t u32EpDir)
{
    if (u32EpType == USB_EP_CFG_TYPE_BULK)
        *((__IO uint32_t *)((uint32_t)&USBD->EPA_RSP_SC+(uint32_t)(u32Ep*0x28)))=(USB_EP_RSP_SC_BUF_FLUSH|USB_EP_RSP_SC_MODE_AUTO);
    else if (u32EpType == USB_EP_CFG_TYPE_INT)
        *((__IO uint32_t *)((uint32_t)&USBD->EPA_RSP_SC+(uint32_t)(u32Ep*0x28)))=(USB_EP_RSP_SC_BUF_FLUSH|USB_EP_RSP_SC_MODE_MANUAL);
    else if (u32EpType == USB_EP_CFG_TYPE_ISO)
        *((__IO uint32_t *)((uint32_t)&USBD->EPA_RSP_SC+(uint32_t)(u32Ep*0x28)))=(USB_EP_RSP_SC_BUF_FLUSH|USB_EP_RSP_SC_MODE_FLY);

    *((__IO uint32_t *)((uint32_t)&USBD->EPA_CFG+(uint32_t)(u32Ep*0x28)))=(u32EpType|u32EpDir|USB_EP_CFG_VALID|(u32EpNum << 4));
}

/**
 * @brief       Set USB endpoint stall state
 *
 * @param[in]   u32Ep         USB endpoint
 * @return      None
 *
 * @details     Set USB endpoint stall state, endpoint will return STALL token.
 */
static __INLINE void USBD_SetStall(uint32_t u32Ep)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;

    if (u32Ep == 0)
        USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_STALL);

    u32CfgAddr = (uint32_t)&USBD->EPA_RSP_SC + (uint32_t)(u32Ep * 0x28);
    u32Cfg = *((__IO uint32_t *) (u32CfgAddr)) & 0xf7;  /* avoid clear TOGGLE bit */
    *((__IO uint32_t *) (u32CfgAddr)) = (u32Cfg | USB_EP_RSP_SC_HALT);
}

/**
 * @brief       Clear USB endpoint stall state
 *
 * @param[in]   u32Ep         USB endpoint
 * @return      None
 *
 * @details     Clear USB endpoint stall state, endpoint will return ACK/NAK token.
 */
static __INLINE void USBD_ClearStall(uint32_t u32Ep)
{
    uint32_t u32CfgAddr;

    u32CfgAddr = (uint32_t)&USBD->EPA_RSP_SC + (uint32_t)(u32Ep * 0x28);
    *((__IO uint32_t *) (u32CfgAddr)) = USB_EP_RSP_SC_TOGGLE;
}

/**
 * @brief       Get USB endpoint stall state
 *
 * @param[in]   u32Ep         USB endpoint
 * @retval      0: USB endpoint is not stalled.
 * @retval      non-0: USB endpoint is stalled.
 *
 * @details     Get USB endpoint stall state.
 */
static __INLINE uint32_t USBD_GetStall(uint32_t u32Ep)
{
    uint32_t u32CfgAddr;

    u32CfgAddr = (uint32_t)&USBD->EPA_RSP_SC + (uint32_t)(u32Ep * 0x28);

    return ((*((__IO uint32_t *) (u32CfgAddr))) & USB_EP_RSP_SC_HALT);
}


/*-------------------------------------------------------------------------------------------*/
void USBD_Open(S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
void USBD_Start(void);
void USBD_ProcessSetupPacket(void);
void USBD_StandardRequest(void);
void USBD_UpdateDeviceState(void);
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlIn(void);
void USBD_SwReset(void);



/*@}*/ /* end of group NUC400_USBD_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_USBD_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__USBD_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
