/******************************************************************************
 * @file     nano1xx_timer.c
 * @brief    NANO1xx TIMER driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "NUC123Series.h"
#include "TIMER.h"
#include "CLOCK.h"
#include "SYS.h"
#include "WWDT.h"
#include "WDT.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */
/** @addtogroup DrvTimer_FUNC TIMER Driver API
  * @{
  */

/**
  * @brief  Initial timer channel
  * @param  timer Timer channel to configure
  * @param  u8Prescale Prescale value. it could be 1 to 255
  * @param  u32Compare Comparator value, it cound be 2~0xFFFFFF
  * @param  u32Mode Timer operating mode. it could be\n
  *                 TIM_MODE_PERIODIC        
  *                 TIM_MODE_TOGGLE        
  *                 TIM_MODE_CONTINUOUS   
  * @return None
  */
void DrvTIMER_Init(TIMER_T *timer, uint8_t u8Prescale, uint32_t u32Compare, uint32_t u32Mode)
{
    if(timer == TIMER0)   		APBCLK_ENABLE(CLK_TMR0);
    else if(timer == TIMER1) 	APBCLK_ENABLE(CLK_TMR1);
    else if(timer == TIMER2) 	APBCLK_ENABLE(CLK_TMR2);
    else                        APBCLK_ENABLE(CLK_TMR3);

    timer->TISR   |=  TIM_INT_FLAG | TIM_WAKEUP_FLAG ;
    timer->TEXISR |=  TIM_TEX_INT_FLAG  ;
    timer->TCMPR   =  u32Compare ;

    timer->TCSR    =  u32Mode + TIM_READ_EN + TIM_RST + u8Prescale ;
}

/**
  * @brief  De-init timer channel
  * @param  timer Timer channel to disable
  * @return None
  */
void DrvTIMER_DeInit(TIMER_T *timer)
{
    timer->TCSR = 0;

    if(timer == TIMER0) {
        APBCLK_DISABLE(CLK_TMR0);
        NVIC_DisableIRQ(TMR0_IRQn);
    } else if(timer == TIMER1) {
        APBCLK_DISABLE(CLK_TMR1);
        NVIC_DisableIRQ(TMR1_IRQn);
    } else if(timer == TIMER2) {
        APBCLK_DISABLE(CLK_TMR2);
        NVIC_DisableIRQ(TMR2_IRQn);
    } else {
        APBCLK_DISABLE(CLK_TMR3);
        NVIC_DisableIRQ(TMR3_IRQn);
    }
}

/**
  * @brief  Enable timer interrupt
  * @param  timer Timer channel to configure
  * @param  u32Mask Interrupt mask to enable, a combination of TIM_INT_EN and TIM_TEX_INT_EN
  * @return None
  */
void DrvTIMER_EnableInt(TIMER_T *timer, uint32_t u32Mask)
{
    timer->TISR = timer->TISR;  // clear pending interrupt
 	
    if(u32Mask&TIM_INT_EN)
        TIM_INTERRUPT_ENBALE(timer);
    if(u32Mask&TIM_TEX_INT_EN)
    	TIM_CAPTURE_INTERRUPT_ENABLE(timer);

    if(timer == TIMER0) {
        NVIC_EnableIRQ(TMR0_IRQn);
    } else if(timer == TIMER1) {
        NVIC_EnableIRQ(TMR1_IRQn);
    } else if(timer == TIMER2) {
        NVIC_EnableIRQ(TMR2_IRQn);
    } else {
        NVIC_EnableIRQ(TMR3_IRQn);
    }
}

/**
  * @brief  Disable timer interrupt
  * @param  timer Timer channel to configure
  * @param  u32Mask Interrupt mask to Disable, a combination of TIMER_IER_TMRIE and TIMER_IER_TMRIE
  * @return None
  */
void DrvTIMER_DisableInt(TIMER_T *timer)
{

    TIM_INTERRUPT_DISABLE(timer);
    TIM_CAPTURE_INTERRUPT_DISABLE(timer);

    if(timer == TIMER0) {
        NVIC_DisableIRQ(TMR0_IRQn);
    } else if(timer == TIMER1) {
        NVIC_DisableIRQ(TMR1_IRQn);
    } else if(timer == TIMER2) {
        NVIC_DisableIRQ(TMR2_IRQn);
    } else {
        NVIC_DisableIRQ(TMR3_IRQn);
    }
}


/**
  * @brief  Initialize WDT
  * @param  u32Interval Time out interval.it could be 0~7
  * @param  u32Period Reset delay
  * @return None
  */
void DrvWDT_Init(uint32_t u32Interval,uint32_t u32clock, uint32_t u32Delay)
{
    SYS_UnlockReg();
    APBCLK_ENABLE(CLK_WDT);
    SET_WDT_CLKSRC(u32clock);
    WDT_SET_INTERVAL(u32Interval);
    WDT_SET_RESET_DELAY(u32Delay);
    SYS_LockReg();
}

/**
  * @brief  Disable WDT
  * @param  None
  * @return None
  */
void DrvWDT_DeInit(void)
{
    SYS_UnlockReg();
    WDT_DISABLE_COUNTING();
    WDT_DISABLE_INT();

    NVIC_DisableIRQ(WDT_IRQn);
    APBCLK_DISABLE(CLK_WDT);
    SYS_LockReg();
}
/**
  * @brief  Enable WDT interrupt
  * @param  None
  * @return None
  * @note   This API will clear pending interrupt status before enabled interrupt
  */
void DrvWDT_EnableInt(void)
{
    SYS_UnlockReg();
    WDT_CLEAR_TIMEOUT_INT_FLAG();
    WDT_ENABLE_INT();
    NVIC_EnableIRQ(WDT_IRQn);
    SYS_LockReg();
}

/**
  * @brief  Disable WDT interrupt
  * @param  None
  * @return None
  */
void DrvWDT_DisableInt(void)
{
    SYS_UnlockReg();
    //if(!(WWDT->IER & WWDT_IER_IE))
    //	NVIC_EnableIRQ(WDT_IRQn);
    WDT_DISABLE_INT();
    NVIC_DisableIRQ(WDT_IRQn);
    SYS_LockReg();
}


/**
  * @brief  Enables WWDT clock, configure prescale and comparator
  * @param  CmpWin WWDT compare window,it could be 1 ~ 0x3F
  * @param  u8Cmp Comparator value
  * @return None
  * @note   This API can only call once after systme boot up
  * @par Example: 
  * @code
  *  //Set WWDT compare window to 32, Prescale period select 13, Enable interrupt.
  *  DrvWWDT_Init(32,13,CLK_WWDT_LIRC); 
  * @endcode
  *
  */
void DrvWWDT_Init(uint32_t CmpWin, uint32_t Prescale,uint32_t u32clock)
{
    //EnableInt
    SYS_UnlockReg();
    SET_WWDT_CLKSRC(u32clock); 
    WWDT_SET_WWDTCR(WWDT_WINCMP(CmpWin)|WWDT_PERIODSEL(Prescale)|WWDT_WWDTIE|WWDT_WWDTEN);
    NVIC_EnableIRQ(WDT_IRQn);                  //En:Enable NVIC WWDT interrupt
    SYS_LockReg();
}

/**
  * @brief  Sorry, can't do this once WWDT init.
  * @param  none
  * @param  none
  */
void WWDT_DeInit(void)
{
    return;
}


/**
  * @brief  Check if WWDT is CPU reset source or not
  * @param  none
  * @return Yes or no.
  * @retval 0 WWDT is not CPU reset source
  * @retval !0 WWDT is CPU reset source
  * @note   This API will clear WWDT reset status
  */
uint8_t DrvWWDT_IsResetSource(void)
{
    int8_t ret = WWDT_GET_RESET_FLAG();

    if(ret)
        WWDT_CLEAR_RESET_FLAG();

    return(ret);

}

/*@}*/ /* end of group DrvTimer_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/

