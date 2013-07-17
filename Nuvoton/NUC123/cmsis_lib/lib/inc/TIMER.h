/******************************************************************************
 * @file     Timer.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/14 15:12p $
 * @brief    NUC123 Series Timer Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef  __TIMER_H
#define  __TIMER_H

#include  "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup TIMER_MACRO Timer Macro
  * @{
  */

/** @addtogroup TIMER_MACRO_CONTANT Timer Macro Contant
  * @{
  */

//// TIMER0->TCSR, TIMER1->TCSR, TIMER2->TCSR, TIMER3->TCSR /////////////////////////////
#define  TIM_DEBUG_MODE            (1ul << TIMER_TCSR_DBGACK_TMR_Pos)//Enable debug mode
#define  TIM_EN                    (1ul << TIMER_TCSR_CEN_Pos)       //Count enable
#define  TIM_INT_EN                (1ul << TIMER_TCSR_IE_Pos)        //Enable interrupt
#define  TIM_MODE_ONCE             (0   << TIMER_TCSR_MODE_Pos)      //Timer work in one time mode
#define  TIM_MODE_PERIODIC         (1ul << TIMER_TCSR_MODE_Pos)      //Timer work in periodic mode
#define  TIM_MODE_TOGGLE           (2ul << TIMER_TCSR_MODE_Pos)      //Timer work in toggle mode
#define  TIM_MODE_CONTINUOUS       (3ul << TIMER_TCSR_MODE_Pos)      //Timer work in continuous mode
#define  TIM_RST                   (1ul << TIMER_TCSR_CACT_Pos)      //Reset Timer
#define  TIM_ACTIVE                (1ul << TIMER_TCSR_CACT_Pos)	     //Timer is actived
#define  TIM_COUNT_MODE            (1ul << TIMER_TCSR_CTB_Pos)	     //Timer work in count mode
#define  TIM_WAKEUP_EN             (1ul << TIMER_TCSR_WAKE_EN_Pos)	 //Timer expire workup enable
#define  TIM_READ_EN               (1ul << TIMER_TCSR_TDR_EN_Pos)    //Read Timer enable

//// TIMER0->TISR, TIMER1->TISR, TIMER2->TISR, TIMER3->TISR /////////////////////////////
#define  TIM_WAKEUP_FLAG            (1ul << TIMER_TISR_TWF_Pos)	     //Timer wake up CPU
#define  TIM_INT_FLAG              (1ul << TIMER_TISR_TIF_Pos)	     //Timer caused interrupt

//// TIMER0->TEXCON, TIMER1->TEXCON, TIMER2->TEXCON, TIMER3->TEXCON /////////////////////////////
#define  TIM_COUNT_DEBOUNCE_EN     (1ul << TIMER_TEXCON_TCDB_Pos)    //Count-pin de-bounce enable
#define  TIM_CAPTURE_DEBOUNCE_EN   (1ul << TIMER_TEXCON_TEXDB_Pos)	 //Capture-pin debounce enable
#define  TIM_TEX_INT_EN            (1ul << TIMER_TEXCON_TEXIEN_Pos)  //Capture-pin interrupt enable
#define  TIM_CAPTURE_RST_EN        (1ul << TIMER_TEXCON_RSTCAPSEL_Pos)//Capture-pin reset timer enable	
#define  TIM_CAPTURE_EN            (1ul << TIMER_TEXCON_TEXEN_Pos)	 //Capture pin enable
#define  TIM_CAPTURE_FALL          (0   << TIMER_TEXCON_TEX_EDGE_Pos)//Capture fall edge
#define  TIM_CAPTURE_RISE          (1   << TIMER_TEXCON_TEX_EDGE_Pos)//Capture rise edge 
#define  TIM_CAPTURE_EDGE          (2   << TIMER_TEXCON_TEX_EDGE_Pos)//Capture fall and rise edge
#define  TIM_COUNT_RISE            (1ul << TIMER_TEXCON_TX_PHASE_Pos)//Count-pin count rise edge of pulse	

//// TIMER0->TEXISR, TIMER1->TEXISR, TIMER2->TEXISR, TIMER3->TEXISR /////////////////////////////
#define  TIM_TEX_INT_FLAG          (1ul << TIMER_TEXISR_TEXIF_Pos)	 //Tex interrupt has occurred

/*@}*/ /* end of group TIMEr_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup TIMER_MACRO_FUNC Timer Macro Func
  @{
*/

/**
 * @brief       Enable Timer debug mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit DBGACK_TMR in TCSR .
 *              Example of function call:  
 *              TIM_DEBUG_MODE_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_DEBUG_MODE_ENABLE(TIMER_T *TIMER)
{
  ((TIMER)->TCSR |=  TIM_DEBUG_MODE) ;
}

/**
 * @brief       Disable Timer debug mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit DBGACK_TMR in TCSR .
 *              Example of function call:  
 *              TIM_DEBUG_MODE_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_DEBUG_MODE_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR &= ~TIM_DEBUG_MODE) ;
}

/**
 * @brief       Enable Timer
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit CEN in TCSR .
 *              Example of function call:  
 *              TIM_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_ENABLE(TIMER_T *TIMER)
{
       ((TIMER)->TCSR |= TIM_EN)  ;
}

/**
 * @brief       Disable Timer debug mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit CEN in TCSR .
 *              Example of function call:  
 *              TIM_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_DISABLE(TIMER_T *TIMER)
{
    (TIMER->TCSR &= ~TIM_EN)  ;
}

/**
 * @brief       Enable Timer interrupt
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit IEN in TCSR .
 *              Example of function call:  
 *              TIM_INTERRUPT_ENBALE(TIMER0) ;
 */
static __INLINE void TIM_INTERRUPT_ENBALE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR |= TIM_INT_EN);
}

/**
 * @brief       Disable Timer interrupt
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit IEN in TCSR .
 *              Example of function call:  
 *              TIM_INTERRUPT_DISBALE(TIMER0) ;
 */
static __INLINE void TIM_INTERRUPT_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR &= ~TIM_INT_EN) ;
}

/**
 * @brief       Set Timer work mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *
 *              MODE    Must be the following constance
 *                       TIM_MODE_PERIODIC        
 *                       TIM_MODE_TOGGLE        
 *                       TIM_MODE_CONTINUOUS     
 *
 * @return      None
 *
 * @details     write bit MODE in TCSR .
 *              Example of function call:  
 *              TIM_WORK_MODE(TIMER0, TIM_MODE_TOGGLE) ;
 */
static __INLINE void TIM_WORK_MODE(TIMER_T *TIMER, uint32_t Mode)
{
    (TIMER->TCSR = ((TIMER->TCSR&(~TIMER_TCSR_MODE_Msk))|(Mode))) ;
}

/**
 * @brief       Reset Timer
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *
 * @return      None
 *
 * @details     Write 1 into bit-CRST in TCSR .
 *              Example of function call:  
 *              TIM_RESET(TIMER0) ;
 */
static __INLINE void  TIM_RESET(TIMER_T *TIMER)
{
    ((TIMER)->TCSR |= TIM_RST) ;
}

/**
 * @brief       Get that whether timer is work
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *
 * @return      Value of bit-CACT in TCSR
 *
 * @details     Read  bit-CACT in TCSR .
 *              Example of function call:  
 *              TIM_READ_ACTIVE_BIT(TIMER0) ;
 */
static __INLINE uint32_t TIM_READ_ACTIVE_BIT(TIMER_T *TIMER)
{
  return  ((TIMER)->TCSR & TIM_ACTIVE)  ;
}
/**
 * @brief       Enable Timer count mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit CTB in TCSR .
 *              Example of function call:  
 *               TIM_COUNT_MODE_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_COUNT_MODE_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR |= TIM_COUNT_MODE) ;
}
/**
 * @brief      Disable Timer count mode
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit CTB in TCSR .
 *              Example of function call:  
 *               TIM_COUNT_MODE_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_COUNT_MODE_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR &= ~TIM_COUNT_MODE) ;
}

/**
 * @brief       Enable Timer wake up function
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit  WAKE_EN in TCSR .
 *              Example of function call:  
 *               TIM_WAKEUP_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_WAKEUP_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR |= TIM_WAKEUP_EN) ;
}

/**
 * @brief      Disable Timer wake up function
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit WAKE_EN in TCSR .
 *              Example of function call:  
 *               TIM_WAKEUP_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_WAKEUP_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR &= ~TIM_WAKEUP_EN) ;
}

/**
 * @brief      Enable Timer updata cotinuously
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit TDR_EN in TCSR .
 *              Example of function call:  
 *               TIM_UPDATA_TDR_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_UPDATA_TDR_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR |= TIM_READ_EN) ;
}

/**
 * @brief      Disable Timer updata cotinuously
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit TDR_EN in TCSR. 
 *              Example of function call:  
 *              TIM_UPDATA_TDR_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_UPDATA_TDR_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TCSR &= ~TIM_READ_EN)  ;
}

/**
 * @brief      Set Timer pre-scaler
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 *              VALUE    range from 1 to 255
 *  
 * @return      None
 *
 * @details     Write PRE_SCALER into TCSR. 
 *              Example of function call:  
 *              TIM_SET_PRESCALE(TIMER0, 100) ;
 */
static __INLINE void TIM_SET_PRESCALE(TIMER_T *TIMER, uint32_t Value)
{
    ((TIMER)->TCSR = (((TIMER->TCSR)&(~TIMER_TCSR_PRESCALE_Msk))|(Value)))  ;
}

/**
 * @brief      Get Timer pre-scaler
 *
 * @param[in]   TIMER   register TCSR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of PRE_SCALER in TCSR
 *
 * @details     Read PRE_SCALER from TCSR. 
 *              Example of function call:  
 *               TIM_GET_PRESCALE(TIMER0) ;
 */
static __INLINE uint32_t TIM_GET_PRESCALE(TIMER_T *TIMER)
{
  return  (TIMER->TCSR & TIMER_TCSR_PRESCALE_Msk) ;
}

/**
 * @brief      Set value of TCMPR 
 *
 * @param[in]   TIMER   register TCMPR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 *              VALUE    range from 2 to 0xFFFFFF
 *  
 * @return      None
 *
 * @details     Write PRE_SCALER into TCMPR. 
 *              Example of function call:  
 *               TIM_SET_TCMPR(TIMER0, 1000) ;
 */
static __INLINE void TIM_SET_TCMPR(TIMER_T *TIMER, uint32_t Value)
{
    (TIMER->TCMPR = (Value)) ;
}
/**
 * @brief      Get TCMPR of Timer  
 *
 * @param[in]   TIMER   register TCMPR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of TCMPR
 *
 * @details     Read TCMPR. 
 *              Example of function call:  
 *               TIM_GET_TCMPR(TIMER0) ;
 */
static __INLINE uint32_t TIM_GET_TCMPR(TIMER_T *TIMER)
{
  return  ((TIMER)->TCMPR) ;
}

/**
 * @brief      Get Timer value
 *
 * @param[in]   TIMER   register TDR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of TDR
 *
 * @details     Read TDR. 
 *              Example of function call:  
 *              TIM_GET_TDR(TIMER0) ;
 */
static __INLINE uint32_t TIM_GET_TDR(TIMER_T *TIMER)
{
  return   ((TIMER)->TDR) ;
}

/**
 * @brief      Get capture value of timer
 *
 * @param[in]   TIMER   register TCAP. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of TCAP
 *
 * @details     Read TCAP. 
 *              Example of function call:  
 *              TIM_GET_TCAP(TIMER0) ;
 */
static __INLINE uint32_t TIM_GET_TCAP(TIMER_T *TIMER)
{
  return   ((TIMER)->TCAP) ;
}

/**
 * @brief      Read the value of bit TWF in TISR.
 *
 * @param[in]   TIMER   register TISR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of bit TWF in TISR
 *
 * @details     Read the value of bit TWF in TISR. 
 *              Example of function call:  
 *              TIM_WAKEUP_CPU(TIMER0) ;
 */
static __INLINE uint32_t TIM_WAKEUP_CPU(TIMER_T *TIMER)
{
  return (TIMER->TISR & TIM_WAKEUP_EN) ;
}

/**
 * @brief      Clear the flag of bit TWF in TISR.
 *
 * @param[in]   TIMER   register TISR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      None
 *
 * @details     Clear the flag of bit TWF in TISR. 
 *              Example of function call:  
 *              TIM_CLEAR_TWF_FLAG(TIMER0) ;
 */
static __INLINE void TIM_CLEAR_WAKEUP_FLAG(TIMER_T *TIMER)
{
    ((TIMER)->TISR |= TIM_WAKEUP_FLAG) ;
}

/**
 * @brief       Read the value of bit IF in TISR.
 *
 * @param[in]   TIMER   register TISR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      bit IF in TISR    Timer occured interrupt
 *              0                 Timer is not occured interrupt.
 * 
 * @details     Read the value of bit IF in TISR. 
 *              Example of function call:  
 *              TIM_READ_INTERRUPT_FLAG(TIMER0) ;
 */
static __INLINE uint32_t TIM_READ_INTERRUPT_FLAG(TIMER_T *TIMER)
{
  return  ((TIMER)->TISR & TIM_INT_FLAG) ;
}

/**
 * @brief      Clear interrupt flag.
 *
 * @param[in]   TIMER   register TISR. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      bit IF in TISR    Timer occured interrupt
 *              0                 Timer is not occured interrupt.
 * 
 * @details     Read the value of bit IF in TISR. 
 *              Example of function call:  
 *              TIM_CLEAR_INTERRUPT_FLAG(TIMER0) ;
 */
static __INLINE void TIM_CLEAR_INTERRUPT_FLAG(TIMER_T *TIMER)
{
   ((TIMER)->TISR |= TIM_INT_FLAG) ;
}

/**
 * @brief       Enable Timer count pin de-bounce function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit TCDB in TEXCON .
 *              Example of function call:  
 *              TIM_COUNT_DEBOUNCE_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_COUNT_DEBOUNCE_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |=  TIM_COUNT_DEBOUNCE_EN ) ;
}

/**
 * @brief       Disable Timer count pin de-bounce function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit TCDB in TEXCON .
 *              Example of function call:  
 *             TIM_COUNT_DEBOUNCE_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_COUNT_DEBOUNCE_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON &= ~TIM_COUNT_DEBOUNCE_EN )  ;
}

/**
 * @brief       Enable Timer capture pin de-bounce function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit TEXDB in TEXCON .
 *              Example of function call:  
 *              TIM_CAPTURE_DEBOUNCE_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_DEBOUNCE_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |=  TIM_CAPTURE_DEBOUNCE_EN ) ;
}

/**
 * @brief       Disable Timer capture pin de-bounce function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit TEXDB in TEXCON .
 *              Example of function call:  
 *             TIM_CAPTURE_DEBOUNCE_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_DEBOUNCE_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON &= ~TIM_CAPTURE_DEBOUNCE_EN ) ;
}
/**
 * @brief       Enable Timer capture interrupt
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit TEXIEN in TEXCON .
 *              Example of function call:  
 *              TIM_CAPTURE_INTERRUPT_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_INTERRUPT_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |=  TIM_TEX_INT_EN) ;
}
/**
 * @brief       Disable Timer capture interrupt
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit TEXIEN in TEXCON .
 *              Example of function call:  
 *             TIM_CAPTURE_INTERRUPT_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_INTERRUPT_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON &= ~TIM_TEX_INT_EN )  ;
}
/**
 * @brief       Enable Timer capture reset function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit RSTCAPn in TEXCON .
 *              Example of function call:  
 *              TIM_CAPTURE_RST_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_RST_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |= TIM_CAPTURE_RST_EN) ;
}

/**
 * @brief       Disable Timer capture reset function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit RSTCAPn in TEXCON .
 *              Example of function call:  
 *             TIM_CAPTURE_RST_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_RST_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON &= ~TIM_CAPTURE_RST_EN ) ;
}

/**
 * @brief       Enable Timer capture function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Set bit TEXEN in TEXCON .
 *              Example of function call:  
 *              TIM_CAPTURE_ENABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_ENABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |= TIM_CAPTURE_EN) ;
}

/**
 * @brief       Disable Timer capture function
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *    
 * @return      None
 *
 * @details     Clear bit TEXEN in TEXCON .
 *              Example of function call:  
 *             TIM_CAPTURE_DISABLE(TIMER0) ;
 */
static __INLINE void TIM_CAPTURE_DISABLE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON &= ~TIM_CAPTURE_EN) ;
}

/**
 * @brief      Set Timer capture rise/fall edge mode
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 *              EDGE_MODE   It should be followin gconstance : 
 *                       TIM_CAPTURE_FALL   
 *                       TIM_CAPTURE_RISE     
 *                       TIM_CAPTURE_EDGE   
 *  
 * @return      None
 *
 * @details     Write bit TEX_EDGE of TEXCON. 
 *              Example of function call:  
 *               TIM_SET_CAP_EDGE_MODE(TIMER0, TIM_CAPTURE_RISE) ;
 */
static __INLINE void TIM_SET_CAP_EDGE_MODE(TIMER_T *TIMER, uint32_t EDGE_MODE)
{
    ((TIMER)->TEXCON = (((TIMER)->TEXCON&(~TIMER_TEXCON_TEX_EDGE_Msk))|(EDGE_MODE))) ;
}

/**
 * @brief      Get Timer capture rise/fall edge mode
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      Value of TEX_EDGE in TEXCON
 *
 * @details     Read TEX_EDGE from register TEXCON. 
 *              Example of function call:  
 *               TIM_GET_CAP_EDGE_MODE(TIMER0) ;
 */
static __INLINE uint32_t TIM_GET_CAP_EDGE_MODE(TIMER_T *TIMER)
{
   return ((TIMER)->TEXCON & TIMER_TEXCON_TEX_EDGE_Msk)  ;
}

/**
 * @brief      It set that timer count rise-edge from pin Tx 
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      None
 *
 * @details     Write bit TX_PHASE of TEXCON. 
 *              Example of function call:  
 *              TIM_COUNT_RISE_EDGE(TIMER0, TIM_CAPTURE_RISE) ;
 */
static __INLINE void TIM_COUNT_RISE_EDGE(TIMER_T *TIMER)
{
    ((TIMER)->TEXCON |=  TIM_COUNT_RISE ) ;
}

/**
 * @brief       It set that timer count fall-edge from pin Tx 
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      None
 *
 * @details     Write bit TX_PHASE of TEXCON. 
 *              Example of function call:  
 *               TIM_COUNT_FALL_EDGE(TIMER0) ;
 */
static __INLINE void TIM_COUNT_FALL_EDGE(TIMER_T *TIMER) 
{
    ((TIMER)->TEXCON &= ~TIM_COUNT_RISE) ;
}

/**
 * @brief       Obtain whether TEX occured interrupt.
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      TIM_TEX_INT_FLAG   If TEX occured interrupt.
 *               0                 If TEX donn't  occured interrupt.
 *
 * @details     read 1 bit TEXIF of TEXISR. 
 *              Example of function call:  
 *              TIM_READ_TEX_INTERRUPT(TIMER0) ;
 */
static __INLINE uint32_t TIM_READ_TEX_INTERRUPT(TIMER_T *TIMER)
{
    return ((TIMER)->TEXISR & TIM_TEX_INT_FLAG ) ;
}

/**
 * @brief       It clear TEX interrupt flag  
 *
 * @param[in]   TIMER   register TEXCON. It should be following lable:          
 *                       TIMER0
 *                       TIMER1
 *                       TIMER2
 *                       TIMER3
 *  
 * @return      None
 *
 * @details     Write 1 into bit TEXIF of TEXISR. 
 *              Example of function call:  
 *              TIM_CLEAR_TEX_INTERRUPT_FLAG(TIMER0) ;
 */
static __INLINE void TIM_CLEAR_TEX_INTERRUPT_FLAG(TIMER_T *TIMER)
{
   ((TIMER)->TEXISR |= TIM_TEX_INT_FLAG ) ;
}

/*@}*/ /* end of group TIMER_MACRO_FUNC */
/*@}*/ /* end of group TIMER_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void DrvTIMER_Init(TIMER_T *timer, uint8_t u8Prescale, uint32_t u32Compare, uint32_t u32Mode) ;
void DrvTIMER_DeInit(TIMER_T *timer) ;
void DrvTIMER_EnableInt(TIMER_T *timer, uint32_t u32Mask) ;
void DrvTIMER_DisableInt(TIMER_T *timer) ;



#endif   //__TIMER_H
