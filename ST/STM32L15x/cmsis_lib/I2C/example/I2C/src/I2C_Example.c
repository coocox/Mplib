/* Includes ------------------------------------------------------------------*/
#include "misc.h"
#include "stm32l1xx.h"
#include "stm32l1xx_i2c.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"
/** @addtogroup STM32F4xx_StdPeriph_Examples
 * @{
 */

/** @addtogroup USART_Printf
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
typedef enum {
	Fail = 0, Pass = !Fail
} TestResult;
/* Private define ------------------------------------------------------------*/
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

/* Private macro -------------------------------------------------------------*/
#define I2C1_MASTER_ADDRESS    0x30
#define I2C2_SLAVE_ADDRESS     0x30
/* Private variables ---------------------------------------------------------*/
uint8_t I2C1_Buffer_Tx[4] = { 0x1, 0x2, 0x3, 0x4 };
uint8_t I2C2_Buffer_Rx[4] = { 0, 0, 0, 0 };
uint8_t Tx_Index = 0, Rx_Index = 0, PEC_Value = 0;
TestResult a;
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void I2CInit(void);
TestResult CmpBuffer(u8* Buffer1, u8* Buffer2, u32 BufferLength);

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
void I2C_Example(void) {

	I2CInit();

	I2C_ITConfig(I2C1, I2C_IT_BUF | I2C_IT_EVT, ENABLE);
	I2C_ITConfig(I2C2, I2C_IT_BUF | I2C_IT_EVT, ENABLE);
	I2C_GenerateSTART(I2C1, ENABLE);

	while (Rx_Index < 5) {
	}
	a = CmpBuffer(I2C1_Buffer_Tx, I2C2_Buffer_Rx, 4);
	if (a == 1) {
		GPIOG->BSRRL = GPIO_Pin_6;
	} else {
		GPIOG->BSRRL = GPIO_Pin_8;
	}

	while (1) {
	}
}

void I2CInit(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	/* Enable I2C clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2, ENABLE);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_I2C2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_I2C2);

	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	I2C_InitStructure.I2C_ClockSpeed = 200000;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = I2C1_MASTER_ADDRESS;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	/* Enable I2C */
	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_InitStructure);

	I2C_InitStructure.I2C_OwnAddress1 = I2C2_SLAVE_ADDRESS;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;

	I2C_Cmd(I2C2, ENABLE);
	I2C_Init(I2C2, &I2C_InitStructure);

	/* Configure the I2C interrupt priority */
	NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = I2C2_EV_IRQn;
	NVIC_Init(&NVIC_InitStructure);
}

void I2C1_EV_IRQHandler(void) {
	switch (I2C_GetLastEvent(I2C1)) {
	case I2C_EVENT_MASTER_MODE_SELECT:
		I2C_Send7bitAddress(I2C1, I2C2_SLAVE_ADDRESS,
				I2C_Direction_Transmitter);
		break;

	case I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED:
		I2C_CalculatePEC(I2C1, ENABLE);
		I2C_CalculatePEC(I2C2, ENABLE);
		I2C_SendData(I2C1, I2C1_Buffer_Tx[Tx_Index++]);
		break;

	case I2C_EVENT_MASTER_BYTE_TRANSMITTING:
		if (Tx_Index < 4) {
			I2C_SendData(I2C1, I2C1_Buffer_Tx[Tx_Index++]);
		} else {
			I2C_ITConfig(I2C1, I2C_IT_BUF | I2C_IT_EVT, DISABLE);
			I2C_TransmitPEC(I2C2, ENABLE);
			I2C_TransmitPEC(I2C1, ENABLE);
		}

		break;

	default:
		break;

	}
}

void I2C2_EV_IRQHandler(void) {
	switch (I2C_GetLastEvent(I2C2)) {
	case I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED:
		break;

	case I2C_EVENT_SLAVE_BYTE_RECEIVED:
		if (Rx_Index < 4) {
			I2C2_Buffer_Rx[Rx_Index++] = I2C_ReceiveData(I2C2);
		} else {
			PEC_Value = I2C_ReceiveData(I2C2);
			Rx_Index++;
			I2C_GenerateSTOP(I2C1, ENABLE);
		}
		break;

	case I2C_EVENT_SLAVE_STOP_DETECTED:

		I2C_ITConfig(I2C2, I2C_IT_BUF | I2C_IT_EVT, DISABLE);

		break;

	default:
		break;
	}
}

TestResult CmpBuffer(u8* Buffer1, u8* Buffer2, u32 BufferLength) {
	while (BufferLength--) {
		if (*Buffer1 != *Buffer2) {
			return Fail;
		}

		Buffer1++;
		Buffer2++;
	}

	return Pass;
}

/**
 * @}
 */

/**
 * @}
 */
