
/**************************************************************************//**
 * @file     pac5xxx_SYS.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX System and Clock Controller
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
 
/*------------- System and Clock Controller (SYSCLKCTL) ----------------------*/
/** @addtogroup PAC5XXX_SYSCLKCTL PAC5XXX System and Clock Controller (SYSCLKCTL)
  @{
*/

/** CCSCTL Clock Source Enumeration Type */
typedef enum {
  CCSCTL_CLKIN_INTOSC = 0,                /*!< Input Clock Select: internal oscillator        */
  CCSCTL_CLKIN_CLKREF = 1,                /*!< Input Clock Select: CLKREF input               */
  CCSCTL_CLKIN_EXTCLK = 2,                /*!< Input Clock Select: EXTCLK input               */
  CCSCTL_CLKIN_XTAL = 3                   /*!< Input Clock Select: Crystal Driver             */
} CCSCTL_CLKIN_Type;

/** CCSCTL HCLK Divider Enumeration Type */
typedef enum {
	CCSCTL_HCLKDIV_DIV1 = 0,                /*!< HCLK Input Divider (/1)                        */
	CCSCTL_HCLKDIV_DIV2 = 1,                /*!< HCLK Input Divider (/2)                        */
	CCSCTL_HCLKDIV_DIV4 = 2,                /*!< HCLK Input Divider (/4)                        */
	CCSCTL_HCLKDIV_DIV8 = 3,                /*!< HCLK Input Divider (/8)                        */
} CCSCTL_HCLKDIV_Type;

/** CCSCTL ACLK Divider Enumeration Type */
typedef enum {
  CCSCTL_ACLKDIV_DIV1 = 0,               	/*!< ACLK Divider: /1                              */
  CCSCTL_ACLKDIV_DIV2 = 1,               	/*!< ACLK Divider: /2                              */
  CCSCTL_ACLKDIV_DIV4 = 2,               	/*!< ACLK Divider: /4                              */
  CCSCTL_ACLKDIV_DIV8 = 3,               	/*!< ACLK Divider: /8                              */
  CCSCTL_ACLKDIV_DIV16 = 4,              	/*!< ACLK Divider: /16                             */
  CCSCTL_ACLKDIV_DIV32 = 5,              	/*!< ACLK Divider: /32                             */
  CCSCTL_ACLKDIV_DIV64 = 6,              	/*!< ACLK Divider: /64                             */
  CCSCTL_ACLKDIV_DIV128 = 7              	/*!< ASCLK Divider: /128                           */
} CCSCTL_ACLKDIV_Type;

/** OSCCTL Frequency Select Enumeration Type */
typedef enum {
  OSCCTL_OSCP_28P17MHZ = 0,                /*!< Oscillator Frequency: 28.17 MHz                */
  OSCCTL_OSCP_15P29MHZ = 1,                /*!< Oscillator Frequency: 15.29 MHz                */
  OSCCTL_OSCP_10P68MHZ = 2,                /*!< Oscillator Frequency: 10.68 MHz                */
  OSCCTL_OSCP_8P31MHZ = 3                  /*!< Oscillator Frequency: 8.31 MHz                 */
} OSCCTL_FREQSEL_Type;

#define OSCCTL_OSCP_8P31MHZPLLCTL_INPUT_DIV(x)   ((x - 2) & 0x001F)   /*!< PLL Input divider                      */
#define PLLCTL_FDBK_DIV(x)    ((x - 2) & 0x01FF)   /*!< PLL Feedback divider                   */
#define PLLCTL_OUTPUT_DIV(x)  ((x)     & 0x000F)   /*!< PLL Output divider                     */

typedef struct
{
  /*!< CCSCTL: Offset 0x0000:      Clock Control System Configuration Register                      */
  struct {
    __IO uint32_t CLKIN                    : 2;   /*!< Input Clock Select                            */
    __IO uint32_t ACLKDIV                  : 3;   /*!< ACLK Divider                                 */
    __IO uint32_t HCLKDIV                  : 2;   /*!< HCLK Divider                                  */
    __IO uint32_t FCLK                     : 1;   /*!< FCLK input select (0: FRCLK, 1: PLL)   */
         uint32_t                          : 24;
  } CCSCTL;
  
  /*!< PLLCTL: Offset 0x0004:      PLL Control Register                                             */
  struct {
    __IO uint32_t PLLEN                    : 1;   /*!< PLL enable                                    */
         uint32_t                          : 1;
    __IO uint32_t PLLINDIV                 : 5;   /*!< PLL input divider                             */
    __IO uint32_t PLLFBDIV                 : 9;   /*!< PLL feedback divider                          */
    __IO uint32_t PLLOUTDIV                : 4;   /*!< PLL output divider                            */
         uint32_t                          : 11;
  } PLLCTL;

  /*!< OSCCTL: Offset 0x0008:      Free-Running Oscillator Control Register                         */
  struct {
    __IO uint32_t OSCEN                    : 1;   /*!< Enable Oscillator                             */
    __IO uint32_t OSCP                     : 2;   /*!< Oscillator Frequency Setting                  */
         uint32_t                          : 29;
  } OSCCTL;
  
  /*!< XTALCTL: Offset 0x000C:     Crystal Oscillator Control Register                              */
  struct {
    __IO uint32_t XTALEN                   : 1;   /*!< Enable XTAL driver                           */
         uint32_t                          : 30;
  } XTALCTL;
  
} PAC5XXX_SYSCLKCTL_TypeDef;
/*@}*/ /* end of group PAC5XXX_SYSCLKCTL */
