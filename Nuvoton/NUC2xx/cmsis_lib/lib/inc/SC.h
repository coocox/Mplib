/**************************************************************************//**
 * @file     SC.h
 * @version  V1.00
 * $Revision: 12 $
 * $Date: 12/08/22 7:24p $
 * @brief    NUC200 Series Smart Card Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 *
 ******************************************************************************/

#ifndef __SC_H__
#define __SC_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "NUC200Series.h"


/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup SC_FUNC SMARTCARD Device Function Interface
  * @{
  */


/*---------------------------------------------------------------------------------------------------------*/
/* Macro, type and constant definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_CD_INS_REM_MASK          0xC
#define SC_MAXIMUM_ATR_CODES        4
#define SC_MAXIMUM_ATR_LENGTH       33
/* Do activation & de-activation & warm-rest with manual sequence */
#define SC_SEQ_MANUAL

#define SC_SC_NUM					    3      // we have 3 interfaces
/*---------------------------------------------------------------------------------------------------------*/
/*  Smart Card Internal Timer number constants definitions                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_TIMER0   8       /*!< Smart Card Internal Timer 0 */
#define SC_TIMER1	16      /*!< Smart Card Internal Timer 1 */ 
#define SC_TIMER2   32      /*!< Smart Card Internal Timer 2 */

/*---------------------------------------------------------------------------------------------------------*/
/* Clock Stop Level                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_CLK_PIN_STOP_NOT_SUPPORT     0
#define SC_CLK_PIN_STOP_LOW             1
#define SC_CLK_PIN_STOP_HIGH            2
#define SC_CLK_PIN_STOP_NO_PREFE        3

/*---------------------------------------------------------------------------------------------------------*/
/*  RBR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_RBR_RBR_MASK				((uint32_t)0x000000FF)			/*!<Receive Buffer Register */
/*---------------------------------------------------------------------------------------------------------*/
/*  THR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_THR_THR_MASK				((uint32_t)0x000000FF)			/*!<Transmit Holding Register */

/*---------------------------------------------------------------------------------------------------------*/
/*  CTL constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_CTL_SC_CEN				((uint32_t)0x00000001)			/*!<SC Engine Enable */
#define SC_CTL_DIS_RX				((uint32_t)0x00000002)			/*!<Disable RX transition */
#define SC_CTL_DIS_TX				((uint32_t)0x00000004)			/*!<Disable TX transition */
#define SC_CTL_AUTO_CON_EN			((uint32_t)0x00000008)			/*!<Auto Convention Enable */
#define SC_CTL_CON_SEL_DIRECT_CON	((uint32_t)0x00000000)			/*!<Convention Select */
#define SC_CTL_CON_SEL_INVERSE_CON	((uint32_t)0x00000030)			/*!<Convention Select */
#define SC_CTL_RX_FTRI_LEV_1BYTE	((uint32_t)0x00000000)			/*!<RX Buffer Trigger Level 1 byte*/
#define SC_CTL_RX_FTRI_LEV_2BYTES	((uint32_t)0x00000040)			/*!<RX Buffer Trigger Level 2 bytes*/
#define SC_CTL_RX_FTRI_LEV_3BYTES	((uint32_t)0x00000080)			/*!<RX Buffer Trigger Level 3 bytes*/
#define SC_CTL_TMR_SEL_DISABLE		((uint32_t)0x00000000)			/*!<Timer Selection. Disable all internal timer function */
#define SC_CTL_TMR_SEL_24_BITS		((uint32_t)0x00002000)			/*!<Timer Selection. Enable internal 24 bits timer */
#define SC_CTL_TMR_SEL_24_8_BITS	((uint32_t)0x00004000)			/*!<Timer Selection. Enable internal 24 bits timer and 8 bits internal timer */
#define SC_CTL_TMR_SEL_24_8_8_BITS	((uint32_t)0x00006000)			/*!<Timer Selection. Enable internal 24 bits timer and two 8 bits timers */
#define SC_CTL_SLEN					((uint32_t)0x00008000)			/*!<Stop Bit Length */
#define SC_CTL_RX_ERETRY_EN			((uint32_t)0x00080000)			/*!<RX Error Retry Enable Register */
#define SC_CTL_TX_ERETRY_EN			((uint32_t)0x00800000)			/*!<TX Error Retry Enable Register */
#define SC_CTL_CD_DEB_SEL_IN_384_REMOVAL_128 ((uint32_t)0x00000000)			/*!<Card Detect De-Bounce Select Register. Card insert once per 384 engine clocks and de-bounce sample card removal once per 128 engine clocks.*/
#define SC_CTL_CD_DEB_SEL_IN_192_REMOVAL_64	 ((uint32_t)0x01000000)			/*!<Card Detect De-Bounce Select Register. Card insert once per 192 engine clocks and de-bounce sample card removal once per 64 engine clocks. */
#define SC_CTL_CD_DEB_SEL_IN_96_REMOVAL_32	 ((uint32_t)0x02000000)			/*!<Card Detect De-Bounce Select Register. Card insert once per 96 engine clocks and de-bounce sample card removal once per 32 engine clocks. */
#define SC_CTL_CD_DEB_SEL_IN_48_REMOVAL_16	 ((uint32_t)0x03000000)			/*!<Card Detect De-Bounce Select Register. Card insert once per 48 engine clocks and de-bounce sample card removal once per 16 engine clocks. */

/*---------------------------------------------------------------------------------------------------------*/
/*  ALTCTL constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_ALTCTL_TX_RST			((uint32_t)0x00000001)			/*!<TX Software Reset */
#define SC_ALTCTL_RX_RST			((uint32_t)0x00000002)			/*!<RX Software Reset */
#define SC_ALTCTL_DACT_EN			((uint32_t)0x00000004)			/*!<Deactivation Sequence Generator Enable */
#define SC_ALTCTL_ACT_EN			((uint32_t)0x00000008)			/*!<Activation Sequence Generator Enable */
#define SC_ALTCTL_WARST_EN			((uint32_t)0x00000010)			/*!<Warm Reset Sequence Generator Enable */
#define SC_ALTCTL_TMR0_SEN			((uint32_t)0x00000020)			/*!<Internal Timer0 Start Enable */
#define SC_ALTCTL_TMR1_SEN			((uint32_t)0x00000040)			/*!<Internal Timer1 Start Enable */
#define SC_ALTCTL_TMR2_SEN			((uint32_t)0x00000080)			/*!<Internal Timer2 Start Enable */
#define SC_ALTCTL_RX_BGT_EN			((uint32_t)0x00001000)			/*!<Receiver Block Guard Time Function Enable */
#define SC_ALTCTL_TMR0_ATV			((uint32_t)0x00002000)			/*!<Internal Timer0 Active State (Read Only) */
#define SC_ALTCTL_TMR1_ATV			((uint32_t)0x00004000)			/*!<Internal Timer1 Active State (Read Only) */
#define SC_ALTCTL_TMR2_ATV			((uint32_t)0x00008000)			/*!<Internal Timer2 Active State (Read Only) */

/*---------------------------------------------------------------------------------------------------------*/
/*  ETUCR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_ETUCR_COMPEN_EN			((uint32_t)0x00008000)			/*!<Compensation Mode Enable */

/*---------------------------------------------------------------------------------------------------------*/
/*  IER constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_IER_RDA_IE				((uint32_t)0x00000001)			/*!<Receive Data Reach Interrupt Enable */
#define SC_IER_TBE_IE				((uint32_t)0x00000002)			/*!<Transmit Buffer Empty Interrupt Enable */
#define SC_IER_TERR_IE				((uint32_t)0x00000004)			/*!<Transfer Error Interrupt Enable */
#define SC_IER_TMR0_IE				((uint32_t)0x00000008)			/*!<Timer0 Interrupt Enable */
#define SC_IER_TMR1_IE				((uint32_t)0x00000010)			/*!<Timer1 Interrupt Enable */
#define SC_IER_TMR2_IE				((uint32_t)0x00000020)			/*!<Timer2 Interrupt Enable */
#define SC_IER_BGT_IE				((uint32_t)0x00000040)			/*!<Block Guard Time Interrupt Enable */
#define SC_IER_CD_IE				((uint32_t)0x00000080)			/*!<Card Detect Interrupt Enable */
#define SC_IER_INIT_IE				((uint32_t)0x00000100)			/*!<Initial End Interrupt Enable */
#define SC_IER_RTMR_IE				((uint32_t)0x00000200)			/*!<Receiver Buffer Time-Out Interrupt Enable  */
#define SC_IER_ACON_ERR_IE			((uint32_t)0x00000400)			/*!<Auto convention Error Interrupt Enable */

/*---------------------------------------------------------------------------------------------------------*/
/*  ISR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_ISR_RDA_IS				((uint32_t)0x00000001)			/*!<Receive Data Reach Interrupt Status Flag (Read Only) */
#define SC_ISR_TBE_IS				((uint32_t)0x00000002)			/*!<Transmit Buffer Empty Interrupt Status Flag (Read Only) */
#define SC_ISR_TERR_IS				((uint32_t)0x00000004)			/*!<Transfer Error Interrupt Status Flag (Read Only) */
#define SC_ISR_TMR0_IS				((uint32_t)0x00000008)			/*!<Timer0 Interrupt Status Flag (Read Only) */
#define SC_ISR_TMR1_IS				((uint32_t)0x00000010)			/*!<Timer1 Interrupt Status Flag (Read Only) */
#define SC_ISR_TMR2_IS				((uint32_t)0x00000020)			/*!<Timer2 Interrupt Status Flag (Read Only) */
#define SC_ISR_BGT_IS				((uint32_t)0x00000040)			/*!<Block Guard Time Interrupt Status Flag (Read Only) */
#define SC_ISR_CD_IS				((uint32_t)0x00000080)			/*!<Card Detect Interrupt Status Flag (Read Only) */
#define SC_ISR_INIT_IS				((uint32_t)0x00000100)			/*!<Initial End Interrupt Status Flag (Read Only) */
#define SC_ISR_RTMR_IS				((uint32_t)0x00000200)			/*!<Receiver buffer Time-Out Interrupt Status Flag (Read Only) */
#define SC_ISR_ACON_ERR_IS			((uint32_t)0x00000400)			/*!<Auto Convention Error Interrupt Status Flag (Read Only) */

/*---------------------------------------------------------------------------------------------------------*/
/*  TRSR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_TRSR_RX_OVER_F			((uint32_t)0x00000001)			/*!<RX Overflow Error Status Flag (Read Only)  */
#define SC_TRSR_RX_EMPTY_F			((uint32_t)0x00000002)			/*!<Receiver Buffer Empty Status Flag(Read Only) */
#define SC_TRSR_RX_FULL_F			((uint32_t)0x00000004)			/*!<Receiver Buffer Full Status Flag (Read Only) */
#define SC_TRSR_RX_EPA_F			((uint32_t)0x00000010)			/*!<Receiver Parity Error Status Flag (Read Only) */
#define SC_TRSR_RX_EFR_F			((uint32_t)0x00000020)			/*!<Receiver Frame Error Status Flag (Read Only) */
#define SC_TRSR_RX_EBR_F			((uint32_t)0x00000040)			/*!<Receiver Break Error Status Flag (Read Only) */
#define SC_TRSR_TX_OVER_F			((uint32_t)0x00000100)			/*!<TX Overflow Error Interrupt Status Flag (Read Only) */
#define SC_TRSR_TX_EMPTY_F			((uint32_t)0x00000200)			/*!<Transmit buffer Empty Status Flag (Read Only) */
#define SC_TRSR_TX_FULL_F			((uint32_t)0x00000400)			/*!<Transmit buffer Full Status flag (Read Only) */
#define SC_TRSR_RX_ERETRY_F			((uint32_t)0x00200000)			/*!<Receiver Retry Error (Read Only) */
#define SC_TRSR_RX_OVER_ERETRY		((uint32_t)0x00400000)			/*!<Receiver Over Retry Error (Read Only) */
#define SC_TRSR_RX_RX_ATV			((uint32_t)0x00800000)			/*!<Receiver In Active Status Flag (Read Only) */
#define SC_TRSR_TX_ERETRY_F			((uint32_t)0x20000000)			/*!<Transmitter Retry Error (Read Only) */
#define SC_TRSR_TX_OVER_ERETRY		((uint32_t)0x40000000)			/*!<Transmitter Over Retry Error (Read Only) */
#define SC_TRSR_TX_ATV				((uint32_t)0x80000000)			/*!<Transmit In Active Status Flag (Read Only) */

/*---------------------------------------------------------------------------------------------------------*/
/*  PINCSR constants definitions                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_PINCSR_POW_EN			((uint32_t)0x00000001)			/*!<SC_POW_EN Pin Signal */
#define SC_PINCSR_SC_RST			((uint32_t)0x00000002)			/*!<SC_RST Pin Signal */
#define SC_PINCSR_CD_REM_F			((uint32_t)0x00000004)			/*!<Card Detect Removal Status Of SC_CD Pin (Read Only) */
#define SC_PINCSR_CD_INS_F			((uint32_t)0x00000008)			/*!<Card Detect Insert Status Of SC_CD Pin (Read Only) */
#define SC_PINCSR_CD_PIN_ST			((uint32_t)0x00000010)			/*!<Card Detect Status Of SC_CD Pin Status (Read Only) */
#define SC_PINCSR_CLK_STOP_LEV		((uint32_t)0x00000020)			/*!<SC Clock Stop Level */
#define SC_PINCSR_CLK_KEEP			((uint32_t)0x00000040)			/*!<SC Clock Enable  */
#define SC_PINCSR_ADAC_CD_EN		((uint32_t)0x00000080)			/*!<Auto Deactivation When Card Removal */
#define SC_PINCSR_SC_OEN_ST			((uint32_t)0x00000100)			/*!<SC Data Output Enable Pin Status (Read Only) */
#define SC_PINCSR_SC_DATA_O			((uint32_t)0x00000200)			/*!<SC Data Output Pin */
#define SC_PINCSR_CD_LEV			((uint32_t)0x00000400)			/*!<Card Detect Level */
#define SC_PINCSR_POW_INV			((uint32_t)0x00000800)			/*!<SC_POW Pin Inverse */
#define SC_PINCSR_SC_DATA_I_ST		((uint32_t)0x00010000)			/*!<SC Data Input Pin Status (Read Only) */

/*---------------------------------------------------------------------------------------------------------*/
/*  SC_TMR0/1/2 Internal Timer Control Mode constants definitions                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_TMR_MODE0_DC				    ((uint32_t)0x00000000)	/*!<Timer0/1/2 Operation Mode 0. 
                                                                    Down Counter start from trigger timer and end to TMR_CNT equal to 0.*/
#define SC_TMR_MODE1_TIMER_DC_S_TO		((uint32_t)0x01000000)	/*!<Timer0/1/2 Operation Mode 1. 
                                                                    Down Counter start from first start bit and end to time-out.*/
#define SC_TMR_MODE2_DC_RX_S_TO		    ((uint32_t)0x02000000)	/*!<Timer0/1/2 Operation Mode 2. 
                                                                    Down Counter start from first reception start bit and end to time-out.*/
#define SC_TMR_MODE3_DC_INITIAL_END	    ((uint32_t)0x03000000)	/*!<Timer0 Operation Mode 3. Timer1/2 don't support Operation Mode 3. 
                                                                    Down Counter start from asserting SC_RST and end to time-out*/
#define SC_TMR_MODE4_DC_RELOAD			((uint32_t)0x04000000)	/*!<Timer0/1/2 Operation Mode 4. 
                                                                    Down Counter start from trigger timer and end to TMR_CNT equal to 0 
                                                                    if DC count to 0, timer will reload and re-count*/
#define SC_TMR_MODE5_DC_RELOAD_S_TO	    ((uint32_t)0x05000000)	/*!<Timer0/1/2 Operation Mode 5. 
                                                                    Down Counter start from first start bit and end to time-out 
                                                                    if DC count to 0, timer will reload and re-count*/
#define SC_TMR_MODE6_DC_RELOAD_RX_S_TO	((uint32_t)0x06000000)	/*!<Timer0/1/2 Operation Mode 6.  
                                                                    Down Counter start from first reception start bit and end to time-out
                                                                    if DC count to 0, timer will reload and re-count. */
#define SC_TMR_MODE7_DC_RELOAD_S_S		((uint32_t)0x07000000)	/*!<Timer0/1/2 Operation Mode 7.  
                                                                    Down Counter start from first start bit and end to next start bit
                                                                    if DC does NOT count to 0 and receive the first start bit, timer will reload and re-count.*/
#define SC_TMR_MODE8_UC				    ((uint32_t)0x08000000)	/*!<Timer0/1/2 Operation Mode 8.
                                                                    Up Counter start from trigger timer and end to stop timer.*/


#define SC_MIN_BUFFER_SIZE             271// 288
#define SC_ATR_ERR_UNRECOGNIZED_MEDIA		-150
#define SC_ATR_ERR_INVALID_PARAMETER		-149
#define SC_ATR_ERR_INVALID_TCK				-148

#define SC_PROTOCOL_T0_OK					0			/* Command OK  */
#define SC_PROTOCOL_T0_ICC_ERROR			-1000		/* ICC comunication error */
#define SC_PROTOCOL_T0_ERROR				-1001		/* T=0 Protocol Error */

#define SC_PROTOCOL_PPS_INVALID			-147

#define SC_PROTOCOL_UNDEFINED		0x00000000  // There is no active protocol.
#define SC_PROTOCOL_T0				0x00000001  // T=0 is the active protocol.
#define SC_PROTOCOL_T1				0x00000002  // T=1 is the active protocol.
#define SC_PROTOCOL_T15				0x00008000  // T=15 is the active protocol.
#define SC_PROTOCOL_RAW				0x00010000  // Raw is the active protocol.

#define SC_STAUS_UNKNOWN			0x0001	/*!< Card status is Unknown state */
#define SC_STAUS_ABSENT			    0x0002	/*!< Card status is absent */
#define SC_STAUS_PRESENT			0x0004	/*!< Card status is present */
#define SC_STAUS_SWALLOWED		    0x0008	/*!< Card status is not powered */
#define SC_STAUS_POWERED			0x0010	/*!< Card status is powered */
#define SC_STAUS_NEGOTIABLE		    0x0020	/*!< Card status is ready for PTS */
#define SC_STAUS_SPECIFIC		    0x0040	/*!< Card status is PTS has been set */

#define SC_T1_BLOCK_MAX_SIZE		259
#define SC_T1_BLOCK_INF_MAX_SIZE	254

/* PCBs */
#define SC_T1_BLOCK_I                0x00
#define SC_T1_BLOCK_R                0x80
#define SC_T1_BLOCK_S                0xC0
//
// constants for the T=1 i/o function
//
#define SC_T1_INIT				0
#define SC_T1_START			    1
#define SC_T1_I_BLOCK			2
#define SC_T1_R_BLOCK			3
#define SC_T1_RESTART			4

#define SC_T1_BLOCK_S_RESYNCH_REQ		0xC0
#define SC_T1_BLOCK_S_RESYNCH_RES		0xE0
#define SC_T1_BLOCK_S_IFS_REQ			0xC1
#define SC_T1_BLOCK_S_IFS_RES			0xE1
#define SC_T1_BLOCK_S_ABORT_REQ			0xC2
#define SC_T1_BLOCK_S_ABORT_RES			0xE2
#define SC_T1_BLOCK_S_WTX_REQ			0xC3
#define SC_T1_BLOCK_S_WTX_RES			0xE3
#define SC_T1_BLOCK_S_VPP_ERR			0xE4
/*****************************************************************************
*
*****************************************************************************/
#define SC_PROTOCOL_T1_OK					0          		/* Command OK  */
#define SC_PROROCOL_T1_P_ERR_NOTICE		    2000			/* T=1 Parity Error Notice */
#define SC_PROTOCOL_T1_ICC_ERROR			-2000       	/* ICC comunication error */
#define SC_PROTOCOL_T1_ERROR				-2001       	/* T=1 Protocol Error */
#define SC_T1_ABORT_RECEIVED				-2002
#define SC_T1_RESYNCH_RECEIVED			    -2003
#define SC_T1_VPP_ERROR_RECEIVED			-2004
#define SC_T1_WTXRES_RECEIVED				-2005
#define SC_T1_IFSRES_RECEIVED				-2006
#define SC_T1_ABORTRES_RECEIVED			    -2007

//
// Information field size the lib uses
//
#define SC_T1_IFSD             254

//
// Maximum attempts to resend a block in T1
//
#define SC_T1_MAX_RETRIES      2

//
// Bit that indenticates if there are more data to send
//
#define SC_T1_MORE_DATA        0x20

//
// T1 Error values
//
#define SC_T1_ERROR_CHKSUM		-1002
#define SC_T1_ERROR_OTHER		-1003
#define SC_T1_ERROR_LENGTH		-1004

//
// Error detection bit as defined by ISO 
//
#define SC_T1_CRC_CHECK        1

//
// Character waiting integer default value as definded by ISO
//
#define SC_T1_CWI_DEFAULT      13

//
// Block waiting integer default value as definded by ISO
//
#define SC_T1_BWI_DEFAULT      4

//
// Receiving an ATR shall have a duration of less than or equal to initial etus
//
#define SC_ATR_TOTAL_TIME		20050


#define SC_ERR_ID        0xffff2000

#define SC_MAX_ATR_LEN					(33)
#define SC_MAX_BUF_LEN					(500)
#define SC_MAX_CMD_LEN					(262)	/* header : 5, data : 256(max), le : 1, plus all 262 */


/* iso7816 operation class */
#define SC_ISO_OPERATIONCLASS_AUTO			(0x00)
#define SC_ISO_OPERATIONCLASS_A				(0x01)
#define SC_ISO_OPERATIONCLASS_B				(0x02)
#define SC_ISO_OPERATIONCLASS_C				(0x03)

// Current card operation in ISR
#define SC_OP_NOP					(0x00)
#define SC_OP_ATR_READ			    (0x01)
#define SC_OP_READ					(0x02)
#define SC_OP_WRITE				    (0x03)

// status successful
#define SC_STATUS_SUCCESS               0

// error code 
#define SC_ERR_CARD_REMOVED			-120
#define SC_ERR_OVER_RUN				-119
#define SC_ERR_PARITY_ERROR			-118
#define SC_ERR_NO_STOP				-117
#define SC_ERR_SILENT_BYTE			-116
#define SC_ERR_CMD				    -115
#define SC_ERR_UNSUPPORTEDCARD		-114
#define SC_ERR_READ					-113
#define SC_ERR_WRITE			    -112
#define SC_ERR_TIME0OUT            	-111
#define SC_ERR_TIME1OUT            	-110
#define SC_ERR_TIME2OUT            	-109
#define SC_ERR_AUTOCONVENTION    	-108
#define SC_ERR_BGTIMEOUT		   	-107


// These are the error code actually returns to user application
#define SC_EIO							(1| SC_ERR_ID)
#define SC_ENODEV						(2| SC_ERR_ID)
#define SC_ENOMEM						(3| SC_ERR_ID)
#define SC_EBUSY						(4| SC_ERR_ID)
#define SC_ENOTTY						(5| SC_ERR_ID)
#define SC_EPROTOCOL					(6| SC_ERR_ID)  
#define SC_EPARAMETER					(7| SC_ERR_ID)



/* ATRIB = A(nswer) T(o) R(eset) I(nterface) B(yte) */
#define SC_ATR_INTERFACE_BYTE_TA		0	/* Interface byte TAi */
#define SC_ATR_INTERFACE_BYTE_TB		1	/* Interface byte TBi */
#define SC_ATR_INTERFACE_BYTE_TC		2	/* Interface byte TCi */
#define SC_ATR_INTERFACE_BYTE_TD		3	/* Interface byte TDi */

// Reset type
#define SC_COLDRESET                (0x1)
#define SC_WARMRESET                (0x2)

#define SC_GET_ONE_BYTE()		                ((SC->RBR & 0xff))
#define SC_PUT_ONE_BYTE(data)		            (SC->THR = data)


/*---------------------------------------------------------------------------------------------------------*/
/*  Define parameter checking                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define SC_CHECK_SC_PORT(port)				((port==SC0) || (port==SC1) || (port==SC2))


/*---------------------------------------------------------------------------------------------------------*/
/*  Define EMV checking                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
//#define SC_EMV_ATR_CHECK		1		/* 1: Enable to check integrity of ATR for EMV */

//#define SC_DEBUG_ENABLE_ENTER_LEAVE
//#define SC_IST_DEBUG				/* IST information check in SC.c */
//#define SC_ATR_DEBUG				/* ATR information check in SC.c */
//#define SC_RD_DEBUG				/* Send/Receive check in SC_Reader.c */
//#define SC_T1_DEBUG				/* T1 protocol check in SC_Protocol.c */

#ifdef SC_DEBUG_ENABLE_ENTER_LEAVE
#define SC_ENTER()					printf("[%-20s] : Enter...\n", __func__)
#define SC_LEAVE()					printf("[%-20s] : Leave...\n", __func__)
#else
#define SC_ENTER()
#define SC_LEAVE()
#endif


#ifdef SC_ATR_DEBUG
#define SC_DEBUG     printf
#else
#define SC_DEBUG(...)
#endif


#ifdef SC_IST_DEBUG
#define SC_ISTDEBUG     printf
#else
#define SC_ISTDEBUG(...)
#endif


#ifdef SC_RD_DEBUG
#define SC_RDDEBUG     printf
#else
#define SC_RDDEBUG(...)
#endif


#ifdef SC_T1_DEBUG
#define SC_T1DEBUG     printf
#else
#define SC_T1DEBUG(...)
#endif

/*---------------------------------------------------------------------------------------------------------*/
/* Smart Card data type conversion structure                                                               */
/*---------------------------------------------------------------------------------------------------------*/
typedef union {
    
    struct {

        unsigned long   l0;

    } l;

    struct {

        uint8_t   b0;
        uint8_t   b1;
        uint8_t   b2;
        uint8_t   b3;
    } b;

} S_SC_LENGTH;


typedef struct {

    // Number of data bytes in this request
    int32_t   Lc;

    // Number of expected bytes from the card
    int32_t   Le;

} S_SC_T0_DATA;


typedef struct {

    // Current information field size that can be transmitted
    uint8_t   IFSC;

    // Current information field size we can receive
    uint8_t   IFSD;

	// Record if received I-block was sent correctly from ICC
	uint8_t   IBLOCK_REC;

    // The 'number' of received I-Blocks
    uint8_t   RSN;

    // The 'number' of sent I-Blocks as defined in ISO 7816-3
    uint8_t   SSN;

    //
    // Waiting time extension requested by the smart card
    // This value should be used by the driver to extend block waiting time.
    //
    uint8_t   Wtx;

} S_SC_T1_DATA;

/*---------------------------------------------------------------------------------------------------------*/
/* This struct is used by the lib for T1 I/O                                                               */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct {  
    uint8_t   Nad;
    uint8_t   Pcb;
    uint8_t   Len;
    uint8_t *  Inf;
} S_SC_T1_BLOCK_FRAME;


/*---------------------------------------------------------------------------------------------------------*/
/* Clock rate conversion table according to ISO structure                                                  */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct {

    const unsigned long F;
    const unsigned long fs; 

} S_SC_CLOCK_RATE_CONVERSION;

//
// Bit rate adjustment factor 
// The layout of this table has been slightly modified due to 
// the unavailibility of floating point math support in the kernel.
// The value D has beed devided into a numerator and a divisor.
//
typedef struct {
    const unsigned long DNumerator;
    const unsigned long DDivisor;
} S_SC_BIT_RATE_ADJUSTMENT;

//
// The clock rate conversion table itself.
// All R(eserved)F(or Future)U(se) fields MUST be 0
//
static S_SC_CLOCK_RATE_CONVERSION ClockRateConversion[] = {

        { 372,  4000000     }, 
        { 372,  5000000     }, 
        { 558,  6000000     }, 
        { 744,  8000000     }, 
        { 1116, 12000000    }, 
        { 1488, 16000000    },
        { 1860, 20000000    },
        { 0,    0            },
        { 0,    0            },
        { 512,  5000000     },
        { 768,  7500000     },
        { 1024, 10000000    },
        { 1536, 15000000    },
        { 2048, 20000000    },
        { 0,    0            },
        { 0,    0            }
};      

//
// The bit rate adjustment table itself.
// All R(eserved)F(or)U(se) fields MUST be 0
//
static S_SC_BIT_RATE_ADJUSTMENT BitRateAdjustment[] = {

    { 0,    0   },
    { 1,    1   },
    { 2,    1   },
    { 4,    1   },
    { 8,    1   },
    { 16,   1   },
    { 32,   1   },
    { 64,   1   },
    { 12,   1   },
    { 20,   1   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   },
    { 0,    0   }
};


//
// This struct holds information for the card currently in use
// The driver must store a received ATR into the ATR struct which is
// part of this struct. The lib will get all other information 
// out of the ATR.
//
typedef struct{

    // Flag that indicates that the current card uses invers convention
    bool InversConvention;

    // Calculated etu 
    unsigned long   etu;        // micro-second unit ; etu = F/D * 1/f
      
    //
    // Answer To Reset string returned by card.
    // Use OsData->SpinLock to access this member
    //
    struct {

        uint8_t Buffer[64];
        uint8_t Length;

    } ATR;

    struct {

        uint8_t Buffer[16];
        uint8_t Length;

    } HistoricalChars;

    // !!! DO NOT MODIFY ANY OF THE BELOW VALUES
    // OTHERWISE THE LIBRARY WON'T WORK PROPERLY

    // Clock rate conversion 
    uint8_t Fl;

    // Bit rate adjustment
    uint8_t Dl;

    // Maximum programming current      // not understand how to use it???
    uint8_t II;

    // Programming voltage in .1 Volts  // not understand how to use it???
    uint8_t P;

    // Extra guard time in etu 
    uint8_t N;

    // Calculated guard time in micro seconds
    unsigned long GT;

    struct {

		// This is a bit mask of the supported protocols
		unsigned long Supported;
		// The currently selected protocol
		unsigned long Selected;

    } Protocol;

    // T=0 specific data
    struct {

        // Waiting integer
        uint8_t WI;

        // Waiting time in micro seconds
        unsigned long WT;

    } T0;

    // T=1 specific data
    struct {

        // Information field size of card
        uint8_t IFSC;

        // Character waiting integer and block waiting integer
        uint8_t CWI;
        uint8_t BWI;

        // Error detection code
        uint8_t EDC;

        // Character and block waiting time in micro seconds
        unsigned long CWT;
        unsigned long BWT;

        // Block guarding time in micro seconds
        unsigned long BGT;

    } T1;

} S_SC_SCARD_CARD_CAPABILITIES;

/*---------------------------------------------------------------------------------------------------------*/
/* SmartCard Data Structure                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
  
typedef struct 
{
	SC_T *base /*, num*/;
	volatile uint32_t op_state;		/* 0 - everything goes well, 1 - some error occured */
	volatile int32_t errno;
	volatile uint32_t openflag;
	volatile uint32_t clock;			/* frequence in KHz */
	uint32_t clock_stop_level;
	volatile uint32_t etu; 			/* in millisecond */
	volatile uint32_t voltage;
	volatile int8_t ActivePowerPin;		/* 1: active High 0: active Low */

    // Capabilities of the current inserted card
    S_SC_SCARD_CARD_CAPABILITIES CardCapabilities;

    //
    // Current state of reader (card present/removed/activated)
    // Use OsData->SpinLock to access this member
    // (mandatory)
    // use for PPS
    unsigned long   CurrentState;

	uint8_t *snd_buf, *rcv_buf;  
	volatile int32_t snd_pos, snd_len;
    volatile int32_t rcv_len, rcv_pos;
	volatile int32_t rcv_cnt;  // cnt is current received data number in write stage read index in read stage
	volatile uint32_t bCardRemoved /* , bCardChanged */;
	int8_t pps_complete; //[20120720]

    // Data for T=0
    S_SC_T0_DATA T0;
    
    // Data for T=1
    S_SC_T1_DATA T1;

}S_SC_DEV_T;


typedef void (SC_PFN_CALLBACK)(void);
  

//  function prototypes: DrvSMARTCARD.c
void SC_TimerINTEnable(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerINTDisable(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerCountSet(S_SC_DEV_T *dev, uint32_t no, uint32_t op_mode, uint32_t cnt);
void SC_WaitFirstReceivedData(S_SC_DEV_T *dev, uint32_t no, uint32_t op_mode, uint32_t cnt);
void SC_TimerStop(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerAllStop(S_SC_DEV_T *dev);
void SC_TimerStart(S_SC_DEV_T *dev, uint32_t no);
void SC_TimerSelect(S_SC_DEV_T *dev, uint32_t type);
int32_t SC_WarmReset(S_SC_DEV_T *dev);
int32_t SC_DoPPS(S_SC_DEV_T *dev, int32_t f, int32_t d, int32_t t);
void SC_DeactivationCmd(S_SC_DEV_T *dev);
void SC_ActivationCmd(S_SC_DEV_T *dev);
void SC_WarmResetCmd(S_SC_DEV_T *dev);
void SC_SetGuardTime(S_SC_DEV_T *dev);
void SC_SetBlockGuardTime(S_SC_DEV_T *dev, uint32_t bgt);
void SC_StartBlockGuardTime( S_SC_DEV_T *dev );
void SC_StopBlockGuardTime( S_SC_DEV_T *dev );
void SC_ClearFIFO(S_SC_DEV_T *dev);
uint8_t * SC_ErrMsg(long errno);
int32_t SC_CheckCardPresent(SC_T *portno);
int32_t SC_ColdReset(S_SC_DEV_T *dev);
void SC_SetClockState(S_SC_DEV_T *dev, int8_t onoff);
void SC_ClockStopLevel(S_SC_DEV_T *dev);
void SC_VoltageConfig(S_SC_DEV_T *dev);
void SC_SetReaderParameter(S_SC_DEV_T *dev);
int32_t SC_PowerActiveLevel(SC_T *portno, int8_t active);
int32_t SC_IgnoreCardAbsent(SC_T *portno);
int32_t SC_CardDetectEdge(SC_T *portno, int8_t edge);

int32_t SC_UpdateCardCapabilities(S_SC_DEV_T *dev);



int32_t SC_Init(SC_T *portno);
int32_t SC_Open(SC_T *portno);
int32_t SC_Close(SC_T *portno);
int32_t SC_GetATRBuffer(SC_T *portno, uint8_t *buf, int16_t length);
int32_t SC_InstallCallBack(SC_T *portno, SC_PFN_CALLBACK pfncallback);

/**
 * @brief      Get Smart Card Clock Source Frequency
 *
 * @param[in]  SC             Smart card port 
 *                            - SC0 : Smart Card port 0
 *                            - SC1 : Smart Card port 1
 *                            - SC2 : Smart Card port 2 
 * @return     Smart card clock source frequency
 * @details    Get smart card clock source frequency for specified port.
 * 
 */
static __INLINE uint32_t SC_GetSmartCardClockSourceFreq(SC_T* SC)
{
    uint32_t u32ClkTbl[4] = {__XTAL, 0, 0, __IRC22M};
    uint32_t u32SCxEngineClk = 0;
    
    u32ClkTbl[1] = PllClock;
    u32ClkTbl[2] = SystemCoreClock;  
    if((SC)==SC0)
    {
        u32SCxEngineClk = SYSCLK->CLKSEL3&SYSCLK_CLKSEL3_SC0_S_Msk;  
    }   
    else if((SC)==SC1)
    {
        u32SCxEngineClk = (SYSCLK->CLKSEL3&SYSCLK_CLKSEL3_SC1_S_Msk)>>SYSCLK_CLKSEL3_SC1_S_Pos;         
    }   
    else if((SC)==SC2)
    {
        u32SCxEngineClk = (SYSCLK->CLKSEL3&SYSCLK_CLKSEL3_SC2_S_Msk)>>SYSCLK_CLKSEL3_SC2_S_Pos;         
    }     
                                           
    return u32ClkTbl[u32SCxEngineClk];    
}



/**
  * @} End of SMARTCARD Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 



#endif		/* __SC_H__ */

/*** (C) COPYRIGHT 2011 Nuvoton Technology Corp. ***/



