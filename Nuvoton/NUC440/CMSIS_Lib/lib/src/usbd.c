/**************************************************************************//**
 * @file     usbd.c
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 13/12/04 9:40a $
 * @brief    NUC400 series USBD driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "usbd.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_USBD_Driver USBD Driver
  @{
*/


/** @addtogroup NUC400_USBD_EXPORTED_FUNCTIONS USBD Exported Functions
  @{
*/
/*--------------------------------------------------------------------------*/
/*!< Global variables for Control Pipe */
S_USBD_CMD_T gUsbCmd;
S_USBD_INFO_T *g_usbd_sInfo;

CLASS_REQ g_usbd_pfnClassRequest = NULL;
SET_INTERFACE_REQ g_usbd_pfnSetInterface = NULL;

static uint8_t *g_usbd_CtrlInPointer = 0;
static uint32_t g_usbd_UsbConfig = 0;
static uint32_t g_usbd_UsbAltInterface = 0;
static uint32_t g_usbd_CtrlMaxPktSize = 64;

uint32_t g_usbd_UsbAddr = 0;
uint32_t g_usbd_CtrlInSize = 0;
uint32_t g_usbd_ShortPacket = 0;
uint32_t volatile g_usbd_DmaDone = 0;

/**
 * @brief       USBD Initial
 *
 * @param[in]   param               Descriptor
 * @param[in]   pfnClassReq         Class Request Callback Function
 * @param[in]   pfnSetInterface     SetInterface Request Callback Function
 *
 * @return      None
 *
 * @details     This function is used to initial USBD.
 */
void USBD_Open(S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface)
{
    g_usbd_sInfo = param;
    g_usbd_pfnClassRequest = pfnClassReq;
    g_usbd_pfnSetInterface = pfnSetInterface;

    /* get EP0 maximum packet size */
    g_usbd_CtrlMaxPktSize = g_usbd_sInfo->gu8DevDesc[7];

    /* Initial USB engine */
    /* Enable PHY */
    USBD_ENABLE_PHY();
    /* wait PHY clock ready */
    while (1) {
        USBD->EPA_MPS = 0x20;
        if (USBD->EPA_MPS == 0x20)
            break;
    }
    /* Force SE0, and then clear it to connect*/
    USBD_SET_SE0();
}

/**
 * @brief       USBD Start
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to start transfer
 */
void USBD_Start(void)
{
    USBD_CLR_SE0();
}

/**
 * @brief       Process Setup Packet
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to process Setup packet.
 */
void USBD_ProcessSetupPacket(void)
{
    // Setup packet process
    gUsbCmd.bmRequestType = (uint8_t)(USBD->SETUP1_0 & 0xff);
    gUsbCmd.bRequest = (int8_t)(USBD->SETUP1_0 >> 8) & 0xff;
    gUsbCmd.wValue = (uint16_t)USBD->SETUP3_2;
    gUsbCmd.wIndex = (uint16_t)USBD->SETUP5_4;
    gUsbCmd.wLength = (uint16_t)USBD->SETUP7_6;

    /* USB device request in setup packet: offset 0, D[6..5]: 0=Standard, 1=Class, 2=Vendor, 3=Reserved */
    switch (gUsbCmd.bmRequestType & 0x60) {
    case REQ_STANDARD: { // Standard
        USBD_StandardRequest();
        break;
    }
    case REQ_CLASS: { // Class
        if (g_usbd_pfnClassRequest != NULL) {
            g_usbd_pfnClassRequest();
        }
        break;
    }
    case REQ_VENDOR: { // Vendor
        break;
    }
    default: { // reserved
        /* Setup error, stall the device */
        USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
        break;
    }
    }
}

/**
 * @brief       Get Descriptor request
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to process GetDescriptor request.
 */
void USBD_GetDescriptor(void)
{
    uint32_t u32Len;

    u32Len = gUsbCmd.wLength;

    switch ((gUsbCmd.wValue & 0xff00) >> 8) {
    // Get Device Descriptor
    case DESC_DEVICE: {
        u32Len = Minimum(u32Len, LEN_DEVICE);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8DevDesc, u32Len);
        break;
    }
    // Get Configuration Descriptor
    case DESC_CONFIG: {
        uint32_t u32TotalLen;

        u32TotalLen = g_usbd_sInfo->gu8ConfigDesc[3];
        u32TotalLen = g_usbd_sInfo->gu8ConfigDesc[2] + (u32TotalLen << 8);

        u32Len = Minimum(u32Len, u32TotalLen);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8ConfigDesc, u32Len);
        break;
    }
    // Get Qualifier Descriptor
    case DESC_QUALIFIER: {
        u32Len = Minimum(u32Len, LEN_QUALIFIER);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8QualDesc, u32Len);
        break;
    }
    // Get Other Speed Descriptor - Full speed
    case DESC_OTHERSPEED: {
        uint32_t u32TotalLen;

        u32TotalLen = g_usbd_sInfo->gu8OtherConfigDesc[3];
        u32TotalLen = g_usbd_sInfo->gu8OtherConfigDesc[2] + (u32TotalLen << 8);

        u32Len = Minimum(u32Len, u32TotalLen);
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8OtherConfigDesc, u32Len);
        break;
    }
    // Get HID Descriptor
    case DESC_HID: {
        u32Len = Minimum(u32Len, LEN_HID);
        USBD_PrepareCtrlIn((uint8_t *)&g_usbd_sInfo->gu8ConfigDesc[LEN_CONFIG+LEN_INTERFACE], u32Len);
        break;
    }
    // Get Report Descriptor
    case DESC_HID_RPT: {
        USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8HidReportDesc, u32Len);
        break;
    }
    // Get String Descriptor
    case DESC_STRING: {
        // Get Language
        if ((gUsbCmd.wValue & 0xff) == 0) {
            u32Len = Minimum(u32Len, 4);
            USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrLangDesc, u32Len);
        } else {
            // Get String Descriptor
            switch (gUsbCmd.wValue & 0xff) {
            case 1: {
                u32Len = Minimum(u32Len, g_usbd_sInfo->gu8StrVendorDesc[0]);
                USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrVendorDesc, u32Len);
                break;
            }
            case 2: {
                u32Len = Minimum(u32Len, g_usbd_sInfo->gu8StrProductDesc[0]);
                USBD_PrepareCtrlIn((uint8_t *)g_usbd_sInfo->gu8StrProductDesc, u32Len);
                break;
            }
            default:
                // Not support. Reply STALL.
                USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
                break;
            }
        }
        break;
    }
    default:
        // Not support. Reply STALL.
        USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
        break;
    }
}


/**
 * @brief       Process USB standard request
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to process USB Standard Request.
 */
void USBD_StandardRequest(void)
{
    /* clear global variables for new request */
    g_usbd_CtrlInPointer = 0;
    g_usbd_CtrlInSize = 0;

    if (gUsbCmd.bmRequestType & 0x80) { /* request data transfer direction */
        // Device to host
        switch (gUsbCmd.bRequest) {
        case GET_CONFIGURATION: {
            // Return current configuration setting
            USBD_PrepareCtrlIn((uint8_t *)&g_usbd_UsbConfig, 1);

            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_IN_TK_Msk);
            break;
        }
        case GET_DESCRIPTOR: {
            USBD_GetDescriptor();
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_IN_TK_Msk);
            break;
        }
        case GET_INTERFACE: {
            // Return current interface setting
            USBD_PrepareCtrlIn((uint8_t *)&g_usbd_UsbAltInterface, 1);

            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_IN_TK_Msk);
            break;
        }
        case GET_STATUS: {
            uint8_t buf[2];
            // Device
            if (gUsbCmd.bmRequestType == 0x80) {
                if (g_usbd_sInfo->gu8ConfigDesc[7] & 0x40)
                    buf[0] = 1; // Self-Powered
                else
                    buf[0] = 0; // bus-Powered
            }
            // Interface
            else if (gUsbCmd.bmRequestType == 0x81)
                buf[0] = 0;
            // Endpoint
            else if (gUsbCmd.bmRequestType == 0x82) {
                uint8_t ep = gUsbCmd.wIndex & 0xF;
                buf[0] = USBD_GetStall(ep)? 1 : 0;
            }

            buf[1] = 0;
            USBD_PrepareCtrlIn(buf, 2);
            break;
        }
        default: {
            /* Setup error, stall the device */
            USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
            break;
        }
        }
    } else {
        // Host to device
        switch (gUsbCmd.bRequest) {
        case CLEAR_FEATURE: {
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        case SET_ADDRESS: {
            g_usbd_UsbAddr = (uint8_t)gUsbCmd.wValue;

            // DATA IN for end of setup
            /* Status Stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        case SET_CONFIGURATION: {
            g_usbd_UsbConfig = (uint8_t)gUsbCmd.wValue;

            // DATA IN for end of setup
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        case SET_FEATURE: {
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        case SET_INTERFACE: {
            g_usbd_UsbAltInterface = (uint8_t)gUsbCmd.wValue;
            if (g_usbd_pfnSetInterface != NULL)
                g_usbd_pfnSetInterface();
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        default: {
            /* Setup error, stall the device */
            USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
            break;
        }
        }
    }
}

/**
 * @brief       Update Device State
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to update Device state when Setup packet complete
 */
void USBD_UpdateDeviceState(void)
{
    switch (gUsbCmd.bRequest) {
    case SET_ADDRESS: {
        USBD_SET_ADDR(g_usbd_UsbAddr);
        break;
    }
    case SET_FEATURE: {
        if(gUsbCmd.wValue == FEATURE_ENDPOINT_HALT)
            USBD_SetStall(gUsbCmd.wIndex & 0xF);
        break;
    }
    case CLEAR_FEATURE: {
        if(gUsbCmd.wValue == FEATURE_ENDPOINT_HALT)
            USBD_ClearStall(gUsbCmd.wIndex & 0xF);
        break;
    }
    default:
        ;
    }
}


/**
 * @brief       Prepare Control IN transaction
 *
 * @param[in]   pu8Buf      Control IN data pointer
 * @param[in]   u32Size     IN transfer size
 *
 * @return      None
 *
 * @details     This function is used to prepare Control IN transfer
 */
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size)
{
    g_usbd_CtrlInPointer = pu8Buf;
    g_usbd_CtrlInSize = u32Size;
}



/**
 * @brief       Start Control IN transfer
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to start Control IN
 */
void USBD_CtrlIn(void)
{
    int volatile i;
    uint32_t volatile count;

    // Process remained data
    if(g_usbd_CtrlInSize > g_usbd_CtrlMaxPktSize) {
        // Data size > MXPLD
        for (i=0; i<(g_usbd_CtrlMaxPktSize >> 2); i++, g_usbd_CtrlInPointer+=4)
            USBD->CEP_DATA_BUF = *(uint32_t *)g_usbd_CtrlInPointer;
        USBD_START_CEP_IN(g_usbd_CtrlMaxPktSize);
        g_usbd_CtrlInSize -= g_usbd_CtrlMaxPktSize;
    } else {
        // Data size <= MXPLD
        for (i=0; i<(g_usbd_CtrlInSize >> 2); i++, g_usbd_CtrlInPointer+=4)
            USBD->CEP_DATA_BUF = *(uint32_t *)g_usbd_CtrlInPointer;

        count = g_usbd_CtrlInSize % 4;
        for (i=0; i<count; i++)
            USBD->CEP_DATA_BUF_BYTE = *(uint8_t *)(g_usbd_CtrlInPointer + i);

        USBD_START_CEP_IN(g_usbd_CtrlInSize);
        g_usbd_CtrlInPointer = 0;
        g_usbd_CtrlInSize = 0;
    }
}

/**
 * @brief       Clear all software flags
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This function is used to clear all software control flag
 */
void USBD_SwReset(void)
{
    // Reset all variables for protocol
    g_usbd_UsbAddr = 0;
    g_usbd_DmaDone = 0;
    g_usbd_ShortPacket = 0;

    // Reset USB device address
    USBD_SET_ADDR(0);
}


/*@}*/ /* end of group NUC400_GPIO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_GPIO_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
