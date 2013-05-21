/**
 *******************************************************************************
 * @file    Read_EEPROM.c
 * @brief   the application functions of Read EEPROM demo for the TOSHIBA
 *          'TMPM333' Device Series 
 * @version V1.200
 * @date    2010/6/23
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
 * (C)Copyright TOSHIBA CORPORATION 2010 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm333_sbi.h"
#include "tx03_common.h"

#define SELFADDR    0xE0U
#define SLAVEADDR   0xA0U
#define SUBADDR     0x0000U
#define DATA1       'S'
#define DATA2       'H'
#define SBI_I2C_SEND                       ((uint32_t)0x00000000)
#define SBI_I2C_RECEIVE                    ((uint32_t)0x00000001)

Result trx_result;

SBI_InitI2CTypeDef myI2C;

uint32_t gI2C_WCnt;
uint32_t gI2C_RCnt;
uint32_t gI2C_TxDataLen;
uint32_t gI2C_TxData[8] = { 0U };

uint32_t gI2C_RxDataLen;
uint32_t gI2C_RxData[8] = { 0U };

void Delay(void);
void SBI2_IO_Configuration(void);

void Read_EEPROM(void)
{
    SBI_I2CState i2c_state;
    TSB_WD_MOD_WDTE = 0U;
    TSB_WD->CR = 0x000000B1;
    SBI2_IO_Configuration();

/*------------------------- Initialize SBI channel 2 -------------------------*/
    myI2C.I2CSelfAddr = SELFADDR;
    myI2C.I2CDataLen = SBI_I2C_DATA_LEN_8;
    myI2C.I2CACKState = ENABLE;
    myI2C.I2CClkDiv = SBI_I2C_CLK_DIV_328;

    SBI_Enable(TSB_SBI2);
    SBI_SWReset(TSB_SBI2);
    SBI_InitI2C(TSB_SBI2, &myI2C);
    NVIC_EnableIRQ(INTSBI2_IRQn);

/*---------------------------- Write EEPROM 2 bytes --------------------------*/
    gI2C_TxData[0] = SUBADDR;
    gI2C_TxData[1] = DATA1;
    gI2C_TxData[2] = DATA2;
    gI2C_TxDataLen = 3U;
    gI2C_RxDataLen = 0U;
    gI2C_WCnt = 0U;
    do{
        i2c_state = SBI_GetI2CState(TSB_SBI2);
    } while (i2c_state.Bit.BusState);
    SBI_SetSendData(TSB_SBI2, SLAVEADDR | SBI_I2C_SEND);
    SBI_GenerateI2CStart(TSB_SBI2);
    while (gI2C_WCnt <= gI2C_TxDataLen);
    Delay();

/*---------------------------- Read EEPROM 2 bytes ---------------------------*/
    do{
        i2c_state = SBI_GetI2CState(TSB_SBI2);
    } while (i2c_state.Bit.BusState);
    gI2C_WCnt = 0U;
    gI2C_RCnt = 0U;
    gI2C_TxData[0] = SUBADDR;
    gI2C_TxDataLen = 1U;
    gI2C_RxDataLen = 2U;
    SBI_SetSendData(TSB_SBI2, SLAVEADDR | SBI_I2C_SEND);
    SBI_GenerateI2CStart(TSB_SBI2);

    while (gI2C_WCnt <= gI2C_TxDataLen);
    Delay();

    do{
        i2c_state = SBI_GetI2CState(TSB_SBI2);
    } while (i2c_state.Bit.BusState);

    SBI_SetSendData(TSB_SBI2, SLAVEADDR | SBI_I2C_RECEIVE);
    SBI_GenerateI2CStart(TSB_SBI2);

    while (gI2C_RCnt <= gI2C_RxDataLen);

/*------------------------- Check transmission result ------------------------*/
    if ((DATA1 == gI2C_RxData[0]) && (DATA2 == gI2C_RxData[1])) {
        trx_result = SUCCESS;
    } else {
        trx_result = ERROR;
    }

    while (1);
}

void Delay(void)
{
    volatile uint32_t i = 0U;
    for (; i <= 10000U; i++);
}

void SBI2_IO_Configuration(void)
{
    TSB_PG->DATA = 0U;
    TSB_PG->CR = 0x30U;
    TSB_PG->FR1 = 0x30U;
    TSB_PG->OD = 0x30U;
    TSB_PG->PUP = 0U;
    TSB_PG->IE = 0x30U;
}

void INTSBI2_IRQHandler(void)
{
    uint32_t tmp = 0U;
    TSB_SBI_TypeDef *SBIx;
    SBI_I2CState sbi_sr;
    
    SBIx = TSB_SBI2;
    sbi_sr = SBI_GetI2CState(SBIx);

    if (sbi_sr.Bit.MasterSlave) {       /* Master mode     */
        if (sbi_sr.Bit.TRx) {   /* Tx mode        */
            if (sbi_sr.Bit.LastRxBit) {       /* LRB=1: the receiver requires no further data. */
                SBI_GenerateI2CStop(SBIx);
            } else {            /* LRB=0: the receiver requires further data. */
                if (gI2C_WCnt < gI2C_TxDataLen) {
                    SBI_SetSendData(SBIx, gI2C_TxData[gI2C_WCnt]);      /* Send next data */
                } else if (gI2C_WCnt == gI2C_TxDataLen) {       /* I2C data send finished. */
                    SBI_GenerateI2CStop(SBIx);
                } else {
                    /* Do nothing */
                }
                gI2C_WCnt++;
            }
        } else {                /* Rx Mode */

            if (gI2C_RCnt > gI2C_RxDataLen) {
                SBI_GenerateI2CStop(SBIx);
            } else {
                if (gI2C_RCnt == gI2C_RxDataLen) {      /* Rx last data */
                    SBI_SetI2CBitNum(SBIx, SBI_I2C_DATA_LEN_1);
                } else if (gI2C_RCnt == (gI2C_RxDataLen - 1U)) {        /* Rx the data second to last */
                    /* Not generate ACK for next data Rx end. */
                    SBI_SetI2CACK(SBIx, DISABLE);
                } else {
                    /* Do nothing */
                }
                tmp = SBI_GetReceiveData(SBIx);
                if (gI2C_RCnt > 0U) {
                    gI2C_RxData[gI2C_RCnt - 1U] = tmp;
                } else {
                    /* first read is dummy read */
                }
                gI2C_RCnt++;
            }
        }
    } else {                    /* Slave mode  */

    }

}
