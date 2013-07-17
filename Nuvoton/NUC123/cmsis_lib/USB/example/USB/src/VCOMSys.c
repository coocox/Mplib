/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "UART.h"
#include "CLOCK.h"
#include "SYS.h"
#include "DrvUSB.h"
#include "VCOMSys.h"

/***************************************************/
/* UART */
#define RXBUFSIZE			256 /* RX buffer size */
#define TXBUFSIZE			256 /* RX buffer size */
#define TX_FIFO_SIZE		64	/* TX Hardware FIFO size */


/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
USB_EP_T EP[5];

volatile uint8_t comRbuf[RXBUFSIZE];
volatile uint16_t comRbytes = 0;
volatile uint16_t comRhead = 0;
volatile uint16_t comRtail = 0;

volatile uint8_t comTbuf[TXBUFSIZE];
volatile uint16_t comTbytes = 0;
volatile uint16_t comThead = 0;
volatile uint16_t comTtail = 0;

uint8_t gRxBuf[MAX_PACKET_SIZE_BULK] = {0};

uint32_t gu32RxSize = 0;
uint32_t gu32TxSize = 0;

volatile int8_t gi8BulkOutReady = 0;

/* Line coding structure
  0-3 dwDTERate    Data terminal rate (baudrate), in bits per second
  4   bCharFormat  Stop bits: 0 - 1 Stop bit, 1 - 1.5 Stop bits, 2 - 2 Stop bits
  5   bParityType  Parity:    0 - None, 1 - Odd, 2 - Even, 3 - Mark, 4 - Space
  6   bDataBits    Data bits: 5, 6, 7, 8, 16  */

typedef struct {
    uint32_t  u32DTERate;     /* Baud rate    */
    uint8_t   u8CharFormat;   /* stop bit     */
    uint8_t   u8ParityType;   /* parity       */
    uint8_t   u8DataBits;     /* data bits    */
} S_VCOM_LINE_CODING;


S_VCOM_LINE_CODING gLineCoding = {115200, 0, 0, 8};    /* Baud rate : 115200    */
													   /* Stop bit     */
													   /* parity       */
													   /* data bits    */

uint16_t gCtrlSignal = 0;     /* BIT0: DTR(Data Terminal Ready) , BIT1: RTS(Request To Send) */

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/
void UART0_IRQHandler(void)
{
    uint8_t bInChar;
    int32_t size;
    
    if(UART_GET_RDA_INT(UART0))
    {
        /* Receiver FIFO threashold level is reached */
        
        /* Get all the input characters */
        while(!UART_GET_RX_EMPTY(UART0))
        {
            /* Get the character from UART Buffer */
            bInChar = UART_READ(UART0);
            
            /* Check if buffer full */
            if(comRbytes < RXBUFSIZE)
            {
                /* Enqueue the character */
                comRbuf[comRtail++] = bInChar;
                if(comRtail >= RXBUFSIZE)
                    comRtail = 0;
                comRbytes++;
            }
            else
            {
            	/* FIFO over run */
            }
        }
    }
    
    if(UART_GET_THRE_IF(UART0))
    {
        
        if(comTbytes)
        {
            /* Fill the Tx FIFO */
            size = comTbytes;
            if(size >= TX_FIFO_SIZE)
            {
                size = TX_FIFO_SIZE;
            }
            
            while(size)
            {
                bInChar = comTbuf[comThead++];
                UART0->DATA = bInChar;
                if(comThead >= TXBUFSIZE)
                    comThead = 0;
                comTbytes--;
                size--;
            }
        }
        else
        {
            /* No more data, just stop Tx (Stop work) */
            UART_DISABLE_INT(UART0, UART_IER_THRE_IEN);
        }
    }

}


/*********************************************/
#define USB_VID			0x0416  /* Vendor ID */
#define USB_PID			0x5011  /* Product ID */

/*======================================================*/
/* USB Descriptor										*/
/*======================================================*/
#define USB_VID_LO      (USB_VID & 0xFF)
#define USB_VID_HI      ((USB_VID >> 8) & 0xFF)

#define USB_PID_LO      (USB_PID & 0xFF)
#define USB_PID_HI      ((USB_PID >> 8) & 0xFF)



const uint8_t gau8DeviceDescriptor[] =
{
    LEN_DEVICE,		/* bLength              */
    DESC_DEVICE,	/* bDescriptorType      */
    0x00, 0x02,		/* bcdUSB               */
    0x02,			/* bDeviceClass         */
    0x00,			/* bDeviceSubClass      */
    0x00,			/* bDeviceProtocol      */
    MAX_PACKET_SIZE0,	/* bMaxPacketSize0      */
    USB_VID_LO,
    USB_VID_HI,     /* Veondor ID           */
    USB_PID_LO,
    USB_PID_HI,     /* Product ID           */
    0x00, 0x03,		/* bcdDevice            */
    0x01,			/* iManufacture         */
    0x02,			/* iProduct             */
    0x00,			/* iSerialNumber        */
    0x01			/* bNumConfigurations   */
};


const uint8_t gau8ConfigDescriptor[] =
{
    LEN_CONFIG,		/* bLength              */
    DESC_CONFIG,	/* bDescriptorType      */
    0x43, 0x00,		/* wTotalLength         */
    0x02,			/* bNumInterfaces       */
    0x01,			/* bConfigurationValue  */
    0x00,			/* iConfiguration       */
    0xC0,			/* bmAttributes         */
    0x32,			/* MaxPower             */
    
    /* INTERFACE descriptor */
    LEN_INTERFACE,	/* bLength              */
    DESC_INTERFACE,	/* bDescriptorType      */
    0x00,			/* bInterfaceNumber     */
    0x00,			/* bAlternateSetting    */
    0x01,			/* bNumEndpoints        */
    0x02,			/* bInterfaceClass      */
    0x02,			/* bInterfaceSubClass   */
    0x01,			/* bInterfaceProtocol   */
    0x00,			/* iInterface           */
    
    /* Communication Class Specified INTERFACE descriptor */
    0x05,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x00,           /* Header functional descriptor subtype */
    0x10, 0x01,     /* Communication device compliant to the communication spec. ver. 1.10 */
    
    /* Communication Class Specified INTERFACE descriptor */
    0x05,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x01,           /* Call management functional descriptor */
    0x00,           /* BIT0: Whether device handle call management itself. */
    				/* BIT1: Whether device can send/receive call management information over a Data Class Interface 0 */
    0x01,           /* Interface number of data class interface optionally used for call management */
    
    /* Communication Class Specified INTERFACE descriptor */
    0x04,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x02,           /* Abstract control management funcational descriptor subtype */
    0x00,           /* bmCapabilities       */
    
    /* Communication Class Specified INTERFACE descriptor */
    0x05,           /* bLength              */
    0x24,           /* bDescriptorType: CS_INTERFACE descriptor type */
    0x06,           /* bDescriptorSubType   */
    0x00,           /* bMasterInterface     */
    0x01,           /* bSlaveInterface0     */
    
    /* ENDPOINT descriptor */
    LEN_ENDPOINT,	                /* bLength          */
    DESC_ENDPOINT,	                /* bDescriptorType  */
    (EP_INPUT | INT_IN_EP_NUM),     /* bEndpointAddress */
    EP_INT,		                    /* bmAttributes     */
    MAX_PACKET_SIZE_INT, 0x00,	            /* wMaxPacketSize   */
    0x01,	                        /* bInterval        */
    
    /* INTERFACE descriptor */
    LEN_INTERFACE,	/* bLength              */
    DESC_INTERFACE,	/* bDescriptorType      */
    0x01,			/* bInterfaceNumber     */
    0x00,			/* bAlternateSetting    */
    0x02,			/* bNumEndpoints        */
    0x0A,			/* bInterfaceClass      */
    0x00,			/* bInterfaceSubClass   */
    0x00,			/* bInterfaceProtocol   */
    0x00,			/* iInterface           */
    
    /* ENDPOINT descriptor */
    LEN_ENDPOINT,	                /* bLength          */
    DESC_ENDPOINT,	                /* bDescriptorType  */
    (EP_INPUT | BULK_IN_EP_NUM),	/* bEndpointAddress */
    EP_BULK,		                /* bmAttributes     */
    MAX_PACKET_SIZE_BULK, 0x00,	        /* wMaxPacketSize   */
    0x00,			                /* bInterval        */
    
    /* ENDPOINT descriptor */
    LEN_ENDPOINT,	                /* bLength          */
    DESC_ENDPOINT,	                /* bDescriptorType  */
    (EP_OUTPUT | BULK_OUT_EP_NUM),	/* bEndpointAddress */
    EP_BULK,		                /* bmAttributes     */
    MAX_PACKET_SIZE_BULK, 0x00,	        /* wMaxPacketSize   */
    0x00,			                /* bInterval        */
};


const uint8_t gau8StringLang[] = {
    4,				/* bLength                  */
    DESC_STRING,	/* bDescriptorType          */
    0x09, 0x04      /* Language ID: USA(0x0409) */
};


const uint8_t gau8VendorStringDescriptor[] = {
    16,             /* bLength          */
    DESC_STRING,    /* bDescriptorType  */
    'N', 0,
    'u', 0,
    'v', 0,
    'o', 0,
    't', 0,
    'o', 0,
    'n', 0
};

const uint8_t gau8ProductStringDescriptor[] = {
    32,             /* bLength          */
    DESC_STRING,    /* bDescriptorType  */
    'U', 0,
    'S', 0,
    'B', 0,
    ' ', 0,
    'V', 0,
    'i', 0,
    'r', 0,
    't', 0,
    'u', 0,
    'a', 0,
    'l', 0,
    ' ', 0,
    'C', 0,
    'O', 0,
    'M', 0
};

//======================================================
// USB ISR
//======================================================
void USBD_IRQHandler(void)
{
    uint32_t u32IntFlag = USBD_GET_INTF();
    uint32_t u32State = USBD_GET_STATE();
    uint32_t u32EPSTS = USBD_EP_GET_STAT_ALL();
    
    if (u32IntFlag & USBD_INTF_BUS)
    {
        /* Clear BUS event flag */
        USBD_CLR_INTF(USBD_INTF_BUS);
        /* Handle the USB bus event: Reset, Suspend, and Resume */
        DrvUSB_UsbBus(u32State);
    }
    else if (u32IntFlag & USBD_INTF_USB)
    {
        /* Handle the USB Protocol/Clase event */
        UsbUsb(u32IntFlag, u32EPSTS);
    }
    else if (u32IntFlag & USBD_INTF_FLDET)
    {
        /* EN: Clear float detect event flag */
        USBD_CLR_INTF(USBD_INTF_FLDET);
        /* Handle the USB attached/detached event */
        DrvUSB_UsbFdt();
    }
    else if (u32IntFlag & USBD_INTF_WAKEUP)
    {
        /* Clear wakeup event. write one clear */
        USBD_CLR_INTF(USBD_INTF_WAKEUP);
    }
}

//======================================================
static void UsbStdReq_StatusOut(void *param)
{
    USBDEV_T *dev = param;
    
    if ((dev->Setup.wLength > dev->ep[0]->size) &&
    	!(dev->ep[0]->size % dev->ep[0]->ep_size))
    {
        USBD_EP_SET_PAYLOAD_LEN(EP0, 0);
    }
    USBD_EP_SET_PAYLOAD_LEN(EP1, 0);
}

int32_t UsbStdReq(void)
{
    /* parse the request in setup packet */
    switch (UsbDev.Setup.bRequest)
    {
        case GET_DESCRIPTOR:
        {
            uint32_t u32DescLen;
            uint8_t *pu8Desc;
            
            switch (UsbDev.Setup.wValue >> 8)
            {
                // Get Device Descriptor
                case DESC_DEVICE:
                {
                    u32DescLen = sizeof(gau8DeviceDescriptor);
                    pu8Desc = (uint8_t *)gau8DeviceDescriptor;
                    break;
                }
                // Get Configuration Descriptor
                case DESC_CONFIG:
                {
                    u32DescLen = sizeof(gau8ConfigDescriptor);
                    pu8Desc = (uint8_t *)gau8ConfigDescriptor;
                    break;
                }
                // Get String Descriptor
                case DESC_STRING:
                {
                    uint8_t u8DescIndex = UsbDev.Setup.wValue & 0xFF;
                    // Get Language
                    if(u8DescIndex == 0)
                    {
                        u32DescLen = gau8StringLang[0];
                        pu8Desc = (uint8_t *)gau8StringLang;
                    }
                    // Get Vendor String Descriptor
                    else if (u8DescIndex == 1)
                    {
                        u32DescLen = gau8VendorStringDescriptor[0];
                        pu8Desc = (uint8_t *)gau8VendorStringDescriptor;
                    }
                    else if (u8DescIndex == 2)
                    {
                        u32DescLen = gau8ProductStringDescriptor[0];
                        pu8Desc = (uint8_t *)gau8ProductStringDescriptor;
                    }
                }
                default:
                    return FALSE;
            }
            EP[0].buffer = pu8Desc;
            EP[0].size = UsbDev.Setup.wLength > u32DescLen ? u32DescLen : UsbDev.Setup.wLength;
            EP[0].ep_size = MAX_PACKET_SIZE0;
            EP[0].direction = DATA_IN;
            EP[0].param = &UsbDev;
            EP[0].callback = UsbStdReq_StatusOut;
            DrvUSB_Transact(EP0, &EP[0]);
            return TRUE;
        }
        
        case SET_ADDRESS:
        {
            /* EN: Get the device address */
            UsbDev.Address = UsbDev.Setup.wValue;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 0);
            UsbDev.Flag = FLAG_SET_ADDRESS;
            return TRUE;
        }
        
        case SET_CONFIGURATION:
        {
            UsbDev.Config = UsbDev.Setup.wValue;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 0);
            USBD_EP_SET_PAYLOAD_LEN(EP2, 0);
            USBD_EP_SET_PAYLOAD_LEN(EP3, MAX_PACKET_SIZE_BULK);
            UsbDev.Flag = FLAG_SET_CONFIG;
            return TRUE;
        }
        case CLEAR_FEATURE:
        case SET_FEATURE:
        {
            if((UsbDev.Setup.bmRequestType == 2) &&
            	(UsbDev.Setup.wValue == FEATURE_ENDPOINT_HALT))
            {
                uint8_t ep = EP(UsbDev.Setup.wIndex);
                
                if(UsbDev.Setup.bRequest == CLEAR_FEATURE)
                    USBD_EP_CLR_STALL(ep);
                else
                    USBD_EP_SET_STALL(ep);
            }
            else
                return FALSE;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 0);
            return TRUE;
        }
        
        case GET_CONFIGURATION:
        {
            g_au8UsbCtrl[0] = UsbDev.Config;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 1);
            UsbDev.Flag = FLAG_OUT_ACK;
            return TRUE;
        }
        
        case GET_STATUS:
        {
            uint8_t u8Data;
            
            u8Data = UsbDev.Setup.bmRequestType;
            // Device
            if (u8Data == 0x80)
                g_au8UsbCtrl[0] = 1;  // Self-Powered
            
            // Interface
            else if (u8Data == 0x81)
                g_au8UsbCtrl[0] = 0;
            
            // Endpoint
            else if (u8Data == 0x82)
            {
                uint8_t ep = EP(UsbDev.Setup.wIndex & 0xF);
                
                g_au8UsbCtrl[0] = USBD_EP_GET_STALL(ep) ? 1 : 0;
            }
            else
                return FALSE;
            
            g_au8UsbCtrl[1] = 0;
            
			USBD_EP_SET_PAYLOAD_LEN(EP0, 2);
            UsbDev.Flag = FLAG_OUT_ACK;
            return TRUE;
        }
        
        case GET_INTERFACE:
        {
            g_au8UsbCtrl[0] = 0;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 1);
            UsbDev.Flag = FLAG_OUT_ACK;
            return TRUE;
        }
        
        case SET_INTERFACE:
        {
            UsbDev.Flag = FLAG_SET_INTERFACE;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0, 0);
            return TRUE;
        }
        default:
            return FALSE;
    }
}


/******************************************************/
/* USB */
//======================================================
// USB Configuration
//======================================================
void UsbCfg(void)
{
    int32_t i;
    /* Init the USB device address to 0x0 */
    USBD_SET_ADDR(0x00);
    
    /* Init control end point */
    USBD_SET_SETUPBUF(BUF_SETUP);					/* Buffer for setup packet */
    USBD_EP_STOP_TRANSACT(EP0);						/* Clear EP0 CTRL IN Ready Flag */
    USBD_EP_ASSIGN_CFG(EP0, CFG0_SETTING);			/* EP0 ==> control IN end point, address 0 */
    USBD_EP_SET_BUF(EP0, BUF_CTRL);					/* Buffer for EP0 */
    USBD_EP_STOP_TRANSACT(EP1);						/* Clear EP1 CTRL OUT Ready Flag */
    USBD_EP_ASSIGN_CFG(EP1, CFG1_SETTING);			/* EP1 ==> control OUT end point, address 0 */
    USBD_EP_SET_BUF(EP1, BUF_CTRL);					/* Buffer for EP1 */
    
    /* Init Bulk IN end point */
    USBD_EP_STOP_TRANSACT(EP2);						/* Clear EP2 BULK IN Ready Flag */
    USBD_EP_ASSIGN_CFG(EP2, CFG2_SETTING);			/* EP2 ==> BULK IN end point, address 1 */
    USBD_EP_SET_BUF(EP2, BUF_BULK_IN);				/* Buffer for EP2 (BULK IN) */
    
    /* Init Bulk OUT end point */
    USBD_EP_STOP_TRANSACT(EP3);						/* Clear EP3 BULK OUT Ready Flag */
    USBD_EP_ASSIGN_CFG(EP3, CFG3_SETTING);			/* EP3 ==> BULK OUT end point, address 2 */
    USBD_EP_SET_BUF(EP3, BUF_BULK_OUT);				/* Buffer for EP3 (BULK OUT) */
    
    /* Init Interrupt IN end point */
    USBD_EP_STOP_TRANSACT(EP4);						/* Clear EP4 INT IN Ready Flag */
    USBD_EP_ASSIGN_CFG(EP4, CFG4_SETTING);			/* EP4 ==> INT IN end point, address 3 */
    USBD_EP_SET_BUF(EP4, BUF_INT_IN);					/* Buffer for EP4 (BULK IN) */

    for(i=0; i<USBD_EP_NUM; i++)
        UsbDev.ep[i] = NULL;

    UsbDev.Address = 0;								/* EN: Device address */
    UsbDev.Config = 0;
    UsbDev.Flag = 0;								/* EN: Flag to record the USB request */
}

//======================================================
void UsbOutAck(void)
{
    switch (UsbDev.Flag)
    {
        case FLAG_SET_LINE_CODE:
        {
            memcpy((void *)&gLineCoding, g_au8UsbCtrl, USBD_EP_GET_PAYLOAD_LEN(EP1));
            USBD_EP_SET_PAYLOAD_LEN(EP0,0);
            break;
        }
        default:
            ;
    }
    UsbDev.Flag = 0;
}

//======================================================
void UsbIntInAck(void)
{
    uint8_t au8Buf[8] = {0};
    memcpy(g_au8UsbIntIn, au8Buf, MAX_PACKET_SIZE_INT);
    USBD_EP_SET_PAYLOAD_LEN(EP4, MAX_PACKET_SIZE_INT);
}

void UsbBulkInAck(void)
{
    gu32TxSize = 0;
}

void UsbBulkOutAck(void)
{
    gu32RxSize = USBD_EP_GET_PAYLOAD_LEN(EP3);
    
    /* Set a flag to indicate builk out ready */
    gi8BulkOutReady = 1;
}

//======================================================
// USB USB Event
//======================================================
void UsbUsb(uint32_t u32IntFlag, uint32_t u32EPSTS)
{
    if (u32IntFlag & USBD_INTF_SETUP)
    {
    /* EN: Clear USB setup event flag */
        USBD_CLR_INTF(USBD_INTF_SETUP);
        
        if (!DrvUSB_UsbSetup())
        {
            /* Setup error, stall the device */
            USBD_EP_SET_STALL(EP0);
            USBD_EP_SET_STALL(EP1);
        }
    }
    else
    {
       /* EN: Clear USB setup event flag */
        USBD_CLR_INTF(USBD_INTF_USB);
        
        DrvUSB_UsbTransact(&u32IntFlag);
        
        if(u32IntFlag & USBD_INTF_EP0)
        {
            /* Ctrl In */
            if((USBD_EP_GET_STAT_FROM(u32EPSTS, 0) == USBD_EPSTAT_INACK))
                DrvUSB_UsbInAck();
        }
        else if(u32IntFlag & USBD_INTF_EP1)
        {
            /* Ctrl Out */
            UsbOutAck();
        }
        else if(u32IntFlag & USBD_INTF_EP2)
        {
            /* Bulk In */
            if((USBD_EP_GET_STAT_FROM(u32EPSTS, 2) == USBD_EPSTAT_INACK))
                UsbBulkInAck();
        }
        else if(u32IntFlag & USBD_INTF_EP3)
        {
            /* Bulk Out */
            UsbBulkOutAck();
        }
        else if(u32IntFlag & USBD_INTF_EP4)
        {
            /* Interrupt In */
            if((USBD_EP_GET_STAT_FROM(u32EPSTS, 4) == USBD_EPSTAT_INACK))
                UsbIntInAck();
        }
        else
        {
            /* Unknow event */
        }
    }
}

//======================================================
int32_t UsbClassReq(void)
{
    switch(UsbDev.Setup.bRequest)
    {
        case SET_LINE_CODE:
        {
            /* Ready to get next Ctrl out */
            USBD_EP_SET_PAYLOAD_LEN(EP1, 7);
            UsbDev.Flag = FLAG_SET_LINE_CODE;
            
            return TRUE;
        }
        
        case GET_LINE_CODE:
        {
            DrvUSB_WordsCpy(g_au8UsbCtrl, (void *)&gLineCoding, 7);
            USBD_EP_SET_PAYLOAD_LEN(EP0, 7);
            USBD_EP_SET_PAYLOAD_LEN(EP1, 0);
            
            return TRUE;
        }
        
        case SET_CONTROL_LINE_STATE:
        {
            gCtrlSignal = UsbDev.Setup.wValue;
            
            USBD_EP_SET_PAYLOAD_LEN(EP0,0);
            return TRUE;
        }
    }
    return FALSE;
}


/***************************************************/
/* Main */
void VCOM_MainProcess(void)
{
    int32_t i, i32Len;
    
    /* Enable Interrupt and install the call back function */
    SYS->GPB_MFP = (SYS_MFPB0_RX0 | SYS_MFPB1_TX0);
    SYS_RESET_IP2(SYS_RST_UART0);                             //En:Reset UART0 IP
    APBCLK_ENABLE(CLK_UART0);                             //En:Enable UART0 clock
    SET_UART_CLKSRC(CLK_UART_HXT);                        //En:Select external crystal as UART clock source
    SET_UART_CLKDIV(1);                                      //En:Set UART clock divider number
    UART_SET_BAUD_MODE2(UART0, __XTAL, 115200);               //En:Set UART0 Baudrate
    UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1); //En:Configure UART0 data format
    UART_ENABLE_INT(UART0, UART_IER_RDA_IEN|UART_IER_RLS_IEN);
    NVIC_EnableIRQ(UART0_IRQn);

    DrvUSB_Init();
    
    while(1)
    {
        /* Check if any data to send to USB & USB is ready to send them out */
        if(comRbytes && (gu32TxSize == 0))
        {
            i32Len = comRbytes;
            if(i32Len > MAX_PACKET_SIZE_BULK)
                i32Len = MAX_PACKET_SIZE_BULK;
            
            for(i=0;i<i32Len;i++)
            {
                gRxBuf[i] = comRbuf[comRhead++];
                if(comRhead >= RXBUFSIZE)
                    comRhead = 0;
            }
            
            NVIC_DisableIRQ(UART0_IRQn);
            comRbytes -= i32Len;
            NVIC_EnableIRQ(UART0_IRQn);
            
            gu32TxSize = i32Len;
            DrvUSB_WordsCpy(g_au8UsbBulkIn, (void *)gRxBuf, i32Len);
            USBD_EP_SET_PAYLOAD_LEN(EP2, i32Len);
        }
        
        
        /* Process the Bulk out data when bulk out data is ready. */
        if(gi8BulkOutReady && (gu32RxSize <= TXBUFSIZE - comTbytes))
        {
            for(i=0;i<gu32RxSize;i++)
            {
                comTbuf[comTtail++] = g_au8UsbBulkOut[i];
                if(comTtail >= TXBUFSIZE)
                    comTtail = 0;
            }
            
            NVIC_DisableIRQ(UART0_IRQn);
            comTbytes += gu32RxSize;
            NVIC_EnableIRQ(UART0_IRQn);
            
            gu32RxSize = 0;
            gi8BulkOutReady = 0; /* Clear bulk out ready flag */
            
            /* Ready to get next BULK out */
            USBD_EP_SET_PAYLOAD_LEN(EP3, MAX_PACKET_SIZE_BULK);
        }
        
        
        /* Process the software Tx FIFO */
        if(comTbytes)
        {
            /* Check if Tx is working */
            if(!(UART_GET_INT(UART0) & UART_IER_THRE_IEN))
            {
                /* Send one bytes out */
                UART_WRITE(UART0, comTbuf[comThead]);
                comThead++;
                if(comThead >= TXBUFSIZE)
                    comThead = 0;
                
                NVIC_DisableIRQ(UART0_IRQn);
                comTbytes--;
                NVIC_EnableIRQ(UART0_IRQn);
                
                /* Enable Tx Empty Interrupt. (Trigger first one) */
                UART_ENABLE_INT(UART0, UART_IER_THRE_IEN);
            }
        }
    }
}
