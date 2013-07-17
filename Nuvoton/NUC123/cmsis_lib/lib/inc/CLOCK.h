/******************************************************************************
 * @file     CLOCK.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/10 1:15p $
 * @brief    NUC123 Series Clock Control Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup CLK_MACRO CLK Macro
  * @{
  */

/** @addtogroup CLK_MACRO_CONTANT CLK Macro Contant
  * @{
  */

/*---------------------------------------------------------------------------------------------------------*/
/*  PWRCON constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PWRCON_PD_WAIT_CPU          (1UL<<CLK_PWRCON_PD_WAIT_CPU_Pos) /*!< Chip entering Power-down mode when the PWR_DOWN_EN bit is set to 1 and CPU run WFI instruction */
#define CLK_PWRCON_PD_NWAIT_CPU         (0UL<<CLK_PWRCON_PD_WAIT_CPU_Pos) /*!< Chip entering Power-down mode when the PWR_DOWN_EN bit is set to 1 */

#define CLK_PWRCON_PD_EN                (1UL<<CLK_PWRCON_PWR_DOWN_EN_Pos) /*!< Enable system power down mode */
#define CLK_PWRCON_PD_DIS               (0UL<<CLK_PWRCON_PWR_DOWN_EN_Pos) /*!< Disable system power down mode */

#define CLK_PWRCON_PD_WU_STS            (1UL<<CLK_PWRCON_PD_WU_STS_Pos) /*!< Power down wake up interrupt flag, write 1 clear */

#define CLK_PWRCON_PD_WU_INT_EN         (1UL<<CLK_PWRCON_PD_WU_INT_EN_Pos) /*!< Enable system power down wake up interrupt */
#define CLK_PWRCON_PD_WU_INT_DIS        (0UL<<CLK_PWRCON_PD_WU_INT_EN_Pos) /*!< Disable system power down wake up interrupt */

#define CLK_PWRCON_PD_WU_DLY_EN         (1UL<<CLK_PWRCON_PD_WU_DLY_Pos) /*!< Enable system power down wake up delay counter */
#define CLK_PWRCON_PD_WU_DLY_DIS        (0UL<<CLK_PWRCON_PD_WU_DLY_Pos) /*!< Disable system power down wake up delay counter */

#define CLK_PWRCON_LIRC_EN              (1UL<<CLK_PWRCON_LIRC_EN_Pos) /*!< Enable internal 10K RC clock */
#define CLK_PWRCON_LIRC_DIS             (0UL<<CLK_PWRCON_LIRC_EN_Pos) /*!< Disable internal 10K RC clock */

#define CLK_PWRCON_HIRC_EN              (1UL<<CLK_PWRCON_HIRC_EN_Pos) /*!< Enable internal 22M RC clock */
#define CLK_PWRCON_HIRC_DIS             (0UL<<CLK_PWRCON_HIRC_EN_Pos) /*!< Disable internal 22M RC clock */

#define CLK_PWRCON_HXT_EN               (1UL<<CLK_PWRCON_HXT_EN_Pos) /*!< Enable external 12M crystal clock */
#define CLK_PWRCON_HXT_DIS              (0UL<<CLK_PWRCON_HXT_EN_Pos) /*!< Disable external 12M crystal clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  AHBCLK constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_ISP                         (1UL<<CLK_AHBCLK_ISP_EN_Pos) /*!< ISP engine clock */
#define CLK_PDMA                        (1UL<<CLK_AHBCLK_PDMA_EN_Pos) /*!< Enable PDMA engine clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  APBCLK constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PS2                         (1UL<<CLK_APBCLK_PS2_EN_Pos) /*!< PS/2 clock */
#define CLK_I2S                         (1UL<<CLK_APBCLK_I2S_EN_Pos) /*!< I2S clock */
#define CLK_ADC                         (1UL<<CLK_APBCLK_ADC_EN_Pos) /*!< ADC clock */
#define CLK_USBD                        (1UL<<CLK_APBCLK_USBD_EN_Pos) /*!< USB device controller clock */
#define CLK_PWM23                       (1UL<<CLK_APBCLK_PWM23_EN_Pos) /*!< PWM23 clock */
#define CLK_PWM01                       (1UL<<CLK_APBCLK_PWM01_EN_Pos) /*!< PWM01 clock */
#define CLK_UART1                       (1UL<<CLK_APBCLK_UART1_EN_Pos) /*!< UART1 clock */
#define CLK_UART0                       (1UL<<CLK_APBCLK_UART0_EN_Pos) /*!< UART0 clock */
#define CLK_SPI2                        (1UL<<CLK_APBCLK_SPI2_EN_Pos) /*!< SPI2 clock */
#define CLK_SPI1                        (1UL<<CLK_APBCLK_SPI1_EN_Pos) /*!< SPI1 clock */
#define CLK_SPI0                        (1UL<<CLK_APBCLK_SPI0_EN_Pos) /*!< SPI0 clock */
#define CLK_I2C1                        (1UL<<CLK_APBCLK_I2C1_EN_Pos) /*!< I2C1 clock */
#define CLK_I2C0                        (1UL<<CLK_APBCLK_I2C0_EN_Pos) /*!< I2C0 clock */
#define CLK_FDIV                        (1UL<<CLK_APBCLK_FDIV_EN_Pos) /*!< FDIV clock */
#define CLK_TMR3                        (1UL<<CLK_APBCLK_TMR3_EN_Pos) /*!< TMR3 clock */
#define CLK_TMR2                        (1UL<<CLK_APBCLK_TMR2_EN_Pos) /*!< TMR2 clock */
#define CLK_TMR1                        (1UL<<CLK_APBCLK_TMR1_EN_Pos) /*!< TMR1 clock */
#define CLK_TMR0                        (1UL<<CLK_APBCLK_TMR0_EN_Pos) /*!< TMR0 clock */
#define CLK_WDT                         (1UL<<CLK_APBCLK_WDT_EN_Pos) /*!< WDT clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSTATUS constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_SW_FAIL                     (1UL<<CLK_CLKSTATUS_CLK_SW_FAIL_Pos) /*!< Clock swithing fail flag */
#define CLK_HIRC_STB                    (1UL<<CLK_CLKSTATUS_HIRC_STB_Pos) /*!< Internal 22M clock source stable flag */
#define CLK_LIRC_STB                    (1UL<<CLK_CLKSTATUS_LIRC_STB_Pos) /*!< Internal 10K clock source stable flag */
#define CLK_PLL_STB                     (1UL<<CLK_CLKSTATUS_PLL_STB_Pos) /*!< Internal PLL clock source stable flag */
#define CLK_HXT_STB                     (1UL<<CLK_CLKSTATUS_HXT_STB_Pos) /*!< External 4~24M clock source stable flag */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL0 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_STCLK_HXT                   (0UL<<CLK_CLKSEL0_STCLK_S_Pos) /*!< Select external 4~24M as M0 SysTick clock source */
#define CLK_STCLK_HXT_2                 (2UL<<CLK_CLKSEL0_STCLK_S_Pos) /*!< Select (external 4~24M)/2 as M0 SysTick clock source */
#define CLK_STCLK_HCLK_2                (3UL<<CLK_CLKSEL0_STCLK_S_Pos) /*!< Select HCLK/2 as M0 SysTick clock source */
#define CLK_STCLK_HIRC_2                (7UL<<CLK_CLKSEL0_STCLK_S_Pos) /*!< Select (internal 22M)/2 as M0 SysTick clock source */

#define CLK_HCLK_HXT                    (0UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Select external 4~24M as HCLK clock source */
#define CLK_HCLK_PLL_2                  (1UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Select PLL/2 as HCLK clock source */
#define CLK_HCLK_PLL                    (2UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Select PLL as HCLK clock source */
#define CLK_HCLK_LIRC                   (3UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Select internal 10K as HCLK clock source */
#define CLK_HCLK_HIRC                   (7UL<<CLK_CLKSEL0_HCLK_S_Pos) /*!< Select internal 22M as HCLK clock source */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PWM23_HXT_L                 (0UL<<CLK_CLKSEL1_PWM23_S_Pos) /*!< Combined with CLKSEL2[9] to select external 4~24M as PWM23 clock source */
#define CLK_PWM23_HCLK_L                (2UL<<CLK_CLKSEL1_PWM23_S_Pos) /*!< Combined with CLKSEL2[9] to select HCLK as PWM23 clock source */
#define CLK_PWM23_HIRC_L                (3UL<<CLK_CLKSEL1_PWM23_S_Pos) /*!< Combined with CLKSEL2[9] to select internal 22M as PWM23 clock source */
#define CLK_PWM23_LIRC_L                (3UL<<CLK_CLKSEL1_PWM23_S_Pos) /*!< Combined with CLKSEL2[9] to select internal 10K as PWM23 clock source */

#define CLK_PWM01_HXT_L                 (0UL<<CLK_CLKSEL1_PWM01_S_Pos) /*!< Combined with CLKSEL2[8] to select external 4~24M as PWM01 clock source */
#define CLK_PWM01_HCLK_L                (2UL<<CLK_CLKSEL1_PWM01_S_Pos) /*!< Combined with CLKSEL2[8] to select HCLK as PWM01 clock source */
#define CLK_PWM01_HIRC_L                (3UL<<CLK_CLKSEL1_PWM01_S_Pos) /*!< Combined with CLKSEL2[8] to select internal 22M as PWM01 clock source */
#define CLK_PWM01_LIRC_L                (3UL<<CLK_CLKSEL1_PWM01_S_Pos) /*!< Combined with CLKSEL2[8] to select internal 10K as PWM01 clock source */

#define CLK_UART_HXT                    (0UL<<CLK_CLKSEL1_UART_S_Pos) /*!< Select external 4~24M as UART clock source */
#define CLK_UART_PLL                    (1UL<<CLK_CLKSEL1_UART_S_Pos) /*!< Select PLL as UART clock source */
#define CLK_UART_HIRC                   (3UL<<CLK_CLKSEL1_UART_S_Pos) /*!< Select internal 22M as UART clock source */

#define CLK_TMR3_HXT                    (0UL<<CLK_CLKSEL1_TMR3_S_Pos) /*!< Select external 4~24M as TMR3 clock source */
#define CLK_TMR3_HCLK                   (2UL<<CLK_CLKSEL1_TMR3_S_Pos) /*!< Select HCLK as TMR3 clock source */
#define CLK_TMR3_LIRC                   (4UL<<CLK_CLKSEL1_TMR3_S_Pos) /*!< Select internal 10K as TMR3 clock source */
#define CLK_TMR3_HIRC                   (7UL<<CLK_CLKSEL1_TMR3_S_Pos) /*!< Select internal 22M as TMR3 clock source */

#define CLK_TMR2_HXT                    (0UL<<CLK_CLKSEL1_TMR2_S_Pos) /*!< Select external 4~24M as TMR2 clock source */
#define CLK_TMR2_HCLK                   (2UL<<CLK_CLKSEL1_TMR2_S_Pos) /*!< Select HCLK as TMR2 clock source */
#define CLK_TMR2_TM2                    (3UL<<CLK_CLKSEL1_TMR2_S_Pos) /*!< Select external clock source to TM2 pin as TMR2 clock source */
#define CLK_TMR2_LIRC                   (4UL<<CLK_CLKSEL1_TMR2_S_Pos) /*!< Select internal 10K as TMR2 clock source */
#define CLK_TMR2_HIRC                   (7UL<<CLK_CLKSEL1_TMR2_S_Pos) /*!< Select internal 22M as TMR2 clock source */

#define CLK_TMR1_HXT                    (0UL<<CLK_CLKSEL1_TMR1_S_Pos) /*!< Select external 4~24M as TMR1 clock source */
#define CLK_TMR1_HCLK                   (2UL<<CLK_CLKSEL1_TMR1_S_Pos) /*!< Select HCLK as TMR1 clock source */
#define CLK_TMR1_TM1                    (3UL<<CLK_CLKSEL1_TMR1_S_Pos) /*!< Select external clock source to TM1 pin as TMR1 clock source */
#define CLK_TMR1_LIRC                   (4UL<<CLK_CLKSEL1_TMR1_S_Pos) /*!< Select internal 10K as TMR1 clock source */
#define CLK_TMR1_HIRC                   (7UL<<CLK_CLKSEL1_TMR1_S_Pos) /*!< Select internal 22M as TMR1 clock source */

#define CLK_TMR0_HXT                    (0UL<<CLK_CLKSEL1_TMR0_S_Pos) /*!< Select external 4~24M as TMR0 clock source */
#define CLK_TMR0_HCLK                   (2UL<<CLK_CLKSEL1_TMR0_S_Pos) /*!< Select HCLK as TMR0 clock source */
#define CLK_TMR0_TM0                    (3UL<<CLK_CLKSEL1_TMR0_S_Pos) /*!< Select external clock source to TM0 pin as TMR0 clock source */
#define CLK_TMR0_LIRC                   (4UL<<CLK_CLKSEL1_TMR0_S_Pos) /*!< Select internal 10K as TMR0 clock source */
#define CLK_TMR0_HIRC                   (7UL<<CLK_CLKSEL1_TMR0_S_Pos) /*!< Select internal 22M as TMR0 clock source */

#define CLK_SPI2_HCLK                   (1UL<<CLK_CLKSEL1_SPI2_S_Pos) /*!< Select HCLK as SPI2 clock source */
#define CLK_SPI2_PLL                    (0UL<<CLK_CLKSEL1_SPI2_S_Pos) /*!< Select PLL as SPI2 clock source */

#define CLK_SPI1_HCLK                   (1UL<<CLK_CLKSEL1_SPI1_S_Pos) /*!< Select HCLK as SPI1 clock source */
#define CLK_SPI1_PLL                    (0UL<<CLK_CLKSEL1_SPI1_S_Pos) /*!< Select PLL as SPI1 clock source */

#define CLK_SPI0_HCLK                   (1UL<<CLK_CLKSEL1_SPI0_S_Pos) /*!< Select HCLK as SPI0 clock source */
#define CLK_SPI0_PLL                    (0UL<<CLK_CLKSEL1_SPI0_S_Pos) /*!< Select PLL as SPI0 clock source */

#define CLK_ADC_HXT                     (0UL<<CLK_CLKSEL1_ADC_S_Pos) /*!< Select external 4~24M as ADC clock source */
#define CLK_ADC_PLL                     (1UL<<CLK_CLKSEL1_ADC_S_Pos) /*!< Select PLL as ADC clock source */
#define CLK_ADC_HCLK                    (2UL<<CLK_CLKSEL1_ADC_S_Pos) /*!< Select HCLK as ADC clock source */
#define CLK_ADC_HIRC                    (3UL<<CLK_CLKSEL1_ADC_S_Pos) /*!< Select internal 22M as ADC clock source */

#define CLK_WDT_HCLK_2048               (2UL<<CLK_CLKSEL1_WDT_S_Pos) /*!< Select HCLK/2048 as WDT clock source */
#define CLK_WDT_LIRC                    (3UL<<CLK_CLKSEL1_WDT_S_Pos) /*!< Select internal 10K as WDT clock source */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKSEL2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_WWDT_HCLK_2048              (2UL<<CLK_CLKSEL2_WWDT_S_Pos) /*!< Select HCLK/2048 as WWDT clock source */
#define CLK_WWDT_LIRC                   (3UL<<CLK_CLKSEL2_WWDT_S_Pos) /*!< Select internal 10K as WWDT clock source */

#define CLK_PWM23_HXT_H                 (0UL<<CLK_CLKSEL2_PWM23_S_EXT_Pos) /*!< Combined with CLKSEL1[31:30] to select external 4~24M as PWM23 clock source */
#define CLK_PWM23_HCLK_H                (0UL<<CLK_CLKSEL2_PWM23_S_EXT_Pos) /*!< Combined with CLKSEL2[31:30] to select HCLK as PWM23 clock source */
#define CLK_PWM23_HIRC_H                (0UL<<CLK_CLKSEL2_PWM23_S_EXT_Pos) /*!< Combined with CLKSEL2[31:30] to select internal 22M as PWM23 clock source */
#define CLK_PWM23_LIRC_H                (1UL<<CLK_CLKSEL2_PWM23_S_EXT_Pos) /*!< Combined with CLKSEL2[31:30] to select internal 10K as PWM23 clock source */

#define CLK_PWM01_HXT_H                 (0UL<<CLK_CLKSEL2_PWM01_S_EXT_Pos) /*!< Combined with CLKSEL2[29:28] to select external 4~24M as PWM01 clock source */
#define CLK_PWM01_HCLK_H                (0UL<<CLK_CLKSEL2_PWM01_S_EXT_Pos) /*!< Combined with CLKSEL2[29:28] to select HCLK as PWM01 clock source */
#define CLK_PWM01_HIRC_H                (0UL<<CLK_CLKSEL2_PWM01_S_EXT_Pos) /*!< Combined with CLKSEL2[29:28] to select internal 22M as PWM01 clock source */
#define CLK_PWM01_LIRC_H                (1UL<<CLK_CLKSEL2_PWM01_S_EXT_Pos) /*!< Combined with CLKSEL2[29:28] to select internal 10K as PWM01 clock source */

#define CLK_FDIV_HXT                    (0UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Select external 4~24M as clock divider clock source */
#define CLK_FDIV_HCLK                   (2UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Select HCLK as clock divider clock source */
#define CLK_FDIV_HIRC                   (3UL<<CLK_CLKSEL2_FRQDIV_S_Pos) /*!< Select internal 22M as clock divider clock source */

#define CLK_I2S_HXT                     (0UL<<CLK_CLKSEL2_I2S_S_Pos) /*!< Select external 4~24M as I2S clock source */
#define CLK_I2S_PLL                     (1UL<<CLK_CLKSEL2_I2S_S_Pos) /*!< Select PLL as I2S clock source */
#define CLK_I2S_HCLK                    (2UL<<CLK_CLKSEL2_I2S_S_Pos) /*!< Select HCLK as I2S clock source */
#define CLK_I2S_HIRC                    (3UL<<CLK_CLKSEL2_I2S_S_Pos) /*!< Select internal 22M as I2S clock source */

/*---------------------------------------------------------------------------------------------------------*/
/*  CLKDIV constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_CLKDIV_ADC(x)               (((x)-1)<<CLK_CLKDIV_ADC_N_Pos) /*!< CLKDIV Setting for ADC clock divider. It could be 1~256 */
#define CLK_CLKDIV_UART(x)              (((x)-1)<<CLK_CLKDIV_UART_N_Pos) /*!< CLKDIV Setting for UART clock divider. It could be 1~16 */
#define CLK_CLKDIV_USB(x)               (((x)-1)<<CLK_CLKDIV_USB_N_Pos) /*!< CLKDIV Setting for USBD clock divider. It could be 1~16 */
#define CLK_CLKDIV_HCLK(x)              (((x)-1)<<CLK_CLKDIV_HCLK_N_Pos) /*!< CLKDIV Setting for HCLK clock divider. It could be 1~16 */

/*---------------------------------------------------------------------------------------------------------*/
/*  PLLCON constant definitions. PLL = FIN * NF / NR / NO                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_PLLSRC_HIRC                 (1UL<<CLK_PLLCON_PLL_SRC_Pos) /*!< For PLL clock source is internal RC clock. FIN = 22.1184MHz */ 
#define CLK_PLLSRC_HXT                  (0UL<<CLK_PLLCON_PLL_SRC_Pos) /*!< For PLL clock source is external cristal.  4MHz < FIN < 24MHz */
#define CLK_PLLSRC(x)                   ((x))                         /*!< Select clock source for PLL */

#define CLK_PLLCON_OUTP_DIS             (1UL<<CLK_PLLCON_OE_Pos) /*!< PLL output is fixed low */ 
#define CLK_PLLCON_OUTP_EN              (0UL<<CLK_PLLCON_OE_Pos) /*!< PLL output enable */

#define CLK_PLLCON_BP_EN                (1UL<<CLK_PLLCON_BP_Pos) /*!< PLL output is the same as FIN */
#define CLK_PLLCON_BP_DIS               (0UL<<CLK_PLLCON_BP_Pos) /*!< PLL output is in normal mode */

#define CLK_PLLCON_PD_EN                (1UL<<CLK_PLLCON_PD_Pos) /*!< PLL is in power down mode */
#define CLK_PLLCON_PD_DIS               (0UL<<CLK_PLLCON_PD_Pos) /*!< PLL is in normal mode */

#define CLK_PLLCON_NO_1                 (0UL<<CLK_PLLCON_OUT_DV_Pos) /*!< For output divider is 1 */
#define CLK_PLLCON_NO_2                 (1UL<<CLK_PLLCON_OUT_DV_Pos) /*!< For output divider is 2 */
#define CLK_PLLCON_NO_4                 (3UL<<CLK_PLLCON_OUT_DV_Pos) /*!< For output divider is 4 */

#define CLK_PLLCON_NR(x)                (((x)-2)<<CLK_PLLCON_IN_DV_Pos) /*!< x must be constant and 2 <= x <= 33.  1.6MHz < FIN/NR < 16MHz */
#define CLK_PLLCON_NF(x)                (((x)-2)<<CLK_PLLCON_FB_DV_Pos) /*!< x must be constant and 2 <= x <= 513. 100MHz < FIN*NF/NR < 200MHz. (120MHz < FIN*NF/NR < 200MHz is preferred.) */ 

/*---------------------------------------------------------------------------------------------------------*/
/*  FRQDIV constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_FDIV_EN                     (1UL<<CLK_FRQDIV_DIVIDER_EN_Pos) /*!< Frequency divider enable */ 
#define CLK_FDIV_DIS                    (0UL<<CLK_FRQDIV_DIVIDER_EN_Pos) /*!< Frequency divider disable */ 
#define CLK_FDIV_FSEL(x)                (((x)-1)<<CLK_FRQDIV_FSEL_Pos) /*!< x must be constant and 1<= x <= 16. Fout = Fin/(2^(x)) */ 

/*---------------------------------------------------------------------------------------------------------*/
/*  APBDIV constant definitions.                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_APBDIV_DIV2                 (1UL<<CLK_APBDIV_APBDIV_Pos) /*!< PCLK = HCLK/2 */
#define CLK_APBDIV_DIV1                 (0UL<<CLK_APBDIV_APBDIV_Pos) /*!< PCLK = HCLK */

/*@}*/ /* end of group CLK_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup CLK_MACRO_FUNC CLK Macro Func
  @{
*/
/**
 * @brief      Wait cpu before entering power down
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Chip entering Power-down mode when both PD_WAIT_CPU and PWR_DOWN_EN bits
 *             are set to 1 and CPU run WFI instruction
 */
static __INLINE void CLK_PD_WAIT_CPU(void)
{
    CLK->PWRCON |= CLK_PWRCON_PD_WAIT_CPU;
}

/**
 * @brief      Do not wait cpu to before entering power down
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Chip entering Power-down mode when the PWR_DOWN_EN bit is set to 1
 */
static __INLINE void CLK_PD_NWAIT_CPU(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_PD_WAIT_CPU_Msk);
}

/**
 * @brief      Enable system power down
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable system power down
 */
static __INLINE void CLK_PD_ENABLE(void)
{
    CLK->PWRCON |= CLK_PWRCON_PD_EN;
}

/**
 * @brief      Disable system power down
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable system power down
 */
static __INLINE void CLK_PD_DISABLE(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_PWR_DOWN_EN_Msk);
}

/**
 * @brief      Get power down wake up interrupt status
 *
 * @param      None
 *
 * @retval     FALSE  No power down wake up interrupt
 * @retval     TRUE   Power down wake up interrupt occured
 *
 * @details    Get power down wake up interrupt status
 */
static __INLINE uint32_t CLK_GET_PD_WU_STS(void)
{
    return (CLK->PWRCON & CLK_PWRCON_PD_WU_STS_Msk);
}

/**
 * @brief      Clear power down wake up interrupt status
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Clear power down wake up interrupt status
 */
static __INLINE void CLK_CLR_PD_WU_STS(void)
{
    CLK->PWRCON |= CLK_PWRCON_PD_WU_STS_Msk;
}

/**
 * @brief      Enable power down wake up interrupt
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable power down wake up interrupt
 */	
static __INLINE void CLK_PD_WU_INT_EN(void)
{
    CLK->PWRCON |= CLK_PWRCON_PD_WU_INT_EN;
}

/**
 * @brief      Disable power down wake up interrupt
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable power down wake up interrupt
 */
static __INLINE void CLK_PD_WU_INT_DIS(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_PD_WU_INT_EN_Msk);
}

/**
 * @brief      Enable power down wake up delay counter
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable power down wake up delay counter
 */
static __INLINE void CLK_PD_WU_DLY_EN(void)
{
    CLK->PWRCON |= CLK_PWRCON_PD_WU_DLY_EN;
}

/**
 * @brief      Disable power down wake up delay counter
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable power down wake up delay counter
 */
static __INLINE void CLK_PD_WU_DLY_DIS(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_PD_WU_DLY_Msk);
}

/**
 * @brief      Enable internal 10K oscillator
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable internal 10K oscillator
 */
static __INLINE void CLK_LIRC_ENABLE(void)
{
    CLK->PWRCON |= CLK_PWRCON_LIRC_EN;
}

/**
 * @brief      Disable internal 10K oscillator.
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable internal 10K oscillator.
 */
static __INLINE void CLK_LIRC_DISABLE(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_LIRC_EN_Msk);
}

/**
 * @brief      Enable internal 22M oscillator.
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable internal 22M oscillator.
 */
static __INLINE void CLK_HIRC_ENABLE(void)
{
    CLK->PWRCON |= CLK_PWRCON_HIRC_EN;
}

/**
 * @brief      Disable internal 22M oscillator.
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable internal 22M oscillator.
 */
static __INLINE void CLK_HIRC_DISABLE(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_HIRC_EN_Msk);
}

/**
 * @brief      Enable external 4~24M crystal.
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable external 4~24M crystal.
 */
static __INLINE void CLK_HXT_ENABLE(void)
{
    CLK->PWRCON |= CLK_PWRCON_HXT_EN;
}

/**
 * @brief      Disable external 4~24M crystal.
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable external 4~24M crystal.
 */
static __INLINE void CLK_HXT_DISABLE(void)
{
    CLK->PWRCON &= (~CLK_PWRCON_HXT_EN_Msk);
}

/**
 * @brief      Check if clock switch failed
 *
 * @param      None
 *
 * @retval     FALSE  Clock switch is succeed
 * @retval     TRUE   Clock switch is failed
 *
 * @details    Check if clock switch failed
 */
static __INLINE uint32_t CLK_IS_SW_FAIL(void)
{
    return (CLK->CLKSTATUS & CLK_CLKSTATUS_CLK_SW_FAIL_Msk);
}

/**
 * @brief      Clear clock switch fail flag
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Clear clock switch fail flag
 */
static __INLINE void CLK_CLR_SW_FAIL(void)
{
    CLK->CLKSTATUS = CLK_CLKSTATUS_CLK_SW_FAIL_Msk;
}

/**
 * @brief      Check if specified clock source stable
 *
 * @param[in]  src  Clock source to be checked. It could be
 *                  CLK_HIRC_STB
 *                  CLK_LIRC_STB
 *                  CLK_PLL_STB
 *                  CLK_HXT_STB
 *
 * @retval     FALSE  Specified clock source is not stable
 * @retval     TRUE   Specified clock source is stable
 *
 * @details    Check if specified clock source stable
 */
static __INLINE uint32_t CLK_IS_STABLE(uint32_t src)
{
    return (CLK->CLKSTATUS & (src));
}

/**
 * @brief      Enable specified AHB Clocks.
 *
 * @param[in]  AHB clock to be enabled, can use seperatly or 'OR' combined:
 *             CLK_ISP
 *             CLK_PDMA
 *
 * @return     None
 *
 * @details    To enable specified AHB clocks
 */
static __INLINE void AHBCLK_ENABLE(uint32_t clk)
{
    CLK->AHBCLK |= (clk);
}

/**
 * @brief      Disable specified AHB Clocks.
 *
 * @param[in]  AHB clock to be enabled, can use seperatly or 'OR' combined:
 *             CLK_ISP
 *             CLK_PDMA
 *
 * @return     None
 *
 * @details    To disable specified AHB clocks
 */
static __INLINE void AHBCLK_DISABLE(uint32_t clk)
{
    CLK->AHBCLK &= (~(clk));
}

/**
 * @brief      Enable specified APB Clock.
 *
 * @param[in]  APB clock to be enabled, can use seperatly or 'OR' combined:
 *             CLK_PS2
 *             CLK_I2S
 *             CLK_ADC
 *             CLK_USBD
 *             CLK_PWM23
 *             CLK_PWM01
 *             CLK_UART1
 *             CLK_UART0
 *             CLK_SPI2
 *             CLK_SPI1
 *             CLK_SPI0
 *             CLK_I2C1
 *             CLK_I2C0
 *             CLK_FDIV
 *             CLK_TMR3
 *             CLK_TMR2
 *             CLK_TMR1
 *             CLK_TMR0
 *             CLK_WDT
 *
 * @return     None
 *
 * @details    To enable specified APB clocks
 */
static __INLINE void APBCLK_ENABLE(uint32_t clk)
{
    CLK->APBCLK |= (clk);
}

/**
 * @brief      Disable specified APB Clocks.
 *
 * @param[in]  APB clock to be enabled, can use seperatly or 'OR' combined:
 *             CLK_PS2
 *             CLK_I2S
 *             CLK_ADC
 *             CLK_USBD
 *             CLK_PWM23
 *             CLK_PWM01
 *             CLK_UART1
 *             CLK_UART0
 *             CLK_SPI2
 *             CLK_SPI1
 *             CLK_SPI0
 *             CLK_I2C1
 *             CLK_I2C0
 *             CLK_FDIV
 *             CLK_TMR3
 *             CLK_TMR2
 *             CLK_TMR1
 *             CLK_TMR0
 *             CLK_WDT
 *
 * @return     None
 *
 * @details    To disable specified APB clocks
 */
static __INLINE void APBCLK_DISABLE(uint32_t clk)
{
    CLK->APBCLK &= (~(clk));
}

/**
 * @brief      Select clock source for SysTick.
 *
 * @param      Possible clock source for SysTic. Including:
 *             CLK_STCLK_HXT
 *             CLK_STCLK_HXT_2
 *             CLK_STCLK_HCLK_2
 *             CLK_STCLK_HIRC_2
 *
 * @return     None
 *
 * @details    To select a required clock source for SysTick.
 */
static __INLINE void SET_SYSTICK_CLKSRC(uint32_t src)
{
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_STCLK_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for MCU.
 *
 * @param      Possible clock source for HCLK. Including:
 *             CLK_HCLK_HXT
 *             CLK_HCLK_PLL_2
 *             CLK_HCLK_PLL
 *             CLK_HCLK_LIRC
 *             CLK_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for MCU.
 */
static __INLINE void SET_HCLK_CLKSRC(uint32_t src)
{
    CLK->CLKSEL0 = (CLK->CLKSEL0 & (~CLK_CLKSEL0_HCLK_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for PWM2 and PWM3.
 *
 * @param      Possible clock source for PWM23, must used in pairs. Including (src_l, src_h):
 *             (CLK_PWM23_HXT_L, CLK_PWM23_HXT_H)
 *             (CLK_PWM23_HCLK_L,   CLK_PWM23_HCLK_H)
 *             (CLK_PWM23_HIRC_L, CLK_PWM23_HIRC_H)
 *             (CLK_PWM23_LIRC_L, CLK_PWM23_LIRC_H)
 *
 * @return     None
 *
 * @details    To select a required clock source for PWM23, PWM2 and PWM3 share the same clock source.
 */
static __INLINE void SET_PWM23_CLKSRC(uint32_t src_l, uint32_t src_h)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_PWM23_S_Msk)) | (src_l);
    CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_PWM23_S_EXT_Msk)) | (src_h);
}

/**
 * @brief      Select clock source for PWM0 and PWM1.
 *
 * @param      Possible clock source for PWM01, must used in pairs. Including (src_l, src_h):
 *             (CLK_PWM01_HXT_L, CLK_PWM01_HXT_H)
 *             (CLK_PWM01_HCLK_L,   CLK_PWM01_HCLK_H)
 *             (CLK_PWM01_HIRC_L, CLK_PWM01_HIRC_H)
 *             (CLK_PWM01_LIRC_L, CLK_PWM01_LIRC_H)
 *
 * @return     None
 *
 * @details    To select a required clock source for PWM01, PWM0 and PWM1 share the same clock source.
 */
static __INLINE void SET_PWM01_CLKSRC(uint32_t src_l, uint32_t src_h)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_PWM01_S_Msk)) | (src_l);
    CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_PWM01_S_EXT_Msk)) | (src_h);
}

/**
 * @brief      Select clock source for UART.
 *
 * @param      Possible clock source for UART. Including:
 *             CLK_UART_HXT
 *             CLK_UART_PLL
 *             CLK_UART_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for UART.
 */
static __INLINE void SET_UART_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_UART_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for Timer 3.
 *
 * @param      Possible clock source for TMR3. Including:
 *             CLK_TMR3_HXT
 *             CLK_TMR3_HCLK
 *             CLK_TMR3_LIRC
 *             CLK_TMR3_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for Timer 3.
 */
static __INLINE void SET_TMR3_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_TMR3_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for Timer 2.
 *
 * @param      Possible clock source for TMR2. Including:
 *             CLK_TMR2_HXT
 *             CLK_TMR2_HCLK
 *             CLK_TMR2_TM2
 *             CLK_TMR2_LIRC
 *             CLK_TMR2_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for Timer 2.
 */
static __INLINE void SET_TMR2_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_TMR2_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for Timer 1.
 *
 * @param      Possible clock source for TMR1. Including:
 *             CLK_TMR1_HXT
 *             CLK_TMR1_HCLK
 *             CLK_TMR1_TM2
 *             CLK_TMR1_LIRC
 *             CLK_TMR1_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for Timer 1.
 */
static __INLINE void SET_TMR1_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_TMR1_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for Timer 0.
 *
 * @param      Possible clock source for TMR0. Including:
 *             CLK_TMR0_HXT
 *             CLK_TMR0_HCLK
 *             CLK_TMR0_TM2
 *             CLK_TMR0_LIRC
 *             CLK_TMR0_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for Timer 0.
 */
static __INLINE void SET_TMR0_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_TMR0_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for SPI 2.
 *
 * @param      Possible clock source for SPI2. Including:
 *             CLK_SPI2_HCLK
 *             CLK_SPI2_PLL
 *
 * @return     None
 *
 * @details    To select a required clock source for SPI 2.
 */
static __INLINE void SET_SPI2_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_SPI2_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for SPI 1.
 *
 * @param      Possible clock source for SPI1. Including:
 *             CLK_SPI1_HCLK
 *             CLK_SPI1_PLL
 *
 * @return     None
 *
 * @details    To select a required clock source for SPI 1.
 */
static __INLINE void SET_SPI1_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_SPI1_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for SPI 0.
 *
 * @param      Possible clock source for SPI0. Including:
 *             CLK_SPI0_HCLK
 *             CLK_SPI0_PLL
 *
 * @return     None
 *
 * @details    To select a required clock source for SPI 0.
 */
static __INLINE void SET_SPI0_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_SPI0_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for ADC.
 *
 * @param      Possible clock source for ADC. Including:
 *             CLK_ADC_HXT
 *             CLK_ADC_PLL
 *             CLK_ADC_HCLK
 *             CLK_ADC_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for ADC.
 */
static __INLINE void SET_ADC_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_ADC_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for WDT.
 *
 * @param      Possible clock source for WDT. Including:
 *             CLK_WDT_HCLK_2048
 *             CLK_WDT_LIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for WDT.
 */
static __INLINE void SET_WDT_CLKSRC(uint32_t src)
{
    CLK->CLKSEL1 = (CLK->CLKSEL1 & (~CLK_CLKSEL1_WDT_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for WWDT.
 *
 * @param      Possible clock source for WWDT. Including:
 *             CLK_WWDT_HCLK_2048
 *             CLK_WWDT_LIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for WWDT.
 */
static __INLINE void SET_WWDT_CLKSRC(uint32_t src)
{
    CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_WWDT_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for clock divider.
 *
 * @param      Possible clock source for clock divider. Including:
 *             CLK_FDIV_HXT
 *             CLK_FDIV_HCLK
 *             CLK_FDIV_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for clock divider.
 */
static __INLINE void SET_FDIV_CLKSRC(uint32_t src)
{
    CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_FRQDIV_S_Msk)) | (src);
}

/**
 * @brief      Select clock source for I2S.
 *
 * @param      Possible clock source for I2S. Including:
 *             CLK_I2S_HXT
 *             CLK_I2S_PLL
 *             CLK_I2S_HCLK
 *             CLK_I2S_HIRC
 *
 * @return     None
 *
 * @details    To select a required clock source for I2S.
 */
static __INLINE void SET_I2S_CLKSRC(uint32_t src)
{
    CLK->CLKSEL2 = (CLK->CLKSEL2 & (~CLK_CLKSEL2_I2S_S_Msk)) | (src);
}

/**
 * @brief      Set ADC clock divider number.
 *
 * @param      Divider number ADC_N: must be 1~256
 *
 * @return     None
 *
 * @details    Set ADC clock divider number from ADC clock source.
 *             ADC clock frequency = (ADC clock source frequency) / (ADC_N + 1).
 */
static __INLINE void SET_ADC_CLKDIV(uint32_t div)
{
    CLK->CLKDIV = (CLK->CLKDIV & (~CLK_CLKDIV_ADC_N_Msk)) | CLK_CLKDIV_ADC(div);
}

/**
 * @brief      Set UART clock divider number.
 *
 * @param      Divider number UART_N: must be 1~16
 *
 * @return     None
 *
 * @details    Set UART clock divider number from UART clock source.
 *             UART clock frequency = (UART clock source frequency) / (UART_N + 1).
 */
static __INLINE void SET_UART_CLKDIV(uint32_t div)
{
    CLK->CLKDIV = (CLK->CLKDIV & (~CLK_CLKDIV_UART_N_Msk)) | CLK_CLKDIV_UART(div);
}

/**
 * @brief      Set USB clock divider number.
 *
 * @param      Divider number USB_N: must be 1~16
 *
 * @return     None
 *
 * @details    Set USB clock divider number from PLL.
 *             USB clock frequency = (PLL frequency) / (USB_N + 1).
 */
static __INLINE void SET_USB_CLKDIV(uint32_t div)
{
    CLK->CLKDIV = (CLK->CLKDIV & (~CLK_CLKDIV_USB_N_Msk)) | CLK_CLKDIV_USB(div);
}

/**
 * @brief      Set HCLK clock divider number.
 *
 * @param      Divider number HCLK_N: must be 1~16
 *
 * @return     None
 *
 * @details    Set HCLK clock divider number from HCLK clock source.
 *             HCLK clock frequency = (HCLK clock source frequency) / (HCLK_N + 1).
 */
static __INLINE void SET_HCLK_CLKDIV(uint32_t div)
{
    CLK->CLKDIV = (CLK->CLKDIV & (~CLK_CLKDIV_HCLK_N_Msk)) | CLK_CLKDIV_HCLK(div);
}

/**
 * @brief      Select clock source for PLL.
 *
 * @param      Possible clock source for PLL. Including:
 *             CLK_PLLSRC_HIRC
 *             CLK_PLLSRC_HXT
 *
 * @return     None
 *
 * @details    To select a required clock source for PLL.
 */
static __INLINE void SET_PLL_CLKSRC(uint32_t src)
{
    CLK->PLLCON = (CLK->PLLCON & (~CLK_PLLCON_PLL_SRC_Msk)) | (src);
}

/**
 * @brief      Enable PLL output
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable PLL output
 */
static __INLINE void CLK_PLL_OUTP_EN(void)
{
    CLK->PLLCON &= (~CLK_PLLCON_OE_Msk);
}

/**
 * @brief      Disable PLL output
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable PLL output
 */
static __INLINE void CLK_PLL_OUTP_DIS(void)
{
    CLK->PLLCON |= CLK_PLLCON_OUTP_DIS;
}

/**
 * @brief      Bypass PLL
 *
 * @param      None
 *
 * @return     None
 *
 * @details    PLL clock output is the same as clock input
 */
static __INLINE void CLK_PLL_BP_EN(void)
{
    CLK->PLLCON |= CLK_PLLCON_BP_EN;
}

/**
 * @brief      Do not bypass PLL
 *
 * @param      None
 *
 * @return     None
 *
 * @details    PLL is in Normal mode
 */
static __INLINE void CLK_PLL_BP_DISABLE(void)
{
    CLK->PLLCON &= (~CLK_PLLCON_BP_Msk);
}

/**
 * @brief      Enable PLL power down mode
 *
 * @param      None
 *
 * @return     None
 *
 * @details    PLL enter power down mode
 */
static __INLINE void CLK_PLL_PD_EN(void)
{
    CLK->PLLCON |= CLK_PLLCON_PD_EN;
}

/**
 * @brief      Disable PLL power down mode
 *
 * @param      None
 *
 * @return     None
 *
 * @details    PLL is in Normal mode
 */
static __INLINE void CLK_PLL_PD_DISABLE(void)
{
    CLK->PLLCON &= (~CLK_PLLCON_PD_Msk);
}

/**
 * @brief      Set PLL output divider number.
 *
 * @param      Divider number NO. including:
 *             CLK_PLLCON_NO_1
 *             CLK_PLLCON_NO_2
 *             CLK_PLLCON_NO_4
 *
 * @return     None
 *
 * @details    Set PLL output divider number.
 *             PLL = FIN * NF / NR / NO.
 */
static __INLINE void CLK_SET_PLL_NO(uint32_t div_no)
{
    CLK->PLLCON = (CLK->PLLCON & (~CLK_PLLCON_OUT_DV_Msk)) | (div_no);
}

/**
 * @brief      Set PLL input divider number.
 *
 * @param      Divider number NR: must be 2~33
 *
 * @return     None
 *
 * @details    Set PLL input divider number.
 *             PLL = FIN * NF / NR / NO.
 */
static __INLINE void CLK_SET_PLL_NR(uint32_t div_nr)
{
    CLK->PLLCON = (CLK->PLLCON & (~CLK_PLLCON_IN_DV_Msk)) | CLK_PLLCON_NR(div_nr);
}

/**
 * @brief      Set PLL feedback divider number.
 *
 * @param      Divider number NF: must be 2~513
 *
 * @return     None
 *
 * @details    Set PLL feedback divider number.
 *             PLL = FIN * NF / NR / NO.
 */
static __INLINE void CLK_SET_PLL_NF(uint32_t div_nf)
{
    CLK->PLLCON = (CLK->PLLCON & (~CLK_PLLCON_FB_DV_Msk)) | CLK_PLLCON_NF(div_nf);
}

/**
 * @brief      Set PLLCON register
 *
 * @param[in]  src  PLL clock source. It could be CLK_PLLSRC_HIRC, CLK_PLLSRC_HXT
 * @param[in]  pll  The combination of OUT_DV, IN_DV and FB_DV in PLLCON register, which is used
 *                  to calculate the PLL output frequency
 *
 * @return     None
 *
 * @details    Set PLLCON register to get required PLL output frequency
 *             Before call the macro, please use PLL Generator Tool, which is placed in directory
 *             NUC123SeriesBSP\Tool, to calculate the PLL setting, and use the setting as
 *             the pll parameter of the macro
 */
static __INLINE void CLK_SET_PLL_FRQ(uint32_t src, uint32_t pll)
{
    CLK->PLLCON = CLK_PLLSRC(src) | (pll);
}

/**
 * @brief      Enable frequency divider
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Enable frequency divider
 */
static __INLINE void CLK_FDIV_ENABLE(void)
{
    CLK->FRQDIV |= CLK_FDIV_EN;
}

/**
 * @brief      Disable frequency divider
 *
 * @param      None
 *
 * @return     None
 *
 * @details    Disable frequency divider
 */
static __INLINE void CLK_FDIV_DISABLE(void)
{
    CLK->FRQDIV &= (~CLK_FRQDIV_DIVIDER_EN_Msk);
}

/**
 * @brief      Set divider output frequency divider number.
 *
 * @param      Divider number N: must be 1~16
 *
 * @return     None
 *
 * @details    Set divider output frequency divider number.
 *             Fout = Fin / (2^N).
 */
static __INLINE void CLK_SET_FDIV(uint32_t div)
{
    CLK->FRQDIV = (CLK->FRQDIV & (~CLK_FRQDIV_FSEL_Msk)) | CLK_FDIV_FSEL(div);
}

/**
 * @brief      Set APBCLK divider number.
 *
 * @param      Divider number. including:
 *             CLK_APBDIV_DIV1
 *             CLK_APBDIV_DIV2
 *
 * @return     None
 *
 * @details    Set APBCLK divider number.
 *             CLK_APBDIV_DIV1: PCLK = HCLK.
 *             CLK_APBDIV_DIV2: PCLK = HCLK/2.
 */
static __INLINE void CLK_SET_APBDIV(uint32_t div)
{
    CLK->APBDIV = (CLK->APBDIV & (~CLK_APBDIV_APBDIV_Msk)) | (div);
}

/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

/**
 * @brief      Get PLL Clock Output Frequency  
 *
 * @param      None
 *
 * @return     PLL clock output frequency 
 *
 * @details    To get actual PLL clock output frequency. The clock uint is in Hz.
 */
static __INLINE uint32_t CLK_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4}; /* OUT_DV :DEF: {1, 2, 2, 4} */
    uint32_t u32Reg;

    u32PllFreq = 0;
    u32Reg = CLK->PLLCON;
    if((u32Reg & (CLK_PLLCON_PD_Msk | CLK_PLLCON_OE_Msk)) == 0)
    {    
        /* PLL is enabled and output enabled */

        u32FIN = (u32Reg & CLK_PLLCON_PLL_SRC_Msk)?__IRC22M:__XTAL;
        if(u32Reg & CLK_PLLCON_BP_Msk)
        {
            /* PLL is in bypass mode */
            u32PllFreq = u32FIN;
        }
        else 
        {
            /* PLL is in normal work mode */
            u32NO = au8NoTbl[((u32Reg & CLK_PLLCON_OUT_DV_Msk) >> CLK_PLLCON_OUT_DV_Pos)];
            u32NF = ((u32Reg & CLK_PLLCON_FB_DV_Msk) >> CLK_PLLCON_FB_DV_Pos) + 2;
            u32NR = ((u32Reg & CLK_PLLCON_IN_DV_Msk) >> CLK_PLLCON_IN_DV_Pos) + 2;
            /* u32FIN is shifted 2 bits to avoid overflow */
            u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2); 
        }
    }

    return u32PllFreq;
}


/**
 * @brief      Get system Clock Frequency  
 *
 * @param      None
 *
 * @return     System clock frequency 
 *
 * @details    To get current system clock frequency. The clock uint is in Hz.
 */
static __INLINE uint32_t CLK_GetHCLKFreq(void)
{
    uint32_t u32Freqout = 0, u32AHBDivider, u32ClkSel;
    
    u32ClkSel = CLK->CLKSEL0 & CLK_CLKSEL0_HCLK_S_Msk;

    if (u32ClkSel == CLK_HCLK_HXT)         /* external crystal clock */
    {
        u32Freqout = __XTAL;    
    }
    else if((u32ClkSel == CLK_HCLK_PLL) || (u32ClkSel == CLK_HCLK_PLL_2)) /* PLL clock/2 */
    {
        u32Freqout = CLK_GetPLLClockFreq();
        if(u32ClkSel == CLK_HCLK_PLL_2)
            u32Freqout /= 2;
    }
    else if(u32ClkSel == CLK_HCLK_LIRC)    /* internal 10KHz oscillator clock */
    {
        u32Freqout = __IRC10K;
    }
    else                                   /* internal 22MHz oscillator clock */
    {
        u32Freqout = __IRC22M;
    
    }
    u32AHBDivider = (CLK->CLKDIV & CLK_CLKDIV_HCLK_N_Msk) + 1 ;
    
    return (u32Freqout/u32AHBDivider);
}

/*@}*/ /* end of group CLK_MACRO_FUNC */
/*@}*/ /* end of group CLK_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */


#endif
