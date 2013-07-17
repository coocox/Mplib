/**************************************************************************//**
 * @file     WDT.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/24 1:45p $
 * @brief    NUC123 Series Watchdog Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __WDT_H__
#define __WDT_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup WDT_MACRO WDT Macro
  * @{
  */
/** @addtogroup WDT_MACRO_CONTANT WDT Macro Contant
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/* WDT WTCR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WDT_WTCR_WTIS(x)     		((x) << WDT_WTCR_WTIS_Pos) /*!< Watchdog Timer Interval Selection  */
#define WDT_WTCR_WTE                (1ul << WDT_WTCR_WTE_Pos)  /*!< Watchdog Timer Enable   */
#define WDT_WTCR_WTIE               (1ul << WDT_WTCR_WTIE_Pos) /*!< Watchdog Timer Interrupt Enable */
#define WDT_WTCR_WTWKF              (1ul << WDT_WTCR_WTWKF_Pos)/*!< Watchdog Timer Wake-up Flag  */
#define WDT_WTCR_WTWKE              (1ul << WDT_WTCR_WTWKE_Pos)/*!< Watchdog Timer Wake-up Function Enable bit  */
#define WDT_WTCR_WTIF               (1ul << WDT_WTCR_WTIF_Pos) /*!< Watchdog Timer Interrupt Flag  */
#define WDT_WTCR_WTRF               (1ul << WDT_WTCR_WTRF_Pos) /*!< Watchdog Timer Reset Flag  */
#define WDT_WTCR_WTRE               (1ul << WDT_WTCR_WTRE_Pos) /*!< Watchdog Timer Reset Enable   */
#define WDT_WTCR_WTR                (1ul << WDT_WTCR_WTR_Pos)  /*!< Clear Watchdog Timer  */
/*---------------------------------------------------------------------------------------------------------*/
/* WDT WTCRALT Constants Definitions                                                                                   */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WDT_RESET_DELAY_1024                (0)	   /*!<Watchdog reset delay period is 1024 watchdog clock */
#define WDT_RESET_DELAY_128                 (1)	   /*!<Watchdog reset delay period is 128 watchdog clock */
#define WDT_RESET_DELAY_16                  (2)	   /*!<Watchdog reset delay period is 16 watchdog clock */
#define WDT_RESET_DELAY_1                   (3)	   /*!<Watchdog reset delay period is 1 watchdog clock */

/*@}*/ /* end of group WDT_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup WDT_MACRO_FUNC WDT Macro Func
  @{
*/

/**
 * @brief      Watchdog Timer Interval Selection
 *
 * @param[in]  x   0~7
 *
 * @return     None
 *                                                           
 * @details    Watchdog Timer Interval Selection
 *             Example: WDT_SET_INTERVAL(6)
 */
static __INLINE void WDT_SET_INTERVAL(uint8_t x) 
{
    (WDT->WTCR = (WDT->WTCR&(~WDT_WTCR_WTIS_Msk))| WDT_WTCR_WTIS(x));
}
/**
 * @brief      Enable WDT
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable WDT to start counting
 *             Example: WDT_ENABLE_COUNTING()
 */
static __INLINE void WDT_ENABLE_COUNTING(void)         
{
    (WDT->WTCR |= WDT_WTCR_WTE);
}
/**
 * @brief      Disable WDT
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable WDT to stop counting
 *             Example: WDT_DISABLE_COUNTING()
 */
static __INLINE void WDT_DISABLE_COUNTING(void)          
{
   (WDT->WTCR &= ~WDT_WTCR_WTE);
}
/**
 * @brief      Enable WDT Interrupt
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable WDT Interrupt
 *             Example: WDT_ENABLE_INT()
 */
static __INLINE void WDT_ENABLE_INT(void)          
{
    (WDT->WTCR |= WDT_WTCR_WTIE);
}
/**
 * @brief      Disable WDT Interrupt
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable WDT Interrupt
 *             Example: WDT_DISABLE_INT()
 */
static __INLINE void WDT_DISABLE_INT(void)       
{
    (WDT->WTCR &= ~WDT_WTCR_WTIE);
}
/**
 * @brief      Get WDT Timeout Wake-up Flag
 *
 * @param[in]  None
 *
 * @retval     !0 = Watchdog Timeout Wake-up occurred
 * @retval     0 = Watchdog Timeout Wake-up did not occur
 *                                                           
 * @details    Get WDT Timeout Wake-up Flag
 *             Example: WDT_GET_TIMEOUT_WAKEUP_FLAG()
 *
 */
static __INLINE uint32_t WDT_GET_TIMEOUT_WAKEUP_FLAG(void) 
{
    return ((WDT->WTCR) & WDT_WTCR_WTWKF);
}
/**
 * @brief      Clear WDT Timeout Wake-up Flag to 0
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear WDT Timeout Wake-up Flag to 0
 *             Example: WDT_CLEAR_TIMEOUT_WAKEUP_FLAG()
 */
static __INLINE void WDT_CLEAR_TIMEOUT_WAKEUP_FLAG()
{
    (WDT->WTCR |= WDT_WTCR_WTWKF);
}
/**
 * @brief      Enable WDT Wakeup
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable WDT Wakeup
 *             Example: WDT_ENABLE_WAKEUP()
 */
static __INLINE void WDT_ENABLE_WAKEUP(void)        
{
    (WDT->WTCR |= WDT_WTCR_WTWKE);
}
/**
 * @brief      Disable WDT Wakeup
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable WDT Wakeup
 *             Example: WDT_DISABLE_WAKEUP()
 */
static __INLINE void WDT_DISABLE_WAKEUP(void)          
{
    (WDT->WTCR &= ~WDT_WTCR_WTWKE);
}
/**
 * @brief      Get WDT Timeout Interrupt Flag
 *
 * @param[in]  None
 *
 * @retval     !0 = Watchdog Timeout Interrupt occurred
 * @retval     0 = Watchdog Timeout Interrupt did not occur
 *                                                           
 * @details    Get WDT Timeout Interrupt Flag
 *             Example: WDT_GET_TIMEOUT_INT_FLAG()
 *
 */
static __INLINE uint32_t WDT_GET_TIMEOUT_INT_FLAG() 
{
    return ((WDT->WTCR) & WDT_WTCR_WTIF);
}
/**
 * @brief      Clear WDT Timeout Interrupt Flag to 0
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear WDT Timeout Interrupt Flag to 0
 *             Example: WDT_CLEAR_TIMEOUT_INT_FLAG()
 */
static __INLINE void WDT_CLEAR_TIMEOUT_INT_FLAG(void)  
{
    (WDT->WTCR |= WDT_WTCR_WTIF);
}
/**
 * @brief      Get WDT Timeout Reset Flag
 *
 * @param[in]  None
 *
 * @retval     1 = Watchdog timer reset occurred
 * @retval     0 = Watchdog timer reset did not occur
 *                                                           
 * @details    Get WDT Timeout Reset Flag.
 *             Example: WDT_GET_RESET_FLAG()
 *
 */
static __INLINE uint32_t WDT_GET_RESET_FLAG(void)         
{
    return ((WDT->WTCR) & WDT_WTCR_WTRF);
}
/**
 * @brief      Clear WDT Timeout Reset Flag to 0
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear WDT Timeout Reset Flag to 0.
 *             Example: WDT_CLEAR_RESET_FLAG()
 */
static __INLINE void WDT_CLEAR_RESET_FLAG(void)      
{
    (WDT->WTCR |= WDT_WTCR_WTRF);
}
/**
 * @brief      Enable WDT Reset
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Enable WDT Reset
 *             Example: WDT_ENABLE_RESET()
 */
static __INLINE void WDT_ENABLE_RESET(void)       
{
    (WDT->WTCR |= WDT_WTCR_WTRE);
}
/**
 * @brief      Disable WDT Reset
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Disable WDT Reset
 *             Example: WDT_DISABLE_RESET()
 */
static __INLINE void WDT_DISABLE_RESET(void)         
{
    (WDT->WTCR &= ~WDT_WTCR_WTRE);
}
/**
 * @brief      Clear Watchdog Timer
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Setting this bit will clear the Watchdog timer.
 *             Example: WDT_TIMER_RESET()
 */
static __INLINE void WDT_TIMER_RESET(void)              
{
    (WDT->WTCR |= WDT_WTCR_WTR);
}
/**
 * @brief      Watchdog Timer Interval Selection
 *
 * @param[in]  x   
 *			   -WDT_RESET_DELAY_1024
 *			   -WDT_RESET_DELAY_128
 *			   -WDT_RESET_DELAY_16
 *			   -WDT_RESET_DELAY_1
 * @return     None
 *                                                           
 * @details    Watchdog Timer Interval Selection
 *             Example: WDT_SET_RESET_DELAY(WDT_RESET_DELAY_16)
 */
static __INLINE void WDT_SET_RESET_DELAY(uint8_t x)          
{
    (WDT->WTCRALT = (x)); 
}

/*@}*/ /* end of group WDT_MACRO_FUNC */
/*@}*/ /* end of group WDT_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void DrvWDT_Init(uint32_t u32Interval,uint32_t u32clock,uint32_t u32Delay);
void DrvWDT_DeInit(void);
void DrvWDT_EnableInt(void);
void DrvWDT_DisableInt(void);


#endif  
