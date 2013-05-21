/**
 *******************************************************************************
 * @file    IGBT_OnePPG.c
 * @brief   The application functions of IGBT One PPG for the TOSHIBA 'TMPM369' 
 *          Device Series 
 * @version V0.100
 * @date    2011/08/22
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
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm369_igbt.h"
#include "tmpm369_gpio.h"
#include "tmpm369_uart.h"

/* fperiph = fc = 16MHz*5 = 80MHz, T0 = fperiph = 80MHz, figbt = T0/2 = 40MHz */
#define IGBT_PPG_PERIOD_50US    ((uint16_t)2000)

void IGBT_IO_Configuration(TSB_MT_TypeDef * IGBTx, IGBT_InitTypeDef * InitTypeDef);
void UART0_Print(char *string);
void SIO_Configuration(void);
void SIO_ChInit(void);

/* Global variable define ----------------------------------------------------*/
WorkState counter_state = BUSY;
Result cancel_result = ERROR;
IGBT_InitTypeDef myIGBT;
IGBT_EMGStateTypeDef EMGState = { IGBT_EMG_INPUT_LOW, IGBT_EMG_NORMAL };

/**
  * @brief  main function to run IGBT One PPG demo
  * @param  None.
  * @retval result to retun to system.
  */
void IGBT_OnePPG(void)
{
    /* UART initialization */
    SIO_Configuration();
    SIO_ChInit();

    myIGBT.StartMode = IGBT_FALLING_TRG_START;          /* IGBT trigger start: falling edge start and active level is "Low" */
    myIGBT.OperationMode = IGBT_CONTINUOUS_OUTPUT;      /* IGBT operation: continuous operation */
    myIGBT.CntStopState = IGBT_OUTPUT_INACTIVE;         /* IGBT stopping status: initial output satus and counter */
    myIGBT.ActiveAcceptTrg = DISABLE;                   /* Trigger edge accept mode: Don't accept trigger during active level */
    myIGBT.INTPeriod = IGBT_INT_PERIOD_1;               /* Interrupt cycle: Every one cycle */
    myIGBT.ClkDiv = IGBT_CLK_DIV_2;                     /* fperiph = fc = 16MHz*5 = 80MHz, T0 = fperiph = 80MHz, figbt = T0/2 = 40MHz */
    myIGBT.Output0Init = IGBT_OUTPUT_HIGH_ACTIVE;       /* MTOUT00 initial state is Low, and active level is High */
    myIGBT.Output1Init = IGBT_OUTPUT_DISABLE;           /* Disable MTOUT10 output */
    myIGBT.TrgDenoiseDiv = IGBT_DENOISE_DIV_240;        /* Trigger input noise elimination time: 240/fsys */
    myIGBT.Output0ActiveTiming = 1U;
    myIGBT.Output0InactiveTiming = 1U + IGBT_PPG_PERIOD_50US / 2;
    myIGBT.Period = IGBT_PPG_PERIOD_50US;               /* Period: 50us */
    myIGBT.EMGFunction = IGBT_EMG_OUTPUT_HIZ;           /* The polarity of MTOUT0x at EMG protection: High-impedance */
    myIGBT.EMGDenoiseDiv = IGBT_DENOISE_DIV_240;        /* EMG input noise elimination time: 240/fsys */

    IGBT_IO_Configuration(IGBT0, &myIGBT);

    IGBT_Enable(IGBT0);
    NVIC_EnableIRQ(INTMTEMG0_IRQn);                     /* Enable IGBT and EMG interrupt */

    do {                                                /* If the timer is still running, wait until it stops */
        counter_state = IGBT_GetCntState(IGBT0);
    } while (counter_state == BUSY);
    do {                                                /* Cancel the EMG protection state */
        cancel_result = IGBT_CancelEMGState(IGBT0);
    } while (cancel_result == ERROR);

    IGBT_Init(IGBT0, &myIGBT);

    IGBT_SetSWRunState(IGBT0, IGBT_RUN);                /* Prepare to run IGBT timer */

    while (1) {

        EMGState = IGBT_GetEMGState(IGBT0);             /* Get EMG protection state to check EMG state */

        if (EMGState.EMGProtectState == IGBT_EMG_PROTECT) {     /* If EMG protection is on going */
            do {
                counter_state = IGBT_GetCntState(IGBT0);
            } while (counter_state == BUSY);
            do {                                        /* Cancel the EMG protection state */
                cancel_result = IGBT_CancelEMGState(IGBT0);
            } while (cancel_result == ERROR);

            UART0_Print("prepare run again");                              /* prepare to run again */
            IGBT_Init(IGBT0, &myIGBT);

            IGBT_SetSWRunState(IGBT0, IGBT_RUN);
        } else {
            /* Do nothing */
        }
    }
}

/**
  * @brief  IRQ for EMG protection
  * @param  None.
  * @retval None.
  */
void INTMTEMG0_IRQHandler(void)
{
    UART0_Print("stop the timer");                                       /* If EMG protection, stop the timer */
    IGBT_SetSWRunState(IGBT0, IGBT_STOP);
}

/**
  * @brief  IGBT port initialization
  * @param  IGBTx: IGBT channel.
  *         InitTypeDef: initialization structure.
  * @retval None.
  */
void IGBT_IO_Configuration(TSB_MT_TypeDef * IGBTx, IGBT_InitTypeDef * InitTypeDef)
{
    if (IGBTx == IGBT0) {
        /* Check whether the trigger is used to start */
        if ((InitTypeDef->StartMode != IGBT_CMD_START) ||
            (InitTypeDef->StartMode != IGBT_CMD_START_NO_START_INT)) {
            GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_0, ENABLE);        /* Enable PG0 input */
            GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_0);   /* Set PG0 as MT0IN */
        } else {
            GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_0, DISABLE);
            GPIO_DisableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_0);
        }
        /* Enable ouput0 or not */
        if (InitTypeDef->Output0Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_3, ENABLE);       /* Enable PG3 output */
            GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_3);   /* Set PG3 as MTOUT00 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_3, DISABLE);
            GPIO_DisableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_3);
        }
        /* Enable ouput1 or not */
        if (InitTypeDef->Output1Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_2, ENABLE);       /* Enable PG2 output */
            GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_2);   /* Set PG2 as MTOUT10 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_2, DISABLE);
            GPIO_DisableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_2);
        }

        GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_1, ENABLE);    /* Enable PG1 input */
        GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_3, GPIO_BIT_1);       /* Set PG1 as GEMG0 */
    }


    if (IGBTx == IGBT1) {
        /* Check whether the trigger is used to start */
        if ((InitTypeDef->StartMode != IGBT_CMD_START) ||
            (InitTypeDef->StartMode != IGBT_CMD_START_NO_START_INT)) {
            GPIO_SetInputEnableReg(GPIO_PL, GPIO_BIT_0, ENABLE);        /* Enable PL0 input */
            GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_0);   /* Set PL0 as MT1IN */
        } else {
            GPIO_SetInputEnableReg(GPIO_PL, GPIO_BIT_0, DISABLE);
            GPIO_DisableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_0);
        }
        /* Enable ouput0 or not */
        if (InitTypeDef->Output0Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PL, GPIO_BIT_3, ENABLE);       /* Enable PL3 output */
            GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_3);   /* Set PL3 as MTOUT01 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PL, GPIO_BIT_3, DISABLE);
            GPIO_DisableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_3);
        }
        /* Enable ouput1 or not */
        if (InitTypeDef->Output1Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PL, GPIO_BIT_2, ENABLE);       /* Enable PL2 output */
            GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_2);   /* Set PL2 as MTOUT11 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PL, GPIO_BIT_2, DISABLE);
            GPIO_DisableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_2);
        }

        GPIO_SetInputEnableReg(GPIO_PL, GPIO_BIT_1, ENABLE);    /* Enable PL1 input */
        GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_3, GPIO_BIT_1);       /* Set PL1 as GEMG1 */
    }

    if (IGBTx == IGBT2) {
        /* Check whether the trigger is used to start */
        if ((InitTypeDef->StartMode != IGBT_CMD_START) ||
            (InitTypeDef->StartMode != IGBT_CMD_START_NO_START_INT)) {
            GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_0, ENABLE);        /* Enable PH0 input */
            GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_0);   /* Set PH0 as MT2IN */
        } else {
            GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_0, DISABLE);
            GPIO_DisableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_0);
        }
        /* Enable ouput0 or not */
        if (InitTypeDef->Output0Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_3, ENABLE);       /* Enable PH3 output */
            GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_3);   /* Set PH3 as MTOUT02 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_3, DISABLE);
            GPIO_DisableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_3);
        }
        /* Enable ouput1 or not */
        if (InitTypeDef->Output1Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_2, ENABLE);       /* Enable PH2 output */
            GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_2);   /* Set PH2 as MTOUT12 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_2, DISABLE);
            GPIO_DisableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_2);
        }

        GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_1, ENABLE);    /* Enable PH1 input */
        GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_3, GPIO_BIT_1);       /* Set PH1 as GEMG2 */
    }

    if (IGBTx == IGBT3) {
        /* Check whether the trigger is used to start */
        if ((InitTypeDef->StartMode != IGBT_CMD_START) ||
            (InitTypeDef->StartMode != IGBT_CMD_START_NO_START_INT)) {
            GPIO_SetInputEnableReg(GPIO_PB, GPIO_BIT_5, ENABLE);        /* Enable PB5 input */
            GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_5);   /* Set PB5 as MT3IN */
        } else {
            GPIO_SetInputEnableReg(GPIO_PB, GPIO_BIT_5, DISABLE);
            GPIO_DisableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_5);
        }
        /* Enable ouput0 or not */
        if (InitTypeDef->Output0Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_2, ENABLE);       /* Enable PB2 output */
            GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_2);   /* Set PB2 as MTOUT03 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_2, DISABLE);
            GPIO_DisableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_2);
        }
        /* Enable ouput1 or not */
        if (InitTypeDef->Output1Init != IGBT_OUTPUT_DISABLE) {
            GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_3, ENABLE);       /* Enable PB3 output */
            GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_3);   /* Set PB3 as MTOUT13 */
        } else {
            GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_3, DISABLE);
            GPIO_DisableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_3);
        }

        GPIO_SetInputEnableReg(GPIO_PB, GPIO_BIT_4, ENABLE);    /* Enable PB4 input */
        GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_4);       /* Set PB4 as GEMG3 */
    }
}

/**
  * @brief  UART0 Print
  * @param  string
  * @retval None
  */
void UART0_Print(char *string)
{
	  char *p = string;
	  uint32_t i;
	  while(*p)
	  {
		    UART_SetTxData(UART0, (uint32_t)(*p));
		    p++;
		    for(i = 0U; i < 0xFFFFU; i ++);
	  }
}

/**
  * @brief  SIO Configuration.
  * @param  None
  * @retval None
  */
void SIO_Configuration(void)
{ 
     GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_2, ENABLE);
     GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_2, DISABLE);
     GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_2);
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
    UART_Enable(UART0);
    myUART.BaudRate = 115200U;  /* baud rate = 115200 */
    myUART.DataBits = UART_DATA_BITS_8; /* no handshake, 8-bit data, clock by baud rate generator */
    myUART.StopBits = UART_STOP_BITS_1; /* 1-bit stop, LSB,  W-buff enable */
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode = UART_ENABLE_TX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;
    UART_Init(UART0, &myUART);
}
