/**
 ******************************************************************************
 * @file    NVIC/IRQ_Mask/main.c
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
#include "stm32l1xx_tim.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_exti.h"
#include "stm32l1xx_syscfg.h"

/** @addtogroup STM32L1xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup IRQ_Mask
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
typedef enum {
	LED1 = 0, LED2 = 1
} Led_TypeDef;

typedef enum {
	BUTTON_KEY = 0,
} Button_TypeDef;

typedef enum {
	BUTTON_MODE_GPIO = 0, BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

#define LEDn                             2

#define LED1_PIN                         GPIO_Pin_6
#define LED1_GPIO_PORT                   GPIOB
#define LED1_GPIO_CLK                    RCC_AHBPeriph_GPIOB

#define LED2_PIN                         GPIO_Pin_7
#define LED2_GPIO_PORT                   GPIOB
#define LED2_GPIO_CLK                    RCC_AHBPeriph_GPIOB

#define BUTTONn 						 1
#define KEY_BUTTON_PIN                   GPIO_Pin_0
#define KEY_BUTTON_GPIO_PORT             GPIOA
#define KEY_BUTTON_GPIO_CLK              RCC_AHBPeriph_GPIOA
#define KEY_BUTTON_EXTI_LINE             EXTI_Line0
#define KEY_BUTTON_EXTI_PORT_SOURCE      EXTI_PortSourceGPIOA
#define KEY_BUTTON_EXTI_PIN_SOURCE       EXTI_PinSource0
#define KEY_BUTTON_EXTI_IRQn             EXTI0_IRQn

GPIO_TypeDef* GPIO_PORT[LEDn] = { LED1_GPIO_PORT, LED2_GPIO_PORT };
const uint16_t GPIO_PIN[LEDn] = { LED1_PIN, LED2_PIN };
const uint32_t GPIO_CLK[LEDn] = { LED1_GPIO_CLK, LED2_GPIO_CLK };

GPIO_TypeDef* BUTTON_PORT[BUTTONn] = { KEY_BUTTON_GPIO_PORT };

const uint16_t BUTTON_PIN[BUTTONn] = { KEY_BUTTON_PIN };
const uint32_t BUTTON_CLK[BUTTONn] = { KEY_BUTTON_GPIO_CLK };
const uint16_t BUTTON_EXTI_LINE[BUTTONn] = { KEY_BUTTON_EXTI_LINE };
const uint8_t BUTTON_PORT_SOURCE[BUTTONn] = { KEY_BUTTON_EXTI_PORT_SOURCE };
const uint8_t BUTTON_PIN_SOURCE[BUTTONn] = { KEY_BUTTON_EXTI_PIN_SOURCE };
const uint8_t BUTTON_IRQn[BUTTONn] = { KEY_BUTTON_EXTI_IRQn };

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void TIM_Config(void);
void STM_EVAL_LEDOn(Led_TypeDef Led);
void STM_EVAL_LEDOff(Led_TypeDef Led);
void STM_EVAL_LEDToggle(Led_TypeDef Led);
void STM_EVAL_LEDInit(Led_TypeDef Led);
void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM_EVAL_PBGetState(Button_TypeDef Button);

/* Private functions ---------------------------------------------------------*/


/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
void IRQ_Mask_Examlpe(void) {
	/*!< At this stage the microcontroller clock setting is already configured,
	 this is done through SystemInit() function which is called from startup
	 file (startup_stm32l1xx_xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32l1xx.c file
	 */

	/* Initialize Leds mounted on STM32L1xx-EVAL board */
	STM_EVAL_LEDInit(LED1);
	STM_EVAL_LEDInit(LED2);

	/* Initialize the KEY and SEL buttons mounted on STM32L1xx-EVAL board */
	STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_GPIO);

	/* TIM configuration -------------------------------------------------------*/
	TIM_Config();

	while (1) {
		/* Wait until KEY button is pressed. */
		while (STM_EVAL_PBGetState(BUTTON_KEY) == RESET) {
		}
		while (STM_EVAL_PBGetState(BUTTON_KEY) != RESET) {
		}

		/* This instruction raises the execution priority to 0. This prevents all
		 exceptions with configurable priority from activating, other than through
		 the HardFault fault escalation mechanism. */
		__disable_irq();

		/* Turn LED4 ON */
		STM_EVAL_LEDOn(LED1);

		/* Wait until KEY button is pressed. */
		while (STM_EVAL_PBGetState(BUTTON_KEY) == RESET) {
		}
		while (STM_EVAL_PBGetState(BUTTON_KEY) != RESET) {
		}

		/* This instruction will allow all exceptions with configurable priority to
		 be activated. */
		__enable_irq();

		/* Turn LED4 OFF */
		STM_EVAL_LEDOff(LED1);
	}
}

void STM_EVAL_LEDInit(Led_TypeDef Led) {
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable the GPIO_LED Clock */
	RCC_AHBPeriphClockCmd(GPIO_CLK[Led], ENABLE);

	/* Configure the GPIO_LED pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIO_PORT[Led], &GPIO_InitStructure);
	GPIO_PORT[Led]->BSRRH = GPIO_PIN[Led];
}

void STM_EVAL_LEDOn(Led_TypeDef Led) {
	GPIO_PORT[Led]->BSRRL = GPIO_PIN[Led];
}

void STM_EVAL_LEDOff(Led_TypeDef Led) {
	GPIO_PORT[Led]->BSRRH = GPIO_PIN[Led];
}

void STM_EVAL_LEDToggle(Led_TypeDef Led) {
	GPIO_PORT[Led]->ODR ^= GPIO_PIN[Led];
}

void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode) {
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* There is no Wakeup and Tamper buttons on STM32L152-EVAL. */

	/* Enable the BUTTON Clock */
	RCC_AHBPeriphClockCmd(BUTTON_CLK[Button], ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	/* Configure Button pin as input */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = BUTTON_PIN[Button];
	GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStructure);

	if (Button_Mode == BUTTON_MODE_EXTI) {
		/* Connect Button EXTI Line to Button GPIO Pin */
		SYSCFG_EXTILineConfig(BUTTON_PORT_SOURCE[Button],
				BUTTON_PIN_SOURCE[Button]);
		/* Configure Button EXTI line */
		EXTI_InitStructure.EXTI_Line = BUTTON_EXTI_LINE[Button];
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

		if (Button != BUTTON_KEY) {
			EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		} else {
			EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		}
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);

		/* Enable and set Button EXTI Interrupt to the lowest priority */
		NVIC_InitStructure.NVIC_IRQChannel = BUTTON_IRQn[Button];
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

		NVIC_Init(&NVIC_InitStructure);
	}
}

uint32_t STM_EVAL_PBGetState(Button_TypeDef Button)
{
  /* There is no Wakeup and Tamper pins on STM32L152-EVAL. */

  return GPIO_ReadInputDataBit(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

/**
 * @brief  Configures the used Timers.
 * @param  None
 * @retval None
 */
void TIM_Config(void) {
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable TIM2, TIM3 and TIM4 clocks */
	RCC_APB1PeriphClockCmd(
			RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4,
			ENABLE);

	/* TIM2 configuration */
	TIM_TimeBaseStructure.TIM_Period = 0x4AF;
	TIM_TimeBaseStructure.TIM_Prescaler = ((SystemCoreClock / 1200) - 1);
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_OCStructInit(&TIM_OCInitStructure);

	/* Output Compare Timing Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
	TIM_OCInitStructure.TIM_Pulse = 0x0;
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);

	/* TIM3 configuration */
	TIM_TimeBaseStructure.TIM_Period = 0x95F;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* Output Compare Timing Mode configuration: Channel1 */
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);

	/* TIM4 configuration */
	TIM_TimeBaseStructure.TIM_Period = 0xE0F;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* Output Compare Timing Mode configuration: Channel1 */
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	/* Immediate load of TIM2,TIM3 and TIM4 Precaler values */
	TIM_PrescalerConfig(TIM2, ((SystemCoreClock / 1200) - 1),
			TIM_PSCReloadMode_Immediate);
	TIM_PrescalerConfig(TIM3, ((SystemCoreClock / 1200) - 1),
			TIM_PSCReloadMode_Immediate);
	TIM_PrescalerConfig(TIM4, ((SystemCoreClock / 1200) - 1),
			TIM_PSCReloadMode_Immediate);

	/* Clear TIM2, TIM3 and TIM4 update pending flags */
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);

	/* Configure two bits for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	/* Enable the TIM2 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the TIM3 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the TIM4 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable TIM2, TIM3 and TIM4 Update interrupts */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	/* TIM2, TIM3 and TIM4 enable counters */
	TIM_Cmd(TIM2, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
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
