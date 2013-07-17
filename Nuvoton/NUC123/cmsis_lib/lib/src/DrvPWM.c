/******************************************************************************
 * @file     nano1xx_pwm.c
 * @brief    NANO1xx PWM driver source file
 * @version  1.0.1
 * @date     04, September, 2012
 *
 * @note
 * Copyright (C) 2012-2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "NUC123Series.h"
#include "PWM.h"
#include "CLOCK.h"
#include "SYS.h"


/** @addtogroup NUC123_FUNC NUC123 Driver API
  * @{
  */

/// @cond
// two channels share a single clock en bit. need to keep track of enabled channel, so we know when to disable clock

/// @endcond

/** @addtogroup DrvPWM_FUNC PWM Driver API
  * @{
  */


/**
  * @brief  Enable PWM interrupt
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_EnableInt(uint8_t u8Ch)
{
    PWMA->PIER |=  1 << u8Ch;
    NVIC_EnableIRQ(PWMA_IRQn);
}

/**
  * @brief  Disable PWM interrupt
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_DisableInt(uint8_t u8Ch)
{
  PWMA->PIER &= ~(1 << u8Ch) ;
  if(((PWMA->PIER & 0x0F0F) == 0)&&((PWMA->CCR0 & 0x60006) == 0)&&((PWMA->CCR2 & 0x60006) == 0))
    NVIC_DisableIRQ(PWMA_IRQn) ;
}

/**
  * @brief  Enable PWM capture interrupt
  * @param  u8Ch    Specify the PWM channel
  *         u32Int  must be the following or their plus . 
  *         PWM_CAP_RISING                   //  0x2
  *         PWM_CAP_FALLING                  //  0x4
  * @return None
  */
void DrvPWM_EnableCaptureInt(uint8_t u8Ch, uint32_t u32Int)  
{
    uint32_t IntMask = u32Int ; 
    volatile uint32_t *pCCR ;

    pCCR = (u8Ch < 2) ? (&PWMA->CCR0) : (&PWMA->CCR2);
    if(u8Ch & 0x1)  IntMask = u32Int << 16 ;         
    *pCCR |= IntMask ;         
    NVIC_EnableIRQ(PWMA_IRQn) ;
}

/**
  * @brief  Disable PWM capture interrupt
  * @param  u8Ch  Specify the PWM channel
  *         u32int Must be the following constance or their plus
  *         PWM_CAP_RISING            //0x2
  *         PWM_CAP_FALLING          // 0x4
  * @return None
  */
void DrvPWM_DisableCaptureInt(uint8_t u8Ch, uint32_t u32Int)
{
  uint32_t IntMask = u32Int ; 
  volatile uint32_t *pCCR ;

  pCCR = (u8Ch < 2) ? (&PWMA->CCR0) : (&PWMA->CCR2) ;
  if(u8Ch & 0x2)  IntMask = u32Int << 16 ;         
  *pCCR &= ~IntMask ;         

  if(((PWMA->PIER & 0x0F0F) == 0)&&((PWMA->CCR0 & 0x60006) == 0)&&((PWMA->CCR0 & 0x60006) == 0))
    NVIC_DisableIRQ(PWMA_IRQn) ;
}

/**
  * @brief  Init PWM channel
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_Init(uint8_t u8Ch)
{
  switch(u8Ch){
  case 0 :
    CLK->APBCLK |= CLK_PWM01 ;
    PWMA->PCR   |= PWM_CH0_EN ;
    break;

  case 1 :
    CLK->APBCLK |= CLK_PWM01 ;
    PWMA->PCR   |= PWM_CH1_EN ;
    break ;

  case 2 :
    CLK->APBCLK |= CLK_PWM23 ;
    PWMA->PCR   |= PWM_CH2_EN ;
    break ;

  case 3 :
    CLK->APBCLK |= CLK_PWM23 ;
    PWMA->PCR   |= PWM_CH3_EN ;
    break ;
  }
}

/**
  * @brief  DeInit PWM channel
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_DeInit(uint8_t u8Ch)
{
  switch(u8Ch){
  case 0 :
    CLK->APBCLK &= ~CLK_PWM01 ;
    PWMA->PCR   &= ~1 ;
    break;

  case 1 :
    CLK->APBCLK &= ~CLK_PWM01 ;
    PWMA->PCR   &= ~0x100 ;
    break ;

  case 2 :
    CLK->APBCLK &= ~CLK_PWM23 ;
    PWMA->PCR   &= ~0x10000 ;
    break ;

  case 3 :
    CLK->APBCLK &= ~CLK_PWM23 ;
    PWMA->PCR   &= ~0x1000000 ;
    break ;
  }
}

/**
  * @brief  Enable PWM output dead zone and set duration
  * @param  u8Ch     Specify the PWM channel
  * @param  u8Length    dead zone Duration
  * @return None
  */
void DrvPWM_EnableDeadZone(uint8_t u8Ch, uint8_t u8Length)
{
  if(u8Ch & 0x02){
    PWMA->PPR  =  (PWMA->PPR & 0xFFFFFF) | (u8Length << 24);
    PWMA->PCR |=  0x20 ;
  }
  else{
    PWMA->PPR  =  (PWMA->PPR & 0xFF00FFFF) | (u8Length << 16);
    PWMA->PCR |=  0x10 ;
  }
}

/**
  * @brief  Disable PWM output dead zone
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_DisableDeadZone(uint8_t u8Ch)
{
  if(u8Ch & 0x02){
    PWMA->PCR &= ~0x20 ;
  }
  else{
    PWMA->PCR &= ~0x10 ;
  }
}

/**
  * @brief  Enable PWM capture channel
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_CaptureEnable(uint8_t u8Ch)
{
  switch(u8Ch){
  case 0 :
    PWMA->CCR0 |= 0x08 ;
    break;

  case 1 :
    PWMA->CCR0 |= 0x080000 ;
    break ;

  case 2 :
    PWMA->CCR2 |= 0x08 ;
    break ;

  case 3 :
    PWMA->CCR2 |= 0x080000 ;
    break ;
  }
}

/**
  * @brief  Disable PWM capture channel
  * @param  u8Ch  Specify the PWM channel
  * @return None
  */
void DrvPWM_CaptureDisable(uint8_t u8Ch)
{
  switch(u8Ch){
  case 0 :
    PWMA->CCR0 &= ~0x08 ;
    break;

  case 1 :
    PWMA->CCR0 &= ~0x080000 ;
    break ;

  case 2 :
    PWMA->CCR2 &= ~0x08 ;
    break ;

  case 3 :
    PWMA->CCR2 &= ~0x080000 ;
    break ;
  }
}

/**
  * @brief  Configure PWM clock parameters
  * @param  u8Ch  Specify the PWM channel
  * @param  cfg Structure pointer points to timing parameters
  * @return None
  */
void DrvPWM_SetClk(uint8_t u8Ch, S_DRVPWM_TIME_DATA_T *cfg)
{
  uint32_t reg=0 ;

  PWMA->PPR  &= ~(0xFF << ((u8Ch>>1)<<3)) ;
  PWMA->PPR  |=  (cfg->u8PreScale-1) << ((u8Ch>>1)<<3) ;
 
  PWMA->CSR  &=  ~(7 <<(u8Ch<<2)) ;
  PWMA->CSR  |=  cfg->u8Div << (u8Ch<<2) ;

  if(cfg->u8Mode) reg  =  8 ;
  if(cfg->u8Inv)  reg |=  6 ;
  PWMA->PCR &= ~(0xE << (u8Ch<<3)) ;
  PWMA->PCR |=  reg << (u8Ch<<3)   ;

  switch(u8Ch){
  case 0 :
    PWMA->CNR0  =  cfg->u16Cn ;
    PWMA->CMR0  =  cfg->u16Cm ;
    break;

  case 1 :
    PWMA->CNR1  =  cfg->u16Cn ;
    PWMA->CMR1  =  cfg->u16Cm ;
    break ;

  case 2 :
    PWMA->CNR2  =  cfg->u16Cn ;
    PWMA->CMR2  =  cfg->u16Cm ;
    break ;

  case 3 :
    PWMA->CNR3  =  cfg->u16Cn ;
    PWMA->CMR3  =  cfg->u16Cm ;
    break ;
  }
}

/**
  * @brief  Enable/Disable PWM capture input
  * @param  u8Ch    Specify the PWM channel
  * @param  u32Enable   Enable/Disable
  * @return None
  */
void DrvPWM_ConfigCaptureIntput(uint8_t u8Ch, uint32_t u32Enable)
{
  volatile uint32_t *pCCR ;

  pCCR  = (u8Ch < 2) ? (&PWMA->CCR0) : (&PWMA->CCR2) ;
  if(u32Enable)  *pCCR |=  8 << ((u8Ch & 0x01)<<4) ;
  else           *pCCR &=  ~(8 << ((u8Ch & 0x01)<<4)) ;
}

/**
  * @brief  Enable PDMA transfer of a capture channel
  * @param  u8Ch Specify the PWM channel
  * @return None
  */
void DrvPWM_EnablePdma(uint8_t u8Ch)
{
  PWMA->CAPPDMACTL |= 1 << ((u8Ch & 0x3)<<3) ;
}

/**
  * @brief  Disable PDMA transfer of a capture channel
  * @param  u8Ch Specify the PWM channel
  * @return None
  */
void DrvPWM_DisablePdma(uint8_t u8Ch)
{
    PWMA->CAPPDMACTL &= ~(1 << ((u8Ch & 0x3)<<3));
}

/*@}*/ /* end of group DrvPWM_FUNC */

/*@}*/ /* end of group NUC123_FUNC */

/*** (C) COPYRIGHT 2012 Nuvoton Technology Corp. ***/
