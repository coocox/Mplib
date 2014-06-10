/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>

/*---------------------------------------------------------------------------------------------------------*/
/* Includes of headers                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
#include "CAN.h"
                                                     

/* Private function prototypes -----------------------------------------------*/
static uint32_t GetFreeIF(void);

/* Private functions ---------------------------------------------------------*/
static STR_CAN_CALLBACK_T CANHandler = {0};

//#define DEBUG_PRINTF printf
#define DEBUG_PRINTF(...)
/*---------------------------------------------------------------------------------------------------------*/
/* CAN0 ISR                                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/
void CAN0_IRQHandler(void)
{
	uint8_t u8IIDRstatus;

    if(CAN->IIDR == 0x8000)     	  /* Check Status Interrupt Flag (Error status Int and Status change Int) */
	{
		/**************************/
		/* Status Change interrupt*/
		/**************************/
		
        if(CAN->STATUS & CAN_STATUS_RXOK_Msk)
        {
            CAN->STATUS ^= CAN_STATUS_RXOK_Msk;    /* Clear Rx Ok status*/
            
            DEBUG_PRINTF("RX OK INT\n") ;   		

            if (CANHandler.RxOkCallBackFn)
	    	{
		    	CANHandler.RxOkCallBackFn(0); 
		    }
        }

        if(CAN->STATUS & CAN_STATUS_TXOK_Msk)
		{
            CAN->STATUS ^= CAN_STATUS_TXOK_Msk;    /* Clear Tx Ok status*/
            
			DEBUG_PRINTF("TX OK INT\n") ; 

            if (CANHandler.TxOkCallBackFn)
	    	{
		    	CANHandler.TxOkCallBackFn(0); 
		    }
        }
		/**************************/
		/* Error Status interrupt */
		/**************************/
        if(CAN->STATUS & CAN_STATUS_EWARN_Msk)
        {
            DEBUG_PRINTF("EWARN INT\n") ; 

            if (CANHandler.ErrorWarningCallBackFn)
	    	{
		    	CANHandler.ErrorWarningCallBackFn(0); 
		    }
        }

        if(CAN->STATUS & CAN_STATUS_BOFF_Msk)
        {
            DEBUG_PRINTF("BOFF INT\n") ; 
        
            if (CANHandler.BusOffCallBackFn)
	    	{
		    	CANHandler.BusOffCallBackFn(0); 
		    }
        }
	}

	else if ((CAN->IIDR)!=0)
	{                       
        DEBUG_PRINTF("=> Interrupt Pointer = %d\n",CAN->IIDR - 1);

		u8IIDRstatus = CAN->IIDR;
		
        if (CANHandler.MessageCallBackFn)
  	    {
		    CANHandler.MessageCallBackFn(u8IIDRstatus); 
		}    

		CAN_ClrIntPnd((CAN->IIDR) - 1);	   /* Clear Interrupt Pending */

	}

    else if(CAN->WU_STATUS==1)
    {
        DEBUG_PRINTF("Wake up\n");

        CAN->WU_STATUS = 0;     				   /* Write '0' to clear */

        if (CANHandler.WakeupCallBackFn)
	    {
		    CANHandler.WakeupCallBackFn(0); 
		}    
    }

}

/**
  * @brief      Check if SmartCard slot is presented.
  * @retval     0   IF0 is free  
  * @retval     1   IF1 is free   
  * @retval     2   No IF is free 
  * @details    Searchs the first free message interface, starting from 0.
  */
static uint32_t GetFreeIF(void)
{
    if((CAN->IF[0].CREQ & CAN_IF_CREQ_BUSY_Msk) == 0)
        return 0;
    else if((CAN->IF[1].CREQ  & CAN_IF_CREQ_BUSY_Msk) == 0)
        return 1;
    else
   	    return 2;
}


/**
  * @brief      Get current bit rate
  * @retval     Current Bit-Rate (kilo bit per second)
  * @details    Return current CAN bitrate according to the user bit-timing parameter settings
  */

int32_t CAN_GetCANBitRate(void)
{
    uint8_t u8Tseg1,u8Tseg2;    
    uint32_t u32Bpr;

    u8Tseg1 = (CAN->BTIME & CAN_BTIME_TSEG1_Msk) >> CAN_BTIME_TSEG1_Pos;
    u8Tseg2 = (CAN->BTIME & CAN_BTIME_TSEG2_Msk) >> CAN_BTIME_TSEG2_Pos;;
    u32Bpr  = (CAN->BTIME & CAN_BTIME_BRP_Msk) | (CAN->BRPE << 6);
    return (SystemCoreClock/(u32Bpr+1)/(u8Tseg1 + u8Tseg2 + 3))/1000;
}


/**
  * @brief      Init CAN driver
  */
                                                                                                            
void CAN_Init(void)
{
}


/**
  * @brief      Disable CAN
  * @details    Reset and clear all CAN control and disable CAN IP
  */

void CAN_Close(void)
{
	/* Clear Install callback function pointer */
	CANHandler.MessageCallBackFn            = NULL; 
    CANHandler.RxOkCallBackFn               = NULL;    
    CANHandler.TxOkCallBackFn               = NULL;    
    CANHandler.ErrorWarningCallBackFn       = NULL;    
    CANHandler.BusOffCallBackFn             = NULL;    
    CANHandler.WakeupCallBackFn             = NULL;    
      
    /* Disable CAN0 Clock and Reset it */
    
    SYS->IPRSTC2 |= SYS_IPRSTC2_CAN0_RST_Msk;
    SYS->IPRSTC2 ^= SYS_IPRSTC2_CAN0_RST_Msk;
    
    SYSCLK->APBCLK |= SYSCLK_APBCLK_CAN0_EN_Msk;

}
     

/**
  * @brief      Enable CAN controller
  * @param[in]	u32kbps: The target CAN kilo bit rate per second. The range of u32kbps is 1~1000KHz
  * @retval     E_CAN_ERR_BITRATE   Set target bit-rate fail
  * @retval     E_SUCCESS           Set target bit-rate successful
  * @details    The function is used to set bus timing parameter according current clock and target bit-rate.
  */

int32_t CAN_Open(uint32_t u32kbps)
{
    uint8_t u8Tseg1,u8Tseg2;    
    uint32_t u32Brp;
    uint32_t u32Value;

    CAN_EnterInitMode();

    u8Tseg1 = 2;
    u8Tseg2 = 3;

    u32Value = SystemCoreClock/1000;
    if(u32kbps * 8 < (u32Value / 2))
        u32Brp = SystemCoreClock / (u32kbps * 1000) / (u8Tseg1 + u8Tseg2 + 3) - 1;
    else
    {
        u8Tseg1 = 2;
        u8Tseg2 = 1;
        u32Brp  = SystemCoreClock/(u32kbps*1000) / (u8Tseg1 + u8Tseg2 + 3) -1;
    }

    u32Value = ((uint32_t)u8Tseg2 << CAN_BTIME_TSEG2_Pos) | ((uint32_t)u8Tseg1 << CAN_BTIME_TSEG1_Pos) | 
               (u32Brp & CAN_BTIME_BRP_Msk) | (CAN->BTIME & CAN_BTIME_SJW_Msk);
    CAN->BTIME = u32Value;
    CAN->BRPE     = (u32Brp >> 6) & 0x0F;
    
    /* Check the result is OK */
    if ((u32kbps < (CAN_GetCANBitRate()*95/100)) || (u32kbps > (CAN_GetCANBitRate()*105/100)))
    {
        DEBUG_PRINTF("\nCurrent CAN bitrate = %d\n",CAN_GetCANBitRate());
        return E_CAN_ERR_BITRATE;        
    }

	CAN_LeaveInitMode();
    return E_SUCCESS;

}

/**
  * @brief      Set CAN timing
  * @param[in]	u8Tseg1     Specifies Time Segment before the sample point. This parameter must be a number between 1 and 16.
  * @param[in]	u8Tseg2     Time Segment after the sample point. This parameter must be a number between 1 and 8.
  * @param[in]	u8Sjw       Synchronisation Jump Width. This parameter must be a number between 1 and 4.
  * @param[in]	u32Brp      Baud Rate Prescaler. This parameter must be a number between 1 and 1024.
  * @details    Setups the CAN timing with specific parameters. 
  *             CAN bit-rate calculation equation as below:
  *                                                                                                         
  *                                                                                                      
  *              Bit-Rate (kbps) = Fin / (u32Brp + 1) x (u8Tseg1 + u8Tseg1 +3)
  *                                                                    
  *                                                                                                         
  *                   where: Fin   : System clock freq. (Hz)                                                
  *                          u32Brp: the baud rate prescale .You can set brp bit field of BTIME register    
  *                                   BRPE bit feild in BRPE reigster                                       
  *                          u8Tseg1: Time Segment before the sample point.                                 
  *                                   You can set tseg1 bit field of BTIME register                         
  *                          u8Tseg2: Time Segment ater the sample point.                                   
  *                                   You can set tseg2 bit field of BTIME register                         
  *                          u32Brp:  The baud rate prescale.                                               
  *                                   It is composed of BRP in CAN_BTIME register and BRPE                  
  *                                   in CAN_BRPE register.                                                 
  *              Example:                                                                                           
  *              Assume System clock Fin = 16MHz, and set u32Brp=1,u8Tseg1=2,u8Tseg2=3                    
  *                                                                                                         
  *              According above equations:                                                                 
  *                                                                                                 
  *                    CAN bit-rate = 16000000/(1 + 1) x ( 2 + 3 + 3) =  1MHz                                    
  *                                                                                   
  *                                                                                                           
  */

void CAN_SetTiming(uint8_t u8Tseg2, uint8_t u8Tseg1, uint8_t u8Sjw, uint32_t u32Brp)
{
    uint32_t u32Reg;
    
    u32Reg = ((uint32_t)u8Tseg2 << CAN_BTIME_TSEG2_Pos) | ((uint32_t)u8Tseg1 << CAN_BTIME_TSEG1_Pos) |
             ((uint32_t)u8Sjw << CAN_BTIME_SJW_Pos) | (u32Brp & CAN_BTIME_BRP_Msk);
    CAN->BTIME = u32Reg;

    CAN->BRPE     = u32Brp >> 6;
}



/**
  * @brief      Configures the target message object as default
  * @param[in]	u8MsgObj    specifies the Message object number, from 0 to 31.
  * @retval     E_SUCCESS                   SUCCESS 
  * @retval     E_CAN_NO_USEFUL_INTERFACE   No useful interface
  * @details    Configures the target message object as default.
  */

int32_t CAN_ResetMsgObj(uint8_t u8MsgObj)
{
    uint8_t u8MsgIfNum=0;

    if ((u8MsgIfNum = GetFreeIF()) == 2)
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }

    CAN->IF[u8MsgIfNum].CMASK  = 0xF3;  /*CAN_CMASK_WRRD| CAN_CMASK_MASK | CAN_CMASK_ARB 
                                              | CAN_CMASK_CONTROL | CAN_CMASK_DATAA  | CAN_CMASK_DATAB; */
    CAN->IF[u8MsgIfNum].MASK1  = 0;
    CAN->IF[u8MsgIfNum].MASK2  = 0;

    CAN->IF[u8MsgIfNum].ARB1   = 0;
    CAN->IF[u8MsgIfNum].ARB2   = 0;

    CAN->IF[u8MsgIfNum].MCON   = 0;
    CAN->IF[u8MsgIfNum].DAT_A1 = 0;
    CAN->IF[u8MsgIfNum].DAT_A2 = 0;
    CAN->IF[u8MsgIfNum].DAT_B1 = 0;
    CAN->IF[u8MsgIfNum].DAT_B2 = 0;

    CAN->IF[u8MsgIfNum].CREQ   = 1 + u8MsgObj;

    return E_SUCCESS;
}

/**
  * @brief      Configures all of the message objects as default.
  */

void CAN_ResetAllMsgObj(void)
{
    uint32_t i=0;
    for (i = 0; i < 32; i++)
        CAN_ResetMsgObj(i);
}


/**
  * @brief      The function is used to configure a transmit object.
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @param[in]	pCanMsg     Pointer to the message structure where received data is copied.
  * @retval     E_SUCCESS                   SUCCESS
  * @retval     E_CAN_NO_USEFUL_INTERFACE   No useful interface
  * @details    The function is used to configure a transmit object.
  */

int32_t CAN_SetTxMsgObj(uint8_t u8MsgObj, STR_CANMSG_T* pCanMsg)
{
    uint8_t u8MsgIfNum=0;

    if ((u8MsgIfNum = GetFreeIF()) == 2)                        /* Check Free Interface for configure */
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }

    /* update the contents needed for transmission*/
    CAN->IF[u8MsgIfNum].CMASK = 0xF3;  /*CAN_CMASK_WRRD| CAN_CMASK_MASK | CAN_CMASK_ARB 
                                           | CAN_CMASK_CONTROL | CAN_CMASK_DATAA  | CAN_CMASK_DATAB; */

    if (pCanMsg->IdType == CAN_STD_ID)
    {
        /* standard ID*/
        CAN->IF[u8MsgIfNum].ARB1 = 0;
		CAN->IF[u8MsgIfNum].ARB2 =  (((pCanMsg->Id)&0x7FF)<<2) | CAN_ARB2_DIR | CAN_ARB2_MSGVAL; 
    }
    else
    {
        /* extended ID*/
        CAN->IF[u8MsgIfNum].ARB1 = (pCanMsg->Id)&0xFFFF;
        CAN->IF[u8MsgIfNum].ARB2 = ((pCanMsg->Id)&0x1FFF0000)>>16 | CAN_ARB2_DIR | CAN_ARB2_XTD | CAN_ARB2_MSGVAL;
    }

    if(pCanMsg->FrameType)
        CAN->IF[u8MsgIfNum].ARB2 |=   CAN_IF_ARB2_DIR_Msk;
    else
        CAN->IF[u8MsgIfNum].ARB2 &= (~CAN_IF_ARB2_DIR_Msk);
       
    CAN->IF[u8MsgIfNum].DAT_A1 = ((uint16_t)pCanMsg->Data[1]<<8) | pCanMsg->Data[0];
    CAN->IF[u8MsgIfNum].DAT_A2 = ((uint16_t)pCanMsg->Data[3]<<8) | pCanMsg->Data[2];
    CAN->IF[u8MsgIfNum].DAT_B1 = ((uint16_t)pCanMsg->Data[5]<<8) | pCanMsg->Data[4];
    CAN->IF[u8MsgIfNum].DAT_B2 = ((uint16_t)pCanMsg->Data[7]<<8) | pCanMsg->Data[6];

	CAN->IF[u8MsgIfNum].MCON   =  CAN_MCON_NEWDAT | pCanMsg->DLC |CAN_MCON_TXIE | CAN_MCON_EOB;
    CAN->IF[u8MsgIfNum].CREQ   = 1 + u8MsgObj;

    return E_SUCCESS;
}

/**
  * @brief      Configures Mask as the message object.
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @param[in]	MaskMsg     Specifies the mask structure as message object
  *                         The structure is including:
  *                             u8Xtd ( Mask IDE bit)
  *                             u8Dir ( Mask Direction)
  *                             u32Id ( Mask ID bit)
  *                             u8IdType ( Mask ID Type)
  *                             Set '0' means DON'T CARE , disable accpetance filter    
  * @retval     E_SUCCESS                   SUCCESS
  * @retval     E_CAN_NO_USEFUL_INTERFACE   No useful interface
  * @details    Configures Mask as the message object.
  */

int32_t CAN_SetMsgObjMask(uint8_t u8MsgObj,STR_CANMASK_T* MaskMsg)
{
    uint8_t u8MsgIfNum=0;

    if ((u8MsgIfNum = GetFreeIF()) == 2)                /* Check Free Interface for configure */
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }
			 
    if (MaskMsg->u8IdType == CAN_STD_ID)	        /* standard ID*/
    {
        CAN->IF[u8MsgIfNum].MASK1 =  0;
		CAN->IF[u8MsgIfNum].MASK2 =  ((MaskMsg->u32Id&0x7FF)<<2) ; 
    }
    else										    /* extended ID*/
    {
        CAN->IF[u8MsgIfNum].MASK1 = (MaskMsg->u32Id) &0xFFFF;
        CAN->IF[u8MsgIfNum].MASK2 = ((MaskMsg->u32Id)&0x1FFF0000)>>16 ;
    }

    if(MaskMsg->u8Xtd)
        CAN->IF[u8MsgIfNum].MASK2 |= CAN_IF_MASK2_MXTD_Msk;
	else
        CAN->IF[u8MsgIfNum].MASK2 &= (~CAN_IF_MASK2_MXTD_Msk);

    if(MaskMsg->u8Dir)
        CAN->IF[u8MsgIfNum].MASK2 |= CAN_IF_MASK2_MDIR_Msk;
    else
        CAN->IF[u8MsgIfNum].MASK2 &= (~CAN_IF_MASK2_MDIR_Msk);

	CAN->IF[u8MsgIfNum].MCON |= CAN_IF_MCON_UMASK_Msk;

	/* update the contents needed for transmission*/
    CAN->IF[u8MsgIfNum].CMASK = CAN_CMASK_WRRD | CAN_CMASK_MASK;
    CAN->IF[u8MsgIfNum].CREQ  = 1 + u8MsgObj;

    return E_SUCCESS;
}


/**
  * @brief      Set Rx message object
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @param[in]	u8idType    Specifies the identifier type of the frames that will be transmitted
  *                         This parameter can be one of the following values:
  *                             CAN_STD_ID (standard ID, 11-bit)
  *                             CAN_EXT_ID (extended ID, 29-bit)
  * @param[in]	u32id       Specifies the identifier used for acceptance filtering.
  * @param[in]	u8singleOrFifoLast  Specifies the end-of-buffer indicator.
  *                                 This parameter can be one of the following values:
  *                                 TRUE: for a single receive object or a FIFO receive object that is the last one of the FIFO.
  *                                 FALSE: for a FIFO receive object that is not the last one.
  * @retval     E_SUCCESS           SUCCESS
  * @retval     E_CAN_NO_USEFUL_INTERFACE   No useful interface
  * @details    The function is used to configure a receive message object.
  */

int32_t CAN_SetRxMsgObj(uint8_t u8MsgObj, uint8_t u8idType, uint32_t u32id, uint8_t u8singleOrFifoLast)
{
    uint8_t u8MsgIfNum=0;

    if ((u8MsgIfNum = GetFreeIF()) == 2)                        /* Check Free Interface for configure */
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }
                                                                /* Command Setting */
    CAN->IF[u8MsgIfNum].CMASK = CAN_CMASK_WRRD | CAN_CMASK_MASK | CAN_CMASK_ARB | 
	                            CAN_CMASK_CONTROL | CAN_CMASK_DATAA | CAN_CMASK_DATAB;

    if (u8idType == CAN_STD_ID) /* According STD/EXT ID format,Configure Mask and Aribration register */
    {
        CAN->IF[u8MsgIfNum].ARB1 = 0;
        CAN->IF[u8MsgIfNum].ARB2 = CAN_ARB2_MSGVAL | (u32id & 0x7FF)<< 2;
    }
    else
    {
        CAN->IF[u8MsgIfNum].ARB1 = u32id & 0xFFFF;
        CAN->IF[u8MsgIfNum].ARB2 = CAN_ARB2_MSGVAL | CAN_ARB2_XTD | (u32id & 0x1FFF0000)>>16;
    }
    
    CAN->IF[u8MsgIfNum].MCON |= CAN_IF_MCON_UMASK_Msk | CAN_IF_MCON_RXIE_Msk;
    if(u8singleOrFifoLast)
        CAN->IF[u8MsgIfNum].MCON |= CAN_IF_MCON_EOB_Msk;
    else
        CAN->IF[u8MsgIfNum].MCON &= (~CAN_IF_MCON_EOB_Msk);

    CAN->IF[u8MsgIfNum].DAT_A1  = 0;
    CAN->IF[u8MsgIfNum].DAT_A2  = 0;
    CAN->IF[u8MsgIfNum].DAT_B1  = 0;
    CAN->IF[u8MsgIfNum].DAT_B2  = 0;

    CAN->IF[u8MsgIfNum].CREQ = 1 + u8MsgObj;

    return E_SUCCESS;
}


/**
  * @brief      Reset IntPnd and TXRQSTNEWDAT bit in a Message Object.
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     E_SUCCESS   Transmission ended
  * @retval     E_CAN_NO_USEFUL_INTERFACE   No useful interface
  * @details    The function is used to reset IntPnd and TXRQSTNEWDAT bit in a Message Object.
  */
 
int32_t CAN_ClrIntPnd(uint8_t u8MsgObj)
{
    uint8_t u8MsgIfNum=0;

    if ((u8MsgIfNum = GetFreeIF()) == 2)    /* Judge if any interface is free */
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }

    CAN->IF[u8MsgIfNum].CMASK = CAN_CMASK_CLRINTPND | CAN_CMASK_TXRQSTNEWDAT;
    CAN->IF[u8MsgIfNum].CREQ = 1 + u8MsgObj;

    return E_SUCCESS;
}


/**
  * @brief      Set transmit request bit
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     E_SUCCESS   SUCCESS
  * @details    The function is used to set transmit request bit in the target message object.
  */

uint32_t CAN_SetTxRqst(uint8_t u8MsgObj)
{
    STR_CANMSG_T rMsg; 
    CAN_ReadMsgObj(u8MsgObj,TRUE, &rMsg);
    CAN->IF[0].CMASK  = CAN_CMASK_WRRD |CAN_CMASK_TXRQSTNEWDAT ;
    CAN->IF[0].CREQ  = 1 + u8MsgObj;
    return E_SUCCESS;
}



/**
  * @brief      Gets the message
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @param[in]	u8Release   Specifies the message release indicator.
  *                         This parameter can be one of the following values:
                            TRUE: the message object is released when getting the data.
                            FALSE:the message object is not released.
  * @param[in]	pCanMsg     Pointer to the message structure where received data is copied.
  * @retval     E_SUCCESS   Success
  * @retval     E_CAN_NO_PENDING_MSG    No any message received
  * @details    Gets the message, if received.
  */

int32_t CAN_ReadMsgObj(uint8_t u8MsgObj, uint8_t u8Release, STR_CANMSG_T* pCanMsg)
{
    if (!CAN_IsNewDataReceived(u8MsgObj))
    {
        return E_CAN_NO_PENDING_MSG;
    }

    CAN->STATUS &= (~CAN_STATUS_RXOK_Msk);

    /* read the message contents*/
    CAN->IF[1].CMASK = CAN_CMASK_MASK
                          | CAN_CMASK_ARB
                          | CAN_CMASK_CONTROL
                          | CAN_CMASK_CLRINTPND
                          | (u8Release ? CAN_CMASK_TXRQSTNEWDAT : 0)
                          | CAN_CMASK_DATAA
                          | CAN_CMASK_DATAB;

    CAN->IF[1].CREQ = 1 + u8MsgObj;

    if (CAN->IF[1].CREQ & CAN_IF_CREQ_BUSY_Msk)
    {
        return E_CAN_NO_USEFUL_INTERFACE;
    }

    if ((CAN->IF[1].ARB2 & CAN_IF_ARB2_XTD_Msk) == 0)
    {
        /* standard ID*/
        pCanMsg->IdType = CAN_STD_ID;
        pCanMsg->Id     = (CAN->IF[1].ARB2 & CAN_IF_ARB2_ID_Msk) >> 2;
    }
    else
    {
        /* extended ID*/
        pCanMsg->IdType = CAN_EXT_ID;
        pCanMsg->Id  = (((CAN->IF[1].ARB2) & 0x1FFF)<<16) | CAN->IF[1].ARB1; 
    }
    
    pCanMsg->DLC     = CAN->IF[1].MCON & CAN_IF_MCON_DLC_Msk;
    pCanMsg->Data[0] = CAN->IF[1].DAT_A1 & CAN_IF_DAT_A1_DATA0_Msk;
    pCanMsg->Data[1] = (CAN->IF[1].DAT_A1 & CAN_IF_DAT_A1_DATA1_Msk) >> CAN_IF_DAT_A1_DATA1_Pos;
    pCanMsg->Data[2] = CAN->IF[1].DAT_A2 & CAN_IF_DAT_A2_DATA2_Msk;
    pCanMsg->Data[3] = (CAN->IF[1].DAT_A2 & CAN_IF_DAT_A2_DATA3_Msk) >> CAN_IF_DAT_A2_DATA3_Pos;
    pCanMsg->Data[4] = CAN->IF[1].DAT_B1 & CAN_IF_DAT_B1_DATA4_Msk;
    pCanMsg->Data[5] = (CAN->IF[1].DAT_B1 & CAN_IF_DAT_B1_DATA5_Msk) >> CAN_IF_DAT_B1_DATA5_Pos;
    pCanMsg->Data[6] = CAN->IF[1].DAT_B2 & CAN_IF_DAT_B2_DATA6_Msk;
    pCanMsg->Data[7] = (CAN->IF[1].DAT_B2 & CAN_IF_DAT_B2_DATA7_Msk) >> CAN_IF_DAT_B2_DATA7_Pos;
 
    return E_SUCCESS;
}


/**
  * @brief      Waiting until current transmission is finished.
  * @param[in]	pVoid	User interrupt callback function, it will be called in USB IRQ Handler
  * @retval     E_SUCCESS   Transmission ended
  * @details    Waiting until current transmission is finished.
  */

int32_t CAN_WaitEndOfTx(void)
{
    while((CAN->STATUS & CAN_STATUS_TXOK_Msk)==0);
    return E_SUCCESS;
}
           

/**
  * @brief      Send CAN message in BASIC mode of test mode
  * @param[in]	pCanMsg     Pointer to the message structure containing data to transmit.
  * @retval     E_SUCCESS   Transmission OK
  *			    E_CAN_ERR_TIMEOUT   Check busy flag of interface 0 is timeout
  * @details    The function is used to send CAN message in BASIC mode of test mode. Before call the API,
  *             the user should be call CAN_EnterTestMode(CAN_TESTR_BASIC) and let CAN controller enter
  *             basic mode of test mode. Please notice IF1 Registers used as Tx Buffer in basic mode.
  */

int32_t CAN_BasicSendMsg(STR_CANMSG_T* pCanMsg)
{
    uint32_t i=0;
    while(CAN->IF[0].CREQ & CAN_IF_CREQ_BUSY_Msk);
   
    CAN->STATUS &= (~CAN_STATUS_TXOK_Msk);

    CAN->IF[0].CMASK = CAN_CMASK_WRRD;  

    if (pCanMsg->IdType == CAN_STD_ID)
    {
        /* standard ID*/
        CAN->IF[0].ARB1 = 0;
		CAN->IF[0].ARB2 =  (((pCanMsg->Id)&0x7FF)<<2) ;
    }
    else
    {
        /* extended ID*/
        CAN->IF[0].ARB1 = (pCanMsg->Id)&0xFFFF;
        CAN->IF[0].ARB2 = ((pCanMsg->Id)&0x1FFF0000)>>16  | CAN_ARB2_XTD;

    }
    
    if(pCanMsg->FrameType)
        CAN->IF[0].ARB2 |= CAN_IF_ARB2_DIR_Msk;
    else
        CAN->IF[0].ARB2 &= (~CAN_IF_ARB2_DIR_Msk);
       
    CAN->IF[0].MCON = (CAN->IF[0].MCON & (~CAN_IF_MCON_DLC_Msk)) | pCanMsg->DLC;
    CAN->IF[0].DAT_A1 = ((uint16_t)pCanMsg->Data[1]<<8) | pCanMsg->Data[0];
    CAN->IF[0].DAT_A2 = ((uint16_t)pCanMsg->Data[3]<<8) | pCanMsg->Data[2];
    CAN->IF[0].DAT_B1 = ((uint16_t)pCanMsg->Data[5]<<8) | pCanMsg->Data[4];
    CAN->IF[0].DAT_B2 = ((uint16_t)pCanMsg->Data[7]<<8) | pCanMsg->Data[6];

    /* request transmission*/
	CAN->IF[0].CREQ &= (~CAN_IF_CREQ_BUSY_Msk);
	if(CAN->IF[0].CREQ & CAN_IF_CREQ_BUSY_Msk)
    {
		DEBUG_PRINTF("Cannot clear busy for sending ...\n");
        return E_CAN_ERR_TIMEOUT;
	}
    
	CAN->IF[0].CREQ |= CAN_IF_CREQ_BUSY_Msk;						   // sending

    for ( i=0; i<0xFFFFF; i++) {
		if((CAN->IF[0].CREQ & CAN_IF_CREQ_BUSY_Msk) == 0) break;
	}

    if ( i >= 0xFFFFF ) {
		DEBUG_PRINTF("Cannot send out...\n");
        return E_CAN_ERR_TIMEOUT;
	}
    return E_SUCCESS;
}


/**
  * @brief      Get a message information in BASIC mode.
  * @param[in]	pCanMsg     Pointer to the message structure where message is copied.
  * @retval     E_SUCCESS   Reception OK 
  * @retval     E_CAN_NO_PENDING_MSG    No any message received
  * @details    Get a message information in BASIC mode. This mode does not use the message RAM
  *             Using IF2 to get receive message information.
  */

int32_t CAN_BasicReceiveMsg(STR_CANMSG_T* pCanMsg)
{
    if((CAN->IF[1].MCON & CAN_IF_MCON_NEWDAT_Msk) == 0) /* In basic mode, receive data always save in IF2 */
    {
        return E_CAN_NO_PENDING_MSG;
    }

    CAN->STATUS &= (~CAN_STATUS_RXOK_Msk);
    
    CAN->IF[1].CMASK = CAN_CMASK_ARB
                             | CAN_CMASK_CONTROL
                             | CAN_CMASK_DATAA
                             | CAN_CMASK_DATAB;

    if((CAN->IF[1].ARB2 & CAN_IF_ARB2_XTD_Msk) == 0)
    {
        /* standard ID*/
        pCanMsg->IdType = CAN_STD_ID;
        pCanMsg->Id = (CAN->IF[1].ARB2 >> 2) & 0x07FF;

    }
    else
    {
        /* extended ID*/
        pCanMsg->IdType = CAN_EXT_ID;
        pCanMsg->Id  = (CAN->IF[1].ARB2 & 0x1FFF)<<16;
        pCanMsg->Id |= (uint32_t)CAN->IF[1].ARB1;
    }

    pCanMsg->FrameType = !((CAN->IF[1].ARB2 & CAN_IF_ARB2_DIR_Msk) >> CAN_IF_ARB2_DIR_Pos);

    pCanMsg->DLC     = CAN->IF[1].MCON & CAN_IF_MCON_DLC_Msk;
    pCanMsg->Data[0] = CAN->IF[1].DAT_A1 & CAN_IF_DAT_A1_DATA0_Msk;
    pCanMsg->Data[1] = (CAN->IF[1].DAT_A1 & CAN_IF_DAT_A1_DATA1_Msk) >> CAN_IF_DAT_A1_DATA1_Pos;
    pCanMsg->Data[2] = CAN->IF[1].DAT_A2 & CAN_IF_DAT_A2_DATA2_Msk;
    pCanMsg->Data[3] = (CAN->IF[1].DAT_A2 & CAN_IF_DAT_A2_DATA3_Msk) >> CAN_IF_DAT_A2_DATA3_Pos;
    pCanMsg->Data[4] = CAN->IF[1].DAT_B1 & CAN_IF_DAT_B1_DATA4_Msk;
    pCanMsg->Data[5] = (CAN->IF[1].DAT_B1 & CAN_IF_DAT_B1_DATA5_Msk) >> CAN_IF_DAT_B1_DATA5_Pos;
    pCanMsg->Data[6] = CAN->IF[1].DAT_B2 & CAN_IF_DAT_B2_DATA6_Msk;
    pCanMsg->Data[7] = (CAN->IF[1].DAT_B2 & CAN_IF_DAT_B2_DATA7_Msk) >> CAN_IF_DAT_B2_DATA7_Pos;
    
    return E_SUCCESS;
}


/**
  * @brief      Enter initialization mode
  * @details    This function is used to set CAN to enter initialization mode and enable access bit timing
  *             register. After bit timing configuration ready, user must call CAN_LeaveInitMode()
  *             to leave initialization mode and lock bit timing register to let new configuration
  *             take effect.
  */

void CAN_EnterInitMode(void)
{
    CAN->CON |= CAN_CON_INIT_Msk;
    CAN->CON |= CAN_CON_CCE_Msk;
}


/**
  * @brief      Leave initialization mode
  * @details    This function is used to set CAN to leave initialization mode to let
  *             bit timing configuration take effect after configuration ready.
  */

void CAN_LeaveInitMode(void)
{
    CAN->CON &= (~(CAN_CON_INIT_Msk | CAN_CON_CCE_Msk));
    
   	while(CAN->CON & CAN_CON_INIT_Msk);       /* Check INIT bit is released */
}


/**
  * @brief      Switchs the CAN into test mode.
  * @param[in]	u8TestMask  Specifies the configuration in test modes
  *                             CAN_TESTR_BASIC   : Enable basic mode of test mode
  *                             CAN_TESTR_SILENT  : Enable silent mode of test mode                           
  *                             CAN_TESTR_LBACK   : Enable Loop Back Mode of test mode                        
  *                             CAN_TESTR_TX0/CAN_TESTR_TX1: Control CAN_TX pin bit feild                     
  * @details    Switchs the CAN into test mode. There are four test mode (BASIC/SILENT/LOOPBACK/
  *             LOOPBACK combined SILENT/CONTROL_TX_PIN)could be selected. After setting test mode,user
  *             must call CAN_LeaveInitMode() to let the setting take effect.
  */


void CAN_EnterTestMode(uint8_t u8TestMask)
{
    CAN->CON |= CAN_CON_TEST_Msk;
	CAN->TEST = u8TestMask;
}


/**
  * @brief      Leave the test mode
  * @details    This function is used to Leave the test mode (switch into normal mode).
  */

void CAN_LeaveTestMode(void)
{
	CAN->CON |= CAN_CON_TEST_Msk;
  	CAN->TEST &= ~(CAN_TESTR_LBACK | CAN_TESTR_SILENT | CAN_TESTR_BASIC);
  	CAN->CON &= (~CAN_CON_TEST_Msk);
}


/**
  * @brief      Get the waiting status of a received message.
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     non-zero    The corresponding message object has a new data bit is set.
  * @retval     0           No message object has new data.
  * @details    This function is used to get the waiting status of a received message.
  */

uint32_t CAN_IsNewDataReceived(uint8_t u8MsgObj)
{
    return (u8MsgObj < 16 ? CAN->NDAT1 & (1 << u8MsgObj) : CAN->NDAT2 & (1 << (u8MsgObj-16)));
}


/**
  * @brief      get Tx request pending status
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     non-zero    The corresponding message object has a new data bit is set.
  * @retval     0           No message object has new data.
  * @details    This function is used to get the request pending status of a transmitted message.
  */

uint32_t CAN_IsTxRqstPending(uint8_t u8MsgObj)
{
  	return (u8MsgObj < 16 ? CAN->TXREQ1 & (1 << u8MsgObj) : CAN->TXREQ2 & (1 << (u8MsgObj-16)));
}


/**
  * @brief      Get message object interrupt status
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     non-zero    The corresponding message object has a new data bit is set.
  * @retval     0           No message object has new data.
  * @details    This function is used to get the interrupt status of a message object
  */

uint32_t CAN_IsIntPending(uint8_t u8MsgObj)
{
  	return (u8MsgObj < 16 ? CAN->IPND1 & (1 << u8MsgObj) : CAN->IPND2 & (1 << (u8MsgObj-16)));
}


/**
  * @brief      Test the validity of a message object
  * @param[in]	u8MsgObj    Specifies the Message object number, from 0 to 31.
  * @retval     non-zero    The corresponding message object has a new data bit is set.
  * @retval     0           No message object has new data.
  * @details    This function is used to test the validity of a message object (ready to use).
  */

uint32_t CAN_IsObjectValid(uint8_t u8MsgObj)
{
  	return (u8MsgObj < 16 ? CAN->MVLD1 & (1 << u8MsgObj) : CAN->MVLD2 & (1 << (u8MsgObj-16)));
}


/**
  * @brief      Reset message interface parameters.
  * @param[in]	u8IF_Num    Specifies the message interface, 0 or 1. 
  * @details    This function is used to reset message interface parameters.
  */

void CAN_ResetIF(uint8_t u8IF_Num)
{
	if(u8IF_Num > 1)
        return;
    CAN->IF[u8IF_Num].CREQ     = 0x0;			// set bit15 for sending
	CAN->IF[u8IF_Num].CMASK    = 0x0;
	CAN->IF[u8IF_Num].MASK1    = 0x0;			// useless in basic mode
	CAN->IF[u8IF_Num].MASK2    = 0x0;		    // useless in basic mode
	CAN->IF[u8IF_Num].ARB1     = 0x0;		    // ID15~0
	CAN->IF[u8IF_Num].ARB2     = 0x0;		    // MsgVal, eXt, xmt, ID28~16
	CAN->IF[u8IF_Num].MCON     = 0x0;  	    	// DLC
	CAN->IF[u8IF_Num].DAT_A1   = 0x0;			// data0,1
	CAN->IF[u8IF_Num].DAT_A2   = 0x0;			// data2,3
	CAN->IF[u8IF_Num].DAT_B1   = 0x0;			// data4,5
	CAN->IF[u8IF_Num].DAT_B2   = 0x0;			// data6,7
}


/**
  * @brief      Wait message into message buffer in basic mode.
  * @details    This function is used to wait message into message buffer in basic mode. Please notice the
  *             function is polling NEWDAT bit of MCON register by while loop and it is used in basic mode.
  */

void CAN_WaitMsg(void)
{
	CAN->STATUS = 0x0;			/* clr status */

	while (1) 
	{
		if(CAN->IF[1].MCON & CAN_IF_MCON_NEWDAT_Msk)  /* check new data */
		{
			DEBUG_PRINTF("New Data IN\n");
			break;	
		}
        if(CAN->STATUS & CAN_STATUS_RXOK_Msk) 
			DEBUG_PRINTF("Rx OK\n");

		if(CAN->STATUS & CAN_STATUS_LEC_Msk)
		{
			DEBUG_PRINTF("Error\n");
		}
	}
}


/**
  * @brief      Enable CAN interrupt
  * @param[in]	u16IntEnable    Interrupt Enable (CAN_CON_IE or CAN_CON_SIE or CAN_CON_EIE)
  *                             CAN_CON_IE  : Module Interrupt Enable                                     
  *                             CAN_CON_SIE : Status Change Interrupt Enable                              
  *                             CAN_CON_EIE : Error Interrupt Enable                                      
  * @retval     E_SUCCESS       Success
  * @details    Enable CAN interrupt and corresponding NVIC of CAN
  */

int32_t CAN_EnableInt(uint16_t u16IntEnable)
{
    CAN_EnterInitMode();

    CAN->CON = (CAN->CON & 0xF1) | ((u16IntEnable & CAN_CON_IE   )? CAN_CON_IE :0)
                                       | ((u16IntEnable & CAN_CON_SIE  )? CAN_CON_SIE:0)
                                       | ((u16IntEnable & CAN_CON_EIE  )? CAN_CON_EIE:0);

    NVIC_SetPriority(CAN0_IRQn, (1<<__NVIC_PRIO_BITS) - 2);
    NVIC_EnableIRQ(CAN0_IRQn);

	CAN_LeaveInitMode();
    return E_SUCCESS;
}


/**
  * @brief      Disable CAN interrupt
  * @param[in]	u16IntEnable    Interrupt Enable (CAN_CON_IE or CAN_CON_SIE or CAN_CON_EIE)
  * @retval     E_SUCCESS       Success 
  * @details    Disable CAN interrupt and corresponding NVIC of CAN
  */

int32_t CAN_DisableInt(uint16_t u16IntEnable)
{
    CAN_EnterInitMode();

    CAN->CON = CAN->CON & ~(CAN_CON_IE | ((u16IntEnable & CAN_CON_SIE )?CAN_CON_SIE:0)
                                    | ((u16IntEnable & CAN_CON_EIE )?CAN_CON_EIE:0));
    NVIC_DisableIRQ(CAN0_IRQn);

    CAN_LeaveInitMode();
   
    return E_SUCCESS;
}



/**
  * @brief      Install CAN call back functions
  * @param[in]	Type        It could be CALLBACK_RXOK/CALLBACK_TXOK/CALLBACK_EWARN/CALLBACK_BOFF/CALLBACK_MSG/CALLBACK_WAKEUP.
  *                             CALLBACK_RXOK: Received a Message Successfully callback fn.         
  *                             CALLBACK_TXOK: Transmitted a Message Successfully callback fn.      
  *                             CALLBACK_EWARN:Error Warning Status callback fn.                    
  *                             CALLBACK_BOFF: Bus-off Status callback fn.                          
  *                             CALLBACK_MSG:Target message object transmitted/received callback fn.
  *                             CALLBACK_WAKEUP: Wakeup callback fn.                                
  * @param[in]	callbackfn  Call back function pointer.
  * @retval     E_SUCCESS   Success    
  * @retval     E_CAN_ERR_ARGUMENT  Failed 
  * @details    Install CAN call back function for CAN normal function MSG,RXOK,TXOK,EWARN,BOFF and WAKEUP.
  */

int32_t CAN_InstallCallback(E_CAN_CALLBACK_TYPE Type, CAN_CALLBACK callbackfn)
{
    switch(Type)
    {
        
        case CALLBACK_MSG:      
                                CANHandler.MessageCallBackFn            = callbackfn;    
                                break;
        case CALLBACK_RXOK:     
                                CANHandler.RxOkCallBackFn               = callbackfn;    
                                break;
        case CALLBACK_TXOK:     
                                CANHandler.TxOkCallBackFn               = callbackfn;    
                                break;
        case CALLBACK_EWARN:    
                                CANHandler.ErrorWarningCallBackFn       = callbackfn;    
                                break;
        case CALLBACK_BOFF:     
                                CANHandler.BusOffCallBackFn             = callbackfn;    
                                break;
        case CALLBACK_WAKEUP:   
                                CANHandler.WakeupCallBackFn             = callbackfn;    
                                break;
        default:
            return E_CAN_ERR_ARGUMENT;                               
    }
           
    return E_SUCCESS;
}

/**
  * @brief      Uninstall exist callback function
  * @param[in]	Type        It could be CALLBACK_RXOK/CALLBACK_TXOK/CALLBACK_EWARN/CALLBACK_BOFF/CALLBACK_MSG/CALLBACK_WAKEUP.
                              CALLBACK_RXOK: Received a Message Successfully callback fn.         
                              CALLBACK_TXOK: Transmitted a Message Successfully callback fn.      
                              CALLBACK_EWARN:Error Warning Status callback fn.                    
                              CALLBACK_BOFF: Bus-off Status callback fn.                          
                              CALLBACK_MSG:Target message object transmitted/received callback fn.
                              CALLBACK_WAKEUP: Wakeup callback fn.                                
  * @retval     E_SUCCESS   Success
  * @retval     E_CAN_ERR_ARGUMENT  Failed 
  * @details    The function is used to uninstall exist callback function pointer.
  */

int32_t CAN_UninstallCallback(E_CAN_CALLBACK_TYPE Type)
{
    switch(Type)
    {
        
        case CALLBACK_MSG:      
                                CANHandler.MessageCallBackFn            = 0;    
                                break;
        case CALLBACK_RXOK:     
                                CANHandler.RxOkCallBackFn               = 0;    
                                break;
        case CALLBACK_TXOK:     
                                CANHandler.TxOkCallBackFn               = 0;    
                                break;
        case CALLBACK_EWARN:    
                                CANHandler.ErrorWarningCallBackFn       = 0;    
                                break;
        case CALLBACK_BOFF:     
                                CANHandler.BusOffCallBackFn             = 0;    
                                break;
        case CALLBACK_WAKEUP:   
                                CANHandler.WakeupCallBackFn             = 0;    
                                break;
        default:
            return E_CAN_ERR_ARGUMENT;                               
    }
           
    return E_SUCCESS;

}

/**
  * @brief      Enable wakeup function.
  * @details    The function is used to enable wakeup function.
  */

void CAN_EnableWakeUp(void)
{
    CAN->WU_EN = 1;
}



/**
  * @brief      Disable wakeup function.
  * @details    The function is used to disable wakeup function.
  */

void CAN_DisableWakeUp(void)
{
    CAN->WU_EN = 0;
}


/**
  * @brief      Get current receive error counter
  * @retval     Current Receive Error Counter(REC)  
  * @details    The function is used to get current receive error counter (REC) 
  */

uint32_t CAN_GetRxErrCount(void)
{
    return ((CAN->ERR & CAN_ERR_REC_Msk) >> CAN_ERR_REC_Pos);
}



/**
  * @brief      Get current transmit error counter.
  * @retval     Current Transmit Error Counter(TEC)
  * @details    The function is used to get current transmit error counter (TEC)
  */

/*---------------------------------------------------------------------------------------------------------*/
/* Function: 	 CAN_GetTxErrCount                                                                      */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*               NONE                                                                                      */
/* Returns:                                                                                                */
/*               Current Transmit Error Counter(TEC)                                                       */
/*                                                                                                         */
/* Description:                                                                                            */
/*               The function is used to get current transmit error counter (TEC)                          */
/*---------------------------------------------------------------------------------------------------------*/
uint32_t CAN_GetTxErrCount(void)
{
    return ((CAN->ERR & CAN_ERR_TEC_Msk) >> CAN_ERR_TEC_Pos);
}




