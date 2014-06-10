/**************************************************************************//**
 * @file     sc.h
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series Smartcard (SC) driver header file
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __SC_H__
#define __SC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_SC_Driver SC Driver
  @{
*/

/** @addtogroup NUC400_SC_EXPORTED_CONSTANTS SC Exported Constants
  @{
*/
#define SC_INTERFACE_NUM        6                /*!< Smartcard interface numbers */
#define SC_PIN_STATE_HIGH       1                /*!< Smartcard pin status high   */
#define SC_PIN_STATE_LOW        0                /*!< Smartcard pin status low    */
#define SC_PIN_STATE_IGNORE     0xFFFFFFFF       /*!< Ignore pin status           */
#define SC_CLK_ON               1                /*!< Smartcard clock on          */
#define SC_CLK_OFF              0                /*!< Smartcard clock off         */

#define SC_TMR_MODE_0                   (0ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 0, down count                                                      */
#define SC_TMR_MODE_1                   (1ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 1, down count, start after detect start bit                        */
#define SC_TMR_MODE_2                   (2ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 2, down count, start after receive start bit                       */
#define SC_TMR_MODE_3                   (3ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 3, down count, use for activation, only timer 0 support this mode  */
#define SC_TMR_MODE_4                   (4ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 4, down count with reload after timeout                            */
#define SC_TMR_MODE_5                   (5ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 5, down count, start after detect start bit, reload after timeout  */
#define SC_TMR_MODE_6                   (6ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 6, down count, start after receive start bit, reload after timeout */
#define SC_TMR_MODE_7                   (7ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 7, down count, start and reload after detect start bit             */
#define SC_TMR_MODE_8                   (8ul << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 8, up count                                                        */
#define SC_TMR_MODE_F                   (0xF << SC_TMR0_MODE_Pos)     /*!<Timer Operation Mode 15, down count, reload after detect start bit                      */


/*@}*/ /* end of group NUC400_SC_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_SC_EXPORTED_FUNCTIONS SC Exported Functions
  @{
*/

/**
  * @brief This macro enable smartcard interrupt
  * @param sc Base address of smartcard module
  * @param u32Mask Interrupt mask to be enabled. A combination of
  *             - \ref SC_IER_ACON_ERR_IE_Msk
  *             - \ref SC_IER_RTMR_IE_Msk
  *             - \ref SC_IER_INIT_IE_Msk
  *             - \ref SC_IER_CD_IE_Msk
  *             - \ref SC_IER_BGT_IE_Msk
  *             - \ref SC_IER_TMR2_IE_Msk
  *             - \ref SC_IER_TMR1_IE_Msk
  *             - \ref SC_IER_TMR0_IE_Msk
  *             - \ref SC_IER_TERR_IE_Msk
  *             - \ref SC_IER_TBE_IE_Msk
  *             - \ref SC_IER_RDA_IE_Msk
  * @return None
  * \hideinitializer
  */
#define SC_ENABLE_INT(sc, u32Mask) ((sc)->IER |= (u32Mask))

/**
  * @brief This macro disable smartcard interrupt
  * @param sc Base address of smartcard module
  * @param u32Mask Interrupt mask to be disabled. A combination of
  *             - \ref SC_IER_ACON_ERR_IE_Msk
  *             - \ref SC_IER_RTMR_IE_Msk
  *             - \ref SC_IER_INIT_IE_Msk
  *             - \ref SC_IER_CD_IE_Msk
  *             - \ref SC_IER_BGT_IE_Msk
  *             - \ref SC_IER_TMR2_IE_Msk
  *             - \ref SC_IER_TMR1_IE_Msk
  *             - \ref SC_IER_TMR0_IE_Msk
  *             - \ref SC_IER_TERR_IE_Msk
  *             - \ref SC_IER_TBE_IE_Msk
  *             - \ref SC_IER_RDA_IE_Msk
  * @return None
  * \hideinitializer
  */
#define SC_DISABLE_INT(sc, u32Mask) ((sc)->IER &= ~(u32Mask))

/**
  * @brief This macro set VCC pin state of smartcard interface
  * @param sc Base address of smartcard module
  * @param u32State Pin state of VCC pin, valid parameters are \ref SC_PIN_STATE_HIGH and \ref SC_PIN_STATE_LOW
  * @return None
  * \hideinitializer
  */
#define SC_SET_VCC_PIN(sc, u32State) \
    do {\
            while(sc->PINCSR & SC_PINCSR_SYNC_Msk);\
            if(u32State)\
                (sc)->PINCSR |= SC_PINCSR_POW_EN_Msk;\
            else\
                (sc)->PINCSR &= ~SC_PINCSR_POW_EN_Msk;\
    }while(0)


/**
  * @brief This macro turns CLK output on or off
  * @param sc Base address of smartcard module
  * @param u32OnOff Clock on or off for selected smartcard module, valid values are \ref SC_CLK_ON and \ref SC_CLK_OFF
  * @return None
  * \hideinitializer
  */
#define SC_SET_CLK_PIN(sc, u32OnOff)\
    do {\
            while(sc->PINCSR & SC_PINCSR_SYNC_Msk);\
            if(u32OnOff)\
                (sc)->PINCSR |= SC_PINCSR_CLK_KEEP_Msk;\
            else\
                (sc)->PINCSR &= ~(SC_PINCSR_CLK_KEEP_Msk);\
    }while(0)

/**
  * @brief This macro set I/O pin state of smartcard interface
  * @param sc Base address of smartcard module
  * @param u32State Pin state of I/O pin, valid parameters are \ref SC_PIN_STATE_HIGH and \ref SC_PIN_STATE_LOW
  * @return None
  * \hideinitializer
  */
#define SC_SET_IO_PIN(sc, u32State)\
    do {\
            while(sc->PINCSR & SC_PINCSR_SYNC_Msk);\
            if(u32State)\
                (sc)->PINCSR |= SC_PINCSR_SC_DATA_O_Msk;\
            else\
                (sc)->PINCSR &= ~SC_PINCSR_SC_DATA_O_Msk;\
    }while(0)

/**
  * @brief This macro set RST pin state of smartcard interface
  * @param sc Base address of smartcard module
  * @param u32State Pin state of RST pin, valid parameters are \ref SC_PIN_STATE_HIGH and \ref SC_PIN_STATE_LOW
  * @return None
  * \hideinitializer
  */
#define SC_SET_RST_PIN(sc, u32State)\
    do {\
            while(sc->PINCSR & SC_PINCSR_SYNC_Msk);\
            if(u32State)\
                (sc)->PINCSR |= SC_PINCSR_SC_RST_Msk;\
            else\
                (sc)->PINCSR &= ~SC_PINCSR_SC_RST_Msk;\
    }while(0)

/**
  * @brief This macro read one byte from smartcard module receive FIFO
  * @param sc Base address of smartcard module
  * @return One byte read from receive FIFO
  * \hideinitializer
  */
#define SC_READ(sc) ((char)((sc)->RBR))

/**
  * @brief This macro write one byte to smartcard module transmit FIFO
  * @param sc Base address of smartcard module
  * @param u8Data Data to write to transmit FIFO
  * @return None
  * \hideinitializer
  */
#define SC_WRITE(sc, u8Data) ((sc)->THR = (u8Data))

/**
  * @brief This macro set smartcard stop bit length
  * @param sc Base address of smartcard module
  * @param u32Len Stop bit length, ether 1 or 2.
  * @return None
  * @details Stop bit length must be 1 for T = 1 protocol and 2 for T = 0 protocol.
  * \hideinitializer
  */
#define SC_SET_STOP_BIT_LEN(sc, u32Len) ((sc)->CTL = ((sc)->CTL & ~SC_CTL_SLEN_Msk) | (u32Len == 1 ? 1 : 0))

/**
  * @brief  Enable/Disable Tx error retry, and set Tx error retry count
  * @param  sc Base address of smartcard module
  * @param  u32Count The number of times of Tx error retry count, between 0~8. 0 means disable Tx error retry
  * @return None
  */
__STATIC_INLINE void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    while(sc->CTL & SC_CTL_SYNC_Msk);
    if(u32Count == 0) {       // disable Tx error retry
        sc->CTL &= ~(SC_CTL_TX_ERETRY_Msk | SC_CTL_TX_ERETRY_EN_Msk);
    } else {
        sc->CTL = (sc->CTL & ~SC_CTL_TX_ERETRY_Msk) | ((u32Count - 1) << SC_CTL_TX_ERETRY_Pos) | SC_CTL_TX_ERETRY_EN_Msk;
    }
}

/**
  * @brief  Enable/Disable Rx error retry, and set Rx error retry count
  * @param  sc Base address of smartcard module
  * @param  u32Count The number of times of Rx error retry count, between 0~8. 0 means disable Rx error retry
  * @return None
  */
__STATIC_INLINE void  SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    while(sc->CTL & SC_CTL_SYNC_Msk);
    if(u32Count == 0) {       // disable Rx error retry
        sc->CTL &= ~(SC_CTL_RX_ERETRY_Msk | SC_CTL_RX_ERETRY_EN_Msk);
    } else {
        sc->CTL = (sc->CTL & ~SC_CTL_RX_ERETRY_Msk) | ((u32Count - 1) << SC_CTL_RX_ERETRY_Pos) | SC_CTL_RX_ERETRY_EN_Msk;
    }
}


uint32_t SC_IsCardInserted(SC_T *sc);
void SC_ClearFIFO(SC_T *sc);
void SC_Close(SC_T *sc);
void SC_Open(SC_T *sc, uint32_t u32CardDet, uint32_t u32PWR);
void SC_ResetReader(SC_T *sc);
void SC_SetBlockGuardTime(SC_T *sc, uint32_t u32BGT);
void SC_SetCharGuardTime(SC_T *sc, uint32_t u32CGT);
void SC_StopAllTimer(SC_T *sc);
void SC_StartTimer(SC_T *sc, uint32_t u32TimerNum, uint32_t u32Mode, uint32_t u32ETUCount);
void SC_StopTimer(SC_T *sc, uint32_t u32TimerNum);


/*@}*/ /* end of group NUC400_SC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_SC_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__SC_H__

/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/
