/**************************************************************************//**
 * @file     TIMER.h
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 12/08/06 8:08p $
 * @brief    NUC200 Series Timer Controller Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __TIMER_H__
#define __TIMER_H__

#include "NUC200Series.h"

/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup TIMER_FUNC TIMER Device Function Interface
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* TCSR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define TIMER_TCSR_CEN_ENABLE           0x40000000UL /*!< Enable Timer to start counting         */
#define TIMER_TCSR_CEN_DISABLE          0x00000000UL /*!< Disable Timer to stop/suspend counting */
#define TIMER_TCSR_IE_ENABLE            0x20000000UL /*!< Enable Timer Interrupt function  */
#define TIMER_TCSR_IE_DISABLE           0x00000000UL /*!< Disable Timer Interrupt function */
#define TIMER_TCSR_MODE_ONESHOT         0x00010000UL /*!< Specify Timer One-Shot mode and enable TDR            */
#define TIMER_TCSR_MODE_PERIODIC        0x08010000UL /*!< Specify Timer Periodic mode and enable TDR            */
#define TIMER_TCSR_MODE_TOGGLE          0x10010000UL /*!< Specify Timer Toggle mode and enable TDR              */
#define TIMER_TCSR_MODE_CONTINUOUS      0x18010000UL /*!< Specify Timer Continuous Counting mode and enable TDR */
#define TIMER_TCSR_CRST                 0x04000000UL /*!< Reset Timer          */
#define TIMER_TCSR_CTB_ENABLE           0x01000000UL /*!< Enable Counter Mode  */
#define TIMER_TCSR_CTB_DISABLE          0x00000000UL /*!< Disable Counter Mode */
#define TIMER_TCSR_WAKE_EN_ENABLE       0x00800000UL /*!< Enable Timer Wake up function  */
#define TIMER_TCSR_WAKE_EN_DISABLE      0x00000000UL /*!< Disable Timer Wake up function */
#define TIMER_TCSR_TDR_EN_ENABLE        0x00010000UL /*!< Enable Timer Data Load function  */
#define TIMER_TCSR_TDR_EN_DISABLE       0x00000000UL /*!< Disable Timer Data Load function */
#define TIMER_TCSR_PRESCALE(x)          ((x)-1)      /*!< TCSR setting for prescale. 1 <= x <= 256 */


/*---------------------------------------------------------------------------------------------------------*/
/* TEXCON Constants Definitions                                                                            */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define TIMER_TEXCON_TCDB_ENABLE        0x80UL /*!< Enable Timer Counter pin de-bounce  */
#define TIMER_TEXCON_TCDB_DISABLE       0x00UL /*!< Disable Timer Counter pin de-bounce */
#define TIMER_TEXCON_TEXDB_ENABLE       0x40UL /*!< Enable Timer Capture pin de-bounce  */
#define TIMER_TEXCON_TEXDB_DISABLE      0x00UL /*!< Disable Timer Capture pin de-bounce */
#define TIMER_TEXCON_TEXIEN_ENABLE      0x20UL /*!< Enable Timer Capture pin interrupt  */
#define TIMER_TEXCON_TEXIEN_DISABLE     0x00UL /*!< Disable Timer Capture pin interrupt */
#define TIMER_TEXCON_MODE_RESET_COUNT   0x10UL /*!< Transition on Timer Capture pin is using to reset the timer counter    */
#define TIMER_TEXCON_MODE_CAP           0x00UL /*!< Transition on Timer Capture pin is using as the Timer Capture function */
#define TIMER_TEXCON_TEXEN_ENABLE       0x08UL /*!< Enable Timer Capture pin function   */
#define TIMER_TEXCON_TEXEN_DISABLE      0x00UL /*!< Disable Timer Capture pin function  */
#define TIMER_TEXCON_TEX_EDGE_BOTH      0x04UL /*!< Capture pin will generate a detected signal both on 0 to 1 and 1 to 0 transition. */
#define TIMER_TEXCON_TEX_EDGE_RISING    0x02UL /*!< Capture pin will generate a detected signal only on 0 to 1 transition.            */
#define TIMER_TEXCON_TEX_EDGE_FALLING   0x00UL /*!< Capture pin will generate a detected signal only on 1 to 0 transition.            */
#define TIMER_TEXCON_TX_PHASE_RISING    0x01UL /*!< Counter pin will generate a count when transition from 0 to 1 on Counter pin */
#define TIMER_TEXCON_TX_PHASE_FALLING   0x00UL /*!< Counter pin will generate a count when transition from 1 to 0 on Counter pin */


/*---------------------------------------------------------------------------------------------------------*/
/* TIMER Macro Definitions                                                                                 */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     Predefined timer TCSR setting for enable periodic timer but disable interrupt. 1 <= x <= 256
 */
#define TIMER_TCSR_INIT(x)              (TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_CEN_Msk | TIMER_TCSR_PRESCALE(x))


/**
 * @details     Predefined timer TCSR setting for enable periodic timer and enable interrupt. 1 <= x <= 256
 */
#define TIMER_TCSR_INIT_IE(x)           (TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk | TIMER_TCSR_PRESCALE(x))


/**
 * @brief       Start Timer Counting
 *
 * @param[in]   TIMER       TIMER port. It could be TIMER0, TIMER1, TIMER2, TIMER3.
 * @param[in]   tcsr        TCSR register settings of specified TIMER port.
 * @param[in]   presacle    Timer clock input will be divided by presacle.
 *
 * @return      None
 *
 * @details     To start Timer counting by TCSR settings.
 */
#define _TIMER_START(TIMER, tcsr, presacle)     ((TIMER)->TCSR = ((tcsr) | TIMER_TCSR_PRESCALE(presacle) | TIMER_TCSR_CEN_ENABLE))    


/**
 * @brief       Enable Timer Capture Function
 *
 * @param[in]   TIMER       TIMER port. It could be TIMER0, TIMER1, TIMER2, TIMER3.
 * @param[in]   texcon      TEXCON register settings of specified TIMER port.
 *
 * @return      None
 *
 * @details     To enable Timer capture function to get current TDR or reset Timer counter when transition on external capture pin.
 */
#define _TIMER_ENABLE_CAPTURE(TIMER, texcon)     ((TIMER)->TEXCON = ((texcon) | TIMER_TEXCON_TEXEN_ENABLE))    


/**
 * @details     To reset the 24-bit up-timer, 8-bit pre-scale counter and also force CEN to 0. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_RESET(TIMER)                     ((TIMER)->TCSR = TIMER_TCSR_CRST)    


/**
 * @details     Set Timer Compared Value for specified Timer channel. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_SET_CMP_VALUE(TIMER, value)      ((TIMER)->TCMPR = value)    


/**
 * @details     Get Timer Compare Match Interrupt Flag. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_GET_CMP_INT_FLAG(TIMER)          (((((TIMER)->TISR) & TIMER_TISR_TIF_Msk) == TIMER_TISR_TIF_Msk)? 1:0)


/**
 * @details     Clear Timer Compare Match Interrupt Flag to 0. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_CLEAR_CMP_INT_FLAG(TIMER)        ((TIMER)->TISR = TIMER_TISR_TIF_Msk)
                                               

/**
 * @details     Get Timer Wakeup Interrupt Flag. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_GET_WAKEUP_INT_FLAG(TIMER)       (((((TIMER)->TISR) & TIMER_TISR_TWF_Msk) == TIMER_TISR_TWF_Msk)? 1:0)


/**
 * @details     Clear Timer Wakeup Interrupt Flag to 0. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_CLEAR_WAKEUP_INT_FLAG(TIMER)     ((TIMER)->TISR = TIMER_TISR_TWF_Msk)
                                               

/**
 * @details     Get Timer TDR value. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_GET_TDR(TIMER)                   ((TIMER)->TDR)


/**
 * @details     Get Timer Capture Data value. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_GET_TCAP(TIMER)                   ((TIMER)->TCAP)


/**
 * @details     Get Interrupt Flag for Capture pin. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_GET_CAP_INT_FLAG(TIMER)          (((((TIMER)->TEXISR) & TIMER_TEXISR_TEXIF_Msk) == TIMER_TEXISR_TEXIF_Msk)? 1:0)


/**
 * @details     Clear Interrupt Flag to 0 for Capture pin. TIMER = TIMER0, TIMER1, TIMER2 or TIMER3
 */
#define _TIMER_CLEAR_CAP_INT_FLAG(TIMER)        ((TIMER)->TEXISR = TIMER_TEXISR_TEXIF_Msk)


/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief       Get Timer Clock Source Frequency
 *
 * @param[in]   eTimerCH    E_TMR0 / E_TMR1 / E_TMR2 / E_TMR3
 *
 * @return      Timer clock frequency (Hz)
 *
 * @details     Get the specified Timer clock source frequency.
 */
static __INLINE uint32_t TIMER_GetClockFreq(uint32_t eTimerCH)
{
    uint8_t u8TMRClkSrcSel;
    uint32_t u32ClkSrcTbl[] = {__XTAL, __RTC_XTAL, 0, 0, 0, __IRC10K, 0, __IRC22M};
        
    u32ClkSrcTbl[2] = SystemCoreClock;

    u8TMRClkSrcSel = (SYSCLK->CLKSEL1 >> (8+(eTimerCH*4))) & 0x7;

    return u32ClkSrcTbl[u8TMRClkSrcSel]; 
}


/**
 * @brief       Calculate Timer Initial Value
 *
 * @param[in]   u32ClockValue   Input the Timer clock frequency (Hz)
 * @param[in]   u32TicksPerSec  Specify the ticks per second
 *
 * @return      Return 32 bits unsigned integer where \n
 *                  bits [ 0:23] - TCMP of Timer Compare Register, the range is 0 ~ 0xFFFFFF. \n
 *                  bits [24:31] - PRESCALE of Timer Control Register, the range is 0 ~ 0xFF.
 *
 * @details     Calculate the Timer Compare Value and pre-scale counter of Timer. \n
 *              The target Timer clock input is divided by (PRESCALE + 1).
 */
static __INLINE uint32_t TIMER_CalInitValue(uint32_t u32ClockFreq, uint32_t u32TicksPerSec)
{
    uint32_t u32Prescale;
    uint32_t u32FinalTCMPR;

    for (u32Prescale=1; u32Prescale<256; u32Prescale++)
    {
        u32FinalTCMPR = u32ClockFreq / (u32TicksPerSec*u32Prescale);

        /* The TCMPR value must > 1 */
        if ((u32FinalTCMPR > 1) && (u32FinalTCMPR < 0x1000000))
            return (((u32Prescale-1) << 24) | u32FinalTCMPR);
    }
    
    return (uint32_t)-1;
}


/**
  * @} End of TIMER Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 


#endif  // __TIMER_H__ 
