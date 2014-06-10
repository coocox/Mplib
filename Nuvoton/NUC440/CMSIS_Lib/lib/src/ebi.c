/****************************************************************************//**
 * @file     ebi.c
 * @version  V0.10
 * $Revision: 4 $
 * $Date: 13/12/10 10:25a $
 * @brief    NUC400 series EBI driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
//#include "NUC400Series.h"
#include "ebi.h"

/** @addtogroup NUC400_Device_Driver NUC400 Device Driver
  @{
*/

/** @addtogroup NUC400_EBI_Driver EBI Driver
  @{
*/


/** @addtogroup NUC400_EBI_EXPORTED_FUNCTIONS EBI Exported Functions
  @{
*/

/**
  * @brief  Initialize EBI for Bank 0~3
  * @param[in]  u32Bank Bank number for EBI. Valid values are:
  *                      - \ref EBI_BANK0
  *                      - \ref EBI_BANK1
  *                      - \ref EBI_BANK2
  *                      - \ref EBI_BANK3
  * @param[in]  u32DataWidth Data bus width. Valid values are:
  *                      - \ref EBI_BUSWIDTH_8BIT
  *                      - \ref EBI_BUSWIDTH_16BIT
  * @param[in]  u32TimingClass Default timing configuration. Valid values are:
  *                      - \ref EBI_TIMING_FASTEST
  *                      - \ref EBI_TIMING_VERYFAST
  *                      - \ref EBI_TIMING_FAST
  *                      - \ref EBI_TIMING_NORMAL
  *                      - \ref EBI_TIMING_SLOW
  *                      - \ref EBI_TIMING_VERYSLOW
  *                      - \ref EBI_TIMING_SLOWEST
  * @param[in]  u32BusMode Enable EBI separate mode. Valid values are:
  *                      - \ref EBI_SEPARATEMODE_ENABLE
  *                      - \ref EBI_SEPARATEMODE_DISABLE
  * @param[in]  u32CSActiveLevel CS is active High/Low. Valid values are:
  *                      - \ref EBI_CS_ACTIVE_HIGH
  *                      - \ref EBI_CS_ACTIVE_LOW
  * @return none
  */
void EBI_Open(uint32_t u32Bank, uint32_t u32DataWidth, uint32_t u32TimingClass, uint32_t u32BusMode, uint32_t u32CSActiveLevel)
{
    uint32_t *u32EbiExtimeBase = (uint32_t *)(&EBI->EXTIME0 + u32Bank);

    *u32EbiExtimeBase |= EBI_EXTIME_EXTEN_Msk;
    if(u32DataWidth == EBI_BUSWIDTH_8BIT)
        *u32EbiExtimeBase &= ~EBI_EXTIME_BW16_Msk;
    else
        *u32EbiExtimeBase |= EBI_EXTIME_BW16_Msk;

    if(u32BusMode)
        *u32EbiExtimeBase |= EBI_EXTIME_SEPEN_Msk;
    else
        *u32EbiExtimeBase &= ~EBI_EXTIME_SEPEN_Msk;

    switch(u32Bank) {
    case EBI_BANK0:
        if(u32CSActiveLevel)
            EBI->EBICON |= EBI_EBICON_EXTCS0_Msk;
        else
            EBI->EBICON &= ~EBI_EBICON_EXTCS0_Msk;
        break;

    case EBI_BANK1:
        if(u32CSActiveLevel)
            EBI->EBICON |= EBI_EBICON_EXTCS1_Msk;
        else
            EBI->EBICON &= ~EBI_EBICON_EXTCS1_Msk;
        break;

    case EBI_BANK2:
        if(u32CSActiveLevel)
            EBI->EBICON |= EBI_EBICON_EXTCS2_Msk;
        else
            EBI->EBICON &= ~EBI_EBICON_EXTCS2_Msk;
        break;

    case EBI_BANK3:
        if(u32CSActiveLevel)
            EBI->EBICON |= EBI_EBICON_EXTCS3_Msk;
        else
            EBI->EBICON &= ~EBI_EBICON_EXTCS3_Msk;
        break;
    }

    *u32EbiExtimeBase &= ~0x0F0FF7FF;

    switch(u32TimingClass) {
    case EBI_TIMING_FASTEST:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_1 << 8);
        break;

    case EBI_TIMING_VERYFAST:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_1 << 8);
        *u32EbiExtimeBase |= 0x0303331B;
        break;

    case EBI_TIMING_FAST:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_2 << 8);
        break;

    case EBI_TIMING_NORMAL:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_2 << 8);
        *u32EbiExtimeBase |= 0x0303331B;
        break;

    case EBI_TIMING_SLOW:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_2 << 8);
        *u32EbiExtimeBase |= 0x0707773F;
        break;

    case EBI_TIMING_VERYSLOW:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_4 << 8);
        *u32EbiExtimeBase |= 0x0707773F;
        break;

    case EBI_TIMING_SLOWEST:
        EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (  EBI_MCLKDIV_8 << 8);
        *u32EbiExtimeBase |= 0x0707773F;
        break;
    }
}

/**
  * @brief  Disable EBI for bank 0~3.
  * @param[in]  u32Bank Bank number for EBI. Valid values are:
  *                      - \ref EBI_BANK0
  *                      - \ref EBI_BANK1
  *                      - \ref EBI_BANK2
  *                      - \ref EBI_BANK3
  * @return none
  */
void EBI_Close(uint8_t u32Bank)
{
    switch(u32Bank) {
    case EBI_BANK0:
        EBI->EXTIME0 &= ~EBI_EXTIME_EXTEN_Msk;
        break;

    case EBI_BANK1:
        EBI->EXTIME1 &= ~EBI_EXTIME_EXTEN_Msk;
        break;

    case EBI_BANK2:
        EBI->EXTIME2 &= ~EBI_EXTIME_EXTEN_Msk;
        break;

    case EBI_BANK3:
        EBI->EXTIME3 &= ~EBI_EXTIME_EXTEN_Msk;
        break;
    }
}

/**
  * @brief  Set EBI bus timings
  * @param[in]  u32Bank Bank number for EBI. Valid values are:
  *                      - \ref EBI_BANK0
  *                      - \ref EBI_BANK1
  *                      - \ref EBI_BANK2
  *                      - \ref EBI_BANK3
  * @param[in]  u32TimingConfig The new EBI timing settings.
  * @param[in]  u32MclkDiv Divider for MCLK. Valid values are:
  *                      - \ref EBI_MCLKDIV_1
  *                      - \ref EBI_MCLKDIV_2
  *                      - \ref EBI_MCLKDIV_4
  *                      - \ref EBI_MCLKDIV_8
  *                      - \ref EBI_MCLKDIV_16
  *                      - \ref EBI_MCLKDIV_32
  * @return none
  */
void EBI_SetBusTiming(uint32_t u32Bank, uint32_t u32TimingConfig, uint32_t u32MclkDiv)
{
    uint32_t *u32EbiExtimeBase = (uint32_t *)(&EBI->EXTIME0 + u32Bank);

    EBI->EBICON = (EBI->EBICON & ~EBI_EBICON_MCLKDIV_Msk) | (u32MclkDiv << 8);
    *u32EbiExtimeBase |= u32TimingConfig;
}

/**
  * @brief  Enable encrypt/decrypt function and set key for EBI bank 0~3.
  * @param[in]  u32Bank Bank number for EBI. Valid values are:
  *                      - \ref EBI_BANK0
  *                      - \ref EBI_BANK1
  *                      - \ref EBI_BANK2
  *                      - \ref EBI_BANK3
  * @param[in]  *u32Key 128-bits encrypt/decrypt key array.
  * @return none
  */
void EBI_EnableCrypto(uint32_t u32Bank, uint32_t *u32Key)
{
    switch(u32Bank) {
    case EBI_BANK0:
        EBI->EBICON |= EBI_EBICON_CRYPT0_Msk;
        break;
    case EBI_BANK1:
        EBI->EBICON |= EBI_EBICON_CRYPT1_Msk;
        break;
    case EBI_BANK2:
        EBI->EBICON |= EBI_EBICON_CRYPT2_Msk;
        break;
    case EBI_BANK3:
        EBI->EBICON |= EBI_EBICON_CRYPT3_Msk;
        break;
    }

    EBI->KEY_W0 = u32Key[0];
    EBI->KEY_W1 = u32Key[1];
    EBI->KEY_W2 = u32Key[2];
    EBI->KEY_W3 = u32Key[3];
}

/**
  * @brief  Disable encrypt/decrypt function for EBI bank 0~3.
  * @param[in]  u32Bank Bank number for EBI. Valid values are:
  *                      - \ref EBI_BANK0
  *                      - \ref EBI_BANK1
  *                      - \ref EBI_BANK2
  *                      - \ref EBI_BANK3
  * @return none
  */
void EBI_DisbleCrypto(uint32_t u32Bank)
{
    switch(u32Bank) {
    case EBI_BANK0:
        EBI->EBICON &= ~EBI_EBICON_CRYPT0_Msk;
        break;
    case EBI_BANK1:
        EBI->EBICON &= ~EBI_EBICON_CRYPT1_Msk;
        break;
    case EBI_BANK2:
        EBI->EBICON &= ~EBI_EBICON_CRYPT2_Msk;
        break;
    case EBI_BANK3:
        EBI->EBICON &= ~EBI_EBICON_CRYPT3_Msk;
        break;
    }
}

/*@}*/ /* end of group NUC400_EBI_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NUC400_EBI_Driver */

/*@}*/ /* end of group NUC400_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
