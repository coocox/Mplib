/**************************************************************************//**
 * @file     WWDT.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/24 1:45p $
 * @brief    NUC123 Series Watchdog Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __WWDT_H__
#define __WWDT_H__

#include "NUC123Series.h"


/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup WWDT_MACRO WWDT Macro
  * @{
  */
/** @addtogroup WWDT_MACRO_CONTANT WWDT Macro Contant
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/* WWDT WWTCR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WWDT_WINCMP(x)     		((x) << WWDT_WWDTCR_WINCMP_Pos) /*!< WWDT Window Compare Register  */
#define WWDT_PERIODSEL(x)        ((x) << WWDT_WWDTCR_PERIODSEL_Pos)/*!< WWDT Pre-scale Period Select  */
#define WWDT_WWDTIE              (1ul << WWDT_WWDTCR_WWDTIE_Pos)	/*!< WWDT Interrupt Enable  */
#define WWDT_WWDTEN              (1ul << WWDT_WWDTCR_WWDTEN_Pos)/*!< WWDT Enable */
/*---------------------------------------------------------------------------------------------------------*/
/* WWDT WWDTSR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WWDT_WWDTSR_WWDTRF              (1ul << WWDT_WWDTSR_WWDTRF_Pos)	/*!< WWDT Reset Flag */
#define WWDT_WWDTSR_WWDTIF              (1ul << WWDT_WWDTSR_WWDTIF_Pos)	/*!< WWDT Compare Match Interrupt Flag */

/*@}*/ /* end of group WWDT_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup WWDT_MACRO_FUNC WWDT Macro Func
  @{
*/

/**
 * @brief      Clear Window Watchdog Timer counter 
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear Window Watchdog Timer counter.
 *             Example: WWDT_TIMER_RESET()
 */
static __INLINE void WWDT_TIMER_RESET(void) 
{
    (WWDT->WWDTRLD = 0x00005AA5);
}
/**
 * @brief      WWDT Disable
 *
 * @param[in]  x   
 *
 * @return     None
 *                                                           
 * @details    WWDTCR only can be write once.
 *             Example: WWDT_SET_WWDTCR(WWDT_WINCMP(20)|WWDT_PERIODSEL(15)|WWDT_WWDTIE|WWDT_WWDTEN)
 */
static __INLINE void WWDT_SET_WWDTCR(uint32_t x)   
{
    (WWDT->WWDTCR = (x));
}
/**
 * @brief      Get WWDT Timeout Reset Flag
 *
 * @param[in]  None
 *
 * @retval     1 = Window Watchdog Timeout cause chip reset happened
 * @retval     0 = Window Watchdog Timeout reset did not occur
 *                                                           
 * @details    Get WWDT Timeout Reset Flag
 *             Example: WWDT_GET_RESET_FLAG()
 *
 */
static __INLINE uint32_t WWDT_GET_RESET_FLAG(void)  
{
    return ((WWDT->WWDTSR) & WWDT_WWDTSR_WWDTRF);
}
/**
 * @brief      Clear WWDT Timeout Reset Flag
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear WWDT Timeout Reset Flag
 *             Example: WWDT_CLEAR_RESET_FLAG()
 */
static __INLINE void WWDT_CLEAR_RESET_FLAG(void)
{
    (WWDT->WWDTSR |= WWDT_WWDTSR_WWDTRF);
}
/**
 * @brief      Get WWDT Timeout interrupt Flag
 *
 * @param[in]  None
 *
 * @retval     1 = Window Watchdog Timeout interrupt occurred
 * @retval     0 = Window Watchdog Timeout interrupt did not occur
 *                                                           
 * @details    Get WWDT Timeout interrupt Flag
 *             Example: WWDT_GET_INT_FLAG()
 *
 */
static __INLINE uint32_t WWDT_GET_INT_FLAG()
{
    return ((WWDT->WWDTSR) & WWDT_WWDTSR_WWDTIF); 
}
/**
 * @brief      Clear WWDT Timeout interrupt Flag
 *
 * @param[in]  None
 *
 * @return     None
 *                                                           
 * @details    Clear WWDT Timeout interrupt Flag
 *             Example: WWDT_CLEAR_INT_FLAG()
 */
static __INLINE void WWDT_CLEAR_INT_FLAG(void)    
{
    (WWDT->WWDTSR |= WWDT_WWDTSR_WWDTIF);
}
/**
 * @brief      WWDT Counter Value
 *
 * @param[in]  None
 *
 * @retval     WWDT Counter Value
 *                                                           
 * @details    Get WWDT Counter Value
 *             Example: WWDT_GET_VALUE()
 *
 */
static __INLINE uint32_t WWDT_GET_VALUE(void) 
{
     return ((WWDT->WWDTCVR) & 0x3F); 
}

/*@}*/ /* end of group WWDT_MACRO_FUNC */
/*@}*/ /* end of group WWDT_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


/*---------------------------------------------------------------------------------------------------------*/
/*  Function declaration                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void DrvWWDT_Init(uint32_t CmpWin, uint32_t Prescale,uint32_t u32clock);
uint8_t DrvWWDT_IsResetSource(void);
void WWDT_DeInit(void);


#endif  
