/**
 ******************************************************************************
 * @file    USART/USART/main.c
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    13-April-2012
 * @brief   Main program body
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
#include "misc.h"
#include "stm32l1xx.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_usart.h"

#define EVAL_COMX EVAL_COM2
#define COMX COM2
#define EVAL_COMX_IRQn EVAL_COM2_IRQn

/** @addtogroup STM32L1xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup USART_USART
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
typedef enum
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;

/* Private define ------------------------------------------------------------*/
#define COMn                             2

/**
 * @brief Definition for COM port1, connected to USART2
 */
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
USART_TypeDef* COM_USART[COMn] = {EVAL_COM1, EVAL_COM2};
GPIO_TypeDef* COM_TX_PORT[COMn] = {EVAL_COM1_TX_GPIO_PORT, EVAL_COM2_TX_GPIO_PORT};
GPIO_TypeDef* COM_RX_PORT[COMn] = {EVAL_COM1_RX_GPIO_PORT, EVAL_COM2_RX_GPIO_PORT};
const uint32_t COM_USART_CLK[COMn] = {EVAL_COM1_CLK, EVAL_COM2_CLK};
const uint32_t COM_TX_PORT_CLK[COMn] = {EVAL_COM1_TX_GPIO_CLK, EVAL_COM2_TX_GPIO_CLK};
const uint32_t COM_RX_PORT_CLK[COMn] = {EVAL_COM1_RX_GPIO_CLK, EVAL_COM2_RX_GPIO_CLK};
const uint16_t COM_TX_PIN[COMn] = {EVAL_COM1_TX_PIN, EVAL_COM2_TX_PIN};
const uint16_t COM_RX_PIN[COMn] = {EVAL_COM1_RX_PIN, EVAL_COM2_RX_PIN};
const uint8_t COM_TX_PIN_SOURCE[COMn] = {EVAL_COM1_TX_SOURCE, EVAL_COM2_TX_SOURCE};
const uint8_t COM_RX_PIN_SOURCE[COMn] = {EVAL_COM1_RX_SOURCE, EVAL_COM2_RX_SOURCE};
const uint8_t COM_TX_AF[COMn] = {EVAL_COM1_TX_AF, EVAL_COM2_TX_AF};
const uint8_t COM_RX_AF[COMn] = {EVAL_COM1_RX_AF, EVAL_COM2_RX_AF};

/* Private variables ---------------------------------------------------------*/
USART_InitTypeDef USART_InitStructure;
extern uint8_t NbrOfDataToTransfer;
extern uint8_t NbrOfDataToRead;
extern __IO uint8_t TxCounter;
extern __IO uint16_t RxCounter;
/* Private function prototypes -----------------------------------------------*/
void NVIC_Config(void);
void STM_EVAL_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief   Main program
 * @param  None
 * @retval None
 */
void USART_Example(void) {
	/*!< At this stage the microcontroller clock setting is already configured,
	 this is done through SystemInit() function which is called from startup
	 file (startup_stm32l1xx_xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32l1xx.c file
	 */

	/* NVIC configuration */
	NVIC_Config();

	/* USARTx configuration ------------------------------------------------------*/
	/* USARTx configured as follow:
	 - BaudRate = 9600 baud
	 - Word Length = 8 Bits
	 - Two Stop Bit
	 - Odd parity
	 - Hardware flow control disabled (RTS and CTS signals)
	 - Receive and transmit enabled
	 */
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_2;
	USART_InitStructure.USART_Parity = USART_Parity_Odd;
	USART_InitStructure.USART_HardwareFlowControl =
			USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	STM_EVAL_COMInit(COMX, &USART_InitStructure);

	/* Enable the EVAL_COMX Transmoit interrupt: this interrupt is generated when the
	 EVAL_COM1 transmit data register is empty */
	USART_ITConfig(EVAL_COMX, USART_IT_TXE, ENABLE);

	/* Wait until EVAL_COMX send the TxBuffer */
	while (TxCounter < NbrOfDataToTransfer) {
	}

	/* The software must wait until TC=1. The TC flag remains cleared during all data
	 transfers and it is set by hardware at the last frame’s end of transmission*/
	while (USART_GetFlagStatus(EVAL_COMX, USART_FLAG_TC) == RESET) {
	}

	/* Enable the EVAL_COMX Receive interrupt: this interrupt is generated when the
	 EVAL_COMX receive data register is not empty */
	USART_ITConfig(EVAL_COMX, USART_IT_RXNE, ENABLE);

	/* Wait until EVAL_COMX receive the RxBuffer */
	while (RxCounter < NbrOfDataToRead) {
	}

	while (1) {
	}
}

/**
 * @brief  Configures the nested vectored interrupt controller.
 * @param  None
 * @retval None
 */
void NVIC_Config(void) {
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable the USARTx Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = EVAL_COMX_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


/**
  * @brief  Configures COM port.
  * @param  COM: Specifies the COM port to be configured.
  *   This parameter can be one of following parameters:
  *     @arg COM1
  *     @arg COM2
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure that
  *   contains the configuration information for the specified USART peripheral.
  * @retval None
  */
void STM_EVAL_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHBPeriphClockCmd(COM_TX_PORT_CLK[COM] | COM_RX_PORT_CLK[COM], ENABLE);

  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(COM_USART_CLK[COM], ENABLE);

  /* Connect PXx to USARTx_Tx */
  GPIO_PinAFConfig(COM_TX_PORT[COM], COM_TX_PIN_SOURCE[COM], COM_TX_AF[COM]);

  /* Connect PXx to USARTx_Rx */
  GPIO_PinAFConfig(COM_RX_PORT[COM], COM_RX_PIN_SOURCE[COM], COM_RX_AF[COM]);

  /* Configure USART Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = COM_TX_PIN[COM];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(COM_TX_PORT[COM], &GPIO_InitStructure);

  /* Configure USART Rx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = COM_RX_PIN[COM];
  GPIO_Init(COM_RX_PORT[COM], &GPIO_InitStructure);

  /* USART configuration */
  USART_Init(COM_USART[COM], USART_InitStruct);

  /* Enable USART */
  USART_Cmd(COM_USART[COM], ENABLE);
}


#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
