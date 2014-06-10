/**
 *******************************************************************************
 * @file    tmpm341_sbi.h
 * @brief   This file provides all the functions prototypes for SBI driver.
 * @version V2.0.2.1
 * @date    2011/02/18
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM341_SBI_H
#define __TMPM341_SBI_H


#ifdef __cplusplus
extern "C" {
#endif  /*__cplusplus*/

/* Includes ------------------------------------------------------------------*/
#include "TMPM341.h"
#include "tx03_common.h"

#if defined(__TMPM341_SBI_H)

/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @addtogroup SBI
  * @{
  */

/** @defgroup SBI_Exported_Types
  * @{
  */
    typedef struct {
        uint32_t I2CSelfAddr;   /*!< Specify self-address of the SBI channel in I2C mode */
        uint32_t I2CDataLen;    /*!< Specify data length of the SBI channel in I2C mode */
        FunctionalState I2CACKState;    /*!< Enable or disable the generation of ACK clock */
        uint32_t I2CClkDiv;     /*!< Select the division for SBI source clock in I2C mode */
    } SBI_InitI2CTypeDef;

    typedef union {
        uint32_t All;
        struct {
            uint32_t LastRxBit:1;
            uint32_t GeneralCall:1;
            uint32_t SlaveAddrMatch:1;
            uint32_t ArbitrationLost:1;
            uint32_t INTReq:1;
            uint32_t BusState:1;
            uint32_t TRx:1;
            uint32_t MasterSlave:1;
        } Bit;
    } SBI_I2CState;


#define SBI_CHANNEL_NUMBER              2
#define IS_SBI_PERIPH(param)      (((param) == TSB_SBI0) || \
                                   ((param) == TSB_SBI1))


#define SBI_I2C_DATA_LEN_8              ((uint32_t)0x00000000)
#define SBI_I2C_DATA_LEN_1              ((uint32_t)0x00000001)
#define SBI_I2C_DATA_LEN_2              ((uint32_t)0x00000002)
#define SBI_I2C_DATA_LEN_3              ((uint32_t)0x00000003)
#define SBI_I2C_DATA_LEN_4              ((uint32_t)0x00000004)
#define SBI_I2C_DATA_LEN_5              ((uint32_t)0x00000005)
#define SBI_I2C_DATA_LEN_6              ((uint32_t)0x00000006)
#define SBI_I2C_DATA_LEN_7              ((uint32_t)0x00000007)

#define SBI_I2C_CLK_DIV_104             ((uint32_t)0x00000000)
#define SBI_I2C_CLK_DIV_136             ((uint32_t)0x00000001)
#define SBI_I2C_CLK_DIV_200             ((uint32_t)0x00000002)
#define SBI_I2C_CLK_DIV_328             ((uint32_t)0x00000003)
#define SBI_I2C_CLK_DIV_584             ((uint32_t)0x00000004)
#define SBI_I2C_CLK_DIV_1096            ((uint32_t)0x00000005)
#define SBI_I2C_CLK_DIV_2120            ((uint32_t)0x00000006)
#define IS_SBI_I2C_CLK_DIV(param)       (((param) == SBI_I2C_CLK_DIV_104) || \
                                         ((param) == SBI_I2C_CLK_DIV_136) || \
                                         ((param) == SBI_I2C_CLK_DIV_200) || \
                                         ((param) == SBI_I2C_CLK_DIV_328) || \
                                         ((param) == SBI_I2C_CLK_DIV_584) || \
                                         ((param) == SBI_I2C_CLK_DIV_1096) || \
                                         ((param) == SBI_I2C_CLK_DIV_2120))

#define SBI_I2C_MASTER_TX               ((uint32_t)0x000000C0)
#define SBI_I2C_MASTER_RX               ((uint32_t)0x00000080)
#define SBI_I2C_SLAVE_TX                ((uint32_t)0x00000040)
#define SBI_I2C_SLAVE_RX                ((uint32_t)0x00000000)
#define IS_SBI_I2C_MODE(param)          (((param) == SBI_I2C_MASTER_TX) || \
                                         ((param) == SBI_I2C_MASTER_RX) || \
                                         ((param) == SBI_I2C_SLAVE_TX) || \
                                         ((param) == SBI_I2C_SLAVE_RX))

/** @} */
/* End of group SBI_Exported_Types */

/** @defgroup SBI_Exported_Macros 
  * @{
  */

#define IS_SBI_DATA(param)              ((param) <= (uint32_t)0x000000FF)
#define IS_I2C_BIT_NUM(param)           ((param) <= (uint32_t)0x00000008)
#define IS_SBI_I2C_ADDR(param)          (((param) < (uint32_t)0x000000FF) && \
                                         (!((param) & (uint32_t)0x00000001)))

#define I2C_STATE_SLAVE_TX              ((uint32_t)0x00000044)
#define I2C_STATE_COMPLETE_TX           ((uint32_t)0x00000040)
#define I2C_STATE_SLAVE_RX              ((uint32_t)0x00000004)
#define I2C_STATE_GET_GENERAL_CALL      ((uint32_t)0x00000006)
#define I2C_STATE_TX_TEMINATED          ((uint32_t)0x00000008)
#define I2C_STATE_COMPLETE_RX           ((uint32_t)0x00000002)
/** @} */
/* End of group SBI_Exported_Macros */

/** @defgroup SBI_Exported_FunctionPrototypes
  * @{
  */
    void SBI_Enable(TSB_SBI_TypeDef * SBIx);
    void SBI_Disable(TSB_SBI_TypeDef * SBIx);
    void SBI_SetI2CACK(TSB_SBI_TypeDef * SBIx, FunctionalState NewState);
    void SBI_InitI2C(TSB_SBI_TypeDef * SBIx, SBI_InitI2CTypeDef * InitI2CStruct);
    void SBI_SetI2CBitNum(TSB_SBI_TypeDef * SBIx, uint32_t I2CBitNum);
    void SBI_SWReset(TSB_SBI_TypeDef * SBIx);
    void SBI_ClearI2CINTReq(TSB_SBI_TypeDef * SBIx);
    void SBI_GenerateI2CStart(TSB_SBI_TypeDef * SBIx);
    void SBI_GenerateI2CStop(TSB_SBI_TypeDef * SBIx);
    SBI_I2CState SBI_GetI2CState(TSB_SBI_TypeDef * SBIx);
    void SBI_SetIdleMode(TSB_SBI_TypeDef * SBIx, FunctionalState NewState);
    void SBI_SetSendData(TSB_SBI_TypeDef * SBIx, uint32_t Data);
    uint32_t SBI_GetReceiveData(TSB_SBI_TypeDef * SBIx);
    void SBI_SetI2CFreeDataMode(TSB_SBI_TypeDef * SBIx, FunctionalState NewState);
/** @} */
/* End of group SBI_Exported_FunctionPrototypes */

/** @} */
/* End of group SBI */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_SBI_H) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM341_SBI_H */
