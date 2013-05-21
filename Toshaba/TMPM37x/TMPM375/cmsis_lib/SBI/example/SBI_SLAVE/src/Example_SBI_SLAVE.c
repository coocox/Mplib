/**
 *******************************************************************************
 * @file    Example_SBI_SLAVE.c
 * @brief   The main functions of SBI slave demo for the
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
uint32_t gI2CRCnt;
uint32_t uSlaveAddr;

uint32_t gI2CRxDataLen;
char gI2CRxData[16U] = { 0U };
volatile uint32_t gSBIMode;

/**
  * @brief  The main routine of SBI demo
  * @param  None
  * @retval None
  */
void Example_SBI_SLAVE(void)
{
    uint32_t gICnt;

    SW_Init();
    hardware_init(UART_RETARGET);

    /* Initialize IO for SBI */
    SBI_IO_Configuration();
    /* Initialize SBI channel */
    myI2C.I2CSelfAddr = SLAVE_ADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    SBI_Enable(TSB_SBI0);
    SBI_SWReset(TSB_SBI0);
    SBI_InitI2C(TSB_SBI0, &myI2C);
    NVIC_EnableIRQ(INTSBI0_IRQn);

    common_uart_disp("K1: SBI SLAVE RECV");
    common_uart_disp("\r\n\r\n");
    /* Initialize variables for SBI */
    gI2CRxDataLen = 7U;
    gI2CRCnt = 0U;
    gSBIMode = MODE_SBI_I2C_INITIAL;
    
    while (1U) {
        
        switch (gSBIMode) {
        case MODE_SBI_I2C_INITIAL:
            for (gICnt = 0U; gICnt < 8U; gICnt++) {
                 gI2CRxData[gICnt] = 0U;
            }
            gSBIMode = MODE_SBI_I2C_RCV;
            break;
            
        case MODE_SBI_I2C_RCV:
            if (SW_Get(SW1)) { 
               if (gI2CRCnt > 7U) {
                  for (gICnt = 1U; gICnt <= gI2CRxDataLen; gICnt++) {
                       gI2CRxData[gICnt - 1U] = gI2CRxData[gICnt];
                  }
                  gI2CRxData[gI2CRxDataLen] = '\0';
                  common_uart_disp(gI2CRxData);
                  common_uart_disp("\r\n");
                  common_uart_disp("MASTER SBI to SLAVE SBI OK");
                  common_uart_disp("\r\n");
                  gSBIMode = MODE_SBI_I2C_INITIAL;
                  gI2CRCnt = 0U;
                  
               }  else {
                /* Do nothing */
               } 
            } else {
                   /* Do nothing */
            }
            break;

        default:
            gI2CRCnt = 0U;
            gSBIMode = MODE_SBI_I2C_INITIAL;
            break;
        }
    }
}

/**
  * @brief  Config the GPIO for SBI
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
    while (1U) {
        __NOP();
    }
}
#endif
