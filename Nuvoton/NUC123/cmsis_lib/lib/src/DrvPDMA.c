/******************************************************************************
 * @file     DrvPDMA.c
 * @brief    NUC123 PDMA driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "PDMA.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvPDMA_FUNC PDMA Driver API
  * @{
  */

/**   
  * @brief  Init PDMA, configures PDMA setting.
  * @param  ch: PDMA Source channel, PDMA1 ~ PDMA6.
  *         sParam : PDMA configure structure.
  *          u32SrcCtrl: Source Address Direction Selection
  *                      - PDMA_SAD_INC
  *                      - PDMA_SAD_FIXED
  *          u32SrcAddr: Source address
  *          u32DestCtrl: Destination Address Direction Selection
  *                      - PDMA_DAD_INC
  *                      - PDMA_DAD_FIXED
  *          u32DestAddr: Destination address
  *          u32TransWidth: Transfer width
  *                      - PDMA_APB_TWS_8BIT
  *                      - PDMA_APB_TWS_16BIT
  *                      - PDMA_APB_TWS_32BIT
  *          u32Mode: PDMA work mode
  *                      - PDMA_MD_MEM2MEM
  *                      - PDMA_MD_APB2MEM
  *                      - PDMA_MD_MEM2APB
  *          u32ByteCnt: Transfer count
  * @retval None.
  */
void DrvPDMA_Init(PDMA_T *ch, STR_PDMA_T *sParam)
{
    uint32_t u32Channel = (((uint32_t)ch) & 0x0F00) >> 8;
    
    PDMA_CH_CLK_ENABLE(1<<(8+u32Channel));
    PDMA_SW_RESET(ch);    
    ch->CSR = sParam->u32SrcCtrl | sParam->u32DestCtrl | sParam->u32TransWidth |
              sParam->u32Mode | PDMA_CH_EN;
    ch->SAR = sParam->u32SrcAddr;
    ch->DAR = sParam->u32DestAddr;
    ch->BCR = sParam->u32ByteCnt;
}

/************************************************************/
/**   
  * @brief  Disable PDMA clock and PDMA interrupt.
  * @param  None.
  * @retval None.
  */
void DrvPDMA_DeInit(void)
{
   	/* Disable All PDMA clock */
    PDMA_GCR->GCRCSR = 0;
    AHBCLK_DISABLE(CLK_PDMA);
    NVIC_DisableIRQ(PDMA_IRQn);
}

/**   
  * @brief  DrvPDMA_EnableInt, Enable Interrupt for channel.
  * @param  ch: PDMA Source channel, PDMA1 ~ PDMA6.
  *         u32IntMask: PDMA channel Intterrupt, should be ored by:
  *                     - PDMA_BLKD_INT
  *                     - PDMA_TABORT_INT
  * @retval None.
  */
void DrvPDMA_EnableInt(PDMA_T *ch, uint32_t u32IntMask)
{
    PDMA_INT_ENABLE(ch, u32IntMask);
    NVIC_EnableIRQ(PDMA_IRQn);
}

/**   
  * @brief  DrvPDMA_DisableInt, Disable channel Interrupt.
  * @param  ch: PDMA Source channel, PDMA1 ~ PDMA6.
  *         u32IntMask: PDMA channel Intterrupt, should be ored by:
  *                     - PDMA_BLKD_INT
  *                     - PDMA_TABORT_INT
  * @retval None.
  */
void DrvPDMA_DisableInt(PDMA_T *ch, uint32_t u32IntMask)
{
    PDMA_INT_DISABLE(ch, u32IntMask);
    if((CRC->DMAIER & 0x3) == 0)
        NVIC_DisableIRQ(PDMA_IRQn);
}

/*@}*/ /* end of group DrvPDMA_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
