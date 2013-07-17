/******************************************************************************
 * @file     nano1xx_spi.c
 * @brief    NANO1xx SPI driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
//* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC123Series.h"
#include "SPI.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvSPI_FUNC SPI Driver API
  * @{
  */


/**
  * @brief  Disable SPI engine clock.
  * @param  SpiPort: SPI port handler
  * @retval None.
  */
void DrvSPI_DeInit(SPI_T *SpiPort)
{	
    if((uint32_t)SpiPort == SPI0_BASE)
    {
        APBCLK_DISABLE(CLK_SPI0);
        NVIC_DisableIRQ(SPI0_IRQn);
    }
    else if((uint32_t)SpiPort == SPI1_BASE)
    {
        APBCLK_DISABLE(CLK_SPI1);
        NVIC_DisableIRQ(SPI1_IRQn);
    }
    else if((uint32_t)SpiPort == SPI2_BASE)
    {
        APBCLK_DISABLE(CLK_SPI2);
        NVIC_DisableIRQ(SPI2_IRQn);	
    }
}

/**
  * @brief  Configure the operation mode, transfer type and bit length of a 
  *         transaction of the specified SPI port.
  * @param  SpiPort: SPI port handler
  *			sParam: Pointer of SPI arguments structure, including
  *          u32Mode: Specify the operation mode (SPI_MASTER/SPI_SLAVE).
  *			 eType: Specify the transfer type (SPI_TYPE0 ~ SPI_TYPE3).
  *			 i32BitLength: Specify the bit length in a transaction (8~32)
  * @retval TRUE: Success.
  */
  
/*
SPI_TYPE0:          
             _________________________________
    CS    --|          Active state           |---
               _   _   _   _   _   _   _   _  
    CLK   ____| |_| |_| |_| |_| |_| |_| |_| |_____
              
    Tx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |-----
          
    Rx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |-----


SPI_TYPE1:          
             _________________________________
    CS    --|          Active state           |---
               _   _   _   _   _   _   _   _  
    CLK   ____| |_| |_| |_| |_| |_| |_| |_| |_____
              
    Tx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |---
          
    Rx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |---


SPI_TYPE2:
             _________________________________
    CS    --|          Active state           |---
           ___   _   _   _   _   _   _   _   ______ 
    CLK       |_| |_| |_| |_| |_| |_| |_| |_|  
              
    Tx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |----
          
    Rx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |----


SPI_TYPE3:
             _________________________________
    CS    --|          Active state           |---
           ___   _   _   _   _   _   _   _   ______ 
    CLK       |_| |_| |_| |_| |_| |_| |_| |_|  
              
    Tx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |------
          
    Rx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |------
*/
int32_t DrvSPI_Init(SPI_T *SpiPort, uint32_t u32Mode, SPI_TRANS_TYPE eType,	int32_t i32BitLength)
{	            
    if((uint32_t)SpiPort == SPI0_BASE)
        APBCLK_ENABLE(CLK_SPI0);               //En:Enable SPI0 clock	
    else if((uint32_t)SpiPort == SPI1_BASE)
        APBCLK_ENABLE(CLK_SPI1);               //En:Enable SPI1 clock	
    else if((uint32_t)SpiPort == SPI2_BASE)		
        APBCLK_ENABLE(CLK_SPI2);               //En:Enable SPI2 clock
    	
    if((uint32_t)SpiPort == SPI0_BASE)
    {		
        SYS_RESET_IP2(SYS_RST_SPI0);                   //中:复位SPI//en: Reset SPI IP 	
    }	
    else if((uint32_t)SpiPort == SPI1_BASE)
    {	
        SYS_RESET_IP2(SYS_RST_SPI1);                   //中:复位SPI//en: Reset SPI IP 	
    }	
    else if((uint32_t)SpiPort == SPI2_BASE)
    {	
        SYS_RESET_IP2(SYS_RST_SPI2);                   //中:复位SPI//en: Reset SPI IP 	
    }
    else	
    return 0;
			
	
    /* "i32BitLength = 0" means 32 bits */
    if(i32BitLength == 32)
        i32BitLength = 0;
		
    SPI_SET_TX_BIT_LEN(SpiPort, i32BitLength);				      //En:Transmit Bit Length
    SPI_SET_MODE(SpiPort, u32Mode);

    /* Waveform types */	
    SPI_Waveform(SpiPort, eType);		
		
    return TRUE;
}

/**
  * @brief  Configure the SPI clock.
  * @param  SpiPort: SPI port handler  
  *			u32Clock1: Specify the SPI clock rate in Hz. It's the clock rate of SPI base clock or variable clock 1.
  *			u32Clock2: Specify the SPI clock rate in Hz. It's the clock rate of variable clock 2.
  * @retval The actual clock rate of SPI engine clock 1 is returned.
  *			The actual clock may be different to the target SPI clock due to hardware limitation.
  */
uint32_t DrvSPI_SetClockFreq(SPI_T *SpiPort, uint32_t u32Clock1, uint32_t u32Clock2)
{
    uint32_t u32Div;
    uint32_t u32Pclk, u32CalculatedSpeed=0;
    
    u32Pclk = DrvSPI_GetSourceClockFreq(SpiPort);
    
    if(u32Clock2!=0)
    {
        u32Div = (((u32Pclk / u32Clock2) + 1) >> 1) - 1;
        if(u32Div > 0xFF)
        u32Div = 0xFF;
		
        u32CalculatedSpeed = u32Pclk / (2*(u32Div+1));
        if(u32CalculatedSpeed > u32Clock2)
            u32Div ++;			
		
        SpiPort->DIVIDER = (SpiPort->DIVIDER & ~SPI_DIVIDER_DIVIDER2_Msk) | (u32Div << 16);
    }
    else
         SpiPort->DIVIDER |= SPI_DIVIDER_DIVIDER2_Msk;
	
    if(u32Clock1!=0)
    {
        u32Div = ((u32Pclk / u32Clock1) >> 1);
        if(u32Div > 0x7F)
            u32Div = 0x7F;
		
        if(u32Div == 0)
            u32CalculatedSpeed = u32Pclk;
        else
            u32CalculatedSpeed = u32Pclk / (u32Div << 1);
		
        if(u32CalculatedSpeed > u32Clock1)
        {	
            u32Div ++;
            u32CalculatedSpeed = u32Pclk / (u32Div << 1);
        }
		
        SpiPort->DIVIDER = (SpiPort->DIVIDER & ~SPI_DIVIDER_DIVIDER_Msk) | u32Div;
    }
    else
        SpiPort->DIVIDER |= SPI_DIVIDER_DIVIDER_Msk;
	
    return u32CalculatedSpeed;
}

/**
  * @brief  Get the SPI engine clock rate in Hz.
  * @param  SpiPort: SPI port handler  
  * @retval The current SPI bus clock frequency in Hz.
  */
uint32_t DrvSPI_GetClock1Freq(SPI_T *SpiPort)
{
    uint32_t u32Div;
    uint32_t u32ApbClock;

    u32ApbClock = DrvSPI_GetSourceClockFreq(SpiPort);
    u32Div = SpiPort->DIVIDER & SPI_DIVIDER_DIVIDER_Msk;
	
    if(u32Div == 0)	return u32ApbClock;
    else return ((u32ApbClock >> 1) / u32Div);   /* SPI_CLK = APB_CLK / (Divider * 2) */
}

/**
  * @brief  Get the clock rate of variable clock 2 in Hz.
  * @param  SpiPort: SPI port handler  
  * @retval The frequency of variable clock 2 in Hz.
  */
uint32_t DrvSPI_GetClock2Freq(SPI_T *SpiPort)
{
    uint32_t u32Div;
    uint32_t u32ApbClock;

    u32ApbClock = DrvSPI_GetSourceClockFreq(SpiPort);
    u32Div = (SpiPort->DIVIDER & SPI_DIVIDER_DIVIDER2_Msk) >> 16;
    return ((u32ApbClock >> 1) / (u32Div + 1));   /* SPI_CLK = APB_CLK / ((Divider + 1) * 2) */
}

/**
  * @brief  Enable the SPI interrupt of the specified SPI port and install the callback function.
  * @param  SpiPort: SPI port handler
  *			pfnCallback: The callback function of SPI interrupt.
  *			u32UserData: The parameter which will be passed to the callback function.
  * @retval None.
  */
void DrvSPI_EnableInt(SPI_T *SpiPort)
{	
    SPI_ENABLE_INTERRUPT(SpiPort);
	
    if((uint32_t)SpiPort == SPI0_BASE)	
        NVIC_EnableIRQ(SPI0_IRQn);
    else if((uint32_t)SpiPort == SPI1_BASE)	
        NVIC_EnableIRQ(SPI1_IRQn);
    else if((uint32_t)SpiPort == SPI2_BASE)		
        NVIC_EnableIRQ(SPI2_IRQn);
}	

/**
  * @brief  Disable the SPI interrupt.
  * @param  SpiPort: SPI port handler
  * @retval None.
  */
void DrvSPI_DisableInt(SPI_T *SpiPort)
{
    SPI_DISABLE_INTERRUPT(SpiPort);

    if((uint32_t)SpiPort == SPI0_BASE)	
        NVIC_DisableIRQ(SPI0_IRQn);
    else if((uint32_t)SpiPort == SPI1_BASE)	
        NVIC_DisableIRQ(SPI1_IRQn);
    else if((uint32_t)SpiPort == SPI2_BASE)		
        NVIC_DisableIRQ(SPI2_IRQn);
}

/**
  * @brief  Enable the 3-wire SPI start interrupt of SPI and install the callback function.
  * @param  SpiPort: SPI port handler 
  * @retval None.
  */
void SPI_Enable3WireStartInt(SPI_T *SpiPort)
{ 
    SPI_ENABLE_3WIRE_START_INT(SpiPort);

    if((uint32_t)SpiPort == SPI0_BASE)	
    {
        NVIC_EnableIRQ(SPI0_IRQn);
    }
    else if((uint32_t)SpiPort == SPI1_BASE)	
    {	
        NVIC_EnableIRQ(SPI1_IRQn);
    }
    else if((uint32_t)SpiPort == SPI2_BASE)
    {	
        NVIC_EnableIRQ(SPI2_IRQn);
    }
}   

/**
  * @brief  Disable the 3-wire SPI start interrupt.
  * @param  SpiPort: SPI port handler  
  * @retval None.
  */
void SPI_Disable3WireStartInt(SPI_T *SpiPort)
{    
    SPI_DISABLE_3WIRE_START_INT(SpiPort);
    
    if((uint32_t)SpiPort == SPI0_BASE)	
        NVIC_DisableIRQ(SPI0_IRQn);
    else if((uint32_t)SpiPort == SPI1_BASE)	
        NVIC_DisableIRQ(SPI1_IRQn);
    else if((uint32_t)SpiPort == SPI2_BASE)		
        NVIC_DisableIRQ(SPI2_IRQn);   
}

/**
  * @brief  Enable/disable FIFO mode. If the caller enables FIFO mode, configure the setting of suspend cycle.
  * @param  SpiPort: SPI port handler
  *         i32Interval: In FIFO mode, it could be 2~15 and 0. 0 indicates the maximum suspend interval; 2
  *                      indicates the minimum suspend interval.                                           
  * @retval None.
  */
void SPI_SetFIFOMode(SPI_T *SpiPort, int32_t i32Interval)
{    
    SPI_SET_SUSPEND_CYCLE(SpiPort, i32Interval);
    SPI_ENABLE_FIFO(SpiPort);
}

/**
  * @brief  Use FIFO mode to write 8bit data only (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu32TxBuf: Specify the buffer to send the data using FIFO.
  *			u32WriteBytes: Specify the number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t DrvSPI_FIFOWrite8(SPI_T *SpiPort, uint8_t *pu8TxBuf, uint32_t u32WriteLength)
{
    uint32_t  u32Count;
	 
    for (u32Count=0; u32Count<u32WriteLength; u32Count++)
    {
        while (SPI_GET_TX_FULL(SpiPort));  /* Wait Tx is empty */

        SpiPort->TX[0] = pu8TxBuf[u32Count];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to write 16bit data only (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu32TxBuf: Specify the buffer to send the data using FIFO.
  *			u32WriteBytes: Specify the number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t SPI_FIFOWrite16(SPI_T *SpiPort, uint16_t *pu16TxBuf, uint32_t u32WriteLength)
{
    uint32_t  u32Count;
	 
    for (u32Count=0; u32Count<u32WriteLength; u32Count++)
    {
   	while (SPI_GET_TX_FULL(SpiPort));  /* Wait Tx is empty */

        SpiPort->TX[0] = pu16TxBuf[u32Count];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to write 32bit data only (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu32TxBuf: Specify the buffer to send the data using FIFO.
  *			u32WriteBytes: Specify the number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t SPI_FIFOWrite32(SPI_T *SpiPort, uint32_t *pu32TxBuf, uint32_t u32WriteLength)
{
    uint32_t  u32Count;
	 
    for (u32Count=0; u32Count<u32WriteLength; u32Count++)
    {
   	while (SPI_GET_TX_FULL(SpiPort));  /* Wait Tx is empty */
 
        SpiPort->TX[0] = pu32TxBuf[u32Count];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to read 8bit data only (usually for slave).
  * @param  SpiPort: SPI port handler
  *         pu32RxBuf: Specify the buffer to receive the data using FIFO.
  *			u32ReadBytes: Specify the word number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t SPI_FIFORead8(SPI_T *SpiPort, uint8_t *pu8RxBuf, uint32_t u32ReadLength)
{
    uint32_t  u32Count;
		 	
    for (u32Count=0; u32Count<u32ReadLength; u32Count++)
    {
   	while (SPI_GET_RX_EMPTY(SpiPort));  /* Wait Rx is not empty*/

        pu8RxBuf[u32Count] = SpiPort->RX[0];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to read 16bit data only (usually for slave).
  * @param  SpiPort: SPI port handler
  *         pu32RxBuf: Specify the buffer to receive the data using FIFO.
  *			u32ReadBytes: Specify the number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t SPI_FIFORead16(SPI_T *SpiPort, uint16_t *pu16RxBuf, uint32_t u32ReadLength)
{
    uint32_t  u32Count;
		 	
    for (u32Count=0; u32Count<u32ReadLength; u32Count++)
    {
   	while (SPI_GET_RX_EMPTY(SpiPort));  /* Wait Rx is not empty */
 
        pu16RxBuf[u32Count] = SpiPort->RX[0];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to read 32bit data only (usually for slave).
  * @param  SpiPort: SPI port handler
  *         pu32RxBuf: Specify the buffer to receive the data using FIFO.
  *			u32ReadBytes: Specify the number of data.
  * @retval TRUE: Success.
  *         SPI_ERR_TIMEOUT: timeout.
  */
int32_t SPI_FIFORead32(SPI_T *SpiPort, uint32_t *pu32RxBuf, uint32_t u32ReadLength)
{
    uint32_t  u32Count;
		 	
    for (u32Count=0; u32Count<u32ReadLength; u32Count++)
    {
   	while (SPI_GET_RX_EMPTY(SpiPort));  /* Wait Rx is not empty */

        pu32RxBuf[u32Count] = SpiPort->RX[0];
    }
    
    return TRUE;
}

/**
  * @brief  Use FIFO mode to read/write 8bit data at the same time  (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu8TxBuf: Specify the buffer to transmit the data using FIFO. 
  *                   NULL: receive data only.
  *					  Otherwise: both send and receive data.
  *         pu8RxBuf: Specify the buffer to receive the data using FIFO.    
  *			u32WriteBytes: Specify the number of data.
  * @retval None.  
  */  
void SPI_FIFOReadWrite8(SPI_T *SpiPort, uint8_t *pu8TxBuf, uint8_t *pu8RxBuf, uint32_t u32Length)
{
    uint32_t  u32Count, u32RxCount = 0;
	 
    for (u32Count=0; u32Count<u32Length; u32Count++)
    {    	
   	while (SPI_GET_TX_FULL(SpiPort))  /* if Tx is full, process Rx */
        {
       	    while(SPI_GET_RX_EMPTY(SpiPort)==0)
   	    	pu8RxBuf[u32RxCount++] = SpiPort->RX[0];				   
        }
        
        if(pu8TxBuf == NULL)
            SpiPort->TX[0] = 0xFFFFFFFF;
        else
            SpiPort->TX[0] = pu8TxBuf[u32Count];

        while(SPI_GET_RX_EMPTY(SpiPort)==0)
            pu8RxBuf[u32RxCount++] = SpiPort->RX[0];
    }

}

/**
  * @brief  Use FIFO mode to read/write 16bit data at the same time  (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu8TxBuf: Specify the buffer to transmit the data using FIFO. 
  *                   NULL: receive data only.
  *					  Otherwise: both send and receive data.
  *         pu8RxBuf: Specify the buffer to receive the data using FIFO.    
  *			u32WriteBytes: Specify the number of data.
  * @retval None.  
  */  
void SPI_FIFOReadWrite16(SPI_T *SpiPort, uint16_t *pu16TxBuf, uint32_t *pu16RxBuf, uint32_t u32Length)
{
    uint32_t  u32Count, u32RxCount = 0;
	 
    for (u32Count=0; u32Count<u32Length; u32Count++)
    {    	
	 while (SPI_GET_TX_FULL(SpiPort))  /* if Tx is full, process Rx */
        {
       	    while(SPI_GET_RX_EMPTY(SpiPort)==0)
   	    	pu16RxBuf[u32RxCount++] = SpiPort->RX[0];				   
        }
        
        if(pu16TxBuf == NULL)
            SpiPort->TX[0] = 0xFFFFFFFF;
        else
            SpiPort->TX[0] = pu16TxBuf[u32Count];

        while(SPI_GET_RX_EMPTY(SpiPort)==0)
           pu16RxBuf[u32RxCount++] = SpiPort->RX[0];

    }
}

/**
  * @brief  Use FIFO mode to read/write 32bit data at the same time  (usually for master).
  * @param  SpiPort: SPI port handler
  *         pu8TxBuf: Specify the buffer to transmit the data using FIFO. 
  *                   NULL: receive data only.
  *					  Otherwise: both send and receive data.
  *         pu8RxBuf: Specify the buffer to receive the data using FIFO.    
  *			u32WriteBytes: Specify the number of data.
  * @retval None.  
  */  
void SPI_FIFOReadWrite32(SPI_T *SpiPort, uint32_t *pu32TxBuf, uint32_t *pu32RxBuf, uint32_t u32Length)
{
    uint32_t  u32Count, u32RxCount = 0;
	 
    for (u32Count=0; u32Count<u32Length; u32Count++)
    {    	
        while (SPI_GET_TX_FULL(SpiPort))  /* if Tx is full, process Rx */
        {
       	    while(SPI_GET_RX_EMPTY(SpiPort)==0)
   	    	pu32RxBuf[u32RxCount++] = SpiPort->RX[0];				   
        }
        
        if(pu32TxBuf == NULL)
            SpiPort->TX[0] = 0xFFFFFFFF;
        else
            SpiPort->TX[0] = pu32TxBuf[u32Count];

        while(SPI_GET_RX_EMPTY(SpiPort)==0)
            pu32RxBuf[u32RxCount++] = SpiPort->RX[0];
    }
}

/**
  * @brief  This function is used to get SPI source clock frequency.
  * @param  None
  * @retval SPI source clock frequency (Hz).
  */
uint32_t DrvSPI_GetSourceClockFreq(SPI_T *SpiPort)
{	
    //	Clock Source is form:
    //  (PLL, HXT, HIRC, LXT, LIRC) --> [HCLK_Div] ---> HCLK --->
    //    |                                                      [SPI_Div] ====> SPI clock
    //    +--------------------------------------------PLL------>
    //
    uint32_t u32Freq = 12000000, u32ClkSrcSel;
	
    if((uint32_t)SpiPort == SPI0_BASE)
        u32ClkSrcSel = CLK->CLKSEL2 & CLK_CLKSEL1_SPI0_S_Msk;
    else if((uint32_t)SpiPort == SPI1_BASE)
        u32ClkSrcSel = CLK->CLKSEL2 & CLK_CLKSEL1_SPI1_S_Msk;
    else 
        u32ClkSrcSel = CLK->CLKSEL2 & CLK_CLKSEL1_SPI2_S_Msk;
		
		
    if((u32ClkSrcSel == CLK_SPI0_PLL)  ||
        (u32ClkSrcSel == CLK_SPI1_PLL) ||
        (u32ClkSrcSel == CLK_SPI2_PLL))
    {
        return CLK_GetPLLClockFreq();
    }
	
    if((u32ClkSrcSel == CLK_SPI0_HCLK)  ||
        (u32ClkSrcSel == CLK_SPI1_HCLK) ||
        (u32ClkSrcSel == CLK_SPI2_HCLK))
    {
        return CLK_GetHCLKFreq();
    }
	
    return u32Freq;
}

/*@}*/ /* end of group DrvSPI_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
