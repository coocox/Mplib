/**************************************************************************//**
 * @file     PDMA.h
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/06 8:08p $
 * @brief    NUC200 Series PDMA Controller Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PDMA_H__
#define __PDMA_H__

#include "NUC200Series.h"


/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup PDMA_FUNC PDMA Device Function Interface
  * @{
  */


/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA_CSRx constants definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_CSR_PDMACEN            (1UL << 0)  /*!< PDMA_CSRx setting for PDMA channel enable */
#define PDMA_CSR_SW_RST             (1UL << 1)  /*!< PDMA_CSRx setting for Software Engine Reset */
#define PDMA_CSR_MODE_SEL_M2M       (0)         /*!< PDMA_CSRx setting for PDMA Mode Selection as Memory to Memory*/
#define PDMA_CSR_MODE_SEL_P2M       (1UL << 2)  /*!< PDMA_CSRx setting for PDMA Mode Selection as Peripheral to Memory*/
#define PDMA_CSR_MODE_SEL_M2P       (2UL << 2)  /*!< PDMA_CSRx setting for PDMA Mode Selection as Memory to Peripheral*/
#define PDMA_CSR_SAD_SEL_INCREASE   (0)         /*!< PDMA_CSRx setting for Transfer Source Address Direction Selection as increase*/
#define PDMA_CSR_SAD_SEL_FIXED      (2UL << 4)  /*!< PDMA_CSRx setting for Transfer Source Address Direction Selection as fixed*/
#define PDMA_CSR_DAD_SEL_INCREASE   (0)         /*!< PDMA_CSRx setting for Transfer Destination Address Direction Selection as increase*/
#define PDMA_CSR_DAD_SEL_FIXED      (2UL << 6)  /*!< PDMA_CSRx setting for Transfer Destination Address Direction Selection as fixed*/
#define PDMA_CSR_APB_TWS_32BITS     (0)         /*!< PDMA_CSRx setting for Peripheral Transfer Width Selection as 32-bits*/
#define PDMA_CSR_APB_TWS_8BITS      (1UL << 19) /*!< PDMA_CSRx setting for Peripheral Transfer Width Selection as 8-bits*/
#define PDMA_CSR_APB_TWS_16BITS     (2UL << 19) /*!< PDMA_CSRx setting for Peripheral Transfer Width Selection as 16-bits*/
#define PDMA_CSR_TRIG_EN            (1UL << 23) /*!< PDMA_CSRx setting for Trigger Enable*/

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA_IERx constants definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_IER_TABORT_IE_ENABLE   (1UL << 0) /*!< PDMA_IERx setting for PDMA Read/Write Target Abort Interrupt Enable*/
#define PDMA_IER_BLKD_IE_ENABLE     (1UL << 1) /*!< PDMA_IERx setting for PDMA Block Transfer Done Interrupt Enable*/

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMAGCR_GCRCSR constants definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMAGCR_CLK0_EN     (1UL << 8)  /*!< PDMA_GCRCSR setting for PDMA Controller Channel 0 Clock Enable Control*/
#define PDMAGCR_CLK1_EN     (1UL << 9)  /*!< PDMA_GCRCSR setting for PDMA Controller Channel 1 Clock Enable Control*/
#define PDMAGCR_CLK2_EN     (1UL << 10) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 2 Clock Enable Control*/
#define PDMAGCR_CLK3_EN     (1UL << 11) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 3 Clock Enable Control*/
#define PDMAGCR_CLK4_EN     (1UL << 12) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 4 Clock Enable Control*/
#define PDMAGCR_CLK5_EN     (1UL << 13) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 5 Clock Enable Control*/
#define PDMAGCR_CLK6_EN     (1UL << 14) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 6 Clock Enable Control*/
#define PDMAGCR_CLK7_EN     (1UL << 15) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 7 Clock Enable Control*/
#define PDMAGCR_CLK8_EN     (1UL << 16) /*!< PDMA_GCRCSR setting for PDMA Controller Channel 8 Clock Enable Control*/

#define PDMAGCR_CRC_CLK_EN  (1UL << 24) /*!< PDMA_GCRCSR setting for CRC Controller Clock Enable Control*/
/*---------------------------------------------------------------------------------------------------------*/
/* CRC CTL Constants Definitions                                                                           */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_CTL_CRC_MODE_CCITT          0x00000000UL  /*!< CRC Polynomial Mode is CRC-CCITT                        */
#define CRC_CTL_CRC_MODE_CRC8           0x40000000UL  /*!< CRC Polynomial Mode is CRC-8                            */
#define CRC_CTL_CRC_MODE_CRC16          0x80000000UL  /*!< CRC Polynomial Mode is CRC-16                           */
#define CRC_CTL_CRC_MODE_CRC32          0xC0000000UL  /*!< CRC Polynomial Mode is CRC-32                           */
#define CRC_CTL_CPU_WDLEN_8             0x00000000UL  /*!< CPU Write Data Length is 8-bit mode                     */
#define CRC_CTL_CPU_WDLEN_16            0x10000000UL  /*!< CPU Write Data Length is 16-bit mode                    */
#define CRC_CTL_CPU_WDLEN_32            0x20000000UL  /*!< CPU Write Data Length is 32-bit mode                    */
#define CRC_CTL_CHECKSUM_COM_EN         0x08000000UL  /*!< Enable 1's complement for CRC checksum                  */
#define CRC_CTL_WDATA_COM_EN            0x04000000UL  /*!< Enable 1's complement for CRC write data in             */
#define CRC_CTL_CHECKSUM_RSV_EN         0x02000000UL  /*!< Enable bit order reverse for CRC checksum               */
#define CRC_CTL_WDATA_RSV_EN            0x01000000UL  /*!< Enable bit order reverse per byre for CRC write data in */
#define CRC_CTL_DMA_TRIG_EN             0x00800000UL  /*!< Enable CRC DMA data read or write transfer              */
#define CRC_CTL_CRC_RST                 0x00000002UL  /*!< CRC Engine Reset                                        */
#define CRC_CTL_CRCCEN_EN               0x00000001UL  /*!< Enable CRC Channel to enable CRC's operation            */


/*---------------------------------------------------------------------------------------------------------*/
/* CRC DMAIER Constants Definitions                                                                        */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_DMAIER_CRC_TABORT_IE_EN     0x0001UL  /*!< Enable CRC DMA Read/Write Target Abort Interrupt function */
#define CRC_DMAIER_CRC_BLKD_IE_EN       0x0002UL  /*!< Enable CRC DMA Block Transfer Done Interrupt function     */


/*---------------------------------------------------------------------------------------------------------*/
/* CRC DMAISR Constants Definitions                                                                        */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define CRC_DMAISR_CRC_TABORT_IF        0x0001UL  /*!< Indicate CRC DMA Read/Write Target Abort Interrupt Flag */
#define CRC_DMAISR_CRC_BLKD_IF          0x0002UL  /*!< Indicate CRC DMA Block Transfer Done Interrupt Flag     */

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA Define Macro                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
// PDSSR0 register default value is 0xFFFFFFFF 
#define _PDMAGCR_PDSSR0_SPI0_RXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<0))) |((x) << 0))  /*!< Set PDMA SPI0 RX as channel x*/
#define _PDMAGCR_PDSSR0_SPI0_TXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<4))) |((x) << 4))  /*!< Set PDMA SPI0 TX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI1_RXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<8))) |((x) << 8))  /*!< Set PDMA SPI1 RX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI1_TXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<12)))|((x) << 12)) /*!< Set PDMA SPI1 TX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI2_RXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<16)))|((x) << 16)) /*!< Set PDMA SPI2 RX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI2_TXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<20)))|((x) << 20)) /*!< Set PDMA SPI2 TX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI3_RXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<24)))|((x) << 24)) /*!< Set PDMA SPI3 RX Selection as channel x*/
#define _PDMAGCR_PDSSR0_SPI3_TXSEL(x)     (PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0&(~(0xF<<28)))|((x) << 28)) /*!< Set PDMA SPI3 TX Selection as channel x*/

// PDSSR1 register default value is 0xFFFFFFFF 
#define _PDMAGCR_PDSSR1_UART0_RXSEL(x)    (PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1&(~(0xF<<0))) |((x) << 0))  /*!< Set PDMA UART0 RX Selection as channel x*/
#define _PDMAGCR_PDSSR1_UART0_TXSEL(x)    (PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1&(~(0xF<<4))) |((x) << 4))  /*!< Set PDMA UART0 TX Selection as channel x*/
#define _PDMAGCR_PDSSR1_UART1_RXSEL(x)    (PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1&(~(0xF<<8))) |((x) << 8))  /*!< Set PDMA UART1 RX Selection as channel x*/
#define _PDMAGCR_PDSSR1_UART1_TXSEL(x)    (PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1&(~(0xF<<12)))|((x) << 12)) /*!< Set PDMA UART1 TX Selection as channel x*/
#define _PDMAGCR_PDSSR1_ADC_RXSEL(x)      (PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1&(~(0xF<<24)))|((x) << 24)) /*!< Set PDMA ADC RX Selection as channel x*/

// PDSSR2 register default value is 0xFF 
#define _PDMAGCR_PDSSR2_I2S_RXSEL(x)      (PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2&(~(0xF<<0))) |((x) << 0))  /*!< Set PDMA I2S RX Selection as channel x*/
#define _PDMAGCR_PDSSR2_I2S_TXSEL(x)      (PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2&(~(0xF<<4))) |((x) << 4))  /*!< Set PDMA I2S TX Selection as channel x*/


/*---------------------------------------------------------------------------------------------------------*/
/* CRC Macro Definitions                                                                                   */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     Reset CRC State Machine and Internal Buffer
 */
#define _CRC_RESET()                        (CRC->CTL |= CRC_CTL_CRC_RST_Msk)


/**
 * @details     Enable CRC Function
 */
#define _CRC_ENABLE()                       (CRC->CTL |= CRC_CTL_CRCCEN_Msk)


/**
 * @details     Disable CRC Function
 */
#define _CRC_DISABLE()                      (CRC->CTL &= ~CRC_CTL_CRCCEN_Msk)


/**
 * @details     Trigger CRC DMA Transfer
 */
#define _CRC_TRIG_DMA()                     (CRC->CTL |= CRC_CTL_TRIG_EN_Msk)


/**
 * @details     Enable CRC DMA Read/Write Target Abort Interrupt
 */
#define _CRC_TABORT_INT_ENABLE()            (CRC->DMAIER |= CRC_DMAIER_CRC_TABORT_IE_Msk)


/**
 * @details     Disable CRC DMA Read/Write Target Abort Interrupt
 */
#define _CRC_TABORT_INT_DISABLE()           (CRC->DMAIER &= ~CRC_DMAIER_CRC_TABORT_IE_Msk)


/**
 * @details     Enable CRC DMA Block Transfer Done Interrupt
 */
#define _CRC_BLKD_INT_ENABLE()              (CRC->DMAIER |= CRC_DMAIER_CRC_BLKD_IE_Msk)


/**
 * @details     Disable CRC DMA Block Transfer Done Interrupt
 */
#define _CRC_BLKD_INT_DISABLE()             (CRC->DMAIER &= ~CRC_DMAIER_CRC_BLKD_IE_Msk)


/**
 * @details     Get CRC DMA Read/Write Target Abort Interrupt Flag
 */
#define _CRC_GET_TABORT_INT_FLAG()          (((CRC->DMAISR & CRC_DMAISR_CRC_TABORT_IF_Msk) == CRC_DMAISR_CRC_TABORT_IF_Msk)? 1:0)


/**
 * @details     Clear CRC DMA Read/Write Target Abort Interrupt Flag
 */
#define _CRC_CLEAR_TABORT_INT_FLAG()        (CRC->DMAISR = CRC_DMAISR_CRC_TABORT_IF_Msk)
                                               

/**
 * @details     Get CRC DMA Block Transfer Done Interrupt Flag
 */
#define _CRC_GET_BLKD_INT_FLAG()            (((CRC->DMAISR & CRC_DMAISR_CRC_BLKD_IF_Msk) == CRC_DMAISR_CRC_BLKD_IF_Msk)? 1:0)


/**
 * @details     Clear CRC DMA Block Transfer Done Interrupt Flag
 */
#define _CRC_CLEAR_BLKD_INT_FLAG()          (CRC->DMAISR = CRC_DMAISR_CRC_BLKD_IF_Msk)


/**
 * @details     Set CRC DMA Transfer Source Address
 */
#define _CRC_SET_DMA_SRC_ADDRESS(x)         (CRC->DMASAR = (x))


/**
 * @details     Get CRC DMA Current Source Address 
 */
#define _CRC_GET_DMA_CURRENT_SRC_ADDRESS()  (CRC->DMACSAR)


/**
 * @details     Set CRC DMA Total Transfer Byte Count 
 */
#define _CRC_SET_DMA_TRANS_BYTE_COUNT(x)    (CRC->DMABCR = (x))


/**
 * @details     Get CRC DMA Current Remained Byte Count 
 */
#define _CRC_GET_DMA_REMAINED_BYTE_COUNT()  (CRC->DMACBCR)


/**
 * @details     Write Data to Perform CRC Operation in CRC CPU Mode
 */
#define _CRC_CPU_WRITE_DATA(x)              (CRC->WDATA = (x))


/**
 * @details     Set CRC Initial Seed Value
 */
#define _CRC_SET_SEED(x)                    (CRC->SEED = (x))


/**
 * @details     Get CRC-CCITT Polynomial Mode Checksum Value
 */
#define _CRC_GET_POLY_CCITT_CHECKSUM()      (CRC->CHECKSUM & 0xFFFF)


/**
 * @details     Get CRC-8 Polynomial Mode Checksum Value
 */
#define _CRC_GET_POLY_8_CHECKSUM()          (CRC->CHECKSUM & 0xFF)


/**
 * @details     Get CRC-16 Polynomial Mode Checksum Value
 */
#define _CRC_GET_POLY_16_CHECKSUM()         (CRC->CHECKSUM & 0xFFFF)


/**
 * @details     Get CRC-32 Polynomial Mode Checksum Value
 */
#define _CRC_GET_POLY_32_CHECKSUM()         (CRC->CHECKSUM & 0xFFFFFFFF)


/**
  * @} End of PDMA Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 


#endif  // __PDMA_H__ 
