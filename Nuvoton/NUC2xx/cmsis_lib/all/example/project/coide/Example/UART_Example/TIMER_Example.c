/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    NUC123 Series Sample of Timer.
 *
 *  Timer0 toggles PIN64:PB8_TM0 every 10ms and PIN10:PB4_LED blinks every 1s at Duty=10%
 *  Timer1, count pulse from PIN32:PB9_TM1.Connect this PIN to PIN10,you can watch TDR1 increasing
 *  Timer2 capture pulse from PIN23:PB2_T2EX, Please connect this PIN to PIN10
 *  PIN64 will output 1KHz wave.
 *
 *  Please watch DEBUG UART1 window while debug routines. And watch the value of TDR1
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/

#include <stdio.h>
#include "NUC123Series.h"
#include "CLOCK.h"
#include "SYS.h"
#include "GPIO.h"
#include "TIMER.h"




#define  PERIOD_LIGHT              100      //Period of LED flashing
uint16_t Light = 10 ;                       //Time lengh of LED lighting. MAX value = PERIOD_LIGHT

void SYS_Init(void);
void GPIO_Init(void);
void Timer0_Timer1_Timer2_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int TIMER_Example(void)
{
  SYS_Init() ;
  GPIO_Init() ;
  Timer0_Timer1_Timer2_Init() ;

  while(1){

  }
}


/**
 * @brief       CLK init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init HCLK and Timer0&Timer1 clock
 */
void SYS_Init(void)
{
    SYS_UnlockReg();
    SET_HCLK_CLKSRC(CLK_HCLK_HIRC) ;                    //HCLK  = 22MHz
    SYS_LockReg() ;
}

/**
 * @brief       GPIO init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init GPIO
 */
void GPIO_Init(void)
{
    GPIO_SET_MODE(PB,4,GPIO_OUTPUT) ;                         //PB4 = output, LED
}

/**
 * @brief       Time init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init Timer IP
 */
void Timer0_Timer1_Timer2_Init(void)
{
    SET_TMR0_CLKSRC(CLK_TMR0_HCLK);                       //Timer0 CLK = 22MHz
    SET_TMR2_CLKSRC(CLK_TMR2_HCLK);                       //Timer1 CLK = 22MHz
    APBCLK_ENABLE(CLK_TMR0 | CLK_TMR1 | CLK_TMR2)  ;      //Enable T0&T1 CLK

    /* Set MFP pin */
    GPIO_TMR0();										   //PB8 = T0 toggle output
    GPIO_T2EX();										   //PB2 = T2EX capture input
    GPIO_TMR1();										   //PB9 = TM1 counter input

    ////Timer0 configure. Toggle PIN64:PB8_TM0 every 10ms ///////////////////////////////////////////
    DrvTIMER_Init(TIMER0, 21/*prescale*/, 10000/*TCMPR*/, TIM_MODE_TOGGLE);
    DrvTIMER_EnableInt(TIMER0, TIM_INT_EN);
    TIM_ENABLE(TIMER0);

    //Timer1 configure. Count pulse from PIN32:PB9_TM1.//////////////////////////////////
    DrvTIMER_Init(TIMER1, 0/*prescale*/, 10/*TCMPR*/, TIM_MODE_PERIODIC);
    TIM_COUNT_MODE_ENABLE(TIMER1) ;                          //count mode
    TIM_COUNT_DEBOUNCE_ENABLE(TIMER1) ;                      //Enable count de-bounce
    TIM_UPDATA_TDR_ENABLE(TIMER1) ;
    DrvTIMER_EnableInt(TIMER1, TIM_INT_EN);
    TIM_ENABLE(TIMER1) ;

    ////Timer2 configure. Capture edge from PIN23:PB2_T2EX ////////////////////////////////
    DrvTIMER_Init(TIMER2, 22/*prescale*/, 10000/*TCMPR*/, TIM_MODE_CONTINUOUS);
    TIM_CAPTURE_DEBOUNCE_ENABLE(TIMER2) ;
    TIM_SET_CAP_EDGE_MODE(TIMER2,TIM_CAPTURE_EDGE);          //capture rise and fall edge.
    TIM_CAPTURE_ENABLE(TIMER2) ;
    DrvTIMER_EnableInt(TIMER2, TIM_TEX_INT_EN);
    TIM_ENABLE(TIMER2);
}

/**
 * @brief       Timer0 IRQHandler
 *
 * @param       None
 *
 * @return      None
 *
 * @details    Toggles PIN64:PB8_TM0 every 10ms and PIN10:PB4_LED blinks every 1s at Duty=10%.
 */
void TMR0_IRQHandler(void)
{
  static uint16_t Relay = 0 ;                              //Every 100 times = 1s

  if(++Relay >= PERIOD_LIGHT){
    Relay = 0 ;
  }
  if(Relay < Light)  GPIO_CLR_PIN(PB4) ;
  else  GPIO_SET_PIN(PB4) ;

  TIM_CLEAR_INTERRUPT_FLAG(TIMER0)  ;                           //Clear IF flag
}

/**
 * @brief       Timer0 IRQHandler
 *
 * @param       None
 *
 * @return      None
 *
 * @details    Count pulse from PIN32:PB9_TM1.
 *             Connect to PIN10_LED, you can watch TDR1 increasing
 */
void TMR1_IRQHandler(void)
{
  printf("\nTimer1 has counted 10 pulses") ;

  TIM_CLEAR_INTERRUPT_FLAG(TIMER1)  ;                           //Clear IF flag
}

/**
 * @brief       Timer2 IRQHandler
 *
 * @param       None
 *
 * @return      None
 *
 * @details    Capture pulse from PIN23:PB2_T2EX, Please connect this PIN to PIN10
 */
void TMR2_IRQHandler(void)
{
  static uint32_t Tim ;

  if(GPIO_GET_PIN(PB2) == 0){
    printf("\nT2_falling! ") ;                   //Print "T2 has captured!"
    Tim = TIM_GET_TCAP(TIMER2) ;
  }
  else{
    printf(" T2_rise! ") ;                        //Print "T2 has captured!"
    printf("Time of Pulse = %dus", TIM_GET_TCAP(TIMER2)-Tim);
  }
  TIM_CLEAR_TEX_INTERRUPT_FLAG(TIMER2);          //Clear interrupt flag
}
