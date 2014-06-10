/**
 *******************************************************************************
 * @file    main.c
 * @brief   The main functions of SBI slave demo for the
 *          TOSHIBA 'TMPM341' Application Notes 
 * @version V0.100
 * @date    2011/02/24
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


#include "main.h"

void SBI_SLAVE(void);

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
/*int main(void)*/
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
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_2, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PG, GPIO_FUNC_REG_2, GPIO_BIT_1);
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
    GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_2, GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_2, GPIO_BIT_1);
    GPIO_SetOutputEnableReg(GPIO_PD, GPIO_BIT_0, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PD, GPIO_BIT_1, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_0, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_1, ENABLE);
    GPIO_SetOpenDrain(GPIO_PD, GPIO_BIT_0, ENABLE);
    GPIO_SetOpenDrain(GPIO_PD, GPIO_BIT_1, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PD, GPIO_BIT_1, ENABLE);
    GPIO_SetPullUp(GPIO_PD, GPIO_BIT_0, ENABLE);
}



#ifdef DEBUG
/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
