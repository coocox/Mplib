/**
 *******************************************************************************
 * @file    CAN_TsetLoopBack.c
 * @brief   The application functions of CAN demo for the TOSHIBA
 *          'TMPM369' Device Series
 * @version V0.100
 * @date    2011/09/21
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
#include "tmpm369_can.h"
#include "tmpm369_adc.h"
#include "tmpm369_gpio.h"

/* Const define --------------------------------------------------------------------*/
#define MSG_ID                      (0x00000001U)
#define BAUDRATE_PRESCALER          (0x000003FFU)

/* Declaration ---------------------------------------------------------------*/
void CAN_PortInit(void);
void ADC_Init(void);
void delay(uint32_t time);


uint8_t fIntADC = 0U;
uint8_t fRcvCAN = 0U;

/**
  * @brief  main function to run CAN demo
  * @param  None.
  * @retval result to retun to system.
  */
void CAN_TsetLoopBack(void)
{
    CAN_GlobalState globalstate;
    CAN_INTFactor intmask;
    ADC_Result adc_value;
    CAN_BitTimingTypeDef bittiming =
        { BAUDRATE_PRESCALER, CAN_TIMING_TSEG1_4TQ, CAN_TIMING_TSEG2_4TQ, CAN_SINGLE_SAMPLING,
        CAN_TIMING_SJW_1TQ
    };
    CAN_MsgTypeDef msgtx = { 0U };
    CAN_MsgTypeDef msgrx = { 0U };
    
    CAN_PortInit();
    ADC_Init();

    /* CAN bit timing setting */
    CAN_ConfigBitTiming(&bittiming);

    /* CAN Tx mailbox0 setting */
    msgtx.MsgID = MSG_ID;
    msgtx.MsgDataLen = 2U;      /* data length: 2 byte */
    CAN_SetMbxMsg(CAN_MBX_0, &msgtx);
    CAN_SetMbxDirection(CAN_MBX_0, CAN_MBX_TX); /* mailbox0: Tx */

    /* CAN Rx mailbox10 setting */
    msgrx.MsgID = msgtx.MsgID;  /* ID of mailbox10 = ID of mailbox0 */
    CAN_SetMbxMsg(CAN_MBX_10, &msgrx);
    CAN_SetMbxDirection(CAN_MBX_10, CAN_MBX_RX);        /* mailbox10: Rx */

    CAN_SetTxOrder(CAN_TX_ORDER_MBX_NUM);       /* Tx order: by mailbox number */    

    globalstate.All = 0U;

    /* Enter suspend mode */
    CAN_SetMode(CAN_SUSPEND_MODE);
    while (globalstate.Bit.SuspendModeAck == 0U) {
        globalstate = CAN_GetGlobalState();
    }

    /* Set test loop back mode */
    CAN_SetTestMode(CAN_TEST_LOOP_BACK_MODE, ENABLE);

    /* Return normal mode */
    CAN_SetMode(CAN_NORMAL_MODE);
    while (globalstate.Bit.SuspendModeAck == 1U) {
        globalstate = CAN_GetGlobalState();
    }

    /* Enable mailbox10 Rx interrupt */
    intmask.MbxBit.Mbx10 = 1U;
    CAN_SetINTMask(CAN_INT_MBX_MASK, &intmask);
    NVIC_EnableIRQ(INTCANRX_IRQn);     
    
    /* Enable mailbox0 and 10 */
    CAN_EnableMbx(CAN_MBX_0 | CAN_MBX_10);     
    
    /* enable AD interrupt */
    NVIC_EnableIRQ(INTADB_IRQn);
    
    /* ADC start to run */
    ADC_Start(TSB_ADB);

    while (1) {

        if (fIntADC == 1U) {
             fIntADC = 0U;
            
            adc_value = ADC_GetConvertResult(TSB_ADB,ADC_REG00);
            msgtx.MsgData[0] = (uint8_t) adc_value.Bit.ADResult;
            msgtx.MsgData[1] = (uint8_t) (adc_value.Bit.ADResult >> 8U);
            
            
            CAN_SetMbxMsg(CAN_MBX_0, &msgtx);   /* Put the ADC result into mailbox0 */
            CAN_SetTxReq(CAN_MBX_0, ENABLE);    /* Start to send */
        } else {
            /* Do nothing */
        }

        if (fRcvCAN == 1U) {
             fRcvCAN = 0U;
             CAN_GetMbxMsg(CAN_MBX_10, &msgrx);     /* Read mailbox10 */                    
        }
        delay(0xFFFFFU);
    }
}


/**
  * @brief  delay
  * @param  delay time
  * @retval None.
  */
void delay(uint32_t time)
{
    volatile uint32_t i;
    for (i = 0U; i < time; i++) {
        /* Do nothing */
    }
}

/**
  * @brief  CAN port initialization
  * @param  None.
  * @retval None.
  */
void CAN_PortInit(void)
{

    GPIO_SetOutput(GPIO_PH, GPIO_BIT_2);        /* Set TX pin as output */
    GPIO_SetInput(GPIO_PH, GPIO_BIT_3); /* Set RX pin as input */
    GPIO_EnableFuncReg(GPIO_PH, GPIO_FUNC_REG_2, (uint8_t) (GPIO_BIT_2| GPIO_BIT_3));  /* Enable TX and RX pin functions */
    GPIO_SetOpenDrain(GPIO_PH, GPIO_BIT_2, DISABLE);    /* Set TX pin as CMOS output */
    GPIO_SetPullUp(GPIO_PH, (uint8_t) (GPIO_BIT_2 | GPIO_BIT_3), DISABLE);      /* Disable pull-ups for CAN pins */
}

/**
  * @brief  ADC module initialization
  * @param  None.
  * @retval None.
  */
void ADC_Init(void)
{
   uint32_t cnt = 0U;
  
    /* software reset ADC unit B */
    ADC_SWReset(TSB_ADB);
    
    /* Enable ADC clock supply */
    ADC_SetClkSupply(ENABLE);
    
    /* set ADC clock */            
    ADC_SetClk(TSB_ADB, ADC_CONVERSION_CLK_80, ADC_FC_DIVIDE_LEVEL_8);

    /* select ADC input channel : ADB00, pin11*/
    ADC_SetInputChannel(TSB_ADB, ADC_AN_00);
    
    /* Enable ADC repeat mode */
    ADC_SetRepeatMode(TSB_ADB, ENABLE);

    /* Set interrupt mode */
    ADC_SetINTMode(TSB_ADB, ADC_INT_CONVERSION_8);

    /* Turn VREF on */
    ADC_SetVref(TSB_ADB, ENABLE); 
    
    /* Wait at least 3us to ensure the voltage is stable */
    cnt = 100U;
    while(cnt){
        cnt--;
    }
}

/**
  * @brief  CAN mailbox Rx interrupt.
  * @param  None
  * @retval None
  */
void INTCANRX_IRQHandler(void)
{
    CAN_MbxState mbxstate = { 0U };

    mbxstate = CAN_GetMbxTRxState(CAN_STATE_ID_RX_ACK); /* Read Rx state */
    if (mbxstate.Bit.Mbx10 == 1U) {     /* If mailbox10 has received a message */
          fRcvCAN=1U;        
    } else {
        /* Do nothing */
    }
    CAN_ClearMbxTRxState(CAN_STATE_ID_RX_ACK);  /* Clear the Rx state */
    CAN_ClearINTFlag(CAN_INT_TYPE_RX);  /* Clear the Rx interrupt flag */
}

/**
  * @brief  ADC interrupt.
  * @param  None
  * @retval None
  */
void INTADC_IRQHandler(void)
{
    fIntADC = 1U;
}
