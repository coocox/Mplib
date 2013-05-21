/**
 *******************************************************************************
 * @file    tmpm375_gpio.h
 * @brief   This file provides all the functions prototypes for GPIO driver. 
 * @version V2.0.2.1
 * @date    2013/01/22
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
#ifndef __TMPM375_GPIO_H
#define __TMPM375_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM375.h"
#include "tx03_common.h"


/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @addtogroup GPIO
  * @{
  */
/** @addtogroup  GPIO_Parameter_Definition
  * @{
  */


/** @brief :The maximum number of the Function Register
  * Note for porting:
  * If functiong register 5 is the maximum number in 
  * all the GPIO port,then define FRMAX (5U)
  */
#define FRMAX  (5U)             /* No port has function register 6 */


/** @brief: define for function register
  * Note for porting:
  * If the maximum number of the function Register is 5,
  * then you need to define 5 GPIO_FUNC_REG_x ,
  * the value should be increased from 0 to 4
  */
#define GPIO_FUNC_REG_1                 ((uint8_t)0x00)
#define GPIO_FUNC_REG_2                 ((uint8_t)0x01)
#define GPIO_FUNC_REG_3                 ((uint8_t)0x02)
#define GPIO_FUNC_REG_4                 ((uint8_t)0x03)
#define GPIO_FUNC_REG_5                 ((uint8_t)0x04)

/** @brief :The GPIO_Port enum
  * Note for porting:
  * the port value order from low to high with '1' step
  * and begin with "0".
  */
    typedef enum {
        GPIO_PB = 0U,
        GPIO_PE = 1U,
        GPIO_PF = 2U,
        GPIO_PG = 3U,
        GPIO_PJ = 4U,
        GPIO_PK = 5U,
        GPIO_PM = 6U
    } GPIO_Port;

#define IS_GPIO_PORT(param)             ((param) <= GPIO_PM)    /*parameter checking for port number */


#define RESER  (8U-(FRMAX))

    typedef struct {
        __IO uint32_t DATA;
        __IO uint32_t CR;
        __IO uint32_t FR[FRMAX];
        uint32_t RESERVED0[RESER];
        __IO uint32_t OD;
        __IO uint32_t PUP;
        __IO uint32_t PDN;
        uint32_t RESERVED1;
        __IO uint32_t IE;
    } TSB_Port_TypeDef;

    typedef struct {
        uint8_t PinDATA;
        uint8_t PinCR;
        uint8_t PinFR[FRMAX];
        uint8_t PinOD;
        uint8_t PinPUP;
        uint8_t PinPDN;
        uint8_t PinIE;
    } GPIO_RegTypeDef;

    typedef struct {
        uint8_t IOMode;         /* Set the port input or output mode       */
        uint8_t PullUp;         /* Enable or disable Pullup function       */
        uint8_t OpenDrain;      /* Enable or disable open drain function */
        uint8_t PullDown;       /* Enable or disable Pulldown function */
    } GPIO_InitTypeDef;

#define GPIO_INPUT_MODE                 ((uint8_t)0x00)
#define GPIO_OUTPUT_MODE                ((uint8_t)0x01)
#define GPIO_IO_MODE_NONE               ((uint8_t)0x02)
#define IS_GPIO_IO_MODE_STATE(param)    (((param) == GPIO_INPUT_MODE) || \
                                         ((param) == GPIO_OUTPUT_MODE) || \
                                         ((param) == GPIO_IO_MODE_NONE))

#define GPIO_PULLUP_DISABLE             ((uint8_t)0x00)
#define GPIO_PULLUP_ENABLE              ((uint8_t)0x01)
#define GPIO_PULLUP_NONE                ((uint8_t)0x02)
#define IS_GPIO_PULLUP_STATE(param)     (((param) == GPIO_PULLUP_ENABLE) || \
                                         ((param) == GPIO_PULLUP_DISABLE) || \
                                         ((param) == GPIO_PULLUP_NONE))

#define GPIO_PULLDOWN_DISABLE           ((uint8_t)0x00)
#define GPIO_PULLDOWN_ENABLE            ((uint8_t)0x01)
#define GPIO_PULLDOWN_NONE              ((uint8_t)0x02)
#define IS_GPIO_PULLDOWN_STATE(param)   (((param) == GPIO_PULLDOWN_ENABLE) || \
                                         ((param) == GPIO_PULLDOWN_DISABLE) || \
                                         ((param) == GPIO_PULLDOWN_NONE))

#define GPIO_OPEN_DRAIN_DISABLE          ((uint8_t)0x00)
#define GPIO_OPEN_DRAIN_ENABLE           ((uint8_t)0x01)
#define GPIO_OPEN_DRAIN_NONE             ((uint8_t)0x02)
#define IS_GPIO_OPEN_DRAIN_STATE(param)  (((param) == GPIO_OPEN_DRAIN_ENABLE) || \
                                          ((param) == GPIO_OPEN_DRAIN_DISABLE) || \
                                          ((param) == GPIO_OPEN_DRAIN_NONE))

#define GPIO_BIT_VALUE_1                ((uint8_t)0x01)
#define GPIO_BIT_VALUE_0                ((uint8_t)0x00)

#define IS_GPIO_BIT_VALUE(BitValue)     (((BitValue) == GPIO_BIT_VALUE_1)|| \
                                         ((BitValue) == GPIO_BIT_VALUE_0))

#define GPIO_BIT_0                      ((uint8_t)0x01)
#define GPIO_BIT_1                      ((uint8_t)0x02)
#define GPIO_BIT_2                      ((uint8_t)0x04)
#define GPIO_BIT_3                      ((uint8_t)0x08)
#define GPIO_BIT_4                      ((uint8_t)0x10)
#define GPIO_BIT_5                      ((uint8_t)0x20)
#define GPIO_BIT_6                      ((uint8_t)0x40)
#define GPIO_BIT_7                      ((uint8_t)0x80)
#define GPIO_BIT_ALL                    ((uint8_t)0xFF)

#define IS_GPIO_WRITE(GPIO_x)                       (GPIO_SFRs[(GPIO_x)].PinCR)

#define IS_GPIO_BIT_DATA(GPIO_x,Bit_x)              ((((GPIO_SFRs[(GPIO_x)].PinDATA) & (Bit_x))&&\
                                                    (!((uint8_t)(~(GPIO_SFRs[(GPIO_x)].PinDATA))&(Bit_x)))))

#define IS_GPIO_BIT_OUT(GPIO_x,Bit_x)               (((GPIO_SFRs[(GPIO_x)].PinCR &(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinCR)&(Bit_x)))))

#define IS_GPIO_BIT_IN(GPIO_x,Bit_x)                (((GPIO_SFRs[(GPIO_x)].PinIE &(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinIE)&(Bit_x)))))

#define IS_GPIO_BIT_PUP(GPIO_x,Bit_x)               (((GPIO_SFRs[(GPIO_x)].PinPUP &(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinPUP)&(Bit_x)))))

#define IS_GPIO_BIT_PDN(GPIO_x,Bit_x)               (((GPIO_SFRs[(GPIO_x)].PinPDN &(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinPDN)&(Bit_x)))))

#define IS_GPIO_BIT_OD(GPIO_x,Bit_x)                (((GPIO_SFRs[(GPIO_x)].PinOD &(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinOD)&(Bit_x)))))

#define IS_GPIO_BIT_FR(GPIO_x,FuncReg_x,Bit_x)      (((GPIO_SFRs[(GPIO_x)].PinFR[(FuncReg_x)]&(Bit_x))&&\
                                                    (!((uint8_t)(~GPIO_SFRs[(GPIO_x)].PinFR[(FuncReg_x)])&(Bit_x)))))


#define IS_GPIO_FUNCTION_REG(param)     ((param) < (FRMAX))
#define IS_GPIO_BIT(param)              (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))
/** @} */
/* End of group GPIO_Bit_Define */

/** @defgroup GPIO_Exported_FunctionPrototypes
  * @{
  */
    uint8_t GPIO_ReadData(GPIO_Port GPIO_x);
    uint8_t GPIO_ReadDataBit(GPIO_Port GPIO_x, uint8_t Bit_x);
    void GPIO_WriteData(GPIO_Port GPIO_x, uint8_t Data);
    void GPIO_WriteDataBit(GPIO_Port GPIO_x, uint8_t Bit_x, uint8_t BitValue);
    void GPIO_Init(GPIO_Port GPIO_x, uint8_t Bit_x, GPIO_InitTypeDef * GPIO_InitStruct);
    void GPIO_SetOutput(GPIO_Port GPIO_x, uint8_t Bit_x);
    void GPIO_SetInput(GPIO_Port GPIO_x, uint8_t Bit_x);
    void GPIO_SetInputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState);
    void GPIO_SetOutputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState);
    void GPIO_SetPullUp(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState);
    void GPIO_SetPullDown(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState);
    void GPIO_SetOpenDrain(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState);
    void GPIO_EnableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x);
    void GPIO_DisableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x);
/** @} */
/* End of group GPIO_Exported_FunctionPrototypes */
/** @} */
/* End of group GPIO */
/** @} */
/* End of group TX03_Periph_Driver */


#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM375_GPIO_H */
