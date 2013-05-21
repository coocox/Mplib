/**
 *******************************************************************************
 * @file    ADC_Data_Read.c
 * @brief   The application functions of ADC demo for the
 *          TOSHIBA 'TMPM365' Demo
 * @version V0.100
 * @date    2012/08/03
 * 
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. TOSHIBA CORPORATION
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 * 
 * TOSHIBA CORPORATION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
 * ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
 * PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
 * DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* include file */
#include <stdio.h>
#include "tmpm365_adc.h"
#include "tmpm365_uart.h"
#include "tmpm365_gpio.h"

/* define the ADC channel used here.the VR3 is connected to AIN0 in this example */
#define ADC_CHANNEL     ADC_AN_00
#define ADC_REG_RESULT  ADC_REG_00

#define BUFFER_SIZE 16U
#define SET     0x01U           /* flag is set */
#define CLEAR   0x00U           /* flag is cleared */
#define NO      0x00U           /* Send finish NG */
#define YES     0x01U           /* Send finish OK */
#define DELAYCONST  180000U



struct mySoftTimer {
    uint8_t flag_TimeUp;
    uint8_t flag_Blink;
    uint32_t timer_Cnt;
} softT;


static void softTimer_Init(void);
static void softTimer_Run(void);

static void display_AD(uint32_t myResult);
void delay(void);
void SIO_Configuration(TSB_SC_TypeDef * SCx);
void SIO_ChInit(void);
uint8_t send_char(uint8_t ch);
void UART1_Print(char *s);
char gSIOTxBuffer[BUFFER_SIZE] = { 0U };



ADC_Result adResult = { 0U };

uint32_t timeUp = 0U;
uint32_t idx = 0U;
uint32_t cnt = 0U;

uint8_t gSIORdIndex = 0U;
uint8_t gSIOWrIndex = 0U;
uint8_t fSIO_INT = 0U;
uint8_t fSIOTxOK = NO;

ADC_State adcState = { 0 };

uint32_t myResult = 0U;
char TxBuffer[] = "";

void ADC_Data_Read()
{

	  /* Initialize system */

    SIO_Configuration(UART1);
    SIO_ChInit();
	  
    /* 1. set ADC clock */
    ADC_SetClk(ADC_CONVERSION_CLK_80, ADC_FC_DIVIDE_LEVEL_4);

    /* 2. turn on reference voltage, and wait at least 3uS to let it stable */
    ADC_SetVref(ENABLE);
    timeUp = 300U;
    while (timeUp) {
        timeUp--;
    }

    /* 3. use Fixed-channel single conversion */
    ADC_SetScanMode(DISABLE);
    ADC_SetRepeatMode(DISABLE);

    /* 4. select ADC channel */
    ADC_SetInputChannel(ADC_CHANNEL);

    /* 5. now start ADC */
    ADC_Start();



    /* initialize soft timer */
    softTimer_Init();

    while (1U) {
        softTimer_Run();
        if (softT.flag_TimeUp) {
            softT.flag_TimeUp = 0U;

            /* check ADC module state */
            adcState = ADC_GetConvertState();
            if (adcState.Bit.NormalComplete) {
                /* read ADC result when it is finished */
                adResult = ADC_GetConvertResult(ADC_REG_RESULT);
                myResult = (uint32_t) adResult.Bit.ADResult;
                ADC_Start();
                display_AD(myResult);
            }
        } else {
            /* Do nothing */
        }

    }
}


/**
  * @brief  Initialize a several mS timer. 
  * @param  None
  * @retval None
  */
static void softTimer_Init(void)
{
    softT.flag_TimeUp = 0U;
    softT.flag_Blink = 0U;
    softT.timer_Cnt = DELAYCONST;
}


/**
  * @brief  Simulate a several mS timer. 
  * @param  None
  * @retval None
  */
static void softTimer_Run(void)
{
    if (softT.timer_Cnt == 0U) {
        softT.flag_TimeUp = 1U;
        softT.flag_Blink = (uint8_t) ~ softT.flag_Blink;
        softT.timer_Cnt = DELAYCONST;
    } else {
        softT.timer_Cnt--;
    }
}

/**
  * @brief  display AD value on LCD. 
  * @param  myResult: AD data which will be displayed
  * @retval None
  */
void display_AD(uint32_t myResult)
{
    /* 12bit ADC */
    myResult &= ((0x1 << 12U) - 1U);
    sprintf(TxBuffer,"%d",myResult);
    UART1_Print("ADC Value is :   ");
	  UART1_Print(TxBuffer);
	  UART1_Print("\n\r");
}

/**
  * @brief  Delay some time
  * @param  None
  * @retval None
  */
void delay(void)
{
    uint32_t i = 0U;
    for (i = 0U; i < 0xFFFU; i++) {
        /* Do nothing */
    }
}

/**
  * @brief  SIO Configuration.
  * @param  SCx
  * @retval None
  */
void SIO_Configuration(TSB_SC_TypeDef * SCx)
{
    if (SCx == UART1) {
        GPIO_SetOutputEnableReg(GPIO_PC, GPIO_BIT_0, ENABLE);
        GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_0);
        GPIO_EnableFuncReg(GPIO_PC, GPIO_FUNC_REG_1, GPIO_BIT_1);
        GPIO_SetInputEnableReg(GPIO_PC, GPIO_BIT_1, ENABLE);
        GPIO_SetPullUp(GPIO_PC, GPIO_BIT_0, ENABLE);
        GPIO_SetPullUp(GPIO_PC, GPIO_BIT_1, ENABLE);
    } else {
        /*  Do Nothing */
    }
}

/**
  * @brief  SIO Configuration Initialize the uart port (SIO1).
  * @param  None
  * @retval None
  */
void SIO_ChInit(void)
{
    UART_InitTypeDef myUART;

    /* configure SIO0 for reception */
    UART_Enable(UART1);
    myUART.BaudRate = 115200U;  /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Init(UART1, &myUART);
}

/**
  * @brief  Send character by SIO1
  * @param  Character to be sent
  * @retval Character to be sent
  */


void UART1_Print(char *s)
{
	while('\0' != *s)
	{
   UART_SetTxData(UART1, (uint32_t)(*s));
	 s ++;
	 delay();
  }
	


}
