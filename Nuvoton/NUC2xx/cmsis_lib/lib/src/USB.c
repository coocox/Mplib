/****************************************************************************
 * @file     USB.c
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 12/08/08 2:49p $ 
 * @brief    NUC200 Series USB Driver API
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "NUC200Series.h"
#include "USB.h"

S_USBD_DEVICE gsUsbDevice;
PFN_USBD_INTCALLBACK g_FnIntCallBack;
uint32_t CFG_EP_SETTING[6];
static uint8_t *g_UsbSramBase;

static int32_t USBD_Init(void);
static void USBD_UnInit(void);

void WordsCpy(void *dest, void *src, int32_t size)
{
    uint8_t *pu8Src, *pu8Dest;
    int32_t i;
    
    pu8Dest = (uint8_t *)dest;
    pu8Src  = (uint8_t *)src;
    
    for(i=0;i<size;i++)
        pu8Dest[i] = pu8Src[i]; 
}


/**
  * @brief      USB interrupt handler
  * @details    This function is used to call event handler when USB interrupt 
  */

void USBD_IRQHandler(void)
{
     USBD_PreDispatchEvent();
     if (g_FnIntCallBack)
         g_FnIntCallBack((void *)&gsUsbDevice);
}

/**
  * @brief      Check if SmartCard slot is presented
  * @param[in]	pVoid	User interrupt callback function, it will be called in USB IRQ Handler
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    Open USB, include assign USB SRAM, init state and install interrupt handlerClose a file
  */
int32_t USBD_Open(void * pVoid)
{
    uint32_t i, j;
    uint8_t *p;
    
    USBD_Init();
    
    if (pVoid != NULL)
        g_FnIntCallBack = (PFN_USBD_INTCALLBACK)pVoid;
    
    gsUsbDevice.u16MiscEventFlags = 0;
    gsUsbDevice.u16EPEventFlags = 0;
    
    p = (uint8_t *)USBD_SRAM_BASE;
    
    /* for setup packet */
    gsUsbDevice.sEpCrl[MAX_EP_ID].u32EpNum = 0x0;
    gsUsbDevice.sEpCrl[MAX_EP_ID].u32MaxPacketSize = 8;
    gsUsbDevice.sEpCrl[MAX_EP_ID].u8SramBuffer = p;
    p += 8;
    
    i = 0;
    while (sEpDescription[i].u32MaxPacketSize != 0)
    {       
        /* There may be some EPs which have the same EP address. We will find them out here in order to use same buffer. */
        for (j = 0; j < i; j++)
        {
            if ((sEpDescription[i].u32EpNum & 0xF) == (gsUsbDevice.sEpCrl[j].u32EpNum & 0xF))
                break;
        }
        
        gsUsbDevice.sEpCrl[i].u32EpNum = sEpDescription[i].u32EpNum;
        gsUsbDevice.sEpCrl[i].u32MaxPacketSize = sEpDescription[i].u32MaxPacketSize;
        
        /* Assign the transfer buffer */
        if (sEpDescription[i].u8SramBuffer == NULL)
        {               
            if (j < i)
            {
                /* Use the same buffer if they have the same EP address */
                gsUsbDevice.sEpCrl[i].u8SramBuffer = gsUsbDevice.sEpCrl[j].u8SramBuffer;
            }
            else
            {
                /* Assign a new buffer */
                gsUsbDevice.sEpCrl[i].u8SramBuffer = p;
                p += sEpDescription[i].u32MaxPacketSize;
            }
            
            /* Write back the assigned buffer */
            sEpDescription[i].u8SramBuffer = gsUsbDevice.sEpCrl[i].u8SramBuffer;
        }

        if ((sEpDescription[i].u32EpNum & 0x1f) == 0)
        {
            /* Only ctrl EP needs to support STALL auto clear */
            CFG_EP_SETTING[i] = (CFG_CSTALL | 
              ((sEpDescription[i].u32EpNum&EP_INPUT)?CFG_EPT_IN:CFG_EPT_OUT) 
              | (sEpDescription[i].u32EpNum&0x0F));
        }
        else
        {
            CFG_EP_SETTING[i] = ((sEpDescription[i].u32EpNum&EP_INPUT)?CFG_EPT_IN:CFG_EPT_OUT) 
              | (sEpDescription[i].u32EpNum&0x0F);
        }
        
        i++;
    }
    
    /* Update the remind buffer base */
    g_UsbSramBase = p;

    gsUsbDevice.eUsbState = eUSBD_DETACHED;
    gsUsbDevice.u32FLDET = USBD->FLDET;
    USBD_PreDispatchFDTEvent(&gsUsbDevice);
    USBD_DispatchMiscEvent(&gsUsbDevice);
    
    NVIC_SetPriority (USBD_IRQn, (1<<__NVIC_PRIO_BITS) - 2);
    NVIC_EnableIRQ(USBD_IRQn);

    return 0;
}

/**
  * @brief      Pre dispatch event base on EVF register
  * @details    Pre dispatch event base on EVF register. This function will be called by IRQ Handler
  */
void USBD_PreDispatchEvent(void)
{
    gsUsbDevice.u32INTSTS = _USBD_GET_EVENT_FLAG();

    if (gsUsbDevice.u32INTSTS & INTSTS_WAKEUP)
    {
        /* Clear wakeup event. write one clear */
        _USBD_SET_EVENT_FLAG(INTSTS_WAKEUP);
        
        /* Pre-dispatch wakeup event. */
        USBD_PreDispatchWakeupEvent(&gsUsbDevice);
    }
    else if (gsUsbDevice.u32INTSTS & INTSTS_FLDET)
    {
        gsUsbDevice.u32FLDET = USBD->FLDET;
        /* Clear float-detection event. Write one clear */
        _USBD_SET_EVENT_FLAG(INTSTS_FLDET);

        /* Pre-dispatch float-detection event. */
        USBD_PreDispatchFDTEvent(&gsUsbDevice);
    }
    else if (gsUsbDevice.u32INTSTS & INTSTS_BUS)
    {
        gsUsbDevice.u32ATTR = *((__IO uint32_t *)(&USBD->ATTR));
        /* Clear bus event. Write one clear */
        _USBD_SET_EVENT_FLAG(INTSTS_BUS);
        
        /* Pre-dispatch bus event. */
        USBD_PreDispatchBusEvent(&gsUsbDevice);
    }
    else if (gsUsbDevice.u32INTSTS & INTSTS_USB)
    {
        gsUsbDevice.u32EPSTS = _USBD_GET_EPSTS();
        
        /* Clear USB events individually instead of in total.
           Otherwise, incoming USB events may be cleared mistakenly.
           Pre-dispatch USB event. */
        USBD_PreDispatchEPEvent(&gsUsbDevice);
    }
}

/**
  * @brief      Dispatch Misc and EP event
  * @details    Dispatch Misc and EP event. Misc event include  attach/detach/bus reset/bus suspend/
  *             bus resume and setup ACK, Misc event'handler is g_sBusOps[] 
  */
void USBD_DispatchEvent(void)
{
    USBD_DispatchMiscEvent(&gsUsbDevice);
    USBD_DispatchEPEvent(&gsUsbDevice);
}


/**
  * @brief      To check if the current DATA is DATA0.
  * @param[in]	u32EpId	    EP Id. The hardware id of specified endpoint
  * @details    To check if the current DATA is DATA0. If it is false, then it should be DATA1.
  */
int32_t USBD_IsData0(uint32_t u32EpId)
{
    int32_t bData0 = 0;

    if (u32EpId >= MAX_EP_ID)
    {
        bData0 = 0;
    }
    else
    {
        bData0 = gsUsbDevice.abData0[u32EpId];
    }

    return bData0;
}

/**
  * @brief      Get current USB state E_USBD_STATE
  * @details    Get current USB state E_USBD_STATE
  */
E_USBD_STATE USBD_GetUsbState(void)
{
    return (E_USBD_STATE)gsUsbDevice.eUsbState;
}

/**
  * @brief      Change current USB state
  * @param[in]	eUsbState   [in]  The wanted state
  * @details    Change current USB state
  */
void USBD_SetUsbState(E_USBD_STATE eUsbState)
{
    gsUsbDevice.eUsbState = eUsbState;
}

/**
  * @brief      Close USB
  * @details    Close USB: uninstall interrupt handler, disable USB clock
  */
void USBD_Close(void)
{    
    NVIC_DisableIRQ(USBD_IRQn);
    USBD_UnInit();
}


/**
  * @brief      Get endpoint id base on endpoint number and direction
  * @param[in]	u32EpNum   EP number
  *             u32EPAttr  EP_OUTPUT/EP_INPUT
  * @retval     0~5         EP id
  *			    Otherwise   Error
  * @details    Get endpoint id base on endpoint number and direction. The endpoint id is used to identify 
  *             the hardware endpoint resource. The range of endpoint id could be 0 ~ 5. The endpoint number is
  *             assigned by software and it could be 0 ~ 15. Host will access the device through relative 
  *             endpoint number.
  */
int32_t USBD_GetEpIdentity(uint32_t u32EpNum, uint32_t u32EpAttr)
{
    uint32_t i;

    S_USBD_DEVICE *psDevice =&gsUsbDevice;
    
    for ( i = 0; i < MAX_EP_ID; i++)
    {
        if (psDevice->sEpCrl[i].u32EpNum == (u32EpNum | u32EpAttr))
            return i;
    }
    
    return E_USBD_INVALID_EP_NUM;

}

/**
  * @brief      Get EP id base on EP number
  * @param[in]	u32EpNum    EP number. bit7 is used to define direction.
  *                         1 = IN endpoint, 0 = OUT endpoint.
  * @retval     0~5         EP id 
  *			    Otherwise   Error
  * @details    Get EP id base on EP number. This EP number is different from USBD_GetEpIdentity's. Because
  *             its argument includes direction. ex: 0x81.
  */
int32_t USBD_GetEpId(uint32_t u32EpNum)
{
    uint32_t i;
    S_USBD_DEVICE *psDevice =&gsUsbDevice;
    
    for ( i = 0; i < MAX_EP_ID; i++)
    {
        if (psDevice->sEpCrl[i].u32EpNum == u32EpNum)
            return i;
    }
    
    return E_USBD_INVALID_EP_NUM; 
}

/**
  * @brief      Trigger data out ready flag by write MXPLD register
  * @param[in]	u32EpNum      EP number
  # @param[in]  u32Size       Max size want to receive from USB
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    Trigger data out ready flag by write MXPLD register.
  */
int32_t USBD_DataOutTrigger(uint32_t u32EpNum, uint32_t u32Size)
{
    uint32_t u32EpId;
    S_USBD_DEVICE *psDevice = &gsUsbDevice;
    
    u32EpId = USBD_GetEpIdentity(u32EpNum, EP_OUTPUT);
    
    if (u32Size > psDevice->sEpCrl[u32EpId].u32MaxPacketSize)
        return E_USBD_SIZE_TOO_LONG;

        
    _USBD_SET_EP_BUF(u32EpId, (uint32_t)psDevice->sEpCrl[u32EpId].u8SramBuffer);
    _USBD_TRIG_EP(u32EpId, u32Size);
    
    return 0;
}

/**
  * @brief      Get USB OUT data
  * @param[in]	u32EpNum    Endpoint number
  * @param[in]	u32Size     Data size that received
  * @retval     USB SRAM address
  *			    
  * @details    This function will return the buffer pointer of u32EpNum's out USB SRAM buffer. User can 
  *             use this pointer to get the data payload of current data out packet.
  */
uint8_t * USBD_GetOutData(uint32_t u32EpNum, uint32_t *u32Size)
{
    uint32_t u32EpId;
    
    u32EpId = USBD_GetEpIdentity(u32EpNum, EP_OUTPUT);
    *u32Size = _USBD_GET_EP_DATA_SIZE(u32EpId);

    return sEpDescription[u32EpId].u8SramBuffer;
}

/**
  * @brief      Prepare the data for USB IN token
  * @param[in]	u32EpNum    EP number, send data from it
  * @param[in]	u8Buffer    Data buffer
  * @param[in]	u32Size     Data size
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    Trigger ready flag for sending data after receive IN token from host, USB will send the data
  *             if u8Buffer == NULL && u32Size == 0 then send DATA1 always else DATA0 and DATA1 by turns.
  */
int32_t USBD_DataIn(uint32_t u32EpNum, const uint8_t * u8Buffer, uint32_t u32Size)
{
    S_USBD_DEVICE *psDevice = &gsUsbDevice;
    uint32_t u32EpId;
    
    u32EpId = USBD_GetEpIdentity(u32EpNum, EP_INPUT);
    
    if (u32Size > psDevice->sEpCrl[u32EpId].u32MaxPacketSize)
        return E_USBD_SIZE_TOO_LONG;

    
    if (u8Buffer && u32Size)
    {
        WordsCpy(psDevice->sEpCrl[u32EpId].u8SramBuffer, (void *)u8Buffer, u32Size);
    }
    
    _USBD_SET_EP_BUF(u32EpId, (uint32_t)psDevice->sEpCrl[u32EpId].u8SramBuffer);
    
    if (u8Buffer == NULL && u32Size == 0)
        psDevice->abData0[u32EpId] = 0;
    else
        psDevice->abData0[u32EpId] = !psDevice->abData0[u32EpId];
    
    _USBD_SET_EP_TOG_BIT(u32EpId, psDevice->abData0[u32EpId]);
    _USBD_TRIG_EP(u32EpId, u32Size);
    
    return 0;
}

/**
  * @brief      Bus reset handler
  * @param[in]	pVoid       Parameter passed by g_sBusOps[]
  * @details    Bus reset handler. After receiving bus reset event, this handler will be called. 
  *             It will reset USB address, accept SETUP packet and initial the endpoints.
  */
void USBD_BusResetCallback(void * pVoid)
{
    S_USBD_DEVICE *psDevice =&gsUsbDevice;
    int i;

    /* Reset function address of USB device */
    _USBD_SET_FADDR(0x00);
    
    /* Disable IN NAK Flag */
    USBD->INTEN &= (~USBD_INTEN_INNAK_EN_Msk);

    _USBD_SET_SETUP_BUF(USB_BUF_SETUP);
    
    /* Initial USB EP according to EP description */
    i = 0;
    while (sEpDescription[i].u32MaxPacketSize != 0)
    {
        /* Write one to clear IN/OUT ready flag */
        _USBD_SET_CFGP(i, 0x01);
        
        /* Initial USB EP CFG Setting */
        _USBD_SET_CFG(i, CFG_EP_SETTING[i]);
        _USBD_SET_EP_BUF(i, (uint32_t)sEpDescription[i].u8SramBuffer);
        i++;
    }

    psDevice->u8UsbAddress = 0;
    psDevice->u8UsbConfiguration = 0;
    
    if(psDevice->eUsbState > eUSBD_DEFAULT)
        psDevice->eUsbState = eUSBD_DEFAULT;
}

/**
  * @brief      Register USB class device to USB driver
  * @param[in]	sUsbClass   USB class structure pointer 
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    Register USB class device to USB driver
  */
void * USBD_InstallClassDevice(S_USBD_CLASS *sUsbClass)
{
    gsUsbDevice.psUsbClass = sUsbClass;

    return &gsUsbDevice;
}

/**
  * @brief      Register ctrl pipe handler
  * @param[in]	device                  USB driver device pointer
  * @param[in]	psCtrlCallbackEntry     Handler structure pointer
  * @param[in]	u32RegCnt               Handler structure size
  * @retval     E_SUCCESS               Success
  *			    E_USBD_NULL_POINTER     NULL function pointer
  * @details    Register ctrl pipe handler including SETUP ACK , IN ACK, OUT ACK handler 
  *             for Standard/Vendor/Class command
  */
int32_t USBD_InstallCtrlHandler(void * *device, 
                S_USBD_CTRL_CALLBACK_ENTRY *psCtrlCallbackEntry,uint32_t u32RegCnt)
{
    S_USBD_DEVICE *pDevice = (S_USBD_DEVICE *)device;
    S_USBD_CTRL_CALLBACK_ENTRY *psEntry;
    int i;

    if (u32RegCnt == 0)
    {
        return 0;
    }

    if (psCtrlCallbackEntry == 0)
    {
        return E_USBD_NULL_POINTER;
    }
    
    pDevice->pCtrlCallback = psCtrlCallbackEntry;
    pDevice->CtrlCallbackSize = u32RegCnt;
    
    for (i = 0; i < u32RegCnt; i++)
    {
        psEntry = psCtrlCallbackEntry + i;
        
        if (psEntry->pfnCtrlDataInCallback == NULL)
            psEntry->pfnCtrlDataInCallback = USBD_CtrlDataInDefault;
        if (psEntry->pfnCtrlDataOutCallback == NULL)
            psEntry->pfnCtrlDataOutCallback = USBD_CtrlDataOutDefault;
    }

    return 0;
}

/**
  * @brief      Callback function for SETUP ack
  * @param[in]	pArgu       Parameter passed by g_sBusOps[]
  * @details    When SETUP ack interrupt happen, this function will be called. it will call SETUP handler 
  *             that USBD_InstallCtrlHandler registered base on command category and command.
  */

void USBD_CtrlSetupAck(void * pArgu)
{
    uint32_t i;
    E_USBD_STATE eUsbState;
    S_USBD_CTRL_CALLBACK_ENTRY *psEntry = 0;
    S_USBD_DEVICE *psDevice = &gsUsbDevice;
    uint8_t * SetupBuffer;
    volatile int32_t u32Delay;

    USBD_ClrCtrlReady();
    

    /* check if after DEFAULT state (RESET) */
    eUsbState = USBD_GetUsbState();
    if (eUsbState < eUSBD_DEFAULT)
    {
        USBD_ClrCtrlReadyAndTrigStall();
        return;
    }
    SetupBuffer = (uint8_t *)USBD_GetSetupBuffer();
    
    u32Delay = 0x1000;
    while(u32Delay--);

    for (i = 0; i < 8; i++)
    {
        psDevice->au8Setup[i] = SetupBuffer[i];
    }
    u32Delay = 0x1000;
    while(u32Delay--);


    for (i = 0; i < psDevice->CtrlCallbackSize; i++)
    {
        psEntry = psDevice->pCtrlCallback + i;
        if (psEntry->pfnCtrlSetupCallback &&
            psEntry->u8RequestType == (psDevice->au8Setup[0] & 0x60) &&
            psEntry->u8Request == psDevice->au8Setup[1])
        {
            psEntry->pfnCtrlSetupCallback(psEntry->pVoid);
            return;
        }
    }
    USBD_ClrCtrlReadyAndTrigStall();
    return;
}

/**
  * @brief      Callback function for control data IN.
  * @param[in]	pArgu       Parameter passed by g_sBusOps[]
  * @details    When IN ack interrupt happen, this function will be called. it will call IN ACK 
  *             handler that USBD_InstallCtrlHandler registered base on command category and command.
  */
void USBD_CtrlDataInAck(void * pArgu)
{
    uint32_t i;
    S_USBD_CTRL_CALLBACK_ENTRY *psEntry = 0;
    S_USBD_DEVICE *psDevice = &gsUsbDevice;

    for (i = 0; i < psDevice->CtrlCallbackSize; i++)
    {
        psEntry = psDevice->pCtrlCallback + i;
        if (psEntry->pfnCtrlDataInCallback &&
            psEntry->u8RequestType == (psDevice->au8Setup[0] & 0x60) &&
            psEntry->u8Request == psDevice->au8Setup[1])
        {
            psEntry->pfnCtrlDataInCallback(psEntry->pVoid);
            return;
        }
    }
    return;
}

/**
  * @brief      Callback function for control data OUT.
  * @param[in]	pArgu       Parameter passed by g_sBusOps[]
  * @details    When OUT ack interrupt happen, this function will be called. it will call OUT handler 
  *             that USBD_InstallCtrlHandler registered base on command category and command.
  */
void USBD_CtrlDataOutAck(void * pArgu)
{
    uint32_t i;
    S_USBD_CTRL_CALLBACK_ENTRY *psEntry = 0;
    S_USBD_DEVICE *psDevice = &gsUsbDevice;

    for (i = 0; i < psDevice->CtrlCallbackSize; i++)
    {
        psEntry = psDevice->pCtrlCallback + i;
        if (psEntry->pfnCtrlDataOutCallback &&
            psEntry->u8RequestType == (psDevice->au8Setup[0] & 0x60) &&
            psEntry->u8Request == psDevice->au8Setup[1])
        {
            psEntry->pfnCtrlDataOutCallback(psEntry->pVoid);
            return;
        }
    }
    return;
}

/**
  * @brief      IN ACK default handler.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    IN ACK default handler
  */
void USBD_CtrlDataInDefault(void * pVoid)
{
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;
    
    if (pInfraDevice->au8Setup[0] & 0x80)
    {
        _USBD_TRIG_EP(1, 0x00);
    }
}

/**
  * @brief      OUT ACK default handler.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    OUT ACK default handler. It is used to return zero data length packet when next IN token. 
  */
void USBD_CtrlDataOutDefault(void * pVoid)
{
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;
    
    if ((pInfraDevice->au8Setup[0] & 0x80) == 0)
    {
        USBD_DataIn(0, NULL, 0);
    }
}

/**
  * @brief      Reset USB endpoints
  * @param[in]	u32EpNum    EP number
  * @details    Restore CFGx and CFGPx register
  */
void USBD_Reset(uint32_t u32EpNum)
{
    uint32_t u32EpId;
    u32EpId = USBD_GetEpIdentity(u32EpNum, EP_INPUT);
    
    if(u32EpId != (uint32_t)E_USBD_INVALID_EP_NUM)
    {
        _USBD_SET_CFG(u32EpId,  CFG_EP_SETTING[u32EpId]);
        _USBD_SET_CFGP(u32EpId, CFGP_CLRRDY);
    }

    u32EpId = USBD_GetEpIdentity(u32EpNum, EP_OUTPUT);
    
    if(u32EpId != (uint32_t)E_USBD_INVALID_EP_NUM)
    {
        _USBD_SET_CFG(u32EpId,  CFG_EP_SETTING[u32EpId]);
        _USBD_SET_CFGP(u32EpId, CFGP_CLRRDY);
    }


}

/**
  * @brief      Clear ctrl pipe ready flag
  * @details    Clear ctrl pipe ready flag that was set by MXPLD
  */
void USBD_ClrCtrlReady(void)
{
    uint32_t u32EpId;

    u32EpId = USBD_GetEpIdentity(0, EP_OUTPUT);
    _USBD_CLEAR_EP_READY(u32EpId);
    u32EpId = USBD_GetEpIdentity(0, EP_INPUT);
    _USBD_CLEAR_EP_READY(u32EpId);
}

/**
  * @brief      Clear ctrl pipe ready flag that was set by MXPLD and send stall.
  * @details    Clear ctrl pipe ready flag that was set by MXPLD and send stall.
  */
void USBD_ClrCtrlReadyAndTrigStall(void)
{
    uint32_t u32EpId;

    u32EpId = USBD_GetEpIdentity(0, EP_OUTPUT);
    _USBD_CLEAR_EP_READY_AND_TRIG_STALL(u32EpId);
    u32EpId = USBD_GetEpIdentity(0, EP_INPUT);
    _USBD_CLEAR_EP_READY_AND_TRIG_STALL(u32EpId);
}

/**
  * @brief      Get setup buffer address in USB SRAM.
  * @param[in]	pVoid	User interrupt callback function, it will be called in USB IRQ Handler
  * @retval     Setup   buffer address
  * @details    Get setup buffer address in USB SRAM.
  */
uint32_t USBD_GetSetupBuffer(void)
{
    return (uint32_t)gsUsbDevice.sEpCrl[MAX_EP_ID].u8SramBuffer;
}

/**
  * @brief      Get free USB SRAM buffer address.
  * @retval     Free USB SRAM address
  * @details    Get free USB SRAM buffer address after EP assign base on sEpDescription[i].u32MaxPacketSize 
  *             in USBD_Open User can get this for dual buffer.
  */
uint32_t USBD_GetFreeSRAM(void)
{
    return (uint32_t)g_UsbSramBase;
}

/**
  * @brief      Enable self power attribution.
  */
void USBD_EnableSelfPower (void)
{   
    gsUsbDevice.bSelfPowered = 1; 
}

/**
  * @brief      Disable self power attribution.
  */
void USBD_DisableSelfPower(void)
{   
    gsUsbDevice.bSelfPowered = 0; 
}

/**
  * @brief      Self-power is enabled or disabled
  * @retval     1       Self-Powereded  
  *			    0       BUS-Powereded     
  * @details    Self-power is enabled or disabled
  */
int32_t USBD_IsSelfPowerEnabled(void)
{
    return gsUsbDevice.bSelfPowered;
}

/**
  * @brief      Enable remote wakeup attribution.
  */
void USBD_EnableRemoteWakeup(void)
{   
    gsUsbDevice.bRemoteWakeup = 1;  
}

/**
  * @brief      Disable remote wakeup attribution.
  */
void USBD_DisableRemoteWakeup(void)
{   
    gsUsbDevice.bRemoteWakeup = 0;
}

/**
  * @brief       Remote wakeup is enabled or disabled.
  * @retval      1   Support RemoteWakeup
  *			     0   Not support
  * @details     Remote wakeup is enabled or disabled.
  */
int32_t USBD_IsRemoteWakeupEnabled(void)
{
    return gsUsbDevice.bRemoteWakeup;
}

/**
  * @brief      Configure max power.
  * @param[in]	u32MaxPower Max power value
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    Configure max power. Maximum MaxPower 0xFA (500mA), default is 0x32 (100mA)
  */
int32_t USBD_SetMaxPower(uint32_t u32MaxPower)
{   
    
    if (u32MaxPower > 0xFA)
    {
        return E_USBD_VALUE_INVALID;
    }
    
    gsUsbDevice.u8MaxPower = (uint8_t)u32MaxPower;
    
    return 0;
}

/**
  * @brief      Get current max power.
  * @details    Get current max power. Maximum MaxPower 0xFA (500mA), default is 0x32 (100mA)
  */
int32_t USBD_GetMaxPower(void)
{   
    return ((int32_t) gsUsbDevice.u8MaxPower);
}

/**
  * @brief      Enable USB and PHY
  * @param[in]	psDevice    USB driver device pointer
  * @details    Enable USB and PHY
  */
void USBD_EnableUsb(S_USBD_DEVICE *psDevice)
{
    _USBD_ENABLE_USB();   /* enable USB & PHY */
}

/**
  * @brief      Disable USB and PHY.
  * @param[in]	psDevice    USB driver device pointer
  * @details    Disable USB and PHY.
  */
void USBD_DisableUsb(S_USBD_DEVICE *psDevice)
{
    _USBD_DISABLE_USB();  /* disable USB & PHY */
}

/**
  * @brief      Wakeup event handler.
  * @param[in]	psDevice    USB driver device pointer
  * @details    Wakeup event handler.
  */
void USBD_PreDispatchWakeupEvent(S_USBD_DEVICE *psDevice)
{

}

/**
  * @brief      Pre dispatch plug-in and plug-out event.
  * @param[in]	psDevice    USB driver device pointer
  * @details    Pre dispatch plug-in and plug-out event.
  */
void USBD_PreDispatchFDTEvent(S_USBD_DEVICE *psDevice)
{
    /* Clear all pending events on USB attach/detach to
       handle the scenario that the time sequence of event happening
       is different from that of event handling. */

    uint32_t u32FLDET = psDevice->u32FLDET;
    
    if (u32FLDET & 1)
    {
        /* attached */
        if (psDevice->eUsbState == eUSBD_DETACHED)
        {
            psDevice->eUsbState = eUSBD_ATTACHED;
            USBD_EnableUsb(psDevice);
        }

        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_ATTACH;
    }
    else
    {
        /* detached */
        psDevice->eUsbState = eUSBD_DETACHED;
        USBD_DisableUsb(psDevice);

        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_DETACH;
    }
}

/**
  * @brief      Pre dispatch BUS event
  * @param[in]	psDevice    USB driver device pointer
  * @details    Pre dispatch BUS event
  */
void USBD_PreDispatchBusEvent(S_USBD_DEVICE *psDevice)
{
    uint32_t u32Attr = psDevice->u32ATTR;

    if (psDevice->eUsbState == eUSBD_DETACHED)
    {
        /* There should be something wrong */
        return;
    }

    if (u32Attr & ATTR_USBRST)
    {
        /* Bus reset */
        _USBD_ENABLE_USB(); /* enable USB & PHY */
        psDevice->eUsbState = eUSBD_DEFAULT;
        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_BUS_RESET;
    }
    else if (u32Attr & ATTR_SUSPEND)
    {
        /* Bus suspend */
        _USBD_DISABLE_PHY(); /* disable PHY */
        if (psDevice->eUsbState >= eUSBD_ATTACHED)
        {
            psDevice->eUsbState |= eUSBD_SUSPENDED;
        }
        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_BUS_SUSPEND;

    }
    else if (u32Attr & ATTR_RESUME)
    {
        /* Bus resume */
        _USBD_ENABLE_USB(); /* enable PHY */
        if (psDevice->eUsbState >= eUSBD_ATTACHED)
        {
            psDevice->eUsbState &= ~eUSBD_SUSPENDED;
        }
        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_BUS_RESUME;
    }
}

/**
  * @brief      Pre dispatch EP event.
  * @param[in]	psDevice    USB driver device pointer
  * @details    Pre dispatch EP event.
  */
void USBD_PreDispatchEPEvent(S_USBD_DEVICE *psDevice)
{
    uint32_t u32EpNum;
    uint32_t u32EpId;
    uint32_t u32INTSTS = psDevice->u32INTSTS;
    uint32_t u32EPSTS = psDevice->u32EPSTS;
    uint32_t u32PacketType;
    uint32_t u32ISOPacketType;
    int32_t i;
        
    if (psDevice->eUsbState == eUSBD_DETACHED)
    {
        /* There should be something wrong. */
        return;
    }

    /* Only care EP events and Setup event */
    u32INTSTS &= (INTSTS_EPTF0 | INTSTS_EPTF1 | INTSTS_EPTF2 | INTSTS_EPTF3 | INTSTS_EPTF4 | INTSTS_EPTF5 | INTSTS_SETUP);

    if (u32INTSTS & INTSTS_SETUP)
    {
        /* Record the event to procee it later */
        psDevice->u16MiscEventFlags |= USBD_EVENT_FLAG_SETUP;
        
        /* Clear setup event flag */
        _USBD_SET_EVENT_FLAG(INTSTS_SETUP);
        
        /* Assign the toggle bit for data phase */
        psDevice->abData0[0] = 1;
    }
    
    u32INTSTS = inp32(&USBD->INTSTS); 
    outp32(&USBD->INTSTS, (u32INTSTS & 0x00FF0000UL));

    for (i=16;i<16+MAX_EP_ID;i++)
    {
        if (u32INTSTS & (1 << i))
        {
            u32EpId = i - 16;

            /* Get the address of EP */
            u32EpNum = (_USBD_GET_CFG(u32EpId) & CFG_EPT);    
            
            u32PacketType = ((u32EPSTS >> (4 + u32EpId * 3)) & EPSTS_STS);
            
            if (u32PacketType == EPSTS_IN_ACK)
            {
                /* Set this EP event as non-handled. */
                psDevice->u16EPEventFlags |= (1 << (u32EpNum*2));
            }
            else if(u32PacketType == EPSTS_OUT0_ACK)
            {
                /* Set this EP event as non-handled. */
                psDevice->u16EPEventFlags |= (1 << (u32EpNum*2 + 1));
                
                /* Assign the toggle bit of data packet */
                psDevice->abData0[u32EpId] = 1;
            }
            else if(u32PacketType == EPSTS_OUT1_ACK)
            {
                /* Set this EP event as non-handled. */
                psDevice->u16EPEventFlags |= (1 << (u32EpNum*2 + 1));
                
                /* Assign the toggle bit of data packet */
                psDevice->abData0[u32EpId] = 0;
            }
            else if(u32PacketType == EPSTS_ISO)
            {
                u32ISOPacketType = (_USBD_GET_CFG(u32EpId) & CFG_STATE);
                
                psDevice->abData0[u32EpId] = 0;
                
                if (u32ISOPacketType == 0x20)
                {
                    /* This is isochronous out translation end. Call relative handler */
                    if(g_sUsbOps[u32EpNum*2 + 1].apfnCallback != 0)
                    {
                        g_sUsbOps[u32EpNum*2 + 1].apfnCallback(g_sUsbOps[u32EpNum*2 + 1].apCallbackArgu);
                    }
                }
                else if(u32ISOPacketType == 0x40)
                {
                    /* This is isochronous in translation end. Call relative handler */
                    if (g_sUsbOps[u32EpNum*2].apfnCallback != 0)
                    {
                        g_sUsbOps[u32EpNum*2].apfnCallback(g_sUsbOps[u32EpNum*2].apCallbackArgu);
                    }
                }
            }
        }
    }
}

/**
  * @brief      For wakeup event dispatch
  * @param[in]	psDevice    USB driver device pointer
  * @details    For wakeup event dispatch
  */
void USBD_DispatchWakeupEvent(S_USBD_DEVICE *psDevice)
{

}

/**
  * @brief      Dispatch Misc event.
  * @param[in]	psDevice    USB driver device pointer
  * @details    Dispatch Misc event, the event is set by pre dispatch misc event include 
  *             attach/detach/bus reset/bus suspend/bus resume and setup ACK, Misc event'handler is g_sBusOps[]
  */
void USBD_DispatchMiscEvent(S_USBD_DEVICE *psDevice)
{
    uint16_t u16MiscEventFlags;
    int32_t i;
    
    u16MiscEventFlags = psDevice->u16MiscEventFlags;
    for (i=0;i<6;i++)
    {
        if (u16MiscEventFlags & (1 << i))
        {           
            psDevice->u16MiscEventFlags &= ~(1 << i);
        
            if (g_sBusOps[i].apfnCallback != 0)
            {
                g_sBusOps[i].apfnCallback(g_sBusOps[i].apCallbackArgu);
            }
        }
    }   
}

/**
  * @brief      Dispatch EP event.
  * @param[in]	pVoid	User interrupt callback function, it will be called in USB IRQ Handler
  * @details    Dispatch EP event, the event is set by pre dispatch EP event include 
  *             IN ACK/IN NAK/OUT ACK/ISO end, EP event'handler is g_sUsbOps[].
  */
void USBD_DispatchEPEvent(S_USBD_DEVICE *psDevice)
{
    int32_t i;
    
    for (i=0;i<12;i++)
    {
        if ((psDevice->u16EPEventFlags >> i)&1)
        {
            psDevice->u16EPEventFlags &= ~(1 << i);
            /* Call the corresponding event handler. */
            if (g_sUsbOps[i].apfnCallback != 0)
            {
                g_sUsbOps[i].apfnCallback(g_sUsbOps[i].apCallbackArgu);
            }       
        }
    }
}

/**
  * @brief      USB init to enable USB clock and reset USB.
  * @retval     0           Success
  *			    Otherwise   Error
  * @details    USB init to enable USB clock and reset USB.
  */
static int32_t USBD_Init(void)
{
    uint32_t temp;
    volatile int32_t delay;
 
    /* Enable USB Clock */
    SYSCLK->APBCLK |= SYSCLK_APBCLK_USBD_EN_Msk;

    /* Reset USB */
    SYS->IPRSTC2 |= SYS_IPRSTC2_USBD_RST_Msk;
    delay = 500;
    while(delay--);
    SYS->IPRSTC2 ^= SYS_IPRSTC2_USBD_RST_Msk;

    _USBD_ENABLE_USB();
    _USBD_ENABLE_SE0();   
    temp = 0x100;
    while(temp--);   
    _USBD_DISABLE_SE0();
    
    return 0;
}

/**
  * @brief      Disable USB and its clock.
  */
static void USBD_UnInit(void)
{
    /* Disable USB */
    _USBD_DISABLE_USB();
    
    /* Disable the USB clock */
    SYSCLK->APBCLK &= (~SYSCLK_APBCLK_USBD_EN_Msk);
}

/**
  * @brief      Setup ACK handler for set address command
  * @param[in]	pVoid       parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler for set address command
  */
void USBD_CtrlSetupSetAddress(void * pVoid)
{
    E_USBD_STATE eUsbState;
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;   

    eUsbState = USBD_GetUsbState();
    if (eUsbState == eUSBD_DEFAULT)
    {
        pInfraDevice->u8UsbAddress = pInfraDevice->au8Setup[2];
        _USBD_SET_EP_TOG_BIT(0, 0);
        _USBD_TRIG_EP(0, 0);

        USBD_SetUsbState(eUSBD_ADDRESS);

    }
    else
    {
        USBD_ClrCtrlReadyAndTrigStall();
    }
}

/**
  * @brief      Setup ACK handler for clear feature command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler for clear feature command.
  */
void USBD_CtrlSetupClearSetFeature(void * pVoid)
{
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;
    uint32_t u32EpId;
    
    /* Device */
    if ((pInfraDevice->au8Setup[0] == 0x00) && (pInfraDevice->au8Setup[2] == FEATURE_DEVICE_REMOTE_WAKEUP))
    {
        if(pInfraDevice->au8Setup[1] == SET_FEATURE)
            USBD_EnableRemoteWakeup();
        if(pInfraDevice->au8Setup[1] == CLEAR_FEATURE)
            USBD_DisableRemoteWakeup();
    }
    /* Interface */
    else if (pInfraDevice->au8Setup[0] == 0x01);
    
    /* Endpoint */
    else if ((pInfraDevice->au8Setup[0] == 0x02) && (pInfraDevice->au8Setup[2] == FEATURE_ENDPOINT_HALT))
    {
        u32EpId = USBD_GetEpId(pInfraDevice->au8Setup[4]);
        
        if (u32EpId < MAX_EP_ID)
        {
            _USBD_CLEAR_EP_DSQ_SYNC(u32EpId);
            if (pInfraDevice->au8Setup[1] == CLEAR_FEATURE)
            {
                _USBD_CLEAR_EP_STALL(u32EpId);
            }
            else
            {
                _USBD_TRIG_EP_STALL(u32EpId);
            }
        }
        else
        {
            USBD_ClrCtrlReadyAndTrigStall();
        }
    }
    else
    {
        USBD_ClrCtrlReadyAndTrigStall();
    }

    USBD_DataIn(0, NULL, 0);  
}

/**
  * @brief      Setup ACK handler for Get configuration command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler for Get configuration command.
  */
void USBD_CtrlSetupGetConfiguration(void * pVoid)
{
    USBD_DataIn(0, &gsUsbDevice.u8UsbConfiguration, 1);   
}

/**
  * @brief      Setup ACK handler Get status command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler Get status command.
  */
void USBD_CtrlSetupGetStatus(void * pVoid)
{
    uint8_t au8Buf[4];
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;
    uint32_t u32EpId;
    
    u32EpId = USBD_GetEpId(pInfraDevice->au8Setup[4]);

    if (pInfraDevice->au8Setup[0] == 0x80)
    {
        au8Buf[0] = pInfraDevice->bRemoteWakeup << 1 | pInfraDevice->bSelfPowered;
    }
    else if (pInfraDevice->au8Setup[0] == 0x81)
    {
        au8Buf[0] = 0x00;
    }
    else if (pInfraDevice->au8Setup[0] == 0x82)
    {
        if (u32EpId < MAX_EP_ID)
        {
            /* Interrupt-In Endpoint */
            au8Buf[0] = (_USBD_GET_CFGP(u32EpId) & CFGP_SSTALL) ? 1 : 0;
        }
        else
        {
            USBD_ClrCtrlReadyAndTrigStall();
            return;
        }
    }
    else
    {
        USBD_ClrCtrlReadyAndTrigStall();
        return;
    }
    au8Buf[1] = 0x00;

    USBD_DataIn(0, au8Buf, 2);    
}

/**
  * @brief      Setup ACK handler for Get interface command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler for Get interface command.
  */
void USBD_CtrlSetupGetInterface(void * pVoid)
{
    const uint8_t c = 0x00;

    USBD_DataIn(0, &c, 1);    
}

/**
  * @brief      Setup ACK handler for Set interface command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler 
  * @details    Setup ACK handler for Set interface command.
  */
void USBD_CtrlSetupSetInterface(void * pVoid)
{
    S_USBD_DEVICE *pDrvDevice = &gsUsbDevice;
    S_USBD_CLASS *psUsbClass = pDrvDevice->psUsbClass;
    
    if(psUsbClass->pfnStart)
        psUsbClass->pfnStart(pVoid);

    USBD_DataIn(0, NULL, 0);
}

/**
  * @brief      Setup ACK handler for Set configuration command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler
  * @details    Setup ACK handler for Set configuration command.
  */
void USBD_CtrlSetupSetConfiguration(void * pVoid)
{
    S_USBD_DEVICE *pDrvDevice = &gsUsbDevice;
    S_USBD_CLASS *psUsbClass = pDrvDevice->psUsbClass;
    int32_t bIsDeviceConfigure;
    
    bIsDeviceConfigure = psUsbClass->pfnCompare ? psUsbClass->pfnCompare(pDrvDevice->au8Setup[2]) : 1;
    
    if (pDrvDevice->au8Setup[2] == 0)
    {
        /* USB address state */
        USBD_SetUsbState(eUSBD_ADDRESS);
        pDrvDevice->u8UsbConfiguration = pDrvDevice->au8Setup[2];
        USBD_DataIn(0, NULL, 0);
    }
    else if (bIsDeviceConfigure)
    {
        /* USB configured state */
        USBD_SetUsbState(eUSBD_CONFIGURED);

        /* Call USB class's start function */
        if(psUsbClass->pfnStart)
            psUsbClass->pfnStart(pVoid);

        pDrvDevice->u8UsbConfiguration = pDrvDevice->au8Setup[2];

        USBD_DataIn(0, NULL, 0);
    }
    else
    {
        /* Not support. Reply STALL */
        USBD_ClrCtrlReadyAndTrigStall();
    }   
}

/**
  * @brief      Setup ACK handler for Set address command.
  * @param[in]	pVoid       Parameter passed by USBD_InstallCtrlHandler 
  * @details    Setup ACK handler for Set address command.
  */
void USBD_CtrlDataInSetAddress(void * pVoid)
{
    S_USBD_DEVICE *pInfraDevice = &gsUsbDevice;

    if (pInfraDevice->u8UsbAddress == 0x00)
    {
        USBD_SetUsbState(eUSBD_DEFAULT);
    }
    else
    {
        USBD_SetUsbState(eUSBD_ADDRESS);
        _USBD_SET_FADDR(pInfraDevice->u8UsbAddress);
    }   
}


/**
  * @brief      The USB buffer is recommended to be byte access.
  * @param[in]	pi8Dest     Destination pointer.
  * @param[in]	pi8Src      Source pointer.
  * @param[in]	u32Size     Data size. The unit is byte.
  * @details    The USB buffer is recommended to be byte access.
  */
void USBD_memcpy(uint8_t *pi8Dest, uint8_t *pi8Src, uint32_t u32Size)
{
    int32_t i;
    
    for(i=0;i<u32Size;i++)
    {
        pi8Dest[i] = pi8Src[i];
    }

}
