/**************************************************************************//**
 * @file     pdma.h
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 13/12/04 9:40a $
 * @brief    NUC400 series PDMA driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __PDMA_H__
#define __PDMA_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_PDMA_Driver PDMA Driver
  @{
*/

/** @addtogroup NUC400_PDMA_EXPORTED_CONSTANTS PDMA Exported Constants
  @{
*/
#define PDMA_CH_MAX    16   /*!< Specify Maximum Channels of PDMA */

/*---------------------------------------------------------------------------------------------------------*/
/*  operation Mode Constant Definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_OP_STOP        0x00000000UL            /*!<DMA Stop Mode */
#define PDMA_OP_BASIC       0x00000001UL            /*!<DMA Basic Mode */
#define PDMA_OP_SCATTER     0x00000002UL            /*!<DMA Scatter-gather Mode */

/*---------------------------------------------------------------------------------------------------------*/
/*  Data Width Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_WIDTH_8        0x00000000UL            /*!<DMA Transfer Width 8-bit */
#define PDMA_WIDTH_16       0x00001000UL            /*!<DMA Transfer Width 16-bit */
#define PDMA_WIDTH_32       0x00002000UL            /*!<DMA Transfer Width 32-bit */

/*---------------------------------------------------------------------------------------------------------*/
/*  Address Attribute Constant Definitions                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_SAR_INC        0x00000000UL            /*!<DMA SAR increment */
#define PDMA_SAR_FIX        0x00000300UL            /*!<DMA SAR fix address */
#define PDMA_DAR_INC        0x00000000UL            /*!<DMA DAR increment */
#define PDMA_DAR_FIX        0x00000C00UL            /*!<DMA DAR fix address */

/*---------------------------------------------------------------------------------------------------------*/
/*  Burst Mode Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_REQ_SINGLE     0x00000004UL            /*!<DMA Single Request */
#define PDMA_REQ_BURST      0x00000000UL            /*!<DMA Burst Request */

#define PDMA_BURST_128      0x00000000UL            /*!<DMA Burst 128 Transfers */
#define PDMA_BURST_64       0x00000010UL            /*!<DMA Burst 64 Transfers */
#define PDMA_BURST_32       0x00000020UL            /*!<DMA Burst 32 Transfers */
#define PDMA_BURST_16       0x00000030UL            /*!<DMA Burst 16 Transfers */
#define PDMA_BURST_8        0x00000040UL            /*!<DMA Burst 8 Transfers */
#define PDMA_BURST_4        0x00000050UL            /*!<DMA Burst 4 Transfers */
#define PDMA_BURST_2        0x00000060UL            /*!<DMA Burst 2 Transfers */
#define PDMA_BURST_1        0x00000070UL            /*!<DMA Burst 1 Transfers */

/*---------------------------------------------------------------------------------------------------------*/
/*  Peripheral Transfer Mode Constant Definitions                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_SPI0_TX        0x00000000UL            /*!<DMA Connect to SPI0 TX */
#define PDMA_SPI1_TX        0x00000001UL            /*!<DMA Connect to SPI1 TX */
#define PDMA_SPI2_TX        0x00000002UL            /*!<DMA Connect to SPI2 TX */
#define PDMA_SPI3_TX        0x00000003UL            /*!<DMA Connect to SPI3 TX */
#define PDMA_UART0_TX       0x00000004UL            /*!<DMA Connect to UART0 TX */
#define PDMA_UART1_TX       0x00000005UL            /*!<DMA Connect to UART1 TX */
#define PDMA_UART2_TX       0x00000006UL            /*!<DMA Connect to UART2 TX */
#define PDMA_UART3_TX       0x00000007UL            /*!<DMA Connect to UART3 TX */
#define PDMA_UART4_TX       0x00000008UL            /*!<DMA Connect to UART4 TX */
#define PDMA_UART5_TX       0x00000009UL            /*!<DMA Connect to UART5 TX */
#define PDMA_I2S_TX         0x0000000BUL            /*!<DMA Connect to I2S TX */
#define PDMA_I2S1_TX        0x0000000CUL            /*!<DMA Connect to I2S1 TX */
#define PDMA_SPI0_RX        0x0000000DUL            /*!<DMA Connect to SPI0 RX */
#define PDMA_SPI1_RX        0x0000000EUL            /*!<DMA Connect to SPI1 RX */
#define PDMA_SPI2_RX        0x0000000FUL            /*!<DMA Connect to SPI2 RX */
#define PDMA_SPI3_RX        0x00000010UL            /*!<DMA Connect to SPI3 RX */
#define PDMA_UART0_RX       0x00000011UL            /*!<DMA Connect to UART0 RX */
#define PDMA_UART1_RX       0x00000012UL            /*!<DMA Connect to UART1 RX */
#define PDMA_UART2_RX       0x00000013UL            /*!<DMA Connect to UART2 RX */
#define PDMA_UART3_RX       0x00000014UL            /*!<DMA Connect to UART3 RX */
#define PDMA_UART4_RX       0x00000015UL            /*!<DMA Connect to UART4 RX */
#define PDMA_UART5_RX       0x00000016UL            /*!<DMA Connect to UART5 RX */
#define PDMA_ADC            0x00000018UL            /*!<DMA Connect to ADC */
#define PDMA_I2S_RX         0x00000019UL            /*!<DMA Connect to I2S TX */
#define PDMA_I2S1_RX        0x0000001AUL            /*!<DMA Connect to I2S1 TX */
#define PDMA_MEM            0x0000001FUL            /*!<DMA Connect to Memory */

/*@}*/ /* end of group NUC400_PDMA_EXPORTED_CONSTANTS */

/** @addtogroup NUC400_PDMA_EXPORTED_FUNCTIONS PDMA Exported Functions
  @{
*/

/**
 * @brief       Get PDMA Interrupt Status
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     This macro gets the interrupt status.
 */
#define PDMA_GET_INT_STATUS()   ((uint32_t)(PDMA->ISR))

/**
 * @brief       Get Transfer Done Interrupt Status
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     Get the transfer done Interrupt status.
 */
#define PDMA_GET_TD_STS()           ((uint32_t)(PDMA->TDF))

/**
 * @brief       Clear Transfer Done Interrupt Status
 *
 * @param[in]   u32Mask     The channel mask
 *
 * @return      None
 *
 * @details     Clear the transfer done Interrupt status.
 */
#define PDMA_CLR_TD_FLAG(u32Mask)   ((uint32_t)(PDMA->TDF = u32Mask))

/**
 * @brief       Get Target Abort Interrupt Status
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     Get the target abort Interrupt status.
 */
#define PDMA_GET_ABORT_STS()        ((uint32_t)(PDMA->ABTF))

/**
 * @brief       Clear Target Abort Interrupt Status
 *
 * @param[in]   u32Mask     The channel mask
 *
 * @return      None
 *
 * @details     Clear the target abort Interrupt status.
 */
#define PDMA_CLR_ABORT_FLAG(u32Mask)    ((uint32_t)(PDMA->ABTF = u32Mask))

/**
 * @brief       Get Scatter-Gather Table Empty Interrupt Status
 *
 * @param[in]   None
 *
 * @return      None
 *
 * @details     Get the scatter-gather table empty Interrupt status.
 */
#define PDMA_GET_EMPTY_STS()        ((uint32_t)(PDMA->SCATDF))

/**
 * @brief       Clear Scatter-Gather Table Empty Interrupt Status
 *
 * @param[in]   u32Mask     The channel mask
 *
 * @return      None
 *
 * @details     Clear the scatter-gather table empty Interrupt status.
 */
#define PDMA_CLR_EMPTY_FLAG(u32Mask)    ((uint32_t)(PDMA->SCATDF = u32Mask))

/**
 * @brief       Clear Timeout Interrupt Status
 *
 * @param[in]   u32Ch     The selected channel
 *
 * @return      None
 *
 * @details     Clear the selected channel timeout interrupt status.
 */
#define PDMA_CLR_TMOUT_FLAG(u32Ch)  ((uint32_t)(PDMA->ISR = (1 << (u32Ch + 8))))

/**
 * @brief       Check Channel Status
 *
 * @param[in]   u32Ch     The selected channel
 *
 * @return      0 = idle; 1 = busy
 *
 * @details     Check the selected channel is busy or not.
 */
#define PDMA_IS_CH_BUSY(u32Ch)    ((uint32_t)(PDMA->REQACTF & (1 << u32Ch))? 1 : 0)

/**
 * @brief       Set Source Address
 *
 * @param[in]   u32Ch     The selected channel
 * @param[in]   u32Addr   The selected address
 *
 * @return      None
 *
 * @details     This macro set the selected channel source address.
 */
#define PDMA_SET_SRC_ADDR(u32Ch, u32Addr) ((uint32_t)(PDMA->DSCT[u32Ch].ENDSAR = u32Addr))

/**
 * @brief       Set Destination Address
 *
 * @param[in]   u32Ch     The selected channel
 * @param[in]   u32Addr   The selected address
 *
 * @return      None
 *
 * @details     This macro set the selected channel destination address.
 */
#define PDMA_SET_DST_ADDR(u32Ch, u32Addr) ((uint32_t)(PDMA->DSCT[u32Ch].ENDDAR = u32Addr))

/**
 * @brief       Set Transfer Count
 *
 * @param[in]   u32Ch     The selected channel
 * @param[in]   u32Count  Transfer Count
 *
 * @return      None
 *
 * @details     This macro set the selected channel transfer count.
 */
#define PDMA_SET_TRANS_CNT(u32Ch, u32Count) ((uint32_t)(PDMA->DSCT[u32Ch].CTRL=(PDMA->DSCT[u32Ch].CTRL&~PDMA_DSCT_CTRL_TFR_CNT_Msk)|(u32TransCount << PDMA_DSCT_CTRL_TFR_CNT_Pos))

/**
 * @brief       Set Scatter-gather descriptor Address
 *
 * @param[in]   u32Ch     The selected channel
 * @param[in]   u32Addr   The descriptor address
 *
 * @return      None
 *
 * @details     This macro set the selected channel scatter-gather descriptor address.
 */
#define PDMA_SET_SCATTER_DESC(u32Ch, u32Addr) ((uint32_t)(PDMA->DSCT[u32Ch].NEXT = u32DescAddr - (PDMA->SCATBA)))

/**
 * @brief       Stop the channel
 *
 * @param[in]   u32Ch     The selected channel
 *
 * @return      None
 *
 * @details     This macro stop the selected channel.
 */
#define PDMA_STOP(u32Ch) ((uint32_t)(PDMA->STOP = (1 << u32Ch)))



void PDMA_Open(uint32_t u32Mask);
void PDMA_Close(void);
void PDMA_SetTransferCnt(uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(uint32_t u32Ch, uint32_t u32Periphral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_SetBurstType(uint32_t u32Ch, uint32_t u32BurstType, uint32_t u32BurstSize);
void PDMA_SetTimeOut(uint32_t u32Ch, uint32_t u32OnOff, uint32_t u32TimeOutCnt);
void PDMA_Trigger(uint32_t u32Ch);
void PDMA_EnableInt(uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(uint32_t u32Ch, uint32_t u32Mask);



/*@}*/ /* end of group NUC400_PDMA_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_PDMA_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__PDMA_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
