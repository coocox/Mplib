/**
 *******************************************************************************
 * @file    Example_SBI_MASTER.c
 * @brief   The main functions of SBI master demo for the
 *          TOSHIBA 'TMPM375' Device Series
 * @version V0.100
 * @date    2013/03/18
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

#include "main.h"
SBI_InitI2CTypeDef myI2C;
uint32_t gI2CWCnt;
uint32_t gI2CTxDataLen;
char gI2CTxData[16] = { 0 };

uint32_t gSBIMode;

/**
  * @brief  Get state of SW3 to check key value is or not same  
  * @param  None
  * @retval None
  */
uint8_t getkey(uint8_t sw)
{
   uint32_t i=20000;
   uint8_t keyflag;
   uint8_t oneflag,twoflag;
   oneflag=SW_Get(sw);
   while(i--);
   twoflag=SW_Get(sw);
   if(oneflag!=twoflag) {
        keyflag=1;
   } else { 
     keyflag=0;
   }
    return keyflag;
}

/**
  * @brief  The main routine of SBI demo I2C
  * @param  None
  * @retval None
  */
void Example_SBI_MASTER(void)
{   
    SBI_I2CState i2c_state;
    SW_Init();
  
    /* Initialize IO for SBI */
    SBI_IO_Configuration();
    /* Initialize SBI channel */
    myI2C.I2CSelfAddr = SELF_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI0);
    SBI_SWReset(TSB_SBI0);
    SBI_InitI2C(TSB_SBI0, &myI2C);
    NVIC_EnableIRQ(INTSBI0_IRQn);
  
    /* Initialize variables for SBI */
    gI2CTxDataLen = 0U;
    gI2CWCnt = 0U;
    gSBIMode = MODE_SBI_I2C_IDLE;
    
    while (1) {
        switch (gSBIMode) {
            /* SW3 input check */
        case MODE_SBI_I2C_IDLE:
            if (getkey(SW3)) {
              while (SW_Get(SW3)); 
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
            gSBIMode = MODE_SBI_I2C_START;
            break;
            /* Check I2C bus state and start TRx */
        case MODE_SBI_I2C_START:
            i2c_state = SBI_GetI2CState(TSB_SBI0);
            if (!i2c_state.Bit.BusState) {
              gSBIMode = MODE_SBI_I2C_TRX;
              SBI_SetSendData(TSB_SBI0, SLAVE_ADDR | SBI_I2C_SEND);
              SBI_GenerateI2CStart(TSB_SBI0);
            } else {
                /* Do nothing */
            }
            break;
        case MODE_SBI_I2C_TRX:  
            if (gI2CWCnt > 7) {
                 gI2CWCnt = 0U;
                 gSBIMode = MODE_SBI_I2C_IDLE;
            } else {
                 /* Do nothing */
            } 
            break;
        default:
            gI2CTxDataLen = 0U;
            gI2CWCnt = 0U;
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
void SBI_IO_Configuration(void)
{
    GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_5, GPIO_BIT_5);
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_5, GPIO_BIT_2);
    GPIO_SetOutputEnableReg(GPIO_PB, GPIO_BIT_5, ENABLE);
    GPIO_SetOutputEnableReg(GPIO_PE, GPIO_BIT_2, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PB, GPIO_BIT_5, ENABLE);
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_2, ENABLE);
    GPIO_SetOpenDrain(GPIO_PB, GPIO_BIT_5, ENABLE);
    GPIO_SetOpenDrain(GPIO_PE, GPIO_BIT_2, ENABLE);
    /* Pull up for SDA&SCL */
    GPIO_SetPullUp(GPIO_PB, GPIO_BIT_5, ENABLE);
    GPIO_SetPullUp(GPIO_PE, GPIO_BIT_2, ENABLE);
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
