/******************************************************************************
 * @file     i2s.h
 * @version  V0.10
 * $Revision: 4 $
 * $Date: 13/12/04 10:36a $
 * @brief    NUC400 series I2S driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __I2S_H__
#define __I2S_H__

#include "NUC400Series.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_I2S_Driver I2S Driver
  @{
*/

/** @addtogroup NUC400_I2S_EXPORTED_CONSTANTS I2S Exported Constants
  @{
*/
#define I2S_DATABIT_8           (0 << I2S_CON_WORDWIDTH_Pos)       /*!< I2S data width is 8-bit */
#define I2S_DATABIT_16          (1 << I2S_CON_WORDWIDTH_Pos)       /*!< I2S data width is 16-bit */
#define I2S_DATABIT_24          (2 << I2S_CON_WORDWIDTH_Pos)       /*!< I2S data width is 24-bit */
#define I2S_DATABIT_32          (3 << I2S_CON_WORDWIDTH_Pos)       /*!< I2S data width is 32-bit */

/* Audio Format */
#define I2S_MONO                I2S_CON_MONO_Msk                   /*!< Mono channel */
#define I2S_STEREO              0                                  /*!< Stereo channel */

/* I2S Data Format */
#define I2S_FORMAT_MSB          I2S_CON_FORMAT_Msk                 /*!< MSB data format */
#define I2S_FORMAT_I2S          0                                  /*!< I2S data format */
#define I2S_FORMAT_PCMB         I2S_CON_FORMAT_Msk                 /*!< PCMB data format */
#define I2S_FORMAT_PCMA         0                                  /*!< PCMA data format */

/* I2S Interface */
#define I2S_PCM                 I2S_CON_PCM_Msk                    /*!< PCM interface is selected */
#define I2S_I2S                 0                                  /*!< I2S interface is selected */

/* I2S Operation mode */
#define I2S_MODE_SLAVE          I2S_CON_SLAVE_Msk                  /*!< As slave mode */
#define I2S_MODE_MASTER         0                                  /*!< As master mode */

/* I2S FIFO Threshold */
#define I2S_FIFO_TX_LEVEL_WORD_0    0                              /*!< TX threshold is 0 word */
#define I2S_FIFO_TX_LEVEL_WORD_1    (1 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 1 word */
#define I2S_FIFO_TX_LEVEL_WORD_2    (2 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 2 words */
#define I2S_FIFO_TX_LEVEL_WORD_3    (3 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 3 words */
#define I2S_FIFO_TX_LEVEL_WORD_4    (4 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 4 words */
#define I2S_FIFO_TX_LEVEL_WORD_5    (5 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 5 words */
#define I2S_FIFO_TX_LEVEL_WORD_6    (6 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 6 words */
#define I2S_FIFO_TX_LEVEL_WORD_7    (7 << I2S_CON_TXTH_Pos)        /*!< TX threshold is 7 words */

#define I2S_FIFO_RX_LEVEL_WORD_1    0                              /*!< RX threshold is 1 word */
#define I2S_FIFO_RX_LEVEL_WORD_2    (1 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 2 words */
#define I2S_FIFO_RX_LEVEL_WORD_3    (2 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 3 words */
#define I2S_FIFO_RX_LEVEL_WORD_4    (3 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 4 words */
#define I2S_FIFO_RX_LEVEL_WORD_5    (4 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 5 words */
#define I2S_FIFO_RX_LEVEL_WORD_6    (5 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 6 words */
#define I2S_FIFO_RX_LEVEL_WORD_7    (6 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 7 words */
#define I2S_FIFO_RX_LEVEL_WORD_8    (7 << I2S_CON_RXTH_Pos)        /*!< RX threshold is 8 words */

/* I2S Record Channel */
#define I2S_MONO_RIGHT          0                                  /*!< Record mono right channel */
#define I2S_MONO_LEFT           I2S_CON_RXLCH_Msk                  /*!< Record mono left channel */

/* I2S Channel */
#define I2S_RIGHT               0                                  /*!< Select right channel */
#define I2S_LEFT                1                                  /*!< Select left channel */

/*@}*/ /* end of group NUC400_I2S_EXPORTED_CONSTANTS */

/** @addtogroup NUC400_I2S_EXPORTED_FUNCTIONS I2S Exported Functions
  @{
*/
/*---------------------------------------------------------------------------------------------------------*/
/* inline functions                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
/**
  * @brief  Enable zero cross detect function.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32ChMask is the mask for left or right channel. Valid values are:
  *                    - \ref I2S_RIGHT
  *                    - \ref I2S_LEFT
  * @return none
  */
static __INLINE void I2S_ENABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == I2S_RIGHT)
        i2s->CON |= I2S_CON_RCHZCEN_Msk;
    else
        i2s->CON |= I2S_CON_LCHZCEN_Msk;
}

/**
  * @brief  Disable zero cross detect function.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32ChMask is the mask for left or right channel. Valid values are:
  *                    - \ref I2S_RIGHT
  *                    - \ref I2S_LEFT
  * @return none
  */
static __INLINE void I2S_DISABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == I2S_RIGHT)
        i2s->CON &= ~I2S_CON_RCHZCEN_Msk;
    else
        i2s->CON &= ~I2S_CON_LCHZCEN_Msk;
}

/**
  * @brief  Enable I2S Tx DMA function. I2S requests DMA to transfer data to Tx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_ENABLE_TXDMA(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_TXDMA_Msk;
}

/**
  * @brief  Disable I2S Tx DMA function. I2S requests DMA to transfer data to Tx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_DISABLE_TXDMA(I2S_T *i2s)
{
    i2s->CON &= ~I2S_CON_TXDMA_Msk;
}

/**
  * @brief  Enable I2S Rx DMA function. I2S requests DMA to transfer data from Rx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_ENABLE_RXDMA(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_RXDMA_Msk;
}

/**
  * @brief  Disable I2S Rx DMA function. I2S requests DMA to transfer data from Rx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_DISABLE_RXDMA(I2S_T *i2s)
{
    i2s->CON &= ~I2S_CON_RXDMA_Msk;
}

/**
  * @brief  Enable I2S Tx function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_ENABLE_TX(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_TXEN_Msk;
}

/**
  * @brief  Disable I2S Tx function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_DISABLE_TX(I2S_T *i2s)
{
    i2s->CON &= ~I2S_CON_TXEN_Msk;
}

/**
  * @brief  Enable I2S Rx function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_ENABLE_RX(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_RXEN_Msk;
}

/**
  * @brief  Disable I2S Rx function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_DISABLE_RX(I2S_T *i2s)
{
    i2s->CON &= ~I2S_CON_RXEN_Msk;
}

/**
  * @brief  Enable Tx Mute function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_ENABLE_TX_MUTE(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_MUTE_Msk;
}

/**
  * @brief  Disable Tx Mute function .
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_DISABLE_TX_MUTE(I2S_T *i2s)
{
    i2s->CON &= ~I2S_CON_MUTE_Msk;
}

/**
  * @brief  Clear Tx FIFO. Internal pointer is reset to FIFO start point.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_CLR_TX_FIFO(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_CLR_TXFIFO_Msk;
}

/**
  * @brief  Clear Rx FIFO. Internal pointer is reset to FIFO start point.
  * @param[in] i2s is the base address of I2S module.
  * @return none
  */
static __INLINE void I2S_CLR_RX_FIFO(I2S_T *i2s)
{
    i2s->CON |= I2S_CON_CLR_RXFIFO_Msk;
}

/**
  * @brief  This function sets the recording source channel when mono mode is used.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32Ch left or right channel. Valid values are:
  *                - \ref I2S_MONO_LEFT
  *                - \ref I2S_MONO_RIGHT
  * @return none
  */
static __INLINE void I2S_SET_MONO_RX_CHANNEL(I2S_T *i2s, uint32_t u32Ch)
{
    u32Ch == I2S_MONO_LEFT ?
    (i2s->CON |= I2S_CON_RXLCH_Msk) :
    (i2s->CON &= ~I2S_CON_RXLCH_Msk);
}

/**
  * @brief  Write data to I2S Tx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32Data: The data written to FIFO.
  * @return none
  */
static __INLINE void I2S_WRITE_TX_FIFO(I2S_T *i2s, uint32_t u32Data)
{
    i2s->TXFIFO = u32Data;
}

/**
  * @brief  Read Rx FIFO.
  * @param[in] i2s is the base address of I2S module.
  * @return Data in Rx FIFO.
  */
static __INLINE uint32_t I2S_READ_RX_FIFO(I2S_T *i2s)
{
    return i2s->RXFIFO;
}

/**
  * @brief  This function gets the interrupt flag according to the mask parameter.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32Mask is the mask for the all interrupt flags.
  * @return The masked bit value of interrupt flag.
  */
static __INLINE uint32_t I2S_GET_INT_FLAG(I2S_T *i2s, uint32_t u32Mask)
{
    return (i2s->STATUS & u32Mask);
}

/**
  * @brief  This function clears the interrupt flag according to the mask parameter.
  * @param[in] i2s is the base address of I2S module.
  * @param[in] u32Mask is the mask for the all interrupt flags.
  * @return none
  */
static __INLINE void I2S_CLR_INT_FLAG(I2S_T *i2s, uint32_t u32Mask)
{
    i2s->STATUS |= u32Mask;
}

/**
  * @brief  Get transmit FIFO level
  * @param[in] i2s is the base address of I2S module.
  * @return FIFO level
  */
static __INLINE uint32_t I2S_GET_TX_FIFO_LEVEL(I2S_T *i2s)
{
    return (((i2s->STATUS & I2S_STATUS_TX_LEVEL_Msk) >> I2S_STATUS_TX_LEVEL_Pos) & 0xF);
}

/**
  * @brief  Get receive FIFO level
  * @param[in] i2s is the base address of I2S module.
  * @return FIFO level
  */
static __INLINE uint32_t I2S_GET_RX_FIFO_LEVEL(I2S_T *i2s)
{
    return (((i2s->STATUS & I2S_STATUS_RX_LEVEL_Msk) >> I2S_STATUS_RX_LEVEL_Pos) & 0xF);
}

uint32_t I2S_Open(I2S_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat, uint32_t u32AudioInterface);
void I2S_Close(I2S_T *i2s);
void I2S_EnableInt(I2S_T *i2s, uint32_t u32Mask);
void I2S_DisableInt(I2S_T *i2s, uint32_t u32Mask);
uint32_t I2S_Enable_MCLK(I2S_T *i2s, uint32_t u32BusClock);
void I2S_Disable_MCLK(I2S_T *i2s);

/*@}*/ /* end of group NUC400_I2S_EXPORTED_FUNCTIONS */


/*@}*/ /* end of group NUC400_I2S_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#endif

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/

