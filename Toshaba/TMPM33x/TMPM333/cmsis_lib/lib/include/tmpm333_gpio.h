/**
 *******************************************************************************
 * @file    tmpm333_gpio.h
 * @brief   This file provides all the functions prototypes for GPIO driver.
 * @version V2.1.0
 * @date    2010/06/15
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
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM333_GPIO_H
#define __TMPM333_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM333.h"
#include "tx03_common.h"

#if defined(__TMPM330_GPIO_H) || defined(__TMPM333_GPIO_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @addtogroup GPIO
  * @{
  */
/** @addtogroup GPIO_Parameter_Definition
  * @{
  */
    typedef struct {
        uint8_t IOMode;         /* Set the port input or output mode       */
        uint8_t PullUp;         /* Enable or disable Pullup function       */
        uint8_t PullDown;       /* Enable or disable Pulldown function     */
        uint8_t OpenDrain;      /* Enable or disable open drain function   */
    } GPIO_InitTypeDef;

#define GPIO_INPUT_MODE                ((uint8_t)0x00)
#define GPIO_OUTPUT_MODE               ((uint8_t)0x01)
#define GPIO_IO_MODE_NONE              ((uint8_t)0x02)
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

#define GPIO_FUNC_REG_1                 ((uint8_t)0x00)
#define GPIO_FUNC_REG_2                 ((uint8_t)0x01)

    typedef enum {
        GPIO_PA = 0,
        GPIO_PB = 1,
        GPIO_PC = 2,
        GPIO_PD = 3,
        GPIO_PE = 4,
        GPIO_PF = 5,
        GPIO_PG = 6,
        GPIO_PH = 7,
        GPIO_PI = 8,
        GPIO_PJ = 9,
        GPIO_PK = 10
    } GPIO_Port;

#define IS_GPIO_PORT(param)             (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PC)|| \
                                         ((param) == GPIO_PD)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_WRITE(param)            (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_INPUT(param)            (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PC)|| \
                                         ((param) == GPIO_PD)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_OUTPUT(param)           (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_PULLUP(param)           (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PC)|| \
                                         ((param) == GPIO_PD)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_PULLDOWN(param)         (((param) == GPIO_PA))

#define IS_GPIO_OPEN_DRAIN(param)        (((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG))

#define IS_GPIO_FUNCTION(param)         (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PD)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PH)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PK))

#define IS_GPIO_PA_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PB_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PD_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PE_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1) || \
                                              ((param) == GPIO_FUNC_REG_2))

#define IS_GPIO_PF_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1) || \
                                              ((param) == GPIO_FUNC_REG_2))

#define IS_GPIO_PG_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PH_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PI_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PJ_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PK_FUNCTION_REGISTER(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                              ((param) == GPIO_FUNC_REG_2))
/** @} */
/* End of group GPIO_Parameter_Definition */

/** @defgroup GPIO_Bit_Define 
  * @{
  */
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

#define GPIO_PA_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PA_PULLUP_BIT_ALL                   ((uint8_t)0xFD)
#define GPIO_PA_PULLDOWN_BIT_ALL                 ((uint8_t)0x02)
#define GPIO_PA_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PB_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PB_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PB_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PC_PULLUP_BIT_ALL                   ((uint8_t)0x0F)
#define GPIO_PC_INPUT_BIT_ALL                    ((uint8_t)0x0F)

#define GPIO_PD_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PD_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PE_OUTPUT_BIT_ALL                   ((uint8_t)0x7F)
#define GPIO_PE_PULLUP_BIT_ALL                   ((uint8_t)0x7F)
#define GPIO_PE_OPEN_DRAIN_BIT_ALL               ((uint8_t)0x7F)
#define GPIO_PE_INPUT_BIT_ALL                    ((uint8_t)0x7F)

#define GPIO_PF_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PF_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PF_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PF_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PG_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PG_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PG_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PG_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PH_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PH_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PH_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PI_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PI_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PI_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PJ_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PJ_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PJ_INPUT_BIT_ALL                    ((uint8_t)0xFF)

#define GPIO_PK_OUTPUT_BIT_ALL                   ((uint8_t)0x07)
#define GPIO_PK_PULLUP_BIT_ALL                   ((uint8_t)0x06)
#define GPIO_PK_INPUT_BIT_ALL                    ((uint8_t)0x07)

#define IS_GPIO_DATA_BIT(param)         (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_BIT_ALL))

#define IS_GPIO_PA_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PB_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PC_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3))

#define IS_GPIO_PD_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PE_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6))

#define IS_GPIO_PF_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PG_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PH_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PI_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PJ_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PK_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2))

#define IS_GPIO_PA_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PA_OUTPUT_BIT_ALL))

#define IS_GPIO_PB_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PB_OUTPUT_BIT_ALL))

#define IS_GPIO_PE_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_PE_OUTPUT_BIT_ALL))

#define IS_GPIO_PF_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PF_OUTPUT_BIT_ALL))

#define IS_GPIO_PG_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PG_OUTPUT_BIT_ALL))

#define IS_GPIO_PH_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PH_OUTPUT_BIT_ALL))

#define IS_GPIO_PI_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PI_OUTPUT_BIT_ALL))

#define IS_GPIO_PJ_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PJ_OUTPUT_BIT_ALL))

#define IS_GPIO_PK_OUTPUT_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_PK_OUTPUT_BIT_ALL))

#define IS_GPIO_PA_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PA_INPUT_BIT_ALL))

#define IS_GPIO_PB_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PB_INPUT_BIT_ALL))

#define IS_GPIO_PC_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_PC_INPUT_BIT_ALL))

#define IS_GPIO_PD_INPUT_BIT(param)     (((param) == GPIO_BIT_0) || \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PD_INPUT_BIT_ALL))

#define IS_GPIO_PE_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_PE_INPUT_BIT_ALL))

#define IS_GPIO_PF_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PF_INPUT_BIT_ALL))

#define IS_GPIO_PG_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PG_INPUT_BIT_ALL))

#define IS_GPIO_PH_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PH_INPUT_BIT_ALL))

#define IS_GPIO_PI_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PI_INPUT_BIT_ALL))

#define IS_GPIO_PJ_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PJ_INPUT_BIT_ALL))

#define IS_GPIO_PK_INPUT_BIT(param)     (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_PK_INPUT_BIT_ALL))

#define IS_GPIO_PA_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PA_PULLUP_BIT_ALL))

#define IS_GPIO_PB_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PB_PULLUP_BIT_ALL))

#define IS_GPIO_PC_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_PC_PULLUP_BIT_ALL))

#define IS_GPIO_PD_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PD_PULLUP_BIT_ALL))

#define IS_GPIO_PE_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_PE_PULLUP_BIT_ALL))

#define IS_GPIO_PF_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PF_PULLUP_BIT_ALL))

#define IS_GPIO_PG_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PG_PULLUP_BIT_ALL))

#define IS_GPIO_PH_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PH_PULLUP_BIT_ALL))

#define IS_GPIO_PI_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PI_PULLUP_BIT_ALL))

#define IS_GPIO_PJ_PULLUP_BIT(param)    (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7)|| \
                                         ((param) == GPIO_PJ_PULLUP_BIT_ALL))

#define IS_GPIO_PK_PULLUP_BIT(param)    (((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_PK_PULLUP_BIT_ALL))

#define IS_GPIO_PA_PULLDOWN_BIT(param)  (((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_PA_PULLDOWN_BIT_ALL))

#define IS_GPIO_PE_OPEN_DRAIN_BIT(param) (((param) == GPIO_BIT_0)|| \
                                          ((param) == GPIO_BIT_1)|| \
                                          ((param) == GPIO_BIT_2)|| \
                                          ((param) == GPIO_BIT_3)|| \
                                          ((param) == GPIO_BIT_4)|| \
                                          ((param) == GPIO_BIT_5)|| \
                                          ((param) == GPIO_BIT_6)|| \
                                          ((param) == GPIO_PE_OPEN_DRAIN_BIT_ALL))

#define IS_GPIO_PF_OPEN_DRAIN_BIT(param) (((param) == GPIO_BIT_0)|| \
                                          ((param) == GPIO_BIT_1)|| \
                                          ((param) == GPIO_BIT_2)|| \
                                          ((param) == GPIO_BIT_3)|| \
                                          ((param) == GPIO_BIT_4)|| \
                                          ((param) == GPIO_BIT_5)|| \
                                          ((param) == GPIO_BIT_6)|| \
                                          ((param) == GPIO_BIT_7)|| \
                                          ((param) == GPIO_PF_OPEN_DRAIN_BIT_ALL))

#define IS_GPIO_PG_OPEN_DRAIN_BIT(param) (((param) == GPIO_BIT_0)|| \
                                          ((param) == GPIO_BIT_1)|| \
                                          ((param) == GPIO_BIT_2)|| \
                                          ((param) == GPIO_BIT_3)|| \
                                          ((param) == GPIO_BIT_4)|| \
                                          ((param) == GPIO_BIT_5)|| \
                                          ((param) == GPIO_BIT_6)|| \
                                          ((param) == GPIO_BIT_7)|| \
                                          ((param) == GPIO_PG_OPEN_DRAIN_BIT_ALL))

#define IS_GPIO_PA_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6))

#define IS_GPIO_PB_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2))

#define IS_GPIO_PD_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3))

#define IS_GPIO_PE_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6))

#define IS_GPIO_PE_FR2_BIT(param)       (((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_6))

#define IS_GPIO_PF_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PF_FR2_BIT(param)       (((param) == GPIO_BIT_2))

#define IS_GPIO_PG_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PH_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PI_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PJ_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PK_FR1_BIT(param)       (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2))

#define IS_GPIO_PK_FR2_BIT(param)       (((param) == GPIO_BIT_1))

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
#endif                          /*(__TMPM330_GPIO_H) || (__TMPM333_GPIO_H) */
#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM333_GPIO_H */
