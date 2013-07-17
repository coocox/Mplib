/**************************************************************************//**
 * @file     UART.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/14 1:45p $
 * @brief    IP UART Header File for Nuc123 Series
 *
 * @note                                                                              
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __UART_H__
#define __UART_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup UART_MACRO UART Macro
  * @{
  */
/** @addtogroup UART_MACRO_CONTANT UART Macro Contant
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/* UA_IER constants definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/

#define UART_IER_DMA_RX_EN            (1ul << UART_IER_DMA_RX_EN_Pos)	   /*!< This bit can enable or disable RX DMA service */
#define UART_IER_DMA_TX_EN            (1ul << UART_IER_DMA_TX_EN_Pos)	   /*!< This bit can enable or disable TX DMA service */
#define UART_IER_AUTO_CTS_EN          (1ul << UART_IER_AUTO_CTS_EN_Pos)	   /*!< CTS Auto Flow Control Enable  */
#define UART_IER_AUTO_RTS_EN          (1ul << UART_IER_AUTO_RTS_EN_Pos)	   /*!< RTS Auto Flow Control Enable */
#define UART_IER_TIMEOUT_COUNTER_EN   (1ul << UART_IER_TIME_OUT_EN_Pos)	  /*!< Time Out Counter Enable */
#define UART_IER_WAKE_EN              (1ul << UART_IER_WAKE_EN_Pos)		  /*!< UART Wake-up Function Enable */
#define UART_IER_BUF_ERR_IEN          (1ul << UART_IER_BUF_ERR_IEN_Pos)	  /*!< Buffer Error Interrupt Enable */
#define UART_IER_RTO_IEN              (1ul << UART_IER_RTO_IEN_Pos)		  /*!< RX Time Out Interrupt Enable */
#define UART_IER_MODEM_IEN            (1ul << UART_IER_MODEM_IEN_Pos)	  /*!< Modem Status Interrupt Enable */
#define UART_IER_RLS_IEN              (1ul << UART_IER_RLS_IEN_Pos)		  /*!< Receive Line Status Interrupt Enable  */
#define UART_IER_THRE_IEN             (1ul << UART_IER_THRE_IEN_Pos)	  /*!< Transmit Holding Register Empty Interrupt Enable */
#define UART_IER_RDA_IEN              (1ul << UART_IER_RDA_IEN_Pos)		  /*!< Receive Data Available Interrupt Enable. */
/*---------------------------------------------------------------------------------------------------------*/
/* UA_FCR constants definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_FCR_RTS_TRI_LEV_1BYTE      (0x0 << UART_FCR_RTS_TRI_LEV_Pos)  /*!< UA_FCR setting to set RTS Trigger Level to 1 bit */
#define UART_FCR_RTS_TRI_LEV_4BYTES     (0x1 << UART_FCR_RTS_TRI_LEV_Pos)  /*!< UA_FCR setting to set RTS Trigger Level to 4 bits */
#define UART_FCR_RTS_TRI_LEV_8BYTES     (0x2 << UART_FCR_RTS_TRI_LEV_Pos)  /*!< UA_FCR setting to set RTS Trigger Level to 8 bits */
#define UART_FCR_RTS_TRI_LEV_14BYTES    (0x3 << UART_FCR_RTS_TRI_LEV_Pos)  /*!< UA_FCR setting to set RTS Trigger Level to 14 bits */

#define UART_FCR_RX_DIS                 (1ul << UART_FCR_RX_DIS_Pos)	  /*!<Receiver Disable Register */

#define UART_FCR_RFITL_1BYTE            (0x0 << UART_FCR_RFITL_Pos)   /*!< UA_FCR setting to set RX FIFO Trigger Level to 1 bit */
#define UART_FCR_RFITL_4BYTES           (0x1 << UART_FCR_RFITL_Pos)   /*!< UA_FCR setting to set RX FIFO Trigger Level to 4 bits */
#define UART_FCR_RFITL_8BYTES           (0x2 << UART_FCR_RFITL_Pos)   /*!< UA_FCR setting to set RX FIFO Trigger Level to 8 bits */
#define UART_FCR_RFITL_14BYTES          (0x3 << UART_FCR_RFITL_Pos)   /*!< UA_FCR setting to set RX FIFO Trigger Level to 14 bits */

#define UART_FCR_RST_TX_FIFO            (1ul << UART_FCR_TFR_Pos)		/*!<TX Field Software Reset */
#define UART_FCR_RST_RX_FIFO            (1ul << UART_FCR_RFR_Pos)		/*!<RX Field Software Reset */
/*---------------------------------------------------------------------------------------------------------*/
/* UA_LCR constants definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_LCR_BCB        (1ul << UART_LCR_BCB_Pos)	  /*!<Break Control Bit */
#define UART_LCR_SPE        (1ul << UART_LCR_SPE_Pos)	  /*!<Stick Parity Enable */
#define UART_LCR_EPE        (1ul << UART_LCR_EPE_Pos)	  /*!<Even Parity Enable*/
#define UART_LCR_PBE        (1ul << UART_LCR_PBE_Pos)	  /*!<Parity Bit Enable */

#define UART_STOP_BIT_1     (0x0 << UART_LCR_NSB_Pos) /*!< UA_LCR setting for one stop bit  */
#define UART_STOP_BIT_1_5   (0x1 << UART_LCR_NSB_Pos) /*!< UA_LCR setting for 1.5 stop bit when 5-bit word length  */
#define UART_STOP_BIT_2     (0x1 << UART_LCR_NSB_Pos) /*!< UA_LCR setting for two stop bit when 6, 7, 8-bit word length */

#define UART_WORD_LEN_5     (0<< UART_LCR_WLS_Pos) /*!< UA_LCR setting to set UART word length to 5 bits */
#define UART_WORD_LEN_6     (1<< UART_LCR_WLS_Pos) /*!< UA_LCR setting to set UART word length to 6 bits */
#define UART_WORD_LEN_7     (2<< UART_LCR_WLS_Pos) /*!< UA_LCR setting to set UART word length to 7 bits */
#define UART_WORD_LEN_8     (3<< UART_LCR_WLS_Pos) /*!< UA_LCR setting to set UART word length to 8 bits */

#define UART_PARITY_NONE    (0x0 << UART_LCR_PBE_Pos) /*!< UA_LCR setting to set UART as no parity   */
#define UART_PARITY_ODD     (0x1 << UART_LCR_PBE_Pos) /*!< UA_LCR setting to set UART as odd parity  */
#define UART_PARITY_EVEN    (0x3 << UART_LCR_PBE_Pos) /*!< UA_LCR setting to set UART as even parity */
#define UART_PARITY_MARK    (0x5 << UART_LCR_PBE_Pos) /*!< UA_LCR setting to keep parity bit as '1'  */
#define UART_PARITY_SPACE   (0x7 << UART_LCR_PBE_Pos) /*!< UA_LCR setting to keep parity bit as '0'  */
/*---------------------------------------------------------------------------------------------------------*/
/* UART MCR constants definitions                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_MCR_RTS_ST     	 (1ul << UART_MCR_RTS_ST_Pos)   /*!< RTS Pin State  */
#define UART_MCR_LEV_RTS_HIGH  (1ul << UART_MCR_LEV_RTS_Pos)  /*!< RTS Trigger Level   */
#define UART_MCR_LEV_RTS_LOW   (0ul << UART_MCR_LEV_RTS_Pos)  /*!< RTS Trigger Level   */
#define UART_MCR_RTS        	 (1ul << UART_MCR_RTS_Pos)	    /*!< Drive RTS (Request-To-Send) Signal  */ 
/*---------------------------------------------------------------------------------------------------------*/
/* UART MSR constants definitions                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_MSR_CST_ST      		(1ul << UART_MSR_CTS_ST_Pos)	 /*!< CTS Pin Status   */
#define UART_MSR_LEV_CTS_HIGH     (1ul << UART_MSR_LEV_CTS_Pos)	 /*!< CTS Trigger Level  */
#define UART_MSR_LEV_CTS_LOW      (0ul << UART_MSR_LEV_CTS_Pos)	 /*!< CTS Trigger Level  */
#define UART_MSR_DCTSF       		(1ul << UART_MSR_DCTSF_Pos)      /*!< Detect CTS State Change Flag   */
/*---------------------------------------------------------------------------------------------------------*/
/* UART FSR constants definitions                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_FSR_TE_FLAG        (1ul << UART_FSR_TE_FLAG_Pos)	   /*!< Transmitter Empty Flag (Read Only)  */
#define UART_FSR_TX_OVER_IF     (1ul << UART_FSR_TX_OVER_IF_Pos)   /*!< TX Overflow Error Interrupt Flag (Read Only)  */
#define UART_FSR_TX_FULL        (1ul << UART_FSR_TX_FULL_Pos)	   /*!< Transmitter FIFO Full (Read Only) */
#define UART_FSR_TX_EMPTY       (1ul << UART_FSR_TX_EMPTY_Pos)	   /*!< Transmitter FIFO Empty (Read Only)  */
#define UART_FSR_TX_POINTER     (1ul << UART_FSR_TX_POINTER_Pos)   /*!< TX FIFO Pointer (Read Only)  */
#define UART_FSR_RX_FULL        (1ul << UART_FSR_RX_FULL_Pos)	   /*!< Receiver FIFO Full (Read Only)  */
#define UART_FSR_RX_EMPTY       (1ul << UART_FSR_RX_EMPTY_Pos)	   /*!< Receiver FIFO Empty (Read Only)  */
#define UART_FSR_RX_POINTER     (1ul << UART_FSR_RX_POINTER_Pos)   /*!< RX FIFO Pointer (Read Only)  */
#define UART_FSR_BIF            (1ul << UART_FSR_BIF_Pos)		   /*!< Break Interrupt Flag (Read Only)  */
#define UART_FSR_FEF            (1ul << UART_FSR_FEF_Pos)		   /*!< Framing Error Flag (Read Only)  */
#define UART_FSR_PEF            (1ul << UART_FSR_PEF_Pos)		   /*!< Parity Error Flag (Read Only)  */
#define UART_FSR_ADD_DETF       (1ul << UART_FSR_RS485_ADD_DETF_Pos)/*!< RS-485 Address Byte Detection Flag (Read Only)   */
#define UART_RX_OVER_IF         (1ul << UART_FSR_RX_OVER_IF_Pos)   /*!< RX Overflow Error IF (Read Only)  */
/*---------------------------------------------------------------------------------------------------------*/
/* UART ISR constants definitions                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_ISR_HW_BUF_ERR_INT (1ul << UART_ISR_HW_BUF_ERR_INT_Pos) /*!< In DMA Mode, Buffer Error Interrupt Indicator (Read Only)  */
#define UART_ISR_HW_TOUT_INT    (1ul << UART_ISR_HW_TOUT_INT_Pos)	 /*!< In DMA Mode, Time Out Interrupt Indicator (Read Only) */
#define UART_ISR_HW_MODEM_INT   (1ul << UART_ISR_HW_MODEM_INT_Pos)	 /*!< In DMA Mode, MODEM Status Interrupt Indicator (Read Only)   */
#define UART_ISR_HW_RLS_INT     (1ul << UART_ISR_HW_RLS_INT_Pos)	 /*!< In DMA Mode, Receive Line Status Interrupt Indicator (Read Only) */
#define UART_ISR_HW_BUF_ERR_IF  (1ul << UART_ISR_HW_BUF_ERR_IF_Pos)	 /*!< In DMA Mode, Buffer Error Interrupt Flag (Read Only) */
#define UART_ISR_HW_TOUT_IF     (1ul << UART_ISR_HW_TOUT_IF_Pos)     /*!< In DMA Mode, Time Out Interrupt Flag (Read Only) */
#define UART_ISR_HW_MODEM_IF    (1ul << UART_ISR_HW_MODEM_IF_Pos)    /*!< In DMA Mode, MODEM Interrupt Flag (Read Only)  */
#define UART_ISR_HW_HW_RLS_IF   (1ul << UART_ISR_HW_RLS_IF_Pos)	     /*!< In DMA Mode, Receive Line Status Flag (Read Only)   */
#define UART_ISR_BUF_ERR_INT    (1ul << UART_ISR_BUF_ERR_INT_Pos)    /*!< Buffer Error Interrupt Indicator (Read Only)  */
#define UART_ISR_TOUT_INT       (1ul << UART_ISR_TOUT_INT_Pos)	     /*!< Time Out Interrupt Indicator (Read Only)  */
#define UART_ISR_MODEM_INT      (1ul << UART_ISR_MODEM_INT_Pos)	     /*!< MODEM Status Interrupt Indicator (Read Only).  */
#define UART_ISR_RLS_INT        (1ul << UART_ISR_RLS_INT_Pos)	     /*!< Receive Line Status Interrupt Indicator (Read Only)  */
#define UART_ISR_THRE_INT       (1ul << UART_ISR_THRE_INT_Pos)	     /*!< Receive Line Status Interrupt Indicator (Read Only) */
#define UART_ISR_RDA_INT        (1ul << UART_ISR_RDA_INT_Pos)	     /*!< Receive Data Available Interrupt Indicator (Read Only)  */
#define UART_ISR_BUF_ERR_IF     (1ul << UART_ISR_BUF_ERR_IF_Pos)     /*!< Buffer Error Interrupt Flag (Read Only) */
#define UART_ISR_TOUT_IF        (1ul << UART_ISR_TOUT_IF_Pos)	     /*!< Time Out Interrupt Flag (Read Only) */
#define UART_ISR_MODEM_IF       (1ul << UART_ISR_MODEM_IF_Pos)	     /*!< MODEM Interrupt Flag (Read Only)  */
#define UART_ISR_RLS_IF         (1ul << UART_ISR_RLS_IF_Pos)	     /*!< Receive Line Interrupt Flag (Read Only).  */
#define UART_ISR_THRE_IF        (1ul << UART_ISR_THRE_IF_Pos)	     /*!< Transmit Holding Register Empty Interrupt Flag (Read Only).   */
#define UART_ISR_RDA_IF         (1ul << UART_ISR_RDA_IF_Pos)	     /*!< Receive Data Available Interrupt Flag (Read Only).  */

/*---------------------------------------------------------------------------------------------------------*/
/* UART BAUD constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_BAUD_MODE0         (0)									   /*!< Baud mode0  */
#define UART_BAUD_MODE2          (UART_BAUD_DIV_X_EN_Msk | UART_BAUD_DIV_X_ONE_Msk)	 /*!< Baud mode2  */

/*---------------------------------------------------------------------------------------------------------*/
/* UART IRCR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_IRCR_INV_RX         (1ul << UART_IRCR_INV_RX_Pos)		   /*!<  Inverse RX input signal */
#define UART_IRCR_INV_TX         (1ul << UART_IRCR_INV_TX_Pos)		   /*!<  Inverse TX output signal  */
#define UART_IRCR_TX_SELECT      (1ul << UART_IRCR_TX_SELECT_Pos)	   /*!< Enable IrDA transmitter  */

/*---------------------------------------------------------------------------------------------------------*/
/* UART ALT_CSR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_RS485_ADD_EN        (1ul << UART_ALT_CSR_RS485_ADD_EN_Pos)	   /*!<  RS-485 Address Detection Enable */
#define UART_RS485_AUD           (1ul << UART_ALT_CSR_RS485_AUD_Pos)       /*!<  RS-485 Auto Direction Mode (AUD) */
#define UART_RS485_AAD           (1ul << UART_ALT_CSR_RS485_AAD_Pos)       /*!<  RS-485 Auto Address Detection Operation Mode (AAD) */
#define UART_RS485_NMM           (1ul << UART_ALT_CSR_RS485_NMM_Pos)       /*!<  RS-485 Normal Multi-drop Operation Mode (NMM) */
/*---------------------------------------------------------------------------------------------------------*/
/* UA_FUNC_SEL constants definitions                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
#define UART_FUNC_SEL_UART  (0x0 << UART_FUN_SEL_FUN_SEL_Pos) /*!< UA_FUNC_SEL setting to set UART Function  (Default) */
#define UART_FUNC_SEL_IrDA  (0x2 << UART_FUN_SEL_FUN_SEL_Pos) /*!< UA_FUNC_SEL setting to set IrDA Function            */
#define UART_FUNC_SEL_RS485 (0x3 << UART_FUN_SEL_FUN_SEL_Pos) /*!< UA_FUNC_SEL setting to set RS485 Function           */

/*@}*/ /* end of group UART_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup UART_MACRO_FUNC UART Macro Func
  @{
*/

/**
 * @brief      Receive one data byte from specify uart port
 *
 * @param[in]  UART         Structure pointer of UART Channel selected, should be: 
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @return     The oldest data byte in RX FIFO 
 *
 * @details    The function is used to get one data byte from RX FIFO of specified UART port.\n
 *             Example: UART_READ(UART0)
 */
static __INLINE uint8_t UART_READ(UART_T *UART)
{
  return ((UART)->RBR);
}
/**
 * @brief      Send one data byte from specify uart port
 *
 * @param[in]  UART         Structure pointer of UART Channel selected, should be:
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  u8Data       Data byte to transmit 
 *                          
 * @return     None
 *
 * @details    The function is used to send UART data.\n
 *             Example: UART_SENDBYTE(UART0,0x55)
 */
static __INLINE void UART_WRITE(UART_T *UART,uint8_t u8Data)   
{
    ((UART)->THR = (u8Data));
}
/**
 * @brief      Enable specified interrupt
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  eIntTypeSel  Interrupt type select
 *                          - UART_IER_BUF_ERR_IEN : Buffur Error interrupt   
 *                          - UART_IER_RTO_IEN     : Rx time-out interrupt       
 *                          - UART_IER_MODEM_IEN   : Modem interrupt           
 *                          - UART_IER_RLS_IEN     : Rx Line status interrupt                              
 *                          - UART_IER_THRE_IEN    : Tx empty interrupt          
 *                          - UART_IER_RDA_IEN     : Rx ready interrupt           
 *
 * @return     None
 *                                                           
 * @details    The function is used to enable specified UART interrupt.\n
 *             Example: UART_ENABLE_INT(UART0,(UART_IER_RDA_IEN | UART_IER_RLS_IEN)
 *             
 * @note       When enable eDRVUART_THRE_INT interrupt source, the interrup will happen continouly if
 *             TX_FIFO is empty. Remind you that be careful to use it.\n  
 *             Please reference TRM to get more information.
 *
 */

static __INLINE void UART_ENABLE_INT(UART_T *UART,uint32_t eIntTypeSel)    
{
    ((UART)->IER |= (eIntTypeSel));
}
/**
 * @brief      Disable specified interrupt  
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  eIntTypeSel  Interrupt type select 
 *                          - UART_IER_BUF_ERR_IEN : Buffur Error interrupt   
 *                          - UART_IER_RTO_IEN     : Rx time-out interrupt       
 *                          - UART_IER_MODEM_IEN   : Modem interrupt           
 *                          - UART_IER_RLS_IEN     : Rx Line status interrupt                              
 *                          - UART_IER_THRE_IEN    : Tx empty interrupt          
 *                          - UART_IER_RDA_IEN     : Rx ready interrupt           
 * @return     None
 *                                                           
 * @details    The function is used to disable UART specified interrupt.\n
 *             Example: UART_DISABLE_INT(UART0,(UART_IER_RDA_IEN | UART_IER_RLS_IEN))
 */
static __INLINE void UART_DISABLE_INT(UART_T *UART,uint32_t eIntSel)    
{ 
    ((UART)->IER &= ~ (eIntSel));
}
/**
 * @brief      Check INT set or not  
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *                                                           
 * @details    Check INT set or not\n
 *             Example: UART_GET_INT(UART0)
 */
static __INLINE uint32_t  UART_GET_INT(UART_T *UART) 
{
    return ((UART)->IER); 
}
/**
 * @brief      Enable RX DMA function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to enable RX DMA function.\n
 *             Example: UART_ENABLE_DMA_RX(UART0)
 *
 */  
static __INLINE void UART_ENABLE_DMA_RX(UART_T *UART)
{     
    ((UART)->IER |= (UART_IER_DMA_RX_EN));
}

/**
 * @brief      Disable RX DMA function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to disable RX DMA function.\n
 *             Example: UART_DISABLE_DMA_RX(UART0)
 *
 */    
static __INLINE void  UART_DISABLE_DMA_RX(UART_T *UART)
{
    ((UART)->IER &= ~(UART_IER_DMA_RX_EN));
}
/**
 * @brief      Enable TX DMA function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to enable TX DMA function.\n
 *             Example: UART_ENABLE_DMA_TX(UART0)
 *
 */  
static __INLINE void UART_ENABLE_DMA_TX(UART_T *UART)     
{
    ((UART)->IER |= (UART_IER_DMA_TX_EN));
}

/**
 * @brief      Disable disable TX DMA function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to disable TX DMA function.\n
 *             Example: UART_DISABLE_DMA_TX(UART0)
 *
 */    
static __INLINE void UART_DISABLE_DMA_TX(UART_T *UART)
{
    ((UART)->IER &= ~(UART_IER_DMA_TX_EN));
}
/**
 * @brief      Enable RTS/CTS Auto Flow Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @param[in]  eFlowCtl     Flow Control Select
 *                          - UART_IER_AUTO_RTS_EN : RTS Auto Flow Control 		   
 *                          - UART_IER_AUTO_CTS_EN : CTS Auto Flow Control 
 * @return     None
 *                                                           
 * @details    The function is used to set AutoFlow Control RTS/CTS function.\n
 *             Example: UART_ENABLE_AUTOFLOW(UART0,UART_AUTO_RTS|UART_IER_AUTO_CTS_EN)
 *
 */  
static __INLINE void UART_ENABLE_AUTOFLOW(UART_T *UART,uint32_t eFlowCtl)
{
     ((UART)->IER |= (eFlowCtl));
}

/**
 * @brief      Disable RTS/CTS Auto Flow Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @param[in]  eFlowCtl     Flow Control Select
 *                          - UART_IER_AUTO_RTS_EN : RTS Auto Flow Control 
 *                          - UART_IER_AUTO_CTS_EN : CTS Auto Flow Control 
 * @return     None
 *                                                           
 * @details    The function is used to disable AutoFlow Control RTS/CTS function.\n
 *             Example: UART_DISABLE_AUTOFLOW(UART0,UART_AUTO_RTS|UART_IER_AUTO_CTS_EN)
 *
 */    
static __INLINE void UART_DISABLE_AUTOFLOW(UART_T *UART,uint32_t eFlowCtl)
{
    ((UART)->IER &= ~(eFlowCtl));
}
/**
 * @brief      Enable time out function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to enable time out function.\n
 *             Example: UART_ENABLE_TIME_OUT(UART0)
 *
 */  
static __INLINE void UART_ENABLE_TIME_OUT(UART_T *UART)    
{
    ((UART)->IER |= (UART_IER_TIMEOUT_COUNTER_EN));
}

/**
 * @brief      Disable time out function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to disable time out function.\n
 *             Example: UART_DISABLE_TIME_OUT(UART0)
 *
 */    
static __INLINE void UART_DISABLE_TIME_OUT(UART_T *UART)
{ 
    ((UART)->IER &= ~(UART_IER_TIMEOUT_COUNTER_EN));
}
/**
 * @brief      Enable wake up function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to enable wake up function.\n
 *             Example: UART_ENABLE_WAKE_UP(UART0)
 *
 */  
static __INLINE void UART_ENABLE_WAKE_UP(UART_T *UART)
{
     ((UART)->IER |= (UART_IER_WAKE_EN));
}
/**
 * @brief      Disable wake up function Control
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to disable wake up function.\n
 *             Example: UART_DISABLE_WAKE_UP(UART0)
 *
 */    
static __INLINE void UART_DISABLE_WAKE_UP(UART_T *UART)
{
    ((UART)->IER &= ~(UART_IER_WAKE_EN));
}

/**
 * @brief      Set RTS Trigger Level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @param[in]  eTRGLevel    RTS Trigger Level Select
 *                          - UART_FCR_RTS_TRI_LEV_1BYTE   : RTS Trigger Level is 1 byte 
 *                          - UART_FCR_RTS_TRI_LEV_4BYTES  : RTS Trigger Level is 4 bytes 
 *                          - UART_FCR_RTS_TRI_LEV_8BYTES  : RTS Trigger Level is 8 bytes 
 *                          - UART_FCR_RTS_TRI_LEV_14BYTES : RTS Trigger Level is 14 bytes
 *
 * @return     None                                                            
 *                                                           
 * @details    The function is used to set RTS trigger level 1,4,8,14 bytes. It is used to autoflow control.\n
 *             Example: UART_SET_RTS_TRGLEV(UART0,UART_RTS_TRG_LEV_1)
 *
 */  
static __INLINE void UART_SET_RTS_TRGLEV(UART_T *UART,uint32_t eTRG_Level)
{
   ((UART)->FCR = (((UART)->FCR & ~UART_FCR_RTS_TRI_LEV_Msk) | (eTRG_Level)));
}             
/**
 * @brief      Enable Rx receive function in RS485 mode
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to set Rx disable function.\n
 *             Example: UART_RS485_SET_RXDISABLE(UART0)
 *
 */                                                                                      
static __INLINE void UART_RS485_SET_RXDISABLE(UART_T *UART)
{
    ((UART)->FCR|= UART_FCR_RX_DIS);
}
/**
 * @brief      Disable Rx receive function in RS485 mode
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to Clear Rx disable function.\n
 *             Example: UART_RS485_CLEAR_RXDISABLE(UART0)
 *
 */                                                                                      
static __INLINE void UART_RS485_CLEAR_RXDISABLE(UART_T *UART)
{
    ((UART)->FCR&= ~UART_FCR_RX_DIS);
}
/**
 * @brief      Set Rx trigger level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  eLevel       Rx trigger level
 *                          - UART_FCR_RFITL_1BYTE   : RDA Trigger Level is 1 byte   
 *                          - UART_FCR_RFITL_4BYTES  : RDA Trigger Level is 4 byte  
 *                          - UART_FCR_RFITL_8BYTES  : RDA Trigger Level is 8 byte 
 *                          - UART_FCR_RFITL_14BYTES : RDA Trigger Level is 14 byte 
 * @return     None
 *                                                           
 * @details    The function is used to access FCR[7:4] to control rx trigger level.\n
 *             Example: UART_SET_RX_TRG_LEV(UART0, UART_RX_TRG_LEV_8)
 *
 * @note       Rx trigger level will effect RDA_IF and RDA_INT.
 */
static __INLINE void UART_SET_RX_TRG_LEV(UART_T *UART,uint32_t eLevel)
{
    ((UART)->FCR = ((UART)->FCR & ~UART_FCR_RFITL_Msk)| (eLevel));
}
/**
 * @brief      Reset TX/RX FIFO
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  uPara      Reset FIFO Select  (Uses "OR" to add your settings)
 *                          - UART_FCR_RST_TX_FIFO : TX FIFO 
 *                          - UART_FCR_RST_RX_FIFO : RX FIFO 
 * @return     None
 *
 * @details    The function is used to write FCR[2:1] to reset TX or RX FIFO.\n
 *             Example: UART_RESET_FIFO(UART0,UART_FCR_RST_TX_FIFO|UART_FCR_RST_TX_FIFO)
 *
 * @note       After user call the function, data in tx or rx fifo in specified UART port will be cleared.
 */

static __INLINE void UART_RESET_FIFO(UART_T *UART,uint32_t uPara)
{
    ((UART)->FCR |= (uPara));
}
/**
 * @brief      Set break control bit
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to set BCB bit and force TXD pin to low state.\n
 *             Example: UART_FORCE_BREAK(UART0)
 *
 */ 
static __INLINE void UART_FORCE_BREAK(UART_T *UART)
{
    ((UART)->LCR |= UART_LCR_BCB);
}
/**
 * @brief      Clear break control bit
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to clear BCB bit and force TXD pin return normal state.\n
 *             Example: UART_CLEAR_BREAK(UART0)
 *
 */ 
static __INLINE void UART_CLEAR_BREAK(UART_T *UART)      
{
     ((UART)->LCR &= ~UART_LCR_BCB);
}
/**
 * @brief      Set UART line control 
 *
 * @param[in]  UART         Structure pointer of UART Channel selected,should be:  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  u32PortSettings  Line control value: Use "|" to combine your settings
 *                          - Word Length Select : eg. UART_WORD_LEN_5
 * 													   UART_WORD_LEN_6
 *													   UART_WORD_LEN_7
 *													   UART_WORD_LEN_8
 *                          - Parity Bit         : eg. UART_PARITY_NONE
 *													   UART_PARITY_ODD
 *													   UART_PARITY_EVEN
 *                          - Stop Bit           : eg. UART_STOPBIT_1
 *													   UART_STOP_BIT_1_5
 *													   UART_STOPBIT_2
 * @return     None
 *
 * @details    The function is used to set UART data format (Word Length Select /Parity Bit/Stop Bit).\n
 *             Example: UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_5 | UART_PARITY_NONE | UART_STOPBIT_1)
 */
static __INLINE void UART_SET_DATA_FORMAT(UART_T *UART, uint32_t u32PortSettings)
{
    ((UART)->LCR = ((UART)->LCR&0x40)|(u32PortSettings));
}
/**
 * @brief      Get RTS Pin value
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @retval     !0 = RTS pin value is HIGH
 * @retval     0 = RTS pin value is LOW
 *                                                           
 * @details    The function is used to get RTS pin value.
 *             Example: UART_GET_RTSPIN(UART0)
 *
 */
static __INLINE uint32_t UART_GET_RTSPIN(UART_T *UART)
{
    return (((UART)->MCR & UART_MCR_RTS_ST_Msk));
}
/**
 * @brief      Set RTS Trigger Level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @return     None                                                            
 *                                                           
 * @details    High level triggered\n
 *             Example: UART_RTS_ACTIVE_LEV_HIGH(UART0)
 *
 * @details    RTS is high level active. 
 */  
static __INLINE void UART_RTS_ACTIVE_LEV_HIGH(UART_T *UART)
{
    ((UART)->MCR = ((UART)->MCR | UART_MCR_LEV_RTS_HIGH));
}
/**
 * @brief      Set RTS Trigger Level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @return     None                                                            
 *                                                           
 * @details    Low level triggered\n
 *             Example: UART_RTS_ACTIVE_LEV_LOW(UART0)
 *
 * @details    RTS is low level active. 
 */  
static __INLINE void  UART_RTS_ACTIVE_LEV_LOW(UART_T *UART)
{ 
    ((UART)->MCR = ((UART)->MCR & (~UART_MCR_LEV_RTS_HIGH)));
}
/**
 * @brief      Get LEV_RTS bit settings
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @retval     !0 = LEV_RTS bit is set
 * @retval     0 = LEV_RTS bit is clear
 *                                                           
 * @details    The function is used to get LEV_RTS bit settings.
 *             Example: UART_GET_LEVRTS(UART0)
 *
 */
static __INLINE uint32_t UART_GET_LEVRTS(UART_T *UART)
{
   return (((UART)->MCR & UART_MCR_LEV_RTS_Msk));
}
/**
 * @brief      Set RTS pin output
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    Drive RTS pin to logic 0 (If the LEV_RTS set to low level triggered)\n
 *             Drive RTS pin to logic 1 (If the LEV_RTS set to high level triggered)\n 
 *             Example: UART_SET_RTS(UART0)
 *
 */ 
static __INLINE void UART_SET_RTS(UART_T *UART)      
{
     ((UART)->MCR |= UART_MCR_RTS);
}
/**
 * @brief      Clear RTS pin output
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    Drive RTS pin to logic 0 (If the LEV_RTS set to high level triggered)\n
 *             Drive RTS pin to logic 1 (If the LEV_RTS set to low level triggered)\n
 *             Example: UART_CLEAR_RTS(UART0)
 *
 */ 
static __INLINE void UART_CLEAR_RTS(UART_T *UART)      
{
     ((UART)->MCR &= ~UART_MCR_RTS);
}
/**
 * @brief      Set CTS Trigger Level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @return     None                                                            
 *                                                           
 * @details    High level triggered\n
 *             Example: UART_CTS_ACTIVE_LEV_HIGH(UART0)
 *
 */  
static __INLINE void UART_CTS_ACTIVE_LEV_HIGH(UART_T *UART)  
{
    ((UART)->MSR |=  UART_MSR_LEV_CTS_HIGH);
}
/**
 * @brief      Set CTS Trigger Level
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @return     None                                                            
 *                                                           
 * @details    Low level triggered\n
 *             Example: UART_CTS_ACTIVE_LEV_LOW(UART0)
 * 
 */  
static __INLINE void UART_CTS_ACTIVE_LEV_LOW(UART_T *UART)
{
    ((UART)->MSR &= (~UART_MSR_LEV_CTS_HIGH));
}
/**
 * @brief      Get CTS Pin value
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @retval     !0 = CTS pin value is HIGH
 * @retval     0 = CTS pin value is LOW
 *                                                           
 * @details    The function is used to get CTS pin value.
 *             Example: UART_GET_CTSPIN(UART0)
 *
 */
static __INLINE uint32_t UART_GET_CTSPIN(UART_T *UART)
{
    return (((UART)->MSR & UART_MSR_CTS_ST_Msk));
}
/**
 * @brief      Detect CTS State Change Flag
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @retval     !0 = CTS input has change state
 * @retval     0 = CTS input not change state
 *                                                           
 * @details    The function is used to get DCTSF value.
 *             Example: UART_GET_DCTSF(UART0)
 *
 */
static __INLINE uint32_t UART_GET_DCTSF(UART_T *UART)
{
    return (((UART)->MSR & UART_MSR_DCTSF_Msk));
}
 /**
 * @brief      Clear Modem interrupt flag
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *                                                           
 * @details    The function is used to access DCTSF to clear Modem interrupt flag.\n
 *             Example: UART_CLEAR_MODEM_INT_FLAG(UART0)
 *
 */  
static __INLINE void UART_CLEAR_MODEM_INT_FLAG(UART_T *UART)
{
   ((UART)->MSR |= UART_MSR_DCTSF);
}
/**
 * @brief      Check specified uart Tx FIFO is Empty. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = The transmission is not over. 
 * @retval     !0 = The transmission is over. 
 *
 * @details    The function is used to read FSR[28] to check the TX_FIFO and TX_Shift_Reigster is empty.\n
 *             Example: UART_GET_TE_FLAG(UART0)
 */
static __INLINE uint32_t UART_GET_TE_FLAG(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_TE_FLAG_Msk)); 
}
/**
 * @brief      Check specified TX FIFO is over. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = TX FIFO  is not over. 
 * @retval     !0 = TX FIFO is over. 
 *
 * @details    The function is used to check TX FIFO is over.\n
 *             Example: UART_GET_TX_OVER_IF(UART0)
 */
static __INLINE uint32_t  UART_GET_TX_OVER_IF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_TX_OVER_IF_Msk)); 
}
/**
 * @brief      Clear buffur error interrupt flag
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *                                                           
 * @details    The function is used to access RX_OVER_IF and TX_OVER_IF to clear buffur error interrupt flag.\n
 *             Example: UART_CLEAR_BUFERR_ERROR_INT_FLAG(UART0)
 *
 */
static __INLINE uint32_t UART_CLEAR_BUFERR_ERROR_INT_FLAG(UART_T *UART)
{
    return ((UART)->FSR |= UART_FSR_RX_OVER_IF_Msk | UART_FSR_TX_OVER_IF_Msk);
}
/**
 * @brief      Check TX FIFO is full or not 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @retval     !0 = TX FIFO is full
 * @retval     0 = TX FIFO is not full
 *
 * @details    The function is used to read FSR[23] to check tx fifo is full or not.
 *             If writing data to tx fifo when it is full,buffer error will happen.
 *             Example: UART_GET_TX_FULL(UART0)
 */
static __INLINE uint32_t UART_GET_TX_FULL(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_TX_FULL_Msk)); 
}
/**
 * @brief      Check TX FIFO is empty or not. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = TX FIFO is not empty. 
 * @retval     !0 = TX FIFO is empty. 
 *
 * @details    This bit indicates TX FIFO empty or not.\n
 *             Example: UART_GET_TX_EMPTY(UART0)
 */
static __INLINE uint32_t UART_GET_TX_EMPTY(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_TX_EMPTY_Msk)); 
}
/**
 * @brief      Check there is un-transmited data in TX FIFO
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @retval     The number of N data bytes in TX FIFO.
 *
 * @details    The function is used to read FSR[21:16] TX FIFO POINTER to check 
 *             there is un-transmited data int TX_FIFO.\n
 *             Example: UART_GET_TX_POINTER(UART0)
 */
static __INLINE uint32_t UART_GET_TX_POINTER(UART_T *UART)
{ 
    return (((UART)->FSR & UART_FSR_TX_POINTER_Msk) >> UART_FSR_TX_POINTER_Pos);
}
/**
 * @brief      Check RX FIFO is full or not 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @retval     !0 = RX FIFO is full
 * @retval     0 = RX FIFO is not full
 *
 * @details    The function is used to read FSR[15] to check rx fifo is full or not.
 *             If receving a new data to rx fifo when it is full,buffer error will happen.
 *             Example: UART_GET_RX_FULL(UART0)
 */

static __INLINE uint32_t UART_GET_RX_FULL(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_RX_FULL_Msk));
}
/**
 * @brief      This bit indicates RX FIFO empty or not. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = RX FIFO is not empty. 
 * @retval     !0 = RX FIFO is empty. 
 *
 * @details    This bit indicates RX FIFO empty or not.\n
 *             Example: UART_GET_RX_EMPTY(UART0)
 */
static __INLINE uint32_t UART_GET_RX_EMPTY(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_RX_EMPTY_Msk)); 
}
/**
 * @brief      Check there is un-read data in RX FIFO
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 *
 * @retval     The number of N data bytes in RX FIFO.
 *
 * @details    The function is used to read FSR[13:8] RX FIFO POINTER to check 
 *             there is un-read data int RX_FIFO.\n
 *             Example: UART_GET_RX_POINTER(UART0)
 */
static __INLINE uint32_t UART_GET_RX_POINTER(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_RX_POINTER_Msk) >> UART_FSR_RX_POINTER_Pos);
}
/**
 * @brief      Check break interrupt happen or not. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = Break interrupt not happen. 
 * @retval     !0 = Break interrupt happen. 
 *
 * @details    Check break interrupt happen or not.\n
 *             Example: UART_GET_BREAK_IF(UART0)
 */
static __INLINE uint32_t UART_GET_BREAK_IF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_BIF_Msk));
}
/**
 * @brief      Clear break interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *
 * @details    Clear break interrupt flag.\n
 *             Example: UART_CLEAR_BREAK_IF(UART0)
 */
static __INLINE uint32_t UART_CLEAR_BREAK_IF(UART_T *UART)
{
    return ((UART)->FSR|=UART_FSR_BIF);
}
/**
 * @brief      Framing Error Flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = Framing Error not happen. 
 * @retval     !0 = Framing Error happen. 
 *
 * @details    Check Framing Error happen or not.\n
 *             Example: UART_GET_FRAME_EF(UART0)
 */
static __INLINE uint32_t UART_GET_FRAME_EF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_FEF_Msk));
}
/**
 * @brief      Clear frame error flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *
 * @details    It is used to clear frame error flag.\n
 *             Example: UART_CLEAR_FRAME_EF(UART0)
 */
static __INLINE uint32_t UART_CLEAR_FRAME_EF(UART_T *UART)
{
    return ((UART)->FSR|=UART_FSR_FEF);
}
/**
 * @brief      Parity Error Flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = Parity Error not happen. 
 * @retval     !0 = Parity Error happen. 
 *
 * @details    Check Parity Error happen or not.\n
 *             Example: UART_GET_PARITY_EF(UART0)
 */
static __INLINE uint32_t UART_GET_PARITY_EF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_PEF_Msk));
}
/**
 * @brief      Clear parity error flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *
 * @details    It is used to clear parity error flag.\n
 *             Example: UART_CLEAR_PARITY_EF(UART0)
 */
static __INLINE uint32_t UART_CLEAR_PARITY_EF(UART_T *UART)
{
    return ((UART)->FSR|=UART_FSR_PEF);
}
/**
 * @brief      Get Receive Line Status flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = RLS flags are set. 
 * @retval     !0 = RLS flags are set. 
 *
 * @details    Get Receive Line Status flag. include Break Error Flag, Parity Error Flag and Frame Error Flag\n
 *             Example: UART_GET_RLS_FLAG(UART0)
 */
static __INLINE uint32_t UART_GET_RLS_FLAG(UART_T *UART)
{
    return (((UART)->FSR & (UART_FSR_BIF|UART_FSR_PEF|UART_FSR_FEF)));
}
/**
 * @brief      Clear Receive Line Status flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @return     None
 *
 * @details    Clear Receive Line Status flag. include Break Error Flag, Parity Error Flag and Frame Error Flag\n
 *             Example: UART_CLEAR_RLS_FLAG(UART0)
 */
static __INLINE uint32_t UART_CLEAR_RLS_FLAG(UART_T *UART)
{
    return (((UART)->FSR |= (UART_FSR_BIF|UART_FSR_PEF|UART_FSR_FEF)));
}
/**
 * @brief      Get RS-485 Address Byte Detection Flag
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @retval     0 = Receiver not detect any address byte.
 * @retval     !0 = Receiver detect any address byte. 
 *                                                           
 * @details    The function is used to get RS-485 Address Byte Detection Flag
 *             Example: UART_RS485_GET_ADD_DETF(UART0)
 *
 */                                                                                      
static __INLINE uint32_t UART_RS485_GET_ADD_DETF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_RS485_ADD_DETF_Msk));
}
/**
 * @brief      Clear RS-485 Address Byte Detection Flag
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @return     None
 *                                                           
 * @details    The function is used to write RS485_ADD_DETF_Msk bit is '1' to this bit
 *             Example: UART_RS485_CLEAR_ADD_DETF(UART0)
 *
 */                                                                                      
static __INLINE uint32_t UART_RS485_CLEAR_ADD_DETF(UART_T *UART)
{
    return ((UART)->FSR  |= UART_FSR_RS485_ADD_DETF_Msk);
}
/**
 * @brief      Check specified RX FIFO is over. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = RX FIFO  is not over. 
 * @retval     !0 = RX FIFO is over. 
 *
 * @details    The function is used to check RX FIFO is over.\n
 *             Example: UART_GET_RX_OVER_IF(UART0)
 */
static __INLINE uint32_t UART_GET_RX_OVER_IF(UART_T *UART)
{
    return (((UART)->FSR & UART_FSR_RX_OVER_IF_Msk)); 
}
/**
 * @brief      In DMA Mode, Buffer Error Interrupt Indicator . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = No buffer error interrupt is generated in DMA mode
 * @retval     !0 = Buffer error interrupt is generated in DMA mode. 
 *
 * @details    In DMA Mode, Buffer Error Interrupt Indicator\n
 *             Example: UART_GET_HW_BUF_ERR_INT(UART0)
 */
static __INLINE uint32_t UART_GET_HW_BUF_ERR_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_BUF_ERR_INT_Msk)); 
}
/**
 * @brief      In DMA Mode, Time Out Interrupt Indicator . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = No time out interrupt is generated in DMA mode
 * @retval     !0 = Time out interrupt is generated in DMA mode. 
 *
 * @details    In DMA Mode, Time Out Interrupt Indicator\n
 *             Example: UART_GET_HW_TOUT_INT(UART0)
 */
static __INLINE uint32_t UART_GET_HW_TOUT_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_TOUT_INT_Msk)); 
}
/**
 * @brief      In DMA Mode, MODEM Status Interrupt Indicator  . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = No Modem interrupt is generated in DMA mode
 * @retval     !0 = Modem interrupt is generated in DMA mode.. 
 *
 * @details    In DMA Mode, MODEM Status Interrupt Indicator \n
 *             Example: UART_GET_HW_MODEM_INT(UART0)
 */
static __INLINE uint32_t UART_GET_HW_MODEM_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_MODEM_INT_Msk)); 
}
/**
 * @brief      In DMA Mode, Receive Line Status Interrupt Indicator  . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = No RLS interrupt is generated in DMA mode
 * @retval     !0 = RLS interrupt is generated in DMA mode. 
 *
 * @details    In DMA Mode, Receive Line Status Interrupt Indicator \n
 *             Example: UART_GET_HW_RLS_INT(UART0)
 */
static __INLINE uint32_t UART_GET_HW_RLS_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_RLS_INT_Msk)) ;
}
/**
 * @brief      In DMA Mode, Buffer Error Interrupt Flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 = No TX or RX FIFO overflows
 * @retval     !0 =  TX or RX FIFO overflows . 
 *
 * @details    In DMA Mode, Buffer Error Interrupt Flag.\n
 *             Example: UART_GET_HW_BUF_ERR_IF(UART0)
 */
static __INLINE uint32_t UART_GET_HW_BUF_ERR_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_BUF_ERR_IF_Msk)); 
}
/**
 * @brief      In DMA Mode, Time Out Interrupt Flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  In DMA Mode,No time out happen
 * @retval     !0 =  In DMA Mode,Time out happen . 
 *
 * @details    In DMA Mode, Time Out Interrupt Flag.\n
 *             Example: UART_GET_HW_TOUT_IF(UART0)
 */
static __INLINE uint32_t UART_GET_HW_TOUT_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_TOUT_IF_Msk)); 
}
/**
 * @brief      In DMA Mode, MODEM Interrupt Flag . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  CTS pin state not change
 * @retval     !0 =  CTS pin has state change . 
 *
 * @details    In DMA Mode, MODEM Interrupt Flag .\n
 *             Example: UART_GET_HW_MODEM_IF(UART0)
 */
static __INLINE uint32_t UART_GET_HW_MODEM_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_MODEM_IF_Msk)); 
}
/**
 * @brief      In DMA Mode, Receive Line Status Flag . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No error
 * @retval     !0 =  RX receive data have parity error, framing error or break error . 
 *
 * @details    In DMA Mode, Receive Line Status Flag .\n
 *             Example: UART_GET_HW_RLS_IF(UART0)
 */
static __INLINE uint32_t UART_GET_HW_RLS_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_HW_RLS_IF_Msk));
}
/**
 * @brief      Buffer Error Interrupt Indicator . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No buffer error interrupt is generated
 * @retval     !0 =  Buffer error interrupt is generated . 
 *
 * @details    Buffer Error Interrupt Indicator .\n
 *             Example: UART_GET_BUF_ERR_INT(UART0)
 */
static __INLINE uint32_t UART_GET_BUF_ERR_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_BUF_ERR_INT_Msk));
}
/**
 * @brief      Time Out Interrupt Indicator. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No time out interrupt is generated
 * @retval     !0 =  Time out interrupt is generated . 
 *
 * @details    Time Out Interrupt Indicator.\n
 *             Example: UART_GET_TOUT_INT(UART0)
 */
static __INLINE uint32_t UART_GET_TOUT_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_TOUT_INT_Msk));
}
/**
 * @brief      MODEM Status Interrupt Indicator. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No Modem interrupt is generated
 * @retval     !0 = Modem interrupt is generated . 
 *
 * @details    MODEM Status Interrupt Indicator.\n
 *             Example: UART_GET_MODEM_INT(UART0)
 */
static __INLINE uint32_t UART_GET_MODEM_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_MODEM_INT_Msk));
}
/**
 * @brief      Receive Line Status Interrupt Indicator. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No RLS interrupt is generated
 * @retval     !0 =  RLS interrupt is generated. 
 *
 * @details    Receive Line Status Interrupt Indicator.\n
 *             Example: UART_GET_RLS_INT(UART0)
 */
static __INLINE uint32_t UART_GET_RLS_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_RLS_INT_Msk));
}
/**
 * @brief      Transmit Holding Register Empty Interrupt Indicator. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No THRE interrupt is generated
 * @retval     !0 =  THRE interrupt is generated. 
 *
 * @details    Transmit Holding Register Empty Interrupt Indicator.\n
 *             Example: UART_GET_THRE_INT(UART0)
 */
static __INLINE uint32_t UART_GET_THRE_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_THRE_INT_Msk));
}
/**
 * @brief      Receive Data Available Interrupt Indicator. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No RDA interrupt is generated
 * @retval     !0 =  RDA interrupt is generated. 
 *
 * @details    Receive Data Available Interrupt Indicator.\n
 *             Example: UART_GET_RDA_INT(UART0)
 */
static __INLINE uint32_t UART_GET_RDA_INT(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_RDA_INT_Msk));
}
/**
 * @brief      Buffer Error Interrupt flag . 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  TX or RX FIFO not overflows
 * @retval     !0 =  TX or RX FIFO overflows . 
 *
 * @details    Buffer Error Interrupt flag .\n
 *             Example: UART_GET_BUF_ERR_IF(UART0)
 */
static __INLINE uint32_t UART_GET_BUF_ERR_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_BUF_ERR_IF_Msk));
}
/**
 * @brief      Time Out Interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No Time Out is generated
 * @retval     !0 =  Time Out is generated . 
 *
 * @details    Time Out Interrupt flag.\n
 *             Example: UART_GET_TOUT_IF(UART0)
 */
static __INLINE uint32_t UART_GET_TOUT_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_TOUT_IF_Msk));
}
/**
 * @brief      MODEM Status Interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  CTS pin has state not change 
 * @retval     !0 = CTS pin has state change  . 
 *
 * @details    MODEM Status Interrupt flag.\n
 *             Example: UART_GET_MODEM_IF(UART0)
 */
static __INLINE uint32_t UART_GET_MODEM_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_MODEM_IF_Msk));
}
/**
 * @brief      Receive Line Status Interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  No error
 * @retval     !0 =  RX receive data have parity error, framing error or break error. 
 *
 * @details    Receive Line Status Interrupt flag.\n
 *             Example: UART_GET_RLS_IF(UART0)
 */
static __INLINE uint32_t UART_GET_RLS_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_RLS_IF_Msk));
}
/**
 * @brief      Transmit Holding Register Empty Interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  TX FIFO is not empty
 * @retval     !0 =  The last data of TX FIFO is transferred to Transmitter Shift Register. 
 *
 * @details    Transmit Holding Register Empty Interrupt flag.\n
 *             Example: UART_GET_THRE_IF(UART0)
 */
static __INLINE uint32_t UART_GET_THRE_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_THRE_IF_Msk));
}
/**
 * @brief      Receive Data Available Interrupt flag. 
 *
 * @param[in]  UART         Structure pointer of UART Channel  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @retval     0 =  RX FIFO is not equal to the RFITL
 * @retval     !0 =  RX FIFO is equal to the RFITL. 
 *
 * @details    Receive Data Available Interrupt flag.\n
 *             Example: UART_GET_RDA_IF(UART0)
 */
static __INLINE uint32_t UART_GET_RDA_IF(UART_T *UART)
{
    return (((UART)->ISR & UART_ISR_RDA_IF_Msk));
}
/**
 * @brief      Set UART transmit delay time 
 *
 * @param[in]  UART         Structure pointer of UART Channel selected,should be:  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  delay
 *                                                                
 * @return     None
 *
 * @details     transfer delay time between the last stop bit and next start bit. \n
 *             Example: UART_SET_TX_DELAY(UART0, 10)
 */

static __INLINE void UART_SET_TX_DELAY(UART_T *UART, uint8_t delay)
{
    ((UART)->TOR = ((UART)->TOR &~UART_TOR_DLY_Msk)|(delay<<UART_TOR_DLY_Pos)); 
}
/**
 * @brief      Set UART RX Time Out Interrupt comparator 
 *
 * @param[in]  UART         Structure pointer of UART Channel selected,should be:  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1 
 * @param[in]  timeout     MAX = 0xFF
 *                                                                
 * @return     None
 *
 * @details    Time Out unit is baudrate  \n
 *             Example: UART_SET_RX_TIMEOUT(UART0, 10)
 */

static __INLINE void UART_SET_RX_TIMEOUT(UART_T *UART, uint8_t timeout)
{
    ((UART)->TOR = ((UART)->TOR &~UART_TOR_TOIC_Msk)|(timeout));  
}
/**
 * @brief      Compute Baud Rate Divider Settings by mode 0
 *
 * @param[in]  UART         Structure pointer of UART Channel selected,should be:  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 *
 * @param[in]  u32SrcFreq      UART clock source(UART_S) divides by UART divider(UART_N)
 * @param[in]  u32BaudRate     Target bitrate (Hz)
 *    
 * @return     None
 *    
 * @details    The function is used to get baud-rate divider settings by mode 0  based on your settings.\n
 *    
 *             Example: UART clock source from PLL(48MHz) and UART clock divider is set 2.\n 
 *                      If desired baudrate is 115200, you can call UART_SET_BAUD_MODE0(UART0,24000000,115200);
 *                           
 */
static __INLINE void UART_SET_BAUD_MODE0(UART_T *UART, uint32_t u32SrcFreq, uint32_t u32BaudRate)
{
    ((UART)->BAUD = (((u32SrcFreq / u32BaudRate) >> 4)-2));
}
/**
 * @brief      Compute Baud Rate Divider Settings by mode 2
 *
 * @param[in]  UART         Structure pointer of UART Channel selected,should be:  
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 *
 * @param[in]  u32SrcFreq      UART clock source(UART_S) was divided by UART divider(UART_N)
 * @param[in]  u32BaudRate     Target bitrate (Hz)
 *    
 * @return     None
 *    
 * @details    The function is used to get baud rate divider settings by mode 2 based on your settings.\n
 *    
 *             Example: UART clock source from PLL(48MHz) and UART clock divider is set 2.\n 
 *                      If desired baudrate is 115200, you can call UART_SET_BAUD_MODE2(UART0,24000000,115200);
 *                           
 */
static __INLINE void UART_SET_BAUD_MODE2(UART_T *UART, uint32_t u32SrcFreq,uint32_t u32BaudRate)
{
    ((UART)->BAUD = (UART_BAUD_MODE2 | ((u32SrcFreq  / u32BaudRate)-2)));
}
/**
 * @brief      Initialize IrDA RX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA RX. It wll switch IrDA mode and 
 *             configure invert rx signal or nor.\n                                              
 *             Example: UART_SET_IRDA_INV_RX(UART0)
 *
 */  
static __INLINE void UART_SET_IRDA_INV_RX(UART_T *UART)
{
    ((UART)->IRCR |= UART_IRCR_INV_RX);
}
/**
 * @brief      Initialize IrDA RX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA RX. It wll switch IrDA mode and 
 *             configure invert rx signal or nor.\n                                              
 *             Example: UART_SET_IRDA_NOINV_RX(UART0)
 *
 */  
static __INLINE void UART_SET_IRDA_NOINV_RX(UART_T *UART)
{
    ((UART)->IRCR &= ~UART_IRCR_INV_RX);
}
/**
 * @brief      Initialize IrDA TX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA TX. It wll switch IrDA mode and 
 *             configure invert tx signal or nor.\n                                              
 *             Example: UART_SET_IRDA_INV_TX(UART0)
 *
 */  
static __INLINE void UART_SET_IRDA_INV_TX(UART_T *UART)
{
    ((UART)->IRCR |= UART_IRCR_INV_TX);
}
/**
 * @brief      Initialize IrDA TX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA TX. It wll switch IrDA mode and 
 *             configure invert tx signal or nor.\n                                              
 *             Example: UART_SET_IRDA_NOINV_TX(UART0)
 *
 */  
static __INLINE void UART_SET_IRDA_NOINV_TX(UART_T *UART)
{
    ((UART)->IRCR &= ~UART_IRCR_INV_TX);
}
/**
 * @brief      Initialize IrDA TX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA TX. It wll enable IrDA transmitter .\n                                              
 *             Example: UART_IRDA_ENABLE_TX(UART0)
 *
 */  
static __INLINE void UART_IRDA_ENABLE_TX(UART_T *UART)
{
    ((UART)->IRCR |= UART_IRCR_TX_SELECT);
}
/**
 * @brief      Initialize IrDA RX configuration
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    The function is used to intialize IrDA TX. It wll enable IrDA receiver .\n                                              
 *             Example: UART_IRDA_ENABLE_RX(UART0)
 *
 */  
static __INLINE void UART_IRDA_ENABLE_RX(UART_T *UART)
{
    ((UART)->IRCR &= ~UART_IRCR_TX_SELECT);
}
/**
 * @brief      Set RS485 address  
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Set RS485 address  .\n                                              
 *             Example: UART_SET_RS485_ADDRESS(UART0,0xC0)
 *
 */  
static __INLINE void UART_SET_RS485_ADDRESS(UART_T *UART,uint8_t address)
{
    ((UART)->ALT_CSR = ((UART)->ALT_CSR&(~UART_ALT_CSR_ADDR_MATCH_Msk)) |(address<<UART_ALT_CSR_ADDR_MATCH_Pos));
}
/**
 * @brief      Enable address detection mode 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Enable address detection mode .\n                                              
 *             Example: UART_RS485_ADD_ENABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_ADD_ENABLE(UART_T *UART)
{
    ((UART)->ALT_CSR |= UART_RS485_ADD_EN);
}
/**
 * @brief      Disable address detection mode 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Disable address detection mode .\n                                              
 *             Example: UART_RS485_ADD_DISABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_ADD_DISABLE(UART_T *UART)
{
    ((UART)->ALT_CSR &= ~UART_RS485_ADD_EN);
}
/**
 * @brief      Enable RS-485 Auto Direction Operation mode (AUD) 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Enable RS-485 Auto Direction Operation mode (AUD)  .\n                                              
 *             Example: UART_RS485_AUD_ENABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_AUD_ENABLE(UART_T *UART)
{
    ((UART)->ALT_CSR |= UART_RS485_AUD);
}
/**
 * @brief      Disable RS-485 Auto Direction Operation mode (AUD)
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Disable RS-485 Auto Direction Operation mode (AUD).\n                                              
 *             Example: UART_RS485_AUD_DISABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_AUD_DISABLE(UART_T *UART)
{
    ((UART)->ALT_CSR &= ~UART_RS485_AUD);
}

/**
 * @brief      Enable RS-485 Auto Address Detection Operation mode (AAD)  
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Enable RS-485 Auto Address Detection Operation mode (AAD) .\n                                              
 *             Example: UART_RS485_AAD_ENABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_AAD_ENABLE(UART_T *UART)
{
    ((UART)->ALT_CSR |= UART_RS485_AAD);
}
/**
 * @brief      Disable RS-485 Auto Address Detection Operation mode (AAD) 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Disable RS-485 Auto Address Detection Operation mode (AAD) .\n                                              
 *             Example: UART_RS485_AAD_DISABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_AAD_DISABLE(UART_T *UART)
{
    ((UART)->ALT_CSR &= ~UART_RS485_AAD);
}
/**
 * @brief      Enable RS-485 Normal Multi-drop Operation mode (NMM) 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Enable RS-485 Normal Multi-drop Operation mode (NMM) .\n                                              
 *             Example: UART_RS485_NMM_ENABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_NMM_ENABLE(UART_T *UART)
{
    ((UART)->ALT_CSR |= UART_RS485_NMM);
}
/**
 * @brief      Disable RS-485 Normal Multi-drop Operation mode (NMM) 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1  
 *
 * @return     None
 *                                                           
 * @details    Disable RS-485 Normal Multi-drop Operation mode (NMM) .\n                                              
 *             Example: UART_RS485_NMM_DISABLE(UART0)
 *
 */  
static __INLINE void UART_RS485_NMM_DISABLE(UART_T *UART)
{
    ((UART)->ALT_CSR &= ~UART_RS485_NMM);
}
/**
 * @brief      Switch Function 
 *
 * @param[in]  UART         Structure pointer of UART Channel
 *                          - UART0 : UART Channel 0
 *                          - UART1 : UART Channel 1
 * @param[in]  eFuncSel     Function Select  
 *                          - UART_FUNC_SEL_UART : UART function 
 *                          - UART_FUNC_SEL_IrDA : IrDA function
 *                          - UART_FUNC_SEL_RS485: RS485 function 
                                    
.* @return     None
 * @details    The function is used to uart function to Uart,IrDA,RS485.\n
 *             Example: UART_SEL_FUNC(UART0,UART_FUNC_SEL_RS485)
 *
 */  
static __INLINE void UART_SEL_FUNC(UART_T *UART,uint8_t eFuncSel)
{
    ((UART)->FUN_SEL = ((UART)->FUN_SEL & ~UART_FUN_SEL_FUN_SEL_Msk) | (eFuncSel));
}


typedef struct DRVUART_STRUCT
{
	uint32_t	u32ClkSrc;			/*!<  UART clock source,it could be:CLK_UART_HXT/CLK_UART_PLL/CLK_UART_HIRC    */
	uint32_t	u32ClkDiv;			/*!<  UART clock divider,it could be:1~16   */
	uint32_t	u32ClkFreq;			/*!<  UART clock frequency,it could be u32ClkSrc/u32ClkDiv */
    uint32_t	u32BaudRate;		/*!<  UART baudrate */
    uint32_t	u32cDataBits;		/*!<  UART bit number, it could be:UART_WORD_LEN_5/UART_WORD_LEN_6/UART_WORD_LEN_7/UART_WORD_LEN_8 */
    uint32_t	u32cStopBits;		/*!<  UART stop bit number, it could be:UART_STOPBIT_1/UART_STOP_BIT_1_5/UART_STOPBIT_2 */
    uint32_t	u32cParity;			/*!<  UART parity setting, it could be:UART_PARITY_NONE/UART_PARITY_ODD/UART_PARITY_EVEN */
    uint32_t	u32cRxTriggerLevel;	/*!<  UART RX FIFO trigger level, it could be:UART_FCR_RFITL_1BYTE/UART_FCR_RFITL_4BYTES/UART_FCR_RFITL_8BYTES/UART_FCR_RFITL_14BYTES */
    uint32_t	u32BaudMode;		/*!<  Set UART baud rate Fomula, it could be:UART_BAUD_MODE0/UART_BAUD_MODE2 */  
    uint8_t		u8RxTimeOut ;		/*!<  Set UART RX FIFO timeout, unit is baudrate, MAX=0xFF */                  
}STR_UART_T;                                                                      

typedef struct DRVUART_FLOWCTRL
{
	uint32_t	u32RTSTriLevel;		/*!<  Set RTS trigger level    */
	uint32_t	u32RTSActiveLevel;  /*!<  Set RTS Active level   */
	uint32_t	u32CTSActiveLevel;	/*!<  Set CTS Active level */
}STR_UART_FLOWCTRL_T;

/*---------------------------------------------------------------------------------------------------------*/
/*  Define IRDA data structure                                                                             */
/*---------------------------------------------------------------------------------------------------------*/

typedef struct IRCR_STRUCT
{
    uint8_t		u8cTXSelect;	/*!<  Enable IrDA TX/RX mode  */
    uint8_t		u8cInvTX;		/*!<  Set Irda TX inverter    */
    uint8_t	    u8cInvRX;	    /*!<  Set Irda Rx inverter    */
}STR_IRCR_T;

/*---------------------------------------------------------------------------------------------------------*/
/*  Define RS485 Setting structure                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

typedef struct RS485_STRUCT
{
    uint32_t	u8cModeSelect;	/*!<  Select operation mode  */
    uint8_t		u8cAddrEnable;	/*!<  Enable RS-485 Address Detection  */
    uint8_t	    u8cAddrValue;	/*!<  Set RS485 Address   */
    uint8_t	    u8cDelayTime;	/*!<  Set RS485 Tx delay  */
    uint8_t	    u8cRxDisable;	/*!<  Disable RS485 RX function  */
}STR_RS485_T;

/*@}*/ /* end of group UART_MACRO_FUNC */
/*@}*/ /* end of group UART_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void DrvUART_DriveRTS(UART_T  *tUART, uint8_t u8Value);
int32_t DrvUART_Init(UART_T  *tUART, STR_UART_T *sParam);
void DrvUART_EnableFlowCtrl(UART_T  *tUART, STR_UART_FLOWCTRL_T *sParam);
void DrvUART_DisableFlowCtrl(UART_T  *tUART);
void DrvUART_DeInit(UART_T  *tUART);
void DrvUART_EnableInt(UART_T  *tUART, uint32_t  u32InterruptFlag);
void DrvUART_DisableInt(UART_T  *tUART, uint32_t u32InterruptFlag);
void DrvUART_GetCTSInfo(UART_T  *tUART, uint8_t *pu8CTSValue, uint8_t	*pu8CTSChangeState);
void DrvUART_SetFnIRDA(UART_T  *tUART, STR_IRCR_T *str_IRCR );
void DrvUART_SetFnRS485(UART_T  *tUART, STR_RS485_T *str_RS485);

#endif











