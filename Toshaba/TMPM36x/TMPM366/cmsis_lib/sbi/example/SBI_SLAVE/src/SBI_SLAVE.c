/**
 *******************************************************************************
 * @file    SBI_SLAVE.c
 * @brief   The main functions of SBI slave demo for the
 *          TOSHIBA 'TMPM366' Application Notes 
 * @version V0.101
 * @date    2011/03/09
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


#include "tmpm366_gpio.h"
#include "tmpm366_sbi.h"

#define SELF_ADDR                ((uint8_t)0xE0)
#define SLAVE_ADDR               ((uint8_t)0xB0)
#define SBI_I2C_SEND             ((uint32_t)0x00000000)

#define MODE_SBI_I2C_IDLE        ((uint8_t)0x00)
#define MODE_SBI_I2C_INITIAL     ((uint8_t)0x10)
#define MODE_SBI_I2C_START       ((uint8_t)0x20)
#define MODE_SBI_I2C_TRX         ((uint8_t)0x21)
#define MODE_SBI_I2C_FINISHED    ((uint8_t)0x30)


Result gTRxResult;
SBI_InitI2CTypeDef myI2C;
uint32_t gI2CWCnt;
uint32_t gI2CRCnt;
uint32_t gI2CTxDataLen;
char gI2CTxData[16] = { 0 };

uint32_t gI2CRxDataLen;
char gI2CRxData[16] = { 0 };

uint32_t gSBIMode;

void SBI0_IO_Configuration(void);
void SBI1_IO_Configuration(void);
void INTSBI0_IRQHandler(void);
void INTSBI1_IRQHandler(void);

void SBI_SLAVE(void)
{
    uint32_t gICnt;
    SBI_I2CState i2c_state;

    /*  Initialize IO for Key input and SBIs */
    SBI0_IO_Configuration();
    SBI1_IO_Configuration();
    /* Initialize SBI channel 0 */
    myI2C.I2CSelfAddr = SELF_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI0);
    SBI_SWReset(TSB_SBI0);
    SBI_InitI2C(TSB_SBI0, &myI2C);
    NVIC_EnableIRQ(INTSBI0_IRQn);
    /* Initialize SBI channel 1 */
    myI2C.I2CSelfAddr = SLAVE_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI1);
    SBI_SWReset(TSB_SBI1);
    SBI_InitI2C(TSB_SBI1, &myI2C);
    NVIC_EnableIRQ(INTSBI1_IRQn);

    /* Initialize variables for SBIs */
    gI2CTxDataLen = 0U;
    gI2CWCnt = 0U;
    gI2CRxDataLen = 0U;
    gI2CRCnt = 0U;
    gSBIMode = MODE_SBI_I2C_IDLE;

    while (1) {
        switch (gSBIMode) {
            /* Key3 input check */
        case MODE_SBI_I2C_IDLE:
            if (TRUE) {
                gSBIMode = MODE_SBI_I2C_INITIAL;
            } else {
                /* Do nothing */
            }
            break;
            /* Initialize TRx buffer and Txlength */
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
            i2c_state = SBI_GetI2CState(TSB_SBI0);
            if (!i2c_state.Bit.BusState) {
                SBI_SetSendData(TSB_SBI0, SLAVE_ADDR | SBI_I2C_SEND);
                SBI_GenerateI2CStart(TSB_SBI0);
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
            } else {
                gTRxResult = ERROR;
            }
            gSBIMode = MODE_SBI_I2C_IDLE;
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
  * @brief  Config the GPIO for SBI0
  * @param  None
  * @retval None
  */
void SBI0_IO_Configuration(void)
{
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_1, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_1, GPIO_BIT_1);
    GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_0, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PG, GPIO_BIT_1, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_0, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PG, GPIO_BIT_1, ENABLE);
    GPIO_SetOpenDrain(GPIO_PG, GPIO_BIT_0, ENABLE);
    GPIO_SetOpenDrain(GPIO_PG, GPIO_BIT_1, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PG, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(GPIO_PG, GPIO_BIT_0, ENABLE);
}

/**
  * @brief  Config the GPIO for SBI1
  * @param  None
  * @retval None
  */
void SBI1_IO_Configuration(void)
{
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_4);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_1, GPIO_BIT_5);
    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_4, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_5, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_4, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_5, ENABLE);
    GPIO_SetOpenDrain(GPIO_PE, GPIO_BIT_4, ENABLE);
    GPIO_SetOpenDrain(GPIO_PE, GPIO_BIT_5, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_5, ENABLE);
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_4, ENABLE);
}

/**
  * @brief  Interrupt Service Routine for SBI0
  * @param  None
  * @retval None
  */
void INTSBI0_IRQHandler(void)
{
    TSB_SBI_TypeDef *SBIx;
    SBI_I2CState sbi_sr;

    SBIx = TSB_SBI0;
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
  * @brief  Interrupt Service Routine for SBI1
  * @param  None
  * @retval None
  */
void INTSBI1_IRQHandler(void)
{
    uint32_t tmp = 0U;
    TSB_SBI_TypeDef *SBIy;
    SBI_I2CState sbi1_sr;

    SBIy = TSB_SBI1;
    sbi1_sr = SBI_GetI2CState(SBIy);

    if (!sbi1_sr.Bit.MasterSlave) {     /* Slave mode */
        if (!sbi1_sr.Bit.TRx) { /* Rx Mode */
            if (sbi1_sr.Bit.SlaveAddrMatch) {
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
