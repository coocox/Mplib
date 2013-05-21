/**
 *******************************************************************************
 * @file    FUART_LoopBack.c
 * @brief   The application functions of FUART_LoopBack demo for the
 *          TOSHIBA 'TMPM366' Device Series
 * @version V0.100
 * @date    2011/06/20
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

/* include file */
#include "tmpm366_fuart.h"
#include "tmpm366_gpio.h"

/* #define RUN_NONE_FLOW_CONTROL */

#define MAX_BUFSIZE  64U

#define SW1_DOWN 1U
#define SW1_UP   0U
#define LED8_OFF 0x00000000
#define LED8_ON  ~LED8_OFF

#define LED1 (1U<<0U)
#define LED2 (1U<<1U)
#define LED3 (1U<<2U)
#define LED4 (1U<<3U)
#define LED5 (1U<<4U)
#define LED6 (1U<<5U)
#define LED7 (1U<<6U)
#define LED8 (1U<<7U)

#define LED_DATA_PORT   GPIO_PA

typedef enum {
    DIFF = 0U,
    SAME = 1U
} TestResult;

void SW1_Init(void);
uint8_t SW1_Get(void);
void LED_TXDataDisplay(uint32_t dat);
void LED_RXDataDisplay(uint32_t state);
TestResult Buffercompare(const uint32_t * Src, const uint32_t * Dst, uint32_t Len);
void FUART_GPIOConfig(void);
void FUART_ChInit(void);
void LEDInit(void);
void LedOff(uint8_t led);
void LedOn(uint8_t led);
void delay(uint32_t time);

void FUART_LoopBack(void)
{
    TestResult result = DIFF;
    FUART_StorageStatus FIFOStatus;
    uint32_t cntTx = 0U;
    uint32_t cntRx = 0U;

    uint32_t receive = 0U;      /* received data */
    uint32_t rxlast = 0U;       /* received data number after last reception */
    uint32_t rxthis = 0U;       /* recevied data number after this reception */
    uint32_t Rx_Buf[MAX_BUFSIZE] = { 0U };
    uint32_t Tx_Buf[MAX_BUFSIZE] = { 0U };

    uint32_t i = 0U;
    for (; i < MAX_BUFSIZE; i++) {
        Tx_Buf[i] = i;
    }

    LEDInit();
    LedOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8);
    SW1_Init();
    FUART_GPIOConfig();         /* Congigure GPIO for FUART0 */
    FUART_ChInit();             /* Initialize FUART0 */

    FUART_Enable(FUART0);
    FUART_EnableFIFO(FUART0);
    FUART_SetINTFIFOLevel(FUART0, FUART_RX_FIFO_LEVEL_16, FUART_TX_FIFO_LEVEL_4);


    while (1) {
        if (cntTx < MAX_BUFSIZE) {
            FIFOStatus = FUART_GetStorageStatus(FUART0, FUART_TX);
            if ((FIFOStatus == FUART_STORAGE_EMPTY)
                || (FIFOStatus == FUART_STORAGE_NORMAL)) {
                FUART_SetTxData(FUART0, Tx_Buf[cntTx]);
                LED_TXDataDisplay(Tx_Buf[cntTx]);
                cntTx++;
            }
        }



        if (SW1_DOWN == SW1_Get()) {    /* press the key SW1 */
            while (FUART_STORAGE_EMPTY != FUART_GetStorageStatus(FUART0, FUART_RX)) {
                receive = FUART_GetRxData(FUART0);
                Rx_Buf[cntRx] = receive;
                cntRx++;
            }

            rxlast = rxthis;
            rxthis = cntRx;

            if (rxlast != rxthis) {     /* there are some data that has been received  */
                LED_RXDataDisplay(LED8_ON);
                delay(0x180000U);
                LED_RXDataDisplay(LED8_OFF);
            } else {            /* receiving data is finished */
                result = Buffercompare(Tx_Buf, Rx_Buf, MAX_BUFSIZE);
                if (result == SAME) {
                    /* received data are same with trnsmitted data */
                    /* RTS and CTS flow control has worked normally */
                    while (1) {
                        LedOn(LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8);
                        delay(0xFFFFFU);
                        LedOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8);
                        delay(0xFFFFFU);
                    }
                } else {
                    /* received data are different with trnsmitted data */
                    /* RTS and CTS flow control doesn't work */
                    while (1) {
                        LedOn(LED1 | LED3 | LED5 | LED7);
                        delay(0xFFFFFU);
                        LedOff(LED1 | LED3 | LED5 | LED7);
                        delay(0xFFFFFU);
                    }
                }
            }
        }
    }
}

/**
  * @brief  Initialize Key SW1, it is port PD1
  * @param  None
  * @retval None
  */
void SW1_Init(void)
{
    GPIO_SetInput(GPIO_PD, GPIO_BIT_1);
}

/**
  * @brief  Get Key SW1 state
  * @param  None
  * @retval SW1_UP or SW1_DOWN
  */
uint8_t SW1_Get(void)
{
    uint8_t tmp = SW1_UP;
    if (GPIO_ReadDataBit(GPIO_PD, GPIO_BIT_1) == 0U) {
        tmp = SW1_DOWN;
    }

    return tmp;

}

/**
  * @brief  Compare Received data and Tranmitted data
  * @param  Src : pointer to point source buffer
  * @param  Dst : pointer to point destination buffer
  * @param  Len : The length of data buffer
  * @retval SAME: received data are same with transmitted data
            DIFF: received data are different with transmitted data
  */
TestResult Buffercompare(const uint32_t * Src, const uint32_t * Dst, uint32_t Len)
{
    uint32_t tmp = 0U;
    TestResult result = SAME;

    for (tmp = 0U; tmp < Len; tmp++) {
        if (Src[tmp] != Dst[tmp]) {
            result = DIFF;
            break;
        } else {
        }
    }

    return result;
}

/**
  * @brief  use leds todisplay the data set to tranmit FIFO
  * @param  the data set to tranmit FIFO
  * @retval None
  */
void LED_TXDataDisplay(uint32_t dat)
{
    uint8_t tmp = 0U;

    tmp = (uint8_t) dat;
    LedOn(tmp);
}

/**
  * @brief  Control LED8 to display that some data are received
  * @param  the LED8 state
  * @retval None
  */
void LED_RXDataDisplay(uint32_t state)
{
    if (state == LED8_ON) {
        uint8_t reg;
        reg = GPIO_ReadData(LED_DATA_PORT);
        reg |= (uint8_t) (LED8);
        GPIO_WriteData(LED_DATA_PORT, reg);
    } else {
        LedOff(LED8);
    }
}

/**
  * @brief  Configure GPIO for Full UART pins, TX02, RX02, CTS2, RTS02
  * @param  None
  * @retval None
  */
void FUART_GPIOConfig(void)
{
    /* Configure port PG0 to be TX02 */
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_4, GPIO_BIT_0);

    /* Configure port PG1 to be RX02 */
    GPIO_SetInput(GPIO_PG, GPIO_BIT_1);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_4, GPIO_BIT_1);

    /* Configure port PG2 to be CTS2 */
    GPIO_SetInput(GPIO_PG, GPIO_BIT_2);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_4, GPIO_BIT_2);
    GPIO_SetOpenDrain(GPIO_PG, GPIO_BIT_2, DISABLE);

    /* Configure port PG4 to be RTS02 */
    GPIO_SetOutput(GPIO_PG, GPIO_BIT_4);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_4, GPIO_BIT_4);
    GPIO_SetOpenDrain(GPIO_PG, GPIO_BIT_4, DISABLE);
}

/**
  * @brief  Initialize Full UART channel 0
  * @param  None
  * @retval None
  */
void FUART_ChInit(void)
{
    FUART_InitTypeDef myFUART;

    myFUART.BaudRate = 300U;
    myFUART.DataBits = FUART_DATA_BITS_8;
    myFUART.StopBits = FUART_STOP_BITS_1;
    myFUART.Parity = FUART_1_PARITY;
    myFUART.Mode = FUART_ENABLE_TX | FUART_ENABLE_RX;

#ifdef RUN_NONE_FLOW_CONTROL
    myFUART.FlowCtrl = FUART_NONE_FLOW_CTRL;
#else
    myFUART.FlowCtrl = FUART_CTS_FLOW_CTRL | FUART_RTS_FLOW_CTRL;
#endif

    FUART_Init(FUART0, &myFUART);
}


/*************************************************************************
 * Function Name: LED_Init
 * Parameters:None
 *
 * Return:None  
 *
 * Description: Init LED ports
 *
 *************************************************************************/
void LEDInit(void)
{
    GPIO_SetOutput(LED_DATA_PORT,0xFFU);    
    GPIO_WriteData(LED_DATA_PORT,0xFFU); 
    
}
/*************************************************************************
 * Function Name: LedOff
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit OFF, but others don't change
 *
 *************************************************************************/
void LedOff(uint8_t led)
{
    uint8_t reg;
    reg = GPIO_ReadData(LED_DATA_PORT);
    reg &= (uint8_t)(~led);
    GPIO_WriteData(LED_DATA_PORT,reg);
}

/*************************************************************************
 * Function Name: LedOn
 * Parameters:LED number
 *
 * Return:None  
 *
 * Description: Led Digtit ON, but others don't change
 *
 *************************************************************************/
void LedOn(uint8_t led)
{
    GPIO_WriteData(LED_DATA_PORT,led);
}

/**
  * @brief  delay some time
  * @param  delay time
  * @retval None.
  */
void delay(uint32_t time)
{
    volatile uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
}
