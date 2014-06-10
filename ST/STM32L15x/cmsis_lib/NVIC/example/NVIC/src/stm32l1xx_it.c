/**
 ******************************************************************************
 * @file    NVIC/IRQ_Mask/stm32l1xx_it.c
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    13-April-2012
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and peripherals
 *          interrupt service routine.
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
#include "stm32l1xx_exti.h"
#include "stm32l1xx_tim.h"

/** @addtogroup STM32L1xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup IRQ_Mask
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
typedef enum {
	LED1 = 0, LED2 = 1
} Led_TypeDef;

typedef enum {
	BUTTON_KEY = 0,
} Button_TypeDef;

typedef enum {
	BUTTON_MODE_GPIO = 0, BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t index =	0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
extern uint32_t STM_EVAL_PBGetState(Button_TypeDef Button);
extern void STM_EVAL_LEDToggle(Led_TypeDef Led);

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
 * @brief  This function handles PendSV_Handler exception.
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
 * @brief  This function handles EXTI Lines 9 to 5 interrupts requests.
 * @param  None
 * @retval None
 */

void EXTI0_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
		if (index == 0) {
			/* Configure the BASEPRI register to 0x40 (Preemption priority = 1).
			 Only IRQ with higher preemption priority than 1 are permitted.
			 This will mask TIM3 and TIM4 IRQ from generation. */
			__set_BASEPRI(0x40);
			index++;
		} else {
			/* Configure the BASEPRI register to 0x00 (Preemption priority = 0).
			 When this BASEPRI register is set to 0, it has no effect on the current
			 priority.
			 TIM2, TIM3 and TIM4 generation is controlled by NVIC priority registers. */
			__set_BASEPRI(0x00);
			index = 0;
		}
		/* Clears the SEL Button EXTI line pending bits. */
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

/**
 * @brief  This function handles TIM2 global interrupt request.
 * @param  None
 * @retval None
 */
void TIM2_IRQHandler(void) {
	/* Clear TIM2 update interrupt */
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	/* Toggle LED1 */
	STM_EVAL_LEDToggle(LED1);
}

/**
 * @brief  This function handles TIM3 global interrupt request.
 * @param  None
 * @retval None
 */
void TIM3_IRQHandler(void) {
	/* Clear TIM3 update interrupt */
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

	/* Toggle LED2 */
	STM_EVAL_LEDToggle(LED2);
}

/**
 * @brief  This function handles TIM4 global interrupt request.
 * @param  None
 * @retval None
 */
void TIM4_IRQHandler(void) {
	/* Clear TIM4 update interrupt */
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);

	/* Toggle LED3 */
	STM_EVAL_LEDToggle(LED1);
	STM_EVAL_LEDToggle(LED2);
}

/******************************************************************************/
/*                 STM32L1xx Peripherals Interrupt Handlers                   */
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
