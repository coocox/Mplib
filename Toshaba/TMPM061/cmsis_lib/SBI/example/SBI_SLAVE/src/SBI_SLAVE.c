/**
 *******************************************************************************
 * @file    main.c
 * @brief   The main functions of SBI slave demo for the
 *          TOSHIBA 'TMPM061' Device Series
 * @version V0.100
 * @date    2012/04/23
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

#include "main.h"

void SBI_Slave(void);

Result gTRxResult;
SBI_InitI2CTypeDef myI2Cm, myI2Cs;
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
void SBI_Slave(void)
{
    uint32_t gICnt;
    SBI_I2CState i2c_state;
    
    LED_Init();
    SW_Init();
    LCD_Configuration();

    /*  Initialize IO for SBIs */
    SBI_IO_Configuration();

    /* Initialize variables for SBIs */
    /* Master mode */
    myI2Cm.I2CSelfAddr = SELF_ADDR;
    myI2Cm.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2Cm.I2CACKState = ENABLE;
    myI2Cm.I2CClkDiv = SBI_I2C_CLK_DIV_328;
    /* Slave mode */
    myI2Cs.I2CSelfAddr = SLAVE_ADDR;
    myI2Cs.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2Cs.I2CACKState = ENABLE;
    myI2Cs.I2CClkDiv = SBI_I2C_CLK_DIV_328;

    gSBIMode = MODE_SBI_I2C_IDLE;
    NVIC_EnableIRQ(INTSBI_IRQn);
    while (1) {
        LED_Off(LED_ALL);
        switch (gSBIMode) {

        case MODE_SBI_I2C_IDLE:
            LED_On(LED0);
            gI2CTxDataLen = 0U;
            gI2CWCnt = 0U;
            gI2CRxDataLen = 0U;
            gI2CRCnt = 0U;

            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text("SW0:Master");
            Send_To_LCD(SECOND_LINE, LCD_COMMAND);
            Send_LCD_Text("SW2:Slave ");
            if (SW_Get(SW0)) {
                gSBIMode = MODE_SBI_MASTER_INITIAL;
            } else if (SW_Get(SW2)) {
                gSBIMode = MODE_SBI_SLAVE_INITIAL;
            } else {
                /* Do Nothing */
            }
            gSBIMode = MODE_SBI_SLAVE_INITIAL;
            break;
            /* Initialize TRx buffer and Tx length */
        case MODE_SBI_MASTER_INITIAL:
            /* Initialize SBI channel to Master mode */
            LED_On(LED1);
            gI2CTxDataLen = 7U;
            gI2CTxData[0] = gI2CTxDataLen;
            gI2CTxData[1] = 'T';
            gI2CTxData[2] = 'O';
            gI2CTxData[3] = 'S';
            gI2CTxData[4] = 'H';
            gI2CTxData[5] = 'I';
            gI2CTxData[6] = 'B';
            gI2CTxData[7] = 'A';

            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text(gI2CTxData + 1);
            Send_To_LCD(SECOND_LINE, LCD_COMMAND);
            Send_LCD_Text("SW1:start send");
            while (SW_Get(SW1) == 0) {
                /* Do Nothing */
            }

            SBI_Enable(TSB_SBI);
            SBI_SWReset(TSB_SBI);
            SBI_InitI2C(TSB_SBI, &myI2Cm);
            gSBIMode = MODE_SBI_I2C_START;
            break;

        case MODE_SBI_SLAVE_INITIAL:
            /* Initialize SBI channel to Slave mode */
            LED_On(LED2);
            gI2CWCnt = 0U;
            for (gICnt = 0U; gICnt < 8U; gICnt++) {
                gI2CRxData[gICnt] = 0U;
            }

            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text("Slave mode:");
            Send_To_LCD(SECOND_LINE, LCD_COMMAND);
            Send_LCD_Text("SW1:Receive");
            
            while (SW_Get(SW1) == 0) {
                /* Do Nothing */
            }
           
            SBI_Enable(TSB_SBI);
            SBI_SWReset(TSB_SBI);
            SBI_InitI2C(TSB_SBI, &myI2Cs);
            gSBIMode = MODE_SBI_I2C_TRX;

            break;

            /* Check I2C bus state and start TRx */
        case MODE_SBI_I2C_START:
            LED_On(LED3);
            i2c_state = SBI_GetI2CState(TSB_SBI);
            if (!i2c_state.Bit.BusState) {
                SBI_SetSendData(TSB_SBI, SLAVE_ADDR | SBI_I2C_SEND);
                SBI_GenerateI2CStart(TSB_SBI);
                gSBIMode = MODE_SBI_MASTER_FINISHED;
            } else {
                /* Do nothing */
            }
            break;
            /* Read I2C bus state to check TRx end */
        case MODE_SBI_I2C_TRX:
            LED_On(LED0|LED3);
            if (gI2CRCnt > gI2CRxData[0]) {
                gI2CRxDataLen = gI2CRxData[0];
                gI2CRCnt = 0U;
                gSBIMode = MODE_SBI_SLAVE_FINISHED;
            } else {
                /* Do nothing */
            }
            break;
            /* Check transmission result */
        case MODE_SBI_MASTER_FINISHED:
            LED_On(LED1|LED3);
            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text("Send Over");
            Send_To_LCD(SECOND_LINE, LCD_COMMAND);
            Send_LCD_Text("SW3:back");
            if (SW_Get(SW3)) {
                SBI_Disable(TSB_SBI);
                gSBIMode = MODE_SBI_I2C_IDLE;
            } else {
                /* Do Nothing */
            }
            break;

        case MODE_SBI_SLAVE_FINISHED:
            LED_On(LED2|LED3);
            Send_To_LCD(FIRST_LINE, LCD_COMMAND);
            Send_LCD_Text(gI2CRxData + 1);
            Send_To_LCD(SECOND_LINE, LCD_COMMAND);
            Send_LCD_Text("SW3:back");
            if (SW_Get(SW3)) {
                SBI_Disable(TSB_SBI);
                gSBIMode = MODE_SBI_I2C_IDLE;
            } else {
                /* Do Nothing */
            }
            break;

        default:

            gSBIMode = MODE_SBI_I2C_IDLE;
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
  /*SDA:PJ0,P28; SCL: PJ1,P29*/
    TSB_PJ->FR1 |= 0x03U;
    TSB_PJ->CR |= 0x03U;
    TSB_PJ->IE |= 0x03U;
    TSB_PJ->OD |= 0x03U;
    TSB_PJ->PUP |= 0x03U;  
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
