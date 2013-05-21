/** 
 *******************************************************************************
 * @file    Example_TMRB_PPG.c
 * @brief   the application functions of TMRB_PPG demo for the TOSHIBA
 *          'TMPM375' Device Series 
 * @version V0.100
 * @date    2013/03/26
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* declaration ---------------------------------------------------------------*/
void delay(uint32_t DelayTime);
void duty_display(void);
uint16_t Tmrb_Calculator(uint16_t Tmrb_Require_us, uint32_t ClkDiv);
uint8_t Rate = 0U;

/**
  * @brief  delay some time
  * @param  delay time
  * @retval None
  */
void delay(uint32_t DelayTime)
{
    uint32_t time = 0U;
    for (time = 0U; time < DelayTime; time++) {
        /* Do nothing */
    }
}

/**
  * @brief  The main function of TMRB_PPG demo
  * @param  None
  * @retval None
  */
void Example_TMRB_PPG(void)
{
    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;
    uint8_t keyvalue;
    uint32_t i = 0U;
    uint32_t tgtDuty[5U] = { 10U, 25U, 50U, 75U, 90U }; /* duty: 10%, 25%, 50%, 75%, 90% */ 
    uint32_t Dutyus[5U] = {0U};
    uint32_t Duty[5U] = {0U}; 
    
    /* Dutyus: 50, 125, 250, 375, 450 */
    for (i=0U;i<=4U;i++) {
        Dutyus[i] = tgtDuty[i] * 5U;
    }

    /* UART & switch initialization */
    hardware_init(UART_RETARGET);   
    SW_Init();

    /* Set PB6 as TB7OUT for PPG output */
    GPIO_SetOutput(GPIO_PB, GPIO_BIT_6);
    GPIO_EnableFuncReg(GPIO_PB, GPIO_FUNC_REG_3, GPIO_BIT_6);

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;     /* internal timer */
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;        /* 1/8PhiT0 */
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;    /* up-counter auto clear */
    for(i=0U;i<=4U;i++) { 
        Duty[i] = Tmrb_Calculator(Dutyus[i], m_tmrb.ClkDiv);
    } 
    m_tmrb.Cycle = Tmrb_Calculator(500U, m_tmrb.ClkDiv);  /* T = 500us */ 
    m_tmrb.Duty = Duty[Rate];   /* duty, initial value 10% */
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_SET;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_CYCLE | TMRB_FLIPFLOP_MATCH_DUTY;

    TMRB_Enable(TSB_TB7);
    TMRB_Init(TSB_TB7, &m_tmrb);
    TMRB_SetFlipFlop(TSB_TB7, &PPGFFInital);
    TMRB_SetDoubleBuf(TSB_TB7, ENABLE, TMRB_WRITE_REG_SEPARATE);        /* enable double buffer */
    TMRB_SetRunState(TSB_TB7, TMRB_RUN);

    do {                        /* Handle the condition that start with the SW0 is high */
        keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_2);
        duty_display();
    } while (GPIO_BIT_VALUE_1 == keyvalue);

    delay(0xFFFFU);             /* noise cancel */

    while (1U) {
        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_2);   /* display when switch is low */
            duty_display();
        } while (GPIO_BIT_VALUE_0 == keyvalue);
        delay(0xFFFFU);         /* noise cancel */
        Rate++;
        if (Rate >= DUTYMAX) {  /* change duty rate */
            Rate = DUTYINIT;
        } else {
            /* Do nothing */
        }
        TMRB_ChangeDuty(TSB_TB7, Duty[Rate]);
        do {
            keyvalue = GPIO_ReadDataBit(KEYPORT, GPIO_BIT_2);   /* display when switch is high */
            duty_display();
        } while (GPIO_BIT_VALUE_1 == keyvalue);
        delay(0xFFFFU);         /* noise cancel */
    }
}

/**
  * @brief  Display the string of TMRB_PPG demo
  * @param  None
  * @retval None
  */
void duty_display()
{
    common_uart_disp("PPG Output");
    common_uart_disp(DutyRateToString(Rate));
}

/** 
  * @brief  Calculate timer value to set timer register. 
  * @param  Tmrb_Require_us: The require period which the uint is us. 
            ClkDiv: Select the division for TMRB source clock 
  * @retval the value set to Tmrb timer register. 
  */ 
uint16_t Tmrb_Calculator(uint16_t Tmrb_Require_us, uint32_t ClkDiv) 
{      
    uint32_t T0 = 0U; 
    const uint16_t Div[8U] = {1U, 2U, 8U, 32U, 64U, 128U, 256U, 512U}; 
    
    SystemCoreClockUpdate(); 

    T0 = SystemCoreClock / (1U << ((TSB_CG->SYSCR >> 8U) & 7U));   
    T0 = T0/((Div[ClkDiv])*1000000U); 
         
    return(Tmrb_Require_us * T0); 
} 

/**
  * @brief  Deal with the error parameter
  * @param  file: Pointer to the file where the error parameter locates
  * @param  line: Number of the line in which the error parameter locates
  * @retval None
  */
#ifdef DEBUG
void assert_failed(char *file, int32_t line)
{
    while (1) {
        __NOP();
    }
}
#endif
