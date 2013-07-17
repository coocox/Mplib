/******************************************************************************
 * @file     DrvCRC.c
 * @brief    NUC123 CRC driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "CRC.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvPDMA_FUNC PDMA Driver API
  * @{
  */

/**   
  * @brief  Init CRC, configures CRC setting.
  * @param  sParam : CRC configure structure.
  *          u32Mode: CRC work mode
  *                      - CRC_CCITT
  *                      - CRC_8
  *                      - CRC_16
  *                      - CRC_32
  *          u32CPUWdlen: CPU write data length
  *                      - CRC_CPU_WDLEN_8
  *                      - CRC_CPU_WDLEN_16
  *                      - CRC_CPU_WDLEN_32
  *          bIsChecksumComplement: Checksum Complement
  *          bIsWriteDataComplement: Write Data Complement
  *          bIsChecksumReverse: Checksum Reverse
  *          bIsWriteDataReverse: Write Data Order Reverse
  *          u32DMASrcAddr: DMA Source Address
  *          u16DMAByteCnt: CRC DMA Transfer Count
  * @retval None.
  */
/**   
  * @brief  PDMA_OpenCRC, configures CRC setting.
  * @param  sParam : PDMA configure structure.
  * @retval None.
  */
void DrvCRC_Init(STR_CRC_T *sParam)
{
    CRC_CLOCK_ENABLE();

    CRC->CTL = sParam->u32Mode | sParam->u32CPUWdlen | 
                  (sParam->bIsChecksumComplement ? CRC_CHECKSUM_COMP : 0) |
                  (sParam->bIsWriteDataComplement ? CRC_WDATA_COMP : 0) |
                  (sParam->bIsChecksumReverse ? CRC_CHECKSUM_RVS : 0) |
                  (sParam->bIsWriteDataReverse ? CRC_WDATA_BYTE_RVS : 0) |
                   CRC_CH_EN;
    CRC_PDMA_SET_SRC_ADDR(sParam->u32DMASrcAddr);
    CRC_PDMA_SET_TRANS_CNT(sParam->u16DMAByteCnt);
}

/************************************************************/
/**   
  * @brief  Disable CRC clock and CRC interrupt.
  * @param  None.
  * @retval None.
  */
void DrvCRC_DeInit(void)
{
    CRC_CLOCK_DISABLE();
    AHBCLK_DISABLE(CLK_PDMA);
    NVIC_DisableIRQ(PDMA_IRQn);
}

/**   
  * @brief  DrvCRC_EnableInt, Enable Interrupt for CRC.
  * @param  u32IntMask: CRC Intterrupt, should be ored by:
  *                     - CRC_BLKD_INT
  *                     - CRC_TABORT_INT
  * @retval None.
  */
void DrvCRC_EnableInt(uint32_t u32IntMask)
{
    CRC_PDMA_INT_ENABLE(u32IntMask);
    NVIC_EnableIRQ(PDMA_IRQn);
}

/**   
  * @brief  DrvCRC_DisableInt, Disable CRC Interrupt.
  * @param  u32IntMask: CRC Intterrupt, should be ored by:
  *                     - CRC_BLKD_INT
  *                     - CRC_TABORT_INT
  * @retval None.
  */
void DrvCRC_DisableInt(uint32_t u32IntMask)
{
    CRC_PDMA_INT_DISABLE(u32IntMask);
    if(((PDMA0->IER & 0x3) == 0) && ((PDMA1->IER & 0x3) == 0) &&
      ((PDMA2->IER & 0x3) == 0) && ((PDMA3->IER & 0x3) == 0) &&
      ((PDMA4->IER & 0x3) == 0) && ((PDMA5->IER & 0x3) == 0))
    NVIC_DisableIRQ(PDMA_IRQn);
}

/*@}*/ /* end of group DrvPDMA_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
