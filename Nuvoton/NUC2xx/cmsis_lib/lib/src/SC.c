/**************************************************************************//**
 * @file     SC.c
 * @version  V1.00
 * $Revision: 14 $
 * $Date: 12/08/31 5:20p $ 
 * @brief    NUC200 Smart Card Driver
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NUC200Series.h"
#include "SC.h"
#include "SYS.h"

/* global buffer is used for IST to receive */
uint8_t g_au8PortRxBuf[3][SC_MIN_BUFFER_SIZE];

/* global buffer is used for IST to transmit */
uint8_t g_au8PortTxBuf[3][SC_MIN_BUFFER_SIZE];

/* global variable for SmartCard Device */
volatile S_SC_DEV_T g_asScDevice[SC_SC_NUM];

/* global variables for receiving ATR from smartcard */
/* TS & T0 */
volatile uint32_t g_au32AtrLen[3]={0,0,0};
volatile uint32_t g_au32AtrRemain[3]={2,2,2};
/* interface bytes flag */
volatile int32_t g_ai32IfbyteFlag[3]={-1,-1,-1};
volatile int32_t g_ai32Tck[3]={0,0,0}; 
volatile int32_t g_ai32Ifcount[3]={0,0,0};

/* ATR is returned within SC_ATR_TOTAL_TIME ETUs defined by EMV */
volatile int32_t g_ai32AtrTime[3]={SC_ATR_TOTAL_TIME, SC_ATR_TOTAL_TIME, SC_ATR_TOTAL_TIME};
volatile int32_t g_ai32AtrCheckTime[3]={0,0,0};
volatile int32_t g_ai32AtrTotalTimeStartFlag[3]={0,0,0};


/* ATR: spend one waiting to check if other redundant byte */
volatile int32_t g_ai32AtrFinalChk[3]={0,0,0};

/* global variable for callback function */
static SC_PFN_CALLBACK *g_pfnSCCallBack_CardPresent[3] = {NULL,NULL,NULL};

/* To store the expected data from ICC, driver will keep it for next reading request */
volatile uint8_t g_au8ScUnexpectedInBuf[3][SC_MIN_BUFFER_SIZE];
volatile uint8_t g_au8ScUnexpectedBufLen[3]={0,0,0};


/* re-fill ETU divider */
volatile uint32_t g_au32ScEtuDivider[3] = {372,372,372};


/**
  * @brief	    Smart card error message
  * @param[in]  errno       Error message	
  * @return     error message 
  */
uint8_t * SC_ErrMsg(long errno)
{
	if(errno == SC_ERR_CARD_REMOVED)
		return (uint8_t *) "SC_ERR_CARD_REMOVED";
	if(errno == SC_ERR_OVER_RUN)
		return (uint8_t *) "SC_ERR_OVER_RUN";
	if(errno == SC_ERR_PARITY_ERROR)
		return (uint8_t *) "SC_ERR_PARITY_ERROR";
	if(errno == SC_ERR_NO_STOP)
		return (uint8_t *) "SC_ERR_NO_STOP";
	if(errno == SC_ERR_SILENT_BYTE)
		return (uint8_t *) "SC_ERR_SILENT_BYTE";
	if(errno == SC_ERR_CMD)
		return (uint8_t *) "SC_ERR_CMD";
	if(errno == SC_ERR_UNSUPPORTEDCARD)
		return (uint8_t *) "SC_ERR_UNSUPPORTEDCARD";
	if(errno == SC_ERR_READ)
		return (uint8_t *) "SC_ERR_READ";
	if(errno == SC_ERR_WRITE)
		return (uint8_t *) "SC_ERR_WRITE";
	if(errno == SC_ERR_TIME0OUT)
		return (uint8_t *) "SC_ERR_TIME0OUT";
	if(errno == SC_ERR_TIME1OUT)
		return (uint8_t *) "SC_ERR_TIME1OUT";
	if(errno == SC_ERR_TIME2OUT)
		return (uint8_t *) "SC_ERR_TIME2OUT";
	if(errno == SC_PROTOCOL_T0_ERROR)
		return (uint8_t *) "SC_PROTOCOL_T0_ERROR";
	if(errno == SC_ERR_AUTOCONVENTION)
		return (uint8_t *) "SC_ERR_AUTOCONVENTION";
	if(errno == SC_ERR_BGTIMEOUT)
		return (uint8_t *) "SC_ERR_BGTIMEOUT";
	if(errno == SC_EPROTOCOL)
		return (uint8_t *) "SC_EPROTOCOL";
	if(errno == SC_T1_ERROR_CHKSUM)
		return (uint8_t *) "SC_T1_ERROR_CHKSUM";
	if(errno == SC_PROTOCOL_T1_ERROR)
		return (uint8_t *) "SC_PROTOCOL_T1_ERROR";
	if(errno == SC_ATR_ERR_INVALID_PARAMETER)
		return (uint8_t *) "SC_ATR_ERR_INVALID_PARAMETER";
	
	return (uint8_t *) "No Such Error Messages";
}

/**
  * @brief      Check if SmartCard slot is presented
  * @param[in]	psPortno        Indicate which port to be used
  *                             - SC0
  *                             - SC1
  *                             - SC2    
  * @retval     SC_STAUS_PRESENT	Specified the SmartCard device is presented
  *			    SC_STAUS_ABSENT	Specified the SmartCard device is absent
  * @details    This function is used to check if specified smart card slot is presented 
  */
int32_t SC_CheckCardPresent(SC_T *psPortno)
{
	S_SC_DEV_T *psDev;
	int32_t port = 0;
	
	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
	
	psDev= (S_SC_DEV_T *)(uint32_t)&g_asScDevice[port];

	return psDev->bCardRemoved;	
}

/**
  * @brief	    Driver always returns card is present.
  * @param[in]	psPortno		Indicate which port to be used
  *                             - SC0
  *                             - SC1
  *                             - SC2 
  * @retval     SC_STATUS_SUCCESS		Successful											 
  * @details    Driver always returns card is present. This function generally is called when
  *             no card detection pin in HW environment. 
  */
int32_t SC_IgnoreCardAbsent(SC_T *psPortno)
{
	S_SC_DEV_T *psDev;
	int32_t port = 0;

	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
		
	psDev= (S_SC_DEV_T *)(uint32_t)&g_asScDevice[port];

	psDev->bCardRemoved = SC_STAUS_PRESENT;

	return SC_STATUS_SUCCESS;
}

/**
  * @brief	    Set the rising/falling edge of detection pin for smart card insertion.
  * @param[in]	psPortno		Indicate which port to be used
  *                             - SC0
  *                             - SC1
  *                             - SC2 
  * @param[in]	edge		    - 1: Rising edge to card insert
  *                             - 0: Falling edge to card insert
  * @retval     SC_STATUS_SUCCESS		Successful
  * @details    Set the rising/falling edge of detection pin for smart card insertion.    
  *             Due to hardware design, this function must be called after calling SC_Init and before calling SC_Open.
  */
int32_t SC_CardDetectEdge(SC_T *psPortno, int8_t edge)
{
	SC_T *SC = psPortno;
		
    SC->CTL&= ~SC_CTL_SC_CEN_Msk;
	/* card detect level must be set before engine enable */
    SC->PINCSR = (SC->PINCSR&(~SC_PINCSR_CD_LEV_Msk)&(~SC_CD_INS_REM_MASK)) | (edge<<SC_PINCSR_CD_LEV_Pos);	// card be detected low -> high, this must be set before enable engine 
    SC->CTL|= SC_CTL_SC_CEN_Msk;
	return SC_STATUS_SUCCESS;
}

/**
  * @brief	    Enable/Disable smart card clock output pin 
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @param[in]	onoff   Enable/Disable clock output pin	
  *                     - 1:Enable clock; 
  *                     - 0:Disable clock  
  * @return     None
  * @details    Enable/Disable smart card clock output pin       
  */
void SC_SetClockState(S_SC_DEV_T *psDev, int8_t onoff)
{
	SC_T *SC = psDev->base;
	
	if ( onoff == 1 )
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK))|SC_PINCSR_CLK_KEEP_Msk;
	else if ( onoff == 0 )
        SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_CLK_KEEP_Msk);
}

/**
  * @brief	    Set the clock stop level according the clock_stop_level field of structure.
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Set the clock stop level according the clock_stop_level field of structure.  
  */
void SC_ClockStopLevel(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	uint32_t clock_level = psDev->clock_stop_level;
	
	if ( clock_level == SC_CLK_PIN_STOP_LOW )
        SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_CLK_STOP_LEV_Msk);
	else if ( clock_level == SC_CLK_PIN_STOP_HIGH )
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK))|SC_PINCSR_CLK_STOP_LEV_Msk;	
}

/**
  * @brief	    Enable Tx error retry function and set the number of times of Tx error retry.
  * @param[in]	psDev 	   The pointer of data structure of smartcard information
  * @param[in]	errNum	   The number of times of Tx error retry. The range of value is from 0 to 8.
  * @return     None
  * @details    Enable Tx error retry function and set the number of times of Tx error retry.
  *             Tx Error retry means that transmission has parity error, hardware will re-transmit again.
  */
static void SC_SetTxRetry(S_SC_DEV_T *psDev, uint32_t errNum)
{
	SC_T *SC = psDev->base;

	//assert_param( errNum<9 );

	if(errNum == 0)	// disable Tx error retry
	{
        SC->CTL&= ~SC_CTL_TX_ERETRY_Msk;
        SC->CTL&= ~SC_CTL_TX_ERETRY_EN_Msk;
	}
	else
	{
        SC->CTL = (SC->CTL&(~SC_CTL_TX_ERETRY_Msk))|((errNum - 1)<<SC_CTL_TX_ERETRY_Pos);
        SC->CTL|= SC_CTL_TX_ERETRY_EN_Msk;
	}

}

/**
  * @brief	    Enable Rx error retry function and set the number of times of Rx error retry.
  * @param[in]	psDev 	   The pointer of data structure of smartcard information
  * @param[in]	errNum	   The number of times of Rx error retry. The range of value is from 0 to 8.
  * @return     None
  * @details    Enable Rx error retry function and set the number of times of Rx error retry.
  *             Rx Error retry means that receiver detects a parity error, hardware will pull I/O LOW to notice the transmitter.
  */
static void SC_SetRxRetry(S_SC_DEV_T *psDev, uint32_t errNum)
{
	SC_T *SC = psDev->base;

	//assert_param( errNum<9 );

	if(errNum == 0)	// disable Rx error retry
	{
        SC->CTL&= ~SC_CTL_RX_ERETRY_Msk;
        SC->CTL&= ~SC_CTL_RX_ERETRY_EN_Msk;
	}
	else
	{
        SC->CTL = (SC->CTL&(~SC_CTL_RX_ERETRY_Msk))|((errNum - 1)<<SC_CTL_RX_ERETRY_Pos);
        SC->CTL|= SC_CTL_RX_ERETRY_EN_Msk;
	}
}

/**
  * @brief	    Reset the Tx/Rx FIFO
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Reset the Tx/Rx FIFO
  */
void SC_ClearFIFO(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	
	/* Check if the end of initial end sequence */
    while((SC->ALTCTL&SC_ALTCTL_WARST_EN_Msk) == SC_ALTCTL_WARST_EN_Msk);
    while((SC->ALTCTL&SC_ALTCTL_ACT_EN_Msk) == SC_ALTCTL_ACT_EN_Msk);
    while((SC->ALTCTL&SC_ALTCTL_DACT_EN_Msk) == SC_ALTCTL_DACT_EN_Msk);
    SC->ALTCTL|= SC_ALTCTL_RX_RST_Msk;
    SC->ALTCTL|= SC_ALTCTL_TX_RST_Msk;
}

/**
  * @brief	    Turn on and configure the output voltage according the voltage field of structure.
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Turn on and configure the output voltage according the voltage field of structure.
  */
void SC_VoltageConfig(S_SC_DEV_T *psDev)
{

	/* select power supply */
	switch(psDev->voltage)
	{
		case SC_ISO_OPERATIONCLASS_A:		/* 5v */
			// TODO: configure VCC to 5V according to hardware design

			break;

		case SC_ISO_OPERATIONCLASS_B:		/* 3v */
			// TODO: configure VCC to 3V according to hardware design

			break;
		default:	
		case SC_ISO_OPERATIONCLASS_C:		/* 1.8v */
			// TODO: configure VCC to 1.8V according to hardware design
			
			break;
	}	

}	

/**
  * @brief	    Determine the active low/high of power pin
  * @param[in]	psPortno	Indicate which port to be used
  *                         - SC0
  *                         - SC1
  *                         - SC2 
  * @param[in]	active      - 1: active HIGH
  *     				    - 0: active LOW
  * @retval     SC_STATUS_SUCCESS		Successful											 
  * @details    Determine the active low/high of power pin
  */
int32_t SC_PowerActiveLevel(SC_T *psPortno, int8_t active)
{
#ifdef SC_SEQ_MANUAL
    SC_T *SC = psPortno;
	S_SC_DEV_T *psDev;	
	int32_t port = 0;
		
	SC = psPortno;
	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
	
	psDev = (S_SC_DEV_T *)((uint32_t)&g_asScDevice[port]);
    SC->CTL&= ~SC_CTL_SC_CEN_Msk;
    SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_POW_INV_Msk);
    SC->CTL|= SC_CTL_SC_CEN_Msk;
	if(active==1) 
	{
        SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_POW_EN_Msk);// power pin low in default
		psDev->ActivePowerPin = 1;
	}
	else if(active==0)
	{
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK))|SC_PINCSR_POW_EN_Msk;// power pin high in default	
		psDev->ActivePowerPin = 0;
	}
#else
	SC_T *SC = psPortno;
	
    SC->CTL&= ~SC_CTL_SC_CEN_Msk;
    SC->CTL|= SC_CTL_SC_CEN_Msk;
#endif
	return SC_STATUS_SUCCESS;
}


/**
  * @brief	    Ture on the power output pin
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Ture on the power output pin
  */
void SC_PowerOn(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
    if(psDev->ActivePowerPin) // power pin 
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | SC_PINCSR_POW_EN_Msk;
    else
        SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_POW_EN_Msk);  
}	
/**
  * @brief	    Ture off the power output pin
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Ture off the power output pin 
  */
void SC_PowerOff(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
    if(psDev->ActivePowerPin) // power pin 
        SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_POW_EN_Msk);
    else
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | SC_PINCSR_POW_EN_Msk;
}


/**
  * @brief	    De-activation sequence generator
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    De-activation sequence generator   
  */
void SC_DeactivationCmd(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	
#ifdef	SC_SEQ_MANUAL
	// Wait for Tx & Rx get into idle mode
    while((SC->TRSR&SC_TRSR_TX_ATV_Msk)==SC_TRSR_TX_ATV_Msk);
    SC->ALTCTL|= SC_ALTCTL_TX_RST_Msk;
	while((SC->TRSR&SC_TRSR_RX_ATV_Msk)==SC_TRSR_RX_ATV_Msk) ;
	SC->ALTCTL|= SC_ALTCTL_RX_RST_Msk;	
	// Reset
    SC->PINCSR = SC->PINCSR&(~SC_CD_INS_REM_MASK)&(~SC_PINCSR_SC_RST_Msk);
	while((SC->PINCSR&SC_PINCSR_SC_RST_Msk)==SC_PINCSR_SC_RST_Msk) ;	// wait HW reset pin really becomes LOW
	// Clock // I/O output LOW
	SC->PINCSR&= ~(SC_CD_INS_REM_MASK | SC_PINCSR_CLK_KEEP_Msk | SC_PINCSR_SC_DATA_O_Msk);
    while((SC->PINCSR&SC_PINCSR_SC_DATA_O_Msk)==SC_PINCSR_SC_DATA_O_Msk);	// wait HW I/O pin really becomes LOW
	// Power
    if(psDev->ActivePowerPin)
        SC->PINCSR&= ~(SC_PINCSR_POW_EN_Msk|SC_CD_INS_REM_MASK);
    else
        SC->PINCSR = (SC->PINCSR &(~SC_CD_INS_REM_MASK)) | SC_PINCSR_POW_EN_Msk;   
#else
    SC->ALTCTL|= SC_ALTCTL_DACT_EN_Msk;
#endif
}
/**
  * @brief	    Activation sequence generator
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Activation sequence generator    
  */
void SC_ActivationCmd(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	
#ifdef	SC_SEQ_MANUAL
	// disable Timer1 interrupt and use polling method to check time-out happened
    SC->IER&= ~SC_IER_TMR1_IE_Msk;
	
	// Power
    if(psDev->ActivePowerPin)
        SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | SC_PINCSR_POW_EN_Msk;
    else
        SC->PINCSR&= ~(SC_CD_INS_REM_MASK|SC_PINCSR_POW_EN_Msk);  
	// Clock
	SC_TimerCountSet(psDev, SC_TIMER1, SC_TMR_MODE0_DC, 1);
	SC_TimerStart(psDev, SC_TIMER1);
	while(((SC->ISR & SC_ISR_TMR1_IS_Msk) == 0x00) && (psDev->errno != SC_ERR_CARD_REMOVED));
    SC->ISR = SC_ISR_TMR1_IS_Msk;
    // CLK enable DAT will be pull high
    SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | (SC_PINCSR_CLK_KEEP_Msk | SC_PINCSR_SC_DATA_O_Msk);
	SC_TimerCountSet(psDev, SC_TIMER1, SC_TMR_MODE0_DC, 109);	// 108*372 = 40176 clocks
	SC_TimerStart(psDev, SC_TIMER1);
	while(((SC->ISR & SC_ISR_TMR1_IS_Msk) == 0x00) && (psDev->errno != SC_ERR_CARD_REMOVED));
	SC->ISR = SC_ISR_TMR1_IS_Msk;
	// enable Timer1 interrupt
    SC->IER|= SC_IER_TMR1_IE_Msk;
    SC->PINCSR = (SC->PINCSR &(~SC_CD_INS_REM_MASK)) | SC_PINCSR_SC_RST_Msk;
	// wait 42036 clock for ATR 
	SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC, (42000/372) + 13);
	SC_TimerStart(psDev, SC_TIMER0);	
#else
    SC->ALTCTL|= SC_ALTCTL_ACT_EN_Msk;    
#endif
}
/**
  * @brief	    WarmReset sequence generator
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    WarmReset sequence generator     
  */
void SC_WarmResetCmd(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	
#ifdef	SC_SEQ_MANUAL
	int32_t cardno = 0;
	if(psDev->base==SC0)
		cardno = 0;
	else if(psDev->base==SC1)
		cardno = 1;
	else if(psDev->base==SC2)
		cardno = 2;

	// Wait for Tx & Rx get into idle mode
    while((SC->TRSR&(SC_TRSR_TX_EMPTY_F_Msk|SC_TRSR_TX_ATV_Msk)) == SC_TRSR_TX_ATV_Msk);
    while((SC->TRSR&(SC_TRSR_RX_EMPTY_F_Msk|SC_TRSR_RX_ATV_Msk)) == SC_TRSR_RX_ATV_Msk);
	// Reset
	while(g_asScDevice[cardno].op_state != SC_OP_NOP) ;		// wait for idle mode
    SC->CTL|= SC_CTL_DIS_RX_Msk;
	SC->PINCSR&= ~(SC_PINCSR_SC_RST_Msk | SC_CD_INS_REM_MASK);
	g_asScDevice[cardno].errno = 0;
	SC_TimerCountSet(psDev, SC_TIMER1, SC_TMR_MODE0_DC, (40000/(SC->ETUCR&SC_ETUCR_ETU_RDIV_Msk))+1);	// exceeds 40000 clocks
	SC_TimerStart(psDev, SC_TIMER1);
	while((g_asScDevice[cardno].errno != SC_ERR_TIME1OUT) && (g_asScDevice[cardno].errno != SC_ERR_CARD_REMOVED)) ;
	SC->PINCSR = (SC->PINCSR &(~SC_CD_INS_REM_MASK)) | SC_PINCSR_SC_RST_Msk;   
    SC->CTL&= ~SC_CTL_DIS_RX_Msk;

	// wait 42036 clock for ATR 
	SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC, (42000/372) + 13);
	SC_TimerStart(psDev, SC_TIMER0);
#else  
    SC->ALTCTL|= SC_ALTCTL_WARST_EN_Msk; 
#endif
}
/**
  * @brief	    Set Guard Time
  * @param[in]	psDev 	The pointer of data structure of smartcard information	
  * @return     None
  * @details    Set Guard Time  
  */
void SC_SetGuardTime(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
	uint32_t gt = psDev->CardCapabilities.GT;

	/* [EMV 2000] EMV in T=0, minmun GT is 12 */
	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T0)
	{
		if(gt==11)
			gt = 12;
		else {
            SC->CTL&= ~SC_CTL_SLEN_Msk;
			SC->EGTR = (SC->EGTR&~SC_EGTR_EGT_Msk) | (gt-12);
		}
	}

	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T1)
	{
		if(gt==11) {
            SC->CTL|= SC_CTL_SLEN_Msk;      // 1 EUT stop bit
			SC->EGTR = (SC->EGTR&~SC_EGTR_EGT_Msk);
		}
		else {
            SC->CTL|= SC_CTL_SLEN_Msk;      // 1 EUT stop bit
			SC->EGTR = (SC->EGTR&~SC_EGTR_EGT_Msk) | (gt-11);
		}
	}	
}
/**
  * @brief	    Set Block Guard Time
  * @param[in]	psDev 	The pointer of data structure of smartcard information	
  * @param	    bgt 	Block Guard time (ETU-based)
  * @return     None
  * @details    Set Block Guard Time
  */
void SC_SetBlockGuardTime(S_SC_DEV_T *psDev, uint32_t bgt)
{
	SC_T *SC = psDev->base;

    SC->CTL = (SC->CTL&(~SC_CTL_BGT_Msk)) | ((bgt-1)<<SC_CTL_BGT_Pos);
}

/**
  * @brief	    Enable the checking of block guard time function
  * @param[in]	psDev 	The pointer of data structure of smartcard information	
  * @return     None
  * @details    Enable the checking of block guard time function
  */
void SC_StartBlockGuardTime( S_SC_DEV_T *psDev )
{
	SC_T *SC = psDev->base;
    SC->ALTCTL|= SC_ALTCTL_RX_BGT_EN_Msk;
}

/**
  * @brief	    Stop the block guard time
  * @param[in]	psDev 	The pointer of data structure of smartcard information	
  * @return     None
  * @details    Stop the block guard time
  */
void SC_StopBlockGuardTime( S_SC_DEV_T *psDev )
{
	SC_T *SC = psDev->base;
    SC->ALTCTL&= ~SC_ALTCTL_RX_BGT_EN_Msk;
}
	
/**
  * @brief	    Check match card reader
  * @param[in]	Fi		Clock rate conversion interger from card
  * @param[in]	Di		Baud rate adjustment integer from card	
  * @retval     - SC_STATUS_SUCCESS             success
  *             - SC_ATR_ERR_INVALID_PARAMETER  Not match
  */	
static int32_t SC_MatchReader(int32_t Fi, int32_t Di)
{
	int32_t i;

	i = Fi/Di;

	if( (i % 31) == 0)
		return SC_STATUS_SUCCESS;
	else if( (i % 32) == 0)
		return SC_STATUS_SUCCESS;
	else
		return SC_ATR_ERR_INVALID_PARAMETER;

	// TODO: Maybe do more things here...
	//...
}	
	

/**
  * @brief	    Set the baudrate according to clock rate conversion integer and baud rate adjustment integer
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @param[in]	fi		The clock rate conversion integer from card
  * @param[in]	di		The baud rate adjustment integer from card
  * @return     None
  * @details    Set the baudrate according to clock rate conversion integer and baud rate adjustment integer
  */
static void SC_SetBaudrate(S_SC_DEV_T *psDev, int32_t fi, int32_t di)
{
	uint32_t etudiv;
	double fi_val, di_val, tmp, tmp2, remainder;
	SC_T *SC = psDev->base;

	fi_val = ClockRateConversion[fi].F;
	di_val = BitRateAdjustment[di].DNumerator;
	tmp = fi_val/di_val;
	remainder = modf(tmp, &tmp2) * 10;

	// if the first decimal point of etu divider is greater than 5, 
	// HW enable the compensation function
	if(remainder >= 5)	
	{
		etudiv = (ClockRateConversion[fi].F / BitRateAdjustment[di].DNumerator);
        SC->ETUCR = (etudiv&SC_ETUCR_ETU_RDIV_Msk)|SC_ETUCR_COMPEN_EN_Msk;
	}
	else
	{
		etudiv = (ClockRateConversion[fi].F / BitRateAdjustment[di].DNumerator);
        SC->ETUCR = (SC->ETUCR&(~SC_ETUCR_COMPEN_EN_Msk)) | (((etudiv - 1)&SC_ETUCR_ETU_RDIV_Msk)<<SC_ETUCR_ETU_RDIV_Pos);
	}

	if(SC==SC0)
        g_au32ScEtuDivider[0] = (SC->ETUCR&SC_ETUCR_ETU_RDIV_Msk);
	else if(SC==SC1)
		g_au32ScEtuDivider[1] = (SC->ETUCR&SC_ETUCR_ETU_RDIV_Msk);
	else if(SC==SC2)
		g_au32ScEtuDivider[2] = (SC->ETUCR&SC_ETUCR_ETU_RDIV_Msk);
}


/**
  * @brief	    According ATR information, basic settings will be set the new value about ETU, clock stop level, guard time and block guard time.
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    According ATR information, basic settings will be set the new value about ETU, clock stop level, guard time and block guard time.
  */
void SC_SetReaderParameter(S_SC_DEV_T *psDev)
{
	/* set reader baud rate and update psDev->clock , so we can calcute etu */
	SC_ENTER();
	
	SC_SetBaudrate(psDev, psDev->CardCapabilities.Fl, psDev->CardCapabilities.Dl);
	
	// TODO: set GT, BGT, clock stop level or apply the new settings

	SC_ClockStopLevel(psDev);
	
	SC_SetGuardTime(psDev);

	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T0)
	{
		SC_SetBlockGuardTime(psDev, 16);	//BGT = 16		  
	}
	else if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T1)
	{		 
		SC_SetBlockGuardTime(psDev, 22);	//BGT = 22
		/* set send-sequence & more-data bit */
		psDev->T1.SSN = 1;	// default value
		psDev->T1.RSN = 0;	// defalut value
		psDev->T1.IBLOCK_REC = 0;	// default value
	}

	/* Tx & Rx Error Retry Settings */
	/* [EMV 2000] */
	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T0)
	{
		SC_SetTxRetry(psDev, 4);		// Tx retry 4 times
		//SC_SetRxRetry(psDev, 8);		// Rx retry 8 times
		// [2011.11.25 night]
		/* EMV Certification */
		SC_SetRxRetry(psDev, 4);		// Rx retry 4 times
	}
	
	SC_LEAVE();

}


/**
  * @brief	    Reset the Tx/Rx FIFO & clock & initail default parameter
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @return     None
  * @details    Reset the Tx/Rx FIFO & clock & initail default parameter
  */
void SC_ResetReader(S_SC_DEV_T *psDev)
{
	SC_T *SC = psDev->base;
    	
	SC_ENTER();

	// TODO: Set basic HW settings & protocol default value
	
	/* Software Reset Tx & Rx transition */
	SC_ClearFIFO(psDev);

	/* Rx FIFO threshold */
    //SC->CTL = (SC->CTL&(~SC_CTL_RX_FTRI_LEV_Msk)) | (RX_FTRI_3BYTES<<SC_CTL_RX_FTRI_LEV_Pos);// trigger level 3 bytes    
    SC->CTL = (SC->CTL&(~SC_CTL_RX_FTRI_LEV_Msk)) | SC_CTL_RX_FTRI_LEV_1BYTE;// trigger level 1 bytes

	/* Rx Time-out setting */
	SC->RFTMR = 0;		// disable Rx FIFO time-out function

	/* Card detect de-bounce setting */
    SC->CTL&= ~SC_CTL_CD_DEB_SEL_Msk;

	/* in default, guard time = 12 etu */
	psDev->CardCapabilities.GT = 12;
	SC_SetGuardTime( psDev );	   

	/* initial end sequence timing setting */
    SC->ALTCTL = (SC->ALTCTL&(~SC_ALTCTL_INIT_SEL_Msk)) | (3<<SC_ALTCTL_INIT_SEL_Pos);

	/* Tx & Rx Error Retry Settings */
	/* [ISO 7816-3] */
	//SC_SetTxRetry(psDev, 8);		// Tx retry 8 times
	//SC_SetRxRetry(psDev, 8);		// Rx retry 8 times

	/* 
	 * Tx & Rx Error Retry Settings 
	 * [EMV 2000] 
	 * EMV 2000 does NOT use ERROR retry function during ATR 
	 */
	SC_SetTxRetry(psDev, 0);		// Tx retry 0 times
	SC_SetRxRetry(psDev, 0);		// Rx retry 0 times
	
	// clear any error status
	// ...

	/* enable auto de-activation sequence */
#ifndef SC_SEQ_MANUAL	
    SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK))|SC_PINCSR_ADAC_CD_EN_Msk;// auto de-activation when card removal
#endif

	/* enable auto convention */
    SC->CTL|= SC_CTL_AUTO_CON_EN_Msk;

	/* enable interrupt  */
    SC->IER|= (SC_IER_RDA_IE_Msk | SC_IER_TERR_IE_Msk |
               SC_IER_TMR0_IE_Msk | SC_IER_TMR1_IE_Msk | SC_IER_TMR2_IE_Msk|
               SC_IER_BGT_IE_Msk | SC_IER_CD_IE_Msk | SC_IER_INIT_IE_Msk |
               SC_IER_RTMR_IE_Msk | SC_IER_ACON_ERR_IE_Msk);

	NVIC_DisableIRQ(SC012_IRQn);
    psDev->errno = 0;
	/* enable SmartCard INT NVIC */
	NVIC_EnableIRQ(SC012_IRQn);

	/* in defalut, all timer 24 or 8 or 8 turn on */
	SC_TimerSelect(psDev, SC_CTL_TMR_SEL_24_8_8_BITS);


	//psDev->CardCapabilities.etu = 93;			// for APDU test card
	//psDev->CardCapabilities.GT = 12;			// for APDU test card
	//psDev->CardCapabilities.Protocol.Selected = SCARD_PROTOCOL_RAW;	// for APDU test card

	/* Get SC clock */
    psDev->clock = SC_GetSmartCardClockSourceFreq(psDev->base);
    
	if(psDev->base==SC0)
		psDev->clock = psDev->clock/1000/((SYSCLK->CLKDIV1&SYSCLK_CLKDIV1_SC0_N_Msk)+1);
	else if(psDev->base==SC1)
		psDev->clock = psDev->clock/1000/(((SYSCLK->CLKDIV1&SYSCLK_CLKDIV1_SC1_N_Msk)>>SYSCLK_CLKDIV1_SC1_N_Pos)+1);
	else if(psDev->base==SC2)
		psDev->clock = psDev->clock/1000/(((SYSCLK->CLKDIV1&SYSCLK_CLKDIV1_SC2_N_Msk)>>SYSCLK_CLKDIV1_SC2_N_Pos)+1);       

	//printf("SC clock	= %d KHz \n", psDev->clock);
	//psDev->clock = 6000;	// 6 Mhz
	//psDev->clock = 4000;	// 4 Mhz		
	//psDev->clock = 3375;	// 3.375 Mhz		
	//psDev->clock = 2000;	// 2 Mhz
	psDev->CardCapabilities.Fl = 1;
	psDev->CardCapabilities.Dl = 1;
	psDev->CardCapabilities.N = 0;	

	psDev->CardCapabilities.T0.WI = 10;

	psDev->CardCapabilities.T1.IFSC = 32;
	psDev->CardCapabilities.T1.CWI = SC_T1_CWI_DEFAULT;
	psDev->CardCapabilities.T1.BWI = SC_T1_BWI_DEFAULT;


	SC_LEAVE();

}


/**
  * @brief	    To do the activation sequence and start receiving and parsing ATR information. 
  * @param[in]	psDev 		The pointer of data structure of smartcard information
  * @param[in]	resettype	Type of reset 
  *                         - SC_COLDRESET 
  *                         - SC_WARMRESET
  * @retval     The result status of check ATR information
  * @details    To do the activation sequence and start receiving and parsing ATR information.
  */
static int32_t SC_ActivateCard(S_SC_DEV_T *psDev, int resettype)
{
	SC_T *SC = psDev->base;
	uint32_t u32SCPort = 0;
    
	SC_ENTER();
    
    if(psDev->base==SC0)
        u32SCPort = 0;
    else if(psDev->base==SC1)
        u32SCPort = 1;
    else if(psDev->base==SC2)
        u32SCPort = 2;
        
	SC_ResetReader(psDev);	
	
	// TODO: set the default ETU clock & Interrupt enable & close all timer
	SC_SetBaudrate(psDev, 1, 1);	 // default 1 ETU == 372 cycles
	
	memset(&psDev->CardCapabilities, 0, sizeof(S_SC_SCARD_CARD_CAPABILITIES));
	memset(&psDev->T0, 0, sizeof(S_SC_T0_DATA));
	memset(&psDev->T1, 0, sizeof(S_SC_T1_DATA));
	// stop timer0-2	
	SC_TimerStop(psDev, (uint32_t)(SC_TIMER0 | SC_TIMER1 |SC_TIMER2));   
	

	/* reset the global variable for receiving ATR */
	g_au32AtrLen[u32SCPort]=0, g_au32AtrRemain[u32SCPort]=2/* TS & T0 */;
	g_ai32IfbyteFlag[u32SCPort]=-1/* interface bytes flag */, g_ai32Tck[u32SCPort]=0, g_ai32Ifcount[u32SCPort]=0;
	g_ai32AtrTime[u32SCPort] = SC_ATR_TOTAL_TIME;
	g_ai32AtrCheckTime[u32SCPort] = 0;
	g_ai32AtrFinalChk[u32SCPort] = 0;
	g_ai32AtrTotalTimeStartFlag[u32SCPort] = 0;	
	/* read ATR */
	psDev->CardCapabilities.ATR.Length = 0;

#ifndef SC_SEQ_MANUAL
	// wait for 40000 clks after pull RST high
	/* [ISO 7816-3] */
	//SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE3_DC_INITIAL_END, (40000/372) + 1);
	//SC_TimerStart(psDev, SC_TIMER0);	
	// wait for 42000 clks after pull RST high
	/* [EMV 2000] */
	SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE3_DC_INITIAL_END, (42000/372) + 1);
	SC_TimerStart(psDev, SC_TIMER0);	
#endif	
	
	// TODO: Do the activation or warm-reset sequence 
	if(resettype == SC_COLDRESET)
		SC_ActivationCmd(psDev);
	else if(resettype == SC_WARMRESET)
		SC_WarmResetCmd(psDev);

	// start IST to receive ATR
	psDev->errno = 0;
	psDev->op_state = SC_OP_ATR_READ;

	/* set timimg control */
	// if initial end is done, set the time check for waiting time
	//while( SC->ALTCTL_BITS.ACT_EN==1 ) ;
	//SC_TimerStop(SC_TIMER0);
	//SC_TimerCountSet(SC_TIMER0, SC_TMR_MODE0_DC_RELOAD_S_S, 9600);  // default waiting time 9600 ETUs
	//SC_TimerStart(SC_TIMER0);

	

#if 0	/* It used the polling method to receive ATR bytes */

	// No worry receive error here, it will be caught while parsing ATR 

    SC->IER&= ~SC_IER_RDA_IE_Msk;	// disable RDA interrupt	

	atrbuffer = psDev->CardCapabilities.ATR.Buffer;
	while((psDev->errno !=  SC_ERR_TIME0OUT) && remain) 
	{  
        if( SC->ISR & (SC_ISR_TMR0_IS_Msk|SC_ISR_TMR1_IS_Msk|SC_ISR_TMR2_IS_Msk) )	// Timer Time-out flag
		{
			break;	// Time out 'cos we read SCSR to see if data ready, sometimes we'll miss timeout interrupt!
		} 
        else if((SC->ISR&SC_ISR_RDA_IS_Msk)==SC_ISR_RDA_IS_Msk)	
		{		
			if(remain==2) 
			{
				SC_TimerStop(psDev, SC_TIMER0);
				SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC_RELOAD_S_S, 9600);	// default waiting time 9600 ETUs
				SC_TimerStart(psDev, SC_TIMER0);
			}
			atrbuffer[length] = SC_GET_ONE_BYTE();
			//printf("%02x\n", atrbuffer[length]);
			remain--;
			offset--;
			if(length == 0) 
			{
				if(atrbuffer[length] == 0x3f) 
				{
					printf("Inverse Convention Card...\n");
				}
			}
			else if(length == 1) 
			{
				remain += (atrbuffer[length] & 0xf); // Historical byte
				offset = 0; // T0 contains Y(x) as well
			}
			if((offset == 0)) 
			{
				
				if(atrbuffer[length] & 0x10)
				{
					++remain; ++offset;
				}
				if(atrbuffer[length] & 0x20)
				{
					++remain; ++offset;
				}
				if(atrbuffer[length] & 0x40)
				{
					++remain; ++offset;
				}
				if(atrbuffer[length] & 0x80)
				{
					++remain; ++offset;
					if((tckflag == 0) && (length != 1) && ((atrbuffer[length] & 0xf) != 0)) 
					{
						++remain; //tck exist
						tckflag = 1;
					}	
				}
				else {
					/* Here, it's special case for APDU test card */
					if((tckflag == 0) && (length != 1) && ((atrbuffer[length] & 0xf) != 0)) 
					{
						++remain; //tck exist
						tckflag = 1;
					}
					offset = -1;									
				}
			}	
			
			length++;
			if(length >= 33)
				break;				
		}
	}

	psDev->CardCapabilities.ATR.Length = length;
    SC->IER|= SC_IER_RDA_IE_Msk;    // Enable RDA interrupt
	psDev->op_state = SC_OP_NOP;
	SC_TimerStop(psDev, SC_TIMER0);
	
#else
	// TODO: wait the ISR to receive ATR done.
    while(psDev->op_state==SC_OP_ATR_READ ) {
		// [2011.11.28]
		/* EMV Certification */
		if((psDev->errno == SC_ERR_TIME2OUT) || 
           (psDev->errno == SC_ERR_TIME0OUT) ||
           ((SC->PINCSR&SC_PINCSR_CD_PIN_ST_Msk) == 0))  // 2012-04-12 Add time0out avoid user insert card in wrong direction  --ya
			break;
	}
	if(psDev->errno < 0) {
		// [2011.11.28]
		/* EMV Certification */
		if(psDev->errno == SC_ERR_TIME2OUT || psDev->errno == SC_ERR_TIME0OUT)  // 2012-04-12 Add time0out avoid user insert card in wrong direction  --ya
			SC_DeactivationCmd(psDev);
		printf("Failed to read ATR..Error Msg:%s \n", SC_ErrMsg(psDev->errno));
	}
	else
#endif


#ifdef SC_ATR_DEBUG
	{
		int32_t j;
		printf("ATR : Length : %d\n", psDev->CardCapabilities.ATR.Length);
		for( j = 0; j < psDev->CardCapabilities.ATR.Length; j ++){
			printf("%x ", psDev->CardCapabilities.ATR.Buffer[j]);
		}
		printf("\n");
	}
#endif

	SC_LEAVE();

	return psDev->errno;
}


/**
  * @brief	    Parse ATR characters and check its integrity
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @retval     The result status of parsing process
  *			    - SC_ERR_UNSUPPORTEDCARD		Card is not supported
  *			    - SC_STATUS_SUCCESS			    Success
  *			    - SC_ATR_ERR_UNRECOGNIZED_MEDIA	Invalid to the length of ATR or TS byte or ATR checksum or Fi/Di
  *			    - SC_ATR_ERR_INVALID_PARAMETER	    Content of ATR has wrong parameter 
  * @details    Parse ATR characters and check its integrity
  */
static int32_t SC_ParseATR(S_SC_DEV_T * psDev, int resettype)
{
	int32_t i, retval;
	uint8_t td;
	uint8_t *atr = psDev->CardCapabilities.ATR.Buffer;
	uint8_t /*N,*/ T, Fi, Di;
	unsigned long protocolTypes = 0;

	struct {
		uint8_t data;
		uint8_t present;
	} ibyte[4][4];

	SC_ENTER();

	memset(&ibyte, 0, sizeof(ibyte));

	atr++;	// skip: TS->T0
	td = *atr++;

	i = 0;

	while(1)
	{

		/* TAi present */
		if( td & 0x10){
			ibyte[i][SC_ATR_INTERFACE_BYTE_TA].data = *atr++;
			ibyte[i][SC_ATR_INTERFACE_BYTE_TA].present = 1;
		}

		/* TBi present */
		if( td & 0x20){
			ibyte[i][SC_ATR_INTERFACE_BYTE_TB].data = *atr++;
			ibyte[i][SC_ATR_INTERFACE_BYTE_TB].present = 1;
		}

		/* TCi present */
		if( td & 0x40){
			ibyte[i][SC_ATR_INTERFACE_BYTE_TC].data = *atr++;
			ibyte[i][SC_ATR_INTERFACE_BYTE_TC].present = 1;
		}

		/* TDi present */
		if( td & 0x80){
			ibyte[i][SC_ATR_INTERFACE_BYTE_TD].data = *atr++;
			ibyte[i][SC_ATR_INTERFACE_BYTE_TD].present = 1;
			td = ibyte[i][SC_ATR_INTERFACE_BYTE_TD].data;
			protocolTypes |= 1 << (td & 0x0F);
			i++;
		}
		else
			break;
		
	}


#if SC_EMV_ATR_CHECK
	/**********************************************************************************************************************/
	/* Checking the integrity of ATR, this process meets EMV 4.2 specification */
	/* Reject ATR if TA1 is not int the range '11' to '13' */
	if(ibyte[0][SC_ATR_INTERFACE_BYTE_TA].present == 1)
	{
		if(ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data < 0x11 || ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data > 0x13)
			return SC_ATR_ERR_INVALID_PARAMETER;
	}
	
	/* In response to the cold-reset, TB1 only could be 0x00 */
	if(resettype == SC_COLDRESET) 
	{
		if(ibyte[0][SC_ATR_INTERFACE_BYTE_TB].present == 1)
			if(ibyte[0][SC_ATR_INTERFACE_BYTE_TB].data != 0x00)
				return SC_ATR_ERR_INVALID_PARAMETER;
		if(ibyte[0][SC_ATR_INTERFACE_BYTE_TB].present == 0)
			return SC_ATR_ERR_INVALID_PARAMETER;
	}

	/* Reject ATR containing TB2 */
	if(ibyte[1][SC_ATR_INTERFACE_BYTE_TB].present == 1)
		return SC_ATR_ERR_INVALID_PARAMETER;


	/* ATR must contain TB3 in T=1 */
	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T1)
	{
		if(ibyte[2][SC_ATR_INTERFACE_BYTE_TB].present == 0)
			return SC_ATR_ERR_INVALID_PARAMETER;
	}
	
	/* Bit [5] of TA2 must be equal to 0x0 */
	if(ibyte[1][SC_ATR_INTERFACE_BYTE_TA].present == 1)
	{
		if((ibyte[1][SC_ATR_INTERFACE_BYTE_TA].data&0x10) == 0x10)
			return SC_ATR_ERR_INVALID_PARAMETER;
	}

	/* Reject an ATR that TC2 is equal to 0x00 */
	if(ibyte[1][SC_ATR_INTERFACE_BYTE_TC].present == 1 && ibyte[1][SC_ATR_INTERFACE_BYTE_TC].data == 0x00)
		return SC_ATR_ERR_INVALID_PARAMETER;
	

	/* TD1's l.s. nibble must be 0x0 or 0x1 */
	if(ibyte[0][SC_ATR_INTERFACE_BYTE_TD].present == 1)
	{
		if((ibyte[0][SC_ATR_INTERFACE_BYTE_TD].data&0xF) > 0x1)
		{
			return SC_ATR_ERR_INVALID_PARAMETER;
		}
	}

	/* TD2's l.s. nibble must be 0x1 or 0xE if TD1's l.s. nibble is 0x0 */
	if(ibyte[1][SC_ATR_INTERFACE_BYTE_TD].present == 1)
	{
		if((ibyte[1][SC_ATR_INTERFACE_BYTE_TD].data&0xF)!=0x1 && (ibyte[1][SC_ATR_INTERFACE_BYTE_TD].data&0xF)!=0xE)
			return SC_ATR_ERR_INVALID_PARAMETER;

		if((ibyte[1][SC_ATR_INTERFACE_BYTE_TD].data&0xF) == 0xE)
		{
			if((ibyte[0][SC_ATR_INTERFACE_BYTE_TD].data&0xF) != 0x0)
				return SC_ATR_ERR_INVALID_PARAMETER;
		}		
	}

	/* Reject TA3 having a value in the range 0x0~0xF or 0xFF */
	if(ibyte[2][SC_ATR_INTERFACE_BYTE_TA].present == 1)
	{
		if(ibyte[2][SC_ATR_INTERFACE_BYTE_TA].data >= 0x0 && 
			ibyte[2][SC_ATR_INTERFACE_BYTE_TA].data <= 0xF)
		{
			return SC_ATR_ERR_INVALID_PARAMETER;
		}
		if(ibyte[2][SC_ATR_INTERFACE_BYTE_TA].data == 0xFF)
		{
			return SC_ATR_ERR_INVALID_PARAMETER;
		}
	}

	/* Reject ATR not containing TB3 or BWI greater than 4 or CWI greater than 5 */
	/* And reject ATR if fitting the formula : 2 to the power of CWI is equal or less than (N+1) */
	if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T1)
	{
		if(ibyte[2][SC_ATR_INTERFACE_BYTE_TB].present == 1)
		{
			if(((ibyte[2][SC_ATR_INTERFACE_BYTE_TB].data&0xF0)>>4) > 0x4)
				return SC_ATR_ERR_INVALID_PARAMETER;

			if((ibyte[2][SC_ATR_INTERFACE_BYTE_TB].data&0xF) > 0x5)
				return SC_ATR_ERR_INVALID_PARAMETER;

			i = 1;
			retval = (ibyte[2][SC_ATR_INTERFACE_BYTE_TB].data&0xF);
			while(retval--)
				i *= 2;
			/* if TC1 is equal to 0xFF, N as -1 that is always valid */
			if(ibyte[0][SC_ATR_INTERFACE_BYTE_TC].data!=0xFF)
				if( i <= (ibyte[0][SC_ATR_INTERFACE_BYTE_TC].data+1))
					return SC_ATR_ERR_INVALID_PARAMETER;
			
		} else return SC_ATR_ERR_INVALID_PARAMETER;
	}

	/* Reject ATR if TC3 is not equal to 0x00 */
	if(ibyte[2][SC_ATR_INTERFACE_BYTE_TC].present == 1)
	{
		if(ibyte[2][SC_ATR_INTERFACE_BYTE_TC].data != 0x00)
		{
			return SC_ATR_ERR_INVALID_PARAMETER;
		}
	}
	/* End of checking the integrity of ATR */
	/**********************************************************************************************************************/
#endif	

	Fi = Di = 1;

	/* set Fi and Di if TA1 present */
	if(ibyte[0][SC_ATR_INTERFACE_BYTE_TA].present)
	{
		Fi = (ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data >> 4) & 0x0f;
		Di = ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data  & 0x0f;
	}

	//N = 0;

	//if(ibyte[0][SC_ATR_INTERFACE_BYTE_TC].present)
	//	N = ibyte[0][SC_ATR_INTERFACE_BYTE_TC].data;

	T = 0;

	/* check TA2 indicates which mode in the card */
	/* in specific mode */
	if(psDev->CurrentState == SC_STAUS_SPECIFIC)
	{	
		T = ibyte[1][SC_ATR_INTERFACE_BYTE_TA].data & 0x0f;

		if(ibyte[1][SC_ATR_INTERFACE_BYTE_TA].data & 0x10)  /* Bit5 = 1, using default value */
		{
			Fi = 1; Di= 1;		/* default value */
		}

		if(SC_MatchReader(ClockRateConversion[Fi].F, BitRateAdjustment[Di].DNumerator) == 0)	/* reader supported mode? */
		{	   
			/* do nothing, */
			/* Match, reader is ready to work */
			;
		}
		else
		{
			if(!(ibyte[1][SC_ATR_INTERFACE_BYTE_TA].data & 0x80))	/* Bit8 indicate if being capable to change mode */
			{		  
				retval = SC_WarmReset(psDev);	/* change to negotiable mode */
				if(retval != 0)
					return retval;
				//Fi = 1; Di = 1; T = 0;
				//retval = SC_DoPPS(psDev, Fi, Di, T);	/* parameter and protocol select */
				//if(retval != 0)
				//	return retval;
			}
			//else		// mask for APDU test card
			//	return SC_ERR_UNSUPPORTEDCARD;
		}

	}

	/* in negotiable mode */
	else if(psDev->CurrentState == SC_STAUS_NEGOTIABLE)	  
	{
		if (ibyte[0][SC_ATR_INTERFACE_BYTE_TD].present)	 // use "first offered transmission protocol"
			T = ibyte[0][SC_ATR_INTERFACE_BYTE_TD].data & 0x0f;
		else
			T = 0;		// means protocol T=0

		/* if the values are the default, no PPS should be done */
		if( (Fi==0) && (Di==1) ) 
		{	   
			if(SC_MatchReader(ClockRateConversion[Fi].F, BitRateAdjustment[Di].DNumerator) == 0)	/* reader supported mode? */
			{	   
				/* do nothing, */
				/* Match, reader is ready to work */
				;
			} else return SC_ERR_UNSUPPORTEDCARD;
		}
		else
		{
#if 1		// mask for INQ test tool
			Fi = Di = 1;
			retval = SC_DoPPS(psDev, Fi, Di, T);		/* parameter and protocol select */
			if(retval < 0) 
			{	/* PPS failed */
				printf("DoPPS is failed!!\n");
				if(retval == SC_ERR_CARD_REMOVED)
					return(SC_ERR_CARD_REMOVED);
			} 
			else 
			{
				psDev->pps_complete = 1;                
				SC_UpdateCardCapabilities(psDev);
			}
#else
			/* Update ATR's Fi/Di value and the system timing  */
			atr = psDev->CardCapabilities.ATR.Buffer;
			atr++;		// TS->T0
			atr++;		// T0->TA1
			*atr = 0x11;	// Fi = Di = 1
			/* Update TCK if exists */
			if (protocolTypes & ~1) 
			{
				atr = psDev->CardCapabilities.ATR.Buffer;
				atr[psDev->CardCapabilities.ATR.Length-1] = 0x00;
				for(i=1; i<(psDev->CardCapabilities.ATR.Length-1); i++)
					atr[psDev->CardCapabilities.ATR.Length-1] ^= atr[i];
			}
			psDev->CardCapabilities.Protocol.Selected = SC_PROTOCOL_T0;
			SC_UpdateCardCapabilities(psDev);
#endif
		}
		
	}

#if 0
	/* First TA for T=15 */
	if( (ibyte[0][SC_ATR_INTERFACE_BYTE_TA].present) && (ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data&0xF)==0xF)
	{
		switch ((ibyte[0][SC_ATR_INTERFACE_BYTE_TA].data & 0xC0)>>6)
		{
			case 0:
				psDev->clock_stop_level = SC_CLK_PIN_STOP_NOT_SUPPORT;
				break;
			case 1:
				psDev->clock_stop_level = SC_CLK_PIN_STOP_LOW;
				break;
			case 2:
				psDev->clock_stop_level = SC_CLK_PIN_STOP_HIGH;
				break;
			case 3:
				psDev->clock_stop_level = SC_CLK_PIN_STOP_NO_PREFE;
				break;
		}
	}
#endif

	SC_SetReaderParameter(psDev);


	SC_LEAVE();

	return SC_STATUS_SUCCESS;
}

/**
  * @brief	    The Cold-reset process that makes activation sequence and gets ATR.
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @retval     The result status of check procedure
  *			    - SC_STATUS_SUCCESS             Success
  *			    - SC_ATR_ERR_UNRECOGNIZED_MEDIA	Invalid to the length of ATR or TS byte or ATR checksum or Fi/Di
  *			    - SC_ERR_UNSUPPORTEDCARD		Card is not supported
  * 		    - SC_ATR_ERR_INVALID_PARAMETER	    Content of ATR has wrong parameter	
  * 		    - SC_ATR_ERR_INVALID_TCK 		    Checksum of ATR is wrong
  * 		    - SC_ERR_AUTOCONVENTION		    TS byte is wrong
  * 		    - SC_ERR_TIME0OUT 			    Time out
  * 		    - SC_ERR_READ 				    Parity error or others during reading ATR	 
  * @details    The Cold-reset process that makes activation sequence and gets ATR.
  */
int32_t SC_ColdReset(S_SC_DEV_T *psDev)
{
	SC_ENTER();

	//SC_DeactivationCmd(psDev);	   // de-activation
	//SC_PowerOff(psDev);

	SC_VoltageConfig(psDev);
	psDev->errno = SC_ActivateCard(psDev, SC_COLDRESET);

	if(psDev->errno != 0)
		return (psDev->errno);

	psDev->pps_complete = 0;
	psDev->errno = SC_UpdateCardCapabilities(psDev);

	if(psDev->errno != 0)
		return (psDev->errno);

	psDev->errno = SC_ParseATR(psDev, SC_COLDRESET);

	if(psDev->errno != 0)
		printf("SMARTCARD_ColdReset:: ParseATR..Error Msg:%s \n", SC_ErrMsg(psDev->errno));

	psDev->openflag = 1;
	
	SC_LEAVE();
	return (psDev->errno);
}


/**
  * @brief	    The Warm-reset process that makes warm-reset sequence and gets ATR.
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @retval     The result status of check procedure
  *			    - SC_STATUS_SUCCESS				Success
  *			    - SC_ATR_ERR_UNRECOGNIZED_MEDIA	Invalid to the length of ATR or TS byte or ATR checksum or Fi/Di
  *			    - SC_ERR_UNSUPPORTEDCARD		Card is not supported
  * 		    - SC_ATR_ERR_INVALID_PARAMETER	    Content of ATR has wrong parameter	
  * 		    - SC_ATR_ERR_INVALID_TCK 		    Checksum of ATR is wrong
  * 		    - SC_ERR_AUTOCONVENTION		    TS byte is wrong
  * 		    - SC_ERR_TIME0OUT 			    Time out
  * 		    - SC_ERR_READ 				    Parity error or others during reading ATR  
  * @details    The Warm-reset process that makes warm-reset sequence and gets ATR.
  */
int32_t SC_WarmReset(S_SC_DEV_T *psDev)
{

	SC_ENTER();	

	psDev->errno = SC_ActivateCard(psDev, SC_WARMRESET);

	if(psDev->errno != 0)
		return (psDev->errno);
	
	psDev->pps_complete = 0;	
	psDev->errno = SC_UpdateCardCapabilities(psDev);

	if(psDev->errno != 0)
		return (psDev->errno);

	psDev->errno = SC_ParseATR(psDev, SC_WARMRESET);

	if(psDev->errno != 0)
		printf("SMARTCARD_WarmReset:: ParseATR..Error Msg:%s \n", SC_ErrMsg(psDev->errno));
	
	SC_LEAVE();
	return (psDev->errno);
	
}

/**
  * @brief	    The selection of transmission parameters and protocol
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @param[in]	Fi		Clock rate conversion interger from card
  * @param[in]	Di		Baud rate adjustment integer from card
  * @param[in]	T		Transmission protocol
  * @retval     The result of processes. Status has many situations in writing/reading procedure.
  * @details    The selection of transmission parameters and protocol
  *			
  */
int32_t SC_DoPPS(S_SC_DEV_T *psDev, int32_t Fi, int32_t Di, int32_t T)
{
	uint8_t buf[4];
	uint8_t *rbuf;
	int32_t len = 4, rPck=0;
	SC_T *SC = psDev->base;	

	SC_ENTER();

	buf[0] = 0xff;								 /* PPSS: PPS request use 0xFF */
	buf[1] = 0x10 |(T & 0x0f);					/* PPS0: PPS1 will be transmited + T transmission protocol */
	buf[2] = ((Fi<<4)&0xf0) | (Di & 0x0f);	   /* PPS1: */
	buf[3] = (buf[0] ^ buf[1] ^ buf[2]);		/* PCK */

	SC_ClearFIFO(psDev);  // clear FIFO

	printf("Sending PPS : %x %x %x %x\n",
				buf[0], buf[1], buf[2], buf[3]);
	
	SC_TimerStop(psDev, (uint32_t)(SC_TIMER0 | SC_TIMER1 |SC_TIMER2));   // stop timer0-2
	

	// Waiting time check
	// the waiting time of PPS is fixed at 9600 ETUs
	SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE7_DC_RELOAD_S_S, 9600); 
	SC_TimerStart(psDev, SC_TIMER0);


	/* Start to do PPS exchange */
	psDev->errno = 0;
	psDev->snd_buf = buf;
	psDev->snd_len = len;
	psDev->snd_pos = 0;
	psDev->op_state = SC_OP_WRITE;
    SC->IER|= SC_IER_TBE_IE_Msk;
	while(psDev->op_state == SC_OP_WRITE && !(psDev->errno));
	psDev->snd_buf = NULL;

	if(psDev->errno != 0) {
		printf("SMARTCARD_DoPPS:: PPS Write..Error Msg:%s \n", SC_ErrMsg(psDev->errno));
		return psDev->errno;
	}

	/* Read Procedure bytes */
	psDev->errno = 0;
	rbuf = psDev->rcv_buf;
	psDev->rcv_pos = 0;
	psDev->rcv_len = len;
	psDev->rcv_cnt = 0;
	psDev->op_state = SC_OP_READ;
	//while(psDev->op_state == SC_OP_READ /*&& !(psDev->bCardRemoved)*/ && !(psDev->errno));
    while(psDev->op_state == SC_OP_READ && (psDev->bCardRemoved == SC_STAUS_PRESENT) && !(psDev->errno));
	
	SC_TimerStop(psDev, SC_TIMER0);	// Stop timer

	if(psDev->errno != 0) {
		printf("SMARTCARD_DoPPS:: PPS Read..Error Msg:%s \n", SC_ErrMsg(psDev->errno));
		return psDev->errno;
	}

	printf("Received PPS : %x %x %x %x\n",
				rbuf[0], rbuf[1], rbuf[2], rbuf[3]);
	
	if(rbuf[0] != buf[0])	/* PPSS */
		return SC_PROTOCOL_PPS_INVALID;

	rPck = rbuf[0];
	if( (rbuf[1]&0x0f) == (buf[1] &0x0f) &&		/* success */  /* PPS0 */
		((rbuf[1] & 0xf0) == 0x10 ||(rbuf[1] & 0xf0) == 0x00))
	{
		rPck ^= rbuf[1];
		
		printf("PPS Request Success, \n"/*now baudrate is %d\n", 9600 * Dtab[Di]*/);
	}
	else 
		return SC_PROTOCOL_PPS_INVALID;

	if (rbuf[2] == buf[2])	/* PPS1 */
		rPck ^= rbuf[2];
	else 
		return SC_PROTOCOL_PPS_INVALID;

	if (rbuf[3] != rPck)  /* PCK */
		return SC_PROTOCOL_PPS_INVALID;


	SC_LEAVE();
	return SC_STATUS_SUCCESS;
}


/**
  * @brief	    ATR information, which be read after activation process 
  * @param[in]	psPortno	Indicate which port to be used
  *                         - SC0
  *                         - SC1
  *                         - SC2 
  * @param[in]	buf 	The pointer of received buffer by application
  * @param[in]	length	The data length we needed to read
  * @retval     The data length of received ATR buffer
  * @details    ATR information, which be read after activation process 
  */
int32_t SC_GetATRBuffer(SC_T *psPortno, uint8_t *buf, int16_t length)
{
	S_SC_DEV_T *psDev;
	int32_t port = 0;

	//assert_param(SC_CHECK_SC_PORT(psPortno));

	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
	
	psDev =  (S_SC_DEV_T *)((uint32_t)&g_asScDevice[port]);

	if(psDev->openflag == 0)
		return(/*SC_EIO*/ 0);	 // upper layer could get confused between length and error code, so return 0 instead.

	memcpy(buf, psDev->CardCapabilities.ATR.Buffer, 
		(length<psDev->CardCapabilities.ATR.Length)?length:psDev->CardCapabilities.ATR.Length);

	return psDev->CardCapabilities.ATR.Length;
}

/**
  * @brief	    This function could activate the smartcard device and use the appropriate the voltage.
  * @param[in]	psPortno	Indicate which port to be used
  *                         - SC0
  *                         - SC1
  *                         - SC2 
  * @retval     The result status of open procedure
  *             - SC_STATUS_SUCCESS			Successful											 
  * 		    - SC_EBUSY					Interface already opened
  * 		    - SC_EIO						Card removed or unsupported card
  * 		    - SC_ATR_ERR_INVALID_PARAMETER	Content of ATR has wrong parameter	
  * 		    - SC_ATR_ERR_INVALID_TCK 		Checksum of ATR is wrong
  * 		    - SC_ERR_AUTOCONVENTION		TS byte is wrong
  * 		    - SC_ERR_TIME0OUT 			Time out
  * 		    - SC_ERR_READ 				Parity error or others during reading ATR
  * @details    This function could activate the smartcard device and use the appropriate the voltage.
  *             If any procedure is failed, do de-activation to end the process.
  */
int32_t SC_Open(SC_T *psPortno)
{
	int32_t retval = SC_STATUS_SUCCESS, i, port = 0;
	S_SC_DEV_T *psDev;
	SC_T *SC;
	
	SC_ENTER();

	//assert_param(SC_CHECK_SC_PORT(psPortno));

	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
	
	psDev = (S_SC_DEV_T *)((uint32_t)&g_asScDevice[port]);
	
	if( psDev->openflag != 0 )		/* a card slot can open only once */
		return(SC_EBUSY);
			
	psDev->base = psPortno;
	SC = psPortno;

	SC_ResetReader(psDev);		// initiate some parameters
	
	/* point to receive buffer */
	psDev->rcv_buf = (uint8_t *)&g_au8PortRxBuf[port];//(uint8_t *)malloc(SC_MAX_BUF_LEN * sizeof(uint8_t));
	psDev->snd_buf = (uint8_t *)&g_au8PortTxBuf[port];

	if((psDev->bCardRemoved==SC_STAUS_ABSENT) || (psDev->bCardRemoved==SC_STAUS_UNKNOWN)) 
	{	
		printf("Card missing\n");
		retval = SC_EIO;
		goto _exit_open;
	} 
	else 
	{
		/* default: 1.8V start */
		psDev->voltage = SC_ISO_OPERATIONCLASS_C;
	
		for( i = 0; i < 1/*3*/; i++)
		{
			if((retval = SC_ColdReset(psDev)) != 0)
			{
				if(i==1)
					psDev->voltage = SC_ISO_OPERATIONCLASS_B;  // 1.8V failed, use 3V
				if(i==2)
					psDev->voltage = SC_ISO_OPERATIONCLASS_A;  // 3V failed, use 5V
				continue;
			}		
			break;
		}

		if(retval != 0) 
		{
			// TODO: disable Group mask
			printf("Cold-Reset is failed...\n");
			SC->IER = 0;		// clear all interrupt source
            SC->IER|= SC_IER_CD_IE_Msk; // Keep the card detection interrupt. Modified by SM
			//psDev->bCardRemoved = 0xFFFFFFFE;
			//NVIC_DisableIRQ(SC012_IRQn); /* disable NVIC interrupts */
			//SC_DeactivationCmd( psDev );		 // de-activation
			//SMARTCARD_PowerOff();
			//psDev->errno = SC_ERR_UNSUPPORTEDCARD;
			//retval = psDev->errno;
		}		
	}

_exit_open:
	psDev->openflag = 1;
	psDev->errno = 0;  // clear error code happened during cold reset
		
	printf("Open Done\n");

	SC_LEAVE();
			
	return retval;	

}


/**
  * @brief	    Disable interrupt and do de-activation
  * @param[in]	psPortno	Indicate which port to be used
  *                         - SC0
  *                         - SC1
  *                         - SC2 
  * @retval     The error code.
  *			    - SC_STATUS_SUCCESS		Success
  * @details    Disable interrupt and do de-activation
  */
int32_t SC_Close(SC_T *psPortno)
{
	S_SC_DEV_T *psDev;
	SC_T *SC;
	int32_t port = 0;

	SC_ENTER();

	//assert_param(SC_CHECK_SC_PORT(psPortno));
	SC = psPortno;
	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;
		
	psDev = (S_SC_DEV_T *)((uint32_t)&g_asScDevice[port]);
	//if(psDev->openflag == 0)
	//	return(SC_EIO);

	// TODO: disable group mask

	/* Disable NVIC SmartCard interrupt */ 
	NVIC_DisableIRQ(SC012_IRQn);
	
	SC_DeactivationCmd( psDev );	   // de-activation
	//SC_PowerOff();

	SC->IER = 0;		// disable all interrupt

	//free(psDev->rcv_buf);
	
	psDev->openflag = 0;

	SC_LEAVE();

	return SC_STATUS_SUCCESS;
}

void SC012_IRQHandler(void)
{
	uint32_t pincsr;
	uint8_t *atrbuffer;
    uint32_t u32Reg;
    uint32_t u32SCPort = 0;
	SC_T *SC = SC0;
	S_SC_DEV_T *psDev= (S_SC_DEV_T *)(uint32_t)&g_asScDevice[0];
            
    u32Reg = SYSINT->IRQSRC[22];
    if(u32Reg&BIT0)
    {
        u32SCPort = 0;
        SC = SC0;    
    }    
    else if(u32Reg&BIT1)
    {
        u32SCPort = 1;    
        SC = SC1;
    }
    else if(u32Reg&BIT2)
    {
        u32SCPort = 2;
        SC = SC2;                
    }
	// TODO: check group mask to decide the interface
	psDev= (S_SC_DEV_T *)(uint32_t)&g_asScDevice[u32SCPort];

	atrbuffer = psDev->CardCapabilities.ATR.Buffer;

	//SC_ISTDEBUG("Interrupt ISR : SC_ISR : [%02x] \n", SC->ISR);		

	if((SC->ISR&SC_ISR_CD_IS_Msk)==SC_ISR_CD_IS_Msk)		/* toggle detect by card */
	{	
		SC_ISTDEBUG("IST[%d]: Card Present Int : SC_ISR : [%x]\n", u32SCPort, SC->ISR);
        SC->ISR = SC_ISR_CD_IS_Msk;// clear CD_IS bit
		pincsr = SC->PINCSR;
		if((pincsr&(SC_PINCSR_CD_REM_F_Msk|SC_PINCSR_CD_INS_F_Msk)) == (SC_PINCSR_CD_REM_F_Msk|SC_PINCSR_CD_INS_F_Msk))    // CD_INS_F & CD_REM_F both trigger
		{
			SC_ISTDEBUG("IST[%d]: Card status is not sure\n",u32SCPort);
			// [2011.11.30]
            /* protect writing operation forever */
            SC->IER&= ~SC_IER_TBE_IE_Msk;
            SC->PINCSR|= (SC_PINCSR_CD_INS_F_Msk|SC_PINCSR_CD_REM_F_Msk);
			psDev->bCardRemoved = SC_STAUS_UNKNOWN;
			psDev->errno = SC_ERR_CARD_REMOVED;
            psDev->op_state = SC_OP_NOP;
            if(psDev->openflag)
            {
#ifdef SC_SEQ_MANUAL
				SC_DeactivationCmd( psDev );       // de-activation, use HW auto de-activation
#endif	
				SC_ClearFIFO(psDev);			// clear FIFO
	            SC_TimerAllStop(psDev);
				psDev->errno = SC_ERR_CARD_REMOVED;
				psDev->op_state = SC_OP_NOP;
				psDev->openflag = 0;
				psDev->CardCapabilities.ATR.Length = 0;  
                SC->IER&= ~SC_IER_TBE_IE_Msk; 			   
				return ;    // leave ISR            
            }
            
		}
        else if( (pincsr&SC_PINCSR_CD_INS_F_Msk) && 
                 (((SC->PINCSR&SC_PINCSR_CD_PIN_ST_Msk)>>SC_PINCSR_CD_PIN_ST_Pos)
                    ==((SC->PINCSR&SC_PINCSR_CD_LEV_Msk)>>SC_PINCSR_CD_LEV_Pos)))  // CD_INS_F 
		{
            SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | SC_PINCSR_CD_INS_F_Msk;// clear CD_INS_F flag
			SC_ISTDEBUG("IST[%d]: Card Inserted\n",u32SCPort);

			psDev->bCardRemoved = SC_STAUS_PRESENT;
			if(g_pfnSCCallBack_CardPresent[u32SCPort]) g_pfnSCCallBack_CardPresent[u32SCPort]();
		}
        else if( (pincsr&SC_PINCSR_CD_REM_F_Msk) && 
                 (((SC->PINCSR&SC_PINCSR_CD_PIN_ST_Msk)>>SC_PINCSR_CD_PIN_ST_Pos)
                    !=((SC->PINCSR&SC_PINCSR_CD_LEV_Msk)>>SC_PINCSR_CD_LEV_Pos)))  // CD_REM_F
		{
            SC->PINCSR = (SC->PINCSR&(~SC_CD_INS_REM_MASK)) | SC_PINCSR_CD_REM_F_Msk; // clear CD_REM_F flag
			psDev->bCardRemoved = SC_STAUS_ABSENT;			
			SC_ISTDEBUG("IST[%d]: Card Removed\n",u32SCPort);
			if(g_pfnSCCallBack_CardPresent[u32SCPort]) g_pfnSCCallBack_CardPresent[u32SCPort]();
			
			if(psDev->openflag)
			{
            	// [2011.11.30]
            	/* protect writing operation forever */
				SC->IER&= ~SC_IER_TBE_IE_Msk;
#ifdef SC_SEQ_MANUAL
				SC_DeactivationCmd( psDev );	   // de-activation, use HW auto de-activation
#endif				
				SC_ClearFIFO(psDev);			// clear FIFO 
	            SC_TimerAllStop(psDev);
				psDev->errno = SC_ERR_CARD_REMOVED;
				psDev->op_state = SC_OP_NOP;
				psDev->openflag = 0;
				psDev->CardCapabilities.ATR.Length = 0;  
				SC->IER&= ~SC_IER_TBE_IE_Msk;               
				return ;	// leave ISR			
			}
		}
		else 
		{
			psDev->bCardRemoved = SC_STAUS_ABSENT;
			psDev->errno = SC_ERR_CARD_REMOVED;
			SC_ISTDEBUG("IST[%d]: Card status is not sure and HW has something wrong...\n",u32SCPort);
		}
	}

	/* Timer0-2 & BGT Time-Out */
    if((SC->ISR&SC_ISR_TMR0_IS_Msk)==SC_ISR_TMR0_IS_Msk)	 // Timer0 time-out
	{
        SC->ISR = SC_ISR_TMR0_IS_Msk; 
		if(g_ai32AtrFinalChk[u32SCPort]==1)
			g_ai32AtrFinalChk[u32SCPort] = 0;
		else
			psDev->errno = SC_ERR_TIME0OUT;
		psDev->op_state = SC_OP_NOP;	
		SC_ISTDEBUG("IST[%d]: Timer0 time-out\n",u32SCPort);
	}
    if((SC->ISR&SC_ISR_TMR1_IS_Msk)==SC_ISR_TMR1_IS_Msk)	 // Timer1 time-out
	{
		SC->ISR = SC_ISR_TMR1_IS_Msk;
		psDev->errno = SC_ERR_TIME1OUT;
		psDev->op_state = SC_OP_NOP;	
		SC_ISTDEBUG("IST[%d]: Timer1 time-out\n",u32SCPort);
	}
	if((SC->ISR&SC_ISR_TMR2_IS_Msk)==SC_ISR_TMR2_IS_Msk)	 // Timer2 time-out
	{
        SC->ISR = SC_ISR_TMR2_IS_Msk;
		if(g_ai32AtrCheckTime[u32SCPort]==0)
		{
			SC_TimerStop(psDev, SC_TIMER2);	
			psDev->errno = SC_ERR_TIME2OUT;
			//psDev->op_state = SC_OP_NOP;		// mask for CCID TPDU exchange
		} 
		else 
		{
			if((g_ai32AtrTime[u32SCPort]-256)>0)
				g_ai32AtrTime[u32SCPort] -= 256;
			else
				g_ai32AtrCheckTime[u32SCPort] = 0;

			// [2011.11.28]
			/* EMV Certification - mask this, time mode use DC_RELOAD */
			//printf("g_ai32AtrTime[u32SCPort]=%d \n", g_ai32AtrTime[u32SCPort]);
			//SC_TimerCountSet(psDev, SC_TIMER2, SC_TMR_MODE0_DC, (g_ai32AtrTime[u32SCPort]>=256)?256:g_ai32AtrTime[u32SCPort]);
			//SC_TimerStart(psDev, SC_TIMER2);	
		}
		SC_ISTDEBUG("IST[%d]: Timer2 time-out\n",u32SCPort);
	}

    if((SC->ISR&SC_ISR_BGT_IS_Msk)==SC_ISR_BGT_IS_Msk)		// Block Guard Time-out
	{
        SC->ISR = SC_ISR_BGT_IS_Msk;
		psDev->errno = SC_ERR_BGTIMEOUT;
		psDev->op_state = SC_OP_NOP;	
		SC_ISTDEBUG("IST[%d]: Block Guard Time-out\n",u32SCPort);
	}


	/* initial end interrupt */
    if((SC->ISR&SC_ISR_INIT_IS_Msk)==SC_ISR_INIT_IS_Msk)
	{
        SC->ISR = SC_ISR_INIT_IS_Msk;   // clear INIT_IS flag
		SC_ISTDEBUG("IST[%d]: Initial End\n",u32SCPort);
	}

	/* auto convention error interrrup	*/
    if((SC->ISR&SC_ISR_ACON_ERR_IS_Msk)==SC_ISR_ACON_ERR_IS_Msk)
	{
        SC->ISR = SC_ISR_ACON_ERR_IS_Msk;
		psDev->errno = SC_ERR_AUTOCONVENTION;
		psDev->op_state = SC_OP_NOP;
		SC_ISTDEBUG("IST[%d]: Auto Convention Error\n",u32SCPort);
	}

	/* transmit buffer empty interrupt */
    if((SC->ISR&SC_ISR_TBE_IS_Msk)==SC_ISR_TBE_IS_Msk)
	{
		if( psDev->op_state==SC_OP_WRITE )
		{
			//SC_ISTDEBUG("SC_TBE Empty, pos, len, data : %x , %x , %x \n",
			//		psDev->snd_pos, psDev->snd_len, psDev->snd_buf[psDev->snd_pos]);	
			
			if((psDev->snd_pos+1) >= psDev->snd_len)
			{
				// disable TX interrupt, disable action must be here, otherwise rapid interrupt will be like a loop in IST
				// send the last byte out
				// [2011.11.24]
				/* EMV Certification: delay Tx speed */
				SYS_SysTickDelay(6);
                //SYS_SysTickDelay(24);
				SC_PUT_ONE_BYTE(psDev->snd_buf[psDev->snd_pos++]);
				SC->IER&= ~SC_IER_TBE_IE_Msk;
				psDev->op_state = SC_OP_NOP;
			}

			/* actual write */
			if( (psDev->snd_pos+1) < psDev->snd_len)
				SC_PUT_ONE_BYTE(psDev->snd_buf[psDev->snd_pos++]);

		}
		else
		{	
			/* We'll get in here if there's no data in FIFO and Tx interrupt 
			enabled the first time, so do nothing here */
			; 
		}	
	}

	/* Rx FIFO data time out, what a good methord */
	/* Receive Data Reach Interrupt : RDR data ready */
    if((SC->ISR&(SC_ISR_RTMR_IS_Msk|SC_ISR_RDA_IS_Msk))!=0)
	{
		if(psDev->op_state == SC_OP_READ)
		{
			// [2011.11.25]
			/* EMV Certification */
			if(psDev->CardCapabilities.Protocol.Selected == SC_PROTOCOL_T1)
				SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE7_DC_RELOAD_S_S, (psDev->CardCapabilities.T1.CWT / psDev->CardCapabilities.etu) + 4 + 1);
			
            if((SC->ISR&SC_ISR_RDA_IS_Msk)==SC_ISR_RDA_IS_Msk)
			{  
				psDev->rcv_buf[psDev->rcv_pos + psDev->rcv_cnt++] = SC_GET_ONE_BYTE();
				//SC_ISTDEBUG("%x  ", psDev->rcv_buf[(psDev->rcv_pos + psDev->rcv_cnt - 1)]);
						
				if(psDev->rcv_cnt>= psDev->rcv_len || psDev->rcv_pos + psDev->rcv_cnt >= SC_MAX_BUF_LEN)
				{
					psDev->op_state = SC_OP_NOP;
					//break;  // don't receive data we don't want
				}	
									
			}
		}

		/* Read ATR ISR */
		else if(psDev->op_state == SC_OP_ATR_READ)
		{
			// TODO: stop checking timer & start to check waiting time 9600
			SC_TimerStop(psDev, SC_TIMER0);
			/* [ISO 7816-3] */
			//SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC, 9627);  // default waiting time 9600 ETUs
			/* [EMV2000] */
			SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC, 9600+480);
			SC_TimerStart(psDev, SC_TIMER0);

			if(g_ai32AtrTotalTimeStartFlag[u32SCPort] == 0)
			{
				g_ai32AtrTotalTimeStartFlag[u32SCPort] = 1;
				/* start counting total time for ATR session */
				SC_TimerStop(psDev, SC_TIMER2);
				SC_TimerCountSet(psDev, SC_TIMER2, SC_TMR_MODE4_DC_RELOAD, 256);
				g_ai32AtrCheckTime[u32SCPort] = 1;
				SC_TimerStart(psDev, SC_TIMER2);
			}

            if( ((SC->ISR&SC_ISR_RDA_IS_Msk)==SC_ISR_RDA_IS_Msk) && g_au32AtrRemain[u32SCPort])
			{
				/* 
				 * atr_len==0 : TS
				 * atr_len==1 : T0
				 */
				atrbuffer[g_au32AtrLen[u32SCPort]] = SC_GET_ONE_BYTE();
				//SC_ISTDEBUG("IST[%d]: ATR[%d]=0x%x remain=%d \n",u32SCPort, g_au32AtrLen[u32SCPort], atrbuffer[g_au32AtrLen[u32SCPort]], g_au32AtrRemain[u32SCPort]);
				g_au32AtrRemain[u32SCPort]--;
				g_ai32IfbyteFlag[u32SCPort]--;
					
				if(g_au32AtrLen[u32SCPort] == 1)
				{
					g_au32AtrRemain[u32SCPort] += (atrbuffer[g_au32AtrLen[u32SCPort]] & 0xf); // Historical byte
					g_ai32IfbyteFlag[u32SCPort] = 0; // T0 contains Y(x) as well
				}
				
				if( g_ai32IfbyteFlag[u32SCPort] == 0 )
				{
					if(atrbuffer[g_au32AtrLen[u32SCPort]] & 0x10)
					{
						++g_au32AtrRemain[u32SCPort];
						++g_ai32IfbyteFlag[u32SCPort];
					}
					if(atrbuffer[g_au32AtrLen[u32SCPort]] & 0x20)
					{
						++g_au32AtrRemain[u32SCPort];
						++g_ai32IfbyteFlag[u32SCPort];
					}
					if(atrbuffer[g_au32AtrLen[u32SCPort]] & 0x40)
					{
						++g_au32AtrRemain[u32SCPort];
						++g_ai32IfbyteFlag[u32SCPort];
					}
					if(atrbuffer[g_au32AtrLen[u32SCPort]] & 0x80)
					{
						++g_au32AtrRemain[u32SCPort];
						++g_ai32IfbyteFlag[u32SCPort];
						if((g_ai32Tck[u32SCPort] == 0) && (g_au32AtrLen[u32SCPort] != 1) && ((atrbuffer[g_au32AtrLen[u32SCPort]] & 0xf) != 0)) 
						{
							++g_au32AtrRemain[u32SCPort]; //tck exist
							g_ai32Tck[u32SCPort] = 1;
						}	
					}
					else
					{
						/* Here, it's special case for APDU test card */
						if((g_ai32Tck[u32SCPort] == 0) && (g_au32AtrLen[u32SCPort] != 1) && ((atrbuffer[g_au32AtrLen[u32SCPort]] & 0xf) != 0)) 
						{
							++g_au32AtrRemain[u32SCPort]; //tck exist
							g_ai32Tck[u32SCPort] = 1;
						}	
						g_ai32IfbyteFlag[u32SCPort] = -1;
					}
				}

				g_au32AtrLen[u32SCPort]++; 	 /* increase the length of ATR */
			}

			if(g_au32AtrRemain[u32SCPort] == 0)	/* receive ATR done */
			{
				psDev->CardCapabilities.ATR.Length = g_au32AtrLen[u32SCPort];
				SC_TimerStop(psDev, SC_TIMER0);
				SC_TimerCountSet(psDev, SC_TIMER0, SC_TMR_MODE0_DC, 480);
				SC_TimerStart(psDev, SC_TIMER0);
				SC_TimerStop(psDev, SC_TIMER2);
				g_ai32AtrFinalChk[u32SCPort] = 1;
				if( ((SC->ISR&SC_ISR_RDA_IS_Msk)==SC_ISR_RDA_IS_Msk) && g_ai32AtrFinalChk[u32SCPort])
				{
					SC_TimerStop(psDev, SC_TIMER0);
					psDev->errno = SC_ATR_ERR_INVALID_PARAMETER;
					psDev->op_state = SC_OP_NOP;
					g_ai32AtrFinalChk[u32SCPort] = 0;
				}
			}							
		}
		else 
		{  
			// Disgard these data			
#ifdef SC_IST_DEBUG			
			SC_ISTDEBUG("\nIST[%d]: Unknown data==>%x  \n",u32SCPort , SC_GET_ONE_BYTE());
#else
			//SC_GET_ONE_BYTE();
			g_au8ScUnexpectedInBuf[u32SCPort][g_au8ScUnexpectedBufLen[u32SCPort]++] = SC_GET_ONE_BYTE();
#endif			
			//SMARTCARD_ClearFIFO(psDev);  // clear FIFO				
		}
	}


	/* Transmit Error: break eror, frame error, Rx/Tx over flow, parity error, invaild stop */
    if(((SC->ISR&SC_ISR_TERR_IS_Msk)==SC_ISR_TERR_IS_Msk)&& ((SC->IER&SC_IER_TERR_IE_Msk)==SC_IER_TERR_IE_Msk))
	{
		//if(psDev->op_state)
		{

			//SC_ISTDEBUG("IST[%d]: SC_TRSR: %x \n",u32SCPort, SC->TRSR);

            if((SC->TRSR&SC_TRSR_RX_OVER_F_Msk)==SC_TRSR_RX_OVER_F_Msk) {
                SC->TRSR = SC_TRSR_RX_OVER_F_Msk;	
				psDev->errno = SC_ERR_READ;
				if(psDev->CardCapabilities.Protocol.Selected != SC_PROTOCOL_T1)
					psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Rx Over Flow\n",u32SCPort);
			}

			if((SC->TRSR&SC_TRSR_TX_OVER_F_Msk)==SC_TRSR_TX_OVER_F_Msk) {
				SC->TRSR = SC_TRSR_TX_OVER_F_Msk;				
				psDev->errno = SC_ERR_WRITE;
				psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Tx Over Flow\n",u32SCPort);
			}

            if((SC->TRSR&SC_TRSR_RX_EPA_F_Msk)==SC_TRSR_RX_EPA_F_Msk) {            
                SC->TRSR = SC_TRSR_RX_EPA_F_Msk;		
				psDev->errno = SC_ERR_PARITY_ERROR;
				SC->ALTCTL|= SC_ALTCTL_RX_RST_Msk;
				if(psDev->CardCapabilities.Protocol.Selected != SC_PROTOCOL_T1)	// for ATR reception
					psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Rx Parity Error\n",u32SCPort);
			}

			if((SC->TRSR&SC_TRSR_RX_EBR_F_Msk)==SC_TRSR_RX_EBR_F_Msk) {
				SC->TRSR = SC_TRSR_RX_EBR_F_Msk;
				SC->ALTCTL|= SC_ALTCTL_RX_RST_Msk;				
				psDev->errno = SC_ERR_READ;
				psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Rx Break Error\n",u32SCPort);
			}

			if((SC->TRSR&SC_TRSR_RX_EFR_F_Msk)==SC_TRSR_RX_EFR_F_Msk) {
				SC->TRSR = SC_TRSR_RX_EFR_F_Msk;
				SC->ALTCTL|= SC_ALTCTL_RX_RST_Msk;				
				psDev->errno = SC_ERR_READ;
				psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Rx Frame Error\n",u32SCPort);
			}

			if((SC->TRSR&SC_TRSR_TX_OVER_REERR_Msk)==SC_TRSR_TX_OVER_REERR_Msk) {
				if(psDev->op_state == SC_OP_WRITE)
					SC->IER&= ~SC_IER_TBE_IE_Msk;
                SC->TRSR = SC_TRSR_TX_REERR_Msk | SC_TRSR_TX_OVER_REERR_Msk;     
                SC->ALTCTL|= SC_ALTCTL_TX_RST_Msk;      	// Tx software reset
				psDev->errno = SC_ERR_WRITE;
				psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Tx Over Retry Error Retry \n",u32SCPort);
			}

			if((SC->TRSR&SC_TRSR_RX_OVER_REERR_Msk)==SC_TRSR_RX_OVER_REERR_Msk) {
                SC->TRSR = SC_TRSR_RX_REERR_Msk | SC_TRSR_RX_OVER_REERR_Msk;			
				psDev->errno = SC_ERR_READ;
				psDev->op_state = SC_OP_NOP;	
				SC_ISTDEBUG("IST[%d]: Rx Over Retry Error Retry \n",u32SCPort);
			}			
				
		}
			
	}	
	return ;

}



/**
  * @brief	This function installs callback which notices the card insertion/removal
  * @param[in]	psPortno	Indicate which port to be used
  *                         - SC0
  *                         - SC1
  *                         - SC2 
  * @param	pfncallback	CallBack function pointer
  * @retval SC_STATUS_SUCCESS		Success
  */
int32_t SC_InstallCallBack(SC_T *psPortno, SC_PFN_CALLBACK pfncallback)
{
	//assert_param(SC_CHECK_SC_PORT(psPortno));

	if(psPortno == SC0)
	{
		g_pfnSCCallBack_CardPresent[0] = pfncallback;
	}
	else if(psPortno == SC1)
	{
		g_pfnSCCallBack_CardPresent[1] = pfncallback;
	}
	else if(psPortno == SC2)
	{
		g_pfnSCCallBack_CardPresent[2] = pfncallback;
	}

	return SC_STATUS_SUCCESS;
}


/**
  * @brief	    Initialization process configures smartcard port and enables its clock and engine clock
  * @param[in]	psPortno					Indicate which port to be used (SC0, SC1, SC2)
  * @retval     SC_STATUS_SUCCESS		Success
  * @details    Initialization process configures smartcard port and enables its clock and engine clock
  */
   
int32_t SC_Init(SC_T *psPortno)
{
	S_SC_DEV_T *psDev;
	SC_T *SC;
	int32_t port = 0;
	
	//assert_param(SC_CHECK_SC_PORT(psPortno));

	SC = psPortno;
	if(psPortno==SC0)
		port = 0;
	else if(psPortno==SC1)
		port = 1;
	else if(psPortno==SC2)
		port = 2;

	psDev = (S_SC_DEV_T *)((uint32_t)&g_asScDevice[port]);
	memset(psDev, 0, sizeof(S_SC_DEV_T));
	psDev->base = psPortno;	//ya		
	// TODO: Initiate engine clock
	if(psPortno==SC0)
		SYSCLK->APBCLK1|= SYSCLK_APBCLK1_SC0_EN_Msk;
	else if(psPortno==SC1)
		SYSCLK->APBCLK1|= SYSCLK_APBCLK1_SC1_EN_Msk;
	else if(psPortno==SC2)
		SYSCLK->APBCLK1|= SYSCLK_APBCLK1_SC2_EN_Msk;    

	/* Card is Absent in default */
	psDev->bCardRemoved = SC_STAUS_ABSENT;

#if 0	// use SC_CardDetectEdge() to set detect edge before calling this function.  --ya
	/* card detect level must be set before engine enable */
	SC->PINCSR|= SC_PINCSR_CD_LEV_Msk; // card be detected low -> high, this must be set before enable engine 
#endif    
	// enable smartcard engine
    SC->CTL|= SC_CTL_SC_CEN_Msk;

	/* enable SmartCard INT NVIC */
	NVIC_EnableIRQ(SC012_IRQn);
	
	// enable card detection interrupt
    SC->IER|= SC_IER_CD_IE_Msk;
			
	printf("\n[%s] : SC%d Init...\n", __func__, (int)port);

	return SC_STATUS_SUCCESS;

}


/**
  * @brief	    Enable Timer Interrupt
  * @param[in]	psDev 	The pointer of data structure of smartcard information
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @return     None
  * @details    Enable Timer Interruptt
  */
void SC_TimerINTEnable(S_SC_DEV_T *psDev, uint32_t no)
{
	SC_T *SC = psDev->base;
    if( no & SC_TIMER0) SC->IER|= SC_IER_TMR0_IE_Msk;
	if( no & SC_TIMER1) SC->IER|= SC_IER_TMR1_IE_Msk;
	if( no & SC_TIMER2) SC->IER|= SC_IER_TMR2_IE_Msk;
}

/**
  * @brief	    Disable Timer Interrupt
  * @param[in]	psDev 	The pointer of data structure of smartcard information	
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @return     None
  * @details    Disable Timer Interrupt
  */
void SC_TimerINTDisable(S_SC_DEV_T *psDev, uint32_t no)
{
	SC_T *SC = psDev->base;
	if( no & SC_TIMER0) SC->IER&= ~SC_IER_TMR0_IE_Msk;
	if( no & SC_TIMER1) SC->IER&= ~SC_IER_TMR1_IE_Msk;
	if( no & SC_TIMER2) SC->IER&= ~SC_IER_TMR2_IE_Msk;
}

/**
  * @brief	Select which type of versatile timer
  * @param[in]	psDev 	The pointer of data structure of smartcard information	  
  * @param[in]	type	Timer selection
  *                     - SC_CTL_TMR_SEL_DISABLE
  *                     - SC_CTL_TMR_SEL_24_BITS
  *                     - SC_CTL_TMR_SEL_24_8_BITS  
  *                     - SC_CTL_TMR_SEL_24_8_8_BITS
  * @return     None
  * @details    Select which type of versatile timer, 24-bit, 24-8-bit or 24-8-8-bit
  */
void SC_TimerSelect(S_SC_DEV_T *psDev, uint32_t type)
{
	SC_T *SC = psDev->base;
    SC->CTL = (SC->CTL&(~SC_CTL_TMR_SEL_Msk)) | (type);
}

/**
  * @brief	    Enable Timer starting, counter will count when condition match
  * @param[in]	psDev 	The pointer of data structure of smartcard information	  
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @return     None
  * @details    Enable Timer starting, counter will count when condition match
  */
void SC_TimerStart(S_SC_DEV_T *psDev, uint32_t no)
{
	SC_T *SC = psDev->base;
	if(no & SC_TIMER0) {
		SC->ISR = SC_ISR_TMR0_IS_Msk;
        SC->ALTCTL|= SC_ALTCTL_TMR0_SEN_Msk;		
	}
	if(no & SC_TIMER1) {
		SC->ISR = SC_ISR_TMR1_IS_Msk; 
        SC->ALTCTL|= SC_ALTCTL_TMR1_SEN_Msk;
	}
	if(no & SC_TIMER2) {
		SC->ISR = SC_ISR_TMR2_IS_Msk; 
        SC->ALTCTL|= SC_ALTCTL_TMR2_SEN_Msk;        
	}
}

/**
  * @brief	    Stop Timer counting
  * @param[in]	psDev 	The pointer of data structure of smartcard information		
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @return     None
  * @details    Stop Timer counting

  */
void SC_TimerStop(S_SC_DEV_T *psDev, uint32_t no)
{
	SC_T *SC = psDev->base;
	if(no & SC_TIMER0)
        SC->ALTCTL&= ~SC_ALTCTL_TMR0_SEN_Msk;
	if(no & SC_TIMER1)
        SC->ALTCTL&= ~SC_ALTCTL_TMR1_SEN_Msk;
	if(no & SC_TIMER2)
        SC->ALTCTL&= ~SC_ALTCTL_TMR2_SEN_Msk;    
}

/**
  * @brief	    Stop All Timer counting
  * @param[in]	psDev 	The pointer of data structure of smartcard information	  
  * @return     None
  * @details    Stop Timer counting
  */
void SC_TimerAllStop( S_SC_DEV_T *psDev )
{
	SC_T *SC = psDev->base;
	// disable all internal timer function
	//SC->CTL_BITS.TMR_SEL = SC_TMR_DISABLE;
    
    SC->ALTCTL&= ~(SC_ALTCTL_TMR0_SEN_Msk | SC_ALTCTL_TMR1_SEN_Msk | SC_ALTCTL_TMR2_SEN_Msk);       
}

/**
  * @brief	    Specified Timer uses specified operation mode and set ETU number to count.
  * @param[in]	psDev 	The pointer of data structure of smartcard information		
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @param[in]	op_mode Timer operation mode
  *                     - SC_TMR_MODE0_DC
  *                     - SC_TMR_MODE1_DC_S_TO
  *                     - SC_TMR_MODE2_DC_RX_S_TO
  *                     - SC_TMR_MODE3_DC_INITIAL_END(SC_TIMER1 and SC_TIMER2 don't suppoert operation mode3)
  *                     - SC_TMR_MODE4_DC_RELOAD
  *                     - SC_TMR_MODE5_DC_RELOAD_S_TO
  *                     - SC_TMR_MODE6_DC_RELOAD_RX_S_TO
  *                     - SC_TMR_MODE7_DC_RELOAD_S_S
  *                     - SC_TMR_MODE8_UC
  * @param[in]	cnt 		Amount count (ETU-based)
  * @return     None
  * @details    Specified Timer uses specified operation mode and set ETU number to count.
  */
void SC_TimerCountSet(S_SC_DEV_T *psDev, uint32_t no, uint32_t op_mode, uint32_t cnt)
{
	SC_T *SC = psDev->base;
	if(no == SC_TIMER0)
	{
        SC->TMR0 = (op_mode) | ((cnt-1)&SC_TMR0_CNT_Msk);
	}
	else if(no == SC_TIMER1)
	{
        SC->TMR1 = (op_mode) | ((cnt-1)&SC_TMR1_CNT_Msk);
	}
	else if(no == SC_TIMER2)
	{
        SC->TMR2 = (op_mode) | ((cnt-1)&SC_TMR2_CNT_Msk);
	}
}


/**
  * @brief	In receiving mode and just waiting for data in, this function uses to detect the first data byte if time-out
  * @param[in]	psDev 		The pointer of data structure of smartcard information		
  * @param[in]	no		Timer number. 
  *                     - SC_TIMER0
  *                     - SC_TIMER1
  *                     - SC_TIMER2
  * @param[in]	op_mode Timer operation mode
  *                     - SC_TMR_MODE0_DC
  *                     - SC_TMR_MODE1_DC_S_TO
  *                     - SC_TMR_MODE2_DC_RX_S_TO
  *                     - SC_TMR_MODE3_DC_INITIAL_END(SC_TIMER1 and SC_TIMER2 don't suppoert operation mode3)
  *                     - SC_TMR_MODE4_DC_RELOAD
  *                     - SC_TMR_MODE5_DC_RELOAD_S_TO
  *                     - SC_TMR_MODE6_DC_RELOAD_RX_S_TO
  *                     - SC_TMR_MODE7_DC_RELOAD_S_S
  *                     - SC_TMR_MODE8_UC
  * @param[in]	cnt 		Amount count (ETU-based)
  * @return     None
  * @details    In receiving mode and just waiting for data in, this function uses to detect the first data byte if time-out
  */
void SC_WaitFirstReceivedData(S_SC_DEV_T *psDev, uint32_t no, uint32_t op_mode, uint32_t cnt)	
{
	int32_t timeOutCount = 0, remainderCount = 0;
	int32_t errorflag = 0;

	/* Because TIMER1 or TIMER2 Max. ETU count is 256 */
	if(no != SC_TIMER0) 
	{
		timeOutCount = cnt / 256;	
		remainderCount = cnt % 256;	
	}

	if(no == SC_TIMER0)
		errorflag = SC_ERR_TIME0OUT;
	else if(no == SC_TIMER1)
		errorflag = SC_ERR_TIME1OUT;
	else if(no == SC_TIMER2)
		errorflag = SC_ERR_TIME2OUT;
	
	while(timeOutCount)
	{
		psDev->errno = 0;
		SC_TimerCountSet(psDev, no, op_mode, 256);
		SC_TimerStart(psDev, no);

		while( !(psDev->errno) )
		{
			if(psDev->errno == errorflag)
				break;
			else 
			{
				// if received the first data ?
				if(psDev->rcv_cnt > 0)
				{
					SC_TimerStop(psDev, no);
					return ;
				}

				// if had any other errors ?
				if( (psDev->errno!=errorflag) && (psDev->errno!=0))
					return ;
			}
		}			
		timeOutCount--;
	}

	if(remainderCount)
	{
		psDev->errno = 0;
		SC_TimerCountSet(psDev, no, op_mode, remainderCount);
		SC_TimerStart(psDev, no);

		while( !(psDev->errno) )
		{
			if(psDev->errno == errorflag)
				break;
			else 
			{
				// if received the first data ?
				if(psDev->rcv_cnt > 0)
				{
					SC_TimerStop(psDev, no);
					return ;
				}

				// if had any other errors ?
				if( (psDev->errno!=errorflag) && (psDev->errno!=0))
					return ;
			}
		}
	}
	/* really time-out happened on first byte */
	psDev->op_state = SC_OP_NOP;
	psDev->errno = errorflag;
	
}


//
// This is the time resolution.
// We calculate all times not in seconds, but in micro seconds
//
#define TR ((unsigned long)(1000l * 1000l)) 	// for time resolution = micro-second unit

/**
  * @brief	    According to the number of power, to calculate the number by 2
  * @param[in]	Exponent	The number of power
  * @retval     The power of 'exponent' by 2
  * @details    According to the number of power, to calculate the number by 2
  */
static unsigned long  Pow2(uint8_t Exponent)
{
	unsigned long result = 1;

	while(Exponent--)
		result *= 2;

	return result;
}

/**
  * @brief	This routine updates the CardCapabilities structure, which holds information about
  * @param[in]	psDev	 The structure of S_SC_DEV_T
  * @retval     The result status of checking processes
  * @details    This routine updates the CardCapabilities structure, which holds information about
  *			    the smartcard that has just been reset and is currently in use. It reads the 
  *			    ATR string and retrieves all the relevent information.
  */
int32_t SC_UpdateCardCapabilities(S_SC_DEV_T *psDev)
{
    S_SC_SCARD_CARD_CAPABILITIES *cardCapabilities = &(psDev->CardCapabilities);
	uint8_t * atrString = cardCapabilities->ATR.Buffer;
	int8_t atrLength = cardCapabilities->ATR.Length;
	uint8_t Y, Tck, TA[SC_MAXIMUM_ATR_CODES], TB[SC_MAXIMUM_ATR_CODES];
	uint8_t TC[SC_MAXIMUM_ATR_CODES], TD[SC_MAXIMUM_ATR_CODES];
	unsigned long i, fs, numProtocols = 0, protocolTypes = 0;
	int32_t status = SC_STATUS_SUCCESS;
	bool TA2Present = false;

	SC_ENTER();

	if (atrLength < 2) {
		
		printf("   ATR is too short (Min. length is 2) \n");

		return SC_ATR_ERR_UNRECOGNIZED_MEDIA;
	}

#ifdef SC_ATR_DEBUG
	printf("ATR: \n");

	DumpData(
		atrString,
		atrLength
		);
#endif

	if (atrString[0] != 0x3b && atrString[0] != 0x3f && atrString[0] != 0x03) {

		printf("   Initial character %xh of ATR is invalid\n", atrString[0] );

		return SC_ATR_ERR_UNRECOGNIZED_MEDIA;
	}

	// Test for inverse convention
	if (*atrString == 0x3F) 
	{

		cardCapabilities->InversConvention = true;

		//
		// When the ATR starts with 0x03 then it 
		// has not been inverted already			
		//
		//SmartcardInvertData(					/* HW can auto-inverted coming data after received TS byte, so we could NOT do it by software */
		//	  cardCapabilities->ATR.Buffer, 
		//	  cardCapabilities->ATR.Length
		//	  );				

		printf("   Card uses Inverse Convention\n");
	} 

	//try {
	{

		//
		// The caller might be calling this function repeatedly in order to 
		// test if the ATR is valid. If the ATR we currently have here is
		// not valid then we need to be able re-invert an inverted ATR.
		//

		atrString += 1;
		atrLength -= 1;

		//
		// Calculate check char, but do not test now since if only T=0 
		// is present the ATR doesn't contain a check char
		//
		for (i = 0, Tck = 0; i < atrLength; i++) {

			Tck ^= atrString[i];
		}

		// Initialize various data
		cardCapabilities->Protocol.Supported = 0;

		memset(TA, 0, sizeof(TA)); 
		memset(TB, 0, sizeof(TB)); 
		memset(TC, 0, sizeof(TC)); 
		memset(TD, 0, sizeof(TD)); 

		//
		// Set default values as described in ISO 7816-3
		//
	
		// TA1 codes Fl in high-byte and Dl in low-byte;
		TA[0] = 0x11;
		// TB1 codes II in bits b7/b6 and Pl1 in b5-b1. b8 has to be 0
		TB[0] = 0x25;
		// TC2 codes T=0 WI
		TC[1] = 10;

		// Translate ATR string to TA to TD values (See ISO)
		cardCapabilities->HistoricalChars.Length = *atrString & 0x0f;

		Y = *atrString++ & 0xf0;		/* Get Format byte T0 */
		atrLength -= 1;

		for (i = 0; i < SC_MAXIMUM_ATR_CODES; i++) 
		{

			if (Y & 0x10) {

				if (i == 1) {

					TA2Present = true;					
				}

				TA[i] = *atrString++;
				atrLength -= 1;
			}

			if (Y & 0x20) {

				TB[i] = *atrString++;
				atrLength -= 1;
			}

			if (Y & 0x40) {

				TC[i] = *atrString++;
				atrLength -= 1;
			}

			if (Y & 0x80) {

				Y = *atrString & 0xf0;			/* Set next interface byte TDi */
				TD[i] = *atrString++ & 0x0f;	/* TD[] only set transmission protocol */
				atrLength -= 1;

				// Check if the next parameters are for a new protocol.
				if (((1 << TD[i]) & protocolTypes) == 0) {

					// Count the number of protocols that the card supports
					numProtocols++;
				}
				protocolTypes |= 1 << TD[i];

			} else {
				
				break;
			}
		} 

		// Check if the card supports a protocol other than T=0
		if (protocolTypes & ~1) 
		{

			//
			// The atr contains a checksum byte.
			// Exclude that from the historical byte length check
			//
			atrLength -=1;		

			//
			// This card supports more than one protocol or a protocol 
			// other than T=0, so test if the checksum is correct
			//
			if (Tck != 0) {

				printf("   ATR Checksum is invalid\n");

				status = SC_ATR_ERR_INVALID_TCK;
				goto _exit;
			}
		}

		if (atrLength < 0 ||
			atrLength != cardCapabilities->HistoricalChars.Length) {
			
			printf("   ATR length is inconsistent\n");

			status = SC_ATR_ERR_UNRECOGNIZED_MEDIA;
			goto _exit;
		}
	}
	

	if (status != SC_STATUS_SUCCESS)
		return status;
		
	// store historical characters
	memcpy( 	// use memcoy API by SM
		cardCapabilities->HistoricalChars.Buffer,
		atrString,
		cardCapabilities->HistoricalChars.Length
		);

	//
	// Now convert TA - TD values to global interface bytes
	//

	// Clock rate conversion
	cardCapabilities->Fl = (TA[0] & 0xf0) >> 4;

	// bit rate adjustment
	cardCapabilities->Dl = (TA[0] & 0x0f);

	// Maximum programming current factor
	cardCapabilities->II = (TB[0] & 0xc0) >> 6;

	// Programming voltage in 0.1 Volts
	cardCapabilities->P = (TB[1] ? TB[1] : (TB[0] & 0x1f) * 10);

	// Extra guard time
	cardCapabilities->N = TC[0];

	//
	// Check if the Dl and Fl values are valid
	// 
	if (BitRateAdjustment[cardCapabilities->Dl].DNumerator == 0 ||
		ClockRateConversion[cardCapabilities->Fl].F == 0) {

		printf("   Dl = %x  or Fl = %x  invalid\n",
			cardCapabilities->Dl,
			cardCapabilities->Fl
			);

		return SC_ATR_ERR_UNRECOGNIZED_MEDIA;
	}

	SC_DEBUG("   Card parameters from ATR:\n		Fl = %x  (Max. %ld KHz), Dl = %x , I = %x , P = %x , N = %x \n",
		cardCapabilities->Fl,
		ClockRateConversion[cardCapabilities->Fl].fs / 1000,
		cardCapabilities->Dl,
		cardCapabilities->II,
		cardCapabilities->P,
		cardCapabilities->N
		);

	//
	// assume default clock frequency
	//
	// TODO: set the SmartCard input clock frequency
	//
	// assume default clock frequency
	//
	fs = psDev->clock * 1000l;

	//
	// We calculate the ETU on basis of the timing supplied by the 
	// clk-frequency of the reader
	//
	//
	// Work etu in units of time resolution(TR) (NOT in seconds)
	//
	cardCapabilities->etu = 
		1 + 	// required to round up
		(TR * 
		/* BitRateAdjustment[cardCapabilities->Dl].DDivisor * */ // ???
		ClockRateConversion[cardCapabilities->Fl].F) /
		(BitRateAdjustment[cardCapabilities->Dl].DNumerator * 
		fs);

	//
	// guard time in micro seconds
	// the guard time is the gap between the end of the
	// current character and the beginning of the next character
	//
	//cardCapabilities->GT = 0;
	cardCapabilities->GT = 12;	// by default GT = 12, modified by SM

	if (cardCapabilities->N == 0) 
	{
		cardCapabilities->GT = 12;
	} 
	else if (cardCapabilities->N == 255) 
	{
		if (protocolTypes & SC_PROTOCOL_T1)
			cardCapabilities->GT = 11;				// T=1, character guard time = 11 etu
	} 
	else if(cardCapabilities->N != 0) // modified by SM
	{
		//cardCapabilities->GT = cardCapabilities->N;		// mask by SM
		cardCapabilities->GT = cardCapabilities->N + 12;	// modified by SM
	}

	SC_DEBUG("   Calculated timing values:\n		Work etu = %ld micro sec, Guard time = %ld ETU\n",
		cardCapabilities->etu,
		cardCapabilities->GT
		);

	if ((TA2Present) || (numProtocols <= 1 && cardCapabilities->Fl == 1 && cardCapabilities->Dl == 1) || (psDev->pps_complete == 1))
	{
		//
		// If the card supports only one protocol (or T=0 as default)
		// and only standard paramters then PTS selection is not available
		//
		psDev->CurrentState = SC_STAUS_SPECIFIC; // modified by SM

	} else {
		
		psDev->CurrentState = SC_STAUS_NEGOTIABLE; // modified by SM 		   
	}

	//
	// Now find protocol specific data
	//

	if (TD[0] == 0) 		   /* Protocol T=0 */
	{
		
		cardCapabilities->Protocol.Supported |= SC_PROTOCOL_T0;

		cardCapabilities->T0.WI = TC[1];

		cardCapabilities->T0.WT = 1 +
			( cardCapabilities->T0.WI *
			960 * cardCapabilities->etu * 
			BitRateAdjustment[cardCapabilities->Dl].DNumerator);   // modified by SM
			

		SC_DEBUG("   T=0 Values from ATR:\n	   WI = %ld\n", cardCapabilities->T0.WI);
		SC_DEBUG("   T=0 Timing from ATR:\n	   WT = %ld us\n", cardCapabilities->T0.WT );
		
	}

	/* Protocol T=1 */
	if (protocolTypes & SC_PROTOCOL_T1) 
	{

		for (i = 0; TD[i] != 1 && i < SC_MAXIMUM_ATR_CODES; i++)
			;
	
		for (; TD[i] == 1 && i < SC_MAXIMUM_ATR_CODES; i++) 
			;

		if (i == SC_MAXIMUM_ATR_CODES) {

			return SC_ATR_ERR_UNRECOGNIZED_MEDIA;			
		}

		cardCapabilities->Protocol.Supported |= 
			SC_PROTOCOL_T1;

		cardCapabilities->T1.IFSC = 
			(TA[i] ? TA[i] : 32);

		cardCapabilities->T1.CWI = (TB[i] & 0x0f);
		/*	((TB[i] & 0x0f) ? (TB[i] & 0x0f) : T1_CWI_DEFAULT);*/

		cardCapabilities->T1.BWI = (TB[i] & 0xf0) >> 4;
		/*	((TB[i] & 0xf0) >> 4 ? (TB[i] & 0xf0) >> 4 : T1_BWI_DEFAULT);*/

		cardCapabilities->T1.EDC = 
			(TC[i] & 0x01);

		cardCapabilities->T1.CWT = 1 +
			(Pow2(cardCapabilities->T1.CWI) + 11) * cardCapabilities->etu;

		cardCapabilities->T1.BWT = 1 +
			//((Pow2(cardCapabilities->T1.BWI) * TR) / 10) + // ???
			((Pow2(cardCapabilities->T1.BWI) * 960 * BitRateAdjustment[cardCapabilities->Dl].DNumerator) +
			11) * cardCapabilities->etu;

		cardCapabilities->T1.BGT = 22 * cardCapabilities->etu;	// added by SM

		SC_DEBUG("   T=1 Values from ATR:\n	   IFSC = %ld, CWI = %ld, BWI = %ld, EDC = %x \n",
			cardCapabilities->T1.IFSC,
			cardCapabilities->T1.CWI,
			cardCapabilities->T1.BWI,
			cardCapabilities->T1.EDC
			);

		SC_DEBUG("   T=1 Timing from ATR:\n	   CWT = %ld us, BWT = %ld us, BGT = %ld us\n",
			cardCapabilities->T1.CWT,
			cardCapabilities->T1.BWT,
			cardCapabilities->T1.BGT
			);
	}


	/* Protocol T=15 */
	if (protocolTypes & SC_PROTOCOL_T15) 
	{
		for (i = 0; TD[i] != 0xF && i < SC_MAXIMUM_ATR_CODES; i++)
			;
	
		for (; TD[i] == 0xF && i < SC_MAXIMUM_ATR_CODES; i++) 
			;

		if (i == SC_MAXIMUM_ATR_CODES) {

			return SC_ATR_ERR_UNRECOGNIZED_MEDIA;			
		}

		if((TA[i] & 0xC0) == 0x00)
			psDev->clock_stop_level = SC_CLK_PIN_STOP_NOT_SUPPORT;
		else if((TA[i] & 0xC0) == 0x40)
			psDev->clock_stop_level = SC_CLK_PIN_STOP_LOW;
		else if((TA[i] & 0xC0) == 0x80)
			psDev->clock_stop_level = SC_CLK_PIN_STOP_HIGH;
		else if((TA[i] & 0xC0) == 0xC0)
			psDev->clock_stop_level = SC_CLK_PIN_STOP_NO_PREFE;

		if((TA[i] & 0x3F) == 0x01)
			psDev->voltage = SC_ISO_OPERATIONCLASS_A;
		else if((TA[i] & 0x3F) == 0x02)
			psDev->voltage = SC_ISO_OPERATIONCLASS_B;
		else if((TA[i] & 0x3F) == 0x04)
			psDev->voltage = SC_ISO_OPERATIONCLASS_C;
		else if((TA[i] & 0x3F) == 0x03)
			psDev->voltage = SC_ISO_OPERATIONCLASS_A | SC_ISO_OPERATIONCLASS_B;
		else if((TA[i] & 0x3F) == 0x06)
			psDev->voltage = SC_ISO_OPERATIONCLASS_B | SC_ISO_OPERATIONCLASS_C;
		else if((TA[i] & 0x3F) == 0x07)
			psDev->voltage = SC_ISO_OPERATIONCLASS_A | SC_ISO_OPERATIONCLASS_B | SC_ISO_OPERATIONCLASS_C;
		else
			psDev->voltage = SC_ISO_OPERATIONCLASS_AUTO;

	}


	if (psDev->CurrentState == SC_STAUS_SPECIFIC)	// modified by SM
	{
		
		if (TA2Present) 
		{
			//
			// TA2 is present in the ATR, so use 
			// the protocol indicated in the ATR
			//
			cardCapabilities->Protocol.Selected = 1 << (TA[1]&0x0F);
			
		} else {
			
			//
			// The card only supports one protocol
			// So make that one protocol the current one to use
			//
			cardCapabilities->Protocol.Selected = 
				cardCapabilities->Protocol.Supported;
		}

		SC_DEBUG("   Mode: Specific %s\n\n",	TA2Present ? "set by TA(2)" : "" );

	}
	else 
	{
		SC_DEBUG("   Mode: Negotiable\n\n");
	}

	//
	// Every card has to support the 'raw' protocol
	// It enables the usage of cards that have their own protocol defined
	//
	//psDev->CardCapabilities.Protocol.Supported |=		// mask by SM, protocol was defined by ATR
	//	SCARD_PROTOCOL_RAW;
	
_exit:
	
	return status;
}

/*** (C) COPYRIGHT 2011 Nuvoton Technology Corp. ***/



