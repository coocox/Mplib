/**************************************************************************//**
 * @file     PS2.h
 * @version  V2.0
 * $Revision: 1 $
 * $Date: 12/08/08 5:39p $
 * @brief    NUC200 Series PS2 Driver Header File
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PS2_H__
#define __PS2_H__

/*---------------------------------------------------------------------------------------------------------*/
/* Include related headers                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#include "NUC200Series.h"

/*---------------------------------------------------------------------------------------------------------*/
/* PS2_PS2CON constant definitions                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define PS2_PS2CON_TXFIFODEPTH(x) (((x)-1) << PS2_PS2CON_TXFIFO_DEPTH_Pos) /*!< PS2_CON setting for TX FIFO DEPTH. it could be 0~15 */

/*---------------------------------------------------------------------------------------------------------*/
/*  Define Macros and functions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/

/**
 * @details    Force PS2DATA Pin Hi 
 */

#define _PS2_FORCE_DATA_PIN_HI() (PS2->PS2CON |= PS2_PS2CON_FPS2DAT_Msk)
/**
 * @details    Force PS2DATA Pin Lo 
 */
#define _PS2_FORCE_DATA_PIN_LO() (PS2->PS2CON &= (~PS2_PS2CON_FPS2DAT_Msk))

/**
 * @details    Force PS2CLK Pin Hi 
 */
#define _PS2_FORCE_CLK_PIN_HI() (PS2->PS2CON |= PS2_PS2CON_FPS2CLK_Msk)

/**
 * @details    Force PS2CLK Pin Lo 
 */
#define _PS2_FORCE_CLK_PIN_LO() (PS2->PS2CON &= (~PS2_PS2CON_FPS2CLK_Msk))

/**
 * @details    Software Override PS/2 CLK/DATA Pin State.
 */
#define _PS2_SOFTWARE_OVERRIDE_ENABLE()  (PS2->PS2CON |= PS2_PS2CON_OVERRIDE_Msk)
 
/**
 * @details    Internal State Machine Override PS/2 CLK/DATA Pin State.
 */ 
#define _PS2_SOFTWARE_OVERRIDE_DISABLE() (PS2->PS2CON &= (~PS2_PS2CON_OVERRIDE_Msk))

/**
 * @details    Always Send Acknowledge to Host at 12th clock
 */
#define _PS2_ACK_ENABLE()	(PS2->PS2CON &= (~PS2_PS2CON_ACK_Msk))

/**
 * @details    If Parity error or Stop bit is Not Received Correctly, Acknowledge will Not be Sent to host at 12th clock
 */
#define _PS2_ACK_DISABLE()	(PS2->PS2CON |= PS2_PS2CON_ACK_Msk)

/**
 * @details    Configure the Transmit Data FIFO Depth PS/2 port. The x setting can be 1-16.
 */
#define _PS2_SET_TX_FIFO_DEPTH(x) (PS2->PS2CON = (PS2->PS2CON & ~PS2_PS2CON_TXFIFO_DEPTH_Msk) | PS2_PS2CON_TXFIFODEPTH(x))

/**
 * @details    Enable Receive Interrupt
 */
#define _PS2_RX_INTERRUPT_ENABLE()  (PS2->PS2CON |= PS2_PS2CON_RXINTEN_Msk)

/**
 * @details    Disable Receive Interrupt
 */
#define _PS2_RX_INTERRUPT_DISABLE() (PS2->PS2CON &= (~PS2_PS2CON_RXINTEN_Msk))

/**
 * @details    Enable Transmit Interrupt
 */
#define _PS2_TX_INTERRUPT_ENABLE() (PS2->PS2CON |= PS2_PS2CON_TXINTEN_Msk)

/**
 * @details    Disable Transmit Interrupt
 */
#define _PS2_TX_INTERRUPT_DISABLE() (PS2->PS2CON &= (~PS2_PS2CON_TXINTEN_Msk))

/**
 * @details    Enable PS/2 Device
 */
#define _PS2_DEVICE_ENABLE()  (PS2->PS2CON |= PS2_PS2CON_PS2EN_Msk)

/**
 * @details    Disable PS/2 Device
 */
#define _PS2_DEVICE_DISABLE() (PS2->PS2CON &= (~PS2_PS2CON_PS2EN_Msk))

/**
 * @details    Write Data to Transmit Buffer0
 */					   
#define _PS2_WRITE_TX_DATA0(x) (PS2->PS2TXDATA0 = (x))

/**
 * @details    Write Data to Transmit Buffer1
 */
#define _PS2_WRITE_TX_DATA1(x) (PS2->PS2TXDATA1 = (x))

/**
 * @details    Write Data to Transmit Buffer2
 */
#define _PS2_WRITE_TX_DATA2(x) (PS2->PS2TXDATA2 = (x))

/**
 * @details    Write Data to Transmit Buffer3
 */ 
#define _PS2_WRITE_TX_DATA3(x) (PS2->PS2TXDATA3 = (x))

/**
 * @details    Get Data from Receive Data Buffer
 */		
#define _PS2_GET_RX_DATA() (PS2->PS2RXDATA)

/**
 * @details    Get indicates which data byte in transmit data shift register
 */								
#define _PS2_GET_TXBUF_BYTE_INDEX() ((PS2->PS2STATUS & PS2_PS2STATUS_BYTEIDX_Msk)>>PS2_PS2STATUS_BYTEIDX_Pos)

/**
 * @details    Get the TX FIFO Empty flag
 */				
#define _PS2_GET_TX_FIFO_EMPTY_FLAG() 	((PS2->PS2STATUS & PS2_PS2STATUS_TXEMPTY_Msk)>>PS2_PS2STATUS_TXEMPTY_Pos) 									

/**
 * @details    Get the Rx Buffer Overwrite flag
 */				
#define _PS2_GET_RXBUF_OVERWRITE_FLAG() ((PS2->PS2STATUS & PS2_PS2STATUS_RXOVF_Msk)>>PS2_PS2STATUS_RXOVF_Pos)

/**
 * @details    clear the Rx Buffer Overwrite flag
 */ 
#define _PS2_CLEAR_RX_OVERWRITE_FLAG() (PS2->PS2STATUS = PS2->PS2STATUS|PS2_PS2STATUS_RXOVF_Msk)

/**
 * @details    Get the Device Tx Busy flag
 */				
#define _PS2_GET_TX_BUSY_FLAG() ((PS2->PS2STATUS & PS2_PS2STATUS_TXBUSY_Msk)>>PS2_PS2STATUS_TXBUSY_Pos)	

/**
 * @details    Get the Device Rx Busy flag
 */				
#define _PS2_GET_RX_BUSY_FLAG() ((PS2->PS2STATUS & PS2_PS2STATUS_RXBUSY_Msk)>>PS2_PS2STATUS_RXBUSY_Pos)

/**
 * @details    Get the parity bit for the last received data byte (odd parity).
 */				
#define _PS2_GET_RX_PARITY_FLAG() ((PS2->PS2STATUS & PS2_PS2STATUS_RXPARITY_Msk)>>PS2_PS2STATUS_RXPARITY_Pos)

/**
 * @details    Get the Frame Error flag
 */				
#define _PS2_GET_FRAME_ERROR_FLAG() ((PS2->PS2STATUS & PS2_PS2STATUS_FRAMERR_Msk)>>PS2_PS2STATUS_FRAMERR_Pos)

/**
 * @details    Clear the Frame Error flag
 */ 
#define _PS2_CLEAR_FRAME_ERROR_FLAG() (PS2->PS2STATUS = PS2->PS2STATUS|PS2_PS2STATUS_FRAMERR_Msk)

/**
 * @details    Get the Data Pin State flag
 */				
#define _PS2_GET_DATA_PIN_STATUS() ((PS2->PS2STATUS & PS2_PS2STATUS_PS2DATA_Msk)>>PS2_PS2STATUS_PS2DATA_Pos)

/**
 * @details    Get the Clk Pin State flag
 */				
#define _PS2_GET_CLK_PIN_STATUS() ((PS2->PS2STATUS & PS2_PS2STATUS_PS2CLK_Msk)>>PS2_PS2STATUS_PS2CLK_Pos)

/**
 * @details    Get the Transmit Interrupt flag
 */
#define _PS2_GET_TX_INT_FLAG() ((PS2->PS2INTID&PS2_PS2INTID_TXINT_Msk)>>PS2_PS2INTID_TXINT_Pos)

/**
 * @details    Clear the Transmit Interrupt flag
 */
#define _PS2_CLEAR_TX_INT_FLAG() (PS2->PS2INTID = PS2->PS2INTID|PS2_PS2INTID_TXINT_Msk)

/**
 * @details    Get the Receive Interrupt flag
 */
#define _PS2_GET_RX_INT_FLAG()	 ((PS2->PS2INTID&PS2_PS2INTID_RXINT_Msk)>>PS2_PS2INTID_RXINT_Pos)

/**
 * @details    Clear the Receive Interrupt flag
 */
#define _PS2_CLEAR_RX_INT_FLAG() (PS2->PS2INTID = PS2->PS2INTID|PS2_PS2INTID_RXINT_Msk)

/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     ADC IP reset 
 */
static __INLINE void PS2_ResetIP()
{
	SYS->IPRSTC2 |=  SYS_IPRSTC2_PS2_RST_Msk;
	SYS->IPRSTC2 &= ~SYS_IPRSTC2_PS2_RST_Msk;
}
/**
 * @details     Clear TX FIFO
 */
static __INLINE void PS2_CLEAR_TX_FIFO()
{
    (PS2->PS2CON |= PS2_PS2CON_CLRFIFO_Msk);
    (PS2->PS2CON &= (~PS2_PS2CON_CLRFIFO_Msk));
}
#endif

