/**
 *******************************************************************************
 * @file    SBI_SLAVE.c
 * @brief   The main functions of SBI slave demo for the
 *          TOSHIBA 'TMPM369' Device Series
 * @version V0.100
 * @date    2011/09/22
 * 
 * THE SOURCE CODE ALAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
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
 * DAMAGES, ND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". TOSHIBA
 * CORPORATION MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
 * WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2011 All rights reserved
 *******************************************************************************
 */

#include "tmpm369_gpio.h"
#include "tmpm369_sbi.h"
#include "tmpm369_uart.h"

#define SELF_ADDR                 ((uint8_t)0xE0)
#define SLAVE_ADDR                ((uint8_t)0xB0)
#define SBI_I2C_SEND             ((uint32_t)0x00000000)
#define SBI_I2C_RECEIVE          ((uint32_t)0x00000001)

#define MODE_SBI_I2C_IDLE        ((uint8_t)0x00)
#define MODE_SBI_I2C_INITIAL     ((uint8_t)0x10)
#define MODE_SBI_I2C_START       ((uint8_t)0x20)
#define MODE_SBI_I2C_TRX         ((uint8_t)0x21)
#define MODE_SBI_I2C_FINISHED    ((uint8_t)0x30)
#define MODE_SBI_I2C_CHECK       ((uint8_t)0x31)

#define SW0         0U
#define SW1         1U
#define SW2         2U
#define SW3         3U
#define SW4         4U
#define SW5         5U
#define SW6         6U
#define SW7         7U

void SBI2_IO_Configuration(void);
void SBI0_IO_Configuration(void);
void SW_Init(void);
uint8_t SW_Get(uint8_t SW);
void UART0_Print(char *string);
void SIO_Configuration(void);
void SIO_ChInit(void);

Result gTRxResult;
SBI_InitI2CTypeDef myI2C;
uint32_t gI2CWCnt;
uint32_t gI2CRCnt;
uint32_t gI2CTxDataLen;
char gI2CTxData[16] = { 0 };

uint32_t gI2CRxDataLen;
char gI2CRxData[16] = { 0 };

uint32_t gSBIMode;

/**
  * @brief  The main routine of SBI demo I2C
  * @param  None
  * @retval None
  */
void SBI_SLAVE(void)
{
    uint32_t gICnt;
    SBI_I2CState i2c_state;

	  SW_Init();
    SIO_Configuration();
    SIO_ChInit();

    /*  Initialize IO for SBIs */
    SBI2_IO_Configuration();
    SBI0_IO_Configuration();
    /* Initialize SBI channel 2 */
    myI2C.I2CSelfAddr = SELF_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI2);
    SBI_SWReset(TSB_SBI2);
    SBI_InitI2C(TSB_SBI2, &myI2C);
    NVIC_EnableIRQ(INTSBI2_IRQn);
    /* Initialize SBI channel 0 */
    myI2C.I2CSelfAddr = SLAVE_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI0);
    SBI_SWReset(TSB_SBI0);
    SBI_InitI2C(TSB_SBI0, &myI2C);
    NVIC_EnableIRQ(INTSBI0_IRQn);

    UART0_Print("K3: SBI2 to SBI0\n\r");
    /* Initialize variables for SBIs */
    gI2CTxDataLen = 0U;
    gI2CWCnt = 0U;
    gI2CRxDataLen = 0U;
    gI2CRCnt = 0U;
    gSBIMode = MODE_SBI_I2C_IDLE;

    while (1) {
        switch (gSBIMode) {
           
        case MODE_SBI_I2C_IDLE:
            if (SW_Get(SW3)) {
                gSBIMode = MODE_SBI_I2C_INITIAL;
            } else {
                /* Do nothing */
            }
            break;
            /* Initialize TRx buffer and Tx length */
        case MODE_SBI_I2C_INITIAL:
            gI2CTxDataLen = 7U;
            gI2CTxData[0] = gI2CTxDataLen;
            gI2CTxData[1] = 'T';
            gI2CTxData[2] = 'O';
            gI2CTxData[3] = 'S';
            gI2CTxData[4] = 'H';
            gI2CTxData[5] = 'I';
            gI2CTxData[6] = 'B';
            gI2CTxData[7] = 'A';
            gI2CWCnt = 0U;
            for (gICnt = 0U; gICnt < 8U; gICnt++) {
                gI2CRxData[gICnt] = 0U;
            }
            gSBIMode = MODE_SBI_I2C_START;
            break;
            /* Check I2C bus state and start TRx */
        case MODE_SBI_I2C_START:
            i2c_state = SBI_GetI2CState(TSB_SBI2);
            if (!i2c_state.Bit.BusState) {
                SBI_SetSendData(TSB_SBI2, SLAVE_ADDR | SBI_I2C_SEND);
                SBI_GenerateI2CStart(TSB_SBI2);
                gSBIMode = MODE_SBI_I2C_TRX;
            } else {
                /* Do nothing */
            }
            break;
            /* Read I2C bus state to check TRx end */
        case MODE_SBI_I2C_TRX:
            if (gI2CRCnt > gI2CRxData[0]) {
                gI2CRxDataLen = gI2CRxData[0];
                gI2CRCnt = 0U;
                gSBIMode = MODE_SBI_I2C_FINISHED;
            } else {
                /* Do nothing */
            }
            break;
            /* Check transmission result */
        case MODE_SBI_I2C_FINISHED:
            if ((gI2CTxData[gI2CTxDataLen] == gI2CRxData[gI2CRxDataLen])) {
                gTRxResult = SUCCESS;
                UART0_Print("Write Over\n\r");
                UART0_Print("K1: Show SBI0\n\r");
                gSBIMode = MODE_SBI_I2C_CHECK;
            } else {
                gTRxResult = ERROR;
                UART0_Print("Write ERROR\n\r");
                gSBIMode = MODE_SBI_I2C_IDLE;
            }
            break;

        case MODE_SBI_I2C_CHECK:
            if (SW_Get(SW1)) {
                for (gICnt = 1U; gICnt <= gI2CRxDataLen; gICnt++) {
                    gI2CRxData[gICnt - 1] = gI2CRxData[gICnt];
                }
                gI2CRxData[gI2CRxDataLen] = 0U;
                UART0_Print(gI2CRxData);
				        UART0_Print("\n\r");
                UART0_Print("SBI2 to SBI0 OK\n\r");
                gSBIMode = MODE_SBI_I2C_IDLE; 
            } else {
                /* Do nothing */
            }								
            break;

        default:
            gI2CTxDataLen = 0U;
            gI2CWCnt = 0U;
            gI2CRxDataLen = 0U;
            gI2CRCnt = 0U;
            gSBIMode = MODE_SBI_I2C_IDLE;
            break;
        }
    }
}

/**
  * @brief  Config the GPIO for SBI2
  * @param  None
  * @retval None
  */
void SBI2_IO_Configuration(void)
{
    GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_5, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_5, GPIO_BIT_1);
    GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_0, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PH, GPIO_BIT_1, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_0, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_1, ENABLE);
    GPIO_SetOpenDrain(GPIO_PH, GPIO_BIT_0, ENABLE);
    GPIO_SetOpenDrain(GPIO_PH, GPIO_BIT_1, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PH, GPIO_BIT_0, ENABLE);
    GPIO_SetPullUp(GPIO_PH, GPIO_BIT_1, ENABLE);
}

/**
  * @brief  Config the GPIO for SBI0
  * @param  None
  * @retval None
  */
void SBI0_IO_Configuration(void)
{
    GPIO_EnableFuncReg(GPIO_PK, GPIO_FUNC_REG_3, GPIO_BIT_2);
    GPIO_EnableFuncReg(GPIO_PK, GPIO_FUNC_REG_3, GPIO_BIT_3);
    GPIO_SetOutputEnableReg(GPIO_PK, GPIO_BIT_2, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PK, GPIO_BIT_3, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PK, GPIO_BIT_2, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PK, GPIO_BIT_3, ENABLE);
    GPIO_SetOpenDrain(GPIO_PK, GPIO_BIT_2, ENABLE);
    GPIO_SetOpenDrain(GPIO_PK, GPIO_BIT_3, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PK, GPIO_BIT_2, ENABLE);
    GPIO_SetPullUp(GPIO_PK, GPIO_BIT_3, ENABLE);
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

/**
  * @brief  SW Init
  * @param  None
  * @retval None
  */
void SW_Init(void)
{
    GPIO_SetInput(GPIO_PI, GPIO_BIT_0);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_1);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_2);
    GPIO_SetInput(GPIO_PI, GPIO_BIT_3);
    
    GPIO_SetOutput(GPIO_PJ, GPIO_BIT_2);
}

/**
  * @brief  Get SW Value
  * @param  SW (choose from SW0 ~ SW7)
  * @retval None
  */
uint8_t SW_Get(uint8_t sw)
{
    uint8_t tmp = 0U;
    if (sw < 4 )
    	{
    		GPIO_WriteDataBit(GPIO_PJ, GPIO_BIT_2, GPIO_BIT_VALUE_0);
    	}else{
    		GPIO_WriteDataBit(GPIO_PJ, GPIO_BIT_2, GPIO_BIT_VALUE_1);
    	}
    switch (sw) {
    case SW0:
    case SW4:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_0) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW1:
    case SW5:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_1) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW2:
    case SW6:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_2) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    case SW3:
    case SW7:
        if (GPIO_ReadDataBit(GPIO_PI, GPIO_BIT_3) == 1U) {
            tmp = 1U;
        } else {
            /*do nothing */
        }
        break;
    default:
        break;
    }
    return tmp;

}

/**
  * @brief  Interrupt Service Routine for SBI2
  * @param  None
  * @retval None
  */
void INTSBI2_IRQHandler(void)
{
    TSB_SBI_TypeDef *SBIx;
    SBI_I2CState sbi_sr;

    SBIx = TSB_SBI2;
    sbi_sr = SBI_GetI2CState(SBIx);

    if (sbi_sr.Bit.MasterSlave) {       /* Master mode */
        if (sbi_sr.Bit.TRx) {   /* Tx mode */
            if (sbi_sr.Bit.LastRxBit) { /* LRB=1: the receiver requires no further data. */
                SBI_GenerateI2CStop(SBIx);
            } else {            /* LRB=0: the receiver requires further data. */
                if (gI2CWCnt <= gI2CTxDataLen) {
                    SBI_SetSendData(SBIx, gI2CTxData[gI2CWCnt]);        /* Send next data */
                    gI2CWCnt++;
                } else {        /* I2C data send finished. */
                    SBI_GenerateI2CStop(SBIx);  /* Stop I2C */
                }
            }
        } else {                /* Rx Mode */
            /* Do nothing */
        }
    } else {                    /* Slave mode */
        /* Do nothing */
    }
}

/**
  * @brief  Interrupt Service Routine for SBI2
  * @param  None
  * @retval None
  */
void INTSBI0_IRQHandler(void)
{
    uint32_t tmp = 0U;
    TSB_SBI_TypeDef *SBIy;
    SBI_I2CState sbi0_sr;

    SBIy = TSB_SBI0;
    sbi0_sr = SBI_GetI2CState(SBIy);

    if (!sbi0_sr.Bit.MasterSlave) {     /* Slave mode */
        if (!sbi0_sr.Bit.TRx) { /* Rx Mode */
            if (sbi0_sr.Bit.SlaveAddrMatch) {
                /* First read is dummy read for Slave address recognize */
                tmp = SBI_GetReceiveData(SBIy);
                gI2CRCnt = 0U;
            } else {
                /* Read I2C received data and save to I2C_RxData buffer */
                tmp = SBI_GetReceiveData(SBIy);
                gI2CRxData[gI2CRCnt] = tmp;
                gI2CRCnt++;
            }
        } else {                /* Tx Mode */
            /* Do nothing */
        }
    } else {                    /* Master mode */
        /* Do nothing */
    }
}
