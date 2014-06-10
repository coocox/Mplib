/**************************************************************************//**
 * @file     I2S.h
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 12/08/06 8:08p $
 * @brief    NUC200 Series I2S Driver Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __I2S_H__
#define __I2S_H__

/*---------------------------------------------------------------------------------------------------------*/
/* Include related headers                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#include "NUC200Series.h"


/** @addtogroup NUC200_FUNC NUC200 Function Interface
  * @{
  */

/** @addtogroup I2S_FUNC I2S Device Function Interface
  * @{
  */


/*---------------------------------------------------------------------------------------------------------*/
/* I2S_CON constant definitions                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define I2S_CON_FMT_PCMA        0x01000000UL
#define I2S_CON_FMT_PCMB        0x01000080UL
#define I2S_CON_FMT_I2S         0x00000000UL
#define I2S_CON_FMT_MSB_JUST    0x00000080UL
#define I2S_CON_WORDWIDTH_8     0x00000000UL
#define I2S_CON_WORDWIDTH_16    0x00000010UL
#define I2S_CON_WORDWIDTH_24    0x00000020UL
#define I2S_CON_WORDWIDTH_32    0x00000030UL
#define I2S_CON_MUTE            0x00000008UL
#define I2S_CON_PLAY_EN         0x00000002UL
#define I2S_CON_REC_EN          0x00000004UL
#define I2S_CON_ENABLE          0x00000001UL
#define I2S_CON_MONO_LEFT   0x00800040UL
#define I2S_CON_MONO_RIGHT  0x00000040UL
#define I2S_CON_STEREO      0x00000000UL
#define I2S_CON_RX_TH(x)    (((x)-1) << 12) // x = 1 ~ 8   
#define I2S_CON_TX_TH(x)    ((x) << 9)      // x = 0 ~ 7
#define I2S_CON_SLAVE       0x00000100UL
#define I2S_CON_MCLK_EN     0x00008000UL
#define I2S_CON_MASTER      0x00000000UL

/*---------------------------------------------------------------------------------------------------------*/
/* I2S_CLKDIV constant definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define I2S_CLKDIV_BCLK(x)  (((x)/2 - 1) << 8)   /*!< I2S_CLKDIV setting for I2S BCLK clock divider. It could be 2,4~512 */
#define I2S_CLKDIV_MCLK(x)  ((x)/2)              /*!< I2S_CLKDIV setting for I2S MCLK clock divider. It could be 0,2,4 ~ 14 */



/*---------------------------------------------------------------------------------------------------------*/
/*  Define Macros and functions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/

#if 0
/**
 * @details    Configure the user-specified SPI port as a master
 */
#define _SPI_SET_MASTER_MODE(port) ((port)->CNTRL &= (~SPI_CNTRL_SLAVE_MODE))




/**
 * @brief      Get SPI clock1 frequency (Hz).
 *
 * @param[in]  pSpiPort   Specify the SPI port.
 *
 * @return     SPI clock1 frequency.
 *
 * @details    This function calculates the clock rate of clock1 (SPI engine clock).
 *
 */
static __INLINE uint32_t SPI_GetClock1Freq(SPI_T * pSpiPort)
{
    return (SystemCoreClock>>1)/((pSpiPort->DIVIDER & 0xFFFF)+1);
}

#endif

/**
  * @} End of I2S Device Function Interface
  */ 

/**
  * @} End of NUC200 Function Interface
  */ 

#endif  //__I2S_H__

