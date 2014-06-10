/**************************************************************************//**
 * @file     SYS.h
 * @version  V1.00
 * $Revision: 12 $
 * $Date: 12/11/09 8:04p $
 * @brief    NUC200 Series Global Control and Clock Control Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __SYS_H__
#define __SYS_H__

#include "NUC200Series.h"

/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup SYS_FUNC SYS Device Function Interface
  * @{
  */


/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON constant definitions. PLL = FIN * NF / NR / NO                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_PLLCON_FIN_IRC22M   0x00080000UL        /*!< For PLL clock source is internal RC clock. 4MHz < FIN < 24MHz */ 
#define SYSCLK_PLLCON_FIN_XTAL     0x00000000UL        /*!< For PLL clock source is external cristal.  4MHz < FIN < 24MHz */

#define SYSCLK_PLLCON_NR(x)        (((x)-2)<<9)        /*!< x must be constant and 2 <= x <= 33.  1.6MHz < FIN/NR < 15MHz */
#define SYSCLK_PLLCON_NF(x)         ((x)-2)            /*!< x must be constant and 2 <= x <= 513. 100MHz < FIN*NF/NR < 200MHz. (120MHz < FIN*NF/NR < 200MHz is preferred.) */ 
 
#define SYSCLK_PLLCON_NO_1         0x0000UL            /*!< For output divider is 1 */
#define SYSCLK_PLLCON_NO_2         0x4000UL            /*!< For output divider is 2 */
#define SYSCLK_PLLCON_NO_4         0xC000UL            /*!< For output divider is 4 */

#if (__XTAL == 12000000)
#define SYSCLK_PLLCON_FOR_I2S      (0xA54)                                                                                     /*!< Predefined PLLCON setting for 147428571.428571Hz PLL output with 12MHz X'tal */
#define SYSCLK_PLLCON_50MHz_XTAL   (SYSCLK_PLLCON_FIN_XTAL | SYSCLK_PLLCON_NR(3) | SYSCLK_PLLCON_NF( 25) | SYSCLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50MHz PLL output with 12MHz X'tal */
#define SYSCLK_PLLCON_48MHz_XTAL   (SYSCLK_PLLCON_FIN_XTAL | SYSCLK_PLLCON_NR(7) | SYSCLK_PLLCON_NF(112) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48MHz PLL output with 12MHz X'tal */
#define SYSCLK_PLLCON_36MHz_XTAL   (SYSCLK_PLLCON_FIN_XTAL | SYSCLK_PLLCON_NR(7) | SYSCLK_PLLCON_NF( 84) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 36MHz PLL output with 12MHz X'tal */
#define SYSCLK_PLLCON_32MHz_XTAL   (SYSCLK_PLLCON_FIN_XTAL | SYSCLK_PLLCON_NR(6) | SYSCLK_PLLCON_NF( 64) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 32MHz PLL output with 12MHz X'tal */
#define SYSCLK_PLLCON_24MHz_XTAL   (SYSCLK_PLLCON_FIN_XTAL | SYSCLK_PLLCON_NR(2) | SYSCLK_PLLCON_NF( 16) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 24MHz PLL output with 12MHz X'tal */
#else
# error "The PLL pre-definitions are only valid when external crystal is 12MHz"
#endif

#define SYSCLK_PLLCON_50MHz_IRC22M (SYSCLK_PLLCON_FIN_IRC22M | SYSCLK_PLLCON_NR(13) | SYSCLK_PLLCON_NF( 59) | SYSCLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50.1918MHz PLL output with 22.1184MHz IRC */
#define SYSCLK_PLLCON_48MHz_IRC22M (SYSCLK_PLLCON_FIN_IRC22M | SYSCLK_PLLCON_NR(13) | SYSCLK_PLLCON_NF(113) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48.064985MHz PLL output with 22.1184MHz IRC*/
#define SYSCLK_PLLCON_36MHz_IRC22M (SYSCLK_PLLCON_FIN_IRC22M | SYSCLK_PLLCON_NR(12) | SYSCLK_PLLCON_NF( 78) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 35.9424MHz PLL output with 22.1184MHz IRC */
#define SYSCLK_PLLCON_32MHz_IRC22M (SYSCLK_PLLCON_FIN_IRC22M | SYSCLK_PLLCON_NR( 9) | SYSCLK_PLLCON_NF( 52) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 31.9488MHz PLL output with 22.1184MHz IRC*/
#define SYSCLK_PLLCON_24MHz_IRC22M (SYSCLK_PLLCON_FIN_IRC22M | SYSCLK_PLLCON_NR( 3) | SYSCLK_PLLCON_NF( 13) | SYSCLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 23.9616MHz PLL output with 22.1184MHz IRC*/


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL0 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKSEL0_HCLK_XTAL          0x00UL /*!< Setting clock source as external X'tal */ 
#define SYSCLK_CLKSEL0_HCLK_XTAL32K       0x01UL /*!< Setting clock source as external X'tal 32.768KHz*/ 
#define SYSCLK_CLKSEL0_HCLK_PLL           0x02UL /*!< Setting clock source as PLL output */
#define SYSCLK_CLKSEL0_HCLK_IRC10K        0x03UL /*!< Setting clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL0_HCLK_IRC22M        0x07UL /*!< Setting clock source as internal 22.1184MHz RC clock */

#define SYSCLK_CLKSEL0_STCLK_XTAL         0x00UL    /*!< Setting clock source as external X'tal */ 
#define SYSCLK_CLKSEL0_STCLK_XTAL32K      (1UL<<3)  /*!< Setting clock source as external X'tal 32.768KHz*/ 
#define SYSCLK_CLKSEL0_STCLK_XTAL_DIV2    (2UL<<3)  /*!< Setting clock source as external X'tal/2 */
#define SYSCLK_CLKSEL0_STCLK_HCLK_DIV2    (3UL<<3)  /*!< Setting clock source as HCLK/2 */
#define SYSCLK_CLKSEL0_STCLK_IRC22M_DIV2  (7UL<<3)  /*!< Setting clock source as internal 22.1184MHz RC clock/2 */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKSEL1_WDT_XTAL32K       (1UL<<0)       /*!< Setting WDT clock source as external X'tal 32.768KHz*/ 
#define SYSCLK_CLKSEL1_WDT_HCLK_DIV2048  (2UL<<0)       /*!< Setting WDT clock source as HCLK/2048 */
#define SYSCLK_CLKSEL1_WDT_IRC10K        (3UL<<0)       /*!< Setting WDT clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL1_ADC_XTAL          0x00000000UL   /*!< Setting ADC clock source as external X'tal */
#define SYSCLK_CLKSEL1_ADC_PLL           (1UL<<2)       /*!< Setting ADC clock source as PLL */ 
#define SYSCLK_CLKSEL1_ADC_HCLK          (2UL<<2)       /*!< Setting ADC clock source as HCLK */
#define SYSCLK_CLKSEL1_ADC_IRC22M        (3UL<<2)       /*!< Setting ADC clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL1_SPI0_PLL          0x00000000UL   /*!< Setting SPI0 clock source as PLL */ 
#define SYSCLK_CLKSEL1_SPI0_HCLK         (1UL<<4)       /*!< Setting SPI0 clock source as HCLK */
#define SYSCLK_CLKSEL1_SPI1_PLL          0x00000000UL   /*!< Setting SPI1 clock source as PLL */ 
#define SYSCLK_CLKSEL1_SPI1_HCLK         (1UL<<5)       /*!< Setting SPI1 clock source as HCLK */
#define SYSCLK_CLKSEL1_SPI2_PLL          0x00000000UL   /*!< Setting SPI2 clock source as PLL */ 
#define SYSCLK_CLKSEL1_SPI2_HCLK         (1UL<<6)       /*!< Setting SPI2 clock source as HCLK */
#define SYSCLK_CLKSEL1_SPI3_PLL          0x00000000UL   /*!< Setting SPI3 clock source as PLL */ 
#define SYSCLK_CLKSEL1_SPI3_HCLK         (1UL<<7)       /*!< Setting SPI3 clock source as HCLK */

#define SYSCLK_CLKSEL1_TMR0_XTAL         0x00000000UL   /*!< Setting Timer 0 clock source as external X'tal */
#define SYSCLK_CLKSEL1_TMR0_XTAL32K      (1UL<<8)       /*!< Setting Timer 0 clock source as external X'tal 32.768KHz */
#define SYSCLK_CLKSEL1_TMR0_HCLK         (2UL<<8)       /*!< Setting Timer 0 clock source as HCLK */
#define SYSCLK_CLKSEL1_TMR0_EXT_TRG      (3UL<<8)       /*!< Setting Timer 0 clock source as external trigger */
#define SYSCLK_CLKSEL1_TMR0_IRC10K       (5UL<<8)       /*!< Setting Timer 0 clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL1_TMR0_IRC22M       (7UL<<8)       /*!< Setting Timer 0 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL1_TMR1_XTAL         0x00000000UL   /*!< Setting Timer 1 clock source as external X'tal */
#define SYSCLK_CLKSEL1_TMR1_XTAL32K      (1UL<<12)      /*!< Setting Timer 1 clock source as external X'tal 32.768KHz */
#define SYSCLK_CLKSEL1_TMR1_HCLK         (2UL<<12)      /*!< Setting Timer 1 clock source as HCLK */
#define SYSCLK_CLKSEL1_TMR1_EXT_TRG      (3UL<<12)      /*!< Setting Timer 1 clock source as external trigger */
#define SYSCLK_CLKSEL1_TMR1_IRC10K       (5UL<<12)      /*!< Setting Timer 1 clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL1_TMR1_IRC22M       (7UL<<12)      /*!< Setting Timer 1 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL1_TMR2_XTAL         0x00000000UL   /*!< Setting Timer 2 clock source as external X'tal */
#define SYSCLK_CLKSEL1_TMR2_XTAL32K      (1UL<<16)      /*!< Setting Timer 2 clock source as external X'tal 32.768KHz */
#define SYSCLK_CLKSEL1_TMR2_HCLK         (2UL<<16)      /*!< Setting Timer 2 clock source as HCLK */
#define SYSCLK_CLKSEL1_TMR2_EXT_TRG      (3UL<<16)      /*!< Setting Timer 2 clock source as external trigger */
#define SYSCLK_CLKSEL1_TMR2_IRC10K       (5UL<<16)      /*!< Setting Timer 2 clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL1_TMR2_IRC22M       (7UL<<16)      /*!< Setting Timer 2 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL1_TMR3_XTAL         0x00000000UL   /*!< Setting Timer 3 clock source as external X'tal */
#define SYSCLK_CLKSEL1_TMR3_XTAL32K      (1UL<<20)      /*!< Setting Timer 3 clock source as external X'tal 32.768KHz */
#define SYSCLK_CLKSEL1_TMR3_HCLK         (2UL<<20)      /*!< Setting Timer 3 clock source as HCLK */
#define SYSCLK_CLKSEL1_TMR3_EXT_TRG      (3UL<<20)      /*!< Setting Timer 3 clock source as external trigger */
#define SYSCLK_CLKSEL1_TMR3_IRC10K       (5UL<<20)      /*!< Setting Timer 3 clock source as internal 10KHz RC clock */
#define SYSCLK_CLKSEL1_TMR3_IRC22M       (7UL<<20)      /*!< Setting Timer 3 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL1_UART_XTAL         0x00000000UL   /*!< Setting UART clock source as external X'tal */
#define SYSCLK_CLKSEL1_UART_PLL          (1UL<<24)      /*!< Setting UART clock source as external PLL */
#define SYSCLK_CLKSEL1_UART_IRC22M       (3UL<<24)      /*!< Setting UART clock source as external internal 22.1184MHz RC clock */

#define SYSCLK_CLKSEL1_PWM01_XTAL        0x00000000UL   /*!< Setting PWM01 clock source control CLKSEL1[29:28] as external X'tal, 
                                                             user must set SYSCLK_CLKSEL2_PWM01_EXT_XTAL concurrently to complete clock source as external X'tal setting*/
#define SYSCLK_CLKSEL1_PWM01_XTAL32K     (1UL<<28)      /*!< Setting PWM01 clock source as external X'tal 32.768KHz,
                                                             user must set SYSCLK_CLKSEL2_PWM01_EXT_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/
#define SYSCLK_CLKSEL1_PWM01_HCLK        (2UL<<28)      /*!< Setting PWM01 clock source as HCLK 
                                                             user must set SYSCLK_CLKSEL2_PWM01_EXT_HCLK concurrently to complete clock source as HCLK setting*/
#define SYSCLK_CLKSEL1_PWM01_IRC22M      (3UL<<28)      /*!< Setting PWM01 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM01_EXT_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/ 
#define SYSCLK_CLKSEL1_PWM01_IRC10K      (3UL<<28)      /*!< Setting PWM01 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM01_EXT_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/
#define SYSCLK_CLKSEL1_PWM23_XTAL        0x00000000UL   /*!< Setting PWM23 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL2_PWM23_EXT_XTAL concurrently to complete clock source as external X'tal setting*/
#define SYSCLK_CLKSEL1_PWM23_XTAL32K     (1UL<<30)      /*!< Setting PWM23 clock source as external X'tal 32.768KHz,
                                                             user must set SYSCLK_CLKSEL2_PWM23_EXT_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/
#define SYSCLK_CLKSEL1_PWM23_HCLK        (2UL<<30)      /*!< Setting PWM23 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL2_PWM23_EXT_HCLK concurrently to complete clock source as HCLK setting*/
#define SYSCLK_CLKSEL1_PWM23_IRC22M      (3UL<<30)      /*!< Setting PWM23 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM23_EXT_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/
#define SYSCLK_CLKSEL1_PWM23_IRC10K      (3UL<<30)      /*!< Setting PWM23 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM23_EXT_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKSEL2_I2S_XTAL           0x00000000UL  /*!< Setting I2S clock source as external X'tal */ 
#define SYSCLK_CLKSEL2_I2S_PLL            (1UL<<0)      /*!< Setting I2S clock source as PLL */
#define SYSCLK_CLKSEL2_I2S_HCLK           (2UL<<0)      /*!< Setting I2S clock source as HCLK */
#define SYSCLK_CLKSEL2_I2S_IRC22M         (3UL<<0)      /*!< Setting I2S clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL2_FRQDIV_XTAL        0x00000000UL  /*!< Setting FRQDIV clock source as external X'tal */ 
#define SYSCLK_CLKSEL2_FRQDIV_XTAL32K     (1UL<<2)      /*!< Setting FRQDIV clock source as external X'tal 32.768KHz */ 
#define SYSCLK_CLKSEL2_FRQDIV_HCLK        (2UL<<2)      /*!< Setting FRQDIV clock source as HCLK */
#define SYSCLK_CLKSEL2_FRQDIV_IRC22M      (3UL<<2)      /*!< Setting FRQDIV clock source as internal 22.1184MHz RC clock */

#define SYSCLK_CLKSEL2_PWM45_XTAL         0x00000000UL  /*!< Setting PWM45 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL2_PWM45_EXT_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM45_XTAL32K      (1UL<<4)      /*!< Setting PWM45 clock source as external X'tal 32.768KHz,
                                                             user must set SYSCLK_CLKSEL2_PWM45_EXT_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/
#define SYSCLK_CLKSEL2_PWM45_HCLK         (2UL<<4)      /*!< Setting PWM45 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL2_PWM45_EXT_HCLK concurrently to complete clock source as HCLK setting*/
#define SYSCLK_CLKSEL2_PWM45_IRC22M       (3UL<<4)      /*!< Setting PWM45 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM45_EXT_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/
#define SYSCLK_CLKSEL2_PWM45_IRC10K       (3UL<<4)      /*!< Setting PWM45 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM45_EXT_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/
#define SYSCLK_CLKSEL2_PWM67_XTAL         0x00000000UL  /*!< Setting PWM67 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL2_PWM67_EXT_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM67_XTAL32K      (1UL<<6)      /*!< Setting PWM67 clock source as external X'tal 32.768KHz,
                                                             user must set SYSCLK_CLKSEL2_PWM67_EXT_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/ 
#define SYSCLK_CLKSEL2_PWM67_HCLK         (2UL<<6)      /*!< Setting PWM67 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL2_PWM67_EXT_HCLK concurrently to complete clock source as HCLK setting*/
#define SYSCLK_CLKSEL2_PWM67_IRC22M       (3UL<<6)      /*!< Setting PWM67 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM67_EXT_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/
#define SYSCLK_CLKSEL2_PWM67_IRC10K       (3UL<<6)      /*!< Setting PWM67 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL2_PWM67_EXT_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/

#define SYSCLK_CLKSEL2_PWM01_EXT_XTAL     0x00000000UL  /*!< Setting PWM01 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL1_PWM01_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM01_EXT_XTAL32K  0x00000000UL  /*!< Setting PWM01 clock source as external X'tal  32.768KHz,
                                                             user must set SYSCLK_CLKSEL1_PWM01_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/ 
#define SYSCLK_CLKSEL2_PWM01_EXT_HCLK     0x00000000UL  /*!< Setting PWM01 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL1_PWM01_HCLK concurrently to complete clock source as HCLK setting*/ 
#define SYSCLK_CLKSEL2_PWM01_EXT_IRC22M   0x00000000UL  /*!< Setting PWM01 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM01_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/ 
#define SYSCLK_CLKSEL2_PWM01_EXT_IRC10K   (1UL<<8)      /*!< Setting PWM01 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM01_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/ 

#define SYSCLK_CLKSEL2_PWM23_EXT_XTAL     0x00000000UL  /*!< Setting PWM23 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL1_PWM23_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM23_EXT_XTAL32K  0x00000000UL  /*!< Setting PWM23 clock source as external X'tal  32.768KHz,
                                                             user must set SYSCLK_CLKSEL1_PWM23_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/ 
#define SYSCLK_CLKSEL2_PWM23_EXT_HCLK     0x00000000UL  /*!< Setting PWM23 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL1_PWM23_HCLK concurrently to complete clock source as HCLK setting*/ 
#define SYSCLK_CLKSEL2_PWM23_EXT_IRC22M   0x00000000UL  /*!< Setting PWM23 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM23_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/  
#define SYSCLK_CLKSEL2_PWM23_EXT_IRC10K   (1UL<<9)      /*!< Setting PWM23 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM23_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/ 

#define SYSCLK_CLKSEL2_PWM45_EXT_XTAL     0x00000000UL  /*!< Setting PWM45 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL1_PWM45_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM45_EXT_XTAL32K  0x00000000UL  /*!< Setting PWM45 clock source as external X'tal  32.768KHz,
                                                             user must set SYSCLK_CLKSEL1_PWM45_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/  
#define SYSCLK_CLKSEL2_PWM45_EXT_HCLK     0x00000000UL  /*!< Setting PWM45 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL1_PWM45_HCLK concurrently to complete clock source as HCLK setting*/ 
#define SYSCLK_CLKSEL2_PWM45_EXT_IRC22M   0x00000000UL  /*!< Setting PWM45 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM45_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/   
#define SYSCLK_CLKSEL2_PWM45_EXT_IRC10K   (1UL<<10)     /*!< Setting PWM45 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM45_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/ 

#define SYSCLK_CLKSEL2_PWM67_EXT_XTAL     0x00000000UL  /*!< Setting PWM67 clock source as external X'tal,
                                                             user must set SYSCLK_CLKSEL1_PWM67_XTAL concurrently to complete clock source as external X'tal setting*/ 
#define SYSCLK_CLKSEL2_PWM67_EXT_XTAL32K  0x00000000UL  /*!< Setting PWM67 clock source as external X'tal  32.768KHz,
                                                             user must set SYSCLK_CLKSEL1_PWM67_XTAL32K concurrently to complete clock source as external X'tal 32.768KHz setting*/ 
#define SYSCLK_CLKSEL2_PWM67_EXT_HCLK     0x00000000UL  /*!< Setting PWM67 clock source as HCLK,
                                                             user must set SYSCLK_CLKSEL1_PWM67_HCLK concurrently to complete clock source as HCLK setting*/ 
#define SYSCLK_CLKSEL2_PWM67_EXT_IRC22M   0x00000000UL  /*!< Setting PWM67 clock source as internal 22.1184MHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM67_IRC22M concurrently to complete clock source as internal 22.1184MHz RC clock setting*/     
#define SYSCLK_CLKSEL2_PWM67_EXT_IRC10K   (1UL<<11)     /*!< Setting PWM67 clock source as internal 10KHz RC clock,
                                                             user must set SYSCLK_CLKSEL1_PWM67_IRC10K concurrently to complete clock source as internal 10KHz RC clock setting*/         

#define SYSCLK_CLKSEL2_WWDT_HCLK_DIV2048   (2UL<<16)    /*!< Setting Window Watchdog Timer clock source as external X'tal */ 
#define SYSCLK_CLKSEL2_WWDT_IRC10K         (3UL<<16)    /*!< Setting Window Watchdog Timer clock source as internal 10KHz RC clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL3 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKSEL3_SC0_XTAL           0x00000000UL  /*!< Setting SC0 clock source as external X'tal */ 
#define SYSCLK_CLKSEL3_SC0_PLL            (1UL<<0)      /*!< Setting SC0 clock source as PLL */
#define SYSCLK_CLKSEL3_SC0_HCLK           (2UL<<0)      /*!< Setting SC0 clock source as HCLK */
#define SYSCLK_CLKSEL3_SC0_IRC22M         (3UL<<0)      /*!< Setting SC0 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL3_SC1_XTAL           0x00000000UL  /*!< Setting SC1 clock source as external X'tal */ 
#define SYSCLK_CLKSEL3_SC1_PLL            (1UL<<2)      /*!< Setting SC1 clock source as PLL */
#define SYSCLK_CLKSEL3_SC1_HCLK           (2UL<<2)      /*!< Setting SC1 clock source as HCLK */
#define SYSCLK_CLKSEL3_SC1_IRC22M         (3UL<<2)      /*!< Setting SC1 clock source as internal 22.1184MHz RC clock */
#define SYSCLK_CLKSEL3_SC2_XTAL           0x00000000UL  /*!< Setting SC2 clock source as external X'tal */ 
#define SYSCLK_CLKSEL3_SC2_PLL            (1UL<<4)      /*!< Setting SC2 clock source as PLL */
#define SYSCLK_CLKSEL3_SC2_HCLK           (2UL<<4)      /*!< Setting SC2 clock source as HCLK */
#define SYSCLK_CLKSEL3_SC2_IRC22M         (3UL<<4)      /*!< Setting SC2 clock source as internal 22.1184MHz RC clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKDIV_HCLK(x)  ((x)-1)        /*!< CLKDIV Setting for HCLK clock divider. It could be 1~16 */ 
#define SYSCLK_CLKDIV_USB(x)  (((x)-1) <<  4) /*!< CLKDIV Setting for USB clock divider. It could be 1~16  */ 
#define SYSCLK_CLKDIV_UART(x) (((x)-1) <<  8) /*!< CLKDIV Setting for UART clock divider. It could be 1~16 */ 
#define SYSCLK_CLKDIV_ADC(x)  (((x)-1) << 16) /*!< CLKDIV Setting for ADC clock divider. It could be 1~256 */ 

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define SYSCLK_CLKDIV1_SC0(x)  ((x)-1)        /*!< CLKDIV1 Setting for SC0 clock divider. It could be 1~256*/ 
#define SYSCLK_CLKDIV1_SC1(x)  (((x)-1) << 8) /*!< CLKDIV1 Setting for SC1 clock divider. It could be 1~256*/ 
#define SYSCLK_CLKDIV1_SC2(x)  (((x)-1) << 16)/*!< CLKDIV1 Setting for SC2 clock divider. It could be 1~256*/ 

/*---------------------------------------------------------------------------------------------------------*/
/*  Multi-Function constant definitions.                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
//#define SYS_MFP_TYPE_Msk(bit)       (1UL << ((bit) +16))
//#define SYS_MFP_MFP_Msk(bit)        (1UL << ((bit)    ))

/* How to use below #define?
Example 1: If user want to set PA.0 as ADC0 and PA1 as ADC1 in initial function, 
           user can issue following command to achieve it.
           
           SYS->GPA_MFP  = SYS_GPA_MFP_PA0_ADC0 | SYS_GPA_MFP_PA1_ADC1;
           SYS->ALT_MFP1 = SYS_ALT_MFP1_PA0_ADC0| SYS_ALT_MFP1_PA1_ADC1;
         
Example 2: If user has set PA.0 as ADC0 in initial function, user want to set PA.1 as ADC1 now. 
           User can issue following command to achieve PA.1 setting and it will not affect PA.0's setting.
           _SYS_GPA_MFP_PA1(SYS_GPA_MFP_PA1_ADC1);
           _SYS_ALT_MFP1_PA1(SYS_ALT_MFP1_PA1_ADC1);                     
*/

//PA.0
#define SYS_GPA_MFP_PA0_GPIO    0x00000000UL            /*!< GPA_MFP PA.0 setting for GPIO  */    
#define SYS_ALT_MFP_PA0_GPIO    NULL                    /*!< No ALT_MFP setting for PA.0    */
#define SYS_ALT_MFP1_PA0_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.0 setting for GPIO */
  
#define SYS_GPA_MFP_PA0_ADC0    (1UL<<0)                /*!< GPA_MFP PA.0 setting for ADC0  */ 
#define SYS_ALT_MFP_PA0_ADC0    NULL                    /*!< No ALT_MFP setting for PA.0    */
#define SYS_ALT_MFP1_PA0_ADC0   0x00000000UL            /*!< ALT_MFP1 PA.0 setting for ADC0 */

#define SYS_GPA_MFP_PA0_SC0PWR  (1UL<<0)                /*!< GPA_MFP PA.0 setting for SC0PWR  */  
#define SYS_ALT_MFP_PA0_SC0PWR  NULL                    /*!< No ALT_MFP setting for PA.0      */
#define SYS_ALT_MFP1_PA0_SC0PWR (1UL<<2)                /*!< ALT_MFP1 PA.0 setting for SC0PWR */

#define SYS_GPA_MFP_PA0_Msk     (1UL<<0)                /*!< GPA_MFP PA.0 mask             */ 
#define SYS_ALT_MFP1_PA0_Msk    (1UL<<2)                /*!< ALT_MFP1 PA.0 mask            */            

//PA.1   
#define SYS_GPA_MFP_PA1_GPIO    0x00000000UL            /*!< GPA_MFP PA.1 setting for GPIO  */    
#define SYS_ALT_MFP_PA1_GPIO    NULL                    /*!< No ALT_MFP setting for PA.1    */
#define SYS_ALT_MFP1_PA1_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.1 setting for GPIO */
    
#define SYS_GPA_MFP_PA1_ADC1    (1UL<<1)                /*!< GPA_MFP PA.1 setting for ADC1  */    
#define SYS_ALT_MFP_PA1_ADC1    NULL                    /*!< No ALT_MFP setting for PA.1    */
#define SYS_ALT_MFP1_PA1_ADC1   0x00000000UL            /*!< ALT_MFP1 PA.1 setting for ADC1 */ 

#define SYS_GPA_MFP_PA1_SC0RST  (1UL<<1)                /*!< GPA_MFP PA.1 setting for SC0RST  */    
#define SYS_ALT_MFP_PA1_SC0RST  NULL                    /*!< No ALT_MFP setting for PA.1      */
#define SYS_ALT_MFP1_PA1_SC0RST (1UL<<3)                /*!< ALT_MFP1 PA.1 setting for SC0RST */ 
 
#define SYS_GPA_MFP_PA1_Msk     (1UL<<1)                /*!< GPA_MFP PA.1 mask             */      
#define SYS_ALT_MFP1_PA1_Msk    (1UL<<3)                /*!< ALT_MFP1 PA.1 mask             */ 

//PA.2
#define SYS_GPA_MFP_PA2_GPIO    0x00000000UL            /*!< GPA_MFP PA.2 setting for GPIO  */    
#define SYS_ALT_MFP_PA2_GPIO    NULL                    /*!< No ALT_MFP setting for PA.2    */
#define SYS_ALT_MFP1_PA2_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.2 setting for GPIO */

#define SYS_GPA_MFP_PA2_ADC2    (1UL<<2)                /*!< GPA_MFP PA.2 setting for ADC2  */    
#define SYS_ALT_MFP_PA2_ADC2    NULL                    /*!< No ALT_MFP setting for PA.2    */
#define SYS_ALT_MFP1_PA2_ADC2   0x00000000UL            /*!< ALT_MFP1 PA.2 setting for ADC2 */

#define SYS_GPA_MFP_PA2_SC0CLK  (1UL<<2)                /*!< GPA_MFP PA.2 setting for SC0CLK  */    
#define SYS_ALT_MFP_PA2_SC0CLK  NULL                    /*!< No ALT_MFP setting for PA.2      */
#define SYS_ALT_MFP1_PA2_SC0CLK (1UL<<0)                /*!< ALT_MFP1 PA.2 setting for SC0CLK */ 

#define SYS_GPA_MFP_PA2_Msk     (1UL<<2)                /*!< GPA_MFP PA.2 mask             */      
#define SYS_ALT_MFP1_PA2_Msk    (1UL<<0)                /*!< ALT_MFP1 PA.2 mask            */ 

//PA.3   
#define SYS_GPA_MFP_PA3_GPIO    0x00000000UL            /*!< GPA_MFP PA.3 setting for GPIO  */    
#define SYS_ALT_MFP_PA3_GPIO    NULL                    /*!< No ALT_MFP setting for PA.3    */
#define SYS_ALT_MFP1_PA3_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.3 setting for GPIO */

#define SYS_GPA_MFP_PA3_ADC3    (1UL<<3)                /*!< GPA_MFP PA.3 setting for ADC3  */    
#define SYS_ALT_MFP_PA3_ADC3    NULL                    /*!< No ALT_MFP setting for PA.3    */
#define SYS_ALT_MFP1_PA3_ADC3   0x00000000UL            /*!< ALT_MFP1 PA.3 setting for ADC3 */

#define SYS_GPA_MFP_PA3_SC0DAT  (1UL<<3)               /*!< GPA_MFP PA.3 setting for SC0DAT  */    
#define SYS_ALT_MFP_PA3_SC0DAT  NULL                   /*!< No ALT_MFP setting for PA.3      */
#define SYS_ALT_MFP1_PA3_SC0DAT (1UL<<1)               /*!< ALT_MFP1 PA.3 setting for SC0DAT */ 

#define SYS_GPA_MFP_PA3_Msk     (1UL<<3)                /*!< GPA_MFP PA.3 mask             */      
#define SYS_ALT_MFP1_PA3_Msk    (1UL<<1)                /*!< ALT_MFP1 PA.3 mask            */ 

//PA.4   
#define SYS_GPA_MFP_PA4_GPIO    0x00000000UL            /*!< GPA_MFP PA.4 setting for GPIO  */    
#define SYS_ALT_MFP_PA4_GPIO    NULL                    /*!< No ALT_MFP setting for PA.4    */
#define SYS_ALT_MFP1_PA4_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.4 setting for GPIO */

#define SYS_GPA_MFP_PA4_ADC4    (1UL<<4)                /*!< GPA_MFP PA.4 setting for ADC4  */    
#define SYS_ALT_MFP_PA4_ADC4    NULL                    /*!< No ALT_MFP setting for PA.4    */
#define SYS_ALT_MFP1_PA4_ADC4   0x00000000UL            /*!< ALT_MFP1 PA.4 setting for ADC4 */

#define SYS_GPA_MFP_PA4_SC1PWR  (1UL<<4)               /*!< GPA_MFP PA.4 setting for SC1PWR  */    
#define SYS_ALT_MFP_PA4_SC1PWR  NULL                   /*!< No ALT_MFP setting for PA.4      */
#define SYS_ALT_MFP1_PA4_SC1PWR (1UL<<7)               /*!< ALT_MFP1 PA.4 setting for SC1PWR */ 

#define SYS_GPA_MFP_PA4_Msk     (1UL<<4)                /*!< GPA_MFP PA.4 mask             */      
#define SYS_ALT_MFP1_PA4_Msk    (1UL<<7)                /*!< ALT_MFP1 PA.4 mask            */ 

//PA.5   
#define SYS_GPA_MFP_PA5_GPIO    0x00000000UL            /*!< GPA_MFP PA.5 setting for GPIO  */    
#define SYS_ALT_MFP_PA5_GPIO    NULL                    /*!< No ALT_MFP setting for PA.5    */
#define SYS_ALT_MFP1_PA5_GPIO   0x00000000UL            /*!< ALT_MFP1 PA.5 setting for GPIO */

#define SYS_GPA_MFP_PA5_ADC5    (1UL<<5)                /*!< GPA_MFP PA.5 setting for ADC5  */     
#define SYS_ALT_MFP_PA5_ADC5    NULL                    /*!< No ALT_MFP setting for PA.5    */
#define SYS_ALT_MFP1_PA5_ADC5   0x00000000UL            /*!< ALT_MFP1 PA.5 setting for ADC5 */

#define SYS_GPA_MFP_PA5_SC1RST  (1UL<<5)               /*!< GPA_MFP PA.5 setting for SC1RST  */    
#define SYS_ALT_MFP_PA5_SC1RST  NULL                   /*!< No ALT_MFP setting for PA.5      */
#define SYS_ALT_MFP1_PA5_SC1RST (1UL<<8)               /*!< ALT_MFP1 PA.5 setting for SC1RST */ 

#define SYS_GPA_MFP_PA5_Msk     (1UL<<5)                /*!< GPA_MFP PA.5 mask             */      
#define SYS_ALT_MFP1_PA5_Msk    (1UL<<8)                /*!< ALT_MFP1 PA.5 mask            */ 

//PA.6   
#define SYS_GPA_MFP_PA6_GPIO    0x00000000UL    /*!< GPA_MFP PA.6 setting for GPIO  */    
#define SYS_ALT_MFP_PA6_GPIO    NULL            /*!< No ALT_MFP setting for PA.6    */
#define SYS_ALT_MFP1_PA6_GPIO   0x00000000UL    /*!< ALT_MFP1 PA.6 setting for GPIO */

#define SYS_GPA_MFP_PA6_ADC6    (1UL<<6)        /*!< GPA_MFP PA.6 setting for ADC6  */     
#define SYS_ALT_MFP_PA6_ADC6    NULL            /*!< No ALT_MFP setting for PA.6    */
#define SYS_ALT_MFP1_PA6_ADC6   0x00000000UL    /*!< ALT_MFP1 PA.6 setting for ADC6 */

#define SYS_GPA_MFP_PA6_SC1CLK  (1UL<<6)        /*!< GPA_MFP PA.6 setting for SC1CLK  */    
#define SYS_ALT_MFP_PA6_SC1CLK  NULL            /*!< No ALT_MFP setting for PA.6      */
#define SYS_ALT_MFP1_PA6_SC1CLK (1UL<<5)        /*!< ALT_MFP1 PA.6 setting for SC1CLK */ 

#define SYS_GPA_MFP_PA6_Msk     (1UL<<6)        /*!< GPA_MFP PA.6 mask             */      
#define SYS_ALT_MFP1_PA6_Msk    (1UL<<5)        /*!< ALT_MFP1 PA.6 mask            */ 

//PA.7   
#define SYS_GPA_MFP_PA7_GPIO    0x00000000UL        /*!< GPA_MFP PA.7 setting for GPIO  */    
#define SYS_ALT_MFP_PA7_GPIO    0x00000000UL        /*!< ALT_MFP PA.7 setting for GPIO  */ 
#define SYS_ALT_MFP1_PA7_GPIO   0x00000000UL        /*!< ALT_MFP1 PA.7 setting for GPIO */

#define SYS_GPA_MFP_PA7_ADC7    (1UL<<7)            /*!< GPA_MFP PA.7 setting for ADC7  */    
#define SYS_ALT_MFP_PA7_ADC7    0x00000000UL        /*!< ALT_MFP PA.7 setting for ADC7  */ 
#define SYS_ALT_MFP1_PA7_ADC7   0x00000000UL        /*!< ALT_MFP1 PA.7 setting for ADC7 */

#define SYS_GPA_MFP_PA7_SPISS21     (1UL<<7)        /*!< GPA_MFP PA.7 setting for SPISS21  */    
#define SYS_ALT_MFP_PA7_SPISS21     (1UL<<2)        /*!< ALT_MFP PA.7 setting for SPISS21  */ 
#define SYS_ALT_MFP1_PA7_SPISS21    0x00000000UL    /*!< ALT_MFP1 PA.7 setting for SPISS21 */

#define SYS_GPA_MFP_PA7_SC1DAT   (1UL<<7)            /*!< GPA_MFP PA.7 setting for SC1DAT  */    
#define SYS_ALT_MFP_PA7_SC1DAT   0x00000000UL        /*!< ALT_MFP PA.7 setting for SC1DAT  */ 
#define SYS_ALT_MFP1_PA7_SC1DAT  (1UL<<6)            /*!< ALT_MFP1 PA.7 setting for SC1DAT */ 

#define SYS_GPA_MFP_PA7_Msk     (1UL<<7)                /*!< GPA_MFP PA.7 mask             */      
#define SYS_ALT_MFP_PA7_Msk     (1UL<<2)                /*!< ALT_MFP PA.7 mask             */ 
#define SYS_ALT_MFP1_PA7_Msk    (1UL<<6)                /*!< ALT_MFP1 PA.7 mask            */ 

//PA.8   
#define SYS_GPA_MFP_PA8_GPIO    0x00000000UL    /*!< GPA_MFP PA.8 setting for GPIO */    
#define SYS_ALT_MFP_PA8_GPIO    NULL            /*!< No ALT_MFP setting for PA.8   */
#define SYS_ALT_MFP1_PA8_GPIO   NULL            /*!< No ALT_MFP1 setting for PA.8  */

#define SYS_GPA_MFP_PA8_SDA0    (1UL<<8)        /*!< GPA_MFP PA.8 setting for SDA0 */    
#define SYS_ALT_MFP_PA8_SDA0    NULL            /*!< No ALT_MFP setting for PA.8   */
#define SYS_ALT_MFP_PA8_SDA0    NULL            /*!< No ALT_MFP1 setting for PA.8  */

#define SYS_GPA_MFP_PA8_Msk     (1UL<<8)        /*!< GPA_MFP PA.8 mask             */      

//PA.9   
#define SYS_GPA_MFP_PA9_GPIO    0x00000000UL    /*!< GPA_MFP PA.9 setting for GPIO */    
#define SYS_ALT_MFP_PA9_GPIO    NULL            /*!< No ALT_MFP setting for PA.9   */
#define SYS_ALT_MFP1_PA9_GPIO   NULL            /*!< No ALT_MFP1 setting for PA.9  */

#define SYS_GPA_MFP_PA9_SCL0    (1UL<<9)        /*!< GPA_MFP PA.9 setting for SCL0 */    
#define SYS_ALT_MFP_PA9_SCL0    NULL            /*!< No ALT_MFP setting for PA.9   */
#define SYS_ALT_MFP1_PA9_SCL0   NULL            /*!< No ALT_MFP1 setting for PA.9  */

#define SYS_GPA_MFP_PA9_Msk     (1UL<<9)        /*!< GPA_MFP PA.9 mask             */ 

//PA.10   
#define SYS_GPA_MFP_PA10_GPIO    0x00000000UL       /*!< GPA_MFP PA.10 setting for GPIO */    
#define SYS_ALT_MFP_PA10_GPIO    0x00000000UL       /*!< ALT_MFP PA.10 setting for GPIO */
#define SYS_ALT_MFP1_PA10_GPIO   NULL               /*!< No ALT_MFP1 setting for PA.10  */
 
#define SYS_GPA_MFP_PA10_SDA1    (1UL<<10)          /*!< GPA_MFP PA.10 setting for SDA1 */    
#define SYS_ALT_MFP_PA10_SDA1    0x00000000UL       /*!< ALT_MFP PA.10 setting for SDA1 */ 
#define SYS_ALT_MFP1_PA10_SDA1   NULL               /*!< No ALT_MFP1 setting for PA.10  */

#define SYS_GPA_MFP_PA10_CANTX1  (1UL<<10)          /*!< GPA_MFP PA.10 setting for CANTX1 */    
#define SYS_ALT_MFP_PA10_CANTX1  (1UL<<28)          /*!< ALT_MFP PA.10 setting for CANTX1 */ 
#define SYS_ALT_MFP1_PA10_CANTX1 NULL               /*!< No ALT_MFP1 setting for PA.10    */

#define SYS_GPA_MFP_PA10_Msk     (1UL<<10)          /*!< GPA_MFP PA.10 mask             */      
#define SYS_ALT_MFP_PA10_Msk     (1UL<<28)          /*!< ALT_MFP PA.10 mask             */ 


//PA.11   
#define SYS_GPA_MFP_PA11_GPIO    0x00000000UL           /*!< GPA_MFP PA.11 setting for GPIO */    
#define SYS_ALT_MFP_PA11_GPIO    0x00000000UL           /*!< ALT_MFP PA.11 setting for GPIO */
#define SYS_ALT_MFP1_PA11_GPIO   NULL                   /*!< No ALT_MFP1 setting for PA.11  */

#define SYS_GPA_MFP_PA11_SCL1    (1UL<<11)              /*!< GPA_MFP PA.11 setting for SCL1 */    
#define SYS_ALT_MFP_PA11_SCL1    0x00000000UL           /*!< ALT_MFP PA.11 setting for SCL1 */ 
#define SYS_ALT_MFP1_PA11_SCL1   NULL                   /*!< No ALT_MFP1 setting for PA.11  */

#define SYS_GPA_MFP_PA11_CANRX1  (1UL<<11)              /*!< GPA_MFP PA.11 setting for CANRX1 */    
#define SYS_ALT_MFP_PA11_CANRX1  (1UL<<28)              /*!< ALT_MFP PA.11 setting for CANRX1 */ 
#define SYS_ALT_MFP1_PA11_CANRX1 NULL                   /*!< No ALT_MFP1 setting for PA.11    */

#define SYS_GPA_MFP_PA11_Msk     (1UL<<11)              /*!< GPA_MFP PA.11 mask             */      
#define SYS_ALT_MFP_PA11_Msk     (1UL<<28)              /*!< ALT_MFP PA.11 mask             */ 


//PA.12   
#define SYS_GPA_MFP_PA12_GPIO    0x00000000UL           /*!< GPA_MFP PA.12 setting for GPIO   */    
#define SYS_ALT_MFP_PA12_GPIO    NULL                   /*!< No ALT_MFP setting for PA.12     */
#define SYS_ALT_MFP1_PA12_GPIO   0x00000000UL           /*!< ALT_MFP1 PA.12 setting for GPIO  */
    
#define SYS_GPA_MFP_PA12_PWM0    (1UL<<12)              /*!< GPA_MFP PA.12 setting for PWM0  */    
#define SYS_ALT_MFP_PA12_PWM0    NULL                   /*!< No ALT_MFP setting for PA.12    */    
#define SYS_ALT_MFP1_PA12_PWM0   0x00000000UL           /*!< ALT_MFP1 PA.12 setting for PWM0 */ 

#define SYS_GPA_MFP_PA12_SC2DAT  (1UL<<12)              /*!< GPA_MFP PA.12 setting for SC2DAT  */    
#define SYS_ALT_MFP_PA12_SC2DAT  NULL                   /*!< No ALT_MFP setting for PA.12      */
#define SYS_ALT_MFP1_PA12_SC2DAT (1UL<<11)              /*!< ALT_MFP1 PA.12 setting for SC2DAT */ 
 
#define SYS_GPA_MFP_PA12_Msk     (1UL<<12)              /*!< GPA_MFP PA.12 mask             */      
#define SYS_ALT_MFP1_PA12_Msk    (1UL<<11)              /*!< ALT_MFP1 PA.12 mask             */ 

//PA.13   
#define SYS_GPA_MFP_PA13_GPIO    0x00000000UL           /*!< GPA_MFP PA.13 setting for GPIO  */    
#define SYS_ALT_MFP_PA13_GPIO    NULL                   /*!< No ALT_MFP setting for PA.13    */
#define SYS_ALT_MFP1_PA13_GPIO   0x00000000UL           /*!< ALT_MFP1 PA.13 setting for GPIO */
    
#define SYS_GPA_MFP_PA13_PWM1    (1UL<<13)              /*!< GPA_MFP PA.13 setting for PWM1  */    
#define SYS_ALT_MFP_PA13_PWM1    NULL                   /*!< No ALT_MFP setting for PA.13    */
#define SYS_ALT_MFP1_PA13_PWM1   0x00000000UL           /*!< ALT_MFP1 PA.13 setting for PWM1 */ 

#define SYS_GPA_MFP_PA13_SC2CLK  (1UL<<13)              /*!< GPA_MFP PA.13 setting for SC2CLK  */    
#define SYS_ALT_MFP_PA13_SC2CLK  NULL                   /*!< No ALT_MFP setting for PA.13      */
#define SYS_ALT_MFP1_PA13_SC2CLK (1UL<<10)              /*!< ALT_MFP1 PA.13 setting for SC2CLK */  
 
#define SYS_GPA_MFP_PA13_Msk     (1UL<<13)              /*!< GPA_MFP PA.13 mask             */      
#define SYS_ALT_MFP1_PA13_Msk    (1UL<<10)              /*!< ALT_MFP1 PA.13 mask             */ 

//PA.14   
#define SYS_GPA_MFP_PA14_GPIO    0x00000000UL           /*!< GPA_MFP PA.14 setting for GPIO  */    
#define SYS_ALT_MFP_PA14_GPIO    NULL                   /*!< No ALT_MFP setting for PA.14    */
#define SYS_ALT_MFP1_PA14_GPIO   0x00000000UL           /*!< ALT_MFP1 PA.14 setting for GPIO */
    
#define SYS_GPA_MFP_PA14_PWM2    (1UL<<14)              /*!< GPA_MFP PA.14 setting for PWM2  */    
#define SYS_ALT_MFP_PA14_PWM2    NULL                   /*!< No ALT_MFP setting for PA.14    */
#define SYS_ALT_MFP1_PA14_PWM2   0x00000000UL           /*!< ALT_MFP1 PA.14 setting for PWM2 */ 

#define SYS_GPA_MFP_PA14_SC2RST  (1UL<<14)              /*!< GPA_MFP PA.14 setting for SC2RST  */    
#define SYS_ALT_MFP_PA14_SC2RST  NULL                   /*!< No ALT_MFP setting for PA.14      */
#define SYS_ALT_MFP1_PA14_SC2RST (1UL<<13)              /*!< ALT_MFP1 PA.14 setting for SC2RST */  
 
#define SYS_GPA_MFP_PA14_Msk     (1UL<<14)              /*!< GPA_MFP PA.14 mask             */      
#define SYS_ALT_MFP1_PA14_Msk    (1UL<<13)              /*!< ALT_MFP1 PA.14 mask             */ 

//PA.15   
#define SYS_GPA_MFP_PA15_GPIO    0x00000000UL   /*!< GPA_MFP PA.15 setting for GPIO */    
#define SYS_ALT_MFP_PA15_GPIO    0x00000000UL   /*!< ALT_MFP PA.15 setting for GPIO */
#define SYS_ALT_MFP1_PA15_GPIO   0x00000000UL   /*!< ALT_MFP1 PA.15 setting for GPIO */
    
#define SYS_GPA_MFP_PA15_PWM3    (1UL<<15)      /*!< GPA_MFP PA.15 setting for PWM3 */    
#define SYS_ALT_MFP_PA15_PWM3    0x00000000UL   /*!< ALT_MFP PA.15 setting for PWM3 */ 
#define SYS_ALT_MFP1_PA15_PWM3   0x00000000UL   /*!< ALT_MFP1 PA.15 setting for PWM3 */ 

#define SYS_GPA_MFP_PA15_I2SMCLK  (1UL<<15)     /*!< GPA_MFP PA.15 setting for I2SMCLK  */    
#define SYS_ALT_MFP_PA15_I2SMCLK  (1UL<<9)      /*!< ALT_MFP PA.15 setting for I2SMCLK  */  
#define SYS_ALT_MFP1_PA15_I2SMCLK 0x00000000UL  /*!< ALT_MFP1 PA.15 setting for I2SMCLK  */ 

#define SYS_GPA_MFP_PA15_SC2PWR  (1UL<<15)      /*!< GPA_MFP PA.15 setting for SC2PWR  */    
#define SYS_ALT_MFP_PA15_SC2PWR  0x00000000UL   /*!< ALT_MFP PA.15 setting for SC2PWR  */  
#define SYS_ALT_MFP1_PA15_SC2PWR (1UL<<12)      /*!< ALT_MFP1 PA.15 setting for SC2PWR  */ 
 
#define SYS_GPA_MFP_PA15_Msk     (1UL<<15)      /*!< GPA_MFP PA.15 mask             */      
#define SYS_ALT_MFP_PA15_Msk     (1UL<<9)       /*!< ALT_MFP PA.15 mask             */ 
#define SYS_ALT_MFP1_PA15_Msk    (1UL<<12)      /*!< ALT_MFP1 PA.15 mask             */ 

//PB.0
#define SYS_GPB_MFP_PB0_GPIO     0x00000000UL    /*!< GPA_MFP PB.0 setting for GPIO */      
#define SYS_ALT_MFP_PB0_GPIO     NULL            /*!< No ALT_MFP setting for PB.0   */
#define SYS_ALT_MFP1_PB0_GPIO    NULL            /*!< No ALT_MFP1 setting for PB.0  */

#define SYS_GPB_MFP_PB0_RXD0     (1UL<<0)        /*!< GPA_MFP PB.0 setting for RXD0 */  
#define SYS_ALT_MFP_PB0_RXD0     NULL            /*!< No ALT_MFP setting for PB.0   */
#define SYS_ALT_MFP1_PB0_RXD0    NULL            /*!< No ALT_MFP1 setting for PB.0  */

#define SYS_GPB_MFP_PB0_Msk      (1UL<<0)        /*!< GPA_MFP PB.0 mask             */   

//PB.1
#define SYS_GPB_MFP_PB1_GPIO    0x00000000UL    /*!< GPA_MFP PB.1 setting for GPIO */      
#define SYS_ALT_MFP_PB1_GPIO    NULL            /*!< No ALT_MFP setting for PB.1   */
#define SYS_ALT_MFP1_PB1_GPIO   NULL            /*!< No ALT_MFP1 setting for PB.1  */

#define SYS_GPB_MFP_PB1_TXD0    (1UL<<1)            /*!< GPA_MFP PB.1 setting for TXD0 */  
#define SYS_ALT_MFP_PB1_TXD0    NULL                /*!< No ALT_MFP setting for PB.1   */
#define SYS_ALT_MFP1_PB1_TXD0   NULL                /*!< No ALT_MFP1 setting for PB.1  */

#define SYS_GPB_MFP_PB1_Msk     (1UL<<1)        /*!< GPA_MFP PB.1 mask             */  

//PB.2   
#define SYS_GPB_MFP_PB2_GPIO    0x00000000UL            /*!< GPB_MFP PB.2 setting for GPIO */    
#define SYS_ALT_MFP_PB2_GPIO    0x00000000UL            /*!< ALT_MFP PB.2 setting for GPIO */
#define SYS_ALT_MFP1_PB2_GPIO   NULL                    /*!< No ALT_MFP1 setting for PB.2  */

#define SYS_GPB_MFP_PB2_RTS0    (1UL<<2)                /*!< GPB_MFP PB.2 setting for RTS0 */    
#define SYS_ALT_MFP_PB2_RTS0    0x00000000UL            /*!< ALT_MFP PB.2 setting for RTS0 */ 
#define SYS_ALT_MFP1_PB2_RTS0   NULL                    /*!< No ALT_MFP1 setting for PB.2  */

#define SYS_GPB_MFP_PB2_T2EX    (1UL<<2)                /*!< GPB_MFP PB.2 setting for T2EX */    
#define SYS_ALT_MFP_PB2_T2EX    (1UL<<26)               /*!< ALT_MFP PB.2 setting for T2EX */ 
#define SYS_ALT_MFP1_PB2_T2EX   NULL                    /*!< No ALT_MFP1 setting for PB.2  */

#define SYS_GPB_MFP_PB2_CPO0    (1UL<<2)                /*!< GPB_MFP PB.2 setting for CPO0 */    
#define SYS_ALT_MFP_PB2_CPO0    (1UL<<30)               /*!< ALT_MFP PB.2 setting for CPO0 */ 
#define SYS_ALT_MFP1_PB2_CPO0   NULL                    /*!< No ALT_MFP1 setting for PB.2  */

#define SYS_GPB_MFP_PB2_Msk     (1UL<<2)                /*!< GPB_MFP PB.2 mask */      
#define SYS_ALT_MFP_PB2_Msk     ((1UL<<30)|(1UL<<26))   /*!< ALT_MFP PB.2 mask */ 

//PB.3   
#define SYS_GPB_MFP_PB3_GPIO    0x00000000UL    /*!< GPB_MFP PB.3 setting for GPIO */    
#define SYS_ALT_MFP_PB3_GPIO    0x00000000UL    /*!< ALT_MFP PB.3 setting for GPIO */
#define SYS_ALT_MFP1_PB3_GPIO   0x00000000UL    /*!< ALT_MFP1 PB.3 setting for GPIO */
    
#define SYS_GPB_MFP_PB3_CTS0    (1UL<<3)        /*!< GPB_MFP PB.3 setting for CTS0 */    
#define SYS_ALT_MFP_PB3_CTS0    0x00000000UL    /*!< ALT_MFP PB.3 setting for CTS0 */ 
#define SYS_ALT_MFP1_PB3_CTS0   0x00000000UL    /*!< ALT_MFP1 PB.3 setting for CTS0 */ 

#define SYS_GPB_MFP_PB3_T3EX    (1UL<<3)        /*!< GPB_MFP PB.3 setting for T3EX */    
#define SYS_ALT_MFP_PB3_T3EX    (1UL<<27)       /*!< ALT_MFP PB.3 setting for T3EX */ 
#define SYS_ALT_MFP1_PB3_T3EX   0x00000000UL    /*!< ALT_MFP1 PB.3 setting for T3EX */ 

#define SYS_GPB_MFP_PB3_SC2CD   (1UL<<3)        /*!< GPB_MFP PB.3 setting for SC2CD */    
#define SYS_ALT_MFP_PB3_SC2CD   0x00000000UL    /*!< ALT_MFP PB.3 setting for SC2CD */ 
#define SYS_ALT_MFP1_PB3_SC2CD  (1UL<<14)       /*!< ALT_MFP1 PB.3 setting for SC2CD */ 
 
#define SYS_GPB_MFP_PB3_Msk     (1UL<<3)        /*!< GPB_MFP PB.3 mask */      
#define SYS_ALT_MFP_PB3_Msk     (1UL<<27)       /*!< ALT_MFP PB.3 mask */ 
#define SYS_ALT_MFP1_PB3_Msk    (1UL<<14)       /*!< ALT_MFP1 PB.3 mask */ 

//PB.4
#define SYS_GPB_MFP_PB4_GPIO     0x00000000UL    /*!< GPA_MFP PB.4 setting for GPIO */      
#define SYS_ALT_MFP_PB4_GPIO     NULL            /*!< No ALT_MFP setting for PB.4   */
#define SYS_ALT_MFP1_PB4_GPIO    NULL            /*!< No ALT_MFP1 setting for PB.4  */   

#define SYS_GPB_MFP_PB4_RXD1     (1UL<<4)        /*!< GPA_MFP PB.4 setting for RXD1 */  
#define SYS_ALT_MFP_PB4_RXD1     NULL            /*!< No ALT_MFP setting for PB.4   */
#define SYS_ALT_MFP1_PB4_RXD1    NULL            /*!< No ALT_MFP1 setting for PB.4  */

#define SYS_GPB_MFP_PB4_Msk         (1UL<<4)        /*!< GPA_MFP PB.4 mask */ 

//PB.5
#define SYS_GPB_MFP_PB5_GPIO        0x00000000UL    /*!< GPA_MFP PB.5 setting for GPIO */      
#define SYS_ALT_MFP_PB5_GPIO        NULL            /*!< No ALT_MFP setting for PB.5   */ 
#define SYS_ALT_MFP1_PB5_GPIO       NULL            /*!< No ALT_MFP1 setting for PB.5  */ 

#define SYS_GPB_MFP_PB5_TXD1       (1UL<<5)         /*!< GPA_MFP PB.5 setting for TXD1 */
#define SYS_ALT_MFP_PB5_TXD1       NULL             /*!< No ALT_MFP setting for PB.5   */
#define SYS_ALT_MFP1_PB5_TXD1      NULL             /*!< No ALT_MFP1 setting for PB.5  */

#define SYS_GPB_MFP_PB5_Msk         (1UL<<5)        /*!< GPA_MFP PB.5 mask */ 

//PB.6   
#define SYS_GPB_MFP_PB6_GPIO    0x00000000UL    /*!< GPB_MFP PB.6 setting for GPIO */        
#define SYS_GPB_MFP_PB6_RTS1    (1UL<<6)        /*!< GPB_MFP PB.6 setting for RTS1 */     
#define SYS_GPB_MFP_PB6_Msk     (1UL<<6)        /*!< GPB_MFP PB.6 mask */      

//PB.7   
#define SYS_GPB_MFP_PB7_GPIO    0x00000000UL    /*!< GPB_MFP PB.7 setting for GPIO */      
#define SYS_GPB_MFP_PB7_CTS1    (1UL<<7)        /*!< GPB_MFP PB.7 setting for CTS1 */     
#define SYS_GPB_MFP_PB7_Msk     (1UL<<7)        /*!< GPB_MFP PB.7 mask */

//PB.8
#define SYS_GPB_MFP_PB8_GPIO    0x00000000UL    /*!< GPA_MFP PB.8 setting for GPIO */   
#define SYS_ALT_MFP_PB8_GPIO    0x00000000UL    /*!< ALT_MFP PB.8 setting for GPIO */
#define SYS_ALT_MFP1_PB8_GPIO   NULL            /*!< No ALT_MFP1 setting for PB.8  */

#define SYS_GPB_MFP_PB8_TM0     (1UL<<8)        /*!< GPA_MFP PB.8 setting for TM0 */  
#define SYS_ALT_MFP_PB8_TM0     0x00000000UL    /*!< ALT_MFP PB.8 setting for TM0 */
#define SYS_ALT_MFP1_PB8_TM0    NULL            /*!< No ALT_MFP1 setting for PB.8  */

#define SYS_GPB_MFP_PB8_CLKO    (1UL<<8)        /*!< GPA_MFP PB.8 setting for CLKO */  
#define SYS_ALT_MFP_PB8_CLKO    (1UL<<29)       /*!< ALT_MFP PB.8 setting for CLKO */
#define SYS_ALT_MFP1_PB8_CLKO   NULL            /*!< No ALT_MFP1 setting for PB.8  */

#define SYS_GPB_MFP_PB8_Msk     (1UL<<8)        /*!< GPA_MFP PB.8 mask */ 
#define SYS_ALT_MFP_PB8_Msk     (1UL<<29)       /*!< ALT_MFP PB.8 mask */ 

//PB.9   
#define SYS_GPB_MFP_PB9_GPIO    0x00000000UL    /*!< GPB_MFP PB.9 setting for GPIO */    
#define SYS_ALT_MFP_PB9_GPIO    0x00000000UL    /*!< ALT_MFP PB.9 setting for GPIO */
#define SYS_ALT_MFP1_PB9_GPIO   NULL            /*!< No ALT_MFP1 setting for PB.9  */
    
#define SYS_GPB_MFP_PB9_TM1     (1UL<<9)        /*!< GPB_MFP PB.9 setting for TM1 */    
#define SYS_ALT_MFP_PB9_TM1     0x00000000UL    /*!< ALT_MFP PB.9 setting for TM1 */ 
#define SYS_ALT_MFP1_PB9_TM1    NULL            /*!< No ALT_MFP1 setting for PB.9 */

#define SYS_GPB_MFP_PB9_SPISS11  (1UL<<9)        /*!< GPB_MFP PB.9 setting for SPISS11  */    
#define SYS_ALT_MFP_PB9_SPISS11  (1UL<<1)        /*!< ALT_MFP PB.9 setting for SPISS11  */ 
#define SYS_ALT_MFP1_PB9_SPISS11 NULL            /*!< No ALT_MFP1 setting for PB.9  */

#define SYS_GPB_MFP_PB9_Msk     (1UL<<9)        /*!< GPB_MFP PB.9 mask */      
#define SYS_ALT_MFP_PB9_Msk     (1UL<<1)        /*!< ALT_MFP PB.9 mask */ 


//PB.10   
#define SYS_GPB_MFP_PB10_GPIO    0x00000000UL       /*!< GPB_MFP PB.10 setting for GPIO */    
#define SYS_ALT_MFP_PB10_GPIO    0x00000000UL       /*!< ALT_MFP PB.10 setting for GPIO */
#define SYS_ALT_MFP1_PB10_GPIO   NULL               /*!< No ALT_MFP1 setting for PB.10  */

#define SYS_GPB_MFP_PB10_TM2     (1UL<<10)          /*!< GPB_MFP PB.10 setting for TM2 */    
#define SYS_ALT_MFP_PB10_TM2     0x00000000UL       /*!< ALT_MFP PB.10 setting for TM2 */ 
#define SYS_ALT_MFP1_PB10_TM2    NULL               /*!< No ALT_MFP1 setting for PB.10 */

#define SYS_GPB_MFP_PB10_SPISS01  (1UL<<10)         /*!< GPB_MFP PB.10 setting for SPISS01 */    
#define SYS_ALT_MFP_PB10_SPISS01  (1UL<<0)          /*!< ALT_MFP PB.10 setting for SPISS01 */ 
#define SYS_ALT_MFP1_PB10_SPISS01 NULL              /*!< No ALT_MFP1 setting for PB.10     */
    
#define SYS_GPB_MFP_PB10_Msk    (1UL<<10)           /*!< GPB_MFP PB.10 mask */      
#define SYS_ALT_MFP_PB10_Msk    (1UL<<0)            /*!< ALT_MFP PB.10 mask */ 

//PB.11   
#define SYS_GPB_MFP_PB11_GPIO   0x00000000UL       /*!< GPB_MFP PB.11 setting for GPIO */    
#define SYS_ALT_MFP_PB11_GPIO   0x00000000UL       /*!< ALT_MFP PB.11 setting for GPIO */
#define SYS_ALT_MFP1_PB11_GPIO  NULL               /*!< No ALT_MFP1 setting for PB.11  */

#define SYS_GPB_MFP_PB11_TM3    (1UL<<11)          /*!< GPB_MFP PB.11 setting for TM3 */    
#define SYS_ALT_MFP_PB11_TM3    0x00000000UL       /*!< ALT_MFP PB.11 setting for TM3 */ 
#define SYS_ALT_MFP1_PB11_TM3   NULL               /*!< No ALT_MFP1 setting for PB.11  */

#define SYS_GPB_MFP_PB11_PWM4   (1UL<<11)           /*!< GPB_MFP PB.11 setting for PWM4  */    
#define SYS_ALT_MFP_PB11_PWM4   (1UL<<4)            /*!< ALT_MFP PB.11 setting for PWM4  */ 
#define SYS_ALT_MFP1_PB11_PWM4  NULL                /*!< No ALT_MFP1 setting for PB.11  */

#define SYS_GPB_MFP_PB11_Msk    (1UL<<11)           /*!< GPB_MFP PB.11 mask */      
#define SYS_ALT_MFP_PB11_Msk    (1UL<<4)            /*!< ALT_MFP PB.11 mask */ 

//PB.12 is reserved

//PB.13   
#define SYS_GPB_MFP_PB13_GPIO   0x00000000UL        /*!< GPB_MFP PB.13 setting for GPIO */      
#define SYS_ALT_MFP_PB13_GPIO   NULL                /*!< No ALT_MFP setting for PB.13   */
#define SYS_ALT_MFP1_PB13_GPIO  NULL                /*!< No ALT_MFP1 setting for PB.13  */

#define SYS_GPB_MFP_PB13_CPO1   (1UL<<13)           /*!< GPB_MFP PB.13 setting for CPO1 */ 
#define SYS_ALT_MFP_PB13_CPO1   NULL                /*!< No ALT_MFP setting for PB.13   */
#define SYS_ALT_MFP1_PB13_CPO1  NULL                /*!< No ALT_MFP1 setting for PB.13  */

#define SYS_GPB_MFP_PB13_Msk    (1UL<<13)           /*!< GPB_MFP PB.13 mask */      

//PB.14   
#define SYS_GPB_MFP_PB14_GPIO   0x00000000UL        /*!< GPB_MFP PB.14 setting for GPIO */    
#define SYS_ALT_MFP_PB14_GPIO   0x00000000UL        /*!< ALT_MFP PB.14 setting for GPIO */
#define SYS_ALT_MFP1_PB14_GPIO  NULL                /*!< No ALT_MFP1 setting for PB.14  */

#define SYS_GPB_MFP_PB14_INT0   (1UL<<14)           /*!< GPB_MFP PB.14 setting for INT0 */    
#define SYS_ALT_MFP_PB14_INT0   0x00000000UL        /*!< ALT_MFP PB.14 setting for INT0 */ 
#define SYS_ALT_MFP1_PB14_INT0  NULL                /*!< No ALT_MFP1 setting for PB.14  */

#define SYS_GPB_MFP_PB14_SPISS31    (1UL<<14)       /*!< GPB_MFP PB.14 setting for SPISS31 */    
#define SYS_ALT_MFP_PB14_SPISS31    (1UL<<3)        /*!< ALT_MFP PB.14 setting for SPISS31 */ 
#define SYS_ALT_MFP1_PB14_SPISS31   NULL            /*!< No ALT_MFP1 setting for PB.14     */

#define SYS_GPB_MFP_PB14_Msk    (1UL<<14)           /*!< GPB_MFP PB.14 mask */      
#define SYS_ALT_MFP_PB14_Msk    (1UL<<3)            /*!< ALT_MFP PB.14 mask */ 
#define SYS_ALT_MFP1_PB14_Msk   NULL

//PB.15   
#define SYS_GPB_MFP_PB15_GPIO    0x00000000UL   /*!< GPB_MFP PB.15 setting for GPIO */    
#define SYS_ALT_MFP_PB15_GPIO    0x00000000UL   /*!< ALT_MFP PB.15 setting for GPIO */
#define SYS_ALT_MFP1_PB15_GPIO   NULL

#define SYS_GPB_MFP_PB15_INT1    (1UL<<15)      /*!< GPB_MFP PB.15 setting for INT1 */    
#define SYS_ALT_MFP_PB15_INT1    0x00000000UL   /*!< ALT_MFP PB.15 setting for INT1 */ 
#define SYS_ALT_MFP1_PB15_INT1   NULL

#define SYS_GPB_MFP_PB15_T0EX   (1UL<<15)       /*!< GPB_MFP PB.15 setting for T0EX  */    
#define SYS_ALT_MFP_PB15_T0EX   (1UL<<24)       /*!< ALT_MFP PB.15 setting for T0EX  */ 
#define SYS_ALT_MFP1_PB15_T0EX  NULL

#define SYS_GPB_MFP_PB15_Msk    (1UL<<15)       /*!< GPB_MFP PB.15 mask */      
#define SYS_ALT_MFP_PB15_Msk    (1UL<<24)       /*!< ALT_MFP PB.15 mask */ 

//PC.0   
#define SYS_GPC_MFP_PC0_GPIO        0x00000000UL   /*!< GPC_MFP PC.0 setting for GPIO */    
#define SYS_ALT_MFP_PC0_GPIO        0x00000000UL   /*!< ALT_MFP PC.0 setting for GPIO */
#define SYS_ALT_MFP1_PC0_GPIO       NULL

#define SYS_GPC_MFP_PC0_SPISS00     (1UL<<0)       /*!< GPC_MFP PC.0 setting for SPISS00 */    
#define SYS_ALT_MFP_PC0_SPISS00     0x00000000UL   /*!< ALT_MFP PC.0 setting for SPISS00 */ 
#define SYS_ALT_MFP1_PC0_SPISS00    NULL

#define SYS_GPC_MFP_PC0_I2SLRCLK    (1UL<<0)       /*!< GPC_MFP PC.0 setting for I2SLRCLK  */    
#define SYS_ALT_MFP_PC0_I2SLRCLK    (1UL<<5)       /*!< ALT_MFP PC.0 setting for I2SLRCLK  */ 
#define SYS_ALT_MFP1_PC0_I2SLRCLK   NULL

#define SYS_GPC_MFP_PC0_Msk         (1UL<<0)       /*!< GPC_MFP PC.0 mask */      
#define SYS_ALT_MFP_PC0_Msk         (1UL<<5)       /*!< ALT_MFP PC.0 mask */ 

//PC.1   
#define SYS_GPC_MFP_PC1_GPIO        0x00000000UL   /*!< GPC_MFP PC.1 setting for GPIO */    
#define SYS_ALT_MFP_PC1_GPIO        0x00000000UL   /*!< ALT_MFP PC.1 setting for GPIO */
#define SYS_ALT_MFP1_PC1_GPIO       NULL

#define SYS_GPC_MFP_PC1_SPICLK0     (1UL<<1)       /*!< GPC_MFP PC.1 setting for SPICLK0 */    
#define SYS_ALT_MFP_PC1_SPICLK0     0x00000000UL   /*!< ALT_MFP PC.1 setting for SPICLK0 */ 
#define SYS_ALT_MFP1_PC1_SPICLK0    NULL

#define SYS_GPC_MFP_PC1_I2SBCLK     (1UL<<1)       /*!< GPC_MFP PC.1 setting for I2SBCLK  */    
#define SYS_ALT_MFP_PC1_I2SBCLK     (1UL<<6)       /*!< ALT_MFP PC.1 setting for I2SBCLK  */ 
#define SYS_ALT_MFP1_PC1_I2SBCLK    NULL 
 
#define SYS_GPC_MFP_PC1_Msk         (1UL<<1)       /*!< GPC_MFP PC.1 mask */      
#define SYS_ALT_MFP_PC1_Msk         (1UL<<6)       /*!< ALT_MFP PC.1 mask */ 

//PC.2   
#define SYS_GPC_MFP_PC2_GPIO        0x00000000UL   /*!< GPC_MFP PC.2 setting for GPIO */    
#define SYS_ALT_MFP_PC2_GPIO        0x00000000UL   /*!< ALT_MFP PC.2 setting for GPIO */
#define SYS_ALT_MFP1_PC2_GPIO       NULL

#define SYS_GPC_MFP_PC2_MISO00      (1UL<<2)       /*!< GPC_MFP PC.2 setting for MISO00 */    
#define SYS_ALT_MFP_PC2_MISO00      0x00000000UL   /*!< ALT_MFP PC.2 setting for MISO00 */ 
#define SYS_ALT_MFP1_PC2_MISO00     NULL

#define SYS_GPC_MFP_PC2_I2SDI       (1UL<<2)       /*!< GPC_MFP PC.2 setting for I2SDI  */    
#define SYS_ALT_MFP_PC2_I2SDI       (1UL<<7)       /*!< ALT_MFP PC.2 setting for I2SDI  */ 
#define SYS_ALT_MFP1_PC2_I2SDI      NULL

#define SYS_GPC_MFP_PC2_Msk         (1UL<<2)       /*!< GPC_MFP PC.2 mask */      
#define SYS_ALT_MFP_PC2_Msk         (1UL<<7)       /*!< ALT_MFP PC.2 mask */ 

//PC.3   
#define SYS_GPC_MFP_PC3_GPIO        0x00000000UL   /*!< GPC_MFP PC.3 setting for GPIO */    
#define SYS_ALT_MFP_PC3_GPIO        0x00000000UL   /*!< ALT_MFP PC.3 setting for GPIO */
#define SYS_ALT_MFP1_PC3_GPIO       NULL

#define SYS_GPC_MFP_PC3_MOSI00      (1UL<<3)       /*!< GPC_MFP PC.3 setting for MOSI00 */    
#define SYS_ALT_MFP_PC3_MOSI00      0x00000000UL   /*!< ALT_MFP PC.3 setting for MOSI00 */ 
#define SYS_ALT_MFP1_PC3_MOSI00     NULL

#define SYS_GPC_MFP_PC3_I2SDO       (1UL<<3)       /*!< GPC_MFP PC.3 setting for I2SDO  */    
#define SYS_ALT_MFP_PC3_I2SDO       (1UL<<8)       /*!< ALT_MFP PC.3 setting for I2SDO  */ 
#define SYS_ALT_MFP1_PC3_I2SDO      NULL

#define SYS_GPC_MFP_PC3_Msk         (1UL<<3)       /*!< GPC_MFP PC.3 mask */      
#define SYS_ALT_MFP_PC3_Msk         (1UL<<8)       /*!< ALT_MFP PC.3 mask */ 

//PC.4   
#define SYS_GPC_MFP_PC4_GPIO        0x00000000UL   /*!< GPC_MFP PC.4 setting for GPIO */     
#define SYS_ALT_MFP_PC4_GPIO        NULL
#define SYS_ALT_MFP1_PC4_GPIO       NULL

#define SYS_GPC_MFP_PC4_MISO1       (1UL<<4)       /*!< GPC_MFP PC.4 setting for MISO01 */      
#define SYS_ALT_MFP_PC4_MISO1       NULL
#define SYS_ALT_MFP1_PC4_MISO1      NULL

#define SYS_GPC_MFP_PC4_Msk         (1UL<<4)       /*!< GPC_MFP PC.4 mask */      

//PC.5   
#define SYS_GPC_MFP_PC5_GPIO        0x00000000UL   /*!< GPC_MFP PC.5 setting for GPIO */     
#define SYS_ALT_MFP_PC5_GPIO        NULL
#define SYS_ALT_MFP1_PC5_GPIO       NULL

#define SYS_GPC_MFP_PC5_MOSI01      (1UL<<5)       /*!< GPC_MFP PC.5 setting for MOSI01 */      
#define SYS_ALT_MFP_PC5_MOSI01      NULL
#define SYS_ALT_MFP1_PC5_MOSI01     NULL

#define SYS_GPC_MFP_PC5_Msk         (1UL<<5)       /*!< GPC_MFP PC.5 mask */  

//PC.6   
#define SYS_GPC_MFP_PC6_GPIO        0x00000000UL   /*!< GPC_MFP PC.6 setting for GPIO */    
#define SYS_ALT_MFP_PC6_GPIO        NULL
#define SYS_ALT_MFP1_PC6_GPIO       0x00000000UL   /*!< ALT_MFP1 PC.6 setting for GPIO */

#define SYS_GPC_MFP_PC6_CPP0        (1UL<<6)       /*!< GPC_MFP PC.6 setting for CPP0 */    
#define SYS_ALT_MFP_PC6_CPP0        NULL
#define SYS_ALT_MFP1_PC6_CPP0       0x00000000UL   /*!< ALT_MFP1 PC.6 setting for CPP0 */ 

#define SYS_GPC_MFP_PC6_SC0CD       (1UL<<6)       /*!< GPC_MFP PC.6 setting for SC0CD  */    
#define SYS_ALT_MFP_PC6_SC0CD       NULL
#define SYS_ALT_MFP1_PC6_SC0CD      (1UL<<4)       /*!< ALT_MFP1 PC.6 setting for SC0CD  */ 
 
#define SYS_GPC_MFP_PC6_Msk         (1UL<<6)       /*!< GPC_MFP PC.6 mask */      
#define SYS_ALT_MFP1_PC6_Msk        (1UL<<4)       /*!< ALT_MFP1 PC.6 mask */ 

//PC.7   
#define SYS_GPC_MFP_PC7_GPIO        0x00000000UL   /*!< GPC_MFP PC.7 setting for GPIO */    
#define SYS_ALT_MFP_PC7_GPIO        NULL
#define SYS_ALT_MFP1_PC7_GPIO       0x00000000UL   /*!< ALT_MFP1 PC.7 setting for GPIO */
    
#define SYS_GPC_MFP_PC7_CPN0        (1UL<<7)       /*!< GPC_MFP PC.7 setting for CPN0 */    
#define SYS_ALT_MFP_PC7_CPN0        NULL
#define SYS_ALT_MFP1_PC7_CPN0       0x00000000UL   /*!< ALT_MFP1 PC.7 setting for CPN0 */ 

#define SYS_GPC_MFP_PC7_SC1CD       (1UL<<7)       /*!< GPC_MFP PC.7 setting for SC1CD  */    
#define SYS_ALT_MFP_PC7_SC1CD       NULL
#define SYS_ALT_MFP1_PC7_SC1CD      (1UL<<9)       /*!< ALT_MFP1 PC.7 setting for SC1CD  */ 
 
#define SYS_GPC_MFP_PC7_Msk         (1UL<<7)       /*!< GPC_MFP PC.7 mask */      
#define SYS_ALT_MFP1_PC7_Msk        (1UL<<9)       /*!< ALT_MFP1 PC.7 mask */ 

//PC.8   
#define SYS_GPC_MFP_PC8_GPIO        0x00000000UL   /*!< GPC_MFP PC.8 setting for GPIO */    
#define SYS_ALT_MFP_PC8_GPIO        NULL
#define SYS_ALT_MFP1_PC8_GPIO       NULL

#define SYS_GPC_MFP_PC8_SPISS10     (1UL<<8)       /*!< GPC_MFP PC.8 setting for SPISS10 */    
#define SYS_ALT_MFP_PC8_SPISS10     NULL
#define SYS_ALT_MFP1_PC8_SPISS10    NULL

#define SYS_GPC_MFP_PC8_Msk         (1UL<<8)       /*!< GPC_MFP PC.8 mask */      

//PC.9   
#define SYS_GPC_MFP_PC9_GPIO        0x00000000UL   /*!< GPC_MFP PC.9 setting for GPIO */       
#define SYS_ALT_MFP_PC9_GPIO        NULL
#define SYS_ALT_MFP1_PC9_GPIO       NULL

#define SYS_GPC_MFP_PC9_SPICLK1     (1UL<<9)       /*!< GPC_MFP PC.9 setting for SPICLK1 */    
#define SYS_ALT_MFP_PC9_SPICLK1     NULL
#define SYS_ALT_MFP1_PC9_SPICLK1    NULL

#define SYS_GPC_MFP_PC9_Msk         (1UL<<9)       /*!< GPC_MFP PC.9 mask */      

//PC.10   
#define SYS_GPC_MFP_PC10_GPIO       0x00000000UL   /*!< GPC_MFP PC.10 setting for GPIO */        
#define SYS_ALT_MFP_PC10_GPIO       NULL
#define SYS_ALT_MFP1_PC10_GPIO      NULL

#define SYS_GPC_MFP_PC10_MISO10     (1UL<<10)      /*!< GPC_MFP PC.10 setting for MISO10 */    
#define SYS_ALT_MFP_PC10_MISO10     NULL
#define SYS_ALT_MFP1_PC10_MISO10    NULL

#define SYS_GPC_MFP_PC10_Msk         (1UL<<10)      /*!< GPC_MFP PC.10 mask */      

//PC.11   
#define SYS_GPC_MFP_PC11_GPIO       0x00000000UL   /*!< GPC_MFP PC.11 setting for GPIO */     
#define SYS_ALT_MFP_PC11_GPIO       NULL
#define SYS_ALT_MFP1_PC11_GPIO      NULL

#define SYS_GPC_MFP_PC11_MOSI10     (1UL<<11)      /*!< GPC_MFP PC.11 setting for MOSI10 */    
#define SYS_ALT_MFP_PC11_MOSI10     NULL
#define SYS_ALT_MFP1_PC11_MOSI10    NULL

#define SYS_GPC_MFP_PC11_Msk         (1UL<<11)      /*!< GPC_MFP PC.11 mask */      


//PC.12   
#define SYS_GPC_MFP_PC12_GPIO        0x00000000UL   /*!< GPC_MFP PC.12 setting for GPIO */     
#define SYS_ALT_MFP_PC12_GPIO        NULL
#define SYS_ALT_MFP1_PC12_GPIO       NULL

#define SYS_GPC_MFP_PC12_MISO11      (1UL<<12)      /*!< GPC_MFP PC.12 setting for MISO11 */      
#define SYS_ALT_MFP_PC12_MISO11      NULL
#define SYS_ALT_MFP1_PC12_MISO11     NULL

#define SYS_GPC_MFP_PC12_Msk         (1UL<<12)      /*!< GPC_MFP PC.12 mask */   

//PC.13   
#define SYS_GPC_MFP_PC13_GPIO        0x00000000UL   /*!< GPC_MFP PC.13 setting for GPIO */     
#define SYS_ALT_MFP_PC13_GPIO        NULL
#define SYS_ALT_MFP1_PC13_GPIO       NULL

#define SYS_GPC_MFP_PC13_MOSI11      (1UL<<13)      /*!< GPC_MFP PC.13 setting for MOSI11 */      
#define SYS_ALT_MFP_PC13_MOSI11      NULL
#define SYS_ALT_MFP1_PC13_MOSI11     NULL

#define SYS_GPC_MFP_PC13_Msk         (1UL<<13)      /*!< GPC_MFP PC.13 mask */   

//PC.14   
#define SYS_GPC_MFP_PC14_GPIO        0x00000000UL   /*!< GPC_MFP PC.14 setting for GPIO */       
#define SYS_ALT_MFP_PC14_GPIO        NULL
#define SYS_ALT_MFP1_PC14_GPIO       NULL

#define SYS_GPC_MFP_PC14_CPP1        (1UL<<14)      /*!< GPC_MFP PC.14 setting for CPP1  */    
#define SYS_ALT_MFP_PC14_CPP1        NULL
#define SYS_ALT_MFP1_PC14_CPP1       NULL

#define SYS_GPC_MFP_PC14_Msk         (1UL<<14)      /*!< GPC_MFP PC.14 mask */      


//PC.15   
#define SYS_GPC_MFP_PC15_GPIO        0x00000000UL   /*!< GPC_MFP PC.15 setting for GPIO */        
#define SYS_ALT_MFP_PC15_GPIO        NULL
#define SYS_ALT_MFP1_PC15_GPIO       NULL

#define SYS_GPC_MFP_PC15_CPN1        (1UL<<15)      /*!< GPC_MFP PC.15 setting for CPN1  */    
#define SYS_ALT_MFP_PC15_CPN1        NULL
#define SYS_ALAT_MFP1_PC15_CPN1      NULL

#define SYS_GPC_MFP_PC15_Msk         (1UL<<15)      /*!< GPC_MFP PC.15 mask */      


//PD.0   
#define SYS_GPD_MFP_PD0_GPIO        0x00000000UL  /*!< GPD_MFP PD.0 setting for GPIO */       
#define SYS_ALT_MFP_PD0_GPIO        NULL
#define SYS_ALT_MFP1_PD0_GPIO       NULL

#define SYS_GPD_MFP_PD0_SPISS20     (1UL<<0)      /*!< GPD_MFP PD.0 setting for SPISS20 */    
#define SYS_ALT_MFP_PD0_SPISS20     NULL
#define SYS_ALT_MFP1_PD0_SPISS20    NULL

#define SYS_GPD_MFP_PD0_Msk         (1UL<<0)      /*!< GPD_MFP PD.0 mask */      

//PD.1   
#define SYS_GPD_MFP_PD1_GPIO        0x00000000UL  /*!< GPD_MFP PD.1 setting for GPIO */       
#define SYS_ALT_MFP_PD1_GPIO        NULL
#define SYS_ALT_MFP1_PD1_GPIO       NULL

#define SYS_GPD_MFP_PD1_SPICLK2     (1UL<<1)      /*!< GPD_MFP PD.1 setting for SPICLK2 */     
#define SYS_ALT_MFP_PD1_SPICLK2     NULL
#define SYS_ALT_MFP1_PD1_SPICLK2    NULL

#define SYS_GPD_MFP_PD1_Msk         (1UL<<1)      /*!< GPD_MFP PD.1 mask */      

//PD.2   
#define SYS_GPD_MFP_PD2_GPIO        0x00000000UL  /*!< GPD_MFP PD.2 setting for GPIO */        
#define SYS_ALT_MFP_PD2_GPIO        NULL
#define SYS_ALT_MFP1_PD2_GPIO       NULL

#define SYS_GPD_MFP_PD2_MISO20      (1UL<<2)      /*!< GPD_MFP PD.2 setting for MISO20 */    
#define SYS_ALT_MFP_PD2_MISO20      NULL
#define SYS_ALT_MFP1_PD2_MISO20     NULL

#define SYS_GPD_MFP_PD2_Msk         (1UL<<2)      /*!< GPD_MFP PD.2 mask */      

//PD.3   
#define SYS_GPD_MFP_PD3_GPIO        0x00000000UL  /*!< GPD_MFP PD.3 setting for GPIO */        
#define SYS_ALT_MFP_PD3_GPIO        NULL
#define SYS_ALT_MFP1_PD3_GPIO       NULL

#define SYS_GPD_MFP_PD3_MOSI20      (1UL<<3)      /*!< GPD_MFP PD.3 setting for MOSI20 */    
#define SYS_ALT_MFP_PD3_MOSI20      NULL
#define SYS_ALT_MFP1_PD3_MOSI20     NULL

#define SYS_GPD_MFP_PD3_Msk         (1UL<<3)      /*!< GPD_MFP PD.3 mask */      

//PD.4   
#define SYS_GPD_MFP_PD4_GPIO        0x00000000UL  /*!< GPD_MFP PD.4 setting for GPIO */       
#define SYS_ALT_MFP_PD4_GPIO        NULL
#define SYS_ALT_MFP1_PD4_GPIO       NULL

#define SYS_GPD_MFP_PD4_MISO21      (1UL<<4)      /*!< GPD_MFP PD.4 setting for MISO21   */    
#define SYS_ALT_MFP_PD4_MISO21      NULL
#define SYS_ALT_MFP1_PD4_MISO21     NULL

#define SYS_GPD_MFP_PD4_Msk         (1UL<<4)      /*!< GPD_MFP PD.4 mask */      

//PD.5   
#define SYS_GPD_MFP_PD5_GPIO        0x00000000UL  /*!< GPD_MFP PD.5 setting for GPIO */       
#define SYS_ALT_MFP_PD5_GPIO        NULL
#define SYS_ALT_MFP1_PD5_GPIO       NULL

#define SYS_GPD_MFP_PD5_MOSI21      (1UL<<5)      /*!< GPD_MFP PD.5 setting for MOSI21   */    
#define SYS_ALT_MFP_PD5_MOSI21      NULL
#define SYS_ALT_MFP1_PD5_MOSI21     NULL

#define SYS_GPD_MFP_PD5_Msk         (1UL<<5)      /*!< GPD_MFP PD.5 mask */ 

//PD.6   
#define SYS_GPD_MFP_PD6_GPIO        0x00000000UL  /*!< GPD_MFP PD.6 setting for GPIO */       
#define SYS_ALT_MFP_PD6_GPIO        NULL
#define SYS_ALT_MFP1_PD6_GPIO       NULL

#define SYS_GPD_MFP_PD6_CAN0RX      (1UL<<6)      /*!< GPD_MFP PD.6 setting for CAN0RX   */    
#define SYS_ALT_MFP_PD6_CAN0RX      NULL
#define SYS_ALT_MFP1_PD6_CAN0RX     NULL

#define SYS_GPD_MFP_PD6_Msk         (1UL<<6)      /*!< GPD_MFP PD.6 mask */ 

//PD.7   
#define SYS_GPD_MFP_PD7_GPIO        0x00000000UL  /*!< GPD_MFP PD.7 setting for GPIO */       
#define SYS_ALT_MFP_PD7_GPIO
#define SYS_ALT_MFP1_PD7_GPIO

#define SYS_GPD_MFP_PD7_CAN0TX      (1UL<<7)      /*!< GPD_MFP PD.7 setting for CAN0TX   */    
#define SYS_ALT_MFP_PD7_CAN0TX      NULL
#define SYS_ALT_MFP1_PD7_CAN0TX     NULL

#define SYS_GPD_MFP_PD7_Msk         (1UL<<7)      /*!< GPD_MFP PD.7 mask */ 

//PD.8   
#define SYS_GPD_MFP_PD8_GPIO        0x00000000UL  /*!< GPD_MFP PD.8 setting for GPIO */       
#define SYS_ALT_MFP_PD8_GPIO        NULL
#define SYS_ALT_MFP1_PD8_GPIO       NULL

#define SYS_GPD_MFP_PD8_SS30        (1UL<<8)      /*!< GPD_MFP PD.8 setting for SPI3 SS30   */    
#define SYS_ALT_MFP_PD8_SS30        NULL
#define SYS_ALT_MFP1_PD8_SS30       NULL

#define SYS_GPD_MFP_PD8_Msk         (1UL<<8)      /*!< GPD_MFP PD.8 mask */ 

//PD.9   
#define SYS_GPD_MFP_PD9_GPIO        0x00000000UL  /*!< GPD_MFP PD.9 setting for GPIO */       
#define SYS_ALT_MFP_PD9_GPIO        NULL
#define SYS_ALT_MFP1_PD9_GPIO       NULL

#define SYS_GPD_MFP_PD9_SPI3CLK     (1UL<<9)      /*!< GPD_MFP PD.9 setting for SPI3CLK   */    
#define SYS_ALT_MFP_PD9_SPI3CLK     NULL
#define SYS_ALT_MFP1_PD9_SPI3CLK    NULL

#define SYS_GPD_MFP_PD9_Msk         (1UL<<9)      /*!< GPD_MFP PD.9 mask */ 

//PD.10   
#define SYS_GPD_MFP_PD10_GPIO       0x00000000UL  /*!< GPD_MFP PD.10 setting for GPIO */       
#define SYS_ALT_MFP_PD10_GPIO       NULL
#define SYS_ALT_MFP1_PD10_GPIO      NULL

#define SYS_GPD_MFP_PD10_MISO30     (1UL<<10)     /*!< GPD_MFP PD.10 setting for MISO30   */    
#define SYS_ALT_MFP_PD10_MISO30     NULL
#define SYS_ALT_MFP1_PD10_MISO30    NULL

#define SYS_GPD_MFP_PD10_Msk        (1UL<<10)     /*!< GPD_MFP PD.10 mask */

//PD.11   
#define SYS_GPD_MFP_PD11_GPIO       0x00000000UL  /*!< GPD_MFP PD.11 setting for GPIO */       
#define SYS_ALT_MFP_PD11_GPIO       NULL
#define SYS_ALT_MFP1_PD11_GPIO      NULL

#define SYS_GPD_MFP_PD11_MOSI30     (1UL<<11)     /*!< GPD_MFP PD.11 setting for MOSI30   */    
#define SYS_ALT_MFP_PD11_MOSI30     NULL
#define SYS_ALT_MFP1_PD11_MOSI30    NULL

#define SYS_GPD_MFP_PD11_Msk        (1UL<<11)     /*!< GPD_MFP PD.11 mask */

//PD.12   
#define SYS_GPD_MFP_PD12_GPIO       0x00000000UL  /*!< GPD_MFP PD.12 setting for GPIO */       
#define SYS_ALT_MFP_PD12_GPIO       NULL
#define SYS_ALT_MFP1_PD12_GPIO      NULL

#define SYS_GPD_MFP_PD12_MISO31     (1UL<<12)     /*!< GPD_MFP PD.12 setting for MISO31   */    
#define SYS_ALT_MFP_PD12_MISO31     NULL
#define SYS_ALT_MFP1_PD12_MISO31    NULL

#define SYS_GPD_MFP_PD12_Msk        (1UL<<12)     /*!< GPD_MFP PD.12 mask */

//PD.13   
#define SYS_GPD_MFP_PD13_GPIO       0x00000000UL  /*!< GPD_MFP PD.13 setting for GPIO */       
#define SYS_ALT_MFP_PD13_GPIO       NULL
#define SYS_ALT_MFP1_PD13_GPIO      NULL

#define SYS_GPD_MFP_PD13_MOSI31     (1UL<<13)     /*!< GPD_MFP PD.13 setting for MOSI31   */    
#define SYS_ALT_MFP_PD13_MOSI31     NULL
#define SYS_ALT_MFP1_PD13_MOSI31    NULL

#define SYS_GPD_MFP_PD13_Msk        (1UL<<13)     /*!< GPD_MFP PD.13 mask */

//PD.14   
#define SYS_GPD_MFP_PD14_GPIO       0x00000000UL  /*!< GPD_MFP PD.14 setting for GPIO */       
#define SYS_ALT_MFP_PD14_GPIO       NULL
#define SYS_ALT_MFP1_PD14_GPIO      NULL

#define SYS_GPD_MFP_PD14_RXD2       (1UL<<14)     /*!< GPD_MFP PD.14 setting for RXD2 */    
#define SYS_ALT_MFP_PD14_RXD2       NULL
#define SYS_ALT_MFP1_PD14_RXD2      NULL

#define SYS_GPD_MFP_PD14_Msk        (1UL<<14)     /*!< GPD_MFP PD.14 mask */

//PD.15   
#define SYS_GPD_MFP_PD15_GPIO       0x00000000UL  /*!< GPD_MFP PD.15 setting for GPIO */       
#define SYS_ALT_MFP_PD15_GPIO       NULL
#define SYS_ALT_MFP1_PD15_GPIO      NULL

#define SYS_GPD_MFP_PD15_TXD2       (1UL<<15)     /*!< GPD_MFP PD.15 setting for TXD2 */    
#define SYS_ALT_MFP_PD15_TXD2       NULL
#define SYS_ALT_MFP1_PD15_TXD2      NULL

#define SYS_GPD_MFP_PD15_Msk        (1UL<<15)     /*!< GPD_MFP PD.15 mask */

//PE.0   
#define SYS_GPE_MFP_PE0_GPIO        0x00000000UL  /*!< GPE_MFP PE.0 setting for GPIO */       
#define SYS_ALT_MFP_PE0_GPIO        NULL
#define SYS_ALT_MFP1_PE0_GPIO       NULL

#define SYS_GPE_MFP_PE0_PWM6        (1UL<<0)      /*!< GPE_MFP PE.0 setting for PWM6   */    
#define SYS_ALT_MFP_PE0_PWM6        NULL
#define SYS_ALT_MFP1_PE0_PWM6       NULL

#define SYS_GPE_MFP_PE0_Msk         (1UL<<0)      /*!< GPE_MFP PE.0 mask */

//PE.1   
#define SYS_GPE_MFP_PE1_GPIO        0x00000000UL  /*!< GPE_MFP PE.1 setting for GPIO */       
#define SYS_ALT_MFP_PE1_GPIO        NULL
#define SYS_ALT_MFP1_PE1_GPIO       NULL

#define SYS_GPE_MFP_PE1_PWM7        (1UL<<1)      /*!< GPE_MFP PE.1 setting for PWM7   */    
#define SYS_ALT_MFP_PE1_PWM7        NULL
#define SYS_ALT_MFP1_PE1_PWM7       NULL

#define SYS_GPE_MFP_PE1_Msk         (1UL<<1)      /*!< GPE_MFP PE.1 mask */

//PE.5   
#define SYS_GPE_MFP_PE5_GPIO        0x00000000UL   /*!< GPE_MFP PE.5 setting for GPIO */    
#define SYS_ALT_MFP_PE5_GPIO        0x00000000UL   /*!< ALT_MFP PE.5 setting for GPIO */
#define SYS_ALT_MFP1_PE5_GPIO       NULL

#define SYS_GPE_MFP_PE5_PWM5        (1UL<<5)       /*!< GPE_MFP PE.5 setting for PWM5  */    
#define SYS_ALT_MFP_PE5_PWM5        0x00000000UL   /*!< ALT_MFP PE.5 setting for PWM5  */ 
#define SYS_ALT_MFP1_PE5_PWM5       NULL

#define SYS_GPE_MFP_PE5_T1EX        (1UL<<5)       /*!< GPE_MFP PE.5 setting for T1EX  */    
#define SYS_ALT_MFP_PE5_T1EX        (1UL<<25)      /*!< ALT_MFP PE.5 setting for T1EX  */ 
#define SYS_ALT_MFP1_PE5_T1EX       NULL

#define SYS_GPE_MFP_PE5_Msk         (1UL<<5)       /*!< GPE_MFP PE.5 mask */      
#define SYS_ALT_MFP_PE5_Msk         (1UL<<25)      /*!< ALT_MFP PE.5 mask */ 

//PF.0   
#define SYS_GPF_MFP_PF0_GPIO        0x00000000UL  /*!< GPF_MFP PF.0 setting for GPIO */       
#define SYS_ALT_MFP_PF0_GPIO        NULL
#define SYS_ALT_MFP1_PF0_GPIO       NULL

#define SYS_GPF_MFP_PF0_XT1_OUT     (1UL<<0)      /*!< GPF_MFP PF.0 setting for XT1_OUT   */    
#define SYS_ALT_MFP_PF0_XT1_OUT     NULL
#define SYS_ALT_MFP1_PF0_XT1_OUT    NULL

#define SYS_GPF_MFP_PF0_Msk         (1UL<<0)      /*!< GPF_MFP PF.0 mask */

//PF.1   
#define SYS_GPF_MFP_PF1_GPIO        0x00000000UL  /*!< GPF_MFP PF.1 setting for GPIO */       
#define SYS_ALT_MFP_PF1_GPIO        NULL
#define SYS_ALT_MFP1_PF1_GPIO       NULL

#define SYS_GPF_MFP_PF1_XT1_IN      (1UL<<1)      /*!< GPF_MFP PF.1 setting for XT1_IN   */    
#define SYS_ALT_MFP_PF1_XT1_IN      NULL
#define SYS_ALT_MFP1_PF1_XT1_IN     NULL

#define SYS_GPF_MFP_PF1_Msk         (1UL<<1)      /*!< GPF_MFP PF.1 mask */

//PF.2   
#define SYS_GPF_MFP_PF2_GPIO        0x00000000UL  /*!< GPF_MFP PF.2 setting for GPIO */       
#define SYS_ALT_MFP_PF2_GPIO        NULL
#define SYS_ALT_MFP1_PF2_GPIO       NULL

#define SYS_GPF_MFP_PF2_PS2DAT      (1UL<<2)      /*!< GPF_MFP PF.2 setting for PS2DAT   */    
#define SYS_ALT_MFP_PF2_PS2DAT      NULL
#define SYS_ALT_MFP1_PF2_PS2DAT     NULL

#define SYS_GPF_MFP_PF2_Msk         (1UL<<2)      /*!< GPF_MFP PF.2 mask */

//PF.3   
#define SYS_GPF_MFP_PF3_GPIO        0x00000000UL  /*!< GPF_MFP PF.3 setting for GPIO */       
#define SYS_ALT_MFP_PF3_GPIO        NULL
#define SYS_ALT_MFP1_PF3_GPIO       NULL

#define SYS_GPF_MFP_PF3_PS2CLK      (1UL<<3)      /*!< GPF_MFP PF.3 setting for PS2CLK   */    
#define SYS_ALT_MFP_PF3_PS2CLK      NULL
#define SYS_ALT_MFP1_PF3_PS2CLK     NULL

#define SYS_GPF_MFP_PF3_Msk         (1UL<<3)      /*!< GPF_MFP PF.3 mask */


/*---------------------------------------------------------------------------------------------------------*/
/*  Brown Out Detector Threshold Voltage Selection constant definitions.                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define SYS_BODCR_BOD_VL_4_5V     0x06UL       /*!< Setting Brown Out Detector Threshold Voltage as 4.5V */
#define SYS_BODCR_BOD_VL_3_8V     0x04UL       /*!< Setting Brown Out Detector Threshold Voltage as 3.8V */ 
#define SYS_BODCR_BOD_VL_2_7V     0x02UL       /*!< Setting Brown Out Detector Threshold Voltage as 2.7V */
#define SYS_BODCR_BOD_VL_2_2V     0x00UL       /*!< Setting Brown Out Detector Threshold Voltage as 2.2V */


/*---------------------------------------------------------------------------------------------------------*/
/*  Define Macro                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define _SYS_RESET_CPU()   (SYS->IPRSTC1 |= SYS_IPRSTC1_CPU_RST_Msk) /*!< Reset CPU by setting CPU_RST bit from IPRSTC1 Register         */
#define _SYS_RESET_CHIP()  (SYS->IPRSTC1 = SYS_IPRSTC1_CHIP_RST_Msk) /*!< Reset Whole Chip by setting CHIP_RST bit from IPRSTC1 Register */

//PA.0
#define _SYS_GPA_MFP_PA0(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA0_Msk)) | (x))
#define _SYS_ALT_MFP1_PA0(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA0_Msk))| (x))

//PA.1
#define _SYS_GPA_MFP_PA1(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA1_Msk)) | (x))
#define _SYS_ALT_MFP1_PA1(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA1_Msk))| (x))

//PA.2
#define _SYS_GPA_MFP_PA2(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA2_Msk)) | (x))
#define _SYS_ALT_MFP1_PA2(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA2_Msk))| (x))

//PA.3
#define _SYS_GPA_MFP_PA3(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA3_Msk)) | (x))
#define _SYS_ALT_MFP1_PA3(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA3_Msk))| (x))

//PA.4
#define _SYS_GPA_MFP_PA4(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA4_Msk)) | (x))
#define _SYS_ALT_MFP1_PA4(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA4_Msk))| (x))

//PA.5
#define _SYS_GPA_MFP_PA5(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA5_Msk)) | (x))
#define _SYS_ALT_MFP1_PA5(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA5_Msk))| (x))

//PA.6
#define _SYS_GPA_MFP_PA6(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA6_Msk)) | (x))
#define _SYS_ALT_MFP1_PA6(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA6_Msk))| (x))

//PA.7
#define _SYS_GPA_MFP_PA7(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA7_Msk)) | (x))
#define _SYS_ALT_MFP_PA7(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PA7_Msk)) | (x))
#define _SYS_ALT_MFP1_PA7(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA7_Msk))| (x))

//PA.8
#define _SYS_GPA_MFP_PA8(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA8_Msk)) | (x))

//PA.9
#define _SYS_GPA_MFP_PA9(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA9_Msk)) | (x))

//PA.10
#define _SYS_GPA_MFP_PA10(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA10_Msk)) | (x))
#define _SYS_ALT_MFP_PA10(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PA10_Msk)) | (x))

//PA.11
#define _SYS_GPA_MFP_PA11(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA11_Msk)) | (x))
#define _SYS_ALT_MFP_PA11(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PA11_Msk)) | (x))

//PA.12
#define _SYS_GPA_MFP_PA12(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA12_Msk)) | (x))
#define _SYS_ALT_MFP1_PA12(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA12_Msk))| (x))

//PA.13
#define _SYS_GPA_MFP_PA13(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA13_Msk)) | (x))
#define _SYS_ALT_MFP1_PA13(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA13_Msk))| (x))

//PA.14
#define _SYS_GPA_MFP_PA14(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA14_Msk)) | (x))
#define _SYS_ALT_MFP1_PA14(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA14_Msk))| (x))

//PA.15
#define _SYS_GPA_MFP_PA15(x)    (SYS->GPA_MFP = (SYS->GPA_MFP & (~SYS_GPA_MFP_PA15_Msk)) | (x))
#define _SYS_ALT_MFP_PA15(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PA15_Msk)) | (x))
#define _SYS_ALT_MFP1_PA15(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PA15_Msk))| (x))

//PB.0
#define _SYS_GPB_MFP_PB0(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB0_Msk)) | (x))

//PB.1
#define _SYS_GPB_MFP_PB1(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB1_Msk)) | (x))

//PB.2
#define _SYS_GPB_MFP_PB2(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB2_Msk)) | (x))
#define _SYS_ALT_MFP_PB2(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB2_Msk)) | (x))

//PB.3
#define _SYS_GPB_MFP_PB3(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB3_Msk)) | (x))
#define _SYS_ALT_MFP_PB3(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB3_Msk)) | (x))
#define _SYS_ALT_MFP1_PB3(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT_MFP1_PB3_Msk))| (x))

//PB.4
#define _SYS_GPB_MFP_PB4(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB4_Msk)) | (x))

//PB.5
#define _SYS_GPB_MFP_PB5(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB5_Msk)) | (x))

//PB.6
#define _SYS_GPB_MFP_PB6(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB6_Msk)) | (x))

//PB.7
#define _SYS_GPB_MFP_PB7(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB7_Msk)) | (x))

//PB.8
#define _SYS_GPB_MFP_PB8(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB8_Msk)) | (x))
#define _SYS_ALT_MFP_PB8(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB8_Msk)) | (x))

//PB.9
#define _SYS_GPB_MFP_PB9(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB9_Msk)) | (x))
#define _SYS_ALT_MFP_PB9(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB9_Msk)) | (x))

//PB.10
#define _SYS_GPB_MFP_PB10(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB10_Msk)) | (x))
#define _SYS_ALT_MFP_PB10(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB10_Msk)) | (x))

//PB.11
#define _SYS_GPB_MFP_PB11(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB11_Msk)) | (x))
#define _SYS_ALT_MFP_PB11(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB11_Msk)) | (x))

//PB.12 Reserved

//PB.13
#define _SYS_GPB_MFP_PB13(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB13_Msk)) | (x))

//PB.14
#define _SYS_GPB_MFP_PB14(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB14_Msk)) | (x))
#define _SYS_ALT_MFP_PB14(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB14_Msk)) | (x))

//PB.15
#define _SYS_GPB_MFP_PB15(x)    (SYS->GPB_MFP = (SYS->GPB_MFP & (~SYS_GPB_MFP_PB15_Msk)) | (x))
#define _SYS_ALT_MFP_PB15(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PB15_Msk)) | (x))

//PC.0
#define _SYS_GPC_MFP_PC0(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC0_Msk)) | (x))
#define _SYS_ALT_MFP_PC0(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PC0_Msk)) | (x))

//PC.1
#define _SYS_GPC_MFP_PC1(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC1_Msk)) | (x))
#define _SYS_ALT_MFP_PC1(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PC1_Msk)) | (x))

//PC.2
#define _SYS_GPC_MFP_PC2(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC2_Msk)) | (x))
#define _SYS_ALT_MFP_PC2(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PC2_Msk)) | (x))

//PC.3
#define _SYS_GPC_MFP_PC3(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC3_Msk)) | (x))
#define _SYS_ALT_MFP_PC3(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PC3_Msk)) | (x))

//PC.4
#define _SYS_GPC_MFP_PC4(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC4_Msk)) | (x))

//PC.5
#define _SYS_GPC_MFP_PC5(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC5_Msk)) | (x))

//PC.6
#define _SYS_GPC_MFP_PC6(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC6_Msk)) | (x))
#define _SYS_ALT_MFP1_PC6(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT1_MFP_PC6_Msk))| (x))

//PC.7
#define _SYS_GPC_MFP_PC7(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC7_Msk)) | (x))
#define _SYS_ALT_MFP1_PC7(x)   (SYS->ALT_MFP1= (SYS->ALT_MFP1& (~SYS_ALT1_MFP_PC7_Msk))| (x))

//PC.8
#define _SYS_GPC_MFP_PC8(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC8_Msk)) | (x))

//PC.9
#define _SYS_GPC_MFP_PC9(x)    (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC9_Msk)) | (x))

//PC.10
#define _SYS_GPC_MFP_PC10(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC10_Msk)) | (x))

//PC.11
#define _SYS_GPC_MFP_PC11(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC11_Msk)) | (x))

//PC.12
#define _SYS_GPC_MFP_PC12(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC12_Msk)) | (x))

//PC.13
#define _SYS_GPC_MFP_PC13(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC13_Msk)) | (x))

//PC.14
#define _SYS_GPC_MFP_PC14(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC14_Msk)) | (x))

//PC.15
#define _SYS_GPC_MFP_PC15(x)   (SYS->GPC_MFP = (SYS->GPC_MFP & (~SYS_GPC_MFP_PC15_Msk)) | (x))

//PD.0
#define _SYS_GPD_MFP_PD0(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD0_Msk)) | (x))
//PD.1
#define _SYS_GPD_MFP_PD1(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD1_Msk)) | (x))
//PD.2
#define _SYS_GPD_MFP_PD2(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD2_Msk)) | (x))
//PD.3
#define _SYS_GPD_MFP_PD3(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD3_Msk)) | (x))
//PD.4
#define _SYS_GPD_MFP_PD4(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD4_Msk)) | (x))
//PD.5
#define _SYS_GPD_MFP_PD5(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD5_Msk)) | (x))
//PD.6
#define _SYS_GPD_MFP_PD6(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD6_Msk)) | (x))
//PD.7
#define _SYS_GPD_MFP_PD7(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD7_Msk)) | (x))
//PD.8
#define _SYS_GPD_MFP_PD8(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD8_Msk)) | (x))
//PD.9
#define _SYS_GPD_MFP_PD9(x)    (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD9_Msk)) | (x))
//PD.10
#define _SYS_GPD_MFP_PD10(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD10_Msk))| (x))
//PD.11
#define _SYS_GPD_MFP_PD11(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD11_Msk))| (x))
//PD.12
#define _SYS_GPD_MFP_PD12(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD12_Msk))| (x))
//PD.13
#define _SYS_GPD_MFP_PD13(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD13_Msk))| (x))
//PD.14
#define _SYS_GPD_MFP_PD14(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD14_Msk))| (x))
//PD.15
#define _SYS_GPD_MFP_PD15(x)   (SYS->GPD_MFP = (SYS->GPD_MFP & (~SYS_GPD_MFP_PD15_Msk))| (x))

//PE.0
#define _SYS_GPE_MFP_PE0(x)    (SYS->GPE_MFP = (SYS->GPE_MFP & (~SYS_GPE_MFP_PE0_Msk)) | (x))

//PE.1
#define _SYS_GPE_MFP_PE1(x)    (SYS->GPE_MFP = (SYS->GPE_MFP & (~SYS_GPE_MFP_PE1_Msk)) | (x))

//PE.5
#define _SYS_GPE_MFP_PE5(x)    (SYS->GPE_MFP = (SYS->GPE_MFP & (~SYS_GPE_MFP_PE5_Msk)) | (x))
#define _SYS_ALT_MFP_PE5(x)    (SYS->ALT_MFP = (SYS->ALT_MFP & (~SYS_ALT_MFP_PE5_Msk)) | (x))

//PF.0
#define _SYS_GPF_MFP_PF0(x)    (SYS->GPF_MFP = (SYS->GPF_MFP & (~SYS_GPF_MFP_PF0_Msk)) | (x))
//PF.1
#define _SYS_GPF_MFP_PF1(x)    (SYS->GPF_MFP = (SYS->GPF_MFP & (~SYS_GPF_MFP_PF1_Msk)) | (x))
//PF.2
#define _SYS_GPF_MFP_PF2(x)    (SYS->GPF_MFP = (SYS->GPF_MFP & (~SYS_GPF_MFP_PF2_Msk)) | (x))
//PF.3
#define _SYS_GPF_MFP_PF3(x)    (SYS->GPF_MFP = (SYS->GPF_MFP & (~SYS_GPF_MFP_PF3_Msk)) | (x))


/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

/**
 * @brief    Get PLL Clock Output Frequency  
 *
 * @param    None
 *
 * @return   PLL clock output frequency 
 *
 * @details  To get actual PLL clock output frequency. The clock uint is in Hz.
 */
static __INLINE uint32_t DrvSYS_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4}; /* OUT_DV :DEF: {1, 2, 2, 4} */
    uint32_t u32Reg;

    u32PllFreq = 0;
    u32Reg = SYSCLK->PLLCON;
    if((u32Reg & (SYSCLK_PLLCON_PD_Msk | SYSCLK_PLLCON_OE_Msk)) == 0)
    {    
        /* PLL is enabled and output enabled */

        u32FIN = (u32Reg & SYSCLK_PLLCON_PLL_SRC_Msk)?__IRC22M:__XTAL;
        if(u32Reg & SYSCLK_PLLCON_BP_Msk)
        {
            /* PLL is in bypass mode */
            u32PllFreq = u32FIN;
        }
        else 
        {
            /* PLL is in normal work mode */
            u32NO = au8NoTbl[((u32Reg & SYSCLK_PLLCON_OUT_DV_Msk) >> SYSCLK_PLLCON_OUT_DV_Pos)];
            u32NF  = ((u32Reg & SYSCLK_PLLCON_FB_DV_Msk) >> SYSCLK_PLLCON_FB_DV_Pos) + 2;
            u32NR  = ((u32Reg & SYSCLK_PLLCON_IN_DV_Msk) >> SYSCLK_PLLCON_IN_DV_Pos) + 2;
            /* u32FIN is shifted 2 bits to avoid overflow */
            u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2); 
        }
    }

    return u32PllFreq;
}


/**
 * @brief    Waiting for clock stable
 *
 * @param    Mask bits of CLKSTATUS register. Including:
 *           SYSCLK_CLKSTATUS_CLK_SW_FAIL_Msk
 *           SYSCLK_CLKSTATUS_IRC22M_STB_Msk
 *           SYSCLK_CLKSTATUS_IRC10K_STB_Msk
 *           SYSCLK_CLKSTATUS_PLL_STB_Msk
 *           SYSCLK_CLKSTATUS_XTL12M_STB_Msk
 *
 * @return   None
 *
 * @details  To wait for clock ready by specified CLKSTATUS bit or timeout (~5ms)
 */
static __INLINE void SYS_WaitingForClockReady(uint32_t u32Mask)
{
    int32_t i32TimeOutCnt;

    i32TimeOutCnt = __HSI / 200; /* About 5ms */
    
    while((SYSCLK->CLKSTATUS & u32Mask) != u32Mask)
    {
        if(i32TimeOutCnt-- <= 0)
            break;    
    }
}

/**
 * @brief      Generate the Delay Time by Systick
 *
 * @param[in]  us  Delay time. The Max value is 2^24 / CPU Clock(MHz). Ex:
 *                             50MHz => 335544us, 48MHz => 349525us, 28MHz => 699050us ...
 *
 * @return     None
 *
 * @details    Use the SysTick to generate the delay time and the UNIT is in us. 
 *             The SysTick clock source is from HCLK, i.e the same as system core clock.
 */
static __INLINE void SYS_SysTickDelay(uint32_t us)
{
    SysTick->LOAD = us * CyclesPerUs;
    SysTick->VAL  =  (0x00);
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    /* Waiting for down-count to zero */
    while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
}


/**
 * @brief      Enable CKO clock
 *
 * @param[in]  u32ClkSrc  Select the source clock for CKO. It could be 
 *                        SYSCLK_CLKSEL2_FRQDIV_XTAL, SYSCLK_CLKSEL2_FRQDIV_HCLK or SYSCLK_CLKSEL2_FRQDIV_IRC22M.
 * @param[in]  u32ClkDiv  Set the clock divider to CKO. 0 <= u32ClkDiv <= 15
 *
 * @return     None
 *
 * @details    Ouput selected clock to CKO. The output clock frequency is divided by u32ClkDiv. 
 *             The formula is:
 *                 CKO frequency = (Clock source frequency) / 2^(u32ClkDiv + 1)
 *             This function is just used to set CKO clock.
 *             User must enable I/O for CKO clock output pin by themselves.
 */
static __INLINE void SYS_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    /* CKO = clock source / 2^(u32ClkDiv + 1) */
    SYSCLK->FRQDIV = SYSCLK_FRQDIV_DIVIDER_EN_Msk | u32ClkDiv;

    /* Enable CKO clock source */
    SYSCLK->APBCLK |= SYSCLK_APBCLK_FDIV_EN_Msk;

    /* Select CKO clock source */
    SYSCLK->CLKSEL2 = (SYSCLK->CLKSEL2 & (~SYSCLK_CLKSEL2_FRQDIV_S_Msk)) | u32ClkSrc;
}


/**
 * @brief      Disable CKO clock
 *
 * @return     None
 *
 * @details    Disable CKO clock 
 *
 */
static __INLINE void SYS_DisableCKO(void)
{
    /* Disable CKO clock source */
    SYSCLK->APBCLK &= (~SYSCLK_APBCLK_FDIV_EN_Msk);
}

/**
 * @brief      Initialization for power down (Deep sleep)
 *
 * @details    To inital the power down control registers
 *
 * @note   
 *             User must call SYS_UnlockReg() to unlock protected registers before calling this function 
 */
static __INLINE void SYS_PowerDownInit(void)
{   
    SCB->SCR = SCB_SCR_SLEEPDEEP_Msk;
    SYSCLK->PWRCON |= (SYSCLK_PWRCON_PD_WAIT_CPU_Msk | SYSCLK_PWRCON_PWR_DOWN_EN_Msk | SYSCLK_PWRCON_PD_WU_STS_Msk);
}


/**
 * @brief      Unlock the protected registers
 *
 * @details    To unlock the protected register to allow write access
 *
 */
static __INLINE void SYS_UnlockReg(void)
{   
    do
    {
        SYS->REGWRPROT = 0x59;
        SYS->REGWRPROT = 0x16;
        SYS->REGWRPROT = 0x88;
    }while(SYS->REGWRPROT == 0);
}

/**
 * @brief      Lock the protected registers
 *
 * @details    To lock the protected register to forbid write access
 *
 */
static __INLINE void SYS_LockReg(void)
{   
    SYS->REGWRPROT = 0;
}


/**
  * @} End of SYS Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 


#endif  //__SYS_H__

