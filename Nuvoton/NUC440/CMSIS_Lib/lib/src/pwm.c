/**************************************************************************//**
 * @file     PWM.c
 * @version  V1.00
 * $Revision: 13 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series PWM driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "pwm.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_PWM_Driver PWM Driver
  @{
*/


/** @addtogroup NUC400_PWM_EXPORTED_FUNCTIONS PWM Exported Functions
  @{
*/

/**
 * @brief This function config PWM generator and get the nearest frequency in edge aligned auto-reload mode
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Frequency Target generator frequency
 * @param[in] u32DutyCycle Target generator duty cycle percentage. Valid range are between 0 ~ 100. 10 means 10%, 20 means 20%...
 * @return Nearest frequency clock in nano second
 * @note Since every two channels, (0 & 1), (2 & 3), (4 & 5), shares a prescaler. Call this API to configure PWM frequency may affect
 *       existing frequency of other channel.
 */
uint32_t PWM_ConfigOutputChannel (PWM_T *pwm,
                                  uint32_t u32ChannelNum,
                                  uint32_t u32Frequency,
                                  uint32_t u32DutyCycle)
{
    uint32_t i;
    uint32_t u32PWM_CLock;
    uint8_t  u8Divider = 1, u8Prescale = 0xFF;
    uint16_t u16CNR = 0xFFFF;

    if (pwm == PWM0) {
        if (u32ChannelNum < 2) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 0)
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 1)
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 2)
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 3)
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 4)
                u32PWM_CLock = __LIRC;
        } else if (u32ChannelNum < 4) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (0 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (1 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (2 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (3 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (4 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __LIRC;
        } else if (u32ChannelNum < 6) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (0 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (1 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (2 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (3 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (4 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __LIRC;
        }
    } else if (pwm == PWM1) {
        if (u32ChannelNum < 2) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 0)
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 1)
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 2)
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 3)
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 4)
                u32PWM_CLock = __LIRC;
        } else if (u32ChannelNum < 4) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (0 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (1 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (2 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (3 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (4 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __LIRC;
        } else if (u32ChannelNum < 6) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (0 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (1 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (2 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (3 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __HIRC;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (4 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __LIRC;
        }
    }

    for(; u8Divider < 17; u8Divider <<= 1) {  // clk divider could only be 1, 2, 4, 8, 16
        i = (u32PWM_CLock / u32Frequency) / u8Divider;
        // If target value is larger than CNR * prescale, need to use a larger divider
        if(i > (0x10000 * 0x100))
            continue;

        // CNR = 0xFFFF + 1, get a prescaler that CNR value is below 0xFFFF
        u8Prescale = (i + 0xFFFF)/ 0x10000;

        // u8Prescale must at least be 2, otherwise the output stop
        if(u8Prescale < 3)
            u8Prescale = 2;

        i /= u8Prescale;

        if(i <= 0x10000) {
            if(i == 1)
                u16CNR = 1;     // Too fast, and PWM cannot generate expected frequency...
            else
                u16CNR = i;
            break;
        }

    }
    // Store return value here 'cos we're gonna change u8Divider & u8Prescale & u16CNR to the real value to fill into register
    i = u32PWM_CLock / (u8Prescale * u8Divider * u16CNR);

    u8Prescale -= 1;
    u16CNR -= 1;
    // convert to real register value
    if(u8Divider == 1)
        u8Divider = 4;
    else if (u8Divider == 2)
        u8Divider = 0;
    else if (u8Divider == 4)
        u8Divider = 1;
    else if (u8Divider == 8)
        u8Divider = 2;
    else // 16
        u8Divider = 3;

    // every two channels share a prescaler
    while((*(__IO uint32_t *) (&pwm->SBS0 + 1 * u32ChannelNum) & 1) == 1);
    pwm->CPR = (pwm->CPR & ~(PWM_CPR_CBP01_Msk << ((u32ChannelNum >> 1) * 8))) | (u8Prescale << ((u32ChannelNum >> 1) * 8));
    pwm->CDR = (pwm->CDR & ~(PWM_CDR_CBD0_Msk << (4 * u32ChannelNum))) | (u8Divider << (4 * u32ChannelNum));
    pwm->CONR |= 1 << (PWM_CONR_CNTMODE_Pos + u32ChannelNum);
    if(u32DutyCycle == 0)
        *(__IO uint32_t *) (&pwm->CMR0 + 1 * u32ChannelNum) = 0;
    else
        *(__IO uint32_t *) (&pwm->CMR0 + 1 * u32ChannelNum) = u32DutyCycle * (u16CNR + 1) / 100 - 1;
    *(__IO uint32_t *) (&pwm->CNR0 + 1 * u32ChannelNum) = u16CNR;

    return(i);
}

/**
 * @brief This function config PWM capture and get the nearest unit time
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32UnitTimeNsec Unit time of counter
 * @param[in] u32CaptureEdge Condition to latch the counter
 * @return Nearest unit time in nano second
 * @note Since every two channels, (0 & 1), (2 & 3), (4 & 5), shares a prescaler. Call this API to configure PWM frequency may affect
 *       existing frequency of other channel.
 */
uint32_t PWM_ConfigCaptureChannel (PWM_T *pwm,
                                   uint32_t u32ChannelNum,
                                   uint32_t u32UnitTimeNsec,
                                   uint32_t u32CaptureEdge)
{
    uint32_t i;
    uint32_t u32PWM_CLock;
    uint8_t  u8Divider = 1, u8Prescale = 0xFF;
    uint16_t u16CNR = 0xFFFF;

    if (pwm == PWM0) {
        if (u32ChannelNum < 2) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 0)
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 1)
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 2)
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH01_S_Msk) == 3)
                u32PWM_CLock = __HIRC;
        } else if (u32ChannelNum < 4) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (0 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (1 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (2 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH23_S_Msk) == (3 << CLK_CLKSEL2_PWM0CH23_S_Pos))
                u32PWM_CLock = __HIRC;
        } else if (u32ChannelNum < 6) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (0 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (1 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (2 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM0CH45_S_Msk) == (3 << CLK_CLKSEL2_PWM0CH45_S_Pos))
                u32PWM_CLock = __HIRC;
        }
    } else if (pwm == PWM1) {
        if (u32ChannelNum < 2) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 0)
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 1)
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 2)
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH01_S_Msk) == 3)
                u32PWM_CLock = __HIRC;
        } else if (u32ChannelNum < 4) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (0 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (1 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (2 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH23_S_Msk) == (3 << CLK_CLKSEL2_PWM1CH23_S_Pos))
                u32PWM_CLock = __HIRC;
        } else if (u32ChannelNum < 6) {
            if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (0 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __HXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (1 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __LXT;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (2 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = SystemCoreClock;
            else if ((CLK->CLKSEL2 & CLK_CLKSEL2_PWM1CH45_S_Msk) == (3 << CLK_CLKSEL2_PWM1CH45_S_Pos))
                u32PWM_CLock = __HIRC;
        }
    }

    for(; u8Divider < 17; u8Divider <<= 1) {  // clk divider could only be 1, 2, 4, 8, 16
        i = ((u32PWM_CLock / u8Divider) * u32UnitTimeNsec) / 1000000;

        // If target value is larger than 0xFF, need to use a larger divider
        if(i > (0xFF))
            continue;

        u8Prescale = i;

        // u8Prescale must at least be 2, otherwise the output stop
        if(u8Prescale < 3)
            u8Prescale = 2;

        break;
    }

    // Store return value here 'cos we're gonna change u8Divider & u8Prescale & u16CNR to the real value to fill into register
    i = (u8Prescale * u8Divider) * 1000000/ u32PWM_CLock;

    u8Prescale -= 1;
    u16CNR -= 1;
    // convert to real register value
    if(u8Divider == 1)
        u8Divider = 4;
    else if (u8Divider == 2)
        u8Divider = 0;
    else if (u8Divider == 4)
        u8Divider = 1;
    else if (u8Divider == 8)
        u8Divider = 2;
    else // 16
        u8Divider = 3;

    // every two channels share a prescaler
    while((*(__IO uint32_t *) (&pwm->SBS0 + 1 * u32ChannelNum) & 1) == 1);
    pwm->CPR = (pwm->CPR & ~(PWM_CPR_CBP01_Msk << ((u32ChannelNum >> 1) * 8))) | (u8Prescale << ((u32ChannelNum >> 1) * 8));
    pwm->CDR = (pwm->CDR & ~(PWM_CDR_CBD0_Msk << (4 * u32ChannelNum))) | (u8Divider << (4 * u32ChannelNum));
    pwm->CONR |= 1 << (PWM_CONR_CNTMODE_Pos + u32ChannelNum);
    *(__IO uint32_t *) (&pwm->CNR0 + 1 * u32ChannelNum) = u16CNR;

    return(i);
}

/**
 * @brief This function start PWM module
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Bit 0 is channel 0, bit 1 is channel 1...
 * @return None
 */
void PWM_Start (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->CER |= u32ChannelMask;
}

/**
 * @brief This function stop PWM module
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Bit 0 is channel 0, bit 1 is channel 1...
 * @return None
 */
void PWM_Stop (PWM_T *pwm, uint32_t u32ChannelMask)
{
    uint32_t i;
    for(i = 0; i < PWM_CHANNEL_NUM; i ++) {
        if(u32ChannelMask & (1 << i)) {
            *(__IO uint32_t *) (&pwm->CNR0 + 1 * i) = 0;
        }
    }

}

/**
 * @brief This function stop PWM generation immediately by clear channel enable bit
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Bit 0 is channel 0, bit 1 is channel 1...
 * @return None
 */
void PWM_ForceStop (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->CER &= ~u32ChannelMask;
}

/**
 * @brief This function enable selected channel to trigger ADC
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Condition The condition to trigger ADC. Combination of following conditions:
 *                  - \ref PWM_TRIGGER_ADC_PERIOD_POINT
 *                  - \ref PWM_TRIGGER_ADC_CENTER_POINT
 *                  - \ref PWM_TRIGGER_ADC_FALLING_EDGE_POINT
 *                  - \ref PWM_TRIGGER_ADC_RISING_EDGE_POINT
 * @return None
 */
void PWM_EnableADCTrigger (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition)
{
    pwm->TCR = (pwm->TCR & ~((PWM_TRIGGER_ADC_PERIOD_POINT |
                              PWM_TRIGGER_ADC_CENTER_POINT |
                              PWM_TRIGGER_ADC_FALLING_EDGE_POINT |
                              PWM_TRIGGER_ADC_RISING_EDGE_POINT ) << (1 * u32ChannelNum))) | (u32Condition << (1 * u32ChannelNum));
}

/**
 * @brief This function disable selected channel to trigger ADC
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_DisableADCTrigger (PWM_T *pwm, uint32_t u32ChannelNum)
{
    pwm->TCR = (pwm->TCR & ~((PWM_TRIGGER_ADC_PERIOD_POINT |
                              PWM_TRIGGER_ADC_CENTER_POINT |
                              PWM_TRIGGER_ADC_FALLING_EDGE_POINT |
                              PWM_TRIGGER_ADC_RISING_EDGE_POINT ) << (1 * u32ChannelNum)));
}

/**
 * @brief This function clear selected channel trigger ADC flag
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Condition PWM triggered ADC flag to be cleared. A combination of following flags:
 *                  - \ref PWM_TRIGGER_ADC_PERIOD_POINT
 *                  - \ref PWM_TRIGGER_ADC_CENTER_POINT
 *                  - \ref PWM_TRIGGER_ADC_FALLING_EDGE_POINT
 *                  - \ref PWM_TRIGGER_ADC_RISING_EDGE_POINT
 * @return None
 */
void PWM_ClearADCTriggerFlag (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition)
{
    pwm->TIR |= (u32Condition << (1 * u32ChannelNum));
}

/**
 * @brief This function get selected channel trigger ADC flag
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return Combination of following trigger conditions which triggered ADC
 *                  - \ref PWM_TRIGGER_ADC_PERIOD_POINT
 *                  - \ref PWM_TRIGGER_ADC_CENTER_POINT
 *                  - \ref PWM_TRIGGER_ADC_FALLING_EDGE_POINT
 *                  - \ref PWM_TRIGGER_ADC_FALLING_EDGE_POINT
 */
uint32_t PWM_GetADCTriggerFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    uint32_t u32Ret;

    u32Ret = pwm->TIR >> u32ChannelNum;

    return (u32Ret & (PWM_TRIGGER_ADC_PERIOD_POINT |
                      PWM_TRIGGER_ADC_CENTER_POINT |
                      PWM_TRIGGER_ADC_FALLING_EDGE_POINT |
                      PWM_TRIGGER_ADC_FALLING_EDGE_POINT));
}

/**
 * @brief This function enable fault brake of selected channels
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask This parameter is not used
 * @param[in] u32LevelMask Output high or low while fault brake occurs, each bit represent the level of a channel
 *                         while fault brake occurs. Bit 0 represents channel 0, bit 1 represents channel 1...
 *                         , bit 6 represent D6, and bit 7 represents D7
 * @param[in] u32BrakeSource Fault brake source, could be one of following source
 *                  - \ref PWM_BCR_CPO0BKEN_Msk
 *                  - \ref PWM_BCR_CPO1BKEN_Msk
 *                  - \ref PWM_BCR_CPO2BKEN_Msk
 *                  - \ref PWM_BCR_LVDBKEN_Msk
 *                  - \ref PWM_BCR_BK1SEL_BKP1
 *                  - \ref PWM_BCR_BK1SEL_CPO0
 *                  - \ref PWM_BCR_BK1SEL_CPO1
 * @return None
 */
void PWM_EnableFaultBrake (PWM_T *pwm,
                           uint32_t u32ChannelMask,
                           uint32_t u32LevelMask,
                           uint32_t u32BrakeSource)
{
    if (u32BrakeSource == PWM_BCR_LVDBKEN_Msk)
        pwm->BCR |= (PWM_BCR_LVDBKEN_Msk | PWM_BCR_BK1EN_Msk);
    else
        pwm->BCR |= (u32BrakeSource | PWM_BCR_BK0EN_Msk);
}

/**
 * @brief This function clear fault brake flag
 * @param[in] pwm The base address of PWM module
 * @param[in] u32BrakeSource This parameter is not used
 * @return None
 * @note After fault brake occurred, application must clear fault brake source before re-enable PWM output
 */
void PWM_ClearFaultBrakeFlag (PWM_T *pwm, uint32_t u32BrakeSource)
{
    pwm->BCR = PWM_IFR_BKLK0_Msk;
}

/**
 * @brief This function enables PWM capture of selected channels
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Set bit 0 to 1 enables channel 0 output, set bit 1 to 1 enables channel 1 output...
 * @return None
 */
void PWM_EnableCapture (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->CCR |= u32ChannelMask;
    pwm->CINER |= u32ChannelMask;
    pwm->CONR |= (u32ChannelMask << PWM_CONR_CNTMODE_Pos);
}

/**
 * @brief This function disables PWM capture of selected channels
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Set bit 0 to 1 enables channel 0 output, set bit 1 to 1 enables channel 1 output...
 * @return None
 */
void PWM_DisableCapture (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->CCR &= ~u32ChannelMask;
    pwm->CINER &= ~u32ChannelMask;
}

/**
 * @brief This function enables PWM output generation of selected channels
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel.
 *                           Set bit 0 to 1 enables channel 0 output, set bit 1 to 1 enables channel 1 output...
 * @return None
 */
void PWM_EnableOutput (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->OER |= u32ChannelMask;
}

/**
 * @brief This function disables PWM output generation of selected channels
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel
 *                           Set bit 0 to 1 disables channel 0 output, set bit 1 to 1 disables channel 1 output...
 * @return None
 */
void PWM_DisableOutput (PWM_T *pwm, uint32_t u32ChannelMask)
{
    pwm->OER &= ~u32ChannelMask;
}

/**
 * @brief This function enable Dead zone of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Duration Dead Zone length in PWM clock count, valid values are between 0~0xFF, but 0 means there is no
 *                        dead zone.
 * @return None
 */
void PWM_EnableDeadZone (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Duration)
{
    // every two channels shares the same setting
    u32ChannelNum >>= 1;
    // set duration
    pwm->DZCR = (pwm->DZCR & ~(PWM_DZCR_DZI01_Msk << (8 * u32ChannelNum))) | (u32Duration << (8 * u32ChannelNum));
    // enable dead zone
    pwm->DZCR |= (PWM_DZCR_DZEN01_Msk << u32ChannelNum);
}

/**
 * @brief This function disable Dead zone of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_DisableDeadZone (PWM_T *pwm, uint32_t u32ChannelNum)
{
    // every two channels shares the same setting
    u32ChannelNum >>= 1;
    // enable dead zone
    pwm->DZCR &= ~(PWM_DZCR_DZEN01_Msk << u32ChannelNum);
}

/**
 * @brief This function enable capture interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Edge Capture interrupt type. It could be either
 *              - \ref PWM_FALLING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_FALLING_LATCH_INT_ENABLE
 * @return None
 */
void PWM_EnableCaptureInt (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge)
{
    // enable capture interrupt
    pwm->IER |= (u32Edge << u32ChannelNum);
}

/**
 * @brief This function disable capture interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Edge Capture interrupt type. It could be either
 *              - \ref PWM_FALLING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_FALLING_LATCH_INT_ENABLE
 * @return None
 */
void PWM_DisableCaptureInt (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge)
{
    // disable capture interrupt
    pwm->IER &= ~(u32Edge << u32ChannelNum);
}

/**
 * @brief This function clear capture interrupt flag of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Edge Capture interrupt type. It could be either
 *              - \ref PWM_FALLING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_LATCH_INT_ENABLE
 *              - \ref PWM_RISING_FALLING_LATCH_INT_ENABLE
 * @return None
 */
void PWM_ClearCaptureIntFlag (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge)
{
    // disable capture interrupt flag
    pwm->IFR = (u32Edge << u32ChannelNum);
}

/**
 * @brief This function get capture interrupt flag of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return Capture interrupt flag of specified channel
 * @retval 0 Capture interrupt did not occurred
 * @retval \t PWM_RISING_LATCH_INT_FLAG Rising edge latch interrupt occurred
 * @retval \t PWM_FALLING_LATCH_INT_FLAG Falling edge latch interrupt occurred
 * @retval \t PWM_RISING_FALLING_LATCH_INT_FLAG Rising and falling edge latch interrupt occurred
 */
uint32_t PWM_GetCaptureIntFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    return ((pwm->IFR & (PWM_RISING_FALLING_LATCH_INT_FLAG << u32ChannelNum)) >> u32ChannelNum);
}

/**
 * @brief This function enable duty interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32IntDutyType Duty interrupt type. It could be either
 *              - \ref PWM_DUTY_INT_MATCH_CMR_UP
 *              - \ref PWM_DUTY_INT_MATCH_CMR_DN
 * @return None
 */
void PWM_EnableDutyInt (PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType)
{
    // set duty interrupt type
    pwm->ICR = (pwm->ICR & ~(PWM_DUTY_INT_MATCH_CMR_UP << u32ChannelNum)) | (u32IntDutyType << u32ChannelNum);
    // enable duty interrupt
    pwm->IER |= ((1 << PWM_IER_PDIE_Pos) << u32ChannelNum);
}

/**
 * @brief This function disable duty interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_DisableDutyInt (PWM_T *pwm, uint32_t u32ChannelNum)
{
    pwm->IER &= ~((1 << PWM_IER_PDIE_Pos) << u32ChannelNum);
}

/**
 * @brief This function clears duty interrupt flag of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_ClearDutyIntFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    // write 1 clear
    pwm->IFR = (1 << PWM_IFR_PDIF_Pos) << u32ChannelNum;
}

/**
 * @brief This function get duty interrupt flag of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return Duty interrupt flag of specified channel
 * @retval 0 Duty interrupt did not occurred
 * @retval 1 Duty interrupt occurred
 */
uint32_t PWM_GetDutyIntFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    return(pwm->IFR & ((1 << PWM_IFR_PDIF_Pos) << u32ChannelNum) ? 1 : 0);
}

/**
 * @brief This function enable fault brake interrupt
 * @param[in] pwm The base address of PWM module
 * @param[in] u32BrakeSource This parameter is not used
 * @return None
 */
void PWM_EnableFaultBrakeInt (PWM_T *pwm, uint32_t u32BrakeSource)
{
    pwm->IER |= PWM_IER_BRKIE_Msk;
}

/**
 * @brief This function disable fault brake interrupt
 * @param[in] pwm The base address of PWM module
 * @param[in] u32BrakeSource This parameter is not used
 * @return None
 */
void PWM_DisableFaultBrakeInt (PWM_T *pwm, uint32_t u32BrakeSource)
{
    pwm->IER &= ~PWM_IER_BRKIE_Msk;
}

/**
 * @brief This function clear fault brake interrupt of selected source
 * @param[in] pwm The base address of PWM module
 * @param[in] u32BrakeSource Fault brake source, could be either
 *                  - \ref PWM_IFR_BKIF0_Msk, or
 *                  - \ref PWM_IFR_BKIF1_Msk
 * @return None
 */
void PWM_ClearFaultBrakeIntFlag (PWM_T *pwm, uint32_t u32BrakeSource)
{
    pwm->IFR = u32BrakeSource;
}

/**
 * @brief This function get fault brake interrupt of selected source
 * @param[in] pwm The base address of PWM module
 * @param[in] u32BrakeSource Fault brake source, could be either
 *                  - \ref PWM_IFR_BKIF0_Msk, or
 *                  - \ref PWM_IFR_BKIF1_Msk
 * @return Fault brake interrupt flag of specified source
 * @retval 0 Fault brake interrupt did not occurred
 * @retval 1 Fault brake interrupt occurred
 */
uint32_t PWM_GetFaultBrakeIntFlag (PWM_T *pwm, uint32_t u32BrakeSource)
{
    return (pwm->IFR & u32BrakeSource ? 1 : 0);
}

/**
 * @brief This function enable period interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32IntPeriodType Period interrupt type, could be either
 *              - \ref PWM_PERIOD_INT_UNDERFLOW
 *              - \ref PWM_PERIOD_INT_MATCH_CNR
 * @return None
 * @note All channels share the same period interrupt type setting.
 */
void PWM_EnablePeriodInt (PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType)
{
    // set period interrupt type
    pwm->ICR = (pwm->ICR & ~(PWM_PERIOD_INT_MATCH_CNR << u32ChannelNum)) | (u32IntPeriodType << u32ChannelNum);
    // enable period interrupt
    pwm->IER |= ((1 << PWM_IER_PPIE_Pos) << u32ChannelNum);
}

/**
 * @brief This function disable period interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_DisablePeriodInt (PWM_T *pwm, uint32_t u32ChannelNum)
{
    pwm->IER &= ~((1 << PWM_IER_PPIE_Pos) << u32ChannelNum);
}

/**
 * @brief This function clear period interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
void PWM_ClearPeriodIntFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    // write 1 clear
    pwm->IFR = ((1 << PWM_IFR_PPIF_Pos) << u32ChannelNum);
}

/**
 * @brief This function get period interrupt of selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return Period interrupt flag of specified channel
 * @retval 0 Period interrupt did not occurred
 * @retval 1 Period interrupt occurred
 */
uint32_t PWM_GetPeriodIntFlag (PWM_T *pwm, uint32_t u32ChannelNum)
{
    return(pwm->IFR & ((1 << PWM_IFR_PPIF_Pos) << u32ChannelNum) ? 1 : 0);
}



/*@}*/ /* end of group NUC400_PWM_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_PWM_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
