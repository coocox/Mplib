/******************************************************************************
 * @file     PS2.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/17 13:49p $
 * @brief    NUC123 Series PS2 Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PS2_H__
#define __PS2_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup PS2_MACRO PS2 Macro
  * @{
  */

/** @addtogroup PS2_MACRO_CONTANT PS2 Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/*  PS2CON constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PS2_PS2CON_DATA_HIGH            (1UL<<PS2_PS2CON_FPS2DAT_Pos) /*!< If OVERRIDE is set to high, forces PS2DATA line high */
#define PS2_PS2CON_DATA_LOW             (0UL<<PS2_PS2CON_FPS2DAT_Pos) /*!< If OVERRIDE is set to high, forces PS2DATA line low */

#define PS2_PS2CON_CLK_HIGH             (1UL<<PS2_PS2CON_FPS2CLK_Pos) /*!< If OVERRIDE is set to high, forces PS2CLK  line high */
#define PS2_PS2CON_CLK_LOW              (0UL<<PS2_PS2CON_FPS2CLK_Pos) /*!< If OVERRIDE is set to high, forces PS2CLK  line low */

#define PS2_PS2CON_OVERRIDE_EN          (1UL<<PS2_PS2CON_OVERRIDE_Pos) /*!< PS2CLK and PS2DATA pins are controlled by software */
#define PS2_PS2CON_OVERRIDE_DIS         (0UL<<PS2_PS2CON_OVERRIDE_Pos) /*!< PS2CLK and PS2DATA pins are controlled by internal state machine */

#define PS2_PS2CON_CLR_TXFIFO           (1UL<<PS2_PS2CON_CLRFIFO_Pos) /*!< Clear TX FIFO */

#define PS2_PS2CON_NO_ERR_ACK           (1UL<<PS2_PS2CON_ACK_Pos) /*!< If parity error or stop bit is not received correctly, non acknowledge sent to host at 12th clock */
#define PS2_PS2CON_ALWAYS_ACK           (0UL<<PS2_PS2CON_ACK_Pos) /*!< Always sends acknowledge to host at 12th clock for host to device communication */

#define PS2_PS2CON_RXINT_EN             (1UL<<PS2_PS2CON_RXINTEN_Pos) /*!< Enable data receive complete interrupt */
#define PS2_PS2CON_RXINT_DIS            (0UL<<PS2_PS2CON_RXINTEN_Pos) /*!< Disable data receive complete interrupt */

#define PS2_PS2CON_TXINT_EN             (1UL<<PS2_PS2CON_TXINTEN_Pos) /*!< Enable data transmit complete interrupt */
#define PS2_PS2CON_TXINT_DIS            (0UL<<PS2_PS2CON_TXINTEN_Pos) /*!< Disable data transmit complete interrupt */

#define PS2_PS2CON_ENABLE               (1UL<<PS2_PS2CON_PS2EN_Pos) /*!< Enable PS2 device controller */
#define PS2_PS2CON_DISABLE              (0UL<<PS2_PS2CON_PS2EN_Pos) /*!< Disable PS2 device controller */

/*---------------------------------------------------------------------------------------------------------*/
/*  PS2STATUS constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PS2_TXFIFO_EMPTY                (1UL<<PS2_PS2STATUS_TXEMPTY_Pos) /*!< Indicate transmit FIFO empty or not */
#define PS2_RXBUF_OVERWRITE             (1UL<<PS2_PS2STATUS_RXOVF_Pos) /*!< Indicate if data in PS2RXDATA register is overwritten by new received data */
#define PS2_TRANSMIT_BUSY               (1UL<<PS2_PS2STATUS_TXBUSY_Pos) /*!< Indicate if the PS/2 device is currently sending data */
#define PS2_RECEIVE_BUSY                (1UL<<PS2_PS2STATUS_RXBUSY_Pos) /*!< Indicate if the PS/2 device is currently receiving  data */
#define PS2_RECEIVE_PARITY              (1UL<<PS2_PS2STATUS_RXPARITY_Pos) /*!< It reflects the parity bit for the last received data byte (odd parity) */
#define PS2_FRAME_ERROR                 (1UL<<PS2_PS2STATUS_FRAMERR_Pos) /*!< It reflects the parity bit for the last received data byte (odd parity) */
#define PS2_DATA_STS                    (1UL<<PS2_PS2STATUS_PS2DATA_Pos) /*!< It reflects the status of the PS2DATA line after synchronizing and sampling */
#define PS2_CLK_STS                     (1UL<<PS2_PS2STATUS_PS2CLK_Pos) /*!< It reflects the status of the PS2CLK line after synchronizing */

/*---------------------------------------------------------------------------------------------------------*/
/*  PS2INTID constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PS2_TXINT_STS                   (1UL<<PS2_PS2INTID_TXINT_Pos) /*!< Transmit interrupt flag */
#define PS2_RXINT_STS                   (1UL<<PS2_PS2INTID_RXINT_Pos) /*!< Receive interrupt flag */

/*@}*/ /* end of group PS2_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup PS2_MACRO_FUNC PS2 Macro Func
  @{
*/
/**
 * @brief       Force PS2DATA line high
 *
 * @param       None
 *
 * @return      None
 *
 * @details     If OVERRIDE is set to high, forces PS2DATA line to high level
 */
static __INLINE void PS2_FORCE_PS2DATA_HIGH(void)
{
    PS2->PS2CON |= PS2_PS2CON_DATA_HIGH;
    PS2->PS2CON |= PS2_PS2CON_OVERRIDE_EN;
}

/**
 * @brief       Force PS2DATA line low
 *
 * @param       None
 *
 * @return      None
 *
 * @details     If OVERRIDE is set to high, forces PS2DATA line to high low
 */
static __INLINE void PS2_FORCE_PS2DATA_LOW(void)
{
    PS2->PS2CON &= ~PS2_PS2CON_FPS2DAT_Msk;
    PS2->PS2CON |= PS2_PS2CON_OVERRIDE_EN;
}

/**
 * @brief       Force PS2CLK line high
 *
 * @param       None
 *
 * @return      None
 *
 * @details     If OVERRIDE is set to high, forces PS2CLK line to high level
 */
static __INLINE void PS2_FORCE_PS2CLK_HIGH(void)
{
    PS2->PS2CON |= PS2_PS2CON_CLK_HIGH;
    PS2->PS2CON |= PS2_PS2CON_OVERRIDE_EN;
}

/**
 * @brief       Force PS2CLK line low
 *
 * @param       None
 *
 * @return      None
 *
 * @details     If OVERRIDE is set to high, forces PS2CLK line to high low
 */
static __INLINE void PS2_FORCE_PS2CLK_LOW(void)
{
    PS2->PS2CON &= ~PS2_PS2CON_FPS2CLK_Msk;
    PS2->PS2CON |= PS2_PS2CON_OVERRIDE_EN;
}

/**
 * @brief       Enable software control PS2CLK and PS2DATA pins
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable software control PS2CLK and PS2DATA pins
 */
static __INLINE void PS2_OVERRIDE_ENABLE(void)
{
    PS2->PS2CON |= PS2_PS2CON_OVERRIDE_EN;
}

/**
 * @brief       Disable software control PS2CLK and PS2DATA pins
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2CLK and PS2DATA pins are controlled by internal state machine
 */
static __INLINE void PS2_OVERRIDE_DISABLE(void)
{
    PS2->PS2CON &= (~PS2_PS2CON_OVERRIDE_Msk);
}

/**
 * @brief       PS2 clear transmit FIFO
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 clear transmit FIFO
 */
static __INLINE void PS2_CLR_TXFIFO(void)
{
    PS2->PS2CON |= PS2_PS2CON_CLR_TXFIFO;
    PS2->PS2CON &= ~PS2_PS2CON_CLRFIFO_Msk;
}

/**
 * @brief       PS2 no error acknoledge
 *
 * @param       None
 *
 * @return      None
 *
 * @details     If parity error or stop bit is not received correctly, acknowledge bit will not be sent to host at 12th clock
 */
static __INLINE void PS2_NO_ERROR_ACK(void)
{
    PS2->PS2CON |= PS2_PS2CON_NO_ERR_ACK;
}

/**
 * @brief       PS2 always acknoledge
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Always sends acknowledge to host at 12th clock for host to device communication
 */
static __INLINE void PS2_ALWAYS_ACK(void)
{
    PS2->PS2CON &= (~PS2_PS2CON_ACK_Msk);
}

/**
 * @brief       Set PS2 transmit data FIFO depth
 *
 * @param[in]   depth  TX FIFO data depth. It could be 1~16
 *
 * @return      None
 *
 * @details     Set PS2 transmit data FIFO depth, from 1 to 16 bytes
 */
static __INLINE void PS2_SET_TXFIFO_DEPTH(uint8_t depth)
{
    PS2->PS2CON = (PS2->PS2CON & (~PS2_PS2CON_TXFIFO_DEPTH_Msk)) | (((depth)-1)<<PS2_PS2CON_TXFIFO_DEPTH_Pos);
}

/**
 * @brief       PS2 enable data receive complete interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 enable data receive complete interrupt
 */
static __INLINE void PS2_RXINT_ENABLE(void)
{
    PS2->PS2CON |= PS2_PS2CON_RXINT_EN;
}

/**
 * @brief       PS2 disable data receive complete interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 disable data receive complete interrupt
 */
static __INLINE void PS2_RXINT_DISABLE(void)
{
    PS2->PS2CON &= (~PS2_PS2CON_RXINTEN_Msk);
}

/**
 * @brief       Get PS2 receive interrupt status
 *
 * @param       None
 *
 * @retval      FALSE  No interrupt
 * @retval      TRUE   Receive interrupt occurs
 *
 * @details     Get PS2 receive interrupt status
 */
static __INLINE uint32_t PS2_GET_RXINT_STS(void)
{
    return (PS2->PS2INTID & PS2_RXINT_STS);
}

/**
 * @brief       Clear PS2 receive interrupt status
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Clear PS2 receive interrupt status
 */
static __INLINE void PS2_CLR_RXINT_STS(void)
{
    PS2->PS2INTID = PS2_RXINT_STS;
}

/**
 * @brief       PS2 enable data transmit complete interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 enable data transmit complete interrupt
 */
static __INLINE void PS2_TXINT_ENABLE(void)
{
    PS2->PS2CON |= PS2_PS2CON_TXINT_EN;
}

/**
 * @brief       PS2 disable data transmit complete interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     PS2 disable data transmit complete interrupt
 */
static __INLINE void PS2_TXINT_DISABLE(void)
{
    PS2->PS2CON &= (~PS2_PS2CON_TXINTEN_Msk);
}

/**
 * @brief       Get PS2 transmit interrupt status
 *
 * @param       None
 *
 * @retval      FALSE  No interrupt
 * @retval      TRUE   Transmit interrupt occurs
 *
 * @details     Get PS2 transmit interrupt status
 */
static __INLINE uint32_t PS2_GET_TXINT_STS(void)
{
    return (PS2->PS2INTID & PS2_TXINT_STS);
}

/**
 * @brief       Clear PS2 transmit interrupt status
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Clear PS2 transmit interrupt status
 */
static __INLINE void PS2_CLR_TXINT_STS(void)
{
    PS2->PS2INTID = PS2_TXINT_STS;
}

/**
 * @brief       Enable PS2 device controller
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Enable PS2 device controller
 */
static __INLINE void PS2_ENABLE(void)
{
    PS2->PS2CON |= PS2_PS2CON_ENABLE;
}

/**
 * @brief       Disable PS2 device controller
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Disable PS2 device controller
 */
static __INLINE void PS2_DISABLE(void)
{
    PS2->PS2CON &= (~PS2_PS2CON_PS2EN_Msk);
}

/**
 * @brief       Set PS2 transmit data register x
 *
 * @param[in]   x     PS2 transmit data register number. It could be 0~3
 * @param[in]   data  Data to be written to PS2 transmit data register x
 *
 * @return      None
 *
 * @details     Set PS2 transmit data register x
 */
static __INLINE void PS2_SET_PS2TXDATA(uint8_t x, uint32_t data)
{
    PS2->PS2TXDATA[(x)] = (data);
}

/**
 * @brief       Get PS2 receive data register
 *
 * @param       None
 *
 * @return      Value of PS2 receive data register
 *
 * @details     Get value of PS2 receive data register
 */
static __INLINE uint32_t PS2_GET_PS2RXDATA(void)
{
    return (PS2->PS2RXDATA);
}

/**
 * @brief       Get PS2 transmit shift register byte index
 *
 * @param       None
 *
 * @return      Byte index in transmit shift register
 *
 * @details     It indicates which data byte in transmit data shift register. \n
 *              When all data in FIFO is transmitted and it will be cleared to 0
 */
static __INLINE uint32_t PS2_GET_BYTE_INDEX(void)
{
    return ((PS2->PS2STATUS & PS2_PS2STATUS_BYTEIDX_Msk) >> PS2_PS2STATUS_BYTEIDX_Pos);
}

/**
 * @brief       Check if PS2 TX FIFO empty
 *
 * @param       None
 *
 * @retval      FALSE  There is data to be transmitted
 * @retval      TRUE   TX FIFO is empty
 *
 * @details     Check if PS2 TX FIFO empty
 */
static __INLINE uint32_t PS2_IS_TXFIFO_EMPTY(void)
{
    return (PS2->PS2STATUS & PS2_TXFIFO_EMPTY);
}

/**
 * @brief       Check if PS2 RX Buffer Overwrite
 *
 * @param       None
 *
 * @retval      FALSE  No overwrite
 * @retval      TRUE   Data in PS2RXDATA register is overwritten by new received data
 *
 * @details     Check if PS2 RX Buffer Overwrite
 */
static __INLINE uint32_t PS2_IS_RXBUF_OVERWRITE(void)
{
    return (PS2->PS2STATUS & PS2_RXBUF_OVERWRITE);
}

/**
 * @brief       Clear PS2 RX Buffer Overwrite flag
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Clear PS2 RX Buffer Overwrite flag
 */
static __INLINE void PS2_CLR_RXBUF_OVF(void)
{
    PS2->PS2STATUS = PS2_RXBUF_OVERWRITE;
}

/**
 * @brief       Check if PS2 transmit busy
 *
 * @param       None
 *
 * @retval      FALSE  PS2 device is idle
 * @retval      TRUE   PS2 device is currently sending data
 *
 * @details     Check if PS2 transmit busy
 */
static __INLINE uint32_t PS2_IS_TX_BUSY(void)
{
    return (PS2->PS2STATUS & PS2_TRANSMIT_BUSY);
}

/**
 * @brief       Check if PS2 receive busy
 *
 * @param       None
 *
 * @retval      FALSE  PS2 device is idle
 * @retval      TRUE   PS2 device is currently receiving data
 *
 * @details     Check if PS2 receive busy
 */
static __INLINE uint32_t PS2_IS_RX_BUSY(void)
{
    return (PS2->PS2STATUS & PS2_RECEIVE_BUSY);
}

/**
 * @brief       Get PS2 Received Parity
 *
 * @param       None
 *
 * @return      Parity bit for the last received data byte (odd parity)
 *
 * @details     Get PS2 Received parity for the last received data byte
 */
static __INLINE uint32_t PS2_GET_RX_PARITY(void)
{
    return (PS2->PS2STATUS & PS2_RECEIVE_PARITY);
}

/**
 * @brief       Check if PS2 Frame error occurred
 *
 * @param       None
 *
 * @retval      FALSE  No frame error
 * @retval      TRUE   Frame error occurred
 *
 * @details     Check if PS2 Frame error occurred
 */
static __INLINE uint32_t PS2_IS_FRAME_ERROR(void)
{
    return (PS2->PS2STATUS & PS2_FRAME_ERROR);
}

/**
 * @brief       Clear PS2 frame error flag
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Clear PS2 frame error flag
 */
static __INLINE void PS2_CLR_FRAMERR(void)
{
    PS2->PS2STATUS = PS2_FRAME_ERROR;
}

/**
 * @brief       Get status of the PS2DATA line
 *
 * @param       None
 *
 * @retval      0  PS2DATA is low level
 * @retval      1  PS2DATA is high level
 *
 * @details     Get status of the PS2DATA line after synchronizing and sampling
 */
static __INLINE uint32_t PS2_GET_PS2DATA(void)
{
    return ((PS2->PS2STATUS & PS2_DATA_STS)>>PS2_PS2STATUS_PS2DATA_Pos);
}

/**
 * @brief       Get status of the PS2CLK line
 *
 * @param       None
 *
 * @retval      0  PS2CLK is low level
 * @retval      1  PS2CLK is high level
 *
 * @details     Get status of the PS2CLK line after synchronizing
 */
static __INLINE uint32_t PS2_GET_PS2CLK(void)
{
    return ((PS2->PS2STATUS & PS2_DATA_STS)>>PS2_PS2STATUS_PS2CLK_Pos);
}

/*@}*/ /* end of group PS2_MACRO_FUNC */
/*@}*/ /* end of group PS2_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


#endif
