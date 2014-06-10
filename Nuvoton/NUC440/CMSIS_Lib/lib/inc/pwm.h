/**************************************************************************//**
 * @file     pwm.h
 * @version  V1.00
 * $Revision: 12 $
 * $Date: 14/01/14 10:47a $
 * @brief    NUC400 series PWM driver header file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NUC400Series.h"
/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_PWM_Driver PWM Driver
  @{
*/

/** @addtogroup NUC400_PWM_EXPORTED_CONSTANTS PWM Exported Constants
  @{
*/
#define PWM_CHANNEL_NUM                     (6)   /*!< PWM channel number */
#define PWM_CH_0_MASK                       (1UL << 0)    /*!< PWM channel 0 mask */
#define PWM_CH_1_MASK                       (1UL << 1)    /*!< PWM channel 1 mask */
#define PWM_CH_2_MASK                       (1UL << 2)    /*!< PWM channel 2 mask */
#define PWM_CH_3_MASK                       (1UL << 3)    /*!< PWM channel 3 mask */
#define PWM_CH_4_MASK                       (1UL << 4)    /*!< PWM channel 4 mask */
#define PWM_CH_5_MASK                       (1UL << 5)    /*!< PWM channel 5 mask */
#define PWM_CH_6_MASK                       (1UL << 6)    /*!< PWM channel 6 mask */
#define PWM_CH_7_MASK                       (1UL << 7)    /*!< PWM channel 7 mask */
#define PWM_CLK_DIV_1                       (4UL) /*!< PWM clock divide by 1 */
#define PWM_CLK_DIV_2                       (0UL) /*!< PWM clock divide by 2 */
#define PWM_CLK_DIV_4                       (1UL) /*!< PWM clock divide by 4 */
#define PWM_CLK_DIV_8                       (2UL) /*!< PWM clock divide by 8 */
#define PWM_CLK_DIV_16                      (3UL) /*!< PWM clock divide by 16 */
#define PWM_EDGE_ALIGNED                    (0UL) /*!< PWM working in edge aligned type */
#define PWM_CENTER_ALIGNED                  (1UL) /*!< PWM working in center aligned type */
#define PWM_TRIGGER_ADC_RISING_EDGE_POINT   (1 << PWM_TCR_RETRG_EN_Pos)     /*!< PWM trigger ADC while output rising edge is detected */
#define PWM_TRIGGER_ADC_FALLING_EDGE_POINT  (1 << PWM_TCR_FETRG_EN_Pos)   /*!< PWM trigger ADC while output falling edge is detected */
#define PWM_TRIGGER_ADC_CENTER_POINT        (1 << PWM_TCR_CTRG_EN_Pos)   /*!< PWM trigger ADC while counter matches (CNR + 1) */
#define PWM_TRIGGER_ADC_PERIOD_POINT        (1 << PWM_TCR_PTRG_EN_Pos)   /*!< PWM trigger ADC while counter down count to 0  */
#define PWM_BCR_BK1SEL_BKP1                 (0UL) /*!< Brake1 signal source from external pin BKP1 */
#define PWM_BCR_BK1SEL_CPO0                 (1UL) /*!< Brake1 signal source from analog comparator 0 output */
#define PWM_BCR_BK1SEL_CPO1                 (2UL) /*!< Brake1 signal source from analog comparator 1 output */
#define PWM_PERIOD_INT_UNDERFLOW            (0)                         /*!< PWM period interrupt trigger if counter underflow */
#define PWM_PERIOD_INT_MATCH_CNR            (1UL)                       /*!< PWM period interrupt trigger if counter match CNR */
#define PWM_DUTY_INT_MATCH_CMR_DN           (0)                         /*!< PWM duty interrupt if counter match CNR during down counting */
#define PWM_DUTY_INT_MATCH_CMR_UP           (1 << PWM_ICR_DINTTYPE_Pos) /*!< PWM duty interrupt if counter match CNR during up counting */
#define PWM_FALLING_LATCH_INT_ENABLE        (1 << PWM_IER_FLIE_Pos)         /*!< PWM falling latch interrupt enable */
#define PWM_RISING_LATCH_INT_ENABLE         (1 << PWM_IER_RLIE_Pos)         /*!< PWM rising latch interrupt enable */
#define PWM_RISING_FALLING_LATCH_INT_ENABLE (0x101 << PWM_IER_RLIE_Pos)     /*!< PWM rising latch interrupt enable */
#define PWM_FALLING_LATCH_INT_FLAG          (PWM_FALLING_LATCH_INT_ENABLE)         /*!< PWM falling latch condition happened */
#define PWM_RISING_LATCH_INT_FLAG           (PWM_RISING_LATCH_INT_ENABLE)          /*!< PWM rising latch condition happened */
#define PWM_RISING_FALLING_LATCH_INT_FLAG   (PWM_RISING_FALLING_LATCH_INT_ENABLE)  /*!< PWM rising latch condition happened */

/*@}*/ /* end of group NUC400_PWM_EXPORTED_CONSTANTS */


/** @addtogroup NUC400_PWM_EXPORTED_FUNCTIONS PWM Exported Functions
  @{
*/

/**
 * @brief This macro enable complementary mode
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_ENABLE_COMPLEMENTARY_MODE(pwm) (pwm->CONR = pwm->CONR | PWM_CONR_OUTMD_Msk)

/**
 * @brief This macro disable complementary mode, and enable independent mode.
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_DISABLE_COMPLEMENTARY_MODE(pwm) (pwm->CONR = pwm->CONR & ~PWM_CONR_OUTMD_Msk)

/**
 * @brief This macro enable group mode
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_ENABLE_GROUP_MODE(pwm) (pwm->CONR = pwm->CONR | PWM_CONR_GRP_EN_Msk)

/**
 * @brief This macro disable group mode
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_DISABLE_GROUP_MODE(pwm) (pwm->CONR = pwm->CONR & ~PWM_CONR_GRP_EN_Msk)

/**
 * @brief This macro enable synchronous mode
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_ENABLE_SYNC_MODE(pwm) (pwm->CONR = pwm->CONR | PWM_CONR_SYNC_EN_Msk)

/**
 * @brief This macro disable synchronous mode, and enable independent mode.
 * @param[in] pwm The base address of PWM module
 * @return None
 */
#define PWM_DISABLE_SYNC_MODE(pwm) (pwm->CONR = pwm->CONR & ~PWM_CONR_SYNC_EN_Msk)

/**
 * @brief This macro enable output inverter of specified channel(s)
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel
 *                           Bit 0 represents channel 0, bit 1 represents channel 1...
 * @return None
 */
#define PWM_ENABLE_OUTPUT_INVERTER(pwm, u32ChannelMask) (pwm->CONR |= (u32ChannelMask << PWM_CONR_PINV_Pos)

/**
 * @brief This macro get captured rising data
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
#define PWM_GET_CAPTURE_RISING_DATA(pwm, u32ChannelNum) (*(__IO uint32_t *) (&pwm->CRLR0 + 2 * u32ChannelNum))

/**
 * @brief This macro get captured falling data
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @return None
 */
#define PWM_GET_CAPTURE_FALLING_DATA(pwm, u32ChannelNum) (*(__IO uint32_t *) (&pwm->CFLR0 + 2 * u32ChannelNum))

/**
 * @brief This macro mask output output logic to high or low
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel
 *                           Bit 0 represents channel 0, bit 1 represents channel 1...
 * @param[in] u32LevelMask Output logic to high or low
 * @return None
 */
#define PWM_MASK_OUTPUT(pwm, u32ChannelMask, u32LevelMask) (pwm->MCR |= u32ChannelMask)

/**
 * @brief This macro set the prescaler of the selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Prescaler Clock prescaler of specified channel. Valid values are between 1 ~ 0xFF
 * @return None
 * @note Every even channel N, and channel (N + 1) share a prescaler. So if channel 0 prescaler changed,
 *       channel 1 will also be affected.
 */
#define PWM_SET_PRESCALER(pwm, u32ChannelNum, u32Prescaler) \
    (pwm->CPR = (pwm->CPR & ~(PWM_CPR_CBP01_Msk << (((u32ChannelNum) >> 1) * 8))) | ((u32Prescaler) << (((u32ChannelNum) >> 1) * 8)))

/**
 * @brief This macro set the divider of the selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32Divider Clock divider of specified channel. Valid values are
 *              - \ref PWM_CLK_DIV_1
 *              - \ref PWM_CLK_DIV_2
 *              - \ref PWM_CLK_DIV_4
 *              - \ref PWM_CLK_DIV_8
 *              - \ref PWM_CLK_DIV_16
 * @return None
 */
#define PWM_SET_DIVIDER(pwm, u32ChannelNum, u32Divider) \
    (pwm->CDR = (pwm->CDR & ~(PWM_CDR_CBD0_Msk << ((u32ChannelNum) * 4))) | ((u32Divider) << ((u32ChannelNum) * 4)))

/**
 * @brief This macro set the duty of the selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32CMR Duty of specified channel. Valid values are between 0~0xFFFF
 * @return None
 * @note This new setting will take effect on next PWM period
 */
#define PWM_SET_CMR(pwm, u32ChannelNum, u32CMR) (*(__IO uint32_t *) (&pwm->CMR0 + 1 * u32ChannelNum) = (u32CMR))

/**
 * @brief This macro set the period of the selected channel
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelNum PWM channel number. Valid values are between 0~5
 * @param[in] u32CNR Period of specified channel. Valid values are between 0~0xFFFF
 * @return None
 * @note This new setting will take effect on next PWM period
 * @note PWM counter will stop if period length set to 0
 */
#define PWM_SET_CNR(pwm, u32ChannelNum, u32CNR)  (*(__IO uint32_t *) (&pwm->CNR0 + 1 * u32ChannelNum) = (u32CNR))

/**
 * @brief This macro set the PWM aligned type
 * @param[in] pwm The base address of PWM module
 * @param[in] u32ChannelMask Combination of enabled channels. Each bit corresponds to a channel
 *                           Bit 0 represents channel 0, bit 1 represents channel 1...
 * @param[in] u32AlignedType PWM aligned type, valid values are:
 *                  - PWM_EDGE_ALIGNED
 *                  - PWM_CENTER_ALIGNED
 * @return None
 */
#define PWM_SET_ALIGNED_TYPE(pwm, u32ChannelMask, u32AlignedType) \
    (pwm->CONR = (pwm->CONR & ~(u32ChannelMask << PWM_CONR_CNTMODE_Pos) | (u32AlignedType << PWM_CONR_CNTMODE_Pos))


uint32_t PWM_ConfigOutputChannel(PWM_T *pwm,
                                 uint32_t u32ChannelNum,
                                 uint32_t u32Frequency,
                                 uint32_t u32DutyCycle);
uint32_t PWM_ConfigCaptureChannel (PWM_T *pwm,
                                   uint32_t u32ChannelNum,
                                   uint32_t u32UnitTimeNsec,
                                   uint32_t u32CaptureEdge);
void PWM_Start(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_Stop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_ForceStop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void PWM_DisableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t PWM_GetADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableFaultBrake(PWM_T *pwm,
                          uint32_t u32ChannelMask,
                          uint32_t u32LevelMask,
                          uint32_t u32BrakeSource);
void PWM_ClearFaultBrakeFlag(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_EnableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Duration);
void PWM_DisableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_DisableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_ClearCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t PWM_GetCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType);
void PWM_DisableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableFaultBrakeInt(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_DisableFaultBrakeInt(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_ClearFaultBrakeIntFlag(PWM_T *pwm, uint32_t u32BrakeSource);
uint32_t PWM_GetFaultBrakeIntFlag(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_EnablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void PWM_DisablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);



/*@}*/ /* end of group NUC400_PWM_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_PWM_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

#ifdef __cplusplus
}
#endif

#endif //__PWM_H__

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
