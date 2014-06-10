/**
 ******************************************************************************
 * @file    USART/USART/stm32l1xx_it.c
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    13-April-2012
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and
 *          peripherals interrupt service routine.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_it.h"
#include "stm32l1xx_usart.h"

/** @addtogroup STM32L1xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup USART_USART
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USARTx_IRQHANDLER   USART1_IRQHandler

#define TXBUFFERSIZE   (countof(TxBuffer) - 1)
#define RXBUFFERSIZE   0x20

#define EVAL_COMX EVAL_COM2
#define COMX COM2
#define EVAL_COMX_IRQn EVAL_COM2_IRQn

#define EVAL_COM1                        USART2
#define EVAL_COM1_CLK                    RCC_APB1Periph_USART2

#define EVAL_COM1_TX_PIN                 GPIO_Pin_5
#define EVAL_COM1_TX_GPIO_PORT           GPIOD
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHBPeriph_GPIOD
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource5
#define EVAL_COM1_TX_AF                  GPIO_AF_USART2

#define EVAL_COM1_RX_PIN                 GPIO_Pin_6
#define EVAL_COM1_RX_GPIO_PORT           GPIOD
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHBPeriph_GPIOD
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource6
#define EVAL_COM1_RX_AF                  GPIO_AF_USART2

#define EVAL_COM1_RTS_PIN                GPIO_Pin_4
#define EVAL_COM1_RTS_GPIO_PORT          GPIOD
#define EVAL_COM1_RTS_GPIO_CLK           RCC_AHBPeriph_GPIOD
#define EVAL_COM1_RTS_SOURCE             GPIO_PinSource4
#define EVAL_COM1_RTS_AF                 GPIO_AF_USART2

#define EVAL_COM1_CTS_PIN                GPIO_Pin_3
#define EVAL_COM1_CTS_GPIO_PORT          GPIOD
#define EVAL_COM1_CTS_GPIO_CLK           RCC_AHBPeriph_GPIOD
#define EVAL_COM1_CTS_SOURCE             GPIO_PinSource3
#define EVAL_COM1_CTS_AF                 GPIO_AF_USART2

#define EVAL_COM1_IRQn                   USART2_IRQn

/**
 * @brief Definition for COM port2, connected to USART3
 */
#define EVAL_COM2                        USART3
#define EVAL_COM2_CLK                    RCC_APB1Periph_USART3

#define EVAL_COM2_TX_PIN                 GPIO_Pin_10
#define EVAL_COM2_TX_GPIO_PORT           GPIOC
#define EVAL_COM2_TX_GPIO_CLK            RCC_AHBPeriph_GPIOC
#define EVAL_COM2_TX_SOURCE              GPIO_PinSource10
#define EVAL_COM2_TX_AF                  GPIO_AF_USART3

#define EVAL_COM2_RX_PIN                 GPIO_Pin_11
#define EVAL_COM2_RX_GPIO_PORT           GPIOC
#define EVAL_COM2_RX_GPIO_CLK            RCC_AHBPeriph_GPIOC
#define EVAL_COM2_RX_SOURCE              GPIO_PinSource11
#define EVAL_COM2_RX_AF                  GPIO_AF_USART3

#define EVAL_COM2_IRQn                   USART3_IRQn

/* Private macro -------------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))

/* Private variables ---------------------------------------------------------*/
uint8_t TxBuffer[] =
		"\n\rUSART Hyperterminal Interrupts Example: USART-Hyperterminal\
 communication using Interrupt\n\r";
uint8_t RxBuffer[RXBUFFERSIZE];
uint8_t NbrOfDataToTransfer = TXBUFFERSIZE;
uint8_t NbrOfDataToRead = RXBUFFERSIZE;
__IO uint8_t TxCounter = 0;
__IO uint16_t RxCounter = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 * @param  None
 * @retval None
 */
void NMI_Handler(void) {
}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
void HardFault_Handler(void) {
	/* Go to infinite loop when Hard Fault exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
void MemManage_Handler(void) {
	/* Go to infinite loop when Memory Manage exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
void BusFault_Handler(void) {
	/* Go to infinite loop when Bus Fault exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
void UsageFault_Handler(void) {
	/* Go to infinite loop when Usage Fault exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
void SVC_Handler(void) {
}

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler(void) {
}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */
void PendSV_Handler(void) {
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void) {
}

/******************************************************************************/
/*            STM32L1xx Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
 * @brief  This function handles USARTx global interrupt request.
 * @param  None
 * @retval None
 */
void USARTx_IRQHANDLER(void) {
	if (USART_GetITStatus(EVAL_COMX, USART_IT_RXNE) != RESET) {
		/* Read one byte from the receive data register */
		RxBuffer[RxCounter++] = (USART_ReceiveData(EVAL_COMX) & 0x7F);

		if (RxCounter == NbrOfDataToRead) {
			/* Disable the EVAL_COMX Receive interrupt */
			USART_ITConfig(EVAL_COMX, USART_IT_RXNE, DISABLE);
		}
	}

	if (USART_GetITStatus(EVAL_COMX, USART_IT_TXE) != RESET) {
		/* Write one byte to the transmit data register */
		USART_SendData(EVAL_COMX, TxBuffer[TxCounter++]);

		if (TxCounter == NbrOfDataToTransfer) {
			/* Disable the EVAL_COMX Transmit interrupt */
			USART_ITConfig(EVAL_COMX, USART_IT_TXE, DISABLE);
		}
	}
}

/******************************************************************************/
/*                 stm32l1xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l1xx_xx.s).                                            */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 * @param  None
 * @retval None
 */
/*void PPP_IRQHandler(void)
 {
 }*/

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
