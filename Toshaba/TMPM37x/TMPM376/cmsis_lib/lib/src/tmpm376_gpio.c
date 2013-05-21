/**
 *******************************************************************************
 * @file    tmpm376_gpio.c
 * @brief   This file provides API functions for GPIO driver.
 * @version V2.0.2.1
 * @date    2011/12/06
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

/* Includes ------------------------------------------------------------------*/
#include "tmpm376_gpio.h"

#if defined(__TMPM376_GPIO_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */
/** @defgroup GPIO
  * @brief GPIO driver modules
  * @{
  */
/** @defgroup GPIO_Exported_Functions
  * @{
  */
/**
  * @brief  Read GPIO Data register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @retval Data:The value of DATA register.
  */
uint8_t GPIO_ReadData(GPIO_Port GPIO_x)
{
    uint8_t Data = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        Data = (uint8_t) (TSB_PA->DATA);
        break;
    case GPIO_PB:
        Data = (uint8_t) (TSB_PB->DATA);
        break;
    case GPIO_PC:
        Data = (uint8_t) (TSB_PC->DATA);
        break;
    case GPIO_PD:
        Data = (uint8_t) (TSB_PD->DATA);
        break;
    case GPIO_PE:
        Data = (uint8_t) (TSB_PE->DATA);
        break;
    case GPIO_PF:
        Data = (uint8_t) (TSB_PF->DATA);
        break;
    case GPIO_PG:
        Data = (uint8_t) (TSB_PG->DATA);
        break;
    case GPIO_PH:
        Data = (uint8_t) (TSB_PH->DATA);
        break;
    case GPIO_PI:
        Data = (uint8_t) (TSB_PI->DATA);
        break;
    case GPIO_PJ:
        Data = (uint8_t) (TSB_PJ->DATA);
        break;
    case GPIO_PK:
        Data = (uint8_t) (TSB_PK->DATA);
        break;
    case GPIO_PL:
        Data = (uint8_t) (TSB_PL->DATA);
        break;
    case GPIO_PM:
        Data = (uint8_t) (TSB_PM->DATA);
        break;
    case GPIO_PN:
        Data = (uint8_t) (TSB_PN->DATA);
        break;
    default:
        /* Do nothing */
        break;
    }
    return (Data);
}

/**
  * @brief  Read Bit of GPIO Data register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7.
  * @retval BitValue:The value of specified Bit.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_VALUE_0, GPIO_BIT_VALUE_1
  */
uint8_t GPIO_ReadDataBit(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t BitValue = GPIO_BIT_VALUE_0;
    uint8_t Data = 0U;
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PA->DATA);
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PB->DATA);
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PC->DATA);
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PD->DATA);
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PE->DATA);
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PF->DATA);
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PG->DATA);
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PH->DATA);
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PI->DATA);
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PJ->DATA);
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PK->DATA);
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PL->DATA);
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PM->DATA);
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_DATA_BIT(Bit_x));
        Data = (uint8_t) (TSB_PN->DATA);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = (uint8_t) (Data & Bit_x);
    if (tmp) {
        BitValue = GPIO_BIT_VALUE_1;
    } else {
        BitValue = GPIO_BIT_VALUE_0;
    }
    return (BitValue);
}

/**
  * @brief  Write specified value to GPIO DATA register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Data: specified value will be written to GPIO DATA register.
  * @retval None
  */
void GPIO_WriteData(GPIO_Port GPIO_x, uint8_t Data)
{
    /* Check the parameters */
    assert_param(IS_GPIO_WRITE(GPIO_x));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        TSB_PA->DATA = (uint32_t) Data;
        break;
    case GPIO_PB:
        TSB_PB->DATA = (uint32_t) Data;
        break;
    case GPIO_PC:
        TSB_PC->DATA = (uint32_t) Data;
        break;
    case GPIO_PD:
        TSB_PD->DATA = (uint32_t) Data;
        break;
    case GPIO_PE:
        TSB_PE->DATA = (uint32_t) Data;
        break;
    case GPIO_PF:
        TSB_PF->DATA = (uint32_t) Data;
        break;
    case GPIO_PG:
        TSB_PG->DATA = (uint32_t) Data;
        break;
    case GPIO_PH:
        TSB_PH->DATA = (uint32_t) Data;
        break;
    case GPIO_PI:
        TSB_PI->DATA = (uint32_t) Data;
        break;
    case GPIO_PJ:
        TSB_PJ->DATA = (uint32_t) Data;
        break;
    case GPIO_PK:
        TSB_PK->DATA = (uint32_t) Data;
        break;
    case GPIO_PL:
        TSB_PL->DATA = (uint32_t) Data;
        break;
    case GPIO_PM:
        TSB_PM->DATA = (uint32_t) Data;
        break;
    case GPIO_PN:
        TSB_PN->DATA = (uint32_t) Data;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Write to specified Bit of GPIO DATA register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7.
  * @param BitValue:The value of specified Bit.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_VALUE_0, GPIO_BIT_VALUE_1
  * @retval None
  */
void GPIO_WriteDataBit(GPIO_Port GPIO_x, uint8_t Bit_x, uint8_t BitValue)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_WRITE(GPIO_x));
    assert_param(IS_GPIO_BIT_VALUE(BitValue));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PA->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PA->DATA = (uint32_t) tmp;
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PB->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PB->DATA = (uint32_t) tmp;
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PC->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PC->DATA = (uint32_t) tmp;
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PD->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PD->DATA = (uint32_t) tmp;
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PE->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PE->DATA = (uint32_t) tmp;
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PF->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PF->DATA = (uint32_t) tmp;
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PG->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PG->DATA = (uint32_t) tmp;
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PH->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PH->DATA = (uint32_t) tmp;
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PI->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PI->DATA = (uint32_t) tmp;
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PJ->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PJ->DATA = (uint32_t) tmp;
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PK->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PK->DATA = (uint32_t) tmp;
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PL->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PL->DATA = (uint32_t) tmp;
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PM->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PM->DATA = (uint32_t) tmp;
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_DATA_BIT(Bit_x));
        tmp = (uint8_t) (TSB_PN->DATA);
        if (BitValue) {
            tmp |= Bit_x;
        } else {
            Bit_x = (~Bit_x);
            tmp &= Bit_x;
        }
        TSB_PN->DATA = (uint32_t) tmp;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Initialize the specified GPIO pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param  GPIO_InitStruct: The structure containing basic GPIO configuration.
  * @retval None
  */
void GPIO_Init(GPIO_Port GPIO_x, uint8_t Bit_x, GPIO_InitTypeDef * GPIO_InitStruct)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_POINTER_NOT_NULL(GPIO_InitStruct));
    assert_param(IS_GPIO_IO_MODE_STATE(GPIO_InitStruct->IOMode));
    assert_param(IS_GPIO_PULLUP_STATE(GPIO_InitStruct->PullUp));
    assert_param(IS_GPIO_PULLDOWN_STATE(GPIO_InitStruct->PullDown));
    assert_param(IS_GPIO_OPEN_DRAIN_STATE(GPIO_InitStruct->OpenDrain));

    tmp = GPIO_InitStruct->IOMode;
    switch (tmp) {
    case GPIO_INPUT_MODE:
        GPIO_SetInput(GPIO_x, Bit_x);
        break;
    case GPIO_OUTPUT_MODE:
        GPIO_SetOutput(GPIO_x, Bit_x);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->PullUp;
    switch (tmp) {
    case GPIO_PULLUP_ENABLE:
        GPIO_SetPullUp(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_PULLUP_DISABLE:
        GPIO_SetPullUp(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->PullDown;
    switch (tmp) {
    case GPIO_PULLDOWN_ENABLE:
        GPIO_SetPullDown(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_PULLDOWN_DISABLE:
        GPIO_SetPullDown(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->OpenDrain;
    switch (tmp) {
    case GPIO_OPEN_DRAIN_ENABLE:
        GPIO_SetOpenDrain(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_OPEN_DRAIN_DISABLE:
        GPIO_SetOpenDrain(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set specified GPIO Pin as output port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PM,
  *   GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @retval None
  */
void GPIO_SetOutput(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_OUTPUT(GPIO_x));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_OUTPUT_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_OUTPUT_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_OUTPUT_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_OUTPUT_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_OUTPUT_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_OUTPUT_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_OUTPUT_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_OUTPUT_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_OUTPUT_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_OUTPUT_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_OUTPUT_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_OUTPUT_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_OUTPUT_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PA->FR1 &= tmp;
        TSB_PA->FR2 &= tmp;
        TSB_PA->IE &= tmp;
        TSB_PA->CR |= Bit_x;
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PB->FR1 &= tmp;
        TSB_PB->IE &= tmp;
        TSB_PB->CR |= Bit_x;
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PC->FR1 &= tmp;
        TSB_PC->IE &= tmp;
        TSB_PC->CR |= Bit_x;
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PD->FR1 &= tmp;
        TSB_PD->FR2 &= tmp;
        TSB_PD->IE &= tmp;
        TSB_PD->CR |= Bit_x;
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PE->FR1 &= tmp;
        TSB_PE->FR2 &= tmp;
        TSB_PE->IE &= tmp;
        TSB_PE->CR |= Bit_x;
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PF->FR1 &= tmp;
        TSB_PF->FR2 &= tmp;
        TSB_PF->FR3 &= tmp;
        TSB_PF->IE &= tmp;
        TSB_PF->CR |= Bit_x;
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PG->FR1 &= tmp;
        TSB_PG->IE &= tmp;
        TSB_PG->CR |= Bit_x;
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PH->FR1 &= tmp;
        TSB_PH->IE &= tmp;
        TSB_PH->CR |= Bit_x;
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PI->IE &= tmp;
        TSB_PI->CR |= Bit_x;
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PJ->FR1 &= tmp;
        TSB_PJ->IE &= tmp;
        TSB_PJ->CR |= Bit_x;
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PK->FR1 &= tmp;
        TSB_PK->IE &= tmp;
        TSB_PK->CR |= Bit_x;
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PM->IE &= tmp;
        TSB_PM->CR |= Bit_x;
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_OUTPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PN->FR1 &= tmp;
        TSB_PN->IE &= tmp;
        TSB_PN->CR |= Bit_x;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set specified GPIO Pin as input port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @retval None
  */
void GPIO_SetInput(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_INPUT(GPIO_x));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_INPUT_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_INPUT_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_INPUT_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_INPUT_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_INPUT_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_INPUT_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_INPUT_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_INPUT_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_INPUT_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_INPUT_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_INPUT_BIT_ALL;
            break;
        case GPIO_PL:
            Bit_x = GPIO_PL_INPUT_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_INPUT_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_INPUT_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PA->FR1 &= tmp;
        TSB_PA->FR2 &= tmp;
        TSB_PA->CR &= tmp;
        TSB_PA->IE |= Bit_x;
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PB->FR1 &= tmp;
        TSB_PB->CR &= tmp;
        TSB_PB->IE |= Bit_x;
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PC->FR1 &= tmp;
        TSB_PC->CR &= tmp;
        TSB_PC->IE |= Bit_x;
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PD->FR1 &= tmp;
        TSB_PD->FR2 &= tmp;
        TSB_PD->CR &= tmp;
        TSB_PD->IE |= Bit_x;
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PE->FR1 &= tmp;
        TSB_PE->FR2 &= tmp;
        TSB_PE->CR &= tmp;
        TSB_PE->IE |= Bit_x;
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PF->FR1 &= tmp;
        TSB_PF->FR2 &= tmp;
        TSB_PF->FR3 &= tmp;
        TSB_PF->CR &= tmp;
        TSB_PF->IE |= Bit_x;
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PG->FR1 &= tmp;
        TSB_PG->CR &= tmp;
        TSB_PG->IE |= Bit_x;
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PH->FR1 &= tmp;
        TSB_PH->CR &= tmp;
        TSB_PH->IE |= Bit_x;
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PI->CR &= tmp;
        TSB_PI->IE |= Bit_x;
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PJ->FR1 &= tmp;
        TSB_PJ->CR &= tmp;
        TSB_PJ->IE |= Bit_x;
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PK->FR1 &= tmp;
        TSB_PK->CR &= tmp;
        TSB_PK->IE |= Bit_x;
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PL->FR1 &= tmp;
        TSB_PL->IE |= Bit_x;
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PM->CR &= tmp;
        TSB_PM->IE |= Bit_x;
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_INPUT_BIT(Bit_x));
        tmp = (~Bit_x);
        TSB_PN->FR1 &= tmp;
        TSB_PN->CR &= tmp;
        TSB_PN->IE |= Bit_x;
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set or clear the bit setting in output control register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PM,
  *   GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param NewState: The output state of the pin.
  *   This parameter can be one of the following values:
  *   ENABLE , DISABLE.
  * @retval None
  */
void GPIO_SetOutputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_OUTPUT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_OUTPUT_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_OUTPUT_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_OUTPUT_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_OUTPUT_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_OUTPUT_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_OUTPUT_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_OUTPUT_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_OUTPUT_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_OUTPUT_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_OUTPUT_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_OUTPUT_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_OUTPUT_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_OUTPUT_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PA->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PA->CR &= tmp;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PB->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PB->CR &= tmp;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PC->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PC->CR &= tmp;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PD->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PD->CR &= tmp;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PE->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PE->CR &= tmp;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PF->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PF->CR &= tmp;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PG->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PG->CR &= tmp;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PH->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PH->CR &= tmp;
        }
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PI->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PI->CR &= tmp;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PJ->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PJ->CR &= tmp;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PK->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PK->CR &= tmp;
        }
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PM->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PM->CR &= tmp;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_OUTPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PN->CR |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PN->CR &= tmp;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set or clear the bit setting in input control register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PL,
  *   GPIO_PM, GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param NewState: The input state of the pin.
  *   This parameter can be one of the following values:
  *   ENABLE , DISABLE.
  * @retval None
  */
void GPIO_SetInputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_INPUT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_INPUT_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_INPUT_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_INPUT_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_INPUT_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_INPUT_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_INPUT_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_INPUT_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_INPUT_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_INPUT_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_INPUT_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_INPUT_BIT_ALL;
            break;
        case GPIO_PL:
            Bit_x = GPIO_PL_INPUT_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_INPUT_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_INPUT_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PA->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PA->IE &= tmp;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PB->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PB->IE &= tmp;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PC->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PC->IE &= tmp;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PD->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PD->IE &= tmp;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PE->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PE->IE &= tmp;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PF->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PF->IE &= tmp;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PG->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PG->IE &= tmp;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PH->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PH->IE &= tmp;
        }
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PI->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PI->IE &= tmp;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PJ->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PJ->IE &= tmp;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PK->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PK->IE &= tmp;
        }
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PL->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PL->IE &= tmp;
        }
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PM->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PM->IE &= tmp;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_INPUT_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PN->IE |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PN->IE &= tmp;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable or Disable pull-up function of specified GPIO Pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PM,
  *   GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param  NewState: New state of the Pull-Up function.
  *   This parameter can be one of the following values:
  *   ENABLE , DISABLE.
  * @retval None
  */
void GPIO_SetPullUp(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PULLUP(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_PULLUP_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_PULLUP_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_PULLUP_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_PULLUP_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_PULLUP_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_PULLUP_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_PULLUP_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_PULLUP_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_PULLUP_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_PULLUP_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_PULLUP_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_PULLUP_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_PULLUP_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PA->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PA->PUP &= tmp;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PB->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PB->PUP &= tmp;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PC->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PC->PUP &= tmp;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PD->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PD->PUP &= tmp;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PE->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PE->PUP &= tmp;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PF->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PF->PUP &= tmp;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PG->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PG->PUP &= tmp;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PH->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PH->PUP &= tmp;
        }
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PI->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PI->PUP &= tmp;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PJ->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PJ->PUP &= tmp;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PK->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PK->PUP &= tmp;
        }
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PM->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PM->PUP &= tmp;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_PULLUP_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PN->PUP |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PN->PUP &= tmp;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable or Disable pull-down function of specified GPIO Pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PM,
  *   GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param  NewState: New state of the Pull-Down function.
  *   This parameter can be one of the following values:
  *   ENABLE , DISABLE.
  * @retval None
  */
void GPIO_SetPullDown(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PULLDOWN(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_PULLDOWN_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_PULLDOWN_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PA->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PA->PDN &= tmp;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PB->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PB->PDN &= tmp;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PC->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PC->PDN &= tmp;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PD->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PD->PDN &= tmp;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PE->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PE->PDN &= tmp;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PF->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PF->PDN &= tmp;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PG->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PG->PDN &= tmp;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PH->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PH->PDN &= tmp;
        }
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PI->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PI->PDN &= tmp;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PJ->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PJ->PDN &= tmp;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PK->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PK->PDN &= tmp;
        }
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PM->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PM->PDN &= tmp;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_PULLDOWN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PN->PDN |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PN->PDN &= tmp;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set specified GPIO Pin as open drain port or CMOS port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PI, GPIO_PJ, GPIO_PK, GPIO_PM,
  *   GPIO_PN.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7, GPIO_BIT_ALL,
  *   or combination of the effective bits.
  * @param  NewState: New state of the Open Drian function.
  *   This parameter can be one of the following values:
  *   ENABLE , DISABLE.
  * @retval None
  */
void GPIO_SetOpenDrain(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_OPEN_DRAIN(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        switch (GPIO_x) {
        case GPIO_PA:
            Bit_x = GPIO_PA_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PB:
            Bit_x = GPIO_PB_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PC:
            Bit_x = GPIO_PC_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PD:
            Bit_x = GPIO_PD_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PE:
            Bit_x = GPIO_PE_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PF:
            Bit_x = GPIO_PF_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PG:
            Bit_x = GPIO_PG_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PH:
            Bit_x = GPIO_PH_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PI:
            Bit_x = GPIO_PI_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PJ:
            Bit_x = GPIO_PJ_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PK:
            Bit_x = GPIO_PK_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PM:
            Bit_x = GPIO_PM_OPEN_DRAIN_BIT_ALL;
            break;
        case GPIO_PN:
            Bit_x = GPIO_PN_OPEN_DRAIN_BIT_ALL;
            break;
        default:
            /* Do nothing */
            break;
        }
    } else {
        /* Do nothing */
    }
    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PA->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PA->OD &= tmp;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PB->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PB->OD &= tmp;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PC->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PC->OD &= tmp;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PD->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PD->OD &= tmp;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PE->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PE->OD &= tmp;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PF->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PF->OD &= tmp;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PG->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PG->OD &= tmp;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PH->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PH->OD &= tmp;
        }
        break;
    case GPIO_PI:
        /* Check the parameters */
        assert_param(IS_GPIO_PI_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PI->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PI->OD &= tmp;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PJ->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PJ->OD &= tmp;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PK->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PK->OD &= tmp;
        }
        break;
    case GPIO_PM:
        /* Check the parameters */
        assert_param(IS_GPIO_PM_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PM->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PM->OD &= tmp;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_OPEN_DRAIN_BIT(Bit_x));
        if (NewState == ENABLE) {
            TSB_PN->OD |= Bit_x;
        } else {
            tmp = (~Bit_x);
            TSB_PN->OD &= tmp;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Enable specified GPIO Function register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN.
  * @param  FuncReg_x: Select Function register of GPIO.
  *   This parameter can be one of the following values:
  *   GPIO_FUNC_REG_1, GPIO_FUNC_REG_2, GPIO_FUNC_REG_3.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   or combination of the effective bits.
  * @retval None
  */
void GPIO_EnableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x)
{
    /* Check the parameters */
    assert_param(IS_GPIO_FUNCTION(GPIO_x));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PA_FR1_BIT(Bit_x));
            TSB_PA->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PA_FR2_BIT(Bit_x));
            TSB_PA->FR2 |= Bit_x;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PB_FR1_BIT(Bit_x));
            TSB_PB->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PC_FR1_BIT(Bit_x));
            TSB_PC->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PD_FR1_BIT(Bit_x));
            TSB_PD->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PD_FR2_BIT(Bit_x));
            TSB_PD->FR2 |= Bit_x;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PE_FR1_BIT(Bit_x));
            TSB_PE->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PE_FR2_BIT(Bit_x));
            TSB_PE->FR2 |= Bit_x;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR1_BIT(Bit_x));
            TSB_PF->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR2_BIT(Bit_x));
            TSB_PF->FR2 |= Bit_x;
            break;
        case GPIO_FUNC_REG_3:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR3_BIT(Bit_x));
            TSB_PF->FR3 |= Bit_x;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PG_FR1_BIT(Bit_x));
            TSB_PG->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PH_FR1_BIT(Bit_x));
            TSB_PH->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PJ_FR1_BIT(Bit_x));
            TSB_PJ->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PK_FR1_BIT(Bit_x));
            TSB_PK->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PL_FR1_BIT(Bit_x));
            TSB_PL->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PN_FR1_BIT(Bit_x));
            TSB_PN->FR1 |= Bit_x;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Disable specified GPIO Function register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN.
  * @param  FuncReg_x: Select Function register of GPIO.
  *   This parameter can be one of the following values:
  *   GPIO_FUNC_REG_1, GPIO_FUNC_REG_2, GPIO_FUNC_REG_3.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   or combination of the effective bits.
  * @retval None
  */
void GPIO_DisableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_FUNCTION(GPIO_x));

    /* Selects GPIO */
    switch (GPIO_x) {
    case GPIO_PA:
        /* Check the parameters */
        assert_param(IS_GPIO_PA_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PA_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PA->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PA_FR2_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PA->FR2 &= tmp;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PB:
        /* Check the parameters */
        assert_param(IS_GPIO_PB_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PB_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PB->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PC:
        /* Check the parameters */
        assert_param(IS_GPIO_PC_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PC_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PC->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PD:
        /* Check the parameters */
        assert_param(IS_GPIO_PD_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PD_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PD->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PD_FR2_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PD->FR2 &= tmp;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PE:
        /* Check the parameters */
        assert_param(IS_GPIO_PE_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PE_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PE->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PE_FR2_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PE->FR2 &= tmp;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PF:
        /* Check the parameters */
        assert_param(IS_GPIO_PF_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PF->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR2_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PF->FR2 &= tmp;
            break;
        case GPIO_FUNC_REG_3:
            /* Check the parameters */
            assert_param(IS_GPIO_PF_FR3_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PF->FR3 &= tmp;
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PG:
        /* Check the parameters */
        assert_param(IS_GPIO_PG_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PG_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PG->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PH:
        /* Check the parameters */
        assert_param(IS_GPIO_PH_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PH_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PH->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PJ:
        /* Check the parameters */
        assert_param(IS_GPIO_PJ_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PJ_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PJ->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PK:
        /* Check the parameters */
        assert_param(IS_GPIO_PK_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PK_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PK->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PL:
        /* Check the parameters */
        assert_param(IS_GPIO_PL_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PL_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PL->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    case GPIO_PN:
        /* Check the parameters */
        assert_param(IS_GPIO_PN_FUNCTION_REG(FuncReg_x));
        switch (FuncReg_x) {
        case GPIO_FUNC_REG_1:
            /* Check the parameters */
            assert_param(IS_GPIO_PN_FR1_BIT(Bit_x));
            tmp = (~Bit_x);
            TSB_PN->FR1 &= tmp;
            break;
        case GPIO_FUNC_REG_2:
            /* Do nothing */
            break;
        default:
            /* Do nothing */
            break;
        }
        break;
    default:
        /* Do nothing */
        break;
    }
}

/** @} */
/* End of group GPIO_Exported_Functions */
/** @} */
/* End of group GPIO */
/** @} */
/* End of group TX03_Periph_Driver */
#endif                          /*(__TMPM376_GPIO_H) */
