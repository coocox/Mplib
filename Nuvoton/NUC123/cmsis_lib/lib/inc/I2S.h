/**************************************************************************//**
 * @file     I2S.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/07/06 4:29p $
 * @brief    NUC123 Series I2S Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __I2S_H__
#define __I2S_H__

/*---------------------------------------------------------------------------------------------------------*/
/* Include related headers                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 Macro
  * @{
  */

/** @addtogroup I2S_MACRO I2S Macro
  * @{
  */

/** @addtogroup I2S_MACRO_CONTANT I2S Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* I2S constant definitions                                                                                */
/*---------------------------------------------------------------------------------------------------------*/

#define I2S_CFG_FORMAT_PCMA         (I2S_CON_PCM_Msk|0)                     /*!< I2S Data Format: PCM mode A */
#define I2S_CFG_FORMAT_PCMB         (I2S_CON_PCM_Msk|I2S_CON_FORMAT_Msk)    /*!< I2S Data Format: PCM mode B */
#define I2S_CFG_FORMAT_MSB_JUST     (0|I2S_CON_FORMAT_Msk)                  /*!< I2S Data Format: MSB justified data format */
#define I2S_CFG_FORMAT_I2S          0                                       /*!< I2S Data Format: I2S */

#define I2S_CFG_CHANNEL_MONO_LEFT   (I2S_CON_MONO_Msk|I2S_CON_RXLCH_Msk)    /*!< I2S Channel: Mono Left channel */
#define I2S_CFG_CHANNEL_MONO_RIGHT  (I2S_CON_MONO_Msk|0)                    /*!< I2S Channel: Mono Right channel */
#define I2S_CFG_CHANNEL_STEREO      0                                       /*!< I2S Channel: Stereo */

#define I2S_CFG_MASTER              0                                       /*!< I2S Master Mode */
#define I2S_CFG_SLAVE               I2S_CON_SLAVE_Msk                       /*!< I2S Slave Mode */
#define I2S_CFG_MCK_EN              I2S_CON_MCLKEN_Msk                      /*!< I2S MCK Enable */
#define I2S_CFG_MCK_DIS             0                                       /*!< I2S MCK Disable */

#define I2S_CFG_RX_THRES_1          (0ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 1-word */
#define I2S_CFG_RX_THRES_2          (1ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 2-word */
#define I2S_CFG_RX_THRES_3          (2ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 3-word */
#define I2S_CFG_RX_THRES_4          (3ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 4-word */
#define I2S_CFG_RX_THRES_5          (4ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 5-word */
#define I2S_CFG_RX_THRES_6          (5ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 6-word */
#define I2S_CFG_RX_THRES_7          (6ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 7-word */
#define I2S_CFG_RX_THRES_8          (7ul<<I2S_CON_RXTH_Pos)                 /*!< I2S Rx Buffer Threshold 8-word */

#define I2S_CFG_TX_THRES_0          (0ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 1-word */
#define I2S_CFG_TX_THRES_1          (1ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 2-word */
#define I2S_CFG_TX_THRES_2          (2ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 3-word */
#define I2S_CFG_TX_THRES_3          (3ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 4-word */
#define I2S_CFG_TX_THRES_4          (4ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 5-word */
#define I2S_CFG_TX_THRES_5          (5ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 6-word */
#define I2S_CFG_TX_THRES_6          (6ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 7-word */
#define I2S_CFG_TX_THRES_7          (7ul<<I2S_CON_TXTH_Pos)                 /*!< I2S Tx Buffer Threshold 8-word */

#define I2S_CFG_WORDWIDTH_8         (0ul<<I2S_CON_WORDWIDTH_Pos)            /*!< I2S Data Size 8-bit */
#define I2S_CFG_WORDWIDTH_16        (1ul<<I2S_CON_WORDWIDTH_Pos)            /*!< I2S Data Size 16-bit */
#define I2S_CFG_WORDWIDTH_24        (2ul<<I2S_CON_WORDWIDTH_Pos)            /*!< I2S Data Size 24-bit */
#define I2S_CFG_WORDWIDTH_32        (3ul<<I2S_CON_WORDWIDTH_Pos)            /*!< I2S Data Size 32-bit */

#define I2S_CFG_TXDMA               I2S_CON_TXDMA_Msk                       /*!< I2S Tx DMA enable */
#define I2S_CFG_RXDMA               I2S_CON_RXDMA_Msk                       /*!< I2S Rx DMA enable */

#define I2S_CFG_MUTE                I2S_CON_MUTE_Msk                        /*!< I2S Mute Enable */
#define I2S_CFG_RXEN                I2S_CON_RXEN_Msk                        /*!< I2S Rx Enable */
#define I2S_CFG_TXEN                I2S_CON_TXEN_Msk                        /*!< I2S Tx Enable */
#define I2S_CFG_EN                  I2S_CON_I2SEN_Msk                       /*!< I2S Enable */

#define I2S_INT_LZC                 I2S_IE_LZCIE_Msk                        /*!< I2S Interrupt Left Channel Zero Cross */
#define I2S_INT_RZC                 I2S_IE_RZCIE_Msk                        /*!< I2S Interrupt Right Channel Zero Cross */
#define I2S_INT_TXTH                I2S_IE_TXTHIE_Msk                       /*!< I2S Interrupt Tx under threshold */
#define I2S_INT_TXOVF               I2S_IE_TXOVFIE_Msk                      /*!< I2S Interrupt Tx Overflow */
#define I2S_INT_TXUDF               I2S_IE_TXUDFIE_Msk                      /*!< I2S Interrupt Tx underflow */
#define I2S_INT_RXTH                I2S_IE_RXTHIE_Msk                       /*!< I2S Interrupt Rx over threshold */
#define I2S_INT_RXOVF               I2S_IE_RXOVFIE_Msk                      /*!< I2S Interrupt Rx Overflow */
#define I2S_INT_RXUDF               I2S_IE_RXUDFIE_Msk                      /*!< I2S Interrupt Rx underflow */

#define I2S_INTF_LZC                I2S_STATUS_LZCF_Msk                     /*!< I2S Interrupt flag Left Channel Zero Cross */
#define I2S_INTF_RZC                I2S_STATUS_RZCF_Msk                     /*!< I2S Interrupt flag Right Channel Zero Cross */
#define I2S_INTF_TXOVF              I2S_STATUS_TXOVF_Msk                    /*!< I2S Interrupt flag Tx Overflow */
#define I2S_INTF_TXUDF              I2S_STATUS_TXUDF_Msk                    /*!< I2S Interrupt flag Tx Underflow */
#define I2S_INTF_RXOVF              I2S_STATUS_RXOVF_Msk                    /*!< I2S Interrupt flag Rx Overflow */
#define I2S_INTF_RXUDF              I2S_STATUS_RXUDF_Msk                    /*!< I2S Interrupt flag Rx Underflow */
#define I2S_INTF_TXINT              I2S_STATUS_I2STXINT_Msk                 /*!< I2S Interrupt flag Tx Interrupt */
#define I2S_INTF_RXINT              I2S_STATUS_I2SRXINT_Msk                 /*!< I2S Interrupt flag Rx Interrupt */

#define I2S_STAT_TX_BUSY            I2S_STATUS_TXBUSY_Msk                   /*!< I2S State Tx Busy */
#define I2S_STAT_TX_EMPTY           I2S_STATUS_TXEMPTY_Msk                  /*!< I2S State Tx FIFO Empty */
#define I2S_STAT_TX_FULL            I2S_STATUS_TXFULL_Msk                   /*!< I2S State Tx FIFO Full */
#define I2S_STAT_TX_THRESHOLD       I2S_STATUS_TXTHF_Msk                    /*!< I2S State Tx FIFO Under Threshold */
#define I2S_STAT_RX_EMPTY           I2S_STATUS_RXEMPTY_Msk                  /*!< I2S State Rx FIFO Empty */
#define I2S_STAT_RX_FULL            I2S_STATUS_RXFULL_Msk                   /*!< I2S State Rx FIFO Full */
#define I2S_STAT_RX_THRESHOLD       I2S_STATUS_RXTHF_Msk                    /*!< I2S State Rx FIFO Over Threshold */
#define I2S_STAT_CHANNEL_MASK       I2S_STATUS_RIGHT_Msk                    /*!< I2S State Current Channel Mask */
#define I2S_STAT_CHANNEL_RIGHT      I2S_STATUS_RIGHT_Msk                    /*!< I2S State Current Channel is Right Channel */
#define I2S_STAT_CHANNEL_LEFT       0                                       /*!< I2S State Current Channel is Left Channel */

/*---------------------------------------------------------------------------------------------------------*/
/*  Structure definition                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct DRVI2S_STRUCT
{
    uint32_t	u32ClkSrc;          /*!<  I2S clock source */
    uint32_t	u32SampleRate;      /*!<  I2S samplerate */
    uint32_t	u32WordWidth;       /*!<  I2S data width */
    uint32_t	u32Mode;            /*!<  I2S work mode */
    uint32_t	u32AudioFormat;     /*!<  I2S audio format */
    uint32_t	u32DataFormat;      /*!<  I2S data format */
    uint32_t	u32TxFIFOThreshold;	/*!<  I2S Transmit FIFO threshold level */
    uint32_t	u32RxFIFOThreshold;	/*!<  I2S Receive FIFO threshold level */
}STR_I2S_T;

/*@}*/ /* end of group I2S_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup I2S_MACRO_FUNC I2S Macro Func
  @{
*/

/**
 * @brief      Clear Rx FIFO
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function clears I2S Rx FIFO.
 *
 */
static __INLINE void I2S_CLR_RXFIFO(void)
{
    I2S->CON |= I2S_CON_CLR_RXFIFO_Msk;
}

/**
 * @brief      Clear Tx FIFO
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function clears I2S Tx FIFO.
 *
 */
static __INLINE void I2S_CLR_TXFIFO(void)
{
    I2S->CON |= I2S_CON_CLR_TXFIFO_Msk;
}

/**
 * @brief      Assign I2S configuration
 *
 * @param[in]  Config      configuration value, should be ored by:
 *                          - I2S_CFG_MASTER/I2S_CFG_SLAVE
 *                          - I2S_CFG_MCK_EN/I2S_CFG_MCK_DIS
 *                          - I2S_CFG_CHANNEL_MONO_LEFT/I2S_CFG_CHANNEL_MONO_RIGHT/I2S_CFG_CHANNEL_STEREO
 *                          - I2S_CFG_FORMAT_PCMA/I2S_CFG_FORMAT_PCMB/I2S_CFG_FORMAT_MSB_JUST/I2S_CFG_FORMAT_I2S
 *                          - I2S_CFG_WORDWIDTH_8/I2S_CFG_WORDWIDTH_16/I2S_CFG_WORDWIDTH_24/I2S_CFG_WORDWIDTH_32
 *                          - I2S_CFG_MUTE
 *                          - I2S_CFG_RXEN
 *                          - I2S_CFG_RXDMA
 *                          - I2S_CFG_TXEN
 *                          - I2S_CFG_TXDMA
 *                          - I2S_CFG_EN
 *                          - I2S_CFG_TX_THRES_X
 *                          - I2S_CFG_RX_THRES_X
 *
 * @return     None
 *
 * @details    This function Assign I2S configuration.
 *
 */
static __INLINE void I2S_ASSIGN_CONFIG(uint32_t config)
{
    I2S->CON = (config);
}

/**
 * @brief      Enable I2S Rx DMA
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function enables I2S Rx DMA.
 *
 */
static __INLINE void I2S_ENABLE_RXDMA(void)
{
    I2S->CON |= I2S_CFG_RXDMA;
}

/**
 * @brief      Disable I2S Rx DMA
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function disables I2S Rx DMA.
 *
 */
static __INLINE void I2S_DISABLE_RXDMA(void)
{
    I2S->CON &= ~I2S_CFG_RXDMA;
}

/**
 * @brief      Enable I2S Tx DMA
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function enables I2S Tx DMA.
 *
 */
static __INLINE void I2S_ENABLE_TXDMA(void)
{
    I2S->CON |= I2S_CFG_TXDMA;
}

/**
 * @brief      Disable I2S Tx DMA
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    This function disables I2S Tx DMA.
 *
 */
static __INLINE void I2S_DISABLE_TXDMA(void)
{
    I2S->CON &= ~I2S_CFG_TXDMA;
}

/**
 * @brief      Configure I2S Data Format
 *
 * @param[in]  Format      configuration value, should be ored by:
 *                          - I2S_CFG_WORDWIDTH_8/I2S_CFG_WORDWIDTH_16/I2S_CFG_WORDWIDTH_24/I2S_CFG_WORDWIDTH_32
 *
 * @return     None
 *
 * @details    Configure I2S data format to be 8, 16, 24, 32 bits.
 *
 */
static __INLINE void I2S_SET_DATAFORMAT(uint32_t format)
{
    I2S->CON = ((I2S->CON & ~I2S_CON_WORDWIDTH_Msk)) | (format);
}

/**
 * @brief      Configure I2S Channel
 *
 * @param[in]  Channel     configuration value, should be ored by:
 *                          - I2S_CFG_CHANNEL_MONO_LEFT/I2S_CFG_CHANNEL_MONO_RIGHT/I2S_CFG_CHANNEL_STEREO
 *
 * @return     None
 *
 * @details    Configure I2S channel to be mono-left, mono-right or stereo.
 *
 */
static __INLINE void I2S_SET_CHANNEL(uint32_t channel)
{
    I2S->CON = (I2S->CON & ~(I2S_CON_MONO_Msk | I2S_CON_RXLCH_Msk)) | (channel);
}

/**
 * @brief      Enable I2S MCK
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Enable I2S MCK clock output.
 *
 */
static __INLINE void I2S_ENABLE_MCK(void)
{
    I2S->CON |= I2S_CON_MCLKEN_Msk;
}

/**
 * @brief      Disable I2S MCK
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Disable I2S MCK clock output.
 *
 */
static __INLINE void I2S_DISABLE_MCK(void)
{
    I2S->CON &= ~I2S_CON_MCLKEN_Msk;
}

/**
 * @brief      Enable I2S Transact
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Enable I2S to send data
 *
 */
static __INLINE void I2S_ENABLE_TX(void)
{
    I2S->CON |= I2S_CON_TXEN_Msk;
}

/**
 * @brief      Disable I2S Transact
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Disable I2S from sending data
 *
 */
static __INLINE void I2S_DISABLE_TX(void)
{
    I2S->CON &= ~I2S_CON_TXEN_Msk;
}

/**
 * @brief      Enable I2S Receive
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Enable I2S to receive data
 *
 */
static __INLINE void I2S_ENABLE_RX(void)
{
    I2S->CON |= I2S_CON_RXEN_Msk;
}

/**
 * @brief      Disable I2S Recivie
 *
 * @param[in]  None
 *
 * @return     None
 *
 * @details    Disable I2S from receiving data
 *
 */
static __INLINE void I2S_DISABLE_RX(void)
{
    I2S->CON &= ~I2S_CON_RXEN_Msk;
}

/**
 * @brief      Set I2S MCK Frequency
 *
 * @param[in]  Frequency  MCK Frequency
 *
 * @return     None
 *
 * @details    Set I2S MCK Frequency.
 *
 */
static __INLINE void I2S_SET_MCK_DIV(uint32_t div)
{
    I2S->CLKDIV = (I2S->CLKDIV & ~I2S_CLKDIV_MCLK_DIV_Msk) | ((div)<<I2S_CLKDIV_MCLK_DIV_Pos);
}

/**
 * @brief      Set I2S Bit Clock Frequency
 *
 * @param[in]  Frequency  Bit Clock Frequency
 *
 * @return     None
 *
 * @details    Set I2S Bit Clock Frequency.
 *
 */
static __INLINE void I2S_SET_BITCLK_DIV(uint32_t div)
{
    I2S->CLKDIV = (I2S->CLKDIV & ~I2S_CLKDIV_BCLK_DIV_Msk) | ((div)<<I2S_CLKDIV_BCLK_DIV_Pos);
}

/**
 * @brief      Enable I2S Interrupt
 *
 * @param[in]  Interrupt  I2S Interrupt, should be ored by:
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
static __INLINE void I2S_ENABLE_INT(uint32_t intr)
{
    I2S->IE |= (intr);
}

/**
 * @brief      Disable I2S Interrupt
 *
 * @param[in]  Interrupt  I2S Interrupt, should be ored by:
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
static __INLINE void I2S_DISABLE_INT(uint32_t intr)
{
    I2S->IE &= ~(intr);
}

/**
 * @brief      Get I2S Interrupt
 *
 * @param[in]  None
 *
 * @return     Interrupt  I2S Interrupt, should be ored by:
 *                         - I2S_INT_LZC
 *                         - I2S_INT_RZC
 *                         - I2S_INT_TXTH
 *                         - I2S_INT_TXOVF
 *                         - I2S_INT_TXUDF
 *                         - I2S_INT_RXTH
 *                         - I2S_INT_RXOVF
 *                         - I2S_INT_RXUDF
 *
 * @details    Get I2S interrupt.
 *
 */
static __INLINE uint32_t I2S_GET_INT(void)
{
    return I2S->IE;
}

/**
 * @brief      Clear I2S Interrupt Flag
 *
 * @param[in]  None
 *
 * @return     Flag       I2S Interrupt flag, should be ored by:
 *                         - I2S_INTF_LZC
 *                         - I2S_INTF_RZC
 *                         - I2S_INTF_TXOVF
 *                         - I2S_INTF_TXUDF
 *                         - I2S_INTF_RXOVF
 *                         - I2S_INTF_RXUDF
 *                         - I2S_INTF_TXINT
 *                         - I2S_INTF_RXINT
 *
 * @details    Clear I2S Interrupt Flag.
 *
 */
static __INLINE uint32_t I2S_GET_INTF(void)
{
    return I2S->STATUS;
}

/**
 * @brief      Clear I2S Interrupt Flag
 *
 * @param[in]  Flag       I2S Interrupt flag, should be ored by:
 *                         - I2S_INTF_LZC
 *                         - I2S_INTF_RZC
 *                         - I2S_INTF_TXOVF
 *                         - I2S_INTF_TXUDF
 *                         - I2S_INTF_RXOVF
 *                         - I2S_INTF_RXUDF
 *
 * @return     None
 *
 * @details    Clear I2S Interrupt Flag.
 *
 */
static __INLINE void I2S_CLR_INTF(uint32_t intr)
{
    I2S->STATUS = (intr);
}

/**
 * @brief      Get I2S State
 *
 * @param[in]  None
 *
 * @return     State      I2S State, ored by:
 *                         - I2S_STAT_TX_BUSY
 *                         - I2S_STAT_TX_EMPTY
 *                         - I2S_STAT_TX_FULL
 *                         - I2S_STAT_TX_THRESHOLD
 *                         - I2S_STAT_RX_EMPTY
 *                         - I2S_STAT_RX_FULL
 *                         - I2S_STAT_RX_THRESHOLD
 *
 * @details    Get I2S State.
 *
 */
static __INLINE uint32_t I2S_GET_STATUS(void)
{
    return I2S->STATUS;
}

/**
 * @brief      Get I2S Channel for current data
 *
 * @param[in]  None
 *
 * @retval     I2S_STAT_CHANNEL_RIGHT        Current data is right channel
 * @retval     I2S_STAT_CHANNEL_LEFT         Current data is left channel
 *
 * @details    Get I2S Channel for current data.
 *
 */
static __INLINE uint32_t I2S_GET_CUR_CHANNEL(void)
{
    return (I2S->STATUS & I2S_STAT_CHANNEL_MASK);
}

/**
 * @brief      Write Data to I2S
 *
 * @param[in]  Data       data to be wiritten to I2S
 *
 * @return     None
 *
 * @details    Write Data to I2S.
 *
 */
static __INLINE void I2S_SET_DATA(uint32_t data)
{
    I2S->TXFIFO = (data);
}

/**
 * @brief      Read Data from I2S
 *
 * @param[in]  None
 *
 * @return     Data       data read from I2S
 *
 * @details    Read Data from I2S.
 *
 */
static __INLINE uint32_t I2S_GET_DATA(void)
{
    return I2S->RXFIFO;
}

/**
  * @brief  Get I2S BCLK frequency.
  * @param  None.
  * @retval I2S BCLK frequency.
  */
static __INLINE uint32_t I2S_GetBCLKFreq(uint32_t u32SrcClk)
{
	uint32_t u32Reg;
	
	u32Reg = (I2S->CLKDIV & I2S_CLKDIV_BCLK_DIV_Msk) >> 8;
	
	return ((u32SrcClk >> 1) / (u32Reg + 1));
}

/**
  * @brief  Set bit clock divider if I2S operates in master mode. BCLK = I2S_CLK / (2x(divider+1)).
  * @param  u32Bclk: I2S bit clock ftequency (Hz).
  * @retval None.
  */
static __INLINE void I2S_SetBCLKFreq(uint32_t u32SrcClk, uint32_t u32Bclk)
{
	uint8_t u8Divider;

	u8Divider = ((u32SrcClk/u32Bclk) >> 1) - 1;

	I2S->CLKDIV |= ((u8Divider << 8) & I2S_CLKDIV_BCLK_DIV_Msk);
}


/**
  * @brief  Get I2S MCLK frequency.
  * @param  None.
  * @retval I2S MCLK frequency.
  */
static __INLINE uint32_t I2S_GetMCLKFreq(uint32_t u32SrcClk)
{
	uint32_t u32Reg;

	u32Reg = I2S->CLKDIV & I2S_CLKDIV_MCLK_DIV_Msk;
	
	if (u32Reg == 0)
		return u32SrcClk;
	else
		return ((u32SrcClk >> 1) / u32Reg);
}

/**
  * @brief  Set master clock divider. MCLK = I2S_CLK / (2xdivider).
  * @param  u32Mclk: I2S master clock output ftequency (Hz).
  * @retval None.
  */
static __INLINE void I2S_SetMCLKFreq(uint32_t u32SrcClk, uint32_t u32Mclk)
{
	uint8_t u8Divider;

	if (u32Mclk == u32SrcClk)
		u8Divider = 0;
	else
		u8Divider = (u32SrcClk/u32Mclk) >> 1;
	
	I2S->CLKDIV |= (u8Divider & I2S_CLKDIV_MCLK_DIV_Msk);
}

/*@}*/ /* end of group I2S_MACRO_FUNC */
/*@}*/ /* end of group I2S_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */
  
/*---------------------------------------------------------------------------------------------------------*/
/* Define I2S API prototype                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
int32_t DrvI2S_Init(STR_I2S_T *sParam);
void DrvI2S_DeInit(void);
void DrvI2S_EnableInt(uint32_t u32IntMask);
void DrvI2S_DisableInt(uint32_t u32IntMask);
uint32_t DrvI2S_GetSourceClockFreq(void);

#endif

