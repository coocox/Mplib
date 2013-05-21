/**
 *******************************************************************************
 * @file    Example_ENC_Roller.c
 * @brief   the application functions of ENC demo for the TOSHIBA 'TMPM375'
 *          Device Series
 * @version V0.100
 * @date    2013/03/19
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
#include "main.h"
uint8_t g_flag;
uint32_t enccount = 15U;


void Delay1(void);
void Delay2(uint32_t time);

/**
  * @brief  Main function
  * @param  None
  * @retval None
  */
void Example_ENC_Roller(void)
{
    ENC_InitTypeDef m_enc;
    ENC_FlagStatus f_enc;
    
    /* LED initialization */
    LED_Init();

    /* ENC0 initialization */   
    m_enc.ModeType = ENC_ENCODER_MODE;
    m_enc.PhaseType = ENC_TWO_PHASE;
    m_enc.CompareStatus = ENC_COMPARE_DISABLE;
    m_enc.ZphaseStatus = ENC_ZPHASE_DISABLE;
    m_enc.FilterValue = ENC_FILTER_VALUE31;
    m_enc.IntEn = ENC_INTERRUPT_ENABLE;
    m_enc.PulseDivFactor = ENC_PULSE_DIV1;
    
    ENC_Init(EN0,&m_enc);
    ENC_SetCounterReload(EN0,0xFFFU);
    
    /* GPIO initialization */
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_0, ENABLE);/*Set PE0 as input */
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_3, GPIO_BIT_0);/*Set PE0 as ENCA */
    GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_1, ENABLE);/*Set PE1 as input */
    GPIO_EnableFuncReg(GPIO_PE, GPIO_FUNC_REG_3, GPIO_BIT_1);/*Set PE1 as ENCB */
    
    /* Enable ENC0*/
    ENC_Enable(EN0);
    /* Enable ENC0 interrupt*/
    NVIC_EnableIRQ(INTENC0_IRQn);   
    
    /* LED1 blink speed based on the rolling of mouse wheel */
    while(1){
        f_enc = ENC_GetENCFlag(EN0);
        g_flag = f_enc.Bit.RotationDirection;  
        LED_On(LED1);
        Delay2(enccount);
        LED_Off(LED1);
        Delay2(enccount);
    } 
}

/**
  * @brief  Delay 10ms
  * @param  None
  * @retval None
  */
void Delay1(void)
{
    uint32_t TimeCounter;
    uint32_t DelayTime = 50000U;
    for (TimeCounter = 0U; TimeCounter < DelayTime; TimeCounter++) {
        /* Do nothing */
    }
}
/**
  * @brief  Delay time
  * @param  time
  * @retval None
  */
void Delay2(uint32_t time)
{
    uint32_t count;
    for (count = 0U; count < time; count++){
        Delay1();
    }
}

#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
