/**************************************************************************//**
 * @file     SPI.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/24 1:45p $
 * @brief    NUC123 Series SPI Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __SPI_H__
#define __SPI_H__

/*---------------------------------------------------------------------------------------------------------*/
/* Include related headers                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup SPI_MACRO SPI Macro
  * @{
  */
/** @addtogroup SPI_MACRO_CONTANT SPI Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* SPI_CNTRL constant definitions                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_CTRL_TX_FULL            (1UL << SPI_CNTRL_TX_FULL_Pos)  /*!< Transmit FIFO Buffer Full Indicator  */
#define SPI_CTRL_TX_EMPTY           (1UL << SPI_CNTRL_TX_EMPTY_Pos) /*!< Transmit FIFO Buffer Empty Indicator  */
#define SPI_CTRL_RX_FULL            (1UL << SPI_CNTRL_RX_FULL_Pos)  /*!< Receive FIFO Buffer Full Indicator  */
#define SPI_CTRL_RX_EMPTY           (1UL << SPI_CNTRL_RX_EMPTY_Pos) /*!< Receive FIFO Buffer Empty Indicator */
#define SPI_VARCLK_EN               (1UL << SPI_CNTRL_VARCLK_EN_Pos)/*!< Variable Clock Enable */
#define SPI_TWO_BIT                 (1UL << SPI_CNTRL_TWOB_Pos)     /*!< Two-Bit Transfer Mode  Enable */ 
#define SPI_FIFO_EN                 (1UL << SPI_CNTRL_FIFO_Pos)     /*!<  FIFO mode Enable */
#define SPI_REORDER                 (1UL << SPI_CNTRL_REORDER_Pos)  /*!< Byte reorder function Enabled */
#define SPI_MASTER                  (0UL << SPI_CNTRL_SLAVE_Pos)    /*!< Master mode  */
#define SPI_SLAVE                   (1UL << SPI_CNTRL_SLAVE_Pos)    /*!< Slave mode  */
#define SPI_IE                      (1UL << SPI_CNTRL_IE_Pos)       /*!< Transfer Interrupt Enable */
#define SPI_IF                      (1UL << SPI_CNTRL_IF_Pos)       /*!< Transfer Done Interrupt Flag */
#define SPI_SUSPEND_CYCLE(x)        ((x) << SPI_CNTRL_SP_CYCLE_Pos) /*!< Suspend Interval (Master Only) */

#define SPI_CLKP_HIGH               (1UL << SPI_CNTRL_CLKP_Pos)     /*!< SPICLK idle high */
#define SPI_CLKP_LOW                (0UL << SPI_CNTRL_CLKP_Pos)     /*!< SPICLK idle low */

#define SPI_CNTRL_LSB               (1UL << SPI_CNTRL_LSB_Pos)      /*!< LSB First */
#define SPI_TX_BIT_LEN(x)           ((((x)!=32)?(x):0) << SPI_CNTRL_TX_BIT_LEN_Pos)/*!< This field specifies how many bits can be transmitted / received in one transactio */
#define SPI_TX_NEG                  (1UL << SPI_CNTRL_TX_NEG_Pos)   /*!< Transmit on Negative Edge */
#define SPI_RX_NEG                  (1UL << SPI_CNTRL_RX_NEG_Pos)   /*!< Receive on Negative Edge */
#define SPI_GO_BUSY                 (1UL << SPI_CNTRL_GO_BUSY_Pos)  /*!< SPI Transfer Control Bit and Busy Status */
												
/*---------------------------------------------------------------------------------------------------------*/
/* SPI_DIVIDER constant definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_DIVIDER_DIV(x)  (x)         /*!< SPI_DIVIDER setting for SPI master clock divider. It could be 0~255 */
#define SPI_DIVIDER_DIV2(x) ((x) << 16) /*!< SPI_DIVIDER setting for SPI master clock divider2 of varialbe clock function. It could be 0~255 */
/*---------------------------------------------------------------------------------------------------------*/
/* SPI_SSR constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_SS_LEVEL_TRIGGER (1UL << SPI_SSR_SS_LTRIG_Pos) /*!< SPI_SSR setting for level trigger in SPI slave mode */
#define SPI_SS_EDGE_TRIGGER  (0UL << SPI_SSR_SS_LTRIG_Pos) /*!< SPI_SSR setting for edge trigger in SPI slave mode */
#define SPI_AUTO_SS          (1UL << SPI_SSR_AUTOSS_Pos)   /*!< SPI_SSR setting for auto chip select in SPI master mode */
#define SPI_SW_SS            (0UL << SPI_SSR_AUTOSS_Pos)   /*!< SPI_SSR setting for manual chip select in SPI master mode */
#define SPI_SS_HIGH_TRIGGER  (1UL << SPI_SSR_SS_LVL_Pos)   /*!< SPI_SSR setting for high level or rising edge trigger in SPI slave/master mode */
#define SPI_SS_LOW_TRIGGER   (0UL << SPI_SSR_SS_LVL_Pos)   /*!< SPI_SSR setting for low level or falling edge trigger in SPI slave/master mode */
#define SPI_SSR1             (1UL << 1)                    /*!< SPI_SSR setting for CS1 in SPI master mode */
#define SPI_SSR0             (1UL << 0)                    /*!< SPI_SSR setting for CS0 in SPI master mode */
/*---------------------------------------------------------------------------------------------------------*/
/* SPI_DMA constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_DMA_PDMA_RST                 (1UL << SPI_DMA_PDMA_RST_Pos)	 /*!< PDMA Reset */		  
#define SPI_DMA_RX_DMA_GO                (1UL << SPI_DMA_RX_DMA_GO_Pos)	 /*!< Receive DMA Start */	
#define SPI_DMA_TX_DMA_GO                (1UL << SPI_DMA_TX_DMA_GO_Pos)	 /*!< Transmit DMA Start */	
/*---------------------------------------------------------------------------------------------------------*/
/* SPI_CNTRL2 constant definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_BCn                   (1UL << SPI_CNTRL2_BCn_Pos)		     /*!< SPI Engine Clock Backward Compatible Option */	
#define SPI_SS_INT_OPT            (1UL << SPI_CNTRL2_SS_INT_OPT_Pos)	     /*!< Slave Select Inactive Interrupt Option */								   
#define SPI_DUAL_IO_EN            (1UL << SPI_CNTRL2_DUAL_IO_EN_Pos)	     /*!< Dual IO Mode function Enable */
#define SPI_DUAL_IO_DIR           (1UL << SPI_CNTRL2_DUAL_IO_DIR_Pos)	 /*!< Dual  IO Mode Direction */
#define SPI_SLV_START_INTSTS      (1UL << SPI_CNTRL2_SLV_START_INTSTS_Pos)/*!< Slave 3-Wire Mode Start Interrupt Status */
#define SPI_SSTA_INTEN            (1UL << SPI_CNTRL2_SSTA_INTEN_Pos)	     /*!< Slave 3-Wire Mode Start Interrupt Enable */
#define SPI_SLV_ABORT             (1UL << SPI_CNTRL2_SLV_ABORT_Pos)	     /*!< Slave 3-Wire Mode Abort Control Bit */
#define SPI_NOSLVSEL              (1UL << SPI_CNTRL2_NOSLVSEL_Pos)	     /*!< No Slave Selected (3-Wire)in Slave mode*/

/*---------------------------------------------------------------------------------------------------------*/
/* SPI_FIFO_CTL constant definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_FIFO_TX_THRESHOLD(x)         ((x) << SPI_FIFO_CTL_TX_THRESHOLD_Pos)	/*!<Transmit FIFO Threshold */	
#define SPI_FIFO_RX_THRESHOLD(x)         ((x) << SPI_FIFO_CTL_RX_THRESHOLD_Pos)	/*!< Received FIFO Threshold */	
#define SPI_TIMEOUT_INTEN                (1UL << SPI_FIFO_CTL_TIMEOUT_INTEN_Pos)/*!< Receive FIFO Time-out Interrupt Enable */	
#define SPI_RXOVER_INTEN                 (1UL << SPI_FIFO_CTL_RXOV_INTEN_Pos)	/*!< Receive FIFO Over Run Interrupt Enable */	
#define SPI_TX_INTEN                     (1UL << SPI_FIFO_CTL_TX_INTEN_Pos)		/*!< TX Threshold Interrupt Enable*/	
#define SPI_RX_INTEN                     (1UL << SPI_FIFO_CTL_RX_INTEN_Pos)	    /*!< RX Threshold Interrupt Enable */	
#define SPI_TX_CLR                       (1UL << SPI_FIFO_CTL_TX_CLR_Pos)	    /*!< Clear Transmit FIFO Buffer */	
#define SPI_RX_CLR                       (1UL << SPI_FIFO_CTL_RX_CLR_Pos)		/*!< Clear Receive FIFO Buffer */	

/*---------------------------------------------------------------------------------------------------------*/
/* SPI_STATUS constant definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define SPI_STATUS_TX_FULL               (1UL << SPI_STATUS_TX_FULL_Pos)	   /*!< Indicates the valid data count of transmit FIFO buffer */
#define SPI_STATUS_TX_EMPTY              (1UL << SPI_STATUS_TX_EMPTY_Pos)	   /*!< Transmit FIFO Buffer Full Indicator  */
#define SPI_STATUS_RX_FULL               (1UL << SPI_STATUS_RX_FULL_Pos)	   /*!< Transmit FIFO Buffer Empty Indicator  */
#define SPI_STATUS_RX_EMPTY              (1UL << SPI_STATUS_RX_EMPTY_Pos)	   /*!< Receive FIFO Buffer Empty Indicator*/
#define SPI_STATUS_TIMEOUT               (1UL << SPI_STATUS_TIMEOUT_Pos)	   /*!< Time-out Interrupt Flag */
#define SPI_STATUS_IF                    (1UL << SPI_STATUS_IF_Pos)			   /*!< SPI Unit Transfer Interrupt Fla*/
#define SPI_STATUS_SLV_START_INTSTS      (1UL << SPI_STATUS_SLV_START_INTSTS_Pos)/*!<Slave Start Interrupt Status */
#define SPI_STATUS_TXINT_STS             (1UL << SPI_STATUS_TX_INTSTS_Pos)	   /*!< Transmit FIFO Threshold Interrupt Status  */
#define SPI_STATUS_RX_OVER_RUN           (1UL << SPI_STATUS_RX_OVERRUN_Pos)	   /*!< Receive FIFO Overrun Status*/
#define SPI_STATUS_RXINT_STS             (1UL << SPI_STATUS_RX_INTSTS_Pos)	   /*!< Receive FIFO Threshold Interrupt Status  */

#define SPI_SUSPEND_0_5                  0
#define SPI_SUSPEND_1_5                  1
#define SPI_SUSPEND_2_5                  2
#define SPI_SUSPEND_3_5                  3
#define SPI_SUSPEND_4_5                  4
#define SPI_SUSPEND_5_5                  5
#define SPI_SUSPEND_6_5                  6
#define SPI_SUSPEND_7_5                  7
#define SPI_SUSPEND_8_5                  8
#define SPI_SUSPEND_9_5                  9
#define SPI_SUSPEND_10_5                 10
#define SPI_SUSPEND_11_5                 11
#define SPI_SUSPEND_12_5                 12
#define SPI_SUSPEND_13_5                 13
#define SPI_SUSPEND_14_5                 14
#define SPI_SUSPEND_15_5                 15

/*@}*/ /* end of group SPI_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup SPI_MACRO_FUNC SPI Macro Func
  @{
*/

/**
 * @brief      Transmit FIFO Buffer Full Indicator
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = Indicates that the transmit FIFO buffer is not full. 
 * @retval     !0 = Indicates that the transmit FIFO buffer is full. 
 *
 * @details    Read Transmit FIFO Buffer Full Indicator
 *             Example: SPI_GET_TX_FULL(SPI0)
 */
static __INLINE uint32_t SPI_GET_TX_FULL(SPI_T *port)
{
    return ((port)->CNTRL & SPI_CTRL_TX_FULL);
}
/**
 * @brief      Transmit FIFO Buffer empty Indicator
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = Indicates that the transmit FIFO buffer is not empty. 
 * @retval     !0 = Indicates that the transmit FIFO buffer is empty. 
 *
 * @details    Read Transmit FIFO Buffer empty Indicator
 *             Example: SPI_GET_TX_EMPTY(SPI0)
 */
static __INLINE uint32_t SPI_GET_TX_EMPTY(SPI_T *port) 
{
    return ((port)->CNTRL & SPI_CTRL_TX_EMPTY);
}
/**
 * @brief      Receive FIFO Buffer Full Indicator
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = Indicates that the Receive FIFO buffer is not full. 
 * @retval     !0 = Indicates that the Receive FIFO buffer is full. 
 *
 * @details    Read Receive FIFO Buffer Full Indicator
 *             Example: SPI_GET_RX_FULL(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX_FULL(SPI_T *port)
{
    return ((port)->CNTRL & SPI_CTRL_RX_FULL);
}
/**
 * @brief      Receive FIFO Buffer empty Indicator
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = Indicates that the receive FIFO buffer is not empty. 
 * @retval     !0 = Indicates that the receive FIFO buffer is empty. 
 *
 * @details    Read Receive FIFO Buffer empty Indicator
 *             Example: SPI_GET_RX_EMPTY(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX_EMPTY(SPI_T *port)
{
    return ((port)->CNTRL & SPI_CTRL_RX_EMPTY);
}
/**
 * @brief      Variable Clock Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Variable Clock Enable
 *             Example: SPI_ENABLE_VARAIBLE_CLOCK(SPI0)
 */
static __INLINE void SPI_ENABLE_VARAIBLE_CLOCK(SPI_T *port)
{
    ((port)->CNTRL |= SPI_VARCLK_EN);
}
/**
 * @brief      Variable Clock Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Variable Clock Disable
 *             Example: SPI_DISABLE_VARAIBLE_CLOCK(SPI0)
 */
static __INLINE void SPI_DISABLE_VARAIBLE_CLOCK(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_VARCLK_EN);
}
/**
 * @brief      Two-Bit Transfer Mode  Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    When TWOB is enabled, the serial transmitted 2-bit data are from SPI_TX1/0, 
 *             and the received 2-bit data input are put in SPI_RX1/0
 *             Example: SPI_ENABLE_TWO_BIT(SPI0)
 */
static __INLINE void SPI_ENABLE_TWO_BIT(SPI_T *port)
{
    ((port)->CNTRL |= SPI_TWO_BIT);
}
/**
 * @brief      Two-Bit Transfer Mode  Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Two-Bit Transfer Mode Disable 
 *             Example: SPI_DISABLE_TWO_BIT(SPI0)
 */
static __INLINE void SPI_DISABLE_TWO_BIT(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_TWO_BIT);
}
/**
 * @brief      FIFO  Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    FIFO  Enable 
 * @Notes:     Before enabling FIFO mode, the other related settings should be set in advance
 *             Example: SPI_ENABLE_FIFO(SPI0)
 */
static __INLINE void SPI_ENABLE_FIFO(SPI_T *port)
{
    ((port)->CNTRL |= SPI_FIFO_EN);
}
/**
 * @brief      FIFO  Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    FIFO  Disable 
 *             Example: SPI_DISABLE_FIFO(SPI0)
 */
static __INLINE void SPI_DISABLE_FIFO(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_FIFO_EN);
}
/**
 * @brief      Byte Reorder Mode Function Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Byte Reorder Mode Function Enable 
 *             Example: SPI_ENABLE_REORDER(SPI0)
 */
static __INLINE void SPI_ENABLE_REORDER(SPI_T *port)
{
    ((port)->CNTRL |= SPI_REORDER);
}
/**
 * @brief      Byte Reorder Mode Function Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Byte Reorder Mode Function Disable. 
 *             Example: SPI_DISABLE_REORDER(SPI0)
 */
static __INLINE void SPI_DISABLE_REORDER(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_REORDER);
}

 /**
 * @brief      Set master mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  mode    SPI mode 
 *                     -SPI_MASTER
 *                     -SPI_SLAVE
 * @return     None 
 *
 * @details    Set master mode.
 *             Example: SPI_SET_MODE(SPI0, SPI_MASTER)
 */
static __INLINE void SPI_SET_MODE(SPI_T *port,uint32_t mode)
{
    ((port)->CNTRL = ((port)->CNTRL&~SPI_SLAVE) | mode);
}
 /**
 * @brief      Enable SPI transfer interrupt
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    SPI transfer done Interrupt Enabled
 *             Example: SPI_ENABLE_INTERRUPT(SPI0)
 */
static __INLINE void SPI_ENABLE_INTERRUPT(SPI_T *port)
{
    ((port)->CNTRL |= SPI_IE);
}
 /**
 * @brief      Disable SPI transfer interrupt
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    SPI transfer done Interrupt disabled
 *             Example: SPI_DISABLE_INTERRUPT(SPI0)
 */
static __INLINE void SPI_DISABLE_INTERRUPT(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_IE);
}
/**
 * @brief      Transfer Done Interrupt Flag
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = It indicates that the transfer does not finish yet. 
 * @retval     !0 = It indicates that the SPI controller has finished one unit transfer. 
 *
 * @details    Transfer Done Interrupt Flag
 *             Example: SPI_GET_IF(SPI0)
 */
static __INLINE uint32_t SPI_GET_IF(SPI_T *port)
{
    return ((port)->CNTRL & SPI_IF);
}
/**
 * @brief     Clear Transfer Done Interrupt Flag
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None  
 *
 * @details    Clear Transfer Done Interrupt Flag
 *             Example: SPI_CLEAR_IF(SPI0)
 */
static __INLINE void SPI_CLEAR_IF(SPI_T *port)
{
    ((port)->CNTRL |= SPI_IF);
}

/**
 * @brief      Suspend Interval
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x
 *             SPI_SUSPEND_0_5.... 
 * @return     None  
 *
 * @details    These four bits provide configurable suspend interval
 *             between two successive transmit/receive transaction in a transfer
 *             Example: SPI_SET_SUSPEND_CYCLE(SPI0,SPI_SUSPEND_6_5)
 */
static __INLINE void SPI_SET_SUSPEND_CYCLE(SPI_T *port,uint32_t x)
{
    ((port)->CNTRL = ((port)->CNTRL&(~SPI_CNTRL_SP_CYCLE_Msk)) | SPI_SUSPEND_CYCLE(x));
}

/**
 * @brief      Set SPI clock idle high
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  level     
 *                     -SPI_CLKP_HIGH
 *                     -SPI_CLKP_LOW
 * @return     None 
 *
 * @details    Set SPI clock idle high.
 *             Example: SPI_SET_SPICLK_IDLE(SPI0, SPI_CLKP_LOW)
 */
static __INLINE void SPI_SET_SPICLK_IDLE(SPI_T *port, uint32_t level)
{
    ((port)->CNTRL = ((port)->CNTRL&~SPI_CNTRL_CLKP_Msk) | level);
}

/**
 * @brief      LSB First
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    The LSB, bit 0 of the SPI TX0/1 register is sent first to the SPI data output pin ,
 *             and the first bit received from the SPI data input pin will be put in the LSB position of the RX register. 
 *             Example: SPI_SET_LSB_FIRST(SPI0)
 */
static __INLINE void SPI_SET_LSB_FIRST(SPI_T *port)
{
    ((port)->CNTRL |= SPI_CNTRL_LSB);
}
/**
 * @brief      MSB First
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    The MSB, which bit of transmit/receive register depends on the setting of TX_BIT_LEN, 
 *             is transmitted/received first.
 *             Example: SPI_SET_MSB_FIRST(SPI0)
 */
static __INLINE void SPI_SET_MSB_FIRST(SPI_T *port) 
{
    ((port)->CNTRL &= ~SPI_CNTRL_LSB);
}
/**
 * @brief      Transmit Bit Length
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x 	8~32
 * @return     None 
 *
 * @details    This field specifies how many bits can be transmitted / received in one transaction 
 *             Example: SPI_SET_TX_BIT_LEN(SPI0,8)
 */
static __INLINE void SPI_SET_TX_BIT_LEN(SPI_T *port,uint32_t x) 
{
    ((port)->CNTRL = ((port)->CNTRL&(~SPI_CNTRL_TX_BIT_LEN_Msk))| SPI_TX_BIT_LEN(x));
}
/**
 * @brief      Transmit on Negative Edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Transmitted data output signal is changed on the falling edge of SPICLK.
 *             Example: SPI_SET_TX_FALLING(SPI0)
 */
static __INLINE void SPI_SET_TX_FALLING(SPI_T *port)
{
    ((port)->CNTRL |= SPI_TX_NEG );
}
/**
 * @brief      Transmit on Positive Edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Transmitted data output signal is changed on the rising edge of SPICLK.
 *             Example: SPI_SET_TX_RISING(SPI0)
 */
static __INLINE void SPI_SET_TX_RISING(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_TX_NEG);
}
/**
 * @brief      Receive on Negative Edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Received data input signal is latched on the falling edge of SPICLK.
 *             Example: SPI_SET_RX_FALLING(SPI0)
 */
static __INLINE void SPI_SET_RX_FALLING(SPI_T *port)
{
    ((port)->CNTRL |= SPI_RX_NEG);
}
/**
 * @brief      Receive on Positive Edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Received data input signal is latched on the rising edge of SPICLK.
 *             Example: SPI_SET_RX_RISING(SPI0)
 */
static __INLINE void SPI_SET_RX_RISING(SPI_T *port)
{
    ((port)->CNTRL &= ~SPI_RX_NEG);
}
/**
 * @brief      Set the SPI GO_BUSY bit of the user-specified SPI port
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Set the SPI GO_BUSY bit of the user-specified SPI port.
 *             Example: SPI_SET_GO(SPI0)
 */
static __INLINE void SPI_SET_GO(SPI_T *port)
{
    ((port)->CNTRL |= SPI_GO_BUSY);
}
/**
 * @brief      Clear the SPI GO_BUSY bit of the user-specified SPI port
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Clear the SPI GO_BUSY bit of the user-specified SPI port.
 *             Example: SPI_CLR_GO(SPI0)
 */
static __INLINE void SPI_CLR_GO(SPI_T *port)
{
    ((port)->CNTRL &= (~SPI_GO_BUSY));
}
/**
 * @brief      Get the SPI busy status of the user-specified SPI port
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = Data transfer stopped. 
 * @retval     !0 = SPI is transferring. 
 *
 * @details    Get the SPI busy status of the user-specified SPI port
 *             Example: SPI_GET_BUSY_STATUS(SPI0)
 */
static __INLINE uint32_t SPI_IS_BUSY(SPI_T *port)
{
    return ((port)->CNTRL & SPI_GO_BUSY);
}
/**
 * @brief      Set SPI Clock Divider 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  u8div
 * @return     None 
 *
 * @details    Set SPI Clock Divider 
 *             Example: SPI_SET_DIVIDER(SPI0,0x04)
 */
static __INLINE void SPI_SET_DIVIDER(SPI_T *port,uint8_t u8div)
{
    ((port)->DIVIDER =((port)->DIVIDER & (~SPI_DIVIDER_DIVIDER_Msk))| u8div);
}
/**
 * @brief      Set SPI Clock Divider 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  u8div
 * @return     None 
 *
 * @details    Set SPI Clock Divider 
 *             Example: SPI_SET_DIVIDER2(SPI0,0x04)
 */
static __INLINE void SPI_SET_DIVIDER2(SPI_T *port,uint8_t u8div)
{
    ((port)->DIVIDER =((port)->DIVIDER & (~SPI_DIVIDER_DIVIDER2_Msk)) | (u8div<<SPI_DIVIDER_DIVIDER2_Pos));
}
/**
 * @brief      Set slave select mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  ssrmode
 *              -SPI_SS_HIGH_TRIGGER
 *              -SPI_SS_LOW_TRIGGER
 * @param[in]  ssrmode
			   -SPI_AUTO_SS
   			   -SPI_SW_SS
 * @return     None 
 *
 * @details    Set slave select mode
 *             Example: SPI_SET_SS(SPI0, SPI_SS_HIGH_TRIGGER, SPI_AUTO_SS);
 */
static __INLINE void SPI_SET_SS(SPI_T *port,uint32_t level,uint32_t  _Auto)
{
    ((port)->SSR |= level|_Auto );
}
/**
 * @brief      Level Trigger Accomplish Flag
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = The transferred bit length of one transaction does not meet the specified requirement. 
 * @retval     !0 = The transferred bit length meets the specified requirement which defined in TX_BIT_LEN. 
 *
 * @details    Get the level trigger Accomplish flag of the user-specified SPI port
 *             Example: SPI_GET_LTRIG_FLAG(SPI0)
 */
static __INLINE uint32_t  SPI_GET_LTRIG_FLAG(SPI_T *port)
{
    return ((port)->SSR & SPI_SSR_LTRIG_FLAG_Msk);
}

/**
 * @brief      Set SPI slave select level active 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Input slave select signal is level-trigger
 *             Example: SPI_SLAVE_SS_LEVEL_ACTIVE(SPI0)
 */
static __INLINE void SPI_SLAVE_SS_LEVEL_ACTIVE(SPI_T *port)
{
    ((port)->SSR = (port)->SSR | SPI_SSR_SS_LTRIG_Msk);
}
/**
 * @brief      Set SPI slave select edge active 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Slave select signal will be edge-trigger
 *             Example: SPI_SLAVE_SS_EDGE_ACTIVE(SPI0)
 */
static __INLINE void SPI_SLAVE_SS_EDGE_ACTIVE(SPI_T *port)
{
    ((port)->SSR = (port)->SSR & ~SPI_SSR_SS_LTRIG_Msk);
}
/**
 * @brief      The slave select signal SPISSx0/1 is active on low-level/falling-edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    The slave select signal SPISSx0/1 is active on low-level/falling-edge
 *             Example: SPI_SS_LOW_ACTIVE(SPI0)
 */
static __INLINE void SPI_SS_LOW_ACTIVE(SPI_T *port)
{
    ((port)->SSR &= ~SPI_SSR_SS_LVL_Msk);
}
/**
 * @brief      The slave select signal SPISSx0/1 is active on high-level/rising-edge
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    The slave select signal SPISSx0/1 is active on high-level/rising-edge
 *             Example: SPI_SS_HIGH_ACTIVE(SPI0)
 */
static __INLINE void SPI_SS_HIGH_ACTIVE(SPI_T *port)
{
    ((port)->SSR |= SPI_SSR_SS_LVL_Msk);
}
/**
 * @brief      Enable the automatic slave select function of the user-specified SPI port
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Enable the automatic slave select function of the user-specified SPI port
 *             Example: SPI_ENABLE_AUTO_SS(SPI0)
 */
static __INLINE void SPI_ENABLE_AUTO_SS(SPI_T *port)
{
    ((port)->SSR |= SPI_SSR_AUTOSS_Msk);
}
/**
 * @brief      Disable the automatic slave select function of the user-specified SPI port
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Disable the automatic slave select function of the user-specified SPI port
 *             Example: SPI_DISABLE_HW_AUTO_SLAVE_SELECT(SPI0)
 */
static __INLINE void SPI_DISABLE_AUTO_SS(SPI_T *port)
{
    ((port)->SSR &= (~SPI_SSR_AUTOSS_Msk));
}
/**
 * @brief      Set the slave select 1 control bit to 1
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Set the slave select control bit to 1
 *             Example: SPI_SET_SS(SPI0)
 */
static __INLINE void SPI_SET_SS1(SPI_T *port)
{
    ((port)->SSR |= SPI_SSR1);
}
/**
 * @brief      Set the slave select 0 control bit to 1
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Set the slave select control bit to 1
 *             Example: SPI_SET_SS(SPI0)
 */
static __INLINE void SPI_SET_SS0(SPI_T *port)
{
    ((port)->SSR |= SPI_SSR0);
}
/**
 * @brief      Clear the slave select control 1 bit to 0
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Clear the slave select control bit to 0
 *             Example: SPI_CLR_SS1(SPI0)
 */
static __INLINE void SPI_CLR_SS1(SPI_T *port)
{
    ((port)->SSR &= (~SPI_SSR1));
}
/**
 * @brief      Clear the slave select control 0 bit to 0
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Clear the slave select control bit to 0
 *             Example: SPI_CLR_SS(SPI0)
 */
static __INLINE void SPI_CLR_SS0(SPI_T *port)
{
    ((port)->SSR &= (~SPI_SSR0));
}
/**
 * @brief      Get the SPI Rx0 data
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     RX[0] 
 *
 * @details    Get the SPI Rx0 data
 *             Example: SPI_GET_RX0_DATA(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX0_DATA(SPI_T *port)
{
    return ((port)->RX[0]);
}
/**
 * @brief      Get the SPI Rx1 data
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     RX[1] 
 *
 * @details    Get the SPI Rx1 data
 *             Example: SPI_GET_RX1_DATA(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX1_DATA(SPI_T *port)
{
    return ((port)->RX[1]);
}
/**
 * @brief      Write data to the SPI Tx buffer0
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x	  data to the SPI Tx buffer0
 * @return     None 
 *
 * @details    Write data to the SPI Tx buffer0
 *             Example: SPI_WRITE_TX_BUFFER0(SPI0,0x55)
 */
static __INLINE void SPI_WRITE_TX0(SPI_T *port, uint32_t x)
{
    ((port)->TX[0] = (x));
}
/**
 * @brief      Write data to the SPI Tx buffer1
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x	  data to the SPI Tx buffer1
 * @return     None 
 *
 * @details    Write data to the SPI Tx buffer1
 *             Example: SPI_WRITE_TX_BUFFER1(SPI0,0x55)
 */
static __INLINE void SPI_WRITE_TX1(SPI_T *port,uint32_t x)
{
    ((port)->TX[1] = (x));
}
/**
 * @brief      PDMA Reset
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Reset the PDMA control logic in this SPI controller. This bit will be cleared to 0 automatically
 *             Example: SPI_PDMA_RST(SPI0)
 */
static __INLINE void SPI_PDMA_RST(SPI_T *port)
{
    ((port)->DMA |= SPI_DMA_PDMA_RST);
}
/**
 * @brief      Receive DMA Start
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Hardware will clear this bit to 0 automatically after PDMA transfer is done
 *             Example: SPI_RX_DMA_GO(SPI0)
 */
static __INLINE void SPI_RX_DMA_GO(SPI_T *port)
{
    ((port)->DMA |= SPI_DMA_RX_DMA_GO);
}
/**
 * @brief      Transmit DMA Start
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Hardware will clear this bit to 0 automatically after PDMA transfer is done
 *             Example: SPI_TX_DMA_GO(SPI0)
 */
static __INLINE void SPI_TX_DMA_GO(SPI_T *port)
{
    ((port)->DMA |= SPI_DMA_TX_DMA_GO);
}
/**
 * @brief      SPI Engine Clock Backward Compatible Option
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    The clock configuration is not backward compatible
 *             Example: SPI_DISABLE_BCN(SPI0)
 */
static __INLINE void SPI_DISABLE_BCN(SPI_T *port)
{
    ((port)->CNTRL2  |= SPI_BCn);
}
/**
 * @brief      SPI Engine Clock Backward Compatible Option
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Backward compatible clock configuration
 *             Example: SPI_ENABLE_BCN(SPI0)
 */
static __INLINE void SPI_ENABLE_BCN(SPI_T *port)
{
    ((port)->CNTRL2 &= ~SPI_BCn);
}
/**
 * @brief      Slave Select Inactive Interrupt Option
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    As the slave select signal goes to inactive level, the IF bit will be set to 1
 *             Example: SPI_ENABLE_SS_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_SS_INT(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_SS_INT_OPT);
}
/**
 * @brief      Slave Select Inactive Interrupt Option
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    As the slave select signal goes to inactive level, the IF bit will NOT be set to 1
 *             Example: SPI_DISABLE_SS_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_SS_INT(SPI_T *port)
{
    ((port)->CNTRL2 &= ~SPI_SS_INT_OPT);
}
/**
 * @brief      Dual  IO Mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Dual IO Mode function Enabled
 *             Example: SPI_ENABLE_DUAL_IO(SPI0)
 */
static __INLINE void SPI_ENABLE_DUAL_IO(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_DUAL_IO_EN);
}
/**
 * @brief      Dual  IO Mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Dual IO Mode function Disabled
 *             Example: SPI_DISABLE_DUAL_IO(SPI0)
 */
static __INLINE void SPI_DISABLE_DUAL_IO(SPI_T *port)
{
    ((port)->CNTRL2 &= ~SPI_DUAL_IO_EN);
}
/**
 * @brief      Dual  IO Direction
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Dual output mode
 *             Example: SPI_SET_DUAL_IO_OUTPUT(SPI0)
 */
static __INLINE void SPI_SET_DUAL_IO_OUTPUT(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_DUAL_IO_DIR);
}
/**
 * @brief      Dual  IO Direction
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Dual input mode
 *             Example: SPI_SET_DUAL_IO_INPUT(SPI0)
 */
static __INLINE void SPI_SET_DUAL_IO_INPUT(SPI_T *port)
{
    ((port)->CNTRL2 &= ~SPI_DUAL_IO_DIR);
}
/**
 * @brief      Slave 3-Wire Mode Start Interrupt Status
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0 = It indicates that the SPI transfer is not active. 
 * @retval     !0 = It indicates that the transfer start in slave mode with no slave selec.  
 *
 * @details    Get Slave 3-Wire Mode Start Interrupt Status
 *             Example: SPI_GET_3WIRE_START_INT_FLAG(SPI0)
 */
static __INLINE uint32_t SPI_GET_3WIRE_START_INT_FLAG(SPI_T *port)
{
    return ((port)->CNTRL2 & SPI_SLV_START_INTSTS);
}
/**
 * @brief      Clear the SPI 3-wire mode start interrupt flag
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Clear the SPI 3-wire mode start interrupt flag
 *             Example: SPI_CLR_3WIRE_START_INT_FLAG(SPI0)
 */
static __INLINE void SPI_CLR_3WIRE_START_INT_FLAG(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_SLV_START_INTSTS);
}
/**
 * @brief      Enable the SPI 3-wire mode start interrupt
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Enable the SPI 3-wire mode start interrupt
 *             Example: SPI_ENABLE_3WIRE_START_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_3WIRE_START_INT(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_SSTA_INTEN);
}
/**
 * @brief      Disable the SPI 3-wire mode start interrupt
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Disable the SPI 3-wire mode start interrupt
 *             Example: SPI_DISABLE_3WIRE_START_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_3WIRE_START_INT(SPI_T *port)
{
    ((port)->CNTRL2 &= (~SPI_SSTA_INTEN));
}
/**
 * @brief      Abort the SPI transfer when the 3-wire mode is enabled
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Abort the SPI transfer when the 3-wire mode is enabled
 *             Example: SPI_ABORT_3WIRE_TRANSFER(SPI0)
 */
static __INLINE void SPI_ABORT_3WIRE_TRANSFER(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_SLV_ABORT);
}

/**
 * @brief      Enable the SPI 3-wire mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Enable the SPI 3-wire mode
 *             Example: SPI_ENABLE_3WIRE_MODE(SPI0)
 */
static __INLINE void SPI_ENABLE_3WIRE_MODE(SPI_T *port)
{
    ((port)->CNTRL2 |= SPI_NOSLVSEL);
}
/**
 * @brief      Disable the SPI 3-wire mode
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Disable the SPI 3-wire mode
 *             Example: SPI_DISABLE_3WIRE_MODE(SPI0)
 */
static __INLINE void SPI_DISABLE_3WIRE_MODE(SPI_T *port)
{
    ((port)->CNTRL2 &= (~SPI_NOSLVSEL));
}
/**
 * @brief      Transmit FIFO Threshold
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x 	
 * @return     None 
 *
 * @details    If the valid data count of the transmit FIFO buffer is less than or equal to the TX_THRESHOLD setting, the TX_INTSTS bit will be set to 1
 *             Example: SPI_SET_TX_FIFO_THRESHOLD(SPI0,7)
 */
static __INLINE void SPI_SET_TX_FIFO_THRESHOLD(SPI_T *port,uint32_t x)
{
   ((port)->FIFO_CTL = ((port)->FIFO_CTL&(~SPI_FIFO_CTL_TX_THRESHOLD_Msk))| SPI_FIFO_TX_THRESHOLD(x));
}
/**
 * @brief      Received  FIFO Threshold
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @param[in]  x 	
 * @return     None 
 *
 * @details    If the valid data count of the receive FIFO buffer is larger than the RX_THRESHOLD setting, the RX_INTSTS bit will be set to 1
 *             Example: SPI_SET_RX_FIFO_THRESHOLD(SPI0,7)
 */
static __INLINE void SPI_SET_RX_FIFO_THRESHOLD(SPI_T *port,uint32_t x)
{
    ((port)->FIFO_CTL = ((port)->FIFO_CTL&(~SPI_FIFO_CTL_RX_THRESHOLD_Msk))| SPI_FIFO_RX_THRESHOLD(x));
}
/**
 * @brief      Receive FIFO Time-out Interrupt Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Receive FIFO Time-out Interrupt Enable, haven't read RX FIFO over the specific time
 *             Example: SPI_ENABLE_TIMEOUT_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_TIMEOUT_INT(SPI_T *port)
{
    ((port)->FIFO_CTL |= SPI_TIMEOUT_INTEN);
}
/**
 * @brief      Receive FIFO Time-out Interrupt Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Receive FIFO Time-out Interrupt Disable
 *             Example: SPI_DISABLE_TIMEOUT_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_TIMEOUT_INT(SPI_T *port)
{
    (((port)->FIFO_CTL &= ~SPI_TIMEOUT_INTEN));
}
/**
 * @brief      Receive FIFO Over Run Interrupt Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Receive FIFO Over Run Interrupt Enable
 *             Example: SPI_ENABLE_RXOVER_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_RXOVER_INT(SPI_T *port)
{
    ((port)->FIFO_CTL |= SPI_RXOVER_INTEN);
}
/**
 * @brief      Receive FIFO Over Run Interrupt Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    Receive FIFO Over Run Interrupt Disable
 *             Example: SPI_DISABLE_RXOVER_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_RXOVER_INT(SPI_T *port)
{
    ((port)->FIFO_CTL &= ~SPI_RXOVER_INTEN);
}
/**
 * @brief      TX Threshold Interrupt Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    TX Threshold Interrupt Enable
 *             Example: SPI_ENABLE_TX_THRESHOLD_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_TX_THRESHOLD_INT(SPI_T *port)
{
    ((port)->FIFO_CTL |= SPI_TX_INTEN);
}
/**
 * @brief      TX Threshold Interrupt Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    TX Threshold Interrupt Disable
 *             Example: SPI_DISABLE_TX_THRESHOLD_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_TX_THRESHOLD_INT(SPI_T *port)
{
    ((port)->FIFO_CTL &= ~SPI_TX_INTEN);
}
/**
 * @brief      RX Threshold Interrupt Enable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    RX Threshold Interrupt Enable
 *             Example: SPI_ENABLE_RX_THRESHOLD_INT(SPI0)
 */
static __INLINE void SPI_ENABLE_RX_THRESHOLD_INT(SPI_T *port)
{
    ((port)->FIFO_CTL |= SPI_RX_INTEN);
}
/**
 * @brief      RX Threshold Interrupt Disable
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    RX Threshold Interrupt Disable
 *             Example: SPI_DISABLE_RX_THRESHOLD_INT(SPI0)
 */
static __INLINE void SPI_DISABLE_RX_THRESHOLD_INT(SPI_T *port)
{
    ((port)->FIFO_CTL &= ~SPI_RX_INTEN);
}
/**
 * @brief      Clear transmit FIFO buffer
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    This bit will be cleared to 0 by hardware after software sets it to 1
 *             Example: SPI_CLEAR_TX_FIFO_BUFFER(SPI0)
 */
static __INLINE void SPI_CLEAR_TX_FIFO(SPI_T *port)
{
    ((port)->FIFO_CTL |= SPI_TX_CLR);
}
/**
 * @brief      Clear receive FIFO buffer
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @return     None 
 *
 * @details    This bit will be cleared to 0 by hardware after software sets it to 1
 *             Example: SPI_CLEAR_RX_FIFO_BUFFER(SPI0)
 */
static __INLINE void SPI_CLEAR_RX_FIFO(SPI_T *port) 
{
    ((port)->FIFO_CTL |= SPI_RX_CLR);
}
/**
 * @brief      Transmit FIFO Data Count 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     The valid data count of transmit FIFO buffer
 *
 * @details    Indicates the valid data count of transmit FIFO buffer
 *             Example: SPI_GET_TX_FIFO_COUNT(SPI0)
 */
static __INLINE uint32_t SPI_GET_TX_FIFO_COUNT(SPI_T *port)
{
    return (((port)->STATUS & SPI_STATUS_TX_FIFO_COUNT_Msk)>>SPI_STATUS_TX_FIFO_COUNT_Pos);
}

/**
 * @brief      Time-out Interrupt Flag
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0    No receive FIFO time-out event
 * @retval     !0    receive FIFO time-out event	happen
 *
 * @details    It indicates that the receive FIFO buffer is not empty and there is not be read
 *             over 64 SPI clock period in master mode and over 576 SPI engine clock period in slave mode
 *             Example: SPI_GET_TIMEOUT(SPI0)
 */
static __INLINE uint32_t SPI_GET_TIMEOUT(SPI_T *port)
{
    return ((port)->STATUS & SPI_STATUS_TIMEOUT);
}
/**
 * @brief      Receive  FIFO Data Count 
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     The valid data count of receive FIFO buffer
 *
 * @details    Indicates the valid data count of receive FIFO buffer
 *             Example: SPI_GET_RX_FIFO_COUNT(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX_FIFO_COUNT(SPI_T *port)
{
    return (((port)->STATUS & SPI_STATUS_RX_FIFO_COUNT_Msk)>>SPI_STATUS_RX_FIFO_COUNT_Pos);
}
/**
 * @brief      Transmit FIFO Threshold Interrupt Status
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0    the valid data count within the transmit FIFO buffer is less than or equal to the setting value of TX_THRESHOLD
 * @retval     1    the valid data count within the transmit FIFO buffer is larger than the setting value of TX_THRESHOLD
 *
 * @details    Transmit FIFO Threshold Interrupt Status
 *             Example: SPI_GET_TX_FIFO_THRESHOLD_IF(SPI0)
 */
static __INLINE uint32_t SPI_GET_TX_FIFO_THRESHOLD_IF(SPI_T *port)
{
    return ((port)->STATUS & SPI_STATUS_TXINT_STS);
}
/**
 * @brief      Receive FIFO Overrun Status
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0   Receive FIFO Not Overrun
 * @retval     1   Receive FIFO Overrun
 *
 * @details    When the receive FIFO buffer is full, the follow-up data will be dropped and this bit will be set to 1
 *             Example: SPI_GET_RX_OVER_RUN(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX_OVERRUN(SPI_T *port)
{
    return ((port)->STATUS & SPI_STATUS_RX_OVER_RUN);
}
/**
 * @brief      Transmit FIFO Threshold Interrupt Status
 *
 * @param[in]  port    SPI port 
 *                     -SPI0
 *                     -SPI1
 *                     -SPI2
 * @retval     0    the valid data count within the receive FIFO buffer is less than or equal to the setting value of RX_THRESHOLD
 * @retval     1    the valid data count within the receive FIFO buffer is larger than the setting value of RX_THRESHOLD
 *
 * @details    Transmit FIFO Threshold Interrupt Status
 *             Example: SPI_GET_RX_FIFO_THRESHOLD(SPI0)
 */
static __INLINE uint32_t SPI_GET_RX_FIFO_THRESHOLD_INT(SPI_T *port)
{
    return ((port)->STATUS & SPI_STATUS_RXINT_STS);
}
/*---------------------------------------------------------------------------------------------------------*/
/* SPI Setting                                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
typedef enum {
	SPI_TYPE0=0x004,
	SPI_TYPE1=0x002,
	SPI_TYPE2=0x804,
	SPI_TYPE3=0x802,
} SPI_TRANS_TYPE;

/*---------------------------------------------------------------------------------------------------------*/
/*  SPI Data Structure 								                                          	           */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct
{	
	uint32_t u32Mode;
	uint32_t u32Type;
	int32_t i32BitLength;
}SPI_DATA_T;

/**
  * @brief  Configure the waveform of SPI transfer.
  * @param  SpiPort: SPI port handler
  *			 eType: Specify the transfer type (SPI_TYPE0 ~ SPI_TYPE2).
  * @retval 1: Success.
  */
  
/*
SPI_TYPE0:CLK_IDLE=low, Tx=falling, Rx=rising          
             _________________________________
    CS    --|          Active state           |---
               _   _   _   _   _   _   _   _  
    CLK   ____| |_| |_| |_| |_| |_| |_| |_| |_____
              
    Tx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |-----
          
    Rx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |-----


SPI_TYPE1:CLK_IDLE=low, Tx=rising, Rx=falling            
             _________________________________
    CS    --|          Active state           |---
               _   _   _   _   _   _   _   _  
    CLK   ____| |_| |_| |_| |_| |_| |_| |_| |_____
              
    Tx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |---
          
    Rx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |---


SPI_TYPE2:CLK_IDLE=high, Tx=falling, Rx=rising
             _________________________________
    CS    --|          Active state           |---
           ___   _   _   _   _   _   _   _   ______ 
    CLK       |_| |_| |_| |_| |_| |_| |_| |_|  
              
    Tx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |----
          
    Rx    ----| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |----


SPI_TYPE3:CLK_IDLE=high, Tx=rising, Rx=falling
             _________________________________
    CS    --|          Active state           |---
           ___   _   _   _   _   _   _   _   ______ 
    CLK       |_| |_| |_| |_| |_| |_| |_| |_|  
              
    Tx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |------
          
    Rx    --| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |------
*/

static __INLINE void SPI_Waveform(SPI_T *SpiPort, SPI_TRANS_TYPE eType)
{   
    SpiPort->CNTRL = (SpiPort->CNTRL&~(SPI_CNTRL_TX_NEG_Msk|SPI_CNTRL_RX_NEG_Msk)) | eType;
}

/*@}*/ /* end of group SPI_MACRO_FUNC */
/*@}*/ /* end of group SPI_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


/*---------------------------------------------------------------------------------------------------------*/
/* Define Function Prototypes                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
void DrvSPI_DeInit(SPI_T *SpiPort);
int32_t DrvSPI_Init(SPI_T *SpiPort, uint32_t u32Mode, SPI_TRANS_TYPE eType,	int32_t i32BitLength);
uint32_t DrvSPI_SetClockFreq(SPI_T *SpiPort, uint32_t u32Clock1, uint32_t u32Clock2);
uint32_t DrvSPI_GetClock1Freq(SPI_T *SpiPort);
uint32_t DrvSPI_GetClock2Freq(SPI_T *SpiPort);
void DrvSPI_EnableInt(SPI_T *SpiPort);
void DrvSPI_DisableInt(SPI_T *SpiPort);
void SPI_Enable3WireStartInt(SPI_T *SpiPort);
void SPI_Disable3WireStartInt(SPI_T *SpiPort);
void SPI_SetFIFOMode(SPI_T *SpiPort, int32_t i32Interval);
int32_t DrvSPI_FIFOWrite8(SPI_T *SpiPort, uint8_t *pu8TxBuf, uint32_t u32WriteLength);
int32_t SPI_FIFOWrite16(SPI_T *SpiPort, uint16_t *pu16TxBuf, uint32_t u32WriteLength);
int32_t SPI_FIFOWrite32(SPI_T *SpiPort, uint32_t *pu32TxBuf, uint32_t u32WriteLength);
int32_t SPI_FIFORead8(SPI_T *SpiPort, uint8_t *pu8RxBuf, uint32_t u32ReadLength);
int32_t SPI_FIFORead16(SPI_T *SpiPort, uint16_t *pu16RxBuf, uint32_t u32ReadLength);
int32_t SPI_FIFORead32(SPI_T *SpiPort, uint32_t *pu32RxBuf, uint32_t u32ReadLength);
void SPI_FIFOReadWrite8(SPI_T *SpiPort, uint8_t *pu8TxBuf, uint8_t *pu8RxBuf, uint32_t u32Length);
void SPI_FIFOReadWrite16(SPI_T *SpiPort, uint16_t *pu16TxBuf, uint32_t *pu16RxBuf, uint32_t u32Length);
void SPI_FIFOReadWrite32(SPI_T *SpiPort, uint32_t *pu32TxBuf, uint32_t *pu32RxBuf, uint32_t u32Length);
uint32_t DrvSPI_GetSourceClockFreq(SPI_T *SpiPort);



#endif

