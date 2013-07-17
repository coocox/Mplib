/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include <stdint.h>
#include "USB.h"
#include "CLOCK.h"
#include "SYS.h"
#include "DrvUSB.h"


/* USB flow control variables */
USBDEV_T UsbDev;

/** @addtogroup DrvUSB_FUNC DrvUSB Function Interface
  * @{
  */


/**
 * @brief      memory copy by byte
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_WordsCpy(uint8_t *dest, uint8_t *src, int32_t size)
{
    while (size--) *dest++ = *src++;
}

/**
 * @brief      USB Initialization
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_Init(void)
{
    int32_t i;

    /* Enable USB device clock */
    APBCLK_ENABLE(CLK_USBD);
    
    /* Reset IP */
    SYS_RESET_IP2(SYS_RST_USBD);
    
    /* Select USB divider source */
    SET_USB_CLKDIV(1);
    
    USBD_ASSIGN_ATTR(USBD_ATTR_USB_EN);
    USBD_SET_SE0();
    for (i=0; i<100; i++);
    USBD_CLR_SE0();
    
    UsbDev.State = USB_STATE_DETACHED;
    DrvUSB_UsbFdt();
    
    /* Enable USB-related interrupts. */
    USBD_ENABLE_WAKEUP();
    UBSD_ENABLE_INT(USBD_INT_WAKEUP|USBD_INT_FLDET|USBD_INT_USB|USBD_INT_BUS);
    
    NVIC_SetPriority (USBD_IRQn, (1<<__NVIC_PRIO_BITS) - 2);
    NVIC_EnableIRQ(USBD_IRQn);
}


/**
 * @brief      USB Bus Event Handling
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_UsbBus(uint32_t u32State)
{
    /* Process USB bus command if USB is attached. */
    if (u32State & USBD_STATE_USBRST)
    {
        /* Enable USB and enable PHY */
        USBD_ASSIGN_ATTR(USBD_ATTR_USB_EN);
        
        /* Configure the end-points */
        UsbCfg();
    }
    else if (u32State & USBD_STATE_SUSPEND)
    {
        /* Enable USB but disable PHY */
        USBD_CLR_ATTR(USBD_ATTR_ENABLEPHY);
        
        /* Update the USB state */
        UsbDev.State = USB_STATE_SUSPENDED;
    }
    else if (u32State & USBD_STATE_RESUME)
    {
        /* Enable USB and enable PHY */
        USBD_ASSIGN_ATTR(USBD_ATTR_USB_EN);
        
        /* Clear the suspend state */
        UsbDev.State = USB_STATE_CONFIGURED;
    }
}

/**
 * @brief      USB INACK Event Handling
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_UsbInAck(void)
{
    switch (UsbDev.Flag)
    {
        // Set Address
        case FLAG_SET_ADDRESS:
        {
            USBD_SET_ADDR(UsbDev.Address);
            break;
        }
        // Set Interface
        case FLAG_SET_INTERFACE:
        // Set Configuration
        case FLAG_SET_CONFIG:
        {
            UsbDev.State = USB_STATE_CONFIGURED;
            break;
        }
        default:
            return;
    }
    UsbDev.Flag = 0;
}

/**
 * @brief      USB SETUP Event Handling
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
int32_t DrvUSB_UsbSetup(void)
{
    /* Clear the data IN/OUT ready flag of control end-points */
    USBD_EP_STOP_TRANSACT(EP0);
    USBD_EP_STOP_TRANSACT(EP1);

    UsbDev.ep[0] = NULL;
    UsbDev.ep[1] = NULL;

    /* USB device request in setup packet: offset 0, D[6..5]: 0=Stardard, 1=Class, 2=Vendor, 3=Reserved */
    USBD_EP_SET_DATATOG(EP0, USBD_EPCFG_DATA1);
    DrvUSB_WordsCpy((uint8_t *)&UsbDev.Setup, (uint8_t *)(USBD_BASE+0x100+USBD_GET_SETUPBUF()), 8);
    switch (UsbDev.Setup.bmRequestType & REQ_MASK)
    {
        case REQ_STANDARD:
            return UsbStdReq();
        case REQ_CLASS:
            return UsbClassReq();
        default:
            return FALSE;
    }
}

//======================================================
// USB Transmission Processors
//======================================================
static void USB_Transact_do(uint8_t ep, USB_EP_T *t, int first)
{
    uint32_t remain_size = t->size - t->cur_pos;
    
    if (remain_size)
    {
        uint16_t cur_size;
        
        if (DATA_IN == t->direction)
        {
            cur_size = t->ep_size > remain_size ? remain_size : t->ep_size;
            DrvUSB_WordsCpy((uint8_t *)USBD_EP_GET_MEMBUF(ep), &t->buffer[t->cur_pos], cur_size);
            USBD_EP_SET_PAYLOAD_LEN(ep, cur_size);
            t->cur_pos += cur_size;
        }
        else
        {
            if(first == 0)
            {
                cur_size = USBD_EP_GET_PAYLOAD_LEN(ep);
                DrvUSB_WordsCpy(&t->buffer[t->cur_pos], (uint8_t *)USBD_EP_GET_MEMBUF(ep), cur_size);
                t->cur_pos += cur_size;
                if(t->size - t->cur_pos == 0)
                    goto status;
            }
            USBD_EP_SET_PAYLOAD_LEN(ep, t->ep_size);
        }
        		
        
    }
    else
    {
status:
        
        if (t->callback != NULL)
        {
            t->callback(t->param);
        }
        UsbDev.ep[ep] = NULL;
        
    }
}

/**
 * @brief      USB Transmission function
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_Transact(uint8_t ep, USB_EP_T *t)
{
    if ((ep < USBD_EP_NUM) && (t != NULL) && (t->buffer != NULL))
    {
        t->cur_pos = 0;
        
        USB_Transact_do(ep, t, 1);
        UsbDev.ep[ep] = t;
    }
}

/**
 * @brief      USB Transmission deal
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_UsbTransact(uint32_t* u32IntFlag)
{
    USB_EP_T *ep;
    uint8_t i;
    
    for (i = 0; i < USBD_EP_NUM; i++)
    {
        ep = UsbDev.ep[i];
        
        if ((*u32IntFlag & USBD_INTF_EP(EP(i))) && (ep != NULL))
        {
            USB_Transact_do(EP(i), ep, 0);
            *u32IntFlag &= ~USBD_INTF_EP(EP(i));
        }
    }
}

/**
 * @brief      USB Floating Detect
 *
 * @param[out]  dest   destination address
 * @param[in]   src     source address 
 * @param[in]   size    byte count to copy 
 * @return     None
 *
 * @details    This function is used to copy size byte in src to dest address
 */
void DrvUSB_UsbFdt(void)
{
    if (USBD_IS_CONNECTED())
    {
        /* USB Plug In */
        
        /* Update USB state */
        UsbDev.State = USB_STATE_ATTACHED;
        
        /* Init the end points */
        UsbCfg();
        
        /* Enable USB and enable PHY */
        USBD_ASSIGN_ATTR(USBD_ATTR_USB_EN);
    }
    else
    {
        /* USB Un-plug */
        
        /* Update USB state */
        UsbDev.State = USB_STATE_DETACHED;
        
        /* Disable USB, Disable remote weak up, and disable PHY */
        USBD_ASSIGN_ATTR(USBD_ATTR_BYTEMODE|USBD_ATTR_POWERON|USBD_ATTR_PULLUP|USBD_ATTR_REMOTEWAKEUP);
    }
}

/*@}*/ /* end of group DrvUSB_FUNC */
