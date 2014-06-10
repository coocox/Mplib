/**************************************************************************//**
 * @file     CLK.h
 * @version  V1.0
 * $Revision  1 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 Series CLK Header File
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CLK_H__
#define __CLK_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "NUC400Series.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_CLK_Driver CLK Driver
  @{
*/


/** @addtogroup NUC400_CLK_EXPORTED_TYPEDEF CLK Exported Type Defines
@{
*/

#define FREQ_50MHZ       50000000
#define FREQ_24MHZ       24000000
#define FREQ_22MHZ       22000000
#define FREQ_32KHZ          32767
#define FREQ_10KHZ          10000
/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON constant definitions. PLL = FIN * NF / NR / NO                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PLLCON_PLL_SRC_HIRC (0x1UL<<CLK_PLLCON_PLL_SRC_Pos)        /*!< For PLL clock source is internal RC clock. 4MHz < FIN < 24MHz */
#define CLK_PLLCON_PLL_SRC_HXT  (0x0UL<<CLK_PLLCON_PLL_SRC_Pos)        /*!< For PLL clock source is external crystal.  4MHz < FIN < 24MHz */

#define CLK_PLLCON_NR(x)        (((x)-2)<<9)        /*!< x must be constant and 2 <= x <= 33.  1.6MHz < FIN/NR < 15MHz */
#define CLK_PLLCON_NF(x)         ((x)-2)            /*!< x must be constant and 2 <= x <= 513. 100MHz < FIN*NF/NR < 200MHz. (120MHz < FIN*NF/NR < 200MHz is preferred.) */

#define CLK_PLLCON_NO_1         (0x0UL<<CLK_PLLCON_OUT_DV_Pos)             /*!< For output divider is 1 */
#define CLK_PLLCON_NO_2         (0x1UL<<CLK_PLLCON_OUT_DV_Pos)             /*!< For output divider is 2 */
#define CLK_PLLCON_NO_4         (0x3UL<<CLK_PLLCON_OUT_DV_Pos)             /*!< For output divider is 4 */

#if (__HXT == 12000000)
#define CLK_PLLCON_FOR_I2S      (0xA54)                                                                                     /*!< Predefined PLLCON setting for 147428571.428571Hz PLL output with 12MHz XTAL */
#define CLK_PLLCON_84MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(2) | CLK_PLLCON_NF( 28) | CLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 84MHz PLL output with 12MHz XTAL */
#define CLK_PLLCON_50MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(3) | CLK_PLLCON_NF( 25) | CLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50MHz PLL output with 12MHz XTAL */
#define CLK_PLLCON_48MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(7) | CLK_PLLCON_NF(112) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48MHz PLL output with 12MHz XTAL */
#define CLK_PLLCON_36MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(7) | CLK_PLLCON_NF( 84) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 36MHz PLL output with 12MHz XTAL */
#define CLK_PLLCON_32MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(6) | CLK_PLLCON_NF( 64) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 32MHz PLL output with 12MHz XTAL */
#define CLK_PLLCON_24MHz_HXT   (CLK_PLLCON_PLL_SRC_HXT | CLK_PLLCON_NR(2) | CLK_PLLCON_NF( 16) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 24MHz PLL output with 12MHz XTAL */
#else
# error "The PLL pre-definitions are only valid when external crystal is 12MHz"
#endif

#define CLK_PLLCON_50MHz_HIRC (CLK_PLLCON_FIN_HIRC | CLK_PLLCON_NR(13) | CLK_PLLCON_NF( 59) | CLK_PLLCON_NO_2) /*!< Predefined PLLCON setting for 50.1918MHz PLL output with 22.1184MHz IRC */
#define CLK_PLLCON_48MHz_HIRC (CLK_PLLCON_FIN_HIRC | CLK_PLLCON_NR(13) | CLK_PLLCON_NF(113) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 48.064985MHz PLL output with 22.1184MHz IRC*/
#define CLK_PLLCON_36MHz_HIRC (CLK_PLLCON_FIN_HIRC | CLK_PLLCON_NR(12) | CLK_PLLCON_NF( 78) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 35.9424MHz PLL output with 22.1184MHz IRC */
#define CLK_PLLCON_32MHz_HIRC (CLK_PLLCON_FIN_HIRC | CLK_PLLCON_NR( 9) | CLK_PLLCON_NF( 52) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 31.9488MHz PLL output with 22.1184MHz IRC*/
#define CLK_PLLCON_24MHz_HIRC (CLK_PLLCON_FIN_HIRC | CLK_PLLCON_NR( 3) | CLK_PLLCON_NF( 13) | CLK_PLLCON_NO_4) /*!< Predefined PLLCON setting for 23.9616MHz PLL output with 22.1184MHz IRC*/

/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON2 constant definitions.                                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PLLCON2_USPLL(x)       (((x)-1) << CLK_PLLCON2_USBPLL_N_Pos) /*!< USBPLL clock frequency = (480 MHz) / 2 / (USB_N + 1). It could be 1~256,  Max. PLL frequency :480MHz / 2 when XTL12M. */
#define CLK_PLLCON2_USBPLL_DIS     (0x00UL<<CLK_PLLCON2_USBPLL_EN_Pos)   /*!< USB PHY PLL (480MHz)  Disable */
#define CLK_PLLCON2_USBPLL_EN    (0x01UL<<CLK_PLLCON2_USBPLL_EN_Pos)   /*!< USB PHY PLL (480MHz)  Enable  */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL0 constant definitions.  (Write-protection)                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL0_HCLK_S_HXT         (0x00UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as external XTAL */
#define CLK_CLKSEL0_HCLK_S_LXT         (0x01UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as external XTAL 32.768KHz*/
#define CLK_CLKSEL0_HCLK_S_PLL         (0x02UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as PLL output */
#define CLK_CLKSEL0_HCLK_S_LIRC        (0x03UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as internal 10KHz RC clock */
#define CLK_CLKSEL0_HCLK_S_USBPLL      (0x04UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as USBPLL clock */
#define CLK_CLKSEL0_HCLK_S_HIRC        (0x07UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Setting clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL0_STCLK_S_HXT         (0x00UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting clock source as external XTAL */
#define CLK_CLKSEL0_STCLK_S_LXT      (0x01UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting clock source as external XTAL 32.768KHz*/
#define CLK_CLKSEL0_STCLK_S_HXT_DIV2    (0x02UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting clock source as external XTAL/2 */
#define CLK_CLKSEL0_STCLK_S_HCLK_DIV2    (0x03UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting clock source as HCLK/2 */
#define CLK_CLKSEL0_STCLK_S_HIRC_DIV2  (0x07UL<<CLK_CLKSEL0_STCLK_S_Pos)  /*!< Setting clock source as internal 22.1184MHz RC clock/2 */

#define CLK_CLKSEL0_PCLK_S_HCLK   (0x00UL<<CLK_CLKSEL0_PCLK_S_Pos)    /*!< Setting clock source as HCLK */
#define CLK_CLKSEL0_PCLK_S_HCLK_DIV2  (0x01UL<<CLK_CLKSEL0_PCLK_S_Pos)    /*!< Setting clock source as HCLK/2 */

#define CLK_CLKSEL0_USB_S_PLL   (0x00UL<<CLK_CLKSEL0_USB_S_Pos)    /*!< Setting clock source as PLL  */
#define CLK_CLKSEL0_USB_S_PLL2    (0x01UL<<CLK_CLKSEL0_USB_S_Pos)    /*!< Setting clock source as PLL2 */

#define CLK_CLKSEL0_EMAC_S_HXT   (0x00UL<<CLK_CLKSEL0_EMAC_S_Pos)    /*!< Setting clock source as external XTAL   */
#define CLK_CLKSEL0_EMAC_S_PLL   (0x01UL<<CLK_CLKSEL0_EMAC_S_Pos)    /*!< Setting clock source as PLL */

#define CLK_CLKSEL0_CAP_S_HXT     (0x00UL<<CLK_CLKSEL0_CAP_S_Pos)    /*!< Setting clock source as external XTAL */
#define CLK_CLKSEL0_CAP_S_PLL2    (0x01UL<<CLK_CLKSEL0_CAP_S_Pos)    /*!< Setting clock source as PLL2 */
#define CLK_CLKSEL0_CAP_S_HCLK    (0x02UL<<CLK_CLKSEL0_CAP_S_Pos)    /*!< Setting clock source as HCLK */
#define CLK_CLKSEL0_CAP_S_HIRC    (0x03UL<<CLK_CLKSEL0_CAP_S_Pos)    /*!< Setting clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL0_SDHOST_S_HXT    (0x00UL<<CLK_CLKSEL0_SDHOST_S_Pos)    /*!< Setting clock source as external XTAL */
#define CLK_CLKSEL0_SDHOST_S_PLL    (0x01UL<<CLK_CLKSEL0_SDHOST_S_Pos)    /*!< Setting clock source as PLL2 */
#define CLK_CLKSEL0_SDHOST_S_HCLK   (0x02UL<<CLK_CLKSEL0_SDHOST_S_Pos)    /*!< Setting clock source as HCLK */
#define CLK_CLKSEL0_SDHOST_S_HIRC   (0x03UL<<CLK_CLKSEL0_SDHOST_S_Pos)    /*!< Setting clock source as internal 22.1184MHz RC clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL1_WDT_S_LXT       (0x1UL<<CLK_CLKSEL1_WDT_S_Pos)       /*!< Setting WDT clock source as external XTAL 32.768KHz*/
#define CLK_CLKSEL1_WDT_S_HCLK_DIV2048  (0x2UL<<CLK_CLKSEL1_WDT_S_Pos)       /*!< Setting WDT clock source as HCLK/2048 */
#define CLK_CLKSEL1_WDT_S_LIRC        (0x3UL<<CLK_CLKSEL1_WDT_S_Pos)       /*!< Setting WDT clock source as internal 10KHz RC clock */

#define CLK_CLKSEL1_ADC_S_HXT          (0x0UL<<CLK_CLKSEL1_ADC_S_Pos)       /*!< Setting ADC clock source as external XTAL */
#define CLK_CLKSEL1_ADC_S_PLL           (0x1UL<<CLK_CLKSEL1_ADC_S_Pos)       /*!< Setting ADC clock source as PLL */
#define CLK_CLKSEL1_ADC_S_PCLK          (0x2UL<<CLK_CLKSEL1_ADC_S_Pos)       /*!< Setting ADC clock source as PCLK */
#define CLK_CLKSEL1_ADC_S_HIRC        (0x3UL<<CLK_CLKSEL1_ADC_S_Pos)       /*!< Setting ADC clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_SPI0_S_PLL          (0x0UL<<CLK_CLKSEL1_SPI0_S_Pos)       /*!< Setting SPI0 clock source as PLL */
#define CLK_CLKSEL1_SPI0_S_PCLK         (0x1UL<<CLK_CLKSEL1_SPI0_S_Pos)       /*!< Setting SPI0 clock source as PCLK */

#define CLK_CLKSEL1_SPI1_S_PLL          (0x0UL<<CLK_CLKSEL1_SPI1_S_Pos)       /*!< Setting SPI1 clock source as PLL */
#define CLK_CLKSEL1_SPI1_S_PCLK         (0x1UL<<CLK_CLKSEL1_SPI1_S_Pos)       /*!< Setting SPI1 clock source as PCLK */

#define CLK_CLKSEL1_SPI2_S_PLL          (0x0UL<<CLK_CLKSEL1_SPI2_S_Pos)       /*!< Setting SPI2 clock source as PLL */
#define CLK_CLKSEL1_SPI2_S_PCLK         (0x1UL<<CLK_CLKSEL1_SPI2_S_Pos)       /*!< Setting SPI2 clock source as PCLK */

#define CLK_CLKSEL1_SPI3_S_PLL          (0x0UL<<CLK_CLKSEL1_SPI3_S_Pos)       /*!< Setting SPI3 clock source as PLL */
#define CLK_CLKSEL1_SPI3_S_PCLK         (0x1UL<<CLK_CLKSEL1_SPI3_S_Pos)       /*!< Setting SPI3 clock source as PCLK */

#define CLK_CLKSEL1_TMR0_S_HXT         (0x0UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as external XTAL */
#define CLK_CLKSEL1_TMR0_S_LXT      (0x1UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL1_TMR0_S_PCLK         (0x2UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as PCLK */
#define CLK_CLKSEL1_TMR0_S_EXT      (0x3UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as external trigger */
#define CLK_CLKSEL1_TMR0_S_LIRC       (0x5UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR0_S_HIRC       (0x7UL<<CLK_CLKSEL1_TMR0_S_Pos)       /*!< Setting Timer 0 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_TMR1_S_HXT         (0x0UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as external XTAL */
#define CLK_CLKSEL1_TMR1_S_LXT      (0x1UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL1_TMR1_S_PCLK         (0x2UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as PCLK */
#define CLK_CLKSEL1_TMR1_S_EXT     (0x3UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as external trigger */
#define CLK_CLKSEL1_TMR1_S_LIRC       (0x5UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR1_S_HIRC       (0x7UL<<CLK_CLKSEL1_TMR1_S_Pos)      /*!< Setting Timer 1 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_TMR2_S_HXT         (0x0UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as external XTAL */
#define CLK_CLKSEL1_TMR2_S_LXT      (0x1UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL1_TMR2_S_PCLK         (0x2UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as PCLK */
#define CLK_CLKSEL1_TMR2_S_EXT      (0x3UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as external trigger */
#define CLK_CLKSEL1_TMR2_S_LIRC       (0x5UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR2_S_HIRC       (0x7UL<<CLK_CLKSEL1_TMR2_S_Pos)      /*!< Setting Timer 2 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_TMR3_S_HXT         (0x0UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as external XTAL */
#define CLK_CLKSEL1_TMR3_S_LXT      (0x1UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL1_TMR3_S_PCLK         (0x2UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as PCLK */
#define CLK_CLKSEL1_TMR3_S_EXT     (0x3UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as external trigger */
#define CLK_CLKSEL1_TMR3_S_LIRC       (0x5UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as internal 10KHz RC clock */
#define CLK_CLKSEL1_TMR3_S_HIRC       (0x7UL<<CLK_CLKSEL1_TMR3_S_Pos)      /*!< Setting Timer 3 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_UART_S_HXT         (0x0UL<<CLK_CLKSEL1_UART_S_Pos)      /*!< Setting UART clock source as external XTAL */
#define CLK_CLKSEL1_UART_S_PLL          (0x1UL<<CLK_CLKSEL1_UART_S_Pos)      /*!< Setting UART clock source as external PLL */
#define CLK_CLKSEL1_UART_S_HIRC       (0x3UL<<CLK_CLKSEL1_UART_S_Pos)      /*!< Setting UART clock source as external internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_FRQDIV_S_HXT       (0x0UL<<CLK_CLKSEL1_FRQDIV_S_Pos)      /*!< Setting FRQDIV clock source as external XTAL */
#define CLK_CLKSEL1_FRQDIV_S_LXT    (0x1UL<<CLK_CLKSEL1_FRQDIV_S_Pos)      /*!< Setting FRQDIV clock source as external XTAL 32.768KHz  */
#define CLK_CLKSEL1_FRQDIV_S_HCLK       (0x2UL<<CLK_CLKSEL1_FRQDIV_S_Pos)      /*!< Setting FRQDIV clock source as HCLK */
#define CLK_CLKSEL1_FRQDIV_S_HIRC     (0x3UL<<CLK_CLKSEL1_FRQDIV_S_Pos)      /*!< Setting FRQDIV clock source as external internal 22.1184MHz RC clock */

#define CLK_CLKSEL1_WWDT_S_HCLK_DIV2048  (0x2UL<<CLK_CLKSEL1_WWDT_S_Pos)       /*!< Setting FRQDIV clock source as  HCLK/2048 */
#define CLK_CLKSEL1_WWDT_S_LIRC        (0x3UL<<CLK_CLKSEL1_WWDT_S_Pos)       /*!< Setting FRQDIV clock source as internal 10KHz RC clock  */


/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL2_PWM0CH01_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM0CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as external XTAL */
#define CLK_CLKSEL2_PWM0CH01_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM0CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM0CH01_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM0CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as PCLK */
#define CLK_CLKSEL2_PWM0CH01_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM0CH01_S_Pos)     /*!< Setting PWM0 and PWM1 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM0CH01_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM0CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as internal 10KHz RC clock */

#define CLK_CLKSEL2_PWM0CH23_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM0CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as external XTAL */
#define CLK_CLKSEL2_PWM0CH23_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM0CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM0CH23_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM0CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as PCLK */
#define CLK_CLKSEL2_PWM0CH23_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM0CH23_S_Pos)     /*!< Setting PWM2 and PWM3 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM0CH23_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM0CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as internal 10KHz RC clock */

#define CLK_CLKSEL2_PWM0CH45_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM0CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as external XTAL */
#define CLK_CLKSEL2_PWM0CH45_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM0CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM0CH45_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM0CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as PCLK */
#define CLK_CLKSEL2_PWM0CH45_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM0CH45_S_Pos)     /*!< Setting PWM4 and PWM5 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM0CH45_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM0CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as internal 10KHz RC clock */

#define CLK_CLKSEL2_PWM1CH01_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM1CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as external XTAL */
#define CLK_CLKSEL2_PWM1CH01_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM1CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM1CH01_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM1CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as PCLK */
#define CLK_CLKSEL2_PWM1CH01_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM1CH01_S_Pos)     /*!< Setting PWM0 and PWM1 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM1CH01_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM1CH01_S_Pos)   /*!< Setting PWM0 and PWM1 clock source as internal 10KHz RC clock */

#define CLK_CLKSEL2_PWM1CH23_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM1CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as external XTAL */
#define CLK_CLKSEL2_PWM1CH23_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM1CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM1CH23_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM1CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as PCLK */
#define CLK_CLKSEL2_PWM1CH23_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM1CH23_S_Pos)     /*!< Setting PWM2 and PWM3 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM1CH23_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM1CH23_S_Pos)   /*!< Setting PWM2 and PWM3 clock source as internal 10KHz RC clock */

#define CLK_CLKSEL2_PWM1CH45_S_HXT      (0x0UL<<CLK_CLKSEL2_PWM1CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as external XTAL */
#define CLK_CLKSEL2_PWM1CH45_S_LXT    (0x1UL<<CLK_CLKSEL2_PWM1CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as external XTAL 32.768KHz */
#define CLK_CLKSEL2_PWM1CH45_S_PCLK     (0x2UL<<CLK_CLKSEL2_PWM1CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as PCLK */
#define CLK_CLKSEL2_PWM1CH45_S_HIRC   (0x3UL<<CLK_CLKSEL2_PWM1CH45_S_Pos)     /*!< Setting PWM4 and PWM5 clock source as internal 22.1184MHz RC clock */
#define CLK_CLKSEL2_PWM1CH45_S_LIRC   (0x7UL<<CLK_CLKSEL2_PWM1CH45_S_Pos)   /*!< Setting PWM4 and PWM5 clock source as internal 10KHz RC clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL3 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKSEL3_SC0_S_HXT           (0x0UL<<CLK_CLKSEL3_SC0_S_Pos)      /*!< Setting SC0 clock source as external XTAL */
#define CLK_CLKSEL3_SC0_S_PLL            (0x1UL<<CLK_CLKSEL3_SC0_S_Pos)      /*!< Setting SC0 clock source as PLL */
#define CLK_CLKSEL3_SC0_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC0_S_Pos)      /*!< Setting SC0 clock source as PCLK */
#define CLK_CLKSEL3_SC0_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC0_S_Pos)      /*!< Setting SC0 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_SC1_S_HXT           (0x0UL<<CLK_CLKSEL3_SC1_S_Pos)      /*!< Setting SC1 clock source as external XTAL */
#define CLK_CLKSEL3_SC1_S_PLL            (0x1UL<<CLK_CLKSEL3_SC1_S_Pos)      /*!< Setting SC1 clock source as PLL */
#define CLK_CLKSEL3_SC1_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC1_S_Pos)      /*!< Setting SC1 clock source as PCLK */
#define CLK_CLKSEL3_SC1_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC1_S_Pos)      /*!< Setting SC1 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_SC2_S_HXT           (0x0UL<<CLK_CLKSEL3_SC2_S_Pos)    /*!< Setting SC2 clock source as external XTAL */
#define CLK_CLKSEL3_SC2_S_PLL            (0x1UL<<CLK_CLKSEL3_SC2_S_Pos)      /*!< Setting SC2 clock source as PLL */
#define CLK_CLKSEL3_SC2_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC2_S_Pos)      /*!< Setting SC2 clock source as PCLK */
#define CLK_CLKSEL3_SC2_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC2_S_Pos)      /*!< Setting SC2 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_SC3_S_HXT           (0x0UL<<CLK_CLKSEL3_SC3_S_Pos)      /*!< Setting SC3 clock source as external XTAL */
#define CLK_CLKSEL3_SC3_S_PLL            (0x1UL<<CLK_CLKSEL3_SC3_S_Pos)      /*!< Setting SC3 clock source as PLL */
#define CLK_CLKSEL3_SC3_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC3_S_Pos)      /*!< Setting SC3 clock source as PCLK */
#define CLK_CLKSEL3_SC3_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC3_S_Pos)      /*!< Setting SC3 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_SC4_S_HXT           (0x0UL<<CLK_CLKSEL3_SC4_S_Pos)      /*!< Setting SC4 clock source as external XTAL */
#define CLK_CLKSEL3_SC4_S_PLL            (0x1UL<<CLK_CLKSEL3_SC4_S_Pos)      /*!< Setting SC4 clock source as PLL */
#define CLK_CLKSEL3_SC4_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC4_S_Pos)      /*!< Setting SC4 clock source as PCLK */
#define CLK_CLKSEL3_SC4_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC4_S_Pos)      /*!< Setting SC4 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_SC5_S_HXT           (0x0UL<<CLK_CLKSEL3_SC5_S_Pos)    /*!< Setting SC5 clock source as external XTAL */
#define CLK_CLKSEL3_SC5_S_PLL            (0x1UL<<CLK_CLKSEL3_SC5_S_Pos)      /*!< Setting SC5 clock source as PLL */
#define CLK_CLKSEL3_SC5_S_PCLK           (0x2UL<<CLK_CLKSEL3_SC5_S_Pos)      /*!< Setting SC5 clock source as PCLK */
#define CLK_CLKSEL3_SC5_S_HIRC         (0x3UL<<CLK_CLKSEL3_SC5_S_Pos)      /*!< Setting SC5 clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_I2S_S_HXT           (0x0UL<<CLK_CLKSEL3_I2S_S_Pos)       /*!< Setting I2S clock source as external XTAL */
#define CLK_CLKSEL3_I2S_S_PLL            (0x1UL<<CLK_CLKSEL3_I2S_S_Pos)      /*!< Setting I2S clock source as PLL */
#define CLK_CLKSEL3_I2S_S_PCLK           (0x2UL<<CLK_CLKSEL3_I2S_S_Pos)      /*!< Setting I2S clock source as PCLK */
#define CLK_CLKSEL3_I2S_S_HIRC         (0x3UL<<CLK_CLKSEL3_I2S_S_Pos)      /*!< Setting I2S clock source as internal 22.1184MHz RC clock */

#define CLK_CLKSEL3_I2S1_S_HXT           (0x0UL<<CLK_CLKSEL3_I2S1_S_Pos)    /*!< Setting I2S1 clock source as external XTAL */
#define CLK_CLKSEL3_I2S1_S_PLL            (0x1UL<<CLK_CLKSEL3_I2S1_S_Pos)      /*!< Setting I2S1 clock source as PLL */
#define CLK_CLKSEL3_I2S1_S_PCLK           (0x2UL<<CLK_CLKSEL3_I2S1_S_Pos)      /*!< Setting I2S1 clock source as PCLK */
#define CLK_CLKSEL3_I2S1_S_HIRC         (0x3UL<<CLK_CLKSEL3_I2S1_S_Pos)      /*!< Setting I2S1 clock source as internal 22.1184MHz RC clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV0 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV0_HCLK(x)  (((x)-1) << CLK_CLKDIV0_HCLK_N_Pos)        /*!< CLKDIV Setting for HCLK clock divider. It could be 1~16 */
#define CLK_CLKDIV0_USB(x)   (((x)-1) << CLK_CLKDIV0_USB_N_Pos)     /*!< CLKDIV Setting for USB clock divider. It could be 1~16  */
#define CLK_CLKDIV0_UART(x)  (((x)-1) << CLK_CLKDIV0_UART_N_Pos)      /*!< CLKDIV Setting for UART clock divider. It could be 1~16 */
#define CLK_CLKDIV0_ADC(x)   (((x)-1) << CLK_CLKDIV0_ADC_N_Pos)     /*!< CLKDIV Setting for ADC clock divider. It could be 1~256 */
#define CLK_CLKDIV0_SDHOST(x)  (((x)-1) << CLK_CLKDIV0_SDHOST_N_Pos)      /*!< CLKDIV Setting for SDIO clock divider. It could be 1~256 */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV1_SC0(x)  (((x)-1) << CLK_CLKDIV1_SC0_N_Pos) /*!< CLKDIV Setting for SC0 clock divider. It could be 1~256 */
#define CLK_CLKDIV1_SC1(x)  (((x)-1) << CLK_CLKDIV1_SC1_N_Pos) /*!< CLKDIV Setting for SC1 clock divider. It could be 1~256 */
#define CLK_CLKDIV1_SC2(x)  (((x)-1) << CLK_CLKDIV1_SC2_N_Pos) /*!< CLKDIV Setting for SC2 clock divider. It could be 1~256 */
#define CLK_CLKDIV1_SC3(x)  (((x)-1) << CLK_CLKDIV1_SC3_N_Pos) /*!< CLKDIV Setting for SC3 clock divider. It could be 1~256 */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV2_SC4(x)  (((x)-1) << CLK_CLKDIV2_SC4_N_Pos) /*!< CLKDIV Setting for SC4 clock divider. It could be 1~256 */
#define CLK_CLKDIV2_SC5(x)  (((x)-1) << CLK_CLKDIV2_SC5_N_Pos) /*!< CLKDIV Setting for SC5 clock divider. It could be 1~256 */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV3 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV3_CAP(x)      (((x)-1) << CLK_CLKDIV3_CAP_N_Pos) /*!< CLKDIV Setting for CAP Engine clock divider. It could be 1~256 */
#define CLK_CLKDIV3_VASENSOR(x)   (((x)-1) << CLK_CLKDIV3_VASENSOR_N_Pos) /*!< CLKDIV Setting for Video Pixel clock divider. It could be 1~256 */
#define CLK_CLKDIV3_EMAC_MDCLK(x)  (((x)-1) << CLK_CLKDIV3_EMAC_MDCLK_N_Pos) /*!< CLKDIV Setting for EMAC_MDCLK clock divider. It could be 1~256 */


/*---------------------------------------------------------------------------------------------------------*/
/*  MODULE constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define MODULE_AHPBCLK(x)                  ((x >>30) & 0x3)    /*!< Calculate AHBCLK/APBCLK offset on MODULE index */
#define MODULE_CLKSEL(x)                   ((x >>28) & 0x3)    /*!< Calculate CLKSEL offset on MODULE index */
#define MODULE_CLKSEL_Msk(x)               ((x >>25) & 0x7)    /*!< Calculate CLKSEL mask offset on MODULE index */
#define MODULE_CLKSEL_Pos(x)               ((x >>20) & 0x1f)   /*!< Calculate CLKSEL position offset on MODULE index */
#define MODULE_CLKDIV(x)                   ((x >>18) & 0x3)    /*!< Calculate APBCLK CLKDIV on MODULE index */
#define MODULE_CLKDIV_Msk(x)               ((x >>10) & 0xff)   /*!< Calculate CLKDIV mask offset on MODULE index */
#define MODULE_CLKDIV_Pos(x)               ((x >>5 ) & 0x1f)   /*!< Calculate CLKDIV position offset on MODULE index */
#define MODULE_IP_EN_Pos(x)                ((x >>0 ) & 0x1f)   /*!< Calculate APBCLK offset on MODULE index */
#define MODULE_NoMsk                       0x0                 /*!< Not mask on MODULE index */
/*--------------------------------------------------------------------------------------------------------------------------------------*/
/*   AHBCLK/APBCLK(2) | CLKSEL(2) | CLKSEL_Msk(3) |    CLKSEL_Pos(5)    | CLKDIV(2) | CLKDIV_Msk(8) |     CLKDIV_Pos(5)  |  IP_EN_Pos(5)*/
/*--------------------------------------------------------------------------------------------------------------------------------------*/
#define PDMA_MODULE      ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_PDMA_EN_Pos)     /*!< PDMA Module */
#define ISP_MODULE       ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_ISP_EN_Pos)      /*!< ISP Module */
#define EBI_MODULE       ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_EBI_EN_Pos)      /*!< EBI Module */
#define USBH_MODULE      ((0UL<<30)|(0<<28)|(1<<25)           |( 8<<20)|(0<<18)|(0xF<<10)        |( 4<<5)|CLK_AHBCLK_USBH_EN_Pos)     /*!< USBH Module */
#define EMAC_MODULE      ((0UL<<30)|(0<<28)|(1<<25)           |(10<<20)|(3<<18)|(0xFF<<10)       |(16<<5)|CLK_AHBCLK_EMAC_EN_Pos)     /*!< EMAC Module */
#define SDHOST_MODULE    ((0UL<<30)|(0<<28)|(3<<25)           |(20<<20)|(0<<18)|(0xFF<<10)       |(24<<5)|CLK_AHBCLK_SDHOST_EN_Pos)   /*!< SDHOST Module */
#define CRC_MODULE       ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_CRC_EN_Pos)      /*!< CRC Module */
#define CAP_MODULE       ((0UL<<30)|(0<<28)|(3<<25)           |(16<<20)|(3<<18)|(0xFF<<10)       |( 0<<5)|CLK_AHBCLK_CAP_EN_Pos)      /*!< CAP Module */
#define SENCLK_MODULE    ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(3<<18)|(0xFF<<10)       |( 8<<5)|CLK_AHBCLK_SENCLK_EN_Pos)   /*!< Sensor Clock Module */
#define UDC20_MODULE     ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_UDC20_EN_Pos)    /*!< UDC20 Module */
#define IPSEC_MODULE     ((0UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_AHBCLK_IPSEC_EN_Pos)    /*!< IPSEC Module */

#define WDT_MODULE       ((1UL<<30)|(3<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_WDT_EN_Pos)    /*!< Watchdog Timer Module */
#define WWDT_MODULE      ((1UL<<30)|(1<<28)|(3<<25)           |(30<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_WDT_EN_Pos)    /*!< Window Watchdog Timer Module */
#define RTC_MODULE       ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_RTC_EN_Pos)    /*!< RTC Module */
#define TMR0_MODULE      ((1UL<<30)|(1<<28)|(7<<25)           |( 8<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_TMR0_EN_Pos)   /*!< Timer0 Module */
#define TMR1_MODULE      ((1UL<<30)|(1<<28)|(7<<25)           |(12<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_TMR1_EN_Pos)   /*!< Timer1 Module */
#define TMR2_MODULE      ((1UL<<30)|(1<<28)|(7<<25)           |(17<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_TMR2_EN_Pos)   /*!< Timer2 Module */
#define TMR3_MODULE      ((1UL<<30)|(1<<28)|(7<<25)           |(20<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_TMR3_EN_Pos)   /*!< Timer3 Module */
#define FDIV_MODULE      ((1UL<<30)|(1<<28)|(3<<25)           |(28<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_FDIV_EN_Pos)   /*!< FDIV Module */
#define ACMP_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_ACMP_EN_Pos)   /*!< ACMP Module */
#define I2C0_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2C0_EN_Pos)   /*!< I2C0 Module */
#define I2C1_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2C1_EN_Pos)   /*!< I2C1 Module */
#define I2C2_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2C2_EN_Pos)   /*!< I2C2 Module */
#define I2C3_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2C3_EN_Pos)   /*!< I2C3 Module */
#define SPI0_MODULE      ((1UL<<30)|(1<<28)|(1<<25)           |( 4<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_SPI0_EN_Pos)   /*!< SPI0 Module */
#define SPI1_MODULE      ((1UL<<30)|(1<<28)|(1<<25)           |( 5<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_SPI1_EN_Pos)   /*!< SPI1 Module */
#define SPI2_MODULE      ((1UL<<30)|(1<<28)|(1<<25)           |( 6<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_SPI2_EN_Pos)   /*!< SPI2 Module */
#define SPI3_MODULE      ((1UL<<30)|(1<<28)|(1<<25)           |( 7<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_SPI3_EN_Pos)   /*!< SPI3 Module */
#define UART0_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART0_EN_Pos)  /*!< UART0 Module */
#define UART1_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART1_EN_Pos)  /*!< UART1 Module */
#define UART2_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART2_EN_Pos)  /*!< UART2 Module */
#define UART3_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART3_EN_Pos)  /*!< UART3 Module */
#define UART4_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART4_EN_Pos)  /*!< UART4 Module */
#define UART5_MODULE     ((1UL<<30)|(1<<28)|(3<<25)           |(24<<20)|(0<<18)|(0xF<<10)         |( 8<<5)|CLK_APBCLK0_UART5_EN_Pos)  /*!< UART5 Module */
#define CAN0_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_CAN0_EN_Pos)   /*!< CAN0 Module */
#define CAN1_MODULE      ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_CAN1_EN_Pos)   /*!< CAN1 Module */
#define OTG_MODULE       ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_OTG_EN_Pos)    /*!< OTG Module */
#define ADC_MODULE       ((1UL<<30)|(1<<28)|(3<<25)           |( 2<<20)|(0<<18)|(0xFF<<10)        |(16<<5)|CLK_APBCLK0_ADC_EN_Pos)    /*!< ADC Module */
#define I2S0_MODULE      ((1UL<<30)|(3<<28)|(3<<25)           |(16<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2S0_EN_Pos)   /*!< I2S0 Module */
#define I2S1_MODULE      ((1UL<<30)|(3<<28)|(3<<25)           |(18<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_I2S1_EN_Pos)   /*!< I2S1 Module */
#define PS2_MODULE       ((1UL<<30)|(0<<28)|(MODULE_NoMsk<<25) |( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK0_PS2_EN_Pos)    /*!< PS2 Module */

#define SC0_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |( 0<<20)|(1<<18)|(0xFF<<10)        |( 0<<5)|CLK_APBCLK1_SC0_EN_Pos)    /*!< SmartCard0 Module */
#define SC1_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |( 2<<20)|(1<<18)|(0xFF<<10)        |( 8<<5)|CLK_APBCLK1_SC1_EN_Pos)    /*!< SmartCard1 Module */
#define SC2_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |( 4<<20)|(1<<18)|(0xFF<<10)        |(16<<5)|CLK_APBCLK1_SC2_EN_Pos)    /*!< SmartCard2 Module */
#define SC3_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |( 6<<20)|(1<<18)|(0xFF<<10)        |(24<<5)|CLK_APBCLK1_SC3_EN_Pos)    /*!< SmartCard3 Module */
#define SC4_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |( 8<<20)|(2<<18)|(0xFF<<10)        |( 0<<5)|CLK_APBCLK1_SC4_EN_Pos)    /*!< SmartCard4 Module */
#define SC5_MODULE       ((2UL<<30)|(3<<28)|(3<<25)           |(10<<20)|(2<<18)|(0xFF<<10)        |( 8<<5)|CLK_APBCLK1_SC5_EN_Pos)    /*!< SmartCard5 Module */
#define I2C4_MODULE      ((2UL<<30)|(0<<28)|(0<<25)           |( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_I2C4_EN_Pos)   /*!< I2C4 Module */
#define PWM0CH01_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM0CH01_EN_Pos) /*!< PWM0CH01 Module */
#define PWM0CH23_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |( 4<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM0CH23_EN_Pos) /*!< PWM0CH23 Module */
#define PWM0CH45_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |( 8<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM0CH45_EN_Pos) /*!< PWM0CH45 Module */
#define PWM1CH01_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |(12<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM1CH01_EN_Pos) /*!< PWM1CH01 Module */
#define PWM1CH23_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |(16<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM1CH23_EN_Pos) /*!< PWM1CH23 Module */
#define PWM1CH45_MODULE  ((2UL<<30)|(2<<28)|(7<<25)           |(20<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_PWM1CH45_EN_Pos) /*!< PWM1CH45 Module */
#define QEI0_MODULE      ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_QEI0_EN_Pos)   /*!< QEI0 Module */
#define QEI1_MODULE      ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_QEI1_EN_Pos)   /*!< QEI1 Module */
#define TAMPER_MODULE    ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_TAMPER_EN_Pos) /*!< TAMPER Module */
#define ECAP0_MODULE     ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_ECAP0_EN_Pos)  /*!< ECAP0 Module */
#define ECAP1_MODULE     ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_ECAP1_EN_Pos)  /*!< ECAP1 Module */
#define EPWM0_MODULE     ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_EPWM0_EN_Pos)  /*!< EPWM0 Module */
#define EPWM1_MODULE     ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_EPWM1_EN_Pos)  /*!< EPWM1 Module */
#define OPA_MODULE       ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_OPA_EN_Pos)    /*!< OPA Module */
#define EADC_MODULE      ((2UL<<30)|(0<<28)|(MODULE_NoMsk<<25)|( 0<<20)|(0<<18)|(MODULE_NoMsk<<10)|( 0<<5)|CLK_APBCLK1_EADC_EN_Pos)   /*!< EADC Module */

/*@}*/ /* end of group NUC400_CLK_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_CLK_EXPORTED_FUNCTIONS CLK Exported Functions
  @{
*/

void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetPCLKFreq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_GetPLLClockFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
void CLK_SysTickDelay(uint32_t us);
void CLK_WaitClockReady(uint32_t u32ClkMask);

/*@}*/ /* end of group NUC400_CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_CLK_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__CLK_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
