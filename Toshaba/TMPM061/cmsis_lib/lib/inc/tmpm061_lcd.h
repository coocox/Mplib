/**
 *******************************************************************************
 * @file    tmpm061_lcd.h
 * @brief   This file provides all the functions prototypes for LCD driver.
 * @version V2.0.2.1
 * @date    2012/04/20
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
 * (C)Copyright TOSHIBA CORPORATION 2012 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM061_LCD_H
#define __TMPM061_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM061.h"
#include "tx00_common.h"

#if defined(__TMPM061_LCD_H)
/** @addtogroup TX00_Periph_Driver
  * @{
  */

/** @addtogroup LCD
  * @{
  */

/** @defgroup LCD_Exported_Types
  * @{
  */

/** @} */
/* End of group LCD_Exported_Types */

/** @defgroup LCD_Exported_Constants
  * @{
  */


    typedef enum {
        LCD_DUTY4_BIAS3 = 0U,   /* 1/4 duty, 1/3 bias */
        LCD_DUTY3_BIAS3 = 1U,   /* 1/3 duty, 1/3 bias */
        LCD_DUTY3_BIAS2 = 2U,   /* 1/3 duty, 1/2 bias */
        LCD_DUTY2_BIAS2 = 3U,   /* 1/2 duty, 1/2 bias */
        LCD_STATIC = 4U         /* static             */
    } LCD_DutyBias;
#define IS_LCD_DUTY_BIAS(param)      ((param)  <= LCD_STATIC)


    typedef enum {              /* to set LCDCR1<SLF> */
        LCD_FSYS_DIVIDE_2_POWER_18 = 0U,        /* F_base = fsys / (2^18) */
        LCD_FSYS_DIVIDE_2_POWER_17 = 1U,        /* F_base = fsys / (2^17) */
        LCD_FSYS_DIVIDE_2_POWER_16 = 2U,        /* F_base = fsys / (2^16) */
        LCD_FSYS_DIVIDE_2_POWER_15 = 3U,        /* F_base = fsys / (2^15) */
        LCD_FSYS_DIVIDE_2_POWER_14 = 4U,        /* F_base = fsys / (2^14) */
        LCD_FS_DIVIDE_2_POWER_9 = 8U,   /* F_base = fs / (2^9)   */
        LCD_FS_DIVIDE_2_POWER_8 = 9U    /* F_base = fs / (2^8)   */
    } LCD_BaseFreq;
#define IS_LCD_BASE_FREQ(param)      (((param)  <= LCD_FSYS_DIVIDE_2_POWER_14) || \
                                      ((param)  == LCD_FS_DIVIDE_2_POWER_9) || \
                                      ((param)  == LCD_FS_DIVIDE_2_POWER_8))


    typedef enum {              /* note: refer comment in LCD_BaseFreq for "F_base" */
        LCD_NOT_CONNECT = 0U,   /* Low internal bleeder resistor is never connected */
        LCD_2_POWER_7_DEVIDE_BASE_FREQ = 1U,    /* (2^7)/F_base  ( connection time = (2^11)/ fsys , when LCDCR1<SLF> = 0 */
        LCD_2_POWER_6_DEVIDE_BASE_FREQ = 2U,    /* (2^6)/F_base  ( connection time = (2^12)/ fsys , when LCDCR1<SLF> = 0 */
        LCD_2_POWER_5_DEVIDE_BASE_FREQ = 3U,    /* (2^5)/F_base  ( connection time = (2^9)/ fsys ,  when LCDCR1<SLF> = 4 */
        LCD_2_POWER_4_DEVIDE_BASE_FREQ = 4U,    /* (2^4)/F_base  ( connection time = (2^5)/ fs ,    when LCDCR1<SLF> = 8 */
        LCD_2_POWER_3_DEVIDE_BASE_FREQ = 5U,    /* (2^3)/F_base  ( connection time = (2^14)/ fsys , when LCDCR1<SLF> = 1 */
        LCD_ALWAYS_CONNECT = 6U /* Low internal bleeder resistor is always connected */
    } LCD_LowResistorConnectionTime;
#define IS_LCD_LOW_RESISTOR_CONNECTION_TIME(param)  ((param)  <= LCD_ALWAYS_CONNECT)


    typedef enum {
        LCD_BLEEDER_RESISTOR_200K = 0U,
        LCD_BLEEDER_RESISTOR_500K = 1U
    } LCD_BleederResistorValue;
#define IS_LCD_BLEEDER_RESISTOR_VALUE(param)      ((param)  <= LCD_BLEEDER_RESISTOR_500K)

    typedef enum {
        LCD_BLEEDER_RESISTOR_EXTERNAL = 0U,
        LCD_BLEEDER_RESISTOR_INTERNAL = 1U
    } LCD_BleederResistorSource;
#define IS_LCD_BLEEDER_RESISTOR_SOURCE(param)      ((param)  <= LCD_BLEEDER_RESISTOR_INTERNAL)


    /* to write data to Segment buffer. */
    /* LCD_BUF_SEGxx (xx == 00 to 39): write data for one seg a time, */
    /* LCD_BUF_SEGxxyy (xxyy == 0100 to 3938): write data for two seg a time */
    typedef enum {
        LCD_BUF_SEG00 = 0U,     /* index to write data for SEG0 in LCDBUF00 */
        LCD_BUF_SEG01 = 1U,     /* index to write data for SEG1 in LCDBUF00 */
        LCD_BUF_SEG02 = 2U,     /* index to write data for SEG2 in LCDBUF01 */
        LCD_BUF_SEG03 = 3U,     /* index to write data for SEG3 in LCDBUF01 */
        LCD_BUF_SEG04 = 4U,
        LCD_BUF_SEG05 = 5U,
        LCD_BUF_SEG06 = 6U,
        LCD_BUF_SEG07 = 7U,
        LCD_BUF_SEG08 = 8U,
        LCD_BUF_SEG09 = 9U,
        LCD_BUF_SEG10 = 10U,
        LCD_BUF_SEG11 = 11U,
        LCD_BUF_SEG12 = 12U,
        LCD_BUF_SEG13 = 13U,
        LCD_BUF_SEG14 = 14U,
        LCD_BUF_SEG15 = 15U,
        LCD_BUF_SEG16 = 16U,
        LCD_BUF_SEG17 = 17U,
        LCD_BUF_SEG18 = 18U,
        LCD_BUF_SEG19 = 19U,
        LCD_BUF_SEG20 = 20U,
        LCD_BUF_SEG21 = 21U,
        LCD_BUF_SEG22 = 22U,
        LCD_BUF_SEG23 = 23U,
        LCD_BUF_SEG24 = 24U,
        LCD_BUF_SEG25 = 25U,
        LCD_BUF_SEG26 = 26U,
        LCD_BUF_SEG27 = 27U,
        LCD_BUF_SEG28 = 28U,
        LCD_BUF_SEG29 = 29U,
        LCD_BUF_SEG30 = 30U,
        LCD_BUF_SEG31 = 31U,
        LCD_BUF_SEG32 = 32U,
        LCD_BUF_SEG33 = 33U,
        LCD_BUF_SEG34 = 34U,
        LCD_BUF_SEG35 = 35U,
        LCD_BUF_SEG36 = 36U,
        LCD_BUF_SEG37 = 37U,
        LCD_BUF_SEG38 = 38U,
        LCD_BUF_SEG39 = 39U,

        LCD_BUF_SEG0100 = 40U,  /* index to write data for SEG1 and SEG0 in LCDBUF00 */
        LCD_BUF_SEG0302 = 41U,  /* index to write data for SEG3 and SEG2 in LCDBUF01 */
        LCD_BUF_SEG0504 = 42U,
        LCD_BUF_SEG0706 = 43U,
        LCD_BUF_SEG0908 = 44U,
        LCD_BUF_SEG1110 = 45U,
        LCD_BUF_SEG1312 = 46U,
        LCD_BUF_SEG1514 = 47U,
        LCD_BUF_SEG1716 = 48U,
        LCD_BUF_SEG1918 = 49U,
        LCD_BUF_SEG2120 = 50U,
        LCD_BUF_SEG2322 = 51U,
        LCD_BUF_SEG2524 = 52U,
        LCD_BUF_SEG2726 = 53U,
        LCD_BUF_SEG2928 = 54U,
        LCD_BUF_SEG3130 = 55U,
        LCD_BUF_SEG3332 = 56U,
        LCD_BUF_SEG3534 = 57U,
        LCD_BUF_SEG3736 = 58U,
        LCD_BUF_SEG3938 = 59U
    } LCD_BufIndex;
#define IS_LCD_BUF_INDEX(param)   ((param)  <= LCD_BUF_SEG3938)
#define IS_LCD_BUF_DATA_1N(param)    ((param)  <= 15U )

/** @} */
/* End of LCD_Exported_Constants */

/** @defgroup LCD_Exported_FunctionPrototypes
  * @{
  */

    void LCD_Enable(void);
    void LCD_Disable(void);
    void LCD_SetDisplay(FunctionalState NewState);
    void LCD_SetDutyBias(LCD_DutyBias DutyBias);
    void LCD_SetBaseFreq(LCD_BaseFreq Freq);
    void LCD_SetLowBleederTime(LCD_LowResistorConnectionTime Time);
    void LCD_SetInternalBleeder(LCD_BleederResistorValue Value);
    void LCD_SetBleederSource(LCD_BleederResistorSource Source);
    void LCD_WriteBuf(LCD_BufIndex TargetBuf, uint8_t Data);


/** @} */
/* End of LCD_Exported_FunctionPrototypes */

/** @} */
/* End of group LCD */

/** @} */
/* End of group TX00_Periph_Driver */
#endif                          /* defined(__TMPM061_LCD_H) */

#ifdef __cplusplus
}
#endif
#endif                          /* __TMPM061_LCD_H */
