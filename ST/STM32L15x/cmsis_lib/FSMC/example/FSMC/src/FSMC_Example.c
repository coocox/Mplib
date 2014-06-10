/**
 ******************************************************************************
 * @file    FSMC/SRAM/main.c
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
#include "stm32l1xx.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"
#include "stm32l152d_eval_fsmc_sram.h"

/** @addtogroup STM32L1xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup FSMC_SRAM
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BUFFER_SIZE        0x400
#define WRITE_READ_ADDR    0x8000
#define LD_GREEN_GPIO_PIN 		GPIO_Pin_7
#define LD_BLUE_GPIO_PIN        GPIO_Pin_6

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint16_t TxBuffer[BUFFER_SIZE];
uint16_t RxBuffer[BUFFER_SIZE];
uint32_t WriteReadStatus = 0, Index = 0;

/* Private function prototypes -----------------------------------------------*/
void Fill_Buffer(uint16_t *pBuffer, uint16_t BufferLenght, uint32_t Offset);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
void FSMC_Example(void) {
	/*!< At this stage the microcontroller clock setting is already configured,
	 this is done through SystemInit() function which is called from startup
	 file (startup_stm32l1xx_xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32l1xx.c file
	 */

	/* Initialize Leds mounted on STM32L1-DISCOVERY board */
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOB Periph clock enable */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	/* Configure PD0 and PD1 or PD3 and PD7 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = LD_GREEN_GPIO_PIN | LD_BLUE_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/* Write/read to/from FSMC SRAM memory  *************************************/
	/* Enable the FSMC Clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

	/* Configure FSMC Bank1 NOR/SRAM3 */
	SRAM_Init();

	/* Write data to FSMC SRAM memory */
	/* Fill the buffer to send */
	Fill_Buffer(TxBuffer, BUFFER_SIZE, 0x3212);
	SRAM_WriteBuffer(TxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);

	/* Read data from FSMC SRAM memory */
	SRAM_ReadBuffer(RxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);

	/* Read back SRAM memory and check content correctness */
	for (Index = 0x00; (Index < BUFFER_SIZE) && (WriteReadStatus == 0);
			Index++) {
		if (RxBuffer[Index] != TxBuffer[Index]) {
			WriteReadStatus = Index + 1;
		}
	}

	if (WriteReadStatus == 0) {
		/* OK */
		/* Turn on LED1 */
		GPIO_SetBits(GPIOB, LD_GREEN_GPIO_PIN);
	} else {
		/* KO */
		/* Turn on LED2 */
		GPIO_SetBits(GPIOB, LD_BLUE_GPIO_PIN);
	}

	while (1) {
	}
}

/**
 * @brief  Fill the global buffer
 * @param  pBuffer: pointer on the Buffer to fill
 * @param  BufferSize: size of the buffer to fill
 * @param  Offset: first value to fill on the Buffer
 */
void Fill_Buffer(uint16_t *pBuffer, uint16_t BufferLenght, uint32_t Offset) {
	uint16_t IndexTmp = 0;

	/* Put in global buffer same values */
	for (IndexTmp = 0; IndexTmp < BufferLenght; IndexTmp++) {
		pBuffer[IndexTmp] = IndexTmp + Offset;
	}
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
