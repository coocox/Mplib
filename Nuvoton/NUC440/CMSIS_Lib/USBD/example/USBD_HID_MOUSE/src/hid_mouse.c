/**************************************************************************//**
 * @file     hid_mouse.c
 * @version  V1.00
 * $Date: 13/11/29 2:57p $
 * @brief    NUC400 series USBD driver Sample file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include <string.h>
#include "NUC400Series.h"
#include "hid_mouse.h"
#include "USBD.h"
signed char mouse_table[] = {-16, -16, -16, 0, 16, 16, 16, 0};
uint8_t mouse_idx = 0;
uint8_t move_len, mouse_mode=1;

uint8_t volatile g_u8EPAReady = 0;

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

            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk);
            USBD_SET_ADDR(0);
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_SUS_Msk|USBD_IRQ_ENB_RUM_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_RST_Msk);
            USBD_CLR_CEP_INT_FLAG(0x1ffc);
        }

        if (IrqSt & USBD_IRQ_STAT_RUM_Msk) {
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_SUS_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_RUM_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_SUS_Msk) {
            UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_RST_Msk | USBD_IRQ_ENB_RUM_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_SUS_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_HISPD_Msk) {
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk);
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_HISPD_Msk);
        }

        if (IrqSt & USBD_IRQ_STAT_DMACOM_Msk) {
            g_usbd_DmaDone = 1;
            USBD_CLR_BUS_INT_FLAG(USBD_IRQ_STAT_DMACOM_Msk);

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

    /* interrupt in */
    if (IrqStL & USBD_IRQ_STAT_L_EPA_Msk) {
        IrqSt = USBD->EPA_IRQ_STAT & USBD->EPA_IRQ_ENB;

        UBSD_ENABLE_EP_INT(EPA, 0);
        EPA_Handler();
        USBD_CLR_EP_INT_FLAG(EPA, IrqSt);
    }
    /* interrupt out */
    if (IrqStL & USBD_IRQ_STAT_L_EPB_Msk) {
        IrqSt = USBD->EPB_IRQ_STAT & USBD->EPB_IRQ_ENB;
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

void EPA_Handler(void)  /* Interrupt IN handler */
{
    g_u8EPAReady = 1;
}


/*--------------------------------------------------------------------------*/
/**
  * @brief  USBD Endpoint Config.
  * @param  None.
  * @retval None.
  */
void HID_Init(void)
{
    /* Configure USB controller */
    /* Enable USB BUS, CEP and EPA global interrupt */
    UBSD_ENABLE_USB_INT(USBD_IRQ_ENB_L_USB_Msk|USBD_IRQ_ENB_L_CEP_Msk|USBD_IRQ_ENB_L_EPA_Msk);
    /* Enable BUS interrupt */
    UBSD_ENABLE_BUS_INT(USBD_IRQ_ENB_DMACOM_Msk|USBD_IRQ_ENB_RUM_Msk|USBD_IRQ_ENB_RST_Msk|USBD_IRQ_ENB_FLODET_Msk);
    /* Reset Address to 0 */
    USBD_SET_ADDR(0);

    /*****************************************************/
    /* Control endpoint */
    USBD_SetEpBufAddr(CEP, CEP_BUF_BASE, CEP_BUF_LEN);
    UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_SETUP_PK_Msk|USBD_CEP_IRQ_ENB_STACOM_Msk);

    /*****************************************************/
    /* EPA ==> Interrupt IN endpoint, address 1 */
    USBD_SetEpBufAddr(EPA, EPA_BUF_BASE, EPA_BUF_LEN);
    UBSD_SET_MAX_PAYLOAD(EPA, EPA_MAX_PKT_SIZE);
    USBD_ConfigEp(EPA, INT_IN_EP_NUM, USB_EP_CFG_TYPE_INT, USB_EP_CFG_DIR_IN);
    /* Buffer range for EP2 */
    USBD_SetEpBufAddr(EPA, EPA_BUF_BASE, EPA_BUF_LEN);

    /* start to IN data */
    g_u8EPAReady = 1;
}

void HID_ClassRequest(void)
{
    if (gUsbCmd.bmRequestType & 0x80) { /* request data transfer direction */
        // Device to host
        switch (gUsbCmd.bRequest) {
        case GET_REPORT:
//             {
//                 break;
//             }
        case GET_IDLE:
//             {
//                 break;
//             }
        case GET_PROTOCOL:
//            {
//                break;
//            }
        default: {
            /* Setup error, stall the device */
            USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
            break;
        }
        }
    } else {
        // Host to device
        switch (gUsbCmd.bRequest) {
        case SET_REPORT: {
            if (((gUsbCmd.wValue >> 8) & 0xff) == 3) {
                /* Request Type = Feature */
                USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
                USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
                UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            }
            break;
        }
        case SET_IDLE: {
            /* Status stage */
            USBD_CLR_CEP_INT_FLAG(USBD_CEP_IRQ_STAT_STACOM_Msk);
            USBD_SET_CEP_STATE(USB_CEP_CTRL_STAT_NAK_CLEAR);
            UBSD_ENABLE_CEP_INT(USBD_CEP_IRQ_ENB_STACOM_Msk);
            break;
        }
        case SET_PROTOCOL:
//             {
//                 break;
//             }
        default: {
            // Stall
            /* Setup error, stall the device */
            USBD_SET_CEP_STATE(USBD_CEP_CTRL_STAT_STLALL_Msk);
            break;
        }
        }
    }
}

void HID_UpdateMouseData(void)
{
    uint8_t buf[4];
    int volatile i;

    if (g_u8EPAReady) {
        mouse_mode ^= 1;

        if (mouse_mode) {
            if (move_len > 14) {
                /* Update new report data */
                buf[0] = 0x00;
                buf[1] = mouse_table[mouse_idx & 0x07];
                buf[2] = mouse_table[(mouse_idx + 2) & 0x07];
                buf[3] = 0x00;
                mouse_idx++;
                move_len = 0;
            }
        } else {
            buf[0] = buf[1] = buf[2] = buf[3] = 0;
        }
        move_len++;
        g_u8EPAReady = 0;
        /* Set transfer length and trigger IN transfer */
        for (i=0; i<4; i++)
            USBD->EPA_DATA_BUF_BYTE = buf[i];
        USBD->EPA_RSP_SC = USB_EP_RSP_SC_PK_END;
        UBSD_ENABLE_EP_INT(EPA, USBD_EP_IRQ_ENB_IN_TK_Msk);
    }
}


