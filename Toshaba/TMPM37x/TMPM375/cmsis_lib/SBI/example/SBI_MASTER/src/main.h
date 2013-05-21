/**
 *******************************************************************************
 * @file    main.h
 * @brief   The header file for main.c of SBI master demo for the
 *          TOSHIBA 'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/03/18
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
 * (C)Copyright TOSHIBA CORPORATION 2013 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#include "sw.h"
#include "tmpm375_gpio.h"
#include "tmpm375_sbi.h"
#include "tmpm375_uart.h"

#define SELF_ADDR                 ((uint8_t)0xE0)
#define SLAVE_ADDR                ((uint8_t)0xB0)
#define SBI_I2C_SEND             ((uint32_t)0x00000000)
#define SBI_I2C_RECEIVE          ((uint32_t)0x00000001)
#define SBICR2_MST_SET           ((uint32_t)0x000000C0)

#define MODE_SBI_I2C_IDLE        ((uint8_t)0x00)
#define MODE_SBI_I2C_INITIAL     ((uint8_t)0x10)
#define MODE_SBI_I2C_START       ((uint8_t)0x20)
#define MODE_SBI_I2C_TRX         ((uint8_t)0x21)
#define SBI_I2C_TRX_FINISHED     ((uint8_t)0x30)
#define SBI_I2C_RCV_FINISHED     ((uint8_t)0x31)
#define MODE_SBI_I2C_CHECK       ((uint8_t)0x40)
#define MODE_SBI_I2C_ACK         ((uint8_t)0x41)
#define MODE_SBI_I2C_RCV_ACK     ((uint8_t)0x50)
#define MODE_SBI_I2C_CHECK_RCV   ((uint8_t)0x51) 
#define MODE_SBI_MASTER_RECV_FINISHED  (((uint8_t)0x60))


#define SBICR2_MASTER_RECV_START ((uint32_t)0x000000B0)

#define SBI_I2C_ACK              ((uint8_t)0x10)
  
extern uint32_t gI2CWCnt;
extern uint32_t gI2CTxDataLen;
extern char gI2CTxData[16];

void SBI_IO_Configuration(void);


#endif                          /* __MAIN_H */
