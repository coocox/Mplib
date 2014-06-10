/****************************************************************************//**
 * @file     spi.h
 * @version  V1.00
 * $Revision: 8 $
 * $Date: 13/12/10 10:29a $
 * @brief    NUC400 series SPI driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_SPI_Driver SPI Driver
  @{
*/

/** @addtogroup NUC400_SPI_EXPORTED_CONSTANTS SPI Exported Constants
  @{
*/

#define SPI_MODE_0        (SPI_CTL_TX_NEG_Msk)                            /*!< CLKP=0; RX_NEG=0; TX_NEG=1 */
#define SPI_MODE_1        (SPI_CTL_RX_NEG_Msk)                            /*!< CLKP=0; RX_NEG=1; TX_NEG=0 */
#define SPI_MODE_2        (SPI_CTL_CLKP_Msk | SPI_CTL_RX_NEG_Msk)         /*!< CLKP=1; RX_NEG=1; TX_NEG=0 */
#define SPI_MODE_3        (SPI_CTL_CLKP_Msk | SPI_CTL_TX_NEG_Msk)         /*!< CLKP=1; RX_NEG=0; TX_NEG=1 */

#define SPI_SLAVE         (SPI_CTL_SLAVE_Msk)                             /*!< Set as slave */
#define SPI_MASTER        (0x0)                                           /*!< Set as master */

#define SPI_SS0               (0x1)                                       /*!< Set SS0 */
#define SPI_SS1               (0x2)                                       /*!< Set SS1 */
#define SPI_SS_ACTIVE_HIGH    (SPI_SSCR_SS_LVL_Msk)                       /*!< SS active high */
#define SPI_SS_ACTIVE_LOW     (0x0)                                       /*!< SS active low */

#define SPI_IE_MASK                        (0x001)                        /*!< Interrupt enable mask */
#define SPI_SSINA_INTEN_MASK               (0x002)                        /*!< Slave Slave Inactive interrupt enable mask */
#define SPI_SSACT_INTEN_MASK               (0x004)                        /*!< Slave Slave Active interrupt enable mask */
#define SPI_SLVER1_INTEN_MASK              (0x008)                        /*!< Slave Mode Error 1 interrupt enable mask */
#define SPI_SLVER0_INTEN_MASK              (0x010)                        /*!< Slave Mode Error 0 interrupt enable mask */
#define SPI_SLVTO_INTEN_MASK               (0x020)                        /*!< Slave Mode Time-out interrupt enable mask */
#define SPI_FIFO_TXTH_INTEN_MASK           (0x040)                        /*!< Transmit FIFO Threshold interrupt enable mask */
#define SPI_FIFO_RXTH_INTEN_MASK           (0x080)                        /*!< Receive FIFO Threshold interrupt enable mask */
#define SPI_FIFO_RXOV_INTEN_MASK           (0x100)                        /*!< Receive FIFO Overrun interrupt enable mask */
#define SPI_FIFO_TXUDR_INTEN_MASK          (0x200)                        /*!< Slave Transmit Under Run interrupt enable mask */
#define SPI_FIFO_RXTIMEOUT_INTEN_MASK      (0x400)                        /*!< Slave Receive Time-out interrupt enable mask */


/*@}*/ /* end of group NUC400_SPI_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_SPI_EXPORTED_FUNCTIONS SPI Exported Functions
  @{
*/

/**
  * @brief  Set time out period for slave.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @param  u32TimeoutPeriod is the period of time out.
  * @return none
  */
static __INLINE void SPI_SET_SLAVE_TIMEOUT_PERIOD(SPI_T *spi, uint32_t u32TimeoutPeriod)
{
    spi->SSCR = (spi->SSCR & ~SPI_SSCR_SLVTOPRD_Msk) | (u32TimeoutPeriod & 0xFFFF);
}

/**
  * @brief  Enable time out clear function for FIFO mode.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_TIMEOUT_FIFO_CLEAR(SPI_T *spi)
{
    spi->SSCR |= SPI_SSCR_SLVTO_FFCLR_Msk;
}

/**
  * @brief  Disable time out clear function for FIFO mode.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_TIMEOUT_FIFO_CLEAR(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_SLVTO_FFCLR_Msk;
}

/**
  * @brief  Set data out signal to low (0) if transmit under-run occurs.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_TX_UNDERRUN_DATA_LOW(SPI_T *spi)
{
    spi->FIFOCTL &= ~SPI_FIFOCTL_TXUDR_DO_Msk;
}

/**
  * @brief  Set data out signal to high (1) if transmit under-run occurs.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_TX_UNDERRUN_DATA_HIGH(SPI_T *spi)
{
    spi->FIFOCTL |= SPI_FIFOCTL_TXUDR_DO_Msk;
}

/**
  * @brief  Get the status flags.
  * @param  spi is the base address of SPI module.
  * @return status flags
  */
static __INLINE uint32_t SPI_GET_STATUS(SPI_T *spi)
{
    return ( spi->STATUS );
}

/**
  * @brief  Clear the unit transfer interrupt flag.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_CLR_UNIT_TRANS_INT_FLAG(SPI_T *spi)
{
    spi->STATUS |= SPI_STATUS_UNIT_INTSTS_Msk;
}

/**
  * @brief  Disable slave 3-wire mode.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_3WIRE_MODE(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_SLV3WIRE_Msk;
}

/**
  * @brief  Enable slave 3-wire mode.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_3WIRE_MODE(SPI_T *spi)
{
    spi->SSCR |= SPI_SSCR_SLV3WIRE_Msk;
}

/**
  * @brief  Get the count of available data in RX FIFO.
  * @param  spi is the base address of SPI module.
  * @return The count of available data in RX FIFO.
  */
static __INLINE uint32_t SPI_GET_RX_FIFO_COUNT(SPI_T *spi)
{
    return ( ((spi->STATUS & SPI_STATUS_RX_FIFO_COUNT_Msk) >> SPI_STATUS_RX_FIFO_COUNT_Pos) & 0xf );
}

/**
  * @brief  Get the Rx FIFO empty flag.
  * @param  spi is the base address of SPI module.
  * @return Rx FIFO flag
  * @retval 0: Rx FIFO is not empty
  * @retval 1: Rx FIFO is empty
  */
static __INLINE uint32_t SPI_GET_RX_FIFO_EMPTY_FLAG(SPI_T *spi)
{
    return ( (spi->STATUS & SPI_STATUS_RX_EMPTY_Msk) == SPI_STATUS_RX_EMPTY_Msk ? 1:0);
}

/**
  * @brief  Get the Tx FIFO empty flag.
  * @param  spi is the base address of SPI module.
  * @return Tx FIFO flag
  * @retval 0: Tx FIFO is not empty
  * @retval 1: Tx FIFO is empty
  */
static __INLINE uint32_t SPI_GET_TX_FIFO_EMPTY_FLAG(SPI_T *spi)
{
    return ( (spi->STATUS & SPI_STATUS_TX_EMPTY_Msk) == SPI_STATUS_TX_EMPTY_Msk ? 1:0);
}

/**
  * @brief  Get the Tx FIFO full flag.
  * @param  spi is the base address of SPI module.
  * @return Tx FIFO flag
  * @retval 0: Tx FIFO is not full
  * @retval 1: Tx FIFO is full
  */
static __INLINE uint32_t SPI_GET_TX_FIFO_FULL_FLAG(SPI_T *spi)
{
    return ( (spi->STATUS & SPI_STATUS_TX_FULL_Msk) == SPI_STATUS_TX_FULL_Msk ? 1:0);
}

/**
  * @brief  Get the datum read from R0 FIFO.
  * @param  spi is the base address of SPI module.
  * @return data in Rx register
  */
static __INLINE uint32_t SPI_READ_RX(SPI_T *spi)
{
    return (spi->RX);
}

/**
  * @brief  Write datum to TX register.
  * @param  spi is the base address of SPI module.
  * @param  u32TxData is the datum which user attempt to transfer through SPI bus.
  * @return none
  */
static __INLINE void SPI_WRITE_TX(SPI_T *spi, uint32_t u32TxData)
{
    spi->TX = u32TxData;
}

/**
  * @brief  Disable automatic slave select function and set SPI_SS pin to high state.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_SS0_HIGH(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_AUTOSS_Msk;
    spi->SSCR |= SPI_SSCR_SS_LVL_Msk;
    spi->SSCR = (spi->SSCR & ~SPI_SSCR_SS_Msk) | SPI_SS0;
}

/**
  * @brief  Disable automatic slave select function and set SPI_SS pin to low state.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_SS0_LOW(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_AUTOSS_Msk;
    spi->SSCR &= ~SPI_SSCR_SS_LVL_Msk;
    spi->SSCR = (spi->SSCR & ~SPI_SSCR_SS_Msk) | SPI_SS0;
}

/**
  * @brief  Disable automatic slave select function and set SPI_SS pin to high state.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_SS1_HIGH(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_AUTOSS_Msk;
    spi->SSCR |= SPI_SSCR_SS_LVL_Msk;
    spi->SSCR = (spi->SSCR & ~SPI_SSCR_SS_Msk) | SPI_SS1;
}

/**
  * @brief  Disable automatic slave select function and set SPI_SS pin to low state.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_SS1_LOW(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_AUTOSS_Msk;
    spi->SSCR |= SPI_SSCR_SS_LVL_Msk;
    spi->SSCR = (spi->SSCR & ~SPI_SSCR_SS_Msk) | SPI_SS1;
}

/**
  * @brief Enable byte reorder function.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_BYTE_REORDER(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_REORDER_Msk;
}

/**
  * @brief  Disable byte reorder function.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_BYTE_REORDER(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_REORDER_Msk;
}

/**
  * @brief  Set the length of suspend interval.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @param  u32SuspCycle decides the length of suspend interval.
  * @return none
  */
static __INLINE void SPI_SET_SUSPEND_CYCLE(SPI_T *spi, uint32_t u32SuspCycle)
{
    spi->CTL = (spi->CTL & ~SPI_CTL_SP_CYCLE_Msk) | (u32SuspCycle << SPI_CTL_SP_CYCLE_Pos);
}

/**
  * @brief  Set the SPI transfer sequence with LSB first.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_LSB_FIRST(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_LSB_Msk;
}

/**
  * @brief  Set the SPI transfer sequence with MSB first.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_SET_MSB_FIRST(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_LSB_Msk;
}

/**
  * @brief  Set the data width of a SPI transaction.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @param  u32Width data width
  * @return none
  */
static __INLINE void SPI_SET_DATA_WIDTH(SPI_T *spi, uint32_t u32Width)
{
    if(u32Width == 32)
        u32Width = 0;

    spi->CTL = (spi->CTL & ~SPI_CTL_DWIDTH_Msk) | (u32Width << SPI_CTL_DWIDTH_Pos);
}

/**
  * @brief  Get the SPI busy state.
  * @param  spi is the base address of SPI module.
  * @return SPI busy status
  * @retval 0: SPI module is not busy
  * @retval 1: SPI module is busy
  */
static __INLINE uint32_t SPI_IS_BUSY(SPI_T *spi)
{
    return ( (spi->STATUS & SPI_STATUS_BUSY_Msk) == SPI_STATUS_BUSY_Msk ? 1:0);
}

/**
  * @brief  Set the SPIEN bit to trigger SPI transfer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_TRIGGER(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_SPIEN_Msk;
}

/**
  * @brief  Disable SPI function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_SPIEN_Msk;
}

/**
  * @brief  Enable SPI Dual IO function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_DUAL_MODE(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_DUAL_IO_EN_Msk;
}

/**
  * @brief  Disable SPI Dual IO function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_DUAL_MODE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_DUAL_IO_EN_Msk;
}

/**
  * @brief  Set SPI Dual IO direction to input.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_DUAL_INPUT_MODE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_QD_IO_DIR_Msk;
}

/**
  * @brief  Set SPI Dual IO direction to output.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_DUAL_OUTPUT_MODE(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_QD_IO_DIR_Msk;
}

/**
  * @brief  Enable SPI QUAD IO function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_QUAD_MODE(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_QUAD_IO_EN_Msk;
}

/**
  * @brief  Disable SPI Dual IO function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_QUAD_MODE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_QUAD_IO_EN_Msk;
}

/**
  * @brief  Set SPI Quad IO direction to input.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_QUAD_INPUT_MODE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_QD_IO_DIR_Msk;
}

/**
  * @brief  Set SPI Quad IO direction to output.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_QUAD_OUTPUT_MODE(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_QD_IO_DIR_Msk;
}

/**
  * @brief  Trigger RX PDMA transfer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_TRIGGER_RX_PDMA(SPI_T *spi)
{
    spi->PDMACTL |= SPI_PDMACTL_RXPDMA_EN_Msk;
}

/**
  * @brief  Trigger TX PDMA transfer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_TRIGGER_TX_PDMA(SPI_T *spi)
{
    spi->PDMACTL |= SPI_PDMACTL_TXPDMA_EN_Msk;
}

/**
  * @brief  Disable RX PDMA transfer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_RX_PDMA(SPI_T *spi)
{
    spi->PDMACTL &= ~SPI_PDMACTL_RXPDMA_EN_Msk;
}

/**
  * @brief  Trigger TX PDMA transfer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_TX_PDMA(SPI_T *spi)
{
    spi->PDMACTL &= ~SPI_PDMACTL_TXPDMA_EN_Msk;
}

/**
  * @brief  Enable 2-bit transfer mode.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_ENABLE_2BIT_MODE(SPI_T *spi)
{
    spi->CTL |= SPI_CTL_TWOB_Msk;
}

/**
  * @brief  Disable 2-bit transfer mode.
  * @note Before calling this function, SPI must be stopped first. \ref SPI_DISABLE must be called.
  * @param  spi is the base address of SPI module.
  * @return none
  */
static __INLINE void SPI_DISABLE_2BIT_MODE(SPI_T *spi)
{
    spi->CTL &= ~SPI_CTL_TWOB_Msk;
}

uint32_t SPI_Open(SPI_T *spi,uint32_t u32MasterSlave, uint32_t u32SPIMode,  uint32_t u32DataWidth, uint32_t u32BusClock);
void SPI_Close(SPI_T *spi);
void SPI_ClearRxFIFO(SPI_T *spi);
void SPI_ClearTxFIFO(SPI_T *spi);
void SPI_DisableAutoSS(SPI_T *spi);
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock);
void SPI_SetFIFOThreshold(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
uint32_t SPI_GetBusClock(SPI_T *spi);
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask);


/*@}*/ /* end of group NUC400_SPI_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_SPI_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__SPI_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
