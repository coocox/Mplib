/******************************************************************************
 * @file     nano1xx_uart.c
 * @brief    NANO1xx UART driver source file
 *           
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NUC123Series.h"
#include "UART.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvUART_FUNC UART Driver API
  * @{
  */


/**
 *  @brief The function is used to set RTS setting.
 *
 *  @param[in] tUART    Specify UART0/UART1
 *  @param[in] u8Value \n
 *                     Set 0: Drive RTS pin to logic 1 (If the LEV_RTS set to low level triggered). \n
 *                            Drive RTS pin to logic 0 (If the LEV_RTS set to high level triggered). \n
 *                     Set 1: Drive RTS pin to logic 0 (If the LEV_RTS set to low level triggered). \n	
 *                            Drive RTS pin to logic 1 (If the LEV_RTS set to high level triggered). \n
 *                     Note: LEV_RTS is RTS Trigger Level. 0 is low level and 1 is high level. 
 *
 *  @return None
 *
 *  @par Example
 *  @code
 *  //Condition: Drive RTS to logic 1 when RTS is high level triggered in UART channel 1 
 *  UART_SetRTS (UART1,1);
 *  @endcode
 *
 */
void DrvUART_DriveRTS(UART_T  *tUART, uint8_t u8Value)
{
    tUART->MCR &= ~UART_MCR_LEV_RTS_HIGH;
    tUART->MCR |= (u8Value<<1);
}	



/**
 *  @brief       The function is used to initialize UART. 
 *               It consists of baud-rate, parity, data-bits, stop-bits, rx-trigger-level and timeout interval settings.
 *
 *  @param[in]   tUART     Specify UART0/UART1
 *  @param[in]   sParam      Specify the property of UART. It includes
 *                           - \b u32BaudRate: Baud rate (Hz)
 *                           - \b u8cParity: NONE/EVEN/ODD parity \n
 *                           It could be: \n
 *                              UART_PARITY_NONE (None parity) \n
 *                              UART_PARITY_EVEN (Even parity) \n 
 *                              UART_PARITY_ODD(Odd parity) \n  
 *                           - \b u8cDataBits: data bit setting \n
 *                             It could be: \n
 *                                UART_WORD_LEN_5 (5 data bits) \n
 *                                UART_WORD_LEN_6 (6 data bits) \n 
 *                                UART_WORD_LEN_7 (7 data bits) \n
 *                                UART_WORD_LEN_8 (8 data bits) \n
 *                           - \b u8cStopBits: stop bits setting \n
 *                             It could be: \n
 *                                UART_STOPBIT_1 (1 stop bit) \n
 *                                UART_STOP_BIT_1_5 (1.5 stop bit) \n
 *                                UART_STOPBIT_2 (2 stop bits) \n
 *                           - \b u8cRxTriggerLevel: Rx FIFO interrupt trigger Level \n
 *                             LEVEL_X_BYTE means the trigger level of UART channel is X bytes \n
 *                             It could be: \n
 *                                UART_FCR_RFITL_1BYTE \n
 *                                UART_FCR_RFITL_4BYTES \n
 *                                UART_FCR_RFITL_8BYTES \n
 *                                UART_FCR_RFITL_14BYTES \n
 *                           - \b u8TimeOut: Time out value "N". It represents N-clock cycle and the counting clock is baud rate.
 *                           - \b u8EnableDiv16: Divider 16 ENABLE/DISABLE.
 *
 * @return E_SUCCESS: Success
 *
 * @par Example: 
 * @code
 *  //Set UART0 under 115200bps, 8 data bits ,1 stop bit and none parity and 1 byte Rx trigger level settings, disable divider 16.
 *  STR_UART_T sParam; 
 *  sParam.u32BaudRate 		= 115200; 
 *  sParam.u8cDataBits 		= UART_WORD_LEN_8; 
 *  sParam.u8cStopBits 		= UART_STOPBIT_1; 
 *  sParam.u8cParity 		= UART_PARITY_NONE; 
 *  sParam.u8cRxTriggerLevel	= UART_FCR_RFITL_14BYTES; 
 *  UART_Init (UART_PORT0, &sParam);
 * @endcode
 *
*/
int32_t DrvUART_Init(UART_T  *tUART, STR_UART_T *sParam)
{
	
    SET_UART_CLKSRC(sParam->u32ClkSrc);
    SET_UART_CLKDIV(sParam->u32ClkDiv);               //En:Set UART clock divider number
	
    if(tUART == UART0)
    {
        /* Reset IP */
        SYS_RESET_IP2(SYS_RST_UART0);                //En:Reset UART0 IP
		
        /* Enable UART clock */
        APBCLK_ENABLE(CLK_UART0);               //En:Enable UART0 clock
    }
    else
    {
        /* Reset IP */
        SYS_RESET_IP2(SYS_RST_UART1);                //En:Reset UART1 IP
		
        /* Enable UART clock */
        APBCLK_ENABLE(CLK_UART1);               //En:Enable UART1 clock
    }
	
    /* Tx FIFO Reset & Rx FIFO Reset & FIFO Mode Enable */
    UART_RESET_FIFO(tUART, UART_FCR_RST_TX_FIFO|UART_FCR_RST_RX_FIFO);

    /* Set Rx Trigger Level, Parity & Data bits & Stop bits */
    UART_SET_RX_TRG_LEV(tUART, sParam->u32cRxTriggerLevel);	
    UART_SET_DATA_FORMAT(tUART, sParam->u32cDataBits | sParam->u32cParity | sParam->u32cStopBits);
	
    /* Set Time-Out */
    UART_SET_RX_TIMEOUT(tUART ,sParam->u8RxTimeOut);

    if(sParam->u32BaudMode == UART_BAUD_MODE2)
        UART_SET_BAUD_MODE2(tUART, sParam->u32ClkFreq, sParam->u32BaudRate);
    else
        UART_SET_BAUD_MODE0(tUART, sParam->u32ClkFreq, sParam->u32BaudRate);

    return TRUE;
}


/**
 *  @brief       The function is used to initialize UART Auto Flow Control. 
 *               It consists of rts active level and cts active level and rts-rx-trigger-level settings.
 *
 *  @param[in]   tUART     Specify UART0/UART1
 *  @param[in]   sParam      Specify the property of UART auto flow control. It includes
 *                           - \b u32RTSTriLevel: RTS Rx FIFO trigger level
 *                           - \b u32RTSActiveLevel: RTS active level \n
 *                           It could be: \n
 *                              UART_MCR_RTS_LEVEL_HIGH (active high) \n
 *                              UART_MCR_RTS_LEVEL_LOW (active low) \n 
 *                           - \b u32CTSActiveLevel: CTS active level \n
 *                             It could be: \n
 *                                UART_MCR_CTS_LEVEL_HIGH (active high) \n
 *                                UART_MCR_CTS_LEVEL_LOW (active low) \n 
 *
 * @return None
 *
 * @par Example: 
 * @code
 *  //Set UART0 RTS Rx FIFO trigger level is 14 bytes settings, RTS active level low, CTS active level low.
 *  STR_UART_FLOWCTRL_T sParam; 
 *  sParam.u32RTSTriLevel	= UART_FCR_RTS_TRI_LEV_14BYTES;
 *	sParam.u32RTSActiveLevel= UART_MCR_RTS_LEVEL_LOW;
 *	sParam.u32CTSActiveLevel= UART_MCR_CTS_LEVEL_LOW;
 *  UART_Init (UART0, &sParam);
 * @endcode
 *
*/

void DrvUART_EnableFlowCtrl(UART_T  *tUART, STR_UART_FLOWCTRL_T *sParam)
{
    UART_ENABLE_AUTOFLOW(tUART, UART_IER_AUTO_RTS_EN|UART_IER_AUTO_CTS_EN);
    UART_SET_RTS_TRGLEV(tUART,  UART_FCR_RTS_TRI_LEV_14BYTES);
    
    if(sParam->u32RTSActiveLevel == UART_MCR_LEV_RTS_HIGH)
    	UART_RTS_ACTIVE_LEV_HIGH(tUART);
    else
    	UART_RTS_ACTIVE_LEV_LOW(tUART);
    if(sParam->u32CTSActiveLevel == UART_MSR_LEV_CTS_HIGH)
    	UART_CTS_ACTIVE_LEV_HIGH(tUART);
    else
    	UART_CTS_ACTIVE_LEV_LOW(tUART);
}

void DrvUART_DisableFlowCtrl(UART_T  *tUART)
{
    UART_DISABLE_AUTOFLOW(tUART, UART_IER_AUTO_RTS_EN|UART_IER_AUTO_CTS_EN);
}


/**
 *  @brief The function is used to disable UART clock, disable ISR and clear callback function pointer after checking the TX empty.
 *
 *  @param[in] tUART     Specify UART0/UART1
 *
 *  @return None
 *
 *  @par Example:
 *  @code
 *   //Close UART channel 0
 *   UART_DeInit (UART0);
 *  @endcode
 *
 */
void DrvUART_DeInit(UART_T  *tUART)
{
    while(UART_GET_TE_FLAG(tUART) == 0);

    if(tUART == UART1)
    {
        APBCLK_DISABLE(CLK_UART1);
        NVIC_DisableIRQ (UART1_IRQn); 
    }
    else
    {
        APBCLK_DISABLE(CLK_UART0);
        NVIC_DisableIRQ(UART0_IRQn); 
    }

}



/**
 *  @brief The function is used to enable specified UART interrupt and enable NVIC UART IRQ.
 *
 *  @param[in] tUART             Specify UART0/UART1
 *  @param[in] u32InterruptFlag  \n
 *                               \b DRVUART_LININT    : LIN Interrupt Enable \n
 *                               \b DRVUART_ABAUDINT  : Auto-Baud Rate Interrupt Enable \n
 *                               \b DRVUART_WAKEINT   : Wakeup Interrupt \n
 *                               \b DRVUART_BUFERRINT : Buffer Error Interrupt Enable \n
 *                               \b DRVUART_TOUTINT   : Time-out Interrupt Enable \n
 *                               \b DRVUART_MOSINT    : MODEM Status Interrupt Enable \n
 *                               \b DRVUART_RLSNT     : Receive Line Status Interrupt Enable \n
 *                               \b DRVUART_THREINT   : Transmit Holding Register Empty Interrupt Enable \n
 *                               \b DRVUART_RDAINT    : Receive Data Available Interrupt Enable 
 *  @param[in] pfncallback       Call back function pointer
 *
 *  @par Include:
 *       nano1xx_drivers/nano1xx_uart.h
 *
 *  @return None
 *
 *  @note Use "|" to connect the interrupt flags to enable multiple interrupts simultaneously. \n
 *        If you call the function twice in a project, the settings is dependent on the second setting.
 *
 *  @par Example:
 *  @code
 *   //Enable UART channel 0 RDA and THRE interrupt.
 *   UART_EnableInt(UART_PORT0, (DRVUART_RDAINT | DRVUART_THREINT ) );
 *
 *  @endcode
 */
void DrvUART_EnableInt(UART_T  *tUART, uint32_t  u32InterruptFlag)
{
    UART_ENABLE_INT(tUART, u32InterruptFlag);

    if (tUART == UART0) 
    {
        NVIC_EnableIRQ(UART0_IRQn); 
    }
    else
    {
        NVIC_EnableIRQ(UART1_IRQn); 
    }
}


/**
 *  @brief The function is used to disable UART specified interrupt and disable NVIC UART IRQ.
 *
 *  @param[in] tUART            Specify UART0/UART1
 *  @param[in] u32InterruptFlag \n
 *                              \b DRVUART_LININT    : LIN Interrupt Enable \n
 *                              \b DRVUART_ABAUDINT  : Auto-Baud Rate Interrupt Enable \n
 *                              \b DRVUART_WAKEINT   : Wakeup Interrupt \n
 *                              \b DRVUART_BUFERRINT : Buffer Error Interrupt Enable \n
 *                              \b DRVUART_TOUTINT   : Time-out Interrupt Enable \n
 *                              \b DRVUART_MOSINT    : MODEM Status Interrupt Enable \n
 *                              \b DRVUART_RLSNT     : Receive Line Status Interrupt Enable \n
 *                              \b DRVUART_THREINT   : Transmit Holding Register Empty Interrupt Enable \n
 *                              \b DRVUART_RDAINT    : Receive Data Available Interrupt Enable 
 *
 *  @par Include:
 *       nano1xx_drivers/nano1xx_uart.h
 *
 *  @return None
 *
 *  @note Use "|" to connect the interrupt flags to disable multiple interrupts simultaneously.
 *
 *  @par Example:
 *  @code
 *   //To disable the THRE interrupt enable flag
 *   UART_DisableInt (UART_PORT0, DRVUART_THREINT);
 *  @endcode
 *
 */
void DrvUART_DisableInt(UART_T  *tUART, uint32_t u32InterruptFlag)
{
    UART_DISABLE_INT(tUART, u32InterruptFlag);
    if (tUART == UART0)
    {
        NVIC_DisableIRQ(UART0_IRQn);   
    }
    else
    {
       	NVIC_DisableIRQ(UART1_IRQn);    
    }
}


/**
 *  @brief The function is used to get CTS pin value and detect CTS change state
 *
 *  @param[in]  tUART             Specify UART0/UART1
 *  @param[out] pu8CTSValue       Specify the buffer to receive the CTS value.Retrun current CTS pin state
 *  @param[out] pu8CTSChangeState Specify the buffer to receive the CTS change state. 
 *                                Return CTS pin state is changed or not.
 *                                1 means changed and 0 means not yet.
 *  @return None
 *
 *  @par Example:
 *  @code
 *  //To get CTS pin status and save to u8CTS_value. To get detect CTS change flag and save to u8CTS_state.
 *  uint8_t u8CTS_value, u8CTS_state;
 *  UART_GetCTSInfo(UART1,& u8CTS_value,& u8CTS_state);
 *  @endcode
 *
 */
void DrvUART_GetCTSInfo(UART_T  *tUART, uint8_t *pu8CTSValue, uint8_t	*pu8CTSChangeState)
{
    *pu8CTSValue 	= UART_GET_CTSPIN(tUART)?1:0 ;
    *pu8CTSChangeState 	= UART_GET_DCTSF(tUART)?1:0;
}	

/**
 *  @brief The function is used to configure IRDA relative settings. It consists of TX or RX mode and Inverse TX or RX signals.
 *
 *  @param[in] tUART    Specify UART0/UART1
 *  @param[in] str_IRCR 
 *                      The structure of IrDA \n
 *                      It includes of \n
 *                      - \b u8cTXSelect : \n
 *                        1 : Enable IrDA transmit function. It becomes TX mode \n
 *                        0 : Disable IrDA transmit function. It becomes RX mode.\n
 *                      - \b u8cInvTX : Invert Tx signal function TRUE or FASLE
 *                      - \b u8cInvRX : Invert Rx signal function (Default value is TRUE) TRUE or FASLE
 *
 *  @par Include:
 *       nano1xx_drivers/nano1xx_uart.h 
 *
 *  @return None
 *           
 *  @note Before using the API, you should configure UART setting firstly.
 *        And make sure the baud-rate setting is used mode 0 (UART divider is 16)in baud-rate configure.
 *
 *  @par Example:
 *  @code
 *  //Change UART1 to IRDA function and Inverse the RX signals. 
 *  STR_IRCR_T sIrda;	
 *  sIrda.u8cTXSelect  = ENABLE;
 *  sIrda.u8cInvTX    = FALSE;
 *  sIrda.u8cInvRX    = TRUE;
 *  UART_SetFnIRDA(UART_PORT1,&sIrda);
 *  @endcode
 *
 */
void DrvUART_SetFnIRDA(UART_T  *tUART, STR_IRCR_T *str_IRCR )
{
    tUART->FUN_SEL = UART_FUNC_SEL_IrDA;	/* Enable IrDA function and configure */
    tUART->IRCR	&= ~(UART_IRCR_TX_SELECT | UART_IRCR_INV_TX | UART_IRCR_INV_RX);
    tUART->IRCR	|= (str_IRCR->u8cTXSelect) ? UART_IRCR_TX_SELECT:0;
    tUART->IRCR	|= (str_IRCR->u8cInvTX) ? UART_IRCR_INV_TX:0;
    tUART->IRCR	|= (str_IRCR->u8cInvRX) ? UART_IRCR_INV_RX:0 ;
}

/**
 *  @brief The function is used to set RS485 relative setting
 *
 *  @param[in] tUART     Specify UART0/UART1
 *  @param[in] str_RS485
 *                       The structure of RS485 \n
 *                       It includes of \n
 *                       - \b u8cModeSelect: Select operation mode \n
 *                       -- UART_RS485_NMM: RS-485 Normal Multi-drop Mode \n
 *                       -- UART_RS485_AAD: RS-485 Auto Address Detection Mode \n
 *                       -- UART_RS485_AUD: RS-485 Auto Direction Mode \n
 *                       - \b u8cAddrEnable: Enable or Disable RS-485 Address Detection 
 *                       - \b u8cAddrValue: Set Address match value
 *                       - \b u8cDelayTime: Set transmit delay time value
 *                       - \b u8cRxDisable: Enable or Disable receiver function.
 *
 *  @return None
 *
 *  @par Example:
 *  @code
 *  //Condition: Change UART1 to RS485 function. Set relative setting as below.
 *  STR_RS485_T sParam_RS485;
 *  sParam_RS485.u8cAddrEnable 	= ENABLE; 
 *  sParam_RS485.u8cAddrValue  	= 0xC0;	 //Address 
 *  sParam_RS485.u8cModeSelect 	= UART_RS485_AAD|UART_RS485_AUD;
 *  sParam_RS485.u8cDelayTime  	= 0;
 *  sParam_RS485.u8cRxDisable  	= TRUE;
 *  UART_SetFnRS485(UART1,&sParam_RS485);
 *  @endcode
 *
 */
void DrvUART_SetFnRS485(UART_T  *tUART, STR_RS485_T *str_RS485)
{
    tUART->FUN_SEL = UART_FUNC_SEL_RS485;

    tUART->ALT_CSR |= ((str_RS485->u8cAddrValue << 24) |
				(str_RS485->u8cAddrEnable << 15) |
				(str_RS485->u8cModeSelect /* << 16*/));
					     
    UART_SET_TX_DELAY(tUART, str_RS485->u8cDelayTime);
	
    tUART->FCR &= ~UART_FCR_RX_DIS;
    tUART->FCR |= (str_RS485->u8cRxDisable) ? UART_FCR_RX_DIS:0;
} 

/*@}*/ /* end of group DrvUART_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/



