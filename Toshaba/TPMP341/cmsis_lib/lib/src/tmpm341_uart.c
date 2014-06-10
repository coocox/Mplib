/**
 *******************************************************************************
 * @file    tmpm341_uart.c
 * @brief   This file provides API functions for UART driver.
 * @version V2.0.2.2
 * @date    2011/1/17
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
#include "tmpm341_uart.h"

#if defined(__TMPM341_UART_H)
/** @addtogroup TX03_Periph_Driver
  * @{
  */

/** @defgroup UART
  * @brief UART driver modules
  * @{
  */

/** @defgroup UART_Private_Defines
  * @{
  */
#define EN_SIOE_SET            ((uint32_t)0x00000001)
#define EN_SIOE_CLEAR          ((uint32_t)0x00000000)

#define CR_PARITY_MASK         ((uint32_t)0x0000009F)
#define CR_ERROR_MASK          ((uint32_t)0x0000001C)
#define CR_OERR_FLAG           ((uint8_t)0x10)
#define CR_PERR_FLAG           ((uint8_t)0x08)
#define CR_FERR_FLAG           ((uint8_t)0x04)

#define MOD0_CTSE_MASK         ((uint32_t)0x000000BF)
#define MOD0_RXE_CLEAR         ((uint32_t)0x000000DF)
#define MOD0_WU_SET            ((uint32_t)0x00000010)
#define MOD0_WU_CLEAR          ((uint32_t)0x000000EF)
#define MOD0_SM_MASK           ((uint32_t)0x000000F3)
#define MOD0_SC_MASK           ((uint32_t)0x000000FC)
#define MOD0_SC_BRG            ((uint32_t)0x00000001)

#define MOD1_I2SC_SET           ((uint32_t)0x00000080)
#define MOD1_I2SC_CLEAR         ((uint32_t)0x0000007F)
#define MOD1_TXE_CLEAR         ((uint32_t)0x000000EF)

#define MOD2_BUF_MASK          ((uint32_t)0x000000C0)
#define MOD2_TBEMP_FLAG        ((uint8_t)0x80)
#define MOD2_RBFLL_FLAG        ((uint8_t)0x40)
#define MOD2_SBLEN_MASK        ((uint32_t)0x000000EF)
#define MOD2_DRCHG_MASK        ((uint32_t)0x000000F7)
#define MOD2_WBUF_SET          ((uint32_t)0x00000004)
#define MOD2_SWRST_MASK        ((uint32_t)0x000000FC)
#define MOD2_SWRST_CMD1        ((uint32_t)0x00000002)
#define MOD2_SWRST_CMD2        ((uint32_t)0x00000001)

#define BRCR_BRADDE_SET        ((uint32_t)0x00000040)
#define BRCR_BRCK_MASK         ((uint32_t)0x000000CF)
#define BRCR_BRS_MASK          ((uint32_t)0x000000F0)

#define BRADD_BRK_MASK         ((uint32_t)0x00000000)

#define FCNF_TFIE_SET          ((uint32_t)0x00000008)
#define FCNF_TFIE_CLEAR        ((uint32_t)0x00000017)
#define FCNF_RFIE_SET          ((uint32_t)0x00000004)
#define FCNF_RFIE_CLEAR        ((uint32_t)0x0000001B)
#define FCNF_RXTXCNT_SET       ((uint32_t)0x00000002)
#define FCNF_RXTXCNT_CLEAR     ((uint32_t)0x0000001D)
#define FCNF_CNFG_SET          ((uint32_t)0x00000001)
#define FCNF_CNFG_CLEAR        ((uint32_t)0x0000001E)

#define TRXFC_TRXFCS_SET       ((uint32_t)0x00000080)

#define TRXT_TU_ROR_MASK       ((uint32_t)0x00000080)
#define TRXT_TRLV_MASK         ((uint32_t)0x00000007)

#define TRXST_FIFO_EMPTY       ((uint32_t)0x00000000)
#define TRXST_FIFO_1B          ((uint32_t)0x00000001)
#define TRXST_FIFO_2B          ((uint32_t)0x00000002)
#define TRXST_FIFO_3B          ((uint32_t)0x00000003)
#define TRXST_FIFO_4B          ((uint32_t)0x00000004)

#define DMA_EN0_SET              ((uint32_t)0x00000001)
#define DMA_EN0_CLEAR            ((uint32_t)0x00000002)

#define DMA_EN1_SET              ((uint32_t)0x00000002)
#define DMA_EN1_CLEAR            ((uint32_t)0x00000001)
/** @} */
/* End of group UART_Private_Defines */

/** @defgroup UART_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group UART_Private_FunctionPrototypes */

/** @defgroup UART_Private_Functions
  * @{
  */

/** @} */
/* End of group UART_Private_Functions */

/** @defgroup UART_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the specified UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval None
  */
void UART_Enable(TSB_SC_TypeDef * UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    /* Set SCxEN<SIOE> to enable UARTx */
    UARTx->EN |= EN_SIOE_SET;
}

/**
  * @brief  Disable the specified UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval None
  */
void UART_Disable(TSB_SC_TypeDef * UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    /* Clear SCxEN<SIOE> to disable UARTx */
    UARTx->EN &= EN_SIOE_CLEAR;
}

/**
  * @brief  Indicate whether the transfer buffer is full or not.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @param  Direction: Select the direction of transfer.
  *   This parameter can be UART_RX or UART_TX.
  * @retval The transfer buffer status.
  *   The value returned can be one of the followings:
  *   BUSY or DONE.
  */
WorkState UART_GetBufState(TSB_SC_TypeDef * UARTx, uint8_t Direction)
{
    uint8_t tmp = 0U;
    WorkState retval = BUSY;

    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_TRX(Direction));

    tmp = ((uint8_t) (UARTx->MOD2 & MOD2_BUF_MASK));
    switch (Direction) {
    case UART_TX:
        if ((tmp & MOD2_TBEMP_FLAG) == MOD2_TBEMP_FLAG) {
            /* Return Tx buffer empty if the flag is set */
            retval = DONE;
        } else {
            /* Do nothing */
        }
        break;
    case UART_RX:
        if ((tmp & MOD2_RBFLL_FLAG) == MOD2_RBFLL_FLAG) {
            /* Return Rx buffer full if the flag is set */
            retval = DONE;
        } else {
            /* Do nothing */
        }
        break;
    default:                   /* Do nothing */
        break;
    }

    return retval;
}

/**
  * @brief  Reset the specified UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval None
  */
void UART_SWReset(TSB_SC_TypeDef * UARTx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* Write software-reset command */
    tmp = UARTx->MOD2;
    tmp &= MOD2_SWRST_MASK;
    UARTx->MOD2 = tmp | MOD2_SWRST_CMD1;
    tmp &= MOD2_SWRST_MASK;
    UARTx->MOD2 = tmp | MOD2_SWRST_CMD2;
}

/**
  * @brief  Initialize the specified UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @param  InitStruct: The structure containing basic UART configuration.
  * @retval None
  */
void UART_Init(TSB_SC_TypeDef * UARTx, UART_InitTypeDef * InitStruct)
{
    uint32_t T0 = 0U;
    uint32_t T = 0U;
    uint32_t t = 0U;
    uint32_t N = 0U;
    uint32_t K = 0U;
    uint32_t tmp = 0U;
    uint32_t divider = 0U;
    const uint32_t a = 2U;
    const uint32_t b = 4U;
    /* Check the parameters */
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_BAUDRATE(InitStruct->BaudRate));
    assert_param(IS_UART_DATA_BITS(InitStruct->DataBits));
    assert_param(IS_UART_STOPBITS(InitStruct->StopBits));
    assert_param(IS_UART_PARITY(InitStruct->Parity));
    assert_param(IS_UART_MODE(InitStruct->Mode));
    assert_param(IS_UART_FLOW_CONTROL(InitStruct->FlowCtrl));

    /* Configure the flow control */
    tmp = UARTx->MOD0;
    tmp &= MOD0_SM_MASK;
    tmp &= MOD0_CTSE_MASK;
    tmp |= (InitStruct->DataBits | InitStruct->FlowCtrl);
    /* Use baud rate generator */
    tmp |= MOD0_SC_BRG;
    UARTx->MOD0 = tmp;

    /* Set the stop bit */
    tmp = UARTx->MOD2;
    tmp &= MOD2_SBLEN_MASK;
    tmp |= InitStruct->StopBits;
    tmp |= MOD2_WBUF_SET;
    UARTx->MOD2 = tmp;

    /* Enable or disable parity check */
    tmp = UARTx->CR;
    tmp &= CR_PARITY_MASK;
    tmp |= InitStruct->Parity;
    UARTx->CR = tmp;

    /* Get the peripheral I/O clock frequency */
    SystemCoreClockUpdate();
    T0 = SystemCoreClock / (a << ((TSB_CG->SYSCR >> 8) & 7U));

    /* Baud rate setting */
    tmp = UARTx->BRCR;
    tmp |= BRCR_BRADDE_SET;
    while ((divider <= 200U) || (divider >= 1600U)) {
        if (t == 0U) {
            T = 1U;
        } else {
            T = b << ((t - 1U) * 2U);
        }
        divider = (100U * T0) / (16U * InitStruct->BaudRate * T);
        t++;
    }
    tmp &= BRCR_BRCK_MASK;
    tmp &= BRCR_BRS_MASK;
    tmp |= (((t - 1U) & 3U) << 4U);
    N = divider / 100U;
    tmp |= (N & 0x0FU);
    UARTx->BRCR = tmp;
    K = (16U * (100U - (divider - (N * 100U)))) / 100U;
    tmp = UARTx->BRADD;
    tmp &= BRADD_BRK_MASK;
    tmp |= (K & 0x0FU);
    UARTx->BRADD = tmp;

    /* Enable or disable transmission or reception */
    switch (InitStruct->Mode) {
    case UART_ENABLE_RX:
        UARTx->MOD0 |= InitStruct->Mode;
        UARTx->MOD1 &= MOD1_TXE_CLEAR;
        break;
    case UART_ENABLE_TX:
        UARTx->MOD1 |= InitStruct->Mode;
        UARTx->MOD0 &= MOD0_RXE_CLEAR;
        break;
    default:
        UARTx->MOD0 |= UART_ENABLE_RX;
        UARTx->MOD1 |= UART_ENABLE_TX;
        break;
    }
}

/**
  * @brief  Get received data of the specified UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval The received data
  */
uint32_t UART_GetRxData(TSB_SC_TypeDef * UARTx)
{
    uint32_t retval = 0U;
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* Return received data */
    retval = (UARTx->CR & 0x80U) << 1;
    retval = retval | (UARTx->BUF & 0xFFU);

    return retval;
}

/**
  * @brief  Set data to be sent and start transmitting via the specified
      UART channel.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @param  Data: the data to be sent.
  * @retval None
  */
void UART_SetTxData(TSB_SC_TypeDef * UARTx, uint32_t Data)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_DATA(Data));

    UARTx->BUF = Data & 0xFFU;
    /* Write MSB to SCxMOD0<TB8> if in 9-bit mode */
    UARTx->MOD0 |= (Data & 0x100U) >> 1;
}

/**
  * @brief  Initialize the specified UART channel in default configuration.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval None
  */
void UART_DefaultConfig(TSB_SC_TypeDef * UARTx)
{
    UART_InitTypeDef uartdefault;
    uartdefault.BaudRate = 115200U;
    uartdefault.DataBits = UART_DATA_BITS_8;
    uartdefault.StopBits = UART_STOP_BITS_1;
    uartdefault.Parity = UART_NO_PARITY;
    uartdefault.Mode = UART_ENABLE_RX | UART_ENABLE_TX;
    uartdefault.FlowCtrl = UART_NONE_FLOW_CTRL;

    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* Enable the selected UART channel */
    UART_Enable(UARTx);
    /* Select baud rate generator as UART source clcok */
    /* Set baud rate as 115200bps */
    /* Select 8-bit UART mode */
    /* Select 1-bit stop */
    /* No parity check */
    /* No flow control */
    /* Enable both transmission and reception */
    UART_Init(UARTx, &uartdefault);
}

/**
  * @brief  Indicate UART transfer error.
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @retval The error flag.
  *   The value returned can be one of the followings:
  *   UART_NO_ERR, UART_OVERRUN, UART_PARITY_ERR, UART_FRAMING_ERR or UART_ERRS.
  */
UART_Err UART_GetErrState(TSB_SC_TypeDef * UARTx)
{
    uint8_t tmp = 0U;
    UART_Err retval = UART_NO_ERR;
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    tmp = ((uint8_t) (UARTx->CR & CR_ERROR_MASK));
    switch (tmp) {
    case CR_OERR_FLAG:         /* Check overrun flag */
        retval = UART_OVERRUN;
        break;
    case CR_PERR_FLAG:         /* Check parity flag */
        retval = UART_PARITY_ERR;
        break;
    case CR_FERR_FLAG:         /* Check framing flag */
        retval = UART_FRAMING_ERR;
        break;
    default:
        if (tmp != 0U) {
            /* more than one error */
            retval = UART_ERRS;
        } else {
            /* Do nothing */
        }
        break;
    }
    return retval;
}

/**
  * @brief  Enable or disable the wake-up function in 9-bit UART mode
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @param  NewState: New state of this function.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_SetWakeUpFunc(TSB_SC_TypeDef * UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set SCxMOD0<WU> to enable wake-up function */
        UARTx->MOD0 |= MOD0_WU_SET;
    } else {
        /* Clear SCxMOD0<WU> to disable wake-up function */
        UARTx->MOD0 &= MOD0_WU_CLEAR;
    }
}

/**
  * @brief  Enable or disable the specified UART channel when system is in IDLE
      mode. 
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART1,UART2,UART3,UART4
  * @param  NewState: New state of the UART channel in IDLE.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_SetIdleMode(TSB_SC_TypeDef * UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set SCxMOD1<I2SC> to enable UARTx running in IDLE */
        UARTx->MOD1 |= MOD1_I2SC_SET;
    } else {
        /* Clear SCxMOD1<I2SC> to disable UARTx running in IDLE */
        UARTx->MOD1 &= MOD1_I2SC_CLEAR;
    }
}

/**
  * @brief  Enable or disable the specified UART channel DMA Request By 
      receive interrupt INTRX
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART2,UART4.
  * @param  NewState: New state of the UART channel in IDLE.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_SetRxDMAReq(TSB_SC_TypeDef * UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_DMA_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set SCxDMA<DMAEN1> to enable UARTx DMA Request */
        UARTx->DMA |= DMA_EN1_SET;
    } else {
        /* Clear SCxDMA<DMAEN1> to disable UUARTx DMA Request */
        UARTx->DMA &= DMA_EN1_CLEAR;
    }
}

/**
  * @brief  Enable or disable the specified UART channel DMA Request By 
      receive interrupt INTTX
  * @param  UARTx: Select the UART channel.
  *   This parameter can be one of the following values:
  *   UART0,UART2,UART4.
  * @param  NewState: New state of the UART channel in IDLE.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_SetTxDMAReq(TSB_SC_TypeDef * UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_DMA_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE) {
        /* Set SCxDMA<DMAEN0> to enable UARTx DMA Request */
        UARTx->DMA |= DMA_EN0_SET;
    } else {
        /* Clear SCxDMA<DMAEN0> to disable UARTx DMA Request */
        UARTx->DMA &= DMA_EN0_CLEAR;
    }
}

/** @} */
/* End of group UART_Exported_Functions */

/** @} */
/* End of group UART */

/** @} */
/* End of group TX03_Periph_Driver */

#endif                          /* defined(__TMPM341_UART_H) */
