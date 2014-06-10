/****************************************************************************//**
 * @file     spi.c
 * @version  V0.10
 * $Revision: 6 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series SPI driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "spi.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_SPI_Driver SPI Driver
  @{
*/


/** @addtogroup NUC400_SPI_EXPORTED_FUNCTIONS SPI Exported Functions
  @{
*/

/**
  * @brief  This function make SPI module be ready to transfer.
  *         By default, the SPI transfer sequence is MSB first and
  *         the automatic slave select function is disabled. In
  *         Slave mode, the u32BusClock must be NULL and the SPI clock
  *         divider setting will be 0.
  * @param  spi is the base address of SPI module.
  * @param  u32MasterSlave decides the SPI module is operating in master mode or in slave mode. Valid values are:
  *                    - \ref SPI_SLAVE
  *                    - \ref SPI_MASTER
  * @param  u32SPIMode decides the transfer timing. Valid values are:
  *                    - \ref SPI_MODE_0
  *                    - \ref SPI_MODE_1
  *                    - \ref SPI_MODE_2
  *                    - \ref SPI_MODE_3
  * @param  u32DataWidth decides the data width of a SPI transaction.
  * @param  u32BusClock is the expected frequency of SPI bus clock in Hz.
  * @return Actual frequency of SPI peripheral clock.
  */
uint32_t SPI_Open(SPI_T *spi, uint32_t u32MasterSlave, uint32_t u32SPIMode,  uint32_t u32DataWidth, uint32_t u32BusClock)
{
    uint32_t u32Pclk, u32Div;

    if(u32DataWidth == 32)
        u32DataWidth = 0;

    spi->CTL = u32MasterSlave | (u32DataWidth << SPI_CTL_DWIDTH_Pos) | (u32SPIMode);

    u32Pclk = CLK_GetHCLKFreq();

    u32Div = 0xffff;

    if(u32BusClock !=0 ) {
        u32Div = ((u32Pclk / u32BusClock) + 1) - 1;
        if(u32Div > 0xFFFF)
            u32Div = 0xFFFF;
        spi->CLKDIV = (spi->CLKDIV & ~0xffff) | u32Div;
    } else
        spi->CLKDIV = 0;

    return ( u32Pclk / (u32Div+1) );
}

/**
  * @brief Reset SPI module and disable SPI peripheral clock.
  * @param  spi is the base address of SPI module.
  * @return none
  */
void SPI_Close(SPI_T *spi)
{
    /* Reset SPI */
    if((uint32_t)spi == SPI0_BASE) {
        SYS->IPRSTC2 |= SYS_IPRSTC2_SPI0_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_SPI0_RST_Msk;
    } else if((uint32_t)spi == SPI1_BASE) {
        SYS->IPRSTC2 |= SYS_IPRSTC2_SPI1_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_SPI1_RST_Msk;
    } else if((uint32_t)spi == SPI2_BASE) {
        SYS->IPRSTC2 |= SYS_IPRSTC2_SPI2_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_SPI2_RST_Msk;
    } else {
        SYS->IPRSTC2 |= SYS_IPRSTC2_SPI3_RST_Msk;
        SYS->IPRSTC2 &= ~SYS_IPRSTC2_SPI3_RST_Msk;
    }
}

/**
  * @brief Clear Rx FIFO buffer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
void SPI_ClearRxFIFO(SPI_T *spi)
{
    spi->FIFOCTL |= SPI_FIFOCTL_RX_CLR_Msk;
}

/**
  * @brief Clear Tx FIFO buffer.
  * @param  spi is the base address of SPI module.
  * @return none
  */
void SPI_ClearTxFIFO(SPI_T *spi)
{
    spi->FIFOCTL |= SPI_FIFOCTL_TX_CLR_Msk;
}

/**
  * @brief Disable the automatic slave select function.
  * @param  spi is the base address of SPI module.
  * @return none
  */
void SPI_DisableAutoSS(SPI_T *spi)
{
    spi->SSCR &= ~SPI_SSCR_AUTOSS_Msk;
}

/**
  * @brief Enable the automatic slave select function. Only available in Master mode.
  * @param  spi is the base address of SPI module.
  * @param  u32SSPinMask specifies slave select pins. Valid values are:
  *                     - \ref SPI_SS0
  *                     - \ref SPI_SS1
  * @param  u32ActiveLevel specifies the active level of slave select signal. Valid values are:
  *                     - \ref SPI_SS_ACTIVE_HIGH
  *                     - \ref SPI_SS_ACTIVE_LOW
  * @return none
  */
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel)
{
    spi->SSCR |= (u32SSPinMask | u32ActiveLevel) | SPI_SSCR_AUTOSS_Msk;
}

/**
  * @brief Set the SPI bus clock. Only available in Master mode.
  * @param  spi is the base address of SPI module.
  * @param  u32BusClock is the expected frequency of SPI bus clock.
  * @return Actual frequency of SPI peripheral clock.
  */
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock)
{
    uint32_t u32Pclk = CLK_GetHCLKFreq();
    uint32_t u32Div = 0xffff;

    if(u32BusClock !=0 ) {
        u32Div = ((u32Pclk / u32BusClock) + 1) - 1;
        if(u32Div > 0xFFFF)
            u32Div = 0xFFFF;
        spi->CLKDIV = (spi->CLKDIV & ~0xffff) | u32Div;
    } else
        spi->CLKDIV = 0;

    return ( u32Pclk / (u32Div+1) );
}

/**
  * @brief Set Tx FIFO threshold and Rx FIFO threshold configurations.
  * @param  spi is the base address of SPI module.
  * @param  u32TxThreshold decides the Tx FIFO threshold.
  * @param  u32RxThreshold decides the Rx FIFO threshold.
  * @return none
  */
void SPI_SetFIFOThreshold(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold)
{
    spi->FIFOCTL = (spi->FIFOCTL & ~(SPI_FIFOCTL_TX_THRESHOLD_Msk | SPI_FIFOCTL_RX_THRESHOLD_Msk) |
                    (u32TxThreshold << SPI_FIFOCTL_TX_THRESHOLD_Pos) |
                    (u32RxThreshold << SPI_FIFOCTL_RX_THRESHOLD_Pos));
}

/**
  * @brief Get the actual frequency of SPI bus clock. Only available in Master mode.
  * @param  spi is the base address of SPI module.
  * @return Actual SPI bus clock frequency.
  */
uint32_t SPI_GetBusClock(SPI_T *spi)
{
    uint32_t u32Div;
    uint32_t u32ApbClock;

    u32ApbClock = CLK_GetHCLKFreq();
    u32Div = spi->CLKDIV & 0xff;
    return (u32ApbClock / (u32Div + 1));
}

/**
  * @brief Enable FIFO related interrupts specified by u32Mask parameter.
  * @param  spi is the base address of SPI module.
  * @param  u32Mask is the combination of all related interrupt enable bits.
  *         Each bit corresponds to a interrupt bit.
  *         This parameter decides which interrupts will be enabled. Valid values are:
  *           - \ref SPI_IE_MASK
  *           - \ref SPI_SSINA_INTEN_MASK
  *           - \ref SPI_SSACT_INTEN_MASK
  *           - \ref SPI_SLVER1_INTEN_MASK
  *           - \ref SPI_SLVER0_INTEN_MASK
  *           - \ref SPI_SLVTO_INTEN_MASK
  *           - \ref SPI_FIFO_TXTH_INTEN_MASK
  *           - \ref SPI_FIFO_RXTH_INTEN_MASK
  *           - \ref SPI_FIFO_RXOV_INTEN_MASK
  *           - \ref SPI_FIFO_TXUDR_INTEN_MASK
  *           - \ref SPI_FIFO_RXTIMEOUT_INTEN_MASK
  * @return none
  */
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask)
{
    if((u32Mask & SPI_IE_MASK) == SPI_IE_MASK)
        spi->CTL |= SPI_CTL_UNIT_INTEN_Msk;

    if((u32Mask & SPI_SSINA_INTEN_MASK) == SPI_SSINA_INTEN_MASK)
        spi->SSCR |= SPI_SSCR_SSINA_INTEN_Msk;

    if((u32Mask & SPI_SSACT_INTEN_MASK) == SPI_SSACT_INTEN_MASK)
        spi->SSCR |= SPI_SSCR_SSACT_INTEN_Msk;

    if((u32Mask & SPI_SLVER1_INTEN_MASK) == SPI_SLVER1_INTEN_MASK)
        spi->SSCR |= SPI_SSCR_SLVER1_INTEN_Msk;

    if((u32Mask & SPI_SLVER0_INTEN_MASK) == SPI_SLVER0_INTEN_MASK)
        spi->SSCR |= SPI_SSCR_SLVER0_INTEN_Msk;

    if((u32Mask & SPI_SLVTO_INTEN_MASK) == SPI_SLVTO_INTEN_MASK)
        spi->SSCR |= SPI_SSCR_SLVTO_INTEN_Msk;

    if((u32Mask & SPI_FIFO_TXTH_INTEN_MASK) == SPI_FIFO_TXTH_INTEN_MASK)
        spi->FIFOCTL |= SPI_FIFOCTL_TXTH_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXTH_INTEN_MASK) == SPI_FIFO_RXTH_INTEN_MASK)
        spi->FIFOCTL |= SPI_FIFOCTL_RXTH_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXOV_INTEN_MASK) == SPI_FIFO_RXOV_INTEN_MASK)
        spi->FIFOCTL |= SPI_FIFOCTL_RXOV_INTEN_Msk;

    if((u32Mask & SPI_FIFO_TXUDR_INTEN_MASK) == SPI_FIFO_TXUDR_INTEN_MASK)
        spi->FIFOCTL |= SPI_FIFOCTL_TXUDR_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXTIMEOUT_INTEN_MASK) == SPI_FIFO_RXTIMEOUT_INTEN_MASK)
        spi->FIFOCTL |= SPI_FIFOCTL_RXTO_INTEN_Msk;
}

/**
  * @brief Disable FIFO related interrupts specified by u32Mask parameter.
  * @param  spi is the base address of SPI module.
  * @param  u32Mask is the combination of all related interrupt enable bits.
  *         Each bit corresponds to a interrupt bit.
 *          This parameter decides which interrupts will be enabled. Valid values are:
  *           - \ref SPI_IE_MASK
  *           - \ref SPI_SSINA_INTEN_MASK
  *           - \ref SPI_SSACT_INTEN_MASK
  *           - \ref SPI_SLVER1_INTEN_MASK
  *           - \ref SPI_SLVER0_INTEN_MASK
  *           - \ref SPI_SLVTO_INTEN_MASK
  *           - \ref SPI_FIFO_TXTH_INTEN_MASK
  *           - \ref SPI_FIFO_RXTH_INTEN_MASK
  *           - \ref SPI_FIFO_RXOV_INTEN_MASK
  *           - \ref SPI_FIFO_TXUDR_INTEN_MASK
  *           - \ref SPI_FIFO_RXTIMEOUT_INTEN_MASK
  * @return none
  */
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask)
{
    if((u32Mask & SPI_IE_MASK) == SPI_IE_MASK)
        spi->CTL &= ~SPI_CTL_UNIT_INTEN_Msk;

    if((u32Mask & SPI_SSINA_INTEN_MASK) == SPI_SSINA_INTEN_MASK)
        spi->SSCR &= ~SPI_SSCR_SSINA_INTEN_Msk;

    if((u32Mask & SPI_SSACT_INTEN_MASK) == SPI_SSACT_INTEN_MASK)
        spi->SSCR &= ~SPI_SSCR_SSACT_INTEN_Msk;

    if((u32Mask & SPI_SLVER1_INTEN_MASK) == SPI_SLVER1_INTEN_MASK)
        spi->SSCR &= ~SPI_SSCR_SLVER1_INTEN_Msk;

    if((u32Mask & SPI_SLVER0_INTEN_MASK) == SPI_SLVER0_INTEN_MASK)
        spi->SSCR &= ~SPI_SSCR_SLVER0_INTEN_Msk;

    if((u32Mask & SPI_SLVTO_INTEN_MASK) == SPI_SLVTO_INTEN_MASK)
        spi->SSCR &= ~SPI_SSCR_SLVTO_INTEN_Msk;

    if((u32Mask & SPI_FIFO_TXTH_INTEN_MASK) == SPI_FIFO_TXTH_INTEN_MASK)
        spi->FIFOCTL &= ~SPI_FIFOCTL_TXTH_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXTH_INTEN_MASK) == SPI_FIFO_RXTH_INTEN_MASK)
        spi->FIFOCTL &= ~SPI_FIFOCTL_RXTH_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXOV_INTEN_MASK) == SPI_FIFO_RXOV_INTEN_MASK)
        spi->FIFOCTL &= ~SPI_FIFOCTL_RXOV_INTEN_Msk;

    if((u32Mask & SPI_FIFO_TXUDR_INTEN_MASK) == SPI_FIFO_TXUDR_INTEN_MASK)
        spi->FIFOCTL &= ~SPI_FIFOCTL_TXUDR_INTEN_Msk;

    if((u32Mask & SPI_FIFO_RXTIMEOUT_INTEN_MASK) == SPI_FIFO_RXTIMEOUT_INTEN_MASK)
        spi->FIFOCTL &= ~SPI_FIFOCTL_RXTO_INTEN_Msk;
}

/*@}*/ /* end of group NUC400_SPI_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_SPI_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
