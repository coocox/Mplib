
/**************************************************************************//**
 * @file     pac5xxx_WDT.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX Watchdog Timer
 * @version  V0.2
 * @date     17 May 2012
 *
 * @note
 * Copyright (C) 2012 Active Semiconductor. All rights reserved.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

/*------------- Watchdog Timer (WDT) ----------------------*/
/** @addtogroup PAC5XXX_WDT PAC5XXX Watchdog Timer (WDT)
  @{
*/

#define WDTCTL_PASS_WRITE          0x4A000000    /*!< WDT Write Register Password                                 */
#define WDTCTL_PASS_READ           0x63000000    /*!< WDT Read Register Password                                  */

#define WDTCTL_IF_SHIFT            4             /*!< WDT interrupt flag bit-shift                                */
#define WDTCTL_IF_MASK             0x00000010    /*!< WDT interrupt flag mask                                     */

#define WDTCTL_RST_SHIFT           0             /*!< WDT reset key bit-shift                                     */
#define WDTCTL_RST_VAL             0x00000005    /*!< WDT reset key value                                         */

#define WDTCTL_IE_SHIFT            3            /*!< WDT interrupt enable bit-shift                              */
#define WDTCTL_IE_MASK             0x00000008    /*!< WDT interrupt enable mask                                   */

#define WDTCTL_POREN_SHIFT         5            /*!< WDT POR enable bit-shift                                    */
#define WDTCTL_POREN_MASK          0x00000020   /*!< WDT POR enable mask                                         */

#define WDTCTL_WRBUSY_SHIFT        11            /*!< WDT Write Busy bit-shift                                    */
#define WDTCTL_WRBUSY_MASK         0x00000800   /*!< WDT Write Busy mask                                         */

#define WDT_WAIT_WRITE_BLOCK       while ((PAC5XXX_WDT->WDTCTL & WDTCTL_WRBUSY_MASK) != 0);

/** WDTCTL Pre-scaler Enumeration Type */
typedef enum {
  WDTCTL_PS_DIV2 = 0,                            /*!< WDT Pre-Scaler (/2)                                         */
  WDTCTL_PS_DIV4 = 1,                            /*!< WDT Pre-Scaler (/4)                                         */
  WDTCTL_PS_DIV8 = 2,                            /*!< WDT Pre-Scaler (/8)                                         */
  WDTCTL_PS_DIV16 = 3,                           /*!< WDT Pre-Scaler (/16)                                        */
  WDTCTL_PS_DIV32 = 4,                           /*!< WDT Pre-Scaler (/32)                                        */
  WDTCTL_PS_DIV64 = 5,                           /*!< WDT Pre-Scaler (/64)                                        */
  WDTCTL_PS_DIV128 = 6,                          /*!< WDT Pre-Scaler (/128)                                       */
  WDTCTL_PS_DIV256 = 7,                          /*!< WDT Pre-Scaler (/128)                                       */
  WDTCTL_PS_DIV512 = 8,                          /*!< WDT Pre-Scaler (/512)                                       */
  WDTCTL_PS_DIV1024 = 9,                         /*!< WDT Pre-Scaler (/1024)                                      */
  WDTCTL_PS_DIV2048 = 10,                        /*!< WDT Pre-Scaler (/2048)                                      */
  WDTCTL_PS_DIV4096 = 11,                        /*!< WDT Pre-Scaler (/4096)                                      */
  WDTCTL_PS_DIV8192 = 12,                        /*!< WDT Pre-Scaler (/8192)                                      */
  WDTCTL_PS_DIV16384 = 13,                       /*!< WDT Pre-Scaler (/16384)                                     */
  WDTCTL_PS_DIV32767 = 14,                       /*!< WDT Pre-Scaler (/32767)                                     */
  WDTCTL_PS_DIV65536 = 15                        /*!< WDT Pre-Scaler (/65536)                                     */
} WDTCTL_PS_Type;

#define WDTCTL_PS_SHIFT            6            /*!< WDT Pre-scaler bit-shift                                    */

/** WDTCTL Clock Select Enumeration Type */
typedef enum {
  WDTCTL_CLKSEL_FRCLK = 0,                       /*!< WDT Clock Select (FRCLK)                                    */
  WDTCTL_CLKSEL_PLLCLK = 1                       /*!< WDT Clock Select (PLLCLK)                                   */
} WDTCTL_CLKSEL_Type;

#define WDTCTL_CLKSEL_SHIFT        10            /*!< WDT CLKSEL shift                                            */

typedef struct
{
  /*!< WDTCTL:      Offset: 0x0000             Watchdog Timer Control Register       */
  __IO uint32_t WDTCTL;

  /*!< WDTCDV:       Offset: 0x0004            Watchdog Timer Countdown Value Reg    */  
  __IO uint32_t WDTCDV;
  
  /*!< WDTCDR:       Offset: 0x0008            Watchdog Timer Countdown Register     */
  union {
    __IO uint32_t w;
    struct {
      __IO uint32_t s               : 16;
           uint32_t                 : 16;
    };
    struct {
      __IO uint32_t b               : 8;
           uint32_t                 : 24;
    };
    struct {
      __I uint32_t VAL              : 24;          /*!< Countdown Register Value         */
	        uint32_t                  : 8;
    };
  } WDTCTR;
  
} PAC5XXX_WDT_TypeDef;
/*@}*/ /* end of group PAC5XXX_WDT */
