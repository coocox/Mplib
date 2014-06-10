/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 12/08/20 11:27a $
 * @brief    NUC123 Series Sample of PWM.
 *
 *  PIN45: PA12_PWM0. This PIN is configured as PWM0 output
 *  PIN43: PA14_PWM2. This PIN is configured as PWM2 capture
 *  PIN10: PB4.       This PIN is configured as input. So LED connected to this PIN is not light.
 *  PIN1 : PB14.      This PIN is configured as GPIO output. And output wave in main routines
 *
 *  Connecting PIN45_PWM0 to PIN10. LED will light gradually and then dark gradually following PWM0.
 *  Connecting PIN1 to PIN43_PWM2. Captured time of pulse will display at DEBUG UART1 windows.
 *  Connecting PIN1 to PIN10.     LED will blinking base on main routines.
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
#include "PWM.h"

void SYS_Init(void);
void GPIO_Init(void);
void PWM01_Init(void);
void PWM23_Init(void);
void DelaySoft(uint32_t Cnt);


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int PWM_Example(void)
{
  uint16_t Light=450, toggle=1 ;
  uint16_t Cnt = 0 ;

  SYS_Init() ;
  PWM01_Init() ;
  PWM23_Init() ;
  GPIO_Init() ;
  while(1){

    if(++Cnt >= 10)Cnt = 0 ;                     //Output pulse over PIN1:PB14
    if(Cnt>1)  GPIO_SET_PIN(PB14);               //Changing duty used for PWM2 capture.
    else  GPIO_CLR_PIN(PB14);

    if(toggle){
      DelaySoft(200000);
      PWMA_SET_CMR0(Light<<1) ;                   //Duty range from 900/1000 to 1020/1000
      if(++Light >= 510) toggle = 0 ;
    }
    else{
      DelaySoft(200000);
      PWMA_SET_CMR0(Light<<1) ;
      if(--Light <= 450){
        toggle = 1 ;                             //Duty range from 1020/1000 to 900/1000
 //       PWMA->CMR0 = 300 ;
      }
    }

  }

}

/**
 * @brief       Sys init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init system clock
 */
void SYS_Init(void)
{
    SYS_UnlockReg();
    SET_HCLK_CLKSRC(CLK_HCLK_HIRC) ;                              //     HCLK = 22MHz
    SET_PWM01_CLKSRC(CLK_PWM01_HIRC_L, CLK_PWM01_HIRC_H);       //PWM01 CLK = 22MHz
    SET_PWM23_CLKSRC(CLK_PWM23_HIRC_L, CLK_PWM23_HIRC_H);       //PWM23 CLK = 22MHz
    APBCLK_ENABLE(CLK_PWM01 | CLK_PWM23) ;                       //Enable PWM CLK
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
  GPIO_SET_MODE(PB,4,GPIO_INPUT) ;                         //configure PB4 as input
  SYS->GPA_MFP |= SYS_MFPA12_PWM0 | SYS_MFPA14_PWM2 ;      //PA12 = PWM0
  GPIO_SET_MODE(PB,14,GPIO_OUTPUT) ;                       //PB14 is GPIO output

}

/**
 * @brief       PWM01 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init PWM01 IP
 */
void PWM01_Init(void)
{
  S_DRVPWM_TIME_DATA_T  pPWM ;

  PWMA_CH01_CENTER_ALIGN() ;

  pPWM.u16Cn       =  1000  ;
  pPWM.u16Cm       =  100  ;
  pPWM.u8PreScale  =  10  ;
  pPWM.u8Div       =  PWM_CSR_1 ;
  pPWM.u8Mode      =  PWM_CHMOD_AUTO_RELOAD ;
  pPWM.u8Inv       =  PWM_NO_INVERT ;
  DrvPWM_SetClk(0, &pPWM) ;

  DrvPWM_Init(0) ;
  PWMA_POE_ENABLE(PWM_POE0) ;
}

/**
 * @brief       PWM23 init
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Init PWM23 IP
 */
void PWM23_Init(void)
{
  S_DRVPWM_TIME_DATA_T  pPWM ;

  PWMA_CH23_EDGE_ALIGN() ;

  pPWM.u16Cn       =  0xFFFE  ;
  pPWM.u16Cm       =  100  ;
  pPWM.u8PreScale  =  221  ;
  pPWM.u8Div       =  PWM_CSR_1 ;
  pPWM.u8Mode      =  PWM_CHMOD_AUTO_RELOAD ;
  pPWM.u8Inv       =  PWM_NO_INVERT ;
  DrvPWM_SetClk(2, &pPWM) ;
  DrvPWM_Init(2) ;

  DrvPWM_EnableCaptureInt(2,PWM_CAP_RISING+PWM_CAP_FALLING);
  DrvPWM_CaptureEnable(2);
  PWMA_CAP2_PA14_ENABLE() ;                                //Enable PWM2 capture
  NVIC_SetPriority(PWMA_IRQn, 2);
}

/**
 * @brief       Software delay time
 *
 * @param       Cnt     Time of loop
 *
 * @return      None
 *
 * @details     Occur delay by software.
 */
void DelaySoft(uint32_t Cnt)
{
  uint32_t n = 0 ;

  for(n=0;n<Cnt;++n) ;
}


/**
 * @brief       PWMA IRQHandler
 *
 * @param       None
 *
 * @return      None
 *
 * @details     Every PWM2 captured a pulse, execute this routines.
 */
void PWMA_IRQHandler()
{
  if(PWM2_CAP_GET_FALL()){
    printf("\nCapture a falling: ") ;
    printf("%d",(0xFFFE - PWM_CAP2_FALL_TIME())/10) ;        //Print string in DEBUG UART1 window
  }
  else if(PWM2_CAP_GET_RISE()){
    printf("          capture a rise: ") ;
    printf("%d",(0xFFFE - PWM_CAP2_RISE_TIME())/10) ;        //Print string in DEBUG UART1 window
    printf("ms\n") ;

  }
  PWM2_CAP_CLEAR_IF() ;                                    //Clear interrupt flag
}

