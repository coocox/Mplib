/******************************************************************************
 * @file     DrvI2S.c
 * @brief    NUC123 I2S driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
  
//* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC123Series.h"
#include "I2S.h"
#include "CLOCK.h"
#include "SYS.h"



/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvI2S_FUNC I2S Driver API
  * @{
  */


/**
  * @brief  This function is used to configure the I2S mode/format/FIFO threshold function/BCLK.
  * @param  sParam: Data structure to configure
  *          u32ClkSrc: I2S clock source - CLK_I2S_HXT
  *                                        CLK_I2S_PLL
  *                                        CLK_I2S_HCLK
  *                                        CLK_I2S_HIRC
  *          u32SampleRate: Sample rate
  *          u32WordWidth: Data length - I2S_CFG_WORDWIDTH_8  :  8-bit Data
  *                                      I2S_CFG_WORDWIDTH_16 : 16-bit Data
  *                                      I2S_CFG_WORDWIDTH_24 : 24-bit Data
  *                                      I2S_CFG_WORDWIDTH_32 : 32-bit Data
  *          u32AudioFormat: Audio format- I2S_CFG_CHANNEL_MONO_LEFT: Mono with left channel enable
  *                                        I2S_CFG_CHANNEL_MONO_RIGHT: Mono with right channel enable
  *                                        I2S_CFG_CHANNEL_STEREO: Stereo
  *          u32DataFormat:  Data format - I2S_CFG_FORMAT_PCMA: PCM mode A
  *                                        I2S_CFG_FORMAT_PCMB: PCM mode B
  *                                        I2S_CFG_FORMAT_I2S:I2S format
  *                                        I2S_CFG_FORMAT_MSB_JUST: MSB justified format
  *          u32Mode: I2S operation mode - I2S_CFG_MASTER: master mode
  *                                        I2S_CFG_SLAVE : slave mode
  *          u32TxFIFOThreshold: Tx FIFO Threshold Level - I2S_CFG_TX_THRES_0 : 0 Word 
  *                                                        I2S_CFG_TX_THRES_1 : 1 Word
  *                                                        I2S_CFG_TX_THRES_2 : 2 Word
  *                                                        I2S_CFG_TX_THRES_3 : 3 Word
  *                                                        I2S_CFG_TX_THRES_4 : 4 Word
  *                                                        I2S_CFG_TX_THRES_5 : 5 Word
  *                                                        I2S_CFG_TX_THRES_6 : 6 Word
  *                                                        I2S_CFG_TX_THRES_7 : 7 Word
  *          u32TxFIFOThreshold: Rx FIFO Threshold Level - I2S_CFG_RX_THRES_1 : 1 Word
  *                                                        I2S_CFG_RX_THRES_2 : 2 Word
  *                                                        I2S_CFG_RX_THRES_3 : 3 Word
  *                                                        I2S_CFG_RX_THRES_4 : 4 Word
  *                                                        I2S_CFG_RX_THRES_5 : 5 Word
  *                                                        I2S_CFG_RX_THRES_6 : 6 Word
  *                                                        I2S_CFG_RX_THRES_7 : 7 Word
  *                                                        I2S_CFG_RX_THRES_8 : 8 Word
  * @retval 0: Success.
  */
int32_t DrvI2S_Init(STR_I2S_T *sParam)
{
    uint8_t u8Divider;
    uint32_t u32BitRate, u32SrcClk;

    SET_I2S_CLKSRC(sParam->u32ClkSrc);
    APBCLK_ENABLE(CLK_I2S);
    SYS_RESET_IP2(SYS_RST_I2S);
    
    I2S_CLR_RXFIFO();
    I2S_CLR_TXFIFO();
				
    I2S->CON = (sParam->u32WordWidth | sParam->u32AudioFormat | sParam->u32DataFormat | sParam->u32Mode |sParam->u32TxFIFOThreshold | sParam->u32RxFIFOThreshold) ;

    u32SrcClk = DrvI2S_GetSourceClockFreq();	
	
    u32BitRate = sParam->u32SampleRate * (sParam->u32WordWidth + 1) * 16;

    u8Divider = ((u32SrcClk/u32BitRate) >> 1) - 1;

    I2S->CLKDIV = (I2S->CLKDIV & ~I2S_CLKDIV_BCLK_DIV_Msk) | (u8Divider << 8);	

    I2S->CON |= I2S_CFG_EN | I2S_CFG_MCK_EN;	

    return 0;
}

/**
  * @brief  Disable I2S clock and I2S interrupt.
  * @param  None.
  * @retval None.
  */
void DrvI2S_DeInit(void)
{
    APBCLK_DISABLE(CLK_I2S);;

    NVIC_DisableIRQ(I2S_IRQn);	
}

/**
 * @brief      Enable I2S Interrupt
 *
 * @param      u32IntMask: I2S Interrupt, should be ored by:
 *                         - I2S_INT_LZC
 *                         - I2S_INT_RZC
 *                         - I2S_INT_TXTH
 *                         - I2S_INT_TXOVF
 *                         - I2S_INT_TXUDF
 *                         - I2S_INT_RXTH
 *                         - I2S_INT_RXOVF
 *                         - I2S_INT_RXUDF
 *
 * @return     None
 *
 * @details    Enable I2S interrupt according to the mask value.
 *
 */
void DrvI2S_EnableInt(uint32_t u32IntMask)
{
    I2S_ENABLE_INT(u32IntMask);
    NVIC_EnableIRQ(I2S_IRQn);	
}

/**
 * @brief      Disable I2S Interrupt
 *
 * @param      u32IntMask: I2S Interrupt, should be ored by:
 *                         - I2S_INT_LZC
 *                         - I2S_INT_RZC
 *                         - I2S_INT_TXTH
 *                         - I2S_INT_TXOVF
 *                         - I2S_INT_TXUDF
 *                         - I2S_INT_RXTH
 *                         - I2S_INT_RXOVF
 *                         - I2S_INT_RXUDF
 *
 * @return     None
 *
 * @details    Disable I2S interrupt according to the mask value.
 *
 */
void DrvI2S_DisableInt(uint32_t u32IntMask)
{
    I2S_DISABLE_INT(u32IntMask);
    NVIC_DisableIRQ(I2S_IRQn);	
}

/**
  * @brief  This function is used to get I2S source clock frequency.
  * @param  None
  * @retval I2S source clock frequency (Hz).
  */
uint32_t DrvI2S_GetSourceClockFreq(void)
{	
    uint32_t u32Freq, u32ClkSrcSel;;
	
    // get I2S selection clock source
    u32ClkSrcSel = CLK->CLKSEL2 & CLK_CLKSEL2_I2S_S_Msk;
	
    switch (u32ClkSrcSel)
    {
        case CLK_I2S_HXT:
            u32Freq = __XTAL;
            break;
		
        case CLK_I2S_PLL:
            u32Freq = CLK_GetPLLClockFreq();					
            break;
            
        case CLK_I2S_HCLK:
            u32Freq = CLK_GetHCLKFreq();
            break;
		
        case CLK_I2S_HIRC:
            u32Freq = __IRC22M;
            break;	
		
        default: 
            u32Freq = __IRC22M;
            break;	
    }

    return u32Freq;
}


/*@}*/ /* end of group DrvI2S_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
