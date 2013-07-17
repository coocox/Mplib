/******************************************************************************
 * @file     PDMA.h
 * @version  V1.0
 * $Revision: 1 $
 * $Date: 12/08/16 09:48a $
 * @brief    NUC123 Series PDMA Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __PDMA_H__
#define __PDMA_H__

#include "NUC123Series.h"

/** @addtogroup NUC123_MACRO_FUNC NUC123 IPs Macro
  * @{
  */

/** @addtogroup PDMA_MACRO PDMA Macro
  * @{
  */

/** @addtogroup PDMA_MACRO_CONTANT PDMA Macro Contant
  * @{
  */
/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA_CSRx constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_TRIG_EN                    (1UL<<PDMA_CSR_TRIG_EN_Pos) /*!< PDMA data read or write transfer Enabled */

#define PDMA_APB_TWS_32BIT              (0UL<<PDMA_CSR_APB_TWS_Pos) /*!< One word (32-bit) is transferred for each PDMA operation */
#define PDMA_APB_TWS_8BIT               (1UL<<PDMA_CSR_APB_TWS_Pos) /*!< One byte (8-bit) is transferred for each PDMA operation */
#define PDMA_APB_TWS_16BIT              (2UL<<PDMA_CSR_APB_TWS_Pos) /*!< One half word (16-bit) is transferred for each PDMA operation */

#define PDMA_DAD_INC                    (0UL<<PDMA_CSR_DAD_SEL_Pos) /*!< Transfer destination address is increasing successively */
#define PDMA_DAD_FIXED                  (2UL<<PDMA_CSR_DAD_SEL_Pos) /*!< Transfer destination address is fixed */

#define PDMA_SAD_INC                    (0UL<<PDMA_CSR_SAD_SEL_Pos) /*!< Transfer source address is increasing successively */
#define PDMA_SAD_FIXED                  (2UL<<PDMA_CSR_SAD_SEL_Pos) /*!< Transfer source address is fixed */

#define PDMA_MD_MEM2MEM                 (0UL<<PDMA_CSR_MODE_SEL_Pos) /*!< Memory to Memory mode */
#define PDMA_MD_APB2MEM                 (1UL<<PDMA_CSR_MODE_SEL_Pos) /*!< Peripheral to Memory mode */
#define PDMA_MD_MEM2APB                 (2UL<<PDMA_CSR_MODE_SEL_Pos) /*!< Memory to Peripheral mode */

#define PDMA_SW_RST                     (1UL<<PDMA_CSR_SW_RST_Pos) /*!< Reset PDMA internal state machine, pointers and internal buffer. Contents of control register will not be cleared */

#define PDMA_CH_EN                      (1UL<<PDMA_CSR_PDMACEN_Pos) /*!< Enables PDMA¡¯s operation */

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA_IERx constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_BLKD_INT_EN                (1UL<<PDMA_ISR_BLKD_IE_Pos) /*!< Enable PDMA transfer done interrupt */
#define PDMA_BLKD_INT_DIS               (0UL<<PDMA_ISR_BLKD_IE_Pos) /*!< Disable PDMA transfer done interrupt */

#define PDMA_TABORT_INT_EN              (1UL<<PDMA_IER_TABORT_IE_Pos) /*!< Enable PDMA transfer target abort interrupt */
#define PDMA_TABORT_INT_DIS             (0UL<<PDMA_IER_TABORT_IE_Pos) /*!< Disable PDMA transfer target abort interrupt */

/*---------------------------------------------------------------------------------------------------------*/
/*  PDMA_ISRx constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_BLKD_IF                    (1UL<<PDMA_ISR_BLKD_IF_Pos) /*!< PDMA transfer done interrupt flag */
#define PDMA_TABORT_IF                  (1UL<<PDMA_ISR_TABORT_IF_Pos) /*!< PDMA transfer target abort interrupt flag */

/*---------------------------------------------------------------------------------------------------------*/
/*  DMA_GCRCSR constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_CRC_CLK_EN                 (1UL<<PDMA_GCRCSR_CRC_CLK_EN_Pos) /*!< Enable CRC controller clock */
#define PDMA_CRC_CLK_DIS                (0UL<<PDMA_GCRCSR_CRC_CLK_EN_Pos) /*!< Disable CRC controller clock */

#define PDMA_CH5_CLK                    (1UL<<PDMA_GCRCSR_CLK5_EN_Pos) /*!< PDMA controller channel 5 clock */
#define PDMA_CH4_CLK                    (1UL<<PDMA_GCRCSR_CLK4_EN_Pos) /*!< PDMA controller channel 4 clock */
#define PDMA_CH3_CLK                    (1UL<<PDMA_GCRCSR_CLK3_EN_Pos) /*!< PDMA controller channel 3 clock */
#define PDMA_CH2_CLK                    (1UL<<PDMA_GCRCSR_CLK2_EN_Pos) /*!< PDMA controller channel 2 clock */
#define PDMA_CH1_CLK                    (1UL<<PDMA_GCRCSR_CLK1_EN_Pos) /*!< PDMA controller channel 1 clock */
#define PDMA_CH0_CLK                    (1UL<<PDMA_GCRCSR_CLK0_EN_Pos) /*!< PDMA controller channel 0 clock */

/*---------------------------------------------------------------------------------------------------------*/
/*  DMA_PDSSR0 constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_SPI2_TX_CH0                (0UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 0 */
#define PDMA_SPI2_TX_CH1                (1UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 1 */
#define PDMA_SPI2_TX_CH2                (2UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 2 */
#define PDMA_SPI2_TX_CH3                (3UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 3 */
#define PDMA_SPI2_TX_CH4                (4UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 4 */
#define PDMA_SPI2_TX_CH5                (5UL<<PDMA_PDSSR0_SPI2_TXSEL_Pos) /*!< Connect SPI2_TX to PDMA channel 5 */

#define PDMA_SPI2_RX_CH0                (0UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 0 */
#define PDMA_SPI2_RX_CH1                (1UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 1 */
#define PDMA_SPI2_RX_CH2                (2UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 2 */
#define PDMA_SPI2_RX_CH3                (3UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 3 */
#define PDMA_SPI2_RX_CH4                (4UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 4 */
#define PDMA_SPI2_RX_CH5                (5UL<<PDMA_PDSSR0_SPI2_RXSEL_Pos) /*!< Connect SPI2_RX to PDMA channel 5 */

#define PDMA_SPI1_TX_CH0                (0UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 0 */
#define PDMA_SPI1_TX_CH1                (1UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 1 */
#define PDMA_SPI1_TX_CH2                (2UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 2 */
#define PDMA_SPI1_TX_CH3                (3UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 3 */
#define PDMA_SPI1_TX_CH4                (4UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 4 */
#define PDMA_SPI1_TX_CH5                (5UL<<PDMA_PDSSR0_SPI1_TXSEL_Pos) /*!< Connect SPI1_TX to PDMA channel 5 */

#define PDMA_SPI1_RX_CH0                (0UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 0 */
#define PDMA_SPI1_RX_CH1                (1UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 1 */
#define PDMA_SPI1_RX_CH2                (2UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 2 */
#define PDMA_SPI1_RX_CH3                (3UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 3 */
#define PDMA_SPI1_RX_CH4                (4UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 4 */
#define PDMA_SPI1_RX_CH5                (5UL<<PDMA_PDSSR0_SPI1_RXSEL_Pos) /*!< Connect SPI1_RX to PDMA channel 5 */

#define PDMA_SPI0_TX_CH0                (0UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 0 */
#define PDMA_SPI0_TX_CH1                (1UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 1 */
#define PDMA_SPI0_TX_CH2                (2UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 2 */
#define PDMA_SPI0_TX_CH3                (3UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 3 */
#define PDMA_SPI0_TX_CH4                (4UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 4 */
#define PDMA_SPI0_TX_CH5                (5UL<<PDMA_PDSSR0_SPI0_TXSEL_Pos) /*!< Connect SPI0_TX to PDMA channel 5 */

#define PDMA_SPI0_RX_CH0                (0UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 0 */
#define PDMA_SPI0_RX_CH1                (1UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 1 */
#define PDMA_SPI0_RX_CH2                (2UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 2 */
#define PDMA_SPI0_RX_CH3                (3UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 3 */
#define PDMA_SPI0_RX_CH4                (4UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 4 */
#define PDMA_SPI0_RX_CH5                (5UL<<PDMA_PDSSR0_SPI0_RXSEL_Pos) /*!< Connect SPI0_RX to PDMA channel 5 */

/*---------------------------------------------------------------------------------------------------------*/
/*  DMA_PDSSR1 constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_ADC_RX_CH0                 (0UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 0 */
#define PDMA_ADC_RX_CH1                 (1UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 1 */
#define PDMA_ADC_RX_CH2                 (2UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 2 */
#define PDMA_ADC_RX_CH3                 (3UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 3 */
#define PDMA_ADC_RX_CH4                 (4UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 4 */
#define PDMA_ADC_RX_CH5                 (5UL<<PDMA_PDSSR1_ADC_RXSEL_Pos) /*!< Connect ADC_RX to PDMA channel 5 */

#define PDMA_UART1_TX_CH0               (0UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 0 */
#define PDMA_UART1_TX_CH1               (1UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 1 */
#define PDMA_UART1_TX_CH2               (2UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 2 */
#define PDMA_UART1_TX_CH3               (3UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 3 */
#define PDMA_UART1_TX_CH4               (4UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 4 */
#define PDMA_UART1_TX_CH5               (5UL<<PDMA_PDSSR1_UART1_TXSEL_Pos) /*!< Connect UART1_TX to PDMA channel 5 */

#define PDMA_UART1_RX_CH0               (0UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 0 */
#define PDMA_UART1_RX_CH1               (1UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 1 */
#define PDMA_UART1_RX_CH2               (2UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 2 */
#define PDMA_UART1_RX_CH3               (3UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 3 */
#define PDMA_UART1_RX_CH4               (4UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 4 */
#define PDMA_UART1_RX_CH5               (5UL<<PDMA_PDSSR1_UART1_RXSEL_Pos) /*!< Connect UART1_RX to PDMA channel 5 */

#define PDMA_UART0_TX_CH0               (0UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 0 */
#define PDMA_UART0_TX_CH1               (1UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 1 */
#define PDMA_UART0_TX_CH2               (2UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 2 */
#define PDMA_UART0_TX_CH3               (3UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 3 */
#define PDMA_UART0_TX_CH4               (4UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 4 */
#define PDMA_UART0_TX_CH5               (5UL<<PDMA_PDSSR1_UART0_TXSEL_Pos) /*!< Connect UART0_TX to PDMA channel 5 */

#define PDMA_UART0_RX_CH0               (0UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 0 */
#define PDMA_UART0_RX_CH1               (1UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 1 */
#define PDMA_UART0_RX_CH2               (2UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 2 */
#define PDMA_UART0_RX_CH3               (3UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 3 */
#define PDMA_UART0_RX_CH4               (4UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 4 */
#define PDMA_UART0_RX_CH5               (5UL<<PDMA_PDSSR1_UART0_RXSEL_Pos) /*!< Connect UART0_RX to PDMA channel 5 */

/*---------------------------------------------------------------------------------------------------------*/
/*  DMA_GCRISR constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_INTR_STS                   (1UL<<PDMA_GCRISR_INTR_Pos) /*!< Interrupt status of PDMA controller */
#define PDMA_INTRCRC_STS                (1UL<<PDMA_GCRISR_INTRCRC_Pos) /*!< Interrupt status of CRC controller */
#define PDMA_INTR5_STS                  (1UL<<PDMA_GCRISR_INTR5_Pos) /*!< Interrupt status of PDMA channel 5 */
#define PDMA_INTR4_STS                  (1UL<<PDMA_GCRISR_INTR4_Pos) /*!< Interrupt status of PDMA channel 4 */
#define PDMA_INTR3_STS                  (1UL<<PDMA_GCRISR_INTR3_Pos) /*!< Interrupt status of PDMA channel 3 */
#define PDMA_INTR2_STS                  (1UL<<PDMA_GCRISR_INTR2_Pos) /*!< Interrupt status of PDMA channel 2 */
#define PDMA_INTR1_STS                  (1UL<<PDMA_GCRISR_INTR1_Pos) /*!< Interrupt status of PDMA channel 1 */
#define PDMA_INTR0_STS                  (1UL<<PDMA_GCRISR_INTR0_Pos) /*!< Interrupt status of PDMA channel 0 */

/*---------------------------------------------------------------------------------------------------------*/
/*  DMA_PDSSR2 constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_PWM3_RX_CH0                (0UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 0 */
#define PDMA_PWM3_RX_CH1                (1UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 1 */
#define PDMA_PWM3_RX_CH2                (2UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 2 */
#define PDMA_PWM3_RX_CH3                (3UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 3 */
#define PDMA_PWM3_RX_CH4                (4UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 4 */
#define PDMA_PWM3_RX_CH5                (5UL<<PDMA_PDSSR2_PWM3_RXSEL_Pos) /*!< Connect PWM3_RX to PDMA channel 5 */

#define PDMA_PWM2_RX_CH0                (0UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 0 */
#define PDMA_PWM2_RX_CH1                (1UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 1 */
#define PDMA_PWM2_RX_CH2                (2UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 2 */
#define PDMA_PWM2_RX_CH3                (3UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 3 */
#define PDMA_PWM2_RX_CH4                (4UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 4 */
#define PDMA_PWM2_RX_CH5                (5UL<<PDMA_PDSSR2_PWM2_RXSEL_Pos) /*!< Connect PWM2_RX to PDMA channel 5 */

#define PDMA_PWM1_RX_CH0                (0UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 0 */
#define PDMA_PWM1_RX_CH1                (1UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 1 */
#define PDMA_PWM1_RX_CH2                (2UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 2 */
#define PDMA_PWM1_RX_CH3                (3UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 3 */
#define PDMA_PWM1_RX_CH4                (4UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 4 */
#define PDMA_PWM1_RX_CH5                (5UL<<PDMA_PDSSR2_PWM1_RXSEL_Pos) /*!< Connect PWM1_RX to PDMA channel 5 */

#define PDMA_PWM0_RX_CH0                (0UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 0 */
#define PDMA_PWM0_RX_CH1                (1UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 1 */
#define PDMA_PWM0_RX_CH2                (2UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 2 */
#define PDMA_PWM0_RX_CH3                (3UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 3 */
#define PDMA_PWM0_RX_CH4                (4UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 4 */
#define PDMA_PWM0_RX_CH5                (5UL<<PDMA_PDSSR2_PWM0_RXSEL_Pos) /*!< Connect PWM0_RX to PDMA channel 5 */

#define PDMA_I2S_TX_CH0                 (0UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 0 */
#define PDMA_I2S_TX_CH1                 (1UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 1 */
#define PDMA_I2S_TX_CH2                 (2UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 2 */
#define PDMA_I2S_TX_CH3                 (3UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 3 */
#define PDMA_I2S_TX_CH4                 (4UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 4 */
#define PDMA_I2S_TX_CH5                 (5UL<<PDMA_PDSSR2_I2S_TXSEL_Pos) /*!< Connect I2S_TX to PDMA channel 5 */

#define PDMA_I2S_RX_CH0                 (0UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 0 */
#define PDMA_I2S_RX_CH1                 (1UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 1 */
#define PDMA_I2S_RX_CH2                 (2UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 2 */
#define PDMA_I2S_RX_CH3                 (3UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 3 */
#define PDMA_I2S_RX_CH4                 (4UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 4 */
#define PDMA_I2S_RX_CH5                 (5UL<<PDMA_PDSSR2_I2S_RXSEL_Pos) /*!< Connect I2S_RX to PDMA channel 5 */

/*---------------------------------------------------------------------------------------------------------*/
/*  Misc constant definitions.                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_BLKD_INT                   (1UL<<PDMA_ISR_BLKD_IF_Pos) /*!< PDMA transfer done interrupt flag */
#define PDMA_TABORT_INT                 (1UL<<PDMA_ISR_TABORT_IF_Pos) /*!< PDMA transfer target abort interrupt flag */

/*---------------------------------------------------------------------------------------------------------*/
/*  Structure definitions.                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
typedef struct DRVPDMA_STRUCT						/* PDMA structure */
{
    uint32_t u32SrcCtrl;    /* Source Control */
    uint32_t u32SrcAddr;    /* Source address */
    uint32_t u32DestCtrl;   /* Destination Control */
    uint32_t u32DestAddr;   /* Destination address */
    uint32_t u32TransWidth; /* Transfer Width */
    uint32_t u32Mode;       /* Operation Mode */
    uint32_t u32ByteCnt;    /* Byte Count */
}STR_PDMA_T;

/*@}*/ /* end of group PDMA_MACRO_CONTANT */

/*---------------------------------------------------------------------------------------------------------*/
/* Macro functions                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/** @addtogroup PDMA_MACRO_FUNC PDMA Macro Func
  @{
*/
/**
 * @brief       Enable PDMA transfer
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      None
 *
 * @details     Enable PDMA read or write transfer of specified channel
 */
static __INLINE void PDMA_TRG_ENABLE(PDMA_T *CH)
{
    (CH)->CSR |= PDMA_TRIG_EN;
}

/**
 * @brief       Set PDMA transfer width
 *
 * @param[in]   CH     PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   width  PDMA transfer width. It could be PDMA_APB_TWS_32BIT, PDMA_APB_TWS_8BIT, PDMA_APB_TWS_16BIT
 *
 * @return      None
 *
 * @details     Set PDMA transfer width of specified channel
 */
static __INLINE void PDMA_SET_APB_WIDTH(PDMA_T *CH, uint32_t width)
{
    (CH)->CSR = ((CH)->CSR & (~PDMA_CSR_APB_TWS_Msk)) | (width);
}

/**
 * @brief       Set PDMA destination address direction
 *
 * @param[in]   CH   PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   dir  PDMA address direction. It could be PDMA_DAD_INC, PDMA_DAD_FIXED
 *
 * @return      None
 *
 * @details     Set PDMA destination address direction of specified channel
 */
static __INLINE void PDMA_SET_DEST_DIR(PDMA_T *CH, uint32_t dir)
{
    (CH)->CSR = ((CH)->CSR & (~PDMA_CSR_DAD_SEL_Msk)) | (dir);
}

/**
 * @brief       Set PDMA source address direction
 *
 * @param[in]   CH   PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   dir  PDMA address direction. It could be PDMA_SAD_INC, PDMA_SAD_FIXED
 *
 * @return      None
 *
 * @details     Set PDMA source address direction of specified channel
 */
static __INLINE void PDMA_SET_SOURCE_DIR(PDMA_T *CH, uint32_t dir)
{
    (CH)->CSR = ((CH)->CSR & (~PDMA_CSR_SAD_SEL_Msk)) | (dir);
}

/**
 * @brief       Set PDMA transfer mode
 *
 * @param[in]   CH     PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   mode  PDMA transfer mode. It could be PDMA_MD_MEM2MEM, PDMA_MD_APB2MEM, PDMA_MD_MEM2APB
 *
 * @return      None
 *
 * @details     Set PDMA transfer mode of specified channel
 */
static __INLINE void PDMA_SET_MODE(PDMA_T *CH, uint32_t mode)
{
    (CH)->CSR = ((CH)->CSR & (~PDMA_CSR_MODE_SEL_Msk)) | (mode);
}

/**
 * @brief       PDMA software engine reset
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      None
 *
 * @details     Reset the internal state machine, pointers and internal buffer. \n
 *              The contents of control register will not be cleared. \n
 *              This bit will be automatically cleared after few clock cycles
 */
static __INLINE void PDMA_SW_RESET(PDMA_T *CH)
{
    (CH)->CSR |= PDMA_SW_RST;
}

/**
 * @brief       Enable PDMA channel
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      None
 *
 * @details     Enable specified PDMA channel
 */
static __INLINE void PDMA_CH_ENABLE(PDMA_T *CH)
{
    (CH)->CSR |= PDMA_CH_EN;
}

/**
 * @brief       Set PDMA transfer source address
 *
 * @param[in]   CH    PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   addr  PDMA transfer 32-bit address, must word aligned
 *
 * @return      None
 *
 * @details     Set PDMA transfer source address of specified channel
 */
static __INLINE void PDMA_SET_SRC_ADDR(PDMA_T *CH, uint32_t addr)
{
    (CH)->SAR = ((addr) & 0xFFFFFFFCUL);
}

/**
 * @brief       Set PDMA transfer destination address
 *
 * @param[in]   CH    PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   addr  PDMA transfer 32-bit address, must word aligned
 *
 * @return      None
 *
 * @details     Set PDMA transfer destination address of specified channel
 */
static __INLINE void PDMA_SET_DEST_ADDR(PDMA_T *CH, uint32_t addr)
{
    (CH)->DAR = ((addr) & 0xFFFFFFFCUL);
}

/**
 * @brief       Set PDMA transfer byte count
 *
 * @param[in]   CH   PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   cnt  PDMA transfer 16-bit byte count
 *
 * @return      None
 *
 * @details     Set PDMA transfer byte count of specified channel
 */
static __INLINE void PDMA_SET_TRANS_CNT(PDMA_T *CH, uint32_t cnt)
{
    (CH)->BCR = (cnt);
}

/**
 * @brief       Get PDMA internal buffer pointer
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      PDMA internal buffer pointer
 *
 * @details     Get PDMA internal buffer pointer of specified channel
 */
static __INLINE uint32_t PDMA_GET_INTERNAL_BUF_POINT(PDMA_T *CH)
{
    return ((CH)->POINT);
}

/**
 * @brief       Get PDMA current source address
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      Source address where the PDMA transfer just occurs
 *
 * @details     Get PDMA current source address of specified channel
 */
static __INLINE uint32_t PDMA_GET_CURRENT_SRC_ADDR(PDMA_T *CH)
{
    return ((CH)->CSAR);
}

/**
 * @brief       Get PDMA current destination address
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      Destination address where the PDMA transfer just occurs
 *
 * @details     Get PDMA current destination address of specified channel
 */
static __INLINE uint32_t PDMA_GET_CURRENT_DEST_ADDR(PDMA_T *CH)
{
    return ((CH)->CDAR);
}

/**
 * @brief       Get PDMA current transfer count
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      The current remained byte count of PDMA
 *
 * @details     Get PDMA current transfer count of specified channel
 */
static __INLINE uint32_t PDMA_GET_REMAINED_CNT(PDMA_T *CH)
{
    return ((CH)->CBCR);
}

/**
 * @brief       Enable PDMA interrupt
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   Type of interrupt of PDMA. It could be
 *              PDMA_BLKD_INT, PDMA_TABORT_INT and their 'OR' combination (PDMA_BLKD_INT | PDMA_TABORT_INT)
 *
 * @return      None
 *
 * @details     Enable specified PDMA interrupt of specified channel
 */
static __INLINE void PDMA_INT_ENABLE(PDMA_T *CH, uint32_t intr)
{
    (CH)->IER |= (intr);
}

/**
 * @brief       Disable PDMA interrupt
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   Type of interrupt of PDMA. It could be
 *              PDMA_BLKD_INT, PDMA_TABORT_INT and their 'OR' combination (PDMA_BLKD_INT | PDMA_TABORT_INT)
 *
 * @return      None
 *
 * @details     Disable specified PDMA interrupt of specified channel
 */
static __INLINE void PDMA_INT_DISABLE(PDMA_T *CH, uint32_t intr)
{
    (CH)->IER &= ~(intr);
}

/**
 * @brief       Get PDMA interrupt status
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   Type of interrupt of PDMA. It could be PDMA_BLKD_INT, PDMA_TABORT_INT
 *
 * @retval      FALSE  No interrupt
 * @retval      TRUE   Specified interrupt occured
 *
 * @details     Get specified PDMA interrupt status of specified channel
 */
static __INLINE uint32_t PDMA_GET_IF(PDMA_T *CH, uint32_t intr)
{
    return ((CH)->ISR & (intr));
}

/**
 * @brief       Clear PDMA interrupt status
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 * @param[in]   Type of interrupt of PDMA. It could be
 *              PDMA_BLKD_INT, PDMA_TABORT_INT and their 'OR' combination (PDMA_BLKD_INT | PDMA_TABORT_INT)
 *
 * @return      None
 *
 * @details     Clear specified PDMA interrupt status of specified channel
 */
static __INLINE void PDMA_CLR_IF(PDMA_T *CH, uint32_t intr)
{
    (CH)->ISR = (intr);
}

/**
 * @brief       Get PDMA shared buffer FIFO 0
 *
 * @param[in]   CH  PDMA channel struct pointer. It could be PDMA0, PDMA1, PDMA2, PDMA3, PDMA4, PDMA5
 *
 * @return      Internal buffer of specified PDMA channel
 *
 * @details     Get PDMA shared buffer FIFO 0 of specified channel
 */
static __INLINE uint32_t PDMA_GET_SBUF(PDMA_T *CH)
{
    return ((CH)->SBUF);
}

/**
 * @brief       Enable PDMA controller clock
 *
 * @param[in]   PDMA channel clock to be enabled, can use seperatly or 'OR' combined:
 *              PDMA_CH5_CLK
 *              PDMA_CH4_CLK
 *              PDMA_CH3_CLK
 *              PDMA_CH2_CLK
 *              PDMA_CH1_CLK
 *              PDMA_CH0_CLK
 *
 * @return      None
 *
 * @details     Enable PDMA controller clock of specified channel
 */
static __INLINE void PDMA_CH_CLK_ENABLE(uint32_t clk)
{
    PDMA_GCR->GCRCSR |= (clk);
}

/**
 * @brief       Disable PDMA controller clock
 *
 * @param[in]   PDMA channel clock to be enabled, can use seperatly or 'OR' combined:
 *              PDMA_CH5_CLK
 *              PDMA_CH4_CLK
 *              PDMA_CH3_CLK
 *              PDMA_CH2_CLK
 *              PDMA_CH1_CLK
 *              PDMA_CH0_CLK
 *
 * @return      None
 *
 * @details     Disable PDMA controller clock of specified channel
 */
static __INLINE void PDMA_CH_CLK_DISABLE(uint32_t clk)
{
    PDMA_GCR->GCRCSR &= ~(clk);
}

/**
 * @brief       Get PDMA controller interrupt status
 *
 * @param       None
 *
 * @retval      FALSE  No interrupt at PDMA controller
 * @retval      TRUE   PDMA controller generated an interrupt
 *
 * @details     Get PDMA controller interrupt status
 */
static __INLINE uint32_t PDMA_GET_INTR_STS(void)
{
    return (PDMA_GCR->GCRISR & PDMA_INTR_STS);
}

/**
 * @brief       Get PDMA channel interrupt status
 *
 * @param[in]   ch  PDMA channel. It could be 0~5
 *
 * @retval      FALSE  No interrupt at specified channel of PDMA controller
 * @retval      TRUE   PDMA controller generated an interrupt on the specified channel
 *
 * @details     Get PDMA interrupt status of specified channel
 */
static __INLINE uint32_t PDMA_GET_CH_INTR_STS(uint8_t ch)
{
    return (PDMA_GCR->GCRISR & (1<<(ch)));
}

/**
 * @brief       Specify PDMA channel for SPI2_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI2_TX_CH0, PDMA_SPI2_TX_CH1, PDMA_SPI2_TX_CH2, \n
 *                       PDMA_SPI2_TX_CH3, PDMA_SPI2_TX_CH4, PDMA_SPI2_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI2_TX
 */
static __INLINE void PDMA_SET_SPI2_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI2_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for SPI2_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI2_RX_CH0, PDMA_SPI2_RX_CH1, PDMA_SPI2_RX_CH2, \n
 *                       PDMA_SPI2_RX_CH3, PDMA_SPI2_RX_CH4, PDMA_SPI2_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI2_RX
 */
static __INLINE void PDMA_SET_SPI2_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI2_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for SPI1_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI1_TX_CH0, PDMA_SPI1_TX_CH1, PDMA_SPI1_TX_CH2, \n
 *                       PDMA_SPI1_TX_CH3, PDMA_SPI1_TX_CH4, PDMA_SPI1_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI1_TX
 */
static __INLINE void PDMA_SET_SPI1_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI1_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for SPI1_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI1_RX_CH0, PDMA_SPI1_RX_CH1, PDMA_SPI1_RX_CH2, \n
 *                       PDMA_SPI1_RX_CH3, PDMA_SPI1_RX_CH4, PDMA_SPI1_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI1_RX
 */
static __INLINE void PDMA_SET_SPI1_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI1_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for SPI0_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI0_TX_CH0, PDMA_SPI0_TX_CH1, PDMA_SPI0_TX_CH2, \n
 *                       PDMA_SPI0_TX_CH3, PDMA_SPI0_TX_CH4, PDMA_SPI0_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI0_TX
 */
static __INLINE void PDMA_SET_SPI0_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI0_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for SPI0_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_SPI0_RX_CH0, PDMA_SPI0_RX_CH1, PDMA_SPI0_RX_CH2, \n
 *                       PDMA_SPI0_RX_CH3, PDMA_SPI0_RX_CH4, PDMA_SPI0_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for SPI0_RX
 */
static __INLINE void PDMA_SET_SPI0_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR0 = (PDMA_GCR->PDSSR0 & (~PDMA_PDSSR0_SPI0_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for ADC_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_ADC_RX_CH0, PDMA_ADC_RX_CH1, PDMA_ADC_RX_CH2, \n
 *                       PDMA_ADC_RX_CH3, PDMA_ADC_RX_CH4, PDMA_ADC_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for ADC_RX
 */
static __INLINE void PDMA_SET_ADC_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1 & (~PDMA_PDSSR1_ADC_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for UART1_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_UART1_TX_CH0, PDMA_UART1_TX_CH1, PDMA_UART1_TX_CH2, \n
 *                       PDMA_UART1_TX_CH3, PDMA_UART1_TX_CH4, PDMA_UART1_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for UART1_TX
 */
static __INLINE void PDMA_SET_UART1_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1 & (~PDMA_PDSSR1_UART1_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for UART1_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_UART1_RX_CH0, PDMA_UART1_RX_CH1, PDMA_UART1_RX_CH2, \n
 *                       PDMA_UART1_RX_CH3, PDMA_UART1_RX_CH4, PDMA_UART1_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for UART1_RX
 */
static __INLINE void PDMA_SET_UART1_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1 & (~PDMA_PDSSR1_UART1_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for UART0_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_UART0_TX_CH0, PDMA_UART0_TX_CH1, PDMA_UART0_TX_CH2, \n
 *                       PDMA_UART0_TX_CH3, PDMA_UART0_TX_CH4, PDMA_UART0_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for UART0_TX
 */
static __INLINE void PDMA_SET_UART0_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1 & (~PDMA_PDSSR1_UART0_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for UART0_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_UART0_RX_CH0, PDMA_UART0_RX_CH1, PDMA_UART0_RX_CH2, \n
 *                       PDMA_UART0_RX_CH3, PDMA_UART0_RX_CH4, PDMA_UART0_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for UART0_RX
 */
static __INLINE void PDMA_SET_UART0_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR1 = (PDMA_GCR->PDSSR1 & (~PDMA_PDSSR1_UART0_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for PWM3_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_PWM3_RX_CH0, PDMA_PWM3_RX_CH1, PDMA_PWM3_RX_CH2, \n
 *                       PDMA_PWM3_RX_CH3, PDMA_PWM3_RX_CH4, PDMA_PWM3_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for PWM3_RX
 */
static __INLINE void PDMA_SET_PWM3_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_PWM3_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for PWM2_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_PWM2_RX_CH0, PDMA_PWM2_RX_CH1, PDMA_PWM2_RX_CH2, \n
 *                       PDMA_PWM2_RX_CH3, PDMA_PWM2_RX_CH4, PDMA_PWM2_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for PWM2_RX
 */
static __INLINE void PDMA_SET_PWM2_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_PWM2_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for PWM1_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_PWM1_RX_CH0, PDMA_PWM1_RX_CH1, PDMA_PWM1_RX_CH2, \n
 *                       PDMA_PWM1_RX_CH3, PDMA_PWM1_RX_CH4, PDMA_PWM1_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for PWM1_RX
 */
static __INLINE void PDMA_SET_PWM1_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_PWM1_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for PWM0_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_PWM0_RX_CH0, PDMA_PWM0_RX_CH1, PDMA_PWM0_RX_CH2, \n
 *                       PDMA_PWM0_RX_CH3, PDMA_PWM0_RX_CH4, PDMA_PWM0_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for PWM0_RX
 */
static __INLINE void PDMA_SET_PWM0_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_PWM0_RXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for I2S_TX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_I2S_TX_CH0, PDMA_I2S_TX_CH1, PDMA_I2S_TX_CH2, \n
 *                       PDMA_I2S_TX_CH3, PDMA_I2S_TX_CH4, PDMA_I2S_TX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for I2S_TX
 */
static __INLINE void PDMA_SET_I2S_TX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_I2S_TXSEL_Msk)) | (channel);
}

/**
 * @brief       Specify PDMA channel for I2S_RX
 *
 * @param[in]   channel  PDMA channel corresponding to the specified IP. It could be \n
 *                       PDMA_I2S_RX_CH0, PDMA_I2S_RX_CH1, PDMA_I2S_RX_CH2, \n
 *                       PDMA_I2S_RX_CH3, PDMA_I2S_RX_CH4, PDMA_I2S_RX_CH5
 *
 * @return      None
 *
 * @details     Specify PDMA channel for I2S_RX
 */
static __INLINE void PDMA_SET_I2S_RX_CH(uint32_t channel)
{
    PDMA_GCR->PDSSR2 = (PDMA_GCR->PDSSR2 & (~PDMA_PDSSR2_I2S_RXSEL_Msk)) | (channel);
}

/*@}*/ /* end of group PDMA_MACRO_FUNC */
/*@}*/ /* end of group PDMA_MACRO */
/*@}*/ /* end of group NUC123_MACRO_FUNC */

  
/*---------------------------------------------------------------------------------------------------------*/
/* Define PDMA API prototype                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void DrvPDMA_Init(PDMA_T *ch, STR_PDMA_T *sParam);
void DrvPDMA_DeInit(void);
void DrvPDMA_EnableInt(PDMA_T *ch, uint32_t u32IntMask);
void DrvPDMA_DisableInt(PDMA_T *ch, uint32_t u32IntMask);

#endif
