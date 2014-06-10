/**************************************************************************//**
 * @file     WDT.h
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 12/08/06 8:08p $
 * @brief    NUC200 Series Watchdog Timer and Window Watchdog Timer Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __WDT_H__
#define __WDT_H__

#include "NUC200Series.h"

/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup WDT_FUNC WDT Device Function Interface
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/* WTCR Constants Definitions                                                                              */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WDT_WTCR_COMMON(x)          (WDT_WTCR_WTE_Msk | WDT_WTCR_WTIF_Msk | WDT_WTCR_WTR_Msk | ((x) << WDT_WTCR_WTIS_Pos))

#define WDT_WTCR_WAKEUP_INT_2POW4   (WDT_WTCR_COMMON(0) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^04 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW6   (WDT_WTCR_COMMON(1) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^06 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW8   (WDT_WTCR_COMMON(2) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^08 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW10  (WDT_WTCR_COMMON(3) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^10 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW12  (WDT_WTCR_COMMON(4) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^12 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW14  (WDT_WTCR_COMMON(5) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^14 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW16  (WDT_WTCR_COMMON(6) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^16 * WDT clock */
#define WDT_WTCR_WAKEUP_INT_2POW18  (WDT_WTCR_COMMON(7) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTWKE_Msk) /*!< WTCR setting for wakeup, interrupt enable and interval = 2^18 * WDT clock */

#define WDT_WTCR_INT_2POW4          (WDT_WTCR_COMMON(0) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^04 * WDT clock */
#define WDT_WTCR_INT_2POW6          (WDT_WTCR_COMMON(1) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^06 * WDT clock */
#define WDT_WTCR_INT_2POW8          (WDT_WTCR_COMMON(2) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^08 * WDT clock */
#define WDT_WTCR_INT_2POW10         (WDT_WTCR_COMMON(3) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^10 * WDT clock */
#define WDT_WTCR_INT_2POW12         (WDT_WTCR_COMMON(4) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^12 * WDT clock */
#define WDT_WTCR_INT_2POW14         (WDT_WTCR_COMMON(5) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^14 * WDT clock */
#define WDT_WTCR_INT_2POW16         (WDT_WTCR_COMMON(6) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^16 * WDT clock */
#define WDT_WTCR_INT_2POW18         (WDT_WTCR_COMMON(7) | WDT_WTCR_WTIE_Msk) /*!< WTCR setting for interrupt enable and interval = 2^18 * WDT clock */

#define WDT_WTCR_INT_RESET_2POW4    (WDT_WTCR_COMMON(0) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^04 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW6    (WDT_WTCR_COMMON(1) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^06 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW8    (WDT_WTCR_COMMON(2) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^08 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW10   (WDT_WTCR_COMMON(3) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^10 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW12   (WDT_WTCR_COMMON(4) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^12 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW14   (WDT_WTCR_COMMON(5) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^14 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW16   (WDT_WTCR_COMMON(6) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^16 * WDT clock */
#define WDT_WTCR_INT_RESET_2POW18   (WDT_WTCR_COMMON(7) | WDT_WTCR_WTIE_Msk | WDT_WTCR_WTRE_Msk) /*!< WTCR setting for interrupt, reset enable and interval = 2^18 * WDT clock */


/*---------------------------------------------------------------------------------------------------------*/
/* WTCRALT Constants Definitions                                                                           */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WDT_WTCRALT_WTRDSEL_1024    0x00000000UL /*!< WTCRALT setting for select Watchdog reset delay period is (1024 + 2) * WDT clock */
#define WDT_WTCRALT_WTRDSEL_128     0x00000001UL /*!< WTCRALT setting for select Watchdog reset delay period is (128 + 2) * WDT clock */
#define WDT_WTCRALT_WTRDSEL_16      0x00000002UL /*!< WTCRALT setting for select Watchdog reset delay period is (16 + 2) * WDT clock */
#define WDT_WTCRALT_WTRDSEL_1       0x00000003UL /*!< WTCRALT setting for select Watchdog reset delay period is (1 + 2) * WDT clock */


/*---------------------------------------------------------------------------------------------------------*/
/* WDT Macro Definitions                                                                                   */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     Get WDT Timeout Reset Flag
 */
#define _WDT_GET_RESET_FLAG()               ((((WDT->WTCR) & WDT_WTCR_WTRE_Msk) == WDT_WTCR_WTRE_Msk)? 1:0)


/**
 * @details     Clear WDT Timeout Reset Flag to 0
 */
#define _WDT_CLEAR_RESET_FLAG()             (WDT->WTCR |= WDT_WTCR_WTRE_Msk)


/**
 * @details     Get WDT Timeout Interrupt Flag
 */
#define _WDT_GET_TIMEOUT_INT_FLAG()         ((((WDT->WTCR) & WDT_WTCR_WTIF_Msk) == WDT_WTCR_WTIF_Msk)? 1:0)


/**
 * @details     Clear WDT Timeout Interrupt Flag to 0
 */
#define _WDT_CLEAR_TIMEOUT_INT_FLAG()       (WDT->WTCR |= WDT_WTCR_WTIF_Msk)


/**
 * @details     Get WDT Timeout Wake-up Flag
 */
#define _WDT_GET_TIMEOUT_WAKEUP_FLAG()      ((((WDT->WTCR) & WDT_WTCR_WTWKF_Msk) == WDT_WTCR_WTWKF_Msk)? 1:0)


/**
 * @details     Clear WDT Timeout Wake-up Flag to 0
 */
#define _WDT_CLEAR_TIMEOUT_WAKEUP_FLAG()    (WDT->WTCR |= WDT_WTCR_WTWKF_Msk)


/**
 * @details     Enable WDT to start counting
 */
#define _WDT_ENABLE_COUNTING()              (WDT->WTCR |= WDT_WTCR_WTE_Msk)


/**
 * @details     Disable WDT to stop counting
 */
#define _WDT_DISABLE_COUNTING()             (WDT->WTCR &= ~WDT_WTCR_WTE_Msk)


/**
 * @details     Reset the contents of WDT
 */
#define _WDT_RESET()                        (WDT->WTCR |= WDT_WTCR_WTR_Msk)


/**
 * @details     To select Watchdog reset delay period. x = WDT_WTCRALT_WTRDSEL_1024, WDT_WTCRALT_WTRDSEL_128, WDT_WTCRALT_WTRDSEL_16 or WDT_WTCRALT_WTRDSEL_1
 */
#define _WDT_SELECT_RESET_DELAY_PERIOD(x)   (WDT->WTCRALT = x)    


/*---------------------------------------------------------------------------------------------------------*/
/* WWDTCR Constants Definitions                                                                            */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
#define WWDT_WWDTCR_WINCMP(x)       ((x) << WWDT_WWDTCR_WINCMP_Pos)   /*!< WWDTCR setting for adjust the valid reload window. 0 <= x <= 0x3F */

#define WWDT_WWDTCR_PERIODSEL_1     (0 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 1 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_2     (1 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 2 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_4     (2 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 4 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_8     (3 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 8 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_16    (4 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 16 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_32    (5 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 32 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_64    (6 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 64 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_128   (7 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 128 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_192   (8 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 192 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_256   (9 << WWDT_WWDTCR_PERIODSEL_Pos)  /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 256 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_384   (10 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 384 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_512   (11 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 512 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_768   (12 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 768 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_1024  (13 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 1024 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_1536  (14 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 1536 * (64*WWDT_CLK) */
#define WWDT_WWDTCR_PERIODSEL_2048  (15 << WWDT_WWDTCR_PERIODSEL_Pos) /*!< WWDTCR setting to select the pre-scale for the WWDT counter period. Max timeout period is 2048 * (64*WWDT_CLK) */


/*---------------------------------------------------------------------------------------------------------*/
/* WWDT Macro Definitions                                                                                  */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @details     Enable WWDT to start counting
 *
 * @param[in]   wincmp      The WWDT valid reload window. 0 <= wincmp <= 0x3F.
 * @param[in]   periodsel   The pre-scale for the WWDT counter period. It could be \n
 *                              WWDT_WWDTCR_PERIODSEL_1, WWDT_WWDTCR_PERIODSEL_2, WWDT_WWDTCR_PERIODSEL_4, WWDT_WWDTCR_PERIODSEL_8, \n
 *                              WWDT_WWDTCR_PERIODSEL_16, WWDT_WWDTCR_PERIODSEL_32, WWDT_WWDTCR_PERIODSEL_64, WWDT_WWDTCR_PERIODSEL_128, \n
 *                              WWDT_WWDTCR_PERIODSEL_192, WWDT_WWDTCR_PERIODSEL_256, WWDT_WWDTCR_PERIODSEL_384, WWDT_WWDTCR_PERIODSEL_512, \n
 *                              WWDT_WWDTCR_PERIODSEL_768, WWDT_WWDTCR_PERIODSEL_1024, WWDT_WWDTCR_PERIODSEL_1536, WWDT_WWDTCR_PERIODSEL_2048.
 *
 * @return      None
 *
 * @details     To start WWDT counting and WWDT interrupt function is disabled.
 */
#define _WWDT_ENABLE(wincmp, periodsel)         (WWDT->WWDTCR = (WWDT_WWDTCR_WINCMP(wincmp) | (periodsel) | WWDT_WWDTCR_WWDTEN_Msk))


/**
 * @details     Enable WWDT to start counting with WWDT interrupt enable
 *
 * @param[in]   wincmp      The WWDT valid reload window. 0 <= wincmp <= 0x3F.
 * @param[in]   periodsel   The pre-scale for the WWDT counter period. It could be \n
 *                              WWDT_WWDTCR_PERIODSEL_1, WWDT_WWDTCR_PERIODSEL_2, WWDT_WWDTCR_PERIODSEL_4, WWDT_WWDTCR_PERIODSEL_8, \n
 *                              WWDT_WWDTCR_PERIODSEL_16, WWDT_WWDTCR_PERIODSEL_32, WWDT_WWDTCR_PERIODSEL_64, WWDT_WWDTCR_PERIODSEL_128, \n
 *                              WWDT_WWDTCR_PERIODSEL_192, WWDT_WWDTCR_PERIODSEL_256, WWDT_WWDTCR_PERIODSEL_384, WWDT_WWDTCR_PERIODSEL_512, \n
 *                              WWDT_WWDTCR_PERIODSEL_768, WWDT_WWDTCR_PERIODSEL_1024, WWDT_WWDTCR_PERIODSEL_1536, WWDT_WWDTCR_PERIODSEL_2048.
 *
 * @return      None
 *
 * @details     To start WWDT counting and enable WWDT interrupt function.
 */
#define _WWDT_ENABLE_IE(wincmp, periodsel)      (WWDT->WWDTCR = (WWDT_WWDTCR_WINCMP(wincmp) | (periodsel) | WWDT_WWDTCR_WWDTIE_Msk | WWDT_WWDTCR_WWDTEN_Msk))


/**
 * @details     To reload the WWDT counter value to 0x3F
 */
#define _WWDT_RELOAD_COUNTER()                  (WWDT->WWDTRLD = 0x00005AA5)


/**
 * @details     To get the counter value of WWDT
 */
#define _WWDT_GET_COUNTER()                     (WWDT->WWDTCVR)
   

/**
 * @details     Get WWDT Compare Match Interrupt Flag
 */
#define _WWDT_GET_CMP_INT_FLAG()                ((((WWDT->WWDTSR) & WWDT_WWDTSR_WWDTIF_Msk) == WWDT_WWDTSR_WWDTIF_Msk)? 1:0)


/**
 * @details     Clear WWDT Compare Match Interrupt Flag to 0
 */
#define _WWDT_CLEAR_CMP_INT_FLAG()              (WWDT->WWDTSR = WWDT_WWDTSR_WWDTIF_Msk)


/**
 * @details     Get WWDT Timeout Reset Flag
 */
#define _WWDT_GET_RESET_FLAG()                  ((((WWDT->WWDTSR) & WWDT_WWDTSR_WWDTRF_Msk) == WWDT_WWDTSR_WWDTRF_Msk)? 1:0)


/**
 * @details     Clear WWDT Timeout Reset Flag to 0
 */
#define _WWDT_CLEAR_RESET_FLAG()                (WWDT->WWDTSR = WWDT_WWDTSR_WWDTRF_Msk)



/**
  * @} End of WDT Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 


#endif  // __WDT_H__ 
