/******************************************************************************
 * @file     CRC.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/16 14:35p $
 * @brief    NUC123 Series CRC Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __CRC_H__
#define __CRC_H__

#include "NUC123Series.h"
#include "PDMA.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup CRC_MACRO CRC Macro
  * @{
  */

/** @addtogroup CRC_MACRO_CONTANT CRC Macro Contant
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/*  CRC_CTL constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_CCITT                       (0UL<<CRC_CTL_CRC_MODE_Pos) /*!< CRC polynomial mode is CRC_CCITT */
#define CRC_8                           (1UL<<CRC_CTL_CRC_MODE_Pos) /*!< CRC polynomial mode is CRC_8 */
#define CRC_16                          (2UL<<CRC_CTL_CRC_MODE_Pos) /*!< CRC polynomial mode is CRC_16 */
#define CRC_32                          (3UL<<CRC_CTL_CRC_MODE_Pos) /*!< CRC polynomial mode is CRC_32 */

#define CRC_CPU_WDLEN_8                 (0UL<<CRC_CTL_CPU_WDLEN_Pos) /*!< When operation in CPU PIO mode(CRCCEN= 1, TRIG_EN = 0), write data length is 8-bit */
#define CRC_CPU_WDLEN_16                (1UL<<CRC_CTL_CPU_WDLEN_Pos) /*!< When operation in CPU PIO mode(CRCCEN= 1, TRIG_EN = 0), write data length is 16-bit */
#define CRC_CPU_WDLEN_32                (2UL<<CRC_CTL_CPU_WDLEN_Pos) /*!< When operation in CPU PIO mode(CRCCEN= 1, TRIG_EN = 0), write data length is 32-bit */

#define CRC_CHECKSUM_COMP               (1UL<<CRC_CTL_CHECKSUM_COM_Pos) /*!< One¡¯s complement for CRC checksum */
#define CRC_CHECKSUM_NON_COMP           (0UL<<CRC_CTL_CHECKSUM_COM_Pos) /*!< No One¡¯s complement for CRC checksum */

#define CRC_WDATA_COMP                  (1UL<<CRC_CTL_WDATA_COM_Pos) /*!< One¡¯s complement for CRC write data */
#define CRC_WDATA_NON_COMP              (0UL<<CRC_CTL_WDATA_COM_Pos) /*!< No One¡¯s complement for CRC write data */

#define CRC_CHECKSUM_RVS                (1UL<<CRC_CTL_CHECKSUM_RVS_Pos) /*!< Bit order reverse for CRC checksum(the whole word) */
#define CRC_CHECKSUM_NON_RVS            (0UL<<CRC_CTL_CHECKSUM_RVS_Pos) /*!< No bit order reverse for CRC checksum */

#define CRC_WDATA_BYTE_RVS              (1UL<<CRC_CTL_WDATA_RVS_Pos) /*!< Bit order reverse for CRC write data(per byte) */
#define CRC_WDATA_NON_RVS               (0UL<<CRC_CTL_WDATA_RVS_Pos) /*!< No bit order reverse for write data */

#define CRC_TRG_EN                      (1UL<<CRC_CTL_TRIG_EN_Pos) /*!< Enable CRC DMA data read or write transfer */
#define CRC_TRG_DIS                     (0UL<<CRC_CTL_TRIG_EN_Pos) /*!< Disable CRC DMA data read or write transfer */

#define CRC_ENGINE_RST                  (1UL<<CRC_CTL_CRC_RST_Pos) /*!< Reset internal CRC state machine and buffer. Contents of control register will not be cleared */

#define CRC_CH_EN                       (1UL<<CRC_CTL_CRCCEN_Pos) /*!< Enables CRC¡¯s operation */
#define CRC_CH_DIS                      (0UL<<CRC_CTL_CRCCEN_Pos) /*!< Enables CRC¡¯s operation */

/*---------------------------------------------------------------------------------------------------------*/
/*  CRC_DMAIER constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_BLKD_INT_EN                 (1UL<<CRC_DMAIER_CRC_BLKD_IE_Pos) /*!< Enable CRC PDMA transfer done interrupt */
#define CRC_BLKD_INT_DIS                (0UL<<CRC_DMAIER_CRC_BLKD_IE_Pos) /*!< Disable CRC PDMA transfer done interrupt */

#define CRC_TABORT_INT_EN               (1UL<<CRC_DMAIER_CRC_TABORT_IE_Pos) /*!< Enable CRC PDMA transfer target abort interrupt */
#define CRC_TABORT_INT_DIS              (0UL<<CRC_DMAIER_CRC_TABORT_IE_Pos) /*!< Disable CRC PDMA transfer target abort interrupt */

/*---------------------------------------------------------------------------------------------------------*/
/*  CRC_DMAISR constant definitions.                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_BLKD_IF                     (1UL<<PDMA_ISR_BLKD_IF_Pos) /*!< CRC PDMA transfer done interrupt flag */
#define CRC_TABORT_IF                   (1UL<<PDMA_ISR_TABORT_IF_Pos) /*!< CRC PDMA transfer target abort interrupt flag */

/*---------------------------------------------------------------------------------------------------------*/
/*  Misc constant definitions.                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_BLKD_INT                    (1UL<<PDMA_ISR_BLKD_IF_Pos) /*!< CRC PDMA transfer done interrupt */
#define CRC_TABORT_INT                  (1UL<<PDMA_ISR_TABORT_IF_Pos) /*!< CRC PDMA transfer target abort interrupt */

/*---------------------------------------------------------------------------------------------------------*/
/*  Structure definitions.                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct DRVCRC_STRUCT         /* CRC structure */
{
    uint32_t u32Mode;                /* CRC work mode */
    uint32_t u32CPUWdlen;            /* CPU write data length */
    uint8_t  bIsChecksumComplement;  /* Checksum Complement */
    uint8_t  bIsWriteDataComplement; /* Write Data Complement */
    uint8_t  bIsChecksumReverse;     /* Checksum Reverse */
    uint8_t  bIsWriteDataReverse;    /* Write Data Order Reverse */
    uint32_t u32DMASrcAddr;          /* DMA Source Address */
    uint16_t u16DMAByteCnt;          /* DMA Byte Count */
}STR_CRC_T;

/*@}*/ /* end of group CRC_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup CRC_MACRO_FUNC CRC Macro Func
  @{
*/
/**
 * @brief       Enable CRC controller clock
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable CRC controller clock
 */
static __INLINE void CRC_CLOCK_ENABLE(void)
{
    PDMA_GCR->GCRCSR |= PDMA_CRC_CLK_EN;
}

/**
 * @brief       Disable CRC controller clock
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Disable CRC controller clock
 */
static __INLINE void CRC_CLOCK_DISABLE(void)
{
    PDMA_GCR->GCRCSR &= (~PDMA_GCRCSR_CRC_CLK_EN_Msk);
}

/**
 * @brief       Get CRC controller interrupt status
 *
 * @param       None
 *
 * @retval      FALSE  No interrupt at CRC controller
 * @retval      TRUE   CRC controller generated an interrupt
 *
 * @details     Get CRC controller interrupt status
 */
static __INLINE uint32_t CRC_GET_INTR_STATUS(void)
{
    return (PDMA_GCR->GCRISR & PDMA_INTRCRC_STS);
}

/**
 * @brief       Specify CRC polynomial mode
 *
 * @param[in]   mode  Selectable CRC polynomial mode. It could be \n
 *                    CRC_CCITT, CRC_8, CRC_16, CRC_32
 *
 * @return      None
 *
 * @details     Specify CRC polynomial mode for CRC operation
 */
static __INLINE void CRC_SET_POLYNO_MODE(uint32_t mode)
{
    CRC->CTL = (CRC->CTL & (~CRC_CTL_CRC_MODE_Msk)) | (mode);
}

/**
 * @brief       Set CRC CPU write data length
 *
 * @param[in]   len  Selectable CPU write data length. It could be \n
 *                   CRC_CPU_WDLEN_8, CRC_CPU_WDLEN_16, CRC_CPU_WDLEN_32
 *
 * @return      None
 *
 * @details     When CRC operating in CPU PIO mode, set CPU write data length
 */
static __INLINE void CRC_SET_CPU_WDATA_LEN(uint32_t len)
{
    CRC->CTL = (CRC->CTL & (~CRC_CTL_CPU_WDLEN_Msk)) | (len);
}

/**
 * @brief       Set CRC checksum one's complement
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set one's complement for CRC checksum
 */
static __INLINE void CRC_SET_CHECKSUM_COMPLEMENT(void)
{
    CRC->CTL |= CRC_CHECKSUM_COMP;
}

/**
 * @brief       CRC checksum non one's complement
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Non one's complement for CRC checksum
 */
static __INLINE void CRC_SET_CHECKSUM_NON_COMPLEMENT(void)
{
    CRC->CTL &= (~CRC_CTL_CHECKSUM_COM_Msk);
}

/**
 * @brief       Set CRC checksum bit order reverse
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set the whole bit field of CRC checksum bit order reverse
 */
static __INLINE void CRC_SET_CHECKSUM_RVS(void)
{
    CRC->CTL |= CRC_CHECKSUM_RVS;
}

/**
 * @brief       Set CRC checksum bit order non-reverse
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set the whole bit field of CRC checksum in normal bit order
 */
static __INLINE void CRC_SET_CHECKSUM_NON_RVS(void)
{
    CRC->CTL &= (~CRC_CTL_CHECKSUM_RVS_Msk);
}

/**
 * @brief       Set CRC write data one's complement
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set one's complement for CRC write data
 */
static __INLINE void CRC_SET_WDATA_COMPLEMENT(void)
{
    CRC->CTL |= CRC_WDATA_COMP;
}

/**
 * @brief       CRC write non one's complement
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Non one's complement for CRC write data
 */
static __INLINE void CRC_SET_WDATA_NON_COMPLEMENT(void)
{
    CRC->CTL &= (~CRC_CTL_WDATA_COM_Msk);
}

/**
 * @brief       Set CRC write data bit order reverse
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set CRC write data bit order reverse in per byte
 */
static __INLINE void CRC_SET_WDATA_BYTE_RVS(void)
{
    CRC->CTL |= CRC_WDATA_BYTE_RVS;
}

/**
 * @brief       Set CRC write data bit order non-reverse
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Set CRC write data in normal bit order
 */
static __INLINE void CRC_SET_WDATA_NON_RVS(void)
{
    CRC->CTL &= (~CRC_CTL_WDATA_RVS_Msk);
}

/**
 * @brief       CRC PDMA triger enable
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable CRC DMA data read or write transfer
 */
static __INLINE void CRC_PDMA_TRG_ENABLE(void)
{
    CRC->CTL |= CRC_TRG_EN;
}

/**
 * @brief       Get CRC PDMA transfer status
 *
 * @param       None
 *
 * @retval      FALSE  CRC PDMA transfer is completed
 * @retval      TRUE   CRC PDMA transfer is not yet completed
 *
 * @details     Get CRC PDMA transfer status.\n
 *              When CRC DMA transfer complete, this bit will be cleared automatically
 */
static __INLINE uint32_t CRC_PDMA_GET_TRANS_STS(void)
{
    return (CRC->CTL & CRC_CTL_TRIG_EN_Msk);
}

/**
 * @brief       CRC engine reset
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Reset the internal CRC state machine and internal buffer. \n
 *              The contents of control register will not be cleared
 */
static __INLINE void CRC_ENGINE_RESET(void)
{
    CRC->CTL |= CRC_ENGINE_RST;
}

/**
 * @brief       CRC channel enable
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable CRC's operation
 */
static __INLINE void CRC_CH_ENABLE(void)
{
    CRC->CTL |= CRC_CH_EN;
}

/**
 * @brief       CRC channel disable
 *
 * @param       None
 *
 * @return      None
 *
 * @details     When operating in CRC DMA mode(TRIG_EN = 1), if user clears this bit, \n
 *              the DMA operation will be continuous until all CRC DMA operation is done,\n
 *              and the TRIG_EN bit will asserted until all CRC DMA operation done. \n
 *              But in this case, the CRC_DMAISR[BLKD_IF] flag will inactive, \n
 *              user can read CRC result by reading CRC_CHECKSUM register when TRIG_EN = 0. \n
 *              When operating in CRC DMA mode(TRIG_EN = 1), if user wants to stop the transfer immediately, \n
 *              user can write 1 to CRC_RST bit to stop the transmission
 */
static __INLINE void CRC_CH_DISABLE(void)
{
    CRC->CTL &= (~CRC_CTL_CRCCEN_Msk);
}

/**
 * @brief       Set CRC PDMA transfer source address
 *
 * @param[in]   addr  CRC PDMA transfer 32-bit address, must word aligned
 *
 * @return      None
 *
 * @details     Set CRC PDMA transfer source address
 */
static __INLINE void CRC_PDMA_SET_SRC_ADDR(uint32_t addr)
{
    CRC->DMASAR = ((addr) & 0xFFFFFFFCUL);
}

/**
 * @brief       Set CRC PDMA transfer byte count
 *
 * @param[in]   cnt  CRC PDMA transfer 16-bit byte count
 *
 * @return      None
 *
 * @details     Set CRC PDMA transfer byte count
 */
static __INLINE void CRC_PDMA_SET_TRANS_CNT(uint32_t cnt)
{
    CRC->DMABCR = (cnt);
}

/**
 * @brief       Get CRC PDMA current source address
 *
 * @param       None
 *
 * @return      Source address where the CRC DMA transfer just occurs
 *
 * @details     Get CRC PDMA current source address
 */
static __INLINE uint32_t CRC_PDMA_GET_CURRENT_SRC_ADDR(void)
{
    return (CRC->DMACSAR);
}

/**
 * @brief       Get CRC PDMA current byte count
 *
 * @param       None
 *
 * @return      The current remained byte count of CRC_DMA
 *
 * @details     Get CRC PDMA current byte count
 */
static __INLINE uint32_t CRC_PDMA_GET_REMAINED_CNT(void)
{
    return (CRC->DMACBCR);
}

/**
 * @brief       Enable CRC PDMA interrupt
 *
 * @param[in]   Type of interrupt of CRC PDMA. It could be
 *              CRC_BLKD_INT, CRC_TABORT_INT and their 'OR' combination (CRC_BLKD_INT | CRC_TABORT_INT)
 *
 * @return      None
 *
 * @details     Enable specified CRC PDMA interrupt
 */
static __INLINE void CRC_PDMA_INT_ENABLE(uint32_t intr)
{
    CRC->DMAIER |= (intr);
}

/**
 * @brief       Disable CRC PDMA interrupt
 *
 * @param[in]   Type of interrupt of CRC PDMA. It could be
 *              CRC_BLKD_INT, CRC_TABORT_INT and their 'OR' combination (CRC_BLKD_INT | CRC_TABORT_INT)
 *
 * @return      None
 *
 * @details     Disable specified CRC PDMA interrupt
 */
static __INLINE void CRC_PDMA_INT_DISABLE(uint32_t intr)
{
    CRC->DMAIER &= ~(intr);
}

/**
 * @brief       Get CRC PDMA interrupt status
 *
 * @param[in]   Type of interrupt of CRC PDMA. It could be CRC_BLKD_INT, CRC_TABORT_INT
 *
 * @retval      FALSE  No interrupt
 * @retval      TRUE   Specified interrupt occured
 *
 * @details     Get specified CRC PDMA interrupt status
 */
static __INLINE uint32_t CRC_PDMA_GET_IF(uint32_t intr)
{
    return (CRC->DMAISR & (intr));
}

/**
 * @brief       Clear CRC PDMA interrupt status
 *
 * @param[in]   Type of interrupt of CRC PDMA. It could be
 *              CRC_BLKD_INT, CRC_TABORT_INT and their 'OR' combination (CRC_BLKD_INT | CRC_TABORT_INT)
 *
 * @return      None
 *
 * @details     Clear specified CRC PDMA interrupt status
 */
static __INLINE void CRC_PDMA_CLR_IF(uint32_t intr)
{
    CRC->DMAISR = (intr);
}

/**
 * @brief       Write CRC data register to perform CRC operation
 *
 * @param[in]   data  32-bit data to be written to CRC data register
 *
 * @return      None
 *
 * @details     When operated in CPU PIO mode, write CRC data register to perform CRC operation
 */
static __INLINE void CRC_WRITE_DATA(uint32_t data)
{
    CRC->WDATA = (data);
}

/**
 * @brief       Get CRC PDMA internal buffer
 *
 * @param       None
 *
 * @return      DMA internal buffer
 *
 * @details     When operated in CRC DMA mode, CRC_WDATA register used as DMA internal buffer
 */
static __INLINE uint32_t CRC_PDMA_GET_INTERNAL_BUF(void)
{
    return (CRC->WDATA);
}

/**
 * @brief       Set CRC seed
 *
 * @param[in]   data  32-bit data to be used as CRC seed
 *
 * @return      None
 *
 * @details     Set CRC seed
 */
static __INLINE void CRC_SET_SEED(uint32_t data)
{
    CRC->SEED = (data);
}

/**
 * @brief       Get CRC seed
 *
 * @param       None
 *
 * @return      CRC seed value
 *
 * @details     Get CRC seed
 */
static __INLINE uint32_t CRC_GET_SEED(void)
{
    return (CRC->SEED);
}

/**
 * @brief       Get CRC checksum
 *
 * @param       None
 *
 * @return      CRC checksum value
 *
 * @details     Get CRC checksum
 */
static __INLINE uint32_t CRC_GET_CHECKSUM(void)
{
    return (CRC->CHECKSUM);
}

/*@}*/ /* end of group CRC_MACRO_FUNC */
/*@}*/ /* end of group CRC_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */
  
/*---------------------------------------------------------------------------------------------------------*/
/* Define CRC API prototype                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void DrvCRC_Init(STR_CRC_T *sParam);
void DrvCRC_DeInit(void);
void DrvCRC_EnableInt(uint32_t u32IntMask);
void DrvCRC_DisableInt(uint32_t u32IntMask);

#endif
