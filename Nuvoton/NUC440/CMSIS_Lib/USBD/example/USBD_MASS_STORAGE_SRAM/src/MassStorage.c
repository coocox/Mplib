/******************************************************************************
 * @file     MassStorage.c
 * @brief    NUC400 series USBD driver Sample file
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 13/11/29 2:58p $
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include <string.h>
#include "NUC400Series.h"
#include "massstorage.h"
#include "USBD.h"
/*--------------------------------------------------------------------------*/
/* Global variables for Control Pipe */
int32_t g_TotalSectors = 0;

/* USB flow control variables */
uint8_t g_u8BulkState = BULK_NORMAL;
uint8_t g_u8Prevent = 0;
uint8_t g_u8MscStart = 0;
//uint8_t g_u8bulk = 0;
//uint8_t g_u8CBWcmd = 0;
uint8_t g_au8SenseKey[4];

uint32_t g_u32MSCMaxLun = 0;
uint32_t g_u32LbaAddress;
uint32_t g_u32MassBase, g_u32StorageBase;

/* CBW/CSW variables */
struct CBW g_sCBW;
struct CSW g_sCSW;


/*--------------------------------------------------------------------------*/
uint8_t g_au8InquiryID[36] = {
    0x00,                   /* Peripheral Device Type */
    0x80,                   /* RMB */
    0x00,                   /* ISO/ECMA, ANSI Version */
    0x00,                   /* Response Data Format */
    0x1F, 0x00, 0x00, 0x00, /* Additional Length */

    /* Vendor Identification */
    'N', 'u', 'v', 'o', 't', 'o', 'n', ' ',

    /* Product Identification */
    'U', 'S', 'B', ' ', 'M', 'a', 's', 's', ' ', 'S', 't', 'o', 'r', 'a', 'g', 'e',

    /* Product Revision */
    '1', '.', '0', '0'
};

// code = 5Ah, Mode Sense
static uint8_t g_au8ModePage_01[12] = {
    0x01, 0x0A, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00
};

static uint8_t g_au8ModePage_05[32] = {
    0x05, 0x1E, 0x13, 0x88, 0x08, 0x20, 0x02, 0x00,
    0x01, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x05, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x68, 0x00, 0x00
};

static uint8_t g_au8ModePage_1B[12] = {
    0x1B, 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

static uint8_t g_au8ModePage_1C[8] = {
    0x1C, 0x06, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00
};

void USBD_IRQHandler(void)
{
    __IO uint32_t IrqStL, IrqSt;

    IrqStL = USBD->IRQ_STAT_L & USBD->IRQ_ENB_L;    /* get interrupt status */

    if (!IrqStL)    return;

    /* USB interrupt */
    if (IrqStL & USBD_IRQ_STAT_L_USB_Msk) {
        IrqSt = USBD->IRQ_STAT & USBD->IRQ_ENB;

        if (IrqSt & USBD_IRQ_STAT_SOF_Msk)
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_SOF_Msk);

        if (IrqSt & USBD_IRQ_STAT_RST_Msk) {
            USBD_SwReset();
            g_u8BulkState = BULK_NORMAL;

            USBD_ResetDMA();

            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk);
            USBD_SET_ADDR(0);
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_SUS_Msk|USBD_IRQ_ENB_RUM_Msk|USBD_IRQ_ENB_FLODET_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_RST_Msk);
            USBD_CLR_CEP_INT_FLAG(0x1ffc);
        }

        if (IrqSt & USBD_IRQ_STAT_RUM_Msk) {
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_SUS_Msk|USBD_IRQ_ENB_FLODET_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_RUM_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_SUS_Msk) {
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk | USBD_IRQ_ENB_RUM_Msk|USBD_IRQ_ENB_FLODET_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_SUS_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_HISPD_Msk) {
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_HISPD_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_DMACOM_Msk) {
            g_usbd_DmaDone = 1;
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_DMACOM_Msk);

            if (!(USBD->DMA_CTRL_STS & USBD_DMA_CTRL_STS_DMA_RD_Msk)) {
                if (g_u8BulkState == BULK_OUT)
                    g_u8BulkState = BULK_CBW;
                UBSD_ENABLE_EP_INT(EPB, USBD_EP_IRQ_ENB_DATA_RxED_Msk);
            }

            if (USBD->DMA_CTRL_STS & USBD_DMA_CTRL_STS_DMA_RD_Msk) {
                if (g_usbd_ShortPacket == 1) {
                    USBD->EPA_RSP_SC = USB_EP_RSP_SC_PK_END;    // packet end
                    g_usbd_ShortPacket = 0;
                }
            }
        }

        if (IrqSt & USBD_IRQ_STAT_TCLKOK_Msk)
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_TCLKOK_Msk);

        if (IrqSt & USBD_IRQ_STAT_FLODET_Msk) {
            if (USBD_IS_ATTACHED()) {
                /* USB Plug In */
                USBD_ENABLE_USB();
            } else {
                /* USB Un-plug */
                USBD_DISABLE_USB();
            }
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_FLODET_Msk);
        }
    }

    if (IrqStL & USBD_IRQ_STAT_L_CEP_Msk) {
        IrqSt = USBD->CEP_IRQ_STAT & USBD->CEP_IRQ_ENB;

        if (IrqSt & USBD_CEP_IRQ_STAT_SETUP_TK_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_SETUP_TK_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_SETUP_PK_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_SETUP_PK_Msk);
            USBD_ProcessSetupPacket();
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_OUT_TK_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_OUT_TK_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_IN_TK_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
            if (!(IrqSt & USBD_CEP_IRQ_STAT_STACOM_Msk)) {
                USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_DATA_TxED_Msk);
                UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_DATA_TxED_Msk);
                USBD_CtrlIn();
            } else {
                USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_DATA_TxED_Msk);
                UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_DATA_TxED_Msk|USBD_CEP_IRQ_ENB_STACOM_Msk);
            }
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_PING_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_PING_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_DATA_TxED_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            if (g_usbd_CtrlInSize) {
                USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
                UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_IN_TK_Msk);
            } else {
                USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
                UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk|USBD_CEP_IRQ_ENB_STACOM_Msk);
            }
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_DATA_TxED_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_DATA_RxED_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_DATA_RxED_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk|USBD_CEP_IRQ_ENB_STACOM_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_NAK_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_NAK_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_STALL_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STALL_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_ERR_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_ERR_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_STACOM_Msk) {
            USBD_UpdateDeviceState();
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_FULL_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_FULL_Msk);
            return;
        }

        if (IrqSt & USBD_CEP_IRQ_STAT_EMPTY_Msk) {
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_EMPTY_Msk);
            return;
        }
    }

    /* bulk in */
    if (IrqStL & USBD_IRQ_STAT_L_EPA_Msk) {
        IrqSt = USBD->EPA_IRQ_STAT & USBD->EPA_IRQ_ENB;

        UBSD_ENABLE_EP_INT(EPA, 0);
        USBD_CLR_EP_INT_FLAG(EPA, IrqSt);
    }
    /* bulk out */
    if (IrqStL & USBD_IRQ_STAT_L_EPB_Msk) {
        IrqSt = USBD->EPB_IRQ_STAT & USBD->EPB_IRQ_ENB;
        UBSD_ENABLE_EP_INT(EPB, 0);
        USBD_CLR_EP_INT_FLAG(EPB, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPC_Msk) {
        IrqSt = USBD->EPC_IRQ_STAT & USBD->EPC_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPC, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPD_Msk) {
        IrqSt = USBD->EPD_IRQ_STAT & USBD->EPD_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPD, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPE_Msk) {
        IrqSt = USBD->EPE_IRQ_STAT & USBD->EPE_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPE, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPF_Msk) {
        IrqSt = USBD->EPF_IRQ_STAT & USBD->EPF_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPF, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPG_Msk) {
        IrqSt = USBD->EPG_IRQ_STAT & USBD->EPG_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPG, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPH_Msk) {
        IrqSt = USBD->EPH_IRQ_STAT & USBD->EPH_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPH, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPI_Msk) {
        IrqSt = USBD->EPI_IRQ_STAT & USBD->EPI_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPI, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPJ_Msk) {
        IrqSt = USBD->EPJ_IRQ_STAT & USBD->EPJ_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPJ, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPK_Msk) {
        IrqSt = USBD->EPK_IRQ_STAT & USBD->EPK_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPK, IrqSt);
    }

    if (IrqStL & USBD_IRQ_STAT_L_EPL_Msk) {
        IrqSt = USBD->EPL_IRQ_STAT & USBD->EPL_IRQ_ENB;
        USBD_CLR_EP_INT_FLAG(EPL, IrqSt);
    }
}

void MSC_Init(void)
{
    /* Configure USB controller */
    /* Enable USB BUS, CEP and EPA , EPB global interrupt */
    UBSD_ENABLE_USB_INT(USBD_IRQ_ENB_L_USB_Msk|USBD_IRQ_ENB_L_CEP_Msk|USBD_IRQ_ENB_L_EPA_Msk|USBD_IRQ_ENB_L_EPB_Msk);
    /* Enable BUS interrupt */
    UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_DMACOM_Msk|USBD_IRQ_ENB_RUM_Msk|USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_FLODET_Msk);
    /* Reset Address to 0 */
    USBD_SET_ADDR(0);

    /*****************************************************/
    /* Control endpoint */
    USBD_SetEpBufAddr(CEP, CEP_BUF_BASE, CEP_BUF_LEN);
    UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk|USBD_CEP_IRQ_ENB_STACOM_Msk);

    /*****************************************************/
    /* EPA ==> Bulk IN endpoint, address 1 */
    USBD_SetEpBufAddr(EPA, EPA_BUF_BASE, EPA_BUF_LEN);
    UBSD_SET_MAX_PAYLOAD(EPA, EPA_MAX_PKT_SIZE);
    USBD_ConfigEp(EPA, BULK_IN_EP_NUM, USB_EP_CFG_TYPE_BULK, USB_EP_CFG_DIR_IN);
    /* Buffer range for EPA */
    USBD_SetEpBufAddr(EPA, EPA_BUF_BASE, EPA_BUF_LEN);

    /* EPB ==> Bulk OUT endpoint, address 2 */
    USBD_SetEpBufAddr(EPB, EPB_BUF_BASE, EPB_BUF_LEN);
    UBSD_SET_MAX_PAYLOAD(EPB, EPB_MAX_PKT_SIZE);
    USBD_ConfigEp(EPB, BULK_OUT_EP_NUM, USB_EP_CFG_TYPE_BULK, USB_EP_CFG_DIR_OUT);
    /* Buffer range for EPB */
    USBD_SetEpBufAddr(EPB, EPB_BUF_BASE, EPB_BUF_LEN);
    UBSD_ENABLE_EP_INT(EPB, USBD_EP_IRQ_ENB_DATA_RxED_Msk);

    g_sCSW.dCSWSignature = CSW_SIGNATURE;
    g_TotalSectors = 60;
    g_u32MassBase = 0x20007000;
    g_u32StorageBase = 0x20008000;
}

void MSC_ClassRequest(void)
{
    g_u8MscStart = 1;
    if (gUsbCmd.bmRequestType & 0x80) { /* request data transfer direction */
        // Device to host
        switch (gUsbCmd.bRequest) {
        case GET_MAX_LUN: {
            // Return current configuration setting
            USBD_PrepareCtrlIn((uint8_t *)&g_u32MSCMaxLun, 1);
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_IN_TK_Msk);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_IN_TK_Msk);
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
        case BULK_ONLY_MASS_STORAGE_RESET: {
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        default: {
            // Stall
            /* Setup error, stall the device */
            USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
            break;
        }
        }
    }
}


void MSC_RequestSense(void)
{
    memset((uint8_t *)(g_u32MassBase), 0, 18);
    if (g_u8Prevent) {
        g_u8Prevent = 0;
        *(uint8_t *)(g_u32MassBase) = 0x70;
    } else
        *(uint8_t *)(g_u32MassBase) = 0xf0;

    *(uint8_t *)(g_u32MassBase + 2) = g_au8SenseKey[0];
    *(uint8_t *)(g_u32MassBase + 7) = 0x0a;
    *(uint8_t *)(g_u32MassBase + 12) = g_au8SenseKey[1];
    *(uint8_t *)(g_u32MassBase + 13) = g_au8SenseKey[2];
    MSC_BulkIn(g_u32MassBase, g_sCBW.dCBWDataTransferLength);

    g_au8SenseKey[0] = 0;
    g_au8SenseKey[1] = 0;
    g_au8SenseKey[2] = 0;
}

void MSC_ReadFormatCapacity(void)
{
    memset((uint8_t *)g_u32MassBase, 0, 36);

    *((uint8_t *)(g_u32MassBase+3)) = 0x10;
    *((uint8_t *)(g_u32MassBase+4)) = *((uint8_t *)&g_TotalSectors+3);
    *((uint8_t *)(g_u32MassBase+5)) = *((uint8_t *)&g_TotalSectors+2);
    *((uint8_t *)(g_u32MassBase+6)) = *((uint8_t *)&g_TotalSectors+1);
    *((uint8_t *)(g_u32MassBase+7)) = *((uint8_t *)&g_TotalSectors+0);
    *((uint8_t *)(g_u32MassBase+8)) = 0x02;
    *((uint8_t *)(g_u32MassBase+10)) = 0x02;
    *((uint8_t *)(g_u32MassBase+12)) = *((uint8_t *)&g_TotalSectors+3);
    *((uint8_t *)(g_u32MassBase+13)) = *((uint8_t *)&g_TotalSectors+2);
    *((uint8_t *)(g_u32MassBase+14)) = *((uint8_t *)&g_TotalSectors+1);
    *((uint8_t *)(g_u32MassBase+15)) = *((uint8_t *)&g_TotalSectors+0);
    *((uint8_t *)(g_u32MassBase+18)) = 0x02;

    MSC_BulkIn(g_u32MassBase, g_sCBW.dCBWDataTransferLength);
}

void MSC_ReadCapacity(void)
{
    uint32_t tmp;

    memset((uint8_t *)g_u32MassBase, 0, 36);

    tmp = g_TotalSectors - 1;
    *((uint8_t *)(g_u32MassBase+0)) = *((uint8_t *)&tmp+3);
    *((uint8_t *)(g_u32MassBase+1)) = *((uint8_t *)&tmp+2);
    *((uint8_t *)(g_u32MassBase+2)) = *((uint8_t *)&tmp+1);
    *((uint8_t *)(g_u32MassBase+3)) = *((uint8_t *)&tmp+0);
    *((uint8_t *)(g_u32MassBase+6)) = 0x02;

    MSC_BulkIn(g_u32MassBase, g_sCBW.dCBWDataTransferLength);
}

void MSC_ModeSense10(void)
{
    uint8_t i,j;
    uint8_t NumHead,NumSector;
    uint16_t NumCyl=0;

    /* Clear the command buffer */
    *((uint32_t *)g_u32MassBase  ) = 0;
    *((uint32_t *)g_u32MassBase + 1) = 0;

    switch (g_sCBW.au8Data[0]) {
    case 0x01:
        *((uint8_t *)g_u32MassBase) = 19;
        i = 8;
        for (j = 0; j<12; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_01[j];
        break;

    case 0x05:
        *((uint8_t *)g_u32MassBase) = 39;
        i = 8;
        for (j = 0; j<32; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_05[j];

        NumHead = 2;
        NumSector = 64;
        NumCyl = g_TotalSectors / 128;

        *((uint8_t *)(g_u32MassBase+12)) = NumHead;
        *((uint8_t *)(g_u32MassBase+13)) = NumSector;
        *((uint8_t *)(g_u32MassBase+16)) = (uint8_t)(NumCyl >> 8);
        *((uint8_t *)(g_u32MassBase+17)) = (uint8_t)(NumCyl & 0x00ff);
        break;

    case 0x1B:
        *((uint8_t *)g_u32MassBase) = 19;
        i = 8;
        for (j = 0; j<12; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_1B[j];
        break;

    case 0x1C:
        *((uint8_t *)g_u32MassBase) = 15;
        i = 8;
        for (j = 0; j<8; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_1C[j];
        break;

    case 0x3F:
        *((uint8_t *)g_u32MassBase) = 0x47;
        i = 8;
        for (j = 0; j<12; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_01[j];
        for (j = 0; j<32; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_05[j];
        for (j = 0; j<12; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_1B[j];
        for (j = 0; j<8; j++, i++)
            *((uint8_t *)(g_u32MassBase+i)) = g_au8ModePage_1C[j];

        NumHead = 2;
        NumSector = 64;
        NumCyl = g_TotalSectors / 128;

        *((uint8_t *)(g_u32MassBase+24)) = NumHead;
        *((uint8_t *)(g_u32MassBase+25)) = NumSector;
        *((uint8_t *)(g_u32MassBase+28)) = (uint8_t)(NumCyl >> 8);
        *((uint8_t *)(g_u32MassBase+29)) = (uint8_t)(NumCyl & 0x00ff);
        break;

    default:
        g_au8SenseKey[0] = 0x05;
        g_au8SenseKey[1] = 0x24;
        g_au8SenseKey[2] = 0x00;
    }
    MSC_BulkIn(g_u32MassBase, g_sCBW.dCBWDataTransferLength);
}

void MSC_BulkOut(uint32_t u32Addr, uint32_t u32Len)
{
    uint32_t u32Loop;
    uint32_t i;

    /* bulk out, dma write, epnum = 2 */
    USBD_SET_DMA_WRITE(BULK_OUT_EP_NUM);
    g_usbd_ShortPacket = 0;

    u32Loop = u32Len / USBD_MAX_DMA_LEN;
    for (i=0; i<u32Loop; i++) {
        MSC_ActiveDMA(u32Addr+i*USBD_MAX_DMA_LEN, USBD_MAX_DMA_LEN);
    }

    u32Loop = u32Len % USBD_MAX_DMA_LEN;
    if (u32Loop) {
        MSC_ActiveDMA(u32Addr+i*USBD_MAX_DMA_LEN, u32Loop);
    }
}

void MSC_BulkIn(uint32_t u32Addr, uint32_t u32Len)
{
    uint32_t u32Loop;
    uint32_t i, addr, count;

    /* bulk in, dma read, epnum = 1 */
    USBD_SET_DMA_READ(BULK_IN_EP_NUM);

    u32Loop = u32Len / USBD_MAX_DMA_LEN;
    for (i=0; i<u32Loop; i++) {
        UBSD_ENABLE_EP_INT(EPA, USBD_EP_IRQ_ENB_DATA_TxED_Msk);
        g_usbd_ShortPacket = 0;
        while(1) {
            if (USBD_GET_EP_INT_FLAG(EPA) & USBD_EP_IRQ_STAT_EMPTY_Msk) {
                MSC_ActiveDMA(u32Addr+i*USBD_MAX_DMA_LEN, USBD_MAX_DMA_LEN);
                break;
            }
        }
    }

    addr = u32Addr + i * USBD_MAX_DMA_LEN;
    u32Loop = u32Len % USBD_MAX_DMA_LEN;
    if (u32Loop) {
        count = u32Loop / EPA_MAX_PKT_SIZE;
        if (count) {
            UBSD_ENABLE_EP_INT(EPA, USBD_EP_IRQ_ENB_DATA_TxED_Msk);
            g_usbd_ShortPacket = 0;
            while(1) {
                if (USBD_GET_EP_INT_FLAG(EPA) & USBD_EP_IRQ_STAT_EMPTY_Msk) {
                    MSC_ActiveDMA(addr, count * EPA_MAX_PKT_SIZE);
                    break;
                }
            }
            addr += (count * EPA_MAX_PKT_SIZE);
        }
        count = u32Loop % EPA_MAX_PKT_SIZE;
        if (count) {
            UBSD_ENABLE_EP_INT(EPA, USBD_EP_IRQ_ENB_DATA_TxED_Msk);
            g_usbd_ShortPacket = 1;
            while(1) {
                if (USBD_GET_EP_INT_FLAG(EPA) & USBD_EP_IRQ_STAT_EMPTY_Msk) {
                    MSC_ActiveDMA(addr, count);
                    break;
                }
            }
        }
    }
}


void MSC_ReceiveCBW(uint32_t u32Buf)
{
    /* bulk out, dma write, epnum = 2 */
    USBD_SET_DMA_WRITE(BULK_OUT_EP_NUM);

    /* Enable BUS interrupt */
    UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_DMACOM_Msk|USBD_IRQ_ENB_SUS_Msk|USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_FLODET_Msk);

    USBD_SET_DMA_ADDR(u32Buf);
    USBD_SET_DMA_LEN(31);

    g_usbd_DmaDone = 0;
    USBD_ENABLE_DMA();

    while(1) {
        if (g_usbd_DmaDone == 1)
            break;

        if (!USBD_IS_ATTACHED())
            break;
    }
}

void MSC_ProcessCmd(void)
{
    uint32_t i;

    if (g_u8BulkState == BULK_NORMAL) {
        g_u8BulkState = BULK_OUT;
        MSC_ReceiveCBW(g_u32MassBase);
    }

    if (g_u8BulkState == BULK_CBW) {
        /* Check Signature of CBW */
        if ((*(uint32_t *)(g_u32MassBase) != CBW_SIGNATURE)) {
            g_u8BulkState = BULK_NORMAL;
            return;
        }

        /* Get the CBW */
        for (i = 0; i < 31; i++)
            *((uint8_t *) (&g_sCBW.dCBWSignature) + i) = *(uint8_t *)(g_u32MassBase + i);

        /* Prepare to echo the tag from CBW to CSW */
        g_sCSW.dCSWTag = g_sCBW.dCBWTag;

        /* Parse Op-Code of CBW */
        switch (g_sCBW.u8OPCode) {
        case UFI_READ_10: {
            /* Get LBA address */
            g_u32LbaAddress = get_be32(&g_sCBW.au8Data[0]) * USBD_SECTOR_SIZE;

            //MSC_ReadMedia(g_u32LbaAddress, g_sCBW.dCBWDataTransferLength, (uint8_t *)g_u32StorageBase);

            MSC_BulkIn(g_u32StorageBase+g_u32LbaAddress, g_sCBW.dCBWDataTransferLength);
            MSC_AckCmd(0);
            break;
        }
        case UFI_WRITE_10: {
            g_u32LbaAddress = get_be32(&g_sCBW.au8Data[0]) * USBD_SECTOR_SIZE;
            MSC_BulkOut(g_u32StorageBase+g_u32LbaAddress, g_sCBW.dCBWDataTransferLength);
            MSC_AckCmd(0);
            break;
        }
        case UFI_PREVENT_ALLOW_MEDIUM_REMOVAL: {
            if (g_sCBW.au8Data[2] & 0x01) {
                g_au8SenseKey[0] = 0x05;  //INVALID COMMAND
                g_au8SenseKey[1] = 0x24;
                g_au8SenseKey[2] = 0;
                g_u8Prevent = 1;
            } else
                g_u8Prevent = 0;
            MSC_AckCmd(0);
            break;
        }
        case UFI_VERIFY_10:
        case UFI_START_STOP:
        case UFI_TEST_UNIT_READY: {
            MSC_AckCmd(0);
            break;
        }
        case UFI_REQUEST_SENSE: {
            MSC_RequestSense();
            MSC_AckCmd(0);
            break;
        }
        case UFI_READ_FORMAT_CAPACITY: {
            MSC_ReadFormatCapacity();
            MSC_AckCmd(0);
            break;
        }
        case UFI_READ_CAPACITY: {
            MSC_ReadCapacity();
            MSC_AckCmd(0);
            break;
        }
        case UFI_MODE_SELECT_10: {
            MSC_BulkOut(g_u32StorageBase, g_sCBW.dCBWDataTransferLength);
            MSC_AckCmd(0);
            break;
        }
        case UFI_MODE_SENSE_10: {
            MSC_ModeSense10();
            MSC_AckCmd(0);
            break;
        }
        case UFI_INQUIRY: {
            /* Bulk IN buffer */
            USBD_MemCopy((uint8_t *)(g_u32MassBase), (uint8_t *)g_au8InquiryID, 36);
            MSC_BulkIn(g_u32MassBase, g_sCBW.dCBWDataTransferLength);
            MSC_AckCmd(0);
            break;
        }
        default: {
            /* Unsupported command */
            g_au8SenseKey[0] = 0x05;
            g_au8SenseKey[1] = 0x20;
            g_au8SenseKey[2] = 0x00;

            /* If CBW request for data phase, just return zero packet to end data phase */
            if (g_sCBW.dCBWDataTransferLength > 0)
                MSC_AckCmd(g_sCBW.dCBWDataTransferLength);
            else
                MSC_AckCmd(0);
        }
        }
    }
}

void MSC_ActiveDMA(uint32_t u32Addr, uint32_t u32Len)
{
    /* Enable BUS interrupt */
    UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_DMACOM_Msk|USBD_IRQ_ENB_SUS_Msk|USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_FLODET_Msk);

    USBD_SET_DMA_ADDR(u32Addr);
    USBD_SET_DMA_LEN(u32Len);
    g_usbd_DmaDone = 0;
    USBD_ENABLE_DMA();
    while(1) {
        if (g_usbd_DmaDone)
            break;

        if (!USBD_IS_ATTACHED())
            break;
    }
}

void MSC_AckCmd(uint32_t u32Residue)
{
    g_sCSW.dCSWDataResidue = u32Residue;
    g_sCSW.bCSWStatus = g_u8Prevent;
    USBD_MemCopy((uint8_t *)g_u32MassBase, (uint8_t *)&g_sCSW.dCSWSignature, 16);
    MSC_BulkIn(g_u32MassBase, 13);
    g_u8BulkState = BULK_NORMAL;
}

void MSC_ReadMedia(uint32_t addr, uint32_t size, uint8_t *buffer)
{
}

void MSC_WriteMedia(uint32_t addr, uint32_t size, uint8_t *buffer)
{
}

