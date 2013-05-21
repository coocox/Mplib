/**
 *******************************************************************************
 * @file    tmpm361_gpio.h
 * @brief   This file provides all the functions prototypes for GPIO driver. 
 * @version V2.2.0
 * @date    2010-12-08
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
#ifndef __TMPM361_GPIO_H
#define __TMPM361_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM361.h"
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
    typedef struct {
        uint8_t IOMode;         /* Set the port input or output mode       */
        uint8_t PullUp;         /* Enable or disable Pullup function       */
        uint8_t OpenDrain;      /* Enable or disable open drain function */
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

#define GPIO_OPEN_DRAIN_DISABLE          ((uint8_t)0x00)
#define GPIO_OPEN_DRAIN_ENABLE           ((uint8_t)0x01)
#define GPIO_OPEN_DRAIN_NONE             ((uint8_t)0x02)
#define IS_GPIO_OPEN_DRAIN_STATE(param)  (((param) == GPIO_OPEN_DRAIN_ENABLE) || \
                                          ((param) == GPIO_OPEN_DRAIN_DISABLE) || \
                                          ((param) == GPIO_OPEN_DRAIN_NONE))

#define GPIO_FUNC_REG_1                 ((uint8_t)0x00)
#define GPIO_FUNC_REG_2                 ((uint8_t)0x01)
#define GPIO_FUNC_REG_3                 ((uint8_t)0x02)

    typedef enum {
        GPIO_PA = 0U,
        GPIO_PB = 1U,
        GPIO_PE = 4U,
        GPIO_PF = 5U,
        GPIO_PG = 6U,
        GPIO_PI = 8U,
        GPIO_PJ = 9U,
        GPIO_PL = 11U,
        GPIO_PM = 12U,
        GPIO_PN = 13U,
        GPIO_PP = 15U
    } GPIO_Port;

#define IS_GPIO_PORT(param)             (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_WRITE(param)            (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_INPUT(param)            (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_OUTPUT(param)           (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_PULLUP(param)           (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_OPEN_DRAIN(param)       (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_FUNCTION(param)         (((param) == GPIO_PA)|| \
                                         ((param) == GPIO_PB)|| \
                                         ((param) == GPIO_PE)|| \
                                         ((param) == GPIO_PF)|| \
                                         ((param) == GPIO_PG)|| \
                                         ((param) == GPIO_PI)|| \
                                         ((param) == GPIO_PJ)|| \
                                         ((param) == GPIO_PL)|| \
                                         ((param) == GPIO_PM)|| \
                                         ((param) == GPIO_PN)|| \
                                         ((param) == GPIO_PP))

#define IS_GPIO_PA_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PB_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PE_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                         ((param) == GPIO_FUNC_REG_2)|| \
                                         ((param) == GPIO_FUNC_REG_3))

#define IS_GPIO_PF_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PG_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                         ((param) == GPIO_FUNC_REG_2)|| \
                                         ((param) == GPIO_FUNC_REG_3))

#define IS_GPIO_PI_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1))

#define IS_GPIO_PJ_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_2))

#define IS_GPIO_PL_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                         ((param) == GPIO_FUNC_REG_2)|| \
                                         ((param) == GPIO_FUNC_REG_3))

#define IS_GPIO_PM_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                         ((param) == GPIO_FUNC_REG_2)|| \
                                         ((param) == GPIO_FUNC_REG_3))

#define IS_GPIO_PN_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
                                         ((param) == GPIO_FUNC_REG_2)|| \
                                         ((param) == GPIO_FUNC_REG_3))

#define IS_GPIO_PP_FUNCTION_REG(param)  (((param) == GPIO_FUNC_REG_1)|| \
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
#define GPIO_PA_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PA_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PA_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PA_FR1_BIT_ALL                      ((uint8_t)0xFF)

#define GPIO_PB_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PB_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PB_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PB_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PB_FR1_BIT_ALL                      ((uint8_t)0xFF)

#define GPIO_PE_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PE_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PE_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PE_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PE_FR1_BIT_ALL                      ((uint8_t)0x7F)
#define GPIO_PE_FR2_BIT_ALL                      ((uint8_t)0xFF)
#define GPIO_PE_FR3_BIT_ALL                      ((uint8_t)0xC0)

#define GPIO_PF_OUTPUT_BIT_ALL                   ((uint8_t)0x1F)
#define GPIO_PF_PULLUP_BIT_ALL                   ((uint8_t)0x1F)
#define GPIO_PF_OPEN_DRAIN_BIT_ALL               ((uint8_t)0x1F)
#define GPIO_PF_INPUT_BIT_ALL                    ((uint8_t)0x1F)
#define GPIO_PF_FR1_BIT_ALL                      ((uint8_t)0x1F)

#define GPIO_PG_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PG_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PG_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PG_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PG_FR1_BIT_ALL                      ((uint8_t)0xFF)
#define GPIO_PG_FR2_BIT_ALL                      ((uint8_t)0x33)
#define GPIO_PG_FR3_BIT_ALL                      ((uint8_t)0xCC)

#define GPIO_PI_OUTPUT_BIT_ALL                   ((uint8_t)0x0F)
#define GPIO_PI_PULLUP_BIT_ALL                   ((uint8_t)0x01)
#define GPIO_PI_OPEN_DRAIN_BIT_ALL               ((uint8_t)0x0D)
#define GPIO_PI_INPUT_BIT_ALL                    ((uint8_t)0x0F)
#define GPIO_PI_FR1_BIT_ALL                      ((uint8_t)0x0E)

#define GPIO_PJ_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PJ_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PJ_FR2_BIT_ALL                      ((uint8_t)0xF8)

#define GPIO_PL_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PL_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PL_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PL_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PL_FR1_BIT_ALL                      ((uint8_t)0xFF)
#define GPIO_PL_FR2_BIT_ALL                      ((uint8_t)0xFF)
#define GPIO_PL_FR3_BIT_ALL                      ((uint8_t)0x70)

#define GPIO_PM_OUTPUT_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PM_PULLUP_BIT_ALL                   ((uint8_t)0xFF)
#define GPIO_PM_OPEN_DRAIN_BIT_ALL               ((uint8_t)0xFF)
#define GPIO_PM_INPUT_BIT_ALL                    ((uint8_t)0xFF)
#define GPIO_PM_FR1_BIT_ALL                      ((uint8_t)0xFF)
#define GPIO_PM_FR2_BIT_ALL                      ((uint8_t)0x0F)
#define GPIO_PM_FR3_BIT_ALL                      ((uint8_t)0x11)

#define GPIO_PN_OUTPUT_BIT_ALL                   ((uint8_t)0x0F)
#define GPIO_PN_PULLUP_BIT_ALL                   ((uint8_t)0x0F)
#define GPIO_PN_OPEN_DRAIN_BIT_ALL               ((uint8_t)0x0F)
#define GPIO_PN_INPUT_BIT_ALL                    ((uint8_t)0x0F)
#define GPIO_PN_FR1_BIT_ALL                      ((uint8_t)0x0F)
#define GPIO_PN_FR2_BIT_ALL                      ((uint8_t)0x0C)
#define GPIO_PN_FR3_BIT_ALL                      ((uint8_t)0x0C)

#define GPIO_PP_OUTPUT_BIT_ALL                   ((uint8_t)0x7F)
#define GPIO_PP_PULLUP_BIT_ALL                   ((uint8_t)0x7F)
#define GPIO_PP_OPEN_DRAIN_BIT_ALL               ((uint8_t)0x7F)
#define GPIO_PP_INPUT_BIT_ALL                    ((uint8_t)0x7F)
#define GPIO_PP_FR1_BIT_ALL                      ((uint8_t)0x7F)
#define GPIO_PP_FR2_BIT_ALL                      ((uint8_t)0x3C)

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

#define IS_GPIO_PE_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PF_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4))

#define IS_GPIO_PG_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
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
                                         ((param) == GPIO_BIT_3))

#define IS_GPIO_PJ_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PL_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PM_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6)|| \
                                         ((param) == GPIO_BIT_7))

#define IS_GPIO_PN_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3))

#define IS_GPIO_PP_DATA_BIT(param)      (((param) == GPIO_BIT_0)|| \
                                         ((param) == GPIO_BIT_1)|| \
                                         ((param) == GPIO_BIT_2)|| \
                                         ((param) == GPIO_BIT_3)|| \
                                         ((param) == GPIO_BIT_4)|| \
                                         ((param) == GPIO_BIT_5)|| \
                                         ((param) == GPIO_BIT_6))

#define IS_GPIO_PA_OUTPUT_BIT(param)     (((param) & GPIO_PA_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PA_OUTPUT_BIT_ALL))))

#define IS_GPIO_PA_FR1_BIT(param)        (((param) & GPIO_PA_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PA_FR1_BIT_ALL))))

#define IS_GPIO_PA_OPEN_DRAIN_BIT(param) (((param) & GPIO_PA_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PA_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PA_PULLUP_BIT(param)     (((param) & GPIO_PA_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PA_PULLUP_BIT_ALL))))

#define IS_GPIO_PA_INPUT_BIT(param)      (((param) & GPIO_PA_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PA_INPUT_BIT_ALL))))

#define IS_GPIO_PB_OUTPUT_BIT(param)     (((param) & GPIO_PB_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PB_OUTPUT_BIT_ALL))))

#define IS_GPIO_PB_FR1_BIT(param)        (((param) & GPIO_PB_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PB_FR1_BIT_ALL))))

#define IS_GPIO_PB_OPEN_DRAIN_BIT(param) (((param) & GPIO_PB_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PB_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PB_PULLUP_BIT(param)     (((param) & GPIO_PB_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PB_PULLUP_BIT_ALL))))

#define IS_GPIO_PB_INPUT_BIT(param)      (((param) & GPIO_PB_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PB_INPUT_BIT_ALL))))

#define IS_GPIO_PE_OUTPUT_BIT(param)     (((param) & GPIO_PE_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_OUTPUT_BIT_ALL))))

#define IS_GPIO_PE_FR1_BIT(param)        (((param) & GPIO_PE_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_FR1_BIT_ALL))))

#define IS_GPIO_PE_FR2_BIT(param)        (((param) & GPIO_PE_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_FR2_BIT_ALL))))

#define IS_GPIO_PE_FR3_BIT(param)        (((param) & GPIO_PE_FR3_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_FR3_BIT_ALL))))

#define IS_GPIO_PE_OPEN_DRAIN_BIT(param) (((param) & GPIO_PE_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PE_PULLUP_BIT(param)     (((param) & GPIO_PE_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_PULLUP_BIT_ALL))))

#define IS_GPIO_PE_INPUT_BIT(param)      (((param) & GPIO_PE_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PE_INPUT_BIT_ALL))))

#define IS_GPIO_PF_OUTPUT_BIT(param)     (((param) & GPIO_PF_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PF_OUTPUT_BIT_ALL))))

#define IS_GPIO_PF_FR1_BIT(param)        (((param) & GPIO_PF_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PF_FR1_BIT_ALL))))

#define IS_GPIO_PF_OPEN_DRAIN_BIT(param) (((param) & GPIO_PF_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PF_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PF_PULLUP_BIT(param)     (((param) & GPIO_PF_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PF_PULLUP_BIT_ALL))))

#define IS_GPIO_PF_INPUT_BIT(param)      (((param) & GPIO_PF_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PF_INPUT_BIT_ALL))))

#define IS_GPIO_PG_OUTPUT_BIT(param)     (((param) & GPIO_PG_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_OUTPUT_BIT_ALL))))

#define IS_GPIO_PG_FR1_BIT(param)        (((param) & GPIO_PG_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_FR1_BIT_ALL))))

#define IS_GPIO_PG_FR2_BIT(param)        (((param) & GPIO_PG_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_FR2_BIT_ALL))))

#define IS_GPIO_PG_FR3_BIT(param)        (((param) & GPIO_PG_FR3_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_FR3_BIT_ALL))))

#define IS_GPIO_PG_OPEN_DRAIN_BIT(param) (((param) & GPIO_PG_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PG_PULLUP_BIT(param)     (((param) & GPIO_PG_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_PULLUP_BIT_ALL))))

#define IS_GPIO_PG_INPUT_BIT(param)      (((param) & GPIO_PG_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PG_INPUT_BIT_ALL))))

#define IS_GPIO_PI_OUTPUT_BIT(param)     (((param) & GPIO_PI_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PI_OUTPUT_BIT_ALL))))

#define IS_GPIO_PI_FR1_BIT(param)        (((param) & GPIO_PI_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PI_FR1_BIT_ALL))))

#define IS_GPIO_PI_OPEN_DRAIN_BIT(param) (((param) & GPIO_PI_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PI_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PI_PULLUP_BIT(param)     (((param) & GPIO_PI_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PI_PULLUP_BIT_ALL))))

#define IS_GPIO_PI_INPUT_BIT(param)      (((param) & GPIO_PI_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PI_INPUT_BIT_ALL))))

#define IS_GPIO_PJ_FR2_BIT(param)        (((param) & GPIO_PJ_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PJ_FR2_BIT_ALL))))

#define IS_GPIO_PJ_PULLUP_BIT(param)     (((param) & GPIO_PJ_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PJ_PULLUP_BIT_ALL))))

#define IS_GPIO_PJ_INPUT_BIT(param)      (((param) & GPIO_PJ_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PJ_INPUT_BIT_ALL))))

#define IS_GPIO_PL_OUTPUT_BIT(param)     (((param) & GPIO_PL_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_OUTPUT_BIT_ALL))))

#define IS_GPIO_PL_FR1_BIT(param)        (((param) & GPIO_PL_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_FR1_BIT_ALL))))

#define IS_GPIO_PL_FR2_BIT(param)        (((param) & GPIO_PL_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_FR2_BIT_ALL))))

#define IS_GPIO_PL_FR3_BIT(param)        (((param) & GPIO_PL_FR3_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_FR3_BIT_ALL))))

#define IS_GPIO_PL_OPEN_DRAIN_BIT(param) (((param) & GPIO_PL_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PL_PULLUP_BIT(param)     (((param) & GPIO_PL_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_PULLUP_BIT_ALL))))

#define IS_GPIO_PL_INPUT_BIT(param)      (((param) & GPIO_PL_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PL_INPUT_BIT_ALL))))

#define IS_GPIO_PM_OUTPUT_BIT(param)     (((param) & GPIO_PM_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_OUTPUT_BIT_ALL))))

#define IS_GPIO_PM_FR1_BIT(param)        (((param) & GPIO_PM_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_FR1_BIT_ALL))))

#define IS_GPIO_PM_FR2_BIT(param)        (((param) & GPIO_PM_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_FR2_BIT_ALL))))

#define IS_GPIO_PM_FR3_BIT(param)        (((param) & GPIO_PM_FR3_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_FR3_BIT_ALL))))

#define IS_GPIO_PM_OPEN_DRAIN_BIT(param) (((param) & GPIO_PM_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PM_PULLUP_BIT(param)     (((param) & GPIO_PM_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_PULLUP_BIT_ALL))))

#define IS_GPIO_PM_INPUT_BIT(param)      (((param) & GPIO_PM_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PM_INPUT_BIT_ALL))))

#define IS_GPIO_PN_OUTPUT_BIT(param)     (((param) & GPIO_PN_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_OUTPUT_BIT_ALL))))

#define IS_GPIO_PN_FR1_BIT(param)        (((param) & GPIO_PN_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_FR1_BIT_ALL))))

#define IS_GPIO_PN_FR2_BIT(param)        (((param) & GPIO_PN_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_FR2_BIT_ALL))))

#define IS_GPIO_PN_FR3_BIT(param)        (((param) & GPIO_PN_FR3_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_FR3_BIT_ALL))))

#define IS_GPIO_PN_OPEN_DRAIN_BIT(param) (((param) & GPIO_PN_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PN_PULLUP_BIT(param)     (((param) & GPIO_PN_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_PULLUP_BIT_ALL))))

#define IS_GPIO_PN_INPUT_BIT(param)      (((param) & GPIO_PN_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PN_INPUT_BIT_ALL))))

#define IS_GPIO_PP_OUTPUT_BIT(param)     (((param) & GPIO_PP_OUTPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_OUTPUT_BIT_ALL))))

#define IS_GPIO_PP_FR1_BIT(param)        (((param) & GPIO_PP_FR1_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_FR1_BIT_ALL))))

#define IS_GPIO_PP_FR2_BIT(param)        (((param) & GPIO_PP_FR2_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_FR2_BIT_ALL))))

#define IS_GPIO_PP_OPEN_DRAIN_BIT(param) (((param) & GPIO_PP_OPEN_DRAIN_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_OPEN_DRAIN_BIT_ALL))))

#define IS_GPIO_PP_PULLUP_BIT(param)     (((param) & GPIO_PP_PULLUP_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_PULLUP_BIT_ALL))))

#define IS_GPIO_PP_INPUT_BIT(param)      (((param) & GPIO_PP_INPUT_BIT_ALL)&& \
                                          (!((param) & (~GPIO_PP_INPUT_BIT_ALL))))

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
#endif                          /* __TMPM361_GPIO_H */
